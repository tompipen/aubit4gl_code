/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-1 Aubit Development Team (See Credits file)       |
# +----------------------------------------------------------------------+
# | This program is free software; you can redistribute it and/or modify |
# | it under the terms of one of the following licenses:                 |
# |                                                                      |
# |  A) the GNU General Public License as published by the Free Software |
# |     Foundation; either version 2 of the License, or (at your option) |
# |     any later version.                                               |
# |                                                                      |
# |  B) the Aubit License as published by the Aubit Development Team and |
# |     included in the distribution in the file: LICENSE                |
# |                                                                      |
# | This program is distributed in the hope that it will be useful,      |
# | but WITHOUT ANY WARRANTY; without even the implied warranty of       |
# | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        |
# | GNU General Public License for more details.                         |
# |                                                                      |
# | You should have received a copy of both licenses referred to here.   |
# | If you did not, or have any questions about Aubit licensing, please  |
# | contact afalout@ihug.co.nz                                           |
# +----------------------------------------------------------------------+
#
# $Id: window.c,v 1.10 2003-10-11 08:41:38 afalout Exp $
#*/

/**
 * @file
 * 4gl Window management in GTK mode.
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/


#include "a4gl_lib_ui_gtk_int.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

extern GtkWidget *win_screen;

/** The windows stack */
static GtkWindow *win_stack[1024];

/** The windows stack counter / index */
static int win_stack_cnt = 0;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

void A4GL_dump_gtkwinstack (void);
//void A4GL_hide_window (char *s);
//void A4GL_show_window (char *s);
//void A4GL_movewin (char *s, int to_by);
//void A4GL_remove_window (char *s);


//void clr_window(char *name);
void A4GL_dump_object (GtkObject * o);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/**
 * Checks if the window have top window
 *
 * @return - 1 : The window have top
 *         - 0 : The window does not have top
 */
static int
has_top (GtkWidget * cwin)
{
  if (gtk_object_get_data (GTK_OBJECT (cwin), "TOP"))
    return 1;
  else
    return 0;
}

/**
 * Implements the HIDE WINDOW statement of 4gl in GTK GUI mode.
 *
 * @param s The 4gl window name to be hidded.
 */
void
A4GL_hide_window (char *s)
{
  GtkWidget *cwin;
  cwin = (GtkWidget *) A4GL_find_pointer (s, WINCODE);
  printf ("cwin=%p", cwin);
  if (has_top (cwin))
    cwin = (GtkWidget *) gtk_object_get_data (GTK_OBJECT (cwin), "TOP");
  printf ("Hide %p\n", cwin);
  gtk_widget_hide (cwin);
  A4GL_gui_run_til_no_more ();
}

/**
 * Implements the SHOW WINDOW 4gl statement in GTK GUI mode.
 *
 * @param s The window name.
 */
void
A4GL_show_window (char *s)
{
  GtkWidget *cwin;

  cwin = (GtkWidget *) A4GL_find_pointer (s, WINCODE);
  if (has_top (cwin))
    cwin = gtk_object_get_data (GTK_OBJECT (cwin), "TOP");
  gtk_widget_show (cwin);
  A4GL_gui_run_til_no_more ();
}

/**
 * Move the 4gl window in GTK GUI mode.
 *
 * The number of rows and or columns is getted from the stack.
 *
 * @param s The window name.
 * @param to_by Flag that identifies the scope of the move:
 *   - 0 : The move is abosulte in the screen.
 *   - 1 : The move is relative to the current position.
 */
int
A4GL_movewin (char *s, int to_by)
{
  int x;
  int y;
  int xo;
  int yo;
  GtkWidget *cwin;


  x = A4GL_pop_int ();
  y = A4GL_pop_int ();

  cwin = (GtkWidget *) A4GL_find_pointer (s, WINCODE);
  yo = (int) gtk_object_get_data (GTK_OBJECT (cwin), "Y_OFF");
  xo = (int) gtk_object_get_data (GTK_OBJECT (cwin), "X_OFF");

  cwin = (GtkWidget *) gtk_object_get_data (GTK_OBJECT (cwin), "TOP");

  gtk_fixed_move ((GtkFixed *) win_screen, cwin, (x - 1) * XWIDTH + xo,
		  (y - 1) * YHEIGHT + yo);
  A4GL_gui_run_til_no_more ();
  return 1;
}

/**
 * Change the window stack in GTK GUI mode.
 *
 * Change the window in the stack cnages the order in wich is viewed.
 *
 * @param w The window widget to be changed in the stack.
 * @param op
 *   - + : The window is created and inserted in the stack.
 *   - - : The window is removed from stack and the last one is made current.
 *   - ^ : The window is made current.
 */
void
A4GL_gtkwin_stack (GtkWindow * w, int op)
{
  int a;
  int b;

  A4GL_debug ("gtkwin_stack : %p %c", w, op);

  if (op == '+')
    win_stack[win_stack_cnt++] = w;

  if (op == '-')
    {
      for (a = 0; a < win_stack_cnt; a++)
	{
	  if (win_stack[a] == w)
	    {
	      win_stack[a] = 0;
	      for (b = a + 1; b < win_stack_cnt; b++)
		{
		  win_stack[b - 1] = win_stack[b];
		}
	      win_stack_cnt--;
	      A4GL_debug ("win_stack_cnt=%d", win_stack_cnt);
	      A4GL_set_current_window (win_stack[win_stack_cnt - 1]);
	      break;
	    }
	}


    }

  if (op == '^')
    {
      A4GL_gtkwin_stack (w, '-');
      A4GL_gtkwin_stack (w, '+');
    }
}

/**
 * Implements the CLOSE WINDOW 4gl statement in GTK GUI mode.
 *
 * @param win_name The window name.
 */
void
A4GL_remove_window (char *s)
{
  GtkWidget *cwin;
  GtkWidget *cwin_2;

  A4GL_debug ("Removing window %s", s);

  if (!(A4GL_has_pointer (s, WINCODE)))
    {
      A4GL_set_error ("Window not found %s", s);
      A4GL_exitwith ("Window not found");
      A4GL_set_errm (s);
      return;
    }

  cwin_2 = (GtkWidget *) A4GL_find_pointer (s, WINCODE);
  A4GL_dump_object ((GtkObject *) cwin_2);

  cwin = gtk_object_get_data (GTK_OBJECT (cwin_2), "TOP");
  A4GL_dump_object ((GtkObject *) cwin);

  A4GL_debug ("cwin_2=%p cwin=%p win_screen=%p", cwin_2, cwin, win_screen);

  gtk_widget_destroy (cwin);
  gtk_widget_destroy (cwin_2);
  A4GL_del_pointer (s, WINCODE);
  A4GL_gui_run_til_no_more ();
  A4GL_dump_gtkwinstack ();
  A4GL_gtkwin_stack ((GtkWindow *) cwin_2, '-');
  A4GL_dump_gtkwinstack ();
}


/**
 * Gets the width of the current window (in GTK GUI mode).
 *
 * @return The width of the current window.
 */
int
A4GL_get_curr_width (void)
{
  GtkWidget *cwin;
  int width;
  cwin = (GtkWidget *) A4GL_get_curr_win_gtk ();
  width = (int) gtk_object_get_data (GTK_OBJECT (cwin), "WIDTH");
  return width;
}

/**
 * Get the line configured as prompt line in current window.
 *
 * @return The prompt line.
 */
int
A4GL_getprompt_line_gtk (void)
{
  GtkWidget *cwin;
  cwin = (GtkWidget *) A4GL_get_curr_win_gtk ();
  if (gtk_object_get_data (GTK_OBJECT (cwin), "currform") == 0)
    {
      return A4GL_decode_line_gtk (std_dbscr.prompt_line);
    }
  return A4GL_decode_line_gtk ((int)
			  gtk_object_get_data (GTK_OBJECT (cwin),
					       "PROMPT_LINE"));
}

/**
 * Get the error line of the current window (in GTK GUI mode).
 *
 * @return The line used to display an error.
 */
int
A4GL_geterr_line_gtk (void)
{
  GtkWidget *cwin;
  cwin = (GtkWidget *) A4GL_get_curr_win_gtk ();
  if (gtk_object_get_data (GTK_OBJECT (cwin), "currform") == 0)
    {
      return A4GL_decode_line_gtk (std_dbscr.error_line);
    }
  return (int) gtk_object_get_data (GTK_OBJECT (cwin), "ERROR_LINE");
}

/**
 * Get the mesage line of the current window (in GTK GUI mode).
 *
 * @return The line used to display a message.
 */
int
A4GL_getmsg_line_gtk (void)
{
  GtkWidget *cwin;
  cwin = (GtkWidget *) A4GL_get_curr_win_gtk ();
  if (gtk_object_get_data (GTK_OBJECT (cwin), "currform") == 0)
    {
      return (int) std_dbscr.message_line;
    }
  else
    {
      return (int) gtk_object_get_data (GTK_OBJECT (cwin), "MESSAGE_LINE");
    }
}

/**
 * Get the border type of the current window.
 *
 * @return The border type.
 */
int
A4GL_get_curr_border_gtk (void)
{
  GtkWidget *cwin;
  cwin = (GtkWidget *) A4GL_get_curr_win_gtk ();
  return (int) gtk_object_get_data (GTK_OBJECT (cwin), "BORDER");

}

int
A4GL_iscurrborder ()
{
  if (A4GL_get_curr_border_gtk ())
    return 1;
  else
    return 0;
}

/**
 * Get the heigth of the current window.
 *
 * @return The heigth of thr current window.
 */
int
A4GL_get_curr_height_gtk (void)
{
  GtkWidget *cwin;
  cwin = (GtkWidget *) A4GL_get_curr_win_gtk ();
  return (int) gtk_object_get_data (GTK_OBJECT (cwin), "HEIGHT");
}

/**
 * Clear the window in GTK GUI mode.
 */
void
A4GL_clr_window (char *name)
{
  GtkWidget *cwin;
  cwin = (GtkWidget *) A4GL_find_pointer (name, WINCODE);
  cwin = gtk_object_get_data (GTK_OBJECT (cwin), "TOP");
  A4GL_debug ("FIXME : A4GL_clr_window NOT IMPLEMENTED YET");
}

/**
 * Decode the line configured (for error, message, etc).
 *
 * The decode is made acording the border style,  and the line.
 *
 * @param l The line to be configured.
 * @return  The decoded line.
 */
int
A4GL_decode_line_gtk (int l)
{
  if (l > 0)
    {
      if (A4GL_get_curr_border_gtk ())
	{
	  A4GL_debug ("1. Decoded line %d to %d (because of border)", l, l - 1);
	  return l - 1;
	}
      else
	{
	  A4GL_debug ("Decoded line %d to %d", l, l);
	  return l;
	}
    }
  /* -1 = last */
  /* -2 = last -1 */
  if (A4GL_get_curr_border_gtk ())
    {
      if (l < 0)
	{
	  A4GL_debug ("2. Decoded line %d to %d  %d ", l, A4GL_get_curr_height_gtk ());
	  return A4GL_get_curr_height_gtk () + l;
	}

    }
  else
    {
      if (l < 0)
	{
	  A4GL_debug ("3. Decoded line %d to %d  %d ", l, A4GL_get_curr_height_gtk ());
	  return A4GL_get_curr_height_gtk () + l + 1;
	}
    }

  return 0;
}

/**
 * Dump the window stack into the A4GL_debug mechanism.
 */
void
A4GL_dump_gtkwinstack (void)
{
  int a;
  for (a = 0; a < win_stack_cnt; a++)
    {
      A4GL_debug ("Winstack : %d %p", a, win_stack[a]);
    }
}

int
aclfgl_fgl_drawbox (int n)
{
  while (n)
    {
      A4GL_pop_int ();
      n--;
    }
  return 0;
}

/* =============================== EOF ============================= */

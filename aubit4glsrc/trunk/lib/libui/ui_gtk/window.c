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
# $Id: window.c,v 1.4 2003-01-14 08:26:29 mikeaubury Exp $
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
static int win_stack_cnt=0;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

void dump_gtkwinstack(void);
void hide_window (char *s);
void show_window (char *s);
void movewin (char *s, int to_by);
void remove_window (char *s);
int get_curr_border_gtk(void);
int get_curr_height_gtk(void);
void clr_window(char *name);

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
has_top(GtkWidget *cwin)
{
 if (gtk_object_get_data (GTK_OBJECT(cwin), "TOP")) return 1;
 else return 0;
}

/**
 * Implements the HIDE WINDOW statement of 4gl in GTK GUI mode.
 *
 * @param s The 4gl window name to be hidded.
 */
void
hide_window (char *s)
{
  GtkWidget *cwin;
  cwin = (GtkWidget *)find_pointer (s, WINCODE);
  printf("cwin=%p",cwin);
  if (has_top(cwin)) 
	  cwin = (GtkWidget *)gtk_object_get_data (GTK_OBJECT(cwin), "TOP");
  printf ("Hide %p\n", cwin);
  gtk_widget_hide (cwin);
  gui_run_til_no_more ();
}

/**
 * Implements the SHOW WINDOW 4gl statement in GTK GUI mode.
 *
 * @param s The window name.
 */
void
show_window (char *s)
{
  GtkWidget *cwin;

  cwin = (GtkWidget *)find_pointer (s, WINCODE);
  if (has_top(cwin)) cwin = gtk_object_get_data (GTK_OBJECT(cwin), "TOP");
  gtk_widget_show (cwin);
  gui_run_til_no_more ();
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
void
movewin (char *s, int to_by)
{
  int x;
  int y;
  int xo;
  int yo;
  GtkWidget *cwin;


  x = pop_int ();
  y = pop_int ();

  cwin = (GtkWidget *)find_pointer (s, WINCODE);
  yo = (int)gtk_object_get_data (GTK_OBJECT(cwin), "Y_OFF");
  xo = (int)gtk_object_get_data (GTK_OBJECT(cwin), "X_OFF");

  cwin = (GtkWidget *)gtk_object_get_data (GTK_OBJECT(cwin), "TOP");

  gtk_fixed_move ((GtkFixed *)win_screen, cwin, (x - 1) * XWIDTH + xo,
		  (y - 1) * YHEIGHT + yo);
  gui_run_til_no_more ();
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
gtkwin_stack(GtkWindow *w,int op)
{
  int a;
  int b;

	debug("gtkwin_stack : %p %c",w,op);

	if (op=='+') 
		win_stack[win_stack_cnt++] = w;

	if (op=='-') 
	{
		for (a=0;a<win_stack_cnt;a++) 
		{
			if (win_stack[a]==w) 
			{
				win_stack[a]=0;
				for (b=a+1;b<win_stack_cnt;b++) 
				{
					win_stack[b-1]=win_stack[b];
				}
	  			win_stack_cnt--;
	  			debug("win_stack_cnt=%d",win_stack_cnt);
	  			set_current_window (win_stack[win_stack_cnt-1]);
				break;
			}
		}


	}
				
	if (op=='^') 
	{
		gtkwin_stack(w,'-');
		gtkwin_stack(w,'+');
	}
}

/**
 * Implements the CLOSE WINDOW 4gl statement in GTK GUI mode.
 *
 * @param win_name The window name.
 */
void
remove_window (char *s)
{
  GtkWidget *cwin;
  GtkWidget *cwin_2;

  debug("Removing window %s",s);
                                               
  if (!(has_pointer (s, WINCODE)))
    {
      set_error ("Window not found %s", s);
      exitwith ("Window not found");
      set_errm (s);
      return;
    } 

  cwin_2 = (GtkWidget *)find_pointer (s, WINCODE);
  dump_object(cwin_2);

  cwin = gtk_object_get_data (GTK_OBJECT(cwin_2), "TOP");
  dump_object(cwin);

  debug("cwin_2=%p cwin=%p win_screen=%p",cwin_2,cwin,win_screen);

  gtk_widget_destroy (cwin);
  gtk_widget_destroy (cwin_2);
  del_pointer (s, WINCODE);
  gui_run_til_no_more ();
  dump_gtkwinstack();
  gtkwin_stack((GtkWindow *)cwin_2,'-');
  dump_gtkwinstack();
}


/**
 * Gets the width of the current window (in GTK GUI mode).
 *
 * @return The width of the current window.
 */
int
get_curr_width_gtk(void)
{
  GtkWidget *cwin;
  int width;
	cwin = (GtkWidget *)get_curr_win_gtk ();
  	width = (int)gtk_object_get_data (GTK_OBJECT(cwin), "WIDTH");
	return width;
}

/**
 * Get the line configured as prompt line in current window.
 *
 * @return The prompt line.
 */
int
getprompt_line_gtk(void)
{
  GtkWidget *cwin;
	cwin = (GtkWidget *)get_curr_win_gtk ();
if (gtk_object_get_data (GTK_OBJECT (cwin), "currform")==0) {
      return decode_line_gtk (std_dbscr.prompt_line);
}
    return decode_line_gtk((int)gtk_object_get_data (GTK_OBJECT(cwin), "PROMPT_LINE"));
}

/**
 * Get the error line of the current window (in GTK GUI mode).
 *
 * @return The line used to display an error.
 */
int 
geterr_line_gtk(void)
{
GtkWidget *cwin;
cwin = (GtkWidget *)get_curr_win_gtk ();
if (gtk_object_get_data (GTK_OBJECT (cwin), "currform")==0) {
      return decode_line_gtk (std_dbscr.error_line);
}
  	return (int)gtk_object_get_data (GTK_OBJECT(cwin), "ERROR_LINE");
}

/**
 * Get the mesage line of the current window (in GTK GUI mode).
 *
 * @return The line used to display a message.
 */
int
getmsg_line_gtk(void)
{
	GtkWidget *cwin;
	cwin = (GtkWidget *)get_curr_win_gtk ();
if (gtk_object_get_data (GTK_OBJECT (cwin), "currform")==0) {
  	return (int)std_dbscr.message_line;
} else {
  	return (int)gtk_object_get_data (GTK_OBJECT(cwin), "MESSAGE_LINE");
}
}

/**
 * Get the border type of the current window.
 *
 * @return The border type.
 */
int
get_curr_border_gtk(void)
{
GtkWidget *cwin;
	cwin = (GtkWidget *)get_curr_win_gtk ();
  	return (int)gtk_object_get_data (GTK_OBJECT(cwin), "BORDER");

}

/**
 * Get the heigth of the current window.
 *
 * @return The heigth of thr current window.
 */
int
get_curr_height_gtk(void)
{
GtkWidget *cwin;
	cwin = (GtkWidget *)get_curr_win_gtk ();
  	return (int)gtk_object_get_data (GTK_OBJECT(cwin), "HEIGHT");
}

/**
 * Clear the window in GTK GUI mode.
 */
void
clr_window(char *name)
{
  GtkWidget *cwin;
  cwin = (GtkWidget *)find_pointer (name, WINCODE);
  cwin = gtk_object_get_data (GTK_OBJECT(cwin), "TOP");
  debug("FIXME : clr_window NOT IMPLEMENTED YET");
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
decode_line_gtk (int l)
{
  if (l > 0)
  {
    if (get_curr_border_gtk ())
      {
        debug ("1. Decoded line %d to %d (because of border)", l, l - 1);
        return l - 1;
      }
    else
      {
        debug ("Decoded line %d to %d", l, l);
        return l;
      }
  }
	/* -1 = last */
	/* -2 = last -1 */
  if (get_curr_border_gtk ())
    {
      if (l < 0)
        {
          debug ("2. Decoded line %d to %d  %d ", l, get_curr_height_gtk ());
          return get_curr_height_gtk () + l;
        }

    }
  else
    {
      if (l < 0)
        {
          debug ("3. Decoded line %d to %d  %d ", l, get_curr_height_gtk ());
          return get_curr_height_gtk () + l + 1;
        }
    }

return 0;
}

/**
 * Dump the window stack into the debug mechanism.
 */
void
dump_gtkwinstack(void)
{
int a;
	for (a=0;a<win_stack_cnt;a++) {
		debug("Winstack : %d %p",a,win_stack[a]);
	}
}

/* =============================== EOF ============================= */


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
# $Id: prompt.c,v 1.18 2003-12-12 16:15:05 mikeaubury Exp $
#*/

/**
 * @file
 * 4gl PROMPT statement implementation in GTK mode.
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

/**
 * The prompt style.
 */
int prompt_style = 0;


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/


//int UILIB_A4GL_start_prompt (struct s_prompt *prompt, int ap, int c, int h,int af);
//int UILIB_A4GL_prompt_loop (struct s_prompt * prompt);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/**
 * Implementation in GTK GUI mode of the first part of C version PROMPT
 * 4gl statement.
 *
 * @param prompt A pointer to the prompt identifier structure where this
 *   function initialize the values.
 * @param ap The attributes for the message.
 * @param c Prompt for char (cbreak()) flag.
 * @param h The help number.
 * @param af The attributes.
 */
int
 UILIB_A4GL_start_prompt (void *vprompt, int ap, int c, int h, int af)
{
  char *promptstr;
  int promptline;
  int width;
  char buff[300];
  GtkHBox *win;
  GtkWidget *cw = 0;
  GtkWidget *sarr[3];
  struct s_prompt *prompt;
  prompt = vprompt;

  win = GTK_HBOX (gtk_hbox_new (0, 0));

  A4GL_debug ("In start prompt %p %d %d %d %d", prompt, ap, c, h, af);

  memset (buff, ' ', 255);

  if (prompt_style == 0)
    {
      promptline = A4GL_getprompt_line_gtk ();
      width = UILIB_A4GL_get_curr_width ();
      cw = GTK_WIDGET (A4GL_get_curr_win_gtk ());
    }
  else
    {
      promptline = 0;
      width = 80;
      if (prompt_style == 1)
	cw = gtk_window_new (GTK_WINDOW_TOPLEVEL);

      /* old style :
         typedef enum
         {
         GTK_WINDOW_TOPLEVEL,
         GTK_WINDOW_DIALOG, << missing!!!
         GTK_WINDOW_POPUP
         } GtkWindowType;

         GTK+ V 2:

         typedef enum
         {
         GTK_WINDOW_TOPLEVEL,
         GTK_WINDOW_POPUP
         } GtkWindowType;

       */

      //if (prompt_style==2) cw=gtk_window_new(GTK_WINDOW_DIALOG);
      if (prompt_style == 2)
	cw = gtk_window_new (GTK_WINDOW_POPUP);
      if (prompt_style == 3)
	cw = gtk_window_new (GTK_WINDOW_POPUP);
      gtk_widget_show (cw);
    }
  A4GL_debug ("Promptline=%d", promptline);
  prompt->win = win;
  promptstr = A4GL_char_pop ();
  prompt->mode = 0;
  prompt->h = h;
  prompt->charmode = c;
A4GL_debug("Prompt mode=%d",c);
  prompt->promptstr = promptstr;
  prompt->lastkey = 0;
  width -= strlen (promptstr);
  width--;

  sarr[0] = (void *) gtk_label_new (promptstr);
  sarr[1] = (void *) gtk_entry_new ();

  gtk_box_pack_start_defaults (GTK_BOX (win), GTK_WIDGET (sarr[0]));
  gtk_box_pack_start_defaults (GTK_BOX (win), GTK_WIDGET (sarr[1]));

  gtk_widget_show (sarr[0]);
  gtk_widget_show (sarr[1]);
  gtk_widget_show (GTK_WIDGET (win));

  gtk_object_set_data (GTK_OBJECT (win), "STYLE", (void *) prompt_style);
  gtk_object_set_data (GTK_OBJECT (win), "CW", cw);

  gtk_signal_connect (GTK_OBJECT (win), "key-press-event",
		      GTK_SIGNAL_FUNC (A4GL_keypress), win);

  gtk_signal_connect (GTK_OBJECT (sarr[1]), "key-press-event",
		      GTK_SIGNAL_FUNC (A4GL_keypress), sarr[1]);

  prompt->field = (void *) sarr[1];

  /* gtk_fixed_put(cw,win,0,promptline*YHEIGHT); */
  if (prompt_style == 0)
    gtk_fixed_put (GTK_FIXED (cw), GTK_WIDGET (win), A4GL_getx_coords(0), A4GL_gety_coords(promptline));
  else
    gtk_container_add (GTK_CONTAINER (cw), GTK_WIDGET (win));


  if (ap)
    {
      A4GL_gui_set_field_fore (sarr[0], ap);
      A4GL_gui_set_field_back (sarr[0], ap);
    }

  if (af)
    {
      A4GL_gui_set_field_back (sarr[1], af);
      A4GL_gui_set_field_fore (sarr[1], af);
    }

  buff[0] = 0;			/* -2 */

  gtk_entry_set_text (GTK_ENTRY (sarr[1]), buff);
  prompt->f = 0;
  A4GLSQL_set_status (0, 0);

  if (a4gl_status != 0)
    return (prompt->mode = 2);

  gtk_widget_grab_focus (GTK_WIDGET (prompt->field));

  A4GLSQL_set_status (0, 0);

  return 1;
}

/**
 * Implementaion in GTK GUI mode of the PROMPT 4gl statement.
 *
 * @param prompt A pointer to the prompt structure where the information about
 * it is stored.
 */
int
 UILIB_A4GL_prompt_loop (void *vprompt,int timeout)
{
  GtkWidget *p;
  int action;
  struct s_prompt *prompt;
  prompt = vprompt;

  p = prompt->win;




  if (prompt->mode == 1)
    {
      int style;
      GtkWidget *cw;
      char buff[1024];

      strcpy (buff, gtk_entry_get_text (GTK_ENTRY (prompt->field)));
      A4GL_trim (buff);
      A4GL_push_char (buff);
      prompt->mode = 2;
      style = (int) gtk_object_get_data (GTK_OBJECT (p), "STYLE");
      cw = gtk_object_get_data (GTK_OBJECT (p), "CW");
      if (style == 0)
	gtk_widget_destroy (p);
      else
	{
	  gtk_widget_destroy (cw);
	}
      return 0;
    }

  if (prompt->mode > 0)
    return 0;

  A4GL_clear_something ();

  while (1)
    {
      action = A4GL_user_has_done_something ();
      /* printf("Action=%d\n",action); */
      if (action)
	{
	  break;
	}

      a4gl_usleep (100);
      if (gtk_events_pending ())
	gtk_main_iteration ();
    }


  if (action == 1)
    {				/*  key pressed... */
      int k;
      k = A4GL_which_key ();
      //printf ("KEY PRESSED 0x%x\n", k);fflush(stdout);
      A4GL_set_last_key (k);
      A4GL_clear_something ();
    }

  prompt->lastkey = A4GL_gui_get_lastkey ();

  //printf("lastkey = %x\n",prompt->lastkey);

  if (prompt->lastkey == 10 || prompt->lastkey == 13
      || prompt->lastkey == 0xff0d || prompt->lastkey == 0xff8d)
    {
      prompt->mode = 1;
      return 0;
    }

  if (prompt->charmode)
    {
      A4GL_push_char (gtk_entry_get_text (GTK_ENTRY (prompt->field)));
    }

  return -90;
}


/**
 * Set the GUI prompt style.
 *
 * @param a The prompt style
 */
void
A4GL_gui_prompt_style (int a)
{
  if (a >= 0 && a <= 3)
    prompt_style = a;
  else
    prompt_style = 0;
}


/* ================================== EOF =========================== */

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
# $Id: error.c,v 1.5 2003-05-12 14:24:30 mikeaubury Exp $
#*/

/**
 * @file
 * Error window management.
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
                    Functions prototypes
=====================================================================
*/

void set_red (void);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/**
 * Show an error in a GTK GUI window
 *
 * @param s The message to be shoed.
 */
void
error_window_gtk (char *s)
{
  GtkWidget *cw;
  GtkWidget *label;
  GtkWidget *win;
  int errline;

  GdkColor red = { 0, 65535, 0, 0 };
  GtkRcStyle *rc_style = gtk_rc_style_new ();

  rc_style->bg[GTK_STATE_NORMAL] = red;
  rc_style->color_flags[GTK_STATE_NORMAL] |= GTK_RC_BG;


  cw = (GtkWidget *) get_curr_win_gtk ();
  win = gtk_object_get_data (GTK_OBJECT (cw), "ERRORLABELWIN");

  if (win)
    gtk_widget_destroy (win);
  if (strlen (s) == 0)
    return;

  errline = decode_line_gtk (geterr_line_gtk ());
  debug ("Error line :%d", errline);

  win = gtk_fixed_new ();
  gtk_widget_set_usize (win, get_curr_width () * XWIDTH, YHEIGHT);
  label = gtk_label_new (s);
  gtk_fixed_put (GTK_FIXED (win), label, 0, 0);
  gtk_widget_show (win);

  gtk_fixed_put (GTK_FIXED (cw), win, 0, (errline - 1) * YHEIGHT);
  gtk_widget_modify_style (win, rc_style);
  gtk_rc_style_unref (rc_style);
  gtk_widget_show (label);
  gtk_object_set_data (GTK_OBJECT (cw), "ERRORLABELWIN", win);
}

/**
 * Clear an error in GTK GUI mode.
 */
void
clr_error_gtk (void)
{
  GtkWidget *cw;
  GtkWidget *win;

  cw = (GtkWidget *) get_curr_win_gtk ();
  win = gtk_object_get_data (GTK_OBJECT (cw), "ERRORLABELWIN");
  if (win)
    {
      gtk_widget_destroy (win);
    }
  gtk_object_set_data (GTK_OBJECT (cw), "ERRORLABELWIN", 0);
}



/**
 * Alocate the color red.
 *
 * @todo : Understand if this function is not used.
 */
void
set_red (void)
{
  GdkColormap *cmap;
  GdkColor color;
  cmap = gdk_colormap_get_system ();
  color.red = 0xffff;
  color.green = 0;
  color.blue = 0;
  if (!gdk_color_alloc (cmap, &color))
    {
      g_error ("couldn't allocate color");
    }
}

/**
 * Show a message in a label from the current window.
 *
 * @param s A string with the message to be showed.
 */
void
msg_window_gtk (char *s)
{
  GtkWidget *cw;
  GtkWidget *label;
  GtkWidget *win;
  int msgline;
  debug ("A0");
  cw = (GtkWidget *) get_curr_win_gtk ();
  debug ("A0.1");
  win = gtk_object_get_data (GTK_OBJECT (cw), "MESSAGELABELWIN");

  if (win)
    gtk_widget_destroy (GTK_WIDGET (win));
  if (strlen (s) == 0)
    return;

  msgline = decode_line_gtk (getmsg_line_gtk ());
  debug ("A1 - msgline = %d", msgline);
  win = gtk_fixed_new ();
  debug ("A2");
  gtk_widget_set_usize (GTK_WIDGET (win), get_curr_width () * XWIDTH,
			YHEIGHT);
  debug ("A2.1");
  label = gtk_label_new (s);
  debug ("A3");
  gtk_fixed_put (GTK_FIXED (win), label, 0, 0);
  gtk_widget_show (win);

  debug ("A4");
  gtk_fixed_put (GTK_FIXED (cw), win, 0, (msgline - 1) * YHEIGHT);
  debug ("A5");
  gtk_widget_show (label);
  debug ("A6");
  gtk_object_set_data (GTK_OBJECT (cw), "MESSAGELABELWIN", win);
}


/* ============================ EOF ================================ */

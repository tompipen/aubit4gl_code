/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-2005 Aubit Development Team (See Credits file)    |
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
# $Id: dialog.c,v 1.5 2005-06-18 09:56:57 mikeaubury Exp $
#*/

/**
 * @file
 * Modal Message Boxes in GTK GUI mode.
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 */

/*
=====================================================================
                                    Includes
=====================================================================
*/


#include <stdio.h>
#include <gtk/gtk.h>
#include <glade/glade.h>
#include "a4gl_libaubit4gl.h"
#include "a4gl_API_ui_lib.h"

/*
=====================================================================
                    Constants definitions
=====================================================================
*/

#define DIALOG_DISABLE_NONE    0
#define DIALOG_DISABLE_PROGRAM 1
#define DIALOG_DISABLE_ALL     2

#define BUTTON_OK     1
#define BUTTON_CANCEL 2
#define BUTTON_ABORT  3
#define BUTTON_RETRY  4
#define BUTTON_IGNORE 5
#define BUTTON_YES    6
#define BUTTON_NO     7

#define BUTTONS_OK                      0
#define BUTTONS_OK_CANCEL               1
#define BUTTONS_RETRY_CANCEL            2
#define BUTTONS_ABORT_RETRY_IGNORE      3
#define BUTTONS_YES_NO                  4
#define BUTTONS_YES_NO_CANCEL           5

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

int A4GL_gtkdialog (char *caption, char *icon, int buttons, int defbutt, int dis,
               char *msg);
//void aclfgli_pr_message (int a, int xwait);
//void UILIB_A4GL_display_error (int a, int xwait);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * Dialog event callback.
 *
 * @param widget A pointer to the widget.
 * @param data
 */
static void
dialog_callback (GtkWidget * widget, gpointer data)
{
  GtkObject *win;
  win = GTK_OBJECT (widget);
  A4GL_debug ("Win=%p\n", win);
  gtk_object_set_data (GTK_OBJECT (win),
                       "RETURNS", gtk_object_get_data (data, "BUTCODE"));
  A4GL_debug ("Set code to %d\n", gtk_object_get_data (win, "RETURNS"));
  /* gtk_main_quit(); */
}


/**
 * Add a new button to the dialog.
 *
 * @param win A pointer to the dialog widget.
 * @param but_code The button type code.
 */
static void
add_button (GtkDialog * win, int but_code)
{
  char *txt = "";
  GtkButton *but;
  switch (but_code)
    {
    case 1:
      txt = "OK";
      break;
    case 2:
      txt = "Cancel";
      break;
    case 3:
      txt = "Abort";
      break;
    case 4:
      txt = "Retry";
      break;
    case 5:
      txt = "Ignore";
      break;
    case 6:
      txt = "Yes";
      break;
    case 7:
      txt = "No";
      break;
    }

  gtk_object_set_data (GTK_OBJECT (win), "RETURNS", 0);
  but = (GtkButton *) gtk_button_new_with_label (txt);
  gtk_object_set_data (GTK_OBJECT (but), "BUTCODE", (gpointer) but_code);
  gtk_object_set_data (GTK_OBJECT (but), "DIALOGWIN", win);
  gtk_container_add (GTK_CONTAINER (GTK_DIALOG (win)->action_area),
                     (GtkWidget *) but);
  gtk_signal_connect_object (GTK_OBJECT (but),
                             "clicked",
                             GTK_SIGNAL_FUNC (dialog_callback),
                             GTK_OBJECT (win));
}


/**
 * Create a gtk dialog widget.
 *
 * @param caption The window title.
 * @param icon The icon for the dialog (not used now).
 * @param buttons The type of the buttons to be showed:
 *   - BUTTONS_OK:
 *   - BUTTONS_OK_CANCEL:
 *   - BUTTONS_RETRY_CANCEL:
 *   - BUTTONS_ABORT_RETRY_IGNORE:
 *   - BUTTONS_YES_NO:
 *   - BUTTONS_YES_NO_CANCEL:
 * @param defbutt Not used now
 * @param dis
 * @param msg Message to be showed.
 * @return
 */
int
A4GL_gtkdialog (char *caption, char *icon, int buttons, int defbutt, int dis,
           char *msg)
{
  int rval;
  GtkDialog *win;
  GtkLabel *label;
/*   GtkButton *but; */

/* Only do modal for now... */
  dis = DIALOG_DISABLE_ALL;
  win = (GtkDialog *) gtk_dialog_new ();
  A4GL_debug ("In A4GL_gtkdialog msg=%s\n", msg);

  gtk_window_set_modal ((GtkWindow *) win, 1);

  gtk_signal_connect (GTK_OBJECT (win),
                      "delete_event", GTK_SIGNAL_FUNC (gtk_true), NULL);
  label = (GtkLabel *) gtk_label_new (msg);
  gtk_container_add (GTK_CONTAINER (GTK_DIALOG (win)->vbox),
                     GTK_WIDGET (label));


  if (strlen (caption))
    gtk_window_set_title (GTK_WINDOW (win), caption);

  switch (buttons)
    {
    case BUTTONS_OK:
      add_button (win, BUTTON_OK);
      break;
    case BUTTONS_OK_CANCEL:
      add_button (win, BUTTON_OK);
      add_button (win, BUTTON_CANCEL);
      break;
    case BUTTONS_RETRY_CANCEL:
      add_button (win, BUTTON_RETRY);
      add_button (win, BUTTON_CANCEL);
      break;
    case BUTTONS_ABORT_RETRY_IGNORE:
      add_button (win, BUTTON_ABORT);
      add_button (win, BUTTON_RETRY);
      add_button (win, BUTTON_IGNORE);
      break;

    case BUTTONS_YES_NO:
      add_button (win, BUTTON_YES);
      add_button (win, BUTTON_NO);
      break;

    case BUTTONS_YES_NO_CANCEL:
      add_button (win, BUTTON_YES);
      add_button (win, BUTTON_NO);
      add_button (win, BUTTON_CANCEL);
      break;
    }


  gtk_widget_show_all (GTK_WIDGET (win));
  rval = 0;
  while (1)
    {
      a4gl_usleep (100);
      /* printf("win = %p\n",win); */
      rval = (int) gtk_object_get_data (GTK_OBJECT (win), "RETURNS");
      if (rval)
        break;
      while (gtk_events_pending ())
        gtk_main_iteration ();
    }

  gtk_widget_destroy (GTK_WIDGET (win));

  return rval;
}




#ifdef DOTEST
/**
 * Main for testing the dialogs
 */
main (int argc, char *argv[])
{
  int a;
  gtk_init (&argc, &argv);
  a =
    A4GL_gtkdialog ("Warning", "Warn.gif", BUTTONS_YES_NO_CANCEL, BUTTON_CANCEL, 0,
               "Are you really really sure ?");
  A4GL_debug ("Returned %d\n", a);
}

#endif

/**
 * Print a message in GTK GUI mode.
 *
 * @param a Not used.
 * @param xwait The time to wait during the message presentation.
 */
void
 UILIB_aclfgli_pr_message_internal (int a, int xwait,char *s)
{
//  char *p;
        /**
         * @todo : This should be fixed by including stack.h not cast
         * but the headers needs some clean.
         */

  if (xwait||1)
    A4GL_gtkdialog ("Message", "", BUTTONS_OK, BUTTON_OK, 0, s);
  //else
    //A4GL_msg_window_gtk (s);
}

/**
 * Display a error received by the char stack.
 *
 * @param a Not used
 * @param xwait - 0 : The Do not wait for OK.
 *             - 1 : Show a window witj OK button.
 */
void
 UILIB_A4GL_display_error (int a, int xwait)
{
  char *p;
  p = (char *) A4GL_char_pop ();
  if (xwait||1)
    A4GL_gtkdialog ("Error", "", BUTTONS_OK, BUTTON_OK, 0, p);
  //else
    //A4GL_error_window_gtk (p);

  free (p);
}


void UILIB_A4GL_zrefresh(void) {
}



void
UILIB_A4GL_set_option_value_for_current_window (char type, int keyval) {
}


int UILIB_A4GL_get_option_value_for_current_window (char type) {
	return 0;
}

void
UILIB_A4GL_ui_exit(void) {
        // Does nothing - required by the API
}


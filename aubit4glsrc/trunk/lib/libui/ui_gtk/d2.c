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
# $Id: d2.c,v 1.1 2002-06-26 06:11:44 afalout Exp $
#*/

/**
 * @file
 * Event handling functions.
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/



#ifdef OLD_INCL
	
	#include <stdio.h>

	#include <gtk/gtk.h>

	#include "a4gl_formxw.h"
	#include "a4gl_gtk_dims.h"
	#include "a4gl_debug.h"

#else

    #include "a4gl_lib_ui_gtk_int.h"

#endif


/*
=====================================================================
                    Variables definitions
=====================================================================
*/

GtkWidget *tooltips;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/


#ifdef OLD_INCL
	gint delete_event (GtkWidget * widget, GdkEvent * event, gpointer data);
	void destroy_event (GtkWidget * widget, gpointer data);
#endif

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * If you return FALSE in the "delete_event" signal handler,
 * GTK will emit the "destroy" signal. Returning TRUE means
 * you don't want the window to be destroyed.
 * This is useful for popping up 'are you sure you want to quit?'
 * type dialogs. 
 *
 * @param widget 
 * @param event
 * @param data
 * @return FALSE
 */
gint
delete_event (GtkWidget * widget, GdkEvent * event, gpointer data)
{

  g_print ("delete event occurred\n");

  /* Change TRUE to FALSE and the main window will be destroyed with
   * a "delete_event". */

  return (FALSE);
}

/**
 * Another callback 
 *
 * @param widget
 * @param data
 */
void
destroy_event (GtkWidget * widget, gpointer data)
{
  gtk_main_quit ();
}


/* ================================ EOF ============================= */

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
# $Id: signals.c,v 1.2 2002-10-13 11:44:40 afalout Exp $
#*/

/**
 * @file
 * Signal management implementation functions
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
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

struct_scr_field *attr;
struct_metrics *metr;
char *field;
char *widgettype;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

void clicked_handler (GtkWidget * w, gpointer user_data);
void changed_handler (GtkWidget * w, gpointer user_data);
void
select_row_handler ( GtkWidget      *w,
                     gint            row,
                     gint            column,
				     GdkEventButton *event,
                     gpointer        user_data );

void grab_focus_handler (GtkWidget * w, gpointer user_data);


#ifdef OLD_INCL
	void add_signal_clicked (GtkWidget * widget, void *funcptr);
	void add_signal_grab_focus (GtkWidget * widget, void *funcptr);
	void add_signal_changed (GtkWidget * widget, void *funcptr);
	void add_signal_select_row (GtkWidget * widget, void *funcptr);
#endif

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * Get some widget information into global variables.
 *
 * @param widget The widget where to assign some attributes.
 */
static void 
set_widget_data (GtkWidget * widget)
{
  attr = gtk_object_get_data (GTK_OBJECT (widget), "Attribute");
  metr = gtk_object_get_data (GTK_OBJECT (widget), "Metric");
  field = gtk_object_get_data (GTK_OBJECT (widget), "Field");
  widgettype = gtk_object_get_data (GTK_OBJECT (widget), "WidgetType");
}

/**
 * Callback function called as listener of a click event ocurred over a widget.
 *
 * @param w The widget where the event was fired.
 * @param user_data A pointer to the callback function that is listening the
 * event.
 */
void
clicked_handler (GtkWidget * w, gpointer user_data)
{
  GtkWidget *nw;
  /* void (*ptr) (); */
  void (*ptr) (GtkWidget *nw, char * a);
  char *l;
  if (user_data)
    ptr = user_data;
  else
    ptr = func;

  debug("Clicked... %p %p",w,user_data);
  l = gtk_object_get_data (GTK_OBJECT (w), "Parent");
  if (l)
    {
      nw = GTK_WIDGET(l);
    }
  else
    {
      nw = w;
    }
  debug ("\nclicked - ptr=%p w=%p\n", ptr, nw);

  set_widget_data (nw);
  ptr (nw, "clicked");
}

/**
 *
 * @param w A pointer to the widget.
 * @param user_data
 */
void
changed_handler (GtkWidget * w, gpointer user_data)
{
  GtkWidget *nw;
  /* void (*ptr) (); */
    void (*ptr) (GtkWidget *nw, char * a);
  char *l;

  if (user_data)
    ptr = user_data;
  else
    ptr = func;

  l = gtk_object_get_data (GTK_OBJECT (w), "Parent");
  /* Is this a change on part of a larger widget  (eg combo/radio) */
  if (l)
    {
      nw = GTK_WIDGET(l);			/* Yes - signal the parent */
    }
  else
    {
      nw = w;			/* No - keep the signal for this widget */
    }
  debug ("\nchanged - ptr=%p w=%p\n", ptr, nw);
  set_widget_data (nw);
  ptr(nw,"on");
}


/**
 *
 * @todo Describe function
 */
void
select_row_handler ( GtkWidget      *w,
                     gint            row,
                     gint            column,
				     GdkEventButton *event,
                     gpointer        user_data )

{
  GtkWidget *nw;
  /* void (*ptr) (); */
  void (*ptr) (GtkWidget *nw, char * a);
  char *l;

  if (user_data)
    ptr = user_data;
  else
    ptr = func;

  l = gtk_object_get_data (GTK_OBJECT (w), "Parent");
  /* Is this a change on part of a larger widget  (eg combo/radio) */
  if (l)
    {
      nw = GTK_WIDGET(l);			/* Yes - signal the parent */
    }
  else
    {
      nw = w;			/* No - keep the signal for this widget */
    }

  set_widget_data (nw);

  if (ptr) ptr(nw,"on");

  else {
	printf("Nothing to do\n");
  }
}



/**
 *
 * @todo Describe function
 */
void
grab_focus_handler (GtkWidget * w, gpointer user_data)
{
  GtkWidget *nw;
  /* void (*ptr) (); */
  void (*ptr) (GtkWidget *nw, char * a);

  char *l;
  
  debug("Focus change ");

  if (user_data)
    ptr = user_data;
  else
    ptr = func;

  l = gtk_object_get_data (GTK_OBJECT (w), "Parent");
  if (l)
    {
      nw = GTK_WIDGET(l);
    }
  else
    {
      nw = w;
    }

  set_widget_data (nw);
  debug ("\nGrab focus w=%p ptr=%p\n", nw, ptr);

  ptr (nw, "grab_focus");
}

/**
 * Add a clicked standard (in this library) event listener.
 *
 * @param widget The widget that we want to add a listener.
 * @param funcptr A pointer to an aditional listener callback.
 */
void
add_signal_clicked (GtkWidget * widget, void *funcptr)
{
  gtk_signal_connect (GTK_OBJECT (widget), "clicked",
		      GTK_SIGNAL_FUNC (clicked_handler), funcptr);
}


/**
 *
 * @todo Describe function
 */
void
add_signal_grab_focus (GtkWidget * widget, void *funcptr)
{
  gtk_signal_connect (GTK_OBJECT (widget), "grab-focus",
		      GTK_SIGNAL_FUNC (grab_focus_handler), funcptr);
}

/**
 *
 * @todo Describe function
 */
void
add_signal_changed (GtkWidget * widget, void *funcptr)
{
  gtk_signal_connect (GTK_OBJECT (widget), "changed",
		      GTK_SIGNAL_FUNC (changed_handler), funcptr);
}


/**
 *
 * @todo Describe function
 */
void
add_signal_select_row (GtkWidget * widget, void *funcptr)
{
  gtk_signal_connect (GTK_OBJECT (widget), "select_row",
		      GTK_SIGNAL_FUNC (select_row_handler), funcptr);
}


/* =========================== EOF ============================= */

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
# $Id: display.c,v 1.13 2003-10-11 09:53:39 afalout Exp $
#*/

/**
 * @file
 * 4gl DISPLAY statement implementation in GUI mode
 *
 * NEWWIDGET
 *
 * New widgets types will need information entered into this file
 * Look for the NEWWIDGET comment in the code.
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

extern GtkWindow *currwindow;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/


#ifdef OLD_INCL
int A4GL_display_generic (GtkWidget * k, char *s);
GtkWidget *A4GL_find_widget (GtkWindow * form, char *ident);
void A4GL_dump_mem (char *ptr);
#endif

/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/**
 * Display information to a widget.
 *
 * Check the widget type and use the apropriate method to do it.
 *
 * @param k A pointer to the widget where to display the information
 * @param s A pointer to the information to be displayed.
 * @return The result of the display:
 *   - 1 : Information displayed.
 *   - 0 :idget type not found.
 */
int
A4GL_display_generic (GtkWidget * k, char *s)
{
  char *ptr;
  A4GL_debug ("in A4GL_display_generic k=%p s='%s'\n", k, s);

  ptr = gtk_object_get_data (GTK_OBJECT (k), "WidgetType");

  if (ptr == 0)
    {
      A4GL_debug ("Cant find tyhe widget!");
      return 1;
    }

  A4GL_debug ("Widgettye=%s\n", ptr);

  if (strcasecmp (ptr, "BUTTON") == 0)
    {
      GtkWidget *w;
      w = gtk_object_get_data (GTK_OBJECT (k), "LABEL");
      if (w)
	{
	  gtk_label_set_text (GTK_LABEL (w), s);
	}
    }



  if (strcasecmp (ptr, "LABEL") == 0)
    {
#if ! GTK_CHECK_VERSION(2,0,0)
	GtkStyle *style;
#endif
      gtk_label_set_text (GTK_LABEL (k), s);

/* check whether a Gtk+ version equal to or greater than
 * major.minor.micro is present.
 */
#if GTK_CHECK_VERSION(2,0,0)

 A4GL_ChangeWidgetFont(k,"FIXED");
    // GTK+ 2.0 and up: structure has no member named `font'
#else
    style = gtk_style_new ();
	gdk_font_unref (style->font);
    style->font = gdk_font_load ("fixed");
	gtk_widget_set_style (k, style);
#endif
      return 1;
    }

  if (strcasecmp (ptr, "ENTRY") == 0 || strcasecmp (ptr, "TEXT") == 0)
    {
      gtk_entry_set_text (GTK_ENTRY (k), s);
      return 1;
    }


  if (strcasecmp (ptr, "LIST") == 0)
    {
      printf ("Adding to list...\n");
      fflush (stdout);

      k = gtk_object_get_data (GTK_OBJECT (k), "Child");
      gtk_clist_append (GTK_CLIST (k), &s);

    }


  if (strcasecmp (ptr, "RADIO") == 0)
    {
      int a;
      GtkWidget *btn;
      char *ptr;
      char buff[20];
      for (a = 0;; a++)
	{
	  sprintf (buff, "B%d", a + 1);
	  A4GL_debug ("Looking for button %s\n", buff);
	  btn = gtk_object_get_data (GTK_OBJECT (k), buff);
	  A4GL_debug ("Got btn=%p\n", btn);
	  if (btn == 0)
	    break;
	  ptr = gtk_object_get_data (GTK_OBJECT (btn), "Value");
	  A4GL_debug ("Got value=%s - compare to %s\n", ptr, s);
	  if (strcmp (ptr, s) == 0)
	    {
	      A4GL_debug ("Ok - set it\n");
	      gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (btn), 1);
	      return 1;
	    }
	}
      return 0;
    }

  if (strcasecmp (ptr, "CALENDAR") == 0)
    {
      int da;
      int d, m, y;
      char ss[21];
      strcpy (ss, s);
      A4GLSQL_set_status (0, 0);
      A4GL_trim (ss);
      if (strlen (ss) == 0)
	{
	  gtk_calendar_clear_marks (GTK_CALENDAR (k));
	  return 0;
	}

      A4GL_debug ("s set to %s\n", ss);
      A4GL_push_variable (&ss, 0x140000);
      A4GL_pop_var2 (&da, 7, 0);
      A4GL_debug ("Got date as %d\n", da);

      if (a4gl_status != 0)
	return 1;
      A4GL_debug ("Everything seems ok...");

      A4GL_push_variable (&da, 0x7);
      aclfgl_day (1);
      A4GL_pop_var2 (&d, 2, 0);

      A4GL_push_variable (&da, 0x7);
      aclfgl_month (1);
      A4GL_pop_var2 (&m, 2, 0);

      A4GL_push_variable (&da, 0x7);
      aclfgl_year (1);
      A4GL_pop_var2 (&y, 2, 0);

      gtk_calendar_select_month (GTK_CALENDAR (k), m, y);
      gtk_calendar_select_day (GTK_CALENDAR (k), d);
      return 1;
    }

  if (strcasecmp (ptr, "SCROLLBAR") == 0)
    {
      gdouble d;
      d = atof (s);
      gtk_adjustment_set_value ((GtkAdjustment *) GTK_ENTRY (k), d);
      /*
         #define GTK_ENTRY(obj)                  (GTK_CHECK_CAST ((obj), GTK_TYPE_ENTRY, GtkEntry))

         void       gtk_adjustment_set_value             (GtkAdjustment   *adjustment,
         gfloat           value);
       */
      return 1;
    }

/* NEWWIDGET - Add here */

  return 0;
}


/**
 *
 * @param form The form widget where to find the sub-widget.
 * @param ident A string that identifies the widget wanted.
 * @return The widget founded.
 */
GtkWidget *
A4GL_find_widget (GtkWindow * form, char *ident)
{
  GtkWidget *w;

  A4GL_debug ("find_widget");
  if (form == 0)
    form = currwindow;

  w = gtk_object_get_data (GTK_OBJECT (form), "currform");


  if (w == 0)
    {
      A4GL_debug ("Bad form displayed\n");
      return 0;			/* Can't find form.. */
    }
  w = gtk_object_get_data (GTK_OBJECT (w), ident);
  if (w == 0)
    {
      A4GL_debug ("Field not found displayed\n");
      return 0;			/* Can't find widget.. */
    }
  return w;
}


/**
 * Dump the content of a string to the A4GL_debug as integers.
 *
 * @param ptr A pointer to the information that we want to dump.
 */
void
A4GL_dump_mem (char *ptr)
{
  int a;
  A4GL_debug ("Mem A4GL_dump for %p\n", ptr);
	return;
  for (a = 0; a < 32; a++)
    {
      A4GL_debug ("%d : %x", a, ptr[a]);
    }
}


/* ============================= EOF ============================ */

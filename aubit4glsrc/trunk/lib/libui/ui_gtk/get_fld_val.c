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
# $Id: get_fld_val.c,v 1.6 2003-05-15 07:10:46 mikeaubury Exp $
#*/

/**
 * @file
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
                    Functions prototypes
=====================================================================
*/

#ifdef OLD_INCL
char *A4GL_fld_val_generic (GtkWidget * k);
#endif

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * Get the value filled in a widget.
 * The value could be typed by the user or filled with defaults in input or
 * display 4gl statements.
 *
 * Check the widget type and execute the corresponding function to get the data.
 *
 * @param k The widget where to get the filled values.
 * @return  The value in the widget.
 */
char *
A4GL_fld_val_generic (GtkWidget * k)
{
  char *ptr;
  char *txt;
  A4GL_debug ("in A4GL_fld_val_generic k=%p\n", k);

  ptr = gtk_object_get_data (GTK_OBJECT (k), "WidgetType");

  if (ptr == NULL)
    {
      A4GL_debug ("Cant find tyhe widget!");
      return (char *) 1;
    }

  A4GL_debug ("Widgettye=%s\n", ptr);

  if (strcasecmp (ptr, "LABEL") == 0)
    {
      gtk_label_get (GTK_LABEL (k), &txt);
      return txt;
    }

  if (strcasecmp (ptr, "ENTRY") == 0 || strcasecmp (ptr, "TEXT") == 0)
    {
      return gtk_entry_get_text (GTK_ENTRY (k));
      return (char *) 1;
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
	  btn = gtk_object_get_data (GTK_OBJECT (k), buff);
	  if (btn == 0)
	    break;
	  if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (btn)))
	    {
	      ptr = gtk_object_get_data (GTK_OBJECT (btn), "Value");
	      return ptr;
	    }
	}
      return NULL;
    }


  if (strcasecmp (ptr, "CALENDAR") == 0)
    {
      int d, m, y;
      static char buff[256];

      gtk_calendar_get_date (GTK_CALENDAR (k), &y, &m, &d);
      A4GL_push_variable (&m, 0x2);
      A4GL_push_variable (&d, 0x2);
      A4GL_push_variable (&y, 0x2);
      aclfgl_mdy (3);
      A4GL_pop_var2 (&buff, 0, 20);
      A4GL_trim (buff);
      return buff;
    }

  if (strcasecmp (ptr, "SCROLLBAR") == 0)
    {
      static char buff[20];
      /* d=gtk_adjustment_get_value (GTK_ADJUSTMENT(k)); */
      sprintf (buff, "%d", 0);
      return buff;
    }

/* NEWWIDGET - Add here */


  return NULL;
}

/* ================================ EOF ================================ */

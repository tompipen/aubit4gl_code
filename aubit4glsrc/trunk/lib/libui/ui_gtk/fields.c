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
# $Id: fields.c,v 1.7 2003-07-18 16:17:32 mikeaubury Exp $
#*/

/**
 * @file
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

//void A4GL_endis_fields_ap (int en_dis, va_list * ap);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * Enable or disable fields in GTK GUI mode.
 *
 * @param en_dis The A4GL_action to do:
 *   - D : Disable
 *   - E : Enable
 * @param ... The list of the fields to be enabled or disabled.
 */
int
A4GL_endis_fields_ap (int en_dis, va_list * ap)
{
  GtkWidget *formdets;
  int a;
  int nofields;
  GtkWidget **field_list;
  formdets = GTK_WIDGET (A4GL_get_curr_form (1));


  A4GL_debug ("Formdets = %p\n", formdets);

  nofields =
    A4GL_gen_field_list_gtk (&field_list, (GtkWindow *) formdets, 9999, ap);
  A4GL_debug ("nofields=%d\n", nofields);

  for (a = 0; a <= nofields; a++)
    {
      A4GL_debug ("Doing something to %p %d\n", field_list[a], en_dis);
      A4GL_gui_set_active (field_list[a], en_dis);
    }
return 1;
}


/**
 * Enable or disable a widget in GTK GUI mode.
 *
 * @param w The widget to be changed.
 * @param en_dis The A4GL_action to do:
 *   - D : Disable.
 *   - E : Enable.
 */
void
A4GL_gui_set_active (GtkWidget * w, int en_dis)
{
  GtkWidget *p;
  A4GL_debug ("Set active : %p %d", w, en_dis);
  p = gtk_object_get_data (GTK_OBJECT (w), "Child");
  A4GL_debug ("p=%p", p);
  if (p == 0)
    p = w;
  A4GL_debug (" activate %p ", p);
  gtk_widget_set_sensitive (p, en_dis);

}


/* ============================= EOF =========================== */

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
# $Id: fields.c,v 1.2 2002-10-13 11:44:40 afalout Exp $
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

void endis_fields (int en_dis,va_list *ap);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * Enable or disable fields in GTK GUI mode.
 *
 * @param en_dis The action to do:
 *   - D : Disable
 *   - E : Enable
 * @param ... The list of the fields to be enabled or disabled.
 */
void
endis_fields (int en_dis,va_list *ap)
{
  GtkWidget *formdets;
  int a;
  int nofields;
  GtkWidget **field_list;
  formdets = GTK_WIDGET(get_curr_form ());


  debug("Formdets = %p\n",formdets);

  nofields = gen_field_list_gtk (&field_list, (GtkWindow *)formdets, 9999, ap);
  debug("nofields=%d\n",nofields);

  for (a = 0; a <= nofields; a++)
    {
	debug("Doing something to %p %d\n",field_list[a],en_dis);
      gui_set_active (field_list[a], en_dis);
    }
}


/**
 * Enable or disable a widget in GTK GUI mode.
 *
 * @param w The widget to be changed.
 * @param en_dis The action to do:
 *   - D : Disable.
 *   - E : Enable.
 */
void
gui_set_active(GtkWidget *w,int en_dis)
{
  GtkWidget *p;
  debug("Set active : %p %d",w,en_dis);
	p=gtk_object_get_data (GTK_OBJECT(w), "Child");
  debug("p=%p",p);
	if (p==0) p=w;
  debug(" activate %p ",p);
	gtk_widget_set_sensitive (p, en_dis);

}


/* ============================= EOF =========================== */

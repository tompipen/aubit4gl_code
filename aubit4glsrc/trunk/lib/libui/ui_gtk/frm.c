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
# $Id: frm.c,v 1.8 2003-12-12 16:15:05 mikeaubury Exp $
#*/

/**
 * @file
 * Form management in GTK mode.
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen A4GL_comments to add to functions
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

int A4GL_find_attrib_from_field (struct_form * f, int field_no);
int A4GL_find_fields_no_metric (struct_form * f, int metric_no);

#ifdef OLD_INCL
char *A4GL_make_colname_from_metric (struct_form * f, int metric_no);
char *A4GL_make_field_from_metric (struct_form * f, int metric_no);
#endif

//void clr_form(int to_default);


/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * Find attributes of the forms from metric.
 *
 * @param f The pointer to a form structure.
 * @param metric_no The metric number.
 * @return
 */
int
A4GL_find_attrib_from_metric (struct_form * f, int metric_no)
{
  return A4GL_find_attrib_from_field (f, A4GL_find_fields_no_metric (f, metric_no));
}

/**
 * Find fields
 *
 * @param f A pointer to a form describing strucutre.
 * @param metric_no The metric sequence number.
 * @return The metric number.
 */
int
A4GL_find_fields_no_metric (struct_form * f, int metric_no)
{
  int a, b;
  A4GL_debug ("BB\n");
  for (a = 0; a < f->fields.fields_len; a++)
    {
      for (b = 0; b < f->fields.fields_val[a].metric.metric_len; b++)
	{
	  if (f->fields.fields_val[a].metric.metric_val[b] == metric_no)
	    {
	      return a;
	    }
	}
    }

  return 0;
}

/**
 *
 * @param f The pointer to a form structure.
 * @param metric_no The metric number.
 * @return
 */
char *
A4GL_make_colname_from_metric (struct_form * f, int metric_no)
{
  int a, b;
  int c;
  static char buff[256];
  A4GL_debug ("BB metric_no=%d\n", metric_no);
  a = A4GL_find_fields_no_metric (f, metric_no);

  for (b = 0; b < f->fields.fields_val[a].metric.metric_len; b++)
    {
      if (f->fields.fields_val[a].metric.metric_val[b] == metric_no)
	{
	  break;
	}
    }

  A4GL_debug ("a3\n");

  c = A4GL_find_attrib_from_field (f, a);
  if (c == -1)
    {
      return "";
    }

  A4GL_debug ("Here a=%d b=%d c=%d\n", a, b, c);
  sprintf (buff, "%s", f->attributes.attributes_val[c].colname);
  A4GL_debug ("Buff=%s\n", buff);
  return buff;
}

/**
 * @param f The pointer to a form structure.
 * @param metric_no The metric number.
 * @return
 */
char *
A4GL_make_field_from_metric (struct_form * f, int metric_no)
{
  int a, b;
  int c;
  static char buff[256];
  A4GL_debug ("BB metric_no=%d\n", metric_no);
  a = A4GL_find_fields_no_metric (f, metric_no);

  for (b = 0; b < f->fields.fields_val[a].metric.metric_len; b++)
    {
      if (f->fields.fields_val[a].metric.metric_val[b] == metric_no)
	{
	  break;
	}
    }

  A4GL_debug ("a3\n");

  c = A4GL_find_attrib_from_field (f, a);
  if (c == -1)
    {
      return "";
    }

  A4GL_debug ("Here a=%d b=%d c=%d\n", a, b, c);

  sprintf (buff, "%s.%s[%d]", f->attributes.attributes_val[c].tabname,
	   f->attributes.attributes_val[c].colname, b);

  A4GL_debug ("Buff=%s\n", buff);
  return buff;
}


/**
 * @param f The pointer to a form structure.
 * @param metric_no The metric number.
 * @return
 */
int
A4GL_find_attrib_from_field (struct_form * f, int field_no)
{
  int a;
  A4GL_debug ("AA\n");
  A4GL_debug ("field_no=%d\n", field_no);

  for (a = 0; a < f->attributes.attributes_len; a++)
    {
      A4GL_debug ("   a=%d\n", a);
      if (f->attributes.attributes_val[a].field_no == field_no)
	{
	  A4GL_debug ("Found field %d @ %d\n", field_no, a);
	  return a;
	}
    }
  A4GL_debug ("Not found\n");
  return -1;

}

/**
 * Add the widgets from form to a panel.
 *
 * Gets all the fields defined in the form, create and add it to the form
 * panel.
 *
 * @param f The pointer to a form structure.
 * @param panel_to_add_to_window
 */
void
A4GL_make_widgets (struct_form * f, GtkWidget * panel_to_add_to_window)
{
  int a;
  A4GL_debug ("Making Widgets..\n");
  for (a = 0; a < f->metrics.metrics_len; a++)
    {
      A4GL_debug ("Making Widget %d\n", a);
      A4GL_add_widget (a, f, panel_to_add_to_window);
    }
  A4GL_debug_last_field_created ("make_widgets");
}

/**
 * Not implemented yet.
 */
void
 UILIB_A4GL_clr_form (int to_default)
{
  /* Not implemented yet */
}



int UILIB_A4GL_read_metrics (void *formdets) {
	// Does nothing in GTK - but we need a function to be here anyway...
	return 1;
}
int
 UILIB_A4GL_read_fields (void *formdetsv) {
	// Does nothing in GTK - but we need a function to be here anyway...
	return 1;
}




/* =============================== EOF ============================== */

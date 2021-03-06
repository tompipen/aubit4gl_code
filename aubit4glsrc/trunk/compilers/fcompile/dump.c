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
# | contact licensing@aubit.com                                           |
# +----------------------------------------------------------------------+
#
# $Id: dump.c,v 1.24 2009-05-26 12:16:57 mikeaubury Exp $
#*/

/**
 * @file
 *
 *
 *
 *
 *
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_fcompile_int.h"
#include "dump_form.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/


char *desc_str[] = {
  "INCLUDE",
  "PICTURE",
  "FORMAT",
  "DEFAULT",
  "PROGRAM",
  "WIDGET", /* old style */
  "CONFIG",
  "COMMENTS",
  "CLASS",
  "ACTION",
  "IMAGE",
  "STYLE",
  "WIDGETTYPE", /* new style */

  0
};

char *desc_bool[] = {
  "AUTONEXT",
  "REVERSE",
  "INVISIBLE",
  "NOENTRY",
  "VERIFY",
  "WORDWRAP",
  "COMPRESS",
  "UPSHIFT",
  "DOWNSHIFT",
  "REQUIRED",
  "NOUPDATE",
  "QUERYCLEAR",
  "ZEROFILL",
  "RIGHT",
  "HIDDEN",
  "SCROLL",
  "WANTTABS",
  "WANTNORETURNS",
  "FONTPITCHFIXED",
  "FONTPITCHVARIABLE",
        "AUTOSCALE",
        "STRETCH_BOTH",
        "STRETCH_Y",
        "SCROLLBARS_BOTH",
        "SCROLLBARS_VERTICAL",
        "SCROLLBARS_HORIZONAL",
        "AUTOSIZE",
        "NOTNULL",

  0
};

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/


static void dump_attributes (struct_form * f);
static void dump_metrics (struct_form * f);
static void dump_fields_desc (struct_form * f);
static void dump_records (struct_form * f);
static void dump_tables (struct_form * f);
//andrej void dump_form_desc (struct_form * f);
void dump_expr_1 (t_expression * expr, int lvl);
void print_lvl_1 (int lvl);



/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/**
 * Dumps a complete form description
 * It calls all the specific dumps(attributes, metrics, field description
 * and tables)
 *
 * @param f A pointer to the form description structure
 */
void
dump_form_desc (struct_form * f,char *fname)
{
  int a;
  printf ("DB         : '%s'\n", f->dbname);
  printf ("Delimiters : '%s'\n", f->delim);
  printf ("maxcol     : %d\n", f->maxcol);
  printf ("maxline    : %d\n", f->maxline);
  printf ("XDR Version: %ld\n", f->fcompile_version);
  printf ("Compiled   : %s\n", ctime (&f->compiled_time));

  printf ("Screens :%d\n", f->snames.snames_len);
  for (a = 0; a < f->snames.snames_len; a++)
    {
      printf ("%s\n", f->snames.snames_val[a].name);
    }

  dump_attributes (f);
  dump_metrics (f);
  dump_fields_desc (f);
  dump_records (f);
  dump_tables (f);
}

/**
 * Make a text A4GL_dump of the form attributes
 *
 * @param f A pointer to a form description record
 */
static void
dump_attributes (struct_form * f)
{
int a;
int b;
	printf ("\nAttributes %d\n", f->attributes.attributes_len);
	for (a = 0; a < f->attributes.attributes_len; a++) {
		printf ("Attribute %d\n", a);
		printf ("   field_no : %d\n", f->attributes.attributes_val[a].field_no);
		printf ("   colname : '%s'\n", f->attributes.attributes_val[a].colname);
		printf ("   tabname : '%s'\n", f->attributes.attributes_val[a].tabname);
		printf ("   subscript[0] : %d\n",f->attributes.attributes_val[a].subscripts[0]);
		printf ("   subscript[1] : %d\n",f->attributes.attributes_val[a].subscripts[1]);
		printf ("   subscript[2] : %d\n", f->attributes.attributes_val[a].subscripts[2]);
		printf ("   datatype : %d (%d)\n", f->attributes.attributes_val[a].datatype,
	      	f->attributes.attributes_val[a].dtype_size);
		printf ("   dynamic  : %d\n", f->attributes.attributes_val[a].dynamic);
		for (b = 0; b < f->attributes.attributes_val[a].str_attribs.str_attribs_len; b++) {
			printf ("          STRING (%d) %s='%s'\n",
				f->attributes.attributes_val[a].str_attribs.str_attribs_val[b].type,
				desc_str[f->attributes.attributes_val[a].str_attribs.str_attribs_val[b].type],
				f->attributes.attributes_val[a].str_attribs.str_attribs_val[b].value);
		}
		for (b = 0; b < f->attributes.attributes_val[a].bool_attribs.bool_attribs_len; b++){
			printf ("          BOOLEAN %d %s\n",
				f->attributes.attributes_val[a].bool_attribs.bool_attribs_val[b],
				desc_bool[f->attributes.attributes_val[a].bool_attribs.bool_attribs_val[b]]);
		}
		if (f->attributes.attributes_val[a].colours.colours_len) {
			int b;
			printf ("   Specified colours (%d)\n", f->attributes.attributes_val[a].colours.colours_len);
			for (b = 0; b < f->attributes.attributes_val[a].colours.colours_len;b++){
				printf ("        colour=%d WHERE ",
					(int)f->attributes.attributes_val[a].colours.colours_val[b].colour);
				dump_expr_1 (f->attributes.attributes_val[a].colours.colours_val[b].whereexpr, 0);
			}
		}
    }
}

/**
 * Make a text A4GL_dump of all text elements from the screen image
 *
 * @param f A pointer to a form description record
 */
static void
dump_metrics (struct_form * f)
{
  int a;
  printf ("\nMetrics %d\n", f->metrics.metrics_len);
  for (a = 0; a < f->metrics.metrics_len; a++)
    {
      printf ("a=%d x=%d y=%d w=%d h=%d scr=%d del=%d label='%s'\n", a,
	      f->metrics.metrics_val[a].x,
	      f->metrics.metrics_val[a].y,
	      f->metrics.metrics_val[a].w,
	      f->metrics.metrics_val[a].h,
	      f->metrics.metrics_val[a].scr,
	      f->metrics.metrics_val[a].delim_code,
	      f->metrics.metrics_val[a].label);
    }
}

/**
 * Text dumps screen record field information
 *
 * @param f A pointer to a form description record
 */
static void
dump_fields_desc (struct_form * f)
{
  int a, b;
  printf ("\nFields %d\n", f->fields.fields_len);
  for (a = 0; a < f->fields.fields_len; a++)
    {
      printf (" %d Tag '%s'\n", a, f->fields.fields_val[a].tag);
      for (b = 0; b < f->fields.fields_val[a].metric.metric_len; b++)
	{
	  printf ("   %d\n", f->fields.fields_val[a].metric.metric_val[b]);
	}
    }
}

/**
 * Make a text A4GL_dump of the screen record information
 *
 * @param f A pointer to a form description record
 */
static void
dump_records (struct_form * f)
{
  int a, b;
  printf ("\nRecords %d\n", f->records.records_len);
  for (a = 0; a < f->records.records_len; a++)
    {
      printf ("%d '%s' %d\n", a, f->records.records_val[a].name,
	      f->records.records_val[a].dim);
      for (b = 0; b < f->records.records_val[a].attribs.attribs_len; b++)
	{
	  printf ("    %d\n",
		  f->records.records_val[a].attribs.attribs_val[b]);
	}
    }
}

/**
 * Dumps a text representation of tables loaded from the parser
 *
 * @param f A pointer to a form description record
 */
static void
dump_tables (struct_form * f)
{
  int a;
  printf ("\nTables %d\n", f->tables.tables_len);
  for (a = 0; a < f->tables.tables_len; a++)
    {
      printf ("%d '%s' '%s'\n", a, f->tables.tables_val[a].tabname,
	      f->tables.tables_val[a].alias);
    }
}



/**
 *
 *
 * @param
 */
void
dump_expr_1 (t_expression * expr, int lvl)
{
  t_complex_expr *ptr2;
  int a;


  if (expr->itemtype == ITEMTYPE_INT)
    {
      print_lvl_1 (lvl);
      printf ("%%%d", expr->u_expression_u.intval);
    }

  if (expr->itemtype == ITEMTYPE_SPECIAL)
    {
      print_lvl_1 (lvl);
      printf ("*%s", expr->u_expression_u.special);
    }

  if (expr->itemtype == ITEMTYPE_LIST)
    {
      print_lvl_1 (lvl);
      printf ("[");
      for (a = 0; a < expr->u_expression_u.listy.listy_len; a++)
	{
	  dump_expr_1 (expr->u_expression_u.listy.listy_val[a].listx, lvl + 1);
	}
      printf ("]");
    }

  if (expr->itemtype == ITEMTYPE_FIELD)
    {
      print_lvl_1 (lvl);
      printf ("$%s", expr->u_expression_u.field);
    }

  if (expr->itemtype == ITEMTYPE_CHAR)
    {
      print_lvl_1 (lvl);
      printf ("'%s'", expr->u_expression_u.charval);
    }

  if (expr->itemtype == ITEMTYPE_NOT)
    {
      printf ("!(");
      dump_expr_1 (expr->u_expression_u.notexpr, lvl + 1);
      printf (")");

    }

  if (expr->itemtype == ITEMTYPE_COMPLEX)
    {
      print_lvl_1 (lvl);
      printf ("(");
      ptr2 = expr->u_expression_u.complex_expr;
      dump_expr_1 (ptr2->item1, lvl + 1);
      print_lvl_1 (lvl);
      printf (" %s ", ptr2->comparitor);
      dump_expr_1 (ptr2->item2, lvl + 1);
      printf (")");

    }

  if (lvl == 0)
    printf ("\n");

}

/**
 *
 *
 * @param
 */
void
print_lvl_1 (int lvl)
{
  int a;
  return;
  for (a = 0; a < lvl; a++)
    {
      printf ("   ");
    }
}


/* ================================ EOF ============================= */

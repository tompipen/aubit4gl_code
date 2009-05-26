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
# $Id: formwrite2.c,v 1.50 2009-05-26 12:16:57 mikeaubury Exp $
#*/

/**
 * @file
 * Functions called by the compiler to load the information about the form
 * being compiled.
 *
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_lib_form_xdr_int.h"
#include <ctype.h>

/* FIXME: duplicated from a4gl_libaubit4gl.h : */
int A4GL_has_str_attribute (struct struct_scr_field *f, int str);

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

extern int as_c;
int cmaxcol = 0;
int cmaxline = 0;
int maxcol;
int maxline;
static int isFormErr=0;

struct struct_screen_record *curr_rec;
char buff_xdr[30000];
extern char *outputfilename;



struct translate_string
{
  char *from;
  char *to;
  char *identifier;
};


extern struct translate_string *translate_list;
extern int translate_list_cnt;


/** File pointer to compiled form object file */
FILE *fxx;
FILE *fyy;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

static void translate_form (void);
extern char *A4GL_translate (char *s);	/* translate.c */
//extern void yyerror(char *s);                 /* fcompile.c */
static void real_set_field (char *s, struct struct_scr_field *f);
static void real_add_str_attr (struct struct_scr_field *f, int type,
			       char *str);
static void real_add_bool_attr (struct struct_scr_field *f, int type);
static int real_isolated_xdr_struct_form (XDR * xdrp,
					  struct struct_form *the_form);
int A4GL_isolated_xdr_struct_form (void *xdrp, void *the_form);


/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * Alocate memory to a new attribute structure and initializes the values
 * of each properties
 */
static void
new_attribute (void)
{
  A4GL_debug ("new_attribute\n");
  the_form.attributes.attributes_len++;
  the_form.attributes.attributes_val =
    realloc (the_form.attributes.attributes_val,
	     the_form.attributes.attributes_len *
	     sizeof (struct struct_scr_field));

  the_form.attributes.attributes_val[the_form.attributes.attributes_len -
				     1].str_attribs.str_attribs_len = 0;
  the_form.attributes.attributes_val[the_form.attributes.attributes_len -
				     1].str_attribs.str_attribs_val = 0;
  the_form.attributes.attributes_val[the_form.attributes.attributes_len -
				     1].bool_attribs.bool_attribs_len = 0;
  the_form.attributes.attributes_val[the_form.attributes.attributes_len -
				     1].bool_attribs.bool_attribs_val = 0;

  the_form.attributes.attributes_val[the_form.attributes.attributes_len - 1].general_ptr=0;
  the_form.attributes.attributes_val[the_form.attributes.attributes_len - 1].do_reverse=0;
  the_form.attributes.attributes_val[the_form.attributes.attributes_len - 1].flags=0;
}


/**
 * Initialize the default values of the last element from the field(s) 
 * array of the current form (the one that is being compiled).
 *
 * It leaves the global field description pointer pointing to the new array
 * element.
 */
void
A4GLFORM_A4GL_init_fld (void)
{
  int cnt;
  A4GL_debug ("init_fld\n");
  new_attribute ();
//extern struct struct_scr_field *fld;

  cnt = the_form.attributes.attributes_len - 1;

#define xxfield the_form.attributes.attributes_val[cnt]

  /*
     the_form.fields.fields_len=0;
     the_form.fields.fields_val=0;
   */

  xxfield.bool_attribs.bool_attribs_len = 0;
  xxfield.bool_attribs.bool_attribs_val = 0;

  xxfield.str_attribs.str_attribs_len = 0;
  xxfield.str_attribs.str_attribs_val = 0;

  xxfield.colname = strdup ("");
  xxfield.tabname = strdup ("");
  xxfield.subscripts[0] = 0;
  xxfield.subscripts[1] = 0;
  xxfield.subscripts[2] = 0;
  //xxfield.colour = -1;
  xxfield.dynamic = 0;
  xxfield.datatype = 0;
  xxfield.dtype_size = 0;
  xxfield.lookup.lookups.lookups_len = 0;
  xxfield.lookup.lookups.lookups_val = 0;
	 A4GL_set_fld (&xxfield);

  A4GL_debug ("done init_fld\n");
}

/**
 * Check if the alias allready exists in the tables array 
 *
 * @param s Alias name
 * @return The table found name or the alias name
 */
static char *
chk_alias (char *s)
{
  int a;
  A4GL_debug ("chk_alias\n");
  for (a = 0; a < the_form.tables.tables_len; a++)
    {
      if (strcasecmp (the_form.tables.tables_val[a].alias, s) == 0)
	return the_form.tables.tables_val[a].tabname;
    }
  return s;
}


/**
 * Find a tag name from the fields array of the form
 *
 * @param s field tag name
 * @return -1 if not found, the index in the array otherwise
 */
int
A4GLFORM_A4GL_find_field (char *s)
{
  int a;
  A4GL_debug ("Looking for tag '%s' in %d fields\n", s,
	 the_form.fields.fields_len);

  for (a = 0; a < the_form.fields.fields_len; a++)
    {
      A4GL_debug ("%s %s", the_form.fields.fields_val[a].tag, s);
      if (strcasecmp (the_form.fields.fields_val[a].tag, s) == 0)
	{
	  A4GL_debug ("Found it @ %d\n", a);
	  return a;
	}
    }

  return -1;
}


int A4GLFORM_A4GL_getFormErr(void)  {
        return isFormErr;
}



/**
 * Display a compilation error and exists
 *
 * @param s Formated string message to pass to printf
 * @param a First parameter of formated string
 * @param b Second parameter of formated string
 */
static void
A4GL_error_with (char *s, char *a, char *b)
{
  static char z[2];
char buff[256];
  z[0] = 0;
  if (a == 0)
    a = z;
  if (b == 0)
    b = z;
  sprintf (buff, s, a, b);
  A4GL_set_fcompile_err(buff);
  
isFormErr=1;
  A4GL_debug ("\n");
  A4GL_exitwith("Form compilation error");
}

/**
 * Alocate memory to a struct of structs_creen_record type and start to 
 * insert as new record of the record array.
 */
static int
new_records (void)
{
  int cnt;
  A4GL_debug ("new_records\n");
  the_form.records.records_len++;
  cnt = the_form.records.records_len;

  the_form.records.records_val = realloc (the_form.records.records_val,
					  the_form.records.records_len *
					  sizeof (struct
						  struct_screen_record));
  the_form.records.records_val[cnt - 1].attribs.attribs_val =
    acl_malloc2 (sizeof (int) * 10);
  the_form.records.records_val[cnt - 1].attribs.attribs_len = 0;
  return the_form.records.records_len - 1;
}

/**
 * Add / Initialize a new screen array
 */
void
A4GLFORM_A4GL_add_srec (void)
{
  A4GL_debug ("add_srec\n");
  new_records ();
  curr_rec = &the_form.records.records_val[the_form.records.records_len - 1];
  curr_rec->dim = 0;
  curr_rec->attribs.attribs_val = acl_malloc2 (sizeof (int) * 1000);
  curr_rec->attribs.attribs_len = 0;
}

/**
 *  Assigns a new name and size to de current screen array
 *
 *  @param s The screen array name
 *  @param a The array size
 */
void
A4GLFORM_A4GL_set_dim_srec (char *s, int a)
{
  A4GL_debug ("set_dim_srec\n");
  curr_rec->dim = a;
  curr_rec->name = strdup (s);
}


/**
 *
 * @param tab The table name
 * @param a The position in the attributes array where to add
 */
static void
add_srec_direct (char *tab, int a)
{
  int z;
  A4GL_make_downshift (tab);
  A4GL_debug ("add_srec_direct\n");
  for (z = 0; z < the_form.records.records_len; z++)
    {
      if (strcasecmp (the_form.records.records_val[z].name, tab) == 0)
	{
	  curr_rec = &the_form.records.records_val[z];
	  curr_rec->attribs.attribs_val[curr_rec->attribs.attribs_len++] = a;
	  return;
	}
    }


  if (strcasecmp (tab, "formonly") == 0)
    {
      A4GLFORM_A4GL_add_srec ();
      A4GLFORM_A4GL_set_dim_srec ("formonly", 1);
      curr_rec->attribs.attribs_val[curr_rec->attribs.attribs_len++] = a;
      return;
    }
  A4GL_error_with ("Table %s has not been defined in the tables section\n", tab, 0);
}



/**
 * Makes some validations and assigns default values on a new field description
 * found at attributes section.
 * 
 * @param s Field tag name ( the one that is before '=' and in the scren
 * section )
 * @param f The field attributes filled in a struct (struct_scr_field)
 */
void
A4GLFORM_A4GL_set_field (char *s, void *f)
{
  real_set_field (s, f);
}
static void
real_set_field (char *s, struct struct_scr_field *f)
{
  int a;
  char *ptr;

  A4GL_debug ("set_field\n");

  /* is it an alias */
  ptr = chk_alias (f->tabname);

  /* if so copy the alias name across */
  if (ptr != f->tabname)
    {
      f->tabname = strdup (ptr);
    }


  for (a = 0; a < the_form.attributes.attributes_len - 1; a++)
    {
      if (strcasecmp
	  (f->tabname, the_form.attributes.attributes_val[a].tabname) == 0
	  && strcasecmp (f->colname,
			 the_form.attributes.attributes_val[a].colname) == 0
	  && f->subscripts[0] ==
	  the_form.attributes.attributes_val[a].subscripts[0]
	  && f->subscripts[0] ==
	  the_form.attributes.attributes_val[a].subscripts[1])
	{
	  A4GL_error_with ("Column %s %s has already been defined\n",
		      f->tabname, f->colname);
	}
    }

  if (f->tabname[0] == 0 || f->colname[0] == 0)
    {
      A4GL_error_with ("Column %s.%s has not been found in the database\n",
		  f->tabname, f->colname);
    }

  f->field_no = A4GLFORM_A4GL_find_field (s);
  A4GL_debug ("****************** set field number to %d\n", f->field_no);

  if (f->field_no == -1)
    {
      A4GL_error_with ("Tag %s has not been defined in the screen section\n", s,
		  0);
    }

  if (A4GL_has_str_attribute (f, FA_S_FORMAT)) {
                char *fmt;
                fmt=A4GL_get_str_attribute(f, FA_S_FORMAT);
        for(a=0;a<the_form.fields.fields_val[f->field_no].metric.metric_len;a++) {
                int w;
                int mno;
                mno=the_form.fields.fields_val[f->field_no].metric.metric_val[0];
                w=the_form.metrics.metrics_val[mno].w;
                if (strlen(fmt)!=w) {
			if (A4GL_isyes(acl_getenv("IGNOREFMTERR"))) ; // Very dangerous - can mess up form handling...
			else {
                        	A4GL_error_with ("FORMAT string is not the same size as the field\n", 0, 0);
			}
                }
  }
  }


  add_srec_direct (f->tabname, the_form.attributes.attributes_len - 1);
}


/**
 * Allocate memory space to a metric structure and insert it in the 
 * metrics array.
 *
 * @todo Define what is a metric
 *
 * @param x The column where the screen element found
 * @param y The line where the screen element was found
 * @param wid The width of the screen element in columns
 * @param scr The screen name
 * @param delim
 * @param label The label (if the element is a field) of the element
 * @return The index of metrics array
 */
static int
new_metric (int x, int y, int wid, int scr, int delim, char *label)
{
  A4GL_debug ("new_metric\n");
  the_form.metrics.metrics_len++;
  the_form.metrics.metrics_val = realloc (the_form.metrics.metrics_val,
					  the_form.metrics.metrics_len *
					  sizeof (struct struct_metrics));

  the_form.metrics.metrics_val[the_form.metrics.metrics_len - 1].dlm1 = 0;
  the_form.metrics.metrics_val[the_form.metrics.metrics_len - 1].dlm2 = 0;
  the_form.metrics.metrics_val[the_form.metrics.metrics_len - 1].field = 0;
  the_form.metrics.metrics_val[the_form.metrics.metrics_len - 1].pos_code = 0;

  the_form.metrics.metrics_val[the_form.metrics.metrics_len - 1].x = x - 1;
  the_form.metrics.metrics_val[the_form.metrics.metrics_len - 1].y = y - 1;

  the_form.metrics.metrics_val[the_form.metrics.metrics_len - 1].h = 1;

  the_form.metrics.metrics_val[the_form.metrics.metrics_len - 1].w = wid;
  the_form.metrics.metrics_val[the_form.metrics.metrics_len - 1].scr = scr;
  the_form.metrics.metrics_val[the_form.metrics.metrics_len - 1].delim_code =
    delim;
  the_form.metrics.metrics_val[the_form.metrics.metrics_len - 1].label =
    strdup (label);
  return the_form.metrics.metrics_len - 1;
}


/**
 * Alocate space to a new field (struct_form_field) and insert it in the fields
 * array
 *
 * @return The fields array index
 */
static int
add_new_field (void)
{
  A4GL_debug ("add_new_field\n");
  the_form.fields.fields_len++;
  the_form.fields.fields_val = realloc (the_form.fields.fields_val,
					the_form.fields.fields_len *
					sizeof (struct struct_form_field));
  the_form.fields.fields_val[the_form.fields.fields_len -
			     1].metric.metric_val = 0;
  the_form.fields.fields_val[the_form.fields.fields_len -
			     1].metric.metric_len = 0;
  return the_form.fields.fields_len - 1;
}

/**
 * Alocate space for a new form metric and insert it in the position
 * wanted or at the end of the array
 *
 * @todo Define what is a form metric
 * @param cnt The position of the array where to insert the form metric
 * @return The new index of form meetric array
 */
static int
new_form_metric (int cnt)
{
  A4GL_debug ("new form metric\n");
  if (cnt == -1)
    cnt = the_form.fields.fields_len - 1;

  the_form.fields.fields_val[cnt].metric.metric_len++;
  the_form.fields.fields_val[cnt].metric.metric_val =
    realloc (the_form.fields.fields_val[cnt].metric.metric_val,
	     the_form.fields.fields_val[cnt].metric.metric_len *
	     sizeof (int));
  return the_form.fields.fields_val[cnt].metric.metric_len - 1;
}


/**
 * Add(s) a new field found inside the screen section to the fields array
 * It validates if the label allready existes (there can be no duplicated
 * labels).
 *
 * Some screen text element is also added
 *
 * @param s
 * @param x Column number where the field starts
 * @param y Line number from starting from the beggining of screen scetion
 * @param wid Width of the screen form block
 * @param scr Screen sequential id
 * @param delim
 * @param label The screen label
 */
int
A4GLFORM_A4GL_add_field (char *s, int x, int y, int wid, int scr, int delim, char *label)
{
  int a;
  int f;
  int xx, yy;
  char *ptr;
  a = the_form.metrics.metrics_len - 1;
  if (a >= 0)
    {
      if (the_form.metrics.metrics_val[a].y == y - 1
	  && strcmp (s, the_form.metrics.metrics_val[a].label) == 0
	  && strcmp (s, "_label") == 0)
	{
	  if (the_form.metrics.metrics_val[a].x +
	      the_form.metrics.metrics_val[a].w == x - 1)
	    {
	      ptr = acl_malloc2 (the_form.metrics.metrics_val[a].w + wid + 1);
	      sprintf (ptr, "%s%s", the_form.metrics.metrics_val[a].label,
		       label);
	      free (the_form.metrics.metrics_val[a].label);
	      the_form.metrics.metrics_val[a].label = ptr;
	      the_form.metrics.metrics_val[a].w += wid;

	      A4GL_debug ("Straight Continuation: '%s' and '%s' = '%s'\n",
		     the_form.metrics.metrics_val[a].label, label, ptr);
	      return 0;
	    }

	  if (the_form.metrics.metrics_val[a].x +
	      the_form.metrics.metrics_val[a].w == x - 2)
	    {
	      A4GL_debug ("Alloc %d bytes",
		     the_form.metrics.metrics_val[a].w + wid + 1);
	      ptr = acl_malloc2 (the_form.metrics.metrics_val[a].w + wid + 2);
	      sprintf (ptr, "%s %s", the_form.metrics.metrics_val[a].label,
		       label);
	      A4GL_debug ("Got : %s\n", ptr);

	      free (the_form.metrics.metrics_val[a].label);
	      A4GL_debug ("Freed");
	      the_form.metrics.metrics_val[a].label = ptr;
	      the_form.metrics.metrics_val[a].w += wid + 1;

	      A4GL_debug ("Single Spaced Continuation: '%s' and '%s' = '%s'\n",
		     the_form.metrics.metrics_val[a].label, label, ptr);
	      return 0;
	    }
	}
    }

  A4GL_debug ("add_field %s %d %d %d %d %d\n", s, x, y, wid, scr, label);
  f = new_metric (x, y, wid, scr, delim, label);

  for (a = 0; a < the_form.fields.fields_len; a++)
    {
      /* does field tag already exist */
      if (strcasecmp (the_form.fields.fields_val[a].tag, s) == 0)
	{
	  xx = new_form_metric (a);

	  the_form.fields.fields_val[a].metric.metric_val[xx] = f;
	  A4GL_debug ("b\n");
	  return 1;
	}
    }

  yy = add_new_field ();
  xx = new_form_metric (-1);

  the_form.fields.fields_val[yy].tag = strdup (s);
  the_form.fields.fields_val[yy].metric.metric_val[xx] = f;
  return yy;
}


/**
 * Adds a new table to the form tables array
 *
 * @param s table name
 * @param a table alias
 */
void
A4GLFORM_A4GL_add_table (char *s, char *a)
{
  char z[3];
  z[0] = 0;

  A4GL_debug ("add_table %s %s\n", s, a);
  if (s == 0 || strlen (s) == 0)
    {
      s = a;
      a = z;
    }

  the_form.tables.tables_val = realloc (the_form.tables.tables_val,
					(the_form.tables.tables_len +
					 1) * sizeof (struct struct_tables));

  the_form.tables.tables_val[the_form.tables.tables_len].tabname = strdup (s);
  the_form.tables.tables_val[the_form.tables.tables_len].alias = strdup (a);
  A4GLFORM_A4GL_add_srec ();
  A4GLFORM_A4GL_set_dim_srec (s, 1);
  the_form.tables.tables_len++;
}

/**
 * Find the attribute for table and column name
 *
 * @param ptr An array pointer where the field will be putted
 * @param tab The table name
 * @param colname The column name
 * @return The index of the attribute in the array
 */
static int
find_attribs (int **ptr, char *tab, char *colname)
{
  static int attrib_list[256];
  int a;
  int cnt = 0;

  A4GL_debug ("find_attribs\n");
  *ptr = (int *) &attrib_list;

  for (a = 0; a < the_form.attributes.attributes_len; a++)
    {
      if (strcasecmp (tab, the_form.attributes.attributes_val[a].tabname) == 0
	  && strcasecmp (colname,
			 the_form.attributes.attributes_val[a].colname) == 0)
	{
	  attrib_list[cnt++] = a;
	}

      if (strcasecmp (tab, "") == 0 &&
	  strcasecmp (colname,
		      the_form.attributes.attributes_val[a].colname) == 0)
	{
	  attrib_list[cnt++] = a;
	}

      if (strcasecmp (tab, the_form.attributes.attributes_val[a].tabname) == 0
	  && strcasecmp (colname, "*") == 0)
	{
	  attrib_list[cnt++] = a;
	}

    }
  return cnt;
}

/**
 * Process the through of fields in the screen record
 * Expands the field attributes of a through in the screen record
 */
static void
proc_thru (void)
{
  int a;
  int b;
  int z;

  A4GL_debug ("proc_thru\n");
  a = curr_rec->attribs.attribs_val[curr_rec->attribs.attribs_len - 2];
  b = curr_rec->attribs.attribs_val[curr_rec->attribs.attribs_len - 1];
  curr_rec->attribs.attribs_len -= 2;

  for (z = a; z <= b; z++)
    {
      curr_rec->attribs.attribs_val[curr_rec->attribs.attribs_len++] = z;
    }
}

/**
 * Adds a new attribute / field, field pattern to the current screen record
 *
 * @param tab The table name or FORMONLY
 * @param col The column name or '*'
 * @param thru 
 */
void
A4GLFORM_A4GL_add_srec_attribute (char *tab, char *col, char *thru)
{
  int *ptr;
  int a;
  int z;

  A4GL_debug ("add_srec_attribute %s %s %s\n", tab, col, thru);
  if (strlen (thru) > 0)
    {
      proc_thru ();
      return;
    }


  a = find_attribs (&ptr, tab, col);

  if (a == 0)
    {
      A4GL_error_with ("No fields matching %s.%s were found\n", tab, col);
    }

  A4GL_debug ("Find_attribs returns %d\n", a);

  for (z = 0; z < a; z++)
    {
      A4GL_debug ("Adding attribute %p",
	     curr_rec->attribs.attribs_val[curr_rec->attribs.attribs_len]);

      A4GL_debug ("ptr[z]=%d\n", ptr[z]);

      /*
         curr_rec->attribs.attribs_val=realloc(
         curr_rec->attribs.attribs_val,
         curr_rec->attribs.attribs_len*sizeof(int));
       */


      curr_rec->attribs.attribs_val[curr_rec->attribs.attribs_len++] = ptr[z];
      if (curr_rec->dim == 1) {
	//curr_rec->dim =
	  //the_form.fields.fields_val[the_form.attributes.
				     //attributes_val[ptr[z]].field_no].metric.
	  //metric_len;

		// @todo - check whether this is actually needed....
	}



      if (the_form.fields.
	  fields_val[the_form.attributes.attributes_val[ptr[z]].field_no].
	  metric.metric_len != curr_rec->dim)
	{
	  A4GL_debug ("cnt=%d dim=%d",
		 the_form.fields.fields_val[the_form.attributes.
					    attributes_val[ptr[z]].field_no].
		 metric.metric_len, curr_rec->dim);
        if (!A4GLFORM_A4GL_has_bool_attribute( &the_form.attributes.attributes_val[ptr[z]] , FA_B_WORDWRAP)){
	  if (curr_rec->dim==1) {
		printf("Warning : Mismatch in screen record\n");
		curr_rec->dim=the_form.fields.fields_val[the_form.attributes.attributes_val[ptr[z]].field_no].metric.metric_len;
	  } else {
	  	A4GL_error_with ("Mismatch in screen record", 0, 0);
	  }
	}
	  return;
	}
    }
}

/**
 * Find the field in the attriutes array by field number
 *  
 * @param fno The field number wanted
 * @return The index of the array of field number wanted
 */

static int
find_field_attr(int fno)
{
  int a;
 A4GL_debug("find_field_attr\n");
  for (a=0;a<the_form.attributes.attributes_len;a++)
  {
    if (the_form.attributes.attributes_val[a].field_no==fno)
    {
      return a;
      A4GL_debug("Field %d found at %d",fno,a);
    }
  }
  A4GL_debug("Not found (%d)",fno);
  return -1;
}


/**
 * Find the fields that are wordwrap for big strings input.
 *
 * It seems not used
 * @todo Understand if its or not used and if so remove it
 */

static void
chk_for_wordwrap(void)
{
  int a,b;
  int w,w1;
  int x,x1;
  int y,y1;
  int fno;
  A4GL_debug("chk_for_wordwrap\n");
  for (a = 0; a < the_form.fields.fields_len; a++) 
  {
    fno=a; 
    fno=find_field_attr(a);
    if (fno==-1) continue;

    A4GL_debug("%s=%s.%s",
    the_form.fields.fields_val[a].tag,
    the_form.attributes.attributes_val[fno].tabname,
    the_form.attributes.attributes_val[fno].colname);

    if (!A4GLFORM_A4GL_has_bool_attribute( &the_form.attributes.attributes_val[fno] ,
        FA_B_WORDWRAP)) 
      continue;

    b=0;
    w=the_form.metrics.metrics_val[
      the_form.fields.fields_val[a].metric.metric_val[b]].w;
    x=the_form.metrics.metrics_val[
      the_form.fields.fields_val[a].metric.metric_val[b]].x;
    y=the_form.metrics.metrics_val[
      the_form.fields.fields_val[a].metric.metric_val[b]].y;
 
    for (b=1;b<the_form.fields.fields_val[a].metric.metric_len;b++) 
    {
        w1=the_form.metrics.metrics_val[
	  the_form.fields.fields_val[a].metric.metric_val[b]].w;
        x1=the_form.metrics.metrics_val[
	  the_form.fields.fields_val[a].metric.metric_val[b]].x;
        y1=the_form.metrics.metrics_val[
	  the_form.fields.fields_val[a].metric.metric_val[b]].y;
 

      if (w1!=w||x1!=x||y1-b!=y) 
      {
        A4GL_debug("w1=%d w=%d x1=%d x=%d y1+b=%d y=%d", w1,w,x1,x,y1+b,y);
        A4GL_error_with(
	  "Wordwrapped fields must be the same width, start at the same place and be on consecutive lines",0,0
	);
      }
    }

    // Now get rid of the extra metrics and make this a multiline field
    the_form.metrics.metrics_val[the_form.fields.fields_val[a].metric.metric_val[0]].h=the_form.fields.fields_val[a].metric.metric_len;
    the_form.fields.fields_val[a].metric.metric_len=1;

  }
}


void A4GLFORM_A4GL_delete_compiled_form_file(void) {
/* ... */
}


/**
 * Write the frm file with the information parsed from the .per to memory
 */
void
A4GLFORM_A4GL_write_form (void)
{
  char fname[132];
  char fname2[132];
  char base[132];
  char ext[132];
  int a;
  XDR xdrp;
  struct_form *ptr;

  ptr = &the_form;

  strcpy (fname, outputfilename);

  A4GL_bname (outputfilename, ext, base);

  /* if (ext[0] == 0) { */
      strcat (fname, acl_getenv ("A4GL_FRM_BASE_EXT"));
    /* } */

  strcpy (fname2, outputfilename);
  strcat (fname2, ".c");

  fxx = fopen (fname, "wb");

  if (fxx == 0)
    {
      A4GL_error_with ("Couldnt open file for write (%s)\n", fname, 0);
      exit (1);
    }
  chk_for_wordwrap();
  translate_form ();
  xdrstdio_create (&xdrp, fxx, XDR_ENCODE);
  a = xdr_struct_form (&xdrp, ptr);

  if (!a)
    {
      A4GL_debug ("*** Write FAILED ***\n");
      A4GL_error_with ("Unable to write data\n", 0, 0);
    }

  xdr_destroy (&xdrp);
  fclose (fxx);

  if (A4GL_get_as_c())
    {
      int cnt = 0;
      int a;
      int len;
      A4GL_debug ("Asc...\n");
      fxx = fopen (fname, "r");
      fseek (fxx, 0, SEEK_END);
      len = ftell (fxx);
      rewind (fxx);


      fyy = fopen (fname2, "w");
      fprintf (fyy, "char compiled_form_%s[]={\n", outputfilename);
      fprintf (fyy, "0x%02x,\n", len & 255);
      len /= 256;
      fprintf (fyy, "0x%02x,\n", len & 255);
      len /= 256;
      fprintf (fyy, "0x%02x,\n", len & 255);
      len /= 256;
      fprintf (fyy, "0x%02x,\n", len & 255);
      len /= 256;


      while (!feof (fxx))
	{
	  a = fgetc (fxx);
	  if (feof (fxx))
	    break;
	  if (cnt > 0)
	    fprintf (fyy, ",");
	  if (cnt % 16 == 0 && cnt)
	    {
	      fprintf (fyy, "\n");
	    }
	  if (a == -1)
	    {
	      break;
	    }
	  fprintf (fyy, "0x%02x", a);
	  cnt++;
	}
      fprintf (fyy, "};\n");
      fclose (fxx);
      fclose (fyy);
      /* unlink(fname); */
    }
}


/**
 * Gets the datatype of the column from the database
 * called from y.tab.c
 * @col The column name
 * @tab The table name
 */
int
A4GLFORM_A4GL_getdatatype (char *col, char *tab)
{
  char *tabs[256];
  char buff[256];
  int a;
  int c;
  A4GL_debug ("getdatatype\n");
  c=0;
  for (a = 0; a < the_form.tables.tables_len; a++)
    {
         if (strcasecmp(the_form.tables.tables_val[a].alias,tab)==0&&strlen(the_form.tables.tables_val[a].alias)) {
                tab=the_form.tables.tables_val[a].tabname;
                tabs[c++] = strdup (the_form.tables.tables_val[a].alias);
        }
      else {
                tabs[c++] = strdup (the_form.tables.tables_val[a].tabname);
        }
    }


  tabs[c] = 0;

  A4GL_debug ("Calling A4GL_get_dtype with %s %s %s", the_form.dbname, tab, col);
  /* int        A4GL_get_dtype                       (char *tabname, char *colname,char *dbname,char *tablist[]); */
  //a=get_dtype(tab,col,the_form.dbname,the_form.tables.tables_val);

  a = A4GL_get_dtype (tab, col, the_form.dbname, tabs);


  /*
     warning: passing arg 4 of `get_dtype' from incompatible pointer type
     so we are passing a char ponter to function expecting char array !!
   */
  A4GL_debug ("get_dtype returns %d", a);
  /* 6-2 ? CHECK */
  //if (a == 6) a = 2;

  if (a == -1)
    {
      A4GL_debug ("get_dtype failed\n");
      sprintf (buff, "%s.%s not found in database\n", tab, col);
      //yyerror(buff);
    }
  return a;
}


/**
 * Intialize the memory needed to compile a 4gl screen form in order to
 * the lexical and sintatic parser to load the information found
 */
void
A4GLFORM_A4GL_init_form (void)
{
  A4GL_debug ("init_form\n");
  the_form.dbname = strdup ("");
  the_form.delim = strdup ("[]|");
  the_form.maxcol = 0;

  the_form.magic = FCOMILE_XDR_MAGIC;	/* Just any number */

  the_form.magic1 = strdup ("A4GL_FORMSTART");
  the_form.fcompile_version = FCOMILE_XDR_VERSION;
  the_form.compiled_time = time (0);

  the_form.magic2 = strdup ("FORMEND");
  the_form.maxline = 0;

  the_form.snames.snames_len = 0;
  the_form.snames.snames_val = 0;

  the_form.attributes.attributes_len = 0;
  the_form.attributes.attributes_val = 0;

  the_form.metrics.metrics_len = 0;
  the_form.metrics.metrics_val = 0;

  the_form.fields.fields_len = 0;
  the_form.fields.fields_val = 0;

  the_form.records.records_len = 0;
  the_form.records.records_val = 0;
  
  the_form.control_blocks.control_blocks_len=0;
  the_form.control_blocks.control_blocks_val=0;

  the_form.master_of.master_of_len=0;
  the_form.master_of.master_of_val=0;

  the_form.composites.composites_len=0;
  the_form.composites.composites_val=0;

}


/**
 * If necessary locate memory to field attributes and insert it to the 
 * attribute array of the screen field pointer.
 *
 * Adds only one of the screen attributes.
 *
 * @param f A screen field structure pointer
 * @param type The attribute type
 * @param str The attribute to add
 */
void
A4GLFORM_A4GL_add_str_attr (void *f, int type, char *str)
{
  real_add_str_attr (f, type, str);
}
static void
real_add_str_attr (struct struct_scr_field *f, int type, char *str)
{
  A4GL_debug ("add_str_attr %d - '%s'\n", type, str);

  if (str[0] != '\n') {
	                  if(str[0]=='\"' || str[0]=='\''){
				                          str = A4GL_char_val (str);
							                  }
			    } else {
				        str++;
					  }



  if (!A4GL_has_str_attribute (f, type))
    {
      f->str_attribs.str_attribs_len++;
      f->str_attribs.str_attribs_val =
	realloc (f->str_attribs.str_attribs_val,
		 f->str_attribs.str_attribs_len *
		 sizeof (struct struct_field_attr_string));
      f->str_attribs.str_attribs_val[f->str_attribs.str_attribs_len -
				     1].type = type;
      f->str_attribs.str_attribs_val[f->str_attribs.str_attribs_len -
				     1].value = strdup (str);
    }
  else
    {
      A4GL_error_with ("Attribute already used  new value '%s'\n", str, 0);
    }
}

/**
 * Try to find the attribute and if not alocate memory and insert it in
 * the attributes array.
 *
 * @param f Pointer to field description
 * @param type The type of the boolean attribute:
 *   
 */
void
A4GLFORM_A4GL_add_bool_attr (void *f, int type)
{
  real_add_bool_attr (f, type);
}
static void
real_add_bool_attr (struct struct_scr_field *f, int type)
{
  char *attrs[] = {
    "AUTONEXT",
    "REVERSE",
    "INVISIBLE",
    "NOENTRY",
    "VERIFY",
    "WORDWRAP",
    "COMPRESS",
    "UPSHIFT",
    "DOWNSHIFT","REQUIRED","NOUPDATE","QUERYCLEAR","ZEROFILL","RIGHT",
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
        "NOTNULL"

  };

  A4GL_debug ("add_bool_attr\n");

  if (!A4GLFORM_A4GL_has_bool_attribute (f, type))	/* see a4gl_aubit_lib.h for declaration */
    {
      if (f->bool_attribs.bool_attribs_len == 0)
	f->bool_attribs.bool_attribs_val = 0;

      A4GL_debug ("n1 %d %p\n",
	     f->bool_attribs.bool_attribs_len,
	     f->bool_attribs.bool_attribs_val);

      f->bool_attribs.bool_attribs_len++;
      f->bool_attribs.bool_attribs_val =
	realloc (f->bool_attribs.bool_attribs_val,
		 f->bool_attribs.bool_attribs_len *
		 sizeof (enum FIELD_ATTRIBUTES_BOOL));
      f->bool_attribs.bool_attribs_val[f->bool_attribs.bool_attribs_len - 1] =
	type;
    }
  else
    {
      printf ("Warning : Attribute already used for %s.%s (%s)\n",
	      f->tabname, f->colname, attrs[type]);
    }
}


/**
 *
 */
static void
translate_form (void)
{
  int a;
  int b;
  char *ptr;

  for (a = 0; a < the_form.metrics.metrics_len; a++)
    {
      A4GL_dumpstring (the_form.metrics.metrics_val[a].label, 0, "");
      ptr = A4GL_translate (the_form.metrics.metrics_val[a].label);
      if (ptr)
	the_form.metrics.metrics_val[a].label = strdup (ptr);
    }

  for (b = 0; b < the_form.attributes.attributes_len; b++)
    {
      for (a = 0;
	   a <
	   the_form.attributes.attributes_val[b].str_attribs.str_attribs_len;
	   a++)
	{
	  if (the_form.attributes.attributes_val[b].str_attribs.
	      str_attribs_val[a].type == FA_S_COMMENTS)
	    {
	      A4GL_dumpstring (the_form.attributes.attributes_val[b].str_attribs.
			  str_attribs_val[a].value, 0, "");
	      ptr =
	 A4GL_translate (the_form.attributes.attributes_val[b].str_attribs.
			   str_attribs_val[a].value);
	      if (ptr)
		the_form.attributes.attributes_val[b].str_attribs.
		  str_attribs_val[a].value = strdup (ptr);
	    }
	}
    }
}



/* ============== from decompile.c ===================== */
/*   did not work, but still needed for fdecompile */
int
A4GL_isolated_xdr_struct_form (void *xdrp, void *the_form)
{
  return real_isolated_xdr_struct_form (xdrp, the_form);
}
static int
real_isolated_xdr_struct_form (XDR * xdrp, struct struct_form *the_form)
{
  int a;
  A4GL_debug ("In isolated xdr_struct_form..");
  a = xdr_struct_form (xdrp, the_form);
  A4GL_debug ("DOne");
  return a;
}

int A4GLFORM_FORM_initlib() {
	return 1;
}

/* =============================== EOF ========================== */

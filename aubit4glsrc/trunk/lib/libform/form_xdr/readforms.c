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
# $Id: readforms.c,v 1.19 2002-09-08 09:41:06 afalout Exp $
#*/

/**
 * @file
 * Read form from file and (or) memory.
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


#include "a4gl_lib_form_xdr_int.h"

/* FIXME: duplicated from a4gl_libaubit4gl.h : */
	int 	find_srec 			(struct_form * fd, char *name);
	/* struct struct_scr_field defined in fcompile/form_x.h */
	int 	has_str_attribute 	(struct struct_scr_field * f, int str);
	int 	attr_name_match 	(struct struct_scr_field *field, char *s);
	char *	get_str_attribute 	(struct struct_scr_field *f, int str);

/*
=====================================================================
                    Constants definitions
=====================================================================
*/


#define POS_FIRST 1
#define POS_VERY_FIRST 2
#define POS_VERY_LAST 4
#define POS_LAST 8
#define INC_EACH "\n"
#define INC_RANGE '\t'

/* SYSTEM Defines - dont change! */

#define DEFAULT -1
#define YES 1
#define YES_COMPRESS 2
#define CASEON 1
#define CASEOFF 0
#define OPTIONS long


/*
=====================================================================
                    Variables definitions
=====================================================================
*/

#ifdef __CYGWIN__
	extern int status;
#endif

/*xdr_struct_form is not part of RPC_[NO]RPC
extern bool_t
xdr_struct_form(xdrs, objp)
	XDR *xdrs;
	struct_form *objp;
*/

int tab_cnt = 0;
int srec_cnt = 0;
extern int errno;
char delimiters[4];

int lastc = 0;
int nline;
int fline;
int ncol;
char dbname[64];


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

/** @todo Take this prototype definition for a header file */
static void do_translate_form(struct_form *the_form);
static void read_attributes (struct s_form_dets *f);
static int include_range_check (char *ss, char *ptr, int dtype);
static int real_has_bool_attribute (struct struct_scr_field *f, int bool);

char *read_string_dup (FILE * ofile);
char *string_width (char *a);
int set_fields2 (int nv, struct BINDING *vars, int d, int n, ...);

static void real_comments (struct struct_scr_field * fprop);
static struct s_form_dets * real_read_form (char *fname, char *formname);
static void real_set_default_form (struct s_form_attr *form);
static void real_dump_srec (struct s_form_dets * fd);



/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/* not used in libFORM_ so moved into libaubit4gl in screen.c
char *
find_attribute (struct s_form_dets *f, int field_no)
{
  int a;

  for (a = 0; a < f->fileform->attributes.attributes_len; a++)
    {

      if (f->fileform->attributes.attributes_val[a].field_no == field_no)
	{
	  debug ("FIeld no %d is reference by attribute %d\n", field_no, a);
	  return (char *) &f->fileform->attributes.attributes_val[a];
	}
    }
  debug ("Couldnt find entry for field no %d\n", field_no);
  return 0;
}
*/

/**
 * Not called from anywhere
 */
/*
static char *
ret_string (char *str)
{
  static char retword[] = "Not Set";
  if (str != 0)
    return str;
  else
    return retword;
}
*/


/**
 *
 */
void *
read_form (char* fname, char* formname)
{
	debug("via read_form in lib");
	return real_read_form(fname, formname);
}

static struct s_form_dets *
real_read_form (char *fname, char *formname)
{
FILE *ofile = 0;
int a;
struct s_form_dets *formdets;
char buff[80];
char *ptr = 0;
XDR xdrp;
trim (fname);
trim (formname);

	debug ("in read_form fname=%s formname=%s", fname, formname);
	strcpy (buff, fname);
	buff[strlen (buff) - 4] = 0;

	if (has_pointer (buff, COMPILED_FORM))
    {
	  int chkint;		/* INT4 */
		ptr = find_pointer (buff, COMPILED_FORM);

		xdrmem_create (&xdrp, ptr, 128 * 1024, XDR_DECODE);
		xdr_int (&xdrp, &chkint);

		if (chkint != FCOMILE_XDR_MAGIC)
		{
			exitwith
			("Couldnt open form - does not appear to be a valid form file");
			return 0;
		}
    }
	else
    {
      int chkint;		/*  INT4 */
		debug ("Opening file");
		ofile = (FILE *) open_file_dbpath (fname);

		if (ofile == 0)
		{
			exitwith ("Couldnt open form");
			return 0;
        }

		debug ("Checking magic header");

		xdrstdio_create (&xdrp, ofile, XDR_DECODE);
		xdr_int (&xdrp, &chkint);

		if (chkint != FCOMILE_XDR_MAGIC)
        {
			exitwith
			("Couldnt open form - does not appear to be a valid form file");
			return 0;
        }

		rewind (ofile);
    }


	#ifdef DEBUG
		{debug ("fname=%s formname=%s", fname, formname); }
	#endif

	gui_startform (formname);
	formdets =
    (struct s_form_dets *) acl_malloc (sizeof (struct s_form_dets),
				       "Readform");
	formdets->fileform =
    	(struct_form *) acl_malloc (sizeof (struct_form), "Readform");

	memset (formdets->fileform, 0, sizeof (struct_form));


	if (ptr == 0)
    {
      debug ("Reading form from file");
      xdrstdio_create (&xdrp, ofile, XDR_DECODE);
    }
	else
    {
      debug ("Reading form from memory");
      xdrmem_create (&xdrp, find_pointer (buff, COMPILED_FORM), 128 * 1024,
		     XDR_DECODE);
    }

	a = xdr_struct_form (&xdrp, formdets->fileform);

	if (!a)
    {
      exitwith ("Unable to read form");
      return 0;
    }

	if (formdets->fileform->fcompile_version != FCOMILE_XDR_VERSION)
    {
      debug ("Form version %d - my version %d",
	     formdets->fileform->fcompile_version, FCOMILE_XDR_VERSION);
      exitwith ("This form has a version number that I can't handle");
      return 0;
    }


	do_translate_form(formdets->fileform);

	formdets->currentfield = 0;
	debug("formdets=%p",formdets);
	read_attributes (formdets);
	debug("formdets=%p",formdets);
	read_metrics (formdets);
	debug("formdets=%p",formdets);
	read_fields (formdets);
	debug("formdets=%p",formdets);
	debug ("Loaded form...");
	gui_endform ();
	debug ("Ended loading forms (%d, %d)", formdets->fileform->maxcol,
										formdets->fileform->maxline);
	return formdets;
}



/**
 * Called from lib/libtui/newpanels.c so it should be in API_form
 */
void
set_default_form (void* form)
{
	real_set_default_form (form);
}

static void
real_set_default_form (struct s_form_attr *form)
{
  form->mode = -1;
  form->insmode = 0;
  form->colour = 0;
  form->comment_line = 1;
  form->form_line = 3;
  form->menu_line = 2;
  form->message_line = 3;
  form->prompt_line = 4;
}

/**
 *
 */
static void
read_attributes (struct s_form_dets *f)
{
  int a;
  debug ("read_attributes %d", f->fileform->attributes.attributes_len);
  for (a = 0; a < f->fileform->attributes.attributes_len; a++)
    {
      debug ("a=%d colour=%d", a,
	     f->fileform->attributes.attributes_val[a].colour);
      if (f->fileform->attributes.attributes_val[a].colour == -1)
	f->fileform->attributes.attributes_val[a].colour = 7;
      if (real_has_bool_attribute /* see a4gl_aubit_lib.h for declaration */
	  (&f->fileform->attributes.attributes_val[a], FA_B_REVERSE))
	f->fileform->attributes.attributes_val[a].do_reverse = 1;
      else
	f->fileform->attributes.attributes_val[a].do_reverse = 0;
      debug ("moving onto next\n");
    }
  debug ("returning\n");
}


/**
 * Called from lib/libtui/ioform.c
 */
void
comments(void* fprop)
{
	debug("via comments in lib");
	real_comments(fprop);
}
static void
real_comments (struct struct_scr_field * fprop)
{
  if (fprop)
    {
      debug ("Has property");
      if (has_str_attribute (fprop, FA_S_COMMENTS))
	{
	  debug ("Adding comment %s",
		 strip_quotes (get_str_attribute (fprop, FA_S_COMMENTS)));
	}
    }
}

/**
 *
 * looks like this is not used because it has return at the top?
 * but there is a call to it from libUI_TUI that needs to be removed
 * if the is the case - and from API_form.spec too
 *
 */
void
dump_srec (void * fd)
{
	real_dump_srec(fd);
}
static void
real_dump_srec (struct s_form_dets * fd)
{
  int a;
  int b;

  return;

  debug ("fd=%p srecs_cnt=%ld", fd, fd->fileform->records.records_len);
  for (a = 0; a < fd->fileform->records.records_len; a++)
	{
		debug ("Screen record : %s [%d] (%d)\n",
		fd->fileform->records.records_val[a].name,
	    fd->fileform->records.records_val[a].dim,
	    fd->fileform->records.records_val[a].attribs.attribs_len);
      for (b = 0;
	   b < fd->fileform->records.records_val[a].attribs.attribs_len; b++)
		{
		  debug ("                    %d\n",
		 fd->fileform->records.records_val[a].attribs.attribs_val[b]);
		}
    }
}


/** This should be moved to lib tui
 *
 *
 */
struct struct_screen_record *
get_srec (char *name)
{
  int a;
  struct s_form_dets *form;
  debug ("Get_srec");
  form = get_curr_form ();
  debug ("found form");

  debug ("Got form %p", form);

  if (form == 0)
    {
      debug ("No form...");
      return (struct struct_screen_record *) 0;
    }

  debug("fileform=%p name=%p(%s)",form->fileform,name,name);

  a = find_srec (form->fileform, name);
  debug ("Got %d", a);
  if (a == -1)
    return (struct struct_screen_record *) 0;
  else
    return (struct struct_screen_record *) &form->fileform->records.
      records_val[a];
}

/**
 * called from lib/libtui/ioform.c so it should be in API_form
 */
int
check_field_for_include (char *s, char *inc, int dtype)
{
  static char buff[1024];
  char *ptr;
  debug ("check_field_for_include (%s,'%s',%d)", s, inc, dtype);
/* no include specified - must be OK */

  if (inc == 0)
    return TRUE;
  if (strlen (inc) == 0)
    return TRUE;

  debug ("Checking include");
  dtype = dtype & DTYPE_MASK;
  strcpy (buff, inc);
  ptr = strtok (buff, INC_EACH);

  while (ptr)
    {
      debug ("Checking token '%s'", ptr);
      if (include_range_check (s, ptr, dtype))
	return TRUE;
      ptr = strtok (0, INC_EACH);
    }
  return FALSE;
}

/**
 *
 */
static int
include_range_check (char *ss, char *ptr, int dtype)
{
  static char buff[2048];	/* what we're checking */
  static char buff2[2048];	/* what we're checking against */
  static char buff3[2048];	/* used if its a range */
  char *ptr1;
  char *ptr2;
  char *ptr3;
  char *s;

  s = strdup (ss);
  trim (s);
  debug ("include_range_check(%s,%s,%d)", s, ptr, dtype);

  ptr3 = strchr (ptr, INC_RANGE);

  if (ptr3)
    {
      ptr3[0] = 0;
      ptr3++;
      debug ("a range has been specified '%s' to '%s'", ptr, ptr3);
    }

  if (dtype != 0)
    {
      debug ("Not a string expression");
      push_char (s);
      pop_param (&buff, dtype, 0);

      push_char (ptr);
      pop_param (&buff2, dtype, 0);

      /* do we have a range of values to check ? */
      if (ptr3)
	{
	  push_char (ptr3);
	  pop_param (&buff3, dtype, 0);
	}
      ptr1 = buff;
      ptr2 = buff2;
      ptr3 = buff3;

    }
  else
    {
      debug ("String expression");
      ptr1 = s;
      ptr2 = ptr;
    }


  if (ptr3 == 0)
    {
      /* Not a range */
      push_param (ptr1, dtype);
      push_param (ptr2, dtype);
      debug_print_stack ();
      pushop (OP_EQUAL);
      debug ("Checking for equal");
      free (s);
      return pop_bool ();

    }
  else
    {
      debug ("if ints : %d comp %d", *(int *) ptr1, *(int *) ptr2);
      push_param (ptr1, dtype);
      push_param (ptr2, dtype);
      debug_print_stack ();
      pushop (OP_GREATER_THAN_EQ);
      debug ("Checking for <=");
      if (pop_bool () == 0)
	{
	  free (s);
	  return FALSE;
	}

      debug ("if ints : %d comp %d", *(int *) ptr1, *(int *) ptr3);
      push_param (ptr1, dtype);
      push_param (ptr3, dtype);
      debug_print_stack ();
      pushop (OP_LESS_THAN_EQ);
      debug ("Checking for >=");
      free (s);
      if (pop_bool () == 0)
	return FALSE;
      return TRUE;
    }

}



/* moved to others.c, because it is also used by 4glc

char *
strip_quotes (char *s)
{
  static char buff[1024];
  if (s[0] == '"' || s[0] == '\'')
    {
      strcpy (buff, &s[1]);
      buff[strlen (buff) - 1] = 0;
    }
  else
    {
      strcpy (buff, s);
    }
  debug ("Returning %s", buff);
  return buff;
}


*/

/**
 *
 */
int
has_bool_attribute (void* f, int bool)
{
	debug("via has_bool_attribute in lib");
	real_has_bool_attribute(f,bool);
}
static int
real_has_bool_attribute (struct struct_scr_field *f, int bool)
{
  int a;
  debug ("Checking %p for %d\n", f, bool);
  for (a = 0; a < f->bool_attribs.bool_attribs_len; a++)
    {
      debug ("%d %d %d\n", bool, a, f->bool_attribs.bool_attribs_len);
      if (f->bool_attribs.bool_attribs_val[a] == bool)
	return 1;
    }
  debug ("Nope");
  return 0;
}

/**
 * Not called anywhere
 */
/*
static int
set_bool_attribute (struct struct_scr_field * f, int bool, int value)
{
  int a;

  for (a = 0; a < f->bool_attribs.bool_attribs_len; a++)
    {
      if (f->bool_attribs.bool_attribs_val[a] == bool)
	return 1;
    }

  return 0;
}
*/

/**
 *
 */
static void
do_translate_form(struct_form *the_form)
{
int a;
int b;
char *ptr;

	for (a=0;a<the_form->metrics.metrics_len;a++)
    {
    	if (strncmp(the_form->metrics.metrics_val[a].label,"get_translated_id:",18)==0)
		{
			ptr=&the_form->metrics.metrics_val[a].label[18];
			ptr=(char *)get_translated_id(ptr);
			the_form->metrics.metrics_val[a].label=ptr;
		}
	}

    for (b=0;b< the_form->attributes.attributes_len;b++)
	{
    	for (a=0;a<the_form->attributes.attributes_val[b].str_attribs.str_attribs_len;a++)
		{
        	if (the_form->attributes.attributes_val[b].str_attribs.str_attribs_val[a].type==FA_S_COMMENTS)
			{
    	    	if (strncmp(the_form->attributes.attributes_val[b].str_attribs.str_attribs_val[a].value, "get_translated_id:",18)==0)
				{
            	    ptr=&the_form->attributes.attributes_val[b].str_attribs.str_attribs_val[a].value[18];
					ptr=(char *)get_translated_id(ptr);
	       	        if (ptr)
		                the_form->attributes.attributes_val[b].str_attribs.str_attribs_val[a].value=ptr;
				}
			}
		}
	}
}


/**
 *  not called anywhere
 */
/*
static int
chk_iskey (char *keys)
{
  char *k;
  char s[256];
  strcpy (s, keys);
  strcat (s, "|");
  debug ("Chk keys %s\n", s);

  if (strcmp (keys, "->ANY") == 0)
    return 1;

  k = strtok (s, "|");
  while (1)
    {
      debug ("Chk keys (%s - %d %d )\n", k, key_val (k), get_lastkey ());
      if (key_val (k) == get_lastkey ())
        {
          return 1;
        }
      k = strtok (0, "|");
      if (k == 0)
        return 0;
    }
  return 0;
}
*/

/* moved to lib/libaubit4gl/others.c because it is used by other modules too, not just forms

char *replace_sql_var (char *s);
int attr_name_match (struct struct_scr_field *field, char *s);
char *get_str_attribute (struct struct_scr_field *f, int str);


char *
replace_sql_var (char *s)
{
  static char buff[1024];
  char *ptr;
  if (s[0] != '\n')
    {
      return s;
    }
  strcpy (buff, &s[1]);

  if (strcmp (buff, "today") == 0)
    {
      push_today ();
      ptr = char_pop ();
      strcpy (buff, ptr);
      acl_free (ptr);
    }
  if (strcmp (buff, "user") == 0)
    {
      push_user ();
      ptr = char_pop ();
      strcpy (buff, ptr);
      acl_free (ptr);
    }
  debug ("replace_sql_var :Returning %s", buff);
  return buff;

}




attr_name_match (struct struct_scr_field * field, char *s)
{
  char colname[40];
  char tabname[40];
  char buff[80];
  int aa;
  int ab;
  //debug ("Field : %p\n", field);
  //debug ("attr_name_match : %s", s);
  bname (s, tabname, colname);

  //debug ("Splits to %s & %s", tabname, colname);
  //debug ("field is [%s %s]", field->tabname, field->colname);

  aa = strcmp (field->tabname, tabname);
  ab = strcmp (field->colname, colname);
  //debug ("Matches = %d %d ", aa, ab);
  if ((ab == 0) || (colname[0] == '*'))
    {
      debug ("Match on *");
      return 1;
    }
  if (ab == 0 && tabname[0] == 0)
    {
      debug ("Matched");
      return 1;
    }
  //debug ("Not matched (%s!=%s or %s!=%s)", field->tabname, tabname,
	 //field->colname, colname);
  return 0;
}



char *
get_str_attribute (struct struct_scr_field *f, int str)
{
  int a;

  if (!has_str_attribute (f, str))
    {
      return 0;
    }

  for (a = 0; a < f->str_attribs.str_attribs_len; a++)
    {
      if (f->str_attribs.str_attribs_val[a].type == str)
	return f->str_attribs.str_attribs_val[a].value;
    }
  return 0;
}



find_srec (struct_form * fd, char *name)
{
  int a;
  int b;

debug("No of records : %d",fd->records.records_len);

  for (a = 0; a < fd->records.records_len; a++)
    {
      if (strcasecmp (name, fd->records.records_val[a].name) == 0)
	return a;
    }
  return -1;
}



has_str_attribute (struct struct_scr_field * f, int str)
{
  int a;
  for (a = 0; a < f->str_attribs.str_attribs_len; a++)
    {
      if (f->str_attribs.str_attribs_val[a].type == str)
	return 1;
    }
  return 0;
}


*/


/* ============================ EOF ============================== */


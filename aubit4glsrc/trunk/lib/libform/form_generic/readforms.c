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
# $Id: readforms.c,v 1.20 2004-05-26 14:14:46 mikeaubury Exp $
#*/

/**
 * @file
 * Read form from file and (or) memory.
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

#include "a4gl_lib_form_generic_int.h"

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
static void do_translate_form (struct_form * the_form);
static void read_attributes (struct s_form_dets *f);
static int include_range_check (char *ss, char *ptr, int dtype);
static int real_has_bool_attribute (struct struct_scr_field *f, int boolval);

char *read_string_dup (FILE * ofile);
char *A4GL_string_width (char *a);
int set_fields2 (int nv, struct BINDING *vars, int d, int n, ...);

static void real_comments (struct struct_scr_field *fprop);
static struct s_form_dets *real_read_form (char *fname, char *formname);
static void real_set_default_form (struct s_form_attr *form);
static void real_dump_srec (struct s_form_dets *fd);



#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/**
 *
 */
void *
A4GL_read_form_internal (char *fname, char *formname)
{
  A4GL_debug ("via A4GL_read_form in lib");
  return real_read_form (fname, formname);
}

/**
 *
 */
static struct s_form_dets *
real_read_form (char *fname, char *formname)
{
  int a;
  struct s_form_dets *formdets;
  char buff[512];

  A4GL_trim (fname);
  A4GL_trim (formname);

  A4GL_debug ("in A4GL_read_form fname=%s formname=%s", fname, formname);
  strcpy (buff, fname);
  buff[strlen (buff) - 4] = 0;


#ifdef DEBUG
  A4GL_debug ("fname=%s formname=%s", fname, formname);
#endif

  A4GL_gui_startform (formname);
  formdets =
    (struct s_form_dets *) acl_malloc (sizeof (struct s_form_dets),
				       "Readform");
  formdets->fileform =
    (struct_form *) acl_malloc (sizeof (struct_form), "Readform");

  memset (formdets->fileform, 0, sizeof (struct_form));

#ifdef DEBUG
  A4GL_debug ("Calling A4GL_read_data_from_file with : struct_form,%p,%s",
	 formdets->fileform, fname);
#endif


  a = A4GL_read_data_from_file ("struct_form", formdets->fileform, fname);

  if (!a)
    {
      A4GL_exitwith ("Unable to read form");
      return 0;
    }

  if (formdets->fileform->fcompile_version != FCOMILE_XDR_VERSION)
    {
      A4GL_debug ("Form version %d - my version %d",
	     formdets->fileform->fcompile_version, FCOMILE_XDR_VERSION);
      A4GL_exitwith ("This form has a version number that I can't handle");
      return 0;
    }


  do_translate_form (formdets->fileform);

  formdets->currentfield = 0;
  A4GL_debug ("formdets=%p", formdets);
  read_attributes (formdets);
  A4GL_debug ("formdets=%p", formdets);
  A4GL_read_metrics (formdets);
  A4GL_debug ("formdets=%p", formdets);
  A4GL_read_fields (formdets);
  A4GL_debug ("formdets=%p", formdets);
  A4GL_debug ("Loaded form...");
  A4GL_gui_endform ();
  A4GL_debug ("Ended loading forms (%d, %d)", formdets->fileform->maxcol,
	 formdets->fileform->maxline);
  return formdets;
}



/**
 * Called from lib/libtui/newpanels.c so it should be in API_form
 */
void
A4GL_set_default_form (void *form)
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
  A4GL_debug ("read_attributes %d", f->fileform->attributes.attributes_len);
  for (a = 0; a < f->fileform->attributes.attributes_len; a++)
    {
      //A4GL_debug ("a=%d colour=%d", a, f->fileform->attributes.attributes_val[a].colour);
      //if (f->fileform->attributes.attributes_val[a].colour == -1) f->fileform->attributes.attributes_val[a].colour = 7;


      if (real_has_bool_attribute	/* see a4gl_aubit_lib.h for declaration */
	  (&f->fileform->attributes.attributes_val[a], FA_B_REVERSE))
	f->fileform->attributes.attributes_val[a].do_reverse = 1;
      else
	f->fileform->attributes.attributes_val[a].do_reverse = 0;
      A4GL_debug ("moving onto next\n");
    }
  A4GL_debug ("returning\n");
}


#ifdef MOVED_TO_CURSLIB
/**
 * Called from lib/libtui/ioform.c
 */
void
A4GL_comments (void *fprop)
{
  A4GL_debug ("via A4GL_comments in lib");
  real_comments (fprop);
}

/**
 *
 */
static void
real_comments (struct struct_scr_field *fprop)
{
  if (fprop)
    {
      A4GL_debug ("Has property");
      if (A4GL_has_str_attribute (fprop, FA_S_COMMENTS))
	{
	  A4GL_debug ("Adding comment %s",
		 A4GL_strip_quotes (A4GL_get_str_attribute (fprop, FA_S_COMMENTS)));
	}
    }
}
#endif


/**
 *
 */
void
A4GL_dump_srec (void *fd)
{
  real_dump_srec (fd);
}


/**
 *
 * looks like this is not used because it has return at the top?
 * but there is a call to it from libUI_TUI that needs to be removed
 * if the is the case - and from API_form.spec too
 *
 */
static void
real_dump_srec (struct s_form_dets *fd)
{
  int a;
  int b;

  return;

  A4GL_debug ("fd=%p srecs_cnt=%ld", fd, fd->fileform->records.records_len);
  for (a = 0; a < fd->fileform->records.records_len; a++)
    {
      A4GL_debug ("Screen record : %s [%d] (%d)\n",
	     fd->fileform->records.records_val[a].name,
	     fd->fileform->records.records_val[a].dim,
	     fd->fileform->records.records_val[a].attribs.attribs_len);
      for (b = 0;
	   b < fd->fileform->records.records_val[a].attribs.attribs_len; b++)
	{
	  A4GL_debug ("                    %d\n",
		 fd->fileform->records.records_val[a].attribs.attribs_val[b]);
	}
    }
}



/**
 * called from lib/libtui/ioform.c so it should be in API_form
 */
int
A4GL_check_field_for_include (char *s, char *inc, int dtype)
{
  static char buff[10024];
  char *ptr;
  A4GL_debug ("check_field_for_include (%s,'%s',%d)", s, inc, dtype);
/* no include specified - must be OK */

  if (inc == 0)
    return TRUE;
  if (strlen (inc) == 0)
    return TRUE;

  A4GL_debug ("Checking include");
  dtype = dtype & DTYPE_MASK;
  strcpy (buff, inc);
  ptr = strtok (buff, INC_EACH);

  while (ptr)
    {
      A4GL_debug ("Checking token '%s'", ptr);
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
  char *ptr1=0;
  char *ptr2=0;
  char *ptr3;
  char *s;

  s = strdup (ss);
  A4GL_trim (s);
  A4GL_debug ("include_range_check(%s,%s,%d)", s, ptr, dtype);
	if (strcasecmp(ptr,"NULL")==0) {
		// Check for a null...
		A4GL_debug("NULL ALLOWED");
		if (strlen(s)==0) {
			return 1;
		}
	}

  ptr3 = strchr (ptr, INC_RANGE);

  if (ptr3)
    {
      ptr3[0] = 0;
      ptr3++;
      A4GL_debug ("a range has been specified '%s' to '%s'", ptr, ptr3);
    }

  if (dtype != 0)
    {
	int dim=0;
	A4GL_debug("X111 - dtype!=0 %s (%s)\n",ptr2,ptr1);


      if (dtype==5||dtype==8) {
		dim=0x2010;
	}
      A4GL_debug ("Not a string expression");
      A4GL_push_char (s);
      A4GL_pop_param (&buff, dtype, dim);

      A4GL_push_char (ptr);
      A4GL_pop_param (&buff2, dtype, dim);

      /* do we have a range of values to check ? */
      if (ptr3)
	{
          A4GL_debug("Have a ptr3 - %s - suggests a range",ptr3);
	  A4GL_push_char (ptr3);
	  A4GL_pop_param (&buff3, dtype, dim);
      	  ptr3 = buff3;
	}
      ptr1 = buff;
      ptr2 = buff2;

    }
  else
    {
      A4GL_debug ("String expression");
      ptr1 = s;
      ptr2 = ptr;
    }


  if (ptr3 == 0)
    {
      /* Not a range */
	A4GL_debug("Not a range... %x",dtype);
	if ((dtype&255)==0) {
		A4GL_debug("checking equal for %s %s",ptr1,ptr2);
	}
/*
	if (strcasecmp(ptr2,"NULL")==0) {
		// Check for a null...
		A4GL_trim(ptr1);
		if (strlen(ptr1)==0) {
			return 1;
		}
	}
*/

      A4GL_push_param (ptr1, dtype);
      A4GL_push_param (ptr2, dtype);
      A4GL_debug_print_stack ();
      A4GL_pushop (OP_EQUAL);
      A4GL_debug ("Checking for equal");
      free (s);
      return A4GL_pop_bool ();

    }
  else
    {
      //A4GL_debug ("if ints : %d comp %d", *(int *) ptr1, *(int *) ptr2);
      A4GL_push_param (ptr1, dtype);
      A4GL_push_param (ptr2, dtype);
      A4GL_debug_print_stack ();
      A4GL_pushop (OP_GREATER_THAN_EQ);
      A4GL_debug ("Checking for <=");
      if (A4GL_pop_bool () == 0)
	{
	  free (s);
	  return FALSE;
	}

      //A4GL_debug ("if ints : %d comp %d", *(int *) ptr1, *(int *) ptr3);
      A4GL_push_param (ptr1, dtype);
      A4GL_push_param (ptr3, dtype);
      A4GL_debug_print_stack ();
      A4GL_pushop (OP_LESS_THAN_EQ);
      A4GL_debug ("Checking for >=");
      free (s);
      if (A4GL_pop_bool () == 0)
	return FALSE;
      return TRUE;
    }

}


/**
 *
 */
int
A4GL_has_bool_attribute (void *f, int boolval)
{
  A4GL_debug ("via A4GL_has_bool_attribute in lib");
  return real_has_bool_attribute (f, boolval);
}

static int
real_has_bool_attribute (struct struct_scr_field *f, int boolval)
{
  int a;
  A4GL_debug ("Checking %p for %d\n", f, boolval);
  for (a = 0; a < f->bool_attribs.bool_attribs_len; a++)
    {
      A4GL_debug ("%d %d %d\n", boolval, a, f->bool_attribs.bool_attribs_len);
      if (f->bool_attribs.bool_attribs_val[a] == boolval)
	return 1;
    }
  A4GL_debug ("Nope");
  return 0;
}


/**
 *
 */
static void
do_translate_form (struct_form * the_form)
{
  int a;
  int b;
  char *ptr;

  for (a = 0; a < the_form->metrics.metrics_len; a++)
    {
      if (strncmp
	  (the_form->metrics.metrics_val[a].label, "get_translated_id:",
	   18) == 0)
	{
	  ptr = &the_form->metrics.metrics_val[a].label[18];
	  ptr = (char *) A4GL_get_translated_id (ptr);
	  the_form->metrics.metrics_val[a].label = ptr;
	}
    }

  for (b = 0; b < the_form->attributes.attributes_len; b++)
    {
      for (a = 0;
	   a <
	   the_form->attributes.attributes_val[b].str_attribs.str_attribs_len;
	   a++)
	{
	  if (the_form->attributes.attributes_val[b].str_attribs.
	      str_attribs_val[a].type == FA_S_COMMENTS)
	    {
	      if (strncmp
		  (the_form->attributes.attributes_val[b].str_attribs.
		   str_attribs_val[a].value, "get_translated_id:", 18) == 0)
		{
		  ptr =
		    &the_form->attributes.attributes_val[b].str_attribs.
		    str_attribs_val[a].value[18];
		  ptr = (char *) A4GL_get_translated_id (ptr);
		  if (ptr)
		    the_form->attributes.attributes_val[b].str_attribs.
		      str_attribs_val[a].value = ptr;
		}
	    }
	}
    }
}



void
A4GLFORM_initlib (void)
{
  // Does nothing...
}

/* ============================ EOF ============================== */

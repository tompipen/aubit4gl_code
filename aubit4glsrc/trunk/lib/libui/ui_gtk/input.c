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
# $Id: input.c,v 1.6 2002-11-19 18:18:56 mikeaubury Exp $
#*/

/**
 * @file
 * 4gl INPUT management in GTK GUI mode.
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
                    Constants definitions
=====================================================================
*/

#define ACL4GLGTK

/**
 *
 * @todo Describe function
 */


/*
=====================================================================
                    Variables definitions
=====================================================================
*/


long inp_current_field = 0;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

long get_curr_infield(void);
void gui_set_init_value (GtkWidget * f, void *ptr, int dtype);
static int save_field (struct s_screenio *s, GtkWidget *w);
static int gui_proc_key_input (int a);
static int gui_form_field_constr (void);
static int gui_form_field_chk (void);



extern char *replace_sql_var (char *s); 	/* others.c */

int form_loop (struct s_screenio * s);
int gen_field_chars (GtkWidget *** field_list, GtkWindow * cwin, va_list *ap);
int set_fields (struct s_screenio * sio);
void disp_fields (int n, int attr, va_list * ap);
int push_constr (struct s_screenio *s);
void fgl_infield (char *s, int a);
int field_name_match_gtk (GtkWidget * f, char *s);
void disp_form_fields (int n, int attr, char *s,va_list * ap);
void set_infield_from_stack (void);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * Get the current form in GTK GUI mode.
 *
 * @return The current form
 */
void *
get_curr_form(void)
{
GtkWidget *w;
  
  debug ("**** GET_CURR_FORM_GTK\n");
  w = (GtkWidget *)get_curr_win_gtk ();


  debug ("get_curr_form as %p ", w);

  return w;
}

/**
 * Get the column name for a widget.
 *
 * @param w A pointer to the widget wanted.
 * @return A string with the column name.
 */
static char *
colname_for_field (GtkWidget * w)
{
  char *s;
  debug ("In colname_for_field %p\n", w);
  if (w)
    {
      s = gtk_object_get_data (GTK_OBJECT (w), "Colname");
      debug ("s=%p\n", s);
      debug ("s=%s\n", s);
      return s;
    }
  else
    return " __init__";
}


/**
 * Implementation of the input loop.
 *
 * This is the function where the events are treated such as ON KEY,
 * AFTER FIELD, etc.
 *
 * @param s A pointer to the screen IO structure.
 * @return 
 *   - -1
 *   - 0
 *   -
 */
int
form_loop (struct s_screenio * s)
{
  int a;
  int action;
  long lastfieldval;
  debug ("Form_loop");

  set_abort (0);
  if (s->mode != MODE_CONSTRUCT)
    /* a = gui_form_field_chk (s, 0); */
    a = gui_form_field_chk ();
  else
    /* a = gui_form_field_constr (s, 0); */
	a = gui_form_field_constr ();
  printf ("a=%d\n", a);

  if (a < 0)
    {
      return a;
    }


  while (1)
  {

    action = user_has_done_something ();

    /* printf("Action=%d\n",action); */
    if (action)
      {
	printf ("ACTION\n");
	fflush (stdout);
	break;
      }

    a4gl_usleep (100);
    if (gtk_events_pending ())
      gtk_main_iteration ();
  }

  printf ("checking action %d\n", action);

  if (action == 1)
    {				/* key pressed... */
      int k;
      k = which_key ();
      //printf ("KEY PRESSED 0x%x\n", k);
      clear_something ();
      k = gui_proc_key_input (k);

      if (k == 0)
	{
	  if (s->mode != MODE_CONSTRUCT)
	    /* a = gui_form_field_chk (s, -1); */
        a = gui_form_field_chk ();
	  else
	    /* a = gui_form_field_constr (s, -1); */
        a = gui_form_field_constr ();
	  return 0;
	}

      if (a < 0) {
	debug("Returning %d\n",a);
	return a;
	}
      //printf ("A=%d\n", a);
      return -90;
    }


  if (action == 2)
    {				/* field focus change */
      char buff[256];
      debug ("Action.... - field change\n");
      if (s)
	{
	  if (s->currentfield)
	    {
	      if (save_field (s, s->currentfield) == 0)
		{
		  clear_something ();
		  return 1;
		}
	    }
	}


      printf ("Saved contents to variable...");

      strcpy (buff, colname_for_field ((GtkWidget *)s->currentfield));
      lastfieldval = (long) s->currentfield;
      debug ("***MJA MJA setting current field to %p", get_which_field ());
      s->currentfield = (void *)get_which_field();

      debug ("Pushing %s  ", colname_for_field ((GtkWidget *)s->currentfield));
      debug ("buff=%s\n", buff);

      push_long ((long)s->currentfield);

      push_char (colname_for_field ((GtkWidget *)s->currentfield));	/* before field */

      push_long (lastfieldval);
      push_char (buff);		/*  after field */
      debug ("Pushed");
      clear_something ();
      debug ("Clearing");
      return -1;
    }


  return 0;

}


/**
 * Generate a field list acording to the parameters passed.
 * 
 * Try to find the fields at:
 *   - attribute array.
 *
 * @param field_list A pointer to the place wher the field list should be puted.
 * @param cwin The window widget.
 * @param a Number of variadic parameters passed / 2.
 * @param ...
 * @return The number of fields found.
 */
int
gen_field_list_gtk (GtkWidget *** field_list, GtkWindow * cwin, int a,
		    va_list * ap)
{
  int z;
  int z1;
  int ff;
  int fno;
  int metric_no;
  int mno;
  char colname[40] = "";
  char tabname[40] = "";
  struct_form *formdets;
  GtkWidget *flist[1024];
  char *s;
  int f;
  void *fd1;
  struct struct_metrics *k;
  int attr_no;
  int srec_no;
  int cnt = 0;

  debug ("XXX2");
  debug ("gui_gen_field_list fd=%p\n", cwin);
  fd1 = gtk_object_get_data(GTK_OBJECT(cwin), "currform");
  debug ("fd1=%p\n", fd1);
  formdets = gtk_object_get_data (fd1, "xdr_form");
  debug ("struct_form=%p\n", formdets);

  if (formdets == 0)
    {
      exitwith ("form not there");
      return 0;
    }

  debug_last_field_created ("gfl 1");

  for (z1 = 0; z1 < a; z1++)
    {

      debug ("Getting first %d of %d", z1, a);
      s = va_arg (*ap, char *);

      debug ("s=%p\n", s);
      debug ("s='%s'\n", s);

      if (s == 0)
		break;

      f = (int) va_arg (*ap, int *);

      f--;

      debug (" got screen record subscript number as %d ", f);

      if (f < -1 || f > 10000)
	{

	  debug ("Looks too stupid");

	/* for (a=1;a<10;a++) { s = va_arg (*ap, char *);	debug("%p (%s)",s,s); } */
	  exitwith ("Must have gotten confused somewhere");
	  exit (0);
	}
      ff = 0;

      /* get screen record/table name */

      debug ("calling bname with : %s %s %s\n", s, tabname, colname);
      bname (s, tabname, colname);
      debug ("called bname with : %s '%s' '%s'\n", s, tabname, colname);
      debug ("Calling find_srec");

      debug_last_field_created ("gfl 2");
      srec_no = find_srec (formdets, tabname);
      debug ("srec_no=%d", srec_no);
      if (srec_no != -1)
	{
	  for (z = 0;
	       z < formdets->records.records_val[srec_no].attribs.attribs_len;
	       z++)
	    {
	      attr_no =
		formdets->records.records_val[srec_no].attribs.attribs_val[z];
	      mno =
		attr_name_match (&formdets->
				 attributes.attributes_val[attr_no], s);
	      if (mno)
		{
		  fno = formdets->attributes.attributes_val[attr_no].field_no;
		  if (fno >= formdets->fields.fields_len)
		    {
		      exitwith ("Dubious form\n");
		      return 0;
		    }
		  metric_no =
		    formdets->fields.fields_val[fno].metric.metric_val[f];
		  debug ("fno=%d f=%d mno=%d metric_no=%d\n", fno, f, mno,
			 metric_no);
		  k = &formdets->metrics.metrics_val[metric_no];

		#ifdef DEBUG
			{debug ("cnt=%d a=%d", cnt, a);}
		#endif

		  if (cnt >= a)
		    {
		      exitwith ("Too few variables for the number of fields");
		    }
		  debug ("Setting flist[%d] to %p", cnt, k);
		  flist[cnt++] = (GtkWidget *)k->field;
		  debug ("Set");
		  ff = 1;
		}

	    }
	}

      else
	{
	  for (z = 0; z < formdets->attributes.attributes_len; z++)
	    {
	      attr_no = z;
	      /* debug ("attr_no=%d", attr_no); */
		#ifdef DEBUG
			{debug ("Attr 2"); }
		#endif
	      mno =
		attr_name_match (&formdets->
				 attributes.attributes_val[attr_no], s);
	      if (mno)
		{
		  fno = formdets->attributes.attributes_val[attr_no].field_no;
		  debug ("Matched to field no %d f=%d", fno, f);

		  metric_no =
		    formdets->fields.fields_val[fno].metric.metric_val[f];

		  debug ("metric_no=%d\n", metric_no);

		  k = &formdets->metrics.metrics_val[metric_no];
		#ifdef DEBUG
			{ debug ("cnt=%d a=%d", cnt, a); }
		#endif
		  if (cnt >= a)
		    {
		      debug ("Too few variable");
		      exitwith ("Too few variables for the number of fields");
		    }
		  debug ("Setting flist[%d] to %p", cnt, k->field);
		  flist[cnt++] = (GtkWidget *)k->field;
		  ff = 1;
		}

	    }

	}
      if (ff == 0)
	{
	  exitwith ("Field name not found");
	}

    }

  debug_last_field_created ("gfl 3");
  debug ("H1");

  /*
  s = va_arg (*ap, char *);
  if (s != 0)
  */


  debug_last_field_created ("gfl 3.5");
  /*
  for (f=0;f<cnt;f++) {
  *field_list[f]=flist[f];
  }
  */

  debug_last_field_created ("gfl 4");


	/* allocate a bit more than we need.... */
  *field_list = calloc (cnt + 1, sizeof (GtkWidget *));
  debug ("H2 %p", field_list);
  memcpy (*field_list, flist, sizeof (GtkWidget *) * (cnt + 1));
  debug ("H3 *%p", *field_list);
  /*
  debug ("Returning list\n");
  for (f=0;f<=cnt;f++) {
		debug("Field_list[%d]=%p",f,field_list[f]);
  }
  */
  return cnt - 1;
}

/**
 *
 * @param field_list A pointer to the place where the values should be returned.
 * @param cwin A pointer to the window widget.
 * @param ...
 * @return The number of elements returned.
 */
int
gen_field_chars (GtkWidget *** field_list, GtkWindow * cwin, va_list *ap)
{
  int a;
  //va_list ap;
  //va_start (ap, cwin);

  debug ("XXX1");
  a = gen_field_list_gtk (field_list, GTK_WINDOW(cwin), 9999, ap);
  return a;
}

/**
 * Initialize and assign the input fields and binding to each variable.
 *
 * @param sio A pointer to a screen structure.
 * @return Not used.
 */
int
set_fields (struct s_screenio * sio)
{
/* Disable all fields */
  int a;
  void *fd1;
  int nofields;
  int nv;
  GtkWidget **field_list;
  int wid = 0;			/* input_without_Defaults ?? */

  struct_form *formdets;
  struct struct_metrics *m;
  debug("In set_fields");
  fd1 = gtk_object_get_data (GTK_OBJECT (sio->currform), "currform");
  debug ("fd1=%p\n", fd1);
  formdets = gtk_object_get_data (GTK_OBJECT (fd1), "xdr_form");
  debug ("struct_form=%p\n", formdets);

  if (sio->mode == MODE_INPUT_WITHOUT_DEFAULTS)
    wid = 1;

  nofields = sio->nfields;
  field_list = (GtkWidget **)sio->field_list;

  debug ("Field list=%p number of fields = %d", field_list, nofields);

  nv = sio->novars;

  if (nofields != nv - 1)
    {
      debug
	("Number of fields (%d) is not the same as the number of vars (%d)",
	 nofields + 1, nv);
      exitwith ("Number of fields is not the same as the number of variables");
      return 0;
    }

	/* Disable everything.... */
  for (a = 0; a < formdets->metrics.metrics_len; a++)
    {

      m = &formdets->metrics.metrics_val[a];

      if (m->field)
	gtk_widget_set_sensitive (GTK_WIDGET (m->field), 0);

    }

  for (a = 0; a <= nofields; a++)
    {

      gtk_widget_set_sensitive (field_list[a], 1);

      if (wid)
	{
	  gui_set_init_value (field_list[a], sio->vars[a].ptr,
			      sio->vars[a].dtype);
	}
      else
	{
	  struct struct_scr_field *prop;

	  prop = (struct struct_scr_field *) gtk_object_get_data (
		  GTK_OBJECT(field_list[a]),
		  "Attribute"
		);

	  if (has_str_attribute (prop, FA_S_DEFAULT))
	    {
	      gui_set_init_value (field_list[a],
				  replace_sql_var (strip_quotes
						   (get_str_attribute
						    (prop, FA_S_DEFAULT))),
				  0);
	    }

	  else
	    {
	      gui_set_init_value (field_list[a], 0, 0);
	    }
	}
    }

	debug("Reached the end...");
  return 1;

}

/**
 *
 * @param w
 * @param attr
 */
void 
gui_set_field_pop_attr (GtkWidget * w, int attr)
{
  char *ptr;
  ptr = char_pop ();
	gui_set_field_fore(w, decode_colour_attr_aubit(attr));
  debug ("Calling display_generic with %p and %s\n", w, ptr);
  display_generic (w, ptr);
  free (ptr);
}


/**
 * Display the fields in GTK GUI mode.
 *
 * @param n
 * @param attr The attributes.
 * @param ... The list of fields.
 * @return
 */
void
disp_fields (int n, int attr, va_list * ap)
{
int a;
int flg;
GtkWidget **field_list;
GtkWidget *formdets;
int nofields;

  status = 0;
  debug_last_field_created ("disp_fields1 ");
  debug ("In disp_fields");
  formdets = get_curr_form ();

  if (status != 0)
    return;

  flg = 0;
  debug_last_field_created ("disp_fields2 ");
  nofields = gen_field_list_gtk (&field_list, GTK_WINDOW(formdets), n, ap);
  debug_last_field_created ("disp_fields3 ");

  debug("nofields=%d\n",nofields);

  for (a = 0; a <= nofields; a++)
    {
      debug ("Field[%d]=%p", a, field_list[a]);
    }


  for (a = nofields; a >= 0; a--)
    {
      debug_last_field_created ("disp_fields4 ");
      debug ("Setting field %d of %d\n", a, nofields);
      gui_set_field_pop_attr (field_list[a], attr);
    }
  debug_last_field_created ("disp_fields3 ");
}


/**
 * Just return 1.
 *
 * @return Allways 1.
 */
static int
gui_form_field_chk (void)
{
  return 1;
}

/**
 * Just return 1
 *
 * @return Allways 1
 */
static int
gui_form_field_constr (void)
{
  return 1;
}

/**
 * Process a key pressed in INPUT.
 *
 * @param a The key pressed.
 * @return 
 */
static int
gui_proc_key_input (int a)
{
  printf ("Checking key %x\n", a);
  set_last_key (a);

  if (a == 0xff1b)
    {
      printf ("Accept key pressed!");
      return 0;
    }

  if (a == 3)
    {
      set_last_key (-100);
      return 0;
    }

  return 0;
}


/**
 *
 */
int
gui_proc_key_display_array (int a)
{
  printf ("Checking key %x\n", a);
  set_last_key (a);

  if (a == 0xff1b)
    {
      printf ("Accept key pressed!");
      return 0;
    }

  if (a == 3)
    {
      set_last_key (-100);
      return 0;
    }
  return 0;
}

/**
 * Save the information that is in the form field.
 *
 * @param s The structure where the value will be stored.
 * @param w A pointer to the field wanted.
 * @return 
 *   - 0 : Field not found.
 *   - 1 : Field found and information saved.
 */
static int
save_field (struct s_screenio *s, GtkWidget *w)
{
  int a;
  char *ptr;
  char *z;
  z = (char *)get_which_field ();
  debug ("Current widget=%p field structure=%p", w, z);

  debug ("s->nfields=%d\n", s->nfields);

  for (a = 0; a <= s->nfields; a++)
    {
      debug ("a=%d\n", a);
      debug ("s->field_list[a]=%p\n", s->field_list[a]);
      debug ("w=%p\n", w);
      debug ("...");
      debug ("col=%p\n", colname_for_field (w));
      /* debug("col=%s\n",colname_for_field); */
      debug ("In save_field - %d %p=%p (%s)?\n", a, s->field_list[a], w,
	     colname_for_field (w));
      if (s->field_list[a] == (void *)w)
	{
	  debug ("Found field @ %d\n", a);
	  ptr = fld_val_generic (w);
	  debug ("Field seems to contain : %s", ptr);
	  push_char (ptr);
	  pop_var2 (s->vars[a].ptr, s->vars[a].dtype, s->vars[a].size);
	  return 1;
	}
    }
  debug ("***** FIELD NOT FOUND");
  return 0;
}

/**
 * set the initial value to the field.
 *
 * The initial values are the one that are in the 4gl variable when use 
 * INPUT WITHOUT DEFAULTS or in the default from the form.
 *
 * @param f A pointer to the field widget.
 * @param ptr A pointer to the information to be showed in the widget.
 * @param dtype Data type of the information.
 */
void
gui_set_init_value (GtkWidget * f, void *ptr, int dtype)
{
  char *x;
  debug ("Push %p %d", ptr, dtype);

  if (ptr)
    push_param (ptr, dtype);
  else
    push_char ("");

  x = char_pop ();

  debug ("poped %s\n", x);
  display_generic (f, x);
  debug ("displayed..");
  free (x);
}


/**
 * 
 *
 * @param s Information about the scrren.
 * @return Allways 1
 */
int
push_constr (struct s_screenio *s)
{
  struct struct_scr_field *fprop;
  GtkWidget *f;
  int a;
  char *ptr;
  int flg = 0;
  for (a = 0; a <= s->nfields; a++)
  {
    f = (GtkWidget *)s->field_list[a];
    fprop = (struct struct_scr_field *) gtk_object_get_data(
		  GTK_OBJECT(s->field_list[a]),
			"Attribute"
		);
    debug ("fprop=%p", fprop);
    if (fprop != 0)
	  {
	  debug ("getting ptr", fprop);
	  debug ("fprop->colname=%s fprop->datatype=%x", fprop->colname,
		 (fprop->datatype) & 0xffff);

	  ptr = (char *) construct (fprop->colname,
				    fld_val_generic (f),
				    ((fprop->datatype & 0xffff) == 0)
				    || ((fprop->datatype & 0xffff) == 8));
	  if (strlen (ptr) > 0)
	    {
	      debug ("ptr=%s\n", ptr);
	      if (flg == 0)
		{
		  push_char (ptr);
		  flg = 1;
		}
	      else
		{
		  push_char (" AND ");
		  push_char (ptr);
		  pushop (OP_CONCAT);
		  pushop (OP_CONCAT);
		}
	    }
	}
    }
  if (flg == 0)
    push_char ("1=1");
  return 1;
}


/**
 * Check if the user is currently in one field.
 *
 * @param s The field name to be checked.
 * @param a
 * @return The current feld number.
 */
void
fgl_infield (char *s, int a)
{
  long fld;

  fld=get_curr_infield();

}

/**
 * @param f
 * @param s
 */
int
field_name_match_gtk (GtkWidget * f, char *s)
{
  char colname[40];
  char tabname[40];
  char *f_colname;
  char *f_tabname;
  struct struct_scr_field  *field;

  int aa;
  int ab;

  if (f == 0)
    return 0;

   field = (struct struct_scr_field *) gtk_object_get_data (GTK_OBJECT(f), "Attribute");
   f_colname=field->colname;
   f_tabname=field->tabname;
  aa = strcmp (field->tabname, tabname);
  ab = strcmp (field->colname, colname);

  debug ("Column defined as %s %s", field->tabname, field->colname);

  if ((aa == 0 && ab == 0) || (aa == 0 && colname[0] == '*'))
    {
      debug ("Matches in .*");
      return 1;
    }

  if (ab == 0 && tabname[0] == 0)
    {
      debug ("matches just on column");
      return 1;

    }
  debug ("Doesn't match - %d %d", aa, ab);
  return 0;
}

/**
 *
 */
void
disp_form_fields (int n, int attr, char *s,va_list * ap)
{
	void *cwin;
	void *w;

	debug("In disp_Form_fields_gtk");
	debug("s='%s'\n",s);
	cwin = (GtkWidget *)get_curr_win_gtk ();
	w = find_pointer (s, WINCODE);
	if (w==0) {
		exitwith("Form not open");
		return;
	}
	debug("Swapping %p for %p",w,cwin);
	set_current_window(w);
	disp_fields(n,attr,ap);
	debug("Swapping %p for %p",cwin,w);
	set_current_window(cwin);
}


/**
 *
 */
void
set_infield_from_stack (void)
{
  debug("**** CHANGED FIELD ****");
  inp_current_field = pop_long ();
  debug("New field :---> %p",inp_current_field);
}


/**
 * @return The current field number.
 */
long
get_curr_infield(void) {
        return inp_current_field;
}


/* =============================== EOF ============================= */

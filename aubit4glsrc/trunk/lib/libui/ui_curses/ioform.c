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
# $Id: ioform.c,v 1.12 2003-03-29 16:48:31 mikeaubury Exp $
#*/

/**
 * @file
 *
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


#include "a4gl_lib_ui_tui_int.h"

/*
=====================================================================
                    Constants definitions
=====================================================================
*/

#define POS_FIRST 		1
#define POS_VERY_FIRST 	2
#define POS_VERY_LAST 	4
#define POS_LAST 		8

/* SYSTEM Defines - dont change! */

#define DEFAULT 		-1
#define YES 			1
#define YES_COMPRESS 	2
#define CASEON 			1
#define CASEOFF 		0
#define OPTIONS 		long

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

extern WINDOW 	*	currwin;
int 				m_lastkey = 0;
int 				tab_cnt = 0;
int 				srec_cnt = 0;
extern int 			errno;
char 				delimiters[4];

int 				lastc = 0;
int 				nline;
int 				fline;
int 				ncol;
char 				dbname[64];
long 				inp_current_field = 0;
int 				do_input_nowrap=0;


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/


/** @todo Take this prototype definition for a header file */

extern char *	replace_sql_var 	(char *s);
char *			read_string_dup 	(FILE * ofile);
struct s_form_dets *getfromform 	(FORM * f);
char *			string_width 		(char *a);
WINDOW *		create_window 		(char *name, int x, int y, int w, int h, int border);


#ifdef OBSOLETE
void 	set_fields2 		(int nv, struct BINDING * vars, int d, int n,...);
#endif

int 			display_fields 		(FORM * mform, int n, ...);
extern char * 	find_attribute 		(struct s_form_dets *f, int field_no);
void 			debug_print_field_opts (FIELD * a);
void 			mja_set_field_buffer (FIELD * field, int nbuff, char *buff);
void 			set_field_pop_attr 	(FIELD * field, int attr);
int 			find_field_no 		(FIELD * f, struct s_screenio *sio);
void 			do_after_field 		(FIELD * f, struct s_screenio * sio);
int 			get_metric_for 		(struct s_form_dets * form, FIELD * f);
int 			get_field_width 	(FIELD * f);
int 			page_for_nfield 	(struct s_screenio * s);
int 			proc_key 			(int a, FORM * mform, struct s_screenio * s);
int 			form_field_chk 		(struct s_screenio *sio, int m);
int 			form_field_constr 	(struct s_screenio *sio, int m);
int 			get_curr_metric 	(struct s_form_dets *form);
int 			page_for_pfield 	(struct s_screenio * s);

void 			field_autonext 		(FIELD * f);
void 			field_dynamic 		(FIELD * f);
void 			field_invisible 	(FIELD * f);
void 			field_noentry 		(FIELD * f);
void 			set_field_attr 		(FIELD * field);
int 			req_field 			(struct s_screenio *s, ...);
int 			form_loop 			(struct s_screenio * s);
void 			set_init_value 		(FIELD * f, void *ptr, int dtype);
int 			get_metric_no 		(struct s_form_dets * form, FIELD * f);
int 			turn_field_off 		(FIELD * f);
void 			turn_field_on 		(FIELD * f);
void 			turn_field_on2 		(FIELD * f, int a);
void 			set_init_pop 		(FIELD * f);
int 			set_fields 			(struct s_screenio *sio);
int 			field_name_match 	(FIELD * f, char *s);
void 			disp_fields 		(int n, int attr, va_list * ap);
int 			gen_field_chars 	(FIELD *** field_list, struct s_form_dets *formdets,
				                     va_list * ap);

void 			do_before_field 	(FIELD * f, struct s_screenio *sio);
void 			dump_fields 		(FIELD * fields[]);
void 			set_init_pop_attr 	(FIELD * field, int attr);
int 			push_constr 		(struct s_screenio *s);

FIELD * 		scan_for_field 		(char *s);
void 			set_infield_from_stack (void);
int 			get_curr_infield	(void);
int 			fgl_infield 		(char *s, int a);
int 			fgl_getfldbuf 		(char *s, int a);
int 			key_prompt 			(int a, FORM * mform, struct s_prompt * prompt);
void 			reset_delims 		(struct s_form_dets * formdets, char *delims);
int 			page_for_field 		(struct s_screenio * s, FIELD * f);
int 			page_for_cfield 	(struct s_screenio * s);
void 			clr_form 			(int to_default);
void 			disp_form_fields 	(int n, int attr, char *formname,...);
int 			curr_metric_is_last (void);
int 			curr_metric_is_first (void);
int 			curr_metric_is_veryfirst (void);
int 			curr_metric_is_verylast (void);
int curses_to_aubit(int a);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/**
 *
 * @todo Describe function
 */
struct s_form_dets *
getfromform (FORM * f)
{
  return f->usrptr;
}


/**
 *
 * @todo Describe function
 */
FIELD *
make_label (int frow, int fcol, char *label)
{
  FIELD *f = new_field (1, strlen (label), frow, fcol, 0, 0);
  gui_mklabel (1, strlen (label), frow, fcol, label);
  if (f)
    {
      mja_set_field_buffer (f, 0, label);
      set_field_opts (f, field_opts (f) & ~O_ACTIVE);
    }
  else
    {
	#ifdef DEBUG
	      {        debug ("FIeld not created!!!");      }
	#endif
    }
  return (f);
}



/**
 *  @todo Validate the calls to make_label that alocates space to a FIELD
 *  struct and assigns the pointer to integers.
 */
int
read_metrics (struct s_form_dets *formdets)
{
int a, n;
int last_field = -1;
int cnt = 0;
int lscr = 1;
int lfieldscr = -1;
char delims[3][2];
delims[0][0] = formdets->fileform->delim[0];
delims[1][0] = formdets->fileform->delim[1];
delims[2][0] = formdets->fileform->delim[2];
delims[0][1] = 0;
delims[1][1] = 0;
delims[2][1] = 0;

  n = formdets->fileform->metrics.metrics_len;
  debug ("metrics len=%d", n);
  for (a = 0; a < n; a++)
    {
      formdets->fileform->metrics.metrics_val[a].pos_code = 0;
      debug ("checking label\n");


      if (strlen (formdets->fileform->metrics.metrics_val[a].label) != 0)
        {
          formdets->fileform->metrics.metrics_val[a].field =
            (int) make_label (formdets->fileform->metrics.metrics_val[a].y,
                              formdets->fileform->metrics.metrics_val[a].x,
                              formdets->fileform->metrics.metrics_val[a].
                              label);
          formdets->form_fields[cnt++] =
            (FIELD *) formdets->fileform->metrics.metrics_val[a].field;
          formdets->form_fields[cnt] = 0;
        }
      else
        {
          debug ("Making field");
          formdets->fileform->metrics.metrics_val[a].field =
            (int) make_field (formdets->fileform->metrics.metrics_val[a].y,
                              formdets->fileform->metrics.metrics_val[a].x, 1,
                              formdets->fileform->metrics.metrics_val[a].w);
          formdets->form_fields[cnt++] =
            (FIELD *) formdets->fileform->metrics.metrics_val[a].field;
          formdets->form_fields[cnt] = 0;
          formdets->fileform->metrics.metrics_val[a].dlm1 =
            (int) make_label (formdets->fileform->metrics.metrics_val[a].y,
                              formdets->fileform->metrics.metrics_val[a].x -
                              1, delims[0]);
          formdets->form_fields[cnt++] =
            (FIELD *) formdets->fileform->metrics.metrics_val[a].dlm1;
          formdets->fileform->metrics.metrics_val[a].dlm2 =
            (int) make_label (formdets->fileform->metrics.metrics_val[a].y,
                              formdets->fileform->metrics.metrics_val[a].x +
                              formdets->fileform->metrics.metrics_val[a].w,
                              delims[1]);
          formdets->form_fields[cnt++] =
            (FIELD *) formdets->fileform->metrics.metrics_val[a].dlm2;
          formdets->form_fields[cnt] = 0;
        }


      if (lscr != formdets->fileform->metrics.metrics_val[a].scr)
        {
          lscr = formdets->fileform->metrics.metrics_val[a].scr;
          set_new_page ((FIELD *) formdets->fileform->metrics.metrics_val[a].
                        field, 1);
        }



      if (strlen (formdets->fileform->metrics.metrics_val[a].label) == 0)
        {
          if (last_field == -1)
            {
              formdets->fileform->metrics.metrics_val[a].pos_code +=
                POS_VERY_FIRST;}
          debug ("LAST_FIELD2 -CHK111");
          debug ("LAST_FIELD1 -CHK111");
        }

      if (lfieldscr != formdets->fileform->metrics.metrics_val[a].scr
          && strlen (formdets->fileform->metrics.metrics_val[a].label) == 0)
        {

          formdets->fileform->metrics.metrics_val[a].pos_code += POS_FIRST;

          if (last_field != -1)
            {
              formdets->fileform->metrics.metrics_val[last_field].pos_code +=
                POS_LAST;
            }
          lfieldscr = formdets->fileform->metrics.metrics_val[a].scr;
        }
      debug ("LAST_FIELD3 -CHK111 a=%d label='%s'", a,
             formdets->fileform->metrics.metrics_val[a].label);
      if (strlen (formdets->fileform->metrics.metrics_val[a].label) == 0)
        last_field = a;
    }

  debug ("Last_field=%d\n", last_field);
  if (last_field < 0)
    {
      exitwith ("Internal Error");
      return 0;
    }

  formdets->fileform->metrics.metrics_val[last_field].pos_code += POS_VERY_LAST;

return 1;
}


/**
 *
 * @todo Describe function
 */
void
default_attributes (FIELD * f, int dtype)
{
  debug ("In def attrib f=%p", f);

  if (dtype == 0)
    set_field_opts (f, O_VISIBLE | O_ACTIVE | O_PUBLIC | O_EDIT | O_STATIC);
  else
    set_field_opts (f,
                    O_VISIBLE | O_ACTIVE | O_PUBLIC | O_EDIT | O_STATIC |
                    O_BLANK);

  debug ("STATIC");
  set_field_fore (f, colour_code (7));
  set_field_back (f, colour_code (7));
}

/**
 *
 * @todo Describe function
 */
void
field_autonext (FIELD * f)
{
  field_opts_on (f, O_AUTOSKIP);
}

/**
 *
 * @todo Describe function
 */
void
field_dynamic (FIELD * f)
{
  field_opts_off (f, O_STATIC);
}

/**
 *
 * @todo Describe function
 */
void
field_invisible (FIELD * f)
{
  field_opts_off (f, O_PUBLIC);
}

/**
 *
 * @todo Describe function
 */
void
field_noentry (FIELD * f)
{
  field_opts_off (f, O_ACTIVE);
  field_opts_off (f, O_EDIT);
}

/**
 *
 * @todo Describe function
 */
void
set_field_attr (FIELD * field)
{
  struct struct_scr_field *f;
  int bc;
  int fc;
  bc = field_back (field);
  fc = field_fore (field);

  debug ("In set_field_attr");
  f = (struct struct_scr_field *) (field_userptr (field));
  if (f == 0)
    return;
  debug ("Setting defs");
  default_attributes (field, f->datatype);
  debug ("Set defs");

  if (has_bool_attribute (f, FA_B_AUTONEXT)) {
	debug("Autoskip");
    field_opts_on (field, O_AUTOSKIP);
  }

  if (has_bool_attribute (f, FA_B_INVISIBLE))
    {
	debug("Invisible");
      field_opts_off (field, O_PUBLIC);
    }

  if (f->dynamic != 0)
    {
      field_opts_off (field, O_STATIC);

      if (f->dynamic == -1)
        {
          debug ("Max size is lots");
          set_max_field (field, 0);
        }
      else
        {
          set_max_field (field, f->dynamic);
          debug ("Max size=%d", f->dynamic);
        }

    }

  if (has_bool_attribute (f, FA_B_NOENTRY))
    {
	debug("No entry");
      field_opts_off (field, O_ACTIVE);
      field_opts_off (field, O_EDIT);
    }

  if (has_bool_attribute (f, FA_B_REQUIRED))
    {
      field_opts_off (field, O_NULLOK);
    }

  if (f->do_reverse && f->colour == AUBIT_COLOR_WHITE)
    {
	debug("XX1 REVERSE");
      set_field_fore (field, A_REVERSE);
      set_field_back (field, A_REVERSE);
    }

  if (has_bool_attribute (f, FA_B_WORDWRAP))
    {
      field_opts_on (field, O_WRAP);
    }

  if (f->do_reverse && f->colour != AUBIT_COLOR_WHITE)
    {
     debug("XX2 REVERSE");
      set_field_back (field, decode_colour_attr_aubit(f->colour) | A_REVERSE);
      set_field_fore (field, decode_colour_attr_aubit(f->colour) | A_REVERSE);
    }

  if (f->do_reverse == 0 && f->colour != AUBIT_COLOR_WHITE)
    {
      set_field_fore (field, decode_colour_attr_aubit (f->colour));
      set_field_back (field, decode_colour_attr_aubit (f->colour));
    }
  if (f->do_reverse == 0 && f->colour == AUBIT_COLOR_WHITE)
    {
      set_field_fore (field, decode_colour_attr_aubit (f->colour));
      set_field_back (field, decode_colour_attr_aubit (f->colour));
    }

  if (bc != field_back (field) || fc != field_fore (field))
    {
      gui_setattr ((long)field, field_fore (field), field_back (field));
    }
  debug ("Returning");
}

/**
 *
 * @todo Describe function
 */
int
req_field (struct s_screenio *s, ...)
{                               /* does nothing yet... */
/* fieldname + = next - = previous */
  int a;
  FIELD **ptr;
  struct s_form_dets *sdets;
  va_list ap;
  va_start (ap, s);

  debug ("req_field");
  a = gen_field_list (&ptr, s->currform, 1, &ap);


  if (a >= 0)
    {
      debug ("Found our field...\n");
    }
  else
    {
      exitwith ("Field not found");
      return 0;
    }
  debug ("Setting current field to %p", ptr[0]);
  sdets = s->currform;
  set_current_field (sdets->form, ptr[0]);

  pos_form_cursor (sdets->form);
  free (ptr);
return 1;
}

/**
 * 4GL CALL
 * @todo Describe function
 */
int
form_loop (struct s_screenio * s)
{
  struct s_form_dets *form;
  int a;
  //int int_form_driver_ret = 0;
  struct struct_scr_field *fprop;
  struct struct_metrics *metrics;
  FORM *mform;
  form = s->currform;
  set_abort (0);

  if (form != get_curr_form ())
    {
	debug("form=%p curr_form=%p",form,get_curr_form());
        exitwith ("Input form is not current");
	return 0;
    }

  mform = form->form;
  mja_wrefresh (currwin);



  if (s->mode != MODE_CONSTRUCT)
    a = form_field_chk (s, 0);
  else
    a = form_field_constr (s, 0);


  pos_form_cursor (mform);

  // Have we changed fields ?
  if (a < 0)
    { 
	// Yep...
      return a;
    }


  fprop = (struct struct_scr_field *) field_userptr (current_field (mform));
  metrics = &form->fileform->metrics.metrics_val[get_curr_metric (form)];

  if (metrics && (int) metrics != -1)
    {
      set_form_page (mform, metrics->scr - 1);
    }


// Wait for a key..
  a = getch_win ();
  if (abort_pressed) a = -1;


// Process the key..
  a = proc_key (a, mform, s);


// Looks like we're done
  if (a == 0)
    {
      if (s->mode != MODE_CONSTRUCT)
        a = form_field_chk (s, -1);
      else
        a = form_field_constr (s, -1);

      return 0;
    }



// Looks like we've got something to do...


// Have we changed fields ?
  if (a < 0) {
		// Yep...
		return a;
  }

  int_form_driver (mform, a);

  mja_wrefresh (currwin);

  if (a >= 0 && a <= 255)
    {
      int_form_driver (mform, REQ_VALIDATION);
    }



  return -90;

}



/**
 *
 * @todo Describe function
 */
int
proc_key (int a, FORM * mform, struct s_screenio * s)
{
  FIELD *f;
  struct s_form_attr *form;
  struct struct_scr_field *fprop;
  struct s_form_dets *fd;
  int npage;
  int acckey;
  fd = getfromform (mform);
  form = &fd->form_details;
  do_input_nowrap=0;

  debug ("proc_key .... %d", a);
  f = current_field (mform);
  debug ("Current field=%p\n", f);
  if (a != 10)
    {
      debug ("Getting fprop");
      fprop = (struct struct_scr_field *) (field_userptr (f));
      debug ("fprop=%p\n", fprop);

      if (fprop != 0)
        {
          debug ("Downshift?");
          if (has_bool_attribute (fprop, FA_B_DOWNSHIFT) && isupper (a)
              && isalpha (a))
            {
              a = tolower (a);
            }
          debug ("Upshift ?");
          if (has_bool_attribute (fprop, FA_B_UPSHIFT) && islower (a)
              && isalpha (a))
            {
              a = toupper (a);
            }
        }

    }

  acckey = key_val ("ACCEPT");

  debug ("Got key %d", a);

  m_lastkey = a;
  set_last_key(curses_to_aubit(a));

  if (a == acckey)
    {
      int_form_driver (mform, REQ_VALIDATION);
      s->field_changed = 1;
      return 0;
    }


  switch (a)
    {
    case 18:
      mja_wrefresh (stdscr);
      mja_wrefresh (currwin);
      mja_refresh ();
      break;


    case -1:
      debug ("proc_key - got an interrupt");
      int_form_driver (mform, REQ_VALIDATION);
      m_lastkey = key_val("INTERRUPT");
      s->field_changed = 1;
      return 0;


    case 26:
      return 0;

    case 127:
    case 8:
    case KEY_DC:
    case KEY_DL:
    case KEY_BACKSPACE:
      return REQ_DEL_PREV;
    case 24:
      return REQ_DEL_CHAR;

    case KEY_UP:
      npage = page_for_pfield (s) - 1;
      set_form_page (s->currform->form, npage);
/*
   if (curr_metric_is_first ())
   {
   //error_box ("iS First");
   int_form_driver (mform, REQ_PREV_PAGE);
   return REQ_PREV_FIELD;
   }

   if (curr_metric_is_veryfirst ())
   {
   int_form_driver (mform, REQ_LAST_PAGE);
   }
 */
      s->field_changed = 1;
      return REQ_PREV_FIELD;

      /*
         case KEY_PGUP : return REQ_PREV_PAGE;
         case KEY_PGDN : return REQ_NEXT_PAGE;
       */

    case '	':
    case KEY_ENTER:
    case 13:
    case 10:
    case KEY_DOWN:
	if (std_dbscr.input_wrapmode==0 && curr_metric_is_verylast())  {
      		s->field_changed = 1;
      		do_input_nowrap=1;
		return 0;
	}

      npage = page_for_nfield (s) - 1;
      set_form_page (s->currform->form, npage);
/*
   if (page_for_cfield()<page_for_nfield()) {
   return REQ_NEXT_PAGE;
   }

   if (page_for_cfield()>page_for_nfield()) {
   return REQ_FIRST_PAGE;
   }

   if (curr_metric_is_last ())
   {
   return REQ_NEXT_PAGE;
   }

   if (curr_metric_is_verylast ())
   {
   return REQ_FIRST_PAGE;
   }
 */

      s->field_changed = 1;
      return REQ_NEXT_FIELD;

    case KEY_LEFT:
      return REQ_PREV_CHAR;

    case KEY_RIGHT:
      return REQ_NEXT_CHAR;

    case 4: // Control - D
      return REQ_CLR_EOF;

    case 1: // Control - A
      form->insmode = form->insmode ? 0 : 1;
      if (form->insmode)
        return REQ_INS_MODE;
      else
        return REQ_OVL_MODE;
    }
  mja_refresh ();
  return a;
}

/**
 *
 * @todo Describe function
 */
void
set_init_value (FIELD * f, void *ptr, int dtype)
{
  char *ff;
  int a;

  debug ("field width=%d", get_field_width (f));
  if (ptr != 0)
    {
      debug ("Got init value");
      push_param (ptr, dtype);
      ff = new_string (get_field_width (f));
      pop_char (ff, get_field_width (f));
    }
  else
    {
      ff = new_string (get_field_width (f));
      for (a = 0; a < get_field_width (f); a++)
        ff[a] = ' ';
      ff[get_field_width (f) - 1] = 0;
    }
  debug ("set_init_value : display '%s' to field", ff);
  mja_set_field_buffer (f, 0, ff);
  debug ("Init complete");
}

/**
 *
 * @todo Describe function
 */
int
read_fields (struct s_form_dets * formdets)
{
  int a, n;
  int n1, a1;
  int metric_no;
  char *ptr;

  n = formdets->fileform->fields.fields_len;
  debug ("Got %d fields\n", n);

  formdets->fields_cnt = n;

  for (a = 0; a < n; a++)
    {
      ptr = find_attribute (formdets, a);
      n1 = formdets->fileform->fields.fields_val[a].metric.metric_len;

      for (a1 = 0; a1 < n1; a1++)
        {
          metric_no =
            formdets->fileform->fields.fields_val[a].metric.metric_val[a1];
          debug ("Metric number read as %d\n", metric_no);

          if (formdets->fileform->metrics.metrics_val[metric_no].field != 0)
            {
              debug ("Has an associated field");
              if (ptr != 0)
                {
                  debug ("Has associated attribute!");
                  set_field_userptr ((FIELD *) formdets->fileform->metrics.
                                     metrics_val[metric_no].field, ptr);
                  set_field_attr ((FIELD *) formdets->fileform->metrics.
                                  metrics_val[metric_no].field);
                  debug ("Done\n");
                }
            }
        }
    }
  debug("formdets->form_fields=%p",formdets->form_fields);
  formdets->form = new_form ((FIELD **)formdets->form_fields);
  if (formdets->form == 0)
    {
      exitwith ("Failed to create the loaded the form");
      return 0;
    }
  set_form_userptr (formdets->form, formdets);
  debug ("Loaded form...");
return 1;
}


/**
 *
 * @todo Describe function
 */
void
start_form (struct s_form_dets *s)
{
  int_form_driver (s->form, REQ_FIRST_PAGE);
  int_form_driver (s->form, REQ_FIRST_FIELD);
  pos_form_cursor (s->form);

  if (s->form_details.insmode)
    int_form_driver (s->form, REQ_INS_MODE);
  else
    int_form_driver (s->form, REQ_OVL_MODE);

  /*form_field_chk (s, 1); */
}

/**
 *
 * @todo Describe function
 */
int
form_field_chk (struct s_screenio *sio, int m)
{
  char buff[80] = "";
  char buff2[80] = "";
  FORM *mform;
  int x, y;
  int flg = 0;
  struct s_form_dets *form;
  struct struct_scr_field *fprop;

  mform = sio->currform->form;
  debug ("CHeck fields 1 m=%d", m);
  form = sio->currform;
  debug ("CHeck fields 2");

  fprop = 0;
  if (m > 0)
    {
      debug ("CHeck fields 3");
      form->currentfield = 0;
      form->currentmetrics = 0;
      debug (" m ");
      return 0;
    }


  debug (" current field %p  currfield=%p m=%d", form->currentfield,
         current_field (mform), m);
  if ((form->currentfield != current_field (mform)) || m < 0)
    {
      /*
	  debug ("Setting focus");
      gui_setfocus (current_field (mform));
      */
      debug ("Is different");
      fprop = 0;

      if (form->currentfield != 0)
        if (field_userptr (form->currentfield) != 0)
          {
            debug ("Is a proper field");
            fprop =
              (struct struct_scr_field
               *) (field_userptr (form->currentfield));
            debug ("fprop=%p", fprop);
            if (fprop != 0)
              {
                debug ("check Datatype ");
                if (((fprop->datatype != (DTYPE_CHAR & DTYPE_MASK)))
                    && (field_status (form->currentfield)))
                  {
                    debug ("modify size dtype");
                    debug ("modfy size for metric %d",
                           get_metric_for (form, form->currentfield));
                    modify_size (&buff[4],
                                 form->fileform->metrics.
                                 metrics_val[get_metric_for
                                             (form, form->currentfield)].w);
                    debug ("modfy size done -> '%s'", &buff[4]);

                    strcpy (&buff[4], field_buffer (form->currentfield, 0));
                    debug ("copy 1");
                    strcpy (buff2, &buff[4]);
                    debug ("copy 2");
                    debug ("trim buff");
                    trim (buff2);
                    getsyx (y, x);

                    debug ("CHange y=%d, x=%d", y, x);
                    debug ("stack manip buff2='%s'", buff2);
                    if (strlen (buff2) > 0)
                      {
#ifdef DEBUG
                        {                          debug ("Pushing param %p");                        }
#endif
                        push_param (buff2, DTYPE_CHAR);
                        if (pop_param
                            (buff, fprop->datatype,
                             get_field_width (form->currentfield)))
                          {
#ifdef DEBUG
                            {                              debug ("Pushing param %p %d", buff, fprop->datatype);                            }
#endif
                            push_param (buff, fprop->datatype);
                            if (has_str_attribute (fprop, FA_S_FORMAT))
                              {
                                push_char (get_str_attribute
                                           (fprop, FA_S_FORMAT));
                                //push_param ("using", FUNCTION_OP);
                                pushop (OP_USING);
                              }
                            pop_param (buff, DTYPE_CHAR,
                                       get_field_width (form->currentfield));
                            mja_set_field_buffer (form->currentfield, 0,
                                                  buff);
                          }
                        else
                          {
			//push_char(acl_getenv("FIELD_ERROR_MSG"));
			//display_error(1,0);
                            error_box (acl_getenv ("FIELD_ERROR_MSG"));
                            debug ("Couldnt read datatype...");
                            mja_set_field_buffer (form->currentfield, 0, " ");
                            set_current_field (mform, form->currentfield);
                          }
                      }
                  }
              }
          }
    }

  debug ("fprop=%p", fprop);
  debug ("form->currentfield=%p", form->currentfield);
  if (fprop)
    {
      debug ("fprop->include=%p", get_str_attribute (fprop, FA_S_INCLUDE));
      debug ("fprop->datatype=%d", fprop->datatype);
    }

  if (form->currentfield != current_field (mform) || m < 0
      || sio->field_changed)
    {
      sio->field_changed = 0;
      fprop =
        (struct struct_scr_field *) (field_userptr (current_field (mform)));

      if (fprop != 0)
        {
          /* push_long (form->currentfield); */
          push_long ((long)current_field (mform));
          push_char (fprop->colname);
        }
      else
        {
          push_long ((long)0);
          push_char ("THIS FIELD IS AT THE START");
        }

      fprop =
        (struct struct_scr_field *) (field_userptr (form->currentfield));
      if (fprop != 0)
        {
          do_after_field (form->currentfield, sio);
          /* push_long (current_field (mform)); */
          push_long ((long)form->currentfield);
          push_char (fprop->colname);
        }
      else
        {
          push_long ((long)0);
          push_char ("THIS FIELD IS AT THE START");
        }
      flg = -1;
    }
#ifdef DEBUG
  {    debug ("Setting current field");  }
#endif
  form->currentfield = current_field (mform);
  fprop = (struct struct_scr_field *) (field_userptr (form->currentfield));
#ifdef DEBUG
  {    debug ("Adding comments %p");  }
#endif
  if (fprop != 0)
    comments (fprop);

#ifdef DEBUG
  {    debug ("returning");  }
#endif
  return flg;

}

/**
 *
 * @todo Describe function
 */
int
get_curr_metric (struct s_form_dets *form)
{
  int a;
  debug ("In curr metric");
  for (a = 0; a < form->fileform->metrics.metrics_len; a++)
    {
      if (current_field (form->form) ==
          (FIELD *) form->fileform->metrics.metrics_val[a].field)
        {
          debug ("Returning %d\n", a);
          return a;
        }
    }
  debug ("NO current metric !");
  return -1;
}

/**
 *
 * @todo Describe function
 */
int
get_metric_no (struct s_form_dets * form, FIELD * f)
{
  int a;
  debug ("In curr metric");
  for (a = 0; a < form->fileform->metrics.metrics_len; a++)
    {
      if (f == (FIELD *) form->fileform->metrics.metrics_val[a].field)
        {
          debug ("Returning %d\n", a);
          return a;
        }
    }
  debug ("NO current metric !");
  return -1;
}


/**
 *
 * @todo Describe function
 */
int
get_metric_for (struct s_form_dets * form, FIELD * f)
{
  int a;

  debug ("In curr metric");
  for (a = 0; a < form->fileform->metrics.metrics_len; a++)
    {
      if (f == (FIELD *) form->fileform->metrics.metrics_val[a].field)
        {
          debug ("Returning %d\n", a);
          return a;
        }
    }
  debug ("NO current metric !");
  return -1;
}


/**
 *
 * @todo Describe function
 */
int
get_field_width (FIELD * f)
{
  int x, y, a;
  dynamic_field_info (f, &y, &x, &a);
  return x;
}

/**
 *
 * @todo Describe function
 */
int
turn_field_off (FIELD * f)
{
  struct struct_scr_field *fprop;
  int a;
  fprop = (struct struct_scr_field *) (field_userptr (f));
  debug ("Turn Field Off %s %s", fprop->tabname, fprop->colname);
  a = field_opts_off (f, O_ACTIVE);
  debug ("a=%d", a);
  a += field_opts_off (f, O_EDIT);
  debug ("a=%d", a);
  if (a == 0)
    return 0;
  return 1;

}

/**
 *
 * @todo Describe function
 */
void
turn_field_on (FIELD * f)
{
  struct struct_scr_field *fprop;
  int a;
  fprop = (struct struct_scr_field *) (field_userptr (f));
  debug ("Turn Field On %s %s", fprop->tabname, fprop->colname);
  a = field_opts_on (f, O_ACTIVE);
  debug ("a=%d", a);
  a = field_opts_on (f, O_EDIT);
  debug ("a=%d", a);
  set_field_attr (f);
}

/**
 *
 * @todo Describe function
 */
void
turn_field_on2 (FIELD * f, int a)
{

  struct struct_scr_field *fprop;
  assertion(f==0,"Field is zero in turn_field_on2");
  debug ("Turn field on %p %d", f, a);
  fprop = (struct struct_scr_field *) (field_userptr (f));
  assertion(fprop==0,"Field has no properties");
  debug ("turn_field_on2 a=%d fprop=%p", a, fprop);
  debug ("Turn Field On %s %s", fprop->tabname, fprop->colname);
  field_opts_on (f, O_ACTIVE);
  field_opts_on (f, O_EDIT);

  if (a)
    {
      debug ("STATIC");
      field_opts_on (f, O_STATIC);
      set_max_field (f, 0);
    }
  else
    {
      debug ("NOT STATIC");
      field_opts_off (f, O_STATIC);
    }
  set_field_attr (f);
}


/**
 *
 * @todo Describe function
 */
void
set_init_pop (FIELD * f)
{
  char *ff;
  ff = new_string (get_field_width (f));
  pop_char (ff, get_field_width (f));
  debug ("set_init_pop : display %s to field", ff);
  mja_set_field_buffer (f, 0, ff);
  touchwin (currwin);
}


/**
 * 4GL CALL
 * @todo Describe function
 */
int
set_fields (struct s_screenio *sio)
{
  int wid;
  int a;
  int nv;
  int flg;
  struct s_form_dets *formdets;
  struct struct_scr_field *field;
  struct struct_scr_field *prop;
  FIELD **field_list;
  FIELD *firstfield = 0;
  int nofields;
  
  
  wid = 0;
  if (sio->mode == MODE_INPUT_WITHOUT_DEFAULTS || sio->mode==MODE_INPUT_ARRAY)
    wid = 1;
  debug ("in set fields");
  formdets = sio->currform;
  debug ("set fdets");

  flg = 0;

  debug ("Turning off all");

  for (a = 0; formdets->form_fields[a] != 0; a++)
    {
      field =
        (struct struct_scr_field
         *) (field_userptr (formdets->form_fields[a]));
      if (field == 0)
        continue;

      if (turn_field_off (formdets->form_fields[a]))
        {
          firstfield = formdets->form_fields[a];
        }

    }

  nofields = sio->nfields;
  field_list = (FIELD **)sio->field_list;

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

  for (a = 0; a <= nofields; a++)
    {

      if (field_list[a] == firstfield)
        {
          firstfield = 0;
        }
      debug ("loop through fields a=%d %p", a, field_list[a]);
      turn_field_on2 (field_list[a], sio->mode != MODE_CONSTRUCT);

      if (wid)
        {
          set_init_value (field_list[a], sio->vars[a].ptr,
                          sio->vars[a].dtype);
        }
      else
        {
          prop = (struct struct_scr_field *) field_userptr (field_list[a]);
          if (has_str_attribute (prop, FA_S_DEFAULT))
            {
              debug ("default from form to '%s'",
                     get_str_attribute (prop, FA_S_DEFAULT));
              set_init_value (field_list[a],
                              replace_sql_var (strip_quotes
                                               (get_str_attribute
                                                (prop, FA_S_DEFAULT))), 0);
            }
          else
            {
              set_init_value (field_list[a], 0, 0);
            }
        }

      if (sio->mode != MODE_CONSTRUCT)
        {
          push_char (field_buffer (field_list[a], 0));
          pop_var2 (sio->vars[a].ptr, sio->vars[a].dtype, sio->vars[a].size);
        }

      if (flg == 0)
        {
          set_current_field (formdets->form, field_list[a]);
			/*formdets->form_fields[z]); */
          flg = 1;
        }

    }

  if (firstfield)
    turn_field_off (firstfield);

  if (flg == 0)
    {
      error_box ("NO active field\n");
    }
  return 1;
}



#ifdef OBSOLETE
/**
 *
 * @todo Describe function
 */
void
set_fields2 (int nv, struct BINDING * vars, int d, int n,...)
{
  int a;
  va_list ap;
  int z;
  int flg;
  char errbuff[80];
  struct s_form_dets *formdets;
  struct struct_scr_field *field;
  FIELD **field_list;
  int nofields;
  formdets = get_curr_form ();
  flg = 0;

  debug ("Turning off all");
  for (z = 0; formdets->form_fields[z] != 0; z++)
    {
      field =
        (struct struct_scr_field
         *) (field_userptr (formdets->form_fields[z]));
      if (field == 0)
        {
          continue;
        }
      turn_field_off (formdets->form_fields[z]);
    }

  debug ("Set_fields - turned off all n=%d", n);

  va_start (ap, n);
#ifdef DEBUG
  {    debug ("Genfldlist 1");  }
#endif
  debug ("set fields 2");
  nofields = gen_field_list (&field_list, formdets, nv, &ap);

  if (nofields != nv - 1)
    {
      sprintf (errbuff,
               "Number of fields (%d) is not the same as the number of vars (%d)",
               nofields, nv);
      exitwith ("Number of fields is not the same as the number of variables");
    }

  for (a = 0; a <= nofields; a++)
    {
      turn_field_on (field_list[a]);
      if (d)
        set_init_value (field_list[a], vars[a].ptr, vars[a].dtype);

      if (flg == 0)
        {
          set_current_field (formdets->form, formdets->form_fields[z]);
          flg = 1;
        }
    }
  if (flg == 0)
    {
      exitwith ("No active field");
    }
}
#endif



/**
 *
 * @todo Describe function
 */
int
field_name_match (FIELD * f, char *s)
{
  char colname[40];
  char tabname[40];
  int aa;
  int ab;
  struct struct_scr_field *field;
  bname (s, tabname, colname);
  debug ("field_name_match : '%s' '%s'", tabname, colname);

  field = (struct struct_scr_field *) (field_userptr (f));
  if (field == 0)
    return 0;

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
 * 4GL CALL
 * @todo Describe function
 */
void
disp_fields (int n, int attr, va_list * ap)
{
  int a;
 int flg;
  struct s_form_dets *formdets;
  FIELD **field_list;
  int nofields;
  a4gl_status = 0;

  debug ("In disp_fields");
  formdets = get_curr_form ();
#ifdef DEBUG
  {    debug ("Status=%d formdets=%p", a4gl_status, formdets);  }
#endif
  if (a4gl_status != 0)
    return;
  flg = 0;

  debug (" field_list = %p", &field_list);
#ifdef DEBUG
  {    debug ("Genfldlist 2");  }
#endif
  debug ("disp_fields");
  nofields = gen_field_list (&field_list, formdets, n, ap);
  debug ("Number of fields=%d", nofields);

  for (a = nofields; a >= 0; a--)
    {
      debug ("field_list[%d]=%p", a, field_list[a]);
      debug_print_field_opts (field_list[a]);
      /* fldattr=field_opts(field_list[a]); */
      set_field_pop_attr (field_list[a], attr);
      /* rc=set_field_opts(field_list[a],fldattr); */
      debug_print_field_opts (field_list[a]);
      debug ("set_init_pop complete");
    }
  mja_wrefresh (currwin);
}



/**
 * 4GL CALL
 * @todo Describe function
 */
int
gen_field_chars (FIELD *** field_list, struct s_form_dets *formdets,
                     va_list * ap)
{
  int a;
  /* va_start (ap, formdets); */
#ifdef DEBUG
  {    debug ("Starting gen_field_chars %p %p", field_list, formdets);  }
  {    debug ("Genfldlist 3");  }
#endif
  debug ("gen_field_chars");
  a = gen_field_list (field_list, formdets, 9999, ap);
#ifdef DEBUG
  {    debug ("--------------------------------------END gen_field_chars");  }
#endif
  debug ("Gen_field_list returned %d", a);
  return a;
}

/**
 *
 * @todo Describe function
 */
int
gen_field_list (FIELD *** field_list, struct s_form_dets *formdets, int a,
                va_list * ap)
{
  int z;
  int z1;
  int ff;
  int fno;
  int metric_no;
  int mno;
  char colname[40];
  char tabname[40];
  FIELD *flist[1024];
  char *s;
  int f;
  struct struct_metrics *k;
  int attr_no;
  int srec_no;
  int cnt = 0;

#ifdef DEBUG
  {    debug ("gen_field_list - %p %p %d %p", field_list, formdets, a, ap);  }
#endif
  debug ("field_list=%p", field_list);
  debug ("Here 2");
  /*
  *field_list = calloc (a, sizeof (FIELD *));
  *field_list = calloc (1024, sizeof (FIELD *));

  dump_srec (&formdets);
  */

  for (z1 = 0; z1 <= a; z1++)
    {
      debug ("Getting first %d", z1);
      s = va_arg (*ap, char *); /* This is suspect.... */

      if (s == 0)
        break;

      debug ("Got first %s", s);

      f = (int) va_arg (*ap, int *);
      debug ("f=%d\n", f);
      if (f)
        f--;
      debug (" got field number as %d ", f);


      ff = 0;

	/* get screen record/table name */

      bname (s, tabname, colname);
      srec_no = find_srec (formdets->fileform, tabname);
      debug ("srec_no=%d", srec_no);
      if (srec_no != -1)
        {
          for (z = 0;
               z <
               formdets->fileform->records.records_val[srec_no].attribs.
               attribs_len; z++)
            {
              debug ("srec_no=%d", srec_no);
              attr_no =
                formdets->fileform->records.records_val[srec_no].attribs.
                attribs_val[z];
              debug ("attr_no=%d", attr_no);
#ifdef DEBUG
              {                debug ("Attr 1");              }
#endif
              debug ("attr_no=%d s=%s\n", attr_no, s);
              mno =
                attr_name_match (&formdets->fileform->attributes.
                                 attributes_val[attr_no], s);
              debug ("mno=%d\n", mno);

             if (mno)
                {
                  fno =
                    formdets->fileform->attributes.attributes_val[attr_no].
                    field_no;
                  debug ("Matched to field no %d", fno);
                  if (fno >= formdets->fileform->fields.fields_len)
                    {
                      exitwith ("Dubious form\n");
                      return 0;
                    }
                  metric_no =
                    formdets->fileform->fields.fields_val[fno].metric.
                    metric_val[f];
                  debug ("fno=%d f=%d mno=%d metric_no=%d\n", fno, f, mno,
                         metric_no);
                  k = &formdets->fileform->metrics.metrics_val[metric_no];
#ifdef DEBUG
                  {                    debug ("cnt=%d a=%d", cnt, a);                  }
#endif

                  if (cnt >= a)
                    {
			debug("cnt=%d a=%d",cnt,a);
                      exitwith ("Too few variables for the number of fields");
                    }
                  debug ("Setting flist[%d] to %p", cnt, k);
                  flist[cnt++] = (FIELD *) k->field;
                  debug ("Set");
                  ff = 1;
                }

            }
        }

      else
        {
          for (z = 0; z < formdets->fileform->attributes.attributes_len; z++)
            {
              attr_no = z;
              debug ("attr_no=%d", attr_no);
#ifdef DEBUG
              {                debug ("Attr 2");              }
#endif
              mno =
                attr_name_match (&formdets->fileform->attributes.
                                 attributes_val[attr_no], s);
              if (mno)
                {
                  fno =
                    formdets->fileform->attributes.attributes_val[attr_no].
                    field_no;
                  debug ("Matched to field no %d", fno);
                  metric_no =
                    formdets->fileform->fields.fields_val[fno].metric.
                    metric_val[f];
                  k = &formdets->fileform->metrics.metrics_val[metric_no];
#ifdef DEBUG
                  {                    debug ("cnt=%d a=%d", cnt, a);                  }
#endif
                  if (cnt >= a) /* was >= */
                    {
                      debug ("cnt=%d a=%d", cnt, a);
                      debug ("Too few variable");
                      exitwith ("Too few variables for the number of fields");
                    }
                  debug ("Setting flist[%d] to %p", cnt, k);
                  flist[cnt++] = (FIELD *) k->field;
                  debug ("aa");
                  ff = 1;
                }
              debug ("aa");
            }
          debug ("aa");

        }
      debug ("aa");
      if (ff == 0)
        {
          exitwith ("Field name not found");
        }

    }
  debug ("aa");
  s = va_arg (*ap, char *);
  debug ("aa");
  if (s != 0)
    debug ("Trailing fields ignored");
  debug ("aa");
  *field_list = calloc (cnt + 1, sizeof (FIELD *));
  debug ("aa");
  memcpy (*field_list, flist, sizeof (FIELD *) * (cnt + 1));
  debug ("aa");
  return cnt - 1;
}



/**
 *
 * @todo Describe function
 */
void
do_after_field (FIELD * f, struct s_screenio * sio)
{
  int a;
  char *ptr;
  struct struct_scr_field *fprop;
  FORM *mform;

  debug ("Do after field");
  debug ("do after field buffer set to '%s'", field_buffer (f, 0));

  a = find_field_no (f, sio);

  if (a == -1)
    {
      exitwith ("after field : field number not found!");
    }

  if (sio->mode != MODE_CONSTRUCT)
    {
#ifdef DEBUG
      {        debug ("   Field buffer = %s", field_buffer (f, 0));      }
#endif
      push_char (field_buffer (f, 0));
#ifdef DEBUG
      {        debug ("   Ptr=%p dtype=%d size=%d", sio->vars[a].ptr,
	  				 sio->vars[a].dtype, sio->vars[a].size);      }
#endif

      /* now check that the form corresponds to the includes */
      if (sio->currform->currentfield)
        {
          debug ("Got current field %p\n", sio->currform->currentfield);
          mform = sio->currform->form;
          fprop = (struct struct_scr_field *) (field_userptr (f));
          debug ("Got form %p", sio->currform->form);
          if (check_field_for_include
              (field_buffer (sio->currform->currentfield, 0),
               get_str_attribute (fprop, FA_S_INCLUDE), fprop->datatype) == 0)
            {
              error_box ("This value is not available");
              set_current_field (mform, sio->currform->currentfield);
            }
        }

      pop_var2 (sio->vars[a].ptr, sio->vars[a].dtype, sio->vars[a].size);

    }
  else
    {
      fprop = (struct struct_scr_field *) (field_userptr (f));
      if (fprop != 0)
        {
          if (fprop->colname != 0)
            {
              ptr =
                (char *) construct (fprop->colname, field_buffer (f, 0),
                                    (fprop->datatype == 0)
                                    || (fprop->datatype == 8));
              debug ("ptr=%s", ptr);
              if (ptr == 0)
                error_box ("Error in expression");
            }
        }
    }

}


/**
 *
 * @todo Describe function
 */
void
do_before_field (FIELD * f, struct s_screenio *sio)
{
  int a;
  char *ptr;
  debug ("Before field....");
  gui_setfocus ((long)f);
  a = find_field_no (f, sio);
  if (a == -1)
    {
      exitwith ("before field : field number not found!");
    }
  if (sio->mode != MODE_CONSTRUCT)
    {
      push_param (sio->vars[a].ptr, sio->vars[a].dtype);
      ptr = char_pop ();
      mja_set_field_buffer (f, 0, ptr);
      acl_free (ptr);
    }

}



/**
 *
 * @todo Describe function
 */
int
find_field_no (FIELD * f, struct s_screenio *sio)
{
  int a;
#ifdef DEBUG
  {    debug ("Finding field %p", f);  }
#endif
  for (a = 0; a <= sio->nfields; a++)
    {
#ifdef DEBUG
      {        debug ("Checking against %p", sio->field_list[a]);      }
#endif

      if (sio->field_list[a] == f)
        return a;

    }
#ifdef DEBUG
  {    debug ("Its not there!");  }
#endif
  return -1;
}


/**
 *
 * @todo Describe function
 */
FIELD *
make_field (int frow, int fcol, int rows, int cols)
{
  FIELD *f;
  debug ("Creating new field entry y=%d x=%d rows=%d width=%d\n", frow, fcol,
         rows, cols);

  f = new_field (rows, cols, frow, fcol, 0, 0);

  if (f)
    {
      gui_mkfield (rows, cols, frow, fcol, f);
      debug ("Field created - setting attributes");
      /*set_field_attr (f); */
      field_opts_off (f, O_ACTIVE);
      field_opts_off (f, O_EDIT);
    }
  else
    {
      exitwith ("Unable to create field");
      return 0;
    }

  return (f);
}


/**
 *
 * @todo Describe function
 */
void
dump_fields (FIELD * fields[])
{
  int a = 0;
  debug ("Dumping fields");
  return;
  while (fields[a] != 0)
    {
      debug ("Field %d %p (%d,%d) (%s)\n", a, fields[a], fields[a]->frow,
             fields[a]->fcol, fields[a]->buf);
      a++;
    }
}


/**
 *
 * @todo Describe function
 */
void
set_field_pop_attr (FIELD * field, int attr)
{
  char *ff;
  struct struct_scr_field *f;
  struct s_form_dets *fff;
  int a;
  long oopt;
  ff = new_string (get_field_width (field));
  pop_char (ff, get_field_width (field));
  debug ("set_init_pop_attr : display %s to field %d", ff, attr);
  f = (struct struct_scr_field *) (field_userptr (field));

  if (has_bool_attribute (f, FA_B_REVERSE))
    a = 1;
  else
    a = 0;

  debug ("f->do_reverse=%d attr=%d", a, attr);

/*
  if (attr)
    {
      if (f->do_reverse)
        f->do_reverse = 0;
      else
        f->do_reverse = 1;
    }
  else
    {
      if (f->do_reverse)
        f->do_reverse = 1;
      else
        f->do_reverse = 0;
    }
*/

  debug ("set f->do_reverse to %d ", f->do_reverse);
  oopt = field_opts (field);
  set_field_attr (field);
  debug ("set field attr");
  fff = get_curr_form ();
  debug ("set field");
  mja_set_field_buffer (field, 0, ff);
  debug ("set field buffer");

  f->do_reverse = a;
  debug ("done ");
  set_field_opts (field, oopt);
}



/**
 *
 * @todo Describe function
 */
void
set_init_pop_attr (FIELD * field, int attr)
{
  char *ff;
  struct struct_scr_field *f;
  struct s_form_dets *fff;
  int a;
  ff = new_string (get_field_width (field));
  pop_char (ff, get_field_width (field));

  debug ("set_init_pop_attr : display %s to field %d", ff, attr);

  f = (struct struct_scr_field *) (field_userptr (field));
  assert (f != 0);
  debug ("f=%p", f);

  a = f->do_reverse;
  debug ("f->reverse=%d attr=%d", f->do_reverse, attr);

  if (attr)
    {
      if (f->do_reverse)
        f->do_reverse = 0;
      else
        f->do_reverse = 1;
    }
  else
    {
      if (f->do_reverse)
        f->do_reverse = 1;
      else
        f->do_reverse = 0;
    }
  debug ("set f->do_reverse to %d ", f->do_reverse);
  set_field_attr (field);
  debug ("set field attr");
  fff = get_curr_form ();
  debug ("got curr form");
  set_current_field (fff->form, field);
  debug ("set field");
  mja_set_field_buffer (field, 0, ff);
  debug ("set field buffer");

  f->do_reverse = a;
  debug ("done ");

}




#ifdef NOLONGERUSED
/**
 *
 * @todo Describe function
 */
void
iarr_arr_fields (int n, int fonly, int attr, ...)
{
  int a;
  va_list ap;
  int flg;
  struct s_form_dets *formdets;
  FIELD **field_list;
  int nofields;
  

  debug ("In disp_fields");
  formdets = get_curr_form ();
  flg = 0;
  va_start (ap, attr);
  debug (" field_list = %p", &field_list);
#ifdef DEBUG
  {    debug ("Genfldlist 5");  }
#endif
  nofields = gen_field_list (&field_list, formdets, n, &ap);
  if (fonly && nofields >= 0)
    nofields = 0;
  debug ("Number of fields=%d", nofields);
  if (nofields >= 0)
    {
      for (a = 0; a <= nofields; a++)
        {
          debug ("field_list[%d]=%p", a, field_list[a]);
          set_init_pop_attr (field_list[a], attr);
          debug ("set_init_pop complete");
        }
    }
}
#endif




/**
 *
 * @todo Describe function
 */
void
disp_arr_fields (int n, int fonly, int attr, ...)
{
  int a;
  va_list ap;
  int flg;
  struct s_form_dets *formdets;
  FIELD **field_list;
  int nofields;
  debug ("In disp_fields");
  formdets = get_curr_form ();
  flg = 0;



  va_start (ap, attr);
  debug (" field_list = %p", &field_list);
#ifdef DEBUG
  {    debug ("Genfldlist 5");  }
#endif
  debug ("disp_arr_fields");
  nofields = gen_field_list (&field_list, formdets, n, &ap);
  if (fonly && nofields >= 0)
    nofields = 0;
  debug ("Number of fields=%d", nofields);
  if (nofields >= 0)
    {
      for (a = 0; a <= nofields; a++)
        {
          debug ("field_list[%d]=%p", a, field_list[a]);
          set_init_pop_attr (field_list[a], attr);
          debug ("set_init_pop complete");
        }
    }
}

/**
 *
 * @todo Describe function
 */
void
set_arr_fields (int n, int attr, ...)
{
  int a;
  va_list ap;
  int flg;
  struct s_form_dets *fff;
  struct s_form_dets *formdets;
  FIELD **field_list;
  int nofields;

  return;   /* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

  debug ("In disp_fields");
  formdets = get_curr_form ();
  flg = 0;

  va_start (ap, attr);
  debug (" field_list = %p", &field_list);
#ifdef DEBUG
  {    debug ("Genfldlist 6");  }
#endif
  debug ("set_arr_fields");
  nofields = gen_field_list (&field_list, formdets, n, &ap);
  debug ("Number of fields=%d", nofields);
  for (a = nofields; a >= 0; a--)
    {
      debug ("field_list[%d]=%p", field_list[a]);
      fff = get_curr_form ();
      set_current_field (fff->form, field_list[a]);
      debug ("set_init_pop complete");
    }
  set_current_field (fff->form, field_list[nofields]);
}


/**
 *
 * @todo Describe function
 */
int
form_field_constr (struct s_screenio *sio, int m)
{
  char buff[80];
  char buff2[80];
  FORM *mform;
  int x, y;
  int flg = 0;
  struct s_form_dets *form;
  struct struct_scr_field *fprop;
  mform = sio->currform->form;
  form = sio->currform;

  if (m)
    {
      form->currentfield = 0;
      form->currentmetrics = 0;
      return 0;
    }


  if (form->currentfield != current_field (mform))
    {
      /* fprop = 0; */
      if (form->currentfield != 0
          && (field_userptr (form->currentfield) != 0))
        {
          fprop =
            (struct struct_scr_field *) (field_userptr (form->currentfield));
          if (fprop != 0)
            {
              if ((fprop->datatype != (DTYPE_CHAR & DTYPE_MASK))
                  && (field_status (form->currentfield)))
                {
                  strcpy (buff, field_buffer (form->currentfield, 0));
                  strcpy (buff2, buff);
                  debug ("CHeckit here");
                  getsyx (y, x);
                }
            }
        }
    }

  if (form->currentfield != current_field (mform))
    {
      fprop =
        (struct struct_scr_field *) (field_userptr (current_field (mform)));
      debug ("Moving to %s", fprop->colname);
      if (fprop != 0)
        {
          push_long ((long)current_field (mform));
          push_char (fprop->colname);
        }
      else
        {
          push_long (0);
          push_char ("THIS FIELD IS AT THE START");
        }

      fprop =
        (struct struct_scr_field *) (field_userptr (form->currentfield));
      if (fprop != 0)
        {
          if (fprop->colname != 0)
            {
              debug ("Moving from %s", fprop->colname);
            }
          else
            {
              debug ("Blank colname");
            }
        }
      if (fprop != 0)
        {
          do_after_field (form->currentfield, sio);
          push_long ((long)form->currentfield);
          push_char (fprop->colname);
        }
      else
        {
          push_long (0);
          push_char ("THIS FIELD IS AT THE START");
        }
      flg = -1;
    }
  debug ("Setting currentfield entry on form...");
  form->currentfield = current_field (mform);


  fprop = (struct struct_scr_field *) (field_userptr (form->currentfield));
  if (fprop != 0)
    comments (fprop);

  pos_form_cursor (mform);
  debug_print_stack ();

  return flg;
}


/**
 *
 * @todo Describe function
 */
void
mja_set_field_buffer (FIELD * field, int nbuff, char *buff)
{
  char buff2[1024];
  int a;
  int b;
  int errno;
  b = get_field_width (field);
  strcpy (buff2, buff);
  a = strlen (buff2);
  b = get_field_width (field);
  debug ("mja_set_field_buffer buff='%s' buff2='%s' (%d,%d) ", buff, buff2, a,
         b);
  gui_setbuff (field, buff);
  if (a < get_field_width (field))
    {
      debug ("Adding padding");
      pad_string (buff2, get_field_width (field));
    }
  else
    {
      debug ("No padding required '%s'", buff);
    }

  errno = set_field_buffer (field, nbuff, buff2);
  debug ("Setting %p %d to %s (%d)", field, nbuff, buff2, errno);
  debug ("field buffer set to '%s'", field_buffer (field, 0));
  debug ("Currwin=%p", currwin);
  pos_form_cursor (field->form);
  if (currwin > (WINDOW *) 1)
    {
      touchwin (currwin);
#ifdef DEBUG
      {        debug ("Touched Window");      }
#endif
    }
  else
    {
#ifdef DEBUG
      {        debug ("No window to Touch");      }
#endif
    }
#ifdef DEBUG
  {    debug ("Refreshed Window");  }
#endif
}



/**
 * 4GL CALL
 * @todo Describe function
 */
int
push_constr (struct s_screenio *s)
{
  struct struct_scr_field *fprop;
  FIELD *f;
  int a;
  char *ptr;
  int flg = 0;
  int_form_driver (s->currform->form, REQ_FIRST_PAGE);

  debug ("Push_constr");
  debug ("nfields=%d", s->nfields);
  debug ("s-field_list[0]=%p", s->field_list[0]);

  for (a = 0; a <= s->nfields; a++)
    {
      debug ("Looping a=%d\n", a);
      f = s->field_list[a];
      debug ("f=%p", f);
      fprop = (struct struct_scr_field *) (field_userptr (f));
      debug ("fprop=%p", fprop);
      if (fprop != 0)
        {
          debug ("getting ptr", fprop);
          debug ("fprop->colname=%s fprop->datatype=%x", fprop->colname,
                 (fprop->datatype) & 0xffff);
          ptr =
            (char *) construct (fprop->colname, field_buffer (f, 0),
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
 *
 * @todo Describe function
 */
FIELD *
scan_for_field (char *s)
{
  struct s_form_dets *f;
  FIELD *fld;
  int a;
  f = get_curr_form ();
  if (f == 0)
    return 0;

  for (a = 0; (fld = (f->form_fields[a])); a++)
    {
      debug ("Calling field_name_match with %p", fld);
      if (field_name_match (fld, s))
        {
          debug ("Got a match - returning %p", fld);
          return fld;
        }
    }
  return 0;
}


/**
 *
 * @todo Describe function
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
int
get_curr_infield(void)
{
        return inp_current_field;
}

/**
 * 4GL CALL
 * @todo Describe function
 */
int
fgl_infield (char *s, int a)
{
  struct s_form_dets *f;
  debug ("fgl_infield - looking for %s", s);


  f = get_curr_form ();

  debug ("Current field = %p\n", current_field (f->form));
  debug ("Current field = %p\n", f->currentfield);

  /* if (scan_for_field (s) == current_field (f->form)) { */
  if (scan_for_field (s) == (FIELD *)inp_current_field)
    {
      debug ("I'm in %s\n", s);
      return 1;
    }

  debug ("I'm not in %s\n", s);
  return 0;
}

/**
 * 4GL CALL
 * @todo Describe function
 */
int
fgl_getfldbuf (char *s, int a)
{
  struct s_form_dets *f;
  FIELD *fld;


  debug ("In fgl_getfldbuf");
  f = get_curr_form ();
  debug ("fld_getfldbuf    f=%p", f);

  if (f == 0)
    {
      debug ("No current form...");
      exitwith ("No current form");
      return -1;
    }
  fld = (FIELD *) scan_for_field (s);
  if (fld == 0)
    {
      exitwith ("Field name not found on form");
      return -1;
    }
  push_char (field_buffer (fld, 0));
  return 1;
}




/**
 *
 * @todo Describe function
 */
int
key_prompt (int a, FORM * mform, struct s_prompt * prompt)
{
  FIELD *f;
  f = current_field (mform);

  m_lastkey = a;
  debug ("In proc_key_prompt.... for %d", a);
  switch (a)
    {
    case 18:
      mja_wrefresh (stdscr);
      mja_wrefresh (currwin);
      mja_refresh ();
      break;
    case -1:

    case 27:
      return 0;

    case 26:
      return 0;

    case 127:
    case 8:
    case KEY_DC:
    case KEY_DL:
    case KEY_BACKSPACE:
      debug ("Req del prev");
      if (get_curr_field_col (mform))
        {
          int_form_driver (mform, REQ_DEL_PREV);
          debug ("Done...");
        }
      return 0;

    case 24:
      int_form_driver (mform, REQ_DEL_CHAR);
      return 0;

    case '	':
    case KEY_ENTER:
    case 13:
    case 10:
    case KEY_DOWN:
#ifdef DEBUG
      {        debug ("Next field in a prompt - they must mean enter");      }
#endif
      return 10;

    case KEY_LEFT:
      int_form_driver (mform, REQ_PREV_CHAR);
      return 0;

    case KEY_RIGHT:
      int_form_driver (mform, REQ_NEXT_CHAR);
      return 0;

    case 4:
      int_form_driver (mform, REQ_CLR_FIELD);
      return 0;
    }

  /* mja_refresh (); */

  if (a == key_val ("HELP"))
    {
      show_help (prompt->h);
      a = 0;
    }

  debug ("Returning %d from proc_key_prompt\n", a);
  return a;
}


/**
 *
 * @todo Describe function
 */
void
reset_delims (struct s_form_dets * formdets, char *delims)
{
  int a;
  char sbuff0[2];
  char sbuff1[2];
  sbuff0[0] = delims[0];
  sbuff0[1] = 0;
  sbuff1[0] = delims[1];
  sbuff1[1] = 0;

  for (a = 0; a < formdets->fileform->metrics.metrics_len; a++)
    {
      mja_set_field_buffer ((FIELD *) formdets->fileform->metrics.
                            metrics_val[a].dlm1, 0, sbuff0);
      mja_set_field_buffer ((FIELD *) formdets->fileform->metrics.
                            metrics_val[a].dlm2, 0, sbuff1);
    }
}


/**
 *
 * @todo Describe function
 */
void
debug_print_field_opts (FIELD * a)
{
  long z;
  char str[2048] = "";
  z = field_opts (a);
  if (z & O_VISIBLE)
    strcat (str, " O_VISIBLE");
  if (z & O_ACTIVE)
    strcat (str, " O_ACTIVE");
  if (z & O_PUBLIC)
    strcat (str, " O_PUBLIC");
  if (z & O_EDIT)
    strcat (str, " O_EDIT");
  if (z & O_WRAP)
    strcat (str, " O_WRAP");
  if (z & O_BLANK)
    strcat (str, " O_BLANK");
  if (z & O_AUTOSKIP)
    strcat (str, " O_AUTOSKIP");
  if (z & O_NULLOK)
    strcat (str, " O_NULLOK");
  if (z & O_STATIC)
    strcat (str, " O_STATIC");
  if (z & O_PASSOK)
    strcat (str, " O_PASSOK");
  debug ("Field %p attribs= %s:", a, str);
}



/**
 *
 * @todo Describe function
 */
int
page_for_field (struct s_screenio * s, FIELD * f)
{
  int a;
  int metric_no;
  for (a = 0; s->field_list[a]; a++)
    {
      if (f == s->field_list[a])
        {
          metric_no = get_metric_no (s->currform, s->field_list[a]);
          debug ("FIELD LIST : %p %d", s->field_list[a],
                 s->currform->fileform->metrics.metrics_val[metric_no].scr);
          return s->currform->fileform->metrics.metrics_val[metric_no].scr;
        }
    }
  return 0;
}

/**
 *
 * @todo Describe function
 */
int
page_for_cfield (struct s_screenio * s)
{
  FIELD *f;
  int a;
  int metric_no;
  f = current_field (s->currform->form);
  for (a = 0; s->field_list[a]; a++)
    {
      if (f == s->field_list[a])
        {
          metric_no = get_metric_no (s->currform, s->field_list[a]);
          debug ("FIELD LIST : %p %d", s->field_list[a],
                 s->currform->fileform->metrics.metrics_val[metric_no].scr);
          return s->currform->fileform->metrics.metrics_val[metric_no].scr;
        }
    }
  return 0;
}


/**
 *
 * @todo Describe function
 */
int
page_for_nfield (struct s_screenio * s)
{
  FIELD *f;
  int a;
  int metric_no;
  debug ("In page_for_nfield %p");
  f = current_field (s->currform->form);
  debug ("Current field %p", f);

  for (a = 0; s->field_list[a]; a++)
    {
      if (f == s->field_list[a])
        {
          a++;
          if (s->field_list[a] == 0)
            a = 0;
          metric_no = get_metric_no (s->currform, s->field_list[a]);
          debug ("Metric_no=%d", metric_no);
          debug ("FIELD LIST : %p %d", s->field_list[a],
                 s->currform->fileform->metrics.metrics_val[metric_no].scr);
          return s->currform->fileform->metrics.metrics_val[metric_no].scr;
        }
    }
  return 0;
}

/**
 *
 * @todo Describe function
 */
int
page_for_pfield (struct s_screenio * s)
{
  FIELD *f;
  int a, b;
  int metric_no;
  f = current_field (s->currform->form);
  debug ("page for previous FIELD f=%p", f);
  for (a = 0; s->field_list[a]; a++)
    {
      if (f == s->field_list[a])
        {
          b = a - 1;
          if (a <= 0)
            {
              debug ("field is at end of list");
              for (b = 0; s->field_list[b + 1]; b++);
              debug ("setting a to %d", a);
            }
          debug ("b=%d", b);
          metric_no = get_metric_no (s->currform, s->field_list[b]);
          debug ("FIELD LIST : %d %p %d", a, s->field_list[b],
                 s->currform->fileform->metrics.metrics_val[metric_no].scr);
          return s->currform->fileform->metrics.metrics_val[metric_no].scr;
        }
    }
  return 0;
}



/**
 *
 * @todo Describe function
 */
int
copy_field_data (struct s_form_dets * form)
{
  char buff[80] = "";
  char buff2[80] = "";
  FORM *mform;
  int x, y;
  struct struct_scr_field *fprop;
  mform = form->form;
  debug ("form->currentfield=%p", form->currentfield);
  if (form->currentfield != 0)
    if (field_userptr (form->currentfield) != 0)
      {
        debug ("Is a proper field");
        fprop =
          (struct struct_scr_field *) (field_userptr (form->currentfield));
        debug ("fprop=%p", fprop);
        if (fprop != 0)
          {
            debug ("check Datatype ");
            if (((fprop->datatype != DTYPE_CHAR) & (DTYPE_MASK))
                && (field_status (form->currentfield)))
              {
                debug ("modify size dtype");
                debug ("modfy size for metric %d",
                       get_metric_for (form, form->currentfield));
                modify_size (&buff[4],
                             form->fileform->metrics.
                             metrics_val[get_metric_for
                                         (form, form->currentfield)].w);
                debug ("modfy size done -> '%s'", &buff[4]);

                strcpy (&buff[4], field_buffer (form->currentfield, 0));
                debug ("copy 1");
                strcpy (buff2, &buff[4]);
                debug ("copy 2");
                debug ("trim buff");
                trim (buff2);
                getsyx (y, x);

                debug ("CHange y=%d, x=%d", y, x);
                debug ("stack manip buff2='%s'", buff2);
                if (strlen (buff2) > 0)
                  {
#ifdef DEBUG
                    {                      debug ("Pushing param %p");                    }
#endif
                    push_param (buff2, DTYPE_CHAR);
                    if (pop_param
                        (buff, fprop->datatype,
                         get_field_width (form->currentfield)))
                      {
#ifdef DEBUG
                        {                          debug ("Pushing param %p %d", buff,
						                                 fprop->datatype);                        }
#endif
                        push_param (buff, fprop->datatype);
                        if (has_str_attribute (fprop, FA_S_FORMAT))
                          {
                            push_char (get_str_attribute
                                       (fprop, FA_S_FORMAT));
                            //push_param ("using", FUNCTION_OP);
                            pushop (OP_USING);
                          }
                        pop_param (buff, DTYPE_CHAR,
                                   get_field_width (form->currentfield));
                        mja_set_field_buffer (form->currentfield, 0, buff);
                      }
                    else
                      {
			//push_char(acl_getenv("FIELD_ERROR_MSG"));
			//display_error(1,0);
                        error_box (acl_getenv ("FIELD_ERROR_MSG"));
                        mja_set_field_buffer (form->currentfield, 0, " ");
                        set_current_field (mform, form->currentfield);
                        return 0;
                      }
                  }
              }
          }
      }
  return 1;
}


/**
 *
 * @todo Describe function
 */
int
get_curr_field_col (FORM * mform)
{
  return mform->curcol;
}


/**
 *
 * @todo Describe function
 */
void
int_form_driver (FORM * form, int a)
{
  int field_pos;
  FIELD *f;
  char buff[1024];
  char buff2[1024];
  field_pos = get_curr_field_col (form);
  f = current_field (form);

  if (f)
    {
      strcpy (buff, field_buffer (f, 0));
    }
  else
    {
      strcpy (buff, "");
    }

  debug ("Calling form_driver with %d for form %p", a, form);

  form_driver (form, a);

  if (f != current_field (form))
    {
      debug ("Resetting focus");
      f = current_field (form);
      gui_setfocus ((long)f);
    }

  if (field_pos != get_curr_field_col (form))
    {
      debug ("Resetting position");
      field_pos = get_curr_field_col (form);
      gui_setposition (field_pos);
    }

  if (f)
    {
      strcpy (buff2, field_buffer (f, 0));
    }
  else
    {
      strcpy (buff2, "");
    }

  if (strcmp (buff, buff2) != 0)
    {
      gui_setbuff (f, buff2);
    }

}


/**
 * 4GL CALL
 * @todo Describe function
 */
void
clr_form (int to_default)
{
  struct s_form_dets *formdets;
  int a;
  int metric_no;
  struct struct_metrics *k;
  FIELD *f;
  int fno;
  int rn;

  A4GLSQL_set_status (0, 0);

  formdets = get_curr_form ();

	/* Go through each field */
  for (a = 0; a < formdets->fileform->attributes.attributes_len; a++)
    {
      fno = formdets->fileform->attributes.attributes_val[a].field_no;

	/* And through each metric for this field */
      for (rn = 0;
           rn < formdets->fileform->fields.fields_val[fno].metric.metric_len;
           rn++)
        {
          metric_no =
            formdets->fileform->fields.fields_val[fno].metric.metric_val[rn];
          k = &formdets->fileform->metrics.metrics_val[metric_no];
          f = (FIELD *) k->field;
          if (!to_default)
            mja_set_field_buffer (f, 0, "");
          else
            {
              struct struct_scr_field *prop;
              prop = (struct struct_scr_field *) field_userptr (f);
              mja_set_field_buffer (f, 0,
                                    replace_sql_var (strip_quotes
                                                     (get_str_attribute
                                                      (prop, FA_S_DEFAULT))));
            }
        }

    }

}


/**
 * 4GL CALL
 * @todo Describe function
 */
void
disp_form_fields (int n, int attr, char *formname,...)
{
        exitwith("Not implemented for TUI mode");
}


/**
 *
 * @todo Describe function
 */
int
curr_metric_is_last (void)
{
  struct s_form_dets *form;
  int a;
  form = get_curr_form ();
  a = get_curr_metric (form);

  if (a == -1)
    {
      return 0;
      exitwith ("No valid metric....");
    }

  //debug("pos_code : %d %d",form->fileform->metrics.metrics_val[a].pos_code , POS_LAST);


  if (form->fileform->metrics.metrics_val[a].pos_code & POS_LAST)
    {
      return 1;
    }



  return 0;
}


/**
 *
 * @todo Describe function
 */
int
curr_metric_is_first (void)
{
  struct s_form_dets *form;
  int a;
  form = get_curr_form ();
  a = get_curr_metric (form);
  if (a == -1)
    {
      return 0;
      exitwith ("No valid metric....");
    }
  if (form->fileform->metrics.metrics_val[a].pos_code & POS_FIRST)
    return 1;
  return 0;
}


/**
 *
 * @todo Describe function
 */
int
curr_metric_is_veryfirst (void)
{
  struct s_form_dets *form;
  int a;
  form = get_curr_form ();
  a = get_curr_metric (form);
  if (a == -1)
    {
      return 0;
      error_box ("No valid metric....");
      exit (0);
    }
  if (form->fileform->metrics.metrics_val[a].pos_code & POS_VERY_FIRST)
    return 1;
  return 0;
}



/**
 *
 * @todo Describe function
 */
int
curr_metric_is_verylast (void)
{
  struct s_form_dets *form;
  int a;
  form = get_curr_form ();
  a = get_curr_metric (form);
  if (a == -1)
    {
      return 0;
      error_box ("No valid metric....");
      exit (0);
    }

  if (form->fileform->metrics.metrics_val[a].pos_code & POS_VERY_LAST)
    return 1;

  return 0;
}


/**
 *
 * @todo Describe function
 */
int
aclfgl_set_page(int n)
{
int b;
struct s_form_dets *f;
	b=pop_int();
	f=get_curr_form();
	set_form_page(f->form,b);
	refresh();
	return 0;
}

/**
 *
 * @todo Describe function
 */
int
aclfgl_get_page(int n)
{
struct s_form_dets *f;
	f=get_curr_form();
	push_int(form_page(f->form));
	return 1;
}

/* ================================ EOF ============================== */

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
# $Id: ioform.c,v 1.36 2003-06-18 09:38:23 mikeaubury Exp $
#*/

/**
 * @file
 *
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


#include "a4gl_lib_ui_tui_int.h"
#include <ctype.h>

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

extern WINDOW *currwin;
int m_lastkey = 0;
int tab_cnt = 0;
int srec_cnt = 0;
extern int errno;
char delimiters[4];

int lastc = 0;
int nline;
int fline;
int ncol;
char dbname[64];
long inp_current_field = 0;
//int do_input_nowrap = 0;


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/


/** @todo Take this prototype definition for a header file */
int A4GL_chkwin (void);
void A4GL_bomb_out (void);
extern char *A4GL_replace_sql_var (char *s);
char *read_string_dup (FILE * ofile);
struct s_form_dets *A4GL_getfromform (FORM * f);
char *A4GL_string_width (char *a);
WINDOW *A4GL_create_window (char *name, int x, int y, int w, int h,
			    int border);
void A4GL_set_field_colour_attr (FIELD * field, int do_reverse, int colour);
int
A4GL_curr_metric_is_used_last_s_screenio (struct s_screenio *s, FIELD * f);

void A4GL_disp_form_fields_ap (int n, int attr, char *formname, va_list * ap);
int display_fields (FORM * mform, int n, ...);
extern char *A4GL_find_attribute (struct s_form_dets *f, int field_no);
void A4GL_debug_print_field_opts (FIELD * a);
void A4GL_mja_set_field_buffer (FIELD * field, int nbuff, char *buff);
void A4GL_mja_set_field_buffer_contrl (FIELD * field, int nbuff, int ch);
void A4GL_set_field_pop_attr (FIELD * field, int attr,int cmd_type);
int A4GL_find_field_no (FIELD * f, struct s_screenio *sio);
void A4GL_do_after_field (FIELD * f, struct s_screenio *sio);
int A4GL_get_metric_for (struct s_form_dets *form, FIELD * f);
int A4GL_get_field_width (FIELD * f);
int A4GL_page_for_nfield (struct s_screenio *s);
int A4GL_proc_key (int a, FORM * mform, struct s_screenio *s);
int A4GL_form_field_chk (struct s_screenio *sio, int m);
int A4GL_form_field_constr (struct s_screenio *sio, int m);
int A4GL_get_curr_metric (struct s_form_dets *form);
int A4GL_page_for_pfield (struct s_screenio *s);
void A4GL_field_autonext (FIELD * f);
void A4GL_field_dynamic (FIELD * f);
void A4GL_field_invisible (FIELD * f);
void A4GL_field_noentry (FIELD * f);
void A4GL_set_field_attr (FIELD * field);
int A4GL_req_field_input (struct s_screenio *s, ...);
int A4GL_req_field_input_array (struct s_inp_arr *s, ...);
void A4GL_set_init_value (FIELD * f, void *ptr, int dtype);
int A4GL_get_metric_no (struct s_form_dets *form, FIELD * f);
int A4GL_turn_field_off (FIELD * f);
void A4GL_turn_field_on (FIELD * f);
void A4GL_turn_field_on2 (FIELD * f, int a);
void A4GL_set_init_pop (FIELD * f);
int A4GL_field_name_match (FIELD * f, char *s);
void A4GL_do_before_field (FIELD * f, struct s_screenio *sio);
void A4GL_dump_fields (FIELD * fields[]);
void A4GL_set_init_pop_attr (FIELD * field, int attr);
FIELD *A4GL_scan_for_field (char *s);
int A4GL_get_curr_infield (void);
int A4GL_key_prompt (int a, FORM * mform, struct s_prompt *prompt);
void A4GL_reset_delims (struct s_form_dets *formdets, char *delims);
int A4GL_page_for_field (struct s_screenio *s, FIELD * f);
int A4GL_page_for_cfield (struct s_screenio *s);
int A4GL_curr_metric_is_last (void);
int A4GL_curr_metric_is_first (void);
int A4GL_curr_metric_is_veryfirst (void);
int A4GL_curr_metric_is_verylast (void);
int A4GL_curses_to_aubit (int a);
void A4GL_set_field_attr_with_attr (FIELD * field, int attr);
int A4GL_gen_field_chars_ap (FIELD *** field_list,
			     struct s_form_dets *formdets, va_list * ap);

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
A4GL_getfromform (FORM * f)
{
  return f->usrptr;
}


/**
 *
 * @todo Describe function
 */
FIELD *
A4GL_make_label (int frow, int fcol, char *label)
{
  FIELD *f;
  int l;
  int is_graphics=0;
  l = strlen (label);
  A4GL_debug ("A4GL_make_label : '%s'", label);
  
  if (l==2 && label[0]=='\n') {
	A4GL_debug("Making graphic character %c @ frow=%d fcol=%d\n",label[1],frow,fcol);
  	f = new_field (1, 1, frow, fcol, 0, 0);
  } else {
	A4GL_debug("Making normal label %s @ frow=%d fcol=%d\n",label,frow,fcol);
  	f = new_field (1, l, frow, fcol, 0, 0);
  }

  if (f==0) {
	A4GL_exitwith("Unable to create field");
	return 0;
  }

  if (l==2 && label[0]=='\n') {
	is_graphics=1;

	if (A4GL_isyes(acl_getenv("SIMPLE_GRAPHICS")))  {
		switch (label[1]) {
			case 'p': A4GL_mja_set_field_buffer_contrl (f, 0, '+'); break;
			case 'q': A4GL_mja_set_field_buffer_contrl (f, 0, '+'); break;
			case 'b': A4GL_mja_set_field_buffer_contrl (f, 0, '+'); break;
			case 'd': A4GL_mja_set_field_buffer_contrl (f, 0, '+'); break;
			case '-': A4GL_mja_set_field_buffer_contrl (f, 0, '-'); break;
			case '|': A4GL_mja_set_field_buffer_contrl (f, 0, '|'); break;
			default : A4GL_debug("Unknown graphic : %c",label[1]); is_graphics=0;
		}
	} else {
		if (!A4GL_isyes(acl_getenv("EXTENDED_GRAPHICS")))  {
			set_field_back(f, A_ALTCHARSET);
			switch(label[1]) {
				case 'p': A4GL_mja_set_field_buffer_contrl (f, 0, ACS_ULCORNER&0xff); break;
				case 'q': A4GL_mja_set_field_buffer_contrl (f, 0, ACS_URCORNER&0xff); break;
				case 'b': A4GL_mja_set_field_buffer_contrl (f, 0, ACS_LLCORNER&0xff); break;
				case 'd': A4GL_mja_set_field_buffer_contrl (f, 0, ACS_LRCORNER&0xff); break;
				case '-': A4GL_mja_set_field_buffer_contrl (f, 0, ACS_HLINE&0xff); break;
				case '|': A4GL_mja_set_field_buffer_contrl (f, 0, ACS_VLINE&0xff); break;
				default : A4GL_debug("Unknown graphic : %c",label[1]); is_graphics=0;
			}
		} else {
			set_field_back(f, A_ALTCHARSET);
			A4GL_debug("Extended graphics : %c",label[1]);
			switch(label[1]) {
				case 'p': A4GL_mja_set_field_buffer_contrl (f, 0, ACS_ULCORNER&0xff); break;
				case 'q': A4GL_mja_set_field_buffer_contrl (f, 0, ACS_URCORNER&0xff); break;
				case 'b': A4GL_mja_set_field_buffer_contrl (f, 0, ACS_LLCORNER&0xff); break;
				case 'd': A4GL_mja_set_field_buffer_contrl (f, 0, ACS_LRCORNER&0xff); break;
				case '-': A4GL_mja_set_field_buffer_contrl (f, 0, ACS_HLINE&0xff); break;
				case '|': A4GL_mja_set_field_buffer_contrl (f, 0, ACS_VLINE&0xff); break;

				case '>': A4GL_mja_set_field_buffer_contrl (f, 0, ACS_LTEE&0xff); break;
				case '<': A4GL_mja_set_field_buffer_contrl (f, 0, ACS_RTEE&0xff); break;
				case '^': A4GL_mja_set_field_buffer_contrl (f, 0, ACS_BTEE&0xff); break;
				case 'v': 
				case 'V': A4GL_mja_set_field_buffer_contrl (f, 0, ACS_TTEE&0xff); break;
				case '+': A4GL_mja_set_field_buffer_contrl (f, 0, ACS_PLUS&0xff); break;
				default : A4GL_debug("Unknown graphic : %c",label[1]); is_graphics=0;
			}
		}
	}
	if (is_graphics) {
        	set_field_opts (f, field_opts (f) & ~O_ACTIVE);
		return f;
	} else {
		label[0]=label[1];
		label[1]=label[0];
	}
  }


  A4GL_gui_mklabel (1, strlen (label), frow, fcol, label);

  if (f)
    {
      A4GL_mja_set_field_buffer (f, 0, label);
      set_field_opts (f, field_opts (f) & ~O_ACTIVE);
    }
  else
    {
#ifdef DEBUG
      {
	A4GL_debug ("FIeld not created!!!");
      }
#endif
    }
  return (f);
}



/**
 *  @todo Validate the calls to A4GL_make_label that alocates space to a FIELD
 *  struct and assigns the pointer to integers.
 */
int
A4GL_read_metrics (struct s_form_dets *formdets)
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
  A4GL_debug ("metrics len=%d", n);
  for (a = 0; a < n; a++)
    {
      formdets->fileform->metrics.metrics_val[a].pos_code = 0;
      A4GL_debug ("checking label\n");


      if (strlen (formdets->fileform->metrics.metrics_val[a].label) != 0)
	{
	  formdets->fileform->metrics.metrics_val[a].field =
	    (int) A4GL_make_label (formdets->fileform->metrics.metrics_val[a].
				   y,
				   formdets->fileform->metrics.metrics_val[a].
				   x,
				   formdets->fileform->metrics.metrics_val[a].
				   label);
	  formdets->form_fields[cnt++] =
	    (FIELD *) formdets->fileform->metrics.metrics_val[a].field;
	  formdets->form_fields[cnt] = 0;
	}
      else
	{
	  A4GL_debug ("Making field");
	  formdets->fileform->metrics.metrics_val[a].field =
	    (int) A4GL_make_field (formdets->fileform->metrics.metrics_val[a].
				   y,
				   formdets->fileform->metrics.metrics_val[a].
				   x, 1,
				   formdets->fileform->metrics.metrics_val[a].
				   w);
	  formdets->form_fields[cnt++] =
	    (FIELD *) formdets->fileform->metrics.metrics_val[a].field;
	  formdets->form_fields[cnt] = 0;
	  formdets->fileform->metrics.metrics_val[a].dlm1 =
	    (int) A4GL_make_label (formdets->fileform->metrics.metrics_val[a].
				   y,
				   formdets->fileform->metrics.metrics_val[a].
				   x - 1, delims[0]);
	  formdets->form_fields[cnt++] =
	    (FIELD *) formdets->fileform->metrics.metrics_val[a].dlm1;
	  formdets->fileform->metrics.metrics_val[a].dlm2 =
	    (int) A4GL_make_label (formdets->fileform->metrics.metrics_val[a].
				   y,
				   formdets->fileform->metrics.metrics_val[a].
				   x +
				   formdets->fileform->metrics.metrics_val[a].
				   w, delims[1]);
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
		POS_VERY_FIRST;
	    }
	  A4GL_debug ("LAST_FIELD2 -CHK111");
	  A4GL_debug ("LAST_FIELD1 -CHK111");
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
      A4GL_debug ("LAST_FIELD3 -CHK111 a=%d label='%s'", a,
		  formdets->fileform->metrics.metrics_val[a].label);
      if (strlen (formdets->fileform->metrics.metrics_val[a].label) == 0)
	last_field = a;
    }

  A4GL_debug ("Last_field=%d\n", last_field);
  if (last_field < 0)
    {
      A4GL_exitwith ("Internal Error");
      return 0;
    }

  formdets->fileform->metrics.metrics_val[last_field].pos_code +=
    POS_VERY_LAST;

  return 1;
}


/**
 *
 * @todo Describe function
 */
void
A4GL_default_attributes (FIELD * f, int dtype)
{
  A4GL_debug ("In def attrib f=%p", f);

  if (dtype == 0)
    set_field_opts (f, O_VISIBLE | O_ACTIVE | O_PUBLIC | O_EDIT | O_STATIC);
  else
    set_field_opts (f,
		    O_VISIBLE | O_ACTIVE | O_PUBLIC | O_EDIT | O_STATIC |
		    O_BLANK);

  A4GL_debug ("STATIC");
  set_field_fore (f, A4GL_colour_code (7));
  set_field_back (f, A4GL_colour_code (7));
}

/**
 *
 * @todo Describe function
 */
void
A4GL_field_autonext (FIELD * f)
{
  field_opts_on (f, O_AUTOSKIP);
}

/**
 *
 * @todo Describe function
 */
void
A4GL_field_dynamic (FIELD * f)
{
  field_opts_off (f, O_STATIC);
}

/**
 *
 * @todo Describe function
 */
void
A4GL_field_invisible (FIELD * f)
{
  field_opts_off (f, O_PUBLIC);
}

/**
 *
 * @todo Describe function
 */
void
A4GL_field_noentry (FIELD * f)
{
  field_opts_off (f, O_ACTIVE);
  field_opts_off (f, O_EDIT);
}

/**
 *
 * @todo Describe function
 */
void
A4GL_set_field_attr (FIELD * field)
{
  struct struct_scr_field *f;
  int bc;
  int fc;
  bc = field_back (field);
  fc = field_fore (field);

  A4GL_debug ("In set_field_attr");
  f = (struct struct_scr_field *) (field_userptr (field));
  if (f == 0)
    return;
  A4GL_debug ("Setting defs");
  A4GL_default_attributes (field, f->datatype);
  A4GL_debug ("Set defs");

  if (A4GL_has_bool_attribute (f, FA_B_AUTONEXT))
    {
      A4GL_debug ("Autoskip");
      field_opts_on (field, O_AUTOSKIP);
    }

  if (A4GL_has_bool_attribute (f, FA_B_INVISIBLE))
    {
      A4GL_debug ("Invisible");
      field_opts_off (field, O_PUBLIC);
    }

  if (f->dynamic != 0)
    {
      field_opts_off (field, O_STATIC);

      if (f->dynamic == -1)
	{
	  A4GL_debug ("Max size is lots");
	  set_max_field (field, 0);
	}
      else
	{
	  set_max_field (field, f->dynamic);
	  A4GL_debug ("Max size=%d", f->dynamic);
	}

    }

  if (A4GL_has_bool_attribute (f, FA_B_NOENTRY))
    {
      A4GL_debug ("No entry");
      field_opts_off (field, O_ACTIVE);
      field_opts_off (field, O_EDIT);
    }

  if (A4GL_has_bool_attribute (f, FA_B_REQUIRED))
    {
      field_opts_off (field, O_NULLOK);
    }

  if (A4GL_has_bool_attribute (f, FA_B_WORDWRAP))
    {
      field_opts_on (field, O_WRAP);
    }

  A4GL_set_field_colour_attr (field, f->do_reverse, f->colour);

}

void
A4GL_set_field_attr_with_attr (FIELD * field, int attr)
{
  int r;
  int nattr;
  struct struct_scr_field *f;
  f = (struct struct_scr_field *) (field_userptr (field));

  nattr=A4GL_determine_attribute(FGL_CMD_DISPLAY_CMD, attr, f);
  A4GL_debug("Passed in attribute: %x, determined attribute should be %x",attr,nattr);
  attr=nattr;

  if (attr & AUBIT_ATTR_REVERSE)
    r = 1;
  else
    r = 0;
  A4GL_debug
    ("MJA Calling A4GL_set_field_colour_attr - do_reverse=%d attr=%d", r,
     attr);
  A4GL_set_field_colour_attr (field, r, attr);
}

void
A4GL_set_field_colour_attr (FIELD * field, int do_reverse, int colour)
{
  struct struct_scr_field *f;
  f = (struct struct_scr_field *) (field_userptr (field));

  colour=colour&0xff00;

  if (do_reverse && colour == AUBIT_COLOR_WHITE)
    {
      A4GL_debug ("XX1 REVERSE");
      set_field_fore (field, A_REVERSE);
      set_field_back (field, A_REVERSE);
    }


  if (do_reverse && colour != AUBIT_COLOR_WHITE)
    {
      A4GL_debug ("XX2 REVERSE");
      set_field_back (field,
		      A4GL_decode_colour_attr_aubit (colour) | A_REVERSE);
      set_field_fore (field,
		      A4GL_decode_colour_attr_aubit (colour) | A_REVERSE);
    }

  if (do_reverse == 0 && colour != AUBIT_COLOR_WHITE)
    {
      set_field_fore (field, A4GL_decode_colour_attr_aubit (colour));
      set_field_back (field, A4GL_decode_colour_attr_aubit (colour));
    }
  if (do_reverse == 0 && colour == AUBIT_COLOR_WHITE)
    {
      set_field_fore (field, A4GL_decode_colour_attr_aubit (colour));
      set_field_back (field, A4GL_decode_colour_attr_aubit (colour));
    }

  A4GL_debug ("Returning");
}

#ifdef MOVED_TO_FORMCONTROL
/**
 *
 * @todo Describe function
 */
int
A4GL_req_field_input (struct s_screenio *s, ...)
{				/* does nothing yet... */
/* fieldname + = next - = previous */
  int a;
  FIELD **ptr;
  struct s_form_dets *sdets;
  va_list ap;
  va_start (ap, s);

  A4GL_debug ("req_field");
  a = A4GL_gen_field_list (&ptr, s->currform, 1, &ap);


  if (a >= 0)
    {
      A4GL_debug ("Found our field...\n");
    }
  else
    {
      A4GL_exitwith ("Field not found");
      return 0;
    }
  A4GL_debug ("Setting current field to %p", ptr[0]);
  sdets = s->currform;
  set_current_field (sdets->form, ptr[0]);

  pos_form_cursor (sdets->form);
  free (ptr);
  return 1;
}
#endif

/**
 *
 * @todo Describe function
 */
int
A4GL_req_field_input_array (struct s_inp_arr *s, ...)
{				/* does nothing yet... */
/* fieldname + = next - = previous */
  int a;
  FIELD **ptr;
  struct s_form_dets *sdets;
  va_list ap;
  va_start (ap, s);



  A4GL_debug ("MJAMJA req_field_input_array...");

  a = A4GL_gen_field_list (&ptr, s->currform, 1, &ap);


  if (a >= 0)
    {
      A4GL_debug ("Found our field...\n");
    }
  else
    {
      A4GL_exitwith ("Field not found");
      return 0;
    }
  A4GL_debug ("Setting current field to %p", ptr[0]);
  sdets = s->currform;
  set_current_field (sdets->form, ptr[0]);

  pos_form_cursor (sdets->form);
  free (ptr);
  return 1;
}


#ifdef MOVED_TO_FORM_CONTROL
/**
 * 4GL CALL
 * @todo Describe function
 */
int
A4GL_form_loop (void *vs)
{
  struct s_form_dets *form;
  int a;
  struct s_screenio *s;
  //int int_form_driver_ret = 0;
  struct struct_scr_field *fprop;
  struct struct_metrics *metrics;
  FORM *mform;
  s = vs;
  form = s->currform;
  A4GL_set_abort (0);
  A4GL_debug ("form_loop0..  currentfield=%p status = %d", form->currentfield,
	      field_status (form->currentfield));

  if (form != A4GL_get_curr_form ())
    {
      A4GL_debug ("form=%p curr_form=%p", form, A4GL_get_curr_form ());
      A4GL_exitwith ("Input form is not current");
      return 0;
    }

  mform = form->form;
  A4GL_mja_wrefresh (currwin);

  //if (s->mode != MODE_CONSTRUCT)
  //a = A4GL_form_field_chk (s, 0);
  //else
  //a = A4GL_form_field_constr (s, 0);


  pos_form_cursor (mform);

  // Have we changed fields ?
  if (a < 0)
    {
      // Yep...
      return a;
    }


  fprop = (struct struct_scr_field *) field_userptr (current_field (mform));
  metrics = &form->fileform->metrics.metrics_val[A4GL_get_curr_metric (form)];

  if (metrics && (int) metrics != -1)
    {
      set_form_page (mform, metrics->scr - 1);
    }


// Wait for a key..
  a = A4GL_getch_win ();
  if (abort_pressed)
    a = -1;

  A4GL_debug ("form_loop1..  currentfield=%p status = %d", form->currentfield,
	      field_status (form->currentfield));

// Process the key..
  a = A4GL_proc_key (a, mform, s);


  A4GL_debug ("form_loop2..  currentfield=%p status = %d", form->currentfield,
	      field_status (form->currentfield));
// Looks like we're done
  if (a == 0)
    {
      if (s->mode != MODE_CONSTRUCT)
	a = A4GL_form_field_chk (s, -1);
      else
	a = A4GL_form_field_constr (s, -1);

      return 0;
    }


  A4GL_debug ("form_loop3..  currentfield=%p status = %d", form->currentfield,
	      field_status (form->currentfield));

// Looks like we've got something to do...


// Have we changed fields ?
  if (a < 0)
    {
      // Yep...
      return a;
    }

  A4GL_debug ("form_loop4..  currentfield=%p status = %d", form->currentfield,
	      field_status (form->currentfield));

  A4GL_int_form_driver (mform, a);

  A4GL_debug ("form_loop5..  currentfield=%p status = %d", form->currentfield,
	      field_status (form->currentfield));

  A4GL_mja_wrefresh (currwin);

  if (a >= 0 && a <= 255)
    {
      A4GL_int_form_driver (mform, REQ_VALIDATION);
    }



  return -90;

}

#endif



#ifdef MOVED_TO_FORM_CONTROL
/**
 *
 * @todo Describe function
 */
int
A4GL_proc_key (int a, FORM * mform, struct s_screenio *s)
{
  FIELD *f;
  struct s_form_attr *form;
  struct struct_scr_field *fprop;
  struct s_form_dets *fd;
  int npage;
  int acckey;
  fd = A4GL_getfromform (mform);
  form = &fd->form_details;
  do_input_nowrap = 0;

  A4GL_debug ("proc_key .... %d", a);
  f = current_field (mform);
  A4GL_debug ("Current field=%p\n", f);
  if (a != 10)
    {
      A4GL_debug ("Getting fprop");
      fprop = (struct struct_scr_field *) (field_userptr (f));
      A4GL_debug ("fprop=%p\n", fprop);

      if (fprop != 0)
	{
	  A4GL_debug ("Downshift?");
	  if (A4GL_has_bool_attribute (fprop, FA_B_DOWNSHIFT) && isupper (a)
	      && isalpha (a))
	    {
	      a = tolower (a);
	    }
	  A4GL_debug ("Upshift ?");
	  if (A4GL_has_bool_attribute (fprop, FA_B_UPSHIFT) && islower (a)
	      && isalpha (a))
	    {
	      a = toupper (a);
	    }
	}

    }

  acckey = A4GL_key_val ("ACCEPT");

  A4GL_debug ("Got key %d", a);

  m_lastkey = a;
  A4GL_set_last_key (A4GL_curses_to_aubit (a));

  if (a == acckey)
    {
      A4GL_int_form_driver (mform, REQ_VALIDATION);
      s->field_changed = 1;
      return 0;
    }


  switch (a)
    {
    case 18:
      A4GL_mja_wrefresh (stdscr);
      A4GL_mja_wrefresh (currwin);
      A4GL_mja_refresh ();
      break;


    case -1:
      A4GL_debug ("proc_key - got an interrupt");
      A4GL_int_form_driver (mform, REQ_VALIDATION);
      m_lastkey = A4GL_key_val ("INTERRUPT");
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
      if (s->mode != MODE_INPUT_ARRAY)
	{
	  npage = A4GL_page_for_pfield (s) - 1;
	  set_form_page (s->currform->form, npage);
	  s->field_changed = 1;
	  return REQ_PREV_FIELD;
	}
      else
	{
	  // We want to go up on an input array...
	  return 0 - A4GLKEY_UP;
	}

      /*
         case KEY_PGUP : return REQ_PREV_PAGE;
         case KEY_PGDN : return REQ_NEXT_PAGE;
       */

    case '	':
    case KEY_ENTER:
    case 13:
    case 10:
    case KEY_DOWN:
      if (s->mode != MODE_INPUT_ARRAY
	  || (a == '\t' && s->mode == MODE_INPUT_ARRAY))
	{
	  if (std_dbscr.input_wrapmode == 0
	      && A4GL_curr_metric_is_used_last_s_screenio (s, f))
	    {
	      s->field_changed = 1;
	      do_input_nowrap = 1;
	      return 0;
	    }

	  npage = A4GL_page_for_nfield (s) - 1;
	  set_form_page (s->currform->form, npage);
	  s->field_changed = 1;
	  return REQ_NEXT_FIELD;
	}
      else
	{
	  // We want to go down a line in the input array...
	  return 0 - A4GLKEY_DOWN;
	}



    case KEY_LEFT:
      return REQ_PREV_CHAR;

    case KEY_RIGHT:
      return REQ_NEXT_CHAR;

    case 4:			// Control - D
      return REQ_CLR_EOF;

    case 1:			// Control - A
      form->insmode = form->insmode ? 0 : 1;
      if (form->insmode)
	return REQ_INS_MODE;
      else
	return REQ_OVL_MODE;
    }
  A4GL_mja_refresh ();
  return a;
}
#endif

/**
 *
 * @todo Describe function
 */
void
A4GL_set_init_value (FIELD * f, void *ptr, int dtype)
{
  char *ff;
  int a;

  A4GL_debug ("field width=%d", A4GL_get_field_width (f));
  if (ptr != 0)
    {
      A4GL_debug ("Got init value");
      A4GL_push_param (ptr, dtype);
      ff = A4GL_new_string (A4GL_get_field_width (f));
      A4GL_pop_char (ff, A4GL_get_field_width (f));
    }
  else
    {
      ff = A4GL_new_string (A4GL_get_field_width (f));
      for (a = 0; a < A4GL_get_field_width (f); a++)
	ff[a] = ' ';
      ff[A4GL_get_field_width (f) - 1] = 0;
    }
  A4GL_debug ("set_init_value : display '%s' to field", ff);
  A4GL_mja_set_field_buffer (f, 0, ff);
  A4GL_debug ("Init complete");
}

/**
 *
 * @todo Describe function
 */
int
A4GL_read_fields (struct s_form_dets *formdets)
{
  int a, n;
  int n1, a1;
  int metric_no;
  char *ptr;
  A4GL_chkwin ();
  n = formdets->fileform->fields.fields_len;
  A4GL_debug ("Got %d fields\n", n);

  formdets->fields_cnt = n;

  for (a = 0; a < n; a++)
    {
      ptr = A4GL_find_attribute (formdets, a);
      n1 = formdets->fileform->fields.fields_val[a].metric.metric_len;

      for (a1 = 0; a1 < n1; a1++)
	{
	  metric_no =
	    formdets->fileform->fields.fields_val[a].metric.metric_val[a1];
	  A4GL_debug ("Metric number read as %d\n", metric_no);

	  if (formdets->fileform->metrics.metrics_val[metric_no].field != 0)
	    {
	      A4GL_debug ("Has an associated field");
	      if (ptr != 0)
		{
		  A4GL_debug ("Has associated attribute!");
		  set_field_userptr ((FIELD *) formdets->fileform->metrics.
				     metrics_val[metric_no].field, ptr);
		  A4GL_set_field_attr ((FIELD *) formdets->fileform->metrics.
				       metrics_val[metric_no].field);
		  A4GL_debug ("Done\n");
		}
	    }
	}
    }
  A4GL_debug ("formdets->form_fields=%p", formdets->form_fields);
  formdets->form = new_form ((FIELD **) formdets->form_fields);
  if (formdets->form == 0)
    {
      A4GL_exitwith ("Failed to create the loaded the form");
      return 0;
    }
  set_form_userptr (formdets->form, formdets);
  A4GL_debug ("Loaded form...");
  return 1;
}


/**
 *
 * @todo Describe function
 */
void
A4GL_start_form (struct s_form_dets *s)
{
  A4GL_int_form_driver (s->form, REQ_FIRST_PAGE);
  A4GL_int_form_driver (s->form, REQ_FIRST_FIELD);
  pos_form_cursor (s->form);

  if (s->form_details.insmode)
    A4GL_int_form_driver (s->form, REQ_INS_MODE);
  else
    A4GL_int_form_driver (s->form, REQ_OVL_MODE);

  /*A4GL_form_field_chk (s, 1); */
}

/**
 *
 * @todo Describe function
 */
int
A4GL_form_field_chk (struct s_screenio *sio, int m)
{
  char buff[80] = "";
  char buff2[80] = "";
  FORM *mform;
  int x, y;
  int flg = 0;
  struct s_form_dets *form;
  struct struct_scr_field *fprop;

  mform = sio->currform->form;
  A4GL_debug ("CHeck fields 1 m=%d", m);
  form = sio->currform;
  A4GL_debug ("CHeck fields 2 currentfield=%p status = %d",
	      form->currentfield, field_status (form->currentfield));

  fprop = 0;
  if (m > 0)
    {
      A4GL_debug ("CHeck fields 3");
      form->currentfield = 0;
      form->currentmetrics = 0;
      A4GL_debug (" m ");
      return 0;
    }


  A4GL_debug (" current field %p  form says currfield=%p m=%d",
	      form->currentfield, current_field (mform), m);
  A4GL_debug
    ("field_status(form->currentfield)=%d field_status(currfield)=%d",
     field_status (form->currentfield), field_status (current_field (mform)));
  if ((form->currentfield != current_field (mform)) || m < 0)
    {
      /*
         A4GL_debug ("Setting focus");
         A4GL_gui_setfocus (current_field (mform));
       */
      A4GL_debug ("Is different");
      fprop = 0;

      if (form->currentfield != 0)
	if (field_userptr (form->currentfield) != 0)
	  {
	    A4GL_debug ("Is a proper field");
	    fprop =
	      (struct struct_scr_field
	       *) (field_userptr (form->currentfield));
	    A4GL_debug ("fprop=%p", fprop);
	    if (fprop != 0)
	      {
		A4GL_debug ("check Datatype ");
		if (((fprop->datatype != (DTYPE_CHAR & DTYPE_MASK)))
		&& (1||field_status (form->currentfield)))
		{
		  A4GL_debug ("modify size dtype");
		  A4GL_debug ("modfy size for metric %d", A4GL_get_metric_for (form, form->currentfield));

		  A4GL_modify_size (&buff[4],
				    form->fileform->metrics.
				    metrics_val[A4GL_get_metric_for
						(form,
						 form->currentfield)].w);
		  A4GL_debug ("modfy size done -> '%s'", &buff[4]);

		  strcpy (&buff[4], field_buffer (form->currentfield, 0));
		  A4GL_debug ("copy 1");
		  strcpy (buff2, &buff[4]);
		  A4GL_debug ("copy 2");
		  A4GL_debug ("trim buff");
		  A4GL_trim (buff2);
		  getsyx (y, x);

		  A4GL_debug ("CHange y=%d, x=%d", y, x);
		  A4GL_debug ("stack manip buff2='%s'", buff2);
		  A4GL_trim (buff2);

		  if (strlen (buff2) != 0)
		    {
		      A4GL_push_param (buff2, DTYPE_CHAR);

		      if (A4GL_pop_param
			  (buff, fprop->datatype,
			   A4GL_get_field_width (form->currentfield)))
			{
#ifdef DEBUG
			  {
			    A4GL_debug ("Pushing param %p %d", buff,
					fprop->datatype);
			  }
#endif
			  A4GL_push_param (buff, fprop->datatype);
			  if (A4GL_has_str_attribute (fprop, FA_S_FORMAT))
			    {
			      A4GL_push_char (A4GL_get_str_attribute
					      (fprop, FA_S_FORMAT));
			      A4GL_pushop (OP_USING);
			    }
			  A4GL_pop_param (buff, DTYPE_CHAR,
					  A4GL_get_field_width (form->
								currentfield));
			  A4GL_mja_set_field_buffer (form->currentfield, 0,
						     buff);
			}
		      else
			{
			  //push_char(acl_getenv("FIELD_ERROR_MSG"),0);
			  //display_error(1,0);
			  A4GL_error_nobox (acl_getenv ("FIELD_ERROR_MSG"),
					    0);
			  A4GL_debug ("Couldnt read datatype...");
			  A4GL_mja_set_field_buffer (form->currentfield, 0,
						     " ");
			  set_current_field (mform, form->currentfield);
			  A4GL_debug ("RETURNING -1 MJAMJAMJA");
			  return -4;
			}
		    }
		}
	      }
	  }
    }


return 0;

  A4GL_debug ("fprop=%p", fprop);
  A4GL_debug ("form->currentfield=%p", form->currentfield);
  if (fprop)
    {
      A4GL_debug ("fprop->include=%p",
		  A4GL_get_str_attribute (fprop, FA_S_INCLUDE));
      A4GL_debug ("fprop->datatype=%d", fprop->datatype);
    }

  if (form->currentfield != current_field (mform) || m < 0
      || sio->field_changed)
    {
      sio->field_changed = 0;
      fprop =
	(struct struct_scr_field *) (field_userptr (current_field (mform)));

      if (fprop != 0)
	{
	  /* A4GL_push_long (form->currentfield); */
	  A4GL_push_long ((long) current_field (mform));
	  A4GL_push_char (fprop->colname);
	}
      else
	{
	  A4GL_push_long ((long) 0);
	  A4GL_push_char ("THIS FIELD IS AT THE START");
	}

      fprop =
	(struct struct_scr_field *) (field_userptr (form->currentfield));
      if (fprop != 0)
	{
	  A4GL_do_after_field (form->currentfield, sio);
	  /* A4GL_push_long (current_field (mform)); */
	  A4GL_push_long ((long) form->currentfield);
	  A4GL_push_char (fprop->colname);
	}
      else
	{
	  A4GL_push_long ((long) 0);
	  A4GL_push_char ("THIS FIELD IS AT THE START");
	}
      flg = -1;
    }
#ifdef DEBUG
  {
    A4GL_debug ("Setting current field");
  }
#endif
  form->currentfield = current_field (mform);
  A4GL_debug ("Set to %p", form->currentfield);
  fprop = (struct struct_scr_field *) (field_userptr (form->currentfield));
#ifdef DEBUG
  {
    A4GL_debug ("Adding A4GL_comments %p");
  }
#endif
  if (fprop != 0)
    A4GL_comments (fprop);

#ifdef DEBUG
  {
    A4GL_debug ("returning");
  }
#endif
  return flg;

}

/**
 *
 * @todo Describe function
 */
int
A4GL_get_curr_metric (struct s_form_dets *form)
{
  int a;
  A4GL_debug ("In curr metric");
  for (a = 0; a < form->fileform->metrics.metrics_len; a++)
    {
      if (current_field (form->form) ==
	  (FIELD *) form->fileform->metrics.metrics_val[a].field)
	{
	  A4GL_debug ("Returning %d\n", a);
	  return a;
	}
    }
  A4GL_debug ("NO current metric !");
  return -1;
}

/**
 *
 * @todo Describe function
 */
int
A4GL_get_metric_no (struct s_form_dets *form, FIELD * f)
{
  int a;
  A4GL_debug ("In curr metric");
  for (a = 0; a < form->fileform->metrics.metrics_len; a++)
    {
      if (f == (FIELD *) form->fileform->metrics.metrics_val[a].field)
	{
	  A4GL_debug ("Returning %d\n", a);
	  return a;
	}
    }
  A4GL_debug ("NO current metric !");
  return -1;
}


/**
 *
 * @todo Describe function
 */
int
A4GL_get_metric_for (struct s_form_dets *form, FIELD * f)
{
  int a;

  A4GL_debug ("In curr metric");
  for (a = 0; a < form->fileform->metrics.metrics_len; a++)
    {
      if (f == (FIELD *) form->fileform->metrics.metrics_val[a].field)
	{
	  A4GL_debug ("Returning %d\n", a);
	  return a;
	}
    }
  A4GL_debug ("NO current metric !");
  return -1;
}


/**
 *
 * @todo Describe function
 */
int
A4GL_get_field_width (FIELD * f)
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
A4GL_turn_field_off (FIELD * f)
{
  struct struct_scr_field *fprop;
  int a;
  fprop = (struct struct_scr_field *) (field_userptr (f));
  A4GL_debug ("Turn Field Off %s %s", fprop->tabname, fprop->colname);
  a = field_opts_off (f, O_ACTIVE);
  A4GL_debug ("a=%d", a);
  a += field_opts_off (f, O_EDIT);
  A4GL_debug ("a=%d", a);
  if (a == 0)
    return 0;
  return 1;

}

/**
 *
 * @todo Describe function
 */
void
A4GL_turn_field_on (FIELD * f)
{
  struct struct_scr_field *fprop;
  int a;
  fprop = (struct struct_scr_field *) (field_userptr (f));
  A4GL_debug ("Turn Field On %s %s", fprop->tabname, fprop->colname);
  a = field_opts_on (f, O_ACTIVE);
  A4GL_debug ("a=%d", a);
  a = field_opts_on (f, O_EDIT);
  A4GL_debug ("a=%d", a);
  A4GL_set_field_attr (f);
}

/**
 *
 * @todo Describe function
 */
void
A4GL_turn_field_on2 (FIELD * f, int a)
{

  struct struct_scr_field *fprop;
  A4GL_assertion (f == 0, "Field is zero in turn_field_on2");
  A4GL_debug ("Turn field on %p %d", f, a);
  fprop = (struct struct_scr_field *) (field_userptr (f));
  A4GL_assertion (fprop == 0, "Field has no properties");
  A4GL_debug ("turn_field_on2 a=%d fprop=%p", a, fprop);

  A4GL_debug ("Turn Field On %p %p", fprop->tabname, fprop->colname);
  A4GL_debug ("Turn Field On %s %s", fprop->tabname, fprop->colname);
  field_opts_on (f, O_ACTIVE);
  field_opts_on (f, O_EDIT);

  if (a)
    {
      A4GL_debug ("STATIC");
      field_opts_on (f, O_STATIC);
      set_max_field (f, 0);
    }
  else
    {
      A4GL_debug ("NOT STATIC");
      field_opts_off (f, O_STATIC);
    }
  A4GL_set_field_attr (f);
}


/**
 *
 * @todo Describe function
 */
void
A4GL_set_init_pop (FIELD * f)
{
  char *ff;
  ff = A4GL_new_string (A4GL_get_field_width (f));
  A4GL_pop_char (ff, A4GL_get_field_width (f));
  A4GL_debug ("set_init_pop : display %s to field", ff);
  A4GL_mja_set_field_buffer (f, 0, ff);
  touchwin (currwin);
}


/**
 * 4GL CALL
 * @todo Describe function
 */
int
A4GL_set_fields (void *vsio)
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
  struct s_screenio *sio;
  sio = vsio;

  wid = 0;
  if (sio->mode == MODE_INPUT_WITHOUT_DEFAULTS
      || sio->mode == MODE_INPUT_ARRAY)
    wid = 1;
  A4GL_debug ("in set fields");
  formdets = sio->currform;
  if (formdets == 0)
    {
      A4GL_exitwith ("No form");
      return 0;
    }
  A4GL_debug ("set fdets");

  flg = 0;

  A4GL_debug ("Turning off all");

  for (a = 0; formdets->form_fields[a] != 0; a++)
    {
      field =
	(struct struct_scr_field
	 *) (field_userptr (formdets->form_fields[a]));
      if (field == 0)
	continue;

      if (A4GL_turn_field_off (formdets->form_fields[a]))
	{
	  firstfield = formdets->form_fields[a];
	}

    }

  nofields = sio->nfields;
  field_list = (FIELD **) sio->field_list;

  A4GL_debug ("Field list=%p number of fields = %d", field_list, nofields);

  nv = sio->novars;

  if (nofields != nv - 1)
    {
      A4GL_debug
	("Number of fields (%d) is not the same as the number of vars (%d)",
	 nofields + 1, nv);
      A4GL_exitwith
	("Number of fields is not the same as the number of variables");
      return 0;
    }

  for (a = 0; a <= nofields; a++)
    {

      if (field_list[a] == firstfield)
	{
	  firstfield = 0;
	}
      A4GL_debug ("loop through fields a=%d %p", a, field_list[a]);
      A4GL_turn_field_on2 (field_list[a], sio->mode != MODE_CONSTRUCT);

      if (wid)
	{
	  A4GL_set_init_value (field_list[a], sio->vars[a].ptr,
			       sio->vars[a].dtype);
	}
      else
	{
	  prop = (struct struct_scr_field *) field_userptr (field_list[a]);
	  if (A4GL_has_str_attribute (prop, FA_S_DEFAULT))
	    {
	      A4GL_debug ("default from form to '%s'",
			  A4GL_get_str_attribute (prop, FA_S_DEFAULT));
	      A4GL_set_init_value (field_list[a],
				   A4GL_replace_sql_var (A4GL_strip_quotes
							 (A4GL_get_str_attribute
							  (prop,
							   FA_S_DEFAULT))),
				   0);
	    }
	  else
	    {
	      A4GL_set_init_value (field_list[a], 0, 0);
	    }
	}

      if (sio->mode != MODE_CONSTRUCT)
	{
	  A4GL_push_char (field_buffer (field_list[a], 0));
	  A4GL_pop_var2 (sio->vars[a].ptr, sio->vars[a].dtype,
			 sio->vars[a].size);
	}

      if (flg == 0)
	{
	  set_current_field (formdets->form, field_list[a]);
	  /*formdets->form_fields[z]); */
	  flg = 1;
	}

      set_field_status (field_list[a], 0);
    }

  if (firstfield)
    A4GL_turn_field_off (firstfield);

  if (flg == 0)
    {
      A4GL_error_box ("NO active field\n", 0);
    }
  return 1;
}



#ifdef OBSOLETE
/**
 *
 * @todo Describe function
 */
void
set_fields2 (int nv, struct BINDING *vars, int d, int n, ...)
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
  formdets = A4GL_get_curr_form ();
  flg = 0;

  A4GL_debug ("Turning off all");
  for (z = 0; formdets->form_fields[z] != 0; z++)
    {
      field =
	(struct struct_scr_field
	 *) (field_userptr (formdets->form_fields[z]));
      if (field == 0)
	{
	  continue;
	}
      A4GL_turn_field_off (formdets->form_fields[z]);
    }

  A4GL_debug ("Set_fields - turned off all n=%d", n);

  va_start (ap, n);
#ifdef DEBUG
  {
    A4GL_debug ("Genfldlist 1");
  }
#endif
  A4GL_debug ("set fields 2");
  nofields = A4GL_gen_field_list (&field_list, formdets, nv, &ap);

  if (nofields != nv - 1)
    {
      sprintf (errbuff,
	       "Number of fields (%d) is not the same as the number of vars (%d)",
	       nofields, nv);
      exitwith
	("Number of fields is not the same as the number of variables");
    }

  for (a = 0; a <= nofields; a++)
    {
      A4GL_turn_field_on (field_list[a]);
      if (d)
	A4GL_set_init_value (field_list[a], vars[a].ptr, vars[a].dtype);

      if (flg == 0)
	{
	  set_current_field (formdets->form, formdets->form_fields[z]);
	  flg = 1;
	}
    }
  if (flg == 0)
    {
      A4GL_exitwith ("No active field");
    }
}
#endif



/**
 *
 * @todo Describe function
 */
int
A4GL_field_name_match (FIELD * f, char *s)
{
  char colname[40];
  char tabname[40];
  int aa;
  int ab;
  struct struct_scr_field *field;
  A4GL_bname (s, tabname, colname);
  A4GL_debug ("field_name_match : '%s' '%s'", tabname, colname);

  field = (struct struct_scr_field *) (field_userptr (f));
  if (field == 0)
    return 0;

  aa = strcmp (field->tabname, tabname);
  ab = strcmp (field->colname, colname);
  A4GL_debug ("Column defined as %s %s", field->tabname, field->colname);

  if ((aa == 0 && ab == 0) || (aa == 0 && colname[0] == '*'))
    {
      A4GL_debug ("Matches in .*");
      return 1;
    }

  if (ab == 0 && tabname[0] == 0)
    {
      A4GL_debug ("matches just on column");
      return 1;

    }
  A4GL_debug ("Doesn't A4GL_match - %d %d", aa, ab);
  return 0;
}


/**
 * 4GL CALL
 * @todo Describe function
 */
void
A4GL_disp_fields_ap (int n, int attr, va_list * ap)
{
  int a;
  int flg;
  struct s_form_dets *formdets;
  FIELD **field_list;
  int nofields;
  a4gl_status = 0;

  A4GL_debug ("In disp_fields");
  formdets = A4GL_get_curr_form ();
#ifdef DEBUG
  {
    A4GL_debug ("Status=%d formdets=%p", a4gl_status, formdets);
  }
#endif
  if (a4gl_status != 0)
    return;
  flg = 0;

  A4GL_debug (" field_list = %p", &field_list);
#ifdef DEBUG
  {
    A4GL_debug ("Genfldlist 2");
  }
#endif
  A4GL_debug ("disp_fields");
  nofields = A4GL_gen_field_list (&field_list, formdets, n, ap);
  A4GL_debug ("Number of fields=%d ", nofields,n);

  if (nofields<0) {
	return ;
  }
  
  for (a = nofields; a >= 0; a--)
    {
      A4GL_debug ("field_list[%d]=%p", a, field_list[a]);
      A4GL_debug_print_field_opts (field_list[a]);
      /* fldattr=field_opts(field_list[a]); */
      A4GL_debug ("MJA Calling A4GL_set_field_pop_attr - 1 - attr=%d", attr);




      A4GL_set_field_pop_attr (field_list[a], attr,FGL_CMD_DISPLAY_CMD);



      /* rc=set_field_opts(field_list[a],fldattr); */
      A4GL_debug_print_field_opts (field_list[a]);
      A4GL_debug ("set_init_pop complete");
    }
  A4GL_mja_wrefresh (currwin);
}



/**
 * 4GL CALL
 * @todo Describe function
 */
int
A4GL_gen_field_chars_ap (FIELD *** field_list, struct s_form_dets *formdets,
			 va_list * ap)
{
  int a;
  /* va_start (ap, formdets); */
#ifdef DEBUG
  {
    A4GL_debug ("Starting A4GL_gen_field_chars %p %p", field_list, formdets);
  }
  {
    A4GL_debug ("Genfldlist 3");
  }
#endif
  A4GL_debug ("gen_field_chars");
  a = A4GL_gen_field_list (field_list, formdets, 9999, ap);
#ifdef DEBUG
  {
    A4GL_debug ("--------------------------------------END gen_field_chars");
  }
#endif
  A4GL_debug ("Gen_field_list returned %d", a);
  return a;
}

/**
 *
 * @todo Describe function
 */
int
A4GL_gen_field_list (FIELD *** field_list, struct s_form_dets *formdets,
		     int a, va_list * ap)
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
  {
    A4GL_debug ("gen_field_list - %p %p %d %p", field_list, formdets, a, ap);
  }
#endif
  A4GL_debug ("field_list=%p", field_list);
  A4GL_debug ("Here 2");
  /*
     *field_list = calloc (a, sizeof (FIELD *));
     *field_list = calloc (1024, sizeof (FIELD *));

     A4GL_dump_srec (&formdets);
   */

  for (z1 = 0; z1 <= a; z1++)
    {
      A4GL_debug ("Getting first %d", z1);
      s = va_arg (*ap, char *);	/* This is suspect.... */

      if (s == 0)
	break;

      A4GL_debug ("Got first %s:", s);

      f = (int) va_arg (*ap, int *);
      A4GL_debug ("f=%d\n", f);
      if (f > 0)
	f--;

      A4GL_debug (" got field number as %d ", f);


      ff = 0;

      /* get screen record/table name */

      A4GL_bname (s, tabname, colname);
      srec_no = A4GL_find_srec (formdets->fileform, tabname);
      A4GL_debug ("srec_no=%d", srec_no);
      if (srec_no != -1)
	{
	  for (z = 0;
	       z <
	       formdets->fileform->records.records_val[srec_no].attribs.
	       attribs_len; z++)
	    {
	      A4GL_debug ("srec_no=%d", srec_no);
	      attr_no =
		formdets->fileform->records.records_val[srec_no].attribs.
		attribs_val[z];
	      A4GL_debug ("attr_no=%d", attr_no);
#ifdef DEBUG
	      {
		A4GL_debug ("Attr 1");
	      }
#endif
	      A4GL_debug ("attr_no=%d s=%s\n", attr_no, s);
	      mno =
		A4GL_attr_name_match (&formdets->fileform->attributes.
				      attributes_val[attr_no], s);
	      A4GL_debug ("mno=%d\n", mno);

	      if (mno)
		{
		  fno =
		    formdets->fileform->attributes.attributes_val[attr_no].
		    field_no;
		  A4GL_debug ("Matched to field no %d", fno);
		  if (fno >= formdets->fileform->fields.fields_len)
		    {
		      A4GL_exitwith ("Dubious form\n");
		      return -1; // Was 0
		    }
		  metric_no =
		    formdets->fileform->fields.fields_val[fno].metric.
		    metric_val[f];
		  A4GL_debug ("fno=%d f=%d mno=%d metric_no=%d\n", fno, f,
			      mno, metric_no);
		  k = &formdets->fileform->metrics.metrics_val[metric_no];
#ifdef DEBUG
		  {
		    A4GL_debug ("cnt=%d a=%d", cnt, a);
		  }
#endif

		  if (cnt >= a)
		    {
		      A4GL_debug ("cnt=%d a=%d", cnt, a);
		      A4GL_exitwith
			("Too few variables for the number of fields");
		    }
		  A4GL_debug ("Setting flist[%d] to %p", cnt, k);
		  flist[cnt++] = (FIELD *) k->field;
		  A4GL_debug ("Set");
		  ff = 1;
		}

	    }
	}

      else
	{
	  for (z = 0; z < formdets->fileform->attributes.attributes_len; z++)
	    {
	      attr_no = z;
	      A4GL_debug ("attr_no=%d", attr_no);
#ifdef DEBUG
	      {
		A4GL_debug ("Attr 2");
	      }
#endif
	      mno =
		A4GL_attr_name_match (&formdets->fileform->attributes.
				      attributes_val[attr_no], s);
	      if (mno)
		{
		  fno =
		    formdets->fileform->attributes.attributes_val[attr_no].
		    field_no;
		  A4GL_debug ("Matched to field no %d - len=%d f=%d", fno,formdets->fileform->fields.fields_val[fno].metric.metric_len,f);
		if (formdets->fileform->fields.fields_val[fno].metric.metric_len<=f || f<0) {
			A4GL_exitwith("Field subscript out of bounds");
			return -1;
		}
		  metric_no =
		    formdets->fileform->fields.fields_val[fno].metric.
		    metric_val[f];
		  k = &formdets->fileform->metrics.metrics_val[metric_no];
#ifdef DEBUG
		  {
		    A4GL_debug ("cnt=%d a=%d", cnt, a);
		  }
#endif
		  if (cnt >= a)	/* was >= */
		    {
		      A4GL_debug ("cnt=%d a=%d", cnt, a);
		      A4GL_debug ("Too few variable");
		      A4GL_exitwith
			("Too few variables for the number of fields");
		    }
		  A4GL_debug ("Setting flist[%d] to %p", cnt, k);
		  flist[cnt++] = (FIELD *) k->field;
		  //set_field_status((FIELD *)k->field, 0);
		  A4GL_debug ("aa");
		  ff = 1;
		}
	      A4GL_debug ("aa");
	    }
	  A4GL_debug ("aa");

	}
      A4GL_debug ("aa");
      if (ff == 0)
	{
	  A4GL_exitwith ("Field name not found");
	  return -1;
	}

    }
  s = va_arg (*ap, char *);

  if (s != 0)
    A4GL_debug ("Trailing fields ignored");


  *field_list = calloc (cnt + 1, sizeof (FIELD *));
  memcpy (*field_list, flist, sizeof (FIELD *) * (cnt + 1));
  return cnt - 1;
}



/**
 *
 * @todo Describe function
 */
void
A4GL_do_after_field (FIELD * f, struct s_screenio *sio)
{
  int a;
  char *ptr;
  struct struct_scr_field *fprop;
  FORM *mform;

  A4GL_debug ("Do after field status=%d", field_status (f));
  A4GL_debug ("do after field buffer set to '%s'", field_buffer (f, 0));

  a = A4GL_find_field_no (f, sio);

  if (a == -1)
    {
      A4GL_exitwith ("after field : field number not found!");
      return;
      //A4GL_bomb_out ();
    }

  if (sio->mode != MODE_CONSTRUCT)
    {
#ifdef DEBUG
      {
	A4GL_debug ("   Field buffer = %s", field_buffer (f, 0));
      }
#endif
      A4GL_push_char (field_buffer (f, 0));
#ifdef DEBUG
      {
	A4GL_debug ("   Ptr=%p dtype=%d size=%d", sio->vars[a].ptr,
		    sio->vars[a].dtype, sio->vars[a].size);
      }
#endif

      /* now check that the form corresponds to the includes */
      if (sio->currform->currentfield)
	{
	  A4GL_debug ("Got current field %p\n", sio->currform->currentfield);
	  mform = sio->currform->form;
	  fprop = (struct struct_scr_field *) (field_userptr (f));
	  A4GL_debug ("Got form %p", sio->currform->form);
	  if (A4GL_check_field_for_include
	      (field_buffer (sio->currform->currentfield, 0),
	       A4GL_get_str_attribute (fprop, FA_S_INCLUDE),
	       fprop->datatype) == 0)
	    {
	      A4GL_error_nobox ("This value is not available", 0);
	      set_current_field (mform, sio->currform->currentfield);
	    }
	}

      A4GL_pop_var2 (sio->vars[a].ptr, sio->vars[a].dtype, sio->vars[a].size);

    }
  else
    {
      fprop = (struct struct_scr_field *) (field_userptr (f));
      if (fprop != 0)
	{
	  if (fprop->colname != 0)
	    {
	      ptr =
		(char *) A4GL_construct (fprop->colname, field_buffer (f, 0),
					 (fprop->datatype == 0)
					 || (fprop->datatype == 8));
	      A4GL_debug ("ptr=%s", ptr);
	      if (ptr == 0)
		A4GL_error_nobox ("Error in expression", 0);
	    }
	}
    }
  A4GL_debug ("Done after field - field_status=%d", field_status (f));

}


/**
 *
 * @todo Describe function
 */
void
A4GL_do_before_field (FIELD * f, struct s_screenio *sio)
{
  int a;
  char *ptr;
  A4GL_debug ("Before field....");
  A4GL_gui_setfocus ((long) f);
  a = A4GL_find_field_no (f, sio);
  if (a == -1)
    {
      A4GL_exitwith ("before field : field number not found!");
    }
  if (sio->mode != MODE_CONSTRUCT)
    {
      A4GL_push_param (sio->vars[a].ptr, sio->vars[a].dtype);
      ptr = A4GL_char_pop ();
      A4GL_mja_set_field_buffer (f, 0, ptr);
      acl_free (ptr);
    }

}



/**
 *
 * @todo Describe function
 */
int
A4GL_find_field_no (FIELD * f, struct s_screenio *sio)
{
  int a;
#ifdef DEBUG
  {
    A4GL_debug ("Finding field %p", f);
  }
#endif
  for (a = 0; a <= sio->nfields; a++)
    {
#ifdef DEBUG
      {
	A4GL_debug ("Checking against %p", sio->field_list[a]);
      }
#endif

      if (sio->field_list[a] == f)
	return a;

    }
#ifdef DEBUG
  {
    A4GL_debug ("Its not there!");
  }
#endif
  return -1;
}




/**
 *
 * @todo Describe function
 */
FIELD *
A4GL_make_field (int frow, int fcol, int rows, int cols)
{
  FIELD *f;
  A4GL_debug ("Creating new field entry y=%d x=%d rows=%d width=%d\n", frow,
	      fcol, rows, cols);

  f = new_field (rows, cols, frow, fcol, 0, 0);

  if (f)
    {
      A4GL_gui_mkfield (rows, cols, frow, fcol, f);
      A4GL_debug ("Field created - setting attributes");
      /*A4GL_set_field_attr (f); */
      field_opts_off (f, O_ACTIVE);
      field_opts_off (f, O_EDIT);
    }
  else
    {
      A4GL_exitwith ("Unable to create field");
      return 0;
    }

  return (f);
}


/**
 *
 * @todo Describe function
 */
void
A4GL_dump_fields (FIELD * fields[])
{
  int a = 0;
  A4GL_debug ("Dumping fields");
  return;
  while (fields[a] != 0)
    {
      A4GL_debug ("Field %d %p (%d,%d) (%s)\n", a, fields[a], fields[a]->frow,
		  fields[a]->fcol, fields[a]->buf);
      a++;
    }
}


/**
 *
 * @todo Describe function
 */
void
A4GL_set_field_pop_attr (FIELD * field, int attr,int cmd_type)
{
  char *ff;
  struct struct_scr_field *f;
  struct s_form_dets *fff;
  int a;
  int field_width;
  long oopt;
  int d1;
  int s1;
  void* ptr1;
  int has_format=0;
  int ignore_formatting=0;


  A4GL_get_top_of_stack (1, &d1, &s1, (void **) &ptr1);
  field_width=A4GL_get_field_width (field);

  ff = A4GL_new_string (A4GL_get_field_width (field));

  f = (struct struct_scr_field *) (field_userptr (field));

  if (A4GL_has_bool_attribute (f, FA_B_REVERSE))
    a = 1;
  else
    a = 0;

  A4GL_debug ("f->do_reverse=%d attr=%d", a, attr);

  has_format=A4GL_has_str_attribute (f, FA_S_FORMAT);

// 'Format' is valid for a lot of datatypes -
// but not all...
// If we are passing **IN** a character string
// for example - we'll omit the formatting...

  switch (d1&DTYPE_MASK) {
	case DTYPE_CHAR:
	case DTYPE_BYTE:
	case DTYPE_TEXT:
	case DTYPE_VCHAR: ignore_formatting=1;
  }


  if (has_format&&!ignore_formatting) 
    {
	A4GL_debug("Has specified format..");
	if (strlen(A4GL_get_str_attribute (f, FA_S_FORMAT))>field_width) {
		A4GL_exitwith("Format is wider than the field");
		return ;
	}

// I think these 2 can be removed...
      //A4GL_pop_char (ff, field_width );
      //A4GL_push_char (ff);
      A4GL_push_char (A4GL_get_str_attribute (f, FA_S_FORMAT));
      A4GL_pushop (OP_USING);
    } 

    if (!has_format&&!ignore_formatting) {
	A4GL_debug("Has no format.. d1=%d",d1&DTYPE_MASK);
	if (A4GL_has_datatype_function_i (d1 & DTYPE_MASK, "DISPLAY")) {
		char *ptr;
        	char *(*function) (void *, int, int, struct struct_scr_field *, int);
	A4GL_debug("check for specific display routine");
        	function = A4GL_get_datatype_function_i (d1 & DTYPE_MASK, "DISPLAY");
		if (function) {
		A4GL_debug("Has a function - calling");
        	ptr = function (ptr1, s1, field_width,f,DISPLAY_TYPE_DISPLAY_TO);
		A4GL_debug("Returns %p\n",ptr);
		} else {
		ptr=0;
		}
		if (ptr!=0) {
			A4GL_debug("Here.. %s",ptr);
			A4GL_drop_param();
			A4GL_debug("Dropped - pushing mine..");
			A4GL_push_char(ptr);
		} 
	}

    }

  A4GL_pop_char (ff, A4GL_get_field_width (field));
  A4GL_debug ("set f->do_reverse to %d ", f->do_reverse);
  oopt = field_opts (field);
  A4GL_set_field_attr (field);

  attr=A4GL_determine_attribute(cmd_type, attr, f);

  if (attr != 0)
    A4GL_set_field_attr_with_attr (field, attr);


  A4GL_debug ("set field attr");
  fff = A4GL_get_curr_form ();
  A4GL_debug ("set field");
  A4GL_mja_set_field_buffer (field, 0, ff);
  A4GL_debug ("set field buffer");

  f->do_reverse = a;
  A4GL_debug ("done ");
  set_field_opts (field, oopt);
  free(ff);
}



/**
 *
 * @todo Describe function
 */
void
A4GL_set_init_pop_attr (FIELD * field, int attr)
{
  char *ff;
  struct struct_scr_field *f;
  struct s_form_dets *fff;
  int a;
  A4GL_debug ("Field = %p", field);
  ff = A4GL_new_string (A4GL_get_field_width (field));
  A4GL_pop_char (ff, A4GL_get_field_width (field));

  A4GL_debug ("set_init_pop_attr : display '%s' to field %d", ff, attr);

  f = (struct struct_scr_field *) (field_userptr (field));
  A4GL_assertion (f == 0, "set_init_pop_attr - Pointer is zero...");
  A4GL_debug ("f=%p", f);

  a = f->do_reverse;
  A4GL_debug ("f->reverse=%d attr=%d", f->do_reverse, attr);

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
  A4GL_debug ("set f->do_reverse to %d ", f->do_reverse);
  A4GL_set_field_attr (field);
  A4GL_debug ("set field attr");
  fff = A4GL_get_curr_form ();
  A4GL_debug ("got curr form");
  set_current_field (fff->form, field);
  A4GL_debug ("set field");
  A4GL_mja_set_field_buffer (field, 0, ff);
  A4GL_debug ("set field buffer");

  f->do_reverse = a;
  A4GL_debug ("done ");

}




/**
 *
 * @todo Describe function
 */
void
A4GL_iarr_arr_fields (int n, int fonly, int attr, ...)
{
  int a;
  va_list ap;
  int flg;
  struct s_form_dets *formdets;
  FIELD **field_list;
  int nofields;
  A4GL_debug ("In disp_fields");

  formdets = A4GL_get_curr_form ();

  flg = 0;
  va_start (ap, attr);
  A4GL_debug (" field_list = %p", &field_list);
#ifdef DEBUG
  {
    A4GL_debug ("Genfldlist 5");
  }
#endif
  nofields = A4GL_gen_field_list (&field_list, formdets, n, &ap);
  if (fonly && nofields >= 0)
    nofields = 0;
  //debug ("MJA Number of fields=%d", nofields);
  if (nofields >= 0)
    {
      for (a = 0; a <= nofields; a++)
	{
	  A4GL_debug ("field_list[%d]=%p", a, field_list[a]);
	  A4GL_set_init_pop_attr (field_list[a], attr);
	  A4GL_debug ("set_init_pop complete");
	}
    }
}




/**
 *
 * @todo Describe function
 */
void
A4GL_disp_arr_fields (int n, int fonly, int attr, ...)
{
  int a;
  va_list ap;
  int flg;
  struct s_form_dets *formdets;
  FIELD **field_list;
  int nofields;
  A4GL_debug ("In disp_fields");
  formdets = A4GL_get_curr_form ();
  flg = 0;



  va_start (ap, attr);
  A4GL_debug (" field_list = %p", &field_list);
#ifdef DEBUG
  {
    A4GL_debug ("Genfldlist 5");
  }
#endif
  A4GL_debug ("disp_arr_fields");
  nofields = A4GL_gen_field_list (&field_list, formdets, n, &ap);
  if (fonly && nofields >= 0)
    nofields = 0;
  A4GL_debug ("Number of fields=%d", nofields);
  if (nofields >= 0)
    {
      for (a = 0; a <= nofields; a++)
	{
	  A4GL_debug ("field_list[%d]=%p", a, field_list[a]);
	  A4GL_set_init_pop_attr (field_list[a], attr);
	  A4GL_debug ("set_init_pop complete");
	}
    }
}

/**
 *
 * @todo Describe function
 */
void
A4GL_set_arr_fields (int n, int attr, ...)
{
  int a;
  va_list ap;
  int flg;
  struct s_form_dets *fff;
  struct s_form_dets *formdets;
  FIELD **field_list;
  int nofields;

  return;			/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

  A4GL_debug ("In disp_fields");
  formdets = A4GL_get_curr_form ();
  flg = 0;

  va_start (ap, attr);
  A4GL_debug (" field_list = %p", &field_list);
#ifdef DEBUG
  {
    A4GL_debug ("Genfldlist 6");
  }
#endif
  A4GL_debug ("set_arr_fields");
  nofields = A4GL_gen_field_list (&field_list, formdets, n, &ap);
  A4GL_debug ("Number of fields=%d", nofields);
  for (a = nofields; a >= 0; a--)
    {
      A4GL_debug ("field_list[%d]=%p", field_list[a]);
      fff = A4GL_get_curr_form ();
      set_current_field (fff->form, field_list[a]);
      A4GL_debug ("set_init_pop complete");
    }
  set_current_field (fff->form, field_list[nofields]);
}


/**
 *
 * @todo Describe function
 */
int
A4GL_form_field_constr (struct s_screenio *sio, int m)
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
		  A4GL_debug ("CHeckit here");
		  getsyx (y, x);
		}
	    }
	}
    }

  if (form->currentfield != current_field (mform))
    {
      fprop =
	(struct struct_scr_field *) (field_userptr (current_field (mform)));
      A4GL_debug ("Moving to %s", fprop->colname);
      if (fprop != 0)
	{
	  A4GL_push_long ((long) current_field (mform));
	  A4GL_push_char (fprop->colname);
	}
      else
	{
	  A4GL_push_long (0);
	  A4GL_push_char ("THIS FIELD IS AT THE START");
	}

      fprop =
	(struct struct_scr_field *) (field_userptr (form->currentfield));
      if (fprop != 0)
	{
	  if (fprop->colname != 0)
	    {
	      A4GL_debug ("Moving from %s", fprop->colname);
	    }
	  else
	    {
	      A4GL_debug ("Blank colname");
	    }
	}
      if (fprop != 0)
	{
	  A4GL_do_after_field (form->currentfield, sio);
	  A4GL_push_long ((long) form->currentfield);
	  A4GL_push_char (fprop->colname);
	}
      else
	{
	  A4GL_push_long (0);
	  A4GL_push_char ("THIS FIELD IS AT THE START");
	}
      flg = -1;
    }
  A4GL_debug ("Setting currentfield entry on form...");
  form->currentfield = current_field (mform);


  fprop = (struct struct_scr_field *) (field_userptr (form->currentfield));
  if (fprop != 0)
    A4GL_comments (fprop);

  pos_form_cursor (mform);
  A4GL_debug_print_stack ();

  return flg;
}


void A4GL_mja_set_field_buffer_contrl (FIELD * field, int nbuff,int ch) {
	char buff[20];
	buff[0]=ch;
	buff[1]=0;
	A4GL_mja_set_field_buffer (field,  nbuff, buff);
}
/**
 *
 * @todo Describe function
 */
void
A4GL_mja_set_field_buffer (FIELD * field, int nbuff, char *buff)
{
  char buff2[1024];
  int a;
  int b;
  int errno;
  b = A4GL_get_field_width (field);
  strcpy (buff2, buff);
  a = strlen (buff2);
  b = A4GL_get_field_width (field);
  A4GL_debug ("mja_set_field_buffer buff='%s' buff2='%s' (%d,%d) ", buff,
	      buff2, a, b);
  A4GL_gui_setbuff (field, buff);
  if (a < A4GL_get_field_width (field))
    {
      A4GL_debug ("Adding padding");
      A4GL_pad_string (buff2, A4GL_get_field_width (field));
    }
  else
    {
      A4GL_debug ("No padding required '%s'", buff);
    }

  errno = set_field_buffer (field, nbuff, buff2);
  A4GL_debug ("Setting %p %d to %s (%d)", field, nbuff, buff2, errno);
  A4GL_debug ("field buffer set to '%s'", field_buffer (field, 0));
  A4GL_debug ("Currwin=%p", currwin);
  pos_form_cursor (field->form);
  if (currwin > (WINDOW *) 1)
    {
      touchwin (currwin);
#ifdef DEBUG
      {
	A4GL_debug ("Touched Window");
      }
#endif
    }
  else
    {
#ifdef DEBUG
      {
	A4GL_debug ("No window to Touch");
      }
#endif
    }
#ifdef DEBUG
  {
    A4GL_debug ("Refreshed Window");
  }
#endif
}



/**
 * 4GL CALL
 * @todo Describe function
 */
int
A4GL_push_constr (void *vs)
{
  struct struct_scr_field *fprop;
  FIELD *f;
  int a;
  char *ptr;
  int flg = 0;
  struct s_screenio *s;
  s = vs;
  if (s->currform == 0)
    {
      A4GL_push_char ("");
      return 0;
    }
  A4GL_int_form_driver (s->currform->form, REQ_FIRST_PAGE);

  A4GL_debug ("Push_constr");
  A4GL_debug ("nfields=%d", s->nfields);
  A4GL_debug ("s-field_list[0]=%p", s->field_list[0]);

  for (a = 0; a <= s->nfields; a++)
    {
      A4GL_debug ("Looping a=%d\n", a);
      f = s->field_list[a];
      A4GL_debug ("f=%p", f);
      fprop = (struct struct_scr_field *) (field_userptr (f));
      A4GL_debug ("fprop=%p", fprop);
      if (fprop != 0)
	{
	  A4GL_debug ("getting ptr", fprop);
	  A4GL_debug ("fprop->colname=%s fprop->datatype=%x", fprop->colname,
		      (fprop->datatype) & 0xffff);
	  ptr =
	    (char *) A4GL_construct (fprop->colname, field_buffer (f, 0),
				     ((fprop->datatype & 0xffff) == 0)
				     || ((fprop->datatype & 0xffff) == 8));
	  if (strlen (ptr) > 0)
	    {
	      A4GL_debug ("ptr=%s\n", ptr);
	      if (flg == 0)
		{
		  A4GL_push_char (ptr);
		  flg = 1;
		}
	      else
		{
		  A4GL_push_char (" AND ");
		  A4GL_push_char (ptr);
		  A4GL_pushop (OP_CONCAT);
		  A4GL_pushop (OP_CONCAT);
		}
	    }
	}
    }
  if (flg == 0)
    A4GL_push_char ("1=1");
  return 1;
}



/**
 *
 * @todo Describe function
 */
FIELD *
A4GL_scan_for_field (char *s)
{
  struct s_form_dets *f;
  FIELD *fld;
  int a;
  f = A4GL_get_curr_form ();
  if (f == 0)
    return 0;

  for (a = 0; (fld = (f->form_fields[a])); a++)
    {
      A4GL_debug ("Calling A4GL_field_name_match with %p", fld);
      if (A4GL_field_name_match (fld, s))
	{
	  A4GL_debug ("Got a A4GL_match - returning %p", fld);
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
A4GL_set_infield_from_stack (void)
{
  A4GL_debug ("**** CHANGED FIELD ****");
  inp_current_field = A4GL_pop_long ();
  A4GL_debug ("New field :---> %p", inp_current_field);
}


/**
 * @return The current field number.
 */
int
A4GL_get_curr_infield (void)
{
  return inp_current_field;
}

/**
 * 4GL CALL
 * @todo Describe function
 */
int
A4GL_fgl_infield (char *s, int a)
{
  struct s_form_dets *f;
  A4GL_debug ("fgl_infield - looking for %s", s);


  f = A4GL_get_curr_form ();

  A4GL_debug ("Current field = %p\n", current_field (f->form));
  A4GL_debug ("Current field = %p\n", f->currentfield);

  /* if (A4GL_scan_for_field (s) == current_field (f->form)) { */
  if (A4GL_scan_for_field (s) == (FIELD *) inp_current_field)
    {
      A4GL_debug ("I'm in %s\n", s);
      return 1;
    }

  A4GL_debug ("I'm not in %s\n", s);
  return 0;
}



/**
 * 4GL CALL
 * @todo Describe function
 */
int
A4GL_fgl_getfldbuf_ap (char *s, int n)
{
  struct s_form_dets *f;
  FIELD *fld;


  A4GL_debug ("In fgl_getfldbuf - @todo ALLOW MORE THAN ONE FIELD");
  f = A4GL_get_curr_form ();
  A4GL_debug ("fld_getfldbuf    f=%p", f);

  if (f == 0)
    {
      A4GL_debug ("No current form...");
      A4GL_exitwith ("No current form");
      return -1;
    }
  fld = (FIELD *) A4GL_scan_for_field (s);
  if (fld == 0)
    {
      A4GL_exitwith ("Field name not found on form");
      return -1;
    }
  A4GL_push_char (field_buffer (fld, 0));
  return 1;
}




/**
 *
 * @todo Describe function
 */
int
A4GL_key_prompt (int a, FORM * mform, struct s_prompt *prompt)
{
  FIELD *f;
  f = current_field (mform);

  m_lastkey = a;
  A4GL_debug ("In proc_key_prompt.... for %d", a);
  switch (a)
    {
    case 18:
      A4GL_mja_wrefresh (stdscr);
      A4GL_mja_wrefresh (currwin);
      A4GL_mja_refresh ();
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
      A4GL_debug ("Req del prev");
      if (A4GL_get_curr_field_col (mform))
	{
	  A4GL_int_form_driver (mform, REQ_DEL_PREV);
	  A4GL_debug ("Done...");
	}
      return 0;

    case 24:
      A4GL_int_form_driver (mform, REQ_DEL_CHAR);
      return 0;

    case '	':
    case KEY_ENTER:
    case 13:
    case 10:
    case KEY_DOWN:
#ifdef DEBUG
      A4GL_debug ("Next field in a prompt - they must mean enter");
#endif
      return 10;

    case KEY_LEFT:
      A4GL_int_form_driver (mform, REQ_PREV_CHAR);
      return 0;

    case KEY_RIGHT:
      A4GL_int_form_driver (mform, REQ_NEXT_CHAR);
      return 0;

    case 4:
      A4GL_int_form_driver (mform, REQ_CLR_FIELD);
      return 0;
    }

  /* A4GL_mja_refresh (); */

  if (a == A4GL_key_val ("HELP"))
    {
      aclfgl_a4gl_show_help (prompt->h);
      a = 0;
    }

  A4GL_debug ("Returning %d from proc_key_prompt\n", a);
  return a;
}


/**
 *
 * @todo Describe function
 */
void
A4GL_reset_delims (struct s_form_dets *formdets, char *delims)
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
      A4GL_mja_set_field_buffer ((FIELD *) formdets->fileform->metrics.
				 metrics_val[a].dlm1, 0, sbuff0);
      A4GL_mja_set_field_buffer ((FIELD *) formdets->fileform->metrics.
				 metrics_val[a].dlm2, 0, sbuff1);
    }
}


/**
 *
 * @todo Describe function
 */
void
A4GL_debug_print_field_opts (FIELD * a)
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
  A4GL_debug ("Field %p attribs= %s:", a, str);
}



/**
 *
 * @todo Describe function
 */
int
A4GL_page_for_field (struct s_screenio *s, FIELD * f)
{
  int a;
  int metric_no;
  for (a = 0; s->field_list[a]; a++)
    {
      if (f == s->field_list[a])
	{
	  metric_no = A4GL_get_metric_no (s->currform, s->field_list[a]);
	  A4GL_debug ("FIELD LIST : %p %d", s->field_list[a],
		      s->currform->fileform->metrics.metrics_val[metric_no].
		      scr);
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
A4GL_page_for_cfield (struct s_screenio *s)
{
  FIELD *f;
  int a;
  int metric_no;
  f = current_field (s->currform->form);
  for (a = 0; s->field_list[a]; a++)
    {
      if (f == s->field_list[a])
	{
	  metric_no = A4GL_get_metric_no (s->currform, s->field_list[a]);
	  A4GL_debug ("FIELD LIST : %p %d", s->field_list[a],
		      s->currform->fileform->metrics.metrics_val[metric_no].
		      scr);
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
A4GL_page_for_nfield (struct s_screenio *s)
{
  FIELD *f;
  int a;
  int metric_no;
  A4GL_debug ("In A4GL_page_for_nfield %p");
  f = current_field (s->currform->form);
  A4GL_debug ("Current field %p", f);

  for (a = 0; s->field_list[a]; a++)
    {
      if (f == s->field_list[a])
	{
	  a++;
	  if (s->field_list[a] == 0)
	    a = 0;
	  metric_no = A4GL_get_metric_no (s->currform, s->field_list[a]);
	  A4GL_debug ("Metric_no=%d", metric_no);
	  A4GL_debug ("FIELD LIST : %p %d", s->field_list[a],
		      s->currform->fileform->metrics.metrics_val[metric_no].
		      scr);
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
A4GL_page_for_pfield (struct s_screenio *s)
{
  FIELD *f;
  int a, b;
  int metric_no;
  f = current_field (s->currform->form);
  A4GL_debug ("page for previous FIELD f=%p", f);
  for (a = 0; s->field_list[a]; a++)
    {
      if (f == s->field_list[a])
	{
	  b = a - 1;
	  if (a <= 0)
	    {
	      A4GL_debug ("field is at end of list");
	      for (b = 0; s->field_list[b + 1]; b++);
	      A4GL_debug ("setting a to %d", a);
	    }
	  A4GL_debug ("b=%d", b);
	  metric_no = A4GL_get_metric_no (s->currform, s->field_list[b]);
	  A4GL_debug ("FIELD LIST : %d %p %d", a, s->field_list[b],
		      s->currform->fileform->metrics.metrics_val[metric_no].
		      scr);
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
A4GL_copy_field_data (struct s_form_dets *form)
{
  char buff[80] = "";
  char buff2[80] = "";
  FORM *mform;
  int x, y;
  struct struct_scr_field *fprop;
  mform = form->form;
  A4GL_debug ("form->currentfield=%p", form->currentfield);
  if (form->currentfield != 0)
    if (field_userptr (form->currentfield) != 0)
      {
	A4GL_debug ("Is a proper field");
	fprop =
	  (struct struct_scr_field *) (field_userptr (form->currentfield));
	A4GL_debug ("fprop=%p", fprop);
	if (fprop != 0)
	  {
	    A4GL_debug ("check Datatype ");
	    if (((fprop->datatype != DTYPE_CHAR) & (DTYPE_MASK))
		&& (field_status (form->currentfield)))
	      {
		A4GL_debug ("modify size dtype");
		A4GL_debug ("modfy size for metric %d",
			    A4GL_get_metric_for (form, form->currentfield));
		A4GL_modify_size (&buff[4],
				  form->fileform->metrics.
				  metrics_val[A4GL_get_metric_for
					      (form, form->currentfield)].w);
		A4GL_debug ("modfy size done -> '%s'", &buff[4]);

		strcpy (&buff[4], field_buffer (form->currentfield, 0));
		A4GL_debug ("copy 1");
		strcpy (buff2, &buff[4]);
		A4GL_debug ("copy 2");
		A4GL_debug ("trim buff");
		A4GL_trim (buff2);
		getsyx (y, x);

		A4GL_debug ("CHange y=%d, x=%d", y, x);
		A4GL_debug ("stack manip buff2='%s'", buff2);
		if (strlen (buff2) > 0)
		  {
#ifdef DEBUG
		    A4GL_debug ("Pushing param %p");
#endif
		    A4GL_push_param (buff2, DTYPE_CHAR);
		    if (A4GL_pop_param
			(buff, fprop->datatype,
			 A4GL_get_field_width (form->currentfield)))
		      {
#ifdef DEBUG
			A4GL_debug ("Pushing param %p %d", buff,
				    fprop->datatype);
#endif
			A4GL_push_param (buff, fprop->datatype);
			if (A4GL_has_str_attribute (fprop, FA_S_FORMAT))
			  {
			    A4GL_push_char (A4GL_get_str_attribute
					    (fprop, FA_S_FORMAT));
			    A4GL_pushop (OP_USING);
			  }
			A4GL_pop_param (buff, DTYPE_CHAR,
					A4GL_get_field_width (form->
							      currentfield));
			A4GL_mja_set_field_buffer (form->currentfield, 0,
						   buff);
		      }
		    else
		      {
			//push_char(acl_getenv("FIELD_ERROR_MSG"));
			//display_error(1,0);
			A4GL_error_nobox (acl_getenv ("FIELD_ERROR_MSG"), 0);
			A4GL_mja_set_field_buffer (form->currentfield, 0,
						   " ");
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
A4GL_get_curr_field_col (FORM * mform)
{
  return mform->curcol;
}


/**
 *
 * @todo Describe function
 */
void
A4GL_int_form_driver (FORM * form, int a)
{
  int field_pos;
  FIELD *f;
  char buff[1024];
  char buff2[1024];
  int fd_ok;

  A4GL_debug ("int_form_driver called with %p - %d", form, a);

  if (a <= 27)
    {
      A4GL_debug ("Control Character or ESC");
      return;
    }

  field_pos = A4GL_get_curr_field_col (form);
  f = current_field (form);
  A4GL_debug ("int_form_driver0..  currentfield=%p status = %d", f,
	      field_status (f));

  if (f)
    {
      strcpy (buff, field_buffer (f, 0));
    }
  else
    {
      strcpy (buff, "");
    }
  A4GL_debug ("int_form_driver1..  currentfield=%p status = %d", f,
	      field_status (f));

  A4GL_debug ("MJA Calling form_driver with %d for form %p", a, form);

  fd_ok = form_driver (form, a);
  A4GL_debug ("int_form_driver2..  currentfield=%p status = %d", f,
	      field_status (f));
  if (fd_ok != E_OK)
    {
      A4GL_debug ("Problem in calling form_driver %p %d - returns %d", form,
		  a, fd_ok);
      switch (fd_ok)
	{
	case E_SYSTEM_ERROR:
	case E_BAD_STATE:
	case E_BAD_ARGUMENT:
	case E_NOT_POSTED:
	case E_UNKNOWN_COMMAND:
	case E_INVALID_FIELD:
	  A4GL_exitwith ("Form driver complaint");
	  return;
	}
    }

  A4GL_debug ("int_form_driver3..  currentfield=%p status = %d", f,
	      field_status (f));
  if (f != current_field (form))
    {
      A4GL_debug ("Resetting focus");
      f = current_field (form);
      A4GL_gui_setfocus ((long) f);
    }

  A4GL_debug ("int_form_driver4..  currentfield=%p status = %d", f,
	      field_status (f));
  if (field_pos != A4GL_get_curr_field_col (form))
    {
      A4GL_debug ("Resetting position");
      field_pos = A4GL_get_curr_field_col (form);
      A4GL_gui_setposition (field_pos);
    }

  A4GL_debug ("int_form_driver5..  currentfield=%p status = %d", f,
	      field_status (f));
  if (f)
    {
      strcpy (buff2, field_buffer (f, 0));
    }
  else
    {
      strcpy (buff2, "");
    }

  A4GL_debug ("int_form_driver6..  currentfield=%p status = %d", f,
	      field_status (f));
  if (strcmp (buff, buff2) != 0)
    {
      A4GL_gui_setbuff (f, buff2);
    }
  if (a != REQ_VALIDATION)
    A4GL_int_form_driver (form, REQ_VALIDATION);

}


/**
 * 4GL CALL
 * @todo Describe function
 */
void
A4GL_clr_form (int to_default)
{
  struct s_form_dets *formdets;
  int a;
  int metric_no;
  struct struct_metrics *k;
  FIELD *f;
  int fno;
  int rn;

  A4GLSQL_set_status (0, 0);

  formdets = A4GL_get_curr_form ();

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

	  A4GL_set_field_attr_with_attr ((FIELD *) formdets->fileform->
					 metrics.metrics_val[metric_no].field,
					 0);

	  if (!to_default)
	    {
	      A4GL_debug ("Blanking field %p MJAMJAMJA", f);
	      A4GL_mja_set_field_buffer (f, 0, "");
	    }
	  else
	    {
	      struct struct_scr_field *prop;
	      prop = (struct struct_scr_field *) field_userptr (f);
	      A4GL_mja_set_field_buffer (f, 0,
					 A4GL_replace_sql_var
					 (A4GL_strip_quotes
					  (A4GL_get_str_attribute
					   (prop, FA_S_DEFAULT))));
	    }
	}

    }

//A4GL_mja_wrefresh (A4GL_get_curr_win());
  A4GL_zrefresh ();
}


/**
 * 4GL CALL
 * @todo Describe function
 */
void
A4GL_disp_form_fields_ap (int n, int attr, char *formname, va_list * ap)
{
  A4GL_exitwith ("Not implemented for TUI mode");
}


/**
 *
 * @todo Describe function
 */
int
A4GL_curr_metric_is_last (void)
{
  struct s_form_dets *form;
  int a;
  form = A4GL_get_curr_form ();
  a = A4GL_get_curr_metric (form);

  if (a == -1)
    {
      return 0;
      A4GL_exitwith ("No valid metric....");
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
A4GL_curr_metric_is_first (void)
{
  struct s_form_dets *form;
  int a;
  form = A4GL_get_curr_form ();
  a = A4GL_get_curr_metric (form);
  if (a == -1)
    {
      return 0;
      A4GL_exitwith ("No valid metric....");
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
A4GL_curr_metric_is_veryfirst (void)
{
  struct s_form_dets *form;
  int a;
  form = A4GL_get_curr_form ();
  a = A4GL_get_curr_metric (form);
  if (a == -1)
    {
      return 0;
      A4GL_error_box ("No valid metric....", 0);
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
A4GL_curr_metric_is_verylast (void)
{
  struct s_form_dets *form;
  int a;
  form = A4GL_get_curr_form ();
  a = A4GL_get_curr_metric (form);
  if (a == -1)
    {
      return 0;
      A4GL_error_box ("No valid metric....", 0);
      exit (0);
    }

  if (form->fileform->metrics.metrics_val[a].pos_code & POS_VERY_LAST)
    return 1;

  return 0;
}


int
A4GL_curr_metric_is_used_last_s_screenio (struct s_screenio *s, FIELD * f)
{
  int a;
  int fno = -1;

  for (a = 0; a <= s->nfields; a++)
    {
      A4GL_debug ("Current field=%p field_list=%p", f, s->field_list[a]);
      if (f == s->field_list[a])
	fno = a;
    }

  A4GL_debug ("curr_metric_is_used_last_s_screenio fno=%d nfields=%d", fno,
	      s->nfields);
  if (fno == s->nfields)
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
aclfgl_set_page (int n)
{
  int b;
  struct s_form_dets *f;
  b = A4GL_pop_int ();
  f = A4GL_get_curr_form ();
  set_form_page (f->form, b);
  refresh ();
  return 0;
}

/**
 *
 * @todo Describe function
 */
int
aclfgl_get_page (int n)
{
  struct s_form_dets *f;
  f = A4GL_get_curr_form ();
  A4GL_push_int (form_page (f->form));
  return 1;
}


/*
 * This function causes a SEGFAULT - useful for stopping the debugger!
*/
void
A4GL_bomb_out ()
{
  char *ptr = 0;
  *ptr = 0;
}



int
A4GL_fgl_fieldtouched_input_ap (struct s_screenio *s, va_list * ap)
{
  int a;
  int c;
  int b;
  FIELD **field_list;
  int found;
  c = A4GL_gen_field_chars_ap (&field_list, s->currform, ap);
  if (c >= 0)
    {
      for (a = 0; a <= c; a++)
	{
	  found = 0;
	  A4GL_debug ("fieldtouched FIELD : %p a=%d c=%d - status=%d\n",
		      field_list[a], a, c, field_status (field_list[a]));

	  // Have a look to see if we are currently inputing this one...
	  for (b = 0; b <= s->nfields; b++)
	    {
	      if (field_list[a] == field_list[b])
		found = 1;
	    }
	  if (!found)
	    {
	      // We don't appear to be...
	      A4GL_exitwith ("Field is not currently being input");
	      return 0;
	    }
	}
      A4GL_debug ("fieldtouched_input - checking field_status");

      for (a = 0; a <= c; a++)
	{
	  if (field_status (field_list[a]))
	    {
	      A4GL_debug ("fieldtouched Field status is set for %p",
			  field_list[a]);
	      free (field_list);
	      return 1;
	    }
	}
      A4GL_debug ("fieldtouched Field status not set for any..");
      free (field_list);
      return 0;

    }
  else
    {
      A4GL_exitwith ("field_touched called with no fields...");
      return 0;
    }
}

/* ================================ EOF ============================== */

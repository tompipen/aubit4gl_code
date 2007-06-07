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
# | contact afalout@ihug.co.nz                                           |
# +----------------------------------------------------------------------+
#
# $Id: ioform.c,v 1.172 2007-06-07 10:25:53 mikeaubury Exp $
#*/
#ifndef lint
	static char const module_id[] =
		"$Id: ioform.c,v 1.172 2007-06-07 10:25:53 mikeaubury Exp $";
#endif

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
#include <ctype.h>
static void chk_for_picture (FIELD * f, char *buff);
int A4GL_field_is_noentry (int doing_construct, struct struct_scr_field *f);
int A4GL_gen_field_list_from_slist_internal (FIELD *** field_list,
					     struct s_form_dets *formdets,
					     int max_number,
					     struct s_field_name_list *list);
static int get_inc_quotes(int a) ;

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

// In some circumstances - Informix allows 
// the table prefix for a column in a field to be ignored.
// In order to emulate this - we need to toggle this ability
// At the moment - this is only set within the field_touched routine
// We might need to add it to others later..
// See mantis bug 1014....
int field_status_strip_tabname=0; 



extern WINDOW *currwin;
//int tab_cnt = 0;
//int srec_cnt = 0;
//char delimiters[4];
char *a_strchr(char *s,char c);
char *A4GL_fld_data_ignore_format (struct struct_scr_field *fprop,
				   char *fld_data);
void A4GL_set_field_attr_with_attr_already_determined (FIELD * field,
						       int attr,
						       int cmd_type);
int A4GL_check_and_copy_field_to_data_area (struct s_form_dets *form,
					    struct struct_scr_field *fprop,
					    char *fld_data, char *data_area);
//int A4GL_get_field_width_w (void *f,int need_height);
void A4GL_set_infield_from_parameter (long a);
void A4GL_set_curr_infield (void *a);

//int lastc = 0;
//int nline;
//int ioform_fline;
//int ncol;
//char dbname[64];
void *inp_current_field = 0;
char * get_print_field_opts_as_string (FIELD * a);

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/






void A4GL_clr_field (FIELD * f);

static void A4GL_set_field_pop_attr (FIELD * field, int attr, int cmd_type);

static long A4GL_get_curr_infield (void);
static void A4GL_mja_set_field_buffer_contrl (FIELD * field, int nbuff,
					      int ch);
static void A4GL_set_field_colour_attr (FIELD * field, int do_reverse,
					int colour);
static void A4GL_mja_set_field_buffer (FIELD * field, int nbuff, char *buff);
static void A4GL_set_field_attr (FIELD * field);


int A4GL_field_name_match (FIELD * f, char *s);
static int A4GL_find_field_no (FIELD * f, struct s_screenio *sio);
int A4GL_do_after_field (FIELD * f, struct s_screenio *sio);
static int A4GL_get_metric_for (struct s_form_dets *form, FIELD * f);
int A4GL_wcswidth(char *mbs);		/* utf8 */

static int local_chk_field(struct s_form_dets *form,FIELD *f) ;

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
  int is_graphics = 0;
  //l = strlen (label);
  l = A4GL_wcswidth (label);
  A4GL_debug ("A4GL_make_label : '%s' l=%d", label, l);

  if (strlen(label) == 2 && label[0] == '\n')
    {
      A4GL_debug ("Making graphic character %c @ frow=%d fcol=%d\n", label[1],
		  frow, fcol);
      f = new_field (1, 1, frow, fcol, 0, 0);
    }
  else
    {
      A4GL_debug ("Making normal label '%s' @ frow=%d fcol=%d\n", label, frow,
		  fcol);
      f = new_field (1, l, frow, fcol, 0, 0);
    }

  if (f == 0)
    {
      A4GL_exitwith ("Unable to create field");
      return 0;
    }

  if (strlen(label) == 2 && label[0] == '\n')
    {
      is_graphics = 1;

      if (A4GL_isyes (acl_getenv ("SIMPLE_GRAPHICS")))
	{
	  switch (label[1])
	    {
	    case 'p':
	      A4GL_mja_set_field_buffer_contrl (f, 0, '+');
	      break;
	    case 'q':
	      A4GL_mja_set_field_buffer_contrl (f, 0, '+');
	      break;
	    case 'b':
	      A4GL_mja_set_field_buffer_contrl (f, 0, '+');
	      break;
	    case 'd':
	      A4GL_mja_set_field_buffer_contrl (f, 0, '+');
	      break;
	    case '-':
	      A4GL_mja_set_field_buffer_contrl (f, 0, '-');
	      break;
	    case '|':
	      A4GL_mja_set_field_buffer_contrl (f, 0, '|');
	      break;
	    default:
	      A4GL_debug ("Unknown graphic : %c", label[1]);
	      is_graphics = 0;
	    }
	}
      else
	{
	  if (A4GL_isno (acl_getenv ("EXTENDED_GRAPHICS")))
	    {
	      set_field_back (f, A_ALTCHARSET);
	      switch (label[1])
		{
		case 'p':
		  A4GL_mja_set_field_buffer_contrl (f, 0, ACS_ULCORNER);
		  break;
		case 'q':
		  A4GL_mja_set_field_buffer_contrl (f, 0, ACS_URCORNER);
		  break;
		case 'b':
		  A4GL_mja_set_field_buffer_contrl (f, 0, ACS_LLCORNER);
		  break;
		case 'd':
		  A4GL_mja_set_field_buffer_contrl (f, 0, ACS_LRCORNER);
		  break;
		case '-':
		  A4GL_mja_set_field_buffer_contrl (f, 0, ACS_HLINE);
		  break;
		case '|':
		  A4GL_mja_set_field_buffer_contrl (f, 0, ACS_VLINE);
		  break;
		default:
		  A4GL_debug ("Unknown graphic : %c", label[1]);
		  is_graphics = 0;
		}
	    }
	  else
	    {
	      set_field_back (f, A_ALTCHARSET);
	      A4GL_debug ("Extended graphics : %c ACS_HLINE=%d", label[1],
			  ACS_HLINE);
	      switch (label[1])
		{
		case 'p':
		  A4GL_mja_set_field_buffer_contrl (f, 0, ACS_ULCORNER);
		  break;
		case 'q':
		  A4GL_mja_set_field_buffer_contrl (f, 0, ACS_URCORNER);
		  break;
		case 'b':
		  A4GL_mja_set_field_buffer_contrl (f, 0, ACS_LLCORNER);
		  break;
		case 'd':
		  A4GL_mja_set_field_buffer_contrl (f, 0, ACS_LRCORNER);
		  break;
		case '-':
		  A4GL_mja_set_field_buffer_contrl (f, 0, ACS_HLINE);
		  break;
		case '|':
		  A4GL_mja_set_field_buffer_contrl (f, 0, ACS_VLINE);
		  break;

		case '>':
		  A4GL_mja_set_field_buffer_contrl (f, 0, ACS_LTEE);
		  break;
		case '<':
		  A4GL_mja_set_field_buffer_contrl (f, 0, ACS_RTEE);
		  break;
		case '^':
		  A4GL_mja_set_field_buffer_contrl (f, 0, ACS_BTEE);
		  break;
		case 'v':
		case 'V':
		  A4GL_mja_set_field_buffer_contrl (f, 0, ACS_TTEE);
		  break;
		case '+':
		  A4GL_mja_set_field_buffer_contrl (f, 0, ACS_PLUS);
		  break;
		default:
		  A4GL_debug ("Unknown graphic : %c", label[1]);
		  is_graphics = 0;
		}
	    }
	}
      if (is_graphics)
	{
	  local_set_field_opts (f, local_field_opts (f) & ~O_ACTIVE);
	  return f;
	}
      else
	{
	  label[0] = label[1];
	  label[1] = label[0];
	}
    }



  if (f)
    {
      A4GL_debug ("99 set field buffer to label = **%s**", label);
      set_field_buffer (f, 0, label);
      local_set_field_opts (f, local_field_opts (f) & ~O_ACTIVE);
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
 *
 * @todo Describe function
 *  @todo Validate the calls to A4GL_make_label that alocates space to a FIELD
 *  struct and assigns the pointer to integers.
 */
int
UILIB_A4GL_read_metrics (void *formdetsv)
{
  struct s_form_dets *formdets;
  int a, n;
  int last_field = -1;
  int cnt = 0;
  int lscr = 1;
  int lfieldscr = -1;
  char delims[3][2];
  formdets = formdetsv;
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
      A4GL_debug ("checking label %s\n",
		  formdets->fileform->metrics.metrics_val[a].label);


      if (strlen (formdets->fileform->metrics.metrics_val[a].label) != 0)
	{
	  formdets->fileform->metrics.metrics_val[a].field =
	    (long) A4GL_make_label (formdets->fileform->metrics.metrics_val[a].
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
	    (long) A4GL_make_field (formdets->fileform->metrics.metrics_val[a].
				   y,
				   formdets->fileform->metrics.metrics_val[a].
				   x,
				   formdets->fileform->metrics.metrics_val[a].
				   h,
				   formdets->fileform->metrics.metrics_val[a].
				   w);
	  formdets->form_fields[cnt++] =
	    (FIELD *) formdets->fileform->metrics.metrics_val[a].field;
	  formdets->form_fields[cnt] = 0;
	  formdets->fileform->metrics.metrics_val[a].dlm1 =(long)
	    A4GL_make_label (formdets->fileform->metrics.metrics_val[a].
				   y,
				   formdets->fileform->metrics.metrics_val[a].
				   x - 1, delims[0]);
	  formdets->form_fields[cnt++] =
	    (FIELD *) formdets->fileform->metrics.metrics_val[a].dlm1;
	  formdets->fileform->metrics.metrics_val[a].dlm2 =(long)
	     A4GL_make_label (formdets->fileform->metrics.metrics_val[a].
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
  struct struct_scr_field *fprop;

  int done = 0;

  fprop = (struct struct_scr_field *) (field_userptr (f));
  A4GL_debug ("In def attrib f=%p", f);

  if (fprop)
    {
      if (A4GL_has_str_attribute (fprop, FA_S_PICTURE))
	{
	  A4GL_debug ("ZZZZ - SET OPTS");
	  local_set_field_opts (f, O_VISIBLE | O_ACTIVE | O_PUBLIC | O_EDIT);
	  done = 1;
	}
    }



  if (done == 0)
    {

      A4GL_debug ("MMMM DTYPE & 255 = %d", dtype);

      if ((dtype & 255) == 0)
	{
	  A4GL_debug ("ZZZZ - SET OPTS");
	  local_set_field_opts (f, O_VISIBLE | O_ACTIVE | O_PUBLIC | O_EDIT);
	  local_field_opts_off (f, O_BLANK);
	}
      else
	{
	  A4GL_debug ("ZZZZ - SET OPTS");
	  A4GL_debug ("BLANK BLANK");
	  local_set_field_opts (f,
			  O_VISIBLE | O_ACTIVE | O_PUBLIC | O_EDIT | O_BLANK);
	}
    }


  //set_field_fore (f, A4GL_colour_code (7));
  //set_field_back (f, A4GL_colour_code (7));
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
      A4GL_debug ("ZZZZ - SET OPTS");
      local_field_opts_on (field, O_AUTOSKIP);
    }

  if (A4GL_has_bool_attribute (f, FA_B_INVISIBLE))
    {
      A4GL_debug ("Invisible ***");
      A4GL_debug ("ZZZZ - SET OPTS");
      local_field_opts_off (field, O_PUBLIC);
    }

  if (f->dynamic != 0)
    {
      A4GL_debug ("ZZZZ - SET OPTS - STATIC OFF");
      local_field_opts_off (field, O_STATIC);


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

  if (A4GL_field_is_noentry (0, f))
    {
      A4GL_debug ("No entry");
      A4GL_debug
	("ZZZZ - SET OPTS - DISABLE ::::::::::::::::::::::::::::::::::::::::::::;;;");
      A4GL_debug ("removed- this may cause problems.....");


    }



  if (A4GL_has_bool_attribute (f, FA_B_REQUIRED))
    {
      A4GL_debug ("ZZZZ - SET OPTS");
      local_field_opts_off (field, O_NULLOK);
    }
  else
    {
      A4GL_debug ("ZZZZ - SET OPTS");
      local_field_opts_on (field, O_NULLOK);
    }

  if (A4GL_has_bool_attribute (f, FA_B_COMPRESS) || A4GL_has_bool_attribute (f, FA_B_WORDWRAP))
    {
      A4GL_debug ("ZZZZ - SET OPTS");
      local_field_opts_on (field, O_WRAP);
    }


}

/**
 *
 * @todo Describe function
 */
void
A4GL_set_field_attr_with_attr (FIELD * field, int attr, int cmd_type)
{
  int r;
  int nattr;
  struct struct_scr_field *f;
  f = (struct struct_scr_field *) (field_userptr (field));

  nattr = A4GL_determine_attribute (cmd_type, attr, f, 0);

  A4GL_debug ("Passed in attribute: %x, determined attribute should be %x", attr, nattr);

  attr = nattr;

  if (attr & AUBIT_ATTR_REVERSE) r = 1;
  else r = 0; 

  A4GL_debug ("MJA Calling A4GL_set_field_colour_attr - do_reverse=%d attr=%d", r, attr);
  A4GL_set_field_colour_attr (field, r, attr);
}

void
A4GL_set_field_attr_with_attr_already_determined (FIELD * field, int attr,
						  int cmd_type)
{
  int r;
  struct struct_scr_field *f;
  f = (struct struct_scr_field *) (field_userptr (field));


  if (attr & AUBIT_ATTR_REVERSE)
    r = 1;
  else
    r = 0;
  A4GL_debug
    ("MJA Calling A4GL_set_field_colour_attr - do_reverse=%d attr=%d", r,
     attr);
  A4GL_set_field_colour_attr (field, r, attr);
}

/**
 *
 * @todo Describe function
 */
void
A4GL_set_field_colour_attr (FIELD * field, int do_reverse, int colour)
{
  struct struct_scr_field *f;
  int fg;
  int bg;
  f = (struct struct_scr_field *) (field_userptr (field));
  A4GL_debug ("set_field_colour_attr - do_reverse=%d colour=%d - %d\n",
	      do_reverse, colour, A4GL_decode_colour_attr_aubit (colour));

  if (colour & AUBIT_ATTR_REVERSE && do_reverse == 0)
    {;
    }				// Maybe we should warn on these
  if (!(colour & AUBIT_ATTR_REVERSE) && do_reverse == 1)
    {;
    }				// Maybe we should warn on these

  fg = A4GL_decode_aubit_attr (colour, 'f');
  bg = A4GL_decode_aubit_attr (colour, 'B');
  set_field_fore (field, fg);
  set_field_back (field, bg);

  A4GL_debug ("FG=%x BG=%x", fg, bg);

  return;


  colour = colour & 0xff00;


  if (do_reverse && colour == AUBIT_COLOR_WHITE)
    {
      A4GL_debug ("XX1 REVERSE");
      A4GL_debug ("DOINGREVERSE");
      set_field_fore (field, A_REVERSE);
      set_field_back (field, A_REVERSE);
    }


  if (do_reverse && colour != AUBIT_COLOR_WHITE)
    {
      A4GL_debug ("XX2 REVERSE");
      A4GL_debug ("DOINGREVERSE");
      set_field_back (field,
		      A4GL_decode_colour_attr_aubit (colour) | A_REVERSE);
      set_field_fore (field,
		      A4GL_decode_colour_attr_aubit (colour) | A_REVERSE);
    }

  if (do_reverse == 0 && colour != AUBIT_COLOR_WHITE)
    {
      A4GL_debug ("XX3 NO REVERSE & COLOUR %d", colour);
      set_field_fore (field, A4GL_decode_colour_attr_aubit (colour));
      set_field_back (field, A4GL_decode_colour_attr_aubit (colour));
    }

  if (do_reverse == 0 && colour == AUBIT_COLOR_WHITE)
    {
      A4GL_debug ("XX3 NO REVERSE & NO COLOUR");
      set_field_fore (field, A4GL_decode_colour_attr_aubit (colour));
      set_field_back (field, A4GL_decode_colour_attr_aubit (colour));
    }

  A4GL_debug ("Returning");
}


/**
 *
 * @todo Describe function
 */
void
A4GL_set_init_value (FIELD * f, void *ptr, int dtype)
{
  char *ff;

  A4GL_debug ("A4GL_set_init_value %p %x", ptr, dtype);
  if (ptr)
    {
      A4GL_push_param (ptr, dtype);
      A4GL_debug ("Calling display_field_contents");
      A4GL_display_field_contents (f, dtype & DTYPE_MASK, DECODE_SIZE (dtype),
				   ptr);
      return;
    }




  A4GL_debug ("field width=%d", A4GL_get_field_width (f));
  if (ptr != 0)
    {
      A4GL_push_param (ptr, dtype);
      ff = acl_malloc2 (A4GL_get_field_width (f) + 1);
      A4GL_pop_char (ff, A4GL_get_field_width (f));
    }
  else
    {
      int l;
      l=A4GL_get_field_width (f);
      ff = acl_malloc2 (l+1);
      memset(ff,' ',l);
      ff[l] = 0;
    }

  A4GL_mja_set_field_buffer (f, 0, ff);
  acl_free (ff);
  A4GL_debug ("Init complete");
}

/**
 *
 * @todo Describe function
 */
int
UILIB_A4GL_read_fields (void *formdetsv)
{
  struct s_form_dets *formdets;
  int a, n;
  int n1, a1;
  int metric_no;
  char *ptr;
  formdets = formdetsv;
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
  A4GL_debug ("Start form - %p %p", s, s->form);

  A4GL_int_form_driver (s->form, REQ_FIRST_PAGE);
  A4GL_int_form_driver (s->form, REQ_FIRST_FIELD);
  pos_form_cursor (s->form);

  s->form_details.insmode = 0;

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

  FORM *mform;
  struct s_form_dets *form;

  mform = sio->currform->form;
  A4GL_debug ("CHeck fields 1 m=%d", m);
  form = sio->currform;
  A4GL_debug ("CHeck fields 2 currentfield=%p status = %d",
	      form->currentfield, field_status (form->currentfield));

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
      A4GL_debug ("Is different");

      if (form->currentfield != 0)
	{
		int rval;
		rval=local_chk_field(form, form->currentfield);
		if (rval==-4) {
				  set_current_field (mform, form->currentfield);
		}
		return rval;
	}
    }


  return 0;
}


int chk_all_fields(struct s_screenio *sio) {
int a;

if  (sio->mode != MODE_CONSTRUCT) { 
	// Might need to do something similar for construct ? 
          for (a=0;a<=sio->nfields;a++)  {
                if (local_chk_field(sio->currform, sio->field_list[a])==-4) {
				return a;
                }
          }
}
return -1;

}


int local_chk_field(struct s_form_dets *form, FIELD *f) {
  char buff[8000] = "";
  char buff2[8000] = "";
  char buff3[8000] = "";
  int pprval;
  int x, y;
  struct struct_scr_field *fprop=0;

	  if (field_userptr (f) != 0)
	    {
	      A4GL_debug ("Is a proper field");
	      fprop = (struct struct_scr_field *) (field_userptr (f));
	      A4GL_debug ("fprop=%p", fprop);



	      if (fprop != 0)
		{


		  if ((fprop->datatype & DTYPE_MASK) != DTYPE_CHAR)
		    {



		      A4GL_modify_size (&buff[4], form->fileform->metrics.  metrics_val[A4GL_get_metric_for (form, f)].w);

		      strcpy (&buff[4], field_buffer (f, 0));

		      strcpy (buff2, &buff[4]);

		      if (A4GL_has_str_attribute (fprop, FA_S_PICTURE))
			{
			  int a;
			  int blank = 1;
			  char *picture;
			  picture =
			    A4GL_get_str_attribute (fprop, FA_S_PICTURE);
			  A4GL_debug ("HAS PICTURE MJA123 : %s", buff2);
			  for (a = 0; a < strlen (buff2); a++)
			    {
			      if (picture[a] == 'X' && buff2[a] != ' ')
				{
				  blank = 0;
				  break;
				}
			      if (picture[a] == 'A' && buff2[a] != ' ')
				{
				  blank = 0;
				  break;
				}
			      if (picture[a] == '#' && buff2[a] != ' ')
				{
				  blank = 0;
				  break;
				}
			    }
			  if (blank)
			    strcpy (buff2, "");
			}


		      A4GL_trim (buff2);
		      getsyx (y, x);
		      A4GL_trim (buff2);

		      if (strlen (buff2) == 0)
			{

			  if (A4GL_has_bool_attribute (fprop, FA_B_REQUIRED))
			    {
			      int allow_it_anyway = 0;

			      // We'll still allow it - so long as there is null in the include list
			      if (A4GL_has_str_attribute
				  (fprop, FA_S_INCLUDE))
				{
				  if (A4GL_check_field_for_include
				      ("",
				       A4GL_get_str_attribute (fprop,
							       FA_S_INCLUDE),
				       fprop->datatype))
				    {
				      allow_it_anyway = 1;
				    }
				}

			      if (!allow_it_anyway)
				{
				  // Well there wasn't - so it is required....
				  A4GL_error_nobox (acl_getenv ("FIELD_REQD_MSG"), 0);

				  //set_current_field (mform, form->currentfield);

				  return -4;
				}


			    }

			  // Could still be thrown out if we have an include without a null in it....
			  A4GL_debug ("X2222 MAYBE");
			  if (A4GL_has_str_attribute (fprop, FA_S_INCLUDE))
			    {
			      if (A4GL_check_field_for_include
				  ("",
				   A4GL_get_str_attribute (fprop,
							   FA_S_INCLUDE),
				   fprop->datatype))
				{
				  return 1;
				}
			      else
				{
				  A4GL_debug
				    ("X2222 Check for include has null...");
				  A4GL_error_nobox (acl_getenv
						    ("FIELD_INCL_MSG"), 0);
				  if (fprop != 0)
				    A4GL_comments (fprop);
				  return -4;
				}
			    }


			  return 0;
			}


		      A4GL_debug ("Pushing to validate : %s\n", buff2);





		      pprval = A4GL_check_and_copy_field_to_data_area (form, fprop, buff2, buff);


		      A4GL_debug ("pprval = %d\n", pprval);
		      if (!pprval)
			{
			  A4GL_error_nobox (acl_getenv ("FIELD_ERROR_MSG"),
					    0);
			  if (fprop != 0)
			    A4GL_comments (fprop);

			  if (A4GL_isyes
			      (acl_getenv ("A4GL_CLR_FIELD_ON_ERROR")))
			    {
			      A4GL_clr_field (f);
			    }
			  else
			    {
			      if (A4GL_isyes (acl_getenv ("FIRSTCOL_ONERR")))
				{
				  A4GL_int_form_driver (form->form, REQ_BEG_FIELD);
				}

			    }


			  //set_current_field (mform, form->currentfield);
			  return -4;
			}
		      else
			{
			  A4GL_debug ("pop_param returns ok...");
			}
		    }


		  strcpy (buff3, field_buffer (f, 0));

		  if (A4GL_has_str_attribute (fprop, FA_S_PICTURE))
		    {
		      int a;
		      int blank = 1;
		      char *picture;
		      picture = A4GL_get_str_attribute (fprop, FA_S_PICTURE);
		      for (a = 0; a < strlen (buff3); a++)
			{
			  if (picture[a] == 'X' && buff3[a] != ' ')
			    {
			      blank = 0;
			      break;
			    }
			  if (picture[a] == 'A' && buff3[a] != ' ')
			    {
			      blank = 0;
			      break;
			    }
			  if (picture[a] == '#' && buff3[a] != ' ')
			    {
			      blank = 0;
			      break;
			    }
			}
		      if (blank)
			strcpy (buff3, "");
		    }


		  if (A4GL_check_field_for_include
		      (buff3, A4GL_get_str_attribute (fprop, FA_S_INCLUDE),
		       fprop->datatype) == 0)
		    {
		      A4GL_debug ("Not in include list");
		      A4GL_error_nobox (acl_getenv ("FIELD_INCL_MSG"), 0);
		      //set_current_field (mform, form->currentfield);
		      return -4;
		    }


		  if (A4GL_has_bool_attribute (fprop, FA_B_REQUIRED))
		    {
		      char buff[8024];
		      strcpy (buff, field_buffer (f, 0));
		      A4GL_trim (buff);

		      if (strlen (buff) == 0)
			{
			  int allow_it_anyway = 0;

			  // We'll still allow it - so long as there is null in the include list
			  if (A4GL_has_str_attribute (fprop, FA_S_INCLUDE))
			    {
			      if (A4GL_check_field_for_include
				  ("",
				   A4GL_get_str_attribute (fprop,
							   FA_S_INCLUDE),
				   fprop->datatype))
				{
				  allow_it_anyway = 1;
				}
			    }
			  if (!allow_it_anyway)
			    {
			      A4GL_error_nobox (acl_getenv ("FIELD_REQD_MSG"), 0);
			      //set_current_field (mform, form->currentfield);
			      return -4;
			    }

			}
		    }

		  // Could still be thrown out if we have an include without a null in it....
		  if (A4GL_has_str_attribute (fprop, FA_S_INCLUDE))
		    {
		      if (A4GL_check_field_for_include
			  ("", A4GL_get_str_attribute (fprop, FA_S_INCLUDE),
			   fprop->datatype))
			{
			  return 1;
			}
		      else
			{
			  return 0;
			}
		    }




		  return 0;



		}

	    }

return 0;
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
  return x * y;
}


/**
 *
 * @todo Describe function
 */
int
A4GL_get_field_height (FIELD * f)
{
  int x, y, a;
  dynamic_field_info (f, &y, &x, &a);
  return y;
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
  A4GL_debug ("ZZZZ - SET OPTS");
  a = local_field_opts_off (f, O_ACTIVE);
  A4GL_debug ("a=%d", a);
  a += local_field_opts_off (f, O_EDIT);
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
  A4GL_debug ("ZZZZ - SET OPTS");
  a = local_field_opts_on (f, O_ACTIVE);
  A4GL_debug ("a=%d", a);
  a = local_field_opts_on (f, O_EDIT);
  if ((fprop->datatype & 255) != 0)
    {
      local_field_opts_on (f, O_BLANK);
    }
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
  int xx;
  A4GL_assertion (f == 0, "Field is zero in turn_field_on2");
  A4GL_debug ("Turn field on %p %d", f, a);
  fprop = (struct struct_scr_field *) (field_userptr (f));
  A4GL_assertion (fprop == 0, "Field has no properties");
  A4GL_debug ("turn_field_on2 a=%d fprop=%p", a, fprop);

  A4GL_debug ("Turn Field On %p %p", fprop->tabname, fprop->colname);
  A4GL_debug ("Turn Field On %s %s", fprop->tabname, fprop->colname);
  local_field_opts_on (f, O_ACTIVE);
  local_field_opts_on (f, O_EDIT);
  if ((fprop->datatype & 255) != 0)
    {
      local_field_opts_on (f, O_BLANK);
    }

  A4GL_set_field_attr (f);


  if (fprop->dynamic != 0) {
      set_max_field (f, 0);
  } else {
	int w;
  	if (!a) {
      		set_max_field (f, 0);
			return;
    	}
	w=A4GL_get_field_width_w (f,0);

  	xx = set_max_field (f, w);
	
	
  	if (xx != 0)
    	{
      		f->dcols = 0;
      		xx = set_max_field (f, w);
    	}
	
	A4GL_debug("set_max_field : %d\n",w);
  	if (xx != 0)
    	{
      	A4GL_debug ("Unable to change field width\n");
	A4GL_assertion(1,"Internal error - unable to change field width");
      	A4GL_exitwith ("Internal error - unable to change field width");
      	return;
    	}
  }


}


int
A4GL_get_field_width_w (void *f,int need_height)
{
  int w;
  int mno;
  struct s_form_dets *formdets;
  struct s_scr_field *fprop;
  fprop = (struct s_scr_field *) (field_userptr (f));

  formdets = UILIB_A4GL_get_curr_form (0);

  if (formdets == 0 || fprop == 0)
    {
      return A4GL_get_field_width (f);
    }
  mno=A4GL_get_metric_for (formdets, f);
  A4GL_debug("mno=%d formdets=%p f=%p\n",mno,formdets, f);
  A4GL_assertion(mno<0,"Invalid metric number");
  w = formdets->fileform->metrics.metrics_val[mno].w;
  if (need_height) {
  	if (formdets->fileform->metrics.metrics_val[A4GL_get_metric_for (formdets, f)].h>1) {
  		w*=formdets->fileform->metrics.metrics_val[A4GL_get_metric_for (formdets, f)].h;
  	}
  }

  return w;
}

void debug_print_field_opts(struct s_form_dets *formdets) {
int a;
if (formdets==0) return;

  for (a = 0; formdets->form_fields[a]; a++)
    {
	void *f;
  	struct struct_scr_field *field;
	f=formdets->form_fields[a];

      	field = (struct struct_scr_field *) (field_userptr (f));
	A4GL_debug("DPFO_FIELD %d BUFFER='%s' - OPTS=%x (%s) field_fore=%x field_back=%x",a,field_buffer(f,0), field_opts(f),get_print_field_opts_as_string(f), field_fore(f),field_back(f));
    }
}

void
A4GL_set_fields_sio (struct s_screenio *sio)
{
  int a;
  int nv;
  //int flg;
  //char buff[8048];
  struct s_form_dets *formdets;
  struct struct_scr_field *field;
  //struct struct_scr_field *prop;
  FIELD **field_list;
  //FIELD *firstfield = 0;
  int nofields;
  //int attr;
  //FIELD *was_current;
  int b;
	//void *f;


  formdets = sio->currform;
  if (formdets == 0)
    {
      A4GL_exitwith ("No form");
      return ;
    }

  nofields = sio->nfields;
  field_list = (FIELD **) sio->field_list;
  nv = sio->novars;

  debug_print_field_opts(formdets);

  for (a = 0; formdets->form_fields[a]; a++)
    {
    	int should_be_on=0;
	void *f;
	f=formdets->form_fields[a];
      	field = (struct struct_scr_field *) (field_userptr (formdets->form_fields[a]));

        if (field == 0) continue;

  	for (b = 0; b<=nofields ; b++)
    	{
		if (f==field_list[b]) {
			A4GL_debug("Should be on... %p",f);
			should_be_on++;
	 		break;
		}
    	} 

	if (should_be_on) {
      		A4GL_turn_field_on2 (f, sio->mode != MODE_CONSTRUCT);
	} else {
      		A4GL_turn_field_off (f);
	}

    }

  debug_print_field_opts(formdets);

}


/**
 * 4GL CALL
 * @todo Describe function
 */
int
UILIB_A4GL_set_fields (void *vsio)
{
  int wid;
  int a;
  int nv;
  int flg;
  char buff[8048];
  struct s_form_dets *formdets;
  struct struct_scr_field *field;
  struct struct_scr_field *prop;
int changed=0;
  FIELD **field_list;
  FIELD *firstfield = 0;
  int nofields;
  struct s_screenio *sio;
  FORM *mform;
  int attr;
  FIELD *was_current;

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
  A4GL_debug ("Mform=%p\n", sio->currform->form);
  mform = sio->currform->form;

  for (a = 0; formdets->form_fields[a] != 0; a++)
    {
      field = (struct struct_scr_field *) (field_userptr (formdets->form_fields[a]));
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
  if (sio->mode == MODE_CONSTRUCT)
    {
      int a;
      int need_fix = 0;
      // this may need explanding if the column contains a '*'
      for (a = 0; a < nv; a++)
	{
	  if (strcmp (sio->constr[a].colname, "*") == 0)
	    {			// It'll need expanding...
	      need_fix = 1;
	    }
	}
      if (need_fix)
	{
	  A4GL_exitwith ("Construct needs fixing to handle 'byname on tab.*'");
	  sio->nfields = 0;
	  return 0;
	}
    }

  if (nofields != nv - 1)
    {
      A4GL_debug
	("Number of fields (%d) is not the same as the number of vars (%d)",
	 nofields + 1, nv);
      A4GL_exitwith
	("Number of fields is not the same as the number of variables");
      sio->nfields = 0;
      return 0;
    }



  was_current = mform->current;
  mform->current = 0;
  mform->curcol = 0;


  for (a = 0; a < nv; a++)
    {

      if (field_list[a] == firstfield)
	{
	  firstfield = 0;
	}
      A4GL_debug ("loop through fields a=%d %p", a, field_list[a]);
      if (sio->mode==MODE_CONSTRUCT) {
			FIELD *f;
			FORM *frm;
			f=field_list[a];
			frm=f->form;


      }


      A4GL_turn_field_on2 (field_list[a], sio->mode != MODE_CONSTRUCT);

      if (wid)
	{
	  A4GL_debug ("99 wid set_init_value as in variable");
	  A4GL_set_init_value (field_list[a], sio->vars[a].ptr,
			       sio->vars[a].dtype +
			       ENCODE_SIZE (sio->vars[a].size));

	changed=0;

	}
      else
	{
	  prop = (struct struct_scr_field *) field_userptr (field_list[a]);
	  if (A4GL_has_str_attribute (prop, FA_S_DEFAULT)
	      && sio->mode != MODE_CONSTRUCT)
	    {
	      A4GL_debug ("99  set_init_value from form");
	      A4GL_debug ("default from form to '%s'",
			  A4GL_get_str_attribute (prop, FA_S_DEFAULT));

	      A4GL_set_init_value (field_list[a], A4GL_replace_sql_var (A4GL_strip_quotes (A4GL_get_str_attribute (prop, FA_S_DEFAULT))), 0);
		changed++;
      		//set_field_status (field_list[a], 1);
		

	    }
	  else
	    {
	      A4GL_debug ("99  set_init_value as nothing...");
		changed=1;
	      A4GL_set_init_value (field_list[a], 0, 0);
	    }
	}

      if (sio->mode != MODE_CONSTRUCT)
	{
	  prop = (struct struct_scr_field *) field_userptr (field_list[a]);

	
      		if (changed) { // default value used
	  		strcpy (buff, A4GL_fld_data_ignore_format (prop, field_buffer (field_list[a], 0)));

	  		A4GL_trim (buff);
		
	  		if (strlen (buff))
	    		A4GL_push_char (buff);
	  		else
	    		A4GL_push_null (sio->vars[a].dtype, sio->vars[a].size);	// @todo - check if its set to not null and return CHARs instead..
	  		A4GL_debug ("Calling pop_var2..");
		
	   		A4GL_pop_var2 (sio->vars[a].ptr, sio->vars[a].dtype, sio->vars[a].size);
		}
	


	}

      if (flg == 0)
	{
	  mform->current = was_current;
	  set_current_field (formdets->form, field_list[a]);
	  /*formdets->form_fields[z]); */
	  flg = 1;
	}


      prop = (struct struct_scr_field *) field_userptr (field_list[a]);

      attr = A4GL_determine_attribute (FGL_CMD_INPUT, sio->attrib, prop, 0);

      if (attr != 0)
	A4GL_set_field_attr_with_attr (field_list[a], attr, FGL_CMD_INPUT);

      set_field_status (field_list[a], 0);
      prop->flags = 0;
    }

  if (firstfield)
    A4GL_turn_field_off (firstfield);

  if (flg == 0)
    {
      A4GL_error_box ("NO active field\n", 0);
    }
           if (sio->mode==MODE_CONSTRUCT) {
		FORM *frm;
                        frm=sio->currform->form;



#ifdef NCURSES_VERSION
			// For some reason the window associated with 
			// a field isn't being cleared properly...
			// lets make sure it is....
			// build test 1253 demonstrates this...
			werase(frm->w);
#endif
      }
				

  UILIB_A4GL_zrefresh ();
  return 1;
}




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
  struct s_form_dets *fdets;
  int srec_no;
  int z;

  fdets = UILIB_A4GL_get_curr_form (1);
  A4GL_bname (s, tabname, colname);
  A4GL_debug ("field_name_match : '%s' '%s'", tabname, colname);

  field = (struct struct_scr_field *) (field_userptr (f));
  if (field == 0)
    return 0;


  if (tabname[0] != 0)
    {
      srec_no = A4GL_find_srec (fdets->fileform, tabname);
    }
  else
    {
      srec_no = -1;
    }

  A4GL_debug ("No srec_no...");
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
  if (srec_no == -1)
    return 0;

  A4GL_debug ("but - Have an srec_no...");

  A4GL_debug ("Match 2");
// Maybe its a screen record - not a table name....




  for (z = 0;
       z < fdets->fileform->records.records_val[srec_no].attribs.attribs_len;
       z++)
    {
      int attr_no;
      attr_no =
	fdets->fileform->records.records_val[srec_no].attribs.attribs_val[z];
      A4GL_debug ("attr_no=%d - %s %s", attr_no,
		  fdets->fileform->attributes.attributes_val[attr_no].tabname,
		  fdets->fileform->attributes.attributes_val[attr_no].
		  colname);
      if (strcmp
	  (fdets->fileform->attributes.attributes_val[attr_no].colname,
	   colname) == 0)
	{			// We've found our entry in the screen record
	  if (strcmp
	      (tabname,
	       fdets->fileform->attributes.attributes_val[attr_no].tabname) !=
	      0)
	    {
	      char buff[256];
	      sprintf (buff, "%s.%s",
		       fdets->fileform->attributes.attributes_val[attr_no].
		       tabname,
		       fdets->fileform->attributes.attributes_val[attr_no].
		       colname);
	      if (A4GL_field_name_match (f, buff))
		return 1;
	    }
	}
    }
  return 0;
}


/**
 * 4GL CALL
 * @todo Describe function
 */
int
UILIB_A4GL_disp_fields_ap (int n, int attr, va_list * ap)
{
  int a;
  int flg;
  struct s_form_dets *formdets;
  FIELD **field_list;
  int nofields;
  struct struct_scr_field *fprop;
  a4gl_status = 0;

  A4GL_chkwin ();
  A4GL_debug ("In disp_fields");
  formdets = UILIB_A4GL_get_curr_form (1);
#ifdef DEBUG
  {
    A4GL_debug ("Status=%d formdets=%p", a4gl_status, formdets);
  }
#endif
  if (a4gl_status != 0)
    return 0;
  flg = 0;

  A4GL_debug (" field_list = %p", &field_list);
#ifdef DEBUG
  {
    A4GL_debug ("Genfldlist 2");
  }
#endif
  A4GL_debug ("disp_fields");
  nofields = A4GL_gen_field_list (&field_list, formdets, n, ap);
  A4GL_debug ("Number of fields=%d ", nofields, n);

  if (nofields < 0)
    {
      A4GL_debug ("Failed to find fields");
      return 0;
    }

  for (a = nofields; a >= 0; a--)
    {
      A4GL_debug ("field_list[%d]=%p", a, field_list[a]);
      A4GL_debug_print_field_opts (field_list[a]);
      /* fldattr=field_opts(field_list[a]); */
      A4GL_debug ("MJA Calling A4GL_set_field_pop_attr - 1 - attr=%d", attr);




	A4GL_set_field_pop_attr (field_list[a], attr, FGL_CMD_DISPLAY_CMD);
      fprop = (struct struct_scr_field *) (field_userptr (field_list[a]));
      fprop->flags |= 2;



      /* rc=set_field_opts(field_list[a],fldattr); */
      A4GL_debug_print_field_opts (field_list[a]);
      A4GL_debug ("set_init_pop complete");
    }

  free(field_list);

  A4GL_mja_wrefresh (currwin);
  return 1;
}



/**
 * 4GL CALL
 * @todo Describe function
 */
int
UILIB_A4GL_gen_field_chars_ap (void *field_listv, void *formdetsv,
			       va_list * ap)
{
  int a;
  FIELD ***field_list;
  struct s_form_dets *formdets;

  field_list = field_listv;
  formdets = formdetsv;

  a = A4GL_gen_field_list (field_list, formdets, 9999, ap);
  return a;
}

int
UILIB_A4GL_gen_field_list_from_slist (void *field_listv, void *formdetsv,
				      void *listv)
{
  int a;
  FIELD ***field_list;
  struct s_form_dets *formdets;
  struct s_field_name_list *list;

  field_list = field_listv;
  formdets = formdetsv;
  list = listv;

  a =
    A4GL_gen_field_list_from_slist_internal (field_list, formdets, 9999,
					     list);
  return a;
}

/**
 *
 * @todo Describe function
 */
int
A4GL_gen_field_list_from_slist_internal (FIELD *** field_list,
					 struct s_form_dets *formdets,
					 int max_number,
					 struct s_field_name_list *list)
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
  int fmetric=0;
  struct struct_metrics *k;
  int attr_no;
  int srec_no;
  int cnt = 0;
  A4GL_debug ("a=%d\n", max_number);


  if (formdets == 0)
    {
      A4GL_exitwith ("No form displayed");
      return -1;
    }

  for (z1 = 0; z1 <= max_number; z1++)
    {

      if (z1 >= list->nfields)
	break;
      s = list->field_name_list[z1].fname;
      if (s == 0)
	{
	  break;
	}

      fmetric = list->field_name_list[z1].fpos;

      A4GL_debug (" got field number as %d z1=%d list=^p", fmetric,z1);

      ff = 0;

      /* get screen record/table name */
      memset (tabname, 0, sizeof (tabname));
      memset (colname, 0, sizeof (colname));
      A4GL_bname (s, tabname, colname);
      srec_no = A4GL_find_srec (formdets->fileform, tabname);
       A4GL_debug("tabname='%s' colname='%s' fpos=%d",tabname,colname,fmetric);
      if (strlen (tabname) && strlen (colname) && srec_no == -1)
	{
	  if (!field_status_strip_tabname) {
			A4GL_exitwith ("Table/Screen record does not exist in form");
	  }
	  return -1;
	}

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
		      return -1;	// Was 0
		    }

		  if (fmetric < 0
		      || fmetric >
		      formdets->fileform->fields.fields_val[fno].metric.
		      metric_len)
		    {
		      A4GL_exitwith ("Field subscript out of bounds");
		      return -1;

		    }
		  metric_no =
		    formdets->fileform->fields.fields_val[fno].metric.
		    metric_val[fmetric];
		  A4GL_debug ("fno=%d f=%d mno=%d metric_no=%d\n", fno,
			      fmetric, mno, metric_no);
		  k = &formdets->fileform->metrics.metrics_val[metric_no];
#ifdef DEBUG
		  {
		    A4GL_debug ("cnt=%d a=%d", cnt, max_number);
		  }
#endif

		  if (cnt >= max_number)
		    {
		      A4GL_debug ("cnt=%d a=%d", cnt, max_number);
		      A4GL_exitwith
			("Too few variables for the number of fields");
		      return -1;
		    }
		  A4GL_debug ("Setting flist[%d] to %p", cnt, k);
		  flist[cnt++] = (FIELD *) k->field;
		  A4GL_debug ("Set");
		  ff = 1;
		/* Test  278 -  multi occurences of the same name for  a fieldname in a form 
			Just use the first one if no table is specified...
			*/
			A4GL_debug("fmetric=%d len=%d",fmetric,strlen(tabname));

		  	if (fmetric==0&&strlen(tabname)==0) {
				A4GL_debug("Are you Test 278...?");
				z=formdets->fileform->records.records_val[srec_no].attribs.attribs_len;
			}

		}

	    }
	}

      else
	{


	  for (z = 0; z < formdets->fileform->attributes.attributes_len; z++)
	    {
	      attr_no = z;
#ifdef DEBUG
	      {
		A4GL_debug ("attr_no=%d", attr_no);
	      }
#endif
	      mno =
		A4GL_attr_name_match (&formdets->fileform->attributes.
				      attributes_val[attr_no], s);
	      A4GL_debug ("mno=%d\n", mno);

	      if (mno)
		{
		  fno =
		    formdets->fileform->attributes.attributes_val[attr_no].
		    field_no;
		  A4GL_debug ("Matched to field no %d - len=%d f=%d", fno,
			      formdets->fileform->fields.fields_val[fno].
			      metric.metric_len, fmetric);
		  if (formdets->fileform->fields.fields_val[fno].metric.
		      metric_len <= fmetric || fmetric < 0)
		    {
		      A4GL_exitwith ("Field subscript out of bounds");
		      return -1;
		    }
		  metric_no =
		    formdets->fileform->fields.fields_val[fno].metric.
		    metric_val[fmetric];
		  k = &formdets->fileform->metrics.metrics_val[metric_no];
#ifdef DEBUG
		  {
		    A4GL_debug ("cnt=%d a=%d", cnt, max_number);
		  }
#endif
		  if (cnt >= max_number)	/* was >= */
		    {
		      A4GL_debug ("cnt=%d a=%d", cnt, max_number);
		      A4GL_debug ("Too few variables");
		      A4GL_exitwith
			("Too few variables for the number of fields");
		      return -1;
		    }
		  A4GL_debug ("Setting flist[%d] to %p", cnt, k);
		  flist[cnt++] = (FIELD *) k->field;
		  A4GL_debug ("aa");
		  	if (fmetric==0&&strlen(tabname)==0) {
				A4GL_debug("Are you Test 278...?");
				z=formdets->fileform->attributes.attributes_len+1;
			}
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

  A4GL_debug("Alloc : cnt=%d ",cnt);

  *field_list = calloc (cnt + 1, sizeof (FIELD *));
  A4GL_debug("Allocated : %p",*field_list);
  memcpy (*field_list, flist, sizeof (FIELD *) * (cnt + 1));
  A4GL_debug("Copied...");
  return cnt - 1;
}



// ADDED FOR MID 1014
static void remove_tables_from_list(struct s_field_name_list *list) { 
int a;

for (a=0;a<list->nfields;a++) {
	char *ptr;
	ptr=strchr(list->field_name_list[a].fname,'.');
	if (ptr) {
			list->field_name_list[a].fname=ptr+1;
		}
}

}
/**
 *
 * @todo Describe function
 */
int
A4GL_gen_field_list (FIELD *** field_list, struct s_form_dets *formdets,
		     int max_number, va_list * ap)
{
  struct s_field_name_list list;
  int n;
  list.field_name_list = 0;
  A4GL_make_field_slist_from_ap (&list, ap);

  n=A4GL_gen_field_list_from_slist_internal (field_list, formdets, max_number, &list);


  if (field_status_strip_tabname && n==-1 && !A4GL_isno(acl_getenv("FIELDTOUCHEDTABLEFIXUP"))) { // MID 1014
	remove_tables_from_list(&list);
  	n=A4GL_gen_field_list_from_slist_internal (field_list, formdets, max_number, &list);
  }  // END OF MID 1014


	free(list.field_name_list);
  return n;

}



/**
 *
 * @todo Describe function
 */
int
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
      return 0;
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
	      A4GL_error_nobox (acl_getenv ("FIELD_INCL_MSG"), 0);
	      set_current_field (mform, sio->currform->currentfield);
	    }
	}

      A4GL_debug ("Calling pop_var2..");
      A4GL_pop_var2 (sio->vars[a].ptr, sio->vars[a].dtype, sio->vars[a].size);

    }
  else
    {
      fprop = (struct struct_scr_field *) (field_userptr (f));
      if (fprop != 0)
	{
	  if (fprop->colname != 0)
	    {
	      A4GL_debug ("Calling constr with : '%s' '%s' datatype=%d",
			  sio->constr[a].tabname, sio->constr[a].colname,fprop->datatype);


	      ptr =
		(char *) A4GL_construct (sio->constr[a].tabname,
					 sio->constr[a].colname,
					 field_buffer (f, 0),get_inc_quotes(fprop->datatype)
					);
	      A4GL_debug ("ptr=%s", ptr);
	      if (ptr == 0)
		{
		  A4GL_error_nobox (acl_getenv ("FIELD_CONSTR_EXPR"), 0);
		  return 0;
		}
	    }
	}
    }
  A4GL_debug ("Done after field - field_status=%d", field_status (f));
  return 1;
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
  A4GL_debug ("Creating new field entry y=%d x=%d rows=%d width=%d\n", frow,
	      fcol, rows, cols);

  f = new_field (rows, cols, frow, fcol, 0, 0);

  if (f)
    {
      A4GL_debug ("Field created - setting attributes");
      /*A4GL_set_field_attr (f); */
      A4GL_debug ("ZZZZ - SET OPTS");
      local_field_opts_off (f, O_ACTIVE);
      local_field_opts_off (f, O_EDIT);
      local_field_opts_off (f, O_BLANK);
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
A4GL_set_field_pop_attr (FIELD * field, int attr, int cmd_type)
{
  struct struct_scr_field *f;
  struct s_form_dets *fff;
  int a;
  long oopt;
  int d1;
  int s1;
  void *ptr1;


  A4GL_get_top_of_stack (1, &d1, &s1, (void **) &ptr1);


  f = (struct struct_scr_field *) (field_userptr (field));

  if (A4GL_has_bool_attribute (f, FA_B_REVERSE))
    a = 1;
  else
    a = 0;

  A4GL_debug ("f->do_reverse=%d attr=%x", a, attr);





  A4GL_display_field_contents (field, d1, s1, ptr1);




  A4GL_debug ("set f->do_reverse to %d ", f->do_reverse);
  oopt = local_field_opts (field);
  A4GL_set_field_attr (field);
  A4GL_debug ("Determining attribute - field_buffer=%s", field_buffer (field, 0));
  attr = A4GL_determine_attribute (cmd_type, attr, f, field_buffer (field, 0));

  if (attr != 0 || 1)
    {
      A4GL_debug ("calling set_field_attr_with_attr : %x", attr);
      A4GL_set_field_attr_with_attr (field, attr, cmd_type);
    }


  A4GL_debug ("set field attr");
  fff = UILIB_A4GL_get_curr_form (1);
  A4GL_debug ("set field");
  A4GL_debug ("set field buffer setting do_reverse=%d", a);

  f->do_reverse = a;
  A4GL_debug ("done ");
  local_set_field_opts (field, oopt);
  A4GL_debug ("ZZZZ - SET OPTS");
  A4GL_debug ("Calling display_field_contents");




}


/**
 *
 * @todo Describe function
 */
void
A4GL_display_field_contents (FIELD * field, int d1, int s1, char *ptr1)
{
  int field_width;
  int has_format;
  int ignore_formatting = 0;
  struct struct_scr_field *f;
  char *ff;

   field_width= A4GL_get_field_width_w (field,1);

  A4GL_debug ("In display_field_contents");
  f = (struct struct_scr_field *) (field_userptr (field));
  ff = acl_malloc2  (field_width+1);

  has_format = A4GL_has_str_attribute (f, FA_S_FORMAT);
  A4GL_debug ("Has format : %d  ", has_format);

// 'Format' is valid for a lot of datatypes -
// but not all...
// If we are passing **IN** a character string
// for example - we'll omit the formatting...

  switch (d1 & DTYPE_MASK)
    {
    case DTYPE_CHAR:
    case DTYPE_BYTE:
    case DTYPE_TEXT:
    case DTYPE_VCHAR:
      ignore_formatting = 1;
    }

  if (has_format && ignore_formatting)
    {
      A4GL_debug ("Which I'm going to ignore..");
    }

  if (has_format && !ignore_formatting)
    {
      A4GL_debug ("Has specified format..");
      if (strlen (A4GL_get_str_attribute (f, FA_S_FORMAT)) > field_width)
	{
	  A4GL_exitwith ("Format is wider than the field");
	      A4GL_drop_param ();
	  return;
	}

      A4GL_push_char (A4GL_get_str_attribute (f, FA_S_FORMAT));
      A4GL_pushop (OP_USING);
    }

  if (!has_format && !ignore_formatting)
    {
      A4GL_debug ("Has no format.. d1=%d", d1 & DTYPE_MASK);
      if (A4GL_has_datatype_function_i (d1 & DTYPE_MASK, "DISPLAY"))
	{
	  char *ptr;
	  char *(*function) (void *, int, int, struct struct_scr_field *,
			     int);
	  A4GL_debug ("check for specific display routine");
	  function =
	    A4GL_get_datatype_function_i (d1 & DTYPE_MASK, "DISPLAY");
	  if (function)
	    {
	      A4GL_debug
		("Has a function - calling XXXX - size=%d decode_size=%d", s1,
		 DECODE_SIZE (d1));
	      ptr = function (ptr1, s1, field_width, f, DISPLAY_TYPE_DISPLAY_TO);
	      A4GL_debug ("Returns %p\n", ptr);
	    }
	  else
	    {
	      ptr = 0;
	    }
	  if (ptr != 0)
	    {
	      A4GL_debug ("Here.. %s", ptr);
	      A4GL_drop_param ();
	      A4GL_debug ("Dropped - pushing mine..");
	      A4GL_push_char (ptr);
	    }
	}

    }

  if (f->dynamic==0) {
  	A4GL_pop_char (ff, field_width);
  }  else {
	  A4GL_debug("Its a dynamic field.... %d",f->dynamic);
	  acl_free(ff);
	  ff=A4GL_char_pop();
	  A4GL_debug("Got : %s instead..\n",ff);
  }

  A4GL_debug ("set_field_contents : '%s'", ff);
  A4GL_mja_set_field_buffer (field, 0, ff);
  acl_free (ff);



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
  va_list *ptr;

  return;			/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

  A4GL_debug ("In disp_fields");
  formdets = UILIB_A4GL_get_curr_form (1);
  flg = 0;

  va_start (ap, attr);
  A4GL_debug (" field_list = %p", &field_list);
#ifdef DEBUG
  {
    A4GL_debug ("Genfldlist 6");
  }
#endif
  A4GL_debug ("set_arr_fields");
  ptr = &ap;
  nofields = A4GL_gen_field_list (&field_list, formdets, n, &ap);
  A4GL_debug ("Number of fields=%d", nofields);
  for (a = nofields; a >= 0; a--)
    {
      A4GL_debug ("field_list[%d]=%p", field_list[a]);
      fff = UILIB_A4GL_get_curr_form (1);
      set_current_field (fff->form, field_list[a]);
      A4GL_debug ("set_init_pop complete");
    }
  set_current_field (fff->form, field_list[0]);	// was nofields....
}


/**
 *
 * @todo Describe function
 */
int
A4GL_form_field_constr (struct s_screenio *sio, int m)
{
  char buff[8000];
  char buff2[8000];
  FORM *mform;
  int x, y;
  int flg = 0;
  struct s_form_dets *form;
  struct struct_scr_field *fprop;
  mform = sio->currform->form;
  form = sio->currform;

  if (m == 1)
    {
      form->currentfield = 0;
      form->currentmetrics = 0;
      A4GL_debug ("ZZ9PA - CHECK CHECK - returning 0");
      return 0;
    }

  A4GL_debug ("ZZ9PA - CHECK CHECK - continuing");

  A4GL_debug ("currentfield=%p current_field(mform)=%p", form->currentfield,
	      current_field (mform));

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
	      if ((fprop->datatype != (DTYPE_CHAR & DTYPE_MASK)) && (field_status (form->currentfield)))
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
  A4GL_debug ("form_field_constr returning %d", flg);
  return flg;
}


/**
 *
 * @todo Describe function
 */
void
A4GL_mja_set_field_buffer_contrl (FIELD * field, int nbuff, int ch)
{
  char buff[20];
  A4GL_debug ("Ch=%d", ch);
  if (ch == 0)
    {
      return;
    }
  buff[0] = ch & 0xff;
  buff[1] = 0;
  A4GL_debug ("Adding char %d %c", ch, ch);
  A4GL_mja_set_field_buffer (field, nbuff, buff);
}

/**
 *
 * @todo Describe function
 */
void
A4GL_mja_set_field_buffer (FIELD * field, int nbuff, char *buff)
{
  char buff2[8024];
  int a;
  int b; 
  int xerrno;
  
  b = A4GL_get_field_width_w (field,1);
  if (strlen(buff)>=sizeof(buff2)) {
		  	A4GL_assertion(1,"Buffer too small");
  }
  strcpy (buff2, buff);
  a = strlen (buff2);
  b = A4GL_get_field_width_w (field,1);
  A4GL_debug ("mja_set_field_buffer buff='%s' buff2='%s' (%d,%d) ", buff, buff2, a, b);
  if (a < A4GL_get_field_width_w (field,1))
    {
      A4GL_debug ("Adding padding");
      A4GL_pad_string (buff2, A4GL_get_field_width_w (field,1));
    }
  else
    {
      A4GL_debug ("No padding required '%s'", buff);
    }
  A4GL_debug("setting field buffer to %s",buff2);

  if (A4GL_isyes(acl_getenv("TRIMFIELD"))) {
	  buff2[b]=0;
  }

  xerrno = set_field_buffer (field, nbuff, buff2);

  if (xerrno!=E_OK) {
	  A4GL_debug("ERROR SETTING FIELD BUFFER %d\n",xerrno);
  }
  A4GL_debug ("Setting %p %d to %s (%d)", field, nbuff, buff2, xerrno);
  A4GL_debug ("field buffer set to '%s'", field_buffer (field, 0));
  A4GL_debug ("Currwin=%p", currwin);
  pos_form_cursor (field->form);
  if (currwin > (WINDOW *) 1)
    {

	//
	// Don't know why it was doing a touchwin here.....
	// - maybe a refresh - but a touchwin ?

      //touchwin (currwin);
	
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
UILIB_A4GL_push_constr (void *vs)
{
  struct struct_scr_field *fprop;
  FIELD *f;
  int a;
  char *ptr;
  int flg = 0;
  struct s_screenio *s;
  s = vs;
A4GL_debug("UILIB_A4GL_push_constr----------------------------------------------------");
  if (s->processed_onkey == A4GLKEY_INTERRUPT)
    {
      A4GL_push_char (s->vars[0].ptr);
      return 0;
    }

  if (s->nfields < 0)
    {
      A4GL_debug ("NO CONSTRUCT - No fields\n");
      A4GL_push_char ("");
      return 0;
    }
  if (s->currform == 0)
    {
      A4GL_debug ("NO CONSTRUCT - No form\n");
      A4GL_push_char ("");
      return 0;
    }
  A4GL_int_form_driver (s->currform->form, REQ_FIRST_PAGE);

  A4GL_debug ("Push_constr");
  A4GL_debug ("nfields=%d", s->nfields);
  if (s->field_list == 0)
    {
      A4GL_exitwith ("Internal error - no field list");
      A4GL_push_char ("");
      return 0;
    }
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
	  A4GL_debug ("fprop->colname=%s fprop->datatype=%x", fprop->colname, (fprop->datatype) & 0xffff);

		A4GL_debug("field_buffer (%p) =%s", f, field_buffer (f, 0));
	

	  ptr =
	    (char *) A4GL_construct (s->constr[a].tabname,
				     s->constr[a].colname, field_buffer (f, 0),get_inc_quotes(fprop->datatype)
		);

	if (ptr==0) { // some error in the field...
      		A4GL_push_char ("");
      		return 0;
	}
	
		A4GL_debug("ptr=%s\n",ptr);
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
		  A4GL_push_char (" and ");
		  A4GL_push_char (ptr);
		  A4GL_pushop (OP_CONCAT);
		  A4GL_pushop (OP_CONCAT);
		}
	    }
	}
    }
  if (flg == 0)
    A4GL_push_char (" 1=1");

if (s->fcntrl) free(s->fcntrl);
if (s->field_list) free(s->field_list);
  return 1;
}





/**
 *
 * @todo Describe function
 */
void
UILIB_A4GL_set_infield_from_stack (void)
{
  A4GL_debug ("**** CHANGED FIELD ****");
  inp_current_field = (void *)A4GL_pop_long ();
  A4GL_debug ("New field :---> %p", inp_current_field);
}

void
A4GL_set_infield_from_parameter (long a)
{
  A4GL_debug ("**** CHANGED FIELD ****");
  inp_current_field = (void *)a;
  A4GL_debug ("New field :---> %p", inp_current_field);
}

/**
 * @return The current field number.
 */
long
A4GL_get_curr_infield (void)
{
  return (long)inp_current_field;
}

void
A4GL_set_curr_infield (void *a)
{
  inp_current_field = a;
}

/**
 * 4GL CALL
 * @todo Describe function
 */
int
UILIB_A4GL_fgl_infield_ap (void *inp, va_list * ap)
{
  FIELD **field_list;
  struct s_screenio *s;
  int c;
  int a;
  int rval = 0;
  char *colname;
  int field_no;

  if (UILIB_A4GL_get_curr_form (0) == 0)
    {
      return 0;
    }




  while (1)
    {
      colname = va_arg (*ap, char *);	/* This is suspect.... */
      if (colname == 0)
	break;
      field_no = va_arg (*ap, int);


      if (A4GL_field_name_match ((FIELD *) A4GL_get_curr_infield (), colname))
	{
	  A4GL_debug ("infield - matches");
	  return 1;
	}
    }
  A4GL_debug ("Infield - doesn't match");
  return 0;




  s = inp;

  c = UILIB_A4GL_gen_field_chars_ap (&field_list, s->currform, ap);
  for (a = 0; a <= c; a++)
    {
      if (field_list[a] == (FIELD *) inp_current_field)
	{

	  rval = 1;
	  break;
	}
    }

  return rval;
}


/**
 *
 * @todo Describe function
 */
int
UILIB_A4GL_fgl_infield_ia_ap (void *inp, va_list * ap)
{
  FIELD **field_list;
  struct s_inp_arr *s;
  int c;
  int a;
  int rval = 0;
  char *colname;
  int field_no;
  s = inp;
  if (UILIB_A4GL_get_curr_form (0) == 0)
    {
      return 0;
    }

  while (1)
    {
      colname = va_arg (*ap, char *);	/* This is suspect.... */
      if (colname == 0)
	break;
      field_no = va_arg (*ap, int);

      if (A4GL_field_name_match ((FIELD *) A4GL_get_curr_infield (), colname))
	{
	  A4GL_debug ("Infield_ia - matches...");
	  return 1;
	}
    }
  A4GL_debug ("Infield_ia - doesn't match");
  return 0;



  c = UILIB_A4GL_gen_field_chars_ap (&field_list, s->currform, ap);
  for (a = 0; a <= c; a++)
    {
      if (field_list[a] == (FIELD *) inp_current_field)
	{

	  rval = 1;
	  break;
	}
    }

  return rval;
}




/**
 * 4GL CALL
 * @todo Describe function
 */
int
UILIB_A4GL_fgl_getfldbuf_ap (void *inp, va_list * ap)
{

  FIELD **field_list;
  struct s_screenio *s;
  int c;
  int a;
  int nr;


  s = inp;

  c = UILIB_A4GL_gen_field_chars_ap (&field_list, s->currform, ap);
  nr = 0;
  for (a = 0; a <= c; a++)
    {
      char *buff=0;
      char *orig=0;
      int freeme=0;

      orig=field_buffer (field_list[a], 0);
      A4GL_debug("Orig=%s\n",orig);
      if (strlen(orig)==0) {
	      	freeme++;
		buff=malloc(2);
		buff[0]=0;
		buff[1]=0;
	      	//buff=strdup("");
      } else {
	      	freeme++;
      		buff = strdup (orig);
      }
      A4GL_debug("Got buff as : '%s'",buff);

      chk_for_picture (field_list[a], buff);

      A4GL_debug("getfldbuf='%s'\n",buff);
      A4GL_push_char (buff);
      if (freeme) {
      	acl_free (buff);
      	}
      nr++;
    }
  return nr;
}

/**
 *
 * @todo Describe function
 */
int
UILIB_A4GL_fgl_getfldbuf_ia_ap (void *inp, va_list * ap)
{

  FIELD **field_list;
  struct s_inp_arr *s;
  int c;
  int a;
  int nr;
  int b;

  s = inp;

  c = UILIB_A4GL_gen_field_chars_ap (&field_list, s->currform, ap);
  nr = 0;
  for (a = 0; a <= c; a++)
    {
      FIELD *f;
      int nv;
      f = field_list[a];	// f will always be in the first rows of screen fields..
      nv=s->nbind;
	if (s->start_slice!=-1) { nv=s->end_slice-s->start_slice+1; }

      for (b = 0; b < nv; b++)
	{
	  if (f == s->field_list[0][b])
	    {
	      char *buff;
	      // Found @ position b...
	      A4GL_push_char (field_buffer
			      (s->field_list[s->scr_line - 1][b], 0));
	      buff =
		strdup (field_buffer (s->field_list[s->scr_line - 1][b], 0));
	      chk_for_picture (field_list[a], buff);
	      A4GL_push_char (buff);
	      acl_free (buff);
	      nr++;
	    }
	}
    }
  return nr;
}


void
UILIB_A4GL_reset_delims (void *vformdets, void *field,char *delims)
{
struct s_form_dets *formdets;
  int a;
  char sbuff0[2];
  char sbuff1[2];
  formdets=vformdets;
  sbuff0[0] = delims[0];
  sbuff0[1] = 0;
  sbuff1[0] = delims[1];
  sbuff1[1] = 0;

  for (a = 0; a < formdets->fileform->metrics.metrics_len; a++)
    {
	if (field && (void *)formdets->fileform->metrics.metrics_val[a].field != field) continue;

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
char * get_print_field_opts_as_string (FIELD * a)
{
  long z;
  static char str[8048] = "";
  strcpy(str,"");
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
return str;
}


/**
 *
 * @todo Describe function
 */
void
A4GL_debug_print_field_opts (FIELD * a)
{
  long z;
  char str[8048] = "";
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
  A4GL_debug ("UUU Field %p attribs= %s: (%s)", a, str,field_buffer(a,0));
}



#ifdef RESERVED_FOR_FUTURE_ENHANCEMENT
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
#endif



/**
 *
 * @todo Describe function
 */
int
A4GL_copy_field_data (struct s_form_dets *form)
{
  char buff[8000] = "";
  char buff2[8000] = "";
  FORM *mform;
  int ppr;
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
	    if (((fprop->datatype != DTYPE_CHAR) & (DTYPE_MASK)) && (field_status (form->currentfield)))
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
		    A4GL_debug ("Pushing param %p", buff2);
#endif




		    ppr =
		      A4GL_check_and_copy_field_to_data_area (form, fprop,
							      buff2, buff);


		    if (ppr)
		      {
#ifdef DEBUG
			A4GL_debug ("Pushing param %p %d", buff,
				    fprop->datatype);
#endif
			if (fprop->datatype == DTYPE_CHAR
			    || fprop->datatype == DTYPE_VCHAR)
			  {
			    A4GL_push_param (buff,
					     fprop->datatype +
					     (strlen (buff) << 16));
			  }
			else
			  {
			    A4GL_push_param (buff,
					     fprop->datatype +
					     (fprop->dtype_size << 16));
			  }
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
			A4GL_error_nobox (acl_getenv ("FIELD_ERROR_MSG"), 0);
			if (fprop != 0)
			  A4GL_comments (fprop);

			if (A4GL_isyes
			    (acl_getenv ("A4GL_CLR_FIELD_ON_ERROR")))
			  {
			    A4GL_clr_field (form->currentfield);
			  }
			else
			  {
			    if (A4GL_isyes (acl_getenv ("FIRSTCOL_ONERR")))
			      {
				A4GL_int_form_driver (mform, REQ_BEG_FIELD);
			      }

			  }

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
  char buff[10024];
  char buff2[10024];
  int fd_ok;

  A4GL_debug ("int_form_driver called with %p - %d", form, a);

  if (a <= 27)
    {
      A4GL_debug ("Control Character or ESC");
      return;
    }

  field_pos = A4GL_get_curr_field_col (form);
  f = current_field (form);

  if (f)
    {
      strcpy (buff, field_buffer (f, 0));
	A4GL_debug("Field buffer was %s\n",buff);
    }
  else
    {
      strcpy (buff, "");
    }
  

  A4GL_debug ("MJA Calling form_driver with %d (%x)  for form %p - buff=%s", a,a, form, buff);
  if (a>KEY_MAX) {
	  	A4GL_debug("FORM CONTROL   - %d\n",a-KEY_MAX);
  }
  if (a_isprint(a)&&a>=' '&&a<127) {
	  	A4GL_debug("Key : %c",a);
  }

  fd_ok = form_driver (form, a);

  if (fd_ok != E_OK)
    {
      A4GL_debug ("Problem in calling form_driver %p c=%d %x - rets %d", form,
		  a, a, fd_ok);
      switch (fd_ok)
	{
	case E_SYSTEM_ERROR:
	case E_BAD_STATE:
	case E_BAD_ARGUMENT:
	case E_NOT_POSTED:
	/* case E_UNKNOWN_COMMAND: */	/* allow this for mbs utf8*/
	case E_INVALID_FIELD:
	  A4GL_exitwith ("Form driver complaint");
	  return;
	}
    }

  if (f)
    {
      strcpy (buff2, field_buffer (f, 0));
	A4GL_debug("field buffer returns %s\n",buff2);
    }
  else
    {
      strcpy (buff2, "");
    }

  if (f != current_field (form))
    {
      A4GL_debug ("Resetting focus");
      f = current_field (form);
    }

  if (field_pos != A4GL_get_curr_field_col (form))
    {
      A4GL_debug ("Resetting position (%d %d)",field_pos,A4GL_get_curr_field_col (form));
      field_pos = A4GL_get_curr_field_col (form);
    }

  A4GL_debug ("Buff2 now = %s", buff2);

  if (a != REQ_VALIDATION) {
		A4GL_debug("REQ_VALIDATION");
	  	A4GL_int_form_driver (form, REQ_VALIDATION);
		A4GL_debug("DONE REQ_VALIDATION");
  }

  if (f)
    {
      strcpy (buff2, field_buffer (f, 0));
	A4GL_debug("field buffer now returns %s\n",buff2);
    }
  else
    {
      strcpy (buff2, "");
    }
  A4GL_debug ("Validation has set Buff2 now = %s", buff2);



}


/**
 * 4GL CALL
 * @todo Describe function
 */
void
UILIB_A4GL_clr_form (int to_default)
{
  struct s_form_dets *formdets;
  int a;
  int metric_no;
  struct struct_metrics *k;
  FIELD *f;
  int fno;
  int rn;

  A4GLSQL_set_status (0, 0);

  formdets = UILIB_A4GL_get_curr_form (1);
  if (formdets==0) return; /* No form to clear ? */


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

	  A4GL_debug ("Calling set_field_attr_with_attr for clearing..");

	  A4GL_set_field_attr_with_attr ((FIELD *) formdets->fileform->
					 metrics.metrics_val[metric_no].field,
					 0, FGL_CMD_CLEAR);

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
					 (char *) A4GL_replace_sql_var
					 ((char *) A4GL_strip_quotes
					  (A4GL_get_str_attribute
					   (prop, FA_S_DEFAULT))));
	    }
	}

    }

  UILIB_A4GL_zrefresh ();
}


/**
 * 4GL CALL
 * @todo Describe function
 */
int
UILIB_A4GL_disp_form_fields_ap (int n, int attr, char *formname, va_list * ap)
{
  A4GL_chkwin ();
  A4GL_exitwith ("Not implemented for TUI mode");
  return 0;
}



/**
 *
 * @todo Describe function
 */
int
A4GL_curr_metric_is_used_last_s_screenio (struct s_screenio *s, FIELD * f)
{
  int a;
  int fno = -1;
  int last_usable = -1;
  struct struct_scr_field *fprop;

  for (a = 0; a <= s->nfields; a++)
    {
      A4GL_debug ("MMM a=%d Current field=%p field_list=%p", a, f,
		  s->field_list[a]);
      if (f == s->field_list[a])
	fno = a;

      fprop = (struct struct_scr_field *) (field_userptr (s->field_list[a]));

      if (!A4GL_field_is_noentry ((s->mode == MODE_CONSTRUCT), fprop)
	  || (fprop->datatype == DTYPE_SERIAL && s->mode != MODE_CONSTRUCT))
	{
	  A4GL_debug ("Field is not noentry");
	  last_usable = a;
	}
      else
	{
	  A4GL_debug ("MMM Field is noentry");
	}
    }

  A4GL_debug ("MMM curr_metric_is_used_last_s_screenio fno=%d nfields=%d",
	      fno, s->nfields);

  if (fno == last_usable)
    {
      A4GL_debug ("MMM Is last");
      return 1;
    }

  A4GL_debug ("MMM Not last");
  return 0;
}


/**
 *
 * @todo Describe function
 */
int
UILIB_aclfgl_a4gl_set_page (int n)
{
  int b;
  struct s_form_dets *f;
  b = A4GL_pop_int ();
  f = UILIB_A4GL_get_curr_form (1);
  set_form_page (f->form, b);
  refresh ();
  return 0;
}

/**
 *
 * @todo Describe function
 */
int
UILIB_aclfgl_a4gl_get_page (int n)
{
  struct s_form_dets *f;
  f = UILIB_A4GL_get_curr_form (1);
  A4GL_push_int (form_page (f->form));
  return 1;
}





/**
 *
 * @todo Describe function
 */
int
UILIB_A4GL_fgl_fieldtouched_input_array_ap (void *sv, va_list * ap)
{
  int a;
  int c;
  int b;
  FIELD **field_list;
  struct s_inp_arr *s;
  struct struct_scr_field *fprop;
  s = sv;
  A4GL_debug ("fgl_fieldtouched - input array");




  field_status_strip_tabname=1;
  c = UILIB_A4GL_gen_field_chars_ap (&field_list, s->currform, ap);
  field_status_strip_tabname=0;
  if (c >= 0)
    {
      /*
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
       */


      A4GL_debug ("fieldtouched_input - checking field_status");

      for (a = 0; a <= c; a++)
	{
	  FIELD *f;
		int nv;
	  f = field_list[a];
      nv=s->nbind;
	if (s->start_slice!=-1) { nv=s->end_slice-s->start_slice+1; }
	  for (b = 0; b <nv; b++)
	    {
	      if (f == s->field_list[0][b])
		{
		  // Found @ position b....
		  fprop =
		    (struct struct_scr_field
		     *) (field_userptr (s->field_list[s->scr_line - 1][b]));
		  if (fprop->flags & 2)
		    {
		      A4GL_debug
			("fieldtouched Field status is set for %p - %d line %d - b=%d",
			 field_list[a], fprop->flags, s->scr_line - 1, b);
		      acl_free (field_list);
		      return 1;
		    }
		}
	    }
	}
      A4GL_debug ("fieldtouched Field status not set for any..");
      acl_free (field_list);
      return 0;

    }
  else
    {
      A4GL_exitwith ("field_touched called with no fields...");
      return 0;
    }
}


/**
 *
 * @todo Describe function
 */
int
UILIB_A4GL_fgl_fieldtouched_input_ap (void *sv, va_list * ap)
{
  int a;
  int c;
  int b;
  FIELD **field_list;
  int found;
  struct s_screenio *s;
  struct struct_scr_field *fprop;
  s = sv;
  A4GL_debug ("fgl_fieldtouched - input ");  
  A4GLSQL_set_status (0, 0);


  field_status_strip_tabname=1;
  c = UILIB_A4GL_gen_field_chars_ap (&field_list, s->currform, ap);
  field_status_strip_tabname=0;


  if (c >= 0)
    {
      for (a = 0; a <= c; a++)
	{
	  found = 0;
	  A4GL_debug ("fieldtouched FIELD : %p a=%d c=%d - status=%d\n", field_list[a], a, c, field_status (field_list[a]));

	  // Have a look to see if we are currently inputing this one...
	  for (b = 0; b <= s->nfields; b++)
	    {
	      void *ptr1;
	      void *ptr2;


	      ptr1 = field_list[a];

		if (b>c) {
			A4GL_debug("Odd - more fields being input than we have fields ?");
			continue;
		}
		A4GL_debug("a=%d b=%d",a,b);
	      ptr2 = field_list[b];

	      A4GL_debug ("Ptr1=%p", ptr1);
	      A4GL_debug ("Ptr2=%p", ptr2);

	      if (ptr1 == ptr2)
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

	  A4GL_int_form_driver (s->currform->form, REQ_VALIDATION);
	  fprop = (struct struct_scr_field *) (field_userptr (field_list[a]));

	  if (fprop->flags & 2)
	    {
	      A4GL_debug ("fieldtouched Field status is set for %p",
			  field_list[a]);
	      acl_free (field_list);
	      return 1;
	    }
	}
      A4GL_debug ("fieldtouched Field status not set for any..");
      acl_free (field_list);
      return 0;

    }
  else
    {
      A4GL_exitwith ("field_touched called with no fields...");
      return 0;
    }
}






/**
 *
 * @todo Describe function
 */
void
UILIB_A4GL_clr_fields_ap (int to_defaults, va_list * ap)
{
  int a;
  FIELD **field_list;
  struct struct_scr_field *f;
  int c;
  A4GL_debug ("clr_Fields_ap");

  c =
    UILIB_A4GL_gen_field_chars_ap (&field_list, UILIB_A4GL_get_curr_form (1),
				   ap);

  for (a = 0; a <= c; a++)
    {
      A4GL_mja_set_field_buffer (field_list[a], 0, "");
      f = (struct struct_scr_field *) (field_userptr (field_list[a]));
      if (f)
	A4GL_default_attributes (field_list[a], f->datatype);
    }


}

/**
 *
 * @todo Describe function
 */
int
A4GL_form_field_chk_iarr (struct s_inp_arr *sio, int m)
{
  char buff[8000] = "";
  char buff2[8000] = "";
  FORM *mform;
  int x, y;
  int pprval;
  struct s_form_dets *form;
  struct struct_scr_field *fprop;

  A4GL_debug ("form_field_chk_iarr....");
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

		A4GL_debug ("15 fprop!=0 flags=%d",fprop->flags);
		if ((fprop->datatype & DTYPE_MASK) != DTYPE_CHAR)
		  {

		    A4GL_modify_size (&buff[4],
				      form->fileform->metrics.
				      metrics_val[A4GL_get_metric_for
						  (form,
						   form->currentfield)].w);

		    strcpy (&buff[4], field_buffer (form->currentfield, 0));
		    strcpy (buff2, &buff[4]);
		    A4GL_trim (buff2);
		    getsyx (y, x);
		    A4GL_trim (buff2);

		    A4GL_debug ("15 Check buff2='%s'", buff2);

		    if (strlen (buff2) == 0)
		      {
			int chged=0;
			// Has the field changed ? 
			// Are we on a new line ? 
			if ((fprop->flags&2) || sio->curr_line_is_new) {
					chged++;
			}

			// are we returning to a previous field ? 
			if ( sio->processed_onkey!=A4GLKEY_ACCEPT   && sio->processed_onkey!=A4GLKEY_UP && sio->processed_onkey!=A4GLKEY_LEFT) {
				A4GL_debug("last key was not up or left");
				chged++;
			}

			if (chged==0) {
				if (!A4GL_entire_row_is_blank(sio,sio->scr_line-1)) {
					chged++;
				}
			}
				A4GL_debug("changed=%d\n", chged);
				//printf("changed=%d\n", chged);fflush(stdout);
			
			if (A4GL_has_bool_attribute (fprop, FA_B_REQUIRED) && chged)
			  {
			    int allow_it_anyway = 0;

			    // We'll still allow it - so long as there is null in the include list
			    if (A4GL_has_str_attribute (fprop, FA_S_INCLUDE))
			      {
				if (A4GL_check_field_for_include
				    ("",
				     A4GL_get_str_attribute (fprop,
							     FA_S_INCLUDE),
				     fprop->datatype))
				  {
				    allow_it_anyway = 1;
				  }
			      }

			    if (!allow_it_anyway)
			      {
				// Well there wasn't - so it is required....
				A4GL_error_nobox (acl_getenv
						  ("FIELD_REQD_MSG"), 0);
				set_current_field (mform, form->currentfield);
				return -4;
			      }


			  }

			// Could still be thrown out if we have an include without a null in it....
			A4GL_debug ("X2222 MAYBE");
			if (A4GL_has_str_attribute (fprop, FA_S_INCLUDE))
			  {
			    if (A4GL_check_field_for_include
				("",
				 A4GL_get_str_attribute (fprop, FA_S_INCLUDE),
				 fprop->datatype))
			      {
				return 1;
			      }
			    else
			      {
				A4GL_debug
				  ("X2222 Check for include has null...");
				A4GL_error_nobox (acl_getenv
						  ("FIELD_INCL_MSG"), 0);
				return -4;
			      }
			  }


			return 0;
		      }



		    pprval =
		      A4GL_check_and_copy_field_to_data_area (form, fprop,
							      buff2, buff);



		    if (!pprval)
		      {
			A4GL_error_nobox (acl_getenv ("FIELD_ERROR_MSG"), 0);
			if (fprop != 0)
			  A4GL_comments (fprop);

			if (A4GL_isyes
			    (acl_getenv ("A4GL_CLR_FIELD_ON_ERROR")))
			  {
			    A4GL_clr_field (form->currentfield);
			  }
			else
			  {
			    if (A4GL_isyes (acl_getenv ("FIRSTCOL_ONERR")))
			      {
				A4GL_int_form_driver (mform, REQ_BEG_FIELD);
			      }

			  }


			set_current_field (mform, form->currentfield);
			return -4;
		      }
		  }


		A4GL_debug ("CHECK FOR INCLUDE");

		strcpy (buff, field_buffer (sio->currform->currentfield, 0));
		if (strlen (buff) == 0)
		  {
		    if (A4GL_has_bool_attribute (fprop, FA_B_REQUIRED))
		      {
			int allow_it_anyway = 0;

			// We'll still allow it - so long as there is null in the include list
			if (A4GL_has_str_attribute (fprop, FA_S_INCLUDE))
			  {
			    if (A4GL_check_field_for_include
				("",
				 A4GL_get_str_attribute (fprop,
							 FA_S_INCLUDE),
				 fprop->datatype))
			      {
				allow_it_anyway = 1;
			      }
			  }

			if (!allow_it_anyway)
			  {
			    // Well there wasn't - so it is required....
			    A4GL_error_nobox (acl_getenv
					      ("FIELD_REQD_MSG"), 0);
			    set_current_field (mform, form->currentfield);
			    return -4;
			  }


		      }



		    A4GL_debug ("X2222 MAYBE");

		    if (A4GL_has_str_attribute (fprop, FA_S_INCLUDE))
		      {
			if (A4GL_check_field_for_include
			    ("",
			     A4GL_get_str_attribute (fprop, FA_S_INCLUDE),
			     fprop->datatype))
			  {
			    return 1;
			  }
			else
			  {
			    A4GL_debug
			      ("X2222 Check for include has null...");
			    A4GL_error_nobox (acl_getenv
					      ("FIELD_INCL_MSG"), 0);
			    return -4;
			  }
		      }

		  }



		if (A4GL_has_str_attribute (fprop, FA_S_INCLUDE))
		  {
		    if (A4GL_check_field_for_include
			(field_buffer (sio->currform->currentfield, 0),
			 A4GL_get_str_attribute (fprop, FA_S_INCLUDE),
			 fprop->datatype) == 0)
		      {
			A4GL_error_nobox (acl_getenv ("FIELD_INCL_MSG"), 0);
			set_current_field (mform, form->currentfield);
			return -4;
		      }
		  }





	      }
	  }
    }
  return 0;

}



void
A4GL_clr_field (FIELD * f)
{
  char *picture;
  char *str;
  int w;
  struct struct_scr_field *fprop;
  fprop = (struct struct_scr_field *) (field_userptr (f));

  w = A4GL_get_field_width (f);
  str = acl_malloc2 (w + 1);
  memset (str, ' ', w);
  str[w] = 0;

  A4GL_debug ("field width=%d", A4GL_get_field_width (f));

  if (A4GL_has_str_attribute (fprop, FA_S_PICTURE))
    {
      int a;
      picture = A4GL_get_str_attribute (fprop, FA_S_PICTURE);
      for (a = 0; a < strlen (picture); a++)
	{
	  if (a > w)
	    break;
	  if (picture[a] == 'X')
	    {
	      str[a] = ' ';
	      continue;
	    }
	  if (picture[a] == 'A')
	    {
	      str[a] = ' ';
	      continue;
	    }
	  if (picture[a] == '#')
	    {
	      str[a] = ' ';
	      continue;
	    }
	  str[a] = picture[a];
	}
    }
  A4GL_mja_set_field_buffer (f, 0, str);
}



void
chk_for_picture (FIELD * f, char *buff)
{
  struct struct_scr_field *fprop;
  char *picture;

  fprop = (struct struct_scr_field *) (field_userptr (f));

  if (A4GL_has_str_attribute (fprop, FA_S_PICTURE))
    {
      int a;
      int blank = 1;
      picture = A4GL_get_str_attribute (fprop, FA_S_PICTURE);
      A4GL_debug ("HAS PICTURE MJA123");
      for (a = 0; a < strlen (buff); a++)
	{
	  if (picture[a] == 'X' && buff[a] != ' ')
	    {
	      blank = 0;
	      break;
	    }
	  if (picture[a] == 'A' && buff[a] != ' ')
	    {
	      blank = 0;
	      break;
	    }
	  if (picture[a] == '#' && buff[a] != ' ')
	    {
	      blank = 0;
	      break;
	    }
	}
      if (blank)
	strcpy (buff, "");
    }
  A4GL_trim (buff);
}



char *
A4GL_fld_data_ignore_format (struct struct_scr_field *fprop, char *fld_data)
{
  char *ptr;
  ptr = A4GL_get_str_attribute (fprop, FA_S_FORMAT);
  A4GL_debug ("FLD_DATA_IGNORE_FORMAT : %s\n", fld_data);
//  if (ptr)
//    {
      // It could the that there are some literals or other characters
      // in fld_data that we need to take out first...
      //
      A4GL_debug ("Has format");
      if (fprop->datatype == DTYPE_SMINT || fprop->datatype == DTYPE_INT
	  || fprop->datatype == DTYPE_DECIMAL
	  || fprop->datatype == DTYPE_MONEY || fprop->datatype == DTYPE_FLOAT
	  || fprop->datatype == DTYPE_SMFLOAT)
	{
	  static char buff_new[256];
	  int a;
	  int c = 0;
	  memset (buff_new, 0, 255);

	  for (a = 0; a < strlen (fld_data); a++)
	    {
	      if ( ! A4GL_is_meaningful_in_decfmt(A4GL_get_convfmts()->ui_decfmt, fld_data[a]))
		  continue;
	      if (fld_data[a] == A4GL_get_convfmts()->ui_decfmt.decsep)
	      {
	        buff_new[c++] = A4GL_get_convfmts()->posix_decfmt.decsep;
	        continue;
	      }
	      buff_new[c++] = fld_data[a];
	    }
	  fld_data = buff_new;
	  A4GL_debug ("COPY -> %s instead", fld_data);
	}

//    }
  A4GL_debug ("Returning : %s", fld_data);
  return fld_data;
}



int
A4GL_check_and_copy_field_to_data_area (struct s_form_dets *form,
					struct struct_scr_field *fprop,
					char *fld_data, char *data_area)
{
  int pprval;
  int dsize;

  fld_data = A4GL_fld_data_ignore_format (fprop, fld_data);
  A4GL_debug ("Got fld_data as : %s", fld_data);
  if (A4GL_is_numeric_datatype(fprop->datatype))
  {
      char *tmpptr;
      tmpptr = strdup(fld_data);
      A4GL_decstr_convert(tmpptr,
	      A4GL_get_convfmts()->posix_decfmt,
	      A4GL_get_convfmts()->posix_decfmt, 0, 1, -1); // validate
      if (tmpptr[0] != 0) //conversion succesful
	  strcpy(fld_data, tmpptr);
      free (tmpptr);
  }
  A4GL_push_param (fld_data, DTYPE_CHAR);

  if ((fprop->datatype & 0xf) == DTYPE_CHAR
      || (fprop->datatype & 0xf) == DTYPE_VCHAR)
    {
      dsize = A4GL_get_field_width (form->currentfield);
    }
  else
    {
      dsize = fprop->dtype_size;
    }

  pprval = A4GL_pop_param (data_area, fprop->datatype, dsize);

  if (pprval)
    {
      if (A4GL_isnull (fprop->datatype, data_area))
	{
	  A4GL_debug
	    ("But I got a null back - strlen = %d fprop->datatype=%x %d",
	     strlen (fld_data), fprop->datatype, DTYPE_DTIME);
	  if (strlen (fld_data))
	    {
	      pprval = 0;
	    }
	}

      if (!A4GL_conversion_ok (-1))
	{
	  pprval = 0;
	}

      if ((fprop->datatype == DTYPE_INT || fprop->datatype == DTYPE_SMINT || fprop->datatype == DTYPE_SERIAL)) {
	{
		 if (a_strchr (fld_data, A4GL_get_convfmts()->ui_decfmt.decsep)) {
	  		A4GL_debug ("Looks like a decimal in a numeric field");
	  		pprval = 0;
		}
	}
	}
    }

  return pprval;

}

static int get_inc_quotes(int a) {
     if ((a & DTYPE_MASK ) == DTYPE_CHAR || (a & DTYPE_MASK) == DTYPE_VCHAR) return 1;
	if ((a & DTYPE_MASK) == DTYPE_DATE) return 2;
	if ((a & DTYPE_MASK) == DTYPE_DTIME) return 2;
	if ((a & DTYPE_MASK) == DTYPE_INTERVAL) return 2;
	return 0;
}

void UILIB_A4GL_direct_to_ui(char *t, char *s) {
// Does nothing - require by the API...
}


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
# $Id: ioform.c,v 1.237 2010-02-16 13:17:29 mikeaubury Exp $
#*/
#ifndef lint
static char const module_id[] = "$Id: ioform.c,v 1.237 2010-02-16 13:17:29 mikeaubury Exp $";
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
					     struct s_form_dets *formdets, int max_number, struct s_field_name_list *list);
static int get_inc_quotes (int a);
static char *set_current_display_delims = 0;
int A4GL_gen_field_list_with_orig_fldlist (FIELD *** field_list, struct s_field_name *orig_field_list, struct s_form_dets *formdets,
					   int max_number, va_list * ap, int replace_0);
int A4GL_gen_field_chars_ap_with_orig_fldlist (void *field_listv, void *formdetsv, struct s_field_name *fldlist, va_list * ap,
					       int replace_0);
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
int field_status_strip_tabname = 0;



extern WINDOW *currwin;
//int tab_cnt = 0;
//int srec_cnt = 0;
//char delimiters[4];
char *a_strchr (char *s, char c);
char *A4GL_fld_data_ignore_format (struct struct_scr_field *fprop, char *fld_data);
void A4GL_set_field_attr_with_attr_already_determined (FIELD * field, int attr, int cmd_type);
int A4GL_check_and_copy_field_to_data_area (struct s_form_dets *form,
					    struct struct_scr_field *fprop, char *fld_data, char *data_area, int var_dtype);
//int A4GL_get_field_width_w (void *f,int need_height);
void A4GL_set_infield_from_parameter (long a);
void A4GL_set_curr_infield (void *a);

//int lastc = 0;
//int nline;
//int ioform_fline;
//int ncol;
//char dbname[64];
void *inp_current_field = 0;
char *get_print_field_opts_as_string (FIELD * a);

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/






void A4GL_clr_field (FIELD * f);

static void A4GL_set_field_pop_attr (FIELD * field, int attr, int cmd_type);

static long A4GL_get_curr_infield (void);
static void A4GL_mja_set_field_buffer_contrl (FIELD * field, int nbuff, int ch);
static void A4GL_set_field_colour_attr (FIELD * field, int do_reverse, int colour);
void A4GL_mja_set_field_buffer (FIELD * field, int nbuff, char *buff);
static void A4GL_set_field_attr (FIELD * field);


int A4GL_field_name_match (FIELD * f, char *s);
static int A4GL_find_field_no (FIELD * f, struct s_screenio *sio);
int A4GL_do_after_field (FIELD * f, struct s_screenio *sio);
static int A4GL_get_metric_for (struct s_form_dets *form, FIELD * f);
//int A4GL_wcswidth(char *mbs);         /* utf8 */

static int local_chk_field (struct s_form_dets *form, FIELD * f, int allfields, int var_dtype);

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
#ifdef DEBUG
  A4GL_debug ("A4GL_make_label : '%s' l=%d", label, l);
#endif

  if (strlen (label) == 2 && label[0] == '\n')
    {
#ifdef DEBUG
      A4GL_debug ("Making graphic character %c @ frow=%d fcol=%d\n", label[1], frow, fcol);
#endif
      f = new_field (1, 1, frow, fcol, 0, 0);
    }
  else
    {
#ifdef DEBUG
      A4GL_debug ("Making normal label '%s' @ frow=%d fcol=%d\n", label, frow, fcol);
#endif
      f = new_field (1, l, frow, fcol, 0, 0);
    }

  if (f == 0)
    {
      A4GL_exitwith ("Unable to create field");
      return 0;
    }

  if (strlen (label) == 2 && label[0] == '\n')
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
#ifdef DEBUG
	      A4GL_debug ("Unknown graphic : %c", label[1]);
#endif
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
#ifdef DEBUG
		  A4GL_debug ("Unknown graphic : %c", label[1]);
#endif
		  is_graphics = 0;
		}
	    }
	  else
	    {
	      set_field_back (f, A_ALTCHARSET);
#ifdef DEBUG
	      A4GL_debug ("Extended graphics : %c ACS_HLINE=%d", label[1], ACS_HLINE);
#endif
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
#ifdef DEBUG
		  A4GL_debug ("Unknown graphic : %c", label[1]);
#endif
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
#ifdef DEBUG
      A4GL_debug ("99 set field buffer to label = **%s**", label);
#endif
      set_field_buffer (f, 0, label);
      local_set_field_opts (f, local_field_opts (f) & ~O_ACTIVE);
    }
  else
    {
#ifdef DEBUG
      {
#ifdef DEBUG
	A4GL_debug ("FIeld not created!!!");
#endif
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
#ifdef DEBUG
  A4GL_debug ("metrics len=%d", n);
#endif
  for (a = 0; a < n; a++)
    {
      int scr;
      int x;
      int y;
      int w;
      int h;
      char *label;
      x = formdets->fileform->metrics.metrics_val[a].x;
      y = formdets->fileform->metrics.metrics_val[a].y;
      w = formdets->fileform->metrics.metrics_val[a].w;
      h = formdets->fileform->metrics.metrics_val[a].h;
      scr = formdets->fileform->metrics.metrics_val[a].scr;
      label = formdets->fileform->metrics.metrics_val[a].label;


      formdets->fileform->metrics.metrics_val[a].pos_code = 0;
#ifdef DEBUG
      A4GL_debug ("checking label %s\n", label);
#endif


      if (strlen (label) != 0)
	{
	  formdets->fileform->metrics.metrics_val[a].field = (long) A4GL_make_label (y, x, label);

	  formdets->form_fields[cnt++] = (FIELD *) formdets->fileform->metrics.metrics_val[a].field;
	  A4GL_assertion (cnt >= MAX_FORM_FIELDS, "Ran out of form_fields...");
	  formdets->form_fields[cnt] = 0;
	}
      else
	{
#ifdef DEBUG
	  A4GL_debug ("Making field");
#endif
	  formdets->fileform->metrics.metrics_val[a].field = (long) A4GL_make_field (y, x, h, w);
	  formdets->form_fields[cnt++] = (FIELD *) formdets->fileform->metrics.metrics_val[a].field;
	  A4GL_assertion (cnt >= MAX_FORM_FIELDS, "Ran out of form_fields...");
	  formdets->form_fields[cnt] = 0;
	  formdets->fileform->metrics.metrics_val[a].dlm1 = (long) A4GL_make_label (y, x - 1, delims[0]);
	  formdets->form_fields[cnt++] = (FIELD *) formdets->fileform->metrics.metrics_val[a].dlm1;
	  A4GL_assertion (cnt >= MAX_FORM_FIELDS, "Ran out of form_fields...");
	  formdets->fileform->metrics.metrics_val[a].dlm2 = (long) A4GL_make_label (y, x + w, delims[1]);
	  formdets->form_fields[cnt++] = (FIELD *) formdets->fileform->metrics.metrics_val[a].dlm2;
	  A4GL_assertion (cnt >= MAX_FORM_FIELDS, "Ran out of form_fields...");
	  formdets->form_fields[cnt] = 0;
	}


      if (lscr != scr)
	{
	  lscr = scr;
	  set_new_page ((FIELD *) formdets->fileform->metrics.metrics_val[a].field, 1);
	}



      if (strlen (label) == 0)
	{
	  if (last_field == -1)
	    {
	      formdets->fileform->metrics.metrics_val[a].pos_code += POS_VERY_FIRST;
	    }
#ifdef DEBUG
	  A4GL_debug ("LAST_FIELD2 -CHK111");
	  A4GL_debug ("LAST_FIELD1 -CHK111");
#endif
	}

      if (lfieldscr != scr && strlen (label) == 0)
	{

	  formdets->fileform->metrics.metrics_val[a].pos_code += POS_FIRST;

	  if (last_field != -1)
	    {
	      formdets->fileform->metrics.metrics_val[last_field].pos_code += POS_LAST;
	    }
	  lfieldscr = formdets->fileform->metrics.metrics_val[a].scr;
	}
#ifdef DEBUG
      A4GL_debug ("LAST_FIELD3 -CHK111 a=%d label='%s'", a, label);
#endif
      if (strlen (label) == 0)
	last_field = a;
    }

#ifdef DEBUG
  A4GL_debug ("Last_field=%d\n", last_field);
#endif
  if (last_field < 0)
    {
      A4GL_exitwith ("Internal Error");
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
A4GL_default_attributes (FIELD * f, int dtype)
{
  struct struct_scr_field *fprop;

  int done = 0;

  fprop = (struct struct_scr_field *) (field_userptr (f));
#ifdef DEBUG
  A4GL_debug ("In def attrib f=%p", f);
#endif

  if (fprop)
    {
      if (A4GL_has_str_attribute (fprop, FA_S_PICTURE))
	{
#ifdef DEBUG
	  A4GL_debug ("ZZZZ - SET OPTS");
#endif
	  local_set_field_opts (f, O_VISIBLE | O_ACTIVE | O_PUBLIC | O_EDIT);
	  done = 1;
	}

    }



  if (done == 0)
    {

#ifdef DEBUG
      A4GL_debug ("MMMM DTYPE & 255 = %d", dtype);
#endif

      if ((dtype & 255) == DTYPE_CHAR || (dtype & 255) == DTYPE_VCHAR)
	{
#ifdef DEBUG
	  A4GL_debug ("ZZZZ - SET OPTS");
#endif
	  local_set_field_opts (f, O_VISIBLE | O_ACTIVE | O_PUBLIC | O_EDIT);
	  local_field_opts_off (f, O_BLANK);
	}
      else
	{
#ifdef DEBUG
	  A4GL_debug ("ZZZZ - SET OPTS");
#endif
#ifdef DEBUG
	  A4GL_debug ("BLANK BLANK");
#endif
	  if (A4GL_isyes (acl_getenv ("USEOBLANK")))
	    {
	      local_set_field_opts (f, O_VISIBLE | O_ACTIVE | O_PUBLIC | O_EDIT | O_BLANK);
	    }
	  else
	    {
	      local_set_field_opts (f, O_VISIBLE | O_ACTIVE | O_PUBLIC | O_EDIT);
	    }
	}
    }


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

#ifdef DEBUG
  A4GL_debug ("In set_field_attr");
#endif
  f = (struct struct_scr_field *) (field_userptr (field));
  if (f == 0)
    return;
#ifdef DEBUG
  A4GL_debug ("Setting defs");
#endif
  A4GL_default_attributes (field, f->datatype);
#ifdef DEBUG
  A4GL_debug ("Set defs");
#endif

  if (A4GL_has_bool_attribute (f, FA_B_AUTONEXT) && !A4GL_has_bool_attribute (f, FA_B_WORDWRAP))
    {
#ifdef DEBUG
      A4GL_debug ("Autoskip");
      A4GL_debug ("ZZZZ - SET OPTS");
#endif
      local_field_opts_on (field, O_AUTOSKIP);
    }

  if (A4GL_has_bool_attribute (f, FA_B_RIGHT))
    {
      int a;
      void *c = NULL;
      FORM *frm = NULL;
#ifdef DEBUG
      A4GL_debug ("RIGHT ALIGN...");
#endif
      frm = field->form;
      if (frm)
	{
	  c = frm->current;
	  frm->current = NULL;
	}

      a = set_field_just (field, JUSTIFY_RIGHT);
      field_opts_on (field, O_STATIC);
      if (a != E_OK)
	{
#ifdef DEBUG
	  A4GL_debug ("... .COULDNT SET RIGHT JUSTIFY");
#endif
	}
      if (frm)
	{
	  frm->current = c;
	}
    }

  if (A4GL_has_bool_attribute (f, FA_B_INVISIBLE))
    {
#ifdef DEBUG
      A4GL_debug ("Invisible ***");
      A4GL_debug ("ZZZZ - SET OPTS");
#endif
      if (!use_invisible_as_color_9 ())
	{
	  local_field_opts_off (field, O_PUBLIC);
	}
    }

  if (f->dynamic == 0)
    {
      local_field_opts_on (field, O_STATIC);
    }
  if (f->dynamic != 0)
    {
#ifdef DEBUG
      A4GL_debug ("ZZZZ - SET OPTS - STATIC OFF");
#endif
      local_field_opts_off (field, O_STATIC);


      if (f->dynamic == -1)
	{
#ifdef DEBUG
	  A4GL_debug ("Max size is lots");
#endif
	  if (!A4GL_isyes (acl_getenv ("ALLOWDYNAMIC")))
	    {
	      A4GL_assertion (1, "Dynamic fields not working atm...");
	    }
	  set_max_field (field, 0);	// DYNAMIC
	}
      else
	{
	  if (!A4GL_isyes (acl_getenv ("ALLOWDYNAMIC")))
	    {
	      A4GL_assertion (1, "Dynamic fields not working atm...");
	    }
	  set_max_field (field, f->dynamic);
#ifdef DEBUG
	  A4GL_debug ("Max size=%d", f->dynamic);
#endif
	}

    }

  if (A4GL_field_is_noentry (0, f))
    {
#ifdef DEBUG
      A4GL_debug ("No entry");
      A4GL_debug ("ZZZZ - SET OPTS - DISABLE ::::::::::::::::::::::::::::::::::::::::::::;;;");
      A4GL_debug ("removed- this may cause problems.....");
#endif


    }



  if (A4GL_has_bool_attribute (f, FA_B_REQUIRED))
    {
#ifdef DEBUG
      A4GL_debug ("ZZZZ - SET OPTS");
#endif
      local_field_opts_off (field, O_NULLOK);
    }
  else
    {
#ifdef DEBUG
      A4GL_debug ("ZZZZ - SET OPTS");
#endif
      local_field_opts_on (field, O_NULLOK);
    }

  if (A4GL_has_bool_attribute (f, FA_B_COMPRESS) || A4GL_has_bool_attribute (f, FA_B_WORDWRAP))
    {
#ifdef DEBUG
      A4GL_debug ("ZZZZ - SET OPTS");
#endif
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

#ifdef DEBUG
  A4GL_debug ("Passed in attribute: %x, determined attribute should be %x", attr, nattr);
#endif

  attr = nattr;

  if (attr & AUBIT_ATTR_REVERSE)
    r = 1;
  else
    r = 0;

#ifdef DEBUG
  A4GL_debug ("MJA Calling A4GL_set_field_colour_attr - do_reverse=%d attr=%d", r, attr);
#endif
  A4GL_set_field_colour_attr (field, r, attr);
}

void
A4GL_set_field_attr_with_attr_already_determined (FIELD * field, int attr, int cmd_type)
{
  int r;
  struct struct_scr_field *f;
  f = (struct struct_scr_field *) (field_userptr (field));


  if (attr & AUBIT_ATTR_REVERSE)
    r = 1;
  else
    r = 0;
#ifdef DEBUG
  A4GL_debug ("MJA Calling A4GL_set_field_colour_attr - do_reverse=%d attr=%d", r, attr);
#endif
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
  int a1, a2;
  char mm[20000];
  f = (struct struct_scr_field *) (field_userptr (field));
#ifdef DEBUG
  A4GL_debug ("set_field_colour_attr - do_reverse=%d colour=%d - %d\n", do_reverse, colour, A4GL_decode_colour_attr_aubit (colour));
#endif

  if (colour & AUBIT_ATTR_REVERSE && do_reverse == 0)
    {;
    }				// Maybe we should warn on these
  if (!(colour & AUBIT_ATTR_REVERSE) && do_reverse == 1)
    {;
    }				// Maybe we should warn on these

  if (A4GL_has_bool_attribute (f, FA_B_INVISIBLE) && use_invisible_as_color_9 ())
    {
      set_field_fore (field, 9 << 8);
      set_field_back (field, 9 << 8);
      return;
    }


  fg = A4GL_decode_aubit_attr (colour, 'f');
  bg = A4GL_decode_aubit_attr (colour, 'B');
  a1 = set_field_fore (field, fg);
  a2 = set_field_back (field, bg);

#ifdef DEBUG
  A4GL_debug ("FG=%x BG=%x a1=%d a2=%d for field %p", fg, bg, a1, a2, field);
#endif

// Redisplay the field to ensure the field attributes are use...
  strcpy (mm, field_buffer (field, 0));
  set_field_buffer (field, 0, mm);

  return;
}


/**
 *
 * @todo Describe function
 */
void
A4GL_set_init_value (FIELD * f, void *ptr, int dtype_passed_value, int dtype_field)
{
  char *ff;

#ifdef DEBUG
  A4GL_debug ("A4GL_set_init_value %p %x", ptr, dtype_passed_value);
#endif
  if (ptr)
    {
      A4GL_push_param (ptr, dtype_passed_value);
#ifdef DEBUG
      A4GL_debug ("Calling display_field_contents");
#endif
      A4GL_display_field_contents (f, dtype_passed_value & DTYPE_MASK, DECODE_SIZE (dtype_passed_value), ptr, dtype_field);
      return;
    }




#ifdef DEBUG
  A4GL_debug ("field width=%d", A4GL_get_field_width (f));
#endif
  if (ptr != 0)
    {
      A4GL_push_param (ptr, dtype_passed_value);
      ff = acl_malloc2 (A4GL_get_field_width (f) + 1);
      A4GL_pop_char (ff, A4GL_get_field_width (f));
    }
  else
    {
      int l;
      l = A4GL_get_field_width (f);
      ff = acl_malloc2 (l + 1);
      memset (ff, ' ', l);
      ff[l] = 0;
    }

  A4GL_mja_set_field_buffer (f, 0, ff);
  acl_free (ff);
#ifdef DEBUG
  A4GL_debug ("Init complete");
#endif
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
  struct struct_scr_field *fprop;


  formdets = formdetsv;
  A4GL_chkwin ();
  n = formdets->fileform->fields.fields_len;
#ifdef DEBUG
  A4GL_debug ("Got %d fields\n", n);
#endif

  formdets->fields_cnt = n;

  for (a = 0; a < n; a++)
    {
      ptr = A4GL_find_attribute (formdets, a);
      n1 = formdets->fileform->fields.fields_val[a].metric.metric_len;

      for (a1 = 0; a1 < n1; a1++)
	{
	  metric_no = formdets->fileform->fields.fields_val[a].metric.metric_val[a1];
#ifdef DEBUG
	  A4GL_debug ("Metric number read as %d\n", metric_no);
#endif

	  if (formdets->fileform->metrics.metrics_val[metric_no].field != 0)
	    {
#ifdef DEBUG
	      A4GL_debug ("Has an associated field");
#endif
	      if (ptr != 0)
		{
#ifdef DEBUG
		  A4GL_debug ("Has associated attribute!");
#endif
		  set_field_userptr ((FIELD *) formdets->fileform->metrics.metrics_val[metric_no].field, ptr);
		  A4GL_set_field_attr ((FIELD *) formdets->fileform->metrics.metrics_val[metric_no].field);
		  fprop = (struct struct_scr_field *) ptr;


#ifdef DEBUG
		  A4GL_debug ("Done\n");
#endif
		}
	    }
	}
    }
#ifdef DEBUG
  A4GL_debug ("formdets->form_fields=%p", formdets->form_fields);
#endif
  formdets->form = new_form ((FIELD **) formdets->form_fields);
  if (formdets->form == 0)
    {
      A4GL_exitwith ("Failed to create the loaded the form");
      return 0;
    }
  set_form_userptr (formdets->form, formdets);
#ifdef DEBUG
  A4GL_debug ("Loaded form...");
#endif
  return 1;
}


/**
 *
 * @todo Describe function
 */
void
A4GL_start_form (struct s_form_dets *s)
{
#ifdef DEBUG
  A4GL_debug ("Start form - %p %p", s, s->form);
#endif

  A4GL_int_form_driver (s->form, REQ_FIRST_PAGE);
  A4GL_int_form_driver (s->form, REQ_FIRST_FIELD);
  A4GL_mja_pos_form_cursor (s->form);

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
#ifdef DEBUG
  A4GL_debug ("CHeck fields 1 m=%d", m);
#endif
  form = sio->currform;
#ifdef DEBUG
  A4GL_debug ("CHeck fields 2 currentfield=%p status = %d", form->currentfield, field_status (form->currentfield));
#endif

  if (m > 0)
    {
#ifdef DEBUG
      A4GL_debug ("CHeck fields 3");
#endif
      form->currentfield = 0;
      form->currentmetrics = 0;
#ifdef DEBUG
      A4GL_debug (" m ");
#endif
      return 0;
    }


#ifdef DEBUG
  A4GL_debug (" current field %p  form says currfield=%p m=%d", form->currentfield, current_field (mform), m);
#endif
#ifdef DEBUG
  A4GL_debug
    ("field_status(form->currentfield)=%d field_status(currfield)=%d",
     field_status (form->currentfield), field_status (current_field (mform)));
#endif

  if ((form->currentfield != current_field (mform)) || m < 0)
    {
#ifdef DEBUG
      A4GL_debug ("Is different");
#endif

      if (form->currentfield != 0)
	{
	  int rval;
	  rval = local_chk_field (form, form->currentfield, 0, sio->vars[sio->curr_attrib].dtype);
	  if (rval == -4)
	    {
	      set_current_field (mform, form->currentfield);
	    }
	  return rval;
	}
    }


  return 0;
}


int
chk_all_fields (struct s_screenio *sio)
{
  int a;

  if (sio->mode != MODE_CONSTRUCT)
    {
      // Might need to do something similar for construct ? 
      for (a = 0; a <= sio->nfields; a++)
	{
	  if (local_chk_field (sio->currform, sio->field_list[a], 1, sio->vars[a].dtype) == -4)
	    {
	      return a;
	    }
	}
    }
  return -1;

}


int
local_chk_field (struct s_form_dets *form, FIELD * f, int allfields, int var_dtype)
{
  char buff[8000] = "";
  char buff2[8000] = "";
  char buff3[8000] = "";
  int pprval;
  int x, y;
  struct struct_scr_field *fprop = 0;
  int chk_required;


// We either check REQUIREDs after the FIELD, or AFTER INPUT...
  chk_required = 0;
  if (A4GL_input_required_handling () == REQUIRED_TYPE_FIELD)
    {
      if (allfields == 0)
	chk_required = 1;	// We'll check after each field...
      else
	chk_required = 0;
    }
  else
    {
      if (allfields == 0)
	chk_required = 0;	// We'll check after the input
      else
	chk_required = 1;
    }



  if (field_userptr (f) != 0)
    {
#ifdef DEBUG
      A4GL_debug ("Is a proper field");
#endif
      fprop = (struct struct_scr_field *) (field_userptr (f));
#ifdef DEBUG
      A4GL_debug ("fprop=%p", fprop);
#endif

      //if (A4GL_has_bool_attribute (fprop, FA_B_NOTNULL)) { // Force a 'REQUIRED' check for any "not null" fields..
      //chk_required=1;
      //}

      if (fprop != 0)
	{


	  if ((fprop->datatype & DTYPE_MASK) != DTYPE_CHAR)
	    {



	      A4GL_modify_size (&buff[4], form->fileform->metrics.metrics_val[A4GL_get_metric_for (form, f)].w);

	      strcpy (&buff[4], field_buffer (f, 0));

	      strcpy (buff2, &buff[4]);

	      if (A4GL_has_str_attribute (fprop, FA_S_PICTURE))
		{
		  int a;
		  int blank = 1;
		  char *picture;
		  picture = A4GL_get_str_attribute (fprop, FA_S_PICTURE);
#ifdef DEBUG
		  A4GL_debug ("HAS PICTURE MJA123 : %s", buff2);
#endif
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

		  if (A4GL_has_bool_attribute (fprop, FA_B_REQUIRED) && !A4GL_has_bool_attribute (fprop, FA_B_NOENTRY)
		      && chk_required)
		    {
		      int allow_it_anyway = 0;

		      // We'll still allow it - so long as there is null in the include list
		      if (A4GL_has_str_attribute (fprop, FA_S_INCLUDE))
			{
			  if (A4GL_check_field_for_include ("", A4GL_get_str_attribute (fprop, FA_S_INCLUDE), fprop->datatype))
			    {
			      allow_it_anyway = 1;
			    }
			}

		      if (!allow_it_anyway)
			{
#ifdef DEBUG
			  A4GL_debug ("FIELD_REQD_MSG");
#endif
			  // Well there wasn't - so it is required....
			  A4GL_error_nobox (acl_getenv ("FIELD_REQD_MSG"), 0);

			  //set_current_field (form->form, f);

			  return -4;
			}


		    }

		  // Could still be thrown out if we have an include without a null in it....
#ifdef DEBUG
		  A4GL_debug ("X2222 MAYBE");
#endif
		  if (A4GL_has_str_attribute (fprop, FA_S_INCLUDE))
		    {
		      if (A4GL_check_field_for_include ("", A4GL_get_str_attribute (fprop, FA_S_INCLUDE), fprop->datatype))
			{
			  return 1;
			}
		      else
			{
#ifdef DEBUG
			  A4GL_debug ("X2222 Check for include has null...");
#endif
			  A4GL_error_nobox (acl_getenv ("FIELD_INCL_MSG"), 0);
			  if (fprop != 0)
			    A4GL_comments (fprop);
			  return -4;
			}
		    }


		  return 0;
		}


	      if (A4GL_has_bool_attribute (fprop, FA_B_NOENTRY))
		{
#ifdef DEBUG
		  A4GL_debug ("Field %s set NOENTRY, skipping validation\n", fprop->colname);
#endif
		}
	      else
		{
#ifdef DEBUG
		  A4GL_debug ("Pushing to validate : %s\n", buff2);
#endif





		  pprval = A4GL_check_and_copy_field_to_data_area (form, fprop, buff2, buff, var_dtype);


#ifdef DEBUG
		  A4GL_debug ("pprval = %d\n", pprval);
#endif
		  if (!pprval)
		    {
		      A4GL_error_nobox (acl_getenv ("FIELD_ERROR_MSG"), 0);
		      if (fprop != 0)
			A4GL_comments (fprop);

		      if (A4GL_isyes (acl_getenv ("A4GL_CLR_FIELD_ON_ERROR")))
			{
			  A4GL_fprop_flag_clear (f, FLAG_MOVED_IN_FIELD);
			  A4GL_fprop_flag_set (f, FLAG_MOVING_TO_FIELD);

			  A4GL_clr_field (f);
			}
		      else
			{
			  if (A4GL_isyes (acl_getenv ("FIRSTCOL_ONERR")))
			    {
			      A4GL_fprop_flag_clear (f, FLAG_MOVED_IN_FIELD);
			      A4GL_fprop_flag_set (f, FLAG_MOVING_TO_FIELD);
			      A4GL_int_form_driver (form->form, REQ_BEG_FIELD);
			    }

			}


		      //set_current_field (mform, form->currentfield);
		      return -4;
		    }
		  else
		    {
#ifdef DEBUG
		      A4GL_debug ("pop_param returns ok...");
#endif
		    }
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


	  if (A4GL_check_field_for_include (buff3, A4GL_get_str_attribute (fprop, FA_S_INCLUDE), fprop->datatype) == 0)
	    {
#ifdef DEBUG
	      A4GL_debug ("Not in include list");
#endif
	      A4GL_fprop_flag_clear (f, FLAG_MOVED_IN_FIELD);
	      A4GL_fprop_flag_set (f, FLAG_MOVING_TO_FIELD);
	      A4GL_int_form_driver (form->form, REQ_BEG_FIELD);
	      A4GL_error_nobox (acl_getenv ("FIELD_INCL_MSG"), 0);
	      //set_current_field (mform, form->currentfield);
	      return -4;
	    }


	  if (A4GL_has_bool_attribute (fprop, FA_B_REQUIRED) && !A4GL_has_bool_attribute (fprop, FA_B_NOENTRY) && chk_required)
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
		      if (A4GL_check_field_for_include ("", A4GL_get_str_attribute (fprop, FA_S_INCLUDE), fprop->datatype))
			{
			  allow_it_anyway = 1;
			}
		    }
		  if (!allow_it_anyway)
		    {
#ifdef DEBUG
		      A4GL_debug ("FIELD_REQD_MSG");
#endif
		      A4GL_error_nobox (acl_getenv ("FIELD_REQD_MSG"), 0);
		      //set_current_field (mform, form->currentfield);
		      return -4;
		    }

		}
	    }

	  // Could still be thrown out if we have an include without a null in it....
	  if (A4GL_has_str_attribute (fprop, FA_S_INCLUDE))
	    {
	      if (A4GL_check_field_for_include ("", A4GL_get_str_attribute (fprop, FA_S_INCLUDE), fprop->datatype))
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
#ifdef DEBUG
  A4GL_debug ("In curr metric");
#endif
  for (a = 0; a < form->fileform->metrics.metrics_len; a++)
    {
      if (current_field (form->form) == (FIELD *) form->fileform->metrics.metrics_val[a].field)
	{
#ifdef DEBUG
	  A4GL_debug ("Returning %d\n", a);
#endif
	  return a;
	}
    }
#ifdef DEBUG
  A4GL_debug ("NO current metric !");
#endif
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

#ifdef DEBUG
  A4GL_debug ("In curr metric");
#endif
  for (a = 0; a < form->fileform->metrics.metrics_len; a++)
    {
      if (f == (FIELD *) form->fileform->metrics.metrics_val[a].field)
	{
#ifdef DEBUG
	  A4GL_debug ("Returning %d\n", a);
#endif
	  return a;
	}
    }
#ifdef DEBUG
  A4GL_debug ("NO current metric !");
#endif
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
#ifdef DEBUG
  A4GL_debug ("Turn Field Off %s %s", fprop->tabname, fprop->colname);
  A4GL_debug ("ZZZZ - SET OPTS");
#endif
  a = local_field_opts_off (f, O_ACTIVE);
#ifdef DEBUG
  A4GL_debug ("a=%d", a);
#endif
  a += local_field_opts_off (f, O_EDIT);
#ifdef DEBUG
  A4GL_debug ("a=%d", a);
#endif
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
#ifdef DEBUG
  A4GL_debug ("Turn Field On %s %s", fprop->tabname, fprop->colname);
#endif
#ifdef DEBUG
  A4GL_debug ("ZZZZ - SET OPTS");
#endif
  a = local_field_opts_on (f, O_ACTIVE);
#ifdef DEBUG
  A4GL_debug ("a=%d", a);
#endif
  a = local_field_opts_on (f, O_EDIT);
  if ((fprop->datatype & 255) != DTYPE_CHAR && (fprop->datatype & 255) != DTYPE_VCHAR)
    {
      if (A4GL_isyes (acl_getenv ("USEOBLANK")))
	{
	  local_field_opts_on (f, O_BLANK);
	}
    }
#ifdef DEBUG
  A4GL_debug ("a=%d", a);
#endif
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
  int xx = 0;
  A4GL_assertion (f == 0, "Field is zero in turn_field_on2");
#ifdef DEBUG
  A4GL_debug ("Turn field on %p %d", f, a);
#endif
  fprop = (struct struct_scr_field *) (field_userptr (f));
  A4GL_assertion (fprop == 0, "Field has no properties");
#ifdef DEBUG
  A4GL_debug ("turn_field_on2 a=%d fprop=%p", a, fprop);
  A4GL_debug ("Turn Field On %p %p", fprop->tabname, fprop->colname);
  A4GL_debug ("Turn Field On %s %s", fprop->tabname, fprop->colname);
#endif
  local_field_opts_on (f, O_ACTIVE);
  local_field_opts_on (f, O_EDIT);
  if ((fprop->datatype & 255) != DTYPE_CHAR && (fprop->datatype & 255) != DTYPE_VCHAR)
    {
      if (A4GL_isyes (acl_getenv ("USEOBLANK")))
	{
	  local_field_opts_on (f, O_BLANK);
	}
    }

  A4GL_set_field_attr (f);


  if (fprop->dynamic != 0)
    {
      if (!A4GL_isyes (acl_getenv ("ALLOWDYNAMIC")))
	{
	  A4GL_assertion (1, "Dynamic fields not working atm...");
	}
      if (fprop->dynamic < 0)
	{
	  set_max_field (f, 0);	// DYNAMIC - Lots
	}
      else
	{
	  set_max_field (f, fprop->dynamic);	// DYNAMIC
	}
    }
  else
    {
      int w;
      if (!a)
	{
	  //set_max_field (f, 0); // CONSTRUCT
	  if (A4GL_has_bool_attribute (fprop, FA_B_AUTONEXT) && !A4GL_has_bool_attribute (fprop, FA_B_WORDWRAP))
	    {
	      local_field_opts_off (f, O_AUTOSKIP);
	    }
	  return;
	}
      w = A4GL_get_field_width_w (f, 0);
      if (w != 0)
	{
	  xx = set_max_field (f, w);
	}


      if (xx != 0)
	{
	  f->dcols = f->cols;
	  f->maxgrow = f->cols;
	  if (w != 0)
	    {
	      xx = set_max_field (f, w);
	    }
	  A4GL_mja_pos_form_cursor (f->form);
	}

#ifdef DEBUG
      A4GL_debug ("set_max_field : %d\n", w);
#endif
      if (xx != 0)
	{
#ifdef DEBUG
	  A4GL_debug ("Unable to change field width\n");
#endif
	  A4GL_assertion (1, "Internal error - unable to change field width");
	  A4GL_exitwith ("Internal error - unable to change field width");
	  return;
	}
    }


}


int
A4GL_get_field_width_w (void *f, int need_height)
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
  mno = A4GL_get_metric_for (formdets, f);
#ifdef DEBUG
  A4GL_debug ("mno=%d formdets=%p f=%p\n", mno, formdets, f);
#endif
  A4GL_assertion (mno < 0, "Invalid metric number");
  w = formdets->fileform->metrics.metrics_val[mno].w;
  if (need_height)
    {
      if (formdets->fileform->metrics.metrics_val[A4GL_get_metric_for (formdets, f)].h > 1)
	{
	  w *= formdets->fileform->metrics.metrics_val[A4GL_get_metric_for (formdets, f)].h;
	}
    }

  return w;
}

void
debug_print_field_opts (struct s_form_dets *formdets)
{
  int a;
  if (formdets == 0)
    return;

  for (a = 0; formdets->form_fields[a]; a++)
    {
      void *f;
      struct struct_scr_field *field;
      f = formdets->form_fields[a];

      field = (struct struct_scr_field *) (field_userptr (f));
#ifdef DEBUG
      A4GL_debug ("DPFO_FIELD %d BUFFER='%s' - OPTS=%x (%s) field_fore=%x field_back=%x", a, field_buffer (f, 0), field_opts (f),
		  get_print_field_opts_as_string (f), field_fore (f), field_back (f));
#endif
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
      return;
    }

  nofields = sio->nfields;
  field_list = (FIELD **) sio->field_list;
  nv = sio->novars;

  debug_print_field_opts (formdets);

  for (a = 0; formdets->form_fields[a]; a++)
    {
      int should_be_on = 0;
      void *f;
      f = formdets->form_fields[a];
      field = (struct struct_scr_field *) (field_userptr (formdets->form_fields[a]));

      if (field == 0)
	continue;

      for (b = 0; b <= nofields; b++)
	{
	  if (f == field_list[b])
	    {
#ifdef DEBUG
	      A4GL_debug ("Should be on... %p", f);
#endif
	      should_be_on++;
	      break;
	    }
	}

      if (should_be_on)
	{
	  A4GL_turn_field_on2 (f, sio->mode != MODE_CONSTRUCT);
	}
      else
	{
	  A4GL_turn_field_off (f);
	}

    }

  debug_print_field_opts (formdets);

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
  int changed = 0;
  FIELD **field_list;
  FIELD *firstfield = 0;
  int nofields;
  struct s_screenio *sio;
  FORM *mform;
  int attr;
  FIELD *was_current;
  static int has_pad_char = -1;
  static int pad_char;

  sio = vsio;
  if (has_pad_char == -1)
    {
      // @env PADCHAR sets the padding attribute (normally blank) 
      if (acl_getenv_not_set_as_0 ("PADCHAR") == 0)
	{
	  has_pad_char = 0;
	}
      else
	{
	  has_pad_char = 1;
	  pad_char = atoi (acl_getenv ("PADCHAR"));
	}
    }

  wid = 0;
  if (sio->mode == MODE_INPUT_WITHOUT_DEFAULTS || sio->mode == MODE_INPUT_ARRAY)
    wid = 1;
#ifdef DEBUG
  A4GL_debug ("in set fields");
#endif
  formdets = sio->currform;
  if (formdets == 0)
    {
      A4GL_exitwith ("No form");
      return 0;
    }
#ifdef DEBUG
  A4GL_debug ("set fdets");
#endif

  flg = 0;

#ifdef DEBUG
  A4GL_debug ("Turning off all");
  A4GL_debug ("Mform=%p\n", sio->currform->form);
#endif
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

#ifdef DEBUG
  A4GL_debug ("Field list=%p number of fields = %d", field_list, nofields);
#endif

  nv = sio->novars;
  if (sio->mode == MODE_CONSTRUCT)
    {
      int a;
      int need_fix = 0;
      // this may need explanding if the column contains a '*'
      for (a = 0; a < nv; a++)
	{
	  sio->constr[a].value = 0;
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
#ifdef DEBUG
      A4GL_debug ("Number of fields (%d) is not the same as the number of vars (%d)", nofields + 1, nv);
#endif
      A4GL_exitwith ("Number of fields is not the same as the number of variables");
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
#ifdef DEBUG
      A4GL_debug ("loop through fields a=%d %p", a, field_list[a]);
#endif
      if (sio->mode == MODE_CONSTRUCT)
	{
	  FIELD *f;
	  FORM *frm;
	  f = field_list[a];
	  frm = f->form;


	}


      A4GL_turn_field_on2 (field_list[a], sio->mode != MODE_CONSTRUCT);

      if (wid)
	{
#ifdef DEBUG
	  A4GL_debug ("99 wid set_init_value as in variable");
#endif
	  A4GL_set_init_value (field_list[a], sio->vars[a].ptr, sio->vars[a].dtype + ENCODE_SIZE (sio->vars[a].size),
			       sio->vars[a].dtype + ENCODE_SIZE (sio->vars[a].size));

	  changed = 0;

	}
      else
	{
	  prop = (struct struct_scr_field *) field_userptr (field_list[a]);
	  if (A4GL_has_str_attribute (prop, FA_S_DEFAULT) && sio->mode != MODE_CONSTRUCT)
	    {
	      int dtype;
	      char *defval;
#ifdef DEBUG
	      A4GL_debug ("99  set_init_value from form");
	      A4GL_debug ("default from form to '%s'", A4GL_get_str_attribute (prop, FA_S_DEFAULT));
#endif
	      dtype = sio->vars[a].dtype + ENCODE_SIZE (sio->vars[a].size);
	      defval = A4GL_replace_sql_var (A4GL_strip_quotes (A4GL_get_str_attribute (prop, FA_S_DEFAULT)));
	      // We're passing in the default value as a character string - even if its not really
	      // supposed to be a character string...
	      A4GL_set_init_value (field_list[a], defval, DTYPE_CHAR, sio->vars[a].dtype + ENCODE_SIZE (sio->vars[a].size));

	      changed++;
	      //set_field_status (field_list[a], 1);


	    }
	  else
	    {
#ifdef DEBUG
	      A4GL_debug ("99  set_init_value as nothing...");
#endif
	      changed = 1;
	      A4GL_set_init_value (field_list[a], 0, 0, 0);
	    }
	}

      if (sio->mode != MODE_CONSTRUCT)
	{
	  prop = (struct struct_scr_field *) field_userptr (field_list[a]);


	  if (changed)
	    {			// default value used
	      strcpy (buff, A4GL_fld_data_ignore_format (prop, field_buffer (field_list[a], 0)));

	      A4GL_trim (buff);

	      if (strlen (buff))
		{
		  A4GL_push_char (buff);
		}
	      else
		{
		  if (A4GL_has_bool_attribute (prop, FA_B_NOTNULL))
		    {
		      A4GL_push_char (" ");
		    }
		  else
		    {
		      A4GL_push_null (sio->vars[a].dtype, sio->vars[a].size);	// @todo - check if its set to not null and return CHARs instead..
		    }
		}
#ifdef DEBUG
	      A4GL_debug ("Calling pop_var2..");
#endif

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


      if (has_pad_char)
	{
	  set_field_pad (field_list[a], pad_char);
	}

      set_field_status (field_list[a], 0);
      A4GL_fprop_flag_clear (field_list[a], 0xff);	// ALL
    }

  if (firstfield)
    A4GL_turn_field_off (firstfield);

  if (flg == 0)
    {
      A4GL_error_box ("NO active field\n", 0);
    }
  if (sio->mode == MODE_CONSTRUCT)
    {
      FORM *frm;
      frm = sio->currform->form;



#ifdef NCURSES_VERSION
      // For some reason the window associated with 
      // a field isn't being cleared properly...
      // lets make sure it is....
      // build test 1253 demonstrates this...
      werase (frm->w);
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
#ifdef DEBUG
  A4GL_debug ("field_name_match : '%s' '%s'", tabname, colname);
#endif

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

#ifdef DEBUG
  A4GL_debug ("No srec_no...");
#endif
  aa = strcmp (field->tabname, tabname);
  ab = strcmp (field->colname, colname);
#ifdef DEBUG
  A4GL_debug ("Column defined as %s %s", field->tabname, field->colname);
#endif

  if ((aa == 0 && ab == 0) || (aa == 0 && colname[0] == '*'))
    {
#ifdef DEBUG
      A4GL_debug ("Matches in .*");
#endif
      return 1;
    }

  if (ab == 0 && tabname[0] == 0)
    {
#ifdef DEBUG
      A4GL_debug ("matches just on column");
#endif
      return 1;

    }

#ifdef DEBUG
  A4GL_debug ("Doesn't A4GL_match - %d %d", aa, ab);
#endif
  if (srec_no == -1)
    return 0;

#ifdef DEBUG
  A4GL_debug ("but - Have an srec_no...");
#endif

#ifdef DEBUG
  A4GL_debug ("Match 2");
#endif
// Maybe its a screen record - not a table name....




  for (z = 0; z < fdets->fileform->records.records_val[srec_no].attribs.attribs_len; z++)
    {
      int attr_no;
      attr_no = fdets->fileform->records.records_val[srec_no].attribs.attribs_val[z];
#ifdef DEBUG
      A4GL_debug ("attr_no=%d - %s %s", attr_no,
		  fdets->fileform->attributes.attributes_val[attr_no].tabname,
		  fdets->fileform->attributes.attributes_val[attr_no].colname);
#endif
      if (strcmp (fdets->fileform->attributes.attributes_val[attr_no].colname, colname) == 0)
	{			// We've found our entry in the screen record
	  if (strcmp (tabname, fdets->fileform->attributes.attributes_val[attr_no].tabname) != 0)
	    {
	      char buff[256];
	      SPRINTF2 (buff, "%s.%s",
			fdets->fileform->attributes.attributes_val[attr_no].
			tabname, fdets->fileform->attributes.attributes_val[attr_no].colname);
	      if (A4GL_field_name_match (f, buff))
		return 1;
	    }
	}
    }
  return 0;
}

/*
 This function sets a value which is used for the
 beginning and end of field delimiters (normally [ and ] )
 so that they can be easily changed from the 4gl code

 This is normally done to emulate the isql perform action
 where only the fields for the current form have their '[' and ']'
 displayed.

 In order to use this value - you have to DISPLAY something to the field

        Example usage :


        call aclfgl_set_display_field_delimiters("  ")
        display "hh" to tabname
        call aclfgl_set_display_field_delimiters("[]")
        display "hh" to tabname
*/

int
UILIB_aclfgl_aclfgl_set_display_field_delimiters (int n)
{
  if (set_current_display_delims)
    free (set_current_display_delims);
  set_current_display_delims = A4GL_char_pop ();
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
#ifdef DEBUG
  A4GL_debug ("In disp_fields");
#endif
  formdets = UILIB_A4GL_get_curr_form (1);
#ifdef DEBUG
  {
    A4GL_debug ("Status=%d formdets=%p", a4gl_status, formdets);
  }
#endif
  if (a4gl_status != 0)
    return 0;
  flg = 0;

#ifdef DEBUG
  A4GL_debug (" field_list = %p", &field_list);
  {
    A4GL_debug ("Genfldlist 2");
  }
  A4GL_debug ("disp_fields");
#endif
  nofields = A4GL_gen_field_list (&field_list, formdets, n, ap, 0);
#ifdef DEBUG
  A4GL_debug ("Number of fields=%d ", nofields, n);
#endif

  if (nofields < 0)
    {
#ifdef DEBUG
      A4GL_debug ("Failed to find fields");
#endif
      return 0;
    }

  for (a = nofields; a >= 0; a--)
    {
#ifdef DEBUG
      A4GL_debug ("field_list[%d]=%p", a, field_list[a]);
#endif
      A4GL_debug_print_field_opts (field_list[a]);
      /* fldattr=field_opts(field_list[a]); */
#ifdef DEBUG
      A4GL_debug ("MJA Calling A4GL_set_field_pop_attr - 1 - attr=%d", attr);
#endif

      if (set_current_display_delims)
	{
	  int dl;
	  // Search through our fields and get our metrics_val - that way
	  // we can change our delimiters
	  for (dl = 0; dl < formdets->fileform->metrics.metrics_len; dl++)
	    {
	      if ((FIELD *) formdets->fileform->metrics.metrics_val[dl].field == (FIELD *) field_list[a])
		{
		  char buff[2];
		  buff[1] = 0;
		  buff[0] = set_current_display_delims[0];
		  set_field_buffer ((FIELD *) formdets->fileform->metrics.metrics_val[dl].dlm1, 0, buff);
		  buff[0] = set_current_display_delims[1];
		  set_field_buffer ((FIELD *) formdets->fileform->metrics.metrics_val[dl].dlm2, 0, buff);
		}
	    }
	}

      if (field_list[a])
	{
	  A4GL_set_field_pop_attr (field_list[a], attr, FGL_CMD_DISPLAY_CMD);
	  fprop = (struct struct_scr_field *) (field_userptr (field_list[a]));
	  A4GL_fprop_flag_set (field_list[a], FLAG_FIELD_TOUCHED);
	}
      else
	{
	  A4GL_exitwith ("Field or field subscript was not found");
	  return 0;
	}



      /* rc=set_field_opts(field_list[a],fldattr); */
      A4GL_debug_print_field_opts (field_list[a]);
#ifdef DEBUG
      A4GL_debug ("set_init_pop complete");
#endif
    }

  free (field_list);

  A4GL_mja_wrefresh (currwin);
//UILIB_A4GL_zrefresh();
  return 1;
}



/**
 * 4GL CALL
 * @todo Describe function
 */
int
UILIB_A4GL_gen_field_chars_ap (void *field_listv, void *formdetsv, va_list * ap, int replace_0)
{
  int a;
  FIELD ***field_list;
  struct s_form_dets *formdets;

  field_list = field_listv;
  formdets = formdetsv;

  a = A4GL_gen_field_list (field_list, formdets, 9999, ap, replace_0);
  return a;
}


int
A4GL_gen_field_chars_ap_with_orig_fldlist (void *field_listv, void *formdetsv, struct s_field_name *fldlist, va_list * ap,
					   int replace_0)
{
  int a;
  FIELD ***field_list;
  struct s_form_dets *formdets;

  field_list = field_listv;
  formdets = formdetsv;

  a = A4GL_gen_field_list_with_orig_fldlist (field_list, fldlist, formdets, 9999, ap, replace_0);
  return a;
}



int
UILIB_A4GL_gen_field_list_from_slist (void *field_listv, void *formdetsv, void *listv)
{
  int a;
  FIELD ***field_list;
  struct s_form_dets *formdets;
  struct s_field_name_list *list;

  field_list = field_listv;
  formdets = formdetsv;
  list = listv;

  a = A4GL_gen_field_list_from_slist_internal (field_list, formdets, 9999, list);
  return a;
}

/**
 *
 * @todo Describe function
 */
int
A4GL_gen_field_list_from_slist_internal (FIELD *** field_list,
					 struct s_form_dets *formdets, int max_number, struct s_field_name_list *list)
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
  int fmetric = 0;
  struct struct_metrics *k;
  int attr_no;
  int srec_no;
  int cnt = 0;
#ifdef DEBUG
  A4GL_debug ("a=%d\n", max_number);
#endif


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

#ifdef DEBUG
      A4GL_debug (" got field number as %d z1=%d list=^p", fmetric, z1);
#endif

      ff = 0;

      /* get screen record/table name */
      memset (tabname, 0, sizeof (tabname));
      memset (colname, 0, sizeof (colname));
      A4GL_bname (s, tabname, colname);
      srec_no = A4GL_find_srec (formdets->fileform, tabname);
#ifdef DEBUG
      A4GL_debug ("tabname='%s' colname='%s' fpos=%d", tabname, colname, fmetric);
#endif
      if (strlen (tabname) && strlen (colname) && srec_no == -1)
	{
	  if (!field_status_strip_tabname)
	    {
	      A4GL_exitwith ("Table/Screen record does not exist in form");
	    }
	  return -1;
	}

#ifdef DEBUG
      A4GL_debug ("srec_no=%d", srec_no);
#endif
      if (srec_no != -1)
	{
	  for (z = 0; z < formdets->fileform->records.records_val[srec_no].attribs.attribs_len; z++)
	    {
#ifdef DEBUG
	      A4GL_debug ("srec_no=%d", srec_no);
#endif
	      attr_no = formdets->fileform->records.records_val[srec_no].attribs.attribs_val[z];
#ifdef DEBUG
	      A4GL_debug ("attr_no=%d", attr_no);
#endif
#ifdef DEBUG
	      {
#ifdef DEBUG
		A4GL_debug ("Attr 1");
#endif
	      }
#endif
#ifdef DEBUG
	      A4GL_debug ("attr_no=%d s=%s\n", attr_no, s);
#endif
	      mno = A4GL_attr_name_match (&formdets->fileform->attributes.attributes_val[attr_no], s);
#ifdef DEBUG
	      A4GL_debug ("mno=%d\n", mno);
#endif

	      if (mno)
		{
		  fno = formdets->fileform->attributes.attributes_val[attr_no].field_no;
#ifdef DEBUG
		  A4GL_debug ("Matched to field no %d", fno);
#endif
		  if (fno >= formdets->fileform->fields.fields_len)
		    {
		      A4GL_exitwith ("Dubious form\n");
		      return -1;	// Was 0
		    }

		  if (fmetric < 0 || fmetric >= formdets->fileform->fields.fields_val[fno].metric.metric_len)
		    {
		      A4GL_exitwith ("Field subscript out of bounds");
		      return -1;

		    }


		  metric_no = formdets->fileform->fields.fields_val[fno].metric.metric_val[fmetric];
#ifdef DEBUG
		  A4GL_debug ("fno=%d f=%d mno=%d metric_no=%d\n", fno, fmetric, mno, metric_no);
#endif
		  k = &formdets->fileform->metrics.metrics_val[metric_no];

		  if (cnt >= max_number)
		    {
#ifdef DEBUG
		      A4GL_debug ("cnt=%d a=%d", cnt, max_number);
#endif
		      A4GL_exitwith ("Too few variables for the number of fields");
		      return -1;
		    }
#ifdef DEBUG
		  A4GL_debug ("Setting flist[%d] to %p", cnt, k);
#endif
		  flist[cnt++] = (FIELD *) k->field;
#ifdef DEBUG
		  A4GL_debug ("Set");
#endif
		  ff = 1;
		  /* Test  278 -  multi occurences of the same name for  a fieldname in a form 
		     Just use the first one if no table is specified...
		   */
#ifdef DEBUG
		  A4GL_debug ("fmetric=%d len=%d", fmetric, strlen (tabname));
#endif

		  if (fmetric == 0 && strlen (tabname) == 0)
		    {
#ifdef DEBUG
		      A4GL_debug ("Are you Test 278...?");
#endif
		      z = formdets->fileform->records.records_val[srec_no].attribs.attribs_len;
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
	      mno = A4GL_attr_name_match (&formdets->fileform->attributes.attributes_val[attr_no], s);
#ifdef DEBUG
	      A4GL_debug ("mno=%d\n", mno);
#endif

	      if (mno)
		{
		  fno = formdets->fileform->attributes.attributes_val[attr_no].field_no;
#ifdef DEBUG
		  A4GL_debug ("Matched to field no %d - len=%d f=%d", fno,
			      formdets->fileform->fields.fields_val[fno].metric.metric_len, fmetric);
#endif
		  if (formdets->fileform->fields.fields_val[fno].metric.metric_len <= fmetric || fmetric < 0)
		    {
		      A4GL_exitwith ("Field subscript out of bounds");
		      return -1;
		    }
		  metric_no = formdets->fileform->fields.fields_val[fno].metric.metric_val[fmetric];
		  k = &formdets->fileform->metrics.metrics_val[metric_no];
#ifdef DEBUG
		  {
		    A4GL_debug ("cnt=%d a=%d", cnt, max_number);
		  }
#endif
		  if (cnt >= max_number)	/* was >= */
		    {
#ifdef DEBUG
		      A4GL_debug ("cnt=%d a=%d", cnt, max_number);
		      A4GL_debug ("Too few variables");
#endif
		      A4GL_exitwith ("Too few variables for the number of fields");
		      return -1;
		    }
#ifdef DEBUG
		  A4GL_debug ("Setting flist[%d] to %p", cnt, k);
#endif
		  flist[cnt++] = (FIELD *) k->field;
#ifdef DEBUG
		  A4GL_debug ("aa");
#endif
		  if (fmetric == 0 && strlen (tabname) == 0)
		    {
#ifdef DEBUG
		      A4GL_debug ("Are you Test 278...?");
#endif
		      z = formdets->fileform->attributes.attributes_len + 1;
		    }
		  ff = 1;
		}
#ifdef DEBUG
	      A4GL_debug ("aa");
#endif
	    }
#ifdef DEBUG
	  A4GL_debug ("aa");
#endif

	}
#ifdef DEBUG
      A4GL_debug ("aa");
#endif
      if (ff == 0)
	{
	  A4GL_exitwith ("Field name not found");
	  return -1;
	}

    }

#ifdef DEBUG
  A4GL_debug ("Alloc : cnt=%d ", cnt);
#endif

  *field_list = calloc (cnt + 1, sizeof (FIELD *));
#ifdef DEBUG
  A4GL_debug ("Allocated : %p", *field_list);
#endif
  memcpy (*field_list, flist, sizeof (FIELD *) * (cnt + 1));
#ifdef DEBUG
  A4GL_debug ("Copied...");
#endif
  return cnt - 1;
}



// ADDED FOR MID 1014
static void
remove_tables_from_list (struct s_field_name_list *list)
{
  int a;

  for (a = 0; a < list->nfields; a++)
    {
      char *ptr;
      ptr = strchr (list->field_name_list[a].fname, '.');
      if (ptr)
	{
	  list->field_name_list[a].fname = ptr + 1;
	}
    }

}





/**
 *
 * @todo Describe function
 */
int
A4GL_gen_field_list_with_orig_fldlist (FIELD *** field_list, struct s_field_name *fldlist, struct s_form_dets *formdets,
				       int max_number, va_list * ap, int replace_0)
{
  struct s_field_name_list list;
  int n;
  list.field_name_list = 0;
  A4GL_make_field_slist_from_ap_with_field_list (&list, ap, replace_0, fldlist);

  n = A4GL_gen_field_list_from_slist_internal (field_list, formdets, max_number, &list);


  if (field_status_strip_tabname && n == -1 && !A4GL_isno (acl_getenv ("FIELDTOUCHEDTABLEFIXUP")))
    {				// MID 1014
      remove_tables_from_list (&list);
      n = A4GL_gen_field_list_from_slist_internal (field_list, formdets, max_number, &list);
    }				// END OF MID 1014


  free (list.field_name_list);
  return n;

}

/**
 *
 * @todo Describe function
 */
int
A4GL_gen_field_list (FIELD *** field_list, struct s_form_dets *formdets, int max_number, va_list * ap, int replace_0)
{
  return A4GL_gen_field_list_with_orig_fldlist (field_list, NULL, formdets, max_number, ap, replace_0);
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

  mform = sio->currform->form;
#ifdef DEBUG
  A4GL_debug ("Do after field status=%d", field_status (f));
  A4GL_debug ("do after field buffer set to '%s'", field_buffer (f, 0));
#endif

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
	A4GL_debug ("   Ptr=%p dtype=%d size=%d", sio->vars[a].ptr, sio->vars[a].dtype, sio->vars[a].size);
      }
#endif

      /* now check that the form corresponds to the includes */
      if (sio->currform->currentfield)
	{
#ifdef DEBUG
	  A4GL_debug ("Got current field %p\n", sio->currform->currentfield);
#endif
	  fprop = (struct struct_scr_field *) (field_userptr (f));
#ifdef DEBUG
	  A4GL_debug ("Got form %p", sio->currform->form);
#endif
	  if (A4GL_check_field_for_include
	      (field_buffer (sio->currform->currentfield, 0), A4GL_get_str_attribute (fprop, FA_S_INCLUDE), fprop->datatype) == 0)
	    {
	      A4GL_error_nobox (acl_getenv ("FIELD_INCL_MSG"), 0);
	      A4GL_fprop_flag_clear (sio->currform->currentfield, FLAG_MOVED_IN_FIELD);
	      A4GL_fprop_flag_set (sio->currform->currentfield, FLAG_MOVING_TO_FIELD);
	      A4GL_int_form_driver (mform, REQ_BEG_FIELD);
	      set_current_field (mform, sio->currform->currentfield);
	    }
	}

#ifdef DEBUG
      A4GL_debug ("Calling pop_var2..");
#endif
      A4GL_pop_var2 (sio->vars[a].ptr, sio->vars[a].dtype, sio->vars[a].size);

    }
  else
    {
      fprop = (struct struct_scr_field *) (field_userptr (f));
      if (fprop != 0)
	{
	  if (fprop->colname != 0)
	    {
	      char *fbuf;
	      fbuf = field_buffer (f, 0);

	      if (sio->constr[a].value)
		{
		  fbuf = sio->constr[a].value;
		}
#ifdef DEBUG
	      A4GL_debug ("Calling constr with : '%s' '%s' datatype=%d", sio->constr[a].tabname, sio->constr[a].colname,
			  fprop->datatype);
#endif

	      ptr =
		(char *) A4GL_construct (sio->constr[a].tabname, sio->constr[a].colname, fbuf, get_inc_quotes (fprop->datatype),
					 fprop->datatype, fprop->dtype_size, sio->callback_function);
#ifdef DEBUG
	      A4GL_debug ("ptr=%s", ptr);
#endif
	      if (ptr == 0)
		{
		  A4GL_error_nobox (acl_getenv ("FIELD_CONSTR_EXPR"), 0);
		  A4GL_fprop_flag_clear (f, FLAG_MOVED_IN_FIELD);
		  A4GL_fprop_flag_set (f, FLAG_MOVING_TO_FIELD);
		  A4GL_int_form_driver (mform, REQ_BEG_FIELD);

		  return 0;
		}
	    }
	}
    }
#ifdef DEBUG
  A4GL_debug ("Done after field - field_status=%d", field_status (f));
#endif
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
#ifdef DEBUG
  A4GL_debug ("Creating new field entry y=%d x=%d rows=%d width=%d\n", frow, fcol, rows, cols);
  A4GL_debug ("Creating new field entry y=%d x=%d rows=%d width=%d\n", frow, fcol, rows, cols);
#endif

  f = new_field (rows, cols, frow, fcol, 0, 0);

  if (f)
    {
#ifdef DEBUG
      A4GL_debug ("Field created - setting attributes");
#endif
      /*A4GL_set_field_attr (f); */
#ifdef DEBUG
      A4GL_debug ("ZZZZ - SET OPTS");
#endif
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

#ifdef DEBUG
  A4GL_debug ("f->do_reverse=%d attr=%x", a, attr);
#endif


  if (A4GL_has_bool_attribute (f, FA_B_RIGHT))
    {
      int a;
      void *c = NULL;
      FORM *frm = NULL;
#ifdef DEBUG
      A4GL_debug ("RIGHT ALIGN...");
#endif

      frm = field->form;
      if (frm)
	{
	  c = frm->current;
	  frm->current = NULL;
	}

      a = set_field_just (field, JUSTIFY_RIGHT);
      field_opts_on (field, O_STATIC);
      if (a != E_OK)
	{
#ifdef DEBUG
	  A4GL_debug ("... .COULDNT SET RIGHT JUSTIFY");
#endif
	}
      if (frm)
	{
	  frm->current = c;
	}
    }

#ifdef DEBUG
  A4GL_debug ("Justification : %d (%d %d %d %d)\n", field_just (field), NO_JUSTIFICATION, JUSTIFY_RIGHT, JUSTIFY_LEFT,
	      JUSTIFY_CENTER);
#endif


  A4GL_display_field_contents (field, d1, s1, ptr1, d1 + ENCODE_SIZE (s1));




#ifdef DEBUG
  A4GL_debug ("set f->do_reverse to %d ", f->do_reverse);
#endif
  oopt = local_field_opts (field);
  A4GL_set_field_attr (field);
#ifdef DEBUG
  A4GL_debug ("Determining attribute - field_buffer=%s", field_buffer (field, 0));
#endif
  attr = A4GL_determine_attribute (cmd_type, attr, f, field_buffer (field, 0));

  if (attr != 0 || 1)
    {
#ifdef DEBUG
      A4GL_debug ("calling set_field_attr_with_attr : %x", attr);
#endif
      A4GL_set_field_attr_with_attr (field, attr, cmd_type);
    }


#ifdef DEBUG
  A4GL_debug ("set field attr");
#endif
  fff = UILIB_A4GL_get_curr_form (1);
#ifdef DEBUG
  A4GL_debug ("set field");
  A4GL_debug ("set field buffer setting do_reverse=%d", a);
#endif

  f->do_reverse = a;
#ifdef DEBUG
  A4GL_debug ("done ");
#endif
  local_set_field_opts (field, oopt);
#ifdef DEBUG
  A4GL_debug ("ZZZZ - SET OPTS");
  A4GL_debug ("Calling display_field_contents");
#endif




}

static void
A4GL_replace_tab_with_spaces_on_stack (void)
{
  char *s;
  char buff[20480];
  int b = 0;
  int a;
  int d1;
  int s1;
  void *ptr1;

  A4GL_get_top_of_stack (1, &d1, &s1, (void **) &ptr1);
  if (ptr1 == NULL)
    return;

  if ((d1 & DTYPE_MASK) == DTYPE_CHAR || (d1 & DTYPE_MASK) == DTYPE_VCHAR)
    {
      if (strchr (ptr1, '\t') == NULL)
	{
	  return;
	}
      s = A4GL_char_pop ();

      for (a = 0; a < strlen (s); a++)
	{
	  if (s[a] == '\t')
	    {
	      buff[b++] = ' ';
	      buff[b++] = ' ';
	      buff[b++] = ' ';
	    }
	  else
	    {
	      buff[b++] = s[a];
	    }
	}
      A4GL_assertion (b > sizeof (buff), "Buffer too small in replace_tab_with_spaces_on_stack");
      buff[b] = 0;
      A4GL_push_char (buff);
      acl_free (s);
    }
}

/**
 *
 * @todo Describe function
 */
void
A4GL_display_field_contents (FIELD * field, int d1_ptr, int s1, char *ptr1, int dtype_field)
{
  int field_width;
  int has_format;
  int has_wordwrap;
  int ignore_formatting = 0;
  struct struct_scr_field *f;
  char *ff;

  field_width = A4GL_get_field_width_w (field, 1);

#ifdef DEBUG
  A4GL_debug ("In display_field_contents field width=%d", field_width);
#endif

  f = (struct struct_scr_field *) (field_userptr (field));
  ff = acl_malloc2 (field_width + 1);

  has_format = A4GL_has_str_attribute (f, FA_S_FORMAT);
  has_wordwrap = A4GL_has_bool_attribute (f, FA_B_WORDWRAP);
#ifdef DEBUG
  A4GL_debug ("Has format : %d  ", has_format);
#endif

// 'Format' is valid for a lot of datatypes -
// but not all...
// If we are passing **IN** a character string
// for example - we'll omit the formatting...

  //if ((d1_ptr & DTYPE_MASK)==DTYPE_TEXT || (d1_ptr & DTYPE_MASK)==DTYPE_BYTE || (dtype_field&DTYPE_MASK)==DTYPE_BYTE || (dtype_field&DTYPE_MASK)==DTYPE_TEXT) {
  if ((d1_ptr & DTYPE_MASK) == DTYPE_BYTE || (dtype_field & DTYPE_MASK) == DTYPE_BYTE)
    {
      // Can't display a blob :-)
      return;
    }

  switch (dtype_field & DTYPE_MASK)
    {
    case DTYPE_CHAR:
    case DTYPE_BYTE:
      //case DTYPE_TEXT:
    case DTYPE_VCHAR:
      ignore_formatting = 1;
    }

  if (has_format && ignore_formatting)
    {
#ifdef DEBUG
      A4GL_debug ("Which I'm going to ignore - %x %x", d1_ptr, dtype_field);
#endif
    }

  if (has_format && !ignore_formatting)
    {
#ifdef DEBUG
      A4GL_debug ("Has specified format..");
#endif
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
#ifdef DEBUG
      A4GL_debug ("Has no format.. dtype_field=%d", dtype_field & DTYPE_MASK);
#endif

      if (A4GL_has_datatype_function_i (dtype_field & DTYPE_MASK, "DISPLAY"))
	{
	  char *ptr;
	  char *(*function) (void *, int, int, struct struct_scr_field *, int);
#ifdef DEBUG
	  A4GL_debug ("check for specific display routine");
#endif
	  function = A4GL_get_datatype_function_i (dtype_field & DTYPE_MASK, "DISPLAY");
	  if (function)
	    {
#ifdef DEBUG
	      A4GL_debug ("Has a function - calling XXXX - size=%d decode_size=%d", s1, DECODE_SIZE (dtype_field));
	      A4GL_debug ("field_width=%d", field_width);
#endif

	      if (d1_ptr == DTYPE_CHAR)
		{
#ifdef DEBUG
		  A4GL_debug ("ptr1=%s\n", ptr1);
#endif
		}

	      if ((dtype_field & DTYPE_MASK) != (d1_ptr & DTYPE_MASK))
		{
		  // We can't pass in this pointer - because its not valid for the required datatype
		  // lets try converting it to that datatype and hope for the best...
		  if (d1_ptr == DTYPE_CHAR)
		    {
		      static char buff[2000];
		      A4GL_push_char (ptr1);
		      A4GL_pop_param (&buff, dtype_field & DTYPE_MASK, DECODE_SIZE (dtype_field));
		      ptr1 = buff;
		    }
		  else
		    {
		      ptr1 = NULL;
		    }
		}

	      ptr = function (ptr1, DECODE_SIZE (dtype_field), field_width, f, DISPLAY_TYPE_DISPLAY_TO);
#ifdef DEBUG
	      A4GL_debug ("Returns %p\n", ptr);
#endif
	    }
	  else
	    {
	      ptr = 0;
	    }

	  if (ptr != 0)
	    {
#ifdef DEBUG
	      A4GL_debug ("Here.. %s", ptr);
#endif
	      A4GL_drop_param ();
#ifdef DEBUG
	      A4GL_debug ("Dropped - pushing mine..");
#endif
	      A4GL_push_char (ptr);
	    }
	}

    }

  if (f->dynamic == 0)
    {
      A4GL_replace_tab_with_spaces_on_stack ();
      A4GL_pop_char (ff, field_width);
    }
  else
    {
#ifdef DEBUG
      A4GL_debug ("Its a dynamic field.... %d", f->dynamic);
#endif
      acl_free (ff);
      ff = A4GL_char_pop ();
#ifdef DEBUG
      A4GL_debug ("Got : %s instead..\n", ff);
#endif
    }
#ifdef DEBUG
  A4GL_debug ("set_field_contents : '%s'", ff);
#endif


  if (has_wordwrap)
    {
      if (!(field_opts (field) & O_WRAP))
	{
#ifdef DEBUG
	  A4GL_debug ("FIELD WRAPPING OFF");
#endif
	}
      else
	{
	  char *tmp;
	  tmp = acl_malloc2 (field_width + 1);

#ifdef DEBUG
	  A4GL_debug ("FIELD WRAPPING ON width=%d", A4GL_get_field_width_w (field, 0));
#endif
	  if (A4GL_wordwrap_text (ff, tmp, A4GL_get_field_width_w (field, 0), field_width))
	    {
	      free (ff);
	      ff = tmp;
	    }
	  else
	    {
	      free (tmp);
	    }
	}
    }



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

#ifdef DEBUG
  A4GL_debug ("In disp_fields");
#endif
  formdets = UILIB_A4GL_get_curr_form (1);
  flg = 0;

  va_start (ap, attr);
#ifdef DEBUG
  A4GL_debug (" field_list = %p", &field_list);
  {
    A4GL_debug ("Genfldlist 6");
  }
  A4GL_debug ("set_arr_fields");
#endif
  ptr = &ap;
  nofields = A4GL_gen_field_list (&field_list, formdets, n, &ap, 0);
#ifdef DEBUG
  A4GL_debug ("Number of fields=%d", nofields);
#endif
  for (a = nofields; a >= 0; a--)
    {
#ifdef DEBUG
      A4GL_debug ("field_list[%d]=%p", field_list[a]);
#endif
      fff = UILIB_A4GL_get_curr_form (1);
      set_current_field (fff->form, field_list[a]);
#ifdef DEBUG
      A4GL_debug ("set_init_pop complete");
#endif
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
#ifdef DEBUG
      A4GL_debug ("ZZ9PA - CHECK CHECK - returning 0");
#endif
      return 0;
    }

#ifdef DEBUG
  A4GL_debug ("ZZ9PA - CHECK CHECK - continuing");
#endif

#ifdef DEBUG
  A4GL_debug ("currentfield=%p current_field(mform)=%p", form->currentfield, current_field (mform));
#endif

  if (form->currentfield != current_field (mform))
    {
      /* fprop = 0; */
      if (form->currentfield != 0 && (field_userptr (form->currentfield) != 0))
	{
	  fprop = (struct struct_scr_field *) (field_userptr (form->currentfield));
	  if (fprop != 0)
	    {
	      if ((fprop->datatype != (DTYPE_CHAR & DTYPE_MASK)) && (field_status (form->currentfield)))
		{
		  strcpy (buff, field_buffer (form->currentfield, 0));
		  strcpy (buff2, buff);
#ifdef DEBUG
		  A4GL_debug ("CHeckit here");
#endif
		  getsyx (y, x);
		}
	    }
	}
    }

  if (form->currentfield != current_field (mform))
    {
      fprop = (struct struct_scr_field *) (field_userptr (current_field (mform)));
#ifdef DEBUG
      A4GL_debug ("Moving to %s", fprop->colname);
#endif
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

      fprop = (struct struct_scr_field *) (field_userptr (form->currentfield));
      if (fprop != 0)
	{
	  if (fprop->colname != 0)
	    {
#ifdef DEBUG
	      A4GL_debug ("Moving from %s", fprop->colname);
#endif
	    }
	  else
	    {
#ifdef DEBUG
	      A4GL_debug ("Blank colname");
#endif
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
#ifdef DEBUG
  A4GL_debug ("Setting currentfield entry on form...");
#endif
  form->currentfield = current_field (mform);


  fprop = (struct struct_scr_field *) (field_userptr (form->currentfield));
  if (fprop != 0)
    A4GL_comments (fprop);

  A4GL_mja_pos_form_cursor (mform);
  A4GL_debug_print_stack ();
#ifdef DEBUG
  A4GL_debug ("form_field_constr returning %d", flg);
#endif
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
#ifdef DEBUG
  A4GL_debug ("Ch=%d", ch);
#endif
  if (ch == 0)
    {
      return;
    }
  buff[0] = ch & 0xff;
  buff[1] = 0;
#ifdef DEBUG
  A4GL_debug ("Adding char %d %c", ch, ch);
#endif
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

  b = A4GL_get_field_width_w (field, 1);
  if (strlen (buff) >= sizeof (buff2))
    {
      A4GL_assertion (1, "Buffer too small");
    }
  strcpy (buff2, buff);
  a = strlen (buff2);
  b = A4GL_get_field_width_w (field, 1);
#ifdef DEBUG
  A4GL_debug ("mja_set_field_buffer buff='%s' buff2='%s' (%d,%d) ", buff, buff2, a, b);
#endif



  if (a < A4GL_get_field_width_w (field, 1) && (!(field_opts (field) & O_WRAP)))
    {
#ifdef DEBUG
      A4GL_debug ("Adding padding");
#endif
      A4GL_pad_string (buff2, A4GL_get_field_width_w (field, 1));
    }
  else
    {
#ifdef DEBUG
      A4GL_debug ("No padding required '%s'", buff);
#endif
    }

  if (A4GL_isyes (acl_getenv ("TRIMFIELD")))
    {
      buff2[b] = 0;
#ifdef DEBUG
      A4GL_debug ("Trimmed");
#endif
    }

  if (field_opts (field) & O_WRAP)
    {
#ifdef DEBUG
      A4GL_debug ("Extra trim for the wordwrap");
#endif
      A4GL_trim (buff2);
    }



#ifdef DEBUG
  A4GL_debug ("setting field buffer to %s .. %d ", buff2, A4GL_get_field_width_w (field, 1));
#endif


  if (local_field_opts (field) & O_STATIC)
    {
      // Trim to size...
      buff2[b] = 0;
    }



  xerrno = set_field_buffer (field, nbuff, buff2);

  if (xerrno != E_OK)
    {
#ifdef DEBUG
      A4GL_debug ("ERROR SETTING FIELD BUFFER %d\n", xerrno);
#endif
    }
#ifdef DEBUG
  A4GL_debug ("Setting %p %d to %s (%d)", field, nbuff, buff2, xerrno);
  A4GL_debug ("field buffer set to '%s'", field_buffer (field, 0));
  A4GL_debug ("Currwin=%p", currwin);
#endif
  A4GL_mja_pos_form_cursor (field->form);
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
#ifdef DEBUG
  A4GL_debug ("UILIB_A4GL_push_constr----------------------------------------------------");
#endif
  if (s->processed_onkey == A4GLKEY_INTERRUPT)
    {
      A4GL_push_char (s->vars[0].ptr);
      return 0;
    }

  if (s->nfields < 0)
    {
#ifdef DEBUG
      A4GL_debug ("NO CONSTRUCT - No fields\n");
#endif
      A4GL_push_empty_char ();
      return 0;
    }
  if (s->currform == 0)
    {
#ifdef DEBUG
      A4GL_debug ("NO CONSTRUCT - No form\n");
#endif
      A4GL_push_empty_char ();
      return 0;
    }
  A4GL_int_form_driver (s->currform->form, REQ_FIRST_PAGE);

#ifdef DEBUG
  A4GL_debug ("Push_constr");
#endif
#ifdef DEBUG
  A4GL_debug ("nfields=%d", s->nfields);
#endif
  if (s->field_list == 0)
    {
      A4GL_exitwith ("Internal error - no field list");
      A4GL_push_empty_char ();
      return 0;
    }
#ifdef DEBUG
  A4GL_debug ("s-field_list[0]=%p", s->field_list[0]);
#endif

  for (a = 0; a <= s->nfields; a++)
    {
#ifdef DEBUG
      A4GL_debug ("Looping a=%d\n", a);
#endif
      f = s->field_list[a];
#ifdef DEBUG
      A4GL_debug ("f=%p", f);
#endif
      fprop = (struct struct_scr_field *) (field_userptr (f));
#ifdef DEBUG
      A4GL_debug ("fprop=%p", fprop);
#endif
      if (fprop != 0)
	{
	  //char buff[32000];
#ifdef DEBUG
	  A4GL_debug ("getting ptr", fprop);
	  A4GL_debug ("fprop->colname=%s fprop->datatype=%x", fprop->colname, (fprop->datatype) & 0xffff);
	  A4GL_debug ("field_buffer (%p) =%s", f, field_buffer (f, 0));
#endif

	  if (s->constr[a].value)
	    {
	      ptr =
		(char *) A4GL_construct (s->constr[a].tabname, s->constr[a].colname, s->constr[a].value,
					 get_inc_quotes (fprop->datatype), fprop->datatype, fprop->dtype_size,
					 s->callback_function);
	    }
	  else
	    {
	      ptr =
		(char *) A4GL_construct (s->constr[a].tabname, s->constr[a].colname, field_buffer (f, 0),
					 get_inc_quotes (fprop->datatype), fprop->datatype, fprop->dtype_size,
					 s->callback_function);
	    }

	  if (ptr == 0)
	    {			// some error in the field...
	      A4GL_push_empty_char ();
	      return 0;
	    }

#ifdef DEBUG
	  A4GL_debug ("ptr=%s\n", ptr);
#endif
	  if (strlen (ptr) > 0)
	    {
#ifdef DEBUG
	      A4GL_debug ("ptr=%s\n", ptr);
#endif
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

  //if (s->fcntrl) { free(s->fcntrl); s->fcntrl=0; }
  if (s->field_list)
    free (s->field_list);
  return 1;
}





/**
 *
 * @todo Describe function
 */
void
UILIB_A4GL_set_infield_from_stack (void)
{
#ifdef DEBUG
  A4GL_debug ("**** CHANGED FIELD ****");
#endif
  inp_current_field = (void *) A4GL_pop_long ();
#ifdef DEBUG
  A4GL_debug ("New field :---> %p", inp_current_field);
#endif
}

void
A4GL_set_infield_from_parameter (long a)
{
#ifdef DEBUG
  A4GL_debug ("**** CHANGED FIELD ****");
#endif
  inp_current_field = (void *) a;
#ifdef DEBUG
  A4GL_debug ("New field :---> %p", inp_current_field);
#endif
}

/**
 * @return The current field number.
 */
long
A4GL_get_curr_infield (void)
{
  return (long) inp_current_field;
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
#ifdef DEBUG
	  A4GL_debug ("infield - matches");
#endif
	  return 1;
	}
    }
#ifdef DEBUG
  A4GL_debug ("Infield - doesn't match");
#endif
  return 0;




  s = inp;

  c = UILIB_A4GL_gen_field_chars_ap (&field_list, s->currform, ap, 0);
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
#ifdef DEBUG
	  A4GL_debug ("Infield_ia - matches...");
#endif
	  return 1;
	}
    }
#ifdef DEBUG
  A4GL_debug ("Infield_ia - doesn't match");
#endif
  return 0;



  c = UILIB_A4GL_gen_field_chars_ap (&field_list, s->currform, ap, s->scr_line);
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
UILIB_A4GL_fgl_getfldbuf_ap (void *inp, ts_field_name * orig_field_list, va_list * ap)
{

  FIELD **field_list;
  struct s_screenio *s;
  int c;
  int a;
  int nr;


  s = inp;


  //c = UILIB_A4GL_gen_field_chars_ap (&field_list, s->currform, ap,0);

  c = A4GL_gen_field_chars_ap_with_orig_fldlist (&field_list, s->currform, orig_field_list, ap, 0);

  nr = 0;
  for (a = 0; a <= c; a++)
    {
      char *buff = 0;
      char *orig = 0;
      int freeme = 0;

      orig = field_buffer (field_list[a], 0);
#ifdef DEBUG
      A4GL_debug ("Orig=%s\n", orig);
#endif
      if (strlen (orig) == 0)
	{
	  freeme++;
	  buff = malloc (2);
	  buff[0] = 0;
	  buff[1] = 0;
	  //buff=strdup("");
	}
      else
	{
	  freeme++;
	  buff = strdup (orig);
	}
#ifdef DEBUG
      A4GL_debug ("Got buff as : '%s'", buff);
#endif

      chk_for_picture (field_list[a], buff);

#ifdef DEBUG
      A4GL_debug ("getfldbuf='%s'\n", buff);
#endif
      A4GL_push_char (buff);
      if (freeme)
	{
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
UILIB_A4GL_fgl_getfldbuf_ia_ap (void *inp, ts_field_name * orig_field_list, va_list * ap)
{

  FIELD **field_list;
  struct s_inp_arr *s;
  int c;
  int a;
  int nr;
  int b;
  int x;

  s = inp;




  c = UILIB_A4GL_gen_field_chars_ap (&field_list, s->currform, ap, s->scr_line);
  nr = 0;
  for (a = 0; a <= c; a++)
    {
      FIELD *f;
      int nv;
      f = field_list[a];	// f will always be in the first rows of screen fields..
      nv = s->nbind;

      if (s->start_slice != -1)
	{
	  nv = s->end_slice - s->start_slice + 1;
	}

      for (b = 0; b < nv; b++)
	{
	  for (x = 0; x < s->srec->dim; x++)
	    {

	      if (f == s->field_list[x][b])
		{
		  char *buff;
		  // Found @ position b...
		  //A4GL_push_char (field_buffer (f, 0));
		  buff = strdup (field_buffer (f, 0));
		  chk_for_picture (field_list[a], buff);
		  A4GL_push_char (buff);
		  acl_free (buff);
		  nr++;
		}
	    }
	}
    }
  return nr;
}


void
UILIB_A4GL_reset_delims (void *vformdets, void *field, char *delims)
{
  struct s_form_dets *formdets;
  int a;
  char sbuff0[2];
  char sbuff1[2];
  formdets = vformdets;
  sbuff0[0] = delims[0];
  sbuff0[1] = 0;
  sbuff1[0] = delims[1];
  sbuff1[1] = 0;

  for (a = 0; a < formdets->fileform->metrics.metrics_len; a++)
    {
      if (field && (void *) formdets->fileform->metrics.metrics_val[a].field != field)
	continue;

      A4GL_mja_set_field_buffer ((FIELD *) formdets->fileform->metrics.metrics_val[a].dlm1, 0, sbuff0);
      A4GL_mja_set_field_buffer ((FIELD *) formdets->fileform->metrics.metrics_val[a].dlm2, 0, sbuff1);
    }
}


/**
 *
 * @todo Describe function
 */
char *
get_print_field_opts_as_string (FIELD * a)
{
  long z;
  static char str[8048] = "";
  strcpy (str, "");
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

  if (field_just (a) == JUSTIFY_RIGHT)
    {
      strcat (str, " RIGHT");
    }

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

  if (field_just (a) == JUSTIFY_RIGHT)
    {
      strcat (str, " RIGHT");
    }
#ifdef DEBUG
  A4GL_debug ("UUU Field %p attribs= %s: (%s)", a, str, field_buffer (a, 0));
#endif
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
#ifdef DEBUG
	  A4GL_debug ("FIELD LIST : %p %d", s->field_list[a], s->currform->fileform->metrics.metrics_val[metric_no].scr);
#endif
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
#ifdef DEBUG
	  A4GL_debug ("FIELD LIST : %p %d", s->field_list[a], s->currform->fileform->metrics.metrics_val[metric_no].scr);
#endif
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
#ifdef DEBUG
  A4GL_debug ("In A4GL_page_for_nfield %p");
#endif
  f = current_field (s->currform->form);
#ifdef DEBUG
  A4GL_debug ("Current field %p", f);
#endif

  for (a = 0; s->field_list[a]; a++)
    {
      if (f == s->field_list[a])
	{
	  a++;
	  if (s->field_list[a] == 0)
	    a = 0;
	  metric_no = A4GL_get_metric_no (s->currform, s->field_list[a]);
#ifdef DEBUG
	  A4GL_debug ("Metric_no=%d", metric_no);
#endif
#ifdef DEBUG
	  A4GL_debug ("FIELD LIST : %p %d", s->field_list[a], s->currform->fileform->metrics.metrics_val[metric_no].scr);
#endif
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
#ifdef DEBUG
  A4GL_debug ("page for previous FIELD f=%p", f);
#endif
  for (a = 0; s->field_list[a]; a++)
    {
      if (f == s->field_list[a])
	{
	  b = a - 1;
	  if (a <= 0)
	    {
#ifdef DEBUG
	      A4GL_debug ("field is at end of list");
#endif
	      for (b = 0; s->field_list[b + 1]; b++);
#ifdef DEBUG
	      A4GL_debug ("setting a to %d", a);
#endif
	    }
#ifdef DEBUG
	  A4GL_debug ("b=%d", b);
#endif
	  metric_no = A4GL_get_metric_no (s->currform, s->field_list[b]);
#ifdef DEBUG
	  A4GL_debug ("FIELD LIST : %d %p %d", a, s->field_list[b], s->currform->fileform->metrics.metrics_val[metric_no].scr);
#endif
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
A4GL_copy_field_data (struct s_form_dets *form, int var_dtype)
{
  char buff[8000] = "";
  char buff2[8000] = "";
  FORM *mform;
  int ppr;
  int x = 0, y = 0;
  struct struct_scr_field *fprop;
  mform = form->form;
#ifdef DEBUG
  A4GL_debug ("form->currentfield=%p", form->currentfield);
#endif
  if (form->currentfield != 0)
    if (field_userptr (form->currentfield) != 0)
      {
#ifdef DEBUG
	A4GL_debug ("Is a proper field");
#endif
	fprop = (struct struct_scr_field *) (field_userptr (form->currentfield));
#ifdef DEBUG
	A4GL_debug ("fprop=%p", fprop);
#endif
	if (fprop != 0)
	  {
#ifdef DEBUG
	    A4GL_debug ("check Datatype ");
#endif
	    if (((fprop->datatype != DTYPE_CHAR) & (DTYPE_MASK)) && (field_status (form->currentfield)))
	      {
#ifdef DEBUG
		A4GL_debug ("modify size dtype");
		A4GL_debug ("modfy size for metric %d", A4GL_get_metric_for (form, form->currentfield));
#endif
		A4GL_modify_size (&buff[4], form->fileform->metrics.metrics_val[A4GL_get_metric_for (form, form->currentfield)].w);
#ifdef DEBUG
		A4GL_debug ("modfy size done -> '%s'", &buff[4]);
#endif

		strcpy (&buff[4], field_buffer (form->currentfield, 0));
#ifdef DEBUG
		A4GL_debug ("copy 1");
#endif
		strcpy (buff2, &buff[4]);
#ifdef DEBUG
		A4GL_debug ("copy 2");
		A4GL_debug ("trim buff");
#endif
		A4GL_trim (buff2);
		getsyx (y, x);

#ifdef DEBUG
		A4GL_debug ("CHange y=%d, x=%d", y, x);
		A4GL_debug ("stack manip buff2='%s'", buff2);
#endif
		if (strlen (buff2) > 0)
		  {
#ifdef DEBUG
		    A4GL_debug ("Pushing param %p", buff2);
#endif




		    ppr = A4GL_check_and_copy_field_to_data_area (form, fprop, buff2, buff, var_dtype);


		    if (ppr)
		      {
#ifdef DEBUG
			A4GL_debug ("Pushing param %p %d", buff, fprop->datatype);
#endif
			if (fprop->datatype == DTYPE_CHAR || fprop->datatype == DTYPE_VCHAR)
			  {
			    A4GL_push_param (buff, (fprop->datatype & DTYPE_MASK) + (strlen (buff) << 16));
			  }
			else
			  {
			    A4GL_push_param (buff, (fprop->datatype & DTYPE_MASK) + (fprop->dtype_size << 16));
			  }
			if (A4GL_has_str_attribute (fprop, FA_S_FORMAT))
			  {
			    A4GL_push_char (A4GL_get_str_attribute (fprop, FA_S_FORMAT));
			    A4GL_pushop (OP_USING);
			  }
			A4GL_pop_param (buff, DTYPE_CHAR, A4GL_get_field_width (form->currentfield));


			if (A4GL_is_numeric_datatype (fprop->datatype))
			  {
			    /* This doesn't seem to make any sense - surely the USING will put in the correct ',' or '.'
			       depending on the decfmt ...
			     */
			    /*

			       A4GL_decstr_convert(buff,
			       A4GL_get_convfmts()->posix_decfmt,
			       A4GL_get_convfmts()->ui_decfmt,
			       0, 1, sizeof(buff));
			     */

			  }


			A4GL_mja_set_field_buffer (form->currentfield, 0, buff);
		      }
		    else
		      {
			A4GL_error_nobox (acl_getenv ("FIELD_ERROR_MSG"), 0);
			if (fprop != 0)
			  A4GL_comments (fprop);

			if (A4GL_isyes (acl_getenv ("A4GL_CLR_FIELD_ON_ERROR")))
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
void
A4GL_int_form_driver (FORM * form, int a)
{
  int field_pos;
  FIELD *f;
  char buff[10024];
  char buff2[10024];
  int fd_ok;

#ifdef DEBUG
  A4GL_debug ("int_form_driver called with %p - %d", form, a);
#endif

  if (a <= 27)
    {
#ifdef DEBUG
      A4GL_debug ("Control Character or ESC");
#endif
      return;
    }

  field_pos = A4GL_get_curr_field_col (form);
  f = current_field (form);

  if (f)
    {
      strcpy (buff, field_buffer (f, 0));
#ifdef DEBUG
      A4GL_debug ("Field buffer was %s\n", buff);
#endif
    }
  else
    {
      strcpy (buff, "");
    }


#ifdef DEBUG
  A4GL_debug ("MJA Calling form_driver with %d (%x)  for form %p - buff=%s", a, a, form, buff);
#endif
  if (a > KEY_MAX)
    {
#ifdef DEBUG
      A4GL_debug ("FORM CONTROL   - %d\n", a - KEY_MAX);
#endif
    }
  if (a_isprint (a) && a >= ' ' && a < 127)
    {
#ifdef DEBUG
      A4GL_debug ("Key : %c", a);
#endif
    }

  fd_ok = form_driver (form, a);

  if (fd_ok != E_OK)
    {
#ifdef DEBUG
      A4GL_debug ("Problem in calling form_driver %p c=%d %x - rets %d", form, a, a, fd_ok);
#endif
      switch (fd_ok)
	{
	case E_SYSTEM_ERROR:
	case E_BAD_STATE:
	case E_BAD_ARGUMENT:
	case E_NOT_POSTED:
	  /* case E_UNKNOWN_COMMAND: *//* allow this for mbs utf8 */
	case E_INVALID_FIELD:
	  A4GL_exitwith ("Form driver complaint");
	  return;
	}
    }

  if (f)
    {
      strcpy (buff2, field_buffer (f, 0));
#ifdef DEBUG
      A4GL_debug ("field buffer returns %s\n", buff2);
#endif
    }
  else
    {
      strcpy (buff2, "");
    }

  if (f != current_field (form))
    {
#ifdef DEBUG
      A4GL_debug ("Resetting focus");
#endif
      f = current_field (form);
    }

  if (field_pos != A4GL_get_curr_field_col (form))
    {
#ifdef DEBUG
      A4GL_debug ("Resetting position (%d %d)", field_pos, A4GL_get_curr_field_col (form));
#endif
      field_pos = A4GL_get_curr_field_col (form);
    }

#ifdef DEBUG
  A4GL_debug ("Buff2 now = %s", buff2);
#endif

  if (a != REQ_VALIDATION)
    {
#ifdef DEBUG
      A4GL_debug ("REQ_VALIDATION");
#endif
      A4GL_int_form_driver (form, REQ_VALIDATION);
#ifdef DEBUG
      A4GL_debug ("DONE REQ_VALIDATION");
#endif
    }

  if (f)
    {
      strcpy (buff2, field_buffer (f, 0));
#ifdef DEBUG
      A4GL_debug ("field buffer now returns %s\n", buff2);
#endif
    }
  else
    {
      strcpy (buff2, "");
    }
#ifdef DEBUG
  A4GL_debug ("Validation has set Buff2 now = %s", buff2);
#endif



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

  A4GL_set_status (0, 0);

  formdets = UILIB_A4GL_get_curr_form (1);
  if (formdets == 0)
    return;			/* No form to clear ? */


  /* Go through each field */
  for (a = 0; a < formdets->fileform->attributes.attributes_len; a++)
    {
      fno = formdets->fileform->attributes.attributes_val[a].field_no;

      /* And through each metric for this field */
      for (rn = 0; rn < formdets->fileform->fields.fields_val[fno].metric.metric_len; rn++)
	{
	  metric_no = formdets->fileform->fields.fields_val[fno].metric.metric_val[rn];
	  k = &formdets->fileform->metrics.metrics_val[metric_no];
	  f = (FIELD *) k->field;

#ifdef DEBUG
	  A4GL_debug ("Calling set_field_attr_with_attr for clearing..");
#endif

	  A4GL_set_field_attr_with_attr ((FIELD *) formdets->fileform->metrics.metrics_val[metric_no].field, 0, FGL_CMD_CLEAR);

	  if (!to_default)
	    {
#ifdef DEBUG
	      A4GL_debug ("Blanking field %p MJAMJAMJA", f);
#endif
	      A4GL_mja_set_field_buffer (f, 0, "");
	    }
	  else
	    {
	      struct struct_scr_field *prop;
	      prop = (struct struct_scr_field *) field_userptr (f);
	      A4GL_mja_set_field_buffer (f, 0,
					 (char *) A4GL_replace_sql_var
					 ((char *) A4GL_strip_quotes (A4GL_get_str_attribute (prop, FA_S_DEFAULT))));
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
#ifdef DEBUG
      A4GL_debug ("MMM a=%d Current field=%p field_list=%p", a, f, s->field_list[a]);
#endif
      if (f == s->field_list[a])
	fno = a;

      fprop = (struct struct_scr_field *) (field_userptr (s->field_list[a]));

      if (!A4GL_field_is_noentry ((s->mode == MODE_CONSTRUCT), fprop)
	  || (fprop->datatype == DTYPE_SERIAL && s->mode != MODE_CONSTRUCT))
	{
#ifdef DEBUG
	  A4GL_debug ("Field is not noentry");
#endif
	  last_usable = a;
	}
      else
	{
#ifdef DEBUG
	  A4GL_debug ("MMM Field is noentry");
#endif
	}
    }

#ifdef DEBUG
  A4GL_debug ("MMM curr_metric_is_used_last_s_screenio fno=%d nfields=%d", fno, s->nfields);
#endif

  if (fno == last_usable)
    {
#ifdef DEBUG
      A4GL_debug ("MMM Is last");
#endif
      return 1;
    }

#ifdef DEBUG
  A4GL_debug ("MMM Not last");
#endif
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
#ifdef DEBUG
  A4GL_debug ("fgl_fieldtouched - input array");
#endif




  field_status_strip_tabname = 1;
  c = UILIB_A4GL_gen_field_chars_ap (&field_list, s->currform, ap, 0);	/* s->scr_line ???? */
  field_status_strip_tabname = 0;
  if (c >= 0)
    {
      /*
         for (a = 0; a <= c; a++)
         {
         found = 0;
#ifdef DEBUG
         A4GL_debug ("fieldtouched FIELD : %p a=%d c=%d - status=%d\n",
#endif
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


#ifdef DEBUG
      A4GL_debug ("fieldtouched_input - checking field_status");
#endif

      for (a = 0; a <= c; a++)
	{
	  FIELD *f;
	  int nv;
	  f = field_list[a];
	  nv = s->nbind;
	  if (s->start_slice != -1)
	    {
	      nv = s->end_slice - s->start_slice + 1;
	    }
	  for (b = 0; b < nv; b++)
	    {
	      if (f == s->field_list[0][b])
		{
		  // Found @ position b....
		  fprop = (struct struct_scr_field *) (field_userptr (s->field_list[s->scr_line - 1][b]));

		  if (A4GL_fprop_flag_get (s->field_list[s->scr_line - 1][b], FLAG_FIELD_TOUCHED))
		    {
#ifdef DEBUG
		      A4GL_debug
			("fieldtouched Field status is set for %p - %d line %d - b=%d",
			 field_list[a], fprop->flags, s->scr_line - 1, b);
#endif
		      acl_free (field_list);
		      return 1;
		    }
		}
	    }
	}
#ifdef DEBUG
      A4GL_debug ("fieldtouched Field status not set for any..");
#endif
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
#ifdef DEBUG
  A4GL_debug ("fgl_fieldtouched - input ");
#endif
  A4GL_set_status (0, 0);


  field_status_strip_tabname = 1;
  c = UILIB_A4GL_gen_field_chars_ap (&field_list, s->currform, ap, 0);
  field_status_strip_tabname = 0;


  if (c >= 0)
    {
      for (a = 0; a <= c; a++)
	{
	  found = 0;
#ifdef DEBUG
	  A4GL_debug ("fieldtouched FIELD : %p a=%d c=%d - status=%d\n", field_list[a], a, c, field_status (field_list[a]));
#endif

	  // Have a look to see if we are currently inputing this one...
	  for (b = 0; b <= s->nfields; b++)
	    {
	      void *ptr1;
	      void *ptr2;


	      ptr1 = field_list[a];

	      if (b > c)
		{
#ifdef DEBUG
		  A4GL_debug ("Odd - more fields being input than we have fields ?");
#endif
		  continue;
		}
#ifdef DEBUG
	      A4GL_debug ("a=%d b=%d", a, b);
#endif
	      ptr2 = field_list[b];

#ifdef DEBUG
	      A4GL_debug ("Ptr1=%p", ptr1);
#endif
#ifdef DEBUG
	      A4GL_debug ("Ptr2=%p", ptr2);
#endif

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
#ifdef DEBUG
      A4GL_debug ("fieldtouched_input - checking field_status");
#endif

      for (a = 0; a <= c; a++)
	{

	  A4GL_int_form_driver (s->currform->form, REQ_VALIDATION);
	  fprop = (struct struct_scr_field *) (field_userptr (field_list[a]));

	  if (A4GL_fprop_flag_get (field_list[a], FLAG_FIELD_TOUCHED))
	    {
#ifdef DEBUG
	      A4GL_debug ("fieldtouched Field status is set for %p", field_list[a]);
#endif
	      acl_free (field_list);
	      return 1;
	    }
	}
#ifdef DEBUG
      A4GL_debug ("fieldtouched Field status not set for any..");
#endif
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
#ifdef DEBUG
  A4GL_debug ("clr_Fields_ap");
#endif

  c = UILIB_A4GL_gen_field_chars_ap (&field_list, UILIB_A4GL_get_curr_form (1), ap, 0);

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
  int var_dtype = 0;

#ifdef DEBUG
  A4GL_debug ("form_field_chk_iarr....");
#endif
  mform = sio->currform->form;
#ifdef DEBUG
  A4GL_debug ("CHeck fields 1 m=%d", m);
#endif
  form = sio->currform;
#ifdef DEBUG
  A4GL_debug ("CHeck fields 2 currentfield=%p status = %d", form->currentfield, field_status (form->currentfield));
#endif

  fprop = 0;
  if (m > 0)
    {
#ifdef DEBUG
      A4GL_debug ("CHeck fields 3");
#endif
      form->currentfield = 0;
      form->currentmetrics = 0;
#ifdef DEBUG
      A4GL_debug (" m ");
#endif
      return 0;
    }


#ifdef DEBUG
  A4GL_debug (" current field %p  form says currfield=%p m=%d", form->currentfield, current_field (mform), m);
  A4GL_debug
    ("field_status(form->currentfield)=%d field_status(currfield)=%d",
     field_status (form->currentfield), field_status (current_field (mform)));
#endif
  if ((form->currentfield != current_field (mform)) || m < 0)
    {
#ifdef DEBUG
      A4GL_debug ("Is different");
#endif
      fprop = 0;

      if (form->currentfield != 0)
	if (field_userptr (form->currentfield) != 0)
	  {
#ifdef DEBUG
	    A4GL_debug ("Is a proper field");
#endif
	    fprop = (struct struct_scr_field *) (field_userptr (form->currentfield));
#ifdef DEBUG
	    A4GL_debug ("fprop=%p", fprop);
#endif



	    if (fprop != 0)
	      {

#ifdef DEBUG
		A4GL_debug ("15 fprop!=0 flags=%d", fprop->flags);
#endif
		if ((fprop->datatype & DTYPE_MASK) != DTYPE_CHAR)
		  {

		    A4GL_modify_size (&buff[4],
				      form->fileform->metrics.metrics_val[A4GL_get_metric_for (form, form->currentfield)].w);

		    strcpy (&buff[4], field_buffer (form->currentfield, 0));
		    strcpy (buff2, &buff[4]);
		    A4GL_trim (buff2);
		    getsyx (y, x);
		    A4GL_trim (buff2);

#ifdef DEBUG
		    A4GL_debug ("15 Check buff2='%s'", buff2);
#endif

		    if (strlen (buff2) == 0)
		      {
			int chged = 0;
			// Has the field changed ? 
			// Are we on a new line ? 
			if ((A4GL_fprop_flag_get (form->currentfield, FLAG_FIELD_TOUCHED)) || sio->curr_line_is_new)
			  {
			    chged++;
			  }

			// are we returning to a previous field ? 
			if (sio->processed_onkey != A4GLKEY_ACCEPT && sio->processed_onkey != A4GLKEY_UP
			    && sio->processed_onkey != A4GLKEY_LEFT && sio->processed_onkey != A4GLKEY_SHTAB)
			  {
#ifdef DEBUG
			    A4GL_debug ("last key was not up or left");
#endif
			    chged++;
			  }

			if (chged == 0)
			  {
			    if (!A4GL_entire_row_is_blank (sio, sio->scr_line - 1))
			      {
				chged++;
			      }
			  }
#ifdef DEBUG
			A4GL_debug ("changed=%d\n", chged);
#endif

			if (A4GL_has_bool_attribute (fprop, FA_B_REQUIRED) && chged
			    && !A4GL_has_bool_attribute (fprop, FA_B_NOENTRY)
			    && A4GL_input_required_handling () == REQUIRED_TYPE_FIELD)
			  {
			    int allow_it_anyway = 0;

			    // We'll still allow it - so long as there is null in the include list
			    if (A4GL_has_str_attribute (fprop, FA_S_INCLUDE))
			      {
				if (A4GL_check_field_for_include
				    ("", A4GL_get_str_attribute (fprop, FA_S_INCLUDE), fprop->datatype))
				  {
				    allow_it_anyway = 1;
				  }
			      }

			    if (!allow_it_anyway)
			      {
				// Well there wasn't - so it is required....
#ifdef DEBUG
				A4GL_debug ("FIELD_REQD_MSG");
#endif
				A4GL_error_nobox (acl_getenv ("FIELD_REQD_MSG"), 0);
				set_current_field (mform, form->currentfield);
				return -4;
			      }


			  }

			// Could still be thrown out if we have an include without a null in it....
#ifdef DEBUG
			A4GL_debug ("X2222 MAYBE");
#endif
			if (A4GL_has_str_attribute (fprop, FA_S_INCLUDE))
			  {
			    if (A4GL_check_field_for_include ("", A4GL_get_str_attribute (fprop, FA_S_INCLUDE), fprop->datatype))
			      {
				return 1;
			      }
			    else
			      {
#ifdef DEBUG
				A4GL_debug ("X2222 Check for include has null...");
#endif
				A4GL_error_nobox (acl_getenv ("FIELD_INCL_MSG"), 0);
				A4GL_fprop_flag_clear (sio->currform->currentfield, FLAG_MOVED_IN_FIELD);
				A4GL_fprop_flag_set (sio->currform->currentfield, FLAG_MOVING_TO_FIELD);
				A4GL_int_form_driver (mform, REQ_BEG_FIELD);
				return -4;
			      }
			  }


			return 0;
		      }


		    var_dtype = sio->binding[sio->curr_attrib].dtype;
		    pprval = A4GL_check_and_copy_field_to_data_area (form, fprop, buff2, buff, var_dtype);



		    if (!pprval)
		      {
			A4GL_error_nobox (acl_getenv ("FIELD_ERROR_MSG"), 0);
			if (fprop != 0)
			  A4GL_comments (fprop);

			if (A4GL_isyes (acl_getenv ("A4GL_CLR_FIELD_ON_ERROR")))
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


#ifdef DEBUG
		A4GL_debug ("CHECK FOR INCLUDE");
#endif

		strcpy (buff, field_buffer (sio->currform->currentfield, 0));
		if (strlen (buff) == 0)
		  {
		    if (A4GL_has_bool_attribute (fprop, FA_B_REQUIRED) && !A4GL_has_bool_attribute (fprop, FA_B_NOENTRY)
			&& A4GL_input_required_handling () == REQUIRED_TYPE_FIELD)
		      {
			int allow_it_anyway = 0;

			// We'll still allow it - so long as there is null in the include list
			if (A4GL_has_str_attribute (fprop, FA_S_INCLUDE))
			  {
			    if (A4GL_check_field_for_include ("", A4GL_get_str_attribute (fprop, FA_S_INCLUDE), fprop->datatype))
			      {
				allow_it_anyway = 1;
			      }
			  }

			if (!allow_it_anyway)
			  {
			    // Well there wasn't - so it is required....
#ifdef DEBUG
			    A4GL_debug ("FIELD_REQD_MSG");
#endif
			    A4GL_error_nobox (acl_getenv ("FIELD_REQD_MSG"), 0);
			    set_current_field (mform, form->currentfield);
			    return -4;
			  }


		      }



#ifdef DEBUG
		    A4GL_debug ("X2222 MAYBE");
#endif

		    if (A4GL_has_str_attribute (fprop, FA_S_INCLUDE))
		      {
			if (A4GL_check_field_for_include ("", A4GL_get_str_attribute (fprop, FA_S_INCLUDE), fprop->datatype))
			  {
			    return 1;
			  }
			else
			  {
#ifdef DEBUG
			    A4GL_debug ("X2222 Check for include has null...");
#endif
			    A4GL_error_nobox (acl_getenv ("FIELD_INCL_MSG"), 0);
			    A4GL_fprop_flag_clear (sio->currform->currentfield, FLAG_MOVED_IN_FIELD);
			    A4GL_fprop_flag_set (sio->currform->currentfield, FLAG_MOVING_TO_FIELD);
			    A4GL_int_form_driver (mform, REQ_BEG_FIELD);
			    return -4;
			  }
		      }

		  }



		if (A4GL_has_str_attribute (fprop, FA_S_INCLUDE))
		  {
		    if (A4GL_check_field_for_include
			(field_buffer (sio->currform->currentfield, 0),
			 A4GL_get_str_attribute (fprop, FA_S_INCLUDE), fprop->datatype) == 0)
		      {
			A4GL_error_nobox (acl_getenv ("FIELD_INCL_MSG"), 0);
			A4GL_fprop_flag_clear (sio->currform->currentfield, FLAG_MOVED_IN_FIELD);
			A4GL_fprop_flag_set (sio->currform->currentfield, FLAG_MOVING_TO_FIELD);
			A4GL_int_form_driver (mform, REQ_BEG_FIELD);
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

#ifdef DEBUG
  A4GL_debug ("field width=%d", A4GL_get_field_width (f));
#endif

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
#ifdef DEBUG
      A4GL_debug ("HAS PICTURE MJA123");
#endif
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

/// This fuction extracts the portion of 'fmt' in 'str' for the search term 'srch'
/// eg get_data_from_formatted_field("dd","01/01/2002","dd/mm/yyyy")
/// this has a sideeffect in that the format will have any matching terms replaced by spaces.
/// so - after this call - fmt will be "  /01/2002"
/// this is done so you can search for longer terms first - like mmm or ddd and not have them confused a
/// later search for mm or dd...
static char *
get_data_from_formatted_field (char *srch, char *str, char *fmt_orig)
{
  char *ptr;
  int offset;
  static char buff[200];
  static char fmt[200];
  strcpy (fmt, fmt_orig);
  for (offset = 0; offset <= strlen (fmt); offset++)
    {
      fmt[offset] = tolower (fmt[offset]);
    }
#ifdef DEBUG
  A4GL_debug ("get_data_from_formatted_field called with '%s' '%s' '%s'", srch, str, fmt);
#endif
  ptr = strstr (fmt, srch);
  if (ptr == 0)
    {
#ifdef DEBUG
      A4GL_debug ("Searching for %s failed in %s", srch, fmt);
#endif
      return 0;
    }
  offset = ptr - fmt;
#ifdef DEBUG
  A4GL_debug ("Offset=%d\n", offset);
#endif
  strncpy (buff, &str[offset], strlen (srch));
  buff[strlen (srch)] = 0;
#ifdef DEBUG
  A4GL_debug ("Searching for %s in %s got %s", srch, fmt, buff);
#endif
  memset (fmt + offset, ' ', strlen (srch));
  return buff;
}





// CHeck if out date looks like our formatted data
// 
static int
matched_date_format (char *fmt, char *data)
{
  int a;
  for (a = 0; a < strlen (data); a++)
    {
      if (fmt[a] == 0)
	return 0;		// Reached the end unexpectedly


      if (data[a] >= '0' && data[a] <= '9')
	{
	  // Have we got a digit where we'd expect one ? 
	  if (tolower (fmt[a]) == 'd' || tolower (fmt[a]) == 'm' || tolower (fmt[a]) == 'y');
	  else
	    {
	      return 0;
	    }
	}
      else
	{
	  // Have we got a non-digit where we'd expect a digit ? 
	  if (tolower (fmt[a]) == 'd' || tolower (fmt[a]) == 'm' || tolower (fmt[a]) == 'y')
	    return 0;
	}
    }
#ifdef DEBUG
  A4GL_debug ("Got what looks like a valid date for the format");
#endif
  // Excellent
  return 1;
}

char *
A4GL_fld_data_ignore_format (struct struct_scr_field *fprop, char *fld_data)
{
  char *ptr;
  ptr = A4GL_get_str_attribute (fprop, FA_S_FORMAT);
#ifdef DEBUG
  A4GL_debug ("FLD_DATA_IGNORE_FORMAT : %s\n", fld_data);
#endif
//  if (ptr)
//    {
  // It could the that there are some literals or other characters
  // in fld_data that we need to take out first...
  //
#ifdef DEBUG
  A4GL_debug ("Has format");
#endif
  if (fprop->datatype == DTYPE_SMINT || fprop->datatype == DTYPE_INT
      || fprop->datatype == DTYPE_DECIMAL
      || fprop->datatype == DTYPE_MONEY || fprop->datatype == DTYPE_FLOAT || fprop->datatype == DTYPE_SMFLOAT)
    {
      static char buff_new[256];
      int a;
      int c = 0;
      memset (buff_new, 0, 255);

      for (a = 0; a < strlen (fld_data); a++)
	{
	  if (!A4GL_is_meaningful_in_decfmt (A4GL_get_convfmts ()->ui_decfmt, fld_data[a]))
	    continue;

	  /*
	     if (fld_data[a] == A4GL_get_convfmts ()->ui_decfmt.decsep)
	     {
	     buff_new[c++] = A4GL_get_convfmts ()->posix_decfmt.decsep;
	     continue;
	     }
	     if (fld_data[a] == A4GL_get_convfmts ()->ui_decfmt.thsep)
	     {
	     buff_new[c++] = A4GL_get_convfmts ()->posix_decfmt.thsep;
	     continue;
	     }
	   */

	  buff_new[c++] = fld_data[a];
	}
      fld_data = buff_new;
#ifdef DEBUG
      A4GL_debug ("COPY -> %s instead", fld_data);
#endif
    }


  if (fprop->datatype == DTYPE_DATE)
    {
      int adate;
      int done = 0;

      if (ptr)
	{
	  char tmpbuff[200];
	  char format[256];
	  //int mm;
	  int rval;
	  char *mmm_s;
	  static char buff_new[256];
	  int mmm = 0;
	  int dd;
	  //int yyyy;
	  int yy;
	  int date_as_int;
	  char *d;
	  date_as_int = A4GL_get_date_from_formatted_date (ptr, fld_data);
	  if (date_as_int != 0)
	    {
	      static char buff_n[256];
	      A4GL_push_date (date_as_int);
	      d = A4GL_char_pop ();
	      strcpy (buff_n, d);
	      free (d);
	      fld_data = buff_n;
	      return fld_data;
	    }

	  if (!matched_date_format (ptr, fld_data))
	    {
	      if (A4GL_stod (fld_data, &adate, 0) == 1)
		{
		  char *d;
		  static char buff_new[256];
		  A4GL_push_date (adate);
		  d = A4GL_char_pop ();
		  strcpy (buff_new, d);
		  free (d);
		  fld_data = buff_new;
		}

	      return fld_data;
	    }


	  memset (buff_new, 0, 255);
	  strcpy (format, ptr);	// 'format' will get changed by the calls to get_data_from_formatted_field
#ifdef DEBUG
	  A4GL_debug ("fld_data=%s\n", fld_data);
#endif
	  strcpy (tmpbuff, fld_data);
	  mmm_s = get_data_from_formatted_field ("mmm", tmpbuff, format);
	  //A4GL_pause_execution();
	  if (mmm_s)
	    {
	      int a;
	      for (a = 1; a <= 12; a++)
		{
		  if (strcmp (A4GL_find_str_resource_int ("_MON", a), mmm_s) == 0)
		    {
		      mmm = a;
		      break;
		    }
		}
	    }
	  else
	    {
	      d = get_data_from_formatted_field ("mm", tmpbuff, format);

	      if (d)
		mmm = atol (d);
	      else
		mmm = -1;
	    }

	  // Just removed any 'ddd' - they are ignored...
	  d = get_data_from_formatted_field ("ddd", tmpbuff, format);

	  d = get_data_from_formatted_field ("dd", tmpbuff, format);
	  if (d)
	    dd = atol (d);
	  else
	    dd = -1;
	  d = get_data_from_formatted_field ("yyyy", tmpbuff, format);

	  if (d)
	    {
	      if (strlen (d) != 4 && strlen (d) != 2)
		{
		  return 0;
		}
	      else
		{
		  if (strlen (d) == 2)
		    {
		      yy = A4GL_modify_year (atol (d));
		    }
		  else
		    {

		      yy = atol (d);
		    }
		}
	    }
	  else
	    {
	      d = get_data_from_formatted_field ("yy", tmpbuff, format);
	      if (d)
		{
		  if (strlen (d) != 2)
		    {
		      return 0;
		    }

		  yy = A4GL_modify_year (atol (d));
		}
	      else
		yy = -1;
	    }

	  if (dd == -1 || mmm == -1 || yy == -1)
	    {
	      // Couldn't figure  out one of them...
	      A4GL_exitwith ("Unable to determine date from format");
	      return "";
	    }
#ifdef DEBUG
	  A4GL_debug ("Got dd=%d mmm=%d yy=%d", dd, mmm, yy);
#endif

	  rval = A4GL_gen_dateno (dd, mmm, yy);
	  A4GL_push_date (rval);
	  d = A4GL_char_pop ();
	  strcpy (buff_new, d);
	  done++;
	  free (d);
	  fld_data = buff_new;
	}
      if (!done)
	{
	  if (A4GL_stod (fld_data, &adate, 0) == 1)
	    {
	      char *d;
	      static char buff_new[256];
	      A4GL_push_date (adate);
	      d = A4GL_char_pop ();
	      strcpy (buff_new, d);
	      free (d);
	      fld_data = buff_new;

	    }
	}
    }
#ifdef DEBUG
  A4GL_debug ("Returning : %s", fld_data);
#endif
  return fld_data;
}


int
A4GL_check_and_copy_field_to_data_area (struct s_form_dets *form,
					struct struct_scr_field *fprop, char *fld_data, char *data_area, int var_dtype)
{
  int pprval;
  int dsize;

  fld_data = A4GL_fld_data_ignore_format (fprop, fld_data);
  if (fld_data == 0)
    {
      return 0;
    }
#ifdef DEBUG
  A4GL_debug ("Got fld_data as : %s", fld_data);
#endif


  if (A4GL_is_numeric_datatype (fprop->datatype) && 0)
    {
      char *tmpptr;
      tmpptr = strdup (fld_data);

      A4GL_decstr_convert (tmpptr, A4GL_get_convfmts ()->posix_decfmt, A4GL_get_convfmts ()->posix_decfmt, 0, 1, -1);	// validate
      if (tmpptr[0] != 0)	//conversion succesful
	strcpy (fld_data, tmpptr);
      free (tmpptr);
    }


  A4GL_push_param (fld_data, DTYPE_CHAR);


  if (A4GL_get_convfmts ()->ui_decfmt.decsep != '.'
      && (A4GL_is_numeric_datatype (fprop->datatype) || A4GL_is_numeric_datatype (var_dtype)))
    {
      // its a A4GL_get_convfmts()->ui_decfmt.decsep separator not a '.' - lets convert it
      A4GL_convert_ui_char_on_stack_decimal_sep ();
    }

  if ((fprop->datatype & 0xf) == DTYPE_CHAR || (fprop->datatype & 0xf) == DTYPE_VCHAR)
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
#ifdef DEBUG
	  A4GL_debug ("But I got a null back - strlen = %d fprop->datatype=%x %d", strlen (fld_data), fprop->datatype, DTYPE_DTIME);
#endif
	  if (strlen (fld_data))
	    {
	      pprval = 0;
	    }
	}

      if (!A4GL_conversion_ok (-1))
	{
	  pprval = 0;
	}

      if ((fprop->datatype == DTYPE_INT || fprop->datatype == DTYPE_SMINT || fprop->datatype == DTYPE_SERIAL))
	{
	  {
	    if (a_strchr (fld_data, A4GL_get_convfmts ()->ui_decfmt.decsep))
	      {
#ifdef DEBUG
		A4GL_debug ("Looks like a decimal in a numeric field");
#endif
		pprval = 0;
	      }
	  }
	}
    }

  return pprval;

}

static int
get_inc_quotes (int a)
{
  if ((a & DTYPE_MASK) == DTYPE_CHAR || (a & DTYPE_MASK) == DTYPE_VCHAR)
    return 1;
  if ((a & DTYPE_MASK) == DTYPE_DATE)
    return 2;
  if ((a & DTYPE_MASK) == DTYPE_DTIME)
    return 3;
  if ((a & DTYPE_MASK) == DTYPE_INTERVAL)
    return 4;
  return 0;
}

void
UILIB_A4GL_direct_to_ui (char *t, char *s)
{
  if (strcmp (t, "FLUSHINP") == 0)
    {
      flushinp ();
    }
  if (strcmp (t, "FILE") == 0)
    {
      A4GL_push_int (0);
    }
  if (strcmp (t, "NAMEDFILE") == 0)
    {
      A4GL_push_int (0);
    }
  if (strcmp (t, "GETFILE") == 0)
    {
      A4GL_push_int (0);
    }
// Does nothing - require by the API...
}

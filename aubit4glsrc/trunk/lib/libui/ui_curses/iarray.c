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
# $Id: iarray.c,v 1.21 2003-06-13 10:04:01 mikeaubury Exp $
#*/

/**
 * @file
 * Input array implementation
 *
 * @todo Add Doxygen A4GL_comments to file
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

#define CONTROL_STACK_LENGTH 10

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

extern int m_lastkey;
extern WINDOW *currwin;
struct s_inp_arr *curr_arr_inp;
void A4GL_mja_set_current_field (FORM * form, FIELD * field);

struct s_movement
{
  int scr_line;
  int arr_line;
  int attrib_no;
};


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/


static void init_arr_line (struct s_inp_arr *sio, int n);
void A4GL_mja_pos_form_cursor (FORM * form);
//int A4GL_set_fields_inp_arr (struct s_inp_arr *sio);
int A4GL_turn_field_off (FIELD * f);
int A4GL_turn_field_on (FIELD * f);
int A4GL_turn_field_on2 (FIELD * f, int a);
void A4GL_debug_print_field_opts (FIELD * a);
static int process_control_stack (struct s_inp_arr *arr);
static int A4GL_has_something_on_control_stack (struct s_inp_arr *sio);

static void A4GL_add_to_control_stack (struct s_inp_arr *sio, int op,
				       FIELD * f, char *parameter,
				       int extent);

static void A4GL_newMovement (struct s_inp_arr *arr, int scr_line,
			      int arr_line, int attrib);
static void A4GL_init_control_stack (struct s_inp_arr *sio, int malloc_data);
void *A4GL_memdup (void *ptr, int size);
/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/**
 *
 *
 * @param
 */
static void
A4GL_iclear_srec_line (struct struct_screen_record *srec, int line)
{
  int a;
  char srec1[256];

  strcpy (srec1, srec->name);
  strcat (srec1, ".*");

  for (a = 0; a < srec->attribs.attribs_len + 1; a++)
    {
      A4GL_push_char (" ");
    }
  A4GL_iarr_arr_fields (srec->attribs.attribs_len + 1, 0, 0, srec1, line + 1,
			0, 0);
}

/**
 *
 *
 * @param
 */
static void
A4GL_idraw_arr (struct s_inp_arr *inpa, int type, int no)
{
  char srec2[256];
  int topline;
  int scr_line;
  int fonly = 0;
#ifdef DEBUG
  {
    A4GL_debug ("in draw_arr %p %d %d", inpa, type, no);
  }
#endif
  if (type < 0)
    {
      type = 0 - type;
      fonly = 1;
    }

  A4GL_debug ("*** no=%d inpa->no_arr=%d\n", no, inpa->no_arr);

  topline = inpa->arr_line - inpa->scr_line + 1;
  scr_line = no - topline + 1;

  if (scr_line > inpa->srec->dim)
    {
      A4GL_debug ("scr line out of range %d %d\n", scr_line, inpa->srec->dim);
      return;
    }
  if (scr_line < 0)
    {
      A4GL_debug ("scr line out of range <0 %d", scr_line);
      return;
    }

  if (no > inpa->no_arr)
    {
      A4GL_debug ("arr no out of range %d %d\n", scr_line, inpa->srec->dim);
      A4GL_iclear_srec_line (inpa->srec, scr_line - 1);
      return;
    }

  strcpy (srec2, inpa->srec->name);
  strcat (srec2, ".*");

  if (type == 2)
    {
      A4GL_debug ("calling set_arr_Fields");
      A4GL_set_arr_fields (inpa->nbind, 1, srec2, scr_line, 0, 0);
#ifdef DEBUG
      {
	A4GL_debug ("Done");
      }
#endif
      return;
    }


  if (fonly)
    A4GL_push_bind (inpa->binding, 1, no, inpa->arr_elemsize);
  else
    A4GL_push_bind (inpa->binding, inpa->nbind, no, inpa->arr_elemsize);

  A4GL_debug ("Print array no %d to scr %d", no, scr_line);
  A4GL_debug ("calling inpa_arR_fields");
  if (inpa->highlight)
    {
      A4GL_debug ("With highlight");
      A4GL_iarr_arr_fields (inpa->nbind, fonly, type * A_REVERSE, srec2,
			    scr_line, 0, 0);
    }
  else
    {
      A4GL_debug ("Without highlight");
      A4GL_iarr_arr_fields (inpa->nbind, fonly, 0, srec2, scr_line, 0, 0);
    }
}

/**
 *
 *
 * @param
 */
static void
iclear_srec (struct struct_screen_record *srec)
{
  int b;

  for (b = 0; b < srec->dim; b++)
    {
      A4GL_iclear_srec_line (srec, b);
    }
}

/**
 *
 *
 * @param
 */
static void
A4GL_idraw_arr_all (struct s_inp_arr *inpa)
{
  int a;
  int topline;
  topline = inpa->arr_line - inpa->scr_line + 1;
#ifdef DEBUG
  {
    A4GL_debug ("Draw_arr_all");
  }
#endif
  for (a = 0; a < inpa->srec->dim; a++)
    {
      /* if (a + topline < inpa->no_arr)
         {
       */
      A4GL_idraw_arr (inpa, a + topline == inpa->arr_line, a + topline);
#ifdef DEBUG
      {
	A4GL_debug ("after draw_arr (6)");
      }
#endif
      /* } */
    }
  A4GL_idraw_arr (inpa, 1, inpa->arr_line);
#ifdef DEBUG
  {
    A4GL_debug ("after draw_arr (7)");
  }
#endif
  //mja_refresh ();
}

/**
 *
 *
 * @param
 */
static void
ireinpalay_arr (struct s_inp_arr *arr, int reinpa)
{

  A4GL_debug ("scr_line=%d arr_line=%d\n", arr->scr_line, arr->arr_line);
  if (reinpa == 1)
    {
      A4GL_debug ("Reinpalay one");
      A4GL_idraw_arr (arr, 0, arr->last_arr);
#ifdef DEBUG
      {
	A4GL_debug ("after draw_arr (4)");
      }
#endif
      A4GL_debug ("Display one");
      A4GL_idraw_arr (arr, 1, arr->arr_line);
#ifdef DEBUG
      {
	A4GL_debug ("after draw_arr (5)");
      }
#endif
    }
  if (reinpa == 2)
    {
      A4GL_debug ("Reinpalay all");
      A4GL_idraw_arr_all (arr);
    }
  A4GL_mja_wrefresh (currwin);
}

/**
 *
 *
 * @param
 */
/*
static char *
proc_zero(char *s)
{
  static char *buff="Not Set";
  if (s==0)
    return buff;
  else
    return s;
}
*/

#ifdef NOT_USED
/**
 * It have a direct return
 * @todo Confirm if its like this and if remove the rest of the code
 */
static void
debug_print_field (FIELD * f)
{
  struct struct_scr_field *attr;
  attr = (struct struct_scr_field *) field_userptr (f);
  A4GL_debug ("Field : %p:\n", f);
  A4GL_debug_print_field_opts (f);
  /* debug("attr=%p",f,attr); */
  A4GL_debug ("Value='%s':", field_buffer (f, 0));
  if (attr)
    {
      //debug ("      Datatype   : %d:", attr->dtype);
      A4GL_debug ("      Field No   : %d:", attr->field_no);
      A4GL_debug ("      Tabname    : %s:", attr->tabname);
      A4GL_debug ("      Colname    : %s:", attr->colname);
/*
      A4GL_debug ("      Metrics    : %d:", attr->metrics_cnt);
      A4GL_debug ("      autonext   : %d:", attr->autonext);
      A4GL_debug ("      invisible  : %d:", attr->invisible);
      A4GL_debug ("      noentry    : %d:", attr->noentry);
      A4GL_debug ("      required   : %d:", attr->required);
      A4GL_debug ("      reverse    : %d:", attr->reverse);
      A4GL_debug ("      shift      : %d:", attr->shift);
      A4GL_debug ("      verify     : %d:", attr->verify);
      A4GL_debug ("      wordwrap   : %d:", attr->wordwrap);
      A4GL_debug ("      colour     : %d:", attr->colour);
      A4GL_debug ("      include    : %s:", proc_zero (attr->include));
      A4GL_debug ("      A4GL_comments   : %s:", proc_zero (attr->comments));
      A4GL_debug ("      default_val: %s:", proc_zero (attr->default_val));
      A4GL_debug ("      format     : %s:", proc_zero (attr->format));
      A4GL_debug ("      picture    : %s:", proc_zero (attr->picture));
      A4GL_debug ("      program    : %s:", proc_zero (attr->program));
      A4GL_debug ("      dynamic    : %d\n\n:", attr->dynamic);
*/
    }
}
#endif

#ifdef NOT_USED
/**
 *
 *
 * @param
 */
static void
debug_print_field_list (FIELD ** fld_list)
{
  int a;
  A4GL_debug ("Field List (%p):", fld_list);
  for (a = 0; fld_list[a]; a++)
    {
      debug_print_field (fld_list[a]);
    }
}
#endif

/**
 *
 *
 * @param
 */
static int
pop_iarr_var (struct s_form_dets *form, int x, int y, int elem,
	      struct BINDING *b)
{
  A4GL_debug ("In pop_iarr_var %d %d", x, y);
  y--;


  if (A4GL_copy_field_data (form))
    {
      A4GL_push_char (field_buffer (form->currentfield, 0));
      A4GL_debug ("Pushed field buffer");
      A4GL_pop_var2 ((char *) b[x].ptr + (y * elem), b[x].dtype, b[x].size);
      A4GL_debug ("Popped field buffer into variable");
      return 1;
    }
  return 0;
}

/**
 *
 *
 * @param
 */
static int
iarr_loop (struct s_inp_arr *arr)
{
  struct s_form_dets *form;
  int a;
  int reinpa;
  FORM *mform;

//int iloop_action;     // What am I proposing to do ?
//#define ILOOP_ACTION_MOVEFIELD
//#define ILOOP_ACTION_MOVELINE
//#define ILOOP_KEYPRESS

  //int iloop_extent;   // How much am i proposing to do it ?
  //void *iloop_context[3];  // What am i doing it do ?


  curr_arr_inp = arr;
  form = arr->currform;
  A4GL_set_array_mode ('I');

  m_lastkey = 0;
#ifdef DEBUG
  {
    A4GL_debug ("Currform=%p (s_form_dets)", form);
  }
#endif
  if (form != A4GL_get_curr_form ())
    {
      A4GL_exitwith ("Input form is not the current form!");
      exit (0);
    }
  mform = form->form;



  A4GL_idraw_arr (arr, 2, arr->arr_line);





  if (A4GL_has_something_on_control_stack (arr))
    {
      int rval;
      rval = process_control_stack (arr);
      A4GL_debug ("Control stack - he say %d", rval);
      return rval;
    }
  else
    {
      if (form->currentfield !=
	  arr->field_list[arr->scr_line - 1][arr->curr_attrib])
	{
	  form->currentfield =
	    arr->field_list[arr->scr_line - 1][arr->curr_attrib];
	}
      A4GL_mja_set_current_field (mform, form->currentfield);
      A4GL_mja_pos_form_cursor (mform);
      abort_pressed = 0;
      a = A4GL_getch_win ();
      if (abort_pressed)
	{
	  a = -1;
	  fprintf (stderr, "ABORT\n");
	  fflush (stderr);
	}
      m_lastkey = a;
    }



  reinpa = 0;





  if (a == KEY_LEFT && mform->curcol == 0 && mform->currow == 0)
    {
      a = KEY_BACKSPACE;
    }

  if (a == A4GL_key_val ("ACCEPT"))
    {
      a = 27;
    }

  if (a == A4GL_key_val ("NEXT"))
    {
      a = KEY_NPAGE;
    }

  if (a == A4GL_key_val ("PREV"))
    {
      a = KEY_PPAGE;
    }

  switch (a)
    {
    case KEY_NPAGE:
      A4GL_newMovement (arr,
			arr->scr_line,
			arr->arr_line + arr->srec->dim, arr->curr_attrib);
      break;

    case KEY_PPAGE:
      A4GL_newMovement (arr,
			arr->scr_line,
			arr->arr_line - arr->srec->dim, arr->curr_attrib);
      break;



    case KEY_DOWN:
      A4GL_newMovement (arr,
			arr->scr_line + 1, arr->arr_line + 1,
			arr->curr_attrib);

      break;


    case KEY_RIGHT:
      A4GL_debug ("Key_right");
      A4GL_int_form_driver (mform, REQ_NEXT_CHAR);
      break;

    case KEY_LEFT:
      A4GL_debug ("Key_left");
      A4GL_int_form_driver (mform, REQ_PREV_CHAR);
      break;


    case 10:
    case 13:
    case '\t':
    case KEY_ENTER:
      A4GL_newMovement (arr, arr->scr_line, arr->arr_line,
			arr->curr_attrib + 1);

      break;

    case KEY_BACKSPACE:
      A4GL_newMovement (arr, arr->scr_line, arr->arr_line,
			arr->curr_attrib - 1);
      break;

    case KEY_UP:
      A4GL_newMovement (arr,
			arr->scr_line - 1, arr->arr_line - 1,
			arr->curr_attrib);
      break;

    case 27:
      A4GL_add_to_control_stack (arr, FORMCONTROL_EXIT_INPUT_OK, 0, 0, a);
      break;

    case -1:
      A4GL_add_to_control_stack (arr, FORMCONTROL_EXIT_INPUT_ABORT, 0, 0, a);
      break;

    }



  if (a > 0 && a < 255)
    {
      A4GL_add_to_control_stack (arr, FORMCONTROL_KEY_PRESS, 0, 0, a);
    }


  return -1;

}

/**
 *
 *
 * @param
 */
static int
gen_field_list_vals (void *a, void *b, int nv, ...)
{
  va_list va;
  va_start (va, nv);
  return A4GL_gen_field_list (a, b, nv, &va);
}

/**
 *
 *
 * @param
 */
static FIELD ***
gen_srec_field_list (char *s, struct s_form_dets *form, int a, int d)
{
  FIELD ***fld_list;
  int fc;
  int lc;
  char buff[64];
  A4GL_debug ("Generating field list for screen array a=%d d=%d", a, d);

  fld_list = (FIELD ***) calloc (d, sizeof (FIELD **));

  for (lc = 0; lc < d; lc++)
    {
      A4GL_debug ("Generating field list for line %d", lc);
      strcpy (buff, s);
      strcat (buff, ".*");
      A4GL_debug ("calling gen_field_list_vals with %p %p %d %s %d %d",
		  &fld_list[lc], form, a, buff, lc, 0);
      fc = gen_field_list_vals (&fld_list[lc], form, a, buff, lc + 1, 0, 0);
      A4GL_debug (">>>> fc=%d fld_list[lc]=%p", fc, fld_list[lc]);
    }

  A4GL_debug ("Field lists (gen_srec_field_list)");

  for (lc = 0; lc < d; lc++)
    {
      A4GL_debug ("Srec line : %d %p", lc, fld_list[lc]);
      for (fc = 0; fc < a; fc++)
	{
	  A4GL_debug ("Line %d Col %d Field %p:", lc, fc, fld_list[lc][fc]);
	}
    }
  A4GL_debug ("End of list");
  return fld_list;
}

/**
 * Implementation of input array.
 *
 * Called by generated code for corresponding of input array 
 * its part of run-time library.
 * 
 * @param inpa
 * @param ptr
 * @param srecname Screen Record name
 * @param attrib Attributes used during input array
 * @return
 */
int
A4GL_inp_arr (void *vinpa, int defs, char *srecname, int attrib, int init)
{
  FIELD ***fld_list;
  //int a;

  struct s_inp_arr *inpa;
  inpa = (struct s_inp_arr *) vinpa;

  curr_arr_inp = inpa;
  A4GL_debug ("In A4GL_inp_arr : %s %p %p %d", srecname, defs, inpa, attrib);
  if (inpa->srec == 0)
    {
      A4GL_debug ("inpaarr1");
      inpa->srec = A4GL_get_srec (srecname);

      A4GL_debug (">>>>inpa->srec=%p", inpa->srec);

      if (inpa->srec == 0)
	{
	  A4GL_exitwith ("Screen record not found");
	  return 0;
	}
      inpa->currform = A4GL_get_curr_form ();

      A4GL_init_control_stack (inpa, 1);

#ifdef DEBUG
      {
	A4GL_debug ("inpa->currform=%p", inpa->currform);
      }
#endif
      inpa->last_arr = -1;
      inpa->scr_line = -1;
      inpa->arr_line = -1;
      inpa->cntrl = 1;
      inpa->highlight = 0;


      A4GL_debug ("********** no_arr=%d\n", inpa->no_arr);
      A4GL_debug ("********** nbind=%d\n", inpa->nbind);
      if (inpa->no_arr == 0)
	init_arr_line (inpa, 0);

      A4GL_set_arr_curr (inpa->arr_line);
      A4GL_set_scr_line (inpa->scr_line);
      A4GL_set_arr_count (inpa->no_arr);

//set_fields_inp_arr(inpa);
      /* A4GL_debug ("Srec dimension name=%s dim=%d no_Attr=%d", inpa->srec->name, inpa->srec->dim, inpa->srec->attribs.attribs_len); */
      A4GL_debug ("inpaarr2");
      if (inpa->srec == 0)

	{

	  A4GL_debug ("Screen record does not exist");

	  return 0;

	}
      A4GL_debug ("inpaarr3");

      if (inpa->srec->attribs.attribs_len != inpa->nbind)

	{

	  A4GL_debug ("Too many or too few variables for fields %d %d",
		      inpa->srec->dim, inpa->nbind);

	  return 0;

	}

      A4GL_debug ("Clearing Record");
      iclear_srec (inpa->srec);
      A4GL_debug ("Cleared record");

      fld_list =
	gen_srec_field_list (inpa->srec->name, inpa->currform,
			     inpa->srec->attribs.attribs_len + 1,
			     inpa->srec->dim);
      A4GL_debug ("All done...");
      inpa->field_list = (void ***) fld_list;
      A4GL_set_fields_inp_arr (inpa);

      //for (a = 0; a < inpa->srec->dim; a++)
      //{
      //if (a < inpa->no_arr)
//
      //{

      //idraw_arr (inpa, a + 1 == inpa->arr_line, a + 1);
//
      //}
//
      //}
      A4GL_idraw_arr (inpa, 1, inpa->arr_line);

      A4GL_gui_scroll (inpa->no_arr);
      inpa->last_scr_line = -1;
      inpa->last_arr_line = -1;
      //set_arr_curr (inpa->arr_line);
      //set_scr_line (inpa->scr_line);


      A4GL_set_arr_count (inpa->no_arr);

      //mja_wrefresh (currwin);
      inpa->curr_attrib = 0;
      //debug("MJAMJA setting current field = %p",inpa->field_list[inpa->scr_line - 1][inpa->curr_attrib]);
      A4GL_newMovement (inpa, 0, 0, 0);

    }
  A4GL_debug ("inpaarr4");
  //ireinpalay_arr (inpa, 2);


  return iarr_loop (inpa);
}


/**
 * I think its not used because the function that calls it its not used
 */
/*
int
set_scrline_ia (int np)
{
  int a;
  if (np != 1)
    {
      A4GL_exitwith ("set_scrline requires 1 parameter");
      return 0;
    }
  a = A4GL_pop_int ();
  curr_arr_inp->scr_line = a;
  A4GL_set_scr_line (a);
  A4GL_idraw_arr_all (curr_arr_inp);
#ifdef DEBUG
  {    A4GL_debug ("Set scrline...%d", a);  }
#endif
  return 1;
}
*/

/**
 * I think its not used because the function that calls it its not used
 */
/*
int
set_arrline_ia (int np)
{
  int a;
  if (np != 1)
    {
      A4GL_exitwith ("set_arrline requires 1 parameter");
      return 0;
    }
  a = A4GL_pop_int ();
  curr_arr_inp->arr_line = a;
  A4GL_set_arr_curr (a);
  A4GL_idraw_arr_all (curr_arr_inp);
#ifdef DEBUG
  {    A4GL_debug ("Set arrline... %d", a);  }
#endif
    return 1;
}
*/

/**
 * Not used
 *
 * @todo Confirm if its not used and deleted if so
 */
/*
static void
debug_print_all_fields(FORM *f)
{
  FIELD **fld_list;
  fld_list=form_fields(f);
  debug_print_field_list(fld_list);
}
*/


/* This function disables all fields except those used in the 
* input array itself
*/
int
A4GL_set_fields_inp_arr (void *vsio)
{
  int wid;
  int a, b;
  int nv;
  int flg;
  struct s_form_dets *formdets;
  struct struct_scr_field *field;
  //struct struct_scr_field *prop;
  FIELD **field_list;
  FIELD *firstfield = 0;
  int nofields;
  struct s_inp_arr *sio;
  sio = vsio;


  wid = 1;
  A4GL_debug ("in set fields");
  formdets = sio->currform;
  A4GL_debug ("set fdets");

  flg = 0;

  A4GL_debug ("Turning off all");

  field_list = form_fields (sio->currform->form);

  for (a = 0; field_list[a]; a++)
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

  nv = sio->nbind;

  if (nofields != nv - 1)
    {
      A4GL_debug
	("Number of fields (%d) is not the same as the number of vars (%d)",
	 nofields + 1, nv);
      A4GL_exitwith
	("Number of fields is not the same as the number of variables");
      return 0;
    }


  A4GL_debug ("turning some back on");
  for (a = 0; a < sio->srec->dim; a++)
    {
      for (b = 0; b < sio->srec->attribs.attribs_len; b++)
	{
	  A4GL_debug ("MJAMJA Turn on field : %p", sio->field_list[a][b]);
	  A4GL_turn_field_on2 (sio->field_list[a][b], 1);
	}
    }
  return 1;
}

void
A4GL_mja_pos_form_cursor (FORM * form)
{
  int a;
  A4GL_debug ("mja_pos_form_cursor called with form=%p field would be %p",
	      form, current_field (form));

  a = pos_form_cursor (form);
  if (a != E_OK)
    {
      A4GL_debug ("Error in pos_form_cursor - %d", a);
    }
  A4GL_mja_wrefresh (currwin);
}



void
A4GL_mja_set_current_field (FORM * form, FIELD * field)
{
  int a;
  a = set_current_field (form, field);
  if (a != E_OK)
    {
      A4GL_debug ("MJA Error in mja_set_current_field: %p %p", form, field);
      switch (a)
	{
	case E_SYSTEM_ERROR:
	  A4GL_debug ("System Error");
	  break;
	case E_BAD_ARGUMENT:
	  A4GL_debug ("Bad Argument");
	  break;
	case E_BAD_STATE:
	  A4GL_debug ("Bad State");
	  break;
	case E_INVALID_FIELD:
	  A4GL_debug ("Invalid Field");
	  break;
	case E_REQUEST_DENIED:
	  A4GL_debug ("Request Denied");
	  break;
	}
    }
  else
    {
      A4GL_debug ("MJA A4GL_mja_set_current_field OK");
      A4GL_mja_pos_form_cursor (form);
    }
}

/* 
* This function is used to initialize a line in an
* input array to null
* this is done when the user moves to a line
* which is greater than the current maximum number of lines
* set from a set_count or previous movement
*/
static void
init_arr_line (struct s_inp_arr *sio, int n)
{
  int a;
  struct BINDING *b;

  b = sio->binding;

  for (a = sio->nbind - 1; a >= 0; a--)
    {
      A4GL_debug ("b[a].dtype=%d", b[a].dtype);
      A4GL_setnull (b[a].dtype,
		    (char *) b[a].ptr + sio->arr_elemsize * (n - 1),
		    b[a].size);
    }
}

/* 
* This function adds a value to the control stack
* this is read to determine when to call before/after fields etc
*
*/
static void
A4GL_add_to_control_stack (struct s_inp_arr *sio, int op, FIELD * f,
			   char *parameter, int extent)
{
  char *field_name;
  int a;
  struct struct_scr_field *attr;

  A4GL_debug ("add to control stack called with op=%d field=%p extent=%d", op,
	      f, extent);

  field_name = 0;

  if (f)
    {
      attr = (struct struct_scr_field *) field_userptr (f);
      field_name = attr->colname;
    }
  a = sio->fcntrl_cnt;
  sio->fcntrl[a].op = op;
  sio->fcntrl[a].parameter = parameter;
  sio->fcntrl[a].field_name = field_name;
  sio->fcntrl[a].field_number = 0;	// This is reserved for future enhancement :)
  sio->fcntrl[a].extent = extent;
  sio->fcntrl_cnt++;

}




/* This function determines if there is something to do on the control stack */
static int
A4GL_has_something_on_control_stack (struct s_inp_arr *sio)
{
  if (sio->fcntrl_cnt)
    return 1;
  return 0;
}




/***************************************
	This function creates the control stack and can also be used for clearing it down (if malloc_data is set to 0)
****************************************/
static void
A4GL_init_control_stack (struct s_inp_arr *sio, int malloc_data)
{
  int a;

  A4GL_debug ("init_control_stack - malloc_data = %d\n", malloc_data);
// Do we need to allocate the storage area ?
  if (malloc_data)
    {
      sio->fcntrl = malloc (sizeof (struct s_formcontrol) * 10);
      sio->fcntrl_cnt = 0;
    }

// Do we need to clear down any old data ?
  if (sio->fcntrl_cnt)
    {
      for (a = 0; a < sio->fcntrl_cnt; a++)
	{
	  // parameter is the only one that will be malloc'd
	  if (sio->fcntrl[a].parameter)
	    {
	      free (sio->fcntrl[a].parameter);
	    }
	}
    }

// Go through each line and set everything to zero...
  for (a = 0; a < CONTROL_STACK_LENGTH; a++)
    {
      sio->fcntrl[a].op = 0;
      sio->fcntrl[a].parameter = 0;
      sio->fcntrl[a].field_number = 0;
      sio->fcntrl[a].state = 99;
      sio->fcntrl[a].extent = 0;

    }
}


/*
 * A4GL_memdup - Allocate a block of memory just like another block
*/
/*
void *memdup(void *ptr,int size) {
	void *p2;
	p2=malloc(size);
	memcpy(p2,ptr,size);
	return p2;
}
*/



/*
 *  Set up a record for a desired movement...
 */
void
A4GL_newMovement (struct s_inp_arr *arr, int scr_line, int arr_line,
		  int attrib)
{
  struct s_movement *ptr;
  void *last_field;
  void *next_field;
  struct struct_scr_field *f;


  A4GL_debug ("newMovement %d %d %d", scr_line, arr_line, attrib);
  if (arr_line > 800000)
    {
      char *ptr = 0;
      *ptr = 0;
    }

// Sanity check the movements....

  if (arr_line < 1)
    {
      // Attempt to move off the top program array...
      A4GL_newMovement (arr, scr_line, 1, attrib);
      return;
    }


  if (attrib < 0)
    {
      // attempt to move too far to the left
      // In informix - this results in just going up a line - still on field 0
      A4GL_debug ("Too far to the left");
      A4GL_newMovement (arr, scr_line, arr_line - 1, 0);
      return;
    }


  if (scr_line > arr->srec->dim)
    {
      A4GL_debug ("Too far down in screen lines");
      scr_line = arr->srec->dim;
      A4GL_newMovement (arr, scr_line, arr_line, attrib);
      return;
    }

  if (scr_line <= 0)
    {
      A4GL_debug ("Too far up in screen lines");
      scr_line = 1;
      A4GL_newMovement (arr, scr_line, arr_line, attrib);
      return;
    }

  if ((arr_line + 1) - scr_line < 0)
    {
      A4GL_debug ("scr lines too big for current line %d %d", scr_line,
		  arr_line);
      scr_line = arr_line - scr_line + 1;
      A4GL_newMovement (arr, scr_line, arr_line, attrib);
      return;
    }



  if (attrib >= arr->srec->attribs.attribs_len)
    {
      // Too far over to the right - wrap around to the start of the next line
      A4GL_debug ("Too far to the right");
      A4GL_newMovement (arr, scr_line + 1, arr_line + 1, 0);
      return;
    }



  if (arr_line > arr->arr_size)
    {				// Attempting to move off the bottom of the array...
      A4GL_debug ("Too far down the program array");
      // Do nothing at all...
      return;
    }


  if (arr_line > arr->no_arr)
    {				// Attempting to move off the bottom of the current set_count
      // @todo - check see if we need to do this here or later...
      A4GL_debug ("Attempting to add a new line");
      if ((arr->inp_flags & 0x01) == 0x01)
	{
	  A4GL_debug ("Refused - no new lines set");
	  // Do nothing at all...
	  return;		// NO NEW ROWS....
	}
    }





  if (arr->scr_line > 0)
    last_field = arr->field_list[arr->scr_line - 1][arr->curr_attrib];
  else
    last_field = 0;

  next_field = arr->field_list[scr_line - 1][attrib];
  f = (struct struct_scr_field *) (field_userptr (next_field));

  if (A4GL_has_bool_attribute (f, FA_B_NOENTRY))
    {
      int dir = 0;
      while (1)
	{

	  if (dir == 0)
	    {
	      if (attrib >= arr->curr_attrib)
		{		// We want to move to the right..
		  dir = 1;
		}
	      else
		{
		  dir = -1;
		}
	    }
	  A4GL_debug ("next_field= srec[%d %d]\n", scr_line, attrib);
	  next_field = arr->field_list[0][attrib];
	  A4GL_debug ("next_field = %p", next_field);
	  f = (struct struct_scr_field *) (field_userptr (next_field));
	  A4GL_debug ("fprop=%p", f);

	  if (A4GL_has_bool_attribute (f, FA_B_NOENTRY))
	    {
	      attrib += dir;
	      if (attrib >= arr->srec->attribs.attribs_len)
		{
		  attrib = 0;
		  scr_line++;
		  arr_line++;
		}

	      if (attrib < 0)
		{
		  attrib = arr->srec->attribs.attribs_len;
		  scr_line--;
		  arr_line--;
		}
	    }
	  else
	    {
	      A4GL_debug ("Found somewhere free...");
	      A4GL_newMovement (arr, scr_line, arr_line, attrib);	// So keep going...
	      return;
	    }
	}
    }




  ptr = malloc (sizeof (struct s_movement));
  ptr->scr_line = scr_line;
  ptr->arr_line = arr_line;
  ptr->attrib_no = attrib;
  if (arr_line != arr->arr_line)
    {
      A4GL_debug ("Bef1");
      A4GL_add_to_control_stack (arr, FORMCONTROL_BEFORE_FIELD, next_field,
				 A4GL_memdup (ptr,
					      sizeof (struct s_movement)), 0);
      A4GL_add_to_control_stack (arr, FORMCONTROL_BEFORE_ROW, next_field,
				 A4GL_memdup (ptr,
					      sizeof (struct s_movement)), 0);

      if (last_field)
	{
	  A4GL_add_to_control_stack (arr, FORMCONTROL_AFTER_ROW, last_field,
				     0, 0);
	  A4GL_add_to_control_stack (arr, FORMCONTROL_AFTER_FIELD, last_field,
				     0, 0);
	}
    }
  else
    {
      A4GL_debug ("Bef2");
      A4GL_add_to_control_stack (arr, FORMCONTROL_BEFORE_FIELD, next_field,
				 A4GL_memdup (ptr,
					      sizeof (struct s_movement)), 0);
      if (last_field)
	A4GL_add_to_control_stack (arr, FORMCONTROL_AFTER_FIELD, last_field,
				   0, 0);
    }

  free (ptr);
}



/* 
* process any waiting actions 
*
*/
static int
process_control_stack (struct s_inp_arr *arr)
{
  int a;
  int rval;
  int new_state;
  struct s_movement *ptr_movement;

  rval = -1;
  new_state = 99;


  a = arr->fcntrl_cnt - 1;

  if (arr->fcntrl[a].op == FORMCONTROL_BEFORE_INPUT)
    {
      new_state = 0;
      rval = -99;
    }

  if (arr->fcntrl[a].op == FORMCONTROL_AFTER_INPUT)
    {
      if (arr->fcntrl[a].op == 99)
	{
	  new_state = 50;
	  rval = -95;		// Do any AFTER INPUT section
	}

      if (arr->fcntrl[a].op == 50)
	{
	  new_state = 0;
	  rval = -94;		// CLEANUP
	}
    }


  if (arr->fcntrl[a].op == FORMCONTROL_EXIT_INPUT_OK)
    {
      new_state = 0;
      A4GL_add_to_control_stack (arr, FORMCONTROL_AFTER_INPUT, 0, 0, 0);
      rval = 0;
    }


  if (arr->fcntrl[a].op == FORMCONTROL_EXIT_INPUT_ABORT)
    {
      //extern int int_flag;
      A4GL_debug ("FORM ABORT..");
      int_flag = 1;
      A4GL_add_to_control_stack (arr, FORMCONTROL_AFTER_INPUT, 0, 0, 0);
      rval = 0;
      new_state = 0;
    }


  if (arr->fcntrl[a].op == FORMCONTROL_BEFORE_DELETE)
    {
      new_state = 0;
      rval = -12;
    }


  if (arr->fcntrl[a].op == FORMCONTROL_AFTER_DELETE)
    {
      new_state = 0;
      rval = -13;
    }


  if (arr->fcntrl[a].op == FORMCONTROL_BEFORE_ROW)
    {
      ptr_movement = (struct s_movement *) arr->fcntrl[a].parameter;

      if (ptr_movement->arr_line > arr->no_arr)
	{
	  A4GL_set_arr_count (ptr_movement->arr_line);
	  init_arr_line (arr, ptr_movement->arr_line);
	  arr->no_arr++;
	}


      arr->scr_line = ptr_movement->scr_line;
      arr->arr_line = ptr_movement->arr_line;
      A4GL_set_arr_curr (ptr_movement->arr_line);
      A4GL_set_scr_line (ptr_movement->scr_line);
      A4GL_debug ("MJAMJA a=%d s=%d", ptr_movement->arr_line,
		  ptr_movement->scr_line);

      if (arr->scr_line != ptr_movement->scr_line);	//ireinpalay_arr (arr, 1);
      else
	ireinpalay_arr (arr, 2);

      new_state = 0;
      rval = -10;
    }



  if (arr->fcntrl[a].op == FORMCONTROL_AFTER_ROW)
    {
      new_state = 0;
      rval = -11;
    }

  if (arr->fcntrl[a].op == FORMCONTROL_BEFORE_INSERT)
    {
      new_state = 0;
      rval = -14;
    }

  if (arr->fcntrl[a].op == FORMCONTROL_AFTER_INSERT)
    {
      new_state = 0;
      rval = -15;
    }

  if (arr->fcntrl[a].op == FORMCONTROL_KEY_PRESS)
    {
      if (arr->fcntrl[a].state == 99)
	{
	  new_state = 50;
	  rval = -90;
	}

      if (arr->fcntrl[a].state == 50)
	{
	  new_state = 0;
	  A4GL_debug ("Checking key state.. %d", arr->fcntrl[a].extent);
	  A4GL_int_form_driver (arr->currform->form, arr->fcntrl[a].extent);
	  A4GL_int_form_driver (arr->currform->form, REQ_VALIDATION);
	  //mja_wrefresh(currwin);
	}
    }


  if (arr->fcntrl[a].op == FORMCONTROL_BEFORE_FIELD)
    {
      ptr_movement = (struct s_movement *) arr->fcntrl[a].parameter;
      new_state = 0;
      arr->curr_attrib = ptr_movement->attrib_no;
      A4GL_debug ("Before field - fieldname=%p", arr->fcntrl[a].field_name);
      A4GL_debug ("Before field - fieldname=%s", arr->fcntrl[a].field_name);
      A4GL_push_long ((long) arr->currentfield);
      A4GL_push_char (arr->fcntrl[a].field_name);
      arr->currentfield =
	arr->field_list[arr->scr_line - 1][arr->curr_attrib];
      rval = -197;
    }


  if (arr->fcntrl[a].op == FORMCONTROL_AFTER_FIELD)
    {
      pop_iarr_var (arr->currform, arr->curr_attrib, arr->arr_line,
		    arr->arr_elemsize, arr->binding);
      new_state = 0;
      A4GL_push_long ((long) arr->currentfield);
      A4GL_push_char (arr->fcntrl[a].field_name);
      rval = -198;
    }

  if (new_state != 0)
    {
      if (arr->fcntrl[a].state == new_state)
	{
	  A4GL_exitwith ("Internal error - no change in state..");
	}
      A4GL_debug ("Setting input control state to %d", new_state);
      arr->fcntrl[a].state = new_state;
    }
  else
    {
      A4GL_debug ("Popping type %d off control stack @ %d", arr->fcntrl[a].op,
		  a);
      arr->fcntrl_cnt--;
      if (arr->fcntrl[a].parameter)
	{
	  free (arr->fcntrl[a].parameter);
	}
    }
  A4GL_debug ("Returning %d\n", rval);
  return rval;
}

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
# $Id: iarray.c,v 1.30 2003-07-27 09:15:30 mikeaubury Exp $
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
#include <ctype.h>

//void A4GL_set_field_attr_with_attr (FIELD * field, int attr, int cmd_type);
static void A4GL_idraw_arr_all (struct s_inp_arr *inpa);

#define CONTROL_STACK_LENGTH 10

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

//extern int m_lastkey;
extern WINDOW *currwin;
struct s_inp_arr *curr_arr_inp;
//void A4GL_mja_set_current_field (FORM * form, FIELD * field);
//int A4GL_form_field_chk_iarr (struct s_inp_arr *sio, int m);
//int A4GL_req_field_input_array (struct s_inp_arr *arr,char typpe, va_list *ap) ;

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
int A4GL_field_name_match (FIELD * f, char *s);

static void init_arr_line (struct s_inp_arr *sio, int n);
static int process_control_stack (struct s_inp_arr *arr);
static int A4GL_has_something_on_control_stack (struct s_inp_arr *sio);

static void A4GL_add_to_control_stack (struct s_inp_arr *sio, int op,
				       FIELD * f, char *parameter,
				       int extent);

static void A4GL_newMovement (struct s_inp_arr *arr, int scr_line,
			      int arr_line, int attrib);
static void A4GL_init_control_stack (struct s_inp_arr *sio, int malloc_data);
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
insert_line_in_array (struct s_inp_arr *inpa)
{
  int a;
  char *src_ptr;
  char *dest_ptr;

  A4GL_debug ("insert_line_in_array no_arr=%d arr_size=%d arr_line=%d",
	      inpa->no_arr, inpa->arr_size, inpa->arr_line);

  if (inpa->no_arr >= inpa->arr_size)
    {
      A4GL_debug ("Array too large");
      return;
    }

  for (a = inpa->no_arr; a >= inpa->arr_line; a--)
    {
      src_ptr = (char *) inpa->binding[0].ptr + inpa->arr_elemsize * (a - 2);
      dest_ptr = (char *) inpa->binding[0].ptr + inpa->arr_elemsize * (a - 1);
      memcpy (dest_ptr, src_ptr, inpa->arr_elemsize);
    }
  inpa->no_arr++;


  init_arr_line (inpa, inpa->arr_line);
  A4GL_idraw_arr_all (inpa);
}

static void
delete_line_in_array (struct s_inp_arr *inpa)
{
  int a;
  char *src_ptr;
  char *dest_ptr;
  A4GL_debug ("delete_line_in_array no_arr=%d arr_size=%d arr_line=%d",
	      inpa->no_arr, inpa->arr_size, inpa->arr_line);
  if (inpa->no_arr)
    {
      for (a = inpa->arr_line; a <= inpa->no_arr; a++)
	{
	  src_ptr = (char *) inpa->binding[0].ptr + inpa->arr_elemsize * (a);
	  dest_ptr =
	    (char *) inpa->binding[0].ptr + inpa->arr_elemsize * (a - 1);
	  memcpy (dest_ptr, src_ptr, inpa->arr_elemsize);
	}
      init_arr_line (inpa, inpa->no_arr);
      inpa->no_arr--;
    }
  else
    {
      init_arr_line (inpa, 1);
      inpa->no_arr = 1;
      inpa->arr_line = 1;
    }


  A4GL_idraw_arr_all (inpa);
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
      A4GL_assertion (1 == 1, "I didn't think type was ever <0");
      type = 0 - type;
      fonly = 1;
    }

  A4GL_debug ("*** no=%d inpa->no_arr=%d\n", no, inpa->no_arr);

  topline = inpa->arr_line - inpa->scr_line + 1;
  scr_line = no - topline + 1;

  if (scr_line > inpa->scr_dim)
    {
      A4GL_debug ("scr line out of range %d %d\n", scr_line, inpa->scr_dim);
      return;
    }


  if (scr_line < 0)
    {
      A4GL_debug ("scr line out of range <0 %d", scr_line);
      return;
    }

  if (no > inpa->no_arr)
    {
      A4GL_debug ("arr no out of range %d %d\n", scr_line, inpa->scr_dim);
      A4GL_iarr_arr_fields (inpa, inpa->display_attrib, 0, scr_line, 1);
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


  A4GL_iarr_arr_fields (inpa, inpa->display_attrib, no, scr_line, 0);
}

/**
 *
 *
 * @param
 */
static void
iclear_srec (struct struct_screen_record *srec, struct s_inp_arr *inpa)
{
  int b;

  for (b = 0; b < inpa->scr_dim; b++)
    {
      A4GL_iarr_arr_fields (inpa, inpa->display_attrib, 0, b + 1, 1);
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
  for (a = 0; a < inpa->scr_dim; a++)
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


  A4GL_debug ("In pop_iarr_var %d %d currentfield=%p", x, y,
	      form->currentfield);
  if (form->currentfield == 0)
    return 1;
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

  //m_lastkey = 0;
#ifdef DEBUG
  {
    A4GL_debug ("Currform=%p (s_form_dets)", form);
  }
#endif
  if (form != A4GL_get_curr_form (1))
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
      if (form->currentfield != arr->field_list[arr->scr_line - 1][arr->curr_attrib])
	{
	  form->currentfield = arr->field_list[arr->scr_line - 1][arr->curr_attrib];
	}
      A4GL_mja_set_current_field (mform, form->currentfield);
      A4GL_mja_pos_form_cursor (mform);
      abort_pressed = 0;
      a = A4GL_getch_win ();
      if (abort_pressed)
	{
	  a = -1;
	  //fprintf (stderr, "ABORT\n");
	  //fflush (stderr);
	}
	A4GL_debug("calling set_last_key : %d",a);
	A4GL_set_last_key(a);
      //m_lastkey = a;
    }



  reinpa = 0;

  if (a != 10)
    {
      struct struct_scr_field *fprop;

      A4GL_debug ("Getting fprop");
      fprop =
	(struct struct_scr_field *) (field_userptr (form->currentfield));
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


  A4GL_add_to_control_stack (arr, FORMCONTROL_KEY_PRESS, 0, 0, a);
  return -1;
}


static void process_key_press(struct s_inp_arr *arr,int a) {
  struct s_form_dets *form;
  FORM *mform;

  form = arr->currform;
  mform = form->form;
  A4GL_debug("In process_key_press : %d",a);




  if (a == A4GL_key_val ("ACCEPT"))
    {
      a = 27;
    }

  if (a == A4GL_key_val ("NEXT"))
    {
      a = A4GLKEY_PGDN;
    }

  if (a == A4GL_key_val ("PREV"))
    {
      a = A4GLKEY_PGUP;
    }

  if (a == A4GL_key_val ("INSERT"))
    {
      if (arr->allow_insert)
	{
	  if (arr->no_arr < arr->arr_size)
	    {
	      a = A4GLKEY_INS;
	    }
	  else
	    {
	      A4GL_debug ("Insert disabled - too many rows");
	    }
	}
    }

  if (a == A4GL_key_val ("DELETE"))
    {
      if (arr->allow_insert)
	a = A4GLKEY_DEL;
    }


  switch (a)
    {

    case 127:
    case 8:
    case A4GLKEY_DC:
    case A4GLKEY_DL:
    case A4GLKEY_BACKSPACE:
        A4GL_int_form_driver (mform, REQ_DEL_PREV);break;

    case 4:                     // Control - D
        A4GL_int_form_driver (mform, REQ_CLR_EOF);break;

    case 1:                     // Control - A
      form->form_details.insmode = form->form_details.insmode ? 0 : 1;

      if (form->form_details.insmode) {
        A4GL_int_form_driver (mform, REQ_INS_MODE);break;
        }
      else {
        A4GL_int_form_driver (mform, REQ_OVL_MODE);break;
        }

    case A4GLKEY_PGDN:
      A4GL_newMovement (arr,
			arr->scr_line,
			arr->arr_line + arr->scr_dim, arr->curr_attrib);
      break;

    case A4GLKEY_PGUP:
      A4GL_newMovement (arr,
			arr->scr_line,
			arr->arr_line - arr->scr_dim, arr->curr_attrib);
      break;



    case A4GLKEY_DOWN:
      A4GL_newMovement (arr,
			arr->scr_line + 1, arr->arr_line + 1,
			arr->curr_attrib);

      break;


    case A4GLKEY_RIGHT:
      A4GL_debug ("Key_right");
      A4GL_int_form_driver (mform, REQ_NEXT_CHAR);
      break;

    case A4GLKEY_LEFT:


  if (a == A4GLKEY_LEFT && mform->curcol == 0 && mform->currow == 0)
    {
      A4GL_newMovement (arr, arr->scr_line, arr->arr_line, arr->curr_attrib - 1);
    } else {
      A4GL_int_form_driver (mform, REQ_PREV_CHAR);
    }
      break;


    case A4GLKEY_INS:
      A4GL_add_to_control_stack (arr, FORMCONTROL_AFTER_INSERT,
				 arr->currentfield, 0, 0);
      A4GL_add_to_control_stack (arr, FORMCONTROL_BEFORE_INSERT,
				 arr->currentfield, 0, 0);
      break;

    case A4GLKEY_DEL:
      A4GL_add_to_control_stack (arr, FORMCONTROL_AFTER_DELETE,
				 arr->currentfield, 0, 0);
      A4GL_add_to_control_stack (arr, FORMCONTROL_BEFORE_DELETE,
				 arr->currentfield, 0, 0);
      break;

    case 10:
    case 13:
    case '\t':
    case A4GLKEY_ENTER:
      A4GL_newMovement (arr, arr->scr_line, arr->arr_line,
			arr->curr_attrib + 1);

      break;

    //case A4GLKEY_BACKSPACE:
      //A4GL_newMovement (arr, arr->scr_line, arr->arr_line, //arr->curr_attrib - 1);
      //break;

    case A4GLKEY_UP:
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
  va_list *ptr;
  va_start (va, nv);
  ptr=&va;
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
int rval;
  //int a;

  struct s_inp_arr *inpa;
  inpa = (struct s_inp_arr *) vinpa;

  curr_arr_inp = inpa;
  A4GL_debug ("In A4GL_inp_arr : %s %p %p %d", srecname, defs, inpa, attrib);

  inpa->display_attrib = attrib;

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
      inpa->currform = A4GL_get_curr_form (1);

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

      if (inpa->count != -1)
	{
	  inpa->no_arr = inpa->count;
	  A4GL_set_arr_count (inpa->no_arr);
	}

      A4GL_debug ("********** no_arr=%d\n", inpa->no_arr);
      A4GL_debug ("********** nbind=%d\n", inpa->nbind);

      if (inpa->no_arr == 0)
	init_arr_line (inpa, 0);

      A4GL_set_arr_curr (inpa->arr_line);
      A4GL_set_scr_line (inpa->scr_line);


//set_fields_inp_arr(inpa);
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

      inpa->scr_dim = inpa->srec->dim;

      if (inpa->maxcount != -1)
	{
	  if (inpa->maxcount > inpa->arr_size)
	    {
	      A4GL_exitwith
		("MAXCOUNT out of range (<0 or > array record size)");
	      return 0;
	    }
	  inpa->arr_size = inpa->maxcount;
	}

      A4GL_debug ("Clearing Record");
      A4GL_debug ("Cleared record");

      fld_list =
	gen_srec_field_list (inpa->srec->name, inpa->currform,
			     inpa->srec->attribs.attribs_len + 1,
			     inpa->scr_dim);
      A4GL_debug ("All done...");
      inpa->field_list = (void ***) fld_list;
      A4GL_set_fields_inp_arr (inpa);

      iclear_srec (inpa->srec, inpa);

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
      inpa->last_scr_line = 1;
      inpa->last_arr_line = 1;
      A4GL_debug("inp_arr - returning -99  BEFORE INPUT....");
      return -99;
    }
  A4GL_debug ("inpaarr4");
  //ireinpalay_arr (inpa, 2);

  rval=iarr_loop (inpa);
  A4GL_debug("DEBUGGING BEFORE INPUT rval=%d",rval);

  return rval;
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
  for (a = 0; a < sio->scr_dim; a++)
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

  A4GL_debug ("add to control stack called with op=%d field=%p extent=%d", op, f, extent);

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
  sio->fcntrl[a].state = 99;
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
  sio->fcntrl_cnt = 0;
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

  if (arr_line < 1 ) 
    {
      // Attempt to move off the top program array...
	if (arr->last_scr_line>0) {
		A4GL_error_nobox (" There are no more rows in the direction you are going 1", 0);
      	} 
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


  if (scr_line > arr->scr_dim)
    {
      A4GL_debug ("Too far down in screen lines");
      scr_line = arr->scr_dim;
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
      static int dir = 0;
      A4GL_debug("Requested field is noentry");
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
	      A4GL_debug("Darn - next field is no entry too...");
	      attrib += dir;
	      if (attrib >= arr->srec->attribs.attribs_len)
		{
		  attrib = 0;
		  scr_line++;
		  arr_line++;
 			if (arr_line > arr->arr_size)
    			{				// Attempting to move off the bottom of the array...
				A4GL_debug("Too far down - should really error at this point");
				return;
			}
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

// Should already have been handled...
  //if (arr->fcntrl[a].op == FORMCONTROL_BEFORE_INPUT)
    //{
      //new_state = 0;
      //rval = -99;
    //}

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


      if (arr->fcntrl[a].state == 99)
	{
	  A4GL_add_to_control_stack (arr, FORMCONTROL_AFTER_FIELD,
				     arr->currentfield, 0, 0);
	  new_state = 50;
	  rval = -90;
	}


      if (arr->fcntrl[a].state == 50)
	{
	  new_state = 0;
	  A4GL_add_to_control_stack (arr, FORMCONTROL_AFTER_INPUT, 0, 0, 0);
	  rval = 0;
	}

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
      if (arr->fcntrl[a].state == 99)
	{
	  new_state = 50;
	  rval = -12;
	}

      if (arr->fcntrl[a].state == 50)
	{
	  // We want to do the actual delete here...
	  new_state = 0;
	  delete_line_in_array (arr);
	}

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
	  A4GL_set_arr_count (ptr_movement->arr_line);	// No new lines ...
	  init_arr_line (arr, ptr_movement->arr_line);
	  arr->no_arr++;
	}


      arr->scr_line = ptr_movement->scr_line;
      arr->arr_line = ptr_movement->arr_line;
      A4GL_set_arr_curr (ptr_movement->arr_line);
      A4GL_set_scr_line (ptr_movement->scr_line);
      A4GL_debug ("MJAMJA a=%d s=%d", ptr_movement->arr_line,
		  ptr_movement->scr_line);

      if (arr->scr_line != ptr_movement->scr_line);	// ireinpalay_arr (arr, 1);
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
      if (arr->fcntrl[a].state == 99)
	{			// BEFORE INSERT 
	  new_state = 50;
	  rval = -11;
	}


      if (arr->fcntrl[a].state == 50)
	{
	  // We want to do the actual insert here...
	  new_state = 0;
	  insert_line_in_array (arr);
	}
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
	  new_state = 25;
	  if (!A4GL_has_processed_onkey ())
	    {
		A4GL_debug("process_key_press");
	      	process_key_press(arr,arr->fcntrl[a].extent);
	    } else {
		A4GL_debug("No process_key_press - had an onkey");
	    }
	  rval=-1;
	}



      if (arr->fcntrl[a].state == 25)
	{
	  new_state = 0;

	      A4GL_debug ("Checking key state.. %d", arr->fcntrl[a].extent);
	      if (arr->fcntrl[a].extent >= 0 && arr->fcntrl[a].extent <= 255)
		{
          		struct struct_scr_field *fprop;


                fprop = (struct struct_scr_field *) (field_userptr (arr->currentfield));
                if (arr->fcntrl[a].extent>=0 && arr->fcntrl[a].extent<=255 && ( (isprint(arr->fcntrl[a].extent) || arr->fcntrl[a].extent==1 || arr->fcntrl[a].extent==4)) ) {

                        if ((fprop->flags & 1)==0)  {
                                        switch (arr->binding[arr->curr_attrib].dtype) {
                                        case DTYPE_SMINT:
                                        case DTYPE_INT:
                                        case DTYPE_FLOAT:
                                        case DTYPE_SMFLOAT:
                                        case DTYPE_DECIMAL:
                                        case DTYPE_MONEY:  A4GL_int_form_driver (arr->currform->form, REQ_CLR_EOF);
                                        }
                        }
                        A4GL_debug("SETTING FLAGS ");
                        fprop->flags|=2; // Set the field status flag
                }
		A4GL_int_form_driver (arr->currform->form, arr->fcntrl[a].extent);
		A4GL_int_form_driver (arr->currform->form, REQ_VALIDATION);
                fprop->flags|=1; // Clear the before field flag





		}
	}
    }


  if (arr->fcntrl[a].op == FORMCONTROL_BEFORE_FIELD)
    {
      struct struct_scr_field *fprop;
      int attr;

      if (arr->fcntrl[a].state == 99)
	{
	  new_state = 50;
	  ptr_movement = (struct s_movement *) arr->fcntrl[a].parameter;
	  A4GL_debug ("Movearray to %d,%d,%d", ptr_movement->scr_line,
		      ptr_movement->arr_line, ptr_movement->attrib_no);
	  arr->curr_attrib = ptr_movement->attrib_no;
	  arr->arr_line = ptr_movement->arr_line;
	  arr->scr_line = ptr_movement->scr_line;

	  arr->currentfield =
	    arr->field_list[arr->scr_line - 1][arr->curr_attrib];
	  A4GL_push_long ((long) arr->currentfield);
	  A4GL_push_char (arr->fcntrl[a].field_name);
	  rval = -197;
	}


      if (arr->fcntrl[a].state == 50)
	{
	  char *cptr;
	  arr->currentfield =
	    arr->field_list[arr->scr_line - 1][arr->curr_attrib];
	  set_current_field (arr->currform->form, arr->currentfield);
	  arr->currform->currentfield = arr->currentfield;
	  A4GL_debug ("Processed after users 'BEFORE FIELD'");

	  fprop =
	    (struct struct_scr_field *) (field_userptr (arr->currentfield));
	  attr =
	    A4GL_determine_attribute (FGL_CMD_INPUT, arr->display_attrib,
				      fprop);



	  if (arr->highlight)
	    {
	      if (attr & AUBIT_ATTR_REVERSE)
		attr = attr - AUBIT_ATTR_REVERSE;
	      else
		attr = attr + AUBIT_ATTR_REVERSE;
	    }

	  if (arr->curr_display)
	    {
	      A4GL_debug ("Got curr_display : %s\n", arr->curr_display);
	      attr = A4GL_get_attr_from_string (arr->curr_display);
	    }

	  if (attr != 0)
	    A4GL_set_field_attr_with_attr (arr->currentfield, attr,
					   FGL_CMD_INPUT);
	  cptr =
	    (char *) arr->binding[arr->curr_attrib].ptr +
	    arr->arr_elemsize * (arr->arr_line - 1);
	  A4GL_push_param (cptr,
			   arr->binding[arr->curr_attrib].dtype +
			   ENCODE_SIZE (arr->binding[arr->curr_attrib].size));



	  A4GL_display_field_contents (arr->currentfield,
				       arr->binding[arr->curr_attrib].dtype,
				       arr->binding[arr->curr_attrib].size,
				       cptr);

	  A4GL_comments (fprop);
	  pos_form_cursor (arr->currform->form);
	if ((fprop->flags & 1) ) fprop->flags-=1;
	  new_state = 0;
	}

    }


  if (arr->fcntrl[a].op == FORMCONTROL_AFTER_FIELD)
    {
      struct struct_scr_field *fprop;
      int attr;
      //int is_ok = 1;



      int ffc_rval;
      ffc_rval = A4GL_form_field_chk_iarr (arr, -1);


      A4GL_debug ("form_Field_chk returns %d\n", ffc_rval);


      if (ffc_rval != -4)
	{
	  //int field_no;
	  char buff[1024];
	  char *cptr;
	  //field_no=arr->curr_attrib;
	  new_state = 0;
	  strcpy (buff, field_buffer (arr->currentfield, 0));
	  A4GL_trim (buff);

	  if (strlen (buff))
	    {
	      A4GL_debug ("Field is not null");
	      A4GL_push_char (buff);
	    }
	  else
	    {
	      A4GL_debug ("Field is null");
	      A4GL_push_null (DTYPE_CHAR, 0);
	    }


	  pop_iarr_var (arr->currform, arr->curr_attrib, arr->arr_line,
			arr->arr_elemsize, arr->binding);
	  cptr =
	    (char *) arr->binding[arr->curr_attrib].ptr +
	    arr->arr_elemsize * (arr->arr_line - 1);

	  fprop =
	    (struct struct_scr_field *) (field_userptr (arr->currentfield));
	  attr =
	    A4GL_determine_attribute (FGL_CMD_INPUT, arr->display_attrib,
				      fprop);


	  if (arr->highlight)
	    {
	      if (attr & AUBIT_ATTR_REVERSE)
		attr = attr - AUBIT_ATTR_REVERSE;
	      else
		attr = attr + AUBIT_ATTR_REVERSE;
	    }

	  if (arr->curr_display)
	    {
	      A4GL_debug ("Got curr_display : %s\n", arr->curr_display);
	      attr = A4GL_get_attr_from_string (arr->curr_display);
	    }


	  if (attr != 0)
	    A4GL_set_field_attr_with_attr (arr->currentfield, attr,
					   FGL_CMD_INPUT);




	  A4GL_push_param (cptr,
			   arr->binding[arr->curr_attrib].dtype +
			   ENCODE_SIZE (arr->binding[arr->curr_attrib].size));
	  A4GL_display_field_contents (arr->currentfield,
				       arr->binding[arr->curr_attrib].dtype,
				       arr->binding[arr->curr_attrib].size,
				       cptr);
	  new_state = 0;
	  A4GL_push_long ((long) arr->currentfield);
	  A4GL_push_char (arr->fcntrl[a].field_name);
	  rval = -198;
	}
      else
	{
	  new_state = 0;
	  A4GL_init_control_stack (arr, 0);
	  rval = -1;
	  return -1;
	}






    }

  if (new_state != 0)
    {
      if (arr->fcntrl[a].state == new_state)
	{
	  A4GL_debug ("new_state=%d state=%d", new_state,
		      arr->fcntrl[a].state);
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






void
A4GL_iarr_arr_fields (struct s_inp_arr *arr, int attr, int arr_line,
		      int scr_line, int blank)
{
  int a;
  int flg;
  struct s_form_dets *formdets;
  char *cptr;
  char buff[256];
  int da;

  struct struct_scr_field *fprop;
  A4GL_debug ("In disp_fields");
  formdets = A4GL_get_curr_form (1);

  flg = 0;

  //if (fonly && nofields >= 0) nofields = 0;


  for (a = 0; a < arr->nbind; a++)
    {

      fprop =
	(struct struct_scr_field
	 *) (field_userptr (arr->field_list[scr_line - 1][a]));
      attr = A4GL_determine_attribute (FGL_CMD_INPUT, attr, fprop);
      da = attr;

      if (arr_line == arr->arr_line)
	{
      attr = A4GL_determine_attribute (FGL_CMD_INPUT, attr, fprop);
      da = attr;
	  if (arr->highlight)
	    {
	      if (da & AUBIT_ATTR_REVERSE)
		da = da - AUBIT_ATTR_REVERSE;
	      else
		da = da + AUBIT_ATTR_REVERSE;
	    }
	  if (arr->curr_display)
	    {
	      A4GL_debug ("Got curr_display : %s\n", arr->curr_display);
	      da = A4GL_get_attr_from_string (arr->curr_display);
	    }
	}

      if (attr != 0)
	A4GL_set_field_attr_with_attr (arr->field_list[scr_line - 1][a], da,
				       FGL_CMD_INPUT);

      if (!blank)
	{
	  cptr =
	    (char *) arr->binding[a].ptr + arr->arr_elemsize * (arr_line - 1);
	  A4GL_push_param (cptr,
			   arr->binding[a].dtype +
			   ENCODE_SIZE (arr->binding[a].size));
	}
      else
	{
	  strcpy (buff, "");
	  cptr = buff;
	  A4GL_push_null (DTYPE_CHAR, 1);
	  A4GL_setnull(arr->binding[a].dtype, cptr,arr->binding[a].size);
	}

      A4GL_display_field_contents (arr->field_list[scr_line - 1][a],
				   arr->binding[a].dtype,
				   arr->binding[a].size, cptr);

    }

}





int A4GL_req_field_input_array ( void *arrv, char type, va_list *ap) 
{
struct s_inp_arr *arr;
/* fieldname + = next - = previous */
  int a;
  FIELD **ptr;
char *colname;
arr=arrv;

  if (type=='+')
    {				// Next field next
      A4GL_init_control_stack (arr, 0);
      arr->currform->currentfield = 0;
      A4GL_newMovement (arr, arr->scr_line, arr->arr_line,
			arr->curr_attrib + 1);
      return 1;
    }

  if (type=='-')
    {				// Next field previous
      A4GL_init_control_stack (arr, 0);
      arr->currform->currentfield = 0;
      A4GL_newMovement (arr, arr->scr_line, arr->arr_line,
			arr->curr_attrib - 1);
      return 1;
    }


  A4GL_debug ("req_field");

  //a = A4GL_gen_field_list (&ptr, arr->currform, 1, ap);
  colname=va_arg(*ap,char *);

  A4GL_debug ("A=%d MJAMJA123", a);
  if (a >= 0)
    {
      for (a = 0; a < arr->nbind; a++)
	{

      if (A4GL_field_name_match (arr->field_list[arr->scr_line][a], colname))

	  //if (arr->field_list[arr->scr_line][a] == ptr[0])
	    {
	      A4GL_init_control_stack (arr, 0);


	      // How risky is this ?
	      arr->currform->currentfield = 0;


	      A4GL_newMovement (arr, arr->scr_line, arr->arr_line, a);
	      return 1;
	    }
	}
      A4GL_exitwith ("Field not found");
      return 0;
    }
  else
    {
      A4GL_exitwith ("Field not found");
      return 0;
    }
}
















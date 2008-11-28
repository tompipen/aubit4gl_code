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
# $Id: input_array.c,v 1.64 2008-11-04 13:20:06 mikeaubury Exp $
#*/
#ifndef lint
static char const module_id[] =
  "$Id: input_array.c,v 1.64 2008-11-04 13:20:06 mikeaubury Exp $";
#endif
/**
 * @file
 * Input array implementation
 *
 * @todo Add Doxygen comments to file
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/


#include "a4gl_lib_ui_int.h"
#include "hl_proto.h"
#include "a4gl_API_ui_lib.h"
#include "formdriver.h"
//#include "ui_highlevel.h"
#include "input_array.h"
#include "formcntrl.h"
#include "a4gl_API_lowlevel.h"

#include <ctype.h>
static
int UILIB_A4GL_inp_arr_v2_i (void *vinpa, int defs, char *srecname, int attrib, int init, void *vevt);

//int A4GL_has_event (int a, struct aclfgl_event_list *evt);
//int A4GL_has_event_for_keypress (int a, struct aclfgl_event_list *evt);
//int A4GL_has_event_for_field (int cat, char *a, struct aclfgl_event_list *evt);
//int A4GL_conversion_ok(int);

//void A4GL_set_field_attr_with_attr (void * field, int attr, int cmd_type);

//void A4GL_set_curr_infield (long a);
//void debug_print_flags (void *sv, char *txt);
//int A4GL_get_attr_from_string (char *s);

static int A4GL_double_chk_line(struct s_inp_arr *arr,int ln, char why) ;
static char *get_field_with_no_picture(void *f) ;
int last_field_pos=-1;
#define CONTROL_STACK_LENGTH 10

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

//extern int m_lastkey;
struct s_inp_arr *curr_arr_inp = 0;
//void A4GL_mja_set_current_field (void * form, void * field);
//int A4GL_form_field_chk_iarr (struct s_inp_arr *sio, int m);
//int UILIB_A4GL_req_field_input_array (struct s_inp_arr *arr,char typpe, va_list *ap) ;

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
//int A4GL_field_name_match (void *f, char *s);

static void init_arr_line (struct s_inp_arr *sio, int n);
static int process_control_stack (struct s_inp_arr *arr,
				  struct aclfgl_event_list *evt);
static int A4GL_has_something_on_control_stack (struct s_inp_arr *sio);

static void A4GL_add_to_control_stack (struct s_inp_arr *sio, enum e_formcontrol op,
				       void *f, char *parameter, int extent);

static void A4GL_newMovement_single (struct s_inp_arr *arr, int scr_line,
			      int arr_line, int attrib, char why);
static void A4GL_init_control_stack (struct s_inp_arr *sio, int malloc_data);

//static int A4GL_set_fields_inp_arr (void *vsio, int n);
/*
=====================================================================
                    Functions definitions
=====================================================================
*/




static void
do_key_move (char lr, struct s_inp_arr *arr, int a, int has_picture,
	     char *picture)
{
  struct s_form_dets *form;
  void *mform;
  int at_first = 0;
  int at_last = 0;

  form = arr->currform;
  mform = form->form;

  if (A4GL_LL_get_carat (mform) == 0)
    {
      at_first = 1;
    }
  if (A4GL_LL_get_carat (mform) == A4GL_get_field_width (A4GL_LL_current_field (mform)) - 1)
    {
      at_last = 1;
    }

  if (lr == 'R')
    {
      A4GL_debug ("Key_right");
      if (at_last)
	{
	  A4GL_newMovement_single (arr, arr->scr_line, arr->arr_line,
			    arr->curr_attrib + 1, 'R');
	  return;
	}
      else
	{
	  A4GL_LL_int_form_driver (mform, AUBIT_REQ_NEXT_CHAR);
	}

    }



  if (lr == 'L')
    {
      if (at_first)
	{
	  if (arr->curr_attrib)
	    {
	      A4GL_newMovement_single (arr, arr->scr_line, arr->arr_line,
				arr->curr_attrib - 1, 'L');
	      return;
	    }
	  else
	    {
	      A4GL_newMovement_single (arr, arr->scr_line - 1, arr->arr_line - 1, 0,
				'U');
	      return;
	    }
	}
      else
	{
	  A4GL_LL_int_form_driver (mform, AUBIT_REQ_PREV_CHAR);
	}
    }

  if (has_picture)
    {
      int newpos;
      void *mform;
      mform = arr->currform->form;
      newpos = A4GL_LL_get_carat (mform);
      if (strchr ("A#X", picture[newpos]))
	return;
      do_key_move (lr, arr, a, has_picture, picture);

    }



}


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
  //int topline;
  //int scr_line;

  A4GL_debug ("insert_line_in_array no_arr=%d arr_size=%d arr_line=%d",
	      inpa->no_arr, inpa->arr_size, inpa->arr_line);

  if (inpa->no_arr >= inpa->arr_size)
    {
      A4GL_debug ("Array too large");
      return;
    }

  for (a = inpa->no_arr + 1; a >= inpa->arr_line; a--)
    {
      src_ptr = (char *) inpa->binding[0].ptr + inpa->arr_elemsize * (a - 2);
      dest_ptr = (char *) inpa->binding[0].ptr + inpa->arr_elemsize * (a - 1);
      memcpy (dest_ptr, src_ptr, inpa->arr_elemsize);
    }
  inpa->no_arr++;
  A4GL_set_arr_count (inpa->no_arr);

  init_arr_line (inpa, inpa->arr_line);

  //topline = inpa->arr_line - inpa->scr_line + 1;

  //for (a = inpa->scr_line+1; a < inpa->scr_dim; a++)
  //{
  //A4GL_idraw_arr (inpa, a + topline == inpa->arr_line, a + topline);
  //}
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
	  dest_ptr = (char *) inpa->binding[0].ptr + inpa->arr_elemsize * (a - 1);
	  memcpy (dest_ptr, src_ptr, inpa->arr_elemsize);
	}
      init_arr_line (inpa, inpa->no_arr);
      inpa->no_arr--;
      A4GL_set_arr_count (inpa->no_arr);
    }
  else
    {
      init_arr_line (inpa, 1);
      inpa->no_arr = 1;
      inpa->arr_line = 1;
      A4GL_set_arr_count (inpa->no_arr);
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
	int nv;
      A4GL_debug ("calling set_arr_Fields");
	nv=inpa->nbind;
      if (inpa->start_slice!=-1 && inpa->end_slice!=-1) { nv=inpa->end_slice-inpa->start_slice+1; }
      A4GL_set_arr_fields (nv, 1, srec2, scr_line, 0, 0);
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
void
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
  A4GL_LL_screen_update ();
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


/**
 *
 *
 * @param
 */
static int
pop_iarr_var (struct s_form_dets *form, int x, int y, int elem,
	      struct BINDING *b)
{
  char buff[8000];
  int really_ok = 0;

  A4GL_debug ("In pop_iarr_var %d %d currentfield=%p", x, y,
	      form->currentfield);
  if (form->currentfield == 0)
    return 1;
  y--;


  if (A4GL_copy_field_data (form))
    {
      char *ptr;
      ptr = strdup (A4GL_LL_field_buffer (form->currentfield, 0));
      A4GL_trim (ptr);
      if (strlen (ptr))
	{
	  struct struct_scr_field *fprop;
	  char *ptr2;
	  fprop =
	    (struct struct_scr_field
	     *) (A4GL_ll_get_field_userptr (form->currentfield));

	  ptr2 = A4GL_fld_data_ignore_format (fprop, ptr);
	  if (ptr2 != ptr)
	    {
	      free (ptr);
	      ptr = strdup (ptr2);
	    }
	  A4GL_push_char (ptr);
	}
      else
	{
	  A4GL_push_null (b[x].dtype, b[x].size);
	}
      A4GL_debug ("Pushed field buffer :'%s'", ptr);
      strcpy (buff, A4GL_LL_field_buffer (form->currentfield, 0));
      A4GL_trim (buff);

      really_ok = 1;
      A4GL_pop_var2 ((char *) b[x].ptr + (y * elem), b[x].dtype, b[x].size);
      if (strlen (buff) && A4GL_isnull (b[x].dtype, b[x].ptr + (y * elem)))
	{
	  A4GL_debug ("Looks null");
	  really_ok = 0;
	}

      if (!A4GL_conversion_ok (-1))
	{
	  A4GL_debug ("Looks like a bad conversion");
	  really_ok = 0;
	}

      if ((b[x].dtype == DTYPE_INT || b[x].dtype == DTYPE_SMINT
	   || b[x].dtype == DTYPE_SERIAL) && strchr (buff, A4GL_get_convfmts()->ui_decfmt.decsep))
	{
	  A4GL_debug ("Looks like its got a decimal separator in it");
	  really_ok = 0;
	}



      free (ptr);
      A4GL_debug ("Popped field buffer into variable");
      if (really_ok == 0)
	{
	  A4GL_error_nobox (acl_getenv ("FIELD_ERROR_MSG"), 0);
	  if (A4GL_isyes (acl_getenv ("A4GL_CLR_FIELD_ON_ERROR")))
	    {
	      A4GL_clr_field (form->currentfield);
	    }
	  else
	    {
	      if (A4GL_isyes (acl_getenv ("FIRSTCOL_ONERR")))
		{
		  A4GL_LL_int_form_driver (form->form, AUBIT_REQ_BEG_FIELD);
		}
	    }
	  A4GL_LL_set_current_field (form->form, form->currentfield);
	  return 0;
	}
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
iarr_loop (struct s_inp_arr *arr, struct aclfgl_event_list *evt)
{
  struct s_form_dets *form;
  int a;
  int reinpa;
  void *mform;
  struct struct_scr_field *fprop;

//int iloop_action;     // What am I proposing to do ?
//#define ILOOP_ACTION_MOVEFIELD
//#define ILOOP_ACTION_MOVELINE
//#define ILOOP_KEYPRESS

  //int iloop_extent;   // How much am i proposing to do it ?
  //void *iloop_context[3];  // What am i doing it do ?


  arr->scr_dim = arr->srec->dim;
  if (curr_arr_inp != arr || curr_arr_inp)
    {
      A4GL_debug ("DO THEM AGAIN...");
      A4GL_set_fields_inp_arr (arr, 1);
    }
  curr_arr_inp = arr;
  form = arr->currform;
  A4GL_set_array_mode ('I');

  //m_lastkey = 0;
#ifdef DEBUG
  {
    A4GL_debug ("Currform=%p (s_form_dets)", form);
  }
#endif
  if (form != UILIB_A4GL_get_curr_form (0))
    {

      A4GL_make_window_with_this_form_current (form);
    }

  if (form != UILIB_A4GL_get_curr_form (1))
    {
      A4GL_exitwith ("Input form is not the current form!");
      exit (0);
    }
  mform = form->form;


  A4GL_idraw_arr (arr, 2, arr->arr_line); ///<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<





  if (A4GL_has_something_on_control_stack (arr))
    {
      int rval;
      rval = process_control_stack (arr, evt);
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

      fprop =
	(struct struct_scr_field
	 *) (A4GL_ll_get_field_userptr (form->currentfield));
      if (fprop)
	A4GL_comments (fprop);

      A4GL_mja_set_current_field (mform, form->currentfield);

      //A4GL_LL_set_carat (mform);
      //A4GL_LL_screen_update();
      abort_pressed = 0;
      while (1)
	{
	  int blk;
	  blk = A4GL_has_evt_timeout (evt);
	  if (blk)
	    {
	      return blk;
	    }
	  a = A4GL_getch_win (1,"input array");

              if (a==A4GLKEY_EVENT) {
		                      A4GL_debug("input array fired event...");
				                      A4GL_evt_not_idle(evt);
						                      return A4GL_LL_get_triggered_event();
								                      }


	  if (a != 0 && a != -1)
	    {
	      A4GL_evt_not_idle (evt);
	      break;
	    }
	  if (abort_pressed)
	    break;
	}


      if (A4GL_is_special_key (a, A4GLKEY_ACCEPT))
	a = A4GLKEY_ACCEPT;
      if (A4GL_is_special_key (a, A4GLKEY_INSERT))
	a = A4GLKEY_INSERT;
      if (A4GL_is_special_key (a, A4GLKEY_DELETE))
	a = A4GLKEY_DELETE;
      if (A4GL_is_special_key (a, A4GLKEY_NEXT))
	a = A4GLKEY_NEXT;
      if (A4GL_is_special_key (a, A4GLKEY_PREV))
	a = A4GLKEY_PREV;


      if (a==A4GLKEY_EVENT) {
	            int rval;
		              rval=A4GL_LL_get_triggered_event();
			                return rval;
					  }


      arr->processed_onkey = a;
      if (abort_pressed)
	{
	  a = A4GLKEY_INTERRUPT;
	}
      A4GL_debug ("calling set_last_key : %d", a);
      A4GL_set_last_key (a);
    }



  reinpa = 0;

  if (a != 10)
    {
      struct struct_scr_field *fprop;

      A4GL_debug ("Getting fprop");
      fprop =
	(struct struct_scr_field
	 *) (A4GL_ll_get_field_userptr (form->currentfield));
      if (fprop != 0)
	{
	  A4GL_debug ("Downshift?");
	  if (A4GL_has_bool_attribute (fprop, FA_B_DOWNSHIFT)
	      && a4gl_isupper (a) && a4gl_isalpha (a))
	    {
	      a = a4gl_tolower (a);
	    }
	  A4GL_debug ("Upshift ?");
	  if (A4GL_has_bool_attribute (fprop, FA_B_UPSHIFT)
	      && a4gl_islower (a) && a4gl_isalpha (a))
	    {
	      a = a4gl_toupper (a);
	    }
	}
    }


  A4GL_add_to_control_stack (arr, FORMCONTROL_KEY_PRESS, 0, 0, a);
  return -1;
}


static void
process_key_press (struct s_inp_arr *arr, int a)
{
  struct s_form_dets *form;
  void *mform;
  int at_first = 0;
  int at_last = 0;
  int act_as;

  form = arr->currform;
  mform = form->form;

  A4GL_debug ("process_key_press inp_arr %d", a);
  if (A4GL_LL_get_carat (mform) == 0)
    {
      at_first = 1;
    }
  if (A4GL_LL_get_carat (mform) ==
      A4GL_get_field_width (A4GL_LL_current_field (mform)) - 1)
    {
      at_last = 1;
    }

  A4GL_debug ("In process_key_press : %d", a);

  act_as = a;


    if (A4GL_is_special_key (a, A4GLKEY_ACCEPT))
    {
      act_as = -99;
    }

  if (A4GL_is_special_key (a, A4GLKEY_NEXT))
    {
      act_as = A4GLKEY_PGDN;
      a = act_as;
    }

   if (A4GL_is_special_key (a, A4GLKEY_PREV))
    {
      act_as = A4GLKEY_PGUP;
      a = act_as;
    }

    if (A4GL_is_special_key (a, A4GLKEY_INSERT))
    {
	    A4GL_debug("INSERT KEY!!!");
      if (arr->allow_insert)
	{
	  if (arr->no_arr < arr->arr_size)
	    {
	      act_as = A4GLKEY_INS;
	      a = act_as;
	    }
	  else
	    {
	      A4GL_debug ("Insert disabled - too many rows");
	      A4GL_error_nobox (acl_getenv ("INPARRAY_FULL_MSG"), 0);
	    }
	}
    }

      if (A4GL_is_special_key (a, A4GLKEY_DELETE))
    {
      if (arr->allow_insert)
	{
	  act_as = A4GLKEY_DEL;
	  a = act_as;
	}
    }


  switch (act_as)
    {

    case 127:
    case 8:
    case A4GLKEY_DL:
    case A4GLKEY_BACKSPACE:
	    if (arr->curr_line_is_new==1) { arr->curr_line_is_new=2; }
		A4GL_fprop_flag_set(arr->currentfield, FLAG_FIELD_TOUCHED);
      A4GL_LL_int_form_driver (mform, AUBIT_REQ_DEL_PREV);
      break;


    case 18:
      A4GL_LL_screen_redraw ();
      break;

    case 4:			// Control - D
      A4GL_debug ("MMMM - Clear EOF ^d");
      if (arr->curr_line_is_new==1) { arr->curr_line_is_new=2; }

		A4GL_fprop_flag_set(arr->currentfield, FLAG_FIELD_TOUCHED);
      A4GL_LL_int_form_driver (mform, AUBIT_REQ_CLR_EOF);
      break;

    case A4GLKEY_DC:
    case 24:			// Control - D
      A4GL_debug ("MMMM - del");
      if (arr->curr_line_is_new==1) { arr->curr_line_is_new=2; }

      A4GL_LL_int_form_driver (mform, AUBIT_REQ_DEL_CHAR);
		A4GL_fprop_flag_set(arr->currentfield, FLAG_FIELD_TOUCHED);
      break;

    case 1:			// Control - A
      form->form_details.insmode = form->form_details.insmode ? 0 : 1;

      if (form->form_details.insmode)
	{
	  A4GL_LL_int_form_driver (mform, AUBIT_REQ_INS_MODE);
	  break;
	}
      else
	{
	  A4GL_LL_int_form_driver (mform, AUBIT_REQ_OVL_MODE);
	  break;
	}

    case A4GLKEY_SHTAB:
      if (arr->curr_attrib)
	{
	  A4GL_newMovement_single (arr, arr->scr_line, arr->arr_line,
			    arr->curr_attrib - 1, 'L');
	}
      else
	{
	  A4GL_newMovement_single (arr, arr->scr_line - 1, arr->arr_line - 1, 0,
			    'L');
	}
      break;

    case A4GLKEY_PGDN:
      if (arr->arr_line + arr->scr_dim <= arr->arr_size)
        {
        A4GL_debug("Calling newmovement PGDN %d %d %d",arr->arr_line, arr->scr_dim, arr->no_arr);

          if (arr->arr_line+ arr->scr_dim> arr->no_arr ) {
                if (arr->arr_line+ arr->scr_dim > arr->no_arr+1) {
                        /* ... */
                        A4GL_error_nobox (acl_getenv("ARR_DIR_MSG"), 0);
                } else {
                        A4GL_debug("A");
                        if (arr->allow_insert) {
                                A4GL_debug("allow_insert");
                                A4GL_newMovement_single (arr, arr->scr_line, arr->no_arr+1, arr->curr_attrib, 'D');
                        } else {
                                A4GL_error_nobox (acl_getenv("ARR_DIR_MSG"), 0);
                        }
                }
          } else {
                        A4GL_debug("nm1");
                A4GL_newMovement_single (arr, arr->scr_line, arr->arr_line + arr->scr_dim, arr->curr_attrib, 'D');
          }
        }
      else
        {
          int d;
        A4GL_debug("XX");
          d = arr->arr_size - arr->arr_line;
          if (d>arr->no_arr) {
                if (arr->allow_insert) {
                        A4GL_newMovement_single (arr, arr->scr_dim, arr->no_arr+1, arr->curr_attrib, 'D');
                } else {
                        A4GL_error_nobox (acl_getenv("ARR_DIR_MSG"), 0);
                }
          } else {
                        A4GL_error_nobox (acl_getenv("ARR_DIR_MSG"), 0);
          }
        }

      break;

    case A4GLKEY_PGUP:
      if (arr->arr_line - arr->scr_dim >= 1)
	{
	  A4GL_newMovement_single (arr,
			    arr->scr_line,
			    arr->arr_line - arr->scr_dim, arr->curr_attrib,
			    'U');
	}
      else
	{
	  A4GL_newMovement_single (arr, 1, 1, arr->curr_attrib, 'U');

	}
      break;



    case A4GLKEY_DOWN:
	  if (arr->arr_line >= arr->no_arr) 
	{
        A4GL_debug ("Key_down -> insert new line");
      	A4GL_newMovement_single (arr,
			arr->scr_line + 1, arr->arr_line + 1,
			0, 'D');
	}
      else
	{
        A4GL_debug ("Key_down -> existing data");
      	A4GL_newMovement_single (arr,
			arr->scr_line + 1, arr->arr_line + 1,
			arr->curr_attrib, 'D');
	}

      break;


    case A4GLKEY_RIGHT:
      A4GL_debug ("Key_right");
      if (at_last)
	{
	  A4GL_newMovement_single (arr,
			    arr->scr_line, arr->arr_line,
			    arr->curr_attrib + 1, 'R');
	}
      else
	{
	  A4GL_LL_int_form_driver (mform, AUBIT_REQ_NEXT_CHAR);
	}
      break;



    case A4GLKEY_HOME:
                A4GL_LL_int_form_driver (mform, AUBIT_REQ_BEG_FIELD);
                          break;
                              case A4GLKEY_END:
                                    A4GL_LL_int_form_driver (mform, AUBIT_REQ_END_FIELD);
                                              break;


    case A4GLKEY_LEFT:
      if (at_first)
	{
	  if (arr->curr_attrib)
	    {
	      A4GL_newMovement_single (arr, arr->scr_line, arr->arr_line,
				arr->curr_attrib - 1, 'L');
	    }
	  else
	    {
	      A4GL_newMovement_single (arr, arr->scr_line - 1, arr->arr_line - 1, 0,
				'U');
	    }
	}
      else
	{
	  A4GL_LL_int_form_driver (mform, AUBIT_REQ_PREV_CHAR);
	}
      break;


    case A4GLKEY_INS:


      /* A4GL_add_to_control_stack (arr, FORMCONTROL_BEFORE_INSERT, arr->currentfield, 0, 0); */
      {
	void *f;
                struct s_movement ptr;
                //int x_sz;

                ptr.scr_line = arr->scr_line;
                ptr.arr_line = arr->arr_line;
                ptr.attrib_no = 0; //arr->curr_attrib;

	f = arr->field_list[arr->scr_line - 1][arr->curr_attrib];
        A4GL_add_to_control_stack (arr, FORMCONTROL_BEFORE_FIELD, f, A4GL_memdup (&ptr, sizeof (struct s_movement)),0);
        A4GL_add_to_control_stack (arr, FORMCONTROL_BEFORE_INSERT, arr->currentfield, 0, 0);

	A4GL_add_to_control_stack (arr, FORMCONTROL_AFTER_ROW, f, 0, 0);
	A4GL_add_to_control_stack (arr, FORMCONTROL_AFTER_FIELD, f, 0, 0);
      }

	//A4GL_newMovement_single (arr, arr->scr_line, arr->arr_line, 0, 'D');

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
      //case A4GLKEY_ENTER:
      A4GL_newMovement_single (arr, arr->scr_line, arr->arr_line,
			arr->curr_attrib + 1, 'R');

      break;

      //case A4GLKEY_BACKSPACE:
      //A4GL_newMovement_single (arr, arr->scr_line, arr->arr_line, //arr->curr_attrib - 1);
      //break;

    case A4GLKEY_UP:
      if (arr->curr_line_is_new==1)
	  {
          A4GL_debug ("KEY_UP in a new blank line, like key_del ??");
          // init_arr_line (arr, arr->no_arr);
          // arr->no_arr--;
          // A4GL_set_arr_count (arr->no_arr);
	  }
      A4GL_newMovement_single (arr,
			arr->scr_line - 1, arr->arr_line - 1,
			arr->curr_attrib, 'U');
      break;

    case -99:
      A4GL_debug ("ACCEPT DETECTED");
      A4GL_add_to_control_stack (arr, FORMCONTROL_EXIT_INPUT_OK, 0, 0, a);
      break;

    case A4GLKEY_INTERRUPT:
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
  ptr = &va;
  return A4GL_gen_field_list (a, b, nv, &va,0);
}

/**
 *
 *
 * @param
 */
static void ***
gen_srec_field_list (char *s, struct s_form_dets *form, int a, int d)
{
  void ***fld_list;
  int fc;
  int lc;
  char buff[64];
  A4GL_debug ("Generating field list for screen array a=%d d=%d", a, d);

  fld_list = (void ***) calloc (d, sizeof (void **));

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


int
UILIB_A4GL_inp_arr_v2 (void *vinpa, int defs, char *srecname, int attrib,
		       int init, void *vevt)
{

  struct s_inp_arr *inpa;
  if (init && defs == 0)
    {
      int n;
      int count;
      // We should initialize our array variables to null...
      // up to and the setcount value anyway...
      inpa = vinpa;
      count = A4GL_get_count ();

      if (count >= inpa->arr_size)
	{
	  count = inpa->arr_size;
	}
      for (n = 1; n <= count; n++)
	{
	  init_arr_line (vinpa, n);
	}
      inpa->no_arr = 0;
      A4GL_set_arr_count (0);
    }


  A4GL_debug ("inp_arr_v2 ... zz9pa");
  while (1)
    {
      int a;
      a = UILIB_A4GL_inp_arr_v2_i (vinpa, defs, srecname, attrib, init, vevt);
      if (a != -1)
	{
	  A4GL_debug ("returing %d zz9pa", a);
	  return a;
	}
    }

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
int UILIB_A4GL_inp_arr_v2_i (void *vinpa, int defs, char *srecname, int attrib, int init, void *vevt)
{
  void ***fld_list;
  int rval;
  struct aclfgl_event_list *evt;
int nv;
  //int blk;
  struct s_inp_arr *inpa;
  evt = vevt;
  //int a;
  //
  
  ActivateToolbar("InputArray",vevt,vinpa);

  inpa = (struct s_inp_arr *) vinpa;

  if (curr_arr_inp && curr_arr_inp != inpa)
    {
      A4GL_debug ("DO THEM AGAIN...");
      A4GL_set_fields_inp_arr (inpa, 0);
    }
  curr_arr_inp = inpa;
  A4GL_debug ("In UILIB_A4GL_inp_arr : %s %p %p %d", srecname, defs, inpa,
	      attrib);

  inpa->display_attrib = attrib;

  if (inpa->srec == 0)
    {
      A4GL_debug ("inpaarr1");
      inpa->srec = A4GL_get_srec (srecname);

      A4GL_debug (">>>>inpa->srec=%p", inpa->srec);

      if (inpa->srec == 0)
	{
	  A4GL_exitwith ("Screen record not found");
  	ActivateToolbar(0,0,0);
	  return 0;
	}
      inpa->currform = UILIB_A4GL_get_curr_form (1);

      A4GL_debug ("Init control stack");
      A4GL_init_control_stack (inpa, 1);
      A4GL_clr_evt_timeouts (evt);
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

      if (inpa->no_arr == 0) {
	init_arr_line (inpa, 1);

      }
      A4GL_set_arr_curr (inpa->arr_line);
      A4GL_set_scr_line (inpa->scr_line);


//set_fields_inp_arr(inpa);
      A4GL_debug ("inpaarr2");
      if (inpa->srec == 0)

	{

	  A4GL_debug ("Screen record does not exist");

  	ActivateToolbar(0,0,0);
	  return 0;

	}
      A4GL_debug ("inpaarr3");
	nv=inpa->nbind;

	if (inpa->start_slice!=-1 ) {
		nv=inpa->end_slice-inpa->start_slice+1;
	}

      if (inpa->srec->attribs.attribs_len != nv)

	{

	  A4GL_debug ("Too many or too few variables for fields %d %d", inpa->srec->dim, nv);
		A4GL_exitwith("Too many or too few variables for fields");
  	ActivateToolbar(0,0,0);
	  return 0;

	}

      inpa->scr_dim = inpa->srec->dim;

      if (inpa->maxcount != -1)
	{
	  if (inpa->maxcount > inpa->arr_size)
	    {
	      A4GL_exitwith
		("MAXCOUNT out of range (<0 or > array record size)");
  	ActivateToolbar(0,0,0);
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
      A4GL_set_fields_inp_arr (inpa, 2);

      iclear_srec (inpa->srec, inpa);

      A4GL_idraw_arr (inpa, 1, inpa->arr_line);

      //A4GL_gui_scroll (inpa->no_arr);
      inpa->last_scr_line = -1;
      inpa->last_arr_line = -1;
      //set_arr_curr (inpa->arr_line);
      //set_scr_line (inpa->scr_line);


      A4GL_set_arr_count (inpa->no_arr);

      inpa->curr_attrib = 0;
      //debug("MJAMJA setting current field = %p",inpa->field_list[inpa->scr_line - 1][inpa->curr_attrib]);
      A4GL_newMovement_single (inpa, 0, 0, 0, 'R');

      inpa->last_scr_line = -1;
      inpa->last_arr_line = -1;

      A4GL_idraw_arr_all (inpa);
      A4GL_LL_screen_update ();
      inpa->last_scr_line = 1;
      inpa->last_arr_line = 1;
      A4GL_debug ("inp_arr - returning -99  BEFORE INPUT....");
      if (A4GL_has_event (A4GL_EVENT_BEFORE_INP, evt))
	return A4GL_has_event (A4GL_EVENT_BEFORE_INP, evt);
  	ActivateToolbar(0,0,0);
      return -1;
    }
  A4GL_debug ("inpaarr4");

  rval = iarr_loop (inpa, evt);
  A4GL_debug ("DEBUGGING rval=%d", rval);
  if (rval < 0 && rval != -1)
    {
      A4GL_debug ("FIXME : rval : %d\n", rval);
    }

  	ActivateToolbar(0,0,0);
  return rval;
}


/* this is used by the fgl_set_scrline function */
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
  {
    A4GL_debug ("Set scrline...%d", a);
  }
#endif
  return 0;
}


/* this is used by the fgl_set_arrline function */
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
  {
    A4GL_debug ("Set arrline... %d", a);
  }
#endif
  return 0;
}


/**
 * Not used
 *
 * @todo Confirm if its not used and deleted if so
 */


/* This function disables all fields except those used in the 
* input array itself
*/
int
A4GL_set_fields_inp_arr (void *vsio, int n)
{
  int wid;
  int a, b;
  int nv;
  int flg;
  struct s_form_dets *formdets;
  struct struct_scr_field *field;
  //struct struct_scr_field *prop;
  void **field_list;
  void *firstfield = 0;
  int nofields;
  struct s_inp_arr *sio;
  sio = vsio;


  wid = 1;
  A4GL_debug ("in set fields");
  formdets = sio->currform;
  A4GL_debug ("set fdets");

  flg = 0;

  A4GL_debug ("Turning off all");

  field_list = formdets->form_fields;

  for (a = 0; field_list[a]; a++)
    {
      field =
	(struct struct_scr_field
	 *) (A4GL_ll_get_field_userptr (formdets->form_fields[a]));

      if (field == 0)
	continue;


      if (A4GL_turn_field_off (formdets->form_fields[a]))
	{
	  firstfield = formdets->form_fields[a];
	}
    }

  nofields = sio->nfields;
  field_list = (void **) sio->field_list;

  A4GL_debug ("Field list=%p number of fields = %d", field_list, nofields);

  nv = sio->nbind;
  if (sio->start_slice!=-1) {
		nv=sio->end_slice-sio->start_slice+1;
  }

  if (nofields != nv - 1)
    {
      A4GL_debug
	("Number of fields (%d) is not the same as the number of vars (%d)",
	 nofields + 1, nv);
      A4GL_exitwith
	("Number of fields is not the same as the number of variables");
      return 0;
    }


  A4GL_debug ("turning some back on : %p %d", sio, sio->scr_dim);



  for (a = 0; a < sio->scr_dim; a++)
    {
      for (b = 0; b < sio->srec->attribs.attribs_len; b++)
	{
	  //A4GL_debug ("MJAMJA Turn on field : %p", sio->field_list[a][b]);
	  if (n == 1)
	    {
              A4GL_debug ("turning some back on : %p %p %d - O_ACTIVE", sio->field_list[a][b],sio, sio->scr_dim);
	      A4GL_field_opts_on (sio->field_list[a][b], AUBIT_O_ACTIVE);
              A4GL_debug ("turning some back on : %p %p %d - O_EDIT", sio->field_list[a][b],sio, sio->scr_dim);
	      A4GL_field_opts_on (sio->field_list[a][b], AUBIT_O_EDIT);
	    }
	  else
	    {

              A4GL_debug ("turning some back on : %p %p %d - ON2", sio->field_list[a][b],sio, sio->scr_dim);
	      A4GL_turn_field_on2 (sio->field_list[a][b], 1);
	    }
	  field =
	    (struct struct_scr_field
	     *) (A4GL_ll_get_field_userptr (sio->field_list[a][b]));

	  if (n == 2) {
		 A4GL_fprop_flag_clear(sio->field_list[a][b], 0xff); // ALL
	  }
	}
    }
  return 1;
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
  if (n<=0) {
          A4GL_assertion(1,"array element must be 1 or more");
  }

  if (sio->start_slice!=-1 && sio->end_slice!=-1) {
  for (a = sio->end_slice; a >= sio->start_slice; a--)
    {
      A4GL_debug ("b[a].dtype=%d", b[a].dtype);
      A4GL_setnull (b[a].dtype, (char *) b[a].ptr + sio->arr_elemsize * (n - 1), b[a].size);
    }
  } else {

  for (a = sio->nbind - 1; a >= 0; a--)
    {
      A4GL_debug ("b[a].dtype=%d", b[a].dtype);
      A4GL_setnull (b[a].dtype,
                    (char *) b[a].ptr + sio->arr_elemsize * (n - 1),
                    b[a].size);
    }
  }
}

/* 
* This function adds a value to the control stack
* this is read to determine when to call before/after fields etc
*
*/
static void
A4GL_add_to_control_stack (struct s_inp_arr *sio, enum e_formcontrol op, void *f,
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
      attr = (struct struct_scr_field *) A4GL_ll_get_field_userptr (f);
      field_name = attr->colname;
    }
  a = sio->fcntrl_cnt;
  sio->fcntrl[a].op = op;
  sio->fcntrl[a].parameter = parameter;
  sio->fcntrl[a].field = f;
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
      sio->fcntrl = acl_malloc2 (sizeof (struct s_formcontrol) * 10);
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
A4GL_newMovement_single (struct s_inp_arr *arr, int scr_line, int arr_line,
		  int attrib, char why)
{
  //struct s_movement *ptr;
  void *last_field = 0;
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
      if (arr->last_scr_line > 0)
	{
	  A4GL_error_nobox (acl_getenv ("ARR_DIR_MSG"), 0);
	}
      A4GL_newMovement_single (arr, scr_line, 1, attrib, why);
      return;
    }

  if (scr_line > arr_line)
    {
      scr_line = arr_line;
    }
  if (attrib < 0)
    {
      // attempt to move too far to the left
      // In informix - this results in just going up a line - still on field 0
      A4GL_debug ("Too far to the left");
      A4GL_newMovement_single (arr, scr_line, arr_line - 1, 0, why);
      return;
    }


  if (scr_line > arr->scr_dim)
    {
      A4GL_debug ("Too far down in screen lines");
      scr_line = arr->scr_dim;
      A4GL_newMovement_single (arr, scr_line, arr_line, attrib, why);
      return;
    }

  if (scr_line <= 0)
    {
      A4GL_debug ("Too far up in screen lines");
      scr_line = 1;
      A4GL_newMovement_single (arr, scr_line, arr_line, attrib, why);
      return;
    }

  if ((arr_line + 1) - scr_line < 0)
    {
      A4GL_debug ("scr lines too big for current line %d %d", scr_line,
		  arr_line);
      scr_line = arr_line - scr_line + 1;
      A4GL_newMovement_single (arr, scr_line, arr_line, attrib, why);
      return;
    }



  if (attrib >= arr->srec->attribs.attribs_len && attrib >= 0)
    {
      // Too far over to the right - wrap around to the start of the next line
      A4GL_debug ("Too far to the right");
      A4GL_newMovement_single (arr, scr_line + 1, arr_line + 1, 0, why);
      return;
    }



  if (arr_line > arr->arr_size)
    {				// Attempting to move off the bottom of the array...
      A4GL_debug ("Too far down the program array");
      A4GL_error_nobox (acl_getenv ("ARR_DIR_MSG"), 0);
      A4GL_newMovement_single (arr, arr->scr_line, arr->arr_size, arr->curr_attrib,
			why);
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
    //last_field = arr->field_list[arr->scr_line - 1][arr->curr_attrib];
    last_field = arr->currentfield;
  else
    last_field = 0;

  next_field = arr->field_list[scr_line - 1][attrib];
  f = (struct struct_scr_field *) (A4GL_ll_get_field_userptr (next_field));

  if (A4GL_has_bool_attribute (f, FA_B_NOENTRY)
      || (f->datatype == DTYPE_SERIAL))
    {
      A4GL_debug ("Requested field is noentry");
      while (1)
	{

	  A4GL_debug ("next_field= srec[%d %d]\n", scr_line, attrib);
	  next_field = arr->field_list[0][attrib];
	  A4GL_debug ("next_field = %p", next_field);
	  f =
	    (struct struct_scr_field
	     *) (A4GL_ll_get_field_userptr (next_field));
	  A4GL_debug ("fprop=%p", f);

	  if (A4GL_has_bool_attribute (f, FA_B_NOENTRY)
	      || (f->datatype == DTYPE_SERIAL))
	    {
	      A4GL_debug ("Darn - next field is no entry too...");
	      if (why == 'R' || why == 0 || why == 'D' || why=='Q')
		attrib++;
	      else
		attrib--;

	      if (attrib >= arr->srec->attribs.attribs_len && attrib >= 0)
		{
		  attrib = 0;
		  scr_line++;
		  arr_line++;
		  if (arr_line > arr->arr_size)
		    {		// Attempting to move off the bottom of the array...
		      A4GL_error_nobox (acl_getenv ("ARR_DIR_MSG"), 0);
		      A4GL_debug
			("Too far down - should really error at this point");
		      A4GL_newMovement_single (arr, scr_line - 1, arr_line - 1, 0,
					why);
		      return;
		    }
		}

	      if (attrib < 0)
		{
		  attrib = 0;	//arr->srec->attribs.attribs_len;
		  why = 0;
		  scr_line--;
		  arr_line--;
		}
	    }
	  else
	    {
	      A4GL_debug ("Found somewhere free...");
	      A4GL_newMovement_single (arr, scr_line, arr_line, attrib, why);	// So keep going...
	      return;
	    }
	}
    }


/*

  ptr = acl_malloc2 (sizeof (struct s_movement));
  ptr->scr_line = scr_line;
  ptr->arr_line = arr_line;
  ptr->attrib_no = attrib;
  */

  A4GL_debug ("iarr - adding entries to stack %d %d", arr_line,
	      arr->arr_line);

  if (arr_line != arr->arr_line)
    {
	          struct s_movement ptr;

        if (!A4GL_double_chk_line(arr,arr->scr_line-1, why)) { // somethings wrong with our current line
                return;
        }

		        ptr.scr_line = scr_line;
			      ptr.arr_line = arr_line;
			            ptr.attrib_no = attrib;

      A4GL_debug ("Bef1 - different array line");
      A4GL_add_to_control_stack (arr, FORMCONTROL_BEFORE_FIELD, next_field,
				 A4GL_memdup (&ptr,
					      sizeof (struct s_movement)), 0);




      A4GL_add_to_control_stack (arr, FORMCONTROL_BEFORE_ROW, next_field,
				 A4GL_memdup (&ptr,
					      sizeof (struct s_movement)), 0);

      A4GL_debug ("Add aftr controls ?  - %p", last_field);

      if (last_field || why=='Q')
	{


	  A4GL_add_to_control_stack (arr, FORMCONTROL_AFTER_ROW, last_field,
				     0, 0);
	  if (arr->curr_line_is_new) {
	    A4GL_add_to_control_stack (arr, FORMCONTROL_AFTER_INSERT,
				       last_field, 0, 0);
	  }
	  arr->curr_line_is_new = 0;
	  A4GL_debug ("Adding AFTER FIELD..");

	  if (last_field) {
	  	A4GL_add_to_control_stack (arr, FORMCONTROL_AFTER_FIELD, last_field,
				     0, 0);
	  }

	}
    }
  else
    {
	          struct s_movement ptr;
		          struct s_movement *ptr_x;
			          int x_sz;

		        ptr.scr_line = scr_line;
			      ptr.arr_line = arr_line;
			            ptr.attrib_no = attrib;


      x_sz=sizeof (struct s_movement);
            ptr_x=A4GL_memdup (&ptr,x_sz);

	          if (ptr.scr_line==scr_line&& ptr.arr_line==arr_line && ptr.attrib_no== attrib) {
			                  A4GL_debug("Moving to the same place ?");
					        }
		        A4GL_add_to_control_stack (arr, FORMCONTROL_BEFORE_FIELD, next_field, (void *)ptr_x,0);



			      A4GL_debug ("Adding AFTER FIELD ? %p", last_field);

			            if (last_field) {
					              A4GL_add_to_control_stack (arr, FORMCONTROL_AFTER_FIELD, last_field, 0, 0);
						              }
				        }



}



/* 
* process any waiting actions 
*
*/
static int
process_control_stack (struct s_inp_arr *arr, struct aclfgl_event_list *evt)
{
  int a;
  int rval;
  int new_state;
  struct s_movement *ptr_movement;
  int cnt;
int nv;

  rval = -1;
  new_state = 99;


  a = arr->fcntrl_cnt - 1;
  A4GL_debug ("a=%d op=%d HEF", a, arr->fcntrl[a].op);
// Should already have been handled...
  //if (arr->fcntrl[a].op == FORMCONTROL_BEFORE_INPUT)
  //{
  //new_state = 0;
  //rval = -99;
  //}

  if (arr->fcntrl[a].op == FORMCONTROL_AFTER_INPUT)
    {
      A4GL_debug ("AFTER INPUT ");
      A4GL_comments (0);
      if (arr->fcntrl[a].state == 99)
	{
	  A4GL_debug ("AFTER INPUT state 99");
	  new_state = 50;
	  A4GL_debug ("Calling after field..");
	  if (A4GL_has_event (A4GL_EVENT_AFTER_INP, evt))
	    rval = A4GL_has_event (A4GL_EVENT_AFTER_INP, evt);
	  else
	    rval = -1;
	}

      if (arr->fcntrl[a].state == 50)
	{
	  A4GL_comments (0);
	  A4GL_debug ("AFTER INPUT state 50");
	  new_state = 0;
	  if (A4GL_has_event (A4GL_EVENT_AFTER_INP_CLEAN, evt))
	    rval = A4GL_has_event (A4GL_EVENT_AFTER_INP_CLEAN, evt);
	  else
	    rval = -1;
	  A4GL_debug ("Calling all done..");
	}
    }


  if (arr->fcntrl[a].op == FORMCONTROL_EXIT_INPUT_OK)
    {

      A4GL_comments (0);

      if (arr->fcntrl[a].state == 99)
	{
	  if (arr->currentfield)
	    {
	      A4GL_debug ("Adding more..");
	      A4GL_add_to_control_stack (arr, FORMCONTROL_AFTER_ROW,
					 arr->currentfield, 0, 0);
	      if (arr->curr_line_is_new==2)
		{
		  A4GL_add_to_control_stack (arr, FORMCONTROL_AFTER_INSERT,
					     arr->currentfield, 0, 0);
		}

              if (arr->curr_line_is_new==1) { // They didn't change anything - so not a real insert...
		                            arr->no_arr--;
					                            A4GL_set_arr_count (arr->no_arr);       // No new lines ...
								                  }

	      arr->curr_line_is_new = 0;
	      A4GL_add_to_control_stack (arr, FORMCONTROL_AFTER_FIELD,
					 arr->currentfield, 0, 0);
	    }
	  new_state = 50;
	  rval = -1;
	}

      if (arr->fcntrl[a].state == 50)
	{
	  new_state = 10;
	  A4GL_add_to_control_stack (arr, FORMCONTROL_AFTER_INPUT, 0, 0, 0);
	  rval = -1;
	}
      if (arr->fcntrl[a].state == 10)
	{
	  new_state = 0;
	  rval = -1;
	}


    }


  if (arr->fcntrl[a].op == FORMCONTROL_EXIT_INPUT_ABORT)
    {
      //extern int int_flag;
      if (arr->fcntrl[a].state == 99)
	{
	  A4GL_comments (0);
	  A4GL_debug ("FORM ABORT..");
	  int_flag = 1;
	  A4GL_add_to_control_stack (arr, FORMCONTROL_AFTER_INPUT, 0, 0, 0);
	  rval = -1;
	  new_state = 10;
	}


      if (arr->fcntrl[a].state == 10)
	{
	  new_state = 0;
	}

    }


  if (arr->fcntrl[a].op == FORMCONTROL_BEFORE_DELETE)
    {
      if (arr->fcntrl[a].state == 99)
	{
	  new_state = 50;
	  if (A4GL_has_event (A4GL_EVENT_BEFORE_DELETE, evt))
	    rval = A4GL_has_event (A4GL_EVENT_BEFORE_DELETE, evt);
	  else
	    {
	      if (A4GL_has_event (A4GL_EVENT_BEF_INSERT_DELETE, evt))
		rval = A4GL_has_event (A4GL_EVENT_BEF_INSERT_DELETE, evt);
	    }
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
      if (arr->fcntrl[a].state == 99)
	{
	  new_state = 50;
	  if (A4GL_has_event (A4GL_EVENT_AFTER_DELETE, evt))
	    rval = A4GL_has_event (A4GL_EVENT_AFTER_DELETE, evt);
	  else
	    {
	      if (A4GL_has_event (A4GL_EVENT_AFT_INSERT_DELETE, evt))
		rval = A4GL_has_event (A4GL_EVENT_AFT_INSERT_DELETE, evt);
	    }
	}

      if (arr->fcntrl[a].state == 50)
	{
	  A4GL_add_to_control_stack (arr, FORMCONTROL_AFTER_ROW,
				     arr->currentfield, 0, 0);
	  new_state = 25;
	  rval = -1;
	}

      if (arr->fcntrl[a].state == 25)
	{
	  struct s_movement ptr;
	  void *next_field;

	  next_field = arr->field_list[arr->scr_line - 1][arr->curr_attrib];
	  ptr.scr_line = arr->scr_line;
	  ptr.arr_line = arr->arr_line;
	  ptr.attrib_no = arr->curr_attrib;

	  A4GL_add_to_control_stack (arr, FORMCONTROL_BEFORE_FIELD,
				     next_field, A4GL_memdup (&ptr,
							      sizeof (struct
								      s_movement)),
				     0);
	  A4GL_add_to_control_stack (arr, FORMCONTROL_BEFORE_ROW, next_field,
				     A4GL_memdup (&ptr,
						  sizeof (struct s_movement)),
				     0);



	  new_state = 10;
	  rval = -1;
	}


      if (arr->fcntrl[a].state == 10)
	{
	  new_state = 0;
	}



    }


  if (arr->fcntrl[a].op == FORMCONTROL_BEFORE_ROW)
    {

      if (arr->fcntrl[a].state == 99)
	{
	  ptr_movement = (struct s_movement *) arr->fcntrl[a].parameter;

	  if (ptr_movement->arr_line > arr->no_arr)
	    {
	      //A4GL_set_arr_count (ptr_movement->arr_line);    // No new lines ...
	      init_arr_line (arr, ptr_movement->arr_line);
	      arr->curr_line_is_new = 1;
	    }
	  else
	    {
	      arr->curr_line_is_new = 0;
	    }

	  arr->scr_line = ptr_movement->scr_line;
	  A4GL_set_scr_line (ptr_movement->scr_line);

	  arr->arr_line = ptr_movement->arr_line;
	  A4GL_set_arr_curr (ptr_movement->arr_line);


	  if (arr->scr_line == ptr_movement->scr_line)
	    {
	      ireinpalay_arr (arr, 2);
	    }


        nv=arr->nbind;
        if (arr->start_slice!=-1 && arr->end_slice!=-1) { nv=arr->end_slice-arr->start_slice+1; }
	  for (cnt = 0; cnt < nv; cnt++)
	    {
	      struct struct_scr_field *fprop;
	      fprop = (struct struct_scr_field *) (A4GL_ll_get_field_userptr (arr->field_list[0][cnt]));	// props are shared - so we don't need the current line...
		A4GL_fprop_flag_clear(arr->field_list[0][cnt], 0xff); // ALL
	      //fprop->flags = 0;
	    }

	  new_state = 50;
	  rval = -1;

	  if (A4GL_has_event (A4GL_EVENT_BEF_ROW, evt))
	    {
	      rval = A4GL_has_event (A4GL_EVENT_BEF_ROW, evt);
	    }
	}



      if (arr->fcntrl[a].state == 50)
	{
	  ptr_movement = (struct s_movement *) arr->fcntrl[a].parameter;

	  if (arr->curr_line_is_new)
	    {
	      if (ptr_movement->arr_line > arr->no_arr)
		{
		  A4GL_set_arr_count (ptr_movement->arr_line);	// No new lines ...
		}

	      A4GL_add_to_control_stack (arr, FORMCONTROL_BEFORE_INSERT, 0, 0,
					 0);
	    }
	  new_state = 25;
	}

      if (arr->fcntrl[a].state == 25)
	{
	  new_state = 0;
	}
    }



  if (arr->fcntrl[a].op == FORMCONTROL_AFTER_ROW)
    {
      new_state = 0;
      if (A4GL_has_event (A4GL_EVENT_AFT_ROW, evt))
	rval = A4GL_has_event (A4GL_EVENT_AFT_ROW, evt);
      //rval = A4GL_EVENT_AFT_ROW;
    }





  if (arr->fcntrl[a].op == FORMCONTROL_BEFORE_INSERT)
    {
      if (arr->fcntrl[a].state == 99)
	{
	  // We want to do the actual insert here...
	  new_state = 80;

#ifdef WHY_IS_THIS_TRIGGERING_BEFORE_INPUT  // ?
	  if (A4GL_has_event (A4GL_EVENT_BEFORE_INP, evt)) {
	  	rval = A4GL_has_event (A4GL_EVENT_BEFORE_INP, evt);
	  }
#endif
	}

      if (arr->fcntrl[a].state == 80)
	{
	  insert_line_in_array (arr);
#ifdef WHY_IS_THIS_TRIGGERING_BEFORE_INPUT  // ?
	  if (A4GL_has_event (A4GL_EVENT_BEFORE_INP, evt)) {
	  	rval = A4GL_has_event (A4GL_EVENT_BEFORE_INP, evt);
	  }
#endif
	  new_state = 50;
	}

      if (arr->fcntrl[a].state == 50)
	{			// BEFORE INSERT 
	  new_state = 0;
	  if (A4GL_has_event (A4GL_EVENT_BEFORE_INSERT, evt))
	    rval = A4GL_has_event (A4GL_EVENT_BEFORE_INSERT, evt);
	  else
	    {
	      if (A4GL_has_event (A4GL_EVENT_BEF_INSERT_DELETE, evt))
		rval = A4GL_has_event (A4GL_EVENT_BEF_INSERT_DELETE, evt);
	    }
	  arr->curr_line_is_new = 1;
	}


    }


  if (arr->fcntrl[a].op == FORMCONTROL_AFTER_INSERT)
    {
      arr->curr_line_is_new = 0;
      new_state = 0;
      if (A4GL_has_event (A4GL_EVENT_AFTER_INSERT, evt))
	rval = A4GL_has_event (A4GL_EVENT_AFTER_INSERT, evt);
      else
	{
	  if (A4GL_has_event (A4GL_EVENT_AFT_INSERT_DELETE, evt))
	    rval = A4GL_has_event (A4GL_EVENT_AFT_INSERT_DELETE, evt);
	}
    }

  if (arr->fcntrl[a].op == FORMCONTROL_KEY_PRESS)
    {

      //debug_print_flags(arr,"kp");
      if (arr->fcntrl[a].state == 99)
	{
	  new_state = 50;
	  if (A4GL_has_event_for_keypress (arr->fcntrl[a].extent, evt))
	    {
	      A4GL_debug ("GOT KEY PRESS... %d %d\n",
			  A4GL_has_event_for_keypress (arr->fcntrl[a].extent,
						       evt));
	      rval = A4GL_has_event_for_keypress (arr->fcntrl[a].extent, evt);
	      arr->processed_onkey = 0;
	    }
	}


      if (arr->fcntrl[a].state == 50)
	{
	  //struct struct_scr_field *fprop;
	  new_state = 25;
	  if (arr->processed_onkey != 0)
	    {
	      A4GL_debug ("process_key_press");
	      process_key_press (arr, arr->fcntrl[a].extent);
	    }
	  else
	    {
	      A4GL_debug ("No process_key_press - had an onkey");
	    }
	  rval = -1;
	}



      if (arr->fcntrl[a].state == 25)
	{
	  struct struct_scr_field *fprop;
	  int ok;
	  int has_picture = 0;
	  char *picture = 0;
	  new_state = 10;

	last_field_pos=-1;

	  fprop =
	    (struct struct_scr_field
	     *) (A4GL_ll_get_field_userptr (arr->currentfield));
	  A4GL_debug ("has_str_attrib - 1 field=%p fprop=%p",
		      arr->currentfield, fprop);

	  if (A4GL_has_str_attribute (fprop, FA_S_PICTURE))
	    {
	      has_picture = 1;
	      picture = A4GL_get_str_attribute (fprop, FA_S_PICTURE);
	    }

	  A4GL_debug ("Checking key state.. %d", arr->fcntrl[a].extent);
	  if (arr->fcntrl[a].extent >= 0 && arr->fcntrl[a].extent <= 255)
	    {
	      if (arr->fcntrl[a].extent >= 0 && arr->fcntrl[a].extent <= 255
		  &&
		  ((a_isprint (arr->fcntrl[a].extent)
		    || arr->fcntrl[a].extent == 1
		    || arr->fcntrl[a].extent == 4)))
		{
		

		  //debug_print_flags(arr,"testing flags for currentfield");
		  if ((A4GL_fprop_flag_get( arr->currentfield, FLAG_MOVED_IN_FIELD)) == 0)
		    {
			int cattrib;
			cattrib=arr->curr_attrib;
	                if (arr->start_slice!=-1) { cattrib+=arr->start_slice; }

		      switch (arr->binding[cattrib].dtype & 255)
			{
			case DTYPE_SMINT:
			case DTYPE_INT:
			case DTYPE_SERIAL:
			case DTYPE_FLOAT:
			case DTYPE_SMFLOAT:
			case DTYPE_DECIMAL:
			case DTYPE_MONEY:
			  A4GL_debug ("MMMM - Clear EOF first pos typing");
			  if (arr->curr_line_is_new==1) { arr->curr_line_is_new=2; }
			  A4GL_LL_int_form_driver (arr->currform->form,
						   AUBIT_REQ_CLR_EOF);
			}
		    }
		  //debug_print_flags(arr,"bs");
		  A4GL_debug ("SETTING FLAGS IA for currentfield");
			A4GL_fprop_flag_set( arr->currentfield,FLAG_FIELD_TOUCHED);
		}



	      if (has_picture)
		{
		  int i;
		  int key;
		  void *mform;
		  mform = arr->currform->form;
		  i = A4GL_LL_get_carat (mform);
		  ok = 1;
		  key = arr->fcntrl[a].extent;

		  if (picture[i] == 'A')
		    {
		      if (a4gl_isalpha (key))
			ok = 1;
		      else
			ok = 0;
		    }
		  if (picture[i] == '#')
		    {
		      if (isdigit (key))
			ok = 1;
		      else
			ok = 0;
		    }
		  if (picture[i] == 'X')
		    {
		      ok = 1;
		    }
		  if (picture[i] != 'X' && picture[i] != '#'
		      && picture[i] != 'A')
		    {
		      ok = 0;
		    }

		}
	      else
		{
		  ok = 1;
		}


	      if (ok == 1)
		{
			  if (arr->curr_line_is_new==1) { arr->curr_line_is_new=2; }
		last_field_pos=A4GL_LL_get_carat ( arr->currform->form);
		  A4GL_LL_int_form_driver (arr->currform->form, arr->fcntrl[a].extent);
		  A4GL_LL_int_form_driver (arr->currform->form, AUBIT_REQ_VALIDATION);
		}


	      if (has_picture && ok)
		{
		  void *mform;
		  mform = arr->currform->form;
		  if (strchr ("A#X", picture[A4GL_LL_get_carat (mform)]) == 0
		      && picture[A4GL_LL_get_carat (mform)])
		    do_key_move ('R', arr, arr->fcntrl[a].extent, has_picture,
				 picture);
		}
	      A4GL_debug ("Setting BF flag for current field");
if (a_isprint(arr->fcntrl[a].extent) && arr->fcntrl[a].extent!='\n'&&arr->fcntrl[a].extent!='\t') {

		A4GL_fprop_flag_set(  arr->currentfield, FLAG_MOVED_IN_FIELD);
	}
	    }
	  rval = -1;
	}

      if (arr->fcntrl[a].state == 10)
	{
	  struct struct_scr_field *fprop;
	  new_state = 5;



	  if (arr->fcntrl[a].extent >= 28 && arr->fcntrl[a].extent <= 255)
	    {
	      rval = -1;
	      fprop = (struct struct_scr_field *) (A4GL_ll_get_field_userptr (arr->currentfield));

	      if (A4GL_has_bool_attribute (fprop, FA_B_AUTONEXT))	// Don't bother - it aint working...
		{
		  void *curses_form;
		int new_field_pos;
		  curses_form = arr->currform->form;
			new_field_pos=A4GL_LL_get_carat (curses_form);
  		  if (new_field_pos == A4GL_get_field_width (A4GL_LL_current_field (curses_form)) - 1 && new_field_pos==last_field_pos) {
		      A4GL_LL_set_current_field (curses_form,
						 arr->currentfield);
		      A4GL_newMovement_single (arr, arr->scr_line, arr->arr_line,
					arr->curr_attrib + 1, 'R');
		    }
		}
	    }

	}

      if (arr->fcntrl[a].state == 5)
	{
	  new_state = 0;
	  rval = -1;
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
	  fprop = (struct struct_scr_field *) (A4GL_ll_get_field_userptr (arr->currentfield));



	  //if (field_opts(arr->currentfield)&AUBIT_O_AUTOSKIP) {
	  //field_opts_off(arr->currentfield,AUBIT_O_AUTOSKIP); // We'll do the autoskiping here...
	  //}

	  A4GL_set_infield_from_parameter ((long) arr->currentfield);
	  //A4GL_push_char (arr->fcntrl[a].field_name);
	  if (A4GL_has_event_for_field
	      (A4GL_EVENT_BEFORE_FIELD, arr->fcntrl[a].field_name, evt))
	    {
	      rval =
		A4GL_has_event_for_field (A4GL_EVENT_BEFORE_FIELD,
					  arr->fcntrl[a].field_name, evt);
	    }
	}


      if (arr->fcntrl[a].state == 50)
	{
	  char *cptr;
	  char *picture = 0;
	  int has_picture = 0;
	//int attrib;
	  arr->currentfield =
	    arr->field_list[arr->scr_line - 1][arr->curr_attrib];
	  A4GL_LL_set_current_field (arr->currform->form, arr->currentfield);

	  arr->currform->currentfield = arr->currentfield;
	  A4GL_debug ("Processed after users 'BEFORE FIELD'");

	  fprop =
	    (struct struct_scr_field
	     *) (A4GL_ll_get_field_userptr (arr->currentfield));
	  attr =
	    A4GL_determine_attribute (FGL_CMD_INPUT, arr->display_attrib,
				      fprop, 0);



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


	  A4GL_debug ("has_str_attrib - 2");
	  if (A4GL_has_str_attribute (fprop, FA_S_PICTURE))
	    {
		int cattrib=arr->curr_attrib;
		 if (arr->start_slice!=-1) { cattrib+=arr->start_slice; }

	      if ((arr->binding[cattrib].dtype & DTYPE_MASK) !=
		  DTYPE_CHAR
		  && (arr->binding[cattrib].dtype & DTYPE_MASK) !=
		  DTYPE_VCHAR)
		{
		  A4GL_exitwith
		    ("Picture applied to a non-char field not implemented yet..");
		}
	      else
		{
		  int a;
		  int w;
		  char *ptr;
		  cptr =
		    (char *) arr->binding[cattrib].ptr +
		    arr->arr_elemsize * (arr->arr_line - 1);
		  w = A4GL_get_field_width (arr->currentfield);
		  has_picture = 1;
		  picture = A4GL_get_str_attribute (fprop, FA_S_PICTURE);
		  ptr = acl_malloc2 (w + 1);
		  strncpy (ptr, cptr, w);
		  ptr[w] = 0;

		  for (a = 0; a < strlen (picture); a++)
		    {
		      if (a > arr->binding[cattrib].size)
			break;

		      if (picture[a] == 'A')
			{
			  if (!a4gl_isalpha (ptr[a]))
			    ptr[a] = ' ';
			  continue;
			}

		      if (picture[a] == '#')
			{
			  if (!isdigit (ptr[a]))
			    ptr[a] = ' ';
			  continue;
			}
		      if (picture[a] == 'X')
			{
			  if (ptr[a] == 0)
			    ptr[a] = ' ';
			  continue;
			}

		      ptr[a] = picture[a];
		    }
		  A4GL_push_param (ptr,
				   arr->binding[cattrib].dtype +
				   ENCODE_SIZE (arr->
						binding[cattrib].
						size));
		  A4GL_display_field_contents (arr->currentfield,
					       arr->binding[cattrib].
					       dtype,
					       arr->binding[cattrib].
					       size, ptr);
		  A4GL_debug ("MJAMJA - PTR=%s", ptr);
		}
	    }
	  else
	    {
		int cattrib=arr->curr_attrib;
		 if (arr->start_slice!=-1) { cattrib+=arr->start_slice; }
	      cptr =
		(char *) arr->binding[cattrib].ptr +
		arr->arr_elemsize * (arr->arr_line - 1);
	      A4GL_push_param (cptr,
			       arr->binding[cattrib].dtype +
			       ENCODE_SIZE (arr->binding[cattrib].
					    size));
	      A4GL_display_field_contents (arr->currentfield,
					   arr->binding[cattrib].
					   dtype,
					   arr->binding[cattrib].
					   size, cptr);
	    }


	  if (has_picture)
	    {
	      void *mform;
	      A4GL_LL_int_form_driver (arr->currform->form, AUBIT_REQ_OVL_MODE);	// Always in overwrite mode in a picture...
	      mform = arr->currform->form;
	      if (strchr ("A#X", picture[A4GL_LL_get_carat (mform)]) == 0
		  && picture[A4GL_LL_get_carat (mform)])
		do_key_move ('R', arr, arr->fcntrl[a].extent, has_picture,
			     picture);
	    }







	  A4GL_comments (fprop);
	  A4GL_LL_set_carat (arr->currform->form);
	  A4GL_debug ("Clearing fprop flag -1 BEFORE FIELD for %d %d",
		      arr->scr_line - 1, arr->curr_attrib);
        A4GL_fprop_flag_clear(arr->currentfield, FLAG_MOVED_IN_FIELD);
        A4GL_fprop_flag_set(arr->currentfield, FLAG_MOVING_TO_FIELD);

	  //if ((fprop->flags & 1)) fprop->flags -= 1;

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
	  char buff[10024];
	  //int has_picture=0;
	  char *picture;

	  char *cptr;
			int cattrib;
			cattrib=arr->curr_attrib;
	                if (arr->start_slice!=-1) { cattrib+=arr->start_slice; }
	  //field_no=arr->curr_attrib;
	  new_state = 0;

	  A4GL_debug ("arr=%p", arr);
	  A4GL_debug ("arr->currentfield=%p field=%p", arr->currentfield,
		      arr->fcntrl[a].field);
	  A4GL_debug ("A4GL_LL_field_buffer(arr->currentfield)=%p",
		      A4GL_LL_field_buffer (arr->currentfield, 0));
	  A4GL_debug ("field contents=%s",
		      A4GL_LL_field_buffer (arr->currentfield, 0));

	  if (arr->currentfield)
	    {
	      fprop =
		(struct struct_scr_field
		 *) (A4GL_ll_get_field_userptr (arr->currentfield));
	      strcpy (buff, A4GL_LL_field_buffer (arr->currentfield, 0));

	      A4GL_debug ("has_str_attrib - 3");
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


	    }
	  else
	    {
	      strcpy (buff, "");
	    }
if (A4GL_fprop_flag_get(arr->currentfield,  FLAG_FIELD_TOUCHED)) {
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

	  A4GL_debug ("Calling pop_iarr_var");
          cattrib=arr->curr_attrib;
          if (arr->start_slice!=-1) cattrib+=arr->start_slice;

	  if (!pop_iarr_var (arr->currform, cattrib, arr->arr_line, arr->arr_elemsize, arr->binding))
	    {
	      A4GL_debug ("Called pop_iarr_var - not ok");
	      new_state = 0;
	      A4GL_debug ("Init control stack");
	      A4GL_init_control_stack (arr, 0);
	      rval = -1;
	      return -1;
	    }

	  cptr =
	    (char *) arr->binding[cattrib].ptr +
	    arr->arr_elemsize * (arr->arr_line - 1);

	  fprop =
	    (struct struct_scr_field
	     *) (A4GL_ll_get_field_userptr (arr->currentfield));
	  attr =
	    A4GL_determine_attribute (FGL_CMD_INPUT, arr->display_attrib,
				      fprop, 0);


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
			   arr->binding[cattrib].dtype +
			   ENCODE_SIZE (arr->binding[cattrib].size));
	  A4GL_display_field_contents (arr->currentfield,
				       arr->binding[cattrib].dtype,
				       arr->binding[cattrib].size,
				       cptr);
	  new_state = 0;
}
	  A4GL_set_infield_from_parameter ((long) arr->currentfield);
	  //A4GL_push_char (arr->fcntrl[a].field_name);
	  if (A4GL_has_event_for_field
	      (A4GL_EVENT_AFTER_FIELD, arr->fcntrl[a].field_name, evt))
	    {
	      rval =
		A4GL_has_event_for_field (A4GL_EVENT_AFTER_FIELD,
					  arr->fcntrl[a].field_name, evt);
	    }
	  //rval = -198;
	}
      else
	{
	  new_state = 0;
	  A4GL_debug ("Init control stack");
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
	  A4GL_debug ("Internal error - no change in state for op %d..",
		      arr->fcntrl[a].op);
	  A4GL_exitwith ("Internal error - no change in state..");
	}
      A4GL_debug ("Setting input control state to %d", new_state);
      arr->fcntrl[a].state = new_state;
    }
  else
    {
      A4GL_debug ("Popping type %d off control stack @ %d", arr->fcntrl[a].op,
		  a);
      if (a != arr->fcntrl_cnt - 1)
	{
	  A4GL_debug ("INTERNAL ERROR - pop state with added new one %d %d",
		      arr->fcntrl[a].op, arr->fcntrl[a].state);
	  A4GL_exitwith ("Internal error - bad change in state ");
	  return -1;
	}
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
A4GL_iarr_arr_fields (struct s_inp_arr *arr, int dattr, int arr_line,
		      int scr_line, int blank)
{
  int a;
  int flg;
  struct s_form_dets *formdets;
  char *cptr;
  char buff[256];
  int da;
  int attr;
	int nv;

  struct struct_scr_field *fprop;
  A4GL_debug ("In disp_fields");

  if (  arr->currform != UILIB_A4GL_get_curr_form (0))
    {
      A4GL_make_window_with_this_form_current (arr->currform);
    }

  formdets = UILIB_A4GL_get_curr_form (1);

  flg = 0;

  //if (fonly && nofields >= 0) nofields = 0;


  nv=arr->nbind;
  if (arr->start_slice!=-1 && arr->end_slice!=-1) { nv=arr->end_slice-arr->start_slice+1; }


  for (a = 0; a < nv; a++)
    {
	int bno;

        if (arr->start_slice==-1) {
                bno=a;
        } else {
                bno=a+arr->start_slice;
        }

      fprop =
	(struct struct_scr_field
	 *) (A4GL_ll_get_field_userptr (arr->field_list[scr_line - 1][a]));

      attr = A4GL_determine_attribute (FGL_CMD_DISPLAY_CMD, dattr, fprop, 0);
      da = attr;

      if (arr_line == arr->arr_line)
	{
	  attr = A4GL_determine_attribute (FGL_CMD_INPUT, dattr, fprop, 0);
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

      A4GL_debug ("Attrib %x - %d fprop=%p %d %d", a, attr, fprop);
      if ((da & AUBIT_ATTR_REVERSE) && blank)
	{
	  da -= AUBIT_ATTR_REVERSE;
	}
      if (attr != 0)
	A4GL_set_field_attr_with_attr_already_determined (arr->
							  field_list[scr_line
								     - 1][a],
							  da, FGL_CMD_INPUT);

      if (!blank)
	{
	  cptr =
	    (char *) arr->binding[bno].ptr + arr->arr_elemsize * (arr_line - 1);
	  A4GL_push_param (cptr,
			   arr->binding[bno].dtype +
			   ENCODE_SIZE (arr->binding[bno].size));
	}
      else
	{
	  strcpy (buff, "");
	  cptr = buff;
	  A4GL_push_null (DTYPE_CHAR, 1);
	  A4GL_setnull (arr->binding[bno].dtype, cptr, arr->binding[bno].size);
	}

      A4GL_display_field_contents (arr->field_list[scr_line - 1][a],
				   arr->binding[bno].dtype,
				   arr->binding[bno].size, cptr);

    }

}





int
UILIB_A4GL_req_field_input_array (void *arrv, char type, va_list * ap)
{
  struct s_inp_arr *arr;
  /* fieldname + = next - = previous */
  int a;
  //void **ptr;
  char *colname;
int nv;


  A4GL_debug ("req_field_input_array - %c", type);
  arr = arrv;

  if (type == '+')
    {				// Next field next
      A4GL_debug ("Init control stack");
      if (arr->currentfield)
	{
	  A4GL_init_control_stack (arr, 0);
	}
      arr->currform->currentfield = 0;
      arr->currentfield = 0;
      A4GL_newMovement_single (arr, arr->scr_line, arr->arr_line,
			arr->curr_attrib + 1, 'R');
      return 1;
    }

  if (type == '-')
    {				// Next field previous
      A4GL_debug ("Init control stack");
      if (arr->currentfield)
	{
	  A4GL_init_control_stack (arr, 0);
	}
      arr->currform->currentfield = 0;
      arr->currentfield = 0;
      A4GL_newMovement_single (arr, arr->scr_line, arr->arr_line,
			arr->curr_attrib - 1, 'L');
      return 1;
    }

  if (type == '0')
    {				// Next field 'current' (used internall)
      A4GL_debug ("Init control stack");
      if (arr->currentfield)
	{
	  A4GL_init_control_stack (arr, 0);
	}
      //arr->currform->currentfield = 0;
      //A4GL_newMovement_single (arr, arr->scr_line, arr->arr_line, arr->curr_attrib );
      return 1;
    }



  A4GL_debug ("req_field");

  a = 1;
  colname = va_arg (*ap, char *);
        nv=arr->nbind;
        if (arr->start_slice!=-1 && arr->end_slice!=-1) { nv=arr->end_slice-arr->start_slice+1; }


  A4GL_debug ("A=%d MJAMJA123", a);
  if (a >= 0)
    {
      for (a = 0; a < nv; a++)
	{

	  if (A4GL_field_name_match (arr->field_list[0][a], colname))

	    //if (arr->field_list[arr->scr_line][a] == ptr[0])
	    {
	      A4GL_debug ("Init control stack");
	      if (arr->currentfield || type =='!')
		{
		  A4GL_init_control_stack (arr, 0);
		} else {
                        if (arr->fcntrl_cnt>=2) {
                                if (arr->fcntrl[0].op==FORMCONTROL_BEFORE_FIELD && arr->fcntrl[1].op==FORMCONTROL_BEFORE_ROW) {
                                        if (arr->fcntrl[2].op==FORMCONTROL_BEFORE_FIELD && arr->fcntrl[3].op==FORMCONTROL_BEFORE_ROW) {
                                                free(arr->fcntrl[0].parameter);
                                                free(arr->fcntrl[1].parameter);
                                                memcpy(&arr->fcntrl[0],&arr->fcntrl[2],sizeof(arr->fcntrl[0]));
                                                memcpy(&arr->fcntrl[1],&arr->fcntrl[3],sizeof(arr->fcntrl[0]));
                                                arr->fcntrl_cnt=2;
                                        }
                                }
                        }
		}


	      if (a != arr->curr_attrib)
		{
		  // How risky is this ?
		  arr->currform->currentfield = 0;
		  arr->currentfield = 0;
		  A4GL_newMovement_single (arr, arr->scr_line, arr->arr_line, a,
				    'Q');
		}
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










void
debug_print_flags (void *sv, char *txt)
{
  struct s_inp_arr *s;
  struct struct_scr_field *fprop;
  int a;
  int b;
int nv;
  s = sv;
  A4GL_debug ("fgl_fieldtouched - input array");
    nv=s->nbind;
    if (s->start_slice!=-1 && s->end_slice!=-1) { nv=s->end_slice-s->start_slice+1; }

  for (a = 0; a < s->scr_dim; a++)
    {
      for (b = 0; b < nv; b++)
	{
	  void *f;
	  f = s->field_list[a][b];
	  fprop =
	    (struct struct_scr_field
	     *) (A4GL_ll_get_field_userptr (s->field_list[a][b]));
	  A4GL_debug ("FLAGS (%s)%d %d - %d %p %p", txt, a, b, fprop->flags,
		      f, fprop);
	}
    }
}



int
A4GL_field_name_match (void *f, char *s)
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

  field = (struct struct_scr_field *) (A4GL_ll_get_field_userptr (f));
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
      //int mno;
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
	      SPRINTF2 (buff, "%s.%s",
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


int
A4GL_copy_field_data (struct s_form_dets *form)
{
  char buff[8000] = "";
  char buff2[8000] = "";
  void *mform;
  int ppr;
  //int x, y;
  struct struct_scr_field *fprop;
  mform = form->form;
  A4GL_debug ("form->currentfield=%p", form->currentfield);
  if (form->currentfield != 0)
    if (A4GL_ll_get_field_userptr (form->currentfield) != 0)
      {
	A4GL_debug ("Is a proper field");
	fprop =
	  (struct struct_scr_field
	   *) (A4GL_ll_get_field_userptr (form->currentfield));
	A4GL_debug ("fprop=%p", fprop);
	if (fprop != 0)
	  {
	    A4GL_debug ("check Datatype ");
	    if (((fprop->datatype != DTYPE_CHAR) & (DTYPE_MASK))
		&& (A4GL_LL_field_status (form->currentfield)))
	      {
		A4GL_debug ("modify size dtype");
		A4GL_debug ("modfy size for metric %d",
			    A4GL_get_metric_for (form, form->currentfield));
		A4GL_modify_size (&buff[4],
				  form->fileform->metrics.
				  metrics_val[A4GL_get_metric_for
					      (form, form->currentfield)].w);
		A4GL_debug ("modfy size done -> '%s'", &buff[4]);

		strcpy (&buff[4],
			A4GL_LL_field_buffer (form->currentfield, 0));
		A4GL_debug ("copy 1");
		strcpy (buff2, &buff[4]);
		A4GL_debug ("copy 2");
		A4GL_debug ("trim buff");
		A4GL_trim (buff2);
		//getsyx (y, x);


		//A4GL_debug ("CHange y=%d, x=%d", y, x);
		A4GL_debug ("stack manip buff2='%s'", buff2);
		if (strlen (buff2) > 0)
		  {
#ifdef DEBUG
		    A4GL_debug ("Pushing param %p");
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
			A4GL_push_param (buff,
					 fprop->datatype +
					 (fprop->dtype_size << 16));
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
						   buff,0);
		      }
		    else
		      {
			A4GL_error_nobox (acl_getenv ("FIELD_ERROR_MSG"), 0);

			if (A4GL_isyes
			    (acl_getenv ("A4GL_CLR_FIELD_ON_ERROR")))
			  {
			    A4GL_clr_field (form->currentfield);
			  }
			else
			  {
			    if (A4GL_isyes (acl_getenv ("FIRSTCOL_ONERR")))
			      {
				A4GL_LL_int_form_driver (mform,
							 AUBIT_REQ_BEG_FIELD);
			      }

			  }

			A4GL_LL_set_current_field (mform, form->currentfield);
			return 0;
		      }
		  }
	      }
	  }
      }
  return 1;
}




void
A4GL_set_arr_fields (int n, int attr, ...)
{
  int a;
  va_list ap;
  int flg;
  struct s_form_dets *fff;
  struct s_form_dets *formdets;
  void **field_list;
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
  nofields = A4GL_gen_field_list (&field_list, formdets, n, &ap,0);
  A4GL_debug ("Number of fields=%d", nofields);
  for (a = nofields; a >= 0; a--)
    {
      A4GL_debug ("field_list[%d]=%p", field_list[a]);
      fff = UILIB_A4GL_get_curr_form (1);
      A4GL_LL_set_current_field (fff->form, field_list[a]);
      A4GL_debug ("set_init_pop complete");
    }

  A4GL_LL_set_current_field (fff->form, field_list[0]);	// was nofields....
}





int
A4GL_form_field_chk_iarr (struct s_inp_arr *sio, int m)
{
  char buff[8000] = "";
  char buff2[8000] = "";
  void *mform;
  int pprval;
  //int flg = 0;
  struct s_form_dets *form;
  struct struct_scr_field *fprop;

  A4GL_debug ("form_field_chk_iarr....");
  mform = sio->currform->form;
  A4GL_debug ("CHeck fields 1 m=%d", m);
  form = sio->currform;
  A4GL_debug ("CHeck fields 2 currentfield=%p status = %d",
	      form->currentfield, A4GL_LL_field_status (form->currentfield));

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
	      form->currentfield, A4GL_LL_current_field (mform), m);
  A4GL_debug
    ("field_status(form->currentfield)=%d field_status(currfield)=%d",
     A4GL_LL_field_status (form->currentfield),
     A4GL_LL_field_status (A4GL_LL_current_field (mform)));
  if ((form->currentfield != A4GL_LL_current_field (mform)) || m < 0)
    {
      /*
         A4GL_debug ("Setting focus");
         A4GL_gui_setfocus (current_field (mform));
       */
      A4GL_debug ("Is different");
      fprop = 0;

      if (form->currentfield != 0)
	if (A4GL_ll_get_field_userptr (form->currentfield) != 0)
	  {
	    A4GL_debug ("Is a proper field");
	    fprop =
	      (struct struct_scr_field
	       *) (A4GL_ll_get_field_userptr (form->currentfield));
	    A4GL_debug ("fprop=%p", fprop);



	    if (fprop != 0)
	      {

		//int d1,s1;
		//char *ptr1;

		A4GL_debug ("15 fprop!=0");
		if ((fprop->datatype & DTYPE_MASK) != DTYPE_CHAR)
		  {

		    A4GL_modify_size (&buff[4],
				      form->fileform->metrics.
				      metrics_val[A4GL_get_metric_for
						  (form,
						   form->currentfield)].w);

		    strcpy (&buff[4],
			    A4GL_LL_field_buffer (form->currentfield, 0));
		    strcpy (buff2, &buff[4]);
		    A4GL_trim (buff2);
		    //getsyx (y, x);
		    A4GL_trim (buff2);
		    A4GL_debug ("15 Check buff2='%s'", buff2);

		    if (strlen (buff2) == 0)
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
				A4GL_LL_set_current_field (mform,
							   form->
							   currentfield);
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

			if (A4GL_isyes
			    (acl_getenv ("A4GL_CLR_FIELD_ON_ERROR")))
			  {
			    A4GL_clr_field (form->currentfield);
			  }
			else
			  {
			    if (A4GL_isyes (acl_getenv ("FIRSTCOL_ONERR")))
			      {
				A4GL_LL_int_form_driver (mform,
							 AUBIT_REQ_BEG_FIELD);
			      }

			  }


			A4GL_LL_set_current_field (mform, form->currentfield);
			return -4;
		      }
		  }


		A4GL_debug ("CHECK FOR INCLUDE");

		strcpy (buff,
			A4GL_LL_field_buffer (sio->currform->currentfield,
					      0));
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
			    A4GL_LL_set_current_field (mform,
						       form->currentfield);
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
			(A4GL_LL_field_buffer
			 (sio->currform->currentfield, 0),
			 A4GL_get_str_attribute (fprop, FA_S_INCLUDE),
			 fprop->datatype) == 0)
		      {
			A4GL_error_nobox (acl_getenv ("FIELD_INCL_MSG"), 0);
			A4GL_LL_set_current_field (mform, form->currentfield);
			return -4;
		      }
		  }





	      }
	  }
    }
  return 0;

}


void
A4GL_turn_field_on2 (void *f, int a)
{
int fo;
  struct struct_scr_field *fprop;

  A4GL_assertion (f == 0, "Field is zero in turn_field_on2");


  fprop = (struct struct_scr_field *) (A4GL_ll_get_field_userptr (f));
  A4GL_assertion (fprop == 0, "Field has no properties");

  fo=A4GL_ll_field_opts(f);

  if (fo==0) {
	  // Looks suspicious...
  }
  if (!(fo&AUBIT_O_ACTIVE)) { fo+=AUBIT_O_ACTIVE; }
  if (!(fo&AUBIT_O_EDIT))   { fo+=AUBIT_O_EDIT;   }


  A4GL_debug ("STATIC");


  if (!a)
    {
        if (A4GL_has_bool_attribute (fprop, FA_B_AUTONEXT)  && ! A4GL_has_bool_attribute (fprop, FA_B_WORDWRAP)) {
		if (fo&AUBIT_O_AUTOSKIP) {
			fo-=AUBIT_O_AUTOSKIP;
  			A4GL_ll_set_field_opts (f, fo);
  			A4GL_set_field_attr_for_ll (0,f);
		} else {
  			A4GL_ll_set_field_opts (f, fo);
  			A4GL_set_field_attr_for_ll (0,f);
		}
        } else {
  		A4GL_ll_set_field_opts (f, fo);
  		A4GL_set_field_attr_for_ll (0,f);
	}

      	//A4GL_LL_set_max_field (f, 0,0);
    } else {
  	A4GL_ll_set_field_opts (f, fo);
  	A4GL_set_field_attr_for_ll (0,f);
  	A4GL_LL_set_max_field (f, A4GL_get_field_width (f),0);
    }

  //}
  //else
  //{
  //A4GL_debug ("NOT STATIC");
  //A4GL_field_opts_off (f, AUBIT_O_STATIC);
  //}

}



void
A4GL_set_field_attr_with_attr_already_determined (void *field, int attr,
						  int cmd_type)
{
  int r;
  //int nattr;
  struct struct_scr_field *f;
  f = (struct struct_scr_field *) (A4GL_ll_get_field_userptr (field));

  //nattr = A4GL_determine_attribute (cmd_type, attr, f, 0);
  //A4GL_debug ("Passed in attribute: %x, determined attribute should be %x",
  //attr, nattr);
  //attr = nattr;

  if (attr & AUBIT_ATTR_REVERSE)
    r = 1;
  else
    r = 0;
  A4GL_debug
    ("MJA Calling A4GL_set_field_colour_attr - do_reverse=%d attr=%d", r,
     attr);
  A4GL_set_field_colour_attr (field, r, attr);
}





static char *get_field_with_no_picture(void *f) {
static char *p=0;
struct struct_scr_field *fprop;
char *picture;

        if (p) free(p);
        fprop = (struct struct_scr_field *) (A4GL_ll_get_field_userptr (f));
        p=strdup(A4GL_LL_field_buffer(f,0));
        picture = A4GL_get_str_attribute (fprop, FA_S_PICTURE);
        // remove any attached picture...
        if (picture) {
                        int z;
                        for (z=0;z<strlen(p);z++) {
                                if (z>strlen(picture)) break;
                                if (picture[z]=='A') p[z]=' ';
                                if (picture[z]=='X') p[z]=' ';
                                if (picture[z]=='#') p[z]=' ';
                        }
        }
        return p;
}


static int A4GL_entire_row_is_blank (struct s_inp_arr *s,int ln)
{
  //struct struct_scr_field *fprop;
  //int a;
  int b;
  int nv;
  int isblank=1;

    nv=s->nbind;
      if (s->start_slice!=-1 && s->end_slice!=-1) { nv=s->end_slice-s->start_slice+1; }

      for (b = 0; b < nv; b++)
        {
                void *f;
                char *p;
                f = s->field_list[ln][b];
                p=get_field_with_no_picture(f);
                // remove any attached picture...
                A4GL_trim(p);
                if (strlen(p)) {
                        isblank=0;
                        break;
                }
    }
return isblank;
}


int
A4GL_double_chk_line (struct s_inp_arr *s, int ln, char why)
{
// Lets just double check for any required fields...
  struct struct_scr_field *fprop;
  //int a;
  int b;
  int nv;
  //int isblank = 1;
  int is_all_blank = 0;
if (ln<0) return 1;

  is_all_blank = A4GL_entire_row_is_blank (s, ln);
  nv = s->nbind;


  if (s->start_slice != -1 && s->end_slice != -1)
    {
      nv = s->end_slice - s->start_slice + 1;
    }

  for (b = 0; b < nv; b++)
    {
      //char *buff2;
      void *f;
      char *p;
      f = s->field_list[ln][b];
        fprop = (struct struct_scr_field *) (A4GL_ll_get_field_userptr (f));
      p = get_field_with_no_picture (f);
      A4GL_trim (p);
      if (strlen (p) == 0)
        {
          int chged = 0;
          // Has the field changed ?
          // Are we on a new line ?
          if ((A4GL_fprop_flag_get(f, FLAG_FIELD_TOUCHED)))
            {
              chged++;
            }

          // are we returning to a previous field ?
          if (s->processed_onkey != A4GLKEY_UP && s->processed_onkey != A4GLKEY_LEFT && s->processed_onkey != A4GLKEY_SHTAB)
            {
              A4GL_debug ("last key was not up or left");
              chged++;
            }



          if (chged == 0)
            {
              if (!is_all_blank)
                {
                  chged++;
                }
            }

          if (A4GL_has_bool_attribute (fprop, FA_B_REQUIRED) && chged)
            {

              int allow_it_anyway = 0;

              // We'll still allow it - so long as there is null in the include list
              if (A4GL_has_str_attribute (fprop, FA_S_INCLUDE))
                {
                  if (A4GL_check_field_for_include
                      ("",
                       A4GL_get_str_attribute (fprop, FA_S_INCLUDE), fprop->datatype))
                    {
                      allow_it_anyway = 1;
                    }
                }

              if (!allow_it_anyway)
                {
                  // Well there wasn't - so it is required....
                  A4GL_error_nobox (acl_getenv ("FIELD_REQD_MSG"), 0);
                  A4GL_newMovement_single (s, s->scr_line, s->arr_line, b, why);
                  return 0;
                }

            }
        }
    }
  return 1;
}

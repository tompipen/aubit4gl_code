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
# $Id: formcntrl.c,v 1.65 2008-03-13 11:13:50 mikeaubury Exp $
#*/
#ifndef lint
static char const module_id[] = "$Id: formcntrl.c,v 1.65 2008-03-13 11:13:50 mikeaubury Exp $";
#endif
/**
 * @file
 * Form movement control
 *
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/
#include "a4gl_libaubit4gl.h"
#include "hl_proto.h"
#include "a4gl_lib_ui_int.h"
#include "a4gl_API_ui_lib.h"
#include "a4gl_incl_4gldef.h"
#include "a4gl_API_lowlevel.h"
#include "formdriver.h"
#include "formcntrl.h"
#include <string.h>
#include <ctype.h>
char *last_field_name;
int construct_last_key;
//void A4GL_set_infield_from_parameter (long a);
int construct_not_added = 0;
int construct_not_moved = 0;

void A4GL_debug_print_field_opts (void *a);
static int A4GL_local_get_curr_window_attr (void);
static int A4GL_construct_large_loop (void *f, struct aclfgl_event_list *evt, struct struct_scr_field *fprop);
static int internal_A4GL_form_loop_v2 (void *vs, int init, void *vevt);
//int A4GL_has_event (int a, struct aclfgl_event_list *evt);
//int A4GL_has_event_for_keypress (int a, struct aclfgl_event_list *evt);
//int A4GL_has_event_for_field (int cat, char *a, struct aclfgl_event_list *evt);
//void *A4GL_get_currwin (void);
//int A4GL_conversion_ok(int);
//void A4GL_fgl_die_with_msg(int n,char *s);

extern int m_lastkey;
#define CONTROL_STACK_LENGTH 10
int A4GL_field_is_noentry (int doing_construct, struct struct_scr_field *f);

/*
static int process_control_stack_single (struct s_screenio *arr, struct aclfgl_event_list *evt);
static int A4GL_has_something_on_control_stack (struct s_screenio *sio);
static void A4GL_add_to_control_stack (struct s_screenio *sio, int op,
				       void *f, char *parameter, int extent);
static void A4GL_newMovement (struct s_screenio *arr, int attrib);
static void A4GL_init_control_stack (struct s_screenio *sio, int malloc_data);
static int A4GL_proc_key_input (int a, void *mform, struct s_screenio *s);
*/

static void do_key_move (char lr, struct s_screenio *s, int a, int has_picture, char *picture);
long inp_current_field = 0;
int last_key_code = 0;

static int chk_all_fields (struct s_screenio *sio);


/*
=====================================================================
                    Variables definitions
=====================================================================
*/

struct s_movement
{
  int scr_line;
  int arr_line;
  int attrib_no;
};
int do_input_nowrap = 0;


char *ops[] = {
  "",
  "FORMCONTROL_BEFORE_FIELD",	//                1
  "FORMCONTROL_AFTER_FIELD",	//                 2
  "FORMCONTROL_BEFORE_INPUT",	//               3
  "FORMCONTROL_AFTER_INPUT",	//              4
  "FORMCONTROL_EXIT_INPUT_OK",	//            5
  "FORMCONTROL_EXIT_INPUT_ABORT",	//          6
  "FORMCONTROL_KEY_PRESS",	//          7
  "FORMCONTROL_BEFORE_INSERT",	//            8
  "FORMCONTROL_BEFORE_DELETE",	//            9
  "FORMCONTROL_AFTER_INSERT",	//            10
  "FORMCONTROL_AFTER_DELETE",	//            11
  "FORMCONTROL_BEFORE_ROW",	//            12
  "FORMCONTROL_AFTER_ROW",	//            13
  0
};

/* 
* This function adds a value to the control stack
* this is read to determine when to call before/after fields etc
*
*/
static void
A4GL_add_to_control_stack (struct s_screenio *sio, enum e_formcontrol op, void *f, char *parameter, int extent)
{
  char *field_name;
  int a;
  struct struct_scr_field *attr;

  A4GL_debug ("add to control stack called with op=%d(%s) field=%p extent=%d", op, ops[op], f, extent);

  field_name = 0;

  if (f)
    {
      attr = (struct struct_scr_field *) A4GL_ll_get_field_userptr (f);
      field_name = attr->colname;
    }
  a = sio->fcntrl_cnt;
  sio->fcntrl[a].op = op;
  sio->fcntrl[a].parameter = parameter;
  sio->fcntrl[a].field_name = field_name;
  sio->fcntrl[a].field_number = 0;	// This is reserved for future enhancement :)
  sio->fcntrl[a].extent = extent;
  sio->fcntrl[a].state = -1;
  sio->fcntrl_cnt++;

}




/* This function determines if there is something to do on the control stack */
static int
A4GL_has_something_on_control_stack (struct s_screenio *sio)
{
  if (sio->fcntrl_cnt)
    return 1;
  return 0;
}




/***************************************
	This function creates the control stack and can also be used for clearing it down (if malloc_data is set to 0)
****************************************/
static void
A4GL_init_control_stack (struct s_screenio *sio, int malloc_data)
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
	      acl_free (sio->fcntrl[a].parameter);
	    }
	}
    }

// Go through each line and set everything to zero...
  for (a = 0; a < CONTROL_STACK_LENGTH; a++)
    {
      sio->fcntrl[a].op = 0;
      sio->fcntrl[a].parameter = 0;
      sio->fcntrl[a].field_number = 0;
      sio->fcntrl[a].state = -1;
      sio->fcntrl[a].extent = 0;

    }
  sio->fcntrl_cnt = 0;
}


/*
 *  Set up a record for a desired movement...
 */
static void
A4GL_newMovement (struct s_screenio *sio, int attrib)
{
  struct s_movement *ptr;
  void *last_field = 0;
  void *next_field = 0;
  struct struct_scr_field *f;

  A4GL_debug ("newMovement %d ", attrib);

  if (attrib < 0)
    {
      // attempt to move too far to the left
      A4GL_debug ("Too far to the left");
      // cc 2004.11.15
      if (sio->currform->currentfield == sio->field_list[0] && A4GL_get_dbscr_inputmode () != 0)
	{
	  A4GL_debug ("Wrap around from top to bottom");
	  A4GL_newMovement (sio, sio->nfields);
	  return;
	}
      // attempt to move too far to the left
      A4GL_debug ("Too far to the left");
      A4GL_newMovement (sio, 0);
      return;
    }

  //if (attrib < 0)
  //{
  //// attempt to move too far to the left
  //A4GL_debug ("Too far to the left");
  //A4GL_newMovement (sio, 0);
  //return;
  //}


  if (attrib > sio->nfields)
    {
      // Too far over to the right - wrap to the left or possible exit - INPUT WRAP...
      A4GL_debug ("Too far to the right");
      A4GL_newMovement (sio, -1);
      return;
    }



  ptr = acl_malloc2 (sizeof (struct s_movement));
  ptr->scr_line = -1;		// Not used for a normal input/construct
  ptr->arr_line = -1;		// Not used for a normal input/construct
  ptr->attrib_no = attrib;

  last_field = sio->currform->currentfield;

  A4GL_debug ("last field was : %p", sio->currform->currentfield);
  next_field = sio->field_list[attrib];
  f = (struct struct_scr_field *) (A4GL_ll_get_field_userptr (next_field));

  if (A4GL_field_is_noentry ((sio->mode == MODE_CONSTRUCT), f) || (f->datatype == DTYPE_SERIAL && sio->mode != MODE_CONSTRUCT))
    {
      int dir = 0;
      A4GL_debug ("NOENTRY!!!!!!!!!!!!!!!!!!!!!!!!!!");
      while (1)
	{

	  if (dir == 0)
	    {
	      if (attrib >= sio->curr_attrib)
		{		// We want to move to the right..
		  dir = 1;
		}
	      else
		{
		  dir = -1;
		}
	    }
	  next_field = sio->field_list[attrib];
	  f = (struct struct_scr_field *) (A4GL_ll_get_field_userptr (next_field));

	  if (A4GL_field_is_noentry ((sio->mode == MODE_CONSTRUCT), f)
	      || (f->datatype == DTYPE_SERIAL && sio->mode != MODE_CONSTRUCT))
	    {
	      attrib += dir;
	      if (attrib > sio->nfields)
		{


		  if (A4GL_get_dbscr_inputmode () == 0)
		    {
		      A4GL_add_to_control_stack (sio, FORMCONTROL_EXIT_INPUT_OK, 0, 0, 0);
		      return;
		    }

		  attrib = 0;
		}

	      if (attrib < 0)
		{
		  attrib = sio->nfields;
		}
	    }
	  else
	    {
	      A4GL_debug ("Found somewhere free...");
	      A4GL_newMovement (sio, attrib);	// So keep going...
	      return;
	    }
	}
    }






  if (last_field != next_field || 1)
    {
      A4GL_add_to_control_stack (sio, FORMCONTROL_BEFORE_FIELD, next_field, A4GL_memdup (ptr, sizeof (struct s_movement)), 0);
      if (last_field)
	{

	  A4GL_add_to_control_stack (sio, FORMCONTROL_AFTER_FIELD, last_field, 0, 0);
	}
      acl_free (ptr);
    }
  else
    {
      acl_free (ptr);
    }
  //A4GL_debug("Done newMovement - last_field was %p new_field is %p",last_field,new_field);
}



/* 
* process any waiting actions 
*
*/
static int
process_control_stack_single (struct s_screenio *sio, struct aclfgl_event_list *evt)
{
  int a;
  int rval;
  int new_state;
  struct s_movement *ptr_movement;
  struct s_formcontrol fcntrl;

  rval = -1;
  new_state = 99;


  a = sio->fcntrl_cnt - 1;
  memcpy (&fcntrl, &sio->fcntrl[a], sizeof (struct s_formcontrol));

  A4GL_debug ("Process control stack %d %d", fcntrl.op, fcntrl.state);
  if (fcntrl.op == FORMCONTROL_BEFORE_INPUT)
    {
      if (sio->fcntrl[a].state == 99)
	{
	  new_state = 50;
	  if (A4GL_has_event (A4GL_EVENT_BEFORE_INP, evt))
	    {
	      rval = A4GL_has_event (A4GL_EVENT_BEFORE_INP, evt);
	      A4GL_debug ("Set rval=%d\n", rval);
	    }
	}
      if (sio->fcntrl[a].state == 50)
	{
	  int c;
	  if (A4GL_isyes (acl_getenv ("CLRFIELDSTATUS")))
	    {
	      for (c = 0; c <= sio->nfields; c++)
		{
		  void *p;
		  struct struct_scr_field *fprop = 0;
		  p = sio->field_list[c];
		  fprop = (struct struct_scr_field *) (A4GL_ll_get_field_userptr (p));
		  A4GL_debug ("Flags=0");
		  A4GL_fprop_flag_clear (p, 0xff);	// ALL FLAGS
		}
	    }
	  new_state = 0;
	  rval = -1;

	}

    }

  if (fcntrl.op == FORMCONTROL_AFTER_INPUT)
    {
      if (fcntrl.state == 99)
	{
	  new_state = 50;
	  if (A4GL_has_event (A4GL_EVENT_AFTER_INP, evt))
	    {
	      rval = A4GL_has_event (A4GL_EVENT_AFTER_INP, evt);
	      A4GL_debug ("Set rval=%d\n", rval);
	    }
	}

      if (fcntrl.state == 50)
	{
	  new_state = 0;
	  if (A4GL_has_event (A4GL_EVENT_AFTER_INP_CLEAN, evt))
	    {
	      rval = A4GL_has_event (A4GL_EVENT_AFTER_INP_CLEAN, evt);
	      A4GL_debug ("Set rval=%d\n", rval);
	    }
	  else
	    {
	      A4GL_exitwith ("Internal error - no break\n");
	      exit (1);
	    }
	}
    }


  if (fcntrl.op == FORMCONTROL_EXIT_INPUT_OK)
    {
      A4GL_comments (0);
      if (fcntrl.state == 99)
	{
	  A4GL_add_to_control_stack (sio, FORMCONTROL_AFTER_FIELD, sio->currentfield, 0, 0);
	  new_state = 60;
	  rval = -1;
	}

      if (sio->fcntrl[a].state == 60)
	{
	  int a;

	  a = chk_all_fields (sio);
	  if (a >= 0)
	    {
	      new_state = 0;
	      A4GL_init_control_stack (sio, 0);
	      A4GL_newMovement (sio, a);
	    }
	  else
	    {
	      new_state = 50;
	    }
	  rval = -1;
	}


      if (fcntrl.state == 50)
	{
	  A4GL_add_to_control_stack (sio, FORMCONTROL_AFTER_INPUT, 0, 0, 0);
	  new_state = 10;
	  A4GL_debug ("SETTING RVAL TO ZERO");
	  rval = -1;
	}
      if (fcntrl.state == 10)
	{
	  new_state = 0;
	  rval = -1;
	}


    }


  if (fcntrl.op == FORMCONTROL_EXIT_INPUT_ABORT)
    {
      //extern int int_flag;
      if (fcntrl.state == 99)
	{
	  A4GL_comments (0);
	  A4GL_debug ("FORM ABORT..");
	  int_flag = 1;
	  A4GL_add_to_control_stack (sio, FORMCONTROL_AFTER_INPUT, 0, 0, 0);
	  A4GL_debug ("SETTING RVAL TO ZERO");
	  rval = -1;
	  new_state = 10;
	}

      if (fcntrl.state == 10)
	{
	  if (sio->mode == MODE_CONSTRUCT)
	    {
	      sio->processed_onkey = A4GLKEY_INTERRUPT;
	    }

	  new_state = 0;
	}

    }

  if (fcntrl.op == FORMCONTROL_KEY_PRESS)
    {
      A4GL_debug ("GOT KEY PRESS - STATE = %d", fcntrl.state);
      if (fcntrl.state == 99)
	{
	  construct_not_added = 1;
	  new_state = 75;

	  if (sio->mode == MODE_CONSTRUCT && last_key_code != A4GLKEY_CANCEL)
	    {
	      if (A4GL_has_event_for_keypress (fcntrl.extent, evt))
		{		// We should be a litle worried...
		  if (!A4GL_do_after_field (sio->currform->currentfield, sio))
		    {
		      new_state = 0;
		    }
		}
	    }

	  if (new_state != 0)
	    {

	      A4GL_debug ("GOT KEY PRESS... %d %d\n", A4GL_has_event_for_keypress (fcntrl.extent, evt));
	      last_key_code = sio->fcntrl[a].extent;
	      rval = A4GL_has_event_for_keypress (fcntrl.extent, evt);
	      if (rval)
		{
		  sio->processed_onkey = 0;
		}
	      else
		{
		  rval = -1;
		}
	      A4GL_debug ("Set rval=%d\n", rval);
	    }
	}



      if (fcntrl.state == 75)
	{
	  new_state = 50;
	  if (sio->processed_onkey != 0)
	    {
	      static int kr = -1;
	      static int kr_q = -1;
	      int ignore;
	      ignore = 0;
	      if (kr == -1)
		{
		  kr = atoi (acl_getenv ("KEY_RECALL"));
		}
	      if (kr_q == -1)
		{
		  kr_q = atoi (acl_getenv ("KEY_RECALL_LAST"));
		}

	      if (kr && fcntrl.extent == kr && ignore == 0)
		{
		  struct struct_scr_field *fprop;
		  fprop = (struct struct_scr_field *) (A4GL_ll_get_field_userptr (sio->currentfield));
		  A4GL_recall_field (fprop->tabname, fprop->colname, 1, 1, 1);
		  new_state = 0;
		  rval = -1;
		  ignore = 1;
		}

	      if (kr_q && fcntrl.extent == kr_q && ignore == 0)
		{
		  struct struct_scr_field *fprop;
		  fprop = (struct struct_scr_field *) (A4GL_ll_get_field_userptr (sio->currentfield));
		  A4GL_recall_field (fprop->tabname, fprop->colname, 1, 1, 0);
		  new_state = 0;
		  rval = -1;
		  ignore = 1;
		}

	      new_state = 50;
	      rval = -1;

	      if (!ignore)
		{
		  int r;
		  struct struct_scr_field *fprop = 0;
		  fprop = (struct struct_scr_field *) (A4GL_ll_get_field_userptr (sio->currentfield));
		  r = A4GL_proc_key_input (fcntrl.extent, sio->currform->form, sio);
		  if (fprop->datatype == DTYPE_BYTE || fprop->datatype == DTYPE_TEXT)
		    {
		      if (r == 0)
			{
			  new_state = 0;
			}
		    }

		}
	    }
	}





      if (fcntrl.state == 50)
	{
	  struct struct_scr_field *fprop;
	  int has_picture = 0;
	  char *picture = 0;
	  int ok = 0;
	  new_state = 10;
	  A4GL_assertion (sio->currentfield == 0, "No current field");
	  fprop = (struct struct_scr_field *) (A4GL_ll_get_field_userptr (sio->currentfield));
	  A4GL_assertion (fprop == 0, "No fprop");

	  A4GL_debug ("Checking key state.. %d", fcntrl.extent);
	  if (A4GL_has_str_attribute (fprop, FA_S_PICTURE))
	    {
	      has_picture = 1;
	      picture = A4GL_get_str_attribute (fprop, FA_S_PICTURE);
	    }
	  if (sio->mode == MODE_CONSTRUCT)
	    has_picture = 0;
	  if (fcntrl.extent >= 0 && fcntrl.extent <= 255
	      && ((a_isprint (fcntrl.extent) || fcntrl.extent == 1 || fcntrl.extent == 4)))
	    {
	      int use_dtype;
	      if (sio->mode == MODE_CONSTRUCT)
		{
		  use_dtype = fprop->datatype & DTYPE_MASK;
		}
	      else
		{
		  use_dtype = sio->vars[sio->curr_attrib].dtype & DTYPE_MASK;
		}

	      if (A4GL_LL_get_carat (sio->currform->form) == 0 && !has_picture
		  && !A4GL_fprop_flag_get (sio->currentfield, FLAG_MOVED_IN_FIELD))
		{
		  switch (use_dtype)
		    {
		    case DTYPE_SMINT:
		    case DTYPE_INT:
		    case DTYPE_SERIAL:
		    case DTYPE_FLOAT:
		    case DTYPE_DATE:
		    case DTYPE_SMFLOAT:
		    case DTYPE_DECIMAL:
		    case DTYPE_MONEY:


		      A4GL_LL_int_form_driver (sio->currform->form, AUBIT_REQ_CLR_EOF);
		      A4GL_debug ("Clear to end of field because of datatype");
		    }
		}
	      A4GL_debug ("SETTING FLAGS ");
	      A4GL_fprop_flag_set (sio->currentfield, FLAG_FIELD_TOUCHED);



	      if (has_picture)
		{
		  int i;
		  int key;
		  void *mform;
		  mform = sio->currform->form;
		  i = A4GL_LL_get_carat (mform);
		  ok = 1;
		  key = fcntrl.extent;

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
		  if (picture[i] != 'X' && picture[i] != '#' && picture[i] != 'A')
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
		  struct struct_scr_field *fprop;
		  char fb[2000];
		  int last_place = 0;
		  int this_place = 0;
		  int k;
		  construct_not_added = 0;
		  construct_not_moved = 0;

		  k = fcntrl.extent;
		  strcpy (fb, A4GL_LL_field_buffer (sio->currentfield, 0));
		  last_place = A4GL_LL_get_carat (sio->currform->form);

		  fprop = (struct struct_scr_field *) (A4GL_ll_get_field_userptr (sio->currentfield));
		  if (fprop)
		    {
		      if (A4GL_has_bool_attribute (fprop, FA_B_DOWNSHIFT) && a4gl_isupper (k) && a4gl_isalpha (k))
			{
			  k = a4gl_tolower (k);
			}
		      if (A4GL_has_bool_attribute (fprop, FA_B_UPSHIFT) && a4gl_islower (k) && a4gl_isalpha (k))
			{
			  k = a4gl_toupper (k);
			}
		    }

		  A4GL_LL_int_form_driver (sio->currform->form, k);
		  A4GL_LL_int_form_driver (sio->currform->form, AUBIT_REQ_VALIDATION);

		  if (strcmp (fb, A4GL_LL_field_buffer (sio->currentfield, 0)) == 0)
		    {		// its the same !
		      A4GL_debug ("No difference : %s %s\n", fb, A4GL_LL_field_buffer (sio->currentfield, 0));
		      if (k != ' ')
			{
			  construct_not_added = 1;
			}
		    }

		  if (this_place == last_place)
		    {
		      construct_not_moved = 1;
		    }

		  A4GL_debug ("construct_not_added=%d construct_not_moved=%d", construct_not_added, construct_not_moved);
		}



	      if (has_picture && ok)
		{
		  void *mform;
		  mform = sio->currform->form;
		  if (strchr ("A#X", picture[A4GL_LL_get_carat (mform)]) == 0 && picture[A4GL_LL_get_carat (mform)])
		    do_key_move ('R', sio, fcntrl.extent, has_picture, picture);
		}

	    }
	  if (A4GL_fprop_flag_get (sio->currentfield, FLAG_MOVING_TO_FIELD))
	    {
	      // This is the first bit - this key stroke has moved us to this field..
	      A4GL_fprop_flag_clear (sio->currentfield, FLAG_MOVING_TO_FIELD);
	    }
	  else
	    {
	      A4GL_fprop_flag_set (sio->currentfield, FLAG_MOVED_IN_FIELD);
	    }

	  rval = -1;
	}


      if (fcntrl.state == 10)
	{
	  struct struct_scr_field *fprop;
	  new_state = 5;

	  rval = -1;


	  if (fcntrl.extent >= 28 && fcntrl.extent <= 255)
	    {
	      fprop = (struct struct_scr_field *) (A4GL_ll_get_field_userptr (sio->currentfield));

	      if (A4GL_has_bool_attribute (fprop, FA_B_AUTONEXT) && !A4GL_has_bool_attribute (fprop, FA_B_WORDWRAP))
		{
		  void *curses_form;
		  curses_form = sio->currform->form;
		  A4GL_debug ("CARAT=%d", A4GL_LL_get_carat (curses_form));
		  if ((void *) A4GL_LL_current_field (curses_form) != sio->currentfield || A4GL_LL_get_carat (curses_form) == 0)
		    {

		      if (A4GL_get_dbscr_inputmode () == 0 && A4GL_curr_metric_is_used_last_s_screenio (sio, sio->currentfield))
			{

			  A4GL_add_to_control_stack (sio, FORMCONTROL_EXIT_INPUT_OK, 0, 0, 0);
			}
		      else
			{
			  A4GL_debug ("I changed fields from %p to %p", sio->currentfield, A4GL_LL_current_field (curses_form));
			  A4GL_debug_print_field_opts (sio->currentfield);
			  A4GL_debug_print_field_opts (A4GL_LL_current_field (curses_form));
			  A4GL_LL_set_current_field (curses_form, sio->currentfield);
			  A4GL_newMovement (sio, sio->curr_attrib + 1);
			}




		    }

		}
	    }

	}

      if (fcntrl.state == 5)
	{

	  if (sio->mode == MODE_CONSTRUCT && last_key_code != A4GLKEY_CANCEL)
	    {
	      struct s_form_dets *form;
	      char rbuff[1024];
	      int w;
	      memset (rbuff, 0, sizeof (rbuff));
	      if (sio->constr[sio->curr_attrib].value)
		{
		  strcpy (rbuff, sio->constr[sio->curr_attrib].value);
		}
	      else
		{
		  strcpy (rbuff, A4GL_LL_field_buffer (sio->currentfield, 0));
		}

	      A4GL_trim (rbuff);
	      form = sio->currform;

	      w = form->fileform->metrics.metrics_val[A4GL_get_metric_for (form, form->currentfield)].w;
	      A4GL_debug
		("CONSTRUCT - do we need a large window : '%s' gfw=%d strlen=%d w=%d",
		 rbuff, A4GL_get_field_width (sio->currentfield), strlen (rbuff), w);
	      if (strlen (rbuff) >= w)
		{
		  struct struct_scr_field *fprop;
		  int k;
		  void *f;
		  int lm;
		  int this_place;
		  void *cf;
		  char rval[10000]="";


	          fprop = (struct struct_scr_field *) (A4GL_ll_get_field_userptr (sio->currentfield));
		  lm = A4GL_LL_get_carat (sio->currform->form);
		  A4GL_LL_set_field_buffer (sio->currentfield, 0, rbuff, 0);
		  while (A4GL_LL_get_carat (sio->currform->form) < lm)
		    {
		      A4GL_LL_int_form_driver (sio->currform->form, AUBIT_REQ_NEXT_CHAR);
		      A4GL_LL_int_form_driver (sio->currform->form, AUBIT_REQ_VALIDATION);
		    }
		  cf = sio->currentfield;

		  this_place = A4GL_LL_get_carat (sio->currform->form) + construct_not_moved;
		  //A4GL_error_nobox("CONSTRUCT BY KEY",0);
		  f =
		    A4GL_LL_construct_large (rbuff, (void *) evt,
					     fcntrl.extent, this_place, "[",
					     "]",
					     UILIB_A4GL_get_curr_width (),
					     UILIB_A4GL_get_curr_height (),
					     A4GL_getcomment_line (), A4GL_get_currwin (), UILIB_A4GL_iscurrborder ());
		  while (A4GL_construct_large_loop (f, evt, fprop));
		  strcpy (rbuff, A4GL_LL_construct_large_finished (f));
		  strcpy (rval, A4GL_LL_construct_large_finished (f));
		  A4GL_comments (0);
		  k = construct_last_key;
		  if (k == A4GLKEY_CANCEL)
		    {
		      A4GL_add_to_control_stack (sio, FORMCONTROL_EXIT_INPUT_ABORT, 0, 0, k);
		    }
		  else
		    {
		      if (A4GL_has_bool_attribute (fprop, FA_B_DOWNSHIFT) && a4gl_isupper (k) && a4gl_isalpha (k))
			{
			  k = a4gl_tolower (k);
			}
		      if (A4GL_has_bool_attribute (fprop, FA_B_UPSHIFT) && a4gl_islower (k) && a4gl_isalpha (k))
			{
			  k = a4gl_toupper (k);
			}

		      A4GL_add_to_control_stack (sio, FORMCONTROL_KEY_PRESS, 0, 0, k);
		      A4GL_LL_set_field_buffer (sio->currentfield, 0, rbuff, 0);

		      if (sio->constr[sio->curr_attrib].value)
			{
			  // get rid...
			  free (sio->constr[sio->curr_attrib].value);
			  sio->constr[sio->curr_attrib].value = 0;
			}
		      if (strlen (rval) >= w)
			{
			  A4GL_debug ("Its too long for a normal buffer - setting value");
			  sio->constr[sio->curr_attrib].value = strdup (rval);
			  A4GL_LL_set_field_buffer (sio->currentfield, 0, rval, 0);
			}
		      else
			{
			  A4GL_debug ("It fits into normal buffer - using that %s", rbuff);
			  // It fits in a normal buffer...
			  A4GL_LL_set_field_buffer (sio->currentfield, 0, rval, 0);
			}

		    }
		  sio->currentfield = cf;
		}
	      else
		{
		  if (sio->constr[sio->curr_attrib].value)
		    {
		      // get rid...
		      free (sio->constr[sio->curr_attrib].value);
		      sio->constr[sio->curr_attrib].value = 0;
		    }

		}
	    }

	  new_state = 2;
	  rval = -1;
	}


      if (fcntrl.state == 2)
	{
	  rval = -1;
	  new_state = 0;
	}




    }


  if (fcntrl.op == FORMCONTROL_BEFORE_FIELD)
    {
      struct struct_scr_field *fprop;
      int attr;
      A4GL_debug ("FORM_BEFORE_void - state=%d", fcntrl.state);

      if (fcntrl.state == 99)
	{
	  new_state = 50;
	  ptr_movement = (struct s_movement *) fcntrl.parameter;
	  sio->curr_attrib = ptr_movement->attrib_no;
	  sio->currentfield = sio->field_list[sio->curr_attrib];
	  A4GL_assertion (sio->currentfield == 0, "Cant set current field");

	  //A4GL_push_long ((long) sio->field_list[sio->curr_attrib]);
	  //A4GL_push_char (fcntrl.field_name);

	  A4GL_set_infield_from_parameter ((long) sio->field_list[sio->curr_attrib]);
	  if (A4GL_has_event_for_field (A4GL_EVENT_BEFORE_FIELD, fcntrl.field_name, evt))
	    {
	      rval = A4GL_has_event_for_field (A4GL_EVENT_BEFORE_FIELD, fcntrl.field_name, evt);
	      A4GL_debug ("Set rval=%d\n", rval);
	    }
	}

      if (fcntrl.state == 50)
	{
	  sio->currentfield = sio->field_list[sio->curr_attrib];
	  A4GL_LL_set_current_field (sio->currform->form, sio->currentfield);
	  sio->currform->currentfield = sio->currentfield;
	  A4GL_LL_set_carat (sio->currform->form);
	  fprop = (struct struct_scr_field *) (A4GL_ll_get_field_userptr (sio->currentfield));
	  attr = A4GL_determine_attribute (FGL_CMD_INPUT, sio->attrib, fprop, (char *) A4GL_LL_field_buffer (sio->currentfield, 0));
	  if (attr != 0)
	    A4GL_set_field_attr_with_attr (sio->currentfield, attr, FGL_CMD_INPUT);
	  if (sio->mode != MODE_CONSTRUCT)
	    {
	      char *picture = 0;
	      int has_picture = 0;
	      if (A4GL_has_str_attribute (fprop, FA_S_PICTURE))
		{
		  char *ptr;
		  int a;
		  int w;

		  A4GL_set_init_value (sio->currentfield,
				       sio->vars[sio->curr_attrib].ptr,
				       sio->vars[sio->curr_attrib].dtype + ENCODE_SIZE (sio->vars[sio->curr_attrib].size));

		  A4GL_debug ("Set value to '%s'", A4GL_LL_field_buffer (sio->currentfield, 0));
		  w = A4GL_get_field_width (sio->currentfield);
		  has_picture = 1;
		  picture = A4GL_get_str_attribute (fprop, FA_S_PICTURE);
		  ptr = acl_malloc2 (w + 1);

		  strcpy (ptr, A4GL_LL_field_buffer (sio->currentfield, 0));
		  ptr[w] = 0;

		  for (a = 0; a < strlen (picture); a++)
		    {
		      if (a > w)
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
		  //A4GL_set_init_value (sio->currentfield, ptr, sio->vars[sio->curr_attrib].dtype+ENCODE_SIZE(sio->vars[sio->curr_attrib].size));
		  A4GL_set_init_value (sio->currentfield, ptr, 0);
		  if (picture[0] != '9' && picture[0] != '#' && picture[0] != 'X')
		    {
		      if (strchr (&picture[1], '9') || strchr (&picture[1], '#') || strchr (&picture[1], 'X'))
			{
			  // Theres no point in moving across if theres
			  // nothing to move to
			  do_key_move ('R', sio, 0, 1, picture);
			}
		    }

		  A4GL_debug ("XYX Set field : %s", ptr);
		  acl_free (ptr);	// ? @todo....
		}
	      else
		{
		  A4GL_set_init_value (sio->currentfield,
				       sio->vars[sio->curr_attrib].ptr,
				       sio->vars[sio->curr_attrib].dtype + ENCODE_SIZE (sio->vars[sio->curr_attrib].size));
		}

	      if (has_picture)
		{
		  A4GL_LL_int_form_driver (sio->currform->form, AUBIT_REQ_OVL_MODE);	// Always in overwrite mode in a picture...
		}


	    }

	  A4GL_comments (fprop);
	  //if ((fprop->flags & 1))

	  A4GL_fprop_flag_clear (sio->currentfield, FLAG_MOVED_IN_FIELD);
	  A4GL_fprop_flag_set (sio->currentfield, FLAG_MOVING_TO_FIELD);


	  new_state = 0;
	  A4GL_debug ("Setting rval to -1");
	}
    }


  if (fcntrl.op == FORMCONTROL_AFTER_FIELD)
    {

      int ffc_rval;
      struct struct_scr_field *fprop;
      int attr;
      if (sio->mode != MODE_CONSTRUCT)
	ffc_rval = A4GL_form_field_chk (sio, -1);
      else
	{
	  int daf;
	  ffc_rval = A4GL_form_field_constr (sio, -1);
	  daf = A4GL_do_after_field (sio->currentfield, sio);
	  if (!daf)
	    ffc_rval = -4;
	}


      A4GL_debug ("form_Field_chk returns %d\n", a);

      if (ffc_rval != -4)
	{
	  int really_ok = 0;
	  new_state = 0;
	  fprop = (struct struct_scr_field *) (A4GL_ll_get_field_userptr (sio->currentfield));
	  if (sio->mode != MODE_CONSTRUCT)
	    {
	      //int has_picture=0;
	      char *picture;
	      int field_no;
	      char buff[10024];
	      field_no = sio->curr_attrib;
	      if (sio->currentfield == 0)
		{
		  A4GL_fgl_die_with_msg (1, "No current field");
		}

	      strncpy (buff, A4GL_LL_field_buffer (sio->currentfield, 0), sizeof (buff));
	      buff[10023] = 0;
	      if (strlen (buff) >= 10023)
		{
		  A4GL_fgl_die_with_msg (1, "Internal error or string too long");
		}


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

	      if (A4GL_fprop_flag_get (sio->currentfield, FLAG_FIELD_TOUCHED))
		{
		  A4GL_trim (buff);

		  if (strlen (buff))
		    {
		      char buff2[10024];
		      A4GL_debug ("Field is not null");
		      strcpy (buff2, (char *) A4GL_fld_data_ignore_format (fprop, buff));
		      strcpy (buff, buff2);
		      A4GL_push_char (buff);
		    }
		  else
		    {
		      A4GL_debug ("Field is null");
		      A4GL_push_null (DTYPE_CHAR, 0);
		    }


		  A4GL_debug ("Calling A4GL_pop_var2 : %p dtype=%d size=%d",
			      sio->vars[field_no].ptr, sio->vars[field_no].dtype, sio->vars[field_no].size);
		  really_ok = 1;


		  A4GL_pop_var2 (sio->vars[field_no].ptr, sio->vars[field_no].dtype, sio->vars[field_no].size);



		  really_ok = 1;
		  A4GL_trim (buff);
		  if (strlen (buff) && A4GL_isnull (sio->vars[field_no].dtype, sio->vars[field_no].ptr))
		    really_ok = 0;

		  if (!A4GL_conversion_ok (-1))
		    really_ok = 0;

		  if ((sio->vars[field_no].dtype == DTYPE_INT
		       || sio->vars[field_no].dtype == DTYPE_SMINT
		       || sio->vars[field_no].dtype == DTYPE_SERIAL) && strchr (buff, A4GL_get_convfmts ()->ui_decfmt.decsep))
		    {
		      really_ok = 0;
		    }


		  if (really_ok == 0)
		    {
		      //
		      A4GL_comments (fprop);
		      A4GL_error_nobox (acl_getenv ("FIELD_ERROR_MSG"), 0);

		      if (A4GL_isyes (acl_getenv ("A4GL_CLR_FIELD_ON_ERROR")))
			{
			  A4GL_fprop_flag_clear (sio->currform->currentfield, FLAG_MOVED_IN_FIELD);
			  A4GL_fprop_flag_set (sio->currform->currentfield, FLAG_MOVING_TO_FIELD);

			  A4GL_clr_field (sio->currform->currentfield);
			}
		      else
			{
			  if (A4GL_isyes (acl_getenv ("FIRSTCOL_ONERR")))
			    {
			      A4GL_fprop_flag_clear (sio->currform->currentfield, FLAG_MOVED_IN_FIELD);
			      A4GL_fprop_flag_set (sio->currform->currentfield, FLAG_MOVING_TO_FIELD);
			      A4GL_LL_int_form_driver (sio->currform->form, AUBIT_REQ_BEG_FIELD);
			    }

			}


		      A4GL_LL_set_current_field (sio->currform->form, sio->currform->currentfield);
		      A4GL_init_control_stack (sio, 0);
		      return -1;
		    }





		  A4GL_push_char (buff);
		  A4GL_debug ("Calling display_field_contents");


		  A4GL_display_field_contents (sio->currentfield, sio->vars[field_no].dtype + ENCODE_SIZE (sio->vars[field_no].size), sio->vars[field_no].size, sio->vars[field_no].ptr);	// MJA 2306

		  fprop = (struct struct_scr_field *) (A4GL_ll_get_field_userptr (sio->currentfield));
		  attr = A4GL_determine_attribute (FGL_CMD_INPUT, sio->attrib, fprop, A4GL_LL_field_buffer (sio->currentfield, 0));
		  if (attr != 0)
		    A4GL_set_field_attr_with_attr (sio->currentfield, attr, FGL_CMD_INPUT);
		}
	    }


	  //A4GL_push_long ((long) sio->currentfield);
	  //A4GL_push_char (fcntrl.field_name);

	  A4GL_set_infield_from_parameter ((long) sio->currentfield);
	  //last_field_name=sio->fcntrl[a].field_name;


	  if (A4GL_has_event_for_field (A4GL_EVENT_AFTER_FIELD, fcntrl.field_name, evt))
	    {
	      rval = A4GL_has_event_for_field (A4GL_EVENT_AFTER_FIELD, fcntrl.field_name, evt);
	      A4GL_debug ("Set rval=%d\n", rval);
	    }


	}
      else
	{
	  if (A4GL_isyes (acl_getenv ("FIRSTCOL_ONERR_INCL")))
	    {
	      A4GL_LL_int_form_driver (sio->currform->form, AUBIT_REQ_BEG_FIELD);
	    }


	  A4GL_init_control_stack (sio, 0);
	  return -1;
	}
    }



  if (new_state != 0 && fcntrl.op != 0)
    {
      if (fcntrl.state == new_state)
	{
	  A4GL_debug ("internal error - state=%d op=%d (%s) @ %d", new_state, fcntrl.op, ops[fcntrl.op], a);
	  A4GL_exitwith ("Internal error - no change in state ");
	  return -1;
	}
      A4GL_debug ("Setting input control state to %d", new_state);
      sio->fcntrl[a].state = new_state;
    }
  else
    {
      A4GL_debug ("Popping type %d (%s) off control stack @ %d", sio->fcntrl[a].op, ops[sio->fcntrl[a].op], a);

      if (a != sio->fcntrl_cnt - 1)
	{
	  A4GL_debug ("INTERNAL ERROR - pop state with added new one %d %d", sio->fcntrl[a].op, sio->fcntrl[a].state);
	  A4GL_exitwith ("Internal error - bad change in state ");
	  return -1;
	}

      sio->fcntrl_cnt--;
      if (sio->fcntrl[a].parameter)
	{
	  acl_free (sio->fcntrl[a].parameter);
	}
    }
  A4GL_debug ("Returning rval=%d\n", rval);
  return rval;
}


int
UILIB_A4GL_req_field_input (void *sv, char type, va_list * ap)
{
  struct s_screenio *s;
/* fieldname + = next - = previous */
  int a;
  void **ptr;
  //char *field_name;
  s = sv;


  if (type == '+')
    {				// Next field next
      A4GL_init_control_stack (s, 0);
      s->currform->currentfield = 0;
      A4GL_newMovement (s, s->curr_attrib + 1);
      return 1;
    }

  if (type == '-')
    {				// Next field previous
      A4GL_init_control_stack (s, 0);
      s->currform->currentfield = 0;
      A4GL_newMovement (s, s->curr_attrib - 1);
      return 1;
    }

  if (type == '0')
    {				// Next field 'current' - used internally
      A4GL_init_control_stack (s, 0);
      //s->currform->currentfield=0;
      //A4GL_newMovement(s,s->curr_attrib-1);
      return 1;
    }


  A4GL_debug ("req_field");

  a = A4GL_gen_field_list (&ptr, s->currform, 1, ap);

  if (a >= 0)
    {
      for (a = 0; a <= s->nfields; a++)
	{
	  if (s->field_list[a] == ptr[0])
	    {
	      A4GL_init_control_stack (s, 0);


	      // How risky is this ?
	      s->currform->currentfield = 0;


	      A4GL_newMovement (s, a);
	      free (ptr);
	      return 1;
	    }
	}
      free (ptr);
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
A4GL_submit_events (void *s, struct aclfgl_event_list *evt)
{
  int a;
  for (a = 0; evt[a].event_type; a++)
    {
      char *p;
      p = evt[a].field;
      if (p == 0)
	p = "";
      A4GL_LL_submit_event (a, s, evt[a].event_type, evt[a].block, evt[a].keycode, p);
    }
}

int
UILIB_A4GL_form_loop_v2 (void *vs, int init, void *vevt)
{
  int a;
  a = -1;
  ActivateToolbar ("Input", vevt, vs);
  while (1)
    {
      a = internal_A4GL_form_loop_v2 (vs, init, vevt);
      A4GL_debug ("internal_A4GL_form_loop_v2 returns %d\n", a);

      if (init || a != -1)
	break;
    }
  ActivateToolbar (0, 0, 0);
  return a;

}

/**
 * 4GL CALL
 * @todo Describe function
 */
int
internal_A4GL_form_loop_v2 (void *vs, int init, void *vevt)
{
  struct s_form_dets *form;
  int a;
  struct s_screenio *s;
  struct aclfgl_event_list *evt;
  //int LL_int_form_driver_ret = 0;
  struct struct_scr_field *fprop;
  struct struct_metrics *metrics;
  void *mform;
  int blk;
  evt = vevt;
  s = vs;
  if (init == 1)
    {
      A4GL_debug ("------------------------------------------------------");
      s->currform->currentfield = 0;
      A4GL_LL_init_form (s->currform->form);
      //s->currform->curcol=0;

      abort_pressed = 0;
    }
  form = s->currform;
  A4GL_set_abort (0);
  //A4GL_debug ("form_loop0..  currentfield=%p status = %d", form->currentfield,field_status(form->currentfield));
  //

  if (form != (struct s_form_dets *) UILIB_A4GL_get_curr_form (0))
    {

      A4GL_make_window_with_this_form_current (form);
    }

  if (form != (struct s_form_dets *) UILIB_A4GL_get_curr_form (1))
    {
      A4GL_debug ("form=%p curr_form=%p", form, UILIB_A4GL_get_curr_form (1));
      A4GL_exitwith ("Input form is not current");
      return 0;
    }

  mform = form->form;
  A4GL_LL_screen_update ();

  if (s->mode == MODE_CONSTRUCT)
    {
	int cnt;
      if (init)
        {
          for (cnt = 0; cnt <= s->nfields; cnt++)
            {
              s->constr[cnt].fldbuf = 0;
            }
        }
      else
        {
          for (cnt = 0; cnt <= s->nfields; cnt++)
            {
              if (s->constr[cnt].fldbuf == 0)
                continue;
              if (strcmp (s->constr[cnt].fldbuf, A4GL_LL_field_buffer (s->field_list[cnt], 0)) != 0)
                {               // They've change the field buffer..
                  if (s->constr[cnt].value)
                    {
                      free (s->constr[cnt].value);
                      s->constr[cnt].value = 0;
                    }
                }
              free (s->constr[cnt].fldbuf);
            }
        }
    }


  if (init)
    {
      A4GL_init_control_stack (s, 1);
      s->curr_attrib = 0;
      s->currentfield = 0;
      A4GL_newMovement (s, 0);
      A4GL_clr_evt_timeouts (evt);
      A4GL_add_to_control_stack (s, FORMCONTROL_BEFORE_INPUT, 0, 0, 0);
      A4GL_submit_events (s, evt);
    }
  else
    {
      //A4GL_LL_activate_events(s);
    }

  if (A4GL_has_something_on_control_stack (s))
    {
      int rval;
      rval = process_control_stack_single (s, evt);
      A4GL_debug ("Control stack - he say %d", rval);
      return rval;
    }


  //if (s->mode != MODE_CONSTRUCT)
  //a = A4GL_form_field_chk (s, 0);
  //else
  //a = A4GL_form_field_constr (s, 0);


  //pos_form_cursor (mform);

  fprop = (struct struct_scr_field *) A4GL_ll_get_field_userptr (A4GL_LL_current_field (mform));
  metrics = &form->fileform->metrics.metrics_val[A4GL_get_curr_metric (form)];

  if (metrics && (long) metrics != -1)
    {
      A4GL_LL_set_form_page (mform, metrics->scr - 1);
    }

//if (current_field(mform)!=form->currentfield) {
  //A4GL_debug("CHANGE OF FIELD\n");
//}


// Wait for a key..
  fprop = (struct struct_scr_field *) A4GL_ll_get_field_userptr (A4GL_LL_current_field (mform));


  A4GL_mja_set_current_field (mform, form->currentfield);

  while (1)
    {
      blk = A4GL_has_evt_timeout (evt);
      if (blk)
	{
	  return blk;
	}

      A4GL_set_active_fields (s, evt);
      A4GL_LL_activate_events (s);
      A4GL_LL_set_carat (mform);

      a = A4GL_getch_win (1, "Input");
      if (a == A4GLKEY_EVENT)
	{
	  A4GL_debug ("input fired event...");
	  A4GL_evt_not_idle (evt);
	  return A4GL_LL_get_triggered_event ();
	}

      if (a != 0 && a != -1)
	{
	  A4GL_evt_not_idle (evt);
	  break;
	}
      if (abort_pressed)
	{
	  break;
	}
    }

  if (a == A4GLKEY_EVENT)
    {
      int rval;
      rval = A4GL_LL_get_triggered_event ();
      return rval;
    }

  if (A4GL_is_special_key (a, A4GLKEY_ACCEPT))
    {
      a = A4GLKEY_ACCEPT;
      A4GL_set_last_key (A4GLKEY_ACCEPT);
    }

  if (a != 0)
    {
      s->processed_onkey = a;
      m_lastkey = a;
      A4GL_set_last_key (a);
      if (a)
	A4GL_clr_error_nobox ("A4GL_form_loop");

      if (abort_pressed)
	{
	  a = A4GLKEY_INTERRUPT;	// A4GL_key_val ("INTERRUPT");
	  A4GL_set_last_key (a);
	  abort_pressed = 0;
	}

      //A4GL_debug ("form_loop1..  currentfield=%p status = %d", form->currentfield,field_status(form->currentfield));

// Process the key..


      if (fprop != 0)
	{
	  A4GL_debug ("Downshift?");
	  if (A4GL_has_bool_attribute (fprop, FA_B_DOWNSHIFT) && a4gl_isupper (a) && a4gl_isalpha (a))
	    {
	      a = a4gl_tolower (a);
	    }
	  A4GL_debug ("Upshift ?");
	  if (A4GL_has_bool_attribute (fprop, FA_B_UPSHIFT) && a4gl_islower (a) && a4gl_isalpha (a))
	    {
	      a = a4gl_toupper (a);
	    }
	}



      if (a)
	{
	  A4GL_add_to_control_stack (s, FORMCONTROL_KEY_PRESS, 0, 0, a);
	}
    }
  return -1;
}




static void
do_key_move (char lr, struct s_screenio *s, int a, int has_picture, char *picture)
{
  int at_last = 0;
  int at_first = 0;
  void *f;
  void *mform;
  int c;
  mform = s->currform->form;
  f = s->currentfield;

  c = A4GL_LL_get_carat (mform);

  if (c == 0)
    {
      at_first = 1;
    }

  if (c == A4GL_get_field_width (A4GL_LL_current_field (mform)) - 1)
    {
      at_last = 1;
      A4GL_debug ("AT LAST..... XYXYXY");
    }


  A4GL_debug ("carat=%d fw=%d first=%d last=%d field=%p", c,
	      A4GL_get_field_width (A4GL_LL_current_field (mform)), at_first, at_last, A4GL_LL_current_field (mform));

  if (lr == 'L')
    {
      if (at_first)
	{
	  if (s->curr_attrib)
	    {
	      A4GL_newMovement (s, s->curr_attrib - 1);	//  go to previous field
	      return;
	    }

	}
      else
	{
	  A4GL_LL_int_form_driver (mform, AUBIT_REQ_PREV_CHAR);	// go to previous character
	}
    }

  if (lr == 'R')
    {
      if (at_last)
	{			// Acts like KEY_DOWN at last position in the field
	  A4GL_debug ("AT LAST");
	  if (A4GL_get_dbscr_inputmode () == 0 && A4GL_curr_metric_is_used_last_s_screenio (s, f))
	    {
	      A4GL_add_to_control_stack (s, FORMCONTROL_EXIT_INPUT_OK, 0, 0, a);
	      return;
	    }
	  else
	    {
	      A4GL_newMovement (s, s->curr_attrib + 1);
	      return;
	    }
	}
      else
	{
	  A4GL_LL_int_form_driver (mform, AUBIT_REQ_NEXT_CHAR);
	}
    }
  A4GL_LL_int_form_driver (s->currform->form, AUBIT_REQ_VALIDATION);


  if (has_picture)
    {
      int newpos;
      void *mform;
      mform = s->currform->form;
      newpos = A4GL_LL_get_carat (mform);
      if (strchr ("A#X", picture[newpos]))
	return;
      do_key_move (lr, s, a, has_picture, picture);
    }
  return;

}

/**
 *
 * @todo Describe function
 */
int
A4GL_proc_key_input (int a, void *mform, struct s_screenio *s)
{
  void *f;
  struct s_form_attr *form;
  struct struct_scr_field *fprop;
  struct s_form_dets *fd;
  int has_picture = 0;
  int isWordWrap = 0;
  int c;
  char *picture = 0;
  int isBlob = 0;


  int at_first = 0;
  int at_last = 0;

  c = A4GL_LL_get_carat (mform);
  if (c == 0)
    {
      at_first = 1;
    }
  if (c == A4GL_get_field_width (A4GL_LL_current_field (mform)) - 1)
    {
      at_last = 1;
    }

  A4GL_debug ("carat=%d fw=%d first=%d last=%d field=%p", c,
	      A4GL_get_field_width (A4GL_LL_current_field (mform)), at_first, at_last, A4GL_LL_current_field (mform));

  //int npage;
  fd = A4GL_ll_get_form_userptr (mform);
  form = &fd->form_details;
  do_input_nowrap = 0;

  A4GL_debug ("proc_key .... %d", a);
  f = A4GL_LL_current_field (mform);
  fprop = (struct struct_scr_field *) (A4GL_ll_get_field_userptr (f));
  A4GL_debug ("Current field=%p\n", f);
  A4GL_assertion (f == 0, "No current field");
  A4GL_assertion (fprop == 0, "No fprop");
  if (fprop->datatype == DTYPE_BYTE || fprop->datatype == DTYPE_TEXT)
    {
      isBlob = 1;
    }

  if (a != 10)
    {
      A4GL_debug ("Getting fprop");
      A4GL_debug ("fprop=%p\n", fprop);

      if (fprop != 0)
	{


	  if (A4GL_has_str_attribute (fprop, FA_S_PICTURE))
	    {
	      has_picture = 1;
	      picture = A4GL_get_str_attribute (fprop, FA_S_PICTURE);
	    }
	  if (s->mode == MODE_CONSTRUCT)
	    has_picture = 0;	/* We don't use the picture in a construct... */


	  A4GL_debug ("Downshift?");
	  if (A4GL_has_bool_attribute (fprop, FA_B_DOWNSHIFT) && a4gl_isupper (a) && a4gl_isalpha (a))
	    {
	      a = a4gl_tolower (a);
	    }
	  A4GL_debug ("Upshift ?");
	  if (A4GL_has_bool_attribute (fprop, FA_B_UPSHIFT) && a4gl_islower (a) && a4gl_isalpha (a))
	    {
	      a = a4gl_toupper (a);
	    }
	}

    }

  if (isBlob)
    {
      char buff[1024];
      char filename[2000] = "blah";
      int reloadblob = 0;
      struct fgl_int_loc *blob;

      blob = s->vars[s->curr_attrib].ptr;
      if (blob->where != 'F' && blob->where != 'M')
	{
	  A4GL_exitwith ("Blob not located");
	  return 0;
	}

      if (blob->where != 'F')
	{
	  FILE *fwr;
	  strcpy (filename, tmpnam (NULL));
	  fwr = fopen (filename, "w");
	  fwrite (blob->ptr, blob->memsize, 1, fwr);
	  fclose (fwr);
	  reloadblob = 1;
	}
      else
	{
	  strcpy (filename, blob->filename);
	}
      if (a == '!')
	{
	  char *program = 0;
	  // start program...
	  if (A4GL_has_str_attribute (fprop, FA_S_PROGRAM))
	    {
	      program = A4GL_get_str_attribute (fprop, FA_S_PROGRAM);
	    }
	  if (program == 0)
	    program = "vi";
	  if (strstr (program, "%s"))
	    {
	      sprintf (buff, program, filename);
	    }
	  else
	    {
	      sprintf (buff, "%s %s", program, filename);
	    }
	  UILIB_A4GL_gotolinemode ();
	  system (buff);
	  A4GL_chkwin ();
	  if (reloadblob)
	    {
	      int fl;
	      FILE *fre;
	      fre = fopen (filename, "r");
	      free (blob->ptr);
	      blob->ptr = 0;
	      fseek (fre, 0, SEEK_END);
	      fl = ftell (fre);
	      rewind (fre);
	      blob->ptr = malloc (fl + 1);
	      blob->memsize = fl;
	      fread (blob->ptr, 1, fl, fre);
	      //blob->ptr[fl]=0;
	    }
	  return 0;
	}
      else
	{
	  if (a >= 32 && a < 255)
	    {
	      A4GL_error_nobox (acl_getenv ("FIELD_BLOB_PLING_MSG"), 0);
	      return 0;
	    }
	}
    }

  A4GL_debug ("Got key %d", a);


  if (a == A4GLKEY_ACCEPT)
    {
      A4GL_add_to_control_stack (s, FORMCONTROL_EXIT_INPUT_OK, 0, 0, a);
      return -1;
    }

  if (A4GL_has_bool_attribute (fprop, FA_B_WORDWRAP))
    {
      if (isBlob)
	isWordWrap = 0;
      else
	isWordWrap = 1;

    }


  switch (a)
    {
    case 18:
      A4GL_LL_screen_redraw ();

      break;

    case A4GLKEY_INTERRUPT:
      A4GL_add_to_control_stack (s, FORMCONTROL_EXIT_INPUT_ABORT, 0, 0, a);
      break;


      //case 26:
      //return 0; ^Z ?

    case 127:
    case 8:
    case A4GLKEY_DL:
    case A4GLKEY_BACKSPACE:
      if (!isBlob)
	{

	  if (!has_picture)
	    {
	      A4GL_debug ("Flags|=FLAG_FIELD_TOUCHED");
	      A4GL_fprop_flag_set (f, FLAG_FIELD_TOUCHED);	// Set the field status flag

	      A4GL_LL_int_form_driver (mform, AUBIT_REQ_DEL_PREV);
	    }
	  else
	    {			// Just like A4GLKEY_LEFT.....
	      do_key_move ('L', s, a, has_picture, picture);
	    }
	}
      break;

    case A4GLKEY_DC:
    case 24:
      if (!isBlob)
	{

	  if (!has_picture)
	    {
	      A4GL_LL_int_form_driver (mform, AUBIT_REQ_DEL_CHAR);
	    }
	  else
	    {
	      A4GL_error_nobox (acl_getenv ("FIELD_PICTURE_MSG"), 0);
	    }
	}
      break;

    case A4GLKEY_SHTAB:
    case A4GLKEY_UP:

      if (isWordWrap)
	{
	  int cHeight;
	  //int curPos;
	  int r;
	  cHeight = A4GL_LL_get_carat_y (mform);
	  r = A4GL_LL_get_carat (mform);
	  if (cHeight > 0)
	    {
	      A4GL_LL_int_form_driver (mform, AUBIT_REQ_PREV_LINE);
	      while (A4GL_LL_get_carat (mform) < r)
		{
		  A4GL_LL_int_form_driver (mform, AUBIT_REQ_NEXT_CHAR);
		}
	      break;
	    }
	}




      A4GL_debug ("MJA Try to move to previous field : %d\n", s->curr_attrib - 1);
      A4GL_newMovement (s, s->curr_attrib - 1);
      break;


      //case 2:
      //A4GL_debug ("FIELD OPTS : ");
      //A4GL_debug_print_field_opts (s->currentfield);
      //break;


    case '\t':
      if (isWordWrap)
	{
	  // strange handling...
	  int w;
	  int r;
	  int cnt;
	  int cHeight;
	  w = A4GL_get_field_width (f);
	  r = A4GL_LL_get_carat (mform) + 1;
	  while (r % 8 != 0)
	    r++;

	  cHeight = A4GL_LL_get_carat_y (mform);
	  if (r > w)
	    {
	      int fieldHeight;
	      fieldHeight = A4GL_get_field_height (f);
	      A4GL_debug ("fieldHeight=%d cHeight=%d", fieldHeight, cHeight);
	      if (cHeight + 1 < fieldHeight)
		{
		  A4GL_LL_int_form_driver (mform, AUBIT_REQ_NEXT_LINE);
		}
	      else
		{
		  if (A4GL_isyes (acl_getenv ("WAITENDOFWORDWRAP")))
		    {
		      r = w - 1;
		      for (cnt = A4GL_LL_get_carat (mform); cnt < r; cnt++)
			{
			  do_key_move ('R', s, a, has_picture, picture);
			}
		    }
		  else
		    {
		      if (A4GL_get_dbscr_inputmode () == 0 && A4GL_curr_metric_is_used_last_s_screenio (s, f))
			{
			  A4GL_add_to_control_stack (s, FORMCONTROL_EXIT_INPUT_OK, 0, 0, a);
			  return 0;
			}
		      A4GL_debug ("MJA Try to move to next field : %d\n", s->curr_attrib + 1);
		      A4GL_newMovement (s, s->curr_attrib + 1);
		    }
		}
	    }
	  else
	    {
	      for (cnt = A4GL_LL_get_carat (mform); cnt < r; cnt++)
		{
		  do_key_move ('R', s, a, has_picture, picture);
		}
	    }
	  break;

	}
      else
	{
	  if (A4GL_get_dbscr_inputmode () == 0 && A4GL_curr_metric_is_used_last_s_screenio (s, f))
	    {
	      A4GL_add_to_control_stack (s, FORMCONTROL_EXIT_INPUT_OK, 0, 0, a);
	      return 0;
	    }
	  A4GL_newMovement (s, s->curr_attrib + 1);
	}
      break;


    case 13:
    case 10:
      if (A4GL_get_dbscr_inputmode () == 0 && A4GL_curr_metric_is_used_last_s_screenio (s, f))
	{
	  A4GL_add_to_control_stack (s, FORMCONTROL_EXIT_INPUT_OK, 0, 0, a);
	  return 0;
	}
      A4GL_newMovement (s, s->curr_attrib + 1);
      break;


    case A4GLKEY_DOWN:
      if (isWordWrap)
	{
	  int fieldHeight;
	  int cHeight;
	  int r;
	  cHeight = A4GL_LL_get_carat_y (mform);
	  r = A4GL_LL_get_carat (mform);
	  fieldHeight = A4GL_get_field_height (f);
	  A4GL_debug ("fieldHeight=%d cHeight=%d", fieldHeight, cHeight);
	  if (cHeight + 1 < fieldHeight)
	    {
	      A4GL_LL_int_form_driver (mform, AUBIT_REQ_NEXT_LINE);
	      while (A4GL_LL_get_carat (mform) < r)
		{
		  A4GL_LL_int_form_driver (mform, AUBIT_REQ_NEXT_CHAR);
		}
	      break;
	    }

	}


      if (A4GL_get_dbscr_inputmode () == 0 && A4GL_curr_metric_is_used_last_s_screenio (s, f))
	{
	  A4GL_add_to_control_stack (s, FORMCONTROL_EXIT_INPUT_OK, 0, 0, a);
	  return 0;
	}
      A4GL_newMovement (s, s->curr_attrib + 1);
      break;

    case A4GLKEY_HOME:
      if (!isBlob)
	{
	  A4GL_LL_int_form_driver (mform, AUBIT_REQ_BEG_FIELD);
	}
      break;
    case A4GLKEY_END:
      if (!isBlob)
	{
	  A4GL_LL_int_form_driver (mform, AUBIT_REQ_END_FIELD);
	}
      break;


    case A4GLKEY_LEFT:
      if (!isBlob)
	{
	  do_key_move ('L', s, a, has_picture, picture);
	}
      break;

    case A4GLKEY_RIGHT:
      if (!isBlob)
	{
	  do_key_move ('R', s, a, has_picture, picture);
	}
      break;

    case 4:			// Control - D
      if (!has_picture)
	{
	  A4GL_LL_int_form_driver (mform, AUBIT_REQ_CLR_EOF);
	  A4GL_fprop_flag_set (f, FLAG_FIELD_TOUCHED);	// Set the field status flag
	}
      else
	{
	  A4GL_error_nobox (acl_getenv ("FIELD_PICTURE_MSG"), 0);
	}
      break;


    case 1:			// Control - A
      if (!has_picture)
	{
	  form->insmode = form->insmode ? 0 : 1;
	  if (form->insmode)
	    {
	      A4GL_LL_int_form_driver (mform, AUBIT_REQ_INS_MODE);
	      break;
	    }
	  else
	    {
	      A4GL_LL_int_form_driver (mform, AUBIT_REQ_OVL_MODE);
	      break;
	    }
	}
      else
	{
	  A4GL_error_nobox (acl_getenv ("FIELD_PICTURE_MSG"), 0);
	}
      break;

    }


  //A4GL_mja_refresh ();   // removed mja 22/08/2003
  //usleep(100000);
  return -1;
}



void
A4GL_set_init_value (void *f, void *ptr, int dtype)
{
  char *ff;
  int a;
  int fw;

  A4GL_debug ("A4GL_set_init_value %p %x", ptr, dtype);
  if (ptr)
    {
      A4GL_push_param (ptr, dtype);
      A4GL_debug ("Calling display_field_contents");
      A4GL_display_field_contents (f, dtype & DTYPE_MASK, DECODE_SIZE (dtype), ptr);
      return;
    }


  fw = A4GL_get_field_width (f);
  A4GL_assertion (fw == 0, "NO field width");
  A4GL_debug ("field width=%d", fw);
  if (ptr != 0)
    {
      A4GL_push_param (ptr, dtype);
      ff = acl_malloc2 (fw + 1);
      A4GL_pop_char (ff, fw);
    }
  else
    {
      ff = acl_malloc2 (fw + 1);
      for (a = 0; a < fw; a++)
	ff[a] = ' ';
      ff[fw - 1] = 0;
    }

  if ((dtype & DTYPE_MASK) == DTYPE_CHAR)
    {
      A4GL_mja_set_field_buffer (f, 0, ff, ptr);
    }
  else
    {
      A4GL_mja_set_field_buffer (f, 0, ff, 0);
    }
  acl_free (ff);
  A4GL_debug ("Init complete");
}



void
A4GL_mja_set_current_field (void *form, void *field)
{
  A4GL_set_curr_infield ((long) field);
  A4GL_LL_set_current_field (form, field);
  A4GL_LL_set_carat (form);
}


/* same function exists in :

	lib/libui/ui_curses/curslib.c 				as (struct struct_scr_field *fprop)
	lib/libui/ui_highlevel/formcntrl.c (this file) as (struct struct_scr_field *fprop)
	
	lib/libform/form_xdr/readforms.c			as (void *fprop) 
	
	proto is defined in API_form.spec :
		//void A4GL_comments (struct struct_scr_field *fprop); 
		A4GL_comments void* fprop -> void 
	
	
*/
void
A4GL_comments (struct struct_scr_field *fprop)
{
  //char *str;
  int cline;
  char buff[256];
  int attr;
  if (!fprop)
    {
      strcpy (buff, " ");
    }
  else
    {
      A4GL_debug ("Has property");

      if (!A4GL_has_str_attribute (fprop, FA_S_COMMENTS))
	{
	  strcpy (buff, "");
	}
      else
	{
	  strcpy (buff, A4GL_get_str_attribute (fprop, FA_S_COMMENTS));
	  A4GL_strip_quotes (buff);
	}
    }

  cline = A4GL_getcomment_line ();
  buff[A4GL_get_curr_width ()] = 0;
  A4GL_debug ("MJA COMMENTS 1,%d,%s", cline, buff);


  if (A4GL_LL_can_show_comments (buff))
    {
      return;
    }

  if (cline > UILIB_A4GL_get_curr_height ())
    {
      cline = UILIB_A4GL_get_curr_height ();
    }

  attr = A4GL_local_get_curr_window_attr ();
  A4GL_debug ("Attr1=%x\n", attr);

  if (!attr)
    {
      attr = A4GL_determine_attribute (FGL_CMD_INPUT, 0, 0, 0);
      A4GL_debug ("Attr2=%x\n", attr);
    }


  if (A4GL_isyes (acl_getenv ("COMMENT_LIKE_INPUT")))
    {
      attr = A4GL_determine_attribute (FGL_CMD_INPUT, 0, 0, 0);
      A4GL_debug ("Attr3=%x\n", attr);
    }

  if (A4GL_isyes (acl_getenv ("COMMENT_LIKE_DISPLAY")))
    {
      attr = A4GL_determine_attribute (FGL_CMD_DISPLAY_CMD, 0, 0, 0);
      A4GL_debug ("Attr4=%x\n", attr);
    }

  A4GL_debug ("Comments attr=%x buff=%s", attr, buff);
  //attr=attr&0xffffff00;
  A4GL_debug ("And display the comments... %d,%d -'%s'", cline, 1, buff);
  UILIB_A4GL_display_internal (1, cline, buff, attr, 1);
  A4GL_debug ("Done display the comments... %d,%d -'%s'", cline, 1, buff);

  A4GL_LL_screen_update ();

}


void
A4GL_set_curr_infield (long a)
{
  inp_current_field = a;
}


int
A4GL_get_curr_infield (void)
{
  return inp_current_field;
}

void
UILIB_A4GL_set_infield_from_stack (void)
{
  A4GL_debug ("**** CHANGED FIELD ****");
  inp_current_field = A4GL_pop_long ();
  A4GL_debug ("New field :---> %p", inp_current_field);
}

void
A4GL_set_infield_from_parameter (long a)
{
  A4GL_debug ("**** CHANGED FIELD ****");
  inp_current_field = a;
  A4GL_debug ("New field :---> %p", inp_current_field);
}


int
A4GL_get_curr_metric (struct s_form_dets *form)
{
  int a;
  void *cfield;
  cfield = A4GL_LL_current_field (form->form);
  A4GL_debug ("In curr metric");
  for (a = 0; a < form->fileform->metrics.metrics_len; a++)
    {
      if (cfield == (void *) form->fileform->metrics.metrics_val[a].field)
	{
	  A4GL_debug ("Returning %d\n", a);
	  return a;
	}
    }
  A4GL_debug ("NO current metric !");
  return -1;
}


int
A4GL_field_is_noentry (int doing_construct, struct struct_scr_field *f)
{
  A4GL_debug ("A4GL_field_is_noentry %d %p", doing_construct, f);

  if (A4GL_has_bool_attribute (f, FA_B_NOENTRY))
    {
      if (doing_construct)
	{
	  A4GL_debug ("A4GL_field_is_noentry returns 0");
	  return 0;
	}
      A4GL_debug ("A4GL_field_is_noentry returns 1");
      return 1;
    }


// It would appear that the NOUPDATE allows entry to a field on a 'construct' but not
// an input...
  if (doing_construct)
    {
      A4GL_debug ("A4GL_field_is_noentry returns 0");
      return 0;
    }
  if (A4GL_has_bool_attribute (f, FA_B_NOUPDATE))
    {
      A4GL_debug ("No UPDATE");
      A4GL_debug ("A4GL_field_is_noentry returns 1");
      return 1;
    }
  A4GL_debug ("OK");
  A4GL_debug ("A4GL_field_is_noentry returns 0");
  return 0;
}



static int
A4GL_construct_large_loop (void *f, struct aclfgl_event_list *evt, struct struct_scr_field *fprop)
{
  static int ins_ovl = 'o';
  int a;
  int looping = 1;
  A4GL_LL_set_carat (f);
  A4GL_debug ("su");
  A4GL_LL_screen_update ();


  //blk=A4GL_has_evt_timeout(evt);
  //if (blk) { return blk; }
  //
  a = A4GL_getch_internal (0, "construct");
  construct_last_key = a;


  A4GL_debug ("construct_large a=%d abort_pressed=%d", a, abort_pressed);
  if (a == A4GLKEY_EVENT)
    {
      A4GL_debug ("construct fired event...");
      A4GL_evt_not_idle (evt);
      return A4GL_LL_get_triggered_event ();
    }


  if (abort_pressed || a == A4GLKEY_INTERRUPT || a == A4GLKEY_CANCEL)
    {
      ins_ovl = 'o';
      return 0;
    }
  if (A4GL_has_event_for_keypress (a, evt))
    {
      ins_ovl = 'o';
      return 0;
    }

                        if (A4GL_has_bool_attribute (fprop, FA_B_DOWNSHIFT)) {
                                        if (a4gl_isupper (a) && a4gl_isalpha (a)) { a = a4gl_tolower (a); }
                        }
                        if (A4GL_has_bool_attribute (fprop, FA_B_UPSHIFT)) {
                                        if ( a4gl_islower (a) && a4gl_isalpha (a)) { a = a4gl_toupper (a); }
                        }


  switch (a)
    {

    case 1:
      if (ins_ovl == 'o')
	{
	  ins_ovl = 'i';
	  A4GL_LL_int_form_driver (f, AUBIT_REQ_INS_MODE);
	}
      else
	{
	  ins_ovl = 'o';
	  A4GL_LL_int_form_driver (f, AUBIT_REQ_OVL_MODE);
	}

    case 27:
    case A4GLKEY_ACCEPT:
    case A4GLKEY_DOWN:
    case A4GLKEY_UP:
    case A4GLKEY_ENTER:
    case '\t':
      looping = 0;
      break;

    case A4GLKEY_LEFT:
      if (A4GL_LL_get_carat (f) == 0)
	{
	  looping = 0;
	  break;
	}
      A4GL_LL_int_form_driver (f, AUBIT_REQ_PREV_CHAR);
      break;


    case 127:
    case 8:
    case A4GLKEY_DC:
    case A4GLKEY_DL:
    case A4GLKEY_BACKSPACE:
      A4GL_LL_int_form_driver (f, AUBIT_REQ_DEL_PREV);
      break;

    case 24:
      A4GL_LL_int_form_driver (f, AUBIT_REQ_DEL_CHAR);
      break;
    case A4GLKEY_RIGHT:
      A4GL_LL_int_form_driver (f, AUBIT_REQ_NEXT_CHAR);
      break;
    default:
      A4GL_LL_int_form_driver (f, a);
      break;
    }


// Reset the ins_ovl flag for next time....
  if (looping == 0)
    {
      ins_ovl = 'o';
      return 0;
    }
  return 1;
}




static int
A4GL_local_get_curr_window_attr (void)
{
  A4GL_debug ("30 XXX - get_curr_window_attr");
  if (A4GL_has_pointer ((char *) A4GL_get_currwin_name (), ATTRIBUTE))
    {
      int a;
      a = (int) A4GL_find_pointer ((char *) A4GL_get_currwin_name (), ATTRIBUTE);
      A4GL_debug ("30 Current window has an attribute %d", a);
      return a;
    }
  A4GL_debug ("30 Current window has no attribute");
  return 0;

}



static int
chk_all_fields (struct s_screenio *sio)
{
  int a;

  if (sio->mode != MODE_CONSTRUCT)
    {
      // Might need to do something similar for construct ?
      for (a = 0; a <= sio->nfields; a++)
	{
	  if (local_chk_field (sio->currform, sio->field_list[a]) == -4)
	    {
	      return a;
	    }
	}
    }
  return -1;

}

int
A4GL_fprop_flag_get (void *f, int flag)
{
  struct struct_scr_field *fprop;
  fprop = (struct struct_scr_field *) (A4GL_ll_get_field_userptr (f));

        A4GL_debug("getting flag to %d", fprop->flags);
  if (fprop->flags & flag)
    return 1;
  return 0;
}

int
A4GL_fprop_flag_set (void *f, int flag)
{
  struct struct_scr_field *fprop;
  fprop = (struct struct_scr_field *) (A4GL_ll_get_field_userptr (f));


  fprop->flags |= flag;
A4GL_debug("Setting flag to %d", fprop->flags);
  return fprop->flags;
}

int
A4GL_fprop_flag_clear (void *f, int flag)
{
  struct struct_scr_field *fprop;
  fprop = (struct struct_scr_field *) (A4GL_ll_get_field_userptr (f));
  fprop->flags -= (fprop->flags & flag);
        A4GL_debug("clearing flag to %d", fprop->flags);
  return fprop->flags;
}


void
A4GL_debug_print_field_opts (void *a)
{
  long z;
  char str[8048] = "";
  z = A4GL_LL_field_opts (a);
  if (z & AUBIT_O_VISIBLE)
    strcat (str, " O_VISIBLE");
  if (z & AUBIT_O_ACTIVE)
    strcat (str, " O_ACTIVE");
  if (z & AUBIT_O_PUBLIC)
    strcat (str, " O_PUBLIC");
  if (z & AUBIT_O_EDIT)
    strcat (str, " O_EDIT");
  if (z & AUBIT_O_WRAP)
    strcat (str, " O_WRAP");
  if (z & AUBIT_O_BLANK)
    strcat (str, " O_BLANK");
  if (z & AUBIT_O_AUTOSKIP)
    strcat (str, " O_AUTOSKIP");
  if (z & AUBIT_O_NULLOK)
    strcat (str, " O_NULLOK");
  if (z & AUBIT_O_STATIC)
    strcat (str, " O_STATIC");
  if (z & AUBIT_O_PASSOK)
    strcat (str, " O_PASSOK");
  A4GL_debug ("UUU Field %p attribs= %s: (%s)", a, str, A4GL_LL_field_buffer (a, 0));
}

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
# $Id: formcntrl.c,v 1.3 2003-06-09 11:12:21 mikeaubury Exp $
#*/

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


#include "a4gl_lib_ui_tui_int.h"
#include <ctype.h>
extern int m_lastkey;
int A4GL_curses_to_aubit (int a);
int A4GL_page_for_pfield (struct s_screenio *s);
int A4GL_curr_metric_is_used_last_s_screenio (struct s_screenio *s, FIELD * f);

#define CONTROL_STACK_LENGTH 10

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

void A4GL_mja_pos_form_cursor (FORM * form);
static int process_control_stack (struct s_screenio *arr);
static int A4GL_has_something_on_control_stack (struct s_screenio *sio);
static void A4GL_add_to_control_stack (struct s_screenio *sio, int op, FIELD * f, char *parameter, int extent);
static void A4GL_newMovement (struct s_screenio *arr,  int attrib);
static void A4GL_init_control_stack (struct s_screenio *sio, int malloc_data);

int A4GL_form_field_chk (struct s_screenio *sio, int m);
int A4GL_form_field_constr (struct s_screenio *sio, int m);
int A4GL_req_field_input (struct s_screenio *s, ...);
int A4GL_proc_key_input (int a, FORM * mform, struct s_screenio *s);
int A4GL_get_curr_metric (struct s_form_dets *form);
int A4GL_page_for_nfield (struct s_screenio *s);
struct s_form_dets *A4GL_getfromform (FORM * f);
void *A4GL_memdup (void *ptr, int size);
void
A4GL_mja_set_current_field (FORM * form, FIELD * field);


struct s_movement
{
  int scr_line;
  int arr_line;
  int attrib_no;
};
int do_input_nowrap = 0;
extern WINDOW *currwin;


char *ops[]= {
"",
"FORMCONTROL_BEFORE_FIELD", //                1
"FORMCONTROL_AFTER_FIELD", //                 2
"FORMCONTROL_BEFORE_INPUT" , //               3
"FORMCONTROL_AFTER_INPUT"   , //              4
"FORMCONTROL_EXIT_INPUT_OK"   , //            5
"FORMCONTROL_EXIT_INPUT_ABORT"  , //          6
"FORMCONTROL_KEY_PRESS"         , //          7
"FORMCONTROL_BEFORE_INSERT"   , //            8
"FORMCONTROL_BEFORE_DELETE"   , //            9
"FORMCONTROL_AFTER_INSERT"    , //            10
"FORMCONTROL_AFTER_DELETE"    , //            11
"FORMCONTROL_BEFORE_ROW"      , //            12
"FORMCONTROL_AFTER_ROW"       , //            13
0};

/* 
* This function adds a value to the control stack
* this is read to determine when to call before/after fields etc
*
*/
static void A4GL_add_to_control_stack (struct s_screenio *sio, int op, FIELD * f, char *parameter, int extent)
{
  char *field_name;
  int a;
  struct struct_scr_field *attr;

  A4GL_debug ("add to control stack called with op=%d(%s) field=%p extent=%d", op, ops[op],f,
	 extent);

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
      sio->fcntrl[a].state =-1;
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
  void *last_field;
  void *next_field;


  A4GL_debug ("newMovement %d ",  attrib);

  if (attrib < 0)
    {
      // attempt to move too far to the left
      A4GL_debug ("Too far to the left");
      A4GL_newMovement (sio,  0);
      return;
    }


  if (attrib > sio->nfields)
    {
      // Too far over to the right - wrap to the left or possible exit - INPUT WRAP...
      A4GL_debug ("Too far to the right");
      A4GL_newMovement (sio,   -1);
      return;
    }



  ptr = malloc (sizeof (struct s_movement));
  ptr->scr_line = -1; // Not used for a normal input/construct
  ptr->arr_line = -1; // Not used for a normal input/construct
  ptr->attrib_no = attrib;

  last_field = sio->currform->currentfield;

  A4GL_debug("last field was : %p",sio->currform->currentfield);
  next_field = sio->field_list[attrib];

  if (last_field!=next_field || 1) {
  	A4GL_add_to_control_stack (sio, FORMCONTROL_BEFORE_FIELD, next_field, A4GL_memdup (ptr, sizeof (struct s_movement)), 0);
  	if (last_field) {
		if (last_field!=next_field)
			A4GL_add_to_control_stack (sio, FORMCONTROL_AFTER_FIELD, last_field, 0, 0);
	}
  } else {
  	free (ptr);
  }
  A4GL_debug("Done newMovement - last_field was %p new_field is %p",last_field,new_field);
}



/* 
* process any waiting actions 
*
*/
static int
process_control_stack (struct s_screenio *sio)
{
  int a;
  int rval;
  int new_state;
  struct s_movement *ptr_movement;

  rval = -1;
  new_state = 99;


  a = sio->fcntrl_cnt - 1;

/* BEFORE_INPUT isn't used yet... */
  if (sio->fcntrl[a].op == FORMCONTROL_BEFORE_INPUT)
    {
      new_state = 0;
      //rval = -99;
    }

  if (sio->fcntrl[a].op == FORMCONTROL_AFTER_INPUT)
    {
      if (sio->fcntrl[a].state == 99)
	{
	  new_state = 50;
	  rval = -95;		// Do any AFTER INPUT section
	}

      if (sio->fcntrl[a].state == 50)
	{
	  new_state = 0;
	  rval = -94;		// CLEANUP
	}
    }


  if (sio->fcntrl[a].op == FORMCONTROL_EXIT_INPUT_OK)
    {
      if (sio->fcntrl[a].state == 99)
        {
         A4GL_add_to_control_stack (sio, FORMCONTROL_AFTER_FIELD, sio->currentfield, 0, 0);
          new_state = 50;
	  rval=-90;
        }

      if (sio->fcntrl[a].state == 50)
        {
      	  A4GL_add_to_control_stack (sio, FORMCONTROL_AFTER_INPUT, 0, 0, 0);
          new_state = 0;
      	rval = 0;
        }
    }


  if (sio->fcntrl[a].op == FORMCONTROL_EXIT_INPUT_ABORT)
    {
      //extern int int_flag;
      A4GL_debug ("FORM ABORT..");
      int_flag = 1;
      A4GL_add_to_control_stack (sio, FORMCONTROL_AFTER_INPUT, 0, 0, 0);
      rval = 0;
      new_state = 0;
    }

  if (sio->fcntrl[a].op == FORMCONTROL_KEY_PRESS)
    {
      if (sio->fcntrl[a].state == 99)
	{
	  new_state = 50;
	  rval = -90;
	}

      if (sio->fcntrl[a].state == 50)
	{
	  new_state = 0;
	  A4GL_debug ("Checking key state.. %d", sio->fcntrl[a].extent);
		if (sio->fcntrl[a].extent>=0 && sio->fcntrl[a].extent<=255) {A4GL_int_form_driver (sio->currform->form, sio->fcntrl[a].extent);
	  A4GL_int_form_driver (sio->currform->form, REQ_VALIDATION);
		}
	rval=-90;
	  //mja_wrefresh(currwin);
	}
    }


  if (sio->fcntrl[a].op == FORMCONTROL_BEFORE_FIELD)
    {
      ptr_movement = (struct s_movement *) sio->fcntrl[a].parameter;
      new_state = 0;
      sio->curr_attrib = ptr_movement->attrib_no;
      A4GL_debug ("Before field - fieldname=%p", sio->fcntrl[a].field_name);
      A4GL_debug ("Before field - fieldname=%s", sio->fcntrl[a].field_name);
      A4GL_push_long ((long) sio->currentfield);
      A4GL_push_char (sio->fcntrl[a].field_name);
      sio->currentfield = sio->field_list[sio->curr_attrib];
      set_current_field (sio->currform->form, sio->currentfield);
      pos_form_cursor (sio->currform->form);
	sio->currform->currentfield=sio->currentfield;

	A4GL_debug("New current field set to %p",sio->currentfield);

      rval = -197;
    }


  if (sio->fcntrl[a].op == FORMCONTROL_AFTER_FIELD)
    {

	int ffc_rval;
  	if (sio->mode != MODE_CONSTRUCT)
    		ffc_rval=A4GL_form_field_chk (sio, -1);
  	else
    		ffc_rval=A4GL_form_field_constr (sio, -1);


	A4GL_debug("form_Field_chk returns %d\n",a);

	if (ffc_rval!=-4) {
      		new_state = 0;
      		A4GL_push_long ((long) sio->currentfield);
      		A4GL_push_char (sio->fcntrl[a].field_name);
      		rval = -198;
	} else {
 			A4GL_init_control_stack (sio,0);
			return -1;
	}
    }

  if (new_state != 0 && sio->fcntrl[a].op!=0)
    {
      if (sio->fcntrl[a].state == new_state)
	{
	A4GL_debug("internal error - state=%d op=%d (%s) @ %d",new_state,sio->fcntrl[a].op,ops[sio->fcntrl[a].op],a);
	  A4GL_exitwith ("Internal error - no change in state ");
	  return -1;
	}
      A4GL_debug ("Setting input control state to %d", new_state);
      sio->fcntrl[a].state = new_state;
    }
  else
    {
      A4GL_debug ("Popping type %d (%s) off control stack @ %d", sio->fcntrl[a].op,ops[sio->fcntrl[a].op],a);
      sio->fcntrl_cnt--;
      if (sio->fcntrl[a].parameter)
	{
	  free (sio->fcntrl[a].parameter);
	}
    }
  A4GL_debug ("Returning %d\n", rval);
  return rval;
}


int
A4GL_req_field_input (struct s_screenio *s, ...)
{ 
/* fieldname + = next - = previous */
  int a;
  FIELD **ptr;
  char *field_name;
  va_list ap;
  va_list ap2;
  va_start (ap, s);
  va_start(ap2,s);
  field_name=va_arg(ap2,char *);

  if (strcmp(field_name,"+")==0) { // Next field next
			A4GL_init_control_stack (s,0);
			A4GL_newMovement(s,s->curr_attrib+1);
			return 1;
  }

  if (strcmp(field_name,"-")==0) { // Next field previous
			A4GL_init_control_stack (s,0);
			A4GL_newMovement(s,s->curr_attrib-1);
			return 1;
  }


  A4GL_debug ("req_field");

  a = A4GL_gen_field_list (&ptr, s->currform, 1, &ap);

  if (a >= 0)
    {
	for (a=0;a<=s->nfields;a++) {
		if (s->field_list[a]==ptr[0]) {
			A4GL_init_control_stack (s,0);
			A4GL_newMovement(s,a);
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




/**
 * 4GL CALL
 * @todo Describe function
 */
int
A4GL_form_loop (void *vs,int init)
{
  struct s_form_dets *form;
  int a;
  struct s_screenio *s;
  //int int_form_driver_ret = 0;
  struct struct_scr_field *fprop;
  struct struct_metrics *metrics;
  FORM *mform;
  s = vs;
  if (init==1) {
	A4GL_debug("------------------------------------------------------");
	s->currform->currentfield=0;
  }
  form = s->currform;
  A4GL_set_abort (0);
  A4GL_debug ("form_loop0..  currentfield=%p status = %d", form->currentfield,field_status(form->currentfield));

  if (form != A4GL_get_curr_form ())
    {
      A4GL_debug ("form=%p curr_form=%p", form, A4GL_get_curr_form ());
      A4GL_exitwith ("Input form is not current");
      return 0;
    }

  mform = form->form;
  A4GL_mja_wrefresh (currwin);

  if (init) {
	A4GL_init_control_stack (s, 1);
	s->curr_attrib=0;
	s->currentfield=0;
	A4GL_newMovement(s,0);
	}

  if (A4GL_has_something_on_control_stack (s))
    {
      int rval;
      rval = process_control_stack (s);
      A4GL_debug ("Control stack - he say %d", rval);
      return rval;
    }


  //if (s->mode != MODE_CONSTRUCT)
    //a = A4GL_form_field_chk (s, 0);
  //else
    //a = A4GL_form_field_constr (s, 0);


  //pos_form_cursor (mform);

  fprop = (struct struct_scr_field *) field_userptr (current_field (mform));
  metrics = &form->fileform->metrics.metrics_val[A4GL_get_curr_metric (form)];

  if (metrics && (int) metrics != -1)
    {
      set_form_page (mform, metrics->scr - 1);
    }


A4GL_mja_set_current_field (mform, form->currentfield);
A4GL_mja_pos_form_cursor (mform);

// Wait for a key..
  a = A4GL_getch_win ();
     A4GL_clr_error_nobox();

  if (abort_pressed) a = -1;

  A4GL_debug ("form_loop1..  currentfield=%p status = %d", form->currentfield,field_status(form->currentfield));

// Process the key..
  A4GL_proc_key_input (a, mform, s);
  return -90;
}




/**
 *
 * @todo Describe function
 */
int
A4GL_proc_key_input (int a, FORM * mform, struct s_screenio *s)
{
  FIELD *f;
  struct s_form_attr *form;
  struct struct_scr_field *fprop;
  struct s_form_dets *fd;
  //int npage;
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
      A4GL_add_to_control_stack (s, FORMCONTROL_EXIT_INPUT_OK, 0, 0, a);
      return -1;
    }


  switch (a)
    {
    case 18:
      A4GL_mja_wrefresh (stdscr);
      A4GL_mja_wrefresh (currwin);
      A4GL_mja_refresh ();
      break;


    case -1:
 	A4GL_add_to_control_stack (s, FORMCONTROL_EXIT_INPUT_ABORT, 0, 0, a);
        break;


    //case 26:
      //return 0; ^Z ?

    case 127:
    case 8:
    case KEY_DC:
    case KEY_DL:
    case KEY_BACKSPACE:
	A4GL_int_form_driver (mform, REQ_DEL_PREV);break;

    case 24:
	A4GL_int_form_driver (mform, REQ_DEL_CHAR);break;

    case KEY_UP:
	A4GL_debug("MJA Try to move to previous field : %d\n",s->curr_attrib-1);
	A4GL_newMovement(s,s->curr_attrib-1);
	break;

    case '\t':
    case KEY_ENTER:
    case 13:
    case 10:
    case KEY_DOWN:
          if (std_dbscr.input_wrapmode == 0 && A4GL_curr_metric_is_used_last_s_screenio (s, f))
            {
      		A4GL_add_to_control_stack (s, FORMCONTROL_EXIT_INPUT_OK, 0, 0, a);
              	return 0;
            }
	A4GL_debug("MJA Try to move to next field : %d\n",s->curr_attrib+1);
	A4GL_newMovement(s,s->curr_attrib+1);


    case KEY_LEFT:
	A4GL_int_form_driver (mform, REQ_PREV_CHAR);break;

    case KEY_RIGHT:
	A4GL_int_form_driver (mform, REQ_NEXT_CHAR);break;

    case 4:                     // Control - D
	A4GL_int_form_driver (mform, REQ_CLR_EOF);break;

    case 1:                     // Control - A
      form->insmode = form->insmode ? 0 : 1;
      if (form->insmode) {
	A4GL_int_form_driver (mform, REQ_INS_MODE);break;
	} 
      else {
	A4GL_int_form_driver (mform, REQ_OVL_MODE);break;
	}
    }

  //if (a > 0 && a < 255)
    //{
      A4GL_add_to_control_stack (s, FORMCONTROL_KEY_PRESS, 0, 0, a);
    //}

  A4GL_mja_refresh ();
  return -1;
}


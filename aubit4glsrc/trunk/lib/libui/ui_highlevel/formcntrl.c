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
# $Id: formcntrl.c,v 1.3 2004-01-17 11:13:34 mikeaubury Exp $
#*/
static char *module_id="$Id: formcntrl.c,v 1.3 2004-01-17 11:13:34 mikeaubury Exp $";
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
#include "a4gl_libaubit4gl.h"
#include "a4gl_lib_ui_int.h"
#include "a4gl_API_ui.h"
#include "a4gl_incl_4gldef.h"
#include "formdriver.h"
#include "formcntrl.h"

#include <ctype.h>

extern int m_lastkey;
#define CONTROL_STACK_LENGTH 10

static int process_control_stack (struct s_screenio *arr, struct aclfgl_event_list *evt);
static int A4GL_has_something_on_control_stack (struct s_screenio *sio);
static void A4GL_add_to_control_stack (struct s_screenio *sio, int op,
				       void *f, char *parameter, int extent);
static void A4GL_newMovement (struct s_screenio *arr, int attrib);
static void A4GL_init_control_stack (struct s_screenio *sio, int malloc_data);
static int A4GL_proc_key_input (int a, void *mform, struct s_screenio *s);
static void do_key_move (char lr, struct s_screenio *s, int a,
			 int has_picture, char *picture);
long inp_current_field = 0;


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
A4GL_add_to_control_stack (struct s_screenio *sio, int op, void *f,
			   char *parameter, int extent)
{
  char *field_name;
  int a;
  struct struct_scr_field *attr;

  A4GL_debug ("add to control stack called with op=%d(%s) field=%p extent=%d",
	      op, ops[op], f, extent);

  field_name = 0;

  if (f)
    {
      attr = (struct struct_scr_field *) A4GL_LL_get_field_userptr (f);
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
  void *last_field;
  void *next_field;
  struct struct_scr_field *f;


  A4GL_debug ("newMovement %d ", attrib);

  if (attrib < 0)
    {
      // attempt to move too far to the left
      A4GL_debug ("Too far to the left");
      A4GL_newMovement (sio, 0);
      return;
    }


  if (attrib > sio->nfields)
    {
      // Too far over to the right - wrap to the left or possible exit - INPUT WRAP...
      A4GL_debug ("Too far to the right");
      A4GL_newMovement (sio, -1);
      return;
    }



  ptr = malloc (sizeof (struct s_movement));
  ptr->scr_line = -1;		// Not used for a normal input/construct
  ptr->arr_line = -1;		// Not used for a normal input/construct
  ptr->attrib_no = attrib;

  last_field = sio->currform->currentfield;

  A4GL_debug ("last field was : %p", sio->currform->currentfield);
  next_field = sio->field_list[attrib];
  f = (struct struct_scr_field *) (A4GL_LL_get_field_userptr (next_field));

  if (A4GL_has_bool_attribute (f, FA_B_NOENTRY)
      || (f->datatype == DTYPE_SERIAL && sio->mode != MODE_CONSTRUCT))
    {
      int dir = 0;
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
	  f =
	    (struct struct_scr_field
	     *) (A4GL_LL_get_field_userptr (next_field));

	  if (A4GL_has_bool_attribute (f, FA_B_NOENTRY)
	      || (f->datatype == DTYPE_SERIAL))
	    {
	      attrib += dir;
	      if (attrib > sio->nfields)
		{


		  if (std_dbscr.input_wrapmode == 0)
		    {
		      A4GL_add_to_control_stack (sio,
						 FORMCONTROL_EXIT_INPUT_OK, 0,
						 0, 0);
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
      A4GL_add_to_control_stack (sio, FORMCONTROL_BEFORE_FIELD, next_field,
				 A4GL_memdup (ptr,
					      sizeof (struct s_movement)), 0);
      if (last_field)
	{
	  //if (last_field!=next_field) {
	  A4GL_add_to_control_stack (sio, FORMCONTROL_AFTER_FIELD, last_field,
				     0, 0);
	  //}
	}
    }
  else
    {
      free (ptr);
    }
  //A4GL_debug("Done newMovement - last_field was %p new_field is %p",last_field,new_field);
}



/* 
* process any waiting actions 
*
*/
static int
process_control_stack (struct s_screenio *sio,struct aclfgl_event_list *evt)
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

  A4GL_debug("Process control stack %d %d",fcntrl.op,fcntrl.state);
  if (fcntrl.op == FORMCONTROL_BEFORE_INPUT)
    {
      new_state = 0;
	if (A4GL_has_event(-99,evt)) rval = A4GL_has_event(-99,evt);
    }

  if (fcntrl.op == FORMCONTROL_AFTER_INPUT)
    {
      if (fcntrl.state == 99)
	{
	  new_state = 50;
	  if (A4GL_has_event(-95,evt)) rval = A4GL_has_event(-95,evt);
	}

      if (fcntrl.state == 50)
	{
	  new_state = 0;
	  if (A4GL_has_event(-94,evt)) rval = A4GL_has_event(-94,evt);
	  else {
		A4GL_exitwith("Internal error - no break\n");
		exit(1);
	  }
	}
    }


  if (fcntrl.op == FORMCONTROL_EXIT_INPUT_OK)
    {
	A4GL_comments (0);
      if (fcntrl.state == 99)
	{
	  A4GL_add_to_control_stack (sio, FORMCONTROL_AFTER_FIELD, sio->currentfield, 0, 0);
	  new_state = 50;
	  rval = -1;
	}

      if (fcntrl.state == 50)
	{
	  A4GL_add_to_control_stack (sio, FORMCONTROL_AFTER_INPUT, 0, 0, 0);
	  new_state = 10;
	  A4GL_debug("SETTING RVAL TO ZERO");
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
	A4GL_comments (0);
      A4GL_debug ("FORM ABORT..");
      int_flag = 1;
      A4GL_add_to_control_stack (sio, FORMCONTROL_AFTER_INPUT, 0, 0, 0);
	  A4GL_debug("SETTING RVAL TO ZERO");
      rval = 0;
      new_state = 0;
    }

  if (fcntrl.op == FORMCONTROL_KEY_PRESS)
    {
	A4GL_debug("GOT KEY PRESS - STATE = %d",fcntrl.state);
      if (fcntrl.state == 99)
	{
	  if (A4GL_has_event_for_keypress(fcntrl.extent,evt)) {
			A4GL_debug("GOT KEY PRESS... %d %d\n",A4GL_has_event_for_keypress(fcntrl.extent,evt));
			rval=A4GL_has_event_for_keypress(fcntrl.extent,evt);
			new_state=0;
	  } else {
		A4GL_proc_key_input (fcntrl.extent, sio->currform->form, sio);
		new_state=50;
		rval=-1;
	  }
	}


      if (fcntrl.state == 50)
	{
	  struct struct_scr_field *fprop;
	  int has_picture = 0;
	  char *picture = 0;
	  int ok = 0;
	  new_state = 10;

	  fprop =
	    (struct struct_scr_field
	     *) (A4GL_LL_get_field_userptr (sio->currentfield));
	  A4GL_debug ("Checking key state.. %d", fcntrl.extent);
	  if (A4GL_has_str_attribute (fprop, FA_S_PICTURE))
	    {
	      has_picture = 1;
	      picture = A4GL_get_str_attribute (fprop, FA_S_PICTURE);
	    }
	  if (sio->mode == MODE_CONSTRUCT)
	    has_picture = 0;
	  if (fcntrl.extent >= 0 && fcntrl.extent <= 255
	      &&
	      ((isprint (fcntrl.extent) || fcntrl.extent == 1
		|| fcntrl.extent == 4)))
	    {

	      if ((fprop->flags & 1) == 0 && !has_picture)
		{
		  switch (sio->vars[sio->curr_attrib].dtype)
		    {
		    case DTYPE_SMINT:
		    case DTYPE_INT:
		    case DTYPE_SERIAL:
		    case DTYPE_FLOAT:
		    case DTYPE_SMFLOAT:
		    case DTYPE_DECIMAL:
		    case DTYPE_MONEY:
		      A4GL_LL_int_form_driver (sio->currform->form,
					       AUBIT_REQ_CLR_EOF);
		      A4GL_debug
			("Clear to end of field because of datatype");
		    }
		}
	      A4GL_debug ("SETTING FLAGS ");
	      fprop->flags |= 2;	// Set the field status flag



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
		      if (isalpha (key))
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
		  A4GL_LL_int_form_driver (sio->currform->form,
					   fcntrl.extent);
		  A4GL_LL_int_form_driver (sio->currform->form,
					   AUBIT_REQ_VALIDATION);
		}


	      if (has_picture && ok)
		{
		  void *mform;
		  mform = sio->currform->form;
		  if (strchr ("A#X", picture[A4GL_LL_get_carat (mform)]) == 0
		      && picture[A4GL_LL_get_carat (mform)])
		    do_key_move ('R', sio, fcntrl.extent, has_picture,
				 picture);
		}

	    }
	  fprop->flags |= 1;	// Clear the before field flag
	  rval = -1;
	}


      if (fcntrl.state == 10)
	{
	  struct struct_scr_field *fprop;
	  new_state = 5;

	  rval = -1;


	  if (fcntrl.extent >= 28 && fcntrl.extent <= 255)
	    {
	      fprop =
		(struct struct_scr_field
		 *) (A4GL_LL_get_field_userptr (sio->currentfield));

	      if (A4GL_has_bool_attribute (fprop, FA_B_AUTONEXT))
		{
		  void *curses_form;
		  curses_form = sio->currform->form;
		  if ((void *) A4GL_LL_current_field (curses_form) !=
		      sio->currentfield)
		    {
		      A4GL_LL_set_current_field (curses_form,
						 sio->currentfield);
		      A4GL_newMovement (sio, sio->curr_attrib + 1);
		    }

		}
	    }

	}

      if (fcntrl.state == 5)
	{
	  new_state = 0;
	  rval = -1;
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

	  //A4GL_push_long ((long) sio->field_list[sio->curr_attrib]);
	  //A4GL_push_char (fcntrl.field_name);

	  A4GL_set_infield_from_parameter ((long)sio->field_list[sio->curr_attrib]);
	  if (A4GL_has_event_for_field(-97,fcntrl.field_name,evt)) {
		rval=A4GL_has_event_for_field(-97,fcntrl.field_name,evt);
	  }
	}

      if (fcntrl.state == 50)
	{
	  sio->currentfield = sio->field_list[sio->curr_attrib];
	  A4GL_LL_set_current_field (sio->currform->form, sio->currentfield);
	  sio->currform->currentfield = sio->currentfield;
	  A4GL_LL_set_carat (sio->currform->form);
	  fprop =
	    (struct struct_scr_field
	     *) (A4GL_LL_get_field_userptr (sio->currentfield));
	  attr =
	    A4GL_determine_attribute (FGL_CMD_INPUT, sio->attrib, fprop,
				      (char *) A4GL_LL_field_buffer (sio->
								     currentfield,
								     0));
	  if (attr != 0)
	    A4GL_set_field_attr_with_attr (sio->currentfield, attr,
					   FGL_CMD_INPUT);
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
				       sio->vars[sio->curr_attrib].dtype +
				       ENCODE_SIZE (sio->
						    vars[sio->curr_attrib].
						    size));

		  A4GL_debug ("Set value to '%s'",
			      A4GL_LL_field_buffer (sio->currentfield, 0));
		  w = A4GL_get_field_width (sio->currentfield);
		  has_picture = 1;
		  picture = A4GL_get_str_attribute (fprop, FA_S_PICTURE);
		  ptr = malloc (w + 1);

		  strcpy (ptr, A4GL_LL_field_buffer (sio->currentfield, 0));
		  ptr[w] = 0;

		  for (a = 0; a < strlen (picture); a++)
		    {
		      if (a > w)
			break;

		      if (picture[a] == 'A')
			{
			  if (!isalpha (ptr[a]))
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
		  A4GL_debug ("XYX Set field : %s", ptr);
		  free (ptr);	// ? @todo....
		}
	      else
		{
		  A4GL_set_init_value (sio->currentfield,
				       sio->vars[sio->curr_attrib].ptr,
				       sio->vars[sio->curr_attrib].dtype +
				       ENCODE_SIZE (sio->
						    vars[sio->curr_attrib].
						    size));
		}

	      if (has_picture)
		{
		  A4GL_LL_int_form_driver (sio->currform->form, AUBIT_REQ_OVL_MODE);	// Always in overwrite mode in a picture...
		}


	    }

	  A4GL_comments (fprop);
	  if ((fprop->flags & 1))
	    fprop->flags -= 1;	// Clear a flag to indicate that we're just starting on this field
	  new_state = 0;
	  A4GL_debug ("Setting rval to -1");
	  //rval=-99;
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
	ffc_rval = A4GL_form_field_constr (sio, -1);


      A4GL_debug ("form_Field_chk returns %d\n", a);

      if (ffc_rval != -4)
	{
	  int really_ok = 0;
	  new_state = 0;
	  fprop =
	    (struct struct_scr_field
	     *) (A4GL_LL_get_field_userptr (sio->currentfield));
	  if (sio->mode != MODE_CONSTRUCT)
	    {
	      //int has_picture=0;
	      char *picture;
	      int field_no;
	      char buff[10024];
	      field_no = sio->curr_attrib;
	      strcpy (buff, A4GL_LL_field_buffer (sio->currentfield, 0));


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

	      if (strlen (buff))
		{
		char buff2[10024];
		  A4GL_debug ("Field is not null");
		  strcpy(buff2,(char *)A4GL_fld_data_ignore_format(fprop,buff));
		strcpy(buff,buff2);
		  A4GL_push_char (buff);
		}
	      else
		{
		  A4GL_debug ("Field is null");
		  A4GL_push_null (DTYPE_CHAR, 0);
		}


	      A4GL_debug ("Calling A4GL_pop_var2 : %p dtype=%d size=%d",
			  sio->vars[field_no].ptr, sio->vars[field_no].dtype,
			  sio->vars[field_no].size);
	      really_ok = 1;


	      A4GL_pop_var2 (sio->vars[field_no].ptr,
			     sio->vars[field_no].dtype,
			     sio->vars[field_no].size);



	      really_ok = 1;

	      if (strlen (buff)
		  && A4GL_isnull (sio->vars[field_no].dtype,
				  sio->vars[field_no].ptr))
		really_ok = 0;

	      if (!A4GL_conversion_ok (-1))
		really_ok = 0;

	      if ((sio->vars[field_no].dtype == DTYPE_INT
		   || sio->vars[field_no].dtype == DTYPE_SMINT
		   || sio->vars[field_no].dtype == DTYPE_SERIAL)
		  && strchr (buff, '.'))
		{
		  really_ok = 0;
		}


	      if (really_ok == 0)
		{
		  //
		  A4GL_error_nobox (acl_getenv ("FIELD_ERROR_MSG"), 0);

		  if (A4GL_isyes (acl_getenv ("A4GL_CLR_FIELD_ON_ERROR")))
		    {
		      A4GL_clr_field (sio->currform->currentfield);
		    }
		  else
		    {
		      if (A4GL_isyes (acl_getenv ("FIRSTCOL_ONERR")))
			{
			  A4GL_LL_int_form_driver (sio->currform->form,
						   AUBIT_REQ_BEG_FIELD);
			}

		    }


		  A4GL_LL_set_current_field (sio->currform->form,
					     sio->currform->currentfield);
		  A4GL_init_control_stack (sio, 0);
		  return -1;
		}





	      A4GL_push_char (buff);
	      A4GL_debug ("Calling display_field_contents");


	      A4GL_display_field_contents (sio->currentfield, sio->vars[field_no].dtype + ENCODE_SIZE (sio->vars[field_no].size), sio->vars[field_no].size, sio->vars[field_no].ptr);	// MJA 2306

	      fprop =
		(struct struct_scr_field
		 *) (A4GL_LL_get_field_userptr (sio->currentfield));
	      attr =
		A4GL_determine_attribute (FGL_CMD_INPUT, sio->attrib, fprop,
					  A4GL_LL_field_buffer (sio->
								currentfield,
								0));
	      if (attr != 0)
		A4GL_set_field_attr_with_attr (sio->currentfield, attr,
					       FGL_CMD_INPUT);

	    }


	  //A4GL_push_long ((long) sio->currentfield);
	  //A4GL_push_char (fcntrl.field_name);

	A4GL_set_infield_from_parameter ((long)sio->currentfield);


	  if (A4GL_has_event_for_field(-98,fcntrl.field_name,evt)) {
		rval=A4GL_has_event_for_field(-98,fcntrl.field_name,evt);
	  }


	}
      else
	{
	  A4GL_init_control_stack (sio, 0);
	  return -1;
	}
    }



  if (new_state != 0 && fcntrl.op != 0)
    {
      if (fcntrl.state == new_state)
	{
	  A4GL_debug ("internal error - state=%d op=%d (%s) @ %d", new_state,
		      fcntrl.op, ops[fcntrl.op], a);
	  A4GL_exitwith ("Internal error - no change in state ");
	  return -1;
	}
      A4GL_debug ("Setting input control state to %d", new_state);
      sio->fcntrl[a].state = new_state;
    }
  else
    {
      A4GL_debug ("Popping type %d (%s) off control stack @ %d",
		  sio->fcntrl[a].op, ops[sio->fcntrl[a].op], a);

  	if (a != sio->fcntrl_cnt - 1) {
		A4GL_debug("INTERNAL ERROR - pop state with added new one %d %d",sio->fcntrl[a].op,sio->fcntrl[a].state);
	  	A4GL_exitwith ("Internal error - bad change in state ");
		return -1;
	}

      sio->fcntrl_cnt--;
      if (sio->fcntrl[a].parameter)
	{
	  free (sio->fcntrl[a].parameter);
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
UILIB_A4GL_form_loop_v2 (void *vs, int init,void *vevt)
{
  struct s_form_dets *form;
  int a;
  struct s_screenio *s;
  struct aclfgl_event_list *evt;
  //int LL_int_form_driver_ret = 0;
  struct struct_scr_field *fprop;
  struct struct_metrics *metrics;
  void *mform;
  evt=vevt;
  s = vs;
  if (init == 1)
    {
      A4GL_debug ("------------------------------------------------------");
      s->currform->currentfield = 0;
      abort_pressed = 0;
    }
  form = s->currform;
  A4GL_set_abort (0);
  //A4GL_debug ("form_loop0..  currentfield=%p status = %d", form->currentfield,field_status(form->currentfield));

  if (form != (struct s_form_dets *)UILIB_A4GL_get_curr_form (0))
    {

        A4GL_make_window_with_this_form_current(form);
    }

  if (form != (struct s_form_dets *)UILIB_A4GL_get_curr_form (1))
    {
      A4GL_debug ("form=%p curr_form=%p", form, UILIB_A4GL_get_curr_form (1));
      A4GL_exitwith ("Input form is not current");
      return 0;
    }

  mform = form->form;
  A4GL_LL_screen_update ();

  if (init)
    {
      A4GL_init_control_stack (s, 1);
      s->curr_attrib = 0;
      s->currentfield = 0;
      A4GL_newMovement (s, 0);
      A4GL_add_to_control_stack (s, FORMCONTROL_BEFORE_INPUT, 0, 0, 0);
    }

  if (A4GL_has_something_on_control_stack (s))
    {
      int rval;
      rval = process_control_stack (s,evt);
      A4GL_debug ("Control stack - he say %d", rval);
      return rval;
    }


  //if (s->mode != MODE_CONSTRUCT)
  //a = A4GL_form_field_chk (s, 0);
  //else
  //a = A4GL_form_field_constr (s, 0);


  //pos_form_cursor (mform);

  fprop =
    (struct struct_scr_field *)
    A4GL_LL_get_field_userptr (A4GL_LL_current_field (mform));
  metrics = &form->fileform->metrics.metrics_val[A4GL_get_curr_metric (form)];

  if (metrics && (int) metrics != -1)
    {
      A4GL_LL_set_form_page (mform, metrics->scr - 1);
    }

//if (current_field(mform)!=form->currentfield) {
  //A4GL_debug("CHANGE OF FIELD\n");
  A4GL_mja_set_current_field (mform, form->currentfield);
//}



// Wait for a key..
   A4GL_LL_set_carat(mform);
  a = A4GL_getch_win ();
  s->processed_onkey = a;
  m_lastkey = a;
  A4GL_set_last_key (a);
  A4GL_clr_error_nobox ("A4GL_form_loop");

  if (abort_pressed) {
    a =  -100;   // A4GL_key_val ("INTERRUPT");
    A4GL_set_last_key (a);
      abort_pressed = 0;
  }

  //A4GL_debug ("form_loop1..  currentfield=%p status = %d", form->currentfield,field_status(form->currentfield));

// Process the key..


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




  A4GL_add_to_control_stack (s, FORMCONTROL_KEY_PRESS, 0, 0, a);
  return -1;
}




static void
do_key_move (char lr, struct s_screenio *s, int a, int has_picture,
	     char *picture)
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
	      A4GL_get_field_width (A4GL_LL_current_field (mform)), at_first,
	      at_last, A4GL_LL_current_field (mform));

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
	  if (std_dbscr.input_wrapmode == 0
	      && A4GL_curr_metric_is_used_last_s_screenio (s, f))
	    {
	      A4GL_add_to_control_stack (s, FORMCONTROL_EXIT_INPUT_OK, 0, 0,
					 a);
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
  int acckey;
  int has_picture = 0;
  int c;
  char *picture = 0;

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
	      A4GL_get_field_width (A4GL_LL_current_field (mform)), at_first,
	      at_last, A4GL_LL_current_field (mform));

  //int npage;
  fd = A4GL_LL_get_form_userptr (mform);
  form = &fd->form_details;
  do_input_nowrap = 0;

  A4GL_debug ("proc_key .... %d", a);
  f = A4GL_LL_current_field (mform);
  A4GL_debug ("Current field=%p\n", f);
  if (a != 10)
    {
      A4GL_debug ("Getting fprop");
      fprop = (struct struct_scr_field *) (A4GL_LL_get_field_userptr (f));
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


  if (a == acckey)
    {
      A4GL_add_to_control_stack (s, FORMCONTROL_EXIT_INPUT_OK, 0, 0, a);
      return -1;
    }



  switch (a)
    {
    case 18:
      A4GL_LL_screen_refresh ();

      break;
/*

A little experiment....

    case 2: A4GL_debug("CONTROL - B %d",s->currentfield); 
A4GL_set_field_attr_with_attr(s->currentfield,0x100,0);
	  		A4GL_LL_int_form_driver (s->currform->form, AUBIT_REQ_VALIDATION);
A4GL_mja_refresh();
break;
*/


    case -100:
      A4GL_add_to_control_stack (s, FORMCONTROL_EXIT_INPUT_ABORT, 0, 0, a);
      break;


      //case 26:
      //return 0; ^Z ?

    case 127:
    case 8:
    case A4GLKEY_DC:
    case A4GLKEY_DL:
    case A4GLKEY_BACKSPACE:
      if (!has_picture)
	{
	  A4GL_LL_int_form_driver (mform, AUBIT_REQ_DEL_PREV);
	}
      else
	{			// Just like A4GLKEY_LEFT.....
	  do_key_move ('L', s, a, has_picture, picture);
	}
      break;

    case 24:
      if (!has_picture)
	{
	  A4GL_LL_int_form_driver (mform, AUBIT_REQ_DEL_CHAR);
	}
      else
	{
	  A4GL_error_nobox (acl_getenv ("FIELD_PICTURE_MSG"), 0);
	}
      break;

    case A4GLKEY_UP:
      A4GL_debug ("MJA Try to move to previous field : %d\n",
		  s->curr_attrib - 1);
      A4GL_newMovement (s, s->curr_attrib - 1);
      break;


    //case 2:
      //A4GL_debug ("FIELD OPTS : ");
      //A4GL_debug_print_field_opts (s->currentfield);
      //break;


    case '\t':
    case A4GLKEY_ENTER:
    case 13:
    case 10:
    case A4GLKEY_DOWN:
      if (std_dbscr.input_wrapmode == 0
	  && A4GL_curr_metric_is_used_last_s_screenio (s, f))
	{
	  A4GL_add_to_control_stack (s, FORMCONTROL_EXIT_INPUT_OK, 0, 0, a);
	  return 0;
	}
      A4GL_debug ("MJA Try to move to next field : %d\n", s->curr_attrib + 1);
      A4GL_newMovement (s, s->curr_attrib + 1);
      break;


    case A4GLKEY_LEFT:
      do_key_move ('L', s, a, has_picture, picture);
      break;

    case A4GLKEY_RIGHT:
      do_key_move ('R', s, a, has_picture, picture);
      break;

    case 4:			// Control - D
      if (!has_picture)
	{
	  A4GL_LL_int_form_driver (mform, AUBIT_REQ_CLR_EOF);
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
      ff = malloc (A4GL_get_field_width (f) + 1);
      A4GL_pop_char (ff, A4GL_get_field_width (f));
    }
  else
    {
      ff = malloc (A4GL_get_field_width (f) + 1);
      for (a = 0; a < A4GL_get_field_width (f); a++)
	ff[a] = ' ';
      ff[A4GL_get_field_width (f) - 1] = 0;
    }

  A4GL_mja_set_field_buffer (f, 0, ff);
  free (ff);
  A4GL_debug ("Init complete");
}



void
A4GL_mja_set_current_field (void *form, void *field)
{
  int a;
  A4GL_set_curr_infield ((long) field);
  A4GL_LL_set_current_field (form, field);
  A4GL_LL_set_carat (form);
}



void
A4GL_comments (struct struct_scr_field *fprop)
{
  //char *str;
  int cline;
  char buff[256];
  int attr;
  if (!fprop) {strcpy(buff,""); }
  else {
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

  if (cline > UILIB_A4GL_get_curr_height ())
    {
      cline = UILIB_A4GL_get_curr_height ();
    }

  attr = A4GL_get_curr_window_attr ();

  if (!attr)
    {
      attr = A4GL_determine_attribute (FGL_CMD_INPUT, 0, 0, 0);
    }


  if (A4GL_isyes (acl_getenv ("COMMENT_LIKE_INPUT")))
    {
      attr = A4GL_determine_attribute (FGL_CMD_INPUT, 0, 0, 0);
    }

  if (A4GL_isyes (acl_getenv ("COMMENT_LIKE_DISPLAY")))
    {
      attr = A4GL_determine_attribute (FGL_CMD_DISPLAY_CMD, 0, 0, 0);
    }


  UILIB_A4GL_display_internal (1, cline, buff, attr, 1);

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
A4GL_set_infield_from_parameter (int a)
{
  A4GL_debug ("**** CHANGED FIELD ****");
  inp_current_field = a;
  A4GL_debug ("New field :---> %p", inp_current_field);
}


int
A4GL_get_curr_metric (struct s_form_dets *form)
{
  int a;
  A4GL_debug ("In curr metric");
  for (a = 0; a < form->fileform->metrics.metrics_len; a++)
    {
      if (A4GL_LL_current_field (form->form) ==
	  (void *) form->fileform->metrics.metrics_val[a].field)
	{
	  A4GL_debug ("Returning %d\n", a);
	  return a;
	}
    }
  A4GL_debug ("NO current metric !");
  return -1;
}

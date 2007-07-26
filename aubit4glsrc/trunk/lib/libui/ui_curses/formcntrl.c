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
# $Id: formcntrl.c,v 1.114 2007-07-26 12:04:29 mikeaubury Exp $
#*/
#ifndef lint
	static char const module_id[] =
		"$Id: formcntrl.c,v 1.114 2007-07-26 12:04:29 mikeaubury Exp $";
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


#include "a4gl_lib_ui_tui_int.h"
#include <ctype.h>
#define CONTROL_STACK_LENGTH 10
//void A4GL_fgl_die_with_msg(int n,char *s);


char *a_strchr(char *s,int c);
void A4GL_idraw_arr_all (struct s_inp_arr *inpa);

static int internal_A4GL_form_loop_v2 (void *vs, int init,void *vevt);

static int A4GL_has_something_on_control_stack (struct s_screenio *sio);
static void A4GL_add_to_control_stack (struct s_screenio *sio, enum e_formcontrol op,
				       FIELD * f, char *parameter,
				       int extent,int line);
static void A4GL_newMovement (struct s_screenio *arr, int attrib);
static void A4GL_init_control_stack (struct s_screenio *sio, int malloc_data);
static int A4GL_proc_key_input (int a, FORM * mform, struct s_screenio *s);
static void do_key_move_fc (char lr, struct s_screenio *s, int a,
			 int has_picture, char *picture);
char *A4GL_fld_data_ignore_format(struct struct_scr_field *fprop,char *fld_data) ;
static char *last_field_name;
static int last_key_code;
//int A4GL_has_event(int a,struct aclfgl_event_list *evt) ;
//int A4GL_has_event_for_keypress(int a,struct aclfgl_event_list *evt) ;
//int A4GL_has_event_for_field(int cat,char *a,struct aclfgl_event_list *evt) ;
int A4GL_get_metric_for (struct s_form_dets *form, void *f);
int A4GL_construct_large(char *orig, struct aclfgl_event_list *evt,int init_key,int initpos, struct struct_scr_field *fprop) ;
void A4GL_set_infield_from_parameter (long a);
int A4GL_do_after_field (FIELD * f, struct s_screenio *sio);
void A4GL_clr_field (FIELD * f);
void A4GL_make_window_with_this_form_current(void *form);
int A4GL_field_is_noentry(int doing_construct, struct struct_scr_field *f);

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
extern WINDOW *currwin;
char m_delims[10]="[]|";


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
A4GL_add_to_control_stack (struct s_screenio *sio, enum e_formcontrol op, FIELD * f,
			   char *parameter, int extent,int line)
{
  char *field_name;
  int a;
  struct struct_scr_field *attr;

  A4GL_debug ("add to control stack called with op=%d(%s) field=%p extent=%d line=%d cnt=%d",
	      op, ops[op], f, extent,line,sio->fcntrl_cnt);

  field_name = 0;

  if (f)
    {
      attr = (struct struct_scr_field *) field_userptr (f);
      field_name = attr->colname;
    }


  if (op==FORMCONTROL_KEY_PRESS) {
	if (A4GL_is_special_key(extent,A4GLKEY_ACCEPT)) {
			extent=A4GLKEY_ACCEPT;
  			A4GL_set_last_key (A4GLKEY_ACCEPT);
	}
  }


  a = sio->fcntrl_cnt;
  if (a>=10) {
		A4GL_assertion(1,"Loop in formcntrl.c ?");
  }
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
  void *last_field;
  void *next_field;
  struct struct_scr_field *f;


  A4GL_debug ("newMovement %d ", attrib);

  if (attrib < 0)
    {
      	// attempt to move too far to the left
      	A4GL_debug ("Too far to the left");
 	// cc 2004.11.15 
 	if (sio->currform->currentfield == sio->field_list[0] && A4GL_get_dbscr_inputmode()!= 0) {
 		A4GL_debug ("Wrap around from top to bottom"); 
 		A4GL_newMovement (sio, sio->nfields); 
 		return; 
 	} 
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



  ptr = acl_malloc2 (sizeof (struct s_movement));
  ptr->scr_line = -1;		// Not used for a normal input/construct
  ptr->arr_line = -1;		// Not used for a normal input/construct
  ptr->attrib_no = attrib;

  last_field = sio->currform->currentfield;

  A4GL_debug ("last field was : %p", sio->currform->currentfield);
A4GL_debug("field=%d %p\n",attrib,sio->field_list);
  next_field = sio->field_list[attrib];
  f = (struct struct_scr_field *) (field_userptr (next_field));

  if ( A4GL_field_is_noentry((sio->mode == MODE_CONSTRUCT),f) || (f->datatype == DTYPE_SERIAL && sio->mode != MODE_CONSTRUCT)) {
      int dir = 0;
      A4GL_debug("Looking across ");
      while (1)
	{

	  if (dir == 0)
	    {
	      if (attrib >= sio->curr_attrib ||
		      sio->curr_attrib == sio->nfields) // last field - wrap to the first
		{		// We want to move to the right..
		  dir = 1;
		}
	      else
		{
		  dir = -1;
		}
	    }
	  next_field = sio->field_list[attrib];
	  f = (struct struct_scr_field *) (field_userptr (next_field));

	  if ( A4GL_field_is_noentry((sio->mode == MODE_CONSTRUCT),f) || (f->datatype == DTYPE_SERIAL  && sio->mode != MODE_CONSTRUCT))
	    {
		A4GL_debug("Looking across");
	      attrib += dir;
		A4GL_debug("Looking across dir=%d attrib=%d nfields=%d",dir,attrib,sio->nfields);
	      if (attrib > sio->nfields)
		{


		  if (A4GL_get_dbscr_inputmode() == 0)
		    {
	A4GL_debug("ACCEPT - EXIT_INPUT_OK\n");
		      A4GL_add_to_control_stack (sio,
						 FORMCONTROL_EXIT_INPUT_OK, 0,
						 0, 0,__LINE__);
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
					      sizeof (struct s_movement)), 0,__LINE__);
      if (last_field)
	{
		A4GL_debug("ADD AFTER FIELD <------------------------------------");
	  A4GL_add_to_control_stack (sio, FORMCONTROL_AFTER_FIELD, last_field,
				     0, 0,__LINE__);
	}
      acl_free (ptr);
    }
  else
    {
      acl_free (ptr);
    }

  A4GL_debug ("Done newMovement - last_field was %p new_field is %p",
	      last_field, new_field);
}



/* 
* process any waiting actions 
*
*/
static int
process_control_stack_internal (struct s_screenio *sio,struct aclfgl_event_list *evt)
{
  int a;
  int rval;
  int new_state;
  struct s_movement *ptr_movement;

  rval = -1;
  new_state = 99;

  a = sio->fcntrl_cnt - 1;
  A4GL_debug("process control stack - op=%d state=%d\n",sio->fcntrl[a].op,sio->fcntrl[a].state);

  if (sio->fcntrl[a].op == FORMCONTROL_BEFORE_INPUT)
    {
      new_state = 0;
      rval = A4GL_EVENT_BEFORE_INP;
    }

  if (sio->fcntrl[a].op == FORMCONTROL_AFTER_INPUT)
    {
      if (sio->fcntrl[a].state == 99)
	{
	  new_state = 50;
	  rval = A4GL_EVENT_AFTER_INP;		// Do any AFTER INPUT section
	}

      if (sio->fcntrl[a].state == 50)
	{
	  new_state = 0;
	  rval = A4GL_EVENT_AFTER_INP_CLEAN;		// CLEANUP
	}
    }


  if (sio->fcntrl[a].op == FORMCONTROL_EXIT_INPUT_OK)
    {
      A4GL_comments (0);
      if (sio->fcntrl[a].state == 99)
	{
		A4GL_debug("ADD AFTER FIELD <------------------------------------");
	  A4GL_add_to_control_stack (sio, FORMCONTROL_AFTER_FIELD,
				     sio->currentfield, 0, 0,__LINE__);
	  new_state = 60;
	  rval = -1;
	}

      if (sio->fcntrl[a].state == 60)
	{	
		int a;

		a=chk_all_fields(sio);
		if (a>=0) {
	  		new_state = 0;
      			A4GL_init_control_stack (sio, 0);
      			A4GL_newMovement (sio, a);
		} else {
			new_state=50;
	  	}
	  	rval = -1;
	}


      if (sio->fcntrl[a].state == 50)
	{
	  A4GL_add_to_control_stack (sio, FORMCONTROL_AFTER_INPUT, 0, 0, 0,__LINE__);
	  new_state = 10;
	  rval = -1;
	}


      if (sio->fcntrl[a].state == 10)
	{
	  new_state = 0;
	  rval = -1;
	}


    }


  if (sio->fcntrl[a].op == FORMCONTROL_EXIT_INPUT_ABORT)
    {
	if (sio->fcntrl[a].state==99) {
      		A4GL_comments (0);
      		A4GL_debug ("FORM ABORT..");
      		int_flag = 1;
      		A4GL_add_to_control_stack (sio, FORMCONTROL_AFTER_INPUT, 0, 0, 0,__LINE__);
      		rval = -1;
      		new_state = 10;
	}

	if (sio->fcntrl[a].state==10) {
		if (sio->mode==MODE_CONSTRUCT) {
			sio->processed_onkey=A4GLKEY_INTERRUPT;
		}
		new_state=0;
	}
    }




  if (sio->fcntrl[a].op == FORMCONTROL_KEY_PRESS)
    {


      if (sio->fcntrl[a].state == 99)
	{
	  new_state = 75;
          if (sio->mode == MODE_CONSTRUCT && last_key_code!=A4GLKEY_CANCEL) {
			if (A4GL_has_event_for_keypress(sio->fcntrl[a].extent,evt)) { // We should be a litle worried...
					if (!A4GL_do_after_field (sio->currform->currentfield, sio)) {
							new_state=0;
					}
			}
	  }

	if (new_state!=0) {
	  		last_key_code=sio->fcntrl[a].extent;
	  		rval = A4GL_EVENT_KEY_PRESS;
		}
	}


      if (sio->fcntrl[a].state == 75)
	{
	  new_state = 50;
	  if (sio->processed_onkey != 0)
	    {
	      A4GL_proc_key_input (sio->fcntrl[a].extent, sio->currform->form, sio);
	    }
	  rval = -1;
	}


      if (sio->fcntrl[a].state == 50)
	{
	  struct struct_scr_field *fprop;
	  int has_picture = 0;
	  char *picture = 0;
	  int ok = 0;
	  new_state = 10;

	  fprop = (struct struct_scr_field *) (field_userptr (sio->currentfield));

	A4GL_debug_print_field_opts (sio->currentfield);

	  A4GL_debug ("Checking key state.. %d", sio->fcntrl[a].extent);
	  if (A4GL_has_str_attribute (fprop, FA_S_PICTURE))
	    {
	      has_picture = 1;
	      picture = A4GL_get_str_attribute (fprop, FA_S_PICTURE);
	    }
	  if (sio->mode == MODE_CONSTRUCT)
	    has_picture = 0;

	
	//if (sio->fcntrl[a].extent=='1') {A4GL_pause_execution();}

	  if (sio->fcntrl[a].extent >= 0 && sio->fcntrl[a].extent <= 255
	      &&
	      ((a_isprint (sio->fcntrl[a].extent) || sio->fcntrl[a].extent == 1
		|| sio->fcntrl[a].extent == 4)))
	    {
	      if ((fprop->flags & 1) == 0 && !has_picture)
		{
		  switch (sio->vars[sio->curr_attrib].dtype & DTYPE_MASK)
		    {
		    case DTYPE_SMINT:
		    case DTYPE_INT:
		    case DTYPE_SERIAL:
		    case DTYPE_FLOAT:
		    case DTYPE_DATE:
		    case DTYPE_SMFLOAT:
		    case DTYPE_DECIMAL:
		    case DTYPE_MONEY:
		      A4GL_int_form_driver (sio->currform->form, REQ_CLR_EOF);
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
		  FORM *mform;
		  mform = sio->currform->form;
		  	A4GL_debug("curcol");
		  i = mform->curcol;
		  	A4GL_debug("curcol");
		  ok = 1;
		  key = sio->fcntrl[a].extent;

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
		  A4GL_int_form_driver (sio->currform->form, sio->fcntrl[a].extent);
		  A4GL_int_form_driver (sio->currform->form, REQ_VALIDATION);
		}


	      if (has_picture && ok)
		{
		  FORM *mform;
		  mform = sio->currform->form;
		  	A4GL_debug("curcol");
		  if (a_strchr ("A#X", picture[mform->curcol]) == 0
		      && picture[mform->curcol])
		    do_key_move_fc ('R', sio, sio->fcntrl[a].extent, has_picture, picture);
		}

	    }
	  A4GL_debug("Clr because of %d", sio->fcntrl[a].extent);
		if (fprop->flags&2 ||  sio->fcntrl[a].extent==A4GLKEY_RIGHT) { // has it changed ? 
	  		fprop->flags |= 1;	// Clear the before field flag
		}
	  rval = -1;
	}


      if (sio->fcntrl[a].state == 10)
	{
	  struct struct_scr_field *fprop;
	  new_state = 5;

	  rval = -1;


	  if (sio->fcntrl[a].extent >= 28 && sio->fcntrl[a].extent <= 255)
	    {
	      fprop = (struct struct_scr_field *) (field_userptr (sio->currentfield));
	      if (A4GL_has_bool_attribute (fprop, FA_B_AUTONEXT))
		{
		  FORM *curses_form;
		  curses_form = sio->currform->form;

		  if (current_field (curses_form) != sio->currentfield || curses_form->curcol==0)
		    {
	  		if (A4GL_get_dbscr_inputmode() == 0 && A4GL_curr_metric_is_used_last_s_screenio (sio, sio->currentfield)) {
	      			A4GL_add_to_control_stack (sio, FORMCONTROL_EXIT_INPUT_OK, 0, 0, 0,__LINE__);
			} else {
		      		set_current_field (curses_form, sio->currentfield);
		      		A4GL_newMovement (sio, sio->curr_attrib + 1);
			}
		    }

		}
	    }

	}

      if (sio->fcntrl[a].state == 5)
        {
		A4GL_debug("abort_pressed=%d last_key_code=%d extent=%d",abort_pressed,last_key_code,sio->fcntrl[a].extent);
          if (sio->mode == MODE_CONSTRUCT && last_key_code!=A4GLKEY_CANCEL) {
                        struct s_form_dets *form;
                        char rbuff[1024];
			FIELD *xw;
                        int w;
			FORM *mform;
                        form=sio->currform;
			mform=form->form;
			xw= current_field (mform);


			if (sio->currentfield!=xw) {
					A4GL_debug("Wrong current field?"); 
			}
			memset(rbuff,0,sizeof(rbuff));
                        strcpy(rbuff,field_buffer(sio->currentfield,0));
                        A4GL_trim(rbuff);
                        w=form->fileform->metrics. metrics_val[A4GL_get_metric_for (form, form->currentfield)].w;
                        A4GL_debug("CONSTRUCT - do we need a large window : '%s' gfw=%d strlen=%d w=%d",rbuff,
							A4GL_get_field_width(sio->currentfield),strlen(rbuff),w);
                        if (strlen(rbuff)>=w) {
                                struct struct_scr_field *fprop;
                                int k;
				int lm;
				FIELD *cf;
				strcpy(m_delims,form->fileform->delim);
		  	A4GL_debug("curcol");

				lm=mform->curcol;
                               	set_field_buffer (sio->currentfield,0,rbuff); 
				mform->curcol=lm;
				cf=sio->currentfield;
				
	      			fprop = (struct struct_scr_field *) (field_userptr (sio->currentfield));
                                k=A4GL_construct_large(rbuff,evt,sio->fcntrl[a].extent,mform->curcol, fprop);
			

				if (k==A4GLKEY_CANCEL) {
					A4GL_add_to_control_stack (sio, FORMCONTROL_EXIT_INPUT_ABORT, 0, 0, k,__LINE__);
				} else {
                                	fprop = (struct struct_scr_field *) (field_userptr (sio->currentfield));
                                	if (A4GL_has_bool_attribute (fprop, FA_B_DOWNSHIFT) && a4gl_isupper (k) && a4gl_isalpha (k)) { k = a4gl_tolower (k); }
                                	if (A4GL_has_bool_attribute (fprop, FA_B_UPSHIFT) && a4gl_islower (k) && a4gl_isalpha (k)) { k = a4gl_toupper (k); }
					

					// This isn't right....
					// the keypress will already have been mostly actioned...
                                	A4GL_add_to_control_stack (sio, FORMCONTROL_KEY_PRESS, 0, 0, k,__LINE__);

                                	set_field_buffer (sio->currentfield,0,rbuff);
				}
				sio->currentfield=cf;
                        }
          }
          new_state = 2;
          rval = -1;
        }


      if (sio->fcntrl[a].state == 2)
        {
		A4GL_debug("Field now : %s",field_buffer(sio->currentfield,0));
                rval=-1;
                new_state=0;
        }





    }


  if (sio->fcntrl[a].op == FORMCONTROL_BEFORE_FIELD)
    {
      struct struct_scr_field *fprop;
      int attr;
      A4GL_debug ("FORM_BEFORE_FIELD - state=%d", sio->fcntrl[a].state);
      if (sio->fcntrl[a].state == 99)
	{
	  new_state = 50;
	  ptr_movement = (struct s_movement *) sio->fcntrl[a].parameter;
	  sio->curr_attrib = ptr_movement->attrib_no;


	  last_field_name=sio->fcntrl[a].field_name;
 	  A4GL_set_infield_from_parameter ((long) sio->field_list[sio->curr_attrib]);
	  A4GL_debug ("Setting rval to A4GL_EVENT_BEFORE_FIELD_1");
	  rval = A4GL_EVENT_BEFORE_FIELD_1;
	}

      if (sio->fcntrl[a].state == 50)
	{
         int rval;
	  sio->currentfield = sio->field_list[sio->curr_attrib];
	A4GL_debug_print_field_opts (sio->currentfield);
	  rval=set_current_field (sio->currform->form, sio->currentfield);
		if (rval!=E_OK) {
			printf("RVAL=%d\n",rval);
			A4GL_assertion(1,"Unable to set current tield...");
			}
	  sio->currform->currentfield = sio->currentfield;
	  pos_form_cursor (sio->currform->form);
	  A4GL_debug ("Processed after users 'BEFORE FIELD'");
	  pos_form_cursor (sio->currform->form);
	  fprop = (struct struct_scr_field *) (field_userptr (sio->currentfield));
	
	  attr = A4GL_determine_attribute (FGL_CMD_INPUT, sio->attrib, fprop, field_buffer (sio->currentfield, 0));

	  if (attr != 0) {
			A4GL_debug("ATTR!=0");
			A4GL_set_field_attr_with_attr (sio->currentfield, attr, FGL_CMD_INPUT);
	  } else {
			A4GL_debug("ATTR==0");
	  }

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
			      field_buffer (sio->currentfield, 0));
		  w = A4GL_get_field_width (sio->currentfield);
		  has_picture = 1;
		  picture = A4GL_get_str_attribute (fprop, FA_S_PICTURE);
		  ptr = acl_malloc2 (w + 1);

		  strcpy (ptr, field_buffer (sio->currentfield, 0));
		  ptr[w] = 0;

		  for (a = 0; a < strlen (picture); a++)
		    {
		      if (a > w)
			break;

		      if (picture[a] == 'A')
			{
			  if (!a4gl_isalpha ((int)ptr[a]))
			    ptr[a] = ' ';
			  continue;
			}

		      if (picture[a] == '#')
			{
			  if (!isdigit ((int)ptr[a]))
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

		  A4GL_set_init_value (sio->currentfield, ptr, 0);
		  if (picture[0]!='9'&&picture[0]!='#' && picture[0]!='X') {
			if (strchr(&picture[1],'9')
			||strchr(&picture[1],'#')
			||strchr(&picture[1],'X')) {
				// Theres no point in moving across if theres
				// nothing to move to
		  		do_key_move_fc ('R', sio, 0, 1, picture);
			}
		  }

		  A4GL_debug ("XYX Set field : %s", ptr);
		  acl_free (ptr);
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
		  A4GL_int_form_driver (sio->currform->form, REQ_OVL_MODE);	// Always in overwrite mode in a picture...
		}


	    }

	  A4GL_comments (fprop);

	  //if ((fprop->flags & 1)) {
	    	fprop->flags = 0;	// Clear a flag to indicate that we're just starting on this field
	  //}
	  new_state = 0;
	  A4GL_debug ("Setting rval to -1");
	}



    }


  if (sio->fcntrl[a].op == FORMCONTROL_AFTER_FIELD)
    {

      int ffc_rval;
      struct struct_scr_field *fprop;
      int attr;

	A4GL_debug("AFTER FIELD - mode=%d (construct=%d)",sio->mode,MODE_CONSTRUCT);

      if (sio->mode != MODE_CONSTRUCT)
	ffc_rval = A4GL_form_field_chk (sio, -1);
      else {
	int daf;
	ffc_rval = A4GL_form_field_constr (sio, -1);
	daf=A4GL_do_after_field(sio->currentfield,sio);
	if (!daf) ffc_rval=-4;
	}


      A4GL_debug ("form_Field_chk returns %d\n", ffc_rval);

      if (ffc_rval != -4)
	{
	int really_ok=0;
	  new_state = 0;
	  fprop =
	    (struct struct_scr_field *) (field_userptr (sio->currentfield));
	  if (sio->mode != MODE_CONSTRUCT)
	    {
	      char *picture;
	      int field_no;
	      char buff[10024];
		char *fld_b;
	      field_no = sio->curr_attrib;
		if (sio->currentfield==0) {
			A4GL_fgl_die_with_msg(1,"No current field");
		}
		fld_b=field_buffer(sio->currentfield,0);
		if (fld_b==0) {
			A4GL_fgl_die_with_msg(1,"No current field buffer");
		}
	      strncpy (buff, fld_b,sizeof(buff));
		buff[10023]=0;
		if (strlen(buff)>=10023) {
			A4GL_fgl_die_with_msg(1,"Internal error or string too long");
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
	if (fprop->flags) {

	      A4GL_trim (buff);

	      if (strlen (buff))
		{
	          char buff2[10024];
		  A4GL_debug ("Field is not null");
		strcpy(buff2,A4GL_fld_data_ignore_format(fprop,buff));
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

		
	        A4GL_pop_param (sio->vars[field_no].ptr, sio->vars[field_no].dtype, sio->vars[field_no].size);

		if (sio->vars[field_no].dtype==0) {
			A4GL_debug("sio->vars[field_no].ptr=%s",sio->vars[field_no].ptr);
		}

		really_ok=1;
		A4GL_trim(buff);
		if (strlen(buff)&&A4GL_isnull(sio->vars[field_no].dtype,sio->vars[field_no].ptr)) {
			A4GL_debug("Not empty and var is null");
			really_ok=0;
		}

		if (!A4GL_conversion_ok(-1)) {
			A4GL_debug("CONVERSION ERROR");
			really_ok=0;
		}

                if ( (sio->vars[field_no].dtype==DTYPE_INT|| sio->vars[field_no].dtype==DTYPE_SMINT|| sio->vars[field_no].dtype==DTYPE_SERIAL)){
			 if (a_strchr(buff,A4GL_get_convfmts()->ui_decfmt.decsep) ) {
				A4GL_debug("%c in an integer", A4GL_get_convfmts()->ui_decfmt.decsep);
				really_ok=0;
			}
		}


		if (really_ok==0) {
			// 
                        A4GL_error_nobox (acl_getenv ("FIELD_ERROR_MSG"), 0);
 			A4GL_comments (fprop);
                        if (A4GL_isyes(acl_getenv("A4GL_CLR_FIELD_ON_ERROR"))) {
                                        A4GL_clr_field (sio->currform->currentfield);
                        } else {
                                if (A4GL_isyes(acl_getenv("FIRSTCOL_ONERR"))) {
                                        A4GL_int_form_driver (sio->currform->form, REQ_BEG_FIELD);
                                }

                        }


                        set_current_field (sio->currform->form, sio->currform->currentfield);
          		A4GL_init_control_stack (sio, 0);
          		return -1;
		}

		A4GL_debug("It would appear that %s could be put into my variable... type=%d size=%d",buff,sio->vars[field_no].dtype,sio->vars[field_no].size);

	      A4GL_push_char (buff);

	      A4GL_debug ("Calling display_field_contents");
	      A4GL_display_field_contents (sio->currentfield, sio->vars[field_no].dtype + ENCODE_SIZE (sio->vars[field_no].size), sio->vars[field_no].size, sio->vars[field_no].ptr);	// MJA 2306

	      fprop =
		(struct struct_scr_field
		 *) (field_userptr (sio->currentfield));
	      attr =
		A4GL_determine_attribute (FGL_CMD_INPUT, sio->attrib, fprop,
					  field_buffer (sio->currentfield,
							0));
	      if (attr != 0)
		A4GL_set_field_attr_with_attr (sio->currentfield, attr,
					       FGL_CMD_INPUT);
		}
	    }

 	  A4GL_set_infield_from_parameter ((long)sio->currentfield);
	  last_field_name=sio->fcntrl[a].field_name;




	  rval = A4GL_EVENT_AFTER_FIELD_1;
	}
      else
	{
             if (A4GL_isyes(acl_getenv("FIRSTCOL_ONERR_INCL"))) {
                         A4GL_int_form_driver (sio->currform->form, REQ_BEG_FIELD);
             }

	  A4GL_init_control_stack (sio, 0);
	  return -1;
	}
    }



  if (new_state != 0 && sio->fcntrl[a].op != 0)
    {
      if (sio->fcntrl[a].state == new_state)
	{
	  A4GL_debug ("internal error - state=%d op=%d (%s) @ %d", new_state,
		      sio->fcntrl[a].op, ops[sio->fcntrl[a].op], a);
	  A4GL_exitwith ("Internal error - no change in state ");
	  return -1;
	}
      A4GL_debug ("Setting input control state to %d", new_state);
      sio->fcntrl[a].state = new_state;
    }
  else
    {
      A4GL_debug ("Popping type %d (%s) off control stack @ %d", sio->fcntrl[a].op, ops[sio->fcntrl[a].op], a);
      sio->fcntrl_cnt--;
      if (sio->fcntrl[a].parameter)
	{
	  acl_free (sio->fcntrl[a].parameter);
	}
    }
  A4GL_debug ("Returning %d\n", rval);
  return rval;
}

static int process_control_stack (struct s_screenio *sio,struct aclfgl_event_list *evt) {
int rval;
rval=process_control_stack_internal(sio,evt);
A4GL_debug("Got rval as : %d",rval);
switch (rval) {
	case A4GL_EVENT_BEFORE_FIELD_1: if (A4GL_has_event_for_field(A4GL_EVENT_BEFORE_FIELD,last_field_name,evt)) { return A4GL_has_event_for_field(A4GL_EVENT_BEFORE_FIELD,last_field_name,evt); } rval=-1;break;
	case A4GL_EVENT_AFTER_FIELD_1: if (A4GL_has_event_for_field(A4GL_EVENT_AFTER_FIELD,last_field_name,evt)) { return A4GL_has_event_for_field(A4GL_EVENT_AFTER_FIELD,last_field_name,evt); } rval=-1;break;
	case A4GL_EVENT_KEY_PRESS :if (A4GL_has_event_for_keypress(last_key_code,evt)) { sio->processed_onkey=0; return A4GL_has_event_for_keypress(last_key_code,evt);} rval=-1;break;
 	case A4GL_EVENT_BEFORE_INP: if (A4GL_has_event(A4GL_EVENT_BEFORE_INP,evt)) return A4GL_has_event(A4GL_EVENT_BEFORE_INP,evt);rval=-1;break;
 	case A4GL_EVENT_AFTER_INP: if (A4GL_has_event(A4GL_EVENT_AFTER_INP,evt)) return A4GL_has_event(A4GL_EVENT_AFTER_INP,evt);rval=-1;break;
 	case A4GL_EVENT_AFTER_INP_CLEAN: if (A4GL_has_event(A4GL_EVENT_AFTER_INP_CLEAN,evt)) return A4GL_has_event(A4GL_EVENT_AFTER_INP_CLEAN,evt);rval=-1;break;

}
if (rval>=0||rval==-1) return -1;


A4GL_debug("Code : %d\n",rval);
A4GL_exitwith("Unhandled code...");
exit(1);
}

int
UILIB_A4GL_req_field_input (void *sv, char type, va_list * ap)
{
  struct s_screenio *s;
/* fieldname + = next - = previous */
  int a;
  FIELD **ptr;
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
		free(ptr);
	      return 1;
	    }
	}
		free(ptr);
      A4GL_exitwith ("Field not found");
      return 0;
    }
  else
    {
      A4GL_exitwith ("Field not found");
      return 0;
    }
}



int UILIB_A4GL_form_loop_v2 (void *vs, int init, void *vevt) {
	        int a;
		a=-1;
		while (1) {

	        a=internal_A4GL_form_loop_v2(vs,init,vevt);
			if (init||a!=-1) break;
		}
	       return a;
}



/**
 * 4GL CALL
 * @todo Describe function
 */
static int internal_A4GL_form_loop_v2 (void *vs, int init,void *vevt)
{
  struct s_form_dets *form;
  struct aclfgl_event_list *evt;
  int a;
  struct s_screenio *s;
  struct struct_scr_field *fprop;
  struct struct_metrics *metrics;
  FORM *mform;
  int blk;
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
  A4GL_debug ("form_loop0..  currentfield=%p ZZFIELD status = %d", form->currentfield, field_status (form->currentfield));

  if (form != UILIB_A4GL_get_curr_form (0))
    {

        A4GL_make_window_with_this_form_current(form);
    }

  if (form != UILIB_A4GL_get_curr_form (0))
    {
        A4GL_exitwith ("Input form is not the current form!");
        return 0;
    }

  mform = form->form;






 A4GL_mja_wrefresh (currwin);

  if (init)
    {
      A4GL_init_control_stack (s, 1);
      s->curr_attrib = 0;
      s->currentfield = 0;
      A4GL_newMovement (s, 0);
      A4GL_clr_evt_timeouts(evt);
      A4GL_add_to_control_stack (s, FORMCONTROL_BEFORE_INPUT, 0, 0, 0,__LINE__);
    }

  if (A4GL_has_something_on_control_stack (s))
    {
      int rval;
      rval = process_control_stack (s,evt);
      A4GL_debug ("Control stack - he say %d", rval);
      return rval;
    }



  fprop = (struct struct_scr_field *) field_userptr (current_field (mform));
  metrics = &form->fileform->metrics.metrics_val[A4GL_get_curr_metric (form)];

  if (metrics && (long) metrics != -1)
    {
      set_form_page (mform, metrics->scr - 1);
    }

  A4GL_mja_set_current_field (mform, form->currentfield);
  A4GL_mja_pos_form_cursor (mform);

  while (1) {

    	blk=A4GL_has_evt_timeout(evt);
    	if (blk) { return blk; }


  // cc 2004.09.14 fprop may have been changed, always read it again
  fprop = (struct struct_scr_field *) field_userptr (current_field (mform));
// Wait for a key..


  	a = A4GL_getch_win ();


  	if (a!=0&&a!=-1) {
	  	A4GL_evt_not_idle(evt);
		break;
  	}

  	if (abort_pressed) {
	  	A4GL_evt_not_idle(evt);
		a = A4GLKEY_INTERRUPT;
		break;
	}
  }


  if (a!=0) {
  	s->processed_onkey = a;
  	A4GL_set_last_key(a);
	A4GL_debug("Current fields options : ");
	A4GL_debug_print_field_opts(form->currentfield);
  	A4GL_debug("setting last key : %d",a);
  	A4GL_set_last_key (a);
  	A4GL_debug("set : %d",a);
  	A4GL_clr_error_nobox ("A4GL_form_loop");


  	A4GL_debug ("form_loop1..  currentfield=%p ZZFIELD status = %d", form->currentfield, field_status (form->currentfield));

// Process the key..


  	A4GL_debug("process");
  	if (fprop != 0)
    	{
      	A4GL_debug ("Downshift?");
      	if (A4GL_has_bool_attribute (fprop, FA_B_DOWNSHIFT) && a4gl_isupper (a)
	  	&& a4gl_isalpha (a))
		{
	  	a = a4gl_tolower (a);
		}
      	A4GL_debug ("Upshift ?");
      	if (A4GL_has_bool_attribute (fprop, FA_B_UPSHIFT) && a4gl_islower (a)
	  	&& a4gl_isalpha (a))
		{
	  	a = a4gl_toupper (a);
		}
    	}
	

	
	A4GL_debug("Got a key press - %d\n",a);
	if (a) {
  		A4GL_add_to_control_stack (s, FORMCONTROL_KEY_PRESS, 0, 0, a,__LINE__);
	}
  }
  return -1;
}




static void
do_key_move_fc (char lr, struct s_screenio *s, int some_a, int has_picture,
	     char *picture)
{
  int at_last = 0;
  int at_first = 0;
  FIELD *f;
  FORM *mform;
  mform = s->currform->form;
  f = s->currentfield;

		  	A4GL_debug("curcol");
  if (mform->curcol == 0)
    {
      at_first = 1;
    }

		  	A4GL_debug("curcol");
  if (mform->curcol == A4GL_get_field_width (current_field (mform)) - 1 )
    {
      at_last = 1;
      A4GL_debug ("AT LAST..... XYXYXY");
    }

  if (lr == 'L')
    {
      if (at_first)
	{
	      A4GL_newMovement (s, s->curr_attrib - 1);	//  go to previous field
	      return;

	}
      else
	{
	  A4GL_int_form_driver (mform, REQ_PREV_CHAR);	// go to previous character
	}
    }

  if (lr == 'R')
    {
      if (at_last)
	{			// Acts like KEY_DOWN at last position in the field
	  A4GL_debug ("AT LAST");
	  if (A4GL_get_dbscr_inputmode() == 0 && A4GL_curr_metric_is_used_last_s_screenio (s, f)) {
		A4GL_debug("AT LAST <-----------------------------------------");
	      A4GL_add_to_control_stack (s, FORMCONTROL_EXIT_INPUT_OK, 0, 0,
					 some_a,__LINE__);
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
		A4GL_int_form_driver (mform, REQ_NEXT_CHAR);
	}
    }
  A4GL_int_form_driver (s->currform->form, REQ_VALIDATION);


  if (has_picture)
    {
      int newpos;
      FORM *mform;
      mform = s->currform->form;
      newpos = mform->curcol;
		  	A4GL_debug("curcol");
      if (a_strchr ("A#X", picture[newpos]))
	return;
      do_key_move_fc (lr, s, some_a, has_picture, picture);
    }
  return;

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
  int has_picture = 0;
  char *picture = 0;
  int isWordWrap = 0;


  int at_first = 0;
  int at_last = 0;

  A4GL_debug ("curcol");
  if (mform->curcol == 0)
    {
      at_first = 1;
    }

  A4GL_debug ("curcol");
  if (mform->curcol == A4GL_get_field_width (current_field (mform)) - 1)
    {
      A4GL_debug ("AT LAST");
      at_last = 1;
    }

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


	  if (A4GL_has_str_attribute (fprop, FA_S_PICTURE))
	    {
	      has_picture = 1;
	      picture = A4GL_get_str_attribute (fprop, FA_S_PICTURE);
	    }
	  if (s->mode == MODE_CONSTRUCT)
	    has_picture = 0;	/* We don't use the picture in a construct... */


	  A4GL_debug ("Downshift?");
	  if (A4GL_has_bool_attribute (fprop, FA_B_DOWNSHIFT)
	      && a4gl_isupper (a) && a4gl_isalpha (a))
	    {
	      a = a4gl_tolower (a);
	    }
	  A4GL_debug ("Upshift ?");
	  if (A4GL_has_bool_attribute (fprop, FA_B_UPSHIFT))
	    {
	      int x_islower = 0;
	      int x_isalpha = 0;
	      x_islower = a4gl_islower (a);
	      x_isalpha = a4gl_isalpha (a);
	      if (x_islower && x_isalpha)
		{
		  a = a4gl_toupper (a);
		}
	    }
	}

    }


  if (A4GL_is_special_key (a, A4GLKEY_ACCEPT))
    {
      A4GL_set_last_key (A4GLKEY_ACCEPT);
      A4GL_debug ("ACCEPT - EXIT_INPUT_OK\n");
      A4GL_add_to_control_stack (s, FORMCONTROL_EXIT_INPUT_OK, 0, 0, a,
				 __LINE__);
      return -1;
    }



  if (A4GL_has_bool_attribute (fprop, FA_B_WORDWRAP))
    {
      isWordWrap = 1;
    }

  switch (a)
    {
    case 18:
      clearok (curscr, 1);
      A4GL_mja_refresh ();
      break;

    case A4GLKEY_INTERRUPT:
      A4GL_add_to_control_stack (s, FORMCONTROL_EXIT_INPUT_ABORT, 0, 0, a,
				 __LINE__);
      break;



    case 127:
    case 8:
    case A4GLKEY_DC:
    case A4GLKEY_DL:
    case A4GLKEY_BACKSPACE:
      if (!has_picture)
	{
	  A4GL_int_form_driver (mform, REQ_DEL_PREV);
	      fprop->flags |= 2;	// Set the field status flag
	}
      else
	{			// Just like A4GLKEY_LEFT.....
	  do_key_move_fc ('L', s, a, has_picture, picture);
	}
      break;

    case 24:
      if (!has_picture)
	{
	  A4GL_int_form_driver (mform, REQ_DEL_CHAR);
	      fprop->flags |= 2;	// Set the field status flag
	}
      else
	{
	  A4GL_error_nobox (acl_getenv ("FIELD_PICTURE_MSG"), 0);
	}
      break;

    case A4GLKEY_UP:
	if (isWordWrap) {
		int cHeight;
		//int curPos;
		int r;
	  	cHeight = mform->currow;
		r=mform->curcol;
	      	if (cHeight >0) {
		  	A4GL_int_form_driver (mform, REQ_PREV_LINE);
			while (mform->curcol< r) {
		  		A4GL_int_form_driver (mform, REQ_NEXT_CHAR);
			}
			break;
		}
	}
      	A4GL_debug ("MJA Try to move to previous field : %d\n", s->curr_attrib - 1);
      	A4GL_newMovement (s, s->curr_attrib - 1);
      break;

    case 2:
      A4GL_debug ("FIELD OPTS : ");
      A4GL_debug_print_field_opts (s->currentfield);
      break;





    case '\t':
      if (isWordWrap)
	{
	  // strange handling...
	  int w;
	  int r;
	  int cnt;
	  int cHeight;
	  //A4GL_pause_execution();
	  w = A4GL_get_field_width_w (f, 0);
	  r = mform->curcol + 1;
	  while (r % 8 != 0)
	    r++;
	  cHeight = mform->currow;
	  if (r > w)
	    {
	      int fieldHeight;
	      fieldHeight = A4GL_get_field_height (f);
	      A4GL_debug ("fieldHeight=%d cHeight=%d", fieldHeight, cHeight);
	      if (cHeight + 1 < fieldHeight)
		{
		  A4GL_int_form_driver (mform, REQ_NEXT_LINE);
		}
	      else
		{
		  if (A4GL_isyes (acl_getenv ("WAITENDOFWORDWRAP")))
		    {
		      r = w - 1;
		      for (cnt = mform->curcol; cnt < r; cnt++)
			{
			  do_key_move_fc ('R', s, a, has_picture, picture);
			}
		    }
		  else
		    {
		      if (A4GL_get_dbscr_inputmode () == 0
			  && A4GL_curr_metric_is_used_last_s_screenio (s, f))
			{
			  A4GL_add_to_control_stack (s,
						     FORMCONTROL_EXIT_INPUT_OK,
						     0, 0, a, __LINE__);
			  return 0;
			}
		      A4GL_debug ("MJA Try to move to next field : %d\n",
				  s->curr_attrib + 1);
		      A4GL_newMovement (s, s->curr_attrib + 1);
		    }
		}
	    }
	  else
	    {
	      for (cnt = mform->curcol; cnt < r; cnt++)
		{
		  do_key_move_fc ('R', s, a, has_picture, picture);
		}
	    }
	  break;

	} else {
		// Exactly the same as 13 or 10 
      if (A4GL_get_dbscr_inputmode () == 0
	  && A4GL_curr_metric_is_used_last_s_screenio (s, f))
	{
	  A4GL_debug ("ACCEPT - EXIT_INPUT_OK\n");
	  A4GL_add_to_control_stack (s, FORMCONTROL_EXIT_INPUT_OK, 0, 0, a,
				     __LINE__);
	  return 0;
	}
      A4GL_debug ("MJA Try to move to next field : %d\n", s->curr_attrib + 1);
      A4GL_newMovement (s, s->curr_attrib + 1);
	}
	break;

	
    case 13:
    case 10:
      if (A4GL_get_dbscr_inputmode () == 0
	  && A4GL_curr_metric_is_used_last_s_screenio (s, f))
	{
	  A4GL_debug ("ACCEPT - EXIT_INPUT_OK\n");
	  A4GL_add_to_control_stack (s, FORMCONTROL_EXIT_INPUT_OK, 0, 0, a,
				     __LINE__);
	  return 0;
	}
      A4GL_debug ("MJA Try to move to next field : %d\n", s->curr_attrib + 1);
      A4GL_newMovement (s, s->curr_attrib + 1);
	break;

    case A4GLKEY_DOWN:
	if (isWordWrap) {
		int fieldHeight;
		int cHeight;	
		int r;
	  	cHeight = mform->currow;
	  	r = mform->curcol ;
	        fieldHeight = A4GL_get_field_height (f);
	        A4GL_debug ("fieldHeight=%d cHeight=%d", fieldHeight, cHeight);
	        if (cHeight + 1 < fieldHeight) {
		  	A4GL_int_form_driver (mform, REQ_NEXT_LINE);
			while (mform->curcol< r) {
		  		A4GL_int_form_driver (mform, REQ_NEXT_CHAR);
			}
			break;
		}
	
	}

      if (A4GL_get_dbscr_inputmode () == 0
	  && A4GL_curr_metric_is_used_last_s_screenio (s, f))
	{
	  A4GL_debug ("ACCEPT - EXIT_INPUT_OK\n");
	  A4GL_add_to_control_stack (s, FORMCONTROL_EXIT_INPUT_OK, 0, 0, a,
				     __LINE__);
	  return 0;
	}
      A4GL_debug ("MJA Try to move to next field : %d\n", s->curr_attrib + 1);
      A4GL_newMovement (s, s->curr_attrib + 1);
      break;

    case A4GLKEY_HOME:
      A4GL_int_form_driver (mform, REQ_BEG_FIELD);
      break;
    case A4GLKEY_END:
      A4GL_int_form_driver (mform, REQ_END_FIELD);
      break;

    case A4GLKEY_LEFT:
      do_key_move_fc ('L', s, a, has_picture, picture);
      break;

    case A4GLKEY_RIGHT:
      do_key_move_fc ('R', s, a, has_picture, picture);
      break;

    case 4:			// Control - D
      if (!has_picture)
	{
	  A4GL_int_form_driver (mform, REQ_CLR_EOF);
	      fprop->flags |= 2;	// Set the field status flag
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
	      A4GL_int_form_driver (mform, REQ_INS_MODE);
	      break;
	    }
	  else
	    {
	      A4GL_int_form_driver (mform, REQ_OVL_MODE);
	      break;
	    }
	}
      else
	{
	  A4GL_error_nobox (acl_getenv ("FIELD_PICTURE_MSG"), 0);
	}
      break;

    }


  return -1;
}


int A4GL_construct_large(char *orig, struct aclfgl_event_list *evt,int init_key,int initpos, struct struct_scr_field *fprop) {
        static char rbuff[1024];
        FIELD *buff[4];
        WINDOW *cwin;
        WINDOW *drwin=0;
        FORM *f;
        int ins_ovl='o';
        int looping=1;
        int fl=0; // comment line...
        int fwidth;
        int a;
char m_d1[2];
char m_d2[2];
int x=0;
        A4GL_debug("In construct_large");

        strcpy(rbuff,orig);
if (m_delims[0]==' ')  {
        m_delims[1]=' ';
        m_delims[2]=' ';
        m_delims[3]=0;
}
m_d1[0]=m_delims[0];
m_d2[0]=m_delims[1];
m_d1[1]=0;
m_d2[1]=0;


        fwidth=UILIB_A4GL_get_curr_width ();
        if (fwidth>80) fwidth=80;
        cwin = (WINDOW *) A4GL_get_currwin ();



	// Construct normally drops to the comment line...
        fl = A4GL_getcomment_line ();

	if (fl==0) {
		fl = UILIB_A4GL_get_curr_height ();
	}

       	if (UILIB_A4GL_iscurrborder()) {
               fl++;
               x++;
        }

       	if (fl > UILIB_A4GL_get_curr_height ()) fl = UILIB_A4GL_get_curr_height ();
       	drwin = derwin (cwin, 1, fwidth, fl-1, x);

        buff[0]=A4GL_make_label(0,0,m_d1);
        buff[1]=A4GL_make_field(0,1,1,fwidth-2);
        local_field_opts_on (buff[1], O_ACTIVE);
        local_field_opts_on (buff[1], O_EDIT);
        local_field_opts_on (buff[1], O_BLANK);


        buff[2]=A4GL_make_label(0,fwidth-1,m_d2);
        buff[3]=0;

        f=new_form(buff);

        set_form_win (f, cwin);
        set_form_sub (f, drwin);
        a=post_form(f);
        A4GL_debug("construct - post_form = %d",a);
        set_field_buffer(buff[1],0,rbuff);
        A4GL_int_form_driver(f,REQ_OVL_MODE);
        if (initpos) {
                A4GL_int_form_driver(f,REQ_END_FIELD);
        }



        while (looping) {
		pos_form_cursor(f);
      		A4GL_mja_refresh ();
		while (1) {
			a=A4GL_real_getch_swin (drwin);
			if (a) break;
		}

  		if (A4GL_is_special_key (a, A4GLKEY_ACCEPT))
			a=A4GLKEY_ACCEPT;

      		A4GL_mja_refresh ();
                if (abort_pressed || a==A4GLKEY_INTERRUPT || a==A4GLKEY_CANCEL) {
			A4GL_debug("Abort Pressed!");
			break;

		}
                if (A4GL_has_event_for_keypress(a,evt)) return a;

                   	if (A4GL_has_bool_attribute (fprop, FA_B_DOWNSHIFT)) {
					if (a4gl_isupper (a) && a4gl_isalpha (a)) { a = a4gl_tolower (a); }
			}
                      	if (A4GL_has_bool_attribute (fprop, FA_B_UPSHIFT)) {
					if ( a4gl_islower (a) && a4gl_isalpha (a)) { a = a4gl_toupper (a); }
			}


                switch (a) {

                        case 1:
                                if (ins_ovl=='o') {
                                        ins_ovl='i';
                                        A4GL_int_form_driver(f,REQ_INS_MODE);
                                } else {
                                        ins_ovl='o';
                                        A4GL_int_form_driver(f,REQ_OVL_MODE);
                                }

                        case 27:
                        case A4GLKEY_ACCEPT:
                        case A4GLKEY_DOWN:
                        case A4GLKEY_UP:
                        case A4GLKEY_ENTER:
                        case '\t': looping=0; break;

                        case A4GLKEY_LEFT:
		  	A4GL_debug("curcol");
                                if (f->curcol==0)  {looping=0;break;}
                                A4GL_int_form_driver (f, REQ_PREV_CHAR);
                                break;


                        case 127:
                        case 8:
                        case A4GLKEY_DC:
                        case A4GLKEY_DL:
                        case A4GLKEY_BACKSPACE: A4GL_int_form_driver (f, REQ_DEL_PREV); break;

                        case 24:                A4GL_int_form_driver (f, REQ_DEL_CHAR);break;
                        case A4GLKEY_RIGHT:     A4GL_int_form_driver (f, REQ_NEXT_CHAR);break;
                        default :               A4GL_int_form_driver (f, a);break;
                }

        }

        A4GL_int_form_driver(f,REQ_VALIDATION);
        strcpy(orig,field_buffer(buff[1],0));


	A4GL_trim(orig);



        A4GL_debug("Unpost and delete...");
        unpost_form(f);
        delwin(drwin);
	 A4GL_debug("delwin : %p",drwin);
	A4GL_mja_refresh();
        A4GL_comments(0);
        return a;
}


int A4GL_get_metric_for (struct s_form_dets *form, void *f)
{
  int a;

  A4GL_debug ("In curr metric");
  for (a = 0; a < form->fileform->metrics.metrics_len; a++)
    {
      if (f == (void *) form->fileform->metrics.metrics_val[a].field)
        {
          A4GL_debug ("Returning %d\n", a);
          return a;
        }
    }
  A4GL_debug ("NO current metric !");
  return -1;
}



void UILIB_A4GL_finish_screenio(void *sio, char *siotype) {
	A4GL_debug("finish_screenio");
	if (strcmp(siotype,"s_inp_arr")==0) {
		A4GL_comments(0);
	}

	if (strcmp(siotype, "s_screenio")==0) {
		A4GL_comments(0);
	}

}



void UILIB_A4GL_reset_state_for(void *sio, char *siotype) {

      if (strcmp(siotype,"s_inp_arr")==0) {
              static void* last_sio=0;
              struct s_inp_arr *s;
              s=sio;
              if (last_sio!=sio) {
                      // May need to do a full redraw..
			
                      if (sio && last_sio) {
				if (((struct s_inp_arr *)sio)->srec==((struct s_inp_arr *)last_sio)->srec) {
					A4GL_idraw_arr_all(s);
				}
			}
                      last_sio=sio;
              }

              if (s) {
                      	A4GL_set_arr_curr (s->arr_line);
                        A4GL_set_scr_line (s->scr_line);
			A4GL_set_arr_count (s->no_arr);
              }

      }

      if (strcmp(siotype,"s_disp_arr")==0) {
              /*static void* last_sio=0; */
              struct s_disp_arr *s;
              s=sio;

              if (s) {
                      	A4GL_set_arr_curr (s->arr_line);
                        A4GL_set_scr_line (s->scr_line);
			A4GL_set_arr_count (s->no_arr);
              }

      }

      if (strcmp(siotype, "s_screenio")==0) {
		struct s_screenio *s;
		s=sio;
		A4GL_set_fields_sio(s);
      }

}



int A4GL_field_is_noentry(int doing_construct, struct struct_scr_field *f) {
	A4GL_debug("A4GL_field_is_noentry %d %p",doing_construct,f);

	if (A4GL_has_bool_attribute (f, FA_B_NOENTRY) ) {
		if (doing_construct) { 
			A4GL_debug("A4GL_field_is_noentry returns 0");
			return 0;
		}
		A4GL_debug("A4GL_field_is_noentry returns 1");
		return 1;
	}


// It would appear that the NOUPDATE allows entry to a field on a 'construct' but not
// an input...
	if (doing_construct) {
		A4GL_debug("A4GL_field_is_noentry returns 0");
		return 0;
	}
	if (A4GL_has_bool_attribute (f, FA_B_NOUPDATE)) {
		A4GL_debug("No UPDATE");
		A4GL_debug("A4GL_field_is_noentry returns 1");
		return 1;
	}
	A4GL_debug("OK");
	A4GL_debug("A4GL_field_is_noentry returns 0");
	return 0;
}




int A4GL_input_required_handling(void) {
static int input_required_type=REQUIRED_TYPE_UNSET;

if (input_required_type==REQUIRED_TYPE_UNSET) {
	char *ptr;
	input_required_type=REQUIRED_TYPE_FIELD;
	ptr=acl_getenv("INPUTREQUIREDTYPE");
	if (ptr==0) ptr="";
	if (A4GL_aubit_strcasecmp(ptr,"FIELD")==0) {input_required_type=REQUIRED_TYPE_FIELD;} 
	if (A4GL_aubit_strcasecmp(ptr,"INPUT")==0) {input_required_type=REQUIRED_TYPE_INPUT;} 
}

return input_required_type;
}

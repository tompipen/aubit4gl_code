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
# $Id: formcntrl.c,v 1.31 2003-09-01 09:16:57 mikeaubury Exp $
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
#define CONTROL_STACK_LENGTH 10

static int process_control_stack (struct s_screenio *arr);
static int A4GL_has_something_on_control_stack (struct s_screenio *sio);
static void A4GL_add_to_control_stack (struct s_screenio *sio, int op, FIELD * f, char *parameter, int extent);
static void A4GL_newMovement (struct s_screenio *arr,  int attrib);
static void A4GL_init_control_stack (struct s_screenio *sio, int malloc_data);
static int A4GL_proc_key_input (int a, FORM * mform, struct s_screenio *s);
static void do_key_move(char lr,struct s_screenio *s,int a, int has_picture, char *picture) ;

#ifdef OLD
int A4GL_curses_to_aubit (int a);
int A4GL_page_for_pfield (struct s_screenio *s);
int A4GL_curr_metric_is_used_last_s_screenio (struct s_screenio *s, FIELD * f);


void A4GL_mja_pos_form_cursor (FORM * form);

int A4GL_form_field_chk (struct s_screenio *sio, int m);
int A4GL_form_field_constr (struct s_screenio *sio, int m);
//int A4GL_req_field_input (struct s_screenio *s, char type, va_list *ap);
int A4GL_proc_key_input (int a, FORM * mform, struct s_screenio *s);
int A4GL_get_curr_metric (struct s_form_dets *form);
int A4GL_page_for_nfield (struct s_screenio *s);
struct s_form_dets *A4GL_getfromform (FORM * f);
void *A4GL_memdup (void *ptr, int size);
void A4GL_mja_set_current_field (FORM * form, FIELD * field);

#endif
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
  struct struct_scr_field *f;


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
  f = (struct struct_scr_field *) (field_userptr (next_field));

  if (A4GL_has_bool_attribute (f, FA_B_NOENTRY))
    {
      int dir = 0;
      while (1)
        {

          if (dir == 0)
            {
              if (attrib >= sio->curr_attrib)
                {               // We want to move to the right..
                  dir = 1;
                }
              else
                {
                  dir = -1;
                }
            }
          next_field = sio->field_list[attrib];
          f = (struct struct_scr_field *) (field_userptr (next_field));

          if (A4GL_has_bool_attribute (f, FA_B_NOENTRY))
            {
              attrib += dir;
              if (attrib > sio->nfields) 
                {
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
              A4GL_newMovement (sio, attrib);       // So keep going...
              return;
            }
        }
    }






  if (last_field!=next_field || 1) {
  	A4GL_add_to_control_stack (sio, FORMCONTROL_BEFORE_FIELD, next_field, A4GL_memdup (ptr, sizeof (struct s_movement)), 0);
  	if (last_field) {
		//if (last_field!=next_field) {
			A4GL_add_to_control_stack (sio, FORMCONTROL_AFTER_FIELD, last_field, 0, 0);
		//}
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

  if (sio->fcntrl[a].op == FORMCONTROL_BEFORE_INPUT)
    {
      new_state = 0;
      rval = -99;
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
	  rval=-1;
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
	  new_state = 75;
	  rval = -90;
	}


      if (sio->fcntrl[a].state == 75)
	{
	  	new_state = 50;
  	  	if (!A4GL_has_processed_onkey()) {
			A4GL_proc_key_input (sio->fcntrl[a].extent, sio->currform->form, sio);
		}
		rval=-1;
	}


      if (sio->fcntrl[a].state == 50)
	{
      	  struct struct_scr_field *fprop;
	  int has_picture=0;
	  char *picture=0;
	  int ok=0;
	  new_state=10;

      		fprop = (struct struct_scr_field *) (field_userptr (sio->currentfield));
	  	A4GL_debug ("Checking key state.. %d", sio->fcntrl[a].extent);
		if (sio->fcntrl[a].extent>=0 && sio->fcntrl[a].extent<=255 && ( (isprint(sio->fcntrl[a].extent) || sio->fcntrl[a].extent==1 || sio->fcntrl[a].extent==4)) ) {

                	if ((fprop->flags & 1)==0)  {
					switch (sio->vars[sio->curr_attrib].dtype) {
					case DTYPE_SMINT:
					case DTYPE_INT:
					case DTYPE_FLOAT:
					case DTYPE_SMFLOAT:
					case DTYPE_DECIMAL:
					case DTYPE_MONEY:  A4GL_int_form_driver (sio->currform->form, REQ_CLR_EOF);
					}
			}
			A4GL_debug("SETTING FLAGS ");
                	fprop->flags|=2; // Set the field status flag

          		if (A4GL_has_str_attribute (fprop, FA_S_PICTURE)) { has_picture=1; picture=A4GL_get_str_attribute (fprop, FA_S_PICTURE);}
			if (sio->mode == MODE_CONSTRUCT) has_picture=0;


  			if (has_picture) {
				int i;
				int key;
	  			FORM *mform;
				mform=sio->currform->form;
				i=mform->curcol;
				ok=1;
				key=sio->fcntrl[a].extent;
				
				if (picture[i]=='A') { if (isalpha(key)) ok=1; else ok=0;} 
				if (picture[i]=='#') { if (isdigit(key)) ok=1; else ok=0;}
				if (picture[i]=='X') { ok=1; }
				if (picture[i]!='X'&& picture[i]!='#'&& picture[i]!='A') { ok=0; }
			
   			} else {
				ok=1;
			}


			if (ok==1) {
				A4GL_int_form_driver (sio->currform->form, sio->fcntrl[a].extent);
	  			A4GL_int_form_driver (sio->currform->form, REQ_VALIDATION);
			}


  			if (has_picture) {
				FORM *mform;
				mform=sio->currform->form;
				if (strchr("A#X",picture[mform->curcol])==0&&picture[mform->curcol])  do_key_move('R',sio,sio->fcntrl[a].extent, has_picture, picture) ;
			}

		} 
              	fprop->flags|=1; // Clear the before field flag
		rval=-1;
	  //mja_wrefresh(currwin);
	}


      if (sio->fcntrl[a].state == 10)
        {
          struct struct_scr_field *fprop;
          new_state = 5;

        rval=-1;


          if (sio->fcntrl[a].extent >= 28 && sio->fcntrl[a].extent <= 255)
            {
              fprop = (struct struct_scr_field *) (field_userptr (sio->currentfield));

              if (A4GL_has_bool_attribute (fprop, FA_B_AUTONEXT)) 
                {
                  FORM *curses_form;
                  //int width;
                  //char buff[256];
                  curses_form = sio->currform->form;
                  //width = A4GL_get_field_width (sio->currentfield);
                  if (current_field (curses_form) != sio->currentfield)
                    {
                      set_current_field (curses_form, sio->currentfield);
		      A4GL_newMovement(sio,sio->curr_attrib+1);
                    }

                }
            }

        }

        if (sio->fcntrl[a].state==5) {
                new_state=0;
                rval=-1;
        }





    }


  if (sio->fcntrl[a].op == FORMCONTROL_BEFORE_FIELD)
    {
      struct struct_scr_field *fprop;
      int attr;
	A4GL_debug("FORM_BEFORE_FIELD - state=%d",sio->fcntrl[a].state);

      if (sio->fcntrl[a].state == 99)
        {
          	new_state = 50;
      		ptr_movement = (struct s_movement *) sio->fcntrl[a].parameter;
      		sio->curr_attrib = ptr_movement->attrib_no;

      	  	A4GL_push_long ((long) sio->field_list[sio->curr_attrib]);
          	A4GL_push_char (sio->fcntrl[a].field_name);
		A4GL_debug("Setting rval to -197");
		rval=-197;
        }

      if (sio->fcntrl[a].state == 50) 
	{
   	  	sio->currentfield = sio->field_list[sio->curr_attrib];
      		set_current_field (sio->currform->form, sio->currentfield);
      		sio->currform->currentfield=sio->currentfield;
      		pos_form_cursor (sio->currform->form);
		A4GL_debug("Processed after users 'BEFORE FIELD'");
      		pos_form_cursor (sio->currform->form);
      		fprop = (struct struct_scr_field *) (field_userptr (sio->currentfield));
      		attr=A4GL_determine_attribute(FGL_CMD_INPUT,sio->attrib, fprop,field_buffer(sio->currentfield,0));
      		if (attr != 0) A4GL_set_field_attr_with_attr (sio->currentfield,attr, FGL_CMD_INPUT);
		if (sio->mode != MODE_CONSTRUCT) {
			char *picture=0;
			int has_picture=0;
          		if (A4GL_has_str_attribute (fprop, FA_S_PICTURE)) { 
					if ((sio->vars[sio->curr_attrib].dtype&DTYPE_MASK)!=DTYPE_CHAR&& (sio->vars[sio->curr_attrib].dtype&DTYPE_MASK)!=DTYPE_VCHAR) {
						A4GL_exitwith("Picture applied to a non-char field not implemented yet..");
					} else {
						int a;
						int w;
						char *ptr;
						w=A4GL_get_field_width(sio->currentfield);
						has_picture=1; picture=A4GL_get_str_attribute (fprop, FA_S_PICTURE);
						ptr=malloc(w+1);
						strncpy(ptr,sio->vars[sio->curr_attrib].ptr,w);
						ptr[w]=0;
					
						for (a=0;a<strlen(picture);a++) {
							if (a>sio->vars[sio->curr_attrib].size) break;

							if (picture[a]=='A') {
									if (!isalpha(ptr[a])) ptr[a]=' '; 
									continue;
							}  

							if (picture[a]=='#') {
									if (!isdigit(ptr[a])) ptr[a]=' '; 
									continue;
							}  
							if (picture[a]=='X') {
									if (ptr[a]==0) ptr[a]=' '; 
									continue;
							}  

							ptr[a]=picture[a];
						}
      						A4GL_set_init_value (sio->currentfield, ptr, sio->vars[sio->curr_attrib].dtype+ENCODE_SIZE(sio->vars[sio->curr_attrib].size));
					}
			} else {
      				A4GL_set_init_value (sio->currentfield, sio->vars[sio->curr_attrib].ptr, sio->vars[sio->curr_attrib].dtype+ENCODE_SIZE(sio->vars[sio->curr_attrib].size));
			}

			if (has_picture) {	
				A4GL_int_form_driver (sio->currform->form, REQ_OVL_MODE); // Always in overwrite mode in a picture...
			}
			

		}

      		A4GL_comments (fprop);
		if ((fprop->flags & 1) ) fprop->flags-=1; // Clear a flag to indicate that we're just starting on this field
      		new_state = 0;
		A4GL_debug("Setting rval to -1");
		//rval=-99;
        }



    }


  if (sio->fcntrl[a].op == FORMCONTROL_AFTER_FIELD)
    {

	int ffc_rval;
      struct struct_scr_field *fprop;
	int attr;
  	if (sio->mode != MODE_CONSTRUCT)
    		ffc_rval=A4GL_form_field_chk (sio, -1);
  	else
    		ffc_rval=A4GL_form_field_constr (sio, -1);


	A4GL_debug("form_Field_chk returns %d\n",a);

	if (ffc_rval!=-4) {
      		new_state = 0;
		if (sio->mode != MODE_CONSTRUCT) {
			int field_no;
			char buff[10024];
			field_no=sio->curr_attrib;
			strcpy(buff,field_buffer (sio->currentfield, 0));
			A4GL_trim(buff);
			A4GL_push_char(buff);
			if (strlen(buff)) {
				A4GL_debug("Field is not null");
	        		A4GL_push_char (buff);
			} else {
				A4GL_debug("Field is null");
		 		A4GL_push_null(DTYPE_CHAR,0);
			}

		
			A4GL_debug("Calling A4GL_pop_var2 : %p dtype=%d size=%d", sio->vars[field_no].ptr, sio->vars[field_no].dtype, sio->vars[field_no].size);
          		A4GL_pop_var2 (sio->vars[field_no].ptr, sio->vars[field_no].dtype, sio->vars[field_no].size);
			A4GL_debug("Calling display_field_contents");
			A4GL_display_field_contents(sio->currentfield,sio->vars[field_no].dtype+ENCODE_SIZE(sio->vars[field_no].size) ,sio->vars[field_no].size,sio->vars[field_no].ptr) ; // MJA 2306

      		fprop = (struct struct_scr_field *) (field_userptr (sio->currentfield));
      		attr=A4GL_determine_attribute(FGL_CMD_INPUT,sio->attrib, fprop,field_buffer(sio->currentfield,0));
      		if (attr != 0) A4GL_set_field_attr_with_attr (sio->currentfield,attr, FGL_CMD_INPUT);

	}
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
A4GL_req_field_input ( void *sv, char type, va_list *ap)
{ 
struct s_screenio *s;
/* fieldname + = next - = previous */
  int a;
  FIELD **ptr;
  //char *field_name;
s=sv;


  if (type=='+') { // Next field next
			A4GL_init_control_stack (s,0);
			s->currform->currentfield=0;
			A4GL_newMovement(s,s->curr_attrib+1);
			return 1;
  }

  if (type=='-') { // Next field previous
			A4GL_init_control_stack (s,0);
			s->currform->currentfield=0;
			A4GL_newMovement(s,s->curr_attrib-1);
			return 1;
  }

  if (type=='0') { // Next field 'current' - used internally
			A4GL_init_control_stack (s,0);
			//s->currform->currentfield=0;
			//A4GL_newMovement(s,s->curr_attrib-1);
			return 1;
  }


  A4GL_debug ("req_field");

  a = A4GL_gen_field_list (&ptr, s->currform, 1,ap);

  if (a >= 0)
    {
	for (a=0;a<=s->nfields;a++) {
		if (s->field_list[a]==ptr[0]) {
			A4GL_init_control_stack (s,0);


			// How risky is this ?
			s->currform->currentfield=0;


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

  if (form != A4GL_get_curr_form (1))
    {
      A4GL_debug ("form=%p curr_form=%p", form, A4GL_get_curr_form (1));
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
	A4GL_add_to_control_stack (s, FORMCONTROL_BEFORE_INPUT, 0, 0, 0);
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

  A4GL_reset_processed_onkey ();
// Wait for a key..
  a = A4GL_getch_win ();
  m_lastkey = a;
  A4GL_set_last_key (a);
     A4GL_clr_error_nobox();

  if (abort_pressed) a = -1;

  A4GL_debug ("form_loop1..  currentfield=%p status = %d", form->currentfield,field_status(form->currentfield));

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
  //A4GL_proc_key_input (a, mform, s);

  //return -90;
  return -1;
}




static void do_key_move(char lr,struct s_screenio *s,int a, int has_picture, char *picture) {
int at_last=0;
int at_first=0;
FIELD *f;
FORM *mform;
mform=s->currform->form;
f=s->currentfield;

if (mform->curcol==0) {
                at_first=1;
}

if (mform->curcol==A4GL_get_field_width(current_field(mform))-1) {
                at_last=1;
}

if (lr=='L') {
	if (at_first) 	{
		if (s->curr_attrib) {
			A4GL_newMovement(s,s->curr_attrib-1); //  go to previous field
			return;
		}

	} else {
		A4GL_int_form_driver (mform, REQ_PREV_CHAR); // go to previous character
	}
}

if (lr=='R') {
	if (at_last) { // Acts like KEY_DOWN at last position in the field
	    if (std_dbscr.input_wrapmode == 0 && A4GL_curr_metric_is_used_last_s_screenio (s, f)) {
                A4GL_add_to_control_stack (s, FORMCONTROL_EXIT_INPUT_OK, 0, 0, a);
                return;
            } else {
			A4GL_newMovement(s,s->curr_attrib+1);
			return;
	    }
	} else {
		A4GL_int_form_driver (mform, REQ_NEXT_CHAR);
	}
}
A4GL_int_form_driver (s->currform->form, REQ_VALIDATION);


if (has_picture) {
             int newpos;
             FORM *mform;
             mform=s->currform->form;
             newpos=mform->curcol;
             if (strchr("A#X",picture[newpos]))  return;
	     do_key_move(lr,s,a, has_picture, picture) ;
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
  int acckey;
  int has_picture=0;
  char *picture=0;


  int at_first=0;
  int at_last=0;
  
  if (mform->curcol==0) {
		at_first=1;
  }
  if (mform->curcol==A4GL_get_field_width(current_field(mform))-1) {
		at_last=1;
  }

  //int npage;
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


          if (A4GL_has_str_attribute (fprop, FA_S_PICTURE)) { has_picture=1; picture=A4GL_get_str_attribute (fprop, FA_S_PICTURE);}
	  if (s->mode == MODE_CONSTRUCT) has_picture=0; /* We don't use the picture in a construct... */


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
      //A4GL_mja_wrefresh (stdscr);
      //A4GL_mja_wrefresh (currwin);

	clearok(curscr,1);
        A4GL_mja_refresh ();

      break;
/*

A little experiment....

    case 2: A4GL_debug("CONTROL - B %d",s->currentfield); 
A4GL_set_field_attr_with_attr(s->currentfield,0x100,0);
	  		A4GL_int_form_driver (s->currform->form, REQ_VALIDATION);
A4GL_mja_refresh();
break;
*/


    case -1:
 	A4GL_add_to_control_stack (s, FORMCONTROL_EXIT_INPUT_ABORT, 0, 0, a);
        break;


    //case 26:
      //return 0; ^Z ?

    case 127:
    case 8:
    case A4GLKEY_DC:
    case A4GLKEY_DL:
    case A4GLKEY_BACKSPACE:
	if (!has_picture) { A4GL_int_form_driver (mform, REQ_DEL_PREV);
	} else { // Just like A4GLKEY_LEFT.....
		do_key_move('L',s,a,has_picture, picture);
	}
	break;

    case 24:
	if (!has_picture) {
			A4GL_int_form_driver (mform, REQ_DEL_CHAR);
	} else  {
		A4GL_error_nobox (acl_getenv ("FIELD_PICTURE_MSG"), 0);
	}
	break;

    case A4GLKEY_UP:
	A4GL_debug("MJA Try to move to previous field : %d\n",s->curr_attrib-1);
	A4GL_newMovement(s,s->curr_attrib-1);
	break;

    case '\t':
    case A4GLKEY_ENTER:
    case 13:
    case 10:
    case A4GLKEY_DOWN:
          if (std_dbscr.input_wrapmode == 0 && A4GL_curr_metric_is_used_last_s_screenio (s, f))
            {
      		A4GL_add_to_control_stack (s, FORMCONTROL_EXIT_INPUT_OK, 0, 0, a);
              	return 0;
            }
	A4GL_debug("MJA Try to move to next field : %d\n",s->curr_attrib+1);
	A4GL_newMovement(s,s->curr_attrib+1);
	break;


    case A4GLKEY_LEFT:
		do_key_move('L',s,a,has_picture, picture);
		break;

    case A4GLKEY_RIGHT:
		do_key_move('R',s,a,has_picture, picture);
		break;

    case 4:                     // Control - D
	if (!has_picture) {
		A4GL_int_form_driver (mform, REQ_CLR_EOF);
	} else {
		A4GL_error_nobox (acl_getenv ("FIELD_PICTURE_MSG"), 0);
	}
	break;


    case 1:                     // Control - A
	if (!has_picture) {
      		form->insmode = form->insmode ? 0 : 1;
      		if (form->insmode) {
			A4GL_int_form_driver (mform, REQ_INS_MODE);break;
		} else {
			A4GL_int_form_driver (mform, REQ_OVL_MODE);break;
		}
	} else {
		A4GL_error_nobox (acl_getenv ("FIELD_PICTURE_MSG"), 0);
	}
	break;

    }


  //A4GL_mja_refresh ();   // removed mja 22/08/2003
	//usleep(100000);
  return -1;
}


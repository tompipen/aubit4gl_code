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
# $Id: iarray.c,v 1.118 2007-02-17 10:00:43 mikeaubury Exp $
#*/
#ifndef lint
	static char const module_id[] =
		"$Id: iarray.c,v 1.118 2007-02-17 10:00:43 mikeaubury Exp $";
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


#include "a4gl_lib_ui_tui_int.h"
#include <ctype.h>

void A4GL_idraw_arr_all (struct s_inp_arr *inpa);
void A4GL_set_curr_infield (void *a);
void debug_print_flags (void *sv, char *txt);
int A4GL_get_attr_from_string (char *s);
char *A4GL_fld_data_ignore_format (struct struct_scr_field *fprop,
				   char *fld_data);
void A4GL_clr_field (FIELD * f);
void A4GL_make_window_with_this_form_current (void *form);
int UILIB_A4GL_inp_arr_v2_i (void *vinpa, int defs, char *srecname, int attrib, int init, void *vevt);


#define CONTROL_STACK_LENGTH 10

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

extern WINDOW *currwin;
struct s_inp_arr *curr_arr_inp = 0;
char *debug_get_fcntrl(int n) ;

struct s_movement
{
  int scr_line;
  int arr_line;
  int attrib_no;
};

static char *last_field_name;
static int last_key_code;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/
int A4GL_field_name_match (FIELD * f, char *s);

static int process_control_stack_internal (struct s_inp_arr *arr);
static int process_control_stack (struct s_inp_arr *sio,
				  struct aclfgl_event_list *evt);
void A4GL_set_infield_from_parameter (long a);
void A4GL_set_field_attr_with_attr_already_determined (FIELD * field,
						       int attr,
						       int cmd_type);


static void init_arr_line (struct s_inp_arr *sio, int n);
static int A4GL_has_something_on_control_stack (struct s_inp_arr *sio);

static void A4GL_add_to_control_stack (struct s_inp_arr *sio, enum e_formcontrol op,
				       FIELD * f, char *parameter,
				       int extent);

static void A4GL_newMovement (struct s_inp_arr *arr, int scr_line,
			      int arr_line, int attrib, char why);
static void A4GL_init_control_stack (struct s_inp_arr *sio, int malloc_data);

static int A4GL_set_fields_inp_arr (void *vsio, int n);
//int A4GL_has_event (int a, struct aclfgl_event_list *evt);
//int A4GL_has_event_for_keypress (int a, struct aclfgl_event_list *evt);
//int A4GL_has_event_for_field (int cat, char *a, struct aclfgl_event_list *evt);
//



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
  int at_first = 0;
  int at_last = 0;
  FORM *mform;
  
  
  A4GL_debug("do_key_move");

  form = arr->currform;
  mform = form->form;

  if (mform->curcol == 0)
    {
      at_first = 1;
    }
  if (mform->curcol == A4GL_get_field_width (current_field (mform)) - 1)
    {
      at_last = 1;
    }

  if (lr == 'R')
    {
      A4GL_debug ("Key_right");
      if (at_last)
	{
	A4GL_debug("Calling newmovement");
	  A4GL_newMovement (arr, arr->scr_line, arr->arr_line,
			    arr->curr_attrib + 1, 'R');
	  return;
	}
      else
	{
	A4GL_int_form_driver (mform, REQ_NEXT_CHAR);
	}

    }



  if (lr == 'L')
    {
      if (at_first)
	{
	  if (arr->curr_attrib)
	    {
	A4GL_debug("Calling newmovement");
	      A4GL_newMovement (arr, arr->scr_line, arr->arr_line,
				arr->curr_attrib - 1, 'L');
		return;
	    }
	  else
	    {
	A4GL_debug("Calling newmovement");
	      A4GL_newMovement (arr, arr->scr_line - 1, arr->arr_line - 1, 0,
				'U');
		return;
	    }
	}
      else
	{
	  A4GL_int_form_driver (mform, REQ_PREV_CHAR);
	}
    }

  if (has_picture)
    {
      int newpos;
      FORM *mform;
      mform = arr->currform->form;
      newpos = mform->curcol;
      if (strchr ("A#X", picture[newpos]))
	return;
	A4GL_debug("do_key_move");
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
  char fbuff[8000];
  int really_ok = 0;
  char *ptr;
  struct struct_scr_field *fprop;

  A4GL_debug ("In pop_iarr_var %d %d currentfield=%p", x, y,
	      form->currentfield);
  if (form->currentfield == 0)
    return 1;

  y--;


  if (!A4GL_copy_field_data (form))
    return 0;

  strcpy (fbuff, field_buffer (form->currentfield, 0));
	A4GL_debug("fbuff=%s\n",fbuff);
  fprop = (struct struct_scr_field *) (field_userptr (form->currentfield));
  if (A4GL_has_str_attribute (fprop, FA_S_PICTURE))
    {
      int a;
      int blank = 1;
      char *picture;
      picture = A4GL_get_str_attribute (fprop, FA_S_PICTURE);
      A4GL_debug ("HAS PICTURE MJA123");
      for (a = 0; a < strlen (fbuff); a++)
	{
	  if (picture[a] == 'X' && fbuff[a] != ' ')
	    {
	      blank = 0;
	      break;
	    }
	  if (picture[a] == 'A' && fbuff[a] != ' ')
	    {
	      blank = 0;
	      break;
	    }
	  if (picture[a] == '#' && fbuff[a] != ' ')
	    {
	      blank = 0;
	      break;
	    }
	}
      if (blank) strcpy (fbuff, "");

      ptr = strdup (fbuff);
      A4GL_trim (ptr);
    }
  else
    {
      ptr = strdup (fbuff);
      A4GL_trim (ptr);
    }

  A4GL_debug ("COPY gets buff = %s ptr=%s\n", fbuff,ptr);



  if (strlen (ptr))
    {
      struct struct_scr_field *fprop;
      char *ptr2;
      fprop =
	(struct struct_scr_field *) (field_userptr (form->currentfield));

      ptr2 = A4GL_fld_data_ignore_format (fprop, ptr);
      if (ptr2 != ptr)
	{
	  A4GL_debug ("Free ptr");
	  acl_free (ptr);
	  ptr = strdup (ptr2);
	}
      A4GL_push_char (ptr);
    }
  else
    {
      A4GL_push_null (b[x].dtype, b[x].size);
    }
  A4GL_debug ("Pushed field buffer :'%s'", ptr);

  strcpy (buff, fbuff);
  A4GL_trim (buff);


  really_ok = 1;
  A4GL_debug ("Calling pop_var2..");
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
       || b[x].dtype == DTYPE_SERIAL) && strchr (buff, '.'))
    {
      A4GL_debug ("Looks like its got a '.' in it");
      really_ok = 0;
    }


  A4GL_debug ("Free ptr 2");
  acl_free (ptr);
  A4GL_debug ("Popped field buffer into variable");
  if (really_ok == 0)
    {
      struct struct_scr_field *fprop;
      fprop =
	(struct struct_scr_field *) (field_userptr (form->currentfield));
      A4GL_error_nobox (acl_getenv ("FIELD_ERROR_MSG"), 0);
      if (fprop)
	A4GL_comments (fprop);

      if (A4GL_isyes (acl_getenv ("A4GL_CLR_FIELD_ON_ERROR")))
	{
	  A4GL_clr_field (form->currentfield);
	}
      else
	{
	  if (A4GL_isyes (acl_getenv ("FIRSTCOL_ONERR")))
	    {
	      A4GL_int_form_driver (form->form, REQ_BEG_FIELD);
	    }
	}
      set_current_field (form->form, form->currentfield);
      return 0;
    }
  return 1;
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
  int somekeypress=0;
  int reinpa;
  FORM *mform;
  struct struct_scr_field *fprop;

  arr->scr_dim = arr->srec->dim;
  if (curr_arr_inp != arr || curr_arr_inp)
    {
      A4GL_debug ("DO THEM AGAIN...");
      A4GL_set_fields_inp_arr (arr, 1);
    }
  curr_arr_inp = arr;
  form = arr->currform;
  A4GL_set_array_mode ('I');

#ifdef DEBUG
  {
    A4GL_debug ("Currform=%p (s_form_dets)", form);
  }
#endif

  if (form != UILIB_A4GL_get_curr_form (0))
    {
      A4GL_make_window_with_this_form_current (form);
    }

  if (form != UILIB_A4GL_get_curr_form (0))
    {
      A4GL_exitwith ("Input form is not the current form!");
      return 0;
    }
  mform = form->form;


  A4GL_debug ("Field = %p opts=%x ", form->currentfield,
	      field_opts (form->currentfield));
  A4GL_idraw_arr (arr, 2, arr->arr_line);





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


      if (arr->currentfield != form->currentfield)
	{
	  arr->currentfield = form->currentfield;
	}


      fprop =
	(struct struct_scr_field *) (field_userptr (form->currentfield));
      if (fprop)
	A4GL_comments (fprop);

      A4GL_mja_set_current_field (mform, form->currentfield);

      A4GL_mja_pos_form_cursor (mform);
      abort_pressed = 0;

      while (1) {
	      	int blk;
  		blk=A4GL_has_evt_timeout(evt);
  		if (blk) { 
			return blk; 
		}
      		somekeypress = A4GL_getch_win ();
      		if (abort_pressed) { somekeypress = A4GLKEY_INTERRUPT; }

      		A4GL_debug("a=%d",somekeypress);
      		if (somekeypress!=0 && somekeypress!=-1) { 
			A4GL_evt_not_idle(evt); 
			break;
		}
	}


      if (A4GL_is_special_key (somekeypress, A4GLKEY_ACCEPT))
	somekeypress = A4GLKEY_ACCEPT;
      if (A4GL_is_special_key (somekeypress, A4GLKEY_INSERT))
	somekeypress = A4GLKEY_INSERT;
      if (A4GL_is_special_key (somekeypress, A4GLKEY_DELETE))
	somekeypress = A4GLKEY_DELETE;
      if (A4GL_is_special_key (somekeypress, A4GLKEY_NEXT))
	somekeypress = A4GLKEY_NEXT;
      if (A4GL_is_special_key (somekeypress, A4GLKEY_PREV))
	somekeypress = A4GLKEY_PREV;

      arr->processed_onkey = somekeypress;

      A4GL_debug ("calling set_last_key : %d", somekeypress);
      A4GL_set_last_key (somekeypress);
    }



  reinpa = 0;

  if (somekeypress != 10)
    {
      struct struct_scr_field *fprop;

      A4GL_debug ("Getting fprop");
      fprop =
	(struct struct_scr_field *) (field_userptr (form->currentfield));
      if (fprop != 0)
	{
	  A4GL_debug ("Downshift?");
	  if (A4GL_has_bool_attribute (fprop, FA_B_DOWNSHIFT)
	      && a4gl_isupper (somekeypress) && a4gl_isalpha (somekeypress))
	    {
	      somekeypress = tolower (somekeypress);
	    }
	  A4GL_debug ("Upshift ?");
	  if (A4GL_has_bool_attribute (fprop, FA_B_UPSHIFT)
	      && a4gl_islower (somekeypress) && a4gl_isalpha (somekeypress))
	    {
	      somekeypress = a4gl_toupper (somekeypress);
	    }
	}
    }

  if (somekeypress!=0) {
  		A4GL_add_to_control_stack (arr, FORMCONTROL_KEY_PRESS, 0, 0, somekeypress);
  }
  return -1;
}


static void
process_key_press (struct s_inp_arr *arr, int a)
{
  struct s_form_dets *form;
  FORM *mform;
  int at_first = 0;
  int at_last = 0;
  int act_as;

  form = arr->currform;
  mform = form->form;


  if (mform->curcol == 0)
    {
      at_first = 1;
    }
  if (mform->curcol == A4GL_get_field_width (current_field (mform)) - 1)
    {
      at_last = 1;
    }

  A4GL_debug ("In process_key_press : %x", a);

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
    case A4GLKEY_DC:
    case A4GLKEY_DL:
    case A4GLKEY_BACKSPACE:
			  if (arr->curr_line_is_new==1) { arr->curr_line_is_new=2; }
      A4GL_int_form_driver (mform, REQ_DEL_PREV);
      break;

    case 18:
      clearok (curscr, 1);
      A4GL_mja_refresh ();
      break;

    case 24:
			  if (arr->curr_line_is_new==1) { arr->curr_line_is_new=2; }
        A4GL_int_form_driver (mform, REQ_DEL_CHAR);
      	break;

    case 4:			// Control - D
      A4GL_debug ("MMMM - Clear EOF ^d");
			  if (arr->curr_line_is_new==1) { arr->curr_line_is_new=2; }
      A4GL_int_form_driver (mform, REQ_CLR_EOF);
      break;

    case 1:			// Control - A
      form->form_details.insmode = form->form_details.insmode ? 0 : 1;

      if (form->form_details.insmode)
	{
	  A4GL_int_form_driver (mform, REQ_INS_MODE);
	  break;
	}
      else
	{
	  A4GL_int_form_driver (mform, REQ_OVL_MODE);
	  break;
	}

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
	  			A4GL_newMovement (arr, arr->scr_line, arr->no_arr+1, arr->curr_attrib, 'D');
			} else {
	 			A4GL_error_nobox (acl_getenv("ARR_DIR_MSG"), 0);
			}
		}
	  } else {
			A4GL_debug("nm1");
	  	A4GL_newMovement (arr, arr->scr_line, arr->arr_line + arr->scr_dim, arr->curr_attrib, 'D');
	  }
	}
      else
	{
	  int d;
	A4GL_debug("XX");
	  d = arr->arr_size - arr->arr_line;
	  if (d>arr->no_arr) {
	 	if (arr->allow_insert) {
  	  		A4GL_newMovement (arr, arr->scr_dim, arr->no_arr+1, arr->curr_attrib, 'D');
		} else {
	 		A4GL_error_nobox (acl_getenv("ARR_DIR_MSG"), 0);
		}
	  } else {
  	  		//A4GL_newMovement (arr, arr->scr_dim, d, arr->curr_attrib, 'D');
	 		A4GL_error_nobox (acl_getenv("ARR_DIR_MSG"), 0);
	  }
	}
      break;

    case A4GLKEY_PGUP:
      if (arr->arr_line - arr->scr_dim >= 1)
	{
	A4GL_debug("Calling newmovement");
	  A4GL_newMovement (arr,
			    arr->scr_line,
			    arr->arr_line - arr->scr_dim, arr->curr_attrib,
			    'U');
	}
      else
	{
	if (A4GL_isyes(acl_getenv("SCROLLBACKTO1")) && arr->arr_line>1 && 0 ) {
	  A4GL_newMovement (arr, 1, 1, arr->curr_attrib, 'U');
	} else {
			A4GL_debug("Calling newmovement");
	 A4GL_error_nobox (acl_getenv("ARR_DIR_MSG"), 0);
	}

	}
      break;



    case A4GLKEY_DOWN:
      if (arr->arr_line >= arr->no_arr) {
	  A4GL_debug("Calling down newmovement -> insert at end");
          A4GL_newMovement (arr,
			    arr->scr_line + 1, arr->arr_line + 1,
			    0, 'D');
      } else {
	  A4GL_debug("Calling down newmovement -> existing data");
          A4GL_newMovement (arr,
			    arr->scr_line + 1, arr->arr_line + 1,
			    arr->curr_attrib, 'D');
      } 
	
	
      break;


    case A4GLKEY_RIGHT:
      A4GL_debug ("Key_right");
      if (at_last)
	{
	A4GL_debug("Calling newmovement");
	  A4GL_newMovement (arr,
			    arr->scr_line, arr->arr_line,
			    arr->curr_attrib + 1, 'R');
	}
      else
	{
	  A4GL_int_form_driver (mform, REQ_NEXT_CHAR);
	}
      break;


    case A4GLKEY_HOME:
                A4GL_int_form_driver (mform, REQ_BEG_FIELD);
		          break;
			      case A4GLKEY_END:
			            A4GL_int_form_driver (mform, REQ_END_FIELD);
				              break;


    case A4GLKEY_LEFT:
      A4GL_debug ("Left key pressed - want to move left...");
      if (at_first)
	{
	  A4GL_debug ("at first - curr_attrib=%d...", arr->curr_attrib);
	  if (arr->curr_attrib)
	    {
	A4GL_debug("Calling newmovement");
	      A4GL_newMovement (arr, arr->scr_line, arr->arr_line,
				arr->curr_attrib - 1, 'L');
	    }
	  else
	    {
	A4GL_debug("Calling newmovement");
	      A4GL_newMovement (arr, arr->scr_line - 1, arr->arr_line - 1, 0,
				'U');
	    }
	}
      else
	{
	  A4GL_int_form_driver (mform, REQ_PREV_CHAR);
	}
      break;


    case A4GLKEY_INS:

      // cc 2004.09.06 when INS key is pressed, content may not be in
      //               content buffer yet, need to copy to ensure this
      A4GL_add_to_control_stack (arr, FORMCONTROL_BEFORE_INSERT, arr->currentfield, 0, 0);
	{
	  FIELD *f;
	  f = arr->field_list[arr->scr_line - 1][arr->curr_attrib];
	      A4GL_add_to_control_stack (arr, FORMCONTROL_AFTER_ROW, f, 0, 0);
	      A4GL_add_to_control_stack (arr, FORMCONTROL_AFTER_FIELD, f, 0, 0);
	}
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
	A4GL_debug("Calling newmovement");
      A4GL_newMovement (arr, arr->scr_line, arr->arr_line,
			arr->curr_attrib + 1, 'R');

      break;


    case A4GLKEY_UP:
	A4GL_debug("Calling newmovement");
      A4GL_newMovement (arr,
			arr->scr_line - 1, arr->arr_line - 1,
			arr->curr_attrib, 'U');
      break;

    case -99:
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


  return fld_list;
}

int
UILIB_A4GL_inp_arr_v2 (void *vinpa, int defs, char *srecname, int attrib,
		       int init, void *vevt) {

	struct s_inp_arr *inpa;
	if (init && defs==0) {
		int  n;
		int count;
		// We should initialize our array variables to null...
		// up to and the setcount value anyway...
		inpa=vinpa;
		count=A4GL_get_count();

		if (count>=inpa->arr_size) {
			count=inpa->arr_size;
		}
		for (n=1;n<=count;n++) {
		    init_arr_line(vinpa,n);
		}
		inpa->no_arr=0;
                A4GL_set_arr_count (0);
	}


A4GL_debug("inp_arr_v2 ... zz9pa");
while (1) {
	int a;
	a=UILIB_A4GL_inp_arr_v2_i(vinpa,defs,srecname,attrib,init,vevt);
	if (a!=-1) {
			A4GL_debug("returing %d zz9pa",a);
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
int UILIB_A4GL_inp_arr_v2_i (void *vinpa, int defs, char *srecname, int attrib,
		       int init, void *vevt)
{
  FIELD ***fld_list;
  int rval;
  struct aclfgl_event_list *evt;

  struct s_inp_arr *inpa;
  inpa = (struct s_inp_arr *) vinpa;
  evt = vevt;

  if (curr_arr_inp && curr_arr_inp != inpa)
    {
      A4GL_debug ("DO THEM AGAIN...");
      A4GL_set_fields_inp_arr (inpa, 0);
    }
  curr_arr_inp = inpa;
  A4GL_debug ("In UILIB_A4GL_inp_arr : %s %p %p %d count=%d (%d) XYX",
	      srecname, defs, inpa, attrib, inpa->count, A4GL_get_count ());

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
      inpa->currform = UILIB_A4GL_get_curr_form (1);

      A4GL_debug ("Init control stack");
      A4GL_init_control_stack (inpa, 1);
      A4GL_clr_evt_timeouts(evt);

#ifdef DEBUG
      {
	A4GL_debug ("inpa->currform=%p", inpa->currform);
	A4GL_debug ("inpa->fcntrl_cnt=%d", inpa->fcntrl_cnt);
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
	{
	  init_arr_line (inpa, 1);
	}

      A4GL_set_arr_curr (inpa->arr_line);
      A4GL_set_scr_line (inpa->scr_line);


      A4GL_debug ("inpaarr2");
      if (inpa->srec == 0)

	{

	  A4GL_debug ("Screen record does not exist");

	  return 0;

	}
      A4GL_debug ("inpaarr3");

      if (inpa->start_slice!=-1 && inpa->end_slice!=-1) {
		if (inpa->srec->attribs.attribs_len!=(inpa->end_slice-inpa->start_slice+1)) {
	  		A4GL_exitwith("Too many or too few variables for fields");
	  		A4GL_debug ("Too many or too few variables for fields %d %d", inpa->srec->dim, inpa->nbind);
	  		return 0;
		}
	} else {
      		if (inpa->srec->attribs.attribs_len != inpa->nbind) {
	  		A4GL_exitwith("Too many or too few variables for fields");
	  		A4GL_debug ("Too many or too few variables for fields %d %d", inpa->srec->dim, inpa->nbind);
	  		return 0;
		}
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
      A4GL_set_fields_inp_arr (inpa, 2);

      iclear_srec (inpa->srec, inpa);

      A4GL_idraw_arr (inpa, 1, inpa->arr_line);

      inpa->last_scr_line = -1;
      inpa->last_arr_line = -1;


      A4GL_set_arr_count (inpa->no_arr);

      inpa->curr_attrib = 0;
	A4GL_debug("Calling newmovement");
      A4GL_newMovement (inpa, 0, 0, 0, 0);

      inpa->last_scr_line = -1;
      inpa->last_arr_line = -1;

      A4GL_idraw_arr_all (inpa);
      A4GL_mja_refresh ();
      inpa->last_scr_line = 1;
      inpa->last_arr_line = 1;
      A4GL_debug ("inp_arr - returning -99  BEFORE INPUT....");
      if (A4GL_has_event (A4GL_EVENT_BEFORE_INP, evt))
	return A4GL_has_event (A4GL_EVENT_BEFORE_INP, evt);
      return -1;
    }
  A4GL_debug ("inpaarr4");


  rval = iarr_loop (inpa, evt);
  A4GL_debug ("DEBUGGING rval=%d", rval);

  return rval;
}


/* This is used by the fgl_set_scrline function */
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
  return 0;
}


/* This is used by the fgl_set_arrline function */
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
    return 0;
}


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
A4GL_set_fields_inp_arr (void *vsio, int n)
{
  int wid;
  int a, b;
  int nv;
  int flg;
  struct s_form_dets *formdets;
  struct struct_scr_field *field;
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
/*
      if (field_opts (field_list[a]) & O_BLANK)
	{
	  A4GL_debug ("O_BLANK MMMM turning off");
	}
*/

      if (A4GL_turn_field_off (formdets->form_fields[a]))
	{
	  firstfield = formdets->form_fields[a];
	}
/*
      if (field_opts (field_list[a]) & O_BLANK)
	{
	  A4GL_debug ("O_BLANK MMMM turned off");
	}
*/

    }

  nofields = sio->nfields;
  field_list = (FIELD **) sio->field_list;

  A4GL_debug ("Field list=%p number of fields = %d", field_list, nofields);

  nv = sio->nbind;
  if (sio->start_slice!=-1 && sio->end_slice!=-1) { nv=sio->end_slice-sio->start_slice+1; }

  if (nofields != nv - 1)
    {
      A4GL_debug
	("Number of fields (%d) is not the same as the number of vars (%d)",
	 nofields + 1, nv);
      A4GL_exitwith ("Number of fields is not the same as the number of variables");
      return 0;
    }


  A4GL_debug ("turning some back on : %p %d", sio, sio->scr_dim);



  for (a = 0; a < sio->scr_dim; a++)
    {
      for (b = 0; b < sio->srec->attribs.attribs_len; b++)
	{
	  if (n == 1)
	    {
	      field_opts_on (sio->field_list[a][b], O_ACTIVE);
	      field_opts_on (sio->field_list[a][b], O_EDIT);
	    }
	  else
	    {

	      A4GL_turn_field_on2 (sio->field_list[a][b], 1);
	    }
	  /* if (field_opts (sio->field_list[a][b]) & O_BLANK)
	    {
	      A4GL_debug ("O_BLANK MMMM %d %d", a, b);
	    }
	*/
	  field =
	    (struct struct_scr_field
	     *) (field_userptr (sio->field_list[a][b]));
	  /* A4GL_debug ("Settings flags to 0 for %d %d", a, b); */

	  if (n == 2)
	    field->flags = 0;
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
  A4GL_set_curr_infield ((void *) field);
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
A4GL_add_to_control_stack (struct s_inp_arr *sio, enum e_formcontrol op, FIELD * f,
			   char *parameter, int extent)
{
  char *field_name;
  int a;
  struct struct_scr_field *attr;


  if (op==FORMCONTROL_BEFORE_ROW) {
	  //A4GL_pause_execution();
  }

  A4GL_debug ("add to control stack called with op=%d field=%p extent=%d", op,
	      f, extent);


  field_name = 0;

  if (f)
    {
      attr = (struct struct_scr_field *) field_userptr (f);
      field_name = attr->colname;
    }

  a = sio->fcntrl_cnt;
  A4GL_debug("a=%d",a);


  if (op == FORMCONTROL_KEY_PRESS)
    {

      if (A4GL_is_special_key (extent, A4GLKEY_ACCEPT))
	extent = A4GLKEY_ACCEPT;
      if (A4GL_is_special_key (extent, A4GLKEY_INSERT))
	extent = A4GLKEY_INSERT;
      if (A4GL_is_special_key (extent, A4GLKEY_DELETE))
	extent = A4GLKEY_DELETE;
      if (A4GL_is_special_key (extent, A4GLKEY_NEXT))
	extent = A4GLKEY_NEXT;
      if (A4GL_is_special_key (extent, A4GLKEY_PREV))
	extent = A4GLKEY_PREV;

      A4GL_debug ("ADDED KEY : %d\n", extent);
    }
  A4GL_debug("sio=%p",sio);
  A4GL_debug(" XXXXXXXXXXXXXXXXXXXXXXXXXX a=%d",a);

  if (a>= 10) {
		A4GL_assertion(1,"Got stuck in a loop in input array?");
  }
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
	      A4GL_debug ("Free parameter");
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
		  int attrib, char why)
{
  void *last_field = 0;
  void *next_field;
  struct struct_scr_field *f;

  A4GL_debug ("newMovement %d %d %d", scr_line, arr_line, attrib);
  if (arr_line > 800000)
    {
      char *ptr = 0;
      *ptr = 0;
	  A4GL_assertion(1,"Sanity check failed - do you really have  > 800000 lines in your array");	  
    }

// Sanity check the movements....

  if (arr_line < 1)
    {
      // Attempt to move off the top program array...
      if (arr->last_scr_line > 0)
	{
	  A4GL_error_nobox (acl_getenv ("ARR_DIR_MSG"), 0);
	}
	A4GL_debug("Calling newmovement");
      A4GL_newMovement (arr, scr_line, 1, attrib, why);
      return;
    }

  if (scr_line > arr_line)
    {
	A4GL_debug("scr_line1");
      scr_line = arr_line;
    }

  if (attrib < 0)
    {
      // attempt to move too far to the left
      // In informix - this results in just going up a line - still on field 0
      A4GL_debug ("Too far to the left");
      A4GL_newMovement (arr, scr_line, arr_line - 1, 0, why);
      return;
    }


  if (scr_line > arr->scr_dim)
    {
      A4GL_debug ("Too far down in screen lines");
      scr_line = arr->scr_dim;
	A4GL_debug("Calling newmovement");
      A4GL_newMovement (arr, scr_line, arr_line, attrib, why);
      return;
    }

  if (scr_line <= 0)
    {
      A4GL_debug ("Too far up in screen lines");
      scr_line = 1;
	A4GL_debug("Calling newmovement");
      A4GL_newMovement (arr, scr_line, arr_line, attrib, why);
      return;
    }

  if ((arr_line + 1) - scr_line < 0)
    {
      A4GL_debug ("scr lines too big for current line %d %d", scr_line,
		  arr_line);
      scr_line = arr_line - scr_line + 1;
	A4GL_debug("Calling newmovement");
      A4GL_newMovement (arr, scr_line, arr_line, attrib, why);
      return;
    }


	A4GL_debug("db1");

  if (attrib >= arr->srec->attribs.attribs_len)
    {
      // Too far over to the right - wrap around to the start of the next line
      A4GL_debug ("Too far to the right");
      if (arr_line >= arr->arr_size)
	{
	  A4GL_error_nobox (acl_getenv ("ARR_DIR_MSG"), 0);
	A4GL_debug("Calling newmovement");
	  A4GL_newMovement (arr, arr->scr_line, arr->arr_size,
			    arr->curr_attrib, why);
	}
      else
	{
	A4GL_debug("Calling newmovement");
	  A4GL_newMovement (arr, scr_line + 1, arr_line + 1, 0, why);
	}
      return;
    }

	A4GL_debug("db2");


  if (arr_line > arr->arr_size)
    {				// Attempting to move off the bottom of the array...
      A4GL_debug ("Too far down the program array");
      A4GL_error_nobox (acl_getenv ("ARR_DIR_MSG"), 0);
	A4GL_debug("Calling newmovement");
      A4GL_newMovement (arr, arr->scr_line, arr->arr_size, arr->curr_attrib,
			why);
      // Do nothing at all...
      return;
    }


	A4GL_debug("db3");
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



	A4GL_debug("db4 arr=%p",arr);

	A4GL_debug("db4.1 arr->scr_line=%d",arr->scr_line);
  
  if (arr->scr_line > 0) {
	  A4GL_debug("setting last_field");
    		last_field = arr->currentfield;
  } else {
	  A4GL_debug("clearing last_field");
    last_field = 0;
  }


	A4GL_debug("db5 - %d %d",scr_line - 1,attrib);

  next_field = arr->field_list[scr_line - 1][attrib];
  A4GL_debug("db6 - nextfield = %p\n",next_field);
  f = (struct struct_scr_field *) (field_userptr (next_field));

  if (A4GL_has_bool_attribute (f, FA_B_NOENTRY)
      || (f->datatype == DTYPE_SERIAL))
    {
      A4GL_debug ("Requested field is noentry attrib=%d curr_attrib=%d",
		  attrib, arr->curr_attrib);
      while (1)
	{
	  A4GL_debug ("in while attrib=%d curr_attrib=%d why=%c", attrib,
		      arr->curr_attrib, why);

	  A4GL_debug ("next_field= srec[%d %d]\n", scr_line, attrib);
	  next_field = arr->field_list[0][attrib];
	  A4GL_debug ("next_field = %p", next_field);
	  f = (struct struct_scr_field *) (field_userptr (next_field));
	  A4GL_debug ("fprop=%p attrib=%d", f, attrib);

	  if (A4GL_has_bool_attribute (f, FA_B_NOENTRY)
	      || (f->datatype == DTYPE_SERIAL))
	    {
	      A4GL_debug ("Darn - next field is no entry too dir=%c", why);
	      if (why == 0 || why == 'R' || why == 'D' || why=='Q')
		{
		  attrib++;
		}
	      else
		{
		  attrib--;
		}


	      A4GL_debug ("attrib now : %d of %d", attrib, arr->srec->attribs.attribs_len);


	      if (attrib >= arr->srec->attribs.attribs_len && attrib >= 0)
		{
			int sl;
			int al;

		  A4GL_debug ("attrib now : %d - too far to the right (%d)",
			      attrib, arr->srec->attribs.attribs_len);
		  attrib = 0;
		  sl=scr_line+1;
		  //scr_line++;
		  //arr_line++;
		  al=arr_line+1;
		  A4GL_debug ("arr_line now %d - scr_line=%d arr->arr_size=%d", al, sl, arr->arr_size);
		  if (al > arr->arr_size)
		    {		// Attempting to move off the bottom of the array...
		      A4GL_error_nobox (acl_getenv ("ARR_DIR_MSG"), 0);
		      A4GL_debug ("Too far down - should really error at this point");
	A4GL_debug("Calling newmovement");
		      A4GL_newMovement (arr, sl - 1, al - 1, 0, why);	// So keep going...
		      return;
		    } else {
		      A4GL_newMovement (arr, sl, al, 0, why);	// So keep going...
		      return;
		    }
		}

	      if (attrib < 0)
		{
		  attrib = 0;	//arr->srec->attribs.attribs_len-1;
		  why = 0;
		  A4GL_debug ("attrib now : %d - too far to the left",
			      attrib);

		  scr_line--;
		  arr_line--;
		}
	    }
	  else
	    {
	      A4GL_debug ("Found somewhere free... %d %d %d", scr_line,
			  arr_line, attrib);
		A4GL_debug("Calling newmovement");
	        A4GL_newMovement (arr, scr_line, arr_line, attrib, why);	// So keep going...
	      return;
	    }
	}
    }





  A4GL_debug ("iarr - adding entries to stack %d %d", arr_line,
	      arr->arr_line);

  if (arr_line != arr->arr_line)
    {
      struct s_movement ptr;
      ptr.scr_line = scr_line;
      ptr.arr_line = arr_line;
      ptr.attrib_no = attrib;
      A4GL_debug ("Bef1 - different array line");
      A4GL_add_to_control_stack (arr, FORMCONTROL_BEFORE_FIELD, next_field, 
		A4GL_memdup (&ptr, sizeof (struct s_movement)), 0);




      A4GL_add_to_control_stack (arr, FORMCONTROL_BEFORE_ROW, next_field,
				 A4GL_memdup (&ptr,
					      sizeof (struct s_movement)), 0);

      A4GL_debug ("Add aftr controls ?  - %p", last_field);

      if (last_field|| why=='Q')
	{

	  A4GL_add_to_control_stack (arr, FORMCONTROL_AFTER_ROW, last_field, 0, 0);
		A4GL_debug("Checking curr_line_is_new : %d",arr->curr_line_is_new);
	  if (arr->curr_line_is_new) { 
		A4GL_debug("check curr_line_is_new for after insert");
		A4GL_debug("XYXY : %p %c %d\n",last_field,why,arr->curr_line_is_new);
		A4GL_add_to_control_stack (arr, FORMCONTROL_AFTER_INSERT, last_field, 0, 0); 
	  }
  	  A4GL_debug("Setting curr_line_is_new to 0");
	  arr->curr_line_is_new = 0;

		if (last_field) {
	  		A4GL_debug ("Adding AFTER FIELD..");
	  		A4GL_add_to_control_stack (arr, FORMCONTROL_AFTER_FIELD, last_field, 0, 0);
		}

	}
    }
  else
    {
	// Same array line....
  	struct s_movement ptr;
  	struct s_movement *ptr_x;
	int x_sz;
      ptr.scr_line = scr_line;
      ptr.arr_line = arr_line;
      ptr.attrib_no = attrib;
	
	A4GL_debug("Move from %d,%d,%d to %d,%d,%d", ptr.scr_line,ptr.arr_line,ptr.attrib_no,scr_line,arr_line,attrib);
      A4GL_debug ("Bef2 ptr=%p", &ptr);

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

  A4GL_debug ("Free ptr 3");
}



/* 
* process any waiting actions 
*
*/
static int
process_control_stack_internal (struct s_inp_arr *arr)
{
  int a;
  int rval;
  int new_state;
  struct s_movement *ptr_movement;
  int cnt;

  rval = -1;
  new_state = 99;


  a = arr->fcntrl_cnt - 1;
  A4GL_debug ("arr->fcntrl_cnt=0x%x a=0x%x", arr->fcntrl_cnt, a);
// Should already have been handled...

  if (a > 10 || a < 0)
    {
      char *ptr = 0;
      *ptr = 0;
      A4GL_assertion (1 == 1, "formcontrol count variable out of range");
    }


/******************************************************************************/
  if (arr->fcntrl[a].op == FORMCONTROL_AFTER_INPUT)
    {

      A4GL_debug ("AFTER INPUT ?");
      A4GL_comments (0);

      if (arr->fcntrl[a].state == 99)
	{
	  A4GL_debug ("DO A4GL_EVENT_AFTER_INP");
	  new_state = 50;
	  rval = A4GL_EVENT_AFTER_INP;		// Do any AFTER INPUT section
	}

      if (arr->fcntrl[a].state == 50)
	{
	  A4GL_debug ("DO A4GL_EVENT_AFTER_INP_CLEAN");
	  A4GL_comments (0);
	  new_state = 0;
	  rval = A4GL_EVENT_AFTER_INP_CLEAN;		// CLEANUP
	}
    }


/******************************************************************************/
  if (arr->fcntrl[a].op == FORMCONTROL_EXIT_INPUT_OK)
    {

      A4GL_debug ("DO EXIT_INPUT_OK");
      A4GL_comments (0);

      if (arr->fcntrl[a].state == 99)
	{
	  if (arr->currentfield)
	    {
	      A4GL_add_to_control_stack (arr, FORMCONTROL_AFTER_ROW, arr->currentfield, 0, 0);
		A4GL_debug("Checking curr_line_is_new : %d for after insert",arr->curr_line_is_new);
	      if (arr->curr_line_is_new==2) {  // If its just 1 then they've not changed anything here...
		      	A4GL_add_to_control_stack (arr, FORMCONTROL_AFTER_INSERT, arr->currentfield, 0, 0); 
	      }

	      if (arr->curr_line_is_new==1) { // They didn't change anything - so not a real insert...
		      arr->no_arr--;
	        	A4GL_set_arr_count (arr->no_arr);	// No new lines ...
	      }



	      A4GL_debug("Setting curr_line_is_new to 0");
	      arr->curr_line_is_new = 0;
	      A4GL_add_to_control_stack (arr, FORMCONTROL_AFTER_FIELD, arr->currentfield, 0, 0);
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


/******************************************************************************/
  if (arr->fcntrl[a].op == FORMCONTROL_EXIT_INPUT_ABORT)
    {
      A4GL_comments (0);
      if (arr->fcntrl[a].state == 99)
	{
	  A4GL_debug ("FORM ABORT..");
	  A4GL_comments (0);
	  int_flag = 1;
	  A4GL_debug ("DO EXIT_INPUT_ABORT");
	  A4GL_add_to_control_stack (arr, FORMCONTROL_AFTER_INPUT, 0, 0, 0);
	  rval = 0;
	  new_state = 10;
	}
      if (arr->fcntrl[a].state == 10)
	{
	  new_state = 0;
	  return -1;
	}


    }


/******************************************************************************/
  if (arr->fcntrl[a].op == FORMCONTROL_BEFORE_DELETE)
    {
      if (arr->fcntrl[a].state == 99)
	{
	  new_state = 50;
	  rval = A4GL_EVENT_BEFORE_DELETE;
	}

      if (arr->fcntrl[a].state == 50)
	{
	  // We want to do the actual delete here...
	  new_state = 0;
	  delete_line_in_array (arr);
	}

    }


/******************************************************************************/
  if (arr->fcntrl[a].op == FORMCONTROL_AFTER_DELETE)
    {
      if (arr->fcntrl[a].state == 99)
	{
	  new_state = 50;
	  rval = A4GL_EVENT_AFTER_DELETE;
	}

      if (arr->fcntrl[a].state == 50)
	{
	  A4GL_add_to_control_stack (arr, FORMCONTROL_AFTER_ROW, arr->currentfield, 0, 0);
	  new_state = 25;
	  rval = A4GL_EVENT_BEFORE_INP; // ?  BEFORE_INPUT ?
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
	  rval = A4GL_EVENT_BEFORE_INP; // ?  BEFORE_INPUT ?
	}
      if (arr->fcntrl[a].state == 10)
	{
	  new_state = 0;
	}



    }


/******************************************************************************/
  if (arr->fcntrl[a].op == FORMCONTROL_BEFORE_ROW)
    {
	int nv;

	//A4GL_pause_execution();
      if (arr->fcntrl[a].state == 99)
	{
	  ptr_movement = (struct s_movement *) arr->fcntrl[a].parameter;

	  A4GL_debug("ptr->movement->arr_line=%d no_arr=%d",ptr_movement->arr_line , arr->no_arr);

	  if (ptr_movement->arr_line > arr->no_arr)
	    {
	      init_arr_line (arr, ptr_movement->arr_line);
	      arr->curr_line_is_new = 1;
	      A4GL_debug("Setting curr_line_is_new to 1");
	      A4GL_debug("BEFORE INSERT");
	      A4GL_debug("curr line is new");
	    }
	  else
	    {
		A4GL_debug("Setting curr_line_is_new to 0");
	      arr->curr_line_is_new = 0;
		A4GL_debug("curr line is not new");
	    }
	   A4GL_debug("checking curr_line_is_new %d",arr->curr_line_is_new);



	  arr->scr_line = ptr_movement->scr_line;
	  A4GL_set_scr_line (ptr_movement->scr_line);

	  arr->arr_line = ptr_movement->arr_line;
	  A4GL_set_arr_curr (ptr_movement->arr_line);
	  A4GL_debug ("MJAMJA a=%d s=%d", ptr_movement->arr_line, ptr_movement->scr_line);

	  if (arr->scr_line == ptr_movement->scr_line) {
	    ireinpalay_arr (arr, 2);
	  }




	nv=arr->nbind;
  	if (arr->start_slice!=-1 && arr->end_slice!=-1) { nv=arr->end_slice-arr->start_slice+1; }


	  for (cnt = 0; cnt < nv; cnt++)
	    {
	      struct struct_scr_field *fprop;
	      fprop = (struct struct_scr_field *) (field_userptr (arr->field_list[0][cnt]));	// props are shared - so we don't need the current line...
		A4GL_debug("Clearing flags zz9pa");
	      fprop->flags = 0;
	    }
	  new_state = 50;
	  rval = A4GL_EVENT_BEF_ROW;
	}





      if (arr->fcntrl[a].state == 50)
	{

	  ptr_movement = (struct s_movement *) arr->fcntrl[a].parameter;
	      	//arr->no_arr++;
	  	if (arr->curr_line_is_new) { 
			if (ptr_movement->arr_line > arr->no_arr) {
	        		A4GL_set_arr_count (ptr_movement->arr_line);	// No new lines ...
			}
				A4GL_add_to_control_stack (arr, FORMCONTROL_BEFORE_INSERT, 0, 0, 0); 
		}
	  	new_state = 25;
	}

      if (arr->fcntrl[a].state == 25) {
	      	new_state=0;
	      }

    }

/******************************************************************************/
  if (arr->fcntrl[a].op == FORMCONTROL_AFTER_ROW)
    {
      new_state = 0;
      rval = A4GL_EVENT_AFT_ROW;
    }

/******************************************************************************/
  if (arr->fcntrl[a].op == FORMCONTROL_BEFORE_INSERT)
    {
	A4GL_debug("Before insert state=%d",arr->fcntrl[a].state);
      if (arr->fcntrl[a].state == 99)
	{
	  // We want to do the actual insert here...
	  FIELD *f;
	  f = arr->field_list[arr->scr_line - 1][arr->curr_attrib];
	  new_state = 80;
	  rval = A4GL_EVENT_BEFORE_INP; //? BEFORE_INPUT ?
	}

      if (arr->fcntrl[a].state == 80)
	{
	  insert_line_in_array (arr);
	  rval = A4GL_EVENT_BEFORE_INP; //? BEFORE_INPUT ? 
	  new_state = 50;
	}

      if (arr->fcntrl[a].state == 50)
	{			// BEFORE INSERT 
	  new_state = 0;
	  rval = A4GL_EVENT_BEFORE_INSERT;
	   A4GL_debug("setting curr_line_is_new to 1");
	  arr->curr_line_is_new = 1;
	}

    }


/******************************************************************************/
  if (arr->fcntrl[a].op == FORMCONTROL_AFTER_INSERT)
    {
	   A4GL_debug("setting curr_line_is_new to 0");
      arr->curr_line_is_new = 0;
      new_state = 0;
      rval = A4GL_EVENT_AFTER_INSERT;
    }

/******************************************************************************/
  if (arr->fcntrl[a].op == FORMCONTROL_KEY_PRESS)
    {

	A4GL_debug("KEY PRESS zz9pa %d state %d\n",arr->fcntrl[a].extent,arr->fcntrl[a].state);
      if (arr->fcntrl[a].state == 99)
	{
	  new_state = 50;
	  last_key_code = arr->fcntrl[a].extent;
	  rval = A4GL_EVENT_KEY_PRESS;
	}


      if (arr->fcntrl[a].state == 50)
	{
	  new_state = 25;
	  if (arr->processed_onkey != 0)
	    {
	      A4GL_debug ("process_key_press");
	      if (field_opts (arr->currentfield) & O_BLANK)
		{
		  A4GL_debug ("O_BLANK MMMM");
		}
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


	  fprop =
	    (struct struct_scr_field *) (field_userptr (arr->currentfield));
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
		A4GL_debug("Extent in range");
	      if (arr->fcntrl[a].extent >= 0 && arr->fcntrl[a].extent <= 255
		  &&
		  (((a_isprint (arr->fcntrl[a].extent))
		    || arr->fcntrl[a].extent == 1
		    || arr->fcntrl[a].extent == 4 )))
		{
		A4GL_debug("Extent check1 %d for currentfield=%p zz9pa",fprop->flags,arr->currentfield);

		  if ((fprop->flags & 1) == 0)
		    {
			int attrib;
		A4GL_debug("Extent check2");
			attrib=arr->curr_attrib;
			if (arr->start_slice!=-1) {
				attrib+=arr->start_slice;
			}
		      switch (arr->binding[attrib].dtype & 255)
			{
			case DTYPE_SMINT:
			case DTYPE_INT:
			case DTYPE_SERIAL:
			case DTYPE_FLOAT:
			case DTYPE_SMFLOAT:
			case DTYPE_DECIMAL:
			case DTYPE_MONEY:
			  A4GL_debug ("MMMM - Clear EOF first pos typing zz9pa");
			  if (arr->curr_line_is_new==1) { arr->curr_line_is_new=2; }
			  A4GL_int_form_driver (arr->currform->form, REQ_CLR_EOF);
			}
		    }
		  A4GL_debug ("SETTING FLAGS IA for currentfield=%p zz9pa",arr->currentfield);
		  fprop->flags |= 2;	// Set the field status flag
		}



	      if (has_picture)
		{
		  int i;
		  int key;
		  FORM *mform;
		  mform = arr->currform->form;
		  i = mform->curcol;
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
		  A4GL_int_form_driver (arr->currform->form,
					arr->fcntrl[a].extent);
		  A4GL_int_form_driver (arr->currform->form, REQ_VALIDATION);
		}


	      if (has_picture && ok)
		{
		  FORM *mform;
		  mform = arr->currform->form;
		  if (strchr ("A#X", picture[mform->curcol]) == 0
		      && picture[mform->curcol]) {
	A4GL_debug("do_key_move");
		    do_key_move ('R', arr, arr->fcntrl[a].extent, has_picture,
				 picture);
			}
		}
		
	      if (a_isprint(arr->fcntrl[a].extent) && arr->fcntrl[a].extent!='\n'&&arr->fcntrl[a].extent!='\t') {
	      A4GL_debug ("Setting BF flag for current field %p zz9pa ok=%d",arr->currentfield,ok);
	      fprop->flags |= 1;	// Clear the before field flag
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
	      fprop =
		(struct struct_scr_field
		 *) (field_userptr (arr->currentfield));

	      if (A4GL_has_bool_attribute (fprop, FA_B_AUTONEXT))	// Don't bother - it aint working...
		{
		  FORM *curses_form;
		  curses_form = arr->currform->form;
		  if (current_field (curses_form) != arr->currentfield)
		    {
		      set_current_field (curses_form, arr->currentfield);
	A4GL_debug("Calling newmovement");
		      A4GL_newMovement (arr, arr->scr_line, arr->arr_line,
					arr->curr_attrib + 1, 'R');
		    }

		}
	    }

	}

      if (arr->fcntrl[a].state == 5)
	{
	  new_state = 0;
	  rval = -1;
	  A4GL_debug("END KEY PRESS zz9pa %d\n",arr->fcntrl[a].extent);
	}
    }

/******************************************************************************/
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
	  fprop =
	    (struct struct_scr_field *) (field_userptr (arr->currentfield));


	  A4GL_set_infield_from_parameter ((long) arr->currentfield);
	  last_field_name = arr->fcntrl[a].field_name;
	  rval = A4GL_EVENT_BEFORE_FIELD_1;
	}


      if (arr->fcntrl[a].state == 50)
	{
	  char *cptr;
	  char *picture = 0;
	  int has_picture = 0;
	  arr->currentfield =
	    arr->field_list[arr->scr_line - 1][arr->curr_attrib];
	  set_current_field (arr->currform->form, arr->currentfield);

	  arr->currform->currentfield = arr->currentfield;
	  A4GL_debug ("Processed after users 'BEFORE FIELD'");

	  fprop =
	    (struct struct_scr_field *) (field_userptr (arr->currentfield));
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
		int attrib=0;
		attrib=arr->curr_attrib;
		if (arr->start_slice!=-1) attrib+=arr->start_slice;

	      if ((arr->binding[attrib].dtype & DTYPE_MASK) != DTYPE_CHAR
		  && (arr->binding[attrib].dtype & DTYPE_MASK) != DTYPE_VCHAR)
		{
		  A4GL_exitwith
		    ("Picture applied to a non-char field not implemented yet..");
		}
	      else
		{
		  int a;
		  int w;
		  char *ptr;
		  cptr = (char *) arr->binding[attrib].ptr + arr->arr_elemsize * (arr->arr_line - 1);
		  w = A4GL_get_field_width (arr->currentfield);
		  has_picture = 1;
		  picture = A4GL_get_str_attribute (fprop, FA_S_PICTURE);
		  ptr = acl_malloc2 (w + 1);
		  strncpy (ptr, cptr, w);
		  ptr[w] = 0;

		  for (a = 0; a < strlen (picture); a++)
		    {
		      if (a > arr->binding[attrib].size)
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
				   arr->binding[attrib].dtype +
				   ENCODE_SIZE (arr-> binding[attrib].  size));
		  A4GL_display_field_contents (arr->currentfield, arr->binding[attrib].  dtype, arr->binding[attrib].  size, ptr);
		  A4GL_debug ("MJAMJA - PTR=%s", ptr);
		}
	    }
	  else
	    {
		int attrib=0;
		attrib=arr->curr_attrib;
		if (arr->start_slice!=-1) attrib+=arr->start_slice;

	      cptr = (char *) arr->binding[attrib].ptr + arr->arr_elemsize * (arr->arr_line - 1);
	      A4GL_push_param (cptr, arr->binding[attrib].dtype +
			       ENCODE_SIZE (arr->binding[attrib].
					    size));
	      A4GL_display_field_contents (arr->currentfield,
					   arr->binding[attrib].dtype,
					   arr->binding[attrib].size, cptr);
	    }


	  if (has_picture)
	    {
	      FORM *mform;
	      A4GL_int_form_driver (arr->currform->form, REQ_OVL_MODE);	// Always in overwrite mode in a picture...
	      mform = arr->currform->form;
	      if (strchr ("A#X", picture[mform->curcol]) == 0 && picture[mform->curcol]) {

                        if (strchr(&picture[mform->curcol+1],'9')
                        ||strchr(&picture[mform->curcol+1],'#')
                        ||strchr(&picture[mform->curcol+1],'X')) {

		
		do_key_move ('R', arr, arr->fcntrl[a].extent, has_picture,
			     picture);
			}
		}
	    }







	  A4GL_comments (fprop);
	  pos_form_cursor (arr->currform->form);
	  A4GL_debug ("Clearing fprop flag -1 BEFORE FIELD for %d %d (%p) zz9pa",
		      arr->scr_line - 1, arr->curr_attrib,arr->currentfield);

	
	  if ((fprop->flags & 1))
	    fprop->flags -= 1;

	  new_state = 0;
	}

    }


/******************************************************************************/
  if (arr->fcntrl[a].op == FORMCONTROL_AFTER_FIELD)
    {
      struct struct_scr_field *fprop;
      int attr;



      int ffc_rval;
      ffc_rval = A4GL_form_field_chk_iarr (arr, -1);


      A4GL_debug ("form_Field_chk returns %d\n", ffc_rval);


      if (ffc_rval != -4)
	{
	  char buff[10024];
	  char *picture;
		int attrib=0;
	  char *cptr;
	  new_state = 0;

		attrib=arr->curr_attrib;
		if (arr->start_slice!=-1) attrib+=arr->start_slice;

	  A4GL_debug ("arr=%p", arr);
	  A4GL_debug ("arr->currentfield=%p field=%p", arr->currentfield,
		      arr->fcntrl[a].field);
	  A4GL_debug ("field_buffer(arr->currentfield)=%p",
		      field_buffer (arr->currentfield, 0));
	  A4GL_debug ("field contents=%s",
		      field_buffer (arr->currentfield, 0));

	  if (arr->currentfield)
	    {
	      fprop =
		(struct struct_scr_field
		 *) (field_userptr (arr->currentfield));
	      strcpy (buff, field_buffer (arr->currentfield, 0));

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
		  if (blank) {
			strcpy (buff, "");
			
		  }
	

		}



	    }
	  else
	    {
	      strcpy (buff, "");
	    }


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


	  attrib=arr->curr_attrib;
	  if (arr->start_slice!=-1) attrib+=arr->start_slice;


	  if (!pop_iarr_var (arr->currform, attrib, arr->arr_line, arr->arr_elemsize, arr->binding))
	    {
	      A4GL_debug ("Called pop_iarr_var - not ok");
	      new_state = 0;
	      A4GL_debug ("Init control stack");
	      A4GL_init_control_stack (arr, 0);
	      rval = -1;
	      return -1;
	    }

	  A4GL_debug ("Called pop_iarr_var - ok");


	  cptr = (char *) arr->binding[attrib].ptr + arr->arr_elemsize * (arr->arr_line - 1);

	  fprop = (struct struct_scr_field *) (field_userptr (arr->currentfield));
	  attr = A4GL_determine_attribute (FGL_CMD_INPUT, arr->display_attrib, fprop, 0);


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
			   arr->binding[attrib].dtype +
			   ENCODE_SIZE (arr->binding[attrib].size));
	  A4GL_display_field_contents (arr->currentfield,
				       arr->binding[attrib].dtype,
				       arr->binding[attrib].size,
				       cptr);
	  new_state = 0;
	  A4GL_set_infield_from_parameter ((long) arr->currentfield);
	  last_field_name = arr->fcntrl[a].field_name;
	  rval = A4GL_EVENT_AFTER_FIELD_1;
	}
      else
	{
	  new_state = 0;
	  A4GL_debug ("Init control stack");
	  if (A4GL_isyes (acl_getenv ("FIRSTCOL_ONERR_INCL")))
	    {
	      A4GL_int_form_driver (arr->currform->form, REQ_BEG_FIELD);
	    }

	  A4GL_init_control_stack (arr, 0);
	  rval = -1;
	  return -1;
	}






    }

  if (new_state != 0)
    {
      if (arr->fcntrl[a].state == new_state)
	{
	  A4GL_debug ("new_state=%d state=%d op=%d", new_state,
		      arr->fcntrl[a].state, arr->fcntrl[a].op);
	  A4GL_exitwith ("Internal error - no change in state");
	}
      A4GL_debug ("Setting input control state to %d", new_state);
      arr->fcntrl[a].state = new_state;
    }
  else
    {
      A4GL_debug ("Popping type %d (%s) off control stack @ %d", arr->fcntrl[a].op,
		debug_get_fcntrl(arr->fcntrl[a].op),
		  a);
      arr->fcntrl_cnt--;
      if (arr->fcntrl[a].parameter)
	{
	  A4GL_debug ("Free parameter");
	  acl_free (arr->fcntrl[a].parameter);
	}
    }
  A4GL_debug ("Returning %d\n", rval);
  return rval;
}

static int
process_control_stack (struct s_inp_arr *sio, struct aclfgl_event_list *evt)
{
  int rval;
  rval = process_control_stack_internal (sio);
  A4GL_debug ("Got rval as : %d", rval);
  switch (rval)
    {
    case A4GL_EVENT_BEFORE_FIELD_1:
      if (A4GL_has_event_for_field (A4GL_EVENT_BEFORE_FIELD, last_field_name, evt))
	{
	  return A4GL_has_event_for_field (A4GL_EVENT_BEFORE_FIELD, last_field_name, evt);
	}
      rval = -1;
      break;
    case A4GL_EVENT_AFTER_FIELD_1:
      if (A4GL_has_event_for_field (A4GL_EVENT_AFTER_FIELD, last_field_name, evt))
	{
	  return A4GL_has_event_for_field (A4GL_EVENT_AFTER_FIELD, last_field_name, evt);
	}
      rval = -1;
      break;
    case A4GL_EVENT_KEY_PRESS:
      if (A4GL_has_event_for_keypress (last_key_code, evt))
	{
	  sio->processed_onkey = 0;
	  return A4GL_has_event_for_keypress (last_key_code, evt);
	}
      rval = -1;
      break;
    case A4GL_EVENT_BEFORE_INP:
      if (A4GL_has_event (A4GL_EVENT_BEFORE_INP, evt))
	return A4GL_has_event (A4GL_EVENT_BEFORE_INP, evt);
      rval = -1;
      break;
    case A4GL_EVENT_AFTER_INP:
      if (A4GL_has_event (A4GL_EVENT_AFTER_INP, evt))
	return A4GL_has_event (A4GL_EVENT_AFTER_INP, evt);
      rval = -1;
      break;
    case A4GL_EVENT_AFTER_INP_CLEAN:
      if (A4GL_has_event (A4GL_EVENT_AFTER_INP_CLEAN, evt))
	return A4GL_has_event (A4GL_EVENT_AFTER_INP_CLEAN, evt);
      rval = -1;
      break;
    case A4GL_EVENT_BEF_ROW:
      if (A4GL_has_event (A4GL_EVENT_BEF_ROW, evt))
	return A4GL_has_event (A4GL_EVENT_BEF_ROW, evt);
      rval = -1;
      break;
    case A4GL_EVENT_AFT_ROW:
      if (A4GL_has_event (A4GL_EVENT_AFT_ROW, evt))
	return A4GL_has_event (A4GL_EVENT_AFT_ROW, evt);
      rval = -1;
      break;
    case A4GL_EVENT_BEFORE_DELETE:
      if (A4GL_has_event (A4GL_EVENT_BEFORE_DELETE, evt))
	return A4GL_has_event (A4GL_EVENT_BEFORE_DELETE, evt);
      if (A4GL_has_event (A4GL_EVENT_BEF_INSERT_DELETE, evt))
	return A4GL_has_event (A4GL_EVENT_BEF_INSERT_DELETE, evt);
      rval = -1;
      break;
    case A4GL_EVENT_AFTER_DELETE:
      if (A4GL_has_event (A4GL_EVENT_AFTER_DELETE, evt))
	return A4GL_has_event (A4GL_EVENT_AFTER_DELETE, evt);
      if (A4GL_has_event (A4GL_EVENT_AFT_INSERT_DELETE, evt))
	return A4GL_has_event (A4GL_EVENT_AFT_INSERT_DELETE, evt);
      rval = -1;
      break;
    case A4GL_EVENT_BEFORE_INSERT:
      if (A4GL_has_event (A4GL_EVENT_BEFORE_INSERT, evt))
	return A4GL_has_event (A4GL_EVENT_BEFORE_INSERT, evt);
      if (A4GL_has_event (A4GL_EVENT_BEF_INSERT_DELETE, evt))
	return A4GL_has_event (A4GL_EVENT_BEF_INSERT_DELETE, evt);
      rval = -1;
      break;
    case A4GL_EVENT_AFTER_INSERT:
      if (A4GL_has_event (A4GL_EVENT_AFTER_INSERT, evt))
	return A4GL_has_event (A4GL_EVENT_AFTER_INSERT, evt);
      if (A4GL_has_event (A4GL_EVENT_AFT_INSERT_DELETE, evt))
	return A4GL_has_event (A4GL_EVENT_AFT_INSERT_DELETE, evt);
      rval = -1;
      break;

    }
  if (rval >= 0 || rval == -1)
    return -1;


  A4GL_debug ("Code : %d\n", rval);
  A4GL_exitwith ("Unhandled code...");
  exit (1);
}




void
A4GL_iarr_arr_fields (struct s_inp_arr *arr, int dattr, int arr_line,
		      int scr_line, int blank)
{
  int a;
  int flg;
  struct s_form_dets *formdets;
  char *cptr;
  static char buff[256];
  int da;
  int nv;
  int attr;

  struct struct_scr_field *fprop;
  A4GL_debug ("In disp_fields");

  if (  arr->currform != UILIB_A4GL_get_curr_form (0))
    {
      A4GL_make_window_with_this_form_current (arr->currform);
    }
  formdets = UILIB_A4GL_get_curr_form (1);

  flg = 0;

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
	 *) (field_userptr (arr->field_list[scr_line - 1][a]));

      // cc 2004.09.06 defualt attribute show be FGL_CMD_DISPLAY_CMD,
      //               only the current field be set to FGL_CMD_INPUT


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

      if (attr != 0) A4GL_set_field_attr_with_attr_already_determined (arr-> field_list[scr_line - 1][a], da, FGL_CMD_INPUT);

      if (!blank)
	{
	  cptr = (char *) arr->binding[bno].ptr + arr->arr_elemsize * (arr_line - 1);
	  A4GL_push_param (cptr, arr->binding[bno].dtype + ENCODE_SIZE (arr->binding[bno].size));
	}
      else
	{
	  strcpy (buff, "");
	  cptr = buff;
	  A4GL_push_null (DTYPE_CHAR, 1);
	  A4GL_debug ("ZZZZZ : %d %p %x", arr->binding[a].dtype, cptr, arr->binding[bno].size);
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
  int a;
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
	A4GL_debug("Calling newmovement");
      A4GL_newMovement (arr, arr->scr_line, arr->arr_line, arr->curr_attrib + 1, 'R');
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
	A4GL_debug("Calling newmovement");
      A4GL_newMovement (arr, arr->scr_line, arr->arr_line,
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

	    {
	      A4GL_debug ("Init control stack");
	      if (arr->currentfield)
		{
		  A4GL_init_control_stack (arr, 0);
		}


	      if (a != arr->curr_attrib)
		{
		  // How risky is this ?
		  arr->currform->currentfield = 0;
		  arr->currentfield = 0;
	A4GL_debug("Calling newmovement");
		  A4GL_newMovement (arr, arr->scr_line, arr->arr_line, a,
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
    nv=s->nbind;
    if (s->start_slice!=-1 && s->end_slice!=-1) { nv=s->end_slice-s->start_slice+1; }


  A4GL_debug ("fgl_fieldtouched - input array");
  for (a = 0; a < s->scr_dim; a++)
    {
      for (b = 0; b < nv; b++)
	{
	  FIELD *f;
	  f = s->field_list[a][b];
	  fprop =
	    (struct struct_scr_field *) (field_userptr (s->field_list[a][b]));
	  A4GL_debug ("FLAGS (%s)%d %d - %d %p %p", txt, a, b, fprop->flags, f, fprop);
	}
    }
}


char *debug_get_fcntrl(int n) {

switch(n) {
case FORMCONTROL_BEFORE_FIELD    : return "FORMCONTROL_BEFORE_FIELD";
case FORMCONTROL_AFTER_FIELD     : return "FORMCONTROL_AFTER_FIELD";
case FORMCONTROL_BEFORE_INPUT    : return "FORMCONTROL_BEFORE_INPUT";
case FORMCONTROL_AFTER_INPUT     : return "FORMCONTROL_AFTER_INPUT";
case FORMCONTROL_EXIT_INPUT_OK   : return "FORMCONTROL_EXIT_INPUT_OK";
case FORMCONTROL_EXIT_INPUT_ABORT: return "FORMCONTROL_EXIT_INPUT_ABORT";
case FORMCONTROL_KEY_PRESS       : return "FORMCONTROL_KEY_PRESS";
case FORMCONTROL_BEFORE_INSERT   : return "FORMCONTROL_BEFORE_INSERT";
case FORMCONTROL_BEFORE_DELETE   : return "FORMCONTROL_BEFORE_DELETE";
case FORMCONTROL_AFTER_INSERT    : return "FORMCONTROL_AFTER_INSERT";
case FORMCONTROL_AFTER_DELETE    : return "FORMCONTROL_AFTER_DELETE";
case FORMCONTROL_BEFORE_ROW      : return "FORMCONTROL_BEFORE_ROW";
case FORMCONTROL_AFTER_ROW       : return "FORMCONTROL_AFTER_ROW";
}
return "Unknown FORMCONTROL";
}

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
# $Id: array.c,v 1.62 2010-02-16 13:17:11 mikeaubury Exp $
#*/


#ifndef lint
	static char const module_id[] =
		"$Id: array.c,v 1.62 2010-02-16 13:17:11 mikeaubury Exp $";
#endif



/**
 * @file
 * Implementation of Display Array
 *
 * @todo Doxygen comments to add
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_lib_ui_tui_int.h"
int set_scrline_da (int np);
int set_arrline_da (int np);
char *a_strchr(char *s,char c);
//int A4GL_get_attr_from_string (char *s);
//
//

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

//extern struct         struct_screen_record *A4GL_get_srec (char *name);
/* struct struct_screen_record *A4GL_get_srec (char *); */

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

//extern int m_lastkey;
extern WINDOW *currwin;
struct s_disp_arr *curr_arr_disp;
int cmode = 0;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/


#define INTERRUPT_HANDLER_NEW_WAY 

static void A4GL_disp_arr_fields_v2 (struct s_disp_arr *disp, int iscurr, int blank, int attr, int arr_line,int first_only,...);
//int A4GL_has_event(int a,struct aclfgl_event_list *evt) ;
//int A4GL_has_event_for_keypress(int a,struct aclfgl_event_list *evt) ;
//int A4GL_has_event_for_field(int cat,char *a,struct aclfgl_event_list *evt) ;
void A4GL_make_window_with_this_form_current(void *form);
/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * Clear a screen record.
 *
 * @param srec The screen record information structure.
 */
static void
clear_srec (struct s_disp_arr *disp,struct struct_screen_record *srec)
{
  int b;
  char srec1[256];
#ifdef DEBUG
  A4GL_debug ("Clearing %s", srec->name);
#endif
  A4GL_chkwin();
  strcpy (srec1, srec->name);
  strcat (srec1, ".*");
#ifdef DEBUG
  A4GL_debug ("Got fields as %s", srec1);
#endif


  for (b = 0; b < srec->dim; b++)
    {
  	A4GL_disp_arr_fields_v2 (disp, 
				0,
				1,  // blank
			 	0,  // Attribute
				0,  // arr_line
				0, // first_only
				srec1, // screen record
				b+1, // field line
				NULL,0);
    }


return;

/*
      for (a = 0; a < srec->attribs.attribs_len + 1; a++) {
	  A4GL_push_char (" ");
	}
      A4GL_disp_arr_fields (srec->attribs.attribs_len + 1, 0, 0, srec1, b + 1, 0, 0);

    }
*/
}

/**
 *
 * @param disp A pointer to the display array inforation strutcure
 * @param type
 * @param no
 */
static void
draw_arr (struct s_disp_arr *disp, int type, int no)
{
  char srec2[256];
  int topline;
  int scr_line;
  int first_only = 0;
  A4GL_chkwin();
#ifdef DEBUG
  {
    A4GL_debug ("in draw_arr %p %d %d", disp, type, no);
  }
#endif
  if (type < 0)
    {
      type = 0 - type;
      first_only = 1;
    }
  topline = disp->arr_line - disp->scr_line + 1;
  scr_line = no - topline + 1;
  strcpy (srec2, disp->srec->name);
  strcat (srec2, ".*");

  if (type == 2)
    {
	int nv;
#ifdef DEBUG
      A4GL_debug ("calling set_arr_Fields");
#endif
	nv=disp->nbind;
	if (disp->start_slice!=-1) { nv=disp->end_slice-disp->start_slice+1; }
      A4GL_set_arr_fields (nv, 0, srec2, scr_line, 0, 0);
#ifdef DEBUG
      {
 A4GL_debug ("Done");
      }
#endif
      return;
    }


#ifdef DEBUG
  A4GL_debug ("Print array no %d to scr %d", no, disp->scr_line);
  A4GL_debug ("calling disp_arR_fields");
#endif

  //disp->highlight=1;

  if (disp->highlight)
    {
#ifdef DEBUG
      A4GL_debug ("With highlight");
#endif
  	A4GL_disp_arr_fields_v2 (disp, type,
				0,  // blank
			 	type*AUBIT_ATTR_REVERSE,  // Attribute
				no,  // arr_line
				first_only,
				srec2, // screen record
				scr_line, // field line
				NULL,0);

    }
  else
    {
#ifdef DEBUG
      A4GL_debug ("Without highlight");
#endif
  	A4GL_disp_arr_fields_v2 (disp, 
				type,
				0,  // blank
			 	0,  // Attribute
				no,  // arr_line
				first_only,
				srec2, // screen record
				scr_line, // field line
				NULL,0);

    }
}

/**
 * Draw / show a screen array.
 *
 * @param disp
 */
static void
draw_arr_all (struct s_disp_arr *disp)
{
  int a;
  int topline;
  topline = disp->arr_line - disp->scr_line + 1;
#ifdef DEBUG
  {
    A4GL_debug ("Draw_arr_all");
  }
#endif
  for (a = 0; a < disp->srec->dim; a++)
    {
      if (a + topline <= disp->no_arr)

	{

	  draw_arr (disp, a + topline == disp->arr_line, a + topline);

#ifdef DEBUG
	  {
	    A4GL_debug ("after draw_arr (6)");
	  }
#endif
	} else {
  		char srec2[256];
  		strcpy (srec2, disp->srec->name);
  		strcat (srec2, ".*");
        	A4GL_disp_arr_fields_v2 (disp,
				0,
                                1,  // blank
                                0,  // Attribute
                                0,  // arr_line
                                0, // first_only
                                srec2, // screen record
                                a+1, // field line
                                NULL,0);
	}

    }

  draw_arr (disp, 1, disp->arr_line);

#ifdef DEBUG
  {
    A4GL_debug ("after draw_arr (7)");
  }
#endif
}

/**
 * 
 * @param arr
 * @param redisp
 */
static void
redisplay_arr (struct s_disp_arr *arr, int redisp)
{

  if (redisp == 2 )
    {
#ifdef DEBUG
      A4GL_debug ("Redisplay all");
#endif
      draw_arr_all (arr);
    }

  if (redisp == 1 )
    {
      draw_arr (arr, 0, arr->last_arr);
      draw_arr (arr, 1, arr->arr_line);
    }
}

/**
 * Assigns the ype of the instruction that are using the array.
 * 
 * @param type The type of array usage :
 *   - I : Input.
 *   - D : Display.
 */
void
A4GL_set_array_mode (int type)
{
  cmode = type;
}

/**
 * The display array loop.
 *
 * Stay in loop until the user type a command that finishes the instruction 
 * (Accept, etc).
 *
 * @param arr A pointer to the display array information structure.
 */
static int
disp_loop_internal (struct s_disp_arr *arr,struct aclfgl_event_list *evt)
{
  struct s_form_dets *form;
  int a;
  int redisp;
  //int acckey;
  FORM *mform;
  int act_as;
  A4GL_chkwin();
  curr_arr_disp = arr;
  form = arr->currform;
  A4GL_set_last_key(0);
  A4GL_set_array_mode ('D');
  abort_pressed=0;

#ifdef DEBUG
  {
    A4GL_debug ("Currform=%p (s_form_dets)", form);
  }
#endif
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


draw_arr (arr, 2, arr->arr_line);
draw_arr (arr, -1, arr->arr_line);

#ifdef DEBUG
  {
    A4GL_debug ("FORM=%p", mform);
  }
#endif

  if (arr->cntrl != 0)
    {
#ifdef DEBUG
	A4GL_debug("Got some cntrl to do.. %d",arr->cntrl);
#endif
      a = arr->cntrl;
#ifdef DEBUG
	A4GL_debug("Got some cntrl to do.. %d",arr->cntrl);
#endif
      arr->cntrl = 0;
    }
  else
    {
	//A4GL_zrefresh();
	arr->processed_onkey=0;


	while (1) {
		int blk;
   		blk=A4GL_has_evt_timeout(evt);

   		if (blk) { return blk; }

        	a = A4GL_getch_win ();
        	if (a!=0&&a!=-1) {
                	A4GL_evt_not_idle(evt);
			break;
        	}
		if (abort_pressed) {
			int_flag=1;
			a=A4GLKEY_INTERRUPT;
#ifdef DEBUG
			A4GL_debug("Abort pressed");
#endif
			break;
		}

	}
/*
// Traditional key handling
// Assume F1 is the Accept Key...
//    
//  The normal truth table would be  :
//
//
//  ON KEY (f1)  ON KEY (ACCEPT) Press Key    FGL_LASTKEY  ACTION
//     N            N               F1        F1       Exit Display    *
//     Y            N               F1        F1       Do ON KEY(f1)   *
//     N            Y               F1        N/A      Exit Display    *
//     Y            Y               F1        F1       Do ON KEY(f1)   *
//
//  ie - ON KEY(ACCEPT) is completely ignored
//
// Setting ONKEY_ACCEPT=Y changes this :
//
//  ON KEY (f1)  ON KEY (ACCEPT) Press Key    FGL_LASTKEY  ACTION
//     N            N               F1        F1       Exit Display       
//     Y            N               F1        F1       Do ON KEY(f1)      
//     N            Y               F1        ACCEPT   Do ON KEY (ACCEPT)
//     Y            Y               F1        F1       Do ON KEY(f1)
*/
	if (A4GL_isyes(acl_getenv("ONKEY_ACCEPT"))) {
        	if (!A4GL_has_event_for_keypress(a,evt)) { // Is it hard coded...
        		if (A4GL_is_special_key(a,A4GLKEY_ACCEPT)&& A4GL_has_event_for_keypress(A4GLKEY_ACCEPT,evt)) a=A4GLKEY_ACCEPT;
		}
	}

	arr->processed_onkey=a;
  	A4GL_set_last_key(a);

        if (A4GL_has_event_for_keypress(a,evt)) {
#ifdef DEBUG
		A4GL_debug("has event...");
#endif
                return A4GL_has_event_for_keypress(a,evt);
        }
	arr->processed_onkey=0;

    }


  redisp = 0;
  act_as=a;

#ifdef DEBUG
  A4GL_debug("act as %d",act_as);
#endif

  if (A4GL_is_special_key(a,A4GLKEY_ACCEPT)) {
	act_as=-99;
  }


  if (A4GL_is_special_key(a ,A4GLKEY_NEXT))
    {
      act_as = A4GLKEY_PGDN;
	a=act_as;
    }

  if (A4GL_is_special_key(a,A4GLKEY_PREV))
    {
      act_as = A4GLKEY_PGUP;
	a=act_as;
    }




  switch (act_as)
    {

    case 18:
        clearok(curscr,1);
        A4GL_mja_refresh ();break;


    case A4GLKEY_PGUP :
      if (arr->arr_line > arr->srec->dim || (arr->arr_line>1&&A4GL_isyes(acl_getenv("SCROLLBACKTO1")))) {
		arr->cntrl=0-A4GLKEY_PGUP;
		if (A4GL_has_event(A4GL_EVENT_AFT_ROW,evt)) return A4GL_has_event(A4GL_EVENT_AFT_ROW,evt);
	} else {
		A4GL_error_nobox (acl_getenv("ARR_DIR_MSG"), 0);
	}
	break;

     case 0-A4GLKEY_PGUP:
        arr->last_arr = arr->arr_line;
	if (arr->arr_line<=arr->srec->dim) { // Aubit Enhancement 
	 arr->scr_line=1;
        }
	arr->arr_line = arr->arr_line - arr->srec->dim;
	while (arr->arr_line-arr->scr_line<0) arr->arr_line++;

	if (arr->arr_line<1) {
		 A4GL_error_nobox (" Balls Up That Shouldn't Happen ", 0);
		 arr->arr_line=1;
		 arr->scr_line=1;
	}
 	redisplay_arr (arr, 2);
        A4GL_set_arr_curr (arr->arr_line);
        A4GL_set_scr_line (arr->scr_line);
	if (A4GL_has_event(A4GL_EVENT_BEF_ROW,evt)) return A4GL_has_event(A4GL_EVENT_BEF_ROW,evt);
	break;

     case 0-A4GLKEY_PGDN:
        arr->last_arr = arr->arr_line;
	arr->arr_line = arr->arr_line + arr->srec->dim;
	if (arr->arr_line >arr->no_arr) {
		//arr->scr_line=1;
		arr->arr_line=arr->no_arr;
	}
       while (arr->arr_line<arr->scr_line) arr->scr_line--;

 	redisplay_arr (arr, 2);
        A4GL_set_arr_curr (arr->arr_line);
        A4GL_set_scr_line (arr->scr_line);
	if (A4GL_has_event(A4GL_EVENT_BEF_ROW,evt)) return A4GL_has_event(A4GL_EVENT_BEF_ROW,evt);
	break;

     case 0-A4GLKEY_SEND:
        arr->last_arr = arr->arr_line;
	arr->arr_line=arr->no_arr;
	arr->scr_line = arr->srec->dim;
        while (arr->arr_line<arr->scr_line) arr->scr_line--;
 	redisplay_arr (arr, 2);
        A4GL_set_arr_curr (arr->arr_line);
        A4GL_set_scr_line (arr->scr_line);
	if (A4GL_has_event(A4GL_EVENT_BEF_ROW,evt)) return A4GL_has_event(A4GL_EVENT_BEF_ROW,evt);
	break;

     case 0-A4GLKEY_SHOME:
        arr->last_arr = arr->arr_line;
	arr->arr_line=1;
	arr->scr_line = 1;
 	redisplay_arr (arr, 2);
        A4GL_set_arr_curr (arr->arr_line);
        A4GL_set_scr_line (arr->scr_line);
	if (A4GL_has_event(A4GL_EVENT_BEF_ROW,evt)) return A4GL_has_event(A4GL_EVENT_BEF_ROW,evt);
	break;


    case A4GLKEY_PGDN :
if ( (arr->arr_line+arr->srec->dim  -arr->scr_line-1<= arr->no_arr) || ( (arr->arr_line< arr->no_arr)&&A4GL_isyes(acl_getenv("SCROLLTOEND"))))  {

      if (arr->arr_line+1 <= arr->no_arr) {
		arr->cntrl=0-A4GLKEY_PGDN;
	  if (A4GL_has_event(A4GL_EVENT_AFT_ROW,evt)) return A4GL_has_event(A4GL_EVENT_AFT_ROW,evt);
	}
} else {
		A4GL_error_nobox (acl_getenv("ARR_DIR_MSG"), 0);
        }
	break;

    case A4GLKEY_SEND : /* shift+end */
	  arr->cntrl=0-A4GLKEY_SEND;
	  if (A4GL_has_event(A4GL_EVENT_AFT_ROW,evt)) return A4GL_has_event(A4GL_EVENT_AFT_ROW,evt);
	break;

    case A4GLKEY_SHOME : /* shift+home */
	  arr->cntrl=0-A4GLKEY_SHOME;
	  if (A4GL_has_event(A4GL_EVENT_AFT_ROW,evt)) return A4GL_has_event(A4GL_EVENT_AFT_ROW,evt);
	break;


    //case A4GLKEY_ENTER:
    case 13:
    case '\t':
    case A4GLKEY_RIGHT:
    case A4GLKEY_DOWN:
#ifdef DEBUG
      A4GL_debug ("Key down");
#endif
      if (arr->arr_line < arr->no_arr)
	{
	  arr->cntrl = 0 - A4GLKEY_DOWN;
	  if (A4GL_has_event(A4GL_EVENT_AFT_ROW,evt)) return A4GL_has_event(A4GL_EVENT_AFT_ROW,evt);
	} else {
		A4GL_error_nobox (acl_getenv("ARR_DIR_MSG"), 0);
        }
      break;

    case 0 - A4GLKEY_DOWN:
#ifdef DEBUG
      A4GL_debug ("Keydown +");
#endif
      arr->last_arr = arr->arr_line;
      arr->arr_line++;
#ifdef DEBUG
      A4GL_debug ("Is really down %d", arr->arr_line);
#endif
      redisp = 1;
      arr->scr_line++;
      if (arr->scr_line > arr->srec->dim)

	{

	  arr->scr_line = arr->srec->dim;

	  redisplay_arr (arr, 2);
	}
      else
	{
	  redisplay_arr (arr, 1);
	}
      A4GL_set_arr_curr (arr->arr_line);
      A4GL_set_scr_line (arr->scr_line);
	if (A4GL_has_event(A4GL_EVENT_BEF_ROW,evt)) return A4GL_has_event(A4GL_EVENT_BEF_ROW,evt);
      break;

    case A4GLKEY_LEFT:
    case A4GLKEY_UP:
      if (arr->arr_line > 1) {
	  arr->cntrl = 0 - A4GLKEY_UP;
	  if (A4GL_has_event(A4GL_EVENT_AFT_ROW,evt)) return A4GL_has_event(A4GL_EVENT_AFT_ROW,evt);
	} else {
		A4GL_error_nobox (acl_getenv("ARR_DIR_MSG"), 0);
        }
      break;

    case 0 - A4GLKEY_UP:
      arr->last_arr = arr->arr_line;
      arr->arr_line--;
#ifdef DEBUG
      A4GL_debug ("Is really up");
#endif
      arr->scr_line--;
      if (arr->scr_line == 0)

	{

	  arr->scr_line = 1;

	  redisplay_arr (arr, 2);

	}
      else
	{
	  redisplay_arr (arr, 1);
	}
      A4GL_set_arr_curr (arr->arr_line);
      A4GL_set_scr_line (arr->scr_line);
	if (A4GL_has_event(A4GL_EVENT_BEF_ROW,evt)) return A4GL_has_event(A4GL_EVENT_BEF_ROW,evt);
      break;


    case -99:
#ifdef DEBUG
		A4GL_debug("Maybe ACCEPT");
#endif
      		if (A4GL_has_event(A4GL_EVENT_AFTER_INP_CLEAN,evt)) return A4GL_has_event(A4GL_EVENT_AFTER_INP_CLEAN,evt);
		break;

    case A4GLKEY_INTERRUPT: 
#ifdef DEBUG
 		A4GL_debug("act as %d - abort!",act_as);
#endif
		int_flag=1;
      		if (A4GL_has_event(A4GL_EVENT_AFTER_INP_CLEAN,evt)) return A4GL_has_event(A4GL_EVENT_AFTER_INP_CLEAN,evt);
	return 0;

    case -101:
      	return 0;			/* ACCEPT */
	break;

    case 26:			/* control-z */
      return 0;
    }
  return -1;
}


static int disp_loop(struct s_disp_arr *arr,struct aclfgl_event_list *evt) {
int rval;
rval=disp_loop_internal(arr,evt);
if (rval<-1) {
        FPRINTF(stderr, "Returned <0 : %d\n",rval);
        exit(0);
}
return rval;
}

/**
 * Execute a display array.
 *
 * This is part of run-time of TUI interface.
 *
 * @param dis A pointer to the display array information structure.
 * @param ptr 
 * @param srecname Screen record name of the form
 * @param attrib The attributes
 */
int
 UILIB_A4GL_disp_arr_v2 (
void *dispv, void *ptr, char *srecname, int attrib, char  *scrollf,int scrollw,void *vevt)
{
  int a;
struct s_disp_arr *disp;
struct aclfgl_event_list *evt;
int nv;
//int blk;
disp=dispv;
evt=vevt;

  A4GL_chkwin();
  curr_arr_disp = disp;
#ifdef DEBUG
  A4GL_debug ("In A4GL_disp_arr : %s %p %p %d", srecname, ptr, disp, attrib);
#endif
  if (disp->srec == 0)
    {
#ifdef DEBUG
      A4GL_debug ("disparr1");
#endif
      disp->srec = A4GL_get_srec (srecname);


      if (disp->srec == 0)
	{
	  A4GL_exitwith ("Screen record not found");
	  return 0;
	}

      disp->currform = UILIB_A4GL_get_curr_form (1);
#ifdef DEBUG
      {
 A4GL_debug ("disp->currform=%p", disp->currform);
      }
#endif
      disp->last_arr = -1;
      disp->scr_line = 1;
      disp->arr_line = 1;
      disp->cntrl = 1;
      disp->highlight = 0;
      disp->attribute=attrib;

#ifdef DEBUG
      A4GL_debug ("disparr2");
#endif
      if (disp->srec == 0)
	{
	  A4GL_exitwith ("Screen record does not exist");

	  return 0;

	}
#ifdef DEBUG
      A4GL_debug ("disparr3");
#endif
 
     nv=disp->nbind;
     if (disp->start_slice!=-1) {nv=disp->end_slice - disp->start_slice +1;}

      if (disp->srec->attribs.attribs_len != nv)
	{
		A4GL_exitwith("Too many or too few variables for fields");

#ifdef DEBUG
	  	A4GL_debug ("Too many or too few variables for fields %d %d %d", disp->srec->dim, disp->nbind, disp->srec->attribs.attribs_len);
#endif

	  return -999;

	}

#ifdef DEBUG
      A4GL_debug ("Clearing Record");
#endif
      clear_srec (disp,disp->srec);
#ifdef DEBUG
      A4GL_debug ("Cleared record");
#endif

	A4GL_clr_evt_timeouts(evt);

      for (a = 0; a < disp->srec->dim; a++)

	{

	  if (a < disp->no_arr)

	    {

#ifdef DEBUG
	      {
	 A4GL_debug ("call draw_arr (1)");
	      }
#endif
	      draw_arr (disp, a + 1 == disp->arr_line, a + 1);

#ifdef DEBUG
	      {
	 A4GL_debug ("after draw_arr (1)");
	      }
#endif
	    }

	}
#ifdef DEBUG
      {
 A4GL_debug ("call draw_arr (2)");
      }
#endif
      draw_arr (disp, 1, disp->arr_line);
#ifdef DEBUG
      {
 A4GL_debug ("after draw_arr (2)");
      }
#endif
      //A4GL_gui_scroll (disp->no_arr);
      A4GL_set_arr_curr (disp->arr_line);
      A4GL_set_scr_line (disp->scr_line);
      A4GL_mja_wrefresh (currwin);
      if (A4GL_has_event(A4GL_EVENT_BEF_ROW,evt)) return A4GL_has_event(A4GL_EVENT_BEF_ROW,evt);
    }
#ifdef DEBUG
  A4GL_debug ("disparr4");
#endif

  return disp_loop (disp,evt);
}

/**
 * Set the screen line.
 *
 * @param np Number of parameters.
 * @return 
 *   - 1 : Everithing OK.
 *   - 0 : There was an error.
 */

int set_scrline_da (int np)
{
  int a;
  if (np != 1)
    {
      A4GL_exitwith ("set_scrline requires 1 parameter");
      return 0;
    }
  a = A4GL_pop_int ();
  curr_arr_disp->scr_line = a;
  A4GL_set_scr_line (a);
  draw_arr_all (curr_arr_disp);
#ifdef DEBUG
  {    A4GL_debug ("Set scrline...%d", a);  }
#endif
    return 0;
}



/**
 *
 * @param np Number of parameters.
 */

int set_arrline_da (int np)
{
  int a;
  if (np != 1)
    {
      A4GL_exitwith ("set_arrline requires 1 parameter");
      return 0;
    }
  a = A4GL_pop_int ();
  curr_arr_disp->arr_line = a;
  A4GL_set_arr_curr (a);
  draw_arr_all (curr_arr_disp);

#ifdef DEBUG
  {    A4GL_debug ("Set arrline... %d", a);  }
#endif
    return 0;
}


int
UILIB_aclfgl_fgl_set_arrline(int np)
{
	if (cmode=='D') {
		return set_arrline_da(np);
	}

	if (cmode=='I') {
		return set_arrline_ia(np);
	}
return 0;
}


int
UILIB_aclfgl_fgl_set_scrline(int np)
{
  if (cmode=='D') {
    return set_scrline_da(np);
  }

  if (cmode=='I') {
    return set_scrline_ia(np);
  }
  A4GL_exitwith("set_scrline() may only be called when in a display/input array");
  return 0;
}







static void
A4GL_disp_arr_fields_v2 (struct s_disp_arr *disp,int iscurr, int blank, int attr, int arr_line, int first_only, ...)
{
  int a;
  va_list ap;
  int flg;
int was_disabled=0;
int orig_set=0;
  struct s_form_dets *formdets;
  FIELD **field_list;
  int nofields;
  char *cptr;
  static char buff[256];
  struct struct_scr_field *f;
#ifdef DEBUG
  A4GL_debug ("In disp_arr_fields_v2 - %p blank=%d attr=%d arr_line=%d",disp,blank,attr,arr_line);
#endif
  formdets = UILIB_A4GL_get_curr_form (1);
  flg = 0;

  va_start (ap, first_only);
	
  nofields = A4GL_gen_field_list (&field_list, formdets, 9999 , &ap,0);

#ifdef DEBUG
  A4GL_debug("disp_arr_fields_v2 - %d fields",nofields);
#endif

  if (first_only) {
	int n;
	int n2;
		n=local_field_opts(field_list[0]);
		orig_set=n;
		n2=n;
#ifdef DEBUG
		A4GL_debug("First only set : %x %x %x",n,O_ACTIVE,O_EDIT);
#endif
		nofields=0;
		if ((n&O_EDIT)==0) { was_disabled=1; n2+=O_EDIT;}
		if ((n&O_ACTIVE)==0) { was_disabled=1; n2+=O_ACTIVE;}
#ifdef DEBUG
		A4GL_debug("First only set now  %x %x %x",n2,O_ACTIVE,O_EDIT);
#endif
		local_set_field_opts(field_list[0],n2);
	}

  for (a=nofields;a>=0;a--) {
	int nattr;
	int bno;
  	f = (struct struct_scr_field *) (field_userptr (field_list[a]));
#ifdef DEBUG
	A4GL_debug("f=%p",f);
#endif

	bno=a;
	if (disp->start_slice!=-1) {
		bno+=disp->start_slice;
	}


  	if (!blank) {
#ifdef DEBUG
			A4GL_debug("Displaying something..");
			A4GL_debug("disp->binding[a].ptr =%p",disp->binding[bno].ptr );
			A4GL_debug("disp->arr_elemsize=%d",disp->arr_elemsize);
			A4GL_debug("arr_line=%d",arr_line);
#endif
             		cptr=(char *) disp->binding[bno].ptr + disp->arr_elemsize * (arr_line - 1);
#ifdef DEBUG
			A4GL_debug("cptr=%p",cptr);
			A4GL_debug(" disp->binding[a].dtype=%d", disp->binding[bno].dtype);
			A4GL_debug("ENCODE_SIZE(disp->binding[a].size)=%d",ENCODE_SIZE(disp->binding[bno].size));
#endif
             		A4GL_push_param (cptr, disp->binding[bno].dtype+ENCODE_SIZE(disp->binding[bno].size));
    	} else {
#ifdef DEBUG
			A4GL_debug("Displaying blank..");
#endif
                        strcpy(buff,"");
                        cptr=&buff[0];
			A4GL_setnull(disp->binding[bno].dtype, cptr,disp->binding[bno].size);
                        A4GL_push_null (disp->binding[bno].dtype, disp->binding[bno].size);
        }


  	A4GL_display_field_contents(field_list[a],disp->binding[bno].dtype,disp->binding[bno].size,cptr, disp->binding[bno].dtype+ENCODE_SIZE(disp->binding[bno].size));

  	nattr=A4GL_determine_attribute(FGL_CMD_DISPLAY_CMD, disp->attribute, f,field_buffer(field_list[a],0));
#ifdef DEBUG
	A4GL_debug("XXXX3 nattr=%d",nattr);
#endif





	if (attr&AUBIT_ATTR_REVERSE) {
		if (nattr&AUBIT_ATTR_REVERSE) 	nattr=nattr-AUBIT_ATTR_REVERSE;
		else 				nattr=nattr+AUBIT_ATTR_REVERSE;
	}


        if (disp->curr_display ) {
	         if (iscurr) {
				nattr=A4GL_strattr_to_num(disp->curr_display);
	                 	//nattr = A4GL_get_attr_from_string (disp->curr_display);
	                 	if (attr&AUBIT_ATTR_REVERSE) {
                            	if (nattr&AUBIT_ATTR_REVERSE)   nattr=nattr-AUBIT_ATTR_REVERSE;
                            	else                            nattr=nattr+AUBIT_ATTR_REVERSE;
                         	}
		 } else {
			 // Not current..
			 // we need to remove the current settings..
		 }
		A4GL_set_field_attr_with_attr (field_list[a], nattr,FGL_CMD_DISPLAY_CMD);
	} else {
  		if (nattr != 0) A4GL_set_field_attr_with_attr (field_list[a], nattr,FGL_CMD_DISPLAY_CMD);
	}


#ifdef DEBUG
	A4GL_debug("XXXX3 nattr now =%d (reverse=%d)",nattr,attr&AUBIT_ATTR_REVERSE);
	A4GL_debug("Attr=%d",attr);
#endif


	if (first_only) {
		//int was_disabled=0;

		set_current_field (formdets->form, field_list[a]);
		A4GL_mja_pos_form_cursor(formdets->form);
		//A4GL_mja_wrefresh (currwin);
		if (orig_set) local_set_field_opts(field_list[0],orig_set);
	}

  }
  free(field_list);

}




void UILIB_A4GL_acli_scroll_ap(int n,va_list *ap) {
struct s_form_dets *f;
int a;
int srec_no;
char barr[256];
char *ptr;
FIELD ***buff;
int b;
int attr;
FIELD *field;
int fno;
int mno;

int dim;
int nfields;
int dir;
char *arr;
arr=va_arg(*ap,char *);

if (n<0) {
        dir=-1;
        n=0-n;
} else {
        dir=1;
}



if (n>1) {
	int cnt;
	for (cnt=0;cnt<n;cnt++) {
	     A4GL_acli_scroll(dir,arr,0,0,0);
        }
	return;
}


f=UILIB_A4GL_get_curr_form (1);
strcpy(barr,arr);

ptr=a_strchr(barr,'.');

if (ptr==0) {
        A4GL_exitwith("Internal error - expected a .* in screen record");
        return;
}

*ptr=0;

#ifdef DEBUG
A4GL_debug("barr=%s",barr);
#endif
A4GL_assertion(f->fileform==NULL,"No fileform");
srec_no=A4GL_find_srec(f->fileform,barr);

if (srec_no==-1) {
        A4GL_exitwith("Unknown screen record");
        return;
}

#ifdef DEBUG
A4GL_debug("srec_no=%d nrows=%d attribs=%d",srec_no,
f->fileform->records.records_val[srec_no].dim,
f->fileform->records.records_val[srec_no].attribs.attribs_len);
#endif
buff=acl_malloc2(sizeof(char *) * f->fileform->records.records_val[srec_no].dim);


for (a=0;a<f->fileform->records.records_val[srec_no].dim;a++) {
	buff[a]=acl_malloc2(sizeof(char *) * f->fileform->records.records_val[srec_no].attribs.attribs_len);
}

dim=f->fileform->records.records_val[srec_no].dim;
nfields=f->fileform->records.records_val[srec_no].attribs.attribs_len;
for (b=0;b<nfields;b++) {
	for (a=0;a<dim;a++) {
		attr=f->fileform->records.records_val[srec_no].attribs.attribs_val[b];
      		fno = f->fileform->attributes.attributes_val[attr].field_no;
		mno=f->fileform->fields.fields_val[fno].metric.metric_val[a];
		field=(void *)f->fileform->metrics.metrics_val[mno].field;
#ifdef DEBUG
		A4GL_debug("SCROLL %s [ %d] . %d = %p (%s)",barr,a,b,field,field_buffer(field,0));
#endif
		buff[a][b]=field;
	}
}


if (dir==-1) {
	for (a=dim-1;a>0;a--) {
		for (b=0;b<nfields;b++) {
#ifdef DEBUG
			A4GL_debug("field[%d][%d] = buffer[%d][%d]",a,b,a-1,b);
#endif
			ptr=field_buffer(buff[a-1][b],0);
#ifdef DEBUG
			A4GL_debug("              = %s",ptr);
#endif
			set_field_buffer(buff[a][b],0,ptr);
		}
	}
	for (b=0;b<nfields;b++) {
			set_field_buffer(buff[0][b],0,"");
	}
}

if (dir==1) {
	for (a=0;a<dim-1;a++) {
		for (b=0;b<nfields;b++) {
#ifdef DEBUG
			A4GL_debug("field[%d][%d] = buffer[%d][%d]",a,b,a+1,b);
#endif
			ptr=field_buffer(buff[a+1][b],0);
#ifdef DEBUG
			A4GL_debug("              = %s",ptr);
#endif
			set_field_buffer(buff[a][b],0,ptr);
		}
	}
	for (b=0;b<nfields;b++) {
			set_field_buffer(buff[dim-1][b],0,"");
	}
}






}



/* =============================== EOF ============================ */


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
# $Id: array.c,v 1.15 2003-08-24 17:54:14 mikeaubury Exp $
#*/

/**
 * @file
 * Implementation of Display Array
 *
 * @todo Doxygen A4GL_comments to add
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_lib_ui_tui_int.h"

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

extern int m_lastkey;
extern WINDOW *currwin;
struct s_disp_arr *curr_arr_disp;
int cmode = 0;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

#ifdef OLD
int A4GL_disp_arr_ap (struct s_disp_arr *disp, void *ptr, char *srecname,
		 int attrib, va_list * ap);
void A4GL_set_field_attr_with_attr (FIELD * field, int attr, int cmd_type);
void A4GL_display_field_contents (FIELD * field, int d1, int s1, char *ptr1);
#endif

static void A4GL_disp_arr_fields_v2 (struct s_disp_arr *disp, int blank, int attr, int arr_line,int first_only,...);
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
  A4GL_debug ("Clearing %s", srec->name);
  A4GL_chkwin();
  strcpy (srec1, srec->name);
  strcat (srec1, ".*");
  A4GL_debug ("Got fields as %s", srec1);


  for (b = 0; b < srec->dim; b++)
    {
  	A4GL_disp_arr_fields_v2 (disp, 
				1,  // blank
			 	0,  // Attribute
				0,  // arr_line
				0, // first_only
				srec1, // screen record
				b+1, // field line
				0,0);
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
      A4GL_debug ("calling set_arr_Fields");
      A4GL_set_arr_fields (disp->nbind, 0, srec2, scr_line, 0, 0);
#ifdef DEBUG
      {
 A4GL_debug ("Done");
      }
#endif
      return;
    }

  //if (first_only)
    //A4GL_push_bind (disp->binding, 1, no, disp->arr_elemsize);
  //else
    //A4GL_push_bind (disp->binding, disp->nbind, no, disp->arr_elemsize);

  A4GL_debug ("Print array no %d to scr %d", no, disp->scr_line);
  A4GL_debug ("calling disp_arR_fields");

  //disp->highlight=1;

  if (disp->highlight)
    {
      A4GL_debug ("With highlight");
  	A4GL_disp_arr_fields_v2 (disp, 
				0,  // blank
			 	type*AUBIT_ATTR_REVERSE,  // Attribute
				no,  // arr_line
				first_only,
				srec2, // screen record
				scr_line, // field line
				0,0);

    }
  else
    {
      A4GL_debug ("Without highlight");
  	A4GL_disp_arr_fields_v2 (disp, 
				0,  // blank
			 	0,  // Attribute
				no,  // arr_line
				first_only,
				srec2, // screen record
				scr_line, // field line
				0,0);

      //A4GL_disp_arr_fields (disp->nbind, first_only, 0, srec2, scr_line, 0, 0);
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
                                1,  // blank
                                0,  // Attribute
                                0,  // arr_line
                                0, // first_only
                                srec2, // screen record
                                a+1, // field line
                                0,0);
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
  if (redisp == 1)
    {
      A4GL_debug ("Redisplay one");
      draw_arr (arr, 0, arr->last_arr);
#ifdef DEBUG
      {
 A4GL_debug ("after draw_arr (4)");
      }
#endif
      A4GL_debug ("Display one");
      draw_arr (arr, 1, arr->arr_line);
#ifdef DEBUG
      {
 A4GL_debug ("after draw_arr (5)");
      }
#endif
    }
  if (redisp == 2)
    {
      A4GL_debug ("Redisplay all");
      draw_arr_all (arr);
    }
  A4GL_mja_wrefresh (currwin);
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
disp_loop (struct s_disp_arr *arr)
{
  struct s_form_dets *form;
  int a;
  int redisp;
  FORM *mform;
  A4GL_chkwin();
  curr_arr_disp = arr;
  form = arr->currform;
  m_lastkey = 0;
  A4GL_set_array_mode ('D');

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


draw_arr (arr, 2, arr->arr_line);
draw_arr (arr, -1, arr->arr_line);
//pos_form_cursor(mform);


//A4GL_mja_wrefresh (currwin);

#ifdef DEBUG
  {
    A4GL_debug ("FORM=%p", mform);
  }
#endif
  if (arr->cntrl != 0)
    {
      a = arr->cntrl;
      arr->cntrl = 0;
    }
  else
    {
	//A4GL_zrefresh();

      a = A4GL_getch_win ();
      A4GL_debug("Got a as %x\n",a);
      m_lastkey = a;
    }



  redisp = 0;

  if (a==A4GL_key_val ("ACCEPT")) {
	a=27;
  }


  if (a == A4GL_key_val ("NEXT"))
    {
      a = A4GLKEY_PGDN;
    }

  if (a == A4GL_key_val ("PREV"))
    {
      a = A4GLKEY_PGUP;
    }




  switch (a)
    {

    case 18:
        clearok(curscr,1);
        A4GL_mja_refresh ();break;


    case A4GLKEY_PGUP :
      if (arr->arr_line > arr->srec->dim || (arr->arr_line>1&&A4GL_isyes(acl_getenv("SCROLLBACKTO1")))) {
		arr->cntrl=0-A4GLKEY_PGUP;
		return -11;
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
        return -10;
	break;

     case 0-A4GLKEY_PGDN:
        arr->last_arr = arr->arr_line;
	arr->arr_line = arr->arr_line + arr->srec->dim;
	if (arr->arr_line >arr->no_arr) {
		arr->scr_line=1;
		arr->arr_line=arr->no_arr;
	}
 	redisplay_arr (arr, 2);
        A4GL_set_arr_curr (arr->arr_line);
        A4GL_set_scr_line (arr->scr_line);
        return -10;
	break;



    case A4GLKEY_PGDN :
      if (arr->arr_line+1 < arr->no_arr) {
		arr->cntrl=0-A4GLKEY_PGDN;
		return -11;
	} else {
		A4GL_error_nobox (acl_getenv("ARR_DIR_MSG"), 0);
        }
	break;


    case '\t':
    case A4GLKEY_RIGHT:
    case A4GLKEY_DOWN:
      A4GL_debug ("Key down");
      if (arr->arr_line < arr->no_arr)
	{
	  arr->cntrl = 0 - A4GLKEY_DOWN;
	  return -11;
	} else {
		A4GL_error_nobox (acl_getenv("ARR_DIR_MSG"), 0);
        }
      break;

    case 0 - A4GLKEY_DOWN:
      A4GL_debug ("Keydown +");
      arr->last_arr = arr->arr_line;
      arr->arr_line++;
      A4GL_debug ("Is really down %d", arr->arr_line);
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
      return -10;
      break;

    case A4GLKEY_LEFT:
    case A4GLKEY_UP:
      if (arr->arr_line > 1) {
	  arr->cntrl = 0 - A4GLKEY_UP;
	  return -11;
	} else {
		A4GL_error_nobox (acl_getenv("ARR_DIR_MSG"), 0);
        }
      break;

    case 0 - A4GLKEY_UP:
      arr->last_arr = arr->arr_line;
      arr->arr_line--;
      A4GL_debug ("Is really up");
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
      return -10;
      break;
    case 27:
      return 0;			/* escape */

    case 26:			/* control-z */
      return 0;
    }
  return -90;
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
A4GL_disp_arr_ap (
void *dispv, void *ptr, char *srecname, int attrib,
	     va_list * ap)
{
  int a;
struct s_disp_arr *disp;
disp=dispv;
  A4GL_chkwin();
  curr_arr_disp = disp;
  A4GL_debug ("In A4GL_disp_arr : %s %p %p %d", srecname, ptr, disp, attrib);
  if (disp->srec == 0)
    {
      A4GL_debug ("disparr1");
      disp->srec = A4GL_get_srec (srecname);


      if (disp->srec == 0)
	{
	  A4GL_exitwith ("Screen record not found");
	  return 0;
	}

      disp->currform = A4GL_get_curr_form (1);
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

      A4GL_debug ("disparr2");
      if (disp->srec == 0)
	{
	  A4GL_exitwith ("Screen record does not exist");

	  return 0;

	}
      A4GL_debug ("disparr3");

      if (disp->srec->attribs.attribs_len != disp->nbind)
	{
	  A4GL_debug ("Too many or too few variables for fields %d %d %d",
		 disp->srec->dim, disp->nbind,
		 disp->srec->attribs.attribs_len);

	  return 0;

	}

      A4GL_debug ("Clearing Record");
      clear_srec (disp,disp->srec);
      A4GL_debug ("Cleared record");
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
      A4GL_gui_scroll (disp->no_arr);
      A4GL_set_arr_curr (disp->arr_line);
      A4GL_set_scr_line (disp->scr_line);
      A4GL_mja_wrefresh (currwin);

      return -10;
    }
  A4GL_debug ("disparr4");
  return disp_loop (disp);
}

/**
 * Set the screen line.
 *
 * @param np Number of parameters.
 * @return 
 *   - 1 : Everithing OK.
 *   - 0 : There was an error.
 */
/*
static int
set_scrline_da (int np)
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
    return 1;
}
*/


/**
 *
 * @param np Number of parameters.
 */
/*
static int
set_arrline_da (int np)
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
    return 1;
}
*/

/**
 * Not used
 *
 * @todo : Remove if not used.
 * @deprecated Removal candidate.
 * @param np Number of parameters.
 */
/*
static int
aclfgl_set_arrline(int np)
{
	if (cmode=='D') {
		return set_arrline_da(np);
	}

	if (cmode=='I') {
		return set_arrline_ia(np);
	}
return 0;
}
*/

/**
 * Not used
 * @todo : Remove if not used.
 * @deprecated Removal candidate.
 */
/*
static int
aclfgl_set_scrline(int np)
{
  if (cmode=='D') {
    return set_scrline_da(np);
  }

  if (cmode=='I') {
    return set_scrline_ia(np);
  }
  exitwith("set_scrline() may only be called when in a display/input array");
  return 0;
}
*/






static void
A4GL_disp_arr_fields_v2 (struct s_disp_arr *disp, int blank, int attr, int arr_line, int first_only, ...)
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
  A4GL_debug ("In disp_arr_fields_v2 - %p blank=%d attr=%d arr_line=%d",disp,blank,attr,arr_line);
  formdets = A4GL_get_curr_form (1);
  flg = 0;

  va_start (ap, first_only);
	
  nofields = A4GL_gen_field_list (&field_list, formdets, 9999 , &ap);

  A4GL_debug("disp_arr_fields_v2 - %d fields",nofields);

  if (first_only) {
	int n;
	int n2;
		n=field_opts(field_list[0]);
		orig_set=n;
		n2=n;
		A4GL_debug("First only set : %x %x %x",n,O_ACTIVE,O_EDIT);
		nofields=0;
		if ((n&O_EDIT)==0) { was_disabled=1; n2+=O_EDIT;}
		if ((n&O_ACTIVE)==0) { was_disabled=1; n2+=O_ACTIVE;}
		A4GL_debug("First only set now  %x %x %x",n2,O_ACTIVE,O_EDIT);
		set_field_opts(field_list[0],n2);
	}

  for (a=nofields;a>=0;a--) {
	int nattr;
  	f = (struct struct_scr_field *) (field_userptr (field_list[a]));
	A4GL_debug("f=%p",f);




  	if (!blank) {
			A4GL_debug("Displaying something..");
             		cptr=(char *) disp->binding[a].ptr + disp->arr_elemsize * (arr_line - 1);
             		A4GL_push_param (cptr, disp->binding[a].dtype+ENCODE_SIZE(disp->binding[a].size));
    	} else {
			A4GL_debug("Displaying blank..");
                        strcpy(buff,"");
                        cptr=&buff[0];
			A4GL_setnull(disp->binding[a].dtype, cptr,disp->binding[a].size);
                        A4GL_push_null (disp->binding[a].dtype, disp->binding[a].size);
        }


  	A4GL_display_field_contents(field_list[a],disp->binding[a].dtype,disp->binding[a].size,cptr);

  	nattr=A4GL_determine_attribute(FGL_CMD_DISPLAY_CMD, disp->attribute, f,field_buffer(field_list[a],0));
	A4GL_debug("XXXX3 nattr=%d",nattr);

	if (attr&AUBIT_ATTR_REVERSE) {
		if (nattr&AUBIT_ATTR_REVERSE) 	nattr=nattr-AUBIT_ATTR_REVERSE;
		else 				nattr=nattr+AUBIT_ATTR_REVERSE;
	}

	A4GL_debug("XXXX3 nattr now =%d (reverse=%d)",nattr,attr&AUBIT_ATTR_REVERSE);
	A4GL_debug("Attr=%d",attr);
  	if (nattr != 0) A4GL_set_field_attr_with_attr (field_list[a], nattr,FGL_CMD_DISPLAY_CMD);


	if (first_only) {
		//int was_disabled=0;

		set_current_field (formdets->form, field_list[a]);
		pos_form_cursor(formdets->form);
		A4GL_mja_wrefresh (currwin);
		if (orig_set) set_field_opts(field_list[0],orig_set);
	}

  }
  free(field_list);

}








/* =============================== EOF ============================ */

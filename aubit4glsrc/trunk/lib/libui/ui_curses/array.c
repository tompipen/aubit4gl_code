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
# $Id: array.c,v 1.1 2002-06-26 06:11:44 afalout Exp $
#*/

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


#ifdef OLD_INCL

	#include "a4gl_tui_tui.h"
	#include "a4gl_dbform.h"
	#include "a4gl_aubit_lib.h"
	#include "a4gl_runtime_tui.h"
	#include "a4gl_debug.h"

#else

    #include "a4gl_lib_ui_tui_int.h"

#endif

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

/* struct struct_screen_record *get_srec (char *); */

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

extern int m_lastkey;
extern WINDOW *currwin;
struct s_disp_arr *curr_arr;
int cmode=0;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

int disp_arr(struct s_disp_arr *disp, void *ptr, char *srecname,int attrib,va_list *ap);

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
clear_srec (struct struct_screen_record *srec)
{
  int a;
  int b;
  char srec1[256];
  debug ("Clearing %s", srec->name);
  strcpy (srec1, srec->name);
  strcat (srec1, ".*");
  debug ("Got fields as %s", srec1);
  for (b = 0; b < srec->dim; b++)
    {
      for (a = 0; a < srec->attribs.attribs_len + 1; a++)

	{

	  push_char (" ");

	}
      debug ("disp_fields(%d,%d,%s,%d,%d)", srec->attribs.attribs_len + 1, 0, srec1, b, 0, 0);
      disp_arr_fields (srec->attribs.attribs_len + 1, 0,0, srec1, b + 1, 0, 0);
    }
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
  int first_only=0;
#ifdef DEBUG
  {    debug ("in draw_arr %p %d %d", disp, type, no);  }
#endif
  if (type<0) {
	type=0-type;
	first_only=1;
	}
  topline = disp->arr_line - disp->scr_line + 1;
  scr_line = no - topline + 1;
  strcpy (srec2, disp->srec->name);
  strcat (srec2, ".*");
  if (type == 2)
    {
      debug ("calling set_arr_Fields");
      set_arr_fields (disp->nbind, 0, srec2, scr_line, 0, 0);
#ifdef DEBUG
      {	debug ("Done");      }
#endif
      return;
    }

	if (first_only)
	  push_bind (disp->binding, 1, no, disp->arr_elemsize);
	else
	  push_bind (disp->binding, disp->nbind, no, disp->arr_elemsize);

  debug ("Print array no %d to scr %d", no, disp->scr_line);
  debug ("calling disp_arR_fields");

  if (disp->highlight)
    {
      debug ("With highlight");
      disp_arr_fields (disp->nbind, first_only,type * A_REVERSE, srec2, scr_line, 0, 0);
    }
  else
    {
      debug ("Without highlight");
      disp_arr_fields (disp->nbind, first_only,0, srec2, scr_line, 0, 0);
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
  {    debug ("Draw_arr_all");  }
#endif
  for (a = 0; a < disp->srec->dim; a++)
    {
      if (a + topline < disp->no_arr)

	{

	  draw_arr (disp, a + topline == disp->arr_line, a + topline);

#ifdef DEBUG
	  {	    debug ("after draw_arr (6)");	  }
#endif
	}
    }
  draw_arr (disp, 1, disp->arr_line);
#ifdef DEBUG
  {    debug ("after draw_arr (7)");  }
#endif
  mja_refresh ();
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
      debug ("Redisplay one");
      draw_arr (arr, 0, arr->last_arr);
#ifdef DEBUG
      {	debug ("after draw_arr (4)");      }
#endif
      debug ("Display one");
      draw_arr (arr, 1, arr->arr_line);
#ifdef DEBUG
      {	debug ("after draw_arr (5)");      }
#endif
    }
  if (redisp == 2)
    {
      debug ("Redisplay all");
      draw_arr_all (arr);
    }
  mja_wrefresh (currwin);
}

/**
 * Assigns the ype of the instruction that are using the array.
 * 
 * @param type The type of array usage :
 *   - I : Input.
 *   - D : Display.
 */
void 
set_array_mode(int type)
{
  cmode=type;
}

/**
 * The display array loop.
 *
 * Stay in loop until the user type a command that finishes the instruction 
 * (Accept, etc).
 *
 * @param arr A pointer to the display array information structure.
 */
static 
int disp_loop (struct s_disp_arr *arr)
{
  struct s_form_dets *form;
  int a;
  int redisp;
  FORM *mform;
  curr_arr = arr;
  form = arr->currform;
  m_lastkey = 0;
  set_array_mode('D');

#ifdef DEBUG
  {    debug ("Currform=%p (s_form_dets)", form);  }
#endif
  if (form != get_curr_form ())
    {
      exitwith ("Input form is not the current form!");
      exit (0);
    }
  mform = form->form;
#ifdef DEBUG
  {    debug ("FORM=%p", mform);  }
#endif
  if (arr->cntrl != 0)
    {
      a = arr->cntrl;
      arr->cntrl = 0;
    }
  else
    {
      draw_arr (arr, 2, arr->arr_line);
#ifdef DEBUG
      {	debug ("after draw_arr (3) mform=%p", mform);      }
      {	debug ("Searching for form");      }
      { find_ptr_debug (form);}
      {	debug ("Searching for mform");      }
      {	find_ptr_debug (mform);      }
      {	debug ("form_win(mform)=%p", form_win (mform));      }
#endif

      draw_arr (arr, -1, arr->arr_line);
      mja_wrefresh(currwin);
      a = getch_win ();
      m_lastkey = a;
    }
  redisp = 0;
  switch (a)
    {
    case KEY_DOWN:
      debug ("Key down");
      if (arr->arr_line < arr->no_arr)
	{

	  arr->cntrl = 0 - KEY_DOWN;

	  return -11;

	}
      break;

    case 0 - KEY_DOWN:
      debug ("Keydown +");
      arr->last_arr = arr->arr_line;
      arr->arr_line++;
      debug ("Is really down %d", arr->arr_line);
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
      set_arr_curr (arr->arr_line);
      set_scr_line (arr->scr_line);
      return -10;
      break;

    case KEY_UP:
      if (arr->arr_line > 1)

	{

	  arr->cntrl = 0 - KEY_UP;

	  return -11;

	}
      break;

    case 0 - KEY_UP:
      arr->last_arr = arr->arr_line;
      arr->arr_line--;
      debug ("Is really up");
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
      set_arr_curr (arr->arr_line);
      set_scr_line (arr->scr_line);
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
disp_arr(struct s_disp_arr *disp, void *ptr, char *srecname,int attrib,va_list *ap)
{
  int a;
  curr_arr = disp;
  debug ("In disp_arr : %s %p %p %d", srecname, ptr, disp, attrib);
  if (disp->srec == 0)
    {
      debug ("disparr1");
      disp->srec = get_srec (srecname);


      if (disp->srec == 0) {
	exitwith ("Screen record not found");
	return 0;
	}

      disp->currform = get_curr_form ();
#ifdef DEBUG
      {	debug ("disp->currform=%p", disp->currform);      }
#endif
      disp->last_arr = -1;
      disp->scr_line = 1;
      disp->arr_line = 1;
      disp->cntrl = 1;
      disp->highlight = 0;
      debug ("disparr2");
      if (disp->srec == 0)
	{
	  exitwith ("Screen record does not exist");

	  return 0;

	}
      debug ("disparr3");

      if (disp->srec->attribs.attribs_len  != disp->nbind)
	{
	  debug ("Too many or too few variables for fields %d %d %d",
		 disp->srec->dim, disp->nbind,disp->srec->attribs.attribs_len
	    );

	  return 0;

	}

      debug ("Clearing Record");
      clear_srec (disp->srec);
      debug ("Cleared record");
      for (a = 0; a < disp->srec->dim; a++)

	{

	  if (a < disp->no_arr)

	    {

#ifdef DEBUG
	      {		debug ("call draw_arr (1)");	      }
#endif
	      draw_arr (disp, a + 1 == disp->arr_line, a + 1);

#ifdef DEBUG
	      {		debug ("after draw_arr (1)");	      }
#endif
	    }

	}
#ifdef DEBUG
      {	debug ("call draw_arr (2)");      }
#endif
      draw_arr (disp, 1, disp->arr_line);
#ifdef DEBUG
      {	debug ("after draw_arr (2)");      }
#endif
      gui_scroll (disp->no_arr);
      set_arr_curr (disp->arr_line);
      set_scr_line (disp->scr_line);
      mja_wrefresh (currwin);

      return -10;
    }
  debug ("disparr4");
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
      exitwith ("set_scrline requires 1 parameter");
      return 0;
    }
  a = pop_int ();
  curr_arr->scr_line = a;
  set_scr_line (a);
  draw_arr_all (curr_arr);
#ifdef DEBUG
  {    debug ("Set scrline...%d", a);  }
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
      exitwith ("set_arrline requires 1 parameter");
      return 0;
    }
  a = pop_int ();
  curr_arr->arr_line = a;
  set_arr_curr (a);
  draw_arr_all (curr_arr);
#ifdef DEBUG
  {    debug ("Set arrline... %d", a);  }
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

/* =============================== EOF ============================ */


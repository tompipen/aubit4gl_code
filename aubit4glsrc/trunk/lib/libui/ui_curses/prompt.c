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
# $Id: prompt.c,v 1.60 2006-08-31 15:06:59 mikeaubury Exp $
#*/
#ifndef lint
	static char const module_id[] =
		"$Id: prompt.c,v 1.60 2006-08-31 15:06:59 mikeaubury Exp $";
#endif

/**
 * @file
 * Prompt implementation for Text User Interface
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

static int prompt_last_key=0;
//int A4GL_has_event(int a,struct aclfgl_event_list *evt) ;
//int A4GL_has_event_for_keypress(int a,struct aclfgl_event_list *evt) ;
//int A4GL_has_event_for_field(int cat,char *a,struct aclfgl_event_list *evt) ;
void A4GL_set_intr (void);

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

static int A4GL_proc_key_prompt (int a, FORM * mform, struct s_prompt *prompt);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/**
 *
 * @todo Describe function
 */
int
 UILIB_A4GL_start_prompt (void *vprompt, int ap, int c, int h, int af)
{
  char *promptstr;
  int promptline;
  struct s_prompt *prompt;
  char *beepchr;
  FIELD *sarr[3];
  WINDOW *p;
  WINDOW *d;
  WINDOW *cw;
  FORM *f;
  int width;
  char buff[300];
  int a;
  int field_cnt=0;
  A4GL_chkwin();
  prompt = vprompt;
  A4GL_debug ("In start prompt %p %d %d %d %d", prompt, ap, c, h, af);
  prompt_last_key=0;
  memset (buff, ' ', 255);
  promptline = A4GL_getprompt_line ();
  A4GL_debug ("promptline=%d", promptline);
  width = UILIB_A4GL_get_curr_width ();
  A4GL_debug ("create window %d %d", 1, promptline);
  A4GL_debug ("%d %d", width - 1, 2);
  cw = (WINDOW *) A4GL_get_currwin ();
  if (A4GL_iscurrborder()) promptline++;
  p = derwin (cw, 1, width, promptline-1  , UILIB_A4GL_iscurrborder ());

#ifdef __WIN32__
   wbkgd(p,'.');
   wbkgdset(p,'.');

   //wbkgd(p,'!');
   //wbkgdset(p,'!');
#endif
  if (p==0) {
		A4GL_exitwith("No prompt window created");
		return 0;
  }
  prompt->win = p;
  buff[width]=0;
  wprintw(p,"%s",buff);
  promptstr = A4GL_char_pop ();
  //
  // Some mad people put \007 in the prompt strings
  // to force a terminal beep....
  //
  while (1)  {
  	beepchr=strchr(promptstr,'\007');
	if (!beepchr) break;
	*beepchr=' ';
	A4GL_dobeep();
  }
  prompt->mode = -1;
  prompt->h = h;
  prompt->insmode=0;
  prompt->charmode = c;
  prompt->promptstr = promptstr;
  prompt->lastkey = 0;
  width -= strlen (promptstr);
  width--;

  if (strlen(promptstr)) {
	sarr[field_cnt++] = (FIELD *) A4GL_make_label (0, 0, promptstr);
  }
  if (width<=0) {
	  A4GL_exitwith("Prompt message is too long to fit in the window.");
	  return 0;
  }
  A4GL_debug ("Creating field %d %d %d", strlen (promptstr) + 1, 1, width - 1);
  set_new_page (sarr[field_cnt-1], 1);
  sarr[field_cnt++] = (FIELD *) A4GL_make_field (0, strlen (promptstr), 1, width + 1);
  prompt->field = sarr[field_cnt-1];
  sarr[field_cnt++] = 0;			/* (FIELD *) A4GL_make_label (0, strlen(promptstr)+width-1,"|"); */

  /* set_field_pad(sarr[1],' '); */
  A4GL_debug ("set field to =%p", prompt->field);
  A4GL_debug ("Field=%p", prompt->field);

  /* A4GL_default_attributes (sarr[0], 0); */

  A4GL_default_attributes (prompt->field, 0);
  local_field_opts_off (prompt->field, O_STATIC);

  A4GL_debug ("ap=%d(%x) af=%d(%x)", ap, ap, af, af);
  ap=A4GL_determine_attribute(FGL_CMD_DISPLAY_CMD , ap,0,0);
  af=A4GL_determine_attribute(FGL_CMD_INPUT, af,0,0);

  if (ap)
    {
	A4GL_debug("AP...");
      if (strlen(promptstr)) {
      		set_field_fore (sarr[0], A4GL_decode_aubit_attr (ap, 'f'));
      		set_field_back (sarr[0], A4GL_decode_aubit_attr (ap, 'b')); // maybe need 'B' for whole field..
	}
    }

  set_field_back (prompt->field, A4GL_colour_code (0));
  set_field_fore (prompt->field, A4GL_colour_code (0)|A_NORMAL);

  if (af)
    {
	A4GL_debug("AF...");
      set_field_back (prompt->field, A4GL_decode_aubit_attr (af, 'f'));
      set_field_fore (prompt->field, A4GL_decode_aubit_attr (af, 'b')); // maybe need 'B' for whole field..
      if (af&AUBIT_ATTR_INVISIBLE) {
          A4GL_debug ("Invisible");
          local_field_opts_off (prompt->field, O_PUBLIC);
          }

    }

  local_field_opts_on (prompt->field, O_NULLOK);
  A4GL_debug ("Set attributes");

  buff[0] = 0;			/* -2 */
  A4GL_debug ("Setting Buffer %p to '%s'", prompt->field, buff);
  set_field_buffer (prompt->field, 0, buff);
  A4GL_debug ("Set buffer ");

  A4GL_debug ("Made fields");
  A4GL_debug ("Field attr : %d", local_field_opts (prompt->field));

  A4GLSQL_set_status (0, 0);
  f = new_form (sarr);

  A4GL_debug ("Form f = %p", f);

  if (a4gl_status!=0 || f==0) {
	  A4GL_exitwith("Prompt message is too long to fit in the window.");
	  return 0;
  }

  prompt->f = f;

  A4GLSQL_set_status (0, 0);
  if (a4gl_status != 0)
    return (prompt->mode = 2);
  d = derwin (p, 0, 0, width + 1, 1);
#ifdef __WIN32__
   //wbkgd(d,'?');
   //wbkgdset(d,'?');
#endif
  set_form_win (f, p);
  set_form_sub (f, d);
  A4GL_debug ("Set form win");
  a = post_form (f);
  A4GL_debug ("Posted form=%d", a);



  A4GL_int_form_driver (f, REQ_FIRST_FIELD);
  A4GL_int_form_driver (f, REQ_OVL_MODE);
  A4GL_debug ("Initialized form");
  A4GLSQL_set_status (0, 0);

  A4GL_mja_refresh ();
  A4GL_zrefresh();
  return 1;
}


/**
 *
 * @todo Describe function
 */
int
A4GL_proc_key_prompt (int a, FORM * mform, struct s_prompt *prompt)
{
  FIELD *f;
  f = current_field (mform);


  A4GL_debug ("In proc_key_prompt.... for %d", a);
  switch (a)
    {
    case 18:
        clearok(curscr,1);
        A4GL_mja_refresh ();
      break;


    case -1:
	abort_pressed=1;
	return 0;

    case A4GLKEY_ESCAPE:
      return 0;

    case 26:
      return 0;

    case 127:
    case 8:
    case A4GLKEY_DC:
    case A4GLKEY_DL:
    case A4GLKEY_BACKSPACE:
      A4GL_debug ("Req del prev");
      if (A4GL_get_curr_field_col (mform))
	{
	  A4GL_int_form_driver (mform, REQ_DEL_PREV);
	  A4GL_debug ("Done...");
	}
      return 0;

    case 24:
      A4GL_int_form_driver (mform, REQ_DEL_CHAR);
      return 0;

    case '\t':
    case A4GLKEY_DOWN:
	if (prompt->charmode==0)
      		return 10;
	else
		return 0;


    //case A4GLKEY_ENTER:
    case 13:
    case 10:
#ifdef DEBUG
      A4GL_debug ("Next field in a prompt - they must mean enter");
#endif
      return 10;

    case A4GLKEY_LEFT:
      A4GL_int_form_driver (mform, REQ_PREV_CHAR);
      return 0;

    case A4GLKEY_RIGHT:
      A4GL_int_form_driver (mform, REQ_NEXT_CHAR);
      return 0;

    case 4:
      A4GL_int_form_driver (mform, REQ_CLR_FIELD);
      return 0;

    case 1:                     // Control - A
      prompt->insmode = prompt->insmode ? 0 : 1;
      if (prompt->insmode)
        A4GL_int_form_driver (mform,REQ_INS_MODE);
      else
        A4GL_int_form_driver (mform,REQ_OVL_MODE);
	return 0;

    }

  /* A4GL_mja_refresh (); */
  if (A4GL_is_special_key(a,A4GLKEY_HELP))
    {
      aclfgl_a4gl_show_help (prompt->h);
      a = 0;
    }

  A4GL_debug ("Returning %d from proc_key_prompt\n", a);
  return a;
}


/**
 *
 * @todo Describe function
 */
int
 UILIB_A4GL_prompt_loop_v2 (void *vprompt,int timeout,void *vevt)
{
  int a;
  WINDOW *p;
struct aclfgl_event_list *evt;
int was_aborted=0;
  FORM *mform;
  int blk;
  struct s_prompt *prompt;

  prompt = vprompt;
  evt=vevt;

  if (prompt->mode==-1) { // Initialize prompt...
  	//int a;
	A4GL_clr_evt_timeouts(evt);
	prompt->mode=0;
	return  0;
  }

  A4GL_chkwin ();
  mform = prompt->f;
  A4GL_set_abort (0);
  p = prompt->win;
#ifdef DEBUG
  {
    A4GL_debug ("In prompt loop mode = %d", prompt->mode);
  }
#endif




  if (prompt->mode == 1)
    {
      char buff[10024];
#ifdef DEBUG
      {
 A4GL_debug ("Mode=1 - prepare to quit field=%p", prompt->field);
      }
      {
 A4GL_debug ("Buffer='%s'", field_buffer (prompt->field, 0));
      }
#endif
      strcpy (buff, field_buffer (prompt->field, 0));
      A4GL_trim (buff);

      A4GL_push_char (buff);
      prompt->mode = 2;
      unpost_form (prompt->f);
      A4GL_debug("Calling clear_prmpt");
      A4GL_clear_prompt (prompt);
      return 0;
    }



  if (prompt->mode > 0) {
    	return 0;
  }

  A4GL_assertion(prompt->mode!=0,"prompt mode is not zero...");




  	pos_form_cursor (mform);
	abort_pressed=0;
	was_aborted=0;
        A4GL_debug("Timeout : %d\n",timeout);


	while (1) {
	  	blk=A4GL_has_evt_timeout(evt);
	  	if (blk) { return blk; }
  		a=A4GL_real_getch_swin (p);
		if (a!=0&&a!=-1) {
			A4GL_evt_not_idle(evt);
			break;
		}
		if (abort_pressed) break;
	}

        prompt->processed_onkey=a;
	A4GL_debug("Read character... %d",a);
  	if (a) {A4GL_clr_error_nobox("prompt");}
	if (abort_pressed ) a=A4GLKEY_INTERRUPT;
	prompt_last_key=a;
  	A4GL_set_last_key (a);
  	prompt->lastkey = A4GL_get_lastkey ();


	if (A4GL_has_event_for_keypress(a,evt)|| abort_pressed) {
      		A4GL_push_null (DTYPE_CHAR,1);
      		prompt->mode = 2;
      		unpost_form (prompt->f);
      		A4GL_debug("Calling clear_prmpt");
      		A4GL_clear_prompt (prompt);
		return A4GL_has_event_for_keypress(a,evt);
	}
	A4GL_debug("No lastkey..");


  a = A4GL_proc_key_prompt (a, mform, prompt);
  if (was_aborted) abort_pressed=1;



  if (abort_pressed) {


  }

  if (a == 0)
    {
#ifdef DEBUG
      {
 A4GL_debug ("a==0");
      }
#endif
      return 0;
    }
#ifdef DEBUG
  {
    A4GL_debug ("a==%d", a);
  }
#endif

  if (a < 0)
    return a;

  A4GL_debug ("Requested..");
  if (a == 10 || a == 13)
    {
	prompt_last_key=0;
      A4GL_int_form_driver (mform, REQ_VALIDATION);
	A4GL_zrefresh();
      wrefresh (p);
      A4GL_debug ("Return pressed");
      prompt->mode = 1;
      return 0;
    }

  A4GL_debug ("Requesting Validation : %p %x %d", mform, a, a);
  if (a_isprint (a) && a<0xff) {
    	A4GL_int_form_driver (mform, a);
  	A4GL_debug ("Called int_form_driver");
  	A4GL_int_form_driver (mform, REQ_VALIDATION);
  }



  wrefresh (p);
#ifdef DEBUG
  {
  A4GL_debug ("Refreshed screen");
    A4GL_debug (">>>Buffer='%s'", field_buffer (prompt->field, 0));
  }
#endif

  if (prompt->charmode)
    {
	if (a_isprint(a)&&a<0xff) {
      		A4GL_push_char (field_buffer (prompt->field, 0));
      		unpost_form (prompt->f);
      A4GL_debug("Calling clear_prmpt");
      		A4GL_clear_prompt (prompt);
      		prompt->mode=2;
	}
    }


  return -1000;
}



/**
 *
 * @todo Describe function
 */
static int
A4GL_curses_to_aubit_int (int a)
{
  int b;
  static int env_cancel=-2;
  if (env_cancel==-2) {
		char *ptr;
		ptr=acl_getenv("TUICANCELKEY");
		env_cancel=-1;
		if (ptr) {
			if (strlen(ptr)) {
				env_cancel=atoi(ptr);
			}
		} 
	A4GL_debug("cancel = %d\n",env_cancel);
   }
	

A4GL_debug("curses -> aubit a=%d %x\n",a,a);
  for (b = 0; b < 64; b++)
    {
      if (a == KEY_F (b))
	return A4GLKEY_F (b);
    }

  if (a == KEY_DOWN)
    return A4GLKEY_DOWN;
  if (a == KEY_UP)
    return A4GLKEY_UP;
  if (a == KEY_LEFT)
    return A4GLKEY_LEFT;
  if (a == KEY_RIGHT)
    return A4GLKEY_RIGHT;

  if (a == KEY_ENTER) return A4GLKEY_ENTER;
  if (a == 13) return A4GLKEY_ENTER;


  if (a==KEY_NPAGE) return A4GLKEY_PGDN;
  if (a==KEY_PPAGE) return A4GLKEY_PGUP;



  if (a == KEY_HOME) return A4GLKEY_HOME;
  if (a == KEY_END) return A4GLKEY_END;
  if (a == KEY_CANCEL || (a==env_cancel && env_cancel!=-1) ) {
		A4GL_set_intr();
		A4GL_debug("Got Cancel...");
		return A4GLKEY_CANCEL;
  }

  if (a == KEY_DC) return A4GLKEY_DC;
  if (a == KEY_DL) return A4GLKEY_DL;
  if (a == KEY_BACKSPACE) return A4GLKEY_BACKSPACE;

  return a;
}

/**
 *
 * @todo Describe function
 */
int A4GL_curses_to_aubit(int a) {
	int orig_a;
	orig_a=a;
	a=A4GL_curses_to_aubit_int(a);
	a=A4GL_key_map(a);
	if (a==-1&&orig_a!=a) {int_flag=1;} // A map to -1 is an interrupt...
	return a;
}


/* ============================== EOF ============================== */

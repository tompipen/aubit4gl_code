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
# $Id: prompt.c,v 1.7 2003-04-02 11:36:10 mikeaubury Exp $
#*/

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


#ifdef OLD_INCL

	#include "a4gl_aubit_lib.h"
	#include "a4gl_tui_tui.h"
	#include "a4gl_pointers.h"
	#include "a4gl_dbform.h"
	#include "a4gl_stack.h"
	#include "a4gl_runtime_tui.h" 		/* push_char() */
	#include "a4gl_debug.h"

#else

    #include "a4gl_lib_ui_tui_int.h"

#endif



/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

int curses_to_aubit(int a);

int start_prompt (struct s_prompt *prompt, int ap, int c, int h,int af);
int proc_key_prompt (int a, FORM * mform, struct s_prompt * prompt);
int prompt_loop (struct s_prompt * prompt);

int         chkwin                          (void);

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
start_prompt (struct s_prompt *prompt, int ap, int c, int h,int af)
{
char *promptstr;
int promptline;
FIELD *sarr[3];
WINDOW *p;
WINDOW *d;
WINDOW *cw;
FORM *f;
int width;
char buff[300];
int a;

  
  debug("In start prompt %p %d %d %d %d",prompt,ap,c,h,af);

  memset (buff, ' ', 255);
  promptline = getprompt_line ();
  debug("promptline=%d",promptline);
  width = get_curr_width ();
  debug("create window %d %d",1,promptline);
  debug("%d %d",width-1,2);
  cw=(WINDOW *)get_currwin();
  p = derwin(cw,1,width,promptline-1+iscurrborder()*2,iscurrborder());
  prompt->win = p;
  promptstr = char_pop ();
  prompt->mode = 0;
  prompt->h=h;
  prompt->charmode=c;
  prompt->promptstr = promptstr;
  prompt->lastkey = 0;
  width -= strlen (promptstr);
  width--;
  sarr[0] = (FIELD *) make_label (0, 0, promptstr);
  set_new_page(sarr[0],1);
  debug("Creating field %d %d %d", strlen (promptstr) + 1, 1, width - 1);
  sarr[1] = (FIELD *) make_field (0, strlen (promptstr) , 1, width+1);
  sarr[2] = 0; /* (FIELD *) make_label (0, strlen(promptstr)+width-1,"|"); */

  /* set_field_pad(sarr[1],' '); */
  prompt->field = sarr[1];
    debug ("set field to =%p", prompt->field);
    debug ("Field=%p", sarr[1]);

  /* default_attributes (sarr[0], 0); */

  default_attributes (sarr[1], 0);
	field_opts_off(sarr[1],O_STATIC);

  debug("ap=%d(%x) af=%d(%x)",ap,ap,af,af);

  if (ap) {
	      set_field_fore(sarr[0],decode_aubit_attr(ap,'f'));
	      set_field_back(sarr[0],decode_aubit_attr(ap,'b'));
	}
  if (af) {
	      set_field_back(sarr[1],decode_aubit_attr(af,'f'));
	      set_field_fore(sarr[1],decode_aubit_attr(af,'b'));
	}

  field_opts_on(sarr[1],O_NULLOK);
  debug("Set attributes");

  buff[0] = 0; /* -2*/
  debug("Setting Buffer %p to '%s'",sarr[1],buff);
  set_field_buffer (sarr[1], 0, buff);
  debug("Set buffer ");
  sarr[2] = 0;

  debug ("Made fields");
  debug("Field attr : %d",field_opts(sarr[1]));

  f = new_form (sarr);
    debug ("Form f = %p", f);
  prompt->f = f;
  A4GLSQL_set_status (0, 0);
  if (a4gl_status != 0)
    return (prompt->mode = 2);
  d = derwin (p, 0, 0, width+1, 1);
  set_form_win (f, p);
  set_form_sub (f, d);
    debug ("Set form win");
  a = post_form (f);
    debug ("Posted form=%d", a);
  int_form_driver (f, REQ_FIRST_FIELD);
  int_form_driver (f, REQ_INS_MODE);
  wrefresh(p);
    debug ("Initialized form");
/* zrefresh(); */
  A4GLSQL_set_status (0, 0);

  gui_startprompt ((long)prompt);
  gui_setfocus((long)sarr[1]);
  wrefresh(p);
  mja_refresh();

return 1;
}







/**
 *
 * @todo Describe function
 */
int
proc_key_prompt (int a, FORM * mform, struct s_prompt * prompt)
{
FIELD *f;

  f = current_field (mform);

  set_last_key(curses_to_aubit(a));

  debug ("In proc_key_prompt.... for %d", a);
  switch (a)
    {
    case 18:
      zrefresh ();
      break;
    case -1:

    case 27:
      return 0;

    case 26:
      return 0;

    case 127:
    case 8:
    case KEY_DC:
    case KEY_DL:
    case KEY_BACKSPACE:
      debug ("Req del prev");
      if (get_curr_field_col (mform))
        {
          int_form_driver (mform, REQ_DEL_PREV);
          debug ("Done...");
        }
      return 0;

    case 24:
      int_form_driver (mform, REQ_DEL_CHAR);
      return 0;

    case '\t':
    case KEY_ENTER:
    case 13:
    case 10:
    case KEY_DOWN:
#ifdef DEBUG
      {        debug ("Next field in a prompt - they must mean enter");      }
#endif
      return 10;

    case KEY_LEFT:
      int_form_driver (mform, REQ_PREV_CHAR);
      return 0;

    case KEY_RIGHT:
      int_form_driver (mform, REQ_NEXT_CHAR);
      return 0;

    case 4:
      int_form_driver (mform, REQ_CLR_FIELD);
      return 0;
    }

  /* mja_refresh (); */
  if (a == key_val ("HELP"))
    {
      show_help (prompt->h);
      a = 0;
    }

  debug ("Returning %d from proc_key_prompt\n", a);
  return a;
}


/**
 *
 * @todo Describe function
 */
int
prompt_loop (struct s_prompt * prompt)
{
  int a;
  WINDOW *p;
  FORM *mform;

chkwin();
  mform = prompt->f;
  p = prompt->win;
#ifdef DEBUG
  {    debug ("In prompt loop mode = %d", prompt->mode);  }
#endif
  if (prompt->mode == 1)
    {
	char buff[1024];
#ifdef DEBUG
      {	debug ("Mode=1 - prepare to quit field=%p", prompt->field);      }
      {	debug ("Buffer='%s'", field_buffer (prompt->field, 0));      }
#endif
	strcpy(buff,field_buffer(prompt->field,0));
	trim(buff);

      push_char (buff);
      prompt->mode = 2;
      gui_endprompt ((long)prompt); /* void    gui_endprompt		(long ld); */
      unpost_form (prompt->f);
      clear_prompt (prompt);
      return 0;
    }
  if (prompt->mode > 0)
    return 0;

  pos_form_cursor (mform);
  a = getch_win();


  a = proc_key_prompt (a, mform,prompt);
  prompt->lastkey = get_lastkey ();

  if (a == 0)
    {
#ifdef DEBUG
      {	debug ("a==0");      }
#endif
      return 0;
    }
#ifdef DEBUG
  {    debug ("a==%d", a);  }
#endif

  if (a < 0)
    return a;

  debug("Requested..");
  if (prompt->lastkey == 10 || prompt->lastkey == 13)
      {
  int_form_driver (mform, REQ_VALIDATION);
  wrefresh(p);
	debug ("Return pressed");
	prompt->mode = 1;
	return 0;
      }

  debug ("Requesting Validation : %p %x %d",mform,a,a);
  if (isprint(a)) int_form_driver (mform, a);
  debug("Called int_form_driver");
  int_form_driver (mform, REQ_VALIDATION);
  debug("Called formdriver(validation)");
  wrefresh(p);
  debug("Refreshed screen");
#ifdef DEBUG
  {    debug (">>>Buffer='%s'", field_buffer (prompt->field, 0));  }
#endif
      if (prompt->charmode) {
	push_char (field_buffer (prompt->field, 0));
	}
  return -90;
}


/**
 *
 * @todo Describe function
 */
/*
static void
decode_field_attr(FIELD *f,int af)
{

   //set_field_fore(f,af);
   //set_field_back(f,colour_code(0));

}
*/



/**
 *
 * @todo Describe function
 */
int
curses_to_aubit(int a)
{
	int b;
	for (b=0;b<64;b++) {
		if (a==KEY_F(b)) return A4GLKEY_F(b);
	}

	if (a==KEY_DOWN) return A4GLKEY_DOWN;
	if (a==KEY_UP) return A4GLKEY_UP;
	if (a==KEY_LEFT) return A4GLKEY_LEFT;
	if (a==KEY_RIGHT) return A4GLKEY_RIGHT;
	if (a==KEY_ENTER) return A4GLKEY_ENTER;
	//if (a==KEY_PGDN) return A4GLKEY_PGDN;
	//if (a==KEY_PGUP) return A4GLKEY_PGUP;
	//if (a==KEY_INS) return A4GLKEY_INS;
	//if (a==KEY_DEL) return A4GLKEY_DEL;
	if (a==KEY_HOME) return A4GLKEY_HOME;
	if (a==KEY_END) return A4GLKEY_END;
	if (a==KEY_CANCEL) return A4GLKEY_CANCEL;

	return a;
}


/* ============================== EOF ============================== */


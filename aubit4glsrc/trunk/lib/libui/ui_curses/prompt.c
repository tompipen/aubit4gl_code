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
# $Id: prompt.c,v 1.11 2003-05-15 07:10:46 mikeaubury Exp $
#*/

/**
 * @file
 * Prompt implementation for Text User Interface
 *
 * @todo Add Doxygen A4GL_comments to file
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen A4GL_comments to add to functions
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

int A4GL_curses_to_aubit (int a);
int A4GL_proc_key_prompt (int a, FORM * mform, struct s_prompt *prompt);
int A4GL_chkwin (void);

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
A4GL_start_prompt (void *vprompt, int ap, int c, int h, int af)
{
  char *promptstr;
  int promptline;
  struct s_prompt *prompt;
  FIELD *sarr[3];
  WINDOW *p;
  WINDOW *d;
  WINDOW *cw;
  FORM *f;
  int width;
  char buff[300];
  int a;

  prompt = vprompt;
  A4GL_debug ("In start prompt %p %d %d %d %d", prompt, ap, c, h, af);

  memset (buff, ' ', 255);
  promptline = A4GL_getprompt_line ();
  A4GL_debug ("promptline=%d", promptline);
  width = A4GL_get_curr_width ();
  A4GL_debug ("create window %d %d", 1, promptline);
  A4GL_debug ("%d %d", width - 1, 2);
  cw = (WINDOW *) A4GL_get_currwin ();
  p =
    derwin (cw, 1, width, promptline - 1 + A4GL_iscurrborder () * 2,
	    A4GL_iscurrborder ());
  prompt->win = p;
  promptstr = A4GL_char_pop ();
  prompt->mode = 0;
  prompt->h = h;
  prompt->charmode = c;
  prompt->promptstr = promptstr;
  prompt->lastkey = 0;
  width -= strlen (promptstr);
  width--;
  sarr[0] = (FIELD *) A4GL_make_label (0, 0, promptstr);
  set_new_page (sarr[0], 1);
  A4GL_debug ("Creating field %d %d %d", strlen (promptstr) + 1, 1, width - 1);
  sarr[1] = (FIELD *) A4GL_make_field (0, strlen (promptstr), 1, width + 1);
  sarr[2] = 0;			/* (FIELD *) A4GL_make_label (0, strlen(promptstr)+width-1,"|"); */

  /* set_field_pad(sarr[1],' '); */
  prompt->field = sarr[1];
  A4GL_debug ("set field to =%p", prompt->field);
  A4GL_debug ("Field=%p", sarr[1]);

  /* A4GL_default_attributes (sarr[0], 0); */

  A4GL_default_attributes (sarr[1], 0);
  field_opts_off (sarr[1], O_STATIC);

  A4GL_debug ("ap=%d(%x) af=%d(%x)", ap, ap, af, af);

  if (ap)
    {
      set_field_fore (sarr[0], A4GL_decode_aubit_attr (ap, 'f'));
      set_field_back (sarr[0], A4GL_decode_aubit_attr (ap, 'b'));
    }
  if (af)
    {
      set_field_back (sarr[1], A4GL_decode_aubit_attr (af, 'f'));
      set_field_fore (sarr[1], A4GL_decode_aubit_attr (af, 'b'));
    }

  field_opts_on (sarr[1], O_NULLOK);
  A4GL_debug ("Set attributes");

  buff[0] = 0;			/* -2 */
  A4GL_debug ("Setting Buffer %p to '%s'", sarr[1], buff);
  set_field_buffer (sarr[1], 0, buff);
  A4GL_debug ("Set buffer ");
  sarr[2] = 0;

  A4GL_debug ("Made fields");
  A4GL_debug ("Field attr : %d", field_opts (sarr[1]));

  f = new_form (sarr);
  A4GL_debug ("Form f = %p", f);
  prompt->f = f;
  A4GLSQL_set_status (0, 0);
  if (a4gl_status != 0)
    return (prompt->mode = 2);
  d = derwin (p, 0, 0, width + 1, 1);
  set_form_win (f, p);
  set_form_sub (f, d);
  A4GL_debug ("Set form win");
  a = post_form (f);
  A4GL_debug ("Posted form=%d", a);
  A4GL_int_form_driver (f, REQ_FIRST_FIELD);
  A4GL_int_form_driver (f, REQ_INS_MODE);
  wrefresh (p);
  A4GL_debug ("Initialized form");
/* zrefresh(); */
  A4GLSQL_set_status (0, 0);

  A4GL_gui_startprompt ((long) prompt);
  A4GL_gui_setfocus ((long) sarr[1]);
  wrefresh (p);
  A4GL_mja_refresh ();

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

  A4GL_set_last_key (A4GL_curses_to_aubit (a));

  A4GL_debug ("In proc_key_prompt.... for %d", a);
  switch (a)
    {
    case 18:
      A4GL_zrefresh ();
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
    case KEY_ENTER:
    case 13:
    case 10:
    case KEY_DOWN:
#ifdef DEBUG
      A4GL_debug ("Next field in a prompt - they must mean enter");
#endif
      return 10;

    case KEY_LEFT:
      A4GL_int_form_driver (mform, REQ_PREV_CHAR);
      return 0;

    case KEY_RIGHT:
      A4GL_int_form_driver (mform, REQ_NEXT_CHAR);
      return 0;

    case 4:
      A4GL_int_form_driver (mform, REQ_CLR_FIELD);
      return 0;
    }

  /* A4GL_mja_refresh (); */
  if (a == A4GL_key_val ("HELP"))
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
A4GL_prompt_loop (void *vprompt)
{
  int a;
  WINDOW *p;
  FORM *mform;
  struct s_prompt *prompt;
  prompt = vprompt;

  A4GL_chkwin ();
  mform = prompt->f;
  p = prompt->win;
#ifdef DEBUG
  {
    A4GL_debug ("In prompt loop mode = %d", prompt->mode);
  }
#endif
  if (prompt->mode == 1)
    {
      char buff[1024];
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
      A4GL_gui_endprompt ((long) prompt);	/* void    A4GL_gui_endprompt            (long ld); */
      unpost_form (prompt->f);
      A4GL_clear_prompt (prompt);
      return 0;
    }
  if (prompt->mode > 0)
    return 0;

  pos_form_cursor (mform);
  a = A4GL_getch_win ();


  a = A4GL_proc_key_prompt (a, mform, prompt);
  prompt->lastkey = A4GL_get_lastkey ();

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
  if (prompt->lastkey == 10 || prompt->lastkey == 13)
    {
      A4GL_int_form_driver (mform, REQ_VALIDATION);
      wrefresh (p);
      A4GL_debug ("Return pressed");
      prompt->mode = 1;
      return 0;
    }

  A4GL_debug ("Requesting Validation : %p %x %d", mform, a, a);
  if (isprint (a))
    A4GL_int_form_driver (mform, a);
  A4GL_debug ("Called int_form_driver");
  A4GL_int_form_driver (mform, REQ_VALIDATION);
  A4GL_debug ("Called formdriver(validation)");
  wrefresh (p);
  A4GL_debug ("Refreshed screen");
#ifdef DEBUG
  {
    A4GL_debug (">>>Buffer='%s'", field_buffer (prompt->field, 0));
  }
#endif
  if (prompt->charmode)
    {
      A4GL_push_char (field_buffer (prompt->field, 0));
    }
  return -90;
}

/**
 *
 * @todo Describe function
 */
int
A4GL_curses_to_aubit (int a)
{
  int b;
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
  if (a == KEY_ENTER)
    return A4GLKEY_ENTER;
  //if (a==KEY_PGDN) return A4GLKEY_PGDN;
  //if (a==KEY_PGUP) return A4GLKEY_PGUP;
  //if (a==KEY_INS) return A4GLKEY_INS;
  //if (a==KEY_DEL) return A4GLKEY_DEL;
  if (a == KEY_HOME)
    return A4GLKEY_HOME;
  if (a == KEY_END)
    return A4GLKEY_END;
  if (a == KEY_CANCEL)
    return A4GLKEY_CANCEL;

  return a;
}


/* ============================== EOF ============================== */

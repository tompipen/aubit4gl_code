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
# $Id: keys.c,v 1.50 2015-01-27 10:19:47 mikeaubury Exp $
#
*/

/**
 * @file
 *
 * @todo Add Doxygen comments to file
 */

/*
=====================================================================
                    Constants definitions
=====================================================================
*/

#define OBJECTMODULE
#define mja_strcmp(a,b) A4GL_mja_strncmp(a,b,0)

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_libaubit4gl_int.h"
#include <ctype.h>

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

int A4GL_key_val2 (char *str);
//void A4GL_set_option_value (char type, int keyval);
void A4GL_init_stddbscr (void);
/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * Checks whether the key stroke (str1) matches any of the keys (double
 * pipe delimited) in str2
 *
 * @todo Describe function
 */
int
A4GL_check_keys (int val, char *str2)
{
  char *ptr;
  int a;
  int l;

#ifdef DEBUG
  A4GL_debug ("check_keys : %d %s", val, str2);
#endif
  ptr = str2;
  l = strlen (str2);
  for (a = 0; a < l; a++)
    {
      if (a < l - 1)
	{
	  if (str2[a] == '|' && str2[a + 1] == '|')
	    {
	      if (A4GL_check_key (val, ptr, (int) (&str2[a] - ptr)))
		return 1;
	      ptr = &str2[a + 2];
	      a++;
	    }
	}
    }
  if (A4GL_check_key (val, ptr, (int) (&str2[a] - ptr)))
    return 1;
  return 0;
}

/**
 *
 * @todo Describe function
 */
int
A4GL_check_key (int val, char *a, int ln)
{
  char buff[20];

  strncpy (buff, a, ln);
  buff[ln] = 0;
#ifdef DEBUG
  A4GL_debug ("Checking key %d against %s  ln=%d", val, a, ln);
#endif
  if (ln == 1)
    {
      if (tolower (buff[0]) == tolower (val))
	return 1;
      if (toupper (buff[0]) == tolower (val))
	return 1;
    }
  else if (A4GL_key_val (buff) == val)
    return 1;
  return 0;
}

/**
 *
 * @todo Describe function
 */
int
A4GL_key_val (char *str)
{
  int a;
  a = A4GL_key_val2 (str);
#ifdef DEBUG
  A4GL_debug (" key_val : '%s' = %d", str, a);
#endif
  return a;
}


/* std_dbscr holds the current options for certain keys...

   This routine checks to see of a particular key matches
   a particular operation

    Keys which can be reprogrammed : 
    	int nextkey;
    	int prevkey;
    	int inskey;
    	int delkey;
    	int helpkey;
    	int acckey;

	@param  k  Key to check
	@param  type key type to check against A4GLKEY_...

*/
int
A4GL_is_special_key (int k, int type)
{
  A4GL_init_stddbscr ();

  if (k == type)
    return 1;
  switch (type)
    {
    case A4GLKEY_NEXT:
      return (std_dbscr.nextkey == k);
    case A4GLKEY_NEXTPAGE:
      return (std_dbscr.nextkey == k);
    case A4GLKEY_PREV:
      return (std_dbscr.prevkey == k);
    case A4GLKEY_PREVPAGE:
      return (std_dbscr.prevkey == k);
    case A4GLKEY_INSERT:
      return (std_dbscr.inskey == k);
    case A4GLKEY_DELETE:
      return (std_dbscr.delkey == k);
    case A4GLKEY_HELP:
#ifdef DEBUG
      A4GL_debug ("Help key : %d\n", std_dbscr.helpkey);
#endif
      return (std_dbscr.helpkey == k);
    case A4GLKEY_ACCEPT:
      return (std_dbscr.acckey == k);
    }
#ifdef DEBUG
  A4GL_debug ("HELP=%d\n", A4GLKEY_HELP);
  A4GL_debug ("Unexpected internal key : hex=%x decimal=%d\n", type, type);
#endif

  PRINTF ("%x\n", type);
  A4GL_exitwith ("Internal error-unexpected keytype for A4GL_is_special_key");
  return 0;
}






/**
 *
 * @todo Describe function
 */
int
A4GL_key_val2 (char *str_x)
{
  int a;
  int rval;
  char b[3];
  char str[256];
  strcpy (str, str_x);
  A4GL_trim (str);
  A4GL_init_stddbscr ();

#ifdef DEBUG
  A4GL_debug ("In A4GL_key_val str=%s", str);
#endif

  if (strlen (str) == 1)
    {
      return str[0];
    }				/*single character */

  if (mja_strcmp ("ACCEPT", str) == 0)
    return A4GLKEY_ACCEPT;
  //return std_dbscr.acckey;

  if (mja_strcmp ("DELETE", str) == 0)
    return A4GLKEY_DELETE;
  //return std_dbscr.delkey;

  if (mja_strcmp ("INSERT", str) == 0)
    return A4GLKEY_INSERT;
  //return std_dbscr.inskey;

  if (mja_strcmp ("HELP", str) == 0)
    return A4GLKEY_HELP;
  //return std_dbscr.helpkey;

  if (A4GL_isyes (acl_getenv ("USEPAGEKEYS")))
    {
      if (mja_strcmp ("NEXT", str) == 0)
	return A4GLKEY_PGDN;
      if (mja_strcmp ("NEXTPAGE", str) == 0)
	return A4GLKEY_PGDN;
      if (mja_strcmp ("PREV", str) == 0)
	return A4GLKEY_PGUP;
      if (mja_strcmp ("PREVIOUS", str) == 0)
	return A4GLKEY_PGUP;
      if (mja_strcmp ("PREVPAGE", str) == 0)
	return A4GLKEY_PGUP;
    }
  else
    {
      if (mja_strcmp ("NEXT", str) == 0)
	return std_dbscr.nextkey;
      if (mja_strcmp ("NEXTPAGE", str) == 0)
	return std_dbscr.nextkey;
      if (mja_strcmp ("PREV", str) == 0)
	return std_dbscr.prevkey;
      if (mja_strcmp ("PREVIOUS", str) == 0)
	return std_dbscr.prevkey;
      if (mja_strcmp ("PREVPAGE", str) == 0)
	return std_dbscr.prevkey;
    }


  if (mja_strcmp ("INTERRUPT", str) == 0)
    return A4GLKEY_INTERRUPT;
  if (mja_strcmp ("RETURN", str) == 0)
    return A4GLKEY_ENTER;
  if (mja_strcmp ("ENTER", str) == 0)
    return A4GLKEY_ENTER;
  if (mja_strcmp ("TAB", str) == 0)
    return '	';

  if (mja_strcmp ("SHTAB", str) == 0)
    return A4GLKEY_SHTAB;

  if (mja_strcmp ("DOWN", str) == 0)
    return A4GLKEY_DOWN;
  if (mja_strcmp ("UP", str) == 0)
    return A4GLKEY_UP;
  if (mja_strcmp ("LEFT", str) == 0)
    return A4GLKEY_LEFT;
  if (mja_strcmp ("RIGHT", str) == 0)
    return A4GLKEY_RIGHT;



  if (mja_strcmp ("ESCAPE", str) == 0)
    return A4GLKEY_ESCAPE;
  if (mja_strcmp ("ESC", str) == 0)
    return A4GLKEY_ESCAPE;
  if (mja_strcmp ("SPACE", str) == 0)
    return 32;



  if (A4GL_isyes (acl_getenv ("PGKEYSMOVE")))
    {
      if (mja_strcmp ("PGDN", str) == 0)
	{
	  return A4GLKEY_PGDN;
	}
      if (mja_strcmp ("PGUP", str) == 0)
	{
	  return A4GLKEY_PGUP;
	}
    }
  else
    {
      if (mja_strcmp ("PGDN", str) == 0)
	{
	  return std_dbscr.nextkey;
	}
      if (mja_strcmp ("PGUP", str) == 0)
	{
	  return std_dbscr.prevkey;;
	}
    }



  if (mja_strcmp ("BACKSPACE", str) == 0)
    {
      return A4GLKEY_BACKSPACE;
    }
  if (mja_strcmp ("CANCEL", str) == 0)
    {
      return A4GLKEY_CANCEL;
    }
  if (mja_strcmp ("HOME", str) == 0)
    {
      return A4GLKEY_HOME;
    }
  if (mja_strcmp ("END", str) == 0)
    {
      return A4GLKEY_END;
    }



  if (A4GL_mja_strncmp ("CONTROL", str, 7) == 0)
    {
#ifdef DEBUG
      A4GL_debug ("control key '%s' - returning '%c'\n", str, str[8]);
#endif
      if (toupper (str[8]) >= 'A' && toupper (str[8]) <= 'Z')
	{
	  rval = a4gl_toupper (str[8]) - 'A' + 1;
#ifdef DEBUG
	  A4GL_debug ("rval1=%d\n", rval);
#endif
	  return rval;
	}
      if (toupper (str[9]) >= 'A' && toupper (str[9]) <= 'Z')
	{
	  rval = a4gl_toupper (str[9]) - 'A' + 1;
#ifdef DEBUG
	  A4GL_debug ("rval2=%d\n", rval);
#endif
	  return rval;
	}
      if (toupper (str[10]) >= 'A' && toupper (str[10]) <= 'Z')
	{
	  rval = a4gl_toupper (str[10]) - 'A' + 1;
#ifdef DEBUG
	  A4GL_debug ("rval3=%d\n", rval);
#endif
	  return rval;
	}
    }




  if (str[0] == '^')
    {
      return toupper (str[1]) - 'A' + 1;
    }




  if (toupper (str[0]) == 'F')
    {
      b[0] = str[1];
      b[1] = str[2];
      b[2] = 0;
#ifdef DEBUG
      A4GL_debug ("Function key..");
#endif
      a = atoi (b);
      a = A4GLKEY_F (a);
#ifdef DEBUG
      A4GL_debug ("F%s = %d", b, a);
#endif
      return a;
    }


  return -1;
}

/**
 *
 * @todo Describe function
 */
void
A4GL_set_option_value (char type, long keyval)
{
  A4GL_init_stddbscr ();
  switch (type)
    {
    case 'C':
      std_dbscr.comment_line = keyval;
      break;
    case 'E':
      std_dbscr.error_line = keyval;
      break;
    case 'F':
      std_dbscr.form_line = keyval;
      break;
    case 'M':
      std_dbscr.menu_line = keyval;
      break;
    case 'm':
      std_dbscr.message_line = keyval;
      break;
    case 'P':
      std_dbscr.prompt_line = keyval;
      break;
    case 'A':
      std_dbscr.acckey = keyval;
      break;
    case 'D':
      std_dbscr.delkey = keyval;
      break;
    case 'I':
      std_dbscr.inskey = keyval;
      break;
    case 'N':
      std_dbscr.nextkey = keyval;
      break;
    case 'p':
      std_dbscr.prevkey = keyval;
      break;
    case 'H':
      std_dbscr.helpkey = keyval;
      break;
    case 'd':
      std_dbscr.dispattr = keyval;
      break;


    case 'c':
      std_dbscr.current_field_attribute = keyval;
      break;

    case 'R':
      std_dbscr.current_row_attribute = keyval;
      break;

    case 'i':
      std_dbscr.inpattr = keyval;
      break;
    case 'W':
      std_dbscr.input_wrapmode = keyval;
      break;
    case 'f':
      std_dbscr.fieldconstr = keyval;
      break;
    case 'S':
      std_dbscr.sqlintr = keyval;
      break;
    case 'r':
      std_dbscr.run_ui_mode = keyval;
      break;
    case '|':
      std_dbscr.pipe_ui_mode = keyval;
      break;
    }
  A4GL_set_option_value_for_current_window (type, keyval);
}

int
A4GL_get_option_value (char type)
{
  A4GL_init_stddbscr ();
#ifdef DEBUG
  A4GL_debug ("Get option value : %c", type);
#endif
  switch (type)
    {
    case 'C':
      return std_dbscr.comment_line;
      break;
    case 'E':
      return std_dbscr.error_line;
      break;
    case 'F':
      return std_dbscr.form_line;
      break;
    case 'M':
      return std_dbscr.menu_line;
      break;
    case 'm':
      return std_dbscr.message_line;
      break;
    case 'P':
      return std_dbscr.prompt_line;
      break;
    case 'A':
      return std_dbscr.acckey;
      break;
    case 'D':
      return std_dbscr.delkey;
      break;
    case 'I':
      return std_dbscr.inskey;
      break;
    case 'N':
      return std_dbscr.nextkey;
      break;
    case 'p':
      return std_dbscr.prevkey;
      break;
    case 'c':
      return std_dbscr.current_field_attribute ;
      break;

    case 'R':
      return std_dbscr.current_row_attribute;
      break;

    case 'H':
      return std_dbscr.helpkey;
      break;
    case 'd':
      return std_dbscr.dispattr;
      break;
    case 'i':
      return std_dbscr.inpattr;
      break;
    case 'W':
      return std_dbscr.input_wrapmode;
      break;
    case 'f':
      return std_dbscr.fieldconstr;
      break;
    case 'S':
      return std_dbscr.sqlintr;
      break;
    case 'r':
      return std_dbscr.run_ui_mode;
      break;
    case '|':
      return std_dbscr.pipe_ui_mode;
      break;
    }
  A4GL_assertion (1, "Unknown option value");
  return 0;
}


void
A4GL_init_stddbscr (void)
{
  static int inited = 0;
  if (inited)
    return;
  inited = 1;
#ifdef DEBUG
  A4GL_debug ("init_stddbscr - form_line");
#endif
  std_dbscr.mode = 0;
  std_dbscr.colour = 0;
  std_dbscr.border = 0;
  std_dbscr.inpattr = 0;
  std_dbscr.dispattr = 0;
  std_dbscr.nextkey = A4GLKEY_F (3);
  std_dbscr.prevkey = A4GLKEY_F (4);
  std_dbscr.acckey = 27;
  std_dbscr.helpkey = 23;
  std_dbscr.input_wrapmode = 0;
  std_dbscr.current_field_attribute = 0;
  std_dbscr.comment_line = 0xff;
  std_dbscr.form_line = 3;
  std_dbscr.menu_line = 1;
  std_dbscr.message_line = 2;
  std_dbscr.prompt_line = 1;
  std_dbscr.fcnt = 0;
  std_dbscr.insmode = 0;
  std_dbscr.error_line = -1;
  std_dbscr.inskey = A4GLKEY_F (1);
  std_dbscr.delkey = A4GLKEY_F (2);
  std_dbscr.pipe_ui_mode = 0;
  std_dbscr.run_ui_mode = 0;
}


int
A4GL_get_dbscr_commentline (void)
{
  return std_dbscr.comment_line;
}

int
A4GL_get_dbscr_formline (void)
{
  return std_dbscr.form_line;
}

int
A4GL_get_dbscr_errorline (void)
{
  return std_dbscr.error_line;
}

int
A4GL_get_dbscr_promptline (void)
{
  return std_dbscr.prompt_line;
}

int
A4GL_get_dbscr_messageline (void)
{
  return std_dbscr.message_line;
}

int
A4GL_get_dbscr_menuline (void)
{
  return std_dbscr.menu_line;
}

int
A4GL_get_dbscr_inputmode (void)
{
  return std_dbscr.input_wrapmode;
}


/* ============================== EOF ============================= */

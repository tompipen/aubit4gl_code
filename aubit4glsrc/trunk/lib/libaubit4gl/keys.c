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
# $Id: keys.c,v 1.8 2002-06-25 03:22:30 afalout Exp $
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
#define mja_strcmp(a,b) mja_strncmp(a,b,0)

/*
=====================================================================
		                    Includes
=====================================================================
*/


#ifdef OLD_INCL

	#include "a4gl_dbform.h"
	#include "a4gl_debug.h"
	#include "a4gl_pointers.h"
	#include "a4gl_keys.h"
	#include "a4gl_aubit_lib.h"

#else

    #include "a4gl_libaubit4gl_int.h"

#endif

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

int 	key_val2 			(char *str);
void    set_option_value	(char type,int keyval);

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
check_keys (int val, char *str2)
{
  char *ptr;
  int a;
  ptr = str2;
  for (a = 0; a < strlen (str2); a++)
    {
      if (a < strlen (str2) - 1)
        {
          if (str2[a] == '|' && str2[a + 1] == '|')
            {
              if (check_key (val, ptr, (int) (&str2[a] - ptr)))
                return 1;
              ptr = &str2[a + 2];
              a++;
            }
        }
    }
  if (check_key (val, ptr, (int) (&str2[a] - ptr)))
    return 1;
  return 0;
}

/**
 *
 * @todo Describe function
 */
int
check_key (int val, char *a, int ln)
{
  char buff[20];
  strncpy (buff, a, ln);
  buff[ln] = 0;
debug("Checking key %d against %s  ln=%d",val,a,ln);
  if (ln == 1)
    {
      if (tolower (buff[0]) == tolower (val))
        return 1;
      if (toupper (buff[0]) == tolower (val))
        return 1;
    }
  else if (key_val (buff) == val)
    return 1;
  return 0;
}

/**
 *
 * @todo Describe function
 */
int
key_val(char *str)
{
int a;
	a=key_val2(str);
	debug("key_val : '%s' = %d",str,a);
	return a;
}

/**
 *
 * @todo Describe function
 */
int
key_val2 (char *str)
{
  int a;
  char b[3];
  debug("In key_val str=%s",str);

  if (strlen (str) == 1)
    {
      return str[0];
    }                           /*single character */

  if (mja_strcmp ("ACCEPT", str) == 0) return std_dbscr.acckey;
  if (mja_strcmp ("DELETE", str) == 0) return std_dbscr.delkey;
  if (mja_strcmp ("INSERT", str) == 0) return std_dbscr.inskey;
  if (mja_strcmp ("HELP", str) == 0) return std_dbscr.helpkey;
  if (mja_strcmp ("NEXT", str) == 0) return std_dbscr.nextkey;
  if (mja_strcmp ("NEXTPAGE", str) == 0) return std_dbscr.nextkey;
  if (mja_strcmp ("PREV", str) == 0) return std_dbscr.prevkey;
  if (mja_strcmp ("PREVPAGE", str) == 0) return std_dbscr.prevkey;
  if (mja_strcmp ("ACCEPT", str) == 0) return std_dbscr.acckey;

  if (mja_strcmp ("INTERRUPT", str) == 0) return -100;
  if (mja_strcmp ("RETURN", str) == 0) return    A4GLKEY_ENTER;
  if (mja_strcmp ("ENTER", str) == 0) return     A4GLKEY_ENTER;
  if (mja_strcmp ("TAB", str) == 0) return '	';
  if (mja_strcmp ("DOWN", str) == 0) return      A4GLKEY_DOWN;
  if (mja_strcmp ("UP", str) == 0) return 	A4GLKEY_UP;
  if (mja_strcmp ("LEFT", str) == 0) return 	A4GLKEY_LEFT;
  if (mja_strcmp ("RIGHT", str) == 0) return 	A4GLKEY_RIGHT;
  if (mja_strcmp ("ESCAPE", str) == 0) return 27;

  if (mja_strncmp ("CONTROL", str, 7) == 0)
    {
        debug("control key '%s' - returning '%c'\n",str,str[10]);
      return toupper(str[10]) - 'A' + 1;
    }

  if (str[0] == '^')
    {
      return toupper(str[1]) - 'A' + 1;
    }

  if (toupper (str[0]) == 'F')
    {
      b[0] = str[1];
      b[1] = str[2];
      b[2] = 0;
	debug("Function key..");
      a = atoi (b);
      a=A4GLKEY_F (a);
	debug("F%s = %d",b,a);
	return a;
    }
  return -1;
}


/**
 *
 * @todo Describe function
 */
void
set_option_value(char type,int keyval)
{
	debug("Set option value : %c %d",type,keyval);
	switch (type) 
	{
		case  'C': std_dbscr.comment_line=keyval;break;
		case  'E': std_dbscr.error_line=keyval;break;
		case  'F': std_dbscr.form_line=keyval;break;
		case  'M': std_dbscr.menu_line=keyval;break;
		case  'm': std_dbscr.message_line=keyval;break;
		case  'P': std_dbscr.prompt_line=keyval;break;
		case  'A': std_dbscr.acckey=keyval;break;
		case  'D': std_dbscr.delkey=keyval;break;
		case  'I': std_dbscr.inskey=keyval;break;
		case  'N': std_dbscr.nextkey=keyval;break;
		case  'p': std_dbscr.prevkey=keyval;break;
		case  'H': std_dbscr.helpkey=keyval;break;
		case  'd': std_dbscr.dispattr=keyval;break;
		case  'i': std_dbscr.inpattr=keyval;break;
		case  'W': std_dbscr.input_wrapmode=keyval;break;
		case  'f': std_dbscr.fieldconstr=keyval;break;
		case  'S': std_dbscr.sqlintr=keyval;break;
	}
}

/* ============================== EOF ============================= */


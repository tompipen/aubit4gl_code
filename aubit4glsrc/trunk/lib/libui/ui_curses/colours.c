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
# $Id: colours.c,v 1.4 2003-05-12 14:24:26 mikeaubury Exp $
#*/

/**
 * @file
 * Gets the color code.
 *
 * @todo : Understand if this function / module is used.
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#ifdef OLD_INCL

#include "a4gl_dbform.h"
#include "a4gl_tui_tui.h"
#include "a4gl_aubitcolours.h"
#include "a4gl_debug.h"

#else

#include "a4gl_lib_ui_tui_int.h"

#endif

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

#ifdef OLD_INCL
int get_strings_from_attr (int attr, char *col_str, char *attr_str);
#endif

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * Return the color code used.
 *
 * @param  The integer color code.
 */
int
colour_code (int a)
{
  int z, b;
  z = 1;

  if (!has_colors ())
    {
      z = A_STANDOUT;
      for (b = 0; b <= a; b++)
	{
	  z *= 2;
	}
      return z;
    }
  debug ("Returning color code (%d+1)\n", a);
  if (a == 0)
    return 0;
  return COLOR_PAIR (a + 1);
}

/**
* Decodes an aubit attribute value to an ncurses colour setting
* 
* @param a the attribute to decode 
**/
int
decode_colour_attr_aubit (int a)
{
  char colour[20];
  char attr[256];
//int col;
  debug ("Decoding a");
  get_strings_from_attr (a, colour, attr);

  debug ("Got colour as : %s", colour);

  if (strcmp (colour, "BLACK") == 0)
    return colour_code (COLOR_BLACK);
  if (strcmp (colour, "RED") == 0)
    return colour_code (COLOR_RED);
  if (strcmp (colour, "GREEN") == 0)
    return colour_code (COLOR_GREEN);
  if (strcmp (colour, "YELLOW") == 0)
    return colour_code (COLOR_YELLOW);
  if (strcmp (colour, "BLUE") == 0)
    return colour_code (COLOR_BLUE);
  if (strcmp (colour, "MAGENTA") == 0)
    return colour_code (COLOR_MAGENTA);
  if (strcmp (colour, "CYAN") == 0)
    return colour_code (COLOR_CYAN);
  if (strcmp (colour, "WHITE") == 0)
    return colour_code (COLOR_WHITE);

  return 0;
}

/**
* Sets an attribute for a window from an Aubit attribute
*
* @param w curses window
* @param a attribute
**/
void
a4glattr_wattrset (WINDOW * w, int a)
{
  wattrset (w, decode_aubit_attr (a, 'w'));
}

/**
* Decodes an aubit attribute into a curses attribute
*
* @param a original aubit attribute
**/
int
decode_aubit_attr (int a, char s)
{
  char colour[20];
  char attr[256];
  int ca;			/* Curses attribute */

  get_strings_from_attr (a, colour, attr);
  ca = A_NORMAL;
  if (s == 'w')
    {
      ca = decode_colour_attr_aubit (a);
      if (strstr (attr, "NORMAL"))
	ca += A_NORMAL;
      if (strstr (attr, "REVERSE"))
	ca += A_REVERSE;
      if (strstr (attr, "UNDERLINE"))
	ca += A_UNDERLINE;
      if (strstr (attr, "BOLD"))
	ca += A_BOLD;
      if (strstr (attr, "BLINK"))
	ca += A_BLINK;
      if (strstr (attr, "DIM"))
	ca += A_DIM;

    }
  if (s == 'f')
    {
      ca = decode_colour_attr_aubit (a);
      if (strstr (attr, "NORMAL"))
	ca += A_NORMAL;
      if (strstr (attr, "REVERSE"))
	ca += A_REVERSE;
      if (strstr (attr, "UNDERLINE"))
	ca += A_UNDERLINE;
      if (strstr (attr, "BOLD"))
	ca += A_BOLD;
      if (strstr (attr, "BLINK"))
	ca += A_BLINK;
      if (strstr (attr, "DIM"))
	ca += A_DIM;
    }

  if (s == 'b')
    {
      ca = decode_colour_attr_aubit (a);
    }


  return ca;
}



/* ========================= EOF ========================= */

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
# $Id: colours.c,v 1.30 2010-02-16 13:17:11 mikeaubury Exp $
#*/
#ifndef lint
	static char const module_id[] =
		"$Id: colours.c,v 1.30 2010-02-16 13:17:11 mikeaubury Exp $";
#endif
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


#include "a4gl_lib_ui_tui_int.h"


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/


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
A4GL_colour_code (int a)
{
  int z;
  z = 1;

  if (!has_colors ()||A4GL_isyes(acl_getenv("MONO")))
    {
#ifdef DEBUG
	A4GL_debug("MJA - STANDOUT");
#endif
      if (a==7) return 0;
      if (a==0) return 0;
      //z = A_STANDOUT;
      //for (b = 0; b <= a; b++)
	//{
	  //z *= 2;
	//}
	if (!A4GL_isyes(acl_getenv("CLASSIC_I4GL_MONO"))) {
		if (a==1)  z=A_BOLD;     // RED
		if (a==2)  z=A_DIM;     // GREEN
		if (a==3)  z=A_BOLD;     // YELLOW
		if (a==4)  z=A_DIM;     // BLUE
		if (a==5)  z=A_BOLD;     // MAGENTA
		if (a==6)  z=A_DIM;     // CYAN
	} else {
		z=0;
	}
#ifdef DEBUG
	A4GL_debug("colour code for mono for %d = %d",a,z);
#endif


      return z;
    }
#ifdef DEBUG
  A4GL_debug ("MJA Returning color code (%d+1)\n", a);
#endif
  if (a == 0) return 0;
	if (a==7){
		 //// white...
		a=COLOR_PAIR(8);
		//a=0;
	} else {
#ifdef ALTERNATE_COLOURS
// 7 = cyan
// 6 = magenta
// 5 = blue
// 4 = yellow
// 3 = green
// 2 = red
		switch (a) {	
			case 0: 
  				a=COLOR_PAIR (8); break;
			case 1: 
  				a=COLOR_PAIR (5); break;
			case 2: 
  				a=COLOR_PAIR (3); break;
			case 3: 
  				a=COLOR_PAIR (7); break;
			case 4: 
  				a=COLOR_PAIR (2); break;
			case 5: 
  				a=COLOR_PAIR (6); break;
			case 6: 
  				a=COLOR_PAIR (4); break;
			case 7: 
  				a=COLOR_PAIR (8); break;
		}
#else
  		a=COLOR_PAIR (a + 1);
#endif
	}
#ifdef DEBUG
  A4GL_debug ("MJA Returning color code = %d\n", a);
#endif
  return a;
}

/**
* Decodes an aubit attribute value to an ncurses colour setting
* 
* @param a the attribute to decode 
**/
int
A4GL_decode_colour_attr_aubit (int a)
{
  char colour[20];
  char attr[256];
//int col;
#ifdef DEBUG
  A4GL_debug ("MJA Decoding %d",a);
#endif
  A4GL_get_strings_from_attr (a, colour, attr);

#ifdef DEBUG
  A4GL_debug ("MJA Got colour as : %s - %s", colour,attr);
#endif
  A4GL_trim(colour);

  if (strlen(colour)==0) {
#ifdef DEBUG
  		A4GL_debug ("MJA Got colour as nothing - Using WHITE ", colour,attr);
#endif
		return A4GL_colour_code(COLOR_WHITE);
  }

  if (strcmp (colour, "BLACK") == 0)
    return A4GL_colour_code (COLOR_BLACK);
  if (strcmp (colour, "RED") == 0)
    return A4GL_colour_code (COLOR_RED);
  if (strcmp (colour, "GREEN") == 0)
    return A4GL_colour_code (COLOR_GREEN);
  if (strcmp (colour, "YELLOW") == 0)
    return A4GL_colour_code (COLOR_YELLOW); 
  if (strcmp (colour, "BLUE") == 0)
    return A4GL_colour_code (COLOR_BLUE);
  if (strcmp (colour, "MAGENTA") == 0)
    return A4GL_colour_code (COLOR_MAGENTA);
  if (strcmp (colour, "CYAN") == 0)
    return A4GL_colour_code (COLOR_CYAN);
  if (strcmp (colour, "WHITE") == 0) {
#ifdef DEBUG
	 A4GL_debug("Its white.. %d",A4GL_colour_code (COLOR_WHITE));
#endif
    return A4GL_colour_code (COLOR_WHITE);
	}

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

if (w) {
	wattrset (w, A4GL_decode_aubit_attr (a, 'w'));
} else {
#ifdef DEBUG
	A4GL_debug("SERIOUS PROBLEM - w is set to zero....");
#endif
}



}

/**
* Decodes an aubit attribute into a curses attribute
*
* @param a original aubit attribute
**/
int
A4GL_decode_aubit_attr (int a, char s)
{
  char colour[20];
  char attr[256];
  int ca;			/* Curses attribute */

  A4GL_get_strings_from_attr (a, colour, attr);

#ifdef DEBUG
  A4GL_debug("A=%d colour=%s attr=%s MJAMJAMJA",a,colour,attr);
#endif

  ca = A_NORMAL;
  if (s == 'w')
    {
      ca = A4GL_decode_colour_attr_aubit (a);
      if (strstr (attr, "INVISIBLE"))
	ca += A_INVIS;

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
      ca = A4GL_decode_colour_attr_aubit (a);

      if (strstr (attr, "INVISIBLE"))
	ca += A_INVIS;

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
      ca = A4GL_decode_colour_attr_aubit (a);
    }

  if (s == 'B')
    {
      ca = A4GL_decode_colour_attr_aubit (a);
      if (strstr (attr, "REVERSE"))
	ca += A_REVERSE;
      if (strstr (attr, "INVISIBLE"))
	ca += A_INVIS;
      if (strstr (attr, "UNDERLINE"))
	ca += A_UNDERLINE;
    }
#ifdef DEBUG
A4GL_debug("Returning ca = %d %x (visible=%d)",ca,ca,!(ca&A_INVIS));
#endif
if (A4GL_isyes(acl_getenv("NO_INVIS_ATTR"))) {
	if (ca&A_INVIS) ca-=A_INVIS;
}

  return ca;
}

void UILIB_A4GL_init_color(int n,int r,int g,int b) {
#ifdef NCURSES_VERSION
	A4GL_chkwin();
	if (can_change_color())   {
#ifdef DEBUG
		A4GL_debug("Changing Colour - %d %d %d %d",n,r,g,b);
#endif
		init_color(n,r,g,b);
	} else {
#ifdef DEBUG
		A4GL_debug("Cannot change colour %d %d %d %d - not supported by terminal",n,r,g,b);
#endif
	}
#else
#ifdef DEBUG
	A4GL_debug("Cannot change colour - not supported unless using ncurses");
#endif
#endif
}

/* ========================= EOF ========================= */

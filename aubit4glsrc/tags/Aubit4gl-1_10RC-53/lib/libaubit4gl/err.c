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
# $Id: err.c,v 1.22 2009-02-23 17:31:49 mikeaubury Exp $
#
*/

/**
 * @file
 * Error composiong function.
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/


#include "a4gl_libaubit4gl_int.h"




/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

extern char *A4GL_get_errmsg (int a);




/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/**
 * Create a string with an 4gl error.
 *
 * @param a The error code.
 * @param s Aditional string to compose the error.
 */
char *
A4GL_err_print (int a, char *s)
{
  char *k;
  static char static_err[1024];
  A4GL_debug ("In err print %d %s", a, s);
  SPRINTF2 (static_err, "Unknown error %d (%s)", a, s);
  k = static_err;
  if (a == -3001)
    {
      A4GL_debug ("Ignore wrong number of variables..");
      strcpy (static_err, "Wrong number of variables returned from function");
      return k;
    }

/*
  if (a == -400)
    {
      A4GL_debug ("Ignore wrong number of variables..");
      SPRINTF1 (static_err, "Database error (%s)", s);

      return static_err;
      return k;
    }
*/


  if (a == -3002)
    {
      A4GL_debug ("Ignore wrong number of variables..");
      strcpy (static_err, "Wrong number of parameters passed to function");
      return k;
    }


  A4GL_debug ("Calling get_errmsg");
  k = A4GL_get_errmsg (a * -1);
  A4GL_debug ("Got %s", k);
  SPRINTF1 (static_err, k, s);
  return static_err;

}

void Never_called_but_I_wanted_a_dummy_function (void);

void
Never_called_but_I_wanted_a_dummy_function (void)
{
  A4GL_exitwith ("Unknown error");
}

/* =============================== EOF ============================== */

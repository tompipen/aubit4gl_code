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
# $Id: err.c,v 1.7 2003-05-12 14:24:05 mikeaubury Exp $
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

#ifdef OLD_INCL

#include "string.h"		/* strcpy() */
#include "stdio.h"		/* sprintf() */
#include "a4gl_debug.h"

#else

#include "a4gl_libaubit4gl_int.h"

#endif


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

extern char *get_errm (int a);

#ifdef OLD_INCL
char *err_print (int a, char *s);
#endif



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
err_print (int a, char *s)
{
  char *k;
  static char static_err[256];
  debug ("In err print");
  sprintf (static_err, "Unknown error %d (%s)", a, s);
  k = static_err;
  if (a == -3001)
    {
      debug ("Ignore wrong number of variables..");
      strcpy (static_err, "Wrong number of variables returned from function");
      return k;
    }
  debug ("Calling get_errm");
  k = get_errm (a * -1);
  debug ("Got %s", k);
  sprintf (static_err, k, s);
  return static_err;
}


/* =============================== EOF ============================== */

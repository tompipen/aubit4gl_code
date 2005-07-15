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
# $Id: gtime.c,v 1.9 2005-07-15 18:28:08 mikeaubury Exp $
#*/

/**
 * @file
 * Gettime function
 * Cannot use calls to A4GL_debug here!
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include <time.h>

/* #include "a4gl_debug.h" - causes wired errors */
extern void A4GL_debug_full (char *fmt, ...);


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

long A4GL_gettime (void);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/**
 * Get time in seconds.
 *
 * @return The time in seconds.
 */
long
A4GL_gettime (void)
{
  return time (0);
}




/* ================================= EOF ============================= */

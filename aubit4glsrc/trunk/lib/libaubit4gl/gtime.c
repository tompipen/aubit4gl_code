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
# $Id: gtime.c,v 1.6 2003-05-12 14:24:16 mikeaubury Exp $
#*/

/**
 * @file
 * Gettime function
 * Cannot use calls to debug here!
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include <time.h>

/* #include "a4gl_debug.h" - causes wired errors */
extern void debug_full (char *fmt, ...);


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

long gettime (void);
void debug (char *s);

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
gettime (void)
{
  return time (0);
}



/**
 * Write a debug message
 *
 * @param s The debug message
 */
/* what is this doing here?
    a4gl_debug.h defines debug as:
    #define debug set_line(__FILE__,__LINE__); debug_full

    it is needed but how/why ?
*/
void
debug (char *s)
{
  debug_full ("ERROR  - debug called in full with %s", s);
}

/* ================================= EOF ============================= */

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
# $Id: main.c,v 1.7 2002-08-29 09:10:31 afalout Exp $
#*/

/**
 * @file
 *
 *
 *
 *
 * @todo Doxygen comments to add to functions
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_ace_int.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/
/**
 *
 * @todo Describe function
 */
int
main (int argc, char *argv[])
{
  if (argc != 2) {
      printf ("Usage\n   %s filename\n", argv[0]);
      exit (1);
  }
  exit(compile_ace_report(argv[1]));
}



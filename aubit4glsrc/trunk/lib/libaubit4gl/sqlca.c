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
# $Id: sqlca.c,v 1.2 2003-05-12 14:24:18 mikeaubury Exp $
#
*/

/*
=====================================================================
                                                           Includes
=====================================================================
*/

#include "a4gl_libaubit4gl_int.h"

extern sqlca_struct a4gl_sqlca;


// Get & Set Functions for a4gl_status and member of the sqlca structure...

void
set_a4gl_status (int a)
{
  a4gl_status = a;
}

int
get_a4gl_status (void)
{
  return a4gl_status;
}



void
set_a4gl_sqlca_sqlcode (int a)
{
  a4gl_sqlca.sqlcode = a;
  set_a4gl_status (a);
}


int
get_a4gl_sqlca_sqlcode (void)
{
  return a4gl_sqlca.sqlcode;
}

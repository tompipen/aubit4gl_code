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
# $Id: sqlca.c,v 1.5 2005-03-09 15:14:41 mikeaubury Exp $
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
A4GL_set_a4gl_status (int a)
{
  a4gl_status = a;
}

int
A4GL_get_a4gl_status (void)
{
  return a4gl_status;
}



void
A4GL_set_a4gl_sqlca_sqlcode (int a)
{
  a4gl_sqlca.sqlcode = a;
  A4GL_set_a4gl_status (a);
}


int
A4GL_get_a4gl_sqlca_sqlcode (void)
{
  return a4gl_sqlca.sqlcode;
}


void A4GL_copy_sqlca_sqlawarn_8chars( char c0, char c1, char c2, char c3, char c4, char c5, char c6, char c7) {

a4gl_sqlca.sqlawarn[0]=c0;
a4gl_sqlca.sqlawarn[1]=c1;
a4gl_sqlca.sqlawarn[2]=c2;
a4gl_sqlca.sqlawarn[3]=c3;
a4gl_sqlca.sqlawarn[4]=c4;
a4gl_sqlca.sqlawarn[5]=c5;
a4gl_sqlca.sqlawarn[6]=c6;
a4gl_sqlca.sqlawarn[7]=c7;
a4gl_sqlca.sqlawarn[8]=0;
}

void A4GL_copy_sqlca_sqlawarn_string8( char *c) {
a4gl_sqlca.sqlawarn[0]=c[0];
a4gl_sqlca.sqlawarn[1]=c[1];
a4gl_sqlca.sqlawarn[2]=c[2];
a4gl_sqlca.sqlawarn[3]=c[3];
a4gl_sqlca.sqlawarn[4]=c[4];
a4gl_sqlca.sqlawarn[5]=c[5];
a4gl_sqlca.sqlawarn[6]=c[6];
a4gl_sqlca.sqlawarn[7]=c[7];
a4gl_sqlca.sqlawarn[8]=0;
}


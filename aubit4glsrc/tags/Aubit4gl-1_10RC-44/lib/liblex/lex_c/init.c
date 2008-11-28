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
# $Id: init.c,v 1.4 2008-07-06 11:34:36 mikeaubury Exp $
*/

#include "a4gl_lib_lex_c_int.h"

void printc (char *fmt, ...);


void
print_module_variable_init ()
{
  printc ("static int _done_init_module_variables=1;\n");
  printc ("static init_module_variables() {");
  printc ("if (_done_init_module_variables==0) return;");
  printc ("_done_init_module_variables=0;");
  print_nullify ('M');
  printc ("}");
}

void
print_function_variable_init ()
{
  printc ("init_module_variables();");
  print_nullify ('F');
}
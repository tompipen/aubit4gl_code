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
# $Id: nopdf.c,v 1.8 2005-03-09 15:15:10 mikeaubury Exp $
#*/

/**
 * @file
 * PDF Report Implementation functions used in absence of PDF libraries on system.
 *
 * @todo Add Doxygen A4GL_comments to file
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen A4GL_comments to add to functions
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include <stdio.h>

#if (defined(WIN32) && ! defined(__CYGWIN__))
#include <windows.h>
int WINAPI
libPDF_NOPDF_init (HANDLE h, DWORD reason, void *foo)
{
  return 1;
}


char
libPDF_NOPDF_is_dll (void)
{
  return 1;
}
#endif /* WIN32 && DLL_EXPORT */

/*
    man dlltool :

   The  first  file  is  a  .def  file  which specifies which
   functions are exported from the DLL, which  functions  the
   DLL  imports,  and  so on.  This is a text file and can be
   created by hand, or dlltool can be used to create it using
   the  -z option.  In this case dlltool will scan the object
   files specified on its  command  line  looking  for  those
   functions  which  have  been  specially  marked  as  being
   exported and put entries for them  in  the  .def  file  it
   creates.

   In  order to mark a function as being exported from a DLL,
   it needs to have an  -export:<name_of_function>  entry  in
   the .drectve section of the object file.  This can be done
   in C by using the asm() operator:

             asm (".section .drectve");
             asm (".ascii \"-export:my_func\"");

             int my_func (void) { ... }



*/

extern void A4GLPDF_initlib (void);

void
A4GLPDF_initlib (void)
{
  /* Does nothing */
}

/* ======================== EOF =============================== */

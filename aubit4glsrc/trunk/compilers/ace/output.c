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
# $Id: output.c,v 1.7 2004-01-29 08:35:41 mikeaubury Exp $
#*/

/**
 * @file
 *
 *
 *
 *
 * @todo Doxygen A4GL_comments to add to functions
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/


#ifdef OLD_INCL

#include "report.h"
#include <stdio.h>

#else

#include "a4gl_ace_int.h"

#endif


/*
=====================================================================
                    Variables definitions
=====================================================================
*/

extern struct report this_report;
extern char *outputfilename;

FILE *fxx;

/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/**
 *
 * @todo Describe function
 */
void
A4GL_write_report (void)
{
  char fname[132];
  char fname2[132];
  char base[132];
  char ext[132];

  int a;
  /* XDR xdrp; */
  struct report *ptr;

  ptr = &this_report;

  strcpy (fname, outputfilename);

  /* ace_bname(outputfilename, ext, base); */
  A4GL_bname (outputfilename, ext, base);

  if (ext[0] == 0)
    {
      strcat (fname, ".aarc");
    }

  strcpy (fname2, outputfilename);
  strcat (fname2, ".c");


  a = A4GL_write_data_to_file ("report", ptr, fname);





  if (!a)
    {
      A4GL_debug ("*** Write FAILED ***\n");
      printf ("Unable to write data\n");
    }

}


/* ================================== EOF =========================== */

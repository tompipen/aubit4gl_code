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
# $Id: output.c,v 1.2 2002-06-29 10:49:36 afalout Exp $
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
write_report (void)
{
  char fname[132];
  char fname2[132];
  char base[132];
  char ext[132];

  int a;
  XDR xdrp;
  struct report *ptr;

  ptr = &this_report;

  strcpy(fname, outputfilename);

  /* ace_bname(outputfilename, ext, base); */
  bname(outputfilename, ext, base);

  if (ext[0] == 0)
  {
          strcat(fname, ".aarc");
  }

  strcpy(fname2, outputfilename);
  strcat(fname2, ".c");

  fxx = fopen(fname,"wb");

  if (fxx == 0)
  {
    printf("Couldnt open file for write (%s)\n", fname);
  }
  xdrstdio_create(&xdrp, fxx, XDR_ENCODE);

  a=xdr_report(&xdrp,ptr);
  if (!a)
        {
           debug("*** Write FAILED ***\n");
                printf("Unable to write data\n");
  }

  xdr_destroy(&xdrp);
  fclose(fxx);
}


/* ================================== EOF =========================== */

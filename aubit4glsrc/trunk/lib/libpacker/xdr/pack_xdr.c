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
# $Id: pack_xdr.c,v 1.8 2003-05-15 07:10:43 mikeaubury Exp $
#*/

/**
 * @file
 *
 * We don't actually do much in here
 * we just use the name of the datatype specified
 * to identify the xdr routine to call
 * and then - call it...
 *
 *
 * @todo Doxygen A4GL_comments to add to functions
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_lib_packer_xdr_int.h"

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

int A4GLPACKER_initlib (void);

static int (*A4GL_func) ();		/*  warning: function declaration isn't a prototype */
static int process_xdr (char dir, char *name, void *s, char *filename);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/**
 *
 * @todo Describe function
 */
int
A4GLPACKER_initlib (void)
{
  return 1;
}

/**
 *
 * @todo Describe function
 */
int
A4GL_can_pack_all (char *name)
{
  void *libptr;
  libptr = (void *) A4GL_dl_openlibrary ("XDRPACKER", name);
  if (libptr)
    return 1;
  return -1;
}



/*
   We don't need to worry about these two functions
   as we're doing the whole thing in one go using xdr
*/
int
A4GL_open_packer (char *fname, char dir)
{
  return 1;
}

void
A4GL_close_packer (char dir)
{
  return;
}


/**
 *
 * @todo Describe function
 */
int
A4GL_pack_all (char *name, void *s, char *filename)
{
  A4GL_debug ("Pack all ...");
  return process_xdr ('O', name, s, filename);
}


/**
 *
 * @todo Describe function
 */
int
A4GL_unpack_all (char *name, void *s, char *filename)
{
  return process_xdr ('I', name, s, filename);
}


/**
 *
 * @todo Describe function
 */
static int
process_xdr (char dir, char *name, void *s, char *filename)
{
  FILE *fxx;
  void *libptr;
  char buff[256];
  XDR xdrp;

  sprintf (buff, "xdr_%s", name);

  libptr = (void *) A4GL_dl_openlibrary ("XDRPACKER", name);
  if (libptr == 0)
    return 0;

  /*
     We can only write to the current directory - but we
     can open files from anywhere on the dbpath
   */
  if (dir == 'O')
    {
      fxx = fopen (filename, "wb");
      A4GL_set_last_outfile (filename);
    }
  else
    fxx = (FILE *) A4GL_open_file_dbpath (filename);


  if (fxx == 0)
    {
      A4GL_debug ("Can't open file %s\n", filename);

      return 0;
    }


  if (dir == 'O')
    xdrstdio_create (&xdrp, fxx, XDR_ENCODE);
  else
    xdrstdio_create (&xdrp, fxx, XDR_DECODE);

  A4GL_func = (void *) A4GL_find_func (libptr, buff);
  if (A4GL_func == 0)
    return 0;

  A4GL_func (&xdrp, s);

  xdr_destroy (&xdrp);
  fclose (fxx);
  return 1;
}



/* =================================== EOF =========================== */

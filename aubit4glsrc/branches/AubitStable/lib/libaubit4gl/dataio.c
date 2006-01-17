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
# $Id: dataio.c,v 1.12 2005-07-15 18:28:08 mikeaubury Exp $
#
*/

/**
 * @file
 * This handles just two functions
 *
 * 1) Reading a file
 * 2) Writing a file
 * 
 * The difficulty comes from the fact that we need to generate or read 
 * C structures in order to read/write the data.
 *
 * To do this we use a series of shared libraries.
 *
 * At the top level we have the functions in the file
 *  These call the relevant 'read' functions from a shared library
 *  These then call (via API_packer) the actual routines to do the reading and 
 *  writing
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

#include "a4gl_libaubit4gl_int.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

static void *libptr = 0;
static int (*A4GL_func) (void *ptr, char *filename);	/*FIXME-warning: function declaration isn't a prototype */

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/


/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 *
 *
 * @param
 * @param
 * @param
 */
int
A4GL_read_data_from_file (char *datatype, void *ptr, char *filename)
{
  char buff[256];
#ifdef DEBUG
  A4GL_debug ("Read_data_from_file : %s %p %s", A4GL_null_as_null(datatype), ptr, A4GL_null_as_null(filename));
#endif
  libptr = (void *) A4GL_dl_openlibrary ("DATA", datatype);
  if (libptr == 0)
    {
      A4GL_exitwith ("Unable to open library");
      return 0;
    }

  SPRINTF1 (buff, "read_%s", datatype);
  A4GL_func = A4GL_find_func (libptr, buff);
  return A4GL_func (ptr, filename);
}


/**
 *
 *
 * @param
 * @param
 * @param
 */
int
A4GL_write_data_to_file (char *datatype, void *ptr, char *filename)
{
  char buff[256];
  int result;
#ifdef DEBUG
  A4GL_debug ("Write data to file : datatype=%s ptr=%p file=%s\n",
	 A4GL_null_as_null(datatype), ptr, A4GL_null_as_null(filename));
#endif
  libptr = (void *) A4GL_dl_openlibrary ("DATA", datatype);
  if (libptr == 0)
    {
      A4GL_exitwith ("Unable to open library");
      return 0;
    }

  SPRINTF1 (buff, "write_%s", datatype);

#ifdef DEBUG
  A4GL_debug ("Looking for function : %s", A4GL_null_as_null(buff));
#endif

  A4GL_func = A4GL_find_func (libptr, buff);
#ifdef DEBUG
  A4GL_debug ("Calling %s(ptr=%p,filename=%s)", A4GL_null_as_null(buff), ptr, A4GL_null_as_null(filename));
#endif

  result = A4GL_func (ptr, filename);

#ifdef DEBUG
  A4GL_debug ("Returned from %s\n", A4GL_null_as_null(buff));
#endif

  return result;
}

/* ================================ EOF =================================== */

/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-2 Aubit Development Team (See Credits file)       |
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
# $Id: dataio.c,v 1.3 2002-10-07 11:06:26 afalout Exp $
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

#ifdef __CYGWIN__
	#include <windows.h>
	#include <errno.h>
#endif

#include "a4gl_libaubit4gl_int.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

static void *libptr=0;
static int (*func)();/*FIXME-warning: function declaration isn't a prototype */

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
read_data_from_file(char *datatype, void *ptr, char *filename)
{
char buff[256];
	#ifdef DEBUG
		debug("Read_data_from_file : %s %p %s",datatype,ptr,filename);
    #endif
	libptr=(void *)dl_openlibrary("DATA",datatype);
	if (libptr==0) {
		exitwith("Unable to open library");
		return 0;
	}

	sprintf(buff,"read_%s",datatype);
	func=find_func(libptr,buff);
	return func(ptr,filename);
}


/**
 *
 *
 * @param
 * @param
 * @param
 */
int
write_data_to_file(char *datatype, void *ptr, char *filename)
{
char buff[256];
	#ifdef DEBUG
		debug("Write data to file : datatype=%s ptr=%p file=%s\n",
			datatype,ptr,filename);
    #endif
	libptr=(void *)dl_openlibrary("DATA",datatype);
	if (libptr==0) {
		exitwith("Unable to open library");
		return 0;
	}

	sprintf(buff,"write_%s",datatype);

	#ifdef DEBUG
		debug("Looking for function : %s",buff);
    #endif

	func=find_func(libptr,buff);
	#ifdef DEBUG
		debug("Calling %s(ptr=%p,filename=%s)",buff,ptr,filename);
    #endif
	return func(ptr,filename);
}

/* ================================ EOF =================================== */

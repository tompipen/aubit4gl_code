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
# $Id: dataio.c,v 1.1 2002-07-11 09:22:04 mikeaubury Exp $
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
 *  These then call (via API_packer) the actual routines to do the reading and writing
 *  
 *
 *
 * @todo Doxygen comments to add to functions
 */

#ifdef OLD_INCL

	#include <signal.h>                 /* SIGINT */
	#include <locale.h>                 /* setlocale() */
	#include <string.h>
	#include <unistd.h> 				/* sleep() */

	#ifdef __CYGWIN__
		#include <windows.h>
		#include <errno.h>
	#endif

	#include "a4gl_dbform.h"
	#include "a4gl_stack.h"
	#include "a4gl_debug.h"
	#include "a4gl_keys.h"
	#include "a4gl_aubit_lib.h"
	#include "a4gl_dlsql.h"				/* A4GLSQL_initlib() */
	#include "a4gl_runtime_tui.h"		/*  push_int() */

#else

    #include "a4gl_libaubit4gl_int.h"

#endif

static void *libptr=0;
static int (*func)();


int read_data_from_file(char *datatype, void *ptr, char *filename) ;
int write_data_to_file(char *datatype, void *ptr, char *filename) ;



int read_data_from_file(char *datatype, void *ptr, char *filename) {
char buff[256];
debug("Read_data_from_file : %s %p %s",datatype,ptr,filename);
	libptr=(void *)dl_openlibrary("DATA",datatype);
	if (libptr==0) {
		exitwith("Unable to open library");
		return 0;
	}

	sprintf(buff,"read_%s",datatype);
	func=find_func(libptr,buff);
	return func(ptr,filename);
}



int write_data_to_file(char *datatype, void *ptr, char *filename) {
char buff[256];

debug("Write data to file : datatype=%s ptr=%p file=%s\n",datatype,ptr,filename);

	libptr=(void *)dl_openlibrary("DATA",datatype);
	if (libptr==0) {
		exitwith("Unable to open library");
		return 0;
	}

	sprintf(buff,"write_%s",datatype);

	debug("Looking for function : %s",buff);

	func=find_func(libptr,buff);
	debug("Calling %s(ptr=%p,filename=%s)",buff,ptr,filename);
	return func(ptr,filename);
}

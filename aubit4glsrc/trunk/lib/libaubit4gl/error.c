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
# $Id: error.c,v 1.5 2002-05-17 07:08:33 afalout Exp $
#
*/

/**
 * @file
 * Error handling (there are several files)
 *
 * @todo Add Doxygen comments to file
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "../generated/tmperrs.h"
#include "a4gl_debug.h"
#include <stdarg.h>

/*
=====================================================================
                    Constants definitions
=====================================================================
*/

#define IGNOREEXITWITH

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

char errorbuff[256]="";
char lasterrorstr[1024]="";
extern int status;
int cache_status=0;
int cache_statusno=0;

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 *
 * @todo Describe function
 */
IGNOREEXITWITH exitwith(char *s)
{
int a;
	#ifdef DEBUG
		/* {DEBUG} */ {debug("Error... %s",s);}
	#endif

	for (a=0;errors[a].errno;a++)
	{
		if (strcmp(s,errors[a].errmsg)==0)
		{
			#ifdef DEBUG
				/* {DEBUG} */ {debug("Found error = %d",errors[a].errno);}
			#endif
			debug("Setting status");
		   	A4GLSQL_set_status(-1*(errors[a].errno+30000),0);
			debug("Setting cache_status");
		    cache_status=(errors[a].errno+30000);
			debug("Setting statusno");
		    cache_statusno=a;
			return;
		}
	}

	exitwith("Unknown error");
}


/**
 *
 * @todo Describe function
 */
IGNOREEXITWITH exitwith_sql(char *s)
{
int a;
	#ifdef DEBUG
		/* {DEBUG} */ {debug("Error... %s",s); }
	#endif
	for (a=0;errors[a].errno;a++)
	{
		if (strcmp(s,errors[a].errmsg)==0)
		{
			#ifdef DEBUG
				/* {DEBUG} */ {debug("Found error = %d",errors[a].errno);}
			#endif
             A4GLSQL_set_status(-1*(errors[a].errno+30000),1);
		     cache_status=(errors[a].errno+30000);
		     cache_statusno=a;
		}
	}
}

/**
 *
 * @todo Describe function
 */
void 
set_error (char *fmt,...)
{
  va_list args;
  va_start (args, fmt);
  vsprintf (errorbuff, fmt, args);
#ifdef DEBUG
	/* {DEBUG} */ {  debug("%s",errorbuff);}
#endif
}

/**
 *
 * @todo Describe function
 */
char *
get_errm(int z)
{
int a;
	debug("In get errm");
	if (z==cache_status) {
	debug("Cached...");
		return errors[cache_statusno].errmsg;
	}

	       debug("Looking up error... %d",a);
	for (a=0;errors[a].errno;a++) {
	       if (errors[a].errno+30000==z) {
		return errors[a].errmsg;
	       }
	}
	debug("Not found...");
	debug("Returning %p",lasterrorstr);
	debug("Returning %s",lasterrorstr);
	return lasterrorstr;
}

// ======================== EOF =======================

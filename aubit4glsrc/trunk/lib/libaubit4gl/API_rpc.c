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
# $Id: API_rpc.c,v 1.8 2002-06-11 08:42:26 afalout Exp $
#
*/

/**
 * @file
 *
 * @todo Add Doxygen comments to file
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_dbform.h"
#include "a4gl_debug.h"
#include "a4gl_aubit_lib.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

static void *libptr=0;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

static int 		(*func)				();
/* void *			find_func			(void *p,char *s); on calldll.c */
int				A4GLRPC_initlib 	(void);
int				remote_func_call 	(char *host,int async,char *funcname,
									int port,int np);


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
A4GLRPC_initlib (void)
{

	debug("Opening RPC library");
        libptr=(void *)dl_openlibrary("RPC",acl_getenv("RPCTYPE"));

        debug("libptr=%p\n",libptr);

        if (libptr==0) {
                exitwith("Unable to open RPC library.");
                return 0;
        }

        func=find_func_allow_missing(libptr,"A4GLRPC_initlib");

        if (func)
                return func();
        else
                return 1;
}




/**
 *
 * @todo Describe function
 */
int
remote_func_call (char *host,int async,char *funcname,int port,int np)
{
	debug("remote_func_call - libptr=%p\n");
  if (libptr==0) A4GLRPC_initlib();
  func=find_func(libptr,"remote_func_call");
  return func (host,async,funcname,port,np);
}


/* ============================== EOF ================================= */

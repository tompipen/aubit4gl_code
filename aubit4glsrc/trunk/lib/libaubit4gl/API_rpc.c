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
# $Id: API_rpc.c,v 1.14 2004-02-10 13:50:20 mikeaubury Exp $
#
*/

/**
 * @file
 *
 * @todo Add Doxygen A4GL_comments to file
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

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

static int (*A4GL_func) ();
int A4GL_register_func(char *s,void *ptr) ;
int A4GL_unregister_func(char *s,void *ptr) ;
int A4GL_server_run(long service) ;

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

  A4GL_debug ("Opening RPC library");
  libptr = (void *) A4GL_dl_openlibrary ("RPC", acl_getenv ("RPCTYPE"));

  A4GL_debug ("libptr=%p\n", libptr);

  if (libptr == 0)
    {
      A4GL_exitwith ("Unable to open RPC library.");
      return 0;
    }

  A4GL_func = A4GL_find_func_allow_missing (libptr, "A4GLRPC_initlib");

  if (A4GL_func)
    return A4GL_func ();
  else
    return 1;
}




/**
 *
 * @todo Describe function
 */
int
A4GL_remote_func_call (char *host, int async, char *funcname, int port, int np)
{
  A4GL_debug ("remote_func_call - libptr=%p\n");
  if (libptr == 0)
    A4GLRPC_initlib ();
  A4GL_func = A4GL_find_func (libptr, "A4GL_remote_func_call");
  return A4GL_func (host, async, funcname, port, np);

}


int A4GL_register_func(char *s,void *ptr) {
  A4GL_debug ("remote_func_call - libptr=%p\n");
  if (libptr == 0) A4GLRPC_initlib ();
  A4GL_func = A4GL_find_func (libptr, "A4GL_register_func");
  return A4GL_func (s,ptr);
}


int A4GL_unregister_func(char *s,void *ptr) {
  A4GL_debug ("remote_func_call - libptr=%p\n");
  if (libptr == 0) A4GLRPC_initlib ();
  A4GL_func = A4GL_find_func (libptr, "A4GL_unregister_func");
  return A4GL_func (s,ptr);
}

int A4GL_server_run(long service) {
  A4GL_debug ("remote_func_call - libptr=%p\n");
  if (libptr == 0) A4GLRPC_initlib ();
  A4GL_func = A4GL_find_func (libptr, "A4GL_server_run");
  return A4GL_func (service);
}




/* ============================== EOF ================================= */

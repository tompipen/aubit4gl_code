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
# $Id: rpc_stack_clnt.c,v 1.4 2002-06-06 12:31:28 afalout Exp $
#*/

/**
 * @file
 * This file was generated using rpcgen and then modified (IIRC) which
 * allows it to act as both a client and a server, in the same C code
 * (which isn't normally possible).
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include <memory.h> /* for memset */
#include "a4gl_xdr_rpc_stack.h"

/*
=====================================================================
                    Constants definitions
=====================================================================
*/

#define main server_run

/*
=====================================================================
                    Variables definitions
=====================================================================
*/


extern unsigned long serviceport;

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 *
 */
return_values *
call_remote_func_1(call arg1,  CLIENT *clnt)
{
static return_values clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));

/* in rpc/clnt.h :
 * enum clnt_stat
 * CLNT_CALL(rh, proc, xargs, argsp, xres, resp, timeout)
 * 	CLIENT *rh;
 *	u_long proc;
 *	xdrproc_t xargs;
 *	caddr_t argsp;
 *	xdrproc_t xres;
 *	caddr_t resp;
 *	struct timeval timeout;
 */

	if (clnt_call(
			clnt,
			CALL_REMOTE_FUNC,
			(xdrproc_t)xdr_call,
			(caddr_t)&arg1,
			(xdrproc_t)xdr_return_values,
			(caddr_t)&clnt_res,
			TIMEOUT
			)
				!= RPC_SUCCESS)
	{
		return (NULL);
	}

	return (&clnt_res);
}


/* ============================= EOF =============================== */


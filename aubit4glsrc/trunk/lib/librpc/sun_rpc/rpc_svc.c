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
# $Id: rpc_svc.c,v 1.9 2002-10-20 12:02:38 afalout Exp $
#*/

/**
 * @file
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

#include "a4gl_lib_rpc_xdr_int.h"

/*
=====================================================================
                    Constants definitions
=====================================================================
*/

#ifdef __STDC__
	#define SIG_PF void(*)(int)
#endif
#define main server_run

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

extern unsigned long serviceport;
SVCXPRT *stransp;
int funcs_registered=0;
int do_stop_serving=0;
int rpc_svc_run(void);

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

int server_run(long port);
int register_func(char *s,void *ptr);
int unregister_func(char *s);
void stop_serving(void);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/
/**
 *
 * @todo Describe function
 */
static return_values *
_call_remote_func_1(call  *argp, struct svc_req *rqstp)
{
	return(call_remote_func_1_svc(*argp, rqstp));
}

/**
 *
 * @todo Describe function
 */
static void
fgl_rpc_1(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		call call_remote_func_1_arg;
	} argument;
	char *result;
	xdrproc_t xdr_argument, xdr_result;
	char *(*local)(char *, struct svc_req *);
	stransp=transp;
	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply(transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case CALL_REMOTE_FUNC:
		xdr_argument = (xdrproc_t) xdr_call;
		xdr_result = (xdrproc_t) xdr_return_values;
		local = (char *(*)(char *, struct svc_req *)) _call_remote_func_1;
		break;

	default:
		svcerr_noproc(transp);
		return;
	}
	(void) memset((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs(transp, xdr_argument, (caddr_t) &argument)) {
		svcerr_decode(transp);
		return;
	}
	result = (*local)((char *)&argument, rqstp);
	if (result != NULL && !svc_sendreply(transp, xdr_result, result)) {
		svcerr_systemerr(transp);
	}
	if (!svc_freeargs(transp, xdr_argument, (caddr_t) &argument)) {
		exitwith("unable to free arguments");
		return;
	}
	return;
}


/**
 *
 * @todo Describe function
 */
int
server_run(long port)
{
	register SVCXPRT *transp;
	serviceport=port;
	debug("Starting server on port %ld",port);
	(void) pmap_unset(FGL_RPC, FGL_RPC_VER);

	transp = svcudp_create(RPC_ANYSOCK);
	if (transp == NULL) {
		exitwith("cannot create udp service.");
		return 0;
	}
	if (!svc_register(transp, FGL_RPC, FGL_RPC_VER, fgl_rpc_1, IPPROTO_UDP)) {
		exitwith("unable to register (FGL_RPC, FGL_RPC_VER, udp).");
		return 0;
	}

	transp = svctcp_create(RPC_ANYSOCK, 0, 0);

	if (transp == NULL) {
		exitwith("cannot create tcp service.");
		return 0;
	}

	if (!svc_register(transp, FGL_RPC, FGL_RPC_VER, fgl_rpc_1, IPPROTO_TCP)) {
		exitwith("unable to register (FGL_RPC, FGL_RPC_VER, tcp).");
		return 0;
	}
	debug("Start loop");
	rpc_svc_run();
	debug("Finished RPC loop (%d)",funcs_registered);
	svc_unregister(FGL_RPC,FGL_RPC_VER);
        debug("Server unregistered reset funcs_registered");
	do_stop_serving=0;
return 1;
}


/**
 *
 * @todo Describe function
 */
int
register_func(char *s,void *ptr)
{
	debug("Registering function %s",s);
	if (has_pointer(s,RPC_FUNC)) {
	        debug("its already there !");
		exitwith("Function Already registered");
		return 0;
	}
	debug("Adding pointer");
	add_pointer(s,RPC_FUNC,ptr);
        funcs_registered++;
	debug("%d functions currently registered",funcs_registered);
return 1;
}


/**
 *
 * @todo Describe function
 */
int
unregister_func(char *s)
{
	if (has_pointer(s,RPC_FUNC)) {
		debug("unregistering rpc %s",s);
		del_pointer(s,RPC_FUNC);
		debug("done");
	} else {
		exitwith("Function not registered");
		return 0;
	}
        funcs_registered--;
        debug("Unregistered %s",s);
return 1;
}

/**
 *
 * @todo Describe function
 */
void
stop_serving(void)
{
	debug("Stopping server");
	do_stop_serving=1;
}

/**
 *
 * @todo Describe function
 */
int
rpc_svc_run(void)
{
fd_set readfdset;
static int tsize=0;
static struct timeval tv;

	if (!tsize) tsize=getdtablesize();
	tv.tv_sec=1;
	tv.tv_usec=0;

	while (1)
	{
		readfdset=svc_fdset;
		switch (select(tsize,&readfdset,
			(fd_set *) NULL,
			(fd_set *) NULL,
			&tv)) {
		case -1 : /* if (errno==EBADF) continue; */
			  exitwith("RPC server failed");
			  return 0;
		case 0 :  if (do_stop_serving==0&&funcs_registered>0) continue;
			  else return 0; /* stop server */

		default : svc_getreqset(&readfdset);
			  if (funcs_registered<=0||do_stop_serving) return 0; /* stop server */
		}
	}
}

/**
 *
 * @todo Describe function
 */
void
fgl_rpc_reply(void *result)
{
	xdrproc_t xdr_result;

	xdr_result = (xdrproc_t) xdr_return_values;
	if (result != NULL && !svc_sendreply(stransp, xdr_result, result))
	{
		exitwith("Unable to send asynchronous reply!");
	}
	return;
}

/* ========================== EOF ================================= */


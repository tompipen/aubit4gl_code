/**
 * @file
 *
 * @todo Add Doxygen comments to file
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 */

#include "rpc_stack.h"
#include "a4gl_pointers.h"

#ifdef __CYGWIN__
	#define GETENV_OK
	//On Cygwin, stdlib.h, will have getenv
	//call. Everywhere else, we should use acl_getenv.
#endif
#include "a4gl_debug.h"

#include <stdio.h>
#include <stdlib.h>				/* getenv, exit */
#include <rpc/pmap_clnt.h> 		/* for pmap_unset */
#include <string.h> 			/* strcmp */
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>





#ifdef __STDC__
#define SIG_PF void(*)(int)
#endif
#define main server_run
extern unsigned long serviceport;

SVCXPRT *stransp;

int funcs_registered=0;
int do_stop_serving=0;


static return_values *
_call_remote_func_1(call  *argp, struct svc_req *rqstp)
{
	return(call_remote_func_1_svc(*argp, rqstp));
}

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
}


register_func(char *s,void *ptr) {
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
}

unregister_func(char *s) {
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
}

stop_serving() {
debug("Stopping server");
	do_stop_serving=1;
}

rpc_svc_run() {
fd_set readfdset;
extern int errno;
static int tsize=0;
static struct timeval tv;

if (!tsize) tsize=getdtablesize();
tv.tv_sec=1;
tv.tv_usec=0;

while (1) {
	readfdset=svc_fdset;
	switch (select(tsize,&readfdset,
		(fd_set *) NULL,
		(fd_set *) NULL,
		&tv)) {
	case -1 : //if (errno==EBADF) continue;
		  exitwith("RPC server failed");
		  return 0;
	case 0 :  if (do_stop_serving==0&&funcs_registered>0) continue;
		  else return 0; /* stop server */

	default : svc_getreqset(&readfdset);
		  if (funcs_registered<=0||do_stop_serving) return 0; /* stop server */
	}
    }
}
		
void fgl_rpc_reply(char *result)
{
	xdrproc_t xdr_result;

	xdr_result = (xdrproc_t) xdr_return_values;
	if (result != NULL && !svc_sendreply(stransp, xdr_result, result)) {
		exitwith("Unable to send asynchronous reply!");
	}
	return;
}




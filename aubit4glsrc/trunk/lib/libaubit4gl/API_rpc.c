
#include "../libincl/dbform.h"
#include "../libincl/debug.h"

static void *libptr=0;
static int (*func)();
void *find_func(void *p,char *s);
void *find_func_allow_missing(void *p,char *s);

int A4GLRPC_initlib (void)
{

	debug("Opening RPC library");
        libptr=(void *)dl_openlibrary("RPC",acl_getenv("RPCTYPE"));

        debug("libptr=%p\n",libptr);

        if (libptr==0) {
                exitwith("Unable to open RPC library...");
                return 0;
        }

        func=find_func_allow_missing(libptr,"A4GLRPC_initlib");

        if (func)
                return func();
        else
                return 1;
}




int
remote_func_call (char *host,int async,char *funcname,int port,int np)
{
  va_list ap;
	debug("remote_func_call - libptr=%p\n");
  if (libptr==0) A4GLRPC_initlib();
  func=find_func(libptr,"remote_func_call");
  return func (host,async,funcname,port,np);
}


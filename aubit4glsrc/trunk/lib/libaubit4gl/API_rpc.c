/*
 * lib=RPC env=A4GL_RPCTYPE lib_prefix= api_prefix=
 * @file
 * File definition
 *
 * This file was created from .spec file of same name, using dlmagic script
 * - if you need to edit it, edit .spec file instad, and use [make filename.c]
 * to re-create it.
 *
 * @todo Add Doxygen comments to file
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 */

/*******************************************************************
* (c) 1997-2002 Aubit Computing Ltd.
*
*
********************************************************************/


#include "a4gl_libaubit4gl_int.h"

static void *libptr=0;
int A4GLRPC_initlib (void);
void A4GLRPC_clrlibptr (void);
int dlclose (void *__handle);

/**
 * Library init function.
 *
 * @todo : explain ussage and parameters.
 * @return .
 */

void A4GLRPC_clrlibptr (void) {
    if (libptr) {dlclose(libptr);}
    libptr=0;
}

int A4GLRPC_initlib (void) {
int (*func)(void);
   libptr=(void *)A4GL_dl_openlibrary("RPC",acl_getenv("A4GL_RPCTYPE"));
   if (libptr==0) {
      A4GL_exitwith("Unable to open  library...");
      return 0;
   }
   func=A4GL_find_func_allow_missing(libptr,"A4GLRPC_initlib");

   if (func)
      return func();
   else
      return 1;
}


/* int A4GL_remote_func_call (char *host, int async, char *funcname, int port, int np) */
/* int A4GL_register_func(char *s,void *ptr)  */
/* int A4GL_unregister_func(char *s,void *ptr)  */
/* int A4GL_server_run(long service)  */
int A4GL_remote_func_call(char* host,int async,char* funcname,int port,int np) {
int rval;
static int (*func_1)(char *  ,int ,char *  ,int ,int );
#ifdef DEBUG
A4GL_debug("Call to int A4GL_remote_func_call((%s)),%d,(%s)),%d,%d)\n",A4GL_null_as_null(host),async,A4GL_null_as_null(funcname),port,np);
#endif
   if (libptr==0) A4GLRPC_initlib();
   func_1=A4GL_find_func(libptr,"A4GL_remote_func_call");
   rval=(int)func_1 (host,async,funcname,port,np);
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

int A4GL_register_func(char* s,void* ptr) {
int rval;
static int (*func_2)(char *  ,void *  );
#ifdef DEBUG
A4GL_debug("Call to int A4GL_register_func((%s)),%p)\n",A4GL_null_as_null(s),ptr);
#endif
   if (libptr==0) A4GLRPC_initlib();
   func_2=A4GL_find_func(libptr,"A4GL_register_func");
   rval=(int)func_2 (s,ptr);
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

int A4GL_unregister_func(char* s) {
int rval;
static int (*func_3)(char *  );
#ifdef DEBUG
A4GL_debug("Call to int A4GL_unregister_func((%s)))\n",A4GL_null_as_null(s));
#endif
   if (libptr==0) A4GLRPC_initlib();
   func_3=A4GL_find_func(libptr,"A4GL_unregister_func");
   rval=(int)func_3 (s);
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

int A4GL_server_run(long service) {
int rval;
static int (*func_4)(long );
#ifdef DEBUG
A4GL_debug("Call to int A4GL_server_run(%p)\n",service);
#endif
   if (libptr==0) A4GLRPC_initlib();
   func_4=A4GL_find_func(libptr,"A4GL_server_run");
   rval=(int)func_4 (service);
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}


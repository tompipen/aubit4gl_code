
/*
 * lib=RPC env=A4GL_RPCTYPE lib_prefix= api_prefix=
 * @file
 * Function prototypes
 *
 * This file was created from .spec file of same name, using dlmagic script
 * - if you need to edit it, edit .spec file instad, and use [make filename.h]
 * to re-create it.
 *
 * @todo See if the functions are static
 * or to be externally seen
 */

/*******************************************************************
* (c) 1997-2002 Aubit Computing Ltd.
*
*
********************************************************************/

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

#ifndef __RPC_H__
#define __RPC_H__
#ifdef __cplusplus
extern "C"
{
#endif

/* int A4GL_remote_func_call (char *host, int async, char *funcname, int port, int np) */
/* int A4GL_register_func(char *s,void *ptr)  */
/* int A4GL_unregister_func(char *s,void *ptr)  */
/* int A4GL_server_run(long service)  */
int A4GL_remote_func_call(char* host,int async,char* funcname,int port,int np);

int A4GL_register_func(char* s,void* ptr);

int A4GL_unregister_func(char* s,void* ptr);

int A4GL_server_run(long service);

#ifdef __cplusplus
}
#endif
#endif  /* #ifdef __ lib _H__  */


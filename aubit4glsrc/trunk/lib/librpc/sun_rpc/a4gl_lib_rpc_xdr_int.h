#if (defined(__sun__) && defined(__sparc__))
	// On Solaris bool_t not defined in RPC lib headers
	#define bool_t int
	// On solaris needed for auth_stat
	#include "rpc/auth.h"
#endif

#if (defined(__CYGWIN__))
	#define	enum_t	int
#endif

#include "a4gl_lib_rpc_int.h"

#if (defined(__MACH__) && defined(__APPLE__))
	/* need to include it explicity */
	#include "rpc/xdr.h"
#endif

/*
why was I including this explicitly, it was all supposed to be 
included via /rpc/rpc.h ????
#include "rpc/auth.h"
pmap_clnt.h was NOT included - have to explicity specify it to get 
proto for pmap_unset:
*/
#include "rpc/pmap_clnt.h" /* pmap_unset() */


/* ======================== from a4gl_xdr_rpc_stack.h ================ */

/**
 * @file XDR RPC stack definitions
 *
 * This file was generated using rpcgen and then modified (IIRC) which
 * allows it to act as both a client and a server, in the same C code
 * (which isn't normally possible).
 *
 */

#ifndef _RPC_STACK_H_RPCGEN
	#define _RPC_STACK_H_RPCGEN
	/*
	   to force LCLint to process <sys/types.h>, since rpc.h needs fd_set.

	   included via /usr/include/sys/types.h but defined in /usr/include/sys/select.h

	 */

	/*@-skipposixheaders@ */
	#include <sys/types.h>
	/*@=skipposixheaders@ */

	#include <rpc/rpc.h>

	#define main server_run

	struct single_dtype
	{
	  int dtype;
	  union
	  {
		short shortval;
		long longval;
		float smfltval;
		double floatval;
		char *chardata;
		struct
		{
		  u_int blobdata_len;
		  char *blobdata_val;
		}
		blobdata;
	  }
	  single_dtype_u;
	};
	typedef struct single_dtype single_dtype;
	#ifdef __cplusplus
		extern "C" bool_t xdr_single_dtype (XDR *, single_dtype *);
	#elif __STDC__
		extern bool_t xdr_single_dtype (XDR *, single_dtype *);
	#else /* Old Style C */
		bool_t xdr_single_dtype ();
	#endif /* Old Style C */


	typedef single_dtype object_data;
	#ifdef __cplusplus
		extern "C" bool_t xdr_object_data (XDR *, object_data *);
	#elif __STDC__
		extern bool_t xdr_object_data (XDR *, object_data *);
	#else /* Old Style C */
		bool_t xdr_object_data ();
	#endif /* Old Style C */

	typedef struct
	{
	  u_int return_values_len;
	  object_data *return_values_val;
	}
	return_values;
	#ifdef __cplusplus
		extern "C" bool_t xdr_return_values (XDR *, return_values *);
	#elif __STDC__
		extern bool_t xdr_return_values (XDR *, return_values *);
	#else /* Old Style C */
		bool_t xdr_return_values ();
	#endif /* Old Style C */
	
	
	struct call
	{
	  char *function_name;
	  struct
	  {
		u_int parameters_len;
		object_data *parameters_val;
	  }
	  parameters;
	  struct
	  {
		u_int sizedata_len;
		long *sizedata_val;
	  }
	  sizedata;
	};
	typedef struct call call;
	#ifdef __cplusplus
		extern "C" bool_t xdr_call (XDR *, call *);
	#elif __STDC__
		extern bool_t xdr_call (XDR *, call *);
	#else /* Old Style C */
		bool_t xdr_call ();
	#endif /* Old Style C */


	#define FGL_RPC ((u_long)serviceport)
	#define FGL_RPC_VER ((u_long)1)

	#ifdef __cplusplus
		#define CALL_REMOTE_FUNC ((u_long)1)
		extern "C" return_values * A4GL_call_remote_func_1 (call, CLIENT *);
		extern "C" return_values * A4GL_call_remote_func_1_svc (call, struct svc_req *);

	#elif __STDC__
		#define CALL_REMOTE_FUNC ((u_long)1)
		extern return_values *A4GL_call_remote_func_1 (call, CLIENT *);
		extern return_values *A4GL_call_remote_func_1_svc (call, struct svc_req *);

	#else /* Old Style C */
		#define CALL_REMOTE_FUNC ((u_long)1)
		extern return_values *A4GL_call_remote_func_1 ();
		extern return_values *A4GL_call_remote_func_1_svc ();
	#endif /* Old Style C */

    /* this was in rpc_client.c, not sure why:
       #ifdef WIN32
       #ifndef __CYGWIN__
       return_values *call_remote_func_1(call *argp, CLIENT *clnt);
       #else
       return_values *call_remote_func_1(call argp, CLIENT *clnt);
       #endif
       #else
       return_values *call_remote_func_1(call argp, CLIENT *clnt);
       #endif
     */

	/* rpc_svc.c */

	void A4GL_fgl_rpc_reply (void *result);

#endif /* !_RPC_STACK_H_RPCGEN */

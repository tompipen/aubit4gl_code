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

#include <memory.h> /* for memset */
#include "rpc_stack.h"
#define main server_run
extern unsigned long serviceport;

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

/**
 *
 */
return_values *call_remote_func_1(call arg1,  CLIENT *clnt)
{
	static return_values clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call(clnt, 
			CALL_REMOTE_FUNC, 
			xdr_call, 
			&arg1, 
			xdr_return_values, 
			&clnt_res, TIMEOUT) != RPC_SUCCESS) 
  {
		return (NULL);
	}
	return (&clnt_res);
}



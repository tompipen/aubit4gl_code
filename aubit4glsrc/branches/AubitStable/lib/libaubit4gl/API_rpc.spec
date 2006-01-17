LIBRARY RPC
VARIABLE A4GL_RPCTYPE
LIB_PREFIX A4GLRPC_
/* int A4GL_remote_func_call (char *host, int async, char *funcname, int port, int np) */
/* int A4GL_register_func(char *s,void *ptr)  */
/* int A4GL_unregister_func(char *s,void *ptr)  */
/* int A4GL_server_run(long service)  */


A4GL_remote_func_call char* host  int async  char* funcname  int port  int np  -> int
A4GL_register_func char* s void* ptr   -> int
A4GL_unregister_func char* s    -> int
A4GL_server_run long service   -> int

#ifndef A4GL_RPC_H
#define A4GL_RPC_H

#ifdef __cplusplus
extern "C"
{
#endif

  int A4GLRPC_initlib (void);
  int A4GL_remote_func_call (char *host, int async, char *funcname,
			int port, int np);

#ifdef __cplusplus
}
#endif
#endif

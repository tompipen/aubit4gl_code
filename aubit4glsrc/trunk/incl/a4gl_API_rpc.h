
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

#if (defined(__CYGWIN__)) || defined(__MINGW32__)
	/* missing from rpcgen generated .h on CygWin: */
	#define bool_t int
	#define u_int unsigned int
#endif

#include "npcode.h"
#include <stdio.h>			/* needed for FILE symbol */

#include "rpc/rpc.h" //XDR, XDR_ENCODE XDR_DECODE

void
nullfunc ()
{
// Does nothing ...
}



#ifdef USE_RPC_ONLY

int
process_xdr (char dir, void *s, char *filename)
{
  FILE *fxx;
  //void *libptr;
  //char buff[256];
  XDR xdrp;
  int a;


  /*
     We can only write to the current directory - but we
     can open files from anywhere on the dbpath
   */
  if (dir == 'O')
    {
      fxx = fopen (filename, "wb");
    }
  else
    fxx = (FILE *) fopen (filename, "r");


  if (fxx == 0)
    {
      return 0;
    }


  if (dir == 'O')
    xdrstdio_create (&xdrp, fxx, XDR_ENCODE);
  else
    xdrstdio_create (&xdrp, fxx, XDR_DECODE);


  a = xdr_module (&xdrp, s);
  xdr_destroy (&xdrp);
  fclose (fxx);
  return a;
}
#else

int process_xdr(char dir, void *s,char *filename) {
int a;
if (dir=='O') {
	a = A4GL_write_data_to_file ("module", s, filename);
	if (!a) return 0;
	return 1;
}

if (dir=='I') {
	a = A4GL_read_data_from_file ("module", s, filename);
	if (!a) return 0;
	return 1;
}

return 0;

}
#endif



#ifdef NO_AUBITLIB

int do_compiler_start(int argc,char *argv[]) {
return 1;
}

int A4GL_write_data_to_file(char *t,void *s,char *fname) {
  FILE *fxx;
  XDR xdrp;
  int a;
  fxx = fopen (fname, "wb");
  xdrstdio_create (&xdrp, fxx, XDR_ENCODE);
  a = xdr_module (&xdrp, s);
  xdr_destroy (&xdrp);
  fclose (fxx);
  return a;
}

int A4GL_read_data_from_file(char *t,void *s,char *fname) {
FILE *fxx;
  XDR xdrp;
  int a;
  fxx = (FILE *) fopen (fname, "r");
  xdrstdio_create (&xdrp, fxx, XDR_DECODE);
  a = xdr_module (&xdrp, s);
  xdr_destroy (&xdrp);
  fclose (fxx);
  return a;
}

#else
int do_compiler_start(int argc,char *argv[]) {
return A4GL_fgl_start(argc,argv);
}

#endif

#if (defined(__CYGWIN__)) || defined(__MINGW32__)
	/* missing from rpcgen generated .h on CygWin: */
	#define bool_t int
	#define u_int unsigned int
#endif

#include "npcode.h"
#include <stdio.h>			/* needed for FILE symbol */

#include "rpc/rpc.h" //XDR, XDR_ENCODE XDR_DECODE

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


void
nullfunc ()
{
// Does nothing ...
}

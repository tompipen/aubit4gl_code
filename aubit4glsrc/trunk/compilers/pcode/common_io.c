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
  write_more(s);
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


write_more(struct module *objp) {
  FILE *fxx;
  XDR xdrp;
  int a;

printf("Write more...\n");


  fxx = fopen ("out.string_table", "wb");
  xdrstdio_create (&xdrp, fxx, XDR_ENCODE);
  xdr_array (&xdrp, (char **)&objp->string_table.string_table_val, (u_int *) &objp->string_table.string_table_len, ~0, sizeof (vstring), (xdrproc_t) xdr_vstring);
  xdr_destroy (&xdrp);
  fclose (fxx);

  fxx = fopen ("out.id_table", "wb");
  xdrstdio_create (&xdrp, fxx, XDR_ENCODE);
  xdr_array (&xdrp, (char **)&objp->id_table.id_table_val, (u_int *) &objp->id_table.id_table_len, ~0, sizeof (vstring), (xdrproc_t) xdr_vstring);
  xdr_destroy (&xdrp);
  fclose (fxx);

  fxx = fopen ("out.external_function_table", "wb");
  xdrstdio_create (&xdrp, fxx, XDR_ENCODE);
  xdr_array (&xdrp, (char **)&objp->external_function_table.external_function_table_val, (u_int *) &objp->external_function_table.external_function_table_len, ~0, sizeof (long), (xdrproc_t) xdr_long);
  xdr_destroy (&xdrp);
  fclose (fxx);

	printf("%d functions\n",objp->functions.functions_len);
  fxx = fopen ("out.functions", "wb");
  xdrstdio_create (&xdrp, fxx, XDR_ENCODE);
  xdr_array (&xdrp, (char **)&objp->functions.functions_val, (u_int *) &objp->functions.functions_len, ~0, sizeof (npfunction), (xdrproc_t) xdr_npfunction);
  xdr_destroy (&xdrp);
  fclose (fxx);




  fxx = fopen ("out.params", "wb");
  printf("%d params\n",objp->params.params_len);
  xdrstdio_create (&xdrp, fxx, XDR_ENCODE);
  xdr_array (&xdrp, (char **)&objp->params.params_val, (u_int *) &objp->params.params_len, ~0, sizeof (param), (xdrproc_t) xdr_param);
  xdr_destroy (&xdrp);
  fclose (fxx);


 {
	int a;
	int b;
	char fname[255];
	for (a=0;a<objp->functions.functions_len;a++) {
		for (b=0;b<objp->functions.functions_val[a].cmds.cmds_len;b++) {
			sprintf(fname,"cmds/%04d_%04d_%d.cmd",a,b,objp->functions.functions_val[a].cmds.cmds_val[b].cmd_type);
			printf("Write : %s\n",fname); fflush(stdout);
  			fxx = fopen (fname, "wb");
  			xdrstdio_create (&xdrp, fxx, XDR_ENCODE);
			xdr_cmd (&xdrp, &objp->functions.functions_val[a].cmds.cmds_val[b]);
  			xdr_destroy (&xdrp);
  			fclose (fxx);
		}
	}
 }


}

#else
int do_compiler_start(int argc,char *argv[]) {
return A4GL_fgl_start(argc,argv);
}

#endif

#include <stdio.h>
#include "rpc/rpc.h"

/*
* We don't actually do much in here
* we just use the name of the datatype specified
* to identify the xdr routine to call
* and then - call it...
*/

static int (*func)();
static int process_xdr(char dir,char *name,void *s,char *filename) ;

int A4GLPACKER_initlib (void) {
	return 1;
}

int can_pack_all(char* name) {
	void *libptr;
  	libptr=(void *)dl_openlibrary("XDRPACKER",name);
	if (libptr) return 1;
	return -1;
}



/* 
   We don't need to worry about these two
   as we're doing the whole thing in one go
   using xdr
*/
int open_packer(char *fname,int dir)  { }
int close_packer(int dir) { }




int pack_all(char *name,void *s,char *filename) {
	return process_xdr('O',name,s,filename);
}


int unpack_all(char *name,void *s,char *filename) {
	return process_xdr('I',name,s,filename);
}


static int process_xdr(char dir,char *name,void *s,char *filename) {
FILE *fxx;
void *ptr;
void *libptr;
char buff[256];
XDR xdrp;

sprintf(buff,"xdr_%s",name);

  libptr=(void *)dl_openlibrary("XDRPACKER",name);
  if (libptr==0) return 0;

/* 
   We can only write to the current directory - but we 
   can open files from anywhere on the dbpath
*/
if (dir=='O') 
  fxx = fopen(filename,"wb");
else 
  fxx = (FILE *) open_file_dbpath (filename);


  if (fxx==0) return 0;


if (dir=='O')
  xdrstdio_create(&xdrp, fxx, XDR_ENCODE);
else
  xdrstdio_create(&xdrp, fxx, XDR_DECODE);

  func=(void *)find_func(libptr,buff);
  if (func==0) return 0;

  func(&xdrp,s);

  xdr_destroy(&xdrp);
  fclose(fxx);
  return 1;
}



/**
 * @file
 * The main module for form decompiler
 */

#include <stdio.h>
//#include "form_x.h"
#include "a4gl_formxw.h"

#ifdef __CYGWIN__
	#include <rpc/rpc.h>
#endif


main(int argc,char *argv[]) {
struct struct_form the_form;
FILE *f;
XDR xdrp;
int a;

	if (argc!=2) {
		printf("Usage %s filename\n",argv[0]);
		exit(0);
	}

	f=fopen(argv[1],"rb");

	if (f==0) {
		printf("Unable to open file %s\n",argv[1]);
		exit(2);
	}

	xdrstdio_create(&xdrp,f,XDR_DECODE);
	xdr_int(&xdrp,&a);

	printf("Magic number : %x\n",a);
	rewind(f);


	if (a != FCOMILE_XDR_MAGIC) {
		printf("This does not appear to be a valid form\n(Bad magic number - got %x rather than %x)\n",a,FCOMILE_XDR_MAGIC);
		exit(0);
	}
	memset(&the_form,0,sizeof(struct_form));

	xdrstdio_create(&xdrp,f,XDR_DECODE);


	a=isolated_xdr_struct_form(&xdrp,&the_form); //in lib/libform/form_xdr/formwrite2.c

	if (!a) {
		printf("Bad format\n");
		exit(1);
	}

	if (the_form.fcompile_version!=FCOMILE_XDR_VERSION) {
		printf("Error - fdecompiler is compiled for XDR version %d forms\n",
			FCOMILE_XDR_VERSION);
		printf("This form appears to be version %d\n",the_form.fcompile_version);
		exit(1);
	}


	dump_form_desc(&the_form);

}



/**
 * @file
 * The main module for form decompiler
 */

#include <stdio.h>
#include "form_x.h"

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

	memset(&the_form,0,sizeof(struct_form));

	xdrstdio_create(&xdrp,f,XDR_DECODE);


	a=xdr_struct_form(&xdrp,&the_form);
	if (!a) {
		printf("Bad format\n");
	} else {
		dump_form_desc(&the_form);
	}
}



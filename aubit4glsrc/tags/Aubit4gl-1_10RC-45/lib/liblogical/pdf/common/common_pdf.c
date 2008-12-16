#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../common/a4gl_lle.h"
#include "../common/common_pdf.h"

#define VERSION 3


struct pdf_layout layout;

void pdf_default_file() {
	//printf("default file\n");
	strcpy(layout.fontname,"Courier");
	layout.fontsize		=8;
	layout.leftmargin	=0;
	layout.topmargin	=0;
	layout.paper_type	=PAPER_TYPE_A4;
	layout.paper_orient	=PAPER_ORIENT_AUTO;

	strcpy(layout.img_src,"");
	layout.img_x            =0;
	layout.img_y            =0;
	layout.nfonts=0;
	layout.fonts=0;
}


int pdf_load_file(FILE *fin) {
	int size;
	int ver;
	int ignore_err=0;
	// We don't need to add anything to the output file
	//printf("load file\n");
	fread(&size,4,1,fin);
	fread(&ver,4,1,fin);
	if (A4GL_isyes(acl_getenv("IGNORESIZEERR"))) {
		ignore_err=1;
	}

	if (size!=sizeof(layout)) {
		printf("Incompatible sizes (Old file format ?)...\n");
		if (!ignore_err) { return 0;}
		fread(&layout,size,1,fin);
		layout.fonts=0;
		layout.nfonts=0;
		return 1;
	}

	if (ver!=VERSION) {
		printf("Wrong Version (%d!=%d ?)...\n",ver,VERSION);
		return 0;
	}


	fread(&layout,sizeof(layout),1,fin);

	if (layout.nfonts==0) {
		layout.fonts=0;
	} else {
		int a;
		layout.fonts=malloc(sizeof(struct fonts)*layout.nfonts);
		for (a=0;a<layout.nfonts;a++) {
			fread(&layout.fonts[a],sizeof(struct fonts),1,fin);
		}
	}

	return 1;
}


int pdf_save_file(FILE *fin) {
	int size;
	int ver;
	int a;
	size=sizeof(layout);
	ver=VERSION;
	fwrite(&size,4,1,fin);
	fwrite(&ver,4,1,fin);
	//printf("SAVING Size %d version %d - fontsize : %d\n", size,ver,layout.fontsize);
	fwrite(&layout,sizeof(layout),1,fin);
	for (a=0;a<layout.nfonts;a++) {
		fwrite(&layout.fonts[a],sizeof(struct fonts),1,fin);
	}
	return 1;
}

void msgbox (char *title, char *txt) {

	return ;
}




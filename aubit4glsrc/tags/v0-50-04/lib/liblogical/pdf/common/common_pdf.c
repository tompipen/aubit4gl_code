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
}


int pdf_load_file(FILE *fin) {
	int size;
	int ver;
	// We don't need to add anything to the output file
	//printf("load file\n");
	fread(&size,4,1,fin);
	fread(&ver,4,1,fin);

	if (size!=sizeof(layout)) {
		printf("Incompatible sizes (Old file format ?)...\n");
		return 0;
	}

	if (ver!=VERSION) {
		printf("Wrong Version (%d!=%d ?)...\n",ver,VERSION);
		return 0;
	}

	fread(&layout,sizeof(layout),1,fin);
	//printf("LOADING Size %d version %d - fontsize : %d\n", size,ver,layout.fontsize);
	//printf("Img = %s\n",layout.img_src);
	return 1;
}


int pdf_save_file(FILE *fin) {
	int size;
	int ver;
	size=sizeof(layout);
	ver=VERSION;
	fwrite(&size,4,1,fin);
	fwrite(&ver,4,1,fin);
	//printf("SAVING Size %d version %d - fontsize : %d\n", size,ver,layout.fontsize);
	fwrite(&layout,sizeof(layout),1,fin);
	return 1;
}

void msgbox (char *title, char *txt) {

	return ;
}




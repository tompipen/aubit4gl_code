#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../common/a4gl_lle.h"
#include "../common/common_pdf.h"


struct pdf_layout layout;

void pdf_default_file() {
	strcpy(layout.fontname,"Courier");
	layout.fontsize=8;
	layout.leftmargin=0;
	layout.topmargin=0;
	layout.paper_type	=PAPER_TYPE_A4;
	layout.paper_orient	=PAPER_ORIENT_AUTO;
}


int pdf_load_file(FILE *fin) {
	// We don't need to add anything to the output file
	fread(&layout,sizeof(layout),1,fin);
	return 1;
}


int pdf_save_file(FILE *fin) {
	fwrite(&layout,sizeof(layout),1,fin);
	return 1;
}

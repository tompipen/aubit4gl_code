#include <stdio.h>
#include <stdlib.h>
#include "../common/common_pdf.h"
#include "pdflib.h"


PDF *p=0;
extern struct pdf_layout layout;
int font=-1;

float layout_page_width=-1;
float layout_page_height=-1;


void
output_page (PDF *p, int w, int h,char **lines)
{
  int a; 
  int orient;
  float this_page_width;
  float this_page_height;
  float printable;
  float eachline;

  if (layout_page_width==-1) {
		switch(layout.paper_type) {
			case PAPER_TYPE_A0: 	layout_page_width=a0_width; layout_page_height=a0_height;break;
			case PAPER_TYPE_A1: 	layout_page_width=a1_width; layout_page_height=a1_height;break;
			case PAPER_TYPE_A2: 	layout_page_width=a2_width; layout_page_height=a2_height;break;
			case PAPER_TYPE_A3: 	layout_page_width=a3_width; layout_page_height=a3_height;break;
			case PAPER_TYPE_A4: 	layout_page_width=a4_width; layout_page_height=a4_height;break;
			case PAPER_TYPE_A5: 	layout_page_width=a5_width; layout_page_height=a5_height;break;
			case PAPER_TYPE_A6: 	layout_page_width=a6_width; layout_page_height=a6_height;break;
			case PAPER_TYPE_B5: 	layout_page_width=b5_width; layout_page_height=b5_height;break;
			case PAPER_TYPE_LETTER: layout_page_width=letter_width; layout_page_height=letter_height;break;
			case PAPER_TYPE_LEGAL: 	layout_page_width=legal_width; layout_page_height=legal_height;break;
			case PAPER_TYPE_LEDGER: layout_page_width=ledger_width; layout_page_height=ledger_height;break;
			case PAPER_TYPE_P11x17: layout_page_width=p11x17_width; layout_page_height=p11x17_height;break;
			default : printf("Bad paper size\n");
		}
  }

  if(layout.paper_orient==PAPER_ORIENT_AUTO) {
	if (w<=80) 	orient=PAPER_ORIENT_PORTRAIT;
	else 		orient=PAPER_ORIENT_LANDSCAPE;
  } else {
	orient=layout.paper_orient;
  }

  if(orient==PAPER_ORIENT_PORTRAIT)  { this_page_width =layout_page_width; this_page_height=layout_page_height; }
  if(orient==PAPER_ORIENT_LANDSCAPE) { this_page_height =layout_page_width; this_page_width=layout_page_height; }

  PDF_begin_page(p,this_page_width,this_page_height);

  if (font==-1) {
		A4GL_trim(layout.fontname);
		font=PDF_load_font(p,layout.fontname,0,"host","");
		if (font<0) {
			font=PDF_load_font(p,"Courier",0,"host",""); // Couldn't load there one - so default it..
		}
			
  }

  PDF_setfont(p,font,layout.fontsize);
  printable=this_page_height-(layout.topmargin*72.0);
  eachline=printable/h;
  //printf("Left margin %f\n",layout.leftmargin);
  //printf("Top margin %f\n",layout.topmargin);
  //printf("Printable=%f page height=%f\n",printable,this_page_height);

  for (a = 0; a < h; a++)
    {
	char *ptr;
	ptr=lines[a];
        trim (ptr);
	PDF_set_text_pos(p,(layout.leftmargin *72.0) ,this_page_height-((float)a*eachline)-(layout.topmargin*72.0));
	PDF_show(p,ptr);
    }
    PDF_end_page(p);
}



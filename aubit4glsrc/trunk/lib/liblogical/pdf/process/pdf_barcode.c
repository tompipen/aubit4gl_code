#include "a4gl_libaubit4gl.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "pdflib.h"
//#include "../../common/a4gl_lle.h"
//#include "../../processor/API_process.h"
#include "pdf_barcode.h"

int width;
int height;
double x00;
double y00,fontsize,xscale;
double atx,aty;
int littlebar;
int bigbar;
int even_odd=0; // CODE 25 variable..



static void InitBarPDF39(PDF *p, double xpos, double ypos, double x, double y, double font_size, double barscale) {
width = x ;
height = y;
x00 = xpos ;
//y00 = ytotal - (ypos * 72.0) - height;
y00 =  (ypos ) ;
fontsize = font_size;
xscale = barscale  ;
}

static void InitBarPDF25(PDF *p, double xpos, double ypos, double x, double y, double font_size, double barscale) {
width = x ;
height = y;
x00 = xpos ;
//y00 = ytotal - (ypos * 72.0) - height;
y00 =  (ypos ) ;
fontsize = font_size;
xscale = barscale  ;
}


static void DoRectanglePDF( PDF *p, double atx,double xsize,double aty, float p_page_height) {
double xabs,yabs;
double xabs2,yabs2;
xabs = x00 + (atx * xscale);
yabs = y00;
xabs2 = xsize * xscale;
yabs2 = height;


PDF_setlinewidth( p, 0.000001 );
PDF_rect (p, xabs, p_page_height-yabs, xabs2,height); //xabs2-xabs,p_page_height-(yabs2-yabs));
PDF_fill_stroke (p);
/*
PDF_setlinewidth( p, 0.000001); //xabs-xabs2/2);
PDF_moveto(p, xabs, p_page_height-yabs);
PDF_lineto(p, xabs, p_page_height-yabs+height);
PDF_stroke (p);
*/


}

static void BarCharPDF39(PDF *p, char *mapstring, float p_page_height) {
int x, barsize  ;
for (x=0;x<9;x++) {
   if (mapstring[x]=='0') 
      barsize=littlebar;
   else 
      barsize=bigbar;

   if ((x+1) % 2) DoRectanglePDF(p, atx,barsize,aty, p_page_height );

   atx +=barsize;
}

atx +=  littlebar;       //# gap between each bar code character

}

static void BarChar_25(PDF *p, char *mapstring, float p_page_height) {
        int  x;
	float barsize;
        for (x=0;x<strlen(mapstring);x++) {
                if (mapstring[x]=='0')  {
                         barsize=littlebar;
                } else {
                         barsize=bigbar;
		}

                if (even_odd) { 
                        even_odd = 0;
                        DoRectanglePDF(p, atx,barsize,aty , p_page_height);
                } else {
                        even_odd = 1;
		}
                 atx +=  barsize ;
	}
}

static char *checa_char_25(char c) {
switch (c) {
    case '1':  return "10001";
    case '2':  return "01001";
    case '3':  return "11000";
    case '4':  return "00101";
    case '5':  return "10100";
    case '6':  return "01100";
    case '7':  return "00011";
    case '8':  return "10010";
    case '9':  return "01010";
    case '0':  return "00110";
}
return "00000";
}


static void PutBarsPDF25(PDF *p, char c1,char c2,float p_page_height) {
char t1[200];
char t2[200];
char t[200];
switch (c1) {
	case '(': BarChar_25(p, "0000",p_page_height); return;
	case ')': BarChar_25(p, "100",p_page_height); return;
}
strcpy(t1, checa_char_25(c1));
strcpy(t2, checa_char_25(c2));

if (c2!=' ') {
	t[0]=t1[0];
	t[1]=t2[0];
	t[2]=t1[1];
	t[3]=t2[1];
	t[4]=t1[2];
	t[5]=t2[2];
	t[6]=t1[3];
	t[7]=t2[3];
	t[8]=t1[4];
	t[9]=t2[4];
	t[10]=0;
} else {
	t[0]=t1[0];
	t[1]=t1[1];
	t[2]=t1[2];
	t[3]=t1[3];
	t[4]=t1[4];
	t[5]=0;
}

BarChar_25(p, t,p_page_height);
}



static void PutBarsPDF39(PDF *p, char c,int p_page_height) {
switch (c) {
   case '0': BarCharPDF39(p, "000110100", p_page_height);break;
   case '1': BarCharPDF39(p, "100100001", p_page_height);break;
   case '2': BarCharPDF39(p, "001100001", p_page_height);break;
   case '3': BarCharPDF39(p, "101100000", p_page_height);break;
   case '4': BarCharPDF39(p, "000110001", p_page_height);break;
   case '5': BarCharPDF39(p, "100110000", p_page_height);break;
   case '6': BarCharPDF39(p, "001110000", p_page_height);break;
   case '7': BarCharPDF39(p, "000100101", p_page_height);break;
   case '8': BarCharPDF39(p, "100100100", p_page_height);break;
   case '9': BarCharPDF39(p, "001100100", p_page_height);break;
   case '-': BarCharPDF39(p, "010000101", p_page_height);break;
   case '.': BarCharPDF39(p, "110000100", p_page_height);break;
   case ' ': BarCharPDF39(p, "011000100", p_page_height);break;
   case '+': BarCharPDF39(p, "010001010", p_page_height);break;
   case '%': BarCharPDF39(p, "000101010", p_page_height);break;
   case '$': BarCharPDF39(p, "010101000", p_page_height);break;
   case '/': BarCharPDF39(p, "010100010", p_page_height);break;
   case 'A': BarCharPDF39(p, "100001001", p_page_height);break;
   case 'B': BarCharPDF39(p, "001001001", p_page_height);break;
   case 'C': BarCharPDF39(p, "101001000", p_page_height);break;
   case 'D': BarCharPDF39(p, "000011001", p_page_height);break;
   case 'E': BarCharPDF39(p, "100011000", p_page_height);break;
   case 'F': BarCharPDF39(p, "001011000", p_page_height);break;
   case 'G': BarCharPDF39(p, "000001101", p_page_height);break;
   case 'H': BarCharPDF39(p, "100001100", p_page_height);break;
   case 'I': BarCharPDF39(p, "001001100", p_page_height);break;
   case 'J': BarCharPDF39(p, "000011100", p_page_height);break;
   case 'K': BarCharPDF39(p, "100000011", p_page_height);break;
   case 'L': BarCharPDF39(p, "001000011", p_page_height);break;
   case 'M': BarCharPDF39(p, "101000010", p_page_height);break;
   case 'N': BarCharPDF39(p, "000010011", p_page_height);break;
   case 'O': BarCharPDF39(p, "100010010", p_page_height);break;
   case 'P': BarCharPDF39(p, "001010010", p_page_height);break;
   case 'Q': BarCharPDF39(p, "000000111", p_page_height);break;
   case 'R': BarCharPDF39(p, "100000110", p_page_height);break;
   case 'S': BarCharPDF39(p, "001000110", p_page_height);break;
   case 'T': BarCharPDF39(p, "000010110", p_page_height);break;
   case 'U': BarCharPDF39(p, "110000001", p_page_height);break;
   case 'V': BarCharPDF39(p, "011000001", p_page_height);break;
   case 'W': BarCharPDF39(p, "111000000", p_page_height);break;
   case 'X': BarCharPDF39(p, "010010001", p_page_height);break;
   case 'Y': BarCharPDF39(p, "110010000", p_page_height);break;
   case 'Z': BarCharPDF39(p, "011010000", p_page_height);break;
   default : BarCharPDF39(p, "010010100", p_page_height);break;
}

}

static void PrintCharPDF39(PDF *p, double x, char c, float p_page_height,int incl_text) {
double xabs,yabs;
static char buff[200];
xabs = x00 + (x * xscale);
yabs = y00 + height + (fontsize * 12.0);
	if (incl_text) {
		SPRINTF1(buff,"%c",c);
        	PDF_set_text_pos (p, xabs, p_page_height-y00- (fontsize ));
        	PDF_show (p, buff);
	}


}

static void PrintThisPDF39(PDF *p, char *s,float p_page_height,int incl_text) {
int x;
PutBarsPDF39(p, '*',p_page_height); //   # starting delimiter 

for (x=0; x<strlen(s);x++) {

   PrintCharPDF39(p, atx,s[x],p_page_height,incl_text);
   PutBarsPDF39(p, s[x],p_page_height);
}

PutBarsPDF39(p, '*',p_page_height);   //# ending delimiter 
}


static void PrintThisPDF25(PDF *p, char *s,float p_page_height) {
int x;
char buff[2000]; // Allow some space for a trailing space- needed if its a noneven length
even_odd=1;
PutBarsPDF25(p, '(',0,p_page_height); //   # starting delimiter 
strcpy(buff,s);
strcat(buff," ");

for (x=0; x<strlen(s);x+=2) {
   	PutBarsPDF25(p, buff[x], buff[x+1],p_page_height);
}

PutBarsPDF25(p, ')',0,p_page_height);   //# ending delimiter 
}




static void TermBarPDF25(PDF *p) {
	// Does nothing..
}

static void TermBarPDF39(PDF *p) {
	// Does nothing..
}


// Adapted from : 
// # Filename: bc.4gl
// # Desc    : Barcodes on Laser Printers
// # SCCS    : @(#) bc.4gl 1.1 96/04/18 15:33:10
// # Author  : Ti Lian Hwang (tilh@sin-co.sg.dhl.com)
// # Date    : 04 Oct 95
void generate_barcode(PDF *p, double xpos,double ypos,double x,double y,char *str,float p_page_height,int incl_text) {

double font_size;
int char_length1;
int i;
double bar_length, bar_scale;
char *S;
int codetype=39;
//printf(" generate_barcode(%p, %lf,%lf,%lf,%lf,%s,%f);\n", p, xpos,ypos,x,y,str,p_page_height);

if (A4GL_isyes(acl_getenv("BARCODE25"))) {
	codetype=25;
}

if (A4GL_isyes(acl_getenv("BARCODE39"))) {
	codetype=39;
}

if (codetype==39) {
	littlebar=8;             //# these numbers are arbitrary, as long as the ratio
	bigbar=20;               //# stays between 2:1 and 3:1
	font_size = (y/72.0) * 14.4;    //# 2/10 of height of bar
	aty = (y/72.0) * 14.4;          //# 2/10 of height of bar
	atx = 0;
	char_length1 = 3 * bigbar + 6 * littlebar;
	i=strlen(str) + 2;                                  //# delimiters
	bar_length = char_length1 * i + (i-1) * littlebar;     //# gap
	bar_scale = (x) / bar_length;
	InitBarPDF39(p, xpos,ypos,x,y,font_size,bar_scale);
	// Create an uppercased version
	S=strdup(str);
	a4gl_upshift(S);
	PrintThisPDF39(p, S,p_page_height,incl_text);
	free(S);
	TermBarPDF39(p);
} 

if (codetype==25) {
	littlebar=8;             //# these numbers are arbitrary, as long as the ratio
	bigbar=20;               //# stays between 2:1 and 3:1
	font_size = (y/72.0) * 14.4;    //# 2/10 of height of bar
	aty = (y/72.0) * 14.4;          //# 2/10 of height of bar
	atx = 0;
	char_length1 = 2 * bigbar + 3 * littlebar;
	i=strlen(str) ;                                  //# delimiters
	bar_length = char_length1 * i + 6 * littlebar +1 *bigbar;     //# gap
	bar_scale = (x) / bar_length;
	InitBarPDF25(p, xpos,ypos,x,y,font_size,bar_scale);
	S=strdup(str);
	a4gl_upshift(S);
	PrintThisPDF25(p, S,p_page_height);
	free(S);
	TermBarPDF25(p);
}


}

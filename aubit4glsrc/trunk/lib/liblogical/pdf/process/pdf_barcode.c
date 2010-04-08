#include "a4gl_libaubit4gl.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "pdflib.h"
//#include "../../common/a4gl_lle.h"
//#include "../../processor/API_process.h"
#include "pdf_barcode.h"
int codetype=-1;


#if HAVE_LIBQRENCODE

#include <qrencode.h>
QRcode *QRcode_encodeMask(QRinput *input, int mask);

#endif

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
xscale = barscale;
}


static void InitBarPDF13(PDF *p, double xpos, double ypos, double x, double y, double font_size, double barscale) {
width = x ;
height = y;
x00 = xpos ;
y00 =  (ypos ) ;
fontsize = font_size;
xscale = barscale  ;
}


static void InitBarPDF8(PDF *p, double xpos, double ypos, double x, double y, double font_size, double barscale) {
width = x ;
height = y;
x00 = xpos ;
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


}


static void BarCharPDF39(PDF *p, const char *mapstring, float p_page_height) {
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


static void BarCharPDF13(PDF *p, const char *mapstring, float p_page_height) {
unsigned int  x;
   for (x=0;x<strlen(mapstring);x++) {
      if (mapstring[x]=='1')  {
			DoRectanglePDF(p, atx,littlebar,aty , p_page_height);
			atx += littlebar ;
		} else { 
		atx += bigbar ;
		}
	}
}



static void BarCharPDF8(PDF *p, const char *mapstring, float p_page_height) {
unsigned int  x;
   for (x=0;x<strlen(mapstring);x++) {
      if (mapstring[x]=='1')  {
			DoRectanglePDF(p, atx,littlebar,aty , p_page_height);
			atx +=littlebar;
		} else {
			atx +=littlebar;
		}
	}
}



static void BarChar_25(PDF *p, const char *mapstring, float p_page_height) {
unsigned int  x;
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

static const char *checa_char_25(char c) {
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



static void PutBarsPDF13(PDF *p, char t, char c,int p_page_height) {
	if (t == '0'){
		switch (c){
			case 'B': BarCharPDF13(p, "000000", p_page_height);break;
			case 'S': BarCharPDF13(p, "101", p_page_height);break;
			case 'M': BarCharPDF13(p, "01010", p_page_height);break;
		}
	}
	if (t == 'A'){
		switch (c){
			case '0': BarCharPDF13(p, "0001101", p_page_height);break;
			case '1': BarCharPDF13(p, "0011001", p_page_height);break;
			case '2': BarCharPDF13(p, "0010011", p_page_height);break;
			case '3': BarCharPDF13(p, "0111101", p_page_height);break;
			case '4': BarCharPDF13(p, "0100011", p_page_height);break;
			case '5': BarCharPDF13(p, "0110001", p_page_height);break;
			case '6': BarCharPDF13(p, "0101111", p_page_height);break;
			case '7': BarCharPDF13(p, "0111011", p_page_height);break;
			case '8': BarCharPDF13(p, "0110111", p_page_height);break;
			case '9': BarCharPDF13(p, "0001011", p_page_height);break;
		}
	}
	if (t == 'B'){
		switch (c){
			case '0': BarCharPDF13(p, "0100111", p_page_height);break;
			case '1': BarCharPDF13(p, "0110011", p_page_height);break;
			case '2': BarCharPDF13(p, "0011011", p_page_height);break;
			case '3': BarCharPDF13(p, "0100001", p_page_height);break;
			case '4': BarCharPDF13(p, "0011101", p_page_height);break;
			case '5': BarCharPDF13(p, "0111001", p_page_height);break;
			case '6': BarCharPDF13(p, "0000101", p_page_height);break;
			case '7': BarCharPDF13(p, "0010001", p_page_height);break;
			case '8': BarCharPDF13(p, "0001001", p_page_height);break;
			case '9': BarCharPDF13(p, "0010111", p_page_height);break;
		}
	}
	if (t == 'C'){
		switch (c){
			case '0': BarCharPDF13(p, "1110010", p_page_height);break;
			case '1': BarCharPDF13(p, "1100110", p_page_height);break;
			case '2': BarCharPDF13(p, "1101100", p_page_height);break;
			case '3': BarCharPDF13(p, "1000010", p_page_height);break;
			case '4': BarCharPDF13(p, "1011100", p_page_height);break;
			case '5': BarCharPDF13(p, "1001110", p_page_height);break;
			case '6': BarCharPDF13(p, "1010000", p_page_height);break;
			case '7': BarCharPDF13(p, "1000100", p_page_height);break;
			case '8': BarCharPDF13(p, "1001000", p_page_height);break;
			case '9': BarCharPDF13(p, "1110100", p_page_height);break;
		}
	}
}


static void PutBarsPDF8(PDF *p, char t, char c,int p_page_height) {
	if (t == '0'){
		switch (c){
			case 'S': BarCharPDF8(p, "101", p_page_height);break;
			case 'M': BarCharPDF8(p, "01010", p_page_height);break;
		}
	}
	if (t == 'A'){
		switch (c){
			case '0': BarCharPDF8(p, "0001101", p_page_height);break;
			case '1': BarCharPDF8(p, "0011001", p_page_height);break;
			case '2': BarCharPDF8(p, "0010011", p_page_height);break;
			case '3': BarCharPDF8(p, "0111101", p_page_height);break;
			case '4': BarCharPDF8(p, "0100011", p_page_height);break;
			case '5': BarCharPDF8(p, "0110001", p_page_height);break;
			case '6': BarCharPDF8(p, "0101111", p_page_height);break;
			case '7': BarCharPDF8(p, "0111011", p_page_height);break;
			case '8': BarCharPDF8(p, "0110111", p_page_height);break;
			case '9': BarCharPDF8(p, "0001011", p_page_height);break;
		}
	}
	if (t == 'C'){
		switch (c){
			case '0': BarCharPDF8(p, "1110010", p_page_height);break;
			case '1': BarCharPDF8(p, "1100110", p_page_height);break;
			case '2': BarCharPDF8(p, "1101100", p_page_height);break;
			case '3': BarCharPDF8(p, "1000010", p_page_height);break;
			case '4': BarCharPDF8(p, "1011100", p_page_height);break;
			case '5': BarCharPDF8(p, "1001110", p_page_height);break;
			case '6': BarCharPDF8(p, "1010000", p_page_height);break;
			case '7': BarCharPDF8(p, "1000100", p_page_height);break;
			case '8': BarCharPDF8(p, "1001000", p_page_height);break;
			case '9': BarCharPDF8(p, "1110100", p_page_height);break;
		}
	}
}


static const char  *PutGrpPDF13(char a){
	switch (a) {
		case '0': return "AAAAAACCCCCC";
		case '1': return "AABABBCCCCCC";
		case '2': return "AABBABCCCCCC";
		case '3': return "AABBBACCCCCC";
		case '4': return "ABAABBCCCCCC";
		case '5': return "ABBAABCCCCCC";
		case '6': return "ABBBAACCCCCC";
		case '7': return "ABABABCCCCCC";
		case '8': return "ABABBACCCCCC";
		case '9': return "ABBABACCCCCC";
	}
	return "000000000000";
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


static void PrintCharPDF13(PDF *p, double x, char c, float p_page_height,int incl_text) {
double xabs,yabs;
static char buff[200];
xabs = x00 + (x * xscale);
yabs = y00 + height + (fontsize * 12.0);
 A4GL_assertion(c==0,"C=null");
	if (incl_text) {
		SPRINTF1(buff,"%c",c);
        	PDF_set_text_pos (p, xabs, p_page_height-y00- (fontsize ));
        	PDF_show (p, buff);
	}


}


static void PrintCharPDF8(PDF *p, double x, char c, float p_page_height,int incl_text) {
double xabs,yabs;
static char buff[200];
xabs = x00 + (x * xscale);
yabs = y00 + height + (fontsize * 12.0);
 A4GL_assertion(c==0,"C=null");
	if (incl_text) {
		SPRINTF1(buff,"%c",c);
			PDF_set_text_pos (p, xabs, p_page_height-y00- (fontsize ));
        	PDF_show (p, buff);
	}


}


static void PrintThisPDF39(PDF *p, char *s,float p_page_height,int incl_text) {
unsigned int x;
PutBarsPDF39(p, '*',p_page_height); //   # starting delimiter 

for (x=0; x<strlen(s);x++) {

   PrintCharPDF39(p, atx,s[x],p_page_height,incl_text);
   PutBarsPDF39(p, s[x],p_page_height);
}

PutBarsPDF39(p, '*',p_page_height);   //# ending delimiter 
}


static void PrintThisPDF13(PDF *p, char *sorig,float p_page_height,int incl_text) {
unsigned int x;
char s[200]="              ";                                           
unsigned int z=0;
char t[13];
int a=0;

strcpy(s,sorig);
if (strlen(s)!=12 && strlen(s)!=13) {
	A4GL_exitwith("Invalid barcode");
}

for (a=0;a<12;a++) {
	
	if (s[a]==0) { continue; }
	// Check its a number
	if (s[a]>='0' && s[a]<='9') continue;

	A4GL_exitwith("Invalid character in barcode");
	return;
}


	// Compute the checkbit...
	a=0;
	a+=(s[11]-'0')*3;
	a+=(s[10]-'0')*1;
	a+=(s[9]-'0')*3;
	a+=(s[8]-'0')*1;
	a+=(s[7]-'0')*3;
	a+=(s[6]-'0')*1;
	a+=(s[5]-'0')*3;
	a+=(s[4]-'0')*1;
	a+=(s[3]-'0')*3;
	a+=(s[2]-'0')*1;
	a+=(s[1]-'0')*3;
	a+=(s[0]-'0')*1;
	a=a%10;
	a=10-a;
	if (a==10) a=0;
	s[12]=a+'0';
	s[13]=0;

A4GL_pad_string(s,40);

strcpy(t, PutGrpPDF13(s[0]));

PutBarsPDF13(p,'0', 'B',p_page_height);		// Silent zone
PrintCharPDF13(p, atx,s[z],p_page_height,incl_text);
atx += 7*littlebar ;
height+=5;
PutBarsPDF13(p,'0', 'S',p_page_height-5); //   # starting delimiter
height-=5;
z++;
for (x=1; x<7;x++) {

	PrintCharPDF13(p, atx,s[z],p_page_height,incl_text);
	PutBarsPDF13(p, t[x-1], s[x], p_page_height);
	z++;
}

height+=5;
PutBarsPDF13(p,'0','M',p_page_height-5); //  # delimiter in the middle
height-=5;
PrintCharPDF13(p, atx,s[z],p_page_height,incl_text);
z++;
for (x=7;x<13;x++) {
	PutBarsPDF13(p, t[x-1], s[x], p_page_height);
	PrintCharPDF13(p, atx,s[z],p_page_height,incl_text);
	z++;
}
height+=5;
PutBarsPDF13(p,'0', 'S',p_page_height-5);         //# ending delimiter
PutBarsPDF13(p,'0', 'B',p_page_height);		// Silent zone
}


static void PrintThisPDF8(PDF *p, char *sorig,float p_page_height,int incl_text) {
unsigned int x;
char s[200]="         ";
char t[9];
int a;

strcpy(s,sorig);

if (strlen(s)!=7 && strlen(s)!=8) {
	A4GL_exitwith("Invalid length of barcode");
}

for (a=0;a<7;a++) {
	
	if (s[a]==0) { continue; }
	// Check its a number
	if (s[a]>='0' && s[a]<='9') continue;

	A4GL_exitwith("Invalid character in barcode");
	return;
}


a=0;
	a+=(s[6]-'0')*3;
	a+=(s[5]-'0')*1;
	a+=(s[4]-'0')*3;
	a+=(s[3]-'0')*1;
	a+=(s[2]-'0')*3;
	a+=(s[1]-'0')*1;
	a+=(s[0]-'0')*3;
	a=10-(a%10); if (a==10) a=0;
	s[7]=a+'0';
	s[8]=0;
A4GL_pad_string(s,40);
		
strcpy(t, "AAAACCCC");
height+=5;
PutBarsPDF8(p,'0', 'S',p_page_height-5); //   # starting delimiter
height-=5;
for (x=0; x<8;x++) {
	if (x==4){
		height+=5;
		PutBarsPDF8(p,'0','M',p_page_height-5); //  # delimiter in the middle
		height-=5;
	}

   PrintCharPDF8(p, atx,s[x],p_page_height,incl_text);
	PutBarsPDF8(p, t[x], s[x], p_page_height);
}
height+=5;
PutBarsPDF8(p,'0', 'S',p_page_height-5);   //# ending delimiter
}



static void PrintThisPDF25(PDF *p, const char *s,float p_page_height) {
unsigned int x;
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


static void TermBarPDF13(PDF *p) {
// Does nothing..
}


static void TermBarPDF8(PDF *p) {
// Does nothing..
}




static void setcodetype(void ) {
	if (A4GL_isyes(acl_getenv("BARCODE8"))) {
		codetype=13;
	}
	
	if (A4GL_isyes(acl_getenv("BARCODE13"))) {
		codetype=13;
	}
	
	if (A4GL_isyes(acl_getenv("BARCODE25"))) {
		codetype=25;
	}
	
	if (A4GL_isyes(acl_getenv("BARCODE39"))) {
		codetype=39;
	}
	
	if (A4GL_isyes(acl_getenv("BARCODEQR"))) {
		codetype=99;
	}
	if (codetype==-1) {
		codetype=39;
	}
}


void set_barcode_type(char *s) {
	if (A4GL_aubit_strcasecmp(s,"8")==0 ||  A4GL_aubit_strcasecmp(s,"ean8")==0 || A4GL_aubit_strcasecmp(s,"ean-8")==0) {
		codetype=8;
		return ;
	}
	if (A4GL_aubit_strcasecmp(s,"13")==0 ||  A4GL_aubit_strcasecmp(s,"ean13")==0 || A4GL_aubit_strcasecmp(s,"ean-13")==0) {
		codetype=13;
		return ;
	}
	if (A4GL_aubit_strcasecmp(s,"39")==0) {
		codetype=39;
		return ;
	}
	if (A4GL_aubit_strcasecmp(s,"25")==0) {
		codetype=25;
		return ;
	}
	if (A4GL_aubit_strcasecmp(s,"QR")==0) {
		codetype=99;
		return ;
	}
	A4GL_exitwith("Invalid barcode type");
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

if (codetype==-1) {
	setcodetype();
}




if (codetype==99) {
	generate_qrcode(p,str, xpos, ypos,x ,y, p_page_height) ;
	return ;
}


if (codetype==39) {
	littlebar=8;             //# these numbers are arbitrary, as long as the ratio
	bigbar=20;               //# stays between 2:1 and 3:1
	font_size = (y/72.0) * 14.4;    //# 2/10 of height of bar
	aty = (y/72.0) * 14.4;          //# 2/10 of height of bar
	atx = 0;
	char_length1 = 3 * bigbar + 6 * littlebar;
	i=strlen(str) + 2;                                  //# delimiters
	bar_length = char_length1 * i + (i-1) * littlebar+ (i-1) * littlebar;     //# gap
	bar_scale = (x) / bar_length;
	InitBarPDF39(p, xpos,ypos,x,y,font_size,bar_scale);
	// Create an uppercased version
	S=strdup(str);
	a4gl_upshift(S);
	PrintThisPDF39(p, S,p_page_height,incl_text);
	free(S);
	TermBarPDF39(p);
} 


if (codetype==13) {
	littlebar=8;             //# these numbers are arbitrary, as long as the ratio
	bigbar=12;
	font_size = (y/72.0) * 14.4;    //# 2/10 of height of bar
	aty = (y/72.0) * 14.4;          //# 2/10 of height of bar
	atx = 0;
	char_length1 = 5 * littlebar + 2 * bigbar;;
	i= 12 + 3; //# start, stop, middle delimiters + silent zone
	bar_length = char_length1*i;//(i-1); 
	bar_scale = (x) / bar_length;
	InitBarPDF13(p, xpos,ypos,x,y,font_size,bar_scale);
	S=strdup(str);
	PrintThisPDF13(p, str,p_page_height,incl_text);
	free(S);
	TermBarPDF13(p);
}



if (codetype==8) {
	littlebar=8;             //# these numbers are arbitrary, as long as the ratio
	font_size = (y/72.0) * 14.4;    //# 2/10 of height of bar
	aty = (y/72.0) * 14.4;          //# 2/10 of height of bar
	atx = 0;
	char_length1 = 7 * littlebar;
	i=strlen(str) + 2;    //# start, stop, middle delimiters
	bar_length = char_length1 * (i-1); 
	bar_scale = (x) / bar_length;
	InitBarPDF8(p, xpos,ypos,x,y,font_size,bar_scale);
	S=strdup(str);
	PrintThisPDF8(p, S,p_page_height,incl_text);
	free(S);
	TermBarPDF8(p);
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


#if HAVE_LIBQRENCODE

void
generate_qrcode (PDF * p, char *str, double xpos, double ypos, double pdfwidth, double pdfheight, double p_page_height)
{
  int ret = -1;
  int version = 1;
  QRecLevel level = QR_ECLEVEL_L;
  int mask = -1;
  QRcode *qrcode=NULL;
  QRinput *input = 0;
  int x;
  int y;
//int w;
  unsigned char *pdata;
  double width;
  double width_multiplier;

  input = QRinput_new2 (version, level);
  ret = QRinput_append (input, QR_MODE_8, strlen (str), (unsigned char *) str);
  if (ret < 0)
    goto alldone;
  QRinput_setVersion (input, version);
  QRinput_setErrorCorrectionLevel (input, level);
#ifdef HAVE_LIBQRENCODE_ENCODEMASK
  qrcode = QRcode_encodeMask (input, mask);
#else
  qrcode = QRcode_encodeInput (input);
#endif

  if (qrcode == NULL)
    goto alldone;
  ypos-=pdfheight;


  // Width in 'pixels'
  width = qrcode->width;
  // get a multiplier to get the size for each 'pixel'
  width_multiplier = pdfwidth / width;

  PDF_setlinewidth (p, 0.000001);	// we dont really want a line - so make it really thin ;-)
  pdata = qrcode->data;
  for (y = 0; y < width; y++)
    {
      for (x = 0; x < width; x++)
	{
	  double xd;
	  double yd;
	  xd = xpos + (x * width_multiplier);
	  yd = (y * width_multiplier);

	  if ((*pdata) & 1)
	    {
	      PDF_rect (p, xd, p_page_height - ( ypos + yd) , width_multiplier, width_multiplier);
	    }
	  pdata++;
	}
    }
  PDF_fill_stroke (p);

alldone:;
  if (input) { QRinput_free (input); }
  if (qrcode) { QRcode_free (qrcode); }
  if (ret < 0) { A4GL_exitwith ("Unable to generate QR code"); }
}




#else 
//  HAVE_LIBQRENCODE not defined...
void generate_qrcode(PDF *p,char *str, double xpos,double ypos,double pdfwidth, double pdfheight, double p_page_height )  {
	A4GL_exitwith("Unable to generate QR code");
}

#endif


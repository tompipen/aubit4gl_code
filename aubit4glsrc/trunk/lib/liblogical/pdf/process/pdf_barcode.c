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
int l;
double x00;
double y00,fontsize,xscale;
double atx,aty;
double bar_scale,bar_length;
int char_length1;
int littlebar;
int bigbar;
int even_odd=0; // CODE 25 variable..



static void InitBarPDF128(PDF *p, double xpos, double ypos, double x, double y, double font_size, double barscale) {
width = x ;
height = y;
x00 = xpos ;
y00 =  (ypos ) ;
fontsize = font_size;
xscale = barscale  ;
}




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


static void InitBarPDF5(PDF *p, double xpos, double ypos, double x, double y, double font_size, double barscale) {
width = x ;
height = y;
x00 = xpos ;
y00 =  (ypos ) ;
fontsize = font_size;
xscale = barscale  ;
}

static void InitBarPDF2(PDF *p, double xpos, double ypos, double x, double y, double font_size, double barscale) {
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



static void BarCharPDF128(PDF *p, const char *mapstring, float p_page_height) {
unsigned int  x;
   for (x=0;x<strlen(mapstring);x++) {
      if (mapstring[x]=='1')  {
			DoRectanglePDF(p, atx,littlebar,aty , p_page_height);
			atx += littlebar ;
		} else {
		atx += littlebar ;
		}
	}
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
		atx += littlebar ;
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


static void BarCharPDF5(PDF *p, const char *mapstring, float p_page_height) {
unsigned int  x;
   for (x=0;x<strlen(mapstring);x++) {
      if (mapstring[x]=='1')  {
			DoRectanglePDF(p, atx,littlebar,aty , p_page_height);
			atx += littlebar ;
		} else {
		atx += littlebar ;
		}
	}
}



static void BarCharPDF2(PDF *p, const char *mapstring, float p_page_height) {
unsigned int  x;
   for (x=0;x<strlen(mapstring);x++) {
      if (mapstring[x]=='1')  {
			DoRectanglePDF(p, atx,littlebar,aty , p_page_height);
			atx += littlebar ;
		} else {
		atx += littlebar ;
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




static void PutBarsPDF128(PDF *p, int c,int p_page_height) {
		switch (c){
			case  0: BarCharPDF128(p,"11011001100", p_page_height);break;   //ascii032, ' '
			case  1: BarCharPDF128(p,"11001101100", p_page_height);break;   //ascii033, '!'
			case  2: BarCharPDF128(p,"11001100110", p_page_height);break;   //ascii034, '"'
			case  3: BarCharPDF128(p,"10010011000", p_page_height);break;   //ascii035, '#'
			case  4: BarCharPDF128(p,"10010001100", p_page_height);break;   //ascii036, '$'
			case  5: BarCharPDF128(p,"10001001100", p_page_height);break;   //ascii037, '%'
			case  6: BarCharPDF128(p,"10011001000", p_page_height);break;   //ascii038, '&'
			case  7: BarCharPDF128(p,"10011000100", p_page_height);break;   //ascii039, '´'
			case  8: BarCharPDF128(p,"10001100100", p_page_height);break;   //ascii040, '('
			case  9: BarCharPDF128(p,"11001001000", p_page_height);break;   //ascii041, ')'
			case  10: BarCharPDF128(p,"11001000100", p_page_height);break;  //ascii042, '*'
			case  11: BarCharPDF128(p,"11000100100", p_page_height);break;  //ascii043, '+'
			case  12: BarCharPDF128(p,"10110011100", p_page_height);break;  //ascii044, ','
			case  13: BarCharPDF128(p,"10011011100", p_page_height);break;  //ascii045, '-'
			case  14: BarCharPDF128(p,"10011001110", p_page_height);break;  //ascii046, '.'
			case  15: BarCharPDF128(p,"10111001100", p_page_height);break;  //ascii047, '/'
			case  16: BarCharPDF128(p,"10011101100", p_page_height);break;  //ascii048, '0'
			case  17: BarCharPDF128(p,"10011100110", p_page_height);break;  //ascii049, '1'
			case  18: BarCharPDF128(p,"11001110010", p_page_height);break;  //ascii050, '2'
			case  19: BarCharPDF128(p,"11001011100", p_page_height);break;  //ascii051, '3'
			case  20: BarCharPDF128(p,"11001001110", p_page_height);break;  //ascii052, '4'
			case  21: BarCharPDF128(p,"11011100100", p_page_height);break;  //ascii053, '5'
			case  22: BarCharPDF128(p,"11001110100", p_page_height);break;  //ascii054, '6'
			case  23: BarCharPDF128(p,"11101101110", p_page_height);break;  //ascii055, '7'
			case  24: BarCharPDF128(p,"11101001100", p_page_height);break;  //ascii056, '8'
			case  25: BarCharPDF128(p,"11100101100", p_page_height);break;  //ascii057, '9'
			case  26: BarCharPDF128(p,"11100100110", p_page_height);break;  //ascii058, ':'
			case  27: BarCharPDF128(p,"11101100100", p_page_height);break;  //ascii059, ';'
			case  28: BarCharPDF128(p,"11100110100", p_page_height);break;  //ascii060, '<'
			case  29: BarCharPDF128(p,"11100110010", p_page_height);break;  //ascii061, '='
			case  30: BarCharPDF128(p,"11011011000", p_page_height);break;  //ascii062, '>'
			case  31: BarCharPDF128(p,"11011000110", p_page_height);break;  //ascii063, '?'
			case  32: BarCharPDF128(p,"11000110110", p_page_height);break;  //ascii064, '@'
			case  33: BarCharPDF128(p,"10100011000", p_page_height);break;  //ascii065, 'A'
			case  34: BarCharPDF128(p,"10001011000", p_page_height);break;  //ascii066, 'B'
			case  35: BarCharPDF128(p,"10001000110", p_page_height);break;  //ascii067, 'C'
			case  36: BarCharPDF128(p,"10110001000", p_page_height);break;  //ascii068, 'D'
			case  37: BarCharPDF128(p,"10001101000", p_page_height);break;  //ascii069, 'E'
			case  38: BarCharPDF128(p,"10001100010", p_page_height);break;  //ascii070, 'F'
			case  39: BarCharPDF128(p,"11010001000", p_page_height);break;  //ascii071, 'G'
			case  40: BarCharPDF128(p,"11000101000", p_page_height);break;  //ascii072, 'H'
			case  41: BarCharPDF128(p,"11000100010", p_page_height);break;  //ascii073, 'I'
			case  42: BarCharPDF128(p,"10110111000", p_page_height);break;  //ascii074, 'J'
			case  43: BarCharPDF128(p,"10110001110", p_page_height);break;  //ascii075, 'K'
			case  44: BarCharPDF128(p,"10001101110", p_page_height);break;  //ascii076, 'L'
			case  45: BarCharPDF128(p,"10111011000", p_page_height);break;  //ascii077, 'M'
			case  46: BarCharPDF128(p,"10111000110", p_page_height);break;  //ascii078, 'N'
			case  47: BarCharPDF128(p,"10001110110", p_page_height);break;  //ascii079, 'O'
			case  48: BarCharPDF128(p,"11101110110", p_page_height);break;  //ascii080, 'P'
			case  49: BarCharPDF128(p,"11010001110", p_page_height);break;  //ascii081, 'Q'
			case  50: BarCharPDF128(p,"11000101110", p_page_height);break;  //ascii082, 'R'
			case  51: BarCharPDF128(p,"11011101000", p_page_height);break;  //ascii083, 'S'
			case  52: BarCharPDF128(p,"11011100010", p_page_height);break;  //ascii084, 'T'
			case  53: BarCharPDF128(p,"11011101110", p_page_height);break;  //ascii085, 'U'
			case  54: BarCharPDF128(p,"11101011000", p_page_height);break;  //ascii086, 'V'
			case  55: BarCharPDF128(p,"11101000110", p_page_height);break;  //ascii087, 'W'
			case  56: BarCharPDF128(p,"11100010110", p_page_height);break;  //ascii088, 'X'
			case  57: BarCharPDF128(p,"11101101000", p_page_height);break;  //ascii089, 'Y'
			case  58: BarCharPDF128(p,"11101100010", p_page_height);break;  //ascii090, 'Z'
			case  59: BarCharPDF128(p,"11100011010", p_page_height);break;  //ascii091, '['
			case  60: BarCharPDF128(p,"11101111010", p_page_height);break;  //ascii092, '\'
			case  61: BarCharPDF128(p,"11001000010", p_page_height);break;  //ascii093, ']'
			case  62: BarCharPDF128(p,"11110001010", p_page_height);break;  //ascii094, '^'
			case  63: BarCharPDF128(p,"10100110000", p_page_height);break;  //ascii095, '_'
			case  64: BarCharPDF128(p,"10100001100", p_page_height);break;  //ascii096, '`'
			case  65: BarCharPDF128(p,"10010110000", p_page_height);break;  //ascii097, 'a'
			case  66: BarCharPDF128(p,"10010000110", p_page_height);break;  //ascii098, 'b'
			case  67: BarCharPDF128(p,"10000101100", p_page_height);break;  //ascii099, 'c'
			case  68: BarCharPDF128(p,"10000100110", p_page_height);break;  //ascii100, 'd'
			case  69: BarCharPDF128(p,"10110010000", p_page_height);break;  //ascii101, 'e'
			case  70: BarCharPDF128(p,"10110000100", p_page_height);break;  //ascii102, 'f'
			case  71: BarCharPDF128(p,"10011010000", p_page_height);break;  //ascii103, 'g'
			case  72: BarCharPDF128(p,"10011000010", p_page_height);break;  //ascii104, 'h'
			case  73: BarCharPDF128(p,"10000110100", p_page_height);break;  //ascii105, 'i'
			case  74: BarCharPDF128(p,"10000110010", p_page_height);break;  //ascii106, 'j'
			case  75: BarCharPDF128(p,"11000010010", p_page_height);break;  //ascii107, 'k'
			case  76: BarCharPDF128(p,"11001010000", p_page_height);break;  //ascii108, 'l'
			case  77: BarCharPDF128(p,"11110111010", p_page_height);break;  //ascii109, 'm'
			case  78: BarCharPDF128(p,"11000010100", p_page_height);break;  //ascii110, 'n'
			case  79: BarCharPDF128(p,"10001111010", p_page_height);break;  //ascii111, 'p'
			case  80: BarCharPDF128(p,"10100111100", p_page_height);break;  //ascii112, 'p'
			case  81: BarCharPDF128(p,"10010111100", p_page_height);break;  //ascii113, 'q'
			case  82: BarCharPDF128(p,"10010011110", p_page_height);break;  //ascii114, 'r'
			case  83: BarCharPDF128(p,"10111100100", p_page_height);break;  //ascii115, 's'
			case  84: BarCharPDF128(p,"10011110100", p_page_height);break;  //ascii116, 't'
			case  85: BarCharPDF128(p,"10011110010", p_page_height);break;  //ascii117, 'u'
			case  86: BarCharPDF128(p,"11110100100", p_page_height);break;  //ascii118, 'v'
			case  87: BarCharPDF128(p,"11110010100", p_page_height);break;  //ascii119, 'w'
			case  88: BarCharPDF128(p,"11110010010", p_page_height);break;  //ascii120, 'x'
			case  89: BarCharPDF128(p,"11011011110", p_page_height);break;  //ascii121, 'y'
			case  90: BarCharPDF128(p,"11011110110", p_page_height);break;  //ascii122, 'z'
			case  91: BarCharPDF128(p,"11110110110", p_page_height);break;  //ascii123, '{'
			case  92: BarCharPDF128(p,"10101111000", p_page_height);break;  //ascii124, '|'
			case  93: BarCharPDF128(p,"10100011110", p_page_height);break;  //ascii125, '}'
			case  94: BarCharPDF128(p,"10001011110", p_page_height);break;  //ascii126, '~'
			case  95: BarCharPDF128(p,"10111101000", p_page_height);break;  //ascii200, del
			case  96: BarCharPDF128(p,"10111100010", p_page_height);break;  //ascii201, Fnc 3
			case  97: BarCharPDF128(p,"11110101000", p_page_height);break;  //ascii202, Fnc 2
			case  98: BarCharPDF128(p,"11110100010", p_page_height);break;  //ascii203, Shift
			case  99: BarCharPDF128(p,"10111011110", p_page_height);break;  //ascii204, Code C
			case 100: BarCharPDF128(p,"10111101110", p_page_height);break;  //ascii205  Code B
			case 101: BarCharPDF128(p,"11101011110", p_page_height);break;  //ascii206, Code A
			case 102: BarCharPDF128(p,"11110101110", p_page_height);break;  //ascii207, Fnc 1
			case 103: BarCharPDF128(p,"11010000100", p_page_height);break;  //Start, Code A
			case 104: BarCharPDF128(p,"11010010000", p_page_height);break;  //Start, Code B
			case 105: BarCharPDF128(p,"11010011100", p_page_height);break;  //Start, Code C
			case 106: BarCharPDF128(p,"1100011101011", p_page_height);break;//Stop, Code A,B,C
			case 107: BarCharPDF128(p,"00000", p_page_height);break;        //silent zone
		}
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
			case 'B': BarCharPDF13(p, "00000", p_page_height);break;
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



static void PutBarsPDF5(PDF *p, char t, char c,int p_page_height) {
	if (t == '0'){
		switch (c){
			case 'B': BarCharPDF5(p, "00000", p_page_height);break;
			case 'S': BarCharPDF5(p, "01011", p_page_height);break;
			case 'M': BarCharPDF5(p, "01", p_page_height);break;
		}
	}
	if (t == 'A'){
		switch (c){
			case '0': BarCharPDF5(p, "0001101", p_page_height);break;
			case '1': BarCharPDF5(p, "0011001", p_page_height);break;
			case '2': BarCharPDF5(p, "0010011", p_page_height);break;
			case '3': BarCharPDF5(p, "0111101", p_page_height);break;
			case '4': BarCharPDF5(p, "0100011", p_page_height);break;
			case '5': BarCharPDF5(p, "0110001", p_page_height);break;
			case '6': BarCharPDF5(p, "0101111", p_page_height);break;
			case '7': BarCharPDF5(p, "0111011", p_page_height);break;
			case '8': BarCharPDF5(p, "0110111", p_page_height);break;
			case '9': BarCharPDF5(p, "0001011", p_page_height);break;
		}
	}
	if (t == 'B'){
		switch (c){
			case '0': BarCharPDF5(p, "0100111", p_page_height);break;
			case '1': BarCharPDF5(p, "0110011", p_page_height);break;
			case '2': BarCharPDF5(p, "0011011", p_page_height);break;
			case '3': BarCharPDF5(p, "0100001", p_page_height);break;
			case '4': BarCharPDF5(p, "0011101", p_page_height);break;
			case '5': BarCharPDF5(p, "0111001", p_page_height);break;
			case '6': BarCharPDF5(p, "0000101", p_page_height);break;
			case '7': BarCharPDF5(p, "0010001", p_page_height);break;
			case '8': BarCharPDF5(p, "0001001", p_page_height);break;
			case '9': BarCharPDF5(p, "0010111", p_page_height);break;
		}
	}
}



static void PutBarsPDF2(PDF *p, char t, char c,int p_page_height) {
	if (t == '0'){
		switch (c){
			case 'B': BarCharPDF2(p, "00000", p_page_height);break;
			case 'S': BarCharPDF2(p, "01011", p_page_height);break;
			case 'M': BarCharPDF2(p, "01", p_page_height);break;
		}
	}
	if (t == 'A'){
		switch (c){
			case '0': BarCharPDF2(p, "0001101", p_page_height);break;
			case '1': BarCharPDF2(p, "0011001", p_page_height);break;
			case '2': BarCharPDF2(p, "0010011", p_page_height);break;
			case '3': BarCharPDF2(p, "0111101", p_page_height);break;
			case '4': BarCharPDF2(p, "0100011", p_page_height);break;
			case '5': BarCharPDF2(p, "0110001", p_page_height);break;
			case '6': BarCharPDF2(p, "0101111", p_page_height);break;
			case '7': BarCharPDF2(p, "0111011", p_page_height);break;
			case '8': BarCharPDF2(p, "0110111", p_page_height);break;
			case '9': BarCharPDF2(p, "0001011", p_page_height);break;
		}
	}
	if (t == 'B'){
		switch (c){
			case '0': BarCharPDF2(p, "0100111", p_page_height);break;
			case '1': BarCharPDF2(p, "0110011", p_page_height);break;
			case '2': BarCharPDF2(p, "0011011", p_page_height);break;
			case '3': BarCharPDF2(p, "0100001", p_page_height);break;
			case '4': BarCharPDF2(p, "0011101", p_page_height);break;
			case '5': BarCharPDF2(p, "0111001", p_page_height);break;
			case '6': BarCharPDF2(p, "0000101", p_page_height);break;
			case '7': BarCharPDF2(p, "0010001", p_page_height);break;
			case '8': BarCharPDF2(p, "0001001", p_page_height);break;
			case '9': BarCharPDF2(p, "0010111", p_page_height);break;
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


static const char  *PutGrpPDF2(char a){
	switch (a) {
		case '0': return "AA";
		case '1': return "AB";
		case '2': return "BA";
		case '3': return "BB";
	}
	return "00";
}


static const char  *PutGrpPDF5(char a){
	switch (a) {
		case '0': return "BBAAA";
		case '1': return "BABAA";
		case '2': return "BAABA";
		case '3': return "BAAAB";
		case '4': return "ABBAA";
		case '5': return "AABBA";
		case '6': return "AAABB";
		case '7': return "ABABA";
		case '8': return "ABAAB";
		case '9': return "AABAB";
	}
	return "00000";
}


static void PrintCharPDF128(PDF *p, double x, char c, float p_page_height,int incl_text) {
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



static void PrintCharPDF5(PDF *p, double x, char c, float p_page_height,int incl_text) {
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


static void PrintCharPDF2(PDF *p, double x, char c, float p_page_height,int incl_text) {
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



static void PrintThisPDF128A(PDF *p, char *sorig,float p_page_height,int incl_text) {
int i;
int x;
int y;
int z;
int s[200];
int s2[200];
char si[200]="                                                     ";
char t[200]="                                                      ";
int a=0;
int b=0;
int d=0;
int f=0;
int g=0;
int res;
double atz=0;

	strcpy(si,sorig);

	if (l>48) {
		A4GL_exitwith("Invalid barcode");
		return;
	}

	for (a=0;a<l;a++) {

		if (si[a]==0) { continue; }
			// Check sign
		if (si[a]>=' ' && si[a]<='~') { continue; }
		  A4GL_exitwith("Invalid character in barcode");
		return;
	}


	i=0;
	x=0;
	while (i < l){
		if(si[i]=='~'){
			s[x]=0;
			s[x]+= (si[++i]-'0')*100;
			s[x]+= (si[++i]-'0')*10;
			s[x]+= (si[++i]-'0');
			i++;
			x++;
		}
		else{
			s[x]=si[i];
			d++;
			i++;
			x++;
		}
	}


	i=0;
	z=0;
	y=0;
	while(i<x){
		switch(s[i]){
			case 200:{i++; z++;} break;   //del, ascii200
			case 201:{i++; z++;} break;   //Fnc3, ascii201
			case 202:{i++; z++;} break;   //Fnc2, ascii202
			case 203:{i++; z++;} break;   //Shift, ascii203
			case 204:{i++; z++;} break;   //Code C ascii204
			case 205:{i++; z++;} break;   //Code B, ascii205
			case 206:{i++; z++;} break;   //Code A, ascii206
			case 207:{i++; z++;} break;   //Fnc 1, ascii207
			case 212:{t[y] = '(';         //~212
								y++;
								i++;
								for(z=0;z<2;z++){
									t[y]=(char)s[i];
									y++;
									i++;
								}
								t[y] = ')';
								y++;
							 } break;
			case 213:{t[y] = '(';         //~213
								y++;
								i++;
								for(z=0;z<3;z++){
									t[y]=(char)s[i];
									y++;
									i++;
								}
								t[y] = ')';
								y++;
							 } break;
			case 214:{t[y] = '(';         //~214
								y++;
								i++;
								for(z=0;z<4;z++){
									t[y]=(char)s[i];
									y++;
									i++;
								}
								t[y] = ')';
								y++;
							 } break;
			case 215:{t[y] = '(';         //~215
								y++;
								i++;
								for(z=0;z<5;z++){
									t[y]=(char)s[i];
									y++;
									i++;
								}
								t[y] = ')';
								y++;
							 } break;
			default: {t[y]=(char)s[i];
								y++;
								i++;
							 } break;
		}
	}
	f=y;

	res = 1;
	for(a=0;a<=x;a++){
		switch(s[a]){
			case 205:res = 2; break;
			case 204:res = 3; break;
			default: break;
		}
	}
	switch(res){
		case 1:{i=0;                                 // code a
						x=0;
						while (i < l){
							if(si[i]=='~'){
								s2[x]=0;
								s2[x]+=(si[++i]-'0')*100;
								s2[x]+=(si[++i]-'0')*10;
								s2[x]+=((si[++i]-'0') - 105);
								if(s2[x] > 106){
									switch(s2[x - 1]){
										case 99: {x--;
															s2[x]=102;
															x++;
															s2[x]=99;
														 } break;
										case 100:{x--;
															s2[x]=102;
															x++;
															s2[x]=100;
														 } break;
										case 101:{x--;
															s2[x]=102;
															x++;
															s2[x]=101;
														 } break;
									}
								}
								i++;
								x++;
								}
								else{
									if(si[i]<=95){
										s2[x]=(si[i] - 32);
										i++;
									x++;
									}
									else{
										s2[x]=(si[i] - 64);
										i++;
										x++;
									}
								}
						}
						b=x;
				  } break;

		case 2:{i=0;                                 //code b
						x=0;
						while (i < l){
							if(si[i]=='~'){
								s2[x]=0;
								s2[x]+=(si[++i]-'0')*100;
								s2[x]+=(si[++i]-'0')*10;
								s2[x]+=((si[++i]-'0') - 105);
								if(s2[x] > 106){
									switch(s2[x - 1]){
										case 99: {x--;
															s2[x]=102;
															x++;
															s2[x]=99;
														 } break;
										case 100:{x--;
															s2[x]=102;
															x++;
															s2[x]=100;
														 } break;
										case 101:{x--;
															s2[x]=102;
															x++;
															s2[x]=101;
														 } break;
									}
								}
								i++;
								x++;
							}
							else{
								s2[x]=si[i] - 32;
								i++;
								x++;
							}
						}
						b=x;
					} break;

		case 3: {i=0;                                //code c
							bar_length = char_length1*i/2;
							bar_scale = (x) / bar_length;
							x=0;
							if((d%2)==1){
								strcat(si,"0");
							}
							while (i < l){
								if(si[i]=='~'){
									s2[x]=0;
									s2[x]+=(si[++i]-'0')*100;
									s2[x]+=(si[++i]-'0')*10;
									s2[x]+=((si[++i]-'0') - 105);
									if(s2[x] > 106){
										switch(s2[x - 1]){
											case 99: {x--;
																s2[x]=102;
																x++;
																s2[x]=99;
															 } break;
											case 100:{x--;
																s2[x]=102;
																x++;
																s2[x]=100;
															 } break;
											case 101:{x--;
																s2[x]=102;
																x++;
																s2[x]=101;
															 } break;
										}
									}
									i++;
									x++;
								}
								else{
									s2[x]=0;
									s2[x]+=(si[i]-'0')*10;
									s2[x]+=(si[++i]-'0');
									i++;
									x++;
								}
						}
						b=x;
				  } break;
	}


	// Compute the checkbit...
	a=0;
	for (i=0; i<x; ++i){
		a+=(s2[i])*(i+1);
	}

	s2[x]=(a+103)%103;


	A4GL_pad_string(t,60);
	g=(int)((bar_length / f) / 11);

	if(g>11){
		g=11;
	}
	if(res==3){
		g=5;
	}

	PutBarsPDF128(p, 107, p_page_height);     // Silent zone
	PutBarsPDF128(p, 103, p_page_height);     // Start, Code A
	atz+=11*littlebar;
	if(b>=f){
		for (i=0; i<=b;i++) {
			if(t[i]=='('){
				atz+=4*littlebar;
			}
			PrintCharPDF128(p, atz,t[i],p_page_height,incl_text);
			if(t[i]==')'){
				atz+=4*littlebar;
			}
			atz+=g*littlebar;
			PutBarsPDF128(p, s2[i], p_page_height);
		}
	}
	else{
		for (i=0; i<=f;i++) {
			if (b>=i){
				if(t[i]=='('){
					atz+=4*littlebar;
				}
				PrintCharPDF128(p, atz,t[i],p_page_height,incl_text);
				if(t[i]==')'){
					atz+=4*littlebar;
				}
				atz+=g*littlebar;
				PutBarsPDF128(p, s2[i], p_page_height);
			}
			if (b<i){
				if(t[i]=='('){
					atz+=4*littlebar;
				}
				PrintCharPDF128(p, atz,t[i],p_page_height,incl_text);
				if(t[i]==')'){
					atz+=4*littlebar;
				}
				atz+=g*littlebar;
			}
		}
	}
	PutBarsPDF128(p, 106, p_page_height);   // Stop
	PutBarsPDF128(p, 107, p_page_height);   // Silent zone
}



static void PrintThisPDF128B(PDF *p, char *sorig,float p_page_height,int incl_text) {
int i;
int x;
int y;
int z;
int s[200];
int s2[200];
char si[200]="                                                     ";
char t[200]="                                                      ";
int a=0;
int b=0;
int d=0;
int f=0;
int g=0;
int res;
double atz=0;

	strcpy(si,sorig);
	
	if (l>48) {
		A4GL_exitwith("Invalid barcode");
		return;
	}

	for (a=0;a<l;a++) {

		if (si[a]==0) { continue; }
			// Check sign
		if (si[a]>=' ' && si[a]<='~') { continue; }
		  A4GL_exitwith("Invalid character in barcode");
		return;
	}


	i=0;
	x=0;
	while (i < l){
		if(si[i]=='~'){
			s[x]=0;
			s[x]+= (si[++i]-'0')*100;
			s[x]+= (si[++i]-'0')*10;
			s[x]+= (si[++i]-'0');
			i++;
			x++;
		}
		else{
			s[x]=si[i];
			d++;
			i++;
			x++;
		}
	}


	i=0;
	z=0;
	y=0;
	while(i<x){
		switch(s[i]){
			case 200:{i++; z++;} break;   //del, ascii200
			case 201:{i++; z++;} break;   //Fnc3, ascii201
			case 202:{i++; z++;} break;   //Fnc2, ascii202
			case 203:{i++; z++;} break;   //Shift, ascii203
			case 204:{i++; z++;} break;   //Code C ascii204
			case 205:{i++; z++;} break;   //Code B, ascii205
			case 206:{i++; z++;} break;   //Code A, ascii206
			case 207:{i++; z++;} break;   //Fnc 1, ascii207
			case 212:{t[y] = '(';         //~212
								y++;
								i++;
								for(z=0;z<2;z++){
									t[y]=(char)s[i];
									y++;
									i++;
								}
								t[y] = ')';
								y++;
							 } break;
			case 213:{t[y] = '(';         //~213
								y++;
								i++;
								for(z=0;z<3;z++){
									t[y]=(char)s[i];
									y++;
									i++;
								}
								t[y] = ')';
								y++;
							 } break;
			case 214:{t[y] = '(';         //~214
								y++;
								i++;
								for(z=0;z<4;z++){
									t[y]=(char)s[i];
									y++;
									i++;
								}
								t[y] = ')';
								y++;
							 } break;
			case 215:{t[y] = '(';         //~215
								y++;
								i++;
								for(z=0;z<5;z++){
									t[y]=(char)s[i];
									y++;
									i++;
								}
								t[y] = ')';
								y++;
							 } break;
			default: {t[y]=(char)s[i];
								y++;
								i++;
							 } break;
		}
	}
	f=y;

	res = 2;
	for(a=0;a<=x;a++){
		switch(s[a]){
			case 206:res = 1; break;
			case 204:res = 3; break;
			default: break;
		}
	}
	switch(res){
		case 1:{i=0;                                 // code a
						x=0;
						while (i < l){
							if(si[i]=='~'){
								s2[x]=0;
								s2[x]+=(si[++i]-'0')*100;
								s2[x]+=(si[++i]-'0')*10;
								s2[x]+=((si[++i]-'0') - 105);
								if(s2[x] > 106){
									switch(s2[x - 1]){
										case 99: {x--;
															s2[x]=102;
															x++;
															s2[x]=99;
														 } break;
										case 100:{x--;
															s2[x]=102;
															x++;
															s2[x]=100;
														 } break;
										case 101:{x--;
															s2[x]=102;
															x++;
															s2[x]=101;
														 } break;
									}
								}
								i++;
								x++;
								}
								else{
									if(si[i]<=95){
										s2[x]=(si[i] - 32);
										i++;
									x++;
									}
									else{
										s2[x]=(si[i] - 64);
										i++;
										x++;
									}
								}
						}
						b=x;
				  } break;

		case 2:{i=0;                                 //code b
						x=0;
						while (i < l){
							if(si[i]=='~'){
								s2[x]=0;
								s2[x]+=(si[++i]-'0')*100;
								s2[x]+=(si[++i]-'0')*10;
								s2[x]+=((si[++i]-'0') - 105);
								if(s2[x] > 106){
									switch(s2[x - 1]){
										case 99: {x--;
															s2[x]=102;
															x++;
															s2[x]=99;
														 } break;
										case 100:{x--;
															s2[x]=102;
															x++;
															s2[x]=100;
														 } break;
										case 101:{x--;
															s2[x]=102;
															x++;
															s2[x]=101;
														 } break;
									}
								}
								i++;
								x++;
							}
							else{
								s2[x]=si[i] - 32;
								i++;
								x++;
							}
						}
						b=x;
					} break;

		case 3: {i=0;                                //code c
							bar_length = char_length1*i/2;
							bar_scale = (x) / bar_length;
							x=0;
							if((d%2)==1){
								strcat(si,"0");
							}
							while (i < l){
								if(si[i]=='~'){
									s2[x]=0;
									s2[x]+=(si[++i]-'0')*100;
									s2[x]+=(si[++i]-'0')*10;
									s2[x]+=((si[++i]-'0') - 105);
									if(s2[x] > 106){
										switch(s2[x - 1]){
											case 99: {x--;
																s2[x]=102;
																x++;
																s2[x]=99;
															 } break;
											case 100:{x--;
																s2[x]=102;
																x++;
																s2[x]=100;
															 } break;
											case 101:{x--;
																s2[x]=102;
																x++;
																s2[x]=101;
															 } break;
										}
									}
									i++;
									x++;
								}
								else{
									s2[x]=0;
									s2[x]+=(si[i]-'0')*10;
									s2[x]+=(si[++i]-'0');
									i++;
									x++;
								}
						}
						b=x;
				  } break;
	}


	// Compute the checkbit...
	a=0;
	for (i=0; i<x; ++i){
		a+=(s2[i])*(i+1);
	}
	
	s2[x]=(a+104)%103;


	A4GL_pad_string(t,60);
	g=(int)((bar_length / f) / 11);

	if(g>11){
		g=11;
	}
	if(res==3){
		g=5;
	}

	PutBarsPDF128(p, 107, p_page_height);     // Silent zone
	PutBarsPDF128(p, 104, p_page_height);     // Start, Code B
	atz+=11*littlebar;
	if(b>=f){
		for (i=0; i<=b;i++) {
			if(t[i]=='('){
				atz+=4*littlebar;
			}
			PrintCharPDF128(p, atz,t[i],p_page_height,incl_text);
			if(t[i]==')'){
				atz+=4*littlebar;
			}
			atz+=g*littlebar;
			PutBarsPDF128(p, s2[i], p_page_height);
		}
	}
	else{
		for (i=0; i<=f;i++) {
			if (b>=i){
				if(t[i]=='('){
					atz+=4*littlebar;
				}
				PrintCharPDF128(p, atz,t[i],p_page_height,incl_text);
				if(t[i]==')'){
					atz+=4*littlebar;
				}
				atz+=g*littlebar;
				PutBarsPDF128(p, s2[i], p_page_height);
			}
			if (b<i){
				if(t[i]=='('){
					atz+=4*littlebar;
				}
				PrintCharPDF128(p, atz,t[i],p_page_height,incl_text);
				if(t[i]==')'){
					atz+=4*littlebar;
				}
				atz+=g*littlebar;
			}
		}
	}
	PutBarsPDF128(p, 106, p_page_height);   // Stop
	PutBarsPDF128(p, 107, p_page_height);   // Silent zone
}


static void PrintThisPDF128C(PDF *p, char *sorig,float p_page_height,int incl_text) {
int i;
int x;
int y;
int z;
int s[200];
int s2[200];
char si[200]="                                                     ";
char t[200]="                                                      ";
int a=0;
int b=0;
int d=0;
int f=0;
int g=0;
int res;
double atz=0;

	strcpy(si,sorig);

	if (l>48) {
		A4GL_exitwith("Invalid barcode");
		return;
	}

	for (a=0;a<l;a++) {

		if (si[a]==0) { continue; }
			// Check sign
		if (si[a]>=' ' && si[a]<='~') { continue; }
		  A4GL_exitwith("Invalid character in barcode");
		return;
	}


	i=0;
	x=0;
	while (i < l){
		if(si[i]=='~'){
			s[x]=0;
			s[x]+= (si[++i]-'0')*100;
			s[x]+= (si[++i]-'0')*10;
			s[x]+= (si[++i]-'0');
			i++;
			x++;
		}
		else{
			s[x]=si[i];
			d++;
			i++;
			x++;
		}
	}


	i=0;
	z=0;
	y=0;
	while(i<x){
		switch(s[i]){
			case 200:{i++; z++;} break;   //del, ascii200
			case 201:{i++; z++;} break;   //Fnc3, ascii201
			case 202:{i++; z++;} break;   //Fnc2, ascii202
			case 203:{i++; z++;} break;   //Shift, ascii203
			case 204:{i++; z++;} break;   //Code C ascii204
			case 205:{i++; z++;} break;   //Code B, ascii205
			case 206:{i++; z++;} break;   //Code A, ascii206
			case 207:{i++; z++;} break;   //Fnc 1, ascii207
			case 212:{t[y] = '(';         //~212
								y++;
								i++;
								for(z=0;z<2;z++){
									t[y]=(char)s[i];
									y++;
									i++;
								}
								t[y] = ')';
								y++;
							 } break;
			case 213:{t[y] = '(';         //~213
								y++;
								i++;
								for(z=0;z<3;z++){
									t[y]=(char)s[i];
									y++;
									i++;
								}
								t[y] = ')';
								y++;
							 } break;
			case 214:{t[y] = '(';         //~214
								y++;
								i++;
								for(z=0;z<4;z++){
									t[y]=(char)s[i];
									y++;
									i++;
								}
								t[y] = ')';
								y++;
							 } break;
			case 215:{t[y] = '(';         //~215
								y++;
								i++;
								for(z=0;z<5;z++){
									t[y]=(char)s[i];
									y++;
									i++;
								}
								t[y] = ')';
								y++;
							 } break;
			default: {t[y]=(char)s[i];
								y++;
								i++;
							 } break;
		}
	}
	f=y;

	res = 3;
	for(a=0;a<=x;a++){
		switch(s[a]){
			case 206:res = 1; break;
			case 205:res = 2; break;
			default: break;
		}
	}
	switch(res){
		case 1:{i=0;                                 // code a
						x=0;
						while (i < l){
							if(si[i]=='~'){
								s2[x]=0;
								s2[x]+=(si[++i]-'0')*100;
								s2[x]+=(si[++i]-'0')*10;
								s2[x]+=((si[++i]-'0') - 105);
								if(s2[x] > 106){
									switch(s2[x - 1]){
										case 99: {x--;
															s2[x]=102;
															x++;
															s2[x]=99;
														 } break;
										case 100:{x--;
															s2[x]=102;
															x++;
															s2[x]=100;
														 } break;
										case 101:{x--;
															s2[x]=102;
															x++;
															s2[x]=101;
														 } break;
									}
								}
								i++;
								x++;
								}
								else{
									if(si[i]<=95){
										s2[x]=(si[i] - 32);
										i++;
									x++;
									}
									else{
										s2[x]=(si[i] - 64);
										i++;
										x++;
									}
								}
						}
						b=x;
				  } break;

		case 2:{i=0;                                 //code b
						x=0;
						while (i < l){
							if(si[i]=='~'){
								s2[x]=0;
								s2[x]+=(si[++i]-'0')*100;
								s2[x]+=(si[++i]-'0')*10;
								s2[x]+=((si[++i]-'0') - 105);
								if(s2[x] > 106){
									switch(s2[x - 1]){
										case 99: {x--;
															s2[x]=102;
															x++;
															s2[x]=99;
														 } break;
										case 100:{x--;
															s2[x]=102;
															x++;
															s2[x]=100;
														 } break;
										case 101:{x--;
															s2[x]=102;
															x++;
															s2[x]=101;
														 } break;
									}
								}
								i++;
								x++;
							}
							else{
								s2[x]=si[i] - 32;
								i++;
								x++;
							}
						}
						b=x;
					} break;

		case 3: {i=0;                                //code c
							bar_length = char_length1*i/2;
							bar_scale = (x) / bar_length;
							x=0;
							if((d%2)==1){
								strcat(si,"0");
							}
							while (i < l){
								if(si[i]=='~'){
									s2[x]=0;
									s2[x]+=(si[++i]-'0')*100;
									s2[x]+=(si[++i]-'0')*10;
									s2[x]+=((si[++i]-'0') - 105);
									if(s2[x] > 106){
										switch(s2[x - 1]){
											case 99: {x--;
																s2[x]=102;
																x++;
																s2[x]=99;
															 } break;
											case 100:{x--;
																s2[x]=102;
																x++;
																s2[x]=100;
															 } break;
											case 101:{x--;
																s2[x]=102;
																x++;
																s2[x]=101;
															 } break;
										}
									}
									i++;
									x++;
								}
								else{
									s2[x]=0;
									s2[x]+=(si[i]-'0')*10;
									s2[x]+=(si[++i]-'0');
									i++;
									x++;
								}
						}
						b=x;
				  } break;
	}


	// Compute the checkbit...
	a=0;
	for (i=0; i<x; ++i){
		a+=(s2[i])*(i+1);
	}

	s2[x]=(a+105)%103;
  

	A4GL_pad_string(t,60);
	g=(int)((bar_length / f) / 11);

	if(g>11){
		g=11;
	}
	if(res==3){
		g=5;
	}

	PutBarsPDF128(p, 107, p_page_height);     // Silent zone
	PutBarsPDF128(p, 105, p_page_height);     // Start, Code C
	atz+=11*littlebar;
	if(b>=f){
		for (i=0; i<=b;i++) {
			if(t[i]=='('){
				atz+=4*littlebar;
			}
			PrintCharPDF128(p, atz,t[i],p_page_height,incl_text);
			if(t[i]==')'){
				atz+=4*littlebar;
			}
			atz+=g*littlebar;
			PutBarsPDF128(p, s2[i], p_page_height);
		}
	}
	else{
		for (i=0; i<=f;i++) {
			if (b>=i){
				if(t[i]=='('){
					atz+=4*littlebar;
				}
				PrintCharPDF128(p, atz,t[i],p_page_height,incl_text);
				if(t[i]==')'){
					atz+=4*littlebar;
				}
				atz+=g*littlebar;
				PutBarsPDF128(p, s2[i], p_page_height);
			}
			if (b<i){
				if(t[i]=='('){
					atz+=4*littlebar;
				}
				PrintCharPDF128(p, atz,t[i],p_page_height,incl_text);
				if(t[i]==')'){
					atz+=4*littlebar;
				}
				atz+=g*littlebar;
			}
		}
	}
	PutBarsPDF128(p, 106, p_page_height);   // Stop
	PutBarsPDF128(p, 107, p_page_height);   // Silent zone
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


static void PrintThisPDF5(PDF *p, char *sorig,float p_page_height,int incl_text) {
unsigned int x;
char s[100]="        ";
char t[6]="     ";
char z[3]="  ";
int a=0;

strcpy(s,sorig);
if (strlen(s)!=5) {
	A4GL_exitwith("Invalid barcode");
}

for (a=0;a<5;a++) {

	if (s[a]==0) { continue; }
	// Check its a number
	if (s[a]>='0' && s[a]<='9') continue;

	A4GL_exitwith("Invalid character in barcode");
	return;
}


	// Compute the checkbit...
	a=0;
	a+=(s[4]-'0')*3;
	a+=(s[3]-'0')*9;
	a+=(s[2]-'0')*3;
	a+=(s[1]-'0')*9;
	a+=(s[0]-'0')*3;
	a=a%10;
   z[0]=a+'0';
	z[1]=0;
	
A4GL_pad_string(s,40);

strcpy(t, PutGrpPDF5(z[0]));

PutBarsPDF5(p,'0', 'B',p_page_height);		// Silent zone
atx += 1*littlebar ;
PutBarsPDF5(p,'0', 'S',p_page_height); //   # starting delimiter
for (x=0; x<5;x++) {
	
	PrintCharPDF5(p, atx,s[x],p_page_height,incl_text);
	PutBarsPDF5(p, t[x], s[x], p_page_height);
	if (x<4){
   PutBarsPDF5(p,'0','M',p_page_height); //  # delimiter in the middle
	}
}
}



static void PrintThisPDF2(PDF *p, char *sorig,float p_page_height,int incl_text) {
char s[50]="     ";
char z[3]="  ";
char t[6]="     ";
int a=0;
int b=0;

strcpy(s,sorig);
if (strlen(s)!=2) {
	A4GL_exitwith("Invalid barcode");
}

for (a=0;a<2;a++) {

	if (s[a]==0) { continue; }
	// Check its a number
	if (s[a]>='0' && s[a]<='9') continue;

	A4GL_exitwith("Invalid character in barcode");
	return;
}

	a=(s[0]-'0');
	b=a*10;
	a=(s[1]-'0');
	b=b+a;
	b=b%4;
	z[0]=b+'0';
	z[1]=0;

A4GL_pad_string(s,40);

strcpy(t, PutGrpPDF2(z[0]));

PutBarsPDF2(p,'0', 'B',p_page_height);		// Silent zone
atx += 1*littlebar ;
PutBarsPDF2(p,'0', 'S',p_page_height); //   # starting delimiter
PrintCharPDF2(p, atx,s[0],p_page_height,incl_text);
PutBarsPDF2(p, t[0], s[0], p_page_height);
PutBarsPDF2(p,'0','M',p_page_height); //  # delimiter in the middle
PrintCharPDF2(p, atx,s[1],p_page_height,incl_text);
PutBarsPDF2(p, t[1], s[1], p_page_height);
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



static void TermBarPDF128A(PDF *p) {
// Does nothing..
}


static void TermBarPDF128B(PDF *p) {
// Does nothing..
}

static void TermBarPDF128C(PDF *p) {
// Does nothing..
}


static void TermBarPDF39(PDF *p) {
	// Does nothing..
}

static void TermBarPDF25(PDF *p) {
	// Does nothing..
}


static void TermBarPDF13(PDF *p) {
// Does nothing..
}


static void TermBarPDF8(PDF *p) {
// Does nothing..
}



static void TermBarPDF5(PDF *p) {
// Does nothing..
}


static void TermBarPDF2(PDF *p) {
// Does nothing..
}


static void setcodetype(void ) {
	if (A4GL_isyes(acl_getenv("BARCODE2"))) {
		codetype=2;
	}
	if (A4GL_isyes(acl_getenv("BARCODE5"))) {
		codetype=5;
	}
	if (A4GL_isyes(acl_getenv("BARCODE8"))) {
		codetype=8;
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

	if (A4GL_isyes(acl_getenv("BARCODE128A"))) {
		codetype=128;
	}
	
	if (A4GL_isyes(acl_getenv("BARCODE128B"))) {
		codetype=129;
	}

	if (A4GL_isyes(acl_getenv("BARCODE128C"))) {
		codetype=130;
	}
	
	if (A4GL_isyes(acl_getenv("BARCODEQR"))) {
		codetype=99;
	}
	if (codetype==-1) {
		codetype=39;
	}
}


void set_barcode_type(char *s) {
	if (A4GL_aubit_strcasecmp(s,"2")==0 ||  A4GL_aubit_strcasecmp(s,"ean2")==0 || A4GL_aubit_strcasecmp(s,"ean-2")==0) {
		codetype=2;
		return ;
	}
	if (A4GL_aubit_strcasecmp(s,"5")==0 ||  A4GL_aubit_strcasecmp(s,"ean5")==0 || A4GL_aubit_strcasecmp(s,"ean-5")==0) {
		codetype=5;
		return ;
	}
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
	
	if (A4GL_aubit_strcasecmp(s,"128A")==0 || A4GL_aubit_strcasecmp(s,"ean128A")==0 ||   		 	A4GL_aubit_strcasecmp(s,"ean-128A")==0) 
		{
		codetype=128;
		return ;
	}
	
	if (A4GL_aubit_strcasecmp(s,"128B")==0 || A4GL_aubit_strcasecmp(s,"ean128B")==0 ||A4GL_aubit_strcasecmp(s,"ean-128B")==0) 
	{
		codetype=129;
		return ;
	}
	
	if (A4GL_aubit_strcasecmp(s,"128C")==0 || A4GL_aubit_strcasecmp(s,"ean128C")==0 ||  A4GL_aubit_strcasecmp(s,"ean-128C")==0)
		{
		codetype=130;
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
int i;
char *S;

if (codetype==-1) {
	setcodetype();
}




if (codetype==99) {
	generate_qrcode(p,str, xpos, ypos,x ,y, p_page_height) ;
	return ;
}

if (codetype==128) {
	littlebar=8;             //# these numbers are arbitrary, as long as the ratio
	font_size = (y/72.0) * 14.4;    //# 2/10 of height of bar
	aty = (y/72.0) * 14.4;          //# 2/10 of height of bar
	atx = 0;
	l = strlen(str);
	char_length1 = 11 * littlebar;
	i= l + 4; //# start, checkdigit, stop, silent zone
	bar_length = char_length1*i;
	bar_scale = (x) / bar_length;
	InitBarPDF128(p, xpos,ypos,x,y,font_size,bar_scale);
	PrintThisPDF128A(p, str,p_page_height,incl_text);
	TermBarPDF128A(p);
}

if (codetype==129) {
	littlebar=8;                    //# these numbers are arbitrary, as long as the ratio
	font_size = (y/72.0) * 14.4;    //# 2/10 of height of bar
	aty = (y/72.0) * 14.4;          //# 2/10 of height of bar
	atx = 0;
	l = strlen(str);
	char_length1 = 11 * littlebar;
	i= l + 4;                       //#start, checkdigit, stop, silent zone
	bar_length = char_length1*i;
	bar_scale = (x) / bar_length;
	InitBarPDF128(p, xpos,ypos,x,y,font_size,bar_scale);
	PrintThisPDF128B(p, str,p_page_height,incl_text);
	TermBarPDF128B(p);
}


if (codetype==130) {
	littlebar=8;                    //# these numbers are arbitrary, as long as the ratio
	font_size = (y/72.0) * 14.4;    //# 2/10 of height of bar
	aty = (y/72.0) * 14.4;          //# 2/10 of height of bar
	atx = 0;
	l = strlen(str);
	char_length1 = 11 * littlebar;
	i= l + 4;                      //# start, checkdigit, stop, silent zone
	bar_length = char_length1*i;
	bar_scale = (x) / bar_length;
	InitBarPDF128(p, xpos,ypos,x,y,font_size,bar_scale);
	PrintThisPDF128C(p, str,p_page_height,incl_text);
	TermBarPDF128C(p);
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
	font_size = (y/72.0) * 14.4;    //# 2/10 of height of bar
	aty = (y/72.0) * 14.4;          //# 2/10 of height of bar
	atx = 0;
	char_length1 = 7 * littlebar;
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



if (codetype==5) {
	littlebar=8;             //# these numbers are arbitrary, as long as the ratio
	font_size = (y/72.0) * 14.4;    //# 2/10 of height of bar
	aty = (y/72.0) * 14.4;          //# 2/10 of height of bar
	atx = 0;
	char_length1 = 7 * littlebar;
	i=strlen(str) + 2;    //# start, middle delimiters
	bar_length = char_length1 * (i-1);
	bar_scale = (x) / bar_length;
	InitBarPDF5(p, xpos,ypos,x,y,font_size,bar_scale);
	S=strdup(str);
	PrintThisPDF5(p, S,p_page_height,incl_text);
	free(S);
	TermBarPDF5(p);
}



if (codetype==2) {
	littlebar=8;             //# these numbers are arbitrary, as long as the ratio
	font_size = (y/72.0) * 14.4;    //# 2/10 of height of bar
	aty = (y/72.0) * 14.4;          //# 2/10 of height of bar
	atx = 0;
	char_length1 = 7 * littlebar;
	i=strlen(str) + 1;    //# start, middle delimiters
	bar_length = char_length1 * (i-1);
	bar_scale = (x) / bar_length;
	InitBarPDF2(p, xpos,ypos,x,y,font_size,bar_scale);
	S=strdup(str);
	PrintThisPDF2(p, S,p_page_height,incl_text);
	free(S);
	TermBarPDF2(p);
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
	qrcode = QRcode_encodeInput (input);
#else
	qrcode = QRcode_encodeMask (input, mask);
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


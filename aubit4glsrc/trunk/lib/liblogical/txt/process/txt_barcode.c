#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include "../../common/a4gl_lle.h"
#include "../../processor/API_process.h"
#include "txt_barcode.h"

int even_odd=0;
int width;
int height;
double x00;
double y00,fontsize,xscale;
double ytotal=10.5*720; // LETTER..
double atx,aty;
int littlebar;
int bigbar;
//double ysize;

static char *BarChar_25(char *mapstring) ;



static char *generate_barcode_CODEV(double xpos,double ypos,double x,double y,char *str) {
static char buff[256];
	static char b[2000];
	memset(b,'.',sizeof(b)); // SHOULD BE ' ' - but cant see those  :-)
	b[strlen(str)]=0;
	sprintf(buff,"^PY^-^M07,10,000^KF^T%04d^BYA%s^G^KF^-^PN^-%s",(int)(x*100),str,b);
return buff;
}

char *format_float(double d) {
static char buff[10][200]; // We'll have a rotating buffer so we can have multiple calls
static int a=0;            // otherwise - we'd be splatting already used memory..
a++;
a=a%10; 

sprintf(buff[a],"%6.3lf",d);
A4GL_lrtrim(buff[a]);
return buff[a];
}

static char *InitBarPCL39(double xpos, double ypos, double x, double y, double font_size, double barscale) {
static char buff[256];
width = x * 720.0;
height = y * 720.0;
x00 = xpos * 720.0;
//y00 = ytotal - (ypos * 720.0) - height;
y00 =  (ypos * 720.0) ;
fontsize = font_size;
xscale = barscale * 10.0;
//  attempt 300 dpi if no 600 dpi
sprintf(buff,"%c*t300R%c*t600R%c&f0S", 27,27,27);
return buff;
}

static char *InitBarPCL25(double xpos, double ypos, double x, double y, double font_size, double barscale) {
static char buff[256];
width = x * 720.0;
height = y * 720.0;
x00 = xpos * 720.0;
//y00 = ytotal - (ypos * 720.0) - height;
y00 =  (ypos * 720.0) ;
fontsize = font_size;
xscale = barscale * 10.0;
//  attempt 300 dpi if no 600 dpi
sprintf(buff,"%c*t300R%c*t600R%c&f0S", 27,27,27);
return buff;
}


static char *DoRectanglePCL( int atx,int xsize,int aty) {
double xabs,yabs;
double xabs2,yabs2;
static char buff[256];
xabs = x00 + (atx * xscale);
yabs = y00;
xabs2 = xsize * xscale;
yabs2 = height;
sprintf(buff,"%c&a%sh%sV%c*c%sh%sV%c*c0P", 27,format_float(xabs),format_float(yabs),27,format_float(xabs2),format_float(yabs2),27);
return buff;
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



static char * PutBarsPCL25(char c1,char c2) {
char t1[200];
char t2[200];
char t[200];
switch (c1) {
        case '(': return BarChar_25( "0000"); 
        case ')': return BarChar_25( "100"); 
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

return BarChar_25(t);
}


static char * BarChar_25(char *mapstring) {
static char buff[2000];
        int  x;
        float barsize;
	strcpy(buff,"");
        for (x=0;x<strlen(mapstring);x++) {
                if (mapstring[x]=='0')  {
                         barsize=littlebar;
                } else {
                         barsize=bigbar;
                }

                if (even_odd) {
                        even_odd = 0;
                        strcat(buff,DoRectanglePCL(atx,barsize,aty ));
                } else {
                        even_odd = 1;
                }
                 atx +=  barsize ;
        }
return buff;
}


static char *BarCharPCL39(char *mapstring) {
int x, barsize  ;
static char buff[2000];
strcpy(buff,"");

for (x=0;x<9;x++) {
   if (mapstring[x]=='0') 
      barsize=littlebar;
   else 
      barsize=bigbar;

   if (x % 2) strcat(buff,DoRectanglePCL(atx,barsize,aty ));

   atx +=barsize;
}

atx +=  littlebar;       //# gap between each bar code character
return buff;

}

static char *PutBarsPCL39(char c) {
switch (c) {
   case '0': return BarCharPCL39("000110100");
   case '1': return BarCharPCL39("100100001");
   case '2': return BarCharPCL39("001100001");
   case '3': return BarCharPCL39("101100000");
   case '4': return BarCharPCL39("000110001");
   case '5': return BarCharPCL39("100110000");
   case '6': return BarCharPCL39("001110000");
   case '7': return BarCharPCL39("000100101");
   case '8': return BarCharPCL39("100100100");
   case '9': return BarCharPCL39("001100100");
   case '-': return BarCharPCL39("010000101");
   case '.': return BarCharPCL39("110000100");
   case ' ': return BarCharPCL39("011000100");
   case '+': return BarCharPCL39("010001010");
   case '%': return BarCharPCL39("000101010");
   case '$': return BarCharPCL39("010101000");
   case '/': return BarCharPCL39("010100010");
   case 'A': return BarCharPCL39("100001001");
   case 'B': return BarCharPCL39("001001001");
   case 'C': return BarCharPCL39("101001000");
   case 'D': return BarCharPCL39("000011001");
   case 'E': return BarCharPCL39("100011000");
   case 'F': return BarCharPCL39("001011000");
   case 'G': return BarCharPCL39("000001101");
   case 'H': return BarCharPCL39("100001100");
   case 'I': return BarCharPCL39("001001100");
   case 'J': return BarCharPCL39("000011100");
   case 'K': return BarCharPCL39("100000011");
   case 'L': return BarCharPCL39("001000011");
   case 'M': return BarCharPCL39("101000010");
   case 'N': return BarCharPCL39("000010011");
   case 'O': return BarCharPCL39("100010010");
   case 'P': return BarCharPCL39("001010010");
   case 'Q': return BarCharPCL39("000000111");
   case 'R': return BarCharPCL39("100000110");
   case 'S': return BarCharPCL39("001000110");
   case 'T': return BarCharPCL39("000010110");
   case 'U': return BarCharPCL39("110000001");
   case 'V': return BarCharPCL39("011000001");
   case 'W': return BarCharPCL39("111000000");
   case 'X': return BarCharPCL39("010010001");
   case 'Y': return BarCharPCL39("110010000");
   case 'Z': return BarCharPCL39("011010000");
   default : return BarCharPCL39("010010100");
}

return "";
}

static char *PrintCharPCL39(double x, char c) {
double xabs,yabs;
static char buff[200];
xabs = x00 + x * xscale;
yabs = y00 + height + (fontsize * 12.0);
sprintf(buff,"%c&a%sh%sV%c",27,format_float(xabs),format_float(yabs),c);
return buff;
}

static char *PrintThisPCL39(char *s) {
int x;
static char buff[20000];
strcpy(buff,"");
strcat(buff, PutBarsPCL39('*')); //   # starting delimiter 

for (x=0; x<strlen(s);x++) {
   strcat(buff, PrintCharPCL39(atx,s[x]));
   strcat(buff, PutBarsPCL39(s[x]));
}

strcat(buff,PutBarsPCL39('*'));   //# ending delimiter 
return buff;
}


static char *PrintThisPCL25(char *s) {
int x;
char buff[2000]; // Allow some space for a trailing space- needed if its a noneven length
static char buff2[2000];
even_odd=1;
strcpy(buff2, PutBarsPCL25('(',0)); //   # starting delimiter
strcpy(buff,s);
strcat(buff," ");

for (x=0; x<strlen(s);x+=2) {
        strcat(buff2,PutBarsPCL25(buff[x], buff[x+1]));
}

strcat(buff2,PutBarsPCL25(')',0));   //# ending delimiter
return buff2;
}



static char *TermBarPCL39(void) {
	static char buff[200];
	sprintf(buff,"%c&f1S%c*rC",27,27);
	return buff;
}

static char *TermBarPCL25(void) {
	static char buff[200];
	sprintf(buff,"%c&f1S%c*rC",27,27);
	return buff;
}


// Adapted from : 
// # Filename: bc.4gl
// # Desc    : Barcodes on Laser Printers
// # SCCS    : @(#) bc.4gl 1.1 96/04/18 15:33:10
// # Author  : Ti Lian Hwang (tilh@sin-co.sg.dhl.com)
// # Date    : 04 Oct 95
static char *generate_barcode_PCL(double xpos,double ypos,double x,double y,char *str) {
double font_size;
int char_length1;
int i;
double bar_length, bar_scale;
char *S;
static char buff[20000];
int code=39;

if (A4GL_isyes(acl_getenv("BARCODE25"))) {
        code=25;
}

if (A4GL_isyes(acl_getenv("BARCODE39"))) {
        code=39;
}



if (code==39) {
	littlebar=8;             //# these numbers are arbitrary, as long as the ratio
	bigbar=20;               //# stays between 2:1 and 3:1
	//ysize = y * 72.0;        //# inch to points
	font_size = y * 14.4;    //# 2/10 of height of bar
	aty = y * 14.4;          //# 2/10 of height of bar
	atx = 0;
	char_length1 = 3 * bigbar + 6 * littlebar;
	i=strlen(str) + 2;                                  //# delimiters
	bar_length = char_length1 * i + (i-1) * littlebar;     //# gap
	bar_scale = (72.0 * x) / bar_length;
	
	strcpy(buff, InitBarPCL39(xpos,ypos,x,y,font_size,bar_scale));
	// Create an uppercased version
	S=strdup(str);
	a4gl_upshift(S);
	strcat(buff,PrintThisPCL39(S));
	free(S);
	strcat(buff,TermBarPCL39());
} else {
        littlebar=8;             //# these numbers are arbitrary, as long as the ratio
        bigbar=20;               //# stays between 2:1 and 3:1
        font_size = y * 14.4;    //# 2/10 of height of bar
        aty = y * 14.4;          //# 2/10 of height of bar
        atx = 0;
        char_length1 = 2 * bigbar + 3 * littlebar;
        i=strlen(str) ;                                  //# delimiters
        bar_length = char_length1 * i + 6 * littlebar +1 *bigbar;     //# gap
        bar_scale = (72.0*x) / bar_length;
        strcpy(buff, InitBarPCL25(xpos,ypos,x,y,font_size,bar_scale));
        S=strdup(str);
        a4gl_upshift(S);
        strcat(buff,PrintThisPCL25(S));
        free(S);
        strcat(buff,TermBarPCL25());

}
return buff;
}



char *generate_barcode(double xpos,double ypos,double w,double h,char *str) {
char *ptr;
	if (A4GL_isyes(acl_getenv("CODEVBARCODE"))) {
		return generate_barcode_CODEV(xpos,ypos,w,h,str);
	}
	ptr=generate_barcode_PCL(xpos,ypos,w,h,str);
return ptr;
}

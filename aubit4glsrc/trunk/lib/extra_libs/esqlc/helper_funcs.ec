//#include "a4gl_incl_4glhdr.h"
//#include "a4gl_libaubit4gl.h"

#include "a4gl_esql.h"


void A4GL_copy_decimal(dec_t *infx,fgldecimal *a4gl,int size,char dir) {
char b[65];
A4GL_debug("Aubit size : %d %d\n",size & 15, size>>4);

if (dir=='i') {
	char *ptr;
A4GL_debug("A4GL_copy_decimal 'i' %x",(size<<16)+5);
	A4GL_push_variable(a4gl,(size<<16)+5);
   	A4GL_pop_var2(&b,0,0x28);
A4GL_debug("Ptr=%s\n",b);
	deccvasc(b,strlen(b),infx);
}

if (dir=='o') {
	char *ptr;
	memset(b,0,65);
	dectoasc(infx,b,64,16);
	A4GL_push_variable(b,(64<<16));
A4GL_debug("Copy_decimal 'o' - gets %s",b);
	A4GL_pop_var2(a4gl,5,0x1e10);

		A4GL_push_variable(a4gl,(size<<16)+5);
   		A4GL_pop_var2(&b,0,0x28);
	A4GL_debug("Double check gives : %s",b);
	//debug("A4GL_copy_decimal 'o' Ptr=dec_t=%p\n",infx);
	//debug("dec_t.dec_exp=%d\n",infx->dec_exp);
	//debug("dec_t.dec_pos=%d\n",infx->dec_pos);
	//debug("dec_t.dec_ndgts=%d\n",infx->dec_ndgts);
	
}
A4GL_debug("All done..");

}



void A4GL_copy_money(dec_t *infx,fglmoney *a4gl,int size,char dir) {
char b[65];
A4GL_debug("Aubit size : %d %d\n",size & 15, size>>4);

if (dir=='i') {
	char *ptr;
A4GL_debug("A4GL_copy_decimal 'i' %x",(size<<16)+5);
	A4GL_push_variable(a4gl,(size<<16)+5);
   	A4GL_pop_var2(&b,0,0x28);
A4GL_debug("Ptr=%s\n",b);
	deccvasc(b,strlen(b),infx);
}

if (dir=='o') {
	char *ptr;
	memset(b,0,65);
	dectoasc(infx,b,64,16);
	A4GL_push_variable(b,(64<<16));
A4GL_debug("Copy_decimal 'o' - gets %s",b);
	A4GL_pop_var2(a4gl,5,0x1e10);

		A4GL_push_variable(a4gl,(size<<16)+5);
   		A4GL_pop_var2(&b,0,0x28);
	A4GL_debug("Double check gives : %s",b);
	//debug("A4GL_copy_decimal 'o' Ptr=dec_t=%p\n",infx);
	//debug("dec_t.dec_exp=%d\n",infx->dec_exp);
	//debug("dec_t.dec_pos=%d\n",infx->dec_pos);
	//debug("dec_t.dec_ndgts=%d\n",infx->dec_ndgts);
	
}


}


#ifndef DIALECT_POSTGRES

// A4GL datetimes scales range from 0->107
// some of these are not valid - but an array is a quick way to
// look up the corresponding Informix Dtype qualifiers...
int arr_dtime[]={
   	0,0,0, 	0, 	0, 	0, 	0, 	0, 	0, 	0, 	0, 
  0, 	0, 	0, 	0, 	0, 	0, 	1024, 	1538, 	2052, 	2566, 
  3080,	3594, 	3851, 	4108, 	4365, 	4622, 	4879, 	0, 	0, 	0, 
  0, 0, 0,
  546, 1060, 1574, 2088, 2602, 2859, 3116, 3373, 3630, 3887,
  0, 0, 0, 0, 0, 0, 0,
  580, 1094, 1608, 2122, 2379, 2636, 2893, 3150, 3407,
  0, 0, 0, 0, 0, 0, 0, 0,
  614, 1128, 1642, 1899, 2156, 2413, 2670, 2927,
  0, 0, 0, 0, 0, 0, 0, 0, 0,
  648, 1162, 1419, 1676, 1933, 2190, 2447,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  682, 939, 1196, 1453, 1710, 1967
  };


void A4GL_copy_datetime(dtime_t *infx, struct A4GLSQL_dtime *a4gl,int size,int mode) {

	if (mode=='i') {
		char *ptr;
		char buff[255];
		A4GL_push_dtime(a4gl);
		ptr=A4GL_char_pop();
		if (size<0||size>107) {
		A4GL_debug("DATETIME OUT OF RANGE");
			printf("ERROR - SEE DEBUG.OUT");
		}
	A4GL_debug("size=%d\n",size);
		infx->dt_qual=arr_dtime[size];
	A4GL_debug("infx_dtqual=%d\n",infx->dt_qual);
		dtcvasc(ptr,infx);

// Debugging stuff only
	A4GL_debug("Copy datetime in - aubit=%s\n",ptr);
		dttoasc(infx,buff);
	A4GL_debug("                Informix=%s\n",buff);
// End of Debugging stuff only

		free(ptr);
	}

	if (mode=='o') {
		char buff[255];
		char *ptr;
		int a;
		dttoasc(infx,buff);
		A4GL_push_char(buff);
		A4GL_pop_param(a4gl,DTYPE_DTIME,size);


// Debugging stuff only
		A4GL_push_dtime(a4gl);
		ptr=A4GL_char_pop();
	A4GL_debug("Copy datetime out - aubit=%s\n",ptr);
	A4GL_debug("                Informix=%s\n",buff);
		free(ptr);
// End of Debugging stuff only
	}



}
#endif

A4GL_copy_interval() {
	printf("A4GL_copy_interval not implemented yet");
}

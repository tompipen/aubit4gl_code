//#include "a4gl_incl_4glhdr.h"
//#include "a4gl_libaubit4gl.h"

#include "a4gl_esql.h"


void A4GL_copy_decimal(dec_t *infx,fgldecimal *a4gl,int size,char dir) {
char b[65];
A4GL_debug("Aubit size : %d %d\n",size & 15, size>>4);

if (dir=='i') {
	char *ptr;
	if (A4GL_isnull(DTYPE_MONEY,(void *)a4gl)) {rsetnull(DTYPE_DECIMAL,(void *)infx);return;}
	A4GL_debug("A4GL_copy_decimal 'i' %x",(size<<16)+5);
	A4GL_push_variable(a4gl,(size<<16)+5);
   	A4GL_pop_var2(&b,0,0x28);
	//printf("Ptr=%s\n",b);
	deccvasc(b,strlen(b),infx);

}

if (dir=='o') {
	char *ptr;
		if (risnull(DTYPE_DECIMAL,(void*)infx)) { A4GL_setnull(DTYPE_DECIMAL,(void *)a4gl,size); return;}
	memset(b,0,65);
	dectoasc(infx,b,64,16);
	A4GL_push_char(b);
	A4GL_pop_var2(a4gl,5,size);

	//A4GL_push_variable(a4gl,(size<<16)+5);
   	//A4GL_pop_var2(&b,0,0x28);
}

A4GL_debug("All done..");

}



void A4GL_copy_money(dec_t *infx,fglmoney *a4gl,int size,char dir) {
char b[65];
A4GL_debug("Aubit size : %d %d\n",size & 15, size>>4);

if (dir=='i') {
	char *ptr;
	if (A4GL_isnull(DTYPE_MONEY,(void *)a4gl)) {rsetnull(DTYPE_MONEY,(void *)infx);return;}
	A4GL_debug("A4GL_copy_decimal 'i' %x",(size<<16)+5);
	A4GL_push_variable(a4gl,(size<<16)+5);
   	A4GL_pop_var2(&b,0,0x28);
	A4GL_debug("Ptr=%s\n",b);
	deccvasc(b,strlen(b),infx);
}

if (dir=='o') {
        char *ptr;
	if (risnull(DTYPE_MONEY,(void*)infx)) { A4GL_setnull(DTYPE_MONEY,(void *)a4gl,size); return;}
        memset(b,0,65);
        dectoasc(infx,b,64,16);
        A4GL_push_char(b);
        A4GL_pop_var2(a4gl,DTYPE_MONEY,size);
	A4GL_dump(a4gl);
}

}







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
#ifdef DIALECT_INFORMIX
		infx->dt_qual=arr_dtime[size];
#endif
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

		if (risnull(DTYPE_DTIME,(void*)infx)) { A4GL_setnull(DTYPE_DTIME,(void *)a4gl,size); return;}
		
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

A4GL_copy_interval() {
	printf("A4GL_copy_interval not implemented yet");
}




A4GL_copy_char(char *infx,char *a4gl,int size,int mode,int x,int y) {
	if (mode=='i') {
		if (A4GL_isnull(0,(void *)a4gl)) {rsetnull(0,infx);return;}
		strcpy((char *)(infx),(char *)(a4gl));
	}
	if (mode=='o') {
		if (risnull(0,(void*)infx)) { A4GL_setnull(0,(void *)a4gl,size); return;}
		strcpy((char *)(a4gl),(char *)(infx));
	}
}


A4GL_copy_smint(short *infx,short *a4gl,int size,int mode) {
	if (mode=='i') {
		if (A4GL_isnull(1,(void *)a4gl)) {rsetnull(1,(void *)infx);return;}
		*infx=*a4gl;
	}
	if (mode=='o') {
		if (risnull(1,(void*)infx)) { A4GL_setnull(1,(void *)a4gl,size); return;}
		*a4gl=*infx;
	}
}


A4GL_copy_int(long *infx,long *a4gl,int size,int mode) {
	if (mode=='i') {
		if (A4GL_isnull(2,(void *)a4gl)) {rsetnull(2,(void *)infx);return;}
		*infx=*a4gl;
	}
	if (mode=='o') {
		if (risnull(2,(void*)infx)) { A4GL_setnull(2,(void *)a4gl,size); return;}
		*a4gl=*infx;
	}
}


A4GL_copy_float(float *infx,float *a4gl,int size,int mode) {
	if (mode=='i') {
		if (A4GL_isnull(4,(void *)a4gl)) {rsetnull(4,(void *)infx);return;}
		*infx=*a4gl;
	}
	if (mode=='o') {
		if (risnull(4,(void*)infx)) { A4GL_setnull(4,(void *)a4gl,size); return;}
		*a4gl=*infx;
	}
}


A4GL_copy_double(double *infx,double *a4gl,int size,int mode) {
	if (mode=='i') {
		if (A4GL_isnull(3,(void *)a4gl)) {rsetnull(3,(void *)infx);return;}
		*infx=*a4gl;
	}
	if (mode=='o') {
		if (risnull(3,(void*)infx)) { A4GL_setnull(3,(void *)a4gl,size); return;}
		*a4gl=*infx;
	}
}


void popdec(void *vx) {
	dec_t *x;
        char *s;
	x=vx;
        s=A4GL_char_pop();
        deccvasc(s,strlen(s),x);
        free(s);
}

void retdec(void *vx) {
	dec_t *x;
        fgldecimal _s;
	x=vx;
        A4GL_copy_decimal(x,&_s,0x1e10,'o');
        A4GL_push_variable(&_s,0x1e100005);
}

void popdtime(void *vx) {
	dtime_t *x;
        char *s;
	x=vx;
        s=A4GL_char_pop();
        dtcvasc(s,x);
        free(s);
}


void retdtime(void *vx) {
        char s[123];
	dtime_t *x;
        struct A4GLSQL_dtime d;
	x=vx;
        dttoasc(x,s);
}

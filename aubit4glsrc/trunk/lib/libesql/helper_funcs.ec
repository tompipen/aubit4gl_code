//#include "a4gl_incl_4glhdr.h"


//needed for DTYPE_MONEY DTYPE_DECIMAL DTYPE_DTIME DTYPE_DATE ...


#ifdef DIALECT_QUERIX
	//avoid redeclaration of int_flag, quit_flag, UCHAR
	#define _NO_INT_QUIT_FLAG_
    //#define __UCHAR_DEFINED__
#endif

#include "a4gl_libaubit4gl.h"
#include "a4gl_esql.h"


void A4GL_copy_decimal(void *infxv,void *a4glv,int indicat,int size,char dir) {
dec_t *infx;fgldecimal *a4gl;
char b[65];
infx=infxv;
a4gl=a4glv;
A4GL_debug("Aubit size : %d %d\n",size & 15, size>>4);

if (dir=='i') {
	char *ptr;
	if (A4GL_isnull(DTYPE_DECIMAL,(void *)a4gl)) {rsetnull(CDECIMALTYPE,(void *)infx);return;}
	A4GL_debug("A4GL_copy_decimal 'i' %x",(size<<16)+5);
	A4GL_push_variable(a4gl,(size<<16)+5);
   	A4GL_pop_var2(&b,0,0x28);
	A4GL_debug("calling deccvasc with %s",b);
	deccvasc(b,strlen(b),infx);

}

if (dir=='o') {
	char *ptr;
	if (indicat==-1||risnull(CDECIMALTYPE,(void*)infx)) { A4GL_setnull(DTYPE_DECIMAL,(void *)a4gl,size); return;}
	memset(b,0,65);
	dectoasc(infx,b,64,16);
	A4GL_debug("calling dectoasc returns %s",b);
	A4GL_push_char(b);
	A4GL_pop_var2(a4gl,5,size);

	//A4GL_push_variable(a4gl,(size<<16)+5);
   	//A4GL_pop_var2(&b,0,0x28);
}

A4GL_debug("All done..");

}



void A4GL_copy_money(void *infxv,void *a4glv,int indicat,int size,char dir) {
dec_t *infx;fgldecimal *a4gl;
char b[65];
infx=infxv;
a4gl=a4glv;
A4GL_debug("Aubit size : %d %d\n",size & 15, size>>4);

if (dir=='i') {
	char *ptr;
	if (A4GL_isnull(DTYPE_MONEY,(void *)a4gl)) {rsetnull(CMONEYTYPE,(void *)infx);return;}
	A4GL_debug("A4GL_copy_decimal 'i' %x",(size<<16)+5);
	A4GL_push_variable(a4gl,(size<<16)+5);
   	A4GL_pop_var2(&b,0,0x28);
	A4GL_debug("Ptr=%s\n",b);
	deccvasc(b,strlen(b),infx);
}

if (dir=='o') {
        char *ptr;
	if (indicat==-1||risnull(CMONEYTYPE,(void*)infx)) { A4GL_setnull(DTYPE_MONEY,(void *)a4gl,size); return;}
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


void A4GL_copy_datetime(void *infxv, void *a4glv,int indicat,int size,int mode) {
dtime_t *infx; struct A4GLSQL_dtime *a4gl;
infx=infxv;
a4gl=a4glv;

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

		if (indicat==-1||risnull(CDTIMETYPE,(void*)infx)) { A4GL_setnull(DTYPE_DTIME,(void *)a4gl,size); return;}
		
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

void A4GL_copy_interval() {
	printf("A4GL_copy_interval not implemented yet");
}




void A4GL_copy_char(char *infx,char *a4gl,int indicat,int size,int mode,int x,int y) {
	
	if (mode=='i') {
		if (A4GL_isnull(0,(void *)a4gl)) {
				rsetnull(CCHARTYPE,infx);
			return;
	
		}
		strcpy((char *)(infx),(char *)(a4gl));
		A4GL_trim(infx); // @todo -  what about varchars ... ?
	}
	if (mode=='o') {
		if (indicat==-1||risnull(CCHARTYPE,(void*)infx)) { A4GL_setnull(0,(void *)a4gl,size); return;}
		infx[size]=0;
		strcpy((char *)(a4gl),(char *)(infx));
	}
}




void A4GL_copy_date(long *infx,long *a4gl,int indicat,int size,int mode) {
short  mdy[3];
int mdy_i[3];
long orig_date;
	if (mode=='i') {
		if (A4GL_isnull(DTYPE_DATE,(void *)a4gl)) {rsetnull(CDATETYPE,(void *)infx);return;}
		A4GL_get_date(*a4gl,&mdy_i[1],&mdy_i[0],&mdy_i[2]);
		mdy[0]=mdy_i[0]; // In aubit - these are integers
		mdy[1]=mdy_i[1]; // so we need to copy them into the shorts
		mdy[2]=mdy_i[2]; // That informix is expecting
		A4GL_debug("copy_date : mode=i - %d %d %d",mdy[0],mdy[1],mdy[2]);
		rmdyjul(mdy,infx); // Set the informix one
	}

	if (mode=='o') {
		if (indicat==-1||risnull(CDATETYPE,(void*)infx)) { A4GL_setnull(DTYPE_DATE,(void *)a4gl,size); return;}
		A4GL_debug("Got date as : '%d' %x",*infx,*infx);
		orig_date=*infx;
		rjulmdy(orig_date,mdy); 				// Get the MDY from informix
		if (mdy[2]>3000||mdy[2]<1000 || mdy[0]<1||mdy[0]>12||mdy[1]<1||mdy[1]>31) {
			// Suspect date ?
			A4GL_debug("SUSPECT DATE DETECTED..... : %d %d %d %d",orig_date,mdy[0],mdy[1],mdy[2]);
			*a4gl=0;
			return;
		}
		A4GL_debug("copy_date : mode=o - %d %d %d",mdy[0],mdy[1],mdy[2]);
		*a4gl=A4GL_gen_dateno(mdy[1],mdy[0],mdy[2]); 	// And use it to generate an aubit.
	}
}



void A4GL_copy_smint(short *infx,short *a4gl,int indicat,int size,int mode) {
	if (mode=='i') {
		if (A4GL_isnull(1,(void *)a4gl)) {rsetnull(CSHORTTYPE,(void *)infx);return;}
		*infx=*a4gl;
	}
	if (mode=='o') {
		if (indicat==-1||risnull(CSHORTTYPE,(void*)infx)) { A4GL_setnull(1,(void *)a4gl,size); return;}
		*a4gl=*infx;
	}
}


void A4GL_copy_int(long *infx,long *a4gl,int indicat,int size,int mode) {
	if (mode=='i') {
		if (A4GL_isnull(2,(void *)a4gl)) {rsetnull(CLONGTYPE,(void *)infx);return;}
		*infx=*a4gl;
	}
	if (mode=='o') {
		if (indicat==-1||risnull(CLONGTYPE,(void*)infx)) { A4GL_setnull(2,(void *)a4gl,size); return;}
		*a4gl=*infx;
	}
}


void A4GL_copy_float(float *infx,float *a4gl,int indicat,int size,int mode) {
	if (mode=='i') {
		if (A4GL_isnull(4,(void *)a4gl)) {rsetnull(CFLOATTYPE,(void *)infx);return;}
		*infx=*a4gl;
	}
	if (mode=='o') {
		if (indicat==-1||risnull(CFLOATTYPE,(void*)infx)) { A4GL_setnull(4,(void *)a4gl,size); return;}
		*a4gl=*infx;
	}
}


void A4GL_copy_double(double *infx,double *a4gl,int indicat,int size,int mode) {
	if (mode=='i') {
		if (A4GL_isnull(3,(void *)a4gl)) {rsetnull(CDOUBLETYPE,(void *)infx);return;}
		*infx=*a4gl;
	}
	if (mode=='o') {
		if (indicat==-1||risnull(CDOUBLETYPE,(void*)infx)) { A4GL_setnull(3,(void *)a4gl,size); return;}
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
        A4GL_copy_decimal(x,&_s,0,0x1e10,'o');
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


A4GLESQL_initlib() {
}

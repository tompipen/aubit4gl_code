/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-1 Aubit Development Team (See Credits file)       |
# +----------------------------------------------------------------------+
# | This program is free software; you can redistribute it and/or modify |
# | it under the terms of one of the following licenses:                 |
# |                                                                      |
# |  A) the GNU General Public License as published by the Free Software |
# |     Foundation; either version 2 of the License, or (at your option) |
# |     any later version.                                               |
# |                                                                      |
# |  B) the Aubit License as published by the Aubit Development Team and |
# |     included in the distribution in the file: LICENSE                |
# |                                                                      |
# | This program is distributed in the hope that it will be useful,      |
# | but WITHOUT ANY WARRANTY; without even the implied warranty of       |
# | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        |
# | GNU General Public License for more details.                         |
# |                                                                      |
# | You should have received a copy of both licenses referred to here.   |
# | If you did not, or have any questions about Aubit licensing, please  |
# | contact afalout@ihug.co.nz                                           |
# +----------------------------------------------------------------------+
#
# $Id: helper_funcs.ec,v 1.18 2004-10-02 08:04:37 mikeaubury Exp $
#
*/

/**
 * @file
 *
 *
 */


//#include "a4gl_incl_4glhdr.h"

//needed for DTYPE_MONEY DTYPE_DECIMAL DTYPE_DTIME DTYPE_DATE ...

#ifdef DIALECT_QUERIX
	//avoid redeclaration of int_flag, quit_flag, UCHAR
	#define _NO_INT_QUIT_FLAG_
    #if (defined(__MINGW32__) || defined (__CYGWIN__))
		//Avoid conflict of DATE in qxdefs.h with MinGW wtypes.h:
		//#define NEWERA
		#define _NO_WINDOWS_H_
    #endif
    //#define __UCHAR_DEFINED__

/*
in Querix libesql.lib:

erence to `rsetnull'
erence to `deccvasc'
erence to `risnull'
erence to `dectoasc'
ference to `dtcvasc'
ference to `dttoasc'
ference to `rmdyjul'
ference to `rjulmdy'

But them missing DtimeToChar and fammily - where are they?

*/

#endif

#include "a4gl_libaubit4gl.h"
#include "a4gl_esql.h"

#ifdef DIALECT_INFORMIX
#define DIALECTED 1
#endif

#ifdef DIALECT_POSTGRES
#define DIALECTED 1
#endif

#ifdef DIALECT_QUERIX
#define DIALECTED 1
#endif

#ifdef DIALECT_SAP
#define DIALECTED 1
#endif


#ifndef DIALECTED
#error "No dialect specified"
#endif


/**
 *
 *
 * @todo describe function
 */
void 
ESQLAPI_A4GL_copy_decimal(void *infxv,void *a4glv,int indicat,int size,char dir) 
{
#ifdef DIALECT_POSTGRES
EXEC SQL BEGIN DECLARE SECTION;
decimal *infx;
EXEC SQL END DECLARE SECTION;
#else
dec_t *infx;
#endif
fgldecimal *a4gl;
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
		if (A4GL_isyes(acl_getenv("DEBUG_DECIMAL"))) {
			A4GL_debug(">b='%s'\n",b);
		}
		A4GL_trim(b);
		A4GL_debug("calling deccvasc with '%s'",b);
		deccvasc(b,strlen(b),infx);
		if (A4GL_isyes(acl_getenv("DEBUG_DECIMAL"))) {
			dectoasc(infx,b,64,16);
			A4GL_debug(">> b='%s'\n",b);
		}

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



/**
 *
 *
 * @todo describe function
 */
void 
ESQLAPI_A4GL_copy_money(void *infxv,void *a4glv,int indicat,int size,char dir) 
{

#ifdef DIALECT_POSTGRES
EXEC SQL BEGIN DECLARE SECTION;
decimal *infx;
EXEC SQL END DECLARE SECTION;
#else
dec_t *infx;
#endif
fgldecimal *a4gl;
char b[65];
	infx=infxv;
	a4gl=a4glv;
	A4GL_debug("Aubit size : %d %d\n",size & 15, size>>4);

	if (dir=='i') {
		char *ptr;
		if (A4GL_isnull(DTYPE_MONEY,(void *)a4gl)) {
#ifdef DIALECT_POSTGRES
				rsetnull(CDECIMALTYPE,(void *)infx);
#else
				rsetnull(CMONEYTYPE,(void *)infx);
#endif
				return;
		}
		A4GL_debug("A4GL_copy_decimal 'i' %x",(size<<16)+5);
		A4GL_push_variable(a4gl,(size<<16)+5);
	   	A4GL_pop_var2(&b,0,0x28);
		A4GL_debug("Ptr=%s\n",b);
		A4GL_trim(b);
		deccvasc(b,strlen(b),infx);
	}

	if (dir=='o') {
	        char *ptr;
		int xisnull;

#ifdef DIALECT_POSTGRES
                xisnull=risnull(CDECIMALTYPE,(void *)infx);
#else
                xisnull=risnull(CMONEYTYPE,(void *)infx);
#endif
		if (indicat==-1||xisnull) { 
				A4GL_setnull(DTYPE_MONEY,(void *)a4gl,size); return;
		}

	        memset(b,0,65);
	        dectoasc(infx,b,64,16);
	        A4GL_push_char(b);
	        A4GL_pop_var2(a4gl,DTYPE_MONEY,size);
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


/**
 *
 *
 * @todo describe function
 */
void 
ESQLAPI_A4GL_copy_datetime(void *infxv, void *a4glv,int indicat,int size,int mode) 
{
dtime_t *infx; struct A4GLSQL_dtime *a4gl;
	infx=infxv;
	a4gl=a4glv;

		if (mode=='i') {
			char *ptr;
			char buff[255];
			if (A4GL_isnull(DTYPE_DTIME,(void *)a4gl)) {rsetnull(CDTIMETYPE,(void *)infx);return;}
			A4GL_push_dtime(a4gl);
			ptr=A4GL_char_pop();
			if (size<0||size>107) {
			A4GL_debug("DATETIME OUT OF RANGE");
				printf("ERROR - SEE DEBUG.OUT\n");
			}
	#ifdef DIALECT_INFORMIX
		if (!A4GL_isyes(acl_getenv("KEEP_QUALIFIER"))) {
			infx->dt_qual=arr_dtime[size];
		}
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
#ifdef DIALECT_POSTGRES
#ifdef HAVE_INT64_TIMESTAMP
#error INT64 timestamp not implemented
#endif
if (*infx==0) indicat=-1;
#endif
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

/**
 *
 *
 * @todo describe function
 */
#ifdef DIALECT_INFORMIX
void ESQLAPI_A4GL_copy_interval(void *infxv, void *a4glv,int indicat,int size,int mode) 
{
intrvl_t *infx; struct A4GLSQL_dtime *a4gl;
if (mode=='i'||mode=='o') ; 
else {
	A4GL_assertion(1,"Mode should be 'o' or 'i'");
}
	infx=infxv;
	a4gl=a4glv;

		if (mode=='i') {
			char *ptr;
			char buff[255];
			if (A4GL_isnull(DTYPE_DTIME,(void *)a4gl)) {rsetnull(CINVTYPE,(void *)infx);return;}
			A4GL_push_interval(a4gl);
			ptr=A4GL_char_pop();

	#ifdef DIALECT_INFORMIX
		if (!A4GL_isyes(acl_getenv("KEEP_QUALIFIER"))) {
			int ndig_s;
			int s;
			int e;
			int tr[]={0,TU_YEAR,TU_MONTH,TU_DAY,TU_HOUR,TU_MINUTE,TU_SECOND,TU_F1,TU_F2,TU_F3,TU_F4,TU_F5,0};
			ndig_s=size>>8;
			s=(size>>4)&0xf;
			e=(size&0xf);
			printf("%x %d %d %d %d\n",size,size,ndig_s,s,e);
			infx->in_qual=TU_IENCODE(ndig_s,tr[s],tr[e]);
		}
	#endif

	incvasc(ptr,infx);

	// Debugging stuff only
		A4GL_debug("Copy interval in - aubit=%s\n",ptr);
		printf("Copy interval in - aubit=%s\n",ptr);
			intoasc(infx,buff);
		printf("                Informix=%s\n",buff);
		A4GL_debug("                Informix=%s\n",buff);
	// End of Debugging stuff only

			free(ptr);
		}

		if (mode=='o') {
			char buff[255];
			char *ptr;
			int a;
#ifdef DIALECT_POSTGRES
#ifdef HAVE_INT64_TIMESTAMP
#error INT64 timestamp not implemented
#endif
//if (*infx==0) indicat=-1;
#endif
			if (indicat==-1||risnull(CINVTYPE,(void*)infx)) { A4GL_setnull(DTYPE_INTERVAL,(void *)a4gl,size); return;}

			intoasc(infx,buff);
			A4GL_push_char(buff);
			A4GL_pop_param(a4gl,DTYPE_INTERVAL,size);


	// Debugging stuff only
			A4GL_push_interval(a4gl);
			ptr=A4GL_char_pop();
		A4GL_debug("Copy datetime out - aubit=%s\n",ptr);
		A4GL_debug("                Informix=%s\n",buff);
			free(ptr);
	// End of Debugging stuff only
		}

}
#endif


#ifdef DIALECT_POSTGRES

void ESQLAPI_A4GL_copy_interval(void *infxv, void *a4glv,int indicat,int size,int mode)  {
	printf("A4GL_copy_interval for postgres not implemented yet\n");

}
#endif
/**
 *
 *
 * @todo describe function
 */
void 
ESQLAPI_A4GL_copy_char(char *infx,char *a4gl,int indicat,int size,int mode,int x,int y) 
{

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




/**
 *
 *
 * @todo describe function
 */
void 
ESQLAPI_A4GL_copy_date(long *infx,long *a4gl,int indicat,int size,int mode) 
{
short  mdy[3];
int mdy_i[3];
long orig_date;
	if (mode=='i') {
		if (A4GL_isnull(DTYPE_DATE,(void *)a4gl)) {rsetnull(CDATETYPE,(void *)infx);A4GL_debug("COPY IN NULL DATE");return;}
		A4GL_get_date(*a4gl,&mdy_i[1],&mdy_i[0],&mdy_i[2]);
		mdy[0]=mdy_i[0]; // In aubit - these are integers
		mdy[1]=mdy_i[1]; // so we need to copy them into the shorts
		mdy[2]=mdy_i[2]; // That informix is expecting
		A4GL_debug("copy_date : mode=i - %d %d %d",mdy[0],mdy[1],mdy[2]);
		rmdyjul(mdy,infx); // Set the informix one
	}

	if (mode=='o') {

#ifdef DIALECT_POSTGRES
if (*infx==0) indicat=-1;
#endif
		if (indicat==-1||risnull(CDATETYPE,(void*)infx)) { A4GL_setnull(DTYPE_DATE,(void *)a4gl,size); return;}
		A4GL_debug("Got date as : '%d' %x",*infx,*infx);
		orig_date=*infx;
		rjulmdy(orig_date,mdy); 				// Get the MDY from informix
		A4GL_debug("copy_date : mode=o - %d %d %d",mdy[0],mdy[1],mdy[2]);
		*a4gl=A4GL_gen_dateno(mdy[1],mdy[0],mdy[2]); 	// And use it to generate an aubit.
	}
}



/**
 *
 *
 * @todo describe function
 */
void 
ESQLAPI_A4GL_copy_smint(short *infx,short *a4gl,int indicat,int size,int mode) 
{
	if (mode=='i') {
		if (A4GL_isnull(1,(void *)a4gl)) {rsetnull(CSHORTTYPE,(void *)infx);return;}
		*infx=*a4gl;
	}
	if (mode=='o') {
		if (indicat==-1||risnull(CSHORTTYPE,(void*)infx)) { A4GL_setnull(1,(void *)a4gl,size); return;}
		*a4gl=*infx;
	}
}


/**
 *
 *
 * @todo describe function
 */
void 
ESQLAPI_A4GL_copy_int(long *infx,long *a4gl,int indicat,int size,int mode) 
{
	if (mode=='i') {
		if (A4GL_isnull(2,(void *)a4gl)) {rsetnull(CLONGTYPE,(void *)infx);return;}
		*infx=*a4gl;
	}
	if (mode=='o') {
		if (indicat==-1||risnull(CLONGTYPE,(void*)infx)) { A4GL_setnull(2,(void *)a4gl,size); return;}
		*a4gl=*infx;
	}
}


/**
 *
 *
 * @todo describe function
 */
void 
ESQLAPI_A4GL_copy_float(float *infx,float *a4gl,int indicat,int size,int mode) 
{
	if (mode=='i') {
		if (A4GL_isnull(4,(void *)a4gl)) {rsetnull(CFLOATTYPE,(void *)infx);return;}
		*infx=*a4gl;
	}
	if (mode=='o') {
		if (indicat==-1||risnull(CFLOATTYPE,(void*)infx)) { A4GL_setnull(4,(void *)a4gl,size); return;}
		*a4gl=*infx;
	}
}


/**
 *
 *
 * @todo describe function
 */
void 
ESQLAPI_A4GL_copy_double(double *infx,double *a4gl,int indicat,int size,int mode) 
{
	if (mode=='i') {
		if (A4GL_isnull(3,(void *)a4gl)) {rsetnull(CDOUBLETYPE,(void *)infx);return;}
		*infx=*a4gl;
	}
	if (mode=='o') {
		if (indicat==-1||risnull(CDOUBLETYPE,(void*)infx)) { A4GL_setnull(3,(void *)a4gl,size); return;}
		*a4gl=*infx;
	}
}


/**
 *
 *
 * @todo describe function
 */
void 
popdec(void *vx)
{
#ifdef DIALECT_POSTGRES
EXEC SQL BEGIN DECLARE SECTION;
	decimal *x;
EXEC SQL END DECLARE SECTION;
#else
	dec_t *x;
#endif
        char *s;
	x=vx;
        s=A4GL_char_pop();
        deccvasc(s,strlen(s),x);
        free(s);
}

/**
 *
 *
 * @todo describe function
 */
void 
retdec(void *vx) 
{
	dec_t *x;
        fgldecimal _s;
	x=vx;
        A4GL_copy_decimal(x,&_s,0,0x1e10,'o');
        A4GL_push_variable(&_s,0x1e100005);
}

/**
 *
 *
 * @todo describe function
 */
void 
popdtime(void *vx) 
{
	dtime_t *x;
        char *s;
	x=vx;
        s=A4GL_char_pop();
        dtcvasc(s,x);
        free(s);
}


/**
 *
 *
 * @todo describe function
 */
void 
retdtime(void *vx) 
{
        char s[123];
	dtime_t *x;
        struct A4GLSQL_dtime d;
	x=vx;
        dttoasc(x,s);
}


/**
 *
 *
 * @todo describe function
 */
ESQLAPI_A4GLESQL_initlib() 
{

}




/* ============================================ EOF ========================================= */


/*
 * +----------------------------------------------------------------------+
 * | Aubit 4gl Language Compiler Version $.0                              |
 * +----------------------------------------------------------------------+
 * | Copyright (c) 2000-4 Aubit Development Team (See Credits file)       |
 * +----------------------------------------------------------------------+
 * | This program is free software; you can redistribute it and/or modify |
 * | it under the terms of one of the following licenses:                 |
 * |                                                                      |
 * |  A) the GNU General Public License as published by the Free Software |
 * |     Foundation; either version 2 of the License, or (at your option) |
 * |     any later version.                                               |
 * |                                                                      |
 * |  B) the Aubit License as published by the Aubit Development Team and |
 * |     included in the distribution in the file: LICENSE                |
 * |                                                                      |
 * | This program is distributed in the hope that it will be useful,      |
 * | but WITHOUT ANY WARRANTY; without even the implied warranty of       |
 * | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        |
 * | GNU General Public License for more details.                         |
 * |                                                                      |
 * | You should have received a copy of both licenses referred to here.   |
 * | If you did not, or have any questions about Aubit licensing, please  |
 * | contact licences@aubit4gl.org
 * +----------------------------------------------------------------------+
 *
 * $Id: decimal.h,v 1.2 2004-06-03 11:45:44 mikeaubury Exp $
 */

/**
 * @file
 * Header file to define data types and macros to allow legacy c source files
 * to work without any change in an Informix 4gl to aubit 4gl porting.
 */

#ifndef _DECIMAL_H
#define _DECIMAL_H
#include "a4gl_libaubit4gl.h"

#ifdef __cplusplus
extern "C"
{
#endif


/** Define the informix decimal type as the aubit4gl type */
typedef FglDecimal dec_t;



int A4GL_declib_decadd  (fgldecimal *fgld, fgldecimal *fgld2, fgldecimal *fgld3) ;
int A4GL_declib_deccmp  (fgldecimal *fgld, fgldecimal *fgl2) ;
void A4GL_declib_deccopy        (fgldecimal *fgld1, fgldecimal *fgld2) ;
int A4GL_declib_deccvasc        (char *str, int len, fgldecimal *fgld) ;
int A4GL_declib_deccvdbl        (double d, fgldecimal *fgld) ;
int A4GL_declib_deccvflt        (double src, fgldecimal *dest) ;
int A4GL_declib_deccvint        (int in, fgldecimal *fgld) ;
int A4GL_declib_deccvlong       (long lng, fgldecimal *fgld) ;
int A4GL_declib_decdiv  (fgldecimal *fgld1, fgldecimal *fgld2, fgldecimal *fgld3) ;
char* A4GL_declib_dececvt       (fgldecimal *fgld, int ndigits, int *decpt, int *sign) ;
char* A4GL_declib_decfcvt       (fgldecimal *fgld, int ndigits, int *decpt, int *sign) ;
int A4GL_declib_decmul  (fgldecimal *fgld1, fgldecimal *fgld2, fgldecimal *fgld3);
void A4GL_declib_decround       (fgldecimal *fgld, int dec_round) ;
int A4GL_declib_decsub  (fgldecimal *fgld1, fgldecimal *fgld2, fgldecimal *fgld3) ;
int A4GL_declib_dectoasc        (fgldecimal *fgld, char *str, int len, int right) ;
int A4GL_declib_dectodbl        (fgldecimal *fgld, double *d) ;
int A4GL_declib_dectoflt        (fgldecimal *src, float *dest) ;
int A4GL_declib_dectoint        (fgldecimal *fgld, int *i) ;
int A4GL_declib_dectolong       (fgldecimal *fgld, long *l) ;
void A4GL_declib_dectrunc       (fgldecimal *fgld, int trunc) ;

#define decadd  	A4GL_declib_decadd  
#define deccmp  	A4GL_declib_deccmp  
#define deccopy   	A4GL_declib_deccopy   
#define deccvasc  	A4GL_declib_deccvasc  
#define deccvdbl  	A4GL_declib_deccvdbl  
#define deccvflt  	A4GL_declib_deccvflt  
#define deccvint  	A4GL_declib_deccvint  
#define deccvlong 	A4GL_declib_deccvlong 
#define decdiv  	A4GL_declib_decdiv  
#define dececvt 	A4GL_declib_dececvt 
#define decfcvt  	A4GL_declib_decfcvt  
#define decmul  	A4GL_declib_decmul  
#define decround 	A4GL_declib_decround 
#define decsub 		A4GL_declib_decsub 
#define dectoasc    	A4GL_declib_dectoasc     
#define dectodbl    	A4GL_declib_dectodbl     
#define dectoflt    	A4GL_declib_dectoflt     
#define dectoint    	A4GL_declib_dectoint    
#define dectolong   	A4GL_declib_dectolong   
#define dectrunc    	A4GL_declib_dectrunc    





#ifdef __cplusplus
}
#endif

#endif

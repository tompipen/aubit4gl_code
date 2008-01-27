/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-2005 Aubit Development Team (See Credits file)    |
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
# $Id: a4gl_incl_4glhdr.h,v 1.46 2008-01-27 15:08:05 mikeaubury Exp $
*/

/**
 * @file
 * Header file used to include in the generated c files with origin
 * in the 4gl source files.
 *
 * This file is NOT included from anywhere else - compile_c.c prints
 * include statemennt for this file when outputing C code that is result
 * of compiling 4gl code by 4glc
 *
 * Therefore, this file contains definitions and prototypes that are
 * needed ONLY when compiling/running compiled programs, and NOT anywhere else in
 * Aubit compiler or libraries code.
 *
 */

#ifndef FGLHDR_INCL
#define FGLHDR_INCL

#ifdef __cplusplus
extern "C"
{
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "a4gl_expr.h"
#include "a4gl_incl_4gldef.h"
#include "a4gl_4gl_callable.h"
#ifdef DMALLOC
#include "dmalloc.h"
#endif


#define A4GL_fglerror(a,b) A4GL_fgl_error(__LINE__,__FILE__,a,b)
#define DO_BEFORE_DELETE  (_fld_dr==-12)
#define DO_AFTER_DELETE  (_fld_dr==-13)
#define DO_BEFORE_INSERT  (_fld_dr==-14)
#define DO_AFTER_INSERT  (_fld_dr==-15)
#define BEF_ROW (_fld_dr==-10)
#define AFT_ROW  (_fld_dr==-11)
#define BEFORE_INP  (_fld_dr==-99)
#define AFTER_INP  (_fld_dr==-95)
#define ON_KEY(zzz)  (_fld_dr==-90&&A4GL_chk_iskey(_sio,_sio_kw,zzz))
#define DEF_ASS(uass,d) char * uass[d]={(char *)-1}

#define OP_MASK (512|1024)
#define OP_MASK_BASE 512


#define NUMERIC_OP_2  (1*OP_MASK_BASE)
#define STRING_OP_S1 (2*OP_MASK_BASE)
#define STRING_OP_S2 (4*OP_MASK_BASE)
#define STRING_OP_N1 (8*OP_MASK_BASE)
#define STRING_OP_N2 (16*OP_MASK_BASE)
#define FUNCTION_OP (32*OP_MASK_BASE)
#define BOOLEAN_OP (64*OP_MASK_BASE)
#define OTHER_OP (128*OP_MASK_BASE)


  /* add no more than 15 items to any of the following groups */
#define OP_ADD (1|NUMERIC_OP_2)
#define OP_SUB (2|NUMERIC_OP_2)
#define OP_MULT (3|NUMERIC_OP_2)
#define OP_DIV (4|NUMERIC_OP_2)
#define OP_POWER (5|NUMERIC_OP_2)
#define OP_MOD (6|NUMERIC_OP_2)

#define OP_CLIP (1|STRING_OP_S1)
#define OP_CONCAT (1|STRING_OP_S2)
#define OP_COPY (2|STRING_OP_S2)
#define OP_USING (3|STRING_OP_S2)
#define OP_MATCHES (4|STRING_OP_S2)
#define OP_LIKE (5|STRING_OP_S2)

#define OP_YEAR (1|STRING_OP_N1)
#define OP_MONTH (2|STRING_OP_N1)
#define OP_DAY (3|STRING_OP_N1)
#define OP_HOUR (4|STRING_OP_N1)
#define OP_MINUTE (5|STRING_OP_N1)
#define OP_SECOND (6|STRING_OP_N1)

#define OP_SUBSTR1 (1|STRING_OP_N2)
#define OP_SUBSTR2 (1|STRING_OP_N3)

#define OP_EQUAL (1|BOOLEAN_OP)
#define OP_LESS_THAN (2|BOOLEAN_OP)
#define OP_GREATER_THAN (3|BOOLEAN_OP)
#define OP_NOT_EQUAL (4|BOOLEAN_OP)
#define OP_LESS_THAN_EQ (5|BOOLEAN_OP)
#define OP_GREATER_THAN_EQ (6|BOOLEAN_OP)
#define OP_AND (7|BOOLEAN_OP)
#define OP_OR (8|BOOLEAN_OP)
#define OP_NOT (9|BOOLEAN_OP)
#define OP_ISNULL (10|BOOLEAN_OP)
#define OP_ISNOTNULL (11|BOOLEAN_OP)
  /* 12|BOOLEAN reserved for OP_MATH which is used internally */

#define OP_IN (1|OTHER_OP)
#define OP_NOTIN (2|OTHER_OP)
#define OP_IN_SELECT (3|OTHER_OP)
#define OP_NOTIN_SELECT (4|OTHER_OP)
#define OP_EXISTS (5|OTHER_OP)
#define OP_NOTEXISTS (6|OTHER_OP)

#define ENCODE_SIZE(x) (x<<16)
#define DECODE_SIZE(x) (x>>16)

#include "a4gl_memhandling.h"

#define GETSETNEW -1
#define GETSETRM -2
#define GETSETGET 1
#define GETSETSET 2
#define GETSETGETPTR 3
#define GETPTR(struct,ptr,element) A4GL_get_set(struct,ptr,GETSETGETPTR,element,0)
#define GET(struct,ptr,element) A4GL_get_set(struct,ptr,GETSETGET,element,0)
#define GET_AS_INT(struct,ptr,element) A4GL_get_set_as_int(struct,ptr,GETSETGET,element,0)
#define SET(struct,ptr,element,value) A4GL_get_set(struct,ptr,GETSETSET,element,(long)value)
#define NEW(struct) A4GL_get_set(struct,0,GETSETNEW,0,0)
#define RM(struct,ptr) A4GL_get_set(struct,ptr,GETSETRM,0,0)
void *A4GL_get_set (char *str, void *ptr, int mode, char *name, long var);
int A4GL_get_set_as_int (char *str, void *ptr, int mode, char *name, long var);

#define REPORT_START -1
#define REPORT_FINISH -2
#define REPORT_DATA -3
#define REPORT_OPS_COMPLETE -4
#define REPORT_AFTERDATA -5
#define REPORT_SENDDATA -6
#define REPORT_BEFOREDATA -7
#define REPORT_BEFOREGROUP -8
#define REPORT_AFTERGROUP -9
#define REPORT_LASTROW -10
#define REPORT_PAGEHEADER -11
#define REPORT_FIRSTPAGEHEADER -12
#define REPORT_LASTDATA -13
#define REPORT_PAGETRAILER -14
#define REPORT_RESTART -15
#define REPORT_CONVERT -16
#define REPORT_FREE    -17
#define REPORT_NOTHING    -20
#define REPORT_TERMINATE -9999


#define ERR_BADNOARGS 1000
#define ABORT 1
#define WARN 2


#ifndef S_CONSTR_LIST
#define S_CONSTR_LIST
struct s_constr_list {
	char *tabname;
	char *colname;
	char *value;
	char *fldbuf;
	};
#endif
//#include "a4gl_screenio.h"
/*
#ifndef NODEBUG
#define A4GL_debug A4GL_set_line(__FILE__,__LINE__),A4GL_debug_full
#else
#define A4GL_debug null_func
#endif
*/

#ifndef NODEBUG

#if __STDC_VERSION__ < 199901L
# if __GNUC__ >= 2
#  define __func__ __FUNCTION__
# else
#  define __func__ "<unknown>"
# endif
#endif

/*
#define A4GL_ftl A4GL_set_line_extended(__FILE__,__LINE__,"FTL",__func__),A4GL_debug_full_extended
#define A4GL_err A4GL_set_line_extended(__FILE__,__LINE__,"ERR",__func__),A4GL_debug_full_extended
#define A4GL_wrn A4GL_set_line_extended(__FILE__,__LINE__,"WRN",__func__),A4GL_debug_full_extended
#define A4GL_inf A4GL_set_line_extended(__FILE__,__LINE__,"inf",__func__),A4GL_debug_full_extended
#define A4GL_dbg A4GL_set_line_extended(__FILE__,__LINE__,"dbg",__func__),A4GL_debug_full_extended
#define A4GL_debug A4GL_dbg
*/

#define A4GL_ftl(fmt,...) A4GL_debug_full_extended_ln(__FILE__,__LINE__,"FTL",__func__, fmt,## __VA_ARGS__)
#define A4GL_err(fmt,...) A4GL_debug_full_extended_ln(__FILE__,__LINE__,"ERR",__func__, fmt,## __VA_ARGS__)
#define A4GL_wrn(fmt,...) A4GL_debug_full_extended_ln(__FILE__,__LINE__,"WRN",__func__, fmt,## __VA_ARGS__)
#define A4GL_inf(fmt,...) A4GL_debug_full_extended_ln(__FILE__,__LINE__,"inf",__func__, fmt,## __VA_ARGS__)
#define A4GL_dbg(fmt,...) A4GL_debug_full_extended_ln(__FILE__,__LINE__,"dbg",__func__, fmt,## __VA_ARGS__)
#define A4GL_debug A4GL_dbg

#ifdef DEBUG
#define A4GL_trc(fmt,...) A4GL_debug_full_extended_ln(__FILE__,__LINE__,"trc",__func__, fmt, ## __VA_ARGS__)
#else //!DEBUG
#define A4GL_trc 
#endif //DEBUG

#else //!NODEBUG

#define A4GL_ftl(fmt,...) 
#define A4GL_err(fmt,...) 
#define A4GL_wrn(fmt,...) 
#define A4GL_inf(fmt,...) 
#define A4GL_dbg(fmt,...) 
#define A4GL_trc(fmt,...) 

#endif //NODEBUG

#define MENU_ALL "_AlL_"

#ifdef __cplusplus
}
#endif
#endif				/* #ifndef FGLHDR_INCL */

/*******************************************************************
* (c) 1997-2002 Aubit Computing Ltd.
*
* This header file should detect the current ESQL/C compiler as
* set the datatype conversion routines as required...
********************************************************************/

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

#ifdef __cplusplus
extern "C"
{
#endif
#include "a4gl_incl_4gldef.h"
#include "a4gl_incl_infx.h"


#ifdef __WIN32__
				/* PG 8 on windows have ecpg_informix.h and no decimal.h */
				#include "ecpg_informix.h"
				/* this used to be in sqltypes.h but on Windows PG8 does not  */
				/* exist at all: */
					#ifndef ECPG_SQLTYPES_H
						#define ECPG_SQLTYPES_H
						
						#define CCHARTYPE	ECPGt_char
						#define CSHORTTYPE	ECPGt_short
						#define CINTTYPE	ECPGt_int
						#define CLONGTYPE	ECPGt_long
						#define CFLOATTYPE	ECPGt_float
						#define CDOUBLETYPE ECPGt_double
						#define CDECIMALTYPE	ECPGt_decimal
						#define CFIXCHARTYPE	108
						#define CSTRINGTYPE ECPGt_char
						#define CDATETYPE	ECPGt_date
						#define CMONEYTYPE	111
						#define CDTIMETYPE	ECPGt_timestamp
						#define CLOCATORTYPE	113
						#define CVCHARTYPE	ECPGt_varchar
						#define CINVTYPE	115
						#define CFILETYPE	116
						#define CINT8TYPE	ECPGt_long_long
						#define CCOLLTYPE		118
						#define CLVCHARTYPE		119
						#define CFIXBINTYPE		120
						#define CVARBINTYPE		121
						#define CBOOLTYPE		ECPGt_bool
						#define CROWTYPE		123
						#define CLVCHARPTRTYPE	124
						#define CTYPEMAX	25
					
					#endif /* ndef ECPG_SQLTYPES_H */
	
					/*in datetime.h on UNIX but missing on Windows PG8 */
					#ifndef _ECPG_DATETIME_H
						#define _ECPG_DATETIME_H
						
						/*missing on Windows PG8:
						//#include <compatlib.h>
						//this is full compatlib.h from UNIX: */
						#ifndef _COMPATLIB_H
							#define _COMPATLIB_H
							/*
							 * This file contains stuff needed to be as compatible to other DBMS as possible.
							 */
							
							#include <ecpglib.h>
							#include <pgtypes_date.h>
							#include <pgtypes_interval.h>
							#include <pgtypes_numeric.h>
							#include <pgtypes_timestamp.h>
							
							/* The following stuff is for Informix compatibility */
							
							#define SQLNOTFOUND 100
							
							#define SQLSMINT 1
							#define SQLINT 2
							#define SQLFLOAT 3
							#define SQLSMFLOAT 4
							#define SQLDECIMAL 5
							#define SQLSERIAL 6
							#define SQLDATE 7
							#define SQLMONEY 8
							#define SQLNULL 9
							#define SQLDTIME 10
							#define SQLBYTES 11
							#define SQLTEXT 12
							#define SQLVCHAR 13
							#define SQLINTERVAL 14
							#define SQLNCHAR 15
							#define SQLNVCHAR 16
							#define SQLINT8 17
							#define SQLSERIAL8 18
							#define SQLSET 19
							#define SQLMULTISET 20
							#define SQLLIST 21
							#define SQLROW 22
							#define SQLCOLLECTION 23
							#define SQLROWREF 24
							
							#define SQLUDTVAR 40
							#define SQLUDTFIXED 41
							#define SQLREFSER8 42
							
							/* These types are used by FE, they are not real major types in BE */
							#define SQLLVARCHAR 43
							#define SQLSENDRECV 44
							#define SQLBOOL 45
							#define SQLIMPEXP 46
							#define SQLIMPEXPBIN 47
							
							/* This type is used by the UDR code to track default parameters,
							it is not a real major type in BE */
							#define SQLUDRDEFAULT 48
							
							#define SQLMAXTYPES 49
							
							#define SQLLABEL SQLINT
							
							#define SQLTYPE 0xFF /* type mask */
							
							
							
							#define ECPG_INFORMIX_NUM_OVERFLOW	-1200
							#define ECPG_INFORMIX_NUM_UNDERFLOW	-1201
							#define ECPG_INFORMIX_DIVIDE_ZERO	-1202
							#define ECPG_INFORMIX_BAD_YEAR		-1204
							#define ECPG_INFORMIX_BAD_MONTH		-1205
							#define ECPG_INFORMIX_BAD_DAY		-1206
							#define ECPG_INFORMIX_ENOSHORTDATE	-1209
							#define ECPG_INFORMIX_DATE_CONVERT	-1210
							#define ECPG_INFORMIX_OUT_OF_MEMORY	-1211
							#define ECPG_INFORMIX_ENOTDMY		-1212
							#define ECPG_INFORMIX_BAD_NUMERIC	-1213
							#define ECPG_INFORMIX_BAD_EXPONENT	-1216
							#define ECPG_INFORMIX_BAD_DATE		-1218
							#define ECPG_INFORMIX_EXTRA_CHARS	-1264
							
							#ifdef __cplusplus
							extern "C"
							{
							#endif
							extern int	rdatestr(date, char *);
							extern void 	rtoday(date *);
							extern int	rjulmdy(date, short *);
							extern int	rdefmtdate(date *, char *, char *);
							extern int	rfmtdate(date, char *, char *);
							extern int	rmdyjul(short *, date *);
							extern int	rstrdate(char *, date *);
							extern int	rdayofweek(date);
							
							extern int	rfmtlong(long, char *, char *);
							extern int	rgetmsg(int, char *, int);
							extern int	risnull(int, char *);
							extern int	rsetnull(int, char *);
							extern int	rtypalign(int, int);
							extern int	rtypmsize(int, int);
							extern int	rtypwidth(int, int);
							extern void 	rupshift(char *);
							
							extern int	byleng(char *, int);
							extern void ldchar(char *, int, char *);
							
							extern void ECPG_informix_set_var(int, void *, int);
							extern void *ECPG_informix_get_var(int);
							
							/* Informix defines these in decimal.h */
							int	decadd(decimal *, decimal *, decimal *);
							int	deccmp(decimal *, decimal *);
							void	deccopy(decimal *, decimal *);
							int	deccvasc(char *, int, decimal *);
							int	deccvdbl(double, decimal *);
							int	deccvint(int, decimal *);
							int	deccvlong(long, decimal *);
							int	decdiv(decimal *, decimal *, decimal *);
							int	decmul(decimal *, decimal *, decimal *);
							int	decsub(decimal *, decimal *, decimal *);
							int	dectoasc(decimal *, char *, int, int);
							int	dectodbl(decimal *, double *);
							int	dectoint(decimal *, int *);
							int	dectolong(decimal *, long *);
							
							/* Informix defines these in datetime.h */
							
							extern void	dtcurrent(timestamp *);
							extern int  	dtcvasc(char *, timestamp *);
							extern int  	dtsub(timestamp *, timestamp *, interval *);
							extern int	dttoasc(timestamp *, char *);
							extern int	dttofmtasc(timestamp *, char *, int, char *);
							extern int	intoasc(interval *, char *);
							extern int	dtcvfmtasc(char *, char *, timestamp *);
							#ifdef __cplusplus
							}
							#endif
						#endif /* ndef _COMPATLIB_H */
						
						typedef timestamp dtime_t;
						typedef interval intrvl_t;
					
					#endif /* ndef _ECPG_DATETIME_H */

					/* decimal.h on UNIX, but missing on Windows PG8 */
					#ifndef _ECPG_DECIMAL_H
						#define _ECPG_DECIMAL_H
						/*
						//mising on Win PG8, allready defined above:
						//#include <compatlib.h>
							*/
						
						typedef decimal dec_t;
						
					#endif /* ndef _ECPG_DECIMAL_H */
#endif



#ifdef HAVE_CONFIG_H
	/* header automatically created with AutoConf-configure */
	#include "a4gl_incl_config.h"
#endif


#if (HAVE_PGSQL_INFORMIX_ESQL_DECIMAL_H == 1)
	#include "pgsql/informix/esql/decimal.h"
#else
	#if (HAVE_POSTGRESQL_INFORMIX_ESQL_DECIMAL_H == 1)
		#include "postgresql/informix/esql/decimal.h"
	#else
		#if (HAVE_DECIMAL_H == 1)
		/* This is dangerous; Informix esqlc and Aubit also have decimal.h */
			/* Who knows which one we will actually include like this... */
			#include "decimal.h"
		#else
			#ifndef __WIN32__			
				/* configure did not find decimal.h, in whic case compiling ECPG PG */
				/* stuff should have been disabled, but you are still here somehow... */
				/* #include "decimal.h" */
				/* make sure we cause compile-time error here: */
				#include "informix/esql/decimal.h"
			#endif
		#endif
	#endif
#endif



#ifndef __WIN32__
	#if PG_ESQLC_V3
		#include "informix/esql/sqltypes.h"
		#include "informix/esql/datetime.h"
		#include "informix/esql/decimal.h"
	#else
		#include "sqltypes.h"
	#endif
#endif

#define COPY_DATA_IN_0(a4gl,pgres,i,size,x,y) A4GL_copy_char(pgres,a4gl,i,size,'i',x,y)
#define COPY_DATA_IN_1(a4gl,pgres,i,size) A4GL_copy_smint(pgres,a4gl,i,size,'i')
#define COPY_DATA_IN_2(a4gl,pgres,i,size) A4GL_copy_int(pgres,a4gl,i,size,'i')
#define COPY_DATA_IN_3(a4gl,pgres,i,size) A4GL_copy_double(pgres,a4gl,i,size,'i')
#define COPY_DATA_IN_4(a4gl,pgres,i,size) A4GL_copy_float(pgres,a4gl,i,size,'i')
#define COPY_DATA_IN_5(a4gl,pgres,i,size) A4GL_copy_decimal(pgres,a4gl,i,size,'i')
#define COPY_DATA_IN_6(a4gl,pgres,i,size) A4GL_copy_int(pgres,a4gl,i,size,'i')
#define COPY_DATA_IN_7(a4gl,pgres,i,size) A4GL_copy_date(pgres,a4gl,i,size,'i')
#define COPY_DATA_IN_8(a4gl,pgres,i,size) A4GL_copy_money(pgres,a4gl,i,size,'i')
#define COPY_DATA_IN_9(a4gl,pgres,i,size) A4GL_copy_int(pgres,a4gl,i,size,'i')
#define COPY_DATA_IN_10(a4gl,pgres,i,size) A4GL_copy_datetime(pgres,a4gl,i,size,'i')
#define COPY_DATA_IN_11(a4gl,pgres,i,size) A4GL_copy_blob_byte(pgres,a4gl,i,size,'i')
#define COPY_DATA_IN_12(a4gl,pgres,i,size) A4GL_copy_blob_text(pgres,a4gl,i,size,'i')
#define COPY_DATA_IN_13(a4gl,pgres,i,size,x,y) A4GL_copy_char(pgres,a4gl,i,size,'i',x,y)

/*
// wrong? 
//#define COPY_DATA_IN_14(a4gl,pgres,size,x,y) A4GL_copy_interval(pgres,a4gl,0,size,'i',x,y)
*/
#define COPY_DATA_IN_14(a4gl,pgres,size,x,y) A4GL_copy_interval(pgres,a4gl,0,size,'i')

#define COPY_DATA_OUT_0(a4gl,pgres,i,size,x,y) A4GL_copy_char(pgres,a4gl,i,size,'o',x,y)
#define COPY_DATA_OUT_1(a4gl,pgres,i,size) A4GL_copy_smint(pgres,a4gl,i,size,'o')
#define COPY_DATA_OUT_2(a4gl,pgres,i,size) A4GL_copy_int(pgres,a4gl,i,size,'o')
#define COPY_DATA_OUT_3(a4gl,pgres,i,size) A4GL_copy_double(pgres,a4gl,i,size,'o')
#define COPY_DATA_OUT_4(a4gl,pgres,i,size) A4GL_copy_float(pgres,a4gl,i,size,'o')
#define COPY_DATA_OUT_5(a4gl,pgres,i,size) A4GL_copy_decimal(pgres,a4gl,i,size,'o')
#define COPY_DATA_OUT_6(a4gl,pgres,i,size) A4GL_copy_int(pgres,a4gl,i,size,'o')
#define COPY_DATA_OUT_7(a4gl,pgres,i,size) A4GL_copy_date(pgres,a4gl,i,size,'o')
#define COPY_DATA_OUT_8(a4gl,pgres,i,size) A4GL_copy_money(pgres,a4gl,i,size,'o')
#define COPY_DATA_OUT_9(a4gl,pgres,i,size) A4GL_copy_int(pgres,a4gl,i,size,'o')
#define COPY_DATA_OUT_10(a4gl,pgres,i,size) A4GL_copy_datetime(pgres,a4gl,i,size,'o')
#define COPY_DATA_OUT_11(a4gl,pgres,i,size) A4GL_copy_blob_byte(pgres,a4gl,i,size,'o')
#define COPY_DATA_OUT_12(a4gl,pgres,i,size) A4GL_copy_blob_text(pgres,a4gl,i,size,'o')
#define COPY_DATA_OUT_13(a4gl,pgres,i,size,x,y) A4GL_copy_char(pgres,a4gl,i,size,'o',x,y)
#define COPY_DATA_OUT_14(a4gl,pgres,i,size) A4GL_copy_interval(pgres,a4gl,i,size,'o')


#define A4GLSQL_SET_SQLCA_SQLWARN A4GL_copy_sqlca_sqlawarn_string8(sqlca.sqlwarn)


/* There may be some circumstances where we don't want to do automatic SQL conversions */
#ifndef NO_SQL_TRANSLATION
	#define CONVERTSQL(s) A4GLSQLCV_convert_sql_ml("POSTGRES",s,_module_name,__LINE__)
	#define CONVERTSQL_LN(s,l) A4GLSQLCV_convert_sql_ml("POSTGRES",s,_module_name,l)
#else
	#define CONVERTSQL(s) s
	#define CONVERTSQL_LN(s,l) s
#endif

#define copy_sqlca

/*#define dtime_t datetime 
//#define popdec(x) {char *s;s=A4GL_char_pop();printf("%s\n",s);deccvasc(s,strlen(s),x); }
//#define retdec(x) {fgldecimal _s;A4GL_copy_decimal(x,&_s,0x1e10,'o');A4GL_push_variable(&_s,0x1e100005);}
*/

#ifdef __cplusplus
}
#endif

/*
@(#)File:            $RCSfile: esqlc.h,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-06-20 04:05:07 $
@(#)Purpose:         Include all relevant ESQL/C type definitions
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1992-93,1995-2002
@(#)Product:         :PRODUCT:
*/

/*
** Include all ESQL/C Headers with prototypes where possible.
** Support for ESQL/C Versions 5.x, 6.x, 7.1x, 7.2x, 9.x is
** believed to be sound.
** Support for ESQL/C Versions 7.0x, 8.0x or 8.1x is unproven; support
** for 8.2x is dubious.
**
** Support for ESQL/C 4.x was dropped at the end of 2001.
** Versions of ESQL/C prior to 4.00 never were supported.
**
** Note that the ESQL/C 4.x and earlier versions placed the headers
** directly in $INFORMIXDIR/incl, but ESQL/C versions 5.00 and later
** place the headers in $INFORMIXDIR/incl.
*/

#ifndef ESQLC_H
#define ESQLC_H

#ifdef MAIN_PROGRAM
#ifndef lint
static const char esqlc_h[] = "@(#)$Id: esqlc.h,v 1.1 2002-06-20 04:05:07 afalout Exp $";
#endif	/* lint */
#endif	/* MAIN_PROGRAM */

#ifdef HAVE_CONFIG_H
/*
** Needed to resolve const-ness problems on AIX 4.2, thanks to the ESQL/C
** headers in CSDK 2.10, 2.30, etc.
*/
#include "config.h"
#endif /* HAVE_CONFIG_H */

/* If ESQLC_VERSION isn't defined, use version 0 */
#ifndef ESQLC_VERSION
#define ESQLC_VERSION 0
#endif /* ESQLC_VERSION */

/*
** On DEC OSF/1 and 64-bits machines, __STDC__ is not necessarily defined,
** but the use of prototypes is necessary under optimization to ensure that
** pointers are treated correctly (sizeof(void *) != sizeof(int)).
** The <sqlhdr.h> prototypes for version 6.00 and above are only active if
** __STDC__ is defined (whether 1 or 0 or something else does not matter).
** Ensure that the compilation options set __STDC__.
*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*
** Some C compilers which can support prototypes do not set __STDC__ at
** all; the C compiler on AIX 4.2 is a case in point.  In some versions
** of ESQL/C (CSDK 2.10, CSDK 2.30, etc), decimal.h and datetime.h only
** declare the function prototypes if __STDC__ is set or if __cplusplus
** is set.  Internally, they set STDC_FLAG to 1 and declare the
** prototypes if STDC_FLAG is set.  All the compilers supported by JLSS
** support prototypes (by definition), so force the prototypes unless
** JLSS_DO_NOT_FORCE_PROTOTYPES is set.  Consistency is wonderful; in
** some versions of ESQL/C (CSDK 2.10, CSDK 2.30, etc), sqlhdr.h uses a
** macro STDC_ENABLE instead of STDC_FLAG.
*/
#ifndef JLSS_DO_NOT_FORCE_PROTOTYPES
#ifndef STDC_FLAG
#define STDC_FLAG 1
#endif /* STDC_FLAG */
#ifndef STDC_ENABLE
#define STDC_ENABLE 1
#endif /* STDC_ENABLE */
#endif /* JLSS_DO_NOT_FORCE_PROTOTYPES */

/*
** AIX pre-empts the use of loc_t (by declaring a type of that name in
** the header file /usr/include/sys/localedef31.h, as it is entitled to
** do according to POSIX.1, if not ISO C).  The standard workaround is
** to define _H_LOCALEDEF on the compiler command line; doing it in this
** header usually does not work.
*/

/* -- Include Files	*/

/*
** Note that an earlier version of this file protected varchar.h with
** #if ESQLC_VERSION >= 400, but did not protect either datetime.h or
** locator.h in the same way, even though neither of those files was
** present prior to version 4.00.
*/

#include <datetime.h>
#include <decimal.h>
#include <locator.h>
#include <sqlca.h>
#include <sqlda.h>
#include <sqlstype.h>
#include <sqltypes.h>
#include <varchar.h>

/* _WIN32 (Windows 95/NT code from Harald Ums <Harald.Ums@sevensys.de> */

#if ESQLC_VERSION < 500
/* No prototypes available -- for earlier versions, you are on your own! */
#elif ESQLC_VERSION < 600
#ifdef _WIN32
#include <windows.h>
#include <sqlhdr.h>
#include <sqlproto.h>
#else
#include "esql5_00.h"
#include "esqllib.h"
#endif /* _WIN32 */
#else
/* For later versions, sqlhdr.h contains the requisite declarations. */
/* However, these declarations are protected by __STDC__ so you need */
/* to ensure that your compiler has it defined.  Note that compilers */
/* on some machines do complain if you try to define __STDC__.       */
#include <sqlhdr.h>

/*
** ClientSDK 2.01 or later needs sqliapi.h; it is unknown whether
** ClientSDK 2.00 does too.  It is also unknown which version is
** reported by the ESQL/C compiler in ClientSDK 2.00 (with 2.01,
** the ESQL/C compiler reports 9.14).
*/
#if ESQLC_VERSION >= 730 && ESQLC_VERSION < 800
/* Probably an inaccurate value for ESQLC_VERSION -- should be 914 or greater */
#include <sqliapi.h>
#elif ESQLC_VERSION >= 914

/*
** To complete our happiness, in some versions of ESQL/C (CSDK 2.10,
** CSDK 2.30) sqliapi.h uses neither STDC_FLAG nor STDC_ENABLE, but
** tests directly on __STDC__ and __cplusplus.  So, for sqliapi.h, we
** have to set __STDC__ if it is not already set.  Not all C compilers
** will allow you to do this (and, specifically, the AIX compiler does
** not allow this).  So, we have to live without prototypes from
** sqliapi.h on AIX, and #undef const at the end.  This was reported as
** PTS Bug B118413, but won't be fixed before CSDK 2.50 at the earliest.
*/

#include <sqliapi.h>
#undef const

#endif /* ESQLC_VERSION ... */

#ifdef _WIN32
#include <sqlproto.h>
#else
#if ESQLC_VERSION >= 720 && ESQLC_VERSION < 730
#include "esql7_20.h"
#endif /* ESQLC_VERSION is 7.2x */

extern int      sqgetdbs(int *ret_fcnt,
                         char **fnames,
                         int fnsize,
                         char *farea,
                         int fasize);
#endif /* _WIN32 */

#endif /* ESQLC_VERSION */

/*
** Some code, notably esqlutil.h, relies on the typedef for value_t.
** However, value.h is not included by sqlhdr.h earlier than 7.20.
** The problem was found by David Edge <dedge@ak.blm.gov> in 7.10.UC1
** on AIX 4.2.1 and was confirmed on Solaris 2.6 with ESQL/C versions
** 5.08, 4.12, and 6.00.  Robert E Wyrick <rob@wyrick.org> had the
** problem with version 8.11.  Versions 8.00 through 8.1x probably had
** the same problem.  XPS 8.20 uses ClientSDK and hence ESQL/C 9.x.
** And the 7.2x version of sqlhdr.h only includes <value.h> when
** __STDC__ is defined, which makes the version-specific testing too
** complex.
**
** The symbol MAXADDR is defined in value.h.  The 4.12 and 5.08
** versions of value.h do not prevent multiple includes, leading to
** problems.  This test is not perfect; if code after #include
** "esqlc.h" includes value.h explicitly, it will not compile under
** many versions of ESQL/C.
*/
#ifndef MAXADDR
#include <value.h>
#endif /* MAXADDR */

/*
** Supply missing type information for IUS (IDS/UDO) data types.
** Two edged sword; it means you have to test rather carefully in
** your code whether to build with IUS data types or not.
** Should be keyed off ESQLC_VERSION, rather than features...
*/
#if ESQLC_VERSION < 900
#include "esql_ius.h"
#endif

/*
** JL 2001-01-23:
** Supply machine and version independent type names and printing
** macros.  Use the ixType names in code that should port to 64-bit
** environments with minimal fuss.  Note that int4 etc are defined
** with CSDK 2.30 (ESQL/C 9.21) and later versions.
** Note that the version-dependent headers such as esql4_00.h do not
** need to be modified to use these types -- they are not version
** independent, by definition.
*/
#include "esqltype.h"

/* -- Constant Definitions */

/* A table name may be: database@server:"owner".table */
/* This contains 5 punctuation characters and a null */
/*
** Note that from 9.2 up (and maybe 7.3 up and maybe from 8.3
** up), identifier names can be much longer -- up to 128 bytes
** each -- and user names can be up to 32 characters.
** Prior versions only allowed 18 characters for table, column,
** database and server names, and only 8 characters for user
** identifiers.
*/
#if (ESQLC_VERSION >= 730 && ESQLC_VERSION < 800) || \
	(ESQLC_VERSION >= 820 && ESQLC_VERSION < 900) || \
	(ESQLC_VERSION >= 920)
#define SQL_NAMELEN	128
#define SQL_USERLEN	32
#else
#define SQL_NAMELEN	18
#define SQL_USERLEN	8
#endif
#define SQL_TABNAMELEN	(3 * SQL_NAMELEN + SQL_USERLEN + sizeof("@:''."))
#define SQL_COLNAMELEN	(SQL_NAMELEN + 1)

#define loc_mode	lc_union.lc_file.lc_mode
#define sqlva		sqlvar_struct

/* -- Type Definitions */

#if ESQLC_VERSION >= 900
typedef struct tag_loc_t Blob;
#else
typedef loc_t		Blob;
#endif

typedef struct decimal	Decimal;
typedef struct dtime	Datetime;
typedef struct intrvl	Interval;
typedef struct sqlca_s	Sqlca;
typedef struct sqlda	Sqlda;
typedef struct sqlva	Sqlva;

#if ESQLC_VERSION >= 900

/* Type for casting dynamic SQL types to LVARCHAR */
typedef void *Lvarchar;

#endif /* ESQLC_VERSION >= 900 */

/* ESQL/C Features */
/* The ESQL/C compiler versions are defined in esqlinfo.h by autoconf */
#if ESQLC_VERSION >= 500
#define ESQLC_STORED_PROCEDURES
#define ESQLC_VARIABLE_CURSORS
#endif

#if ESQLC_VERSION >= 600
#define ESQLC_CONNECT
#endif

#if ESQLC_VERSION >= 720
#define ESQLC_CONNECT_DORMANT
#endif

#if ESQLC_VERSION >= 900
#define ESQLC_IUS_TYPES
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif	/* ESQLC_H */

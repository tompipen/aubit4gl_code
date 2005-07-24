/*
@(#)File:            $RCSfile: esql5_00.h,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-06-20 04:05:07 $
@(#)Purpose:         Function prototypes for ESQL/C Versions 5.00..5.10
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1992-93,1995-97,2000,2002
@(#)Product:         :PRODUCT:
*/

/*
**	@(#)Informix ESQL/C Version 5.0x ANSI C Function Prototypes
*/

/*
**  Beware:
**  ESQL/C version 5.00 has a 4-argument version of _iqlocate_cursor(), but
**  ESQL/C versions 5.02 and upwards (to 5.07 at least) have a 3-argument
**  version of _iqlocate_cursor().  Opinion is divided on whether version
**  5.01 used 3 or 4 arguments.  On SunOS 4.1.3, 5.01.UC1 used 4 arguments.
**  You must set ESQLC_VERSION accurately.
*/

#ifndef ESQL5_00_H
#define ESQL5_00_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* There is an unprototyped declaration of _iqlocate_cursor() in <sqlhdr.h> */
#undef _iqlocate_cursor
#define _iqlocate_cursor _iq_non_existent
#include <sqlhdr.h>
#undef _iqlocate_cursor

#include <sqlda.h>
#include <value.h>

#ifdef MAIN_PROGRAM
#ifndef lint
static const char esql5_00_h[] = "@(#)$Id: esql5_00.h,v 1.1 2002-06-20 04:05:07 afalout Exp $";
#endif	/* lint */
#endif	/* MAIN_PROGRAM */

#ifdef __cplusplus
#define ESQLC_STRICT_PROTOTYPES
#endif /* __cplusplus */

#ifdef ESQLC_STRICT_PROTOTYPES
/* A non-prototyped declaration for _iqnprep() is emitted by the compiler */
extern _SQCURSOR *_iqnprep(const char *name, const char *stmt, short cs_sens);
#else
extern _SQCURSOR *_iqnprep();
#endif /* ESQLC_STRICT_PROTOTYPES */

#ifdef ESQLC_SLOPPY_CONST
typedef char **CCPCCPC;
#else
/* The code generator emits a dubious declaration for the cmdtxt parameter. */
/* The CCPCCPC (const char pointer to const char pointer to const) typedef */
/* isn't entirely accurate (because the called code isn't prototyped, much */
/* less declared with const attributes, but the code in the called routines */
/* honours the restrictions (it doesn't modify anything), so it does OK. */
typedef const char *const *const CCPCCPC;
#endif /* ESQLC_SLOPPY_CONST */

#if ESQLC_VERSION == 500 || ESQLC_VERSION == 501
extern _SQCURSOR *_iqlocate_cursor(const char *name, int type, int cs, int xx);
#else
extern _SQCURSOR *_iqlocate_cursor(const char *name, int type, int cs);
#endif /* ESQLC_VERSION in {500, 501} */

extern int      _iqalloc(const char *descname, int occurrence);
extern int      _iqbeginwork(void);
extern int      _iqcdcl(_SQCURSOR *cursor,
                        const char *curname,
                        CCPCCPC cmdtxt,
                        struct sqlda *idesc,
                        struct sqlda *odesc,
                        int flags);
extern int      _iqcddcl(_SQCURSOR *cursor,
                         const char *curname,
                         _SQCURSOR *stmt,
                         int flags);
extern int      _iqcftch(_SQCURSOR *cursor,
                         struct sqlda *idesc,
                         struct sqlda *odesc,
                         const char *odesc_name,
                         _FetchSpec *fetchspec);
extern int      _iqclose(_SQCURSOR *cursor);
extern int      _iqcommit(void);
extern int      _iqcopen(_SQCURSOR *cursor,
                         int icnt,
                         struct sqlvar_struct *ibind,
                         struct sqlda *idesc,
                         struct value *ivalues,
                         int useflag);
extern int      _iqcput(_SQCURSOR *cursor,
                        struct sqlda *idesc,
                        const char *desc_name);
extern int      _iqcrproc(const char *fname);
extern int      _iqdbase(const char *db_name, int exclusive);
extern int      _iqdbclose(void);
extern int      _iqdcopen(_SQCURSOR *cursor,
                          struct sqlda *idesc,
                          const char *desc_name,
                          char *ivalues,
                          int useflag);
extern int      _iqdealloc(const char *desc_name);
extern int      _iqdescribe(_SQCURSOR *cursor,
                            struct sqlda **descp,
                            const char *desc_name);
extern int      _iqexecute(_SQCURSOR *cursor,
                           struct sqlda *idesc,
                           const char *desc_name,
                           struct value *ivalues);
extern int      _iqeximm(const char *stmt);
extern int      _iqexproc(_SQCURSOR *cursor,
                          CCPCCPC cmdtxt,
                          int icnt,
                          struct sqlvar_struct *ibind,
                          int ocnt,
                          struct sqlvar_struct *obind,
                          int chkind);
extern int      _iqflush(_SQCURSOR *cursor);
extern int      _iqfree(_SQCURSOR *cursor);
extern int      _iqgetdesc(const char *desc_name,
                           int sqlvar_num,
                           struct hostvar_struct *hosttab,
                           int xopen_flg);
extern int      _iqprepare(_SQCURSOR *cursor, const char *stmt);
extern int      _iqrollback(void);
extern int      _iqsetdesc(const char *desc_name,
                           int sqlvar_num,
                           struct hostvar_struct *hosttab,
                           int xopen_flg);
extern int      _iqslct(_SQCURSOR *cursor,
                        CCPCCPC cmdtxt,
                        int icnt,
                        struct sqlvar_struct *ibind,
                        int ocnt,
                        struct sqlvar_struct *obind,
                        int chkind);
extern int      _iqstmnt(_SQSTMT *scb,
                         CCPCCPC cmdtxt,
                         int icnt,
                         struct sqlvar_struct *ibind,
                         struct value *ivalues);
extern void     iec_stop(void);
extern int      sqgetdbs(int *ret_fcnt,
                         char **fnames,
                         int fnsize,
                         char *farea,
                         int fasize);
extern int      sqlbreak(void);
extern void     sqldetach(void);
extern void     sqlexit(void);
extern int      sqlstart(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif	/* ESQL5_00_H */

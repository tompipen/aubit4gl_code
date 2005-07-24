/*
@(#)File:            $RCSfile: decsci.h,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-06-21 05:44:01 $
@(#)Purpose:         JLSS Functions to manipulate DECIMAL values
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1996-99,2001
@(#)Product:         :PRODUCT:
*/

/*TABSTOP=4*/

#ifndef DECSCI_H
#define DECSCI_H

#ifdef MAIN_PROGRAM
#ifndef lint
static const char decsci_h[] = "@(#)$Id: decsci.h,v 1.1 2002-06-21 05:44:01 afalout Exp $";
#endif	/* lint */
#endif	/* MAIN_PROGRAM */

#include <stddef.h>
#include "decimal.h"

extern int decabs(const dec_t *x, dec_t *r1);
extern int decneg(const dec_t *x, dec_t *r1);
extern int decpower(const dec_t *x, int n, dec_t *r1);
extern int decsqrt(dec_t *x, dec_t *r1);

/* NB: these routines are not thread-safe and return a pointer to static data */
extern char *decfix(const dec_t *d, int ndigit, int plus);
extern char *decsci(const dec_t *d, int ndigit, int plus);
extern char *deceng(const dec_t *d, int ndigit, int plus, int cw);

/* NB: these routines are thread-safe */
extern char *dec_fix(const dec_t *d, int ndigit, int plus, char *buffer, size_t buflen);
extern char *dec_sci(const dec_t *d, int ndigit, int plus, char *buffer, size_t buflen);
extern char *dec_eng(const dec_t *d, int ndigit, int plus, int cw, char *buffer, size_t buflen);

/* Primarily an internal routine - format exponent */
extern char *decexp(char *buffer, int exp);

/* Incomplete code */
extern int dec_chk(dec_t *d, int sqllen);
extern int dec_set(dec_t *d, int sqllen);

extern int dec_is_zero(dec_t *d);
extern int dec_is_null(dec_t *d);

extern void dec_setzero(dec_t *d);
extern void dec_setnull(dec_t *d);
extern void dec_verify(dec_t *d);

extern int decfmt(const dec_t *d, int sqllen, int fmtcode, char *buffer, size_t buflen); 

#endif	/* DECSCI_H */

head	1.1;
access;
symbols;
locks; strict;
comment	@ * @;


1.1
date	91.11.17.16.35.14;	author jl;	state Exp;
branches;
next	;


desc
@@


1.1
log
@Initial revision
@
text
@/*
@@(#)File:            $RCSfile: monfmt.h,v $
@@(#)Version:         $Revision: 1.1 $
@@(#)Last changed:    $Date: 2002-06-14 05:03:46 $
@@(#)Purpose:         Header for fmtmoney(3)
@@(#)Author:          P J Plauger / J Leffler
*/

/*TABSTOP=4*/

/*
** Include file based on xfmtval.c in P J Plauger "The Standard C Library"
** Incorporates some features of setlocale etc.  Should be readily upgradable
** to use a full Standard C Library implementation.
*/

#ifndef MONFMT_H
#define MONFMT_H

/* -- Constant Definitions */

#define FMT_LOCAL_CURR	-1
#define FMT_INTER_CURR	-2
#define FMT_INTEGER		-3

/* -- Macro Definitions	*/

#ifdef __STDC__
#define _PROTOTYPE(x, y)	x y
#else
#define const
#define _PROTOTYPE(x, y)	x()
#endif	/* __STDC__ */

/* -- Type Definitions */

struct Money_fmt
{
	char           *currency_symbol;
	char           *int_curr_symbol;
	char           *mon_decimal_point;
	char           *mon_grouping;
	char           *mon_thousands_sep;
	char           *negative_sign;
	char           *positive_sign;
	char            frac_digits;
	char            int_frac_digits;
	char            n_cs_precedes;
	char            n_sep_by_space;
	char            n_sign_posn;
	char            p_cs_precedes;
	char            p_sep_by_space;
	char            p_sign_posn;
	char           *decimal_point;
	char           *grouping;
	char           *thousands_sep;
};

typedef struct Money_fmt Money_fmt;

/* -- Declarations */

extern Money_fmt *_PROTOTYPE(get_monfmt, (void));
extern char      *_PROTOTYPE(fmt_money, (char *, int, double, int));
extern char      *_PROTOTYPE(get_monlocale, (void));
extern int        _PROTOTYPE(set_monfmt, (char *));

#endif	/* MONFMT_H */
@

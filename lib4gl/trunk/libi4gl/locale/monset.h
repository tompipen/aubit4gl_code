head	1.1;
access;
symbols;
locks; strict;
comment	@ * @;


1.1
date	91.11.17.16.35.17;	author jl;	state Exp;
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
@@(#)File:            $RCSfile: monset.h,v $
@@(#)Version:         $Revision: 1.1 $
@@(#)Last changed:    $Date: 2002-06-14 05:03:46 $
@@(#)Purpose:         ESQL/C header for structure of table Locale.
@@(#)Author:          J Leffler
*/

/*TABSTOP=4*/

#ifndef MONSET_H
#define MONSET_H

/* -- Type Definitions */

$struct Tab_locale            
{
	char            locale_name[19];
	char            currency_symbol[5];
	char            int_curr_symbol[5];
	char            mon_decimal_point[2];
	char            mon_grouping[11];
	char            mon_thousands_sep[2];
	char            negative_sign[5];
	char            positive_sign[5];
	char            frac_digits[2];
	char            int_frac_digits[2];
	char            n_cs_precedes[2];
	char            n_sep_by_space[2];
	char            n_sign_posn[2];
	char            p_cs_precedes[2];
	char            p_sep_by_space[2];
	char            p_sign_posn[2];
	char            decimal_point[2];
	char            grouping[11];
	char            thousands_sep[2];
};

typedef struct Tab_locale Tab_locale;

#endif	/* MONSET_H */
@

head	1.1;
access;
symbols;
locks; strict;
comment	@ * @;


1.1
date	91.11.17.16.35.11;	author jl;	state Exp;
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
@@(#)File:            $RCSfile: mondmp.c,v $
@@(#)Version:         $Revision: 1.1 $
@@(#)Last changed:    $Date: 2002-06-14 05:03:46 $
@@(#)Purpose:         Print locale details (Informix LOCALE)
@@(#)Author:          J Leffler
@@(#)Copyright:       (C) JLSS 1991
*/

/*TABSTOP=4*/

#include <stdio.h>
#include "monfmt.h"

#ifndef lint
static char     sccs[] = "@@(#)$Id: mondmp.c,v 1.1 2002-06-14 05:03:46 afalout Exp $";
#endif

static void     dmp_grouping(fp, s, g)
FILE           *fp;
char           *s;
char           *g;
{
	char           *t;
	char           *pad;

	pad = "";
	fprintf(fp, "%-18s = ", s);
	for (t = g; *t != '\0'; t++)
	{
		fprintf(fp, "%s%d", pad, *t);
		pad = ":";
	}
	fprintf(fp, "\n");
}

void            dmp_money_fmt(fp, m)
FILE           *fp;
Money_fmt      *m;
{
	fprintf(fp, "%-18s = %s\n", "currency_symbol", m->currency_symbol);
	fprintf(fp, "%-18s = %s\n", "int_curr_symbol", m->int_curr_symbol);
	fprintf(fp, "%-18s = %s\n", "mon_decimal_point", m->mon_decimal_point);
	dmp_grouping(fp, "mon_grouping", m->mon_grouping);
	fprintf(fp, "%-18s = %s\n", "mon_thousands_sep", m->mon_thousands_sep);
	fprintf(fp, "%-18s = %s\n", "negative_sign", m->negative_sign);
	fprintf(fp, "%-18s = %s\n", "positive_sign", m->positive_sign);
	fprintf(fp, "%-18s = %d\n", "frac_digits", m->frac_digits);
	fprintf(fp, "%-18s = %d\n", "int_frac_digits", m->int_frac_digits);
	fprintf(fp, "%-18s = %d\n", "n_cs_precedes", m->n_cs_precedes);
	fprintf(fp, "%-18s = %d\n", "n_sep_by_space", m->n_sep_by_space);
	fprintf(fp, "%-18s = %d\n", "n_sign_posn", m->n_sign_posn);
	fprintf(fp, "%-18s = %d\n", "p_cs_precedes", m->p_cs_precedes);
	fprintf(fp, "%-18s = %d\n", "p_sep_by_space", m->p_sep_by_space);
	fprintf(fp, "%-18s = %d\n", "p_sign_posn", m->p_sign_posn);
	fprintf(fp, "%-18s = %s\n", "decimal_point", m->decimal_point);
	dmp_grouping(fp, "grouping", m->grouping);
	fprintf(fp, "%-18s = %s\n", "thousands_sep", m->thousands_sep);
}
@

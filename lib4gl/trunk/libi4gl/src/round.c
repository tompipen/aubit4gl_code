head	1.1;
access;
symbols;
locks; strict;
comment	@ * @;


1.1
date	89.06.06.13.35.23;	author john;	state Exp;
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
@@(#)File:            $RCSfile: round.c,v $
@@(#)Version:         $Revision: 1.1 $
@@(#)Last changed:    $Date: 2002-06-14 05:03:47 $
@@(#)Purpose:         I4GL: Round Informix Decimal Numbers
@@(#)Author:          J Leffler
*/

/* -- Include Files */

#define DEBUG
#include <stdio.h>
#include <assert.h>
#include <decimal.h>

#ifndef lint
static	char	sccs[] = "@@(#)$Id: round.c,v 1.1 2002-06-14 05:03:47 afalout Exp $";
#endif
/* -- Routine: round		*/

int	round(i)
int	i;
{
	dec_t	d;
	int		n;

	assert(i == 2);
	popint(&n);
	popdec(&d);
	decround(&d, n);	/* Undocumented function call */
	retdec(&d);
	return(1);
}
@

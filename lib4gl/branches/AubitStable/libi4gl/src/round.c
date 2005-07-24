/*
@(#)File:            $RCSfile: round.c,v $
@(#)Version:         $Revision: 1.2 $
@(#)Last changed:    $Date: 2002-06-14 09:23:17 $
@(#)Purpose:         I4GL: Round Informix Decimal Numbers
@(#)Author:          J Leffler
*/

/* -- Include Files */

#define DEBUG
#include <stdio.h>
#include <assert.h>
#include <decimal.h>

#ifndef lint
static	char	sccs[] = "@(#)$Id: round.c,v 1.2 2002-06-14 09:23:17 afalout Exp $";
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

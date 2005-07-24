/*
@(#)File:            $RCSfile: decexp.c,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-06-21 05:44:01 $
@(#)Purpose:         Format exponent for DECIMAL
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1991-93,1996-97,1999,2001-02
@(#)Product:         :PRODUCT:
*/

#include "esqlc.h"
#include "decsci.h"

#ifndef lint
static const char rcs[] = "@(#)$Id: decexp.c,v 1.1 2002-06-21 05:44:01 afalout Exp $";
#endif

/* Assume dst points to at least 6 characters. */
/* Return pointer to terminal NUL '\0' */

/* Format an exponent */
char    *decexp(register char  *dst, register int exp)
{
	*dst++ = 'E';
	if (exp >= 0)
		*dst++ = '+';
	else
	{
		*dst++ = '-';
		exp = -exp;
	}
	if (exp / 100 != 0)
		*dst++ = exp / 100 + '0';
	*dst++ = (exp / 10) % 10 + '0';
	*dst++ = (exp % 10) + '0';
	if (exp / 100 == 0)
		*dst++ = ' ';
	*dst = '\0';
	return(dst);
}

#ifdef TEST

#include <stdio.h>

#define DIM(x)	(sizeof(x)/sizeof(*(x)))

static int values[] =
{
 0, -1, -9, -10, -99, -100, -124, 1, 9, 10, 99, 100
};

int main(void)
{
	char            buffer[8];
	int             i;
	char *end;

	for (i = 0; i < DIM(values); i++)
	{
		end = decexp(buffer, values[i]);
		printf("%4d = <<%s>>\n", values[i], buffer);
	}

	return(0);
}

#endif	/* TEST */

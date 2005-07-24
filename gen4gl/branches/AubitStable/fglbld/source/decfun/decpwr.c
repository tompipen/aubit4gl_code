/*
@(#)File:            $RCSfile: decpwr.c,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-06-21 05:44:01 $
@(#)Purpose:         Raise DECIMAL to integer power
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1992,1997
@(#)Product:         :PRODUCT:
*/

/*TABSTOP=4*/
/*LINTLIBRARY*/

#include "decsci.h"

#ifndef lint
static const char rcs[] = "@(#)$Id: decpwr.c,v 1.1 2002-06-21 05:44:01 afalout Exp $";
#endif

int decpower(const dec_t *x, int n, dec_t *r1)
{
	dec_t           p;
	dec_t           r;
	dec_t           one;
	int             recip = 0;
	int             s;

	if (n < 0)
	{
		n = -n;
		recip = 1;
	}

	p = *x;
	if ((s = deccvasc("1.0", 3, &one)) != 0)
		return(s);
	r = one;
	while (n > 0)
	{
		if (n % 2 == 1)
			if ((s = decmul(&r, &p, &r)) != 0)
				return(s);
		if ((s = decmul(&p, &p, &p)) != 0)
			return(s);
		n /= 2;
	}

	if (recip)
		if ((s = decdiv(&one, &r, &r)) != 0)
			return(s);
	*r1 = r;
	return(0);
}

#ifdef TEST

#include <stdio.h>

int main(void)
{
	int             i;
	dec_t           two;
	dec_t           res;
	char            buffer[26];
	char            buftwo[4];

	deccvdbl(2.0, &two);
	dectoasc(&two, buftwo, sizeof(buftwo) - 1, -1);
	buftwo[sizeof(buftwo) - 1] = '\0';
	for (i = 10; i >= -10; i--)
	{
		decpower(&two, i, &res);
		dectoasc(&res, buffer, sizeof(buffer) - 1, -1);
		buffer[sizeof(buffer) - 1] = '\0';
		printf("%s ** %d = %s\n", buftwo, i, buffer);
	}
	return(0);
}

#endif	/* TEST */

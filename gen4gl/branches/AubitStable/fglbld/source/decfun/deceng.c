/*
@(#)File:            $RCSfile: deceng.c,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-06-21 05:44:01 $
@(#)Purpose:         Engineering formatting of DECIMALs
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1991-93,1996-97,1999,2001
@(#)Product:         :PRODUCT:
*/

#include "esqlc.h"
#include "decsci.h"

#ifndef __STDC__
/*
** JL - 1999-12-06
** For some versions of ESQL/C (eg 7.23), the dececvt() functions are
** not declared unless __STDC__ is defined.  Patch this up by declaring
** them, prototype and all, if __STDC__ is not defined.
*/
extern char *dececvt(dec_t *np, int ndigit, int *decpt, int *sign);
#endif /* __STDC__ */

/*
** JL - 1999-12-06 - Future Directions.
** There should be cover functions for these routines that use the
** declared type of the decimal/money value, and only the cover
** functions should call these functions.  The engineering notation code
** should be in a separate file.  These routines are neither thread-safe
** nor re-entrant because of the static buffer used.  This too can be
** fixed by renaming the routines, with cover functions providing the
** original functionality as a migration tool - the current interfaces
** are obsolescent.
*/

#define SIGN(s, p)  ((s) ? '-' : ((p) ? '+' : ' '))
#define VALID(n)	(((n) <= 0) ? 6 : (((n) > 32) ? 32 : (n)))

#define CONST_CAST(t, v)	((t)(v))

#ifndef lint
static const char rcs[] = "@(#)$Id: deceng.c,v 1.1 2002-06-21 05:44:01 afalout Exp $";
#endif

char           *deceng(const dec_t *d, int ndigit, int plus, int cw)
{
	/* For 32 digits, 3-digit exponent, leading blanks, etc, 42 is enough */
	static char     buffer[42];
	return(dec_eng(d, ndigit, plus, cw, buffer, sizeof(buffer)));
}

/*
**	Format an engineering notation number.
**	Exponent is always a power of three.  Exponent is omitted if it is zero.
**	For values 1.0E-1 <= ABS(x) < 1.0E0, the value is printed as 0.xxxx.
**	The field always aligns the decimal points, prefixing blanks if necessary.
**	The number of digits printed ND is such that if the power of ten is of
**	the form (n * 3 + m) (m = 0, 1, 2), ND = ndigit - 2 + m.  The exception
**	to this is when the value is treated as 0.xxxx and ND = ndigit - 2
**	including the leading zero!
**	The field can be made constant width by specifying a non-zero cw.
*/
char           *dec_eng(const dec_t *d, int ndigit, int plus, int cw, char *buffer, size_t buflen)
{
	register char  *dst = buffer;
	register char  *src;
	int             sn;
	int             dp;
	int             lb;
	int             exp;

	if (risnull(CDECIMALTYPE, (char *)d))
	{
		*dst = '\0';
		return(buffer);
	}

	ndigit = VALID(ndigit);
	src = dececvt(CONST_CAST(dec_t *, d), ndigit, &dp, &sn);
	exp = dp - 1;
	/* Calculate leading blanks */
	lb = 2 - (exp % 3);
	if (lb >= 3)
		lb -= 3;
	if (exp == -1)
	{
		lb = 2;
		ndigit--;
	}
	/* Shorten digit string as necessary */
	src[ndigit - lb] = '\0';

	while (lb-- > 0)			/* Leading blanks */
		*dst++ = ' ';

	*dst++ = SIGN(sn, plus);	/* Sign */
	if (exp == -1)
	{							/* Leading 0 */
		*dst++ = '0';
		exp = 0;
	}
	else
	{							/* Leading digits */
		while (exp % 3 != 0)
		{
			*dst++ = ((*src) ? *src++ : '0');
			exp--;
		}
		*dst++ = *src++;
	}
	*dst++ = '.';				/* Decimal point */
	while (*src)				/* Digits after decimal point */
		*dst++ = *src++;
	if (exp != 0)				/* Exponent */
		dst = decexp(dst, exp);
	else if (cw)
	{
		for (lb = 0; lb < 5; lb++)
			*dst++ = ' ';
	}
	*dst = '\0';
	return(buffer);
}

#ifdef TEST

#include <stdio.h>

#define DIM(x)	(sizeof(x)/sizeof(*(x)))

static char    *values[] =
{
 "0",
 "+3.14159265358979323844e+00",
 "-3.14159265358979323844e+01",
 " 3.14159265358979323844e+02",
 "+3.14159265358979323844e+03",
 "-3.14159265358979323844e+34",
 " 3.14159265358979323844e+68",
 "+3.14159265358979323844e+99",
 "-3.14159265358979323844e+100",
 " 9.99999999999999999999e+125",
 "+1.00000000000000000000e+126",
 "-3.14159265358979323844e+00",
 " 3.14159265358979323844e-01",
 "+3.14159265358979323844e-02",
 "-3.14159265358979323844e-03",
 " 3.14159265358979323844e-34",
 "+3.14159265358979323844e-68",
 "-3.14159265358979323844e-99",
 " 3.14159265358979323844e-100",
 "+3.14159265358979323844e-126",
 "-3.14159265358979323844e-127",
 " 1.00000000000000000000e-128",
 "+1.00000000000000000000e-129",
 "-1.00000000000000000000e-130",
 " 9.99999999999999999999e-131",
};

int main(void)
{
	char           *s;
	dec_t           d;
	int             i;
	int             err;

	printf("\nEngineering notation (variable)\n");
	printf("%-30s %s\n", "Input value", "Formatted");
	for (i = 0; i < DIM(values); i++)
	{
		if ((err = deccvasc(values[i], strlen(values[i]), &d)) != 0)
			printf("deccvasc error %d on %s\n", err, values[i]);
		else
		{
			/*s = deceng(&d, 16 + (i / 3), i % 2, 0);*/
			s = deceng(&d, 16, i % 2, 0);
			printf("%-30s :%s:\n", values[i], s);
		}
	}

	printf("\nEngineering notation (constant)\n");
	printf("%-30s %s\n", "Input value", "Formatted");
	for (i = 0; i < DIM(values); i++)
	{
		if ((err = deccvasc(values[i], strlen(values[i]), &d)) != 0)
			printf("deccvasc error %d on %s\n", err, values[i]);
		else
		{
			s = deceng(&d, 32 - 3 * (i / 3), i % 2, 1);
			printf("%-30s :%s:\n", values[i], s);
		}
	}

	return(0);
}

#endif	/* TEST */

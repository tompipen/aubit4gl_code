/*
@(#)File:            $RCSfile: decsci.c,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-06-21 05:44:01 $
@(#)Purpose:         Exponential formatting of DECIMALs
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
static const char rcs[] = "@(#)$Id: decsci.c,v 1.1 2002-06-21 05:44:01 afalout Exp $";
#endif

char           *decsci(const dec_t *d, int ndigit, int plus)
{
	/* For 32 digits, 3-digit exponent, leading blanks, etc, 42 is enough */
	static char     buffer[42];
	return(dec_sci(d, ndigit, plus, buffer, sizeof(buffer)));
}

/*	Format a scientific notation number */
char           *dec_sci(const dec_t *d, int ndigit, int plus, char *buffer, size_t buflen)
{
	register char  *dst = buffer;
	register char  *src;
	int             sn;
	int             dp;
	dec_t           z;

	if (risnull(CDECIMALTYPE, (char *)d))
	{
		*dst = '\0';
		return(buffer);
	}

	ndigit = VALID(ndigit);
	src = dececvt(CONST_CAST(dec_t *, d), ndigit, &dp, &sn);
	*dst++ = SIGN(sn, plus);	/* Sign */
	*dst++ = *src++;			/* Digit before decimal point */
	*dst++ = '.';				/* Decimal point */
	while (*src)				/* Digits after decimal point */
		*dst++ = *src++;
	deccvdbl(0.0, &z);
	dst = decexp(dst, dp - (deccmp(CONST_CAST(dec_t *, d), &z) != 0));	/* Exponent */
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

	printf("\nScientific notation\n");
	printf("%-30s %s\n", "Input value", "Formatted");
	for (i = 0; i < DIM(values); i++)
	{
		if ((err = deccvasc(values[i], strlen(values[i]), &d)) != 0)
			printf("deccvasc error %d on %s\n", err, values[i]);
		else
		{
			s = decsci(&d, 6, i % 2);
			printf("%-30s :%s:\n", values[i], s);
		}
	}

	return(0);
}

#endif	/* TEST */

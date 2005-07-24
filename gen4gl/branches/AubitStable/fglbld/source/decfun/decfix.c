/*
@(#)File:            $RCSfile: decfix.c,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-06-21 05:44:01 $
@(#)Purpose:         Fixed formatting of DECIMALs
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1991-93,1996-97,1999,2001
@(#)Product:         :PRODUCT:
*/

#include "esqlc.h"
#include "decsci.h"

#ifndef __STDC__
/*
** JL - 1999-12-06
** For some versions of ESQL/C (eg 7.23), the decfcvt() functions are
** not declared unless __STDC__ is defined.  Patch this up by declaring
** them, prototype and all, if __STDC__ is not defined.
*/
extern char *decfcvt(dec_t *np, int ndigit, int *decpt, int *sign);
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
#define VALID(n)	(((n) <= 0) ? 0 : (((n) > 151) ? 151 : (n)))

#define CONST_CAST(t, v)	((t)(v))

#ifndef lint
static const char rcs[] = "@(#)$Id: decfix.c,v 1.1 2002-06-21 05:44:01 afalout Exp $";
#endif

char           *decfix(const dec_t *d, int ndigit, int plus)
{
	/* For 32 digits, 3-digit exponent, leading blanks, etc, 42 is enough */
	/* With fixed format, could have -0.(130*0)(32 digits) + null for length 166 */
	static char     buffer[166];
	return(dec_fix(d, ndigit, plus, buffer, sizeof(buffer)));
}

/*
**	Format a fixed-point number.  Unreliable for ndigit > 58 because of the
**	implementation of decfcvt in ${SOURCE}/infx/decconv.c
*/
char           *dec_fix(const dec_t *d, int ndigit, int plus, char *buffer, size_t buflen)
{
	register char  *dst = buffer;
	register char  *src;
	int             i;
	int             sn;
	int             dp;

	if (risnull(CDECIMALTYPE, (char *)d))
	{
		*dst = '\0';
		return(buffer);
	}

	ndigit = VALID(ndigit);

	src = decfcvt(CONST_CAST(dec_t *, d), ndigit, &dp, &sn);

	*dst++ = SIGN(sn, plus);	/* Sign */
	if (dp >= 1)
	{
		while (dp-- > 0)
			*dst++ = ((*src) ? *src++ : '0');
		if (ndigit > 0)
			*dst++ = '.';
		for (i = 0; i < ndigit; i++)
			*dst++ = ((*src) ? *src++ : '0');
	}
	else
	{
		*dst++ = '0';
		if (ndigit > 0)
			*dst++ = '.';
		i = 0;
		while (dp++ < 0 && i < ndigit)
		{
			*dst++ = '0';
			i++;
		}
		while (*src && i < ndigit)
		{
			*dst++ = *src++;
			i++;
		}
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

	printf("\nFixed-point notation\n");
	printf("%-30s %s\n", "Input value", "Formatted");
	for (i = 0; i < DIM(values); i++)
	{
		if ((err = deccvasc(values[i], strlen(values[i]), &d)) != 0)
			printf("deccvasc error %d on %s\n", err, values[i]);
		else
		{
			s = decfix(&d, 6 + 3 * i, i % 2);
			printf("%-30s :%s:\n", values[i], s);
		}
	}

	return(0);
}

#endif	/* TEST */

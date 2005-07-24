/*
@(#)File:            $RCSfile: decfmt.c,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-06-21 05:44:01 $
@(#)Purpose:         Format a decimal value according to sqllen type code
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1999,2002
@(#)Product:         :PRODUCT:
*/

#include <string.h>
#include <assert.h>
#include "esqlc.h"
#include "decsci.h"

#ifndef lint
static const char rcs[] = "@(#)$Id: decfmt.c,v 1.1 2002-06-21 05:44:01 afalout Exp $";
#endif

/*
** decfmt - format decimal value according to sqllen type code
**
** Formats decimal value with precision and scale specified by sqllen
** type code into buffer of size buflen, with format encoded by fmtcode.
** For the time being, always use fmtcode == 0, which is enforced by
** assertion.  The fmtcode will eventually indicate strip trailing
** zeroes, always use sign, use 2-digit or 3-digit exponents, etc.
*/
int	decfmt(const dec_t *d, int sqllen, int fmtcode, char *buffer, size_t buflen)
{
	int nd = PRECTOT(sqllen);
	int dp = PRECDEC(sqllen);
	int rc = 0;
	char *val;

	assert(fmtcode == 0);
	if (dp == 0xFF || dp < 0)
	{
		/* Floating point DECIMAL */
		val = decsci(d, nd, 0);
	}
	else
	{
		/* Fixed point DECIMAL or MONEY */
		val = decfix(d, dp, 0);
	}

	if (strlen(val) < buflen)
		strcpy(buffer, val);
	else
	{
		/* -1235: Character host variable is too short for the data. */
		rc = -1235;
		*buffer = '\0';
	}
	return(rc);
}

#ifdef TEST

#include <stdio.h>

#define DIM(x)	(sizeof(x)/sizeof(*(x)))

/*
** Do not try to determine the limits of decimals -- it varies from
** release to release, dammitall.  See declim.c for a limit tester.
*/
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
 "-3.14159265358979323844e+00",
 " 3.14159265358979323844e-01",
 "+3.14159265358979323844e-02",
 "-3.14159265358979323844e-03",
 " 3.14159265358979323844e-34",
 "+3.14159265358979323844e-68",
 "-3.14159265358979323844e-99",
 " 3.14159265358979323844e-100",
};

int main(void)
{
	char            buffer[200];
	dec_t           d;
	int             i;
	int             err;
	int sqllen;
	int prec;
	int scale;

	printf("\nFixed-point notation\n");
	printf("%-30s %s\n", "Input value", "Formatted");
	for (i = 0; i < DIM(values); i++)
	{
		if ((err = deccvasc(values[i], strlen(values[i]), &d)) != 0)
			printf("deccvasc error %d on %s\n", err, values[i]);
		else
		{
			for (prec = 4; prec <= 32; prec += 3)
			{
				for (scale = 0; scale <= prec; scale += prec / 3)
				{
					sqllen = PRECMAKE(prec, scale);
					err = decfmt(&d, sqllen, 0, buffer, sizeof(buffer));
					if (err == 0)
						printf("%-30s :p=%2d:s=%2d:%s:\n", values[i], prec, scale, buffer);
					else
						printf("%-30s : error = %d\n", values[i], err);
				}
			}
		}
	}

	return(0);
}

#endif	/* TEST */

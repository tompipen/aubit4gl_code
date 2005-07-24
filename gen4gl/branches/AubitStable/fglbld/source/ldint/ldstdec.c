/*
@(#)File:            $RCSfile: ldstdec.c,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-06-21 05:44:01 $
@(#)Purpose:         Implement ld_decimal(), st_decimal() - Compatible with C-ISAM lddecimal(), stdecimal()
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 2000
@(#)Product:         :PRODUCT:
*/

/*TABSTOP=4*/

#include <stdio.h>	/* DEBUG ONLY */
#include <assert.h>
#include <string.h>
#include "decimal.h"
#include "stldint.h"

#ifndef lint
static const char rcs[] = "@(#)$Id: ldstdec.c,v 1.1 2002-06-21 05:44:01 afalout Exp $";
#endif

/*
** From decimal.h header
**
** Unpacked Format (in-memory format):
**    Signed exponent "dec_exp" ranging from  -64 to +63.
**    Separate sign of mantissa "dec_pos".
**    Base 100 digits (range 0 - 99) with decimal point
**    immediately to the left of first digit.
**
** Additional info (in-memory format):
**    NULL: dec_pos = DECPOSNULL
**    Zero: dec_pos = 1, dec_ndgts = 0, dec_exp = -64
**    NB: Unless value is zero, dec_dgts[0] != 0.
**
** Packed Format (on-disk format)
**    First byte:
**      top 1 bit  = sign (0 = neg, 1 = pos)
**      low 7 bits = exponent in excess 64 format
**    Rest of bytes = base 100 digits in 100 complement format
**    Notes:
**    --    This format sorts numerically with just a simple byte by
**          byte unsigned comparison.
**    --    Zero is represented as 80,00,00,... (hex).
**    --    Negative numbers have the exponent complemented and the
**          base 100 digits in 100's complement.
**
** Additional info (disk format):
**    NULL: first byte 0; second byte 0.
*/

/* Two external routines in this file share common, non-trivial routine */

/*
** dec_100comp -- Calculate the 100's-complement of a digit string.
**
** Officially, the 100's complement is formed by subtracting each digit
** in the sequence from 99, and then adding 1 to the last digit,
** carrying any overflow back up the digit chain.  For a string of
** zeroes, this converts each zero into 99, and then the addition
** reverts them all back to zero.
**
** The 100's-complement is formed by subtracting each of the leading
** digits from 99, but the last non-zero digit is subtracted from 100.
*/

static void dec_100comp(char *cp, int len)
{
	char *ep = cp + len - 1;

	assert(len > 0 && len <= DECSIZE);
	while (ep > cp && *ep == 0)
		ep--;

	if (*ep != 0)
		*ep = 100 - *ep;

	if (ep == cp)
		return;
	
	while (ep > cp)
	{
		ep--;
		assert(*ep >= 0 && *ep < 100);
		*ep = 99 - *ep;
	}
}

/* ld_decimal - convert decimal value in disk format to memory format */
/* Assume disk format is valid! */
int ld_decimal(const char *cp, int len, dec_t *np)
{
	int exp;
	char *dp;

	/* Exponent (1 byte) and at least 1 digit; no more than DECSIZE digits */
	assert(len > 1 && len <= DECSIZE + 1);

	if (cp[0] == 0 && cp[1] == 0)
	{
		/* NULL */
		np->dec_ndgts = 0;
		np->dec_exp = 0;
		np->dec_pos = DECPOSNULL;
		return(0);
	}

	memcpy(np->dec_dgts, cp + 1, --len);

	/* Drop trailing zeroes */
	for (dp = &np->dec_dgts[len - 1]; dp >= np->dec_dgts; dp--)
	{
		if (*dp != '\0')
			break;
		len--;
	}
	np->dec_ndgts = len;

	exp = *cp & 0xFF;
	if ((exp & 0x80) == 0)
	{
		/* Negative - complement both mantissa and exponent */
		dec_100comp(np->dec_dgts, len);
		exp ^= 0x7F;
		np->dec_pos = 0;
	}
	else
		np->dec_pos = 1;

	np->dec_exp = (exp & 0x7F) - 64;

	return 0;
}

/* st_decimal - convert decimal value in memory format to disk format */
void st_decimal(const dec_t *np, char *cp, int len)
{
	char *bp;

	assert(len > 1 && len <= DECSIZE + 1);
	if (np->dec_pos == DECPOSNULL)
	{
		/* NULL */
		memset(cp, '\0', len);
	}
	else if (np->dec_ndgts == 0)
	{
		/* Zero */
		*cp = 0x80;
		memset(cp+1, '\0', len - 1);
	}
	else
	{
		/* Stash exponent (0..127) */
		assert(np->dec_exp >= -64 && np->dec_exp <= 63);
		*cp++ = np->dec_exp + 64;
		len--;

		if (len >= np->dec_ndgts)
		{
			/* Copy digits */
			memcpy(cp, np->dec_dgts, np->dec_ndgts);
			if (len > np->dec_ndgts)
			{
				/* Zero pad space */
				memset(cp + np->dec_ndgts, '\0', len - np->dec_ndgts);
			}
		}
		else if (len < np->dec_ndgts)
		{
			/* Copy digits */
			memcpy(cp, np->dec_dgts, len);
			if (np->dec_dgts[len] >= 50)
			{
				/* round up result */
				bp = cp + len;
				while (++(*--bp) >= 100)    /* propagate carry up */
				{
					if (bp == cp)
					{
						/* All digits must have been 99; all now zero */
						/* Required result is 1 in first digit and increased exponent */
						*bp = 1;
						++cp[-1];       /* up the exponent */
						break;
					}
					else
						*bp = 0;
				}
			}
		}

		if (np->dec_pos != 0)
		{
			/* Positive */
			cp[-1] |= 0x80;
		}
		else
		{
			/* Negative: complement mantissa and exponent */
			dec_100comp(cp, len);
			cp[-1] ^= 0x7F;
		}
	}
}

#ifdef TEST

#include <stdio.h>
#include "esqlutil.h"

#define DIM(x)	(sizeof(x)/sizeof(*(x)))

static double values[] =
{
	1.0,
	9.9,
	99.99,
	999.999,
	9.99999E-13,
	9.99999E+13,
	9.99999999E-31,
	9.99999999E+31,
	1.2345678901234E-9,
	1.2345678901234E+9,
};

static void analyze(double d)
{
	size_t j;
	size_t k;
	dec_t d0;
	dec_t d1;
	dec_t d2;
	char buff1[DECSIZE+1];
	char buff2[DECSIZE+1];
	int dflag;

	printf("Value: %23.15g\n", d);
	deccvdbl(d, &d0);
	dump_decimal(stdout, "Value", &d0);
	for (j = 2; j <= 17; j++)
	{
		st_decimal(&d0, buff1, j);	/* Local */
		stdecimal(&d0, buff2, j);	/* Informix */
		if (memcmp(buff1, buff2, j) == 0)
		{
			printf("OK: st_decimal() == stdecimal(): len=%2d - ", j);
			for (k = 0; k < j; k++)
				printf("0x%02X ", buff1[k] & 0xFF);
			putchar('\n');
		}
		else
		{
			for (k = 0; k < j; k++)
			{
				if (buff1[k] != buff2[k])
					printf("*** st_decimal() ERROR %u: JL 0x%02X, IX 0x%02X\n", k, buff1[k] & 0xFF, buff2[k] & 0xFF);
			}
		}
		ld_decimal(buff2, j, &d1);	/* Local */
		lddecimal(buff2, j, &d2);	/* Informix */
		dflag = 0;
		if (d1.dec_exp != d2.dec_exp)
			dflag = 1,
			printf("*** ld_decimal() ERROR - dec_exp: JL %d, IX %d\n", d1.dec_exp, d2.dec_exp);
		if (d1.dec_pos != d2.dec_pos)
			dflag = 1,
			printf("*** ld_decimal() ERROR - dec_pos: JL %d, IX %d\n", d1.dec_pos, d2.dec_pos);
		if (d1.dec_ndgts != d2.dec_ndgts)
			dflag = 1,
			printf("*** ld_decimal() ERROR - dec_ndgts: JL %d, IX %d\n", d1.dec_ndgts, d2.dec_ndgts);
		for (k = 0; k < d1.dec_ndgts; k++)
		{
			if (d1.dec_dgts[k] != d2.dec_dgts[k])
				dflag = 1,
				printf("*** ld_decimal() ERROR - %u: JL 0x%02X, IX 0x%02X\n", k, d1.dec_dgts[k] & 0xFF, d1.dec_dgts[k] & 0xFF);
		}
		if (dflag == 0)
			printf("OK: ld_decimal() == lddecimal()\n");
	}
}

int main(void)
{
	size_t i;
	double d;

	analyze(0.0);
	for (i = 0; i < DIM(values); i++)
	{
		analyze(+values[i]);
		analyze(-values[i]);
	}
	rsetnull(CDOUBLETYPE, (char *)&d);
	analyze(d);
	return(0);
}

#endif /* TEST */


/*
@(#)File:            $RCSfile: decsqrt.c,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-06-21 05:44:01 $
@(#)Purpose:         Square root of DECIMAL value
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1992,1995,1997-99
@(#)Product:         :PRODUCT:
*/

/*TABSTOP=4*/
/*LINTLIBRARY*/

#include <stdio.h>

#include "decsci.h"
#include <math.h>
#include <errno.h>
#include <assert.h>

#ifdef TEST
#define PRINTLEN    32
#define MAXTESTS	4
#define MAXITER		2
#define	ITERATIONS	iter
static int		iter;
#else
#define ITERATIONS	1		/* Empirically, one is sufficient! */
#endif	/* TEST */

#ifndef lint
static const char rcs[] = "@(#)$Id: decsqrt.c,v 1.1 2002-06-21 05:44:01 afalout Exp $";
#endif

/* Return square root of x in r1 */
int decsqrt(dec_t *x, dec_t *r1)
{
	int		s;
	dec_t	r;
	dec_t	t;
	dec_t	zero;
	dec_t	two;
	double	d;
	int     i;
	int     c;
	int     b;
	int     e;

	/* Check for zero and negative numbers */
	s = deccvdbl(0.0, &zero);
	assert(s == 0);
	if ((s = deccmp(x, &zero)) <= 0)
	{
		*r1 = zero;
		return((s == 0) ? 0 : -EDOM);
	}


	/**
	** Deduce initial guess of sqrt(a * 100 ** N).
	** Given N = (2b + c) where c = 0 or 1, the initial estimate of sqrt(r)
	** is sqrt(a * 100 ** c) * 100 ** b.  Be wary of negative values of N;
	** if N = -1, b = -1 and c = 1.  To further complicate the issue, the
	** internal representation of decimals has dec_exp set one larger than
	** you'd expect.  For example:
	** Decimal     dec_exp   sign    ndigits      digits
	**    0.0001      -1       1        1          01
	**    0.001       -1       1        1          10
	**    0.01         0       1        1          01
	**    0.1          0       1        1          10
	**    1.0          1       1        1          01
	**   10.0          1       1        1          10
	**  100.0          2       1        1          01
	** 1000.0          2       1        1          10
	*/

	r = *x;
	e = r.dec_exp - 1;
	if (e < 0)
	{
		e = -e;
		c = e % 2;
		b = -(e+1)/2;
	}
	else
	{
		c = e % 2;
		b = e / 2;
	}
	assert(c == 0 || c == 1);
	assert((r.dec_exp <= 0 && b < 0) || (r.dec_exp > 0 && b >= 0));
	r.dec_exp = c + 1;

	s = dectodbl(&r, &d);
	assert(s == 0);
	assert(d >= 1.0 && d < 10000.0);
	d = sqrt(d);
	assert(d >= 1.0 && d < 100.0);
	s = deccvdbl(d, &r);
	assert(s == 0);
	r.dec_exp += b;

	s = deccvdbl(2.0, &two);
	assert(s == 0);

	for (i = 0; i < ITERATIONS; i++)
	{
		if ((s = decdiv(x, &r, &t)) != 0)
			return(s);
		if ((s = decadd(&r, &t, &t)) != 0)
			return(s);
		if ((s = decdiv(&t, &two, &r)) != 0)
			return(s);
	}
	*r1 = r;
	return(0);
}

#ifdef TEST

#include <stdio.h>
#include <string.h>
#include "stderr.h"
/* #include "esqlutil.h" */ /* if using dump_decimal() */

#define DIM(x)	(sizeof(x)/sizeof(*(x)))

static const char	*decimals[] =
{
	"-1.0",
	"0.0",
	"1.0",
	"2.0",
	"10.0",
	"20.0",
	"200.0",
	"2000.0",
	"20000.0",
	"200000.0",
	"2e30",
	"2e31",
	"2e32",
	"2e33",
	"2e120",
	"0.1",
	"2e-02",
	"2e-03",
	"2e-04",
	"2e-05",
	"2e-06",
	"2e-07",
	"2e-08",
	"2e-09",
	"2e-10",
	"2e-15",
	"2e-20",
	"2e-25",
	"2e-30",
	"2e-31",
	"2e-32",
	"2e-33",
	"2e-120",
};

/*
** do_compare() - Compare strings s1 and s2 which contain numbers.
** Complain about any mistmatch - but report whether problem is in
** mantissa or exponent (both have been a problem at various times).
*/
static int do_compare(const char *s1, const char *s2)
{
	const char *e = strchr(s1, 'E');

	assert(e != 0);
	if (strncmp(s1, s2, e - s1 - 3) != 0)
	{
		size_t t = e - s1 - 3;
		err_remark("mantissa mismatch (%.*s vs %.*s)\n", t, s1, t, s2);
		return(-1);
	}
	else if (strcmp(e, s2 + (e - s1)) != 0)
	{
		err_remark("exponent mismatch (%s vs %s)\n", e, s2 + (e - s1));
		return(-1);
	}
	else
		return(0);
}

int main(int argc, char **argv)
{
	int		i;
	int		j;
	int     k;
	int		n;
	dec_t	num;
	dec_t	res;
	dec_t   sqr;
	char    buffer[40];
	char    bufnum[40];
	char    bufsqr[40];
	int     estat = 0;

	setarg0(argv[0]);

	for (j = 0; j < DIM(decimals); j++)
	{
		if ((i = deccvasc(decimals[j], strlen(decimals[j]), &num)) != 0)
		{
			estat = 1;
			err_remark("error %d from deccvasc processing %s\n", i, decimals[j]);
			continue;
		}

		for (i = 1; i < MAXTESTS; i++)
		{
			for (n = 1; n <= MAXITER; n++)
			{
				iter = n;
				/* dump_decimal(stdout, "Number", &num); */
				k = decsqrt(&num, &res);
				decmul(&res, &res, &sqr);

				strcpy(bufnum, decsci(&num, PRINTLEN, 0));
				strcpy(buffer, decsci(&res, PRINTLEN, 0));
				strcpy(bufsqr, decsci(&sqr, PRINTLEN, 0));

				printf("ITER %2d: RC = %5d: SQRT(%s) = %s\n", n, k, bufnum, buffer);
				if (k != 0)
					break;
				if (do_compare(bufnum, bufsqr) != 0)
				{
					estat = 1;
					err_remark("square out of tolerance: %s\n", bufsqr);
				}
			}
			num = res;
		}
	}
	return(estat);
}

#endif	/* TEST */

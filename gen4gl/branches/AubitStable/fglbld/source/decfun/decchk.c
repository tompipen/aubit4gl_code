/*
> Note that decchk.c is not fully functional - it fails some of its own
> tests.  All the changes checked in today were actually coded in 2001,
> but not checked in.  Your call whether you decide to use what you've
> already got or go with these instead.
*/



/*
@(#)File:            $RCSfile: decchk.c,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-06-21 05:44:01 $
@(#)Purpose:         Check whether a decimal value will fit in a column
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1999,2001-02
@(#)Product:         :PRODUCT:
*/

#include "esqlc.h"
#include "decsci.h"
#include "debug.h"

#undef NDEBUG
#ifndef JLSS_ENABLE_DEBUG
#define NDEBUG 1
#endif

#include <assert.h>

#ifdef NDEBUG
#define DEC_VERIFY(x)	((void)0)
#else
#define DEC_VERIFY(x)	dec_verify(x)
#endif

#ifndef lint
static const char rcs[] = "@(#)$Id: decchk.c,v 1.1 2002-06-21 05:44:01 afalout Exp $";
#endif

/*
** In memory representation of:
**    NULL   => dec_pos =  -1
**    0.0000 => dec_pos =  +1, dec_exp = -64, dec_ndgts = 0
**    0.0001 => dec_pos =  +1, dec_exp =  -1, dec_ndgts = 1, dec_dgts[0] =  1
**    0.0010 => dec_pos =  +1, dec_exp =  -1, dec_ndgts = 1, dec_dgts[0] = 10
**   -0.0100 => dec_pos =   0, dec_exp =   0, dec_ndgts = 1, dec_dgts[0] =  1
**    0.1000 => dec_pos =  +1, dec_exp =   0, dec_ndgts = 1, dec_dgts[0] = 10
**   -1.0000 => dec_pos =   0, dec_exp =   1, dec_ndgts = 1, dec_dgts[0] =  1
**   99.0000 => dec_pos =  +1, dec_exp =   1, dec_ndgts = 1, dec_dgts[0] = 99
** -100.0000 => dec_pos =   0, dec_exp =   2, dec_ndgts = 1, dec_dgts[0] =  1
** 9900.0000 => dec_pos =  +1, dec_exp =   2, dec_ndgts = 1, dec_dgts[0] = 99
** Note that the mantissa is a fraction between 0.01 and 0.99... and the
** exponent matches this.
**
** DECIMAL(p,s)=> p = precision, s = scale.
** -- scale is number of decimal places.
** -- precision is total number of digits.
** -- scale == 0xFF => floating point
** -- 0 <= scale <= precision
** -- 0 < precision <= 32
*/

enum { ERR_OVERFLOW = -1226, WARN_LOSTPRECISION = +1241, WARN_UNDERFLOW = +1240 };

/* Check fixed point decimal and digits before decimal point */
static int dec_chk_fix_xdb(dec_t *d, int ld)
{
	int rc;
	
	assert(ld >= 0 && ld <= 32);
	if (d->dec_exp * 2 <= ld - 1)
		rc = 0;
	else if (d->dec_exp * 2 > ld + 1)
		rc = ERR_OVERFLOW;
	else if (ld % 2 == 0)
		rc = 0;
	else if (d->dec_dgts[0] < 10)
		rc = 0;
	else
		rc = ERR_OVERFLOW;
	return rc;
}

/* Check fixed point decimal and digits after decimal point */
static int dec_chk_fix_xda(dec_t *d, int dp)
{
	int rc;

	assert(dp >= 0 && dp <= 32);
	if (d->dec_exp >= d->dec_ndgts)
		rc = 0;		/* No fractional part */
	else if (d->dec_exp * -2 >= dp)
		rc = WARN_UNDERFLOW;
	else if ((d->dec_exp - d->dec_ndgts) * -2 > dp)
		rc = WARN_LOSTPRECISION;		/* Partial underflow */
	else if (dp % 2 == 0)
		rc = 0;
	else if (d->dec_dgts[d->dec_ndgts - 1] % 10 == 0)
		rc = 0;
	else
		rc = WARN_LOSTPRECISION;
	return rc;
}

/* Check fixed-point decimal */
static int dec_chk_fix(dec_t *d, int prec, int scale)
{
	int rc;

	if ((rc = dec_chk_fix_xdb(d, prec - scale)) == 0)
		rc = dec_chk_fix_xda(d, scale);
	return(rc);
}

void dec_setzero(dec_t *d)
{
	d->dec_ndgts = 0;
	d->dec_exp = -64;
	/* memset(d->dec_dgts, sizeof(d->dec_dgts), '\0'); */
}

int dec_is_zero(dec_t *d)
{
	return(d->dec_ndgts == 0 && d->dec_exp == -64);
}

void dec_setnull(dec_t *d)
{
	d->dec_pos = -1;
	/* d->dec_exp = -64; */
	/* memset(d->dec_dgts, sizeof(d->dec_dgts), '\0'); */
}

int dec_is_null(dec_t *d)
{
	return(d->dec_pos == -1);
}

#define dec_setnull(d)	((d)->dec_pos = -1, (void)0)
#define dec_is_null(d)	((d)->dec_pos == -1)

/* Check floating-point decimal */
static int dec_chk_exp(dec_t *d, int sf)
{
	int rc = 0;
	int dd = d->dec_ndgts * 2;

	assert(!dec_is_null(d) && !dec_is_zero(d));
	/*if (d->dec_ndgts * 2 > sf + 2)*/
	if (dd > sf + 2)
		rc = WARN_LOSTPRECISION;
	/*else if (d->dec_ndgts * 2 <= sf)*/
	/*else if (dd <= sf)*/
	/*	rc = 0;*/
	else if (dd > sf)
	{
		if (d->dec_dgts[0] < 10)
			dd--;
		if (d->dec_dgts[d->dec_ndgts-1] % 10 == 0)
			dd--;
		if (dd > sf)
			rc = WARN_LOSTPRECISION;
	}
	/*else*/
	/*	rc = WARN_LOSTPRECISION;*/
	return(rc);
}

/*
** dec_chk: check whether decimal value could be stored in SQL type
** Returns:   0 for a null, a zero value
**            0 for a value which fits into the SQL type (with no loss
**              of information)
**        -1226 for value to big to fit into fixed point
** (warn) +1240 for value which is zeroed to fit into fixed point
**              (complete underflow)
** (warn) +1241 for value which loses any information (partial underflow)
*/

int dec_chk(dec_t *d, int sqllen)
{
	int rc = 0;

	if (!dec_is_null(d) && !dec_is_zero(d))
	{
		/* Neither NULL nor Zero */
		int prec = PRECTOT(sqllen);
		int scale = PRECDEC(sqllen);
		if (scale == 0xFF || scale < 0)
			rc = dec_chk_exp(d, prec);
		else
			rc = dec_chk_fix(d, prec, scale);
	}
	return(rc);
}

/* decset: modify decimal value so it could be stored in SQL type */
int	dec_set(dec_t *d, int sqllen)
{
	int rc;

	if ((rc = dec_chk(d, sqllen)) != ERR_OVERFLOW)
	{
		int dp = PRECDEC(sqllen);
		if (dp == 0xFF || dp < 0)
		{
			/* Floating point DECIMAL */
#if 0
			int sf = (PRECTOT(sqllen) + 1) / 2;
			if (d->dec_ndgts > sf)
				dec_exp_round(d, sf);
#else
			assert(0);
#endif
		}
		else
		{
			/* Fixed point DECIMAL or MONEY */
			decround(d, dp);
		}
		rc = 0;
	}
	return(rc);
}


#ifdef TEST

#include <stdlib.h>
#include <string.h>

#define DIM(x)	(sizeof(x)/sizeof(*(x)))

typedef struct Testdata
{
	char *in;
	char *out;
	int prec;
	int scale;
	int chk_rv;
	int set_rv;
	char *purpose;
} Testdata;

static Testdata testdata[] =
{
	{ "", "", 9, 3, 0, 0, "NULL" },
	{ "0", "0.000", 9, 3, 0, 0, "Zero" },
	{ "0.1", "0", 9, 0, WARN_UNDERFLOW, 0, "trunc to zero" },
	{ "0.5", "1", 9, 0, WARN_LOSTPRECISION, 0, "round up - not coded yet" },
	{ "0.1", "0.1", 9, 1, 0, 0, "fits OK" },
	{ "0.01", "0.0", 9, 1, WARN_UNDERFLOW, 0, "trunc to zero" },
	{ "0.05", "0.1", 9, 1, WARN_LOSTPRECISION, 0, "round up - not coded yet" },
	{ "0.0999", "0.1", 9, 1, WARN_LOSTPRECISION, 0, "round up" },
	{ "1234.0999", "1234.1", 9, 1, WARN_LOSTPRECISION, 0, "round up" },
	{ "123456", "123456.0", 9, 1, 0, 0, "fits OK" },
	/* ...lots more tests to be added... */
};

static int test_decimal(int testnum, Testdata t)
{
	int err;
	int failures = 0;
	dec_t d;

	if ((err = deccvasc(t.in, strlen(t.in), &d)) != 0)
	{
		/* Will this handle NULL? */
		if (!dec_is_null(&d))
			printf("deccvasc did not set decimal to null\n");
		printf("deccvasc error %d on <<%s>>\n", err, t.in);
		failures++;
	}
	else
	{
		char buffer[256];
		int sqllen = PRECMAKE(t.prec, t.scale);
		dec_verify(&d);
		printf("%2d: <<%s>> => DECIMAL(%d,%d) => <<%s>> (%d,%d) -- %s\n",
				testnum, t.in, t.prec, t.scale, t.out, t.chk_rv, t.set_rv, t.purpose);
		err = dec_chk(&d, sqllen);
		if (err != t.chk_rv)
		{
			failures++;
			printf("%2d: **FAIL: dec_chk() - got %d, wanted %d\n", testnum, err, t.chk_rv);
		}
		err = dec_set(&d, sqllen);
		if (err != t.set_rv)
		{
			failures++;
			printf("%2d: **FAIL: dec_set() - got %d, wanted %d\n", testnum, err, t.set_rv);
		}
		dec_verify(&d);
		if (err != 0 && !dec_is_null(&d))
		{
			failures++;
			printf("%2d: **FAIL: dec_set() - set failed but value not null -- %s\n", testnum, t.in);
		}
		if ((err = dectoasc(&d, buffer, sizeof(buffer), (t.scale == 0xFF) ? -1 : t.scale)) != 0)
		{
			failures++;
			printf("%2d: **FAIL: dectoasc() - conversion failed (%d)\n", testnum, err);
		}
		else
		{
			char *blank = strchr(buffer, ' ');
			if (blank != 0)
				*blank = '\0';
			if (strcmp(t.out, buffer) != 0)
			{
				failures++;
				printf("%2d: **FAIL: dec_set() - got <<%s>>, wanted <<%s>>\n", testnum, buffer, t.in);
			}
		}
		if (failures == 0)
			printf("%2d: ==PASS\n", testnum);
	}
	return(failures);
}

int main(void)
{
	int i;
	int n = DIM(testdata);
	int failures = 0;
	int passed = 0;

	for (i = 0; i < n; i++)
	{
		int nfail = test_decimal(i, testdata[i]);
		if (nfail == 0)
			passed++;
		failures += nfail;
	}

	if (failures == 0)
		printf("PASS: %d tests run OK\n", n);
	else
		printf("FAIL: %d failures from %d tests run (%d passed)\n", failures, n, passed);

	return(failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE);
}

#endif /* TEST */

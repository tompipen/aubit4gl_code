/*
@(#)File:            $RCSfile: decvfy.c,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-06-21 05:44:01 $
@(#)Purpose:         Verify contents of decimal structure
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 2001
@(#)Product:         :PRODUCT:
*/

#include <assert.h>
#include "esqlc.h"
#include "decsci.h"

#undef NDEBUG
#include <assert.h>
#include <stdio.h>
#include "esqlutil.h"

#define ASSERT(x, dp) (!(x) ? dump_decimal(stderr, "dec_verify: failed assertion: " #x, dp), assert(0) : (void)0)

#ifndef lint
static const char rcs[] = "@(#)$Id: decvfy.c,v 1.1 2002-06-21 05:44:01 afalout Exp $";
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

void dec_verify(dec_t *d)
{
	int i;
	ASSERT(d->dec_pos >= -1 && d->dec_pos <= +1, d);
	if (d->dec_pos == -1)
		return;	/* NULL */
	ASSERT(d->dec_exp >= -64 && d->dec_exp <= +63, d);
	if (d->dec_exp == -64 && d->dec_ndgts == 0)
		return;	/* Zero */
	ASSERT(d->dec_ndgts > 0 && d->dec_ndgts <= 16, d);
	ASSERT(d->dec_dgts[0] != 0, d);
	ASSERT(d->dec_dgts[d->dec_ndgts-1] != 0, d);
	for (i = 0; i < d->dec_ndgts; i++)
		ASSERT(d->dec_dgts[i] >= 0 && d->dec_dgts[0] < 100, d);
}


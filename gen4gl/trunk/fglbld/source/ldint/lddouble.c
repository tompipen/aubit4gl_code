/*
@(#)File:            $RCSfile: lddouble.c,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-06-21 05:44:01 $
@(#)Purpose:         Implement ld_double(), ld_double_null() - Compatible with C-ISAM lddbl(), lddblnull()
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 2000
@(#)Product:         :PRODUCT:
*/

/*TABSTOP=4*/

#include <assert.h>
#include <string.h>
#include "stldint.h"

#ifndef lint
static const char rcs[] = "@(#)$Id: lddouble.c,v 1.1 2002-06-21 05:44:01 afalout Exp $";
#endif

/*
** ld_double - load double number from unaligned memory
*/
double ld_double(const char *p)
{
	double dval;
	memcpy(&dval, p, sizeof(double));
	return(dval);
}

/*
** ld_double_null - load double number from unaligned memory, checking for null
** Prototype imperative!
*/
double ld_double_null(const char *cptr, short *nullflag)
{
    /* if all the characters = -1 then the value is null */
	static const char null[sizeof(double)] = { -1, -1, -1, -1, -1, -1, -1, -1 };

	assert(sizeof(double) == 8);
    if (memcmp(cptr, null, sizeof(double)) == 0)
	{
		*nullflag= 1;
		return(0.0);
	}
    else
	{
		*nullflag= 0;
		return(ld_double(cptr));
	}
}

#ifdef TEST

#include <assert.h>
#include <stdio.h>

int main(void)
{
}

#endif /* TEST */

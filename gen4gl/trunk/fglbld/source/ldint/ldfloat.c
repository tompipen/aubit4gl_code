/*
@(#)File:            $RCSfile: ldfloat.c,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-06-21 05:44:01 $
@(#)Purpose:         Implement ld_float(), ld_float_null() - Compatible with C-ISAM ldfloat(), ldfltnull()
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 2000
@(#)Product:         :PRODUCT:
*/

/*TABSTOP=4*/

#include <assert.h>
#include <string.h>
#include "stldint.h"

#ifndef lint
static const char rcs[] = "@(#)$Id: ldfloat.c,v 1.1 2002-06-21 05:44:01 afalout Exp $";
#endif


/*
** ld_float - load float number from unaligned memory
** Prototype imperative!
*/
float ld_float(const char *p)
{
	float fval;
	memcpy(&fval, p, sizeof(float));
	return(fval);
}

/*
** ld_float_null - load float number from unaligned memory, checking for null
** Prototype imperative!
*/
float ld_float_null(const char *cptr, short *nullflag)
{
    /* if all the characters = -1 then the value is null */
	static const char null[sizeof(float)] = { -1, -1, -1, -1 };

	assert(sizeof(float) == 4);
    if (memcmp(cptr, null, sizeof(float)) == 0)
	{
		*nullflag= 1;
		return(0.0);
	}
    else
	{
		*nullflag= 0;
		return(ld_float(cptr));
	}
}

#ifdef TEST

#include <assert.h>
#include <stdio.h>

int main(void)
{
}

#endif /* TEST */

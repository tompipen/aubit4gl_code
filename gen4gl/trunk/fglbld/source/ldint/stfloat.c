/*
@(#)File:            $RCSfile: stfloat.c,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-06-21 05:44:01 $
@(#)Purpose:         Implement st_float(), st_float_null() - Compatible with C-ISAM stfloat(), stfltnull()
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 2000
@(#)Product:         :PRODUCT:
*/

/*TABSTOP=4*/

#include <string.h>
#include "stldint.h"

#ifndef lint
static const char rcs[] = "@(#)$Id: stfloat.c,v 1.1 2002-06-21 05:44:01 afalout Exp $";
#endif

/*
** st_float - store float number into unaligned memory
** Prototype imperative!
*/
void st_float(float fval, char *p)
{
	memcpy(p, &fval, sizeof(float));
}

/*
** st_float_null - store float number into unaligned memory, checking for null
** Prototype imperative!
*/
void st_float_null(float fval, char *ptr, short nullflag)
{
    if (nullflag)
		memset(ptr, -1, sizeof(float));
    else
		st_float(fval, ptr);
}

#ifdef TEST

#include <assert.h>
#include <stdio.h>

int main(void)
{
}

#endif /* TEST */

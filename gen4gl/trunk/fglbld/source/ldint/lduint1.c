/*
@(#)File:            $RCSfile: lduint1.c,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-06-21 05:44:01 $
@(#)Purpose:         C-ISAM style LD_UINT1(3)
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 2000
@(#)Product:         :PRODUCT:
*/

/*TABSTOP=4*/
/*LINTLIBRARY*/

#include "stldint.h"

#ifndef lint
static const char rcs[] = "@(#)$Id: lduint1.c,v 1.1 2002-06-21 05:44:01 afalout Exp $";
#endif

/*
**	Convert 1-byte character array into unsigned 1-byte integer.
*/
Uint1          ld_uint1(register const char *s)
{
	register Uint1 u1 = *(signed char *)s;
	return(u1);
}

#ifdef TEST

#include <stdio.h>

#define DIM(x)	(sizeof(x)/sizeof(*(x)))

static char values[][2] =
{
	"\000",
	"\002",
	"\017",
	"\177",
	"\200",
	"\377",
};

int main(void)
{
	int             i;

	puts("LOAD Unsigned 1-Byte Integer");
	for (i = 0; i < DIM(values); i++)
		printf("0x%02X => 0x%02X\n", (unsigned char)values[i][0], ld_uint1(values[i]));
	return(0);
}

#endif	/* TEST */

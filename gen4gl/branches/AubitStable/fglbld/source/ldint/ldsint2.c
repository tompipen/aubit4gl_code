/*
@(#)File:            $RCSfile: ldsint2.c,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-06-21 05:44:01 $
@(#)Purpose:         C-ISAM style LD_SINT2(3)
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 2000
@(#)Product:         :PRODUCT:
*/

/*TABSTOP=4*/
/*LINTLIBRARY*/

#include "stldint.h"

#ifndef lint
static const char rcs[] = "@(#)$Id: ldsint2.c,v 1.1 2002-06-21 05:44:01 afalout Exp $";
#endif

/*
**	Convert 2-byte character array into signed 2-byte integer.
*/
Sint2          ld_sint2(register const char *s)
{
	register int    i;
	register Sint2  j = 0;

	for (i = 0; i < 2; i++)
	{
		j = (j << 8) | (*s++ & 0xFF);
	}
	return(j);
}

#ifdef TEST

#include <stdio.h>

#define DIM(x)	(sizeof(x)/sizeof(*(x)))

static char values[][2] =
{
	"\000\000",
	"\002\003",
	"\017\017",
	"\177\177",
	"\177\377",
	"\200\000",
	"\200\200",
	"\377\377",
};

int main(void)
{
	int             i;

	puts("LOAD Signed 2-Byte Integer");
	for (i = 0; i < DIM(values); i++)
	{
		printf("0x%02X%02X => %6d => 0x%04X\n",
			   (unsigned char)values[i][0], (unsigned char)values[i][1],
			   ld_sint2(values[i]), (Uint2)ld_sint2(values[i]));
	}
	return(0);
}

#endif	/* TEST */

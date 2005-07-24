/*
@(#)File:            $RCSfile: lduint4.c,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-06-21 05:44:01 $
@(#)Purpose:         C-ISAM style LD_UINT4(3)
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 2000
@(#)Product:         :PRODUCT:
*/

/*TABSTOP=4*/
/*LINTLIBRARY*/

#include "stldint.h"

#ifndef lint
static const char rcs[] = "@(#)$Id: lduint4.c,v 1.1 2002-06-21 05:44:01 afalout Exp $";
#endif

/*
**	Convert 4-byte character array into unsigned 4-byte integer.
*/
Uint4	ld_uint4(register const char *s)
{
	register int	i;
	register Uint4	j = 0;

	for (i = 0; i < 4; i++)
	{
		j = (j << 8) | (*s++ & 0xFF);
	}
	return(j);
}

#ifdef TEST

#include <stdio.h>

#define DIM(x)	(sizeof(x)/sizeof(*(x)))

static char     values[][4] =
{
	"\000\000\000\000",
	"\001\002\003\004",
	"\177\377\377\377",
	"\200\000\000\000",
	"\327\147\167\377",
	"\377\377\377\377",
};

int main(void)
{
	int             i;

	puts("LOAD Unsigned 4-Byte Integer");
	for (i = 0; i < DIM(values); i++)
	{
		printf("0x%02X%02X%02X%02X => 0x%08lX\n",
			   (unsigned char)values[i][0], (unsigned char)values[i][1],
			   (unsigned char)values[i][2], (unsigned char)values[i][3],
			   ld_uint4(values[i]));
	}
	return(0);
}

#endif	/* TEST */

/*
@(#)File:            $RCSfile: lduint8.c,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-06-21 05:44:01 $
@(#)Purpose:         C-ISAM style LD_UINT8(3)
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 2000
@(#)Product:         :PRODUCT:
*/

/*TABSTOP=4*/
/*LINTLIBRARY*/

#include "stldint.h"

#ifndef lint
static const char rcs[] = "@(#)$Id: lduint8.c,v 1.1 2002-06-21 05:44:01 afalout Exp $";
#endif

/*
**	Convert 8-byte character array into unsigned 8-byte integer.
*/
Uint8	ld_uint8(register const char *s)
{
	register int	i;
	register Uint8	j = 0;

	for (i = 0; i < 8; i++)
	{
		j = (j << 8) | (*s++ & 0xFF);
	}
	return(j);
}

#ifdef TEST

#include <stdio.h>

#define DIM(x)	(sizeof(x)/sizeof(*(x)))

static char     values[][8] =
{
	"\000\000\000\000\000\000\000\000",
	"\001\002\003\004\005\006\007\008",
	"\177\377\377\377\377\377\377\377",
	"\200\000\000\000\000\000\000\000",
	"\327\147\167\377\222\111\333\000",
	"\377\377\377\377\377\377\377\377",
};

int main(void)
{
	int             i;

	puts("LOAD Unsigned 8-Byte Integer");
	for (i = 0; i < DIM(values); i++)
	{
		printf("0x%02X%02X%02X%02X%02X%02X%02X%02X => 0x%016llX\n",
			   (unsigned char)values[i][0], (unsigned char)values[i][1],
			   (unsigned char)values[i][2], (unsigned char)values[i][3],
			   (unsigned char)values[i][4], (unsigned char)values[i][5],
			   (unsigned char)values[i][6], (unsigned char)values[i][7],
			   ld_uint8(values[i]));
	}
	return(0);
}

#endif	/* TEST */

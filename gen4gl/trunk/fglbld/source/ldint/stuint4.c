/*
@(#)File:            $RCSfile: stuint4.c,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-06-21 05:44:01 $
@(#)Purpose:         C-ISAM style ST_UINT4(3)
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 2000
@(#)Product:         :PRODUCT:
*/

/*TABSTOP=4*/
/*LINTLIBRARY*/

#include "stldint.h"

#ifndef lint
static const char rcs[] = "@(#)$Id: stuint4.c,v 1.1 2002-06-21 05:44:01 afalout Exp $";
#endif

/*
**	Convert unsigned 4-byte integer into 4-byte character array.
*/
void		st_uint4(register Uint4 l, register char *s)
{
	s += sizeof(Uint4) - 1;
	*s-- = l & 0xFF;
	l >>= 8;
	*s-- = l & 0xFF;
	l >>= 8;
	*s-- = l & 0xFF;
	l >>= 8;
	*s   = l & 0xFF;
}

#ifdef TEST

#include <stdio.h>
#include <assert.h>

#define DIM(x)	(sizeof(x)/sizeof(*(x)))

static Uint4 values[] =
{
	 0x00000000,
	 0x01020304,
	 0x7FFFFFFF,
	 0x80000000,
	 0x976770FF,
	 0xFFFFFFFF,
};

int main(void)
{
	char            buff[5];
	int             i;

	puts("STORE Unsigned 4-Byte Integer");
	for (i = 0; i < DIM(values); i++)
	{
		buff[4] = i;
		st_uint4(values[i], buff);
		printf("0x%08lX => 0x%02X%02X%02X%02X\n", values[i],
			   (unsigned char)buff[0], (unsigned char)buff[1],
			   (unsigned char)buff[2], (unsigned char)buff[3]);
		assert(buff[4] == i);
	}
	return(0);
}

#endif	/* TEST */

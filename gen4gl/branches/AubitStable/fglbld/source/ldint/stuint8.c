/*
@(#)File:            $RCSfile: stuint8.c,v $
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
static const char rcs[] = "@(#)$Id: stuint8.c,v 1.1 2002-06-21 05:44:01 afalout Exp $";
#endif

/*
**	Convert unsigned 8-byte integer into 8-byte character array.
*/
void		st_uint8(register Uint8 l, register char *s)
{
	s += sizeof(Uint8) - 1;
	*s-- = l & 0xFF;
	l >>= 8;
	*s-- = l & 0xFF;
	l >>= 8;
	*s-- = l & 0xFF;
	l >>= 8;
	*s-- = l & 0xFF;
	l >>= 8;
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

static Uint8 values[] =
{
	 0x0000000000000000,
	 0x0102030405060708,
	 0x7FFFFFFFFFFFFFFF,
	 0x8000000000000000,
	 0x976770FF22334455,
	 0xFFFFFFFFFFFFFFFF,
};

int main(void)
{
	char            buff[9];
	int             i;

	puts("STORE Unsigned 8-Byte Integer");
	for (i = 0; i < DIM(values); i++)
	{
		buff[8] = i;
		st_uint8(values[i], buff);
		printf("0x%016llX => 0x%02X%02X%02X%02X%02X%02X%02X%02X\n", values[i],
			   (unsigned char)buff[0], (unsigned char)buff[1],
			   (unsigned char)buff[2], (unsigned char)buff[3],
			   (unsigned char)buff[4], (unsigned char)buff[5],
			   (unsigned char)buff[6], (unsigned char)buff[7]);
		assert(buff[8] == i);
	}
	return(0);
}

#endif	/* TEST */

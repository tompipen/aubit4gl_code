/*
@(#)File:            $RCSfile: stsint4.c,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-06-21 05:44:01 $
@(#)Purpose:         C-ISAM style ST_SINT4(3)
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 2000
@(#)Product:         :PRODUCT:
*/

/*TABSTOP=4*/
/*LINTLIBRARY*/

#include "stldint.h"

#ifndef lint
static const char rcs[] = "@(#)$Id: stsint4.c,v 1.1 2002-06-21 05:44:01 afalout Exp $";
#endif

/*
**	Convert signed 4-byte signed integer into 4-byte character array.
*/
void		st_sint4(register Sint4 l, register char *s)
{
	s += sizeof(Sint4) - 1;
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

static Sint4 values[] =
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

	puts("STORE Signed 4-Byte Integer");
	for (i = 0; i < DIM(values); i++)
	{
		buff[4] = i;
		st_sint4(values[i], buff);
		printf("%11ld => 0x%08lX => 0x%02X%02X%02X%02X\n", values[i], (Uint4)values[i],
			   (unsigned char)buff[0], (unsigned char)buff[1],
			   (unsigned char)buff[2], (unsigned char)buff[3]);
		assert(buff[4] == i);
	}
	return(0);
}

#endif	/* TEST */

/*
@(#)File:            $RCSfile: stuint2.c,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-06-21 05:44:01 $
@(#)Purpose:         C-ISAM style ST_UINT2(3)
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 2000
@(#)Product:         :PRODUCT:
*/

/*TABSTOP=4*/
/*LINTLIBRARY*/

#include "stldint.h"

#ifndef lint
static const char rcs[] = "@(#)$Id: stuint2.c,v 1.1 2002-06-21 05:44:01 afalout Exp $";
#endif

/*
**	Convert unsigned 2-byte integer into 2-byte character array
*/
void            st_uint2(register Uint2 i, register char *s)
{
	*s++ = (i >> 8) & 0xFF;
	*s = i & 0xFF;
}

#ifdef TEST

#include <stdio.h>
#include <assert.h>

#define DIM(x)	(sizeof(x)/sizeof(*(x)))

static Uint2 values[] =
{
	 0x0000,
	 0x0102,
	 0x7FFF,
	 0x8000,
	 0xFFFF,
};

int main(void)
{
	char            buff[3];
	int             i;

	puts("STORE Unsigned 2-Byte Integer");
	for (i = 0; i < DIM(values); i++)
	{
		buff[2] = i;
		st_uint2(values[i], buff);
		printf("0x%04X => 0x%02X%02X \n", values[i],
			   (unsigned char)buff[0], (unsigned char)buff[1]);
		assert(buff[2] == i);
	}
	return(0);
}

#endif	/* TEST */

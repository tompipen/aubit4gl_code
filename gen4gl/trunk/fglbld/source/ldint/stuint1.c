/*
@(#)File:            $RCSfile: stuint1.c,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-06-21 05:44:01 $
@(#)Purpose:         C-ISAM style ST_UINT1(3)
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 2000
@(#)Product:         :PRODUCT:
*/

/*TABSTOP=4*/
/*LINTLIBRARY*/

#include "stldint.h"

#ifndef lint
static const char rcs[] = "@(#)$Id: stuint1.c,v 1.1 2002-06-21 05:44:01 afalout Exp $";
#endif

/*
**	Convert unsigned 1-byte integer into 1-byte character array
*/
void            st_uint1(register Uint1 i, register char *s)
{
	*s = i;
}

#ifdef TEST

#include <stdio.h>
#include <assert.h>

#define DIM(x)	(sizeof(x)/sizeof(*(x)))

static Uint1 values[] =
{
	 0x00,
	 0x01,
	 0x7F,
	 0x80,
	 0xFF,
};

int main(void)
{
	char            buff[2];
	int             i;

	puts("STORE Unsigned 1-Byte Integer");
	for (i = 0; i < DIM(values); i++)
	{
		buff[1] = i;
		st_uint1(values[i], buff);
		printf("0x%02X => 0x%02X\n", values[i],
			   (unsigned char)buff[0]);
		assert(buff[1] == i);
	}
	return(0);
}

#endif	/* TEST */

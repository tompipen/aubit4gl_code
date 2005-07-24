/*
@(#)File:            $RCSfile: stsint1.c,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-06-21 05:44:01 $
@(#)Purpose:         C-ISAM style ST_SINT1(3)
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 2000
@(#)Product:         :PRODUCT:
*/

/*TABSTOP=4*/
/*LINTLIBRARY*/

#include "stldint.h"

#ifndef lint
static const char rcs[] = "@(#)$Id: stsint1.c,v 1.1 2002-06-21 05:44:01 afalout Exp $";
#endif

/*
**	Convert signed 1-byte integer into 1-byte character array
*/
void            st_sint1(register Sint1 i, register char *s)
{
	*s = i;
}

#ifdef TEST

#include <stdio.h>
#include <assert.h>

#define DIM(x)	(sizeof(x)/sizeof(*(x)))

static Sint1 values[] =
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

	puts("STORE Signed 1-Byte Integer");
	for (i = 0; i < DIM(values); i++)
	{
		buff[1] = i;
		st_sint1(values[i], buff);
		printf("%4d => %4d\n", values[i], buff[0]);
		assert(buff[1] == i);
	}
	return(0);
}

#endif	/* TEST */

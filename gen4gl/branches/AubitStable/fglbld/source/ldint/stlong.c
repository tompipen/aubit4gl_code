/*
@(#)File:            $RCSfile: stlong.c,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-06-21 05:44:01 $
@(#)Purpose:         C-ISAM style STLONG(3)
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1990-91,1997
@(#)Product:         :PRODUCT:
*/

/*TABSTOP=4*/
/*LINTLIBRARY*/

#include "stldint.h"

#ifndef lint
static const char rcs[] = "@(#)$Id: stlong.c,v 1.1 2002-06-21 05:44:01 afalout Exp $";
#endif

/*
**	Convert long integer into 4-byte character array.
**	Works on both 680x0 and 80x86 type machines.
**	Slows 680x0 type machines up as it is then a no-op.
*/
void		stlong(register long int l, register char *s)
{
	s += sizeof(long) - 1;
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

#define DIM(x)	(sizeof(x)/sizeof(*(x)))

static long    values[] =
{
	 0x01020304,
	 0x576777FF
};

int main(void)
{
	char            buff[4];
	int             i;

	for (i = 0; i < DIM(values); i++)
	{
		stlong(values[i], buff);
		printf("0x%08lX => 0x%02X%02X%02X%02X \n", values[i],
			   (unsigned char)buff[0], (unsigned char)buff[1],
			   (unsigned char)buff[2], (unsigned char)buff[3]);
	}
	return(0);
}

#endif	/* TEST */

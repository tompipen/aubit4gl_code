/*
@(#)File:            $RCSfile: ldlong.c,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-06-21 05:44:01 $
@(#)Purpose:         C-ISAM style LDLONG(3)
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1990-91,1997
@(#)Product:         :PRODUCT:
*/

/*TABSTOP=4*/
/*LINTLIBRARY*/

#include "stldint.h"

#ifndef lint
static const char rcs[] = "@(#)$Id: ldlong.c,v 1.1 2002-06-21 05:44:01 afalout Exp $";
#endif

/*
**	Convert 4-byte character array into real long integer.
**	Works on both 680x0 and 80x86 type machines.
**	Slows 680x0 type machines up as it is then a no-op.
*/
Ulong	ldlong(register char *s)
{
	register int	i;
	register Ulong	j;

	for (i = j = 0; i < 4; i++)
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
	"\001\002\003\004",
	"\127\147\167\377"
};

int main(void)
{
	int             i;

	for (i = 0; i < DIM(values); i++)
		printf("0x%02X%02X%02X%02X => 0x%08lX\n",
			   (unsigned char)values[i][0], (unsigned char)values[i][1],
			   (unsigned char)values[i][2], (unsigned char)values[i][3],
			   ldlong(values[i]));
	return(0);
}

#endif	/* TEST */

/*
@(#)File:            $RCSfile: ldint.c,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-06-21 05:44:01 $
@(#)Purpose:         C-ISAM style LDINT(3)
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1990-91,1997
@(#)Product:         :PRODUCT:
*/

/*TABSTOP=4*/
/*LINTLIBRARY*/

#include "stldint.h"

#ifndef lint
static const char rcs[] = "@(#)$Id: ldint.c,v 1.1 2002-06-21 05:44:01 afalout Exp $";
#endif

/*
**	Convert 2-byte character array into real short integer
**	Works on both 680x0 and 80x86 type machines.
**	Slows 680x0 type machines up as it is then a no-op.
*/
Ushort          ldint(register char *s)
{
	register int    i;
	register Ushort j;

	for (i = j = 0; i < 2; i++)
	{
		j = (j << 8) | (*s++ & 0xFF);
	}
	return(j);
}

#ifdef TEST

#include <stdio.h>

#define DIM(x)	(sizeof(x)/sizeof(*(x)))

static char values[][2] =
{
	"\002\003",
	"\017\017"
};

int main(void)
{
	int             i;

	for (i = 0; i < DIM(values); i++)
		printf("0x%02X%02X => 0x%04X\n",
			   (unsigned char)values[i][0], (unsigned char)values[i][1],
			   ldint(values[i]));
	return(0);
}

#endif	/* TEST */

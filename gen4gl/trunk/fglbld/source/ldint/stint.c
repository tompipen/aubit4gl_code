/*
@(#)File:            $RCSfile: stint.c,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-06-21 05:44:01 $
@(#)Purpose:         C-ISAM style STINT(3)
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1990-91,1997
@(#)Product:         :PRODUCT:
*/

/*TABSTOP=4*/
/*LINTLIBRARY*/

#include "stldint.h"

#ifndef lint
static const char rcs[] = "@(#)$Id: stint.c,v 1.1 2002-06-21 05:44:01 afalout Exp $";
#endif

/*
**	Convert short integer into 2-byte character array
**	Works on both 680x0 and 80x86 type machines.
**	Slows 680x0 type machines as it is then a no-op.
*/
void            stint(register short int i, register char *s)
{
	*s++ = (i >> 8) & 0xFF;
	*s = i & 0xFF;
}

#ifdef TEST

#include <stdio.h>

#define DIM(x)	(sizeof(x)/sizeof(*(x)))

static short values[] =
{
	 0x0102,
	 0x77FF
};

int main(void)
{
	char            buff[2];
	int             i;

	for (i = 0; i < DIM(values); i++)
	{
		stint(values[i], buff);
		printf("0x%04X => 0x%02X%02X \n", values[i],
			   (unsigned char)buff[0], (unsigned char)buff[1]);
	}
	return(0);
}

#endif	/* TEST */

/*
@(#)File:            $RCSfile: ldsint1.c,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-06-21 05:44:01 $
@(#)Purpose:         C-ISAM style LD_SINT1(3)
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 2000
@(#)Product:         :PRODUCT:
*/

/*TABSTOP=4*/
/*LINTLIBRARY*/

#include "stldint.h"

#ifndef lint
static const char rcs[] = "@(#)$Id: ldsint1.c,v 1.1 2002-06-21 05:44:01 afalout Exp $";
#endif

/*
**	Convert 1-byte character array into signed 1-byte integer
*/
Sint1          ld_sint1(register const char *s)
{
	register Sint1 s1 = *(Sint1 *)s;
	return(s1);
}

#ifdef TEST

#include <stdio.h>

#define DIM(x)	(sizeof(x)/sizeof(*(x)))

static char values[][2] =
{
	"\000",
	"\002",
	"\017",
	"\177",
	"\200",
	"\377",
};

int main(void)
{
	int             i;

	puts("LOAD Signed 1-Byte Integer");
	for (i = 0; i < DIM(values); i++)
		printf("%4d => %4d\n", (signed char)values[i][0], ld_sint1(values[i]));
	return(0);
}

#endif	/* TEST */

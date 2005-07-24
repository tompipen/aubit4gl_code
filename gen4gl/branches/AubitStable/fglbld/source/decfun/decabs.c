/*
@(#)File:            $RCSfile: decabs.c,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-06-21 05:44:01 $
@(#)Purpose:         Absolute value of DECIMAL variable
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1992,1997
@(#)Product:         :PRODUCT:
*/

/*TABSTOP=4*/
/*LINTLIBRARY*/

#include "decsci.h"

#ifndef lint
static const char rcs[] = "@(#)$Id: decabs.c,v 1.1 2002-06-21 05:44:01 afalout Exp $";
#endif

int decabs(const dec_t *x, dec_t *r1)
{
	*r1 = *x;
	if (r1->dec_pos != -1)	/* not null */
		r1->dec_pos = 1;
	return(0);
}

#ifdef TEST

#include <stdio.h>

#define DIM(x)	(sizeof(x)/sizeof(*(x)))

static const char *decimals[] =
{
	"-1.0",
	"0.0",
	"1.0",
	"2e-120",
	"-2e-120",
	"2e+120",
	"-2e+120"
};

int main(void)
{
	int		i;
	int		j;
	int     k;
	dec_t	num;
	dec_t	res;
	char    buffer[40];
	char    bufnum[40];

	for (j = 0; j < DIM(decimals); j++)
	{
		if ((i = deccvasc(decimals[j], strlen(decimals[j]), &num)) != 0)
		{
			fprintf(stderr, "error %d from deccvasc processing %s\n",
					i, decimals[j]);
			exit(0);
		}

		k = decabs(&num, &res);

		strcpy(bufnum, decsci(&num, 10, 0));
		strcpy(buffer, decsci(&res, 10, 0));

		printf("%2d: %5d: ABS(%s) = %s\n", i, k, bufnum, buffer);
	}
	return(0);
}

#endif	/* TEST */

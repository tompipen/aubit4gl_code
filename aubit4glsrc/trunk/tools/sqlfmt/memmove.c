/*
@(#)File:            $RCSfile: memmove.c,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-11-28 06:40:47 $
@(#)Purpose:         Simulate MEMMOVE(3)
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1991,1997
@(#)Product:         SQLFMT Version 14 (1998-11-04)
*/

/*TABSTOP=4*/
/*LINTLIBRARY*/

#include <string.h>

#ifndef lint
static const char rcs[] = "@(#)$Id: memmove.c,v 1.1 2002-11-28 06:40:47 afalout Exp $";
#endif

void           *memmove(void *s1, const void *s2, size_t n)
{
	const char     *t;
	char           *t1 = (char *)s1;
	const char     *t2 = (const char *)s2;
	void           *s = s1;

	if (t1 < t2)
	{							/* Copy forwards */
		t = t1 + n;
		while (t1 < t)
			*t1++ = *t2++;
	}
	else
	{							/* Copy backwards */
		t = t2;
		t1 += n;
		t2 += n;
		while (t2 > t)
			*--t1 = *--t2;
	}
	return(s);
}

#ifdef TEST

#include <stdio.h>

int main(void)
{
	char            buffer[80];
	int             ok = 0;

	strcpy(&buffer[0], "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	printf("buffer = %s\n", buffer);
	printf("memmove(&buffer[0], &buffer[9], 10);\n");
	memmove(&buffer[0], &buffer[9], 10);
	printf("buffer = %s\n", buffer);
	if (strcmp(buffer, "JKLMNOPQRSKLMNOPQRSTUVWXYZ") != 0)
		ok++, printf("** FAILED **\n");
	printf("memmove(&buffer[5], &buffer[0], 10);\n");
	memmove(&buffer[5], &buffer[0], 10);
	printf("buffer = %s\n", buffer);
	if (strcmp(buffer, "JKLMNJKLMNOPQRSPQRSTUVWXYZ") != 0)
		ok++, printf("** FAILED **\n");

	if (ok == 0)
		printf("OK\n");
	return(0);
}

#endif	/* TEST */

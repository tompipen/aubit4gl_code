/*
@(#)File:            $RCSfile: strlower.c,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-11-28 06:40:47 $
@(#)Purpose:         Convert string to lower case
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1992,1997-98
@(#)Product:         SQLFMT Version 14 (1998-11-04)
*/

/*TABSTOP=4*/

#define _POSIX_SOURCE	1

#include <ctype.h>
#include "jlss.h"

#ifndef lint
static const char rcs[] = "@(#)$Id: strlower.c,v 1.1 2002-11-28 06:40:47 afalout Exp $";
#endif

char	*strlower(char *s)
{
	char	*t = s;
	char	 c;

	while ((c = *t) != '\0')
		*t++ = tolower(c);
	return(t);
}

#ifdef TEST

static char *list[] =
{
	"ALL UPPER CASE OR NON-ALPHA _0123456789~`!@#$%^&*()-=+[]{}|\\\"':;/?.,<>",
	"all lower case",
	"mIxEd CaSe",
	(char *)0
};

#include <stdio.h>
#include <string.h>
#include <assert.h>

int main(void)
{
	char	**s;
	char     *end;
	char     *src;
	char      buffer[128];

	for (s = list; *s != (char *)0; s++)
	{
		strcpy(buffer, *s);
		printf("Before: %s\n", buffer);
		end = strlower(buffer);
		assert(*end == '\0');
		for (src = buffer; src < end; src++)
		{
			char c = *src;
			assert(!isalpha(c) || islower(c));
		}
		printf("After:  %s\n", buffer);
	}
	return(0);
}

#endif	/* TEST */

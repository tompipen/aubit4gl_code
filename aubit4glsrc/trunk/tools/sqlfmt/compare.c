/*
	@(#)$Id: compare.c,v 1.1 2002-11-28 06:40:47 afalout Exp $
	@(#)Keyword comparison for sqlfmt
	J Leffler
*/

#include <ctype.h>
#include "sqlfmt.h"

#ifndef lint
static const char sccs[] = "@(#)$Id: compare.c,v 1.1 2002-11-28 06:40:47 afalout Exp $";
#endif

int upper(c)
char	c;
{
	return(toupper(c));
}

int compare(const void *item, const void *entry)
{
	register const char	*s1 = (const char *)item;
	register const char	*s2 = *(const char **)entry;
	register char	c1, c2;

	c1 = upper(*s1++);
	c2 = upper(*s2++);

	while (c1 != '\0' && c1 == c2)
	{
		c1 = upper(*s1++);
		c2 = upper(*s2++);
	}
	return(c1 - c2);
}

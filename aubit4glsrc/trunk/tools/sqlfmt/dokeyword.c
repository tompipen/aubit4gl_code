/*
	@(#)$Id: dokeyword.c,v 1.1 2002-11-28 06:40:47 afalout Exp $
	@(#)Keyword comparison for sqlfmt
	@(#)J Leffler
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqlfmt.h"

#ifndef BIGKEYWORDSIZE
#define BIGKEYWORDSIZE	1024
#endif

#ifndef lint
static const char sccs[] = "@(#)$Id: dokeyword.c,v 1.1 2002-11-28 06:40:47 afalout Exp $";
#endif

static void print_mapped(int f, const char *s)
{
	char buffer[BIGKEYWORDSIZE];

	assert(strlen(s) < sizeof(buffer));
	strcpy(buffer, s);
	switch (f)
	{
	case PLAIN_CASE:
		break;
	case UPPER_CASE:
		strupper(buffer);
		break;
	case LOWER_CASE:
		strlower(buffer);
		break;
	}
	fputs(buffer, stdout);
}

void dokeyword(const char *s, int l)
{
	void	*what;

	what = bsearch(s, kw_table, kw_size, sizeof(char *), compare);
	if (what != NULL)
		print_mapped(kflag, *(char **)what);	/* Print mapped keyword */
	else
		print_mapped(wflag, s);					/* Print mapped non-keyword */
}

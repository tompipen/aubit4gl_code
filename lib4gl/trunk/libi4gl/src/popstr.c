/*
@(#)File:            $RCSfile: popstr.c,v $
@(#)Version:         $Revision: 1.2 $
@(#)Last changed:    $Date: 2002-06-14 09:23:16 $
@(#)Purpose:         Pop string and strip trailing blanks
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1988,1990,1998
*/

#include <string.h>
#include <assert.h>

#ifdef FOURJS
#include "f2c/r_c.h"
#else
#include "fglsys.h"
#endif

#ifndef lint
static const char rcs[] = "@(#)$Id: popstr.c,v 1.2 2002-06-14 09:23:16 afalout Exp $";
#endif

/* -- Routine: popstring		*/

void	popstring(char *s, int l)
{
	register char *p = s + l - 1;

	popquote(s, l);
	assert(strlen(s) == l - 1);

	if (l <= 1)
		return;	/* Length 1 => "" */

	while (p > s)
		if (*--p != ' ')
			break;
	*(p+1) = '\0';
}

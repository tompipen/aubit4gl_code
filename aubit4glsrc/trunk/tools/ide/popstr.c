/*
@(#)File:            $RCSfile: popstr.c,v $
@(#)Version:         $Revision: 1.1.1.1 $
@(#)Last changed:    $Date: 2001-08-20 02:37:08 $
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
static const char rcs[] = "@(#)$Id: popstr.c,v 1.1.1.1 2001-08-20 02:37:08 afalout Exp $";
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

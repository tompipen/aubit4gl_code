/*
@(#)File:            $RCSfile: popstr.c,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-06-20 09:10:42 $
@(#)Purpose:         Pop string and strip trailing blanks
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1988,1990,1998
*/

#include <string.h>
#include <assert.h>

#ifdef FOURJS
	#include "f2c/r_c.h"
#else
	/* fglsys.h is distributed with c-code I4GL. */
	#ifdef I4GL_C4GL
		#include "fglsys.h"
	#endif
#endif

#ifndef lint
	static const char rcs[] = "@(#)$Id: popstr.c,v 1.1 2002-06-20 09:10:42 afalout Exp $";
#endif

#ifdef _NO_LONGER_NEEDED_
/*
popstring() is now redundant in I4GL since popstring() was
added to I4GL 6.0x (where I think x was 0 but it might have been as late as 2)
*/

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

#endif

head	1.3;
access;
symbols;
locks; strict;
comment	@ * @;


1.3
date	98.06.16.21.04.40;	author jleffler;	state Exp;
branches;
next	1.2;

1.2
date	90.04.05.10.51.04;	author john;	state Exp;
branches;
next	1.1;

1.1
date	88.04.20.19.26.40;	author john;	state Exp;
branches;
next	;


desc
@@


1.3
log
@Converted to prototypes and D4GL
@
text
@/*
@@(#)File:            $RCSfile: popstr.c,v $
@@(#)Version:         $Revision: 1.1 $
@@(#)Last changed:    $Date: 2002-06-14 05:03:47 $
@@(#)Purpose:         Pop string and strip trailing blanks
@@(#)Author:          J Leffler
@@(#)Copyright:       (C) JLSS 1988,1990,1998
*/

#include <string.h>
#include <assert.h>

#ifdef FOURJS
#include "f2c/r_c.h"
#else
#include "fglsys.h"
#endif

#ifndef lint
static const char rcs[] = "@@(#)$Id: popstr.c,v 1.1 2002-06-14 05:03:47 afalout Exp $";
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
@


1.2
log
@Revise SCCS ID and tidy a little
@
text
@d2 3
a4 3
@@(#)File:            $RCSfile: popstr.c,v $
@@(#)Version:         $Revision: 1.1 $
@@(#)Last changed:    $Date: 2002-06-14 05:03:47 $
d7 1
d10 8
a17 1
/* -- Declarations		*/
d20 1
a20 1
static	char	sccs[] = "@@(#)$Id: popstr.c,v 1.1 2002-06-14 05:03:47 afalout Exp $";
d25 1
a25 3
void	popstring(s, l)
char	*s;		/* InOut: String to be stripped */
int		 l;		/* In:    Length of string      */
d29 2
a30 1
	popquote(s,l);
@


1.1
log
@Initial revision
@
text
@d2 5
a6 5
@@(#)	File:			$RCSfile: popstr.c,v $
@@(#)	Version:		$Revision: 1.1 $
@@(#)	Last changed:	$Date: 2002-06-14 05:03:47 $
@@(#)	Purpose:		Pop string and strip trailing blanks
@@(#)	Author:			J Leffler
a17 1

a19 4

/*
	Purpose:	Pop string and strip trailing blanks
*/
@

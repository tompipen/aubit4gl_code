head	1.2;
access;
symbols;
locks; strict;
comment	@ * @;


1.2
date	91.05.09.18.10.14;	author johnl;	state Exp;
branches;
next	1.1;

1.1
date	91.05.09.15.34.49;	author johnl;	state Exp;
branches;
next	;


desc
@@


1.2
log
@Upgrade
@
text
@/*
@@(#)	File:			$RCSfile: ljust.c,v $
@@(#)	Version:		$Revision: 1.1 $
@@(#)	Last changed:	$Date: 2002-06-14 05:03:46 $
@@(#)	Purpose:		I4GL: Left justify string
@@(#)	Author:			J Leffler
*/

#ifndef lint
static char sccs[] = "@@(#)$Id: ljust.c,v 1.1 2002-06-14 05:03:46 afalout Exp $";
#endif

/* ljust: left justify string */
/* I4GL: LET s = ljust(s) */

int	ljust(i)
int	i;
{
	char	        s[512];
	register char	*p;

	popstring(s, sizeof(s));
	p = s;
	while (*p == ' ' || *p == '\t')
		p++;

	retquote(p);
	return(1);
}
@


1.1
log
@Initial revision
@
text
@d9 4
@

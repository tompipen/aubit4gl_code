head	1.1;
access;
symbols;
locks; strict;
comment	@ * @;


1.1
date	88.04.20.19.26.40;	author john;	state Exp;
branches;
next	;


desc
@@


1.1
log
@Initial revision
@
text
@/*
@@(#)	File:			$RCSfile: popstr.c,v $
@@(#)	Version:		$Revision: 1.1 $
@@(#)	Last changed:	$Date: 2002-06-14 05:03:46 $
@@(#)	Purpose:		Pop string and strip trailing blanks
@@(#)	Author:			J Leffler
*/

/* -- Declarations		*/

#ifndef lint
static	char	sccs[] = "@@(#)$Id: popstr.c,v 1.1 2002-06-14 05:03:46 afalout Exp $";
#endif

/* -- Routine: popstring		*/

void	popstring(s, l)

char	*s;		/* InOut: String to be stripped */
int		 l;		/* In:    Length of string      */

/*
	Purpose:	Pop string and strip trailing blanks
*/
{
	register char *p = s + l - 1;

	popquote(s,l);

	if (l <= 1)
		return;	/* Length 1 => "" */

	while (p > s)
		if (*--p != ' ')
			break;
	*(p+1) = '\0';
}
@

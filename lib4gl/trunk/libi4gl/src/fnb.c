head	1.2;
access;
symbols;
locks; strict;
comment	@ * @;


1.2
date	91.05.09.18.11.53;	author johnl;	state Exp;
branches;
next	1.1;

1.1
date	88.04.26.11.01.32;	author john;	state Exp;
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
@@(#)	File:			$RCSfile: fnb.c,v $
@@(#)	Version:		$Revision: 1.1 $
@@(#)	Last changed:	$Date: 2002-06-14 05:03:46 $
@@(#)	Purpose:		I4GL: Return first non-blank character in string
@@(#)	Author:			J Leffler
*/

#ifndef lint
static char sccs[] = "@@(#)$Id: fnb.c,v 1.1 2002-06-14 05:03:46 afalout Exp $";
#endif

/* fnb: return first non-blank character in string */
/* I4GL: LET c = fnb(s) */

int	fnb(i)
int	i;
{
	char	s[256];
	char	*p;

	if (i == 1)
	{
		popstring(s, sizeof(s));
		p = s;
		while (*p)
		{
			if (*p != ' ' && *p !='\t')
			{
				*(p+1) = '\0';
				retquote(p);
				return(1);
			}
		}
	}

	retquote(" ");
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

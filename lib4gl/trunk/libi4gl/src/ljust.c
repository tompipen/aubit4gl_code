/*
@(#)	File:			$RCSfile: ljust.c,v $
@(#)	Version:		$Revision: 1.2 $
@(#)	Last changed:	$Date: 2002-06-14 09:23:16 $
@(#)	Purpose:		I4GL: Left justify string
@(#)	Author:			J Leffler
*/

#ifndef lint
static char sccs[] = "@(#)$Id: ljust.c,v 1.2 2002-06-14 09:23:16 afalout Exp $";
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

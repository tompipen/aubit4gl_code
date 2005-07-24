/*
@(#)	File:			$RCSfile: ljust.c,v $
@(#)	Version:		$Revision: 1.1 $
@(#)	Last changed:	$Date: 2002-06-20 09:10:42 $
@(#)	Purpose:		I4GL: Left justify string
@(#)	Author:			J Leffler
*/

#ifndef lint
static char sccs[] = "@(#)$Id: ljust.c,v 1.1 2002-06-20 09:10:42 afalout Exp $";
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

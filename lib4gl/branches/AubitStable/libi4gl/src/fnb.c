/*
@(#)	File:			$RCSfile: fnb.c,v $
@(#)	Version:		$Revision: 1.2 $
@(#)	Last changed:	$Date: 2002-06-14 09:23:16 $
@(#)	Purpose:		I4GL: Return first non-blank character in string
@(#)	Author:			J Leffler
*/

#ifndef lint
static char sccs[] = "@(#)$Id: fnb.c,v 1.2 2002-06-14 09:23:16 afalout Exp $";
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

/*
@(#)	File:			$RCSfile: remblank.c,v $
@(#)	Version:		$Revision: 1.1.1.1 $
@(#)	Last changed:	$Date: 2002-06-15 05:07:14 $
@(#)	Purpose:		Strip trailing blanks from string
@(#)	Author:			J Leffler
*/

/* -- Declarations		*/

#ifndef lint
static	char	sccs[] = "@(#)$Id: remblank.c,v 1.1.1.1 2002-06-15 05:07:14 afalout Exp $";
#endif

void	strip_blanks(s, l)
char	*s;		/* InOut: String to be stripped */
int		 l;		/* In:    Length of string      */
{
	register char *p = s + l - 1;

	if (l <= 1)
		return;	/* Length 1 => "" */

	while (p > s)
		if (*--p != ' ')
			break;
	*(p+1) = '\0';
}

/*
@(#)File:            $RCSfile: popstr.c,v $
@(#)Version:         $Revision: 1.2 $
@(#)Last changed:    $Date: 2002-06-14 09:23:16 $
@(#)Purpose:         Pop string and strip trailing blanks
@(#)Author:          J Leffler
*/

/* -- Declarations		*/

#ifndef lint
static	char	sccs[] = "@(#)$Id: popstr.c,v 1.2 2002-06-14 09:23:16 afalout Exp $";
#endif

/* -- Routine: popstring		*/

void	popstring(s, l)
char	*s;		/* InOut: String to be stripped */
int		 l;		/* In:    Length of string      */
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

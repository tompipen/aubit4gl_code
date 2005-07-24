/*
@(#)	File:			$RCSfile: editstr.c,v $
@(#)	Version:		$Revision: 1.2 $
@(#)	Last changed:	$Date: 2002-06-14 09:23:16 $
@(#)	Purpose:		I4GL: Globally substitute substring in string
@(#)	Author:			J Leffler
*/

/* edit_string: globally substitute for a substring in a string */
/* I4GL: LET new_string = edit_string(old_string, sub, rep) */

int	edit_string(i)
int	i;
{
	char	old[512];
	char	new[512];
	char	sub[32];
	char	rep[32];
	char	*src;
	char	*dst;
	char	*s;
	char	*t;
	int		l_rep;
	int		l_sub;
	extern char	*strpat();
	extern char	*strn_cat();

	if (i != 3)
	{
		retquote("");
		return(1);
	}
	popstring(rep, sizeof(rep));
	popstring(sub, sizeof(sub));
	popstring(old, sizeof(old));
	dst = new;
	src = old;
	l_sub = strlen(sub);

	*dst = '\0';
	while ((s = strpat(src, sub)) != 0)
	{
		dst = strn_cat(dst, src, s-src+1);
		dst = strn_cat(dst, rep);
		src = s + l_sub;
	}
	(void)strn_cat(dst, src, sizeof(new));	/* tack on tail string */

	retquote(new);
	return(1);
}

static	char	*strn_cat(d, s, n)
register char	*d;		/* Out: string to be appended to */
register char	*s;		/* In:  string to append */
register int	 n;		/* In:  maximum characters to copy */
{
	while (*d)
		d++;
	while (*s && --n > 0)
		*d++ = *s++;
	*d = '\0';
	return(d);
}

static	char	*strpat(s, p)
register char	*s;		/* In: string to search */
register char	*p;		/* In: string to search for */
{
	char	*t;
	register char c;
	char *u;

	c = *p;
	while (*s)
	{
		if (*s == c)
		{
			t = s;
			u = p;
			while (*u && *u++ == *t++)
				;
			if (*u == '\0')
				return(s);	/* match found */
		}
		s++;
	}
	return(0); /* no match */
}

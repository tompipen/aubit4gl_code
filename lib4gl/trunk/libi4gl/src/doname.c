/*
@(#)	File:			$RCSfile: doname.c,v $
@(#)	Version:		$Revision: 1.2 $
@(#)	Last changed:	$Date: 2002-06-14 09:23:16 $
@(#)	Purpose:		I4GL: Ensure name does not contain periods
@(#)	Author:			J Leffler
*/

/* doname: ensure name does not contain periods */
/* I4GL: LET name = doname() */

int doname(i)
int	i;
{
	char	s[512];
	char	t[512];
	char	*src, *dst, *end;

	if (i != 1)
	{
		retquote("");
		return(1);
	}

	popquote(s, sizeof(s));
	src=s;
	dst=t;
	while (*src)
	{
		if (*src == '.')
		{
			if (*(src+1) != ' ')
				*dst++ = ' ';
			src++;
		}
		else
			*dst++ = *src++;
	}
	*dst = '\0';
	retquote(t);
	return(1);
}

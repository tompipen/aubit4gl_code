head	1.1;
access;
symbols;
locks; strict;
comment	@ * @;


1.1
date	88.04.19.12.44.54;	author john;	state Exp;
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
@@(#)	File:			$RCSfile: doname.c,v $
@@(#)	Version:		$Revision: 1.1 $
@@(#)	Last changed:	$Date: 2002-06-14 05:03:46 $
@@(#)	Purpose:		I4GL: Ensure name does not contain periods
@@(#)	Author:			J Leffler
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
@

head	1.1;
access;
symbols;
locks; strict;
comment	@ * @;


1.1
date	91.06.27.09.30.50;	author johnl;	state Exp;
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
@@(#)File:            $RCSfile: fstring.c,v $
@@(#)Version:         $Revision: 1.1 $
@@(#)Last changed:    $Date: 2002-06-14 05:03:46 $
@@(#)Purpose:         Find start of one string in another
@@(#)Author:          J Leffler
*/

#define I4GL_C

extern char *strstr();

#ifndef lint
static	char	sccs[] = "@@(#)$Id: fstring.c,v 1.1 2002-06-14 05:03:46 afalout Exp $";
#endif

I4GL_C	find_string(n)
int		n;
{
	char	buffer1[513];
	char	buffer2[513];

	if (n != 2)
		retint(0);
	else
	{
		popstring(buffer2, sizeof(buffer2));
		popstring(buffer1, sizeof(buffer1));
		cp = strstr(buffer1, buffer2);
		if (cp == (char *)0)
			retint(0);
		else
			retint(cp - buffer1 + 1);
	}
	return(1);
}
@

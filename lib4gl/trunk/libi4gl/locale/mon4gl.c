/*
@(#)File:            $RCSfile: mon4gl.c,v $
@(#)Version:         $Revision: 1.2 $
@(#)Last changed:    $Date: 2002-06-14 09:23:16 $
@(#)Purpose:         I4GL interface to monetary format routines
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1991
*/

/*TABSTOP=4*/

#include "monfmt.h"

#define I4GL_C		/* I4GL calling interface */

#ifndef lint
static char     sccs[] = "@(#)$Id: mon4gl.c,v 1.2 2002-06-14 09:23:16 afalout Exp $";
#endif

I4GL_C	i4gl_fmt_money(n)
int			n;
{
	char		buffer[80];
	double		value;
	int			fmtcode;

	if (n == 2)
	{
		popint(&fmtcode);
		popdub(&value);
		fmt_money(buffer, sizeof(buffer), value, fmtcode);
		retquote(buffer);
	}
	else
		retquote("");
	return(1);
}

/*ARGSUSED*/
I4GL_C	i4gl_get_locale(n)
int		n;
{
	retquote(get_monlocale());
	return(1);
}

I4GL_C	i4gl_set_locale(n)
int		n;
{
	char	name[19];

	if (n == 1)
	{
		popstring(name, sizeof(name));
		retint(set_monlocale(name));
	}
	else
		retint(-1318);		/* Parameter count mismatch */
	return(1);
}

head	1.1;
access;
symbols;
locks; strict;
comment	@ * @;


1.1
date	88.03.01.18.18.13;	author john;	state Exp;
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
@@(#)	File:			$RCSfile: decformat.c,v $
@@(#)	Version:		$Revision: 1.1 $
@@(#)	Last changed:	$Date: 2002-06-14 05:03:46 $
@@(#)	Purpose:		Convert DECIMAL/FLOAT/SMALLFLOAT to string
@@(#)	Author:			J Leffler
*/

/*
	Call from I4GL:
	DEFINE s CHAR(30), value DECIMAL {or FLOAT}

	LET s = decformat("%13.6e", value)
*/

decformat(i)
int	i;
{
	double	d;
	char	str[32];
	char	fmt[32];

	if (i != 2)
	{
		retquote("");
		return(1);
	}

	popdub(&d);
	popquote(fmt, 30);
	sprintf(str, fmt, d);
	str[31] = '\0';
	retquote(str);
	return(1);
}
@

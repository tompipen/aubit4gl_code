/*
@(#)	File:			$RCSfile: decformat.c,v $
@(#)	Version:		$Revision: 1.2 $
@(#)	Last changed:	$Date: 2002-06-14 09:23:16 $
@(#)	Purpose:		Convert DECIMAL/FLOAT/SMALLFLOAT to string
@(#)	Author:			J Leffler
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

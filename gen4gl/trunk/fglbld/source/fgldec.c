/*
@(#)File:            $RCSfile: fgldec.c,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-06-20 09:10:42 $
@(#)Purpose:         I4GL Interface to routines DECFIX, DECSCI, and DECENG
@(#)Author:          J Leffler
*/

#include <decimal.h>

extern char	*deceng();
extern char	*decfix();
extern char	*decsci();

#ifndef lint
static	char	sccs[] = "@(#)$Id: fgldec.c,v 1.1 2002-06-20 09:10:42 afalout Exp $";
#endif

int	fgldecfix(i)
int		i;
{
	dec_t	d;
	int		n;
	int		p;

	if (i != 3)
		retquote("");
	else
	{
		popint(&p);
		popint(&n);
		popdec(&d);
		retquote(decfix(&d, n, p));
	}
	return(1);
}


int	fgldeceng(i)
int		i;
{
	dec_t	d;
	int		n;
	int		p;
	int		c;

	if (i != 4)
		retquote("");
	else
	{
		popint(&c);
		popint(&p);
		popint(&n);
		popdec(&d);
		retquote(deceng(&d, n, p, c));
	}
	return(1);
}


int	fgldecsci(i)
int		i;
{
	dec_t	d;
	int		n;
	int		p;

	if (i != 3)
		retquote("");
	else
	{
		popint(&p);
		popint(&n);
		popdec(&d);
		retquote(decsci(&d, n, p));
	}
	return(1);
}


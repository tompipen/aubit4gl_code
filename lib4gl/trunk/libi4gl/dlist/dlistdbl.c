/*
	@(#)$Id: dlistdbl.c,v 1.2 2002-06-14 09:23:16 afalout Exp $
	@(#)C code to maintain multiple D-lists of arbitrary data
	@(#)I4GL interface code -- SQL FLOAT/SMALLFLOAT types
*/

#include "dlist.h"

#if !defined(lint)
static	char	sccs[] = "@(#)$Id: dlistdbl.c,v 1.2 2002-06-14 09:23:16 afalout Exp $";
#endif

#define I4GL_C		/* Informix-4GL interface routine */

/* Create new D-list (nominally of doubles) */
I4GL_C	int	sc_mkdbl(n)
int	n;
{
	int	retval;

	if (n != 0)
	{
		sc_error = EINVARG;
		retval = sc_error;
	}
	else
		retval = mk_key();
	retint(retval);
	return(1);
}

/* Remove list (nominally of doubles) */
I4GL_C	int	sc_rmdbl(n)
int	n;
{
	int	index;

	if (n != 1)
		sc_error = EINVARG;
	else
	{
		popint(&index);
		(void)rm_key(index);
	}
	retint(sc_error);
	return(1);
}

/* Insert new key */
I4GL_C	int	sc_insdbl(n)
int	n;
{
	double	value;
	int		index;

	if (n != 2)
		sc_error = EINVARG;
	else
	{
		popdub(&value);
		popint(&index);
		(void)ins_key(index, (char *)&value, sizeof(double));
	}

	retint(sc_error);
	return(1);
}

/* Update current key */
I4GL_C	int	sc_upddbl(n)
int	n;
{
	double	value;
	int		index;

	if (n != 2)
		sc_error = EINVARG;
	else
	{
		popdub(&value);
		popint(&index);
		(void)upd_key(index, (char *)&value, sizeof(double));
	}
	retint(sc_error);
	return(1);
}

/* Delete current key */
I4GL_C	int	sc_deldbl(n)
int	n;
{
	int		index;

	if (n != 1)
		sc_error = EINVARG;
	else
	{
		popint(&index);
		(void)del_key(index);
	}
	retint(sc_error);
	return(1);
}

/* Get current/next/previous/first/last/absolute/relative key */
I4GL_C	int	sc_getdbl(n)
int	n;
{
	int		index;
	int		offset; 	/* Distance to move */
	char	string[2];	/* Type of move */
	double	*pvalue;	/* Pointer to value */
	double	value;		/* Key found */

	value = 0;

	if (n != 3)
		sc_error = EINVARG;
	else
	{
		popint(&offset);
		popquote(string, 2);
		popint(&index);
		pvalue = (double *)get_key(index, string[0], offset);
		value = (pvalue != NIL(double *)) ? *pvalue : 0.0;
	}
	retint(sc_error);
	retdub(value);
	return(2);
}

/* Delete complete list */
I4GL_C	int	sc_zapdbl(n)
int	n;
{
	int		index;

	if (n != 1)
		sc_error = EINVARG;
	else
	{
		popint(&index);
		(void)zap_key(index);
	}
	retint(sc_error);
	return(1);
}

/* Number of keys in list */
I4GL_C	int	sc_cntdbl(n)
int	n;
{
	int		index;
	int		retval;

	if (n != 1)
	{
		sc_error = EINVARG;
		retval = sc_error;
	}
	else
	{
		popint(&index);
		retval = cnt_key(index);
	}
	retint(retval);
	return(1);
}

/* Number of current key */
I4GL_C	int	sc_numdbl(n)
int	n;
{
	int		index;
	int		retval;

	if (n != 1)
	{
		sc_error = EINVARG;
		retval = sc_error;
	}
	else
	{
		popint(&index);
		retval = num_key(index);
	}
	retint(retval);
	return(1);
}

/*
	@(#)$Id: dlistint.c,v 1.2 2002-06-14 09:23:16 afalout Exp $
	@(#)C code to maintain multiple D-lists of arbitrary data
	@(#)I4GL interface code -- SQL INTEGER/SMALLINT/DATE/SERIAL types
*/

#include "dlist.h"

#if !defined(lint)
static	char	sccs[] = "@(#)$Id: dlistint.c,v 1.2 2002-06-14 09:23:16 afalout Exp $";
#endif

#define I4GL_C		/* Informix-4GL interface routine */

/* Create new D-list (nominally of integers) */
I4GL_C	int	sc_mkint(n)
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

/* Remove list (nominally of integers) */
I4GL_C	int	sc_rmint(n)
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
I4GL_C	int	sc_insint(n)
int	n;
{
	long	value;
	int		index;

	if (n != 2)
		sc_error = EINVARG;
	else
	{
		poplong(&value);
		popint(&index);
		(void)ins_key(index, (char *)&value, sizeof(long));
	}

	retint(sc_error);
	return(1);
}

/* Update current key */
I4GL_C	int	sc_updint(n)
int	n;
{
	long	value;
	int		index;

	if (n != 2)
		sc_error = EINVARG;
	else
	{
		poplong(&value);
		popint(&index);
		(void)upd_key(index, (char *)&value, sizeof(long));
	}
	retint(sc_error);
	return(1);
}

/* Delete current key */
I4GL_C	int	sc_delint(n)
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
I4GL_C	int	sc_getint(n)
int	n;
{
	int		index;
	int		offset; 	/* Distance to move */
	char	string[2];	/* Type of move */
	long	*pvalue;	/* Pointer to value */
	long	value;		/* Key found */

	value = 0;

	if (n != 3)
		sc_error = EINVARG;
	else
	{
		popint(&offset);
		popquote(string, 2);
		popint(&index);
		pvalue = (long *)get_key(index, string[0], offset);
		value = (pvalue != NIL(long *)) ? *pvalue : 0;
	}
	retint(sc_error);
	retlong(value);
	return(2);
}

/* Delete complete list */
I4GL_C	int	sc_zapint(n)
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
I4GL_C	int	sc_cntint(n)
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
I4GL_C	int	sc_numint(n)
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

/*
	@(#)$Id: dlistdec.c,v 1.1 2002-06-20 09:10:42 afalout Exp $
	@(#)C code to maintain multiple D-lists of arbitrary data
	@(#)I4GL interface code -- SQL DECIMAL/MONEY types
*/

#include "dlist.h"
#include <tools/decimal.h>

#if !defined(lint)
static	char	sccs[] = "@(#)$Id: dlistdec.c,v 1.1 2002-06-20 09:10:42 afalout Exp $";
#endif

#define I4GL_C		/* Informix-4GL interface routine */

typedef struct decimal	Decimal;

/* Create new D-list (nominally of decimals) */
I4GL_C	int	sc_mkdec(n)
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

/* Remove list (nominally of decimals) */
I4GL_C	int	sc_rmdec(n)
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
I4GL_C	int	sc_insdec(n)
int	n;
{
	Decimal	value;
	int		index;

	if (n != 2)
		sc_error = EINVARG;
	else
	{
		popdec(&value);
		popint(&index);
		(void)ins_key(index, (char *)&value, sizeof(Decimal));
	}

	retint(sc_error);
	return(1);
}

/* Update current key */
I4GL_C	int	sc_upddec(n)
int	n;
{
	Decimal	value;
	int		index;

	if (n != 2)
		sc_error = EINVARG;
	else
	{
		popdec(&value);
		popint(&index);
		(void)upd_key(index, (char *)&value, sizeof(Decimal));
	}
	retint(sc_error);
	return(1);
}

/* Delete current key */
I4GL_C	int	sc_deldec(n)
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
I4GL_C	int	sc_getdec(n)
int	n;
{
	int		index;
	int		offset; 	/* Distance to move */
	char	string[2];	/* Type of move */
	Decimal	*pvalue;	/* Pointer to value */
	Decimal	value;		/* Key found */

	deccvint(0, &value);

	if (n != 3)
		sc_error = EINVARG;
	else
	{
		popint(&offset);
		popquote(string, 2);
		popint(&index);
		pvalue = (Decimal *)get_key(index, string[0], offset);
		if (pvalue != NIL(Decimal *))
			value = *pvalue;
	}
	retint(sc_error);
	retdec(value);
	return(2);
}

/* Delete complete list */
I4GL_C	int	sc_zapdec(n)
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
I4GL_C	int	sc_cntdec(n)
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
I4GL_C	int	sc_numdec(n)
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

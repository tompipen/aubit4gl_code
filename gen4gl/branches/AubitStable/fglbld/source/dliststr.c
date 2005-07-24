/*
	@(#)$Id: dliststr.c,v 1.1 2002-06-20 09:10:42 afalout Exp $
	@(#)C code to maintain multiple D-lists of arbitrary data
	@(#)I4GL interface code -- SQL CHAR types
*/

#include "dlist.h"

#if !defined(lint)
static	char	sccs[] = "@(#)$Id: dliststr.c,v 1.1 2002-06-20 09:10:42 afalout Exp $";
#endif

#define I4GL_C		/* Informix-4GL interface routine */

/* Long enough for longest I4GL string that could be Primary Key only */
typedef char	String[121];

/* Create new D-list (nominally of strings) */
I4GL_C	int	sc_mkstr(n)
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

/* Remove list (nominally of strings) */
I4GL_C	int	sc_rmstr(n)
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
I4GL_C	int	sc_insstr(n)
int	n;
{
	String	value;
	int		index;

	if (n != 2)
		sc_error = EINVARG;
	else
	{
		popstring(value, sizeof(String));
		popint(&index);
		(void)ins_key(index, (char *)value, strlen(value)+1);
	}

	retint(sc_error);
	return(1);
}

/* Update current key */
I4GL_C	int	sc_updstr(n)
int	n;
{
	String	value;
	int		index;

	if (n != 2)
		sc_error = EINVARG;
	else
	{
		popstring(value, sizeof(String));
		popint(&index);
		(void)upd_key(index, (char *)value, strlen(value)+1);
	}
	retint(sc_error);
	return(1);
}

/* Delete current key */
I4GL_C	int	sc_delstr(n)
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
I4GL_C	int	sc_getstr(n)
int	n;
{
	int		 index;
	int		 offset; 	/* Distance to move */
	char	 string[2];	/* Type of move */
	char	*value;		/* Key found */

	value = "";

	if (n != 3)
		sc_error = EINVARG;
	else
	{
		popint(&offset);
		popquote(string, 2);
		popint(&index);
		value = get_key(index, string[0], offset);
		if (value == NIL(char *))
			value = "";
	}
	retint(sc_error);
	retquote(value);
	return(2);
}

/* Delete complete list */
I4GL_C	int	sc_zapstr(n)
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
I4GL_C	int	sc_cntstr(n)
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
I4GL_C	int	sc_numstr(n)
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

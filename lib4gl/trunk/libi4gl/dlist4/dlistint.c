/*
@(#)	File:			$RCSfile: dlistint.c,v $
@(#)	Version:		$Revision: 1.2 $
@(#)	Last changed:	$Date: 2002-06-14 09:23:16 $
@(#)	Purpose:		I4GL interface to integer D-Lists
@(#)	Author:			J Leffler
*/

/*TABSTOP=4*/

#include "dlist.h"

#define I4GL_C					/* Informix-4GL interface routine */

#if !defined(lint)
static char     sccs[] = "@(#)$Id: dlistint.c,v 1.2 2002-06-14 09:23:16 afalout Exp $";
#endif

/* Create new D-list */
I4GL_C int      sc_create(n)
int             n;
{
	int             retval;

	if (n != 0)
	{
		sc_error = EINVARG;
		retval = sc_error;
	}
	else
		retval = dl_create();
	retint(retval);
	return (1);
}

/* Destroy D-list */
I4GL_C int      sc_destroy(n)
int             n;
{
	int             index;

	if (n != 1)
		sc_error = EINVARG;
	else
	{
		popint(&index);
		(void) dl_destroy(index);
	}
	retint(sc_error);
	return (1);
}

/* Insert new key */
I4GL_C int      sc_insert(n)
int             n;
{
	long            value;
	int             index;

	if (n != 2)
		sc_error = EINVARG;
	else
	{
		poplong(&value);
		popint(&index);
		(void) dl_insert(index, value);
	}

	retint(sc_error);
	return (1);
}

/* Update current key */
I4GL_C int      sc_update(n)
int             n;
{
	long            value;
	int             index;

	if (n != 2)
		sc_error = EINVARG;
	else
	{
		poplong(&value);
		popint(&index);
		(void) dl_update(index, value);
	}
	retint(sc_error);
	return (1);
}

/* Delete current key */
I4GL_C int      sc_delete(n)
int             n;
{
	int             index;

	if (n != 1)
		sc_error = EINVARG;
	else
	{
		popint(&index);
		(void) dl_delete(index);
	}
	retint(sc_error);
	return (1);
}

/* Get current/next/previous/first/last/absolute/relative key */
I4GL_C int      sc_select(n)
int             n;
{
	int             index;
	int             offset;	/* Distance to move */
	char            string[2];	/* Type of move */
	long            value;		/* Key found */

	value = 0;

	if (n != 3)
		sc_error = EINVARG;
	else
	{
		popint(&offset);
		popquote(string, sizeof(string));
		popint(&index);
		value = dl_select(index, string[0], offset);
	}
	retint(sc_error);
	retlong(value);
	return (2);
}

/* Delete complete list */
I4GL_C int      sc_empty(n)
int             n;
{
	int             index;

	if (n != 1)
		sc_error = EINVARG;
	else
	{
		popint(&index);
		(void) dl_empty(index);
	}
	retint(sc_error);
	return (1);
}

/* Number of keys in list */
I4GL_C int      sc_count(n)
int             n;
{
	int             index;
	int             retval;

	if (n != 1)
	{
		sc_error = EINVARG;
		retval = sc_error;
	}
	else
	{
		popint(&index);
		retval = dl_count(index);
	}
	retint(retval);
	return (1);
}

/* Number of current key */
I4GL_C int      sc_index(n)
int             n;
{
	int             index;
	int             retval;

	if (n != 1)
	{
		sc_error = EINVARG;
		retval = sc_error;
	}
	else
	{
		popint(&index);
		retval = dl_index(index);
	}
	retint(retval);
	return (1);
}

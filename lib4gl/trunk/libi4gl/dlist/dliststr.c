/*
	@@(#)$Id: dliststr.c,v 1.1 2002-06-14 05:03:45 afalout Exp $
	@@(#)C code to maintain multiple D-lists of arbitrary data
	@@(#)I4GL interface code -- SQL CHAR types
*/

#include "dlist.h"

#if !defined(lint)
static	char	sccs[] = "@@(#)$Id: dliststr.c,v 1.1 2002-06-14 05:03:45 afalout Exp $";
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
@


3.2
log
@Tidy up some more comments
@
text
@@


3.1
log
@Revise headers; unify discrepant versions
@
text
@d18 1
a18 1
/* Create new list of integers */
d35 1
a35 1
/* Remove list (hopefully of integers) */
@


2.4
log
@Take care not to dereference null pointers!!!
@
text
@d3 2
a4 2
	@@(#)I4GL interface code to maintain doubly-linked list of data and
	@@(#)C code to maintain doubly-linked list of data -- integers
@


2.3
log
@Shut lint up: void some results
@
text
@d127 2
@


2.2
log
@Call the correct functions with the correct string size
@
text
@d65 1
a65 1
		ins_key(index, (char *)value, strlen(value)+1);
d85 1
a85 1
		upd_key(index, (char *)value, strlen(value)+1);
d144 1
a144 1
		zap_key(index);
@


2.1
log
@Convert to new standard
@
text
@d18 1
a18 1
/* Create new l=list of integers */
d63 1
a63 1
		popstr(value, sizeof(String));
d65 1
a65 1
		ins_key(index, (char *)value, strlen(value));
d83 1
a83 1
		popstr(value, sizeof(String));
d85 1
a85 1
		upd_key(index, (char *)value, strlen(value));
d129 1
a129 1
	retstr(value);
@


1.6
log
@Fix the off-by-one error
@
text
@d4 1
a4 1
	@@(#)C code to maintain doubly-linked list of data -- strings
a12 1
/* This version of string handling is bloody clumsy */
a13 7
#define POPKEY(x)	popstring(x, sizeof(keyarg))
#define RETKEY(x)	retquote(x)
#define MAXSTRSIZE	512

typedef	char	*keytype;
typedef	char	 keyarg[MAXSTRSIZE];
typedef	unsigned long	ulong;
d15 2
a16 23
struct	dlist
{
	struct	dlist	*next;
	struct	dlist	*prev;
	keytype			 key;
};
typedef	struct dlist Dlist;

static	Dlist	*head;
static	Dlist	*tail;
static	Dlist	*curr;
static	int		 listlength;
static	int		 initialised;
static	Dlist	 array[2];
static	int		 sc_error;

extern	char	*malloc();
extern	void	 free();

/*
**	Note: curr is null if there is no current row
**	There is a current row unless there are no rows in the list
*/
d18 3
a20 3
/* Automatically initialise Dlist system */
/* Resets sc_error on every call */
static	void	initialise()
d22 1
a22 13
	if (!initialised)
	{
		head = &array[0];
		tail = &array[1];
		head->prev = NIL(Dlist *);
		tail->next = NIL(Dlist *);
		head->next = tail;
		tail->prev = head;
		listlength = 0;
		initialised = 1;
	}
	sc_error = ENOERROR;
}
d24 1
a24 35
/* Add new key */
static	void	ins_key(keyval)
keytype	keyval;
{
	Dlist	*new;
	ulong	 alloc;

	initialise();

	/* Allocate new Dlist item */
	alloc = sizeof(Dlist) + strlen(keyval) + 1;
	if ((new = (Dlist *)malloc(alloc)) == NIL(Dlist *))
	{
		sc_error = ENOMEM;
		return;
	}

	/* Insert new item */
	new->key = ((char *)new) + sizeof(Dlist);
	strcpy(new->key, keyval);

#if defined(INSERT_AT_END)
	new->prev = tail->prev;
	new->next = tail;
	new->prev->next = new;
	tail->prev = new;
#else
	if (listlength <= 0)
	{	/* Empty list */
		new->prev = head;
		new->next = tail;
		head->next = new;
		tail->prev = new;
	}
	else
d26 2
a27 4
		new->prev = curr;
		new->next = curr->next;
		curr->next->prev = new;
		curr->next = new;
a28 14
#endif

	listlength++;
	curr = new;
}

/* Delete current key */
static	void	del_key()
{
	Dlist	*old;

	initialise();
	if (listlength <= 0)
		sc_error = ENOLIST;
d30 3
a32 14
	{
		old = curr;
		curr->prev->next = curr->next;
		curr->next->prev = curr->prev;
		listlength--;
		if (curr->next != tail)
			curr = curr->next;
		else if (curr->prev != head)
			curr = curr->prev;
		else
			curr = NIL(Dlist *);

		free((char *)old);
	}
d35 3
a37 4
/* Update current key */
/* Note delete then insert because length may vary */
static	void	upd_key(keyval)
keytype	keyval;
d39 1
a39 1
	initialise();
d41 2
a42 2
	if (listlength <= 0)
		sc_error = ENOLIST;
d45 2
a46 2
		del_key();
		ins_key(keyval);
d48 2
d52 1
a52 119
/* Get current/next/previous/first/last/relative/absolute key */
static	keytype	get_key(flag, offset)
int		flag;	/* Type of move */
int		offset; /* Distance to move */
{
	int	i;

	initialise();

	if (listlength <= 0)
	{
		sc_error = ENOLIST;
		return("");
	}

	/* SC_RELATIVE gets mapped into NEXT, PREVIOUS or CURRENT */
	if (flag == SC_RELATIVE)
	{
		if (offset == 0)
			flag = SC_CURRENT;
		else if (offset > 0)
			flag = SC_NEXT;
		else
		{
			flag = SC_PREVIOUS;
			offset = -offset;
		}
	}

	/* Only non-negative offsets */
	if (offset < 0 || (flag == SC_ABSOLUTE && offset == 0))
	{
		sc_error = EINVARG;
		return("");
	}
	if (offset == 0)
		offset++;

	/* Absolute maps into SC_NEXT from first */
	if (flag == SC_ABSOLUTE)
	{
		flag = SC_NEXT;
		curr = head->next;
		offset--;
	}

	/* Find relevant row -- overshoot is not an error */
	switch (flag)
	{
	case SC_CURRENT:
		/* curr = curr; */
		break;
	case SC_FIRST:
		curr = head->next;
		break;
	case SC_LAST:
		curr = tail->prev;
		break;
	case SC_NEXT:
		for (i = 0; i < offset; i++)
		{
			if (curr->next == tail)
				break;
			curr = curr->next;
		}
		break;
	case SC_PREVIOUS:
		for (i = 0; i < offset; i++)
		{
			if (curr->prev == head)
				break;
			curr = curr->prev;
		}
		break;
	}

	return(curr->key);
}

/* Delete complete list */
static	void	del_all()
{
	Dlist	*old;

	initialise();

	curr = head->next;
	while (curr != tail)
	{
		old = curr;
		curr = curr->next;
		free((char *)old);
	}
	listlength = 0;
	initialised = 0;
}

/* Number of keys in list */
static	int	cnt_key()
{
	return(listlength);
}

/* Number of current key */
static	int	key_num()
{
	Dlist	*p;
	int		 i;

	i = 0;
	if (listlength > 0)
	{
		for (p = head->next, i = 1; p != curr; p = p->next)
			i++;
	}
	return(i);
}

/* Add new key */

/*
d56 2
a57 1
	keyarg	keyval;
d59 1
a59 1
	if (n != 1)
d63 3
a65 2
		POPKEY(keyval);
		ins_key(keyval);
d76 2
a77 1
	keyarg	keyval;
d79 1
a79 1
	if (n != 1)
d83 3
a85 2
		POPKEY(keyval);
		upd_key(keyval);
d95 3
a97 1
	if (n != 0)
d100 4
a103 1
		del_key();
d112 4
a115 4
	int		offset; */	/* Distance to move */
/*	char	string[2];*/	/* Type of move */
/*	keytype	keyval;		*//* Key found */
/*
d117 1
a117 1
	keyval = "";
d119 1
a119 1
	if (n != 2)
d125 2
a126 1
		keyval = get_key(string[0], offset);
d129 1
a129 1
	RETKEY(keyval);
d137 3
a139 1
	if (n != 0)
d142 4
a145 1
		del_all();
d154 14
a167 1
	retint(cnt_key());
d172 1
a172 1
I4GL_C	int	sc_keystr(n)
d175 14
a188 1
	retint(key_num());
a190 1

@


1.5
log
@Correct bug in key_num -- now goes to current row, not end
@
text
@d265 1
a265 3
		p = head->next;
		while (p != curr)
		{
a266 2
			p = p->next;
		}
@


1.4
log
@Apparently operational
@
text
@d263 1
a263 2
	p = head->next;
	while (p != tail)
d265 6
a270 2
		i++;
		p = p->next;
@


1.3
log
@Rename I4GL sc_key_num
@
text
@a157 1
	static	keytype	keyval;*/	/* Must be static for character strings */
/*
a161 2
	strcpy(keyval, "");

d165 1
a165 1
		return(keyval);
d186 1
a186 1
		return(keyval);
d229 1
a229 2
	strncpy(keyval, curr->key, sizeof(keytype));
	return(keyval);
@


1.2
log
@Systematically rename I4GL interface
@
text
@d368 1
a368 1
I4GL_C	int	sc_key_num(n)
@


1.1
log
@Initial revision
@
text
@d277 1
a277 1
I4GL_C	int	sc_ins_key(n)
d295 1
a295 1
I4GL_C	int	sc_upd_key(n)
d312 1
a312 1
I4GL_C	int	sc_del_key(n)
d324 1
a324 1
I4GL_C	int	sc_get_key(n)
d348 1
a348 1
I4GL_C	int	sc_del_all(n)
d360 1
a360 1
I4GL_C	int	sc_cnt_key(n)
@

*/

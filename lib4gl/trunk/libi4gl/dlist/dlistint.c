/*
	@@(#)$Id: dlistint.c,v 1.1 2002-06-14 05:03:45 afalout Exp $
	@@(#)C code to maintain multiple D-lists of arbitrary data
	@@(#)I4GL interface code -- SQL INTEGER/SMALLINT/DATE/SERIAL types
*/

#include "dlist.h"

#if !defined(lint)
static	char	sccs[] = "@@(#)$Id: dlistint.c,v 1.1 2002-06-14 05:03:45 afalout Exp $";
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
@d15 1
a15 1
/* Create new l=list of integers */
d32 1
a32 1
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
@d112 1
d124 2
a125 1
		value = *(long *)get_key(index, string[0], offset);
@


2.2
log
@Change count routine
@
text
@d62 1
a62 1
		ins_key(index, (char *)&value, sizeof(long));
d82 1
a82 1
		upd_key(index, (char *)&value, sizeof(long));
d141 1
a141 1
		zap_key(index);
@


2.1
log
@Remove generic material; add sc_mkint and sc_rmint
@
text
@d169 1
a169 1
I4GL_C	int	sc_keyint(n)
@


1.5
log
@Fix the off-by-one error
@
text
@a13 2
#define POPKEY(x)	poplong(&x)
#define RETKEY(x)	retlong(x)
d15 3
a17 4
typedef	long	keytype;
typedef	long	keyret;

struct	dlist
d19 1
a19 39
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

/* Automatically initialise Dlist system */
/* Resets sc_error on every call */
static	void	initialise()
{
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
d21 1
a21 10
/* Add new item with key value at end of list */
static	void	ins_key(value)
keytype	value;
{
	Dlist	*new;

	initialise();

	/* Allocate new Dlist item */
	if ((new = (Dlist *)malloc(sizeof(Dlist))) == NIL(Dlist *))
d23 2
a24 19
		sc_error = ENOMEM;
		return;
	}

	/* Insert new item */
	new->key = value;

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
d27 3
a29 10
	{
		new->prev = curr;
		new->next = curr->next;
		curr->next->prev = new;
		curr->next = new;
	}
#endif

	listlength++;
	curr = new;
d32 3
a34 3
/* Update current key */
static	void	upd_key(value)
keytype	value;
d36 1
a36 1
	initialise();
d38 2
a39 14
	if (listlength <= 0)
		sc_error = ENOLIST;
	else
		curr->key = value;
}

/* Delete current key */
static	void	del_key()
{
	Dlist	*old;

	initialise();
	if (listlength <= 0)
		sc_error = ENOLIST;
d42 2
a43 12
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
d45 2
d49 1
a49 123
/* Get current/next/previous/first/last/relative/absolute key */
static	keyret	get_key(flag, offset)
int		flag;	/* Type of move */
int		offset; /* Distance to move */
{
	static	keytype	keyval;	/* Must be static for character strings */
	int	i;

	initialise();

	keyval = 0;

	if (listlength <= 0)
	{
		sc_error = ENOLIST;
		return(keyval);
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
		return(keyval);
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

	keyval = curr->key;
	return(keyval);
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

/* Add new item with key value at end of list */

/*
d53 2
a54 1
	keytype	value;
d56 1
a56 1
	if (n != 1)
d60 3
a62 2
		POPKEY(value);
		ins_key(value);
d73 2
a74 1
	keytype	value;
d76 1
a76 1
	if (n != 1)
d80 3
a82 2
		POPKEY(value);
		upd_key(value);
d92 3
a94 1
	if (n != 0)
d97 4
a100 1
		del_key();
d109 1
d112 1
a112 1
	keytype	value;	*/	/* Key found */
/*
d116 1
a116 1
	if (n != 2)
d122 2
a123 1
		value = get_key(string[0], offset);
d126 1
a126 1
	RETKEY(value);
d134 3
a136 1
	if (n != 0)
d139 4
a142 1
		del_all();
d151 14
a164 1
	retint(cnt_key());
d172 14
a185 1
	retint(key_num());
@


1.4
log
@Correct bug in key_num -- now goes to current row, not end
@
text
@d259 1
a259 3
		p = head->next;
		while (p != curr)
		{
a260 2
			p = p->next;
		}
@


1.3
log
@Rename I4GL sc_key_num
@
text
@d257 1
a257 2
	p = head->next;
	while (p != tail)
d259 6
a264 2
		i++;
		p = p->next;
@


1.2
log
@Systematically rename I4GL interface
@
text
@d357 1
a357 1
I4GL_C	int	sc_key_num(n)
@


1.1
log
@Initial revision
@
text
@d267 1
a267 1
I4GL_C	int	sc_ins_key(n)
d285 1
a285 1
I4GL_C	int	sc_upd_key(n)
d302 1
a302 1
I4GL_C	int	sc_del_key(n)
d314 1
a314 1
I4GL_C	int	sc_get_key(n)
d337 1
a337 1
I4GL_C	int	sc_del_all(n)
d349 1
a349 1
I4GL_C	int	sc_cnt_key(n)
@

*/
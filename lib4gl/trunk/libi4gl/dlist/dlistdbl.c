/*
	@@(#)$Id: dlistdbl.c,v 1.1 2002-06-14 05:03:45 afalout Exp $
	@@(#)C code to maintain multiple D-lists of arbitrary data
	@@(#)I4GL interface code -- SQL FLOAT/SMALLFLOAT types
*/

#include "dlist.h"

#if !defined(lint)
static	char	sccs[] = "@@(#)$Id: dlistdbl.c,v 1.1 2002-06-14 05:03:45 afalout Exp $";
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
/* Remove list (hopefully of doubles) */
@


2.3
log
@Take care not to dereference null pointers!!!
@
text
@d3 2
a4 2
	@@(#)I4GL interface code to maintain doubly-linked list of data and
	@@(#)C code to maintain doubly-linked list of data -- integers
@


2.2
log
@Shut lint up: void some results
@
text
@d112 1
d124 2
a125 1
		value = *(double *)get_key(index, string[0], offset);
@


2.1
log
@Convert to new standard
@
text
@d62 1
a62 1
		ins_key(index, (char *)&value, sizeof(double));
d82 1
a82 1
		upd_key(index, (char *)&value, sizeof(double));
d141 1
a141 1
		zap_key(index);
@


1.5
log
@Fix the off-by-one error
@
text
@d4 1
a4 1
	@@(#)C code to maintain doubly-linked list of data -- double & float
a13 2
#define POPKEY(x)	popdub(&x)
#define RETKEY(x)	retdub(&x)
d15 3
a17 3
typedef	double	keytype;

struct	dlist
d19 1
a19 21
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
d21 1
a21 5
/* Automatically initialise Dlist system */
/* Resets sc_error on every call */
static	void	initialise()
{
	if (!initialised)
d23 2
a24 42
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

/* Add new key */
static	void	ins_key(keyval)
keytype	keyval;
{
	Dlist	*new;

	initialise();

	/* Allocate new Dlist item */
	if ((new = (Dlist *)malloc(sizeof(Dlist))) == NIL(Dlist *))
	{
		sc_error = ENOMEM;
		return;
	}

	/* Insert new item */
	new->key = keyval;

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
static	void	upd_key(keyval)
keytype	keyval;
d36 1
a36 1
	initialise();
d38 2
a39 14
	if (listlength <= 0)
		sc_error = ENOLIST;
	else
		curr->key = keyval;
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
static	keytype	get_key(flag, offset)
int		flag;	/* Type of move */
int		offset; /* Distance to move */
{
	static	keytype	keyval;	/* Must be static for character strings */
	int	i;

	initialise();

	keyval = 0.0;

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

/* Add new key */
d53 2
a54 1
	keytype	keyval;
d56 1
a56 1
	if (n != 1)
d60 3
a62 2
		POPKEY(keyval);
		ins_key(keyval);
d73 2
a74 1
	keytype	keyval;
d76 1
a76 1
	if (n != 1)
d80 3
a82 2
		POPKEY(keyval);
		upd_key(keyval);
d92 3
a94 1
	if (n != 0)
d97 4
a100 1
		del_key();
d109 1
d112 1
a112 1
	keytype	keyval;		/* Key found */
d114 1
a114 1
	keyval = 0.0;
d116 1
a116 1
	if (n != 2)
d122 2
a123 1
		keyval = get_key(string[0], offset);
d126 1
a126 1
	RETKEY(keyval);
d134 3
a136 1
	if (n != 0)
d139 4
a142 1
		del_all();
d151 14
a164 1
	retint(cnt_key());
d169 1
a169 1
I4GL_C	int	sc_keydbl(n)
d172 14
a185 1
	retint(key_num());
@


1.4
log
@Correct bug in key_num -- now goes to current row, not end
@
text
@d258 1
a258 3
		p = head->next;
		while (p != curr)
		{
a259 2
			p = p->next;
		}
@


1.3
log
@Rename I4GL sc_key_num
@
text
@d256 1
a256 2
	p = head->next;
	while (p != tail)
d258 6
a263 2
		i++;
		p = p->next;
@


1.2
log
@Systematically rename I4GL interface
@
text
@d356 1
a356 1
I4GL_C	int	sc_key_num(n)
@


1.1
log
@Initial revision
@
text
@d266 1
a266 1
I4GL_C	int	sc_ins_key(n)
d284 1
a284 1
I4GL_C	int	sc_upd_key(n)
d301 1
a301 1
I4GL_C	int	sc_del_key(n)
d313 1
a313 1
I4GL_C	int	sc_get_key(n)
d336 1
a336 1
I4GL_C	int	sc_del_all(n)
d348 1
a348 1
I4GL_C	int	sc_cnt_key(n)
@

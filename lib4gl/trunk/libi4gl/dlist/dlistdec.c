/*
	@@(#)$Id: dlistdec.c,v 1.1 2002-06-14 05:03:45 afalout Exp $
	@@(#)C code to maintain multiple D-lists of arbitrary data
	@@(#)I4GL interface code -- SQL DECIMAL/MONEY types
*/

#include "dlist.h"
#include <decimal.h>

#if !defined(lint)
static	char	sccs[] = "@@(#)$Id: dlistdec.c,v 1.1 2002-06-14 05:03:45 afalout Exp $";
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


/*


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
a18 1 */
/* Create new l=list of integers */
/* d35 1
a35 1 */
/* Remove list (hopefully of integers) */
/*
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
@d115 1
d127 3
a129 1
		value = *(Decimal *)get_key(index, string[0], offset);
@


2.1
log
@Convert to new standard
@
text
@d65 1
a65 1
		ins_key(index, (char *)&value, sizeof(Decimal));
d85 1
a85 1
		upd_key(index, (char *)&value, sizeof(Decimal));
d144 1
a144 1
		zap_key(index);
@


1.5
log
@Fix the off-by-one error
@
text
@d4 1
a4 1
	@@(#)C code to maintain doubly-linked list of data -- decimal & money
d8 1
a8 1
#include "decimal.h"
a14 2
#define POPKEY(x)	popdec(&x)
#define RETKEY(x)	retdec(&x)
d16 1
a16 2
typedef	dec_t	keytype;
typedef	dec_t	keyret;
d18 3
a20 1
struct	dlist
d22 1
a22 21
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
*/
/*
**	Note: curr is null if there is no current row
**	There is a current row unless there are no rows in the list
*/

/* Automatically initialise Dlist system */
/* Resets sc_error on every call */

static	void	initialise()
{
	if (!initialised)
d26 2
a27 42
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

/* Add new item with key value at end of list */
static	void	ins_key(value)
keytype	value;
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
/*
d30 3
a32 10
	{
		new->prev = curr;
		new->next = curr->next;
		curr->next->prev = new;
		curr->next = new;
	}
#endif

	listlength++;
	curr = new;
*/
/* Update current key */
/*
static	void	upd_key(value)
keytype	value;
d39 1
a39 1
	initialise();
d41 2
a42 14
	if (listlength <= 0)
		sc_error = ENOLIST;
	else
		curr->key = value;
}
*/
/* Delete current key */
/*
static	void	del_key()
{
	Dlist	*old;

	initialise();
	if (listlength <= 0)
		sc_error = ENOLIST;
d45 2
a46 12
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
d48 2
d52 1
a52 123
*/
/* Get current/next/previous/first/last/relative/absolute key */
static	keyret	get_key(flag, offset)
int		flag;	/* Type of move */
int		offset; /* Distance to move */
{
	static	keytype	keyval;	/* Must be static for character strings */
	int	i;

	initialise();

	deccvint(0, &keyval);

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
d56 2
a57 1
	keytype	value;
d59 1
a59 1
	if (n != 1)
d63 3
a65 2
		POPKEY(value);
		ins_key(value);
d76 2
a77 1
	keytype	value;
d79 1
a79 1
	if (n != 1)
d83 3
a85 2
		POPKEY(value);
		upd_key(value);
d95 3
a97 1
	if (n != 0)
d100 4
a103 1
		del_key();
d112 1
d115 1
a115 1
	keytype	value;	*/	/* Key found */
/*
d119 1
a119 1
	if (n != 2)
d125 2
a126 1
		value = get_key(string[0], offset);
d129 1
a129 1
	RETKEY(value);
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
I4GL_C	int	sc_keydec(n)
d175 14
a188 1
	retint(key_num());
@


1.4
log
@Correct bug in key_num -- now goes to current row, not end
@
text
@d260 1
a260 3
		p = head->next;
		while (p != curr)
		{
a261 2
			p = p->next;
		}
@


1.3
log
@Rename I4GL sc_key_num
@
text
@d258 1
a258 2
	p = head->next;
	while (p != tail)
d260 6
a265 2
		i++;
		p = p->next;
@


1.2
log
@Systematically rename I4GL interface
@
text
@d358 1
a358 1
I4GL_C	int	sc_key_num(n)
@


1.1
log
@Initial revision
@
text
@d268 1
a268 1
I4GL_C	int	sc_ins_key(n)
d286 1
a286 1
I4GL_C	int	sc_upd_key(n)
d303 1
a303 1
I4GL_C	int	sc_del_key(n)
d315 1
a315 1
I4GL_C	int	sc_get_key(n)
d338 1
a338 1
I4GL_C	int	sc_del_all(n)
d350 1
a350 1
I4GL_C	int	sc_cnt_key(n)
@
*/

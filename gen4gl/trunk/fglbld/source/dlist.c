/*
@(#)	File:			$RCSfile: dlist.c,v $
@(#)	Version:		$Revision: 1.1 $
@(#)	Last changed:	$Date: 2002-06-20 09:10:42 $
@(#)	Purpose:		Maintain multiple D-lists of arbitrary data
@(#)	Author:			J Leffler
*/

/* -- Configuration        */

/* #define FIXEDALLOCATION to use a fixed number of lists */
/* #define VARIABLEALLOCATION to use a variable number of lists */
/* #define PARANOID to scrutinise each dlist before each use */

#if defined(FIXEDALLOCATION) && defined(VARIABLEALLOCATION)
#undef FIXEDALLOCATION
#endif

#if !defined(FIXEDALLOCATION) && !defined(VARIABLEALLOCATION)
#define VARIABLEALLOCATION
#endif

/* -- Include Files        */

#include "dlist.h"
#if defined(PARANOID)
#include <stdio.h>
#endif

/* -- Constant Definitions */

#define GLOBAL
#if defined(FIXEDALLOCATION) && !defined(MAXDLIST)
#define MAXDLIST	30
#endif

/* -- Type Definitions     */

struct	ditem
{
	struct	ditem	*next;
	struct	ditem	*prev;
	char	*key;
	int		 len;
};
typedef	struct ditem Ditem;

struct	dlist
{
	Ditem	*head;
	Ditem	*curr;
	int		 listlength;
	Ditem	 item;
	int		 inuse;
};
typedef	struct dlist Dlist;
typedef	unsigned long	ulong;

/* -- Declarations         */

#if !defined(lint)
static	char	sccs[] = "@(#)$Id: dlist.c,v 1.1 2002-06-20 09:10:42 afalout Exp $";
#endif

#if defined(FIXEDALLOCATION)
static	Dlist	 master[MAXDLIST];
static	int		 nalloc = MAXDLIST;
#endif

#if defined(VARIABLEALLOCATION)
static	Dlist	*master = NIL(Dlist *);
static	int		 nalloc = 0;
extern	char	*malloc();
extern	Dlist	*dalloc();
extern	void	 free();
#endif

GLOBAL	int		 sc_error;
static	int		 nused  = 0;
static	Dlist	*d = NIL(Dlist *);

/* Initialise new or emptied list */
static	void	initialise(index)
int		index;
{
	Dlist	*dp = &master[index-1];

	dp->head = &dp->item;
	dp->curr = dp->head;
	dp->head->next = dp->head;
	dp->head->prev = dp->head;
	dp->listlength = 0;
}

/* Check that list is valid, reset sc_error, set d */
static	int	check(index)
int			index;
{

#ifdef PARANOID
	chk_key(index);
#endif

	sc_error = ENOERROR;
	if (index < 1 || index > nalloc || master[index-1].inuse != 1)
		sc_error = EINVARG;
	else
		d = &master[index-1];

	return(sc_error);
}

/* Create new list */
int	mk_key()
{
	int	index;

	sc_error = ENOERROR;
	if (nalloc == nused)
	{
		/* No space left in current list */
#if defined(FIXEDALLOCATION)
		sc_error = ENOMEM;
		return(sc_error);
#endif
#if defined(VARIABLEALLOCATION)
		if (master == NIL(Dlist *))
		{
			master = (Dlist *)malloc(sizeof(Dlist));
		}
		else
		{
			master = dalloc(master, nalloc, (nalloc+1));
		}
		if (master == NIL(Dlist *))
		{
			/* Failure -- no memory */
			/* NB: old lists have not been lost */
			sc_error = ENOMEM;
			return(sc_error);
		}
		index = ++nalloc;
		master[index-1].inuse = 1;
		nused++;
#endif
	}
	else
	{
		for (index = 0; index < nalloc; index++)
			if (master[index].inuse == 0)
				break;
		if (index >= nalloc)
		{
			/* Lists are scrambled -- core dump imminent */
			sc_error = ENOMEM;
			return(sc_error);
		}
		master[index++].inuse = 1;
		nused++;
	}
	initialise(index);
	return(index);
}

/* Remove list -- make it inactive */
int	rm_key(index)
int		index;
{
	if (check(index))
		return(sc_error);
	(void)zap_key(index);
	nused--;
	master[index-1].inuse = 0;
	return(sc_error);
}

/* Add new item with key value at end of list */
int	ins_key(index, keyval, keylen)
int		 index;
char	*keyval;
int		 keylen;
{
	Ditem	*new;
	ulong	 alloclen;

	if (check(index))
		return(sc_error);

	/* Allocate new Ditem item */
	alloclen = sizeof(Ditem) + keylen;
	if ((new = (Ditem *)malloc(alloclen)) == NIL(Ditem *))
	{
		sc_error = ENOMEM;
		return(sc_error);
	}

	/* Insert new item */
	new->key = ((char *)new) + sizeof(Ditem);
	memcpy(new->key, keyval, keylen);
	new->len = keylen;

#if defined(INSERT_AT_END)
	new->prev = d->head->prev;
	new->next = d->head;
	new->prev->next = new;
	d->head->prev = new;
#else
	/* Relies on d->curr being set to d->head for empty list */
	new->prev = d->curr;
	new->next = d->curr->next;
	d->curr->next->prev = new;
	d->curr->next = new;
#endif

	d->listlength++;
	d->curr = new;

	return(sc_error);
}

/* Update current key */
upd_key(index, keyval, keylen)
int		 index;
char	*keyval;
int		 keylen;
{
	if (check(index))
		return(sc_error);

	if (d->listlength <= 0)
		sc_error = ENOLIST;
	else
	{
		(void)del_key(index);
		(void)ins_key(index, keyval, keylen);
	}
	return(sc_error);
}

/* Delete current key */
del_key(index)
int		index;
{
	Ditem	*old;

	if (check(index))
		return(sc_error);
	if (d->listlength <= 0)
		sc_error = ENOLIST;
	else
	{
		old = d->curr;
		old->prev->next = old->next;
		old->next->prev = old->prev;
		d->listlength--;
		if (old->next != d->head)
			d->curr = old->next;
		else if (old->prev != d->head)
			d->curr = old->prev;
		else
			d->curr = d->head;

		free((char *)old);
	}
	return(sc_error);
}

/* Get current/next/previous/first/last/relative/absolute key */
char	*get_key(index, flag, offset)
int		index;	/* List to work on */
int		flag;	/* Type of move */
int		offset; /* Distance to move */
{
	register Ditem	*curr;
	int		 i;

	if (check(index))
		return(NIL(char *));

	if (d->listlength <= 0)
	{
		sc_error = ENOLIST;
		return(NIL(char *));
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
	if (offset < 0)
	{
		sc_error = EINVARG;
		return(NIL(char *));
	}

	/* Fetch absolute 0 should not produce an error */
	if (flag == SC_ABSOLUTE && offset == 0)
	{
		return(NIL(char *));
	}

	if (offset == 0)
		offset++;

	/* Absolute maps into SC_NEXT from first */
	if (flag == SC_ABSOLUTE)
	{
		flag = SC_NEXT;
		d->curr = d->head->next;
		offset--;
	}

	/* Find relevant row -- overshoot is not an error */
	curr = d->curr;
	switch (flag)
	{
	case SC_CURRENT:
		/* curr = curr; */
		break;
	case SC_FIRST:
		curr = d->head->next;
		break;
	case SC_LAST:
		curr = d->head->prev;
		break;
	case SC_NEXT:
		for (i = 0; i < offset; i++)
		{
			if (curr->next == d->head)
				break;
			curr = curr->next;
		}
		break;
	case SC_PREVIOUS:
		for (i = 0; i < offset; i++)
		{
			if (curr->prev == d->head)
				break;
			curr = curr->prev;
		}
		break;
#if defined(PARANOID)
	default:
		err_key("Impossible case in get_key", flag, 1);
		break;
#endif
	}

	d->curr = curr;
	return(curr->key);
}

/* Delete complete list */
int	zap_key(index)
int		index;
{
	Ditem	*curr;
	Ditem	*old;

	if (check(index))
		return(sc_error);

	curr = d->head->next;
	while (curr != d->head)
	{
		old = curr;
		curr = curr->next;
		free((char *)old);
	}
	d->listlength = 0;
	initialise(index);
	return(sc_error);
}

/* Number of keys in list */
int	cnt_key(index)
int		index;
{
	if (check(index))
		return(sc_error);

	return(d->listlength);
}

/* Number of current key */
int	num_key(index)
int		index;
{
	Ditem	*p;
	int		 i;

	if (check(index))
		return(sc_error);

	i = 0;
	if (d->listlength > 0)
	{
		for (p = d->head->next, i = 1; p != d->curr; p = p->next)
			i++;
	}
	return(i);
}

#if defined(VARIABLEALLOCATION)
#define MIN(a,b)	(((a)<(b))?(a):(b))

Dlist	*dalloc(old, old_size, new_size)
Dlist	*old;
ulong	 old_size;
ulong	 new_size;
{
	Dlist	*new;
	Dlist	*op;
	Dlist	*np;
	int		 i;
	int		 n;

	new = (Dlist *)malloc(new_size*sizeof(Dlist));
	if (new == NIL(Dlist *))
		return(new);

	/* Transfer old lists -- adjust pointers galore */
	n = MIN(old_size, new_size);
	for (i = 0, op = old, np = new; i < n; i++, op++, np++)
	{
		np->head = &np->item;
		if (op->listlength > 0)
		{
			np->head->next = op->head->next;
			np->head->prev = op->head->prev;
			np->head->next->prev = np->head;
			np->head->prev->next = np->head;
		}
		else
		{
			np->head->next = np->head;
			np->head->prev = np->head;
		}
		np->listlength = op->listlength;
		np->inuse      = op->inuse;
		if (op->curr == op->head)
			np->curr = np->head;
		else
			np->curr = op->curr;
	}

	free((char *)old);
	return(new);
}
#endif

#ifdef PARANOID
/*
	This code is never necessary.  On the other hand, it does a
	fairly thorough scrutiny of the data in the named dlist.
	Against that though, the one time it was needed (debugging
	realloc on a SUN), it didn't detect the problem in time.
*/
static int err_count = 0;

chk_key(index)
int	index;
{
	Ditem	*p;
	Ditem	*o;
	int		 i;

	i = 0;
	sc_error = ENOERROR;
	if (index < 1)
		err_key("index under bounds", index, i, 1);
	if (index > nalloc)
		err_key("index over bounds", index, i, 1);
	if (master == NIL(Dlist *))
		err_key("nil master pointer", index, i, 1);
	if (master[index-1].inuse != 1)
		err_key("list not in use", index, i, 1);
	d = &master[index-1];

	if (d == NIL(Dlist *))
		err_key("nil list ptr", index, i, 1);
	o = d->head;
	if (o == NIL(Ditem *))
		err_key("nil head ptr", index, i, 1);
	if (o != &d->item)
		err_key("invalid head ptr", index, i, 1);
	if (o->next == NIL(Ditem *))
		err_key("nil frwd ptr from head", index, i, 1);
	if (o->prev == NIL(Ditem *))
		err_key("nil back ptr from head", index, i, 1);
	if (d->curr == NIL(Ditem *))
		err_key("nil curr ptr", index, i, 0); /* Not fatal immediately */

	p = d->head->next;
	while (p != d->head)
	{
		i++;
		if (o != p->prev)
			err_key("back link error", index, i, 0); /* Not fatal immediately */
		if (p->next == NIL(Ditem *))
			err_key("nil frwd link", index, i, 1);
		if (p->key == NIL(char *))
			err_key("nil data item", index, i, 0); /* Not fatal immediately */
		o = p;
		p = p->next;
	}

	if (i != d->listlength)
		err_key("list length error", index, i, 1);
	if (err_count)
		err_key("too many errors", index, i, 1);
	return(sc_error);
}

static	FILE *fp = NIL(FILE *);
static	err_key(s, ix, inum, mode)
char	*s;
int		 ix;
int		 inum;
int		 mode;
{
	if (fp == NIL(FILE *))
		fp = fopen("key.errors", "w");
	fprintf(fp, "<error> %s in dlist %d item %d\n", s, ix, inum);
	fflush(fp);
	err_count++;
	if (mode == 1)
	{
		dmp_list(d);
		fclose(fp);
		abort();
	}
}

static	dmp_list(p)
Dlist	*p;
{
	Ditem	*s;
	int		 i;

	if (fp == NIL(FILE *))
		fp = fopen("key.errors", "w");

	if (p == NIL(Dlist *))
		fprintf(fp, "Nil list ptr\n");
	else
	{
		fprintf(fp, "Dump of list at 0x%08X\n", p);
		fprintf(fp, "Head = 0x%08X (cf. 0x%08X)\n", p->head, &p->item);
		fprintf(fp, "Current item = 0x%08X\n", p->curr);
		fprintf(fp, "List length = %d\n", p->listlength);
		fprintf(fp, "Use state = %d\n", p->inuse);
		fprintf(fp, "Address    Next       Previous   Key        Length\n");
		fflush(fp);
		s = p->head;
		dmp_item(s);
		for (i = 0; i < p->listlength; i++)
		{
			s = s->next;
			dmp_item(s);
		}
		dmp_item(s->next);
	}
}

static	dmp_item(s)
Ditem	*s;
{
	if (s == NIL(Ditem *))
		fprintf(fp, "<nil> pointer to item");
	fprintf(fp, "0x%08X 0x%08X 0x%08X 0x%08X %d\n",
			s, s->next, s->prev, s->key, s->len);
	fflush(fp);
}
#endif /* PARANOID */

/*
@@(#)	File:			$RCSfile: dlist.c,v $
@@(#)	Version:		$Revision: 1.1 $
@@(#)	Last changed:	$Date: 2002-06-14 05:03:45 $
@@(#)	Purpose:		Maintain multiple D-lists of arbitrary data
@@(#)	Author:			J Leffler
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
static	char	sccs[] = "@@(#)$Id: dlist.c,v 1.1 2002-06-14 05:03:45 afalout Exp $";
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

/*

3.2
log
@Found bug -- when doing realloc, not adjusting all pointers
This is now fixed.
Also self-configuring with either fixed or variable allocation.
Also standard header added etc.
@
text
@d261 1
a261 1
			d->curr = NIL(Ditem *);
@


3.1
log
@Revise headers; unify discrepant versions
@
text
@d2 5
a6 2
	@@(#)$Id: dlist.c,v 1.1 2002-06-14 05:03:45 afalout Exp $
	@@(#)C code to maintain multiple D-lists of arbitrary data
d9 16
d26 3
d30 1
a30 3
#if !defined(lint)
static	char	sccs[] = "@@(#)$Id: dlist.c,v 1.1 2002-06-14 05:03:45 afalout Exp $";
#endif
d33 1
d35 3
a37 4
*/
/* FIXEDALLOCATION if you do not want to use realloc */
#define FIXEDALLOCATION
/* PARANOID if you want each dlist scrutinised before each use */
/* #define PARANOID */
/*
a50 1
	Ditem	*tail;
d53 1
a53 2
	int		 initialised;
	Ditem	 array[2];
d59 7
a65 2
GLOBAL	int		 sc_error;
#ifdef FIXEDALLOCATION
d68 3
a70 1
#else
d73 3
d77 2
a81 4
extern	char	*malloc();
extern	char	*realloc();
extern	void	 free();

d88 4
a91 6
	dp->head = &dp->array[0];
	dp->tail = &dp->array[1];
	dp->head->prev = NIL(Ditem *);
	dp->tail->next = NIL(Ditem *);
	dp->head->next = dp->tail;
	dp->tail->prev = dp->head;
a92 1
	dp->initialised = 1;
d99 5
a109 4
#ifdef PARANOID
	chk_key(index);
#endif

d122 5
a126 4
#ifdef FIXEDALLOCATION
		_efemode();	*/ /* Assumes this is embedded in I4GL */
/*		abort();
#else
d128 1
d130 1
d132 3
a134 1
			master = (Dlist *)realloc((char *)master, (nalloc+1)*sizeof(Dlist));
d138 1
a138 1
*/			/* Must assume all lists lost */
/*
a139 2
			nalloc = 0;
			nused  = 0;
d154 3
a156 2
			_efemode();	 */ /* Assumes this is embedded in I4GL */
/*			abort();
d203 2
a204 2
	new->prev = d->tail->prev;
	new->next = d->tail;
d206 1
a206 1
	d->tail->prev = new;
d208 5
a212 14
	if (d->listlength <= 0) */
	{	/* Empty list */
/*		new->prev = d->head;
		new->next = d->tail;
		d->head->next = new;
		d->tail->prev = new;
	}
	else
	{
		new->prev = d->curr;
		new->next = d->curr->next;
		d->curr->next->prev = new;
		d->curr->next = new;
	}
d256 1
a256 1
		if (old->next != d->tail)
d335 1
a335 1
		curr = d->tail->prev;
d340 1
a340 1
			if (curr->next == d->tail)
d353 5
d375 1
a375 1
	while (curr != d->tail)
a381 1
	d->initialised = 0;
d415 48
d472 1
a472 1
static	chk_key(index)
d480 11
d496 2
d500 5
d506 1
a506 1
	while (p != d->tail)
d510 1
a510 1
			err_key("back link error", index, i, 0);
d514 1
a514 1
			err_key("nil data item", index, i, 0);
d518 1
d526 1
a526 2
#include <stdio.h>
static	FILE *fp;
a532 1

d539 1
a539 1
	{	
a541 1
		_efemode();	*/ /* Assumes this is embedded in I4GL */
/*
d560 1
a560 2
		fprintf(fp, "Head = 0x%08X (cf. 0x%08X)\n", p->head, &p->array[0]);
		fprintf(fp, "Tail = 0x%08X (cf. 0x%08X)\n", p->tail, &p->array[1]);
a561 1
		fprintf(fp, "Initialisation state = %d\n", p->initialised);
d564 1
a564 1
		fprintf(fp, "Address     Next        Previous    Key         Length\n");
d582 2
a583 1
	fprintf(fp, "0x%08X  0x%08X  0x%08X  0x%08X  %d\n", s, s->next, s->prev, s->key, s->len);
d586 1
a586 1
#endif
@


2.5
log
@Add PARANOID code for consistency checking
Not completely bug-proof.
Add FIXEDALLOCATION code to avoid problems with realloc.
@
text
@d3 1
a3 1
	@@(#)C code to maintain multiple doubly-linked list of arbitrary data
d14 1
d16 2
a17 1
#define PARANOID
d99 1
a99 1
		_efemode();
d127 1
a127 1
			_efemode();
d393 6
d454 1
a454 1
		_efemode();
@


2.4
log
@Change indexing (valid lists are 1 .. oo)
@
text
@d13 3
d40 4
d46 1
d79 5
d96 4
d116 1
a122 1
*/		/*
d124 4
a127 2
			lists are buggered;
		*/ /*
d280 1
a280 1
	if (offset < 0 || (flag == SC_ABSOLUTE && offset == 0))
d285 7
d389 104
@


2.3
log
@Fix glitch; return index in mk_key
@
text
@d50 1
a50 1
	Dlist	*d = &master[index];
d52 8
a59 8
	d->head = &d->array[0];
	d->tail = &d->array[1];
	d->head->prev = NIL(Ditem *);
	d->tail->next = NIL(Ditem *);
	d->head->next = d->tail;
	d->tail->prev = d->head;
	d->listlength = 0;
	d->initialised = 1;
d67 1
a67 1
	if (index < 0 || index >= nalloc || master[index].inuse != 1)
d70 1
a70 1
		d = &master[index];
d96 2
a97 3
		index = nalloc;
		master[index].inuse = 1;
		nalloc++;
d109 1
a109 1
		master[index].inuse = 1;
d122 1
a122 1
	zap_key(index);
d124 2
a125 1
	master[index].inuse = 0;
d225 1
@


2.2
log
@Make sc_error GLOBAL
@
text
@d114 1
@


2.1
log
@Initial revision
@
text
@d12 2
d36 1
a36 1
static	int		 sc_error;
@

*/
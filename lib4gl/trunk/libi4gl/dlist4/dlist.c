head	4.1;
access;
symbols;
locks; strict;
comment	@ * @;


4.1
date	91.11.17.22.15.29;	author jl;	state Exp;
branches;
next	3.3;

3.3
date	89.06.28.18.41.32;	author john;	state Exp;
branches;
next	3.2;

3.2
date	88.11.15.11.11.46;	author john;	state Exp;
branches;
next	3.1;

3.1
date	88.10.13.16.17.51;	author john;	state Exp;
branches;
next	2.5;

2.5
date	88.10.12.13.12.35;	author john;	state Exp;
branches;
next	2.4;

2.4
date	88.08.23.15.14.31;	author john;	state Exp;
branches;
next	2.3;

2.3
date	88.06.30.11.07.20;	author john;	state Exp;
branches;
next	2.2;

2.2
date	88.06.29.19.49.58;	author john;	state Exp;
branches;
next	2.1;

2.1
date	88.06.22.09.22.43;	author john;	state Exp;
branches;
next	;


desc
@@


4.1
log
@Un-generalise: now D-Lists store integers (long) only
@
text
@/*
@@(#)	File:			$RCSfile: dlist.c,v $
@@(#)	Version:		$Revision: 1.1 $
@@(#)	Last changed:	$Date: 2002-06-14 05:03:45 $
@@(#)	Purpose:		Maintain multiple integer D-lists
@@(#)	Author:			J Leffler
*/

/*TABSTOP=4*/

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
#endif	/* PARANOID */

/* -- Constant Definitions */

#define GLOBAL
#if defined(FIXEDALLOCATION) && !defined(MAXDLIST)
#define MAXDLIST	30
#endif

/* -- Type Definitions     */

typedef struct Ditem Ditem;
struct Ditem
{
	Ditem          *next;
	Ditem          *prev;
	int             key;
};

struct Dlist
{
	Ditem          *head;
	Ditem          *curr;
	int             listlength;
	Ditem           item;
	int             inuse;
};
typedef struct Dlist Dlist;
typedef unsigned long ulong;

/* -- Declarations         */

#if defined(FIXEDALLOCATION)
static Dlist    master[MAXDLIST];
static int      nalloc = MAXDLIST;
#endif	/* FIXEDALLOCATION */

#if defined(VARIABLEALLOCATION)
static Dlist   *master = NIL(Dlist *);
static int      nalloc = 0;
extern char    *malloc();
extern Dlist   *dalloc();
extern void     free();
#endif	/* VARIABLEALLOCATION */

GLOBAL int      sc_error;
static int      nused = 0;
static Dlist   *d = NIL(Dlist *);

#if defined(PARANOID)
static char     paranoid[] = "@@(#)*** PARANOID D-LISTS ***";
#endif	/* PARANOID */

#if !defined(lint)
static char     sccs[] = "@@(#)$Id: dlist.c,v 1.1 2002-06-14 05:03:45 afalout Exp $";
#endif	/* lint */

/* Initialise new or emptied list */
static void     initialise(index)
int             index;
{
	Dlist          *dp = &master[index - 1];

	dp->head = &dp->item;
	dp->curr = dp->head;
	dp->head->next = dp->head;
	dp->head->prev = dp->head;
	dp->listlength = 0;
}

/* Check that list is valid, reset sc_error, set d */
static int      check(index)
int             index;
{

#ifdef PARANOID
	dl_check(index);
#endif

	sc_error = ENOERROR;
	if (index < 1 || index > nalloc || master[index - 1].inuse != 1)
		sc_error = EINVARG;
	else
		d = &master[index - 1];

	return(sc_error);
}

/* Create new list */
int             dl_create()
{
	int             index;

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
			master = dalloc(master, nalloc, (nalloc + 1));
		}
		if (master == NIL(Dlist *))
		{
			/* Failure -- no memory */
			/* NB: old lists have not been lost */
			sc_error = ENOMEM;
			return(sc_error);
		}
		index = ++nalloc;
		master[index - 1].inuse = 1;
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
int             dl_destroy(index)
int             index;
{
	if (check(index))
		return(sc_error);
	(void)dl_empty(index);
	nused--;
	master[index - 1].inuse = 0;
	return(sc_error);
}

/* Add new item with key value at end of list */
int             dl_insert(index, keyval)
int             index;
int             keyval;
{
	Ditem          *new;
	int             retval;

	if (check(index) != 0)
		retval = sc_error;
	else if ((new = (Ditem *)malloc(sizeof(Ditem))) == NIL(Ditem *))
	{
		sc_error = ENOMEM;
		retval = sc_error;
	}
	else
	{
		/* Insert new item */
		new->key = keyval;
		new->prev = d->curr;
		new->next = d->curr->next;
		d->curr->next->prev = new;
		d->curr->next = new;
		d->listlength++;
		d->curr = new;
		retval = sc_error = 0;
	}
	return(retval);
}

/* Update current key */
dl_update(index, keyval)
int             index;
int             keyval;
{
	if (check(index))
		return(sc_error);

	if (d->listlength <= 0)
		sc_error = ENOLIST;
	else
	{
		(void)dl_delete(index);
		(void)dl_insert(index, keyval);
	}
	return(sc_error);
}

/* Delete current key */
dl_delete(index)
int             index;
{
	Ditem          *old;

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
int             dl_select(index, flag, offset)
int             index;			/* List to work on */
int             flag;			/* Type of move */
int             offset;		/* Distance to move */
{
	register Ditem *curr;
	int             i;

	if (check(index))
		return(0);

	if (d->listlength <= 0)
	{
		sc_error = ENOLIST;
		return(0);
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
		return(0);
	}

	/* Fetch absolute 0 should not produce an error */
	if (flag == SC_ABSOLUTE && offset == 0)
	{
		return(0);
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
		dl_error("Impossible case in dl_select", flag, 1);
		break;
#endif	/* PARANOID */
	}

	d->curr = curr;
	return(curr->key);
}

/* Delete complete list */
int             dl_empty(index)
int             index;
{
	Ditem          *curr;
	Ditem          *old;

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
int             dl_count(index)
int             index;
{
	if (check(index))
		return(sc_error);

	return(d->listlength);
}

/* Number of current key */
int             dl_index(index)
int             index;
{
	Ditem          *p;
	int             i;

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

Dlist          *dalloc(old, old_size, new_size)
Dlist          *old;
ulong           old_size;
ulong           new_size;
{
	Dlist          *new;
	Dlist          *op;
	Dlist          *np;
	int             i;
	int             n;

	new = (Dlist *)malloc(new_size * sizeof(Dlist));
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
		np->inuse = op->inuse;
		if (op->curr == op->head)
			np->curr = np->head;
		else
			np->curr = op->curr;
	}

	free((char *)old);
	return(new);
}

#endif	/* VARIABLEALLOCATION */

#ifdef PARANOID
/*
	This code is never necessary.  On the other hand, it does a
	fairly thorough scrutiny of the data in the named dlist.
	Against that though, the one time it was needed (debugging
	realloc on a SUN), it didn't detect the problem in time.
*/
static int      err_count = 0;

dl_check(index)
int             index;
{
	Ditem          *p;
	Ditem          *o;
	int             i;

	i = 0;
	sc_error = ENOERROR;
	if (index < 1)
		dl_error("index under bounds", index, i, 1);
	if (index > nalloc)
		dl_error("index over bounds", index, i, 1);
	if (master == NIL(Dlist *))
		dl_error("nil master pointer", index, i, 1);
	if (master[index - 1].inuse != 1)
		dl_error("list not in use", index, i, 1);
	d = &master[index - 1];

	if (d == NIL(Dlist *))
		dl_error("nil list ptr", index, i, 1);
	o = d->head;
	if (o == NIL(Ditem *))
		dl_error("nil head ptr", index, i, 1);
	if (o != &d->item)
		dl_error("invalid head ptr", index, i, 1);
	if (o->next == NIL(Ditem *))
		dl_error("nil frwd ptr from head", index, i, 1);
	if (o->prev == NIL(Ditem *))
		dl_error("nil back ptr from head", index, i, 1);
	if (d->curr == NIL(Ditem *))
		dl_error("nil curr ptr", index, i, 0);	/* Not fatal immediately */

	p = d->head->next;
	while (p != d->head)
	{
		i++;
		if (o != p->prev)
			dl_error("back link error", index, i, 0);
		if (p->next == NIL(Ditem *))
			dl_error("nil frwd link", index, i, 1);
		o = p;
		p = p->next;
	}

	if (i != d->listlength)
		dl_error("list length error", index, i, 1);
	if (err_count)
		dl_error("too many errors", index, i, 1);
	return(sc_error);
}

static FILE    *fp = NIL(FILE *);
static          dl_error(s, ix, inum, mode)
char           *s;
int             ix;
int             inum;
int             mode;
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

static          dmp_list(p)
Dlist          *p;
{
	Ditem          *s;
	int             i;

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
		fprintf(fp, "Address    Next       Previous   Key\n");
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

static          dmp_item(s)
Ditem          *s;
{
	if (s == NIL(Ditem *))
		fprintf(fp, "<nil> pointer to item");
	fprintf(fp, "0x%08X 0x%08X 0x%08X %d\n",
			s, s->next, s->prev, s->key);
	fflush(fp);
}

#endif	/* PARANOID */
@


3.3
log
@Fix d->curr = d->head when list is emptied
@
text
@d5 1
a5 1
@@(#)	Purpose:		Maintain multiple D-lists of arbitrary data
d9 2
d30 1
a30 1
#endif
d41 2
a42 1
struct	ditem
d44 3
a46 4
	struct	ditem	*next;
	struct	ditem	*prev;
	char	*key;
	int		 len;
a47 1
typedef	struct ditem Ditem;
d49 1
a49 1
struct	dlist
d51 5
a55 5
	Ditem	*head;
	Ditem	*curr;
	int		 listlength;
	Ditem	 item;
	int		 inuse;
d57 2
a58 2
typedef	struct dlist Dlist;
typedef	unsigned long	ulong;
a61 4
#if !defined(lint)
static	char	sccs[] = "@@(#)$Id: dlist.c,v 1.1 2002-06-14 05:03:45 afalout Exp $";
#endif

d63 3
a65 3
static	Dlist	 master[MAXDLIST];
static	int		 nalloc = MAXDLIST;
#endif
d68 14
a81 6
static	Dlist	*master = NIL(Dlist *);
static	int		 nalloc = 0;
extern	char	*malloc();
extern	Dlist	*dalloc();
extern	void	 free();
#endif
d83 3
a85 3
GLOBAL	int		 sc_error;
static	int		 nused  = 0;
static	Dlist	*d = NIL(Dlist *);
d88 2
a89 2
static	void	initialise(index)
int		index;
d91 1
a91 1
	Dlist	*dp = &master[index-1];
d101 2
a102 2
static	int	check(index)
int			index;
d106 1
a106 1
	chk_key(index);
d110 1
a110 1
	if (index < 1 || index > nalloc || master[index-1].inuse != 1)
d113 1
a113 1
		d = &master[index-1];
d119 1
a119 1
int	mk_key()
d121 1
a121 1
	int	index;
d138 1
a138 1
			master = dalloc(master, nalloc, (nalloc+1));
d148 1
a148 1
		master[index-1].inuse = 1;
d171 2
a172 2
int	rm_key(index)
int		index;
d176 1
a176 1
	(void)zap_key(index);
d178 1
a178 1
	master[index-1].inuse = 0;
d183 10
a192 14
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
d195 13
a207 1
		return(sc_error);
d209 1
a209 23

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
d213 3
a215 4
upd_key(index, keyval, keylen)
int		 index;
char	*keyval;
int		 keylen;
d224 2
a225 2
		(void)del_key(index);
		(void)ins_key(index, keyval, keylen);
d231 2
a232 2
del_key(index)
int		index;
d234 1
a234 1
	Ditem	*old;
a251 1

d258 4
a261 4
char	*get_key(index, flag, offset)
int		index;	/* List to work on */
int		flag;	/* Type of move */
int		offset; /* Distance to move */
d263 2
a264 2
	register Ditem	*curr;
	int		 i;
d267 1
a267 1
		return(NIL(char *));
d272 1
a272 1
		return(NIL(char *));
d293 1
a293 1
		return(NIL(char *));
d299 1
a299 1
		return(NIL(char *));
d344 1
a344 1
		err_key("Impossible case in get_key", flag, 1);
d346 1
a346 1
#endif
d354 2
a355 2
int	zap_key(index)
int		index;
d357 2
a358 2
	Ditem	*curr;
	Ditem	*old;
d376 2
a377 2
int	cnt_key(index)
int		index;
d386 2
a387 2
int	num_key(index)
int		index;
d389 2
a390 2
	Ditem	*p;
	int		 i;
d407 10
a416 10
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
d418 1
a418 1
	new = (Dlist *)malloc(new_size*sizeof(Dlist));
d440 1
a440 1
		np->inuse      = op->inuse;
d450 2
a451 1
#endif
d460 1
a460 1
static int err_count = 0;
d462 2
a463 2
chk_key(index)
int	index;
d465 3
a467 3
	Ditem	*p;
	Ditem	*o;
	int		 i;
d472 1
a472 1
		err_key("index under bounds", index, i, 1);
d474 1
a474 1
		err_key("index over bounds", index, i, 1);
d476 4
a479 4
		err_key("nil master pointer", index, i, 1);
	if (master[index-1].inuse != 1)
		err_key("list not in use", index, i, 1);
	d = &master[index-1];
d482 1
a482 1
		err_key("nil list ptr", index, i, 1);
d485 1
a485 1
		err_key("nil head ptr", index, i, 1);
d487 1
a487 1
		err_key("invalid head ptr", index, i, 1);
d489 1
a489 1
		err_key("nil frwd ptr from head", index, i, 1);
d491 1
a491 1
		err_key("nil back ptr from head", index, i, 1);
d493 1
a493 1
		err_key("nil curr ptr", index, i, 0); /* Not fatal immediately */
d500 1
a500 1
			err_key("back link error", index, i, 0); /* Not fatal immediately */
d502 1
a502 3
			err_key("nil frwd link", index, i, 1);
		if (p->key == NIL(char *))
			err_key("nil data item", index, i, 0); /* Not fatal immediately */
d508 1
a508 1
		err_key("list length error", index, i, 1);
d510 1
a510 1
		err_key("too many errors", index, i, 1);
d514 6
a519 6
static	FILE *fp = NIL(FILE *);
static	err_key(s, ix, inum, mode)
char	*s;
int		 ix;
int		 inum;
int		 mode;
d534 2
a535 2
static	dmp_list(p)
Dlist	*p;
d537 2
a538 2
	Ditem	*s;
	int		 i;
d552 1
a552 1
		fprintf(fp, "Address    Next       Previous   Key        Length\n");
d565 2
a566 2
static	dmp_item(s)
Ditem	*s;
d570 2
a571 2
	fprintf(fp, "0x%08X 0x%08X 0x%08X 0x%08X %d\n",
			s, s->next, s->prev, s->key, s->len);
d574 2
a575 1
#endif /* PARANOID */
@


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
/* FIXEDALLOCATION if you do not want to use realloc */
#define FIXEDALLOCATION
/* PARANOID if you want each dlist scrutinised before each use */
/* #define PARANOID */
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
		_efemode();	/* Assumes this is embedded in I4GL */
		abort();
#else
d128 1
d130 1
d132 3
a134 1
			master = (Dlist *)realloc((char *)master, (nalloc+1)*sizeof(Dlist));
d138 1
a138 1
			/* Must assume all lists lost */
a139 2
			nalloc = 0;
			nused  = 0;
d154 3
a156 2
			_efemode();	/* Assumes this is embedded in I4GL */
			abort();
d203 2
a204 2
	new->prev = d->tail->prev;
	new->next = d->tail;
d206 1
a206 1
	d->tail->prev = new;
d208 5
a212 14
	if (d->listlength <= 0)
	{	/* Empty list */
		new->prev = d->head;
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
		_efemode();	/* Assumes this is embedded in I4GL */
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
		/*
d124 4
a127 2
			lists are buggered;
		*/
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

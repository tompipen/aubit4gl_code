/*
@(#)	File:			$RCSfile: dlist.c,v $
@(#)	Version:		$Revision: 1.2 $
@(#)	Last changed:	$Date: 2002-06-14 09:23:16 $
@(#)	Purpose:		Maintain multiple integer D-lists
@(#)	Author:			J Leffler
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
static char     paranoid[] = "@(#)*** PARANOID D-LISTS ***";
#endif	/* PARANOID */

#if !defined(lint)
static char     sccs[] = "@(#)$Id: dlist.c,v 1.2 2002-06-14 09:23:16 afalout Exp $";
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

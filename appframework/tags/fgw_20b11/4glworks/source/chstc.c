/*
	CHSTL.c - hash table routines

	The 4glWorks application framework
	Copyright (C) 1992-2002 Marco Greco (marco@4glworks.com)

	Initial release: Apr 99
	Current release: Jan 02

	This library is free software; you can redistribute it and/or
	modify it under the terms of the GNU Lesser General Public
	License as published by the Free Software Foundation; either
	version 2.1 of the License, or (at your option) any later version.

	This library is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public
	License along with this library; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

#ifndef popquote
#define popquote popvchar	/* since this is what we actually need */
#endif

#include <string.h>
#include <signal.h>
#include <locator.h>
#include <datetime.h>
#include <sqltypes.h>
#include "chstc.h"

/* align every struct allocated to 16 bytes boundaries */
#define fgw_entrysize(arg) ((arg & 0xf)? ((arg | 0xf)+1): arg);

extern char *fgw_popquote();
extern int status;

#define K_hashmin	  4
#define K_hashmax	 64
#define K_hashmult	  2
#define K_hashlim	  3

/*
** test if bytevar is a usable blob
*/
static int fgw_testhash(bytevar)
loc_t *bytevar;
{
    return ((bytevar->loc_loctype!=LOCMEMORY) ||
	    (bytevar->loc_type!=SQLBYTES) ||
	    (fgw_hashhead(bytevar)->magic!=HASHKEY));
}

/*
** frees space in hash
*/
static fgw_hstfree(bytevar, o)
loc_t *bytevar;
int o;
{
    fgw_hstentry *e, *f, *g;
    int *n;

/*
** mark entry as free & adjust free count
*/
    e=fgw_hashentry(bytevar, o);
    e->type=-1;
    fgw_hashhead(bytevar)->freecnt+=e->size;
    n=&(fgw_hashhead(bytevar)->freeptr);
/*
** scan all free list entries
*/
    while (*n)
    {
	f=fgw_hashentry(bytevar, *n);
/*
** new free entry is next to previous
*/
	if (*n+f->size==o)
	{
	    f->size+=e->size;
/*
** and together they are next to the next
*/
	    if (*n+f->size==f->next)
	    {
		g=fgw_hashentry(bytevar, f->next);
		f->size+=g->size;
		f->next=g->next;
	    }
	    return;
	}
/*
** new free entry is next to next
*/
	else if (o==f->next)
	{
	    g=fgw_hashentry(bytevar, f->next);
	    e->next=g->next;
	    e->size+=g->size;
	    *n=o;
	    return;
	}
	n=&(f->next);
    }
/*
** last entry int the free list
*/
    *n=o;
    e->next=0;
}

/*
** allocates new entry
*/
static int fgw_hstnew(bytevar, l)
loc_t *bytevar;
int l;
{
    fgw_hstentry *f, *g;
    int o, *p, r, s;
    char *b;

    l=fgw_entrysize(l);
    p=&(fgw_hashhead(bytevar)->freeptr);
/*
** scan all free list entries
*/
    while (*p)
    {
	f=fgw_hashentry(bytevar, *p);
/*
** an exact fit
*/
	if (f->size==l)
	{
	    r=*p;
	    *p=f->next;
	    fgw_hashhead(bytevar)->freecnt-=l;
	    return r;
	}
/*
** a greater fit, will have to split it in two
*/
	else if (f->size>l)
	{
	    r=*p;
	    *p+=l;
	    g=fgw_hashentry(bytevar, *p);
	    g->type=1;
	    g->size=f->size-l;
	    g->next=f->next;
	    f->size=l;
	    return r;
	}
	p=&(f->next);
    }
/*
** no free space found, reallocate byte buffer
*/
   o=(int) ((char *) p-bytevar->loc_buffer);
   s=(l>STARTHASHSIZE)? l: STARTHASHSIZE;
   if (b=(char *) realloc(bytevar->loc_buffer, bytevar->loc_bufsize+s))
   {
	bytevar->loc_buffer=b;
	p=(int *) b+o;
	r=bytevar->loc_size;
	bytevar->loc_size+=s;
/*
** if we have reallocated more space than needed, create new free entry
*/
	if (s>l)
	{
	    f=fgw_hashentry(bytevar, r+l);
	    f->next=0;
	    f->type=-1;
	    f->size=s-l;
/*
** and fix last entry's next
*/
	    *p=r+l;
	}
	return r;
   }
   return 0;
}

/*
**  hash function
*/
static int eval_hst(s, b)
char *s;
long b;
{
    char *c;
#ifdef __STDC__
    unsigned
#endif
	long h;

    h=0;
    c=s;
    while (*c)
	h=*c++ +65599*h;
#ifndef __STDC__
    h&=(MAXINT>>1);	/* avoid negative hashes! */
#endif
    return 1+(h%b);
}

/*
**  free an old blob
*/
fgw_freehash(bytevar)
loc_t *bytevar;
{
/*
**  try to avoid memory leaks & segv's :-)
*/
    if (bytevar->loc_loctype==LOCMEMORY &&
	bytevar->loc_bufsize>0 &&
	bytevar->loc_buffer)
    {
	free(bytevar->loc_buffer);
	bytevar->loc_buffer=NULL;
    }
}

/*
**  starts a hash table
*/
fgw_locatehash(bytevar, buckets)
loc_t *bytevar;
int buckets;
{
    int i;
    fgw_hstentry *h;

    if (buckets<K_hashmin || buckets>K_hashmax)
    {
	status=-717;
	return;
    }
    fgw_freehash(bytevar);
    bytevar->loc_buffer=(char *) malloc(STARTHASHSIZE);
    if (!bytevar->loc_buffer)
    {
	status=-1319;
	return;
    }
/*
** init blob...
*/
    bytevar->loc_type=SQLBYTES;
    bytevar->loc_loctype=LOCMEMORY;
    bytevar->loc_bufsize=STARTHASHSIZE;
    bytevar->loc_size=sizeof(fgw_hsthead)+sizeof(int)*buckets+
			fgw_entrysize(sizeof(fgw_hstentry));
    bytevar->loc_indicator=0;
/*
** ...and hash head...
*/
    fgw_hashhead(bytevar)->magic=HASHKEY;
    fgw_hashhead(bytevar)->entries=0;
    fgw_hashhead(bytevar)->freecnt=STARTHASHSIZE-sizeof(fgw_hsthead)
				   -sizeof(int)*buckets;
    fgw_hashhead(bytevar)->freeptr=sizeof(int)*buckets+sizeof(fgw_hsthead);
    fgw_hashhead(bytevar)->buckets[0]=buckets;
/*
** ...and buckets
*/
    for (i=1; i<=buckets; i++)
	fgw_hashhead(bytevar)->buckets[i]=0;
/*
** init free list
*/
    h=fgw_hashentry(bytevar, fgw_hashhead(bytevar)->freeptr);
    h->next=0;
    h->size=fgw_hashhead(bytevar)->freecnt;
    h->type=-1;
}


/*
** reorganize & resize hash
*/
static reorg_hst(bytevar, buckets)
loc_t *bytevar;
int buckets;
{
    char *ob, *nb;
    int os, ns, o, b;
    fgw_hstentry *oe, *ne;

    ns=bytevar->loc_bufsize-fgw_hashhead(bytevar)->buckets[0]*sizeof(int)-
	fgw_hashhead(bytevar)->freecnt+buckets*sizeof(int);
/*
** if not enough memory, leave buffer untouched
*/
    if (!(nb=(char *) malloc(ns)))
	return;
/*
** save old buffer data for scan
*/
    oe=fgw_hashentry(bytevar, sizeof(fgw_hsthead)+
			      fgw_hashhead(bytevar)->buckets[0]*sizeof(int));
    os=bytevar->loc_bufsize;
    ob=bytevar->loc_buffer;
/*
** initialize byte variable
*/
   bytevar->loc_bufsize=ns;
   bytevar->loc_buffer=nb;
/*
** ...and hash head...
*/
    fgw_hashhead(bytevar)->magic=HASHKEY;
    fgw_hashhead(bytevar)->entries=0;
    fgw_hashhead(bytevar)->freecnt=bytevar->loc_bufsize-sizeof(fgw_hsthead)
				   -sizeof(int)*buckets;
    fgw_hashhead(bytevar)->freeptr=sizeof(int)*buckets+sizeof(fgw_hsthead);
    fgw_hashhead(bytevar)->buckets[0]=buckets;
/*
** ...and buckets
*/
    for (b=1; b<=buckets; b++);
	fgw_hashhead(bytevar)->buckets[b]=0;
/*
** init free list
*/
    ne=fgw_hashentry(bytevar, fgw_hashhead(bytevar)->freeptr);
    ne->next=0;
    ne->size=fgw_hashhead(bytevar)->freecnt;
    ne->type=-1;
/*
** scan old buffer & populate new;
*/
    while (os>0)
    {
/*
** copy entries save freelist
*/
	if (oe->type!=-1)
	{
	    b=eval_hst(buckets, fgw_defentry(oe));
/*
** FIXME: ought to be checking for lack of space for completeness
** (not really necessary - we should have allocated all the memory we need)
*/
	    o=fgw_hstnew(bytevar, oe->size);
	    ne=fgw_hashentry(bytevar, o);
	    fgw_move(ne, oe, oe->size);
	    ne->next=fgw_hashhead(bytevar)->buckets[b];
	    fgw_hashhead(bytevar)->buckets[b]=o;
	}
	os-=oe->size;
	oe=(fgw_hstentry *) ((char *) oe+oe->size);
    }
/*
** and finally release old buffer
*/
    free(ob);
}

/*
** add entry
*/
fgw_hstadd(bytevar, def, type, entry)
loc_t *bytevar;
char *def;
int type;
char *entry;
{
    int b, o, *p, l;
    fgw_hstentry *e;

    if (fgw_testhash(bytevar))
    {
	status=-717;
	return;
    }
    if (risnull(CSTRINGTYPE, def))
	*def='\0';
    switch(type)
    {
      case CSTRINGTYPE:
	l=strlen(entry)+1;
	break;
      case CDOUBLETYPE:
	l=sizeof(double);
	break;
      case CINTTYPE:
      case CDATETYPE:
	l=sizeof(int);
	break;
      case CDTIMETYPE:
	l=sizeof(dtime_t);
	break;
      case CINVTYPE:
	l=sizeof(intrvl_t);
	break;
      case CDECIMALTYPE:
      case CMONEYTYPE:
	l=sizeof(dec_t);
	break;
    }
    b=eval_hst(def, fgw_hashhead(bytevar)->buckets[0]);
    p=&(fgw_hashhead(bytevar)->buckets[b]);
/*
** scan bucket chain until entry found
*/
    while (*p)
    {
	e=fgw_hashentry(bytevar, *p);
/*
** was already there...
*/
	if (!strcmp(fgw_defentry(e), def))
/*
** ...and new value fits (leave entry untouched, makes further changes faster)
*/
	    if (e->def>l)
	    {
		e->type=type;
		fgw_move(&(e->entry), entry, l);
		return;
	    }
/*
** does not fit, hence free old entry & allocate new
*/
	    else
	    {
		fgw_hashhead(bytevar)->entries--;
		o=e->next;
		fgw_hstfree(bytevar, *p);
		*p=o;
		break;
	    }
	p=&(e->next);
    }
/*
** if lack of space, we loose the old contents (may want to fix this)
*/
    if (o=fgw_hstnew(bytevar, sizeof(fgw_hstentry)+strlen(def)+l))
    {
	e=fgw_hashentry(bytevar, o);
/*
** construct new entry
*/
	e->next=fgw_hashhead(bytevar)->buckets[b];
	e->type=type;
	e->def=l;
	fgw_move(&(e->entry), entry, l);
	fgw_move(&(e->entry)+l, def, strlen(def)+1);
/*
** place it on top of the bucket chain
*/
	fgw_hashhead(bytevar)->buckets[b]=o;
/*
** fix header * reorg if necessary
*/
	fgw_hashhead(bytevar)->entries++;
	if ((fgw_hashhead(bytevar)->entries>
	     fgw_hashhead(bytevar)->buckets[0]*K_hashlim) &&
	    (fgw_hashhead(bytevar)->buckets[0]*K_hashmult<=K_hashmax))
	    reorg_hst(bytevar, fgw_hashhead(bytevar)->buckets[0]*K_hashmult);
    }
    else
	status=-1319;
}

/*
** retrieve entry
*/
fgw_hstentry *fgw_hstget(bytevar, def)
loc_t *bytevar;
char *def;
{
    int o, *p, b;
    fgw_hstentry *e;

    if (fgw_testhash(bytevar))
    {
	status=-717;
	return NULL;
    }
    if (risnull(CSTRINGTYPE, def))
	*def='\0';
    b=eval_hst(def, fgw_hashhead(bytevar)->buckets[0]);
    p=&(fgw_hashhead(bytevar)->buckets[b]);
/*
** scan bucket chain until entry found
*/
    while (*p)
    {
	e=fgw_hashentry(bytevar, *p);
	if (!strcmp(fgw_defentry(e), def))
/*
** found match - move it on top of the bucket chain
*/
	{
	    o=*p;
	    *p=e->next;
	    e->next=fgw_hashhead(bytevar)->buckets[b];
	    fgw_hashhead(bytevar)->buckets[b]=o;
	    return e;
	}
	p=&(e->next);
    }
    return NULL;
}

/*
** drop entry
*/
fgw_hstdrop(bytevar, def)
loc_t *bytevar;
char *def;
{
    fgw_hstentry *e;
    int *n, oo;

    if (fgw_testhash(bytevar))
    {
        status=-717;
        return;
    }
    if (risnull(CSTRINGTYPE, def))
	*def='\0';
/*
** save pointer to previous fgw_hstentry->next
*/
    n=&fgw_hashhead(bytevar)->buckets[eval_hst(def,
                                        fgw_hashhead(bytevar)->buckets[0])];
    while (*n)
    {
        e=fgw_hashentry(bytevar, *n);
        if (!strcmp(fgw_defentry(e), def))
        {
	    oo=*n;
/*
** adjust nexts, type of entry to free, # of entries
*/
	    *n=e->next;
	    e->type=-1;
	    fgw_hashhead(bytevar)->entries--;
/*
** if too few entries, resize hash, else proceed with freeing entry
*/
	    if ((fgw_hashhead(bytevar)->entries<
		 fgw_hashhead(bytevar)->buckets[0]/K_hashlim) &&
		(fgw_hashhead(bytevar)->buckets[0]*K_hashmult>=K_hashmin))
		reorg_hst(bytevar, fgw_hashhead(bytevar)->buckets[0]/K_hashmult);
	    else if (fgw_hashhead(bytevar)->freecnt*2>bytevar->loc_size)
		reorg_hst(bytevar, fgw_hashhead(bytevar)->buckets[0]);
	    else
		fgw_hstfree(bytevar, oo);
	    break;
	}
	n=&(e->next);
    }
}

/*
**  starts a hash table
*/
hst_start(nargs)
int nargs;
{
    loc_t *bytevar;
    int buckets, i;
    fgw_hstentry *h;

    popint(&buckets);
    poplocator(&bytevar);
    fgw_locatehash(bytevar, buckets);
    return 0;
}

/*
**  frees a hash table
*/
hst_free(nargs)
int nargs;
{
    loc_t *bytevar;

    poplocator(&bytevar);
    fgw_freehash(bytevar);
    if (!bytevar->loc_buffer)
	bytevar->loc_loctype=0;
    return(0);
}

/*
**  enters/modifies an entry
*/
hst_enter(nargs)
int nargs;
{
    loc_t *bytevar;
    char *def;
    char *entry;

    entry=fgw_popquote();
    def=fgw_popquote();
    poplocator(&bytevar);
    if (def && entry)
	fgw_hstadd(bytevar, def, CSTRINGTYPE, entry);
    if (def)
	free(def);
    if (entry)
	free(entry);
    return 0;
}

/*
**  enters/modifies an entry
*/
hst_enterint(nargs)
int nargs;
{
    loc_t *bytevar;
    char *def;
    int entry;

    popint(&entry);
    def=fgw_popquote();
    poplocator(&bytevar);
    if (def)
    {
	fgw_hstadd(bytevar, def, CINTTYPE, (char *) &entry);
	free(def);
    }
    return 0;
}

/*
**  enters/modifies an entry
*/
hst_enterfloat(nargs)
int nargs;
{
    loc_t *bytevar;
    char *def;
    double entry;

    popdub(&entry);
    def=fgw_popquote();
    poplocator(&bytevar);
    if (def)
    {
	fgw_hstadd(bytevar, def, CDOUBLETYPE, (char *) &entry);
	free(def);
    }
    return 0;
}

/*
**  enters/modifies an entry
*/
hst_enterdecimal(nargs)
int nargs;
{
    loc_t *bytevar;
    char *def;
    dec_t entry;

    popdec(&entry);
    def=fgw_popquote();
    poplocator(&bytevar);
    if (def)
    {
	fgw_hstadd(bytevar, def, CDECIMALTYPE, (char *) &entry);
	free(def);
    }
    return 0;
}

/*
**  enters/modifies an entry
*/
hst_enterdate(nargs)
int nargs;
{
    loc_t *bytevar;
    char *def;
    int entry;

    popint(&entry);
    def=fgw_popquote();
    poplocator(&bytevar);
    if (def)
    {
	fgw_hstadd(bytevar, def, CDATETYPE, (char *) &entry);
	free(def);
    }
    return 0;
}

/*
**  enters/modifies an entry
*/
hst_enterdtime(nargs)
int nargs;
{
    loc_t *bytevar;
    char *def;
    dtime_t entry;

    popdtime(&entry);
    def=fgw_popquote();
    poplocator(&bytevar);
    if (def)
    {
	fgw_hstadd(bytevar, def, CDTIMETYPE, (char *) &entry);
	free(def);
    }
    return 0;
}

/*
**  enters/modifies an entry
*/
hst_enterinv(nargs)
int nargs;
{
    loc_t *bytevar;
    char *def;
    intrvl_t entry;

    popinv(&entry);
    def=fgw_popquote();
    poplocator(&bytevar);
    if (def)
    {
	fgw_hstadd(bytevar, def, CINVTYPE, (char *) &entry);
	free(def);
    }
    return 0;
}

/*
**  retrieve an entry
*/
hst_retrieve(nargs)
int nargs;
{
    loc_t *bytevar;
    char *def;
    fgw_hstentry *entry;

    def=fgw_popquote();
    poplocator(&bytevar);
    if (def && (entry=fgw_hstget(bytevar, def)))
	switch (entry->type)
	{
	case CINTTYPE:
	    retint(*(int *) &(entry->entry));
	    break;
	case CDATETYPE:
	    retdate(*(int *) &(entry->entry));
	    break;
	case CDOUBLETYPE:
	    retdub(*(double *) &(entry->entry));
	    break;
	case CMONEYTYPE:
	case CDECIMALTYPE:
	    retdec((dec_t *) &(entry->entry));
	    break;
	case CDTIMETYPE:
	    retdtime((dtime_t *) &(entry->entry));
	    break;
	case CINVTYPE:
	    retinv((intrvl_t *) &(entry->entry));
	    break;
	case CSTRINGTYPE:
	    retquote(&(entry->entry));
	    break;
	}
    else
	retquote("");
    if (def)
	free(def);
    return 1;
}

/*
**  drops an entry
*/
hst_drop(nargs)
int nargs;
{
    loc_t *bytevar;
    char *def;

    def=fgw_popquote();
    poplocator(&bytevar);
    if (def)
    {
	fgw_hstdrop(bytevar, def);
	free(def);
    }
    return 0;
}

/*
**  true if entry is member of the hash
*/
hst_member(nargs)
int nargs;
{
    loc_t *bytevar;
    char *def;
    int r;

    def=fgw_popquote();
    poplocator(&bytevar);
    rsetnull(CINTTYPE, (char *) &r);
    if (def)
    {
	if (fgw_hstget(bytevar, def))
	    r=1;
	else if (!status)	/* side effect */
	    r=0;
	free(def);
    }
    retint(r);
    return 1;
}

/*
**  hash scan (for member in hash...)
*/
hst_scan(nargs)
int nargs;
{
    loc_t *bytevar;
    int idx, nidx;
    fgw_hstentry *h;

    rsetnull(CINTTYPE, (char *) &nidx);
    popint(&idx);
    poplocator(&bytevar);
    if (fgw_testhash(bytevar))
	goto badexit;
    if (risnull(&idx, CINTTYPE) || idx==0)
	h=fgw_hashentry(bytevar,
  			sizeof(fgw_hsthead)+fgw_hashhead(bytevar)->buckets[0]); 
    else if (idx>0 && idx<bytevar->loc_size-sizeof(fgw_hstentry))
	h=fgw_hashentry(bytevar, idx);
    else
	goto badexit;
    if (h->type==-1)
	h=(fgw_hstentry *) ((char *) h+h->size);
    if (h->type!=CINTTYPE && h->type!=CDATETYPE &&
	h->type!=CDOUBLETYPE && h->type!=CSTRINGTYPE)
	goto badexit;
    retquote(fgw_defentry(h));
    switch(h->type)
    {
    case CINTTYPE:
	retint(*(int *) &(h->entry));
	break;
    case CDATETYPE:
	retdate(*(int *) &(h->entry));
	break;
    case CDOUBLETYPE:
	retdub(*(double *) &(h->entry));
	break;
    case CDTIMETYPE:
	retdtime((dtime_t *) &(h->entry));
	break;
    case CINVTYPE:
	retinv((intrvl_t *) &(h->entry));
	break;
    case CSTRINGTYPE:
	retquote(&(h->entry));
	break;
    }
    retint(idx+h->size);
    return(3);
badexit:
    retquote("");
    retquote("");
    retint(nidx);
    return(3);
}

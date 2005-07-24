/*
	CCMNC.c  -  functions used by C functions only

	The 4glWorks application framework
	Copyright (C) 1992-2002 Marco Greco (marco@4glworks.com)

	Initial release: Oct 92
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

#include <string.h>
#include "ccmnc.h"

extern int status;

/*
**  Internal routine to clip strings
*/
fgw_clip(c)
char *c;
{
    char *p;
    int i;

    i=1;
    if (c)
    {
	while (*c)
	{
	    if (*c!=' ')
		i=1;
	    else if (i)
	    {
		p=c;
		i=0;
	    }
	    c++;
	}
	if (!i)
	    *p=0;
    }
}

/*
**  returns the position of a substring within a string
*/
fgw_pos(s1, s2)
char *s1, *s2;
{
    char *p, *q, *r;

    if (!*s2)
	return 0;
    for (p=s1; *p;)
    {
	r=p++;
	q=s2;
	while (*r==*q)
	{
	    r++;
	    q++;
	    if (!*q)
		return p-s1;
	}
    }
    return 0;
}

/*
**  moves buffer contents (memmove not available in all systems)
*/
fgw_move(d, s, c)
char *d, *s;
int c;
{
    if (d>s)
    {
	d+=c;
	s+=c;
	while (c--)
	    *--d=*--s;
    }
    else
	while (c--)
	    *d++=*s++;
}

/*
**  pops a char, allocating appropriate mem amount
*/
char *fgw_popquote()
{
    char *p, *q;
    int l;
    char b[2];

    p=(char *) malloc(36000);
    if (p)
    {
	popquote(p, 32000);
	fgw_clip(p);
/*
** buffer is going to be at least ten chars, and twice as much as the
** length of the string being popped - should be enough for manipulating
** strings. if you exceed this amount, expect a core dump!
*/
	if ((l=strlen(p))<10)
	   l+=10;
	else
	   l*=2;
	if (q=(char *) realloc(p, l))
	    p=q;		/* defensive code, really */
    }
    else popquote(b, 2);	/* clear stack */
    return(p);
}

/*
**  search list entry
*/
fgw_listentry *fgw_listsearch(id, list)
int id;
fgw_listtype *list;
{
    fgw_listentry *p;

    if (id==list->lastid)
	return list->last;
    p=list->head;
    while (p!=NULL)
    {
	if (p->id==id)
	{
	    list->last=p;
	    list->lastid=id;
	    return list->last;
	}
	p=p->next;
    }
    status=list->notfound;
    return NULL;
}

/*
**  add entry to list
*/
fgw_newentry(entry, list)
fgw_listentry *entry;
fgw_listtype *list;
{
    entry->next=list->head;
    entry->id=++(list->base);
    list->head=entry;
}

/*
**  remove entry from list
*/
fgw_dropentry(entry, list)
fgw_listentry *entry;
fgw_listtype *list;
{
    fgw_listentry *p;
    fgw_listentry *prev;

    if (entry==list->last);
    {
	list->lastid=0;
	list->last=NULL;
    }
    if (entry==list->head)
    	list->head=entry->next;
    else
    {
	p=list->head;
	while (p && p->next!=entry)
	    p=p->next;
	if (p)
	    p->next=entry->next;
    }
    free(entry);
}

/*
** initializes stack structure
*/
fgw_stackinit(stack, size)
fgw_stacktype *stack;
int size;
{
    stack->size=size;
    stack->count=0;
    stack->len=0;
    stack->stack=NULL;
}

/*
** frees stack structure
*/
fgw_stackfree(stack, clear)
fgw_stacktype *stack;
void (*clear)();
{
    int i;
    char *s;

    if (clear)
        for (i=0, s=stack->stack; i<stack->count; i++, s+=stack->size)
	    (*clear)(s);
    if (stack->stack)
	free(stack->stack);
    stack->len=0;
    stack->count=0;
    stack->size=0;
    stack->stack=NULL;
}

/*
** pushes element onto stack
*/
fgw_stackpush(stack, element)
fgw_stacktype *stack;
char *element;
{
    char *dummy;

    if (stack->len==stack->count || !stack->len)
    {
	if (!(dummy=(char *) realloc(stack->stack, (stack->len+10)*stack->size)))
	{
	    status=-208;
	    return;
	}
	stack->len+=10;
	stack->stack=dummy;
    }
    fgw_move(stack->stack+(stack->count*stack->size), element, stack->size);
    stack->count++;
}

/*
** pops element off stack
*/
char *fgw_stackpop(stack)
fgw_stacktype *stack;
{
    if (stack->count)
    {
	stack->count--;
	return stack->stack+(stack->count*stack->size);
    }
    else
	return NULL;
}

/*
** peeks top of stack
*/
char *fgw_stackpeek(stack)
fgw_stacktype *stack;
{
    if (stack->count)
	return stack->stack+((stack->count-1)*stack->size);
    else
	return NULL;
}

/*
** drops n elements off stack
*/
fgw_stackdrop(stack, n)
fgw_stacktype *stack;
int n;
{
    if (n>0)
	if (stack->count>=n)
	    stack->count-=n;
	else
	    stack->count=0;	/* FIXME: tighter error checking */
}

/* circular linked list going backwards (allows fast ordered inserts)
   linked list going forward (easy end of list test) */


/*
** attach element to temporary space
*/
fgw_tssattach(head, element)
fgw_tsstype **head;
char *element;
{
    fgw_tsstype *p;
 
    p=(fgw_tsstype *) ((char *) element-2*sizeof(char *));
    if (*head)
    {
	(*head)->prev->next=p;
	p->prev=(*head)->prev;
	(*head)->prev=p;
    }
    else
    {
	p->prev=p;
	(*head)=p;
    }
    p->next=NULL;
}

/*
** detach element from temporary space
*/
fgw_tssdetach(head, element)
fgw_tsstype **head;
char *element;
{
    fgw_tsstype *s;
 
    s=(fgw_tsstype *) ((char *) element-2*sizeof(char *));
    if (s==*head)
    {
	*head=s->next;
	if (*head)
	    (*head)->prev=s->prev;    
    }
    else
    {
	if (s->next)
	{
	    s->prev->next=s->next;
	    s->next->prev=s->prev;
	}
	else
	{
	    s->prev->next=NULL;
	    (*head)->prev=s->prev;
	}
    }
}

/*
** allocate temporary space
*/
char *fgw_tssmalloc(head, size)
fgw_tsstype **head;
int size;
{
    fgw_tsstype *p;
 
    if (!(p=(fgw_tsstype *) malloc(size+sizeof(fgw_tsstype))))
	return NULL;
    fgw_tssattach(head, &(p->string));
    return &(p->string);
}


/*
** reallocate temporary space
*/
char *fgw_tssrealloc(head, element, size)
fgw_tsstype **head;
char *element;
int size;
{
    fgw_tsstype *p, *n;
 
    if (!element)
	return fgw_tssmalloc(head, size);
    p=(fgw_tsstype *) ((char *) element-2*sizeof(char *));
    if (n=(fgw_tsstype *) realloc(p, size+sizeof(fgw_tsstype)))
    {
	if (*head==p)
	    *head=n;
	else
	    n->prev->next=n;
	if (n->next)
	    n->next->prev=n;
	return &(n->string);
    }
    else
	return NULL;
}

/*
** free temporary space
*/
fgw_tssfree(head, element)
fgw_tsstype **head;
char *element;
{
    fgw_tsstype *s;
 
    s=(fgw_tsstype *) ((char *) element-2*sizeof(char *));
    fgw_tssdetach(head, element);
    free(s);
}

/*
** drop temporary space
*/
fgw_tssdrop(head)
fgw_tsstype **head;
{
    fgw_tsstype *h, *n;
 
    h=*head;
    while (n=h)         /* not an error */
    {
        h=h->next;
        free(n);
    }
    *head=NULL;
}

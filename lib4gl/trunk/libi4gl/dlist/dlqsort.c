/*
@@(#)File:            $RCSfile: dlqsort.c,v $
@@(#)Version:         $Revision: 1.1 $
@@(#)Last changed:    $Date: 2002-06-14 05:03:45 $
@@(#)Purpose:         QSORT for doubly-linked lists
@@(#)Product:         :PRODUCT:
*/

/*TABSTOP=4*/

/*
** From: jjsc@@inf.rl.ac.uk (John Cullen)
** Newsgroups: comp.lang.c
** Subject: Double linked list quicksort - program.
** Message-ID: <11906@@pecan.rl.ac.uk>
** Date: 6 Jan 92 11:04:35 GMT
**
** I am posting this on behalf of a friend without direct news
** access.  If possible please reply to him direct.
**
** John
**
** ---- Start of included message ----
**
** Earlier this year, I sent my double-linked list package out on
** this list.  In the description, I raised the question as to the
** possibility of sorting a double-linked list (without converting it
** to an array of pointers).  Well, it is possible; and I append a
** quicksort to sort double-linked lists, together with a
** demonstration program.  You will need my header file from my
** previous posting.  If you havn't got a copy, mail me, and I will
** send you one.  My e-mail address is: GORMAN_B@@P1.LANCSP.AC.UK.  Our
** site will be closed from Christmas Eve until the New Year, so there
** may be a delay in replying.  Enjoy!
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkpack.h"

#ifndef lint
static char     sccs[] = "@@(#)$Id: dlqsort.c,v 1.1 2002-06-14 05:03:45 afalout Exp $";
#endif

/******************************************\
**                                        **
**  DOUBLY-LINKED LIST QUICKSORT PACKAGE  **
**                                        **
\******************************************/

static int    (*qsort_l2_cmp)(void *e1, void *e2);

static void     qsort_l2_swop(s, t)
LINKS          *s;
LINKS          *t;				/* assumes: s!=t && s->prev!=t */
{
	LINKS          *r = s->prev;
	LINKS          *u = t->next;/* get surrounding pointers */

	(void)remove(s);
	(void)remove(t);			/* unlink list elements */
	add_after(r, t);
	add_before(u, s);			/* and re-link in new place */
}

/*
** Main working routine for D-List Quick-Sort
*/
static void     qsort_l2_aux(left, right)
LINKS          *left;
LINKS          *right;
{
	while (left != right)		/* don't sort less than two elements */
	{
		LINKS          *p = left = left->prev;
		LINKS          *q = right;	/* p is i, and q is j in the book */

		do
		{
			while ((*qsort_l2_cmp)(p = p->next, right) < 0)
				;	/* scan left */
			while (p != q && (*qsort_l2_cmp)(q = q->prev, right) > 0)
				;	/* scan right */
			if (p == q)
				break;			/* stop when the pointers meet */
			qsort_l2_swop(p, q);/* swop the two unordered elements */
			{					/* then swop the pointers as well! */
				LINKS          *x;
				x = p;
				p = q;
				q = x;
			}
		}
		while (1);				/* and go round again */

		if (p != right)
		{
			q = p->prev;					/* q holds logical position of p */
			qsort_l2_swop(p, right);		/* effectively swops p and right */
			qsort_l2_aux(right->next, p);	/* so use them interchanged here */
			p = q->next;					/* and then restore p afterwards */
		}

		if ((left = left->next) == p)
			return;
		right = p->prev;
	}
}

void            qsort_l2(root, fcmp)
ROOT            root;
int             (*fcmp)( /* void *, void * */ );
{
	qsort_l2_cmp = fcmp;		/* assign once, to save copying at each level */
	qsort_l2_aux(root.first, root.last);
}

#ifdef TEST

/*****************************************\
**                                       **
**  SAMPLE CODE USING QUICKSORT PACKAGE  **
**                                       **
\*****************************************/

typedef struct elem
{
	struct
	{
		struct elem    *next;
		struct elem    *prev;
	}               link;
	int             line_no;
	char            text[1];
}               ELEM;

ELEM           *p;
ROOT            list;			/* globals for printlist */

void            printlist()
{
	for (p = (ELEM *)list.first; p != end(list); p = p->link.next)
	{
		printf("%2d: %s\n", p->line_no, p->text);
	}
}

int             compare(s1, s2)
void           *s1;
void           *s2;
{
	ELEM           *e1 = (ELEM *)s1;
	ELEM           *e2 = (ELEM *)s2;

	return(strcmp(e1->text, e2->text));
}

int             main()
{
	int             line_num = 0;
	char            buffer[82];
	ELEM           *new;

	init(list);

	fprintf(stderr, "> ");
	while (strlen(fgets(buffer, sizeof(buffer), stdin)) != 0)
	{
		new = (ELEM *)malloc(sizeof(ELEM) + strlen(buffer) + 1);
		strcpy(new->text, buffer);
		new->line_no = ++line_num;
		add_tail(list, new);
		fprintf(stderr, "> ");
	}
	fprintf(stderr, "\n");

	printlist();
	qsort_l2(list, compare);
	printlist();

	return(0);
}

#endif	/* TEST */


head	1.1;
access;
symbols;
locks; strict;
comment	@ * @;


1.1
date	91.11.17.22.17.42;	author jl;	state Exp;
branches;
next	;


desc
@@


1.1
log
@Initial revision
@
text
@/*
@@(#)File:            $RCSfile: random.c,v $
@@(#)Version:         $Revision: 1.1 $
@@(#)Last changed:    $Date: 2002-06-14 05:03:47 $
@@(#)Purpose:         I4GL interface to (basic) ANSI C random functions
@@(#)Author:          J Leffler
@@(#)Copyright:       (C) JLSS 1991
*/

/*TABSTOP=4*/

#define I4GL_C
#define RAND_MAX	32767	/* NB: this must be 32767 for algorithm below */

static unsigned long next = 1;

#ifndef lint
static char     sccs[] = "@@(#)$Id: random.c,v 1.1 2002-06-14 05:03:47 afalout Exp $";
#endif

I4GL_C          i4gl_random(n)
int             n;
{
	next = next * 1103515245 + 12345;
	retint((unsigned int) (next / 65536) % (RAND_MAX + 1));
	return (1);
}

I4GL_C          i4gl_seed(n)
int             n;
{
	unsigned int    seed;

	popint(&seed);
	next = seed;
	return (0);
}
@

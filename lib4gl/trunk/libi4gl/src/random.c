/*
@(#)File:            $RCSfile: random.c,v $
@(#)Version:         $Revision: 1.2 $
@(#)Last changed:    $Date: 2002-06-14 09:23:16 $
@(#)Purpose:         I4GL interface to (basic) ANSI C random functions
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1991
*/

/*TABSTOP=4*/

#define I4GL_C
#define RAND_MAX	32767	/* NB: this must be 32767 for algorithm below */

static unsigned long next = 1;

#ifndef lint
static char     sccs[] = "@(#)$Id: random.c,v 1.2 2002-06-14 09:23:16 afalout Exp $";
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

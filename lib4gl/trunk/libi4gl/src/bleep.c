head	1.1;
access;
symbols;
locks; strict;
comment	@ * @;


1.1
date	91.10.16.18.09.07;	author johnl;	state Exp;
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
@@(#)File:            $RCSfile: bleep.c,v $
@@(#)Version:         $Revision: 1.1 $
@@(#)Last changed:    $Date: 2002-06-14 05:03:46 $
@@(#)Purpose:         I4GL: Emit bleep
@@(#)Author:          J Leffler
*/

/*TABSTOP=4*/

#include <stdio.h>
#define I4GL_C
#define BLEEP	'\007'			/* Control-G */

#ifndef lint
static char     sccs[] = "@@(#)$Id: bleep.c,v 1.1 2002-06-14 05:03:46 afalout Exp $";

#endif

I4GL_C  bleep(i)
int     i;
{
	fprintf(stderr, BLEEP);
	return (0);
}
@

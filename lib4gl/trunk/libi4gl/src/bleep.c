/*
@(#)File:            $RCSfile: bleep.c,v $
@(#)Version:         $Revision: 1.2 $
@(#)Last changed:    $Date: 2002-06-14 09:23:16 $
@(#)Purpose:         I4GL: Emit bleep
@(#)Author:          J Leffler
*/

/*TABSTOP=4*/

#include <stdio.h>
#define I4GL_C
#define BLEEP	'\007'			/* Control-G */

#ifndef lint
static char     sccs[] = "@(#)$Id: bleep.c,v 1.2 2002-06-14 09:23:16 afalout Exp $";

#endif

I4GL_C  bleep(i)
int     i;
{
	fprintf(stderr, BLEEP);
	return (0);
}

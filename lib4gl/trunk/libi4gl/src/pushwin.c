head	1.2;
access;
symbols;
locks; strict;
comment	@ * @;


1.2
date	90.04.05.10.51.05;	author john;	state Exp;
branches;
next	1.1;

1.1
date	88.09.08.15.34.36;	author john;	state Exp;
branches;
next	;


desc
@@


1.2
log
@Revise SCCS ID and tidy a little
@
text
@/*
@@(#)File:            $RCSfile: pushwin.c,v $
@@(#)Version:         $Revision: 1.1 $
@@(#)Last changed:    $Date: 2002-06-14 05:03:47 $
@@(#)Purpose:         Maintain stack of I4GL windows
@@(#)Author:          J Leffler
*/

#include <sqlfm.h>

#define STACKSIZE	10
#define I4GL_C		int

typedef struct _EFwindow Window;

extern	Window	*topwin;
static	Window	*stack[STACKSIZE];
static	int		 sp = 0;

#ifndef lint
static	char	sccs[] = "@@(#)$Id: pushwin.c,v 1.1 2002-06-14 05:03:47 afalout Exp $";
#endif

/* Save current window on stack */
I4GL_C	push_window(i)
int	i;
{
	if (sp < STACKSIZE)
		stack[sp++] = topwin;
	return(0);
}

/* Make top window on stack the current window */
I4GL_C	pop_window(i)
int	i;
{
	if (sp > 0)
		_efwcur(stack[--sp]);
	return(0);
}
@


1.1
log
@Initial revision
@
text
@d2 5
a6 5
@@(#)	File:			$RCSfile: pushwin.c,v $
@@(#)	Version:		$Revision: 1.1 $
@@(#)	Last changed:	$Date: 2002-06-14 05:03:47 $
@@(#)	Purpose:		Maintain stack of I4GL windows
@@(#)	Author:			J Leffler
d24 1
a24 4
/*
	Purpose:	Save current window on stack
*/

d33 1
a33 4
/*
	Purpose:	Make top window on stack the current window
*/

@

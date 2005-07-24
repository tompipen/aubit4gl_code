/*
@(#)File:            $RCSfile: pushwin.c,v $
@(#)Version:         $Revision: 1.2 $
@(#)Last changed:    $Date: 2002-06-14 09:23:16 $
@(#)Purpose:         Maintain stack of I4GL windows
@(#)Author:          J Leffler
*/

#include <sqlfm.h>

#define STACKSIZE	10
#define I4GL_C		int

typedef struct _EFwindow Window;

extern	Window	*topwin;
static	Window	*stack[STACKSIZE];
static	int		 sp = 0;

#ifndef lint
static	char	sccs[] = "@(#)$Id: pushwin.c,v 1.2 2002-06-14 09:23:16 afalout Exp $";
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

head	1.4;
access;
symbols;
locks; strict;
comment	@ * @;


1.4
date	90.02.09.09.51.19;	author john;	state Exp;
branches;
next	1.3;

1.3
date	90.02.09.09.20.11;	author john;	state Exp;
branches;
next	1.2;

1.2
date	89.08.02.14.09.44;	author john;	state Exp;
branches;
next	1.1;

1.1
date	89.08.02.13.59.35;	author john;	state Exp;
branches;
next	;


desc
@@


1.4
log
@Use _winredraw -- it lets fglgo link and still works;
Use curscr instead of stdscr
@
text
@/*
	@@(#)$Id: redraw.c,v 1.1 2002-06-14 05:03:47 afalout Exp $
	@@(#)Informix-4GL Screen Redraw
	@@(#)RDS Curses Structure for ISQL 2.10 or I4GL 1.10
	@@(#)Author: JL
*/

#include <stdio.h>
#include "rdscurses.h"

#define	clearok(win,bf)	 (win->_clear = bf)
#define TRUE 1

#ifndef lint
static	char	sccs[] = "@@(#)$Id: redraw.c,v 1.1 2002-06-14 05:03:47 afalout Exp $";
#endif

/*
** I4GL Interface: CALL redraw_screen()
*/
int	redraw_screen(i)
int	i;
{
	clearok(curscr, TRUE);
	_winredraw(curscr);
	return(0);
}
@


1.3
log
@Modify this to use curscr -- also wrefresh
@
text
@d25 1
a25 1
	wrefresh(curscr);
@


1.2
log
@This version seems to work
@
text
@d24 2
a25 2
	clearok(stdscr, TRUE);
	_winredraw(stdscr);
@


1.1
log
@Initial revision
@
text
@d11 3
d24 1
@

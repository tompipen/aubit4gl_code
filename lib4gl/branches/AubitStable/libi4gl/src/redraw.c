/*
	@(#)$Id: redraw.c,v 1.2 2002-06-14 09:23:16 afalout Exp $
	@(#)Informix-4GL Screen Redraw
	@(#)RDS Curses Structure for ISQL 2.10 or I4GL 1.10
	@(#)Author: JL
*/

#include <stdio.h>
#include "rdscurses.h"

#define	clearok(win,bf)	 (win->_clear = bf)
#define TRUE 1

#ifndef lint
static	char	sccs[] = "@(#)$Id: redraw.c,v 1.2 2002-06-14 09:23:16 afalout Exp $";
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

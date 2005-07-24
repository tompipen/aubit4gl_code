/*
	@(#)$Id: scrdump.c,v 1.2 2002-06-14 09:23:17 afalout Exp $
	@(#)Informix-4GL Screen Dump
	@(#)Author: JL
*/

#include <stdio.h>
#include "rdscurses.h"

#define NIL(x)	((x)0)

#ifndef lint
static	char	sccs[] = "@(#)$Id: scrdump.c,v 1.2 2002-06-14 09:23:17 afalout Exp $";
#endif

static	void	scrdump();

/*
** I4GL Interface: CALL screendump("dumpfile")
*/
int	screendump(i)
int	i;
{
	FILE *fp;
	char  filename[256];

	if (i == 1)
	{
		popstring(filename, sizeof(filename));
		if ((fp = fopen(filename, "w")) != NIL(FILE *))
		{
			scrdump(fp);
		}
		fclose(fp);
	}
	return(0);
}

static	void	scrdump(fp)
FILE *fp;
{
	int	nrows, ncols,i,j;
	int	c;

	if (curscr == 0)
		return;

	nrows = curscr->_maxy;
	ncols = curscr->_maxx;

	for (i = 0; i < nrows; i++)
	{
		for (j = 0; j < ncols; j++)
		{
			wmove(curscr, i, j);
			c = winch(curscr);
			putc(c, fp);
		}
		putc('\n', fp);
	}
}

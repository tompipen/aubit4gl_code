head	1.6;
access;
symbols;
locks; strict;
comment	@ * @;


1.6
date	90.02.09.08.11.30;	author john;	state Exp;
branches;
next	1.5;

1.5
date	90.02.08.19.05.17;	author john;	state Exp;
branches;
next	1.4;

1.4
date	89.08.03.10.03.59;	author john;	state Exp;
branches;
next	1.3;

1.3
date	88.07.27.13.06.10;	author john;	state Exp;
branches;
next	1.2;

1.2
date	88.07.27.13.01.01;	author john;	state Exp;
branches;
next	1.1;

1.1
date	88.06.07.18.57.11;	author john;	state Exp;
branches;
next	;


desc
@@


1.6
log
@Use curscr for whole screen
@
text
@/*
	@@(#)$Id: scrdump.c,v 1.1 2002-06-14 05:03:47 afalout Exp $
	@@(#)Informix-4GL Screen Dump
	@@(#)Author: JL
*/

#include <stdio.h>
#include "rdscurses.h"

#define NIL(x)	((x)0)

#ifndef lint
static	char	sccs[] = "@@(#)$Id: scrdump.c,v 1.1 2002-06-14 05:03:47 afalout Exp $";
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
@


1.5
log
@Make interface to screendump work with both C4GL and RDS
@
text
@d45 1
a45 1
	if (stdscr == 0)
d48 2
a49 2
	nrows = stdscr->_maxy;
	ncols = stdscr->_maxx;
d55 2
a56 2
			wmove(stdscr, i, j);
			c = winch(stdscr);
@


1.4
log
@Simplify
@
text
@d19 1
a19 1
** I4GL Interface: CALL screen_dump("dumpfile")
d21 1
a21 1
int	screen_dump(i)
@


1.3
log
@Pride goeth before a fall; now it compiles
@
text
@a3 1
	@@(#)RDS Curses Structure for ISQL 2.10 or I4GL 1.10
a41 1
	RDSWINDOW	*window;
d45 1
a45 4
	window = stdscr;
	if (window == NIL(RDSWINDOW *))
	{
		fprintf(fp, "No current window\n");
a46 1
	}
d48 2
a49 2
	nrows = window->_maxy;
	ncols = window->_maxx;
d55 2
a56 2
			wmove(window, i, j);
			c = winch(window);
@


1.2
log
@It works! Reorganize
@
text
@d17 2
d20 2
a21 1
** I$GL Interface: CALL screen_dump("dumpfile")
@


1.1
log
@Initial revision
@
text
@a0 1
#include <stdio.h>
d3 3
a5 2
	RDS Curses Structure
	ISQL 2.10 or I4GL 1.10
d7 4
a10 1
#define CHARMASK 0x7F
d13 2
a14 5
typedef char bool;
#ifdef OLD
typedef char	scrchar;
#else
typedef short	scrchar;
d17 3
a19 22
typedef struct rds_win_st
{
	short	  _cury;
	short	  _curx;
	short	  _maxy;
	short	  _maxx;
	short	  _begy;
	short	  _begx;
	short	  _flags;
	bool	  _clear;
	bool	  _leave;
	bool	  _scroll;
	scrchar **_y;
	short    *_firstch;
	short	 *_lastch;
	short	_attr;
}	RDSWINDOW;

extern RDSWINDOW   *stdscr, *curscr;


fgl_dump(i)
d23 3
a25 1
	if ( i == 0)
d27 2
a28 1
		if ((fp = fopen("screen.dump", "w")) != NIL(FILE *))
a29 1
			setbuf(fp, NIL(char *));
d37 1
a37 1
scrdump(fp)
a40 1
	scrchar	**scrbase;
d42 1
a44 4
	/*
	if (window == NIL(RDSWINDOW *))
		window = curscr;
	*/
d47 1
a47 1
		fprintf(stderr, "No current window\r\n");
a49 1
	odump((char *) window, sizeof(*window), fp);
a50 1
	scrbase = window->_y;
a52 10
	if (scrbase = NIL(scrchar **))
	{
		fprintf(stderr, "Screen arrays for window not defined\r\n");
		return;
	}

	fprintf(fp, "screen: %d x %d\n", nrows, ncols);
	for (i = 0; i < nrows; i++)
		fprintf(fp, "%2d 0x%08x\n", i, scrbase[i]);
	putc('\n', fp);
a55 5
		if (scrbase[i] == NIL(scrchar *))
		{
			fprintf(stderr, "Invalid row %d\n", i);
			return;
		}
d58 3
a60 2
			fprintf(fp, "%02d %02d %04x\n", i, j, (scrbase[i][j] & 0xFFFF));
			/* putc(scrbase[i][j] & CHARMASK, fp); */
a63 14
}

odump(s, l, fp)
char	 *s;
int		l;
FILE 	*fp;
{
	int	i;
	for (i = 0; i < l; i++)
	{
		fprintf(fp, "%3d = 0x%02x  = %c\n", *s, *s, *s);
		s++;
	}
	putc('\n', fp);
@

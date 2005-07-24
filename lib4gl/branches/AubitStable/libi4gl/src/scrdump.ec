/*
** @(#)$Id: scrdump.ec,v 1.2 2002-06-14 09:23:17 afalout Exp $
** @(#)Informix-4GL Screen Dump
** @(#)Author: JL plus Scott Ellard
*/

/*
**	From: davek@newjersey (David Kosenko)
**	Message-Id: <9011131708.AA20100@newjersey.>
**	To: tech@newjersey
**	Subject: Re: Printscreen with 4GL
**
**	What follows is a C function written by the legendary Scott Ellard.
**	You call it from 4gl as you would any other C function, and include it in
**	your compile line when compiling your 4gl program.
**
**	Dave Kosenko
**
**	Date: Thu, 25 Jul 91 12:43:50 CDT
**	From: markj@infmxchi (Mark Jeske)
**	Message-Id: <9107251743.AA19568@infmxchi.chicago>
**	To: aryeh@grizzly, richm@asterix, tech@asterix
**	Subject: Re: Screendumps in 4GL
**
**	Dave Wable and I found a small bug with this program; it doesn't
**	print the error message line if there is a current error message on
**	the screen.
**
**	Modified 7-9-91 Mark Jeske
**	Added code to include the error message line.
**
**	Modified 1991-08-14 J Leffler
**	Integrated into existing (rather more primitive) version of code.
**	Removed dependency on rdscurses.h.  Changed extension to .ec for
**	convenience when compiling.
*/

#include <stdio.h>
#include <sqlfm.h>

/* BEGIN stuff taken from /s/src/sql2.10.03/color/rdsterm.h */

#define	bool		char
#define	CHAR		short
#define	_ATTRIBUTE	(0x7f00)
#define	_CHARACTER	(0x00ff)
#define _GRAPHMODE	(0x8000)

typedef struct window			/* (I made this a typedef) */
{
	short           _cury;
	short           _curx;
	short           _maxy;
	short           _maxx;
	short           _begy;
	short           _begx;
	short           _flags;
	bool            _clear;
	bool            _leave;
	bool            _scroll;
	CHAR          **_y;
	short          *_firstch;
	short          *_lastch;
	short           _attr;
}               WINDOW;

/* END stuff taken from /s/src/sql2.10.03/color/rdsterm.h */

extern _EFwindow *topwin;
extern _EFwindow *botwin;
extern _EFwindow *_Wscreen;
extern WINDOW  *_efbigwin;
extern char    *GB;
extern WINDOW  *errwin;
extern int      _errwclr;

#define NIL(x)	((x)0)

#ifndef lint
static	char	sccs[] = "@(#)$Id: scrdump.ec,v 1.2 2002-06-14 09:23:17 afalout Exp $";
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
			fclose(fp);
		}
	}
	return(0);
}

static	void	scrdump(fp)
FILE *fp;
{
	register _EFwindow *scr;
	register WINDOW *win;
	register CHAR **line;
	register CHAR  *data;
	register int    y;
	register int    x;
	register char   c;

	if (topwin == _Wscreen)
	{
		/* the user is looking at the "screen" */
		win = (WINDOW *) _Wscreen->win;
	}
	else
	{
		/* the user is looking at one or more "windows" */
		win = _efbigwin;
		for (scr = botwin; scr != (_EFwindow *) 0;
			 scr = (_EFwindow *) scr->upper)
		{
			overwrite((WINDOW *) scr->win, win);
		}
	}
	if (!_errwclr)
		overwrite(errwin, win);

	for (y = 0, line = win->_y; y < win->_maxy; y++, line++)
	{
		for (x = 0, data = *line; x < win->_maxx; x++, data++)
		{
			c = (char) *data & _CHARACTER;
			if ((*data & _GRAPHMODE) && *GB)
			{
				if (c == GB[0])
					c = '+';
				else if (c == GB[1])
					c = '+';
				else if (c == GB[2])
					c = '+';
				else if (c == GB[3])
					c = '+';
				else if (c == GB[4])
					c = '-';
				else if (c == GB[5])
					c = '|';
			}
			fputc(c, fp);
		}
		fputc('\n', fp);
	}
}

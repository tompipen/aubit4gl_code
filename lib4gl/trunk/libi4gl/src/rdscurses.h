head	1.3;
access;
symbols;
locks; strict;
comment	@ * @;


1.3
date	90.02.09.08.11.12;	author john;	state Exp;
branches;
next	1.2;

1.2
date	89.08.03.09.32.38;	author john;	state Exp;
branches;
next	1.1;

1.1
date	88.07.15.18.18.59;	author john;	state Exp;
branches;
next	;


desc
@@


1.3
log
@Use curscr for whole screen
@
text
@/*
	@@(#)$Id: rdscurses.h,v 1.1 2002-06-14 05:03:47 afalout Exp $
	@@(#)Termcap Curses Structure
	@@(#)Works for simple uses with ISQL 2.10 or I4GL 1.10
	@@(#)Taken from the Nutshell Handbook `Programming with Curses'
*/

#ifndef TERMCAP_WINDOW

typedef char bool;

struct rds_win_st
{
		short   _cury, _curx;
		short   _maxy, _maxx;
		short   _begy, _begx;
		short   _flags;
		bool    _clear;
		bool    _leave;
		bool    _scroll;
		char    **_y;
		short   *_firstch;
		short   *_lastch;
};

#define TERMCAP_WINDOW  struct rds_win_st

extern TERMCAP_WINDOW   *stdscr;
extern TERMCAP_WINDOW   *curscr;

#endif /* TERMCAP_WINDOW */
@


1.2
log
@Redefine where it came from
@
text
@d29 1
@


1.1
log
@Initial revision
@
text
@d2 4
a5 2
	RDS Curses Structure
	ISQL 2.10 or I4GL 1.10
d8 1
a8 1
#ifndef RDSWINDOW
a10 5
#ifdef OLD
typedef char	scrchar;
#else
typedef short	scrchar;
#endif
d14 10
a23 11
        short   _cury, _curx;
        short   _maxy, _maxx;
        short   _begy, _begx;
        short   _flags;
        bool    _clear;
        bool    _leave;
        bool    _scroll;
        scrchar **_y;
        short   *_firstch;
        short   *_lastch;
        short   _attr;
d26 1
a26 1
#define RDSWINDOW  struct rds_win_st
d28 1
a28 1
extern RDSWINDOW   *stdscr, *curscr;
d30 1
a30 3
#define CHARMASK 0x7F

#endif
@

/*
	@(#)$Id: rdscurses.h,v 1.1 2002-06-16 07:36:15 afalout Exp $
	@(#)Termcap Curses Structure
	@(#)Works for simple uses with ISQL 2.10 or I4GL 1.10
	@(#)Taken from the Nutshell Handbook `Programming with Curses'
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

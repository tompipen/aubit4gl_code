
/*
 * This file contains the C function c_getkey() which is designed
 * to be called from an Informix 4GL program. The function reads and
 * identifies a keystroke entered from the keyboard relying on the
 * Informix functions rgetkey() and mvcur(). It accepts row and column
 * coordinates as its two arguments. The row and column coordinates are
 * relative to the current Informix 4GL window and give the cursor
 * position where the function will read a keystroke. If the row
 * equals zero then the cursor is not positioned. The function returns
 * a special code used to identify the keystroke and a 1 character
 * string value if the keystroke was a printing character.
 *
 * usage: call c_getkey(y, x) returning key_code, key_string
 */


/*
 * lowlevel key code definitions based on these key code
 * definitions from INFORMIX
 *
 * KEY_UP	2000
 * KEY_DOWN	2001
 * KEY_LEFT	2002
 * KEY_RIGHT	2003
 * KEY_BACKUP	2004
 * KEY_NXTSCR	2005
 * KEY_PRVSCR	2006
 * KEY_LBSAME	2007
 * KEY_HELP	2008
 * KEY_INSCHAR  2009
 * KEY_DELCHAR  2010
 * KEY_INTRPT	2011
 * KEY_HOME	2012
 * KEY_END	2013
 * KEY_INSLINE  2014
 * KEY_DELLINE  2015
 * KEY_ACCEPT	2016
 * KEY_DBINT	2017
 */

# define	K_CHAR		0
# define	K_F0		3000
# define	K_FA		3010
# define	K_FZ		3035
# define	K_ESC		27
# define	K_UP		2000
# define	K_DOWN		2001
# define	K_LEFT		2002
# define	K_RIGHT		2003
# define	K_BACK		2004
# define	K_NPAGE		2005
# define	K_PPAGE		2006
# define	K_LBSAME	2007 /* ??? */
# define	K_HELP		2008
# define	K_INSCHR	2009
# define	K_DELCHR	2010
# define	K_DEL		2011
# define	K_HOME		2012
# define	K_END		2013
# define	K_INSLN		2014
# define	K_DELLN		2015
# define	K_ACCEPT	2016
# define	K_DBINT		2017 /* ??? */

/* 4gl key codes */
# define	CNTL_CODE	1
# define	FUNC_CODE	101
# define	ESC_CODE	135
# define	DEL_CODE	136

/* extended 4gl key codes */
# define	UP_KEY		137
# define	DOWN_KEY	138
# define	LEFT_KEY	139
# define	RIGHT_KEY	140
# define	BACK_KEY	141
# define	D_PAGE_KEY	142
# define	U_PAGE_KEY	143
# define	L_PAGE_KEY	144
# define	R_PAGE_KEY	145
# define	INSC_KEY	146
# define	DELC_KEY	147
# define	HOME_KEY	148
# define	END_KEY		149
# define	INSL_KEY	150
# define	DELL_KEY	151
# define	NO_KEY		152

# define	LI		24
# define	CO		80


# include	"cfun4gl.h"

# ifdef sco_unix
#  include	<tinfo.h>
# else
#  if defined(BIG_MUTHA_HP)
#   include	<curses_colr/curses.h>
#  else
#   define	M_TERMINFO
#   include	<curses.h>
#  endif
# endif


int rgetkey(void);
void clrmsg(void);

function(c_getkey,2,2,1,2)
    RUNNER(fgiusr)
{
    char in_chr[2];
    int code;
    int y_old, x_old;
    int y_get, x_get;

    popint(&x_get);
    popint(&y_get);

    /* clear the return string */
    in_chr[0] = 0;
    in_chr[1] = 0;

    /* position cursor if requested */
    if(y_get)
    {
	/* adjust coordinates to physical screen values */
	--y_get;
	--x_get;

	/* make sure coordinates are in bounds */
	if(y_get < 0 || y_get > LI - 1) y_get = 0;
	if(x_get < 0 || x_get > CO - 1) x_get = 0;

	/* get current position */
	y_old = curscr->_cury;
	x_old = curscr->_curx;

	/* position the cursor - INFORMIX */
	mvcur(y_old, x_old, y_get, x_get);
    }

    /* get the key code - INFORMIX */
    code = rgetkey();
    clrmsg();

    /* reposition the cursor to the starting position - INFORMIX */
    if(y_get)
	mvcur(y_get, x_get, y_old, x_old);


    /* Translate the Key Code */

    if(code >= 32 && code <= 256)		/* printable characters */
    {
	in_chr[0] = (char) code;
	code = K_CHAR;
    }
    else if (code > 0 && code < 27)		/* control keys */
	;
    else if (code >= K_F0 && code <= K_FZ)	/* function keys */
	code = code - K_F0 + FUNC_CODE;
    else
	switch (code)				/* other special keys */
	{
	case K_ESC:
	    code = ESC_CODE;
	    break;

	case K_DEL:
	    code = DEL_CODE;
	    break;

	case K_UP:
	    code = UP_KEY;
	    break;

	case K_DOWN:
	    code = DOWN_KEY;
	    break;

	case K_LEFT:
	case K_LBSAME:
	    code = LEFT_KEY;
	    break;

	case K_RIGHT:
	    code = RIGHT_KEY;
	    break;

	case K_HOME:
	    code = HOME_KEY;
	    break;

	case K_BACK:
	    code = BACK_KEY;
	    break;

	case K_INSCHR:
	    code = INSC_KEY;
	    break;

	case K_DELCHR:
	    code = DELC_KEY;
	    break;

	case K_INSLN:
	    code = INSL_KEY;
	    break;

	case K_DELLN:
	    code = DELL_KEY;
	    break;

	case K_PPAGE:
	    code = U_PAGE_KEY;
	    break;

	case K_NPAGE:
	    code = D_PAGE_KEY;
	    break;

	default:
	    code = NO_KEY;
	    break;
	}

    /* return the keycode and value */
    retint(code);
    retquote(in_chr);

    return 2;
}   /* c_getkey */
/*JFACE*/ int c_getkey_2(int nargs) { return c_getkey(nargs); }

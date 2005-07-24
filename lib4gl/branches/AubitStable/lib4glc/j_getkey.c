/**********************************************************************
 * Copyright (C) 1992-2002 Sanderson Australia Pty. Limited           *
 * All rights reserved.                                               *
 * Use, modification, duplication, and/or distribution of this        *
 * software is limited by the software license agreement.             *
 * Sccsid: %Z% %M%%Y% %Q%%I% %E%                                      *
 **********************************************************************/

# include	"cfun4gl.h"
# define	SQLCA_INCL	/* I4GLC4 */

# if !defined(__STDC__)
#  define	const 
# endif

# include	<locator.h>
# include	<datetime.h>
# include	<fglrep.h>

int fgl_getkey(int);

function(j_getkey,2,2,1,2)
    RUNNER(fglext c_getkey)
{
    short y, x;
    char in_chr[2];
    int code;

    popshort(&x);
    popshort(&y);
    in_chr[0] = 0;
    in_chr[1] = 0;

    (void) fgl_getkey(0);
    popint(&code);

    switch(code)
    {
    case 2017: code = 141; break;
    case    1: code = 146; break;
    case    3: code = 136; break;
    case   10: code = 138; break;
    case   11: code = 137; break;
    case   12: code = 140; break;
    case   24: code = 147; break;
    case   27: code = 135; break;
    case 2011: code = 136; break;
    case 2000: code = 137; break;
    case 2001: code = 138; break;
    case 2002: code = 139; break;
    case 2007: code = 139; break;
    case 2003: code = 140; break;
    case 2012: code = 148; break;
    case 2004: code = 141; break;
    case 2009: code = 146; break;
    case 2010: code = 147; break;
    case 2014: code = 150; break;
    case 2015: code = 151; break;
    case 2006: code = 143; break;
    case 2005: code = 142; break;

    default:
	if(32 <= code && code <= 256)		/* ordinary keys */
	{
	    in_chr[0] = code;
	    code = 0;
	}
	else if(0 < code && code < 27)		/* control keys */
	{
	}
	else if(3000 <= code && code <= 3035)	/* function keys */
	    code += 101 - 3000;
	else
	    code = 152;
	break;
    }

    retint(code);
    retquote(in_chr);

    return 2;
}   /* j_getkey */
/*JFACE*/ int c_getkey_2(int nargs) { return j_getkey(nargs); }

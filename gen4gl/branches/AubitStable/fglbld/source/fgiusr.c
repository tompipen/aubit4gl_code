/*
@(#)File:            $RCSfile: fgiusr.c,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-06-20 09:10:42 $
@(#)Purpose:         User-defined functions for customised FGLGO/FGLDB
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1992
@(#)Product:         :PRODUCT:
*/

/* -- Include Files */

#include "tools/fgicfunc.h"

/* -- Configuration */

#define STR_DLISTS	/* String D-Lists */
#define INT_DLISTS	/* Integer D-Lists */
/* #define DEC_DLISTS	/* Decimal D-Lists */
/* #define DBL_DLISTS	/* Float D-Lists */
#define SET_REPORT	/* Set report output values */

/* -- Declarations */

#ifndef lint
static	char	vers[] = "@(#):PRODUCT:";
static	char	sccs[] = "@(#)$Id: fgiusr.c,v 1.1 2002-06-20 09:10:42 afalout Exp $";
#endif

/* General functions */
extern	int	fgl_getenv();	/* 1 */

/*
[root@aptiva fglbld]# ./fglgo fglbld.4gi
FORMS statement error number -1351.
The function (or report) "fgl_getkey" has already been defined.  Function
and report cannot both have the same name.


>       fgl_getkey() is now in I4GL 7.3x, but was previously a program using
> internal knowledge of the I4GL libraries.
*/
/* extern	int	fgl_getkey(); */	/* 0 */


extern	int	edit_string();	/* 3 */
extern	int	exec();			/* 1 */




/* #ifdef WHERE_ARE_THEY */

/*
>       fgl_msgclose(), fgl_msgopen(), fgl_msgread() are some C code to open
> and read an Informix message file.
*/

extern	int	fgl_msgclose();	/* 1 */
extern	int	fgl_msgopen();	/* 1 */
extern	int	fgl_msgread();	/* 1 */

/*
>       fgldeceng(), fgldecfix(), fgldecsci() are some C code cover functions
> for routines deceng(), decfix() and decsci() which are available from
> SQLCMD.
*/

extern	int	fgldeceng();	/* 4 */
extern	int	fgldecfix();	/* 3 */
extern	int	fgldecsci();	/* 3 */

/*
>       file_access() is a C cover function for the access() system call.
*/

extern	int	file_access();	/* 2 */

/*
>       ljust() is a C function that essentially strips leading blanks.
*/

extern	int	ljust();		/* 1 */

/*
>       sqltypename() is a C cover function that returns the (IDS 7.x or
> earlier) type name corresponding to coltype and collength.
*/


extern	int	sqltypename();	/* 2 */
/* #endif */

extern	int	isdirectory();	/* 1 */
extern	int	mkfilename();	/* 1 */
extern	int	redraw_screen();	/* 0 */
extern	int	round();		/* 2 */
extern	int	screendump();	/* 1 */
extern	int	username();		/* 0 */

#ifdef INT_DLISTS
/* Integer D-Lists */
extern	int	sc_mkint();		/* 0 */
extern	int	sc_rmint();		/* 1 */
extern	int	sc_insint();	/* 2 */
extern	int	sc_updint();	/* 2 */
extern	int	sc_delint();	/* 1 */
extern	int	sc_getint();	/* 3 */
extern	int	sc_zapint();	/* 1 */
extern	int	sc_cntint();	/* 1 */
extern	int	sc_numint();	/* 1 */
#endif /* INT_DLISTS */

#ifdef STR_DLISTS
/* String D-Lists */
extern	int	sc_mkstr();		/* 0 */
extern	int	sc_rmstr();		/* 1 */
extern	int	sc_insstr();	/* 2 */
extern	int	sc_updstr();	/* 2 */
extern	int	sc_delstr();	/* 1 */
extern	int	sc_getstr();	/* 3 */
extern	int	sc_zapstr();	/* 1 */
extern	int	sc_cntstr();	/* 1 */
extern	int	sc_numstr();	/* 1 */
#endif /* STR_DLISTS */

#ifdef DEC_DLISTS
/* Decimal D-Lists */
extern	int	sc_mkdec();		/* 0 */
extern	int	sc_rmdec();		/* 1 */
extern	int	sc_insdec();	/* 2 */
extern	int	sc_upddec();	/* 2 */
extern	int	sc_deldec();	/* 1 */
extern	int	sc_getdec();	/* 3 */
extern	int	sc_zapdec();	/* 1 */
extern	int	sc_cntdec();	/* 1 */
extern	int	sc_numdec();	/* 1 */
#endif /* DEC_DLISTS */

#ifdef DBL_DLISTS
/* Float D-Lists */
extern	int	sc_mkdbl();		/* 0 */
extern	int	sc_rmdbl();		/* 1 */
extern	int	sc_insdbl();	/* 2 */
extern	int	sc_upddbl();	/* 2 */
extern	int	sc_deldbl();	/* 1 */
extern	int	sc_getdbl();	/* 3 */
extern	int	sc_zapdbl();	/* 1 */
extern	int	sc_cntdbl();	/* 1 */
extern	int	sc_numdbl();	/* 1 */
#endif /* DBL_DLISTS */

#ifdef SET_REPORT
extern	int	set_output();	/* 0 */
extern	int	get_rmargin();	/* 0 */
extern	int	get_tmargin();	/* 0 */
extern	int	get_bmargin();	/* 0 */
extern	int	get_lmargin();	/* 0 */
extern	int	get_plength();	/* 0 */
extern	int	set_rmargin();	/* 1 */
extern	int	set_tmargin();	/* 1 */
extern	int	set_bmargin();	/* 1 */
extern	int	set_lmargin();	/* 1 */
extern	int	set_plength();	/* 1 */
#endif /* SET_REPORT */

/***************************************************************************
**
** This table is for user-defined C functions.
** Each initializer has the form:		{	"name", name, nargs },
** For variable number of arguments: set nargs to -(maximum # args)
**
** Be sure to declare name before the table and to leave the
** line of 0's at the end of the table.
**
****************************************************************************
*/

cfunc_t usrcfuncs[] = 
{
	/* General functions */
    
    /* obsolete
	{ "fgl_getkey",		fgl_getkey,		0	},
    */
	/* #ifdef WHERE_ARE_THEY */

	{ "deceng",			fgldeceng,		4	},
	{ "decfix",			fgldecfix,		3	},
	{ "decsci",			fgldecsci,		3	},
	{ "fgl_msgclose",	fgl_msgclose,	1	},
	{ "fgl_msgopen",	fgl_msgopen,	1	},
	{ "fgl_msgread",	fgl_msgread,	1	},
	{ "fgl_msgtext",	fgl_msgread,	1	},	/* SYNONYM for compatability */
	{ "file_access",	file_access,	2	},
	{ "ljust",			ljust,			1	},
	{ "sqltypename",	sqltypename,	2	},
	{ "sqltype",		sqltypename,	2	},	/* SYNONYM for compatability */

	/* #endif */
	{ "editstring",		edit_string,	3	},
	{ "exec",			exec,			1	},
	{ "getenviron",		fgl_getenv,		1	},	/* SYNONYM for compatability */
	{ "isdirectory",	isdirectory,	1	},
	{ "mkfilename",		mkfilename,		1	},
	{ "redraw_screen",	redraw_screen,	0	},
	{ "round",			round,			2	},
	{ "screendump",		screendump,		1	},
	{ "username",		username,		0	},

#ifdef INT_DLISTS
	/* Integer D-Lists */
	{ "sc_mkint",	sc_mkint,	0	},
	{ "sc_rmint",	sc_rmint,	1	},
	{ "sc_insint",	sc_insint,	2	},
	{ "sc_updint",	sc_updint,	2	},
	{ "sc_delint",	sc_delint,	1	},
	{ "sc_getint",	sc_getint,	3	},
	{ "sc_zapint",	sc_zapint,	1	},
	{ "sc_cntint",	sc_cntint,	1	},
	{ "sc_numint",	sc_numint,	1	},
#endif /* INT_DLISTS */

#ifdef STR_DLISTS
	/* String D-Lists */
	{ "sc_mkstr",	sc_mkstr,	0	},
	{ "sc_rmstr",	sc_rmstr,	1	},
	{ "sc_insstr",	sc_insstr,	2	},
	{ "sc_updstr",	sc_updstr,	2	},
	{ "sc_delstr",	sc_delstr,	1	},
	{ "sc_getstr",	sc_getstr,	3	},
	{ "sc_zapstr",	sc_zapstr,	1	},
	{ "sc_cntstr",	sc_cntstr,	1	},
	{ "sc_numstr",	sc_numstr,	1	},
#endif /* STR_DLISTS */

#ifdef DEC_DLISTS
	/* Decimal D-Lists */
	{ "sc_mkdec",	sc_mkdec,	0	},
	{ "sc_rmdec",	sc_rmdec,	1	},
	{ "sc_insdec",	sc_insdec,	2	},
	{ "sc_upddec",	sc_upddec,	2	},
	{ "sc_deldec",	sc_deldec,	1	},
	{ "sc_getdec",	sc_getdec,	3	},
	{ "sc_zapdec",	sc_zapdec,	1	},
	{ "sc_cntdec",	sc_cntdec,	1	},
	{ "sc_numdec",	sc_numdec,	1	},
#endif /* DEC_DLISTS */

#ifdef DBL_DLISTS
	/* Float D-Lists */
	{ "sc_mkdbl",	sc_mkdbl,	0	},
	{ "sc_rmdbl",	sc_rmdbl,	1	},
	{ "sc_insdbl",	sc_insdbl,	2	},
	{ "sc_upddbl",	sc_upddbl,	2	},
	{ "sc_deldbl",	sc_deldbl,	1	},
	{ "sc_getdbl",	sc_getdbl,	3	},
	{ "sc_zapdbl",	sc_zapdbl,	1	},
	{ "sc_cntdbl",	sc_cntdbl,	1	},
	{ "sc_numdbl",	sc_numdbl,	1	},
#endif /* DBL_DLISTS */

#ifdef SET_REPORT
	{ "set_output",		set_output,		0	},
	{ "get_rmargin",	get_rmargin,	0	},
	{ "get_tmargin",	get_tmargin,	0	},
	{ "get_bmargin",	get_bmargin,	0	},
	{ "get_lmargin",	get_lmargin,	0	},
	{ "get_plength",	get_plength,	0	},
	{ "set_rmargin",	set_rmargin,	1	},
	{ "set_tmargin",	set_tmargin,	1	},
	{ "set_bmargin",	set_bmargin,	1	},
	{ "set_lmargin",	set_lmargin,	1	},
	{ "set_plength",	set_plength,	1	},
#endif /* SET_REPORT */

    { 0,			0,			0	}
};

/*
The following can be used on extern declarations 
to produce the initialisers.

Yank the long line into a named buffer -- e.g. "aY
Then apply it to one of the lines -- e.g. @a
After the first line, you can apply it to the rest using & -- e.g. :.,$&

:s/^extern	int	\([a-zA-Z0-9_]*\).*\([0-9][0-9]*\).*$/&
	{ "\1",	\1,	\2	},/

*/

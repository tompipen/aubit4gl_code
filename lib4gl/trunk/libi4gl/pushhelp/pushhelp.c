head	1.2;
access;
symbols;
locks; strict;
comment	@ * @;


1.2
date	88.10.07.15.15.30;	author john;	state Exp;
branches;
next	1.1;

1.1
date	88.09.09.12.31.49;	author john;	state Exp;
branches;
next	;


desc
@@


1.2
log
@Add check to ensure that help file has been set previously
@
text
@/*
@@(#)	File:			$RCSfile: pushhelp.c,v $
@@(#)	Version:		$Revision: 1.1 $
@@(#)	Last changed:	$Date: 2002-06-14 05:03:46 $
@@(#)	Purpose:		Maintain stack of I4GL helpfiles
@@(#)	Author:			J Leffler
*/

#define STACKSIZE	10
#define I4GL_C		int

typedef char	*Filename;

static	Filename	stack[STACKSIZE];
static	Filename	lastfile = (Filename)0;
static	int		 	sp = 0;

#ifndef lint
static	char	sccs[] = "@@(#)$Id: pushhelp.c,v 1.1 2002-06-14 05:03:46 afalout Exp $";
#endif

/*
	Purpose:	Save current helpfile on stack
*/

I4GL_C	push_helpfile(i)
int	i;
{
	if (sp < STACKSIZE && lastfile != (Filename)0)
		stack[sp++] = lastfile;
	return(0);
}

/*
	Purpose:	Make top helpfile on stack the current helpfile
*/

I4GL_C	pop_helpfile(i)
int	i;
{
	if (sp > 0)
		_ef_v_hlpfile(stack[--sp]);
	return(0);
}

/*
	Purpose:	Intercept OPTIONS HELP FILE and store filename
*/

_ef_v_hlpfile(file)
char	*file;
{
	lastfile = file;
	_efhlpfile(file);
}
@


1.1
log
@Initial revision
@
text
@d29 1
a29 1
	if (sp < STACKSIZE)
@

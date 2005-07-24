/*
@(#)	File:			$RCSfile: pushhelp.c,v $
@(#)	Version:		$Revision: 1.2 $
@(#)	Last changed:	$Date: 2002-06-14 09:23:16 $
@(#)	Purpose:		Maintain stack of I4GL helpfiles
@(#)	Author:			J Leffler
*/

#define STACKSIZE	10
#define I4GL_C		int

typedef char	*Filename;

static	Filename	stack[STACKSIZE];
static	Filename	lastfile = (Filename)0;
static	int		 	sp = 0;

#ifndef lint
static	char	sccs[] = "@(#)$Id: pushhelp.c,v 1.2 2002-06-14 09:23:16 afalout Exp $";
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

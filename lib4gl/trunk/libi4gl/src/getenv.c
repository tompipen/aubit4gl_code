head	1.3;
access;
symbols;
locks; strict;
comment	@ * @;


1.3
date	90.04.05.10.50.59;	author john;	state Exp;
branches;
next	1.2;

1.2
date	88.05.03.09.40.04;	author john;	state Exp;
branches;
next	1.1;

1.1
date	88.02.17.10.41.19;	author john;	state Exp;
branches;
next	;


desc
@@


1.3
log
@Revise SCCS ID and tidy a little
@
text
@/*
@@(#)File:            $RCSfile: getenv.c,v $
@@(#)Version:         $Revision: 1.1 $
@@(#)Last changed:    $Date: 2002-06-14 05:03:46 $
@@(#)Purpose:         Get value of environment variable
@@(#)Author:          J Leffler
*/

#define CCHARTYPE	100	/* Strictly from sqltypes.h */
#define NIL(x)	((x)0)

extern	char	*getenv();

#ifndef lint
static	char	sccs[] = "@@(#)$Id: getenv.c,v 1.1 2002-06-14 05:03:46 afalout Exp $";
#endif

/* -- Routine: getenviron		*/
/* -- I4GL: LET kpidir = getenviron("KPIDIRECTORY") */

int	getenviron(i)
int	i;
{
	char	env[33];
	char	*value;

	if (i == 1)
	{
		popstring(env, sizeof(env));
		if ((value = getenv(env)) == NIL(char *))
		{
			value = env;
			rsetnull(CCHARTYPE, value);
		}
	}
	retquote(value);
	return(1);
}
@


1.2
log
@Convert opquote/blankstrip to popstring
@
text
@d2 5
a6 5
@@(#)	File:			$RCSfile: getenv.c,v $
@@(#)	Version:		$Revision: 1.1 $
@@(#)	Last changed:	$Date: 2002-06-14 05:03:46 $
@@(#)	Purpose:		Get value of environment variable
@@(#)	Author:			J Leffler
a8 2
/* -- Constant Definitions	*/

a9 3

/* -- Macro Definitions	*/

a11 2
/* -- Declarations		*/

d17 1
a17 1

a21 1

a22 1

@


1.1
log
@Initial revision
@
text
@d38 1
a38 2
		popquote(env, sizeof(env));
		blankstrip(env, sizeof(env));
@

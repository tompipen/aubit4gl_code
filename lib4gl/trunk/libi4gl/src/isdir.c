head	1.3;
access;
symbols;
locks; strict;
comment	@ * @;


1.3
date	90.04.05.10.51.00;	author john;	state Exp;
branches;
next	1.2;

1.2
date	88.05.03.09.40.07;	author john;	state Exp;
branches;
next	1.1;

1.1
date	88.02.15.20.27.04;	author john;	state Exp;
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
@@(#)File:            $RCSfile: isdir.c,v $
@@(#)Version:         $Revision: 1.1 $
@@(#)Last changed:    $Date: 2002-06-14 05:03:46 $
@@(#)Purpose:         Validate directory name in I4GL
@@(#)Author:          J Leffler
*/

#include <sys/types.h>
#include <sys/stat.h>

typedef struct	stat	Stat;

#ifndef lint
static	char	sccs[] = "@@(#)$Id: isdir.c,v 1.1 2002-06-14 05:03:46 afalout Exp $";
#endif

/* -- Routine: isdirectory		*/
/* -- I4GL: IF isdirectory(pathname) THEN ... */

int	isdirectory(i)
int	i;
{
	Stat	statbuf;
	char	path[65];
	int		status = 0;

	if (i == 1)
	{
		popstring(path, sizeof(path));
		if (stat(path, &statbuf) == 0)
			status = ((statbuf.st_mode & S_IFMT) == S_IFDIR);
	}
	retint(status);
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
@@(#)	File:			$RCSfile: isdir.c,v $
@@(#)	Version:		$Revision: 1.1 $
@@(#)	Last changed:	$Date: 2002-06-14 05:03:46 $
@@(#)	Purpose:		Validate directory name in I4GL
@@(#)	Author:			J Leffler
a8 2
/* -- Include Files		*/

a11 2
/* -- Type Definitions		*/

a13 2
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
		popquote(path, sizeof(path));
		blankstrip(path, sizeof(path));
@

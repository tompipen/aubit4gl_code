head	1.4;
access;
symbols;
locks; strict;
comment	@ * @;


1.4
date	90.04.05.10.51.03;	author john;	state Exp;
branches;
next	1.3;

1.3
date	88.05.03.09.40.13;	author john;	state Exp;
branches;
next	1.2;

1.2
date	88.03.03.12.51.04;	author john;	state Exp;
branches;
next	1.1;

1.1
date	88.03.03.11.56.33;	author john;	state Exp;
branches;
next	;


desc
@@


1.4
log
@Revise SCCS ID and tidy a little
@
text
@/*
@@(#)File:            $RCSfile: mkfile.c,v $
@@(#)Version:         $Revision: 1.1 $
@@(#)Last changed:    $Date: 2002-06-14 05:03:46 $
@@(#)Purpose:         Create temporary file name in I4GL
@@(#)Author:          J Leffler
*/

/* -- Macro definitions		*/

#define NIL(x)	((x)0)

/* -- Declarations		*/

extern	char	*mktemp();

static	char	*deftemplate = "/tmp/dbkpi.XXXXXX";

#ifndef lint
static	char	sccs[] = "@@(#)$Id: mkfile.c,v 1.1 2002-06-14 05:03:46 afalout Exp $";
#endif

/* -- Routine: mkfilename		*/
/* -- I4GL: LET fname = mkfilename("/tmp/trqXXXXXX") */

int	mkfilename(i)
int	i;
{
	char	path[65];
	char	*x1;

	if (i == 1)
	{
		popstring(path, sizeof(path));
		if (!has6xes(path))
			strcpy(path, deftemplate);
		if ((x1 = mktemp(path)) == NIL(char *))
		{
			strcpy(path, deftemplate);
			x1 = mktemp(path);
		}
		retquote(x1);
	}
	else
	{
		strcpy(path, deftemplate);
		retquote(mktemp(path));
	}
	return(1);
}

static	int	has6xes(s)
char	*s;
{
	char	*t;

	while (*s)
	{
		if (*s++ == 'X')
		{
			t = s;
			while (*t == 'X')
				t++;
			if ((t - s) >= 6 - 1) /* s has been incremented! */
				return(1);	/* OK */
			s = t;
		}
	}
	return(0);	/* Not OK */
}
@


1.3
log
@Convert opquote/blankstrip to popstring
@
text
@d2 5
a6 5
@@(#)	File:			$RCSfile: mkfile.c,v $
@@(#)	Version:		$Revision: 1.1 $
@@(#)	Last changed:	$Date: 2002-06-14 05:03:46 $
@@(#)	Purpose:		Create temporary file name in I4GL
@@(#)	Author:			J Leffler
d22 2
a23 2

/* -- Routine: isdirectory		*/
a26 1

a27 1

@


1.2
log
@Make foolproof
@
text
@d36 1
a36 2
		popquote(path, sizeof(path));
		blankstrip(path, sizeof(path));
@


1.1
log
@Initial revision
@
text
@d9 4
d14 3
d32 1
a32 1
	int		status = 0;
d38 4
a41 1
		if (strlen(path) < 6)
d43 3
a45 1
		retquote(mktemp(path));
d49 2
a50 1
		retquote(mktemp(deftemplate));
d53 20
@

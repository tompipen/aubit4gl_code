head	1.3;
access;
symbols;
locks; strict;
comment	@ * @;


1.3
date	90.04.05.10.50.57;	author john;	state Exp;
branches;
next	1.2;

1.2
date	88.12.01.18.10.56;	author john;	state Exp;
branches;
next	1.1;

1.1
date	88.09.13.11.23.14;	author john;	state Exp;
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
@@(#)File:            $RCSfile: exec.c,v $
@@(#)Version:         $Revision: 1.1 $
@@(#)Last changed:    $Date: 2002-06-14 05:03:46 $
@@(#)Purpose:         Implement exec() for I4GL
@@(#)Author:          J Leffler
*/

#define SHELL "/bin/sh"
#define I4GL_C	int

#ifndef lint
static	char	sccs[] = "@@(#)$Id: exec.c,v 1.1 2002-06-14 05:03:46 afalout Exp $";
#endif

I4GL_C	exec(n)
int	n;
{
	int		 i;
	char	 cmd[512]; /* Largest string passable in I4GL */
	char	*argv[4];

	/* Reset terminal characteristics and close log file */
	_efemode();
	fgl_clog();

	/* If called wrongly, exit immediately */
	if (n != 1)
		exit(1);

	/* Find what is to be executed */
	popstring(cmd, sizeof(cmd));

	/* Close unwanted files (all except stdin, stdout, stderr) */
	for (i = 3; i < 20; i++)
		(void) close(i);

	argv[0] = SHELL;
	argv[1] = "-c";
	argv[2] = cmd;
	argv[3] = (char *)0;

	execv(SHELL, argv);
	exit(1);
}
@


1.2
log
@Close log file too
@
text
@d2 5
a6 5
@@(#)	File:			$RCSfile: exec.c,v $
@@(#)	Version:		$Revision: 1.1 $
@@(#)	Last changed:	$Date: 2002-06-14 05:03:46 $
@@(#)	Purpose:		Implement exec() for I4GL
@@(#)	Author:			J Leffler
a16 1

a17 5

/*
	Purpose:	Implement exec for I4GL
*/

@


1.1
log
@Initial revision
@
text
@d29 1
a29 1
	/* Reset terminal characteristics */
d31 1
@

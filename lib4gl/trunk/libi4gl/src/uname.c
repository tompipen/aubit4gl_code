head	1.2;
access;
symbols;
locks; strict;
comment	@ * @;


1.2
date	91.05.09.18.12.15;	author johnl;	state Exp;
branches;
next	1.1;

1.1
date	88.02.25.16.24.53;	author john;	state Exp;
branches;
next	;


desc
@@


1.2
log
@Upgrade
@
text
@/*
@@(#)	File:			$RCSfile: uname.c,v $
@@(#)	Version:		$Revision: 1.1 $
@@(#)	Last changed:	$Date: 2002-06-14 05:03:47 $
@@(#)	Purpose:		I4GL: Find user name -- no reference to database
@@(#)	Author:			J Leffler
*/

/* -- Include Files		*/

#include <pwd.h>
#include <string.h>

struct passwd	*getpwuid();
static char		 u_name[10];

#ifndef lint
static char sccs[] = "@@(#)$Id: uname.c,v 1.1 2002-06-14 05:03:47 afalout Exp $";
#endif

/* username: return name of user */
/* I4GL: LET uname = username() */

int	username(i)
int	i;
{
	struct passwd	*p;

	if (u_name[0] == '\0')
	{
		p = getpwuid(getuid());
		strncpy(u_name, p->pw_name, sizeof(u_name));
	}
	retquote(u_name);
	return(1);
}
@


1.1
log
@Initial revision
@
text
@d15 5
a24 1

a25 1

d29 6
a34 2
	p = getpwuid(getuid());
	retquote(p->pw_name);
@

/*
@(#)	File:			$RCSfile: uname.c,v $
@(#)	Version:		$Revision: 1.1 $
@(#)	Last changed:	$Date: 2002-06-20 09:10:42 $
@(#)	Purpose:		I4GL: Find user name -- no reference to database
@(#)	Author:			J Leffler
*/

/* -- Include Files		*/

#include <pwd.h>
#include <string.h>

struct passwd	*getpwuid();
static char		 u_name[10];

#ifndef lint
static char sccs[] = "@(#)$Id: uname.c,v 1.1 2002-06-20 09:10:42 afalout Exp $";
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

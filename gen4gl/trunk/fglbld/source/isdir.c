/*
@(#)File:            $RCSfile: isdir.c,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-06-20 09:10:42 $
@(#)Purpose:         Validate directory name in I4GL
@(#)Author:          J Leffler
*/

#include <sys/types.h>
#include <sys/stat.h>

typedef struct	stat	Stat;

#ifndef lint
static	char	sccs[] = "@(#)$Id: isdir.c,v 1.1 2002-06-20 09:10:42 afalout Exp $";
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

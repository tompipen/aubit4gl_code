head	1.3;
access;
symbols;
locks; strict;
comment	@ * @;


1.3
date	90.04.05.10.51.01;	author john;	state Exp;
branches;
next	1.2;

1.2
date	88.05.03.09.40.09;	author john;	state Exp;
branches;
next	1.1;

1.1
date	88.02.15.20.27.10;	author john;	state Exp;
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
@@(#)File:            $RCSfile: isfile.c,v $
@@(#)Version:         $Revision: 1.1 $
@@(#)Last changed:    $Date: 2002-06-14 05:03:46 $
@@(#)Purpose:         Validate file name in I4GL
@@(#)Author:          J Leffler
*/

/* -- Include Files		*/

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

/* -- Constant Definitions	*/

#define SCCSFILESIZE	256	/* Max length for SCCS file name		*/
#define SCCS1	"SCCS/"		/* directory containing SCCS files 		*/
#define SCCS2	"sccs/"		/* alternative directory for SCCS files	*/

/* -- Macro Definitions		*/

#define NIL(x)			((x)0)

/* -- Type Definitions		*/

typedef struct	stat	Stat;

/* -- Declarations		*/

void	strinsert();
void	split_name();

#ifndef lint
static	char	sccs[] = "@@(#)$Id: isfile.c,v 1.1 2002-06-14 05:03:46 afalout Exp $";
#endif

/* -- Routine: isfile			*/
/* -- I4GL: IF isfile(pathname, basename, ext, sccsflag) THEN ... */
/* -- sccsflag = 1 => try looking for SCCS version of file */

int	isfile(i)
int	i;
{
	Stat	statbuf;
	char	file[15];
	char	ext[5];
	char	path[65];
	char	fullpath[79];
	int		status = 0;
	int		sccs;

	if (i == 4)
	{
		popint(&sccs);
		popstring(ext, sizeof(ext));
		popstring(file, sizeof(file));
		popstring(path, sizeof(path));
		(void)sprintf(fullpath,"%s/%s%s", path, file, ext);
		if (stat(fullpath, &statbuf) == 0)
			status = ((statbuf.st_mode & S_IFMT) == S_IFREG);
		else if (sccs)
			status = sccsfile(fullpath);
	}
	retint(status);
	return(1);
}

/*
**	sccsfile -- try to find a SCCS file corresponding to name
**
**	look in same directory as specified file
**	then in subdirectory SCCS1 of specified directory
**	then in subdirectory SCCS2 of specified directory
**	then give up and return original name
**
**	name is InOut because split_name() can strip trailing slashes
*/

static int	sccsfile(name)
char	*name;		/* InOut:	Name to be sought	*/
{
	char	base[SCCSFILESIZE];
	char	dir[SCCSFILESIZE];
	char	sccsname[SCCSFILESIZE];

	/* Do not need check on plain name -- it cannot be found */
	split_name(name, base, dir);

	/* Insert s. if missing */
	if (strncmp(base, "s.", 2))
		(void)strinsert(base, "s.");
	
	(void)sprintf(sccsname, "%s%s", dir, base);
	if (access(sccsname, 0) == 0)
		return(1);
	(void)sprintf(sccsname, "%s%s%s", dir, SCCS1, base);
	if (access(sccsname, 0) == 0)
		return(1);
	(void)sprintf(sccsname, "%s%s%s", dir, SCCS2, base);
	if (access(sccsname, 0) == 0)
		return(1);

	/* Cannot find SCCS file corresponding to name */
	return(0);
}

/*
**	split_name -- break name into base and directory
**	name is shortened by any trailing slashes.
**	base and dir are in allocated space.
*/

static void	split_name(name, base, dir)
char	*name;		/* Inout: Name to be split			*/
char	*base;		/* Out:   Pointer to basename		*/
char	*dir;		/* Out:   Pointer to directory name	*/
{
	int		 l;
	char	*p;

	l = strlen(name);

	/* Remove trailing slashes -- and worry about "/" */
	while (name[l-1] == '/' && l > 1)
		name[--l] = '\0';

	/* Split name into directory and basename */
	if ((p = strrchr(name, '/')) == name)
	{	/* Using root -- and the best of British */
		strcpy(dir, "");
		strcpy(base, "/");
	}
	else if (p != NIL(char *))
	{	/* Ordinary path name */
		strcpy(base, p+1);
		*p = '\0';
		strcpy(dir, name);
		strcat(dir, "/");
		*p = '/';
	}
	else
	{	/* Plain file name */
		strcpy(base, name);
		strcpy(dir, "");
	}
}

/*
**	strinsert -- Insert string t before string s
*/

static void strinsert(s, t)
char	*s;		/* InOut: String to be altered */
char	*t;		/* In:    String to be inserted */
{
	int		i = strlen(t);
	int		j = strlen(s);
	char	*p;
	char	*q;

	p = s + i + j;	/* Beyond the string s */
	q = s + j; 		/* At the null of s */
	while (q >= s)
		*p-- = *q--;
	while (*t)
		*s++ = *t++;
}
@


1.2
log
@Convert opquote/blankstrip to popstring
@
text
@d2 5
a6 5
@@(#)	File:			$RCSfile: isfile.c,v $
@@(#)	Version:		$Revision: 1.1 $
@@(#)	Last changed:	$Date: 2002-06-14 05:03:46 $
@@(#)	Purpose:		Validate file name in I4GL
@@(#)	Author:			J Leffler
a43 1

a44 1

@


1.1
log
@Initial revision
@
text
@d59 3
a61 6
		popquote(ext, sizeof(ext));
		blankstrip(ext, sizeof(ext));
		popquote(file, sizeof(file));
		blankstrip(file, sizeof(file));
		popquote(path, sizeof(path));
		blankstrip(path, sizeof(path));
@

/*
@(#)File:            $RCSfile: mkfile.c,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-06-20 09:10:42 $
@(#)Purpose:         Create temporary file name in I4GL
@(#)Author:          J Leffler
*/

/* -- Macro definitions		*/

#define NIL(x)	((x)0)

/* -- Declarations		*/

extern	char	*mktemp();

static	char	*deftemplate = "/tmp/dbkpi.XXXXXX";

#ifndef lint
static	char	sccs[] = "@(#)$Id: mkfile.c,v 1.1 2002-06-20 09:10:42 afalout Exp $";
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

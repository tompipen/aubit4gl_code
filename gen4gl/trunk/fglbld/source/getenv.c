/*
@(#)File:            $RCSfile: getenv.c,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-06-20 09:10:42 $
@(#)Purpose:         Get value of environment variable
@(#)Author:          J Leffler
*/

#define CCHARTYPE	100	/* Strictly from sqltypes.h */
#define NIL(x)	((x)0)

extern	char	*getenv();

#ifndef lint
static	char	sccs[] = "@(#)$Id: getenv.c,v 1.1 2002-06-20 09:10:42 afalout Exp $";
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

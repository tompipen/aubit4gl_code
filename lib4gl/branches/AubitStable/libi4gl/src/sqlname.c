/*
	@(#)$Id: sqlname.c,v 1.2 2002-06-14 09:23:17 afalout Exp $
	@(#)JLSS Informix Tools: General Library
	@(#)I4GL Interface to SQLTYPE(3J)
	@(#)Author: J Leffler
*/

#ifndef lint
static char sccs[] = "@(#)$Id: sqlname.c,v 1.2 2002-06-14 09:23:17 afalout Exp $";
#endif

extern char *sqltype();

int	sqltypename(i)
int		i;
{
	int n;
	int		collen;
	int		coltype;

	if (n != 2)
	{
		retquote("");
		return(1);
	}
	popint(&collen);
	popint(&coltype);

	retquote(sqltype(coltype, collen));
	return(1);
}

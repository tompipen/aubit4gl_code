head	1.3;
access;
symbols;
locks; strict;
comment	@ * @;


1.3
date	91.05.09.18.09.45;	author johnl;	state Exp;
branches;
next	1.2;

1.2
date	89.11.28.10.07.39;	author john;	state Exp;
branches;
next	1.1;

1.1
date	88.07.12.12.30.46;	author john;	state Exp;
branches;
next	;


desc
@@


1.3
log
@Rename function; use "standard" C sqltype() function
@
text
@/*
	@@(#)$Id: sqlname.c,v 1.1 2002-06-14 05:03:47 afalout Exp $
	@@(#)JLSS Informix Tools: General Library
	@@(#)I4GL Interface to SQLTYPE(3J)
	@@(#)Author: J Leffler
*/

#ifndef lint
static char sccs[] = "@@(#)$Id: sqlname.c,v 1.1 2002-06-14 05:03:47 afalout Exp $";
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
@


1.2
log
@Fix glitch in format of DECIMAL(n) fields
@
text
@d3 3
a5 1
	@@(#)Convert type and length from Syscolumns to string
d8 3
a10 2
#include "sqltypes.h"
#define I4GL_C
d12 1
a12 12
static char	*sqltypes[] = 
{
	"CHAR",
	"SMALLINT",
	"INTEGER",
	"FLOAT",
	"SMALLFLOAT",
	"DECIMAL",
	"SERIAL",
	"DATE",
	"MONEY"
};
d14 2
a15 2
I4GL_C	sqltype(n)
int	n;
d17 2
a18 1
	char	typestr[30];
a19 3
	int		collen;
	int		precision;
	int		scale;
d29 1
a29 30
	if (coltype >= 256)
		coltype -= 256;	/* Indicates a not null column */

	switch (coltype)
	{
	case SQLCHAR:
		sprintf(typestr, "%s(%d)", sqltypes[coltype], collen);
		break;
	case SQLSMINT:
	case SQLINT:
	case SQLFLOAT:
	case SQLSMFLOAT:
	case SQLDATE:
	case SQLSERIAL:
		strcpy(typestr, sqltypes[coltype]);
		break;
	case SQLDECIMAL:
	case SQLMONEY:
		precision = (collen >> 8) & 0xFF;
		scale = (collen & 0xFF);
		if (scale == 0xFF)
			sprintf(typestr, "%s(%d)", sqltypes[coltype], precision);
		else
			sprintf(typestr, "%s(%d,%d)", sqltypes[coltype], precision, scale);
		break;
	default:
		sprintf(typestr, "Unknown type %d, len %d", coltype, collen);
		break;
	}
	retquote(typestr);
@


1.1
log
@Initial revision
@
text
@d6 1
a6 1
#include <sqltypes.h>
d59 4
a62 1
		sprintf(typestr, "%s(%d,%d)", sqltypes[coltype], precision, scale);
@

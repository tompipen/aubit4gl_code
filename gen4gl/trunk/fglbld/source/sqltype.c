/*
	@(#)$Id: sqltype.c,v 1.1 2002-06-20 09:10:42 afalout Exp $
	@(#)Convert type and length from Syscolumns to string


This file is NOT compiled by makefile - but is needed to make a distribution
so it's probaly obsolete ?


*/

#include "sqltypes.h"
#define I4GL_C

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

I4GL_C	sqltype(n)
int	n;
{
	char	typestr[30];
	int		coltype;
	int		collen;
	int		precision;
	int		scale;

	if (n != 2)
	{
		retquote("");
		return(1);
	}
	popint(&collen);
	popint(&coltype);

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
	return(1);
}

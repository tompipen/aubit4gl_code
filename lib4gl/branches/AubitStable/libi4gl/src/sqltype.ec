/*
@(#)File:            $RCSfile: sqltype.ec,v $
@(#)Version:         $Revision: 1.2 $
@(#)Last changed:    $Date: 2002-06-14 09:23:17 $
@(#)Purpose:         Convert type and length from Syscolumns to string
@(#)Author:          J Leffler
*/

/*TABSTOP=4*/

#ifndef lint
static	char	sccs[] = "@(#)$Id: sqltype.ec,v 1.2 2002-06-14 09:23:17 afalout Exp $";
#endif

#include <stdio.h>
#include <sqltypes.h>
#include <datetime.h>

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
	"MONEY",
	"NULL",
	"DATETIME",
	"BYTE IN TABLE",
	"TEXT IN TABLE",
	"VARCHAR",
	"INTERVAL"
};

static	char	*dt_ext[] =
{
	"YEAR",
	"{unknown}",
	"MONTH",
	"{unknown}",
	"DAY",
	"{unknown}",
	"HOUR",
	"{unknown}",
	"MINUTE",
	"{unknown}",
	"SECOND",
	"FRACTION(1)",
	"FRACTION(2)",
	"FRACTION(3)",
	"FRACTION(4)",
	"FRACTION(5)"
};

static char	typestr[30];

char	*sqltype(coltype, collen)
int		coltype;
int		collen;
{
	int		precision;
	int		dt_fr;
	int		dt_to;
	int		dt_ld;
	int		vc_min;
	int		vc_max;
	int		scale;

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
	case SQLNULL:
	case SQLTEXT:
	case SQLBYTES:
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
	case SQLVCHAR:
		vc_min = (collen >> 8) & 0xFF;
		vc_max = (collen & 0xFF);
		if (vc_min == 0)
			sprintf(typestr, "%s(%d)", sqltypes[coltype], vc_max);
		else
			sprintf(typestr, "%s(%d,%d)", sqltypes[coltype], vc_max, vc_min);
		break;
	case SQLDTIME:
		dt_fr = TU_START(collen);
		dt_to = TU_END(collen);
		sprintf(typestr, "%s %s TO %s", sqltypes[coltype], dt_ext[dt_fr],
				dt_ext[dt_to]);
		break;
	case SQLINTERVAL:
		dt_fr = TU_START(collen);
		dt_to = TU_END(collen);
		dt_ld = TU_FLEN(collen);
		sprintf(typestr, "%s %s(%d) TO %s", sqltypes[coltype], dt_ext[dt_fr],
				dt_ld, dt_ext[dt_to]);
		break;
	default:
		sprintf(typestr, "Unknown type %d, len %d", coltype, collen);
		break;
	}
	return(typestr);
}

#ifdef TEST

#define DIM(x)	(sizeof(x)/sizeof(*(x)))

typedef struct	Typelist
{
	char	*code;
	int		coltype;
	int		collen;
}	Typelist;

static Typelist	types[] =
{
	{	"serial",							262,		4		},
	{	"char",								0,			10		},
	{	"date",								7,			4		},
	{	"decimal",							5,			4351	},
	{	"decimal(16)",						5,			4351	},
	{	"decimal(32,14)",					5,			8206	},
	{	"float",							3,			8		},
	{	"integer",							2,			4		},
	{	"money",							8,			4098	},
	{	"money(16,2)",						8,			4098	},
	{	"smallfloat",						4,			4		},
	{	"smallint",							1,			2		},
	{	"varchar(128)",						13,			128		},
	{	"varchar(128,64)",					13,			16512	},
	{	"datetime day to day",				10,			580		},
	{	"datetime hour to fraction(3)",		10,			2413	},
	{	"datetime minute to fraction(3)",	10,			1933	},
	{	"datetime month to fraction(3)",	10,			3373	},
	{	"datetime second to fraction(5)",	10,			1967	},
	{	"datetime second to second",		10,			682		},
	{	"datetime year to fraction(3)",		10,			4365	},
	{	"datetime year to fraction(5)",		10,			4879	},
	{	"datetime year to year",			10,			1024	},
	{	"interval day(4) to fraction(3)",	14,			3405	},
	{	"interval day(9) to fraction(5)",	14,			5199	},
	{	"interval day to fraction(5)",		14,			3407	},
	{	"interval hour(4) to fraction(3)",	14,			2925	},
	{	"interval hour(6) to fraction(5)",	14,			3951	},
	{	"interval hour to fraction(5)",		14,			2927	},
	{	"byte in table",					11,			56		},
	{	"text in table",					12,			56		}
};

main()
{
	int             i;

	printf("%-32s %4s %6s   %s\n", "Code", "Type", "Length", "Full type");
	for (i = 0; i < DIM(types); i++)
	{
		printf("%-32s %4d %6d = %s\n",
			   types[i].code, types[i].coltype, types[i].collen,
			   sqltype(types[i].coltype, types[i].collen));
		fflush(stdout);
	}
	return (0);
}
#endif	/* TEST */

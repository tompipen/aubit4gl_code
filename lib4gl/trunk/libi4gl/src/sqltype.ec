head	1.6;
access;
symbols;
locks; strict;
comment	@# @;


1.6
date	91.03.22.13.36.39;	author johnl;	state Exp;
branches;
next	1.5;

1.5
date	91.03.13.13.32.43;	author johnl;	state Exp;
branches;
next	1.4;

1.4
date	91.03.13.13.31.39;	author johnl;	state Exp;
branches;
next	1.3;

1.3
date	90.04.05.12.04.53;	author john;	state Exp;
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


1.6
log
@Correct interval handling; add test rig
@
text
@/*
@@(#)File:            $RCSfile: sqltype.ec,v $
@@(#)Version:         $Revision: 1.1 $
@@(#)Last changed:    $Date: 2002-06-14 05:03:47 $
@@(#)Purpose:         Convert type and length from Syscolumns to string
@@(#)Author:          J Leffler
*/

/*TABSTOP=4*/

#ifndef lint
static	char	sccs[] = "@@(#)$Id: sqltype.ec,v 1.1 2002-06-14 05:03:47 afalout Exp $";
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
@


1.5
log
@Without checking, of course
@
text
@d9 2
d15 1
d17 1
d67 1
d109 2
a110 3
	case SQLINTERVAL:
		dt_fr = (collen >> 4) & 0xF;
		dt_to = (collen & 0xF);
d113 8
d127 62
@


1.4
log
@Convert to real C interface
@
text
@a66 3
	collen  = len;
	coltype = type;

@


1.3
log
@Upgrade to include Version 4.00 data types
@
text
@d13 1
a13 2
#include "sqltypes.h"
#define I4GL_C
d54 5
a58 2
I4GL_C	sqltype(n)
int	n;
a59 3
	char	typestr[30];
	int		coltype;
	int		collen;
d67 2
a68 7
	if (n != 2)
	{
		retquote("");
		return(1);
	}
	popint(&collen);
	popint(&coltype);
d116 1
a116 2
	retquote(typestr);
	return(1);
@


1.2
log
@Fix glitch in format of DECIMAL(n) fields
@
text
@d2 5
a6 2
	@@(#)$Id: sqltype.ec,v 1.1 2002-06-14 05:03:47 afalout Exp $
	@@(#)Convert type and length from Syscolumns to string
d9 4
d26 27
a52 1
	"MONEY"
d62 4
d90 3
d104 14
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

#line 1 "ESQLinit.ec"
#include <sqlhdr.h>
#define SQLCODE sqlca.sqlcode
#line 1 "monset.ec"
/*
@(#)File:            $RCSfile: monset.c,v $
@(#)Version:         $Revision: 1.2 $
@(#)Last changed:    $Date: 2002-06-14 09:23:16 $
@(#)Purpose:         Set/Get Locale from Database
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1991
*/

/*TABSTOP=4*/

#include <ctype.h>
#include <limits.h>
#include <string.h>
#include <sqlca.h>

#include "monfmt.h"

#define NIL(x)		((x)0)

#line 1 "MSQLmonset.ec"
struct Tab_locale
  {
    char locale_name[19];
    char currency_symbol[5];
    char int_curr_symbol[5];
    char mon_decimal_point[2];
    char mon_grouping[11];
    char mon_thousands_sep[2];
    char negative_sign[5];
    char positive_sign[5];
    char frac_digits[2];
    char int_frac_digits[2];
    char n_cs_precedes[2];
    char n_sep_by_space[2];
    char n_sign_posn[2];
    char p_cs_precedes[2];
    char p_sep_by_space[2];
    char p_sign_posn[2];
    char decimal_point[2];
    char grouping[11];
    char thousands_sep[2];
  } ;
#line 43 "monset.ec"

typedef struct Tab_locale Tab_locale;

/* -- Declarations */

static Money_fmt c_locale =
{
	"",
	"",
	"",
	"",
	"",
	"",
	"",
	CHAR_MAX,
	CHAR_MAX,
	CHAR_MAX,
	CHAR_MAX,
	CHAR_MAX,
	CHAR_MAX,
	CHAR_MAX,
	CHAR_MAX,
	".",
	"",
	""
};

#line 23 "MSQLmonset.ec"
static Tab_locale db_locale;
#line 71 "monset.ec"
 static Money_fmt   s_locale;
 static char       *cur_locale;

#ifndef lint
static char     sccs[] = "@(#)$Id: monset.c,v 1.2 2002-06-14 09:23:16 afalout Exp $";
#endif

/* Return current format information */
Money_fmt      *get_monfmt()
{
	return ((cur_locale == NIL(char *)) ? &c_locale : &s_locale);
}

/* Return name of current locale */
char           *get_monlocale()
{
	return ((cur_locale == NIL(char *)) ? "C" : cur_locale);
}

/* Convert the DB grouping information to ANSI C information */
static char    *groupconv(grp)
char           *grp;
{
	char           *s;
	char            c;

	s = grp;
	while ((c = *s) != '\0' && !isspace(c))
	{
		if (c == '.')
		{
			/* No further grouping is to occur */
			*s++ = CHAR_MAX;
			break;
		}
		else
			*s++ = c - '0';
	}
	*s = '\0';
	return (grp);
}

/* Convert any of the numeric codes from Informix-DB to ANSI C */
static int      charconv(c)
char           c;
{
	int             i;

	if (c == '.')
		i = CHAR_MAX;
	else
		i = c - '0';
	if (i < 0 || i > 9)
		i = CHAR_MAX;
	return (i);
}

/* Set a new locale from the database.  Return 0 => OK or SQL error code */
int             set_monlocale(name)
#line 24 "MSQLmonset.ec"
char *name;
#line 131 "monset.ec"
{
	/* User cannot effectively redefine the C locale */
	if (*name == '\0' || strcmp(name, "C") == 0)
	{
		cur_locale = NIL(char *);
		/*dmp_money_fmt(stderr, &c_locale);*/
		return (0);
	}

#line 25 "MSQLmonset.ec"
/* 	$ select        L.locale_name,
 */
 { /* Beginning of ESQL/C generated code */
 static char *sqlcmdtxt[] =
  {
  " select L . locale_name , L . currency_symbol , L . int_curr_symbol ,",
   " L . mon_decimal_point , L . mon_grouping , L . mon_thousands_sep , L",
   " . negative_sign , L . positive_sign , L . frac_digits , L .",
   " int_frac_digits , L . n_cs_precedes , L . n_sep_by_space , L .",
   " n_sign_posn , L . p_cs_precedes , L . p_sep_by_space , L .",
   " p_sign_posn , L . decimal_point , L . grouping , L . thousands_sep",
   " from Locale L where L . Locale_name = ?",
  (char *) 0
  };
 static _SQCURSOR _SQ0 = {0};
 static struct sqlvar_struct _sqibind[] = 
 {
 {100, 0, (char *) 0, (short *) 0, (char *) 0, (char *) 0, 0, 0, (char *) 0},

 };
 static struct sqlvar_struct _sqobind[] = 
 {
 {100, sizeof(db_locale.locale_name), (char *) 0, (short *) 0, (char *) 0, (char *) 0, 0, 0, (char *) 0},
 {100, sizeof(db_locale.currency_symbol), (char *) 0, (short *) 0, (char *) 0, (char *) 0, 0, 0, (char *) 0},
 {100, sizeof(db_locale.int_curr_symbol), (char *) 0, (short *) 0, (char *) 0, (char *) 0, 0, 0, (char *) 0},
 {100, sizeof(db_locale.mon_decimal_point), (char *) 0, (short *) 0, (char *) 0, (char *) 0, 0, 0, (char *) 0},
 {100, sizeof(db_locale.mon_grouping), (char *) 0, (short *) 0, (char *) 0, (char *) 0, 0, 0, (char *) 0},
 {100, sizeof(db_locale.mon_thousands_sep), (char *) 0, (short *) 0, (char *) 0, (char *) 0, 0, 0, (char *) 0},
 {100, sizeof(db_locale.negative_sign), (char *) 0, (short *) 0, (char *) 0, (char *) 0, 0, 0, (char *) 0},
 {100, sizeof(db_locale.positive_sign), (char *) 0, (short *) 0, (char *) 0, (char *) 0, 0, 0, (char *) 0},
 {100, sizeof(db_locale.frac_digits), (char *) 0, (short *) 0, (char *) 0, (char *) 0, 0, 0, (char *) 0},
 {100, sizeof(db_locale.int_frac_digits), (char *) 0, (short *) 0, (char *) 0, (char *) 0, 0, 0, (char *) 0},
 {100, sizeof(db_locale.n_cs_precedes), (char *) 0, (short *) 0, (char *) 0, (char *) 0, 0, 0, (char *) 0},
 {100, sizeof(db_locale.n_sep_by_space), (char *) 0, (short *) 0, (char *) 0, (char *) 0, 0, 0, (char *) 0},
 {100, sizeof(db_locale.n_sign_posn), (char *) 0, (short *) 0, (char *) 0, (char *) 0, 0, 0, (char *) 0},
 {100, sizeof(db_locale.p_cs_precedes), (char *) 0, (short *) 0, (char *) 0, (char *) 0, 0, 0, (char *) 0},
 {100, sizeof(db_locale.p_sep_by_space), (char *) 0, (short *) 0, (char *) 0, (char *) 0, 0, 0, (char *) 0},
 {100, sizeof(db_locale.p_sign_posn), (char *) 0, (short *) 0, (char *) 0, (char *) 0, 0, 0, (char *) 0},
 {100, sizeof(db_locale.decimal_point), (char *) 0, (short *) 0, (char *) 0, (char *) 0, 0, 0, (char *) 0},
 {100, sizeof(db_locale.grouping), (char *) 0, (short *) 0, (char *) 0, (char *) 0, 0, 0, (char *) 0},
 {100, sizeof(db_locale.thousands_sep), (char *) 0, (short *) 0, (char *) 0, (char *) 0, 0, 0, (char *) 0},

 };
 _sqibind[0].sqldata = (name);
 _sqobind[0].sqldata = (db_locale.locale_name);
 _sqobind[1].sqldata = (db_locale.currency_symbol);
 _sqobind[2].sqldata = (db_locale.int_curr_symbol);
 _sqobind[3].sqldata = (db_locale.mon_decimal_point);
 _sqobind[4].sqldata = (db_locale.mon_grouping);
 _sqobind[5].sqldata = (db_locale.mon_thousands_sep);
 _sqobind[6].sqldata = (db_locale.negative_sign);
 _sqobind[7].sqldata = (db_locale.positive_sign);
 _sqobind[8].sqldata = (db_locale.frac_digits);
 _sqobind[9].sqldata = (db_locale.int_frac_digits);
 _sqobind[10].sqldata = (db_locale.n_cs_precedes);
 _sqobind[11].sqldata = (db_locale.n_sep_by_space);
 _sqobind[12].sqldata = (db_locale.n_sign_posn);
 _sqobind[13].sqldata = (db_locale.p_cs_precedes);
 _sqobind[14].sqldata = (db_locale.p_sep_by_space);
 _sqobind[15].sqldata = (db_locale.p_sign_posn);
 _sqobind[16].sqldata = (db_locale.decimal_point);
 _sqobind[17].sqldata = (db_locale.grouping);
 _sqobind[18].sqldata = (db_locale.thousands_sep);
 _iqslct(&_SQ0, sqlcmdtxt, 1, _sqibind, 19, _sqobind, 0);
 } /* End of ESQL/C generated code */
#line 181 "monset.ec"

	if (sqlca.sqlcode != 0)
	{
		/* Something's wrong -- could be almost anything */
		/* Database not open */
		/* Table locale not in database */
		/* No matching row */
		/* Multiple matching rows */
		return (sqlca.sqlcode);
	}

	/* Save current locale name */
	if (cur_locale != NIL(char *))
		free(cur_locale);
	cur_locale = strdup(name);

	/* Mangle database version of locale into <locale.h> version */
	s_locale.decimal_point		= db_locale.decimal_point;
	s_locale.grouping			= groupconv(db_locale.grouping);
	s_locale.thousands_sep		= db_locale.thousands_sep;
	s_locale.currency_symbol	= db_locale.currency_symbol;
	s_locale.int_curr_symbol	= db_locale.int_curr_symbol;
	s_locale.mon_decimal_point	= db_locale.mon_decimal_point;
	s_locale.mon_grouping		= groupconv(db_locale.mon_grouping);
	s_locale.mon_thousands_sep	= db_locale.mon_thousands_sep;
	s_locale.negative_sign		= db_locale.negative_sign;
	s_locale.positive_sign		= db_locale.positive_sign;
	s_locale.frac_digits		= charconv(db_locale.frac_digits[0]);
	s_locale.int_frac_digits	= charconv(db_locale.int_frac_digits[0]);
	s_locale.n_cs_precedes		= charconv(db_locale.n_cs_precedes[0]);
	s_locale.n_sep_by_space		= charconv(db_locale.n_sep_by_space[0]);
	s_locale.n_sign_posn		= charconv(db_locale.n_sign_posn[0]);
	s_locale.p_cs_precedes		= charconv(db_locale.p_cs_precedes[0]);
	s_locale.p_sep_by_space		= charconv(db_locale.p_sep_by_space[0]);
	s_locale.p_sign_posn		= charconv(db_locale.p_sign_posn[0]);
	/*dmp_money_fmt(stderr, &s_locale);*/
	return (0);
}

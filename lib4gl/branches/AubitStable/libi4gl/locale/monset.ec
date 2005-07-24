/*
@(#)File:            $RCSfile: monset.ec,v $
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

$struct Tab_locale            
{
	char            locale_name[19];
	char            currency_symbol[5];
	char            int_curr_symbol[5];
	char            mon_decimal_point[2];
	char            mon_grouping[11];
	char            mon_thousands_sep[2];
	char            negative_sign[5];
	char            positive_sign[5];
	char            frac_digits[2];
	char            int_frac_digits[2];
	char            n_cs_precedes[2];
	char            n_sep_by_space[2];
	char            n_sign_posn[2];
	char            p_cs_precedes[2];
	char            p_sep_by_space[2];
	char            p_sign_posn[2];
	char            decimal_point[2];
	char            grouping[11];
	char            thousands_sep[2];
};

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

$static Tab_locale  db_locale;
 static Money_fmt   s_locale;
 static char       *cur_locale;

#ifndef lint
static char     sccs[] = "@(#)$Id: monset.ec,v 1.2 2002-06-14 09:23:16 afalout Exp $";
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

/* Strip trailing blanks */
static char    *stb(s)
char           *s;
{
	char           *e = s + strlen(s) - 1;

	while (e >= s & isspace(*e))
		*e-- = '\0';
	return (s);
}

/* Set a new locale from the database.  Return 0 => OK or SQL error code */
int             set_monlocale(name)
$char          *name;
{
	/* User cannot effectively redefine the C locale */
	if (*name == '\0' || strcmp(name, "C") == 0)
	{
		cur_locale = NIL(char *);
		/*dmp_money_fmt(stderr, &c_locale);*/
		return (0);
	}

	$ select        L.locale_name,
	                L.currency_symbol,
	                L.int_curr_symbol,
	                L.mon_decimal_point,
	                L.mon_grouping,
	                L.mon_thousands_sep,
	                L.negative_sign,
	                L.positive_sign,
	                L.frac_digits,
	                L.int_frac_digits,
	                L.n_cs_precedes,
	                L.n_sep_by_space,
	                L.n_sign_posn,
	                L.p_cs_precedes,
	                L.p_sep_by_space,
	                L.p_sign_posn,
	                L.decimal_point,
	                L.grouping,
	                L.thousands_sep
		into
	               :db_locale.locale_name,
	               :db_locale.currency_symbol,
	               :db_locale.int_curr_symbol,
	               :db_locale.mon_decimal_point,
	               :db_locale.mon_grouping,
	               :db_locale.mon_thousands_sep,
	               :db_locale.negative_sign,
	               :db_locale.positive_sign,
	               :db_locale.frac_digits,
	               :db_locale.int_frac_digits,
	               :db_locale.n_cs_precedes,
	               :db_locale.n_sep_by_space,
	               :db_locale.n_sign_posn,
	               :db_locale.p_cs_precedes,
	               :db_locale.p_sep_by_space,
	               :db_locale.p_sign_posn,
	               :db_locale.decimal_point,
	               :db_locale.grouping,
	               :db_locale.thousands_sep
		from Locale L
		where L.Locale_name = :name;

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
	s_locale.currency_symbol	= stb(db_locale.currency_symbol);
	s_locale.int_curr_symbol	= stb(db_locale.int_curr_symbol);
	s_locale.mon_decimal_point	= db_locale.mon_decimal_point;
	s_locale.mon_grouping		= groupconv(db_locale.mon_grouping);
	s_locale.mon_thousands_sep	= db_locale.mon_thousands_sep;
	s_locale.negative_sign		= stb(db_locale.negative_sign);
	s_locale.positive_sign		= stb(db_locale.positive_sign);
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

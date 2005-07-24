/*
@(#)File:            $RCSfile: monfmt.c,v $
@(#)Version:         $Revision: 1.2 $
@(#)Last changed:    $Date: 2002-06-14 09:23:16 $
@(#)Purpose:         Locale-specific formatting
@(#)Author:          P J Plauger / J Leffler
*/

/*TABSTOP=4*/

/*
** Modelled on _Fmtval from P J Plauger "The Standard C Library"
**
** Apart from renaming the function, the function now takes an
** extra argument which indicates the available string length.  It
** tries to avoid trampling beyond that length -- and signals a
** failure by returning a null pointer when it doesn't crash.  It
** also detects a bad digits argument and returns a null pointer.
** Finally, a header has been defined for use with this function.
** NB: this version does not use <locale.h> as defined in ANSI C.
**     However, it should not be difficult to adapt it to work
**     with the proper structures.
*/

/* -- Include Files */

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include "monfmt.h"

/* -- Declarations */

#ifndef lint
static char     sccs[] = "@(#)$Id: monfmt.c,v 1.2 2002-06-14 09:23:16 afalout Exp $";
#endif

#ifdef __STDC__
char           *(fmt_money)(char *buf, int len, double d, int digits)
#else
#undef fmt_money
char           *fmt_money(buf, len, d, digits)
char           *buf;
int             len;
double          d;
int             digits;
#endif	/* __STDC__ */
{
	char           *cur_sym;	/* Currency symbol */
	char            dec_pt;		/* Decimal point */
	char           *grps;		/* Group size */
	char            grp_sep;	/* Group separator */
	char           *sign;		/* Sign */
	const char     *fmt;		/* Internal format specifier */
	int             fd;			/* Digits after decimal point */
	int             neg;		/* Flag: number is negative */
	Money_fmt      *loc = get_monfmt();

	if (d >= 0.0)
		neg = 0;
	else
	{
		d = -d;
		neg = 1;
	}

	/* Sort out formatting to be done */
	if (digits == FMT_INTER_CURR)
	{							/* International currency */
		cur_sym = loc->int_curr_symbol;
		dec_pt = loc->mon_decimal_point[0];
		fmt = "$-V";
		fd = loc->int_frac_digits;
		grps = loc->mon_grouping;
		grp_sep = loc->mon_thousands_sep[0];
		sign = neg ? loc->negative_sign : loc->positive_sign;
	}
	else if (digits == FMT_LOCAL_CURR)
	{							/* Local currency */
		static const char *ftab[5][2][2] =
		{
			"(V$)",		"-V$",	"V$-",	"V-$",	"V$-",
			"($V)",		"-$V",	"$V-",	"-$V",	"$-V",
			"(V $)",	"-V $",	"V $-",	"V- $",	"V $-",
			"($ V)",	"-$ V",	"$ V-",	"-$ V",	"$ -V"
		};
		int		i1;
		int		i2;
		int		i3;

		cur_sym = loc->currency_symbol;
		dec_pt = loc->mon_decimal_point[0];
		if (neg)
		{
			i1 = loc->n_sign_posn;
			i1 = (i1 < 0 || i1 > 4) ? 0 : i1;
			i2 = loc->n_cs_precedes == 1;
			i3 = loc->n_sep_by_space == 1;
		}
		else
		{
			i1 = loc->p_sign_posn;
			i1 = (i1 < 0 || i1 > 4) ? 0 : i1;
			i2 = loc->p_cs_precedes == 1;
			i3 = loc->p_sep_by_space == 1;
		}
		fmt = ftab[i1][i2][i3];
		fd = loc->frac_digits;
		grps = loc->mon_grouping;
		grp_sep = loc->mon_thousands_sep[0];
		sign = neg ? loc->negative_sign : loc->positive_sign;
	}
	else if (digits < FMT_INTEGER)
	{							/* Invalid argument */
		return (NULL);
	}
	else
	{							/* Plain number -- no currency symbol */
		dec_pt = loc->decimal_point[0];
		cur_sym = "";
		fmt = "-V";
		fd = digits;
		grps = loc->grouping;
		grp_sep = loc->thousands_sep[0];
		sign = neg ? "-" : "";
	}

	{
		char           *end;
		char           *s;
		const char     *g;
		size_t          i;
		size_t          ns;
		char           *bufend = buf + len;

		buf[0] = '\0';
		for (s = buf; *fmt != '\0' && s < bufend; fmt++, s += strlen(s))
		{
			switch (*fmt)
			{
			case '$':
				if (s + strlen(cur_sym) >= bufend)
					return (NULL);
				strcpy(s, cur_sym);
				break;
			case '-':
				if (s + strlen(sign) >= bufend)
					return (NULL);
				strcpy(s, sign);
				break;
			default:
				*s++ = *fmt;
				*s = '\0';
				break;
			case 'V':
				/* This is where the length checking could go horribly wrong */
				/* e.g. pass in 1.0E289 */
				if (digits < 0 || digits == CHAR_MAX)
					digits = 0;
				/* The # forces a decimal point */
				sprintf(s, "%#.*f", (fd > 0 && fd != CHAR_MAX) ? fd : 0, d);
				if (s + strlen(s) >= bufend)
					return(NULL);
				end = strchr(s, dec_pt);
				for (ns = 0, i = end - s, g = grps; i > 0; ns++)
				{
					/* Count separators to add to field */
					if (g[0] <= 0 || i <= g[0] || g[0] == CHAR_MAX)
						break;
					i -= g[0];
					if (g[1] != 0)
						g++;
				}
				if (s + strlen(s) + ns >= bufend)
					return(NULL);
				memmove(end + ns, end, strlen(end) + 1);
				i = end - s;
				end += ns;
				*end = (fd >= 0 && fd != CHAR_MAX) ? dec_pt : '\0';
				for (g = grps; i > 0; ns--)
				{
					if (g[0] <= 0 || i <= g[0] || g[0] == CHAR_MAX)
						break;
					i -= g[0];
					end -= g[0];
					memmove(end, end - ns, g[0]);
					*--end = grp_sep;
					if (g[1] != 0)
						g++;
				}
				break;
			}
		}
	}
	return(buf);
}

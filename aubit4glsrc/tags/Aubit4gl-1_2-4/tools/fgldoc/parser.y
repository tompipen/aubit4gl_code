%{
/*
 * fgldoc, an Informix-4GL program documenter
 * Copyright (c) 1995-1999 Ivan Nejgebauer <ian@uns.ns.ac.yu>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

/*
 * 2.00 Jun 1999 ian
 *
 * 1.16 Nov 1998 ian
 *
 * 1.00 Jan 1995 ian
 */

#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "fgldoc.h"

/* local functions */
static int bltincmp(const void *i1, const void *i2);
static int bltin(char *ident);
static char *uc_ident(char *ident);

%}

%token MAIN FUNCTION REPORT END
%token START OUTPUT TO FINISH
%token OPEN WINDOW AT WITH
%token FORM FROM
%token STRING IDENT ANYTHING

%start fglfile

%%

fglfile	: /* empty */
	| clauses
	;

clauses	: clause
	| clauses clause
	;

clause	: startblock
	| endblock
	| reportstmt
	| fcall
	| openstmt
	| freetext
	;

startblock: MAIN { regfun("!main"); }
	| FUNCTION IDENT { regfun(matched); }
	| REPORT IDENT { regrep(matched); }
	;

endblock: END MAIN
	| END FUNCTION
	| END REPORT
	| END IDENT
	;

reportstmt: START REPORT IDENT { regrcall(matched); }
	| OUTPUT TO REPORT IDENT
	| OUTPUT REPORT
	| OUTPUT IDENT
	| FINISH REPORT
	;

fcall	: IDENT '(' {
	    if (!bltin(matched))
		regfcall(matched);
	}
	;

openstmt: OPEN WINDOW IDENT AT iexpr ',' iexpr WITH wopts
	| OPEN FORM IDENT FROM STRING { regfrm(matched); }
	| OPEN FORM IDENT FROM IDENT { regfrm(uc_ident(matched)); }
	| OPEN IDENT
	;

iexpr	: IDENT
	| ANYTHING
	;

wopts	: FORM STRING { regfrm(matched); }
	| FORM IDENT { regfrm(uc_ident(matched)); }
	| IDENT
	| ANYTHING
	;

freetext: ANYTHING
	| IDENT
	| STRING
	| WINDOW
	| FORM
	| FROM
	| TO
	| AT
	| ','
	| '('
	;

%%

static char *builtin[] = {
    "all",
    "and",
    "arg_count",
    "arg_val",
    "arr_count",
    "arr_curr",
    "attribute",
    "average",
    "avg",
    "between",
    "case",
    "char",
    "character",
    "count",
    "cursor_name",
    "date",
    "day",
    "downshift",
    "err_get",
    "err_print",
    "err_quit",
    "errorlog",
    "extend",
    "fgl_drawbox",
    "fgl_keyval",
    "fgl_lastkey",
    "field_touched",
    "fraction",
    "get_fldbuf",
    "if",
    "infield",
    "key",
    "length",
    "max",
    "mdy",
    "min",
    "month",
    "num_args",
    "or",
    "ord",
    "percent",
    "return",
    "scr_line",
    "select",
    "set_count",
    "showhelp",
    "startlog",
    "sum",
    "union",
    "upshift",
    "values",
    "varchar",
    "weekday",
    "when",
    "where",
    "while",
    "year",
};

#define NBLTIN (sizeof builtin / sizeof(char *))

static int
bltincmp(const void *i1, const void *i2)
{
    return strcmp(*((char **) i1), *((char **) i2));
}

static int
bltin(char *ident)
{
    return !!bsearch(&ident, builtin, NBLTIN, sizeof(char *), bltincmp);
}

static char *
uc_ident(char *ident)
{
    register char *s;

    for (s = ident; *s; s++)
	*s = toupper(*s);
    return ident;
}

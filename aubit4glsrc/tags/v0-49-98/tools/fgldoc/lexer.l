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
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"

/* from fglref.c */
extern int verbose;

/* globals */
int lineno;
char matched[256];

/* local functions */
static void ldisp(void);
static void skipcmt(int cmtend);
static void cpstring(int delimiter);
static int chktok(char *yp);
static int rwcmp(const void *cptr, const void *rptr);

%}

TOKEN	[_a-zA-Z][_a-zA-Z0-9]*
INTNUM	[0-9]+

%%

\#		{ skipcmt('\n'); }
--		{ skipcmt('\n'); }
\{		{ skipcmt('}'); }
\"		{ cpstring('\"'); return STRING; }
'		{ cpstring('\''); return STRING; }
{TOKEN}		{ return chktok(yytext); }
{INTNUM}	{ return ANYTHING; }
[ \t]+		{ /* eat up whitespace */ }
\n		{ lineno++; if (verbose && !(lineno % 100)) ldisp(); }
","		{ return ','; }
"("		{ return '('; }
.		{ return ANYTHING; }

%%

typedef struct {
    char *toktext;
    int tokval;
} Token;

/* reserved words */
static Token reswords[] = {
    "at", AT,
    "end", END,
    "finish", FINISH,
    "form", FORM,
    "from", FROM,
    "function", FUNCTION,
    "main", MAIN,
    "open", OPEN,
    "output", OUTPUT,
    "report", REPORT,
    "start", START,
    "to", TO,
    "window", WINDOW,
    "with", WITH,
};

#define NRESWORDS (sizeof reswords / sizeof(Token))

/* display line numbers in increments by 100 if verbose mode set */
static void
ldisp(void)
{
    fprintf(stderr, "\b\b\b\b\b\b%6d", lineno);
    fflush(stderr);
}

/* skip a comment until the char sent */
static void
skipcmt(int cmtend)
{
    int c;

    while ((c = input()) != EOF) {
	if (c == '\n')
	    lineno++;
	if (c == cmtend)
	    break;
    }
}

/* copy a string, paying attention to doubled delimiters and escaped chars */
static void
cpstring(int delimiter)
{
    int c;
    int last = 0;
    int escape = 0;
    int i = 0;

    while ((c = input()) != EOF) {
	if (last == delimiter && c != delimiter) {
	    unput(c);
	    break;
	}
	if (c == '\n')
	    lineno++;
	if (c == delimiter && last != delimiter && last != '\\') {
	    last = c;
	    continue;
	} else if (last == delimiter || last == '\\')
	    last = 0;
	else
	    last = c;
	if (c == '\\' && !escape) {
	    escape = 1;
	    continue;
	}
	escape = 0;
	if (i < sizeof matched - 1)
	    matched[i++] = c;
    }
    matched[i] = '\0';
}

static int
rwcmp(const void *cptr, const void *rptr)
{
    Token *c = (Token *) cptr;
    Token *r = (Token *) rptr;

    c->tokval = r->tokval;
    return strcmp(c->toktext, r->toktext);
}

/* check a token */
static int
chktok(char *yp)
{
    int i;
    char tok[64];
    Token curr;

    for (i = 0; i < sizeof tok - 1 && (tok[i] = tolower(*yp++)); i++)
	;
    tok[i] = '\0';
    curr.toktext = tok;
    curr.tokval = 0;
    strcpy(matched, tok);
    if (bsearch(&curr, reswords, NRESWORDS, sizeof(Token), rwcmp))
	return curr.tokval;
    else
	return IDENT;
}

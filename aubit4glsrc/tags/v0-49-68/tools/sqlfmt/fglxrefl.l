%{
/*
@(#)File:            $RCSfile: fglxrefl.l,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-11-28 06:40:47 $
@(#)Purpose:         Lexical Analyser for FGLXREF
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1992
@(#)Product:         SQLFMT Version 14 (1998-11-04)
*/

/*TABSTOP=4*/

#include <stdio.h>
#include <stdlib.h>
#include "sqlfmt.h"
#include "stderr.h"

#define ALPHA	1
#define DIGIT	2
#define SPACE	3
#define OTHER	4
#define QUOTE	5
#define BRACE	6
#define POINT	7

#define DEFINE		0
#define FUNCTION	1
#define DATABASE	2
#define LIKE		3
#define WINFORM		4

static int      line = 0;
static char    *yyfn;
static char     flags[] = "-----";
static char     lasttoken;

static void     fglkeyword(char *s, int l);
static void     print_xref(char *s);
static void     rdbrace(void);
static void     yylex_reset(FILE *fp, char *fn);
extern void     fglxref(FILE *fp, char *fn);

#ifndef lint
static const char sccs[] = "@(#)$Id: fglxrefl.l,v 1.1 2002-11-28 06:40:47 afalout Exp $";
#endif
%}

alpha		[A-Za-z]
alphanum	[A-Za-z0-9_]
string		\"[^"]*\"
quote		\'[^']*\'
digit		[0-9]
space		[ \t\f]

%%
{alpha}{alphanum}*	{ return(ALPHA); }
{string}			{ return(QUOTE); }
{quote}				{ return(QUOTE); }
{digit}+			{ return(DIGIT); }
{space}+			{ return(SPACE); }
#.*					{ return(OTHER); }
--.*				{ return(OTHER); }
\{					{ return(BRACE); }
"\n"				{ line++;        }
\.					{ return(POINT); }
.					{ return(OTHER); }
%%

void            fglxref(FILE *fp, char *fn)
{
	int             type;

	line = 1;
	yylex_reset(fp, fn);

	while ((type = yylex()) != 0)
	{
#ifdef DEBUG
		switch (type)
		{
		case ALPHA:
			fprintf(stderr, "ALPHA: %s\n", yytext);
			break;
		case QUOTE:
			fprintf(stderr, "QUOTE: %s\n", yytext);
			break;
		case DIGIT:
			fprintf(stderr, "DIGIT: %s\n", yytext);
			break;
		case SPACE:
			fprintf(stderr, "SPACE: %s\n", yytext);
			break;
		case BRACE:
			fprintf(stderr, "BRACE: %s\n", yytext);
			break;
		case OTHER:
			fprintf(stderr, "OTHER: %s\n", yytext);
			break;
		case POINT:
			fprintf(stderr, "POINT: %s\n", yytext);
			break;
		default:
			fprintf(stderr, "?????: %s\n", yytext);
			exit(1);
		}
#endif	/* DEBUG */

		switch (type)
		{
		case POINT:
		case ALPHA:
			fglkeyword(yytext, strlen(yytext));
			break;
		case BRACE:
			rdbrace();
			break;
		default:
			if (*yytext == '\n')
				line++;
			break;
		}
	}
}

static void     rdbrace(void)
{
	int             c;
	int             oc;

	oc = '{';
	while ((c = input()) != '}' || oc == '\\')
	{
		oc = c;
		if (c == '\n')
			line++;
	}
}

static void     print_xref(char *s)
{
	printf("%s:%d:%s:%s\n", yyfn, line, s, flags);
}

static void     fglkeyword(char *s, int l)
{
	char           *what;

	what = bsearch(s, kw_table, kw_size, sizeof(char *), compare);
	if (what == (char *)NULL)
	{							/* Not a keyword */
		/* Is it a database? */
		if (lasttoken == 'd')
			flags[DATABASE] = 'D';
		else
			flags[DATABASE] = '-';

		/* Is it a special symbol name? */
		if (lasttoken == 'w')
			flags[WINFORM] = 'W';
		else if (lasttoken == 'f')
			flags[WINFORM] = 'F';
		else if (lasttoken == 'p')
			flags[WINFORM] = 'P';
		else if (lasttoken == 'D')
			flags[WINFORM] = 'D';
		else
			flags[WINFORM] = '-';

		if (flags[LIKE] == 'L' && *s == '.')
		{
			lasttoken = 'l';
		}
		else if (*s != '.')
		{
			if (lasttoken == 'l')
				flags[LIKE] = 'L';
			else
				flags[LIKE] = '-';
			lasttoken = '-';
			print_xref(s);
		}

		flags[FUNCTION] = '-';

	}
	else
	{
		/* Is a keyword */
		flags[DATABASE] = '-';

		/* Is it a type definition keyword? */
		if (compare("define", &s) == 0 ||
			compare("record", &s) == 0 ||
			compare("like", &s) == 0 ||
			compare("array", &s) == 0 ||
			compare("serial", &s) == 0 ||
			compare("date", &s) == 0 ||
			compare("smallint", &s) == 0 ||
			compare("int", &s) == 0 ||
			compare("integer", &s) == 0 ||
			compare("decimal", &s) == 0 ||
			compare("numeric", &s) == 0 ||
			compare("dec", &s) == 0 ||
			compare("money", &s) == 0 ||
			compare("char", &s) == 0 ||
			compare("varchar", &s) == 0 ||
			compare("character", &s) == 0 ||
			compare("byte", &s) == 0 ||
			compare("text", &s) == 0 ||
			compare("datetime", &s) == 0 ||
			compare("interval", &s) == 0 ||
			compare("year", &s) == 0 ||
			compare("month", &s) == 0 ||
			compare("day", &s) == 0 ||
			compare("hour", &s) == 0 ||
			compare("minute", &s) == 0 ||
			compare("second", &s) == 0 ||
			compare("fraction", &s) == 0 ||
			compare("real", &s) == 0 ||
			compare("double", &s) == 0 ||
			compare("precision", &s) == 0 ||
			compare("float", &s) == 0 ||
			compare("smallfloat", &s) == 0)
		{
			flags[DEFINE] = 'D';
		}
		else if (compare("of", &s) == 0 || compare("to", &s) == 0)
		{
			/* Distinguish between: ARRAY... OF and CURRENT OF cursor */
			/* and FOR UPDATE OF ... */
			flags[DEFINE] = (flags[DEFINE] == 'D') ? 'D' : '-';
		}
		else
			flags[DEFINE] = '-';

		flags[FUNCTION] = '-';
		if (compare("function", &s) == 0)
		{
			if (lasttoken != 'e')
				flags[FUNCTION] = 'F';
		}

		if (compare("report", &s) == 0)
		{
			if (lasttoken != 'e' && lasttoken != 'r')
				flags[FUNCTION] = 'R';
		}

		if (compare("main", &s) == 0)
		{
			if (lasttoken != 'e')
			{
				flags[FUNCTION] = 'M';
				print_xref("MAIN");
			}
		}

		/* Record this token when relevant */
		if (compare("end", &s) == 0)
			lasttoken = 'e';
		else if (compare("database", &s) == 0)
			lasttoken = 'd';
		else if (compare("start", &s) == 0)
			lasttoken = 'r';
		else if (compare("finish", &s) == 0)
			lasttoken = 'r';
		else if (compare("to", &s) == 0)
			lasttoken = 'r';
		else if (compare("like", &s) == 0)
			lasttoken = 'l';
		else if (compare("current", &s) == 0)
			lasttoken = 'c';
		else if (compare("window", &s) == 0)
			lasttoken = (lasttoken == 'o') ? 'w' : '-';
		else if (compare("declare", &s) == 0)
			lasttoken = 'D';
		else if (compare("prepare", &s) == 0)
			lasttoken = 'p';
		else if (compare("form", &s) == 0)
			lasttoken = (lasttoken == 'o') ? 'f' : '-';
		else if (compare("open", &s) == 0)
			lasttoken = 'o';
		else
			lasttoken = '-';
	}
}

static void     yylex_reset(FILE *fp, char *fn)
{
#ifdef FLEX_SCANNER
	yy_init  = 1;
	yy_start = 0;
#endif	/* FLEX_SCANNER */
	yyin     = fp;
	yyfn     = fn;
}

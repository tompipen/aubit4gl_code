%{
/*
@(#)File:            $RCSfile: sqlfmt.l,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-11-28 06:40:47 $
@(#)Purpose:         Lexical Analyser for SQLFMT/FGLFMT
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1992
@(#)Product:         SQLFMT Version 14 (1998-11-04)
*/

/*TABSTOP=4*/

#include <stdio.h>
#include "sqlfmt.h"
#include "stderr.h"

#define ALPHA	1
#define DIGIT	2
#define SPACE	3
#define OTHER	4
#define QUOTE	5
#define BRACE	6
#define COMMENT	7

static char	*yyfn;

static void     yylex_reset(FILE *fp, char *fn);
static void     rdcomment(void);
static void     rdbrace(void);

#ifndef lint
static const char sccs[] = "@(#)$Id: sqlfmt.l,v 1.1 2002-11-28 06:40:47 afalout Exp $";
#endif
%}

alpha		[A-Za-z]
alphanum	[A-Za-z0-9_]
string		\"[^"]*\"
digit		[0-9]
space		[ \t\n\f]

%%
{alpha}{alphanum}*	{ return(ALPHA); }
{string}			{ return(QUOTE); }
{digit}+			{ return(DIGIT); }
{space}+			{ return(SPACE); }
\{					{ return(BRACE); }
#|\-\-|!			{ return(COMMENT); }
.					{ return(OTHER); }
%%

#ifdef FLEX_SCANNER
#define output(c)	putc(c, yyout)
#endif

void            sqlfmt(FILE *fp, char *fn)
{
	int             type;

	yylex_reset(fp, fn);

	while ((type = yylex()) != 0)
	{
		switch (type)
		{
		case ALPHA:
			dokeyword(yytext, strlen(yytext));
			break;
		case BRACE:
			rdbrace();
			break;
		case COMMENT:
			rdcomment();
			break;
		default:
			printf("%s", yytext);
			break;
		}
	}
}

static void     rdbrace(void)
{
	int             c;
	int             oc;

	oc = '{';
	output('{');
	while ((c = input()) != '}' || oc == '\\')
	{
		output(c);
		oc = c;
	}
	output('}');
}

static void     rdcomment(void)
{
	int             c;

	output(*yytext);
	if (*(yytext + 1) != '\0')
		output(*(yytext + 1));
	while ((c = input()) != '\n')
		output(c);
	output('\n');
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

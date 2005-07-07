%{
/*
@(#)File:            $RCSfile: esqlfmt.l,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-11-28 06:40:47 $
@(#)Purpose:         Scanning code for ESQL/C re-formatter
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1992
@(#)Product:         SQLFMT Version 14 (1998-11-04)
*/

/*TABSTOP=4*/

#include <stdio.h>
#include "sqlfmt.h"

#define ALPHA	1
#define DIGIT	2
#define SPACE	3
#define OTHER	4
#define QUOTE	5
#define DOLLAR	6
#define SCOLON	7
#define RBRACE	8
#define LBRACE	9
#define EXECSQL	10

#define ESQL		1
#define NOTESQL		0
#define INCOMMENT	2

static int      state = NOTESQL;
static char    *yyfn;

static void     do_c_comment(void);
static void     dodoubledash(void);
static void     yylex_reset(FILE *fp, char *fn);

#ifndef lint
static const char sccs[] = "@(#)$Id: esqlfmt.l,v 1.1 2002-11-28 06:40:47 afalout Exp $";
#endif
%}

alpha		[A-Za-z]
alphanum	[A-Za-z0-9_]
string		\"[^"]*\"
digit		[0-9]
space		[\ \t\n\f]
execsql		[eE][xX][eE][cC]{space}+[sS][qQ][lL]

%%
{execsql}			{ return(EXECSQL); }
{alpha}{alphanum}*	{ return(ALPHA);   }
{string}			{ return(QUOTE);   }
{digit}+			{ return(DIGIT);   }
\$					{ return(DOLLAR);  }
\/\*				{ do_c_comment();  }
--					{ dodoubledash();  }
;					{ return(SCOLON);  }
\}					{ return(RBRACE);  }
\{					{ return(LBRACE);  }
{space}+			{ return(SPACE);   }
.					{ return(OTHER);   }
%%

static void     do_c_comment(void)
{
	int             c;
	int             oc;

	ECHO;
	oc = '/';					/* Not '*' */
	while ((c = input()) != '\0')
	{
		putchar(c);
		if (c == '/' && oc == '*')
			break;
		oc = c;
	}
}

static void     dodoubledash(void)
{
	int             c;

	ECHO;
	if (state != NOTESQL)
	{
		while ((c = input()) != '\0')
		{
			putchar(c);
			if (c == '\n')
				break;
		}
	}
}

void            esqlfmt(FILE *fp, char *fn)
{
	int             type;

	yylex_reset(fp, fn);

	state = NOTESQL;
	while ((type = yylex()) != 0)
	{
#ifdef DEBUG
		switch (type)
		{
		case ALPHA:
			fprintf(stderr, "ALPHA: %d: %s\n", state, yytext);
			break;
		case DIGIT:
			fprintf(stderr, "DIGIT: %d: %s\n", state, yytext);
			break;
		case SPACE:
			fprintf(stderr, "SPACE: %d: %s\n", state, yytext);
			break;
		case OTHER:
			fprintf(stderr, "OTHER: %d: %s\n", state, yytext);
			break;
		case QUOTE:
			fprintf(stderr, "QUOTE: %d: %s\n", state, yytext);
			break;
		case DOLLAR:
			fprintf(stderr, "DOLLAR: %d: %s\n", state, yytext);
			break;
		case SCOLON:
			fprintf(stderr, "SCOLON: %d: %s\n", state, yytext);
			break;
		case RBRACE:
			fprintf(stderr, "RBRACE: %d: %s\n", state, yytext);
			break;
		case LBRACE:
			fprintf(stderr, "LBRACE: %d: %s\n", state, yytext);
			break;
		case EXECSQL:
			fprintf(stderr, "EXECSQL: %d: %s\n", state, yytext);
			break;
		}
#endif	/* DEBUG */

		switch (type)
		{
		case ALPHA:
			if (state == ESQL)
				dokeyword(yytext, strlen(yytext));
			else
				ECHO;
			break;
		case EXECSQL:
			state = ESQL;
			dokeyword("exec", sizeof("exec")-1);
			putchar(' ');
			dokeyword("sql", sizeof("sql")-1);
			break;
		case DOLLAR:
			state = ESQL;
			ECHO;
			break;
		case LBRACE:
			if (state == ESQL)
				state = INCOMMENT;
			ECHO;
			break;
		case RBRACE:
			if (state == INCOMMENT)
				state = ESQL;
			ECHO;
			break;
		case SCOLON:
			if (state == ESQL)
				state = NOTESQL;
			ECHO;
			break;
		default:
			ECHO;
			break;
		}
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

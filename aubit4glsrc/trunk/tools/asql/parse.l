%option yylineno
%{
#if (defined(__CYGWIN__)) || defined(__MINGW32__)
	/* missing from rpcgen generated .h on CygWin: */
	#define bool_t int
	#define u_int unsigned int
#endif

void comment (void );
int check_type (void);
int use_4gl_kw=1;
%}
D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*

%{
#include <stdio.h>
#include "simple.h"

void count();
%}

%%
";"			{ count(); return(KW_SEMI); }
"{"			{ count(); return(KW_OBRACE); }
"}"			{ count(); return(KW_CBRACE); }
"select"		{ count(); return(KW_SELECT); }
"update"		{ count(); return(KW_UPDATE); }
"delete"		{ count(); return(KW_DELETE); }
"insert"		{ count(); return(KW_INSERT); }
"into"			{ count(); return(KW_INTO); }
"temp"			{ count(); return(KW_TEMP); }
"where"			{ count(); return(KW_WHERE); }
{L}({L}|{D})*		{ count(); return(IDENTIFIER); }
0[xX]{H}+{IS}?		{ count(); return(CONSTANT); }
0{D}+{IS}?		{ count(); return(CONSTANT); }
{D}+{IS}?		{ count(); return(CONSTANT); }
L?'(\\.|[^\\'])+'	{ count(); return(CONSTANT); }
{D}+{E}{FS}?		{ count(); return(CONSTANT); }
{D}*"."{D}+({E})?{FS}?	{ count(); return(CONSTANT); }
{D}+"."{D}*({E})?{FS}?	{ count(); return(CONSTANT); }
L?\"(\\.|[^\\"])*\"	{ count(); return(STRING_LITERAL); }
[ \t\v\f]		{ count(); return (KW_SPACE); }
[\n]			{ count(); return (NL);}
.			{ count(); return (CHAR);}


%%

int yywrap ()
{
  return (1);
}


int column = 0;

extern int debug_mode;

void 
count ()
{
  int i;

  for (i = 0; yytext[i] != '\0'; i++)
    if (yytext[i] == '\n' || yytext[i]=='\r')
      column = 0;
    else if (yytext[i] == '\t')
      column += 8 - (column % 8);
    else
      column++;

    strcpy(yylval.str,yytext);
}


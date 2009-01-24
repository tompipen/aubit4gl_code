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
"explain"		{ count(); return(KW_EXPLAIN); }
"select"		{ count(); return(KW_SELECT); }
"update"		{ count(); return(KW_UPDATE); }
"delete"		{ count(); return(KW_DELETE); }
"insert"		{ count(); return(KW_INSERT); }
"into"			{ count(); return(KW_INTO); }
"temp"			{ count(); return(KW_TEMP); }
"where"			{ count(); return(KW_WHERE); }
load[ \t\v\f]*from	{ count(); return(KW_LOAD); }
unload[ \t\v\f]*to	{ count(); return(KW_UNLOAD); }
"delimiter"		{ count(); return(KW_DELIMITER); }
info[ \t\v\f]*columns[ \t\v\f]*for { count(); return(KW_INFO_COL); }
info[ \t\v\f]*status[ \t\v\f]*for  { count(); return(KW_INFO_STAT); }
info[ \t\v\f]*indexes[ \t\v\f]*for { count(); return(KW_INFO_IDX); }
info[ \t\v\f]*access[ \t\v\f]*for { count(); return(KW_INFO_PRIV); }
info[ \t\v\f]*privileges[ \t\v\f]*for { count(); return(KW_INFO_PRIV); }
info[ \t\v\f]*tables 		   { count(); return(KW_INFO_TABLES); }
{L}({L}|{D})*		{ count(); return(KW_IDENTIFIER); }
0[xX]{H}+{IS}?		{ count(); return(KW_CONSTANT); }
0{D}+{IS}?		{ count(); return(KW_CONSTANT); }
{D}+{IS}?		{ count(); return(KW_CONSTANT); }
L?'(\\.|[^\\'])+'	{ count(); return(KW_CONSTANT); }
{D}+{E}{FS}?		{ count(); return(KW_CONSTANT); }
{D}*"."{D}+({E})?{FS}?	{ count(); return(KW_CONSTANT); }
{D}+"."{D}*({E})?{FS}?	{ count(); return(KW_CONSTANT); }
L?\"(\\.|[^\\"])*\"	{ count(); return(KW_STRING_LITERAL); }
[ \t\v\f]		{ count(); return (KW_SPACE); }
[\n]			{ count(); return (KW_NL);}
.			{ count(); return (KW_CHAR);}


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


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
#include <string.h>                   /* strcpy() */
void A4GL_debug(char *s);

void count(void);
%}

%%
";"			{ count(); return(KW_SEMI); }
"{"			{ count(); return(KW_OBRACE); }
"}"			{ count(); return(KW_CBRACE); }
"--"			{ count(); return(KW_MINUS_MINUS); }
"explain"		{ count(); return(KW_EXPLAIN); }
"select"		{ count(); return(KW_SELECT); }
"update"		{ count(); return(KW_UPDATE); }
"delete"		{ count(); return(KW_DELETE); }
"insert"		{ count(); return(KW_INSERT); }
"into"			{ count(); return(KW_INTO); }
"temp"			{ count(); return(KW_TEMP); }
"where"			{ count(); return(KW_WHERE); }
create[ \t\v\f]*procedure	{ count(); return(KW_CREATE_PROCEDURE); }
end[ \t\v\f]*procedure		{ count(); return(KW_END_PROCEDURE); }
load[ \t\v\f]*from	{ count(); return(KW_LOAD); }
unload[ \t\v\f]*to	{ count(); return(KW_UNLOAD); }
output[ \t\v\f]*to	{ count(); return(KW_OUTPUT_TO); }
output[ \t\v\f]*to[ \t\v\f]*pipe	{ count(); return(KW_OUTPUT_TO_PIPE); }
without[ \t\v\f]*headings	{ count(); return(KW_WITHOUT_HEADINGS); }
"delimiter"		{ count(); return(KW_DELIMITER); }
info[ \t\v\f]*columns[ \t\v\f]*for { count(); return(KW_INFO_COL); }
info[ \t\v\f]*status[ \t\v\f]*for  { count(); return(KW_INFO_STAT); }
info[ \t\v\f]*indexes[ \t\v\f]*for { count(); return(KW_INFO_IDX); }
info[ \t\v\f]*access[ \t\v\f]*for { count(); return(KW_INFO_PRIV); }
info[ \t\v\f]*privileges[ \t\v\f]*for { count(); return(KW_INFO_PRIV); }
info[ \t\v\f]*tables 		   { count(); return(KW_INFO_TABLES); }

"SET{"		{ count(); return(KW_IDENTIFIER); } 
"SET[ 	]+{"		{ count(); return(KW_IDENTIFIER); } 

{L}({L}|{D})*		{ count();  return(KW_IDENTIFIER); }
0[xX]{H}+{IS}?		{ count(); A4GL_debug("1"); return(KW_CONSTANT); }
0{D}+{IS}?		{ count(); A4GL_debug("2"); return(KW_CONSTANT); }
{D}+{IS}?		{ count(); A4GL_debug("3"); return(KW_CONSTANT); }
L?'(\\.|[^\\'])*'	{ count(); A4GL_debug("4"); return(KW_CONSTANT); }
{D}+{E}{FS}?		{ count(); A4GL_debug("5"); return(KW_CONSTANT); }
{D}*"."{D}+({E})?{FS}?	{ count(); A4GL_debug("6"); return(KW_CONSTANT); }
{D}+"."{D}*({E})?{FS}?	{ count(); A4GL_debug("7"); return(KW_CONSTANT); }
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
count (void)
{
  int i;

  for (i = 0; yytext[i] != '\0'; i++)
    if (yytext[i] == '\n' || yytext[i]=='\r')
      column = 0;
    else if (yytext[i] == '\t')
      column += 8 - (column % 8);
    else
      column++;

if (strlen(yytext)>sizeof(yylval.str)) {
	printf("Buffer : %d string : %d\n", strlen(yytext),sizeof(yylval.str));
	//printf("%s\n", yytext);
}

A4GL_assertion(strlen(yytext)>sizeof(yylval.str),"String buffer too small");
    strcpy(yylval.str,yytext);
}


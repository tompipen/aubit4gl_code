/*
	lex.yy.c was made from screen.lex using lex program
    it is then included in y.tab.c that was generated from
	screen.yacc using yacc

*/


%e 1000
%p 4000
%n 700
%k 200
%a 4000
%o 4200
%x comment
%option yylineno
%%
[\r] ;
[\n] 	{REJECT}
[ ]	;
[	]	;
[	 \n]	;
"," 	{ return KW_COMMA;}
"FILE" 	{ return KW_FILE;}
"DELIMITER" 	{ return KW_DELIMITER;}
"INSERT" 	{ return KW_INSERT;}
"INTO" 	{ return KW_INTO;}
"NULL" 	{ return KW_NULL;}
"=" 	{ return KW_EQUAL;}
"-" 	{ return KW_MINUS;}
":" 	{ return KW_COLON;}
"(" 	{ return KW_OPEN_BRACKET;}
")" 	{ return KW_CLOSE_BRACKET;}
"VALUES" 	{ return KW_VALUES;}
";" 	{strcpy(yylval.str,yytext); return KW_SEMICOLON;}
[0-9]+  {strcpy(yylval.str, yytext); return(KW_INT_VALUE);}
[0-9]+|[0-9]*\.[0-9]+   { strcpy(yylval.str, yytext); return(KW_NUMBER_VALUE);}
\"[^\"]+\" {  strcpy(yylval.str,A4GL_strip_quotes(yytext)); return KW_STRING;}
\"\" {  strcpy(yylval.str,A4GL_strip_quotes(yytext)); return KW_STRING;}
\'[^\']+\' {  strcpy(yylval.str,(char *)conv_dbl(A4GL_strip_quotes(yytext))); return KW_STRING;}
\'\' {  strcpy(yylval.str,A4GL_strip_quotes(yytext)); return KW_STRING;}
[a-zA-Z]+[a-zA-Z\_0-9]*	{
     strcpy(yylval.str, yytext);
     return(KW_NAMED);
}
[a-zA-Z/\.]+[a-zA-Z\_0-9/\.]*	{
     strcpy(yylval.str, yytext);
     return(KW_FNAMED);
}
[a-zA-Z\_0-9]+[a-zA-Z\_0-9]*	{
		strcpy(yylval.str, yytext);
		return(KW_NAMED);
		}
. {printf("UNPROCESSED: %s\n",yytext);}
%%

/* ============================== EOF =============================== */


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
%option yylineno
%%
[\r\n]  	;
[ 	] 	;

[a-z_]+ 	{   strcpy(yylval.str, yytext); return NAMED;}
\'[^\']+\'  	{  strcpy(yylval.str, yytext); return STRING;}
"\."  		{return DOT;}
"[" 		{ return OPEN_SQUARE;}
"]" 		{ return CLOSE_SQUARE;}
"{" 		{ return OPEN_BRACE;}
"}"	 	{ return CLOSE_BRACE;}
"(" 		{ return OPEN_BRACKET;}
")" 		{ return CLOSE_BRACKET;}
"=" 		{ return EQUAL;}
"|" 		{ return PIPE;}
.		 {printf("Unexpected character....'%s'\n",yytext); exit(2);}
%%


/* ============================== EOF =============================== */


/* [A-Z_]+ 	{ printf("BAD ENTRY : %s\n", yytext);  strcpy(yylval.str, yytext); return NAMED;} */
/*
%token DOT PIPE OPEN_SQUARE CLOSE_SQUARE OPEN_BRACE CLOSE_BRACE STRING OPEN_BRACKET CLOSE_BRACKET  NAMED EQUAL
*/

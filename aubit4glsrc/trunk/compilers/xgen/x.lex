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
[\n] 	{lineno++;colno=0;REJECT}
[ ]	{ colno++;}
[	]	{colno+=3;}
[	 \n]	;
<comment>"*/"	{BEGIN INITIAL;}
<comment>.	;
<comment>[\n]	;

"/*"      { BEGIN comment; yymore(); }
"{"      {strcpy(yylval.str,yytext); return OPEN_BRACE;}
"}"      {strcpy(yylval.str,yytext); return CLOSE_BRACE;}
"["      {strcpy(yylval.str,yytext); return OPEN_SQUARE;}
"]"      {strcpy(yylval.str,yytext); return CLOSE_SQUARE;}
"("      {strcpy(yylval.str,yytext); return OPEN_BRACKET;}
")"      {strcpy(yylval.str,yytext); return CLOSE_BRACKET;}
"<"      {strcpy(yylval.str,yytext); return LESS_THAN;}
">"      {strcpy(yylval.str,yytext); return GREATER_THAN;}
"="      {strcpy(yylval.str,yytext); return EQUAL;}
"*"      {strcpy(yylval.str,yytext); return STAR;}
","      {strcpy(yylval.str,yytext); return COMMA;}
";"      {strcpy(yylval.str,yytext); return SEMICOLON;}
":"      {strcpy(yylval.str,yytext); return COLON;}

"const"      {strcpy(yylval.str,yytext); return CONST;}
"enum"      {strcpy(yylval.str,yytext); return ENUM;}
"struct"      {strcpy(yylval.str,yytext); return STRUCT;}
"union"      {strcpy(yylval.str,yytext); return UNION;}
"switch"      {strcpy(yylval.str,yytext); return SWITCH;}
"case"      {strcpy(yylval.str,yytext); return CASE;}
"string"      {strcpy(yylval.str,yytext); return STRING;}
"int"      {strcpy(yylval.str,yytext); return INT;}
"short"      {strcpy(yylval.str,yytext); return SHORT;}
"long"      {strcpy(yylval.str,yytext); return LONG;}
"double"      {strcpy(yylval.str,yytext); return DOUBLE;}
"opaque"      {strcpy(yylval.str,yytext); return OPAQUE;}
"bool"         {strcpy(yylval.str,yytext); return BOOL;}
"typedef"      {strcpy(yylval.str,yytext); return TYPEDEF;}
[0-9]+  { strcpy(yylval.str, yytext); return(INT_VAL);}
[0-9]+|[0-9]*\.[0-9]+   { strcpy(yylval.str, yytext); return(NUMBER_VAL);}
\"[^\"]+\" 	{  strcpy(yylval.str,yytext); return STRING_VAL;}
\"\" 		{  strcpy(yylval.str,yytext); return STRING_VAL;}
\'[^\']+\' 	{  strcpy(yylval.str,yytext); return STRING_VAL;}
\'\' 		{  strcpy(yylval.str,yytext); return STRING_VAL;}
[a-zA-Z]+[a-zA-Z\_0-9]*	{
strcpy(yylval.str, yytext);colno+=strlen(yytext);
 return(NAMED);
}
[a-zA-Z\_0-9]+[a-zA-Z\_0-9]*	{
strcpy(yylval.str, yytext);colno+=strlen(yytext); 
return(NAMED);}
. {return CH;}
%%

/**
 * Get the yacc buffer position
 *
 * @return The position
 */
int buffpos(void) 
{
  struct yy_buffer_state *y;
  y=YY_CURRENT_BUFFER;
  return (int)(yy_c_buf_p-y->yy_ch_buf);
}

void dummy_not_used_prevent_warning(void);

/* dummy function to eliminate wanrings about static
functions not being used */
void
dummy_not_used_prevent_warning(void)
{
	/* static void *yy_flex_realloc YY_PROTO(( void *, yy_size_t )); */
	yy_flex_realloc (0,0);

	/* static void yyunput YY_PROTO(( int c, char *buf_ptr )); */
	yyunput (0,0);
}


/* ============================== EOF =============================== */


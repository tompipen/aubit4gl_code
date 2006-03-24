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
<comment>"}"	{BEGIN INITIAL;}
<comment>.	;
<comment>[\n]	;

"{"      { BEGIN comment; yymore(); }
"."      {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return DOT;}
"@"      {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return ATSIGN;}
":"      {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return COLON;}
">"      {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return COMPARISON;}
"="     {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return EQUAL;}
"!="     {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return COMPARISON;}
"<>"     {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return COMPARISON;}
"<"      {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return COMPARISON;}
">="     {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return COMPARISON;}
"<="     {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return COMPARISON;}
";" 	{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return SEMICOLON;}
"(" 	{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return OPEN_BRACKET;}
")" 	{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return CLOSE_BRACKET;}
"/" 	{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return DIVIDE;}
"*" 	{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return MULTIPLY;}
"**" 	{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return POW;}
"+" 	{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return PLUS;}
"-" 	{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return MINUS;}
"," 	{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return COMMA;}
"]" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return CLOSE_SQUARE;}
"[" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return OPEN_SQUARE;}
"$" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return DOLLAR;}

"AFTER" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return AFTER;}
"ALL" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return ALL;}
"AND" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return AND;}
"ANY" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return ANY;}
"BEGIN" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return XBEGIN;}
"ASC" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return ASC;}
"ASCII" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return ASCII;}
"AVG" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return AVG;}
"BEFORE" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return BEFORE;}
"ATSIGN" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return ATSIGN;}
"BETWEEN" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return BETWEEN;}
"BOTTOM" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return BOTTOM;}
"BY" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return BY;}
"CHAR" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return CHAR;}
"CLIPPED" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return CLIPPED;}
"PRINT FILE" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return PRINT_FILE;}

"COUNT" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return COUNT;}
"DATABASE" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return DATABASE;}
"DATE" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return DATE;}
"DATETIME" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return DATETIME;}
"DAY" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return DAY;}
"DEFINE" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return DEFINE;}
"DELIMITER" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return DELIMITER;}
"DESC" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return DESC;}
"DISTINCT" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return DISTINCT;}
"DO" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return DO;}
"ELSE" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return ELSE;}
"END" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return END;}
"EQUAL" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return EQUAL;}
"ESCAPE" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return ESCAPE;}
"EVERY" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return EVERY;}
"EXISTS" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return EXISTS;}
"EXTERNAL" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return EXTERNAL;}
"FIRST" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return FIRST;}
"PAGE" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return PAGE;}
"HEADER" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return HEADER;}
"FLOAT" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return FLOAT;}
"FOR" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return FOR;}
"FORMAT" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return FORMAT;}
"FRACTION" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return FRACTION;}
"FROM" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return FROM;}
"FUNCTION" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return FUNCTION;}
"GROUP BY" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return GROUP_BY;}
"HAVING" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return HAVING;}
"HOUR" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return HOUR;}
"IF" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return IF;}
"IN" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return IN;}
"INPUT" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return INPUT;}
"INTEGER" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return INTEGER;}
"INTERVAL" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return INTERVAL;}
"INTO" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return INTO;}
"GROUP" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return GROUP;}
"PERCENT" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return PERCENT;}
"AVERAGE" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return AVERAGE;}
"OF" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return OF;}
"TOTAL" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return TOTAL;}
"TEMP" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return TEMP;}
"IS NOT NULL" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return IS_NOT_NULL;}
"IS NULL" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return IS_NULL;}
"FALSE" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return KW_FALSE;}
"TRUE" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return KW_TRUE;}
"LEFT" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return LEFT;}
"LENGTH" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return LENGTH;}
"LET" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return LET;}
"LINE" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return LINES;}
"LINES" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return LINES;}
"MARGIN" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return MARGIN;}
"MOD" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return MOD;}
"MINUTE" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return MINUTE;}
"MONTH" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return MONTH;}
"NAMED" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return NAMED;}
"NEED" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return NEED;}

"MATCHES" {if (ignorekw) REJECT;strcpy(yylval.str,"MATCHES"); return MATCHES;}
"LIKE" {if (ignorekw) REJECT;strcpy(yylval.str,"LIKE"); return LIKE;}

"NOT" {if (ignorekw) REJECT;strcpy(yylval.str,"NOT"); return NOT;}
"NOT EQUAL" {if (ignorekw) REJECT;strcpy(yylval.str,"<>"); return NOT_EQUAL;}
"NOT EXISTS" {if (ignorekw) REJECT;strcpy(yylval.str,"NOT EXISTS"); return NOT_EXISTS;}
"NOT IN" {if (ignorekw) REJECT;strcpy(yylval.str,"NOT IN"); return NOT_IN;}
"NOT LIKE" {if (ignorekw) REJECT;strcpy(yylval.str,"NOT LIKE"); return NOT_LIKE;}
"NOT MATCHES" {if (ignorekw) REJECT;strcpy(yylval.str,"NOT MATCHES"); return NOT_MATCHES;}

"NUMERIC" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return NUMERIC;}
"ON"  {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return ON;}
"EVERY"  {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return EVERY;}
"ROW" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return ROW;}
"LAST" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return LAST;}
"OR" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return OR;}
"ORDER BY" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return ORDER_BY;}
"ORDER EXTERNAL BY" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return ORDER_EXTERNAL_BY;}
"OUTER" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return OUTER;}
"OUTPUT" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return OUTPUT;}
"PAGE" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return PAGE;}
"PIPE" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return PIPE;}
"HEADER" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return HEADER;}
"TRAILER" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return TRAILER;}
"PARAM" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return PARAM;}
"PAUSE" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return PAUSE;}
"PRINT" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return PRINT;}
"PRINTER" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return PRINTER;}
"PROMPT" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return PROMPT;}
"READ" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return READ;}
"REPORT" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return REPORT;}
"RIGHT" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return RIGHT;}
"ROW" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return ROW;}
"SECOND" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return SECOND;}
"SELECT" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return SELECT;}
"SEMICOLON" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return SEMICOLON;}
"SKIP" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return SKIP;}
"SMALLFLOAT" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return SMALLFLOAT;}
"SMALLINT" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return SMALLINT;}
"MONEY" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return MONEY;}
"DECIMAL" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return DECIMAL;}

"SOME" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return SOME;}
"STEP" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return STEP;}
"SUM" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return SUM;}
"THEN" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return THEN;}
"TO" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return TO;}
"TOP" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return TOP;}
"TOP OF PAGE" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return TOP_OF_PAGE;}
"UNION" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return UNION;}
"UNIQUE" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return UNIQUE;}
"UPDATE" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return UPDATE;}
"USER" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return USER;}
"USING" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return USING;}
"VARCHAR" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return VARCHAR;}
"COLUMN" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return COLUMN;}
"SPACE" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return SPACES;}
"SPACES" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return SPACES;}
"VARIABLE" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return VARIABLE;}
"WHERE" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return WHERE;}
"WHILE" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return WHILE;}
"MAX" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return XMAX;}
"MIN" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return XMIN;}
"YEAR" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return YEAR;}
"CALL" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return KW_CALL;}
"WITH NO LOG" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return WITH_NO_LOG;}
[0-9]+  {if (ignorekw) REJECT; strcpy(yylval.str, yytext); return(INTVAL);}
[0-9]+|[0-9]*\.[0-9]+   {if (ignorekw) REJECT; strcpy(yylval.str, yytext); return(NUMBER_VALUE);}
"UNITS YEAR" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return UNITS_YEAR;}
"UNITS MONTH" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return UNITS_MONTH;}
"UNITS DAY" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return UNITS_DAY;}
"UNITS HOUR" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return UNITS_HOUR;}
"UNITS MINUTE" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return UNITS_MINUTE;}
"UNITS SECOND" {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return UNITS_SECOND;}
\"[^\"]+\" {  strcpy(yylval.str,A4GL_strip_quotes(yytext)); return CHAR_VALUE;}
\"\" {  strcpy(yylval.str,A4GL_strip_quotes(yytext)); return CHAR_VALUE;}
\'[^\']+\' {  strcpy(yylval.str,A4GL_strip_quotes(yytext)); return CHAR_VALUE;}

\'\' {  strcpy(yylval.str,A4GL_strip_quotes(yytext)); return CHAR_VALUE;}
[a-zA-Z]+[a-zA-Z\_0-9]*	{
	if (ignorekw) REJECT;strcpy(yylval.str, yytext);colno+=strlen(yytext);
 return(NAMED);
}
[a-zA-Z\_0-9]+[a-zA-Z\_0-9]*	{
if (ignorekw!=1) REJECT;strcpy(yylval.str, yytext);colno+=strlen(yytext); 
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
	//yy_flex_realloc (0,0);

	/* static void yyunput YY_PROTO(( int c, char *buf_ptr )); */
	yyunput (0,0);
}


/* ============================== EOF =============================== */


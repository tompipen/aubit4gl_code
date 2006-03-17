/*

    file menu.lex is processed by lex and lex.yy.c is created, which
    is then included at the end of menu.yacc

*/


%e 1000
%p 4000
%n 700
%k 200
%a 4000
%o 4200
%x comment
%option yylineno
/*%option interactive*/
%%
[\n] {lineno++;colno=0;REJECT;}
[ ]	{ colno++;}
[	]	{ colno+=3;}
[	 \n]	;

<comment>"}"	{BEGIN INITIAL;}
<comment>.	; 


"MENU"		{if (ignorekw) REJECT; strcpy(yylval.str, yytext); return(KW_MENU);}
"USE"		{if (ignorekw) REJECT; strcpy(yylval.str, yytext); return(KW_USE);}
"SUBMENU"	{if (ignorekw) REJECT; strcpy(yylval.str, yytext); return(KW_SUBMENU);}
"OPTION"	{if (ignorekw) REJECT; strcpy(yylval.str, yytext); return(KW_OPTION);}
"RIGHT"	{if (ignorekw) REJECT; strcpy(yylval.str, yytext); return(KW_RIGHT);}
"CHECK"	{if (ignorekw) REJECT; strcpy(yylval.str, yytext); return(KW_CHECK);}

"IMAGE" {if (ignorekw) REJECT; strcpy(yylval.str, yytext); return(KW_IMAGE);}
"HIDDEN" {if (ignorekw) REJECT; strcpy(yylval.str, yytext); return(KW_HIDDEN);}
"ATTRIBUTES" {if (ignorekw) REJECT; strcpy(yylval.str, yytext); return(ATTRIBUTES);}

"["		{ strcpy(yylval.str, yytext); colno++;return(OPEN_SQUARE);}
"end"		{if (ignorekw) REJECT; strcpy(yylval.str, yytext); return(KW_END);}
"]"		{ strcpy(yylval.str, yytext); colno++;return(CLOSE_SQUARE);}
[0-9]+|[0-9]*\.[0-9]+  	{if (ignorekw) REJECT; strcpy(yylval.str, yytext); return(NUMBER_VALUE);}
\"[^\"]+\" { strcpy(yylval.str,yytext); return CHAR_VALUE;}
[	 \n]	;
"{" 		{strcpy(yylval.str,yytext); return OPEN_BRACE;}
"}" 		{strcpy(yylval.str,yytext); return CLOSE_BRACE;}
"@" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return ATSIGN;}
":" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return COLON;}
"." 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return DOT;}
"|" 		{strcpy(yylval.str,yytext); colno++;return PIPE;}
"=" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return EQUAL;}
"(" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return OPEN_BRACKET;}
")" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return CLOSE_BRACKET;}
"*" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return STAR;}
"," 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return COMMA;}
"black" 	{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return BLACK;}
"blue" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return BLUE;}
"white" 	{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return WHITE;}
"yellow" 	{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return YELLOW;}
"red" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return RED;}
"green" 	{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return GREEN;}
"cyan" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return CYAN;}

"magenta" 	{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return MAGENTA;}

"color"		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return COLOR;}

[a-zA-Z]+[a-zA-Z\_0-9]*	{if (ignorekw) REJECT;strcpy(yylval.str, yytext);colno+=strlen(yytext); return(NAMED);}
[a-zA-Z\_0-9]+[a-zA-Z\_0-9]*	{if (ignorekw!=1) REJECT;strcpy(yylval.str, yytext);colno+=strlen(yytext); return(NAMED);}
.			{ strcpy(yylval.str,yytext);colno++;return CH;}
%%

int
buffpos(void)
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


/* ================================ EOF ============================= */



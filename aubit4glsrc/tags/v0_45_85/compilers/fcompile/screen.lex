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
/*%option interactive*/

%%
[\r] ;
[\n] 	{if (ignorekw==1) {graphics_mode=0;return KW_NL;} else {graphics_mode=0;REJECT; }}
[ ]	{ if (ignorekw==1) return KW_WS; }
[\t]	{ 	
		if (ignorekw==1) {return KW_TAB;}
	}
[	 \n]	;
<comment>"}"	{BEGIN INITIAL;}
<comment>.	;
<comment>[\n]	;

"\\g" 	{
		if (graphics_mode) graphics_mode=0;
		else graphics_mode=1;
		if (ignorekw==1) {
			return KW_NONSPACE;
		}
	}

--! 	{if (in_screen_section) REJECT; }
	
--[^!].* 	{if (in_screen_section) REJECT; 
}

[pdqb]  {
        if (ignorekw==0) REJECT;
        if (graphics_mode==0) REJECT;
        sprintf(yylval.str, "\n%s",yytext);
        return (GRAPH_CH);
}

[v<>+^] {
        if (graphics_mode==0) REJECT;
	if (!A4GL_isyes(acl_getenv("EXTENDED_GRAPHICS"))) REJECT;
        sprintf(yylval.str, "\n%s",yytext);
        return (GRAPH_CH);
}

"like"		{if (ignorekw) REJECT; strcpy(yylval.str, yytext); return(LIKE);}
"database"		{if (ignorekw) REJECT; strcpy(yylval.str, yytext); return(DATABASE);}
"instructions"		{if (ignorekw) REJECT; strcpy(yylval.str, yytext); return(INSTRUCTIONS);}
"attributes"		{if (ignorekw) REJECT; strcpy(yylval.str, yytext); buffpos();return(ATTRIBUTES);}
"screen"		{if (ignorekw) REJECT; strcpy(yylval.str, yytext); return(KW_SCREEN);}
"title"		{if (ignorekw) REJECT; strcpy(yylval.str, yytext); return(TITLE);}
screen[ 	]*title		{if (ignorekw) REJECT; strcpy(yylval.str, yytext); return(KW_SCREEN_TITLE);}
"type"		{if (ignorekw) REJECT; strcpy(yylval.str, yytext); return(TYPE);}

"year" 			{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return YEAR;}
"month" 			{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return MONTH;}
"day" 			{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return DAY;}
"hour" 			{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return HOUR;}
"minute" 			{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return MINUTE;}
"second" 			{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return SECOND;}
"fraction" 			{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return FRACTION;}
"validate" 			{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return VALIDATE;}


"record"		{if (ignorekw) REJECT; strcpy(yylval.str, yytext); return(RECORD);}
"formonly"		{if (ignorekw) REJECT; strcpy(yylval.str, yytext); return(FORMONLY);}
"size"		{ if (ignorekw) REJECT;strcpy(yylval.str, yytext); return(KW_SIZE);}
"by"		{if (ignorekw) REJECT; strcpy(yylval.str, yytext); return(BY);}
"["		{ strcpy(yylval.str, yytext); return(OPEN_SQUARE);}
"end"		{if (ignorekw) REJECT; strcpy(yylval.str, yytext); return(KW_END);}
"]"		{ strcpy(yylval.str, yytext); return(CLOSE_SQUARE);}
is[ ]+null 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return KWNULLCHK;}
is[ ]+not[ ]+null 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return KWNOTNULLCHK;}
"is null" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return KWNULLCHK;}
"is not null" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return KWNOTNULLCHK;}
[0-9]+|[0-9]*\.[0-9]+  	{if (ignorekw) REJECT; strcpy(yylval.str, yytext); return(NUMBER_VALUE);}


\"[^\"]+\" { if (in_screen_section==1) REJECT; strcpy(yylval.str,yytext); return CHAR_VALUE;}
\"(\"\"|[^"])*\" { if (in_screen_section==1) REJECT; strcpy(yylval.str,(char *)rm_dup_quotes(yytext)); return CHAR_VALUE;}
\"\" {  if (in_screen_section==1) REJECT;strcpy(yylval.str,yytext); return CHAR_VALUE;}
\'[^\']+\' {  if (in_screen_section==1) REJECT;strcpy(yylval.str,yytext); return CHAR_VALUE;}

\'\' { if (in_screen_section==1) REJECT; strcpy(yylval.str,yytext); return CHAR_VALUE;}

[	 \n]	;

"{" 		{if(in_screen_section!=0) {strcpy(yylval.str,yytext); return OPEN_BRACE; } else {	BEGIN comment; yymore(); } }
"}" 		{strcpy(yylval.str,yytext); return CLOSE_BRACE;}
"@" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return ATSIGN;}
":" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return COLON;}
">" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return COMPARISON;}
"!=" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return COMPARISON;}
"<" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return COMPARISON;}
">=" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return COMPARISON;}
"<=" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return COMPARISON;}
"MATCHES" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return COMPARISON;}
"where" 	{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return KWWHERE;}
"AND" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return KWAND;}
"OR" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return KWOR;}

"true" 		{if (ignorekw) REJECT;strcpy(yylval.str,"TRUE"); return XVAL;}
"false" 		{if (ignorekw) REJECT;strcpy(yylval.str,"FALSE"); return XVAL;}
"IN" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return KWIN;}
"BETWEEN" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return KWBETWEEN;}
"NOT" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return KWNOT;}

"." 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return DOT;}
"|" 		{ strcpy(yylval.str,yytext); 
			if (graphics_mode==0) {
				return PIPE; 
			} else {
				sprintf(yylval.str,"\n|");
				return GRAPH_CH; 
			}
		}
"=" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return EQUAL;}
"tables" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return TABLES;}
"without" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return WITHOUT;}
"null" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return KW_NULL;}
"input" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return INPUT;}
";" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return SEMICOLON;}
"(" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return OPEN_BRACKET;}
")" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return CLOSE_BRACKET;}
"*" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return STAR;}
"+" 		{if (ignorekw) REJECT;
			strcpy(yylval.str,yytext); 
			if (graphics_mode) {
				A4GL_debug("GM +");
				strcpy(yylval.str,"\n+");
				return CH;
				}
		return PLUS;
		}
- 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); 
			if (graphics_mode) {
				strcpy(yylval.str,"\n-");
				return CH;
				}
		return MINUS;
		}
"," 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return COMMA;}
"thru" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return THROUGH;}
"through" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return THROUGH;}
"delimiters" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return DELIMITERS;}
"delimiter" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return DELIMITERS;}
"char" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return KW_CHAR;}
"character" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return KW_CHAR;}
"string" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return KW_CHAR;}
"integer" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return KW_INT;}
"int" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return KW_INT;}
"serial" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return SERIAL;}
"byte" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return KW_BYTE;}
"text" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return KW_TEXT;}
"varchar" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return VARCHAR;}
"date" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return KW_DATE;}
"datetime" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return DATETIME;}
"float" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return KW_FLOAT;}
"smallfloat" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return SMALLFLOAT;}
"smallint" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return SMALLINT;}
"decimal" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return KW_DECIMAL;}
"dec" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return KW_DECIMAL;}
"money" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return MONEY;}
"widget" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return WIDGET;}
"config" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return CONFIG;}
"black" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return BLACK;}
"blue" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return BLUE;}
"white" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return WHITE;}
"yellow" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return YELLOW;}
"red" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return RED;}
"green" 	{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return GREEN;}
"cyan" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return CYAN;}

"magenta" 	{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return MAGENTA;}

"autonext"	{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return AUTONEXT;}
"color"		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return COLOR;}
"comments"	{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return COMMENTS;}
"default"	{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return DEFAULT;}
"display"		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return DISPLAY;}
"downshift"		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return DOWNSHIFT;}
"upshift"		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return UPSHIFT;}
"format"		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return FORMAT;}
"include"		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return INCLUDE;}
"invisible"		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return INVISIBLE;}
"noentry"		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return NOENTRY;}
"picture"		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return PICTURE;}
"program"		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return PROGRAM;}
"required"		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return REQUIRED;}
"dynamic"		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return DYNAMIC;}
"reverse"		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return REVERSE;}
"verify"		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return VERIFY;}
"wordwrap"		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return WORDWRAP;}
"compress"		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return COMPRESS;}
"noncompress"		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return NONCOMPRESS;}
"today"		{if (ignorekw) REJECT;strcpy(yylval.str,"TODAY"); return SQL_VAR;}
"user"		{if (ignorekw) REJECT;strcpy(yylval.str,"USER"); return SQL_VAR;}
"to"		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return TO;}
"as"		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return AS;}
"noupdate"		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return NOUPDATE;}
"zerofill"		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return SQLONLY;}
"left"		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return LEFT;}
"right"		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return SQLONLY;}
"listbox"		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return LISTBOX;}
"button"		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return BUTTON;}
"panel"		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return KW_PANEL;}

[a-zA-Z]+[a-zA-Z\_0-9]*	{
	if (ignorekw) REJECT;
	strcpy(yylval.str, yytext);
	A4GL_debug("NAMED : %s\n",yytext);
 	return(NAMED);
}
[a-zA-Z\_0-9]+[a-zA-Z\_0-9]*	{
if (ignorekw!=1) REJECT;
if (graphics_mode) {
	if (strchr(yytext,'p')) REJECT;
	if (strchr(yytext,'q')) REJECT;
	if (strchr(yytext,'b')) REJECT;
	if (strchr(yytext,'d')) REJECT;
	if (strchr(yytext,'-')) REJECT;
	if (strchr(yytext,'|')) REJECT;
	if (strchr(yytext,'+')) REJECT;
}
strcpy(yylval.str, yytext);
 A4GL_debug("NAMED : %s\n",yytext); 
return(NAMED);}

.	{
        if (ignorekw==0) REJECT;
	strcpy(yylval.str,yytext);

	if (graphics_mode) {
		if (
			strcmp(yytext,"+")==0 ||
			strcmp(yytext,"p")==0 ||
			strcmp(yytext,"q")==0 ||
			strcmp(yytext,"b")==0 ||
			strcmp(yytext,"d")==0 ||
			strcmp(yytext,"-")==0 ||
			strcmp(yytext,"|")==0 ) {
			sprintf(yylval.str,"\n%s",yytext);
			return  GRAPH_CH;
		}
	}
 A4GL_debug("CH : %s\n",yytext);  
return CH;
}
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


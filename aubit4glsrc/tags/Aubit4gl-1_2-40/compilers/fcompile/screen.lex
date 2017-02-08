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
%x instructions
%x escaped
%option yylineno
/*%option interactive*/
ID [a-zA-Z‰ﬂ£_]+[a-zA-Z\_0-9]*
IDEXT [a-zA-Z‰ﬂ£\_0-9]+[a-zA-Z\_0-9]*

%%

[\r] ;
[\n] 	{ if (ignorekw==1) {graphics_mode=0;return KW_NL;} else {graphics_mode=0;yylineno--;REJECT; }}
<escaped>[\n] 	{ if (ignorekw==1) {graphics_mode=0;return KW_NL;} else {graphics_mode=0;REJECT; }}
[ ]	{ if (ignorekw==1) return KW_WS; }
<escaped>[ ]	{ if (ignorekw==1) return KW_WS; }

[\t]	{ 	
		if (ignorekw==1) {return KW_TAB;}
	}
[	 \n]	;
<comment>"}"	{BEGIN INITIAL;}
<comment>.	;
<comment>[\n]	;


<escaped>g	{
		BEGIN INITIAL;
		if (graphics_mode) graphics_mode=0;
		else graphics_mode=1;

		if (ignorekw==1) {
			return KW_NONSPACE;
		}
}

<escaped>. {
	BEGIN INITIAL;
        if (ignorekw==0) {
			REJECT;
	}
	strcpy(yylval.str,yytext);
	if (graphics_mode) {
		int test_extend=0;
	        if (A4GL_isyes(acl_getenv("EXTENDED_GRAPHICS"))||extended_graphics==1) { 
			test_extend=1;
		}
		if (
			strcmp(yytext,"+")==0 ||
			strcmp(yytext,"p")==0 ||
			strcmp(yytext,"q")==0 ||
			strcmp(yytext,"b")==0 ||
			strcmp(yytext,"d")==0 ||
			strcmp(yytext,"-")==0 ||
			strcmp(yytext,"|")==0 ||
			(test_extend && ( 
				strcmp(yytext,"^")==0 ||
				strcmp(yytext,"v")==0 ||
				strcmp(yytext,"<")==0 ||
				strcmp(yytext,">")==0 ||
				strcmp(yytext,"+")==0))) {

						sprintf(yylval.str,"\n%s",yytext);
						return  GRAPH_CH;
		}
	}

#ifdef DEBUG
 	A4GL_debug("CH : %s\n",yytext);  
#endif
	return CH;
}
"]"		{ strcpy(yylval.str, yytext); return(CLOSE_SQUARE);}
"\\"		{ if (ignorekw==0) REJECT; BEGIN escaped; }
"["		{ strcpy(yylval.str, yytext); return(OPEN_SQUARE);}
"]"		{ strcpy(yylval.str, yytext); return(CLOSE_SQUARE);}



--$ {if (in_screen_section) REJECT; }
--\n {if (in_screen_section) REJECT; }

	
#.*$ {if (in_screen_section) REJECT; }
--! 	{ if (in_screen_section) REJECT; }
--# 	{ if (in_screen_section) REJECT; }
--[^!^\n^#].* 	{if (in_screen_section) REJECT; }

"uses extended" 	{ if (ignorekw) REJECT;strcpy(yylval.str,yytext); return KW_USES_EXTENDED; }
screen[ 	]*title		{if (ignorekw) REJECT; strcpy(yylval.str, yytext); return(KW_SCREEN_TITLE);}
is[ ]+null 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return KWNULLCHK;}
is[ ]+not[ ]+null 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return KWNOTNULLCHK;}
"is null" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return KWNULLCHK;}
"is not null" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return KWNOTNULLCHK;}
[0-9]+|[0-9]*\.[0-9]+  	{if (ignorekw) REJECT; strcpy(yylval.str, yytext); return(NUMBER_VALUE);}



\"[^\"]+\" { if (in_screen_section==1) REJECT; strcpy(yylval.str,yytext); return CHAR_VALUE;}
\"\" {  if (in_screen_section==1) REJECT;strcpy(yylval.str,yytext); return CHAR_VALUE;}
\"(\"\"|[^"])*\" { if (in_screen_section==1) REJECT;  strcpy(yylval.str,(char *)rm_dup_quotes(yytext)); return CHAR_VALUE;}
\'[^\']+\' {  if (in_screen_section==1) REJECT;strcpy(yylval.str,yytext); return CHAR_VALUE;}

\'\' { if (in_screen_section==1) REJECT; strcpy(yylval.str,yytext); return CHAR_VALUE;}

[	 \n]	;

"{!" 		;
"!}" 		;

"{" 		{
		 if(in_screen_section!=0) {strcpy(yylval.str,yytext); if (colno==0||!A4GL_isno(acl_getenv("FIRSTBRACE"))) {return OPEN_BRACE;} else {return CHAR_VALUE;} } else {	BEGIN comment; yymore(); } }
"}" 		{strcpy(yylval.str,yytext); if (colno==0||!A4GL_isno(acl_getenv("FIRSTBRACE"))) {return CLOSE_BRACE;} else {return CHAR_VALUE;}}
"@" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return ATSIGN;}
":" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return COLON;}
"!=" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return COMPARISON;}
"<>" 		{if (ignorekw) REJECT;strcpy(yylval.str,"!="); return COMPARISON;}
">=" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return COMPARISON;}
"<=" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return COMPARISON;}
"<" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext);  return LESSTHAN;}
">" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext);  return GREATERTHAN;}
"%%DBNAME%%"    {if (ignorekw) REJECT;strcpy(yylval.str,yytext); return SPECIAL_DBNAME;}

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
";" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return SEMICOLON;}
"(" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return OPEN_BRACKET;}
")" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return CLOSE_BRACKET;}
"*" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return STAR;}
"/" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return DIVIDE;}
"+" 		{if (ignorekw) REJECT;
			strcpy(yylval.str,yytext); 
			if (graphics_mode) {
#ifdef DEBUG
				A4GL_debug("GM +");
#endif
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
master[ 	]+of 	{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return KW_MASTER_OF;}
"not matches" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return COMPARISON;}


"matches" 		{if (ign_kw(yystate, COMPARISON)) REJECT;strcpy(yylval.str,yytext); return COMPARISON;}
"where" 	{if (ign_kw(yystate, KWWHERE)) REJECT;strcpy(yylval.str,yytext); return KWWHERE;}
"and" 		{if (ign_kw(yystate, KWAND)) REJECT;strcpy(yylval.str,yytext); return KWAND;}
"or" 		{if (ign_kw(yystate, KWOR)) REJECT;strcpy(yylval.str,yytext); return KWOR;}

"true" 		{if (ign_kw(yystate, XVAL)) REJECT;strcpy(yylval.str,"TRUE"); return XVAL;}
"false" 		{if (ign_kw(yystate, XVAL)) REJECT;strcpy(yylval.str,"FALSE"); return XVAL;}
"in" 		{if (ign_kw(yystate, KWIN)) REJECT;strcpy(yylval.str,yytext); return KWIN;}
"between" 		{if (ign_kw(yystate, KWBETWEEN)) REJECT;strcpy(yylval.str,yytext); return KWBETWEEN;}
"not" 		{if (ign_kw(yystate, KWNOT)) REJECT;strcpy(yylval.str,yytext); return KWNOT;}
"tables" 		{if (ign_kw(yystate, TABLES)) REJECT;strcpy(yylval.str,yytext); return TABLES;}
"without" 		{if (ign_kw(yystate, WITHOUT)) REJECT;strcpy(yylval.str,yytext); return WITHOUT;}
"null" 		{if (ign_kw(yystate, KW_NULL)) REJECT;strcpy(yylval.str,yytext); return KW_NULL;}
"input" 		{if (ign_kw(yystate,INPUT)) REJECT;strcpy(yylval.str,yytext); return INPUT;}
"like"		{if (ign_kw(yystate, LIKE)) REJECT; strcpy(yylval.str, yytext); return(LIKE);}
"database"		{if (ign_kw(yystate, DATABASE)) REJECT; strcpy(yylval.str, yytext); return(DATABASE);}
"character encoding"		{if (ign_kw(yystate, CHARACTER_ENCODING)) REJECT; strcpy(yylval.str, yytext); return(CHARACTER_ENCODING);}
"schema"		{if (ign_kw(yystate, DATABASE)) REJECT; strcpy(yylval.str, yytext); return(DATABASE);}
"instructions"		{if (ign_kw(yystate,INSTRUCTIONS)) REJECT; strcpy(yylval.str, yytext); return(INSTRUCTIONS);}
"attributes"		{if (ign_kw(yystate, ATTRIBUTES)) REJECT; strcpy(yylval.str, yytext); buffpos();return(ATTRIBUTES);}
"screen"		{if (ign_kw(yystate, KW_SCREEN)) REJECT; strcpy(yylval.str, yytext); return(KW_SCREEN);}
"title"		{if (ign_kw(yystate, TITLE)) REJECT; strcpy(yylval.str, yytext); return(TITLE);}
"type"		{if (ign_kw(yystate, TYPE)) REJECT; strcpy(yylval.str, yytext); return(TYPE);}

"year" 			{if (ign_kw(yystate, YEAR)) REJECT;strcpy(yylval.str,yytext); return YEAR;}
"month" 			{if (ign_kw(yystate, MONTH)) REJECT;strcpy(yylval.str,yytext); return MONTH;}
"day" 			{if (ign_kw(yystate, DAY)) REJECT;strcpy(yylval.str,yytext); return DAY;}
"hour" 			{if (ign_kw(yystate, HOUR)) REJECT;strcpy(yylval.str,yytext); return HOUR;}
"minute" 			{if (ign_kw(yystate, MINUTE)) REJECT;strcpy(yylval.str,yytext); return MINUTE;}
"second" 			{if (ign_kw(yystate, SECOND)) REJECT;strcpy(yylval.str,yytext); return SECOND;}
"fraction" 			{if (ign_kw(yystate,FRACTION)) REJECT;strcpy(yylval.str,yytext); return FRACTION;}
"validate" 			{if (ign_kw(yystate,VALIDATE)) REJECT;strcpy(yylval.str,yytext); return VALIDATE;}


"action"		{if (ign_kw(yystate, KW_ACTION)) REJECT; strcpy(yylval.str, yytext); return(KW_ACTION);}
"record"		{if (ign_kw(yystate, RECORD)) REJECT; strcpy(yylval.str, yytext); return(RECORD);}
"formonly"		{if (ign_kw(yystate, FORMONLY)) REJECT; strcpy(yylval.str, yytext); return(FORMONLY);}
"size"		{ if (ign_kw(yystate, KW_SIZE)) REJECT;strcpy(yylval.str, yytext); return(KW_SIZE);}
"by"		{if (ign_kw(yystate, BY)) REJECT; strcpy(yylval.str, yytext); return(BY);}


"end"		{if (ign_kw(yystate, KW_END)) REJECT; strcpy(yylval.str, yytext); return(KW_END);}
"thru" 		{if (ign_kw(yystate, THROUGH)) REJECT;strcpy(yylval.str,yytext); return THROUGH;}
"through" 		{if (ign_kw(yystate, THROUGH)) REJECT;strcpy(yylval.str,yytext); return THROUGH;}
"delimiters" 		{if (ign_kw(yystate, DELIMITERS)) REJECT;strcpy(yylval.str,yytext); return DELIMITERS;}
"delimiter" 		{if (ign_kw(yystate, DELIMITERS)) REJECT;strcpy(yylval.str,yytext); return DELIMITERS;}
"char" 		{if (ign_kw(yystate, KW_CHAR)) REJECT;strcpy(yylval.str,yytext); return KW_CHAR;}
"character" 		{if (ign_kw(yystate, KW_CHAR)) REJECT;strcpy(yylval.str,yytext); return KW_CHAR;}
"string" 		{if (ign_kw(yystate, KW_CHAR)) REJECT;strcpy(yylval.str,yytext); return KW_CHAR;}
"integer" 		{if (ign_kw(yystate, KW_INT)) REJECT;strcpy(yylval.str,yytext); return KW_INT;}
"int" 		{if (ign_kw(yystate, KW_INT)) REJECT;strcpy(yylval.str,yytext); return KW_INT;}
"serial" 		{if (ign_kw(yystate, SERIAL)) REJECT;strcpy(yylval.str,yytext); return SERIAL;}
"byte" 		{if (ign_kw(yystate, KW_BYTE)) REJECT;strcpy(yylval.str,yytext); return KW_BYTE;}
"text" 		{if (ign_kw(yystate, KW_TEXT)) REJECT;strcpy(yylval.str,yytext); return KW_TEXT;}
"header" 		{if (ign_kw(yystate, KW_HEADER)) REJECT;strcpy(yylval.str,yytext); return KW_HEADER;}
"varchar" 		{if (ign_kw(yystate, VARCHAR)) REJECT;strcpy(yylval.str,yytext); return VARCHAR;}
"date" 		{if (ign_kw(yystate, KW_DATE)) REJECT;strcpy(yylval.str,yytext); return KW_DATE;}
"datetime" 		{if (ign_kw(yystate,DATETIME)) REJECT;strcpy(yylval.str,yytext); return DATETIME;}
"interval" 		{if (ign_kw(yystate,INTERVAL)) REJECT;strcpy(yylval.str,yytext); return INTERVAL;}
"float" 		{if (ign_kw(yystate, KW_FLOAT)) REJECT;strcpy(yylval.str,yytext); return KW_FLOAT;}
"double precision" 		{if (ign_kw(yystate, KW_FLOAT)) REJECT;strcpy(yylval.str,yytext); return KW_FLOAT;}
"real" 		{if (ign_kw(yystate, SMALLFLOAT)) REJECT;strcpy(yylval.str,yytext); return SMALLFLOAT;}
"numeric" 		{if (ign_kw(yystate, KW_DECIMAL)) REJECT;strcpy(yylval.str,yytext); return KW_DECIMAL;}
"smallfloat" 		{if (ign_kw(yystate, SMALLFLOAT)) REJECT;strcpy(yylval.str,yytext); return SMALLFLOAT;}
"smallint" 		{if (ign_kw(yystate, SMALLINT)) REJECT;strcpy(yylval.str,yytext); return SMALLINT;}
"decimal" 		{if (ign_kw(yystate, KW_DECIMAL)) REJECT;strcpy(yylval.str,yytext); return KW_DECIMAL;}
"dec" 		{if (ign_kw(yystate, KW_DECIMAL)) REJECT;strcpy(yylval.str,yytext); return KW_DECIMAL;}

"evenlines" 		{if (ign_kw(yystate, KW_LINEISEVEN)) REJECT;strcpy(yylval.str,yytext); return KW_LINEISEVEN;}
"oddlines" 		{if (ign_kw(yystate, KW_LINEISODD)) REJECT;strcpy(yylval.str,yytext); return KW_LINEISODD;}

"money" 		{if (ign_kw(yystate, MONEY)) REJECT;strcpy(yylval.str,yytext); return MONEY;}
"widget" 		{if (ign_kw(yystate, WIDGET)) REJECT;strcpy(yylval.str,yytext); return WIDGET;}
"options" 		{if (ign_kw(yystate, OPTIONS)) REJECT;strcpy(yylval.str,yytext); return OPTIONS;}
"config" 		{if (ign_kw(yystate, CONFIG)) REJECT;strcpy(yylval.str,yytext); return CONFIG;}
"black" 		{if (ign_kw(yystate, BLACK)) REJECT;strcpy(yylval.str,yytext); return BLACK;}
"blue" 		{if (ign_kw(yystate, BLUE)) REJECT;strcpy(yylval.str,yytext); return BLUE;}
"white" 		{if (ign_kw(yystate, WHITE)) REJECT;strcpy(yylval.str,yytext); return WHITE;}
"yellow" 		{if (ign_kw(yystate, YELLOW)) REJECT;strcpy(yylval.str,yytext); return YELLOW;}
"red" 		{if (ign_kw(yystate, RED)) REJECT;strcpy(yylval.str,yytext); return RED;}
"green" 	{if (ign_kw(yystate, GREEN)) REJECT;strcpy(yylval.str,yytext); return GREEN;}
"cyan" 		{if (ign_kw(yystate, CYAN)) REJECT;strcpy(yylval.str,yytext); return CYAN;}
"blink" 		{if (ign_kw(yystate, BLINK)) REJECT;strcpy(yylval.str,yytext); return BLINK;}
"underline" 		{if (ign_kw(yystate, UNDERLINE)) REJECT;strcpy(yylval.str,yytext); return UNDERLINE;}

"magenta" 	{if (ign_kw(yystate, MAGENTA)) REJECT;strcpy(yylval.str,yytext); return MAGENTA;}

"autonext"	{if (ign_kw(yystate, AUTONEXT)) REJECT;strcpy(yylval.str,yytext); return AUTONEXT;}
"autosize"	{if (ign_kw(yystate, KW_AUTOSIZE)) REJECT;strcpy(yylval.str,yytext); return KW_AUTOSIZE;}
"color"		{if (ign_kw(yystate, COLOR)) REJECT;strcpy(yylval.str,yytext); return COLOR;}
"composites"		{if (ign_kw(yystate, KW_COMPOSITES)) REJECT;strcpy(yylval.str,yytext); return KW_COMPOSITES;}
"comments"	{if (ign_kw(yystate, COMMENTS)) REJECT;strcpy(yylval.str,yytext); return COMMENTS;}
"comment"	{if (ign_kw(yystate, COMMENTS)) REJECT;strcpy(yylval.str,yytext); return COMMENTS;}
"default"	{if (ign_kw(yystate, DEFAULT)) REJECT;strcpy(yylval.str,yytext); return DEFAULT;}
"display"		{if (ign_kw(yystate, DISPLAY)) REJECT;strcpy(yylval.str,yytext); return DISPLAY;}
"downshift"		{if (ign_kw(yystate, DOWNSHIFT)) REJECT;strcpy(yylval.str,yytext); return DOWNSHIFT;}
"upshift"		{if (ign_kw(yystate, UPSHIFT)) REJECT;strcpy(yylval.str,yytext); return UPSHIFT;}
"format"		{if (ign_kw(yystate, FORMAT)) REJECT;strcpy(yylval.str,yytext); return FORMAT;}
"include"		{if (ign_kw(yystate, INCLUDE)) REJECT;strcpy(yylval.str,yytext); return INCLUDE;}
"invisible"		{if (ign_kw(yystate, INVISIBLE)) REJECT;strcpy(yylval.str,yytext); return INVISIBLE;}
"noentry"		{if (ign_kw(yystate, NOENTRY)) REJECT;strcpy(yylval.str,yytext); return NOENTRY;}
"picture"		{if (ign_kw(yystate, PICTURE)) REJECT;strcpy(yylval.str,yytext); return PICTURE;}
"program"		{if (ign_kw(yystate, PROGRAM)) REJECT;strcpy(yylval.str,yytext); return PROGRAM;}
"required"		{if (ign_kw(yystate, REQUIRED)) REJECT;strcpy(yylval.str,yytext); return REQUIRED;}
"unhidable"		{if (ign_kw(yystate, UNHIDABLE)) REJECT;strcpy(yylval.str,yytext); return UNHIDABLE;}
"dynamic"		{if (ign_kw(yystate, DYNAMIC)) REJECT;strcpy(yylval.str,yytext); return DYNAMIC;}
"dim"		{if (ign_kw(yystate, DIM)) REJECT;strcpy(yylval.str,yytext); return DIM;}
"bold"		{if (ign_kw(yystate,BOLD)) REJECT;strcpy(yylval.str,yytext); return BOLD;}
"normal"		{if (ign_kw(yystate,NORMAL)) REJECT;strcpy(yylval.str,yytext); return NORMAL;}
"reverse"		{if (ign_kw(yystate,REVERSE)) REJECT;strcpy(yylval.str,yytext); return REVERSE;}
"verify"		{if (ign_kw(yystate, VERIFY)) REJECT;strcpy(yylval.str,yytext); return VERIFY;}
"queryclear"		{if (ign_kw(yystate, QUERYCLEAR)) REJECT;strcpy(yylval.str,yytext); return QUERYCLEAR;}
"displayonly"		{if (ign_kw(yystate, DISPLAYONLY)) REJECT;strcpy(yylval.str,yytext); return DISPLAYONLY;}
"allowing"		{if (ign_kw(yystate, ALLOWING)) REJECT;strcpy(yylval.str,yytext); return ALLOWING;}

"lookup" 	{if (ign_kw(yystate, LOOKUP)) REJECT;strcpy(yylval.str,yytext); return LOOKUP;}
"lookup from" 	{if (ign_kw(yystate, LOOKUP_FROM)) REJECT;strcpy(yylval.str,yytext); return LOOKUP_FROM;}
"joining" 	{if (ign_kw(yystate, JOINING)) REJECT;strcpy(yylval.str,yytext); return JOINING;}
"wordwrap"		{if (ign_kw(yystate, WORDWRAP)) REJECT;strcpy(yylval.str,yytext); return WORDWRAP;}
"compress"		{if (ign_kw(yystate, COMPRESS)) REJECT;strcpy(yylval.str,yytext); return COMPRESS;}
"noncompress"		{if (ign_kw(yystate, NONCOMPRESS)) REJECT;strcpy(yylval.str,yytext); return NONCOMPRESS;}
"today"		{if (ign_kw(yystate, SQL_VAR)) REJECT;strcpy(yylval.str,"TODAY"); return SQL_VAR;}
"user"		{if (ign_kw(yystate, SQL_VAR)) REJECT;strcpy(yylval.str,"USER"); return SQL_VAR;}
"current"		{if (ign_kw(yystate, SQL_VAR)) REJECT;strcpy(yylval.str,"CURRENT"); return SQL_VAR;}
"to"		{if (ign_kw(yystate,TO)) REJECT;strcpy(yylval.str,yytext); return TO;}
"as"		{if (ign_kw(yystate,AS)) REJECT;strcpy(yylval.str,yytext); return AS;}
"noupdate"		{if (ign_kw(yystate, NOUPDATE)) REJECT;strcpy(yylval.str,yytext); return NOUPDATE;}
"left"		{if (ign_kw(yystate, LEFT)) REJECT;strcpy(yylval.str,yytext); return LEFT;}



 
"page"		{if (ign_kw(yystate, KW_PAGE)) REJECT;strcpy(yylval.str,yytext); return KW_PAGE;}
"hbox"		{if (ign_kw(yystate, KW_HBOX)) REJECT;strcpy(yylval.str,yytext); return KW_HBOX;}
"vbox"		{if (ign_kw(yystate, KW_VBOX)) REJECT;strcpy(yylval.str,yytext); return KW_VBOX;}
"grid"		{if (ign_kw(yystate, KW_GRID)) REJECT;strcpy(yylval.str,yytext); return KW_GRID;}
"group"		{if (ign_kw(yystate, KW_GROUP)) REJECT;strcpy(yylval.str,yytext); return KW_GROUP;}
"table"		{if (ign_kw(yystate, KW_TABLE)) REJECT;strcpy(yylval.str,yytext); return KW_TABLE;}
"folder"	{if (ign_kw(yystate, KW_FOLDER)) REJECT;strcpy(yylval.str,yytext); return KW_FOLDER;}
"style"		{if (ign_kw(yystate, KW_STYLE)) REJECT;strcpy(yylval.str,yytext); return KW_STYLE;}
"layout"		{if (ign_kw(yystate, KW_LAYOUT)) REJECT;strcpy(yylval.str,yytext); return KW_LAYOUT;}
"hidden"		{if (ign_kw(yystate, KW_HIDDEN)) REJECT;strcpy(yylval.str,yytext); return KW_HIDDEN;}
"noshow"		{if (ign_kw(yystate, KW_NOSHOW)) REJECT;strcpy(yylval.str,yytext); return KW_NOSHOW;}
"scroll"		{if (ign_kw(yystate, KW_SCROLL)) REJECT;strcpy(yylval.str,yytext); return KW_SCROLL;}
"textedit"		{if (ign_kw(yystate, KW_TEXTEDIT)) REJECT;strcpy(yylval.str,yytext); return KW_TEXTEDIT;}
"edit"		{if (ign_kw(yystate, KW_EDIT)) REJECT;strcpy(yylval.str,yytext); return KW_EDIT;}
"dateedit"		{if (ign_kw(yystate, KW_DATEEDIT)) REJECT;strcpy(yylval.str,yytext); return KW_DATEEDIT;}
"buttonedit"		{if (ign_kw(yystate, KW_BUTTONEDIT)) REJECT;strcpy(yylval.str,yytext); return KW_BUTTONEDIT;}
"label"		{if (ign_kw(yystate, KW_LABEL)) REJECT;strcpy(yylval.str,yytext); return KW_LABEL;}
"image"		{if (ign_kw(yystate, KW_IMAGE)) REJECT;strcpy(yylval.str,yytext); return KW_IMAGE;}
"fontpitch"		{if (ign_kw(yystate, KW_FONTPITCH)) REJECT;strcpy(yylval.str,yytext); return KW_FONTPITCH;}
"fixed"		{if (ign_kw(yystate, KW_FIXED)) REJECT;strcpy(yylval.str,yytext); return KW_FIXED;}
"variable"		{if (ign_kw(yystate, KW_VARIABLE)) REJECT;strcpy(yylval.str,yytext); return KW_VARIABLE;}
"wantnoreturns"		{if (ign_kw(yystate, KW_WANTNORETURNS)) REJECT;strcpy(yylval.str,yytext); return KW_WANTNORETURNS;}
"wantreturns"		{if (ign_kw(yystate, KW_WANTRETURNS)) REJECT;strcpy(yylval.str,yytext); return KW_WANTRETURNS;}
"wanttabs"		{if (ign_kw(yystate, KW_WANTTABS)) REJECT;strcpy(yylval.str,yytext); return KW_WANTTABS;}
"autoscale"		{if (ign_kw(yystate, KW_AUTOSCALE)) REJECT;strcpy(yylval.str,yytext); return KW_AUTOSCALE;}
"pixelwidth"		{if (ign_kw(yystate, KW_PIXELWIDTH)) REJECT;strcpy(yylval.str,yytext); return KW_PIXELWIDTH;}
"pixelheight"		{if (ign_kw(yystate, KW_PIXELHEIGHT)) REJECT;strcpy(yylval.str,yytext); return KW_PIXELHEIGHT;}
"scrollbars=both"		{if (ign_kw(yystate, KW_SCROLLBARS_BOTH)) REJECT;strcpy(yylval.str,yytext); return KW_SCROLLBARS_BOTH;}
"scrollbars=vertical"		{if (ign_kw(yystate, KW_SCROLLBARS_V)) REJECT;strcpy(yylval.str,yytext); return KW_SCROLLBARS_V;}
"scrollbars=horizonal"		{if (ign_kw(yystate, KW_SCROLLBARS_H)) REJECT;strcpy(yylval.str,yytext); return KW_SCROLLBARS_H;}
"stretch=y"		{if (ign_kw(yystate, KW_STRETCH_Y)) REJECT;strcpy(yylval.str,yytext); return KW_STRETCH_Y;}
"stretch=both"		{if (ign_kw(yystate, KW_STRETCH_BOTH)) REJECT;strcpy(yylval.str,yytext); return KW_STRETCH_BOTH;}
"items"		{if (ign_kw(yystate,KW_ITEMS )) REJECT;strcpy(yylval.str,yytext); return KW_ITEMS;}
"valuemax"		{if (ign_kw(yystate, KW_VALUEMAX)) REJECT;strcpy(yylval.str,yytext); return KW_VALUEMAX;}
"valuemin"		{if (ign_kw(yystate, KW_VALUEMIN)) REJECT;strcpy(yylval.str,yytext); return KW_VALUEMIN;}
"progressbar"		{if (ign_kw(yystate, KW_PROGRESSBAR)) REJECT;strcpy(yylval.str,yytext); return KW_PROGRESSBAR;}
"combobox"		{if (ign_kw(yystate, KW_COMBOBOX)) REJECT;strcpy(yylval.str,yytext); return KW_COMBOBOX;}
"checkbox"		{if (ign_kw(yystate, KW_CHECKBOX)) REJECT;strcpy(yylval.str,yytext); return KW_CHECKBOX;}
"valuechecked"		{if (ign_kw(yystate, KW_VALUECHECKED)) REJECT;strcpy(yylval.str,yytext); return KW_VALUECHECKED;}
"valueunchecked"	{if (ign_kw(yystate, KW_VALUEUNCHECKED)) REJECT;strcpy(yylval.str,yytext); return KW_VALUEUNCHECKED;}
"browser"		{if (ign_kw(yystate, KW_BROWSER)) REJECT;strcpy(yylval.str,yytext); return KW_BROWSER;}

"zerofill"		{if (ign_kw(yystate, KW_ZEROFILL)) REJECT;strcpy(yylval.str,yytext); if (doing_4gl()) return SQLONLY; else return KW_ZEROFILL;}
"right"			{if (ign_kw(yystate, KW_RIGHT)) REJECT;strcpy(yylval.str,yytext);  return KW_RIGHT;}
"justify"			{if (ign_kw(yystate, KW_JUSTIFY)) REJECT;strcpy(yylval.str,yytext);  return KW_JUSTIFY;}
"tabindex"			{if (ign_kw(yystate, KW_TABINDEX)) REJECT;strcpy(yylval.str,yytext);  return KW_TABINDEX;}
"not null"			{if (ign_kw(yystate, KW_NOT_NULL)) REJECT;strcpy(yylval.str,yytext);  return KW_NOT_NULL;}
"center"			{if (ign_kw(yystate, KW_CENTER)) REJECT;strcpy(yylval.str,yytext);  return KW_CENTER;}
"listbox"		{if (ign_kw(yystate, LISTBOX)) REJECT;strcpy(yylval.str,yytext); return LISTBOX;}
"button"		{if (ign_kw(yystate, BUTTON)) REJECT;strcpy(yylval.str,yytext); return BUTTON;}
"panel"		{if (ign_kw(yystate, KW_PANEL)) REJECT;strcpy(yylval.str,yytext); return KW_PANEL;}

"before" 	{if (ign_kw(yystate, KW_BEFORE)||doing_4gl()) REJECT;strcpy(yylval.str,yytext); return KW_BEFORE ;}
"after" 	{if (ign_kw(yystate, KW_AFTER)||doing_4gl()) REJECT;strcpy(yylval.str,yytext); return KW_AFTER ;}
"editadd" 	{if (ign_kw(yystate, KW_EDITADD)||doing_4gl()) REJECT;strcpy(yylval.str,yytext); return KW_EDITADD ;}
"editupdate" 	{if (ign_kw(yystate, KW_EDITUPDATE)||doing_4gl()) REJECT;strcpy(yylval.str,yytext); return KW_EDITUPDATE ;}
"if" 		{if (ign_kw(yystate, KW_IF)||doing_4gl()) REJECT;strcpy(yylval.str,yytext); return KW_IF ;}
"remove" 	{if (ign_kw(yystate, KW_REMOVE)||doing_4gl()) REJECT;strcpy(yylval.str,yytext); return KW_REMOVE ;}
"of" 		{if (ign_kw(yystate, KW_OF)||doing_4gl()) REJECT;strcpy(yylval.str,yytext); return KW_OF;}
"add" 		{if (ign_kw(yystate, KW_ADD)||doing_4gl()) REJECT;strcpy(yylval.str,yytext); return KW_ADD ;}
"update" 	{if (ign_kw(yystate, KW_UPDATE)||doing_4gl()) REJECT;strcpy(yylval.str,yytext); return KW_UPDATE ;}
"query" 	{if (ign_kw(yystate, KW_QUERY)||doing_4gl()) REJECT;strcpy(yylval.str,yytext); return KW_QUERY ;}
on[ 	]ending 	{if (ign_kw(yystate, KW_ON_ENDING)||doing_4gl()) REJECT;strcpy(yylval.str,yytext); return KW_ON_ENDING ;}
on[	 ]beginning 	{if (ign_kw(yystate, KW_ON_BEGINNING)||doing_4gl()) REJECT;strcpy(yylval.str,yytext); return KW_ON_BEGINNING;}
"call" 		{if (ign_kw(yystate, KW_CALL)||doing_4gl()) REJECT;strcpy(yylval.str,yytext); return KW_CALL;}
"bell" 		{if (ign_kw(yystate, KW_BELL)||doing_4gl()) REJECT;strcpy(yylval.str,yytext); return KW_BELL ;}
"abort" 	{if (ign_kw(yystate, KW_ABORT)||doing_4gl()) REJECT;strcpy(yylval.str,yytext); return KW_ABORT ;}
"let" 		{if (ign_kw(yystate, KW_LET)||doing_4gl()) REJECT;strcpy(yylval.str,yytext); return KW_LET ;}
"exitnow" 	{if (ign_kw(yystate, KW_EXITNOW)||doing_4gl()) REJECT;strcpy(yylval.str,yytext); return KW_EXITNOW ;}
"nextfield" 	{if (ign_kw(yystate, KW_NEXTFIELD)||doing_4gl()) REJECT;strcpy(yylval.str,yytext); return KW_NEXTFIELD;}
"then" 		{if (ign_kw(yystate, KW_THEN)||doing_4gl()) REJECT;strcpy(yylval.str,yytext); return KW_THEN ;}
"else" 		{if (ign_kw(yystate, KW_ELSE)||doing_4gl()) REJECT;strcpy(yylval.str,yytext); return KW_ELSE;}
"begin" 	{if (ign_kw(yystate, KW_BEGIN)||doing_4gl()) REJECT;strcpy(yylval.str,yytext); return KW_BEGIN;}
"total" 	{if (ign_kw(yystate, KW_TOTAL)||doing_4gl()) REJECT;strcpy(yylval.str,yytext); return KW_TOTAL;}







`{ID}` {
/* [a-zA-Z‰ﬂ£_]+[a-zA-Z\_0-9]*	 */
	char buff[20000];
	if (ignorekw) REJECT;
	strcpy(buff,&yytext[1]);
	char *ptr=strchr(buff,'`');
	if (ptr) *ptr=0;
	strcpy(yylval.str, buff);
#ifdef DEBUG
	A4GL_debug("NAMED : %s\n",buff);
#endif
	if (yydebug) {printf("NAMED: %s\n",buff); fflush(stdout);}
 	return(NAMED_CASE_SPECIFIC);
}

{ID} {
/* [a-zA-Z‰ﬂ£_]+[a-zA-Z\_0-9]*	 */
	if (ignorekw) REJECT;
	strcpy(yylval.str, yytext);
#ifdef DEBUG
	A4GL_debug("NAMED : %s\n",yytext);
#endif
	if (yydebug) {printf("NAMED: %s\n",yytext); fflush(stdout);}
 	return(NAMED);
}

{IDEXT} {
/*[a-zA-Z‰ﬂ£\_0-9]+[a-zA-Z\_0-9]*	*/
if (ignorekw!=1) REJECT;

        if (graphics_mode) {
                int test_extend=0;
                if (A4GL_isyes(acl_getenv("EXTENDED_GRAPHICS"))||extended_graphics==1) {
                        test_extend=1;
                }
                if (
			 ((strcmp(yytext,"p")==0 || strcmp(yytext,"q")==0 || strcmp(yytext,"b")==0 || strcmp(yytext,"d")==0 ) &&fstart==-1) ||
                        strcmp(yytext,"+")==0 ||
                        strcmp(yytext,"-")==0 ||
                        strcmp(yytext,"|")==0 ||
                        (test_extend && (
                                strcmp(yytext,"^")==0 ||
                                strcmp(yytext,"v")==0 ||
                                strcmp(yytext,"<")==0 ||
                                strcmp(yytext,">")==0 ))) { REJECT;}


}

strcpy(yylval.str, yytext);
#ifdef DEBUG
 A4GL_debug("NAMED : %s\n",yytext); 
	A4GL_debug("NAMED : %s\n",yytext);
#endif
	if (yydebug) {printf("NAMED: %s\n",yytext); fflush(stdout);}
return(NAMED);}

.	{
        if (ignorekw==0) REJECT;
	strcpy(yylval.str,yytext);
	if (graphics_mode) {
		int test_extend=0;
	        if (A4GL_isyes(acl_getenv("EXTENDED_GRAPHICS"))||extended_graphics==1) { 
			test_extend=1;
		}
		if (
			 ((strcmp(yytext,"p")==0 || strcmp(yytext,"q")==0 || strcmp(yytext,"b")==0 || strcmp(yytext,"d")==0 ) &&fstart==-1)

			||
			strcmp(yytext,"+")==0 ||
			strcmp(yytext,"-")==0 ||
			strcmp(yytext,"|")==0 ||
			(test_extend && ( 
				strcmp(yytext,"^")==0 ||
				strcmp(yytext,"v")==0 ||
				strcmp(yytext,"<")==0 ||
				strcmp(yytext,">")==0 ))) {

						sprintf(yylval.str,"\n%s",yytext);
						return  GRAPH_CH;
		}
	}


#ifdef DEBUG
 A4GL_debug("CH : %s\n",yytext);  
#endif
	if (yydebug) printf("%s\n",yytext);
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
#include "mk_fstates.c"

void dummy_not_used_prevent_warning(void);

/* dummy function to eliminate wanrings about static
functions not being used */
void
dummy_not_used_prevent_warning(void)
{
	/* static void *yy_flex_realloc YY_PROTO(( void *, yy_size_t )); */
	//yy_flex_realloc (0,0);

	/* static void yyunput YY_PROTO(( int c, char *buf_ptr )); */
	//yyunput (0,0);
}

int ign_kw(int yystate,int kw) {
	if (ignorekw) return 1;
	if (!FORMPARSE_allow_token_state(yystate,kw)) return 1;
	return 0;

}
/* ============================== EOF =============================== */


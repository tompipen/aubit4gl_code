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

"database"		{if (ignorekw) REJECT; strcpy(yylval.str, yytext); return(DATABASE);}
"instructions"		{if (ignorekw) REJECT; strcpy(yylval.str, yytext); return(INSTRUCTIONS);}
"attributes"		{if (ignorekw) REJECT; strcpy(yylval.str, yytext); buffpos();return(ATTRIBUTES);}
"screen"		{if (ignorekw) REJECT; strcpy(yylval.str, yytext); return(KW_SCREEN);}
"title"		{if (ignorekw) REJECT; strcpy(yylval.str, yytext); return(TITLE);}
"type"		{if (ignorekw) REJECT; strcpy(yylval.str, yytext); return(TYPE);}
"record"		{if (ignorekw) REJECT; strcpy(yylval.str, yytext); return(RECORD);}
"formonly"		{if (ignorekw) REJECT; strcpy(yylval.str, yytext); return(FORMONLY);}
"size"		{ if (ignorekw) REJECT;strcpy(yylval.str, yytext); return(KW_SIZE);}
"by"		{if (ignorekw) REJECT; strcpy(yylval.str, yytext); return(BY);}
"["		{ strcpy(yylval.str, yytext); colno++;return(OPEN_SQUARE);}
"end"		{if (ignorekw) REJECT; strcpy(yylval.str, yytext); return(KW_END);}
"]"		{ strcpy(yylval.str, yytext); colno++;return(CLOSE_SQUARE);}
[0-9]+|[0-9]*\.[0-9]+  	{if (ignorekw) REJECT; strcpy(yylval.str, yytext); return(NUMBER_VALUE);}
\"[^\"]+\" { strcpy(yylval.str,yytext); return CHAR_VALUE;}
[	 \n]	;
"{" 		{if(in_screen_section!=0) {strcpy(yylval.str,yytext); return OPEN_BRACE;}
else {	
	BEGIN comment;
	yymore();
}
}

"}" 		{strcpy(yylval.str,yytext); return CLOSE_BRACE;}
"@" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return ATSIGN;}
":" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return COLON;}
"." 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return DOT;}
"|" 		{strcpy(yylval.str,yytext); colno++;return PIPE;}
"=" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return EQUAL;}
"tables" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return TABLES;}
"without" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return WITHOUT;}
"null" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return KW_NULL;}
"input" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return INPUT;}
";" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return SEMICOLON;}
"(" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return OPEN_BRACKET;}
")" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return CLOSE_BRACKET;}
"*" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return STAR;}
"," 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return COMMA;}
"thru" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return THROUGH;}
"through" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return THROUGH;}
"like" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return LIKE;}
"not" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return NOT;}
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
"float" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return KW_FLOAT;}
"smallfloat" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return SMALLFLOAT;}
"smallint" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return SMALLINT;}
"decimal" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return KW_DECIMAL;}
"money" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return MONEY;}
"widget" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return WIDGET;}
"config" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return CONFIG;}
"black" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return BLACK;}
"blue" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return BLUE;}
"white" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return WHITE;}
"yellow" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return YELLOW;}
"red" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return RED;}
"green" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return GREEN;}
"cyan" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return CYAN;}

"magenta" 		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return MAGENTA;}

"autonext"		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return AUTONEXT;}
"color"		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return COLOR;}
"comments"		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return COMMENTS;}
"default"		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return DEFAULT;}
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
"noupdate"		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return SQLONLY;}
"zerofill"		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return SQLONLY;}
"left"		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return SQLONLY;}
"right"		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return SQLONLY;}



"listbox"		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return LISTBOX;}
"button"		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return BUTTON;}
"panel"		{if (ignorekw) REJECT;strcpy(yylval.str,yytext); return KW_PANEL;}
[a-zA-Z]+[a-zA-Z\_0-9]*	{if (ignorekw) REJECT;strcpy(yylval.str, yytext);colno+=strlen(yytext); return(NAMED);}
[a-zA-Z\_0-9]+[a-zA-Z\_0-9]*	{if (ignorekw!=1) REJECT;strcpy(yylval.str, yytext);colno+=strlen(yytext); return(NAMED);}
.			{ strcpy(yylval.str,yytext);colno++;return CH;}
%%

buffpos() {
struct yy_buffer_state *y;
y=YY_CURRENT_BUFFER;
        return (int)(yy_c_buf_p-y->yy_ch_buf);
}



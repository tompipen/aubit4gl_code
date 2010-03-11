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
%x comment ccode header body trailer
%option yylineno
%%
[\r] ;
[\n] 		{lineno++;colno=0;REJECT}
[ ]		{ colno++;}
[	]	{colno+=3;}
[	 \n]	;
<body>[\r] ;
<body>[\n] 		{lineno++;colno=0;REJECT}
<body>[ ]		{ colno++;}
<body>[	]	{colno+=3;}
<body>[	 \n]	;
<INITIAL>[\r] ;
<INITIAL>[\n] 		{lineno++;colno=0;REJECT}
<INITIAL>[ ]		{ colno++;}
<INITIAL>[	]	{colno+=3;}
<INITIAL>[	 \n]	;
<header>[\r] ;
<header>[\n] 		{lineno++;colno=0;REJECT}
<header>[ ]		{ colno++;}
<header>[	]	{colno+=3;}
<header>[	 \n]	;
<trailer>[\r] ;
<trailer>[\n] 		{lineno++;colno=0;REJECT}
<trailer>[ ]		{ colno++;}
<trailer>[	]	{colno+=3;}
<trailer>[	 \n]	;
<ccode>[\r] ;
<ccode>[\n] 		{lineno++;colno=0;REJECT}
<ccode>[ ]		{ colno++;}
<ccode>[	]	{colno+=3;}
<ccode>[	 \n]	;
<comment>[\r] ;
<comment>[\n] 		{lineno++;colno=0;REJECT}
<comment>[ ]		{ colno++;}
<comment>[	]	{colno+=3;}
<comment>[	 \n]	;


<INITIAL>"%%"				{gottocode++;if (gottocode==1) {BEGIN body;} else {printf("TRAILER\n"); BEGIN trailer;}}
<body>"%%"				{ BEGIN trailer;}
<INITIAL>"%{"				{;BEGIN header;}
<INITIAL>.				;
<trailer>.				;
<header>"%}" 				{BEGIN INITIAL;}
<header>.  				;
<comment>"*/"				{BEGIN body;}

<comment>.				;
<comment>[\n]				;

<ccode>"{"      			{lvl++;}
<ccode>"}"      			{lvl--; if (lvl==0) BEGIN body;}
<ccode>.				; /* Ignore all C code */

<body>"{" 				{lvl++; BEGIN  ccode;}
<body>"/*"     				{BEGIN comment; yymore(); }

<body>[0-9]+  				{strcpy(yylval.str, yytext); return(INTVAL);}
<body>[0-9]+|[0-9]*\.[0-9]+   		{strcpy(yylval.str, yytext); return(NUMBER_VALUE);}
<body>\"[^\"]+\" 			{strcpy(yylval.str,A4GL_strip_quotes(yytext)); return CHAR_VALUE;}
<body>\"\" 				{strcpy(yylval.str,A4GL_strip_quotes(yytext)); return CHAR_VALUE;}
<body>\'[^\']+\' 			{strcpy(yylval.str,A4GL_strip_quotes(yytext)); return CHAR_VALUE;}

<body>\'\' 				{strcpy(yylval.str,A4GL_strip_quotes(yytext)); return CHAR_VALUE;}
<body>OPTIONAL		{strcpy(yylval.str, yytext);colno+=strlen(yytext); return(OPTIONAL); }
<body>%prec 		{strcpy(yylval.str, yytext);colno+=strlen(yytext); return(PREC); }
<body>error		{strcpy(yylval.str, yytext);colno+=strlen(yytext); return(ERROR); }
<body>[a-zA-Z]+[a-zA-Z\_0-9]*		{strcpy(yylval.str, yytext);colno+=strlen(yytext); return(NAMED); }
<body>[a-zA-Z\_0-9]+[a-zA-Z\_0-9]*	{strcpy(yylval.str, yytext);colno+=strlen(yytext); return(NAMED);}
<body>. {return yytext[0];}
<INITIAL>. ;
<ccode>. ;
<trailer>. ;
%%


/* ============================== EOF =============================== */


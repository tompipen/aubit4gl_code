%{
/*
 *      LEXICO.L -- hy4GL -- analisis lexico
 */


#include <stdlib.h>
#include <string.h>
#include "global.h"
#include "asa.h"
#include "y.tab.h"

extern int yylineno;
extern int yycolno;
extern char yyfilename[255];
static int busca_reservada(void);
static int nivel_comentario1, nivel_comentario2=0;
#define DIM(a)  (sizeof(a)/sizeof((a)[0]))
%}

letter          [a-zA-Z_]
digit           [0-9]
esc             \\([abfnrtv"'?\\]|[0-7]{1,3}|x[0-9a-fA-F]+)
alphanum        [a-zA-Z_0-9]
blank           [ \t]
other           .

%x COMENTARIO1
%x COMENTARIO2
%x FUENTE_C

%%

"{"					{nivel_comentario1=1;BEGIN(COMENTARIO1);}
<COMENTARIO1>"{"	{nivel_comentario1++;}
<COMENTARIO1>"}"	{nivel_comentario1--; 
                    	if(nivel_comentario1==0) BEGIN 0;}
<COMENTARIO1>.		;
<COMENTARIO1>\n		{yylineno++;}

"/*"				{nivel_comentario2=1;BEGIN(COMENTARIO2);}
<COMENTARIO2>"/*"	{nivel_comentario2++;}
<COMENTARIO2>"*/"	{nivel_comentario2--; 
						if(nivel_comentario2==0) BEGIN 0;}
<COMENTARIO2>.		;
<COMENTARIO2>\n		{yylineno++;}


^{blank}*".c"						{BEGIN(FUENTE_C);}
<FUENTE_C>^{blank}*"c."{other}*\n	{yylineno++;
                                     BEGIN 0;}
<FUENTE_C>{other}*\n	{strncpy(yylval.string,yytext,sizeof(yylval.string));
                    	 yylval.string[sizeof(yylval.string)]='\0';
                         yylineno++;
                         return TK_FUENTE_C;}

"||"    return TK_OR;
"&&"    return TK_AND;
"=="    return TK_IGUAL;
"="     return TK_IGUAL;
"!="    return TK_DISTINTO;
"<="    return TK_MENORIGUAL;
">="    return TK_MAYORIGUAL;
"++"    return TK_ADDADD;
"--"    return TK_SUBSUB;

{letter}{alphanum}*      return busca_reservada();

{digit}*\.{digit}+      {yylval.valor=atof(yytext);
                         return TK_REAL;}

{digit}+                {yylval.valor=atol(yytext); 
   			return TK_CONS;}

L?\"([^"\\\n]|{esc})*\"  {  strcpy(yylval.string,yytext+1);
									 yylval.string[strlen(yytext)-2]='\0';
       							 return TK_CADENA;}

{blank}+                ;
\n                      {yylineno++;}

{other}                 return yytext[0];

%%

/*
 *     busca_reservada
 */

static const struct {
  char *name;
  int yylex;
} keywords[] = {
          {"abort",         TK_ABORT},
          {"after",         TK_AFTER},
          {"and",           TK_AND},
          {"as",            TK_AS},
          {"ascending",     TK_ASCENDING},
          {"at",            TK_AT},
          {"attribute",     TK_ATTR},
          {"attributes",    TK_ATTR},
          {"before",        TK_BEFORE},
          {"begin",         TK_BEGIN},
          {"border",        TK_BORDER},
          {"bright",        TK_BRIGHT},
          {"browse",        TK_BROWSE},
          {"button",        TK_BUTTON},
          {"by",            TK_BY},
          {"call",          TK_CALL},
          {"char",          TK_CHAR},
          {"check",         TK_CHECK},
          {"clear",         TK_CLEAR},
          {"clipped",       TK_CLIPPED},
          {"close",         TK_CLOSE},
          {"columns",       TK_COLS},
          {"command",       TK_COMMAND},
          {"commit",        TK_COMMIT},
          {"continue",	    TK_CONTINUE},
          {"create",        TK_CREATE},
          {"current",       TK_CURRENT},
          {"cursor",        TK_CURSOR},
          {"database",      TK_DB},
          {"declare",       TK_DECLARE},
          {"define",        TK_DEFINE},
          {"delay",         TK_DELAY},
          {"delete",        TK_DELETE},
          {"descending",    TK_DESCENDING},
          {"display",       TK_DISPLAY},
          {"doble",         TK_DOBLE},
          {"drop",          TK_DROP},
          {"else",          TK_ELSE},
          {"end",           TK_END},
          {"every",         TK_EVERY},
          {"exec_sql",      TK_EXEC},
          {"exit",          TK_EXIT},
          {"extern",        TK_EXTERN},
          {"fetch",         TK_FETCH},
          {"field",         TK_FIELD},
          {"finish",        TK_FINISH},
          {"first",         TK_FIRST},
          {"footer",        TK_FOOTER},
          {"for",           TK_FOR},
          {"foreach",       TK_FOREACH},
          {"form",          TK_FORM},
          {"format",        TK_FORMAT},
          {"from",          TK_FROM},
          {"function",      TK_FUNCTION},
          {"group",         TK_GROUP},
          {"header",        TK_HEADER},
          {"horizontal",    TK_HORIZ},
          {"if",            TK_IF},
          {"input",         TK_INPUT},
          {"insert",        TK_INSERT},
          {"into",          TK_INTO},
          {"key",           TK_KEY},
          {"label",         TK_LABEL},
          {"last",          TK_LAST},
          {"let",           TK_LET},
          {"like",          TK_LIKE},
          {"local",         TK_LOCAL},
          {"main",          TK_MAIN},
          {"menu",          TK_MENU},
          {"move",          TK_MOVE},
          {"next",          TK_NEXT},
          {"of",            TK_OF},
          {"on",            TK_ON},
          {"open",          TK_OPEN},
          {"or",            TK_OR},
          {"order",         TK_ORDER},
          {"output",        TK_OUTPUT},
          {"over",          TK_OVER},
          {"page",          TK_PAGE},
          {"pipe",          TK_PIPE},
          {"previous",      TK_PREVIOUS},
          {"print",         TK_PRINT},
          {"prompt",        TK_PROMPT},
          {"radio",         TK_RADIO},
          {"record",        TK_RECORD},
          {"report",        TK_REPORT},
          {"return",        TK_RETURN},
          {"returning",     TK_RETURNING},
          {"row",           TK_ROW},
          {"rows",          TK_ROWS},
          {"select",        TK_SELECT},
          {"start",         TK_START},
          {"then",          TK_THEN},
          {"title",         TK_TITLE},
          {"to",            TK_TO},
          {"trailer",       TK_FOOTER},
          {"transaction",   TK_TRANSACTION},
          {"update",        TK_UPDATE},
          {"using",         TK_USING},
          {"validate",      TK_VALIDATE},
          {"values",        TK_VALUES},
          {"vertical",      TK_VERT},
          {"whenever",      TK_WHENEVER},
          {"where",         TK_WHERE},
          {"while",         TK_WHILE},
          {"window",        TK_WINDOW},
          {"with",          TK_WITH},
};

static int busca_reservada(void)
{
  register int mid;
  int cc, hi, lo;

	/* Hace la busqueda del token entre las palabras reservadas
      con busqueda binaria. */
  lo = 0;
  hi = DIM(keywords) - 1;
  while (lo <= hi) {
        mid = (lo + hi) / 2;
        if ((cc = strcasecmp(yytext, keywords[mid].name)) == 0)
          return keywords[mid].yylex;
        if (cc < 0)
          hi = mid - 1;
        else
          lo = mid + 1;
  }
  strncpy(yylval.string,yytext,MAXLONGID);
  return TK_ID;
}


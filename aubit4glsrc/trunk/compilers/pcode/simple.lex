%{
#if (defined(__CYGWIN__)) || defined(__MINGW32__)
	/* missing from rpcgen generated .h on CygWin: */
	#define bool_t int
	#define u_int unsigned int
#endif

#include "npcode.h"
#include "npcode_defs.h"
void comment (void );
int check_type (void);
int use_4gl_kw=1;
void hash (void );
%}
D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*

%{
#include <stdio.h>
#include "y.tab.h"

void count();
%}

%%
"/*"			{ comment(); }

"op_and" {strcpy(yytext,"32775");count(); return CONSTANT;}
"OP_CLIP" {strcpy(yytext,"1025");count(); return CONSTANT;}
"OP_CONCAT" {strcpy(yytext,"2049");count(); return CONSTANT;}
"OP_COPY" {strcpy(yytext,"2050");count(); return CONSTANT;}
"OP_DAY" {strcpy(yytext,"4099");count(); return CONSTANT;}
"OP_DIV" {strcpy(yytext,"516");count(); return CONSTANT;}
"OP_EQUAL" {strcpy(yytext,"32769");count(); return CONSTANT;}
"OP_EXISTS" {strcpy(yytext,"65541");count(); return CONSTANT;}
"OP_GREATER_THAN" {strcpy(yytext,"32771");count(); return CONSTANT;}
"OP_GREATER_THAN_EQ" {strcpy(yytext,"32774");count(); return CONSTANT;}
"OP_HOUR" {strcpy(yytext,"4100");count(); return CONSTANT;}
"OP_IN" {strcpy(yytext,"65537");count(); return CONSTANT;}
"OP_IN_SELECT" {strcpy(yytext,"65539");count(); return CONSTANT;}
"OP_ISNOTNULL" {strcpy(yytext,"32779");count(); return CONSTANT;}
"OP_ISNULL" {strcpy(yytext,"32778");count(); return CONSTANT;}
"OP_LESS_THAN" {strcpy(yytext,"32770");count(); return CONSTANT;}
"OP_LESS_THAN_EQ" {strcpy(yytext,"32773");count(); return CONSTANT;}
"OP_LIKE" {strcpy(yytext,"2053");count(); return CONSTANT;}
"OP_MASK" {strcpy(yytext,"1536");count(); return CONSTANT;}
"OP_MASK_BASE" {strcpy(yytext,"512");count(); return CONSTANT;}
"OP_MATCHES" {strcpy(yytext,"2052");count(); return CONSTANT;}
"OP_MATH" {strcpy(yytext,"32780");count(); return CONSTANT;}
"OP_MINUTE" {strcpy(yytext,"4101");count(); return CONSTANT;}
"OP_MOD" {strcpy(yytext,"518");count(); return CONSTANT;}
"OP_MONTH" {strcpy(yytext,"4098");count(); return CONSTANT;}
"OP_MULT" {strcpy(yytext,"515");count(); return CONSTANT;}
"OP_NOT" {strcpy(yytext,"32777");count(); return CONSTANT;}
"OP_NOTEXISTS" {strcpy(yytext,"65542");count(); return CONSTANT;}
"OP_NOTIN" {strcpy(yytext,"65538");count(); return CONSTANT;}
"OP_NOTIN_SELECT" {strcpy(yytext,"65540");count(); return CONSTANT;}
"OP_NOT_EQUAL" {strcpy(yytext,"32772");count(); return CONSTANT;}
"OP_OR" {strcpy(yytext,"32776");count(); return CONSTANT;}
"OP_POWER" {strcpy(yytext,"517");count(); return CONSTANT;}
"OP_SECOND" {strcpy(yytext,"4102");count(); return CONSTANT;}
"OP_SUB" {strcpy(yytext,"514");count(); return CONSTANT;}
"OP_USING" {strcpy(yytext,"2051");count(); return CONSTANT;}
"OP_YEAR" {strcpy(yytext,"4097");count(); return CONSTANT;}
"OP_ADD" {strcpy(yytext,"513");count(); return CONSTANT;}


"ON_KEY" {count(); return ON_KEY;}
"BEF_ROW" {count(); return BEF_ROW;}

"REPORT_START" 			{strcpy(yytext,"-1"); count(); return CONSTANT;}
"REPORT_FINISH" 		{strcpy(yytext,"-2"); count(); return CONSTANT;}
"REPORT_DATA" 			{strcpy(yytext,"-3"); count(); return CONSTANT;}
"REPORT_OPS_COMPLETE" 		{strcpy(yytext,"-4"); count(); return CONSTANT;}
"REPORT_AFTERDATA" 		{strcpy(yytext,"-5"); count(); return CONSTANT;}
"REPORT_SENDDATA" 		{strcpy(yytext,"-6"); count(); return CONSTANT;}
"REPORT_BEFOREDATA" 		{strcpy(yytext,"-7"); count(); return CONSTANT;}
"REPORT_BEFOREGROUP"	 	{strcpy(yytext,"-8"); count(); return CONSTANT;}
"REPORT_AFTERGROUP" 		{strcpy(yytext,"-9"); count(); return CONSTANT;}
"REPORT_LASTROW" 		{strcpy(yytext,"-10"); count(); return CONSTANT;}
"REPORT_PAGEHEADER" 		{strcpy(yytext,"-11"); count(); return CONSTANT;}
"REPORT_FIRSTPAGEHEADER"	{strcpy(yytext,"-12"); count(); return CONSTANT;}
"REPORT_LASTDATA" 		{strcpy(yytext,"-13"); count(); return CONSTANT;}
"REPORT_PAGETRAILER" 		{strcpy(yytext,"-14"); count(); return CONSTANT;}
"REPORT_TERMINATE" 		{strcpy(yytext,"-9999"); count(); return CONSTANT;}

"A4GL_push_long"	{if (use_4gl_kw) return KW_A_PUSH_LONG; else REJECT;}
"A4GL_push_int"		{if (use_4gl_kw) return KW_A_PUSH_INT; else REJECT;}
"A4GL_push_char"	{if (use_4gl_kw) return KW_A_PUSH_CHAR; else REJECT;}
"A4GL_chk_err"		{if (use_4gl_kw) return KW_A_CHK_ERR; else REJECT;}
"aclfgli_clr_err_flg"	{if (use_4gl_kw) return KW_A_CLR_ERR; else REJECT;}


"auto"			{ count(); return(AUTO); }
"break"			{ count(); return(BREAK); }
"case"			{ count(); return(CASE); }
"char"			{ count(); return(CHAR); }
"const"			{ count(); return(CONST); }
"continue"		{ count(); return(CONTINUE); }
"default"		{ count(); return(DEFAULT); }
"do"			{ count(); return(DO); }
"double"		{ count(); return(DOUBLE); }
"else"			{ count(); return(ELSE); }
"enum"			{ count(); return(ENUM); }
"extern"		{ count(); return(EXTERN); }

"a4gl_function"		{ count(); return(FUNCTION); }
"a4gl_internal_function"		{ count(); return(FUNCTION); }
"a4gl_report"		{ count(); return(FUNCTION); }
"a4gl_main"		{ count(); return(FUNCTION); }

"float"			{ count(); return(FLOAT); }
"for"			{ count(); return(FOR); }
"goto"			{ count(); return(GOTO); }
"if"			{ count(); return(IF); }
"int"			{ count(); return(INT); }
"fgldate"			{ count(); return(FGLDATE); }
"fgldecimal"			{ count(); return(FGLDECIMAL); }
"fglmoney"			{ count(); return(FGLMONEY); }
"long"			{ count(); return(LONG); }
"register"		{ count(); return(REGISTER); }
"return"		{ count(); return(RETURN); }
"short"			{ count(); return(SHORT); }
"signed"		{ count(); return(SIGNED); }
"sizeof"		{ count(); return(SIZEOF); }
"static"		{ count(); return(STATIC); }
"struct"		{ count(); return(STRUCT); }
"switch"		{ count(); return(SWITCH); }
"typedef"		{ count(); return(TYPEDEF); }
"union"			{ count(); return(UNION); }
"unsigned"		{ count(); return(UNSIGNED); }
"void"			{ count(); return(VOID); }
"volatile"		{ count(); return(VOLATILE); }
"while"			{ count(); return(WHILE); }
{L}({L}|{D})*		{ count(); return(check_type()); }

0[xX]{H}+{IS}?		{ count(); return(CONSTANT); }
0{D}+{IS}?		{ count(); return(CONSTANT); }
{D}+{IS}?		{ count(); return(CONSTANT); }
L?'(\\.|[^\\'])+'	{ count(); return(CONSTANT); }

{D}+{E}{FS}?		{ count(); return(CONSTANT); }
{D}*"."{D}+({E})?{FS}?	{ count(); return(CONSTANT); }
{D}+"."{D}*({E})?{FS}?	{ count(); return(CONSTANT); }

L?\"(\\.|[^\\"])*\"	{ count(); return(STRING_LITERAL); }

"..."			{ count(); return(ELLIPSIS); }
">>="			{ count(); return(RIGHT_ASSIGN); }
"<<="			{ count(); return(LEFT_ASSIGN); }
"+="			{ count(); return(ADD_ASSIGN); }
"-="			{ count(); return(SUB_ASSIGN); }
"*="			{ count(); return(MUL_ASSIGN); }
"/="			{ count(); return(DIV_ASSIGN); }
"%="			{ count(); return(MOD_ASSIGN); }
"&="			{ count(); return(AND_ASSIGN); }
"^="			{ count(); return(XOR_ASSIGN); }
"|="			{ count(); return(OR_ASSIGN); }
">>"			{ count(); return(RIGHT_OP); }
"<<"			{ count(); return(LEFT_OP); }
"++"			{ count(); return(INC_OP); }
"--"			{ count(); return(DEC_OP); }
"->"			{ count(); return(PTR_OP); }
"&&"			{ count(); return(AND_OP); }
"||"			{ count(); return(OR_OP); }
"<="			{ count(); return(LE_OP); }
">="			{ count(); return(GE_OP); }
"=="			{ count(); return(EQ_OP); }
"!="			{ count(); return(NE_OP); }
";"			{ count(); return(';'); }
("{"|"<%")		{ count(); return('{'); }
("}"|"%>")		{ count(); return('}'); }
","			{ count(); return(','); }
":"			{ count(); return(':'); }
"="			{ count(); return('='); }
"("			{ count(); return('('); }
")"			{ count(); return(')'); }
("["|"<:")		{ count(); return('['); }
("]"|":>")		{ count(); return(']'); }
"."			{ count(); return('.'); }
"&"			{ count(); return('&'); }
"!"			{ count(); return('!'); }
"~"			{ count(); return('~'); }
"-"			{ count(); return('-'); }
"+"			{ count(); return('+'); }
"*"			{ count(); return('*'); }
"/"			{ count(); return('/'); }
"%"			{ count(); return('%'); }
"<"			{ count(); return('<'); }
">"			{ count(); return('>'); }
"^"			{ count(); return('^'); }
"|"			{ count(); return('|'); }
"?"			{ count(); return('?'); }
"#"			{ hash();}


[ \t\v\n\f]		{ count(); }
.			{ /* ignore bad characters */ }

%%

int yywrap ()
{
  return (1);
}


void comment (void )
{
  char c, c1;

loop:
  while ((c = input ()) != '*' && c != 0) ;
    //putchar (c);

  if ((c1 = input ()) != '/' && c != 0)
    {
      unput (c1);
      goto loop;
    }

  //if (c != 0) ;
    //putchar (c1);
}


void hash (void)
{
  char c;

  while ((c = input ()) != '\n' && c != 0) ;

}



int column = 0;

extern int debug_mode;

void 
count ()
{
  int i;

  for (i = 0; yytext[i] != '\0'; i++)
    if (yytext[i] == '\n')
      column = 0;
    else if (yytext[i] == '\t')
      column += 8 - (column % 8);
    else
      column++;

 if (debug_mode) {
		ECHO;
  }


strcpy(yylval.str,yytext);


}

int check_type (void)
{

//if (is_typename(yytext)) return TYPE_NAME;
return IDENTIFIER;

//printf("Check type : %s\n",yytext);
  /*
     * pseudo code --- this is what it should check
     *
     *    if (yytext == type_name)
     *            return(TYPE_NAME);
     *
     *    return(IDENTIFIER);
   */

  /*
     *    it actually will only return IDENTIFIER
   */

  return (IDENTIFIER);
}

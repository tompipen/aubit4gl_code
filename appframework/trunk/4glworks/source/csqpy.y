%{
/*
	CSQPY.y  -  Sql interpreter parser and scanner

	The 4glWorks application framework
	Copyright (C) 1992-2002 Marco Greco (marco@4glworks.com)

	Initial release: Mar 00
	Current release: Jan 02

	This library is free software; you can redistribute it and/or
	modify it under the terms of the GNU Lesser General Public
	License as published by the Free Software Foundation; either
	version 2.1 of the License, or (at your option) any later version.

	This library is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public
	License along with this library; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

#include <errno.h>
#include <math.h>
#include <ctype.h>
#include <pwd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <datetime.h>
#include <decimal.h>
#include <locator.h>
#include <sqlca.h>
#include <sqlda.h>
#include <sqltypes.h> 

#include "ccmnc.h"
#include "chstc.h"
#include "csqdc.h"
#include "csqec.h"
#include "csqoc.h"
#include "csqpc.h"

#define FGWVAR 99	/* small optimization on string variables */

#ifndef __STDC__
#define void int
#endif

#ifndef YYBISON
#define yyparse yyparse_sqp     /* just in case we decide to have */
#define yylex yylex_sqp         /* multiple parsers */
#define yyerror yyerror_sqp
#define yyval yyval_sqp
#define yylval yylval_sqp
#define yyvs yyvs_sqp
#define yycheck yycheck_sqp
#define yychar yychar_sqp
#define yylhs yylhs_sqp
#define yylen yylen_sqp
#define yydefred yydefred_sqp
#define yydgoto yydgoto_sqp
#define yysindex yysindex_sqp
#define yyrindex yyrindex_sqp
#define yygindex yygindex_sqp
#define yytable yytable_sqp
#endif

#define FAIL(e)		{ \
			    status=e; \
			    yyerror(""); \
			    YYERROR; \
			}

#define FAILCHECK	if (status) \
			{ \
			    yyerror(""); \
			    YYERROR; \
			}

extern fgw_stmttype *sql_newstatement();
extern int status;

#define NUMTOKENS 110
#define STRINGCONVSIZE 30

/*
** function & reserved words list
*/
typedef struct tokenlist
{
    char *name;
    void (*func)();
    int type;
    int parms;
    struct tokenlist *next;
} tokenlist_t;

/*
** parser kludges
*/
#define NOOPTION 0
#define SQLHACK 1
#define DMLHACK 2
#define SELECTHACK 4
#define FUNCHACK 8
#define PROCHACK 0x10
#define DTHACK 0x20
#define QUALIFIERHACK 0x40
#define EXPRONLY 0x100

/*
** parser and scanner state
*/
static parserstate_t *pstate;
static int delimident=-1;

/*
** html styles
*/
#define F_none          0
#define F_pre           1
#define F_table         2
 
/*
** statement types
*/
#define T_for           0
#define T_foreach       1
#define T_while         2
#define T_if            3
#define T_procedure     4

/*
** control stack states
*/
#define S_active         1
#define S_disabled       0
#define S_procedure     -1
#define S_continue      -2
#define S_if            -3

/*
** intermediate buffers for ops
*/
static int iholder1, iholder2;
static double fholder1, fholder2;
static dec_t *dholder1, *dholder2;
static char *sholder1, *sholder2;
static int nullind;

/*
** current statement
*/
static fgw_stmttype *curstmt=NULL;
static int ssize=0, slen=0;

/*
** fork/exec status
*/
static int is_child=0;
static int errcode=0;
static int childstatus=0;

/*
** forward declarations
*/
char *fgw_getstring();
char *fgw_getvar();
static int fgw_parmcount();
static void yyerror();
static int yylex();
static int fgw_exprtype();
static int fgw_optype();
static int fgw_compare();
static void fgw_cvvar();
static void fgw_2int();
static int fgw_2decimal();
static void fgw_2double();
static void fgw_2string();
static int fgw_toboolean();
static int fgw_toint();
static int fgw_todate();
static double fgw_todouble();
static dtime_t *fgw_todtime();
static intrvl_t *fgw_toinv();
static double fgw_todouble();
static dec_t *fgw_todecimal();
static char *fgw_tostring();
static int fgw_qualifier();
static int inaddsub_sqp();
static int inadd();
static int insub();
static int fgw_isnull();
static void fgw_setnull();
static void dtadd_sqp();
static void dtaddinv_sqp();
static void dtsub_sqp();
static void dtsubinv_sqp();
static void fgw_setint();
static void fgw_setdouble();
static char *fgw_smalloc();
static void fgw_sfree();
static void fgw_freetssstack();
%}

%union {
char		*var;		/* variables */
tokenlist_t	*func;		/* functions */
exprstack_t	stack;		/* expression result */
}

%type <stack>	format1, ftype, fspec
%type <stack>	elist
%type <stack>	allexp
%type <stack>	exp, casecl, lcasecl, elsecl, nullcl, unitcl, qualcl
%type <stack>	boolexp, betweencl, mrexcl, lrexcl, escape, parms
%type <stack>   rangecl

%nonassoc FOR FOREACH WHILE IF ELIF ELSE FI DONE CONTINUE BREAK
%nonassoc DISPLAY LET LOAD UNLOAD PIPE APPEND OUTPUT
%nonassoc SELECT INSERT DELETE UPDATE EXECUTE CREATE END
%nonassoc PROCEDURE FUNCTION
%nonassoc IN INTO USING FORMAT FROM TO DELIMITER
%nonassoc BRIEF VERTICAL FULL HEADERS
%nonassoc TEMP SCRATCH EXTERNAL
%nonassoc CASE WHEN THEN IS NULLVALUE
%nonassoc BETWEEN MATCHES LIKE ESCAPE
%nonassoc YEAR MONTH DAY HOUR MINUTE SECOND FRACTION

%right ASSIGN

%token <stack>	CNST SQLTOK
%token <var>	VAR
%token <func>	FNCT FNDP FNDN /* need to differentiate between datetime
				  functions with & without args */
%left AND OR
%right NOT
%nonassoc '=' EQ NEQ '<' LEQ '>' GEQ
%left DPIPE
%token <func> PFIXFNCT
%left '-' '+'
%left '*' '/'
%nonassoc UNITS
%left NEG PLUS

/*
** Grammar
*/

%% 
target:	    {
		if (!(pstate->parseroptions & EXPRONLY))
		    YYFAIL;
	    }
	  allexp	{
			    fgw_stackpush(&pstate->exprlist, &($2));
			    YYACCEPT;
			}
	|   {
		if (pstate->parseroptions & EXPRONLY)
		    YYFAIL;
	    }
	  stmt
;
stmt:	  plain
;
plain:	  assign
	| display	{
			    pstate->done_display=1;
			}
	| /* empty */
;
display:  DISPLAY
	    {
		if (!(curstmt=sql_newstatement()))
		    FAIL(-208)
		sql_setwidth(curstmt, pstate->width);
	    }
	  elist format {
			    exprstack_t *s;
			    struct sqlvar_struct col;
			    int i, c;

			    sql_initdisplay(curstmt, pstate->txtvar);
			    s=(exprstack_t *) fgw_stackpeek(&pstate->exprlist);
			    c=s->count;
			    for (i=0, s=s-c+1; i<c; i++, s++)
			    {
				switch(s->type)
				{
				  case FGWVAR:
				  case CSTRINGTYPE:
				    col.sqltype=CSTRINGTYPE;
				    col.sqllen=strlen(s->val.string)+1;
				    col.sqldata=s->val.string;
				    break;
				  case CDTIMETYPE:
				  case CINVTYPE:
				  case CDECIMALTYPE:
				  case CMONEYTYPE:
				    col.sqltype=s->type;
				    col.sqldata=(char *) s->val.datetime;
				    break;
				  default:
				    col.sqltype=s->type;
				    col.sqldata=(char *) &(s->val.real);
				}
				sql_display(curstmt, pstate->txtvar, &col);
				fgw_freetssstack(s);
			    }
			    sql_enddisplay(curstmt, pstate->txtvar);
			    sql_freestatement(curstmt);
			    fgw_stackdrop(&pstate->exprlist, c);
			    curstmt=NULL;
			}
;
/*
** WARNING: see fgw_cvvar. This only works as we do 
** assignments as a production external to exp!
*/
assign:	  LET VAR '=' allexp %prec ASSIGN	{
			    switch ($4.type)
			    {
			      case CSTRINGTYPE:
			      case FGWVAR:
				fgw_hstadd(pstate->vars, $<var>2, CSTRINGTYPE,
					   $4.val.string);
				break;
			      case CDOUBLETYPE:
			      case CINTTYPE:
			      case CDATETYPE:
				fgw_hstadd(pstate->vars, $<var>2, $4.type,
					   (char *) &($4.val.real));
				break;
			      default:
				fgw_hstadd(pstate->vars, $<var>2, $4.type,
					   (char *) $4.val.datetime);
			    }
			    fgw_sfree($<var>2);
			    fgw_freetssstack(&($4));
			}
	| LET VAR rangecl '=' allexp %prec ASSIGN	{
			    exprstack_t s;
			    int vl, el, ol, n1, n2, sp;
			    char *e, ebuf[STRINGCONVSIZE];
			    char *v, *t, vbuf[STRINGCONVSIZE];

/* FIXME: this could be optimized */
			    fgw_cvvar(&s, fgw_hstget(pstate->vars, $<var>2));
			    v=fgw_tostring(&s, &vbuf, &n1);
			    vl=stleng(v);
			    if (!(t=fgw_smalloc(ol=$3.val.range[1]-
						  $3.val.range[0]+1)))
				FAIL(-208)
			    stcopy(v, t);
			    e=fgw_tostring(&($5), &ebuf, &n2);
			    if ((el=stleng(e))>ol)
				el=ol;
			    bycopy(e, t+$3.val.range[0], el);
/*
** fill with spaces as appropriate
*/
			    if ($3.val.range[0]>vl)
				byfill(t+vl, $3.val.range[0]-vl, ' ');
			    if ((sp=$3.val.range[0]+el)<=$3.val.range[1])
				byfill(t+sp, $3.val.range[1]-sp+1, ' ');
/*
** zero terminate if appropriate
*/
			    if ($3.val.range[1]>=vl)
			        *(t+$3.val.range[1]+1)='\0';
			    fgw_hstadd(pstate->vars, $<var>2, CSTRINGTYPE, t);
			    fgw_sfree(t);
			    fgw_sfree($<var>2);
			    fgw_freetssstack(&($5));
			}
;
elist:	  elist ',' allexp 	{
				    exprstack_t *s;

				    s=(exprstack_t *) fgw_stackpeek(
							&pstate->exprlist);
				    $3.count=s->count+1;
				    fgw_stackpush(&pstate->exprlist, &($3));
				}
	| allexp	{
			    $1.count=1;
			    fgw_stackpush(&pstate->exprlist, &($1));
			}
;
format:	  format1	{
			}
;
format1:  /* empty */	{
			    curstmt->fmt_type=pstate->html? FMT_FULL: FMT_BRIEF;
			    $$.type=1;
			}
	| FORMAT ftype	{
			    char cbuf[STRINGCONVSIZE];

/* need to set format string after headers */
			    if (fgw_isnull(&($2)))
				$$.type=1;
			    else
				$$.type=sql_setformat(curstmt, fgw_tostring(&($2),
								&cbuf, NULL));
			    fgw_freetssstack(&($2));
			}
;
ftype:	  BRIEF		{
			    fgw_setnull(&($$));
			    curstmt->fmt_type=pstate->html? FMT_FULL: FMT_BRIEF;
			}
	| VERTICAL fspec headers	{
					    $$=$2;
					    curstmt->fmt_type=FMT_VERTICAL;
					}
	| FULL fspec headers		{
					    $$=$2;
					    curstmt->fmt_type=FMT_FULL;
					}
;
fspec:	  /* empty */	{
			    fgw_setnull(&($$));
			}
	| CNST		{
			    $$=$1;
			}
;
headers:  /* empty */
	| HEADERS hlist
;
hlist:	  hlist ',' allexp 	{
				    char cbuf[STRINGCONVSIZE];

				    sql_setheader(curstmt, fgw_tostring(&($3),
								&cbuf, NULL));
				    fgw_freetssstack(&($3));
				}
	| allexp	{
			    char cbuf[STRINGCONVSIZE];

			    sql_setheader(curstmt, fgw_tostring(&($1), 
							&cbuf, NULL));
			    fgw_freetssstack(&($1));
			}
;
/*
** had a single exp rule, but the BETWEEN and ESCAPE clauses would result
** in 40 s/r & 7 r/r conflicts. This grammar is less powerful, but cleaner
*/
allexp:	  boolexp		{
				    $$=$1;
				}
	| exp			{
				    $$=$1;
				}
;
exp:	  CNST			{
				    $$=$1;
				}
	| NULLVALUE		{
				    fgw_setnull(&($$));
				}
	| VAR			{
				    fgw_cvvar(&($$), fgw_hstget(pstate->vars,
								$<var>1));
				    FAILCHECK
				    fgw_sfree($<var>1);
				}
/* FIXME: index, replace, pads & substrings use byte (as opposed to char)
   starts & ends/lengths. they should be ok as far as GLS goes, but this 
   needs to be checked */
	| VAR rangecl		{
				    exprstack_t s;
				    int l, n1;
				    char *c, sbuf[STRINGCONVSIZE];

				    fgw_cvvar(&s, fgw_hstget(pstate->vars,
							     $<var>1));
				    c=fgw_tostring(&s, &sbuf, &n1);
				    $$.type=CSTRINGTYPE;
				    if (!($$.val.string=
					   fgw_smalloc(l=$2.val.range[1]-
							 $2.val.range[0]+1)))
					FAIL(-208)
				    if ($2.val.range[0]>stleng(c) || n1)
					rsetnull(CSTRINGTYPE,$$.val.string);
				    else
				    {
					bycopy(c+$2.val.range[0],
					       $$.val.string, l);
					*($$.val.string+l)='\0';
				    }
				    fgw_sfree($<var>1);
			}
	| CASE casecl elsecl END	{
				    if ($2.type==ELSE)
					$$=$3;
				    else
				    {
					$$=$2;
					fgw_freetssstack(&($3));
				    }
				}
	| CASE exp lcasecl elsecl END	{
/* FIXME: should be finding a solution that uses left recursion */
				    exprstack_t *s;

				    s=&($3);
				    if (fgw_isnull(&($2)))
					$$=$4;
				    else
				    {
					while (s)
					{
					    int r;

					    r=fgw_compare($2.type, &($2), s);
					    if (!nullind && !r)
					    {
						$$=*s->next;
						break;
					    }
					    else
						s=s->next->next;
					}
					if (!s)
					     $$=$4;
				    }
				    fgw_freetssstack(&($2));
				}
	| FNCT 			{
				    if ($1->parms)
					FAIL(-664)
				    (*($1->func))(&($$));
				    FAILCHECK
				}
	| FNCT '(' parms ')'	{
				    exprstack_t *s;

/*
** check parm count
*/
				    switch ($1->parms)
				    {
				      case 0:
					FAIL(-664)
				      case -1:
					break;
				      default:
					if (fgw_parmcount(&($3))!=$1->parms)
					    FAIL(-664)
				    }
/*
** call func & abort if error
*/
				    (*($1->func))(&($3), &($$));
				    FAILCHECK
/*
** otherwise free strings
*/
				    s=&($3);
				    while (s)
				    {
					fgw_freetssstack(s);
					s=s->next;
				    }
				}
	| FNDN { pstate->parseroptions|=QUALIFIERHACK; } qualcl {
				    pstate->parseroptions&=~QUALIFIERHACK;
				    if ($1->parms)
					FAIL(-664)
				    (*($1->func))(&($$), $3.type);
				    FAILCHECK
				}
/*
** change to
**
	| FNDP '(' { pstate->parseroptions|=DTHACK } CNST ')'
	  { pstate->parseroptions|=QUALIFIERHACK; } qualcl	{
**
** for true datetime/interval syntax
*/
	| FNDP '(' parms ')' { pstate->parseroptions|=QUALIFIERHACK; } qualcl	{
				    exprstack_t *s;

				    pstate->parseroptions&=~QUALIFIERHACK;
				    switch ($1->parms)
				    {
				      case 0:
					FAIL(-664)
				      case -1:
					break;
				      default:
					if (fgw_parmcount(&($3))!=$1->parms)
					    FAIL(-664)
				    }
				    (*($1->func))(&($3), &($$), $6.type);
				    FAILCHECK
				    s=&($3);
				    while (s)
				    {
					fgw_freetssstack(s);
					s=s->next;
				    }
				}
	| exp DPIPE exp		{
				    fgw_2string(&($1), &($3));
/*
** allocate memory - if none available, nullify result (dirty hack)
*/
				    $$.val.string=(char *) fgw_smalloc(
							strlen(sholder1)+
							strlen(sholder2));
				    if (!($$.val.string))
					fgw_setnull(&($$));
				    else
				    {
					$$.type=CSTRINGTYPE;
					stcopy(sholder1, $$.val.string);
					stcat(sholder2, $$.val.string);
				    }
				    fgw_freetssstack(&($1));
				    fgw_freetssstack(&($3));
				}
	| exp USING exp		{
				    char *f;

				    if (!(f=fgw_smalloc(64)))
					FAIL(-208)
				    else
				    {
					switch($1.type)
					{
					  case CDECIMALTYPE:
					  case CMONEYTYPE:
					    status=rfmtdec($1.val.decimal,
							 $3.val.string, f);
					    break;
					  case CDOUBLETYPE:
					    status=rfmtdouble($1.val.real,
							 $3.val.string, f);
					    break;
					  case CDATETYPE:
					    status=rfmtdate($1.val.intvalue,
							 $3.val.string, f);
					    break;
#ifdef HAS_DTFMT
					  case CDTIMETYPE:
					    status=dttofmtasc($1.val.datetime,
					                 f, 64, $3.val.string);
					    break;
					  case CINVTYPE:
					    status=intofmtasc($1.val.interval,
					                 f, 64, $3.val.string);
					    break;
#endif 
					  case CINTTYPE:
					    status=rfmtlong($1.val.intvalue,
							 $3.val.string, f);
					    break;
					  default:
					    stcopy($3.val.string, f);
					}
					FAILCHECK
					$$.type=CSTRINGTYPE;
					$$.val.string=f;
				    }
				    fgw_freetssstack(&($1));
				    fgw_freetssstack(&($3));
				}
/* $%^&! 8 s/r conflicts from this one */
	| exp PFIXFNCT		{
				    (*($2->func))(&($1), &($$));
				    FAILCHECK
				    fgw_freetssstack(&($1));
				}
	| exp '+' exp		{
				    exprstack_t *l, *r;
				    intrvl_t in1, in2;

				    switch ($$.type=fgw_optype(&($1), &($3),
							       &l, &r))
				    {
				      case CDTIMETYPE:
					dtaddinv_sqp(l, r, &($$));
					break;
				      case CDATETYPE:
					if (fgw_isnull(l)||fgw_isnull(r))
					    rsetnull(CDATETYPE,
						(char *) &($$.val.intvalue));
					else switch (r->type)
					{
					  case CINTTYPE:
					  case CDOUBLETYPE:
					    $$.type=CDATETYPE;
					    $$.val.intvalue=l->val.intvalue+
						fgw_toint(r, NULL);
					    break;
					  default:
					    dtaddinv_sqp(l, r, &($$));
					}
					break;
				      case CINVTYPE:
					if (inaddsub_sqp(&($1), &($3),
							 &in1, &in2, &($$)))
					    status=inadd(&in1, &in2,
							 $$.val.interval);
					break;
				      case CDECIMALTYPE:
				      case CMONEYTYPE:
					if (fgw_2decimal(&($1), &($3), &($$)))
					    status=decadd(dholder1, dholder2,
							  $$.val.decimal);
					break;
				      case CDOUBLETYPE:
				      case CSTRINGTYPE:
					fgw_2double(&($1), &($3));
					fgw_setdouble(&($$), fholder1+fholder2);
					break;
				      case CINTTYPE:
					fgw_2int(&($1), &($3));
					fgw_setint(&($$), iholder1+iholder2);
					break;
				      default:
					fgw_setnull(&($$));
				    }
				    FAILCHECK
				    fgw_freetssstack(&($1));
				    fgw_freetssstack(&($3));
				}
	| exp '-' exp		{
				    int d;
				    intrvl_t in1, in2;

				    if ($1.type==CDTIMETYPE)
				    {
					if ($3.type==CINVTYPE)
					    dtsubinv_sqp(&($1), &($3), &($$));
					else
					    dtsub_sqp(&($1), &($3), &($$));
				    }
				    else if ($1.type==CDATETYPE)
				    {
					if (fgw_isnull(&($1))||fgw_isnull(&($3)))
					    rsetnull(CDATETYPE,
						(char *) &($$.val.intvalue));
					else switch ($3.type)
					{
					  case CINTTYPE:
					  case CDOUBLETYPE:
					    $$.type=CDATETYPE;
					    $$.val.intvalue=$1.val.intvalue-
						fgw_toint(&($3), NULL);
					    break;
					  case CINVTYPE:
					    dtsubinv_sqp(&($1), &($3), &($$));
					    break;
					  case CDTIMETYPE:
					    dtsub_sqp(&($1), &($3), &($$));
					    break;
					  default:
					    d=fgw_todate(&($3), NULL);
					    $$.type=CINTTYPE;
					    $$.val.intvalue=$1.val.intvalue-d;
					}
				    }
				    else if ($1.type==CINVTYPE)
				    {
					if (inaddsub_sqp(&($1), &($3),
							 &in1, &in2, &($$)))
					    status=insub(&in1, &in2,
							 $$.val.interval);
				    }
				    else switch ($$.type=fgw_exprtype($1.type,
								      $3.type))
				    {
				      case CDECIMALTYPE:
				      case CMONEYTYPE:
					if (fgw_2decimal(&($1), &($3), &($$)))
					    status=decadd(dholder1, dholder2,
							  $$.val.decimal);
					break;
				      case CSTRINGTYPE:
				      case CDOUBLETYPE:
					fgw_2double(&($1), &($3));
					fgw_setdouble(&($$), fholder1-fholder2);
					break;
				      case CINTTYPE:
					fgw_2int(&($1), &($3));
					fgw_setint(&($$), iholder1-iholder2);
					break;
				      default:
					fgw_setnull(&($$));
				    }
				    FAILCHECK
				    fgw_freetssstack(&($1));
				    fgw_freetssstack(&($3));
				}
	| exp '*' exp		{
				    exprstack_t *l, *r;
				    intrvl_t *ip1, in1;
				    int n1, n2;
				    double f;

				    switch ($$.type=fgw_optype(&($1), &($3),
							       &l, &r))
				    {
				      case CDECIMALTYPE:
				      case CMONEYTYPE:
					if (fgw_2decimal(&($1), &($3), &($$)))
					    status=decmul(dholder1, dholder2,
							  $$.val.decimal);
					break;
				      case CDOUBLETYPE:
				      case CSTRINGTYPE:
					fgw_2double(&($1), &($3));
					fgw_setdouble(&($$), fholder1*fholder2);
					break;
				      case CINTTYPE:
					fgw_2int(&($1), &($3));
					fgw_setint(&($$), iholder1*iholder2);
					break;
				      case CINVTYPE:
					ip1=fgw_toinv(l, &in1, -1, &n1);
					f=fgw_todouble(r, &n2);
					if (!($$.val.interval=(intrvl_t *)
						fgw_smalloc(sizeof(intrvl_t))))
					    FAIL(-208)
					$$.type=CINVTYPE;
					if (n1||n2)
					    rsetnull(CINVTYPE,
						     (char *) $$.val.interval);
					status=invmuldbl(ip1, f,
							 $$.val.interval);
					break;
				      default:
					fgw_setnull(&($$));
				    }
				    FAILCHECK
				    fgw_freetssstack(&($1));
				    fgw_freetssstack(&($3));
				}
	| exp '/' exp		{
				    if ($1.type==CINVTYPE)
				    {
					int n1, n2;
					intrvl_t *ip1, *ip2, in2;
					double f;

					if ($3.type==CINTTYPE ||
					    $3.type==CDOUBLETYPE)
					{
					    ip1=fgw_toinv(&($1), &in2, -1, &n1);
					    f=fgw_todouble(&($3), &n2);
					    $$.type=CINVTYPE;
					    if (!($$.val.interval=(intrvl_t *)
						  fgw_smalloc(sizeof(intrvl_t))))
						FAIL(-208)
					    $$.val.interval->in_qual=ip1->in_qual;
					    if (n1||n2)
						rsetnull(CINVTYPE, (char *)
							  $$.val.interval);
					    else
						status=invdivdbl(ip1, f,
							    $$.val.interval);
					}
					else
					{
					    ip1=fgw_toinv(&($1), &in2, -1, &n1);
					    ip2=fgw_toinv(&($3), &in2, -1, &n2);
					    if (n1||n2)
						fgw_setnull(&($$));
					    else
					    {
						$$.type=CDOUBLETYPE;
						status=invdivinv(ip1, ip2,
							&($$.val.real));
					    }
					}
				    }
				    else switch ($$.type=fgw_exprtype($1.type,
								      $3.type))
				    {
				      case CDECIMALTYPE:
				      case CMONEYTYPE:
					if (fgw_2decimal(&($1), &($3), &($$)))
					    status=decdiv(dholder1, dholder2,
							  $$.val.decimal);
					break;
				      case CSTRINGTYPE:
				      case CDOUBLETYPE:
					fgw_2double(&($1), &($3));
/*
** avoid problems with null or 0 divisors...
*/
					if (nullind)
					{
					    $$.type=CDOUBLETYPE;
					    rsetnull(CDOUBLETYPE,
						    (char *) &($$.val.real));
					}
					else if (fholder2==0)
					    FAIL(-1202)
					else
					    fgw_setdouble(&($$),
							 fholder1/fholder2);
					break;
				      case CINTTYPE:
					fgw_2int(&($1), &($3));
					if (nullind)
					    fgw_setnull(&($$));
					else if (iholder2==0)
					    FAIL(-1202)
					else
					    fgw_setint(&($$),
						iholder1/iholder2);
					break;
				      default:
					fgw_setnull(&($$));
				    }
				    FAILCHECK
				    fgw_freetssstack(&($1));
				    fgw_freetssstack(&($3));
				}
	| exp UNITS { pstate->parseroptions|=QUALIFIERHACK; } unitcl {
				    exprstack_t r;
				    int n;

/*
**  we complicate things a bit to have units behave as in the engine
**  rather than an interval shorthand
*/
				    pstate->parseroptions&=~QUALIFIERHACK;
				    r.type=CINTTYPE;
				    r.val.intvalue=fgw_toint(&($1), NULL);
				    $$.type=CINVTYPE;
				    if (!($$.val.interval=(intrvl_t *)
					     fgw_smalloc(sizeof(intrvl_t))))
					FAIL(-208)
				    fgw_toinv(&r, $$.val.interval,
					TU_IENCODE(5, $4.type, $4.type), &n);
				    if (n)
					rsetnull(CINVTYPE,
						 (char *) $$.val.interval);
				    fgw_freetssstack(&($1));
				}
	| '-' exp  %prec NEG	{
				    dec_t dec1;

				    if (fgw_isnull(&($2)))
					$$=$2;
				    else
					switch ($2.type)
				 	{
				 	  case CSTRINGTYPE:
				 	  case FGWVAR:
					    fgw_setdouble(&($$),
						-fgw_todouble(&($2), &nullind));
					    break;
					  case CDECIMALTYPE:
					  case CMONEYTYPE:
					    status=deccvlong(-1, &dec1);
					    $$.type=$2.type;
					    if (!($$.val.decimal=
						   (dec_t *) fgw_smalloc(
							    sizeof(dec_t))))
						FAIL(-208)
					    else
						decmul($2.val.decimal,
						   &dec1, $$.val.decimal);
					    break;
				 	  case CDOUBLETYPE:
					    $$.type=$2.type;
					    $$.val.real=-$2.val.real;
					    break;
					  case CINTTYPE:
					    $$.type=$2.type;
					    $$.val.intvalue=-$2.val.intvalue;
					    break;
					  case CINVTYPE:
					    $$.type=$2.type;
					    if (!($$.val.interval=
						   (intrvl_t *) fgw_smalloc(
							    sizeof(intrvl_t))))
						FAIL(-208)
					    else
						invmuldbl($2.val.interval,
						   -1.0, $$.val.interval);
					    break;
					  default:
					    fgw_setnull(&($$));
					}
				    fgw_freetssstack(&($2));
				}
	| '+' exp  %prec PLUS	{
				    if (fgw_isnull(&($2)))
					$$=$2;
				    else
					switch ($2.type)
				 	{
				 	  case CSTRINGTYPE:
				 	  case FGWVAR:
					    fgw_setdouble(&($$),
						fgw_todouble(&($2), &nullind));
					    break;
				 	  case CDECIMALTYPE:
				 	  case CMONEYTYPE:
				 	  case CDOUBLETYPE:
					  case CINTTYPE:
					  case CINVTYPE:
					    $$=$2;
					    break;
					  default:
					    fgw_setnull(&($$));
					}
				    fgw_freetssstack(&($2));
				}
	| '(' exp ')'		{
				    $$=$2;
				}
;
boolexp:	exp IN '(' parms ')'	{
/* FIXME: should be finding a solution that uses left recursion */
				    exprstack_t *s;

				    s=&($4);
				    if (fgw_isnull(&($1)))
					fgw_setnull(&($$));
				    else
				    {
					$$.type=CINTTYPE;
					$$.val.intvalue=0;
					while (s)
					{
					    int r;

					    r=fgw_compare($1.type, &($1), s);
					    if (!nullind && !r)
					    {
						$$.val.intvalue=1;
						break;
					    }
					    s=s->next;
					}
					fgw_freetssstack(&($1));
				    }
				    while (s)
				    {
					fgw_freetssstack(s);
					s=s->next;
				    }
				}
	| exp NOT IN '(' parms ')'	{
/* FIXME: should be finding a solution that uses left recursion */
				    exprstack_t *s;

				    s=&($5);
				    if (fgw_isnull(&($1)))
					fgw_setnull(&($$));
				    else
				    {
					$$.type=CINTTYPE;
					$$.val.intvalue=1;
					while (s)
					{
					    int r;

					    r=fgw_compare($1.type, &($1), s);
/*
** a null in a NOT IN clause will yield NULL
** (NOT exp IN & exp NOT IN are semantically different. is this right?)
*/
					    if (nullind)
					    {
						fgw_setnull(&($$));
						break;
					    }
					    else if (!r)
					    {
						$$.val.intvalue=0;
						break;
					    }
					    s=s->next;
					}
					fgw_freetssstack(&($1));
				    }
				    while (s)
				    {
					fgw_freetssstack(s);
					s=s->next;
				    }
				}
	| exp betweencl exp AND exp	{
				    int rl, rh;

				    if (fgw_isnull(&($1)))
					fgw_setnull(&($$));
				    else
				    {
/*
** $3 needs to be smaller than $5, but that's ok the engine
** behaves the same way
*/
					rl=fgw_compare($1.type, &($1), &($3));
					if (nullind)
					    fgw_setnull(&($$));
					else
					{
					    rh=fgw_compare($1.type, &($1), &($5));
					    if (nullind)
						fgw_setnull(&($$));
					    else if ($2.type==BETWEEN)
						fgw_setint(&($$),
							   rl>=0 && rh<=0);
					    else
						fgw_setint(&($$), 
							   rl<0 || rh>0);
					}
				    }
				    fgw_freetssstack(&($1));
				}
	| exp mrexcl exp escape {
				    int r;
				    char *e, esc[STRINGCONVSIZE];

				    fgw_2string(&($1), &($3));
				    if (nullind)
					fgw_setnull(&($$));
				    else
				    {
					retquote(sholder1);
					retquote(sholder2);
				 	e=fgw_tostring(&($4), &esc, NULL);
/* FIXME: should I be testing for a null escape here? */
/* FIXME: using 4gl internals */
					_domatches((char) *e);
					popint(&r);
					if ($2.type==MATCHES)
					    fgw_setint(&($$), r);
					else

					    fgw_setint(&($$), !r);
				    }
				    fgw_freetssstack(&($1));
				    fgw_freetssstack(&($3));
				    fgw_freetssstack(&($4));
				}
	| exp lrexcl exp escape {
				    int r;
				    char *e, esc[STRINGCONVSIZE];

				    fgw_2string(&($1), &($3));
				    if (nullind)
					fgw_setnull(&($$));
				    else
				    {
					retquote(sholder1);
					retquote(sholder2);
				 	e=fgw_tostring(&($4), &esc, NULL);
/* FIXME: should I be testing for a null escape here? */
/* FIXME: using 4gl internals */
					_dolike((char) *e);
					popint(&r);
					if ($2.type==LIKE)
					    fgw_setint(&($$), r);
					else
					    fgw_setint(&($$), !r);
				    }
				    fgw_freetssstack(&($1));
				    fgw_freetssstack(&($3));
				    fgw_freetssstack(&($4));
				}
	| allexp OR allexp	{
				    int b1, b2, n1, n2;

				    b1=fgw_toboolean(&($1), &n1);
				    b2=fgw_toboolean(&($3), &n2);
				    nullind=n1||n2;
				    fgw_setint(&($$), b1 || b2);
				    fgw_freetssstack(&($1));
				    fgw_freetssstack(&($3));
				}
	| allexp AND allexp	{
				    int b1, b2, n1, n2;

				    b1=fgw_toboolean(&($1), &n1);
				    b2=fgw_toboolean(&($3), &n2);
				    nullind=n1||n2;
				    fgw_setint(&($$), b1 && b2);
				    fgw_freetssstack(&($1));
				    fgw_freetssstack(&($3));
				}
	| NOT allexp		{
				    int b1;

				    b1=fgw_toboolean(&($2), &nullind);
				    fgw_setint(&($$), !b1);
				    fgw_freetssstack(&($2));
				}
	| exp IS nullcl		{
				    int r;

				    nullind=0;
				    r=fgw_isnull(&($1));
				    if ($3.type==NULLVALUE)
					fgw_setint(&($$), r);
				    else
					fgw_setint(&($$), !r);
				    fgw_freetssstack(&($1));
				}
	| exp eqcl exp		{
				    int r;

				    r=fgw_compare(fgw_exprtype($1.type, $3.type),
						  &($1), &($3));
				    fgw_setint(&($$), !r);
				    fgw_freetssstack(&($1));
				}
	| exp NEQ exp		{
				    int r;

				    r=fgw_compare(fgw_exprtype($1.type, $3.type),
						  &($1), &($3));
				    fgw_setint(&($$), (r!=0));
				    fgw_freetssstack(&($1));
				}
	| exp LEQ exp		{
				    int r;

				    r=fgw_compare(fgw_exprtype($1.type, $3.type),
						  &($1), &($3));
				    fgw_setint(&($$), (r<=0));
				    fgw_freetssstack(&($1));
				}
	| exp '<' exp		{
				    int r;

				    r=fgw_compare(fgw_exprtype($1.type, $3.type),
						  &($1), &($3));
				    fgw_setint(&($$), (r<0));
				    fgw_freetssstack(&($1));
				}
	| exp GEQ exp		{
				    int r;

				    r=fgw_compare(fgw_exprtype($1.type, $3.type),
						  &($1), &($3));
				    fgw_setint(&($$), (r>=0));
				    fgw_freetssstack(&($1));
				}
	| exp '>' exp		{
				    int r;

				    r=fgw_compare(fgw_exprtype($1.type, $3.type),
						  &($1), &($3));
				    fgw_setint(&($$), (r>0));
				    fgw_freetssstack(&($1));
				}
	| '(' boolexp ')'	{
				    $$=$2;
				}
;
rangecl:  '[' exp ']'		{
				    int i, n;

				    i=fgw_toint(&($2), &n);
				    if (i<=0 || iholder1>0x7fff || n)
					FAIL(-307)
				    $$.val.range[0]=i-1;
				    $$.val.range[1]=i-1;
				    fgw_freetssstack(&($2));
				}
	| '[' exp ',' exp ']'	{
				    fgw_2int(&($2), &($4));
				    if (iholder1<=0 || iholder2<iholder1 ||
					nullind || iholder2>0x7fff)
					FAIL(-307)
				    $$.val.range[0]=iholder1-1;
				    $$.val.range[1]=iholder2-1;
				    fgw_freetssstack(&($2));
				    fgw_freetssstack(&($4));
				}
;
qualcl:	/* empty */		{
				    $$.type=-1;
				}
	| unitcl TO unitcl	{
				    if ($1.type>$3.type)
					FAIL(-201)
				    $$.type=TU_DTENCODE($1.type, $3.type);
				}
;
unitcl:	  YEAR			{
				    $$.type=TU_YEAR;
				}
	| MONTH			{
				    $$.type=TU_MONTH;
				}
	| DAY			{
				    $$.type=TU_DAY;
				}
	| HOUR			{
				    $$.type=TU_HOUR;
				}
	| MINUTE		{
				    $$.type=TU_MINUTE;
				}
	| SECOND		{
				    $$.type=TU_SECOND;
				}
	| FRACTION		{
				    $$.type=TU_F5;
				}
;
casecl:	  casecl WHEN allexp THEN exp	{
				    iholder1=fgw_toboolean(&($3), &nullind);
				    if ($1.type!=ELSE)
				    {
					$$=$1;
					fgw_freetssstack(&($3));
					fgw_freetssstack(&($5));
				    }
				    else if (iholder1)
				    {
					$$=$5;
					fgw_freetssstack(&($3));
				    }
				    else
				    {
					$$.type=ELSE;
					fgw_freetssstack(&($3));
					fgw_freetssstack(&($5));
				    }
				}
	| /* empty */		{
					$$.type=ELSE;
				}
;
lcasecl:  WHEN exp THEN exp lcasecl	{
				     $2.next=&($4);
				     $4.next=&($5);
				     $$=$2;
				}
	| WHEN exp THEN exp	{
				     $2.next=&($4);
				     $4.next=NULL;
				     $$=$2;
				}
;
elsecl:	  ELSE exp		{
				    $$=$2;
				}
	| /* empty */		{
				    fgw_setnull(&($$));
				}
;
nullcl:	  NULLVALUE		{
				    $$.type=NULLVALUE;
				}
	| NOT NULLVALUE		{
				    $$.type=~NULLVALUE;
				}
;
eqcl:	  '='
	| EQ
;
parms:	  allexp		{
				    $1.next=NULL;
				    $$=$1;
				}
/*
** we want right recursion, as our aim is to have a linked
** list of elements on the stack
*/
	| allexp ',' parms	{	
				    $1.next=&($3);
				    $$=$1;
				}
;
betweencl:  BETWEEN		{
				    $$.type=BETWEEN;
				}
 	| NOT BETWEEN		{
				    $$.type=~BETWEEN;
				}
;
mrexcl:	  MATCHES		{
				    $$.type=MATCHES;
				}
 	| NOT MATCHES		{
				    $$.type=~MATCHES;
				}
;
lrexcl:	  LIKE			{
				    $$.type=LIKE;
				}
 	| NOT LIKE		{
				    $$.type=~LIKE;
				}
;
escape:	  ESCAPE exp		{
				    $$=$2;
				}
	| /* empty */		{
				    $$.type=FGWVAR;
				    $$.val.string="\\";
				}

;
%%

/*
** csqpc interface
*/
static void init_sqp();

/*
** the parser
*/
int sql_parser(state)
parserstate_t *state;
{
    pstate=state;
    if (pstate->parseroptions)
	pstate->parseroptions=EXPRONLY;
    pstate->ibufp=pstate->o_query+pstate->phase1.stmt_start;
    init_sqp();
    status=0;
    yyparse();
    return status;
}

/*
** returns token, if string matches one
*/
fgw_scanreserved(str, t)
char *str;
tokenlist_t *t;
{
/*
** scan reserved words, bomb out if found
*/
    while (t)
    {
	if (stcmpr(str, t->name))
	    t=t->next;
	else
	    return t->type;
    }
    return 0;
}

/*
** returns delimident flag
*/
fgw_delimident()
{
    return delimident;
}

/*
** returns is_child flag
*/
fgw_ischild()
{
    return is_child;
}

/*
** sets fork status (output/append/pipe)
*/
fgw_setfork(ec, cs)
int ec, cs;
{
    errcode=ec;
    childstatus=cs;
}

/*
** known functions
**
** ascii
*/
static void ascii_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    int c, n;

/* FIXME: not GLS aware */
    if (!(funcout->val.string=fgw_smalloc(1)))
	status=-208;
    else
    {
	funcout->type=CSTRINGTYPE;
	c=fgw_toint(s, &n);
	if (n)
	   rsetnull(CSTRINGTYPE, funcout->val.string);
	else if (c<1 || c>255)
	   status=-717;
	else
	    *funcout->val.string=(char) c;
    }
}

/*
** clipped
*/
static void clipped_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    int n, l;
    char *c, cbuf[STRINGCONVSIZE], *p;

    c=fgw_tostring(s, &cbuf, &n);
    if (n)
	l=0;
    else if (l=stleng(c))
    {
	p=c+l-1;
	while (*p--==' ')
	    l--;
    }
    if (!(funcout->val.string=fgw_smalloc(l)))
	status=-208;
    else
    {
	funcout->type=CSTRINGTYPE;
	if (n)
	    rsetnull(CSTRINGTYPE, funcout->val.string);
	else
	{
	    if (l)
		bycopy(c, funcout->val.string, l);
	    *(funcout->val.string+l)='\0';
	}
    }
}

/*
** does actual padding
*/
static dopadding_sqp(cnt, ist, ost)
int cnt;
char *ist, *ost;
{
    int l;

    l=stleng(ist);
    while (cnt>0)
    {
	bycopy(ist, ost, cnt);
	cnt-=l;
	ost+=l;
    }
}

/*
** spaces
*/
static void spaces_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    int sp, n;

    sp=fgw_toint(s, &n);
    if (n)
	fgw_setnull(funcout);
    else if (sp<=0)
	status=-717;
    else if (!(funcout->val.string=(char *) fgw_smalloc(sp)))
	status=-208;
    else
    {
	funcout->type=CSTRINGTYPE;
	dopadding_sqp(sp, " ", funcout->val.string);
	*(funcout->val.string+sp)='\0';
    }
}

/*
** exec
*/
static void exec_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    int n;
    char *c, cbuf[STRINGCONVSIZE];

    if (pstate->parseroptions & EXPRONLY)
    {
	status=-201;
	return;
    }
    c=fgw_tostring(s, &cbuf, &n);
/*
** a bit too overprotective, but only childs can exec
*/
    if (is_child)
    {
	execl("/bin/sh", "sh", "-c", c, NULL);
	errcode=errno;
    }
    else
	status=1;
    funcout->type=CINTTYPE;
    funcout->val.intvalue=-1;
}

/*
** fork
*/
static void fork_sqp(funcout)
exprstack_t *funcout;
{
    if (pstate->parseroptions & EXPRONLY)
    {
	status=-201;
	return;
    }
    funcout->type=CINTTYPE;
    funcout->val.intvalue=(int) fork();
/*
** parent branch
*/
    if (funcout->val.intvalue)
	errcode=errno;
/*
** child branch
*/
    else
    {
	sqldetach();
	is_child=1;
    }
}

/*
** getenv
*/
static void getenv_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    int n, l;
    char *e, ebuf[STRINGCONVSIZE], *v;

    l=0;
    e=fgw_tostring(s, &ebuf, &n);
    if (!n && (v=getenv(e)))
	l=stleng(v);
    if (!(funcout->val.string=fgw_smalloc(l)))
	status=-208;
    else
    {
	funcout->type=CSTRINGTYPE;
	if (n)
	    rsetnull(CSTRINGTYPE, funcout->val.string);
	else
	{
	    if (l)
		bycopy(v, funcout->val.string, l);
	    *(funcout->val.string+l)='\0';
	}
    }
}

/*
** wait
*/
static void wait_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    if (pstate->parseroptions & EXPRONLY)
    {
	status=-201;
	return;
    }
    funcout->type=CINTTYPE;
    do
    {
        funcout->val.intvalue=wait(&childstatus);
    } while (funcout->val.intvalue==-1 && errno==EINTR);
    if (funcout->val.intvalue==-1)
        errcode=errno;
    else
        childstatus=childstatus>>8;
}

/*
** waitpid
*/
static void waitpid_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    int pid, n1;

    if (pstate->parseroptions & EXPRONLY)
    {
	status=-201;
	return;
    }
    pid=fgw_toint(s, &n1);
    funcout->type=CINTTYPE;
    do
    {
	funcout->val.intvalue=waitpid(pid, &childstatus, WUNTRACED);
    } while (funcout->val.intvalue==-1 && errno==EINTR);
    if (funcout->val.intvalue==-1)
	errcode=errno;
    else
	childstatus=childstatus>>8;
}

/*
** index
*/
static void index_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    fgw_2string(s, s->next);
    if (nullind)
	fgw_setnull(funcout);
    else
    {
	funcout->type=CINTTYPE;
	funcout->val.intvalue=fgw_pos(sholder1, sholder2);
    }
}

/*
** pad
*/
static void pad_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    int sp, n1, n2;
    char *ps, cbuf[STRINGCONVSIZE];

    sp=fgw_toint(s, &n1);
    ps=fgw_tostring(s->next, &cbuf, &n2);
    if (n1||n2)
	fgw_setnull(funcout);
    else if (sp<=0)
	status=-717;
    else if (!(funcout->val.string=(char *) fgw_smalloc(sp)))
	status=-208;
    else
    {
	funcout->type=CSTRINGTYPE;
	dopadding_sqp(sp, ps, funcout->val.string);
	*(funcout->val.string+sp)='\0';
    }
}

/*
** random
*/
static void random_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    int newseed, top, n;

    funcout->type=CINTTYPE;
    if (s->next)
	if (s->next->next)
	{
	    status=-664;
	    return;
	}
	else
	{
	    newseed=fgw_toint(s->next, &n);
	    if (n)
	    {
		status=-717;	
		return;
	    }
	    else
		srand48(newseed);
	}
    top=fgw_toint(s, &n);
    if (n)
	rsetnull(CINTTYPE, (char *) &funcout->val.intvalue);
    else
	funcout->val.intvalue=lrand48() % top;
}

/*
** current
*/
static void current_sqp(funcout, q)
exprstack_t *funcout;
int q;
{
    if (q<0)
	q=TU_DTENCODE(TU_YEAR, TU_SECOND);
    funcout->type=CDTIMETYPE;
    if (!(funcout->val.datetime=(dtime_t *) fgw_smalloc(sizeof(dtime_t))))
	status=-208;
    else
    {
	funcout->val.datetime->dt_qual=q;
	dtcurrent(funcout->val.datetime);
    }
}

/*
** today
*/
static void today_sqp(funcout)
exprstack_t *funcout;
{
    funcout->type=CDATETYPE;
    rtoday(&funcout->val.intvalue);
}

/*
** user
*/
static void user_sqp(funcout)
exprstack_t *funcout;
{
    struct passwd *p;

    if (p=getpwuid(getuid()))
    {
	funcout->type=CSTRINGTYPE;
	if (funcout->val.string=fgw_smalloc(strlen(p->pw_name)))
	    stcopy(p->pw_name, funcout->val.string);
	else
	    status=-208;
    }
    else
        fgw_setnull(&funcout);
}

/*
** decode
*/
static void decode_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    exprstack_t *w;

    fgw_setnull(funcout);
    w=s->next;
    while (w)
    {
	int r;

	if (w->next)
	{
	    r=fgw_compare(s->type, s, w);
	    w=w->next;
	    if (r)
	    {
		w=w->next;
		continue;
	    }
	}
	*funcout=*w;
	fgw_setint(w, 0);		/* hack: avoid freeing strings */
	break;
    }
}

/*
** nvl
*/
static void nvl_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    if (fgw_isnull(s))
        s=s->next;
    *funcout=*s;
    fgw_setint(s, 0);		/* hack: avoid freeing strings */
}

/*
** abs
*/
static void abs_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    double f;
    int n;

    f=fgw_todouble(s, &n);
    funcout->type=CDOUBLETYPE;
    if (n)
	rsetnull(CDOUBLETYPE, (char *) &(funcout->val.real));
    else
	funcout->val.real=fabs(f);
}

/*
** mod
*/
static void mod_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    fgw_2int(s, s->next);
    funcout->type=CINTTYPE;
    if (nullind)
	rsetnull(CINTTYPE, (char *) &(funcout->val.intvalue));
    else if (iholder2==0)
	status=-717;
    else
	funcout->val.intvalue=iholder1-(iholder1/iholder2)*iholder2;
}

/*
** pow
*/
static void pow_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    fgw_2double(s, s->next);
    funcout->type=CDOUBLETYPE;
    if (nullind)
	rsetnull(CDOUBLETYPE, (char *) &(funcout->val.real));
    else
	funcout->val.real=pow(fholder1, fholder2);
}

/*
** root
*/
static void root_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    fgw_2double(s, s->next);
    funcout->type=CDOUBLETYPE;
    if (nullind)
	rsetnull(CDOUBLETYPE, (char *) &(funcout->val.real));
    else if (fholder2==0.0)
	status=-717;
    else
	funcout->val.real=pow(fholder1, 1.0/fholder2);
}

/*
** does actual rounding
*/
static void fgw_round(s, r, funcout)
exprstack_t *s;
double r;
exprstack_t *funcout;
{
    double f;
    int i, n1, n2;

/*
** check args & convert
*/
    f=fgw_todouble(s, &n1);
    if (s->next)
	if (s->next->next)
	{
	    status=-664;
	    return;
	}
	else
	    i=fgw_toint(s->next, &n2);
    else
	i=0;
    funcout->type=CDOUBLETYPE;
    if (n1||n2)
	rsetnull(CDOUBLETYPE, (char *) &(funcout->val.real));
    else
    {
	double d;

	d=pow(10.0, -i);
	if (f>0.0)
	    funcout->val.real=floor((f/d)+r)*d;
	else
	    funcout->val.real=floor((f/d)-r)*d;
    }
}

/*
** round
*/
static void round_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    fgw_round(s, 0.5, funcout);
}

/*
** sqrt
*/
static void sqrt_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    double f;
    int n;

    f=fgw_todouble(s, &n);
    funcout->type=CDOUBLETYPE;
    if (n)
	rsetnull(CDOUBLETYPE, (char *) &(funcout->val.real));
    else
	funcout->val.real=sqrt(f);
}

/*
** trunc
*/
static void trunc_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    fgw_round(s, 0.0, funcout);
}

/*
** dbinfo
*/
static void dbinfo_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    int n;
    char *c, cbuf[STRINGCONVSIZE];

    funcout->type=CINTTYPE;
    c=fgw_tostring(s, &cbuf, &n);
/* FIXME: don't check for GLS overruns */
    rdownshift(c);
    if (n)
	status=-728;
    else if (!strcmp(c, "sqlca.sqlerrd1"))
	funcout->val.intvalue=sqlca.sqlerrd[1];
    else if (!strcmp(c, "sqlca.sqlerrd2"))
	funcout->val.intvalue=sqlca.sqlerrd[2];
    else if (!strcmp(c, "sqlca.sqlcode"))
	funcout->val.intvalue=sqlca.sqlcode;
    else if (!strcmp(c, "errno"))
	funcout->val.intvalue=errcode;
    else if (!strcmp(c, "$?"))
	funcout->val.intvalue=childstatus;
    else
	status=-728;
}

/*
** exp
*/
static void exp_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    double f;
    int n;

    f=fgw_todouble(s, &n);
    funcout->type=CDOUBLETYPE;
    if (n)
	rsetnull(CDOUBLETYPE, (char *) &(funcout->val.real));
    else
	funcout->val.real=exp(f);
}

/*
** log10
*/
static void log10_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    double f;
    int n;

    f=fgw_todouble(s, &n);
    funcout->type=CDOUBLETYPE;
    if (n)
	rsetnull(CDOUBLETYPE, (char *) &(funcout->val.real));
    else if (f<=0.0)
	status=-717;
    else
	funcout->val.real=log10(f);
}

/*
** logn
*/
static void logn_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    double f;
    int n;

    f=fgw_todouble(s, &n);
    funcout->type=CDOUBLETYPE;
    if (n)
	rsetnull(CDOUBLETYPE, (char *) &(funcout->val.real));
    else if (f<=0.0)
	status=-717;
    else
	funcout->val.real=log(f);
}

/*
** hex
*/
static void hex_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    int i, n;

    if (!(funcout->val.string=fgw_smalloc(11)))
	status=-208;
    else
    {
	i=fgw_toint(s, &n);
	funcout->type=CSTRINGTYPE;
	if (n)
	    rsetnull(CSTRINGTYPE, funcout->val.string);
	else
	    sprintf(funcout->val.string, "0x%x", i);
    }
}

/*
** char_length
*/
static void charlength_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    char *c, cbuf[STRINGCONVSIZE];
    int n;

    c=fgw_tostring(s, &cbuf, &n);
    funcout->type=CINTTYPE;
    if (n)
	funcout->val.intvalue=0;
    else
	funcout->val.intvalue=stleng(c);
}

/*
** length
*/
static void length_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    char *c, *p, cbuf[STRINGCONVSIZE];
    int l, n;

    c=fgw_tostring(s, &cbuf, &n);
    funcout->type=CINTTYPE;
    if (n || !(l=stleng(c)))
	funcout->val.intvalue=0;
    else
    {
	p=c+l-1;
	while (l && *p--==' ')
	    l--;
	funcout->val.intvalue=l;
    }
}

/*
** datetime
*/
static void datetime_sqp(s, funcout, q)
exprstack_t *s, *funcout;
int q;
{
    int n1, n2;

     if (q<0)
	q=TU_DTENCODE(TU_YEAR, TU_SECOND);
     funcout->type=CDTIMETYPE;
     if (!(funcout->val.datetime=(dtime_t *) fgw_smalloc(sizeof(dtime_t))))
     {
	status=-208;
	return;
     }
#ifdef HAS_DTFMT
    if (s->next)
	if (s->next->next)
	{
	    status=-664;
	    return;
	}
	else
	{
	    fgw_2string(s, s->next);
	    status=dtcvfmtasc(sholder1, sholder2, funcout->val.datetime);
	}
    else
#endif
    {
	fgw_todtime(s, funcout->val.datetime, q, &n1);
	if (n1)
	    rsetnull(CDTIMETYPE, funcout->val.string);
    }
}

/*
** interval
*/
static void interval_sqp(s, funcout, q)
exprstack_t *s, *funcout;
int q;
{
    int n1, n2;

    if (q<0)
	q=TU_IENCODE(5, TU_DAY, TU_F5);
    else
	q=TU_IENCODE(5, TU_START(q), TU_END(q));
    funcout->type=CINVTYPE;
    if (!(funcout->val.interval=(intrvl_t *) fgw_smalloc(sizeof(intrvl_t))))
    {
	status=-208;
	return;
    }
#ifdef HAS_DTFMT
    if (s->next)
	if (s->next->next)
	{
	    status=-664;
	    return;
	}
	else
	{
	    fgw_2string(s, s->next);
	    status=incvfmtasc(sholder1, sholder2, funcout->val.interval);
	}
    else
#endif
    {
	fgw_toinv(s, funcout->val.interval, q, &n1);
	if (n1)
	    rsetnull(CINVTYPE, (char *) funcout->val.interval);
    }
}

/*
** date
*/
static void date_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    int n1, n2;

    funcout->type=CDATETYPE;
    if (s->next)
	if (s->next->next)
	{
	    status=-664;
	    return;
	}
	else
	{
	    fgw_2string(s, s->next);
	    status=rdefmtdate(&funcout->val.intvalue, sholder2, sholder1);
	}
    else
    {
	funcout->val.intvalue=fgw_todate(s, &n1);
	if (n1)
	    rsetnull(CDATETYPE, (char *) &funcout->val.intvalue);
    }
}

/*
** day
*/
static void day_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    short mdy[3];
    int d, n;

    d=fgw_todate(s, &n);
    if (n)
	fgw_setnull(funcout);
    else
    {
	funcout->type=CINTTYPE;
	status=rjulmdy(d, mdy);
	funcout->val.intvalue=mdy[1];
    }
}

/*
** month
*/
static void month_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    short mdy[3];
    int d, n;

    d=fgw_todate(s, &n);
    if (n)
	fgw_setnull(funcout);
    else
    {
	funcout->type=CINTTYPE;
	status=rjulmdy(d, mdy);
	funcout->val.intvalue=mdy[0];
    }
}

/*
** year
*/
static void year_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    short mdy[3];
    int d, n;

    d=fgw_todate(s, &n);
    if (n)
	fgw_setnull(funcout);
    else
    {
	funcout->type=CINTTYPE;
	status=rjulmdy(d, mdy);
	funcout->val.intvalue=mdy[2];
    }
}

/*
** weekday
*/
static void weekday_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    int d, n;

    d=fgw_todate(s, n);
    if (n)
	fgw_setnull(funcout);
    else
    {
	funcout->type=CINTTYPE;
	funcout->val.intvalue=rdayofweek(d);
    }
}

/*
** mdy
*/
static void mdy_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    short mdy[3];
    int i, c, n;

    for (c=0; c<3; c++, s=s->next)
    {
	i=fgw_toint(s, &n);
	if (n)
	{
	    fgw_setnull(funcout);
	    return;
	}
	mdy[c]=i;
    }
    funcout->type=CDATETYPE;
    status=rmdyjul(mdy, &funcout->val.intvalue);
}

/*
** cos
*/
static void cos_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    double f;
    int n;

    f=fgw_todouble(s, &n);
    funcout->type=CDOUBLETYPE;
    if (n)
	rsetnull(CDOUBLETYPE, (char *) &(funcout->val.real));
    else
	funcout->val.real=cos(f);
}

/*
** sin
*/
static void sin_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    double f;
    int n;

    f=fgw_todouble(s, &n);
    funcout->type=CDOUBLETYPE;
    if (n)
	rsetnull(CDOUBLETYPE, (char *) &(funcout->val.real));
    else
	funcout->val.real=sin(f);
}

/*
** tan
*/
static void tan_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    double f;
    int n;

    f=fgw_todouble(s, &n);
    funcout->type=CDOUBLETYPE;
    if (n)
	rsetnull(CDOUBLETYPE, (char *) &(funcout->val.real));
    else
	funcout->val.real=tan(f);
}

/*
** acos
*/
static void acos_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    double f;
    int n;

    f=fgw_todouble(s, &n);
    funcout->type=CDOUBLETYPE;
    if (n)
	rsetnull(CDOUBLETYPE, (char *) &(funcout->val.real));
    else
/* if not in [-1..1] will return nan on most systems */
	funcout->val.real=acos(f);
}

/*
** asin
*/
static void asin_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    double f;
    int n;

    f=fgw_todouble(s, &n);
    funcout->type=CDOUBLETYPE;
    if (n)
	rsetnull(CDOUBLETYPE, (char *) &(funcout->val.real));
    else
/* if not in [-1..1] will return nan on most systems */
	funcout->val.real=asin(f);
}

/*
** atan
*/
static void atan_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    double f;
    int n;

    f=fgw_todouble(s, &n);
    funcout->type=CDOUBLETYPE;
    if (n)
	rsetnull(CDOUBLETYPE, (char *) &(funcout->val.real));
    else
	funcout->val.real=atan(f);
}

/*
** atan2
*/
static void atan2_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    fgw_2double(s, s->next);
    funcout->type=CDOUBLETYPE;
    if (nullind)
	rsetnull(CDOUBLETYPE, (char *) &(funcout->val.real));
    else
	funcout->val.real=atan2(fholder1, fholder2);
}

/*
** substr
*/
static void substr_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    int l, n;
    char *c, cbuf[STRINGCONVSIZE];

    funcout->type=CSTRINGTYPE;
    c=fgw_tostring(s, &cbuf, &n);
    fgw_2int(s->next, s->next->next);
    if (n||nullind)
    {
	if (!(funcout->val.string=fgw_smalloc(0)))
	    status=-208;
	else
	    rsetnull(CSTRINGTYPE, funcout->val.string);
	return;
    }
/*
** can't have a negative length
*/
    if (iholder2<1)
    {
	status=717;
	return;
    }
/*
**  if start is negative, we count from the tail
*/
    l=stleng(c);
    if (iholder1<0)
	iholder1=l+iholder1;
    else if (iholder1)
	iholder1--;
/*
** can't have a negative start
*/
    if (iholder1<0)
    {
	status=717;
	return;
    }
/*
** and avoid stupid segvs
*/
    if (iholder1+iholder2>l)
	iholder2=l-iholder1;
    if (!(funcout->val.string=fgw_smalloc(iholder2+1)))
    {
	status=-208;
	return;
    }
    if (iholder1>l)
	*funcout->val.string='\0';
    else
    {
	bycopy(c+iholder1, funcout->val.string, iholder2);
	*(funcout->val.string+iholder2)='\0';
    }
}

/*
** replace
*/
static void replace_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    int pc, n, ni, idx, st, l, fl, tl, ol, il;
    exprstack_t *p;
    char *ob;
    char *sb, sbuf[STRINGCONVSIZE];
    char *fb, fbuf[STRINGCONVSIZE];
    char *tb, tbuf[STRINGCONVSIZE];

/*
** sort out parms:
*/
    if ((pc=fgw_parmcount(s))<2 || pc>5)
    {
	status=-664;
	return;
    }
/*
** original string
*/
    sb=fgw_tostring(s, &sbuf, &n);
    if (n)
	ol=0;
    else
	ol=stleng(sb);
/*
** from string
*/
    p=s->next;
    fb=fgw_tostring(p, &fbuf, &ni);
    if (ni)
	fl=0;
    else
	fl=stleng(fb);
    n|=ni;
/*
** optional to string
*/
    if (pc>2)
    {
	p=p->next;
	tb=fgw_tostring(p, &tbuf, &ni);
	if (ni)
	    tl=0;
	else
	    tl=stleng(tb);
/*	n|=ni; */
    }
    else
    {
	tb=(char *) &tbuf;
	*tb='\0';
	tl=0;
    }
/*
** optional start
*/
    if (pc>3)
    {
	p=p->next;
	st=fgw_toint(p, &ni);
	n|=ni;
	if (st<0)
	   st=ol+st;
	else if (st)
	    st--;
    }
    else
	st=0;
/*
** optional length
*/
    if (pc>4)
    {
	p=p->next;
	il=fgw_toint(p, &ni);
	n|=ni;
    }
    else
	il=ol;
/*
** allocate memory
*/
    funcout->type=CSTRINGTYPE;
    if (!(funcout->val.string=fgw_smalloc(ol)))
    {
	status=-208;
	return;
    }
/*
** & return null if any parm null
*/
    if (n)
	rsetnull(CSTRINGTYPE, funcout->val.string);
/*
** wrong parms
*/
    else if (il<1 || st<0)
	status=-717;
/*
** empty from string, nothing to change
*/
    else if (!*fb)
	stcopy(sb, funcout->val.string);
    else
    {
	l=0;
	ob=funcout->val.string;
	if (st)
	{
	    bycopy(sb, ob, st);
	    sb+=st;
	    ob+=st;
	    il-=st;
	}
/*
** scan input string
*/
	for (;;)
	{
/*
** search next instance of 'from' text
*/
	    if (!(idx=fgw_pos(sb, fb)) || (idx--)>il)
	    {
/*
** not there or beyond limit
*/
		stcopy(sb, ob);
		return;
	    }
	    if (l+il+tl-fl>ol)
/*
** output buffer doesn't fit, resize
*/
	    	if (ob=fgw_smalloc(l+il+tl-fl))
		{
		    bycopy(funcout->val.string, ob, l);
		    fgw_sfree(funcout->val.string);
		    funcout->val.string=ob;
		    ob+=l;
		}
		else
		{
		    status=-208;
		    return;
		}
/*
** copy and adjust pointers
*/
	    if (idx)
		bycopy(sb, ob, idx);
	    ob+=idx;
	    if (tl)
		bycopy(tb, ob, tl);
	    l+=tl+idx;
	    ob+=tl;
	    sb+=idx+fl;
	    il-=(idx+fl);
	}
    }
}

/*
** common bit of lpad & rpad
*/
static dorlpad_sqp(s, funcout, c, cbuf, p, pbuf, l , il)
exprstack_t *s, *funcout;
char **c, *cbuf, **p, *pbuf;
int *l, *il;
{
    int pc, n1, n2, n3;

    pc=fgw_parmcount(s);
    if (pc!=2 && pc!=3)
	status=-664;
    else
    {
	funcout->type=CSTRINGTYPE;
	*c=fgw_tostring(s, cbuf, &n1);
	*l=fgw_toint(s->next, &n2);
	if (pc==3)
	    *p=fgw_tostring(s->next->next, pbuf, &n3);
	else
	{
	    *p=" ";
	    n3=0;
	}
	if (n2)
	   fgw_setnull(funcout);
	else if (!(funcout->val.string=fgw_smalloc(*l)))
	    status=-208;
	else if (n1 || n3)
	    rsetnull(CSTRINGTYPE, funcout->val.string);
	else if (*l<=(*il=stleng(*c)))
	{
	    bycopy(*c, funcout->val.string, *l);
	    *(funcout->val.string+*l)='\0';
	}
    }
}

/*
** lpad
*/
static void lpad_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    char *c, cbuf[STRINGCONVSIZE], *p, pbuf[STRINGCONVSIZE];
    int l, il;

    dorlpad_sqp(s, funcout, &c, &cbuf, &p, &pbuf, &l , &il);
    if (l>il && !status)
    {
	dopadding_sqp(l-il, p, funcout->val.string);
	bycopy(c, funcout->val.string+l-il, il);
	*(funcout->val.string+l)='\0';
    }
}

/*
** rpad
*/
static void rpad_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    char *c, cbuf[STRINGCONVSIZE], *p, pbuf[STRINGCONVSIZE];
    int l, il;

    dorlpad_sqp(s, funcout, &c, &cbuf, &p, &pbuf, &l , &il);
    if (l>il && !status)
    {
	bycopy(c, funcout->val.string, il);
	dopadding_sqp(l-il, p, funcout->val.string+il);
	*(funcout->val.string+l)='\0';
    }
}

/*
** upper
*/
static void upper_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    int n;
    char *c, cbuf[STRINGCONVSIZE];

    c=fgw_tostring(s, &cbuf, &n);
    if (funcout->val.string=fgw_smalloc(strlen(c)*2))
    {
	funcout->type=CSTRINGTYPE;
	if (n)
	    rsetnull(CSTRINGTYPE, funcout->val.string);
	else
	{
	    stcopy(c, funcout->val.string);
	    rupshift(funcout->val.string);
	}
    }
    else
	status=-208;
}

/*
** lower
*/
static void lower_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    int n;
    char *c, cbuf[STRINGCONVSIZE];

    c=fgw_tostring(s, &cbuf, &n);
    if (funcout->val.string=fgw_smalloc(strlen(c)*2))
    {
	funcout->type=CSTRINGTYPE;
	if (n)
	    rsetnull(CSTRINGTYPE, funcout->val.string);
	else
	{
	    stcopy(c, funcout->val.string);
	    rdownshift(funcout->val.string);
	}
    }
    else
	status=-208;
}

/*
** initcap
*/
static void initcap_sqp(s, funcout)
exprstack_t *s, *funcout;
{
    char *c, *ip, *op, cbuf[STRINGCONVSIZE];
    int notaletter, n;

    c=fgw_tostring(s, &cbuf, &n);
    if (n)
	funcout->val.intvalue=0;
    else if (!(funcout->val.string=fgw_smalloc(stleng(c))))
	status=-208;
    else
    {
	funcout->type=CSTRINGTYPE;
	ip=c;
	op=funcout->val.string;
	notaletter=1;
/* FIXME: not GLS aware */
	for (;;)
	    if (*ip>='a' && *ip<='z' && notaletter)
	    {
		*op++=toupper(*ip++);
		notaletter=0;
	    }
	    else
	    {
		notaletter=(*ip<'A' || (*ip>'Z' && *ip<'a') || *ip>'z');
		if (!(*op++=*ip++))
		    break;
	    }
    }
}

/*
** counts parameters
*/
static int fgw_parmcount(s)
exprstack_t *s;
{
    int p;

    p=1;
    while (s->next)
    {
        s=s->next;
        p++;
    }
    return p;
}
/*
** ancillary data & routines
**
** reserved words list
*/
static tokenlist_t tokenlist[NUMTOKENS]=
{
    "for", NULL, FOR, 0, NULL,
    "foreach", NULL, FOREACH, 0, NULL,
    "while", NULL, WHILE, 0, NULL,
    "if", NULL, IF, 0, NULL,
    "elif", NULL, ELIF, 0, NULL,
    "else", NULL, ELSE, 0, NULL,
    "fi", NULL, FI, 0, NULL,
    "done", NULL, DONE, 0, NULL,
    "continue", NULL, CONTINUE, 0, NULL,
    "break", NULL, BREAK, 0, NULL,

    "display", NULL, DISPLAY, 0, NULL,
    "let", NULL, LET, 0, NULL,
    "load", NULL, LOAD, 0, NULL,
    "unload", NULL, UNLOAD, 0, NULL,
    "pipe", NULL, PIPE, 0, NULL,
    "append", NULL, APPEND, 0, NULL,
    "output", NULL, OUTPUT, 0, NULL,

    "select", NULL, SELECT, 0, NULL,
    "insert", NULL, INSERT, 0, NULL,
    "delete", NULL, DELETE, 0, NULL,
    "update", NULL, UPDATE, 0, NULL,
    "execute", NULL, EXECUTE, 0, NULL,

    "create", NULL, CREATE, 0, NULL,
    "end", NULL, END, 0, NULL,
    "procedure", NULL, PROCEDURE, 0, NULL,
    "function", NULL, FUNCTION, 0, NULL,

    "in", NULL, IN, 0, NULL,
    "into", NULL, INTO, 0, NULL,
    "using", NULL, USING, 0, NULL,
    "format", NULL, FORMAT, 0, NULL,
    "brief", NULL, BRIEF, 0, NULL,
    "vertical", NULL, VERTICAL, 0, NULL,
    "full", NULL, FULL, 0, NULL,
    "headers", NULL, HEADERS, 0, NULL,
    "from", NULL, FROM, 0, NULL,
    "to", NULL, TO, 0, NULL,
    "delimiter", NULL, DELIMITER, 0, NULL,

    "temp", NULL, TEMP, 0, NULL,
    "scratch", NULL, SCRATCH, 0, NULL,
    "external", NULL, EXTERNAL, 0, NULL,

    "and", NULL, AND, 0, NULL,
    "or", NULL, OR, 0, NULL,
    "not", NULL, NOT, 0, NULL,
    "is", NULL, IS, 0, NULL,
    "case", NULL, CASE, 0, NULL,
    "when", NULL, WHEN, 0, NULL,
    "then", NULL, THEN, 0, NULL,
    "null", NULL, NULLVALUE, 0, NULL,
    "between", NULL, BETWEEN, 0, NULL,
    "matches", NULL, MATCHES, 0, NULL,
    "like", NULL, LIKE, 0, NULL,
    "escape", NULL, ESCAPE, 0, NULL,
    "units", NULL, UNITS, 0, NULL,
    "hour", NULL, HOUR, 0, NULL,
    "minute", NULL, MINUTE, 0, NULL,
    "second", NULL, SECOND, 0, NULL,
    "fraction", NULL, FRACTION, 0, NULL,

    "ascii", ascii_sqp, FNCT, 1, NULL,
    "clipped", clipped_sqp, PFIXFNCT, 1, NULL,
    "spaces", spaces_sqp, PFIXFNCT, 1, NULL,

    "exec", exec_sqp, FNCT, 1, NULL,
    "fork", fork_sqp, FNCT, 0, NULL,
    "getenv", getenv_sqp, FNCT, 1, NULL,
    "wait", wait_sqp, FNCT, 0, NULL,
    "waitpid", waitpid_sqp, FNCT, 1, NULL,

    "index", index_sqp, FNCT, 2, NULL,
    "pad", pad_sqp, FNCT, 2, NULL,
    "random", random_sqp, FNCT, -1, NULL,

    "current", current_sqp, FNDN, 0, NULL,
    "today", today_sqp, FNCT, 0, NULL,
    "user", user_sqp, FNCT, 0, NULL,

/* dbservername */
/* sitename */

    "decode", decode_sqp, FNCT, -1, NULL,
    "nvl", nvl_sqp, FNCT, 2, NULL,

    "abs", abs_sqp, FNCT, 1, NULL,
    "mod", mod_sqp, FNCT, 2, NULL,
    "pow", pow_sqp, FNCT, 2, NULL,
    "root", root_sqp, FNCT, 2, NULL,
    "round", round_sqp, FNCT, -1, NULL,
    "sqrt", sqrt_sqp, FNCT, 1, NULL,
    "trunc", trunc_sqp, FNCT, -1, NULL,

    "dbinfo", dbinfo_sqp, FNCT, 1, NULL,

    "exp", exp_sqp, FNCT, 1, NULL,
    "log10", log10_sqp, FNCT, 1, NULL,
    "logn", logn_sqp, FNCT, 1, NULL,
    "hex", hex_sqp, FNCT, 1, NULL,

    "char_length", charlength_sqp, FNCT, 1, NULL,
    "character_length", charlength_sqp, FNCT, 1, NULL,
    "length", length_sqp, FNCT, 1, NULL,
/* octet_length e */

#ifdef HAS_DTFMT
    "datetime", datetime_sqp, FNDP, -1, NULL,
    "interval", interval_sqp, FNDP, -1, NULL,
#else
    "datetime", datetime_sqp, FNDP, 1, NULL,
    "interval", interval_sqp, FNDP, 1, NULL,
#endif
    "date", date_sqp, FNCT, -1, NULL,
    "day", day_sqp, DAY, 1, NULL,
    "month", month_sqp, MONTH, 1, NULL,
    "year", year_sqp, YEAR, 1, NULL,
    "weekday", weekday_sqp, FNCT, 1, NULL,
    "mdy", mdy_sqp, FNCT, 3, NULL,
/* extend e / f to l */
/* to_char e /fmt */
/* to_date e /fmt */

    "cos", cos_sqp, FNCT, 1, NULL,
    "sin", sin_sqp, FNCT, 1, NULL,
    "tan", tan_sqp, FNCT, 1, NULL,
    "acos", acos_sqp, FNCT, 1, NULL,
    "asin", asin_sqp, FNCT, 1, NULL,
    "atan", atan_sqp, FNCT, 1, NULL,
    "atan2", atan2_sqp, FNCT, 2, NULL,

/* trim leading/trailing/both e from e */
/* substring e from start for length */
    "substr", substr_sqp, FNCT, 3, NULL,
    "replace", replace_sqp, FNCT, -1, NULL,
    "lpad", lpad_sqp, FNCT, -1, NULL,
    "rpad", rpad_sqp, FNCT, -1, NULL,

    "lower", lower_sqp, FNCT, 1, NULL,
    "upper", upper_sqp, FNCT, 1, NULL,
    "initcap", initcap_sqp, FNCT, 1, NULL
};

/*
** error handler
*/
static void yyerror(s)
char *s;
{
/*
** set error if not alread set
*/
    if (!status)
	status=-201;
/*
** free resources
*/
    if (curstmt)
	sql_freestatement(curstmt);
}

/*
** scanner
*/
static int yylex()
{
    char c;
    int r;
    tokenlist_t *t;

/* if we ever want to revert to true datetime/interval constant syntax,
   here's the place to

    if (pstate->parseroptions&DTHACK)
    {
	pstate->parseroptions&=~DTHACK;
	while (c=*pstate->ibufp++!=')')
...etc
    }
    else
*/
    while (c=*pstate->ibufp++)
    {
/*
** skip spaces, tabs & newlines
*/
	if (c==' ' || c=='\t' || c=='\n')
	    continue;
	pstate->tokstart=pstate->ibufp-1;
/*
** looks like an hex number
*/
	if (c=='0' && (*pstate->ibufp=='x' ||
		       *pstate->ibufp=='X'))
	{
	    yylval.stack.type=CINTTYPE;
	    yylval.stack.val.intvalue=strtol(pstate->tokstart,
					     &(pstate->ibufp), 16);
	    return CNST;
	}
/*
** integer or float
*/
	else if (c>='0' && c<='9')
	{
	    yylval.stack.val.intvalue=strtol(pstate->tokstart,
					     &(pstate->ibufp), 10);
	    if (*pstate->ibufp=='.')
	    {
		yylval.stack.type=CDOUBLETYPE;
		yylval.stack.val.real=yylval.stack.val.intvalue+
					strtod(pstate->ibufp,
					       &(pstate->ibufp));
	    }
	    else
		yylval.stack.type=CINTTYPE;
	    return CNST;
	}
/*
** variable, function or keyword
*/
	else if ((c>='A' && c<='Z') || (c>='a' &&c<='z'))
	{
	    if (!(yylval.var=fgw_getvar(&(pstate->tsshead), pstate->tokstart,
					&(pstate->ibufp), &t)))
/*
** no memory, so stop scanning & parsing, issue an error
*/
	    {
		status=-208;
		return 0;
	    }
	    while (t)
	    {
		if (stcmpr(t->name, yylval.var))
		    t=t->next;
		else
		{
		    fgw_sfree(yylval.var);
		    switch (t->type)
		    {
		      case FNCT:
		      case FNDP:
		      case FNDN:
		      case PFIXFNCT:
			yylval.func=t;
			return t->type;
		      default:
			if (t->func && !(pstate->parseroptions & QUALIFIERHACK))
			{
			    yylval.func=t;
			    return FNCT;
			}
			return t->type;
		    }
		}
	    }
	    return VAR;
	}
/*
** delimited identifiers
*/
	else if (c=='\"' && delimident)
	{
	    if (yylval.var=fgw_getstring(&(pstate->tsshead), pstate->tokstart,
					 &(pstate->ibufp)))
		return VAR;
	    else
		return (int) c;
	}
/*
** strings
*/
	else if (c=='\'' || c=='\"')
	{
	    yylval.stack.type=CSTRINGTYPE;
	    if (yylval.stack.val.string=fgw_getstring(&(pstate->tsshead),
						      pstate->tokstart,
						      &(pstate->ibufp)))
		return CNST;
	    else
		return (int) c;
	}
/*
** operators
*/
	else if (c=='<' && *pstate->ibufp=='>')
	{
	    pstate->ibufp++;
	    return NEQ;
	}
	else if ((r=GEQ, c=='>') || (r=LEQ, c=='<') ||
		 (r=EQ, c=='=') || (r=NEQ, c=='!'))
	{
	    if (*pstate->ibufp=='=')
	    {
		pstate->ibufp++;
	    	return r;
	    }
	}
	else if (c=='|' && *pstate->ibufp=='|')
	{
	    pstate->ibufp++;
	    return DPIPE;
	}
/*
** everything else
*/
	return c;
    }
    return 0;
}

/*
** initiliazes module
*/
static void init_sqp()
{
    tokenlist_t src[NUMTOKENS], temp[NUMTOKENS], *t;
    int i, b, f;
    char *c;
#ifdef __STDC__
    unsigned
#endif
	long h;

    if (delimident>=0)
	return;
    delimident=(getenv("DELIMIDENT")!=NULL);
    srand48(time(NULL));
/*
** initialize token lists
*/
    for (i=0; i<NUMTOKENS; i++)
	src[i]=tokenlist[i];
    byfill(&tokenlist, sizeof(tokenlist), 0);
    byfill(&temp, sizeof(temp), 0);
    b=0;
    for (i=0; i<NUMTOKENS; i++)
    {
/*
** hash name, determine bucket
*/
	h=0;
	c=src[i].name;
	while (*c)
	    h=*c++ +65599*h;
#ifndef __STDC__
	h&=(MAXINT>>1);     /* avoid negative hashes! */
#endif
	h=(h%NUMTOKENS);
/*
** oops, bucket already in use
*/
	if (tokenlist[h].name)
	{
	    temp[b]=src[i];
	    temp[b++].next=&tokenlist[h];
	}
	else
	    tokenlist[h]=src[i];
    }
/*
** insert remaining tokens
*/
   f=0;
   for (i=0; i<b; i++)
   {
/*
** scan bucket chain
*/
	t=temp[i].next;
	while (t->next)
	    t=t->next;
/*
** find next free entry
*/
	while (tokenlist[f].name)
	    f++;
	tokenlist[f]=temp[i];
	tokenlist[f].next=NULL;
	t->next=&tokenlist[f];
    }
}

/*
** scans input buffer for variable name
*/
char *fgw_getvar(hd, s, n, t)
fgw_tsstype **hd;
char *s, **n;
tokenlist_t **t;
{
    char *v, *c;
#ifdef __STDC__
    unsigned
#endif
	long h;

    init_sqp();
    h=0;
    *n=s+1;
    while ((**n>='a' && **n<='z') ||
	   (**n>='A' && **n<='Z') ||
	   (**n>='0' && **n<='9') ||
	   (**n=='_'))
	(*n)++;
    if (v=(char *) fgw_tssmalloc(hd, (int) ((*n)-s)))
    {
	c=v;
	while (s<*n)
	{
	   *c=tolower(*s++);
	   h=*c++ +65599*h;
	}
	*c='\0';
#ifndef __STDC__
    h&=(MAXINT>>1);	/* avoid negative hashes! */
#endif
	*t=&tokenlist[h%NUMTOKENS];
    }
    return v;
}

/*
** scans input buffer for string
*/
char *fgw_getstring(h, s, n)
fgw_tsstype **h;
char *s, **n;
{
    char d, *sbuf=NULL;
    int sz=0, newsz;

    init_sqp();
    d=*s++;
    *n=s;
    for(;;)
    {
/*
** scan till end of quote
*/
	while ((**n) && (**n!=d))
	    (*n)++;
/*
** none found, bail out
*/
	if (!(**n))
	    goto bad_exit;
/*
** allocate new memory
*/
	newsz=(int) ((*n)-s);
	if (!(sbuf=(char *) fgw_tssrealloc(h, sbuf, sz+newsz)))
	{
	    status=-208;
	    goto bad_exit;
	}
/*
** copy string & adjust sizes
*/
	bycopy(s, sbuf+sz, newsz);
	sz+=newsz;
	*(sbuf+sz)='\0';
/*
** single quote: we're thru
*/
	if (*++(*n)!=d)
	    return sbuf;
/*
** if it was two quotes instead, will have to start again
*/
	else
	    s=(*n)++;
    }
bad_exit:
    if (sbuf)
	fgw_tssfree(h, sbuf);
    return NULL;
}

/*
** determines overall expression type
*/
static int fgw_exprtype(t1, t2)
int t1, t2;
{
    if (t1==CDTIMETYPE || t2==CDTIMETYPE)
	return CDTIMETYPE;
    if (t1==CDATETYPE || t2==CDATETYPE)
	return CDATETYPE;
    if (t1==CINVTYPE || t2==CINVTYPE)
	return CINVTYPE;
    if (t1==CMONEYTYPE || t2==CMONEYTYPE)
	return CDOUBLETYPE;
    if (t1==CDECIMALTYPE || t2==CDECIMALTYPE)
	return CDOUBLETYPE;
    if (t1==CDOUBLETYPE || t2==CDOUBLETYPE)
	return CDOUBLETYPE;
    if (t1==CINTTYPE || t2==CINTTYPE)
	return CINTTYPE;
    return CSTRINGTYPE;
}

/*
** determines overall expression type for arithmetic operators
*/
static int fgw_optype(s1, s2, sl, sr)
exprstack_t *s1, *s2, **sl, **sr;
{
    int t;

    if ((t=fgw_exprtype(s1->type, s2->type))==s1->type)
    {
	*sl=s1;
	*sr=s2;
    }
    else
    {
	*sl=s2;
	*sr=s1;
    }
    return t;
}

/*
** compares r1 & r2 converting to type t first. frees r2 
*/
static int fgw_compare(t, r1, r2)
int t;
exprstack_t *r1, *r2;
{
    int r, q;
    dtime_t dt1, dt2, dt3, dt4, *dp1, *dp2;
    intrvl_t in1, in2, in3, in4, *ip1, *ip2;
    dec_t *decp1, *decp2, dec1, dec2;
    int d1, d2;
    int n1, n2;

    switch (t)
    {
      case CDATETYPE:
	d1=fgw_todate(r1, &n1);
	d2=fgw_todate(r2, &n2);
	if (nullind=n1||n2)
	    r=0;
	else
	    r=(d1-d2);
	break;
      case CINTTYPE:
	fgw_2int(r1, r2);
	r=(iholder1-iholder2);
	break;
      case CDECIMALTYPE:
      case CMONEYTYPE:
	decp1=fgw_todecimal(r1, &dec1);
	decp2=fgw_todecimal(r2, &dec2);
	if (nullind=n1||n2)
	    r=0;
	else
	    r=deccmp(decp1, decp2);
	break;
      case CDOUBLETYPE:
	fgw_2double(r1, r2);
	r=(fholder1>fholder2? 1: (fholder1<fholder2? -1: 0));
	break;
      case FGWVAR:
      case CSTRINGTYPE:
	fgw_2string(r1, r2);
	r=stcmpr(sholder1, sholder2);
	break;
      case CDTIMETYPE:
	dp1=fgw_todtime(r1, &dt1, -1, &n1);
	dp2=fgw_todtime(r2, &dt2, -1, &n2);
	if (nullind=n1||n2)
	    r=0;
	else
	{
	    q=fgw_qualifier(dp1->dt_qual, dp2->dt_qual);
	    dt3.dt_qual=q;
	    status=dtextend(dp1, &dt3);
	    dt4.dt_qual=q;
	    status=dtextend(dp2, &dt4);
	    r=deccmp(&dt3.dt_dec, &dt4.dt_dec);
	}
	break;
      case CINVTYPE:
	ip1=fgw_toinv(r1, &in1, -1, &n1);
	ip2=fgw_toinv(r2, &in2, -1, &n2);
	if (nullind=n1||n2)
	    r=0;
	else
	{
	    q=fgw_qualifier(ip1->in_qual, ip2->in_qual);
/*
** check correct qualifier range
*/
	    if (TU_START(q)<TU_DAY && TU_END(q)>=TU_DAY)
		status=-1266;
	    else
	    {
		in3.in_qual=q;
		(void) invextend(ip1, &in3);
		in4.in_qual=q;
		(void) invextend(ip2, &in4);
		r=deccmp(&in3.in_dec, &in4.in_dec);
	    }
	}
    }
    fgw_freetssstack(r2);
    return r;
}

/*
**  generates stack entry from var 
*/
static void fgw_cvvar(s, e)
exprstack_t *s;
fgw_hstentry *e;
{
/*
** nullify if symbol undefined
*/
    if (!e)
	fgw_setnull(s);
    else switch (s->type=e->type)
    {
/*
** WARNING: this only works in the assumption that the symbol table does
** not change during the parsing (hst's do get reorganised), if this is
** not the case (ie a production of the kind VAR=exp is added within exp, 
** boolexp or allexp), then you should fgw_smalloc a temporary buffer,
** & copy the string there
*/
       case CSTRINGTYPE:
	s->type=FGWVAR;
	s->val.string=(char *) &(e->entry);
	break;
      case CDTIMETYPE:
      case CINVTYPE:
	s->val.datetime=(dtime_t *) fgw_smalloc(sizeof(dtime_t));
	fgw_move((char *) s->val.datetime, (char *) &(e->entry),
		    sizeof(dtime_t));
	break;
      case CDECIMALTYPE:
      case CMONEYTYPE:
	s->val.decimal=(dec_t *) fgw_smalloc(sizeof(dec_t));
	fgw_move((char *) s->val.decimal, (char *) &(e->entry),
		    sizeof(dec_t));
	break;
      case CDOUBLETYPE:
	s->val.real=*(double *) &(e->entry);
	break;
      default:
	s->val.intvalue=*(int *) &(e->entry);
    }
}

/*
** converts stack entries to ints
*/
static void fgw_2int(r1, r2)
exprstack_t *r1, *r2;
{
    int n1, n2;

    iholder1=fgw_toint(r1, &n1);
    iholder2=fgw_toint(r2, &n2);
    nullind=n1||n2;
}

static dec_t decbuf1, decbuf2;

/*
** converts stack entries to decimals
*/
static int fgw_2decimal(r1, r2, rr)
exprstack_t *r1, *r2, *rr;
{
    int n1, n2;

    if (!(rr->val.decimal=(dec_t *) fgw_smalloc(sizeof(dec_t))))
    {
	status=-208;
	return 0;
    }
    dholder1=fgw_todecimal(r1, &decbuf1, &n1);
    dholder2=fgw_todecimal(r2, &decbuf2, &n2);
    if (nullind=n1||n2)
    {
	rsetnull(CDECIMALTYPE, (char *) rr->val.decimal);
	return 0;
    }
    return 1;
}

/*
** converts stack entries to floats
*/
static void fgw_2double(r1, r2)
exprstack_t *r1, *r2;
{
    int n1, n2;

    fholder1=fgw_todouble(r1, &n1);
    fholder2=fgw_todouble(r2, &n2);
    nullind=n1||n2;
}

static char sbuf1[STRINGCONVSIZE], sbuf2[STRINGCONVSIZE];
/*
** converts stack entries to strings
*/
static void fgw_2string(r1, r2)
exprstack_t *r1, *r2;
{
    int n1, n2;

    sholder1=fgw_tostring(r1, &sbuf1, &n1);
    sholder2=fgw_tostring(r2, &sbuf2, &n2);
    nullind=n1||n2;
}

/*
** converts stack entries to booleans
*/
static int fgw_toboolean(r, n)
exprstack_t *r;
int *n;
{
    int i;

    switch (r->type)
    {
      case CINTTYPE:
      case CDATETYPE:
	*n=risnull(CINTTYPE, (char *) &(r->val.intvalue));
	return (r->val.intvalue!=0);
      case CDOUBLETYPE:
	*n=risnull(CDOUBLETYPE, (char *) &(r->val.real));
	return (r->val.real!=0);
      case CDECIMALTYPE:
      case CMONEYTYPE:
	if (*n=risnull(CDECIMALTYPE, (char *) r->val.decimal))
	    return 0;
	status=dectoint(r->val.decimal, &i);
	return (i!=0);
      case CDTIMETYPE:
	*n=risnull(CDTIMETYPE, (char *) r->val.datetime);
	return 1;
      case CINVTYPE:
	if (*n=risnull(CSTRINGTYPE, (char *) r->val.interval))
	    return 0;
	status=dectoint(&(r->val.interval->in_dec), &i);
	return (i!=0);
      case CSTRINGTYPE:
      case FGWVAR:
	*n=risnull(CSTRINGTYPE, r->val.string);
	return (strlen(r->val.string)>1 || *r->val.string!='0');
    }
}

/*
** converts stack entries to integers
*/
static int fgw_toint(r, n)
exprstack_t *r;
int *n;
{
    int i;
    char *e;

    if (n)
	*n=fgw_isnull(r);
    switch (r->type)
    {
      case CINTTYPE:
      case CDATETYPE:
	return r->val.intvalue;
	break;
      case CDOUBLETYPE:
	i=r->val.real;
	break;
      case CDECIMALTYPE:
      case CMONEYTYPE:
	status=dectoint(r->val.decimal, &i);
	break;
      case CSTRINGTYPE:
      case FGWVAR:
/*
** we could have a float so try it first
*/
	i=strtod(r->val.string, &e);
/*
** didn't go thru, could it be an int?
*/
	if (*e)
	{
	    i=strtol(r->val.string, &e, 0);
	    if (n)
		*n|=(*e!='\0');
	}
	break;
      default:
	if (n)
	    *n=1;
	rsetnull(CINTTYPE, (char *) &i);
    }
    return i;
}

/*
** converts stack entries to floats
*/
static double fgw_todouble(r, n)
exprstack_t *r;
int *n;
{
    double f;
    char *e;

    if (n)
	*n=fgw_isnull(r);
    switch (r->type)
    {
      case CINTTYPE:
      case CDATETYPE:
	f=r->val.intvalue;
	break;
      case CDOUBLETYPE:
	return r->val.real;
      case CDECIMALTYPE:
      case CMONEYTYPE:
	status=dectodbl(r->val.decimal, &f);
	break;
      case CSTRINGTYPE:
      case FGWVAR:
	f=strtod(r->val.string, &e);
	if (n)
	    *n|=(*e!='\0');
	break;
      default:
	if (n)
	    *n=1;
	rsetnull(CDOUBLETYPE, (char *) &f);
    }
    return f;
}

/*
** converts stack entries to decimals
*/
static dec_t *fgw_todecimal(r, b, n)
exprstack_t *r;
dec_t *b;
int *n;
{
    int isnull;

    isnull=fgw_isnull(r);
    if (n)
	*n=isnull;
    if (isnull)
	rsetnull(CDECIMALTYPE, b);
    else switch (r->type)
    {
      case CDECIMALTYPE:
      case CMONEYTYPE:
	return r->val.decimal;
      case CSTRINGTYPE:
      case FGWVAR:
	status=deccvasc(r->val.string, stleng(r->val.string), b);
	break;
      case CDATETYPE:
      case CINTTYPE:
	status=deccvint(r->val.intvalue, b);
	break;
      case CDOUBLETYPE:
	status=deccvdbl(r->val.real, b);
	break;
      default:
	if (n)
	    *n=1;
	rsetnull(CDECIMALTYPE, b);
    }
    return b;
}

/*
** converts stack entries to strings
*/
static char *fgw_tostring(r, b, n)
exprstack_t *r;
char *b;
int *n;
{
    int isnull;
    char *p;

    isnull=fgw_isnull(r);
    if (n)
	*n=isnull;
    if (isnull)
	rsetnull(CSTRINGTYPE, b);
    else switch (r->type)
    {
      case CSTRINGTYPE:
      case FGWVAR:
	return r->val.string;
      case CDTIMETYPE:
	status=dttoasc(r->val.datetime, b);
	break;
      case CINVTYPE:
	status=intoasc(r->val.interval, b);
	break;
      case CDATETYPE:
	rdatestr(r->val.intvalue, b);
	break;
      case CINTTYPE:
	sprintf(b, "%i", r->val.intvalue);
	break;
      case CDOUBLETYPE:
	sprintf(b, "%f", r->val.real);
	break;
      case CDECIMALTYPE:
      case CMONEYTYPE:
	status=dectoasc(r->val.decimal, b, STRINGCONVSIZE-1, -1);
	p=b+STRINGCONVSIZE-1;
	while (*p==' ')
	    p--;
	*++p='\0';
	break;
      default:
	if (n)
	    *n=1;
	rsetnull(CSTRINGTYPE, b);
    }
    return b;
}

/*
** converts stack entries to dates
*/
static int fgw_todate(r, n)
exprstack_t *r;
int *n;
{
    char *e;
    int d;

    switch (r->type)
    {
      case CINTTYPE:
      case CDATETYPE:
	if (n)
	    *n=risnull(CINTTYPE, (char *) &(r->val.intvalue));
	d=r->val.intvalue;
	break;
      case CDTIMETYPE:
	if (n)
	    *n=risnull(CDTIMETYPE, (char *) r->val.datetime);
/* FIXME: using 4gl internals */
	pushdtime(r->val.datetime);
	popdate(&d);
	break;
      case CDOUBLETYPE:
	if (n)
	    *n=risnull(CDOUBLETYPE, (char *) &(r->val.real));
	d=r->val.real;
	break;
      case CDECIMALTYPE:
      case CMONEYTYPE:
	if (n)
	    *n=risnull(CDECIMALTYPE, (char *) r->val.decimal);
	status=dectoint(r->val.decimal, &d);
	break;
      case CSTRINGTYPE:
      case FGWVAR:
	if (n)
	    *n=risnull(CSTRINGTYPE, r->val.string);
	rstrdate(r->val.string, &d);
	break;
      default:
	if (n)
	    *n=1;
	rsetnull(CDATETYPE, (char *) &d);
    }
    return d;
}

/*
** converts stack entries to datetimes
*/
static dtime_t *fgw_todtime(r, dt, q, n)
exprstack_t *r;
dtime_t *dt;
int q;
int *n;
{
    if (n)
	*n=fgw_isnull(r);
    if (q<0)
	dt->dt_qual=TU_DTENCODE(TU_YEAR, TU_SECOND);
    else
	dt->dt_qual=q;
    switch (r->type)
    {
      case CDTIMETYPE:
	if (q<0)
	    return r->val.datetime;
	status=dtextend(r->val.datetime, dt);
	return dt;
      case CDATETYPE:
	if (q<0)
	    dt->dt_qual=TU_DTENCODE(TU_YEAR, TU_DAY);
/* FIXME: using 4gl internals */
	pushdate(r->val.intvalue);
	popdtime(dt, dt->dt_qual);
	return dt;
      case FGWVAR:
      case CSTRINGTYPE:
	status=dtcvasc(r->val.string, dt);
	return dt;
      default:
	if (n)
	    *n=1;
	rsetnull(CDTIMETYPE, (char *) dt);
	return dt;
    }
}

/*
** converts stack entries to intervals
*/
static intrvl_t *fgw_toinv(r, in, q, n)
exprstack_t *r;
intrvl_t *in;
int q;
int *n;
{
    if (n)
	*n=fgw_isnull(r);
    if (q<0)
	in->in_qual=TU_IENCODE(5, TU_DAY, TU_F5);
    else
	in->in_qual=q;
    switch (r->type)
    {
      case CINVTYPE:
	if (q<0)
	    return r->val.interval;
	status=invextend(r->val.interval, in);
	return in;
      case FGWVAR:
      case CSTRINGTYPE:
	status=incvasc(r->val.string, in);
	return in;
      case CINTTYPE:
/* FIXME: using 4gl internals */
	pushint(r->val.intvalue);
	goto dub;
      case CDECIMALTYPE:
      case CMONEYTYPE:
/* FIXME: using 4gl internals */
	pushdec(r->val.decimal);
	goto dub;
      case CDOUBLETYPE:
/* FIXME: using 4gl internals */
	pushdub(&r->val.real);
dub:
	pushint(in->in_qual);
	 _dounits();
	popinv(in, in->in_qual);
	return in;
      default:
	if (n)
	    *n=1;
	rsetnull(CINVTYPE, (char *) in);
	return in;
    }
}

/*
**  determines largest qualifier for 2 intervals or datetimes
*/
static int fgw_qualifier(q1, q2)
int q1, q2;
{
    int s, e;

    s=TU_START(q1);
    if (s>TU_START(q2))
	s=TU_START(q2);
    e=TU_END(q1);
    if (e<TU_END(q2))
	e=TU_END(q2);
    return TU_DTENCODE(s, e);
}

#ifdef NEED_DTINVS
/*
**  need our homegrown invextend
*/
static int invextend(ii, oi)
intrvl_t *ii, *oi;
{
    int q;

    q=oi->in_qual;
/* FIXME: using 4gl internals */
    pushinv(ii);
    popinv(oi, q);
    return status;
}

/*
**  need our homegrown dtaddinv
*/
static int dtaddinv(id, ii, od)
dtime_t *id;
intrvl_t *ii;
dtime_t *od;
{
    int q;

    q=id->dt_qual;
/* FIXME: using 4gl internals */
    pushdtime(id);
    pushinv(ii);
    _doadd();
    popdtime(od, q);
    return status;
}

/*
**  need our homegrown dtsub
*/
static int dtsub(id, id2, oi)
dtime_t *id, *id2;
intrvl_t *oi;
{
    int q;

    q=oi->in_qual;
/* FIXME: using 4gl internals */
    pushdtime(id);
    pushdtime(id2);
    _dosub();
    popinv(oi, q);
    return status;
}

/*
**  need our homegrown dtsubinv
*/
static int dtsubinv(id, ii, od)
dtime_t *id;
intrvl_t *ii;
dtime_t *od;
{
    int q;

    q=id->dt_qual;
/* FIXME: using 4gl internals */
    pushdtime(id);
    pushinv(ii);
    _dosub();
    popdtime(od, q);
    return status;
}

/*
**  need our homegrown invmuldbl
*/
static int invmuldbl(ii, f, oi)
intrvl_t *ii;
double f;
intrvl_t *oi;
{
    int q;

    q=ii->in_qual;
/* FIXME: using 4gl internals */
    pushinv(ii);
    pushdub(&f);
    _domult();
    popinv(oi, q);
    return status;
}

/*
**  need our homegrown invdivdbl
*/
static int invdivdbl(ii, f, oi)
intrvl_t *ii;
double f;
intrvl_t *oi;
{
    int q;

    q=ii->in_qual;
/* FIXME: using 4gl internals */
    pushinv(ii);
    pushdub(&f);
    _dodiv();
    popinv(oi, q);
    return status;
}

/*
**  need our homegrown invdivinv
*/
static int invdivinv(ii, ii2, of)
intrvl_t *ii, *ii2;
double *of;
{
/* FIXME: using 4gl internals */
/* FIXME: apparently always yields null with 4.x */
    pushinv(ii);
    pushinv(ii2);
    _dodiv();
    popdub(of);
    return status;
}
#endif

/*
**  need our homegrown inadd
*/
static int inadd(ii, ii2, oi)
dtime_t *ii, *ii2;
intrvl_t *oi;
{
    int q;

    q=oi->in_qual;
/* FIXME: using 4gl internals */
    pushinv(ii);
    pushinv(ii2);
    _doadd();
    popinv(oi, q);
    return status;
}

/*
**  need our homegrown insub
*/
static int insub(ii, ii2, oi)
dtime_t *ii, *ii2;
intrvl_t *oi;
{
    int q;

    q=oi->in_qual;
/* FIXME: using 4gl internals */
    pushinv(ii);
    pushinv(ii2);
    _dosub();
    popinv(oi, q);
    return status;
}

/*
** tests for null stack element
*/
static int fgw_isnull(r)
exprstack_t *r;
{
    switch (r->type)
    {
      case CDOUBLETYPE:
      case CINTTYPE:
      case CDATETYPE:
	return risnull(r->type, (char *) &(r->val.real));
      default:
	return risnull(r->type, r->val.string);
    }
}

/*
** assigns null int value to stack entry
*/
static void fgw_setnull(r)
exprstack_t *r;
{
    
    r->type=CINTTYPE;
    rsetnull(CINTTYPE, (char *) &(r->val.intvalue));
}

/*
** does datetime interval addition
*/
static void dtaddinv_sqp(r1, r2, rs)
exprstack_t *r1, *r2, *rs;
{
    int n1, n2;
    dtime_t *dp1, dt1, dte;
    intrvl_t *ip1, in1;

    dp1=fgw_todtime(r1, &dt1, -1, &n1);
    ip1=fgw_toinv(r2, &in1, -1, &n2);
/*
**  need to extend the resulting datetime
*/
    dte.dt_qual=fgw_qualifier(dp1->dt_qual, ip1->in_qual);
    status=dtextend(dp1, &dte);
    if (!(rs->val.datetime=(dtime_t *)
	fgw_smalloc(sizeof(dtime_t))))
	status=-208;
    else
    {
	rs->type=CDTIMETYPE;
	if (n1||n2)
	    rsetnull(CDTIMETYPE, (char *) rs->val.datetime);
	else
	    status=dtaddinv(&dte, ip1, rs->val.datetime);
    }
}

/*
** does datetime interval subtraction
*/
static void dtsubinv_sqp(r1, r2, rs)
exprstack_t *r1, *r2, *rs;
{
    int n1, n2;
    dtime_t *dp1, dt1, dte;
    intrvl_t *ip1, in1;

    dp1=fgw_todtime(r1, &dt1, -1, &n1);
    ip1=fgw_toinv(r2, &in1, -1, &n2);
/*
**  need to extend the resulting datetime
*/
    dte.dt_qual=fgw_qualifier(dp1->dt_qual, ip1->in_qual);
    status=dtextend(dp1, &dte);
    if (!(rs->val.datetime=(dtime_t *)
	fgw_smalloc(sizeof(dtime_t))))
	status=-208;
    else
    {
	rs->type=CDTIMETYPE;
	if (n1||n2)
	    rsetnull(CDTIMETYPE, (char *) rs->val.datetime);
	else
	    status=dtsubinv(&dte, ip1, rs->val.datetime);
    }
}

/*
** does datetime datetime subtraction
*/
static void dtsub_sqp(r1, r2, rs)
exprstack_t *r1, *r2, *rs;
{
    int n1, n2;
    dtime_t *dp1, *dp2, dt1, dt2;

    dp1=fgw_todtime(r1, &dt1, -1, &n1);
    dp2=fgw_todtime(r2, &dt2, -1, &n2);
    if (!(rs->val.interval=(intrvl_t *)
	fgw_smalloc(sizeof(intrvl_t))))
	status=-208;
    else
    {
	rs->type=CINVTYPE;
/*
**  need to initialize the resulting interval qualifier
**  FIXME: as there's no way in the syntax to specify the class, we will use
**  day to ...
*/
	rs->val.interval->in_qual=fgw_qualifier(dp1->dt_qual, dp2->dt_qual);
	if (TU_START(rs->val.interval->in_qual)<TU_DAY)
	    rs->val.interval->in_qual=TU_IENCODE(5, TU_DAY,
					TU_END(rs->val.interval->in_qual));
	if (n1||n2)
	    rsetnull(CINVTYPE, (char *) rs->val.interval);
	else
	    status=dtsub(dp1, dp2, rs->val.interval);
    }
}

/*
**  prepares for interval addition/subtraction
*/
static int inaddsub_sqp(i1, i2, oi1, oi2, or)
exprstack_t *i1, *i2;
intrvl_t *oi1, *oi2;
exprstack_t *or;
{
    int n1, n2, q;
    intrvl_t *ip1, *ip2, in1, in2;

    ip1=fgw_toinv(i1, &in1, -1, &n1);
    ip2=fgw_toinv(i2, &in2, -1, &n2);
    or->type=CINVTYPE;
    if (!(or->val.interval=(intrvl_t *) fgw_smalloc(sizeof(intrvl_t))))
    {
	status=-208;
	return 0;
    }
    if (n1||n2)
    {
	rsetnull(CINVTYPE, (char *) or->val.interval);
	return 0;
    }
    else
    {
	oi1->in_qual=fgw_qualifier(ip1->in_qual, ip2->in_qual);
	oi2->in_qual=oi1->in_qual;
	if (status=invextend(ip1, oi1))
	   return 0;
	status=invextend(ip2, oi2);
	return !status;
    }
}

/*
** assigns int value to stack entry
*/
static void fgw_setint(r, v)
exprstack_t *r;
int v;
{
    
    r->type=CINTTYPE;
    if (nullind)
	rsetnull(CINTTYPE, (char *) &(r->val.intvalue));
    else
	r->val.intvalue=v;
}

/*
** assigns double value to stack entry
*/
static void fgw_setdouble(r, v)
exprstack_t *r;
double v;
{
    
    r->type=CDOUBLETYPE;
    if (nullind)
	rsetnull(CDOUBLETYPE, (char *) &(r->val.real));
    else
	r->val.real=v;
}

/*
** allocates temporary memory
*/
static char *fgw_smalloc(s)
int s;
{
    return fgw_tssmalloc(&pstate->tsshead, s);
}

/*
** frees temporary memory
*/
static void fgw_sfree(str)
char *str;
{
    fgw_tssfree(&pstate->tsshead, str);
}

/*
** frees temporary memory on stack
*/
static void fgw_freetssstack(r1)
exprstack_t *r1;
{
    if ((r1->type==CSTRINGTYPE ||
	 r1->type==CINVTYPE ||
	 r1->type==CDTIMETYPE) && r1->val.string)
	fgw_tssfree(&pstate->tsshead, r1->val.string);
}

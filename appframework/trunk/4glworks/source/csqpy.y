%{
/*
	CSQPY.y  -  Sql interpreter parser and scanner

	The 4glWorks application framework
	Copyright (C) 1992-2002 Marco Greco (marco@4glworks.com)

	Initial release: Mar 00
	Current release: Sep 02

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
#include "cfioc.h"
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
extern fgw_fdesc *sql_openfile();
extern int status;

#define NUMTOKENS 119
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
static int prevtoken=-1;

/*
** html styles
*/
#define F_none          0
#define F_pre           1
#define F_table         2
 
/*
** stack memory (dis)allocation
*/
#define fgw_smalloc(s) fgw_tssmalloc(&pstate->exphead, s)
#define fgw_sfree(str) fgw_tssfree(&pstate->exphead, str)

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
static exprstack_t *arglist_sqp();
static void pushresult_sqp();
static void fgw_freetssstack();
static void fgw_assign();
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
%}

%union {
char		*var;		/* variables */
tokenlist_t	*func;		/* functions */
exprstack_t	stack;		/* expression result */
char 		*token;		/* token start in source - for sql hacks */
fgw_fdesc	*fd;		/* output statements */
}

%type <fd>	output, append
%type <stack>	fnproc, breaks, exitcl, format1, ftype, fspec
%type <stack>	nullcl, unitcl
%type <stack>	betweencl, mrexcl, lrexcl

%nonassoc FOR FOREACH WHILE IF ELIF ELSE FI DONE CONTINUE BREAK EXIT
%nonassoc DISPLAY LET LOAD UNLOAD WHENEVER PIPE APPEND OUTPUT
%nonassoc SELECT INSERT DELETE UPDATE EXECUTE CREATE END
%nonassoc SQLTOK PROCEDURE FUNCTION
%nonassoc ERROR STOP DEFAULT
%nonassoc IN INTO USING FORMAT FROM TO DELIMITER
%nonassoc BRIEF VERTICAL FULL HEADERS
%nonassoc TEMP SCRATCH EXTERNAL
%nonassoc CASE WHEN THEN IS NULLVALUE
%nonassoc BETWEEN MATCHES LIKE ESCAPE
%nonassoc YEAR MONTH DAY HOUR MINUTE SECOND FRACTION

%right ASSIGN

%token <stack>	CNST
%token <token>	SELECT EXECUTE INTO USING FORMAT
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
			    YYACCEPT;
			}
	|   {
		if (pstate->parseroptions & EXPRONLY)
		    YYFAIL;
	    }
	  stmt
;
/*
** technically, we support nested stored procedures, even if the engine does not
*/
stmt:	  END fnproc	{
			    controlstack_t *c;
			
			    if (!pstate->control.count)
				YYFAIL;
			    c=(controlstack_t *) fgw_stackpeek(&pstate->control);
			    if (c->stmt_type!=$2.type)
				YYFAIL;
			    if (c->state==S_INPROC)
			    {
				fgw_stmttype *s;
				int r;

				if (!(s=sql_newstatement()))
				    FAIL(-208)
				r=sql_run(c->proc_start, s, pstate->touch);
				sql_freestatement(s);
				if (!status)
				    status=r;
				if (!risnull(CINTTYPE, (char *) &status))
				    if (pstate->error_cont)
					status=0;
				    else
					FAILCHECK
			    }
			    fgw_stackdrop(&pstate->control, 1);
			}
	| CREATE fnproc	{
			    controlstack_t c;

			    byfill(&c, sizeof(c), 0);
			    c.stmt_type=$2.type;
			    if (pstate->control.count)
				switch (((controlstack_t *)
				    fgw_stackpeek(&pstate->control))->state)
				{
				  case S_ACTIVE:
				    c.state=S_INPROC;
				    break;
				  case S_NESTED:
				  case S_INPROC:
				    c.state=S_NESTED;
				    break;
				  default:
				    c.state=S_DISPROC;
				}
			    else
				c.state=S_INPROC;
			    c.proc_start=pstate->sqlstart;
			    fgw_stackpush(&pstate->control, &c);
			    YYACCEPT
			}
	| {
	    int s;

	    s=pstate->control.count? ((controlstack_t *)
		fgw_stackpeek(&pstate->control))->state: S_ACTIVE;
	    if (s==S_INPROC || s==S_DISPROC || s==S_NESTED)
		YYACCEPT;
	  } stmt1
;
fnproc:	  FUNCTION	{
			    $$.type=FUNCTION;
			}
	| PROCEDURE	{
			    $$.type=PROCEDURE;
			}
;
stmt1:	  {
/*
** if we don't have to do anything, we don't parse, just accept
*/
	    if (pstate->control.count &&
		((controlstack_t *) fgw_stackpeek(&pstate->control))->state<S_ACTIVE)
	    {
		controlstack_t c;

		byfill(&c, sizeof(c), 0);
		c.stmt_type=yychar;
		c.state=S_DISABLED;
		fgw_stackpush(&pstate->control, &c);
		YYACCEPT;
	    }
	  } ctrl
	| DONE		{
			    controlstack_t *c;
			    exprstack_t *e;

			    if (!pstate->control.count)
				YYFAIL;
			    c=(controlstack_t *) fgw_stackpeek(&pstate->control);
			    switch(c->stmt_type)
			    {
			      case FOR:
				if (c->state!=S_DISABLED &&
				    c->element)
				{
				    c->element--;
				    e=(exprstack_t *)
					fgw_stackpeek(&pstate->exprlist)-
					    c->element;
				    fgw_assign(e, c->destvar);
				    fgw_freetssstack(e);
				    c->state=S_ACTIVE;
				    pstate->phase1=c->phase1;
				}
				else
				{
				    if (c->destvar)
					fgw_sfree(c->destvar);
				    if (c->forcount)
				    {
					e=(exprstack_t *)
					    fgw_stackpeek(&pstate->exprlist)-
						c->element;
					while (c->element--)
					    fgw_freetssstack(++e);
					fgw_stackdrop(&pstate->exprlist,
							c->forcount);
				    }
				    fgw_stackdrop(&pstate->control, 1);
				}
				break;
			      case FOREACH:
				curstmt=c->stmt;
				if (c->state!=S_DISABLED)
				{
				    c->state=S_ACTIVE;
				    sql_dorows(curstmt, pstate->txtvar,
						pstate->vars, 0);
				    if (status==SQLNOTFOUND)
				    {
					status=0;
					c->state=S_DISABLED;
				    }
				    else if (!risnull(CINTTYPE, (char *) &status))
					if (pstate->error_cont)
					    status=0;
					else
					    FAILCHECK
				}
				if (c->state==S_DISABLED)
				{
				    if (curstmt)
					sql_freestatement(curstmt);
				    fgw_stackdrop(&pstate->control, 1);
				}
				else
				    pstate->phase1=c->phase1;
				curstmt=NULL;
				break;
			      case WHILE:
				if (c->state!=S_DISABLED)
				{
				    c->nextphase1=pstate->phase1;
				    pstate->phase1=c->phase1;
				    c->state=S_WHILE;
				}
				else
				    fgw_stackdrop(&pstate->control, 1);
				break;
			      default:
				YYFAIL;
			    }
			}
	| ELIF		{
			    controlstack_t *c;

			    if (!pstate->control.count)
				YYFAIL;
			    c=(controlstack_t *) fgw_stackpeek(&pstate->control);
			    if (c->stmt_type!=IF)
				YYFAIL;
			    if (c->state!=S_IF)
			    {
				c->state=S_DISABLED;
				YYACCEPT;
			    }
			} allexp {
			    controlstack_t *c;
			    exprstack_t *s;
			    int r, n;
 
			    c=(controlstack_t *) fgw_stackpeek(&pstate->control);
			    s=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
			    r=fgw_toboolean(s, &n);
			    fgw_freetssstack(s);
			    if (n || !r)
				c->state=S_IF;
			    else
				c->state=S_ACTIVE;
			}
	| ELSE		{
			    controlstack_t *c;

			    if (!pstate->control.count)
				YYFAIL;
			    c=(controlstack_t *) fgw_stackpeek(&pstate->control);
			    if (c->stmt_type!=IF)
				YYFAIL;
			    if (c->state==S_IF)
				c->state=S_ACTIVE;
			    else
				c->state=S_DISABLED;
			}
	| FI		{
			    controlstack_t *c;

			    if (!pstate->control.count)
				YYFAIL;
			    c=(controlstack_t *) fgw_stackpeek(&pstate->control);
			    if (c->stmt_type!=IF)
				YYFAIL;
			    fgw_stackdrop(&pstate->control, 1);
			}
	| { 
	    if (pstate->control.count &&
		((controlstack_t *) fgw_stackpeek(&pstate->control))->state!=
		  S_ACTIVE)
		YYACCEPT;
	  } plain

;
ctrl:	  FOR VAR IN elist	{
			    controlstack_t c;
			    exprstack_t *e;

			    byfill(&c, sizeof(c), 0);
			    c.stmt_type=FOR;
			    e=arglist_sqp(&pstate->exprlist, &c.forcount);
			    c.element=c.forcount-1;
			    fgw_tssdetach(&pstate->lexhead, $2);
			    fgw_tssattach(&pstate->exphead, $2);
			    c.destvar=$2;
			    c.state=S_ACTIVE;
			    c.phase1=pstate->phase1;
			    fgw_assign(e, c.destvar);
			    fgw_freetssstack(e);
			    fgw_stackpush(&pstate->control, &c);
			}
	| FOREACH	{
			    if (!(curstmt=sql_newstatement()))
				FAIL(-208)
			} select using into format {
			    int r;
			    controlstack_t c;

			    byfill(&c, sizeof(c), 0);
			    c.stmt_type=FOREACH;
			    c.state=S_ACTIVE;
			    c.phase1=pstate->phase1;
			    c.stmt=curstmt;
			    pstate->sqlsv=*pstate->sqlend;
			    *pstate->sqlend='\0';
			    if (!(r=sql_run(pstate->sqlstart, curstmt,
					    pstate->touch)))
			    {
				sql_dorows(curstmt, pstate->txtvar, pstate->vars,
					   0);
				if (status==SQLNOTFOUND)
				{
				    status=0;
				    c.state=S_DISABLED;
				}
			    }
			    curstmt=NULL;
			    if (!status)
				status=r;
			    if (!risnull(CINTTYPE, (char *) &status))
				if (pstate->error_cont)
				    status=0;
				else
				    FAILCHECK
			    fgw_stackpush(&pstate->control, &c);
			}
	| WHILE allexp	{
			    controlstack_t c, *oc;
			    exprstack_t *s;
			    int r, n;

			    s=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
			    r=fgw_toboolean(s, &n);
			    fgw_freetssstack(s);
			    if (pstate->control.count)
			    {
			        oc=(controlstack_t *)
					fgw_stackpeek(&pstate->control);
				if (oc->state==S_WHILE)
				{
				    if (n || !r)
					if (pstate->inside_expansion)
					    oc->state=S_DISABLED;
					else
					{
					    pstate->phase1=oc->nextphase1;
					    fgw_stackdrop(&pstate->control, 1);
					}
				    else
					oc->state=S_ACTIVE;
				    goto done_while;
				}
			    }
			    byfill(&c, sizeof(c), 0);
			    c.stmt_type=WHILE;
			    if (n || !r)
				c.state=S_DISABLED;
			    else
				c.state=S_ACTIVE;
			    c.phase1=pstate->prevphase1;
			    fgw_stackpush(&pstate->control, &c);
done_while:
			}
	| IF allexp	{
			    controlstack_t c;
			    exprstack_t *s;
			    int r, n;

			    s=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
			    r=fgw_toboolean(s, &n);
			    fgw_freetssstack(s);
			    byfill(&c, sizeof(c), 0);
			    c.stmt_type=IF;
			    if (n || !r)
				c.state=S_IF;
			    else
				c.state=S_ACTIVE;
			    fgw_stackpush(&pstate->control, &c);
			}
;
plain:	  breaks	{
			    controlstack_t *c;
			    int i;

			    i=pstate->control.count;
			    c=(controlstack_t *) fgw_stackpeek(&pstate->control);
			    while (i && c->stmt_type==IF)
			    {
				i--;
				c->state=S_DISABLED;
				c--;
			    }
			    if (!i)
				YYFAIL;
			    if ($1.type==BREAK)
				c->state=S_DISABLED;
			    else
				c->state=S_CONTINUE;
			}
	| display
	| assign
	| output	{
/*
** if it is a pipe, see if we can write to it, or child has gone away
*/
			    if (!status && $<fd>1 &&
				$<fd>1!=(fgw_fdesc *) -1 && $<fd>1->fd_pid)
			    {
/*
** give the child shell the time to exec the correct image
** FIXME - older SYSV might not know about usleep
*/
			        (void) usleep(100000);
			        fgw_fdwrite($<fd>1, "", 0);
			        if (status)
				{
				    errcode=status;
				    childstatus=fgw_fdclose($<fd>1);
				}
			    }
			    if (!status)
			    {
				if (pstate->curr_fd &&
				    pstate->curr_fd!=(fgw_fdesc *) -1)
				{
				    sql_flush(pstate->txtvar, 1);
/* FIXME: close flag */
				    if (pstate->curr_fd!=pstate->def_fd)
				    {
					childstatus=fgw_fdclose(pstate->curr_fd);
					errcode=status;
				    }
				}
			    }
			    if (!status)
			    {
				sql_openfile(pstate->txtvar, $<fd>1);
				pstate->curr_fd=$<fd>1;
			    }
			    else
				status=0;
			}
        | sql
	| WHENEVER ERROR errcl
	| LOAD FROM exp del	{
			    exprstack_t f, d;

			    d=*(exprstack_t *) fgw_stackpop(&pstate->exprlist);
			    f=*(exprstack_t *) fgw_stackpop(&pstate->exprlist);
			    fgw_2string(&f, &d);
/* FIXME: using 4gl internals */
			    _ffload(sholder1,  sholder2,  pstate->tokstart);
			    fgw_freetssstack(&f);
			    fgw_freetssstack(&d);
			    status=sqlca.sqlcode;
			    FAILCHECK
			    rsetnull(CINTTYPE, (char *) &status);
			    YYACCEPT
			}
	| UNLOAD TO exp del	{
			    exprstack_t *f, *d;

			    d=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
			    f=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
			    fgw_2string(f, d);
/* FIXME: using 4gl internals */
			    _ffunload(sholder1, sholder2, pstate->tokstart,
				      0, (struct sqlvar_struct *)0);
			    fgw_freetssstack(f);
			    fgw_freetssstack(d);
			    status=sqlca.sqlcode;
			    FAILCHECK
			    rsetnull(CINTTYPE, (char *) &status);
			    YYACCEPT
			}
	| EXIT exitcl	{
			    if (is_child)
			    {
				if (pstate->curr_fd &&
				    pstate->curr_fd!=(fgw_fdesc *)-1)
				{
				    sql_flush(pstate->txtvar, 1);
				    if (pstate->curr_fd!=pstate->def_fd)
					fgw_fdclose(pstate->curr_fd);
				}
				exit($2.type);
			    }
			    else
			    {
/*
** this is a dirty hack, but it causes the external layer to stop
*/
				pstate->i_size=0;
				pstate->o_size=0;
			    }
			}
	| /* empty */
;
breaks:	  BREAK			{
				    $$.type=BREAK;
				}
	| CONTINUE		{
				    $$.type=CONTINUE;
				}
;
output:	  APPEND TO append	{
				    $$=$3;
				}
	| OUTPUT TO exp	{
			    exprstack_t *s;
			    char cbuf[STRINGCONVSIZE];

			    s=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
			    $<fd>$=fgw_fileopen(fgw_tostring(s, &cbuf, NULL), "w");
			    fgw_freetssstack(s);
			}
	| PIPE TO exp	{
			    exprstack_t *s;
			    char cbuf[STRINGCONVSIZE];

			    s=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
			    $<fd>$=fgw_pipeopen(fgw_tostring(s, &cbuf, NULL), "w");
			    fgw_freetssstack(s);
			}
;
append:	  DEFAULT	{
			    $<fd>$=pstate->def_fd;
			}
	| exp		{
			    exprstack_t *s;
			    char cbuf[STRINGCONVSIZE];

			    s=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
			    $<fd>$=fgw_fileopen(fgw_tostring(s, &cbuf, NULL), "a");
			    fgw_freetssstack(s);
			}
;
errcl:	  CONTINUE	{
			    pstate->error_cont=1;
			}
	| STOP		{
			    pstate->error_cont=0;
			}
;
del:	  DELIMITER exp
	| /* empty */	{
			    exprstack_t s;

			    s.type=FGWVAR;
			    s.val.string="|";
			    fgw_stackpush(&pstate->exprlist, &s);
			}
;
exitcl:	  /* empty */	{
			    $$.type=0;
			}
	| exp		{
			    if (is_child)
			    {
				exprstack_t *e;
				int r, n;

				e=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
				r=fgw_toint(e, &n);
				fgw_freetssstack(e);
				if (n || r<0 || r>127)
				{
				    status=-385;
				    YYFAIL;
				}
				$$.type=r;
			    }
			    else
				YYFAIL;
			}
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
			    s=arglist_sqp(&pstate->exprlist, &c);
			    for (i=0; i<c; i++, s++)
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
			    exprstack_t *s;

			    s=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
			    fgw_assign(s, $2);
			    fgw_tssfree(&pstate->lexhead, $2);
			    fgw_freetssstack(s);
			}
	| LET VAR rangecl '=' allexp %prec ASSIGN	{
			    exprstack_t *r, *s1, s2;
			    int vl, el, ol, n1, n2, sp;
			    char *e, ebuf[STRINGCONVSIZE];
			    char *v, *t, vbuf[STRINGCONVSIZE];

			    s1=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
			    r=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
/* FIXME: this could be optimized */
			    fgw_cvvar(&s2, fgw_hstget(pstate->vars, $<var>2));
			    v=fgw_tostring(&s2, &vbuf, &n1);
			    vl=stleng(v);
			    if (!(t=fgw_smalloc(ol=r->val.range[1]-
						  r->val.range[0]+1)))
				FAIL(-208)
			    stcopy(v, t);
			    e=fgw_tostring(s1, &ebuf, &n2);
			    if ((el=stleng(e))>ol)
				el=ol;
			    bycopy(e, t+r->val.range[0], el);
/*
** fill with spaces as appropriate
*/
			    if (r->val.range[0]>vl)
				byfill(t+vl, r->val.range[0]-vl, ' ');
			    if ((sp=r->val.range[0]+el)<=r->val.range[1])
				byfill(t+sp, r->val.range[1]-sp+1, ' ');
/*
** zero terminate if appropriate
*/
			    if (r->val.range[1]>=vl)
			        *(t+r->val.range[1]+1)='\0';
			    fgw_hstadd(pstate->vars, $2, CSTRINGTYPE, t);
			    fgw_sfree(t);
			    fgw_tssfree(&pstate->lexhead, $2);
			    fgw_freetssstack(s1);
			}
;
/*
** what we don't understand from the first token, we just pass to the engine
*/
sql:	    {
		 if (!(curstmt=sql_newstatement()))
		    FAIL(-208)
	    } sql1	{
			    if (!risnull(CINTTYPE, (char *) &status))
				if (pstate->error_cont)
				    status=0;
				else
				    FAILCHECK
			    YYACCEPT
			}
;
/*
** be warned: actions require that format follows into
*/
sql1:	   select using into format	{
			    int r;

			    pstate->sqlsv=*pstate->sqlend;
			    *pstate->sqlend='\0';
			    if (!(r=sql_run(pstate->sqlstart, curstmt,
					    pstate->touch)))
				sql_dorows(curstmt, pstate->txtvar, pstate->vars,
					   !curstmt->intovars);
			    sql_freestatement(curstmt);
			    curstmt=NULL;
			    if (!status)
				status=r;
			}
	 | squsing	{
			    int r;
 
			    pstate->sqlsv=*pstate->sqlend;
			    *pstate->sqlend='\0';
			    r=sql_run(pstate->sqlstart, curstmt, pstate->touch);
			    sql_freestatement(curstmt);
			    curstmt=NULL;
			    if (!status)
				status=r;
			}
	 | SQLTOK	{
			    int r;
 
			    r=sql_run(pstate->sqlstart, curstmt, pstate->touch);
			    sql_freestatement(curstmt);
			    curstmt=NULL;
			    if (!status)
				status=r;
			}
;
select:	  SELECT	{}
	| EXECUTE	{}
;
squsing:  dml using	{}
	| SELECT SQLTOK using	{}
;
dml:	  INSERT	{}
	| UPDATE	{}
	| DELETE	{}
;
into:	  /* empty */
	| INTO vlist	{
			    if ($<token>1<pstate->sqlend)
				pstate->sqlend=$<token>1;
			}
;
vlist:	  vlist ',' VAR {
			    fgw_tssdetach(&pstate->lexhead, $3);
			    fgw_tssattach(&curstmt->intovars, $3);
			}
	| VAR		{
			    fgw_tssdetach(&pstate->lexhead, $1);
			    fgw_tssattach(&curstmt->intovars, $1);
			}
;
using:	  /* empty */
	| USING ulist	{
			    if ($<token>1<pstate->sqlend)
				pstate->sqlend=$<token>1;
			}
;
ulist:	  ulist ',' VAR	{
			    sql_setholder(curstmt, pstate->vars, $3);
			    fgw_tssfree(&pstate->lexhead, $<var>1);
			}
	| VAR		{
			    sql_setholder(curstmt, pstate->vars, $1);
			    fgw_tssfree(&pstate->lexhead, $<var>1);
			}
;
format:	  format1	{
			    if (curstmt->fmt_type!=FMT_NULL)
				pstate->done_display=1;
			}
;
format1:  /* empty */	{
/*
** turn off output if INTO clause and no explicit FORMAT clause
*/
			    curstmt->fmt_type=(curstmt->intovars? FMT_NULL:
/*
** default format is BRIEF
*/
				(pstate->html? FMT_FULL: FMT_BRIEF));
			    curstmt->width=pstate->width;
			    $$.type=1;
			}
	| FORMAT ftype	{
			    char cbuf[STRINGCONVSIZE];

			    if ($<token>1<pstate->sqlend)
				pstate->sqlend=$<token>1;
			    curstmt->width=pstate->width;
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
/*
** no BRIEF format in html mode - we just use FULL with no format specifier
** or headers
*/
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
	| allexp	{
			    $$=*(exprstack_t *) fgw_stackpop(&pstate->exprlist);
			}
;
headers:  /* empty */
	| HEADERS hlist
;
hlist:	  hlist ',' allexp 	{
				    exprstack_t *s;
				    char cbuf[STRINGCONVSIZE];

				    s=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
				    sql_setheader(curstmt, fgw_tostring(s,
								&cbuf, NULL));
/*				    fgw_freetssstack(s);
*/
				}
	| allexp	{
			    exprstack_t *s;
			    char cbuf[STRINGCONVSIZE];

			    s=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
			    sql_setheader(curstmt, fgw_tostring(s, &cbuf, NULL));
/*			    fgw_freetssstack(s);
*/
			}
;
/*
** had a single exp rule, but the BETWEEN and ESCAPE clauses would result
** in 40 s/r & 7 r/r conflicts. This grammar is less powerful, but cleaner
*/
allexp:	  boolexp
	| exp
;
exp:	  CNST			{
				    $1.count=0;
				    if ($1.type==CSTRINGTYPE)
				    {
					fgw_tssdetach(&pstate->lexhead,
						      $1.val.string);
					fgw_tssattach(&pstate->exphead,
						      $1.val.string);
				    }
				    fgw_stackpush(&pstate->exprlist, &($1));
				}
	| NULLVALUE		{
				    exprstack_t n;

				    fgw_setnull(&n);
				    n.count=0;
				    fgw_stackpush(&pstate->exprlist, &n);
				}
	| VAR			{
				    exprstack_t v;
				    fgw_cvvar(&v, fgw_hstget(pstate->vars, $1));
				    FAILCHECK
				    v.count=0;
				    fgw_stackpush(&pstate->exprlist, &v);
				    fgw_tssfree(&pstate->lexhead, $1);
				}
/* FIXME: index, replace, pads & substrings use byte (as opposed to char)
   starts & ends/lengths. they should be ok as far as GLS goes, but this 
   needs to be checked */
	| VAR rangecl		{
				    exprstack_t v, e, *r;
				    int l, n1;
				    char *c, sbuf[STRINGCONVSIZE];

				    r=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
				    fgw_cvvar(&v, fgw_hstget(pstate->vars,
							     $<var>1));
				    c=fgw_tostring(&v, &sbuf, &n1);
				    e.type=CSTRINGTYPE;
				    if (!(e.val.string=
					   fgw_smalloc(l=r->val.range[1]-
							 r->val.range[0]+1)))
					FAIL(-208)
				    if (r->val.range[0]>stleng(c) || n1)
					rsetnull(CSTRINGTYPE, e.val.string);
				    else
				    {
					bycopy(c+r->val.range[0],
					       e.val.string, l);
					*(e.val.string+l)='\0';
				    }
				    e.count=0;
				    fgw_stackpush(&pstate->exprlist, &e);
				    fgw_tssfree(&pstate->lexhead, $1);
				}
	| CASE casecl elsecl END	{
				    exprstack_t *e, *w;

				    e=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
				    w=(exprstack_t *) fgw_stackpeek(&pstate->exprlist);
				    if (w->type==ELSE)
				    {
					fgw_stackdrop(&pstate->exprlist, 1);
					fgw_freetssstack(w);
					fgw_stackpush(&pstate->exprlist, e);
				    }
				    else
					fgw_freetssstack(e);
				}
	| CASE exp lcasecl elsecl END	{
				    exprstack_t *a, *e, *s1, *s2, r;
				    int i, c;

				    e=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
				    s1=arglist_sqp(&pstate->exprlist, &c);
				    s2=s1;
				    a=s1-1;
				    r=*e;
				    if (!fgw_isnull(a))
				    {
					for (i=0; i<c; i+=2, s1+=2)
					{
					    int t;

					    t=fgw_compare(a->type, a, s1);
					    if (!nullind && !t)
					    {
						r=*++s1;
						fgw_freetssstack(e);
						s1->type=CINTTYPE;
						break;
					    }
					}
				    }
				    for (i=0; i<c; i++, s2++)
					fgw_freetssstack(s2);
				    fgw_freetssstack(a);
				    fgw_stackdrop(&pstate->exprlist, c+1);
				    r.count=0;
				    fgw_stackpush(&pstate->exprlist, &r);
				}
	| FNCT 			{
				    if ($1->parms)
					FAIL(-664)
				    (*($1->func))(&pstate->exprlist);
				    FAILCHECK
				}
	| FNCT '(' elist ')'	{
				    exprstack_t *s;

				    s=(exprstack_t *) fgw_stackpeek(&pstate->exprlist);
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
					if (s->count!=$1->parms)
					    FAIL(-664)
				    }
/*
** call func & abort if error
*/
				    (*($1->func))(&pstate->exprlist);
				    FAILCHECK
				}
	| FNDN { pstate->parseroptions|=QUALIFIERHACK; } qualcl {
				    pstate->parseroptions&=~QUALIFIERHACK;
				    if ($1->parms)
					FAIL(-664)
				    (*($1->func))(&pstate->exprlist);
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
	| FNDP '(' elist ')' { pstate->parseroptions|=QUALIFIERHACK; } qualcl	{
				    exprstack_t *s;

				    s=(exprstack_t *) fgw_stackpeek(&pstate->exprlist)-1;
				    pstate->parseroptions&=~QUALIFIERHACK;
				    switch ($1->parms)
				    {
				      case 0:
					FAIL(-664)
				      case -1:
					break;
				      default:
					if (s->count!=$1->parms)
					    FAIL(-664)
				    }
				    (*($1->func))(&pstate->exprlist);
				    FAILCHECK
				}
	| exp DPIPE exp		{
				    exprstack_t *o1, *o2, r;

				    o2=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
				    o1=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
				    fgw_2string(o1, o2);
/*
** allocate memory - if none available, nullify result (dirty hack)
*/
				    r.val.string=(char *) fgw_smalloc(
							strlen(sholder1)+
							strlen(sholder2));
				    if (!(r.val.string))
					fgw_setnull(&r);
				    else
				    {
					r.type=CSTRINGTYPE;
					stcopy(sholder1, r.val.string);
					stcat(sholder2, r.val.string);
				    }
				    fgw_freetssstack(o1);
				    fgw_freetssstack(o2);
				    r.count=0;
				    fgw_stackpush(&pstate->exprlist, &r);
				}
	| exp USING exp		{
				    char *f;
				    exprstack_t *o1, *o2, r;

				    o2=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
				    o1=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
				    if (!(f=fgw_smalloc(64)))
					FAIL(-208)
				    else
				    {
					switch(o1->type)
					{
					  case CDECIMALTYPE:
					  case CMONEYTYPE:
					    status=rfmtdec(o1->val.decimal,
							 o2->val.string, f);
					    break;
					  case CDOUBLETYPE:
					    status=rfmtdouble(o1->val.real,
							 o2->val.string, f);
					    break;
					  case CDATETYPE:
					    status=rfmtdate(o1->val.intvalue,
							 o2->val.string, f);
					    break;
#ifdef HAS_DTFMT
					  case CDTIMETYPE:
					    status=dttofmtasc(o1->val.datetime,
					                 f, 64, o2->val.string);
					    break;
					  case CINVTYPE:
					    status=intofmtasc(o1->val.interval,
					                 f, 64, o2->val.string);
					    break;
#endif 
					  case CINTTYPE:
					    status=rfmtlong(o1->val.intvalue,
							 o2->val.string, f);
					    break;
					  default:
					    stcopy(o2->val.string, f);
					}
					FAILCHECK
					r.type=CSTRINGTYPE;
					r.val.string=f;
				    }
				    fgw_freetssstack(o1);
				    fgw_freetssstack(o2);
				    r.count=0;
				    fgw_stackpush(&pstate->exprlist, &r);
				}
/* $%^&! 8 s/r conflicts from this one */
	| exp PFIXFNCT		{
				    exprstack_t *t;

				    t=(exprstack_t *) fgw_stackpeek(&pstate->exprlist);
				    t->count=1;
				    (*($2->func))(&pstate->exprlist);
				    FAILCHECK
				}
	| exp '+' exp		{
				    exprstack_t *l, *r;
				    exprstack_t *o1, *o2, d;
				    intrvl_t in1, in2;

				    o2=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
				    o1=(exprstack_t *) fgw_stackpop(&pstate->exprlist);

				    switch (d.type=fgw_optype(o1, o2,
							       &l, &r))
				    {
				      case CDTIMETYPE:
					dtaddinv_sqp(l, r, &d);
					break;
				      case CDATETYPE:
					if (fgw_isnull(l)||fgw_isnull(r))
					    rsetnull(CDATETYPE,
						(char *) &(d.val.intvalue));
					else switch (r->type)
					{
					  case CINTTYPE:
					  case CDOUBLETYPE:
					    d.type=CDATETYPE;
					    d.val.intvalue=l->val.intvalue+
						fgw_toint(r, NULL);
					    break;
					  default:
					    dtaddinv_sqp(l, r, &d);
					}
					break;
				      case CINVTYPE:
					if (inaddsub_sqp(o1, o2,
							 &in1, &in2, &d))
					    status=inadd(&in1, &in2,
							 d.val.interval);
					break;
				      case CDECIMALTYPE:
				      case CMONEYTYPE:
					if (fgw_2decimal(o1, o2, &d))
					    status=decadd(dholder1, dholder2,
							  d.val.decimal);
					break;
				      case CDOUBLETYPE:
				      case CSTRINGTYPE:
					fgw_2double(o1, o2);
					fgw_setdouble(&d, fholder1+fholder2);
					break;
				      case CINTTYPE:
					fgw_2int(o1, o2);
					fgw_setint(&d, iholder1+iholder2);
					break;
				      default:
					fgw_setnull(&d);
				    }
				    FAILCHECK
				    fgw_freetssstack(o1);
				    fgw_freetssstack(o2);
				    d.count=0;
				    fgw_stackpush(&pstate->exprlist, &d);
				}
	| exp '-' exp		{
				    int d;
				    intrvl_t in1, in2;
				    exprstack_t *o1, *o2, r;

				    o2=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
				    o1=(exprstack_t *) fgw_stackpop(&pstate->exprlist);

				    if (o1->type==CDTIMETYPE)
				    {
					if (o2->type==CINVTYPE)
					    dtsubinv_sqp(o1, o2, &r);
					else
					    dtsub_sqp(o1, o2, &r);
				    }
				    else if (o1->type==CDATETYPE)
				    {
					if (fgw_isnull(o1)||fgw_isnull(o2))
					    rsetnull(CDATETYPE,
						(char *) &(r.val.intvalue));
					else switch (o2->type)
					{
					  case CINTTYPE:
					  case CDOUBLETYPE:
					    r.type=CDATETYPE;
					    r.val.intvalue=o1->val.intvalue-
						fgw_toint(o2, NULL);
					    break;
					  case CINVTYPE:
					    dtsubinv_sqp(o1, o2, &r);
					    break;
					  case CDTIMETYPE:
					    dtsub_sqp(o1, o2, &r);
					    break;
					  default:
					    d=fgw_todate(o2, NULL);
					    r.type=CINTTYPE;
					    r.val.intvalue=o1->val.intvalue-d;
					}
				    }
				    else if (o1->type==CINVTYPE)
				    {
					if (inaddsub_sqp(o1, o2,
							 &in1, &in2, &r))
					    status=insub(&in1, &in2,
							 r.val.interval);
				    }
				    else switch (r.type=fgw_exprtype(o1->type,
								     o2->type))
				    {
				      case CDECIMALTYPE:
				      case CMONEYTYPE:
					if (fgw_2decimal(o1, o2, &r))
					    status=decadd(dholder1, dholder2,
							  r.val.decimal);
					break;
				      case CSTRINGTYPE:
				      case CDOUBLETYPE:
					fgw_2double(o1, o2);
					fgw_setdouble(&r, fholder1-fholder2);
					break;
				      case CINTTYPE:
					fgw_2int(o1, o2);
					fgw_setint(&r, iholder1-iholder2);
					break;
				      default:
					fgw_setnull(&r);
				    }
				    FAILCHECK
				    fgw_freetssstack(o1);
				    fgw_freetssstack(o2);
				    r.count=0;
				    fgw_stackpush(&pstate->exprlist, &r);
				}
	| exp '*' exp		{
				    exprstack_t *l, *r;
				    exprstack_t *o1, *o2, d;
				    intrvl_t *ip1, in1;
				    int n1, n2;
				    double f;

				    o2=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
				    o1=(exprstack_t *) fgw_stackpop(&pstate->exprlist);

				    switch (d.type=fgw_optype(o1, o2,
							       &l, &r))
				    {
				      case CDECIMALTYPE:
				      case CMONEYTYPE:
					if (fgw_2decimal(o1, o2, &d))
					    status=decmul(dholder1, dholder2,
							  d.val.decimal);
					break;
				      case CDOUBLETYPE:
				      case CSTRINGTYPE:
					fgw_2double(o1, o2);
					fgw_setdouble(&d, fholder1*fholder2);
					break;
				      case CINTTYPE:
					fgw_2int(o1, o2);
					fgw_setint(&d, iholder1*iholder2);
					break;
				      case CINVTYPE:
					ip1=fgw_toinv(l, &in1, -1, &n1);
					f=fgw_todouble(r, &n2);
					if (!(d.val.interval=(intrvl_t *)
						fgw_smalloc(sizeof(intrvl_t))))
					    FAIL(-208)
					d.type=CINVTYPE;
					if (n1||n2)
					    rsetnull(CINVTYPE,
						     (char *) d.val.interval);
					status=invmuldbl(ip1, f,
							 d.val.interval);
					break;
				      default:
					fgw_setnull(&d);
				    }
				    FAILCHECK
				    fgw_freetssstack(o1);
				    fgw_freetssstack(o2);
				    d.count=0;
				    fgw_stackpush(&pstate->exprlist, &d);
				}
	| exp '/' exp		{
				    exprstack_t *o1, *o2, r;

				    o2=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
				    o1=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
				    if (o1->type==CINVTYPE)
				    {
					int n1, n2;
					intrvl_t *ip1, *ip2, in2;
					double f;

					if (o2->type==CINTTYPE ||
					    o2->type==CDOUBLETYPE)
					{
					    ip1=fgw_toinv(o1, &in2, -1, &n1);
					    f=fgw_todouble(o2, &n2);
					    r.type=CINVTYPE;
					    if (!(r.val.interval=(intrvl_t *)
						  fgw_smalloc(sizeof(intrvl_t))))
						FAIL(-208)
					    r.val.interval->in_qual=ip1->in_qual;
					    if (n1||n2)
						rsetnull(CINVTYPE, (char *)
							  r.val.interval);
					    else
						status=invdivdbl(ip1, f,
							    r.val.interval);
					}
					else
					{
					    ip1=fgw_toinv(o1, &in2, -1, &n1);
					    ip2=fgw_toinv(o2, &in2, -1, &n2);
					    if (n1||n2)
						fgw_setnull(&r);
					    else
					    {
						r.type=CDOUBLETYPE;
						status=invdivinv(ip1, ip2,
							&(r.val.real));
					    }
					}
				    }
				    else switch (r.type=fgw_exprtype(o1->type,
								     o2->type))
				    {
				      case CDECIMALTYPE:
				      case CMONEYTYPE:
					if (fgw_2decimal(o1, o2, &r))
					    status=decdiv(dholder1, dholder2,
							  r.val.decimal);
					break;
				      case CSTRINGTYPE:
				      case CDOUBLETYPE:
					fgw_2double(o1, o2);
/*
** avoid problems with null or 0 divisors...
*/
					if (nullind)
					{
					    r.type=CDOUBLETYPE;
					    rsetnull(CDOUBLETYPE,
						    (char *) &(r.val.real));
					}
					else if (fholder2==0)
					    FAIL(-1202)
					else
					    fgw_setdouble(&r,
							 fholder1/fholder2);
					break;
				      case CINTTYPE:
					fgw_2int(o1, o2);
					if (nullind)
					    fgw_setnull(&r);
					else if (iholder2==0)
					    FAIL(-1202)
					else
					    fgw_setint(&r,
						iholder1/iholder2);
					break;
				      default:
					fgw_setnull(&r);
				    }
				    FAILCHECK
				    fgw_freetssstack(o1);
				    fgw_freetssstack(o2);
				    r.count=0;
				    fgw_stackpush(&pstate->exprlist, &r);
				}
	| exp UNITS { pstate->parseroptions|=QUALIFIERHACK; } unitcl {
				    exprstack_t i, *o, r;
				    int n;

				    o=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
/*
**  we complicate things a bit to have units behave as in the engine
**  rather than an interval shorthand
*/
				    pstate->parseroptions&=~QUALIFIERHACK;
				    i.type=CINTTYPE;
				    i.val.intvalue=fgw_toint(o, NULL);
				    r.type=CINVTYPE;
				    if (!(r.val.interval=(intrvl_t *)
					     fgw_smalloc(sizeof(intrvl_t))))
					FAIL(-208)
				    fgw_toinv(&i, r.val.interval,
					TU_IENCODE(5, $4.type, $4.type), &n);
				    if (n)
					rsetnull(CINVTYPE,
						 (char *) r.val.interval);
				    fgw_freetssstack(o);
				    r.count=0;
				    fgw_stackpush(&pstate->exprlist, &r);
				}
	| '-' exp  %prec NEG	{
				    dec_t dec1;
				    exprstack_t *o, r;

				    o=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
				    if (fgw_isnull(o))
					r=*o;
				    else
					switch (o->type)
				 	{
				 	  case CSTRINGTYPE:
				 	  case FGWVAR:
					    fgw_setdouble(&r,
						-fgw_todouble(o, &nullind));
					    break;
					  case CDECIMALTYPE:
					  case CMONEYTYPE:
					    status=deccvlong(-1, &dec1);
					    r.type=o->type;
					    if (!(r.val.decimal=
						   (dec_t *) fgw_smalloc(
							    sizeof(dec_t))))
						FAIL(-208)
					    else
						decmul(o->val.decimal,
						   &dec1, r.val.decimal);
					    break;
				 	  case CDOUBLETYPE:
					    r.type=o->type;
					    r.val.real=-o->val.real;
					    break;
					  case CINTTYPE:
					    r.type=o->type;
					    r.val.intvalue=-o->val.intvalue;
					    break;
					  case CINVTYPE:
					    r.type=o->type;
					    if (!(r.val.interval=
						   (intrvl_t *) fgw_smalloc(
							    sizeof(intrvl_t))))
						FAIL(-208)
					    else
						invmuldbl(o->val.interval,
						   -1.0, r.val.interval);
					    break;
					  default:
					    fgw_setnull(&r);
					}
				    fgw_freetssstack(o);
				    r.count=0;
				    fgw_stackpush(&pstate->exprlist, &r);
				}
	| '+' exp  %prec PLUS	{
				    exprstack_t *o, r;

				    o=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
				    if (fgw_isnull(o))
					r=*o;
				    else
					switch (o->type)
				 	{
				 	  case CSTRINGTYPE:
				 	  case FGWVAR:
					    fgw_setdouble(&r,
						fgw_todouble(o, &nullind));
					    break;
				 	  case CDECIMALTYPE:
				 	  case CMONEYTYPE:
				 	  case CDOUBLETYPE:
					  case CINTTYPE:
					  case CINVTYPE:
					    r=*o;
					    break;
					  default:
					    fgw_setnull(&r);
					}
				    fgw_freetssstack(o);
				    r.count=0;
				    fgw_stackpush(&pstate->exprlist, &r);
				}
	| '(' exp ')'
;
boolexp:	exp IN '(' elist ')'	{
				    exprstack_t *s, *e, r;
				    int i, c;

				    s=arglist_sqp(&pstate->exprlist, &c);
				    e=s-1;
				    if (fgw_isnull(e))
					fgw_setnull(&r);
				    else
				    {
					r.type=CINTTYPE;
					r.val.intvalue=0;
					for (i=0; i<c; i++, s++)
					{
					    int t;

					    t=fgw_compare(e->type, e, s);
					    if (!nullind && !t)
					    {
						r.val.intvalue=1;
						break;
					    }
					    fgw_freetssstack(s);
					}
					fgw_freetssstack(e);
				    }
				    for (; i<c; i++, s++);
					fgw_freetssstack(s);
				    fgw_stackdrop(&pstate->exprlist, c);
				    r.count=0;
				    fgw_stackpush(&pstate->exprlist, &r);
				}
	| exp NOT IN '(' elist ')'	{
				    exprstack_t *s, *e, r;
				    int i, c;

				    s=arglist_sqp(&pstate->exprlist, &c);
				    e=s-1;
				    if (fgw_isnull(e))
					fgw_setnull(&r);
				    else
				    {
					r.type=CINTTYPE;
					r.val.intvalue=1;
					for (i=0; i<c; i++, s++)
					{
					    int t;

					    t=fgw_compare(e->type, e, s);
/*
** a null in a NOT IN clause will yield NULL
** (NOT exp IN & exp NOT IN are semantically different. is this right?)
*/
					    if (nullind)
					    {
						fgw_setnull(&r);
						break;
					    }
					    else if (!t)
					    {
						r.val.intvalue=0;
						break;
					    }
					    fgw_freetssstack(s);
					}
					fgw_freetssstack(e);
				    }
				    for (; i<c; i++, s++);
					fgw_freetssstack(s);
				    fgw_stackdrop(&pstate->exprlist, c);
				    r.count=0;
				    fgw_stackpush(&pstate->exprlist, &r);
				}
	| exp betweencl exp AND exp	{
				    int rl, rh;
				    exprstack_t *e, *el, *eh, r;

				    eh=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
				    el=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
				    e=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
				    if (fgw_isnull(e))
					fgw_setnull(&r);
				    else
				    {
/*
** el needs to be smaller than eh, but that's ok the engine
** behaves the same way
*/
					rl=fgw_compare(e->type, e, el);
					if (nullind)
					    fgw_setnull(&r);
					else
					{
					    rh=fgw_compare(e->type, e, eh);
					    if (nullind)
						fgw_setnull(&r);
					    else if ($2.type==BETWEEN)
						fgw_setint(&r,
							   rl>=0 && rh<=0);
					    else
						fgw_setint(&r, 
							   rl<0 || rh>0);
					}
				    }
				    fgw_freetssstack(e);
				    fgw_freetssstack(el);
				    fgw_freetssstack(eh);
				    r.count=0;
				    fgw_stackpush(&pstate->exprlist, &r);
				}
	| exp mrexcl exp escape {
				    int t;
				    char *e, esc[STRINGCONVSIZE];
				    exprstack_t *o1, *o2, *o3, r;

				    o3=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
				    o2=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
				    o1=(exprstack_t *) fgw_stackpop(&pstate->exprlist);

				    fgw_2string(o1, o2);
				    if (nullind)
					fgw_setnull(&r);
				    else
				    {
					retquote(sholder1);
					retquote(sholder2);
				 	e=fgw_tostring(o3, &esc, NULL);
/* FIXME: should I be testing for a null escape here? */
/* FIXME: using 4gl internals */
					_domatches((char) *e);
					popint(&t);
					if ($2.type==MATCHES)
					    fgw_setint(&r, t);
					else

					    fgw_setint(&r, !t);
				    }
				    fgw_freetssstack(o1);
				    fgw_freetssstack(o2);
				    fgw_freetssstack(o3);
				    r.count=0;
				    fgw_stackpush(&pstate->exprlist, &r);
				}
	| exp lrexcl exp escape {
				    int t;
				    char *e, esc[STRINGCONVSIZE];
				    exprstack_t *o1, *o2, *o3, r;

				    o3=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
				    o2=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
				    o1=(exprstack_t *) fgw_stackpop(&pstate->exprlist);

				    fgw_2string(o1, o2);
				    if (nullind)
					fgw_setnull(&r);
				    else
				    {
					retquote(sholder1);
					retquote(sholder2);
				 	e=fgw_tostring(o3, &esc, NULL);
/* FIXME: should I be testing for a null escape here? */
/* FIXME: using 4gl internals */
					_dolike((char) *e);
					popint(&t);
					if ($2.type==LIKE)
					    fgw_setint(&r, t);
					else
					    fgw_setint(&r, !t);
				    }
				    fgw_freetssstack(o1);
				    fgw_freetssstack(o2);
				    fgw_freetssstack(o3);
				    r.count=0;
				    fgw_stackpush(&pstate->exprlist, &r);
				}
	| allexp OR allexp	{
				    int b1, b2, n1, n2;
				    exprstack_t *o1, *o2, r;

				    o2=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
				    o1=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
				    b1=fgw_toboolean(o1, &n1);
				    b2=fgw_toboolean(o2, &n2);
				    nullind=n1||n2;
				    fgw_setint(&r, b1 || b2);
				    fgw_freetssstack(o1);
				    fgw_freetssstack(o2);
				    r.count=0;
				    fgw_stackpush(&pstate->exprlist, &r);
				}
	| allexp AND allexp	{
				    int b1, b2, n1, n2;
				    exprstack_t *o1, *o2, r;

				    o2=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
				    o1=(exprstack_t *) fgw_stackpop(&pstate->exprlist);

				    b1=fgw_toboolean(o1, &n1);
				    b2=fgw_toboolean(03, &n2);
				    nullind=n1||n2;
				    fgw_setint(&r, b1 && b2);
				    fgw_freetssstack(o1);
				    fgw_freetssstack(o2);
				    r.count=0;
				    fgw_stackpush(&pstate->exprlist, &r);
				}
	| NOT allexp		{
				    int b;
				    exprstack_t *o, r;

				    o=(exprstack_t *) fgw_stackpop(&pstate->exprlist);

				    b=fgw_toboolean(o, &nullind);
				    fgw_setint(&r, !b);
				    fgw_freetssstack(o);
				    r.count=0;
				    fgw_stackpush(&pstate->exprlist, &r);
				}
	| exp IS nullcl		{
				    int t;
				    exprstack_t *o, r;

				    o=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
				    nullind=0;
				    t=fgw_isnull(o);
				    if ($3.type==NULLVALUE)
					fgw_setint(&r, t);
				    else
					fgw_setint(&r, !t);
				    fgw_freetssstack(o);
				    r.count=0;
				    fgw_stackpush(&pstate->exprlist, &r);
				}
	| exp eqcl exp		{
				    int t;
				    exprstack_t *o1, *o2, r;

				    o2=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
				    o1=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
				    t=fgw_compare(fgw_exprtype(o1->type, o2->type),
						  o1, o2);
				    fgw_setint(&r, !t);
				    fgw_freetssstack(o1);
				    fgw_freetssstack(o2);
				    r.count=0;
				    fgw_stackpush(&pstate->exprlist, &r);
				}
	| exp NEQ exp		{
				    int t;
				    exprstack_t *o1, *o2, r;

				    o2=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
				    o1=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
				    t=fgw_compare(fgw_exprtype(o1->type, o2->type),
						  o1, o2);
				    fgw_setint(&r, (t!=0));
				    fgw_freetssstack(o1);
				    fgw_freetssstack(o2);
				    r.count=0;
				    fgw_stackpush(&pstate->exprlist, &r);
				}
	| exp LEQ exp		{
				    int t;
				    exprstack_t *o1, *o2, r;

				    o2=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
				    o1=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
				    t=fgw_compare(fgw_exprtype(o1->type, o2->type),
						  o1, o2);
				    fgw_setint(&r, (t<=0));
				    fgw_freetssstack(o1);
				    fgw_freetssstack(o2);
				    r.count=0;
				    fgw_stackpush(&pstate->exprlist, &r);
				}
	| exp '<' exp		{
				    int t;
				    exprstack_t *o1, *o2, r;

				    o2=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
				    o1=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
				    t=fgw_compare(fgw_exprtype(o1->type, o2->type),
						  o1, o2);
				    fgw_setint(&r, (t<0));
				    fgw_freetssstack(o1);
				    fgw_freetssstack(o2);
				    r.count=0;
				    fgw_stackpush(&pstate->exprlist, &r);
				}
	| exp GEQ exp		{
				    int t;
				    exprstack_t *o1, *o2, r;

				    o2=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
				    o1=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
				    t=fgw_compare(fgw_exprtype(o1->type, o2->type),
						  o1, o2);
				    fgw_setint(&r, (t>=0));
				    fgw_freetssstack(o1);
				    fgw_freetssstack(o2);
				    r.count=0;
				    fgw_stackpush(&pstate->exprlist, &r);
				}
	| exp '>' exp		{
				    int t;
				    exprstack_t *o1, *o2, r;

				    o2=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
				    o1=(exprstack_t *) fgw_stackpop(&pstate->exprlist);

				    t=fgw_compare(fgw_exprtype(o1->type, o2->type),
						  o1, o2);
				    fgw_setint(&r, (t>0));
				    fgw_freetssstack(o1);
				    fgw_freetssstack(o2);
				    r.count=0;
				    fgw_stackpush(&pstate->exprlist, &r);
				}
	| '(' boolexp ')'
;
rangecl:  '[' exp ']'		{
				    int i, n;
				    exprstack_t *o;

				    o=(exprstack_t *) fgw_stackpeek(&pstate->exprlist);
				    i=fgw_toint(o, &n);
				    if (i<=0 || iholder1>0x7fff || n)
					FAIL(-307)
				    fgw_freetssstack(o);
				    o->val.range[0]=i-1;
				    o->val.range[1]=i-1;
				}
	| '[' exp ',' exp ']'	{
				    exprstack_t *o1, *o2;

				    o2=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
				    o1=(exprstack_t *) fgw_stackpeek(&pstate->exprlist);
				    fgw_2int(o1, o2);
				    if (iholder1<=0 || iholder2<iholder1 ||
					nullind || iholder2>0x7fff)
					FAIL(-307)
				    fgw_freetssstack(o1);
				    fgw_freetssstack(o2);
				    o1->val.range[0]=iholder1-1;
				    o1->val.range[1]=iholder2-1;
				}
;
qualcl:	/* empty */		{
				    exprstack_t q;

				    q.type=CINTTYPE;
				    q.val.intvalue=-1;
				    q.count=0;
				    fgw_stackpush(&pstate->exprlist, &q);
				}
	| unitcl TO unitcl	{
				    exprstack_t q;

				    if ($1.type>$3.type)
					FAIL(-201)
				    q.type=CINTTYPE;
				    q.val.intvalue=TU_DTENCODE($1.type, $3.type);
				    q.count=0;
				    fgw_stackpush(&pstate->exprlist, &q);
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
				    exprstack_t *c, *w, *t;

				    t=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
				    w=(exprstack_t *) fgw_stackpop(&pstate->exprlist);
				    c=(exprstack_t *) fgw_stackpeek(&pstate->exprlist);
				    iholder1=fgw_toboolean(w, &nullind);
				    if (c->type!=ELSE)
				    {
					fgw_freetssstack(w);
					fgw_freetssstack(t);
				    }
				    else if (iholder1)
				    {
					*c=*t;
					fgw_freetssstack(w);
				    }
				    else
				    {
					c->type=ELSE;	/* superfluous, but... */
					fgw_freetssstack(w);
					fgw_freetssstack(t);
				    }
				}
	| /* empty */		{
				    exprstack_t r;

				    r.type=ELSE;
				    r.count=0;
				    fgw_stackpush(&pstate->exprlist, &r);
				}
;
lcasecl:  lcasecl WHEN exp THEN exp 	{
				    exprstack_t *c, *w, *t;

				    t=(exprstack_t *) fgw_stackpeek(&pstate->exprlist);
				    w=t-1;
				    c=w-1;
				    w->count=c->count+1;
				    t->count=w->count+1;
				}
	| WHEN exp THEN exp 	{
				    exprstack_t *w, *t;

				    t=(exprstack_t *) fgw_stackpeek(&pstate->exprlist);
				    w=t-1;
				    w->count=1;
				    t->count=2;
				}
;
elsecl:	  ELSE exp
	| /* empty */		{
				    exprstack_t r;

				    fgw_setnull(&r);
				    r.count=0;
				    fgw_stackpush(&pstate->exprlist, &r);
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
elist:	  elist ',' allexp 	{
				    exprstack_t *t, *t1;

				    t=(exprstack_t *) fgw_stackpeek(
							&pstate->exprlist);
				    t1=t-1;
				    t->count=t1->count+1;
				}
	| allexp	{
			    exprstack_t *t;

			    t=(exprstack_t *) fgw_stackpeek(&pstate->exprlist);
			    t->count=1;
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
escape:	  ESCAPE exp
	| /* empty */		{
				    exprstack_t r;

				    r.type=FGWVAR;
				    r.val.string="\\";
				    r.count=0;
				    fgw_stackpush(&pstate->exprlist, &r);
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
    else
  	pstate->parseroptions=SQLHACK;
    pstate->ibufp=pstate->o_query+pstate->phase1.stmt_start;
    pstate->ibufe=pstate->ibufp+strlen(pstate->ibufp);
    pstate->sqlstart=pstate->ibufp;
    pstate->sqlend=pstate->ibufe;
    pstate->sqlsv=0;
    init_sqp();
    status=0;
    yyparse();
/*
** stored procedures and outer layers require buffer untouched
** restore whatever damage we have done
*/
    if (pstate->sqlsv)
	*pstate->sqlend=pstate->sqlsv;
/*
** free string resources
*/
    prevtoken=-1;
    fgw_tssdrop(&(pstate->lexhead));
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
static void ascii_sqp(s)
fgw_stacktype *s;
{
    int c, n;
    exprstack_t *i, o;

    i=arglist_sqp(s, NULL);
/* FIXME: not GLS aware */
    if (!(o.val.string=fgw_smalloc(1)))
	status=-208;
    else
    {
	o.type=CSTRINGTYPE;
	c=fgw_toint(i, &n);
	if (n)
	   rsetnull(CSTRINGTYPE, o.val.string);
	else if (c<1 || c>255)
	   status=-717;
	else
	{
	    *o.val.string=(char) c;
	    *(o.val.string+1)='\0';
	}
    }
    pushresult_sqp(s, &o, 1);
}

/*
** clipped
*/
static void clipped_sqp(s)
fgw_stacktype *s;
{
    int n, l;
    exprstack_t *i, o;
    char *c, cbuf[STRINGCONVSIZE], *p;

    i=arglist_sqp(s, NULL);
    c=fgw_tostring(i, &cbuf, &n);
    if (n)
	l=0;
    else if (l=stleng(c))
    {
	p=c+l-1;
	while (*p--==' ')
	    l--;
    }
    if (!(o.val.string=fgw_smalloc(l)))
	status=-208;
    else
    {
	o.type=CSTRINGTYPE;
	if (n)
	    rsetnull(CSTRINGTYPE, o.val.string);
	else
	{
	    if (l)
		bycopy(c, o.val.string, l);
	    *(o.val.string+l)='\0';
	}
    }
    pushresult_sqp(s, &o, 1);
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
static void spaces_sqp(s)
fgw_stacktype *s;
{
    int sp, n;
    exprstack_t *i, o;

    i=arglist_sqp(s, NULL);
    sp=fgw_toint(i, &n);
    if (n)
	fgw_setnull(&o);
    else if (sp<=0)
	status=-717;
    else if (!(o.val.string=(char *) fgw_smalloc(sp)))
	status=-208;
    else
    {
	o.type=CSTRINGTYPE;
	dopadding_sqp(sp, " ", o.val.string);
	*(o.val.string+sp)='\0';
    }
    pushresult_sqp(s, &o, 1);
}

/*
** exec
*/
static void exec_sqp(s)
fgw_stacktype *s;
{
    int n;
    char *c, cbuf[STRINGCONVSIZE];
    exprstack_t *i, o;

    i=arglist_sqp(s, NULL);
    if (pstate->parseroptions & EXPRONLY)
	status=-201;
    else
    {
	c=fgw_tostring(i, &cbuf, &n);
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
	o.type=CINTTYPE;
	o.val.intvalue=-1;
    }
    pushresult_sqp(s, &o, 1);
}

/*
** fork
*/
static void fork_sqp(s)
fgw_stacktype *s;
{
    exprstack_t o;

    if (pstate->parseroptions & EXPRONLY)
    {
	status=-201;
	return;
    }
    o.type=CINTTYPE;
    o.val.intvalue=(int) fork();
/*
** parent branch
*/
    if (o.val.intvalue)
	errcode=errno;
/*
** child branch
*/
    else
    {
/*
** children do not have a default output and don't mess with the parent
** current output
*/
	pstate->def_fd=(fgw_fdesc *) -1;
	pstate->curr_fd=sql_openfile(pstate->def_fd);
	sql_flush(pstate->curr_fd, 1);
	sqldetach();
	is_child=1;
    }
    pushresult_sqp(s, &o, 1);
}

/*
** getenv
*/
static void getenv_sqp(s)
fgw_stacktype *s;
{
    int n, l;
    char *e, ebuf[STRINGCONVSIZE], *v;
    exprstack_t *i, o;

    l=0;
    i=arglist_sqp(s, NULL);
    e=fgw_tostring(i, &ebuf, &n);
    if (!n && (v=getenv(e)))
	l=stleng(v);
    if (!(o.val.string=fgw_smalloc(l)))
	status=-208;
    else
    {
	o.type=CSTRINGTYPE;
	if (n)
	    rsetnull(CSTRINGTYPE, o.val.string);
	else
	{
	    if (l)
		bycopy(v, o.val.string, l);
	    *(o.val.string+l)='\0';
	}
    }
    pushresult_sqp(s, &o, 1);
}

/*
** wait
*/
static void wait_sqp(s)
fgw_stacktype *s;
{
    exprstack_t o;

    if (pstate->parseroptions & EXPRONLY)
    {
	status=-201;
	return;
    }
    o.type=CINTTYPE;
    do
    {
        o.val.intvalue=wait(&childstatus);
    } while (o.val.intvalue==-1 && errno==EINTR);
    if (o.val.intvalue==-1)
        errcode=errno;
    else
        childstatus=childstatus>>8;
    pushresult_sqp(s, &o, 1);
}

/*
** waitpid
*/
static void waitpid_sqp(s)
fgw_stacktype *s;
{
    int pid, n1;
    exprstack_t *i, o;

    i=arglist_sqp(s, NULL);
    if (pstate->parseroptions & EXPRONLY)
	status=-201;
    else
    {
	pid=fgw_toint(i, &n1);
	o.type=CINTTYPE;
	do
	{
	    o.val.intvalue=waitpid(pid, &childstatus, WUNTRACED);
	} while (o.val.intvalue==-1 && errno==EINTR);
	if (o.val.intvalue==-1)
	    errcode=errno;
	else
	    childstatus=childstatus>>8;
    }
    pushresult_sqp(s, &o, 1);
}

/*
** index
*/
static void index_sqp(s)
fgw_stacktype *s;
{
    exprstack_t *i, o;

    i=arglist_sqp(s, NULL);
    fgw_2string(i, i+1);
    if (nullind)
	fgw_setnull(&o);
    else
    {
	o.type=CINTTYPE;
	o.val.intvalue=fgw_pos(sholder1, sholder2);
    }
    pushresult_sqp(s, &o, 1);
}

/*
** pad
*/
static void pad_sqp(s)
fgw_stacktype *s;
{
    int sp, n1, n2;
    char *ps, cbuf[STRINGCONVSIZE];
    exprstack_t *i, o;

    i=arglist_sqp(s, NULL);
    ps=fgw_tostring(i++, &cbuf, &n2);
    sp=fgw_toint(i, &n1);
    if (n1||n2)
	fgw_setnull(&o);
    else if (sp<=0)
	status=-717;
    else if (!(o.val.string=(char *) fgw_smalloc(sp)))
	status=-208;
    else
    {
	o.type=CSTRINGTYPE;
	dopadding_sqp(sp, ps, o.val.string);
	*(o.val.string+sp)='\0';
    }
    pushresult_sqp(s, &o, 1);
}

/*
** random
*/
static void random_sqp(s)
fgw_stacktype *s;
{
    int newseed, top, p, n;
    exprstack_t *i, o;

    i=arglist_sqp(s, &p);
    o.type=CINTTYPE;
    switch (p)
    {
      case 2:
	newseed=fgw_toint(i+1, &n);
	if (n)
	{
	    status=-717;	
	    break;
	}
	else
	    srand48(newseed);
      case 1:
	top=fgw_toint(i, &n);
	if (n)
	    rsetnull(CINTTYPE, (char *) &o.val.intvalue);
	else
	    o.val.intvalue=lrand48() % top;
	break;
      default:
	status=-664;
    }
    pushresult_sqp(s, &o, p);
}

/*
** current
*/
static void current_sqp(s)
fgw_stacktype *s;
{
    int q;
    exprstack_t *i, o;

    i=(exprstack_t *) fgw_stackpop(s);
    if ((q=i->val.intvalue)<0)
	q=TU_DTENCODE(TU_YEAR, TU_SECOND);
    o.type=CDTIMETYPE;
    if (!(o.val.datetime=(dtime_t *) fgw_smalloc(sizeof(dtime_t))))
	status=-208;
    else
    {
	o.val.datetime->dt_qual=q;
	dtcurrent(o.val.datetime);
    }
    pushresult_sqp(s, &o, 0);
}

/*
** today
*/
static void today_sqp(s)
fgw_stacktype *s;
{
    exprstack_t o;

    o.type=CDATETYPE;
    rtoday(&o.val.intvalue);
    pushresult_sqp(s, &o, 0);
}

/*
** user
*/
static void user_sqp(s)
fgw_stacktype *s;
{
    struct passwd *p;
    exprstack_t o;

    o.type=CSTRINGTYPE;
    if (p=getpwuid(getuid()))
    {
	if (o.val.string=fgw_smalloc(strlen(p->pw_name)))
	    stcopy(p->pw_name, o.val.string);
	else
	    status=-208;
    }
    else
        fgw_setnull(&o);
    pushresult_sqp(s, &o, 0);
}

/*
** decode
*/
static void decode_sqp(s)
fgw_stacktype *s;
{
    exprstack_t *i, *w, o;
    int p, c;

    i=arglist_sqp(s, &p);
    fgw_setnull(&o);
    w=i+1;
    c=p-1;
    while (c)
    {
	int r;

	if (c>1)
	{
	    r=fgw_compare(i->type, i, w);
	    w++;
	    c--;
	    if (r)
	    {
		w++;
		c--;
		continue;
	    }
	}
	o=*w;
	fgw_setint(w, 0);		/* hack: avoid freeing strings */
	break;
    }
    pushresult_sqp(s, &o, p);
}

/*
** nvl
*/
static void nvl_sqp(s)
fgw_stacktype *s;
{
    exprstack_t *i, o;

    i=arglist_sqp(s, NULL);
    if (fgw_isnull(i))
        i++;
    o=*i;
    fgw_setint(i, 0);		/* hack: avoid freeing strings */
    pushresult_sqp(s, &o, 2);
}

/*
** abs
*/
static void abs_sqp(s)
fgw_stacktype *s;
{
    double f;
    int n;
    exprstack_t *i, o;

    i=arglist_sqp(s, NULL);
    f=fgw_todouble(i, &n);
    o.type=CDOUBLETYPE;
    if (n)
	rsetnull(CDOUBLETYPE, (char *) &(o.val.real));
    else
	o.val.real=fabs(f);
    pushresult_sqp(s, &o, 1);
}

/*
** mod
*/
static void mod_sqp(s)
fgw_stacktype *s;
{
    exprstack_t *i, o;

    i=arglist_sqp(s, NULL);
    fgw_2int(i, i+1);
    o.type=CINTTYPE;
    if (nullind)
	rsetnull(CINTTYPE, (char *) &(o.val.intvalue));
    else if (iholder2==0)
	status=-717;
    else
	o.val.intvalue=iholder1-(iholder1/iholder2)*iholder2;
    pushresult_sqp(s, &o, 2);
}

/*
** pow
*/
static void pow_sqp(s)
fgw_stacktype *s;
{
    exprstack_t *i, o;

    i=arglist_sqp(s, NULL);
    fgw_2double(i, i+1);
    o.type=CDOUBLETYPE;
    if (nullind)
	rsetnull(CDOUBLETYPE, (char *) &(o.val.real));
    else
	o.val.real=pow(fholder1, fholder2);
    pushresult_sqp(s, &o, 2);
}

/*
** root
*/
static void root_sqp(s)
fgw_stacktype *s;
{
    exprstack_t *i, o;

    i=arglist_sqp(s, NULL);
    fgw_2double(i, i+1);
    o.type=CDOUBLETYPE;
    if (nullind)
	rsetnull(CDOUBLETYPE, (char *) &(o.val.real));
    else if (fholder2==0.0)
	status=-717;
    else
	o.val.real=pow(fholder1, 1.0/fholder2);
    pushresult_sqp(s, &o, 2);
}

/*
** does actual rounding
*/
static void fgw_round(s, r)
fgw_stacktype *s;
double r;
{
    double f;
    int k, n1, n2, p;
    exprstack_t *i, o;

/*
** check args & convert
*/
    i=arglist_sqp(s, &p);
    f=fgw_todouble(i, &n1);
    if (p>2)
	status=-664;
    else
    {
	if (p==2)
	    k=fgw_toint(i+1, &n2);
	else
	{
	    k=0;
	    n2=0;
	}
	o.type=CDOUBLETYPE;
	if (n1||n2)
	    rsetnull(CDOUBLETYPE, (char *) &(o.val.real));
	else
	{
	    double d;

	    d=pow(10.0, -k);
	    if (f>0.0)
		o.val.real=floor((f/d)+r)*d;
	    else
		o.val.real=floor((f/d)-r)*d;
	}
    }
    pushresult_sqp(s, &o, p);
}

/*
** round
*/
static void round_sqp(s)
fgw_stacktype *s;
{
    fgw_round(s, 0.5);
}

/*
** sqrt
*/
static void sqrt_sqp(s)
fgw_stacktype *s;
{
    double f;
    int n;
    exprstack_t *i, o;

    i=arglist_sqp(s, NULL);
    f=fgw_todouble(i, &n);
    o.type=CDOUBLETYPE;
    if (n)
	rsetnull(CDOUBLETYPE, (char *) &(o.val.real));
    else
	o.val.real=sqrt(f);
    pushresult_sqp(s, &o, 1);
}

/*
** trunc
*/
static void trunc_sqp(s)
fgw_stacktype *s;
{
    fgw_round(s, 0.0);
}

/*
** dbinfo
*/
static void dbinfo_sqp(s)
fgw_stacktype *s;
{
    int n;
    char *c, cbuf[STRINGCONVSIZE];
    exprstack_t *i, o;

    i=arglist_sqp(s, NULL);
    c=fgw_tostring(i, &cbuf, &n);
/* FIXME: don't check for GLS overruns */
    rdownshift(c);
    o.type=CINTTYPE;
    if (n)
	status=-728;
    else if (!strcmp(c, "sqlca.sqlerrd1"))
	o.val.intvalue=sqlca.sqlerrd[1];
    else if (!strcmp(c, "sqlca.sqlerrd2"))
	o.val.intvalue=sqlca.sqlerrd[2];
    else if (!strcmp(c, "sqlca.sqlcode"))
	o.val.intvalue=sqlca.sqlcode;
    else if (!strcmp(c, "errno"))
	o.val.intvalue=errcode;
    else if (!strcmp(c, "$?"))
	o.val.intvalue=childstatus;
    else
	status=-728;
    pushresult_sqp(s, &o, 1);
}

/*
** sqlcode
*/
static void sqlcode_sqp(s)
fgw_stacktype *s;
{
    struct passwd *p;
    exprstack_t o;

    o.type=CINTTYPE;
    o.val.intvalue=sqlca.sqlcode;
    pushresult_sqp(s, &o, 0);
}

/*
** sqlerrd1
*/
static void sqlerrd1_sqp(s)
fgw_stacktype *s;
{
    struct passwd *p;
    exprstack_t o;

    o.type=CINTTYPE;
    o.val.intvalue=sqlca.sqlerrd[1];
    pushresult_sqp(s, &o, 0);
}

/*
** sqlerrd2
*/
static void sqlerrd2_sqp(s)
fgw_stacktype *s;
{
    struct passwd *p;
    exprstack_t o;

    o.type=CINTTYPE;
    o.val.intvalue=sqlca.sqlerrd[2];
    pushresult_sqp(s, &o, 0);
}

/*
** errno
*/
static void errno_sqp(s)
fgw_stacktype *s;
{
    struct passwd *p;
    exprstack_t o;

    o.type=CINTTYPE;
    o.val.intvalue=errcode;
    pushresult_sqp(s, &o, 0);
}

/*
** exp
*/
static void exp_sqp(s)
fgw_stacktype *s;
{
    double f;
    int n;
    exprstack_t *i, o;

    i=arglist_sqp(s, NULL);
    f=fgw_todouble(i, &n);
    o.type=CDOUBLETYPE;
    if (n)
	rsetnull(CDOUBLETYPE, (char *) &(o.val.real));
    else
	o.val.real=exp(f);
    pushresult_sqp(s, &o, 1);
}

/*
** log10
*/
static void log10_sqp(s)
fgw_stacktype *s;
{
    double f;
    int n;
    exprstack_t *i, o;

    i=arglist_sqp(s, NULL);
    f=fgw_todouble(i, &n);
    o.type=CDOUBLETYPE;
    if (n)
	rsetnull(CDOUBLETYPE, (char *) &(o.val.real));
    else if (f<=0.0)
	status=-717;
    else
	o.val.real=log10(f);
    pushresult_sqp(s, &o, 1);
}

/*
** logn
*/
static void logn_sqp(s)
fgw_stacktype *s;
{
    double f;
    int n;
    exprstack_t *i, o;

    i=arglist_sqp(s, NULL);
    f=fgw_todouble(i, &n);
    o.type=CDOUBLETYPE;
    if (n)
	rsetnull(CDOUBLETYPE, (char *) &(o.val.real));
    else if (f<=0.0)
	status=-717;
    else
	o.val.real=log(f);
    pushresult_sqp(s, &o, 1);
}

/*
** hex
*/
static void hex_sqp(s)
fgw_stacktype *s;
{
    int k, n;
    exprstack_t *i, o;

    i=arglist_sqp(s, NULL);
    if (!(o.val.string=fgw_smalloc(11)))
	status=-208;
    else
    {
	k=fgw_toint(i, &n);
	o.type=CSTRINGTYPE;
	if (n)
	    rsetnull(CSTRINGTYPE, o.val.string);
	else
	    sprintf(o.val.string, "0x%x", k);
    }
    pushresult_sqp(s, &o, 1);
}

/*
** char_length
*/
static void charlength_sqp(s)
fgw_stacktype *s;
{
    char *c, cbuf[STRINGCONVSIZE];
    int n;
    exprstack_t *i, o;

    i=arglist_sqp(s, NULL);
    c=fgw_tostring(i, &cbuf, &n);
    o.type=CINTTYPE;
    if (n)
	o.val.intvalue=0;
    else
	o.val.intvalue=stleng(c);
    pushresult_sqp(s, &o, 1);
}

/*
** length
*/
static void length_sqp(s)
fgw_stacktype *s;
{
    char *c, *p, cbuf[STRINGCONVSIZE];
    int l, n;
    exprstack_t *i, o;

    i=arglist_sqp(s, NULL);
    c=fgw_tostring(i, &cbuf, &n);
    o.type=CINTTYPE;
    if (n || !(l=stleng(c)))
	o.val.intvalue=0;
    else
    {
	p=c+l-1;
	while (l && *p--==' ')
	    l--;
	o.val.intvalue=l;
    }
    pushresult_sqp(s, &o, 1);
}

/*
** datetime
*/
static void datetime_sqp(s)
fgw_stacktype *s;
{
    int n1, n2, q, pc;
    exprstack_t *i, o;

    i=(exprstack_t *) fgw_stackpop(s);
    if ((q=i->val.intvalue)<0)
	q=TU_DTENCODE(TU_YEAR, TU_SECOND);
    i=arglist_sqp(s, &pc);
    o.type=CDTIMETYPE;
    if (!(o.val.datetime=(dtime_t *) fgw_smalloc(sizeof(dtime_t))))
    {
	status=-208;
	return;
    }
#ifdef HAS_DTFMT
    if (pc==2)
    {
	fgw_2string(i, i+1);
	status=dtcvfmtasc(sholder1, sholder2, o.val.datetime);
    }
    else if (pc>2)
    {
	status=-664;
	return;
    }
    else
#endif
    {
	fgw_todtime(i, o.val.datetime, q, &n1);
	if (n1)
	    rsetnull(CDTIMETYPE, o.val.string);
    }
    pushresult_sqp(s, &o, pc);
}

/*
** interval
*/
static void interval_sqp(s)
fgw_stacktype *s;
{
    int n1, n2, q, pc;
    exprstack_t *i, o;

    i=(exprstack_t *) fgw_stackpop(s);
    if ((q=i->val.intvalue)<0)
	q=TU_IENCODE(5, TU_DAY, TU_F5);
    else
	q=TU_IENCODE(5, TU_START(q), TU_END(q));
    i=arglist_sqp(s, &pc);
    o.type=CINVTYPE;
    if (!(o.val.interval=(intrvl_t *) fgw_smalloc(sizeof(intrvl_t))))
    {
	status=-208;
	return;
    }
#ifdef HAS_DTFMT
    if (pc==2)
    {
	fgw_2string(i, i+1);
	status=incvfmtasc(sholder1, sholder2, o.val.interval);
    }
    else if (pc>2)
    {
	status=-664;
	return;
    }
    else
#endif
    {
	fgw_toinv(i, o.val.interval, q, &n1);
	if (n1)
	    rsetnull(CINVTYPE, o.val.string);
    }
    pushresult_sqp(s, &o, pc);
}

/*
** date
*/
static void date_sqp(s)
fgw_stacktype *s;
{
    int n1, n2, p;
    exprstack_t *i, o;

    i=arglist_sqp(s, &p);
    o.type=CDATETYPE;
    switch(p)
    {
      case 1:
	o.val.intvalue=fgw_todate(i, &n1);
	if (n1)
	    rsetnull(CDATETYPE, (char *) &o.val.intvalue);
	break;
      case 2:
	fgw_2string(i, i+1);
	status=rdefmtdate(&o.val.intvalue, sholder2, sholder1);
	break;
      default:
	status=-664;
    }
    pushresult_sqp(s, &o, p);
}

/*
** day
*/
static void day_sqp(s)
fgw_stacktype *s;
{
    short mdy[3];
    int d, n;
    exprstack_t *i, o;

    i=arglist_sqp(s, NULL);
    d=fgw_todate(i, &n);
    if (n)
	fgw_setnull(&o);
    else
    {
	o.type=CINTTYPE;
	status=rjulmdy(d, mdy);
	o.val.intvalue=mdy[1];
    }
    pushresult_sqp(s, &o, 1);
}

/*
** month
*/
static void month_sqp(s)
fgw_stacktype *s;
{
    short mdy[3];
    int d, n;
    exprstack_t *i, o;

    i=arglist_sqp(s, NULL);
    d=fgw_todate(i, &n);
    if (n)
	fgw_setnull(&o);
    else
    {
	o.type=CINTTYPE;
	status=rjulmdy(d, mdy);
	o.val.intvalue=mdy[0];
    }
    pushresult_sqp(s, &o, 1);
}

/*
** year
*/
static void year_sqp(s)
fgw_stacktype *s;
{
    short mdy[3];
    int d, n;
    exprstack_t *i, o;

    i=arglist_sqp(s, NULL);
    d=fgw_todate(i, &n);
    if (n)
	fgw_setnull(&o);
    else
    {
	o.type=CINTTYPE;
	status=rjulmdy(d, mdy);
	o.val.intvalue=mdy[2];
    }
}

/*
** weekday
*/
static void weekday_sqp(s)
fgw_stacktype *s;
{
    int d, n;
    exprstack_t *i, o;

    i=arglist_sqp(s, NULL);
    d=fgw_todate(i, &n);
    if (n)
	fgw_setnull(&o);
    else
    {
	o.type=CINTTYPE;
	o.val.intvalue=rdayofweek(d);
    }
    pushresult_sqp(s, &o, 1);
}

/*
** mdy
*/
static void mdy_sqp(s)
fgw_stacktype *s;
{
    short mdy[3];
    int c, d, n;
    exprstack_t *i, o;

    i=arglist_sqp(s, NULL);
    for (c=0; c<3; c++, i++)
    {
	d=fgw_toint(i, &n);
	if (n)
	{
	    fgw_setnull(&o);
	    break;
	}
	mdy[c]=d;
    }
    o.type=CDATETYPE;
    status=rmdyjul(mdy, &o.val.intvalue);
    pushresult_sqp(s, &o, 3);
}

/*
** cos
*/
static void cos_sqp(s)
fgw_stacktype *s;
{
    double f;
    int n;
    exprstack_t *i, o;

    i=arglist_sqp(s, NULL);
    f=fgw_todouble(i, &n);
    o.type=CDOUBLETYPE;
    if (n)
	rsetnull(CDOUBLETYPE, (char *) &(o.val.real));
    else
	o.val.real=cos(f);
    pushresult_sqp(s, &o, 1);
}

/*
** sin
*/
static void sin_sqp(s)
fgw_stacktype *s;
{
    double f;
    int n;
    exprstack_t *i, o;

    i=arglist_sqp(s, NULL);
    f=fgw_todouble(i, &n);
    o.type=CDOUBLETYPE;
    if (n)
	rsetnull(CDOUBLETYPE, (char *) &(o.val.real));
    else
	o.val.real=sin(f);
    pushresult_sqp(s, &o, 1);
}

/*
** tan
*/
static void tan_sqp(s)
fgw_stacktype *s;
{
    double f;
    int n;
    exprstack_t *i, o;

    i=arglist_sqp(s, NULL);
    f=fgw_todouble(i, &n);
    o.type=CDOUBLETYPE;
    if (n)
	rsetnull(CDOUBLETYPE, (char *) &(o.val.real));
    else
	o.val.real=tan(f);
    pushresult_sqp(s, &o, 1);
}

/*
** acos
*/
static void acos_sqp(s)
fgw_stacktype *s;
{
    double f;
    int n;
    exprstack_t *i, o;

    i=arglist_sqp(s, NULL);
    f=fgw_todouble(i, &n);
    o.type=CDOUBLETYPE;
    if (n)
	rsetnull(CDOUBLETYPE, (char *) &(o.val.real));
    else
/* if not in [-1..1] will return nan on most systems */
	o.val.real=acos(f);
    pushresult_sqp(s, &o, 1);
}

/*
** asin
*/
static void asin_sqp(s)
fgw_stacktype *s;
{
    double f;
    int n;
    exprstack_t *i, o;

    i=arglist_sqp(s, NULL);
    f=fgw_todouble(i, &n);
    o.type=CDOUBLETYPE;
    if (n)
	rsetnull(CDOUBLETYPE, (char *) &(o.val.real));
    else
/* if not in [-1..1] will return nan on most systems */
	o.val.real=asin(f);
    pushresult_sqp(s, &o, 1);
}

/*
** atan
*/
static void atan_sqp(s)
fgw_stacktype *s;
{
    double f;
    int n;
    exprstack_t *i, o;

    i=arglist_sqp(s, NULL);
    f=fgw_todouble(i, &n);
    o.type=CDOUBLETYPE;
    if (n)
	rsetnull(CDOUBLETYPE, (char *) &(o.val.real));
    else
	o.val.real=atan(f);
    pushresult_sqp(s, &o, 1);
}

/*
** atan2
*/
static void atan2_sqp(s)
fgw_stacktype *s;
{
    exprstack_t *i, o;

    i=arglist_sqp(s, NULL);
    fgw_2double(i, i+1);
    o.type=CDOUBLETYPE;
    if (nullind)
	rsetnull(CDOUBLETYPE, (char *) &(o.val.real));
    else
	o.val.real=atan2(fholder1, fholder2);
    pushresult_sqp(s, &o, 2);
}

/*
** substr
*/
static void substr_sqp(s)
fgw_stacktype *s;
{
    int l, n;
    char *c, cbuf[STRINGCONVSIZE];
    exprstack_t *i, o;

    i=arglist_sqp(s, NULL);
    o.type=CSTRINGTYPE;
    c=fgw_tostring(i, &cbuf, &n);
    fgw_2int(i+1, i+2);
    if (n||nullind)
    {
	if (!(o.val.string=fgw_smalloc(0)))
	    status=-208;
	else
	    rsetnull(CSTRINGTYPE, o.val.string);
	goto end;
    }
/*
** can't have a negative length
*/
    if (iholder2<1)
    {
	status=717;
	goto end;
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
	goto end;
    }
/*
** and avoid stupid segvs
*/
    if (iholder1+iholder2>l)
	iholder2=l-iholder1;
    if (!(o.val.string=fgw_smalloc(iholder2+1)))
    {
	status=-208;
	goto end;
    }
    if (iholder1>l)
	*o.val.string='\0';
    else
    {
	bycopy(c+iholder1, o.val.string, iholder2);
	*(o.val.string+iholder2)='\0';
    }
end:
    pushresult_sqp(s, &o, 3);
}

/*
** replace
*/
static void replace_sqp(s)
fgw_stacktype *s;
{
    int pc, n, ni, idx, st, l, fl, tl, ol, il;
    exprstack_t *p;
    char *ob;
    char *sb, sbuf[STRINGCONVSIZE];
    char *fb, fbuf[STRINGCONVSIZE];
    char *tb, tbuf[STRINGCONVSIZE];
    exprstack_t *i, o;

/*
** sort out parms:
*/
    i=arglist_sqp(s, &pc);
    if (pc<2 || pc>5)
    {
	status=-664;
	goto end;
    }
/*
** original string
*/
    sb=fgw_tostring(i, &sbuf, &n);
    if (n)
	ol=0;
    else
	ol=stleng(sb);
/*
** from string
*/
    fb=fgw_tostring(i+1, &fbuf, &ni);
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
	tb=fgw_tostring(i+2, &tbuf, &ni);
	if (ni)
	    tl=0;
	else
	    tl=stleng(tb);
/*	n|=ni; */	/* we allow removal of substrings */
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
	st=fgw_toint(i+3, &ni);
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
	il=fgw_toint(i+4, &ni);
	n|=ni;
    }
    else
	il=ol;
/*
** allocate memory
*/
    o.type=CSTRINGTYPE;
    if (!(o.val.string=fgw_smalloc(ol)))
    {
	status=-208;
	goto end;
    }
/*
** & return null if any parm null
*/
    if (n)
	rsetnull(CSTRINGTYPE, o.val.string);
/*
** wrong parms
*/
    else if (il<1 || st<0)
	status=-717;
/*
** empty from string, nothing to change
*/
    else if (!*fb)
	stcopy(sb, o.val.string);
    else
    {
	l=0;
	ob=o.val.string;
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
		goto end;
	    }
	    if (l+il+tl-fl>ol)
/*
** output buffer doesn't fit, resize
*/
	    	if (ob=fgw_smalloc(l+il+tl-fl))
		{
		    bycopy(o.val.string, ob, l);
		    fgw_sfree(o.val.string);
		    o.val.string=ob;
		    ob+=l;
		}
		else
		{
		    status=-208;
		    goto end;
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
end:
    pushresult_sqp(s, &o, pc);
}

/*
** common bit of lpad & rpad
*/
static dorlpad_sqp(s, o, c, cbuf, p, pbuf, l , il, pc)
fgw_stacktype *s;
exprstack_t *o;
char **c, *cbuf, **p, *pbuf;
int *l, *il, *pc;
{
    exprstack_t *i;
    int n1, n2, n3;

    i=arglist_sqp(s, pc);
    if (*pc!=2 && *pc!=3)
	status=-664;
    else
    {
	o->type=CSTRINGTYPE;
	*c=fgw_tostring(i, cbuf, &n1);
	*l=fgw_toint(i+1, &n2);
	if (*pc==3)
	    *p=fgw_tostring(i+2, pbuf, &n3);
	else
	{
	    *p=" ";
	    n3=0;
	}
	if (n2)
	   fgw_setnull(o);
	else if (!(o->val.string=fgw_smalloc(*l)))
	    status=-208;
	else if (n1 || n3)
	    rsetnull(CSTRINGTYPE, o->val.string);
	else if (*l<=(*il=stleng(*c)))
	{
	    bycopy(*c, o->val.string, *l);
	    *(o->val.string+*l)='\0';
	}
    }
}

/*
** lpad
*/
static void lpad_sqp(s)
fgw_stacktype *s;
{
    exprstack_t o;
    char *c, cbuf[STRINGCONVSIZE], *p, pbuf[STRINGCONVSIZE];
    int l, il, pc;

    dorlpad_sqp(s, o, &c, &cbuf, &p, &pbuf, &l , &il, &pc);
    if (l>il && !status)
    {
	dopadding_sqp(l-il, p, o.val.string);
	bycopy(c, o.val.string+l-il, il);
	*(o.val.string+l)='\0';
    }
    pushresult_sqp(s, &o, pc);
}

/*
** rpad
*/
static void rpad_sqp(s)
fgw_stacktype *s;
{
    exprstack_t o;
    char *c, cbuf[STRINGCONVSIZE], *p, pbuf[STRINGCONVSIZE];
    int l, il, pc;

    dorlpad_sqp(s, o, &c, &cbuf, &p, &pbuf, &l , &il, &pc);
    if (l>il && !status)
    {
	bycopy(c, o.val.string, il);
	dopadding_sqp(l-il, p, o.val.string+il);
	*(o.val.string+l)='\0';
    }
    pushresult_sqp(s, &o, pc);
}

/*
** upper
*/
static void upper_sqp(s)
fgw_stacktype *s;
{
    int n;
    char *c, cbuf[STRINGCONVSIZE];
    exprstack_t *i, o;

    i=arglist_sqp(s, NULL);
    c=fgw_tostring(i, &cbuf, &n);
    if (o.val.string=fgw_smalloc(strlen(c)*2))
    {
	o.type=CSTRINGTYPE;
	if (n)
	    rsetnull(CSTRINGTYPE, o.val.string);
	else
	{
	    stcopy(c, o.val.string);
	    rupshift(o.val.string);
	}
    }
    else
	status=-208;
    pushresult_sqp(s, &o, 1);
}

/*
** lower
*/
static void lower_sqp(s)
fgw_stacktype *s;
{
    int n;
    char *c, cbuf[STRINGCONVSIZE];
    exprstack_t *i, o;

    i=arglist_sqp(s, NULL);
    c=fgw_tostring(i, &cbuf, &n);
    if (o.val.string=fgw_smalloc(strlen(c)*2))
    {
	o.type=CSTRINGTYPE;
	if (n)
	    rsetnull(CSTRINGTYPE, o.val.string);
	else
	{
	    stcopy(c, o.val.string);
	    rdownshift(o.val.string);
	}
    }
    else
	status=-208;
    pushresult_sqp(s, &o, 1);
}

/*
** initcap
*/
static void initcap_sqp(s)
fgw_stacktype *s;
{
    char *c, *ip, *op, cbuf[STRINGCONVSIZE];
    int notaletter, n;
    exprstack_t *i, o;

    i=arglist_sqp(s, NULL);
    c=fgw_tostring(i, &cbuf, &n);
    if (n)
	o.val.intvalue=0;
    else if (!(o.val.string=fgw_smalloc(stleng(c))))
	status=-208;
    else
    {
	o.type=CSTRINGTYPE;
	ip=c;
	op=o.val.string;
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
    pushresult_sqp(s, &o, 1);
}

/*
** expression stack ops
**
** returns first element in list, element count
*/
static exprstack_t *arglist_sqp(s, c)
fgw_stacktype *s;
int *c;
{
    exprstack_t *i;

    i=(exprstack_t *) fgw_stackpeek(s);
    if (c)
	*c=i->count;
    return i-i->count+1;
}

/*
** pops parameters, pushes return value
*/
static void pushresult_sqp(s, o, d)
fgw_stacktype *s;
exprstack_t *o;
int d;
{
    exprstack_t *i;
    int c;
 
    if (d)
    {
	i=(exprstack_t *) fgw_stackpeek(s);
	for (c=d; c; c--, i--)
	    fgw_freetssstack(i);
	fgw_stackdrop(s, d);
    }
    o->count=0;
    fgw_stackpush(s, o);
}

/*
** frees temporary memory on stack
*/
static void fgw_freetssstack(r1)
exprstack_t *r1;
{
    switch(r1->type)
    {
      case CSTRINGTYPE:
      case CINVTYPE:
      case CDTIMETYPE:
	if (r1->val.string)
	    fgw_tssfree(&pstate->exphead, r1->val.string);
    }
}

/*
** assigns stack contents to variable
*/
static void fgw_assign(s, v)
exprstack_t *s;
char *v;
{
    switch (s->type)
    {
      case CSTRINGTYPE:
      case FGWVAR:
	fgw_hstadd(pstate->vars, v, CSTRINGTYPE, s->val.string);
	break;
      case CDOUBLETYPE:
      case CINTTYPE:
      case CDATETYPE:
	fgw_hstadd(pstate->vars, v, s->type, (char *) &(s->val.real));
	break;
      default:
	fgw_hstadd(pstate->vars, v, s->type, (char *) s->val.datetime);
    }
}

/*
** scanner & parser hacks
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
    "exit", NULL, EXIT, 0, NULL,

    "display", NULL, DISPLAY, 0, NULL,
    "let", NULL, LET, 0, NULL,
    "load", NULL, LOAD, 0, NULL,
    "unload", NULL, UNLOAD, 0, NULL,
    "pipe", NULL, PIPE, 0, NULL,
    "append", NULL, APPEND, 0, NULL,
    "output", NULL, OUTPUT, 0, NULL,
    "whenever", NULL, WHENEVER, 0, NULL,

    "select", NULL, SELECT, 0, NULL,
    "insert", NULL, INSERT, 0, NULL,
    "delete", NULL, DELETE, 0, NULL,
    "update", NULL, UPDATE, 0, NULL,
    "execute", NULL, EXECUTE, 0, NULL,

    "create", NULL, CREATE, 0, NULL,
    "end", NULL, END, 0, NULL,
    "procedure", NULL, PROCEDURE, 0, NULL,
    "function", NULL, FUNCTION, 0, NULL,

    "default", NULL, DEFAULT, 0, NULL,
    "error", NULL, ERROR, 0, NULL,
    "stop", NULL, STOP, 0, NULL,

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
    "sqlcode", sqlcode_sqp, FNCT, 0, NULL,
    "sqlerrd1", sqlerrd1_sqp, FNCT, 0, NULL,
    "sqlerrd2", sqlerrd2_sqp, FNCT, 0, NULL,
    "errno", errno_sqp, FNCT, 0, NULL,

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
static int scanner_sql()
{
    char c;
    int r;
    tokenlist_t *t;

/* if we ever want to revert to true datetime/interval constant syntax,
   here's the place to

    if (pstate->parseroptions & DTHACK)
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
	    if (!(yylval.var=fgw_getvar(&(pstate->lexhead), pstate->tokstart,
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
		    fgw_tssfree(&pstate->lexhead, yylval.var);
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
			yylval.token=pstate->tokstart;
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
	    if (yylval.var=fgw_getstring(&(pstate->lexhead), pstate->tokstart,
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
	    if (yylval.stack.val.string=fgw_getstring(&(pstate->lexhead),
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
    pstate->tokstart=pstate->ibufp-1;
    return 0;
}

/*
** parser hacks
*/
static int yylex()
{
    static YYSTYPE svlval;
    YYSTYPE swlval;
    int t;

    if (prevtoken>=0)
    {
	t=prevtoken;
	prevtoken=-1;
	yylval=svlval;
	return t;
    }
    else if (pstate->parseroptions & (DMLHACK | SELECTHACK))
    {
	for(;;)
	{
	    t=scanner_sql();
	    switch (t)
	    {
/*
** we could actually postpone cleaning up those to when lexhead is dropped
** we do it here to avoid allocating needlessly memory
** FIXME: we could get scanner_sql to avoid allocating memory in the first place
*/
	      case VAR:
		fgw_tssfree(&pstate->lexhead, yylval.var);
		break;
	      case CNST:
		if (yylval.stack.type==CSTRINGTYPE)
		    fgw_tssfree(&pstate->lexhead, yylval.stack.val.string);
		break;
	      case INTO:
		if (pstate->parseroptions & DMLHACK)
		    break;
		swlval=yylval;
		t=scanner_sql();
		if (t==VAR)
		{
		    pstate->parseroptions&=~(DMLHACK | SELECTHACK);
		    prevtoken=t;
		    svlval=yylval;
		    yylval=swlval;
		    return INTO;
		}
		if (t==CNST && yylval.stack.type==CSTRINGTYPE)
		    fgw_tssfree(&pstate->lexhead, yylval.stack.val.string);
		break;
	      case FORMAT:
		if (pstate->parseroptions & DMLHACK)
		    break;
	      case USING:
	      case 0:
		pstate->parseroptions&=~(DMLHACK | SELECTHACK);
		return t;
	    }
	}
    }
    t=scanner_sql();
    if (pstate->parseroptions & SQLHACK)
    {
	pstate->parseroptions&=~SQLHACK;
	switch (t)
	{
	  case VAR:
	    t=SQLTOK;
	    break;
/*
** avoid one R/R conflict between create proc and create something else
*/
	  case CREATE:
	    prevtoken=scanner_sql();
	    if (prevtoken!=FUNCTION && prevtoken!=PROCEDURE)
		return SQLTOK;
	}
    }
    switch (t)
    {
      case INSERT:
      case DELETE:
      case UPDATE:
	pstate->parseroptions|=DMLHACK;
	break;
      case EXECUTE:
      case SELECT:
	pstate->parseroptions|=SELECTHACK;
	pstate->sqlstart=pstate->tokstart;
	break;
    }
    return t;
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
	if (newsz)
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
** expression related stuff
**
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
** compares r1 & r2 converting to type t first
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


#define _NO_FORM_X_H_

#include "a4gl_libaubit4gl.h"

#if HAVE_RPC_H
	#include <rpc/rpc.h>
#endif


#include "report.h"


/* ================ from lex.yy.c ============================ */
int buffpos(void);
#ifndef _NO_YYLEX_PROTO_
	int yylex ( void );
	//void yylex ( void );
#endif
void * memdup(void *p,int l);
void set_expr_int(struct expr *e,int a);


/* ================= from data.c ============================ */

void init_report (void);
void ace_add_variable (char *name, char *dstring, int category, int pno, int dtype, int dim);
void add_inputs (char *prompt, char *variable);
void add_function (char *name);
void add_select (char *sql, char *temptabname);
void execute_selects (void);
void print_lexpr(struct expr_list *l);
int find_variable (char *name);
int add_agg(struct agg_val agg) ;
int find_sql_var (int colno);

/* ================= from output.c =========================== */

void write_report (void);


/* ================= from main.c =========================== */

void yyerror (char *s);

/* ================== from y.tab.c ======================= */


#ifndef _NO_YYPARSE_PROTO_
	/* int yyparse (void *); */
	int yyparse (void);
#endif


/* =================== from tables.c ====================== */

void reset_sql_stuff(void);
void add_select_column(char *colname,char *alias);
void check_sql_columns(void);
// /opt/aubit/aubit4glsrc/incl/a4gl_API_form.h:129: warning: previous declaration of `add_table'
//had to rename function:
int ace_add_table (char *tabname, char *alias);


/* =================== from fileio.c ========================= */


int compile_ace_report (char *filename);




/* ============================== EOF =================================== */


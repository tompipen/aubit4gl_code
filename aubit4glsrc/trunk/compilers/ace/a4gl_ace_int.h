
#define _NO_FORM_X_H_

#include "a4gl_libaubit4gl.h"


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
void add_variable (char *name, char *dstring, int category, int pno, int dtype, int dim);
void add_inputs (char *prompt, char *variable);
void add_function (char *name);
void add_select (char *sql, char *temptabname);
void execute_selects (void);
void print_lexpr(struct expr_list *l);
int find_variable (char *name);


/* ================= from output.c =========================== */

void write_report (void);


/* ================= from main.c =========================== */

void yyerror (char *s);

/* ================== from y.tab.c ======================= */


#ifndef _NO_YYPARSE_PROTO_
	/* int yyparse (void *); */
	int yyparse (void);
#endif


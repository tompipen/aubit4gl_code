


#include "a4gl_libaubit4gl.h"


/* ============== from a4gl_fcomp_fcompile.h ======================= */



	/* ====================== From formwrite2.c ====================== */
	/* char *       char_val                (char *s); */

	/* ===================== From screen.lex ========================= */
int buffpos (void);

#ifndef _BISON_SIMPLE_INCL_
		/* ===================== From y.tab.c ============================ */
int yyparse (void);
		/* ====================== From fcompile.c ======================== */
int yywrap (void);
#endif
int yylex (void);

	/* ====================== From fcompile.c ======================== */
void yyerror (char *s);



/* ====================== from a4gl_fcomp_where.h ================== */

t_expression *create_field_expr (char *fieldname);
t_expression *create_int_expr (long intval);
t_expression *create_char_expr (char *charval);
t_expression *create_special_expr (char *charval);
t_expression *create_not_expr (t_expression * expr);
t_expression *create_list_expr (void);
t_expression *create_expr_expr (t_complex_expr * expr);
t_expression *create_expr_comp_expr (t_expression * expr1,
				     t_expression * expr2, char *comp);
t_expression *add_list_expr (t_expression * ptr, t_expression * expr);

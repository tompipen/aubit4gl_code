//	#define __GNU_LIBRARY__
	#include <getopt.h> 			/* struct option */

#include "a4gl_libaubit4gl.h"

	#include "rules/generated/kw.h"
	
	#ifndef _NO_Y_TAB_H_
		#include "rules/generated/y.tab.h"
    #endif

//	#include "kw.h"
//	#include "y.tab.h"




/* ==================== from a4gl_4glc_4glc.h ===================== */


	/* =========================== Implemented in 4glc.c ================= */
	void 	rm_quote			(char *s);
	int 	read_globals		(char *fname);
	void 	rm_quotes 			(char *s);
	void 	adderr 				(char *s, char *p, char *q);
	int 	only_doing_globals 	(void);
	int 	isGenStackInfo		(void);
	void 	yyerror 			(char *s);


	/* ========================== Implemented in lexer.c ================= */
	#include <stdio.h>
	int 	mja_fgetc 			(FILE * f);
	void 	turn_state 			(int kw, int v);
	int 	yylex 				(void);

	/* ========================== Implemented in list.c ================== */
	char *	list_prompt 		(char *s);
	void 	list_prompt_many	(char *id, char *s);
	void 	list_prompt_single 	(char *id, char *s);
	void 	list_set_single 	(char *id, char *s);
	void 	list_append 		(char *id, char *id2, char *str);
	void 	list_copy 			(char *id, char *id2);
	void 	list_print_all		(void);
	char *	new_id 				(void);
	void 	list_columns 		(char *id, char *s);
	void 	list_set_plus 		(char *newid, char *cid1, char *cid2);
	void 	list_set_minus 		(char *newid, char *cid1, char *cid2);
	void 	list_in				(void);
	char * 	get_idents			(int a);

	/* =================== Implemented in mod.c ========================== */
	char *	get_report_stack_why(int a);
	char *	get_report_stack_whytype(int a);

	#ifdef OLD_INCL
		#include "a4gl_incl_4glhdr.h" /* struct rep_structure */
    #endif


	void 	resize_paper		(struct pdf_rep_structure *pdf_rep_struct);
	void 	clr_variable		(void);
	void 	inmod				(void);
	void 	setinc				(int a);
	void 	print_variables		(void);
	void 	push_name 			(char *a, char *n);
	void 	push_type 			(char *a, char *n, char *as);
	void 	push_record 		(void);
	void 	push_associate 		(char *a, char *b);
	void 	pop_associate 		(char *a);
	void 	add_link_to 		(char *tab, char *pkey);
	void 	pop_record 			(void);
	void 	push_command 		(int mn, int mnopt, char *a, char *b, char *c, char *hlp);
	int 	getinc				(void);
	long 	scan_variable 		(char *s);
	long 	isarrvariable 		(char *s);
	void    add_constant 		(char t, char *ptr, char *name);
	void 	set_4gl_vars		(void);
	void 	open_db 			(char *s);
	void 	push_like 			(char *t);
	void 	push_rectab 		(char *t);
	void 	dump_vars 			(void);
	void 	push_menu_title 	(char *s);
	void 	push_blockcommand 	(char *cmd_type);
	void 	add_continue_blockcommand (char *cmd_type);
	void 	pop_blockcommand 	(char *cmd_type);
	int 	in_command 			(char *cmd_type);
	void 	push_gen 			(int a, char *s);
	void 	pop_all_gen 		(int a, char *s);
	int 	start_bind 			(char i, char *var);
	int 	get_bind_cnt 		(char i);
	int 	add_bind 			(char i, char *var);
	int 	how_many_in_bind 	(char i);
	void 	continue_loop 		(char *cmd_type);
	void 	exit_loop 			(char *cmd_type);
	void 	push_report_block 	(char *why, char whytype);
	void 	init_report_structure (struct rep_structure *rep);
	int 	attr_code 			(char *s);
	void 	set_mod_level 		(int a);
	long 	get_variable_dets 	(char *s, int *type, int *arrsize,
			   int *size, int *level, char *arr);
	int 	scan_orderby 		(char *varname, int cnt);
	void 	pdf_init_report_structure (struct pdf_rep_structure *rep);
	/* #include "a4gl_oform.h" */ /* struct form_attr */

    #ifdef OLD_INCL
		#include "a4gl_aclform.h"  /* struct form_attr */
    #endif

	void 	reset_attrib 		(struct form_attr * form_attrib);
	void 	new_counter 		(void);
	int 	get_counter_val 	(void);
	void 	drop_counter		(void);
	int 	dec_counter 		(void);
	int 	inc_counter 		(void);
	int 	push_bind_rec 		(char *s, char bindtype);
	void 	reset_counter 		(void);
	void 	set_counter 		(int a);
	void 	inc_counter_by 		(int a);
	void 	start_arr_bind 		(char i, char *var);
	void 	push_construct 		(char *a, char *b);
	void 	reset_constr 		(void);
	char *	convstrsql 			(char *s);
	void 	read_glob 			(char *s);
	char *	upshift 			(char *a);
	char *	downshift 			(char *a);
	int 	add_report_agg 		(char t, char *s1, char *s2, int a);
	void 	set_curr_rep_name 	(char *s);
	char *	get_curr_rep_name 	(void);
	void 	set_curr_block 		(int a);
	void 	set_ingroup 		(void);
	void 	set_whento 			(char *p);
	void 	set_whenever 		(int c, char *p);
	void 	clr_function_constants (void);
	int 	check_for_constant 	(char *name, char *buff);
	int 	npush_menu 			(void);
	void 	pop_menu 			(void);
	int 	setrecord 			(char *s, char *t, char *c);
	int 	num_arr_elem 		(char *s);
	char *	change_arr_elem 	(char *s);
	int 	system_var 			(char *s);
	void 	inc_report_cnt 		(void);
	int 	last_var_is_linked 	(char *tabname, char *pklist);
	int 	linked_split 		(char *s, int a, char *buff);
	void 	set_pklist 			(char *s);
	char *	get_upd_using_notpk (void);
	char *	get_upd_using_queries (void);
	char *	ispdf 				(void);
	int 	print_push_rec 		(char *s, char *b);
	void 	expand_obind 		(void);
	#include "a4gl_4glc_compiledefs.h"	/* struct expr_str */
	void 	expand_bind 		(struct binding * bind, int btype, int cnt);
	char *	get_var_name 		(int z);
	void 	chk_init_var 		(char *s);
	void 	dump_expr 			(struct expr_str *orig_ptr);
	void *	new_expr 			(char *value);
	void *	append_expr 		(struct expr_str *orig_ptr, char *value);
	void *	append_expr_expr 	(struct expr_str *orig_ptr, struct expr_str *second_ptr);
	int 	length_expr 		(struct expr_str * ptr);
	void 	tr_glob_fname 		(char *s);
	void    add_ex_dtype		(char *sx);

	/* ====================== Implemented in map.c ======================= */
	void 	openmap 			(char *s);
	void 	addmap 				(char *t, char *s, char *w, int l, char *m);
	void 	closemap 			(void);


	/* =========================== dim.c ================================= */

	void 	dim_push_name 		(char *a, char *b);
	void 	dim_push_rectab 	(char *a);
	void 	dim_pop_record 		(void);
	void 	dim_push_record 	(void);
	void 	dim_pop_associate 	(char *a);
	void 	dim_push_associate 	(char *a, char *b);
	void 	dim_push_like 		(char *a);
	void 	dim_push_type 		(char *type, char *sz, char *arrsz);
	void 	dim_set_name 		(char *a);
	void 	push_dim 			(char *a);

	/* ==================== rules/generated/states.c ==================== */
	void 	start_state			(char *s,int on_off);
	void	init_states			(void);


	/* =========================== y.tab.c ============================== */
	void 	set_clobber			(char *c);

    #ifndef _BISON_SIMPLE_INCL_ /* defiend in /usr/lib/bison.simple */
		/* int     yyparse				(void); */
		#ifdef __GNUC__
			#ifdef YYPARSE_PARAM
				int yyparse (void *);
			#else
				int yyparse (void);
			#endif
		#endif
    #endif

	void    set_str				(char *s);
	void    set_hdrdbname		(char *s);
	char *  get_hdrdbname		(void);






#include "a4gl_libaubit4gl.h"

struct local_expr_list {
        listitem *expr_list;
        int nlist;
};


/* ============== from a4gl_fcomp_fcompile.h ======================= */



	/* ====================== From formwrite2.c ====================== */
	/* char *       A4GL_char_val                (char *s); */

	/* ===================== From screen.lex ========================= */
int buffpos (void);

#ifndef _BISON_SIMPLE_INCL_
		/* ===================== From y.tab.c ============================ */
int yyparse (void);
		/* ====================== From fcompile.c ======================== */
int yywrap (void);
#endif
char * downshift (char *a);
void clr_status(void);
void err_on_status(void);
int A4GL_check_compiled_form(void);
int yylex (int yystate);

	/* ====================== From fcompile.c ======================== */
void yyerror (char *s);
int A4GLF_open_db (char *s);
int A4GLF_getdatatype_fcompile (char *col, char *tab);



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

t_expression *
create_fcall(char *name, struct local_expr_list *el) ;

int doing_4gl(void );
//void dump_form_desc (struct_form * f,char *fname);
//void dump_global_4gl(void);
//void dump_common_4gl(void);
//void set_single_file_mode(void);
void new_layout_attribs(void);
void add_child(struct s_layout *parent, struct s_layout *child);
void add_bool_layout_attrib(enum FIELD_ATTRIBUTES_BOOL attrib);
void add_str_layout_attrib(enum FA_ATTRIBUTES_STRING attrib, char *value);
struct s_layout_attributes *get_layout_attrib(void );
char *fcompile_find_table(char*tabname);
char *process_include(char *s) ;

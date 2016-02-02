#include <stdio.h>

#define KW_IDENTIFIER 258
#define KW_CONSTANT 259
#define KW_STRING_LITERAL 260
#define KW_INSERT 261
#define KW_SELECT 262
#define KW_DELETE 263
#define KW_UPDATE 264
#define KW_OBRACE 265
#define KW_CBRACE 266
#define KW_SEMI 267
#define KW_SPACE 268
#define KW_CHAR 269
#define KW_NL 270
#define KW_MINUS_MINUS  271
#define KW_INTO 272
#define KW_TEMP 273
#define KW_WHERE 274
#define KW_LOAD 275
#define KW_UNLOAD 276
#define KW_DELIMITER 277
#define KW_INFO_COL 278
#define KW_INFO_STAT 279
#define KW_INFO_IDX 280
#define KW_INFO_TABLES 281
#define KW_INFO_PRIV 282
#define KW_EXPLAIN 283
#define KW_CREATE_PROCEDURE 284
#define KW_END_PROCEDURE 285
#define KW_OUTPUT_TO_PIPE 286
#define KW_OUTPUT_TO 287
#define KW_WITHOUT_HEADINGS 288
#define KW_FILENAME 289

struct element {
	int lineno;
	char type;
	char *stmt;
	char *delim;
	char *fname;
	int with_headings;
};


#ifdef EXTERN_YYLVAL
extern
#endif


union  {
	char str[20000];
	char *s;
	struct element elem;
} yylval;






//int asql_unload_data(struct element *e,int *errat);
//int asql_load_data(struct element *e,int *errat);




FILE *get_curr_mvfin (char *lv_type);
char *escape_delim(char *s);
char *get_delim_flag(void);
char *get_qry_msg(int qry_type, int n);
char *get_tmp_dir(void);
char *make_sql_string(char *first, ...);
int DetermineEndianNess(void);
int asql_explain(struct element *e);
int asql_info(struct element *e);
int asql_load_data(struct element *e, int *err_at_col);
int asql_unload_data(struct element *e, int *errat);
int can_do_unload(void);
int charcpy(unsigned char *target, unsigned char *source, long len);
int do_mode_1(void);
int do_unload(struct element *e, long *raffected);
int ec_check_and_report_error(void);
int execute_query_1(int *raffected, int *errat);
int execute_select_free(void);
int execute_select_prepare(int *err_at_col, int type, int *hasrows);
int execute_sql_fetch(int *raffected, int *err_at_col);
int get_exec_mode_c(void);
int get_heading_flag(void);
int get_isam_error(void);
int get_sqlcode(void);
int get_type_id(char *s);
int isSqlError(void);
int is_echo_c(void);
int isdump(char s);
int isneed_fname(int a);
int load_err(int row, char *msg);
int main(int argc, char *argv[]);
int not_blank(char *s);
int prepare_query_1(char *s, char type, int *err_at_col);
int printField(FILE *outputFile, int idx, char *descName);
int read_only_mode(void);
int rewrite_query_input(int errline, int errcol, char *msg);
int run_q(int *err_at_colptr, int qry_type);
int set_outlines_c(char *fname);
int set_stdin_width(void);
int strip(char *str, int len);
void add_stmt(struct element *e);
void add_temp_file(char *s);
void bye(void);
void clean_up_temp_files(void);
void clr_stmt(void);
void count(void);
void cp_sqlca(void);
void display_mode_unload(int a);
void set_heading_flag(int n, char *delim);
void set_outfname(void);
void set_sqlcode(int n);
void stripnlload(char *s, char delim);
void trim_trailing_0(char *buffer);
void set_display_lines(void);
void open_display_file_c(void);

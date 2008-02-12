/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-2005 Aubit Development Team (See Credits file)    |
# +----------------------------------------------------------------------+
# | This program is free software; you can redistribute it and/or modify |
# | it under the terms of one of the following licenses:                 |
# |                                                                      |
# |  A) the GNU General Public License as published by the Free Software |
# |     Foundation; either version 2 of the License, or (at your option) |
# |     any later version.                                               |
# |                                                                      |
# |  B) the Aubit License as published by the Aubit Development Team and |
# |     included in the distribution in the file: LICENSE                |
# |                                                                      |
# | This program is distributed in the hope that it will be useful,      |
# | but WITHOUT ANY WARRANTY; without even the implied warranty of       |
# | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        |
# | GNU General Public License for more details.                         |
# |                                                                      |
# | You should have received a copy of both licenses referred to here.   |
# | If you did not, or have any questions about Aubit licensing, please  |
# | contact afalout@ihug.co.nz                                           |
# +----------------------------------------------------------------------+
#
# $Id: a4gl_4gl_callable.h,v 1.34 2008-02-12 12:46:58 mikeaubury Exp $
*/

/**
 * @file
 * Header file used to include in the generated c files with origin
 * in the 4gl source files.
 *
 * This file is NOT included from anywhere else - compile_c.c prints
 * include statemennt for this file when outputing C code that is result
 * of compiling 4gl code by 4glc
 *
 * Therefore, this file contains definitions and prototypes that are
 * needed ONLY when compiling/running compiled programs, and NOT anywhere else in
 * Aubit compiler or libraries code.
 *
 */

#ifndef FGLINCLDEF_INCL
#define FGLINCLDEF_INCL

#ifdef __cplusplus
extern "C"
{
#endif


#ifndef ALLOW_BOTH_LIB_AND_CALL
#ifdef _AUBIT_LIB_INCL_EXT_
#error a4gl_4gl_callable.h and a4gl_libaubit4gl.h should not be included together
#endif
#endif


/* #include "a4gl_API_esql.h" */
#include "a4gl_exdata.h"
#include "a4gl_API_exreport.h"
#include "a4gl_API_form.h"
#include "a4gl_API_help.h"
/* #include "a4gl_API_lex.h" */
#include "a4gl_API_menu.h"
//#include "a4gl_API_msg.h"
/* #include "a4gl_API_packer.h" */
#include "a4gl_API_rpc.h"
#include "a4gl_API_sql.h"
#include "a4gl_API_sqlparse.h"
#include "a4gl_API_ui.h"

int A4GLSQL_load_data (char *fname, char *delims, char *tabname, ...);
void A4GL_end_report_table (struct BINDING *b, int n, struct BINDING *reread);
void A4GL_skip_top_of_page (struct rep_structure *rep,int rep_end);
void A4GL_aclfgli_skip_lines (struct rep_structure *rep);
void A4GL_add_spaces (void);
void A4GL_add_row_report_table (struct BINDING *b, int n);
void A4GL_need_lines (struct rep_structure *rep);
int A4GL_chk_params (struct BINDING *b, int nb, struct BINDING *o, int no);
void A4GL_def_int (void);
void A4GL_def_quit (void);
void A4GL_make_report_table (struct BINDING *b, int n);
int A4GL_init_report_table (struct BINDING *b, int n, struct BINDING *o, int no, struct BINDING **reread,char *asc_desc);
void *A4GLSQL_prepare_glob_sql (char *s, int ni, void  *ibind);
struct s_sid * A4GLSQL_prepare_select (struct BINDING *ibind, int ni, struct BINDING *obind, int no, char *s,char *modname, int lineno,int converted, int singleton);


void A4GL_rep_file_print (struct rep_structure *rep, char *fname, int opt_semi);
void A4GL_rep_print (struct rep_structure *rep, int a, int s, int right_margin,int entry);
void A4GL_close_report_file(struct rep_structure *rep);
int A4GL_report_table_fetch (struct BINDING *reread, int n, struct BINDING *b);
void A4GL_set_column (struct rep_structure *rep);
void A4GL_set_help_file (char *fname);


#define ALREADY_DONE_POP_PUSH_ETC


// Sept 15 2006
int A4GL_get_a4gl_status (void);
void A4GLSQL_set_sqlerrd(int a0,int a1,int a2,int a3,int a4,int a5);
void A4GL_copy_sqlca_sqlawarn_8chars( char c0, char c1, char c2, char c3, char c4, char c5, char c6, char c7);
void A4GLSQL_set_sqlerrm (char *m, char *p);

//**********

double A4GL_pop_double(void);
double A4GL_pop_double_null_as_zero(void);
void A4GL_pop_into_double (double *d);
void A4GL_pop_into_double_null_as_zero(double *d );
int A4GL_pop_bool (void);
short A4GL_pop_int (void);
long A4GL_pop_long (void);
long A4GL_pop_date (void);
float A4GL_pop_float (void);
void A4GL_debug_full (char *fmt, ...);
void A4GL_debug_full_extended (char *fmt, ...);
int A4GL_pop_var (void *p, int d);
int A4GL_pop_var2 (void *p, int d, int s);
int A4GL_pop_char (char *z, int size);
int A4GL_pop_param (void *p, int d, int size);
void A4GL_pop_params (struct BINDING *b, int n);
void A4GL_push_param (void *p, int d);
void A4GL_push_user (void);
void A4GL_push_today (void);
void A4GL_push_params (struct BINDING *b, int n);
void A4GL_pop_args (int a);
int A4GL_set_line (char *s, long l);
int A4GL_set_line_extended (char *s, long l, const char *level, const char * func);
char *a4gl_substr (char *s, int dtype, int a, int b, ...);
void A4GL_push_dtime (struct A4GLSQL_dtime *p);
void A4GL_push_int (short p);
void A4GL_push_long (long p);
void A4GL_push_date (long p);
void A4GL_push_float (float p);
void A4GL_push_dec (char *p, int ismoney,int size);
void A4GL_push_double (double p);
void A4GL_push_chars (char *p, int dtype, int size);
void A4GL_push_empty_char(void);
void A4GL_push_char (char *p);
void A4GL_push_variable (void *ptr, int dtype);
void A4GL_push_interval (struct ival *p);
char *acl_getenv (char *);
void A4GL_pushop (int a);
void A4GL_push_null (int dtype,int size);
void A4GL_push_bind (struct BINDING *b, int n, int no, int elemsize);
void A4GL_push_bind_reverse (struct BINDING *b, int n, int no, int elemsize);
void A4GL_chk_err (int lineno, char *fname);
void A4GL_err_continue_log (int lineno, char *fname);

int A4GLSTK_isStackInfo (void);
char *A4GLSTK_getStackTrace (void);
void A4GLSTK_pushFunction (const char *functionName, char *params[], int n);
void A4GLSTK_popFunction (void);
void A4GL_fgl_end_4gl_0 (void);
void A4GL_fgl_end_4gl_1 (void); /* Used on interrupt */
void A4GL_display_at (int n, int a);
int A4GL_add_compiled_form (char *s, char *packer, char *formtype, char *frm);
int A4GLSQL_set_status (int a, int sql);
int A4GL_key_val(char *s);
int A4GL_internal_build (void);
char *A4GL_internal_version (void);
int aclfgl_aclfgl_setenv(int n);
int aclfgl_aclfgl_get_stack_trace(int n);
int A4GL_setenv(char *name, char *value, int overwrite);
int A4GL_isyes(char *s);
void A4GL_set_esql_connection(char *s);
char *A4GL_get_esql_connection(void);
void *A4GL_get_curr_report(void);
void A4GL_set_curr_report(void *);
void A4GL_debug_full_extended_ln (char *s, long l, const char *level, const char * func, char *fmt, ...);
//void A4GLSQL_map_tname(char *db, char *code);
//void A4GLSQL_unmap_tname(char *db);
//int A4GLSQL_is_tname_mapped(char *code);


#define A4GL_FUNCTION
#define A4GL_INTERNAL_FUNCTION
#define A4GL_MAIN
#define A4GL_REPORT


#ifdef __cplusplus
}
#endif
#endif				/* #ifndef FGLHDR_INCL */

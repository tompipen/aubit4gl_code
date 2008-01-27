
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
# $Id: expr.c,v 1.23 2008-01-27 15:15:17 mikeaubury Exp $
#
*/

/**
 * @file expr.c 
 * Compile time expression handling
 * there is a fairly good chance this can be moved to the 4glc/lib4glc sometime...
 *
 * @todo 
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_libaubit4gl_int.h"
#include "a4gl_expr.h"
#include <ctype.h>
#if HAVE_STRINGS_H
#include <strings.h>
#endif

#if HAVE_LIMITS_H
#include <limits.h>
#endif
#ifndef INT32_MAX
        #define INT32_MAX  2147483647
        #define INT32_MIN -2147483647-1
#endif


/*
=====================================================================
                    Variables definitions
=====================================================================
*/

/*
=====================================================================
                    Prototypes
=====================================================================
*/

char *expr_name(enum e_expr_type e) {
switch (e) {
//case ET_EXPR_CHAR: return "ET_EXPR_CHAR";
//case ET_EXPR_EXPR: return "ET_EXPR_EXPR";
case ET_EXPR_EXPR_LIST: return "ET_EXPR_EXPR_LIST";
//case ET_EXPR_OP: return "ET_EXPR_OP";
//case ET_EXPR_INT: return "ET_EXPR_INT";
//case ET_EXPR_NUM: return "ET_EXPR_NUM";
case ET_EXPR_STRING: return "ET_EXPR_STRING";
/* case ET_EXPR_PUSH_VARIABLE: return "ET_EXPR_PUSH_VARIABLE"; */
case ET_EXPR_TODAY: return "ET_EXPR_TODAY";
case ET_EXPR_TIME: return "ET_EXPR_TIME";
case ET_EXPR_LINENO: return "ET_EXPR_LINENO";
case ET_EXPR_PAGENO: return "ET_EXPR_PAGENO";
case ET_EXPR_TIME_EXPR: return "ET_EXPR_TIME_EXPR";
case ET_EXPR_DATE_EXPR: return "ET_EXPR_DATE_EXPR";
case ET_EXPR_NULL: return "ET_EXPR_NULL";
case ET_EXPR_TRUE: return "ET_EXPR_TRUE";
case ET_EXPR_FALSE: return "ET_EXPR_FALSE";
case ET_EXPR_NOT: return "ET_EXPR_NOT";
case ET_EXPR_UPSHIFT: return "ET_EXPR_UPSHIFT";
case ET_EXPR_DOWNSHIFT: return "ET_EXPR_DOWNSHIFT";
case ET_EXPR_EXTEND: return "ET_EXPR_EXTEND";
case ET_EXPR_ASCII: return "ET_EXPR_ASCII";
case ET_EXPR_MM: return "ET_EXPR_MM";
case ET_EXPR_POINTS: return "ET_EXPR_POINTS";
case ET_EXPR_INCHES: return "ET_EXPR_INCHES";
case ET_EXPR_CURRENT: return "ET_EXPR_CURRENT";
case ET_EXPR_OP_MULT: return "ET_EXPR_OP_MULT";
case ET_EXPR_OP_DIV: return "ET_EXPR_OP_DIV";
case ET_EXPR_OP_POWER: return "ET_EXPR_OP_POWER";
case ET_EXPR_OP_ADD: return "ET_EXPR_OP_ADD";
case ET_EXPR_OP_SUB: return "ET_EXPR_OP_SUB";
case ET_EXPR_OP_EQUAL: return "ET_EXPR_OP_EQUAL";
case ET_EXPR_OP_NOT_EQUAL: return "ET_EXPR_OP_NOT_EQUAL";
case ET_EXPR_OP_MOD: return "ET_EXPR_OP_MOD";
case ET_EXPR_OP_USING: return "ET_EXPR_OP_USING";
case ET_EXPR_OP_LIKE: return "ET_EXPR_OP_LIKE";
case ET_EXPR_OP_NOT_LIKE: return "ET_EXPR_OP_NOT_LIKE";
//case ET_EXPR_OP_LENGTH: return "ET_EXPR_OP_LENGTH";
case ET_EXPR_OP_IN: return "ET_EXPR_OP_IN";
case ET_EXPR_OP_CONCAT: return "ET_EXPR_OP_CONCAT";
case ET_EXPR_OP_MATCHES: return "ET_EXPR_OP_MATCHES";
case ET_EXPR_OP_NOT_MATCHES: return "ET_EXPR_OP_NOT_MATCHES";
case ET_EXPR_OP_CLIP: return "ET_EXPR_OP_CLIP";
case ET_EXPR_OP_LESS_THAN: return "ET_EXPR_OP_LESS_THAN";
case ET_EXPR_OP_LESS_THAN_EQ: return "ET_EXPR_OP_LESS_THAN_EQ";
case ET_EXPR_OP_GREATER_THAN: return "ET_EXPR_OP_GREATER_THAN";
case ET_EXPR_OP_GREATER_THAN_EQ: return "ET_EXPR_OP_GREATER_THAN_EQ";
case ET_EXPR_OP_YEAR: return "ET_EXPR_OP_YEAR";
case ET_EXPR_OP_MONTH: return "ET_EXPR_OP_MONTH";
case ET_EXPR_OP_DAY: return "ET_EXPR_OP_DAY";
case ET_EXPR_OP_HOUR: return "ET_EXPR_OP_HOUR";
case ET_EXPR_OP_MINUTE: return "ET_EXPR_OP_MINUTE";
case ET_EXPR_OP_SECOND: return "ET_EXPR_OP_SECOND";
case ET_EXPR_OP_ISNULL: return "ET_EXPR_OP_ISNULL";
case ET_EXPR_OP_ISNOTNULL: return "ET_EXPR_OP_ISNOTNULL";
case ET_EXPR_OP_SPACES: return "ET_EXPR_OP_SPACES";
case ET_EXPR_OP_AND: return "ET_EXPR_OP_AND";
case ET_EXPR_OP_OR: return "ET_EXPR_OP_OR";
case ET_EXPR_NEG: return "ET_EXPR_NEG";
case ET_EXPR_FCALL: return "ET_EXPR_FCALL";
case ET_EXPR_PDF_FCALL: return "ET_EXPR_PDF_FCALL";
case ET_EXPR_SHARED_FCALL: return "ET_EXPR_SHARED_FCALL";
case ET_EXPR_MEMBER_FCALL: return "ET_EXPR_MEMBER_FCALL";
case ET_EXPR_COLUMN: return "ET_EXPR_COLUMN";
case ET_EXPR_REPORT_EMAIL: return "ET_EXPR_REPORT_EMAIL";
case ET_EXPR_REPORT_PRINTER: return "ET_EXPR_REPORT_PRINTER";
case ET_EXPR_QUOTED_STRING: return "ET_EXPR_QUOTED_STRING";
case ET_EXPR_LITERAL_DOUBLE_STR: return "ET_EXPR_LITERAL_DOUBLE_STR";
case ET_EXPR_LITERAL_LONG: return "ET_EXPR_LITERAL_LONG";
case ET_EXPR_LITERAL_STRING: return "ET_EXPR_LITERAL_STRING";
case ET_EXPR_LITERAL_EMPTY_STRING: return "ET_EXPR_LITERAL_EMPTY_STRING";
case ET_EXPR_REDUCED: return "ET_EXPR_REDUCED";
case ET_EXPR_LAST: return "ET_EXPR_LAST";
case ET_EXPR_EXTERNAL: return "ET_EXPR_EXTERNAL";
case ET_EXPR_GET_FLDBUF: return "ET_EXPR_GET_FLDBUF";
case ET_EXPR_WORDWRAP: return "ET_EXPR_WORDWRAP";
//case ET_EXPR_SUBSTRING: return "ET_EXPR_SUBSTRING";
case ET_EXPR_OP_NOT_IN:return "ET_EXPR_OP_NOT_IN";
case ET_EXPR_NOT_EXISTS_SUBQUERY:return "ET_EXPR_NOT_EXISTS_SUBQUERY";
case ET_EXPR_EXISTS_SUBQUERY:return "ET_EXPR_EXISTS_SUBQUERY";
case ET_EXPR_OP_IN_SUBQUERY:return "ET_EXPR_OP_IN_SUBQUERY";
case ET_EXPR_OP_NOTIN_SUBQUERY:return "ET_EXPR_OP_NOTIN_SUBQUERY";
case ET_EXPR_CAST: return "ET_EXPR_CAST";
case ET_EXPR_CONCAT_LIST: return "ET_EXPR_CONCAT_LIST";
case ET_EXPR_YEAR_FUNC: return "ET_EXPR_YEAR_FUNC";
case ET_EXPR_MONTH_FUNC: return "ET_EXPR_MONTH_FUNC";
case ET_EXPR_DAY_FUNC: return "ET_EXPR_DAY_FUNC";
case ET_EXPR_DATE_FUNC: return "ET_EXPR_DATE_FUNC";
case ET_EXPR_DTVAL: return "ET_EXPR_DTVAL";
case ET_EXPR_TIME_FUNC: return "ET_EXPR_TIME_FUNC";
case ET_EXPR_INFIELD: return "ET_EXPR_INFIELD";
case ET_EXPR_NOT_FIELD_TOUCHED: return "ET_EXPR_NOT_FIELD_TOUCHED";
case ET_EXPR_FIELD_TOUCHED: return "ET_EXPR_FIELD_TOUCHED";
case ET_EXPR_IVAL_VAL: return "ET_EXPR_IVAL_VAL";
//case ET_EXPR_FCALL_SINGLE: return "ET_EXPR_FCALL_SINGLE";
case ET_EXPR_TEMP: return "ET_EXPR_TEMP";
case ET_EXPR_BOUND_FCALL: return "ET_EXPR_BOUND_FCALL";
case ET_EXPR_AGGREGATE: return "ET_EXPR_AGGREGATE";
case ET_EXPR_FGL_SIZEOF: return "ET_EXPR_FGL_SIZEOF";
case ET_EXPR_FGL_ADDRESSOF: return "ET_EXPR_FGL_ADDRESSOF";
case ET_EXPR_FGL_ISDYNARR_ALLOCATED: return "ET_EXPR_FGL_ISDYNARR_ALLOCATED";
case ET_EXPR_FGL_DYNARR_EXTENTSIZE: return "ET_EXPR_FGL_DYNARR_EXTENTSIZE";
case ET_EXPR_FIELDTOWIDGET: return "ET_EXPR_FIELDTOWIDGET";
case ET_EXPR_ID_TO_INT: return "ET_EXPR_ID_TO_INT";
case ET_EXPR_CACHED: return "ET_EXPR_CACHED";
case ET_EXPR_MENU_ALL: return "ET_EXPR_MENU_ALL";
case ET_EXPR_IDENTIFIER: return "ET_EXPR_IDENTIFIER";
case ET_EXPR_VARIABLE_IDENTIFIER: return "ET_EXPR_VARIABLE_IDENTIFIER";
//case ET_EXPR_PROMPT_RESULT: return "ET_EXPR_PROMPT_RESULT";
case ET_EXPR_MODULE_FUNC: return "ET_EXPR_MODULE_FUNC";



}
PRINTF("Expression Type : %d\n",e);
return "Oopps - dont know";
}
/* =========================== EOF ================================ */






struct expr_str_list *A4GL_new_ptr_list(struct expr_str *ptr) {
	struct expr_str_list *l;
	l=malloc(sizeof(struct expr_str_list));
	l->list.list_len=0;
	l->list.list_val=0;
	//l->nlist=0;
	if (ptr) A4GL_new_append_ptr_list(l,ptr);
	return l;

}




struct expr_str_list *A4GL_new_append_ptr_list(struct expr_str_list *l,struct expr_str *ptr) {
	        l->list.list_len++;
		l->list.list_val=realloc(l->list.list_val,sizeof(struct expr_str)*l->list.list_len);
		l->list.list_val[l->list.list_len-1]=ptr;
		return l;
}

int A4GL_new_list_get_count(struct expr_str_list *l) {
	        if (l==0) return 0;
		        return l->list.list_len;
}


// A list of expressions can contain another list -
//  a typical example might be
//  display "Hello",a.*
//  where a.* is some record which is expanded
//  Lets assume a is comprised of 'b' and 'c'
//  We'll end up with a list containing two entries :
//       "Hello"
//      LIST(a.b,a.c)
// 
//  At this point our list count would be 2
//  In most cases - we'd want to rationalize the list so that we have a list of expressions
//  which does *not* contain any further lists....
//  This function then converts to a list which does not contain any further lists
//  the above example would become a list containing 3 entried
//   "Hello"
//   a.b
//   a.c
//   
struct expr_str_list *A4GL_rationalize_list(struct expr_str_list *l) {
	int a;
	int b;
		struct expr_str_list *nl;
		struct expr_str_list *nl2;
		struct expr_str *p;
		if (l==0) return 0;


		nl=A4GL_new_ptr_list(0);
		A4GL_assertion( l->list.list_len>100000, "Dubious list length") ;
		for (a=0;a<l->list.list_len;a++) {
			p=l->list.list_val[a];
			if (p->expr_type==ET_EXPR_EXPR_LIST) { // We've got a list...
				nl2=A4GL_rationalize_list(p->expr_str_u.expr_list);
				for (b=0;b<nl2->list.list_len;b++) {
					A4GL_new_append_ptr_list(nl,nl2->list.list_val[b]);
				}
			} else {
				A4GL_new_append_ptr_list(nl,l->list.list_val[a]);
			}
		}

		free(l->list.list_val); // We've made our copy - so we can get rid of this now...

		l->list.list_len=nl->list.list_len;
		l->list.list_val=nl->list.list_val;
		return l;
}


struct expr_str_list *A4GL_new_prepend_ptr_list(struct expr_str_list *l,struct expr_str *p) {
	struct expr_str **old_list;
	int a;
	l->list.list_len++;
	old_list=l->list.list_val;
	l->list.list_val=malloc(sizeof(struct expr_str)*l->list.list_len);
	l->list.list_val[0]=p;
	for (a=1;a<l->list.list_len;a++) {
		l->list.list_val[a]=old_list[a-1];
	}
	free(old_list);
	return l;
}


/*
struct expr_str *A4GL_new_substring_expr (expt_str *str,long str_len,expr_str *ptr_s, expr_str *ptr_e,int type) {
  struct expr_str *ptr;
    ptr=A4GL_new_expr_simple(ET_EXPR_SUBSTRING);
    ptr->expr_str_u.expr_substring=malloc(sizeof(struct s_expr_substring));
    ptr->expr_str_u.expr_substring->str=str;
    ptr->expr_str_u.expr_substring->len=str_len;
    if (ptr_s[0]==' ') ptr_s++;
    ptr->expr_str_u.expr_substring->substring_start=acl_strdup(ptr_s);
    A4GL_trim(ptr->expr_str_u.expr_substring->substring_start);
    if (ptr_e[0]==' ') ptr_e++;
    ptr->expr_str_u.expr_substring->substring_end=acl_strdup(ptr_e);
    A4GL_trim(ptr->expr_str_u.expr_substring->substring_end);
    ptr->expr_str_u.expr_substring->type=type;
  return ptr;
}
*/


struct expr_str *A4GL_new_op_expr(struct expr_str *left, struct expr_str *right, enum e_expr_type type, struct expr_str *escape) {
  struct expr_str *ptr;
  ptr=A4GL_new_expr_simple(type);
  ptr->expr_str_u.expr_op=malloc(sizeof(struct s_expr_op));
  ptr->expr_str_u.expr_op->left=left;
  ptr->expr_str_u.expr_op->right=right;
  ptr->expr_str_u.expr_op->escape=escape;
  return ptr;
}



struct expr_str *A4GL_new_literal_double_str (char *value)
{
  struct expr_str *ptr;
  ptr=A4GL_new_expr_simple (ET_EXPR_LITERAL_DOUBLE_STR);
  ptr->expr_str_u.expr_string=acl_strdup(value);
  return ptr;
}

struct expr_str *A4GL_new_quoted_string (char *value)
{
  struct expr_str *ptr;
  ptr=A4GL_new_expr_simple (ET_EXPR_QUOTED_STRING);
  ptr->expr_str_u.expr_string=acl_strdup(value);
  return ptr;
}


struct expr_str *A4GL_new_literal_long_str (char *value)
{
  struct expr_str *ptr;
  FILE *f;
  long l;

  ptr=A4GL_new_expr_simple (ET_EXPR_LITERAL_LONG);
  l=atol(value);

  if (sizeof(l)>4) { // 64 bit..
        if (l<INT32_MIN || l>INT32_MAX) {
                l=LONG_MAX;
        }
  }


  ptr->expr_str_u.expr_long=l;

  if (A4GL_isyes(acl_getenv("LOG_STRINGS"))) {
	if (value[0]=='"') {
		f=fopen("/tmp/strings.log","w");
		if (f) FPRINTF(f,"%s\n",value);
		fclose(f);
	}
  }

  return ptr;
}


struct expr_str *A4GL_new_expr_agg (char type,int nagg, expr_str *s1, expr_str *s2, int in_group, int blockid)
{
  struct expr_str *ptr;
  ptr=A4GL_new_expr_simple (ET_EXPR_AGGREGATE);
  ptr->expr_str_u.expr_agg=malloc(sizeof(struct s_expr_agg));
  ptr->expr_str_u.expr_agg->agg_type=type;
	printf("nagg=%d\n",nagg);
  ptr->expr_str_u.expr_agg->expr_num=nagg;
  ptr->expr_str_u.expr_agg->in_group=in_group;
  ptr->expr_str_u.expr_agg->agg_expr=s1;
  ptr->expr_str_u.expr_agg->expr_where=s2;
  ptr->expr_str_u.expr_agg->blockid=blockid;
  return ptr;
}

struct expr_str *A4GL_new_literal_long_long (long value)
{
  struct expr_str *ptr;
  ptr=A4GL_new_expr_simple (ET_EXPR_LITERAL_LONG);
  ptr->expr_str_u.expr_long=value;
  return ptr;
}

struct expr_str *A4GL_new_expr_temp(char *s,int dtype) {
  struct expr_str *ptr;
  ptr=A4GL_new_expr_simple (ET_EXPR_TEMP);
  ptr->expr_str_u.expr_tmp=malloc(sizeof (struct s_expr_tmp));
  ptr->expr_str_u.expr_tmp->str=acl_strdup(s);
  ptr->expr_str_u.expr_tmp->dtype=dtype;
  return ptr;
}

struct expr_str * A4GL_new_translated_string (char *value) {
  struct expr_str *ptr;
  ptr=A4GL_new_expr_simple (ET_EXPR_TRANSLATED_STRING);
  ptr->expr_str_u.expr_string=acl_strdup(value);
  return ptr;
}


struct expr_str *A4GL_new_literal_string (char *value)
{
  struct expr_str *ptr;
int a;
int l;
  ptr=A4GL_new_expr_simple (ET_EXPR_LITERAL_STRING);

  ptr->expr_str_u.expr_string=acl_strdup(value);
	l=strlen(ptr->expr_str_u.expr_string);
	for (a=0;a<l;a++) {
		if (ptr->expr_str_u.expr_string[a]=='\t') ptr->expr_str_u.expr_string[a]=' ';
	}
  return ptr;
}


struct expr_str *A4GL_new_literal_empty_str (void)
{
  struct expr_str *ptr;
  ptr=A4GL_new_expr_simple (ET_EXPR_LITERAL_EMPTY_STRING);
  return ptr;
}

struct expr_str *A4GL_new_expr_neg(struct expr_str *ptr) {
struct expr_str *ptr_new;

if (ptr->expr_type==ET_EXPR_LITERAL_LONG) {
	ptr->expr_str_u.expr_long=0-ptr->expr_str_u.expr_long;
	return ptr;
}

if (ptr->expr_type==ET_EXPR_LITERAL_DOUBLE_STR) {
	char buff[256];
	SPRINTF1(buff,"-%s",ptr->expr_str_u.expr_string);
	ptr->expr_str_u.expr_string=acl_strdup(buff);
	return ptr;
}


ptr_new=A4GL_new_expr_simple_expr(ptr,ET_EXPR_NEG);
return ptr_new;

}

struct expr_str *A4GL_new_expr_simple_expr(struct expr_str *ptr,enum e_expr_type type) {
      struct expr_str *ptr_new;
      ptr_new=A4GL_new_expr_simple (type);
      ptr_new->expr_str_u.expr_expr=ptr;
      return ptr_new;
}


struct expr_str *A4GL_new_expr_simple_string(char *str,enum e_expr_type type) {
      struct expr_str *ptr_new;
      ptr_new=A4GL_new_expr_simple (type);
      ptr_new->expr_str_u.expr_string=strdup(str);
      return ptr_new;
}



struct expr_str *A4GL_new_expr_simple (enum e_expr_type type)
{
  struct expr_str *ptr;
  ptr = acl_malloc2 (sizeof (struct expr_str));
  memset(ptr,0,sizeof(struct expr_str));
  //ptr->next = 0;
  ptr->expr_type=type;
  return ptr;
}


struct expr_str *A4GL_new_expr_push_variable(struct variable_usage *v) {
//struct s_expr_push_variable *p;
struct expr_str *p2;
	//p=malloc(sizeof(struct s_expr_push_variable));
        p2=A4GL_new_expr_simple (ET_EXPR_VARIABLE_USAGE);
	//p->variable=v;
	//p->var_dtype=dtype;
	//p->scope=scope;
	p2->expr_str_u.expr_variable_usage=v;

	//inc_var_usage(v);

	return p2;
}

struct expr_str *A4GL_new_select_list_item_expr(struct s_select_list_item *s) {
	struct expr_str *p2;
        p2=A4GL_new_expr_simple (ET_EXPR_SELECT_LIST_ITEM);
	p2->expr_str_u.sl_item=s;
	return p2;
}

struct expr_str *A4GL_new_concat_list(struct expr_str_list *params) {
	struct expr_str *p2;
        p2=A4GL_new_expr_simple (ET_EXPR_CONCAT_LIST);
	p2->expr_str_u.expr_list=params;

	return p2;
}


struct expr_str *A4GL_new_datetime_expr(char *str, int extent) {
	struct s_expr_datetime *p;
	struct expr_str *p2;
	p=malloc(sizeof(struct s_expr_datetime));
	p2=A4GL_new_expr_simple (ET_EXPR_DTVAL);
	p->dtval=acl_strdup(str);
	p->extend=extent;
	p2->expr_str_u.expr_datetime=p;
	return p2;
}


struct expr_str *A4GL_new_interval_expr(char *str, int extent) {
	struct s_expr_interval *p;
	struct expr_str *p2;
	p=malloc(sizeof(struct s_expr_interval));
	p2=A4GL_new_expr_simple (ET_EXPR_IVAL_VAL);
	p->intval=acl_strdup(str);
	p->extend=extent;
	p2->expr_str_u.expr_interval=p;
	return p2;
}

struct expr_str *A4GL_new_expr_current(int from, int to) {
	struct s_expr_current *p;
	struct expr_str *p2;
	p=malloc(sizeof(struct s_expr_current));
	p2=A4GL_new_expr_simple (ET_EXPR_CURRENT);
	p->from=from;
	p->to=to;
	p2->expr_str_u.expr_current=p;
	return p2;
}



struct expr_str *A4GL_new_expr_fcall(char *function,struct expr_str_list *params,char *mod,int line,char *p_namespace) {
struct s_expr_function_call *p;
struct expr_str *p2;
	p=malloc(sizeof(struct s_expr_function_call));
        p2=A4GL_new_expr_simple (ET_EXPR_FCALL);
	p->fname=acl_strdup(function);
	p->parameters=A4GL_rationalize_list(params);
	p->namespace=p_namespace;
	p->module=mod;
	p->line=line;
	p2->expr_str_u.expr_function_call=p;
	return p2;
}

struct expr_str *A4GL_new_expr_pdf_fcall(char *function,struct expr_str_list *params,char *mod,int line,char *p_namespace) {
struct s_expr_pdf_function_call *p;
struct expr_str *p2;
	p=malloc(sizeof(struct s_expr_function_call));
        p2=A4GL_new_expr_simple (ET_EXPR_PDF_FCALL);
	p->fname=acl_strdup(function);
	p->parameters=params;
	p->namespace=p_namespace;
	p->module=mod;
	p->line=line;
	p2->expr_str_u.expr_pdf_function_call=p;
	return p2;
}

struct expr_str *A4GL_new_expr_field_touched(int sid, struct fh_field_list *fl,char *mod,int line) {
struct s_expr_field_touched *p;
struct expr_str *p2;
	p=malloc(sizeof(struct s_expr_field_touched));
        p2=A4GL_new_expr_simple (ET_EXPR_FIELD_TOUCHED);
	p->sio_id=sid;
	p->field_list=fl;
	p->module=mod;
	p->line=line;
	p2->expr_str_u.expr_field_touched=p;
	return p2;
}

struct expr_str *A4GL_new_expr_not_field_touched(int sid, struct fh_field_list *fl,char *mod,int line) {
struct s_expr_field_touched *p;
struct expr_str *p2;
	p=malloc(sizeof(struct s_expr_field_touched));
        p2=A4GL_new_expr_simple (ET_EXPR_NOT_FIELD_TOUCHED);
	p->sio_id=sid;
	p->field_list=fl;
	p->module=mod;
	p->line=line;
	p2->expr_str_u.expr_field_touched=p;
	return p2;
}


struct expr_str *A4GL_new_expr_get_fldbuf(int sid, struct fh_field_list *fl,char *mod,int line) {
struct s_expr_get_fldbuf *p;
struct expr_str *p2;
	p=malloc(sizeof(struct s_expr_get_fldbuf));
        p2=A4GL_new_expr_simple (ET_EXPR_GET_FLDBUF);
	p->sio_id=sid;
	p->field_list=fl;
	p->module=mod;
	p->line=line;
	p2->expr_str_u.expr_get_fldbuf=p;
	return p2;
}



struct expr_str *A4GL_new_expr_infield(int sid, struct fh_field_list *fl,char *mod,int line) {
struct s_expr_infield *p;
struct expr_str *p2;
	p=malloc(sizeof(struct s_expr_infield));
        p2=A4GL_new_expr_simple (ET_EXPR_INFIELD);
	p->sio_id=sid;
	p->field_list=fl;
	p->module=mod;
	p->line=line;
	p2->expr_str_u.expr_infield=p;
	return p2;
}


struct expr_str *A4GL_new_expr_wordwrap(struct expr_str *ptr,expr_str *wrap_at) {
	struct s_expr_wordwrap *p;
	struct expr_str *p2;
	p=malloc(sizeof(struct s_expr_wordwrap));
        p2=A4GL_new_expr_simple (ET_EXPR_WORDWRAP);
	p->expr=ptr;
	p->wrap_at=wrap_at;
	p2->expr_str_u.expr_wordwrap=p;
	return p2;
}

struct expr_str *A4GL_new_expr_extend(struct expr_str *ptr,int to) {
	struct s_expr_extend *p;
	struct expr_str *p2;
	p=malloc(sizeof(struct s_expr_extend));
        p2=A4GL_new_expr_simple (ET_EXPR_EXTEND);
	p->expr=ptr;
	p->to=to;
	p2->expr_str_u.expr_extend=p;
	return p2;
}

struct expr_str *A4GL_new_expr_member_fcall(struct expr_str *var_usage_ptr,struct expr_str_list *params,char *mod,int line,char *p_namespace) {
struct s_expr_member_function_call *p;
struct expr_str *p2;
	p=malloc(sizeof(struct s_expr_member_function_call));
        p2=A4GL_new_expr_simple (ET_EXPR_MEMBER_FCALL);
	p->var_usage_ptr=var_usage_ptr;
	p->parameters=params;
	p->namespace=strdup(p_namespace);
	p->module=strdup(mod);
	p->line=line;
	p2->expr_str_u.expr_member_function_call=p;
	return p2;
}


struct expr_str *A4GL_new_expr_bound_fcall(char *lib, char *function,char *mod,int line,expr_str *channel, expr_str_list *values, char *p_namespace) {
struct s_expr_bound_fcall *p;
struct expr_str *p2;
        p=malloc(sizeof(struct s_expr_bound_fcall));
        p2=A4GL_new_expr_simple (ET_EXPR_BOUND_FCALL);
	p->namespace=p_namespace;
        p->fname=acl_strdup(function);
        p->lib=acl_strdup(lib);
        p->module=mod;
        p->line=line;
	p->channel=channel;
	p->values=values;

	//p->nibind=l_ibindcnt;
	//p->ibind=malloc(sizeof(binding_comp_list));
	//p->ibind->bindings.bindings_len=l_ibindcnt;
	//memcpy(p->ibind->bindings.bindings_val,l_ibind,l_ibindcnt*sizeof(binding_comp));
//
	//p->ebind=malloc(sizeof(binding_comp_list));
	//p->ebind->bindings.bindings_len=l_ebindcnt;
	//memcpy(p->ebind->bindings.bindings_val,l_ebind,l_ebindcnt*sizeof(binding_comp));

        p2->expr_str_u.expr_bound_fcall=p;
        return p2;
}




struct expr_str *A4GL_new_expr_shared_fcall(char *lib, char *function,struct expr_str_list *params,char *mod,int line,char *p_namespace) {
struct s_expr_shared_function_call *p;
struct expr_str *p2;
	p=malloc(sizeof(struct s_expr_shared_function_call));
        p2=A4GL_new_expr_simple (ET_EXPR_SHARED_FCALL);
	p->fname=acl_strdup(function);
	p->namespace=p_namespace;
	p->lib=acl_strdup(lib);
	p->parameters=params;
	p->module=mod;
	p->line=line;
	p2->expr_str_u.expr_shared_function_call=p;
	return p2;
}

struct expr_str *A4GL_new_expr_call_external(char *host,char *func,expr_str *port,struct expr_str_list *params,int nowait,char *mod,int line,char *namespace) {
struct s_expr_external_call *p;
struct expr_str *p2;
	p=malloc(sizeof(struct s_expr_external_call));
        p2=A4GL_new_expr_simple (ET_EXPR_EXTERNAL);
	p->host=acl_strdup(host);
	p->func=acl_strdup(func);
	p->port=port;
	p->namespace=namespace;
	p->parameters=params;
	p->module=mod;
	p->line=line;
	p->without_waiting=nowait;
	p2->expr_str_u.expr_external_call=p;
	return p2;
}

struct expr_str *A4GL_new_expr_list () {
	struct expr_str *p;
        p=A4GL_new_expr_simple (ET_EXPR_EXPR_LIST);
	p->expr_str_u.expr_list= A4GL_new_ptr_list(0);
	return p;
}


struct expr_str *A4GL_expr_exists_sq(int invert,struct s_select * s) {
  int l;
  struct expr_str *ptr;
  if (invert) {
  	ptr=A4GL_new_expr_simple (ET_EXPR_EXISTS_SUBQUERY);
  } else {
  	ptr=A4GL_new_expr_simple (ET_EXPR_NOT_EXISTS_SUBQUERY);
  }
  ptr->expr_str_u.expr_exists_sq=malloc(sizeof(struct s_expr_exists_sq));
  ptr->expr_str_u.expr_exists_sq->subquery=s;

  //l=sizeof(struct binding_comp)*nbind;
  //ptr->expr_str_u.expr_exists_sq->ibind=malloc(l);
  //memcpy(ptr->expr_str_u.expr_exists_sq->ibind,b,l);

  //ptr->expr_str_u.expr_exists_sq->nibind=nbind;
  return ptr;
}


struct expr_str *A4GL_expr_in(struct expr_str *expr, int invert,struct expr_str_list *elist) {
  struct expr_str *ptr;


  if (invert) {
  	ptr=A4GL_new_expr_simple (ET_EXPR_OP_IN);
  } else {
  	ptr=A4GL_new_expr_simple (ET_EXPR_OP_NOT_IN);
  }
  ptr->expr_str_u.expr_in=malloc(sizeof(struct s_expr_in));
  ptr->expr_str_u.expr_in->expr=expr;
  ptr->expr_str_u.expr_in->elist=elist;

  return ptr;
}



struct expr_str *A4GL_expr_in_sq(struct expr_str *expr, int invert,struct s_select *s) {
  struct expr_str *ptr;
  long l;
  if (invert) {
  	ptr=A4GL_new_expr_simple (ET_EXPR_OP_IN_SUBQUERY);
  } else {
  	ptr=A4GL_new_expr_simple (ET_EXPR_OP_NOTIN_SUBQUERY);
  }
  ptr->expr_str_u.expr_in_sq=malloc(sizeof(struct s_expr_in_sq));
  ptr->expr_str_u.expr_in_sq->expr=expr;
  ptr->expr_str_u.expr_in_sq->subquery=s;

  //l=sizeof(struct binding_comp)*nbind;
  //ptr->expr_str_u.expr_in_sq->ibind=malloc(l);
  //memcpy(ptr->expr_str_u.expr_in_sq->ibind,b,l);
  //ptr->expr_str_u.expr_in_sq->nibind=nbind;
  return ptr;
}



/*****************************************************************************/
/* All code after here is OLD stuff which is badly written and bad to use    */
/* we should look at removing calls to these functions asap...               */
/*****************************************************************************/



#ifdef OLD

/**
 * Insert a new value to the expression.
 *
 * @param orig_expr
 * @param value
 * @return
 */
struct expr_str * 
A4GL_append_expr_obsol (struct expr_str *orig_ptr, char *value)
{
  struct expr_str *ptr;
  struct expr_str *start;
  start = orig_ptr;

  A4GL_debug ("MJA A4GL_append_expr %p (%s)", orig_ptr, value);

  ptr = A4GL_new_expr_obsol (value);
  if (orig_ptr->next != 0)
    {
      while (orig_ptr->next != 0)
        orig_ptr = orig_ptr->next;
    }
  orig_ptr->next = ptr;
  A4GL_debug ("Appended expr");
  //dump_expr(start);
  return start;
}



/**
 *  * Insert a new expression at the end of anoher one.
 *   *
 *    * @param orig_ptr The expression to be appended.
 *     * @param second_ptr The expression to append.
 *      */

void *
A4GL_append_expr_expr (struct expr_str *orig_ptr, struct expr_str *second_ptr)
{
  struct expr_str *start;


  if (orig_ptr==second_ptr) {
          struct expr_str *new_ptr;
          /* duplication of ourselves... */
          new_ptr=malloc(sizeof(struct expr_str));
          new_ptr->next=0;
          new_ptr->expr_type=orig_ptr->expr_type;

          switch(orig_ptr->expr_type) {
                  case ET_EXPR_STRING: new_ptr->expr_str_u.expr_char=acl_strdup(orig_ptr->expr_str_u.expr_char); break;
                  case ET_EXPR_LITERAL_DOUBLE_STR: new_ptr->expr_str_u.expr_char=acl_strdup(orig_ptr->expr_str_u.expr_char); break;
                  default : 
				       	PRINTF("%d - %s\n",orig_ptr->expr_type, expr_name(orig_ptr->expr_type));
				       	A4GL_assertion(1,"Unhandled expr copy");
          }
          return A4GL_append_expr_expr (new_ptr,orig_ptr);

  }
  A4GL_debug ("MJA A4GL_append_expr_expr %p %p", orig_ptr, second_ptr);
  start = orig_ptr;
  if (orig_ptr->next != 0)
    {
      while (orig_ptr->next != 0)
        orig_ptr = orig_ptr->next;
    }
  orig_ptr->next = second_ptr;
  /*dump_expr(start);*/
  return start;
}




/**
 *  * Checks and return the length of an expression
 *  *
 *  * @param ptr
 *  * @return The number of operands in an expression
 *  */
int
A4GL_length_expr (struct expr_str *ptr)
{
  int c = 0;
  A4GL_assertion(1,"No longer used");
  A4GL_debug ("Print expr... %p", ptr);
  while (ptr)
    {
      c++;
      ptr = ptr->next;
    }
  return c;
}
#endif


struct expr_str * 
A4GL_new_expr_obsol (char *value)
{
  struct expr_str *ptr;
  A4GL_debug ("new_expr - %s", value);


  A4GL_assertion(1,"Bad news - shouldn't be using A4GL_new_expr\n");

  ptr=A4GL_new_expr_simple (ET_EXPR_STRING);
  //ptr->next = 0;
  //ptr->expr_str_u.expr_char = acl_strdup (value);
  A4GL_debug ("newexpr : %s -> %p\n", value, ptr);
  return ptr;
}





int
A4GL_is_just_int_literal (expr_str * e, long val)
{
  if (e->expr_type == ET_EXPR_LITERAL_LONG)
    {
      if (e->expr_str_u.expr_long == val)
        return 1;
    }

  if (e->expr_type == ET_EXPR_TRUE  && val==1) {
		return 1;
	 }
  if (e->expr_type == ET_EXPR_FALSE  && val==0) {
		return 1;
	 }
  return 0;
}


int get_variable_dtype_from_variable_expression(expr_str *ptr) {
	//
	A4GL_assertion(1,"NIY");
}

int A4GL_is_just_expr_clipped(char *v,struct expr_str_list *ptr) {
        struct expr_str *p;
        if (ptr->list.list_len!=1) {
                return 0;
        }
        p=ptr->list.list_val[0];

        if (p->expr_type==ET_EXPR_OP_CLIP) {
                p=p->expr_str_u.expr_expr;
                if (p->expr_type==ET_EXPR_VARIABLE_USAGE) {
#ifdef FIXME
                        if (strcmp(p->expr_str_u.expr_variable_usage->variable,v)==0) {
                                return 1;
                        }
#endif
                }

        }
        return 0;
}


char *A4GL_expr_starts_with_single_string(struct expr_str_list *ptr) {
        struct expr_str *p;
        int a;
        char *buff=0;
        // LAST_STRING <- USE TO SEARCH...!

        if (ptr->list.list_len==1) {
                p=ptr->list.list_val[0];
                if (p->expr_type==ET_EXPR_VARIABLE_USAGE)        { return "Yes"; }
                if (p->expr_type==ET_EXPR_LITERAL_STRING)       { return p->expr_str_u.expr_string; }
                if (p->expr_type==ET_EXPR_LITERAL_EMPTY_STRING) { return ""; }
        }

        for (a=0;a<1;a++) {
                p=ptr->list.list_val[a];

                if (p->expr_type==ET_EXPR_OP_CLIP) {
                        p=p->expr_str_u.expr_expr; // We'll ignore any clipping for the sake of determining if its a single string...
                }

                if (p->expr_type==ET_EXPR_OP_USING) {
                        p=p->expr_str_u.expr_op->left; // We'll ignore any USING string and just use it as is..
                }

                if (p->expr_type==ET_EXPR_LITERAL_STRING) {
                        if (buff) {
                                        buff=realloc(buff,(strlen(buff)+strlen(p->expr_str_u.expr_string)+1));
                                        strcat(buff,p->expr_str_u.expr_string);
                        } else {
                                buff=strdup(p->expr_str_u.expr_string);
                        }
                        continue;
                }

                if (p->expr_type==ET_EXPR_VARIABLE_USAGE) {
                        // If we're using variables here - we really ought to store them somewhere
                        // as we're replacing them with a '?'
                        return 0;
                        if ((p->expr_str_u.expr_variable_usage ->datatype&DTYPE_MASK)==DTYPE_CHAR) { // Its a character strings
                                int sz;
                                sz=p->expr_str_u.expr_variable_usage->datatype>>16;
                                if (sz>10) {

                                        //printf("DTYPE : %x\n",p->expr_str_u.expr_variable_usage->datatype);
                                        return 0;
                                }
                        }
                        if (buff) {
                                        buff=realloc(buff,(strlen(buff)+1+1));
                                        strcat(buff,"`");
                        } else {
                                        buff=strdup("`");
                        }
                        continue;
                }

                //printf("Nope - %d. %d %s\n",a,p->expr_type,expr_name(p->expr_type));
                return 0;
        }

        return buff;
}




char *A4GL_expr_is_single_string(struct expr_str_list *ptr) {
        struct expr_str *p;
        int a;
        char *buff=0;
        // LAST_STRING <- USE TO SEARCH...!

        if (ptr->list.list_len==1) {
                p=ptr->list.list_val[0];
                if (p->expr_type==ET_EXPR_VARIABLE_USAGE)        { return "Yes"; }
                if (p->expr_type==ET_EXPR_LITERAL_STRING)       { return p->expr_str_u.expr_string; }
                if (p->expr_type==ET_EXPR_LITERAL_EMPTY_STRING) { return ""; }
        }

        for (a=0;a<ptr->list.list_len;a++) {
                p=ptr->list.list_val[a];

                if (p->expr_type==ET_EXPR_OP_CLIP) {
                        p=p->expr_str_u.expr_expr; // We'll ignore any clipping for the sake of determining if its a single string...
                }

                if (p->expr_type==ET_EXPR_OP_USING) {
                        p=p->expr_str_u.expr_op->left; // We'll ignore any USING string and just use it as is..
                }

                if (p->expr_type==ET_EXPR_LITERAL_STRING) {
                        if (buff) {
                                        buff=realloc(buff,(strlen(buff)+strlen(p->expr_str_u.expr_string)+1));
                                        strcat(buff,p->expr_str_u.expr_string);
                        } else {
                                buff=strdup(p->expr_str_u.expr_string);
                        }
                        continue;
                }

                if (p->expr_type==ET_EXPR_VARIABLE_USAGE) {
                        // If we're using variables here - we really ought to store them somewhere
                        // as we're replacing them with a '?'
                        return 0;
                        if ((p->expr_str_u.expr_variable_usage->datatype&DTYPE_MASK)==DTYPE_CHAR) { // Its a character strings
                                int sz;
                                sz=p->expr_str_u.expr_variable_usage->datatype>>16;
                                if (sz>10) {

                                        //printf("DTYPE : %x\n",p->expr_str_u.expr_variable_usage->datatype);
                                        return 0;
                                }
                        }
                        if (buff) {
                                        buff=realloc(buff,(strlen(buff)+1+1));
                                        strcat(buff,"`");
                        } else {
                                        buff=strdup("`");
                        }
                        continue;
                }

                //printf("Nope - %d. %d %s\n",a,p->expr_type,expr_name(p->expr_type));
                return 0;
        }

        return buff;
}
   

struct expr_str *
A4GL_new_variable_usage_with_asc_desc (expr_str * e, char *asc_desc)
{
  expr_str *ptr;
  ptr = A4GL_new_expr_simple (ET_EXPR_VARIABLE_USAGE_WITH_ASC_DESC);
  ptr->expr_str_u.expr_variable_usage_with_asc_desc = malloc (sizeof (struct variable_usage_with_asc_desc));
  A4GL_assertion (e->expr_type != ET_EXPR_VARIABLE_USAGE, "Unexpected expression type - should be a variable usage");

  ptr->expr_str_u.expr_variable_usage_with_asc_desc->var_usage =  malloc(sizeof(struct variable_usage));
  memcpy(ptr->expr_str_u.expr_variable_usage_with_asc_desc->var_usage, e->expr_str_u.expr_variable_usage,sizeof(struct variable_usage));

  if (asc_desc)
    {
      ptr->expr_str_u.expr_variable_usage_with_asc_desc->asc_desc = toupper (asc_desc[0]);
    }
  else
    {
      ptr->expr_str_u.expr_variable_usage_with_asc_desc->asc_desc = 'A';
    }

  return ptr;
}

char *expr_as_string(expr_str *s) {
//
A4GL_assertion(1,"FIXME");
return 0;
}

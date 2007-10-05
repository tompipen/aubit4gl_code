
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
# $Id: expr.c,v 1.20 2007-10-05 15:00:14 mikeaubury Exp $
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
#include <ctype.h>
#if HAVE_STRINGS_H
#include <strings.h>
#endif
struct binding_comp
{
	  char varname[132];
	    int dtype;
	      int start_char_subscript;
	        int end_char_subscript;
};
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
case ET_EXPR_PUSH_VARIABLE: return "ET_EXPR_PUSH_VARIABLE";
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
case ET_EXPR_SUBSTRING: return "ET_EXPR_SUBSTRING";
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
case ET_EXPR_FCALL_SINGLE: return "ET_EXPR_FCALL_SINGLE";
case ET_EXPR_TEMP: return "ET_EXPR_TEMP";
case ET_EXPR_BOUND_FCALL: return "ET_EXPR_BOUND_FCALL";
case ET_EXPR_AGGREGATE: return "ET_EXPR_AGGREGATE";
case ET_EXPR_FGL_SIZEOF: return "ET_EXPR_FGL_SIZEOF";
case ET_EXPR_FGL_ADDRESSOF: return "ET_EXPR_FGL_ADDRESSOF";
case ET_EXPR_FGL_ISDYNARR_ALLOCATED: return "ET_EXPR_FGL_ISDYNARR_ALLOCATED";
case ET_EXPR_FGL_DYNARR_EXTENTSIZE: return "ET_EXPR_FGL_DYNARR_EXTENTSIZE";
case ET_EXPR_FIELDTOWIDGET: return "ET_EXPR_FIELDTOWIDGET";
case ET_EXPR_ID_TO_INT: return "ET_EXPR_ID_TO_INT";
case ET_EXPR_PROMPT_RESULT: return "ET_EXPR_PROMPT_RESULT";
case ET_EXPR_MODULE_FUNC: return "ET_EXPR_MODULE_FUNC";



}
PRINTF("Expression Type : %d\n",e);
return "Oopps - dont know";
}
/* =========================== EOF ================================ */






struct expr_str_list *A4GL_new_ptr_list(struct expr_str *ptr) {
	struct expr_str_list *l;
	l=malloc(sizeof(struct expr_str_list));
	l->list=0;
	l->nlist=0;
	if (ptr) A4GL_new_append_ptr_list(l,ptr);
	return l;

}


struct expr_str_list *A4GL_new_append_ptr_list(struct expr_str_list *l,struct expr_str *ptr) {
	        l->nlist++;
		        l->list=realloc(l->list,sizeof(struct expr_str)*l->nlist);
			        l->list[l->nlist-1]=ptr;
				        return l;
}

int A4GL_new_list_get_count(struct expr_str_list *l) {
	        if (l==0) return 0;
		        return l->nlist;
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
		for (a=0;a<l->nlist;a++) {
			p=l->list[a];
			if (p->expr_type==ET_EXPR_EXPR_LIST) { // We've got a list...
				nl2=A4GL_rationalize_list(p->u_data.expr_list);
				for (b=0;b<nl2->nlist;b++) {
					A4GL_new_append_ptr_list(nl,nl2->list[b]);
				}
			} else {
				A4GL_new_append_ptr_list(nl,l->list[a]);
			}
		}

		free(l->list); // We've made our copy - so we can get rid of this now...

		l->nlist=nl->nlist;
		l->list=nl->list;
		return l;
}


struct expr_str_list *A4GL_new_prepend_ptr_list(struct expr_str_list *l,struct expr_str *p) {
	struct expr_str **old_list;
	int a;
	l->nlist++;
	old_list=l->list;
	l->list=malloc(sizeof(struct expr_str)*l->nlist);
	l->list[0]=p;
	for (a=1;a<l->nlist;a++) {
		l->list[a]=old_list[a-1];
	}
	free(old_list);
	return l;
}

struct expr_str *A4GL_new_substring_expr (char *str,long str_len,char *ptr_s, char *ptr_e,int type) {
  struct expr_str *ptr;
    ptr=A4GL_new_expr_simple(ET_EXPR_SUBSTRING);
    ptr->u_data.expr_substring=malloc(sizeof(struct expr_substring));
    ptr->u_data.expr_substring->str=acl_strdup(str);
    A4GL_trim( ptr->u_data.expr_substring->str);
    ptr->u_data.expr_substring->len=str_len;
    if (ptr_s[0]==' ') ptr_s++;
    ptr->u_data.expr_substring->substring_start=acl_strdup(ptr_s);
    A4GL_trim(ptr->u_data.expr_substring->substring_start);
    if (ptr_e[0]==' ') ptr_e++;
    ptr->u_data.expr_substring->substring_end=acl_strdup(ptr_e);
    A4GL_trim(ptr->u_data.expr_substring->substring_end);
    ptr->u_data.expr_substring->type=type;
  return ptr;
}


struct expr_str *A4GL_new_op_expr(struct expr_str *left, struct expr_str *right, enum e_expr_type type, struct expr_str *escape) {
  struct expr_str *ptr;
  ptr=A4GL_new_expr_simple(type);
  ptr->u_data.expr_op=malloc(sizeof(struct expr_op));
  ptr->u_data.expr_op->left=left;
  ptr->u_data.expr_op->right=right;
  ptr->u_data.expr_op->escape=escape;
  return ptr;
}



struct expr_str *A4GL_new_literal_double_str (char *value)
{
  struct expr_str *ptr;
  ptr=A4GL_new_expr_simple (ET_EXPR_LITERAL_DOUBLE_STR);
  ptr->u_data.expr_string=acl_strdup(value);
  return ptr;
}

struct expr_str *A4GL_new_quoted_string (char *value)
{
  struct expr_str *ptr;
  ptr=A4GL_new_expr_simple (ET_EXPR_QUOTED_STRING);
  ptr->u_data.expr_string=acl_strdup(value);
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

  ptr->u_data.expr_long=l;

  if (A4GL_isyes(acl_getenv("LOG_STRINGS"))) {
	if (value[0]=='"') {
		f=fopen("/tmp/strings.log","w");
		if (f) FPRINTF(f,"%s\n",value);
		fclose(f);
	}
  }

  return ptr;
}


struct expr_str *A4GL_new_expr_agg (char type,int nagg)
{
  struct expr_str *ptr;
  ptr=A4GL_new_expr_simple (ET_EXPR_AGGREGATE);
  ptr->u_data.expr_agg=malloc(sizeof(struct expr_agg));
  ptr->u_data.expr_agg->agg_type=type;
  ptr->u_data.expr_agg->expr_num=nagg;
  ptr->u_data.expr_agg->in_group=-1;
  return ptr;
}

struct expr_str *A4GL_new_literal_long_long (long value)
{
  struct expr_str *ptr;
  ptr=A4GL_new_expr_simple (ET_EXPR_LITERAL_LONG);
  ptr->u_data.expr_long=value;
  return ptr;
}

struct expr_str *A4GL_new_expr_temp(char *s,int dtype) {
  struct expr_str *ptr;
  ptr=A4GL_new_expr_simple (ET_EXPR_TEMP);
  ptr->u_data.expr_tmp=malloc(sizeof (struct expr_tmp));
  ptr->u_data.expr_tmp->str=acl_strdup(s);
  ptr->u_data.expr_tmp->dtype=dtype;
  return ptr;
}

struct expr_str *A4GL_new_literal_string (char *value)
{
  struct expr_str *ptr;
int a;
int l;
  ptr=A4GL_new_expr_simple (ET_EXPR_LITERAL_STRING);

  ptr->u_data.expr_string=acl_strdup(value);
	l=strlen(ptr->u_data.expr_string);
	for (a=0;a<l;a++) {
		if (ptr->u_data.expr_string[a]=='\t') ptr->u_data.expr_string[a]=' ';
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
	ptr->u_data.expr_long=0-ptr->u_data.expr_long;
	return ptr;
}
if (ptr->expr_type==ET_EXPR_LITERAL_DOUBLE_STR) {
	char buff[256];
	SPRINTF1(buff,"-%s",ptr->u_data.expr_char);
	ptr->u_data.expr_char=acl_strdup(buff);
	return ptr;
}


ptr_new=A4GL_new_expr_simple_expr(ptr,ET_EXPR_NEG);
return ptr_new;

}

struct expr_str *A4GL_new_expr_simple_expr(struct expr_str *ptr,enum e_expr_type type) {
      struct expr_str *ptr_new;
      ptr_new=A4GL_new_expr_simple (type);
      ptr_new->u_data.expr_expr=ptr;
      return ptr_new;
}


struct expr_str *A4GL_new_expr_simple_string(char *str,enum e_expr_type type) {
      struct expr_str *ptr_new;
      ptr_new=A4GL_new_expr_simple (type);
      ptr_new->u_data.expr_string=str;
      return ptr_new;
}



struct expr_str *A4GL_new_expr_simple (enum e_expr_type type)
{
  struct expr_str *ptr;
  ptr = acl_malloc2 (sizeof (struct expr_str));
  memset(ptr,0,sizeof(struct expr_str));
  ptr->next = 0;
  ptr->expr_type=type;
  return ptr;
}


struct expr_str *A4GL_new_expr_push_variable(char *v,long dtype) {
struct expr_push_variable *p;
struct expr_str *p2;
	p=malloc(sizeof(struct expr_push_variable));
        p2=A4GL_new_expr_simple (ET_EXPR_PUSH_VARIABLE);
	p->variable=acl_strdup(v);
	p->var_dtype=dtype;
	p2->u_data.expr_push_variable=p;
return p2;
}


struct expr_str *A4GL_new_concat_list(struct expr_str_list *params) {
	struct expr_str *p2;
        p2=A4GL_new_expr_simple (ET_EXPR_CONCAT_LIST);
	p2->u_data.expr_list=params;

	return p2;
}


struct expr_str *A4GL_new_datetime_expr(char *str, int extent) {
	struct expr_datetime *p;
	struct expr_str *p2;
	p=malloc(sizeof(struct expr_datetime));
	p2=A4GL_new_expr_simple (ET_EXPR_DTVAL);
	p->dtval=acl_strdup(str);
	p->extend=extent;
	p2->u_data.expr_datetime=p;
	return p2;
}


struct expr_str *A4GL_new_interval_expr(char *str, int extent) {
	struct expr_interval *p;
	struct expr_str *p2;
	p=malloc(sizeof(struct expr_interval));
	p2=A4GL_new_expr_simple (ET_EXPR_IVAL_VAL);
	p->intval=acl_strdup(str);
	p->extend=extent;
	p2->u_data.expr_interval=p;
	return p2;
}

struct expr_str *A4GL_new_expr_current(int from, int to) {
	struct expr_current *p;
	struct expr_str *p2;
	p=malloc(sizeof(struct expr_current));
	p2=A4GL_new_expr_simple (ET_EXPR_CURRENT);
	p->from=from;
	p->to=to;
	p2->u_data.expr_current=p;
	return p2;
}



struct expr_str *A4GL_new_expr_fcall(char *function,struct expr_str_list *params,char *mod,int line) {
struct expr_function_call *p;
struct expr_str *p2;
	p=malloc(sizeof(struct expr_function_call));
        p2=A4GL_new_expr_simple (ET_EXPR_FCALL);
	p->fname=acl_strdup(function);
	p->parameters=params;
	p->module=mod;
	p->line=line;
	p2->u_data.expr_function_call=p;
	return p2;
}


struct expr_str *A4GL_new_expr_field_touched(int sid, struct fh_field_list *fl,char *mod,int line) {
struct expr_field_touched *p;
struct expr_str *p2;
	p=malloc(sizeof(struct expr_field_touched));
        p2=A4GL_new_expr_simple (ET_EXPR_FIELD_TOUCHED);
	p->sio_id=sid;
	p->field_list=fl;
	p->module=mod;
	p->line=line;
	p2->u_data.expr_field_touched=p;
	return p2;
}

struct expr_str *A4GL_new_expr_not_field_touched(int sid, struct fh_field_list *fl,char *mod,int line) {
struct expr_field_touched *p;
struct expr_str *p2;
	p=malloc(sizeof(struct expr_field_touched));
        p2=A4GL_new_expr_simple (ET_EXPR_NOT_FIELD_TOUCHED);
	p->sio_id=sid;
	p->field_list=fl;
	p->module=mod;
	p->line=line;
	p2->u_data.expr_field_touched=p;
	return p2;
}


struct expr_str *A4GL_new_expr_get_fldbuf(int sid, struct fh_field_list *fl,char *mod,int line) {
struct expr_get_fldbuf *p;
struct expr_str *p2;
	p=malloc(sizeof(struct expr_get_fldbuf));
        p2=A4GL_new_expr_simple (ET_EXPR_GET_FLDBUF);
	p->sio_id=sid;
	p->field_list=fl;
	p->module=mod;
	p->line=line;
	p2->u_data.expr_get_fldbuf=p;
	return p2;
}



struct expr_str *A4GL_new_expr_infield(int sid, struct fh_field_list *fl,char *mod,int line) {
struct expr_infield *p;
struct expr_str *p2;
	p=malloc(sizeof(struct expr_infield));
        p2=A4GL_new_expr_simple (ET_EXPR_INFIELD);
	p->sio_id=sid;
	p->field_list=fl;
	p->module=mod;
	p->line=line;
	p2->u_data.expr_infield=p;
	return p2;
}


struct expr_str *A4GL_new_expr_wordwrap(struct expr_str *ptr,char *wrap_at) {
	struct expr_wordwrap *p;
	struct expr_str *p2;
	p=malloc(sizeof(struct expr_wordwrap));
        p2=A4GL_new_expr_simple (ET_EXPR_WORDWRAP);
	p->expr=ptr;
	p->wrap_at=acl_strdup(wrap_at);
	p2->u_data.expr_wordwrap=p;
	return p2;
}

struct expr_str *A4GL_new_expr_extend(struct expr_str *ptr,int to) {
	struct expr_extend *p;
	struct expr_str *p2;
	p=malloc(sizeof(struct expr_extend));
        p2=A4GL_new_expr_simple (ET_EXPR_EXTEND);
	p->expr=ptr;
	p->to=to;
	p2->u_data.expr_extend=p;
	return p2;
}

struct expr_str *A4GL_new_expr_member_fcall(char *lib,char *function,struct expr_str_list *params,char *mod,int line) {
struct expr_member_function_call *p;
struct expr_str *p2;
	p=malloc(sizeof(struct expr_member_function_call));
        p2=A4GL_new_expr_simple (ET_EXPR_MEMBER_FCALL);
	p->lib=acl_strdup(lib);
	p->fname=acl_strdup(function);
	p->parameters=params;
	p->module=mod;
	p->line=line;
	p2->u_data.expr_member_function_call=p;
	return p2;
}


struct expr_str *A4GL_new_expr_bound_fcall(char *lib, char *function,char *mod,int line,int l_ibindcnt,void *l_ibind,int nibytes,int l_ebindcnt,void *l_ebind,int nebytes) {
struct expr_bound_fcall *p;
struct expr_str *p2;
        p=malloc(sizeof(struct expr_bound_fcall));
        p2=A4GL_new_expr_simple (ET_EXPR_BOUND_FCALL);
        p->fname=acl_strdup(function);
        p->lib=acl_strdup(lib);
        p->module=mod;
        p->line=line;
	p->nibind=l_ibindcnt;
	p->ibind=malloc(nibytes);
	memcpy(p->ibind,l_ibind,nibytes);
	p->nebind=l_ebindcnt;
	p->ebind=malloc(nebytes);
	memcpy(p->ebind,l_ebind,nebytes);
        p2->u_data.expr_bound_fcall=p;
        return p2;
}




struct expr_str *A4GL_new_expr_shared_fcall(char *lib, char *function,struct expr_str_list *params,char *mod,int line) {
struct expr_shared_function_call *p;
struct expr_str *p2;
	p=malloc(sizeof(struct expr_shared_function_call));
        p2=A4GL_new_expr_simple (ET_EXPR_SHARED_FCALL);
	p->fname=acl_strdup(function);
	p->lib=acl_strdup(lib);
	p->parameters=params;
	p->module=mod;
	p->line=line;
	p2->u_data.expr_shared_function_call=p;
	return p2;
}

struct expr_str *A4GL_new_expr_call_external(char *host,char *func,char *port,struct expr_str_list *params,int nowait,char *mod,int line) {
struct expr_external_call *p;
struct expr_str *p2;
	p=malloc(sizeof(struct expr_external_call));
        p2=A4GL_new_expr_simple (ET_EXPR_EXTERNAL);
	p->host=acl_strdup(host);
	p->port=acl_strdup(port);
	p->func=acl_strdup(func);
	p->parameters=params;
	p->module=mod;
	p->line=line;
	p->without_waiting=nowait;
	p2->u_data.expr_external_call=p;
	return p2;
}

struct expr_str *A4GL_new_expr_list () {
	struct expr_str *p;
        p=A4GL_new_expr_simple (ET_EXPR_EXPR_LIST);
	p->u_data.expr_list= A4GL_new_ptr_list(0);
	return p;
}


struct expr_str *A4GL_expr_exists_sq(int invert,char *s,void *b,int nbind) {
  struct expr_str *ptr;
  int l;
  if (invert) {
  	ptr=A4GL_new_expr_simple (ET_EXPR_EXISTS_SUBQUERY);
  } else {
  	ptr=A4GL_new_expr_simple (ET_EXPR_NOT_EXISTS_SUBQUERY);
  }
  ptr->u_data.expr_exists_sq=malloc(sizeof(struct expr_exists_sq));
  ptr->u_data.expr_exists_sq->subquery=acl_strdup(s);

  l=sizeof(struct binding_comp)*nbind;
  ptr->u_data.expr_exists_sq->ibind=malloc(l);
  memcpy(ptr->u_data.expr_exists_sq->ibind,b,l);

  ptr->u_data.expr_exists_sq->nibind=nbind;
  return ptr;
}


struct expr_str *A4GL_expr_in(struct expr_str *expr, int invert,struct expr_str_list *elist) {
  struct expr_str *ptr;


  if (invert) {
  	ptr=A4GL_new_expr_simple (ET_EXPR_OP_IN);
  } else {
  	ptr=A4GL_new_expr_simple (ET_EXPR_OP_NOT_IN);
  }
  ptr->u_data.expr_in=malloc(sizeof(struct expr_in));
  ptr->u_data.expr_in->expr=expr;
  ptr->u_data.expr_in->elist=elist;

  return ptr;
}



struct expr_str *A4GL_expr_in_sq(struct expr_str *expr, int invert,char *subquery,void *b,int nbind) {
  struct expr_str *ptr;
  long l;
  if (invert) {
  	ptr=A4GL_new_expr_simple (ET_EXPR_OP_IN_SUBQUERY);
  } else {
  	ptr=A4GL_new_expr_simple (ET_EXPR_OP_NOTIN_SUBQUERY);
  }
  ptr->u_data.expr_in_sq=malloc(sizeof(struct expr_in_sq));
  ptr->u_data.expr_in_sq->expr=expr;
  ptr->u_data.expr_in_sq->subquery=acl_strdup(subquery);
  l=sizeof(struct binding_comp)*nbind;
  ptr->u_data.expr_in_sq->ibind=malloc(l);
  memcpy(ptr->u_data.expr_in_sq->ibind,b,l);
  ptr->u_data.expr_in_sq->nibind=nbind;
  return ptr;
}



/*****************************************************************************/
/* All code after here is OLD stuff which is badly written and bad to use    */
/* we should look at removing calls to these functions asap...               */
/*****************************************************************************/




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
                  case ET_EXPR_STRING: new_ptr->u_data.expr_char=acl_strdup(orig_ptr->u_data.expr_char); break;
                  case ET_EXPR_LITERAL_DOUBLE_STR: new_ptr->u_data.expr_char=acl_strdup(orig_ptr->u_data.expr_char); break;
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


struct expr_str * 
A4GL_new_expr_obsol (char *value)
{
  struct expr_str *ptr;
  A4GL_debug ("new_expr - %s", value);


  //A4GL_assertion(1,"Bad news - shouldn't be using A4GL_new_expr\n");

  ptr=A4GL_new_expr_simple (ET_EXPR_STRING);
  ptr->next = 0;
  ptr->u_data.expr_char = acl_strdup (value);
  A4GL_debug ("newexpr : %s -> %p\n", value, ptr);
  return ptr;
}




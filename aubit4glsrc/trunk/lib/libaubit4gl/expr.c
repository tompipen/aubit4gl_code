
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
# $Id: expr.c,v 1.4 2005-10-03 10:09:45 mikeaubury Exp $
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
#ifdef HAVE_STRINGS_H
#include <strings.h>
#endif

/*
=====================================================================
                    Variables definitions
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
case ET_EXPR_OP_NOTIN: return "ET_EXPR_OP_NOTIN";
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
    ptr->u_data.expr_substring->str=strdup(str);
    A4GL_trim( ptr->u_data.expr_substring->str);
    ptr->u_data.expr_substring->len=str_len;
    if (ptr_s[0]==' ') ptr_s++;
    ptr->u_data.expr_substring->substring_start=strdup(ptr_s);
    A4GL_trim(ptr->u_data.expr_substring->substring_start);
    if (ptr_e[0]==' ') ptr_e++;
    ptr->u_data.expr_substring->substring_end=strdup(ptr_e);
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


struct expr_str *A4GL_new_literal_long_str (char *value)
{
  struct expr_str *ptr;
  ptr=A4GL_new_expr_simple (ET_EXPR_LITERAL_LONG);
  ptr->u_data.expr_long=atol(value);
  return ptr;
}

struct expr_str *A4GL_new_literal_long_long (long value)
{
  struct expr_str *ptr;
  ptr=A4GL_new_expr_simple (ET_EXPR_LITERAL_LONG);
  ptr->u_data.expr_long=value;
  return ptr;
}


struct expr_str *A4GL_new_literal_string (char *value)
{
  struct expr_str *ptr;
  ptr=A4GL_new_expr_simple (ET_EXPR_LITERAL_STRING);
  ptr->u_data.expr_string=strdup(value);
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
} else {
	ptr_new=A4GL_new_expr_simple_expr(ptr,ET_EXPR_NEG);
	return ptr_new;
}
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
  ptr->next = 0;
  ptr->expr_type=type;
  return ptr;
}


struct expr_str *A4GL_new_expr_push_variable(char *v,long dtype) {
struct expr_push_variable *p;
struct expr_str *p2;
	p=malloc(sizeof(struct expr_push_variable));
        p2=A4GL_new_expr_simple (ET_EXPR_PUSH_VARIABLE);
	p->variable=strdup(v);
	p->var_dtype=dtype;
	p2->u_data.expr_push_variable=p;
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
	p->fname=strdup(function);
	p->parameters=params;
	p->module=mod;
	p->line=line;
	p2->u_data.expr_function_call=p;
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


struct expr_str *A4GL_new_expr_wordwrap(struct expr_str *ptr,char *wrap_at) {
	struct expr_wordwrap *p;
	struct expr_str *p2;
	p=malloc(sizeof(struct expr_get_fldbuf));
        p2=A4GL_new_expr_simple (ET_EXPR_WORDWRAP);
	p->expr=ptr;
	p->wrap_at=strdup(wrap_at);
	p2->u_data.expr_wordwrap=p;
	return p2;
}


struct expr_str *A4GL_new_expr_member_fcall(char *lib,char *function,struct expr_str_list *params,char *mod,int line) {
struct expr_member_function_call *p;
struct expr_str *p2;
	p=malloc(sizeof(struct expr_member_function_call));
        p2=A4GL_new_expr_simple (ET_EXPR_MEMBER_FCALL);
	p->lib=strdup(lib);
	p->fname=strdup(function);
	p->parameters=params;
	p->module=mod;
	p->line=line;
	p2->u_data.expr_member_function_call=p;
	return p2;
}


struct expr_str *A4GL_new_expr_shared_fcall(char *lib, char *function,struct expr_str_list *params,char *mod,int line) {
struct expr_shared_function_call *p;
struct expr_str *p2;
	p=malloc(sizeof(struct expr_shared_function_call));
        p2=A4GL_new_expr_simple (ET_EXPR_SHARED_FCALL);
	p->fname=strdup(function);
	p->lib=strdup(lib);
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
	p->host=strdup(host);
	p->port=strdup(port);
	p->func=strdup(func);
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
void * 
A4GL_append_expr (struct expr_str *orig_ptr, char *value)
{
  struct expr_str *ptr;
  struct expr_str *start;
  start = orig_ptr;

  A4GL_debug ("MJA A4GL_append_expr %p (%s)", orig_ptr, value);

  ptr = A4GL_new_expr (value);
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
                  case ET_EXPR_STRING: new_ptr->u_data.expr_char=strdup(orig_ptr->u_data.expr_char); break;
                  case ET_EXPR_LITERAL_DOUBLE_STR: new_ptr->u_data.expr_char=strdup(orig_ptr->u_data.expr_char); break;
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
  A4GL_debug ("Print expr... %p", ptr);
  while (ptr)
    {
      c++;
      ptr = ptr->next;
    }
  return c;
}


void * 
A4GL_new_expr (char *value)
{
  struct expr_str *ptr;
  A4GL_debug ("new_expr - %s", value);
  ptr=A4GL_new_expr_simple (ET_EXPR_STRING);
  ptr->next = 0;
  ptr->u_data.expr_char = acl_strdup (value);
  A4GL_debug ("newexpr : %s -> %p\n", value, ptr);
  return ptr;
}


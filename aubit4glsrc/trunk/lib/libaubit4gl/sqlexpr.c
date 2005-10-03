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
# $Id: sqlexpr.c,v 1.3 2005-10-03 10:09:45 mikeaubury Exp $
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

static char *get_sli_type (enum e_sli type) ;
char * make_sql_string_and_free (char *first, ...);
char *kw_space=" ";
char *kw_comma=",";
char *kw_ob="(";
char *kw_cb=")";

//char *get_select_list_item_list(struct s_select *select, struct s_select_list_item_list *i) ;
//char *get_select_list_item(struct s_select *select, struct s_select_list_item *p) ;
static char *get_select_list_item_i(struct s_select *select, struct s_select_list_item *p) ;
static void make_list_item_list_from_select_list(struct s_select *select,struct s_select_list_item_list *p) ;
static void make_list_item_list_from_select(struct s_select *select,struct s_select_list_item *p);





static struct s_select_list_item *empty_select_list_item(enum e_sli type) {
	struct s_select_list_item *p;
	p=malloc(sizeof(struct s_select_list_item));
	p->type=type;
	p->alias=0;
	p->sign=0;
	return p;
}


struct s_select_list_item_list *new_select_list_item_list(struct s_select_list_item *i) {
	struct s_select_list_item_list *p;
	p=malloc(sizeof(struct s_select_list_item_list));
	p->list=0;
	p->nlist=0;
	if (i) add_select_list_item_list(p,i);
	return p;
}

struct s_select_list_item_list *add_select_list_item_list(struct s_select_list_item_list *p,struct s_select_list_item *i) {
	p->nlist++;
	p->list=realloc(p->list,sizeof(struct s_select_list_item *)*p->nlist);
	p->list[p->nlist-1]=i;
	return p;
}


static struct s_select_list_item_list *add_select_list_item_list_once(struct s_select_list_item_list *p,struct s_select_list_item *i) {
	int a;
	if (p->nlist) {
		for (a=0;a<p->nlist;a++) {
			if (p->list[a]==i) return p;
		}
	}
	return add_select_list_item_list(p,i);
}


struct s_select_list_item *new_select_list_item_char (char *s) {
	struct s_select_list_item *p;
	A4GL_assertion(1,"Is this used ?");
	p=empty_select_list_item(E_SLI_CHAR);
	p->u_data.expression=strdup(s);
	return p;
}


struct s_select_list_item *new_select_list_item_variable (char *s) {
	struct s_select_list_item *p;
	p=empty_select_list_item(E_SLI_VARIABLE);
	p->u_data.expression=strdup(s);
	return p;
}

struct s_select_list_item *new_select_list_item_column_from_transform(char *s) {
	struct s_select_list_item *p;
	if (strcmp(s,"?")==0) {
		p=empty_select_list_item(E_SLI_QUERY_PLACEHOLDER);
		p->u_data.expression=strdup(s);
		return p;
	}

	if (strchr(s,'.')) {
		char *b;
		char *ptr;
		struct ilist subscripts;
		b=strdup(s);
		ptr=strchr(b,'.');
		*ptr=0;
		ptr++;
		subscripts.i0=0;
		subscripts.i1=0;
		subscripts.i2=0;
		subscripts.i3=0;
		subscripts.i4=0;
		subscripts.i5=0;
		return new_select_list_item_col (b,ptr,&subscripts) ;


	}

	return new_select_list_item_col (0,s,0);

	/* 
	 p=empty_select_list_item(E_SLI_COLUMN_NOT_TRANSFORMED); // @@@ FIXME....
	 p->u_data.expression=strdup(s);
	*/
	return p;
}


struct s_select_list_item *new_select_list_item_literal (char *s) {
	struct s_select_list_item *p;
	p=empty_select_list_item(E_SLI_LITERAL);
	p->u_data.expression=strdup(s);
	return p;
}



struct s_select_list_item *new_select_list_item_ibind (char *s) {
	struct s_select_list_item *p;
	p=empty_select_list_item(E_SLI_IBIND);
	p->u_data.expression=strdup(s);
	return p;
}

struct s_select_list_item *new_select_list_item_datetime (char *s) {
	struct s_select_list_item *p;
	p=empty_select_list_item(E_SLI_DATETIME);
	p->u_data.expression=strdup(s);
	return p;
}

struct s_select_list_item *new_select_list_item_extend (struct s_select_list_item *dt_expr, char *from,char *to) {
	struct s_select_list_item *p;
	p=empty_select_list_item(E_SLI_EXTEND);
	strcpy(p->u_data.extend.from,from);
	strcpy(p->u_data.extend.to,to);
	p->u_data.extend.expr=dt_expr;
	return p;
}


struct s_select_list_item *new_select_list_item_interval (char *s) {
	struct s_select_list_item *p;
	p=empty_select_list_item(E_SLI_INTERVAL);
	p->u_data.expression=strdup(s);
	return p;
}

struct s_select_list_item *new_select_list_item_col (char *t,char *c,struct ilist *subscripts) {
	struct s_select_list_item *p;
	p=empty_select_list_item(E_SLI_COLUMN);

	p->u_data.column.tabname=0;
	p->u_data.column.colname=0;

	if (t) {
		p->u_data.column.tabname=strdup(t);
	}
	if (c) {
		p->u_data.column.colname=strdup(c);
	}
	p->u_data.column.subscript.i0=-1;
	p->u_data.column.subscript.i1=-1;
	p->u_data.column.subscript.i2=-1;
	p->u_data.column.subscript.i3=-1;
	p->u_data.column.subscript.i4=-1;
	p->u_data.column.subscript.i5=-1;

	if (subscripts) {
		p->u_data.column.subscript.i0=subscripts->i0;
		p->u_data.column.subscript.i1=subscripts->i1;
		p->u_data.column.subscript.i2=subscripts->i2;
		p->u_data.column.subscript.i3=subscripts->i3;
		p->u_data.column.subscript.i4=subscripts->i4;
		p->u_data.column.subscript.i5=subscripts->i5;
		
	}
	return p;
}

struct s_select_list_item *new_select_list_item_sq (enum sq_expression_type type, struct s_select_list_item *s) {
	struct s_select_list_item *p;
	p=empty_select_list_item(E_SLI_SUBQUERY_EXPRESSION);
	p->u_data.sq_expression.type=type;
	p->u_data.sq_expression.sq=s;
	return p;
}


struct s_select_list_item *new_select_list_item_builtin_const (enum e_sli type) {
	struct s_select_list_item *p;
	p=empty_select_list_item(type);
	return p;
}


struct s_select_list_item *new_select_list_item_agg1 (enum e_sli type,char *aud, struct s_select_list_item *i) {
	struct s_select_list_item *p;
	p=empty_select_list_item(type);
	strcpy(p->u_data.agg_expr.aud,aud);
	p->u_data.agg_expr.expr=i;
	return p;
}


struct s_select_list_item *new_select_list_item_op_sli (struct s_select_list_item *left, struct s_select_list_item *right, enum e_sli op) {
	struct s_select_list_item *p;
	p=empty_select_list_item(op);
	p->u_data.sli_expr.left=left;
	p->u_data.sli_expr.right=right;
	return p;
}

struct s_select_list_item *new_select_list_item_op_slil (struct s_select_list_item *left, struct s_select_list_item_list *right, enum e_sli op) {
	struct s_select_list_item *p;
	p=empty_select_list_item(op);
	p->u_data.slil_expr.left=left;
	p->u_data.slil_expr.right_list=right;
	return p;
}

struct s_select_list_item *new_select_list_item_op_expr (struct s_select_list_item *left, struct s_select_list_item *right, char* op) {
	struct s_select_list_item *p;
	p=empty_select_list_item(E_SLI_OP);
	p->u_data.complex_expr.left=left;
	p->u_data.complex_expr.right=right;
	strcpy(p->u_data.complex_expr.op,op);
	return p;
}

struct s_select_list_item *new_select_list_item_op_between (char *not,struct s_select_list_item *v, struct s_select_list_item *from, struct s_select_list_item *to,int not_between) {
	struct s_select_list_item *p;
	if (not_between) {
		p=empty_select_list_item(E_SLI_NOT_BETWEEN);
	} else {
		p=empty_select_list_item(E_SLI_BETWEEN);
	}
	p->u_data.between_expr.val=v;
	p->u_data.between_expr.from=from;
	p->u_data.between_expr.to=to;
	return p;
}

struct s_select_list_item *new_select_list_item_fcall (char *fname, struct s_select_list_item_list *params) {
	struct s_select_list_item *p;
	p=empty_select_list_item(E_SLI_FCALL);
	strcpy(p->u_data.fcall.fname,fname);
	p->u_data.fcall.params=params;
	return p;
}



struct s_select_list_item *new_select_list_item_builtin_fcall (enum e_sli type, struct s_select_list_item_list *params) {
	struct s_select_list_item *p;
	p=empty_select_list_item(type);
	p->u_data.builtin_fcall.params=params;
	return p;
}


struct s_select_list_item *new_select_list_item_simple_expr (enum e_sli type, struct s_select_list_item *expr) {
	struct s_select_list_item *p;
	p=empty_select_list_item(type);
	p->u_data.simple_op_expr.expr=expr;
	return p;
}


struct s_select_list_item *new_select_list_item_regex (enum e_sli type, struct s_select_list_item *val,struct s_select_list_item *regex,char *escape) {
	struct s_select_list_item *p;
	p=empty_select_list_item(type);
	p->u_data.regex.val=val;
	p->u_data.regex.regex=regex;
	strcpy(p->u_data.regex.escape,escape);
	return p;
}



struct s_select_list_item *new_select_list_subquery(struct s_select *s) {
	struct s_select_list_item *p;
	p=empty_select_list_item(E_SLI_SUBQUERY);
	p->u_data.subquery=s;
	return p;
}


struct s_select *new_empty_select (void) {
	struct s_select *p;
	p=malloc(sizeof(struct s_select));
	p->modifier=0;
	p->limit.start=-1;
	p->limit.end=-1;
	p->limit.offset=-1;
	p->ncolumns=0;
	p->select_list=0;
	p->first=0;
	p->table_elements.ntables=0;
	p->table_elements.tables=0;
	p->group_by=0;
	p->having=0;
	p->list_of_items.nlist=0;
	p->list_of_items.list=0;
	p->where_clause=0;
	p->next=0;
	p->sf=0;
	p->union_op=0;
	p->into=0;



	return p;
}

char *get_select_list_item_list(struct s_select *select, struct s_select_list_item_list *i) {
char *buff=0;
char *buff2;
int a;
	if (i==0) return "";
	for (a=0;a<i->nlist;a++) {
		if (a) {
			buff2=get_select_list_item(select,i->list[a]);
			buff=make_sql_string_and_free(buff,strdup(","),buff2,0);
		} else {
			buff=get_select_list_item(select,i->list[a]);
		}
		if (buff==0)  {
				A4GL_assertion(1,"SHould be set to something");
		}
	}
	return buff;
}

char *get_select_list_item(struct s_select *select, struct s_select_list_item *p) {
	char *rval;
	char *rval2;
	rval=get_select_list_item_i(select,p);
	rval2=strdup(A4GLSQLCV_check_expr(rval));
	free(rval);
	rval=rval2;

	if (p->sign=='-') { rval=make_sql_string_and_free("-",rval,0); }
	if (p->alias) { 
			if (A4GLSQLCV_check_requirement("COLUMN_ALIAS_AS")) {
				rval=make_sql_string_and_free(rval," AS ", p->alias,0); 
			} else {
				rval=make_sql_string_and_free(rval," ",p->alias,0); 
			}
	}
	return rval;
}

static char *get_select_list_item_i(struct s_select *select, struct s_select_list_item *p) {
		// This is the guts of this code!
		A4GL_debug("%d (%s)\n",p->type,get_sli_type(p->type));

		switch (p->type) {
			case E_SLI_CHAR: 			A4GL_assertion(1,"Not used");

			case E_SLI_IBIND: 			return strdup(p->u_data.expression); 
			case E_SLI_VARIABLE: 			return strdup(p->u_data.expression); 
			case E_SLI_DATETIME: 			return strdup(p->u_data.expression); 
			case E_SLI_INTERVAL: 			return strdup(p->u_data.expression); 

			case E_SLI_COLUMN_NOT_TRANSFORMED: 	return strdup(p->u_data.expression); 

			case E_SLI_OP: 				return make_sql_string_and_free(get_select_list_item(select,p->u_data.complex_expr.left),
											strdup(p->u_data.complex_expr.op),
											get_select_list_item(select,p->u_data.complex_expr.right),0); 

			/*
			case E_SLI_JOIN: 				return make_sql_string_and_free(strdup("JOIN("),get_select_list_item(select,p->u_data.complex_expr.left), 
											strdup("="),
											get_select_list_item(select,p->u_data.complex_expr.right),strdup(")"),0); 
			*/


			case E_SLI_JOIN: 				return make_sql_string_and_free(get_select_list_item(select,p->u_data.complex_expr.left), 
											strdup("="),
											get_select_list_item(select,p->u_data.complex_expr.right),0); 


			case E_SLI_IN_VALUES: 			return make_sql_string_and_free(get_select_list_item(select,
											p->u_data.slil_expr.left), acl_strdup(" IN ("),
										get_select_list_item_list(select,p->u_data.slil_expr.right_list),acl_strdup(")"), 0); 

			case E_SLI_NOT_IN_VALUES: 		return make_sql_string_and_free(get_select_list_item(select,
											p->u_data.slil_expr.left), acl_strdup(" NOT IN ("),
										get_select_list_item_list(select,p->u_data.slil_expr.right_list),acl_strdup(")"), 0); 


			case E_SLI_IN_SELECT: 			return make_sql_string_and_free(get_select_list_item(select,p->u_data.complex_expr.left), acl_strdup(" IN ("),
										get_select_list_item(select,p->u_data.complex_expr.right), kw_cb,0); 

			case E_SLI_NOT_IN_SELECT: 		return make_sql_string_and_free(get_select_list_item(select,p->u_data.complex_expr.left), acl_strdup(" NOT IN ("),
										get_select_list_item(select,p->u_data.complex_expr.right), kw_cb,0); 

			case E_SLI_LITERAL: 			return strdup(p->u_data.expression);

			case E_SLI_REGEX_MATCHES:	        {
									char *p1;
									char *p2;
									p1=get_select_list_item(select,p->u_data.regex.val);
									p2=get_select_list_item(select,p->u_data.regex.regex);
									return make_sql_string_and_free(p1,A4GLSQLCV_matches_string("",p2,p->u_data.regex.escape),0);
								}

			case E_SLI_REGEX_NOT_MATCHES:	        {
									char *p1;
									char *p2;
									p1=get_select_list_item(select,p->u_data.regex.val);
									p2=get_select_list_item(select,p->u_data.regex.regex);
									return make_sql_string_and_free(p1,A4GLSQLCV_matches_string(" NOT ",p2,p->u_data.regex.escape),0);
								}
			case E_SLI_REGEX_LIKE:	        	{
									char *p1;
									char *p2;
									p1=get_select_list_item(select,p->u_data.regex.val);
									p2=get_select_list_item(select,p->u_data.regex.regex);
									if (p->u_data.regex.escape && strlen(p->u_data.regex.escape)) {
										return make_sql_string_and_free(p1," LIKE " ,p2, p->u_data.regex.escape,0);
									} else {
										return make_sql_string_and_free(p1," LIKE " ,p2,0);
									}
								}
			case E_SLI_REGEX_NOT_LIKE:	        	{
									char *p1;
									char *p2;
									p1=get_select_list_item(select,p->u_data.regex.val);
									p2=get_select_list_item(select,p->u_data.regex.regex);
									if (p->u_data.regex.escape && strlen(p->u_data.regex.escape)) {
										return make_sql_string_and_free(p1," NOT LIKE " ,p2, p->u_data.regex.escape,0);
									} else {
										return make_sql_string_and_free(p1," NOT LIKE " ,p2,0);
									}
								}
			case E_SLI_REGEX_ILIKE:	        	{
									char *p1;
									char *p2;
									p1=get_select_list_item(select,p->u_data.regex.val);
									p2=get_select_list_item(select,p->u_data.regex.regex);
									if (p->u_data.regex.escape && strlen(p->u_data.regex.escape)) {
										return make_sql_string_and_free(p1," ILIKE " ,p2,p->u_data.regex.escape,0);
									} else {
										return make_sql_string_and_free(p1," ILIKE " ,p2,0);
									}
								}
			case E_SLI_REGEX_NOT_ILIKE:	        	{
									char *p1;
									char *p2;
									p1=get_select_list_item(select,p->u_data.regex.val);
									p2=get_select_list_item(select,p->u_data.regex.regex);
									if (p->u_data.regex.escape && strlen(p->u_data.regex.escape)) {
										return make_sql_string_and_free(p1," NOT ILIKE " ,p2, p->u_data.regex.escape,0);
									} else {
										return make_sql_string_and_free(p1," NOT ILIKE " ,p2,0);
									}
								}

			case E_SLI_ISNULL:	        	return make_sql_string_and_free(get_select_list_item(select,p->u_data.simple_op_expr.expr),acl_strdup(" IS NULL"),0);
			case E_SLI_ISNOTNULL:	        	return make_sql_string_and_free(get_select_list_item(select,p->u_data.simple_op_expr.expr),acl_strdup(" IS NOT NULL"),0);
			case E_SLI_ASC:	        		return make_sql_string_and_free(get_select_list_item(select,p->u_data.simple_op_expr.expr),acl_strdup(" ASC"),0);
			case E_SLI_DESC:	        	
								return make_sql_string_and_free(get_select_list_item(select,p->u_data.simple_op_expr.expr),acl_strdup(" DESC"),0);
			case E_SLI_NOT:	        		return make_sql_string_and_free(acl_strdup("NOT("),get_select_list_item(select,p->u_data.simple_op_expr.expr),acl_strdup(")"),0);
			case E_SLI_BRACKET_EXPR:        	return make_sql_string_and_free(acl_strdup("("),get_select_list_item(select,p->u_data.simple_op_expr.expr),acl_strdup(")"),0);
			case E_SLI_UNITS_YEAR:			return make_sql_string_and_free(get_select_list_item(select,p->u_data.simple_op_expr.expr),acl_strdup(" UNITS YEAR"),0);
			case E_SLI_UNITS_MONTH:			return make_sql_string_and_free(get_select_list_item(select,p->u_data.simple_op_expr.expr),acl_strdup(" UNITS MONTH"),0);
			case E_SLI_UNITS_DAY:			return make_sql_string_and_free(get_select_list_item(select,p->u_data.simple_op_expr.expr),acl_strdup(" UNITS DAY"),0);
			case E_SLI_UNITS_HOUR:			return make_sql_string_and_free(get_select_list_item(select,p->u_data.simple_op_expr.expr),acl_strdup(" UNITS HOUR"),0);
			case E_SLI_UNITS_MINUTE:		return make_sql_string_and_free(get_select_list_item(select,p->u_data.simple_op_expr.expr),acl_strdup(" UNITS MINUTE"),0);
			case E_SLI_UNITS_SECOND:		return make_sql_string_and_free(get_select_list_item(select,p->u_data.simple_op_expr.expr),acl_strdup(" UNITS SECOND"),0);
			case E_SLI_BUILTIN_CONST_TRUE:		return acl_strdup(A4GLSQLCV_get_sqlconst("FALSE"));
			case E_SLI_BUILTIN_CONST_FALSE:		return acl_strdup(A4GLSQLCV_get_sqlconst("TRUE"));
			case E_SLI_BUILTIN_CONST_USER:		return acl_strdup(A4GLSQLCV_get_sqlconst("USER"));
			case E_SLI_BUILTIN_CONST_TODAY:		return acl_strdup(A4GLSQLCV_get_sqlconst("TODAY"));
			case E_SLI_BUILTIN_CONST_STAR:		return acl_strdup("*");
			case E_SLI_BUILTIN_CONST_COUNT_STAR:	return acl_strdup("COUNT *");
			case E_SLI_BUILTIN_CONST_CURRENT:	return acl_strdup("CURRENT ");

			case E_SLI_BUILTIN_FUNC_YEAR:		{ char *params; char *rval; params=get_select_list_item_list(select, p->u_data.builtin_fcall.params); rval=acl_strdup(A4GLSQLCV_sql_func("YEAR",params)); free(params);return rval; }
			case E_SLI_BUILTIN_FUNC_MONTH:		{ char *params; char *rval; params=get_select_list_item_list(select, p->u_data.builtin_fcall.params); rval=acl_strdup(A4GLSQLCV_sql_func("MONTH",params)); free(params);return rval; }
			case E_SLI_BUILTIN_FUNC_DAY:		{ char *params; char *rval; params=get_select_list_item_list(select, p->u_data.builtin_fcall.params); rval=acl_strdup(A4GLSQLCV_sql_func("DAY",params)); free(params);return rval; }
			case E_SLI_BUILTIN_FUNC_DOW:		{ char *params; char *rval; params=get_select_list_item_list(select, p->u_data.builtin_fcall.params); rval=acl_strdup(A4GLSQLCV_sql_func("DOW",params)); free(params);return rval; }
			case E_SLI_BUILTIN_FUNC_WEEKDAY:	{ char *params; char *rval; params=get_select_list_item_list(select, p->u_data.builtin_fcall.params); rval=acl_strdup(A4GLSQLCV_sql_func("WEEKDAY",params)); free(params);return rval; }
			case E_SLI_BUILTIN_FUNC_MDY:		{ char *params; char *rval; params=get_select_list_item_list(select, p->u_data.builtin_fcall.params); rval=acl_strdup(A4GLSQLCV_sql_func("MDY",params)); free(params);return rval; }
			case E_SLI_BUILTIN_FUNC_DATE:		{ char *params; char *rval; params=get_select_list_item_list(select, p->u_data.builtin_fcall.params); rval=acl_strdup(A4GLSQLCV_sql_func("DATE",params)); free(params);return rval; }
			case E_SLI_BUILTIN_AGG_AVG:		return make_sql_string_and_free( acl_strdup("AVG("), p->u_data.agg_expr.aud, get_select_list_item(select,p->u_data.agg_expr.expr), acl_strdup(")"),0);
			case E_SLI_BUILTIN_AGG_MAX:		return make_sql_string_and_free( acl_strdup("MAX("), p->u_data.agg_expr.aud, get_select_list_item(select,p->u_data.agg_expr.expr), acl_strdup(")"),0);
			case E_SLI_BUILTIN_AGG_MIN:		return make_sql_string_and_free( acl_strdup("MIN("), p->u_data.agg_expr.aud, get_select_list_item(select,p->u_data.agg_expr.expr), acl_strdup(")"),0);
			case E_SLI_BUILTIN_AGG_SUM:		return make_sql_string_and_free( acl_strdup("SUM("), p->u_data.agg_expr.aud, get_select_list_item(select,p->u_data.agg_expr.expr), acl_strdup(")"),0);
			case E_SLI_BUILTIN_AGG_COUNT:		return make_sql_string_and_free( acl_strdup("COUNT("), p->u_data.agg_expr.aud, get_select_list_item(select,p->u_data.agg_expr.expr), acl_strdup(")"),0);

			case E_SLI_BETWEEN: 			 return make_sql_string_and_free( get_select_list_item(select,p->u_data.between_expr.val), acl_strdup(" BETWEEN "), get_select_list_item(select,p->u_data.between_expr.from), acl_strdup(" AND "), get_select_list_item(select,p->u_data.between_expr.to),0);
			case E_SLI_NOT_BETWEEN: 			 return make_sql_string_and_free( get_select_list_item(select,p->u_data.between_expr.val), acl_strdup(" NOT BETWEEN "), get_select_list_item(select,p->u_data.between_expr.from), acl_strdup(" AND "), get_select_list_item(select,p->u_data.between_expr.to),0);


			case E_SLI_FCALL: return make_sql_string_and_free(acl_strdup(p->u_data.fcall.fname),kw_ob,get_select_list_item_list(select, p->u_data.fcall.params),kw_cb,0);


			case E_SLI_EXTEND: return make_sql_string_and_free(acl_strdup("EXTEND ("),get_select_list_item(select,p->u_data.extend.expr),strdup(","),p->u_data.extend.from,strdup(" TO "),strdup(p->u_data.extend.to),kw_cb,0);
			case E_SLI_QUERY_PLACEHOLDER: return strdup("?");

        		case E_SLI_COLUMN :  {
						char buff[50]="";
					  	if (p->u_data.column.subscript.i0>=1) {
								return strdup(A4GLSQLCV_make_substr(
									A4GLSQLCV_check_colname(p->u_data.column.tabname,p->u_data.column.colname),
											p->u_data.column.subscript.i0,
											p->u_data.column.subscript.i1,
											p->u_data.column.subscript.i2));
					  	}
						A4GL_assertion(p->u_data.column.colname==0,"Column name was null pointer");
					  	if (p->u_data.column.tabname) {
					  			return strdup(A4GLSQLCV_check_colname(p->u_data.column.tabname,p->u_data.column.colname));
						}
					  	return make_sql_string_and_free(strdup(p->u_data.column.colname),strdup(buff),0);
					}
			case E_SLI_SUBQUERY: return make_select_stmt(p->u_data.subquery);

			case E_SLI_SUBQUERY_EXPRESSION:
			 	switch(p->u_data.sq_expression.type) {
					case E_SQE_DONT_CARE: return make_sql_string_and_free(kw_ob,get_select_list_item(select,p->u_data.sq_expression.sq),kw_cb,0); 
					case E_SQE_EXISTS: return  make_sql_string_and_free(acl_strdup("EXISTS ("),get_select_list_item(select,p->u_data.sq_expression.sq),kw_cb,0); 

					case E_SQE_NOT_EXISTS: return  make_sql_string_and_free(acl_strdup("NOT EXISTS ("),get_select_list_item(select,p->u_data.sq_expression.sq),kw_cb,0); 
					case E_SQE_ALL: return  make_sql_string_and_free(acl_strdup("ALL ("),get_select_list_item(select,p->u_data.sq_expression.sq),kw_cb,0); 
					case E_SQE_ANY: return  make_sql_string_and_free(acl_strdup("ANY ("),get_select_list_item(select,p->u_data.sq_expression.sq),kw_cb,0); 
					case E_SQE_SOME: return  make_sql_string_and_free(acl_strdup("SOME ("),get_select_list_item(select,p->u_data.sq_expression.sq),kw_cb,0); 
				}
		}
		A4GL_assertion(1,"Shouldn't happen...");
		return "BADCOL";
}



char *make_table_expression(struct s_select *select) {
	char buff[20000];
	char buff_from[20000];
	//char into_temp[256];
	//char **select_cols;
	//int a;
	strcpy(buff,"");

        A4GLSQLPARSE_from_clause(select->first,buff_from,&select->table_elements);


	strcat(buff,buff_from);
	if (select->modifier) {
		if (strlen(select->modifier)) A4GL_assertion(1,"Not expecting a modifier");
	}

	A4GL_assertion(select->having!=0,"Not expecting a HAVING");
	A4GL_assertion(select->group_by!=0,"Not expecting a GROUP BY");
	A4GL_assertion(select->sf!=0,"Not expecting and INTO TEMP or ORDER BY");
	A4GL_assertion(select->next!=0,"Not expecting a UNION");

	if (select->where_clause) {
		char *ptr;
		ptr=get_select_list_item(select,select->where_clause);
		strcat(buff," WHERE ");
		strcat(buff,ptr);
		free(ptr);
	}

	return strdup(buff);
}


void make_list_in_subselect_stmt(struct s_select *orig, struct s_select *next) {
		// Do nothing for now - until we figure out what to do...
		// This isn't particularly important anyway....
}





static char *find_table(struct s_select *select, struct s_select_list_item *i) {
	int a;
	char *colname;
	A4GL_assertion(i->type!=E_SLI_COLUMN,"Expecting a column...");


	if (i->u_data.column.tabname==0) {
		// Need to look into the database to see what tables contain this column
		// from our list of candidate tables....
	}


	if (i->u_data.column.tabname!=0) {
		for (a=0;a<select->table_elements.ntables;a++) {
			if (select->table_elements.tables[a].alias) {
			A4GL_assertion(i->u_data.column.tabname==0,"tabname shouldn't be null");
	
				if (strcmp(select->table_elements.tables[a].alias,i->u_data.column.tabname)==0) {
					return select->table_elements.tables[a].tabname;
				}
			}
			if (strcmp(select->table_elements.tables[a].tabname,i->u_data.column.tabname)==0) {
					return select->table_elements.tables[a].tabname;
			}
		}
		printf("Can't find table %s in FROM clause\n",i->u_data.column.tabname);
		return i->u_data.column.tabname;
	}
	return "";
}


void preprocess_sql_statement(struct s_select *select) {
int a;
struct s_select_list_item *p;
//
// Lets collect all our expressions in one place....
//
       for (a=0;a<select->select_list->nlist;a++) {
                   make_list_item_list_from_select(select,select->select_list->list[a]);
       }
       make_list_item_list_from_select(select,select->where_clause);
       make_list_item_list_from_select_list(select,select->group_by);
       make_list_item_list_from_select(select,select->having);
// 
A4GL_debug("That appears to have %d elements",select->list_of_items.nlist);
	for (a=0;a<select->list_of_items.nlist;a++) {
		p=select->list_of_items.list[a];
		A4GL_debug("%d %d - %s\n",a,p->type,get_sli_type(p->type));
		if (p->type==E_SLI_COLUMN) {

			if (p->u_data.column.tabname==0 && 0) {
				A4GL_debug("Unknown column : %s\n",p->u_data.column.colname);

				if (select->table_elements.ntables==1) {
					char *t="Unknown";
					t=select->table_elements.tables[0].alias;
					if (t==0) {
						t=select->table_elements.tables[0].tabname;
					}
					p->u_data.column.tabname=strdup(t);
					A4GL_debug("   But as we only have one table - guessing its %s\n",t);
				}


			} else {
					A4GL_debug("<%s>.<%s>",p->u_data.column.tabname,p->u_data.column.colname);
			}
		}
		if (p->type==E_SLI_COLUMN_NOT_TRANSFORMED) { A4GL_debug("    Untransformed : %s\n",p->u_data.expression); }
		if (p->type==E_SLI_OP) { A4GL_debug("    OP=%s\n",p->u_data.complex_expr.op); }
	}

	A4GL_debug("Done1");

	for (a=0;a<select->list_of_items.nlist;a++) {
		p=select->list_of_items.list[a];
		if (p->type==E_SLI_OP) {
			if (strcmp(p->u_data.complex_expr.op,"=")==0) { // Possible join...
					if (p->u_data.complex_expr.left->type==E_SLI_COLUMN && p->u_data.complex_expr.right->type==E_SLI_COLUMN ) {
						char *lt;
						char *rt;
						struct s_select_list_item *l;
						struct s_select_list_item *r;
						l=p->u_data.complex_expr.left;
						r=p->u_data.complex_expr.right;
						// Looks like a join....
						p->type=E_SLI_JOIN;


						lt=find_table(select,l);
						rt=find_table(select,r);


						

					}
			}
		}
	}
}

char *make_select_stmt(struct s_select *select) {
	char buff[40000];
	char buff_from[20000];
	char into_temp[256];
	int a;

        A4GLSQLPARSE_from_clause(select->first,buff_from,&select->table_elements);
	preprocess_sql_statement(select);

	A4GL_debug("Has %d tables :\n",select->table_elements.ntables);
	for (a=0;a<select->table_elements.ntables;a++) {
			char *tabname;
			char *alias;
			tabname=select->table_elements.tables[a].tabname;
			alias=select->table_elements.tables[a].alias;
			if (alias==0) alias="";
			A4GL_debug("   %-20s %s\n",tabname,alias);
	}
	A4GL_debug("\n");
	

	strcpy(buff,"SELECT ");
		A4GL_debug("buff=%s",buff);


	if (select->modifier) {
		A4GL_debug("buff=%s",buff);
		if (strlen(select->modifier)) {
			strcat(buff,select->modifier);
		A4GL_debug("buff=%s",buff);
			strcat(buff," ");
		A4GL_debug("buff=%s",buff);
		}
		A4GL_debug("buff=%s",buff);
	}

	//select_cols=malloc(sizeof(char *)*select->select_list->nlist);

		A4GL_debug("buff=%s",buff);
	for (a=0;a<select->select_list->nlist;a++) {
		char *ptr;
		ptr=get_select_list_item(select,select->select_list->list[a]);
		if (a) strcat(buff,",");
		strcat(buff,ptr);
		A4GL_debug("buff=%s",buff);
		free(ptr);
	}

	strcat(buff," ");

		A4GL_debug("buff=%s",buff);
	if (select->into) {
		if (strlen(select->into)) {
			strcat(buff,select->into);
			strcat(buff," ");
		}
	}
	strcat(buff,"FROM ");

		A4GL_debug("buff=%s",buff);
	strcat(buff,buff_from);

		A4GL_debug("buff=%s",buff);
	if (select->where_clause) {
		char *ptr;
		ptr=get_select_list_item(select,select->where_clause);
		strcat(buff," WHERE ");
		strcat(buff,ptr);
		free(ptr);
	}

		A4GL_debug("buff=%s",buff);
	if (select->group_by) {
		char *ptr;
		strcat(buff," GROUP BY ");
		ptr=get_select_list_item_list(select,select->group_by);
		strcat(buff,ptr);
	}
		A4GL_debug("buff=%s",buff);

	if (select->having) {
		char *ptr;
		strcat(buff," HAVING ");
		ptr=get_select_list_item(select,select->having);
		strcat(buff,ptr);
	}

		A4GL_debug("buff=%s",buff);

	if (select->next) {
		char *ptr;
		ptr=make_select_stmt(select->next);
		A4GL_debug("ptr=%s",ptr);
		A4GL_debug("buff=%s",buff);
		strcat(buff," UNION ");
		A4GL_debug("buff=%s",buff);
		if (select->union_op) {
				strcat(buff,select->union_op);
		A4GL_debug("buff=%s",buff);
				strcat(buff," "); 
		A4GL_debug("buff=%s",buff);
		}
		A4GL_debug("buff=%s",buff);
		strcat(buff,ptr);
		A4GL_debug("buff=%s",buff);
		free(ptr);
	}


	if (select->sf) {
		strcpy(into_temp,"");
		if (select->sf->into_temp) {
			char *ptr;

			if (select->sf->order_by) {
                			if (!A4GLSQLCV_check_requirement("STRIP_ORDER_BY_INTO_TEMP")) {
						strcat(into_temp," ORDER BY ");
						strcat(into_temp,get_select_list_item_list(select,select->sf->order_by));
					}
			}

			strcpy(into_temp," INTO TEMP ");
			strcat(into_temp,select->sf->into_temp);

			if (select->sf->nolog) {
				if (!A4GLSQLCV_check_requirement("OMIT_NO_LOG")) {
					strcat(into_temp," WITH NO LOG");
				}
			}
			ptr=A4GLSQLCV_select_into_temp(buff,into_temp, select->sf->into_temp);
			strcpy(buff,ptr);
			free(ptr);

		} else {
			if (select->sf->order_by) {
				strcat(into_temp," ORDER BY ");
				strcat(into_temp,get_select_list_item_list(select,select->sf->order_by));
			}
			strcat(buff,into_temp);
		}

	}
		A4GL_debug("buff=%s",buff);



	A4GL_debug("--->%s\n",buff);
	return strdup(buff);

}





static char *get_sli_type (enum e_sli type) {
switch (type) {
	case E_SLI_CHAR: 			return "E_SLI_CHAR"; break;
	case E_SLI_COLUMN: 			return "E_SLI_COLUMN"; break;
	case E_SLI_SUBQUERY_EXPRESSION:		return "E_SLI_SUBQUERY_EXPRESSION"; break;
	case E_SLI_BUILTIN_CONST_TRUE: 		return "E_SLI_BUILTIN_CONST_TRUE"; break;
	case E_SLI_BUILTIN_CONST_FALSE: 	return "E_SLI_BUILTIN_CONST_FALSE"; break;
	case E_SLI_BUILTIN_CONST_USER: 		return "E_SLI_BUILTIN_CONST_USER"; break;
	case E_SLI_BUILTIN_CONST_TODAY: 	return "E_SLI_BUILTIN_CONST_TODAY"; break;
	case E_SLI_BUILTIN_CONST_STAR: 		return "E_SLI_BUILTIN_CONST_STAR"; break;
	case E_SLI_BUILTIN_CONST_COUNT_STAR: 	return "E_SLI_BUILTIN_CONST_COUNT_STAR"; break;
	case E_SLI_BUILTIN_CONST_CURRENT: 	return "E_SLI_BUILTIN_CONST_CURRENT"; break;
	case E_SLI_BUILTIN_FUNC_YEAR: 		return "E_SLI_BUILTIN_FUNC_YEAR"; break;
	case E_SLI_BUILTIN_FUNC_MONTH: 		return "E_SLI_BUILTIN_FUNC_MONTH"; break;
	case E_SLI_BUILTIN_FUNC_DAY: 		return "E_SLI_BUILTIN_FUNC_DAY"; break;
	case E_SLI_BUILTIN_FUNC_MDY: 		return "E_SLI_BUILTIN_FUNC_MDY"; break;
	case E_SLI_BUILTIN_FUNC_WEEKDAY: 	return "E_SLI_BUILTIN_FUNC_WEEKDAY"; break;
	case E_SLI_BUILTIN_FUNC_DOW: 		return "E_SLI_BUILTIN_FUNC_DOW"; break;
	case E_SLI_BUILTIN_FUNC_DATE: 		return "E_SLI_BUILTIN_FUNC_DATE"; break;
	case E_SLI_BUILTIN_AGG_AVG: 		return "E_SLI_BUILTIN_AGG_AVG"; break;
	case E_SLI_BUILTIN_AGG_MAX: 		return "E_SLI_BUILTIN_AGG_MAX"; break;
	case E_SLI_BUILTIN_AGG_MIN: 		return "E_SLI_BUILTIN_AGG_MIN"; break;
	case E_SLI_BUILTIN_AGG_SUM: 		return "E_SLI_BUILTIN_AGG_SUM"; break;
	case E_SLI_BUILTIN_AGG_COUNT: 		return "E_SLI_BUILTIN_AGG_COUNT"; break;
	case E_SLI_BRACKET_EXPR: 		return "E_SLI_BRACKET_EXPR"; break;
	case E_SLI_UNITS_YEAR: 			return "E_SLI_UNITS_YEAR"; break;
	case E_SLI_UNITS_MONTH: 		return "E_SLI_UNITS_MONTH"; break;
	case E_SLI_UNITS_DAY: 			return "E_SLI_UNITS_DAY"; break;
	case E_SLI_UNITS_HOUR: 			return "E_SLI_UNITS_HOUR"; break;
	case E_SLI_UNITS_MINUTE: 		return "E_SLI_UNITS_MINUTE"; break;
	case E_SLI_UNITS_SECOND: 		return "E_SLI_UNITS_SECOND"; break;
	case E_SLI_OP: 				return "E_SLI_OP"; break;
	case E_SLI_BETWEEN: 			return "E_SLI_BETWEEN"; break;
	case E_SLI_NOT_BETWEEN: 		return "E_SLI_NOT_BETWEEN"; break;
	case E_SLI_DATETIME: 			return "E_SLI_DATETIME"; break;
	case E_SLI_INTERVAL: 			return "E_SLI_INTERVAL"; break;
	case E_SLI_EXTEND: 			return "E_SLI_EXTEND"; break;
	case E_SLI_LITERAL: 			return "E_SLI_LITERAL"; break;
	//case E_SLI_EXISTS: 			return "E_SLI_EXISTS"; break;
	//case E_SLI_NOT_EXISTS: 			return "E_SLI_NOT_EXISTS"; break;
	case E_SLI_IN_VALUES: 				return "E_SLI_IN_VALUES"; break;
	case E_SLI_IN_SELECT: 				return "E_SLI_IN_SELECT"; break;
	case E_SLI_NOT_IN_SELECT: 			return "E_SLI_NOT_IN_SELECT"; break;
	case E_SLI_NOT_IN_VALUES: 			return "E_SLI_NOT_IN_VALUES"; break;
	case E_SLI_ISNULL: 			return "E_SLI_ISNULL"; break;
	case E_SLI_ISNOTNULL: 			return "E_SLI_ISNOTNULL"; break;
	case E_SLI_NOT: 			return "E_SLI_NOT"; break;
	//case E_SLI_CHECK: 			return "E_SLI_CHECK"; break;
	case E_SLI_REGEX_LIKE: 			return "E_SLI_REGEX_LIKE"; break;
	case E_SLI_REGEX_NOT_LIKE: 		return "E_SLI_REGEX_NOT_LIKE"; break;
	case E_SLI_REGEX_MATCHES: 		return "E_SLI_REGEX_MATCHES"; break;
	case E_SLI_REGEX_NOT_MATCHES: 		return "E_SLI_REGEX_NOT_MATCHES"; break;
	case E_SLI_REGEX_ILIKE: 		return "E_SLI_REGEX_ILIKE"; break;
	case E_SLI_REGEX_NOT_ILIKE: 		return "E_SLI_REGEX_NOT_ILIKE"; break;
	case E_SLI_FCALL: 			return "E_SLI_FCALL"; break;
	case E_SLI_ASC: 			return "E_SLI_ASC"; break;
	case E_SLI_DESC: 			return "E_SLI_DESC"; break;
	case E_SLI_IBIND: 			return "E_SLI_IBIND"; break;
	case E_SLI_VARIABLE: 			return "E_SLI_VARIABLE"; break;
	case E_SLI_SUBQUERY: 			return "E_SLI_SUBQUERY"; break;

	
	case E_SLI_COLUMN_NOT_TRANSFORMED: 	return "E_SLI_COLUMN_NOT_TRANSFORMED"; break;
	case E_SLI_JOIN: 	return "E_SLI_JOIN"; break;
	case E_SLI_QUERY_PLACEHOLDER: return "E_SLI_QUERY_PLACEHOLDER";

	}
return "Unknown";
}



char * make_sql_string_and_free (char *first, ...)
{
  va_list ap;
  char *ptr = 0;
  int l;
  char *next;
  int n;


  n = 0;
  va_start (ap, first);
  ptr = acl_strdup (first);


        if (first!=kw_comma && first!=kw_space && first!=kw_ob && first!=kw_cb) {
                A4GL_debug("FREE %p (%s)\n",first,first);
                if (A4GL_isyes(acl_getenv("FREE_SQL_MEM"))) {
                        free(first);
                }
                        first=0;
        }
  l = strlen (ptr);

  while (1)
    {
      n++;
      next = va_arg (ap, char *);
      if (next == 0)
        break;
      l += strlen (next);
      l++;                      /* Extra space...*/
      ptr = acl_realloc (ptr, l);
      strcat (ptr, next);
        if (next!=kw_comma && next!=kw_space && next!=kw_ob && next!=kw_cb) {
                A4GL_debug("FREE %p (%s)\n",next,next);
                if (A4GL_isyes(acl_getenv("FREE_SQL_MEM"))) {
                        free(next);
                }
        }
    }
  A4GL_debug("Generated : %s\n",ptr);
  return ptr;
}

static void make_list_item_list_from_select_list(struct s_select *select,struct s_select_list_item_list *p) {
	int a;
	if (p==0) return;
	for (a=0;a<p->nlist;a++) {
		make_list_item_list_from_select(select,p->list[a]);
	}
}



// In this function - we want to walk through all of the expressions ins our select list, where clause etc
// and construct a single list of all of these so we can go through the list for easy processing...
// 
static void 
make_list_item_list_from_select(struct s_select *select,struct s_select_list_item *p) {
if (p==0) return;

		add_select_list_item_list_once(&select->list_of_items,p);

		switch (p->type) {

			case E_SLI_NOT_IN_SELECT: 		
			case E_SLI_IN_SELECT: 			make_list_item_list_from_select(select,p->u_data.complex_expr.left);
			case E_SLI_OP: 				make_list_item_list_from_select(select,p->u_data.complex_expr.left),
								make_list_item_list_from_select(select,p->u_data.complex_expr.right);
								break;

			case E_SLI_NOT_IN_VALUES: 		
			case E_SLI_IN_VALUES: 			make_list_item_list_from_select(select, p->u_data.slil_expr.left);
								make_list_item_list_from_select_list(select,p->u_data.slil_expr.right_list);
								break;






			case E_SLI_REGEX_MATCHES:	       
			case E_SLI_REGEX_NOT_MATCHES:	  
			case E_SLI_REGEX_LIKE:	        	
			case E_SLI_REGEX_NOT_LIKE:	        	
			case E_SLI_REGEX_ILIKE:	        	
			case E_SLI_REGEX_NOT_ILIKE:	       	make_list_item_list_from_select(select,p->u_data.regex.val);
							       	make_list_item_list_from_select(select,p->u_data.regex.regex);
								break;

			case E_SLI_ISNULL:	        	
			case E_SLI_ISNOTNULL:	        	
			case E_SLI_ASC:	        		
			case E_SLI_DESC:	        	
			case E_SLI_NOT:	        		
			case E_SLI_BRACKET_EXPR:        	
			case E_SLI_UNITS_YEAR:			
			case E_SLI_UNITS_MONTH:			
			case E_SLI_UNITS_DAY:			
			case E_SLI_UNITS_HOUR:			
			case E_SLI_UNITS_MINUTE:		
			case E_SLI_UNITS_SECOND:		make_list_item_list_from_select(select,p->u_data.simple_op_expr.expr); 
								break;

			case E_SLI_BUILTIN_FUNC_YEAR:		
			case E_SLI_BUILTIN_FUNC_MONTH:		
			case E_SLI_BUILTIN_FUNC_DAY:		
			case E_SLI_BUILTIN_FUNC_DOW:		
			case E_SLI_BUILTIN_FUNC_WEEKDAY:	
			case E_SLI_BUILTIN_FUNC_MDY:		
			case E_SLI_BUILTIN_FUNC_DATE:		 make_list_item_list_from_select_list(select, p->u_data.builtin_fcall.params); 
								 break;



			case E_SLI_BUILTIN_AGG_AVG:		
			case E_SLI_BUILTIN_AGG_MAX:		
			case E_SLI_BUILTIN_AGG_MIN:		
			case E_SLI_BUILTIN_AGG_SUM:		
			case E_SLI_BUILTIN_AGG_COUNT:		make_list_item_list_from_select(select,p->u_data.agg_expr.expr); 
								break;

			case E_SLI_NOT_BETWEEN:
			case E_SLI_BETWEEN: 			make_list_item_list_from_select(select,p->u_data.between_expr.val);
								make_list_item_list_from_select(select,p->u_data.between_expr.from);
								make_list_item_list_from_select(select,p->u_data.between_expr.to);
								break;


			case E_SLI_FCALL: 			make_list_item_list_from_select_list(select, p->u_data.fcall.params);
								break;


			case E_SLI_EXTEND: 			make_list_item_list_from_select(select,p->u_data.extend.expr);
								break;
					  	
			case E_SLI_SUBQUERY: 			make_list_in_subselect_stmt(select,p->u_data.subquery); 
								break;
 
			case E_SLI_SUBQUERY_EXPRESSION: 	make_list_item_list_from_select(select,p->u_data.sq_expression.sq);  
								break;
			default : ; 				// We don't care about doing any more with the others - as they don't have any embedded expressions...
		}

}


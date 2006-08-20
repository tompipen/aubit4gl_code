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
# $Id: sqlexpr.c,v 1.31 2006-08-20 12:35:36 mikeaubury Exp $
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

char *get_sli_type (enum e_sli type);
char *make_sql_string_and_free (char *first, ...);
char *kw_space = " ";
char *kw_comma = ",";
char *kw_ob = "(";
char *kw_cb = ")";
int place_holder_cnt = 0;
int dont_set_for_single_table = 0;

//char *get_select_list_item_list(struct s_select *select, struct s_select_list_item_list *i) ;
//char *get_select_list_item(struct s_select *select, struct s_select_list_item *p) ;
static char *get_select_list_item_i (struct s_select *select,
				     struct s_select_list_item *p);
static void make_list_item_list_from_select_list (struct s_select *select,
						  struct
						  s_select_list_item_list *p);
static void make_list_item_list_from_select (struct s_select *select,
					     struct s_select_list_item *p);
static char *find_tabname_for_alias (struct s_select *select, char *alias);
//void save_temp_table (char *tabname,int select_into);
//void load_temp_table (void);
void make_list_in_subselect_stmt (struct s_select *orig,
				  struct s_select *next);
void preprocess_sql_statement (struct s_select *select);
//struct s_table_list *A4GLSQLPARSE_add_table_to_table_list (struct s_table_list *tl, char *t, char *a);


int A4GL_has_column (char *t, char *c);
char * get_select_list_item_ob (struct s_select *select, struct s_select_list_item *p);

static struct s_select_list_item *
empty_select_list_item (enum e_sli type)
{
  struct s_select_list_item *p;
  p = malloc (sizeof (struct s_select_list_item));
  p->type = type;
  p->alias = 0;
  p->sign = 0;
  return p;
}


struct s_select_list_item_list *
new_select_list_item_list (struct s_select_list_item *i)
{
  struct s_select_list_item_list *p;
  p = malloc (sizeof (struct s_select_list_item_list));
  p->list = 0;
  p->nlist = 0;
  if (i)
    add_select_list_item_list (p, i);
  return p;
}

struct s_select_list_item_list *
add_select_list_item_list (struct s_select_list_item_list *p,
			   struct s_select_list_item *i)
{
  p->nlist++;
  p->list =
    realloc (p->list, sizeof (struct s_select_list_item *) * p->nlist);
  p->list[p->nlist - 1] = i;
  return p;
}


static struct s_select_list_item_list *
add_select_list_item_list_once (struct s_select_list_item_list *p,
				struct s_select_list_item *i)
{
  int a;
  if (p->nlist)
    {
      for (a = 0; a < p->nlist; a++)
	{
	  if (p->list[a] == i)
	    return p;
	}
    }
  return add_select_list_item_list (p, i);
}


struct s_select_list_item *
new_select_list_item_char (char *s)
{
  struct s_select_list_item *p;
  A4GL_assertion (1, "Is this used ?");
  p = empty_select_list_item (E_SLI_CHAR);
  p->u_data.expression = acl_strdup (s);
  return p;
}


struct s_select_list_item *
new_select_list_item_replace_var (char *s)
{
  struct s_select_list_item *p;
  p = empty_select_list_item (E_SLI_VAR_REPLACE);
  p->u_data.replace_var.replace_var = acl_strdup (s);
  return p;
}

struct s_select_list_item *
new_select_list_item_case (struct s_select_list_item *i)
{
  struct s_select_list_item *p;
  p = empty_select_list_item (E_SLI_CASE);
  p->u_data.sqlcase.nelements = 0;
  p->u_data.sqlcase.elements = 0;
  return append_select_list_item_case (p, i);
}

struct s_select_list_item *
append_select_list_item_case (struct s_select_list_item *l,
			      struct s_select_list_item *w)
{
  l->u_data.sqlcase.nelements++;
  l->u_data.sqlcase.elements =
    realloc (l->u_data.sqlcase.elements,
	     sizeof (struct s_sli_case_element *) *
	     l->u_data.sqlcase.nelements);
  l->u_data.sqlcase.elements[l->u_data.sqlcase.nelements - 1] = w;
  return l;
}

struct s_select_list_item *
new_select_list_item_case_element (struct s_select_list_item *w,
				   struct s_select_list_item *e)
{
  struct s_select_list_item *p;
  p = empty_select_list_item (E_SLI_CASE_ELEMENT);

  p->u_data.sqlcaseelement.condition = w;
  p->u_data.sqlcaseelement.response = e;
  return p;



}


struct s_select_list_item *
new_select_list_item_variable (char *s)
{
  struct s_select_list_item *p;
  p = empty_select_list_item (E_SLI_VARIABLE);
  p->u_data.expression = acl_strdup (s);
  return p;
}

struct s_select_list_item *
new_select_list_item_column_from_transform (char *s)
{
  struct s_select_list_item *p;
  if (strcmp (s, "?") == 0 || strcmp (s, "?@@PARAM@@?") == 0)
    {
      p = empty_select_list_item (E_SLI_QUERY_PLACEHOLDER);
      p->u_data.expression = acl_strdup (s);
      return p;
    }

  if (strchr (s, '.'))
    {
      char *b;
      char *ptr;
      struct ilist subscripts;
      b = acl_strdup (s);
      ptr = strchr (b, '.');
      *ptr = 0;
      ptr++;
      subscripts.i0 = 0;
      subscripts.i1 = 0;
      subscripts.i2 = 0;
      subscripts.i3 = 0;
      subscripts.i4 = 0;
      subscripts.i5 = 0;
      return new_select_list_item_col (b, ptr, &subscripts);


    }

  return new_select_list_item_col (0, s, 0);

  /* 
     p=empty_select_list_item(E_SLI_COLUMN_NOT_TRANSFORMED); // @@@ FIXME....
     p->u_data.expression=acl_strdup(s);
   */
  return p;
}


struct s_select_list_item *
new_select_list_item_literal (char *s)
{
  struct s_select_list_item *p;
  p = empty_select_list_item (E_SLI_LITERAL);
  p->u_data.expression = acl_strdup (s);
  return p;
}



struct s_select_list_item *
new_select_list_item_ibind (char *s)
{
  struct s_select_list_item *p;
  p = empty_select_list_item (E_SLI_IBIND);
  p->u_data.expression = acl_strdup (s);
  return p;
}

struct s_select_list_item *
new_select_list_item_datetime (char *s)
{
  struct s_select_list_item *p;
  p = empty_select_list_item (E_SLI_DATETIME);
  p->u_data.expression = acl_strdup (s);
  return p;
}

struct s_select_list_item *
new_select_list_item_extend (struct s_select_list_item *dt_expr, char *from,
			     char *to)
{
  struct s_select_list_item *p;
  p = empty_select_list_item (E_SLI_EXTEND);
  strcpy (p->u_data.extend.from, from);
  strcpy (p->u_data.extend.to, to);
  p->u_data.extend.expr = dt_expr;
  return p;
}


struct s_select_list_item *
new_select_list_item_interval (char *s)
{
  struct s_select_list_item *p;
  p = empty_select_list_item (E_SLI_INTERVAL);
  p->u_data.expression = acl_strdup (s);
  return p;
}

struct s_select_list_item *
new_select_list_item_col (char *t, char *c, struct ilist *subscripts)
{
  struct s_select_list_item *p;
  p = empty_select_list_item (E_SLI_COLUMN);

  p->u_data.column.tabname = 0;
  p->u_data.column.colname = 0;

  if (t)
    {
      p->u_data.column.tabname = acl_strdup (t);
    }
  if (c)
    {
      p->u_data.column.colname = acl_strdup (c);
      A4GL_trim (c);
    }
  p->u_data.column.subscript.i0 = -1;
  p->u_data.column.subscript.i1 = -1;
  p->u_data.column.subscript.i2 = -1;
  p->u_data.column.subscript.i3 = -1;
  p->u_data.column.subscript.i4 = -1;
  p->u_data.column.subscript.i5 = -1;

  if (subscripts)
    {
      p->u_data.column.subscript.i0 = subscripts->i0;
      p->u_data.column.subscript.i1 = subscripts->i1;
      p->u_data.column.subscript.i2 = subscripts->i2;
      p->u_data.column.subscript.i3 = subscripts->i3;
      p->u_data.column.subscript.i4 = subscripts->i4;
      p->u_data.column.subscript.i5 = subscripts->i5;

    }
  return p;
}

struct s_select_list_item *
new_select_list_item_sq (enum sq_expression_type type,
			 struct s_select_list_item *s)
{
  struct s_select_list_item *p;
  p = empty_select_list_item (E_SLI_SUBQUERY_EXPRESSION);
  p->u_data.sq_expression.type = type;
  p->u_data.sq_expression.sq = s;
  return p;
}


struct s_select_list_item *
new_select_list_item_builtin_const (enum e_sli type)
{
  struct s_select_list_item *p;
  p = empty_select_list_item (type);
  return p;
}


struct s_select_list_item *
new_select_list_item_agg1 (enum e_sli type, char *aud,
			   struct s_select_list_item *i)
{
  struct s_select_list_item *p;
  p = empty_select_list_item (type);
  strcpy (p->u_data.agg_expr.aud, aud);
  p->u_data.agg_expr.expr = i;
  return p;
}


struct s_select_list_item *
new_select_list_item_op_sli (struct s_select_list_item *left,
			     struct s_select_list_item *right, enum e_sli op)
{
  struct s_select_list_item *p;
  p = empty_select_list_item (op);
  p->u_data.sli_expr.left = left;
  p->u_data.sli_expr.right = right;
  return p;
}

struct s_select_list_item *
new_select_list_item_op_slil (struct s_select_list_item *left,
			      struct s_select_list_item_list *right,
			      enum e_sli op)
{
  struct s_select_list_item *p;
  p = empty_select_list_item (op);
  p->u_data.slil_expr.left = left;
  p->u_data.slil_expr.right_list = right;
  return p;
}

struct s_select_list_item *
new_select_list_item_op_expr (struct s_select_list_item *left,
			      struct s_select_list_item *right, char *op)
{
  struct s_select_list_item *p;
  p = empty_select_list_item (E_SLI_OP);
  p->u_data.complex_expr.left = left;
  p->u_data.complex_expr.right = right;
  strcpy (p->u_data.complex_expr.op, op);
  return p;
}

struct s_select_list_item *
new_select_list_item_op_between (char *not, struct s_select_list_item *v,
				 struct s_select_list_item *from,
				 struct s_select_list_item *to,
				 int not_between)
{
  struct s_select_list_item *p;
  if (not_between)
    {
      p = empty_select_list_item (E_SLI_NOT_BETWEEN);
    }
  else
    {
      p = empty_select_list_item (E_SLI_BETWEEN);
    }
  p->u_data.between_expr.val = v;
  p->u_data.between_expr.from = from;
  p->u_data.between_expr.to = to;
  return p;
}

struct s_select_list_item *
new_select_list_item_fcall (char *fname,
			    struct s_select_list_item_list *params)
{
  struct s_select_list_item *p;
  p = empty_select_list_item (E_SLI_FCALL);
  strcpy (p->u_data.fcall.fname, fname);
  p->u_data.fcall.params = params;
  return p;
}



struct s_select_list_item *
new_select_list_item_builtin_fcall (enum e_sli type,
				    struct s_select_list_item_list *params)
{
  struct s_select_list_item *p;
  p = empty_select_list_item (type);
  p->u_data.builtin_fcall.params = params;
  return p;
}


struct s_select_list_item *
new_select_list_item_simple_expr (enum e_sli type,
				  struct s_select_list_item *expr)
{
  struct s_select_list_item *p;
  p = empty_select_list_item (type);
  p->u_data.simple_op_expr.expr = expr;
  return p;
}


struct s_select_list_item *
new_select_list_item_regex (enum e_sli type, struct s_select_list_item *val,
			    struct s_select_list_item *regex, char *escape)
{
  struct s_select_list_item *p;
  p = empty_select_list_item (type);
  p->u_data.regex.val = val;
  p->u_data.regex.regex = regex;
  strcpy (p->u_data.regex.escape, escape);
  return p;
}



struct s_select_list_item *
new_select_list_subquery (struct s_select *s)
{
  struct s_select_list_item *p;
  p = empty_select_list_item (E_SLI_SUBQUERY);
  p->u_data.subquery = s;
  return p;
}


struct s_select *
new_empty_select (void)
{
  struct s_select *p;
  p = malloc (sizeof (struct s_select));
  p->modifier = 0;
  p->limit.start = -1;
  p->limit.end = -1;
  p->limit.offset = -1;
  p->ncolumns = 0;
  p->select_list = 0;
  p->first = 0;
  p->table_elements.ntables = 0;
  p->table_elements.tables = 0;
  p->group_by = 0;
  p->having = 0;
  p->list_of_items.nlist = 0;
  p->list_of_items.list = 0;
  p->where_clause = 0;
  p->next = 0;
  p->sf = 0;
  p->union_op = 0;
  p->into = 0;
  p->extra_statement = 0;



  return p;
}



char * fix_delete_update_columns (char *table, struct s_select_list_item *i)
{
// This is passed a where clause - so we need to go 
  struct s_select *select;
  char *s;
  //extern char current_upd_table[];
  select = new_empty_select ();
  select->select_list =
    new_select_list_item_list (new_select_list_item_literal ("1"));
  select->where_clause = i;
  select->first = A4GLSQLPARSE_new_tablename (table, 0);
  s = make_select_stmt (select);
  s = strstr (s, "WHERE ") + 6;
  return s;
}



static char *
decode_month (char m1, char m2)
{
  static char buff[20];
  int m1i = -1;
  int m2i = -1;
  sprintf (buff, "%c%c", m1, m2);
  if (m1 >= '0' && m1 <= '9')
    {
      m1i = m1 - '0';
    }
  if (m2 >= '0' && m2 <= '9')
    {
      m2i = m2 - '0';
    }
  if (m1i >= 0 && m2i >= 0)
    {
      m1i = m1i * 10 + m2i;
      if (m1i < 1 || m1i > 12)
	return buff;		// Well - thats stuffed!
      strcpy (buff, A4GL_find_str_resource_int ("_MON", m1i));
    }
  return buff;
}

char *
get_select_list_item_list_ob (struct s_select *select,
			      struct s_select_list_item_list *i)
{
  char *buff = 0;
  char *buff2;
  int a;
  if (i == 0)
    return "";
  for (a = 0; a < i->nlist; a++)
    {
      if (a)
	{
	  buff2 = get_select_list_item_ob (select, i->list[a]);
	  buff = make_sql_string_and_free (buff, acl_strdup (","), buff2, 0);
	}
      else
	{
	  buff = get_select_list_item_ob (select, i->list[a]);
	}
      if (buff == 0)
	{
	  A4GL_assertion (1, "SHould be set to something");
	}
    }
  return buff;
}




char *
get_select_list_item_list (struct s_select *select,
			   struct s_select_list_item_list *i)
{
  char *buff = 0;
  char *buff2;
  int a;
  if (i == 0)
    return "";
  for (a = 0; a < i->nlist; a++)
    {
      if (a)
	{
	  buff2 = get_select_list_item (select, i->list[a]);
	  buff = make_sql_string_and_free (buff, acl_strdup (","), buff2, 0);
	}
      else
	{
	  buff = get_select_list_item (select, i->list[a]);
	}
      if (buff == 0)
	{
	  A4GL_assertion (1, "SHould be set to something");
	}
    }
  return buff;
}

char * get_select_list_item_ob (struct s_select *select, struct s_select_list_item *p)
{
  char *s;
  //char *ptr;
  //int a;
  dont_set_for_single_table = 1;
  s = get_select_list_item (select, p);
  dont_set_for_single_table = 0;
  return s;

}




char *
get_select_list_item (struct s_select *select, struct s_select_list_item *p)
{
  char *rval;
  char *rval2;
  rval = get_select_list_item_i (select, p);
  rval2 = acl_strdup (A4GLSQLCV_check_expr (rval));
  free (rval);
  rval = rval2;

  if (p->sign == '-')
    {
      rval = make_sql_string_and_free ("-", rval, 0);
    }

  if (p->alias)
    {
      if (A4GLSQLCV_check_runtime_requirement ("COLUMN_ALIAS_AS"))
	{
	  rval = make_sql_string_and_free (rval, " AS ", p->alias, 0);
	}
      else
	{
	  rval = make_sql_string_and_free (rval, " ", p->alias, 0);
	}
    }
  return rval;
}

static char *
get_select_list_item_i (struct s_select *select, struct s_select_list_item *p)
{
  // This is the guts of this code!
  A4GL_debug ("%d (%s)\n", p->type, get_sli_type (p->type));

  switch (p->type)
    {
    case E_SLI_CHAR:
      A4GL_assertion (1, "Not used");

    case E_SLI_IBIND:
      return acl_strdup (p->u_data.expression);
    case E_SLI_VARIABLE:
      return acl_strdup (p->u_data.expression);
    case E_SLI_DATETIME:
      return acl_strdup (p->u_data.expression);
    case E_SLI_INTERVAL:
      return acl_strdup (p->u_data.expression);

    case E_SLI_COLUMN_NOT_TRANSFORMED:
      	A4GL_debug("Not transformed : %s",p->u_data.expression);
      return acl_strdup (p->u_data.expression);

    case E_SLI_OP:
      return
	make_sql_string_and_free (get_select_list_item
				  (select, p->u_data.complex_expr.left),
				  acl_strdup (p->u_data.complex_expr.op),
				  get_select_list_item (select,
							p->u_data.
							complex_expr.right),
				  0);

      /*
         case E_SLI_JOIN:                             return make_sql_string_and_free(acl_strdup("JOIN("),get_select_list_item(select,p->u_data.complex_expr.left), 
         acl_strdup("="),
         get_select_list_item(select,p->u_data.complex_expr.right),acl_strdup(")"),0); 
       */


    case E_SLI_JOIN:
      return
	make_sql_string_and_free (get_select_list_item
				  (select, p->u_data.complex_expr.left),
				  acl_strdup ("="), get_select_list_item (select,
								      p->
								      u_data.
								      complex_expr.
								      right),
				  0);


    case E_SLI_IN_VALUES:
      return make_sql_string_and_free (get_select_list_item (select,
							     p->u_data.
							     slil_expr.left),
				       acl_strdup (" IN ("),
				       get_select_list_item_list (select,
								  p->u_data.
								  slil_expr.
								  right_list),
				       acl_strdup (")"), 0);

    case E_SLI_NOT_IN_VALUES:
      return make_sql_string_and_free (get_select_list_item (select,
							     p->u_data.
							     slil_expr.left),
				       acl_strdup (" NOT IN ("),
				       get_select_list_item_list (select,
								  p->u_data.
								  slil_expr.
								  right_list),
				       acl_strdup (")"), 0);


    case E_SLI_IN_SELECT:
      return
	make_sql_string_and_free (get_select_list_item
				  (select, p->u_data.complex_expr.left),
				  acl_strdup (" IN ("),
				  get_select_list_item (select,
							p->u_data.
							complex_expr.right),
				  kw_cb, 0);

    case E_SLI_NOT_IN_SELECT:
      return
	make_sql_string_and_free (get_select_list_item
				  (select, p->u_data.complex_expr.left),
				  acl_strdup (" NOT IN ("),
				  get_select_list_item (select,
							p->u_data.
							complex_expr.right), kw_cb, 0);

    case E_SLI_LITERAL:
      if (A4GLSQLCV_check_runtime_requirement ("DATE_STRING_TO_CAST_DATE"))
	{
	  if (p->u_data.expression[0] == '\'')
	    {
	      char buff[256];
	      if (isdigit (p->u_data.expression[1]) &&
		  isdigit (p->u_data.expression[2]) &&
		  p->u_data.expression[3] == '/' &&
		  isdigit (p->u_data.expression[4]) &&
		  isdigit (p->u_data.expression[5]) &&
		  p->u_data.expression[6] == '/' &&
		  isdigit (p->u_data.expression[7]) &&
		  isdigit (p->u_data.expression[8]) &&
		  isdigit (p->u_data.expression[9]) &&
		  isdigit (p->u_data.expression[10]))
		{		// Well - it looks like a date..

			
		  SPRINTF1 (buff, "Cast(%s as DateTime)",
			   p->u_data.expression);
		  return acl_strdup (buff);

		}
	    }
	}

      if (A4GLSQLCV_check_runtime_requirement ("DATE_STRING_TO_CAST_DMY"))
	{
	  if (p->u_data.expression[0] == '\'')
	    {
	      char buff[256];
	      if (isdigit (p->u_data.expression[1]) &&
		  isdigit (p->u_data.expression[2]) &&
		  p->u_data.expression[3] == '/' &&
		  isdigit (p->u_data.expression[4]) &&
		  isdigit (p->u_data.expression[5]) &&
		  p->u_data.expression[6] == '/' &&
		  isdigit (p->u_data.expression[7]) &&
		  isdigit (p->u_data.expression[8]) &&
		  isdigit (p->u_data.expression[9]) &&
		  isdigit (p->u_data.expression[10]))
		{		// Well - it looks like a date..
			char *dbdate;
		dbdate=A4GL_get_dbdate();
		if (dbdate[0]=='D'||dbdate[0]=='d') {
		  SPRINTF7 (buff, "Cast('%c%c %s %c%c%c%c' as DateTime)", 
								p->u_data.expression[1], p->u_data.expression[2],
				  				decode_month(p->u_data.expression[4], p->u_data.expression[5]), 
				  				p->u_data.expression[7], p->u_data.expression[8], p->u_data.expression[9], p->u_data.expression[10]
								);
		  return acl_strdup (buff);
		} else {
		  SPRINTF7 (buff, "Cast('%c%c %s %c%c%c%c' as DateTime)", 
								p->u_data.expression[4], p->u_data.expression[5],
				  				decode_month(p->u_data.expression[1], p->u_data.expression[2]), 
				  				p->u_data.expression[7], p->u_data.expression[8], p->u_data.expression[9], p->u_data.expression[10] 
								);
		  return acl_strdup (buff);
		}

		}
	    }
	}

      if (A4GLSQLCV_check_runtime_requirement ("DATE_STRING_TO_YMD"))
	{
	  if (p->u_data.expression[0] == '\'')
	    {
	      char buff[256];
	      if (isdigit (p->u_data.expression[1]) &&
		  isdigit (p->u_data.expression[2]) &&
		  p->u_data.expression[3] == '/' &&
		  isdigit (p->u_data.expression[4]) &&
		  isdigit (p->u_data.expression[5]) &&
		  p->u_data.expression[6] == '/' &&
		  isdigit (p->u_data.expression[7]) &&
		  isdigit (p->u_data.expression[8]) &&
		  isdigit (p->u_data.expression[9]) &&
		  isdigit (p->u_data.expression[10]))
		{		// Well - it looks like a date..
			char *dbdate;
		dbdate=A4GL_get_dbdate();
		if (dbdate[0]=='D'||dbdate[0]=='d') {
		  SPRINTF8 (buff, "'%c%c%c%c-%c%c-%c%c'", p->u_data.expression[7], p->u_data.expression[8],
				  	p->u_data.expression[9], p->u_data.expression[10], p->u_data.expression[4],
				  	p->u_data.expression[5], p->u_data.expression[1], p->u_data.expression[2]);
		  return acl_strdup (buff);
		} else {
		  SPRINTF8 (buff, "'%c%c%c%c-%c%c-%c%c'", p->u_data.expression[7], p->u_data.expression[8], p->u_data.expression[9], p->u_data.expression[10], 
				  		p->u_data.expression[1], p->u_data.expression[2], 
						p->u_data.expression[4], p->u_data.expression[5]);
		  return acl_strdup (buff);
		}

		}
	    }
	}

      return acl_strdup (p->u_data.expression);

    case E_SLI_REGEX_MATCHES:
      {
	char *p1;
	char *p2;
	p1 = get_select_list_item (select, p->u_data.regex.val);
	p2 = get_select_list_item (select, p->u_data.regex.regex);
	return make_sql_string_and_free (p1,
					 A4GLSQLCV_matches_string ("", p2,
								   p->u_data.
								   regex.
								   escape),
					 0);
      }

    case E_SLI_REGEX_NOT_MATCHES:
      {
	char *p1;
	char *p2;
	p1 = get_select_list_item (select, p->u_data.regex.val);
	p2 = get_select_list_item (select, p->u_data.regex.regex);
	return make_sql_string_and_free (p1,
					 A4GLSQLCV_matches_string (" NOT ",
								   p2,
								   p->u_data.
								   regex.
								   escape),
					 0);
      }
    case E_SLI_REGEX_LIKE:
      {
	char *p1;
	char *p2;
	p1 = get_select_list_item (select, p->u_data.regex.val);
	p2 = get_select_list_item (select, p->u_data.regex.regex);
	if (p->u_data.regex.escape && strlen (p->u_data.regex.escape))
	  {
	    return make_sql_string_and_free (p1, " LIKE ", p2,
					     p->u_data.regex.escape, 0);
	  }
	else
	  {
	    return make_sql_string_and_free (p1, " LIKE ", p2, 0);
	  }
      }
    case E_SLI_REGEX_NOT_LIKE:
      {
	char *p1;
	char *p2;
	p1 = get_select_list_item (select, p->u_data.regex.val);
	p2 = get_select_list_item (select, p->u_data.regex.regex);
	if (p->u_data.regex.escape && strlen (p->u_data.regex.escape))
	  {
	    return make_sql_string_and_free (p1, " NOT LIKE ", p2,
					     p->u_data.regex.escape, 0);
	  }
	else
	  {
	    return make_sql_string_and_free (p1, " NOT LIKE ", p2, 0);
	  }
      }
    case E_SLI_REGEX_ILIKE:
      {
	char *p1;
	char *p2;
	p1 = get_select_list_item (select, p->u_data.regex.val);
	p2 = get_select_list_item (select, p->u_data.regex.regex);
	if (p->u_data.regex.escape && strlen (p->u_data.regex.escape))
	  {
	    return make_sql_string_and_free (p1, " ILIKE ", p2,
					     p->u_data.regex.escape, 0);
	  }
	else
	  {
	    return make_sql_string_and_free (p1, " ILIKE ", p2, 0);
	  }
      }
    case E_SLI_REGEX_NOT_ILIKE:
      {
	char *p1;
	char *p2;
	p1 = get_select_list_item (select, p->u_data.regex.val);
	p2 = get_select_list_item (select, p->u_data.regex.regex);
	if (p->u_data.regex.escape && strlen (p->u_data.regex.escape))
	  {
	    return make_sql_string_and_free (p1, " NOT ILIKE ", p2,
					     p->u_data.regex.escape, 0);
	  }
	else
	  {
	    return make_sql_string_and_free (p1, " NOT ILIKE ", p2, 0);
	  }
      }

    case E_SLI_ISNULL:
      return
	make_sql_string_and_free (get_select_list_item
				  (select, p->u_data.simple_op_expr.expr),
				  acl_strdup (" IS NULL"), 0);
    case E_SLI_ISNOTNULL:
      return
	make_sql_string_and_free (get_select_list_item
				  (select, p->u_data.simple_op_expr.expr),
				  acl_strdup (" IS NOT NULL"), 0);
    case E_SLI_ASC:
      return
	make_sql_string_and_free (get_select_list_item
				  (select, p->u_data.simple_op_expr.expr),
				  acl_strdup (" ASC"), 0);
    case E_SLI_DESC:
      return
	make_sql_string_and_free (get_select_list_item
				  (select, p->u_data.simple_op_expr.expr),
				  acl_strdup (" DESC"), 0);
    case E_SLI_NOT:
      return make_sql_string_and_free (acl_strdup ("NOT("),
				       get_select_list_item (select,
							     p->u_data.
							     simple_op_expr.
							     expr),
				       acl_strdup (")"), 0);
    case E_SLI_BRACKET_EXPR:
      return make_sql_string_and_free (acl_strdup ("("),
				       get_select_list_item (select,
							     p->u_data.
							     simple_op_expr.
							     expr),
				       acl_strdup (")"), 0);
    case E_SLI_UNITS_YEAR:
      return
	make_sql_string_and_free (get_select_list_item
				  (select, p->u_data.simple_op_expr.expr),
				  acl_strdup (" UNITS YEAR"), 0);
    case E_SLI_UNITS_MONTH:
      return
	make_sql_string_and_free (get_select_list_item
				  (select, p->u_data.simple_op_expr.expr),
				  acl_strdup (" UNITS MONTH"), 0);
    case E_SLI_UNITS_DAY:
      return
	make_sql_string_and_free (get_select_list_item
				  (select, p->u_data.simple_op_expr.expr),
				  acl_strdup (" UNITS DAY"), 0);
    case E_SLI_UNITS_HOUR:
      return
	make_sql_string_and_free (get_select_list_item
				  (select, p->u_data.simple_op_expr.expr),
				  acl_strdup (" UNITS HOUR"), 0);
    case E_SLI_UNITS_MINUTE:
      return
	make_sql_string_and_free (get_select_list_item
				  (select, p->u_data.simple_op_expr.expr),
				  acl_strdup (" UNITS MINUTE"), 0);
    case E_SLI_UNITS_SECOND:
      return
	make_sql_string_and_free (get_select_list_item
				  (select, p->u_data.simple_op_expr.expr),
				  acl_strdup (" UNITS SECOND"), 0);
    case E_SLI_BUILTIN_CONST_TRUE:
      return acl_strdup (A4GLSQLCV_get_sqlconst ("TRUE"));
    case E_SLI_BUILTIN_CONST_FALSE:
      return acl_strdup (A4GLSQLCV_get_sqlconst ("FALSE"));
    case E_SLI_BUILTIN_CONST_USER:
      return acl_strdup (A4GLSQLCV_get_sqlconst ("USER"));
    case E_SLI_BUILTIN_CONST_TODAY:
      return acl_strdup (A4GLSQLCV_get_sqlconst ("TODAY"));
    case E_SLI_BUILTIN_CONST_TIME:
      return acl_strdup (A4GLSQLCV_get_sqlconst ("TIME"));
    case E_SLI_BUILTIN_CONST_STAR:
      return acl_strdup ("*");
    case E_SLI_BUILTIN_CONST_COUNT_STAR:
      return acl_strdup ("COUNT *");
    case E_SLI_BUILTIN_CONST_CURRENT:
      return acl_strdup ("CURRENT ");

    case E_SLI_BUILTIN_FUNC_YEAR:
      {
	char *params;
	char *rval;
	params =
	  get_select_list_item_list (select, p->u_data.builtin_fcall.params);
	rval = acl_strdup (A4GLSQLCV_sql_func ("YEAR", params));
	free (params);
	return rval;
      }
    case E_SLI_BUILTIN_FUNC_MONTH:
      {
	char *params;
	char *rval;
	params =
	  get_select_list_item_list (select, p->u_data.builtin_fcall.params);
	rval = acl_strdup (A4GLSQLCV_sql_func ("MONTH", params));
	free (params);
	return rval;
      }
    case E_SLI_BUILTIN_FUNC_DAY:
      {
	char *params;
	char *rval;
	params =
	  get_select_list_item_list (select, p->u_data.builtin_fcall.params);
	rval = acl_strdup (A4GLSQLCV_sql_func ("DAY", params));
	free (params);
	return rval;
      }
    case E_SLI_BUILTIN_FUNC_DOW:
      {
	char *params;
	char *rval;
	params =
	  get_select_list_item_list (select, p->u_data.builtin_fcall.params);
	rval = acl_strdup (A4GLSQLCV_sql_func ("DOW", params));
	free (params);
	return rval;
      }
    case E_SLI_BUILTIN_FUNC_WEEKDAY:
      {
	char *params;
	char *rval;
	params =
	  get_select_list_item_list (select, p->u_data.builtin_fcall.params);
	rval = acl_strdup (A4GLSQLCV_sql_func ("WEEKDAY", params));
	free (params);
	return rval;
      }
    case E_SLI_BUILTIN_FUNC_MDY:
      {
	char *params;
	char *rval;
	params =
	  get_select_list_item_list (select, p->u_data.builtin_fcall.params);
	rval = acl_strdup (A4GLSQLCV_sql_func ("MDY", params));
	free (params);
	return rval;
      }
    case E_SLI_BUILTIN_FUNC_DATE:
      {
	char *params;
	char *rval;
	params =
	  get_select_list_item_list (select, p->u_data.builtin_fcall.params);
	rval = acl_strdup (A4GLSQLCV_sql_func ("DATE", params));
	free (params);
	return rval;
      }
    case E_SLI_BUILTIN_AGG_AVG:
      return make_sql_string_and_free (acl_strdup ("AVG("),
				       p->u_data.agg_expr.aud,
				       get_select_list_item (select,
							     p->u_data.
							     agg_expr.expr),
				       acl_strdup (")"), 0);
    case E_SLI_BUILTIN_AGG_MAX:
      return make_sql_string_and_free (acl_strdup ("MAX("),
				       p->u_data.agg_expr.aud,
				       get_select_list_item (select,
							     p->u_data.
							     agg_expr.expr),
				       acl_strdup (")"), 0);
    case E_SLI_BUILTIN_AGG_MIN:
      return make_sql_string_and_free (acl_strdup ("MIN("),
				       p->u_data.agg_expr.aud,
				       get_select_list_item (select,
							     p->u_data.
							     agg_expr.expr),
				       acl_strdup (")"), 0);
    case E_SLI_BUILTIN_AGG_SUM:
      return make_sql_string_and_free (acl_strdup ("SUM("),
				       p->u_data.agg_expr.aud,
				       get_select_list_item (select,
							     p->u_data.
							     agg_expr.expr),
				       acl_strdup (")"), 0);
    case E_SLI_BUILTIN_AGG_COUNT:
      return make_sql_string_and_free (acl_strdup ("COUNT("),
				       p->u_data.agg_expr.aud,
				       get_select_list_item (select,
							     p->u_data.
							     agg_expr.expr),
				       acl_strdup (")"), 0);

    case E_SLI_BETWEEN:
      return
	make_sql_string_and_free (get_select_list_item
				  (select, p->u_data.between_expr.val),
				  acl_strdup (" BETWEEN "),
				  get_select_list_item (select,
							p->u_data.
							between_expr.from),
				  acl_strdup (" AND "),
				  get_select_list_item (select,
							p->u_data.
							between_expr.to), 0);
    case E_SLI_NOT_BETWEEN:
      return
	make_sql_string_and_free (get_select_list_item
				  (select, p->u_data.between_expr.val),
				  acl_strdup (" NOT BETWEEN "),
				  get_select_list_item (select,
							p->u_data.
							between_expr.from),
				  acl_strdup (" AND "),
				  get_select_list_item (select,
							p->u_data.
							between_expr.to), 0);


    case E_SLI_FCALL:
      	{
             char *params;
	     char *rval;
	     params = get_select_list_item_list (select, p->u_data.fcall.params);

	     rval = acl_strdup (A4GLSQLCV_sql_func (p->u_data.fcall.fname, params));
             free (params);
	     return rval;
	     	}
/*
      return make_sql_string_and_free (acl_strdup (A4GLSQLCV_sql_func(p->u_data.fcall.fname)),
				       kw_ob,
				       get_select_list_item_list (select,
								  p->u_data.
								  fcall.
								  params),
				       kw_cb, 0);
				       	*/


    case E_SLI_EXTEND:
      return make_sql_string_and_free (acl_strdup ("EXTEND ("),
				       get_select_list_item (select,
							     p->u_data.extend.
							     expr),
				       acl_strdup (","), p->u_data.extend.from,
				       acl_strdup (" TO "),
				       acl_strdup (p->u_data.extend.to), kw_cb,
				       0);

    case E_SLI_QUERY_PLACEHOLDER:
      if (A4GL_isyes (acl_getenv ("DOING_CM")))
	{
	  return acl_strdup ("?@@PARAM@@?");
	  //      @param_NNNN
	}
      else
	{
	  return acl_strdup ("?");
	}

    case E_SLI_COLUMN:
      {
	      char *rval;
	char buff[50] = "";
	if (p->u_data.column.subscript.i0 >= 1)
	  {
	      rval=acl_strdup (A4GLSQLCV_make_substr
		      (A4GLSQLCV_check_colname_alias
		       (p->u_data.column.tabname,
			find_tabname_for_alias (select,
						p->u_data.column.tabname),
			p->u_data.column.colname),
		       p->u_data.column.subscript.i0,
		       p->u_data.column.subscript.i1,
		       p->u_data.column.subscript.i2));
	      A4GL_debug("returning %s\n",rval);
	      return rval;
	  }
	A4GL_assertion (p->u_data.column.colname == 0,
			"Column name was null pointer");
	if (p->u_data.column.tabname)
	  {
	    char *orig;
	    char *rval;
	    orig = find_tabname_for_alias (select, p->u_data.column.tabname);
	    rval=acl_strdup (A4GLSQLCV_check_colname_alias (p->u_data.column.tabname, orig, p->u_data.column.colname));
	      A4GL_debug("returning %s\n",rval);
	      return rval;
	  }

	
	if (select)
	  {
	    if (select->table_elements.ntables == 1)
	      {

		if (A4GL_has_column
		    (select->table_elements.tables[0].tabname,
		     p->u_data.column.colname))
		  {
			  rval=
		      acl_strdup (A4GLSQLCV_check_colname
			      (select->table_elements.tables[0].tabname,
			       p->u_data.column.colname));
	      A4GL_debug("returning %s\n",rval);
			  return rval;
		  }
	      }
	  }

		rval = make_sql_string_and_free (acl_strdup (p->u_data.column.colname),
					 acl_strdup (buff), 0);
	      A4GL_debug("returning %s\n",rval);
		return rval;
      }


    case E_SLI_VAR_REPLACE: {
			char buff[256];
			SPRINTF1(buff,"@@VARIABLE[%s]@@",p->u_data.replace_var.replace_var);
			return strdup(buff);
		}



 
    case E_SLI_COLUMN_ORDERBY:
      {
	//char buff[50] = "";
	int a;
	if (p->u_data.column.subscript.i0 >= 1)
	  {
	    A4GL_assertion (p->u_data.column.colname == 0,
			    "Order by subscript not handled");
	  }

	if (p->u_data.column.tabname)
	  {
	    char *orig;
	    orig = find_tabname_for_alias (select, p->u_data.column.tabname);
	    return acl_strdup (A4GLSQLCV_check_colname_alias (p->u_data.column.tabname, orig, p->u_data.column.colname));
	  }
	if (select)
	  {
	    for (a = 0; a < select->select_list->nlist; a++)
	      {
		// Do we match to an alias ?
		if (select->select_list->list[a]->alias)
		  {
		    if (strcmp
			(select->select_list->list[a]->alias,
			 p->u_data.column.colname) == 0)
		      {
			return
			  make_sql_string_and_free (acl_strdup
						    (p->u_data.column.
						     colname), 0);
		      }
		  }
	      }

	    if (select->table_elements.ntables == 1)
	      {
		if (A4GL_has_column
		    (select->table_elements.tables[0].tabname,
		     p->u_data.column.colname))
		  {

			if (select->table_elements.tables[0].alias) {
		    return acl_strdup (A4GLSQLCV_check_colname_alias (
		select->table_elements.tables[0].alias,
		select->table_elements.tables[0].tabname
		, p->u_data.column.colname));
			} else {
		    return acl_strdup (A4GLSQLCV_check_colname (select->table_elements.tables[0].tabname, p->u_data.column.colname));
			}
		  }
	      }




	  }

	return make_sql_string_and_free (acl_strdup (p->u_data.column.colname),
					 0);
      }

    case E_SLI_CASE:
      return
	make_sql_string_and_free (A4GLSQLCV_make_case
				  (select, &p->u_data.sqlcase), 0);

    case E_SLI_CASE_ELEMENT:
      A4GL_assertion (1, "Elements shouldn't be printed in isolation...");
      return "";

    case E_SLI_SUBQUERY:
      return make_select_stmt (p->u_data.subquery);

    
    case E_SLI_SUBQUERY_EXPRESSION:
      switch (p->u_data.sq_expression.type)
	{
	case E_SQE_DONT_CARE:
	  return make_sql_string_and_free (kw_ob,
					   get_select_list_item (select,
								 p->u_data.
								 sq_expression.
								 sq), kw_cb,
					   0);
	case E_SQE_EXISTS:
	  return make_sql_string_and_free (acl_strdup ("EXISTS ("),
					   get_select_list_item (select,
								 p->u_data.
								 sq_expression.
								 sq), kw_cb,
					   0);

	case E_SQE_NOT_EXISTS:
	  return make_sql_string_and_free (acl_strdup ("NOT EXISTS ("),
					   get_select_list_item (select,
								 p->u_data.
								 sq_expression.
								 sq), kw_cb,
					   0);
	case E_SQE_ALL:
	  return make_sql_string_and_free (acl_strdup ("ALL ("),
					   get_select_list_item (select,
								 p->u_data.
								 sq_expression.
								 sq), kw_cb,
					   0);
	case E_SQE_ANY:
	  return make_sql_string_and_free (acl_strdup ("ANY ("),
					   get_select_list_item (select,
								 p->u_data.
								 sq_expression.
								 sq), kw_cb,
					   0);
	case E_SQE_SOME:
	  return make_sql_string_and_free (acl_strdup ("SOME ("),
					   get_select_list_item (select,
								 p->u_data.
								 sq_expression.
								 sq), kw_cb,
					   0);
	}

    }
  A4GL_assertion (1, "Shouldn't happen...");
  return "BADCOL";
}



char *
make_table_expression (struct s_select *select)
{
  char buff[20000];
  char buff_from[20000];
  //char into_temp[256];
  //char **select_cols;
  //int a;
  strcpy (buff, "");

  A4GLSQLPARSE_from_clause_collect_tables (select, select->first,
					   &select->table_elements);
  preprocess_sql_statement (select);
  A4GLSQLPARSE_from_clause (select, select->first, buff_from,
			    &select->table_elements);


  strcat (buff, buff_from);
  if (select->modifier)
    {
      if (strlen (select->modifier))
	A4GL_assertion (1, "Not expecting a modifier");
    }

  A4GL_assertion (select->having != 0, "Not expecting a HAVING");
  A4GL_assertion (select->group_by != 0, "Not expecting a GROUP BY");
  A4GL_assertion (select->sf != 0, "Not expecting and INTO TEMP or ORDER BY");
  A4GL_assertion (select->next != 0, "Not expecting a UNION");

  if (select->where_clause)
    {
      char *ptr;
      ptr = get_select_list_item (select, select->where_clause);
      strcat (buff, " WHERE ");
      strcat (buff, ptr);
      free (ptr);
    }

  return acl_strdup (buff);
}


void
make_list_in_subselect_stmt (struct s_select *orig, struct s_select *next)
{
  int a;

  for (a = 0; a < orig->table_elements.ntables; a++)
    {
      A4GLSQLPARSE_add_table_to_table_list (&next->table_elements,
					    orig->table_elements.tables[a].
					    tabname,
					    orig->table_elements.tables[a].
					    alias);
    }
}





char * find_table (struct s_select *select, struct s_select_list_item *i)
{
  int a;
  //char *colname;
  A4GL_assertion (i->type != E_SLI_COLUMN, "Expecting a column...");


  if (i->u_data.column.tabname == 0)
    {
      // Need to look into the database to see what tables contain this column
      // from our list of candidate tables....
    }


  if (i->u_data.column.tabname != 0)
    {
      for (a = 0; a < select->table_elements.ntables; a++)
	{
	  if (select->table_elements.tables[a].alias)
	    {
	      A4GL_assertion (i->u_data.column.tabname == 0,
			      "tabname shouldn't be null");

	      if (strcmp
		  (select->table_elements.tables[a].alias,
		   i->u_data.column.tabname) == 0)
		{
		  return select->table_elements.tables[a].tabname;
		}
	    }
	  if (strcmp
	      (select->table_elements.tables[a].tabname,
	       i->u_data.column.tabname) == 0)
	    {
	      return select->table_elements.tables[a].tabname;
	    }
	}
      FPRINTF (stderr, "Can't find table %s in FROM clause\n",
	       i->u_data.column.tabname);
      return i->u_data.column.tabname;
    }
  return "";
}


void
preprocess_sql_statement (struct s_select *select)
{
  int a;
  struct s_select_list_item *p;
  struct s_select_list_item *pnew;
  struct s_select_list_item_list *n;
  int expand_many;

//
// Lets collect all our expressions in one place....
//
  if (A4GLSQLCV_check_runtime_requirement ("EXPAND_COLUMNS"))
    {

      expand_many = 0;
      for (a = 0; a < select->select_list->nlist; a++)
	{
	  p = select->select_list->list[a];
	  if (select->select_list->list[a]->type == E_SLI_BUILTIN_CONST_STAR)
	    {
	      char *tname;
	      if (select->table_elements.ntables == 1)
		{
		  tname = select->table_elements.tables[0].tabname;
		  select->select_list->list[a] = new_select_list_item_col (acl_strdup (tname), "*", 0);
		}
	      else
		{
		  expand_many = 1;
		}
	    }
	}


      if (expand_many)
	{
	  n = new_select_list_item_list (0);

	  for (a = 0; a < select->select_list->nlist; a++)
	    {

	      p = select->select_list->list[a];

	      if (select->select_list->list[a]->type ==
		  E_SLI_BUILTIN_CONST_STAR)
		{
		  char *tname;
		  int b;
		  for (b = 0; b < select->table_elements.ntables; b++)
		    {
		      if (select->table_elements.tables[b].alias)
			{
			  tname = select->table_elements.tables[b].alias;
			}
		      else
			{
			  tname = select->table_elements.tables[b].tabname;
			}
		      A4GL_assertion (tname == 0, "No tablename?");
		      p = new_select_list_item_col (tname, "*", 0);
		      add_select_list_item_list (n, p);
		    }
		}
	      else
		{
		  add_select_list_item_list (n, p);
		  continue;
		}
	    }
	  select->select_list = n;
	}


      n = new_select_list_item_list (0);


      for (a = 0; a < select->select_list->nlist; a++)
	{
	  p = select->select_list->list[a];

	  if (p->type == E_SLI_COLUMN)
	    {
	      if (strcmp (p->u_data.column.colname, "*") != 0)
		{
		  add_select_list_item_list (n, p);
		  continue;
		}
	      else
		{
		  int isize = 0;
		  int idtype = 0;
		  char colname[256] = "";
		  int rval;
		  char *ccol = 0;
		  char *tname;

		  if (strcmp (p->u_data.column.tabname, "") == 0)
		    {
		      if (A4GL_isyes (acl_getenv ("SHOW_WARNING"))) {
		      PRINTF ("No tabname - got %d tables...\n", select->table_elements.ntables);
		      }
		      if (select->table_elements.ntables == 1 && !dont_set_for_single_table)	// A
			{
			  p->u_data.column.tabname =
			    select->table_elements.tables[0].tabname;
			}
		    }

		  if (strcmp (p->u_data.column.tabname, "") == 0)
		    {
		      if (A4GL_isyes (acl_getenv ("SHOW_WARNING"))) {
		      		PRINTF ("WARNING: No table specified for expansion - column expansion not possible\n");
		      }
		      add_select_list_item_list (n, p);
		      continue;
		    }

		  tname =
		    find_tabname_for_alias (select, p->u_data.column.tabname);

		  rval = A4GLSQL_get_columns (tname, colname, &idtype, &isize);

		  if (rval == 0)
		    {		//
		      if (A4GL_isyes (acl_getenv ("SHOW_WARNING")))
			{
			  FPRINTF (stderr,
				   "WARNING: Unable to locate %s in the database - column expansion not possible\n",
				   tname);
			}
			A4GLSQL_set_status(0,0);
	
		      add_select_list_item_list (n, p);
		      continue;
		    }

		  while (1)
		    {
		      colname[0] = 0;
		      ccol = 0;
		      rval = A4GLSQL_next_column (&ccol, &idtype, &isize);
		      if (rval == 0)
			{
			  break;
			}
		      A4GL_trim (ccol);
		      if (is_fake_rowid_column(ccol)) {continue;}

		      pnew =
			new_select_list_item_col (p->u_data.column.tabname,
						  ccol, 0);
		      add_select_list_item_list (n, pnew);
		    }
		  continue;
		}
	    }

	  if (p->type == E_SLI_COLUMN_NOT_TRANSFORMED)
	    {
	      add_select_list_item_list (n, p);
	      continue;
	    }

	  add_select_list_item_list (n, p);
	}
      select->select_list = n;
    }

  for (a = 0; a < select->select_list->nlist; a++)
    {
      make_list_item_list_from_select (select, select->select_list->list[a]);
    }
  make_list_item_list_from_select (select, select->where_clause);
  make_list_item_list_from_select_list (select, select->group_by);
  make_list_item_list_from_select (select, select->having);
// 
  A4GL_debug ("That appears to have %d elements",
	      select->list_of_items.nlist);
  for (a = 0; a < select->list_of_items.nlist; a++)
    {
      p = select->list_of_items.list[a];
      A4GL_debug ("%d %d - %s\n", a, p->type, get_sli_type (p->type));
      if (p->type == E_SLI_COLUMN)
	{
	  int b;
	  if (p->u_data.column.tabname == 0)
	    {
		    int nelements;
		    nelements=select->table_elements.ntables;
	      A4GL_debug ("No tabname for column : %s %d\n", p->u_data.column.colname, select->table_elements.ntables);
	      for (b = nelements-1; b >=0 ; b--) 
		{
		  char *t;
		  A4GL_debug ("Looking in %s\n",
			      select->table_elements.tables[b].tabname);
		  if (A4GL_isyes(acl_getenv ("NEVER_CONVERT"))) {
			  // Do nothing...
		  } else {
		  if (A4GL_has_column
		      (select->table_elements.tables[b].tabname,
		       p->u_data.column.colname))
		    {
		      t = select->table_elements.tables[b].alias;
		      if (!t) {
			      		t = select->table_elements.tables[b].tabname;
			}
		      
		      p->u_data.column.tabname = acl_strdup (t);
		      A4GL_debug ("Setting to %s\n", t);
		      break;
		    }
		  }
		}
	    }

	  if (p->u_data.column.tabname == 0 && 0)
	    {
	      A4GL_debug ("Unknown column : %s\n", p->u_data.column.colname);

	      if (select->table_elements.ntables == 1)
		{
		  char *t = "Unknown";
		  t = select->table_elements.tables[0].alias;
		  if (t == 0)
		    {
		      t = select->table_elements.tables[0].tabname;
		    }

		  p->u_data.column.tabname = acl_strdup (t);
		  A4GL_debug
		    ("   But as we only have one table - guessing its %s\n",
		     t);
		}


	    }
	  else
	    {
	      A4GL_debug ("<%s>.<%s>", p->u_data.column.tabname,
			  p->u_data.column.colname);
	    }
	}



      if (p->type == E_SLI_COLUMN_NOT_TRANSFORMED)
	{
	  A4GL_debug ("    Untransformed : %s\n", p->u_data.expression);
	}
      if (p->type == E_SLI_OP)
	{
	  A4GL_debug ("    OP=%s\n", p->u_data.complex_expr.op);
	}
    }

  A4GL_debug ("Done1");

  for (a = 0; a < select->list_of_items.nlist; a++)
    {
      p = select->list_of_items.list[a];
      if (p->type == E_SLI_OP)
	{
	  if (strcmp (p->u_data.complex_expr.op, "=") == 0)
	    {			// Possible join...
	      if (p->u_data.complex_expr.left->type == E_SLI_COLUMN
		  && p->u_data.complex_expr.right->type == E_SLI_COLUMN)
		{
		  char *lt;
		  char *rt;
		  struct s_select_list_item *l;
		  struct s_select_list_item *r;
		  l = p->u_data.complex_expr.left;
		  r = p->u_data.complex_expr.right;
		  // Looks like a join....
		  p->type = E_SLI_JOIN;


		  lt = find_table (select, l);
		  rt = find_table (select, r);




		}
	    }
	}
    }
}


char *
find_tabname_for_alias (struct s_select *select, char *alias)
{
  int a;
  if (!select)
    return alias;
  if (select->table_elements.ntables == 1)
    {
      if (select->table_elements.tables[0].alias)
	{
	  if (A4GL_aubit_strcasecmp (alias, select->table_elements.tables[0].alias) == 0)
	    {
	      return select->table_elements.tables[0].tabname;
	    }
	}
      return alias;
    }
  for (a = 0; a < select->table_elements.ntables; a++)
    {
      if (select->table_elements.tables[a].alias)
	{
	  if (A4GL_aubit_strcasecmp (alias, select->table_elements.tables[a].alias) == 0)
	    {
	      return select->table_elements.tables[a].tabname;
	    }
	}
    }
  return alias;
}


char *
make_select_stmt (struct s_select *select)
{
  char buff[40000];
  char buff_from[20000];
  char into_temp[25600];
  int a;

  A4GLSQLPARSE_from_clause_collect_tables (select, select->first,
					   &select->table_elements);
  preprocess_sql_statement (select);
  A4GLSQLPARSE_from_clause (select, select->first, buff_from,
			    &select->table_elements);


  A4GL_debug ("Has %d tables :\n", select->table_elements.ntables);
  for (a = 0; a < select->table_elements.ntables; a++)
    {
      char *tabname;
      char *alias;
      tabname = select->table_elements.tables[a].tabname;
      alias = select->table_elements.tables[a].alias;
      if (alias == 0)
	alias = "";
      A4GL_debug ("   %-20s %s\n", tabname, alias);
    }
  A4GL_debug ("\n");


  strcpy (buff, "SELECT ");
  A4GL_debug ("buff=%s", buff);


  if (select->modifier)
    {
      A4GL_debug ("buff=%s", buff);
      if (strlen (select->modifier))
	{
	  strcat (buff, select->modifier);
	  A4GL_debug ("buff=%s", buff);
	  strcat (buff, " ");
	  A4GL_debug ("buff=%s", buff);
	}
      A4GL_debug ("buff=%s", buff);
    }

  //select_cols=malloc(sizeof(char *)*select->select_list->nlist);

  A4GL_debug ("buff=%s", buff);
  for (a = 0; a < select->select_list->nlist; a++)
    {
      char *ptr;
      ptr = get_select_list_item (select, select->select_list->list[a]);
      if (a)
	strcat (buff, ",");
      strcat (buff, ptr);
      A4GL_debug ("buff=%s", buff);
      free (ptr);
    }

  strcat (buff, " ");

  A4GL_debug ("buff=%s", buff);
  if (select->into)
    {
      if (strlen (select->into))
	{
	  strcat (buff, select->into);
	  strcat (buff, " ");
	}
    }



  if (select->sf)
    {
      if (select->sf->into_temp)
	{
	  if (A4GLSQLCV_check_runtime_requirement ("SELECT_INTO_TEMP_INTO_TEMP_HASH"))
	    {
	      save_temp_table (select->sf->into_temp,1);
	      strcpy (into_temp, " INTO TEMP #");
	      strcat (into_temp, select->sf->into_temp);
	      strcat (buff, into_temp);
	      strcat (buff, " ");
	    }
	  if (A4GLSQLCV_check_runtime_requirement ("SELECT_INTO_TEMP_INTO_HASH"))
	    {   
	      save_temp_table (select->sf->into_temp,1);
	      strcpy (into_temp, " INTO #");
	      strcat (into_temp, select->sf->into_temp);
	      strcat (buff, into_temp);
	      strcat (buff, " ");
	    }
	}
    }




  strcat (buff, "FROM ");

  A4GL_debug ("buff=%s", buff);
  strcat (buff, buff_from);

  A4GL_debug ("buff=%s", buff);
  if (select->where_clause)
    {
      char *ptr;
      ptr = get_select_list_item (select, select->where_clause);
      strcat (buff, " WHERE ");
      strcat (buff, ptr);
      free (ptr);
    }

  A4GL_debug ("buff=%s", buff);
  if (select->group_by)
    {
      char *ptr;
      strcat (buff, " GROUP BY ");
      ptr = get_select_list_item_list (select, select->group_by);
      strcat (buff, ptr);
    }
  A4GL_debug ("buff=%s", buff);

  if (select->having)
    {
      char *ptr;
      strcat (buff, " HAVING ");
      ptr = get_select_list_item (select, select->having);
      strcat (buff, ptr);
    }

  A4GL_debug ("buff=%s", buff);

  if (select->next)
    {
      char *ptr;
      ptr = make_select_stmt (select->next);
      A4GL_debug ("ptr=%s", ptr);
      A4GL_debug ("buff=%s", buff);
      strcat (buff, " UNION ");
      A4GL_debug ("buff=%s", buff);
      if (select->union_op)
	{
	  strcat (buff, select->union_op);
	  A4GL_debug ("buff=%s", buff);
	  strcat (buff, " ");
	  A4GL_debug ("buff=%s", buff);
	}
      A4GL_debug ("buff=%s", buff);
      strcat (buff, ptr);
      A4GL_debug ("buff=%s", buff);
      free (ptr);
    }


  if (select->sf)
    {
      strcpy (into_temp, "");
      if (select->sf->into_temp)
	{
	  char *ptr;

	  if (select->sf->order_by)
	    {
	      if (!A4GLSQLCV_check_runtime_requirement ("STRIP_ORDER_BY_INTO_TEMP"))
		{
		  strcat (into_temp, " ORDER BY ");
		  strcat (into_temp,
			  get_select_list_item_list_ob (select,
							select->sf->
							order_by));
		}
	    }

	  if (!A4GLSQLCV_check_runtime_requirement ("SELECT_INTO_TEMP_INTO_TEMP_HASH")
	      && !A4GLSQLCV_check_runtime_requirement ("SELECT_INTO_TEMP_INTO_HASH"))
	    {
	      save_temp_table (select->sf->into_temp,1);
	      strcpy (into_temp, " INTO TEMP ");
	      strcat (into_temp, select->sf->into_temp);
	    }

	  if (select->sf->nolog)
	    {
	      if (!A4GLSQLCV_check_runtime_requirement ("OMIT_NO_LOG"))
		{
		  strcat (into_temp, " WITH NO LOG");
		}
	    }
	  ptr =
	    A4GLSQLCV_select_into_temp (buff, into_temp,
					select->sf->into_temp);

	  if (A4GLSQLCV_check_runtime_requirement ("SELECT_INTO_TEMP_AS_DECLARE_INSERT"))
	    {
		select->extra_statement = acl_malloc2(strlen (buff) + 200);
		SPRINTF2 (select->extra_statement,
			  "DECLARE GLOBAL TEMPORARY TABLE SESSION.%s AS ( %s ) "
			  "DEFINITION ONLY ON COMMIT PRESERVE ROWS",
			  select->sf->into_temp, buff);
	    }

	  strcpy (buff, ptr);
	  free (ptr);

	}
      else
	{
	  if (select->sf->order_by)
	    {
	      strcat (into_temp, " ORDER BY ");
	      strcat (into_temp,
		      get_select_list_item_list_ob (select,
						    select->sf->order_by));
	    }
	  strcat (buff, into_temp);
	}

    }
  A4GL_debug ("buff=%s", buff);



  A4GL_debug ("--->%s\n", buff);
  return acl_strdup (buff);

}





char *
get_sli_type (enum e_sli type)
{
  switch (type)
    {
    case E_SLI_CHAR:
      return "E_SLI_CHAR";
      break;
    case E_SLI_COLUMN:
      return "E_SLI_COLUMN";
      break;
    case E_SLI_SUBQUERY_EXPRESSION:
      return "E_SLI_SUBQUERY_EXPRESSION";
      break;
    case E_SLI_BUILTIN_CONST_TRUE:
      return "E_SLI_BUILTIN_CONST_TRUE";
      break;
    case E_SLI_BUILTIN_CONST_FALSE:
      return "E_SLI_BUILTIN_CONST_FALSE";
      break;
    case E_SLI_BUILTIN_CONST_USER:
      return "E_SLI_BUILTIN_CONST_USER";
      break;
    case E_SLI_BUILTIN_CONST_TODAY:
      return "E_SLI_BUILTIN_CONST_TODAY";
      break;
    case E_SLI_BUILTIN_CONST_TIME:
      return "E_SLI_BUILTIN_CONST_TIME";
      break;
    case E_SLI_BUILTIN_CONST_STAR:
      return "E_SLI_BUILTIN_CONST_STAR";
      break;
    case E_SLI_BUILTIN_CONST_COUNT_STAR:
      return "E_SLI_BUILTIN_CONST_COUNT_STAR";
      break;
    case E_SLI_BUILTIN_CONST_CURRENT:
      return "E_SLI_BUILTIN_CONST_CURRENT";
      break;
    case E_SLI_BUILTIN_FUNC_YEAR:
      return "E_SLI_BUILTIN_FUNC_YEAR";
      break;
    case E_SLI_BUILTIN_FUNC_MONTH:
      return "E_SLI_BUILTIN_FUNC_MONTH";
      break;
    case E_SLI_BUILTIN_FUNC_DAY:
      return "E_SLI_BUILTIN_FUNC_DAY";
      break;
    case E_SLI_BUILTIN_FUNC_MDY:
      return "E_SLI_BUILTIN_FUNC_MDY";
      break;
    case E_SLI_BUILTIN_FUNC_WEEKDAY:
      return "E_SLI_BUILTIN_FUNC_WEEKDAY";
      break;
    case E_SLI_BUILTIN_FUNC_DOW:
      return "E_SLI_BUILTIN_FUNC_DOW";
      break;
    case E_SLI_BUILTIN_FUNC_DATE:
      return "E_SLI_BUILTIN_FUNC_DATE";
      break;
    case E_SLI_BUILTIN_AGG_AVG:
      return "E_SLI_BUILTIN_AGG_AVG";
      break;
    case E_SLI_BUILTIN_AGG_MAX:
      return "E_SLI_BUILTIN_AGG_MAX";
      break;
    case E_SLI_BUILTIN_AGG_MIN:
      return "E_SLI_BUILTIN_AGG_MIN";
      break;
    case E_SLI_BUILTIN_AGG_SUM:
      return "E_SLI_BUILTIN_AGG_SUM";
      break;
    case E_SLI_BUILTIN_AGG_COUNT:
      return "E_SLI_BUILTIN_AGG_COUNT";
      break;
    case E_SLI_BRACKET_EXPR:
      return "E_SLI_BRACKET_EXPR";
      break;
    case E_SLI_UNITS_YEAR:
      return "E_SLI_UNITS_YEAR";
      break;
    case E_SLI_UNITS_MONTH:
      return "E_SLI_UNITS_MONTH";
      break;
    case E_SLI_UNITS_DAY:
      return "E_SLI_UNITS_DAY";
      break;
    case E_SLI_UNITS_HOUR:
      return "E_SLI_UNITS_HOUR";
      break;
    case E_SLI_UNITS_MINUTE:
      return "E_SLI_UNITS_MINUTE";
      break;
    case E_SLI_UNITS_SECOND:
      return "E_SLI_UNITS_SECOND";
      break;
    case E_SLI_OP:
      return "E_SLI_OP";
      break;
    case E_SLI_BETWEEN:
      return "E_SLI_BETWEEN";
      break;
    case E_SLI_NOT_BETWEEN:
      return "E_SLI_NOT_BETWEEN";
      break;
    case E_SLI_DATETIME:
      return "E_SLI_DATETIME";
      break;
    case E_SLI_INTERVAL:
      return "E_SLI_INTERVAL";
      break;
    case E_SLI_EXTEND:
      return "E_SLI_EXTEND";
      break;
    case E_SLI_LITERAL:
      return "E_SLI_LITERAL";
      break;
      //case E_SLI_EXISTS:                    return "E_SLI_EXISTS"; break;
      //case E_SLI_NOT_EXISTS:                        return "E_SLI_NOT_EXISTS"; break;
    case E_SLI_IN_VALUES:
      return "E_SLI_IN_VALUES";
      break;
    case E_SLI_IN_SELECT:
      return "E_SLI_IN_SELECT";
      break;
    case E_SLI_NOT_IN_SELECT:
      return "E_SLI_NOT_IN_SELECT";
      break;
    case E_SLI_NOT_IN_VALUES:
      return "E_SLI_NOT_IN_VALUES";
      break;
    case E_SLI_ISNULL:
      return "E_SLI_ISNULL";
      break;
    case E_SLI_ISNOTNULL:
      return "E_SLI_ISNOTNULL";
      break;
    case E_SLI_NOT:
      return "E_SLI_NOT";
      break;
      //case E_SLI_CHECK:                     return "E_SLI_CHECK"; break;
    case E_SLI_REGEX_LIKE:
      return "E_SLI_REGEX_LIKE";
      break;
    case E_SLI_REGEX_NOT_LIKE:
      return "E_SLI_REGEX_NOT_LIKE";
      break;
    case E_SLI_REGEX_MATCHES:
      return "E_SLI_REGEX_MATCHES";
      break;
    case E_SLI_REGEX_NOT_MATCHES:
      return "E_SLI_REGEX_NOT_MATCHES";
      break;
    case E_SLI_REGEX_ILIKE:
      return "E_SLI_REGEX_ILIKE";
      break;
    case E_SLI_REGEX_NOT_ILIKE:
      return "E_SLI_REGEX_NOT_ILIKE";
      break;
    case E_SLI_FCALL:
      return "E_SLI_FCALL";
      break;
    case E_SLI_ASC:
      return "E_SLI_ASC";
      break;
    case E_SLI_DESC:
      return "E_SLI_DESC";
      break;
    case E_SLI_IBIND:
      return "E_SLI_IBIND";
      break;
    case E_SLI_VARIABLE:
      return "E_SLI_VARIABLE";
      break;
    case E_SLI_SUBQUERY:
      return "E_SLI_SUBQUERY";
      break;


    case E_SLI_COLUMN_NOT_TRANSFORMED:
      return "E_SLI_COLUMN_NOT_TRANSFORMED";
      break;
    case E_SLI_JOIN:
      return "E_SLI_JOIN";
      break;
    case E_SLI_QUERY_PLACEHOLDER:
      return "E_SLI_QUERY_PLACEHOLDER";
    case E_SLI_CASE:
      return "E_SLI_CASE";
    case E_SLI_CASE_ELEMENT:
      return "E_SLI_CASE_ELEMENT";
    case E_SLI_COLUMN_ORDERBY:
      return "E_SLI_COLUMN_ORDERBY";
    case E_SLI_VAR_REPLACE:
      return "E_SLI_VAR_REPLACE";

    }
  return "Unknown";
}



char *
make_sql_string_and_free (char *first, ...)
{
  va_list ap;
  char *ptr = 0;
  int l;
  char *next;
  int n;


  n = 0;
  va_start (ap, first);
  ptr = acl_strdup (first);


  if (first != kw_comma && first != kw_space && first != kw_ob
      && first != kw_cb)
    {
      A4GL_debug ("FREE %p (%s)\n", first, first);
      if (A4GL_isyes (acl_getenv ("FREE_SQL_MEM")))
	{
	  free (first);
	}
      first = 0;
    }
  l = strlen (ptr);

  while (1)
    {
      n++;
      next = va_arg (ap, char *);
      if (next == 0)
	break;
      l += strlen (next);
      l++;			/* Extra space... */
      ptr = acl_realloc (ptr, l);
      strcat (ptr, next);
      if (next != kw_comma && next != kw_space && next != kw_ob
	  && next != kw_cb)
	{
	  A4GL_debug ("FREE %p (%s)\n", next, next);
	  if (A4GL_isyes (acl_getenv ("FREE_SQL_MEM")))
	    {
		    printf("Freeing : %s",next);
	      free (next);
	    }
	}
    }
  A4GL_debug ("Generated : %s\n", ptr);
  return ptr;
}

static void
make_list_item_list_from_select_list (struct s_select *select,
				      struct s_select_list_item_list *p)
{
  int a;
  if (p == 0)
    return;
  for (a = 0; a < p->nlist; a++)
    {
      make_list_item_list_from_select (select, p->list[a]);
    }
}



// In this function - we want to walk through all of the expressions ins our select list, where clause etc
// and construct a single list of all of these so we can go through the list for easy processing...
// 
static void
make_list_item_list_from_select (struct s_select *select,
				 struct s_select_list_item *p)
{
  if (p == 0)
    return;

  add_select_list_item_list_once (&select->list_of_items, p);

  switch (p->type)
    {

    case E_SLI_NOT_IN_SELECT:
    case E_SLI_IN_SELECT:
      make_list_item_list_from_select (select, p->u_data.complex_expr.left);
    case E_SLI_OP:
      make_list_item_list_from_select (select, p->u_data.complex_expr.left),
	make_list_item_list_from_select (select,
					 p->u_data.complex_expr.right);
      break;

    case E_SLI_NOT_IN_VALUES:
    case E_SLI_IN_VALUES:
      make_list_item_list_from_select (select, p->u_data.slil_expr.left);
      make_list_item_list_from_select_list (select,
					    p->u_data.slil_expr.right_list);
      break;






    case E_SLI_REGEX_MATCHES:
    case E_SLI_REGEX_NOT_MATCHES:
    case E_SLI_REGEX_LIKE:
    case E_SLI_REGEX_NOT_LIKE:
    case E_SLI_REGEX_ILIKE:
    case E_SLI_REGEX_NOT_ILIKE:
      make_list_item_list_from_select (select, p->u_data.regex.val);
      make_list_item_list_from_select (select, p->u_data.regex.regex);
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
    case E_SLI_UNITS_SECOND:
      make_list_item_list_from_select (select, p->u_data.simple_op_expr.expr);
      break;

    case E_SLI_BUILTIN_FUNC_YEAR:
    case E_SLI_BUILTIN_FUNC_MONTH:
    case E_SLI_BUILTIN_FUNC_DAY:
    case E_SLI_BUILTIN_FUNC_DOW:
    case E_SLI_BUILTIN_FUNC_WEEKDAY:
    case E_SLI_BUILTIN_FUNC_MDY:
    case E_SLI_BUILTIN_FUNC_DATE:
      make_list_item_list_from_select_list (select,
					    p->u_data.builtin_fcall.params);
      break;



    case E_SLI_BUILTIN_AGG_AVG:
    case E_SLI_BUILTIN_AGG_MAX:
    case E_SLI_BUILTIN_AGG_MIN:
    case E_SLI_BUILTIN_AGG_SUM:
    case E_SLI_BUILTIN_AGG_COUNT:
      make_list_item_list_from_select (select, p->u_data.agg_expr.expr);
      break;

    case E_SLI_NOT_BETWEEN:
    case E_SLI_BETWEEN:
      make_list_item_list_from_select (select, p->u_data.between_expr.val);
      make_list_item_list_from_select (select, p->u_data.between_expr.from);
      make_list_item_list_from_select (select, p->u_data.between_expr.to);
      break;


    case E_SLI_FCALL:
      make_list_item_list_from_select_list (select, p->u_data.fcall.params);
      break;


    case E_SLI_EXTEND:
      make_list_item_list_from_select (select, p->u_data.extend.expr);
      break;

    case E_SLI_SUBQUERY:
      make_list_in_subselect_stmt (select, p->u_data.subquery);
      break;

    case E_SLI_SUBQUERY_EXPRESSION:
      make_list_item_list_from_select (select, p->u_data.sq_expression.sq);
      break;
    default:;			// We don't care about doing any more with the others - as they don't have any embedded expressions...
    }

}

void
save_temp_table (char *tabname,int select_into)
{
  char *ptr;
  char buff[256];
  static int loaded = 0;
  FILE *f = 0;
  ptr = acl_getenv_not_set_as_0 ("WRITE_TEMP_TABLES");
  if (ptr == 0)
    return;

  if (!loaded)
    {
      loaded = 1;
      f = fopen (ptr, "r");
      if (f != 0)
	{
	  while (fgets (buff, sizeof (buff), f))
	    {
	      	char *ptr;
		int s_into=1;
		ptr=strchr(buff,' '); 
		if (ptr) {*ptr=0; ptr++; s_into=atoi(ptr)+2; }
	        A4GL_trim_nl (buff);
	        A4GL_add_pointer (buff, LOG_TEMP_TABLE, (void *) s_into);
	    }
	}
    }


  if (!A4GL_has_pointer (tabname, LOG_TEMP_TABLE))
    {
      f = fopen (ptr, "a");
      A4GL_add_pointer (tabname, LOG_TEMP_TABLE, (void *) (select_into+2));
      if (f)
	{
	  FPRINTF (f, "%s %d\n", tabname,select_into);
	  fclose (f);
	}
    }
}

void
load_temp_table (void)
{
  char *ptr;
  char buff[256];
  static int loaded = 0;
  FILE *f = 0;

  ptr = acl_getenv_not_set_as_0 ("READ_TEMP_TABLES");
  if (ptr == 0)
    return;

  if (!loaded)
    {
      loaded = 1;
      f = fopen (ptr, "r");
      if (f != 0)
	{
	  while (fgets (buff, sizeof (buff), f))
	    {
	      	char *ptr;
		int select_into=0;
		ptr=strchr(buff,' ');
		if (ptr) {*ptr=0; ptr++; select_into=atoi(ptr)+2; }
	        A4GL_trim_nl (buff);
	        A4GL_add_pointer (buff, LOG_TEMP_TABLE, (void *) select_into);
	    }
	}
    }


}


int A4GL_has_column (char *t, char *c)
{
  //char colname[256];
  int rc;
  char *cptr;
  int dtype;
  int size;
  int opened = 0;
  int found = 0;

  if (strcmp(acl_getenv("SQLTYPE"),"nosql")==0) {
	  return 0;
  }

  if (A4GL_isyes(acl_getenv ("NEVER_CONVERT"))) {
	  return 0;
  }

  if (A4GL_isyes(acl_getenv ("NEVER_CONVERT_COLUMNS"))) {
	  return 0;
  }

  rc = A4GLSQL_get_columns (t, "", &dtype, &size);
  while (rc)
    {
      char *s = 0;
      opened++;
      rc = A4GLSQL_next_column (&cptr, &dtype, &size);
      if (!rc)
	break;
      s = acl_strdup (cptr);
      A4GL_trim (s);
      if (A4GL_aubit_strcasecmp (s, c) == 0)
	{
	  free (s);
	  found = 1;
	  break;
	}
      free (s);
    }

  if (opened)
    A4GLSQL_end_get_columns ();
			A4GLSQL_set_status(0,0);
  return found;
}

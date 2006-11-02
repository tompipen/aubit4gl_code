

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
# $Id: expr.c,v 1.2 2006-11-02 17:53:39 mikeaubury Exp $
# @TODO - Remove rep_cond & rep_cond_expr from everywhere and replace
# with struct expr_str equivalent
*/
#ifndef lint
static char const module_id[] =
  "$Id: expr.c,v 1.2 2006-11-02 17:53:39 mikeaubury Exp $";
#endif

#define CM

/**
 * @file
 * Generate .C & .H modules.
 *
 * Most of the functions implemented here are called by the parser.
 *
 * The goal is to generate a C program that implement the functionality of
 * the 4gl being compiled.
 */
//void A4GL_4glc_push_gen (int a, char *s);
/*
=====================================================================








                WHEN EDITING THIS FILE, PLEASE REMEMBER TO DO
                THE SAME CHANGES TO EQUIVALENT FILE(s) IN OTHER
                LANGUAGE OUTPUT TARGETS, LIKE:

                    compile_c.c
                    compile_c_gtk.c
                    compile_perl.c
                    API_lex.c
                    ...etc...











=====================================================================
*/

#define FGL_PLUS_PLUS
extern int doing_report_print;
/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "compile_perl.h"

/*
void ensure_dtype (struct expr_str *e, int dtype, int nonull);
void ensure_bool (struct expr_str *s, int notnull);
void ensure_smint (struct expr_str *s, int notnull);
void ensure_char (struct expr_str *s, int notnull);
void ensure_dtime (struct expr_str *s, int notnull);
//void ensure_date (struct expr_str *s, int notnull);
void ensure_int (struct expr_str *s, int notnull);
void ensure_decimal (struct expr_str *s, int notnull);
void ensure_smfloat (struct expr_str *s, int notnull);
void ensure_interval (struct expr_str *s, int notnull);
void ensure_byte (struct expr_str *s, int notnull);
*/


//extern FILE *meta_file;

/*
void set_suppress_newlines (void);
void clr_suppress_newlines (void);
*/
//char *expr_name (enum e_expr_type e);
void fix_compare (char *op, struct expr_str *s);
void log_compare (int a, int b);
//int expr_datatype (struct expr_str *p);
//char *valid_func_name (char *s);
int is_null_params (char *s);
//char *rettype_integer_internal_nn (int n, int nn);

//char *rettype_integer_internal (int n);


#define ONE_NOT_ZERO(x) (x?x:1)
#define FAKE_DTYPE_BOOL 15

void print_expr_list_comma (struct expr_str_list *l);
void real_print_expr (struct expr_str *ptr);
//void printc (char *fmt, ...);
//void printh (char *fmt, ...);
int find_function (char *f);
//char *use_scope (char *s);
int write_meta (void);
//void ensure_dtype (struct expr_str *e, int dtype, int notnull);
int param_type (char *f, int p);
//void ensure_date (struct expr_str *s);
//void ensure_char (struct expr_str *s);
void A4GL_print_expr_list_concat (struct expr_str_list *l);



//void ensure_int (struct expr_str *s, int notnull);

/**
 * Print the generated C code with the implementation of an expression.
 * called from API
 * @param ptr A pointer to an expr_str expression (structure that describes
 * an expression).
 */
void
LEXLIB_print_expr (void *ptr)
{
#ifdef DEBUG
  A4GL_debug ("via print_expr in lib");
#endif
  set_suppress_newlines ();
  real_print_expr (ptr);
  clr_suppress_newlines ();
}



static char *
cast_name (int n)
{
  static char buff[256];
  sprintf (buff, "%d", n);
  n = n & DTYPE_MASK;

  if (n == DTYPE_SMINT)
    return "Int32";		/* Int16 */
  if (n == DTYPE_INT)
    return "Int32";
  if (n == DTYPE_CHAR)
    return "String";
  if (n == DTYPE_FLOAT)
    return "Double";
  if (n == DTYPE_SMFLOAT)
    return "Float";
  if (n == DTYPE_DECIMAL)
    return "Decimal";
  if (n == DTYPE_DTIME)
    return "DateTime";
  if (n == DTYPE_INTERVAL)
    return "Interval";
  if (n == DTYPE_DATE)
    return "Date";
  return buff;
}

void
real_print_expr (struct expr_str *ptr)
{
  void *optr;
  int l;
  int r;
  int need_as_datetime = 0;
  char target[256];
  int upcasting;
  char casting;
  extern char curr_func[];
  A4GL_debug ("Print expr... %p", ptr);

  A4GL_assertion (ptr == 0, "can't print a null pointer...");

  while (ptr)
    {
      switch (ptr->expr_type)
	{
	  // These will never be implemented - because they dont make sense..
	case ET_EXPR_REDUCED:
	  A4GL_assertion (1, "ET_EXPR_REDUCED should never be printed");
	  break;
	case ET_EXPR_LAST:
	  A4GL_assertion (1, "ET_EXPR_LAST should never be printed");
	  break;
	case ET_EXPR_EXPR_LIST:
	  A4GL_assertion (1,
			  "ET_EXPR_EXPR_LIST can't be printed - print using A4GL_print_expr_list or A4GL_print_expr_list_concat");
	  break;
	case ET_EXPR_WORDWRAP:
	  // Wordwraps shouldn't be printed - in the report_print - the wrapped expression should be printed...
	  A4GL_assertion (1, "ET_EXPR_WORDWRAP should never be printed");
	  break;


	  // These should be implemented - but aren't yet... 
	case ET_EXPR_EXTERNAL:
	  A4GL_assertion (1,
			  "ET_EXPR_EXTERNAL has not been implented as an expression yet");
	  break;
	case ET_EXPR_OP_IN:
	  A4GL_assertion (1,
			  "ET_EXPR_OP_IN has not been implented as an expression yet");
	  break;
	case ET_EXPR_OP_NOT_IN:
	  A4GL_assertion (1,
			  "ET_EXPR_OP_NOTIN has not been implented as an expression yet");
	  break;


	case ET_EXPR_STRING:
	  printc ("%s", ptr->u_data.expr_char);
	  free (ptr->u_data.expr_char);
	  break;

	case ET_EXPR_PUSH_VARIABLE:
	  printc ("$%s",
		  use_scope (fixup_squares
			     (ptr->u_data.expr_push_variable->variable)));
	  //ptr->u_data.expr_push_variable->var_dtype);
	  break;

	case ET_EXPR_TIME:
	  printc ("time()");
	  break;
	case ET_EXPR_NULL:
	  printc ("null");
	  break;
	case ET_EXPR_TRUE:
	  printc ("true");
	  break;
	case ET_EXPR_FALSE:
	  printc ("false");
	  break;
	case ET_EXPR_NOT:
	  printc (" (!(");
	  real_print_expr (ptr->u_data.expr_expr);
	  printc ("))");
	  break;

	case ET_EXPR_NEG:
	  printc ("(0-");
	  real_print_expr (ptr->u_data.expr_expr);
	  printc (")");
	  break;

	case ET_EXPR_UPSHIFT:
	  printc ("upshift(");
	  real_print_expr (ptr->u_data.expr_expr);
	  printc (")");
	  break;

	case ET_EXPR_DOWNSHIFT:
	  printc ("downshift(");
	  real_print_expr (ptr->u_data.expr_expr);
	  printc (")");
	  break;

	case ET_EXPR_DATE_EXPR:
	  printc ("date()");
	  break;
/*
	case ET_EXPR_COLUMN:
	  if (doing_report_print)
	    {
	      printc ("%sset_column(_rep,", ispdf ());
	      real_print_expr (ptr->u_data.expr_expr);
	      printc (")");
	    }
	  else
	    {
	      printc ("ensure_column(");
	      real_print_expr (ptr->u_data.expr_expr);
	      printc (")");
	    }
	  break;
*/

	case ET_EXPR_TIME_EXPR:
	  printc ("time()");
	  break;
	case ET_EXPR_TODAY:
	  printc ("today()");
	  break;

	case ET_EXPR_ASCII:
	  printc ("Ascii(");
	  real_print_expr (ptr->u_data.expr_expr);
	  printc (")");
	  break;



#ifdef Nope
	case ET_EXPR_EXTEND:
	  printc ("Extend(");
	  ensure_dtime (ptr->u_data.expr_extend->expr, 1);
	  real_print_expr (ptr->u_data.expr_extend->expr);
	  printc (",%d", ptr->u_data.expr_extend->to);
	  printc (") /* end of extend */");
	  break;
#endif

#ifdef Nope
	case ET_EXPR_PAGENO:
	  printc ("_rep.page_no");
	  break;

	case ET_EXPR_LINENO:
	  printc ("(_rep.line_no-1)");
	  break;

	case ET_EXPR_AGGREGATE:
	  if (ptr->u_data.expr_agg->agg_type == 'C')
	    {
	      printc ("(this._g_%s_%s_%d)\n", A4GL_compiling_module_basename (), curr_func, ptr->u_data.expr_agg->expr_num);	// C
	    }
	  if (ptr->u_data.expr_agg->agg_type == 'P')
	    {
	      printc ("((Double)this._g_%s_%s_%d/(Double)this._g_%s_%s_%d)\n", A4GL_compiling_module_basename (), curr_func, ptr->u_data.expr_agg->expr_num, A4GL_compiling_module_basename (), curr_func, ptr->u_data.expr_agg->expr_num + 1);	// P
	    }
	  if (ptr->u_data.expr_agg->agg_type == 'A')
	    {
	      printc ("this.Report_%s.use_val_or_null_if_false(this._g_%s_%s_%d_used,this._g_%s_%s_%d)\n", curr_func, A4GL_compiling_module_basename (), curr_func, ptr->u_data.expr_agg->expr_num, A4GL_compiling_module_basename (), curr_func, ptr->u_data.expr_agg->expr_num);	//S
	    }
	  if (ptr->u_data.expr_agg->agg_type == 'N'
	      || ptr->u_data.expr_agg->agg_type == 'X')
	    {
	      printc ("(this._g_%s_%s_%d)\n", A4GL_compiling_module_basename (), curr_func, ptr->u_data.expr_agg->expr_num);	//N or X
	    }
	  if (ptr->u_data.expr_agg->agg_type == 'A')
	    {
	      printc ("(this._g_%s_%s_%d/(Double)this._g_%s_%s_%d)\n", A4GL_compiling_module (), curr_func, ptr->u_data.expr_agg->expr_num, A4GL_compiling_module_basename (), curr_func, ptr->u_data.expr_agg->expr_num + 1);	// A
	    }
	  break;

#endif

	case ET_EXPR_FCALL:

	  {
	    int a;
	    int b;
	    //char lib[255];
	    //int params;
	    struct expr_str_list *l;
	    b = 0;


	    l = ptr->u_data.expr_function_call->parameters;
	    l = A4GL_rationalize_list (l);


	    printc ("%s(",
		    valid_func_name (ptr->u_data.expr_function_call->fname));

	    if (l)
	      {
		for (a = 0; a < l->nlist; a++)
		  {
		    if (a)
		      printc (",");
		    //ensure_dtype (l->list[a], param_type (ptr->u_data.expr_function_call-> fname, a) & DTYPE_MASK, is_null_params (ptr->u_data.  expr_function_call->fname));
		    print_expr (l->list[a]);
		  }
	      }
	    printc (")");
	  }
	  break;


	case ET_EXPR_FCALL_SINGLE:

	  {
	    int a;
	    int b;
	    //char lib[255];
	    //int params;
	    struct expr_str_list *l;
	    b = 0;


	    l = ptr->u_data.expr_function_call->parameters;
	    l = A4GL_rationalize_list (l);

	    printc ("%s(",
		    valid_func_name (ptr->u_data.expr_function_call->fname));

	    if (l)
	      {
		for (a = 0; a < l->nlist; a++)
		  {
		    if (a)
		      printc (",");
		    //ensure_dtype (l->list[a], param_type (ptr->u_data.expr_function_call-> fname, a) & DTYPE_MASK, is_null_params (ptr->u_data.  expr_function_call->fname));
		    print_expr (l->list[a]);
		  }
	      }
	    printc (")");
	  }
	  break;

	case ET_EXPR_SUBSTRING:
	  if (ptr->u_data.expr_substring->type != 0)
	    {

	      if (strcmp (ptr->u_data.expr_substring->substring_end, "0") ==
		  0)
		{
		  ptr->u_data.expr_substring->substring_end =
		    ptr->u_data.expr_substring->substring_start;
		}
	      printc ("substring($%s,%s,%s)",
		      use_scope (fixup_squares (ptr->u_data.expr_substring->str)),
		      ptr->u_data.expr_substring->substring_start,
		      ptr->u_data.expr_substring->substring_end);
	    }
	  else
	    {
	      printc ("substring($%s, %s,%s)",
		      use_scope (fixup_squares
				 (ptr->u_data.expr_substring->str)),
		      ptr->u_data.expr_substring->substring_start,
		      ptr->u_data.expr_substring->substring_start);
	    }
	  break;


	case ET_EXPR_REPORT_PRINTER:
	  printc ("getenv(\"DBPRINT\")");
	  break;

	case ET_EXPR_REPORT_EMAIL:
	  printc ("A4GL_push_char(A4GL_get_tmp_rep(module_name,\"%s\"));",
		  ptr->u_data.expr_string);
	  break;


	case ET_EXPR_LITERAL_LONG:
	  printc ("%d", ptr->u_data.expr_long);
	  break;
	case ET_EXPR_LITERAL_STRING:
	  printc ("\"%s\"", ptr->u_data.expr_string);
	  break;
	case ET_EXPR_QUOTED_STRING:
	  printc ("%s", ptr->u_data.expr_string);
	  break;
	case ET_EXPR_LITERAL_DOUBLE_STR:
	  printc ("(\"%s\")", ptr->u_data.expr_string);
	  break;
	case ET_EXPR_OP_CLIP:
	  printc ("trim(");
	  real_print_expr (ptr->u_data.expr_expr);
	  printc (")");
	  break;

	case ET_EXPR_OP_ISNULL:
	  {
	    int d;
	    printc ("(");
	    real_print_expr (ptr->u_data.expr_expr);
	    printc (" == $null)");
	  }
	  break;

	case ET_EXPR_OP_ISNOTNULL:
	  {
	    int d;
	    printc (" (! (");
	    real_print_expr (ptr->u_data.expr_expr);
	    printc (" == $null))");
	  }
	  break;

	case ET_EXPR_OP_MATCHES:
	  printc ("matches(");
	  real_print_expr (ptr->u_data.expr_op->left);
	  printc (",");
	  real_print_expr (ptr->u_data.expr_op->right);
	  printc (",");
	  if (ptr->u_data.expr_op->escape)
	    {
	      real_print_expr (ptr->u_data.expr_op->right);
	    }
	  else
	    {
	      printc ("\"\\\\\"");
	    }
	  printc (")");
	  break;
	case ET_EXPR_OP_NOT_MATCHES:
	  printc ("not_matches(");
	  real_print_expr (ptr->u_data.expr_op->left);
	  printc (",");
	  real_print_expr (ptr->u_data.expr_op->right);
	  printc (",");
	  if (ptr->u_data.expr_op->escape)
	    {
	      real_print_expr (ptr->u_data.expr_op->right);
	    }
	  else
	    {
	      printc ("\"\\\\\"");
	    }
	  printc (")");
	  break;

	case ET_EXPR_OP_LIKE:
	  printc ("like(");
	  real_print_expr (ptr->u_data.expr_op->left);
	  printc (",");
	  real_print_expr (ptr->u_data.expr_op->right);
	  printc (",");
	  if (ptr->u_data.expr_op->escape)
	    {
	      real_print_expr (ptr->u_data.expr_op->right);
	    }
	  else
	    {
	      printc ("\"\\\\\"");
	    }
	  printc (")");
	  break;

	case ET_EXPR_OP_NOT_LIKE:
	  printc ("not_like(");
	  real_print_expr (ptr->u_data.expr_op->left);
	  printc (",");
	  real_print_expr (ptr->u_data.expr_op->right);
	  printc (",");
	  if (ptr->u_data.expr_op->escape)
	    {
	      real_print_expr (ptr->u_data.expr_op->right);
	    }
	  else
	    {
	      printc ("\"\\\\\"");
	    }
	  printc (")");
	  break;


	case ET_EXPR_TEMP:
	  printc ("%s", ptr->u_data.expr_tmp->str);
	  break;

	case ET_EXPR_OP_ADD:
	  printc ("(");
	  real_print_expr (ptr->u_data.expr_op->left);
	  printc ("+");
	  real_print_expr (ptr->u_data.expr_op->right);
	  printc (")");
	  break;

	case ET_EXPR_OP_SUB:
	  printc ("(");
	  real_print_expr (ptr->u_data.expr_op->left);
	  printc ("-");
	  real_print_expr (ptr->u_data.expr_op->right);
	  printc (")");
	  break;

	case ET_EXPR_OP_DIV:
	  printc ("(");
	  real_print_expr (ptr->u_data.expr_op->left);
	  printc ("/");
	  real_print_expr (ptr->u_data.expr_op->right);
	  printc (")");
	  break;

	case ET_EXPR_OP_MULT:
	  printc ("(");
	  real_print_expr (ptr->u_data.expr_op->left);
	  printc ("*");
	  real_print_expr (ptr->u_data.expr_op->right);
	  printc (")");
	  break;

	case ET_EXPR_OP_LESS_THAN:
	  printc ("(");
	  real_print_expr (ptr->u_data.expr_op->left);
	  printc ("<");
	  real_print_expr (ptr->u_data.expr_op->right);
	  printc (")");
	  break;

	case ET_EXPR_OP_GREATER_THAN:
	  printc ("(");
	  real_print_expr (ptr->u_data.expr_op->left);
	  printc (">");
	  real_print_expr (ptr->u_data.expr_op->right);
	  printc (")");
	  break;

	case ET_EXPR_OP_EQUAL:
	  printc ("(");
	  real_print_expr (ptr->u_data.expr_op->left);
	  printc ("==");
	  real_print_expr (ptr->u_data.expr_op->right);
	  printc (")");
	  break;

	case ET_EXPR_OP_NOT_EQUAL:
	  printc ("(");
	  real_print_expr (ptr->u_data.expr_op->left);
	  printc ("!=");
	  real_print_expr (ptr->u_data.expr_op->right);
	  printc (")");
	  break;

	case ET_EXPR_OP_LESS_THAN_EQ:
	  printc ("(");
	  real_print_expr (ptr->u_data.expr_op->left);
	  printc ("<=");
	  real_print_expr (ptr->u_data.expr_op->right);
	  printc (")");
	  break;

	case ET_EXPR_OP_GREATER_THAN_EQ:
	  printc ("(");
	  real_print_expr (ptr->u_data.expr_op->left);
	  printc (">=");
	  real_print_expr (ptr->u_data.expr_op->right);
	  printc (")");
	  break;

	case ET_EXPR_OP_OR:
	  printc ("(");
	  real_print_expr (ptr->u_data.expr_op->left);
	  printc (" || ");
	  real_print_expr (ptr->u_data.expr_op->right);
	  printc (")");
	  break;
	case ET_EXPR_OP_AND:
	  printc ("(");
	  real_print_expr (ptr->u_data.expr_op->left);
	  printc (" && ");
	  real_print_expr (ptr->u_data.expr_op->right);
	  printc (")");
	  break;

	case ET_EXPR_LITERAL_EMPTY_STRING:
	  printc ("$EmptyString");
	  break;

	case ET_EXPR_OP_USING:
	  printc ("Using(");
	  //ensure_dtype (ptr->u_data.expr_op->left, expr_datatype (ptr->u_data.expr_op->left), 1);
	  real_print_expr (ptr->u_data.expr_op->left);
	  printc (",");
	  real_print_expr (ptr->u_data.expr_op->right);
	  printc (")");
	  //printc ("A4GL_pushop(OP_USING)");
	  break;

	case ET_EXPR_OP_MOD:
	  printc ("(");
	  real_print_expr (ptr->u_data.expr_op->left);
	  printc ("%%");
	  real_print_expr (ptr->u_data.expr_op->right);
	  printc (")");
	  break;

	case ET_EXPR_OP_POWER:
	  printc ("Power(");
	  //ensure_float (ptr->u_data.expr_op->left, 1);
	  //ensure_float (ptr->u_data.expr_op->right, 1);
	  real_print_expr (ptr->u_data.expr_op->left);
	  printc (",");
	  real_print_expr (ptr->u_data.expr_op->right);
	  printc (")");
	  break;

	case ET_EXPR_OP_CONCAT:
	  real_print_expr (ptr->u_data.expr_op->left);
	  printc (".");
	  real_print_expr (ptr->u_data.expr_op->right);
	  break;

	case ET_EXPR_OP_YEAR:
	  printc ("UnitsYear(");
	  real_print_expr (ptr->u_data.expr_expr);
	  printc (")");
	  break;
	case ET_EXPR_OP_MONTH:
	  printc ("UnitsMonth(");
	  real_print_expr (ptr->u_data.expr_expr);
	  printc (")");
	  break;
	case ET_EXPR_OP_DAY:
	  printc ("UnitsDay(");
	  real_print_expr (ptr->u_data.expr_expr);
	  printc (")");
	  break;
	case ET_EXPR_OP_HOUR:
	  printc ("UnitsHour(");
	  real_print_expr (ptr->u_data.expr_expr);
	  printc (")");
	  break;
	case ET_EXPR_OP_MINUTE:
	  printc ("UnitsMinute(");
	  real_print_expr (ptr->u_data.expr_expr);
	  printc (")");
	  break;
	case ET_EXPR_OP_SECOND:
	  printc ("UnitsSecond(");
	  real_print_expr (ptr->u_data.expr_expr);
	  printc (")");
	  break;

	case ET_EXPR_CURRENT:
	  printc ("current(%d,%d)",
		  ptr->u_data.expr_current->from,
		  ptr->u_data.expr_current->to);
	  break;

	case ET_EXPR_OP_SPACES:
	  printc ("spaces(");
	  real_print_expr (ptr->u_data.expr_expr);
	  printc (")");
	  break;

	  /*
	     case ET_EXPR_GET_FLDBUF:

	     printc ("this.Input_%s_%d.GetValueByName(%s)",
	     A4GL_compiling_module_basename (),
	     ptr->u_data.expr_get_fldbuf->sio_id,
	     ptr->u_data.expr_get_fldbuf->field_list->fields[0].field_name);

	     break;


	     case ET_EXPR_INFIELD:
	     printc ("this.Infield(%s)",
	     field_name_list_as_char (ptr->u_data.expr_infield->
	     field_list));
	     break;
	   */

	case ET_EXPR_YEAR_FUNC:
	  //ensure_date (ptr->u_data.expr_expr, 1);
	  printc ("Year(");
	  real_print_expr (ptr->u_data.expr_expr);
	  printc (")");
	  break;

	case ET_EXPR_MONTH_FUNC:
	  //ensure_date (ptr->u_data.expr_expr, 1);
	  printc ("Month(");
	  real_print_expr (ptr->u_data.expr_expr);
	  printc (")");
	  break;

	case ET_EXPR_DAY_FUNC:
	  //ensure_date (ptr->u_data.expr_expr, 1);
	  printc ("Day(");
	  real_print_expr (ptr->u_data.expr_expr);
	  printc (")");
	  break;

	case ET_EXPR_DATE_FUNC:
	  //ensure_char (ptr->u_data.expr_expr,0);
	  printc ("Cast_Date(");
	  real_print_expr (ptr->u_data.expr_expr);
	  printc (")");
	  break;

	case ET_EXPR_TIME_FUNC:
	  ensure_char (ptr->u_data.expr_expr, 0);
	  printc ("Time(");
	  real_print_expr (ptr->u_data.expr_expr);
	  printc (")");
	  break;

	case ET_EXPR_DTVAL:
	  printc ("DateTime(%s,%d)", ptr->u_data.expr_datetime->dtval,
		  ptr->u_data.expr_datetime->extend);
	  break;


	case ET_EXPR_IVAL_VAL:
	  printc ("TimeSpan(%s,%d)", ptr->u_data.expr_interval->intval,
		  ptr->u_data.expr_interval->extend);
	  break;


	case ET_EXPR_MM:
	case ET_EXPR_POINTS:
	case ET_EXPR_INCHES:
	case ET_EXPR_SHARED_FCALL:
	case ET_EXPR_MEMBER_FCALL:
	  A4GL_assertion (1, "Not used for CM module");

	case ET_EXPR_CONCAT_LIST:
	  A4GL_print_expr_list_concat (ptr->u_data.expr_list);
	  break;

	default:
	  printf ("%s\n", expr_name (ptr->expr_type));
	  A4GL_assertion (1, "Unhandled expression (1)");

	}

      optr = ptr;
      A4GL_debug ("going to %p", ptr->next);
      ptr = ptr->next;
      A4GL_debug ("Freeing old value %p", optr);


      free (optr);		// <----      THIS FREE SHOULD BE OK
      //
      //  if valgrind indicates its a problem - check
      //  you've got a 'break' after the case's above....
      //
    }
}


void
log_compare (int a, int b)
{
  FILE *g;
  return;
  g = fopen ("/tmp/compare.log", "a");
  if (a == 1)
    a = 2;
  if (b == 1)
    b = 2;
  fprintf (g, "Compare(op String,l %d, r %d)\n", a, b);
  fclose (g);


}


#ifdef NOPE
void
fix_compare (char *op, struct expr_str *s)
{
  int l;
  int r;
  int fixed = 0;

  //l = expr_datatype (s->u_data.expr_op->left) & DTYPE_MASK;
  //r = expr_datatype (s->u_data.expr_op->right) & DTYPE_MASK;


  // Comparing differing types...
  if (l == DTYPE_INT && r == DTYPE_SMINT)
    {
      ensure_int (s->u_data.expr_op->right, 0);
      fixed++;
    }

  if (l == DTYPE_DECIMAL && r == DTYPE_INT)
    {
      ensure_dtype (s->u_data.expr_op->right, DTYPE_DECIMAL, 0);
      fixed++;
    }

  if (l == DTYPE_DECIMAL && r == DTYPE_SMINT)
    {
      ensure_dtype (s->u_data.expr_op->right, DTYPE_DECIMAL, 0);
      fixed++;
    }

  if (l == DTYPE_DECIMAL && r == DTYPE_FLOAT)
    {
      ensure_dtype (s->u_data.expr_op->right, DTYPE_DECIMAL, 0);
      fixed++;
    }

  if (r == DTYPE_DECIMAL && l == DTYPE_FLOAT)
    {
      ensure_dtype (s->u_data.expr_op->left, DTYPE_DECIMAL, 0);
      fixed++;
    }

  if (l == DTYPE_SMINT && r == DTYPE_INT)
    {
      ensure_int (s->u_data.expr_op->left, 0);
      fixed++;
    }

  if (l == FAKE_DTYPE_BOOL && (r == DTYPE_INT || r == DTYPE_SMINT))
    {
      ensure_int (s->u_data.expr_op->left, 0);
      fixed++;
    }

  if (r == FAKE_DTYPE_BOOL && (l == DTYPE_INT || l == DTYPE_SMINT))
    {
      ensure_int (s->u_data.expr_op->right, 0);
      fixed++;
    }

  if ((l == DTYPE_INT || l == DTYPE_SMINT) && r == DTYPE_CHAR)
    {
      if (s->u_data.expr_op->right->expr_type == ET_EXPR_LITERAL_STRING)
	{
	  char *a;
	  a = strdup (s->u_data.expr_op->right->u_data.expr_string);
	  A4GL_trim (a);

	  if (strlen (a) == 0
	      && (strcmp (op, "<>") == 0 || strcmp (op, "=") == 0))
	    {
	      // Its a blank string...
	      // they mean is null or is not null
	      struct expr_str *l;
	      l = s->u_data.expr_op->left;
	      if (strcmp (op, "<>") == 0)
		{
		  s->expr_type = ET_EXPR_OP_ISNOTNULL;
		  s->u_data.expr_expr = l;
		  free (a);
		  return;
		}
	      if (strcmp (op, "=") == 0)
		{
		  s->expr_type = ET_EXPR_OP_ISNULL;
		  s->u_data.expr_expr = l;
		  free (a);
		  return;
		}
	    }
	  free (a);

	}
    }

  l = expr_datatype (s->u_data.expr_op->left) & DTYPE_MASK;
  r = expr_datatype (s->u_data.expr_op->right) & DTYPE_MASK;

  //printf ("COMPARE %s %d %d\n", op, l, r);
}


#endif




void
A4GL_print_expr_list_concat (struct expr_str_list *l)
{
  int a;
  struct expr_str *p;
  //struct expr_str *p2;
  //struct expr_str_list *l2;
  //int b;
  //int printed = 0;

  if (l == 0)
    return;
  l = A4GL_rationalize_list_concat (l);

  for (a = 0; a < l->nlist; a++)
    {
      p = l->list[a];
      if (p->expr_type == ET_EXPR_REDUCED)
	continue;
      ensure_char (l->list[a], 0);
      if (a)
	printc ("+");
      print_expr (l->list[a]);
      //if (printed) { printc ("A4GL_pushop(OP_CONCAT); /* 1 */\n"); }
      //printed++;

    }

}

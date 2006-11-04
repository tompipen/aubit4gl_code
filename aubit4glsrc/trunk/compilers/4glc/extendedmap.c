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
# $Id: extendedmap.c,v 1.4 2006-11-04 09:26:02 mikeaubury Exp $
#*/


/*
=====================================================================
		                    Includes
=====================================================================
*/

#include <stdarg.h>
#include "a4gl_4glc_int.h"
static void map_select_list_item (char *stmttype, struct s_select *select,
				  struct s_select_list_item *p);
static void map_select_list_item_list (char *stmttype, char *listtype,
				       struct s_select *select,
				       struct s_select_list_item_list *i);
char *find_tabname_for_alias (struct s_select *select, char *alias);
int A4GL_has_column (char *t, char *c);
int indent=1;
static enum e_mapset get_currmapset(void) ;



enum e_mapset {
	MAPSET_NONE,

	MAPSET_UI_OPENFORM,

	MAPSET_LIBCALL_WORKFLOW,
	MAPSET_LIBCALL_CORR,
	MAPSET_LIBCALL_AWB,
	MAPSET_LIBCALL,
	MAPSET_CALL,
	MAPSET_RUN,

	MAPSET_CRUD_SELECT,
	MAPSET_CRUD_UPDATE,
	MAPSET_CRUD_DELETE,
	MAPSET_CRUD_INSERT,
	MAPSET_CRUD_OTHER,
	MAPSET_UI,
	MAPSET_EVENTS,
	MAPSET_ENV,
	//MAPSET_DISPLAY_AT,


	MAPSET_LAST
};

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

extern FILE *crudfile;		/* The map file pointer opened file */
extern char curr_func[];
extern int yylineno;
extern char infilename[];
char *module_name_without_dirstart (char *s);
static int find_subqueries (char *stmttype, struct s_select *select, struct s_select_list_item *p) ;
static int print_subqueries(int sc) ;
static void dump_mapsets(void) ;
static void add_currmapset(enum e_mapset e) ;
static void rm_currmapset(void) ;
static void init_mapsets(void) ;
static void dump_mapset_to_crud(char *tag, enum e_mapset e) ;
static void dump_mapset(enum e_mapset e) ;

static int isSpecial (char *fname, char *lib,char *cat);
static void A4GL_add_xmlmap (enum e_mapset mapset, char *fmt, ...) ;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/


/*
=====================================================================
                    Functions definitions
=====================================================================
*/
struct {
	char **lines;
	int nlines;
} map_crud[100];

struct s_select *subq_stmts[2000];
//struct selects *subq_selects[2000];
int stmts_cnt=0;

enum e_mapset curr_mapset[100];
int curr_mapset_cnt=0;


static void init_mapsets(void) {
int a;
	for (a=0;a<100;a++) {
		map_crud[a].lines=0;
		map_crud[a].nlines=0;
	}
}


static void dump_mapset_to_crud(char *tag, enum e_mapset e) {
int a;
	FPRINTF(crudfile,"      <%s>\n",tag);

	for (a=0;a<map_crud[e].nlines;a++) {
		FPRINTF(crudfile,"         %s",map_crud[e].lines[a]);
		free(map_crud[e].lines[a]);
	}

	FPRINTF(crudfile,"      </%s>\n",tag);

	free(map_crud[e].lines);
	map_crud[e].lines=0;
	map_crud[e].nlines=0;
}

/*
void dump_mapset_to_crud_to_mapset(char *tag, enum e_mapset e,enum e_mapset e_dest) {
int a;
if (map_crud[e].nlines) {
	A4GL_add_xmlmap(e_dest,"CP<%s>\n",tag);

	for (a=0;a<map_crud[e].nlines;a++) {
		A4GL_add_xmlmap(e_dest,"CP%s", map_crud[e].lines[a]);
		free(map_crud[e].lines[a]);
	}
	A4GL_add_xmlmap(e_dest,"CP</%s>\n",tag);
	free(map_crud[e].lines);
	map_crud[e].lines=0;
	map_crud[e].nlines=0;
}
}
*/

static void dump_mapset(enum e_mapset e) {


	switch (e) {
		case MAPSET_NONE : 		dump_mapset_to_crud("Impossibles",e); break;
		case MAPSET_UI: 		dump_mapset_to_crud("UIs",e); break;
		case MAPSET_RUN: 		dump_mapset_to_crud("RUNS",e); break;
		case MAPSET_CRUD_SELECT: 	dump_mapset_to_crud("SELECTS",e); break;
		case MAPSET_CRUD_UPDATE: 	dump_mapset_to_crud("UPDATES",e); break;
		case MAPSET_CRUD_DELETE: 	dump_mapset_to_crud("DELETES",e); break;
		case MAPSET_CRUD_INSERT: 	dump_mapset_to_crud("INSERTS",e); break;
		case MAPSET_CRUD_OTHER: 	dump_mapset_to_crud("OTHERSQLS",e); break;
		case MAPSET_UI_OPENFORM: 	dump_mapset_to_crud("FORMS",e); break;
		case MAPSET_CALL: 		dump_mapset_to_crud("CALLS",e); break;
		case MAPSET_EVENTS: 		dump_mapset_to_crud("EVENTS",e); break;
		//case MAPSET_DISPLAY_AT: 	dump_mapset_to_crud("DISPLATATS",e); break;
		case MAPSET_LIBCALL_WORKFLOW: 	dump_mapset_to_crud("WORKFLOWCALLS",e); break;
		case MAPSET_LIBCALL_CORR: 	dump_mapset_to_crud("CORRESPONDANCECALLS",e); break;
		case MAPSET_LIBCALL_AWB: 	dump_mapset_to_crud("AWBCALLS",e); break;
		case MAPSET_LIBCALL: 		dump_mapset_to_crud("OTHERLIBCALLS",e); break;
		case MAPSET_ENV: 		dump_mapset_to_crud("ENVIRONMENTVARS",e); break;
		default : 	A4GL_assertion(1,"Unexpected");
	}
}

static void dump_mapsets(void) {
int a;
	for (a=0;a<100;a++) {
		if (map_crud[a].nlines) {
			dump_mapset(a);
		}
	}

}

static void add_currmapset(enum e_mapset e) {
	curr_mapset[curr_mapset_cnt++]=e;
}

static void rm_currmapset(void) {
	curr_mapset_cnt--;
}

static enum e_mapset get_currmapset(void) {
	return curr_mapset[curr_mapset_cnt-1];
}

static void A4GL_add_xmlmap (enum e_mapset mapset, char *fmt, ...) {
va_list args;
char buff[1025];
va_start (args, fmt);
vsprintf (buff, fmt, args);
map_crud[mapset].nlines++;
map_crud[mapset].lines=realloc(map_crud[mapset].lines,map_crud[mapset].nlines*sizeof(char *));
map_crud[mapset].lines[map_crud[mapset].nlines-1]=strdup(buff);
}





//
// CRUD mapping...
//
//
//


static void
map_select_list_item_list (char *stmttype, char *listtype,
			   struct s_select *select,
			   struct s_select_list_item_list *i)
{
  int a;
  if (i == 0)
    return;

  A4GL_add_xmlmap (get_currmapset(), "   <LIST_%s>\n", listtype);
  for (a = 0; a < i->nlist; a++)
    {
      map_select_list_item (stmttype, select, i->list[a]);
    }
  A4GL_add_xmlmap (get_currmapset(), "   </LIST_%s>\n", listtype);
}



static void
map_select_list_item_i (char *stmttype, struct s_select *select,
			struct s_select_list_item *p)
{
  switch (p->type)
    {
    case E_SLI_CHAR:
      A4GL_assertion (1, "Not used");
    case E_SLI_BUILTIN_CONST_COUNT_STAR:

    case E_SLI_IBIND:
    case E_SLI_VARIABLE:
    case E_SLI_DATETIME:
    case E_SLI_INTERVAL:
    case E_SLI_LITERAL:
    case E_SLI_BUILTIN_CONST_TRUE:
    case E_SLI_BUILTIN_CONST_FALSE:
    case E_SLI_QUERY_PLACEHOLDER:
    case E_SLI_VAR_REPLACE:
    case E_SLI_COLUMN_ORDERBY:	// Dont care about order bys..

      return;

    case E_SLI_COLUMN_NOT_TRANSFORMED:
      		A4GL_add_xmlmap (get_currmapset(), "<COLUMN NAME=\"%s\" />\n", p->u_data.expression);
      return;

    case E_SLI_OP:
      map_select_list_item (stmttype, select, p->u_data.complex_expr.left);
      map_select_list_item (stmttype, select, p->u_data.complex_expr.right);
      return;


    case E_SLI_JOIN:
      map_select_list_item (stmttype, select, p->u_data.complex_expr.left);
      map_select_list_item (stmttype, select, p->u_data.complex_expr.right);
      return;


    case E_SLI_IN_VALUES:
      map_select_list_item (stmttype, select, p->u_data.slil_expr.left);
      map_select_list_item_list (stmttype, "IN", select,
				 p->u_data.slil_expr.right_list);
      return;

    case E_SLI_NOT_IN_VALUES:
      map_select_list_item (stmttype, select, p->u_data.slil_expr.left);
      map_select_list_item_list (stmttype, "NOTIN", select,
				 p->u_data.slil_expr.right_list);
      return;


    case E_SLI_IN_SELECT:
      map_select_list_item (stmttype, select, p->u_data.complex_expr.left);
      map_select_list_item (stmttype, select, p->u_data.complex_expr.right);
      return;

    case E_SLI_NOT_IN_SELECT:
      map_select_list_item (stmttype, select, p->u_data.complex_expr.left);
      map_select_list_item (stmttype, select, p->u_data.complex_expr.right);
      return;

    case E_SLI_REGEX_MATCHES:
      map_select_list_item (stmttype, select, p->u_data.regex.val);
      map_select_list_item (stmttype, select, p->u_data.regex.regex);
      return;

    case E_SLI_REGEX_NOT_MATCHES:
      map_select_list_item (stmttype, select, p->u_data.regex.val);
      map_select_list_item (stmttype, select, p->u_data.regex.regex);
      return;
    case E_SLI_REGEX_LIKE:
      map_select_list_item (stmttype, select, p->u_data.regex.val);
      map_select_list_item (stmttype, select, p->u_data.regex.regex);
      return;

    case E_SLI_REGEX_NOT_LIKE:
      map_select_list_item (stmttype, select, p->u_data.regex.val);
      map_select_list_item (stmttype, select, p->u_data.regex.regex);
      return;
    case E_SLI_REGEX_ILIKE:
      map_select_list_item (stmttype, select, p->u_data.regex.val);
      map_select_list_item (stmttype, select, p->u_data.regex.regex);
      return;
    case E_SLI_REGEX_NOT_ILIKE:
      map_select_list_item (stmttype, select, p->u_data.regex.val);
      map_select_list_item (stmttype, select, p->u_data.regex.regex);
      return;
    case E_SLI_ISNULL:
      map_select_list_item (stmttype, select, p->u_data.simple_op_expr.expr);
      return;
    case E_SLI_ISNOTNULL:
      map_select_list_item (stmttype, select, p->u_data.simple_op_expr.expr);
      return;
    case E_SLI_ASC:
      map_select_list_item (stmttype, select, p->u_data.simple_op_expr.expr);
      return;
    case E_SLI_DESC:
      map_select_list_item (stmttype, select, p->u_data.simple_op_expr.expr);
      return;
    case E_SLI_NOT:
      map_select_list_item (stmttype, select, p->u_data.simple_op_expr.expr);
      return;

    case E_SLI_BRACKET_EXPR:
      map_select_list_item (stmttype, select, p->u_data.simple_op_expr.expr);
      return;
    case E_SLI_UNITS_YEAR:
      map_select_list_item (stmttype, select, p->u_data.simple_op_expr.expr);
      return;
    case E_SLI_UNITS_MONTH:
      map_select_list_item (stmttype, select, p->u_data.simple_op_expr.expr);
      return;
    case E_SLI_UNITS_DAY:
      map_select_list_item (stmttype, select, p->u_data.simple_op_expr.expr);
      return;
    case E_SLI_UNITS_HOUR:
      map_select_list_item (stmttype, select, p->u_data.simple_op_expr.expr);
      return;
    case E_SLI_UNITS_MINUTE:
      map_select_list_item (stmttype, select, p->u_data.simple_op_expr.expr);
      return;
    case E_SLI_UNITS_SECOND:
      map_select_list_item (stmttype, select, p->u_data.simple_op_expr.expr);
      return;



    case E_SLI_BUILTIN_CONST_USER:
      A4GL_add_xmlmap (get_currmapset(), "<COLUMN NAME=\"USER\" TYPE=\"BUILTIN\" />\n");
      return;
    case E_SLI_BUILTIN_CONST_TODAY:
      A4GL_add_xmlmap (get_currmapset(), "<COLUMN NAME=\"TODAY\" TYPE=\"BUILTIN\" />\n");
      return;
    case E_SLI_BUILTIN_CONST_TIME:
      A4GL_add_xmlmap (get_currmapset(), "<COLUMN NAME=\"TIME\" TYPE=\"BUILTIN\" />\n");
      return;
    case E_SLI_BUILTIN_CONST_STAR:
      A4GL_add_xmlmap (get_currmapset(), "<COLUMN NAME=\"*\"/>\n");
      return;

    case E_SLI_BUILTIN_CONST_CURRENT:
      A4GL_add_xmlmap (get_currmapset(), "<COLUMN NAME=\"CURRENT\" TYPE=\"BUILTIN\" />\n");
      return;

    case E_SLI_BUILTIN_FUNC_YEAR:
      map_select_list_item_list (stmttype, "PARAMETERS", select,
				 p->u_data.builtin_fcall.params);
      return;

    case E_SLI_BUILTIN_FUNC_MONTH:
      map_select_list_item_list (stmttype, "PARAMETERS", select,
				 p->u_data.builtin_fcall.params);
      return;
    case E_SLI_BUILTIN_FUNC_DAY:
      map_select_list_item_list (stmttype, "PARAMETERS", select,
				 p->u_data.builtin_fcall.params);
      return;
    case E_SLI_BUILTIN_FUNC_DOW:
      map_select_list_item_list (stmttype, "PARAMETERS", select,
				 p->u_data.builtin_fcall.params);
      return;
    case E_SLI_BUILTIN_FUNC_WEEKDAY:
      map_select_list_item_list (stmttype, "PARAMETERS", select,
				 p->u_data.builtin_fcall.params);
      return;
    case E_SLI_BUILTIN_FUNC_MDY:
      map_select_list_item_list (stmttype, "PARAMETERS", select,
				 p->u_data.builtin_fcall.params);
      return;
    case E_SLI_BUILTIN_FUNC_DATE:
      map_select_list_item_list (stmttype, "PARAMETERS", select,
				 p->u_data.builtin_fcall.params);
      return;

    case E_SLI_BUILTIN_AGG_AVG:
      map_select_list_item (stmttype, select, p->u_data.agg_expr.expr);
      return;

    case E_SLI_BUILTIN_AGG_MAX:
      map_select_list_item (stmttype, select, p->u_data.agg_expr.expr);
      return;

    case E_SLI_BUILTIN_AGG_MIN:
      map_select_list_item (stmttype, select, p->u_data.agg_expr.expr);
      return;

    case E_SLI_BUILTIN_AGG_SUM:
      map_select_list_item (stmttype, select, p->u_data.agg_expr.expr);
      return;

    case E_SLI_BUILTIN_AGG_COUNT:
      map_select_list_item (stmttype, select, p->u_data.agg_expr.expr);
      return;

    case E_SLI_BETWEEN:
      map_select_list_item (stmttype, select, p->u_data.between_expr.val);
      map_select_list_item (stmttype, select, p->u_data.between_expr.from);
      map_select_list_item (stmttype, select, p->u_data.between_expr.to);
      return;

    case E_SLI_NOT_BETWEEN:
      map_select_list_item (stmttype, select, p->u_data.between_expr.val);
      map_select_list_item (stmttype, select, p->u_data.between_expr.from);
      map_select_list_item (stmttype, select, p->u_data.between_expr.to);
      return;


    case E_SLI_FCALL:
      A4GL_add_xmlmap (get_currmapset(), "<SQLCALL NAME=\"%s\" LINENO=\"%d\"/>\n", p->u_data.fcall.fname, yylineno);
      map_select_list_item_list (stmttype, "PARAMETERS", select,
				 p->u_data.fcall.params);
      return;



    case E_SLI_EXTEND:
      map_select_list_item (stmttype, select, p->u_data.extend.expr);
      return;


    case E_SLI_COLUMN:
      if (p->u_data.column.colname == 0)
	return;
      if (p->u_data.column.tabname && strlen (p->u_data.column.tabname))
	{
	  A4GL_add_xmlmap (get_currmapset(), "<COLUMN NAME=\"%s\" TABLE=\"%s\" REALTABLE=\"%s\" />\n", p->u_data.column.colname, p->u_data.column.tabname, find_tabname_for_alias (select, p->u_data.column.tabname));
	  return;
	}
      else
	{

	  if (select)
	    {
	      int a;
	      int cnt;
	      if (select->table_elements.ntables == 1)
		{

		  if (A4GL_has_column
		      (select->table_elements.tables[0].tabname,
		       p->u_data.column.colname))
		    {
		      A4GL_add_xmlmap (get_currmapset(),
			       "<COLUMN NAME=\"%s\" TABLE=\"%s\"/>\n",
			       p->u_data.column.colname,
			       select->table_elements.tables[0].tabname);
		      return;
		    }
		}
	      cnt = 0;
	      for (a = 0; a < select->table_elements.ntables; a++)
		{
		  if (A4GL_has_column
		      (select->table_elements.tables[a].tabname,
		       p->u_data.column.colname))
		    {
		      cnt++;
		    }
		}

	      if (cnt == 1)
		{		// Column only existed in one table...
		  for (a = 0; a < select->table_elements.ntables; a++)
		    {
		      if (A4GL_has_column
			  (select->table_elements.tables[a].tabname,
			   p->u_data.column.colname))
			{
			  A4GL_add_xmlmap (get_currmapset(),
				   "<COLUMN NAME=\"%s\" TABLE=\"%s\"/>\n",
				   p->u_data.column.colname,
				   select->table_elements.tables[a].tabname);
			}
		    }
		}
	    }
	  A4GL_add_xmlmap (get_currmapset(), "<COLUMN NAME=\"%s\"/>\n",
		   p->u_data.column.colname);

	}
      return;



    case E_SLI_CASE:
      PRINTF ("WARNING : Mapping case in selects not handled yet");
      return;
      //return make_sql_string_and_free (A4GLSQLCV_make_case (select, &p->u_data.sqlcase), NULL);

    case E_SLI_CASE_ELEMENT:
      return;

    case E_SLI_SUBQUERY:
     	/* map_select_stmt ("SUBSELECT", p->u_data.subquery); */
      return;


    case E_SLI_SUBQUERY_EXPRESSION:
      	/* map_select_list_item (stmttype, select, p->u_data.sq_expression.sq); */
      return;


    }


  A4GL_assertion (1, "Unhandled element");
  return;
}




static void map_select_list_item_where (char *stmttype, struct s_select *select, struct s_select_list_item *p)
{
  map_select_list_item_i (stmttype, select, p);
}




static void
map_select_list_item (char *stmttype, struct s_select *select,
		      struct s_select_list_item *p)
{
  map_select_list_item_i (stmttype, select, p);
}


void
map_open_form (struct expr_str *s)
{
  if (crudfile == 0)
    return;
  if (s->expr_type == ET_EXPR_EXPR_LIST)
    {
      //s=s->u_data.expr_list->list[0];
    }

  if (s->expr_type == ET_EXPR_LITERAL_STRING)
    {
	A4GL_add_xmlmap( MAPSET_UI_OPENFORM, "<FORM FILENAME=\"%s\" LINENO=\"%d\"/>\n", s->u_data.expr_string, yylineno);
    }
  else
    {
	A4GL_add_xmlmap( MAPSET_UI_OPENFORM, "<FORM FILENAME=\"VARIABLE\"  LINENO=\"%d\"/>\n", yylineno);
    }
}


void
map_function_start (char *s)
{
  if (crudfile)
    {
      FPRINTF (crudfile, "   <FUNCTION NAME=\"%s\"  LINENO=\"%d\" TYPE=\"FUNCTION\">\n", s, yylineno);
	init_mapsets();
    }
}

void
map_function_end ()
{
  if (crudfile)
    {
	dump_mapsets();
      	FPRINTF (crudfile, "   </FUNCTION>\n");
	init_mapsets();
    }
}


void
map_call (struct expr_str *p)
{
  extern char *builtin_aclfgl_functions[];
  char libname[256];
  char libcat[256];
  int a;
char *s;

s=p->u_data.expr_function_call->fname;


  if (crudfile)
    {
	if (strcmp(s,"fgl_getenv")==0) {
			int printed=0;
			if (p->u_data.expr_function_call->parameters->nlist==1) {
				struct expr_str *pl;
				pl=p->u_data.expr_function_call->parameters->list[0];
				if (pl->expr_type==ET_EXPR_LITERAL_STRING) {
	  				A4GL_add_xmlmap (MAPSET_ENV, "<ENV VAR=\"%s\" LINENO=\"%d\"/>\n", pl->u_data.expr_string, yylineno);
					printed++;
				}
			} 

			if (!printed) {
	  			A4GL_add_xmlmap (MAPSET_ENV, "<ENV VAR=\"UNKNOWN\" LINENO=\"%d\"/>\n", s, yylineno);
			}
			return ;
	}


      for (a = 0; builtin_aclfgl_functions[a]; a++)
	{

	
	  if (strcmp (builtin_aclfgl_functions[a], s) == 0)
	    return;		// Ignore...
	}


      if (!isSpecial (s, libname,libcat))
	{
	  A4GL_add_xmlmap (MAPSET_CALL, "<CALL NAME=\"%s\" LINENO=\"%d\"/>\n", s, yylineno);
	}
      else
	{
		if (strlen(libcat)) {
			enum e_mapset ms;
			ms=MAPSET_LIBCALL;
			if (strcmp(libcat,"workflow")==0) {
				ms=MAPSET_LIBCALL_WORKFLOW;
			}
			if (strcmp(libcat,"awb")==0) {
				ms=MAPSET_LIBCALL_AWB;
			}
			if (strcmp(libcat,"correspondance")==0) {
				ms=MAPSET_LIBCALL_CORR;
			}
 			A4GL_add_xmlmap (ms, "<CALL NAME=\"%s\" LIBRARY=\"%s\" CATEGORY=\"%s\" LINENO=\"%d\"/>\n", s, libname, libcat,yylineno);
		} else {
	  		A4GL_add_xmlmap (MAPSET_LIBCALL, "<CALL NAME=\"%s\" LIBRARY=\"%s\"  LINENO=\"%d\"/>\n", s, libname, yylineno);
		}
	}
    }
}

void
map_start_report (char *s)
{
  if (crudfile)
    {
      A4GL_add_xmlmap (MAPSET_CALL, "<CALL NAME=\"%s\" LINENO=\"%d\"/>\n", s, yylineno);
    }
}


void
map_ui (char *s)
{
  if (crudfile)
    {
      A4GL_add_xmlmap (MAPSET_UI, "<UI TYPE=\"%s\"  LINENO=\"%d\" />\n", s, yylineno);
    }
}

void
map_ui_block (char *s)
{
  if (crudfile)
    {
      if (strcmp (s, "INPUT_ARRAY") == 0)
	{
	  A4GL_add_xmlmap (MAPSET_UI, "<UI TYPE=\"INPUT ARRAY\" LINENO=\"%d\" />\n", yylineno);
	}
      else
	{
	  A4GL_add_xmlmap (MAPSET_UI, "<UI TYPE=\"%s\"  LINENO=\"%d\" />\n", s,  yylineno);
	}
	
    }
}
void
map_ui_endblock (char *s)
{
  if (crudfile)
    {
      //FPRINTF (crudfile, "</%s>\n\n", s);
    }
}

static char *
decode_event (int n)
{
  switch (n)
    {
    case A4GL_EVENT_BEF_ROW:
      return "BEF_ROW";
    case A4GL_EVENT_AFT_ROW:
      return "AFT_ROW";
    case A4GL_EVENT_BEFORE_DELETE:
      return "BEFORE_DELETE";
    case A4GL_EVENT_AFTER_DELETE:
      return "AFTER_DELETE";
    case A4GL_EVENT_BEFORE_INSERT:
      return "BEFORE_INSERT";
    case A4GL_EVENT_AFTER_INSERT:
      return "AFTER_INSERT";
    case A4GL_EVENT_BEF_INSERT_DELETE:
      return "BEF_INSERT_DELETE";
    case A4GL_EVENT_AFT_INSERT_DELETE:
      return "AFT_INSERT_DELETE";
    case A4GL_EVENT_ON_IDLE:
      return "ON_IDLE";
    case A4GL_EVENT_ON_INTERVAL:
      return "ON_INTERVAL";
    case A4GL_EVENT_ON_TIME:
      return "ON_TIME";
    case A4GL_EVENT_KEY_PRESS:
      return "KEY_PRESS";
    case A4GL_EVENT_ON_ACTION:
      return "ON_ACTION";
//case A4GL_EVENT_AFTER_INP_CLEAN   : return "AFTER_INP_CLEAN"; 
    case A4GL_EVENT_AFTER_INP:
      return "AFTER_INPUT";
    case A4GL_EVENT_BEFORE_FIELD:
      return "BEFORE_FIELD";
    case A4GL_EVENT_AFTER_FIELD:
      return "AFTER_FIELD";
    case A4GL_EVENT_BEFORE_INP:
      return "BEFORE_INP";
    case A4GL_EVENT_BEFORE_FIELD_1:
      return "BEFORE_FIELD_1";
    case A4GL_EVENT_AFTER_FIELD_1:
      return "AFTER_FIELD_1";
    }

  return 0;

}




void
map_ui_event (int n, char *s)
{
  if (crudfile)
    {
      if (decode_event (n) != 0)
	{
	  A4GL_add_xmlmap (MAPSET_EVENTS, "<EVENT TYPE=\"%s\" LINENO=\"%d\" />\n", decode_event (n), yylineno);
	}
    }

}

void
map_ui_endevent (int n)
{
  if (crudfile)
    {
	/*
      if (decode_event (n) != 0)
	{
	  FPRINTF (crudfile, "</EVENT>\n");
	}
	*/
    }

}

void
map_report_start (char *s)
{
  if (crudfile)
    {
      FPRINTF(crudfile, "<FUNCTION NAME=\"%s\" LINENO=\"%d\" TYPE=\"REPORT\">\n", s,  yylineno);
	init_mapsets();
    }
}


void
map_report_end ()
{
  if (crudfile)
    {
	dump_mapsets();
      FPRINTF (crudfile, "</FUNCTION>\n");
	init_mapsets();
    }
}



void
map_display_at (struct expr_str *x, struct expr_str *y)
{
  char x_str[200];
  char y_str[200];

  if (!crudfile)
    return;

  sprintf (x_str, "VARIABLE(%s)", expr_name (x->expr_type));
  sprintf (y_str, "VARIABLE(%s)", expr_name (y->expr_type));

  printf ("%s, %s\n", x_str, y_str);
  if (x->expr_type == ET_EXPR_LITERAL_LONG)
    {
      sprintf (x_str, "%ld", x->u_data.expr_long);
    }
  if (y->expr_type == ET_EXPR_LITERAL_LONG)
    {
      sprintf (y_str, "%ld", y->u_data.expr_long);
    }

  A4GL_add_xmlmap (MAPSET_UI, "<UI TYPE=\"DISPLAY_AT\" X=\"%s\" Y=\"%s\" LINENO=\"%d\" />\n", x_str, y_str, yylineno);
}



void
map_run (struct expr_str *s)
{
  if (crudfile)
    {
      printf ("%d - %s \n", s->expr_type, expr_name (s->expr_type));

      if (s->expr_type == ET_EXPR_LITERAL_STRING)
	{
	  A4GL_add_xmlmap (MAPSET_RUN, "<RUN LINENO=\"%d\" TYPE=\"KNOWN\" >%s</RUN>\n", yylineno,s->u_data.expr_string);
	}

      if (s->expr_type == ET_EXPR_PUSH_VARIABLE)
	{
	  if (A4GL_has_pointer
	      (s->u_data.expr_push_variable->variable, LAST_STRING))
	    {
	      A4GL_add_xmlmap (MAPSET_RUN, "<RUN LINENO=\"%d\" TYPE=\"KNOWN\" >%s</RUN>\n", yylineno, (char *) A4GL_find_pointer (s->u_data.  expr_push_variable-> variable, LAST_STRING));
	    }
	  else
	    {
	      if (A4GL_has_pointer
		  (s->u_data.expr_push_variable->variable, LAST_STRING_START))
		{
		  A4GL_add_xmlmap (MAPSET_RUN, "<RUN LINENO=\"%d\" TYPE=\"KNOWN\" >%s</RUN>\n", yylineno,(char *) A4GL_find_pointer (s->u_data.  expr_push_variable-> variable, LAST_STRING_START));
		}
	      else
		{
		  A4GL_add_xmlmap (MAPSET_RUN, "<RUN LINENO=\"%d\" TYPE=\"UNKNOWN\" >%s</RUN>\n", yylineno, s->u_data.expr_push_variable->variable);
		}

	    }
	}

    }
}

void
map_select_stmt (char *main_statement_type, struct s_select *select)
{
  int a;

  if (!A4GL_isyes (acl_getenv ("MAPCRUD")))
    {
      return;
    }


  if (crudfile == 0)
    return;


  if (strcmp (main_statement_type, "SUBSELECT") != 0)
    {
	int printed=0;
	if (strcmp (main_statement_type, "SELECT")==0) { A4GL_add_xmlmap (MAPSET_CRUD_SELECT, "<SELECT_STMT LINENO=\"%d\" >\n",  yylineno); printed++;  
	add_currmapset(MAPSET_CRUD_SELECT);
		}
	if (strcmp (main_statement_type, "DELETE")==0) { A4GL_add_xmlmap (MAPSET_CRUD_DELETE, "<DELETE_STMT LINENO=\"%d\" >\n",  yylineno); printed++;  add_currmapset(MAPSET_CRUD_DELETE);}
	if (strcmp (main_statement_type, "INSERT")==0) { A4GL_add_xmlmap (MAPSET_CRUD_INSERT, "<INSERT_STMT LINENO=\"%d\" >\n",  yylineno); printed++;  add_currmapset(MAPSET_CRUD_INSERT);}
	if (strcmp (main_statement_type, "UPDATE")==0) { A4GL_add_xmlmap (MAPSET_CRUD_UPDATE, "<UPDATE_STMT LINENO=\"%d\" >\n",  yylineno); printed++;  add_currmapset(MAPSET_CRUD_UPDATE);}
	if (!printed) {
		A4GL_add_xmlmap (MAPSET_CRUD_OTHER, "<SQL STATEMENT=\"%s\" LINENO=\"%d\" >\n", main_statement_type,  yylineno); printed++; 
		add_currmapset(MAPSET_CRUD_OTHER);
	}
    }
  else
    {
      A4GL_add_xmlmap (get_currmapset(), "<SUBSELECT>\n", main_statement_type);
    }

      A4GL_add_xmlmap (get_currmapset(), "   <TABLES>\n");

  for (a = 0; a < select->table_elements.ntables; a++)
    {
      char *tabname;
      char *alias;
      tabname = strdup (select->table_elements.tables[a].tabname);
      alias = select->table_elements.tables[a].alias;
      if (alias == 0)
	{
	  alias = tabname;
	}
      else
	{
	  alias = strdup (alias);
	  A4GL_trim (alias);
	}
      A4GL_trim (tabname);
      A4GL_add_xmlmap (get_currmapset(), "      <TABLE NAME=\"%s\" ALIAS=\"%s\" />\n", tabname, alias);
    }

      A4GL_add_xmlmap (get_currmapset(), "   </TABLES>\n");


  map_select_list_item_list (main_statement_type, "VALUESLIST", select,
			     select->select_list);
  if (select->where_clause)
    {
	int sc;
      A4GL_add_xmlmap (get_currmapset(), "<FILTER>\n");
	sc=stmts_cnt;
	find_subqueries( main_statement_type,select, select->where_clause);
        map_select_list_item_where (main_statement_type, select, select->where_clause);
        A4GL_add_xmlmap (get_currmapset(), "</FILTER>\n",sc,stmts_cnt);
	if (stmts_cnt-sc) {
		print_subqueries(sc);
	}
	
    }






  if (strcmp (main_statement_type, "SUBSELECT") != 0)
    {
	int printed=0;
	if (strcmp (main_statement_type, "SELECT")==0) { 
      			A4GL_add_xmlmap (get_currmapset(), "</SELECT_STMT>\n\n");	printed++;
	}
	if (strcmp (main_statement_type, "DELETE")==0) { 
      			A4GL_add_xmlmap (get_currmapset(), "</DELETE_STMT>\n\n");	printed++;
	}
	if (strcmp (main_statement_type, "INSERT")==0) { 
      			A4GL_add_xmlmap (get_currmapset(), "</INSERT_STMT>\n\n");	
			printed++;
	}
	if (strcmp (main_statement_type, "UPDATE")==0) { 
      			A4GL_add_xmlmap (get_currmapset(), "</UPDATE_STMT>\n\n");	
			printed++;
	}
	if (!printed) {
      			A4GL_add_xmlmap (get_currmapset(), "</SQL>\n\n");
		}
	rm_currmapset();
	
    }

  else
    {
      A4GL_add_xmlmap (get_currmapset(), "</SUBSELECT>\n", main_statement_type);
    }
  if (select->next)
    {
      map_select_stmt ("SELECT", select->next);
}

}

void
map_delete_update (char *main_statement_type, char *table,
		   struct s_select_list_item *i)
{
  struct s_select *select;
int printed=0;
  //char *s;


  if (!A4GL_isyes (acl_getenv ("MAPCRUD")))
    {
      return;
    }

  select = new_empty_select ();
  select->select_list =
    new_select_list_item_list (new_select_list_item_literal ("1"));
  select->where_clause = i;
  select->first = A4GLSQLPARSE_new_tablename (table, 0);

  if (strcmp (main_statement_type, "DELETE")==0) { 
		A4GL_add_xmlmap (MAPSET_CRUD_DELETE, "<DELETE_STMT LINENO=\"%d\" >\n",   yylineno); 
		printed++;  
		add_currmapset(MAPSET_CRUD_DELETE);
  }

  if (strcmp (main_statement_type, "INSERT")==0) { 
		A4GL_add_xmlmap (MAPSET_CRUD_INSERT, "<INSERT_STMT LINENO=\"%d\" >\n",   yylineno); 
		printed++;  
		add_currmapset(MAPSET_CRUD_INSERT);
  }

  if (strcmp (main_statement_type, "UPDATE")==0) { 
		A4GL_add_xmlmap (MAPSET_CRUD_UPDATE, "<UPDATE_STMT LINENO=\"%d\" >\n",   yylineno); 
		printed++;  
		add_currmapset(MAPSET_CRUD_UPDATE);
  }
  if (!printed) {
		A4GL_add_xmlmap (MAPSET_CRUD_OTHER, "<SQL STATEMENT=\"%s\" LINENO=\"%d\" >\n",  main_statement_type, yylineno); 
		add_currmapset(MAPSET_CRUD_OTHER);
  }

  A4GL_add_xmlmap (get_currmapset(), "<TABLE NAME=\"%s\"/>\n", table);

  if (strcmp (main_statement_type, "UPDATE") == 0)
    {
      int a;
	if (A4GL_4glc_gen_cnt (UPDCOL)) {
	A4GL_add_xmlmap(get_currmapset(),"<COLUMNS>\n");

      for (a = 0; a < A4GL_4glc_gen_cnt (UPDCOL); a++)
	{
	  A4GL_add_xmlmap (get_currmapset(), "<COLUMN NAME=\"%s\" TABLE=\"%s\"/>\n",
		   A4GL_4glc_get_gen (UPDCOL, a), table);
	}
	A4GL_add_xmlmap(get_currmapset(),"</COLUMNS>\n");
	}
    }
  if (select->where_clause)
    {
	int sc;
	sc=stmts_cnt;
	find_subqueries( main_statement_type,select, select->where_clause);
      A4GL_add_xmlmap (get_currmapset(), "<FILTER>\n");
      map_select_list_item (main_statement_type, select, select->where_clause);
      A4GL_add_xmlmap (get_currmapset(), "</FILTER>\n");
	if (stmts_cnt-sc) {
		print_subqueries(sc);
	}
    }

  printed=0;
  if (strcmp (main_statement_type, "DELETE")==0) { 
  		A4GL_add_xmlmap (get_currmapset(), "</DELETE_STMT>\n");
		printed++;  
  }

  if (strcmp (main_statement_type, "INSERT")==0) { 
  		A4GL_add_xmlmap (get_currmapset(), "</INSERT_STMT>\n");
		printed++;  
  }

  if (strcmp (main_statement_type, "UPDATE")==0) { 
  		A4GL_add_xmlmap (get_currmapset(), "</UPDATE_STMT>\n");
		printed++;  
  }
  if (!printed) {
  		A4GL_add_xmlmap (get_currmapset(), "</SQL>\n");
  }
  rm_currmapset();

}

char *
module_name_without_dirstart (char *s)
{
  char *ptr;
  ptr = acl_getenv_not_set_as_0 ("DIRSTART");
  if (ptr == 0)
    return s;

  if (strncmp (s, ptr, strlen (ptr)) != 0)
    {
      return s;
    }
  s += strlen (ptr);
  return s;
}


struct special_Calls
{
  char *fcall;
  char lib[256];
  char cat[256];
};

struct special_Calls Specials[] = {
  {"act_fund_fundcalc", "lib_fundcalc","awb"},
  {"annuityamarta_annstart", "lib_annuity","awb"},
  {"dciamarta_f_sa_dci", "lib_dci","awb"},
  {"deathamarta_cl_dth_ini", "lib_dthclm","awb"},
  {"ded_risk2_cl_ded_risk2", "lib_ded_risk","awb"},
  {"depadmin_f_depadmin2", "lib_interest2","awb"},
  {"dtaaamarta_cl_f_sa_dta", "lib_dta","awb"},
  {"gfvamarta_t_guar_fund_val", "lib_gfv","awb"},
  {"incrpremsa_cl_incr_sa", "lib_incpremsa","awb"},
  {"intbonamarta_cl_int_bonus", "lib_ibr_bon","awb"},
  {"loyalty_cl_loyalty_bonus", "lib_lbr_bon","awb"},
  {"loybon2amarta_t_bonrev_calc", "lib_inv_bonres","awb"},
  {"matamarta_cl_mat_ini_calcs", "lib_mat","awb"},
  {"naramarta_t_next_anniv_res", "lib_nar","awb"},
  {"nbaltamarta_t_nb_alt", "lib_altcalc","awb"},
  {"new_business_cl_new_bus", "lib_nbquote2","awb"},
  {"pre_charge_cl_pre_charge", "lib_pre_charge","awb"},
  {"ptaamarta_t_recost_ta", "lib_pta","awb"},
  {"quotesamarta_t_ul_projections", "lib_quote3","awb"},
  {"quotesamarta_t_wp_projections", "lib_quote4","awb"},
  {"reassamarta_f_reass_riskprem", "lib_reass","awb"},
  {"surpup2amarta_t_svpup_calcs", "lib_svpup2","awb"},
  {"surpupamarta2_cl_svpup_calcs", "lib_svpup","awb"},
  {"transferamarta_cl_ret_ini_calcs", "lib_transfer","awb"},
  {"t_tax_efficien1_t_tax_efficiency", "lib_taxeff","awb"},
  {"unit_alloc_cl_unit_alloc", "lib_unit_alloc","awb"},
  {"wdrswtamarta_t_cgt_wdrw_swtch", "lib_wdr_swt","awb"},
  {"wolamarta_t_wol_review", "lib_wol","awb"},
  {"wpprojections_cl_wp_proj", "lib_quote2","awb"},
  {"cor_req_corresp_now", "-","correspondance"},
  {"init_wf_globals","-","workflow"},
  {"return_current_rule","-","workflow"},
  {"check_run_rule","-","workflow"},
  {"waiting_for_rules","-","workflow"},
  {"wfrulepickedat","-","workflow"},
  {"clear_rule","-","workflow"},
  {"check_proc_stat","-","workflow"},
  {"lifecy_begin_at","-","workflow"},
  {"start_lifecycle","-","workflow"},
  {"setup_cic","-","workflow"},
  {"setup_action","-","workflow"},
  {0, "",""}
};


int isSpecial (char *fname, char *lib,char *cat)
{
  int a;
  for (a = 0; Specials[a].fcall; a++)
    {
	strcpy(lib,"");
	strcpy(cat,"");
      if (strcmp (fname, Specials[a].fcall) == 0)
	{
	  strcpy (lib, Specials[a].lib);
	  strcpy (cat, Specials[a].cat);
	  return 1;
	}
    }
  return 0;
}

static int find_subqueries (char *stmttype, struct s_select *select, struct s_select_list_item *p) {
  switch (p->type)
    {
    case E_SLI_CHAR:
      A4GL_assertion (1, "Not used");
    case E_SLI_BUILTIN_CONST_COUNT_STAR:

    case E_SLI_IBIND:
    case E_SLI_VARIABLE:
    case E_SLI_DATETIME:
    case E_SLI_INTERVAL:
    case E_SLI_LITERAL:
    case E_SLI_BUILTIN_CONST_TRUE:
    case E_SLI_BUILTIN_CONST_FALSE:
    case E_SLI_QUERY_PLACEHOLDER:
    case E_SLI_VAR_REPLACE:
    case E_SLI_COLUMN_ORDERBY:	// Dont care about order bys..
    case E_SLI_IN_VALUES:
    case E_SLI_JOIN:
    case E_SLI_BUILTIN_CONST_USER:
    case E_SLI_BUILTIN_CONST_TODAY:
    case E_SLI_BUILTIN_CONST_STAR:
    case E_SLI_BUILTIN_CONST_CURRENT:
    case E_SLI_BUILTIN_FUNC_YEAR:
    case E_SLI_BUILTIN_FUNC_MONTH:
    case E_SLI_BUILTIN_FUNC_DAY:
    case E_SLI_BUILTIN_FUNC_DOW:
    case E_SLI_BUILTIN_FUNC_WEEKDAY:
    case E_SLI_BUILTIN_FUNC_MDY:
    case E_SLI_BUILTIN_FUNC_DATE:
    case E_SLI_BUILTIN_AGG_AVG:
    case E_SLI_BUILTIN_AGG_MAX:
    case E_SLI_BUILTIN_AGG_MIN:
    case E_SLI_FCALL:
    case E_SLI_EXTEND:
    case E_SLI_COLUMN:
    case E_SLI_BUILTIN_CONST_TIME:
    case E_SLI_BUILTIN_AGG_SUM:
    case E_SLI_BUILTIN_AGG_COUNT:

      return 0;
    case E_SLI_UNITS_YEAR: return 0 ;
    case E_SLI_UNITS_MONTH: return 0 ;
    case E_SLI_UNITS_DAY: return 0 ;
    case E_SLI_UNITS_HOUR: return 0 ;
    case E_SLI_UNITS_MINUTE: return 0 ;
    case E_SLI_UNITS_SECOND: return 0 ;

    case E_SLI_COLUMN_NOT_TRANSFORMED:
      return 0;

    case E_SLI_OP:
      find_subqueries (stmttype, select, p->u_data.complex_expr.left);
      find_subqueries (stmttype, select, p->u_data.complex_expr.right);
      return 0;

    case E_SLI_NOT_IN_VALUES:
      return 0;


    case E_SLI_IN_SELECT:
      find_subqueries (stmttype, select, p->u_data.complex_expr.left);
      find_subqueries (stmttype, select, p->u_data.complex_expr.right);
      return 0;

    case E_SLI_NOT_IN_SELECT:
      find_subqueries (stmttype, select, p->u_data.complex_expr.left);
      find_subqueries (stmttype, select, p->u_data.complex_expr.right);
      return 0;

    case E_SLI_REGEX_MATCHES:
      find_subqueries (stmttype, select, p->u_data.regex.val);
      find_subqueries (stmttype, select, p->u_data.regex.regex);
      return 0;

    case E_SLI_REGEX_NOT_MATCHES:
      find_subqueries (stmttype, select, p->u_data.regex.val);
      find_subqueries (stmttype, select, p->u_data.regex.regex);
      return 0;
    case E_SLI_REGEX_LIKE:
      find_subqueries (stmttype, select, p->u_data.regex.val);
      find_subqueries (stmttype, select, p->u_data.regex.regex);
      return 0;

    case E_SLI_REGEX_NOT_LIKE:
      find_subqueries (stmttype, select, p->u_data.regex.val);
      find_subqueries (stmttype, select, p->u_data.regex.regex);
      return 0;
    case E_SLI_REGEX_ILIKE:
      find_subqueries (stmttype, select, p->u_data.regex.val);
      find_subqueries (stmttype, select, p->u_data.regex.regex);
      return 0;
    case E_SLI_REGEX_NOT_ILIKE:
      find_subqueries (stmttype, select, p->u_data.regex.val);
      find_subqueries (stmttype, select, p->u_data.regex.regex);
      return 0;
    case E_SLI_ISNULL:
      find_subqueries (stmttype, select, p->u_data.simple_op_expr.expr);
      return 0;
    case E_SLI_ISNOTNULL:
      find_subqueries (stmttype, select, p->u_data.simple_op_expr.expr);
      return 0;
    case E_SLI_ASC:
      find_subqueries (stmttype, select, p->u_data.simple_op_expr.expr);
      return 0;
    case E_SLI_DESC:
      find_subqueries (stmttype, select, p->u_data.simple_op_expr.expr);
      return 0;
    case E_SLI_NOT:
      find_subqueries (stmttype, select, p->u_data.simple_op_expr.expr);
      return 0;

    case E_SLI_BRACKET_EXPR:
      find_subqueries (stmttype, select, p->u_data.simple_op_expr.expr);
      return 0;





    case E_SLI_BETWEEN:
      find_subqueries (stmttype, select, p->u_data.between_expr.val);
      find_subqueries (stmttype, select, p->u_data.between_expr.from);
      find_subqueries (stmttype, select, p->u_data.between_expr.to);
      return 0;

    case E_SLI_NOT_BETWEEN:
      find_subqueries (stmttype, select, p->u_data.between_expr.val);
      find_subqueries (stmttype, select, p->u_data.between_expr.from);
      find_subqueries (stmttype, select, p->u_data.between_expr.to);
      return 0;




    case E_SLI_CASE:
    case E_SLI_CASE_ELEMENT:
      return 0;

    case E_SLI_SUBQUERY:
	subq_stmts[stmts_cnt]=p->u_data.subquery;
	//subq_selects[stmts_cnt++]=select;

     	 //map_select_stmt ("SUBSELECT", p->u_data.subquery); */
      return 0;


    case E_SLI_SUBQUERY_EXPRESSION:
	//subq_stmts[stmts_cnt]= p->u_data.sq_expression.sq;
	//subq_selects[stmts_cnt++]=select;

      	find_subqueries (stmttype, select, p->u_data.sq_expression.sq); 
      return 0;


    }


  A4GL_assertion (1, "Unhandled element");
  return 0;
}

static int print_subqueries(int sc) {
int a;
	
	A4GL_add_xmlmap(get_currmapset(),"<SUBQUERIES>\n");
	for (a=sc;a<stmts_cnt;a++) {
     	 	map_select_stmt ("SUBSELECT", subq_stmts[a]);
	}
	A4GL_add_xmlmap(get_currmapset(),"</SUBQUERIES>\n");
	stmts_cnt=sc;
	return 1;
}
/* ================================ EOF ============================== */

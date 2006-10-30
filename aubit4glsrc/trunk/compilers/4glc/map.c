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
# $Id: map.c,v 1.45 2006-10-30 09:31:25 mikeaubury Exp $
#*/

/**
 * @file
 * Generation of map file.
 *
 * The map file is used to put in a file some mapping between the elements
 * in the 4gl source code and the line number module, etc.
 *
 * It is a file with pipe separated columns and \n separated records
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_4glc_int.h"
static void map_select_list_item (char *stmttype,struct s_select *select, struct s_select_list_item *p);
static void map_select_list_item_list (char *stmttype, char*listtype,struct s_select *select, struct s_select_list_item_list *i);

int A4GL_has_column (char *t, char *c);

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

static FILE *mapfile = 0;	/* The map file pointer opened file */
FILE *crudfile = 0;	/* The map file pointer opened file */
extern char curr_func[];
extern int yylineno;
extern char infilename[];
static char *module_name_without_dirstart(char *s) ;

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

/**
 * Open the map file.
 *
 * If the environment variable MAP4GL is assigned with Y open the file
 * Downt do nothing otherwise
 *
 * @param s The map file name
 */
void
openmap (char *s)
{
  char buff[256];
#ifdef DEBUG
  A4GL_debug ("openmap");
#endif

  if (strcmp (acl_getenv ("A4GL_MAP4GL"), "Y") == 0 && mapfile == 0)
    {
#ifdef DEBUG
      A4GL_debug ("Opening map file..%s \n", acl_getenv ("A4GL_MAP4GL"));
#endif
      if (A4GL_isyes (acl_getenv ("A4GL_LOCALOUTPUT")))
	{
	  char *str;
	  str = rindex (s, '/');
	  if (str)
	    s = str + 1;
	}
      SPRINTF1 (buff, "%s.map", s);
      mapfile = fopen (buff, "w");

      if (mapfile == 0)
	{
#ifdef DEBUG
	  A4GL_debug ("Unable to open map file");
#endif
	  FPRINTF (stderr, "Unable to open map file\n");
	  exit (1);
	}
#ifdef DEBUG
      A4GL_debug ("Mapfile=%p", mapfile);
#endif
    }

  if (strcmp (acl_getenv ("MAPCRUD"), "Y") == 0 && crudfile == 0)
    {
      if (A4GL_isyes (acl_getenv ("A4GL_LOCALOUTPUT")))
	{
	  char *str;
	  str = rindex (s, '/');
	  if (str)
	    s = str + 1;
	}
      SPRINTF1 (buff, "%s.map.xml", s);

      crudfile = fopen (buff, "w");

      if (crudfile == 0)
	{
#ifdef DEBUG
	  A4GL_debug ("Unable to open map file");
#endif
	  FPRINTF (stderr, "Unable to open CRUD map file\n");
	  exit (1);
	}
      FPRINTF(crudfile,"<MODULE name=\"%s\">\n",module_name_without_dirstart(infilename));
      FPRINTF(crudfile,"   <FUNCTIONS>\n",module_name_without_dirstart(infilename));


    }


}

/**
 * Add a new map to the opened file.
 *
 * Just adds if the mapfile was opened (controled by environment variable
 * A4GL_MAP4GL)
 *
 * @param t The x4gl element type
 * @param s The name of the element
 * @param w The scope where the element was declared
 *    - MAIN
 *    - MODULE
 *    - Function name
 * @param l The line number in the source code where the implementation was
 *          started.
 * @param m The x4gl module name
 */
void
addmap (char *t, char *s, char *w, int l, char *m)
{
  static char *last_w = 0;
  static int last_l = 0;
  static char *last_m = 0;

  if (m == 0)
    m = last_m;
  if (l == 0)
    l = last_l;
  if (w == 0)
    w = last_w;

  if (w == 0)
    w = "";
  if (m == 0)
    m = "";
  last_w = w;
  last_l = l;
  last_m = m;

#ifdef DEBUG
  A4GL_debug ("Adding to map: %p", mapfile);
#endif
  if (mapfile)
    FPRINTF (mapfile, "%s|%s|%s|%d|%s|\n", t, s, w, l, m);
}

/**
 * Close the map file
 */
void
closemap (void)
{
  if (mapfile)
    fclose (mapfile);
  if (crudfile)  {
         FPRINTF(crudfile,"   </FUNCTIONS>\n");
	  FPRINTF(crudfile,"</MODULE>\n");
	  fclose(crudfile);
  }
}

/**
 * Remove the quotes from a quoted string.
 * @todo move in common library
 * @param s The string to be unquoted
 */
void
rm_quotes (char *s)
{
  char *d;

  if (*s == 0)
    return;

  for (d = s; *s; *s++)
    {
      if (*s != '"')
	*d++ = *s;
    }
  *d = 0;
}

/**
 * Remove the quotes in the beginning and at the from a quoted string
 * @todo move in common library
 * @param s The string to be unquoted
 */
void
rm_quote (char *s)
{
  char *buff;
  int a;
  int b = 0;

  if (*s == 0)
    return;

  buff = calloc (strlen (s) + 1, 1);

  for (a = 0; a <= strlen (s); a++)
    {
      if (s[a] != '"')
	{
	  buff[b++] = s[a];
	}
    }
  for (a = strlen (buff) - 1; a >= 0; a--)
    {
      if (buff[a] == '/')
	break;			// Maybe its a . or .. directory...
      if (buff[a] == '.')
	{
	  buff[a] = 0;
	  break;
	}
    }
  strcpy (s, buff);

  free (buff);
}




#ifdef MOVED
//
// CRUD mapping...
//
//
//


static void map_select_list_item_list (char *stmttype, char*listtype,struct s_select *select, struct s_select_list_item_list *i)
{
  int a;
  if (i == 0)
    return;

  FPRINTF(crudfile,"<LIST type=\"%s\">\n",listtype);
  for (a = 0; a < i->nlist; a++)
    {
      map_select_list_item (stmttype,select, i->list[a]);
    }
  FPRINTF(crudfile,"</LIST>\n");
}



static void
map_select_list_item_i (char *stmttype, struct s_select *select, struct s_select_list_item *p)
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
      FPRINTF (crudfile,"<COLUMN name=\"%s\" />\n", p->u_data.expression);
      return;

    case E_SLI_OP:
      map_select_list_item (stmttype,select, p->u_data.complex_expr.left);
      map_select_list_item (stmttype,select, p->u_data.complex_expr.right);
      return;


    case E_SLI_JOIN:
      map_select_list_item (stmttype,select, p->u_data.complex_expr.left);
      map_select_list_item (stmttype,select, p->u_data.complex_expr.right);
      return;


    case E_SLI_IN_VALUES:
      map_select_list_item (stmttype,select, p->u_data.slil_expr.left);
      map_select_list_item_list (stmttype,"IN",select, p->u_data.slil_expr.right_list);
      return;
    case E_SLI_NOT_IN_VALUES:
      map_select_list_item (stmttype,select, p->u_data.slil_expr.left);
      map_select_list_item_list (stmttype,"NOTIN",select, p->u_data.slil_expr.right_list);
      return;


    case E_SLI_IN_SELECT:
      map_select_list_item (stmttype,select, p->u_data.complex_expr.left);
      map_select_list_item (stmttype,select, p->u_data.complex_expr.right);
      return;

    case E_SLI_NOT_IN_SELECT:
      map_select_list_item (stmttype,select, p->u_data.complex_expr.left);
      map_select_list_item (stmttype,select, p->u_data.complex_expr.right);
      return;

    case E_SLI_REGEX_MATCHES:
      map_select_list_item (stmttype,select, p->u_data.regex.val);
      map_select_list_item (stmttype,select, p->u_data.regex.regex);
      return;

    case E_SLI_REGEX_NOT_MATCHES:
      map_select_list_item (stmttype,select, p->u_data.regex.val);
      map_select_list_item (stmttype,select, p->u_data.regex.regex);
      return;
    case E_SLI_REGEX_LIKE:
      map_select_list_item (stmttype,select, p->u_data.regex.val);
      map_select_list_item (stmttype,select, p->u_data.regex.regex);
      return;

    case E_SLI_REGEX_NOT_LIKE:
      map_select_list_item (stmttype,select, p->u_data.regex.val);
      map_select_list_item (stmttype,select, p->u_data.regex.regex);
      return;
    case E_SLI_REGEX_ILIKE:
      map_select_list_item (stmttype,select, p->u_data.regex.val);
      map_select_list_item (stmttype,select, p->u_data.regex.regex);
      return;
    case E_SLI_REGEX_NOT_ILIKE:
      map_select_list_item (stmttype,select, p->u_data.regex.val);
      map_select_list_item (stmttype,select, p->u_data.regex.regex);
      return;
    case E_SLI_ISNULL:
      map_select_list_item (stmttype,select, p->u_data.simple_op_expr.expr);
      return;
    case E_SLI_ISNOTNULL:
      map_select_list_item (stmttype,select, p->u_data.simple_op_expr.expr);
      return;
    case E_SLI_ASC:
      map_select_list_item (stmttype,select, p->u_data.simple_op_expr.expr);
      return;
    case E_SLI_DESC:
      map_select_list_item (stmttype,select, p->u_data.simple_op_expr.expr);
      return;
    case E_SLI_NOT:
      map_select_list_item (stmttype,select, p->u_data.simple_op_expr.expr);
      return;

    case E_SLI_BRACKET_EXPR:
      map_select_list_item (stmttype,select, p->u_data.simple_op_expr.expr);
      return;
    case E_SLI_UNITS_YEAR:
      map_select_list_item (stmttype,select, p->u_data.simple_op_expr.expr);
      return;
    case E_SLI_UNITS_MONTH:
      map_select_list_item (stmttype,select, p->u_data.simple_op_expr.expr);
      return;
    case E_SLI_UNITS_DAY:
      map_select_list_item (stmttype,select, p->u_data.simple_op_expr.expr);
      return;
    case E_SLI_UNITS_HOUR:
      map_select_list_item (stmttype,select, p->u_data.simple_op_expr.expr);
      return;
    case E_SLI_UNITS_MINUTE:
      map_select_list_item (stmttype,select, p->u_data.simple_op_expr.expr);
      return;
    case E_SLI_UNITS_SECOND:
      map_select_list_item (stmttype,select, p->u_data.simple_op_expr.expr);
      return;



    case E_SLI_BUILTIN_CONST_USER:
      FPRINTF (crudfile,"<BUILTIN type=USER/>\n" );
      return;
    case E_SLI_BUILTIN_CONST_TODAY:
      FPRINTF (crudfile,"<BUILTIN type=TODAY/>\n");
      return;
    case E_SLI_BUILTIN_CONST_TIME:
      FPRINTF (crudfile,"<BUILTIN type=TIME/>\n");
      return;
    case E_SLI_BUILTIN_CONST_STAR:
      FPRINTF (crudfile,"<COLUMN name=\"*\"/>\n" );
      return;

    case E_SLI_BUILTIN_CONST_CURRENT:
      FPRINTF (crudfile,"<BUILTIN type=CURRENT/>\n");
      return;

    case E_SLI_BUILTIN_FUNC_YEAR:
      map_select_list_item_list (stmttype,"PARAMETERS",select, p->u_data.builtin_fcall.params);
      return;

    case E_SLI_BUILTIN_FUNC_MONTH:
      map_select_list_item_list (stmttype,"PARAMETERS",select, p->u_data.builtin_fcall.params);
      return;
    case E_SLI_BUILTIN_FUNC_DAY:
      map_select_list_item_list (stmttype,"PARAMETERS",select, p->u_data.builtin_fcall.params);
      return;
    case E_SLI_BUILTIN_FUNC_DOW:
      map_select_list_item_list (stmttype,"PARAMETERS",select, p->u_data.builtin_fcall.params);
      return;
    case E_SLI_BUILTIN_FUNC_WEEKDAY:
      map_select_list_item_list (stmttype,"PARAMETERS",select, p->u_data.builtin_fcall.params);
      return;
    case E_SLI_BUILTIN_FUNC_MDY:
      map_select_list_item_list (stmttype,"PARAMETERS",select, p->u_data.builtin_fcall.params);
      return;
    case E_SLI_BUILTIN_FUNC_DATE:
      map_select_list_item_list (stmttype,"PARAMETERS",select, p->u_data.builtin_fcall.params);
      return;

    case E_SLI_BUILTIN_AGG_AVG:
      map_select_list_item (stmttype,select, p->u_data.agg_expr.expr); return;

    case E_SLI_BUILTIN_AGG_MAX:
      map_select_list_item (stmttype,select, p->u_data.agg_expr.expr); return;

    case E_SLI_BUILTIN_AGG_MIN:
      map_select_list_item (stmttype,select, p->u_data.agg_expr.expr);
      return;

    case E_SLI_BUILTIN_AGG_SUM:
      map_select_list_item (stmttype,select, p->u_data.agg_expr.expr);
      return;

    case E_SLI_BUILTIN_AGG_COUNT:
      map_select_list_item (stmttype,select, p->u_data.agg_expr.expr);
      return;

    case E_SLI_BETWEEN:
      map_select_list_item (stmttype,select, p->u_data.between_expr.val);
      map_select_list_item (stmttype,select, p->u_data.between_expr.from);
      map_select_list_item (stmttype,select, p->u_data.between_expr.to);
      return;

    case E_SLI_NOT_BETWEEN:
      map_select_list_item (stmttype,select, p->u_data.between_expr.val);
      map_select_list_item (stmttype,select, p->u_data.between_expr.from);
      map_select_list_item (stmttype,select, p->u_data.between_expr.to);
      return;


    case E_SLI_FCALL:
      FPRINTF (crudfile,"<CALL %s/>", p->u_data.fcall.fname);
      map_select_list_item_list (stmttype,"PARAMETERS",select, p->u_data.fcall.params);
      return;



    case E_SLI_EXTEND:
      map_select_list_item (stmttype,select, p->u_data.extend.expr);
      return;


    case E_SLI_COLUMN:
	if (p->u_data.column.colname==0) return;
      if (p->u_data.column.tabname && strlen (p->u_data.column.tabname))
	{
	  FPRINTF (crudfile,"<COLUMN NAME=\"%s\" TABLE=\"%s\" REALTABLE=\"%s\" />\n", p->u_data.column.colname, p->u_data.column.tabname,find_tabname_for_alias(select,p->u_data.column.tabname));
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
		      FPRINTF (crudfile,"<COLUMN name=\"%s\" table=\"%s\"/>\n",
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
	    {			// Column only existed in one table...
	      for (a = 0; a < select->table_elements.ntables; a++)
		{
		  if (A4GL_has_column
		      (select->table_elements.tables[a].tabname,
		       p->u_data.column.colname))
		    {
		      FPRINTF (crudfile,"<COLUMN name=\"%s\" table=\"%s\"/>\n",
			      p->u_data.column.colname,
			      select->table_elements.tables[a].tabname);
		    }
		}
	    }
	    }
	  FPRINTF (crudfile,"<COLUMN name=\"%s\"/>\n", p->u_data.column.colname);

	}
	return;



    case E_SLI_CASE:
      PRINTF ("WARNING : Mapping case in selects not handled yet");
      return;
      //return make_sql_string_and_free (A4GLSQLCV_make_case (select, &p->u_data.sqlcase), NULL);

    case E_SLI_CASE_ELEMENT:
      return;

    case E_SLI_SUBQUERY:
      map_select_stmt ("SUBSELECT", p->u_data.subquery);
      return;


    case E_SLI_SUBQUERY_EXPRESSION:
      map_select_list_item (stmttype,select, p->u_data.sq_expression.sq);
      return;


    }


  A4GL_assertion (1, "Unhandled element");
  return;
}








static void map_select_list_item (char *stmttype,struct s_select *select, struct s_select_list_item *p)
{

  map_select_list_item_i (stmttype,select, p);
}


void map_open_form(struct expr_str *s) {
	if (crudfile==0) return;
	if (s->expr_type==ET_EXPR_EXPR_LIST) {
		printf("LIST : %d\n",s->u_data.expr_list->nlist);
		//s=s->u_data.expr_list->list[0];
	}

	if (s->expr_type==ET_EXPR_LITERAL_STRING) {
  		FPRINTF (crudfile,"<FORM FILENAME=\"%s\" MODULE=\"%s\" LINENO=\"%d\"/>\n",s->u_data.expr_string,module_name_without_dirstart(infilename),yylineno);
	} else {
		printf(" OPEN FORM : %s (%d)\n",expr_name(s->expr_type),yylineno);
		
  		FPRINTF (crudfile,"<FORM FILENAME=VARIABLE MODULE=\"%s\" LINENO=\"%d\"/>\n",s->u_data.expr_string,module_name_without_dirstart(infilename),yylineno);
	}
}


void map_function_start(char *s) {
if (crudfile ) { 
  	FPRINTF (crudfile,"<FUNCTION NAME=\"%s\" MODULE=\"%s\" LINENO=\"%d\">\n",s,module_name_without_dirstart(infilename),yylineno);
}
}

void map_function_end() {
if (crudfile ) { 
  	FPRINTF (crudfile,"</FUNCTION>\n");
}
}


void map_call(char *s) {
extern char *builtin_aclfgl_functions[];
int a;
if (crudfile ) { 
	for (a=0;builtin_aclfgl_functions[a];a++) {
		if (strcmp(builtin_aclfgl_functions[a],s)==0) return; // Ignore...
	}
  		FPRINTF (crudfile,"<CALL NAME=\"%s\" MODULE=\"%s\" LINENO=\"%d\"/>\n",s,module_name_without_dirstart(infilename),yylineno);
	}
}

void map_start_report(char *s) {
	if (crudfile ) { 
  		FPRINTF (crudfile,"<CALL NAME=\"%s\" MODULE=\"%s\" LINENO=\"%d\"/>\n",s,module_name_without_dirstart(infilename),yylineno);
	}
}

void map_report_start(char *s) {
if (crudfile ) { 
  	FPRINTF (crudfile,"<REPORT NAME=\"%s\" MODULE=\"%s\" LINENO=\"%d\">\n",s,module_name_without_dirstart(infilename),yylineno);
}
}


void map_report_end() {
if (crudfile ) { 
  	FPRINTF (crudfile,"</REPORT>\n");
}
}




void map_run(struct expr_str *s) {
if (crudfile ) { 
	printf("%d - %s \n",s->expr_type,expr_name(s->expr_type));
	if (s->expr_type==ET_EXPR_LITERAL_STRING) {
  		FPRINTF (crudfile,"<RUN MODULE=\"%s\" LINENO=\"%d\">",module_name_without_dirstart(infilename),yylineno);
		FPRINTF (crudfile,"%s",s->u_data.expr_string);
  		FPRINTF (crudfile,"</RUN>");
	}

	if (s->expr_type==ET_EXPR_PUSH_VARIABLE) {
		if (A4GL_has_pointer(s->u_data.expr_push_variable->variable,LAST_STRING)) {
  			FPRINTF (crudfile,"<RUN MODULE=\"%s\" LINENO=\"%d\">",module_name_without_dirstart(infilename),yylineno);
			FPRINTF (crudfile,"%s",A4GL_find_pointer(s->u_data.expr_push_variable->variable,LAST_STRING));
  			FPRINTF (crudfile,"</RUN>");
		} else {
			if (A4GL_has_pointer(s->u_data.expr_push_variable->variable,LAST_STRING_START)) {
  			FPRINTF (crudfile,"<RUN MODULE=\"%s\" LINENO=\"%d\">",module_name_without_dirstart(infilename),yylineno);
			FPRINTF (crudfile,"%s",A4GL_find_pointer(s->u_data.expr_push_variable->variable,LAST_STRING_START));
  			FPRINTF (crudfile,"</RUN>");
			} else {
  			FPRINTF (crudfile,"<RUN MODULE=\"%s\" LINENO=\"%d\">",module_name_without_dirstart(infilename),yylineno);
			FPRINTF (crudfile,"%s",s->u_data.expr_push_variable->variable);
  			FPRINTF (crudfile,"</RUN>");
			}

		}
	}

}
}

void
map_select_stmt (char *main_statement_type, struct s_select *select)
{
  int a;

  if (!A4GL_isyes(acl_getenv("MAPCRUD"))) {
	  	return ;
  }

  if (strcmp (main_statement_type, "SUBSELECT") != 0)
    {
  	FPRINTF (crudfile,"<CRUD STATEMENT=\"%s\" FUNCTION=\"%s\" LINENO=\"%d\" MODULE=\"%s\">\n",main_statement_type,curr_func,yylineno,module_name_without_dirstart(infilename));
    } else {
  	FPRINTF (crudfile,"<%s>\n", main_statement_type);
    }
  for (a = 0; a < select->table_elements.ntables; a++)
    {
      char *tabname;
      char *alias;
      tabname = strdup(select->table_elements.tables[a].tabname);
      alias = select->table_elements.tables[a].alias;
      if (alias == 0) {alias = tabname;
	      	}
      else {
	      	alias=strdup(alias);
      		A4GL_trim(alias);
      }
      A4GL_trim(tabname);
      FPRINTF (crudfile,"<TABLE NAME=\"%s\" ALIAS=\"%s\" />\n", tabname, alias);
    }



  map_select_list_item_list (main_statement_type, "VALUESLIST", select, select->select_list);
  if (select->where_clause) {
	  FPRINTF(crudfile,"<FILTER>\n");
  		map_select_list_item (main_statement_type, select, select->where_clause);
	  FPRINTF(crudfile,"</FILTER>\n");
  }
  map_select_list_item_list (main_statement_type, "GROUPBY", select, select->group_by);
  if (select->having) {
	  FPRINTF(crudfile,"<HAVING>\n");
  		map_select_list_item (main_statement_type,  select, select->having);
	  FPRINTF(crudfile,"</HAVING>\n");
  }

  if (select->sf){ 
  	map_select_list_item_list (main_statement_type, "ORDERBY", select, select->sf->order_by);
  }

  if (select->next)
    {
      map_select_stmt ("SUBSELECT", select->next);
    }



  if (strcmp (main_statement_type, "SUBSELECT") != 0)
    {
      FPRINTF (crudfile,"</CRUD>\n\n");
    } else {
  FPRINTF (crudfile,"</%s>\n", main_statement_type);
    }
}

void
map_delete_update (char *main_statement_type, char *table, struct s_select_list_item *i)
{
  struct s_select *select;
  //char *s;


  if (!A4GL_isyes(acl_getenv("MAPCRUD"))) {
	  	return ;
  }

  select = new_empty_select ();
  select->select_list = new_select_list_item_list (new_select_list_item_literal ("1"));
  select->where_clause = i;
  select->first = A4GLSQLPARSE_new_tablename (table, 0);

  FPRINTF (crudfile,"<CRUD STATEMENT=\"%s\" FUNCTION=\"%s\" LINENO=\"%d\" MODULE=\"%s\">\n",main_statement_type,curr_func,yylineno,module_name_without_dirstart(infilename));
  FPRINTF(crudfile,"<TABLE name=\"%s\"/>\n",table);
  if (strcmp(main_statement_type,"UPDATE")==0) {
	  int a;
	   for (a = 0; a < A4GL_4glc_gen_cnt (UPDCOL); a++)
	        {
			   FPRINTF(crudfile,"<COLUMN NAME=\"%s\" TABLE=\"%s\"/>\n",A4GL_4glc_get_gen (UPDCOL, a),table);
		}

  }
  if (select->where_clause) {
	  FPRINTF(crudfile,"<FILTER>\n");
  		map_select_list_item (main_statement_type, select, select->where_clause);
	  FPRINTF(crudfile,"</FILTER>\n");
  }

  FPRINTF (crudfile,"</CRUD>\n");

}

static char *module_name_without_dirstart(char *s) {
char *ptr;
ptr=acl_getenv_not_set_as_0("DIRSTART");
if (ptr==0) return s;

if (strncmp(s,ptr,strlen(ptr))!=0) {
	return s;
}
s+=strlen(ptr);
return s;
}

#endif
/* ================================ EOF ============================== */

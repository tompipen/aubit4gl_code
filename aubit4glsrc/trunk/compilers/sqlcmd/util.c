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
# | contact licensing@aubit.com                                           |
# +----------------------------------------------------------------------+
#
# $Id: util.c,v 1.1 2011-01-07 11:43:21 mikeaubury Exp $
#
*/

/**
 * @file
 * This file is #include'd into y.tab.c so we can make a lot of these functions static
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_API_sqlparse_lib.h"
#include "a4gl_libaubit4gl.h"
#include "sql_compiler_util.h"


//#ifdef SIMPLIFIED
//#include "../4glc/lib4glc/fix_insert.c"
//#else
//#include "../4glc/fix_insert.c"
//#endif
//#include "sqlcompiler.h"



// the maintaners of flex (in their infinite wisdom fixed flex 
// so that the following are properly prefixed in later versions
#ifndef yy_delete_buffer
#define DELETE_BUFFER sqlparse_yy_delete_buffer
#define THEYYWRAP sqlparse_yywrap
#define YYSCANSTRING sqlparse_yy_scan_string
#else
#include "alias.h"
#define DELETE_BUFFER yy_delete_buffer
#define THEYYWRAP yywrap
#define YYSCANSTRING yy_scan_string
#endif
static void trim_spaces (char *s);

/*
=====================================================================
		                    Variables
=====================================================================
*/


struct command *lastCmd=0;
void *nbs = 0;


void set_Cmd(struct command *c) {
	lastCmd=c;
}

//extern char *Sql;
//

static void
A4GLSQLCV_setbuffer (char *s)
{
  if (nbs) {
    DELETE_BUFFER (nbs);
        nbs=0;
  }
  if (Sql)
    acl_free (Sql);
  Sql = acl_strdup (s);
  A4GL_trim (Sql);
  nbs = YYSCANSTRING (Sql);
/*
  if (stmts)
    {
        int a;
        for (a=0;a<stmts_cnt;a++) {
                acl_free(stmts[a].val);
        }
      acl_free (stmts);
      stmts = 0;
      stmts_cnt = 0;
    }
*/
  //input_from_file = 0;
  //Sql_file = 0;
}

struct command *A4GLPARSECMD_processSQL (char *sql)
{
  lastCmd=0;
  A4GLSQLCV_setbuffer (sql);
  sqlparse_yyparse ();
  return lastCmd;
}


int
sqlparse_yyerror (char *s)
{
return 0;
}


int sqlparse_yywrap() {
return 1;
}


void
A4GL_warn (char *s)
{
  // Does nothing
}
  
str_list *generate_update_column_list_for(char *tabname,struct s_select_list_item_list *value_list) {
char colname[2000];
  int isize = 0;
  int idtype = 0;
  char *ccol;
struct str_list *l;
int rval;
l=NULL;

      strcpy (colname, "");
      rval = A4GLSQL_get_columns (tabname, colname, &idtype, &isize);
      if (rval == 0)
        {
        //set_yytext(tabname);
          a4gl_yyerror ("Table is not in the database)");
          A4GLSQL_end_get_columns ();
          return NULL;
        }

        l=new_str_list(0);

      while (1)
        {
          colname[0] = 0;
          rval = A4GLSQL_next_column (&ccol, &idtype, &isize);
          strcpy (colname, ccol);
          if (rval == 0)
            break;
          trim_spaces (colname);
          add_str_list(l, colname);
          //A4GL_4glc_push_gen (UPDCOL, colname);
        }
      A4GLSQL_end_get_columns ();

        return l;
}


void
A4GL_add_feature (char *feature)
{
  /* Reserved for future use */
}
struct s_select_list_item_list *local_add_select_list_item_list( struct s_select_list_item_list *p, struct s_select_list_item *i)
{
struct s_select_list_item_list * prval;
 //A4GL_pause_execution();



 prval=add_select_list_item_list(p,i);

  return prval;
}

/*
 * these indirect to the ones in lib/libaubit4gl so that we can do some expansions of variables first
 * and some checks/debugs/breakpoints etc
 * */
struct s_select_list_item_list * local_new_select_list_item_list(  struct s_select_list_item *i) {
 //struct s_select_list_item_list * prval;
 //struct variable_usage *u;
        return new_select_list_item_list(i);
}


struct s_select_list_item_list *expand_slil(struct s_select_list_item_list *l) {

 l=rationalize_select_list_item_list(l);
 return l;
}


/**
 *  *  * Trim the spaces at the right part of a string.
 *   *   *
 *    *    * @param s The string to be trimmed
 *     *     */
static void trim_spaces (char *s)
{
          int l;
            for (l = strlen (s) - 1; l >= 0; l--)
                        {
                                      if (s[l] == ' ')
                                                      s[l] = 0;
                                            else
                                                            break;
                                                }
}



void map_select_stmt (char *main_statement_type, struct s_select *select) {
}

void map_delete_update (char *main_statement_type, char *table, struct s_select_list_item *i)
{
}



void fail_on_select_ibind(void) {
}

void map_create_temp(char *tab, char *src) {
}

int set_ignore_indicators(void) {
        return 0;
        // required ...
        }
        //
         int clr_ignore_indicators(void) {
                 return 0;
                         // required ...
                         }



int
A4GL_cursor_current (expr_str *s)
{
  return 0;
}



static void
ansi_violation (char *s, int n)
{
}


void
add_sql_function (char *s)
{

}

static void addmap_runtime (char *s, char *f)
{

}


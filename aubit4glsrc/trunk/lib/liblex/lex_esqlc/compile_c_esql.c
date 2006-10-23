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
# $Id: compile_c_esql.c,v 1.156 2006-10-23 08:49:17 mikeaubury Exp $
# @TODO - Remove rep_cond & rep_cond_expr from everywhere and replace
# with struct expr_str equivalent
*/


#ifndef lint
static char const module_id[] =
  "$Id: compile_c_esql.c,v 1.156 2006-10-23 08:49:17 mikeaubury Exp $";
#endif
extern int yylineno;


/**
 * @file
 * Generate .C & .H modules for compiling with Informix or PostgreSQL 
 * ESQL/C pre-compilers.
 *
 * Most of the functions implemented here are called by the parser.
 *
 * The goal is to generate a ESQL/C program that implement the functionality of
 * the 4gl being compiled.
 */

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

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_lib_lex_esqlc_int.h"
char *A4GL_dtype_sz (int d, int s);
void make_sql_bind (char *sql, char *type);
extern int fbindcnt;
/*
=====================================================================
                    Variables definitions
=====================================================================
*/


//extern int obindcnt;
//extern int ibindcnt;



//struct binding_comp *ensure_bind(long *a_bindp,long need, struct binding_comp *b) ;

//void set_suppress_lines(void);
//void clr_suppress_lines(void);

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

void printcomment (char *fmt, ...);
//enum e_dialect                esql_type               (void);
extern void printh (char *fmt, ...);
void printc (char *fmt, ...);
static void print_copy_status (void);
void print_conversions_g (t_binding_comp_list *bind);
void print_report_table (char *repname, char type, int c,char *asc_desc,t_binding_comp_list *funclist, t_binding_comp_list *orderbind);


char *A4GL_mk_temp_tab (struct BINDING *b, int n);
/*
=====================================================================
                    Functions definitions
=====================================================================
*/


static void A4GL_save_sql (char *s, char *s2);
extern char buff_in[];




static void
A4GL_save_sql (char *s, char *s2)
{
  static int sqlcnt = 0;
  char *buff;
  int a;
  if (A4GL_isyes (acl_getenv ("A4GL_EC_LOGSQL")))
    {
      if (s2 == 0)
	{
	  buff = strdup (s);
	}
      else
	{
	  buff = acl_malloc2 (strlen (s) + strlen (s2));
	  sprintf (buff, s, s2);
	}
      printh ("char _sql_stmt_%d[]={\n", sqlcnt);
      for (a = 0; a < strlen (buff); a++)
	{
	  if (a4gl_isalpha (buff[a]) || isdigit (buff[a]))
	    {
	      printh ("'%c',", buff[a]);
	    }
	  else
	    {
	      printh ("%3d,", buff[a]);
	    }
	  if ((a % 20) == 19)
	    printh ("\n");
	}
      printh ("0};\n");
      printc ("A4GL_logsql(%d,_module_name,_sql_stmt_%d);", yylineno,
	      sqlcnt++);
      free (buff);
    }
}

/**
 * Print the C implementation of the execution of the SQL statement allready
 * readed.
 *
 * @param The string with the sql statement to be executed.
 */
void
LEXLIB_print_exec_sql (char *s, int converted)
{
  A4GL_debug ("In print_exec_sql");
  A4GL_save_sql (s, 0);
  A4GL_debug ("saved");

  if (strlen (s))
    {
      A4GL_debug ("Here");
      printc ("\nEXEC SQL %s; /* exec_sql */\n", s);
    }
  if (A4GLSQLCV_check_requirement ("TEMP_AS_DECLARE_GLOBAL"))
    {
      if (strstr (s, "DECLARE GLOBAL TEMPORARY TABLE"))
	{
	  char tabname[64];
	  char *ptr;
	  strncpy (tabname, &s[39], 64);
	  ptr = strchr (tabname, ' ');
	  if (ptr)
	    *ptr = 0;
	  printc ("A4GLSQLCV_add_temp_table(\"%s\");", tabname);
	}
    }
  A4GL_debug ("Done");
  print_copy_status ();
}


/**
 * @todo Desribe
 *
 *
 * @param
 */
void
LEXLIB_print_exec_sql_bound_g (char *s, int converted,t_binding_comp_list *bind)
{
  int c;
  printc ("{/* Start exec_sql_bound */\n");
  set_suppress_lines ();
  c = LEXLIB_print_bind_definition_g (bind);
  printc ("/* printed bind - print conversions */");
  LEXLIB_print_bind_set_value_g (bind);
  print_conversions_g (bind);
  A4GL_save_sql (s, 0);
  printc ("\nEXEC SQL %s; /* exec_sql_bound */\n", s);
  print_copy_status ();
  printc ("}\n");
  clr_suppress_lines ();
}

/**
 * @todo Desribe
 *
 *
 * @param
 */
void
LEXLIB_print_close (char type, char *name)
{
  printc ("/* CLOSE */");
  switch (type)
    {
    case 'F':
      printc ("A4GL_close_form(%s);\n", name);
      break;
    case 'W':
      printc ("A4GL_remove_window(%s);\n", name);
      break;
    case 'D':
      if (A4GLSQLCV_check_requirement ("USE_DATABASE_STMT")
	  || esql_type () == E_DIALECT_INFOFLEX)
	{
	  A4GL_save_sql ("CLOSE DATABASE", 0);
	  printc ("\nEXEC SQL CLOSE DATABASE;\n");
	}
      else
	{
	  A4GL_save_sql ("DISCONNECT 'default'", 0);
	  printc ("\nEXEC SQL DISCONNECT 'default';\n");
	}
      printc ("if (sqlca.sqlcode==0) A4GL_esql_db_open(0,0,0,\"\");");
      print_copy_status ();
      break;

    case 'S':
      A4GL_save_sql ("DISCONNECT %s", A4GL_strip_quotes (name));
      printc ("\nEXEC SQL DISCONNECT %s;\n", A4GL_strip_quotes (name));
      print_copy_status ();
      break;

    case 'C':
      A4GL_save_sql ("CLOSE  %s", A4GL_strip_quotes (name));
      printc ("\nEXEC SQL CLOSE %s;\n", A4GL_strip_quotes (name));
      if (A4GLSQLCV_check_requirement ("IGNORE_CLOSE_ERROR"))
	{
	  printc ("sqlca.sqlcode=0;");
	}
      print_copy_status ();
      break;
    }
  printc ("/* END OF CLOSE */");
}

/**
 * Print the second part of the C implementation of FOREACH 4gl statement.
 *
 * Called when the parser found the into part of statement.
 *
 * @param cursorname The name of 4gl cursor name.
 * @param into The variable list where the cursor is fetched in.
 */
void
LEXLIB_print_foreach_next_g (char *xcursorname, t_binding_comp_list *using_bind, t_binding_comp_list *into_bind)
{
  int ni;
  int no;
  static char *cursorname = 0;
  if (cursorname)
    free (cursorname);
  cursorname = strdup (A4GL_strip_quotes (xcursorname));

  printc ("a4gl_sqlca.sqlcode=0;\n");


  LEXLIB_print_open_cursor_g (cursorname, using_bind);


  /* printc ("if (a4gl_sqlca.sqlcode==0) {\n");*/
  printc ("if (a4gl_sqlca.sqlcode!=0) {");
exit_loop("FOREACH"); 
  printc("}");

  printc("_cursoropen=1;");
  printc ("while (1) {\n");
  ni = LEXLIB_print_bind_definition_g (using_bind);
  no = LEXLIB_print_bind_definition_g (into_bind);
  LEXLIB_print_bind_set_value_g (using_bind);
  LEXLIB_print_bind_set_value_g (into_bind);
  print_conversions_g (using_bind);
  set_suppress_lines ();
  A4GL_save_sql ("FETCH %s", A4GL_strip_quotes (cursorname));


  if (no == 0 && A4GLSQLCV_check_requirement ("NO_FETCH_WITHOUT_INTO"))
    { a4gl_yyerror ("You cannot use a FETCH without an INTO with the target database"); return;
    }
  printc ("\nEXEC SQL FETCH %s %s; /*foreach ni=%d no=%d*/\n", cursorname, A4GL_get_into_part (0, no), ni, no);
  print_copy_status ();
  printc ("internal_recopy_%s_o_Dir();", cursorname);
  print_conversions_g (into_bind);
  clr_suppress_lines ();

  printc ("if (a4gl_sqlca.sqlcode<0||a4gl_sqlca.sqlcode==100) break;\n");
}

/**
 * Print the C implementation of the FREE CURSOR 4gl statement.
 *
 *
 * @param c The cursor name.
 */
void
LEXLIB_print_free_cursor (char *s)
{
  static char *cname = 0;
  if (cname)
    free (cname);
  cname = strdup (A4GL_strip_quotes (s));
  A4GL_save_sql ("FREE %s", s);
  printc ("\nEXEC SQL FREE %s;\n", cname);
  print_copy_status ();
}


/**
 * The parser found the LOCATE 4gl statement for the BLOB variables.
 *
 * Generate the C implementation code in the output file.
 *
 * @param where The place where the variable should be located:
 *   - M : In the memory.
 *   - F : In a file.
 * @param var The variable name to be located somewhere.
 * @param fname The file name where it should be located (if type=F).
 */
void
LEXLIB_print_locate (char where, char *var, char *fname)
{
  printc ("A4GL_locate_var(&%s,'%c',%s);  /* FIXME */\n", var, where, fname);
}


/* *************************** REPORT **********************/

/**
 * @todo Desribe
 *
 *
 * @param
 */
void
LEXLIB_print_set_conn (char *conn)
{
  A4GL_save_sql ("SET CONNECTION %s", conn);
        if (esql_type () == E_DIALECT_POSTGRES) {   // Postgres...
  			printc ("\nEXEC SQL SET CONNECTION %s;\n", A4GL_strip_quotes (conn));
		} else {
  			printc ("\nEXEC SQL SET CONNECTION %s;\n", conn);
		}

  printc("if (sqlca.sqlcode>=0) {A4GL_set_esql_connection(%s);}",conn);
  print_copy_status ();
}

/**
 * Generate the C implementation for the PUT statement for using with 
 * insert cursors.
 */
void
LEXLIB_print_put_g (char *xcname, char *putvals,t_binding_comp_list *bind)
{
  int n;
  int a;
  static char *cname = 0;
  if (cname)
    free (cname);
  cname = strdup (A4GL_strip_quotes (xcname));

  if (!A4GL_find_pointer(cname,CURCODE)) {
		set_yytext(cname);
		a4gl_yyerror("Cursor has not been previously defined");
		return ;
  }

  if (A4GLSQLCV_check_requirement ("NO_PUT"))
    {
      if (A4GL_isyes (acl_getenv ("A4GL_INCOMPAT_AT_RUNTIME")))
	{
	  printc ("/* FAKE PUT - WILL STOP AT RUN-TIME */");
	  printc
	    ("printf (\"You cannot use a PUT with the target database\\n\"); ");
	  printc ("A4GL_push_long(3);");
	  print_exit_program (A4GL_new_literal_long_long (1));
	}
      else
	{
	  a4gl_yyerror ("You cannot use a PUT with the target database");
	}
      return;
    }


  if (A4GLSQLCV_check_requirement ("EMULATE_INSERT_CURSOR"))
    {
      char c;
      char *ptr;
      c = A4GL_cursor_type (xcname);

      if (c != 'I')
	{
	  a4gl_yyerror
	    ("Got confused - I didn't think that was an insert cursor\\n Use 'PRAGMA EMULATE INSERT CURSOR FOR CursorName' to hint the compiler");
	  return;
	}
      ptr = A4GL_get_insert_prep (xcname);

      printc ("/* FAKE PUT - USING EXECUTE */");

      if (bind->nbind == 0)
	{
	  // PUT statment without FROM clause
	  if (A4GL_isyes (acl_getenv ("A4GL_INCOMPAT_AT_RUNTIME")))
	    {
	      printc ("/* FAKE PUT without FROM - WILL STOP AT RUN-TIME */");
	      printc
		("printf (\"You cannot use a PUT without FROM with the target database\\n\"); ");
	      printc ("A4GL_push_long(3);");
	      print_exit_program (A4GL_new_literal_long_long (1));
	    }
	  else
	    {
	      a4gl_yyerror
		("Doing this isn't implemented yet (PUT without FROM)");
	      return;
	    }
	}
      else
	{
	  // We should be ok...
	  LEXLIB_print_execute_g (ptr, 1,bind,empty_genbind('o'));
	}
      printc ("/* END OF FAKE PUT - USING EXECUTE */");
      return;
    }

  printc ("{ /*ins1 */\n");
  n = LEXLIB_print_bind_definition_g (bind);
  LEXLIB_print_bind_set_value_g (bind);
  print_conversions_g (bind);
  printc ("internal_recopy_%s_i_Dir();", cname);
  A4GL_save_sql ("PUT %s", cname);


  set_suppress_lines ();


  printc ("\nEXEC SQL PUT %s /* '%s' */\n", cname, putvals);

  if (A4GLSQLCV_check_requirement ("USE_BINDING_FOR_PUT") == 0)
    {

      if (strlen (putvals))
	{
	  printc ("FROM %s", putvals);
	}
    }
  else
    {

      if (n)
	{
	  printc ("FROM ");
	  for (a = 0; a < n; a++)
	    {
	      if (a)
		printc (",");
	      printc ("   :_vi_%d", a);
	    }
	}
    }
  printc (";");
  print_copy_status ();
  printc ("}\n");
  clr_suppress_lines ();
}


/**
 * Print the C implementation of the PREPARE statement.
 *
 * Called when the parser identifies the complete statemen.
 *
 * @param stmt The statement identifier.
 * @param sqlvar The 4gl char variable from where the statement is to be
 * prepared.
 */
void
LEXLIB_print_prepare (char *xstmt, char *sqlvar)
{
  static char *stmt = 0;
  if (stmt)
    free (stmt);
  stmt = strdup (A4GL_strip_quotes (xstmt));
  printc ("{ /* prep1 */\n");
  set_suppress_lines ();
  printc ("\nEXEC SQL BEGIN DECLARE SECTION;\n");
  printc ("char *_s;\n");
  if (A4GL_strstartswith (stmt, "aclfgli_str_to_id"))
    {
      printc ("char *_sid;\n");
    }
  printc ("\nEXEC SQL END DECLARE SECTION;\n");
  clr_suppress_lines ();

  printc ("_s=strdup(CONVERTSQL_LN(%s,%d));\n", sqlvar, yylineno);

  if (A4GL_strstartswith (stmt, "aclfgli_str_to_id"))
    {
      printc ("_sid=%s;\n", xstmt);
      printc ("\nEXEC SQL PREPARE :_sid FROM :_s;\n", sqlvar);
    }
  else
    {
      printc ("\nEXEC SQL PREPARE %s FROM :_s;\n", stmt, sqlvar);
    }
  A4GL_save_sql ("PREPARE %s", sqlvar);

  printc ("free(_s);\n");
  printc ("}\n");
  print_copy_status ();
}


/**
 * The parser found a EXECUTE 4gl statement and generate the C implementation in
 * the output generated file.
 *
 * @param The statement identifier.
 * @param using Flag to indicate if the statement have USING instruction:
 *   - 0 : Does not have USING
 *   - 1 : EXECUTE have USING
 *   - 2 :         has INTO
 *   - 3 :         has INTO & USING
 */
void
LEXLIB_print_execute_g (char *stmt, int using, t_binding_comp_list* using_bind, t_binding_comp_list* into_bind)
{

  if (using == 0)
    {
      A4GL_save_sql ("EXECUTE %s", A4GL_strip_quotes (stmt));
      printc ("\nEXEC SQL EXECUTE %s;\n", A4GL_strip_quotes (stmt));
      print_copy_status ();
    }


  if (using == 1)
    {
      int a;
      printc ("{ /* EXECUTE 1 */\n");

      LEXLIB_print_bind_definition_g (using_bind);
      LEXLIB_print_bind_set_value_g (using_bind);
      print_conversions_g (using_bind);

      A4GL_save_sql ("EXECUTE %s USING ...", A4GL_strip_quotes (stmt));
      set_suppress_lines ();
      printc ("\nEXEC SQL EXECUTE %s USING \n", A4GL_strip_quotes (stmt));
      for (a = 0; a < using_bind->nbind; a++)
	{

	  if (a) printc (",");

	  if (!A4GLSQLCV_check_requirement ("USE_INDICATOR"))
	    {
	      printc (":_vi_%d\n", a);
	    }
	  else
	    {
	      if (esql_type () == E_DIALECT_INFOFLEX)
		{
		  printc (":_vi_%d  :_vii_%d\n", a, a);
		}
	      else
		{
	      if (esql_type () == E_DIALECT_POSTGRES)
		{
		  printc (":_vi_%d \n", a, a);
		} else {
		  printc (":_vi_%d INDICATOR :_vii_%d\n", a, a);
		}
		}
	    }
	}

      printc (";");
      clr_suppress_lines ();
      print_copy_status ();
      printc ("}\n");
    }

  if (using == 2)
    {
      int a;
      printc ("{ /* EXECUTE 2 */\n");
      LEXLIB_print_bind_definition_g (into_bind);
      LEXLIB_print_bind_set_value_g (into_bind);
      set_suppress_lines ();
      A4GL_save_sql ("EXECUTE %s INTO ...", A4GL_strip_quotes (stmt));
      printc ("\nEXEC SQL EXECUTE %s INTO \n", A4GL_strip_quotes (stmt));
      for (a = 0; a < into_bind->nbind; a++)
	{
	  if (a) printc (",");
	  if (!A4GLSQLCV_check_requirement ("USE_INDICATOR"))
	    {
	      printc (":_vo_%d\n", a);
	    }
	  else
	    {

	      if (esql_type () == E_DIALECT_INFOFLEX)
		{
		  printc (":_vo_%d  :_voi_%d\n", a, a);
		}
	      else
		{
		  printc (":_vo_%d INDICATOR :_voi_%d\n", a, a);
		}
	    }
	}

      printc (";");
      print_copy_status ();
      print_conversions_g (into_bind);
      printc ("}\n");
      clr_suppress_lines ();
    }


  if (using == 3)
    {
      int a;
      set_suppress_lines ();
      printc ("{ /* EXECUTE 3 */\n");
      LEXLIB_print_bind_definition_g (using_bind);
      LEXLIB_print_bind_definition_g (into_bind);

      LEXLIB_print_bind_set_value_g (into_bind);
      LEXLIB_print_bind_set_value_g (using_bind);

      print_conversions_g (using_bind);
      set_suppress_lines ();

      A4GL_save_sql ("EXECUTE %s INTO ... USING ...",
		     A4GL_strip_quotes (stmt));
      printc ("\nEXEC SQL EXECUTE %s ", A4GL_strip_quotes (stmt));

      printc (" INTO ");
      for (a = 0; a < into_bind->nbind ; a++)
	{
	  if (a)
	    printc (",");
	  if (!A4GLSQLCV_check_requirement ("USE_INDICATOR"))
	    {
	      printc (":_vo_%d\n", a);
	    }
	  else
	    {
	      if (esql_type () == E_DIALECT_INFOFLEX)
		{
		  printc (":_vo_%d  :_voi_%d\n", a, a);
		}
	      else
		{
		  printc (":_vo_%d INDICATOR :_voi_%d\n", a, a);
		}
	    }

	}

      printc (" USING ");

      for (a = 0; a < using_bind->nbind; a++)
	{
	  if (a)
	    printc (",");
	  if (!A4GLSQLCV_check_requirement ("USE_INDICATOR"))
	    {
	      printc (":_vi_%d\n", a);

	    }
	  else
	    {
	      if (esql_type () == E_DIALECT_INFOFLEX)
		{
		  printc (":_vi_%d  :_vii_%d\n", a, a);
		}
	      else
		{
	      if (esql_type () == E_DIALECT_POSTGRES) {
		  printc (":_vi_%d \n", a, a);
		} else {
		  printc (":_vi_%d INDICATOR :_vii_%d\n", a, a);
		}
		}
	    }
	}

      printc (";");
      clr_suppress_lines ();
      print_copy_status ();
      print_conversions_g (into_bind);
      printc ("}\n");
    }






}


/**
 * Generate the C code implementation of connetion to the database opening.
 *
 * Called when the parser found OPEN SESSION or CONNECT TO statement.
 *
 * @param s The connection identifier.
 * @param v The database name.
 * @param user The user name used.
 */
void
LEXLIB_print_open_session (char *s, char *v, char *user)
{
  printc ("{");
  set_suppress_lines ();
  printc ("\nEXEC SQL BEGIN DECLARE SECTION;");
  printc ("char _u[256];");
  printc ("char _p[256];");
  printc ("char _d[256];");
  printc ("\nEXEC SQL END DECLARE SECTION;");
  clr_suppress_lines ();
  
		/*
		Note: ecpg checks for PG_DBPATH:

		export PG_DBPATH=dbname[@server][:port]

		This will override any DATABASE statements in the .cpc (This is part of ecpg
		- not aubit4gl)

		see the sourcecode - I found some :
		http://jonathangardner.net/PostgreSQL/doxygen/7.4/connect_8c-source.html
		*/
  
  
  if (strcmp (v, "?") == 0)
    {
      printc ("strcpy(_d,A4GL_char_pop()); A4GL_trim(_d);");
    }
  if (strcmp(user,"0")==0) {
	  	user="";
  }
  if (strcmp(user,"0,0")==0) {
	  	user="";
  }
  if (strlen (user))
    {
      if (strcmp (user, "?") == 0)
	{
	  printc ("strcpy(_u,A4GL_char_pop());A4GL_trim(_u);");
	}
      else
	{
	  char buff[256];
	  char *ptr;
	  strcpy (buff, user);
	  ptr = strchr (buff, ',');
	  if (ptr)
	    {
	      *ptr = 0;
	      ptr++;
	    }
	  	printc ("strcpy(_u,%s);A4GL_trim(_u);", buff);
	  if (ptr)
	    {
	      printc ("strcpy(_p,%s);A4GL_trim(_p);", ptr);
	    }
	}
    }

  //printc("if (A4GL_esql_db_open(-1,0,0,\"\")) {");
  //print_close('D',"");
  //printc("}");
  //
  A4GL_save_sql ("CONNECT TO '%s'", v);

  if (strcmp (v, "?") == 0)
    {
	switch (esql_type()) {
	
	case E_DIALECT_POSTGRES:
	  printc ("\nEXEC SQL CONNECT TO  :_d AS %s", A4GL_strip_quotes (s));
	  if (strlen (user))
	    {
	      printc ("USER :_u USING :_p");
	    }
 	  break;

	case E_DIALECT_INFOFLEX:
	  printc ("\nEXEC SQL DATABASE  :_d ");
 	  break;

	default:
	  printc ("\nEXEC SQL CONNECT TO  :_d AS %s", s);
	  if (strlen (user))
	    {
	      printc ("USER :_u USING :_p");
	    }
	}
    }
  else
    {
      if (esql_type () == E_DIALECT_POSTGRES)
	{			// Postgres...
	  printc ("\nEXEC SQL CONNECT TO  %s AS %s", v,
		  A4GL_strip_quotes (s));
	  if (strlen (user))
	    {
	      printc ("USER :_u USING :_p");
	    }
	}
      else
	{
	  printc ("\nEXEC SQL CONNECT TO  '%s' AS %s", v, s);
	  if (strlen (user))
	    {
	      printc ("USER :_u USING :_p");
	    }
	}
    }
  printc (";");

  printc("if (sqlca.sqlcode>=0) {A4GL_set_esql_connection(%s);}",s);
  print_copy_status ();

  printc ("}");
}

/**
 * Generate the C code of a cursor opening.
 *
 * Called when the parser found the OPEN CURSOR 4gl statement.
 *
 * @param cname The cursor name.
 * @param using The using expression list.
 */
void
LEXLIB_print_open_cursor_g (char *xcname, t_binding_comp_list *using_bind)
{
  //int n;
  //int a;
  static char *cname = 0;
  if (cname)
    free (cname);
  cname = strdup (A4GL_strip_quotes (xcname));

  if (!A4GL_find_pointer(cname,CURCODE)) {
		set_yytext(cname);
		a4gl_yyerror("Cursor has not been previously defined");
		return ;
  }


  if (A4GLSQLCV_check_requirement ("EMULATE_INSERT_CURSOR"))
    {
      char c;
      c = A4GL_cursor_type (xcname);
      if (c == 'I')
	{
	  printc ("/* Ignore open cursor - faking insert cursor */");
	  return;		/* We don't really open a cursor - remember - we're pretending :-) */
	}
    }

  set_suppress_lines ();

  if (A4GLSQLCV_check_requirement ("CLOSE_CURSOR_BEFORE_OPEN"))
    {
      printc ("\nEXEC SQL CLOSE  %s; /* AUTOCLOSE */\n", cname);
    }

  if (using_bind && using_bind->bind)
    {
      int a;
      int ni;
      printc ("internal_recopy_%s_i_Dir();", cname);
      printc ("{ /* OPEN */\n");
      ni = LEXLIB_print_bind_definition_g (using_bind);
      LEXLIB_print_bind_set_value_g (using_bind);
      print_conversions_g (using_bind);

      A4GL_save_sql ("OPEN %s USING ...", cname);
      printc ("\nEXEC SQL OPEN %s USING \n", cname);
      for (a = 0; a < ni; a++)
	{
	  if (a)
	    printc (",");
	  printc (":_vi_%d\n", a);
	}

      printc (";");
      printc ("}\n");
    }
  else
    {
      printc ("internal_recopy_%s_i_Dir();", cname);
      A4GL_save_sql ("OPEN '%s'", cname);
      printc ("\nEXEC SQL OPEN  %s;\n", cname);
    }


  clr_suppress_lines ();
  print_copy_status ();
}

/**
 * @todo Desribe
 *
 *
 * @param
 */
void
LEXLIB_print_sql_commit (int t)
{
  if (t == -1)
    {
      A4GL_save_sql ("BEGIN WORK", 0);
      printc ("\nEXEC SQL BEGIN WORK;\n", t);
    }
  if (t == 0)
    {
      A4GL_save_sql ("ROLLBACK WORK", 0);
      printc ("\nEXEC SQL ROLLBACK WORK;\n", t);
    }
  if (t == 1)
    {
      A4GL_save_sql ("COMMIT WORK", 0);
      printc ("\nEXEC SQL COMMIT WORK;\n", t);
    }

  print_copy_status ();
}

/**
 * Print the C implementation of the FETCH statement.
 *
 * Called by the parser after found the end of the fetch (into).
 *
 * The generated code calls the function A4GLSQL_fetch_cursor()
 *
 * It seems to call fetch_cursor with diferent number of parameters, but
 * its not true since into is a string with values separated with comma.
 *
 * @param ftp The fetch part that includes: 
 *   - The cursor name.
 *   - The fetch scope ( ABSOLUTE or RELATIVE ).
 *   - The fetch place 
 * @param into The into variable list, taht includes:
 */
void
LEXLIB_print_fetch_3_g (struct s_fetch *fp, t_binding_comp_list *bind)
{
  //int fp1 = 0;
  //int fp2 = 0;
  //int poped = 0;
  char buff[256];
  int no;
  //char cname[256];
  char sqcname[256];
  int ll;
  struct expr_str *e;
  char bufffp[200];
  e = fp->fp->fetch_expr;

  no=bind->nbind;

  printc ("{");
  set_suppress_lines ();
  printc ("\nEXEC SQL BEGIN DECLARE SECTION;");
  printc ("int _fp;");
  printc ("\nEXEC SQL END DECLARE SECTION;");
  clr_suppress_lines ();


  strcpy (sqcname, A4GL_strip_quotes (fp->cname));
  set_suppress_lines ();

  if (!A4GL_find_pointer(sqcname,CURCODE)) {
		set_yytext(sqcname);
		a4gl_yyerror("Cursor has not been previously defined");
		return ;
  }

  ll = -2;
  if (e)
    {
      if (e->expr_type == ET_EXPR_LITERAL_LONG)
	{
	  ll = e->u_data.expr_long;
	  sprintf (bufffp, "%ld", e->u_data.expr_long);
	}
      else
	{
	  LEXLIB_print_expr (e);
	  printc ("_fp=A4GL_pop_long();");
	  sprintf (bufffp, ":_fp");
	}
    }



  if (fp->fp->ab_rel == FETCH_ABSOLUTE)
    {				/* FETCH ABSOLUTE */
      switch (ll)
	{
	case 1:
	  sprintf (buff, "\nEXEC SQL FETCH FIRST %s ", sqcname);
	  break;

	case -1:
	  sprintf (buff, "\nEXEC SQL FETCH LAST %s ", sqcname);
	  break;

	default:
	  sprintf (buff, "\nEXEC SQL FETCH ABSOLUTE %s %s", bufffp, sqcname);

	}
    }
  else
    {				/* FETCH RELATIVE */
      if (strcmp (bufffp, "1") != 0)
	{
	  sprintf (buff, "\nEXEC SQL FETCH RELATIVE %s %s ", bufffp, sqcname);
	}
      else
	{
	  sprintf (buff, "\nEXEC SQL FETCH %s", sqcname);
	}
    }

  if (strcmp (buff, "EMPTY") == 0)
    {
      a4gl_yyerror ("error calculating fetch instruction");
      return;
    }



  if (no == 0 && A4GLSQLCV_check_requirement ("NO_FETCH_WITHOUT_INTO"))
    {
      a4gl_yyerror
	("You cannot use a FETCH without an INTO with the target database");
    }


  printc ("/* ... no=%d*/", no);
  printc ("%s %s ;", buff, A4GL_get_into_part (0, no));

  A4GL_save_sql (buff, 0);

  print_copy_status ();
  if (bind->nbind) 
    {
      print_conversions_g (bind);
    }
  printc ("internal_recopy_%s_o_Dir();", sqcname);
  printc ("}");
  printc ("}");
  printc ("}");
  clr_suppress_lines ();
}

/**
 * Print in the ouput C generated file the implementation of DATABASE 
 * instruction.
 *
 * Called by the parser when found the DATABASE statement.
 *
 * Generate a call to the library implementation of connection initialization.
 *
 * @param db The database name:
 *   - 0 : Gets the database name from stack.
 *   - Otherwise : Use it as database name.
 */
void
LEXLIB_print_init_conn (char *db)
{

  if (A4GLSQLCV_check_requirement ("USE_DATABASE_STMT")
      || esql_type () == E_DIALECT_INFOFLEX)
    {
      if (db == 0)
	{
	  printc ("{");
	  set_suppress_lines ();
	  printc ("\nEXEC SQL BEGIN DECLARE SECTION;\n");
	  printc ("char *s;");
	  printc ("char setdb[256];");
	  printc ("\nEXEC SQL END DECLARE SECTION;\n");
	  clr_suppress_lines ();
	  printc ("s=A4GL_char_pop();A4GL_trim(s);");
	  /*printc("sprintf(setbuf,\"DATABASE %%s\");\n"); */


	  /*printc ("\nEXEC SQL PREPARE acl_p_set_db FROM $setdb;"); */
	  /*printc ("\nEXEC SQL EXECUTE acl_p_set_db;\n");  */
	  A4GL_save_sql ("DATABASE $s", 0);
	  printc ("\nEXEC SQL DATABASE $s;\n");

	  printc ("}");
	}
      else
	{
	  switch (esql_type ())
	    {
	    case E_DIALECT_NONE:
	      A4GL_assertion (1, "No ESQL/C Dialect");
	      break;
	    case E_DIALECT_INFORMIX:
	      A4GL_save_sql ("DATABASE %s", db);
	      printc ("\nEXEC SQL DATABASE %s;\n", db);
	      break;

	    case E_DIALECT_POSTGRES:
	      A4GL_save_sql ("DATABASE %s", db);
	      printc ("\nEXEC SQL DATABASE %s;\n", db);
	      break;

	    case E_DIALECT_SAPDB:
	      A4GL_save_sql ("DATABASE %s", db);
	      printc ("\nEXEC SQL DATABASE %s;\n", db);
	      break;

	    case E_DIALECT_INGRES:
	      A4GL_save_sql ("DATABASE %s", db);
	      printc ("\nEXEC SQL DATABASE %s;\n", db);
	      break;

	    case E_DIALECT_INFOFLEX:
	      A4GL_save_sql ("DATABASE %s", db);
	      printc ("\nEXEC SQL DATABASE %s;\n", db);
	      break;
	    }
	}
    }
  else
    {
      if (db == 0)
	{
	  printc ("{");
	  set_suppress_lines ();
	  printc ("\nEXEC SQL BEGIN DECLARE SECTION; \n");
	  printc ("char *s;");
	  printc ("\nEXEC SQL END DECLARE SECTION;\n");
	  clr_suppress_lines ();
	  printc ("if (A4GL_esql_db_open(-1,0,0,\"\")) {");
	  print_close ('D', "");
	  printc ("}");
	  printc ("s=A4GL_char_pop();A4GL_trim(s);\n");


	  A4GL_save_sql ("CONNECT TO $s AS 'default'", 0);

	  switch (esql_type ())
	    {
	    case E_DIALECT_NONE:
	      A4GL_assertion (1, "No ESQL/C Dialect");
	      break;
	    case E_DIALECT_INFORMIX:
	      printc ("\nEXEC SQL CONNECT TO $s AS 'default';\n");
	      break;
	    case E_DIALECT_POSTGRES:
	      printc ("\nEXEC SQL CONNECT TO :s AS 'default';\n");
	      break;
	    case E_DIALECT_SAPDB:
	      printc ("\nEXEC SQL CONNECT TO $s AS 'default';\n");
	      break;
	    case E_DIALECT_INGRES:
	      printc ("\nEXEC SQL CONNECT :s ;\n");
	      break;
	    case E_DIALECT_INFOFLEX:
	      printc ("\nEXEC SQL CONNECT TO $s AS 'default';\n");
	      break;
	    }
	  printc ("}");
	}
      else
	{
	  printc ("if (A4GL_esql_db_open(-1,0,0,\"\")) {");
	  print_close ('D', "");
	  A4GL_save_sql ("DISCONNECT default'", 0);
	  /*printc ("\nEXEC SQL DISCONNECT 'default';\n"); */
	  printc ("}");
	  switch (esql_type ())
	    {
	    case E_DIALECT_NONE:
	      A4GL_assertion (1, "No ESQL/C Dialect");
	      break;

	    case E_DIALECT_INFORMIX:
	      A4GL_save_sql ("CONNECT TO \"%s\" AS 'default'", db);
	      printc ("\nEXEC SQL CONNECT TO \"%s\" AS 'default';\n", db);
	      break;

	    case E_DIALECT_POSTGRES:
	      A4GL_save_sql ("CONNECT TO %s AS 'default'", db);
	      printc ("\nEXEC SQL CONNECT TO %s AS 'default';\n", db);
	      break;

	    case E_DIALECT_SAPDB:
	      A4GL_save_sql ("CONNECT TO %s AS 'default'", db);
	      printc ("\nEXEC SQL CONNECT TO %s AS 'default';\n", db);
	      break;

	    case E_DIALECT_INFOFLEX:
	      A4GL_save_sql ("CONNECT TO \"%s\" AS 'default'", db);
	      printc ("\nEXEC SQL CONNECT TO \"%s\" AS 'default';\n", db);
	      break;

	    case 4:
	      printc ("\nEXEC SQL CONNECT %s;\n", db);
	      break;
	    }
	}
    }

  switch (esql_type ())
    {
    case E_DIALECT_NONE:
      A4GL_assertion (1, "No ESQL/C Dialect");
      break;
    case E_DIALECT_INFORMIX:
      printc
	("if (sqlca.sqlcode==0) A4GL_esql_db_open(1,\"INFORMIX\",\"INFORMIX\",\"%s\");",
	 db);
      break;
    case E_DIALECT_POSTGRES:
      printc
	("if (sqlca.sqlcode==0) A4GL_esql_db_open(1,\"INFORMIX\",\"POSTGRES\",\"%s\");",
	 db);
      break;
    case E_DIALECT_SAPDB:
      printc
	("if (sqlca.sqlcode==0) A4GL_esql_db_open(1,\"INFORMIX\",\"SAP\",\"%s\");",
	 db);
      break;
    case E_DIALECT_INGRES:
      printc
	("if (sqlca.sqlcode==0) A4GL_esql_db_open(1,\"INFORMIX\",\"INGRES\",\"%s\");",
	 db);
      break;
    case E_DIALECT_INFOFLEX:
      printc
	("if (sqlca.sqlcode==0) A4GL_esql_db_open(1,\"INFORMIX\",\"INFOFLEX\",\"%s\");",
	 db);
      break;
    }


  print_copy_status ();
}


/**
 * Print the implementation of the execution of a select statement to the 
 * output C file.
 *
 * Called by the parser when it found the end of a select statement.
 *
 * @param s A string with the complete SQL select statement text.
 */
void
LEXLIB_print_do_select (char *s, int converted,t_binding_comp_list *bind)
{
//int no;
  A4GL_save_sql (s, 0);
  set_suppress_lines ();
  if (bind->nbind == 0 && A4GLSQLCV_check_requirement ("NO_SELECT_WITHOUT_INTO"))
    {
      a4gl_yyerror
	("You cannot use a SELECT without an INTO with the target database");
      return;
    }
  printc ("\nEXEC SQL %s;\n/* do_select */", s);
  clr_suppress_lines ();
  print_copy_status ();
  print_conversions_g (bind);
  printc ("}\n");
}

/**
 * Print in the generated C file the implementation of the FLUSH 4gl statement.
 *
 * Called by the parser when it founds that statement.
 *
 * @param s The cursor name.
 */
void
LEXLIB_print_flush_cursor (char *s)
{
  if (A4GLSQLCV_check_requirement ("EMULATE_INSERT_CURSOR"))
    {
      /* When emulating insert cursor, acutual INSERT is performed so
         there is nothing to FLUSH */
      printc ("\n /* ignored FLUSH for %s */ \n", A4GL_strip_quotes (s));
      //A4GL_save_sql("FLUSH %s",A4GL_strip_quotes(s));
    }
  else
    {
      A4GL_save_sql ("FLUSH %s", A4GL_strip_quotes (s));
      printc ("\nEXEC SQL FLUSH %s;\n", A4GL_strip_quotes (s));
      print_copy_status ();
    }
}

/**
 * Print in the output C file the implementation of a cursor declaration.
 *
 * Called by the parser when found every type of cursor declaration.
 *
 * The generated code calls the library funcation A4GLSQL_declare_cursor().
 *
 * @todo When the cursor is for update the string of the select need for 
 * update keyword at the end.
 *
 * @param a1 Indicate if the cursor is for update.
 *   - 1 : The cursor is for update.
 *   - 0 : The cursor is NOT for update.
 * @param a2 The cursor specification generated struct s_sid variable name.
 * @param a3 The cursor name.
 * @param h1 Flag to indicate if the cursor is with hold.
 *   - 0 : not WITH HOLD
 *   - 2 : WITH HOLD
 * @param h2 Flag that indicate if the cursor is with scroll:
 *   - 0 : The cursor its not with scroll
 *   - 1 : The cursor is with scroll
 */
void
LEXLIB_print_declare_g (char *a1, char *a2, char *a3, int h1, int h2,t_binding_comp_list *inbind, t_binding_comp_list *outbind)
{
  char buff[256];
  int intprflg = 0;
  static char *cname = 0;
  static int ccnt = 0;
  char *cname2 = 0;
  char *cname3 = 0;

  if (cname)
    free (cname);
  set_suppress_lines ();
  cname = strdup (A4GL_strip_quotes (a3));

  A4GL_add_pointer(cname,CURCODE,(void *) 1);


  // Are we trying to emulate an insert cursor ?
  if (A4GLSQLCV_check_requirement ("EMULATE_INSERT_CURSOR"))
    {
      char c;
      c = A4GL_cursor_type (a3);
      if (c == 'I')
	{
	  // Do we have a real statement or a prepared statement ?
	  if (a2[0] == '"' || A4GL_strstartswith (a2, "aclfgli_str_to_id"))
	    {			// It's already prepared
	      printc ("/* Ignore declare cursor - faking insert cursor */");
	      A4GL_insert_cursor_prep (a3, a2);
	    }
	  else
	    {
	      static int pcnt = 0;
	      char buff[20];
	      int aa;
	      char *sstr;
	      printc
		("/* preparing insert used on declare cursor - faking insert cursor */");
	      sprintf (buff, "\"p_a4gl_%d\"", pcnt++);
	      sstr = acl_malloc2 (strlen (a2) + 2000);
	      sprintf (sstr, "\"%s\"", a2);
	      for (aa = 0; aa < strlen (sstr); aa++)
		{
		  if (strncmp (&sstr[aa], ":_vi_", 5) == 0)
		    {
		      int b;
		      sstr[aa] = '?';
		      sstr[aa + 1] = ' ';
		      sstr[aa + 2] = ' ';
		      sstr[aa + 3] = ' ';
		      sstr[aa + 4] = ' ';
		      for (b = aa + 5; b < strlen (sstr); b++)
			{
			  if (sstr[b] < '0' || sstr[b] > '9')
			    {
			      aa = b - 1;
			      break;
			    }
			  sstr[b] = ' ';
			}
		    }






		  if (esql_type () == E_DIALECT_INFOFLEX)
		    {
		      if (strncmp (&sstr[aa], " :_vii_", 7) == 0)
			{
			  int b;
			  sstr[aa] = ' ';
			  sstr[aa + 1] = ' ';
			  sstr[aa + 2] = ' ';
			  sstr[aa + 3] = ' ';
			  sstr[aa + 4] = ' ';
			  sstr[aa + 5] = ' ';
			  sstr[aa + 6] = ' ';
			  for (b = aa + 16; b < strlen (sstr); b++)
			    {
			      if (sstr[b] < '0' || sstr[b] > '9')
				{
				  aa = b - 1;
				  break;
				}
			      sstr[b] = ' ';
			    }
			}


		      if (sstr[aa] == '\n')
			sstr[aa] = ' ';

		    }
		  else
		    {
		      if (strncmp (&sstr[aa], "INDICATOR :_vii_", 16) == 0)
			{
			  int b;
			  sstr[aa] = ' ';
			  sstr[aa + 1] = ' ';
			  sstr[aa + 2] = ' ';
			  sstr[aa + 3] = ' ';
			  sstr[aa + 4] = ' ';
			  sstr[aa + 5] = ' ';
			  sstr[aa + 6] = ' ';
			  sstr[aa + 7] = ' ';
			  sstr[aa + 8] = ' ';
			  sstr[aa + 9] = ' ';
			  sstr[aa + 10] = ' ';
			  sstr[aa + 11] = ' ';
			  sstr[aa + 12] = ' ';
			  sstr[aa + 13] = ' ';
			  sstr[aa + 14] = ' ';
			  sstr[aa + 15] = ' ';
			  for (b = aa + 16; b < strlen (sstr); b++)
			    {
			      if (sstr[b] < '0' || sstr[b] > '9')
				{
				  aa = b - 1;
				  break;
				}
			      sstr[b] = ' ';
			    }
			}


		      if (sstr[aa] == '\n')
			sstr[aa] = ' ';
		    }
		}
	      print_prepare (buff, sstr);
	      A4GL_insert_cursor_prep (a3, buff);
	      printc ("}");
	    }

	  return;		/* We don't really declare a cursor - remember - we're pretending :-) */
	}
    }



  if (a2[0] == '"' || A4GL_strstartswith (a2, "aclfgli_str_to_id"))
    {
      printc ("{ /* DC 0 */");
      if (A4GL_strstartswith (a2, "aclfgli_str_to_id"))
	{
	  printc ("EXEC SQL BEGIN DECLARE SECTION;\n");
	  printc ("char *_sid;");
	  printc ("EXEC SQL END DECLARE SECTION;\n");
	}
    }


  if (a2[0] == '"')
    {
      printc ("/* ... */");
      //start_bind ('i', 0);
      //start_bind ('o', 0);
      printc ("/* .2. */");
      print_conversions_g (outbind);
    }



  if (strlen (a1) && h2)
    {
      a4gl_yyerror ("Updates are not allowed on a scroll cursor");
      clr_suppress_lines ();
      return;
    }

  if (A4GL_strstartswith (a2, "aclfgli_str_to_id"))
    {
      printc ("_sid=%s;\n", a2);
      a2 = ":_sid";
    }

  cname2 = cname;
  cname3 = cname;

  if (A4GL_strstartswith (cname, "aclfgli_str_to_id"))
    {
      char buff[20];
      printc ("{ /* Another one */");
      printc ("EXEC SQL BEGIN DECLARE SECTION;");
      printc ("char _cid[256];");
      printc ("EXEC SQL END DECLARE SECTION;");
      printc ("strcpy(_cid,%s);", cname);
      cname2 = strdup (":_cid");
      sprintf (buff, "_%d", ccnt++);
      cname3 = buff;
    }

  sprintf (buff, "sqlca.sqlcode=0;\nEXEC SQL DECLARE %s", cname2);
  if (h2)
    {
      strcat (buff, " SCROLL");
    }
  strcat (buff, " CURSOR");
  if (h1 || esql_type () == E_DIALECT_POSTGRES)	/* All postgres cursors should be with hold */
    {
      strcat (buff, " WITH HOLD");
    }

  printc ("%s FOR", buff);
  A4GL_save_sql ("DECLARE CURSOR FOR %s", a2);
  printc ("     %s ", A4GL_strip_quotes (a2));

  printc (";");
  if (A4GL_strstartswith (cname, "aclfgli_str_to_id"))
    {
      printc ("} /* Cname starts with aclfgli... */");
    }
  print_copy_status ();


  if (outbind->nbind && A4GLSQLCV_check_requirement ("NO_DECLARE_INTO"))
    {
      a4gl_yyerror
	("You cannot use an INTO with a declare with the target database");
      return;
    }






  printh ("static int acli_ni_%s=%d;\n", cname3, inbind->nbind); // USE
  printh ("static int acli_no_%s=%d;\n", cname3, outbind->nbind); // USE
  printh ("static struct BINDING *acli_bi_%s=0;\n", cname3);
  printh ("static struct BINDING *acli_bo_%s=0;\n", cname3);
  printh ("static struct BINDING *acli_nbi_%s=0;\n", cname3);
  printh ("static struct BINDING *acli_nbo_%s=0;\n", cname3);
  printh ("static struct BINDING *acli_nbii_%s=0;\n", cname3);
  printh ("static struct BINDING *acli_nboi_%s=0;\n", cname3);

  printh ("\n\nstatic void internal_recopy_%s_i_Dir(void) {\n", cname3);
  printh ("struct BINDING *ibind;\n");
  printh ("struct BINDING *native_binding_i;\n");
  printh ("struct BINDING *native_binding_i_ind;\n");
  printh ("ibind=acli_bi_%s;\n", cname3);
  printh ("native_binding_i_ind=acli_nbii_%s;\n", cname3);
  printh ("native_binding_i=acli_nbi_%s;\n", cname3);
  inbind->type='I';
  print_conversions_g (inbind);
  inbind->type='i';

  printh ("}\n");

  printh ("\n\nstatic void internal_recopy_%s_o_Dir(void) {\n", cname3);
  printh ("struct BINDING *obind;\n");
  printh ("struct BINDING *native_binding_o;\n");
  printh ("struct BINDING *native_binding_o_ind;\n");
  printh ("obind=acli_bo_%s;\n", cname3);
  printh ("native_binding_o=acli_nbo_%s;\n", cname3);
  printh ("native_binding_o_ind=acli_nboi_%s;\n", cname3);



  outbind->type='O';
  print_conversions_g (outbind);
  outbind->type='o';
  
  
  
  printh ("}\n");
  printh
    ("\n\nstatic void internal_set_%s(struct BINDING *i,struct BINDING *o,struct BINDING *ni,struct BINDING *no,struct BINDING *nii,struct BINDING *noi) {\n",
     cname3);
  printh ("acli_bi_%s  =bind_recopy(acli_bi_%s,  %d,i);\n", cname3, cname3, inbind->nbind); // USE
  printh ("acli_bo_%s  =bind_recopy(acli_bo_%s,  %d,o);\n", cname3, cname3, outbind->nbind); // USE
  printh ("acli_nbi_%s =bind_recopy(acli_nbi_%s, %d,ni);\n", cname3, cname3, inbind->nbind); // USE
  printh ("acli_nbo_%s =bind_recopy(acli_nbo_%s, %d,no);\n", cname3, cname3, outbind->nbind); // USE
  printh ("acli_nbii_%s=bind_recopy(acli_nbii_%s,%d,nii);\n", cname3, cname3, inbind->nbind); // USE
  printh ("acli_nboi_%s=bind_recopy(acli_nboi_%s,%d,noi);\n", cname3, cname3, outbind->nbind); // USE
  printh ("}\n");

  intprflg = 0;

  if (inbind->nbind) intprflg++; // USE
  if (outbind->nbind) intprflg += 2; // USE

  switch (intprflg)
    {
    case 3:
      if (!A4GLSQLCV_check_requirement ("USE_INDICATOR"))
	sprintf (buff, "0,0");
      else
	sprintf (buff, "native_binding_i_ind,native_binding_o_ind");
      printc
	("internal_set_%s(ibind,obind,native_binding_i,native_binding_o,%s);",
	 cname3, buff);
      break;
    case 2:
      if (!A4GLSQLCV_check_requirement ("USE_INDICATOR"))
	sprintf (buff, "0,0");
      else
	sprintf (buff, "0,native_binding_o_ind");
      printc ("internal_set_%s(0,obind,0,native_binding_o,%s);", cname3,
	      buff);
      break;
    case 1:
      if (!A4GLSQLCV_check_requirement ("USE_INDICATOR"))
	{
	  sprintf (buff, "0,0");
	}
      else
	{
	  sprintf (buff, "native_binding_i_ind,0");
	}

      printc ("internal_set_%s(ibind,0,native_binding_i,0,%s);", cname3,
	      buff);
      break;

    case 0:
      printc ("internal_set_%s(0,0,0,0,0,0);", cname3);
      break;
    default:
      printc ("#error No internal_set written\n");
      break;

    }

  printc ("} /* DC 1*/\n");
  clr_suppress_lines ();

}




/**
 * Create the C code implementation to a cursor specification.
 *
 * Called by the parser when it founds a DECLARE CURSOR 4gl statement.
 *
 * @param type Define if the cursor have an explicit sql or is prepared:
 *   - 1 : The cursor is for insert.
 *   - 2 : The cursor is for select.
 * @param s The statement text.
 * @return A string with the C implementation.
 */
char *
LEXLIB_print_curr_spec_g (int type, char *s,t_binding_comp_list* inbind,t_binding_comp_list* outbind)
{
  static char buff[3000];
  int bt;
  int ni;
  int no;
  strcpy (buff, "");
  if (type == 1)
    {
      bt = 0;
      ni = inbind->nbind;
      no = outbind->nbind;


      if (outbind->nbind)
	{
	  bt++;
	}
      if (inbind->nbind)
	{
	  bt += 2;
	}

      if (bt || 1)
	printc ("{ /* cs1 */");
      if (bt & 1)
	LEXLIB_print_bind_definition_g (outbind);
      if (bt & 2)
	LEXLIB_print_bind_definition_g (inbind);
      if (bt & 1)
	LEXLIB_print_bind_set_value_g (outbind);
      if (bt & 2)
	LEXLIB_print_bind_set_value_g (inbind);
      if (bt)
	print_conversions_g (inbind);
      sprintf (buff, "%s", s);
    }


  if (type == 2)
    {
      sprintf (buff, "%s", s);
    }
  return buff;
}

/**
 * Create the C implementation of a select statement.
 *
 * This implementation calls the library function that prepares the statement 
 * A4GLSQL_prepare_select().
 *
 * This is called directly by the parser.
 *
 * @todo : Separate the generation from the parsing using an abstract syntax
 * tree.
 *
 *
 * @param buff A string buffer with the select statement
 * @return A string with the C implementation
 */
char *
LEXLIB_print_select_all_g (char *buff, int converted,t_binding_comp_list* inbind,t_binding_comp_list* outbind)
{
  int ni, no;
  static char *b2;
  printc ("{ /* print_select_all */\n");
  ni = LEXLIB_print_bind_definition_g (inbind);

  no = LEXLIB_print_bind_definition_g (outbind);

  LEXLIB_print_bind_set_value_g (inbind);
  LEXLIB_print_bind_set_value_g (outbind);
  print_conversions_g (inbind);
  b2 = strdup (buff);
  printc (" /* end of print_select_all */");
  return b2;
}

static char *
conv_owner (char *s)
{
  int a;
  int b = 0;
  static char *ptr = 0;
  if (ptr)
    free (ptr);

  ptr = acl_malloc2 (strlen (s) + 1000);
  for (a = 0; a < strlen (s); a++)
    {
      if (s[a] == '"' && s[a - 1] != '\\')
	ptr[b++] = '\\';
      ptr[b++] = s[a];
    }
  ptr[b] = 0;
  return ptr;
}


/**
 * Print in the generated C output file the implementation of the UNLOAD
 * 4gl statement.
 *
 * Called when the parser found the UNLOAD statement inthe 4gl source code.
 *
 * Here just calls the library function tal implements the real unload
 * (A4GLSQL_unload_data()).
 *
 * @param file The file name where the load will be to.
 * @param delim The delimiter between columns to generate.
 * @param sql The SQL that originate the unload data.
 */
void
LEXLIB_print_unload_g (char *file, char *delim, char *sql, t_binding_comp_list* inbind)
{
  char filename[256];
  char delim_s[256];
  int doing_esql_unload = 0;

  if (delim[0] == '"')
    {
      sprintf (delim_s, "'%s'", A4GL_strip_quotes (delim));
    }
  else
    {
      sprintf (delim_s, ":%s", delim);
    }



// ESQL_UNLOAD was initially designed to work with postgres
// postgres uses the COPY command to do the unload - but it can only
// handle UNLOADS with explicit SELECT statements - not variables
// 
// We need to check to see if we're dealing with that situation here...
//

  doing_esql_unload = A4GLSQLCV_check_requirement ("ESQL_UNLOAD");

  if (doing_esql_unload && strncasecmp (sql, "SELECT", 6) != 0)
    {

      // Looks like a query variable on the unload...
      // Do we just allow it anyway - and assume the esql/c compiler
      // can handle this syntax ?
      //
      if (A4GLSQLCV_check_requirement ("ESQL_UNLOAD_STRING"));	/* its ok */
      else
	{
	  // Traditionally - we'd just error here - but lets allow a 
	  // fallback to the libSQL_... unload functions
	  if (A4GLSQLCV_check_requirement ("ESQL_UNLOAD_LIB_FALLBACK"))
	    {
	      doing_esql_unload = 0;
	    }			/* its ok */
	  else
	    {
	      a4gl_yyerror
		("Cannot do an ESQL_UNLOAD for a prepared statement");
	      return;
	    }
	}
    }


  if (doing_esql_unload)
    {
      int ni;
      printc ("{ /* un1 */");
      ni = LEXLIB_print_bind_definition_g (inbind);
      LEXLIB_print_bind_set_value_g (inbind);
      print_conversions_g (inbind);
      sprintf (filename, ":_unlfname");
      printc ("{ /* un2 */");
      set_suppress_lines ();
      printc ("\nEXEC SQL BEGIN DECLARE SECTION; ");
      printc ("char _unlfname[512];");
      printc ("char _delim[512];");
      printc ("\nEXEC SQL END DECLARE SECTION;");
      clr_suppress_lines ();
      printc ("strcpy(_unlfname,%s);", file);
      printc ("strcpy(_delim,%s);", delim);
      printc ("A4GL_trim(_unlfname);");

      if (A4GLSQLCV_check_requirement ("ESQL_UNLOAD_FULL_PATH"))
	{
	  printc ("A4GLSQLCV_check_fullpath(_unlfname);");
	}

      A4GL_save_sql ("UNLOAD : %s", sql);
      printc ("\nEXEC SQL UNLOAD TO %s DELIMITER :_delim %s ;", filename,
	      sql);

      printc ("}");

      print_copy_status ();
      printc ("}");

    }
  else
    {
      int ni;
      int a;
      char *ptr;
      int isvar = -1;
      printc ("{ /* un3 */");
      ni = LEXLIB_print_bind_definition_g (inbind);
      LEXLIB_print_bind_set_value_g (inbind);
      ptr = strdup (sql);
      for (a = 0; a < strlen (ptr); a++)
	{
	  if (strncmp (&ptr[a], ":_vi_", 5) == 0)
	    {
	      int b;
	      ptr[a] = '?';
	      ptr[a + 1] = ' ';
	      ptr[a + 2] = ' ';
	      ptr[a + 3] = ' ';
	      ptr[a + 4] = ' ';
	      for (b = a + 5; b < strlen (ptr); b++)
		{
		  if (ptr[b] < '0' || ptr[b] > '9')
		    {
		      a = b - 1;
		      break;
		    }
		  ptr[b] = ' ';
		}
	    }

	  if (esql_type () == E_DIALECT_INFOFLEX)
	    {
	      if (strncmp (&ptr[a], " :_vii_", 16) == 0)
		{
		  int b;
		  for (b = 0; b < 16; b++)
		    {
		      ptr[a + b] = ' ';
		    }

		  for (b = a + 16; b < strlen (ptr); b++)
		    {
		      if (ptr[b] < '0' || ptr[b] > '9')
			{
			  a = b - 1;
			  break;
			}
		      ptr[b] = ' ';
		    }
		}
	    }
	  else
	    {
	      if (strncmp (&ptr[a], "INDICATOR :_vii_", 16) == 0)
		{
		  int b;
		  for (b = 0; b < 16; b++)
		    {
		      ptr[a + b] = ' ';
		    }

		  for (b = a + 16; b < strlen (ptr); b++)
		    {
		      if (ptr[b] < '0' || ptr[b] > '9')
			{
			  a = b - 1;
			  break;
			}
		      ptr[b] = ' ';
		    }
		}
	    }


	  if (ptr[a] == '\n')
	    ptr[a] = ' ';
	}
      print_conversions_g (inbind);


      if (strncmp (sql, "SELECT ", 7) == 0)
	isvar = 0;
      if (isvar == -1)
	{
	  if (scan_variable (ptr) == -1)
	    isvar = 0;
	  else
	    isvar = 1;
	}


      if (isvar == 0)
	{
	  printc
	    ("A4GLSQL_unload_data(%s,%s, \"%s\",%d,native_binding_i,0);\n",
	     file, delim, conv_owner (ptr), ni);
	}
      else
	{
	  printc ("A4GLSQL_unload_data(%s,%s, %s,%d,native_binding_i,0);\n",
		  file, delim, conv_owner (ptr), ni);
	}
      printc ("}");
    }
}

/**
 * Print in the generated C output file the implementation of the LOAD
 * 4gl statement.
 *
 * Here it just call the library function that implements the real load
 * (A4GLSQL_load_data()).
 *
 * @param file The file from where the load it will be made.
 * @param delim The field/column delimiter character.
 * @param tab The name of the database table where the rows will be loaded.
 * @param list The list of the columns to be loaded. If null uses all the
 *             columns of the table.
 */
void
LEXLIB_print_load (char *file, char *delim, char *tab, char *list)
{
  char filename[256];
  char delim_s[256];

  if (A4GLSQLCV_check_requirement ("ESQL_UNLOAD"))
    {
      printc ("{ /* load1 */");
      set_suppress_lines ();
      printc ("\nEXEC SQL BEGIN DECLARE SECTION; ");
      printc ("char _loadfname[512];");
      printc ("char _delim[64];");
      printc ("\nEXEC SQL END DECLARE SECTION;");
      clr_suppress_lines ();


      if (file[0] == '"')
	{
	  sprintf (filename, ":_loadfname");
	  printc ("strcpy(_loadfname,%s);", file);
	  printc ("A4GL_trim(_loadfname);");
	  if (A4GLSQLCV_check_requirement ("ESQL_UNLOAD_FULL_PATH"))
	    {
	      printc ("A4GLSQLCV_check_fullpath(_loadfname);");
	    }
	}
      else
	{
	  sprintf (filename, ":_loadfname");
	  printc ("strcpy(_loadfname,%s);", file);
	  printc ("A4GL_trim(_loadfname);");
	  if (A4GLSQLCV_check_requirement ("ESQL_UNLOAD_FULL_PATH"))
	    {
	      printc ("A4GLSQLCV_check_fullpath(_loadfname);");
	    }
	}


      if (delim[0] == '"')
	{
	  sprintf (delim_s, "\'%s\'", A4GL_strip_quotes (delim));
	}
      else
	{
	  printc ("strcpy(_delim,%s);", delim);
	  strcpy (delim_s, ":_delim");
	}

      A4GL_save_sql ("LOAD : %s", tab);
      printc ("\nEXEC SQL LOAD FROM %s DELIMITER %s ", filename, delim_s);


      if (strlen (list) == 1)
	printc (" INSERT INTO %s  ;", tab);
      else
	{
	  char *ptr;
	  char buff[100];
	  int p = 0;
	  list[strlen (list) - 2] = 0;
	  ptr = list;
	  printc (" INSERT INTO %s (", tab);
	  while (1)
	    {
	      strcpy (buff, ptr);
	      ptr = strchr (buff, ',');
	      if (ptr)
		*ptr = 0;
	      printc ("%c%s", p ? ',' : ' ', A4GL_strip_quotes (buff));

	      p++;
	      if (ptr == 0)
		break;
	      ptr++;
	    }
	  printc (");");

	}
      printc ("}");
      print_copy_status ();
    }
  else
    {
      printc ("A4GLSQL_load_data(%s,%s,\"%s\",%s);\n", file, delim, tab,
	      list);
    }
}



/**
 * @todo Desribe
 *
 *
 * @param
 */
void
LEXLIB_print_load_str (char *file, char *delim, char *str)
{
  printc ("/* LOAD NOT IMPLEMENTED YET */");
}


/**
 * Print in the generated file the C implementation for use a specific 
 * connection in a SQL statement.
 *
 * Called when the parser found USE SESSION statement before an sql statement.
 *
 * @param sess The session string identifier.
 */
void
LEXLIB_print_use_session (char *sess)
{
  printc ("{");
  printc("EXEC SQL BEGIN DECLARE SECTION;");
  printc("char _sav_cur_conn[32];\n"); 
  printc("EXEC SQL END DECLARE SECTION;");
  printc ("strcpy(_sav_cur_conn,A4GL_get_esql_connection());\n"); 
  //printc ("EXEC SQL S"ET CONNECTION %s;\n", sess); 
	  LEXLIB_print_set_conn(sess);
  //printc ("/* USE NOT IMPLEMENTED FOR ESQL/C */");
}


/**
 * Used when the parser found the USE SESSION <connection> FOR <sql_statement>
 * to store the current opened connection.
 *
 * This statement (USE SESSION) is an aubit extension that gives us the ability
 * of using several connections in one 4gl program.
 *
 * @return The C implementation for seving current connection.
 */
char *
LEXLIB_A4GL_get_undo_use (void)
{
  return "EXEC SQL SET CONNECTION :_sav_cur_conn;}\n"; 
  /* return ""; */
}


/**
 * @todo Desribe
 *
 *
 * @param
 */
static void
print_copy_status ()
{
  printc
    ("A4GLSQL_set_status(sqlca.sqlcode,1); /* Informix Status -> A4GL */");
  printc
    ("A4GLSQL_set_sqlerrd(sqlca.sqlerrd[0], sqlca.sqlerrd[1], sqlca.sqlerrd[2], sqlca.sqlerrd[3], sqlca.sqlerrd[4], sqlca.sqlerrd[5]);");

  printc ("A4GLSQL_SET_SQLCA_SQLWARN;");

  switch (esql_type ())
    {
    case E_DIALECT_NONE:
      A4GL_assertion (1, "No ESQL/C Dialect");
      break;
    case E_DIALECT_INFORMIX:
      printc ("A4GLSQL_set_sqlerrm(sqlca.sqlerrm,sqlca.sqlerrp);");
      break;
    case E_DIALECT_POSTGRES:
      printc ("A4GLSQL_set_sqlerrm(sqlca.sqlerrm.sqlerrmc,sqlca.sqlerrp);");
      break;
    case E_DIALECT_SAPDB:
      printc ("A4GLSQL_set_sqlerrm(sqlca.sqlerrm.sqlerrmc,sqlca.sqlerrp);");
      break;
    case E_DIALECT_INGRES:
      printc ("A4GLSQL_set_sqlerrm(sqlca.sqlerrm.sqlerrmc,sqlca.sqlerrp);");
      break;
    case E_DIALECT_INFOFLEX:
      printc ("A4GLSQL_set_sqlerrm(sqlca.sqlerrm,sqlca.sqlerrp);");
      break;
    }

}


/**
 * @todo Desribe
 *
 *
 * @param
 */
void
LEXLIB_print_sql_block_cmd_g (char *s,t_binding_comp_list *inbind,t_binding_comp_list *outbind)
{
  int ni;
  int no;
  printc ("{ /* sql_block_cmd */");
  ni = LEXLIB_print_bind_definition_g (inbind);
  no = LEXLIB_print_bind_definition_g (outbind);
  LEXLIB_print_bind_set_value_g (inbind);
  LEXLIB_print_bind_set_value_g (outbind);
  print_conversions_g (inbind);
  A4GL_save_sql (s, 0);
  printc ("\nEXEC SQL %s;", s);
  print_copy_status ();
  print_conversions_g (outbind);
  printc ("}");
}

/**
 * The parser found END FOREACH.
 *
 * Prints to the generated output file the C implementation of the end of
 * this statement (that is a C block close with }).
 */
void
LEXLIB_print_foreach_end (char *cname)
{
  printc ("}");




  /* printc ("}"); */
  printcomment ("/* end of foreach while loop */\n");



  /* printc ("}\n"); */


  /* print_foreach_close(cname); */
  /*print_close('C', cname); */
}


/**
 * @todo Desribe
 *
 *
 * @param
 */
char *
LEXLIB_get_column_transform (char *s)
{
  char buff[256];
  static char buff2[256];
  char *ptr1;
  char *ptr2;
  int n, m;
  int l;
  if (strchr (s, '[') == 0)
    return s;







  switch (esql_type ())
    {
    case E_DIALECT_NONE:
      A4GL_assertion (1, "No ESQL/C Dialect");
      break;
    case E_DIALECT_INFORMIX:
      return s;			/* Informix style */
      break;

    case E_DIALECT_POSTGRES:
    case E_DIALECT_SAPDB:
    case E_DIALECT_INGRES:
      strcpy (buff, s);
      ptr1 = strchr (buff, '[');
      *ptr1 = 0;
      ptr1++;
      ptr2 = strchr (ptr1, ',');
      if (ptr2 == 0)
	{
	  ptr2 = strdup ("1]");
	}
      else
	{
	  *ptr2 = 0;
	  ptr2++;
	}
      l = strlen (ptr2);
      if (ptr2[l - 1] == ']')
	{
	  ptr2[l - 1] = 0;
	}
      n = atoi (ptr1);
      m = atoi (ptr2);
      sprintf (buff2, "substr(%s,%d,%d)", buff, n, (m - n) + 1);
      return buff2;
      break;
    case E_DIALECT_INFOFLEX:
      return s;			/* Informix style */
      break;
    }
  return s;
}




static char *
nm (int n)
{
  switch (n & 15)
    {
    case 0:
      return "CHAR";
    case 1:
      return "SMALLINT";
    case 2:
      return "INTEGER";
    case 3:
      return "FLOAT";
    case 4:
      return "SMALLFLOAT";
    case 5:
      return "DECIMAL";
    case 6:
      return "INTEGER";
    case 7:
      return "DATE";
    case 8:
      if (A4GLSQLCV_check_requirement ("MONEY_AS_DECIMAL"))
	return "DECIMAL";
      else
	return "MONEY";
    case 10:
      return "DATETIME";
    case 11:
      return "BYTE";
    case 12:
      return "TEXT";
    case 13:
      return "VARCHAR";
    case 14:
      return "INTERVAL ";
    }
  return "CHAR";
}


void
print_report_table (char *repname, char type, int c,char *asc_desc,t_binding_comp_list *funcbind,t_binding_comp_list *orderbind)
{



  static char iname[256];
  static char cname[256];
  char buff[10000];
  static char reptab[64];
  char tmpbuff[256];
  char ins_str[10000];
  static int rcnt = 0;
  int a;
  int converted = 0;
  int l_dt;
  int l_sz;

  t_binding_comp_list *inbind;
  t_binding_comp_list *outbind;

  if (A4GLSQLCV_check_requirement ("TEMP_AS_DECLARE_GLOBAL"))
    {
      char b[64];
      sprintf (reptab, "aclfgl_%d%s", rcnt, repname);
      reptab[18] = 0;		/* Make sure its short enough... */
      sprintf (b, "session.%s", reptab);
      strcpy (reptab, b);
    }
  else
    {
      sprintf (reptab, "aclfgl_%d%s", rcnt, repname);
      reptab[18] = 0;		/* Make sure its short enough... */
    }

  if (type == 'R')
    {
	t_binding_comp_list l;
      /* to copy it across... */
      //extern int ibindcnt;
      //extern long a_ibind;
      //extern int fbindcnt;
      //ibindcnt = fbindcnt;
      //ibind = ensure_bind (&a_ibind, ibindcnt, ibind);
      //memcpy (ibind, fbind, sizeof (struct binding_comp) * c + 1);
      
      if (A4GLSQLCV_check_requirement ("TEMP_AS_DECLARE_GLOBAL"))
	{
	  sprintf (iname, "acl_p%s", &reptab[8]);
	  iname[18] = 0;
	}
      else
	{
	  sprintf (iname, "acl_p%s", reptab);
	  iname[18] = 0;
	}

      /* print_execute needs an ibind - we have an fbind - so we need */
	memcpy(&l,funcbind,sizeof(l));
	l.type='i';
        LEXLIB_print_execute_g (iname, 1,&l,empty_genbind('o'));
    }


  if (type == 'E')
    {
      printc ("A4GL_free_duplicate_binding(obind,%d);", fbindcnt);
      printc ("}");

    }

  if (type == 'F')
    {
     t_binding_comp_list l;
      //extern int fbindcnt;
      //char buff[256];
      //char buff2[256];
      struct s_fetch f;
	memcpy(&l,funcbind,sizeof(l));
	l.type='o';

      printc ("{ /* Type F */");
      printc ("struct BINDING *obind;");
      printc ("obind=A4GL_duplicate_binding(_rbind,%d);", funcbind->nbind);
      printc ("        while (1) {");
      printc ("{ /* Type F 2 */");
      printc ("{");

	make_sql_bind_g (&l);

      printc ("/* MJAMJA - printing obind */");


      strcpy (f.cname, cname);
      f.fp = malloc (sizeof (struct s_fetch_place));
      f.fp->ab_rel = FETCH_RELATIVE;
      f.fp->fetch_expr = A4GL_new_literal_long_long (1);
      //sprintf (buff2, "%d,_rbind", c);
      print_fetch_3_g (&f,&l);
      printc ("if (sqlca.sqlcode!=0) break;");
      printc ("A4GL_push_params (obind, %d);", c);

    }

  if (type == 'I')
    {
      //extern int current_ordbindcnt;
      //extern struct binding_comp *ordbind;
      char sql[1024];
      int a;
      int b;
      char *p;
      /* We need to */
      /*    1.  Generate the SQL including our order by */
      /*    2.  declare a cursor for it */
      /*    3.  open that cursor */
      if (A4GLSQLCV_check_requirement ("TEMP_AS_DECLARE_GLOBAL"))
	{
	  sprintf (cname, "acl_c%s", &reptab[8]);
	  cname[18] = 0;
	}
      else
	{
	  sprintf (cname, "acl_c%s", reptab);
	  cname[18] = 0;
	}

      sprintf (sql, "SELECT * FROM %s ORDER BY ", reptab);
      for (a = 0; a < orderbind->nbind ; a++)
	{
	  int found = 0;
	  if (a)
	    strcat (sql, ",");

	  for (b = 0; b < funcbind->nbind; b++)
	    {
	      if (strcmp (orderbind->bind[a].varname, funcbind->bind[b].varname) == 0)
		{
		  char tmpbuff[256];
		  if (asc_desc[a]=='D') {
		  	sprintf (tmpbuff, "c%d DESC", b);
		  } else {
		  	sprintf (tmpbuff, "c%d", b);
		  }
		  strcat (sql, tmpbuff);
		  found = 1;
		  break;
		}
	    }

	  if (found == 0)
	    {
	      a4gl_yyerror ("Could not find variable for order by in report");
	      return;
	    }
	}


      //start_bind ('i', 0);
      //start_bind ('o', 0);
      inbind=empty_genbind('i');
      outbind=empty_genbind('o');
      p = print_select_all_g (sql, 0,inbind,outbind);
      print_declare_g ("0", p, cname, 0, 0,inbind,outbind);
      LEXLIB_print_open_cursor_g (cname, inbind);


    }


  if (type == 'E')
    {
      char buff[256];
      if (A4GLSQLCV_check_requirement ("TEMP_AS_DECLARE_GLOBAL"))
	{
	  sprintf (cname, "acl_c%s", &reptab[8]);
	  cname[18] = 0;
	}
      else
	{
	  sprintf (cname, "acl_c%s", reptab);
	  cname[18] = 0;
	}

      print_close ('C', cname);
      sprintf (buff, "DROP TABLE %s", reptab);
      inbind=empty_genbind('i');
      print_exec_sql_bound_g (buff, 0,inbind);
    }

  if (type == 'M')
    {				/* Make the table */
      char *xptr;
      if (A4GLSQLCV_check_requirement ("TEMP_AS_DECLARE_GLOBAL"))
	{
	  printc ("A4GLSQLCV_add_temp_table(\"%s\");", &reptab[8]);
	  sprintf (buff, "DECLARE GLOBAL TEMPORARY TABLE %s( \n", reptab);

	}
      else
	{
	  sprintf (buff, "CREATE TEMP TABLE %s( \n", reptab);
	}
      sprintf (ins_str, "\"INSERT INTO %s VALUES (", reptab);
      rcnt++;
      for (a = 0; a < c; a++)
	{
	  char dtype_char[256];
	  char dtype_char2[256];;
	  if (a)
	    {
	      strcat (buff, ",\n");
	      strcat (ins_str, ",");
	    }
	  sprintf (tmpbuff, "c%d ", a);
	  strcat (buff, tmpbuff);
	  l_dt = funcbind->bind[a].dtype & 0xffff;
	  l_sz = DECODE_SIZE (funcbind->bind[a].dtype);

	  strcpy (dtype_char, nm (l_dt));

	  strcat (dtype_char, (char *) A4GL_dtype_sz (l_dt, l_sz));
	  strcpy (dtype_char2, A4GLSQLCV_dtype_alias (dtype_char));
	  strcat (buff, dtype_char2);
	  strcat (ins_str, "?");
	}

      if (A4GLSQLCV_check_requirement ("TEMP_AS_DECLARE_GLOBAL"))
	{
	  strcat (buff, ") ON COMMIT PRESERVE ROWS WITH NORECOVERY");
	  if (!A4GL_has_pointer (&reptab[8], LOG_TEMP_TABLE))
	    {
	      A4GL_add_pointer (&reptab[8], LOG_TEMP_TABLE, (void *) 1);
	    }

	}
      else
	{
	  strcat (buff, ")");
	}
      strcat (ins_str, ")\"");

      //start_bind ('i', 0);
      set_suppress_lines ();

      xptr = A4GLSQLCV_check_sql (buff, &converted);
	inbind=empty_genbind('i');
      print_exec_sql_bound_g (xptr, converted,inbind);

      clr_suppress_lines ();

      sprintf (buff, "DELETE FROM %s", reptab);
      xptr = A4GLSQLCV_check_sql (buff, &converted);
      print_exec_sql_bound_g (xptr, converted,inbind );


      if (A4GLSQLCV_check_requirement ("TEMP_AS_DECLARE_GLOBAL"))
	{
	  sprintf (iname, "acl_p%s", &reptab[8]);
	  iname[18] = 0;
	}
      else
	{
	  sprintf (iname, "acl_p%s", reptab);
	  iname[18] = 0;
	}



      print_prepare (iname, ins_str);
    }

}


void
LEXLIB_A4GL_add_put_string (char *s)
{
}


void
print_exists_subquery (int i, struct expr_exists_sq *e_expr)
{
  char buff[256];
  char cname[256];
  static int ncnt = 0;
  t_binding_comp_list l;

  sprintf (cname, "aclfgl_cE_%d", ncnt++);

  printc ("{");
  printc ("EXEC SQL BEGIN DECLARE SECTION;");
  printc ("int _npc;");
  printc ("short _npi;");
  printc ("char _np[256];");
  printc ("EXEC SQL END DECLARE SECTION;");
	l.type='i';
	l.bind=e_expr->ibind;
	l.nbind=e_expr->nibind;
	l.abind=e_expr->nibind;
	l.str=0;

  print_bind_dir_definition_g (&l);
  LEXLIB_print_bind_set_value_g (&l);

  printc ("%s", l.str);
  if (esql_type () == E_DIALECT_INGRES)
    {
      printc ("sqlca.sqlcode=0;\nEXEC SQL DECLARE %s CURSOR FOR %s;", cname,
	      e_expr->subquery);
    }
  else
    {
      printc
	("sqlca.sqlcode=0;\nEXEC SQL DECLARE %s CURSOR WITH HOLD FOR %s;",
	 cname, e_expr->subquery);
    }

  printc ("if (sqlca.sqlcode==0) {\nEXEC SQL OPEN %s;\n", cname);



  if (i)
    {
      printc ("\nEXEC SQL FETCH %s INTO :_np;\n", cname);
      printc ("} if (sqlca.sqlcode==0) A4GL_push_int(1);");
      printc ("else A4GL_push_int(0);\n}");
      return;			//ptr
    }
  else
    {
      printc (buff, "\nEXEC SQL FETCH %s INTO :_np;\n", cname);
      printc (buff, "} if (sqlca.sqlcode==100) A4GL_push_int(1);");
      printc (buff, "else A4GL_push_int(0);\n}");
      return;			// ptr
    }
}



void
print_in_subquery (int i, struct expr_in_sq *in_expr)
{
  char cname[256];
  static int ncnt = 0;
  t_binding_comp_list l;

  sprintf (cname, "aclfgl_cI_%d", ncnt++);
  LEXLIB_print_expr (in_expr->expr);
  printc ("{");
  printc ("EXEC SQL BEGIN DECLARE SECTION;");
  printc ("int _npc;");
  printc ("short _npi;");
  printc ("char _np[256];");
  printc ("EXEC SQL END DECLARE SECTION;");

	l.type='i';
	l.bind=in_expr->ibind;
	l.nbind=in_expr->nibind;
	l.abind=in_expr->nibind;
	l.str=0;

  print_bind_dir_definition_g (&l);
  LEXLIB_print_bind_set_value_g (&l);



  printc ("%s", l.str);

  if (esql_type () == E_DIALECT_INGRES)
    {
      printc ("sqlca.sqlcode=0;\nEXEC SQL DECLARE %s CURSOR FOR %s;", cname,
	      in_expr->subquery);
    }
  else
    {
      printc
	("sqlca.sqlcode=0;\nEXEC SQL DECLARE %s CURSOR WITH HOLD FOR %s;",
	 cname, in_expr->subquery);
    }

  printc ("if (sqlca.sqlcode==0) {\nEXEC SQL OPEN %s;\n", cname);


  printc ("_npc=0;while (1) {\n");



  if (!A4GLSQLCV_check_requirement ("USE_INDICATOR"))
    {
      printc ("\nEXEC SQL FETCH %s INTO :_np;\n", cname);
    }
  else
    {

      if (esql_type () == E_DIALECT_INFOFLEX)
	{
	  printc ("\nEXEC SQL FETCH %s INTO :_np :_npi;\n", cname);
	}
      else
	{
	  printc ("\nEXEC SQL FETCH %s INTO :_np INDICATOR :_npi;\n", cname);
	}
    }

  printc ("if (sqlca.sqlcode!=0) break;\n");
  printc
    ("if (_npi>=0) A4GL_push_char(_np); else A4GL_push_null(2,0); _npc++;\n");
  printc ("}\nA4GL_push_int(_npc);");

  if (i)
    printc (" A4GL_pushop(OP_IN);");
  else
    printc (" A4GL_pushop(OP_NOTIN);");
  printc ("} else {A4GL_push_int(0);}\n}");
}


/**
 *  *
 *   * @todo Describe function
 *    */
int
doing_esql (void)
{
  return 1;
}

/*
int LEXLIB_compile_time_convert(void) {
	        return 1;
}
*/



/* ================================== EOF =============================== */





// 0 for escape = "\\\\"
//

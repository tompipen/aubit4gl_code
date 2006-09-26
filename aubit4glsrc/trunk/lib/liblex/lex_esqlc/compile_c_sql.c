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
# $Id: compile_c_sql.c,v 1.70 2006-09-26 09:08:22 mikeaubury Exp $
#
*/

#include "a4gl_lib_lex_esqlc_int.h"
void printc (char *fmt, ...);
void printcomment (char *fmt, ...);
#ifndef lint
	static char const module_id[] =
		"$Id: compile_c_sql.c,v 1.70 2006-09-26 09:08:22 mikeaubury Exp $";
#endif


void print_report_table(char *repname,char type, int c);
void printh (char *fmt, ...);
void liblex_add_ibind(int dtype,char *var) ;
static char *trans_quote (char *s);
extern char curr_func[];
extern int lastlineno;
extern int yylineno;
extern char *infilename;

/**
 * Print the C implementation of the execution of the SQL statement allready
 * readed.
 *
 * @param The string with the sql statement to be executed.
 */
void
LEXLIB_print_exec_sql (char *s,int converted)
{
  printc ("A4GLSQL_execute_implicit_sql(A4GLSQL_prepare_select(0,0,0,0,\"%s\",_module_name,%d,%d),1);\n", s,lastlineno,converted);
}


/**
 * @todo Desribe
 *
 *
 * @param
 */
void
LEXLIB_print_exec_sql_bound (char *s,int converted)
{
  int c;
  printc ("{\n");
  c = LEXLIB_print_bind_definition ('i');
  LEXLIB_print_bind_set_value ('i');
  printc
    ("A4GLSQL_execute_implicit_sql(A4GLSQL_prepare_select(ibind,%d,0,0,\"%s\",_module_name,%d,%d),1);\n", c,s,lastlineno,converted);
  printc ("}\n");
}

void
LEXLIB_print_close (char type, char *name)
{
  switch (type)
    {
    case 'F':
      printc ("A4GL_close_form(%s);\n", name);
      break;
    case 'W':
      printc ("A4GL_remove_window(%s);\n", name);
      break;
    case 'D':
      printc ("A4GL_close_database();\n");
      break;
    case 'S':
      printc ("A4GLSQL_close_session(%s);\n", name);
      break;
    case 'C':
      printc ("A4GLSQL_close_cursor(%s);\n", name);
      break;
    }
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
LEXLIB_print_foreach_next (char *cursorname, int has_using, char *into)
{
  int ni;
  printc ("A4GLSQL_set_sqlca_sqlcode(0);\n");
  LEXLIB_print_open_cursor(cursorname,has_using);
  /*printc ("A4GLSQL_open_cursor(0,%s);\n", cursorname);*/

  printc ("if (a4gl_sqlca.sqlcode!=0) {");
  exit_loop("FOREACH");
    printc("}");

  /* printc ("if (a4gl_sqlca.sqlcode==0) {\n");*/
  printc("_cursoropen=1;");
  printc ("while (1) {\n");
  ni = LEXLIB_print_bind_definition ('o');
  LEXLIB_print_bind_set_value('o');
  printc ("A4GLSQL_fetch_cursor(%s,%d,1,%d,obind);\n", cursorname, FETCH_RELATIVE, ni);
  printc ("if (a4gl_sqlca.sqlcode<0||a4gl_sqlca.sqlcode==100) break;\n");
}

/**
 * Print the C implementation of the FREE CURSOR 4gl statement.
 *
 * Not used and do not generate any implementation.
 *
 * FIXME: function exists in odbc/sql.c
 *
 * @param c The cursor name.
 */
void
LEXLIB_print_free_cursor (char *s)
{
  printc ("A4GLSQL_free_cursor (%s);\n",s);


}

/**
 * Print the C code implementation for sql USING 4gl statements.
 *
 * This statement are not informix 4gl original statements.
 *
 * @param type : The sql statement type.
 *   - S : Select
 *   - D : Delete
 *   - U : Update
 * @param var The 4gl variable name to be used.
 */
int
LEXLIB_print_linked_cmd (int type, char *var)
{
  char tabname[64];
  char pklist[256];
  int ni;
  if (last_var_is_linked (tabname, pklist))
    {
      char buff[80];
      char buff2[80];
      int no = 0;
      int no_keys;
      int azcnt;
      printc ("{\n");
      if (type == 'S')
	{
	  start_bind ('o', 0);
	  sprintf (buff, "%s.*", var);
	  add_bind ('o', buff);
	}

      A4GL_debug ("Finding number of keys...\n");
      no_keys = linked_split (pklist, 0, 0);
      A4GL_debug ("No of keys=%d", no_keys);
      start_bind ('i', 0);
      if (type == 'U')
	{
	  char buffer[256];
	  set_pklist (pklist);
	  sprintf (buffer, "%s.*", var);
	  push_bind_rec (buffer, 'u');
	}
      for (azcnt = 1; azcnt <= no_keys; azcnt++)
	{
	  A4GL_debug ("Getting key no %d", azcnt);
	  linked_split (pklist, azcnt, buff2);
	  sprintf (buff, "%s.%s", var, buff2);
	  A4GL_debug ("Adding linked %s", buff);
	  add_bind ('i', buff);
	  A4GL_debug (" key count %d %d\n", azcnt, no_keys);
	}
      if (type == 'S') no = LEXLIB_print_bind_definition ('o');
      ni = LEXLIB_print_bind_definition ('i');

      if (type == 'S') LEXLIB_print_bind_set_value ('o');
      LEXLIB_print_bind_set_value ('i');
	
      if (type == 'S')
	sprintf (buff, "SELECT * FROM %s WHERE ", tabname);
      if (type == 'D')
	sprintf (buff, "DELETE FROM %s WHERE ", tabname);
      if (type == 'U')
	sprintf (buff, "UPDATE %s SET (%s)=(%s) WHERE ", tabname,
		 get_upd_using_notpk (), get_upd_using_queries ());
      for (azcnt = 1; azcnt <= no_keys; azcnt++)
	{
	  if (azcnt > 1)
	    strcat (buff, "AND");
	  linked_split (pklist, azcnt, buff2);
	  strcat (buff, " ");
	  strcat (buff, buff2);
	  strcat (buff, "=? ");
	}
      if (type == 'S')
	printc
	  ("A4GLSQL_execute_implicit_select((void *)A4GLSQL_prepare_select(ibind,%d,obind,%d,\"%s\",_module_name,%d,1),1); /* 1 */",
	   ni, no, buff,lastlineno);
      if (type == 'D' || type == 'U')
	printc
	  ("A4GLSQL_execute_implicit_sql(A4GLSQL_prepare_select(ibind,%d,0,0,\"%s\",_module_name,%d,1),1);",  ni,buff,lastlineno);
      printc ("}\n");
    }
  else
    {
      return 0;
    }
  return 1;
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
  printc ("A4GL_locate_var(&%s,'%c',%s);\n", var, where, fname);
}


/* *************************** REPORT **********************/

void
LEXLIB_print_set_conn (char *conn)
{
  printc ("A4GLSQL_set_conn(%s);\n", conn);
}

/**
 * Generate the C implementation for the PUT statement for using with 
 * insert cursors.
 */
void
LEXLIB_print_put (char *cname,char *putvals)
{
  int n;
  printc ("{\n");
  LEXLIB_print_pushchar(cname);
  n = LEXLIB_print_bind_definition ('i');
  LEXLIB_print_bind_set_value ('i');
  printc ("A4GLSQL_put_insert(ibind,%d);\n", n);
  printc ("}\n");
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
LEXLIB_print_prepare (char *stmt, char *sqlvar)
{
	 if (A4GL_isyes(acl_getenv("DOING_CM"))) {
	char *p=0;
	//printf("?P : %s\n",stmt);
	//
	if (A4GL_has_pointer(sqlvar,LAST_STRING)) {
		p=A4GL_find_pointer(sqlvar,LAST_STRING);
		//printf("?p=%p",p);
	}

	if (p || sqlvar[0]=='"') {
		printf("PREPARE %s %s %s - %s\n",curr_func,stmt,sqlvar,p);
	} else {
		//extern int yylineno;
		printf("UNKNOWN_PREPARE %s.4gl %d %s %s %s\n",A4GL_compiling_module(),yylineno,curr_func,stmt,sqlvar);
	}
	if (p) {
			A4GL_del_pointer(sqlvar,LAST_STRING);
	}
	}

  	printc ("A4GLSQL_add_prepare(%s,(void *)A4GLSQL_prepare_select(0,0,0,0,%s,_module_name,%d,0));\n", stmt, sqlvar,lastlineno);
}


/**
 * The parser found a EXECUTE 4gl statement and generate the C implementation in
 * the output generated file.
 *
 * @param The statement identifier.
 * @param using Flag to indicate if the statement have USING instruction:
 *   - 0 : Does not have USING
 *   - 1 : EXECUTE have USING
 */
void
LEXLIB_print_execute (char *stmt, int using)
{
  int ni;
  int no;
  if (using == 0) {printc ("A4GLSQL_execute_sql(%s,0,0);\n", stmt);}

  if (using==1) {
      printc ("{\n");
      ni = LEXLIB_print_bind_definition ('i');
      LEXLIB_print_bind_set_value ('i');
      printc ("A4GLSQL_execute_sql(%s,%d,ibind);\n", stmt, ni);
      printc ("}\n");
    }

  if (using==2) {
      printc ("{\n");
      printc("void *_save_bind_ptr;");
      printc("int   _save_bind_cnt;");
      no = LEXLIB_print_bind_definition ('o');
      LEXLIB_print_bind_set_value ('o');
      printc ("A4GLSQL_swap_bind_stmt(%s,'o',&_save_bind_ptr,&_save_bind_cnt,obind,%d);",stmt,no);
      printc ("A4GLSQL_execute_implicit_select(A4GLSQL_find_prepare(%s),0); /* 2 */\n", stmt);
      printc ("A4GLSQL_swap_bind_stmt(%s,'o',0,0,_save_bind_ptr,_save_bind_cnt);",stmt);
      printc ("}\n");
    }

  if (using==3) {
      printc ("{\n");
      printc("void *_osave_bind_ptr;");
      printc("int   _osave_bind_cnt;");
      printc("void *_isave_bind_ptr;");
      printc("int   _isave_bind_cnt;");
      no = LEXLIB_print_bind_definition ('o');
      ni = LEXLIB_print_bind_definition ('i');
      LEXLIB_print_bind_set_value ('o');
      LEXLIB_print_bind_set_value ('i');
      printc ("A4GLSQL_swap_bind_stmt(%s,'o',&_osave_bind_ptr,&_osave_bind_cnt,obind,%d);",stmt,no);
      printc ("A4GLSQL_swap_bind_stmt(%s,'i',&_isave_bind_ptr,&_isave_bind_cnt,ibind,%d);",stmt,ni);
      printc ("A4GLSQL_execute_implicit_select(A4GLSQL_find_prepare(%s),0); /* 3 */\n", stmt);
      printc ("A4GLSQL_swap_bind_stmt(%s,'o',0,0,_osave_bind_ptr,_osave_bind_cnt);",stmt);
      printc ("A4GLSQL_swap_bind_stmt(%s,'i',0,0,_isave_bind_ptr,_isave_bind_cnt);",stmt);
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
  printc ("A4GLSQL_init_session(%s", s);
  if (strcmp (user, "?") == 0)
    {
      printc (",A4GL_char_pop(),%s);\n", user);
    }
  else
    {
      printc (",\"%s\",%s);\n", v, user);
    }
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
LEXLIB_print_open_cursor (char *cname, int has_using)
{
   if (has_using) {
	int ni;
      	printc ("{\n");
      	ni = LEXLIB_print_bind_definition ('i');
      	LEXLIB_print_bind_set_value ('i');
  	printc ("A4GLSQL_open_cursor(%s,%d,ibind);\n", cname,ni);
  	printc("}");
	/*
	A4GL_prchkerr (lastlineno, infilename); // line number, file name should be provided
				// to A4GL_prchkerr, but where to get them from?
	*/
  } else {
  	printc ("A4GLSQL_open_cursor(%s,0,0);\n",  cname);
	/*
	A4GL_prchkerr (lastlineno, infilename); // line number, file name should be provided
				// to A4GL_prchkerr, but where to get them from?
	*/
  }
}

void
LEXLIB_print_sql_commit (int t)
{
  printc ("A4GLSQL_commit_rollback(%d);\n", t);
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
LEXLIB_print_fetch_3 (struct s_fetch *fp, char *into)
{
  struct expr_str *e;
char buff[200];
e=fp->fp->fetch_expr;
  if (e) {
	if (e->expr_type==ET_EXPR_LITERAL_LONG) {
		sprintf(buff,"%ld",e->u_data.expr_long);
	} else {
		LEXLIB_print_expr(e);
		sprintf(buff,"A4GL_pop_long()");
	}
  }
  printc ("A4GLSQL_fetch_cursor(%s,%d,%s,%s);}\n}\n", fp->cname,fp->fp->ab_rel, buff,into);
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
  if (db == 0)
    printc ("A4GLSQL_init_connection(A4GL_char_pop());\n");
  else
    printc ("A4GLSQL_init_connection(\"%s\");\n", db);
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
LEXLIB_print_do_select (char *s,int converted)
{
if (strstr(s," INTO TEMP ")==0) {
  printc ("A4GLSQL_execute_implicit_select(%s,1); /* 0 */\n}\n", s);
} else {
  printc ("A4GLSQL_execute_implicit_sql(%s,1); /* 0 */\n}\n", s);
}
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
  printc ("A4GLSQL_flush_cursor(%s);\n\n", s);
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
 *   - " ", "column,column" : The cursor is for update. (column list not handled in this mode..)
 *   - "" : The cursor is NOT for update.
 * @param a2 The cursor specification generated struct s_sid variable name.
 * @param a3 The cursor name.
 * @param h1 Flag to indicate if the cursor is with hold.
 *   - 0 :
 *   - 2 :
 * @param h2 Flag that indicate if the cursor is with scroll:
 *   - 0 : The cursor its not with scroll
 *   - 1 : The cursor is with scroll
 */
void
LEXLIB_print_declare (char *sa1, char *a2, char *a3, int h1, int h2)
{
  int a1;
  if (strlen(sa1)) a1=1; 
  else a1=0;
  printc ("A4GLSQL_declare_cursor(%d+%d,%s,%d,%s);\n}\n", a1, h1, a2, h2, a3);
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
LEXLIB_print_curr_spec (int type, char *s)
{
  static char buff[3000];
  int ni;
  int no;
  int bt;

	extern int obindcnt,ibindcnt;
  printc ("{\n");
  if (type == 1) {
		bt=0;
		ni=ibindcnt;
		no=obindcnt;
		if (obindcnt) {bt++;LEXLIB_print_bind_definition('o');}
		if (ibindcnt) {bt+=2;LEXLIB_print_bind_definition('i');}
		if (obindcnt) {LEXLIB_print_bind_set_value('o');}
		if (ibindcnt) {LEXLIB_print_bind_set_value('i');}
		
		switch(bt) {
    		case 0: sprintf (buff, "A4GLSQL_prepare_select(0,0,0,0,\"%s\",_module_name,%d,0)", s,lastlineno);break;
   		case 1: sprintf (buff, "A4GLSQL_prepare_select(0,0,obind,%d,\"%s\",_module_name,%d,0)", no,s,lastlineno); break;
    		case 2: sprintf (buff, "A4GLSQL_prepare_select(ibind,%d,0,0,\"%s\",_module_name,%d,0)", ni,s,lastlineno); break;
    		case 3: sprintf (buff, "A4GLSQL_prepare_select(ibind,%d,obind,%d,\"%s\",_module_name,%d,0)", no,ni,s,lastlineno); break;
		}
  }
  if (type == 2)
    sprintf (buff, "A4GLSQL_find_prepare(%s)", s);
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
LEXLIB_print_select_all (char *buff,int converted)
{
  int ni, no;
  static char b2[20000];
  int os;
  printc ("{\n");
  ni = LEXLIB_print_bind_definition ('i');
  no = LEXLIB_print_bind_definition ('o');
  LEXLIB_print_bind_set_value ('i');
  LEXLIB_print_bind_set_value ('o');
  os=snprintf (b2, sizeof(b2),"A4GLSQL_prepare_select(ibind,%d,obind,%d,\"%s\",_module_name,%d,%d)", ni, no, buff,lastlineno,converted);
  if (os>=sizeof(b2)) {
		A4GL_debug("print_select_all failed");
		a4gl_yyerror("Internal error - string too long\n");
		exit(2);
	}
  return b2;
}


/**
 * Print in the generated C output file the implementation of the UNLOAD
 * 4gl statement.
 *
 * Called when the parser found the UNLOAD statement inthe 4gl source code.
 *
 * Here just calls the library function tal implements the real unload
 * (A4GLSQL_Unload_data()).
 *
 * @param file The file name where the load will be to.
 * @param delim The delimiter between columns to generate.
 * @param sql The SQL that originate the unload data.
 */
void
LEXLIB_print_unload (char *file, char *delim, char *sql)
{
  int ni;
  //static char b2[20000];
  //int os;
  int isvar=-1;
  printc ("{\n");
  ni = LEXLIB_print_bind_definition ('i');
  LEXLIB_print_bind_set_value ('i');

if (strncmp(sql,"SELECT ",7)==0) isvar=0;

if (isvar==-1) {
	if (scan_variable (sql) == -1) isvar=0; else isvar=1;
}

if (isvar==0) {
  printc ("A4GLSQL_unload_data(%s,%s, /*1*/ \"%s\" /*2*/,%d,ibind,0);\n", file, delim, sql,ni);
} else {
  printc ("A4GLSQL_unload_data(%s,%s, /*1*/ %s /*2*/,%d,ibind,0);\n", file, delim, sql,ni);
}
 printc("}");

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
  printc ("A4GLSQL_load_data(%s,%s,\"%s\",%s);\n", file, delim, tab, list);
}


void
LEXLIB_print_load_str (char *file, char *delim, char *sql)
{
  printc ("A4GLSQL_load_data_str(%s,%s,%s);\n", file, delim, sql);
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
  printc ("{char _sav_cur_conn[32];\n");
  printc ("strcpy(_sav_cur_conn,A4GLSQL_get_curr_conn());\n");
  printc ("A4GLSQL_set_conn(%s);\n", sess);
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
  return "A4GLSQL_set_conn(_sav_cur_conn);}";
}

void
LEXLIB_print_sql_block_cmd (char *s)
{
int u=0;
static int sqlblock=0;
char tmpbuff[256];
  if (get_bind_cnt('o')) u+=2;
  if (get_bind_cnt('i')) u+=1;
  sprintf(tmpbuff,"\"A4GLsb_%d%d\"",sqlblock++,yylineno);
  printc("A4GLSQL_add_prepare(%s,(void *)A4GLSQL_prepare_select(0,0,0,0,\"%s\",_module_name,%d,%d));",tmpbuff,trans_quote(s),lastlineno,0 /* never converted */);
  LEXLIB_print_execute(tmpbuff,u);
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
  printcomment ("/* end of foreach while loop */\n");


  /*
  printc("}");
  printc ("}\n");
  */
}




char *LEXLIB_get_column_transform(char *s) {
return s;
}



void print_report_table(char *repname,char type, int c) {
/* We don't need repname here - but the ESQL/C version does.. */
if (type=='R')
  printc ("A4GL_add_row_report_table (_rbind,%d);",c);

if (type=='F') 
  printc ("        while (A4GL_report_table_fetch(reread,%d,_rbind)) {",c);

if (type=='I')
  printc ("        A4GL_init_report_table(_rbind,%d,_ordbind,sizeof(_ordbind)/sizeof(struct BINDING),&reread);\n", c);

if (type=='E') 
  printc ("        A4GL_end_report_table(_rbind,%d,reread);",c);
if (type=='M')
  printc ("       A4GL_make_report_table(_rbind,%d);",c);

}

void LEXLIB_A4GL_add_put_string(char *s) {
static int put_string_no=0;
char buff[80];
if (strcmp(s,"?")==0) return;
if (s[0]=='\'') {
	char *ptr;
	ptr=strdup(&s[1]);
	ptr[strlen(ptr)-1]=0;
	sprintf(buff,"a4gl_putstr_%d",put_string_no);
	printh("static char %s[]=\"%s\";\n",buff,ptr);
	liblex_add_ibind(0+(strlen(ptr)<<16),buff);
	free(ptr);
	strcpy(s,"?");
}

}



#ifdef OBSOLETE

void *LEXLIB_get_in_exists_sql(char *sql, char type) {
char buff[2048];
int n;
void *ptr;
char *x;
	x=acl_malloc2(strlen(sql)+255);
	sprintf(x,"A4GL_push_char(\"%s\");",sql);
        ptr=A4GL_new_expr(x);
	
        A4GL_append_expr(ptr,"{");
        n=print_bind_expr(ptr,'i');
        sprintf(buff,"A4GL_push_binding(ibind,%d);}",n);
        A4GL_append_expr(ptr,buff);
	if (type=='E') A4GL_append_expr(ptr,"A4GL_pushop(OP_EXISTS);");
	if (type=='e') A4GL_append_expr(ptr,"A4GL_pushop(OP_NOTEXISTS);");
 	if (type=='I') A4GL_append_expr(ptr,"A4GL_pushop(OP_IN_SELECT);");
 	if (type=='i') A4GL_append_expr(ptr,"A4GL_pushop(OP_NOTIN_SELECT);");
	free(x);
	return ptr;
}

#endif

void print_exists_subquery(int i, struct expr_exists_sq *e) {
	int n;
	printc("A4GL_push_char(\"%s\");",e->subquery);
	printc("{");
	n=e->nibind;
	LEXLIB_print_bind('i');
        printc("A4GL_push_binding(ibind,%d);",n);
	if (i) printc("A4GL_pushop(OP_EXISTS);");
	else   printc("A4GL_pushop(OP_NOTEXISTS);");
	printc("}");
}

void print_in_subquery(int i, struct expr_in_sq *e) {
	int n;
	LEXLIB_print_expr(e->expr);
	printc("A4GL_push_char(\"%s\");",e->subquery);
	printc("{");
	n=e->nibind;
	LEXLIB_print_bind('i');
        printc("A4GL_push_binding(ibind,%d);",n);
 	if (i) printc("A4GL_pushop(OP_IN_SELECT);");
	else   printc("A4GL_pushop(OP_NOTIN_SELECT);");
	printc("}");
}

static char *
trans_quote (char *s)
{
static char buff[64000];
  int c;
  int a;
  c = 0;
  for (a = 0; a < strlen (s); a++)
    {
      if (s[a] == '"')
        {
          buff[c++] = '\\';
        }
      buff[c++] = s[a];
      buff[c] = 0;
    }
  return buff;
}


/**
 *  *
 *   * @todo Describe function
 *    */
int
doing_esql (void)
{
	    return 0;
}



/*
int LEXLIB_compile_time_convert(void) {
	        return 0;
}
*/


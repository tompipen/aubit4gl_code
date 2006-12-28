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
# $Id: compile_c_sql.c,v 1.78 2006-12-28 13:10:20 gyver309 Exp $
#
*/

#include "a4gl_lib_lex_esqlc_int.h"
void printc (char *fmt, ...);
void printcomment (char *fmt, ...);
#ifndef lint
	static char const module_id[] =
		"$Id: compile_c_sql.c,v 1.78 2006-12-28 13:10:20 gyver309 Exp $";
#endif


void print_report_table(char *repname,char type, int c,char *asc_desc,t_binding_comp_list *funcbind);
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
LEXLIB_print_exec_sql_bound_g (char *s,int converted,t_binding_comp_list* bind)
{
  int c;
  printc ("{\n");
  c = LEXLIB_print_bind_definition_g (bind);
  LEXLIB_print_bind_set_value_g (bind);
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
LEXLIB_print_foreach_next_g (char *cursorname, t_binding_comp_list  *using_bind, t_binding_comp_list *into_bind)
{
  int ni;
  printc ("A4GLSQL_set_sqlca_sqlcode(0);\n");
  LEXLIB_print_open_cursor_g(cursorname,using_bind);

  printc ("if (a4gl_sqlca.sqlcode!=0) {");
  exit_loop("FOREACH");
    printc("}");

  printc("_cursoropen=1;");
  printc ("while (1) {\n");
  ni = LEXLIB_print_bind_definition_g (into_bind);
  LEXLIB_print_bind_set_value_g(into_bind);
  printc ("A4GLSQL_fetch_cursor(%s,%d,1,%d,obind); /* Foreach next */\n", cursorname, FETCH_RELATIVE, ni);
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
LEXLIB_print_put_g (char *cname,char *putvals,t_binding_comp_list* bind)
{
  int n;
  /* pascal_v: switch order of LEXLIB_print_pushchar(cname) and printc ("{\n")
    because the resulting code does not compile */
  LEXLIB_print_pushchar(cname);
  printc ("{\n");
  n = LEXLIB_print_bind_definition_g (bind);
  LEXLIB_print_bind_set_value_g (bind);
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
  if (A4GL_isyes (acl_getenv ("DOING_CM")))
    {
      char *p = 0;
      if (A4GL_has_pointer (sqlvar, LAST_STRING))
        {
          p = A4GL_find_pointer (sqlvar, LAST_STRING);
        }

      if (p || sqlvar[0] == '"')
        {
          printf ("PREPARE %s %s %s - %s\n", curr_func, stmt, sqlvar, p);
          A4GLSQLCV_convert_sql_ml ("INFORMIX", A4GL_strip_quotes(sqlvar), A4GL_compiling_module (), yylineno);
        }
      else
        {
          printf ("UNKNOWN_PREPARE %s.4gl %d %s %s %s\n",
                  A4GL_compiling_module (), yylineno, curr_func, stmt,
                  sqlvar);
        }
      if (p)
        {
          A4GL_del_pointer (sqlvar, LAST_STRING);
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
LEXLIB_print_execute_g (char *stmt, int using, t_binding_comp_list* using_bind, t_binding_comp_list* into_bind)
{
  int ni;
  int no;
  if (using == 0) {printc ("A4GLSQL_execute_sql(%s,0,0);\n", stmt);}

  if (using==1) {
      printc ("{\n");
      ni = LEXLIB_print_bind_definition_g (using_bind);
      LEXLIB_print_bind_set_value_g (using_bind);
      printc ("A4GLSQL_execute_sql(%s,%d,ibind);\n", stmt, ni);
      printc ("}\n");
    }

  if (using==2) {
      printc ("{\n");
      printc("void *_save_bind_ptr;");
      printc("int   _save_bind_cnt;");
      no = LEXLIB_print_bind_definition_g (into_bind);
      LEXLIB_print_bind_set_value_g (into_bind);
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
      no = LEXLIB_print_bind_definition_g (into_bind);
      ni = LEXLIB_print_bind_definition_g (using_bind);
      LEXLIB_print_bind_set_value_g (into_bind);
      LEXLIB_print_bind_set_value_g (using_bind);
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
LEXLIB_print_open_cursor_g (char *cname, t_binding_comp_list *using_bind)
{
   if (using_bind->nbind) {
	int ni;
      	printc ("{\n");
      	ni = LEXLIB_print_bind_definition_g (using_bind);
      	LEXLIB_print_bind_set_value_g (using_bind);
  	printc ("A4GLSQL_open_cursor(%s,%d,ibind);\n", cname,ni);
  	printc("}");
//	A4GL_prchkerr (lastlineno, infilename); // where should it be placed?
  } else {
  	printc ("A4GLSQL_open_cursor(%s,0,0);\n",  cname);
//	A4GL_prchkerr (lastlineno, infilename); // where should it be placed?
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
LEXLIB_print_fetch_3_g (struct s_fetch *fp, t_binding_comp_list *bind)
{
  struct expr_str *e;
char buff[200];
  e=fp->fp->fetch_expr;

  if (e) {
	if (e->expr_type==ET_EXPR_LITERAL_LONG) {
		SPRINTF1(buff,"%ld",e->u_data.expr_long);
	} else {
		LEXLIB_print_expr(e);
		SPRINTF0(buff,"A4GL_pop_long()");
	}
  }

  if (bind->nbind==0) {
  		printc ("A4GLSQL_fetch_cursor(%s,%d,%s,0,0); /* No bind */", fp->cname,fp->fp->ab_rel, buff);
  } else {
  		printc ("A4GLSQL_fetch_cursor(%s,%d,%s,%d,obind);", fp->cname,fp->fp->ab_rel, buff,bind->nbind);
  }

  printc("}\n}\n");
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
LEXLIB_print_init_conn (struct expr_str *db,char *exclusive)
{

printc("{char *_s; ");
        LEXLIB_print_expr(db);
	printc("_s=A4GL_char_pop();A4GL_trim(_s);");
    printc ("A4GLSQL_init_connection(_s);");
    printc("free(_s);}\n");
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
LEXLIB_print_do_select (char *s,int converted,t_binding_comp_list *outbind)
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
LEXLIB_print_declare_g (char *sa1, char *a2, char *a3, int h1, int h2,t_binding_comp_list *inbind, t_binding_comp_list *outbind)
{
  int a1;

  //A4GL_add_pointer(A4GL_strip_quotes(a3),CURCODE,(void *)1);

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
LEXLIB_print_curr_spec_g (int type, char *s, t_binding_comp_list *inbind, t_binding_comp_list *outbind)
{
  static char buff[3000];
  int ni;
  int no;
  int bt;

	//extern int obindcnt,ibindcnt;
  printc ("{\n");
  if (type == 1) {
		bt=0;
		ni=inbind->nbind;
		no=outbind->nbind;
		if (no) {bt++;LEXLIB_print_bind_definition_g(outbind);}
		if (ni) {bt+=2;LEXLIB_print_bind_definition_g(inbind);}
		if (no) {LEXLIB_print_bind_set_value_g(outbind);}
		if (ni) {LEXLIB_print_bind_set_value_g(inbind);}

		A4GL_assertion(no,"DIDNT THINK THIS HAPPEND");

		switch(bt) {
    		case 0: SPRINTF2 (buff, "A4GLSQL_prepare_select(0,0,0,0,\"%s\",_module_name,%d,0)", s,lastlineno);break;
   		case 1: SPRINTF3 (buff, "A4GLSQL_prepare_select(0,0,obind,%d,\"%s\",_module_name,%d,0)", no,s,lastlineno); break;
    		case 2: SPRINTF3 (buff, "A4GLSQL_prepare_select(ibind,%d,0,0,\"%s\",_module_name,%d,0)", ni,s,lastlineno); break;
    		case 3: SPRINTF4 (buff, "A4GLSQL_prepare_select(ibind,%d,obind,%d,\"%s\",_module_name,%d,0)", no,ni,s,lastlineno); break;
		}
  }

  if (type == 2) SPRINTF1 (buff, "A4GLSQL_find_prepare(%s)", s);

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
LEXLIB_print_select_all_g (char *buff,int converted,t_binding_comp_list *inbind, t_binding_comp_list *outbind,int used_with_declare)
{
  int ni, no;
  static char b2[20000];
  int os;
  printc ("{\n");
  ni = LEXLIB_print_bind_definition_g (inbind);
  no = LEXLIB_print_bind_definition_g (outbind);
  LEXLIB_print_bind_set_value_g (inbind);
  LEXLIB_print_bind_set_value_g(outbind);
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
LEXLIB_print_unload_g (char *file, char *delim, char *sql, t_binding_comp_list* inbind)
{
  int ni;
  //static char b2[20000];
  //int os;
  int isvar=-1;
  printc ("{\n");
  ni = LEXLIB_print_bind_definition_g (inbind);
  LEXLIB_print_bind_set_value_g (inbind);

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
LEXLIB_print_sql_block_cmd_g (char *s,t_binding_comp_list *inbind, t_binding_comp_list *outbind)
{
int u=0;
static int sqlblock=0;
char tmpbuff[256];
  if (outbind->nbind) u+=2;
  if (inbind->nbind)  u+=1;
  SPRINTF2(tmpbuff,"\"A4GLsb_%d%d\"",sqlblock++,yylineno);
  printc("A4GLSQL_add_prepare(%s,(void *)A4GLSQL_prepare_select(0,0,0,0,\"%s\",_module_name,%d,%d));",tmpbuff,trans_quote(s),lastlineno,0 /* never converted */);
  LEXLIB_print_execute_g(tmpbuff,u,inbind,outbind);
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



void print_report_table(char *repname,char type, int c,char *asc_desc,t_binding_comp_list *funcbind) {
/* We don't need repname here - but the ESQL/C version does.. */
if (type=='R')
  printc ("A4GL_add_row_report_table (_rbind,%d);",c);

if (type=='F')
  printc ("        while (A4GL_report_table_fetch(reread,%d,_rbind)) {",c);

if (type=='I')
  printc ("        A4GL_init_report_table(_rbind,%d,_ordbind,sizeof(_ordbind)/sizeof(struct BINDING),&reread,\"%s\");\n", c,asc_desc);

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
	SPRINTF1(buff,"a4gl_putstr_%d",put_string_no);
	printh("static char %s[]=\"%s\";\n",buff,ptr);
	llex_add_ibind(0+(strlen(ptr)<<16),buff);
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
	SPRINTF1(x,"A4GL_push_char(\"%s\");",sql);
        ptr=A4GL_new_expr(x);

        A4GL_append_expr(ptr,"{");
        n=print_bind_expr(ptr,'i');
        SPRINTF1(buff,"A4GL_push_binding(ibind,%d);}",n);
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
	t_binding_comp_list l;
	printc("A4GL_push_char(\"%s\");",e->subquery);
	printc("{");
	n=e->nibind;

	l.bind=e->ibind;
	l.nbind=e->nibind;
	l.type='i';
	LEXLIB_print_bind_definition_g (&l);
	LEXLIB_print_bind_set_value_g(&l);

        printc("A4GL_push_binding(ibind,%d);",n);
	if (i) printc("A4GL_pushop(OP_EXISTS);");
	else   printc("A4GL_pushop(OP_NOTEXISTS);");
	printc("}");
}

void print_in_subquery(int i, struct expr_in_sq *e) {
	int n;
	t_binding_comp_list l;
	LEXLIB_print_expr(e->expr);
	printc("A4GL_push_char(\"%s\");",e->subquery);
	printc("{");
	n=e->nibind;

	//LEXLIB_print_bind('i');

	l.bind=e->ibind;
	l.nbind=e->nibind;
	l.type='i';
	LEXLIB_print_bind_definition_g (&l);
	LEXLIB_print_bind_set_value_g(&l);

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


#include "a4gl_lib_lex_esqlc_int.h"

/**
 * Print the C implementation of the execution of the SQL statement allready
 * readed.
 *
 * @param The string with the sql statement to be executed.
 */
void
print_exec_sql (char *s)
{

  printc
    ("EXEC SQL %s; /* exec_sql */\n", s);
  print_copy_status();
}


/**
 * @todo Desribe
 *
 *
 * @param
 */
void
print_exec_sql_bound (char *s)
{
  int c;
  printc ("{/* Start exec_sql_bound */\n");
  c = print_bind ('i');
  printc("/* printed bind - print conversions */");
  print_conversions('i');
  printc ("EXEC SQL %s; /* exec_sql_bound */\n", s);
  print_copy_status();
  printc ("}\n");
}

void
print_close (char type, char *name)
{
  switch (type)
    {
    case 'F':
      printc ("close_form(%s);\n", name);
      break;
    case 'W':
      printc ("remove_window(%s);\n", name);
      break;
    case 'D':
      printc ("close_database();\n");
      break;
    case 'S':
      printc ("EXEC SQL CLOSE SESSION %s;\n", name);
  print_copy_status();
      break;
    case 'C':
      printc ("EXEC SQL CLOSE CURSOR %s;\n", name);
  print_copy_status();
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
print_foreach_next (char *cursorname, char *into)
{
  int ni;
  int no;
  printc ("sqlca.sqlcode=0;\n");
  printc ("\nEXEC SQL OPEN  %s; /* into=%s */\n", strip_quotes(cursorname),into);
  print_copy_status();
  printc ("while (1) {\n");
  ni = print_bind ('i');
  no = print_bind ('o');
  print_conversions('i');
  printc ("\nEXEC SQL FETCH %s %s; /*foreach ni=%d no=%d*/\n",strip_quotes(cursorname),get_into_part(no),ni,no);
  print_copy_status();
  print_conversions('o');

  printc ("if (sqlca.sqlcode<0||sqlca.sqlcode==100) break;\n");
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
print_free_cursor (char *s)
{
  printc ("EXEC SQL FREE CURSOR %s\n",s);
  print_copy_status();
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
print_linked_cmd (int type, char *var)
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

      debug ("Finding number of keys...\n");
      no_keys = linked_split (pklist, 0, 0);
      debug ("No of keys=%d", no_keys);
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
	  debug ("Getting key no %d", azcnt);
	  linked_split (pklist, azcnt, buff2);
	  sprintf (buff, "%s.%s", var, buff2);
	  debug ("Adding linked %s", buff);
	  add_bind ('i', buff);
	  debug (" key count %d %d\n", azcnt, no_keys);
	}
      if (type == 'S')
	no = print_bind ('o');

      ni = print_bind ('i');
  	print_conversions('i');


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

      if (type == 'S') {
	printc ("EXEC SQL %s; /* linked - S */",buff);
  print_copy_status();
      }

      if (type == 'D' || type == 'U') {
	printc ("EXEC SQL %s; /* linked - D/U */", buff);
  print_copy_status();
      }

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
print_locate (char where, char *var, char *fname)
{
  printc ("locate_var(&%s,'%c',%s);  /* FIXME */\n", var, where, fname);
}


/* *************************** REPORT **********************/

void
print_set_conn (char *conn)
{
  printc ("EXEC SQL SET CONNECTION TO %s;\n", conn);
  print_copy_status();
}

/**
 * Generate the C implementation for the PUT statement for using with 
 * insert cursors.
 */
void
print_put (void)
{
  int n;
  printc ("{\n");
  n = print_bind ('i');
  print_conversions('i');
  printc ("EXEC SQL PUT /*FIXME - cursorname ? */\n", n);
  print_copy_status();
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
print_prepare (char *stmt, char *sqlvar)
{
  printc("{\n");
  printc("EXEC SQL BEGIN DECLARE SECTION;\n");
  printc("char *_s;\n");
  printc("EXEC SQL END DECLARE SECTION;\n");
  printc("_s=strdup(%s);\n",sqlvar);
  printc ("EXEC SQL PREPARE %s FROM $_s;\n", strip_quotes(stmt), sqlvar);

  printc("free(_s);\n}\n");
  print_copy_status();
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
print_execute (char *stmt, int using)
{
  int ni;
  if (using == 0) {
    printc ("EXEC SQL %s\n", stmt);
  print_copy_status();
  }
  else
    {
      printc ("{ /* EXECUTE */\n");
      ni = print_bind ('i');
print_conversions('i');
      printc ("EXEC SQL %s; /* Execute */\n", stmt);
  print_copy_status();
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
print_open_session (char *s, char *v, char *user)
{

  printc ("EXEC SQL OPEN SESSION %s", s);
  print_copy_status();


  if (strcmp (user, "?") == 0)
    {
      printc (",char_pop(),%s);\n", user);
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
print_open_cursor (char *cname, char *using)
{
  printc ("\nEXEC SQL OPEN  %s USING %s;\n",  strip_quotes(cname),using);
  print_copy_status();
}

void
print_sql_commit (int t)
{
	if (t==-1) printc ("EXEC SQL BEGIN WORK;\n", t);
	if (t==0) printc ("EXEC SQL ROLLBACK WORK;\n", t);
	if (t==1) printc ("EXEC SQL COMMIT WORK;\n", t);
  print_copy_status();
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
print_fetch_3 (char *ftp, char *into)
{
  printc("/* ftp=%s into=%s */\n",ftp,into);
  printc ("\nEXEC SQL FETCH  %s INTO %s; /*fetch3*/\n", strip_quotes(ftp), into);
  print_copy_status();
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
print_init_conn (char *db)
{

  if (db == 0) {
    printc ("{EXEC SQL BEGIN DECLARE SECTION;\n");
    printc ("char *s;s=char_pop();\n");
    printc ("EXEC SQL CONNECT TO :s AS 'default';\n");
  }
  else
    printc ("EXEC SQL CONNECT TO \"%s\" AS 'default';\n",db);
  print_copy_status();
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
print_do_select (char *s)
{
  printc ("EXEC SQL %s;\n/* do_select */", s);
  print_copy_status();
  print_conversions('o');
  printc("}\n");
}

/**
 * Print in the generated C file the implementation of the FLUSH 4gl statement.
 *
 * Called by the parser when it founds that statement.
 *
 * @param s The cursor name.
 */
void
print_flush_cursor (char *s)
{
  printc ("EXEC SQL FLUSH CURSOR %s;\n", s);
  print_copy_status();
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
 *   - 0 :
 *   - 2 :
 * @param h2 Flag that indicate if the cursor is with scroll:
 *   - 0 : The cursor its not with scroll
 *   - 1 : The cursor is with scroll
 */
void
print_declare (char *a1, char *a2, char *a3, int h1, int h2)
{
  printc ("/* %s+%d,%s,%d,%s */\n", a1, h1, a2, h2, a3);
  printc(" /* nibind=%d a2=%s*/\n",get_bind_cnt('i'),a2);
  printc(" /* nobind=%d a3=%s */\n",get_bind_cnt('o'),a3);

  if (strstr(a2,"INTO $")!=0) {
	  	yyerror("ESQL lexer cannot handle DECLARE .. INTO at present, put the INTO on the FETCH/FOREACH instead...");
		return;
  }
  if (a2[0]=='"') {
	  	printc("{");
}
  printc ("EXEC SQL DECLARE %s",strip_quotes(a3));
  printc(" CURSOR FOR %s;\n",strip_quotes(a2));

  print_copy_status();
  printc ("}\n");

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
print_curr_spec (int type, char *s)
{
  static char buff[3000];

  if (type == 1)
    sprintf (buff, "%s", s);

  if (type == 2)
    sprintf (buff, "%s", s);

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
print_select_all (char *buff)
{
  int ni, no;
  static char b2[2000];
  printc ("{ /* print_select_all */\n");
  ni = print_bind ('i');
  no = print_bind ('o');
  print_conversions('i');
  sprintf (b2, "%s ",  buff);
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
print_unload (char *file, char *delim, char *sql)
{

  //printc ("A4GLSQL_unload_data(%s,%s, /*1*/ \"%s\" /*2*/);\n", file, delim, sql);
  printc ("/* UNLOAD NOT IMPLEMENTED YET */");
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
print_load (char *file, char *delim, char *tab, char *list)
{
  //printc ("A4GLSQL_load_data(%s,%s,\"%s\",%s);\n", file, delim, tab, list);
  printc("/* LOAD NOT IMPLEMENTED YET */");
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
print_use_session (char *sess)
{
  //printc ("{char _sav_cur_conn[32];\n");
  //printc ("strcpy(_sav_cur_conn,A4GLSQL_get_curr_conn());\n");
  //printc ("A4GLSQL_set_conn(%s);\n", sess);
  printc("/* USE NOT IMPLEMENTED FOR ESQL/C */");
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
get_undo_use (void)
{
  //return "A4GLSQL_set_conn(_sav_cur_conn);}";
  return "";
}


static void print_copy_status() {
	printc("A4GLSQL_set_status(sqlca.sqlcode,1);");
}

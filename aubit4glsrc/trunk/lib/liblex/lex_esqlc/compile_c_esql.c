/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-1 Aubit Development Team (See Credits file)       |
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
# $Id: compile_c_esql.c,v 1.60 2003-12-04 19:06:12 mikeaubury Exp $
# @TODO - Remove rep_cond & rep_cond_expr from everywhere and replace
# with struct expr_str equivalent
*/

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

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

int last_ni;
int last_no;


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

void 		printcomment 	(char *fmt, ...);
int 		esql_type 		(void);
extern void printh 			(char *fmt, ...);
void 		printc 			(char *fmt, ...);
static void print_copy_status (void);
void 		print_conversions (char i);
void print_report_table(char *repname,char type, int c) ;


char * A4GL_mk_temp_tab (struct BINDING *b, int n);
/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * Print the C implementation of the execution of the SQL statement allready
 * readed.
 *
 * @param The string with the sql statement to be executed.
 */
void
print_exec_sql (char *s)
{

  printc ("EXEC SQL %s; /* exec_sql */\n", s);
  print_copy_status ();
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
  printc ("/* printed bind - print conversions */");
  print_conversions ('i');
  printc ("EXEC SQL %s; /* exec_sql_bound */\n", s);
  print_copy_status ();
  printc ("}\n");
}

/**
 * @todo Desribe
 *
 *
 * @param
 */
void
print_close (char type, char *name)
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
	if (A4GL_isyes(acl_getenv("USE_DATABASE_STMT"))) {
      		printc ("EXEC SQL CLOSE DATABASE;\n");
	} else {
      		printc ("EXEC SQL DISCONNECT 'default';\n");
	}
      printc("if (sqlca.sqlcode==0) A4GL_esql_db_open(0);");
      print_copy_status ();
      break;
    case 'S':
      printc ("EXEC SQL CLOSE SESSION %s;\n", A4GL_strip_quotes (name));
      print_copy_status ();
      break;
    case 'C':
      printc ("EXEC SQL CLOSE %s;\n", A4GL_strip_quotes (name));
      print_copy_status ();
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
print_foreach_next (char *cursorname, char *using, char *into)
{
  int ni;
  int no;
  printc ("a4gl_sqlca.sqlcode=0;\n");


  print_open_cursor(cursorname,using);

  //printc("internal_recopy_%s_i_Dir();",A4GL_strip_quotes(cursorname));
  //printc ("\nEXEC SQL OPEN  %s; /* into=%s */\n", A4GL_strip_quotes (cursorname), into);
  //print_copy_status ();


  printc ("if (a4gl_sqlca.sqlcode==0) {\n");
  printc ("while (1) {\n");
  ni = print_bind ('i');
  no = print_bind ('o');
  print_conversions ('i');
  printc ("\nEXEC SQL FETCH %s %s; /*foreach ni=%d no=%d*/\n",
	  A4GL_strip_quotes (cursorname), A4GL_get_into_part (0,no), ni, no);
  printc("internal_recopy_%s_o_Dir();",A4GL_strip_quotes(cursorname));
  print_copy_status ();
  print_conversions ('o');

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
print_free_cursor (char *s)
{
  printc ("EXEC SQL FREE %s\n", s);
  print_copy_status ();
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
      if (type == 'S')
	no = print_bind ('o');

      ni = print_bind ('i');
      print_conversions ('i');


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
	{
	  printc ("EXEC SQL %s; /* linked - S */", buff);
	  print_copy_status ();
	}

      if (type == 'D' || type == 'U')
	{
	  printc ("EXEC SQL %s; /* linked - D/U */", buff);
	  print_copy_status ();
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

/**
 * @todo Desribe
 *
 *
 * @param
 */
void
print_set_conn (char *conn)
{
  printc ("EXEC SQL SET CONNECTION %s;\n", conn);
  print_copy_status ();
}

/**
 * Generate the C implementation for the PUT statement for using with 
 * insert cursors.
 */
void
print_put (char *cname,char *putvals)
{
  int n;
  int a;
  printc ("{\n");
  n = print_bind ('i');
  print_conversions ('i');
  printc ("EXEC SQL PUT %s /* '%s' */\n", A4GL_strip_quotes (cname),putvals);

  if (A4GL_isyes(acl_getenv("USE_BINDING_FOR_PUT"))==0) {

  	if (strlen(putvals)) {
		printc("FROM %s",putvals);
  	} 
  } else {

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
  printc ("{\n");
  printc ("EXEC SQL BEGIN DECLARE SECTION;\n");
  printc ("char *_s;\n");
  printc ("EXEC SQL END DECLARE SECTION;\n");
  printc ("_s=strdup(%s);\n", sqlvar);
  printc ("EXEC SQL PREPARE %s FROM :_s;\n", A4GL_strip_quotes (stmt), sqlvar);

  printc ("free(_s);\n}\n");
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
 */
void
print_execute (char *stmt, int using)
{
  int ni;

  if (using == 0)
    {
      printc ("EXEC SQL EXECUTE %s;\n", A4GL_strip_quotes (stmt));
      print_copy_status ();
    }
  else
    {
      int a;
      printc ("{ /* EXECUTE */\n");
      ni = print_bind ('i');
      print_conversions ('i');
      printc ("EXEC SQL EXECUTE %s USING \n", A4GL_strip_quotes (stmt));
      for (a = 0; a < ni; a++)
	{
	  if (a)
	    printc (",");
	  printc (":_vi_%d\n", a);
	}

      printc (";");
      print_copy_status ();
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



  	printc("{");
	printc("EXEC SQL BEGIN DECLARE SECTION;");
	printc("char _u[256];");
	printc("char _p[256];");
	printc("EXEC SQL END DECLARE SECTION;");
	if (strlen(user)) {
  	if (strcmp (user, "?") == 0)
    	{
		printc("strcpy(_u,A4GL_char_pop());");
    	} else {
		char buff[256];
		char *ptr;
		strcpy(buff,user);
		ptr=strchr(buff,',');
		if (ptr) {
			 *ptr=0;
			ptr++;
		}
		printc("strcpy(_u,%s);",buff);
		if (ptr) {
			printc("strcpy(_p,%s);",ptr);
		}
	}	
	}

  	printc ("EXEC SQL CONNECT TO  '%s' AS %s", v,s);
	if (strlen(user)) {
		printc("USER :_u USING :_p");
	}
	printc("/* s=%s v=%s user=%s */",s,v,user);

  printc(";");
  print_copy_status ();

  printc("}");
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
  int n;
  int a;


  n = atoi (using);
  if (n)
    {
      printc ("{\nEXEC SQL BEGIN DECLARE SECTION;");
      for (a = n - 1; a >= 0; a--)
	{
	  printc ("char *_using_%d;", a);
	}
      printc ("EXEC SQL END DECLARE SECTION;");

      for (a = n - 1; a >= 0; a--)
	{
	  printc ("_using_%d=A4GL_char_pop();A4GL_trim(_using_%d);\n", a,a);
	}

      printc("internal_recopy_%s_i_Dir();",A4GL_strip_quotes(cname));
      printc ("\nEXEC SQL OPEN  %s USING /* %d variables */",
	      A4GL_strip_quotes (cname), n);
      for (a = 0; a < n; a++)
	{
	  if (a)
	    printc (",");
	  printc (":_using_%d\n", a);
	}

      printc (";");

      for (a = n - 1; a >= 0; a--)
	{
	  printc ("free(_using_%d);\n", a);
	}
      printc ("}");
    }
  else
    {
      printc("internal_recopy_%s_i_Dir();",A4GL_strip_quotes(cname));
      printc ("\nEXEC SQL OPEN  %s; /* No using */\n", A4GL_strip_quotes (cname));
	//printc("A4GL_char_pop();");
    }
  print_copy_status ();
}

/**
 * @todo Desribe
 *
 *
 * @param
 */
void
print_sql_commit (int t)
{
  if (t == -1)
    printc ("EXEC SQL BEGIN WORK;\n", t);
  if (t == 0)
    printc ("EXEC SQL ROLLBACK WORK;\n", t);
  if (t == 1)
    printc ("EXEC SQL COMMIT WORK;\n", t);

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
print_fetch_3 (char *ftp, char *into)
{
  int fp1 = 0;
  int fp2 = 0;
  int poped = 0;
  char buff[256];
  int no;
  char cname[256];
  //printf("/* ftp=%s into=%s */\n",ftp,into);
  sscanf (into, "%d,", &no);
  //printf("no=%d\n",no);
  printc ("EXEC SQL BEGIN DECLARE SECTION;");
  printc ("int _fp;");
  printc ("EXEC SQL END DECLARE SECTION;");

  if (strstr (ftp, "pop_int") == 0)
    {
      char *ptr;
      char *ptr2;
      char sbuff[256];
      strcpy (sbuff, ftp);
      ptr = strchr (sbuff, ',');
      if (ptr == 0)
	{
	  a4gl_yyerror ("Internal Error FETCH1");
	  return;
	}
      *ptr = 0;
      strcpy (cname, sbuff);
      ptr++;

      ptr2 = strchr (ptr, ',');
      if (ptr == 0)
	{
	  a4gl_yyerror ("Internal Error FETCH2");
	  return;
	}
      *ptr2 = 0;
      fp1 = atoi (ptr);
      ptr2++;
      fp2 = atoi (ptr2);
      printc ("_fp=%d;\n", fp2);
    }
  else
    {
      char *ptr;
      char *ptr2;
      char sbuff[256];
      strcpy (sbuff, ftp);
      ptr = strchr (sbuff, ',');
      if (ptr == 0)
	{
	  a4gl_yyerror ("Internal Error FETCH3");
	  return;
	}
      *ptr = 0;
      strcpy (cname, sbuff);
      ptr++;
      ptr2 = strchr (ptr, ',');
      if (ptr == 0)
	{
	  a4gl_yyerror ("Internal Error FETCH4");
	  return;
	}
      *ptr2 = 0;
      fp1 = atoi (ptr);
      poped = 1;
      printc ("_fp=A4GL_pop_int();");
    }

  strcpy (buff, "EMPTY");

  if (poped == 0)
    {
      if (fp1 == 1)
	{			// FETCH ABSOLUTE
	  switch (fp2)
	    {
	    case 1:
	      sprintf (buff, "EXEC SQL FETCH FIRST %s ",
		       A4GL_strip_quotes (cname));
	      break;
	    case -1:
	      sprintf (buff, "EXEC SQL FETCH LAST %s ", A4GL_strip_quotes (cname));
	      break;

	    }
	}
      else
	{			// FETCH RELATIVE
	  if (fp2 != 1)
	    {
	      sprintf (buff, "EXEC SQL FETCH RELATIVE %d %s ", fp2,
		       A4GL_strip_quotes (cname));
	    }
	  else
	    {
	      sprintf (buff, "EXEC SQL FETCH %s", A4GL_strip_quotes (cname));
	    }
	}
    }
  else
    {
      if (fp1 == 1)
	{			// FETCH ABSOLUTE
	  sprintf (buff, "EXEC SQL FETCH ABSOLUTE :_fp %s",
		   A4GL_strip_quotes (cname));
	}
      else
	{
	  sprintf (buff, "EXEC SQL FETCH RELATIVE :_fp %s",
		   A4GL_strip_quotes (cname));
	}
    }

  if (strcmp (buff, "EMPTY") == 0)
    {
      a4gl_yyerror ("error calculating fetch instruction");
      return;
    }

  printc("/* ... no=%d*/",no);
  printc ("%s %s ;", buff, A4GL_get_into_part (0,no));
  if (strcmp (into, "0,0") != 0)
    {
      print_copy_status ();
      print_conversions ('o');
    }
  printc("internal_recopy_%s_o_Dir();",A4GL_strip_quotes(cname));
  printc ("}");
  printc ("}");
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

if (A4GL_isyes(acl_getenv("USE_DATABASE_STMT"))) {
  if (db == 0) {
      printc ("{");
      printc ("EXEC SQL BEGIN DECLARE SECTION;\n");
      printc ("char *s;");
      printc ("char setdb[256];");
      printc ("EXEC SQL END DECLARE SECTION;\n");
      printc ("s=A4GL_char_pop();A4GL_trim(s);");
	//printc("sprintf(setbuf,\"DATABASE %%s\");\n");
	

      //printc ("EXEC SQL PREPARE acl_p_set_db FROM $setdb;");
      //printc ("EXEC SQL EXECUTE acl_p_set_db;\n");	
	printc("EXEC SQL DATABASE $s;\n");

      printc ("}");
  } else {
      switch (esql_type ())
	{
	case 1:
	  printc ("EXEC SQL DATABASE %s;\n", db);
	  break;
	case 2:
	  printc ("EXEC SQL DATABASE %s;\n", db);
	  break;
	}
  }
} else {
  if (db == 0)
    {
      printc ("{");
      printc ("EXEC SQL BEGIN DECLARE SECTION;\n");
      printc ("char *s;");
      printc ("EXEC SQL END DECLARE SECTION;\n");
      printc ("s=A4GL_char_pop();A4GL_trim(s);\n");
      printc ("EXEC SQL CONNECT TO $s AS 'default';\n");
      printc ("}");
    }
  else
    {
	printc("if (A4GL_esql_db_open(-1)) {");
	print_close('D',"");
      		//printc ("EXEC SQL DISCONNECT 'default';\n");
	printc("}");
      switch (esql_type ())
	{
	case 1:
	  printc ("EXEC SQL CONNECT TO \"%s\" AS 'default';\n", db);
	  break;
	case 2:
	  printc ("EXEC SQL CONNECT TO %s AS 'default';\n", db);
	  break;
	}
    }
  }

  printc("if (sqlca.sqlcode==0) A4GL_esql_db_open(1);");
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
print_do_select (char *s)
{
//int ni;
  //ni = print_bind ('i');
  //printc("/* printed bind ni=%d */",ni);
  //print_conversions('i');
  printc ("EXEC SQL %s;\n/* do_select */", s);
  print_copy_status ();
  print_conversions ('o');
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
print_flush_cursor (char *s)
{
  printc ("EXEC SQL FLUSH CURSOR %s;\n", s);
  print_copy_status ();
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
print_declare (char *a1, char *a2, char *a3, int h1, int h2)
{
char buff[256];
int intprflg=0;

  if (a2[0] == '"')
    {
      printc ("{ /* DC 0 */");
    }


  if (a2[0]=='"') { 
		start_bind('i',0); start_bind('o',0); 
		last_ni=0; 
		last_no=0; 
  		print_conversions('0');
  }


  //if (strstr (a2, "INTO $") != 0)
    //{
      //a4gl_yyerror
	//("ESQL lexer cannot handle DECLARE .. INTO at present, put the INTO on the FETCH/FOREACH instead...");
      //return;
    //}


  if (strlen (a1) && h2)
    {
      a4gl_yyerror ("Updates are not allowed on a scroll cursor");
      return;
    }

  sprintf (buff, "EXEC SQL DECLARE %s", A4GL_strip_quotes (a3));
  if (h2)
    {
      strcat (buff, " SCROLL");
    }
  strcat (buff, " CURSOR");
  if (h1 || esql_type ()==2) // All postgres cursors should be with hold
    {
      strcat (buff, " WITH HOLD");
    }

  printc ("%s FOR", buff);
  printc ("     %s ", A4GL_strip_quotes (a2));
  //if (strlen (a1))
    //{
      //printc ("     FOR UPDATE");
	//if (a1[0]!=' ') {
		//printc(" OF %s",a1);
	//}
    //}
  printc (";");
  //printc(" /* A2='%s'*/",a2);
  print_copy_status ();
  printh("static int acli_ni_%s=%d;\n",A4GL_strip_quotes(a3),last_ni);
  printh("static int acli_no_%s=%d;\n",A4GL_strip_quotes(a3),last_no);
  printh("static struct BINDING *acli_bi_%s=0;\n",A4GL_strip_quotes(a3));
  printh("static struct BINDING *acli_bo_%s=0;\n",A4GL_strip_quotes(a3));
  printh("static struct BINDING *acli_nbi_%s=0;\n",A4GL_strip_quotes(a3));
  printh("static struct BINDING *acli_nbo_%s=0;\n",A4GL_strip_quotes(a3));
  printh("static struct BINDING *acli_nboi_%s=0;\n",A4GL_strip_quotes(a3));
  //printh("#undef ibind\n#undef obind\n");
  //printh("#define ibind acli_bi_%s\n",A4GL_strip_quotes(a3));
  //printh("#define obind acli_bo_%s\n",A4GL_strip_quotes(a3));

  printh("\n\nstatic void internal_recopy_%s_i_Dir(void) {\n",A4GL_strip_quotes(a3));
  printh("struct BINDING *ibind;\n");
  printh("struct BINDING *native_binding_i;\n");
  printh("ibind=acli_bi_%s;\n",A4GL_strip_quotes(a3));
  printh("native_binding_i=acli_nbi_%s;\n",A4GL_strip_quotes(a3));
  print_conversions('I');

  printh("}\n");

  printh("\n\nstatic void internal_recopy_%s_o_Dir(void) {\n",A4GL_strip_quotes(a3));
  printh("struct BINDING *obind;\n");
  printh("struct BINDING *native_binding_o;\n");
  printh("struct BINDING *native_binding_o_ind;\n");
  printh("obind=acli_bo_%s;\n",A4GL_strip_quotes(a3));
  printh("native_binding_o=acli_nbo_%s;\n",A4GL_strip_quotes(a3));
  printh("native_binding_o_ind=acli_nboi_%s;\n",A4GL_strip_quotes(a3));
  print_conversions('O');
  printh("}\n");
  printh("\n\nstatic void internal_set_%s(struct BINDING *i,struct BINDING *o,struct BINDING *ni,struct BINDING *no,struct BINDING *noi) {\n",A4GL_strip_quotes(a3));
  printh("acli_bi_%s=i;\n",A4GL_strip_quotes(a3));
  printh("acli_bo_%s=o;\n",A4GL_strip_quotes(a3));
  printh("acli_nbi_%s=ni;\n",A4GL_strip_quotes(a3));
  printh("acli_nbo_%s=no;\n",A4GL_strip_quotes(a3));
  printh("acli_nboi_%s=noi;\n",A4GL_strip_quotes(a3));
  printh("}\n");

intprflg=0;
if (last_ni) intprflg++;
if (last_no) intprflg+=2;
printc("/* intprflg=%d last_ni=%d last_no=%d */\n",intprflg, last_ni,last_no);
if (!A4GL_isyes(acl_getenv("USE_INDICATOR")))
	sprintf(buff,"0");
else
	sprintf(buff,"native_binding_o_ind");

switch (intprflg) {
	case 3: printc("internal_set_%s(ibind,obind,native_binding_i,native_binding_o,%s);",A4GL_strip_quotes(a3),buff); break;
	case 2: printc("internal_set_%s(0,obind,0,native_binding_o,%s);",A4GL_strip_quotes(a3),buff); break;
	case 1: printc("internal_set_%s(ibind,0,native_binding_i,0,0);",A4GL_strip_quotes(a3)); break;
	case 0: printc("internal_set_%s(0,0,0,0,0);",A4GL_strip_quotes(a3)); break;
	default: printc("#error No internal_set written\n");break;
	
}

  printc("} /* DC 1*/\n"); 

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
  strcpy (buff, "");
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
  static char *b2;
  printc ("{ /* print_select_all */\n");
  ni = print_bind ('i');
  last_ni=ni;
  no = print_bind ('o');
  last_no=no;
  printc("/* SETTING last_no=%d */",last_no);
  print_conversions ('i');
  b2 = strdup (buff);
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
char filename[256];
char delim_s[256];
if (delim[0]=='"') { sprintf(delim_s,"'%s'",A4GL_strip_quotes(delim)); } else { sprintf(delim_s,":%s",delim); }

  if (A4GL_isyes(acl_getenv("ESQL_UNLOAD"))) {
	int ni;
		printc("{");
  		ni = print_bind ('i');
  		print_conversions ('i');
			if (file[0]=='"') { 
				sprintf(filename,"'%s'",A4GL_strip_quotes(file)); 
			} else { 
				sprintf(filename,":_unlfname"); 
				printc("{");
				printc("EXEC SQL BEGIN DECLARE SECTION;");
				printc("char _unlfname[512];");
				printc("EXEC SQL END DECLARE SECTION;");
				printc("strcpy(_unlfname,%s);",file);
				printc("A4GL_trim(_unlfname);");
			}

  			printc ("EXEC SQL UNLOAD TO %s DELIMITER %s %s ;",filename,delim_s,sql);

			if (file[0]!='"') { 
				printc("}");
			}

			print_copy_status ();
		printc("}");

  } else {
	int ni;
	int a;
	char *ptr;
        printc("{");
	ni=print_bind('i');
	ptr=strdup(sql);
	for (a=0;a<strlen(ptr);a++) {
		if (strncmp(&ptr[a],":_vi_",5)==0) {
			int b;
			ptr[a]='?';
			ptr[a+1]=' ';
			ptr[a+2]=' ';
			ptr[a+3]=' ';
			ptr[a+4]=' ';
			for (b=a+5;b<strlen(ptr);b++) {
				if (ptr[b]<'0'||ptr[b]>'9') {a=b-1;break;}
				ptr[b]=' ';
			}
		}
		if (ptr[a]=='\n') ptr[a]=' ';
	}
  print_conversions('i');
  	printc ("A4GLSQL_unload_data(%s,%s, \"%s\",%d,native_binding_i);\n", file, delim,ptr,ni);
	printc("}");
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
print_load (char *file, char *delim, char *tab, char *list)
{
char filename[256];
char delim_s[256];
if (delim[0]=='"') { sprintf(delim_s,"'%s'",A4GL_strip_quotes(delim)); } else { sprintf(delim_s,":%s",delim); }

  if (A4GL_isyes(acl_getenv("ESQL_UNLOAD"))) {
			if (file[0]=='"') { 
				sprintf(filename,"'%s'",A4GL_strip_quotes(file)); 
			} else {
                                sprintf(filename,":_loadfname");
                                printc("{");
                                printc("EXEC SQL BEGIN DECLARE SECTION;");
                                printc("char _loadfname[512];");
                                printc("EXEC SQL END DECLARE SECTION;");
                                printc("strcpy(_loadfname,%s);",file);
                                printc("A4GL_trim(_loadfname);");
			}

	printc ("EXEC SQL LOAD FROM %s DELIMITER %s ",filename,delim_s);


	if (strlen(list)==1) printc (" INSERT INTO %s  ;",tab);
	else {	
		char *ptr;
		char buff[100];
		int p=0;
		list[strlen(list)-2]=0;
		ptr=list;
  			printc (" INSERT INTO %s (",tab);
		while (1) {
			strcpy(buff,ptr);
			ptr=strchr(buff,',');
			if (ptr) *ptr=0;
			printc("%c%s",p?',':' ',A4GL_strip_quotes(buff));

			p++;
			if (ptr==0) break;
			ptr++;
		}
		printc(");");
			
	}
	if (file[0]!='"') {
		printc("}");
	}
  	print_copy_status ();
  } else {
  	printc ("A4GLSQL_load_data(%s,%s,\"%s\",%s);\n", file, delim, tab, list);
  }
  //printc ("/* LOAD NOT IMPLEMENTED YET */");
}

/**
 * @todo Desribe
 *
 *
 * @param
 */
void
print_load_str (char *file, char *delim, char *str)
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
print_use_session (char *sess)
{
  //printc ("{char _sav_cur_conn[32];\n");
  //printc ("strcpy(_sav_cur_conn,A4GLSQL_get_curr_conn());\n");
  //printc ("A4GLSQL_set_conn(%s);\n", sess);
  printc ("/* USE NOT IMPLEMENTED FOR ESQL/C */");
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
A4GL_get_undo_use (void)
{
  //return "A4GLSQL_set_conn(_sav_cur_conn);}";
  return "";
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
  printc ("A4GLSQL_set_status(sqlca.sqlcode,1); /* Informix Status -> A4GL */");
  printc ("A4GLSQL_set_sqlerrd(sqlca.sqlerrd[0], sqlca.sqlerrd[1], sqlca.sqlerrd[2], sqlca.sqlerrd[3], sqlca.sqlerrd[4], sqlca.sqlerrd[5]);");

}


/**
 * @todo Desribe
 *
 *
 * @param
 */
void
print_sql_block_cmd (char *s)
{
int ni;
int no;
printc("{");
  ni = print_bind ('i');
  last_ni=ni;
  no = print_bind ('o');
  last_no=no;
  print_conversions('i');
  printc ("EXEC SQL %s;", s);
  print_copy_status ();
  print_conversions ('o');
printc("}");
}

/**
 * The parser found END FOREACH.
 *
 * Prints to the generated output file the C implementation of the end of
 * this statement (that is a C block close with }).
 */
void
print_foreach_end (char *cname)
{
  printc ("}");
  printc ("}");
  printcomment ("/* end of foreach while loop */\n");
  printc ("}\n");
  //print_close('C', cname);
}


/**
 * @todo Desribe
 *
 *
 * @param
 */
char *
get_column_transform(char *s) 
{
char buff[256];
static char buff2[256];
char *ptr1;
char *ptr2;
int n,m;
int l;
if (strchr(s,'[')==0) return s;

//printf("TRANSFORM %s\n",s);
      switch (esql_type ())
	{
	case 1:
		//printf("Informix\n");
		return s; // Informix style
	  break;

	case 2:
		//printf("Postgres\n");
		strcpy(buff,s);
		ptr1=strchr(buff,'[');
		*ptr1=0;
		ptr1++;
		ptr2=strchr(ptr1,',');
		if (ptr2==0) {
			ptr2=strdup("1]");
		} else {
			 *ptr2=0;
			ptr2++;
		}
		l=strlen(ptr2);
		if (ptr2[l-1]==']') {
			ptr2[l-1]=0;
		}
		n=atoi(ptr1);
		m=atoi(ptr2);
		//printf("N=%d m=%d s=%s\n",n,m,s);
		sprintf(buff2,"substr(%s,%d,%d)",buff,n,(m-n)+1);
		return buff2;
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
      return "INTERVAL";
    }
  return "CHAR";
}


void print_report_table(char *repname,char type, int c) {

dll_import struct binding_comp fbind[];
//extern struct binding_comp fbind[];
dll_import struct binding_comp ibind[];
//extern struct binding_comp ibind[];
dll_import struct binding_comp obind[];
//extern struct binding_comp obind[];


static char iname[256];
static char cname[256];
char buff[10000];
static char reptab[64];
char tmpbuff[256];
char ins_str[10000];
static int rcnt=0;
int a;
int l_dt;
int l_sz;

sprintf(reptab,"aclfgl_%d%s",rcnt,repname);
reptab[18]=0; // Make sure its short enough...

if (type=='R') {
	// print_execute needs an ibind - we have an fbind - so we need
	// to copy it across...
	extern int ibindcnt;
	extern int fbindcnt;
	memcpy(ibind,fbind,sizeof(struct binding_comp)*c+1);
	ibindcnt=fbindcnt;
	sprintf(iname,"acl_p%s",reptab);
	iname[18]=0;
	print_execute(iname,1);
}

if (type=='F') {
	extern int obindcnt;
	extern int fbindcnt;
	char buff[256];
        char buff2[256];
	memcpy(obind,fbind,sizeof(struct binding_comp)*c+1);
	obindcnt=fbindcnt;
	printc ("        while (1) {");
	print_fetch_1();
	print_fetch_2();
	printc("/* MJAMJA - printing obind */");
	print_bind('o');
	sprintf(buff,"\"%s\",FETCH_RELATIVE,1",cname);
	sprintf(buff2,"%d,rbind",c);
	print_fetch_3(buff,buff2);
	printc("if (sqlca.sqlcode!=0) break;");
        printc("A4GL_push_params (rbind, %d);",c);

}

if (type=='I') {
	extern int current_ordbindcnt;
	extern int fbindcnt;
	extern struct binding_comp ordbind[];
	char sql[1024];
	int a;
	int b;
	char *p;
	// We need to
	//    1.  Generate the SQL including our order by
	//    2.  declare a cursor for it
	//    3.  open that cursor
		sprintf(cname,"acl_c%s",reptab);
		cname[18]=0;

  		sprintf (sql, "SELECT * FROM %s ORDER BY ", reptab);
		for (a=0;a<current_ordbindcnt;a++) {
			int found=0;
			if (a) strcat(sql,",");

			for (b=0;b<fbindcnt;b++) {
				if (strcmp(ordbind[a].varname,fbind[b].varname)==0) {
					char tmpbuff[256];
					sprintf(tmpbuff,"c%d",b);
					strcat(sql,tmpbuff);
					found=1;
					break;
				}
			}
			if (found==0) {
				a4gl_yyerror("Could not find variable for order by in report");
				return;
			}
		}


		start_bind('i',0);
		start_bind('o',0);
		//printc("{ /* RT0 */");
		p=print_select_all(sql);
		//printf("p=%s",p);
		print_declare("0",p,cname,0,0);
		print_open_cursor(cname,"0");


}


if (type=='E') {
		char buff[256];
		sprintf(cname,"acl_c%s",reptab);
		cname[18]=0;
		print_close ('C', cname);
		start_bind('i',0);
		sprintf(buff,"DROP TABLE %s",reptab);
		print_exec_sql_bound(buff);
}

if (type=='M') { /* Make the table */
  	sprintf (buff, "CREATE TEMP TABLE %s(\n",reptab);
	sprintf(ins_str,"\"INSERT INTO %s VALUES (",reptab);
  	rcnt++;
  	for (a = 0; a < c; a++) {
      		if (a) {
			strcat (buff,",\n");
			strcat (ins_str,",");
		}
      		sprintf (tmpbuff, "c%d ",a);
		l_dt=fbind[a].dtype&0xffff;
		l_sz=DECODE_SIZE(fbind[a].dtype);
		strcat(tmpbuff, nm (l_dt));
		
		strcat(tmpbuff, A4GL_dtype_sz (l_dt,l_sz));
		
      		strcat (buff, tmpbuff);
		strcat (ins_str,"?");
    	}
        strcat(buff,")");
        strcat(ins_str,")\"");

	start_bind('i',0);
	print_exec_sql_bound(buff);

	sprintf(buff,"DELETE FROM %s",reptab);
	print_exec_sql_bound(buff);
	sprintf(iname,"acl_p%s",reptab);
	iname[18]=0;
	print_prepare (iname, ins_str);
	}

}


void A4GL_add_put_string(char *s) {
}


/* ================================== EOF =============================== */



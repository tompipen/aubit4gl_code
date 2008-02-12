#include "a4gl_lib_lex_esqlc_int.h"
#define ONE_NOT_ZERO(x) (x?x:1)
#include "field_handling.h"
#include "compile_c.h"
#include "cmd_funcs.h"
#include "fgl_enums.h"
#define set_nonewlines() set_nonewlines_full(__LINE__)

extern int line_for_cmd;
extern int tmp_ccnt;

//@ FIXMES : 
// make sure to check usages of A4GL_find_pointer, because we might not be 
// adding the CURCODE values in...


/* 
 * These bindings will be populated when SQL commands are
 * generated via callbacks from get_sql_variable_usage
 */
struct expr_str_list *input_bind=0;
struct expr_str_list *output_bind=0;
static char *get_esql_ident_as_string(expr_str *ptr);
static char * get_ibind_usage (int a, char *context);
char * get_ibind_usage_nl (int a, char *context) ; // Just the same but with a \n at the end...
static char * get_obind_usage (int a, char *context);
static char *get_esql_ident_as_string_for_function_calls(expr_str *ptr,int quote_string);
int match_variable_usage(variable_usage *u1, variable_usage *u2);

#define GET_SQL_VARIABLE_USAGE_STYLE_NORMAL 0
#define GET_SQL_VARIABLE_USAGE_STYLE_QUERY_PLACEHOLDER 1

int get_sql_variable_usage_style=GET_SQL_VARIABLE_USAGE_STYLE_NORMAL;

struct insert_cursor_prep {
	char *cursorname;
	char *prepname;
	struct expr_str_list *binding;
};





/******************************************************************************/
/*                            HELPER  COMMANDS                                */
/******************************************************************************/
int doing_esql() {
	return 1;
}



// INSERT CURSOR EMULATION
// we need to store the prepare statement associated with an insert cursor so we
// can 'execute' it when the 4gl says to do a put...
// There are two situtations that may occur
//
// 1) The declare is for a real insert statement
//    if this is the case - we need to prepare it ourselves
// 2) the declare is for a prepared statement
//    we can just use that...
//
struct insert_cursor_prep *insert_cursor_preps=0;

int insert_cursor_preps_cnt=0;
static void add_insert_cursor_preps(char *cursorname, char *prepname,struct expr_str_list *l) {
struct expr_str_list *lnew;
	insert_cursor_preps_cnt++;
	insert_cursor_preps=realloc(insert_cursor_preps, sizeof(struct insert_cursor_prep)*insert_cursor_preps_cnt);
	insert_cursor_preps[insert_cursor_preps_cnt-1].cursorname=strdup(cursorname);
	insert_cursor_preps[insert_cursor_preps_cnt-1].prepname=strdup(prepname);
	if (l) {
		lnew=malloc(sizeof(struct expr_str_list));
		lnew->list.list_len=l->list.list_len;
		lnew->list.list_val=l->list.list_val;
		insert_cursor_preps[insert_cursor_preps_cnt-1].binding=lnew;
	} else {
		insert_cursor_preps[insert_cursor_preps_cnt-1].binding=0;
	}
}

static char *get_insert_cursor_preps_prepname(char *cursorname) {
int a;
for (a=0;a<insert_cursor_preps_cnt;a++) {
	if (strcmp(insert_cursor_preps[a].cursorname,cursorname)==0) {
		return insert_cursor_preps[a].prepname;
	}
}
return 0;
}

/*
static struct expr_str_list*get_insert_cursor_preps_binding(char *cursorname) {
int a;
for (a=0;a<insert_cursor_preps_cnt;a++) {
	if (strcmp(insert_cursor_preps[a].cursorname,cursorname)==0) {
		return insert_cursor_preps[a].binding;
	}
}
return 0;
} 
*/



/********************************************************************************/

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


/********************************************************************************/

static void clr_bindings(void) {
	if (input_bind) {
		if (input_bind->list.list_val) free(input_bind->list.list_val);
	} else {
		input_bind=malloc(sizeof(struct expr_str_list));
	}

	input_bind->list.list_len=0;
	input_bind->list.list_val=0;

	if (output_bind) {
		if (output_bind->list.list_val) free(output_bind->list.list_val);
	} else {
		output_bind=malloc(sizeof(struct expr_str_list));
	}
	output_bind->list.list_len=0;
	output_bind->list.list_val=0;
}


static void
A4GL_save_sql_from_var (void)
{
  //static int sqlcnt = 0;
  //int a;
  if (A4GL_isyes (acl_getenv ("A4GL_EC_LOGSQL")))
    {
      printc ("A4GL_logsql(%d,_module_name,_sql);", line_for_cmd);
    }
}


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
          SPRINTF1 (buff, s, s2);
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
      printc ("A4GL_logsql(%d,_module_name,_sql_stmt_%d);", line_for_cmd,
              sqlcnt++);
      free (buff);
    }
}

static void print_execute_g (expr_str *stmtname,int using_type,struct expr_str_list *using_bind,struct expr_str_list *into_bind) {
int started_with_aclfgli=0;
char *stmt=0;
struct expr_str_list empty;
empty.list.list_len=0;
empty.list.list_val=0;

  if (stmtname->expr_type==ET_EXPR_VARIABLE_IDENTIFIER) 
    {
        static char buff[200];
        started_with_aclfgli=1;
        printc ("{");
        printc("EXEC SQL BEGIN DECLARE SECTION;");
        printc("char *_sid;\n");
        printc("EXEC SQL END DECLARE SECTION;");
	print_expr(stmtname->expr_str_u.expr_expr);
        printc ("_sid=A4GL_char_pop;\n", stmt);
        sprintf(buff,":_sid");
        stmt=buff;
    } 

    if (stmtname->expr_type==ET_EXPR_IDENTIFIER) {
	stmt=stmtname->expr_str_u.expr_string;
    }

  A4GL_assertion(stmt==0,"Internal error - No statement found, expression type not matched");


  if (using_type == 0)
    {
      A4GL_save_sql ("EXECUTE %s", stmt);
      printc ("\nEXEC SQL EXECUTE %s;\n", stmt);
    }

  if (using_type == 1)
    {
      int a;
      printc ("{ /* EXECUTE 1 */\n");

	if (using_bind==0) using_bind=&empty;
      print_bind_definition_g (using_bind,'i');
      print_bind_set_value_g (using_bind,'i');
      print_conversions_g (using_bind,'i');

      A4GL_save_sql ("EXECUTE %s USING ...", stmt);
      set_suppress_lines ();
      printc ("\nEXEC SQL EXECUTE %s USING \n", stmt);
      for (a = 0; a < using_bind->list.list_len; a++)
        {
          	if (a) printc (",");
		printc("%s",get_ibind_usage_nl(a,"EXECUTE"));
        }
      printc (";");
      clr_suppress_lines ();
      printc ("}\n");
    }

  if (using_type == 2)
    {
      int a;
	if (into_bind==0) into_bind=&empty;
      printc ("{ /* EXECUTE 2 */\n");
      print_bind_definition_g (into_bind,'o');
      print_bind_set_value_g (into_bind,'o');
      set_suppress_lines ();
      A4GL_save_sql ("EXECUTE %s INTO ...", stmt);
      printc ("\nEXEC SQL EXECUTE %s INTO \n", stmt);
      for (a = 0; a < into_bind->list.list_len; a++)
        {
          if (a) printc (",");
	  printc("%s", get_obind_usage(a,"EXECUTE"));
        }

      printc (";");
      print_conversions_g (into_bind,'o');
      printc ("}\n");
      clr_suppress_lines ();
    }

  if (using_type == 3)
    {
      int a;
      set_suppress_lines ();
	if (into_bind==0) into_bind=&empty;
	if (using_bind==0) using_bind=&empty;
      printc ("{ /* EXECUTE 3 */\n");
      print_bind_definition_g (using_bind,'i');
      print_bind_definition_g (into_bind,'o');

      print_bind_set_value_g (into_bind,'o');
      print_bind_set_value_g (using_bind,'i');

      print_conversions_g (using_bind,'i');
      A4GL_save_sql ("EXECUTE %s INTO ... USING ...", stmt);
      printc ("\nEXEC SQL EXECUTE %s ", stmt);

      printc (" INTO ");
      for (a = 0; a < into_bind->list.list_len; a++)
        {
          if (a) printc (",");
	  printc("%s", get_obind_usage(a,"EXECUTE"));
        }
      printc (" USING ");
      for (a = 0; a < using_bind->list.list_len; a++)
        {
          	if (a) printc (",");
		printc("%s",get_ibind_usage_nl(a,"EXECUTE"));
        }
      printc (";");
      clr_suppress_lines ();
      print_conversions_g (into_bind,'o');
      printc ("}\n");
    }


  if (started_with_aclfgli) {
		printc("free(_sid);");
                printc("}");
  }


}


void print_exit_program (expr_str *s) {
struct_exit_prog_cmd c;
c.exit_val=s;
print_exit_prog_cmd(&c);

}


// Get the string to use for binding an input variable in a peice of sql...
char * get_ibind_usage (int a, char *context)
{
  static char smbuff[256];
  if (!A4GLSQLCV_check_requirement ("USE_INDICATOR") || strcmp(context,"OPEN")==0)
    {

      SPRINTF1 (smbuff, ":_vi_%d", a);
    }
  else
    {
      if (esql_type () == E_DIALECT_INFOFLEX)
	{
	  SPRINTF2 (smbuff, ":_vi_%d  :_vii_%d", a, a);
	}
      else
	{
	  if (esql_type () == E_DIALECT_POSTGRES)
	    {
	      SPRINTF2 (smbuff, ":_vi_%d INDICATOR :_vii_%d", a, a);
	    }
	  else
	    {
	      SPRINTF2 (smbuff, ":_vi_%d INDICATOR :_vii_%d", a, a);
	    }
	}
    }
  return smbuff;
}


char * get_obind_usage(int a,char *context) {
  static char smbuff[256];
          if (!A4GLSQLCV_check_requirement ("USE_INDICATOR"))
            {
              sprintf (smbuff,":_vo_%d", a);
            }
          else
            {

              if (esql_type () == E_DIALECT_INFOFLEX)
                {
                  sprintf (smbuff,":_vo_%d  :_voi_%d", a, a);
                }
              else
                {
                  sprintf (smbuff,":_vo_%d INDICATOR :_voi_%d", a, a);
                }
            }
	return smbuff;
}

char * get_ibind_usage_nl (int a, char *context) {
	static char buff[2000];
	sprintf(buff,"%s\n",get_ibind_usage(a,context));
	return buff;
}


//  Call back function which appends to the input or output bindings the
//  variables found whilst processing a select, insert, update or delete...
char * get_sql_variable_usage (variable_usage * u, char dir)
{
  struct expr_str *e;
  int a;
  static char smbuff[2000];
  e = A4GL_new_expr_push_variable (u);

  switch (dir)
    {
    case 'i':
      A4GL_new_append_ptr_list (input_bind, e);
      a = input_bind->list.list_len-1;
      break;
    case 'o':
      A4GL_new_append_ptr_list (output_bind, e);
      a = output_bind->list.list_len-1;
      break;
    }


 //
 // If we're processing a string which we'll later prepare - we want to use '?'
 // rather than real variable placeholders...
 // In some outputs - we might want to use named placeholders..
 // If that ever happens - just use the 'a' variable for the @....
 //
 if (get_sql_variable_usage_style==GET_SQL_VARIABLE_USAGE_STYLE_QUERY_PLACEHOLDER) {
	return "?";
  }



  if (!A4GLSQLCV_check_requirement ("USE_INDICATOR"))
    {

      SPRINTF2 (smbuff, ":_v%c_%d", dir, a);
    }
  else
    {
      if (esql_type () == E_DIALECT_INFOFLEX)
	{
	  SPRINTF4 (smbuff, ":_v%c_%d  :_v%ci_%d", dir, a, dir, a);
	}
      else
	{
	  if (esql_type () == E_DIALECT_POSTGRES)
	    {
	      SPRINTF4 (smbuff, ":_v%c_%d INDICATOR :_v%ci_%d", dir, a, dir, a);
	    }
	  else
	    {
	      SPRINTF4 (smbuff, ":_v%c_%d INDICATOR :_v%ci_%d", dir, a, dir, a);
	    }
	}
    }

  return smbuff;
}




char *get_sql_into_buff(struct expr_str_list *into) {
static char buff[64000];
int a;
	if (into==0) return "";
	if (into->list.list_len==0) return 0;
	strcpy(buff," INTO ");
	for (a=0;a<into->list.list_len;a++) {
		if (a) strcat(buff,",\n");
		A4GL_assertion(into->list.list_val[a]->expr_type!=ET_EXPR_VARIABLE_USAGE,"Expecting a variable usage");


		strcat(buff,get_sql_variable_usage (into->list.list_val[a]->expr_str_u.expr_variable_usage,'o'));
	}
	return buff;
}





void
print_generation_copy_status (void)
{
  printc ("A4GLSQL_set_status(sqlca.sqlcode,1); /* Informix Status -> A4GL */");
  printc ("A4GLSQL_set_sqlerrd(sqlca.sqlerrd[0], sqlca.sqlerrd[1], sqlca.sqlerrd[2], sqlca.sqlerrd[3], sqlca.sqlerrd[4], sqlca.sqlerrd[5]);");

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


/******************************************************************************/
int
print_connect_cmd (struct_connect_cmd * cmd_data)
{
char db[2000];
//char user_str[2000];
char connname[2000];
int using_username=0;
  print_cmd_start ();



  printc ("{");
  set_suppress_lines ();
  printc ("\nEXEC SQL BEGIN DECLARE SECTION;");
  printc ("char _u[256];");
  printc ("char _p[256];");
  printc ("char _uAcl[256];");
  printc ("char _pAcl[256];");
  printc ("char _d[256];");
  printc ("\nEXEC SQL END DECLARE SECTION;");




  if (cmd_data->username) {
	print_expr(cmd_data->username);
	printc("A4GL_pop_char(_u, 254);A4GL_trim(_p);");
	print_expr(cmd_data->password);
	printc("A4GL_pop_char(_p, 254);A4GL_trim(_p);");	
	using_username=1;
  }
  

  if (cmd_data->conn_name) {
  	strcpy(connname, local_expr_as_string(cmd_data->conn_name));
  } else {
	strcpy(connname, "\"default_conn\"");
  }


  //if (cmd_data->conn_dbname->expr_type==ET_

  if (cmd_data->conn_dbname->expr_type==ET_EXPR_IDENTIFIER) {
		sprintf(db,"'%s'", cmd_data->conn_dbname->expr_str_u.expr_string);
  } else {
		print_expr(cmd_data->conn_dbname);
		printc("A4GL_pop_char(_d,254);A4GL_trim(_d);");
		sprintf(db,":_d");
  }

  A4GL_save_sql ("CONNECT TO %s",db);

   if (using_username==0) {
   	printc("if (A4GL_sqlid_from_aclfile (_d, _uAcl, _pAcl)) {");
	tmp_ccnt++;
	printc("strcpy(_u, _uAcl); strcpy(_p,_pAcl);");
   		set_nonewlines();
   		switch (esql_type()) {
        			case E_DIALECT_POSTGRES:
          			printc ("\nEXEC SQL CONNECT TO  %s AS %s", db, connname);
              			printc (" USER :_u USING :_p");
          			break;
	
        			case E_DIALECT_INFOFLEX:
          			printc ("\nEXEC SQL DATABASE  %s ",db);
          			break;
	
        			default:
          			printc ("\nEXEC SQL CONNECT TO  %s AS %s", db, connname);
              			printc (" USER :_u USING :_p");
       	}
	tmp_ccnt--;
	printc(";");
   	clr_nonewlines();
   	printc("}");
   }

   set_nonewlines();
   switch (esql_type()) {
        	case E_DIALECT_POSTGRES:
          	printc ("\nEXEC SQL CONNECT TO  %s AS %s", db, connname);
          	if (using_username)
            	{
              	printc (" USER :_u USING :_p");
            	}
          	break;
	
        	case E_DIALECT_INFOFLEX:
          	printc ("\nEXEC SQL DATABASE  %s ",db);
          	break;
	
        	default:
          	printc ("\nEXEC SQL CONNECT TO  %s AS %s", db, connname);
          	if (using_username)
            	{
              	printc (" USER :_u USING :_p");
            	}
       	}
	printc(";");
   	clr_nonewlines();

  
	
  printc("if (sqlca.sqlcode>=0) {A4GL_set_esql_connection(%s);}",connname);

   printc("}");
  clr_suppress_lines ();

  print_copy_status_with_sql (0);
  return 1;
}




static void print_set_conn_from_str(char *conn) { 
  A4GL_save_sql ("SET CONNECTION %s", conn);
  if (esql_type () == E_DIALECT_POSTGRES) {   // Postgres...
                        printc ("\nEXEC SQL SET CONNECTION %s;\n", A4GL_strip_quotes (conn));
  } else {
                        printc ("\nEXEC SQL SET CONNECTION %s;\n", conn);
  }

  printc("if (sqlca.sqlcode>=0) {A4GL_set_esql_connection(%s);}",conn);
}

/******************************************************************************/
static void print_use_session(expr_str *con) {
  if (con==NULL) return ;
  printc ("{");
  printc("EXEC SQL BEGIN DECLARE SECTION;");
  printc("char _sav_cur_conn[32];\n");
  printc("EXEC SQL END DECLARE SECTION;");
  printc ("strcpy(_sav_cur_conn,A4GL_get_esql_connection());\n");
  print_set_conn_from_str(local_expr_as_string(con));
}

/******************************************************************************/

static void print_undo_use(expr_str *con) {
if (con) {
	  printc("EXEC SQL SET CONNECTION :_sav_cur_conn;}");
}
}



void print_exists_subquery(int i, struct s_expr_exists_sq *e) {
        //int n;
	struct s_select *s;
        //expr_str_list l;
	char *ptr;
	char *sql;
	//char ibindstr[256];
	int converted=0;
	static int ncnt=0;
	//char buff[200];
  	char cname[256];

        clr_bindings();

  	SPRINTF1 (cname, "aclfgl_cE_%d", ncnt++);

  	printc ("{");
  	printc ("EXEC SQL BEGIN DECLARE SECTION;");
  	printc("char *_sql;");
  	printc ("int _npc;");
  	printc ("short _npi;");
  	printc ("char _np[256];");
  	printc ("EXEC SQL END DECLARE SECTION;");


	s=e->subquery;

  preprocess_sql_statement (s);
  			search_sql_variables (&s->list_of_items,'i');
  			sql=get_select (s, "");

			if (input_bind && input_bind->list.list_len) {
  				print_bind_definition_g (input_bind,'i');
  				print_bind_set_value_g (input_bind,'i');
  				print_conversions_g (input_bind,'i');
			}

  			if (A4GL_compile_time_convert ())
    			{
      				ptr = A4GLSQLCV_check_sql (sql, &converted);
    			}
  			else
    			{
      				ptr = sql;
    			}
  if (esql_type () == E_DIALECT_INGRES)
    {
      printc ("sqlca.sqlcode=0;\nEXEC SQL DECLARE %s CURSOR FOR %s;", cname,
              ptr);
    }
  else
    {
      printc
        ("sqlca.sqlcode=0;\nEXEC SQL DECLARE %s CURSOR WITH HOLD FOR %s;",
         cname, ptr);
    }

  printc ("if (sqlca.sqlcode==0) {\nEXEC SQL OPEN %s;\n", cname);


      printc ("\nEXEC SQL FETCH %s INTO :_np;\n", cname);
      printc ("}");

  if (i)
    {
      printc ("if (sqlca.sqlcode==0) A4GL_push_int(1);");
      printc ("else A4GL_push_int(0);\n}");
      return;                   //ptr
    }
  else
    {
      printc ("if (sqlca.sqlcode==100) A4GL_push_int(1);");
      printc ("else A4GL_push_int(0);\n}");
      return;                   // ptr
    }

    printc("}");
}



void print_in_subquery(int i, struct s_expr_in_sq *e) {
        //int n;
	struct s_select *s;
        //expr_str_list l;
	char *ptr;
	char *sql;
	char ibindstr[256];
	int converted=0;
  char cname[256];
  static int ncnt = 0;




  	SPRINTF1 (cname, "aclfgl_cI_%d", ncnt++);

        clr_bindings();
        printc("{ /* SUBQUERY - IN */");
  printc ("EXEC SQL BEGIN DECLARE SECTION;");
  printc ("int _npc;");
  printc ("short _npi;");
  printc ("char _np[256];");
  printc ("EXEC SQL END DECLARE SECTION;");

		tmp_ccnt++;
        	print_expr(e->expr);
		s=e->subquery;
		strcpy(ibindstr,"NULL,0");

  			preprocess_sql_statement (s);
  			search_sql_variables (&s->list_of_items,'i');
  			sql=get_select (s, "");




			if (input_bind && input_bind->list.list_len) {
  				print_bind_definition_g (input_bind,'i');
  				print_bind_set_value_g (input_bind,'i');
  				print_conversions_g (input_bind,'i');
			}

  			if (A4GL_compile_time_convert ())
    			{
      				ptr = A4GLSQLCV_check_sql (sql, &converted);
    			}
  			else
    			{
      				ptr = sql;
    			}


	//printc("%s", ptr);


  if (esql_type () == E_DIALECT_INGRES)
    {
      printc ("sqlca.sqlcode=0;\nEXEC SQL DECLARE %s CURSOR FOR %s;", cname,
	      ptr);
    }
  else
    {
      printc
	("sqlca.sqlcode=0;\nEXEC SQL DECLARE %s CURSOR WITH HOLD FOR %s;",
	 cname, ptr);
    }

  printc ("if (sqlca.sqlcode==0) {");
  tmp_ccnt++;
	print_expr(e->expr);
	printc("EXEC SQL OPEN %s;\n", cname);
  	printc ("_npc=0;");
	printc("while (1) {\n");
	tmp_ccnt++;



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
  printc ("if (_npi>=0) A4GL_push_char(_np); else A4GL_push_null(2,0);");
  printc ("_npc++;\n");
  tmp_ccnt--;
  printc ("}\n");
  printc("A4GL_push_int(_npc);");

  if (i) printc (" A4GL_pushop(OP_IN);");
  else printc (" A4GL_pushop(OP_NOTIN);");
  tmp_ccnt--;
  printc ("} else {A4GL_push_int(0);}");
  tmp_ccnt--;
	printc("\n}");

}

/******************************************************************************/
int print_close_sql_cmd(struct_close_sql_cmd *cmd_data,int already_in_command) {
if (!already_in_command)
  print_cmd_start ();
   switch (cmd_data->cl_type) {
		case E_CT_DATABASE:     
			      if (A4GLSQLCV_check_requirement ("USE_DATABASE_STMT") || esql_type () == E_DIALECT_INFOFLEX || esql_type () == E_DIALECT_INFORMIX) {
          				A4GL_save_sql ("CLOSE DATABASE", 0);
          							printc ("\nEXEC SQL CLOSE DATABASE;\n");
        			} else {
          				A4GL_save_sql ("DISCONNECT default", 0);
          				/* printc ("\nEXEC SQL DISCONNECT default;\n"); */
          				printc ("\nEXEC SQL DISCONNECT;\n");
        				}
      				printc ("if (sqlca.sqlcode==0) A4GL_esql_db_open(0,0,0,\"\");");
				break;

		case E_CT_SESSION:      
      					A4GL_save_sql ("DISCONNECT %s", get_esql_ident_as_string(cmd_data->ident));
      					printc ("\nEXEC SQL DISCONNECT %s;\n",get_esql_ident_as_string(cmd_data->ident));
					break;

		case E_CT_CURS_OR_PREP: 
      					A4GL_save_sql ("CLOSE  %s", get_esql_ident_as_string(cmd_data->ident));
      					printc ("\nEXEC SQL CLOSE %s;\n", get_esql_ident_as_string(cmd_data->ident));
      					if (A4GLSQLCV_check_requirement ("IGNORE_CLOSE_ERROR")) {
          					printc ("sqlca.sqlcode=0;");
        				}

  					if (A4GLSQLCV_check_requirement ("CLOSE_CURSOR_BEFORE_OPEN"))
    					{
        					printc("A4GL_ESQL_set_cursor_is_closed(%s);",get_esql_ident_as_string_for_function_calls(cmd_data->ident,1));
    					}

  }

if (!already_in_command)
  print_copy_status_with_sql (0);
  return 1;
}




/******************************************************************************/
int
print_sql_transact_cmd (struct_sql_transact_cmd * cmd_data)
{
  print_cmd_start ();

  if (cmd_data->trans == -1)
    {
      A4GL_save_sql ("BEGIN WORK", 0);
      printc ("\nEXEC SQL BEGIN WORK;\n");
    }
  if (cmd_data->trans == 0)
    {
      A4GL_save_sql ("ROLLBACK WORK", 0);
      printc ("\nEXEC SQL ROLLBACK WORK;\n");
    }
  if (cmd_data->trans == 1)
    {
      A4GL_save_sql ("COMMIT WORK", 0);
      printc ("\nEXEC SQL COMMIT WORK;\n");
    }



  print_copy_status_with_sql (0);
  print_undo_use(cmd_data->connid);
  return 1;
}



static int check_cursor_defined(expr_str *s) {
char *cname;
  cname=get_esql_ident_as_string(s);
  if (!A4GL_find_pointer(cname,CURCODE)) {
                set_yytext(cname);
                a4gl_yyerror("Cursor has not been previously defined");
                return 0;
  }

  return 1;
}


/******************************************************************************/
/*                                SQL COMMANDS                                */
/******************************************************************************/


int
print_put_cmd (struct_put_cmd * cmd_data)
{
int n;
struct expr_str_list *bind;

bind=cmd_data->values;
if (bind && bind->list.list_len==0) {
	bind=0;
}


// ---- 
  print_cmd_start ();
  print_use_session(cmd_data->connid);

  if (!check_cursor_defined(cmd_data->cursorname)) {
	return 0;
  }

  if (A4GLSQLCV_check_requirement ("NO_PUT"))
    {
      if (A4GL_isyes (acl_getenv ("A4GL_INCOMPAT_AT_RUNTIME")))
	{
	
	  printc ("/* FAKE PUT - WILL STOP AT RUN-TIME */");
	  printc ("printf (\"You cannot use a PUT with the target database\\n\"); ");
	  printc ("A4GL_push_long(3);");
	  print_exit_program (A4GL_new_literal_long_long (1));
      return 1 ;
	}
      else
	{
	  a4gl_yyerror ("You cannot use a PUT with the target database");
      return 0 ;
	}
    }


  if (A4GLSQLCV_check_requirement ("EMULATE_INSERT_CURSOR"))
    {
      char *ptr;
      ptr = get_insert_cursor_preps_prepname(get_esql_ident_as_string(cmd_data->cursorname));
      printc ("/* FAKE PUT - USING EXECUTE */");
	if (ptr==0) {
		a4gl_yyerror("No prepared statement for fake insert cursor");
		return 0;
	}

      if (bind == 0)
	{
	  // PUT statment without FROM clause
	  if (A4GL_isyes (acl_getenv ("A4GL_INCOMPAT_AT_RUNTIME")))
	    {
	      printc ("/* FAKE PUT without FROM - WILL STOP AT RUN-TIME */");
	      printc ("printf (\"You cannot use a PUT without FROM with the target database\\n\"); ");
	      printc ("A4GL_push_long(3);");
	      print_exit_program (A4GL_new_literal_long_long (1));
	    }
	  else
	    {
	      a4gl_yyerror ("Doing this isn't implemented yet (PUT without FROM)");
	      return 0;
	    }
	}
      else
	{
	  // We should be ok...
	  print_execute_g (A4GL_new_expr_simple_string(ptr, ET_EXPR_IDENTIFIER), 1,bind,0);
      return 1;
	}
      printc ("/* END OF FAKE PUT - USING EXECUTE */");
      return 1;
    }

  if (bind && bind->list.list_len) {
  printc ("{ /*ins1 */\n");

  n = print_bind_definition_g (bind,'i');
  print_bind_set_value_g (bind,'i');
  print_conversions_g (bind,'i');
  }
  printc ("internal_recopy_%s_i_Dir();", get_esql_ident_as_string_for_function_calls(cmd_data->cursorname,0));
  A4GL_save_sql ("PUT %s", get_esql_ident_as_string_for_function_calls(cmd_data->cursorname,0)  );


  set_suppress_lines ();


  printc ("\nEXEC SQL PUT %s \n", get_esql_ident_as_string(cmd_data->cursorname));


if (bind && bind->list.list_len) {
  if (A4GLSQLCV_check_requirement ("USE_BINDING_FOR_PUT") == 0)
    {
		int a;
		static int bind_using_literals=0; // Switch this if we can bind using literals...
		//int b=0;
		tmp_ccnt++;
	  	printc ("FROM ");
		tmp_ccnt++;


		if (bind_using_literals) {

		for (a=0;a<n;a++) {
			set_nonewlines();
			switch (bind->list.list_val[a]->expr_type) {
			case ET_EXPR_NULL:
				printc("NULL");
				break;
			case ET_EXPR_LITERAL_STRING:
				printc("'%s'", c_generation_trans_quote(bind->list.list_val[a]->expr_str_u.expr_string));
				break;
			case ET_EXPR_VARIABLE_USAGE:
				printc("%s",get_ibind_usage (a,"PUT"));
				break;
			default:
				printc("%s", get_esql_ident_as_string(bind->list.list_val[a]));
			}

			if (a<n-1) printc(",");
			clr_nonewlines();
		}
		} else {
		for (a=0;a<n;a++) {
			set_nonewlines();
				printc("%s",get_ibind_usage (a,"PUT"));
			if (a<n-1) printc(",");
			clr_nonewlines();
			}
		}
		tmp_ccnt--;
		tmp_ccnt--;
    }
  else
    {

      if (n)
	{
	int a;
	  printc ("FROM ");
	  for (a = 0; a < n; a++)
	    {
	      if (a)
		printc (",");
		printc("%s", get_ibind_usage(a,"PUT2"));
	    }
	}
    }
  printc (";");
  printc ("}\n");
} else {
	printc(";");
}

  clr_suppress_lines ();













  print_copy_status_with_sql (0);
  print_undo_use(cmd_data->connid);
  return 1;
}


/******************************************************************************/
int
print_set_session_cmd (struct_set_session_cmd * cmd_data)
{

  print_cmd_start ();

  if (strcmp(cmd_data->session_type,"session")==0) {
	printc ("A4GLSQL_set_conn(%s);\n", get_ident_as_string(cmd_data->s1));
  } else {
	printc("{ char *_s1; char *_s2;char *_s3;");
	print_expr(cmd_data->s1);
	printc("_s1=A4GL_char_pop();");
	print_expr(cmd_data->s2);
	printc("_s2=A4GL_char_pop();");
	print_expr(cmd_data->s3);
	printc("_s3=A4GL_char_pop();");
	printc ("A4GL_set_%s_options(_s1,_s2,_s3);\n", cmd_data->session_type);
	printc("free(_s1); free(_s2);free(_s3);");
	printc("}");

  }

  print_copy_status_with_sql (0);
  return 1;
}




/******************************************************************************/
int
print_locate_cmd (struct_locate_cmd * cmd_data)
{
int a;
print_cmd_start ();
if (cmd_data->where.where==E_LOC_FILE) {
	printc("{char *_fname;");
	print_expr(cmd_data->where.locate_pos_u.filename);
	printc("_fname=A4GL_char_pop();");
}

for (a=0;a<cmd_data->variables->list.list_len;a++) {
	switch (cmd_data->where.where) {
		case E_LOC_FILE: 
			set_nonewlines();
			printc ("A4GL_locate_var(&");
			print_variable_usage(cmd_data->variables->list.list_val[a]);
			printc(",'F',_fname);");
			clr_nonewlines();
			break;
		case E_LOC_MEMORY:
			set_nonewlines();
			printc ("A4GL_locate_var(&");
			print_variable_usage(cmd_data->variables->list.list_val[a]);
			printc(",'M',NULL);");
			clr_nonewlines();
			break;
	}
}
if (cmd_data->where.where==E_LOC_FILE) {
printc("free(_fname);}");
}

  print_copy_status_with_sql (0);

  return 1;
}





/******************************************************************************/
int
print_flush_cmd (struct_flush_cmd * cmd_data)
{
// ---- 
        //struct expr_str * connid;
        //struct expr_str * cursorname;

  print_cmd_start ();
  print_use_session(cmd_data->connid);


  if (A4GLSQLCV_check_requirement ("EMULATE_INSERT_CURSOR"))
    {
      printc ("\n /* ignored FLUSH for %s */ \n", get_esql_ident_as_string (cmd_data->cursorname));
    }
  else
    {
      A4GL_save_sql ("FLUSH %s", get_esql_ident_as_string (cmd_data->cursorname));
      printc ("\nEXEC SQL FLUSH %s;\n", get_esql_ident_as_string (cmd_data->cursorname));
    }

  print_copy_status_with_sql (0);
  print_undo_use(cmd_data->connid);
  return 1;
}



char *get_esql_ident_as_string(expr_str *ptr) {
static char buff[2000];

  if (ptr->expr_type == ET_EXPR_IDENTIFIER)
    {
       sprintf(buff, "%s", ptr->expr_str_u.expr_string);
        return buff;
    }

  if (ptr->expr_type == ET_EXPR_VARIABLE_IDENTIFIER) // a _VARIABLE
    {
	sprintf(buff,":%s",local_expr_as_string (ptr->expr_str_u.expr_expr));
	return buff;
    }


  A4GL_assertion (1, "get_esql_ident_as_string not implemented for this expression type yet");
  return 0;
}



char *get_esql_ident_as_string_for_function_calls(expr_str *ptr,int quote_string) {
static char buff[2000];

  if (ptr->expr_type == ET_EXPR_IDENTIFIER)
    {
	if (quote_string) {
       		sprintf(buff, "\"%s\"", ptr->expr_str_u.expr_string);
	} else {
       		sprintf(buff, "%s", ptr->expr_str_u.expr_string);
	}
        return buff;
    }

  if (ptr->expr_type == ET_EXPR_VARIABLE_IDENTIFIER) // a _VARIABLE
    {
	sprintf(buff,"%s",local_expr_as_string (ptr->expr_str_u.expr_expr));
	return buff;
    }


  A4GL_assertion (1, "get_esql_ident_as_string not implemented for this expression type yet");
  return 0;
}



/******************************************************************************/
int
print_prepare_cmd (struct_prepare_cmd * cmd_data,int already_doing_cmd)
{
// ---- 
        //struct expr_str *connid;
        //struct expr_str *stmtid;
        //struct expr_str *sql;

  if (!already_doing_cmd) {
  		print_cmd_start ();
		print_use_session(cmd_data->connid);
	}
  printc ("{ /* prep1 */\n");
  set_suppress_lines ();
  printc ("\nEXEC SQL BEGIN DECLARE SECTION;\n");
  printc ("char *_sql;\n");
  printc ("char *_s;\n");
  printc ("\nEXEC SQL END DECLARE SECTION;\n");
  clr_suppress_lines ();
  print_expr(cmd_data->sql);
  printc("_sql=A4GL_char_pop();");
  printc ("_s=strdup(CONVERTSQL_LN(_sql,%d));\n", line_for_cmd);
  printc("A4GL_set_err_txt(_s);");
  printc ("\nEXEC SQL PREPARE %s FROM :_s;\n", get_esql_ident_as_string(cmd_data->stmtid));
  A4GL_save_sql_from_var ();
  printc ("free(_s);\n");
  printc ("free(_sql);\n");
  printc ("}\n");



  if (!already_doing_cmd) {
  	print_copy_status_with_sql (0);
  	print_undo_use(cmd_data->connid);
  }
  return 1;
}



/******************************************************************************/
int
print_execute_immediate_cmd (struct_execute_immediate_cmd * cmd_data)
{
static int cnt;
struct struct_prepare_cmd p;
struct struct_execute_cmd e;
char buff[256];


// We'll use NULL on these connections because
// we'll set up up before and clear it after executing both
// PREPARE/EXECUTE calls..
//
	p.connid=NULL; 
	e.connid=NULL; 

// We dont do an EXECUTE IMMEDIATE directly here
// we do a PREPARE then an EXECUTE on the prepare..
	sprintf (buff, "p_%d_%lx", cnt++, time (0));
	p.stmtid=A4GL_new_expr_simple_string(buff, ET_EXPR_IDENTIFIER);

	e.sql_stmtid=p.stmtid;
	e.inbind=NULL;
	e.outbind=NULL;
	p.sql=cmd_data->sql_stmt;
        print_cmd_start ();
        print_use_session(cmd_data->connid);
	print_prepare_cmd(&p,1);
 	printc("if (sqlca.sqlcode>=0) {");
	print_execute_cmd(&e,1);
	printc("}");
  	print_copy_status_with_sql (0);
  	print_undo_use(cmd_data->connid);
  return 1;
}



/******************************************************************************/
int
print_free_cmd (struct_free_cmd * cmd_data)
{
  //static char *cname = 0;
  //struct expr_str *cursorname;
  print_cmd_start ();
  print_use_session(cmd_data->connid);

  printc ("\nEXEC SQL FREE %s;\n", get_esql_ident_as_string(cmd_data->cursorname));
  print_copy_status_with_sql (0);
  print_undo_use(cmd_data->connid);
  return 1;
}



/******************************************************************************/
int
print_set_database_cmd (struct_set_database_cmd * cmd_data)
{
// ---- 
  print_cmd_start ();
        //struct expr_str* set_dbname;
        //enum e_boolean exclusive_mode;



  if (A4GLSQLCV_check_requirement ("USE_DATABASE_STMT") || esql_type () == E_DIALECT_INFOFLEX ||  esql_type () == E_DIALECT_INFORMIX)
    {
	  printc ("{");
	  set_suppress_lines ();
	  printc ("\nEXEC SQL BEGIN DECLARE SECTION;\n");
	  printc ("char *_s;");
	  printc ("\nEXEC SQL END DECLARE SECTION;\n");
	  clr_suppress_lines ();
    print_expr(cmd_data->set_dbname);
	  printc ("_s=A4GL_char_pop();A4GL_trim(_s);");
	  printc ("\nEXEC SQL DATABASE $_s;\n");
    }
  else
    {
                struct_close_sql_cmd cmd_data_for_close_db;
                cmd_data_for_close_db.cl_type=E_CT_DATABASE;
	  printc ("{");
	  set_suppress_lines ();
	  printc ("\nEXEC SQL BEGIN DECLARE SECTION; \n");
	  printc ("char *_s;");
	  printc ("char _uAcl[256]=\"\";");
	  printc ("char _pAcl[256]=\"\";");
	  printc ("\nEXEC SQL END DECLARE SECTION;\n");
	  clr_suppress_lines ();
	  printc ("if (A4GL_esql_db_open(-1,0,0,\"\")) {");
        print_close_sql_cmd(&cmd_data_for_close_db,1);
	  printc ("}");
    	  print_expr(cmd_data->set_dbname);
	  printc ("_s=A4GL_char_pop();A4GL_trim(_s);\n");
  	  printc("if (A4GL_sqlid_from_aclfile (_s, _uAcl, _pAcl)) {");

	  switch (esql_type ())
	    {
	    case E_DIALECT_NONE:
	      A4GL_assertion (1, "No ESQL/C Dialect");
	      break;
	    case E_DIALECT_INFORMIX:
	      A4GL_save_sql ("CONNECT TO $s AS 'default'", 0);	
	      printc ("\nEXEC SQL CONNECT TO $_s AS 'default'\n");
	          printc ("USER :_uAcl USING :_pAcl; "); 

	      break;
	    case E_DIALECT_POSTGRES:
	      A4GL_save_sql ("CONNECT TO $s", 0);		// ecpg 8.1.5
	      printc ("\nEXEC SQL CONNECT TO :_s\n");		// ecpg 8.1.5
	           printc ("USER :_uAcl USING :_pAcl; "); 
	      break;

	    case E_DIALECT_SAPDB:
	      A4GL_save_sql ("CONNECT TO $s AS 'default'", 0);
	      printc ("\nEXEC SQL CONNECT TO $_s AS 'default';\n");
	      break;

	    case E_DIALECT_INGRES:
	      A4GL_save_sql ("CONNECT TO $_s AS 'default'", 0);	
	      printc ("\nEXEC SQL CONNECT :s ;\n");
	      break;
	    case E_DIALECT_INFOFLEX:
	      A4GL_save_sql ("CONNECT TO $_s AS 'default'", 0);	
	      printc ("\nEXEC SQL CONNECT TO $_s AS 'default';\n");
	      break;
	    }

  	  printc("} else {");

	  switch (esql_type ())
	    {
	    case E_DIALECT_NONE:
	      A4GL_assertion (1, "No ESQL/C Dialect");
	      break;
	    case E_DIALECT_INFORMIX:
	      A4GL_save_sql ("CONNECT TO $s AS 'default'", 0);	
	      printc ("\nEXEC SQL CONNECT TO $_s AS 'default';\n");
	      break;
	    case E_DIALECT_POSTGRES:
	      A4GL_save_sql ("CONNECT TO $s", 0);		// ecpg 8.1.5
	      printc ("\nEXEC SQL CONNECT TO :_s;\n");		// ecpg 8.1.5
	      break;
	    case E_DIALECT_SAPDB:
	      A4GL_save_sql ("CONNECT TO $s AS 'default'", 0);
	      printc ("\nEXEC SQL CONNECT TO $_s AS 'default';\n");
	      break;
	    case E_DIALECT_INGRES:
	      A4GL_save_sql ("CONNECT TO $_s AS 'default'", 0);	
	      printc ("\nEXEC SQL CONNECT :s ;\n");
	      break;
	    case E_DIALECT_INFOFLEX:
	      A4GL_save_sql ("CONNECT TO $_s AS 'default'", 0);	
	      printc ("\nEXEC SQL CONNECT TO $_s AS 'default';\n");
	      break;
	    }
  	  printc("}");




    }

  switch (esql_type ())
    {
    case E_DIALECT_NONE:
      A4GL_assertion (1, "No ESQL/C Dialect");
      break;
    case E_DIALECT_INFORMIX:
      printc
	("if (sqlca.sqlcode==0) A4GL_esql_db_open(1,\"INFORMIX\",\"INFORMIX\",_s);");
      break;
    case E_DIALECT_POSTGRES:
      printc
	("if (sqlca.sqlcode==0) A4GL_esql_db_open(1,\"INFORMIX\",\"POSTGRES\",_s);");
      break;
    case E_DIALECT_SAPDB:
      printc
	("if (sqlca.sqlcode==0) A4GL_esql_db_open(1,\"INFORMIX\",\"SAP\",_s);"
	 );
      break;
    case E_DIALECT_INGRES:
      printc
	("if (sqlca.sqlcode==0) A4GL_esql_db_open(1,\"INFORMIX\",\"INGRES\",_s);"
	 );
      break;
    case E_DIALECT_INFOFLEX:
      printc ("if (sqlca.sqlcode==0) A4GL_esql_db_open(1,\"INFORMIX\",\"INFOFLEX\",_s);");
      break;
    }





    printc("free(_s);}\n");


  print_copy_status_with_sql (0);
  return 1;
}




/******************************************************************************/
int
print_fetch_cmd (struct_fetch_cmd * cmd_data,int using_obind_dup_not_obind)
{
  struct expr_str *e;
  char buff[200];
  char *sqcname;
  char *sqcname_no_colon;
int ll;


  if (!check_cursor_defined(cmd_data->fetch->cname)) {
	return 0;
  }

  print_cmd_start ();
  print_use_session(cmd_data->connid);

  set_suppress_lines ();

  printc ("{");
  printc ("\nEXEC SQL BEGIN DECLARE SECTION;");
  printc ("int _fp;");

  if (cmd_data->fetch->cname->expr_type==ET_EXPR_VARIABLE_IDENTIFIER) {
	printc("char _cname[256];");
  }
  printc ("\nEXEC SQL END DECLARE SECTION;");


  if (cmd_data->outbind  && cmd_data->outbind->list.list_len) {
	if (using_obind_dup_not_obind) {
  		print_bind_definition_g(cmd_data->outbind,'r');
  		print_bind_set_value_g(cmd_data->outbind,'r');
	} else {
  		print_bind_definition_g(cmd_data->outbind,'o');
  		print_bind_set_value_g(cmd_data->outbind,'o');
	}
  }


  ll = -2; // Some random number thats not 1 or -1
  e=cmd_data->fetch->fp->fetch_expr;
  if (e) {
        if (e->expr_type==ET_EXPR_LITERAL_LONG) {
		ll=e->expr_str_u.expr_long;
                printc("_fp=%ld;",e->expr_str_u.expr_long);
        } else {
                print_expr(e);
                printc("_fp=A4GL_pop_long();");
        }
  }

  if (cmd_data->fetch->cname->expr_type==ET_EXPR_VARIABLE_IDENTIFIER) {
	print_expr(cmd_data->fetch->cname);
	printc("A4GL_char_pop(_cname,255);A4GL_trim(_cname);");
	sqcname=":_cname";
  	sqcname_no_colon="_cname";
  } else {
  	sqcname=get_esql_ident_as_string(cmd_data->fetch->cname);
  }
  

  if (cmd_data->fetch->fp->ab_rel == FETCH_ABSOLUTE)
    {                           /* FETCH ABSOLUTE */
      switch (ll)
        {
        case 1:
          SPRINTF1 (buff, "\nEXEC SQL FETCH FIRST %s ", sqcname);
          break;

        case -1:
          SPRINTF1 (buff, "\nEXEC SQL FETCH LAST %s ", sqcname);
          break;

        default:
          SPRINTF1 (buff, "\nEXEC SQL FETCH ABSOLUTE :_fp %s",  sqcname);

        }
    }
  else
    {                           /* FETCH RELATIVE */
	switch (ll) {
		case 1:
          		SPRINTF1 (buff, "\nEXEC SQL FETCH %s", sqcname);
			break;
		case -1:
          		SPRINTF1 (buff, "\nEXEC SQL FETCH PREVIOUS %s", sqcname);
			break;
		default: 
          		SPRINTF1 (buff, "\nEXEC SQL FETCH RELATIVE :_fp %s ",  sqcname);
        }
    }

  if (strcmp (buff, "EMPTY") == 0)
    {
      a4gl_yyerror ("error calculating fetch instruction");
      return 0;
    }


  if (A4GLSQLCV_check_requirement ("NO_FETCH_WITHOUT_INTO"))
    {
	int no=0;
	if (cmd_data->outbind ) { no=cmd_data->outbind->list.list_len; }
	if (no==0) {
      		a4gl_yyerror ("You cannot use a FETCH without an INTO with the target database");
	}
    }

        clr_bindings();
  printc ("%s %s ;", buff, get_sql_into_buff(cmd_data->outbind));

  A4GL_save_sql (buff, 0);
  if (cmd_data->outbind && cmd_data->outbind->list.list_len)
    {
	if (using_obind_dup_not_obind) {
      		print_conversions_g (cmd_data->outbind,'r');
	} else {
      		print_conversions_g (cmd_data->outbind,'o');
	}
    }
  printc ("internal_recopy_%s_o_Dir();", get_esql_ident_as_string_for_function_calls(cmd_data->fetch->cname,0));

  printc("}\n");


  clr_suppress_lines ();


  print_copy_status_with_sql (0);
  print_undo_use(cmd_data->connid);

  return 1;
}



int
print_declare_cmd (struct_declare_cmd * cmd_data)
{
//int forUpdate=0;   // when porting - this always seemed blank - it goes in the SQL statement instead...
//char * sid_string;
char cname[256];;
struct s_cur_def *declare_dets;
struct expr_str_list empty;
char *prepname=0;
int var_cname;
int var_prepname;
char *vcname;
char *stmt;
char buff[2000];
	int converted;
int block_started=0;
char *cname3;
int intprflg;


empty.list.list_val=0;
empty.list.list_len=0;


// ---- 
        //struct expr_str *cursorname;
        //struct s_cur_def *declare_dets;
        //e_boolean with_hold;
        //e_boolean scroll;
        //e_boolean isstmt;

  strcpy(cname,get_esql_ident_as_string(cmd_data->cursorname));
  A4GL_add_pointer(cname,CURCODE,(void *) 1);
  cname3=get_esql_ident_as_string_for_function_calls(cmd_data->cursorname,0);
  print_cmd_start ();
  print_use_session(cmd_data->connid);
  clr_bindings();


  declare_dets=cmd_data->declare_dets;
  set_suppress_lines ();

  A4GL_add_pointer(cname,CURCODE,(void *) 1);


  // Are we trying to emulate an insert cursor ?
  if (A4GLSQLCV_check_requirement ("EMULATE_INSERT_CURSOR"))
    {
      char c;
	c=cmd_data->cursor_type;
      if (c == 'I')
	{
		char *str;
		int converted;
		char buff[256];
		static int pcnt=0;
		
		if (declare_dets->ident) {
			// we dont need to do anything else - its already prepared...
			add_insert_cursor_preps(cname, get_esql_ident_as_string(declare_dets->ident),0);
			return 1;
	   	}

		// We've got a real INSERT - so we'll need to prepare that instead...
		// If we do this normally - the string wil probably have some _vi_%d etc in there
		// we'll need to remove these and replace them with '?' instead...
		get_sql_variable_usage_style=GET_SQL_VARIABLE_USAGE_STYLE_QUERY_PLACEHOLDER;
		str=get_insert_cmd(declare_dets->insert_cmd,&converted);
		get_sql_variable_usage_style=GET_SQL_VARIABLE_USAGE_STYLE_NORMAL;

		sprintf(buff,"p_a4gl_%d", pcnt++);
		printc("{");
  		printc ("\nEXEC SQL BEGIN DECLARE SECTION;\n");
  		printc ("char *_sql=\"%s\";\n",escape_quotes_and_remove_nl(str));
  		printc ("\nEXEC SQL END DECLARE SECTION;\n");
  		clr_suppress_lines ();
		printc("EXEC SQL PREPARE %s FROM :_sql;",buff);
		printc("}");
		add_insert_cursor_preps(cname, buff,input_bind);

	  	return 1;		/* We don't really declare a cursor - remember - we're pretending :-) */
	    }
    }

    // We've not got a prepared statement...
    // That means we're looking at an INSERT or a SELECT
    	if (declare_dets->insert_cmd) {
		clr_bindings();
		stmt=get_insert_cmd(declare_dets->insert_cmd,&converted);
	}
	if (declare_dets->select) {
		struct s_select *s;
			clr_bindings();
                        s=declare_dets->select; // just a shortcut to save typing..
                        // Preprocessing will collect all the variables..
                        preprocess_sql_statement (s);
                        // Now convert the variables to '?'
                        search_sql_variables (&s->list_of_items,'i');
                        // generate the SQL string..
                        stmt=get_select (s, "");

			if (declare_dets->forUpdate && strlen(declare_dets->forUpdate)) {
				char *stmt2;
				stmt2=malloc(strlen(stmt)+strlen(declare_dets->forUpdate)+10);
				strcpy(stmt2,stmt);
				strcat(stmt2,declare_dets->forUpdate);
				stmt=stmt2;
			}
	}

var_cname=0;
var_prepname=0;

  if (declare_dets->ident &&declare_dets->ident->expr_type==ET_EXPR_VARIABLE_IDENTIFIER) var_prepname=1;
  if (cmd_data->cursorname && cmd_data->cursorname->expr_type==ET_EXPR_VARIABLE_IDENTIFIER) var_cname=1;

	  

  if (var_cname || var_prepname) {
	printc("{"); block_started++;
  	if (input_bind->list.list_len) { print_bind_definition_g (input_bind,'i'); }
  	if (output_bind->list.list_len) { print_bind_definition_g (output_bind,'o'); }
	printc ("EXEC SQL BEGIN DECLARE SECTION;\n");
      	if (var_cname)    printc ("char _cid[256];");
	if (var_prepname) printc ("char _sid[256];");
	printc ("EXEC SQL END DECLARE SECTION;\n");
      	if (var_cname)    {print_expr(cmd_data->cursorname); printc ("A4GL_pop_char(_cid,254);A4GL_trim(_cid);");}
	if (var_prepname) {print_expr(declare_dets->ident); printc ("A4GL_pop_char(_sid,254);A4GL_trim(_sid);");}
  } else {
	printc("{"); block_started++;
  	if (input_bind->list.list_len) { print_bind_definition_g (input_bind,'i'); }
  	if (output_bind->list.list_len) { print_bind_definition_g (output_bind,'o'); }
  }
  
 if (input_bind->list.list_len) { print_bind_set_value_g (input_bind,'i'); print_conversions_g (input_bind,'i');}
 if (output_bind->list.list_len) { print_bind_set_value_g (output_bind,'o'); }

  if (declare_dets->ident) 
    {
  	if (declare_dets->ident->expr_type==ET_EXPR_VARIABLE_IDENTIFIER) 
	{
      	  prepname = ":_sid";
	} else {
	  prepname= get_esql_ident_as_string(declare_dets->ident);
	}
      set_suppress_lines();
      if (output_bind->list.list_len) print_conversions_g (output_bind,'o');
      clr_suppress_lines();
      stmt=prepname;
    }

  if (var_cname) {
  	vcname=":_cid";
  } else {
	vcname=cname;
  }

  printc("sqlca.sqlcode=0;");

  SPRINTF1 (buff, "EXEC SQL DECLARE %s", vcname);

  if (cmd_data->scroll==EB_TRUE)
    {
      strcat (buff, " SCROLL");
    }
  strcat (buff, " CURSOR");
  if (cmd_data->with_hold==EB_TRUE || esql_type () == E_DIALECT_POSTGRES)	/* All postgres cursors should be with hold */
    {
      strcat (buff, " WITH HOLD");
    }


// If its big - split it up, if not - do it all on one line....
  if (strlen(stmt)>50) {
  	printc ("%s FOR", buff);
  	tmp_ccnt++;
  	printc("%s;",stmt);
  	tmp_ccnt--;
  } else {
  	printc ("%s FOR %s;", buff,stmt);
  }
  A4GL_save_sql ("DECLARE CURSOR FOR %s", vcname);




  if (output_bind->list.list_len && A4GLSQLCV_check_requirement ("NO_DECLARE_INTO"))
    {
      a4gl_yyerror ("You cannot use an INTO with a declare with the target database");
      return 0;
    }




  printh ("static int acli_ni_%s=%d;\n", cname3, input_bind->list.list_len); // USE
  printh ("static int acli_no_%s=%d;\n", cname3, output_bind->list.list_len); // USE
  printh ("static struct BINDING *acli_bi_%s=0;\n", cname3);
  printh ("static struct BINDING *acli_bo_%s=0;\n", cname3);
  printh ("static struct BINDING *acli_nbi_%s=0;\n", cname3);
  printh ("static struct BINDING *acli_nbo_%s=0;\n", cname3);
  printh ("static struct BINDING *acli_nbii_%s=0;\n", cname3);
  printh ("static struct BINDING *acli_nboi_%s=0;\n", cname3);

  printh ("\n\nstatic void internal_recopy_%s_i_Dir(void) {\n", cname3);
  if (input_bind->list.list_len && has_conversions_g(input_bind,'I')) {
  	printh ("struct BINDING *ibind;\n");
  	printh ("struct BINDING *native_binding_i;\n");
  	printh ("struct BINDING *native_binding_i_ind;\n");
  	printh ("ibind=acli_bi_%s;\n", cname3);
  	printh ("native_binding_i_ind=acli_nbii_%s;\n", cname3);
  	printh ("native_binding_i=acli_nbi_%s;\n", cname3);
  	print_conversions_g (input_bind,'I');
  } else {
	printh("/* doesn't need to do anything */\n");
  }
  printh ("}\n");

  printh ("\n\nstatic void internal_recopy_%s_o_Dir(void) {\n", cname3);
  if (output_bind->list.list_len && has_conversions_g (output_bind,'O')) {
  	printh ("struct BINDING *obind;\n");
  	printh ("struct BINDING *native_binding_o;\n");
  	printh ("struct BINDING *native_binding_o_ind;\n");
  	printh ("obind=acli_bo_%s;\n", cname3);
  	printh ("native_binding_o=acli_nbo_%s;\n", cname3);
  	printh ("native_binding_o_ind=acli_nboi_%s;\n", cname3);
  	 print_conversions_g (output_bind,'O');
  } else {
	printh("/* doesn't need to do anything */\n");
  }
  printh ("}\n");


  printh
    ("\n\nstatic void internal_set_%s(struct BINDING *i,struct BINDING *o,struct BINDING *ni,struct BINDING *no,struct BINDING *nii,struct BINDING *noi) {\n",
     cname3);
  printh ("acli_bi_%s  =bind_recopy(acli_bi_%s,  %d,i);\n", cname3, cname3, input_bind->list.list_len); // USE
  printh ("acli_bo_%s  =bind_recopy(acli_bo_%s,  %d,o);\n", cname3, cname3, output_bind->list.list_len); // USE
  printh ("acli_nbi_%s =bind_recopy(acli_nbi_%s, %d,ni);\n", cname3, cname3, input_bind->list.list_len); // USE
  printh ("acli_nbo_%s =bind_recopy(acli_nbo_%s, %d,no);\n", cname3, cname3, output_bind->list.list_len); // USE
  printh ("acli_nbii_%s=bind_recopy(acli_nbii_%s,%d,nii);\n", cname3, cname3, input_bind->list.list_len); // USE
  printh ("acli_nboi_%s=bind_recopy(acli_nboi_%s,%d,noi);\n", cname3, cname3, output_bind->list.list_len); // USE
  printh ("}\n");

  intprflg = 0;

  if (input_bind->list.list_len) intprflg++; // USE
  if (output_bind->list.list_len) intprflg += 2; // USE

  switch (intprflg)
    {
    case 3:
      if (!A4GLSQLCV_check_requirement ("USE_INDICATOR"))
	strcpy (buff, "0,0");
      else
	strcpy (buff, "native_binding_i_ind,native_binding_o_ind");
      printc
	("internal_set_%s(ibind,obind,native_binding_i,native_binding_o,%s);",
	 cname3, buff);
      break;
    case 2:
      if (!A4GLSQLCV_check_requirement ("USE_INDICATOR"))
	strcpy (buff, "0,0");
      else
	strcpy (buff, "0,native_binding_o_ind");
      printc ("internal_set_%s(0,obind,0,native_binding_o,%s);", cname3,
	      buff);
      break;
    case 1:
      if (!A4GLSQLCV_check_requirement ("USE_INDICATOR"))
	{
	  strcpy (buff, "0,0");
	}
      else
	{
	  strcpy (buff, "native_binding_i_ind,0");
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

  //printc ("} /* DC 1*/\n");

  if (block_started)
    {
      printc ("} /* Cname starts with aclfgli... */");
    }

  clr_suppress_lines ();
  print_copy_status_with_sql (0);
  print_undo_use(cmd_data->connid);
  return 1;
}


/******************************************************************************/
int
print_execute_cmd (struct_execute_cmd * cmd_data,int already_doing_command)
{
// ---- 
////int ni;
//int no;
int using;
        //struct expr_str_list* inbind;
        //struct expr_str_list* outbind;
        //struct expr_str *sql_stmtid;
  if (!already_doing_command) {
  	print_cmd_start ();
  	print_use_session(cmd_data->connid);
  }

  using=0;
        
  if (cmd_data->inbind && cmd_data->inbind->list.list_len) using +=1;
  if (cmd_data->outbind && cmd_data->outbind->list.list_len) using +=2;

  print_execute_g (cmd_data->sql_stmtid,using,cmd_data->inbind,cmd_data->outbind) ;

  if (!already_doing_command) {
  	print_copy_status_with_sql (0);
  	print_undo_use(cmd_data->connid);
  }
  return 1;
}




/******************************************************************************/
int
print_open_cursor_cmd (struct_open_cursor_cmd * cmd_data)
{
  static char *cname = 0;
  struct expr_str_list *using_bind;

// ---- 
  print_cmd_start ();
  print_use_session(cmd_data->connid);

  cname =get_esql_ident_as_string(cmd_data->cursorname);

  if (!check_cursor_defined(cmd_data->cursorname)) {
	return 0;
  }


  if (A4GLSQLCV_check_requirement ("EMULATE_INSERT_CURSOR"))
    {
      char c;
      c = cmd_data->cursor_type;
      if (c == 'I')
	{
	  printc ("/* Ignore open cursor - faking insert cursor */");
	  return 1;		/* We don't really open a cursor - remember - we're pretending :-) */
	}
    }

  set_suppress_lines ();

  if (A4GLSQLCV_check_requirement ("CLOSE_CURSOR_BEFORE_OPEN"))
    {
      printc ("\nif (A4GL_ESQL_cursor_is_open(%s)) {\nEXEC SQL CLOSE  %s; /* AUTOCLOSE */\n}\n", get_esql_ident_as_string_for_function_calls(cmd_data->cursorname,1), cname);
    }

  using_bind=cmd_data->using_bind;
  if (using_bind && using_bind->list.list_len )
    {
      int a;
      int ni;
      printc ("internal_recopy_%s_i_Dir();", get_esql_ident_as_string_for_function_calls(cmd_data->cursorname,0));
      printc ("{ /* OPEN */\n");
      ni = print_bind_definition_g (using_bind,'i');
      print_bind_set_value_g (using_bind,'i');
      print_conversions_g (using_bind,'i');

      A4GL_save_sql ("OPEN %s USING ...", get_esql_ident_as_string_for_function_calls(cmd_data->cursorname,0));
      printc ("\nEXEC SQL OPEN %s USING \n", get_esql_ident_as_string_for_function_calls(cmd_data->cursorname,0));

      for (a = 0; a < ni; a++)
	{
	  //if (a) printc (",");
	  printc ("   %s%s\n", get_ibind_usage(a,"OPEN"), a<(ni-1)?",":"");
	}

      printc ("   ;");
      printc ("}\n");
    }
  else
    {
      printc ("internal_recopy_%s_i_Dir();", get_esql_ident_as_string_for_function_calls(cmd_data->cursorname,0));
      A4GL_save_sql ("OPEN '%s'", get_esql_ident_as_string_for_function_calls(cmd_data->cursorname,0));
      printc ("\nEXEC SQL OPEN  %s;\n", get_esql_ident_as_string(cmd_data->cursorname));
    }


  clr_suppress_lines ();
  if (A4GLSQLCV_check_requirement ("CLOSE_CURSOR_BEFORE_OPEN"))
    {
	printc("if (sqlca.sqlcode>=0) {A4GL_ESQL_set_cursor_is_open(%s);}",get_esql_ident_as_string_for_function_calls(cmd_data->cursorname,1));
    }


  print_copy_status_with_sql (0);
  print_undo_use(cmd_data->connid);
  return 1;
}


/******************************************************************************/
int
print_sql_block_cmd (struct_sql_block_cmd * cmd_data)
{
int a;
struct expr_str_list *into_list=0;
char buff[20000]="";
//static int sqlblock;
//char tmpbuff[200];
//struct struct_execute_cmd exec_cmd;
int ni;
int no;
  print_cmd_start ();
  print_use_session(cmd_data->connid);

  set_suppress_lines ();
  clr_bindings();

// Collect any 'intos...'
  for (a=0;a<cmd_data->list->list.list_len;a++) {
	expr_str *e;
	e=cmd_data->list->list.list_val[a];
	A4GL_debug("%d - %s\n",a, decode_e_expr_type(e->expr_type));
	switch (e->expr_type) {
		
		case ET_EXPR_SQLBLOCK_INTO:
			if (into_list) {
				a4gl_yyerror("More than one INTO is not supported");
			}
			into_list=e->expr_str_u.expr_list;
			break;

		case ET_EXPR_VARIABLE_USAGE:
			A4GL_new_append_ptr_list(input_bind, e);
			break;


		case ET_EXPR_SQLBLOCK_TEXT:
			break;
	
		default: 
			A4GL_pause_execution();
			break;
	}
  }

  for (a=0;a<cmd_data->list->list.list_len;a++) {
	int ibindcnt=0;
	expr_str *e;
	e=cmd_data->list->list.list_val[a];
	switch (e->expr_type) {

		case ET_EXPR_SQLBLOCK_INTO:
			strcat(buff,get_sql_into_buff(into_list));
			break;

		case ET_EXPR_VARIABLE_USAGE:
			strcat(buff, get_ibind_usage(ibindcnt++,"SQLBLOCK"));
			strcat(buff,"\n");
			break;

		case ET_EXPR_SQLBLOCK_TEXT:
			if (strlen(buff)) {
				strcat(buff," ");
			}
			strcat(buff,e->expr_str_u.expr_string);
			break;
			
		default:
			A4GL_assertion(1,"Not implemented");
	}
  }


  printc ("{ /* sql_block_cmd */");
  ni = print_bind_definition_g (input_bind,'i');
  no = print_bind_definition_g (into_list,'o');
  print_bind_set_value_g (input_bind,'i');
  print_bind_set_value_g (into_list,'o');
  print_conversions_g (input_bind,'i');
  A4GL_save_sql (buff, 0);
  printc ("\nEXEC SQL %s;", buff);
  print_conversions_g (into_list ,'o');
  printc ("}");
  clr_suppress_lines ();

  print_copy_status_with_sql (0);
  print_undo_use(cmd_data->connid);
  return 1;
}





static void print_exec_sql_bound_g (char *s, int converted,expr_str_list *bind)
{
  int c;
  set_suppress_lines ();

  A4GL_save_sql (s, 0);

if (bind && bind->list.list_len) {
  printc ("{/* Start exec_sql_bound */\n");
  c = print_bind_definition_g (bind,'i');
  printc ("/* printed bind - print conversions */");
  print_bind_set_value_g (bind,'i');
  print_conversions_g (bind,'i');
}
  printc ("\nEXEC SQL %s; /* exec_sql_bound */\n", s);

if (bind && bind->list.list_len) {
  printc ("}\n");
}

  clr_suppress_lines ();
}




/******************************************************************************/
int
print_unload_cmd (struct_unload_cmd * cmd_data)
{
int print_freesql;
int converted=0;
//char ibindstr[200];
char filename[256];
int isvar=0;
//char delim_s[256];
char *sql;
int doing_esql_unload = 0;
// ---- 
  print_cmd_start ();
  print_use_session(cmd_data->connid);
        //struct expr_str * connid;
        //struct expr_str * sql;
        //struct expr_str* filename;
        //struct expr_str* delimiter;
      
  printc("{");
  tmp_ccnt++;
  printc ("\nEXEC SQL BEGIN DECLARE SECTION;\n");
  printc("char *_sql=0;\n");
  printc("char _filename[512];");
  printc("char *_delimiter=\"|\";");
  printc ("\nEXEC SQL END DECLARE SECTION;\n");
  clr_bindings();


  print_expr(cmd_data->filename);
  printc("A4GL_pop_char(_filename,511);");
  printc ("A4GL_trim(_filename);");
  if (cmd_data->delimiter) {
	print_expr(cmd_data->delimiter);
	printc("_delimiter=A4GL_char_pop();");
  }




// ESQL_UNLOAD was initially designed to work with postgres
// postgres uses the COPY command to do the unload - but it can only
// handle UNLOADS with explicit SELECT statements - not variables
// 
// We need to check to see if we're dealing with that situation here...
//

  doing_esql_unload = A4GLSQLCV_check_requirement ("ESQL_UNLOAD");

  if (doing_esql_unload  && cmd_data->sql->expr_type==ET_EXPR_VARIABLE_USAGE)
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
		("Cannot do an ESQL_UNLOAD for a prepared statement - try setting ESQL_UNLOAD_LIB_FALLBACK=Y if your sql driver allows it");
	      return 0;
	    }
	}
    }

  
// cmd_data->sql will contain a E_SLI_QUERY (within a ET_EXPR_SELECT_LIST_ITEM) or a variable usage
//
switch (cmd_data->sql->expr_type) {

	case ET_EXPR_LITERAL_STRING:	
		sql=cmd_data->sql->expr_str_u.expr_string;
		
		break;
	case ET_E_V_OR_LIT_STRING:
		sql=cmd_data->sql->expr_str_u.expr_string;
		break;

	case ET_EXPR_VARIABLE_USAGE:
		print_expr(cmd_data->sql);
		print_freesql=1;
		printc("_sql=A4GL_char_pop();\n");
		isvar=1;
		sql=":_sql";
		break;

	case ET_EXPR_SELECT_LIST_ITEM:
		{
			struct s_select_list_item *sl_item;
			struct s_select *s;
			char *selectsql;
			char *ptr;
			sl_item=cmd_data->sql->expr_str_u.sl_item;
			A4GL_assertion(sl_item->data.type!=E_SLI_QUERY, "Expecting a query");
			s=sl_item->data.s_select_list_item_data_u.subquery;

  			clr_bindings();
			if (!doing_esql_unload) {
				get_sql_variable_usage_style=GET_SQL_VARIABLE_USAGE_STYLE_QUERY_PLACEHOLDER;
			}
  			preprocess_sql_statement (s);
  			search_sql_variables (&s->list_of_items,'i');
  			selectsql=get_select (s, "");
			get_sql_variable_usage_style=GET_SQL_VARIABLE_USAGE_STYLE_NORMAL;

			print_freesql=0;
  			if (A4GL_compile_time_convert ())
    			{
      				ptr = A4GLSQLCV_check_sql (selectsql, &converted);
    			}
  			else
    			{
      				ptr = selectsql;
    			}
			sql=ptr;
		}
		break;

	default:
		A4GL_assertion(1, "Not handled");
		return 0;

		
}

  if (doing_esql_unload)
    {
      int ni;
      printc ("{ /* un1 */");
  	tmp_ccnt++;
      ni = print_bind_definition_g (input_bind,'i');
      print_bind_set_value_g (input_bind,'i');
      print_conversions_g (input_bind,'i');
      strcpy (filename, ":_filename");
      if (A4GLSQLCV_check_requirement ("ESQL_UNLOAD_FULL_PATH"))
	{
	  printc ("A4GLSQLCV_check_fullpath(_filename);");
	}

      A4GL_save_sql ("UNLOAD : %s", sql);
      printc ("\nEXEC SQL UNLOAD TO %s DELIMITER :_delimiter %s ;", filename,sql);
  	tmp_ccnt--;
      printc ("}");
  	tmp_ccnt--;
      printc ("}");

    }
  else
    {
      int ni=0;
      //int a;
      //char *ptr;
	char ibindstr[128];
      printc ("{ /* un3 */");
  	tmp_ccnt++;
      if (input_bind && input_bind->list.list_len) {
      		ni = print_bind_definition_g (input_bind,'i');
      		print_bind_set_value_g (input_bind,'i');
      		//print_conversions_g (input_bind);
		sprintf(ibindstr,"%d,ibind", ni);
	} else {
		strcpy(ibindstr,"0,NULL");
	}

      if (isvar == 0)
	{
	  printc ("A4GLSQL_unload_data(_filename,_delimiter, \"%s\",%s,0);\n", escape_quotes_and_remove_nl (sql), ibindstr);
	}
      else
	{
	  printc ("A4GLSQL_unload_data(_filename,_delimiter, _sql,%s,0);\n",  ibindstr);
	  
	}
  	tmp_ccnt--;
      printc ("}");
  	tmp_ccnt--;
      printc ("}");
    }


if (doing_esql_unload) {
  print_copy_status_with_sql (0);
} else {
  print_copy_status_not_sql (0);
}
  print_undo_use(cmd_data->connid);
  return 1;
}


/******************************************************************************/
int
print_insert_cmd (struct_insert_cmd * cmd_data)
{
char *ptr;
int c;
int converted;
// ---- 
  print_cmd_start ();
  print_use_session(cmd_data->connid);
       

  // Firstly - clear down the input_bind and output_bind
  
  clr_bindings();

  //
  // generate the insert command - and then make sure its properly
  // escaped so we can use it in a string...
  // We'll get back whether there was any conversion done - which we can then put
  // into the prepare later...
  ptr=(get_insert_cmd(cmd_data,&converted));

  A4GL_save_sql (ptr, 0);

  set_suppress_lines ();
  if (input_bind && input_bind->list.list_len) {
	// We used some variables...
  	printc ("{\n");
  	c = print_bind_definition_g (input_bind,'i');
  	print_bind_set_value_g (input_bind,'i');
  	print_conversions_g (input_bind,'i');
  	printc ("\nEXEC SQL %s;\n", ptr);
  	printc ("}\n");
  } else {
	// No variables used...
  	printc ("\nEXEC SQL %s;\n", ptr);
  }
  clr_suppress_lines ();

  print_copy_status_with_sql (0);
  print_undo_use(cmd_data->connid);
  return 1;
}






/******************************************************************************/
int
print_delete_cmd (struct_delete_cmd * cmd_data)
{
char *ptr;
int converted=0;
  print_cmd_start ();
  print_use_session(cmd_data->connid);
  // Firstly - clear down the input_bind and output_bind
  
  clr_bindings();

  //
  // generate the insert command - and then make sure its properly
  // escaped so we can use it in a string...
  // We'll get back whether there was any conversion done - which we can then put
  // into the prepare later...
  ptr=(get_delete_cmd(cmd_data,&converted));


  set_suppress_lines ();	
  if (input_bind && input_bind->list.list_len) {
	int c;
	// We used some variables...
  	printc ("{\n");
  	c = print_bind_definition_g (input_bind,'i');
  	print_bind_set_value_g (input_bind,'i');
  	print_conversions_g (input_bind,'i');
  	printc ("\nEXEC SQL %s;\n", ptr);
  	printc ("}\n");
  } else {
	// No variables used...
  	printc ("\nEXEC SQL %s;\n", ptr);
  }
  clr_suppress_lines ();



  print_copy_status_with_sql (0);
  print_undo_use(cmd_data->connid);
  return 1;
}




/******************************************************************************/
int
print_update_cmd (struct_update_cmd * cmd_data)
{
char *ptr;
int converted=0;
        //struct expr_str *connid;
        //str table;
        //str_list *column_list;
        //struct s_select_list_item_list *value_list;
        //struct expr_str *where_clause;

  print_cmd_start ();
  print_use_session(cmd_data->connid);

  // Firstly - clear down the input_bind and output_bind
  
  clr_bindings();

  //
  // generate the insert command - and then make sure its properly
  // escaped so we can use it in a string...
  // We'll get back whether there was any conversion done - which we can then put
  // into the prepare later...
  ptr=(get_update_cmd(cmd_data,&converted));

  set_suppress_lines ();
  if (input_bind && input_bind->list.list_len) {
	int c;
	// We used some variables...
  	printc ("{\n");
  	c = print_bind_definition_g (input_bind,'i');
  	print_bind_set_value_g (input_bind,'i');
  	print_conversions_g (input_bind,'i');
  	printc ("\nEXEC SQL %s;\n", ptr);
  	printc ("}\n");
  } else {
	// No variables used...
  	printc ("\nEXEC SQL %s;\n", ptr);
  }
  clr_suppress_lines ();


  print_copy_status_with_sql (0);
  print_undo_use(cmd_data->connid);
  return 1;
}



/******************************************************************************/
int
print_sql_cmd (struct_sql_cmd * cmd_data)
{
  char *ptr;
  int converted = 0;
// ---- 
  print_cmd_start ();
  print_use_session(cmd_data->connid);

  if (A4GL_compile_time_convert ())
    {
      ptr = A4GLSQLCV_check_sql (cmd_data->sql, &converted);
    }
  else
    {
      ptr = cmd_data->sql;
    }

  set_suppress_lines ();
	// No variables used...
  printc ("\nEXEC SQL %s;\n", ptr);
  clr_suppress_lines ();



  print_copy_status_with_sql (0);
  print_undo_use(cmd_data->connid);
  return 1;
}


/* ********************************************************************************  */
/* ********************************************************************************  */
/* ********************************************************************************  */
/* ********************************************************************************  */
/* ********************************************************************************  */
/* ********************************************************************************  */
/* ********************************************************************************  */
/* ********************************************************************************  */
/* ********************************************************************************  */
/* ********************************************************************************  */
/* ********************************************************************************  */
/* ********************************************************************************  */
/* ********************************************************************************  */
/* ********************************************************************************  */
/* ********************************************************************************  */
/* ********************************************************************************  */
/* ********************************************************************************  */
/* ********************************************************************************  */
/* ********************************************************************************  */
/* ********************************************************************************  */
/* ********************************************************************************  */


/******************************************************************************/
int
print_select_cmd (struct_select_cmd * cmd_data)
{
  int ni, no;
  int converted=0;
  //static char b2[60000];
  //int os;
  char *sql;
  char *ptr;
  //char i[200];
  //char o[200];
// ---- 
  print_cmd_start ();
  print_use_session(cmd_data->connid);
        //struct expr_str * connid;
        //struct s_select *sql;
        //str forupdate;
  clr_bindings();

  preprocess_sql_statement (cmd_data->sql);
  search_sql_variables (&cmd_data->sql->list_of_items,'i');
  sql=get_select (cmd_data->sql, cmd_data->forupdate);
  output_bind=cmd_data->sql->into;

  if (input_bind) {
	ni=input_bind->list.list_len;
  } else {	
	ni=0;
  }
  if (output_bind) {
	no=output_bind->list.list_len;
  } else {
	no=0;
  }

  if (no||ni) {
  	printc ("{\n");
	// These have to be done in this order
	// because the print_bind_definition_g print the variable declarations
	// and the print_bind_set_value_g set the values that go in them.
	// We want the variable declarations after the '{'...
	if (ni) {
  		print_bind_definition_g (input_bind,'i');
	} 
	if (no) {
  		print_bind_definition_g (output_bind,'o');
	}
	if (ni) {
  		print_bind_set_value_g (input_bind,'i');
      		print_conversions_g (input_bind,'i');
	}
	if (no) {
  		print_bind_set_value_g(output_bind,'o');
	}
  }
 

  if (A4GL_compile_time_convert ())
    {
      ptr = A4GLSQLCV_check_sql (sql, &converted);
    }
  else
    {
      ptr = sql;
    }


  printc("EXEC SQL %s;", ptr);
  if (no) {
  	print_conversions_g (output_bind,'o');
  }

  if (no||ni) {
  	printc ("}\n");
  }

  print_copy_status_with_sql (0);
  print_undo_use(cmd_data->connid);
  return 1;
}





/******************************************************************************************************************************************************/

/******************************************************************************/
int
print_foreach_cmd (struct_foreach_cmd * cmd_data)
{
int ni;
  //struct expr_str * cursorname;
  //struct expr_str_list* inputvals;
  //struct expr_str_list* outputvals;
  //commands *foreach_commands;
  //int block_id;
  struct struct_open_cursor_cmd open_cursor;

	open_cursor.connid=NULL;
	open_cursor.cursorname=cmd_data->cursorname;
 	open_cursor.using_bind=cmd_data->inputvals;
clr_bindings();
  print_cmd_start ();
  print_use_session(cmd_data->connid);
  printc ("{");
  tmp_ccnt++;
  printc("int _cursoropen=0;");
  printc("int _fetcherr=0;");
  printc("int _fetchstatus=0;");


  printc ("A4GLSQL_set_sqlca_sqlcode(0);\n");
  print_open_cursor_cmd(&open_cursor);
  print_generation_copy_status();
  printc ("if (a4gl_sqlca.sqlcode!=0) {");
  printc("goto END_BLOCK_%d;",cmd_data->block_id);
  printc("}");

  printc("_cursoropen=1;");
  printc("_fetcherr=0;");
  printc ("while (1) {\n");
  tmp_ccnt++;

	if (cmd_data->outputvals && cmd_data->outputvals->list.list_len) {
  		ni = print_bind_definition_g (cmd_data->outputvals,'o');
  		print_bind_set_value_g(cmd_data->outputvals,'o');
		  printc ("\nEXEC SQL FETCH %s %s;\n", get_esql_ident_as_string(cmd_data->cursorname), get_sql_into_buff (cmd_data->outputvals));
	} else {
		  printc ("\nEXEC SQL FETCH %s;\n", get_esql_ident_as_string(cmd_data->cursorname));
	}
  printc("if (sqlca.sqlcode<0) _fetcherr=sqlca.sqlcode;");
  print_copy_status_with_sql(0);
  printc("_fetchstatus=sqlca.sqlcode;");
  //print_generation_copy_status();
  printc ("internal_recopy_%s_o_Dir();", get_esql_ident_as_string_for_function_calls(cmd_data->cursorname,0));
  if (cmd_data->outputvals && cmd_data->outputvals->list.list_len) {
  	print_conversions_g (cmd_data->outputvals,'o');
	}
  clr_suppress_lines ();
  printc ("if (_fetchstatus==100 ) break;\n");

  dump_commands(cmd_data->foreach_commands);
  printc("CONTINUE_BLOCK_%d:;",cmd_data->block_id );
  tmp_ccnt--;
  printc ("}");
  printc("END_BLOCK_%d:;",cmd_data->block_id );
  printc("if (_cursoropen) {");
  tmp_ccnt++;
  printc ("EXEC SQL CLOSE %s;\n",  get_esql_ident_as_string(cmd_data->cursorname)); 
  printc("if (a4gl_status == 0) { if (_fetcherr) {A4GLSQL_set_status(_fetcherr,1);}}");
  printc("if (a4gl_status == 100) { if (_fetcherr) {a4gl_sqlca.sqlcode = a4gl_status=_fetcherr;} else {a4gl_sqlca.sqlcode = a4gl_status = 0; }}");
  tmp_ccnt--;
  printc("}");

tmp_ccnt--;
  printc("}");
  printcomment ("/* end of foreach while loop */\n");

  //print_copy_status_with_sql (0);

  print_undo_use(cmd_data->connid);
  return 1;
}




/******************************************************************************/
int
print_load_cmd (struct_load_cmd * cmd_data)
{
int has_collist;
int issql=0;
// ---- 
  //struct expr_str * connid;
  //struct expr_str* filename;
  //struct expr_str* delimiter;
  //struct expr_str *sqlvar; /* We'll use either sqlvar or tabname/collist */
  //str tabname;
  //str_list*  collist;

  print_cmd_start ();
  print_use_session (cmd_data->connid);

  printc ("{");
  printc ("\nEXEC SQL BEGIN DECLARE SECTION; ");

  printc ("char _filename[512];");
  if (cmd_data->delimiter)
    {
      printc ("char *_delimiter=0;");
    }
  else
    {
      printc ("char *_delimiter=\"|\";");
    }
  if (cmd_data->sqlvar)
    {
      printc ("char *_sql=0;");
    }
  printc ("\nEXEC SQL END DECLARE SECTION;");

  print_expr (cmd_data->filename);
  printc ("A4GL_pop_char(_filename,511); A4GL_trim(_filename); ");

  if (cmd_data->delimiter)
    {
      print_expr (cmd_data->delimiter);
      printc ("_delimiter=A4GL_char_pop();");
    }


  if (A4GLSQLCV_check_requirement ("ESQL_UNLOAD"))
    {
      if (A4GLSQLCV_check_requirement ("ESQL_UNLOAD_FULL_PATH"))
	{
	  printc ("A4GLSQLCV_check_fullpath(_filename);");
	}

      printc ("\nEXEC SQL LOAD FROM :_filename DELIMITER :_delimiter ");
		issql=0;


	has_collist=1;
	if (cmd_data->collist==0) {
			has_collist=0;
	} else {
		if (cmd_data->collist->str_list_entry.str_list_entry_len==0) has_collist=0;
	}


      if (has_collist==0) {
        printc (" INSERT INTO %s;", cmd_data->tabname);
	} else {
          printc (" INSERT INTO %s (%s);", cmd_data->tabname, get_str_list_as_string(cmd_data->collist,","));
        }
    }
  else
    {
      if (cmd_data->sqlvar)
	{
	  print_expr (cmd_data->sqlvar);
	  printc ("_sql=A4GL_char_pop();");
	  printc ("A4GLSQL_load_data_str(_filename,_delimiter,_sql);\n");
	  printc ("free(_sql);");
		issql=0;
	}
      else
	{
	  int a;
	  set_nonewlines ();
	  printc ("A4GLSQL_load_data(_filename,_delimiter,\"%s\"\n", cmd_data->tabname);
	  if (cmd_data->collist)
	    {
	      for (a = 0; a < cmd_data->collist->str_list_entry.str_list_entry_len; a++)
		{
		  printc (",");
		  printc ("\"%s\"", cmd_data->collist->str_list_entry.str_list_entry_val[a]);
		}
	    }
	  printc (",0);\n");
		issql=0;
	  clr_nonewlines ();
	}
    }


  if (cmd_data->delimiter)
    {
      printc ("free(_delimiter);");
    }
  printc ("}");

if (issql) {
  print_copy_status_with_sql (0);
} else {
  print_copy_status_not_sql (0);
}
  print_undo_use (cmd_data->connid);
  return 1;
}



void print_report_table (char *repname, char type, int c,char*asc_desc,struct expr_str_list *funcbind, struct expr_str_list *orderbind) {
  static char iname[256];
  static expr_str *cname=0;
  char buff[10000];
  static char reptab[64]="XXXXXXXXXXXXXXXXXXXXXXXX";
  char tmpbuff[256];
  char ins_str[10000];
  static int rcnt = 0;
  int a;
  int converted = 0;
  int l_dt;
  int l_sz;

  //expr_str_list *inbind;
  //expr_str_list *outbind;

printc("/*******************************************************************/");
printc("/* PRINT REPORT TABLE %c */",type);
printc("/*******************************************************************/");

  if (A4GLSQLCV_check_requirement ("TEMP_AS_DECLARE_GLOBAL"))
    {
      char b[64];
      SPRINTF2 (reptab, "aclfgl_%d%s", rcnt, repname);
      reptab[18] = 0;		/* Make sure its short enough... */
      SPRINTF1 (b, "session.%s", reptab);
      strcpy (reptab, b);
    }
  else
    {
      SPRINTF2 (reptab, "aclfgl_%d%s", rcnt, repname);
      reptab[18] = 0;		/* Make sure its short enough... */
    }

  if (type == 'R')
    {
      /* to copy it across... */
      //extern int ibindcnt;
      //extern long a_ibind;
      //extern int fbindcnt;
      //ibindcnt = fbindcnt;
      //ibind = ensure_bind (&a_ibind, ibindcnt, ibind);
      //memcpy (ibind, fbind, sizeof (struct binding_comp) * c + 1);

      if (esql_type () != E_DIALECT_POSTGRES)
	{
	  if (A4GLSQLCV_check_requirement ("TEMP_AS_DECLARE_GLOBAL"))
	    {
	      SPRINTF1 (iname, "acl_p%s", &reptab[8]);
	      iname[18] = 0;
	    }
	  else
	    {
	      SPRINTF1 (iname, "acl_p%s", reptab);
	      iname[18] = 0;
	    }
	
	  /* print_execute needs an ibind - we have an fbind - so we need */
	  print_execute_g (A4GL_new_expr_simple_string(iname, ET_EXPR_IDENTIFIER), 1, funcbind, NULL);
	}
      else
	{
	  SPRINTF1 (ins_str, "INSERT INTO %s VALUES (", reptab);
	  for (a = 0; a < c; a++)
	    {
	      if (a) { strcat (ins_str, ","); }
	      strcat(ins_str,get_ibind_usage(a,"REPORT"));
	    }

	  strcat (ins_str, ")");
	  print_exec_sql_bound_g (ins_str, 1, funcbind);
	}
    }

  if (type == 'F')
    {
      //extern int fbindcnt;
      //char buff[256];
      //char buff2[256];
      struct s_fetch f;
      //char *s;
      struct struct_fetch_cmd fetch;

      printc ("{ /* Type F */");
	tmp_ccnt++;
      //printc ("struct BINDING *obind_dup;");

      // The duplicate bindings allocates space as well, so we might
      // as well free it...
      printc("struct BINDING *obind_dup;");
      printc ("obind_dup=A4GL_duplicate_binding(_rbind,%d);",  funcbind->list.list_len);
      //print_bind_definition_g(funcbind,'r');
      //print_bind_set_value_g(funcbind,'r');
      printc ("while (1) {");
		tmp_ccnt++;
	//printc("{");
	//tmp_ccnt++;
      //local_print_bind_set_value_g(funcbind,0,1);
      //strcpy (f.cname, cname);
	f.cname=cname;
 
      f.fp = malloc (sizeof (struct s_fetch_place));
      f.fp->ab_rel = FETCH_RELATIVE;
      f.fp->fetch_expr = A4GL_new_literal_long_long (1);
	fetch.connid=NULL;
	fetch.fetch=&f;
	fetch.outbind=funcbind;

	print_fetch_cmd(&fetch,1);


      printc ("if (sqlca.sqlcode!=0) break;");
      printc ("A4GL_push_params (obind_dup, %d);", c);
	//tmp_ccnt--;
	//printc("}");
    }

  if (type == 'E')
    {
		tmp_ccnt--;
      printc ("A4GL_free_duplicate_binding(obind_dup,%d);", funcbind->list.list_len);
	tmp_ccnt--;
      printc ("}");

    }


  if (type == 'I')
    {
      //extern int current_ordbindcnt;
      //extern struct binding_comp *ordbind;
      char sql[1024];
      int a;
      int b;
      //char *p;
	struct expr_str *pname;
	char cname_str[256];
	char pname_str[256];
	struct struct_declare_cmd declare_cmd;
	struct s_cur_def cur_def;
	struct struct_open_cursor_cmd open_cmd;
	struct struct_prepare_cmd prepare_cmd;


      /* We need to */
      /*    1.  Generate the SQL including our order by */
      /*    2.  declare a cursor for it */
      /*    3.  open that cursor */
      if (A4GLSQLCV_check_requirement ("TEMP_AS_DECLARE_GLOBAL"))
	{
	  SPRINTF1 (cname_str, "acl_c%s", &reptab[8]);
	  cname_str[18] = 0;
	}
      else
	{
	  SPRINTF1 (cname_str, "acl_c%s", reptab);
	  cname_str[18] = 0;
	}

	strcpy(pname_str,cname_str);
	pname_str[4]='S';
	cname=A4GL_new_expr_simple_string(cname_str, ET_EXPR_IDENTIFIER);
	pname=A4GL_new_expr_simple_string(pname_str, ET_EXPR_IDENTIFIER);

      SPRINTF1 (sql, "SELECT * FROM %s ORDER BY ", reptab);

      for (a = 0; a < orderbind->list.list_len; a++)
	{
	  int found = 0;
	  struct variable_usage *vu_orderbind=0;

	  switch (orderbind->list.list_val[a]->expr_type) {
		case ET_EXPR_VARIABLE_USAGE: vu_orderbind=orderbind->list.list_val[a]->expr_str_u.expr_variable_usage; break;
		case ET_EXPR_VARIABLE_USAGE_WITH_ASC_DESC:  vu_orderbind=orderbind->list.list_val[a]->expr_str_u.expr_variable_usage_with_asc_desc->var_usage; break;
		default:
	  		A4GL_assertion(1,"Unable to get variable usage for orderbind");
	  }

	  if (a) strcat (sql, ",");

	  for (b = 0; b < funcbind->list.list_len; b++)
	    {

		struct variable_usage *vu_funcbind;
		A4GL_assertion(funcbind->list.list_val[b]->expr_type!=ET_EXPR_VARIABLE_USAGE, "Expecting a variable usage for funcbind");
		vu_funcbind=funcbind->list.list_val[b]->expr_str_u.expr_variable_usage;
	
	A4GL_debug("COMPARING: %s %s\n",generation_get_variable_usage_as_string(vu_funcbind), generation_get_variable_usage_as_string(vu_orderbind));

	      if (match_variable_usage(vu_funcbind, vu_orderbind)) {
		  char tmpbuff[256];
		  if (asc_desc[a] == 'D')
		    {
		      SPRINTF1 (tmpbuff, "c%d DESC", b);
		    }
		  else
		    {
		      SPRINTF1 (tmpbuff, "c%d", b);
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


      //inbind = empty_genbind ('i');
      //outbind = empty_genbind ('o');


	prepare_cmd.connid=NULL;
	prepare_cmd.stmtid=pname;
	prepare_cmd.sql=A4GL_new_literal_string(sql);

	print_prepare_cmd(& prepare_cmd, 0);

	cur_def.forUpdate=0;
	cur_def.insert_cmd=NULL;
	cur_def.ident=pname;
	cur_def.select=NULL;

	declare_cmd.connid=NULL;
	declare_cmd.cursorname=cname;
	declare_cmd.declare_dets=&cur_def;
	declare_cmd.with_hold=EB_TRUE;
	declare_cmd.scroll=EB_FALSE;
	declare_cmd.isstmt=EB_TRUE;
	declare_cmd.cursor_type='S';
	print_declare_cmd(&declare_cmd);

	open_cmd.cursor_type='S';
	open_cmd.connid=NULL;
	open_cmd.cursorname=cname;
	open_cmd.using_bind=NULL;
	print_open_cursor_cmd(&open_cmd);
    }


  if (type == 'E')
    {
      //char buff[256];
      char cname_str[256];
      struct struct_close_sql_cmd cmd_close;
      if (A4GLSQLCV_check_requirement ("TEMP_AS_DECLARE_GLOBAL"))
	{
	  SPRINTF1 (cname_str, "acl_c%s", &reptab[8]);
	  cname_str[18] = 0;
	}
      else
	{
	  SPRINTF1 (cname_str, "acl_c%s", reptab);
	  cname_str[18] = 0;
	}
	cname=A4GL_new_expr_simple_string(cname_str, ET_EXPR_IDENTIFIER);
	cmd_close.cl_type=E_CT_CURS_OR_PREP;
	cmd_close.ident=cname;
	print_close_sql_cmd(&cmd_close,1);
        printc("EXEC SQL DROP TABLE %s;", reptab);
    }


  if (type == 'M')
    {				/* Make the table */
      char *xptr;
	struct struct_prepare_cmd prepare_cmd;


      if (A4GLSQLCV_check_requirement ("TEMP_AS_DECLARE_GLOBAL"))
	{
	  printc ("A4GLSQLCV_add_temp_table(\"%s\");", &reptab[8]);
	  SPRINTF1 (buff, "DECLARE GLOBAL TEMPORARY TABLE %s( \n", reptab);

	}
      else
	{
	  SPRINTF1 (buff, "CREATE TEMP TABLE %s( \n", reptab);
	}
      SPRINTF1 (ins_str, "INSERT INTO %s VALUES (", reptab);
      rcnt++;
      for (a = 0; a < c; a++)
	{
	  char dtype_char[256];
	  char dtype_char2[256];
	int dt;
	  if (a)
	    {
	      strcat (buff, ",\n");
	      strcat (ins_str, ",");
	    }
	  SPRINTF1 (tmpbuff, "c%d ", a);
	  strcat (buff, tmpbuff);
		dt=get_binding_dtype(funcbind->list.list_val[a]);

	  l_dt = dt & DTYPE_MASK;
	  l_sz = DECODE_SIZE (dt);
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
      strcat (ins_str, ")");

      //start_bind ('i', 0);
      set_suppress_lines ();

      xptr = A4GLSQLCV_check_sql (buff, &converted);
      printc("EXEC SQL %s;",xptr);
      //print_exec_sql_bound_g (xptr, converted, inbind);

      clr_suppress_lines ();

      SPRINTF1 (buff, "DELETE FROM %s", reptab);
      xptr = A4GLSQLCV_check_sql (buff, &converted);
      print_exec_sql_bound_g (xptr, converted, NULL);


      if (A4GLSQLCV_check_requirement ("TEMP_AS_DECLARE_GLOBAL"))
	{
	  SPRINTF1 (iname, "acl_p%s", &reptab[8]);
	  iname[18] = 0;
	}
      else
	{
	  SPRINTF1 (iname, "acl_p%s", reptab);
	  iname[18] = 0;
	}

	prepare_cmd.connid=NULL;
	prepare_cmd.stmtid=A4GL_new_expr_simple_string(iname, ET_EXPR_IDENTIFIER);
	prepare_cmd.sql=A4GL_new_literal_string(ins_str);
	print_prepare_cmd(&prepare_cmd,0);

	//printc("/* PRINT PREPARE ??? %s %s */",iname,ins_str);
/*
      if (esql_type () != E_DIALECT_POSTGRES)
	{
	  print_prepare (iname, ins_str);
	}
*/
    }

printc("/*******************************************************************/");
printc("/* END PRINT REPORT TABLE %c */",type);
printc("/*******************************************************************/");

}


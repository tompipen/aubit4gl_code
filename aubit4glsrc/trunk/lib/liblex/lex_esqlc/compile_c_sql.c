#include "a4gl_lib_lex_esqlc_int.h"
#define ONE_NOT_ZERO(x) (x?x:1)
#include "field_handling.h"
#include "compile_c.h"
#include "cmd_funcs.h"
#define set_nonewlines() set_nonewlines_full(__LINE__)

extern int line_for_cmd;
extern int tmp_ccnt;


/* 
 * These bindings will be populated when SQL commands are
 * generated via callbacks from get_sql_variable_usage
 */
struct expr_str_list *input_bind=0;
struct expr_str_list *output_bind=0;



/******************************************************************************/
/*                            HELPER  COMMANDS                                */
/******************************************************************************/
int doing_esql(void) {
	return 0;
}

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


void print_generation_copy_status() {
	// Does nothing here - required for ESQL/C generation
}


char *get_sql_variable_usage (variable_usage *u ,char dir) {
	struct expr_str *e;
	e=A4GL_new_expr_push_variable(u);

	switch (dir) {
		case 'i': A4GL_new_append_ptr_list(input_bind, e); break;
		case 'o': A4GL_new_append_ptr_list(output_bind, e); break;
	}

	/* For normal C generation - we'll just return a placeholder.. */
	return "?";
}

char *get_sql_into_buff(struct expr_str_list *into) {
	// we dont need to put anything in the generate SQL - because its handled via
	// bindings in the SQL driver libraries...
	return "";
}


void print_report_table (char *repname, char type, int c,char*asc_desc,struct expr_str_list *funcbind, struct expr_str_list *orderbind) {
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


/******************************************************************************/
static void print_use_session(expr_str *con) {
  	if (con==NULL) return ;
  	printc ("{char _sav_cur_conn[32];\n");
  	printc ("strcpy(_sav_cur_conn,A4GLSQL_get_curr_conn());\n");
  	printc ("A4GLSQL_set_conn(%s);\n", get_ident_as_string(con));
}

/******************************************************************************/

static void print_undo_use(expr_str *con) {
if (con) {
	printc("A4GLSQL_set_conn(_sav_cur_conn);}");
}
}



void print_exists_subquery(int i, struct s_expr_exists_sq *e) {
        //int n;
	struct s_select *s;
        //expr_str_list l;
	char *ptr;
	char *sql;
	char ibindstr[256];
	int converted=0;
        clr_bindings();
        printc("{");
	printc("char *_sql;");
	s=e->subquery;
	strcpy(ibindstr,"NULL,0");

  chk_ibind_select(s);
  			preprocess_sql_statement (s);
  			search_sql_variables (&s->list_of_items,'i');
  			sql=get_select (s, "");

			if (input_bind && input_bind->list.list_len) {
  				print_bind_definition_g (input_bind,'i');
  				print_bind_set_value_g (input_bind,'i');
				sprintf(ibindstr,"ibind,%d",input_bind->list.list_len);
			}

  			if (A4GL_compile_time_convert ())
    			{
      				ptr = A4GLSQLCV_check_sql (sql, &converted);
    			}
  			else
    			{
      				ptr = sql;
    			}
			printc("_sql=\"%s\";", escape_quotes_and_remove_nl(ptr));

        printc("A4GL_push_char(_sql);",e->subquery);
        printc("A4GL_push_binding(%s);",ibindstr);

        if (i) printc("A4GL_pushop(OP_EXISTS);");
        else   printc("A4GL_pushop(OP_NOTEXISTS);");
	//printc("free(_sql);");
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
        clr_bindings();
        printc("{");
        printc("char *_sql;");
        print_expr(e->expr);
	s=e->subquery;
	strcpy(ibindstr,"NULL,0");

  chk_ibind_select(s);
  			preprocess_sql_statement (s);
  			search_sql_variables (&s->list_of_items,'i');
  			sql=get_select (s, "");

			if (input_bind && input_bind->list.list_len) {
  				print_bind_definition_g (input_bind,'i');
  				print_bind_set_value_g (input_bind,'i');
				sprintf(ibindstr,"ibind,%d",input_bind->list.list_len);
			}

  			if (A4GL_compile_time_convert ())
    			{
      				ptr = A4GLSQLCV_check_sql (sql, &converted);
    			}
  			else
    			{
      				ptr = sql;
    			}
			printc("_sql=\"%s\";", escape_quotes_and_remove_nl(ptr));

        printc("A4GL_push_char(_sql);",e->subquery);
        printc("A4GL_push_binding(%s);",ibindstr);

        if (i) printc("A4GL_pushop(OP_IN_SELECT);");
        else   printc("A4GL_pushop(OP_NOTIN_SELECT);");
	//printc("free(_sql);");
        printc("}");
}


/******************************************************************************/
/*                                SQL COMMANDS                                */
/******************************************************************************/


int
print_put_cmd (struct_put_cmd * cmd_data)
{
int n;
// ---- 
  print_cmd_start ();
  print_use_session(cmd_data->connid);
  printc("A4GL_push_char(%s);", get_ident_as_string(cmd_data->cursorname));
  if (cmd_data->values) {
  	printc ("{\n");
  	n = print_bind_definition_g (cmd_data->values,'i');
  	print_bind_set_value_g (cmd_data->values,'i');
  	printc ("A4GLSQL_put_insert(ibind,%d);\n", n);
  	printc ("}\n");
  } else {
  	printc ("A4GLSQL_put_insert(NULL,0);\n", n);
  }
  print_copy_status_with_sql (0);
  print_undo_use(cmd_data->connid);
  return 1;
}

/******************************************************************************/
int print_close_sql_cmd(struct_close_sql_cmd *cmd_data,int already_in_command) {

if (!already_in_command) {
  print_cmd_start ();
}
   switch (cmd_data->cl_type) {
		case E_CT_DATABASE:     printc ("A4GL_close_database();\n"); break;
		case E_CT_SESSION:      printc ("A4GLSQL_close_session(%s);\n", get_ident_as_string(cmd_data->ident)); break;
		case E_CT_CURS_OR_PREP: printc ("A4GLSQL_close_cursor(%s);\n",  get_ident_as_string(cmd_data->ident)); break;
  }

if (!already_in_command) {
  print_copy_status_with_sql (0);
}
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
print_sql_transact_cmd (struct_sql_transact_cmd * cmd_data)
{
  print_cmd_start ();
  print_use_session(cmd_data->connid);
  switch (cmd_data->trans) {
	case -1: // Begin
		printc("A4GLSQL_commit_rollback(%d);",cmd_data->trans); break;
	case 1:  // Commit
		printc("A4GLSQL_commit_rollback(%d);",cmd_data->trans); break;
	case 0:  // Rolback
		printc("A4GLSQL_commit_rollback(%d);",cmd_data->trans); break;
  }

  print_copy_status_with_sql (0);
  print_undo_use(cmd_data->connid);
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
  printc ("A4GLSQL_flush_cursor(%s);\n\n", get_ident_as_string(cmd_data->cursorname));
  print_copy_status_with_sql (0);
  print_undo_use(cmd_data->connid);
  return 1;
}




/******************************************************************************/
int
print_prepare_cmd (struct_prepare_cmd * cmd_data,int already_doing_command)
{
// ---- 
if (!already_doing_command) {
  	print_cmd_start ();
	print_use_session(cmd_data->connid);
}
printc("{char *_sql;");
print_expr(cmd_data->sql);
printc("_sql=A4GL_char_pop();");
printc ("A4GLSQL_add_prepare(%s,(void *)A4GLSQL_prepare_select(0,0,0,0,_sql,_module_name,%d,0,0));\n", get_ident_as_string(cmd_data->stmtid),line_for_cmd);
printc("free(_sql);");
printc("}");

  if (!already_doing_command) {
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
  	print_copy_status_with_sql (0);
 	printc("if (a4gl_sqlca.sqlcode>=0) {");
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
  //struct expr_str *cursorname;
  print_cmd_start ();
print_use_session(cmd_data->connid);
  printc ("A4GLSQL_free_cursor (%s);\n",get_ident_as_string(cmd_data->cursorname));
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
    printc("{char *_s; ");
    print_expr(cmd_data->set_dbname);
    printc("_s=A4GL_char_pop();A4GL_trim(_s);");
    printc ("A4GLSQL_init_connection(_s);");
    printc("free(_s);}\n");


  print_copy_status_with_sql (0);
  return 1;
}



/******************************************************************************/
int
print_connect_cmd (struct_connect_cmd * cmd_data)
{
  print_cmd_start ();

  if (cmd_data->username) {
	printc("{char *_u; char *_p;");
	print_expr(cmd_data->username);
	printc("_u=A4GL_char_pop();");
	print_expr(cmd_data->password);
	printc("_p=A4GL_char_pop();");
  }
  set_nonewlines();

  if (cmd_data->conn_name==0) {
  	printc ("A4GLSQL_init_session(\"default_conn\",");
  } else {
  	printc ("A4GLSQL_init_session(%s,", get_ident_as_string(cmd_data->conn_name) );
  }

  print_ident(cmd_data->conn_dbname);

  if (cmd_data->username) {
	printc(",_u,_p);");
    }
  else
    {
      printc (",NULL,NULL);\n");
    }
clr_nonewlines();

  if (cmd_data->username) {
	printc("free(_u); free(_p);}");
  }

  print_copy_status_with_sql (0);
  return 1;
}


/******************************************************************************/
/* using_obind_dup is only used for ESQL/C mode - we can ignore it here       */
int
print_fetch_cmd (struct_fetch_cmd * cmd_data,int using_obind_dup)
{
  struct expr_str *e;
  char buff[200];


  print_cmd_start ();
print_use_session(cmd_data->connid);

  if (cmd_data->outbind ) {
  	printc ("{");
  	print_bind_definition_g(cmd_data->outbind,'o');
  	print_bind_set_value_g(cmd_data->outbind,'o');
  }


  e=cmd_data->fetch->fp->fetch_expr;

  if (e) {
        if (e->expr_type==ET_EXPR_LITERAL_LONG) {
                SPRINTF1(buff,"%ld",e->expr_str_u.expr_long);
        } else {
                print_expr(e);
                SPRINTF0(buff,"A4GL_pop_long()");
        }
  }

  if (cmd_data->outbind==0) {
                printc ("A4GLSQL_fetch_cursor(%s,%d,%s,NULL,NULL); /* No bind */", get_ident_as_string(cmd_data->fetch->cname),cmd_data->fetch->fp->ab_rel, buff);
  } else {
                printc ("A4GLSQL_fetch_cursor(%s,%d,%s,%d,obind);", get_ident_as_string(cmd_data->fetch->cname),cmd_data->fetch->fp->ab_rel, buff,cmd_data->outbind->list.list_len);
  }

  if (cmd_data->outbind ) {
  		printc("}\n");
	}



  print_copy_status_with_sql (0);
  print_undo_use(cmd_data->connid);
  return 1;
}





/******************************************************************************/
int
print_unload_cmd (struct_unload_cmd * cmd_data)
{
int print_freesql;
int converted=0;
char ibindstr[200];
// ---- 
  print_cmd_start ();
  print_use_session(cmd_data->connid);
        //struct expr_str * connid;
        //struct expr_str * sql;
        //struct expr_str* filename;
        //struct expr_str* delimiter;
      
  strcpy(ibindstr,"0,NULL"); // Set up as if we have no input bindings in the SELECT...

  printc("{char *_sql;\n");
  printc("char *_filename;");
  printc("char *_delimiter=\"|\";");
  
// cmd_data->sql will contain a E_SLI_QUERY (within a ET_EXPR_SELECT_LIST_ITEM) or a variable usage
//
switch (cmd_data->sql->expr_type) {

	case ET_EXPR_LITERAL_STRING:	
	case ET_EXPR_VARIABLE_USAGE:
	case ET_E_V_OR_LIT_STRING:
		print_expr(cmd_data->sql);
		print_freesql=1;
		printc("_sql=A4GL_char_pop();\n");
		break;

	case ET_EXPR_SELECT_LIST_ITEM:
		{
			struct s_select_list_item *sl_item;
			struct s_select *s;
			char *sql;
			char *ptr;
			sl_item=cmd_data->sql->expr_str_u.sl_item;
			A4GL_assertion(sl_item->data.type!=E_SLI_QUERY, "Expecting a query");
			s=sl_item->data.s_select_list_item_data_u.subquery;

  			clr_bindings();

  			chk_ibind_select(s);
  			preprocess_sql_statement (s);
  			search_sql_variables (&s->list_of_items,'i');
  			sql=get_select (s, "");

			if (input_bind && input_bind->list.list_len) {
  				print_bind_definition_g (input_bind,'i');
  				print_bind_set_value_g (input_bind,'i');
				sprintf(ibindstr,"%d, ibind",input_bind->list.list_len);
			}

			print_freesql=0;
  			if (A4GL_compile_time_convert ())
    			{
      				ptr = A4GLSQLCV_check_sql (sql, &converted);
    			}
  			else
    			{
      				ptr = sql;
    			}
			printc("_sql=\"%s\";", escape_quotes_and_remove_nl(ptr));
		}
		break;

	default:
		A4GL_assertion(1, "Not handled");
		return 0;

		
}

  print_expr(cmd_data->filename);
  printc("_filename=A4GL_char_pop();");
  if (cmd_data->delimiter) {
	print_expr(cmd_data->delimiter);
	printc("_delimiter=A4GL_char_pop();");
  }

  printc ("A4GLSQL_unload_data(_filename,_delimiter, _sql,%s,%d);\n", ibindstr,converted);
  printc("free(_filename);");
  if (cmd_data->delimiter) { printc("free(_delimiter);"); }
  if (print_freesql) { printc("free(_sql);"); }
  printc("}");

  print_copy_status_with_sql (0);
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
  ptr=escape_quotes_and_remove_nl(get_insert_cmd(cmd_data,&converted));


  if (input_bind && input_bind->list.list_len) {
	// We used some variables...
  	printc ("{\n");
  	c = print_bind_definition_g (input_bind,'i');
  	print_bind_set_value_g (input_bind,'i');
  	printc ("A4GLSQL_execute_implicit_sql(A4GLSQL_prepare_select(ibind,%d,0,0,\"%s\",_module_name,%d,%d,0),1,0,0);\n", c, ptr,line_for_cmd,converted);
  	printc ("}\n");
  } else {
	// No variables used...
  	printc ("A4GLSQL_execute_implicit_sql(A4GLSQL_prepare_select(NULL,0,0,0,\"%s\",_module_name,%d,%d,0),1,0,0);\n", ptr,line_for_cmd,converted);
  }


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
  ptr=escape_quotes_and_remove_nl(get_delete_cmd(cmd_data,&converted));


  if (input_bind && input_bind->list.list_len) {
	int c;
	// We used some variables...
  	printc ("{\n");
  	c = print_bind_definition_g (input_bind,'i');
  	print_bind_set_value_g (input_bind,'i');
  	printc ("A4GLSQL_execute_implicit_sql(A4GLSQL_prepare_select(ibind,%d,0,0,\"%s\",_module_name,%d,%d,0),1,0,0);\n", c, ptr,line_for_cmd,converted);
  	printc ("}\n");
  } else {
	// No variables used...
  	printc ("A4GLSQL_execute_implicit_sql(A4GLSQL_prepare_select(NULL,0,0,0,\"%s\",_module_name,%d,%d,0),1,0,0);\n", ptr,line_for_cmd,converted);
  }


  print_copy_status_with_sql (0);
  print_undo_use(cmd_data->connid);
  return 1;
}



/******************************************************************************/
int
print_load_cmd (struct_load_cmd * cmd_data)
{
// ---- 
        //struct expr_str * connid;
        //struct expr_str* filename;
        //struct expr_str* delimiter;
        //struct expr_str *sqlvar; /* We'll use either sqlvar or tabname/collist */
        //str tabname;
        //str_list*  collist;

  print_cmd_start ();
  print_use_session(cmd_data->connid);


// We could probably just 'inline' the expressions using local_expr_as_string 
// but that might cause issues at a later date if we expand the usage of the 
// expression to something wider..
//
// Might as well make it as generic as possible now...
//

  printc("{");
  printc("char *_filename;");
  if (cmd_data->delimiter) {
  	printc("char *_delimiter=0;");
  } else {
  	printc("char *_delimiter=\"|\";");
  }
  if (cmd_data->sqlvar) {
  	printc("char *_sql;");
  } 
  print_expr(cmd_data->filename);
  printc("_filename=A4GL_char_pop();");

  if (cmd_data->delimiter) {	
	print_expr(cmd_data->delimiter);
	printc("_delimiter=A4GL_char_pop();");
  }
  
  if (cmd_data->sqlvar) {
	print_expr(cmd_data->sqlvar);
	printc("_sql=A4GL_char_pop();");
  	printc ("A4GLSQL_load_data_str(_filename,_delimiter,_sql);\n");
	printc("free(_sql);");
	
  } else {
	int a;
	set_nonewlines();
  	printc ("A4GLSQL_load_data(_filename,_delimiter,\"%s\"\n",cmd_data->tabname);
	if (cmd_data->collist) {
		for (a=0;a<cmd_data->collist->str_list_entry.str_list_entry_len;a++) {
			printc(",");
  			printc ("\"%s\"", cmd_data->collist->str_list_entry.str_list_entry_val[a]);
		}
	}
	printc(",0);\n");
	clr_nonewlines();
  }

  
  printc("free(_filename);");

  if (cmd_data->delimiter) {
	printc("free(_delimiter);");
  }

  printc("}");


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

  ptr=escape_quotes_and_remove_nl(ptr);

  printc ("A4GLSQL_execute_implicit_sql(A4GLSQL_prepare_select(0,0,0,0,\"%s\",_module_name,%d,%d,0),1,0,0);\n", ptr,line_for_cmd,converted);

  print_copy_status_with_sql (0);
  print_undo_use(cmd_data->connid);
  return 1;
}


/******************************************************************************/
int
print_select_cmd (struct_select_cmd * cmd_data)
{
  int ni, no;
  int converted=0;
  static char b2[60000];
  int os;
  char *sql;
  char *ptr;
  char i[200];
  char o[200];
// ---- 
  print_cmd_start ();
  print_use_session(cmd_data->connid);
        //struct expr_str * connid;
        //struct s_select *sql;
        //str forupdate;
  clr_bindings();

  chk_ibind_select(cmd_data->sql);
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


  strcpy(i,"NULL,0");
  strcpy(o,"NULL,0");

  if (no||ni) {
  	printc ("{\n");
	// These have to be done in this order
	// because the print_bind_definition_g print the variable declarations
	// and the print_bind_set_value_g set the values that go in them.
	// We want the variable declarations after the '{'...
	if (ni) {
  		print_bind_definition_g (input_bind,'i');
		sprintf(i,"ibind,%d",ni);
	} 
	if (no) {
  		print_bind_definition_g (output_bind,'o');
		sprintf(o,"obind,%d",no);
	}
	if (ni) {
  		print_bind_set_value_g (input_bind,'i');
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

  ptr=escape_quotes_and_remove_nl(ptr);
  os=snprintf (b2, sizeof(b2),"A4GLSQL_prepare_select(%s,%s,\"%s\",_module_name,%d,%d,%d)", i, o, ptr,line_for_cmd,converted, 0);

  if (cmd_data->sql->sf && cmd_data->sql->sf->into_temp && strlen(cmd_data->sql->sf->into_temp)) {
  	printc ("A4GLSQL_execute_implicit_sql(%s,1,0,0); /* 0 */\n\n", b2);
  } else {
  	printc ("A4GLSQL_execute_implicit_select(%s,1); /* 0 */\n\n", b2);
  }

  if (no||ni) {
  	printc ("}\n");
  }

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
  ptr=escape_quotes_and_remove_nl(get_update_cmd(cmd_data,&converted));

  if (input_bind && input_bind->list.list_len) {
	int c;
	// We used some variables...
  	printc ("{\n");
  	c = print_bind_definition_g (input_bind,'i');
  	print_bind_set_value_g (input_bind,'i');
  	printc ("A4GLSQL_execute_implicit_sql(A4GLSQL_prepare_select(ibind,%d,0,0,\"%s\",_module_name,%d,%d,0),1,0,0);\n", c, ptr,line_for_cmd,converted);
  	printc ("}\n");
  } else {
	// No variables used...
  	printc ("A4GLSQL_execute_implicit_sql(A4GLSQL_prepare_select(NULL,0,0,0,\"%s\",_module_name,%d,%d,0),1,0,0);\n", ptr,line_for_cmd,converted);
  }


  print_copy_status_with_sql (0);
  print_undo_use(cmd_data->connid);
  return 1;
}


/******************************************************************************/
static char *generate_sid_string_for_declare(struct s_cur_def *declare_dets,int *forUpdate) {
static char buff[64000];
	if (declare_dets->forUpdate && strlen(declare_dets->forUpdate)) {
		*forUpdate=1;
	} else {
		*forUpdate=0;
	}
	
        // struct struct_insert_cmd *insert_cmd;
	if (declare_dets->insert_cmd) {
		int converted;
		char *ptr;
		int c;
		// Its an insert cursor...
  		// Firstly - clear down the input_bind and output_bind
  		ptr=escape_quotes_and_remove_nl(get_insert_cmd(declare_dets->insert_cmd,&converted));
  		if (input_bind && input_bind->list.list_len) {
			// We used some variables...
  			c = print_bind_definition_g (input_bind,'i');
  			print_bind_set_value_g (input_bind,'i');
  			sprintf (buff, "A4GLSQL_prepare_select(ibind,%d,0,0,\"%s\",_module_name,%d,%d,0)", c, ptr,line_for_cmd,converted);
  		} else {
			// No variables used...
  			sprintf(buff, "A4GLSQL_prepare_select(NULL,0,0,0,\"%s\",_module_name,%d,%d,0)", ptr,line_for_cmd,converted);
  		}

		return buff;
	}

	if (declare_dets->ident) {
		sprintf(buff,"A4GLSQL_find_prepare(%s)",get_ident_as_string(declare_dets->ident));
		return buff;
	}

        if (declare_dets->select) {
			int converted=0;
			char obindstr[200]="NULL,0";
			char ibindstr[200]="NULL,0";
			struct s_select *s;
			char *sql;
			char *ptr;

			printc("char *_sql;"); // We'll use this to store the SQL select statement...

			s=declare_dets->select; // just a shortcut to save typing..


			// Preprocessing will collect all the variables..
  			chk_ibind_select(s);
  			preprocess_sql_statement (s);

			// Now convert the variables to '?'
  			search_sql_variables (&s->list_of_items,'i');

			// generate the SQL string..
  			sql=get_select (s, "");


			// Does it use any variables for input ? 
			if (input_bind && input_bind->list.list_len) {
  				print_bind_definition_g (input_bind,'i');
			}

			// Does it do a SELECT ..INTO .. ? 
			if (s->into && s->into->list.list_len) {
  				print_bind_definition_g (s->into,'o');

			}

			
			if (input_bind && input_bind->list.list_len) {
  				print_bind_set_value_g (input_bind,'i');
				sprintf(ibindstr,"ibind,%d",input_bind->list.list_len);
			}
			if (s->into && s->into->list.list_len) {
  				print_bind_set_value_g (s->into,'o');
				sprintf(obindstr,"obind,%d",s->into->list.list_len);
			}

  			if (A4GL_compile_time_convert ())
    			{
      				ptr = A4GLSQLCV_check_sql (sql, &converted);
    			}
  			else
    			{
      				ptr = sql;
    			}
			if (declare_dets->forUpdate && strlen(declare_dets->forUpdate) && ! strstr(ptr,"FOR UPDATE OF")) {
				if (!strstr(ptr,"FOR UPDATE OF")) {
					char *p;
					p=strdup(escape_quotes_and_remove_nl(declare_dets->forUpdate ));
					printc("_sql=\"%s%s\";", escape_quotes_and_remove_nl(ptr), p);
				}
			} else {
				printc("_sql=\"%s\";", escape_quotes_and_remove_nl(ptr));
			}
  			sprintf(buff, "A4GLSQL_prepare_select(%s,%s,_sql,_module_name,%d,%d,0)", ibindstr,obindstr, line_for_cmd,converted);
			return buff;

	}
	A4GL_assertion(1,"Unhandled declare");
	return "";

}



int
print_declare_cmd (struct_declare_cmd * cmd_data)
{
int forUpdate=0;   // when porting - this always seemed blank - it goes in the SQL statement instead...
char * sid_string;

// ---- 
        //struct expr_str *cursorname;
        //struct s_cur_def *declare_dets;
        //e_boolean with_hold;
        //e_boolean scroll;
        //e_boolean isstmt;

  print_cmd_start ();
  print_use_session(cmd_data->connid);
  clr_bindings();
  printc("{");
  sid_string=generate_sid_string_for_declare(cmd_data->declare_dets,&forUpdate);
  printc ("A4GLSQL_declare_cursor(%d,%s,%d,%s);", forUpdate+cmd_data->with_hold==EB_TRUE?2:0, sid_string, cmd_data->scroll==EB_TRUE, get_ident_as_string(cmd_data->cursorname));
  printc("}");
  print_copy_status_with_sql (0);
  print_undo_use(cmd_data->connid);
  return 1;
}


/******************************************************************************/
int
print_execute_cmd (struct_execute_cmd * cmd_data,int already_doing_command)
{
// ---- 
int ni;
int no;
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

  if (using == 0) {printc ("A4GLSQL_execute_sql(%s,0,0);\n", get_ident_as_string(cmd_data->sql_stmtid));}

  if (using==1) {
      printc ("{\n");
      ni = print_bind_definition_g (cmd_data->inbind,'i');
      print_bind_set_value_g (cmd_data->inbind,'i');
      printc ("A4GLSQL_execute_sql(%s,%d,ibind);\n", get_ident_as_string(cmd_data->sql_stmtid), ni);
      printc ("}\n");
    }

  if (using==2) {
      printc ("{\n");
      printc("void *_save_bind_ptr;");
      printc("int   _save_bind_cnt;");
      no = print_bind_definition_g (cmd_data->outbind,'o');
      print_bind_set_value_g (cmd_data->outbind,'o');
      printc ("A4GLSQL_swap_bind_stmt(%s,'o',&_save_bind_ptr,&_save_bind_cnt,obind,%d);",get_ident_as_string(cmd_data->sql_stmtid),no);
      printc ("A4GLSQL_execute_implicit_select(A4GLSQL_find_prepare(%s),0); /* 2 */\n", get_ident_as_string(cmd_data->sql_stmtid));
      printc ("A4GLSQL_swap_bind_stmt(%s,'o',0,0,_save_bind_ptr,_save_bind_cnt);",get_ident_as_string(cmd_data->sql_stmtid));
      printc ("}\n");
    }

  if (using==3) {
      printc ("{\n");
      printc("void *_osave_bind_ptr;");
      printc("int   _osave_bind_cnt;");
      printc("void *_isave_bind_ptr;");
      printc("int   _isave_bind_cnt;");
      no = print_bind_definition_g (cmd_data->outbind,'o');
      ni = print_bind_definition_g (cmd_data->inbind,'i');
      print_bind_set_value_g (cmd_data->outbind,'o');
      print_bind_set_value_g (cmd_data->inbind,'i');
      printc ("A4GLSQL_swap_bind_stmt(%s,'o',&_osave_bind_ptr,&_osave_bind_cnt,obind,%d);",get_ident_as_string(cmd_data->sql_stmtid),no);
      printc ("A4GLSQL_swap_bind_stmt(%s,'i',&_isave_bind_ptr,&_isave_bind_cnt,ibind,%d);",get_ident_as_string(cmd_data->sql_stmtid),ni);
      printc ("A4GLSQL_execute_implicit_select(A4GLSQL_find_prepare(%s),0); /* 3 */\n", get_ident_as_string(cmd_data->sql_stmtid));
      printc ("A4GLSQL_swap_bind_stmt(%s,'o',0,0,_osave_bind_ptr,_osave_bind_cnt);",get_ident_as_string(cmd_data->sql_stmtid));
      printc ("A4GLSQL_swap_bind_stmt(%s,'i',0,0,_isave_bind_ptr,_isave_bind_cnt);",get_ident_as_string(cmd_data->sql_stmtid));
      printc ("}\n");
    }



  if (!already_doing_command) {
  	print_copy_status_with_sql (0);
  	print_undo_use(cmd_data->connid);
  }
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

  printc ("{");
tmp_ccnt++;
  printc("int _cursoropen=0;");
  printc("int _fetcherr=0;");
  printc("int _fetchstatus=0;");


  printc ("A4GLSQL_set_sqlca_sqlcode(0);\n");
  print_open_cursor_cmd(&open_cursor);

    printc ("if (a4gl_sqlca.sqlcode!=0) {");
    printc("goto END_BLOCK_%d;",cmd_data->block_id);
    printc("}");

  printc("_cursoropen=1;");
  printc ("while (1) {\n");
  tmp_ccnt++;

	if (cmd_data->outputvals && cmd_data->outputvals->list.list_len) {
  		ni = print_bind_definition_g (cmd_data->outputvals,'o');
  		print_bind_set_value_g(cmd_data->outputvals,'o');
  		printc ("A4GLSQL_fetch_cursor(%s,%d,1,%d,obind); /* Foreach next */\n", get_ident_as_string(cmd_data->cursorname) , FETCH_RELATIVE, ni);
	} else {
  		printc ("A4GLSQL_fetch_cursor(%s,%d,1,0,NULL); /* Foreach next */\n", get_ident_as_string(cmd_data->cursorname) , FETCH_RELATIVE, ni);
	}

  printc ("if (a4gl_sqlca.sqlcode<0||a4gl_sqlca.sqlcode==100) break;\n");

  dump_commands(cmd_data->foreach_commands);
	printc("CONTINUE_BLOCK_%d:;",cmd_data->block_id );

tmp_ccnt--;
  printc ("}");
  printc("END_BLOCK_%d:;",cmd_data->block_id );
  printc("if (_cursoropen) {");
  tmp_ccnt++;
  printc ("A4GLSQL_close_cursor(%s);\n",  get_ident_as_string(cmd_data->cursorname)); 
  printc("if (a4gl_status == 0) { if (_fetcherr) {A4GLSQL_set_status(_fetcherr,1);}}");
  printc("if (a4gl_status == 100) { if (_fetcherr) {a4gl_sqlca.sqlcode = a4gl_status=_fetcherr;} else {a4gl_sqlca.sqlcode = a4gl_status = 0; }}");
tmp_ccnt--;
  printc("}");

tmp_ccnt--;
  printc("}");
  printcomment ("/* end of foreach while loop */\n");

  print_copy_status_with_sql (0);
  print_undo_use(cmd_data->connid);
  return 1;
}




/******************************************************************************/
int
print_open_cursor_cmd (struct_open_cursor_cmd * cmd_data)
{
// ---- 
  print_cmd_start ();
print_use_session(cmd_data->connid);


   if (cmd_data->using_bind && cmd_data->using_bind->list.list_len) {
        int ni;
        printc ("{\n");
        ni = print_bind_definition_g (cmd_data->using_bind,'i');
        print_bind_set_value_g (cmd_data->using_bind,'i');
        printc ("A4GLSQL_open_cursor(%s,%d,ibind);\n", get_ident_as_string(cmd_data->cursorname),ni);
        printc("}");
  } else {
        printc ("A4GLSQL_open_cursor(%s,0,0);\n",  get_ident_as_string(cmd_data->cursorname));
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
static int sqlblock;
char tmpbuff[200];
struct struct_execute_cmd exec_cmd;
  print_cmd_start ();
  print_use_session(cmd_data->connid);

  clr_bindings();

// Collect any 'intos...'
  for (a=0;a<cmd_data->list->list.list_len;a++) {
	expr_str *e;
	e=cmd_data->list->list.list_val[a];
	//printf("%d - %s\n",a, decode_e_expr_type(e->expr_type));
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
	
		default: break;
	}
  }

  for (a=0;a<cmd_data->list->list.list_len;a++) {
	expr_str *e;
	e=cmd_data->list->list.list_val[a];
	switch (e->expr_type) {

		case ET_EXPR_SQLBLOCK_INTO:
			break;
		case ET_EXPR_VARIABLE_USAGE:
			strcat(buff,"?");
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



  //if (output_bind->list.list_len) u+=2;
  //if (input_bind->list.list_len)  u+=1;
  SPRINTF2(tmpbuff,"A4GLsb_%d%d",sqlblock++,line_for_cmd);
  printc("A4GLSQL_add_prepare(\"%s\",(void *)A4GLSQL_prepare_select(0,0,0,0,\"%s\",_module_name,%d,%d,0));",tmpbuff,escape_quotes_and_remove_nl(buff),line_for_cmd,0 /* never converted */);
	exec_cmd.connid=NULL; 

        exec_cmd.sql_stmtid=A4GL_new_expr_simple_string(tmpbuff, ET_EXPR_IDENTIFIER);

  exec_cmd.inbind=input_bind;
  exec_cmd.outbind=into_list;

 print_execute_cmd(&exec_cmd,1);


  print_copy_status_with_sql (0);
  print_undo_use(cmd_data->connid);
  return 1;
}







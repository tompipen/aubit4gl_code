#include "a4gl_4glc_int.h"
#include "a4gl_API_parse_lib.h"

#include "trim_spaces.h"

extern struct cmds command_stack[CMD_STACK_SIZE];
extern int nblock_no;
extern struct s_report_stack report_stack[REPORTSTACKSIZE];

extern int report_stack_cnt;

extern int lines_printed;
extern int use_group;
extern struct s_report sreports[SREPORTS_SIZE];
extern int sreports_cnt;


extern char when_to_tmp[64];
extern char when_to[8][128];
extern int when_code[8];

extern char *whentostore_p;
extern int whenever_store_c;
extern char *whenever_store_p;
extern int ibindcnt;
extern struct binding_comp *ibind;
extern int nullbindcnt;
extern struct binding_comp *nullbind;

extern struct variable **list_local;
extern int list_local_cnt;
extern int list_local_alloc;

/* Lists for our variables in each scope...*/
extern struct variable **list_global ;      /* Our List*/
extern int list_global_cnt ;        /* Number used in our list*/
extern int list_global_alloc ;      /* Space allocated for our list*/


extern struct variable **list_imported_global ;     /* Our List*/
extern int list_imported_global_cnt ;       /* Number used in our list*/
extern int list_imported_global_alloc ;     /* Space allocated for our list*/
extern char                clobber[64];


extern struct variable **list_class ;
extern int list_class_cnt ;
extern int list_class_alloc ;


extern struct variable **list_module;
extern int list_module_cnt ;
extern int list_module_alloc ;
extern char *allbuff;
extern int allbuffsize ;

extern char variable_scope ;


//static void write_variable_header (struct variable *v);
//static void write_variable_simple (struct variable *v);
//static void write_variable_linked (struct variable *v);
//static void write_variable_record (struct variable *v);
//static void write_variable_object (struct variable *v);
//static void write_variable_assoc (struct variable *v);
//static void write_variable_constant (struct variable *v);
//static void write_class_string (char *name, char *val);
//static void write_class_int (char *name, int val);
//static void read_class_int (char *name, int *val);
//static void write_variable_function (struct variable *v);
//static void do_append (void);
//static void escape (char *buff) ;
static char get_current_variable_scope (void);
static void print_module_variables (void);
static void print_global_variables (void);
static void print_local_variables (void);

char * rettype_integer (int n);
//char tmpbuff[1024] = "";

/**
 * Check if is a continue of a command.
 *
 * @param s The keyword / token for it could be a continue.
 *
 * @return
 *   - 1 : Is a continue command.
 *   - 0 : Otherwise.
 */
static int
iscontinuecmd (char *s)
{

  //if (strcmp (s, "FOR") == 0) return 1;
  /* if (strcmp(s,"FOREACH")==0) return 1; */
  //if (strcmp (s, "WHILE") == 0) return 1;
  //if (strcmp (s, "CASE") == 0) return 1;
  /*
     if (strcmp(s,"CONSTRUCT")==0) return 1;
     if (strcmp(s,"DISPLAY")==0) return 1;
     if (strcmp(s,"PROMPT")==0) return 1;
   */

  return 0;
}





void
A4GL_CV_print_exec_sql (char *s)
{
  char *ptr;
  int converted = 0;
  if (A4GL_compile_time_convert ())
    {
      ptr = A4GLSQLCV_check_sql (s, &converted);
    }
  else
    {
      ptr = s;
    }
  print_exec_sql (ptr, converted);
}


void
A4GL_CV_print_exec_sql_bound (char *s)
{
  char *ptr;
  int converted = 0;
  if (A4GL_compile_time_convert ())
    {
      ptr = A4GLSQLCV_check_sql (s, &converted);
    }
  else
    {
      ptr = s;
    }
  print_exec_sql_bound_g (ptr, converted,copy_togenbind('i'));
}


void
A4GL_CV_print_do_select (char *s,t_binding_comp_list *l)
{
  print_do_select (s, 0,l);
//copy_togenbind('o'));
}


/**
 * Acces to the database and push a variable declaration for a simple
 * like variable (the ones that are not like table.*)
 *
 * @param tableName The name of the table
 * @param columnName The name of the column
 *
 * @return
 *   - 0 : Column does not exist or an error ocurred.
 *   - 1 : Type readed.
 */
static int
pushLikeTableColumn (char *tableName, char *columnName)
{
  int rval;
  int idtype;
  int isize;
  char csize[20];
  char cdtype[20];
  char buff[300];
  char *cname;

  A4GL_debug ("pushLikeTableColumn()");

  rval = A4GLSQL_read_columns (tableName, columnName, &idtype, &isize);
  cname = A4GL_confirm_colname (tableName, columnName);

  if (rval == 0)
    {
      SPRINTF2 (buff, "%s.%s does not exist in the database", tableName,
		columnName);
      a4gl_yyerror (buff);
      return 0;
    }
  SPRINTF1 (cdtype, "%d", idtype & 15);
  SPRINTF1 (csize, "%d", isize);

  trim_spaces (cname);
  push_type (rettype (cdtype), csize, (char *) 0);
  return 1;
}



/**
 * Find all columns of a table from the database to declare a record like
 * table.*
 *
 * @param tableName The name of the table
 */
static int
pushLikeAllTableColumns (char *tableName)
{
  int rval;
  int isize = 0;
  int idtype = 0;
  char colname[256] = "";
  char csize[20];
  char cdtype[20];
  char buff[300];
  char *ccol = 0;
  int ncol = 0;
  char *cname;


  A4GL_debug ("pushLikeAllTableColumns()");
  A4GL_debug ("Calling get_columns : '%s'\n", A4GL_null_as_null (tableName));
  rval = A4GLSQL_get_columns (tableName, colname, &idtype, &isize);
  A4GL_debug ("rval = %d", rval);
  if (rval == 0 && tableName)
    {
      SPRINTF1 (buff, "%s does not exist in the database", tableName);
      a4gl_yyerror (buff);
      return 1;
    }

  A4GL_debug ("Rval (%d) !=0", rval);

  while (1)
    {
      colname[0] = 0;

      ccol = 0;
      rval = A4GLSQL_next_column (&ccol, &idtype, &isize);
      if (rval == 0)
	{
	  A4GL_debug ("Got rval back from next_column as 0");
	  break;
	}

      ncol++;

      A4GL_assertion (ccol == 0, "No column name set");

      A4GL_debug ("next column for table '%p' is '%p'", tableName, ccol);
      A4GL_debug ("next column for table '%s' is '%s'",
		  A4GL_null_as_null (tableName), A4GL_null_as_null (ccol));
      strcpy (colname, ccol);


      SPRINTF1 (cdtype, "%d", idtype & 15);
      SPRINTF1 (csize, "%d", isize);
      A4GL_debug ("%d %d", idtype, isize);
      A4GL_debug ("---> %s %s", A4GL_null_as_null (cdtype),
		  A4GL_null_as_null (csize));
      A4GL_debug ("A4GLSQL_read_columns: Pushing %s %s %s",
		  A4GL_null_as_null (colname), A4GL_null_as_null (cdtype),
		  A4GL_null_as_null (csize));


      cname = strdup (colname);


      trim_spaces (cname);
      push_name (cname, 0);
      push_type (rettype (cdtype), csize, 0);
    }
  A4GL_debug ("ncol=%d\n", ncol);
  if (ncol == 0)
    {

      SPRINTF1 (buff, "%s does not exist in the database", tableName);
      a4gl_yyerror (buff);
      return 1;
    }
  A4GLSQL_end_get_columns ();
  return 0;
}




/**
 * The parser found a variable declared like table.column
 * It needs to go to the database to find the data type in order to do the
 * proper declaration, binds and convertions.
 *
 * @param t2 The table and column (table.column format)
 */
static void
push_like2 (char *t2)
{
  char buff[300];
  char *tableName;
  char *columnName;
  char t[256];
  A4GL_debug ("In push_like2");

  if (A4GL_db_used () == 0)
    {
      SPRINTF0 (buff, "You cannot use LIKE without specifying a database");
      a4gl_yyerror (buff);
      return;
    }

  strcpy (t, t2);
  strcpy (buff, t);
  strcat (buff, ".");

  tableName = strtok (buff, ".");	/* table name */
  columnName = strtok (0, ".");	/* column name */
  A4GL_debug ("a='%s' b='%s'", A4GL_null_as_null (tableName),
	      A4GL_null_as_null (columnName));

  if (columnName)
    {
      pushLikeTableColumn (tableName, columnName);
      return;
    }

  pushLikeAllTableColumns (tableName);
  return;
}


/**
   * The parser found a new variable like table.column.
   *
   * Its gonna be inserted in the variables array.
   *
   * @param t The table and column (table.column format)
   */
void
push_like (char *t)
{

  A4GL_debug (">>>>>> %s\n", A4GL_null_as_null (t));
  push_like2 (t);
  A4GL_debug ("<<<<<<\n");
}




/**
 * The parser found the begining of a new block command
 *
 * Some of the commands are marked in the generated code as a C label.
 * Others (Main, func, report, globals, etc) are just added to the command
 * stack.
 *
 * @param cmd_type The type of the command found:
 */
int
push_blockcommand (char *cmd_type)
{
  int ccnt;
  ccnt = A4GL_get_ccnt ();
  A4GL_debug ("START BLOCK %s", cmd_type);
  A4GL_debug ("\n\n--------->%s\n\n", cmd_type);
  A4GL_debug (" /* new block %s %d */\n", cmd_type, ccnt);
  strcpy (command_stack[ccnt].cmd_type, cmd_type);
  if (strcmp (cmd_type, "MAIN") == 0
      || strcmp (cmd_type, "FUNC") == 0 ||
      strcmp (cmd_type, "REPORT") == 0 || strcmp (cmd_type, "GLOBALS") == 0 ||
      strcmp (cmd_type, "FORMHANDLER") == 0
      || strcmp (cmd_type, "MENUHANDLER") == 0)
    {
      command_stack[ccnt].block_no = -1;
    }
  else
    {
      print_start_block (nblock_no);

      command_stack[ccnt].block_no = nblock_no++;
    }
  A4GL_debug (" Added new block");
  ccnt++;
  file_out_indent (ccnt);
  A4GL_set_ccnt (ccnt);
  return command_stack[ccnt].block_no;
}



/**
 * The parser found a CONTINUE statement.
 *
 * @param cmd_type The type of continue found (the keyword found after
 * the CONTINUE token).
 */
void
add_continue_blockcommand (char *cmd_type)
{
  int a;
  int ccnt;
  ccnt = A4GL_get_ccnt ();

  /* more checks here ! */

  for (a = ccnt - 1; a > 0; a--)
    {
      if (strcmp (command_stack[a].cmd_type, cmd_type) == 0)
	{
	  print_continue_block (command_stack[a].block_no, 0, 0);
	  return;
	}
    }

}


void
continue_blockcommand (char *cmd_type)
{
  int ccnt;
  ccnt = A4GL_get_ccnt ();
  //int a;

  //char err[80];
  print_continue_block (command_stack[ccnt - 1].block_no, 0, cmd_type);
}


/**
 * An end of a block command was ocurred.
 *
 *   - End the block with the necessary command.
 *   - Decrement the increment count.
 *
 * @param cmd_type The type of the block that was ended.
 */
void
pop_blockcommand (char *cmd_type)
{
  int a;
  int ccnt;
  char err[80];
  A4GL_debug ("END BLOCK %s", cmd_type);
  ccnt = A4GL_get_ccnt ();
  /* more checks here ! */

  ccnt--;
  A4GL_set_ccnt (ccnt);
  file_out_indent (ccnt);
  if (command_stack[ccnt].block_no > 0)
    {

      if (iscontinuecmd (cmd_type))
	{
	  print_continue_block (command_stack[ccnt].block_no, 0, cmd_type);
	}
      print_end_block (command_stack[ccnt].block_no);
    }

  A4GL_debug ("\n\n--------->%s\n\n", cmd_type);

  if (strcmp (command_stack[ccnt].cmd_type, cmd_type) == 0)
    {

      command_stack[ccnt].cmd_type[0] = 0;

      return;

    }

  SPRINTF3 (err, "%s was not last block command (I've got a %s @ %d)\n",
	    cmd_type, command_stack[ccnt].cmd_type, ccnt);
  A4GL_debug (err);
  A4GL_debug ("------------------\n");
  for (a = 0; a <= ccnt; a++)
    {
      A4GL_debug ("   %s\n", command_stack[a].cmd_type);
    }
  A4GL_debug ("------------------\n");
  a4gl_yyerror (err);
  //exit (0);
}




/**
 * The parser found a CONTINUE instruction for a specific loop command.
 *
 * One example could be CONTINUE WHILE.
 *
 * The loop commands could be:
 *   - WHILE
 *   - INPUT
 *   - FOREACH
 *   - FOR
 *   - CONSTRUCT
 *   - DISPLAY
 *   - MENU
 *
 *   Finds backwards the opened corresponding command.
 *   This means that if we have a CONTINUE WHILE then it belongs to the
 *   last founded (and not yet closed) WHILE.
 *
 * @param cmd_type The string containing the type name of the loop used
 */
void
continue_loop (char *cmd_type)
{
  int a;
  int g = 0;
  char *internal_cmd_type;
  int ccnt;
  ccnt = A4GL_get_ccnt ();


/* We have to do some messing around here...*/
/* If we want to 'continue input' - we call continue_input("INPUT")*/
/* if we want a next field ... that does the next field bit - then calls continue_input("INPUTREQ")*/
/* Here - we will always be looking for "INPUT" - but pass on the INPUT/INPUTREQ to the print stage...*/
/* Same goes for construct*/


  internal_cmd_type = acl_strdup (cmd_type);

  if (strcmp (cmd_type, "INPUTREQ") == 0)
    strcpy (internal_cmd_type, "INPUT");
  if (strcmp (cmd_type, "CONSTRUCTREQ") == 0)
    strcpy (internal_cmd_type, "CONSTRUCT");

  for (a = ccnt - 1; a >= 0; a--)
    {
      A4GL_debug ("continue_loop:%s %s %s\n", command_stack[a].cmd_type,
		  cmd_type, internal_cmd_type);

      if (strcmp (command_stack[a].cmd_type, internal_cmd_type) == 0)
	{
	  g = 1;
	  break;
	}
    }
  if (g == 0)
    {
      A4GL_debug ("/* wanted to continue a %s but wasnt in one! */",
		  cmd_type);
      return;
    }
  print_continue_loop (command_stack[a].block_no, cmd_type);
}



/**
 * The parser found a EXIT instruction for a specific loop command.
 *
 * One example could be EXIT WHILE.
 *
 * The loop commands could be:
 *   - WHILE
 *   - INPUT
 *   - FOREACH
 *   - FOR
 *   - CONSTRUCT
 *   - DISPLAY
 *   - MENU
 *
 *   Finds backwards the opened corresponding command.
 *   This means that if we have a EXIT WHILE then it belongs to the
 *   last founded (and not yet closed) WHILE.
 *
 * @param cmd_type The string containing the type name of the loop used
 */
void
exit_loop (char *cmd_type)
{
  int a;
  int ccnt;
  int g = 0;
  int printed = 0;
  ccnt = A4GL_get_ccnt ();

  for (a = ccnt - 1; a >= 0; a--)
    {
      A4GL_debug ("exit_loop:%s %s\n", command_stack[a].cmd_type, cmd_type);

      if (strcmp (command_stack[a].cmd_type, cmd_type) == 0)
	{
	  g = 1;
	  break;
	}
    }
  if (g == 0)
    {
      printf ("wanted to exit a %s but wasnt in one!\n", cmd_type);
      A4GL_debug ("/* wanted to exit a %s but wasnt in one! */", cmd_type);
      return;
    }
  if (strcmp (cmd_type, "MENU") == 0)
    {
      print_exit_loop ('M', command_stack[a].block_no,"MENU");
      printed = 1;
    }
  if (strcmp (cmd_type, "PROMPT") == 0)
    {
      print_exit_loop ('P', 0,"PROMPT");
      printed = 1;
    }
  if (printed == 0)
    {
      print_exit_loop (0, command_stack[a].block_no,cmd_type);
    }
}



/**
 * The parse found a new record like table.*
 *
 * @param t The table name
 */
void
push_rectab (char *t)
{
  push_like (t);
}



/*
 * The parser found a new report block
 *
 * @todo Comment the parameters
 *
 * @param why
 * @param whytype
 */
void
push_report_block (char *why, char whytype)
{
  set_curr_block (0);
  strcpy (report_stack[report_stack_cnt].why, why);
  report_stack[report_stack_cnt].whytype = whytype;
  print_repctrl_block ();
  report_stack_cnt++;
  lines_printed = 0;
}


/**
 * Add a report ???
 *
 * @param t
 * @param s1
 * @param s2
 * @param a
 *
 * @return
 */
struct expr_str *
add_report_agg (char t, struct expr_str *s1, struct expr_str *s2, int a,
		long *n)
{
  int rval;
  struct expr_str *x;
  A4GL_debug ("In add_report_agg a=%d\n", a);
  if (use_group)
    {
      sreports[sreports_cnt].in_b = get_curr_block ();
    }
  else
    {
      sreports[sreports_cnt].in_b = 0;
    }

  if (s2 == 0)
    {

      A4GL_debug ("Adding default where on report aggregate of 1");
      sreports[sreports_cnt].rep_where_expr = A4GL_new_literal_long_str ("1");
    }
  else
    {
      A4GL_debug ("Adding non-default where on report aggregate");
      sreports[sreports_cnt].rep_where_expr = s2;
    }


  sreports[sreports_cnt].rep_cond_expr = s1;
  sreports[sreports_cnt].a = a;
  sreports[sreports_cnt].t = t;
  sreports_cnt++;

  rval = print_agg_defines (t, a);
  *n = rval;
  x = A4GL_new_expr_agg (t, a);
  use_group = 0;

  return x;
}





/**
 * Define the error handling after a certain point of the program.
 *
 * @param c The event to be catched:
 *  - WHEN_ERROR:
 *  - WHEN_ANYERROR:
 *  - WHEN_SQLERROR:
 *  - WHEN_WARNING:
 *  - WHEN_SQLWARNING:
 *  - WHEN_NOTFOUND:
 *  - WHEN_SUCCESS:
 *  - WHEN_SQLSUCCESS:
 * @param p The A4GL_action to execute.
 */
void
set_whenever (int c, char *p)
{
  int code;
  int oldcode;
  oldcode = c & 15;
  c = c >> 4;
  c = c << 4;
  code = -1;
  switch (c)
    {
    case WHEN_ERROR:
      set_whenever (WHEN_SQLERROR, p);
      code = A_WHEN_ERROR;
      break;

    case WHEN_ANYERROR:
      set_whenever (WHEN_ERROR, p);
      set_whenever (WHEN_SQLERROR, p);
      code = A_WHEN_ERROR;
      break;

    case WHEN_SQLERROR:
      code = A_WHEN_SQLERROR;
      break;

    case WHEN_WARNING:
      code = A_WHEN_WARNING;
      break;

    case WHEN_SQLWARNING:
      code = A_WHEN_SQLWARNING;
      break;

    case WHEN_NOTFOUND:
      code = A_WHEN_NOTFOUND;
      break;


    case WHEN_SUCCESS:
      code = A_WHEN_SUCCESS;
      break;

    case WHEN_SQLSUCCESS:
      code = A_WHEN_SQLSUCCESS;
      break;
    }

  if (code == -1)
    {
      PRINTF ("Code=%d (%x) to %p\n", c, c, p);
      a4gl_yyerror ("Internal error setting whenever error...");
      exit (0);
    }

  if (p)
    {
      strcpy (when_to[code], p);
    }
  else
    {
      strcpy (when_to[code], when_to_tmp);
    }
  when_code[code] = oldcode;

  A4GL_whenchange(c);

  print_clr_status ();
}





void
set_whenever_from_store (void)
{
char *s;
s=whentostore_p;
if (s==0) {s=when_to_tmp;}
  if (get_whenever_style(whenever_store_c, s)) {
  	set_whento (whentostore_p);
  	set_whenever (whenever_store_c, whenever_store_p);
  }
}




/**
 *  *
 *   *
 *    * @param
 *     */
void
add_ex_dtype (char *sx)
{
  char s[256];
  char ss[256];
  strcpy (s, sx);
  A4GL_trim (s);
  strcpy (s, downshift (s));
  A4GL_debug ("Initializing datatype : %s\n", s);

  A4GLEXDATA_initlib (s);

  A4GL_debug ("Checking if we need an extra include...");

  if (A4GL_has_datatype_function_n (s, "INCLUDE"))
    {
      /* char *(*function) (); */
      char *(*function) (void);
      A4GL_debug ("yep");

      function = A4GL_get_datatype_function_n (s, "INCLUDE");

      A4GL_debug ("function=%s\n", function);

      strcpy (ss, function ());
      print_include (ss);
    }
}



void
do_print_menu_1 (void)
{
  print_menu_1 (get_blk_no ());
  print_menu_1b (get_blk_no ());
}

void
do_print_menu_block_end (int mn)
{
  print_menu_block_end (mn, get_blk_no ());
}




char *
A4GL_CV_print_select_all (char *s,t_binding_comp_list *inbind, t_binding_comp_list *outbind,int used_with_declare)
{
  char *ptr;
  int converted = 0;
  if (A4GL_compile_time_convert ())
    {
      ptr = A4GLSQLCV_check_sql (s, &converted);
    }
  else
    {
      ptr = s;
    }
  return print_select_all_g (ptr, converted,inbind,outbind,used_with_declare);
}




void
print_display_by_name (char *attr, char *Style)
{
  int a;
  char tabname[40];
  char colname[40];

  t_dt_display dt;
  struct expr_str *e;
  struct expr_str_list *l;
  l = A4GL_new_ptr_list (0);
  dt.u_data.field_list = new_field_list ();

  for (a = 0; a < ibindcnt; a++)
    {
      e = A4GL_new_expr_push_variable (ibind[a].varname, ibind[a].dtype);
      l = A4GL_new_append_ptr_list (l, e);

      A4GL_bname (ibind[a].varname, tabname, colname);
      append_field_to_list (dt.u_data.field_list,
			    new_field_entry (colname, "1", 1));
    }

  dt.type = DT_DISPLAY_TYPE_FIELD_LIST;

  print_display_new (l, &dt, attr, Style);
  start_bind ('i', 0);

}


void FGLPARSE_do_print_declare_associate_1(char* variable,char* size,char* n) {
	print_declare_associate_1(variable,size,n);
}



/******************************************************************************/
static void print_local_variables (void)
{
	  int a;

	    A4GL_debug("printing local variables\n");
	      for (a = 0; a < list_local_cnt; a++)
		          {
				        print_variable_new (list_local[a], 'L', 0);
					    }

}


/******************************************************************************/
static void print_class_variables (void)
{
	  int a;

	    for (a = 0; a < list_class_cnt; a++)
		        {
				      print_variable_new (list_class[a], 'C', 0);
				          }
}


/******************************************************************************/
static void print_module_variables (void)
{
	  int a;

	    for (a = 0; a < list_module_cnt; a++)
		        {
				      print_variable_new (list_module[a], 'M', 0);
				          }

}


/******************************************************************************/
void
print_global_variables (void)
{
	  int a;

	    for (a = 0; a < list_imported_global_cnt; a++)
		        {
				      print_variable_new (list_imported_global[a], 'G', 0);

		          }

	if (list_global_cnt) {
		print_start_globals();
	      		for (a = 0; a < list_global_cnt; a++)
		          {
				        print_variable_new (list_global[a], 'g', 0);
		    		}
		print_end_globals();
	}
}






void
print_variables (void)
{

  char scope;

  /* MJA - NEWVARIABLE*/

  A4GL_debug
    ("/**********************************************************/\n");
  A4GL_debug
    ("/******************* Variable definitions *****************/\n");
  A4GL_debug
    ("/**********************************************************/\n");


  scope = get_current_variable_scope ();

  A4GL_debug("Scope=%c\n",scope);

  if (scope == 'l' || scope=='R')
    {
      print_local_variables ();
    }

  if (scope == 'g')
    {
      print_global_variables ();
#ifdef DEBUG
      A4GL_debug ("***** DUMP GVARS ****");
#endif

      if (only_doing_globals ())
        {
          dump_gvars ();
          exit (0);
        }
    }


  if (scope == 'm')
    {
      print_module_variables ();
    }

  if (scope == 'C')
    {
      print_class_variables ();
    }

}



/******************************************************************************/
static char get_current_variable_scope (void)
{
  char scope = 'm';
  int is_inreport=0;
  if (variable_scope=='T') return 'T';

  if (isin_command ("REPORT"))  {
          is_inreport=1;
          if (A4GL_isyes (acl_getenv ("REPORT_VARS_AT_MODULE"))) {
                        is_inreport=0;
                        return 'R';
          } else {
                scope='m';
          }
  }


  if (isin_command ("FUNC") || is_inreport
      || isin_command ("FORMHANDLER") || isin_command ("MENUHANDLER")
      || isin_command ("MAIN"))
    {
      scope = 'l';
    }
  else
    {
      if (variable_scope == 'G')
        { scope = 'G'; }

      if (variable_scope == 'C') // Class
        { scope = 'C'; }

      if (variable_scope == 'P') // Class Parent
        { scope = 'P'; }

      if (variable_scope == 'g')
        { scope = 'g'; }
      if (variable_scope == 'm')
        { scope = 'm'; }
      if (variable_scope == 'R')
        { scope = 'R'; }
    }

  return scope;

}

int A4GL_open_class_dll(char *s) {
	char buff[512];
	FILE *f;
	strcpy(buff,s);
	strcat(buff,acl_getenv("A4GL_DLL_EXT"));
	A4GL_debug("Looking for : %s\n",buff);
	f=A4GL_open_file_classpath(buff);

	if (f) { // We've found our dll...
		        fclose(f);
			        //
			        read_class(s,0);
	} else {
		        return 0;
	}


	return 1;
}


/**
 *  * Gets the C data type corresponding to 4gl data type
 *   *
 *    * @param s A string with the numeric 4gl data type (@see find_type())
 *     * @return The string (static) with the C declaration
 *      */
char * rettype_integer (int n)
{
	  char s[200];

	    /*static char rs[20] = "long";*/
	    /*int a;*/

	    A4GL_debug ("rettype_integer : %d\n", n);

	      SPRINTF1 (s, "%d", n);
	        return rettype (s);
}




void FGLPARSE_A4GL_lexer_import_package(char *s) {
	FILE *f;
	f=A4GL_open_file_classpath(s);
	if (f==0 ) {
		        int ok=0;
			        if (strcmp(s,"default") == 0 ) {
					                // We don't care if this one isn't there...
					                return;
							        }

				        ok=A4GL_open_class_dll(s) ;

					        if (!ok) {
							                a4gl_yyerror("Unable to open package description");
									        }
						        return;
	}
	read_package_contents(f);

}



/******************************************************************************/
/**
 * Identifies the data type from a string and convert it to numeric with
 * the goal of being more easyli used.
 *
 * @todo organize some defines to the data types.
 *
 * @param s The string where the data type will be scanned
 * @return The data type in numeric code
 */

int
FGLPARSE_A4GL_lexer_find_type (char *s)
{
  char errbuff[80];
  static char types[20][80];
  //char buff[20];
  int a;
  //int b;
  static int set_types=0;
  if (set_types==0) {
          for (a=0;a<15;a++) { strcpy(types[a],rettype_integer(a)); }
          set_types=1;
  }

  for (a=0;a<15;a++) {
          if (strcmp(types[a],s)==0) { return a; }
  }

  A4GL_debug ("Looking for type '%s'", s);

  if (A4GL_find_datatype_out (s) != -1)
    {
      A4GL_debug ("Found it...");
      return A4GL_find_datatype_out (s);
    }

  A4GL_debug ("Not found - keep looking");
  A4GL_debug ("find_type %s\n", s);
  if (strcmp ("char", s) == 0) return 0;
  if (strcmp ("long", s) == 0) return 2;
  if (strcmp ("integer", s) == 0) return 1;
  if (strcmp ("int", s) == 0) return 1;
  if (strcmp ("short", s) == 0) return 1;
  if (strcmp ("double", s) == 0) return 3;
  if (strcmp ("float", s) == 0) return 4;
  if (strcmp ("fgldecimal", s) == 0) return 5;
  if (strcmp ("serial", s) == 0) return 6;
  if (strcmp ("fgldate", s) == 0) return 7;
  if (strcmp ("fglmoney", s) == 0) return 8;
  if (strcmp ("struct_dtime", s) == 0) return 10;
  if (strcmp ("fglbyte", s) == 0) return 11;
  if (strcmp ("fgltext", s) == 0) return 12;
  if (strcmp ("varchar", s) == 0) return 13;
  if (strcmp ("struct_ival", s) == 0) return 14;
  if (strcmp ("_RECORD", s) == 0) return -2;
  if (strcmp ("form", s) == 0) return 9;
  if (strcmp ("uiwindow", s) == 0) return 9;
  if (strcmp ("omdomnode", s) == 0) return 9;
  if (strcmp ("omnodelist", s) == 0) return 9;
  if (strcmp ("basechannel", s) == 0) return 9;
  if (strcmp ("string", s) == 0) return 9;
  if (strncmp ("struct _class_struct_", s,21) == 0) { return -3; }
  A4GL_debug ("Invalid type : '%s'\n", s);
  SPRINTF1 (errbuff, "Internal Error (Invalid type : '%s')\n", s);
  a4gl_yyerror (errbuff);
  return 0;
}



void
print_nullify (char type)
{
  int a;
  struct variable **list = 0;
  int list_cnt = 0;


  A4GL_debug ("print_nullify called :%c\n", type);

  A4GL_debug ("AUTONULL ?");


  a = A4GL_isyes (acl_getenv ("AUTONULL"));
  A4GL_debug ("isyes returns %d ", a);

  if (a)
    {
      A4GL_debug ("AUTONULL must be YES");
      if (type == 'M')
        {
          list = list_module;
          list_cnt = list_module_cnt;
        }
      if (type == 'F')
        {
          list = list_local;
          list_cnt = list_local_cnt;
        }
      if (list == 0)
        {
          return;
        }
      start_bind ('N', 0);

      for (a = 0; a < list_cnt; a++)
        {
        int print=0;
        if (list[a]->variable_type != VARIABLE_TYPE_CONSTANT) print=1;
        #ifdef PRINT_CONSTANTS
                print=1;
        #endif

          if (print)
            {
                if (A4GL_isyes(acl_getenv("DOING_CM")) || strcmp(acl_getenv("A4GL_LEXTYPE"),"php")==0) {
                        if (!has_fbind(list[a]->names.name)) {
                                add_bind ('N', list[a]->names.name);
                        }
                } else {
                        add_bind ('N', list[a]->names.name);
                }
            }

        }
      expand_bind (&nullbind[0], 'N', nullbindcnt,0);
      print_init_g (copy_togenbind('N'),0);
    }
  else
    {
      A4GL_debug ("AUTONULL must be NO");
    }

}

void
A4GL_set_clobber (char *c)
{
  char *ptr;
  //char *ptr2;
  ptr = strrchr (c, '/');
  if (ptr)
    {
      strcpy (clobber, ptr + 1);
      return;
    }

  /* Do dos mode ? */
  ptr = strrchr (c, '\\');
  if (ptr)
    {
      strcpy (clobber, ptr + 1);
      return;
    }

  strcpy (clobber, c);
}

int A4GL_is_class_static(char *s) {
	if (strncmp(s,"base.",5)==0) return 1;
	return 0;
}



void print_init_explicit(void) {
	expand_bind (&nullbind[0], 'N', nullbindcnt,0);
        print_init_g(copy_togenbind('N'), 1);
}



void FGLPARSE_A4GL_lexer_parsed_fgl(void) {
	A4GL_lex_parsed_fgl ();
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
  //int ni;

  if (last_var_is_linked (tabname, pklist))
    {
      char buff[80];
      char buff2[80];
      //int no = 0;
      int no_keys;
      int azcnt;

      if (type == 'S')
	{
	  start_bind ('o', 0);
	  sprintf (buff, "%s.*", var);
	  add_bind ('o', buff);
	}

      no_keys = linked_split (pklist, 0, 0);
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
	
      if (type == 'S') sprintf (buff, "SELECT * FROM %s WHERE ", tabname);
      if (type == 'D') sprintf (buff, "DELETE FROM %s WHERE ", tabname);
      if (type == 'U') sprintf (buff, "UPDATE %s SET (%s)=(%s) WHERE ", tabname, get_upd_using_notpk (), get_upd_using_queries ());

      for (azcnt = 1; azcnt <= no_keys; azcnt++)
	{
	  if (azcnt > 1)
	    strcat (buff, "AND");
	  linked_split (pklist, azcnt, buff2);
	  strcat (buff, " ");
	  strcat (buff, buff2);
	  strcat (buff, "=? ");
	}


        if (type == 'S')  {
		print_execute_g(buff,3,copy_togenbind('i'),copy_togenbind('o'));
      	} else {
		print_execute_g(buff,3,copy_togenbind('i'),empty_genbind('o'));
	}
	start_bind('o',0);
	start_bind('i',0);

    }
  else
    {
      return 0;
    }
  return 1;
}

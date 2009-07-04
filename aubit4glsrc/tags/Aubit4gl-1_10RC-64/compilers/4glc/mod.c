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
# $Id: mod.c,v 1.329 2009-07-04 12:40:09 mikeaubury Exp $
#
*/

/**
 * @file
 * It looks like functions to help the parsing of a module (a x4gl one).
 * For that the name mod.c
 *
 * @todo Doxygen comments in all functions
 * @todo static in modular variables
 * @todo const in read only strings
 * @todo -Wmissig-prototypes
 * @todo -Wstrict-prototypes
 * @todo -Wall
 * @todo -pedantic
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_4glc_int.h"
#include "variables.h"
#include "variables_new.h"
#include <ctype.h>
#include "field_handling.h"
#include "parsehelp.h"
#include "a4gl_expr.h"
//#include "fgl.xs.h"
#include <errno.h>
#define GEN_STACK_HERE
extern struct module_definition this_module;
struct s_func_def {
        char *fname;
        char type;
        int rvals;
        int params;
};
struct s_func_def *function_definitions=0;
int nfunction_definitions=0;


#include "a4gl_gen_stack.h"
#define FEATURE_USED            'X'
//char                 hdr_dbname[64]="";

char force_ui[FORCE_UI_SIZE];
char debug_filename[DEBUG_FILENAME_SIZE]="";

extern int a4gl_yydebug;
int             chk4var=0;
char            curr_func[256]="Module";
int isin_formhandler=0;
int sql_mode=0;
//int             is_schema=0;


int             menu_cmd_cnt[MAXMENUOPTS] ={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int             menu_blk[MAXMENU]         ={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

int add_bind_subs (char i, char *var_i, char *sub_start, char *sub_end);
/*
=====================================================================
                    Constants definitions
=====================================================================
*/
char last_orderby_ascdesc=0;
char *order_asc_desc=0;

#define USE_PRINTCOMMENT
#define GEN_STACKS 		10
#define MAXVARS 		2000
#define EMPTY 			"----"
//#define MAXMENU               50
//#define MAXMENUOPTS   50

#define UPDCOL 0
#define UPDVAL 1
#define UPDVAL2 4
#define INSCOL 5
#define INSVAL 6
#define TCOL 7

#define a0_width         (float) 2380.0
#define a0_height        (float) 3368.0
#define a1_width         (float) 1684.0
#define a1_height        (float) 2380.0
#define a2_width         (float) 1190.0
#define a2_height        (float) 1684.0
#define a3_width         (float) 842.0
#define a3_height        (float) 1190.0
#define a4_width         (float) 595.0
#define a4_height        (float) 842.0
#define a5_width         (float) 421.0
#define a5_height        (float) 595.0
#define a6_width         (float) 297.0
#define a6_height        (float) 421.0
#define b5_width         (float) 501.0
#define b5_height        (float) 709.0
#define letter_width     (float) 612.0
#define letter_height    (float) 792.0
#define legal_width      (float) 612.0
#define legal_height     (float) 1008.0
#define ledger_width     (float) 1224.0
#define ledger_height    (float) 792.0
#define p11x17_width     (float) 792.0
#define p11x17_height    (float) 1224.0

int ui_elements = 0;
int arr_ui_elements[2000];
struct s_replacements
{
  char *find;
  char *replace;
};
struct s_replacements *replacements = 0;
int nreplacements = 0;

static void A4GL_set_sql_features (void);
void expand_ordbind2(void ) ;

int A4GL_get_nevents (void);
void A4GL_get_event (int n, int *i, char **s);
//static void set_whento (char *p);
//void set_whento_store(char *p);
//void set_whenever_store (int c, char *p) ;
//void set_whenever_from_store(void) ;
//void A4GL_lex_printh(char* fmt,... );

int nreturn_values = -1;

int A4GL_findex (char *str, char c);
/*void push_validate (char *t2);*/

//int A4GL_get_attr_from_string (char *s);
//char get_curr_report_stack_whytype_1 (void);
char *get_curr_report_stack_why (void);
//char find_variable_scope (char *s_in);
//char *A4GL_get_important_from_clobber (char *s);
//char *A4GLSQLCV_check_sql(char *s) ;
int get_rep_no_orderby (void);
//int get_validate_list_cnt (void);
char *sql_features = 0;
//int get_ccnt(void);
//void set_ccnt(int a);
//int get_block_no (int n);
//struct fh_field_list *new_field_list(void);
//char *A4GL_decode_packtype(char *s) ;

/*
=====================================================================
                    Variables definitions
=====================================================================
*/


//
//void dump_updvals (void);
//void dump_insvals (void);
//char *pop_gen (int a);
/*int gen_cnt (int a);*/
//void copy_gen (int a, int b);
int menu_cnt=0;			/** The count of menus found */
extern int yylineno;			/** The source file line number */
//extern char infilename[];    /** The input (4gl file name */
char             infilename[132];
int in_define=0;
extern int doing_a_print;

static int db_used = 0;		 /** Flag that indicate that a database is being used */
static int inc = 0;
static char pklist[2048] = "";
static char upd_using_notpk[5000] = "";
static int upd_using_notpk_cnt = 0;
char current_upd_table[64]="";
char current_ins_table[256]="";

struct expr_str *menu_attrib_comment=0;
struct expr_str *menu_attrib_style=0;
struct expr_str *menu_attrib_image=0;

/*static int    const_cnt = 0;*/

int rep_type = REP_TYPE_NOTSET;	      /** The report type */

/*int           last_var_found = -1;*/

/*int           var_hdr_finished;*/
//int isin_command (char *cmd_type);



int lines_printed = 0;

int lines_printed_true = 0;
int lines_printed_false = 0;

static int push_construct_table (char *tableName);

char when_to_tmp[64] = "";
char when_to[8][128] = { "", "", "", "", "", "", "", "" };
int menu_nos[100];
int cmenu = 0;
int use_group = 0;
char curr_rep_name[256];
int curr_rep_block;
int max_menu_no = 0;
struct s_report sreports[SREPORTS_SIZE];
int sreports_cnt = 0;
char mmtitle[132][132];				/** Menu titles */
extern char *outputfilename;			/** Variables A4GL_dump output file name */
int read_glob_var = 0;
int counters[256];
int count_counters = 0;
struct s_report_stack report_stack[REPORTSTACKSIZE];
int report_stack_cnt = 0;
int report_cnt = 1;
int nblock_no = 1;

/******************************************************************************/
int with_page_length=-1;
int with_left_margin=-1;
int with_right_margin=-1;
int with_top_margin=-1;
int with_bottom_margin=-1;
char *with_top_of_page="";
int table_cnt=0;
char            menuhandler[256];
char            last_var [256];
char            larr[4096]="";
char            larr2[4096]="";
char            clobber[64]="";
char            dtypelist[2048];
char            where_having[1024];
char            menu[2048];
char            varstring[100];
char            current_del_table[64]="";
// int             rordcnt;
int             racnt=0;
int             ccode=0;
int             errbomb=0;
int             glob_only=0;
int             inp_flags=0;
int             lcnt;
int             vcnt;
int             rcnt;
int             lastlineno=0;
int             cnt;
int             inrec=0;
int             iskey=0;
int             insql=0;
int             in_sql=0;
int             continue_cmd[]={0,1,1,1,1,1,1,1,1,0};
int             in_cmd[]={0,0,0,0,0,0,0,0,0,0};
int             fcall_cnt=0;
int             doing_declare=0;
int             message_cnt=0;
int             doing_a_print=0;
char mv_parent_class[255];
char *last_style=0;
char *last_text=0;
char *into_temp_clause=0;
struct          rep_structure rep_struct;
struct          pdf_rep_structure pdf_rep_struct;
struct          form_attr form_attrib;
/* struct          input_array_attribs curr_input_array_attribs; */
//int             if_print_stack[100][2];
//int     if_print_stack_cnt=0;
//int     if_print_section[100]={0,0,0,0};
char    last_tmp_name[256]="";

/******************************************************************************/

/*#define GEN_STACK_SIZE 5000*/
#define GEN_STACK_SIZE 10000




struct s_constr_buff constr_buff[256];
int constr_cnt = 0;



/**
 * Input bind array.
 *
 * Used for instructions like execute using or open using wher we have a list 
 * of variables that act as input for the statement.
 */
//struct binding_comp *ibind = 0;	//[NUMBINDINGS];
//long a_ibind = 0;
//struct binding_comp *nullbind = 0;	//[NUMBINDINGS];
//long a_nullbind = 0;

/**
 * Output bind array.
 */
//struct binding_comp *obind = 0;	//[NUMBINDINGS];
//long a_obind = 0;
//struct binding_comp *fbind = 0;	//[NUMBINDINGS];
//long a_fbind = 0;
//struct binding_comp *ebind = 0;	//[NUMBINDINGS];
//long a_ebind = 0;
//struct binding_comp *ordbind = 0;	//[NUMBINDINGS];
//long a_ordbind = 0;
//
//int ordbindcnt = 0;
//int ibindcnt = 0;			/** Number of elements in ibind array */
//int nullbindcnt = 0;
//int obindcnt = 0;
//int fbindcnt = 0;
//int ebindcnt = 0;




//struct binding_comp *ensure_bind (long *a_bindp, long need, struct binding_comp *b);
//struct binding_list *new_bind_list (char *s);
//struct binding_list *append_bind_list (struct binding_list *l, char *s);

/**
 * Module current scope level for variable declaration.
 *
 * It contains:
 *   - -1  : Global variables
 *   - 0   : Modular variables
 *   - > 0 : Function local variables
 */
int modlevel = -1;

/** Command stack array */
struct cmds command_stack[CMD_STACK_SIZE];

//extern int ccnt;		/* in lexer.c */


/** Array index to the last variable filled in the variables array  */




//int in_record = 0;
struct s_menu_stack menu_stack[MAXMENU][MAXMENUOPTS];	       /** The menu stack array */

int has_default_database (void);
char *get_default_database (void);

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/
//char *rettype (char *s);
int yywrap (void);
struct sreports *get_sreports (int z);
void a4gl_add_variable (char *name, char *type, char *n);
static void push_validate_column (char *tabname, char *colname);

//char *get_namespace (char *s);
char *make_sql_string_and_free (char *first, ...);
char *pg_make_sql_string_and_free (char *first, ...);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/






int
A4GL_db_used (void)
{
  return db_used;
}


/**
 * Strips square brackets "[]" from a string at leaves it just as it was.
 * 
 * @param buff The original string to be stripped
 * @return static buffer with string stripped
 */
/*
static char *
with_strip_bracket (const char *buff)
{
  static char bff[256];
  A4GL_debug ("with_strip_bracket\n");
  strcpy (bff, buff);
  strip_bracket (bff);
  return bff;
}
*/



/**
 * Clear the variable stack by setting the counter to zero.
 */
void
clr_variable (void)
{
  /* Does nothing */
}

/**
 *
 */
void
inmod (void)
{
  /* Does nothing */
}

/**
 * Check if the current state of the compiler is inside a command.
 *
 * Used to see what should be the scope of declarations and usages.
 *
 * Compare the parameter with the string with command type stored in
 * the command stack.
 *
 * @param cmd_type The command type
 * @return
 *   - 0 : We are NOT in command type
 *   - 1 : We are in command type
 */
int
isin_command (char *cmd_type)
{
  int z;
  int ccnt;
  ccnt=A4GL_get_ccnt();
  if (ccnt== 0)
    {
      return 0;
    }

  for (z = ccnt - 1; z >= 0; z--)
    {
      if (command_stack[z].cmd_type == 0 || command_stack[z].cmd_type[0] == 0)
	continue;

      if (strcmp (command_stack[z].cmd_type, cmd_type) == 0)
	{
	  A4GL_debug ("OK\n");
	  return z + 1;
	}
    }
  return 0;
}


char *
command_type_for_stack_pos (int n)
{
  return command_stack[n].cmd_type;
}

/**
 * This function gets the last command of type s
 * and returns the an ID for it - this is just the stack position - but
 * later maybe made into something unique for a module
 * This ensures that we can have lots of concurrent _sio's running...
 * (prompts within inputs etc)
 * @param cmt_type - Command type to look for ("ALL" for any sio based command, "ALLINPUT" to exclude display array)
 * @return stack ID
**/

int
get_sio_id (char *cmd_type)
{
  int stack_ids[10];
  int a;
  int max_id = 0;
  int anymode = 0;
  int ccnt;
  ccnt=A4GL_get_ccnt();
  for (a = 0; a < 10; a++)
    stack_ids[a] = 0;
/* Are we looking for anything ? */
  if (strcmp (cmd_type, "ALL") == 0)
    {
      anymode = 1;
    }
  if (strcmp (cmd_type, "ALLINPUT") == 0)
    {
      anymode = 2;
    }
  if (anymode)
    {				/* used for getfldbuf etc */
      stack_ids[0] = isin_command ("INPUT");
      stack_ids[1] = isin_command ("CONSTRUCT");
      if (anymode != 2)
	stack_ids[2] = isin_command ("DISPLAY");

      for (a = 0; a < 3; a++)
	{
	  if (stack_ids[a] > max_id)
	    max_id = stack_ids[a];
	}
      return max_id;
    }

  a = isin_command (cmd_type);
  if (a == 0)
    {
      int z;
      PRINTF ("Looking for cmd_type = %s - not found\n", cmd_type);
      for (z = ccnt - 1; z >= 0; z--)
	{
	  if (command_stack[z].cmd_type == 0
	      || command_stack[z].cmd_type[0] == 0)
	    continue;
	  PRINTF ("%d %s\n", z, command_stack[z].cmd_type);
	}
      a4gl_yyerror ("Internal error - unable to find sio_id for command");
      return 0;
    }
  return a;

}




/**
 * Print the declaration of a record.
 *
 * @param z The variable index in the array.
 * @param ff The scope of the record variable:
 *   - -
 *   - G
 * @param vname The record variable name
 */

/**
 * Increment the variable inc by a value.
 *
 * @param a The increment.
 */
void
setinc (int a)
{
  inc += a;
}




/**
 *
 * @param mn
 * @param mnopt
 * @param a
 * @param b
 * @param c
 * @param hlp
 */
void
push_command (int mn, int mnopt, char *a, char *b, char *c, char *hlp)
{

  A4GL_debug ("Menu %d Option %d '%s'", mn, mnopt, A4GL_null_as_null (b));
  A4GL_assertion (mn >= MAXMENU, "Ran out of menu spaces");
  A4GL_assertion (mnopt >= MAXMENUOPTS, "Ran out of option slots");
  strcpy (menu_stack[mn][mnopt - 1].menu_title, b);
  strcpy (menu_stack[mn][mnopt - 1].menu_help, c);
  strcpy (menu_stack[mn][mnopt - 1].menu_key, a);
  if (hlp)
    menu_stack[mn][mnopt - 1].menu_helpno = atoi (hlp);
  else
    menu_stack[mn][mnopt - 1].menu_helpno = 0;

  menu_stack[mn][mnopt].menu_title[0] = 0;
  menu_stack[mn][mnopt].menu_help[0] = 0;
  menu_stack[mn][mnopt].menu_key[0] = 0;
  menu_stack[mn][mnopt].idle_interval = 0;
  menu_stack[mn][mnopt].timeout_val = 0;
  menu_stack[mn][mnopt].action[0] = 0;
}


void
push_menu_action (int mn, int mnopt, char *s)
{
  strcpy (menu_stack[mn][mnopt - 1].menu_title, "\"\"");
  strcpy (menu_stack[mn][mnopt - 1].menu_help, "\"\"");
  strcpy (menu_stack[mn][mnopt - 1].menu_key, "");
  menu_stack[mn][mnopt - 1].menu_helpno = 0;
  menu_stack[mn][mnopt - 1].idle_interval = 'A';
  strcpy (menu_stack[mn][mnopt - 1].action, s);


  menu_stack[mn][mnopt].menu_title[0] = 0;
  menu_stack[mn][mnopt].menu_help[0] = 0;
  menu_stack[mn][mnopt].menu_key[0] = 0;
  menu_stack[mn][mnopt].idle_interval = 0;
  menu_stack[mn][mnopt].timeout_val = 0;
  menu_stack[mn][mnopt].action[0] = 0;
}

void
push_menu_timeout (int mn, int mnopt, char *s)
{
  strcpy (menu_stack[mn][mnopt - 1].menu_title, "\"\"");
  strcpy (menu_stack[mn][mnopt - 1].menu_help, "\"\"");
  strcpy (menu_stack[mn][mnopt - 1].menu_key, "\"\"");
  menu_stack[mn][mnopt - 1].menu_helpno = 0;
  menu_stack[mn][mnopt - 1].idle_interval = s[0];
  menu_stack[mn][mnopt - 1].timeout_val = atol (&s[2]);

  menu_stack[mn][mnopt].menu_title[0] = 0;
  menu_stack[mn][mnopt].menu_help[0] = 0;
  menu_stack[mn][mnopt].menu_key[0] = 0;
  menu_stack[mn][mnopt].idle_interval = 0;
  menu_stack[mn][mnopt].timeout_val = 0;
  menu_stack[mn][mnopt].action[0] = 0;
}



/**
 * Obtain the value of the inc variable.
 *
 * @return The content of the inc variable.
 */
int
getinc (void)
{
  return inc;
}

/**
 * Find a character in a string.
 *
 * @param str The string where to find the caracter
 * @param c The character to be found in a string
 * @return
 *   - The index of the character if found in the string
 *   - 0 if not found
 */
int
A4GL_findex (char *str, char c)
{
  int a;
  for (a = 0; a < strlen (str); a++)
    {
      if (str[a] == c)
	return a;
    }
  return 0;
}




/**
 * Set the internal 4gl variables in the array.
 */
void
set_4gl_vars (void)
{
struct variable_list *vlist=NULL;

struct variable_list *vl_sqlca=NULL;
struct variable *v_sqlerrd;
struct variable *v_sqlca;

  set_current_variable_scope (E_SCOPE_IMPORTED_GLOBAL);
  set_variable_user_system('S');

  vlist=new_variable_list(NULL);

  append_variable_list(vlist, new_simple_variable("int_flag",DTYPE_INT,0,0));
  append_variable_list(vlist, new_simple_variable("quit_flag",DTYPE_INT,0,0));
  append_variable_list(vlist, new_simple_variable("a4gl_status",DTYPE_INT,0,0));
  append_variable_list(vlist, new_simple_variable("time",DTYPE_CHAR,8,0));

// We first need to create a variable list - this will be the contents of the SQLCA record...
  vl_sqlca=new_variable_list(NULL);
  append_variable_list(vl_sqlca, new_simple_variable("sqlcode",DTYPE_INT,0,0));
  append_variable_list(vl_sqlca, new_simple_variable("sqlerrm",DTYPE_CHAR,72,0));
  append_variable_list(vl_sqlca, new_simple_variable("sqlerrp",DTYPE_CHAR,8,0));


  // Slightly more complicated for an array - we need to set it up manually..
  v_sqlerrd=new_simple_variable("sqlerrd",DTYPE_INT,0,0);
  v_sqlerrd->arr_subscripts.arr_subscripts_len=1; /* Its a 1 dimensional array */
  v_sqlerrd->arr_subscripts.arr_subscripts_val=malloc(sizeof(int)*1);
  v_sqlerrd->arr_subscripts.arr_subscripts_val[0]=6; /* And its got 6 elements */
  append_variable_list(vl_sqlca, v_sqlerrd);

  // Now back to the simple stuff..
  append_variable_list(vl_sqlca, new_simple_variable("sqlawarn",DTYPE_CHAR,8,0));
  append_variable_list(vl_sqlca, new_simple_variable("sqlstate",DTYPE_CHAR,9,0));
  v_sqlca=new_variable_record("a4gl_sqlca", vl_sqlca);
  append_variable_list(vlist,v_sqlca);



  append_variable_list(vlist, new_constant('i', "100","notfound" ));
  append_variable_list(vlist, new_constant('i', "1","true" ));
  append_variable_list(vlist, new_constant('i', "0","false" ));

  append_variable_list(vlist, new_simple_variable("today",DTYPE_DATE,0,0));
  append_variable_list(vlist, new_simple_variable("fgl_user",DTYPE_CHAR,8,0));
  append_variable_list(vlist, new_simple_variable("pageno",DTYPE_INT,0,0));
  append_variable_list(vlist, new_simple_variable("lineno",DTYPE_INT,0,0));

  append_variable_list(vlist, new_simple_variable("usrtime",DTYPE_INT,0,0));

  append_variable_list(vlist, new_simple_variable("curr_hwnd",DTYPE_INT,0,0));
  append_variable_list(vlist, new_simple_variable("curr_form",DTYPE_INT,0,0));
  append_variable_list(vlist, new_simple_variable("err_file_name",DTYPE_CHAR,32,0));
  append_variable_list(vlist, new_simple_variable("err_line_no",DTYPE_INT,0,0));

  append_variable_list(vlist, new_simple_variable("curr_file_name",DTYPE_CHAR,32,0));
  append_variable_list(vlist, new_simple_variable("curr_line_no",DTYPE_INT,0,0));

  append_variable_list(vlist, new_simple_variable("err_status",DTYPE_INT,0,0));
  append_variable_list(vlist, new_simple_variable("aiplib_status",DTYPE_INT,0,0));

  // When we've got to here - 'vlist' contains all our system variables...
  merge_variable_list(&this_module.imported_global_variables,vlist);
  set_variable_user_system('-');

  set_current_variable_scope (E_SCOPE_MODULE);
  
 
}

/**
 * Open a database.
 *
 * Called by the parser when found the 4gl DATABASE statement.
 *
 * @param s The database name
 */
void
open_db (char *s)
{
  char db[2048];
  char buff[256];

  A4GL_debug ("open_db %s", A4GL_null_as_null (s));
  strcpy (db, s);

  if (has_default_database ())
    {
      strcpy (db, get_default_database ());
      A4GL_debug ("Overriding default database with %s",
		  A4GL_null_as_null (db));
      A4GL_trim (db);
    }

  A4GL_set_status (0, 1);
  A4GL_init_connection (db);
  if (A4GL_get_status () != 0)
    {
      SPRINTF2 (buff, "Could not connect to database %s (%s)",
	       A4GL_null_as_null (db),
	       A4GL_null_as_null (A4GLSQL_get_sqlerrm ()));
      a4gl_yyerror (buff);
    }
  if (db_used == 0)
    db_used = 1;
}





#include "trim_spaces.h"




static int
pushValidateTableColumn (char *tableName, char *columnName)
{
  int rval;
  int idtype;
  int isize;
  /*char csize[20]; */
  /*char cdtype[20]; */
  char buff[300];

  A4GL_debug ("pushValidateTableColumn()");
  rval = A4GL_read_columns (tableName, columnName, &idtype, &isize);
  if (rval == 0)
    {
      SPRINTF2 (buff, "%s.%s does not exist in the database", tableName,
	       columnName);
      a4gl_yyerror (buff);
      return 0;
    }
  trim_spaces (columnName);
  push_validate_column (tableName, columnName);
  return 1;
}

static int
pushValidateAllTableColumns (char *tableName)
{
  int rval;
  int isize = 0;
  int idtype = 0;
  char colname[256] = "";
  /*char csize[20]; */
  /*char cdtype[20]; */
  char buff[300];
  char *ccol;

  A4GL_debug ("pushValidateAllTableColumns()");


  A4GL_debug ("Calling get_columns : %s\n", A4GL_null_as_null (tableName));

  rval = A4GLSQL_get_columns (tableName, colname, &idtype, &isize);

  A4GL_debug ("rval = %d", rval);
  if (rval == 0 && tableName)
    {
      SPRINTF1 (buff, "%s does not exist in the database", tableName);
      a4gl_yyerror (buff);
      A4GLSQL_end_get_columns ();
      return 1;
    }

  A4GL_debug ("Rval !=0");

  while (1)
    {
      colname[0] = 0;

      rval = A4GLSQL_next_column (&ccol, &idtype, &isize);

      /*
         warning: passing arg 1 of `A4GLSQL_next_column' from incompatible pointer type
         we are sending char ARRAY to function expecting char POINTER !!!!
       */

      if (rval == 0)
	break;

      strcpy (colname, ccol);

      A4GL_debug ("next column for table '%p' is '%p'", tableName, ccol);
      A4GL_debug ("next column for table '%s' is '%s'",
		  A4GL_null_as_null (tableName), A4GL_null_as_null (ccol));

      trim_spaces (colname);
      push_validate_column (tableName, colname);

    }
  A4GLSQL_end_get_columns ();
  return 0;
}



void
push_validate (char *t2)
{
  char buff[300];
  char *tableName;
  char *columnName;
  char t[256];
  A4GL_debug ("In push_validate");


/* Skip any owner bit...*/
  if (t2[0] == '\\' && t2[1] == '"')
    {
      char *x;
      x = strchr (t2, '.');
      if (x)
	{
	  t2 = x + 1;
	}
    }



  if (db_used == 0)
    {
      SPRINTF0 (buff, "You cannot use VALIDATE without specifying a database");
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

  if (columnName && strcmp (columnName, "*") != 0)
    {
      pushValidateTableColumn (tableName, columnName);
      return;
    }

  pushValidateAllTableColumns (tableName);
  return;
}






/**
 * Insert a new menu title in the menu titles array.
 *
 * The parser have found a new menu.
 *
 * @param s The title of the menu
 */
void
push_menu_title (char *s)
{
  strcpy (mmtitle[menu_cnt], s);
}


/**
 *
 * @param cmd_type
 */
int
in_command (char *cmd_type)
{

	int ccnt;
  int z;
  char buff[255];
ccnt=A4GL_get_ccnt();
  A4GL_debug ("Check for %s %d \n", cmd_type, ccnt);

  if (ccnt == 0)
    {
      A4GL_debug ("Stack is empty\n");
      return 0;
    }

  for (z = ccnt - 1; z >= 0; z--)
    {

      if (command_stack[z].cmd_type == 0 || command_stack[z].cmd_type[0] == 0)
	continue;

      if (strcmp (command_stack[z].cmd_type, cmd_type) == 0)
	{
	  A4GL_debug ("OK\n");
	  return 1;
	}
    }

  //PRINTF ("Not in a %s command\n", cmd_type);
  SPRINTF1 (buff,
	   "Can't exit/continue '%s' command (because you're not in one)",
	   cmd_type);
  a4gl_yyerror (buff);

  return 0;
}


/**
 * Trim the New Line at the end of a string.
 * 
 * @param s The string to be trimmed
 */
/* in funcs_d.c :

void 	trim				(char *p);

static void
trim(char *s)
{
  if (s[strlen (s) - 1] == '\n')
    s[strlen (s) - 1] = 0;
}

*/



int
get_block_no (int n)
{
  return command_stack[n].block_no;
}


/**
 *
 *
 * @param
 */
void
set_curr_block (int a)
{
	//printf("Setting block=%d\n",a);
  curr_rep_block = a;
}




/**
 *
 *
 * @param
 */
/*
static
get_curr_rep ()
{
  return report_cnt;
}
*/

/**
 * Initializes a new report structurem where some information about it
 * is stored.
 *
 * @param rep The report structure pointer
 */
void
init_report_structure (struct rep_structure *rep)
{
  memset(rep,0,sizeof(struct rep_structure));

  rep->top_margin = 3;
  rep->bottom_margin = 3;
  rep->left_margin = 5;
  rep->right_margin = 132;
  rep->page_length = 66;
  rep->page_no = 0;
  rep->printed_page_no = 0;
  rep->line_no = 0;
  rep->col_no = 0;
  rep->output_mode = '-';
  rep->lines_in_header = 0;
  rep->lines_in_first_header = 0;
  rep->lines_in_trailer = 0;
  strcpy(rep->top_of_page,"");
  rep->output_loc=0;
}


void
pdf_init_report_structure (struct pdf_rep_structure *rep)
{
  A4GL_debug ("ZZ1 init structure...");
  rep->top_margin = -36.0;
  rep->bottom_margin = -36.0;
  rep->left_margin = -36.0;

  rep->page_length = -842.0;	/* A4 */
  rep->page_width = -595.0;	/* A4 */

  rep->right_margin = rep->page_width - (2 * rep->left_margin);
  rep->bluebar_style=E_BLUEBAR_NONE;
  rep->bluebar_r=0.9;
  rep->bluebar_g=0.9;
  rep->bluebar_b=1.00;
  rep->page_no = 0;
  rep->printed_page_no = 0;
  rep->line_no = 0.0;
  rep->col_no = 0.0;
  rep->output_mode = 'F';
  rep->font_size = 10;
  rep->paper_size = 0;
  rep->lines_in_header = 0;
  rep->lines_in_first_header = 0;
  rep->lines_in_trailer = 0;
  strcpy (rep->font_name, "\"Helvetica\"");
  rep->output_loc=0;
}

/**
 *
 *
 * @param
 */
void
resize_paper (struct pdf_rep_structure *pdf_rep_struct)
{
  int portrait = 1;
  float a;

  A4GL_debug ("ZZ1 Fixing paper size.....");

  if (pdf_rep_struct->paper_size != 0)
    {

      if (pdf_rep_struct->paper_size < 0)
	{
	  portrait = 0;
	  pdf_rep_struct->paper_size = 0 - pdf_rep_struct->paper_size;
	}

      switch (pdf_rep_struct->paper_size)
	{
	case 1:
	  pdf_rep_struct->page_length = 0 - a4_height;
	  pdf_rep_struct->page_width = 0 - a4_width;
	  break;
	case 2:
	  pdf_rep_struct->page_length = 0 - letter_height;
	  pdf_rep_struct->page_width = 0 - letter_width;
	  break;
	case 3:
	  pdf_rep_struct->page_length = 0 - legal_height;
	  pdf_rep_struct->page_width = 0 - legal_width;
	  break;

	case 4:		/* Not used.... */
	  pdf_rep_struct->page_length = 0 - a4_height;
	  pdf_rep_struct->page_width = 0 - a4_width;
	  break;

	case 5:
	  pdf_rep_struct->page_length = 0 - a5_height;
	  pdf_rep_struct->page_width = 0 - a5_width;
	  break;

	}
    }


  if (portrait == 0)		/* Its landscape - swap it around.... */
    {
      a = pdf_rep_struct->page_length;
      pdf_rep_struct->page_length = pdf_rep_struct->page_width;
      pdf_rep_struct->page_width = a;
    }

}




/**
 *
 *
 * @param
 */
void
reset_attrib (struct form_attr *form_attrib)
{
  A4GL_debug ("Reseting attributes\n");
  form_attrib->iswindow = 0;

  form_attrib->attrib = 0xffff;

  form_attrib->form_line = 0xff;
  form_attrib->error_line = 0xff;
  form_attrib->comment_line = 0xff;
  form_attrib->message_line = 0xff;
  form_attrib->prompt_line = 0xff;
  form_attrib->menu_line = 0xff;

  form_attrib->border = 0;
}


/**
 *
 *
 * @param
 */
int
attr_code (char *s)
{

  A4GL_debug ("Decoding colour %s\n", s);

  return A4GL_get_attr_from_string (s);

}

/**
 * Breaks the file name to take the file name without extension and dir name
 *
 * Its used to separate column names from tablename too.
 *
 * This function is repeated in severall places.
 *
 * @param str The file name
 * @param str1 A pointer to the place where to return the left part.
 * @param str2 A pointer to the place where to return the right part.
 */
/*
static
A4GL_bname (char *str, char *str1, char *str2)
{
  char fn[132];
  int a;
  char *ptr;
  strcpy (fn, str);
  for (a = strlen (fn); a >= 0; a--)
    {
      if (fn[a] == '.')
	{
	  fn[a] = 0;
	  break;
	}
    }
  ptr = &fn[a];
  strcpy (str1, fn);
  if (a >= 0)
    strcpy (str2, ptr + 1);
  else
    str2[0] = 0;
}
*/

/**
 * Not Used
 */
/*
static
get_single_key (char *s)
{
  char buff[2];
  s[0] = s[1];
  s[1] = 0;
}
*/

/**
 *
 *
 * @param
 */
void
set_mod_level (int a)
{
  modlevel = a;
}


/**
 *
 *
 * @param
 */
void
drop_counter (void)
{
  count_counters--;
}

/**
 *
 *
 * @param
 */
void
new_counter (void)
{
  count_counters++;
  counters[count_counters] = 0;
}

/**
 *
 *
 * @param
 */
int
get_counter_val (void)
{
  A4GL_debug ("/* get_counter_val =  %d counter number %d*/\n",
	      counters[count_counters], count_counters);
  return counters[count_counters];
}

/**
 *
 *
 * @param
 */
int
inc_counter (void)
{
  return ++counters[count_counters];
}

/**
 *
 *
 * @param
 */
int
dec_counter (void)
{
  return --counters[count_counters];
}

/**
 *
 *
 * @param
 */
void
reset_counter (void)
{
  counters[count_counters] = 0;
}

/**
 *
 *
 * @param
 */
void
set_counter (int a)
{
  counters[count_counters] = a;
}

/**
 *
 *
 * @param
 */
void
inc_counter_by (int a)
{
  counters[count_counters] += a;
  A4GL_debug ("/* inc_by =  %d counter number %d*/\n",
	      counters[count_counters], count_counters);
}

/**
 *
 *
 * @param
 */
/*
static void
dec_counter_by (int a)
{
  counters[count_counters] -= a;
}
*/





cons_list* append_constr_col_list(struct cons_list *c ,struct cons_list_entry *new_entry) {
	if (c==0) {
                c=malloc(sizeof(cons_list));
		c->list.list_len=0;
		c->list.list_val=0;
        }

	if (strcmp(new_entry->colname,"*")==0) {
  		int rval;
  		int isize = 0;
  		int idtype = 0;
  		char colname[256] = "";
  		/*char csize[20]; */
  		/*char cdtype[20]; */
  		char buff[300];
  		char *ccol;
		struct cons_list_entry *generated_new_entry;

  		A4GL_debug ("push_construct_table()");
  		A4GL_debug ("Calling get_columns : %s\n", new_entry->tabname);
  		rval = A4GLSQL_get_columns (new_entry->tabname, colname, &idtype, &isize);
  		A4GL_debug ("rval = %d", rval);
  		if (rval == 0 && new_entry->tabname) {
      			SPRINTF1 (buff, "%s does not exist in the database", new_entry->tabname);
      			a4gl_yyerror (buff);
      			A4GLSQL_end_get_columns ();
      			return 0;
    		}
  		A4GL_debug ("Rval !=0");

  		while (1) {
      			colname[0] = 0;

      			rval = A4GLSQL_next_column (&ccol, &idtype, &isize);
			
      			strcpy (colname, ccol);
      			A4GL_trim (colname);
      			/*
         			warning: passing arg 1 of `A4GLSQL_next_column' from incompatible pointer type
         			we are sending char ARRAY to function expecting char POINTER !!!!
       			*/
			
      			if (rval == 0)
				break;
			generated_new_entry=malloc(sizeof(struct cons_list_entry));
			generated_new_entry->tabname=new_entry->tabname;
			generated_new_entry->colname=strdup(colname);
      			append_constr_col_list (c, generated_new_entry);
    			}
  		A4GLSQL_end_get_columns ();

	} else {
		c->list.list_len++;
		c->list.list_val=realloc( c->list.list_val, sizeof(c->list.list_val[0])* c->list.list_len);
		c->list.list_val[c->list.list_len-1]=new_entry;
	}

	return c;
}



/**
 *
 *
 * @param
 */
void
push_construct (char *a, char *b)
{
  if (strcmp (b, "*") == 0)
    {
      push_construct_table (a);
    }
  else
    {
      strcpy (constr_buff[constr_cnt].tab, a);
      strcpy (constr_buff[constr_cnt].col, b);
      constr_cnt++;
    }
}




static int
push_construct_table (char *tableName)
{
  int rval;
  int isize = 0;
  int idtype = 0;
  char colname[256] = "";
  /*char csize[20]; */
  /*char cdtype[20]; */
  char buff[300];
  char *ccol;

  A4GL_debug ("push_construct_table()");
  A4GL_debug ("Calling get_columns : %s\n", tableName);
  rval = A4GLSQL_get_columns (tableName, colname, &idtype, &isize);
  A4GL_debug ("rval = %d", rval);
  if (rval == 0 && tableName)
    {
      SPRINTF1 (buff, "%s does not exist in the database", tableName);
      a4gl_yyerror (buff);
      A4GLSQL_end_get_columns ();
      return 1;
    }

  A4GL_debug ("Rval !=0");

  while (1)
    {
      colname[0] = 0;

      rval = A4GLSQL_next_column (&ccol, &idtype, &isize);
      A4GL_debug ("next column for table '%p' is '%p'", tableName, ccol);
      A4GL_debug ("next column for table '%s' is '%s'", tableName, ccol);

      strcpy (colname, ccol);
      A4GL_trim (colname);
      /*
         warning: passing arg 1 of `A4GLSQL_next_column' from incompatible pointer type
         we are sending char ARRAY to function expecting char POINTER !!!!
       */

      if (rval == 0)
	break;

      push_construct (tableName, colname);
    }
  A4GLSQL_end_get_columns ();
  return 0;
}


/**
 *
 *
 * @param
 */
void
reset_constr (void)
{
  constr_cnt = 0;
}


/**
 *
 *
 * @param
 */
char *
convstrsql (char *s)
{
  static char buff[1024];
  int a;
  int b = 0;
  A4GL_debug ("Convstrsql ... %s", s);
  for (a = 0; a <= strlen (s); a++)
    {
      if (s[a] == '"')
	{
	  if (a == 0 || (s[0]=='"' && a==strlen(s)-1)) {
	    buff[b++] = '\'';
	  }
	  else
	    {
	      if (s[a - 1] != '\\')
		{
		  buff[b++] = '\'';
		} else {
	  	  buff[b++] = '"';
		}
	    }
	  continue;
	}
      if (s[a] == '\'')
	{
	  buff[b++] = '\'';
	  buff[b++] = '\'';
	  continue;
	}
      buff[b++] = s[a];

    }
  A4GL_debug ("Convstrsql ... %s => %s", s, buff);
  return buff;
}


/**
 * Obtain the current report block.
 *
 * @return The current block.
 */
int
get_curr_block (void)
{
  return curr_rep_block;
}



/**
 * Generate the name for the current report.
 *
 * It is generated with an aubit4gl specific namespace.
 *
 * @param s The name of the report in the 4gl source
 */
void
set_curr_rep_name (char *s)
{
  strcpy (curr_rep_name, (char *) get_namespace (s));
  strcat (curr_rep_name, s);
}

/**
 * Obtain the current report name.
 *
 * @return The name of the report.
 */
char *
get_curr_rep_name (void)
{
  return curr_rep_name;
}

/**
 * Assigns the flag that tells that we are inside a group.
 */
void
set_ingroup (void)
{
  use_group = 1;
}


char *whentostore_p = 0;
int whenever_store_c = 0;
char *whenever_store_p = 0;



void
set_whento_store (char *p)
{
//printf("p=%s\n",p);
  if (p)
    whentostore_p = acl_strdup (p);
  else
    whentostore_p = 0;
}



/**
 *
 */
void
set_whento (char *p)
{
  A4GL_debug ("whento = %p", p);
  strcpy (when_to_tmp, p);
}

void
set_whenever_store (int c, char *p)
{
//printf("WHEN %d %s\n",c,p);
  whenever_store_c = c;
  if (p)
    whenever_store_p = acl_strdup (p);
  else
    whenever_store_p = 0;
}




/**
 *
 *
 * @param
 */
int
npush_menu (void)
{
  max_menu_no++;
  cmenu++;
  menu_nos[cmenu] = max_menu_no;
  A4GL_debug ("Menu no %d", max_menu_no);
  return max_menu_no;
}

/**
 *
 *
 * @param
 */
void
pop_menu (void)
{
  cmenu--;
  if (cmenu >= 0)
    {
      menu_cnt = menu_nos[cmenu];
      A4GL_debug ("Reset Menu no %d", menu_cnt);
    }
  else
    {
      A4GL_debug ("Nothing to reset to...");
    }
}

/**
 *
 *
 * @param
 */
int
setrecord (char *s, char *t, char *c)
{
  return 0;
}

/**
 * Escape special characters in a string copying it to another.
 *
 * Escape \,",' with a \
 *
 * @param d A pointer to he destination string
 * @param s A pointer to the origin string.
 */
/*
static void
swapstring (char *d, char *s)
{
  int b = 0;
  int a;
  int flg;
  for (a = 0; a <= strlen (s); a++)
    {
      if (s[a] == '\'')
	{
	  flg = 1;
	  if (a > 0)
	    {
	      if (s[a - 1] == '\\')
		{
		  flg = 0;
		}
	    }
	  if (flg)
	    d[b++] = '"';
	  else
	    d[b++] = s[a];
	}
      else if (s[a] == '"')
	{
	  d[b++] = '\\';
	  d[b++] = '"';
	}
      else
	d[b++] = s[a];
    }
  A4GL_debug ("Converted : %s to %s", s, d);
}
*/

/**
 * Check the number of dimentions in the array declaration string
 *
 * @param s A pointer to the string with array declaration.
 * @return The number of dimentions.
 */
int
num_arr_elem (char *s)
{
  int a;
  int c = 0;
  for (a = 0; a < strlen (s); a++)
    {
      if (s[a] == '[')
	c++;
    }
  return c;
}


/**
 * Executed at the end of the parsing process by bison.
 */
int
yywrap (void)
{
  return 1;
}

/**
 * Check if a string is one of the internal variables: today,time,user,date
 *
 * @param s The string to be checked.
 * @return 
 *   - 1 : Is an internal variable.
 *   - 0 : Otherwise
 */
int
system_var (char *s)
{
  if (A4GL_aubit_strcasecmp (s, "today") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (s, "time") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (s, "user") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (s, "date") == 0)
    return 1;
  return 0;
}

/**
 * Increment the number of reports declared.
 */
void
inc_report_cnt (void)
{
  sreports_cnt = 0;
  reset_report_aggregates();
  report_cnt++;
  report_stack_cnt = 0;
}

/**
 * Escape the quotes in a string with backslash.
 *
 * @param s The string to be checked.
 * @return A pointer to a static buffer with the escaped string.
 */
/*
static char *
trans_quote (char *s)
{
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
*/


/**
 * Split a string into pieces, 
 *
 * @param s The input string
 * @param a
 * @param buff A pointer to the buffer where the result is putted.
 * @return 
 *   - if a=0 return the number of pieces
 *   - if a=1 then return the first into buffetc...
 */
int
linked_split (char *s, int a, char *buff)
{
  char *p;
  int z;
  int cnt;
  char buffer[2000];
  strcpy (buffer, s);
  strcat (buffer, ",");

  cnt = 0;
  A4GL_debug ("linked_split %s %d %p", s, a, buff);
  if (a == 0)
    {
      for (z = 0; z < strlen (buffer); z++)
	{
	  if (buffer[z] == ',')
	    {
	      cnt++;
	    }
	}
      return cnt;
    }
  strcpy (buff, "");
  p = buffer;
  cnt = 0;
  if (a > 0)
    {
      for (z = 0; z < strlen (buffer); z++)
	{
	  if (buffer[z] == ',')
	    {
	      cnt++;
	      if (cnt == a)
		{
		  buffer[z] = 0;
		  strcpy (buff, p);
		  A4GL_debug ("Linked found:%s", p);
		  return 1;
		}
	      p = &buffer[z + 1];
	    }
	}
    }
  return 0;
}

/**
 * Copy a value to the primary key list.
 *
 * @param s The string to be copied.
 */
void
set_pklist (char *s)
{
  A4GL_debug ("pklist set to %s\n", s);
  strcpy (pklist, s);
  strcpy (upd_using_notpk, "");
  upd_using_notpk_cnt = 0;
}

/**
 *
 *
 * @param
 */
char *
get_upd_using_notpk (void)
{
  A4GL_debug ("get_upd_using_notpk");
  A4GL_debug ("Returning %s", upd_using_notpk);
  return upd_using_notpk;
}

/**
 *
 *
 * @param
 */
char *
get_upd_using_queries (void)
{
  static char buff[2000];
  int a;
  A4GL_debug ("get_upd_using_???");
  strcpy (buff, "");

  for (a = 0; a < upd_using_notpk_cnt; a++)
    {
      if (strlen (buff) > 0)
	strcat (buff, ",");
      if (A4GL_isyes (acl_getenv ("DOING_CM")))
	{
	  strcat (buff, "?@@PARAM@@?");
	}
      else
	{
	  strcat (buff, "?");
	}
    }
  A4GL_debug ("Returning %s", buff);
  return buff;

}

/**
 * Check if the current report is a pdf one.
 *
 * @todo : The rep type is never assigned.
 *
 * @return 
 *   - An empty string if is a normal report 
 *   - pdf_ Otherwise
 */
char *
compile_ispdf (void)
{
  if (rep_type == REP_TYPE_NORMAL)
    return "";
  else
    return "pdf_";
}




/**
 * Dump an expression if in A4GL_debug mode.
 *
 * @param orig_ptr A pointer to the expression list
 */
void
dump_expr (struct expr_str *orig_ptr)
{
  struct expr_str *start;
  start = orig_ptr;

  A4GL_debug ("DUMP EXPR : ");
  while (orig_ptr)
    {
      int printed = 0;
      if (orig_ptr->expr_type == ET_EXPR_STRING)
	{
	  A4GL_debug ("     %d - %s", orig_ptr->expr_type, orig_ptr->expr_str_u.expr_string);
	  printed = 1;
	}
      if (!printed)
	{
	  A4GL_debug ("exprtype : %d", orig_ptr->expr_type);
	}
    }
  A4GL_debug ("---------------------------------------------------");
}





/**
 * This is something internal for Mike?
 * It's called from main.rule, in function file_name, for GLOBALS file names
 * @param s
 */
void
tr_glob_fname (char *s)
{
  int a;
  for (a = 0; a <= strlen (s); a++)
    {
      if (s[a] == '\\')
	s[a] = '/';
      if (A4GL_isyes (acl_getenv ("LOWER_CASE_GLOB_NAME")))
	{
	  s[a] = tolower (s[a]);
	}
    }
}

char
get_curr_report_stack_whytype_1 (void)
{
  return report_stack[report_stack_cnt - 1].whytype;
}

char
get_curr_report_stack_whytype (void)
{
  return report_stack[report_stack_cnt].whytype;
}


char *
get_curr_report_stack_why (void)
{
  return report_stack[report_stack_cnt].why;
}

char *
get_curr_report_stack_var (void)
{
  return report_stack[report_stack_cnt].var;
}


/* folowing functions are to work around problem with exporting struct in Windows dll */

/**
 *
 *
 * @param
 */
char
get_report_stack_whytype (int a)
{
  return report_stack[a].whytype;
}

/**
 *
 *
 * @param
 */
char *
get_report_stack_why (int a)
{
  return report_stack[a].why;
}

char *
get_report_stack_var (int a)
{
  return report_stack[a].var;
}
/**
 *
 *
 * @param
 */
struct sreports *
get_sreports (int z)
{
  return (struct sreports *) z;
}



/**
 *
 *
 * @param
 */
char *
subtract_one (char *s)
{
  static char buff[256];
  int a;
  int c;

  c = 0;
  for (a = 0; a < strlen (s); a++)
    {
      if (s[a] == ',')
	{
	  buff[c++] = '-';
	  buff[c++] = '1';
	}
      buff[c++] = s[a];
    }
  buff[c++] = '-';
  buff[c++] = '1';
  buff[c] = 0;
  return buff;
}


void chk_for_update_on_serial(char *tab) {
int a;
int idtype, isize;
//printf("Tab=%s current_upd_table=%s\n", tab, current_upd_table);
//printf("A4GL_4glc_gen_cnt=%d\n", A4GL_4glc_gen_cnt (UPDCOL));
  for (a = 0; a < A4GL_4glc_gen_cnt (UPDCOL); a++)
    {
	char *ptr;
	int rval;
	idtype=-1;
	ptr=A4GL_4glc_get_gen (UPDCOL, a);
	rval = A4GL_read_columns (current_upd_table, ptr, &idtype, &isize);
			idtype=idtype&DTYPE_MASK;
	if (idtype==-1 || rval!=1) continue;
//printf("Here %d %d rval=%d\n", idtype,isize,rval);
	if ((idtype &  DTYPE_MASK )==DTYPE_SERIAL) {
		A4GL_warn("Updating a serial column");
	}
    }
}

/**
 * @param mode If mode is set to 1 - expect a '*' as column names...
*/
char *
fix_update_expr (int mode)
{
  static char big_buff[20000];
  int a;
  int rval;
  int isize = 0;
  int idtype = 0;
  char colname[256] = "";
  char buff[1000];
  char *ccol;
  char *notab;
  strcpy (big_buff, "SET ");

  if (mode == 1)
    {
      /* It will only be a '*' anyway.... */
      if (db_used == 0)
	{
	  SPRINTF0 (buff,
		   "You cannot use update * =  without specifying a database");
	  a4gl_yyerror (buff);
	  return 0;
	}

      A4GL_4glc_clr_gen (UPDCOL);

      strcpy (colname, "");
      rval =
	A4GLSQL_get_columns (current_upd_table, colname, &idtype, &isize);
      if (rval == 0)
	{
	set_yytext(current_upd_table);
	  a4gl_yyerror ("Table is not in the database");
	  A4GLSQL_end_get_columns ();
	  return 0;
	}


      while (1)
	{
	  colname[0] = 0;
	  rval = A4GLSQL_next_column (&ccol, &idtype, &isize);
	  strcpy (colname, ccol);
	  if (rval == 0)
	    break;
	  trim_spaces (colname);
	  A4GL_4glc_push_gen (UPDCOL, colname);
	}
      A4GLSQL_end_get_columns ();
    }

  if (A4GL_4glc_gen_cnt (UPDCOL) != A4GL_4glc_gen_cnt (UPDVAL))
    {
      A4GL_4glc_dump_updvals ();
      a4gl_yyerror
	("Number of columns in update not the same as number of values");
    }

  for (a = 0; a < A4GL_4glc_gen_cnt (UPDCOL); a++)
    {
      if (a)
	strcat (big_buff, ",");
      if (A4GL_isyes (acl_getenv ("DOING_CM")))
	{
	  if (strcmp (A4GL_4glc_get_gen (UPDVAL, a), "?") == 0 && 0)
	    {
	      A4GL_assertion (1, "How ?");
	    }
	}

      notab=A4GLSQLCV_check_colname (current_upd_table, A4GL_4glc_get_gen (UPDCOL, a));

      while (strchr(notab,'.')) {
	      notab=strchr(notab,'.')+1;
      }

      SPRINTF2 (buff, "%s=%s ", notab, A4GL_4glc_get_gen (UPDVAL, a));

      strcat (big_buff, buff);
    }

  return big_buff;
}




char *
pg_make_sql_string_and_free (char *first, ...)
{
  va_list ap;
  char *ptr = 0;
  int l;
  char *next;
  int n;
  n = 0;
  va_start (ap, first);
  ptr = acl_strdup (first);


  if (A4GL_isyes (acl_getenv ("FREE_SQL_MEM")))
    {
      free (first);
    }
  first = 0;
  l = strlen (ptr);

  while (1)
    {
      n++;
      next = va_arg (ap, char *);
      if (next == 0)
	break;
      l += strlen (next);
      l += 3;			/* Extra space... */
      ptr = acl_realloc (ptr, l);
      if (strlen (ptr))
	{
	  if (!ispunct (ptr[strlen (ptr) - 1]))
	    {
	      strcat (ptr, " ");
	    }
	}

      strcat (ptr, next);
      if (A4GL_isyes (acl_getenv ("FREE_SQL_MEM")))
	{
	  free (next);
	}
    }
  A4GL_debug ("Generated : %s\n", ptr);
  return ptr;
}








int
get_blk_no (void)
{
	int ccnt;
	ccnt=A4GL_get_ccnt();
  return command_stack[ccnt - 1].block_no;
}

int
get_blk_no_1 (void)
{
	int ccnt;
	ccnt=A4GL_get_ccnt();
  return command_stack[ccnt - 2].block_no;
}



int rep_no_orderby = 0;

void
set_rep_no_orderby (int n)
{
  rep_no_orderby = n;
}

int
get_rep_no_orderby (void)
{
  return rep_no_orderby;
}

struct s_validate
{
  char tabname[65];
  char colname[65];
  struct expr_str_list *expr;
};

struct s_validate *validate_list = 0;
int validate_list_cnt = 0;

int
get_validate_list_cnt (void)
{
  return validate_list_cnt;
}

void
clr_validate_list (void)
{
  if (validate_list)
    free (validate_list);
  validate_list_cnt = 0;
  validate_list = 0;
}

static void
push_validate_column (char *tabname, char *colname)
{
  validate_list_cnt++;
  validate_list =
    acl_realloc (validate_list,
		 sizeof (struct s_validate) * validate_list_cnt);
  /*A4GL_trim(tabname); */
  /*A4GL_trim(colname); */
  strcpy (validate_list[validate_list_cnt - 1].tabname, tabname);
  strcpy (validate_list[validate_list_cnt - 1].colname, colname);

  validate_list[validate_list_cnt - 1].expr =(void*) A4GLSQL_get_validation_expr (tabname, colname);
  if (validate_list[validate_list_cnt - 1].expr == (void *) -1)
    {
      a4gl_yyerror
	("Unable to get validation information - does A4GL_SYSCOL_VAL exist ?");
    }


}

struct expr_str_list *
A4GL_get_validate_expr (int n)
{
  return validate_list[n].expr;
}


struct s_event
{
  int n;
  char *s;
};

struct s_event_list
{
  int nevents;
  struct s_event *events;
};

struct s_event_list event_queue[255];
int nevent_queue = -1;

void
A4GL_new_events (void)
{
  nevent_queue++;
  event_queue[nevent_queue].nevents = 0;
  event_queue[nevent_queue].events = 0;
}

void
A4GL_drop_events ()
{
  int a;
  if (event_queue[nevent_queue].events)
    {
      if (event_queue[nevent_queue].nevents)
	{
	  for (a = 0; a < event_queue[nevent_queue].nevents; a++)
	    {
	      free (event_queue[nevent_queue].events[a].s);
	    }
	}
      free (event_queue[nevent_queue].events);
    }
  event_queue[nevent_queue].nevents = 0;
  event_queue[nevent_queue].events = 0;
  nevent_queue--;
}

void
A4GL_add_onkey_key (char *s)
{
  A4GL_add_event (A4GL_EVENT_KEY_PRESS, s);
}

void
A4GL_add_onaction (char *s)
{
  A4GL_add_event (A4GL_EVENT_ON_ACTION, s);
}

void
A4GL_add_ontimer (char *s)
{
  if (s[0] == 'D')
    {
      A4GL_add_event (A4GL_EVENT_ON_IDLE, &s[2]);
      return;
    }
  if (s[0] == 'V')
    {
      A4GL_add_event (A4GL_EVENT_ON_INTERVAL, &s[2]);
      return;
    }
  if (s[0] == 'T')
    {
      A4GL_add_event (A4GL_EVENT_ON_TIME, &s[2]);
      return;
    }
}

void
A4GL_add_event (int n, char *s)
{
  map_ui_event(n,s);
  event_queue[nevent_queue].nevents++;
  event_queue[nevent_queue].events =
    acl_realloc (event_queue[nevent_queue].events,
		 sizeof (struct s_event) * event_queue[nevent_queue].nevents);
  event_queue[nevent_queue].events[event_queue[nevent_queue].nevents - 1].n =
    n;
  event_queue[nevent_queue].events[event_queue[nevent_queue].nevents - 1].s =
    acl_strdup (s);
}

int
A4GL_get_nevents (void)
{
  return event_queue[nevent_queue].nevents;
}

void
A4GL_get_event (int n, int *i, char **s)
{
  *i = event_queue[nevent_queue].events[n].n;
  *s = event_queue[nevent_queue].events[n].s;
}




/* 
   Translate from the directory name for the SQLPACK to the
   logical name used for translating...
*/
char *
A4GL_decode_packtype (char *s)
{
  if (strcmp (s, "infx") == 0)
    return "INFORMIX";
  if (strcmp (s, "postgres") == 0)
    return "POSTGRES";

  return s;
}


void
A4GL_load_features ()
{
  int dump_features;
  FILE *f;
  char *ptr;
  char buff[300];
  dump_features = A4GL_isyes (acl_getenv ("DUMP_FEATURES"));
  if (dump_features == 0)
    return;
  A4GL_set_sql_features ();
  f = fopen (sql_features, "r");
  if (f == 0)
    {
      return;
    }
  while (1)
    {
      strcpy (buff, "");
      fgets (buff, 256, f);
      if (feof (f))
	break;
      ptr = strchr (buff, ' ');
      if (ptr)
	*ptr = 0;
      ptr = strchr (buff, '\n');
      if (ptr)
	*ptr = 0;
      ptr = strchr (buff, '\r');
      if (ptr)
	*ptr = 0;
      ptr = strchr (buff, '\t');
      if (ptr)
	*ptr = 0;
      A4GL_trim (buff);
      if (buff[0] == '#')
	continue;
      if (strlen (buff) == 0)
	continue;
      A4GL_add_pointer (buff, FEATURE_USED, (void *) 1);
    }
  fclose (f);


}

void
A4GL_add_feature (char *feature)
{
  static int dump_features = -1;
  static int failed = 0;
  FILE *f;

  if (dump_features == -1)
    {
      dump_features = A4GL_isyes (acl_getenv ("DUMP_FEATURES"));
    }

  if (dump_features == 0)
    return;
  if (!A4GL_has_pointer (feature, FEATURE_USED))
    {
      A4GL_set_sql_features ();
      f = fopen (sql_features, "a");
      if (f == 0)
	{
	  if (failed == 0)
	    PRINTF ("Unable to open features file (%s) - %d\n", sql_features,
		    errno);
	  failed++;
	  return;
	}
      A4GL_add_pointer (feature, FEATURE_USED, (void *) 1);
      FPRINTF (f, "%s\n", feature);
      fclose (f);
    }
}




char *
A4GLSQLCV_generate_ins_string (char *current_ins_table, char *s,int is_select_into )
{
  char buff[40000];
  if (A4GLSQLCV_check_requirement ("FULL_INSERT") && !is_select_into)
    {
      char *p;
      if (strstr (s, " VALUES "))
	{
	  p = fix_insert_expr (1);
	  if (p)
	    {
	      SPRINTF2 (buff, "INSERT INTO %s %s", current_ins_table, p);
	      free (s);
	      return acl_strdup (buff);
	    }
	}
    }


  return s;

}





static void
A4GL_set_sql_features (void)
{
  if (sql_features == 0)
    {
      sql_features = acl_getenv ("A4GL_SQL_FEATURE_FILE");
      if (sql_features == 0)
	sql_features = "sql_features";
      if (strlen (sql_features) == 0)
	{
	  sql_features = "sql_features";
	}
    }
}

void
emulate_insert (module_definition *mod, char *s)
{
char buff[256];
	strcpy(buff,do_clobbering_sql(mod, clobber,downshift(s)));
  	A4GL_cursor_defined (A4GL_new_expr_simple_string(buff, ET_EXPR_IDENTIFIER), 'I');
}


void
add_serial_column (char *t, char *c)
{
  // Doesn't do anything just yet....

        char buff[256];
        SPRINTF2(buff,"%s.%s",t,c);
        A4GL_add_pointer(buff,TAB_COL_IS_SERIAL, (void *)1);
}


void
do_yyerror (char *s)
{
  a4gl_yyerror (s);
}





/*
int A4GL_am_doing_a_print(void) {
	return doing_a_print;
}
*/










void
add_sql_function (char *s)
{
  FILE *f = 0;
  if (A4GL_isyes(acl_getenv("LOGSQLFUNCTIONS"))) {
  f = fopen ("/tmp/sqlcall.log", "a");
  if (!f)
    return;
  FPRINTF (f, "%s %s %d\n", s, A4GL_compiling_module (), yylineno);
  fclose (f);
  }
}



int
get_sio_ids (char *s)
{
int a;
  a=get_block_no (get_sio_id (s) - 1);
return a;
}


void
add_replace (char *a, char *b)
{
  nreplacements++;
  replacements =
    realloc (replacements, sizeof (struct s_replacements) * nreplacements);
  replacements[nreplacements - 1].find = strdup (a);
  replacements[nreplacements - 1].replace = strdup (b);
}


void
drop_replace (char *a)
{
  int z;
  for (z = 0; z < nreplacements; z++)
    {
      if (replacements[z].find == 0)
	continue;
      if (strcmp (replacements[z].find, a) == 0)
	replacements[z].find = 0;
    }
}



struct expr_str *
get_for_default_step (void)
{
  struct expr_str *ptr;
  ptr = A4GL_new_literal_long_str ("1");
  return ptr;
}




char *get_debug_filename(void) {
	return debug_filename;
}


char *get_force_ui(void) {
	return force_ui;
}


void init_blk(void) {
	int a;
	for (a=0;a<MAXMENUOPTS;a++) menu_cmd_cnt[a] =0;
	for (a=0;a<MAXMENU;a++) menu_blk[a]=0;
}


void clr_menu_attribs(void) {

menu_attrib_comment=0;
menu_attrib_style=0;
menu_attrib_image=0;

}

struct expr_str * get_menu_attrib(char type) {
        if (type=='S') {
                return menu_attrib_style;
        }
        if (type=='C') {
                return menu_attrib_comment;
        }
        if (type=='I') {
                return menu_attrib_image;
        }
	return NULL;
}


void set_menu_attrib(char type, struct expr_str *value) {
	if (type=='S') {
		menu_attrib_style=value;
	}
	if (type=='C') {
		menu_attrib_comment=value;
	}
	if (type=='I') {
		menu_attrib_image=value;
	}
}

int A4GL_is_internal_class_function(char *class,char *name) {
	return 1;
}













char *A4GL_lextype(void) {
	return acl_getenv("A4GL_LEXTYPE");
}





struct expr_str *chk_expr(struct expr_str *p) {
	return p;
}

struct expr_str_list *make_fgl_expr_list(expr_str_list *p) {
	
return fully_expand_variables_in_expr_str_list(p);

//expand_variables_in_expr_str_list(p,0,1);
}




static int get_function_definition(char *s) {
int a;
for (a=0;a<nfunction_definitions;a++) {
        if (A4GL_aubit_strcasecmp(s, function_definitions[a].fname)==0) {
                return a;
        }
}
return -1;
}

void output_to_report_definition(char *s, struct expr_str_list  *p) {
        int nbind;
        int curr_fdef;
        char buff[256];
        curr_fdef=get_function_definition(s);
        if (curr_fdef==-1) {
                nfunction_definitions++;
                function_definitions=realloc(function_definitions, nfunction_definitions*sizeof(function_definitions[0]));
                function_definitions[nfunction_definitions-1].fname=strdup(s);
                function_definitions[nfunction_definitions-1].type='R';
                if (p) {
                function_definitions[nfunction_definitions-1].params=p->list.list_len;
                } else {
                function_definitions[nfunction_definitions-1].params=0;
                }
                function_definitions[nfunction_definitions-1].rvals=-1; /* reserved for future use.. */
                return;
        }
        if (p) {
                nbind=p->list.list_len;
        } else {
                nbind=0;
        }

        if (nbind==function_definitions[curr_fdef].params) return;

        sprintf(buff,"%d != %d", nbind,function_definitions[curr_fdef].params);
        set_yytext(buff);
        a4gl_yyerror("Report has been defined with a different number of parameters");
}



void add_report_definition(char *s, struct  expr_str_list *params) {

        int nbind;
        char buff[256];
        int curr_fdef;
        curr_fdef=get_function_definition(s);
	
	if (params) {
		params=expand_variables_in_expr_str_list(params,1,1);
	}
        if (curr_fdef==-1) {
                nfunction_definitions++;
                function_definitions=realloc(function_definitions, nfunction_definitions*sizeof(function_definitions[0]));
                function_definitions[nfunction_definitions-1].fname=strdup(s);
                function_definitions[nfunction_definitions-1].type='R';
                if (params) {
                	function_definitions[nfunction_definitions-1].params=params->list.list_len;
                } else {
                	function_definitions[nfunction_definitions-1].params=0;
                }
                function_definitions[nfunction_definitions-1].rvals=-1; /* reserved for future use.. */
                return;
        }
        if (params) {
        nbind=params->list.list_len;
        } else {
        nbind=0;
        }
        if (nbind==function_definitions[curr_fdef].params) return;
        sprintf(buff,"%d != %d", nbind,function_definitions[curr_fdef].params);
        set_yytext(buff);
        a4gl_yyerror("Report has already been called with a different number of parameters");
}



int check_cursor_name(expr_str *si) {
char *s;
if (si->expr_type==ET_EXPR_IDENTIFIER) {
	s=si->expr_str_u.expr_string;
        if (A4GL_has_pointer(s,CURSOR_DEFINED_MOD)){
                set_yytext(s);
                a4gl_yyerror("Cursor has already been used");
                return 0;
        }
        A4GL_add_pointer(s,CURSOR_DEFINED_MOD,(void *)1);
}
        return 1;
}


/*
 * Add a table/column to an string list
 * this is only really needed for the INITIALIZE LIKE - and then
 * only if they pass in a table.*
 * in which case - we need to add all the columns for that table..
 **/
void add_to_str_list_set_record(struct str_list *sl, struct s_full_col *sfc) {
char smbuff[200];
if (sfc->col) {
        // Nice and simple - theres only a single column...
        sl->str_list_entry.str_list_entry_len=sl->str_list_entry.str_list_entry_len+1;
        sl->str_list_entry.str_list_entry_val=realloc(sl->str_list_entry.str_list_entry_val, sizeof(char *)* sl->str_list_entry.str_list_entry_len);
        sprintf(smbuff,"%s.%s", sfc->tab, sfc->col);
        sl->str_list_entry.str_list_entry_val[sl->str_list_entry.str_list_entry_len-1]=strdup(smbuff);
        return ;
} else {
// Theres a .* - so we need all the columns...
      int rval;
      int isize = 0;
      int idtype = 0;
      char colname[256] = "";
      char buff[300];
      char *ccol;
      rval = A4GLSQL_get_columns (sfc->tab, 0, &idtype, &isize);
      A4GL_debug ("rval = %d", rval);
      if (rval == 0 && sfc->tab)
        {
          SPRINTF1 (buff, "%s does not exist in the database", sfc->tab);
          a4gl_yyerror (buff);
          A4GLSQL_end_get_columns ();
          return ;
        }

      while (1)
        {
                struct s_full_col new_sfc;
                colname[0] = 0;
                rval = A4GLSQL_next_column (&ccol, &idtype, &isize);
                if (rval == 0) break;
                strcpy (colname, ccol);
                trim_spaces (colname);
                new_sfc.tab=sfc->tab;
                new_sfc.col=colname;
                add_to_str_list_set_record(sl, &new_sfc);
          //setrecord (s, t, colname);
        }
      A4GLSQL_end_get_columns ();
      return ;
    }
}


// generate_update_column_list_for - generates a column list for an update statement
// Value_list may be adjusted if there is a SERIAL column (to drop that value)
//
str_list *generate_update_column_list_for(char *tabname, struct s_select_list_item_list *value_list) {
char colname[2000];
int isize = 0;
int idtype = 0;
char *ccol;
struct str_list *l;
int rval;
// We might need a new value list if we're generating and it 
// includes a serial column - because we'll need to remove that value from our
// list...
struct s_select_list_item_list value_list_new;
int cnt=0;
int colcnt=0;
int uses_serial=0;
l=NULL;


	value_list_new.list.list_len=0;
	value_list_new.list.list_val=0;


      strcpy (colname, "");
      rval = A4GLSQL_get_columns (tabname, colname, &idtype, &isize);
      if (rval == 0)
        {
	set_yytext(tabname);
          a4gl_yyerror ("Table is not in the database)");
          A4GLSQL_end_get_columns ();
          return NULL;
        }

	l=new_str_list(0);

      while (1)
        {
          colname[0] = 0;
          rval = A4GLSQL_next_column (&ccol, &idtype, &isize);
			idtype=idtype&DTYPE_MASK;
	
          if (rval == 0)
            break;

          strcpy (colname, ccol);
          trim_spaces (colname);

	  if ((idtype & DTYPE_MASK)==DTYPE_SERIAL || A4GL_has_serial_column_marker(tabname,colname) ) {
			uses_serial=1;
	  }  else {
	  	add_str_list(l, colname);	
		if (colcnt<value_list->list.list_len) {
			add_select_list_item_list (&value_list_new, value_list->list.list_val[colcnt]);
		}
		cnt++;
	  }
	colcnt++;
        }
        A4GLSQL_end_get_columns ();

	if (cnt!=value_list_new.list.list_len) {
		a4gl_yyerror("Number of columns does not match number of values");
	}

	if (uses_serial) {
		A4GL_warn("Serial column dropped from UPDATE statement (serial columns cannot be updated)");
		value_list->list.list_len= value_list_new.list.list_len;
		value_list->list.list_val= value_list_new.list.list_val;
	}
	return l;
}




/* 
 * these indirect to the ones in lib/libaubit4gl so that we can do some expansions of variables first 
 * and some checks/debugs/breakpoints etc
 * */
struct s_select_list_item_list * local_add_select_list_item_list( struct s_select_list_item_list *p, struct s_select_list_item *i)
{
struct s_select_list_item_list * prval;



 prval=add_select_list_item_list(p,i);

  return prval;
}

/* 
 * these indirect to the ones in lib/libaubit4gl so that we can do some expansions of variables first 
 * and some checks/debugs/breakpoints etc
 * */
struct s_select_list_item_list * local_new_select_list_item_list(  struct s_select_list_item *i) {
 struct s_select_list_item_list * prval=NULL;
 struct variable_usage *u;

 if (i->data.type !=E_SLI_VARIABLE_USAGE) {
  	prval=new_select_list_item_list(i);
  	return prval;
 } 

 // Its a variable usage - is it for a record ? 
 u=i->data.s_select_list_item_data_u.var_usage;
 u=usage_bottom_level(u);
 if (u->datatype==-2) {
	// Its - its a record... 
	A4GL_assertion(1,"Not expecting a record...");
 } else {
	// Not - it must be a single variable...
  	prval=new_select_list_item_list(i);
  	return prval;
 }
 
return prval;
}

/* 
 * these indirect to the ones in lib/libaubit4gl so that we can do some expansions of variables first 
 * and some checks/debugs/breakpoints etc
 * */
struct s_select_list_item_list *expand_slil(struct s_select_list_item_list *l) {

 l=rationalize_select_list_item_list(l);
 return l;
}


int current_is_report(void) {
	  if (isin_command ("REPORT")) return 1;
	  return 0;
}

/* ================================= EOF ============================= */

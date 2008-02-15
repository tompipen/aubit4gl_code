#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"
//#include "fgl.x.h"
#include "a4gl_4glc_int.h"
#include "lint.h"
#include "linearise.h"

#define MODE_TRY 0
#define MODE_BUY 1

static int indent = 0;
static int cache_expression (char *s, expr_str ** ptr, int mode);
//expr_str *get_expr_datatype (int n);
extern int yylineno;
char *lint_module = 0;
static void load_boltons (char *fname);
static int add_calltree_calls (char *s, commands * func_commands, int mode);
char *decode_rb (enum report_blocks a);
//char *expr_as_string_when_possible (expr_str * p);

//void dump_prototypes (void);
//static struct commands * linearise_commands(struct commands *master_list, struct commands *cmds) ;
//static void linearise_commands_from_events(struct commands *master_list, struct on_events* evt_list) ;
//static char *get_lint_filename(char *s) ;
//static char *local_xml_escape(char *s) ;
//static void cache_expressions(struct expr_str_list *list, struct commands *cmds) ;
//static void cache_expression(struct expr_str_list *list, struct expr_str **eptr) ;
//static void cache_expression_list(struct expr_str_list *list, struct expr_str_list *srclist) ;
extern module_definition this_module;
int expr_datatype (struct expr_str *p);

//static void scan_functions(char *infuncname, int calltree_entry,int *calltree, struct call_list *f,struct commands *calling_funcs_commands) ;
//static void set_lint_module (char *s) ;

//static void check_variable_name(char *modname, char *scope, struct variable *v) ;
//static void check_cmds_for_dead_code( struct commands *cmds) ;
//int has_variable (struct variable_list *v, char *name);
//int get_lint_style (void);


#define PROTO_FUNCTION 		1
#define PROTO_REPORT 		2
#define PROTO_PDF_REPORT 	3

//void A4GL_lint (char *module, int line, char *code, char *type, char *extra);
//static char * A4GL_transform_basename (char *s);

struct s_function_prototype
{
  int proto_type;
  char *pname;
  int nparams;
  int *param_dtypes;
  int nreturns;
  int *return_dtypes;
};

struct s_function_prototype *fprototypes = 0;

struct s_function_prototype *fprototypes_boltons = 0;
int nboltons = 0;
static int is_bolton_function (char *s);


expr_str_list *expr_cache = 0;

//static int promoteable(int a, int b) ;

//static void set_expr_cache(expr_str_list *n) { expr_cache=n; }

expr_str *
get_expr_datatype (int n)
{
  A4GL_assertion (expr_cache == 0, "No expression cache");
  if (n > expr_cache->list.list_len || n < 0)
    {
      A4GL_assertion (1, "Expression cache subscript out of range");
    }
  return expr_cache->list.list_val[n];
}



char *
dtype_as_string (int dtype)
{
  if (dtype == 90)
    {
      return "Boolean";
    }
  switch (dtype & DTYPE_MASK)
    {
    case DTYPE_CHAR:
      return "char";
    case DTYPE_SMINT:
      return "smallint";
    case DTYPE_INT:
      return "integer";
    case DTYPE_FLOAT:
      return "float";
    case DTYPE_SMFLOAT:
      return "smallfloat";
    case DTYPE_DECIMAL:
      return "decimal";
    case DTYPE_SERIAL:
      return "serial";
    case DTYPE_DATE:
      return "date";
    case DTYPE_MONEY:
      return "money";
    case DTYPE_NULL:
      return "null";
    case DTYPE_DTIME:
      return "datetime";
    case DTYPE_BYTE:
      return "byte";
    case DTYPE_TEXT:
      return "text";
    case DTYPE_VCHAR:
      return "varchar";
    case DTYPE_INTERVAL:
      return "interval";
    case DTYPE_NCHAR:
      return "nchar";
    }
  return "Unknown";

}




static int
is_char_dtype (int dtype)
{
  dtype = dtype & DTYPE_MASK;
  if (dtype == DTYPE_CHAR)
    return 1;
  if (dtype == DTYPE_NCHAR)
    return 1;
  if (dtype == DTYPE_VCHAR)
    return 1;
  return 0;
}



static int
local_is_system_variable (char *s)
{
  //if (strcmp (s, "int_flag") == 0) return 1;
  //if (strcmp (s, "quit_flag") == 0) return 1;

  if (A4GL_aubit_strcasecmp (s, "a4gl_status") == 0)
    return 1;
  if (strncmp (s, "a4gl_sqlca", 10) == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (s, "notfound") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (s, "false") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (s, "true") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (s, "today") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (s, "user") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (s, "pageno") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (s, "lineno") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (s, "time") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (s, "usrtime") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (s, "curr_hwnd") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (s, "curr_form") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (s, "err_file_name") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (s, "err_file_no") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (s, "curr_file_name") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (s, "curr_line_no") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (s, "err_status") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (s, "aiplib_status") == 0)
    return 1;
  return 0;
}



int
local_is_valid_vname (struct variable *v, char scope)
{
  char *nm;
  nm = v->names.names.names_val[0].name;

  if (strlen (nm) < 4)
    return 0;			// too short for sn_
  if (nm[2] != '_')
    return 0;

  if (nm[1] == 'v')
    {
      return 1;
    }

  switch (v->var_data.variable_type)
    {
    case VARIABLE_TYPE_SIMPLE:
      switch (v->var_data.variable_data_u.v_simple.datatype & DTYPE_MASK)
	{
	case DTYPE_CHAR:
	  if (nm[1] != 'c')
	    return 0;
	  else
	    return 1;
	case DTYPE_SMINT:
	  if (nm[1] != 'b' && nm[1] != 's')
	    return 0;
	  else
	    return 1;
	case DTYPE_SERIAL:
	case DTYPE_INT:
	  if (nm[1] != 'n')
	    return 0;
	  else
	    return 1;
	case DTYPE_DATE:
	  if (nm[1] != 'd')
	    return 0;
	  else
	    return 1;
	case DTYPE_DECIMAL:
	  if (nm[1] != 'l')
	    return 0;
	  else
	    return 1;
	case DTYPE_INTERVAL:
	  if (nm[1] != 'i')
	    return 0;
	  else
	    return 1;
	}
      // No specific rule - so must be ok...
      return 1;

    case VARIABLE_TYPE_RECORD:
      if (nm[1] != 'r')
	return 0;
      else
	return 1;



    case VARIABLE_TYPE_ASSOC:
    case VARIABLE_TYPE_CONSTANT:
    case VARIABLE_TYPE_FUNCTION_DECLARE:
    case VARIABLE_TYPE_OBJECT:
    case VARIABLE_TYPE_LINKED:
      return 1;


      //case VARIABLE_TYPE_ARRAY:
      //if (nm[1]!='a') return 0; else return 1;
    }

  return 1;
}



void
check_module (struct module_definition *d)
{
  struct commands *all_cmds = 0;
  int a;
  int b;


  all_cmds = linearise_commands (0, 0);

}
























static int
system_function_dtype (char *funcname)
{

// Dont return anything
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_add_keymap") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_closeiem") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "a4gl_dump_screen") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "a4gl_load_datatype") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "a4gl_run_gui") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "a4gl_set_page") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "a4gl_show_help") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_dump_screen") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_fetchiem") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_get_curr_height") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_get_curr_width") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_get_user") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_libhelp_showhelp") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_openiem") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_random") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_read_pipe") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_set_color") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_setenv") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_scr_size") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_getkey_wait") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_keysetlabel") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "ddeconnect") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "ddeexecute") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "ddefinish") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "ddefinishall") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "ddegeterror") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "ddepeek") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "ddepoke") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "err_print") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "err_quit") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "errorlog") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_dialog_setbuffer") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_dialog_setcurrline") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_dialog_setkeylabel") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_prtscr") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_set_arrline") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_set_scrline") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_setkeylabel") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_strtosend") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_winmessage") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_drawbox") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "set_count") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "showhelp") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "startlog") == 0)
    return -1;

// INTs
  if (A4GL_aubit_strcasecmp (funcname, "length") == 0)
    return DTYPE_INT;
  if (A4GL_aubit_strcasecmp (funcname, "weekday") == 0)
    return DTYPE_INT;
  if (A4GL_aubit_strcasecmp (funcname, "year") == 0)
    return DTYPE_INT;
  if (A4GL_aubit_strcasecmp (funcname, "arr_count") == 0)
    return DTYPE_INT;
  if (A4GL_aubit_strcasecmp (funcname, "arr_curr") == 0)
    return DTYPE_INT;
  if (A4GL_aubit_strcasecmp (funcname, "day") == 0)
    return DTYPE_INT;
  if (A4GL_aubit_strcasecmp (funcname, "length") == 0)
    return DTYPE_INT;
  if (A4GL_aubit_strcasecmp (funcname, "month") == 0)
    return DTYPE_INT;

  if (A4GL_aubit_strcasecmp (funcname, "winexec") == 0)
    return DTYPE_SMINT;


  if (A4GL_aubit_strcasecmp (funcname, "mdy") == 0)
    return DTYPE_DATE;

  if (A4GL_aubit_strcasecmp (funcname, "a4gl_get_info") == 0)
    return DTYPE_CHAR;
  if (A4GL_aubit_strcasecmp (funcname, "a4gl_get_page") == 0)
    return DTYPE_CHAR;
  if (A4GL_aubit_strcasecmp (funcname, "a4gl_get_ui_mode") == 0)
    return DTYPE_CHAR;
  if (A4GL_aubit_strcasecmp (funcname, "arg_val") == 0)
    return DTYPE_CHAR;



  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_byte_as_str") == 0)
    return DTYPE_CHAR;



  if (A4GL_aubit_strcasecmp (funcname, "ascii") == 0)
    return DTYPE_CHAR;
  if (A4GL_aubit_strcasecmp (funcname, "date") == 0)
    return DTYPE_DATE;
  if (A4GL_aubit_strcasecmp (funcname, "dbms_dialect") == 0)
    return DTYPE_CHAR;
  if (A4GL_aubit_strcasecmp (funcname, "downshift") == 0)
    return DTYPE_CHAR;
  if (A4GL_aubit_strcasecmp (funcname, "err_get") == 0)
    return DTYPE_CHAR;

  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_expand_env_vars_in_cmdline") == 0)
    return DTYPE_CHAR;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_buffertouched") == 0)
    return DTYPE_INT;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_compare") == 0)
    return DTYPE_INT;

  if (A4GL_aubit_strcasecmp (funcname, "fgl_dialog_getbuffer") == 0)
    return DTYPE_CHAR;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_dialog_getfieldname") == 0)
    return DTYPE_CHAR;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_getenv") == 0)
    return DTYPE_CHAR;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_getkey") == 0)
    return DTYPE_CHAR;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_keyval") == 0)
    return DTYPE_INT;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_lastkey") == 0)
    return DTYPE_INT;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_round") == 0)
    return DTYPE_INT;


  if (A4GL_aubit_strcasecmp (funcname, "ord") == 0)
    return DTYPE_INT;
  if (A4GL_aubit_strcasecmp (funcname, "num_args") == 0)
    return DTYPE_INT;
  if (A4GL_aubit_strcasecmp (funcname, "scr_line") == 0)
    return DTYPE_INT;
  if (A4GL_aubit_strcasecmp (funcname, "upshift") == 0)
    return DTYPE_CHAR;



  if (A4GL_aubit_strcasecmp (funcname, "abs") == 0)
    return DTYPE_FLOAT;
  if (A4GL_aubit_strcasecmp (funcname, "sqrt") == 0)
    return DTYPE_FLOAT;

  return -2;
}


static int
system_function (char *funcname)
{
  if (system_function_dtype (funcname) != -2)
    {
      return 1;
    }
  return 0;
}



/********************************************************************************/
static int
find_function_in_me (module_definition * me, char *s)
{
  int a;

  for (a = 0; a < me->module_entries.module_entries_len; a++)
    {
      struct module_entry *m;
      m = me->module_entries.module_entries_val[a];
      switch (m->met_type)
	{
	case E_MET_MAIN_DEFINITION:

	case E_MET_FUNCTION_DEFINITION:
	  if (A4GL_aubit_strcasecmp (m->module_entry_u.function_definition.funcname, s) == 0)
	    return a;
	case E_MET_REPORT_DEFINITION:
	  if (A4GL_aubit_strcasecmp (m->module_entry_u.report_definition.funcname, s) == 0)
	    return a;
	case E_MET_PDF_REPORT_DEFINITION:
	  if (A4GL_aubit_strcasecmp (m->module_entry_u.pdf_report_definition.funcname, s) == 0)
	    return a;

	default:

	  // Dont care - cant be a function or report anyway...
	  break;
	}
    }
  return -1;
}


struct function_calls
{
  char *conditional;
  int nchildren;
  struct function_calls *children;

};


struct function
{
  char *module;
  int line;
  char *function;
  char f_or_r;
  struct function_calls *calls;
  void *ptr;
  int called;
};

struct function *functions = 0;
int functions_cnt = 0;

FILE *output = 0;



static void
add_function (char *module, int line, char *fname, char forr, void *ptr)
{
  functions_cnt++;
  functions = realloc (functions, sizeof (struct function) * functions_cnt);
  functions[functions_cnt - 1].module = module;
  functions[functions_cnt - 1].line = line;
  functions[functions_cnt - 1].function = fname;
  functions[functions_cnt - 1].f_or_r = forr;
  functions[functions_cnt - 1].calls = 0;
  functions[functions_cnt - 1].ptr = ptr;
  functions[functions_cnt - 1].called = 0;
  printf ("Added %s in %s.%d\n", fname, module, line);
}

int callstack_cnt = 0;
char **callstack = 0;

static void
add_to_callstack (char *s)
{
  callstack_cnt++;
  callstack = realloc (callstack, sizeof (char *) * callstack_cnt);
  callstack[callstack_cnt - 1] = s;
  if (callstack_cnt > 100)
    {
      printf ("Callstack too deep\n");
    }
}



static int
isoncallstack (char *s)
{
  int a;
  for (a = 0; a < callstack_cnt; a++)
    {
      if (strcmp (s, callstack[a]) == 0)
	return 1;
    }
  return 0;
}

static void
pop_callstack (void)
{
  callstack_cnt--;
}

static int
find_function (char *s)
{
  int a;
  for (a = 0; a < functions_cnt; a++)
    {
      if (strcmp (s, functions[a].function) == 0)
	return a;
    }
  return -1;
}

int
print_spaces (int n)
{
  int a;
  if (n <= 0)
    return 0;
  for (a = 0; a < n; a++)
    printf ("   ");

  return 0;
}

void
print_indent ()
{
  int a;
  for (a = 0; a < indent; a++)
    {
      fprintf (output, "   ");
    }
}

static int
cache_expression (char *s, expr_str ** ptr, int mode)
{
  expr_str *expr;
  if (ptr == 0) return 0;
  expr = *ptr;


  if (expr == 0) return 0;


  switch (expr->expr_type)
    {
    case ET_EXPR_NOT:
    case ET_EXPR_NEG:
    case ET_EXPR_UPSHIFT:
    case ET_EXPR_DOWNSHIFT:
    case ET_EXPR_ASCII:
    case ET_EXPR_OP_ISNULL:
    case ET_EXPR_OP_ISNOTNULL:
    case ET_EXPR_YEAR_FUNC:
    case ET_EXPR_DATE_FUNC:
    case ET_EXPR_MONTH_FUNC:
    case ET_EXPR_DAY_FUNC:
    case ET_EXPR_TIME_FUNC:
    case ET_EXPR_OP_YEAR:
    case ET_EXPR_OP_MONTH:
    case ET_EXPR_OP_DAY:
    case ET_EXPR_OP_HOUR:
    case ET_EXPR_OP_MINUTE:
    case ET_EXPR_OP_SECOND:
      return cache_expression ("",&expr->expr_str_u.expr_expr,mode);

    case ET_EXPR_OP_MATCHES:
    case ET_EXPR_OP_LIKE:
    case ET_EXPR_OP_NOT_LIKE:
    case ET_EXPR_OP_NOT_MATCHES:
    case ET_EXPR_OP_ADD:
    case ET_EXPR_OP_SUB:
    case ET_EXPR_OP_DIV:
    case ET_EXPR_OP_MULT:
    case ET_EXPR_OP_LESS_THAN:
    case ET_EXPR_OP_GREATER_THAN:
    case ET_EXPR_OP_EQUAL:
    case ET_EXPR_OP_NOT_EQUAL:
    case ET_EXPR_OP_LESS_THAN_EQ:
    case ET_EXPR_OP_GREATER_THAN_EQ:
    case ET_EXPR_OP_OR:
    case ET_EXPR_OP_AND:
    case ET_EXPR_OP_USING:
    case ET_EXPR_OP_MOD:
    case ET_EXPR_OP_POWER:
    case ET_EXPR_OP_CONCAT:
      return cache_expression ("",&expr->expr_str_u.expr_op->left,mode)+ cache_expression ("",&expr->expr_str_u.expr_op->right,mode);
	default: break;

}

  if (expr->expr_type == ET_EXPR_FCALL)
    {
      int a;
      // Got a function call - add it to the stack..
      if (mode == MODE_BUY) {
	  			print_indent ();
	  			fprintf (output, "<CALLS FUNCTIONNAME='%s' LINE=\"%d\"/>\n", expr->expr_str_u.expr_function_call->fname,
						expr->expr_str_u.expr_function_call->line
					);
				}
      return 1;
    }

  return 0;
}


static int
cache_expression_list (char *s, struct expr_str_list *srclist, int mode)
{
  int a;
  int cnt = 0;
  if (srclist == 0)
    return 0;
  if (srclist->list.list_len == 0)
    return 0;

  for (a = 0; a < srclist->list.list_len; a++)
    {
      cnt += cache_expression (s, &srclist->list.list_val[a], mode);
    }
  return cnt;
}



static char *
get_str_list (str_list * list)
{
  static char buff[2000];
  int a;
  strcpy (buff, "");
  for (a = 0; a < list->str_list_entry.str_list_entry_len; a++)
    {
      if (a)
	strcat (buff, ",");
      strcat (buff, list->str_list_entry.str_list_entry_val[a]);
    }
  return buff;
}

static char *
get_field_list (fh_field_list * list)
{
  static char buff[2000];
  int a;
  strcpy (buff, "");
  for (a = 0; a < list->field_list_entries.field_list_entries_len; a++)
    {
      if (a)
	strcat (buff, ",");
      strcat (buff, expr_as_string_when_possible(list->field_list_entries.field_list_entries_val[a].field));
    }
  return buff;
}

static char *
get_var_lit (expr_str * x)
{
  static char buff[256];
  if (x == 0)
    return "";
  switch (x->expr_type)
    {

    case ET_E_V_OR_LIT_NOVALUE:
      return "";
    //case ET_E_V_OR_LIT_VAR: return x->expr_str_u.var->varname;
    case ET_E_V_OR_LIT_INT:
      sprintf (buff, "%d", x->expr_str_u.i);
      return buff;
    case ET_E_V_OR_LIT_STRING:
      return x->expr_str_u.s;
    case ET_E_V_OR_LIT_VAR_AS_STRING:
      return x->expr_str_u.sv;
    case ET_E_V_OR_LIT_IDENT:
      return x->expr_str_u.si;
// case ET_E_V_OR_LIT_NULL: return "";
	default:
		A4GL_assertion(1,"Unexpected expression type");

    }
  sprintf (buff, "Bad VAR=%d", x->expr_type);
  return buff;
  return "Blah1";

}
static char *
xml_encode (char *s)
{
  static char *buff = 0;
  static int last_len = 0;
  int c;
  int a;
  int l;
  int b;
  c = 0;
  if (strchr (s, '&'))
    c++;
  if (strchr (s, '<'))
    c++;
  if (strchr (s, '>'))
    c++;
  if (strchr (s, '"'))
    c++;
  if (strchr (s, '\''))
    c++;

  if (c == 0)
    {
      return s;
    }

  l = strlen (s);
  if (l > last_len)
    {
      buff = realloc (buff, l * 5 + 1);
      last_len = l;
    }

  b = 0;
  for (a = 0; a < l; a++)
    {
      if (s[a] == '>')
	{
	  buff[b++] = '&';
	  buff[b++] = 'g';
	  buff[b++] = 't';
	  buff[b++] = ';';
	  continue;
	}
      if (s[a] == '"')
	{
	  buff[b++] = '&';
	  buff[b++] = 'q';
	  buff[b++] = 'u';
	  buff[b++] = 'o';
	  buff[b++] = 't';
	  buff[b++] = ';';
	  continue;
	}
      if (s[a] == '\'')
	{
	  buff[b++] = '&';
	  buff[b++] = 'a';
	  buff[b++] = 'p';
	  buff[b++] = 'o';
	  buff[b++] = 's';
	  buff[b++] = ';';
	  continue;
	}
      if (s[a] == '<')
	{
	  buff[b++] = '&';
	  buff[b++] = 'l';
	  buff[b++] = 't';
	  buff[b++] = ';';
	  continue;
	}
      if (s[a] == '&')
	{
	  buff[b++] = '&';
	  buff[b++] = 'a';
	  buff[b++] = 'm';
	  buff[b++] = 'p';
	  buff[b++] = ';';
	  continue;
	}
      buff[b++] = s[a];
    }

  buff[b] = 0;
  return buff;
}


static char *
get_menu_option (menuoption * mn)
{
  static char buff[1024];
  char smbuff[100];;
  strcpy (buff, "");
  sprintf (smbuff, "KEYS=\"%s\"", xml_encode (get_str_list (mn->keys)));
  strcat (buff, smbuff);
  sprintf (smbuff, " SHORT=\"%s\"", xml_encode (get_var_lit (mn->shortname)));
  strcat (buff, smbuff);
  sprintf (smbuff, " LONG=\"%s\"", xml_encode (get_var_lit (mn->longname)));
  strcat (buff, smbuff);

  return buff;
}

static char *
get_event (event_data * a)
{
  static char buff[1024];
  switch (a->event_type)
    {
    case EVENT_BEF_ROW:
      return "EVENT_TYPE=\"BEFORE ROW\"";
    case EVENT_AFT_ROW:
      return "EVENT_TYPE=\"AFTTER ROW\"";
    case EVENT_BEFORE_DELETE:
      return "EVENT_TYPE=\"BEFORE DELETE\"";
    case EVENT_AFTER_DELETE:
      return "EVENT_TYPE=\"AFTER DELETE\"";
    case EVENT_BEFORE_INSERT:
      return "EVENT_TYPE=\"BEFORE INSERT\"";
    case EVENT_AFTER_INSERT:
      return "EVENT_TYPE=\"AFTER INSERT\"";
    case EVENT_BEFORE_OPEN_FORM:
      return "EVENT_TYPE=\"BEFORE OPEN FORM\"";
    case EVENT_BEFORE_INSERT_DELETE:
      return "EVENT_TYPE=\"BEFORE INSERT DELETE\"";
    case EVENT_AFTER_INSERT_DELETE:
      return "EVENT_TYPE=\"AFTER INSERT DELETE\"";
    case EVENT_AFTER_INP_CLEAN:
      return "EVENT_TYPE=\"AFTER_INP_CLEAN\"";
    case EVENT_ANYKEY_PRESS:
      return "EVENT_TYPE=\"ANYKEY_PRESS\"";
    case EVENT_AFTER_INPUT:
      return "EVENT_TYPE=\"AFTER INPUT\"";
    case EVENT_BEFORE_INPUT:
      return "EVENT_TYPE=\"BEFORE INPUT\"";

    case EVENT_AFTER_DISPLAY:
      return "EVENT_TYPE=\"AFTER DISPLAY\"";
    case EVENT_BEFORE_DISPLAY:
      return "EVENT_TYPE=\"BEFORE DISPLAY\"";
    case EVENT_AFTER_CONSTRUCT:
      return "EVENT_TYPE=\"AFTER CONSTRUCT\"";
    case EVENT_BEFORE_CONSTRUCT:
      return "EVENT_TYPE=\"BEFORE CONSTRUCT\"";
    case EVENT_BEFORE_MENU:
      return "EVENT_TYPE=\"BEFORE MENU\"";
    case EVENT_AFTER_EVENT:
      return "EVENT_TYPE=\"AFTER EVENT\"";
    case EVENT_BEFORE_CLOSE_FORM:
      return "EVENT_TYPE=\"BEFORE CLOSE_FORM\"";
    case EVENT_BEFORE_ANY:
      return "EVENT_TYPE=\"BEFORE ANY\"";
    case EVENT_AFTER_ANY:
      return "EVENT_TYPE=\"AFTER ANY\"";
    case EVENT_BEFORE_EVENT:
      return "EVENT_TYPE=\"BEFORE EVENT\"";


    case EVENT_ON_IDLE:
      return "EVENT_ON_IDLE";
    case EVENT_ON_INTERVAL:
      return "EVENT_ON_INTERVAL";
    case EVENT_ON_TIME:
      return "EVENT_ON_TIME";

    case EVENT_KEY_PRESS:
      sprintf (buff, "EVENT_TYPE=\"KEY_PRESS\" KEYS=\"%s\"", xml_encode (get_str_list (a->event_data_u.key)));
      return buff;
      //case EVENT_ON_ACTION: get_str_list(on_action);
      //case EVENT_ON:                *on;

    case EVENT_BEFORE_FIELD:
      sprintf (buff, "EVENT_TYPE=\"BEFORE_FIELD\" FIELDLIST=\"%s\"", xml_encode (get_field_list (a->event_data_u.before_field)));
      return buff;
    case EVENT_AFTER_FIELD:
      sprintf (buff, "EVENT_TYPE=\"AFTER_FIELD\" FIELDLIST=\"%s\"", xml_encode (get_field_list (a->event_data_u.after_field)));
      return buff;
    case EVENT_MENU_COMMAND:
      sprintf (buff, "EVENT_TYPE=\"MENU_COMMAND\" %s", get_menu_option (a->event_data_u.mnoption));
      return buff;
      //case EVENT_BEFORE:    str_list *before;
      //case EVENT_AFTER:     str_list *after;
    }

  return "Blah2";
}


static int
add_calltree_calls_from_events (char *s, struct on_events *evt_list, int mode)
{
  int a;
  int cnt = 0;
  int xcnt = 0;
  if (evt_list == 0)
    return 0;
  for (a = 0; a < evt_list->event.event_len; a++)
    {

      xcnt = add_calltree_calls (s, evt_list->event.event_val[a]->on_event_commands, MODE_TRY);
      cnt += xcnt;
      if (xcnt)
	{
	  if (mode == MODE_BUY)
	    {
	      print_indent ();
	      fprintf (output, "<EVENT %s>\n", get_event (&evt_list->event.event_val[a]->evt_data));
	      indent++;
	    }

	if (mode==MODE_BUY) {
	  print_indent ();
	  fprintf (output, "<COMMANDS>\n");
	  indent++;
	}
	  add_calltree_calls (s, evt_list->event.event_val[a]->on_event_commands, mode);
	if (mode==MODE_BUY) {

	  indent--;
	  print_indent ();
	  fprintf (output, "</COMMANDS>\n");
	}

	  if (mode == MODE_BUY)
	    {
	      indent--;
	      print_indent ();
	      fprintf (output, "</EVENT>\n");
	    }
	}
    }

  return cnt;
}


static int
calls_something (commands * func_commands)
{
  return add_calltree_calls ("", func_commands, MODE_TRY);
}

static int
add_calltree_calls (char *s, commands * func_commands, int mode)
{
  int a;
  int cnt;
  struct on_events *evt_list;
  struct struct_display_cmd *disp;
  int call_cnt = 0;

  if (func_commands == 0)
    return 0;

  for (a = 0; a < func_commands->cmds.cmds_len; a++)
    {
      switch (func_commands->cmds.cmds_val[a]->cmd_data.type)
	{

	case E_CMD_FOR_CMD:

	  call_cnt += cache_expression ("", &func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.for_cmd.start, mode);
	  call_cnt += cache_expression ("", &func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.for_cmd.end, mode);
	  call_cnt += cache_expression ("", &func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.for_cmd.step, mode);

	  if (calls_something (func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.for_cmd.for_commands))
	    {
	      call_cnt++;
	      if (mode == MODE_BUY)
		{
		print_indent();
		  fprintf (output, "<FOR START=\"%s\"",
			   xml_encode (expr_as_string_when_possible
				       (func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.for_cmd.start)));
		  fprintf (output, " END=\"%s\"",
			   xml_encode (expr_as_string_when_possible
				       (func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.for_cmd.end)));
		  fprintf (output, " STEP=\"%s\" LINE=\"%d\">\n",
			   xml_encode (expr_as_string_when_possible
				       (func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.for_cmd.end)),
				func_commands->cmds.cmds_val[a]->lineno
	
		);
		  indent++;
	  print_indent ();
		  fprintf (output, "<COMMANDS>\n");
		  indent++;
		  add_calltree_calls ("", func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.for_cmd.for_commands, mode);
		  indent--;
	  print_indent ();
		  fprintf (output, "</COMMANDS>\n");
		  indent--;
		print_indent();
		  fprintf (output, "</FOR>\n");
		}
	    }
	  break;

	case E_CMD_IF_CMD:
	  {
	    struct struct_if_cmd *ifcmd;
	    int printed_if = 0;
	
	    ifcmd = &func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.if_cmd;

	    for (cnt = 0; cnt < ifcmd->truths.conditions.conditions_len; cnt++)
	      {
				cnt += cache_expression ("", &ifcmd->truths.conditions.conditions_val[cnt].test_expr, mode);
	      }



	    for (cnt = 0; cnt < func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.if_cmd.truths.conditions.conditions_len;
		 cnt++)
	      {
		if (calls_something
		    (func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.if_cmd.truths.conditions.conditions_val[cnt].
		     whentrue))
		  {
		    call_cnt++;
		    if (mode == MODE_BUY)
		      {
			if (!printed_if)
			  {
			    printed_if++;
			    print_indent ();
			    fprintf (output, "<IF CONDITION=\"%s\" LINE=\"%d\">\n",
				     xml_encode (expr_as_string_when_possible
						 (ifcmd->truths.conditions.conditions_val[cnt].test_expr)),
						func_commands->cmds.cmds_val[a]->lineno
					);
			  }
			indent++;
			print_indent ();
			fprintf (output, "<ONTRUE>\n");
			indent++;
	  print_indent ();
			fprintf (output, "<COMMANDS>\n");
			indent++;
			add_calltree_calls ("",
					    func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.if_cmd.truths.conditions.
					    conditions_val[cnt].whentrue, mode);
			indent--;
	  print_indent ();
			fprintf (output, "</COMMANDS>\n");
			indent--;
			print_indent ();
			fprintf (output, "</ONTRUE>\n");
			indent--;
		      }
		  }
	      }

	    if (func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.if_cmd.whenfalse)
	      {
		if (calls_something (func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.if_cmd.whenfalse))
		  {
		    call_cnt++;
		    if (mode == MODE_BUY)
		      {
			if (!printed_if)
			  {
			    printed_if++;
			    print_indent ();
			    fprintf (output, "<IF CONDITION=\"%s\">\n",
				     xml_encode (expr_as_string_when_possible
						 (ifcmd->truths.conditions.conditions_val[0].test_expr)));
			  }
			indent++;
			print_indent ();
			fprintf (output, "<ONFALSE>\n");
			indent++;
	  print_indent ();
			fprintf (output, "<COMMANDS>\n");
			indent++;
			add_calltree_calls ("", func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.if_cmd.whenfalse, mode);
			indent--;
	  print_indent ();
			fprintf (output, "</COMMANDS>\n");
			indent--;
			print_indent ();
			fprintf (output, "</ONFALSE>\n");
			indent--;
		      }

		  }

	      }
	    if (printed_if)
	      {
		print_indent ();
		fprintf (output, "</IF>\n");
	      }
	  }
	  break;

	case E_CMD_FOREACH_CMD:
	  if (calls_something(func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.foreach_cmd.foreach_commands))
	    {
	      call_cnt++;
	      if (mode == MODE_BUY)
		{
		  print_indent(); fprintf (output, "<FOREACH LINE=\"%d\">\n", func_commands->cmds.cmds_val[a]->lineno);
		  indent++;
	  	print_indent ();
		  fprintf (output, "<COMMANDS>\n");
		  indent++;
		  add_calltree_calls ("", func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.foreach_cmd.foreach_commands,
				      mode);
		  indent--;
	  	print_indent ();
		  fprintf (output, "</COMMANDS>\n");
		  indent--;
		  print_indent(); fprintf (output, "</FOREACH>\n");
		}
	    }
	  break;

	case E_CMD_WHILE_CMD:
	  call_cnt += cache_expression ("", &func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.while_cmd.while_expr, mode);
	  if (calls_something (func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.while_cmd.while_commands))
	    {
	      call_cnt++;

	      if (mode == MODE_BUY)
		{
		  print_indent(); fprintf (output, "<WHILE CONDITION=\"%s\" LINE=\"%d\">\n",
			   xml_encode (expr_as_string_when_possible
				       (func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.while_cmd.while_expr)), func_commands->cmds.cmds_val[a]->lineno);
		  indent++;
	  print_indent ();
		  fprintf (output, "<COMMANDS>\n");
		  indent++;
		  add_calltree_calls ("", func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.while_cmd.while_commands, mode);
		  indent--;
	  print_indent ();
		  fprintf (output, "</COMMANDS>\n");
		  indent--;
		  print_indent(); fprintf (output, "</WHILE>\n");
		}
	    }
	  break;


	case E_CMD_CASE_CMD:
	  {
	    struct struct_case_cmd *casecmd;
	    int printed_case = 0;

	    casecmd = &func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.case_cmd;

	    cache_expression ("", &casecmd->case_expr, mode);

	    for (cnt = 0; cnt < func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.case_cmd.whens->whens.whens_len; cnt++)
	      {

		call_cnt += cache_expression ("", &casecmd->whens->whens.whens_val[cnt]->when_expr, mode);

		if (calls_something
		    (func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.case_cmd.whens->whens.whens_val[cnt]->when_commands))
		  {
		    call_cnt++;
		    if (mode == MODE_BUY)
		      {
			if (!printed_case)
			  {
			    if (casecmd->case_expr)
			      {
				print_indent ();
				fprintf (output, "<CASE TESTAGAINST=\"%s\" LINE=\"%d\">\n",
					 xml_encode (expr_as_string_when_possible (casecmd->case_expr)), func_commands->cmds.cmds_val[a]->lineno);
				printed_case = 1;
				indent++;
			      }
			    else
			      {
				print_indent ();
				fprintf (output, "<CASE>\n");
				printed_case = 1;
				indent++;
			      }
			  }
			print_indent ();
			fprintf (output, "<WHEN CONDITION=\"%s\" LINE=\"%d\">\n",
				 xml_encode (expr_as_string_when_possible (casecmd->whens->whens.whens_val[cnt]->when_expr)), casecmd->whens->whens.whens_val[cnt]->lineno);
			indent++;
			print_indent(); fprintf (output, "<COMMANDS>\n");
			indent++;
			add_calltree_calls ("",
					    func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.case_cmd.whens->whens.
					    whens_val[cnt]->when_commands, mode);
			indent--;
			print_indent(); fprintf (output, "</COMMANDS>\n");
			indent--;
			print_indent ();
			fprintf (output, "</WHEN>\n");
		      }
		  }
	      }


	    if (func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.case_cmd.otherwise)
	      {
		if (calls_something (func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.case_cmd.otherwise))
		  {
		    call_cnt++;
		    if (mode == MODE_BUY)
		      {
			if (!printed_case)
			  {
			    print_indent ();
			    fprintf (output, "<CASE LINE=\"%d\">\n", func_commands->cmds.cmds_val[a]->lineno);
			    printed_case = 1;
			    indent++;
			  }
			indent++;
			print_indent ();
			fprintf (output, "<OTHERWISE>\n");
			print_indent(); fprintf (output, "<COMMANDS>\n");
			indent++;
			add_calltree_calls ("", func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.case_cmd.otherwise, mode);
			indent--;
			print_indent(); fprintf (output, "</COMMANDS>\n");
			print_indent ();
			fprintf (output, "</OTHERWISE>\n");
			indent--;
		      }
		  }
	      }
	    if (printed_case && mode == MODE_BUY)
	      {
		indent--;
		print_indent ();
		fprintf (output, "</CASE>\n");
	      }
	  }

	  break;



	case E_CMD_START_CMD:
	  print_indent ();
	  fprintf (output, "<START REPORT=\"%s\" LINE=\"%d\"/>\n", func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.start_cmd.repname, func_commands->cmds.cmds_val[a]->lineno);
	  call_cnt++;
	  break;

	case E_CMD_FINISH_CMD:
	  print_indent ();
	  fprintf (output, "<FINISH REPORT=\"%s\" LINE=\"%d\"/>\n",
		   func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.finish_cmd.repname, func_commands->cmds.cmds_val[a]->lineno);
	  call_cnt++;
	  break;

	case E_CMD_OUTPUT_CMD:
	  cache_expression_list ("", func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.output_cmd.expressions, mode);
	  print_indent ();
	  fprintf (output, "<OUTPUT REPORT=\"%s\" LINE=\"%d\"/>\n",
		   func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.output_cmd.repname,func_commands->cmds.cmds_val[a]->lineno);
	  call_cnt++;
	  break;


	case E_CMD_MENU_CMD:
	  {
	    int does_call;
	    evt_list = func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.menu_cmd.events;
	    does_call = add_calltree_calls_from_events ("", evt_list, MODE_TRY);
	    if (does_call)
	      {
		call_cnt += does_call;
		if (mode == MODE_BUY)
		  {
		    print_indent ();
		    fprintf (output, "<MENU LINE=\"%d\">\n", func_commands->cmds.cmds_val[a]->lineno);
		    indent++; print_indent(); fprintf (output, "<EVENTS>\n");
		    indent++;
		    add_calltree_calls_from_events ("", evt_list, mode);
		    indent--; print_indent(); fprintf (output, "</EVENTS>\n");
		    indent--;
		    print_indent ();
		    fprintf (output, "</MENU>\n");
		  }
	      }
	  }
	  break;

	case E_CMD_PROMPT_CMD:
	  {
	    int does_call;
	    evt_list = func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.prompt_cmd.events;
	    does_call = add_calltree_calls_from_events ("", evt_list, MODE_TRY);
	    if (does_call)
	      {
		call_cnt += does_call;
		if (mode == MODE_BUY)
		  {
		    print_indent ();
		    fprintf (output, "<PROMPT LINE=\"%d\">\n", func_commands->cmds.cmds_val[a]->lineno);
		    indent++; print_indent(); fprintf (output, "<EVENTS>\n");
		    indent++;
		    add_calltree_calls_from_events ("", evt_list, mode);
		    indent--; print_indent(); fprintf (output, "</EVENTS>\n");
		    indent--;
		    print_indent ();
		    fprintf (output, "</PROMPT>\n");
		  }
	      }
	  }
	  break;

	case E_CMD_DISPLAY_ARRAY_CMD:
	  {
	    int does_call;
	    evt_list = func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.display_array_cmd.events;
	    does_call = add_calltree_calls_from_events ("", evt_list, MODE_TRY);
	    if (does_call)
	      {
		call_cnt += does_call;
		if (mode == MODE_BUY)
		  {
		    print_indent ();
		    fprintf (output, "<DISPLAYARRAY LINE=\"%d\">\n", func_commands->cmds.cmds_val[a]->lineno);
		    indent++; print_indent(); fprintf (output, "<EVENTS>\n");
		    indent++;
		    add_calltree_calls_from_events ("", evt_list, mode);
		    indent--; print_indent(); fprintf (output, "</EVENTS>\n");
		    indent--;
		    print_indent ();
		    fprintf (output, "</DISPLAYARRAY>\n");
		  }
	      }
	  }
	  break;

	case E_CMD_INPUT_CMD:
	  {
	    int does_call;
	    evt_list = func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.input_cmd.events;
	    does_call = add_calltree_calls_from_events ("", evt_list, MODE_TRY);
	    if (does_call)
	      {
		call_cnt += does_call;
		if (mode == MODE_BUY)
		  {
		    print_indent ();
		    fprintf (output, "<INPUT LINE=\"%d\">\n", func_commands->cmds.cmds_val[a]->lineno);
		    indent++; print_indent(); fprintf (output, "<EVENTS>\n");
		    indent++;
		    add_calltree_calls_from_events ("", evt_list, mode);
		    indent--; print_indent(); fprintf (output, "</EVENTS>\n");
		    indent--;
		    print_indent ();
		    fprintf (output, "</INPUT>\n");
		  }
	      }
	  }
	  break;

	case E_CMD_INPUT_ARRAY_CMD:
	  {
	    int does_call;
	    evt_list = func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.input_array_cmd.events;
	    does_call = add_calltree_calls_from_events ("", evt_list, MODE_TRY);
	    if (does_call)
	      {
		call_cnt += does_call;
		if (mode == MODE_BUY)
		  {
		    print_indent ();
		    fprintf (output, "<INPUTARRAY LINE=\"%d\">\n", func_commands->cmds.cmds_val[a]->lineno);
		    indent++; print_indent(); fprintf (output, "<EVENTS>\n");
		    indent++;
		    add_calltree_calls_from_events ("", evt_list, mode);
		    indent--; print_indent(); fprintf (output, "</EVENTS>\n");
		    indent--;
		    print_indent ();
		    fprintf (output, "</INPUTARRAY>\n");
		  }
	      }
	  }
	  break;

	case E_CMD_CONSTRUCT_CMD:
	  {
	    int does_call;
	    evt_list = func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.construct_cmd.events;
	    does_call = add_calltree_calls_from_events ("", evt_list, MODE_TRY);
	    if (does_call)
	      {
		call_cnt += does_call;
		if (mode == MODE_BUY)
		  {
		    print_indent ();
		    fprintf (output, "<CONSTRUCT LINE=\"%d\">\n", func_commands->cmds.cmds_val[a]->lineno);
		    indent++; print_indent(); fprintf (output, "<EVENTS>\n");
		    indent++;
		    add_calltree_calls_from_events ("", evt_list, mode);
		    indent--; print_indent(); fprintf (output, "</EVENTS>\n");
		    indent--;
		    print_indent ();
		    fprintf (output, "</CONSTRUCT>\n");
		  }
	      }
	    break;
	  }





	case E_CMD_DISPLAY_CMD:
	  disp = &func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.display_cmd;
	  call_cnt += cache_expression_list ("", disp->exprs, mode);
	  if (disp->where->dttype == DT_DISPLAY_TYPE_AT)
	    {
	      call_cnt += cache_expression ("", &disp->where->dt_display_u.x_y.x, mode);
	      call_cnt += cache_expression ("", &disp->where->dt_display_u.x_y.y, mode);
	    }
	  break;


	case E_CMD_ERROR_CMD:
	  call_cnt +=
	    cache_expression_list ("", func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.error_cmd.expr_list, mode);
	  break;

	case E_CMD_SLEEP_CMD:
	  call_cnt += cache_expression ("", &func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.sleep_cmd.sleep_expr, mode);
	  break;

	case E_CMD_MOVE_CMD:
	  call_cnt += cache_expression ("", &func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.move_cmd.x, mode);
	  call_cnt += cache_expression ("", &func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.move_cmd.y, mode);
	  break;

	case E_CMD_SHOW_MENU_CMD:
	  call_cnt += cache_expression ("", &func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.show_menu_cmd.mn_file, mode);
	  break;

	case E_CMD_RUN_CMD:
	  call_cnt += cache_expression ("", &func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.run_cmd.run_string, mode);
	  break;

	case E_CMD_SCROLL_CMD:
	  call_cnt += cache_expression ("", &func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.scroll_cmd.val, mode);
	  break;
	case E_CMD_EXIT_PROG_CMD:
	  call_cnt += cache_expression ("", &func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.exit_prog_cmd.exit_val, mode);
	  break;

	case E_CMD_RETURN_CMD:
	  call_cnt += cache_expression_list ("", func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.return_cmd.retvals, mode);
	  break;

	case E_CMD_MESSAGE_CMD:
	  call_cnt +=
	    cache_expression_list ("", func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.message_cmd.message_expr, mode);
	  break;


	case E_CMD_CALL_CMD:
	  call_cnt += cache_expression ("", &func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.call_cmd.fcall, mode);
	  break;

	case E_CMD_PDF_CALL_CMD:
	  call_cnt += cache_expression ("", &func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.pdf_call_cmd.fcall, mode);
	  break;

	case E_CMD_LET_CMD:
	  call_cnt += cache_expression_list ("", func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.let_cmd.vals, mode);
	  break;


	case E_CMD_OPEN_WINDOW_CMD:
	  call_cnt += cache_expression ("", &func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.open_window_cmd.x, mode);
	  call_cnt += cache_expression ("", &func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.open_window_cmd.y, mode);
	  if (func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.open_window_cmd.wt.wintype == EWT_FORM)
	    {
	      call_cnt += cache_expression ("",
					    &func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.open_window_cmd.wt.
					    windowtype_u.formfilename, mode);
	    }
	  break;

	case E_CMD_FETCH_CMD:
	  if (func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.fetch_cmd.fetch)
	    {
	      if (func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.fetch_cmd.fetch->fp)
		{
		  call_cnt +=
		    cache_expression ("", &func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.fetch_cmd.fetch->fp->fetch_expr,
				      mode);
		}
	    }
	  break;

	case E_CMD_OPEN_FORM_CMD:
	  call_cnt +=
	    cache_expression ("", &func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.open_form_cmd.form_filename, mode);
	  break;



	case E_CMD_SET_DATABASE_CMD:
	  call_cnt +=
	    cache_expression ("", &func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.set_database_cmd.set_dbname, mode);
	  break;

	case E_CMD_NEED_CMD:
	  call_cnt += cache_expression ("", &func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.need_cmd.expr, mode);
	  break;
	case E_CMD_PRINT_CMD:
	  call_cnt +=
	    cache_expression_list ("", func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.print_cmd.print_expr, mode);
	  break;

	case E_CMD_PRINT_IMG_CMD:
	  call_cnt += cache_expression ("", &func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.print_img_cmd.scale_x, mode);
	  call_cnt += cache_expression ("", &func_commands->cmds.cmds_val[a]->cmd_data.command_data_u.print_img_cmd.scale_y, mode);
	  break;




	default:
	  break;
	}
    }

  return call_cnt;
}



/*
int
run_calltree (int n)
{
  int a;
  if (isoncallstack (functions[n].function))
    {
      // Recursion somewhere....
      return 0;
    }

  if (functions[n].called)
    {
      if (functions[n].called != callstack_cnt)
	{
  		print_spaces (callstack_cnt); printf ("%s^\n", functions[n].function);
	}
      return;
    }

  print_spaces (callstack_cnt); 
	printf ("%s\n", functions[n].function);
  functions[n].called = callstack_cnt;

  add_to_callstack (functions[n].function);
  if (functions[n].f_or_r == 'F')
    {
      struct s_function_definition *f;
      f = functions[n].ptr;
      add_calltree_calls ("", f->func_commands);
    }
  pop_callstack ();
  return 1;
}
*/

int
check_program (module_definition * mods, int nmodules)
{
  char *dbname = 0;
  int a;
  int b;
  int *calltree;
  int bad_load = 0;
  struct commands *all_cmds = 0;
  char *fname;
  int mid;

  fname = acl_getenv_not_set_as_0 ("CFUNCSFILE");
  if (fname)
    {
      load_boltons (fname);
    }
  else
    {
      printf ("WARNING - not CFUNCSFILE file specified\n");
    }

  for (a = 0; a < nmodules; a++)
    {
      printf ("Module : %s.4gl\n", mods[a].module_name);
      for (b = 0; b < mods[a].module_entries.module_entries_len; b++)
	{
	  switch (mods[a].module_entries.module_entries_val[b]->met_type)
	    {

	    case E_MET_MAIN_DEFINITION:
	      add_function (mods[a].module_name,
			    mods[a].module_entries.module_entries_val[b]->module_entry_u.function_definition.lineno,
			    "MAIN", 'F', &mods[a].module_entries.module_entries_val[b]->module_entry_u.function_definition);
	      break;

	    case E_MET_FUNCTION_DEFINITION:
	      add_function (mods[a].module_name,
			    mods[a].module_entries.module_entries_val[b]->module_entry_u.function_definition.lineno,
			    mods[a].module_entries.module_entries_val[b]->module_entry_u.function_definition.funcname,
			    'F', &mods[a].module_entries.module_entries_val[b]->module_entry_u.function_definition);
	      break;

	    case E_MET_REPORT_DEFINITION:
	      add_function (mods[a].module_name,
			    mods[a].module_entries.module_entries_val[b]->module_entry_u.report_definition.lineno,
			    mods[a].module_entries.module_entries_val[b]->module_entry_u.report_definition.funcname,
			    'R', &mods[a].module_entries.module_entries_val[b]->module_entry_u.report_definition);
	      break;


	    default:
	      // Ignore...
	      break;
	    }
	}

    }


  printf ("Program\n");
  mid = find_function ("MAIN");
  if (mid < 0)
    {
      //printf ("No main...\n");
      //exit (2);
    }

  output = fopen ("calltree.xml", "w");
  if (output == 0)
    {
      printf ("Unable to open output file\n");
      exit (2);
    }


  fprintf (output, "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n");
  fprintf (output, "<PROGRAM>\n");

  for (a = 0; a < functions_cnt; a++)
    {
      if (functions[a].f_or_r == 'F')
	{
	  struct s_function_definition *f;
	  fprintf (output, "<FUNCTION NAME=\"%s\" MODULE=\"%s\"  LINE=\"%d\">\n", functions[a].function, functions[a].module,
		   functions[a].line);
	  f = functions[a].ptr;
	  indent++;
	  print_indent(); fprintf (output, "<COMMANDS>\n");
	  indent++;
	  add_calltree_calls ("", f->func_commands, MODE_BUY);
	  indent--;
	  print_indent(); fprintf (output, "</COMMANDS>\n");
	  indent--;
	}
      else
	{
	  int b;
	  struct s_report_definition *r;
	  fprintf (output, "<REPORT NAME=\"%s\" MODULE=\"%s\"  LINE=\"%d\">\n", functions[a].function, functions[a].module,
		   functions[a].line);
	  r = functions[a].ptr;
	  indent++;

	  for (b = 0; b < r->report_format_section->entries.entries_len; b++)
	    {
	      if (calls_something (r->report_format_section->entries.entries_val[b]->rep_sec_commands))
		{
		  print_indent ();
		  fprintf (output, "<SECTION ID=\"%d\" TYPE=\"%s\">\n", b,
			   decode_rb (r->report_format_section->entries.entries_val[b]->rb_block.rb));
		  indent++;
		  print_indent(); fprintf (output, "<COMMANDS>\n");
		  indent++;
		  add_calltree_calls ("", r->report_format_section->entries.entries_val[b]->rep_sec_commands, MODE_BUY);
		  indent--;
		  print_indent(); fprintf (output, "</COMMANDS>\n");
		  indent--;
		  print_indent ();
		  fprintf (output, "</SECTION>\n");
		}
	    }
	  indent--;
	}


      if (functions[a].f_or_r == 'F')
	{
	  fprintf (output, "</FUNCTION>\n");
	}
      else
	{
	  fprintf (output, "</REPORT>\n");
	}

    }
  fprintf (output, "</PROGRAM>\n");
  fclose (output);
  return 1;
}




static void
add_bolton (char *fname, char *params, char *rets)
{
  char *p_params[200];
  char *p_rets[200];
  int pcnt = 0;
  int rcnt = 0;
  int l;
  int a;
  nboltons++;

  fprototypes_boltons = realloc (fprototypes_boltons, sizeof (fprototypes_boltons[0]) * nboltons);

  l = strlen (params);

  if (l == 0)
    {
      pcnt = 0;
    }
  else
    {

      pcnt = 0;
      p_params[0] = params;
      for (a = 0; a <= l; a++)
	{
	  if (params[a] == ',' || params[a] == 0)
	    {
	      params[a] = 0;
	      pcnt++;
	      p_params[pcnt] = &params[a + 1];
	      continue;
	    }
	}
    }

  l = strlen (rets);
  if (l == 0)
    {
      rcnt = 0;
    }
  else
    {

      rcnt = 0;
      p_rets[0] = rets;
      for (a = 0; a <= l; a++)
	{
	  if (rets[a] == ',' || rets[a] == 0)
	    {
	      rets[a] = 0;
	      rcnt++;
	      p_rets[rcnt] = &rets[a + 1];
	      continue;
	    }
	}
    }

  fprototypes_boltons[nboltons - 1].pname = strdup (fname);
  fprototypes_boltons[nboltons - 1].proto_type = 0;
  fprototypes_boltons[nboltons - 1].nparams = pcnt;
  if (pcnt)
    {
      fprototypes_boltons[nboltons - 1].param_dtypes = malloc (sizeof (int) * pcnt);
      for (a = 0; a < pcnt; a++)
	{
	  fprototypes_boltons[nboltons - 1].param_dtypes[a] = atoi (p_params[a]);
	}
    }
  else
    {
      fprototypes_boltons[nboltons - 1].param_dtypes = 0;
    }


  fprototypes_boltons[nboltons - 1].nreturns = rcnt;
  if (rcnt)
    {
      fprototypes_boltons[nboltons - 1].return_dtypes = malloc (sizeof (int) * rcnt);
      for (a = 0; a < rcnt; a++)
	{
	  fprototypes_boltons[nboltons - 1].return_dtypes[a] = atoi (p_rets[a]);
	}
    }
  else
    {
      fprototypes_boltons[nboltons - 1].return_dtypes = 0;
    }

/*
	int nparams;
	int *param_dtypes;
	int nreturns;
	int *return_dtypes;
};
*/
}

int
is_bolton_function (char *s)
{
  int a;
  for (a = 0; a < nboltons; a++)
    {
      if (A4GL_aubit_strcasecmp (s, fprototypes_boltons[a].pname) == 0)
	{
	  return a;
	}
    }
  return -1;
}



static void
load_boltons (char *fname)
{
  FILE *f;
  int lineno = 0;
//char *funcname;
//int nparam;
//int nret;
//char *params;
//char *rets;
  int printed;
  char buff[256];
  if (fname == 0)
    return;
  if (strlen (fname) == 0)
    return;
  f = fopen (fname, "r");
  if (f == 0)
    return;

  while (1)
    {
      char *p[3];
      fgets (buff, 255, f);
      lineno++;
      if (feof (f))
	break;
      A4GL_trim (buff);
      printed = 0;

      p[0] = buff;
      p[1] = strchr (buff, '|');
      if (p[1])
	{
	  *p[1] = 0;
	  p[1]++;
	  p[2] = strchr (p[1], '|');
	  if (p[2])
	    {
	      *p[2] = 0;
	      p[2]++;
	      //printf("Loading : %s %s %s\n",p[0],p[1],p[2]);
	      printed++;
	      add_bolton (p[0], p[1], p[2]);
	    }
	}

      if (!printed)
	{
	  printf ("Bad line : %s @ %d\n", buff, lineno);
	  continue;
	}
    }
}


int yylineno;

FILE *lintfile;

module_definition this_module;

int
main (int argc, char *argv[])
{
  module_definition *m;
  int a;

  if (argc < 2)
    {
      printf ("Usage : %s infile infile...\n", argv[0]);
      exit (2);
    }

  m = malloc (sizeof (struct module_definition) * (argc - 1));

  for (a = 1; a < argc; a++)
    {
      char buff[256];
      sprintf (buff, argv[a]);
      if (strstr (buff, ".dat") != 0)
	{
	  char *p;
	  p = strstr (buff, ".dat");
	  *p = 0;
	}
      printf ("Loading %s : ", buff);
      fflush (stdout);
      if (read_module_definition (&m[a - 1], buff))
	{
	  printf ("OK...%s\n", argv[a]);
	}
      else
	{
	  printf ("- Failed to load %s\n", argv[a]);
	  exit (1);
	}
    }

  check_program (m, argc - 1);
  return 0;
}

char *
decode_rb (enum report_blocks a)
{
  switch (a)
    {
    case RB_FIRST_PAGE_HEADER:
      return "FIRST_PAGE_HEADER";
    case RB_PAGE_HEADER:
      return "PAGE_HEADER";
    case RB_PAGE_TRAILER:
      return "PAGE_TRAILER";
    case RB_ON_EVERY_ROW:
      return "ON_EVERY_ROW";
    case RB_ON_LAST_ROW:
      return "ON_LAST_ROW";

    case RB_FORMAT_EVERY_ROW:
      return "FORMAT_EVERY_ROW";

    case RB_BEFORE_GROUP_OF:
      return "BEFORE_GROUP_OF";
    case RB_AFTER_GROUP_OF:
      return "AFTER_GROUP_OF";
    }

  return "Blah3";
}

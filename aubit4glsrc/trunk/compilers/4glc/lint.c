#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"
#include "a4gl_4glc_int.h"
#include "lint.h"
#include "linearise.h"
#include "expr_munging.h"

//expr_str_list *expand_parameters(struct variable_list *var_list, expr_str_list *parameters) ;
int nomain = 0;
char *decode_cmd_type (enum cmd_type value);
int A4GL_is_valid_4gl_type (char *s);
int inc4GL = 1;
  struct s_severities
  {
    char *code;
    int severity;
  } severities[1000] =
  {
    {
    "DEAD", 5},
    { "CS.VNAME", 0},
    { "CS.GOTO", 1},
    {
    "CS.EXITDIRECT", 0},
    {
    "CS.EXITNOTMAIN", 0},
    {
    "CS.GETERRORRECORD", 0},
    {
    "CS.ERRORHANDLER", 0},
    {
    "CS.MRET", 1},
    {
    "CS.FRET", 1},
    {
    "CS.NOOTHERWISE", 1},
    {
    "CS.WRITESQLCA", 2},
    {
    "VARNOTUSED", 1},
    {
    "VARASSNOTUSED", 1},
    {
    "TOOCOMPLEX", 2},
    {
    "FUNCNOTCALLED", 4},
    {
    "VARUSED", 6},
    {
    "STRINGLONG", 3},
    {
    "MRETNUM", 8},
    {
    "CONCATFROMNONSTR", 2},
    {
    "FUNCRETCNT", 8},
    {
    "MISMATCHSELECT", 4},
    {
    "SELECTSTAR", 2},
    {
    "IFSQLCA", 2},
    {
    "SELECTNOTINTO", 2},
    {
    "INSERTNOCOLS", 2},
    {
    "CHKSTATUS", 4},
    {
    "REPORD", 3},
    {
    "DIFFMATH", 4},
    {
    "LETEXPR", 3},
    {
    "FORVARNUM", 6},
    {
    "FORENDEXPR", 4},
    {
    "VNAMEDTYPE", 6},
    {
    "PARAMNOTUSED", 2},
	{"CS.WRITEINTFLAG",3},
	{"LABELNOTUSED",2},
	{"MADMATH",6},
	{"WHENDUP",6},

    {
    NULL, 0}
  };

#define LINTMODULE_FOR_PROGRAM "[PROGRAM]"
extern int yylineno;
static int dbg = 0;
char *lint_module = 0;
static void load_boltons (char *fname);
static int find_function (char *s);
static void linearise_expressions (struct expr_str_list *list);
static void check_boolean (char *module_name, int lineno, expr_str * s, int last_was_sql, int done_true_false);
static void init_lint (void);
static void add_lint_expect (char *s);
static void add_lint_ignore (char *s);
static void set_lint_ignore (struct command *c);
static void set_lint_expect (struct command *c);

static int has_lint_ignore (char *c);
static int has_lint_expect (char *c);

static void clr_lint_expect (void);


//void log_proto( struct  expr_str *fcall, struct binding_comp_list *ret) ;
//void dump_prototypes(void) ;
//static struct commands * linearise_commands(struct commands *master_list, struct commands *cmds) ;
//static void linearise_commands_from_events(struct commands *master_list, struct on_events* evt_list) ;
static char *get_lint_filename (char *s);
static char *local_xml_escape (char *s);
static void cache_expressions (struct expr_str_list *list, struct commands *cmds);
static void cache_expression (struct expr_str_list *list, struct expr_str **eptr);
static void cache_expression_list (struct expr_str_list *list, struct expr_str_list *srclist);
static int A4GL_is_just_literal (struct expr_str_list *list, expr_str * ptr, int already_done_true_and_false);
extern module_definition this_module;
//int expr_datatype (struct expr_str *p);
static struct module_definition *find_module (module_definition * mods, int nmodules, char *name);

static void scan_functions (char *infuncname, int calltree_entry, int *calltree, struct call_list *f,
			    struct commands *calling_funcs_commands);
static void set_lint_module (char *s);

static void check_variable_name (char *modname, char *scope, struct variable *v);
static void check_cmds_for_dead_code (struct commands *cmds);
//int has_variable (struct variable_list *v, char *name) ;
//int get_lint_style(void) ;
FILE *lintfile = 0;

#define PROTO_FUNCTION 		1
#define PROTO_REPORT 		2
#define PROTO_PDF_REPORT 	3

static char *A4GL_transform_basename (char *s);
//void gen_function_prototypes(int e, struct s_function_definition *function_definition) ;

struct s_function_prototype
{
  int proto_type;
  char *pname;
  int nparams;
  int *param_dtypes;
  int nreturns;
  int *return_dtypes;
  char *module;
  int lineno;
};

static int system_function (char *funcname);
struct s_function_prototype *fprototypes = 0;

struct s_function_prototype *fboltons = 0;
int nboltons = 0;
static int is_bolton_function (char *s);


struct global_variable_function
{
  char *function;
  char *module;
  int line;
};

struct global_variable_assignement
{
  char *varname;
  struct global_variable_function *function_list;
  int nfunction_list;
};

struct global_variable_assignement *gass = 0;
int ngass = 0;


int
add_global_variable_assignement (char *s, char *currfunc, char *module, int line)
{
  int a;
// We want to keep a track of all the assignments to global variables
// and flag whenever we have more than one function assigning it a value

// DOnt worry about these ones...
  if (strcmp (s, "int_flag") == 0)
    return 0;
  if (strcmp (s, "quit_flag") == 0)
    return 0;
  if (strcmp (s, "locked") == 0)
    return 0;
  if (strcmp (s, "error_occured") == 0)
    return 0;
  if (strcmp (s, "err_line") == 0)
    return 0;

  for (a = 0; a < ngass; a++)
    {
      if (strcmp (gass[a].varname, s) == 0)
	{			// we've found it...
	  int b;
	  //int found=0;
	  for (b = 0; b < gass[a].nfunction_list; b++)
	    {
	      if (strcmp (currfunc, gass[a].function_list[b].function) == 0)
		{
		  return 1;
		}
	    }
	  gass[a].nfunction_list++;

	  gass[a].function_list =
	    realloc (gass[a].function_list, sizeof (struct global_variable_function) * gass[a].nfunction_list);
	  gass[a].function_list[gass[a].nfunction_list - 1].function = strdup (currfunc);
	  gass[a].function_list[gass[a].nfunction_list - 1].module = strdup (module);
	  gass[a].function_list[gass[a].nfunction_list - 1].line = line;
	  return 1;
	}
    }
  ngass++;
  gass = realloc (gass, sizeof (gass[0]) * ngass);
  gass[ngass - 1].varname = strdup (s);
  gass[ngass - 1].nfunction_list = 1;
  gass[ngass - 1].function_list = malloc (sizeof (struct global_variable_function));
  gass[ngass - 1].function_list[0].function = strdup (currfunc);
  gass[ngass - 1].function_list[0].module = strdup (module);
  gass[ngass - 1].function_list[0].line = line;


  return 0;
}

/*
static void set_assigned_binding_var(struct binding_comp *v,char *currfunc,char *module, int line) {
	if (v->scope=='G' || v->scope=='g') {
			char buff[2000];
			char *ptr;
			strcpy(buff,v->varname);
			ptr=strchr(buff,'[');
			if (ptr) *ptr=0;
			add_global_variable_assignement(buff,currfunc,module,line);
			//printf("ASSIGNMENT OF GLOBALS %s\n",buff);
	}
}

static void set_assigned_binding(struct binding_comp_list *vlist, char *currfunc, char *module, int line) {
int a;
	if (vlist==0) return;
	if (vlist->list.list_len==0) return;
	for (a=0;a<vlist->list.list_len;a++) {
		set_assigned_binding_var(&vlist->list.list_val[a],currfunc,module,line);
	}


	//
}
*/

expr_str_list *expr_cache = 0;
static int promoteable (int a, int b);

static void
set_expr_cache (expr_str_list * n)
{
  expr_cache = n;
}


static int
is_numeric (int dtype)
{
  dtype = dtype & DTYPE_MASK;
  switch (dtype)
    {
    case DTYPE_INT:
    case DTYPE_SMINT:
    case DTYPE_FLOAT:
    case DTYPE_SMFLOAT:
    case DTYPE_DECIMAL:
    case DTYPE_MONEY:
    case DTYPE_SERIAL:
      return 1;
    }
  return 0;
}

expr_str *
get_cached_expr_datatype (int n)
{
  A4GL_assertion (expr_cache == 0, "No expression cache");
  if (n > expr_cache->list.list_len || n < 0)
    {
      A4GL_assertion (1, "Expression cache subscript out of range");
    }
  return expr_cache->list.list_val[n];
}

char *
lint_get_variable_usage_as_string (struct variable_usage *var_usage)
{
  char buff[2000];

  sprintf (buff, "%s", var_usage->variable_name);
  if (var_usage->subscripts.subscripts_len)
    {
      int a;
      strcat (buff, "[");
      for (a = 0; a < var_usage->subscripts.subscripts_len; a++)
	{
	  if (a)
	    strcat (buff, ",");
	  strcat (buff, expr_as_string_when_possible (var_usage->subscripts.subscripts_val[a]));
	}
      strcat (buff, "]");
    }
  if (var_usage->substrings_start)
    {
      strcat (buff, "[");
      strcat (buff, expr_as_string_when_possible (var_usage->substrings_start));
      if (var_usage->substrings_end)
	{
	  strcat (buff, ",");
	  strcat (buff, expr_as_string_when_possible (var_usage->substrings_end));
	}
      strcat (buff, "]");
    }
  if (var_usage->next)
    {
      char *ptr;
      strcat (buff, ".");
      ptr = lint_get_variable_usage_as_string (var_usage->next);
      strcat (buff, ptr);
      free (ptr);
    }

  return strdup (buff);
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
check_cmds_for_bad_key (int keycode, enum cmd_type cmd_type)
{
  if (cmd_type == E_CMD_INPUT_CMD || cmd_type == E_CMD_PROMPT_CMD || cmd_type == E_CMD_DISPLAY_ARRAY_CMD
      || cmd_type == E_CMD_CONSTRUCT_CMD)
    {
      if (keycode == A4GLKEY_NEXT || keycode == A4GLKEY_PREV || keycode == A4GLKEY_INSERT || keycode == A4GLKEY_DELETE
	  || keycode == A4GLKEY_NEXTPAGE || keycode == A4GLKEY_PREVPAGE)
	{
	  return 1;
	}
    }
  return 0;
}



static int *
get_key_codes (char *keys)
{
  char s[1024];
  char *k;
  char *k1;
  static int *x = 0;
  int xcnt = 0;

  if (x)
    {
      free (x);
      x = 0;
    }

  strcpy (s, keys);
  A4GL_trim (s);
  strcat (s, "||");
  A4GL_debug ("Chk keys %s\n", s);

  if (strcmp (keys, "->ANY") == 0)
    {
      x = acl_malloc2 (sizeof (int) * 2);
      x[0] = 0xffff;
      x[1] = 0;
      return x;
    }

  k = s;

  while (1)
    {
      k1 = k;
      k = strstr (k1, "||");
      if (k == 0)
	break;
      *k = 0;
      k += 2;
      xcnt++;
      x = realloc (x, sizeof (int) * xcnt);
      x[xcnt - 1] = A4GL_key_val (k1);
    }


  xcnt++;
  x = realloc (x, sizeof (int) * xcnt);
  x[xcnt - 1] = 0;
  return x;
}




static void
check_cmds_for_bad_keys (struct on_events *evt_list, struct command *cmd)
{
  enum cmd_type cmd_type;
  int a;
  int *keys;

  cmd_type = cmd->cmd_data.type;

  if (evt_list == 0)
    return;

  for (a = 0; a < evt_list->event.event_len; a++)
    {
      if (evt_list->event.event_val[a]->evt_data.event_type == EVENT_KEY_PRESS)
	{
	  int b;
	  int c;
	  str_list *sl;
	  sl = evt_list->event.event_val[a]->evt_data.event_data_u.key;
	  if (sl)
	    {
	      for (c = 0; c < sl->str_list_entry.str_list_entry_len; c++)
		{
		  keys = get_key_codes (sl->str_list_entry.str_list_entry_val[c]);
		  for (b = 0; keys[b]; b++)
		    {
		      if (keys[b] == -1)
			{	// Invalid key code...
			  A4GL_lint (cmd->module, evt_list->event.event_val[a]->lineno, "BADKEY", "Invalid key code", 0);
			}

		      if (check_cmds_for_bad_key (keys[b], cmd_type))
			{
			  A4GL_lint (cmd->module, evt_list->event.event_val[a]->lineno, "BADKEYCONTEXT", "Invalid key code in this context", sl->str_list_entry.str_list_entry_val[c]);
			}
		    }
		}
	    }
	}
    }

}

static void
check_cmds_for_dead_code_from_events (struct on_events *evt_list)
{
  int a;

  if (evt_list == 0)
    return;

  for (a = 0; a < evt_list->event.event_len; a++)
    {

      check_cmds_for_dead_code (evt_list->event.event_val[a]->on_event_commands);
    }

}


static void
check_cmds_for_dead_code (struct commands *cmds)
{
  int a;
  int cnt;
  int ignore = 0;
  int reported = 0;
  struct on_events *evt_list;

  if (cmds == 0)
    return;

  for (a = 0; a < cmds->cmds.cmds_len; a++)
    {

      if (cmds->cmds.cmds_val[a]->cmd_data.type == E_CMD_LINT_EXPECT_CMD)
	{
	  set_lint_expect (cmds->cmds.cmds_val[a]);
	  continue;
	}
      if (cmds->cmds.cmds_val[a]->cmd_data.type == E_CMD_LINT_IGNORE_CMD)
	{
	  set_lint_ignore (cmds->cmds.cmds_val[a]);
	  continue;
	}

      if (ignore && cmds->cmds.cmds_val[a]->cmd_data.type != E_CMD_WHENEVER_CMD
	  && cmds->cmds.cmds_val[a]->cmd_data.type != E_CMD_LABEL_CMD)
	{
	  yylineno = cmds->cmds.cmds_val[a]->lineno;
	  A4GL_lint (cmds->cmds.cmds_val[a]->module, cmds->cmds.cmds_val[a]->lineno, "DEAD", "Dead code detected", 0);
	  reported++;
	  return;
	}

      switch (cmds->cmds.cmds_val[a]->cmd_data.type)
	{

	case E_CMD_FOR_CMD:
	  check_cmds_for_dead_code (cmds->cmds.cmds_val[a]->cmd_data.command_data_u.for_cmd.for_commands);

	  break;

	case E_CMD_IF_CMD:
	  for (cnt = 0; cnt < cmds->cmds.cmds_val[a]->cmd_data.command_data_u.if_cmd.truths.conditions.conditions_len; cnt++)
	    {
	      check_cmds_for_dead_code (cmds->cmds.cmds_val[a]->cmd_data.command_data_u.if_cmd.truths.conditions.
					conditions_val[cnt].whentrue);
	    }
	  check_cmds_for_dead_code (cmds->cmds.cmds_val[a]->cmd_data.command_data_u.if_cmd.whenfalse);
	  break;

	case E_CMD_FOREACH_CMD:
	  check_cmds_for_dead_code (cmds->cmds.cmds_val[a]->cmd_data.command_data_u.foreach_cmd.foreach_commands);
	  break;

	case E_CMD_WHILE_CMD:
	  check_cmds_for_dead_code (cmds->cmds.cmds_val[a]->cmd_data.command_data_u.while_cmd.while_commands);
	  break;


	case E_CMD_CASE_CMD:
	  for (cnt = 0; cnt < cmds->cmds.cmds_val[a]->cmd_data.command_data_u.case_cmd.whens->whens.whens_len; cnt++)
	    {
	      check_cmds_for_dead_code (cmds->cmds.cmds_val[a]->cmd_data.command_data_u.case_cmd.whens->whens.whens_val[cnt]->
					when_commands);
	    }
	  check_cmds_for_dead_code (cmds->cmds.cmds_val[a]->cmd_data.command_data_u.case_cmd.otherwise);
	  break;


	case E_CMD_MENU_CMD:
	  evt_list = cmds->cmds.cmds_val[a]->cmd_data.command_data_u.menu_cmd.events;
	  check_cmds_for_dead_code_from_events (evt_list);
	  break;

	case E_CMD_PROMPT_CMD:
	  evt_list = cmds->cmds.cmds_val[a]->cmd_data.command_data_u.prompt_cmd.events;
	  check_cmds_for_dead_code_from_events (evt_list);
	  check_cmds_for_bad_keys (evt_list, cmds->cmds.cmds_val[a]);
	  break;

	case E_CMD_DISPLAY_ARRAY_CMD:
	  evt_list = cmds->cmds.cmds_val[a]->cmd_data.command_data_u.display_array_cmd.events;
	  check_cmds_for_dead_code_from_events (evt_list);
	  check_cmds_for_bad_keys (evt_list, cmds->cmds.cmds_val[a]);
	  break;

	case E_CMD_INPUT_CMD:
	  evt_list = cmds->cmds.cmds_val[a]->cmd_data.command_data_u.input_cmd.events;
	  check_cmds_for_dead_code_from_events (evt_list);
	  check_cmds_for_bad_keys (evt_list, cmds->cmds.cmds_val[a]);
	  break;

	case E_CMD_INPUT_ARRAY_CMD:
	  evt_list = cmds->cmds.cmds_val[a]->cmd_data.command_data_u.input_array_cmd.events;
	  check_cmds_for_dead_code_from_events (evt_list);
	  break;
	case E_CMD_CONSTRUCT_CMD:
	  evt_list = cmds->cmds.cmds_val[a]->cmd_data.command_data_u.construct_cmd.events;
	  check_cmds_for_dead_code_from_events (evt_list);
	  check_cmds_for_bad_keys (evt_list, cmds->cmds.cmds_val[a]);
	  break;


	case E_CMD_EXIT_PROG_CMD:
	case E_CMD_CONTINUE_CMD:
	case E_CMD_EXT_CMD:
	case E_CMD_RETURN_CMD:
	case E_CMD_GOTO_CMD:
	  ignore++;
	  break;

	case E_CMD_LABEL_CMD:
	  // If we jumped to this label - it'd always be in live code again..
	  ignore = 0;
	  break;

	default:
	  // dont need to do anything - these don't embed Commands..
	  break;
	}

    }
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



static void
check_function_for_complexity (struct module_definition *d, struct s_function_definition *f)
{
  int ncomments = 0;
  int a;
  struct commands *func_cmds = 0;
  int flow = 0;
  for (a = 0; a < d->comment_list.comment_list_len; a++)
    {
      if (d->comment_list.comment_list_val[a].lineno >= f->lineno && d->comment_list.comment_list_val[a].lineno <= f->lastlineno)
	ncomments++;
    }


  func_cmds = linearise_commands (0, 0);
  linearise_commands (func_cmds, f->func_commands);


  for (a = 0; a < func_cmds->cmds.cmds_len; a++)
    {
      switch (func_cmds->cmds.cmds_val[a]->cmd_data.type)
	{
	case E_CMD_WHILE_CMD:
	case E_CMD_FOR_CMD:
	case E_CMD_FOREACH_CMD:
	case E_CMD_CASE_CMD:
	case E_CMD_IF_CMD:
	case E_CMD_MENU_CMD:
	  flow++;
	  break;

	default:
	  break;
	}
    }
  if (flow > 10 || f->lastlineno - f->lineno > 250)
    {
      A4GL_lint (f->module, f->lineno, "TOOCOMPLEX", "Function is too complex", f->funcname);
    }


}


static int
expr_char_length (char *module, int lineno, expr_str * ptr)
{
  int d;
  int sz;
  FILE *f;
  d = expr_datatype (module, lineno, ptr);

  if (!is_char_dtype (d))
    {
      return 0;			// its not a character string - assume at least '0'
      // (ie - ignore it - theres not much else we can do)
    }



  sz = d >> 16;
  if (sz)
    {
      return sz;		// We've got it already !!!
    }



  // Gonna need to work it out...
  switch (ptr->expr_type)
    {
    case ET_EXPR_LITERAL_STRING:
      return strlen (ptr->expr_str_u.expr_string);

    case ET_EXPR_OP_USING:
      return expr_char_length (module, lineno, ptr->expr_str_u.expr_op->right);

    case ET_EXPR_UPSHIFT:
      return expr_char_length (module, lineno, ptr->expr_str_u.expr_expr);

    case ET_EXPR_DOWNSHIFT:
      return expr_char_length (module, lineno, ptr->expr_str_u.expr_expr);

    case ET_EXPR_OP_CLIP:
      return 0;			// Anything clipped can probably be 0 length...

    case ET_EXPR_CACHED:
      A4GL_assertion (1, "Cached expression not handled");

    default:
      break;
    }

  if (strlen (acl_getenv ("DEBUG")))
    {
      f = fopen ("/tmp/expr_char_length.out", "a");
      if (f)
	{
	  fprintf (f, "Expr %d Datatype %d\n", ptr->expr_type, d);
	  fclose (f);
	}
    }


  return 0;			// Ignore its length
}

static int
isParameter (struct variable *var, expr_str_list * parameters)
{
  char *str;
//variable_list vlist;
  int a;
  if (parameters == 0)
    return 0;
  for (a = 0; a < parameters->list.list_len; a++)
    {
      if (parameters->list.list_val[a]->expr_type == ET_EXPR_VARIABLE_USAGE)
	{
	  str = lint_get_variable_usage_as_string (parameters->list.list_val[a]->expr_str_u.expr_variable_usage);
	  if (strcmp (var->names.names.names_val[0].name, str) == 0)
	    {
	      return 1;
	    }
	}
    }


  return 0;
}

static void
check_variables (char *module_name, struct module_definition *d, variable_list * variables, expr_str_list * parameters)
{
  int a;
//char *module_name;

  //module_name=d->module_name;
  //parameters=expand_parameters(variables, parameters);


  for (a = 0; a < variables->variables.variables_len; a++)
    {
      char *localname;
      struct variable *v;
      v = variables->variables.variables_val[a];
      if (v->var_data.variable_type == VARIABLE_TYPE_CONSTANT)
	continue;

      localname = variables->variables.variables_val[a]->names.names.names_val[0].name;

      check_variable_name (module_name, "Local", variables->variables.variables_val[a]);

      if (has_variable (&d->imported_global_variables, localname))
	{
	  A4GL_lint (module_name, variables->variables.variables_val[a]->lineno, "CS.VARHIDE", "Coding Standards: Local variable hides an imported Global variable", variables->variables.variables_val[a]->names.names.names_val[0].name);
	}

      if (has_variable (&d->exported_global_variables, localname))
	{
	  A4GL_lint (module_name, variables->variables.variables_val[a]->lineno, "CS.VARHIDE", "Coding Standards: Local variable hides an exported Global variable", variables->variables.variables_val[a]->names.names.names_val[0].name);
	}
      if (has_variable (&d->module_variables, localname))
	{
	  A4GL_lint (module_name, variables->variables.variables_val[a]->lineno, "CS.VARHIDE", "Coding Standards: Local variable hides a Module variable", variables->variables.variables_val[a]->names.names.names_val[0].name);
	}


      if (variables->variables.variables_val[a]->flags & 1)
	{
	  A4GL_lint (module_name, variables->variables.variables_val[a]->lineno, "VARUSED", "Local variable is used before its assigned a value", variables->variables.variables_val[a]->names.names.names_val[0].name);
	}

      if (variables->variables.variables_val[a]->usage == 0 && variables->variables.variables_val[a]->assigned == 0)
	{
	  A4GL_lint (module_name, variables->variables.variables_val[a]->lineno, "VARNOTUSED", "Local variable is defined but not used", variables->variables.variables_val[a]->names.names.names_val[0].name);
	}

      if (variables->variables.variables_val[a]->usage == 0 && variables->variables.variables_val[a]->assigned)
	{
	  if (isParameter (variables->variables.variables_val[a], parameters))
	    {
	      A4GL_lint (module_name, variables->variables.variables_val[a]->lineno, "PARAMNOTUSED", "Function/Report parameter not used", variables->variables.variables_val[a]->names.names.names_val[0].name);
	    }
	  else
	    {
	      A4GL_lint (module_name, variables->variables.variables_val[a]->lineno, "VARASSNOTUSED", "Local variable is assigned a value but not used", variables->variables.variables_val[a]->names.names.names_val[0].name);
	    }
	}
    }
}


static void
check_linearised_commands (char *module_name, commands * func_cmds)
{
  int cnt;
  int nreturns = 0;
  int nretvals = 0;

  struct command *r;
  int local_last_whencode[10] = { -1, -1, -1, -1, -1, -1, -1 };
  char *local_last_whento[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  for (cnt = 0; cnt < 10; cnt++)
    {
      local_last_whencode[cnt] = -1;
      local_last_whento[cnt] = 0;
    }

  for (cnt = 0; cnt < func_cmds->cmds.cmds_len; cnt++)
    {
      r = func_cmds->cmds.cmds_val[cnt];

      if (r->cmd_data.type == E_CMD_LINT_EXPECT_CMD)
	{
	  set_lint_expect (r);
	  continue;
	}
      if (r->cmd_data.type == E_CMD_LINT_IGNORE_CMD)
	{
	  set_lint_ignore (r);
	  continue;
	}

      yylineno = r->lineno;
      if (r->cmd_data.type == E_CMD_RETURN_CMD)
	{

	  if (nreturns)
	    {
	      int nvals;
	      yylineno = r->lineno;



	      if (r->cmd_data.command_data_u.return_cmd.retvals)
		{
		  nvals = r->cmd_data.command_data_u.return_cmd.retvals->list.list_len;
		}
	      else
		{
		  nvals = 0;
		}

	      if (nvals != nretvals)
		{
		  char buff[200];
		  sprintf (buff, "%d!=%d", nvals, nretvals);
		  A4GL_lint (module_name, r->lineno, "MRETNUM", "RETURN with different number of values", buff);
		}
	      else
		{
		  A4GL_lint (module_name, r->lineno, "CS.MRET", "Coding Standards: Multiple RETURNs in function", 0);
		}

	    }
	  else
	    {
	      if (r->cmd_data.command_data_u.return_cmd.retvals)
		{
		  nretvals = r->cmd_data.command_data_u.return_cmd.retvals->list.list_len;
		}
	      else
		{
		  nretvals = 0;
		}
	      nreturns++;
	    }

	  if (r->cmd_data.command_data_u.return_cmd.retvals)
	    {
	      int a;
	      struct expr_str_list list;
	      list.list.list_len = 0;
	      list.list.list_val = 0;

	      cache_expression_list (&list, r->cmd_data.command_data_u.return_cmd.retvals);
	      linearise_expressions (&list);
	      for (a = 0; a < list.list.list_len; a++)
		{
		  if (list.list.list_val[a]->expr_type == ET_EXPR_FCALL)
		    {
		      A4GL_lint (module_name, r->lineno, "CS.FRET", "Coding Standards: Function RETURNs  with a the result from another function call", 0);
		      break;	// no point repeating the test..
		    }
		}
	    }

	}



      if (r->cmd_data.type == E_CMD_WHENEVER_CMD)
	{
	  int p_whencode;
	  char *p_whento;
	  int type;
	  p_whencode = r->cmd_data.command_data_u.whenever_cmd.whencode;
	  p_whento = r->cmd_data.command_data_u.whenever_cmd.whento;
	  type = p_whencode >> 4;

	  if (local_last_whencode[type] == p_whencode)
	    {
	      if (local_last_whento[type] == 0 && p_whento == 0)
		{
		  A4GL_lint (module_name, r->lineno, "CS.WHENRESET", "Resetting WHENEVER ... to same settings", 0);
		}

	      if (local_last_whento[type] != 0 && p_whento != 0)
		{
		  if (A4GL_aubit_strcasecmp (local_last_whento[type], p_whento) == 0)
		    {
		      A4GL_lint (module_name, r->lineno, "CS.WHENRESET", "Resetting WHENEVER ... to same settings", 0);
		    }
		}
	    }

	}


      if (r->cmd_data.type == E_CMD_INSERT_CMD)
	{

	  if (r->cmd_data.command_data_u.insert_cmd.column_list == NULL)
	    {
	      A4GL_lint (module_name, r->lineno, "INSERTNOCOLS", "Insert with no column list used", 0);
	    }
	  else
	    {
	      int ok = 0;
	      if (r->cmd_data.command_data_u.insert_cmd.column_list->str_list_entry.str_list_entry_len == 1)
		{
		  if (strcmp (r->cmd_data.command_data_u.insert_cmd.column_list->str_list_entry.str_list_entry_val[0], "*") == 0)
		    ok = 1;
		}


	      if (ok == 0
		  && r->cmd_data.command_data_u.insert_cmd.column_list->str_list_entry.str_list_entry_len !=
		  r->cmd_data.command_data_u.insert_cmd.value_list->list.list_len)
		{
		  char buff[200];
		  sprintf (buff, "%d!=%d", r->cmd_data.command_data_u.insert_cmd.column_list->str_list_entry.str_list_entry_len,
			   r->cmd_data.command_data_u.insert_cmd.value_list->list.list_len);
		  A4GL_lint (module_name, r->lineno, "INSERTCOLS", "Number of columns in INSERT does not match number of values", buff);
		}
	    }
	}

      if (r->cmd_data.type == E_CMD_SELECT_CMD)
	{
	  struct s_select *s;
	  int ncols;
	  int nvars;
	  int a;
	  s = r->cmd_data.command_data_u.select_cmd.sql;
	  A4GL_setenv ("EXPAND_COLUMNS", "Y", 1);

	  // Lets look before we preprocess
	  // 
	  if (s->select_list)
	    {
	      for (a = 0; a < s->select_list->list.list_len; a++)
		{
		  if (s->select_list->list.list_val[a]->data.type == E_SLI_BUILTIN_CONST_STAR)
		    {
		      A4GL_lint (module_name, r->lineno, "SELECTSTAR", "SELECT * used", 0);
		      break;
		    }
		}
	    }

	  preprocess_sql_statement (s);
	  if (s->into)
	    {
	      nvars = s->into->list.list_len;
	    }
	  else
	    {
	      nvars = 0;
	    }

	  ncols = s->select_list->list.list_len;

	  if (nvars != ncols)
	    {
	      int warn = 1;
	      // Check for SELECT ... INTO TEMP
	      if (nvars == 0)
		{
		  if (s->sf)
		    {
		      if (s->sf->into_temp && strlen (s->sf->into_temp))
			{
			  warn = 0;
			}
		      if (s->sf->insert_into && strlen (s->sf->insert_into))
			{
			  warn = 0;
			}
		    }
		  if (ncols == 1)
		    {
		      if (s->select_list->list.list_val[0]->data.type == E_SLI_LITERAL)
			{
			  // We can ignore it - its a SELECT 1 ..
			  // they are probably going to check the status...
			  warn = 0;
			}
		    }
		}

	      if (warn)
		{
		  if (nvars == 0)
		    {
		      A4GL_lint (module_name, r->lineno, "SELECTNOTINTO", "SELECT WITH NO INTO", 0);
		    }
		  else
		    {
		      A4GL_lint (module_name, r->lineno, "MISMATCHSELECT", "number of values selected is not the same as the number of variables", 0);
		    }
		}


	    }
	}


      if (r->cmd_data.type == E_CMD_LABEL_CMD)
	{
	  struct command *r2;
	  int isused = 0;
	  int b;

	  for (b = 0; b < func_cmds->cmds.cmds_len; b++)
	    {
	      r2 = func_cmds->cmds.cmds_val[b];
	      if (r2->cmd_data.type == E_CMD_GOTO_CMD)
		{
		  if (A4GL_aubit_strcasecmp (r2->cmd_data.command_data_u.goto_cmd.label, r->cmd_data.command_data_u.label_cmd.label)
		      == 0)
		    {
		      isused++;
		    }
		}
	    }
	  if (!isused)
	    {
	      A4GL_lint (module_name, r->lineno, "LABELNOTUSED", "Label defined but not used", r->cmd_data.command_data_u.label_cmd.label);
	    }
	}


      if (r->cmd_data.type == E_CMD_DISPLAY_ARRAY_CMD || r->cmd_data.type == E_CMD_INPUT_ARRAY_CMD)
	{
	  int isWithoutDefaults=-1;
	  int bcnt;
	  struct command *r2;
	  int found_setcount = 0;
	  //int c=0;

	  if (r->cmd_data.type == E_CMD_INPUT_ARRAY_CMD) {
			if (r->cmd_data.command_data_u.input_array_cmd.without_defaults==EB_TRUE) {
				isWithoutDefaults=1;
			} else {
				isWithoutDefaults=0;
			}
	  }

	  for (bcnt = cnt; bcnt >= 0; bcnt--)
	    {
	      r2 = func_cmds->cmds.cmds_val[bcnt];
	      if (r2->cmd_data.type == E_CMD_CALL_CMD)
		{
		  struct expr_str *ptr;
		  ptr = r2->cmd_data.command_data_u.call_cmd.fcall;
		  if (ptr->expr_type == ET_EXPR_FCALL)
		    {
		      if (strcmp (ptr->expr_str_u.expr_function_call->fname, "set_count") == 0)
			{
			  found_setcount = 1;
			  break;
			}
		    }
		}
	    }

//printf("isWithoutDefaults=%d\n", isWithoutDefaults);
	  if (!found_setcount && (isWithoutDefaults==1 || isWithoutDefaults==-1)) /* Its not without defaults */
	    {
	      A4GL_lint (module_name, r->lineno, "NSETCOUNT", "Cannot see a 'setcount' immediately before an Input/Display array", NULL);
	    }
	}

      if (r->cmd_data.type == E_CMD_WHILE_CMD)
	{
	  if (r->cmd_data.command_data_u.while_cmd.while_expr)
	    {
	      ensure_bool (r->module, r->lineno, r->cmd_data.command_data_u.while_cmd.while_expr, 0);
	    }
	}

      if (r->cmd_data.type == E_CMD_IF_CMD)
	{
	  int b;
	  struct if_conds *if_c;
	  if_c = &r->cmd_data.command_data_u.if_cmd.truths;



	  for (b = 0; b < if_c->conditions.conditions_len; b++)
	    {
	      //expr_str *e;
	      struct command *r2;
	      int last_was_sql = 0;
	      int done = 0;
	      ensure_bool (r->module, if_c->conditions.conditions_val[b].lineno, if_c->conditions.conditions_val[b].test_expr, 0);



	      if (A4GL_is_just_int_literal (if_c->conditions.conditions_val[b].test_expr, 0))
		{
		  yylineno = r->lineno;
		  A4GL_lint (module_name, r->lineno, "IFFALSE", "IF condition is always FALSE", 0);
		  done++;
		}

	      if (A4GL_is_just_int_literal (if_c->conditions.conditions_val[b].test_expr, 1))
		{
		  yylineno = r->lineno;
		  A4GL_lint (module_name, r->lineno, "IFTRUE", "IF condition is always TRUE", 0);
		  //A4GL_lint("IF condition is always TRUE");
		  done++;
		}


	      if (cnt)
		{
		  r2 = func_cmds->cmds.cmds_val[cnt - 1];
		  switch (r2->cmd_data.type)
		    {
		    case E_CMD_SELECT_CMD:
		    case E_CMD_SQL_CMD:
		    case E_CMD_SQL_TRANSACT_CMD:
		    case E_CMD_FETCH_CMD:
		    case E_CMD_INSERT_CMD:
		    case E_CMD_DELETE_CMD:
		    case E_CMD_UPDATE_CMD:
		    case E_CMD_FREE_CMD:
		    case E_CMD_EXECUTE_CMD:
		    case E_CMD_PREPARE_CMD:
		    case E_CMD_DECLARE_CMD:
		    case E_CMD_FOREACH_CMD:
		    case E_CMD_UNLOAD_CMD:
		    case E_CMD_LOAD_CMD:
		    case E_CMD_OPEN_CURSOR_CMD:
		    case E_CMD_PUT_CMD:
		    case E_CMD_EXECUTE_IMMEDIATE_CMD:
		      last_was_sql = 1;
		      break;
		    default:
		      break;
		    }
		}
	      // Further checks - like STATUS and SQLCA usage...
	      check_boolean (module_name, r->lineno, if_c->conditions.conditions_val[b].test_expr, last_was_sql, done);
	    }
	}


      if (r->cmd_data.type == E_CMD_GOTO_CMD)
	{
	  A4GL_lint (module_name, r->lineno, "CS.GOTO", "Use of GOTO is not recommended", 0);
	}


      if (r->cmd_data.type == E_CMD_FOR_CMD)
	{
	  int dtype;
	  struct expr_str s2;
	  struct expr_str *s3;
	  struct expr_str_list list;
	  int a;

	  list.list.list_len = 0;
	  list.list.list_val = 0;
	  dtype = expr_datatype (module_name, r->lineno, r->cmd_data.command_data_u.for_cmd.var);
	  if (!is_numeric (dtype))
	    {
	      A4GL_lint (module_name, r->lineno, "FORVARNUM", "Variable used in FOR is not numeric", 0);
	    }


	  // Lets check our 'ending' expression....
	  s3 = &s2;
	  memcpy (&s2, r->cmd_data.command_data_u.for_cmd.end, sizeof (struct expr_str));
	  cache_expression (&list, &s3);
	  linearise_expressions (&list);
	  for (a = 0; a < list.list.list_len; a++)
	    {
	      if (list.list.list_val[a])
		{
		  if (list.list.list_val[a]->expr_type == ET_EXPR_FCALL)
		    {
		      // Function call in the 'end' expression will be called multiple times
		      A4GL_lint (module_name, r->lineno, "FORENDEXPR", "Conditional for FOR calls a function (and so might be called many times)", 0);
		    }
		}
	    }



	  //set_assigned_binding_var(r->cmd_data.command_data_u.for_cmd.var,currfunc, r->module,r->lineno);
	}

      if (r->cmd_data.type == E_CMD_RUN_CMD)
	{
	  //set_assigned_binding(r->cmd_data.command_data_u.run_cmd.returning,currfunc, r->module,r->lineno);
	}

      if (r->cmd_data.type == E_CMD_INIT_CMD)
	{
	  //set_assigned_binding(r->cmd_data.command_data_u.init_cmd.expanded_varlist,currfunc, r->module,r->lineno);
	}
      if (r->cmd_data.type == E_CMD_DECLARE_CMD)
	{
	  //set_assigned_binding(r->cmd_data.command_data_u.declare_cmd.into_bind,currfunc, r->module,r->lineno);
	}
      if (r->cmd_data.type == E_CMD_SELECT_CMD)
	{
	  //set_assigned_binding(r->cmd_data.command_data_u.select_cmd.outbind,currfunc, r->module,r->lineno);
	}
      if (r->cmd_data.type == E_CMD_LET_CMD)
	{
	  //set_assigned_binding(r->cmd_data.command_data_u.let_cmd.vars,currfunc, r->module,r->lineno);
	}

      if (r->cmd_data.type == E_CMD_EXECUTE_CMD)
	{
	  //set_assigned_binding(r->cmd_data.command_data_u.execute_cmd.outbind,currfunc, r->module,r->lineno);
	}

      if (r->cmd_data.type == E_CMD_SQL_BLOCK_CMD)
	{
	  //set_assigned_binding(r->cmd_data.command_data_u.sql_block_cmd.outbind,currfunc, r->module,r->lineno);
	}
      if (r->cmd_data.type == E_CMD_CALL_CMD)
	{			// E_CMD_CALL_CMD is referenced a little later too - 
	  // just in case this ever makes it to a 'switch' statement!
	  //set_assigned_binding(r->cmd_data.command_data_u.call_cmd.returning,currfunc, r->module,r->lineno);
	}
      if (r->cmd_data.type == E_CMD_PDF_CALL_CMD)
	{
	  //set_assigned_binding(r->cmd_data.command_data_u.pdf_call_cmd.returning,currfunc, r->module,r->lineno);
	}
      if (r->cmd_data.type == E_CMD_FETCH_CMD)
	{
	  //set_assigned_binding(r->cmd_data.command_data_u.fetch_cmd.outbind,currfunc, r->module,r->lineno);
	}
      if (r->cmd_data.type == E_CMD_RUN_CMD)
	{
	  //set_assigned_binding(r->cmd_data.command_data_u.run_cmd.returning,currfunc, r->module,r->lineno);
	}

      if (r->cmd_data.type == E_CMD_CASE_CMD)
	{
	      int b;
	      for (b = 0; b < r->cmd_data.command_data_u.case_cmd.whens->whens.whens_len; b++)
		{
		char *s;
		char *s2;
		int next;
		int found;
		  expr_str *expr;
		  //int is_string;
		  	expr = r->cmd_data.command_data_u.case_cmd.whens->whens.whens_val[b]->when_expr;

			s=strdup(expr_as_string_when_possible(expr));
			for (next=b+1;next<r->cmd_data.command_data_u.case_cmd.whens->whens.whens_len;next++) {
				s2=strdup(expr_as_string_when_possible(r->cmd_data.command_data_u.case_cmd.whens->whens.whens_val[next]->when_expr));
				if (strcmp(s,s2)==0) {
					char buff[200];
	//printf("s=%s s2=%s\n",s,s2);
						sprintf(buff,"seen again line %d", r->cmd_data.command_data_u.case_cmd.whens->whens.whens_val[next]->lineno);
		      				A4GL_lint (module_name, r->cmd_data.command_data_u.case_cmd.whens->whens.whens_val[b]->lineno, "WHENDUP", "DUPLICATE WHEN", buff);
						break;
				}
				free(s2);
			}
			free(s);
		}

	  if (r->cmd_data.command_data_u.case_cmd.case_expr == 0)
	    {
	      for (b = 0; b < r->cmd_data.command_data_u.case_cmd.whens->whens.whens_len; b++)
		{
		char *s;
		char *s2;
		int next;
		  expr_str *expr;
		  //int is_string;
		  	expr = r->cmd_data.command_data_u.case_cmd.whens->whens.whens_val[b]->when_expr;


		  yylineno = r->lineno;
		  if (expr_datatype (module_name, r->cmd_data.command_data_u.case_cmd.whens->whens.whens_val[b]->lineno, expr) ==
		      DTYPE_CHAR
		      || expr_datatype (module_name, r->cmd_data.command_data_u.case_cmd.whens->whens.whens_val[b]->lineno,
					expr) == DTYPE_VCHAR)
		    {
		      A4GL_lint (module_name, r->cmd_data.command_data_u.case_cmd.whens->whens.whens_val[b]->lineno, "CASESTR", "Use of String for WHEN in a CASE with no expression", 0);
		    }

		  if (A4GL_is_just_int_literal (expr, 0))
		    {
		      yylineno = r->lineno;
		      A4GL_lint (module_name, r->cmd_data.command_data_u.case_cmd.whens->whens.whens_val[b]->lineno, "CASEFALSE", "WHEN condition is always FALSE", 0);
		      continue;
		    }
		  if (A4GL_is_just_int_literal (expr, 1))
		    {
		      yylineno = r->lineno;
		      A4GL_lint (module_name, r->cmd_data.command_data_u.case_cmd.whens->whens.whens_val[b]->lineno, "CASETRUE", "WHEN condition is always TRUE", 0);
		      continue;
		    }

		  if (A4GL_is_just_literal (NULL, expr, 1))
		    {
		      yylineno = r->lineno;
		      A4GL_lint (module_name, r->cmd_data.command_data_u.case_cmd.whens->whens.whens_val[b]->lineno, "CASECONST", "WHEN condition is constant", 0);
		    }

		
		}
	    }

	  if (!r->cmd_data.command_data_u.case_cmd.otherwise)
	    {
	      yylineno = r->lineno;
	      A4GL_lint (module_name, r->lineno, "CS.NOOTHERWISE", "CASE has no OTHERWISE", 0);
	    }
	}
      if (r->cmd_data.type == E_CMD_CALL_CMD)
	{
	  int cnt1;
	  int cnt2;

	  struct expr_str *fcall;
	  char *funcname;
	  int b = -1;
	  fcall = r->cmd_data.command_data_u.call_cmd.fcall;
	  funcname = fcall->expr_str_u.expr_function_call->fname;

	  if (fcall->expr_type == ET_EXPR_FCALL)
	    {
	      b = find_function (fcall->expr_str_u.expr_function_call->fname);
	    }

	  if (b == -1)
	    {

	      if (fcall->expr_type == ET_EXPR_FCALL)
		{
		  if (!system_function (fcall->expr_str_u.expr_function_call->fname)
		      && is_bolton_function (fcall->expr_str_u.expr_function_call->fname) == -1)
		    {
		      char buff[200];
		      sprintf (buff, "Function %s was called but is not defined", fcall->expr_str_u.expr_function_call->fname);
		      //A4GL_lint (module_name, r->lineno, "FUNCNOTDEF", "Function was called but is not defined", fcall->expr_str_u.expr_function_call->fname);
		      log_proto (fcall, r->cmd_data.command_data_u.call_cmd.returning);
		    }
		}
	    }
	  else
	    {
	      // We know the function
	      if (is_bolton_function (funcname) != -1)
		{
		  int a;
		  a = is_bolton_function (funcname);

		  if (fboltons[a].nreturns > 0 && r->cmd_data.command_data_u.call_cmd.returning == 0)
		    {
		      A4GL_lint (module_name, r->lineno, "FUNCRETCNT", "Function returns too many values ", funcname);
		      continue;
		    }

		  if (fboltons[a].nreturns > r->cmd_data.command_data_u.call_cmd.returning->list.list_len)
		    {
		      A4GL_lint (module_name, r->lineno, "FUNCRETCNT", "Function returns too few values ", funcname);
		      continue;
		    }
		  if (fboltons[a].nreturns < r->cmd_data.command_data_u.call_cmd.returning->list.list_len)
		    {
		      A4GL_lint (module_name, r->lineno, "FUNCRETCNT", "Function returns too many values ", funcname);
		      continue;
		    }
		}
	      else
		{
		  cnt1 = fprototypes[b].nreturns;
		  if (r->cmd_data.command_data_u.call_cmd.returning)
		    {
		      cnt2 = r->cmd_data.command_data_u.call_cmd.returning->list.list_len;
		    }
		  else
		    {
		      cnt2 = 0;
		    }

		  if (cnt1 < cnt2)
		    {
		      A4GL_lint (module_name, r->lineno, "FUNCRETCNT", "Function returns too few values", funcname);
		      continue;
		    }
		  if (cnt1 > cnt2)
		    {
		      A4GL_lint (module_name, r->lineno, "FUNCRETCNT", "Function returns too many values", funcname);
		      continue;
		    }
		}

	      // If we've got to here - we've got the right number of return variables...
	      if (r->cmd_data.command_data_u.call_cmd.returning == 0)
		{		// 
		  // Nothing else to check...
		  continue;
		}
	      if (r->cmd_data.command_data_u.call_cmd.returning->list.list_len == 0)
		{		// 
		  // Nothing else to check...
		  continue;
		}

	      if (is_bolton_function (funcname) != -1)
		{
		  // Its a bolton
		  //int a;

		}
	      else
		{
		  // Its not a bolton
		  int a;
		  int etype;
		  struct expr_str_list *varlist;
		  varlist = r->cmd_data.command_data_u.call_cmd.returning;
		  if (varlist->list.list_len > 100)
		    {
		      A4GL_lint (r->module, r->lineno, "CALLRETNUM", "CALL returns a lot of values", "");
		    }
		  for (a = 0; a < varlist->list.list_len; a++)
		    {
		      int vlist_dtype;


		      etype = fprototypes[b].return_dtypes[a] & DTYPE_MASK;
		      vlist_dtype = expr_datatype (r->module, r->lineno, varlist->list.list_val[a]);
		      if (promoteable (etype, vlist_dtype) == -1)
			{


			  char buff[200];
			  // Mismatch in return types..
			  sprintf (buff, "%s - types expression (%s) != variable (%s) @ %d",
				   lint_get_variable_usage_as_string (varlist->list.list_val[a]->expr_str_u.expr_variable_usage),
				   dtype_as_string (etype), dtype_as_string (vlist_dtype), a + 1);
			  A4GL_lint (r->module, r->lineno, "CALLRETEXPR", "Expression is not directly compatible with Variable", buff);
			}
		    }
		}
	    }

	  //break;
	}



      if (r->cmd_data.type == E_CMD_LET_CMD)
	{
	  expr_str_list *expr_list = 0;
	  expr_str_list *varlist;
	  int from_exprs;
	  int b;

	  expr_list = r->cmd_data.command_data_u.let_cmd.vals;
	  if (expr_list == 0)
	    {
	      // LET ? = NULL
	      continue;
	    }
	  expr_list = A4GL_rationalize_list (expr_list);
	  from_exprs = A4GL_new_list_get_count (expr_list);


	  varlist = r->cmd_data.command_data_u.let_cmd.vars;

	  if (from_exprs != varlist->list.list_len && varlist->list.list_len != 1)
	    {
	      yylineno = r->lineno;
	      A4GL_lint (module_name, r->lineno, "LETCOUNT", "Mismatch in number of parameters", 0);
	    }


	  for (b = 0; b < varlist->list.list_len; b++)
	    {
	      if (strncmp (expr_as_string_when_possible (varlist->list.list_val[b]), "a4gl_sqlca", 10) == 0)
		{
		  yylineno = r->lineno;
		  A4GL_lint (module_name, r->lineno, "CS.WRITESQLCA", "Direct assignment to SQLCA record entry", 0);
		}

	      if (A4GL_aubit_strcasecmp (expr_as_string_when_possible (varlist->list.list_val[b]), "int_flag") == 0)
		{
		  if (A4GL_is_just_int_literal (expr_list->list.list_val[b], 0)
		      || A4GL_is_just_int_literal (expr_list->list.list_val[b], 1));
		  else
		    {
		      yylineno = r->lineno;
		      A4GL_lint (module_name, r->lineno, "CS.WRITEINTFLAG", "'int_flag' set to value which is neither TRUE or FALSE", 0);
		    }
		}

	      if (A4GL_aubit_strcasecmp (expr_as_string_when_possible (varlist->list.list_val[b]), "quit_flag") == 0)
		{
		  if (A4GL_is_just_int_literal (expr_list->list.list_val[b], 0)
		      || A4GL_is_just_int_literal (expr_list->list.list_val[b], 1));
		  else
		    {
		      yylineno = r->lineno;
		      A4GL_lint (module_name, r->lineno, "CS.WRITEQUITFLAG", "'quit_flag' set to value which is neither TRUE or FALSE", 0);
		    }
		}


	      if (A4GL_aubit_strcasecmp (expr_as_string_when_possible (varlist->list.list_val[b]), "quit_flag") == 0)
		{
		  if (A4GL_is_just_int_literal (expr_list->list.list_val[b], 0)
		      || A4GL_is_just_int_literal (expr_list->list.list_val[b], 1));
		  else
		    {
		      yylineno = r->lineno;
		      A4GL_lint (module_name, r->lineno, "CS.WRITEQUITFLAG", "'quit_flag' set to value which is neither TRUE or FALSE", 0);
		    }
		}


	    }

	  if (varlist->list.list_len && varlist->list.list_len == 1)
	    {			// single variable
	      char buff[256];
	      //int e;

	      if (from_exprs > 1)
		{		// This should be a string concat
		  if (!is_char_dtype (expr_datatype (module_name, r->lineno, varlist->list.list_val[0])))
		    {
		      A4GL_lint (module_name, r->lineno, "CONCATTONONSTR", "Assigning a string concentenation to a non-character variable",
				 expr_as_string_when_possible (varlist->list.list_val[0]));
		    }
		  else
		    {
		      // Its a character string...
		      int ecnt;
		      int lmax;	// Whats the maximum size of the expression being passed in..
		      int var_length;
		      lmax = 0;
		      var_length = expr_datatype (module_name, r->lineno, varlist->list.list_val[0]) >> 16;

		      // It is a string - so all our expressions should really be strings
		      // we know we can convert between integers and strings - but this is a lint
		      // checker - maybe they should consider using a USING ? 
		      for (ecnt = 0; ecnt < from_exprs; ecnt++)
			{
			  int etype;
			  int l;
			  yylineno = r->lineno;
			  etype = expr_datatype (module_name, r->lineno, expr_list->list.list_val[ecnt]);
			  if (lmax >= 0)
			    {
			      l = expr_char_length (module_name, r->lineno, expr_list->list.list_val[ecnt]);
			      // If this is -1 then we cant work out what the length is - so
			      // we can ignore any further checks on the size...
			      if (l < 0)
				{
				  lmax = -1;
				}

			      if (l >= 0)
				{
				  lmax += l;
				}
			    }

			  if (!is_char_dtype (etype))
			    {
			      sprintf (buff, "%d expression", ecnt + 1);
			      A4GL_lint (module_name, r->lineno, "CONCATFROMNONSTR", "Expression in string concatenation assignment, is not a string", buff);
			    }
			}
		      if (lmax > 0 && lmax > var_length)
			{
			  A4GL_lint (module_name, r->lineno, "STRINGLONG", "Expression assigned to string may not fit into destination", NULL);
			}
		    }
		}
	      else
		{
		  //  single value going into a single variable...
		  int etype;
		  if (expr_list->list.list_val[0]->expr_type == ET_EXPR_NULL)
		    {
		      etype = expr_datatype (module_name, r->lineno, varlist->list.list_val[0]);
		    }
		  else
		    {
		      yylineno = r->lineno;
		      etype = expr_datatype (module_name, r->lineno, expr_list->list.list_val[0]);
		    }

		  if (is_char_dtype (etype) && is_char_dtype (expr_datatype (module_name, r->lineno, varlist->list.list_val[0])))
		    {		// String to a string..
		      int lmax;
		      int var_length;
		      lmax = expr_char_length (module_name, r->lineno, expr_list->list.list_val[0]);
		      var_length = expr_datatype (module_name, r->lineno, varlist->list.list_val[0]) >> 16;
		      if (lmax > 0)
			{
			  if (lmax > var_length)
			    {
			      A4GL_lint (module_name, r->lineno, "STRINGLONG", "Expression assigned to string may not fit into destination", NULL);
			    }
			}
		    }
		  if (promoteable (etype, expr_datatype (module_name, r->lineno, varlist->list.list_val[0])) == -1)
		    {
		      char buff[256];
		      sprintf (buff, "%s - types expression (%s) != variable (%s)",
			       expr_as_string_when_possible (varlist->list.list_val[0]), dtype_as_string (etype),
			       dtype_as_string (expr_datatype (module_name, r->lineno, varlist->list.list_val[0])));
		      A4GL_lint (r->module, r->lineno, "LETEXPR", "Expression is not directly compatible with Variable", buff);
		    }
		}

	    }
	  else
	    {
	      //char buff[256];
	      // More than one expression - more than one variable..
	      if (varlist->list.list_len && varlist->list.list_len == from_exprs)
		{
		  int ecnt;
		  for (ecnt = 0; ecnt < from_exprs; ecnt++)
		    {
		      int etype;
		      if (expr_list->list.list_val[ecnt]->expr_type == ET_EXPR_NULL)
			{
			  etype = expr_datatype (module_name, r->lineno, varlist->list.list_val[ecnt]);
			}
		      else
			{
			  yylineno = r->lineno;
			  etype = expr_datatype (module_name, r->lineno, expr_list->list.list_val[ecnt]);
			}
		      if (promoteable (etype, expr_datatype (module_name, r->lineno, varlist->list.list_val[ecnt])) == -1)
			{
			  char buff[256];
			  sprintf (buff, "Assignement to '%s', record element %d (%s %s)",
				   expr_as_string_when_possible (varlist->list.list_val[ecnt]), ecnt + 1, dtype_as_string (etype),
				   dtype_as_string (expr_datatype (module_name, r->lineno, varlist->list.list_val[ecnt])));
			  A4GL_lint (module_name, r->lineno, "LETEXPR", "Expression is not directly compatible with Variable", buff);

			}

		    }
		}
	    }
	}
      clr_lint_expect ();
    }
}



static void
check_report (struct module_definition *d, struct s_report_definition *r)
{
  int a;
  char *module_name;
  module_name = r->module;
  check_variables (r->module, d, &r->variables, r->parameters);

  if (r->report_format_section)
    {
      for (a = 0; a < r->report_format_section->entries.entries_len; a++)
	{
	  if (r->report_format_section->entries.entries_val[a]->rep_sec_commands != NULL)
	    {
	      struct commands *func_cmds = 0;
	      check_cmds_for_dead_code (r->report_format_section->entries.entries_val[a]->rep_sec_commands);

	      func_cmds = linearise_commands (0, 0);
	      linearise_commands (func_cmds, r->report_format_section->entries.entries_val[a]->rep_sec_commands);
	      check_linearised_commands (r->module, func_cmds);
	      cache_expressions (&r->expression_list, func_cmds);
	      set_expr_cache (&r->expression_list);
	      set_expr_cache (0);


	    }
	}
    }

  if (r->report_orderby_section)
    {

      if (r->report_orderby_section->rord_type == REPORT_ORDERBY)
	{
	  A4GL_lint (module_name, r->lineno, "REPORD", "ORDER BY on report (use ORDER EXTERNAL BY if possible)", NULL);
	}

    }
}

static void
check_pdf_report (struct module_definition *d, struct s_pdf_report_definition *r)
{
  int a;
  char *module_name;
  module_name = r->module;
  check_variables (r->module, d, &r->variables, r->parameters);

  if (r->report_format_section)
    {
      for (a = 0; a < r->report_format_section->entries.entries_len; a++)
	{
	  if (r->report_format_section->entries.entries_val[a]->rep_sec_commands != NULL)
	    {
	      struct commands *func_cmds = 0;
	      check_cmds_for_dead_code (r->report_format_section->entries.entries_val[a]->rep_sec_commands);

	      func_cmds = linearise_commands (0, 0);
	      linearise_commands (func_cmds, r->report_format_section->entries.entries_val[a]->rep_sec_commands);
	      check_linearised_commands (r->module, func_cmds);
	      cache_expressions (&r->expression_list, func_cmds);
	      set_expr_cache (&r->expression_list);
	      set_expr_cache (0);


	    }
	}
    }

  if (r->report_orderby_section)
    {
      if (r->report_orderby_section->rord_type == REPORT_ORDERBY)
	{
	  A4GL_lint (module_name, r->lineno, "REPORD", "ORDER BY on report (use ORDER EXTERNAL BY if possible)", NULL);
	}

    }
}


static void
check_function (struct module_definition *d, struct s_function_definition *f)
{
  struct commands *func_cmds = 0;
  //int a;
  //int b;
  char *currfunc;

  check_cmds_for_dead_code (f->func_commands);

  currfunc = f->funcname;



  check_variables (f->module, d, &f->variables, f->parameters);

  func_cmds = linearise_commands (0, 0);
  linearise_commands (func_cmds, f->func_commands);
  check_linearised_commands (f->module, func_cmds);
  cache_expressions (&f->expression_list, func_cmds);


  set_expr_cache (&f->expression_list);

  // first - check for multiple return paths..
  set_expr_cache (0);

}



static int
local_print_whenever_style (int code, char *whento, int *when_set_to_call)
{
int set=0;

  switch (code)
    {
    case 0x12:
	set=0;
      if (A4GL_aubit_strcasecmp (whento, "get_error_record") == 0)
	{
	  *when_set_to_call = 1;
	set++;
	}

      if (A4GL_aubit_strcasecmp (whento, "error_handler") == 0)
	{
	  *when_set_to_call = 2;
	set++;
	}


	if (!set)
	{
	  *when_set_to_call = 0;
	}

      return 0;

    case 0x11:
      *when_set_to_call = 0;
      return 0;

    case 0x10:
      *when_set_to_call = 0;
      return 0;

    case 0x20:
      return 0;
    case 0x21:
      return 0;
    case 0x22:
      return 0;
    }

  A4GL_assertion (1, "Unhandled whenever");

  return 0;


}




// This goes through all the functions in a module and checks that WHENEVER ERROR CALL get_error_record
// has been called before any SQL statements are used 
static void
check_whenever_abuse (module_definition * d)
{
  int a;
  //int b;
  int cmd;
  struct commands *all_cmds = 0;
  struct command *c;
  int when_set_to_call = 0;
  //struct report_format_section *report_format_section;
  char *curr_func = "";


  for (a = 0; a < d->module_entries.module_entries_len; a++)
    {
      //struct s_function_definition *f;
      all_cmds = 0;

      curr_func = "";

      switch (d->module_entries.module_entries_val[a]->met_type)
	{

	case E_MET_MAIN_DEFINITION:
	case E_MET_FUNCTION_DEFINITION:
	  all_cmds = linearise_commands (0, 0);
	  linearise_commands (all_cmds, d->module_entries.module_entries_val[a]->module_entry_u.function_definition.func_commands);
	  curr_func = d->module_entries.module_entries_val[a]->module_entry_u.function_definition.funcname;
	  break;

	case E_MET_REPORT_DEFINITION:
	  linearise_report (all_cmds,
			    d->module_entries.module_entries_val[a]->module_entry_u.report_definition.report_format_section);

	  break;

	case E_MET_PDF_REPORT_DEFINITION:
	  linearise_report (all_cmds,
			    d->module_entries.module_entries_val[a]->module_entry_u.pdf_report_definition.report_format_section);
	  break;
	case E_MET_FORMHANDLER_DEFINITION:
	  printf ("Not implemented yet (E_MET_FORMHANDLER_DEFINITION,2) \n");
	  exit (4);
	  break;

	case E_MET_CMD:
	  c = d->module_entries.module_entries_val[a]->module_entry_u.cmd;
	  if (c->cmd_data.type == E_CMD_WHENEVER_CMD)
	    {
	      local_print_whenever_style (c->cmd_data.command_data_u.whenever_cmd.whencode,
					  c->cmd_data.command_data_u.whenever_cmd.whento, &when_set_to_call);
	    }
	  break;

	  // We dont need to worry about these commands....
	case E_MET_IMPORT_FUNCTION_DEFINITION:
	case E_MET_IMPORT_LEGACY_DEFINITION:
	case E_MET_CLASS_DEFINITION:
	case E_MET_IMPORT_DATATYPE:
	case E_MET_IMPORT_PACKAGE:
	  break;

	}


      if (all_cmds)
	{
	  struct command *r;
	  for (cmd = 0; cmd < all_cmds->cmds.cmds_len; cmd++)
	    {
	      r = all_cmds->cmds.cmds_val[cmd];
	      if (r->cmd_data.type == E_CMD_LINT_EXPECT_CMD)
		{
		  set_lint_expect (r);
		  continue;
		}
	      if (r->cmd_data.type == E_CMD_LINT_IGNORE_CMD)
		{
		  set_lint_ignore (r);
		  continue;
		}

	      switch (r->cmd_data.type)
		{
		case E_CMD_EXIT_PROG_CMD:
		  if (A4GL_aubit_strcasecmp (curr_func, "exit_prog") != 0)
		    {
		      A4GL_lint (d->module_name, r->lineno, "CS.EXITDIRECT", "EXIT PROGRAM must not be used directly - use CALL exit_prog instead", 0);
		    }


		  if (A4GL_aubit_strcasecmp (curr_func, "main") != 0)
		    {
		      A4GL_lint (d->module_name, r->lineno, "CS.EXITNOTMAIN", "EXIT PROGRAM must only be in main", 0);
		    }
		  break;

		case E_CMD_WHENEVER_CMD:
		  local_print_whenever_style (r->cmd_data.command_data_u.whenever_cmd.whencode,
					      r->cmd_data.command_data_u.whenever_cmd.whento, &when_set_to_call);
		  break;


		  // Transactions should only be done in functions called 'begin_work', 'rollback_work', and 'commit_work'....
		case E_CMD_SQL_TRANSACT_CMD:
		  if (when_set_to_call!=1)
		    {
		      A4GL_lint (d->module_name, r->lineno, "CS.GETERRORRECORD", "Must use 'WHENEVER ERROR CALL get_error_record' before using SQL", 0);
			}
		  if (when_set_to_call!=2) {
		      A4GL_lint (d->module_name, r->lineno, "CS.ERRORHANDLER", "Must use 'WHENEVER ERROR CALL error_handler' before using SQL", 0);
		    }
		  break;


		  switch (r->cmd_data.command_data_u.sql_transact_cmd.trans)
		    {
		    case -1:
		      if (A4GL_aubit_strcasecmp (curr_func, "begin_work") != 0)
			{
			  A4GL_lint (d->module_name, r->lineno, "CS.DIRECTTRANS", "BEGIN WORK used directly", 0);
			}
		      break;
		    case 0:
		      if (A4GL_aubit_strcasecmp (curr_func, "rollback_work") != 0)
			{
			  A4GL_lint (d->module_name, r->lineno, "CS.DIRECTTRANS", "ROLLBACK WORK used directly", 0);
			}
		      break;
		    case 1:
		      if (A4GL_aubit_strcasecmp (curr_func, "commit_work") != 0)
			{
			  A4GL_lint (d->module_name, r->lineno, "CS.DIRECTTRANS", "COMMIT WORK used directly", 0);
			}
		      break;
		    }
		  break;




		case E_CMD_SELECT_CMD:
		case E_CMD_FETCH_CMD:
		case E_CMD_SQL_BLOCK_CMD:
		case E_CMD_SQL_CMD:
		case E_CMD_EXECUTE_CMD:
		case E_CMD_PREPARE_CMD:
		  if (when_set_to_call!=1)
		    {
		      A4GL_lint (d->module_name, r->lineno, "CS.GETERRORRECORD", "Must use 'WHENEVER ERROR CALL get_error_record' before using SQL", 0);
		    }
		  if (when_set_to_call!=2) {
		      A4GL_lint (d->module_name, r->lineno, "CS.ERRORHANDLER", "Must use 'WHENEVER ERROR CALL error_handler' before using SQL", 0);
		    }
		  break;

		default:
		  break;
		  // Don't care -they are not SQL commands...

		}
	      clr_lint_expect ();
	    }
	}


    }


}




void
lint_warnings (int n, struct lint_warning *v)
{
  int a;
  for (a = 0; a < n; a++)
    {
      A4GL_lint (0, v->lineno, "CTIME", v->warning, 0);
    }
}

static void
check_functions_in_module (int *calltree, module_definition * d)
{
  int a;
  struct module_entry *m;
//int b;




  for (a = 0; a < d->module_entries.module_entries_len; a++)
    {
      //struct s_function_definition *f;
      //printf ("a=%d of %d\n", a, d->module_entries.module_entries_len);
      switch (d->module_entries.module_entries_val[a]->met_type)
	{

	case E_MET_MAIN_DEFINITION:
	case E_MET_FUNCTION_DEFINITION:
	  m = this_module.module_entries.module_entries_val[a];
	  set_lint_module (m->module_entry_u.function_definition.module);
	  lint_warnings (d->module_entries.module_entries_val[a]->module_entry_u.function_definition.extra_warnings.
			 extra_warnings_len,
			 d->module_entries.module_entries_val[a]->module_entry_u.function_definition.extra_warnings.
			 extra_warnings_val);


	  if (calltree[a] != 0 || nomain)
	    {
	      printf ("Check : %s\n", d->module_entries.module_entries_val[a]->module_entry_u.function_definition.funcname);
	      fflush (stdout);
	      check_function (d, &d->module_entries.module_entries_val[a]->module_entry_u.function_definition);
	    }
	  break;

	case E_MET_REPORT_DEFINITION:


	  lint_warnings (d->module_entries.module_entries_val[a]->module_entry_u.report_definition.extra_warnings.
			 extra_warnings_len,
			 d->module_entries.module_entries_val[a]->module_entry_u.report_definition.extra_warnings.
			 extra_warnings_val);

	  if (calltree[a] != 0 || nomain)
	    {
	      printf ("Check : %s\n", d->module_entries.module_entries_val[a]->module_entry_u.function_definition.funcname);
	      fflush (stdout);
	      check_report (d, &d->module_entries.module_entries_val[a]->module_entry_u.report_definition);
	    }
	  break;

	case E_MET_PDF_REPORT_DEFINITION:
	  lint_warnings (d->module_entries.module_entries_val[a]->module_entry_u.pdf_report_definition.extra_warnings.
			 extra_warnings_len,
			 d->module_entries.module_entries_val[a]->module_entry_u.pdf_report_definition.extra_warnings.
			 extra_warnings_val);
	  if (calltree[a] != 0 || nomain)
	    {
	      check_pdf_report (d, &d->module_entries.module_entries_val[a]->module_entry_u.pdf_report_definition);
	    }
	  break;

	case E_MET_FORMHANDLER_DEFINITION:
	  printf ("Not implemented yet (E_MET_FORMHANDLER_DEFINITION.3)\n");
	  exit (4);
	  break;
	  // We dont need to worry about these commands....
	case E_MET_CMD:
	case E_MET_IMPORT_FUNCTION_DEFINITION:
	case E_MET_CLASS_DEFINITION:
	case E_MET_IMPORT_LEGACY_DEFINITION:
	case E_MET_IMPORT_DATATYPE:
	case E_MET_IMPORT_PACKAGE:
	  break;

	}
    }

  for (a = 0; a < ngass; a++)
    {
      if (gass[a].nfunction_list > 1)
	{
	  //char buff[2000];
	  int b;
	  for (b = 0; b < gass[a].nfunction_list; b++)
	    {
	      A4GL_lint (gass[a].function_list[b].module, gass[a].function_list[b].line, "ASSGLOBALS", "Global variable has been assigned in multiple functions", gass[a].varname);
	    }

	}
    }

  //A4GL_setenv("A4GL_PACKER","XML2",1);

//if (A4GL_isyes(acl_getenv("DUMPOUTPUT"))) {
  //write_module_definition(d, "test1.xml");
//}


}


static void
check_functions_in_module_for_complexity (module_definition * d)
{
  int a;
//struct module_entry *m;
//int b;
  for (a = 0; a < d->module_entries.module_entries_len; a++)
    {
      //struct s_function_definition *f;

      switch (d->module_entries.module_entries_val[a]->met_type)
	{

	case E_MET_MAIN_DEFINITION:
	case E_MET_FUNCTION_DEFINITION:
	  check_function_for_complexity (d, &d->module_entries.module_entries_val[a]->module_entry_u.function_definition);
	  break;

	  // We dont need to worry about these commands....
	case E_MET_REPORT_DEFINITION:
	case E_MET_PDF_REPORT_DEFINITION:
	case E_MET_CMD:
	case E_MET_IMPORT_FUNCTION_DEFINITION:
	case E_MET_CLASS_DEFINITION:
	case E_MET_IMPORT_LEGACY_DEFINITION:
	case E_MET_IMPORT_DATATYPE:
	case E_MET_IMPORT_PACKAGE:
	  break;

	case E_MET_FORMHANDLER_DEFINITION:
	  printf ("Not implemented yet (E_MET_FORMHANDLER_DEFINITION.4) \n");
	  exit (4);
	  break;

	}
    }

  //A4GL_setenv("A4GL_PACKER","XML2",1);

//if (A4GL_isyes(acl_getenv("DUMPOUTPUT"))) {
  //write_module_definition(d, "test1.xml");
//}


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
  if (A4GL_aubit_strcasecmp (s, "err_line_no") == 0)
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
local_is_valid_vname (struct variable *v, enum e_scope scope)
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
    case VARIABLE_TYPE_TYPE_DECLARATION:
      //case VARIABLE_TYPE_LINKED:
      return 1;


      //case VARIABLE_TYPE_ARRAY:
      //if (nm[1]!='a') return 0; else return 1;
    }

  return 1;
}

static char *
get_orig_from_clobber (struct module_definition *mod, char *s)
{
  int a;

  if (mod == NULL)
    return s;

  for (a = 0; a < mod->clobberings.clobberings_len; a++)
    {
      if (strcmp (mod->clobberings.clobberings_val[a].newval, s) == 0)
	{
	  return mod->clobberings.clobberings_val[a].important;
	}
    }
  return s;
}


char *
lint_get_ident_as_string (struct module_definition *mod, struct expr_str *ptr)
{

  static char buff[2000];
  if (ptr->expr_type == ET_EXPR_IDENTIFIER)
    {
      sprintf (buff, "\"%s\"", get_orig_from_clobber (mod, ptr->expr_str_u.expr_string));
      return strdup (buff);
    }

  if (ptr->expr_type == ET_EXPR_VARIABLE_IDENTIFIER)	// a _VARIABLE
    {
      return strdup (expr_as_string_when_possible (ptr->expr_str_u.expr_expr));
    }

  if (ptr->expr_type == ET_EXPR_VARIABLE_USAGE)
    {
      return strdup (lint_get_variable_usage_as_string (ptr->expr_str_u.expr_variable_usage));
    }


  A4GL_assertion (1, "lint_get_ident_as_string not implemented for this expression type yet");
  return 0;
}



void
check_variable_name (char *modname, char *scope, struct variable *v)
{
  int issystem;
//char buff[256];

  if (v->var_data.variable_type == VARIABLE_TYPE_SIMPLE
      || v->var_data.variable_type == VARIABLE_TYPE_RECORD
      || v->var_data.variable_type == VARIABLE_TYPE_OBJECT || v->var_data.variable_type == VARIABLE_TYPE_ASSOC);
  else
    return;

  issystem = local_is_system_variable (v->names.names.names_val[0].name);

  if (A4GL_aubit_strcasecmp (v->names.names.names_val[0].name, "int_flag") == 0)
    issystem = 1;
  if (A4GL_aubit_strcasecmp (v->names.names.names_val[0].name, "quit_flag") == 0)
    issystem = 1;
  if (A4GL_aubit_strcasecmp (v->names.names.names_val[0].name, "fgl_user") == 0)
    issystem = 1;
/*
  if (A4GL_aubit_strcasecmp (v->names.names.names_val[0].name, "lineno") == 0)
    issystem = 1;
  if (A4GL_aubit_strcasecmp (v->names.names.names_val[0].name, "pageno") == 0)
    issystem = 1;
*/


  if (issystem)
    return;

  if (A4GL_is_valid_4gl_type (v->names.names.names_val[0].name))
    {

      A4GL_lint (v->src_module, v->lineno, "VNAMEDTYPE", "Variable name is the same as a Datatype (got an extra ',' ?)", v->names.names.names_val[0].name);
    }

  if (A4GL_aubit_strcasecmp (scope, "ImportedGlobal") == 0)
    {
      // These should be picked up in the module in which they are exported...
      return;
    }


  if (A4GL_aubit_strcasecmp (scope, "Global") == 0)
    {
      if (v->names.names.names_val[0].name[0] != 'g')
	{

	  A4GL_lint (v->src_module, v->lineno, "CS.VNAME", "Global variable does not begin with 'g'", v->names.names.names_val[0].name);
	}

      if (!local_is_valid_vname (v, 'g'))
	{
	  A4GL_lint (v->src_module, v->lineno, "CS.VNAME", "Variable is not in the form sn_xxxx", v->names.names.names_val[0].name);
	}

      return;

    }

  if (A4GL_aubit_strcasecmp (scope, "Module") == 0)
    {
      // Module level variable
      if (v->names.names.names_val[0].name[0] != 'm')
	{
	  A4GL_lint (v->src_module, v->lineno, "CS.VNAME", "Module variable does not begin with 'm'", v->names.names.names_val[0].name);
	}
      if (!local_is_valid_vname (v, 'm'))
	{
	  A4GL_lint (v->src_module, v->lineno, "CS.VNAME", "Variable is not in the form sn_xxxx", v->names.names.names_val[0].name);
	}
      return;
    }

  if (A4GL_aubit_strcasecmp (scope, "Local") == 0)
    {
      // Module level variable
      if (v->names.names.names_val[0].name[0] != 'l')
	{
	  A4GL_lint (v->src_module, v->lineno, "CS.VNAME", "Local variable does not begin with 'l'", v->names.names.names_val[0].name);
	}
      if (!local_is_valid_vname (v, 'l'))
	{
	  A4GL_lint (v->src_module, v->lineno, "CS.VNAME", "Variable is not in the form sn_xxxx", v->names.names.names_val[0].name);
	}
      return;
    }

  //if (strcmp(v->names.names.names_val[0].name[0],"int

  printf ("Unexpected scope : %s -->%s\n", scope, v->names.names.names_val[0].name);
  exit (1);
}


int
has_variable (struct variable_list *v, char *name)
{
  int a;
  for (a = 0; a < v->variables.variables_len; a++)
    {
      if (A4GL_aubit_strcasecmp (v->variables.variables_val[a]->names.names.names_val[0].name, name) == 0)
	return 1;
    }
  return 0;
}

void
check_module (struct module_definition *d)
{
  struct commands *all_cmds = 0;
  int a;
  int b;

  all_cmds = linearise_commands (0, 0);
  printf ("Check Module %s\n", d->module_name);
  fflush (stdout);
  for (a = 0; a < d->imported_global_variables.variables.variables_len; a++)
    {
      check_variable_name (d->module_name, "ImportedGlobal", d->imported_global_variables.variables.variables_val[a]);
    }

  for (a = 0; a < d->exported_global_variables.variables.variables_len; a++)
    {
      check_variable_name (d->module_name, "Global", d->exported_global_variables.variables.variables_val[a]);
      if (has_variable
	  (&d->imported_global_variables, d->exported_global_variables.variables.variables_val[a]->names.names.names_val[0].name))
	{
	  A4GL_lint (0, d->exported_global_variables.variables.variables_val[a]->lineno, "CS.VARHIDE", "Global variable hides an imported Global variable", d->exported_global_variables.variables.variables_val[a]->names.names.names_val[0].name);
	}
    }


  for (a = 0; a < d->module_variables.variables.variables_len; a++)
    {

      check_variable_name (d->module_name, "Module", d->module_variables.variables.variables_val[a]);

      if (has_variable
	  (&d->imported_global_variables, d->module_variables.variables.variables_val[a]->names.names.names_val[0].name))
	{
	  A4GL_lint (d->module_name, d->module_variables.variables.variables_val[a]->lineno, "CS.VARHIDE", "Module variable hides an imported Global variable", d->module_variables.variables.variables_val[a]->names.names.names_val[0].name);
	}

      if (has_variable
	  (&d->exported_global_variables, d->module_variables.variables.variables_val[a]->names.names.names_val[0].name))
	{
	  A4GL_lint (d->module_name, d->module_variables.variables.variables_val[a]->lineno, "CS.VARHIDE", "Module variable hides an exported Global variable", d->module_variables.variables.variables_val[a]->names.names.names_val[0].name);
	}

      if (d->module_variables.variables.variables_val[a]->usage == 0
	  && d->module_variables.variables.variables_val[a]->assigned == 0)
	{
	  if (d->module_variables.variables.variables_val[a]->var_data.variable_type == VARIABLE_TYPE_CONSTANT)
	    continue;
	  yylineno = 1;
	  A4GL_lint (d->module_name, d->module_variables.variables.variables_val[a]->lineno, "VARNOTUSED", "Module variable is defined but not used", d->module_variables.variables.variables_val[a]->names.names.names_val[0].name);
	}

      if (d->module_variables.variables.variables_val[a]->usage == 0 && d->module_variables.variables.variables_val[a]->assigned)
	{
	  yylineno = 1;
	  A4GL_lint (d->module_name, d->module_variables.variables.variables_val[a]->lineno, "VARASSNOTUSED", "Module variable is assigned a value but not used", d->module_variables.variables.variables_val[a]->names.names.names_val[0].name);
	}


    }





  check_functions_in_module_for_complexity (d);
  if (d->source_code.lines.lines_len > 10000)
    {
      // from tools/sqlfmt/i4glxref.1j
      // JL suggests : 
      // If there are more than 10,000 lines in a file, the output becomes imperfectly columnar and the author of the I4GL code containing 10,000 lines in a single file should be shot!
      //
      A4GL_lint (d->module_name, 10000, "AUTHSHOOT", "Module is too long", NULL);

    }

  linearise_module (all_cmds, d);

  // Look for Prepared but not used...
  for (a = 0; a < all_cmds->cmds.cmds_len; a++)
    {
      if (all_cmds->cmds.cmds_val[a]->cmd_data.type == E_CMD_LINT_EXPECT_CMD)
	{
	  set_lint_expect (all_cmds->cmds.cmds_val[a]);
	  continue;
	}
      if (all_cmds->cmds.cmds_val[a]->cmd_data.type == E_CMD_LINT_IGNORE_CMD)
	{
	  set_lint_ignore (all_cmds->cmds.cmds_val[a]);
	  continue;
	}

      if (all_cmds->cmds.cmds_val[a]->cmd_data.type == E_CMD_PREPARE_CMD)
	{
	  int used = 0;
	  for (b = 0; b < all_cmds->cmds.cmds_len; b++)
	    {

	      // Prepares can be used for DECLARE or for EXECUTE
	      if (all_cmds->cmds.cmds_val[b]->cmd_data.type == E_CMD_EXECUTE_CMD)
		{
		  if (A4GL_aubit_strcasecmp
		      (lint_get_ident_as_string (d, all_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.prepare_cmd.stmtid),
		       lint_get_ident_as_string (d,
						 all_cmds->cmds.cmds_val[b]->cmd_data.command_data_u.execute_cmd.sql_stmtid)) == 0)
		    {
		      used++;
		    }
		}

	      if (all_cmds->cmds.cmds_val[b]->cmd_data.type == E_CMD_DECLARE_CMD)
		{
		  if (all_cmds->cmds.cmds_val[b]->cmd_data.command_data_u.declare_cmd.declare_dets->ident == NULL)
		    continue;
		  if (A4GL_aubit_strcasecmp
		      (lint_get_ident_as_string (d, all_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.prepare_cmd.stmtid),
		       lint_get_ident_as_string (d, all_cmds->cmds.cmds_val[b]->cmd_data.command_data_u.declare_cmd.declare_dets->
						 ident)) == 0)
		    {
		      used++;
		    }
		}

	    }

	  if (!used)
	    {
	      yylineno = all_cmds->cmds.cmds_val[a]->lineno;
	      A4GL_lint (all_cmds->cmds.cmds_val[a]->module, all_cmds->cmds.cmds_val[a]->lineno, "PREPARENOTUSED", "Prepared statement is not used", A4GL_strip_quotes (lint_get_ident_as_string (d, all_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.prepare_cmd.stmtid)));

	    }
	}

      clr_lint_expect ();
    }


  // Look for DECLAREd but not used...
  for (a = 0; a < all_cmds->cmds.cmds_len; a++)
    {
      if (all_cmds->cmds.cmds_val[a]->cmd_data.type == E_CMD_LINT_EXPECT_CMD)
	{
	  set_lint_expect (all_cmds->cmds.cmds_val[a]);
	  continue;
	}
      if (all_cmds->cmds.cmds_val[a]->cmd_data.type == E_CMD_LINT_IGNORE_CMD)
	{
	  set_lint_ignore (all_cmds->cmds.cmds_val[a]);
	  continue;
	}
      if (all_cmds->cmds.cmds_val[a]->cmd_data.type == E_CMD_DECLARE_CMD)
	{
	  int used = 0;
	  for (b = 0; b < all_cmds->cmds.cmds_len; b++)
	    {

	      // Prepares can be used for DECLARE or for EXECUTE
	      if (all_cmds->cmds.cmds_val[b]->cmd_data.type == E_CMD_OPEN_CURSOR_CMD)
		{
		  if (A4GL_aubit_strcasecmp
		      (lint_get_ident_as_string (d, all_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.declare_cmd.cursorname),
		       lint_get_ident_as_string (d,
						 all_cmds->cmds.cmds_val[b]->cmd_data.command_data_u.open_cursor_cmd.cursorname)) ==
		      0)
		    {
		      used++;
		    }
		}


	      if (all_cmds->cmds.cmds_val[b]->cmd_data.type == E_CMD_FOREACH_CMD)
		{
		  if (A4GL_aubit_strcasecmp
		      (lint_get_ident_as_string (d, all_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.declare_cmd.cursorname),
		       lint_get_ident_as_string (d,
						 all_cmds->cmds.cmds_val[b]->cmd_data.command_data_u.foreach_cmd.cursorname)) == 0)
		    {
		      used++;
		    }
		}
	    }

	  if (!used)
	    {
	      yylineno = all_cmds->cmds.cmds_val[a]->lineno;
	      A4GL_lint (all_cmds->cmds.cmds_val[a]->module, all_cmds->cmds.cmds_val[a]->lineno, "DECLARENOTUSED", "Cursor is DECLAREd but not OPENed", A4GL_strip_quotes (lint_get_ident_as_string (d, all_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.declare_cmd.cursorname)));
	    }
	}
      clr_lint_expect ();
    }


}























/********************************************************************************/
// LINT CHECKS FOR A PROGRAM (not a module )

static void
add_all_module_entry (module_entry * m)
{
  // For this call - this_module is defined in link.c
  // add_all_module_entry shouldn't be called during normal compilation- so it won't 
  // apply to the one defintion in the compiler (in parsehelp.c)
  if (m)
    {
      this_module.module_entries.module_entries_len++;
      this_module.module_entries.module_entries_val =
	realloc (this_module.module_entries.module_entries_val,
		 sizeof (module_entry *) * this_module.module_entries.module_entries_len);
      this_module.module_entries.module_entries_val[this_module.module_entries.module_entries_len - 1] = m;
    }
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
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_get_user") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_libhelp_showhelp") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_openiem") == 0)
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
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_add_acs_mapping") == 0)
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
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_send_to_ui") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_settitle") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_set_display_field_delimiters") == 0)
    return -1;

// INTs
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_random") == 0)
    return DTYPE_INT;
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_get_curr_height") == 0)
    return DTYPE_INT;
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_get_curr_width") == 0)
    return DTYPE_INT;
  if (A4GL_aubit_strcasecmp (funcname, "length") == 0)
    return DTYPE_INT;
  if (A4GL_aubit_strcasecmp (funcname, "arr_curr") == 0)
    return DTYPE_INT;
  if (A4GL_aubit_strcasecmp (funcname, "arr_count") == 0)
    return DTYPE_INT;
  if (A4GL_aubit_strcasecmp (funcname, "scr_line") == 0)
    return DTYPE_INT;
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_sendfile_to_ui") == 0)
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
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_replace_in_string") == 0)
    return DTYPE_CHAR;
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_getcwd") == 0)
    return DTYPE_CHAR;



  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_byte_as_str") == 0)
    return DTYPE_CHAR;

  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_read_pipe") == 0)
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
    return DTYPE_CHAR + ENCODE_SIZE (1);
  if (A4GL_aubit_strcasecmp (funcname, "fgl_dialog_getfieldname") == 0)
    return DTYPE_CHAR + ENCODE_SIZE (1);
  if (A4GL_aubit_strcasecmp (funcname, "fgl_getenv") == 0)
    return DTYPE_CHAR + ENCODE_SIZE (1);
  if (A4GL_aubit_strcasecmp (funcname, "fgl_getkey") == 0)
    return DTYPE_CHAR + ENCODE_SIZE (1);
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
find_function (char *s)
{
  int a;

  for (a = 0; a < this_module.module_entries.module_entries_len; a++)
    {
      struct module_entry *m;
      m = this_module.module_entries.module_entries_val[a];
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

	case E_MET_FORMHANDLER_DEFINITION:
	  //printf("Not implemented yet (E_MET_FORMHANDLER_DEFINITION.5)\n");
	  //exit(4);
	  break;

	default:

	  // Dont care - cant be a function or report anyway...
	  break;
	}
    }
  return -1;
}




int
find_function_single_rtype (char *funcname)
{
  int calltree_entry;
  static int callstack = 0;

  if (system_function (funcname))
    {
      return system_function_dtype (funcname);
    }

  calltree_entry = find_function (funcname);

  if (calltree_entry == -1)
    {
      if (is_bolton_function (funcname) != -1)
	{
	  int a;
	  a = is_bolton_function (funcname);

	  if (fboltons[a].nreturns > 1)
	    {
	      A4GL_lint (0, 0, "FUNCRETMANY", "Function returns more than one value but is being used where it should return only one", funcname);
	      return -1;
	    }

	  if (fboltons[a].nreturns < 1)
	    {
	      A4GL_lint (0, 0, "FUNCNOTRET", "Function does not return a value but is being used where it should return a value", funcname);
	      return -1;
	    }

	  return fboltons[a].return_dtypes[0];
	}
      else
	{
	  printf ("WARNING : No calltree entry for %s...)\n", funcname);
	  return DTYPE_CHAR;
	}
      /*
         int a;
         for (a = 0; a < this_module.module_entries.module_entries_len; a++)
         {
         struct module_entry *m;
         m = this_module.module_entries.module_entries_val[a];
         switch (m->met_type)
         {
         case E_MET_MAIN_DEFINITION:
         case E_MET_FUNCTION_DEFINITION:
         //printf ("%s (%d) %s\n", m->module_entry_u.function_definition.module,  m->module_entry_u.function_definition.lineno,     m->module_entry_u.function_definition.funcname); break;
         default: break;
         }
         }
         exit (2);
       */
    }

  if (fprototypes == 0)
    {
      printf ("Faking dtype to be CHAR for %s\n", funcname);
      return DTYPE_CHAR;	/* Well - it might be ;-) */
    }

  if (fprototypes[calltree_entry].nreturns == -1)
    {
      //int b;

      if (!system_function (funcname) && is_bolton_function (funcname) == -1)
	{
	  callstack++;
	  if (callstack < 5)
	    {
	      gen_function_prototypes (calltree_entry,
				       &this_module.module_entries.module_entries_val[calltree_entry]->module_entry_u.
				       function_definition);
	    }
	  callstack--;
	}
    }

  if (fprototypes[calltree_entry].nreturns == -1)
    {
      printf ("Functions (%s) return values  have not been 'described' yet -assuming single int\n", funcname);
      return DTYPE_INT;
      //exit (2);
    }

  if (fprototypes[calltree_entry].nreturns == 0)
    {
      //char buff[256];
      //sprintf (buff, "Function %s does not return a value but is being used where it should return a value", funcname);

      A4GL_lint (0, 0, "FUNCNOTRET", "Function does not return a value but is being used where it should return a value", funcname);
      //A4GL_lint (buff);
      return -1;
    }

  if (fprototypes[calltree_entry].nreturns != 1)
    {
      A4GL_lint (0, 0, "FUNCRETMANY", "Function returns more than one value but is being used where it should return only one", funcname);
      return -1;
    }

  return fprototypes[calltree_entry].return_dtypes[0];

}


/********************************************************************************/


static void
scan_module_entry (int *calltree, int a)
{
  struct module_entry *m;
  struct commands *rep_commands = 0;

  m = this_module.module_entries.module_entries_val[a];

  switch (m->met_type)
    {
    case E_MET_MAIN_DEFINITION:
      A4GL_lint (0, 0, "MAINMAIN", "MAIN shouldnt be called from MAIN", 0);
      break;

    case E_MET_FUNCTION_DEFINITION:
      set_lint_module (m->module_entry_u.function_definition.module);
      scan_functions (m->module_entry_u.function_definition.funcname, a, calltree, &m->module_entry_u.function_definition.call_list,
		      m->module_entry_u.function_definition.func_commands);
      break;

    case E_MET_REPORT_DEFINITION:
      set_lint_module (m->module_entry_u.report_definition.module);
      rep_commands = linearise_report (0, m->module_entry_u.pdf_report_definition.report_format_section);
      scan_functions (m->module_entry_u.report_definition.funcname, a, calltree, &m->module_entry_u.report_definition.call_list,
		      rep_commands);
      break;

    case E_MET_PDF_REPORT_DEFINITION:
      set_lint_module (m->module_entry_u.pdf_report_definition.module);
      rep_commands = linearise_report (0, m->module_entry_u.pdf_report_definition.report_format_section);
      scan_functions (m->module_entry_u.pdf_report_definition.funcname, a, calltree,
		      &m->module_entry_u.pdf_report_definition.call_list, rep_commands);
      break;

    case E_MET_FORMHANDLER_DEFINITION:
      printf ("Not implemented yet (E_MET_FORMHANDLER_DEFINITION.6)\n");
      exit (4);
      break;

    default:
      break;

    }
}


/********************************************************************************/
static int
promoteable (int a, int b)
{

  if (a == DTYPE_SERIAL)
    a = DTYPE_INT;
  if (b == DTYPE_SERIAL)
    b = DTYPE_INT;

  A4GL_assertion (a == DTYPE_SERIAL || b == DTYPE_SERIAL, "No serials in here..");
  if (a == b)
    return a;

  a = a & DTYPE_MASK;
  b = b & DTYPE_MASK;

  if (a == DTYPE_DTIME && b == DTYPE_DTIME)
    return DTYPE_DTIME;
  if (a == DTYPE_CHAR && b == DTYPE_CHAR)
    return DTYPE_CHAR;
  if (a == DTYPE_CHAR && b == DTYPE_VCHAR)
    return DTYPE_VCHAR;
  if (a == DTYPE_VCHAR && b == DTYPE_CHAR)
    return DTYPE_VCHAR;
  if (a == DTYPE_VCHAR && b == DTYPE_VCHAR)
    return DTYPE_VCHAR;

  if (a == DTYPE_DATE && b == DTYPE_DATE)
    return DTYPE_DATE;
  if (a == DTYPE_SERIAL)
    a = DTYPE_INT;
  if (b == DTYPE_SERIAL)
    b = DTYPE_INT;

  if (a == DTYPE_SMINT)
    {
      if (b == DTYPE_SMINT)
	return DTYPE_SMINT;
      if (b == DTYPE_INT)
	return DTYPE_INT;
      if (b == DTYPE_FLOAT)
	return DTYPE_FLOAT;
      if (b == DTYPE_SMFLOAT)
	return DTYPE_SMFLOAT;
      if (b == DTYPE_DECIMAL)
	return DTYPE_DECIMAL;
      if (b == DTYPE_MONEY)
	return DTYPE_MONEY;
      if (b == 90)
	return DTYPE_SMINT;
    }

  if (a == DTYPE_INT)
    {
      if (b == DTYPE_SMINT)
	return DTYPE_INT;
      if (b == DTYPE_INT)
	return DTYPE_INT;
      if (b == DTYPE_FLOAT)
	return DTYPE_FLOAT;
      if (b == DTYPE_SMFLOAT)
	return DTYPE_SMFLOAT;
      if (b == DTYPE_DECIMAL)
	return DTYPE_DECIMAL;
      if (b == DTYPE_MONEY)
	return DTYPE_MONEY;
      if (b == 90)
	return DTYPE_INT;
    }

  if (a == DTYPE_FLOAT)
    {
      if (b == DTYPE_SMINT)
	return DTYPE_FLOAT;
      if (b == DTYPE_INT)
	return DTYPE_FLOAT;
      if (b == DTYPE_FLOAT)
	return DTYPE_FLOAT;
      if (b == DTYPE_SMFLOAT)
	return DTYPE_FLOAT;
      if (b == DTYPE_DECIMAL)
	return DTYPE_DECIMAL;
      if (b == DTYPE_MONEY)
	return DTYPE_MONEY;
    }

  if (a == DTYPE_SMFLOAT)
    {
      if (b == DTYPE_SMINT)
	return DTYPE_SMFLOAT;
      if (b == DTYPE_INT)
	return DTYPE_SMFLOAT;
      if (b == DTYPE_FLOAT)
	return DTYPE_FLOAT;
      if (b == DTYPE_SMFLOAT)
	return DTYPE_SMFLOAT;
      if (b == DTYPE_DECIMAL)
	return DTYPE_DECIMAL;
      if (b == DTYPE_MONEY)
	return DTYPE_MONEY;
    }

  if (a == DTYPE_DECIMAL)
    {
      if (b == DTYPE_SMINT)
	return DTYPE_DECIMAL;
      if (b == DTYPE_INT)
	return DTYPE_DECIMAL;
      if (b == DTYPE_FLOAT)
	return DTYPE_DECIMAL;
      if (b == DTYPE_SMFLOAT)
	return DTYPE_DECIMAL;
      if (b == DTYPE_DECIMAL)
	return DTYPE_DECIMAL;
      if (b == DTYPE_MONEY)
	return DTYPE_DECIMAL;
    }

  if (a == DTYPE_MONEY)
    {
      if (b == DTYPE_SMINT)
	return DTYPE_DECIMAL;
      if (b == DTYPE_INT)
	return DTYPE_DECIMAL;
      if (b == DTYPE_FLOAT)
	return DTYPE_DECIMAL;
      if (b == DTYPE_SMFLOAT)
	return DTYPE_DECIMAL;
      if (b == DTYPE_DECIMAL)
	return DTYPE_DECIMAL;
      if (b == DTYPE_MONEY)
	return DTYPE_MONEY;
    }
  if (a == 90)
    {
      if (b == DTYPE_SMINT)
	return DTYPE_DECIMAL;
      if (b == DTYPE_INT)
	return DTYPE_DECIMAL;
      if (b == 90)
	return 90;
    }
  return -1;
}

//
// go through all the calls made by this function 
// and ensure that they are marked as called
//
static void
scan_functions (char *infuncname, int calltree_entry, int *calltree, struct call_list *f, struct commands *calling_funcs_cmds)
{
  int a;
  int b;
  struct commands *func_cmds = 0;
  struct command *r = 0;
  if (dbg)
    {
      printf ("DBG:In scan functions : %s %d\n", infuncname, calltree_entry);
      fflush (stdout);
    }



  // We only need to check the calls by expr for now - as these will include all the calls_by_call - 
  // we just cant check the return values just yet...
  for (a = 0; a < f->calls_by_expr.calls_by_expr_len; a++)
    {
      expr_str *e;
      int nparam;
      e = f->calls_by_expr.calls_by_expr_val[a];

      if (e->expr_type == ET_EXPR_SHARED_FCALL)
	{
	  // just continue..
	  continue;
	}
      if (e->expr_type == ET_EXPR_BOUND_FCALL)
	{
	  continue;
	}

      if (e->expr_type == ET_EXPR_FCALL)
	{
	  b = find_function (e->expr_str_u.expr_function_call->fname);
	  if (b == -1)
	    {
	      if (!system_function (e->expr_str_u.expr_function_call->fname)
		  && is_bolton_function (e->expr_str_u.expr_function_call->fname) == -1)
		{
		  yylineno = e->expr_str_u.expr_function_call->line;
		  A4GL_lint (e->expr_str_u.expr_function_call->module, e->expr_str_u.expr_function_call->line, "FUNCNOTDEF", "Function was called but is not defined", e->expr_str_u.expr_function_call->fname);
		  log_proto (e, 0);
		  continue;
		}
	      continue;
	    }
	  if (dbg)
	    printf ("DBG: Function found @ %d\n", b);
	  if (e->expr_str_u.expr_function_call->parameters)
	    {
	      e->expr_str_u.expr_function_call->parameters = A4GL_rationalize_list (e->expr_str_u.expr_function_call->parameters);
	      nparam = e->expr_str_u.expr_function_call->parameters->list.list_len;
	    }
	  else
	    {
	      nparam = 0;
	    }

	  // Now - we have the function prototypes in fprototypes - lets see if we have the right number of parameters
	  if (nparam != fprototypes[b].nparams)
	    {
	      char buff[256];
	      yylineno = e->expr_str_u.expr_function_call->line;
	      sprintf (buff, "Function %s expected %d passed %d", e->expr_str_u.expr_function_call->fname, fprototypes[b].nparams,
		       nparam);
	      A4GL_lint (e->expr_str_u.expr_function_call->module, e->expr_str_u.expr_function_call->line, "FUNCPARMCNT", "Function called with wrong number of parameters", buff);
	    }
	  else
	    {
	      int ecnt;
	      A4GL_assertion (nparam != fprototypes[b].nparams, "If test ?");
	      for (ecnt = 0; ecnt < nparam; ecnt++)
		{
		  int etype;
		  yylineno = e->expr_str_u.expr_function_call->line;
		  etype =
		    expr_datatype (e->expr_str_u.expr_function_call->module, e->expr_str_u.expr_function_call->line,
				   e->expr_str_u.expr_function_call->parameters->list.list_val[ecnt]) & DTYPE_MASK;
		  if (promoteable (etype, fprototypes[b].param_dtypes[ecnt]) == -1)
		    {
		      char buff[256];
		      char smbuff[256] = "";
#ifdef DUMP_PROTOTYPE
		      int c;
		      strcpy (smbuff, " ");
		      strcat (smbuff, e->expr_str_u.expr_function_call->fname);
		      strcat (smbuff, "(");
		      for (c = 0; c < nparam; c++)
			{
			  if (c)
			    strcat (smbuff, ",");
			  sprintf (buff, "%d", fprototypes[b].param_dtypes[c]);
			  strcat (smbuff, buff);
			}
		      strcat (smbuff, ")");
#endif
		      sprintf (buff, "Function %s expects '%s' got '%s' @ %d parameter", e->expr_str_u.expr_function_call->fname,
			       dtype_as_string (fprototypes[b].param_dtypes[ecnt]),
			       //fprototypes[b].param_dtypes[ecnt], 
			       dtype_as_string (etype),
			       //etype
			       ecnt + 1);
		      if (strlen (smbuff))
			strcat (buff, smbuff);
		      A4GL_lint (e->expr_str_u.expr_function_call->module, e->expr_str_u.expr_function_call->line, "FUNCPARMTYPE", "Incompatible parameter for function", buff);
		    }
		}
	    }

	  // Have we called this function before ? 
	  if (calltree[b] == 0)
	    {
	      // No - ok - spider down into this function to get all the functions that it calls...
	      calltree[b]++;
	      if (dbg)
		printf ("DBG: Finding function calls in function\n");
	      scan_module_entry (calltree, b);
	    }
	  continue;
	}

      printf ("Unexpected expression type : %d while checking for function calls\n", e->expr_type);

      exit (3);
    }




  func_cmds = linearise_commands (0, 0);
  linearise_commands (func_cmds, calling_funcs_cmds);


  // Now - lets have a look and see if we call any reports...
  for (a = 0; a < func_cmds->cmds.cmds_len; a++)
    {
      r = func_cmds->cmds.cmds_val[a];

      if (r->cmd_data.type == E_CMD_LINT_EXPECT_CMD)
	{
	  set_lint_expect (r);
	  continue;
	}
      if (r->cmd_data.type == E_CMD_LINT_IGNORE_CMD)
	{
	  set_lint_ignore (r);
	  continue;
	}
      if (r->cmd_data.type == E_CMD_START_CMD)
	{			// 
	  int b;
	  b = find_function (r->cmd_data.command_data_u.start_cmd.repname);
	  if (b < 0)
	    {
	      yylineno = r->lineno;
	      A4GL_lint (r->module, yylineno, "REPNOTDEF", "Report was called but is not defined", r->cmd_data.command_data_u.start_cmd.repname);
	      continue;
	    }
	  A4GL_assertion (b < 0, "Couldnt find report");
	  if (calltree[b] == 0)
	    {
	      // No - ok - spider down into this function to get all the functions that it calls...
	      calltree[b]++;
	      if (dbg)
		printf ("DBG: Finding function calls in function\n");
	      scan_module_entry (calltree, b);
	    }
	}

      if (r->cmd_data.type == E_CMD_FINISH_CMD)
	{			// 
	  int b;
	  //printf("%s\n", r->cmd_data.command_data_u.finish_cmd.repname);
	  b = find_function (r->cmd_data.command_data_u.finish_cmd.repname);
	  if (b < 0)
	    {
	      yylineno = r->lineno;
	      A4GL_lint (r->module, yylineno, "REPNOTDEF", "Report was called but is not defined", r->cmd_data.command_data_u.finish_cmd.repname);
	      continue;
	    }
	  A4GL_assertion (b < 0, "Couldnt find report");
	  if (calltree[b] == 0)
	    {
	      // No - ok - spider down into this function to get all the functions that it calls...
	      calltree[b]++;
	      if (dbg)
		printf ("DBG: Finding function calls in function\n");
	      scan_module_entry (calltree, b);
	    }

	}

      if (r->cmd_data.type == E_CMD_WHENEVER_CMD)
	{
	  int b;
	  if (r->cmd_data.command_data_u.whenever_cmd.whencode & 0x2)
	    {			// WHENEVER ERROR CALL
	      b = find_function (r->cmd_data.command_data_u.whenever_cmd.whento);
	      if (calltree[b] == 0)
		{
		  calltree[b]++;
		  scan_module_entry (calltree, b);
		}
	    }
	}
      if (r->cmd_data.type == E_CMD_OUTPUT_CMD)
	{			// 
	  int b;
	  //printf("%s\n", r->cmd_data.command_data_u.output_cmd.repname);
	  b = find_function (r->cmd_data.command_data_u.output_cmd.repname);
	  if (b < 0)
	    {
	      yylineno = r->lineno;
	      A4GL_lint (r->module, yylineno, "REPNOTDEF", "Report was called but is not defined", r->cmd_data.command_data_u.output_cmd.repname);
	      continue;
	    }
	  A4GL_assertion (b < 0, "Couldnt find report");
	  if (calltree[b] == 0)
	    {
	      // No - ok - spider down into this function to get all the functions that it calls...
	      calltree[b]++;
	      if (dbg)
		printf ("DBG: Finding function calls in function\n");
	      scan_module_entry (calltree, b);
	    }
	}

      clr_lint_expect ();

    }

  // We should now have scanned all our called function...
  // return types should therefore have been set - we can look to see what we're returning...
  if (dbg)
    printf ("DBG : Examining return values\n");


  // Have we already processed the return values for this function ? 
  if (fprototypes[calltree_entry].nreturns == -1)
    {
      // No - we havent lets get all the commands in a list
      // so we can easily go through them

      //printf("Function %s contains %d commands\n", infuncname, func_cmds->cmds.cmds_len);
      for (a = 0; a < func_cmds->cmds.cmds_len; a++)
	{
	  r = func_cmds->cmds.cmds_val[a];



	  if (r->cmd_data.type == E_CMD_LINT_EXPECT_CMD)
	    {
	      set_lint_expect (r);
	      continue;
	    }
	  if (r->cmd_data.type == E_CMD_LINT_IGNORE_CMD)
	    {
	      set_lint_ignore (r);
	      continue;
	    }
	  //printf("Cmd %d - type = %d\n", a, r->cmd_data.type);
	  // Its a return
	  if (r->cmd_data.type == E_CMD_RETURN_CMD)
	    {
	      if (dbg)
		{
		  printf ("DBG: Got a return in %s @ %d\n", infuncname, r->lineno);
		  fflush (stdout);
		}
	      if (dbg)
		{
		  printf ("DBG: fprototypes[calltree_entry].nreturns=%d\n", fprototypes[calltree_entry].nreturns);
		}
	      if (fprototypes[calltree_entry].nreturns == -1)
		{
		  int nrets;
		  if (r->cmd_data.command_data_u.return_cmd.retvals)
		    {
		      nrets = r->cmd_data.command_data_u.return_cmd.retvals->list.list_len;
		    }
		  else
		    {
		      nrets = 0;
		    }
		  fprototypes[calltree_entry].nreturns = nrets;
		  fprototypes[calltree_entry].return_dtypes = malloc (sizeof (long) * fprototypes[calltree_entry].nreturns);

		  for (b = 0; b < nrets; b++)
		    {
		      expr_str *e;
		      e = r->cmd_data.command_data_u.return_cmd.retvals->list.list_val[b];
		      yylineno = r->lineno;
		      fprototypes[calltree_entry].return_dtypes[b] = expr_datatype (r->module, r->lineno, e);
		    }
		}
	      else
		{
		  int nrets;
		  yylineno = r->lineno;
		  if (r->cmd_data.command_data_u.return_cmd.retvals == 0)
		    {
		      nrets = 0;
		    }
		  else
		    {
		      nrets = r->cmd_data.command_data_u.return_cmd.retvals->list.list_len;
		    }
		  if (fprototypes[calltree_entry].nreturns != nrets)
		    {
		      A4GL_lint (r->module, r->lineno, "FUNCRETCNT", "Function RETURNs different numbers of values(7)", 0);
		    }
		  else
		    {
		      for (b = 0; b < nrets; b++)
			{
			  expr_str *e;
			  int dtype1;
			  int dtype2;

			  e = r->cmd_data.command_data_u.return_cmd.retvals->list.list_val[b];
			  dtype1 = fprototypes[calltree_entry].return_dtypes[b];
			  yylineno = r->lineno;
			  dtype2 = expr_datatype (r->module, r->lineno, e);

			  if (dtype1 != dtype2)
			    {
			      int final_dtype;
			      char buff[256];
			      // if we've previously returned a smallint and now are returning an integer
			      // that should be fine - we just need to change our prototype...
			      final_dtype = promoteable (dtype1, dtype2);
			      if (final_dtype == -1)
				{
				  sprintf (buff, "Expression %d type %s!=%s", b + 1, dtype_as_string (dtype1),
					   dtype_as_string (dtype2));
				  A4GL_lint (r->module, r->lineno, "FUNCRETTYPE", "Return value has a different type", buff);
				}
			      else
				{
				  fprototypes[calltree_entry].return_dtypes[b] = final_dtype;
				}
			    }
			}

		    }
		}
	    }

	  clr_lint_expect ();
	}
    }

}


static struct module_definition *
find_module (module_definition * mods, int nmodules, char *name)
{
  int a;
  for (a = 0; a < nmodules; a++)
    {
      if (strcmp (mods[a].module_name, name) == 0)
	return &mods[a];
    }
  return NULL;
}


int
check_program (module_definition * mods, int nmodules)
{
  char *dbname = 0;
  int a;
  int b;
  int *calltree;
  int bad_load = 0;
  int main_cnt = 0;
  struct commands *all_cmds = 0;
  char *fname;
  int mcnt;
  int fromLibrary[50000];


  init_lint ();



  if (get_lint_style () == 2)
    {
      if (inc4GL)
	{
	  // Dump the sourcecode of the 4gls
	  fprintf (lintfile, "<MODULES>\n");
	  for (a = 0; a < nmodules; a++)
	    {
	      int line;
	      fprintf (lintfile, "<MODULE NAME=\"%s\" MODULENO=\"%d\" FULLNAME=\"%s\" ISINLIBRARY=\"%ld\">\n", mods[a].module_name, a,
		       local_xml_escape (mods[a].full_path_filename), 
			mods[a].moduleIsInLibrary
			);
	      for (line = 0; line < mods[a].source_code.lines.lines_len; line++)
		{
		  fprintf (lintfile, "<LINE>%s</LINE>\n", local_xml_escape (mods[a].source_code.lines.lines_val[line]));
		}
	      fprintf (lintfile, "</MODULE>\n");
	    }
	  fprintf (lintfile, "</MODULES>\n");
	}

      fprintf (lintfile, "<LINTS>\n");
    }

  fname = acl_getenv_not_set_as_0 ("CFUNCSFILE");
  if (fname)
    {
      load_boltons (fname);
    }
  else
    {
      printf ("WARNING - not CFUNCSFILE file specified\n");
    }
  this_module.module_name = "COMPOSITE";
  this_module.module_entries.module_entries_len = 0;
  this_module.module_entries.module_entries_val = 0;
  this_module.source_code.lines.lines_len = 0;
  this_module.source_code.lines.lines_val = 0;
  yylineno = 0;

  for (a = 0; a < nmodules; a++)
    {
      for (b = a + 1; b < nmodules; b++)
	{
	  if (A4GL_aubit_strcasecmp (mods[a].module_name, mods[b].module_name) == 0)
	    {
	      bad_load++;
	      printf ("Module :%s loaded more than once...\n", mods[a].module_name);
	    }
	}
    }
  if (bad_load)
    {
      exit (1);
    }

  for (a = 0; a < nmodules; a++)
    {
      char buff1[256];
      char buff2[256];
      for (b = a + 1; b < nmodules; b++)
	{

	  if (mods[a].module_name[0] == 'F')
	    {
	      strcpy (buff1, &mods[a].module_name[1]);
	    }
	  else
	    {
	      strcpy (buff1, mods[a].module_name);
	    }

	  if (mods[b].module_name[0] == 'F')
	    {
	      strcpy (buff2, &mods[b].module_name[1]);
	    }
	  else
	    {
	      strcpy (buff2, mods[b].module_name);
	    }

	  if (A4GL_aubit_strcasecmp (buff1, buff2) == 0)
	    {
	      A4GL_lint (mods[a].module_name, 0, "MODNAME", "Module name used for Function and non-function module", buff1);
	    }
	}
    }

  for (a = 0; a < nmodules; a++)
    {
      if (mods[a].mod_dbname)
	{
	  if (dbname == 0)
	    dbname = mods[a].mod_dbname;
	  else
	    {
	      if (A4GL_aubit_strcasecmp (dbname, mods[a].mod_dbname))
		{
		  char buff[256];
		  if (strlen (mods[a].mod_dbname) && strlen (dbname))
		    {
		      sprintf (buff, "%s!=%s", dbname, mods[a].mod_dbname);
		      A4GL_lint (mods[a].module_name, 0, "DBDIFF", "Module compiled against a different database", buff);
		    }
		  if (strlen (dbname) == 0 && strlen (mods[a].mod_dbname) > 0)
		    {
		      dbname = mods[a].mod_dbname;
		    }
		}
	    }
	}

      printf ("Module : %s.4gl\n", mods[a].module_name);
      for (b = 0; b < mods[a].module_entries.module_entries_len; b++)
	{
		fromLibrary[this_module.module_entries.module_entries_len]=mods[a].moduleIsInLibrary;
	  	add_all_module_entry (mods[a].module_entries.module_entries_val[b]);
	}

    }
  for (a = 0; a < nmodules; a++)
    {
      lint_module = mods[a].module_name;
      check_module (&mods[a]);
    }

  printf ("Program\n");
  if (dbname)
    {
      open_db (dbname);

    }

  lint_module = LINTMODULE_FOR_PROGRAM;


  // Create and clear down some cache informaton for 
  // function definitions/calls
  calltree = malloc (sizeof (int) * this_module.module_entries.module_entries_len);
  fprototypes = malloc (sizeof (struct s_function_prototype) * this_module.module_entries.module_entries_len);



  for (a = 0; a < this_module.module_entries.module_entries_len; a++)
    {
      calltree[a] = 0;

      fprototypes[a].proto_type = 0;
      fprototypes[a].pname = 0;
      fprototypes[a].nparams = -1;
      fprototypes[a].nreturns = -1;
      fprototypes[a].param_dtypes = 0;
      fprototypes[a].return_dtypes = 0;
    }


  // Go through and generate our function prototypes - 
  // so we can check these really quickly
  for (a = 0; a < this_module.module_entries.module_entries_len; a++)
    {
      struct module_entry *m;
      m = this_module.module_entries.module_entries_val[a];
      switch (m->met_type)
	{
	case E_MET_FUNCTION_DEFINITION:
	  {
	    struct s_function_definition *f;
	    f = &m->module_entry_u.function_definition;
	    fprototypes[a].proto_type = PROTO_FUNCTION;
	    fprototypes[a].pname = f->funcname;

	    f->parameters = expand_parameters (&f->variables, f->parameters);
	    if (f->parameters == 0)
	      {
		fprototypes[a].nparams = 0;
	      }
	    else
	      {
		fprototypes[a].nparams = f->parameters->list.list_len;
	      }

	    if (fprototypes[a].nparams)
	      {
		fprototypes[a].param_dtypes = malloc (sizeof (long) * fprototypes[a].nparams);

		for (b = 0; b < f->parameters->list.list_len; b++)
		  {
		    fprototypes[a].param_dtypes[b] =
		      expr_datatype (f->module, f->lineno, f->parameters->list.list_val[b]) & DTYPE_MASK;
		  }

	      }
	    gen_function_prototypes (a, f);

	    if (f->parameters && f->parameters->list.list_len > 100)
	      {
		A4GL_lint (f->module, f->lineno, "FUNCPARAMNUM", "FUNCTION has a lot of parameters", f->funcname);
	      }
	  }
	  break;

	case E_MET_MAIN_DEFINITION:
	  {
	    struct s_function_definition *f;
	    f = &m->module_entry_u.function_definition;
	    fprototypes[a].proto_type = PROTO_FUNCTION;
	    fprototypes[a].pname = f->funcname;
	    if (f->parameters == 0)
	      {
		fprototypes[a].nparams = 0;
	      }
	    else
	      {
		fprototypes[a].nparams = f->parameters->list.list_len;
	      }

	    if (fprototypes[a].nparams)
	      {
		fprototypes[a].param_dtypes = malloc (sizeof (long) * fprototypes[a].nparams);
		for (b = 0; b < f->parameters->list.list_len; b++)
		  {
		    fprototypes[a].param_dtypes[b] =
		      expr_datatype (f->module, f->lineno, f->parameters->list.list_val[b]) & DTYPE_MASK;
		  }
	      }
	  }
	  break;

	case E_MET_REPORT_DEFINITION:
	  {
	    struct s_report_definition *fr;
	    fr = &m->module_entry_u.report_definition;
	    fprototypes[a].proto_type = PROTO_REPORT;
	    fprototypes[a].pname = fr->funcname;
	    fr->parameters = expand_parameters (&fr->variables, fr->parameters);
	    if (fr->parameters == 0)
	      {
		fprototypes[a].nparams = 0;
	      }
	    else
	      {
		fprototypes[a].nparams = fr->parameters->list.list_len;
	      }

	    if (fprototypes[a].nparams)
	      {
		fprototypes[a].param_dtypes = malloc (sizeof (long) * fprototypes[a].nparams);
		for (b = 0; b < fr->parameters->list.list_len; b++)
		  {
		    fprototypes[a].param_dtypes[b] =
		      expr_datatype (fr->module, fr->lineno, fr->parameters->list.list_val[b]) & DTYPE_MASK;
		  }
	      }
	    if (fr->parameters && fr->parameters->list.list_len > 100)
	      {
		A4GL_lint (fr->module, fr->lineno, "FUNCPARAMNUM", "FUNCTION has a lot of parameters", fr->funcname);
	      }
	  }
	  break;

	case E_MET_PDF_REPORT_DEFINITION:
	  {
	    struct s_pdf_report_definition *fr;
	    fr = &m->module_entry_u.pdf_report_definition;
	    fr->parameters = expand_parameters (&fr->variables, fr->parameters);
	    fprototypes[a].proto_type = PROTO_REPORT;
	    fprototypes[a].pname = fr->funcname;
	    if (fr->parameters == 0)
	      {
		fprototypes[a].nparams = 0;
	      }
	    else
	      {
		fprototypes[a].nparams = fr->parameters->list.list_len;
	      }

	    if (fprototypes[a].nparams)
	      {
		fprototypes[a].param_dtypes = malloc (sizeof (long) * fprototypes[a].nparams);
		for (b = 0; b < fr->parameters->list.list_len; b++)
		  {
		    fprototypes[a].param_dtypes[b] =
		      expr_datatype (fr->module, fr->lineno, fr->parameters->list.list_val[b]) & DTYPE_MASK;
		  }
	      }
	    if (fr->parameters && fr->parameters->list.list_len > 100)
	      {
		A4GL_lint (fr->module, fr->lineno, "FUNCPARAMNUM", "FUNCTION has a lot of parameters", fr->funcname);
	      }
	  }
	  break;
	case E_MET_FORMHANDLER_DEFINITION:
	  printf ("Not implemented yet (E_MET_FORMHANDLER_DEFINITION.1)\n");
	  exit (4);
	  break;

	case E_MET_CMD:
	  {
	    struct command *c;
	    c = m->module_entry_u.cmd;
	    if (c->cmd_data.type == E_CMD_LINT_IGNORE_CMD)
	      {
		set_lint_ignore (c);
	      }

	  }

	  break;
	default:
	  break;		// Cant have a function prototype
	}
    }


  bad_load = 0;
  // lets look for any duplicates...
  for (a = 0; a < this_module.module_entries.module_entries_len; a++)
    {
      char *mod_a = "Unknown";
      int yylineno_a = -1;
      char *mod_b = "Unknown";
      int yylineno_b = -1;
      switch (this_module.module_entries.module_entries_val[a]->met_type)
	{
	case E_MET_PDF_REPORT_DEFINITION:
	  yylineno_a = this_module.module_entries.module_entries_val[a]->module_entry_u.pdf_report_definition.lineno;
	  mod_a = this_module.module_entries.module_entries_val[a]->module_entry_u.pdf_report_definition.module;
	  break;
	case E_MET_REPORT_DEFINITION:
	  yylineno_a = this_module.module_entries.module_entries_val[a]->module_entry_u.report_definition.lineno;
	  mod_a = this_module.module_entries.module_entries_val[a]->module_entry_u.report_definition.module;
	  break;
	case E_MET_FUNCTION_DEFINITION:
	  yylineno_a = this_module.module_entries.module_entries_val[a]->module_entry_u.function_definition.lineno;
	  mod_a = this_module.module_entries.module_entries_val[a]->module_entry_u.function_definition.module;
	  break;

	default:
	  break;
	}
      if (fprototypes[a].pname == 0)
	continue;

      for (b = a + 1; b < this_module.module_entries.module_entries_len; b++)
	{
	  if (fprototypes[b].pname == 0)
	    continue;


	  if (A4GL_aubit_strcasecmp (fprototypes[a].pname, fprototypes[b].pname) == 0) {
		//printf ("Duplicate name check : %d %d - %s %s, a=%d b=%d \n", fromLibrary[b], fromLibrary[a], fprototypes[a].pname, fprototypes[b].pname, a,b);
		// Is that module marked as being in a library ? 
          	if (fromLibrary[b]) {
			// We can ignore it..
			fprototypes[b].pname[0]='!';
			continue;
	  	} else {
          		if (fromLibrary[a]) {
				// We can ignore it..
				fprototypes[a].pname[0]='!';
				continue;
	  		}
		}
	 }


	  if (A4GL_aubit_strcasecmp (fprototypes[a].pname, fprototypes[b].pname) == 0)
	    {
	      char buff[256];



	      switch (this_module.module_entries.module_entries_val[b]->met_type)
		{
		case E_MET_PDF_REPORT_DEFINITION:
		  yylineno_b = this_module.module_entries.module_entries_val[b]->module_entry_u.pdf_report_definition.lineno;
		  mod_b = this_module.module_entries.module_entries_val[b]->module_entry_u.pdf_report_definition.module;
		  break;
		case E_MET_REPORT_DEFINITION:
		  yylineno_b = this_module.module_entries.module_entries_val[b]->module_entry_u.report_definition.lineno;
		  mod_b = this_module.module_entries.module_entries_val[b]->module_entry_u.report_definition.module;
		  break;
		case E_MET_FUNCTION_DEFINITION:
		  yylineno_b = this_module.module_entries.module_entries_val[b]->module_entry_u.function_definition.lineno;
		  mod_b = this_module.module_entries.module_entries_val[b]->module_entry_u.function_definition.module;
		  break;
		default:
		  break;
		}
	      yylineno = yylineno_b;

	      bad_load++;


	      sprintf (buff, "%s First in %s.4gl Lines %d (%s.4gl %d, %d %d)", fprototypes[a].pname, mod_a, yylineno_a, mod_b,
		       yylineno_b, a, b);
	      A4GL_lint (mod_b, yylineno_b, "FUNCDUP", "Function name is duplicated", buff);

	    }
	}
    }

  if (bad_load)
    {
      printf ("Aborting further lint checks\n");
      exit (2);
    }

  // Ok - starting with our 'main' - call any functions called by this one...
  for (a = 0; a < this_module.module_entries.module_entries_len; a++)
    {
      struct module_entry *m;
      m = this_module.module_entries.module_entries_val[a];
      switch (m->met_type)
	{
	case E_MET_MAIN_DEFINITION:
	  main_cnt++;
	  set_lint_module (m->module_entry_u.function_definition.module);
	  calltree[a]++;
	  scan_functions ("MAIN", a, calltree, &m->module_entry_u.function_definition.call_list,
			  m->module_entry_u.function_definition.func_commands);
	  break;
	default:
	  break;
	}
    }

  // Did we find any main ? 
  if (main_cnt == 0)
    {
      A4GL_lint (LINTMODULE_FOR_PROGRAM, 0, "NOMAIN", "Program has no MAIN", 0);
      nomain++;
    }


  // Did we find more than one!
  if (main_cnt > 1)
    {
      A4GL_lint (LINTMODULE_FOR_PROGRAM, 0, "MAINDUP", "Program has more than one MAIN", 0);
    }

  // Right - we should have searched all our functions
  // and all the functions called by our functions etc
  // whats not been called at all ? 
  for (a = 0; a < this_module.module_entries.module_entries_len; a++)
    {
      struct module_entry *m;
      m = this_module.module_entries.module_entries_val[a];
      if (calltree[a] == 0)
	{
	  switch (m->met_type)
	    {
	    case E_MET_FUNCTION_DEFINITION:
		if ( fprototypes[a].pname[0]!=' ') {
	      		yylineno = m->module_entry_u.function_definition.lineno;
	      		A4GL_lint (m->module_entry_u.function_definition.module, m->module_entry_u.function_definition.lineno, "FUNCNOTCALLED", "Function is defined but never called", m->module_entry_u.function_definition.funcname);
		}
	      break;
	    default:		// dont care
	      break;
	    }
	}
    }



  for (a = 0; a < nmodules; a++)
    {
      int mod_used = 0;
      for (b = 0; b < mods[a].module_entries.module_entries_len; b++)
	{
	  struct module_entry *m;
	  int fno;
	  m = mods[a].module_entries.module_entries_val[b];
	  switch (m->met_type)
	    {
	    case E_MET_FUNCTION_DEFINITION:
	      fno = find_function (m->module_entry_u.function_definition.funcname);
	      if (calltree[fno])
		mod_used++;
	      break;

	    default:
	      mod_used++;
	    }
	}


      // We're not calling anything - but was there anything to actually call ? 
      //
      // The normal situation here is when we have a GLOBALS module...
      //
      if (mod_used == 0)
	{
	  int b = 0;
	  int has_something = 0;
	  for (b = 0; b < mods[a].module_entries.module_entries_len; b++)
	    {
	      switch (mods[a].module_entries.module_entries_val[b]->met_type)
		{
		case E_MET_MAIN_DEFINITION:
		case E_MET_FUNCTION_DEFINITION:
		case E_MET_REPORT_DEFINITION:
		case E_MET_PDF_REPORT_DEFINITION:
		case E_MET_FORMHANDLER_DEFINITION:
		case E_MET_IMPORT_FUNCTION_DEFINITION:
		case E_MET_IMPORT_LEGACY_DEFINITION:
		case E_MET_CLASS_DEFINITION:
		case E_MET_IMPORT_DATATYPE:
		case E_MET_IMPORT_PACKAGE:
		  has_something++;
		  break;

		case E_MET_CMD:
		  break;

		}
	    }


	  if (has_something)
	    {
		if (mods[a].moduleIsInLibrary==0) {
	      		A4GL_lint (mods[a].module_name, 1, "MODNOTCALLED", "No Functions are called", 0);
		}
	    }
	  else
	    {
	      // Nothing defined in there..
	      //
	      if (mods[a].exported_global_variables.variables.variables_len)
		{
		  // Its a global variable..
		}
	      else
		{
		if (mods[a].moduleIsInLibrary==0) {
		  		A4GL_lint (mods[a].module_name, 1, "MODNOFUNCS", "Module has no substantial contents", 0);
			}
		}
	    }

	}

    }



  for (a = 0; a < nmodules; a++)
    {
      check_whenever_abuse (&mods[a]);
    }

  all_cmds = linearise_commands (0, 0);

  linearise_module (all_cmds, &this_module);
  check_functions_in_module (calltree, &this_module);





  // Look for OPEN FORM but not DISPLAYed...
  for (a = 0; a < all_cmds->cmds.cmds_len; a++)
    {
      if (all_cmds->cmds.cmds_val[a]->cmd_data.type == E_CMD_LINT_EXPECT_CMD)
	{
	  set_lint_expect (all_cmds->cmds.cmds_val[a]);
	  continue;
	}
      if (all_cmds->cmds.cmds_val[a]->cmd_data.type == E_CMD_LINT_IGNORE_CMD)
	{
	  set_lint_ignore (all_cmds->cmds.cmds_val[a]);
	  continue;
	}
      if (all_cmds->cmds.cmds_val[a]->cmd_data.type == E_CMD_OPEN_FORM_CMD)
	{
	  int used = 0;
	  for (b = 0; b < all_cmds->cmds.cmds_len; b++)
	    {

	      // Prepares can be used for DECLARE or for EXECUTE
	      if (all_cmds->cmds.cmds_val[b]->cmd_data.type == E_CMD_DISPLAY_FORM_CMD)
		{
		  if (A4GL_aubit_strcasecmp
		      (lint_get_ident_as_string
		       (find_module (mods, nmodules, all_cmds->cmds.cmds_val[a]->module),
			all_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.open_form_cmd.formname),
		       lint_get_ident_as_string (find_module (mods, nmodules, all_cmds->cmds.cmds_val[a]->module),
						 all_cmds->cmds.cmds_val[b]->cmd_data.command_data_u.display_form_cmd.formname)) ==
		      0)
		    {
		      used++;
		    }
		}
	    }

	  if (!used)
	    {
	      yylineno = all_cmds->cmds.cmds_val[a]->lineno;
	      A4GL_lint (all_cmds->cmds.cmds_val[a]->module, yylineno, "FORMNOTDISP", "FORM is OPENed but not DISPLAYed", lint_get_ident_as_string (find_module (mods, nmodules, all_cmds->cmds.cmds_val[a]->module), all_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.open_form_cmd.formname));
	      //sprintf(buff,"FORM (%s) is OPENed but not DISPLAYed", A4GL_strip_quotes(all_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.open_form_cmd.formname));
	    }
	}
      clr_lint_expect ();
    }


  for (mcnt = 0; mcnt < this_module.module_entries.module_entries_len; mcnt++)
    {
      struct module_entry *m;
      char *repname = 0;
      char *module;
      int r_outputed = 0;
      int r_started = 0;
      int r_finished = 0;
      int lineno;
      m = this_module.module_entries.module_entries_val[mcnt];
      switch (m->met_type)
	{
	case E_MET_REPORT_DEFINITION:
	  {
	    struct s_report_definition *fr;
	    fr = &m->module_entry_u.report_definition;
	    lineno = fr->lineno;
	    repname = fr->funcname;
	    module = fr->module;
	    break;
	  }

	case E_MET_PDF_REPORT_DEFINITION:
	  {
	    struct s_pdf_report_definition *fr;
	    fr = &m->module_entry_u.pdf_report_definition;
	    lineno = fr->lineno;
	    repname = fr->funcname;
	    module = fr->module;

	    break;
	  }
	default:
	  repname = 0;
	  break;
	}

      if (repname == 0)
	continue;		// its not a report...

      // Look for OUTPUT 
      for (a = 0; a < all_cmds->cmds.cmds_len; a++)
	{
	  if (all_cmds->cmds.cmds_val[a]->cmd_data.type == E_CMD_LINT_EXPECT_CMD)
	    {
	      set_lint_expect (all_cmds->cmds.cmds_val[a]);
	      continue;
	    }
	  if (all_cmds->cmds.cmds_val[a]->cmd_data.type == E_CMD_LINT_IGNORE_CMD)
	    {
	      set_lint_ignore (all_cmds->cmds.cmds_val[a]);
	      continue;
	    }
	  switch (all_cmds->cmds.cmds_val[a]->cmd_data.type)
	    {
	    case E_CMD_OUTPUT_CMD:
	      if (strcmp (all_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.output_cmd.repname, repname) == 0)
		{
		  r_outputed++;
		}
	      break;
	    case E_CMD_FINISH_CMD:
	      if (strcmp (all_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.finish_cmd.repname, repname) == 0)
		{
		  r_finished++;
		}
	      break;
	    case E_CMD_START_CMD:
	      if (strcmp (all_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.start_cmd.repname, repname) == 0)
		{
		  r_started++;
		}
	      break;
	    default:
	      break;
	    }

	  clr_lint_expect ();
	}
      yylineno = lineno;
      if (!r_started && !r_outputed && !r_finished)
	{
	  A4GL_lint (module, yylineno, "REPNOTUSED", "Report is never used", repname);
	}
      else
	{
	  if (!r_started)
	    {
	      A4GL_lint (module, yylineno, "REPNOTSTART", "Report is never started", repname);
	    }
	  if (!r_outputed)
	    {
	      A4GL_lint (module, yylineno, "REPNOTOUTPUT", "Report is never OUTPUTed", repname);
	    }
	  if (!r_finished)
	    {
	      A4GL_lint (module, yylineno, "REPNOTFINISHED", "Report is never finished", repname);
	    }

	}

    }


  // CURRENT WINDOW IS or CLOSE WINDOW but not OPENED...
  for (a = 0; a < all_cmds->cmds.cmds_len; a++)
    {
      int found_something = 0;
      char *cwindow = "undefined";
      char *action = "undefined";
      if (all_cmds->cmds.cmds_val[a]->cmd_data.type == E_CMD_LINT_EXPECT_CMD)
	{
	  set_lint_expect (all_cmds->cmds.cmds_val[a]);
	  continue;
	}
      if (all_cmds->cmds.cmds_val[a]->cmd_data.type == E_CMD_LINT_IGNORE_CMD)
	{
	  set_lint_ignore (all_cmds->cmds.cmds_val[a]);
	  continue;
	}

      if (all_cmds->cmds.cmds_val[a]->cmd_data.type == E_CMD_CURRENT_WIN_CMD)
	{
	  if (A4GL_aubit_strcasecmp
	      (lint_get_ident_as_string
	       (find_module (mods, nmodules, all_cmds->cmds.cmds_val[a]->module),
		all_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.current_win_cmd.windowname), "screen") != 0)
	    {
	      // CURRENT WINDOW IS SCREEN should always be ok :-)
	      found_something++;
	      cwindow =
		lint_get_ident_as_string (find_module (mods, nmodules, all_cmds->cmds.cmds_val[a]->module),
					  all_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.current_win_cmd.windowname);
	      action = "has been made CURRENT";
	    }
	}
      if (all_cmds->cmds.cmds_val[a]->cmd_data.type == E_CMD_CLOSE_CMD)
	{
	  if (all_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.close_cmd.cl_type == E_CT_WINDOW)
	    {
	      found_something++;
	      cwindow =
		lint_get_ident_as_string (find_module (mods, nmodules, all_cmds->cmds.cmds_val[a]->module),
					  all_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.close_cmd.ident);
	      action = "has been CLOSEd";
	    }
	}


      if (found_something)
	{
	  int used = 0;
	  for (b = 0; b < all_cmds->cmds.cmds_len; b++)
	    {
	      if (all_cmds->cmds.cmds_val[b]->cmd_data.type == E_CMD_OPEN_WINDOW_CMD)
		{
		  if (A4GL_aubit_strcasecmp
		      (cwindow,
		       lint_get_ident_as_string (find_module (mods, nmodules, all_cmds->cmds.cmds_val[a]->module),
						 all_cmds->cmds.cmds_val[b]->cmd_data.command_data_u.open_window_cmd.windowname)) ==
		      0)
		    {
		      used++;
		    }
		}
	    }

	  if (!used)
	    {
	      yylineno = all_cmds->cmds.cmds_val[a]->lineno;
	      if (A4GL_aubit_strcasecmp (action, "has been made CURRENT") == 0)
		{
		  A4GL_lint (all_cmds->cmds.cmds_val[a]->module, yylineno, "WINDOWNOTOPEN", "CURRENT WINDOW for window which is never OPENed", cwindow);
		}
	      if (A4GL_aubit_strcasecmp (action, "has been CLOSEd") == 0)
		{
		  A4GL_lint (all_cmds->cmds.cmds_val[a]->module, yylineno, "WINDOWNOTOPEN", "CLOSE WINDOW for window which is never OPENed", cwindow);
		}
	    }
	}
      clr_lint_expect ();
    }


  return 1;
}


void
set_lint_module (char *s)
{
  lint_module = s;
}


static void add_severity(char *s, int n) {
int a;
for (a=0;a<1000;a++) {
	if (severities[a].code==0) {
		severities[a].code=strdup(s);
		severities[a].severity=n;
		severities[a+1].code=0;
		severities[a+1].severity=0;
		return;
	}

	if (strcmp(severities[a].code,s)==0) {
		// Found it already
		severities[a].severity=n;
		return;
	}
}
}

static void add_custom_severities(void) {
char *fname;
FILE *f;
char code[200];
char buff[256];
int level;
fname=acl_getenv("A4GL_LINTSEVERITYFILE");
if (fname) {
	if (strlen(fname)==0) fname=0;
}

if (fname==0) {return;}
f=fopen(fname,"r");
if (f==0) return;
while (1) {
	strcpy(buff,"");
	fgets(buff,256,f);
	if (feof(f)) break;
	A4GL_trim_nl(buff);
	A4GL_trim(buff);
	if (sscanf(buff,"%s %d",code,&level)==2) {
		add_severity(code,level);
	}
}
fclose(f);
}

static int
get_severity (char *code)
{
  int a;



  for (a = 0; severities[a].code; a++)
    {
      if (strcmp (code, severities[a].code) == 0)
	{
	  //printf("Found severity : %s %d\n", code,severities[a].severity);
	  return severities[a].severity;
	}
    }
  return 5;
}


void
A4GL_lint (char *module_in, int lintline, char *code, char *type, char *extra)
{
  char buff[256];
  char module[255];
  int severity;
  static int minseverity = -1;
  if (minseverity == -1)
    {
      char *s;
      // @env LINTSEVERITY - minumum severity for a LINT warning to be issued...
      s = acl_getenv ("LINTSEVERITY");
      minseverity = 1;
      if (s)
	{
	  if (strlen (s))
	    {
	      minseverity = atoi (s);
	    }
	}

    }

  severity = get_severity (code);

  if (severity < minseverity)
    {
      return;
    }

  if (has_lint_ignore (code) || has_lint_expect (code))
    {
      return;
    }


  if (module_in == 0)
    {
      A4GL_pause_execution ();
      printf ("WARNING : %s does not pass in a module!\n", code);
      module_in = lint_module;
    }

  if (module_in == 0)
    {
      module_in = "unknown";
    }

  if (lintline == 0)
    {
      lintline = yylineno;
    }

  if (strchr (module_in, '/'))
    {
      module_in = A4GL_transform_basename (module_in);
    }


  strcpy (module, module_in);

  if (strcmp (module, LINTMODULE_FOR_PROGRAM) == 0)
    {				// This is our pseudo 'program' module which represents the program as whole
    }
  else
    {
      if (strstr (module, ".4gl"))
	{
	  char *ptr;
	  ptr = strstr (module, ".4gl");
	  *ptr = 0;
	}
      strcat (module, ".4gl");
    }


  if (!A4GL_isyes (acl_getenv ("SUPPRESSLINT")))
    {

      switch (get_lint_style ())
	{
	case 0:
	  sprintf (buff, "%s Line %d (Severity:%d)", module, lintline, severity);
	  if (extra)
	    {
	      fprintf (stderr, "  LINT : %-30s %-20s %s (%s)\n", buff, code, type, extra);
	    }
	  else
	    {
	      fprintf (stderr, "  LINT : %-30s %-20s %s \n", buff, code, type);
	    }
	  break;

	case 1:
	  {
	    //char fname[200];
	    //strcpy(fname,module);
	    //strcat(fname,".4gl");
	    sprintf (buff, "%-20s:%-6d (Severity:%2d)", module, lintline, severity);
	  }
	  if (extra)
	    {
	      fprintf (lintfile, "%-20s, %-20s %s (%s)\n", buff, code, type, extra);
	    }
	  else
	    {
	      fprintf (lintfile, "%-20s, %-20s %s \n", buff, code, type);
	    }
	  break;


	case 2:
	  if (extra == 0)
	    extra = " ";
	  if (lintfile)
	    {
	      fprintf (lintfile,
		       "<LINT MODULE='%s' LINE='%d' CODE='%s' SEVERITY='%d'><DESCRIPTION>%s</DESCRIPTION><DETAILS>%s</DETAILS></LINT>\n",
		       module, lintline, code, severity, local_xml_escape (type), local_xml_escape (extra));
	    }
	  break;


	case 3:
	  if (extra == 0)
	    extra = " ";
	  if (lintfile)
	    {
	      fprintf (lintfile, "%s|%d|%s|%d|%s|%s|\n", module, lintline, code, severity, type, extra);
	    }
	  break;

	default:
	  printf ("Unhandled LINT style\n");
	}

    }


}


void
open_lintfile (char *s)
{
  char *fname;
  if (get_lint_style () == 0)
    return;
  fname = get_lint_filename (s);
  lintfile = fopen (fname, "w");
  if (lintfile == 0)
    {
      printf ("Unable to open lintfile\n");
    }

  if (get_lint_style () == 2)
    {
      fprintf (lintfile, "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n");
          fprintf (lintfile, "<PROGRAM>\n");
    }

}


static void dump_function_definitions(void) {
  int b;
  int a;

  fprintf(lintfile,"<FUNCTIONS>\n");
  for (a = 0; a < this_module.module_entries.module_entries_len; a++)
    {
	switch (this_module.module_entries.module_entries_val[a]->met_type) {
		case E_MET_FUNCTION_DEFINITION:
		case E_MET_MAIN_DEFINITION:
			if (this_module.module_entries.module_entries_val[a]->module_entry_u.function_definition.funcname[0]!='!')  {
      			fprintf (lintfile, "<FUNCTION TYPE=\"FUNCTION\" NAME=\"%s\" MODULE=\"%s\" LINE=\"%d\" ENDLINE=\"%d\"/>\n", 
			this_module.module_entries.module_entries_val[a]->module_entry_u.function_definition.funcname,
			this_module.module_entries.module_entries_val[a]->module_entry_u.function_definition.module,
			this_module.module_entries.module_entries_val[a]->module_entry_u.function_definition.lineno,
			this_module.module_entries.module_entries_val[a]->module_entry_u.function_definition.lastlineno
			);
			}
			break;
		case E_MET_REPORT_DEFINITION:

			if (this_module.module_entries.module_entries_val[a]->module_entry_u.report_definition.funcname[0]!='!') {
      			fprintf (lintfile, "<FUNCTION TYPE=\"REPORT\" NAME=\"%s\" MODULE=\"%s\" LINE=\"%d\" ENDLINE=\"%d\"/>\n", 
			this_module.module_entries.module_entries_val[a]->module_entry_u.report_definition.funcname,
			this_module.module_entries.module_entries_val[a]->module_entry_u.report_definition.module,
			this_module.module_entries.module_entries_val[a]->module_entry_u.report_definition.lineno,
			this_module.module_entries.module_entries_val[a]->module_entry_u.report_definition.lastlineno
			);
			}
			break;
		case E_MET_PDF_REPORT_DEFINITION:
			if (this_module.module_entries.module_entries_val[a]->module_entry_u.pdf_report_definition.funcname[0]!='!') {
      			fprintf (lintfile, "<FUNCTION TYPE=\"REPORT\" NAME=\"%s\" MODULE=\"%s\" LINE=\"%d\" ENDLINE=\"%d\"/>\n", 
			this_module.module_entries.module_entries_val[a]->module_entry_u.pdf_report_definition.funcname,
			this_module.module_entries.module_entries_val[a]->module_entry_u.pdf_report_definition.module,
			this_module.module_entries.module_entries_val[a]->module_entry_u.pdf_report_definition.lineno,
			this_module.module_entries.module_entries_val[a]->module_entry_u.pdf_report_definition.lastlineno
				);
			}
			break;
		default: break;
    }
}
  fprintf(lintfile,"</FUNCTIONS>\n");
}

void
close_lintfile ()
{

  if (get_lint_style () == 0)
    return;

  if (get_lint_style () == 2)
    {
      	fprintf (lintfile, "</LINTS>\n");
	dump_function_definitions();
    	fprintf (lintfile, "</PROGRAM>\n");
    }
  if (lintfile)
    {
      fclose (lintfile);
    }
}


static char *
get_lint_filename (char *s)
{
  static char buff[3000];
   char *fname;
   fname=acl_getenv_not_set_as_0("A4GL_LINTFILE");
   if (fname) {
		return fname;
   }

  if (s == 0)
    {				// no program name...
      switch (get_lint_style ())
	{
	case 1:		// Text 
	  return "lint.txt";
	case 2:		// XML
	  return "lint.xml";
	case 3:		// UNL
	  return "lint.unl";
	default:
	  printf ("Unhandled lint style\n");
	  return "lint.txt";
	}
    }

// No name specified
  switch (get_lint_style ())
    {
    case 1:			// Text 
      sprintf (buff, "%s.txt", s);
      return buff;
    case 2:			// XML
      sprintf (buff, "%s.xml", s);
      return buff;
    case 3:			// UNL
      sprintf (buff, "%s.unl", s);
      return buff;
    default:
      printf ("Unhandled lint style\n");
      return "lint.txt";
    }
}



int
get_lint_style (void)
{
  static int lintoutputstyle = -1;
  if (lintoutputstyle == -1)
    {
      lintoutputstyle = 0;

      if (A4GL_aubit_strcasecmp(acl_getenv ("A4GL_LINTSTYLE"),"TXT")==0)
	{
	  lintoutputstyle = 1;
	  return lintoutputstyle;
	}

      if (A4GL_aubit_strcasecmp(acl_getenv ("A4GL_LINTSTYLE"),"XML")==0)
	{
	  lintoutputstyle = 2;
	  return lintoutputstyle;
	}

      if (A4GL_aubit_strcasecmp(acl_getenv ("A4GL_LINTSTYLE"),"UNL")==0)
	{
	  lintoutputstyle = 3;
	  return lintoutputstyle;
	}
    }
  return lintoutputstyle;
}



static char *
local_xml_escape (char *s)
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
      if (s[a] == '>')
	{
	  buff[b++] = '&';
	  buff[b++] = 'g';
	  buff[b++] = 't';
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
//printf("ESCAPE (%s)=%s\n",s,buff);
  return buff;
}

static char *
A4GL_transform_basename (char *s)
{
  static char buff[256];
  if (strrchr (s, '/') == 0)
    return s;
  else
    {

      //sprintf (buff, "F%s", strrchr (s, '/') + 1);
      sprintf (buff, "%s", strrchr (s, '/') + 1);

      return buff;
      return strrchr (s, '/') + 1;
    }

  return s;
}


void
dump_prototypes (void)
{
  int b;
  int a;

  for (a = 0; a < this_module.module_entries.module_entries_len; a++)
    {
      printf ("FUNCTION %s ", fprototypes[a].pname);
      printf ("PARAMETERS  (");
      for (b = 0; b < fprototypes[a].nparams; b++)
	{
	  if (b)
	    printf (",");
	  printf ("%d", fprototypes[a].param_dtypes[b]);
	}
      printf (") RETURNS (");
      for (b = 0; b < fprototypes[a].nreturns; b++)
	{
	  if (b)
	    printf (",");
	  printf ("%d", fprototypes[a].return_dtypes[b]);
	}
      printf (")\n");
    }
}


int
is_bolton_function (char *s)
{
  int a;
  for (a = 0; a < nboltons; a++)
    {
      if (A4GL_aubit_strcasecmp (s, fboltons[a].pname) == 0)
	{
	  return a;
	}
    }
  return -1;
}


/*
int is_bolton_function_ret(char *s,int r) {
	if (A4GL_aubit_strcasecmp(s,"push_server_call_arg")==0) {
		if (r==0) {
			return 0;
		}
	}
}
*/


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

  fboltons = realloc (fboltons, sizeof (fboltons[0]) * nboltons);

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

  fboltons[nboltons - 1].pname = strdup (fname);
  fboltons[nboltons - 1].proto_type = 0;
  fboltons[nboltons - 1].nparams = pcnt;
  if (pcnt)
    {
      fboltons[nboltons - 1].param_dtypes = malloc (sizeof (int) * pcnt);
      for (a = 0; a < pcnt; a++)
	{
	  fboltons[nboltons - 1].param_dtypes[a] = atoi (p_params[a]);
	}
    }
  else
    {
      fboltons[nboltons - 1].param_dtypes = 0;
    }


  fboltons[nboltons - 1].nreturns = rcnt;
  if (rcnt)
    {
      fboltons[nboltons - 1].return_dtypes = malloc (sizeof (int) * rcnt);
      for (a = 0; a < rcnt; a++)
	{
	  fboltons[nboltons - 1].return_dtypes[a] = atoi (p_rets[a]);
	}
    }
  else
    {
      fboltons[nboltons - 1].return_dtypes = 0;
    }

/*
	int nparams;
	int *param_dtypes;
	int nreturns;
	int *return_dtypes;
};
*/
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

/*
struct s_function_prototype {
	char *pname;
	int nparams;
	int *param_dtypes;
	int nreturns;
	int *return_dtypes;
};
*/



// EXPRESSION HANDLING....
// 
// To make life easier for our lint checker its a good idea to get all our functions expressions in one place
// we can do that by moving them all to the functions 'expressions_list' - we should probably be doing something
// like this at compile time - but this is the next best thing...
// So - we need to go through all the commands that use an expression and pull out that expression data
// the - we need to go through those expressions and pull out any that are used in those expressions...
// we should end up with a list of expressions at the top - which only reference cached expressions or literals


static void
linearise_expressions (struct expr_str_list *list)
{
  int b;
  if (list == 0)
    return;

  if (list->list.list_len == 0)
    return;

  for (b = 0; b < list->list.list_len; b++)
    {
      if (list->list.list_val[b] == 0)
	continue;
      if (list->list.list_val[b]->expr_type == ET_EXPR_CACHED)
	continue;

      switch (list->list.list_val[b]->expr_type)
	{
	  // We're looking here for any compound expressions (ie - expressions containing another expression)

	case ET_EXPR_EXTEND:
	  {
	    struct s_expr_extend *expr_extend;
	    expr_extend = list->list.list_val[b]->expr_str_u.expr_extend;
	    cache_expression (list, &expr_extend->expr);
	  }
	  break;


	case ET_EXPR_EXPR_LIST:
	case ET_EXPR_CONCAT_LIST:
	  {
	    struct expr_str_list *expr_list;
	    expr_list = list->list.list_val[b]->expr_str_u.expr_list;
	    cache_expression_list (list, expr_list);
	  }
	  break;

	case ET_EXPR_FCALL:
	  {
	    struct s_expr_function_call *expr_function_call;
	    expr_function_call = list->list.list_val[b]->expr_str_u.expr_function_call;
	    cache_expression_list (list, expr_function_call->parameters);
	  }
	  break;

	case ET_EXPR_PDF_FCALL:
	  {
	    struct s_expr_pdf_function_call *expr_pdf_function_call;
	    expr_pdf_function_call = list->list.list_val[b]->expr_str_u.expr_pdf_function_call;
	    cache_expression_list (list, expr_pdf_function_call->parameters);
	  }
	  break;

	case ET_EXPR_SHARED_FCALL:
	  {
	    struct s_expr_shared_function_call *expr_shared_function_call;
	    expr_shared_function_call = list->list.list_val[b]->expr_str_u.expr_shared_function_call;
	    cache_expression_list (list, expr_shared_function_call->parameters);
	  }
	  break;

	case ET_EXPR_MEMBER_FCALL:
	  {
	    struct s_expr_member_function_call *expr_member_function_call;
	    expr_member_function_call = list->list.list_val[b]->expr_str_u.expr_member_function_call;
	    cache_expression_list (list, expr_member_function_call->parameters);
	  }
	  break;

	case ET_EXPR_EXTERNAL:
	  {
	    struct s_expr_external_call *expr_external_call;
	    expr_external_call = list->list.list_val[b]->expr_str_u.expr_external_call;
	    cache_expression_list (list, expr_external_call->parameters);
	  }
	  break;

	case ET_EXPR_OP_ADD:
	case ET_EXPR_OP_AND:
	case ET_EXPR_OP_CONCAT:
	case ET_EXPR_OP_DIV:
	case ET_EXPR_OP_EQUAL:
	case ET_EXPR_OP_GREATER_THAN:
	case ET_EXPR_OP_GREATER_THAN_EQ:
	case ET_EXPR_OP_LESS_THAN:
	case ET_EXPR_OP_LESS_THAN_EQ:
	case ET_EXPR_OP_LIKE:
	case ET_EXPR_OP_MATCHES:
	case ET_EXPR_OP_MOD:
	case ET_EXPR_OP_MULT:
	case ET_EXPR_OP_NOT_EQUAL:
	case ET_EXPR_OP_NOT_LIKE:
	case ET_EXPR_OP_NOT_MATCHES:
	case ET_EXPR_OP_OR:
	case ET_EXPR_OP_POWER:
	case ET_EXPR_OP_SUB:
	case ET_EXPR_OP_USING:
	  {
	    struct s_expr_op *expr_op;
	    expr_op = list->list.list_val[b]->expr_str_u.expr_op;

	    cache_expression (list, &expr_op->left);
	    cache_expression (list, &expr_op->right);
	    cache_expression (list, &expr_op->escape);
	  }
	  break;


	case ET_EXPR_WORDWRAP:
	  {
	    struct s_expr_wordwrap *expr_wordwrap;
	    expr_wordwrap = list->list.list_val[b]->expr_str_u.expr_wordwrap;
	    cache_expression (list, &expr_wordwrap->expr);
	  }
	  break;


	case ET_EXPR_BRACKET:
	  {
	    cache_expression (list, &list->list.list_val[b]->expr_str_u.expr_expr);
	  }
	  break;

	case ET_EXPR_OP_IN:
	case ET_EXPR_OP_NOT_IN:
	  {
	    struct s_expr_in *expr_in;
	    expr_in = list->list.list_val[b]->expr_str_u.expr_in;
	    cache_expression (list, &expr_in->expr);
	    cache_expression_list (list, expr_in->elist);
	  }
	  break;


	case ET_EXPR_OP_IN_SUBQUERY:
	case ET_EXPR_OP_NOTIN_SUBQUERY:
	  {
	    struct s_expr_in_sq *expr_in_sq;
	    expr_in_sq = list->list.list_val[b]->expr_str_u.expr_in_sq;
	    cache_expression (list, &expr_in_sq->expr);
	  }
	  break;


	case ET_EXPR_CAST:
	  {
	    struct s_expr_cast *expr_cast;
	    expr_cast = list->list.list_val[b]->expr_str_u.expr_cast;
	    cache_expression (list, &expr_cast->expr);
	  }
	  break;


	case ET_EXPR_TIME_FUNC:
	case ET_EXPR_MONTH_FUNC:
	case ET_EXPR_DAY_FUNC:
	case ET_EXPR_YEAR_FUNC:
	case ET_EXPR_UPSHIFT:
	case ET_EXPR_DOWNSHIFT:
	case ET_EXPR_ASCII:
	case ET_EXPR_POINTS:
	case ET_EXPR_MM:
	case ET_EXPR_INCHES:
	case ET_EXPR_DATE_FUNC:
	case ET_EXPR_COLUMN:
	case ET_EXPR_OP_SPACES:
	case ET_EXPR_OP_ISNULL:
	case ET_EXPR_OP_ISNOTNULL:
	case ET_EXPR_NOT:
	case ET_EXPR_OP_CLIP:
	case ET_EXPR_OP_YEAR:
	case ET_EXPR_OP_MONTH:
	case ET_EXPR_OP_DAY:
	case ET_EXPR_OP_HOUR:
	case ET_EXPR_OP_MINUTE:
	case ET_EXPR_OP_SECOND:
	case ET_EXPR_NEG:
	  {
	    struct expr_str *expr_expr;
	    expr_expr = list->list.list_val[b]->expr_str_u.expr_expr;
	    cache_expression (list, &expr_expr);
	  }
	  break;



	case ET_EXPR_GET_FLDBUF:
	  {
	    struct s_expr_get_fldbuf *expr_get_fldbuf;
	    expr_get_fldbuf = list->list.list_val[b]->expr_str_u.expr_get_fldbuf;
	    //@ FIXME
	  }
	  break;

	case ET_EXPR_INFIELD:
	  {
	    struct s_expr_infield *expr_infield;
	    expr_infield = list->list.list_val[b]->expr_str_u.expr_infield;
	    //@ FIXME
	  }
	  break;
	case ET_EXPR_FIELD_TOUCHED:
	case ET_EXPR_NOT_FIELD_TOUCHED:
	  {
	    struct s_expr_field_touched *expr_field_touched;
	    expr_field_touched = list->list.list_val[b]->expr_str_u.expr_field_touched;
	    //@ FIXME
	  }
	  break;


	case ET_EXPR_ID_TO_INT:
	case ET_EXPR_FIELDTOWIDGET:
	  {
	    struct fh_field_entry *expr_field_entry;
	    expr_field_entry = list->list.list_val[b]->expr_str_u.expr_field_entry;
	    //@ FIXME
	  }
	  break;







	default:
	  break;

	}

    }

}


static int
add_cache_expression (struct expr_str_list *list, expr_str * e)
{
  int a;
  if (list->list.list_len)
    {
      for (a = 0; a < list->list.list_len; a++)
	{
	  if (list->list.list_val[a] == e)
	    return a;
	}
    }

  list->list.list_len++;
  list->list.list_val = realloc (list->list.list_val, sizeof (expr_str *) * list->list.list_len);
  list->list.list_val[list->list.list_len - 1] = e;	//malloc(sizeof(expr_str));

  //memcpy(list->list.list_val[list->list.list_len - 1], e,sizeof(expr_str));

  return list->list.list_len - 1;
}

static void
cache_expression (struct expr_str_list *list, struct expr_str **eptr)
{
  struct expr_str *e;
  struct expr_str *enew;
  e = *eptr;
  if (e == 0)
    return;
  if (e->expr_type == ET_EXPR_CACHED)
    return;
  enew = malloc (sizeof (struct expr_str));
  enew->expr_type = ET_EXPR_CACHED;
  enew->expr_str_u.expr_cached.cache_num = add_cache_expression (list, e);
  if (enew->expr_str_u.expr_cached.cache_num == list->list.list_len - 1)
    {				// Its new 
      enew->expr_str_u.expr_cached.ref_cnt = 0;
    }
  else
    {
      enew->expr_str_u.expr_cached.ref_cnt++;
    }
  *eptr = enew;
}

static void
cache_expression_list (struct expr_str_list *list, struct expr_str_list *srclist)
{
  int a;
  if (srclist == 0)
    return;
  if (srclist->list.list_len == 0)
    return;

  for (a = 0; a < srclist->list.list_len; a++)
    {
      cache_expression (list, &srclist->list.list_val[a]);
    }
}



static void
cache_expressions (struct expr_str_list *list, struct commands *cmds)
{
  int a;
  int b;
  struct struct_display_cmd *disp;
  list->list.list_len = 0;
  list->list.list_val = 0;
  return;

  for (a = 0; a < cmds->cmds.cmds_len; a++)
    {
      struct command *c;
      c = cmds->cmds.cmds_val[a];


      switch (c->cmd_data.type)
	{
	case E_CMD_DISPLAY_CMD:
	  disp = &c->cmd_data.command_data_u.display_cmd;
	  cache_expression_list (list, disp->exprs);
	  if (disp->where->dttype == DT_DISPLAY_TYPE_AT)
	    {
	      cache_expression (list, &disp->where->dt_display_u.x_y.x);
	      cache_expression (list, &disp->where->dt_display_u.x_y.y);
	    }
	  break;


	case E_CMD_ERROR_CMD:
	  cache_expression_list (list, c->cmd_data.command_data_u.error_cmd.expr_list);
	  break;

	case E_CMD_SLEEP_CMD:
	  cache_expression (list, &c->cmd_data.command_data_u.sleep_cmd.sleep_expr);
	  break;

	case E_CMD_MOVE_CMD:
	  cache_expression (list, &c->cmd_data.command_data_u.move_cmd.x);
	  cache_expression (list, &c->cmd_data.command_data_u.move_cmd.y);
	  break;

	case E_CMD_SHOW_MENU_CMD:
	  cache_expression (list, &c->cmd_data.command_data_u.show_menu_cmd.mn_file);
	  break;

	case E_CMD_RUN_CMD:
	  cache_expression (list, &c->cmd_data.command_data_u.run_cmd.run_string);
	  break;

	case E_CMD_RUN_WAITING_FOR_CMD:
	  cache_expression (list, &c->cmd_data.command_data_u.run_waiting_for_cmd.run_string);
	  cache_expression (list, &c->cmd_data.command_data_u.run_waiting_for_cmd.sleep);
	  cache_expression (list, &c->cmd_data.command_data_u.run_waiting_for_cmd.msg_repeat_every);
	  cache_expression (list, &c->cmd_data.command_data_u.run_waiting_for_cmd.msg_text);
	  break;

	case E_CMD_SCROLL_CMD:
	  cache_expression (list, &c->cmd_data.command_data_u.scroll_cmd.val);
	  break;

	case E_CMD_EXIT_PROG_CMD:
	  cache_expression (list, &c->cmd_data.command_data_u.exit_prog_cmd.exit_val);
	  break;

	case E_CMD_RETURN_CMD:
	  cache_expression_list (list, c->cmd_data.command_data_u.return_cmd.retvals);
	  break;

	case E_CMD_MESSAGE_CMD:
	  cache_expression_list (list, c->cmd_data.command_data_u.message_cmd.message_expr);
	  break;

	case E_CMD_FOR_CMD:
	  cache_expression (list, &c->cmd_data.command_data_u.for_cmd.start);
	  cache_expression (list, &c->cmd_data.command_data_u.for_cmd.end);
	  cache_expression (list, &c->cmd_data.command_data_u.for_cmd.step);
	  break;

	case E_CMD_CALL_CMD:
	  cache_expression (list, &c->cmd_data.command_data_u.call_cmd.fcall);
	  break;

	case E_CMD_PDF_CALL_CMD:
	  cache_expression (list, &c->cmd_data.command_data_u.pdf_call_cmd.fcall);
	  break;

	case E_CMD_LET_CMD:
	  cache_expression_list (list, c->cmd_data.command_data_u.let_cmd.vals);
	  break;

	case E_CMD_IF_CMD:
	  {
	    struct struct_if_cmd *ifcmd;
	    ifcmd = &c->cmd_data.command_data_u.if_cmd;
	    for (b = 0; b < ifcmd->truths.conditions.conditions_len; b++)
	      {
		ensure_bool (c->module, ifcmd->truths.conditions.conditions_val[b].lineno,
			     ifcmd->truths.conditions.conditions_val[b].test_expr, 0);
		cache_expression (list, &ifcmd->truths.conditions.conditions_val[b].test_expr);
	      }
	  }
	  break;

	case E_CMD_CASE_CMD:
	  {
	    struct struct_case_cmd *casecmd;
	    casecmd = &c->cmd_data.command_data_u.case_cmd;
	    cache_expression (list, &casecmd->case_expr);

	    for (b = 0; b < casecmd->whens->whens.whens_len; b++)
	      {
		cache_expression (list, &casecmd->whens->whens.whens_val[b]->when_expr);
	      }
	  }
	  break;


	case E_CMD_OPEN_WINDOW_CMD:
	  cache_expression (list, &c->cmd_data.command_data_u.open_window_cmd.x);
	  cache_expression (list, &c->cmd_data.command_data_u.open_window_cmd.y);
	  if (c->cmd_data.command_data_u.open_window_cmd.wt.wintype == EWT_FORM)
	    {
	      cache_expression (list, &c->cmd_data.command_data_u.open_window_cmd.wt.windowtype_u.formfilename);
	    }
	  break;

	case E_CMD_FETCH_CMD:
	  if (c->cmd_data.command_data_u.fetch_cmd.fetch)
	    {
	      if (c->cmd_data.command_data_u.fetch_cmd.fetch->fp)
		{
		  cache_expression (list, &c->cmd_data.command_data_u.fetch_cmd.fetch->fp->fetch_expr);
		}
	    }
	  break;

	case E_CMD_OPEN_FORM_CMD:
	  cache_expression (list, &c->cmd_data.command_data_u.open_form_cmd.form_filename);
	  break;

	case E_CMD_WHILE_CMD:
	  cache_expression (list, &c->cmd_data.command_data_u.while_cmd.while_expr);
	  break;

	case E_CMD_OUTPUT_CMD:
	  cache_expression_list (list, c->cmd_data.command_data_u.output_cmd.expressions);
	  break;

	case E_CMD_SET_DATABASE_CMD:
	  cache_expression (list, &c->cmd_data.command_data_u.set_database_cmd.set_dbname);
	  break;

	case E_CMD_NEED_CMD:
	  cache_expression (list, &c->cmd_data.command_data_u.need_cmd.expr);
	  break;

	case E_CMD_PRINT_CMD:
	  cache_expression_list (list, c->cmd_data.command_data_u.print_cmd.print_expr);
	  break;

	case E_CMD_PRINT_IMG_CMD:
	  cache_expression (list, &c->cmd_data.command_data_u.print_img_cmd.scale_x);
	  cache_expression (list, &c->cmd_data.command_data_u.print_img_cmd.scale_y);
	  break;

	  /*
	     case E_CMD_PAUSE_CMD: 
	     cache_expression(list, &c->cmd_data.command_data_u.pause_cmd.prompt_str);
	     break;
	   */

	default:
	  break;
	}

    }
  linearise_expressions (list);
}



void
gen_function_prototypes (int e, struct s_function_definition *function_definition)
{
  struct commands *func_cmds;
  int nreturns;
  int a;
  struct command *r;
  int *dtypes = 0;
  func_cmds = linearise_commands (0, 0);

  linearise_commands (func_cmds, function_definition->func_commands);

  nreturns = 0;
  for (a = 0; a < func_cmds->cmds.cmds_len; a++)
    {
      r = func_cmds->cmds.cmds_val[a];

      if (r->cmd_data.type == E_CMD_LINT_EXPECT_CMD)
	{
	  set_lint_expect (r);
	  continue;
	}
      if (r->cmd_data.type == E_CMD_LINT_IGNORE_CMD)
	{
	  set_lint_ignore (r);
	  continue;
	}

      if (r->cmd_data.type == E_CMD_RETURN_CMD)
	{

	  if (r->cmd_data.command_data_u.return_cmd.retvals)
	    {
	      int b;
	      nreturns = r->cmd_data.command_data_u.return_cmd.retvals->list.list_len;

	      fprototypes[e].nreturns = nreturns;
	      if (nreturns)
		{
		  fprototypes[e].return_dtypes = malloc (sizeof (long) * fprototypes[e].nreturns);
		  dtypes = realloc (dtypes, sizeof (int) * nreturns);
		}
	      else
		{
		  fprototypes[e].return_dtypes = 0;
		}

	      for (b = 0; b < nreturns; b++)
		{
		  dtypes[b] = expr_datatype (r->module, r->lineno, r->cmd_data.command_data_u.return_cmd.retvals->list.list_val[b]);
		  if (dtypes[b] == 90)
		    {		// always return a int instead..
		      dtypes[b] = DTYPE_INT;
		    }
		  fprototypes[e].return_dtypes[b] = dtypes[b];
		}

	    }

	  break;
	}
      clr_lint_expect ();
    }
  if (fprototypes[e].nreturns == -1)
    {
      fprototypes[e].nreturns = 0;
    }

  fprototypes[e].module=r->module;
  fprototypes[e].lineno=r->lineno;
}


void
create_protos_from_module (module_definition * this_module)
{
  int a;
  int process;
  printf ("CREATE\n");
  fprototypes = malloc (sizeof (struct s_function_prototype) * this_module->module_entries.module_entries_len);
  for (a = 0; a < this_module->module_entries.module_entries_len; a++)
    {
      fprototypes[a].proto_type = 0;
      fprototypes[a].pname = 0;
      fprototypes[a].nparams = -1;
      fprototypes[a].nreturns = -1;
      fprototypes[a].param_dtypes = 0;
      fprototypes[a].return_dtypes = 0;
      process = 0;
      switch (this_module->module_entries.module_entries_val[a]->met_type)
	{
	case E_MET_FUNCTION_DEFINITION:
	case E_MET_MAIN_DEFINITION:
	case E_MET_REPORT_DEFINITION:
	case E_MET_PDF_REPORT_DEFINITION:
	  process = 1;
	  break;
	default:
	  break;

	}



      if (process)
	{
	  gen_function_prototypes (a, &this_module->module_entries.module_entries_val[a]->module_entry_u.function_definition);
	}
    }

}

void
log_proto (struct expr_str *fcall, struct expr_str_list *ret)
{
  int a;
  if (A4GL_isyes (acl_getenv ("LOGPROTOS")))
    {
      struct expr_str_list *l;
      FILE *f;
      f = fopen ("protos.out", "a");
      fprintf (f, "%s|", fcall->expr_str_u.expr_function_call->fname);
      l = A4GL_rationalize_list (fcall->expr_str_u.expr_function_call->parameters);
      for (a = 0; a < l->list.list_len; a++)
	{
	  if (a)
	    fprintf (f, ",");
	  fprintf (f, "%d", expr_datatype (0, 0, l->list.list_val[a]) & DTYPE_MASK);
	}
      fprintf (f, "|");
      if (ret != 0)
	{
	  for (a = 0; a < ret->list.list_len; a++)
	    {
	      if (a)
		fprintf (f, ",");
	      fprintf (f, "%d", expr_datatype (0, 0, ret->list.list_val[a]) & DTYPE_MASK);
	    }
	}
      fprintf (f, "\n");
    }
}



char *
decode_cmd_type (enum cmd_type value)
{
  switch (value)
    {
    case E_CMD_ALLOC_ARR_CMD:
      return "E_CMD_ALLOC_ARR_CMD";
    case E_CMD_AT_TERM_CMD:
      return "E_CMD_AT_TERM_CMD";
    case E_CMD_CALL_CMD:
      return "E_CMD_CALL_CMD";
    case E_CMD_CANCEL_CMD:
      return "E_CMD_CANCEL_CMD";
    case E_CMD_CASE_CMD:
      return "E_CMD_CASE_CMD";
    case E_CMD_CHECK_MENU_CMD:
      return "E_CMD_CHECK_MENU_CMD";
    case E_CMD_CLEAR_CMD:
      return "E_CMD_CLEAR_CMD";
    case E_CMD_CLOSE_CMD:
      return "E_CMD_CLOSE_CMD";
    case E_CMD_CLOSE_SQL_CMD:
      return "E_CMD_CLOSE_SQL_CMD";
    case E_CMD_CODE_CMD:
      return "E_CMD_CODE_CMD";
    case E_CMD_CONNECT_CMD:
      return "E_CMD_CONNECT_CMD";
    case E_CMD_CONSTRUCT_CMD:
      return "E_CMD_CONSTRUCT_CMD";
    case E_CMD_CONTINUE_CMD:
      return "E_CMD_CONTINUE_CMD";
    case E_CMD_CONVERT_CMD:
      return "E_CMD_CONVERT_CMD";
    case E_CMD_CURRENT_WIN_CMD:
      return "E_CMD_CURRENT_WIN_CMD";
    case E_CMD_DEALLOC_ARR_CMD:
      return "E_CMD_DEALLOC_ARR_CMD";
    case E_CMD_DECLARE_CMD:
      return "E_CMD_DECLARE_CMD";
    case E_CMD_DEFER_CMD:
      return "E_CMD_DEFER_CMD";
    case E_CMD_DISABLE_MENU_CMD:
      return "E_CMD_DISABLE_MENU_CMD";
    case E_CMD_DISPLAY_ARRAY_CMD:
      return "E_CMD_DISPLAY_ARRAY_CMD";
    case E_CMD_DISPLAY_B_N_CMD:
      return "E_CMD_DISPLAY_B_N_CMD";
    case E_CMD_DISPLAY_CMD:
      return "E_CMD_DISPLAY_CMD";
    case E_CMD_DISPLAY_FORM_CMD:
      return "E_CMD_DISPLAY_FORM_CMD";
    case E_CMD_ENABLE_MENU_CMD:
      return "E_CMD_ENABLE_MENU_CMD";
    case E_CMD_ERROR_CMD:
      return "E_CMD_ERROR_CMD";
    case E_CMD_EXECUTE_CMD:
      return "E_CMD_EXECUTE_CMD";
    case E_CMD_EXECUTE_IMMEDIATE_CMD:
      return "E_CMD_EXECUTE_IMMEDIATE_CMD";
    case E_CMD_EXIT_PROG_CMD:
      return "E_CMD_EXIT_PROG_CMD";
    case E_CMD_EXT_CMD:
      return "E_CMD_EXT_CMD";
    case E_CMD_FINISH_CMD:
      return "E_CMD_FINISH_CMD";
    case E_CMD_FLUSH_CMD:
      return "E_CMD_FLUSH_CMD";
    case E_CMD_FOREACH_CMD:
      return "E_CMD_FOREACH_CMD";
    case E_CMD_FOR_CMD:
      return "E_CMD_FOR_CMD";
    case E_CMD_FREE_CMD:
      return "E_CMD_FREE_CMD";
    case E_CMD_FREE_REP_CMD:
      return "E_CMD_FREE_REP_CMD";
    case E_CMD_GOTO_CMD:
      return "E_CMD_GOTO_CMD";
    case E_CMD_HIDE_CMD:
      return "E_CMD_HIDE_CMD";
    case E_CMD_HIDE_OPTION_CMD:
      return "E_CMD_HIDE_OPTION_CMD";
    case E_CMD_IF_CMD:
      return "E_CMD_IF_CMD";
    case E_CMD_INIT_CMD:
      return "E_CMD_INIT_CMD";
    case E_CMD_INPUT_ARRAY_CMD:
      return "E_CMD_INPUT_ARRAY_CMD";
    case E_CMD_INPUT_CMD:
      return "E_CMD_INPUT_CMD";
    case E_CMD_LABEL_CMD:
      return "E_CMD_LABEL_CMD";
    case E_CMD_LET_CMD:
      return "E_CMD_LET_CMD";
    case E_CMD_LOAD_CMD:
      return "E_CMD_LOAD_CMD";
    case E_CMD_LOCATE_CMD:
      return "E_CMD_LOCATE_CMD";
    case E_CMD_MENU_CMD:
      return "E_CMD_MENU_CMD";
    case E_CMD_MESSAGE_CMD:
      return "E_CMD_MESSAGE_CMD";
    case E_CMD_MOVE_CMD:
      return "E_CMD_MOVE_CMD";
    case E_CMD_MSG_BOX_CMD:
      return "E_CMD_MSG_BOX_CMD";
    case E_CMD_NEED_CMD:
      return "E_CMD_NEED_CMD";
    case E_CMD_NEXT_FIELD_CMD:
      return "E_CMD_NEXT_FIELD_CMD";
    case E_CMD_NEXT_FORM_CMD:
      return "E_CMD_NEXT_FORM_CMD";
    case E_CMD_NEXT_OPTION_CMD:
      return "E_CMD_NEXT_OPTION_CMD";
    case E_CMD_OPEN_CURSOR_CMD:
      return "E_CMD_OPEN_CURSOR_CMD";
    case E_CMD_OPEN_FORM_CMD:
      return "E_CMD_OPEN_FORM_CMD";
    case E_CMD_OPEN_FORM_GUI_CMD:
      return "E_CMD_OPEN_FORM_GUI_CMD";
    case E_CMD_OPEN_STATUSBOX_CMD:
      return "E_CMD_OPEN_STATUSBOX_CMD";
    case E_CMD_OPEN_WINDOW_CMD:
      return "E_CMD_OPEN_WINDOW_CMD";
    case E_CMD_OPTIONS_CMD:
      return "E_CMD_OPTIONS_CMD";
    case E_CMD_OUTPUT_CMD:
      return "E_CMD_OUTPUT_CMD";
    case E_CMD_PAUSE_CMD:
      return "E_CMD_PAUSE_CMD";
    case E_CMD_PAUSE_SCREEN_OFF_CMD:
      return "E_CMD_PAUSE_SCREEN_OFF_CMD";
    case E_CMD_PAUSE_SCREEN_ON_CMD:
      return "E_CMD_PAUSE_SCREEN_ON_CMD";
    case E_CMD_PREPARE_CMD:
      return "E_CMD_PREPARE_CMD";
    case E_CMD_PRINT_CMD:
      return "E_CMD_PRINT_CMD";
    case E_CMD_PRINT_FILE_CMD:
      return "E_CMD_PRINT_FILE_CMD";
    case E_CMD_PRINT_IMG_CMD:
      return "E_CMD_PRINT_IMG_CMD";
    case E_CMD_PROMPT_CMD:
      return "E_CMD_PROMPT_CMD";
    case E_CMD_PUT_CMD:
      return "E_CMD_PUT_CMD";
    case E_CMD_RESIZE_ARR_CMD:
      return "E_CMD_RESIZE_ARR_CMD";
    case E_CMD_RETURN_CMD:
      return "E_CMD_RETURN_CMD";
    case E_CMD_RUN_CMD:
      return "E_CMD_RUN_CMD";
    case E_CMD_RUN_WAITING_FOR_CMD:
      return "E_CMD_RUN_WAITING_FOR_CMD";
    case E_CMD_SCROLL_CMD:
      return "E_CMD_SCROLL_CMD";
    case E_CMD_SET_DATABASE_CMD:
      return "E_CMD_SET_DATABASE_CMD";
    case E_CMD_SHOW_CMD:
      return "E_CMD_SHOW_CMD";
    case E_CMD_SHOW_OPTION_CMD:
      return "E_CMD_SHOW_OPTION_CMD";
    case E_CMD_SKIP_BY_CMD:
      return "E_CMD_SKIP_BY_CMD";
    case E_CMD_SKIP_CMD:
      return "E_CMD_SKIP_CMD";
    case E_CMD_SKIP_TO_CMD:
      return "E_CMD_SKIP_TO_CMD";
    case E_CMD_SKIP_TO_TOP_CMD:
      return "E_CMD_SKIP_TO_TOP_CMD";
    case E_CMD_SLEEP_CMD:
      return "E_CMD_SLEEP_CMD";
    case E_CMD_SELECT_CMD:
      return "E_CMD_SELECT_CMD";
    case E_CMD_SQL_BLOCK_CMD:
      return "E_CMD_SQL_BLOCK_CMD";
    case E_CMD_SQL_CMD:
      return "E_CMD_SQL_CMD";
    case E_CMD_SQL_TRANSACT_CMD:
      return "E_CMD_SQL_TRANSACT_CMD";
    case E_CMD_START_CMD:
      return "E_CMD_START_CMD";
    case E_CMD_START_RPC_CMD:
      return "E_CMD_START_RPC_CMD";
    case E_CMD_STOP_RPC_CMD:
      return "E_CMD_STOP_RPC_CMD";
    case E_CMD_TERM_REP_CMD:
      return "E_CMD_TERM_REP_CMD";
    case E_CMD_UNCHECK_MENU_CMD:
      return "E_CMD_UNCHECK_MENU_CMD";
    case E_CMD_UNLOAD_CMD:
      return "E_CMD_UNLOAD_CMD";
    case E_CMD_VALIDATE_CMD:
      return "E_CMD_VALIDATE_CMD";
    case E_CMD_WHENEVER_CMD:
      return "E_CMD_WHENEVER_CMD";
    case E_CMD_SHOW_MENU_CMD:
      return "E_CMD_SHOW_MENU_CMD";
    case E_CMD_WHILE_CMD:
      return "E_CMD_WHILE_CMD";
    case E_CMD_ENABLE_CMD:
      return "E_CMD_ENABLE_CMD";
    case E_CMD_ENABLE_FORM_CMD:
      return "E_CMD_ENABLE_FORM_CMD";
    case E_CMD_DISABLE_CMD:
      return "E_CMD_DISABLE_CMD";
    case E_CMD_DISABLE_FORM_CMD:
      return "E_CMD_DISABLE_FORM_CMD";
    case E_CMD_FETCH_CMD:
      return "E_CMD_FETCH_CMD";
    case E_CMD_PDF_CALL_CMD:
      return "E_CMD_PDF_CALL_CMD";
    case E_CMD_SET_SESSION_CMD:
      return "E_CMD_SET_SESSION_CMD";
    case E_CMD_UPDATE_CMD:
      return "E_CMD_UPDATE_CMD";
    case E_CMD_INSERT_CMD:
      return "E_CMD_INSERT_CMD";
    case E_CMD_DELETE_CMD:
      return "E_CMD_DELETE_CMD";
    case E_CMD_LAST:
      return "E_CMD_LAST";
    default:
      return "Unhandled";
    }				/* end of switch */
}



void
check_boolean (char *module_name, int lineno, expr_str * s, int last_was_sql, int done_true_false)
{
  struct expr_str s2;
  struct expr_str *s3;
  int a;
  struct expr_str_list list;
  list.list.list_len = 0;
  list.list.list_val = 0;

  s3 = &s2;
  memcpy (&s2, s, sizeof (s2));
  cache_expression (&list, &s3);
  linearise_expressions (&list);

  for (a = 0; a < list.list.list_len; a++)
    {
      struct expr_str *e;
      e = list.list.list_val[a];

      //printf ("check boolean : %d . %s (%d)\n", a, expr_name (list.list.list_val[a]->expr_type), list.list.list_val[a]->expr_type);
      if (e->expr_type == ET_EXPR_OP_EQUAL)
	{
	  expr_str *l_e;
	  expr_str *r_e;
	  char *ptr_l = NULL;
	  char *ptr_r = NULL;
	  l_e = e->expr_str_u.expr_op->left;
	  r_e = e->expr_str_u.expr_op->right;

	  if (l_e->expr_type == ET_EXPR_CACHED)
	    {
	      l_e = list.list.list_val[l_e->expr_str_u.expr_cached.cache_num];
	    }
	  if (r_e->expr_type == ET_EXPR_CACHED)
	    {
	      r_e = list.list.list_val[r_e->expr_str_u.expr_cached.cache_num];
	    }

	  if (l_e->expr_type == ET_EXPR_VARIABLE_USAGE)
	    {
	      ptr_l = lint_get_variable_usage_as_string (l_e->expr_str_u.expr_variable_usage);
	    }

	  if (r_e->expr_type == ET_EXPR_VARIABLE_USAGE)
	    {
	      ptr_r = lint_get_variable_usage_as_string (r_e->expr_str_u.expr_variable_usage);
	    }

	  if (ptr_l)
	    {
	      if (A4GL_is_just_int_literal (r_e, 100))
		{
		  if (l_e->expr_type == ET_EXPR_VARIABLE_USAGE)
		    {
		      if (A4GL_aubit_strcasecmp (ptr_l, "a4gl_status") == 0)
			{
			  A4GL_lint (module_name, lineno, "CHKSTATUS", "Checking 'status' for NOTFOUND", 0);
			}
		      if (A4GL_aubit_strcasecmp (ptr_l, "status") == 0)
			{
			  A4GL_lint (module_name, lineno, "CHKSTATUS", "Checking 'status' for NOTFOUND", 0);
			}
		    }

		}
	      if (strcmp (ptr_l, "sqlca.sqlcode") == 0 || strcmp (ptr_l, "a4gl_sqlca.sqlcode") == 0)
		{
		  if (!last_was_sql)
		    {
		      A4GL_lint (module_name, lineno, "IFSQLCA", "IF test on sqlca.sqlcode not following SQL statement", 0);
		    }
		}
	    }
	}
    }
  if (A4GL_is_just_literal (&list, NULL, done_true_false))
    {
      A4GL_lint (module_name, lineno, "IFCONST", "IF condition is constant", 0);
    }
}



int
A4GL_is_just_literal (struct expr_str_list *list, expr_str * ptr, int already_done_true_and_false)
{
  int a;
  expr_str str;

  struct expr_str_list listv;
  if (list == 0)
    {
      if (ptr == NULL)
	return 0;
      list = &listv;
      listv.list.list_len = 0;
      listv.list.list_val = 0;
      memcpy (&str, ptr, sizeof (str));
      ptr = &str;
      cache_expression (&listv, &ptr);
      linearise_expressions (&listv);
    }


  if (list == NULL)
    return 0;
  if (list->list.list_len == 1 && already_done_true_and_false)
    {
      if (list->list.list_val[0]->expr_type == ET_EXPR_TRUE)
	return 0;
      if (list->list.list_val[0]->expr_type == ET_EXPR_FALSE)
	return 0;
    }
  for (a = 0; a < list->list.list_len; a++)
    {
      int isliteral = 0;
      switch (list->list.list_val[a]->expr_type)
	{
	case ET_EXPR_OP_OR:
	case ET_EXPR_OP_AND:
	case ET_EXPR_BRACKET:
	case ET_EXPR_LITERAL_DOUBLE_STR:
	case ET_EXPR_LITERAL_LONG:
	case ET_EXPR_LITERAL_STRING:
	case ET_EXPR_LITERAL_EMPTY_STRING:
	case ET_EXPR_TRANSLATED_STRING:
	case ET_EXPR_QUOTED_STRING:
	case ET_EXPR_NEG:
	case ET_EXPR_NOT:
	case ET_EXPR_NULL:
	case ET_EXPR_OP_ADD:
	case ET_EXPR_CAST:
	case ET_EXPR_OP_CONCAT:
	case ET_EXPR_OP_DIV:
	case ET_EXPR_OP_EQUAL:
	case ET_EXPR_OP_GREATER_THAN:
	case ET_EXPR_OP_GREATER_THAN_EQ:
	case ET_EXPR_OP_LESS_THAN:
	case ET_EXPR_OP_LESS_THAN_EQ:
	case ET_EXPR_OP_LIKE:
	case ET_EXPR_OP_MATCHES:
	case ET_EXPR_OP_MOD:
	case ET_EXPR_OP_MULT:
	case ET_EXPR_OP_NOT_EQUAL:
	case ET_EXPR_OP_NOT_LIKE:
	case ET_EXPR_OP_NOT_MATCHES:
	case ET_EXPR_OP_POWER:
	case ET_EXPR_OP_SUB:
	case ET_EXPR_OP_USING:
	case ET_EXPR_OP_IN:
	case ET_EXPR_OP_NOT_IN:
	case ET_EXPR_OP_IN_SUBQUERY:
	case ET_EXPR_OP_NOTIN_SUBQUERY:
	case ET_EXPR_OP_SPACES:
	case ET_EXPR_OP_ISNULL:
	case ET_EXPR_OP_ISNOTNULL:
	case ET_EXPR_OP_CLIP:
	case ET_EXPR_OP_YEAR:
	case ET_EXPR_OP_MONTH:
	case ET_EXPR_OP_DAY:
	case ET_EXPR_OP_HOUR:
	case ET_EXPR_OP_MINUTE:
	case ET_EXPR_OP_SECOND:
	case ET_EXPR_CACHED:

	  isliteral = 1;
	  break;
	default:
	  break;
	}
      if (isliteral == 0)
	return 0;
    }


  return 1;
}


static char *
rettype_lint (char *s)
{
  static char rs[20] = "long";
  int a;
  A4GL_debug ("In rettype : %s", A4GL_null_as_null (s));

  a = atoi (s);

  A4GL_debug ("In rettype");
  if (A4GL_has_datatype_function_i (a, "OUTPUT"))
    {
      /* char *(*function) (); */
      char *(*function) (void);
      A4GL_debug ("In datatype");
      function = A4GL_get_datatype_function_i (a, "OUTPUT");
      A4GL_debug ("Copy");
      strcpy (rs, function ());
      A4GL_debug ("Returning %s\n", A4GL_null_as_null (rs));
      return rs;
    }
  if (strcmp (s, "0") == 0)
    strcpy (rs, "CHAR");
  if (strcmp (s, "1") == 0)
    strcpy (rs, "SMALLINT");
  if (strcmp (s, "2") == 0)
    strcpy (rs, "INTEGER");
  if (strcmp (s, "3") == 0)
    strcpy (rs, "FLOAT");
  if (strcmp (s, "4") == 0)
    strcpy (rs, "SMALLFLOAT");
  if (strcmp (s, "5") == 0)
    strcpy (rs, "DECIMAL");
  if (strcmp (s, "6") == 0)
    strcpy (rs, "INTEGER");
  if (strcmp (s, "7") == 0)
    strcpy (rs, "DATE");
  if (strcmp (s, "8") == 0)
    strcpy (rs, "MONEY");
  if (strcmp (s, "10") == 0)
    strcpy (rs, "DATETIME");
  if (strcmp (s, "11") == 0)
    strcpy (rs, "BYTE");
  if (strcmp (s, "12") == 0)
    strcpy (rs, "TEXT");
  if (strcmp (s, "13") == 0)
    strcpy (rs, "VARCHAR");
  if (strcmp (s, "14") == 0)
    strcpy (rs, "INTERVAL");
  return strdup (rs);
}

/**
 *  *  * Gets the C data type corresponding to 4gl data type
 *   *   *
 *    *    * @param s A string with the numeric 4gl data type (@see find_type())
 *     *     * @return The string (static) with the C declaration
 *      *      */
static char *
rettype_integer (int n)
{
  char s[200];

  /*static char rs[20] = "long"; */
  /*int a; */

  A4GL_debug ("rettype_integer : %d\n", n);

  SPRINTF1 (s, "%d", n);
  return rettype_lint (s);
}


int
A4GL_is_valid_4gl_type (char *s)
{
  //char errbuff[80];
  static char types[20][80];
  //char buff[20];
  int a;
  //int b;
  static int set_types = 0;
  if (set_types == 0)
    {
      for (a = 0; a < 15; a++)
	{
	  strcpy (types[a], rettype_integer (a));
	}
      set_types = 1;
    }

  for (a = 0; a < 15; a++)
    {
      if (A4GL_aubit_strcasecmp (types[a], s) == 0)
	{
	  return 1;
	}
    }

  A4GL_debug ("Looking for type '%s'", s);

  if (A4GL_find_datatype_out (s) != -1)
    {
      return 1;
    }

  A4GL_debug ("Not found - keep looking");
  A4GL_debug ("find_type %s\n", s);
  if (A4GL_aubit_strcasecmp ("char", s) == 0)
    return 1;
  if (A4GL_aubit_strcasecmp ("long", s) == 0)
    return 1;
  if (A4GL_aubit_strcasecmp ("int8", s) == 0)
    return 1;
  if (A4GL_aubit_strcasecmp ("serial8", s) == 0)
    return 1;
  if (A4GL_aubit_strcasecmp ("integer", s) == 0)
    return 1;
  if (A4GL_aubit_strcasecmp ("int", s) == 0)
    return 1;
  if (A4GL_aubit_strcasecmp ("short", s) == 0)
    return 1;
  if (A4GL_aubit_strcasecmp ("double", s) == 0)
    return 1;
  if (A4GL_aubit_strcasecmp ("float", s) == 0)
    return 1;
  if (A4GL_aubit_strcasecmp ("fgldecimal", s) == 0)
    return 1;
  if (A4GL_aubit_strcasecmp ("serial", s) == 0)
    return 1;
  if (A4GL_aubit_strcasecmp ("fgldate", s) == 0)
    return 1;
  if (A4GL_aubit_strcasecmp ("fglmoney", s) == 0)
    return 1;
  if (A4GL_aubit_strcasecmp ("struct_dtime", s) == 0)
    return 1;
  if (A4GL_aubit_strcasecmp ("fglbyte", s) == 0)
    return 1;
  if (A4GL_aubit_strcasecmp ("fgltext", s) == 0)
    return 1;
  if (A4GL_aubit_strcasecmp ("varchar", s) == 0)
    return 1;
  if (A4GL_aubit_strcasecmp ("struct_ival", s) == 0)
    return 1;
  if (A4GL_aubit_strcasecmp ("form", s) == 0)
    return 1;
  if (A4GL_aubit_strcasecmp ("uiwindow", s) == 0)
    return 1;
  if (A4GL_aubit_strcasecmp ("omdomnode", s) == 0)
    return 1;
  if (A4GL_aubit_strcasecmp ("omnodelist", s) == 0)
    return 1;
  if (A4GL_aubit_strcasecmp ("basechannel", s) == 0)
    return 1;
  if (A4GL_aubit_strcasecmp ("string", s) == 0)
    return 1;
  return 0;
}


// Lint expect/ignore handling
//
#define MAX_NUM_LINT_ERRORS 1000
char *lint_expect_list[MAX_NUM_LINT_ERRORS];
char *lint_ignore_list[MAX_NUM_LINT_ERRORS];

static void
init_lint (void)
{
  int a;
  for (a = 0; a < MAX_NUM_LINT_ERRORS; a++)
    {
      lint_expect_list[a] = NULL;
      lint_ignore_list[a] = NULL;
    }
  add_custom_severities();
}


static void
add_lint_ignore (char *s)
{
  int firstnull = -1;
  int a;


//printf("add_lint_ignore: %s\n",s);

  if (s[0] == '-')
    {
      // We need to remove it from our list...
      //
      // Skip the '-'
      s++;
      for (a = 0; a < MAX_NUM_LINT_ERRORS; a++)
	{
	  if (lint_ignore_list[a])
	    {
	      if (strcmp (s, lint_ignore_list[a]) == 0)
		{
		  // We've found it in our list..
		  free (lint_ignore_list[a]);
		  lint_ignore_list[a] = NULL;
		}
	    }
	}
      return;
    }



  if (s[0] == '+')
    s++;


  for (a = 0; a < MAX_NUM_LINT_ERRORS; a++)
    {
      if (lint_ignore_list[a])
	{
	  if (strcmp (s, lint_ignore_list[a]) == 0)
	    {
	      // We've found it in our list - its already active..
	      return;
	    }
	}
      else
	{
	  // The space is empty - do we need to use it ? 
	  if (firstnull == -1)
	    {
	      // if its not found by the time we reach the end of the array - we can use it...
	      firstnull = a;
	    }
	}
    }

  if (firstnull == -1)
    {
      printf ("Unable to find empty place to put lint warning..(ignore)\n");
      exit (2);
    }
  lint_ignore_list[firstnull] = strdup (s);
}


static void
add_lint_expect (char *s)
{
  int firstnull = -1;
  int a;

  if (s[0] == '-')
    {
      // We need to remove it from our list...
      //
      // Skip the '-'
      s++;
      for (a = 0; a < MAX_NUM_LINT_ERRORS; a++)
	{
	  if (lint_expect_list[a])
	    {
	      // We remove *all* of the entries...
	      free (lint_expect_list[a]);
	      lint_expect_list[a] = NULL;
	    }
	}
      return;
    }



  if (s[0] == '+')
    s++;


  for (a = 0; a < MAX_NUM_LINT_ERRORS; a++)
    {
      if (lint_expect_list[a])
	{
	  if (strcmp (s, lint_expect_list[a]) == 0)
	    {
	      // We've found it in our list - its already active..
	      return;
	    }
	}
      else
	{
	  // The space is empty - do we need to use it ? 
	  if (firstnull == -1)
	    {
	      // if its not found by the time we reach the end of the array - we can use it...
	      firstnull = a;
	    }
	}
    }

  if (firstnull == -1)
    {
      printf ("Unable to find empty place to put lint warning (expect)..\n");
      exit (2);
    }

  lint_expect_list[firstnull] = strdup (s);

}


static void
set_lint_ignore (struct command *c)
{
  int a;
  A4GL_assertion (c->cmd_data.type != E_CMD_LINT_IGNORE_CMD, "Expecting 'E_CMD_LINT_IGNORE_CMD'");
  if (c->cmd_data.command_data_u.lint_ignore_cmd.values == NULL)
    return;
  for (a = 0; a < c->cmd_data.command_data_u.lint_ignore_cmd.values->str_list_entry.str_list_entry_len; a++)
    {
      add_lint_ignore (c->cmd_data.command_data_u.lint_ignore_cmd.values->str_list_entry.str_list_entry_val[a]);
    }
}

static void
set_lint_expect (struct command *c)
{
  int a;
  A4GL_assertion (c->cmd_data.type != E_CMD_LINT_EXPECT_CMD, "Expecting 'E_CMD_LINT_EXPECT_CMD'");
  if (c->cmd_data.command_data_u.lint_expect_cmd.values == NULL)
    return;
  for (a = 0; a < c->cmd_data.command_data_u.lint_expect_cmd.values->str_list_entry.str_list_entry_len; a++)
    {
      add_lint_expect (c->cmd_data.command_data_u.lint_expect_cmd.values->str_list_entry.str_list_entry_val[a]);
    }
}
static void
clr_lint_expect ()
{
  add_lint_expect ("-");
}

static int
has_lint_ignore (char *c)
{
  int a;
  for (a = 0; a < MAX_NUM_LINT_ERRORS; a++)
    {
      if (lint_ignore_list[a])
	{
	  //printf("%s %s\n", lint_ignore_list[a],c);
	  if (strcmp (lint_ignore_list[a], c) == 0) {
	    return 1;
	  }
	}
    }
  return 0;
}

static int
has_lint_expect (char *c)
{
  int a;
  for (a = 0; a < MAX_NUM_LINT_ERRORS; a++)
    {
      if (lint_expect_list[a])
	{
	  //printf("%s %s\n", lint_expect_list[a],c);
	  if (strcmp (lint_expect_list[a], c) == 0)
	    return 1;
	}
    }
  return 0;
}

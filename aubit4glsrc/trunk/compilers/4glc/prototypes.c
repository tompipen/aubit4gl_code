#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"
#include "a4gl_4glc_int.h"
#include "lint.h"
#include "linearise.h"
#include "expr_munging.h"

#define MODE_TRY 0
#define MODE_BUY 1

static int indent = 0;
char currfunc[2000];
char currmod[2000];
extern int yylineno;
//char *lint_module = 0;
//static void load_boltons (char *fname);
//static int add_calltree_calls (char *s, commands * func_commands, int mode);
static int find_function (char *s);
int find_function_single_rtype_proto (char *funcname);
int is_bolton_function (char *funcname);
char *decode_rb (enum report_blocks a);
static void run_calltree (char *s);
static void generate_blacklist (void);
//int ignLibFunc=1;

//int inc4GL = 1;                       /* Include 4gl in the output */
//int incProg = 1;

extern module_definition this_module;
//int expr_datatype (struct expr_str *p);


#define PROTO_FUNCTION 		1
#define PROTO_REPORT 		2
#define PROTO_PDF_REPORT 	3


struct rettypes
{
  int nreturns;
  int *returns;
  char **retexprs;
  int lineno;
};

struct function
{
  char *module;
  int module_no;
  int line;
  char *function;
  int nparameters;
  int *parameters;
  char **paramnames;
  commands return_commands;
  struct rettypes **return_datatypes;
  int nreturn_datatypes;
  int processed_returns;
  call_list *call_list;
  int called;
  int isInLibraryModule;
};



struct function *functions = 0;
int functions_cnt = 0;

FILE *output = 0;
FILE *output_unl = 0;



//int nboltons = 0;

//expr_str_list *expr_cache = 0;

//int simpleGraph = 1;
//int printAllFuncs = 0;


#define NODE_FUNC_DEFINED "**DEFINED**"


/*
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
*/












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
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_send_to_ui") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_settitle") == 0)
    return -1;

  if (A4GL_aubit_strcasecmp (funcname, "fgl_winquestion") == 0)
    return DTYPE_CHAR;
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_add_to_toolbar") == 0)
    return -1;

// INTs
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_sendfile_to_ui") == 0)
    return DTYPE_INT;
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
  if (A4GL_aubit_strcasecmp (funcname, "fgl_winmessage") == 0)
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






static void
add_function (int module_no, char *module, int line, char *fname, char forr, void *ptr, int isInLibrary, commands * commands,
	      expr_str_list * params, call_list * call_list, int isInLibraryModule)
{
  struct commands *all_cmds;
  int a;
  functions_cnt++;
  functions = realloc (functions, sizeof (struct function) * functions_cnt);
  functions[functions_cnt - 1].module = module;
  functions[functions_cnt - 1].module_no = module_no;
  functions[functions_cnt - 1].line = line;
  functions[functions_cnt - 1].function = fname;

  functions[functions_cnt - 1].nparameters = 0;
  functions[functions_cnt - 1].parameters = NULL;
  functions[functions_cnt - 1].paramnames = NULL;
  functions[functions_cnt - 1].return_datatypes = NULL;
  functions[functions_cnt - 1].nreturn_datatypes = 0;
  functions[functions_cnt - 1].processed_returns = 0;
  functions[functions_cnt - 1].call_list = call_list;
  functions[functions_cnt - 1].called = 0;
  functions[functions_cnt - 1].isInLibraryModule = isInLibraryModule;

  if (params)
    {
      int z;
      functions[functions_cnt - 1].nparameters = params->list.list_len;

      functions[functions_cnt - 1].parameters = malloc (sizeof (int) * functions[functions_cnt - 1].nparameters);
      functions[functions_cnt - 1].paramnames = malloc (sizeof (char *) * functions[functions_cnt - 1].nparameters);
      for (z = 0; z < functions[functions_cnt - 1].nparameters; z++)
	{

	  functions[functions_cnt - 1].parameters[z] = expr_datatype (module, line, params->list.list_val[z]);
		if (functions[functions_cnt - 1].parameters[z]==DTYPE_SERIAL) {
			functions[functions_cnt - 1].parameters[z]=DTYPE_INT;
		}
	  functions[functions_cnt - 1].paramnames[z] = strdup (expr_as_string_when_possible (params->list.list_val[z]));

	  //params.list.list_val;
	}
    }

  //functions[functions_cnt - 1].f_or_r = forr;

  all_cmds = linearise_commands (0, 0);
  functions[functions_cnt - 1].return_commands.cmds.cmds_len = 0;
  functions[functions_cnt - 1].return_commands.cmds.cmds_val = 0;

  printf ("Adding %s in %s.%d\n", fname, module, line);
  if (commands != NULL)
    {
      linearise_commands (all_cmds, commands);



      for (a = 0; a < all_cmds->cmds.cmds_len; a++)
	{

#ifdef GENERATE_CALLS_UNL
/* This is used to generate some more prototypes  */
	  if (all_cmds->cmds.cmds_val[a]->cmd_data.type == E_CMD_CALL_CMD) {
			FILE *p;
			p=fopen("calls.unl","a");
			if (p) {
				int b;
				struct struct_call_cmd *c;
				c=&all_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.call_cmd;
				if (c->fcall->expr_type==ET_EXPR_FCALL) {
					struct s_expr_function_call *fcall;
					fcall=c->fcall->expr_str_u.expr_function_call;
					fprintf(p,"%s|", fcall->fname);
					if (fcall->parameters) {
						for (b=0;b<fcall->parameters->list.list_len;b++)  {
							int d;
      							d= expr_datatype (all_cmds->cmds.cmds_val[a]->module, all_cmds->cmds.cmds_val[a]->lineno, fcall->parameters->list.list_val[b]);
							if (b) fprintf(p,",");
							fprintf(p,"%d",d&DTYPE_MASK);
						}
					}
					fprintf(p,"|");
					if (c->returning) {
						for (b=0;b<c->returning->list.list_len;b++)  {
							int d;
      							d= expr_datatype (all_cmds->cmds.cmds_val[a]->module, all_cmds->cmds.cmds_val[a]->lineno, c->returning->list.list_val[b]);
							if (b) fprintf(p,",");
							fprintf(p,"%d",d&DTYPE_MASK);
						}
					}
					fprintf(p,"|\n");
				}
			}
			fclose(p);
	  }
#endif

	  if (all_cmds->cmds.cmds_val[a]->cmd_data.type == E_CMD_RETURN_CMD)
	    {

	      printf ("   Adding Return @ line : %s.%d\n", module, all_cmds->cmds.cmds_val[a]->lineno);

	      functions[functions_cnt - 1].return_commands.cmds.cmds_len =
		functions[functions_cnt - 1].return_commands.cmds.cmds_len + 1;
	      functions[functions_cnt - 1].return_commands.cmds.cmds_val =
		realloc (functions[functions_cnt - 1].return_commands.cmds.cmds_val,
			 sizeof (functions[functions_cnt - 1].return_commands.cmds.cmds_val[0]) * functions[functions_cnt -
													    1].return_commands.cmds.
			 cmds_len);
	      functions[functions_cnt -
			1].return_commands.cmds.cmds_val[functions[functions_cnt - 1].return_commands.cmds.cmds_len - 1] =
		all_cmds->cmds.cmds_val[a];
	    }
	}
    }

}

int callstack_cnt = 0;
char **callstack = 0;



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


static void
print_indent (void)
{
  int a;
  for (a = 0; a < indent; a++)
    {
      fprintf (output, "   ");
    }
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
      strcat (buff, expr_as_string_when_possible (list->field_list_entries.field_list_entries_val[a].field));
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
      return expr_as_string_when_possible (x);
      A4GL_assertion (1, "Unexpected expression type");

    }
  sprintf (buff, "Bad VAR=%d", x->expr_type);
  return buff;
  return "Blah1";
}



static void
add_rettypes (int funcno, struct rettypes *rl)
{
  int a;
  int found = 1;

#ifdef MINIMIZE
  for (a = 0; a < functions[funcno].nreturn_datatypes; a++)
    {
      int b;
      found = 1;
      if (rl->nreturns != functions[funcno].return_datatypes[a]->nreturns)
	{
	  found = 0;
	  continue;
	}
      for (b = 0; b < rl->nreturns; b++)
	{
	  if (functions[funcno].return_datatypes[a]->returns[b] != rl->returns[b])
	    {
	      found = 0;
	      break;
	    }
	}
      if (found)
	{
	  return;		// Its a duplicate of something thats already there...
	}
    }
#endif

  // if we get to here - it must be new :-)
  //
  functions[funcno].nreturn_datatypes++;
  functions[funcno].return_datatypes =
    realloc (functions[funcno].return_datatypes,
	     sizeof (functions[funcno].return_datatypes[0]) * functions[funcno].nreturn_datatypes);
  functions[funcno].return_datatypes[functions[funcno].nreturn_datatypes - 1] = rl;

}

static struct rettypes *
prototype_returns (int a, command * c)
{
  struct rettypes *rl;
  int d;
  expr_str_list *retvals;
  retvals = c->cmd_data.command_data_u.return_cmd.retvals;
  rl = malloc (sizeof (struct rettypes));
  if (retvals == 0)
    {
      rl->nreturns = 0;
      rl->returns = 0;
      rl->lineno = 0;
      rl->retexprs = 0;
      return rl;
    }
  rl->nreturns = retvals->list.list_len;
  rl->returns = malloc (sizeof (int) * rl->nreturns);
  rl->retexprs = malloc (sizeof (char *) * rl->nreturns);
  rl->lineno = c->lineno;

  for (d = 0; d < retvals->list.list_len; d++)
    {
      rl->returns[d] = expr_datatype (functions[a].module, functions[a].line, retvals->list.list_val[d]);
	if ((rl->returns[d]&DTYPE_MASK) ==DTYPE_SERIAL) {
		rl->returns[d]=DTYPE_INT;
	}
      rl->retexprs[d] = expr_as_string_when_possible (retvals->list.list_val[d]);

      //if (d) printf(",");
      //printf("%d", rl->returns[d]);

    }
  //printf("\n");
  return rl;
}



static void
process_return_types_for_function (int a)
{
  int b;
  //printf("Process %d - %d\n",a,functions[a].processed_returns);
  if (functions[a].processed_returns)
    {
      return;
    }
  functions[a].processed_returns = 1;
  //printf("%s\n",functions[a].function);

  for (b = 0; b < functions[a].return_commands.cmds.cmds_len; b++)
    {
      struct command *c;
      c = functions[a].return_commands.cmds.cmds_val[b];

      switch (c->cmd_data.type)
	{

	case E_CMD_RETURN_CMD:
	  {
	    struct rettypes *rl;
	    rl = prototype_returns (a, c);
	    add_rettypes (a, rl);
	  }
	  break;

	default:
	  fprintf (stderr, "Unexpected command type - this is just supposed to be RETURN commands...\n");
	  exit (1);
	}
    }
  functions[a].processed_returns = 2;

}

static int
proto_program (module_definition * mods, int nmodules)
{
  int a;
  int b;
  char *fname;
  int mid;

  for (a = 0; a < nmodules; a++)
    {

      //init_whenever ();

      printf ("Module : %s.4gl\n", mods[a].module_name);
      for (b = 0; b < mods[a].module_entries.module_entries_len; b++)
	{
	  switch (mods[a].module_entries.module_entries_val[b]->met_type)
	    {

	    case E_MET_MAIN_DEFINITION:
	      mods[a].module_entries.module_entries_val[b]->module_entry_u.function_definition.parameters =
		expand_parameters (&mods[a].module_entries.module_entries_val[b]->module_entry_u.function_definition.variables,
				   mods[a].module_entries.module_entries_val[b]->module_entry_u.function_definition.parameters);

	      add_function (a, mods[a].module_name,
			    mods[a].module_entries.module_entries_val[b]->module_entry_u.function_definition.lineno,
			    "MAIN", 'F', &mods[a].module_entries.module_entries_val[b]->module_entry_u.function_definition,
			    mods[a].moduleIsInLibrary,
			    mods[a].module_entries.module_entries_val[b]->module_entry_u.function_definition.func_commands,
			    mods[a].module_entries.module_entries_val[b]->module_entry_u.function_definition.parameters,
			    &mods[a].module_entries.module_entries_val[b]->module_entry_u.function_definition.call_list,
			    mods[a].moduleIsInLibrary);

	      break;

	    case E_MET_FUNCTION_DEFINITION:
	      mods[a].module_entries.module_entries_val[b]->module_entry_u.function_definition.parameters =
		expand_parameters (&mods[a].module_entries.module_entries_val[b]->module_entry_u.function_definition.variables,
				   mods[a].module_entries.module_entries_val[b]->module_entry_u.function_definition.parameters);


	      add_function (a, mods[a].module_name,
			    mods[a].module_entries.module_entries_val[b]->module_entry_u.function_definition.lineno,
			    mods[a].module_entries.module_entries_val[b]->module_entry_u.function_definition.funcname,
			    'F', &mods[a].module_entries.module_entries_val[b]->module_entry_u.function_definition,
			    mods[a].moduleIsInLibrary,
			    mods[a].module_entries.module_entries_val[b]->module_entry_u.function_definition.func_commands,
			    mods[a].module_entries.module_entries_val[b]->module_entry_u.function_definition.parameters,
			    &mods[a].module_entries.module_entries_val[b]->module_entry_u.function_definition.call_list,
			    mods[a].moduleIsInLibrary);
	      break;

	    case E_MET_REPORT_DEFINITION:
	      mods[a].module_entries.module_entries_val[b]->module_entry_u.report_definition.parameters =
		expand_parameters (&mods[a].module_entries.module_entries_val[b]->module_entry_u.report_definition.variables,
				   mods[a].module_entries.module_entries_val[b]->module_entry_u.report_definition.parameters);
	      add_function (a, mods[a].module_name,
			    mods[a].module_entries.module_entries_val[b]->module_entry_u.report_definition.lineno,
			    mods[a].module_entries.module_entries_val[b]->module_entry_u.report_definition.funcname,
			    'R', &mods[a].module_entries.module_entries_val[b]->module_entry_u.report_definition,
			    mods[a].moduleIsInLibrary, NULL,
			    mods[a].module_entries.module_entries_val[b]->module_entry_u.report_definition.parameters,
			    &mods[a].module_entries.module_entries_val[b]->module_entry_u.function_definition.call_list,
			    mods[a].moduleIsInLibrary);
	      break;

	    case E_MET_PDF_REPORT_DEFINITION:
	      mods[a].module_entries.module_entries_val[b]->module_entry_u.pdf_report_definition.parameters =
		expand_parameters (&mods[a].module_entries.module_entries_val[b]->module_entry_u.pdf_report_definition.variables,
				   mods[a].module_entries.module_entries_val[b]->module_entry_u.pdf_report_definition.parameters);

	      add_function (a, mods[a].module_name,
			    mods[a].module_entries.module_entries_val[b]->module_entry_u.pdf_report_definition.lineno,
			    mods[a].module_entries.module_entries_val[b]->module_entry_u.pdf_report_definition.funcname,
			    'P', &mods[a].module_entries.module_entries_val[b]->module_entry_u.pdf_report_definition,
			    mods[a].moduleIsInLibrary, NULL,
			    mods[a].module_entries.module_entries_val[b]->module_entry_u.pdf_report_definition.parameters,
			    &mods[a].module_entries.module_entries_val[b]->module_entry_u.function_definition.call_list,
			    mods[a].moduleIsInLibrary);

	      break;

	    case E_MET_CMD:
	      {
		struct command *c;
		c = mods[a].module_entries.module_entries_val[b]->module_entry_u.cmd;
		if (c->cmd_data.type == E_CMD_WHENEVER_CMD)
		  {
		  }
	      }
	      break;

	    default:
	      // Ignore...
	      break;
	    }
	}

    }




// Now scan for any WHENEVER ERRORs outside of functions - as these wont be in the call_list...
  for (a = 0; a < nmodules; a++)
    {

      for (b = 0; b < mods[a].module_entries.module_entries_len; b++)
	{
	  switch (mods[a].module_entries.module_entries_val[b]->met_type)
	    {
	    case E_MET_CMD:
	      {
		struct command *c;
		c = mods[a].module_entries.module_entries_val[b]->module_entry_u.cmd;
		if (c->cmd_data.type == E_CMD_WHENEVER_CMD)
		  {
		    if (c->cmd_data.command_data_u.whenever_cmd.whencode & WHEN_CALL)
		      {

		      }
		  }
	      }
	      break;

	    default:
	      // Ignore...
	      break;
	    }
	}
    }


  printf ("Total # functions %d\n", functions_cnt);

  // see whats actually used...
  run_calltree ("MAIN");
  generate_blacklist ();

  // Now - we should have loaded all our function definitions
  // go and process the RETURN commands - which should resolve to 
  // real functions now - even if they are in different 4gl modules
  for (a = 0; a < functions_cnt; a++)
    {
      process_return_types_for_function (a);
    }

  output = fopen ("prototypes.xml", "w");

  if (output == 0)
    {
      printf ("Unable to open output file (calltree.xml)\n");
      exit (2);
    }
  output_unl = fopen ("prototypes.unl", "w");

  fprintf (output, "<?xml version=\"1.0\" ?>\n");
  fprintf (output, "<PROGRAM>\n");
  for (a = 0; a < functions_cnt; a++)
    {
      char buff_proto[20000];
      //sprintf(buff_proto,"%s|%s|%d|", functions[a].module,functions[a].function,  functions[a].line);
      sprintf (buff_proto, "%s|", functions[a].function);

      fprintf (output, " <FUNCTION NAME=\"%s\" MODULE=\"%s\" LINE=\"%d\">\n",
	       functions[a].function, functions[a].module, functions[a].line);
      fprintf (output, "  <PARAMETERS>\n");
      if (functions[a].nparameters)
	{
	  char tmp[200];
	  int b;
	  for (b = 0; b < functions[a].nparameters; b++)
	    {
		int printed=0;
	      fprintf (output, "   <EXPR NO=\"%d\" DATATYPE=\"%d\" LENGTH=\"%d\" NAME=\"%s\"/>\n",
		       b, functions[a].parameters[b] & DTYPE_MASK, functions[a].parameters[b] >> 16, functions[a].paramnames[b]);
	      if (b)
		{
		  strcat (buff_proto, ",");
		}
	      //sprintf(tmp,"%d",  functions[a].parameters[b]&DTYPE_MASK);
	      if ((functions[a].parameters[b] & DTYPE_MASK) == DTYPE_INTERVAL)
		{
		  sprintf (tmp, "%d", functions[a].parameters[b]);
		  printed++;
		}
		if ((functions[a].parameters[b] & DTYPE_MASK)==DTYPE_SMINT)  {
  			if (A4GL_strstartswith(functions[a].paramnames[b],"lb_") && A4GL_isyes(acl_getenv("USE_LB_AS_BOOL")) ) {
		  		sprintf (tmp, "%d", 90);
		  		printed++;
			}
  			if (A4GL_strstartswith(functions[a].paramnames[b],"mb_") && A4GL_isyes(acl_getenv("USE_LB_AS_BOOL")) ) {
		  		sprintf (tmp, "%d", 90);
		  		printed++;
			}
  			if (A4GL_strstartswith(functions[a].paramnames[b],"gb_") && A4GL_isyes(acl_getenv("USE_LB_AS_BOOL")) ) {
		  		sprintf (tmp, "%d", 90);
		  		printed++;
			}
		}

		if (!printed) {
		  	sprintf (tmp, "%d", functions[a].parameters[b] & DTYPE_MASK);
		}
		
	      strcat (buff_proto, tmp);
	    }
	}
      fprintf (output, "  </PARAMETERS>\n");
      fprintf (output, "  <RETURNS NUMRETS=\"%d\">\n", functions[a].nreturn_datatypes);

      if (functions[a].return_datatypes)
	{
	  for (b = 0; b < functions[a].nreturn_datatypes; b++)
	    {
	      int c;
	      fprintf (output_unl, "%s|", buff_proto);

	      fprintf (output, "   <RETURN LINENO=\"%d\">\n", functions[a].return_datatypes[b]->lineno);
	      for (c = 0; c < functions[a].return_datatypes[b]->nreturns; c++)
		{
		  fprintf (output, "    <EXPR NO=\"%d\" DATATYPE=\"%d\" LENGTH=\"%d\">%s</EXPR>\n",
			   c,
			   functions[a].return_datatypes[b]->returns[c] & DTYPE_MASK,
			   functions[a].return_datatypes[b]->returns[c] >> 16,
			   local_xml_escape (functions[a].return_datatypes[b]->retexprs[c]));
		  if (c)
		    {
		      fprintf (output_unl, ",");
		    }
		  //fprintf(output_unl,"%d", functions[a].return_datatypes[b]->returns[c]&DTYPE_MASK);
		  if ((functions[a].return_datatypes[b]->returns[c] & DTYPE_MASK) != DTYPE_INTERVAL)
		    {
		      fprintf (output_unl, "%d", functions[a].return_datatypes[b]->returns[c] & DTYPE_MASK);
		    }
		  else
		    {
		      fprintf (output_unl, "%d", functions[a].return_datatypes[b]->returns[c]);
		    }
		}
	      fprintf (output_unl, "|\n");
	      fprintf (output, "   </RETURN>\n");
	    }
	}
      else
	{
	  fprintf (output_unl, "%s| |\n", buff_proto);
	}
      fprintf (output, "  </RETURNS>\n");

      fprintf (output, " </FUNCTION>\n");
    }
  fprintf (output, "</PROGRAM>\n");
  fclose (output);
  fclose (output_unl);
  return 1;
}


int yylineno;
FILE *lintfile;

module_definition this_module;

int
main (int argc, char *argv[])
{
  module_definition *m;
  char buff[3000];
  int a;
  int b;

  if (argc < 2)
    {
      printf ("Usage : %s infile infile...\n", argv[0]);
      exit (2);
    }

  A4GL_build_user_resources ();

  m = malloc (sizeof (struct module_definition) * (argc - 1));



  for (a = 1; a < argc; a++)
    {
      sprintf (buff, "%s", argv[a]);
      if (strstr (buff, ".dat") != 0)
	{
	  char *p;
	  p = strstr (buff, ".dat");
	  *p = 0;
	}
      printf ("Loading %s : ", buff);
      fflush (stdout);

      if (A4GL_read_data_from_file ("module_definition", &m[a - 1], buff))
	{
	  printf ("OK...\n");
	}
      else
	{
	  printf ("- Failed to load\n");
	  exit (1);
	}
    }

  proto_program (m, argc - 1);
  return 0;
}


void
open_db (char *s)
{
  // Nope..
}

void
set_yytext (char *s)
{
}



int
current_is_report ()
{				// just used for lineno/pageno ..
  return 0;
}


int
find_function_single_rtype_proto (char *funcname)
{
  int a;
  if (system_function (funcname))
    {
      return system_function_dtype (funcname);
    }


  if (is_bolton_function (funcname) != -1)
    {
      return get_bolton_rtype (is_bolton_function (funcname), 0);
    }

  for (a = 0; a < functions_cnt; a++)
    {
      if (strcmp (functions[a].function, funcname) == 0)
	{
	  int b;

	  if (!functions[a].processed_returns)
	    {
	      process_return_types_for_function (a);
	    }


	  if (functions[a].nreturn_datatypes == 1)
	    {			// A single return
	      if (functions[a].return_datatypes[0]->nreturns == 1)
		{		// OF a single value..
		  return functions[a].return_datatypes[0]->returns[0];
		}
	    }
	  else
	    {
	      // more than one return...
	      for (b = 0; b < functions[a].nreturn_datatypes; b++)
		{
		  if (functions[a].return_datatypes[b]->nreturns == 1)
		    {		// Does it have 1 value ? 
		      if (functions[a].return_datatypes[b]->returns[0] != -1)
			{	// Is it sensible ? 
			  return functions[a].return_datatypes[b]->returns[0];	// Use it...
			}
		    }
		}
	    }

	  if (functions[a].processed_returns == 1)
	    return -1;
	  printf ("Found function - but can't use it %d returns\n", functions[a].nreturn_datatypes);
	  for (b = 0; b < functions[a].nreturn_datatypes; b++)
	    {
	      int c;
	      printf ("Returns %d values:", functions[a].return_datatypes[b]->nreturns);
	      for (c = 0; c < functions[a].return_datatypes[b]->nreturns; c++)
		{
		  if (c)
		    printf (",");
		  printf ("%d", functions[a].return_datatypes[b]->returns[c]);
		}
	      printf ("\n");

	    }
	  exit (2);

	}
    }

  return -1;
}


static void
run_calltree_for (call_list * call_list)
{
  int a;
  struct s_expr_function_call *fcall;
  for (a = 0; a < call_list->calls_by_expr.calls_by_expr_len; a++)
    {
      switch (call_list->calls_by_expr.calls_by_expr_val[a]->expr_type)
	{
	case ET_EXPR_FCALL:
	  fcall = call_list->calls_by_expr.calls_by_expr_val[a]->expr_str_u.expr_function_call;
	  run_calltree (fcall->fname);
	  break;
	default:
	  break;
	}
    }
}


// Go through and generate the whitelist of all functions
// which are actually called...
static void
run_calltree (char *s)
{
  int a;
  if (system_function (s))
    {
      return;
    }
  for (a = 0; a < functions_cnt; a++)
    {
      if (strcmp (functions[a].function, s) == 0)
	{
	  if (functions[a].called == 0)
	    {
	      functions[a].called = 1;
	      run_calltree_for (functions[a].call_list);
	    }
	  return;
	}
    }

  printf ("Warning : function not found (%s) whilst generating whitelist\n", s);
}



char **whitelist = 0;
int nwhitelist = 0;



static void
add_to_whitelist (char *s)
{
  nwhitelist++;
  whitelist = realloc (whitelist, sizeof (char *) * nwhitelist);
  whitelist[nwhitelist - 1] = strdup (s);
}


static int
is_on_whitelist (char *s)
{
  int a;
  if (whitelist == NULL)
    return 0;
  for (a = 0; a < nwhitelist; a++)
    {
      if (A4GL_aubit_strcasecmp (s, whitelist[a]) == 0)
	return 1;
    }

  return 0;
}



static void
load_whitelist (void)
{
  FILE *f;
  char buff[2000];
  f = fopen ("whitelist", "r");
  if (f == NULL)
    return;
  while (1)
    {
      memset (buff, 0, sizeof (buff));
      fgets (buff, 256, f);
      if (strlen (buff))
	{
	  A4GL_trim_nl (buff);
	  add_to_whitelist (buff);
	}
      if (feof (f))
	break;
    }
}


//
// generates a file (blacklist) with all of the functions
// which do not appear to be called 
// The file will *not* contain any functions which are not called
// but are in modules which have been compiled with the isInLibraryModule flag set
//
static void
generate_blacklist (void)
{
  FILE *fout;
  int a;
  int blacklisted = 0;
  load_whitelist ();
  fout = fopen ("blacklist", "w");
  if (fout == 0)
    {
      printf ("Unable to open blacklist for writing\n");
      return;
    }
  for (a = 0; a < functions_cnt; a++)
    {
      if (functions[a].called == 0)
	{
	  if (A4GL_isyes (acl_getenv ("BLACKLISTLIBFUNCSALSO")));
	  else
	    {
	      if (functions[a].isInLibraryModule)
		{
		  continue;
		}
	    }

	  if (is_on_whitelist (functions[a].function))
	    {
	      continue;
	    }

	  fprintf (fout, "%s\n", functions[a].function);
	  blacklisted++;
	}
    }
  fclose (fout);
  printf ("%d blacklisted functions\n", blacklisted);

}

#define ET_EXPR_VARIABLE_USAGE_call lint_get_variable_usage_as_string

#include "expr_as_string_when_possible.c"

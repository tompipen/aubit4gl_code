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
# $Id: php.c,v 1.1 2014-09-09 14:23:16 mikeaubury Exp $
# @TODO - Remove rep_cond & rep_cond_expr from everywhere and replace
# with struct expr_str equivalent
*/
#ifndef lint
static char const module_id[] = "$Id: php.c,v 1.1 2014-09-09 14:23:16 mikeaubury Exp $";
#endif
/**
 * @file
 * Generate .C & .H modules.
 *
 * Most of the functions implemented here are called by the parser.
 *
 * The goal is to generate a C program that implement the functionality of
 * the 4gl being compiled.
 */
//void A4GL_4glc_push_gen (int a, char *s);
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


static int daylight = 0;

//static char *A4GL_nobacktick (char *s);
char commentsfile[256] = "";
//static void dump_comments (int n);
struct module_definition *curr_module;
char *ofilename = "";
//static char find_scope (char *s);
static void merge_files (void);
char *return_datatype (int a);
//static int internal_var (char *s);
static char *local_has_comment (int n, int c, char *type);
int nonewlines = 0;
//char *decode_extend (int n);
//char *map_fname (char *s);
//static char *chk_for_var (char *ptr);


struct module_entry *current_entry = 0;
struct variable_list *current_entry_variables = 0;
static int isReport = 0;

char *thisClass = "Unset";
int suppress_lines = 0;
int rep_print_entry = 0;
int doing_input_array = 0;
char input_array_variable[200] = "";
int doing_report_print = 0;
char cmodname[256] = "";
char input_list[20000];
int nreturns = 0;
char *mod_whento[256];
int mod_whencode[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
static char initModVariables[2000] = "";
void A4GL_get_event (int n, int *i, char **s);
int A4GL_get_nevents (void);
char *rettype_integer (int n);
static int last_was_return=0;
static int Currnrets = 0;
static char *decode_dt(int n,int n2);
static char *decode_ival_define2(int n);
static char *decode_ival_define1(int n);
static char * decode_extend (int n);
static char * cleaned_name (char *s);
#define CONTEXT_INPUT 0
#define CONTEXT_MENU 1
#define CONTEXT_CONSTRUCT 2
#define CONTEXT_PROMPT 3
char last_context[10][200] = { "", "", "", "", "", "", "", "", "", "" };

//char *decode_ival_define1 (int n);
//char *decode_ival_define2 (int n);
//char *decode_current1 (int n);
//char *decode_current2 (int n);
int when_set_to_call = 0;
struct variable *find_var (char *s);
//static char *transform_get_mod_var (char *s);
int record_lvl = 0;
char membuffer[10][60000] = { "", "", "", "", "", "", "", "", "", "" };
char recname[10][600] = { "", "", "", "", "", "", "", "", "", "" };
static int *dtypes = 0;
int case_level = 0;
int case_num = 0;
int case_id[100];


struct sDeclares
{
  char ident[2000];
  struct expr_str_list *inbind;
  struct expr_str_list *outbind;
#define DECLARE_PREPARED 0
#define DECLARE_SELECT 1
#define DECLARE_INSERT 2
  int type;
};
char *make_sql_string_and_free (char *s, ...);

struct sDeclares *Declares = 0;
int nDeclares = 0;

int hasDeclare (char *s);
int addDeclare (char *s, struct expr_str_list *inbind, struct expr_str_list *outbind, int type);
/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_lib_lex_fgl_int.h"
#define ONE_NOT_ZERO(x) (x?x:1)

#include "field_handling.h"
#define COMPILE_CS_STATICS_TOO
#include "compile_php.h"
#include "../../../compilers/4glc/linearise.h"
char *replace_bind (char *s, expr_str_list * bind, char dir);
//static void real_print_binding_with_separator (expr_str_list * s, char read_or_write, char *sep);
//static void real_print_field_list (struct fh_field_list *fl);
//static void print_returning (expr_str_list * l);
//static void print_attributes (attrib * x);
//static char *field_name_list_from_byname (expr_str_list * t);
//static void real_print_str_list_with_separator (str_list * s, char *sep);
//static void print_events_as_calls (on_events * es, struct command *parent);
//static void print_events_as_4gl (on_events * es, struct command *parent);
//static char *irettype_integer (char *s, int n);
static void module_var_binding (struct expr_str_list *l, int stage);
static int local_is_system_variable (char *s);
static void print_function_variable_init (variable_list * fvars);
static char *explicitCastFunction (int targetDtype);
static char * map_fname (char *s);
static char * decode_current1 (int n);
static char * decode_current2 (int n);
static void tmp_ccntminus ();
static void A4GL_internal_lex_printc (char *fmt, va_list * ap);
static void A4GL_internal_lex_printh (char *fmt, va_list * ap);
static void print_define_char (char *varo, int size, int isstatic_extern, int lvl, int vno, char *defsrc, char *arrvar);
void real_print_expr (struct expr_str *ptr);
static void add_function_to_header (char *identifier, int params, char *is_static);
//int get_binding_dtype (expr_str * e);
static int isCharExpr(expr_str *e) ;
static struct variable * local_find_variable_from_usage (struct variable_usage *u);
char * decode_varbind (struct expr_str *t, char read_or_write, int pos);
static int uses_exit_case (struct s_commands *cmds);
static void print_goto_comment(void) ;
static int print_insert_cmd (struct_insert_cmd * cmd_data);
char * generation_get_variable_usage_as_string (struct variable_usage *u);

void dump_comments (int n);

struct expr_str_list *input_bind = 0;
struct expr_str_list *output_bind = 0;
char **printedDeclare = 0;
int nPrintedDeclare = 0;

int rep_print_code;
int last_orderby_type = -1;
//static int gen_ord (char *s);
static char *local_expr_as_string (expr_str * ptr);
static int isInReport (void);
/*
=====================================================================
                    Variables definitions
=====================================================================
*/

//void print_Constant_1 (char *name, struct constant_data *c);
char mv_repname[256];
int cs_ticker = 0;
int current_ordbindcnt = 0;
//static int idle_cnt = 0;
/** Pointer to the output C file */
static FILE *outfile = 0;
static void init_var (struct expr_str *b);
static void real_print_expr_list_with_separator (struct expr_str_list *l, char *s);

//void real_print_expr (struct expr_str *ptr);

struct command *last_rret = 0;
//void ensure_dtype (struct expr_str *e, int dtype, int notnull);
void ensure_dtype (char *module, int lineno, struct expr_str *e, int dtype, int notnull);


/** Pointer to the output header (.h) file */
static FILE *hfile = 0;
char filename_hfile[256] = "";
char filename_cfile[256] = "";
char filename_outfile[256] = "";
FILE *final_o;
//char *generation_get_variable_usage_as_string (struct variable_usage *u);
char *cleaned_fname (char *s);

/** The source code linenumber */
extern int yylineno;
char *currfuncname = 0;
//void print_prepare_cmd (struct_prepare_cmd * p);

#ifndef dll_import
#define dll_import
#endif

#define COPY_DATA_FROM_MODVARS_INTO_TMPS 1
#define COPY_DATA_FROM_TMPS_INTO_MODVARS 3

//dll_import struct rep_structure rep_struct;
//char *decode_form_attrib_call (struct form_attr *f);
//static void real_print_expr_with_separator (struct expr_str *l, char *s);
static void ensure_parameters (char *fname, struct expr_str_list *parameters);
//static void create_protos_from_module (module_definition * this_module);

//static void order_by_report_stack (void);
//static void real_print_expr_list (struct expr_str_list *l);
//static void A4GL_print_expr_list_concat (struct expr_str_list *l);
static int uses_loop (struct s_commands *cmds, char type, int blockid);
char *generation_get_variable_usage (struct expr_str *var_usage);

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

//void printc (char *fmt, ...);
static void print_module_variable_init (variable_list * mvars);
//static void print_output_rep (struct rep_structure *rep);
//static void print_form_attrib (struct form_attr *form_attrob);
void search_sql_variables (struct s_select_list_item_list *l, char dir);
//static int print_field_bind (int ccc);
//static int print_arr_bind (char i);
//static int print_constr (void);
//static int print_field_bind_constr (void);
//static int pr_when_do (char *when_str, int when_code, int l, char *f, char *when_to);
//static void pr_report_agg (void);
//static void pr_report_agg_clr (void);
static void check_for_variable (struct s_select_list_item *l, char dir);
static int is_substring_variable_usage (variable_usage * u, expr_str ** s, expr_str ** e);
//static void print_menu (int mn, int n);

//void print_in_binding (struct expr_str_list *list);
void print_in_binding_using (struct expr_str_list *list);
//void print_copy_fromRSet (struct expr_str_list *list);
static void print_when_sql_start (void);
static void print_when_sql_end (void);
char *decode_cmd_type (enum cmd_type value);


struct variable_usage *
new_variable_usage (struct variable_usage *old, char *partname, char prepend);
//static void real_print_expr (struct expr_str *ptr);
//static void real_print_func_call (t_expr_str * fcall, int close);
//static void real_print_class_func_call (char *var, char *identifier, struct expr_str *args, int args_cnt);
//static void real_print_pdf_call (char *a1, struct expr_str_list *args, char *a3);

static char *decode_event_id (e_event i);
//static char *local_get_namespace (char *s);
int tmp_ccnt = 0;
static char *get_attributes_as_string (attrib * x);
//static struct s_commands *linearise_commands (struct s_commands *master_list, struct s_commands *cmds);

struct s_function_definition *current_func = 0;
struct s_report_definition *current_report = 0;
struct s_pdf_report_definition *current_pdf_report = 0;
int returns = 0;


//int dump_cmds (struct s_commands *c, struct command *parent);
static void print_nullify (char type, variable_list * v);
//int expr_datatype (char *module, int lineno, struct expr_str *p);
//void dump_comments (int n);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/


static char *menu_contexts[100];
int nMenuContexts = 0;

static char *ui_contexts[100];
int nuiContexts = 0;

static void
push_menu_context (char *s)
{
  nMenuContexts++;
  menu_contexts[nMenuContexts - 1] = strdup (s);
}

static char *
get_menu_context (void)
{
  if (menu_contexts[nMenuContexts - 1][0] < ' ')
    {
      A4GL_pause_execution ();
    }
  return menu_contexts[nMenuContexts - 1];
}

static void
pop_menu_context (void)
{
  A4GL_assertion (nMenuContexts <= 0, "nMenuContexts <0");
  nMenuContexts--;
  free (menu_contexts[nMenuContexts]);
  menu_contexts[nMenuContexts] = "Freed";

}

static void
push_ui_context (char *s)
{
  nuiContexts++;
  ui_contexts[nuiContexts - 1] = strdup (s);
}

static char *
get_ui_context (void)
{

  if (ui_contexts[nuiContexts - 1][0] < ' ')
    {
      A4GL_pause_execution ();
    }
  if (nuiContexts)
    {
      return ui_contexts[nuiContexts - 1];
    }
  else
    {
      return "UILib.CurrentContext";
    }
}

static void
pop_ui_context (void)
{
  A4GL_assertion (nuiContexts <= 0, "nMenuContexts <0");
  nuiContexts--;
  free (ui_contexts[nuiContexts]);

}


static char *
check_name (char *s)
{
//printf("Check name : %s\n",s);


/*
  if (strcmp (s, "ref") == 0)
    return "xxx_ref";
*/

  return s;
}

/**
 * Print spaces to the increment acording to scope level generated in
 * target C code.
 */
static void
print_space (void)
{
  static char buff[256];
  int ccnt;
  if (tmp_ccnt < 0)
    {
      A4GL_assertion (1, "tmp_ccnt<0");
    }
  //ccnt=A4GL_get_ccnt()+tmp_ccnt;
  ccnt = tmp_ccnt + 1;
  memset (buff, ' ', 255);
  buff[ccnt * 4] = 0;
  if (outfile)
    FPRINTF (outfile, "%s", buff);
}


static void
print_uievents (char *prefix, struct on_events *events, int type, struct command *parent)
{
  int a;
  int b;


  if (events == 0)
    return;

  if (type == 0)
    {

      for (a = 0; a < events->event.event_len; a++)
	{
	  switch (events->event.event_val[a]->evt_data.event_type)
	    {

	    case EVENT_BEFORE_MENU:
	      printc ("%s->BeforeMenu=%d;\n", prefix, a);
	      break;

	    case EVENT_MENU_COMMAND:
	      set_nonewlines ();
	      printc ("%s->AddMenuCommand(%d,\n", prefix, a);

	      if (events->event.event_val[a]->evt_data.event_data_u.mnoption->shortname == 0)
		{
		  printc ("null");
		}
	      else
		{
		  real_print_expr (events->event.event_val[a]->evt_data.event_data_u.mnoption->shortname);
		}
	      printc (",");

	      if (events->event.event_val[a]->evt_data.event_data_u.mnoption->longname == 0)
		{
		  printc ("null");
		}
	      else
		{
		  real_print_expr (events->event.event_val[a]->evt_data.event_data_u.mnoption->longname);
		}
	      printc (",%d", events->event.event_val[a]->evt_data.event_data_u.mnoption->helpno);
	      printc (", new UILib_keylist(");
	      for (b = 0; b < events->event.event_val[a]->evt_data.event_data_u.mnoption->keys->str_list_entry.str_list_entry_len;
		   b++)
		{
		  if (b)
		    printc (",");
		  printc ("\"%s\"",
			  events->event.event_val[a]->evt_data.event_data_u.mnoption->keys->str_list_entry.str_list_entry_val[b]);
		}
	      printc (")");
	      printc (");");
	      clr_nonewlines ();
	      break;


	    case EVENT_BEF_ROW:
	      printc ("%s->BeforeRow=%d;", prefix, a);
	      break;

	    case EVENT_AFT_ROW:
	      printc ("%s->AfterRow=%d;", prefix, a);
	      break;

	    case EVENT_BEFORE_DELETE:
	      printc ("%s->BeforeDelete=%d;", prefix, a);
	      break;

	    case EVENT_AFTER_DELETE:
	      printc ("%s->AfterDelete=%d;", prefix, a);
	      break;

	    case EVENT_BEFORE_INSERT:
	      printc ("%s->BeforeInsert=%d;", prefix, a);
	      break;

	    case EVENT_AFTER_INSERT:
	      printc ("%s->AfterInsert=%d;", prefix, a);
	      break;

	    case EVENT_BEFORE_INSERT_DELETE:
	      printc ("%s->BeforeInsert=%d;", prefix, a);
	      printc ("%s->BeforeDelete=%d;", prefix, a);
	      break;

	    case EVENT_AFTER_INSERT_DELETE:
	      printc ("%s->AfterInsert=%d;", prefix, a);
	      printc ("%s->AfterDelete=%d;", prefix, a);
	      break;


	    case EVENT_AFTER_INPUT:
	      printc ("%s->AfterInput=%d;", prefix, a);
	      break;

	    case EVENT_BEFORE_INPUT:
	      printc ("%s->BeforeInput=%d;", prefix, a);
	      break;

	    case EVENT_AFTER_DISPLAY:
	      printc ("%s->AfterDisplay=%d;", prefix, a);
	      break;

	    case EVENT_BEFORE_DISPLAY:
	      printc ("%s->BeforeDisplay=%d;", prefix, a);
	      break;

	    case EVENT_AFTER_CONSTRUCT:
	      printc ("%s->AfterConstruct=%d;", prefix, a);
	      break;

	    case EVENT_BEFORE_CONSTRUCT:
	      printc ("%s->BeforeConstruct=%d;", prefix, a);
	      break;


	    case EVENT_AFTER_FIELD:
	      {
		//int z;
		//for (z = 0; z < events->event.event_val[a]->evt_data.event_data_u.st->str_list_entry.str_list_entry_len; z++)
		  //{
		    printc ("%s->AfterField(%d,%s);", prefix, a,
			    field_name_list_as_char (events->event.event_val[a]->evt_data.event_data_u.before_after_field));
		  //}
	      }
	      break;

	    case EVENT_BEFORE_FIELD:
	      {
		//int z;
		//for (z = 0; z < events->event.event_val[a]->evt_data.event_data_u.key->str_list_entry.str_list_entry_len; z++)
		  //{
		    printc ("%s->BeforeField(%d,%s);", prefix, a,
			    field_name_list_as_char (events->event.event_val[a]->evt_data.event_data_u.before_after_field));
		  //}
	      }
	      break;

	    case EVENT_KEY_PRESS:
	      {
		int z;
		for (z = 0; z < events->event.event_val[a]->evt_data.event_data_u.slist->str_list_entry.str_list_entry_len; z++)
		  {
		    printc ("%s->OnKey(%d,\"%s\");", prefix, a,
			    A4GL_strip_quotes (events->event.event_val[a]->evt_data.event_data_u.slist->str_list_entry.
					       str_list_entry_val[z]));
		  }
	      }
	      break;


	    case EVENT_ON_ACTION:
			A4GL_assertion(1,"NIY");
		/*
	      printc ("%s->OnAction(%d,\"%s\");", prefix, a,
		      A4GL_strip_quotes (events->event.event_val[a]->evt_data.event_data_u.on_action));
		*/
	      break;
	    case EVENT_ANYKEY_PRESS:
	    case EVENT_ON_IDLE:
	    case EVENT_ON_INTERVAL:
	    case EVENT_ON_TIME:
	    default:
	      printc ("UNHANDLED EVENT");
	      break;
	    }
	}
    }



  if (type == 1)
    {
      for (a = 0; a < events->event.event_len; a++)
	{
	  tmp_ccnt++;
	  printc ("case %d: /* %s */", a, decode_event_id (events->event.event_val[a]->evt_data.event_type));
	  tmp_ccnt++;
	  dump_cmds (events->event.event_val[a]->on_event_commands, parent);
	  printc ("break;");
	  tmp_ccnt--;
	  tmp_ccnt--;
	  printc ("#");
	}
    }

}


static int encode_variable_datatype(int dtype, int size1,int size2) {
A4GL_assertion(size2>0,"Expecting size2 to always be 0");
        return dtype+(size1<<16);
}


static char *
escape_quotes_and_remove_nl (char *s, int remove_nl)
{
  static char *buffer = 0;
  static int oldlen = 0;
  int a;
  int b = 0;
  int newlen;
  newlen = strlen (s) * 2 + 1;
  if (newlen > oldlen)
    {
      oldlen = newlen;
      buffer = realloc (buffer, newlen);
    }
  for (a = 0; a < strlen (s); a++)
    {
      if (s[a] == '"')
	{
	  buffer[b++] = '"';
	}
      if (s[a] == '$') {
	  buffer[b++] = '\\';
	  buffer[b++] = '$';
	continue;
	}
      if (s[a] == '\t')
	{
	  buffer[b++] = ' ';
	  continue;
	}
      if (s[a] == '\n' && remove_nl)
	{
	  if (buffer[b - 1] == ' ' || s[a + 1] == ' ')
	    {
	      continue;
	    }
	  buffer[b++] = ' ';
	  continue;
	}

      buffer[b++] = s[a];
    }
  buffer[b] = 0;
  return buffer;
}




static void
clr_bindings (void)
{
  if (input_bind)
    {
      if (input_bind->list.list_val)
	free (input_bind->list.list_val);
    }
  else
    {
      input_bind = malloc (sizeof (struct expr_str_list));
    }

  input_bind->list.list_len = 0;
  input_bind->list.list_val = 0;

  if (output_bind)
    {
      if (output_bind->list.list_val)
	free (output_bind->list.list_val);
    }
  else
    {
      output_bind = malloc (sizeof (struct expr_str_list));
    }
  output_bind->list.list_len = 0;
  output_bind->list.list_val = 0;
}


static char *
get_select (struct s_select *s, char *forUpdate)
{
  char *str;
  char *ptr;
  //char into_buff[65000] = "";

  if (forUpdate == 0)
    forUpdate = "";
  str = make_select_stmt_v2 (0, s, "");

  ptr = malloc (strlen (str) + strlen (forUpdate) + 1);
  if (strlen (forUpdate))
    {
      sprintf (ptr, "%s%s", str, forUpdate);
    }
  else
    {
      strcpy (ptr, str);
    }
  return ptr;
}


static char *
get_str_list_as_string (str_list * list, char *sep)
{
  char *rbuff = 0;
  int a;
  for (a = 0; a < list->str_list_entry.str_list_entry_len; a++)
    {
      if (a)
	rbuff = make_sql_string_and_free (rbuff, strdup (sep), list->str_list_entry.str_list_entry_val[a], NULL);
      else
	rbuff = make_sql_string_and_free (list->str_list_entry.str_list_entry_val[a], NULL);
    }
  return rbuff;
}




static char *
get_select_list_item_list_with_separator (struct s_select *select, struct s_select_list_item_list *slist, char *sep)
{
  int a;
  char *rval;
  if (slist == 0)
    return "";

  for (a = 0; a < slist->list.list_len; a++)
    {
      if (a)
	{
	  rval =
	    make_sql_string_and_free (rval, strdup (sep), strdup (get_select_list_item (select, slist->list.list_val[a])), NULL);
	}
      else
	{
	  rval = strdup (get_select_list_item (select, slist->list.list_val[a]));
	}
    }
  return rval;
}





static char *
get_insert_cmd (struct struct_insert_cmd *insertCmd, int *converted)
{
  static char buff[64000];
  char *ptr;
  char smbuff[256];
  *converted = 0;


  sprintf (smbuff, "INSERT INTO %s ", insertCmd->table);
  if (insertCmd->column_list)
    {
      sprintf (buff, "%s(%s) ", smbuff, get_str_list_as_string (insertCmd->column_list, ","));
    }
  else
    {
      strcpy (buff, smbuff);
    }

  // Collect all our inbinds..
  if (insertCmd->value_list)
    {
      search_sql_variables (insertCmd->value_list, 'i');
    }
  else
    {
      preprocess_sql_statement (insertCmd->subselect);
      search_sql_variables (&insertCmd->subselect->list_of_items, 'i');
    }

  if (insertCmd->value_list)
    {
      char *p;
      //char *p2;
      p = get_select_list_item_list_with_separator (NULL, insertCmd->value_list, ",\n   ");
      A4GL_assertion (p == 0, "No values list!");
      strcat (buff, "VALUES (\n   ");
      strcat (buff, p);
      strcat (buff, ")");
    }
  else
    {
      strcat (buff, get_select (insertCmd->subselect, ""));
    }



//
// if we're doing ESQL/C generation - we need to do some extra work..
//
  if (A4GL_compile_time_convert ())
    {
      ptr = A4GLSQLCV_check_sql (buff, converted);
    }
  else
    {
      ptr = buff;
    }

  return strdup (ptr);
}

static char *
get_update_cmd (struct struct_update_cmd *updateCmd, int *converted)
{
  int a;
  char *rval;
  //struct struct_update_cmd *u;
  struct s_select fake_select;
  //struct s_select_list_item_list l;
  struct s_table t;
  char *ptr;
  static char buff[64000];
  char smbuff[2000];

  *converted = 0;
  strcpy (buff, "");

  fake_select.modifier = 0;
  fake_select.limit.start = -1;
  fake_select.limit.end = -1;
  fake_select.limit.offset = -1;
  fake_select.ncolumns = 0;
  fake_select.select_list = 0;
  fake_select.first = 0;
  fake_select.table_elements.tables.tables_len = 0;
  fake_select.table_elements.tables.tables_val = 0;
  fake_select.group_by = 0;
  fake_select.having = 0;
  fake_select.list_of_items.list.list_len = 0;
  fake_select.list_of_items.list.list_val = 0;
  fake_select.where_clause = 0;
  fake_select.next = 0;
  fake_select.sf = 0;
  fake_select.union_op = 0;
  fake_select.into = 0;
  fake_select.first = &t;

  fake_select.first->tabname = updateCmd->table;
  fake_select.first->alias = fake_select.first->tabname;

  fake_select.first->next = NULL;
  fake_select.first->outer_next = NULL;
  fake_select.first->outer_join_condition = NULL;

  fake_select.table_elements.tables.tables_len = 0;
  fake_select.table_elements.tables.tables_val = 0;


  fake_select.where_clause = 0;
  if (updateCmd->where_clause)
    {
      fake_select.where_clause = updateCmd->where_clause->expr_str_u.sl_item;
    }
  fake_select.group_by = 0;
  fake_select.next = 0;
  fake_select.sf = 0;
  fake_select.into = 0;
  fake_select.union_op = 0;
  fake_select.extra_statement = 0;
  fake_select.select_list = updateCmd->value_list;

  A4GLSQLPARSE_from_clause_collect_tables (&fake_select, fake_select.first, &fake_select.table_elements);
  preprocess_sql_statement (&fake_select);
  search_sql_variables (&fake_select.list_of_items, 'i');

  sprintf (buff, "UPDATE %s SET ", updateCmd->table);

  A4GL_assertion (updateCmd->column_list == 0, "No column list");
  A4GL_assertion (updateCmd->value_list == 0, "No value list");

  if (updateCmd->value_list->list.list_len == updateCmd->column_list->str_list_entry.str_list_entry_len)
    {
      // Same length..
      for (a = 0; a < updateCmd->value_list->list.list_len; a++)
	{
	  if (a)
	    {
	      strcat (buff, ",");
	    }
	  rval = get_select_list_item (0, updateCmd->value_list->list.list_val[a]);
	  sprintf (smbuff, "%s=%s\n", updateCmd->column_list->str_list_entry.str_list_entry_val[a], rval);
	  strcat (buff, smbuff);
	  free (rval);
	}
    }
  else
    {
      strcat (buff, "(");
      for (a = 0; a < updateCmd->column_list->str_list_entry.str_list_entry_len; a++)
	{
	  if (a)
	    {
	      strcat (buff, ",\n");
	    }
	  strcat (buff, updateCmd->column_list->str_list_entry.str_list_entry_val[a]);
	}
      strcat (buff, ")=(");
      for (a = 0; a < updateCmd->value_list->list.list_len; a++)
	{
	  if (a)
	    {
	      strcat (buff, ",\n");
	    }
	  rval = get_select_list_item (0, updateCmd->value_list->list.list_val[a]);
	  strcat (buff, rval);
	  free (rval);
	}
      strcat (buff, ")");

    }

  if (updateCmd->where_clause)
    {
      if (updateCmd->where_clause->expr_type == ET_EXPR_WHERE_CURRENT_OF)
	{
	  struct expr_str *e;
	  strcat (buff, " WHERE CURRENT OF ");
	  e = updateCmd->where_clause->expr_str_u.expr_expr;
	  A4GL_assertion (e->expr_type != ET_EXPR_IDENTIFIER, "Expecting an identifier");
	  strcat (buff, e->expr_str_u.expr_string);
	}
      else
	{
	  strcat (buff, " WHERE ");
	  strcat (buff, get_select_list_item (&fake_select, updateCmd->where_clause->expr_str_u.sl_item));
	}
    }


  if (A4GL_compile_time_convert ())
    {
      ptr = A4GLSQLCV_check_sql (buff, converted);
    }
  else
    {
      ptr = buff;
    }
  return strdup (ptr);
}

static char *
get_delete_cmd (struct struct_delete_cmd *deleteCmd, int *converted)
{
  char topbuff[64000] = "";
  char smbuff[64000] = "";
  char *ptr;


  *converted = 0;

  sprintf (topbuff, "DELETE FROM %s", deleteCmd->table);

  if (deleteCmd->where_clause != NULL)
    {

      if (deleteCmd->where_clause->expr_type == ET_EXPR_WHERE_CURRENT_OF)
	{
	  //char buff[2000];
	  if (deleteCmd->where_clause->expr_str_u.expr_expr->expr_type == ET_EXPR_VARIABLE_IDENTIFIER)
	    {
	      //yylineno=line_for_cmd;
	      a4gl_yyerror ("You cant use a variable id in this position...");
	      return "<badsql>";
	    }
	  else
	    {
	      //printf("decode=%s\n", decode_e_expr_type(deleteCmd->where_clause->expr_str_u.expr_expr->expr_type));  
	      sprintf (smbuff, " WHERE CURRENT OF %s", deleteCmd->where_clause->expr_str_u.expr_expr->expr_str_u.expr_string);
	    }
	  /*
	     if (deleteCmd->where_clause->expr_str_u.expr_type==ET_EXPR_
	     ptr = A4GLSQLCV_check_sql (topbuff, converted);
	     strcpy(topbuff,buff);
	     sprintf(buff,
	     strcpy(topbuff,"_r");
	   */


	}
      else
	{
	  struct s_select fake_select;
	  struct s_select_list_item_list l;
	  struct s_table t;
	  fake_select.modifier = 0;
	  fake_select.limit.start = -1;
	  fake_select.limit.end = -1;
	  fake_select.limit.offset = -1;
	  fake_select.ncolumns = 0;
	  fake_select.select_list = 0;
	  fake_select.first = 0;
	  fake_select.table_elements.tables.tables_len = 0;
	  fake_select.table_elements.tables.tables_val = 0;
	  fake_select.group_by = 0;
	  fake_select.having = 0;
	  fake_select.list_of_items.list.list_len = 0;
	  fake_select.list_of_items.list.list_val = 0;
	  fake_select.where_clause = 0;
	  fake_select.next = 0;
	  fake_select.sf = 0;
	  fake_select.union_op = 0;
	  fake_select.into = 0;

	  fake_select.first = &t;

	  fake_select.first->tabname = deleteCmd->table;
	  fake_select.first->alias = fake_select.first->tabname;
	  fake_select.first->next = NULL;
	  fake_select.first->outer_next = NULL;
	  fake_select.first->outer_join_condition = NULL;
	  fake_select.table_elements.tables.tables_len = 0;
	  fake_select.table_elements.tables.tables_val = 0;

	  fake_select.where_clause = deleteCmd->where_clause->expr_str_u.sl_item;
	  fake_select.group_by = 0;
	  fake_select.next = 0;
	  fake_select.sf = 0;
	  fake_select.into = 0;
	  fake_select.union_op = 0;
	  fake_select.extra_statement = 0;
	  l.list.list_len = 0;
	  l.list.list_val = 0;
	  fake_select.select_list = &l;
	  A4GLSQLPARSE_from_clause_collect_tables (&fake_select, fake_select.first, &fake_select.table_elements);

	  preprocess_sql_statement (&fake_select);
	  search_sql_variables (&fake_select.list_of_items, 'i');

	  sprintf (smbuff, " WHERE %s", get_select_list_item (&fake_select, deleteCmd->where_clause->expr_str_u.sl_item));

	}
      strcat (topbuff, smbuff);
    }



  if (A4GL_compile_time_convert ())
    {
      ptr = A4GLSQLCV_check_sql (topbuff, converted);
    }
  else
    {
      ptr = topbuff;
    }
  return strdup (ptr);
}




static void
print_select (struct s_select *s, char *forUpdate)
{
  char *str;
  str = get_select (s, forUpdate);
  printc ("%s", escape_quotes_and_remove_nl (str, 1));
  free (str);
}


// This function is used by INSERT,UPDATE And DELETE to find any embedded variables usages (E_SLI_VARIABLE_USAGE)
// and replace them with proper variable subsitutions as required...
void
search_sql_variables (struct s_select_list_item_list *l, char dir)
{
  int a;
  if (l == 0)
    return;

  for (a = 0; a < l->list.list_len; a++)
    {
      check_for_variable (l->list.list_val[a], dir);
    }
}




static char *
get_sql_variable_usage (variable_usage * u, char dir)
{
  struct expr_str *e;
  int a;
  variable_usage *ub;
  ub=usage_bottom_level(u);

  if (ub->datatype==-2) {
	static char buff[20000]="";
	struct variable *v;
	v=local_find_variable_from_usage(u);
	if (v->var_data.variable_type==VARIABLE_TYPE_RECORD) {
		variable_usage *unew;
  		//variable_usage *ub2;

		for (a=0;a<v->var_data.variable_data_u.v_record.variables.variables_len;a++) {
			struct variable *v2;
			struct variable_usage *vn;
			struct variable_usage *u2;

			unew=clone_variable_usage(u);

			vn=new_variable_usage(0,v->var_data.variable_data_u.v_record.variables.variables_val[a]->names.names.names_val[0].name,0);
			u2=unew;
			while (u2->next!=0) {
				u2=u2->next;
			}
			u2->next=vn;
			v2=v->var_data.variable_data_u.v_record.variables.variables_val[a];

			if (v2->var_data.variable_type==VARIABLE_TYPE_SIMPLE) {
				int d1;
				d1=v2->var_data.variable_data_u.v_simple.datatype;
	
				d1+=ENCODE_SIZE(v2->var_data.variable_data_u.v_simple.dimensions[0]);
				//printf("---> %d\n", v2->var_data.variable_data_u.v_simple.datatype);	
				vn->datatype=d1;
			
				//printf("Datatype set to %d\n", vn->datatype);
			} else {
				a4gl_yyerror("Not simple");
			}
			if (strlen(buff)) {
				strcat(buff,",");
			}
			
			
			strcat(buff,strdup(get_sql_variable_usage(unew,dir)));
		}
	} else {
		a4gl_yyerror("Cant handle non-record & not expanded");
	}
	//printf("Returning : %s\n", buff);
	return buff;
  }


  e = A4GL_new_expr_push_variable (u, (current_report != NULL) || (current_pdf_report != NULL));

  switch (dir)
    {
    case 'i':
      A4GL_new_append_ptr_list (input_bind, e);
      a = input_bind->list.list_len - 1;
      break;
    case 'o':
      A4GL_new_append_ptr_list (output_bind, e);
      a = output_bind->list.list_len - 1;
      break;
    }



  return "?";
}



static void
check_for_variable (struct s_select_list_item *l, char dir)
{
char *ptr;
  switch (l->data.type)
    {
    case E_SLI_VARIABLE_USAGE:
      l->data.type = E_SLI_VARIABLE;
	ptr=get_sql_variable_usage (l->data.s_select_list_item_data_u.var_usage, dir);
      l->data.s_select_list_item_data_u.expression =
	strdup (ptr);
      return;
    case E_SLI_VARIABLE_USAGE_IN_SELECT_LIST:
      l->data.type = E_SLI_VARIABLE;
      //set_dont_use_indicators=1;
      l->data.s_select_list_item_data_u.expression =
	strdup (get_sql_variable_usage (l->data.s_select_list_item_data_u.var_usage, dir));
      //set_dont_use_indicators=0;
      return;

    case E_SLI_OP:
      check_for_variable (l->data.s_select_list_item_data_u.complex_expr.left, dir),
	check_for_variable (l->data.s_select_list_item_data_u.complex_expr.right, dir);
      return;

    case E_SLI_NOT_IN_SELECT:
    case E_SLI_IN_SELECT:
      check_for_variable (l->data.s_select_list_item_data_u.complex_expr.left, dir);
      return;

    case E_SLI_NOT_IN_VALUES:
    case E_SLI_IN_VALUES:
      check_for_variable (l->data.s_select_list_item_data_u.slil_expr.left, dir);
      search_sql_variables (l->data.s_select_list_item_data_u.slil_expr.right_list, dir);
      break;

    case E_SLI_REGEX_MATCHES:
    case E_SLI_REGEX_NOT_MATCHES:
    case E_SLI_REGEX_LIKE:
    case E_SLI_REGEX_NOT_LIKE:
    case E_SLI_REGEX_ILIKE:
    case E_SLI_REGEX_NOT_ILIKE:
      check_for_variable (l->data.s_select_list_item_data_u.regex.val, dir);
      check_for_variable (l->data.s_select_list_item_data_u.regex.regex, dir);
      break;

    case E_SLI_ISNULL:
    case E_SLI_ISNOTNULL:
    case E_SLI_ASC:
    case E_SLI_DESC:
    case E_SLI_NOT:
    case E_SLI_BRACKET_EXPR:
    case E_SLI_UNITS_YEAR:
    case E_SLI_UNITS_MONTH:
    case E_SLI_UNITS_DAY:
    case E_SLI_UNITS_HOUR:
    case E_SLI_UNITS_MINUTE:
    case E_SLI_UNITS_SECOND:
      check_for_variable (l->data.s_select_list_item_data_u.expr, dir);
      break;

    case E_SLI_BUILTIN_FUNC_YEAR:
    case E_SLI_BUILTIN_FUNC_MONTH:
    case E_SLI_BUILTIN_FUNC_DAY:
    case E_SLI_BUILTIN_FUNC_DOW:
    case E_SLI_BUILTIN_FUNC_WEEKDAY:
    case E_SLI_BUILTIN_FUNC_MDY:
    case E_SLI_BUILTIN_FUNC_DATE:
      search_sql_variables (l->data.s_select_list_item_data_u.builtin_fcall.params, dir);
      break;


    case E_SLI_BUILTIN_AGG_AVG:
    case E_SLI_BUILTIN_AGG_MAX:
    case E_SLI_BUILTIN_AGG_MIN:
    case E_SLI_BUILTIN_AGG_SUM:
    case E_SLI_BUILTIN_AGG_COUNT:
      check_for_variable (l->data.s_select_list_item_data_u.agg_expr.expr, dir);
      break;

    case E_SLI_NOT_BETWEEN:
    case E_SLI_BETWEEN:
      check_for_variable (l->data.s_select_list_item_data_u.between_expr.val, dir);
      check_for_variable (l->data.s_select_list_item_data_u.between_expr.from, dir);
      check_for_variable (l->data.s_select_list_item_data_u.between_expr.to, dir);
      break;


    case E_SLI_FCALL:
      search_sql_variables (l->data.s_select_list_item_data_u.fcall.params, dir);
      break;


    case E_SLI_EXTEND:
      check_for_variable (l->data.s_select_list_item_data_u.extend.expr, dir);
      break;

    case E_SLI_SUBQUERY_EXPRESSION:
      check_for_variable (l->data.s_select_list_item_data_u.sq_expression.sq, dir);
      break;

    case E_SLI_CAST_EXPR:
      check_for_variable (l->data.s_select_list_item_data_u.casting.expr, dir);
      break;




    default:
      break;

    }


}




static char *
local_get_namespace_internal (char *s)
{
 if (isReport) return "thisApp.";
  return "";
}


static enum e_scope
get_var_expr_scope (struct expr_str *p)
{
  struct variable_usage *u;

  if (p->expr_type != ET_EXPR_VARIABLE_USAGE)
    {
      A4GL_assertion (1, "Should be ET_EXPR_VARIABLE_USAGE");
    }
  u = p->expr_str_u.expr_variable_usage;
  return u->escope;

}


int
get_binding_dtype (expr_str * e)
{
  struct variable_usage *u;


  switch (e->expr_type)
    {
    case ET_EXPR_PARAMETER:
      A4GL_assertion (1, "Should have been expanded away...");
      break;

    case ET_EXPR_VARIABLE_USAGE_WITH_ASC_DESC:
      // If this assert fails - we've not found the variable previously and
      // the datatype isnt set :-(
      u = e->expr_str_u.expr_variable_usage_with_asc_desc->var_usage;
      u = usage_bottom_level (u);
      if (u->datatype < 0)
	{
	  set_yytext (generation_get_variable_usage_as_string (u));
	  a4gl_yyerror ("Invalid variable usage (1)");
	  return 0;
	}
      //A4GL_assertion(u->datatype<0,"Invalid datatype") ;
      return u->datatype;


    case ET_EXPR_VARIABLE_USAGE:
      // If this assert fails - we've not found the variable previously and
      // the datatype isnt set :-(
      u = e->expr_str_u.expr_variable_usage;
      u = usage_bottom_level (u);
      if (u->datatype < 0)
	{
	  set_yytext (generation_get_variable_usage_as_string (u));
		printf("dtype=%d\n", u->datatype);
	  a4gl_yyerror ("Invalid variable usage (2) ");
	  return 0;
	}
      A4GL_assertion (u->datatype < 0, "Invalid datatype");
      return u->datatype;

    case ET_EXPR_LITERAL_EMPTY_STRING:
      return DTYPE_CHAR + ENCODE_SIZE (1);

    case ET_E_V_OR_LIT_STRING:
    case ET_EXPR_LITERAL_STRING:
      // Can happen on a PUT  - but its never a substring...
      return DTYPE_CHAR + ENCODE_SIZE (strlen (e->expr_str_u.expr_string));

    case ET_EXPR_NULL:
      // Can happen on a PUT  - but its never a substring...
      return DTYPE_CHAR + ENCODE_SIZE (1);

    case ET_EXPR_LITERAL_LONG:
      return 2;

    default:
      A4GL_assertion (1, "Not implemented");
    }
  return 0;

}





void
set_suppress_lines (char *why)
{
  suppress_lines++;
}

void
clr_suppress_lines (void)
{
  suppress_lines--;
}



static int
need_daylight (void)
{
  if (daylight)
    return 0;
  printc ("#");

  return 1;
}


static char *
decode_event_id (e_event i)
{


  switch (i)
    {
    case EVENT_BEF_ROW:
      return "BEFORE ROW";
    case EVENT_AFT_ROW:
      return "AFTER ROW";
    case EVENT_BEFORE_DELETE:
      return "BEFORE DELETE";
    case EVENT_AFTER_DELETE:
      return "AFTER DELETE";
    case EVENT_BEFORE_INSERT:
      return "BEFORE INSERT";
    case EVENT_AFTER_INSERT:
      return "AFTER INSERT";
    case EVENT_BEFORE_INSERT_DELETE:
      return "BEFORE_INSERT_DELETE";
    case EVENT_AFTER_INSERT_DELETE:
      return "AFTER_INSERT_DELETE";
    case EVENT_ANYKEY_PRESS:
      return "ANYKEY";
    case EVENT_ON_IDLE:
      return "ON IDLE";
    case EVENT_ON_INTERVAL:
      return "ON INTERVAL";
    case EVENT_ON_TIME:
      return "ON TIMER";
    case EVENT_KEY_PRESS:
      return "KEYPRESS";
    case EVENT_ON_ACTION:
      return "ON ACTION";

    case EVENT_AFTER_INPUT:
      return "AFTER INPUT";
    case EVENT_BEFORE_INPUT:
      return "BEFORE INPUT";

    case EVENT_AFTER_DISPLAY:
      return "AFTER DISPLAY";
    case EVENT_BEFORE_DISPLAY:
      return "BEFORE DISPLAY";
    case EVENT_AFTER_CONSTRUCT:
      return "AFTER CONSTRUCT";
    case EVENT_BEFORE_CONSTRUCT:
      return "BEFORE CONSTRUCT";
    case EVENT_BEFORE_MENU:
      return "BEFORE MENU";

    case EVENT_BEFORE_FIELD:
      return "BEFORE FIELD";
    case EVENT_AFTER_FIELD:
      return "AFTER FIELD";
    case EVENT_MENU_COMMAND:
      return "COMMAND";

    default:
      return "Other";

    }

  A4GL_assertion (1, "UNKNOWN event ID");
  return "";

}

static char *compiling_module(void) {
	return curr_module->module_name;
}

char *
get_ident (struct expr_str *ptr,int prefixWithModuleName)
{

if (prefixWithModuleName) {
  if (ptr->expr_type == ET_EXPR_IDENTIFIER)
    {
	static char buff[2000];
	sprintf(buff,"%s_%s", cleaned_fname (compiling_module ()),ptr->expr_str_u.expr_string);
	return buff;
    }

  if (ptr->expr_type == ET_EXPR_VARIABLE_IDENTIFIER)
    {
      return local_expr_as_string (ptr->expr_str_u.expr_expr);
    }

  if (ptr->expr_type == ET_EXPR_VARIABLE_USAGE)
    {
      return generation_get_variable_usage (ptr);
    }
} else {
  if (ptr->expr_type == ET_EXPR_IDENTIFIER)
    {
      return ptr->expr_str_u.expr_string;
    }

  if (ptr->expr_type == ET_EXPR_VARIABLE_IDENTIFIER)
    {
      return local_expr_as_string (ptr->expr_str_u.expr_expr);
    }

  if (ptr->expr_type == ET_EXPR_VARIABLE_USAGE)
    {
      return generation_get_variable_usage (ptr);
    }
}


  return "UNKNOWN GET_IDENT";

}


char *
generation_get_variable_usage (struct expr_str *ptr)
{

  if (ptr->expr_type == ET_EXPR_VARIABLE_USAGE)
    {

      return check_name (generation_get_variable_usage_as_string (ptr->expr_str_u.expr_variable_usage));
    }

  if (ptr->expr_type==ET_EXPR_LITERAL_STRING) {
	static char buff[12000];
	static char buff2[12000];
	strcpy(buff,local_expr_as_string(ptr));
	if (buff[0]=='"') return buff;
	sprintf(buff2,"\"%s\"",buff);
	//printf("---->%s\n", buff2);
	return buff2;
	
	
  }
  if (ptr->expr_type==ET_EXPR_LITERAL_EMPTY_STRING) {
		return "\"\"";
  }

  printf("--->%s\n",expr_name(ptr->expr_type));

  A4GL_assertion (1, "Not a variable usage...");
  return NULL;
}

char * generation_get_variable_usage_as_string (struct variable_usage *u)
{
  static char rbuff[2000];
  int substring = 0;
  char buff[2000];
  expr_str *substring_start;
  expr_str *substring_end;



  substring = is_substring_variable_usage (u, &substring_start, &substring_end);
  if (u->escope == 0)
    u->escope = E_SCOPE_LOCAL;

/*
  if (substring)
    {
      A4GL_assertion (1, "Cant use a substring here");
      printc ("A4GL_push_substr(");
    }
*/

//printf("u->variable_name =%s ... %d\n", u->variable_name, u->escope);
  strcpy (buff, "");
  while (u)
    {
      if (strlen (buff) == 0)
	{
	  char name[2000];
	  strcpy (name, u->variable_name);

	if (u->escope==E_SCOPE_LOCAL) {
	  strcpy (buff, name);
	}  else {
		if (u->escope==E_SCOPE_MODULE) {
			sprintf(buff,"GLOBALS['M_%s']['%s']",cleaned_name (curr_module->module_name), name);
		} else {
			sprintf(buff,"GLOBALS['%s']", name);
		}
	}

	}
      else
	{
	char buff2[3000];
		sprintf(buff2,"['%s']", u->variable_name);
	  strcat (buff, buff2);
	}

      if (u->subscripts.subscripts_len)
	{
	  int a;
	int dt;
	  strcat (buff, "[");

	  for (a = 0; a < u->subscripts.subscripts_len; a++)
	    {
	      if (a)
		strcat (buff, ",");


 		if (u->subscripts.subscripts_val[a]->expr_type==ET_EXPR_LITERAL_LONG) {
			char smbuff[200];
			sprintf(smbuff,"%ld",  u->subscripts.subscripts_val[a]->expr_str_u.expr_long - 1);
	        	strcat (buff, smbuff);

		} else {
	  		dt=expr_datatype(0,0,u->subscripts.subscripts_val[a])&DTYPE_MASK;
			/*
			if (dt==DTYPE_INT||dt==DTYPE_SMINT) {
				strcat(buff,""); // Needed to convert from int? to int
			} else {
				strcat(buff,"");
			}
			*/
	        	strcat (buff, local_expr_as_string (u->subscripts.subscripts_val[a]));
			strcat(buff,"-1");
		}
	    }
	  strcat (buff, "]");
	}
      if (u->next == 0)
	break;


      //strcat (buff, ".");

      u = u->next;
    }

  	strcpy (rbuff, buff);

//printf("RBUFF=%s\n",rbuff);

  return strdup (rbuff);
}


/**
 * Open the ouput target C file
 */
static void
open_outfile (void)
{
  char filename_for_h[132];
  char filename_for_c[132];
  char err[132];
  char *outputfilename;
  char *override;
  override = acl_getenv_not_set_as_0 ("OVERRIDE_OUTPUT");


  outputfilename = curr_module->module_name;

  if (outputfilename == 0)
    {
      A4GL_debug ("NO output file name");
    }

  if (!A4GL_env_option_set ("A4GL_LOCALOUTPUT"))
    {
      strcpy (filename_for_c, outputfilename);
      strcpy (filename_for_h, outputfilename);
      strcpy (err, outputfilename);
      ofilename = strdup (outputfilename);
    }
  else
    {
      char *ptr;
      // Local output will strip any directory from the output
      // files and create them in the local directory instead...
      ptr = outputfilename;
      if (rindex (ptr, '/'))
	{
	  ptr = rindex (ptr, '/') + 1;
	}
      strcpy (filename_for_c, ptr);
      strcpy (filename_for_h, ptr);
      strcpy (err, ptr);
      ofilename = strdup (ptr);
    }


  if (strcmp (acl_getenv ("A4GL_NOCLOBBER"), "N") == 0)
    {
      A4GL_debug ("Clobbering...");
      A4GL_set_clobber (outputfilename);
    }

  A4GL_debug ("Opening output map");

  /* openmap (outputfilename); */

  A4GL_debug ("nocfile = %s\n", acl_getenv ("A4GL_NOCFILE"));

  if (A4GL_isyes (acl_getenv ("A4GL_NOCFILE")))
    {
      A4GL_debug (">>> NO C FILES... ");
      return;
    }

  A4GL_debug ("Opening output map");

  strcpy (filename_outfile, filename_for_c);
  strcat (filename_outfile, ".php");


  if (curr_module->moduleIsInLibrary)
    {
      char buff[2000];
      sprintf (buff, "F%s", filename_outfile);
      strcpy (filename_outfile, buff);
    }

  if (override)
    {
      strcpy (filename_outfile, override);
    }

  strcat (filename_for_c, "_code.php");
  strcat (filename_for_h, "_structs.php");

  strcat (err, ".err");



  strcpy (filename_cfile, filename_for_c);
  outfile = A4GL_mja_fopen (filename_for_c, "wb");
  if (outfile == 0)
    {
      printf ("Unable to open file %s (Check permissions)\n", filename_for_c);
      exit (3);
    }

  A4GL_debug ("Output file is %s", filename_for_c);

  sprintf (cmodname, "%s.4gl", outputfilename);


  strcpy (filename_hfile, filename_for_h);


  hfile = A4GL_mja_fopen (filename_for_h, "wb");
  if (hfile == 0)
    {
      printf ("Unable to open file %s (Check permissions)\n", filename_for_h);
      exit (3);
    }
  thisClass = acl_getenv_not_set_as_0 ("THISCLASS");
  if (thisClass == 0)
    {
      thisClass = "Simple";
    }

  //fprintf(hfile, "using IBM.Data.Informix;\n");
  //fprintf(hfile, "public partial class FglModule {\n");

}


/**
 * Print the instructions to be generated to the target C file.
 *
 * If the INCLINES environment/config variable is set then the source target C
 * file is generated with #line (for debugging purposes).
 *
 * If the output file is not opened, call the open function.
 *
 * @param fmt the format to be passed to vSPRINTF
 * @param ... The variadic parameters to be passed to vSPRINTF
 */
/* cannot be static since it's called from compile_c_gtk.c. How do I make*/
/* it to be accessible only form libLEX_ ? LIBPRIVATE ?*/
void
printc (char *fmt, ...)
{
  va_list ap;
  /*A4GL_debug("via printc (a) in lib\n"); */


  va_start (ap, fmt);
  A4GL_internal_lex_printc (fmt, &ap);
}


void
printc_safe_to_split_at_comma (char *fmt, ...)
{
  int a;
  va_list ap;
  va_start (ap, fmt);
  static char buff[40960] = "ERROR-empty init";
  char *ptr;
  int l;
  va_start (ap, fmt);
  vsnprintf (buff, sizeof (buff), fmt, ap);
  set_nonewlines ();
  ptr = buff;
  l = strlen (buff);
  for (a = 0; a < l; a++)
    {
      if (buff[a] == ',')
	{
	  buff[a] = 0;
	  printc ("%s,", ptr);
	  a++;
	  ptr = &buff[a];
	}
    }
  printc ("%s", ptr);
  clr_nonewlines ();

}



void A4GL_internal_lex_printc (char *fmt, va_list * ap)
{
  static char buff[40960] = "ERROR-empty init";
  //static char buff2[40960];
  char *ptr;
  //int a;
  int os;
  static int ln = 0;

  daylight = 0;

  if (outfile == 0)
    {
      open_outfile ();
      if (outfile == 0)
	return;
    }

  os = vsnprintf (buff, sizeof (buff), fmt, *ap);

  if (os >= sizeof (buff))
    {
      a4gl_yyerror ("Internal error - string too big\n");
      exit (0);
    }



  ptr = strtok (buff, "\n");
  while (ptr)
    {
      if (!nonewlines)
	{
	  if (strcmp (ptr, "#") == 0)
	    {
	      ln = 0;
	      daylight++;
	      if (outfile)
		FPRINTF (outfile, "\n");
	    }
	  else
	    {
	      print_space ();
	      if (outfile)
		FPRINTF (outfile, "%s\n", ptr);
	      ln = 0;
	    }
	}
      else
	{
	  if (strcmp (ptr, "#") == 0);
	  else
	    {


	      ln += strlen (ptr);
	      if (ln > 80)
		{
		  if (outfile)
		    FPRINTF (outfile, "\n");
		  print_space ();
		  if (outfile)
		    FPRINTF (outfile, "   ");
		  ln = 3;
		}

	      if (outfile) {


	//if (dbgmode) {fprintf(outfile,">>",ptr);}
		//fwrite(outfile, strlen(ptr),1, ptr);
		fwrite(ptr,  strlen(ptr),1, outfile);

	//if (dbgmode) {fprintf(outfile,"<<",ptr);}
		}

	    }
	}
      ptr = strtok (0, "\n");
    }

  /* Having this will really slow it down - only enable it if we are debugging... */
  if (strcmp (acl_getenv ("DEBUG"), "ALL") == 0)
    {
      fflush (outfile);
    }
}


/**
 * Print the generated definitions to the target header file (.h)
 *
 * If the output file is not opened call the open function.
 *
 * @param fmt the format to be passed to vSPRINTF
 * @param ... The variadic parameters to be passed to vSPRINTF
 */
void
printh (char *fmt, ...)
{
  va_list ap;
  va_start (ap, fmt);
  A4GL_internal_lex_printh (fmt, &ap);
}

void A4GL_internal_lex_printh (char *fmt, va_list * ap)
{
/* va_list args; */
  if (outfile == 0)
    {
      open_outfile ();
    }
  if (outfile == 0)
    return;

  if (hfile)
    VFPRINTF (hfile, fmt, *ap);

}




static void
print_unload_cmd (struct_unload_cmd * cmd_data)
{
  A4GL_assertion (1, "Not implemented yet");
}

static void
print_load_cmd (struct_load_cmd * cmd_data)
{
  A4GL_assertion (1, "Not implemented yet");
}










static char *
explicitCastFunction (int targetDtype)
{
  static char buff[2000];
int dorig;

  dorig=targetDtype>>16;

  targetDtype = targetDtype & DTYPE_MASK;

  switch (targetDtype)
    {
    case DTYPE_INT:
      return "/*ecf*/ AsInt";
    case DTYPE_SMINT:
      return "/*ecf2*/ AsInt";
    case DTYPE_DATE:
      return "AsDate";
    case DTYPE_FLOAT:
      return "AsFloat";
    case DTYPE_SMFLOAT:
      return "AsSmallFloat";
    case DTYPE_CHAR:
      return "AsString";
    case DTYPE_SERIAL:
      return "/*ecf3*/ AsInt";
    case DTYPE_DECIMAL:
      return "AsDecimal";
    case DTYPE_MONEY:
      return "AsMoney";
    case DTYPE_DTIME:
      return "AsDateTime";
    case DTYPE_INTERVAL:
		if (((dorig >> 4) & 0xf) <= 2) {
      			return "AsMonthSpan";
		} else {
      			return "AsTimeSpan";
		}
    case 90:
      return "AsBool";

    }

  sprintf (buff, "As%d", targetDtype);

  return buff;
}



#ifdef IN_EXPR
void real_print_expr (struct expr_str *ptr)
{
  int a;
  A4GL_debug ("Print expr... %p", ptr);

  A4GL_assertion (ptr == 0, "can't print a null pointer...");

  switch (ptr->expr_type)
    {
      // These will never be implemented - because they dont make sense..
    case ET_EXPR_REDUCED:
      A4GL_assertion (1, "ET_EXPR_REDUCED should never be printed");
      break;
    case ET_EXPR_LAST:
      A4GL_assertion (1, "ET_EXPR_LAST should never be printed");
      break;
    case ET_EXPR_EXPR_LIST:
      A4GL_assertion (1, "ET_EXPR_EXPR_LIST can't be printed - print using A4GL_print_expr_list or A4GL_print_expr_list_concat");
      break;

    case ET_EXPR_WORDWRAP:
      // Wordwraps shouldn't be printed - in the report_print - the wrapped expression should be printed...
      A4GL_assertion (1, "ET_EXPR_WORDWRAP should never be printed");
      break;


      // These should be implemented - but aren't yet... 
    case ET_EXPR_EXTERNAL:
      A4GL_assertion (1, "ET_EXPR_EXTERNAL has not been implented as an expression yet");
      break;

    case ET_EXPR_OP_IN:
      real_print_expr (ptr->expr_str_u.expr_in->expr);
      printc ("IN (");
      for (a = 0; a < ptr->expr_str_u.expr_in->elist->list.list_len; a++)
	{
	  if (a)
	    printc (",");
	  real_print_expr (ptr->expr_str_u.expr_in->elist->list.list_val[a]);
	}
      printc (")");
      break;

    case ET_EXPR_OP_NOT_IN:
      real_print_expr (ptr->expr_str_u.expr_in->expr);
      printc ("NOT IN (");
      for (a = 0; a < ptr->expr_str_u.expr_in->elist->list.list_len; a++)
	{
	  if (a)
	    {
	      printc (",");
	    }
	  real_print_expr (ptr->expr_str_u.expr_in->elist->list.list_val[a]);
	}
      printc (")");
      break;


    case ET_EXPR_NOT_EXISTS_SUBQUERY:
      print_exists_subquery (0, ptr->expr_str_u.expr_exists_sq);
      break;
    case ET_EXPR_EXISTS_SUBQUERY:
      print_exists_subquery (1, ptr->expr_str_u.expr_exists_sq);
      break;
    case ET_EXPR_OP_NOTIN_SUBQUERY:
      print_in_subquery (0, ptr->expr_str_u.expr_in_sq);
      break;
    case ET_EXPR_OP_IN_SUBQUERY:
      print_in_subquery (1, ptr->expr_str_u.expr_in_sq);
      break;

    case ET_EXPR_STRING:
      printc ("%s", ptr->expr_str_u.expr_string);
      free (ptr->expr_str_u.expr_string);
      break;






    case ET_EXPR_TIME:
      printc ("TIME");
      break;
    case ET_EXPR_NULL:
      printc ("NULL");
      break;
    case ET_EXPR_TRUE:
      printc ("true");
      break;
    case ET_EXPR_FALSE:
      printc ("false");
      break;
    case ET_EXPR_NOT:
      printc ("!(");
      real_print_expr (ptr->expr_str_u.expr_expr);
      printc (")");
      break;

    case ET_EXPR_NEG:
      printc ("(0-");
      real_print_expr (ptr->expr_str_u.expr_expr);
      printc (")");
      break;
    case ET_EXPR_UPSHIFT:
      printc ("Upshift(");
      real_print_expr (ptr->expr_str_u.expr_expr);
      printc (")");
      break;
    case ET_EXPR_DOWNSHIFT:
      printc ("Downshift(");
      real_print_expr (ptr->expr_str_u.expr_expr);
      printc (")");
      break;

    case ET_EXPR_DATE_EXPR:
      printc ("DATE()");
      break;
    case ET_EXPR_COLUMN:
      printc ("COLUMN ");
      real_print_expr (ptr->expr_str_u.expr_expr);
      break;
    case ET_EXPR_TIME_EXPR:
      printc ("TIME");
      break;
    case ET_EXPR_TODAY:
      A4GL_warn ("Coding Standards: Use of builtin TODAY variable");
      printc ("SQLToday()");
      break;

    case ET_EXPR_ASCII:
      printc ("Ascii(");
      real_print_expr (ptr->expr_str_u.expr_expr);
      printc (")");
      break;
    case ET_EXPR_EXTEND:
      printc ("Extend(");
      real_print_expr (ptr->expr_str_u.expr_extend->expr);
      printc (",\"%s\")", decode_extend (ptr->expr_str_u.expr_extend->to));
      break;



    case ET_EXPR_AGGREGATE:
      {
	printc ("_g%d.getValue()", ptr->expr_str_u.expr_agg->expr_num);
	//struct  s_expr_agg           *expr_agg;
	//printc ("AGG");
      }
      break;



    case ET_EXPR_MM:
      A4GL_assertion (1, "Not implemented");
      break;

    case ET_EXPR_INCHES:
      A4GL_assertion (1, "Not implemented");
      break;
    case ET_EXPR_POINTS:
      A4GL_assertion (1, "Not implemented");
      break;

    case ET_EXPR_PAGENO:
      printc ("PAGENO");

      //printc ("A4GL_push_variable(&_rep.page_no,2);");
      break;
    case ET_EXPR_LINENO:
      printc ("LINENO");
      //printc ("{static int _ln; _ln=_rep.line_no-1;A4GL_push_variable(&_ln,2);}");
      break;

    case ET_EXPR_FCALL:

      {
	//int a;
	int b;
	//char lib[255];
	int params;
	struct expr_str_list *l;
	b = 0;

	if (ptr)
	  {
	    l = ptr->expr_str_u.expr_function_call->parameters;
	    l = A4GL_rationalize_list (l);
	    /*
	       if (l)
	       {
	       for (a = 0; a < l->nlist; a++)
	       {
	       real_print_expr (l->list[a]);
	       }
	       }
	     */
	  }

	params = A4GL_new_list_get_count (ptr->expr_str_u.expr_function_call->parameters);
	ensure_parameters (ptr->expr_str_u.expr_function_call->functionname, ptr->expr_str_u.expr_function_call->parameters);
	printc ("%s%s(", local_get_namespace_internal (ptr->expr_str_u.expr_function_call->functionname),
		map_fname (ptr->expr_str_u.expr_function_call->functionname));
	real_print_expr_list_with_separator (ptr->expr_str_u.expr_function_call->parameters, ",");
	printc (") ");

	add_function_to_header (ptr->expr_str_u.expr_function_call->functionname, 1, "");
      }
      break;


    case ET_EXPR_SHARED_FCALL:
      A4GL_assertion (1, "Not implemented");
      break;

    case ET_EXPR_BOUND_FCALL:
      A4GL_assertion (1, "Not implemented");
      break;


    case ET_EXPR_MEMBER_FCALL_NEW:
      A4GL_assertion (1, "Not implemented");
      break;

    case ET_EXPR_REPORT_PRINTER:
      printc ("A4GL_push_char(acl_getenv(\"DBPRINT\"));");
      break;
    case ET_EXPR_REPORT_EMAIL:
      printc ("A4GL_push_char(A4GL_get_tmp_rep(_module_name,\"%s\"));", ptr->expr_str_u.expr_string);
      break;


    case ET_EXPR_LITERAL_LONG:
      printc ("%ld", ptr->expr_str_u.expr_long);
      break;
    case ET_EXPR_LITERAL_STRING:
      if (ptr->expr_str_u.expr_string[0] == '"')
	{
	  printc ("%s", ptr->expr_str_u.expr_string);
	}
      else
	{
	  printc ("\"%s\"", ptr->expr_str_u.expr_string);
	}
      break;
    case ET_EXPR_QUOTED_STRING:
      printc ("%s;", ptr->expr_str_u.expr_string);
      break;
    case ET_EXPR_LITERAL_DOUBLE_STR:
      printc ("%s", ptr->expr_str_u.expr_string);
      break;
    case ET_EXPR_OP_CLIP:

      set_nonewlines ();
	printc("TrimEnd(");
	ensure_dtype(0,0,ptr->expr_str_u.expr_expr,DTYPE_CHAR,0);
      	real_print_expr (ptr->expr_str_u.expr_expr);
      	printc (")");
      clr_nonewlines ();
      break;

    case ET_EXPR_OP_ISNULL:
	if (expr_datatype(0,0,ptr->expr_str_u.expr_expr)==90) {
		printc ("false /* FGLCHECK: Ignore 'IS NULL' check on boolean */");
		
	      //a4gl_yyerror ("Can't use IS NULL or IS NOT NULL on a boolean");
	} else {
      		printc ("IsNull(");
      		real_print_expr (ptr->expr_str_u.expr_expr);
      		printc (")");
	}
      break;

    case ET_EXPR_OP_ISNOTNULL:
	if (expr_datatype(0,0,ptr->expr_str_u.expr_expr)==90) {
		printc ("true /* FGLCHECK: Ignore IS NOT NULL check on boolean */");
	      //a4gl_yyerror ("Can't use IS NULL or IS NOT NULL on a boolean");
	} else {
      		printc ("IsNotNull(");
      		real_print_expr (ptr->expr_str_u.expr_expr);
      		printc (") /*IsNotNull*/");
	}
      break;
    case ET_EXPR_OP_MATCHES:
      printc (" Matches(");
      real_print_expr (ptr->expr_str_u.expr_op->left);
      printc (",");
      real_print_expr (ptr->expr_str_u.expr_op->right);

      if (ptr->expr_str_u.expr_op->escape)
	{
	  printc (",");
	  real_print_expr (ptr->expr_str_u.expr_op->escape);
	}
      else
	{
	}
      printc (")");
      break;

    case ET_EXPR_OP_NOT_MATCHES:
      printc (" NotMatches(");
      real_print_expr (ptr->expr_str_u.expr_op->left);
      printc (" /*<- matches_left */");
      printc (",");
      real_print_expr (ptr->expr_str_u.expr_op->right);
      printc (" /*<- matches_right */");
      if (ptr->expr_str_u.expr_op->escape)
	{
	  printc (" , ");
	  real_print_expr (ptr->expr_str_u.expr_op->right);
	}
      else
	{
	}
      printc (") /* NotMatches */");
      break;

/*
	case ET_EXPR_PROMPT_RESULT:
	  A4GL_assertion (1, "Prompt Result not required here..");
	  break;
*/

    case ET_EXPR_OP_LIKE:
      printc ("(");
      real_print_expr (ptr->expr_str_u.expr_op->left);
      printc (" LIKE ");
      real_print_expr (ptr->expr_str_u.expr_op->right);
      if (ptr->expr_str_u.expr_op->escape)
	{
	  printc (" ESCAPE ");
	  real_print_expr (ptr->expr_str_u.expr_op->right);
	}
      else
	{
	}
      printc (")");
      break;


    case ET_EXPR_OP_NOT_LIKE:
      printc ("(");
      real_print_expr (ptr->expr_str_u.expr_op->left);
      printc (" LIKE ");
      real_print_expr (ptr->expr_str_u.expr_op->right);
      if (ptr->expr_str_u.expr_op->escape)
	{
	  printc (" ESCAPE ");
	  real_print_expr (ptr->expr_str_u.expr_op->right);
	}
      else
	{
	  printc ("A4GL_push_char(\"\\\\\");");
	}
      printc (")");
      break;



    case ET_EXPR_OP_ADD:
      	if (isCharExpr( ptr->expr_str_u.expr_op->left)) { ensure_dtype(0,0,ptr->expr_str_u.expr_op->left, DTYPE_FLOAT,1); printc("/* FGLCHECK: Maths on Strings */");}
      	if (isCharExpr( ptr->expr_str_u.expr_op->right)) { ensure_dtype(0,0,ptr->expr_str_u.expr_op->right, DTYPE_FLOAT,1); printc("/* FGLCHECK: Maths on Strings */");}
      printc ("(");
      real_print_expr (ptr->expr_str_u.expr_op->left);
      printc ("+");
      real_print_expr (ptr->expr_str_u.expr_op->right);
      printc (")");
      break;
    case ET_EXPR_OP_SUB:
      	if (isCharExpr( ptr->expr_str_u.expr_op->left)) { ensure_dtype(0,0,ptr->expr_str_u.expr_op->left, DTYPE_FLOAT,1); printc("/* FGLCHECK: Maths on Strings */");}
      	if (isCharExpr( ptr->expr_str_u.expr_op->right)) { ensure_dtype(0,0,ptr->expr_str_u.expr_op->right, DTYPE_FLOAT,1); printc("/* FGLCHECK: Maths on Strings */");}
      printc ("(");
      real_print_expr (ptr->expr_str_u.expr_op->left);
      printc ("-");
      real_print_expr (ptr->expr_str_u.expr_op->right);
      printc (")");
      break;
    case ET_EXPR_OP_DIV:
      	if (isCharExpr( ptr->expr_str_u.expr_op->left)) { ensure_dtype(0,0,ptr->expr_str_u.expr_op->left, DTYPE_FLOAT,1); printc("/* FGLCHECK: Maths on Strings */");}
      	if (isCharExpr( ptr->expr_str_u.expr_op->right)) { ensure_dtype(0,0,ptr->expr_str_u.expr_op->right, DTYPE_FLOAT,1); printc("/* FGLCHECK: Maths on Strings */");}
      printc ("(");
      real_print_expr (ptr->expr_str_u.expr_op->left);
      printc ("/");
      real_print_expr (ptr->expr_str_u.expr_op->right);
      printc (")");
      break;

    case ET_EXPR_OP_MULT:
      	if (isCharExpr( ptr->expr_str_u.expr_op->left)) { ensure_dtype(0,0,ptr->expr_str_u.expr_op->left, DTYPE_FLOAT,1); printc("/* FGLCHECK: Maths on Strings */");}
      	if (isCharExpr( ptr->expr_str_u.expr_op->right)) { ensure_dtype(0,0,ptr->expr_str_u.expr_op->right, DTYPE_FLOAT,1); printc("/* FGLCHECK: Maths on Strings */");}
      printc ("(");
      real_print_expr (ptr->expr_str_u.expr_op->left);
      printc ("*");
      real_print_expr (ptr->expr_str_u.expr_op->right);
      printc (")");
      break;


    case ET_EXPR_OP_LESS_THAN:
      if (isCharExpr( ptr->expr_str_u.expr_op->left) || isCharExpr( ptr->expr_str_u.expr_op->right)) 
	{
	  // String comparison..
	  printc ("CompareString(");
	  //ensure_dtype(0,0,ptr->expr_str_u.expr_op->left,DTYPE_CHAR,0);
	  //ensure_dtype(0,0,ptr->expr_str_u.expr_op->right,DTYPE_CHAR,0);
	  real_print_expr (ptr->expr_str_u.expr_op->left);
	  printc (",");
	  real_print_expr (ptr->expr_str_u.expr_op->right);
	  printc (",");
	  printc ("\"<\"");
	  printc (")");
	}
      else
	{
	  printc ("(");
	  real_print_expr (ptr->expr_str_u.expr_op->left);
	  printc (" < ");
	  real_print_expr (ptr->expr_str_u.expr_op->right);
	  printc (")");
	}
      break;

    case ET_EXPR_OP_GREATER_THAN:
      if (isCharExpr( ptr->expr_str_u.expr_op->left) || isCharExpr( ptr->expr_str_u.expr_op->right)) 
	{
	  // String comparison..
	  printc ("CompareString(");
	  real_print_expr (ptr->expr_str_u.expr_op->left);
	  printc (",");
	  real_print_expr (ptr->expr_str_u.expr_op->right);
	  printc (",");
	  printc ("\">\"");
	  printc (")");
	}
      else
	{
	  printc ("(");
	  real_print_expr (ptr->expr_str_u.expr_op->left);
	  printc (" > ");
	  real_print_expr (ptr->expr_str_u.expr_op->right);
	  printc (")");
	}
      break;
    case ET_EXPR_OP_EQUAL:
      if (isCharExpr( ptr->expr_str_u.expr_op->left) || isCharExpr( ptr->expr_str_u.expr_op->right)) 
	{
	  // String comparison..
	  printc ("CompareString(");
	  real_print_expr (ptr->expr_str_u.expr_op->left);
	  printc (",");
	  real_print_expr (ptr->expr_str_u.expr_op->right);
	  printc (",");
	  printc ("\"=\"");
	  printc (")");
	}
      else
	{
	  printc ("(");
	  real_print_expr (ptr->expr_str_u.expr_op->left);
	  printc ("==");
	  real_print_expr (ptr->expr_str_u.expr_op->right);
	  printc (")");
	}
      break;
    case ET_EXPR_OP_NOT_EQUAL:
      if (isCharExpr( ptr->expr_str_u.expr_op->left) || isCharExpr( ptr->expr_str_u.expr_op->right)) 
	{
	  // String comparison..
	  printc ("CompareString(");
	  real_print_expr (ptr->expr_str_u.expr_op->left);
	  printc (",");
	  real_print_expr (ptr->expr_str_u.expr_op->right);
	  printc (",");
	  printc ("\"!=\"");
	  printc (")");
	}
      else
	{
	  printc ("(");
	  real_print_expr (ptr->expr_str_u.expr_op->left);
	  printc (" != ");
	  real_print_expr (ptr->expr_str_u.expr_op->right);
	  printc (")");
	}
      break;
    case ET_EXPR_OP_LESS_THAN_EQ:
      if (isCharExpr( ptr->expr_str_u.expr_op->left) || isCharExpr( ptr->expr_str_u.expr_op->right)) 
	{
	  // String comparison..
	  printc ("CompareString(");
	  real_print_expr (ptr->expr_str_u.expr_op->left);
	  printc (",");
	  real_print_expr (ptr->expr_str_u.expr_op->right);
	  printc (",");
	  printc ("\"<=\"");
	  printc (")");
	}
      else
	{
	  printc ("(");
	  real_print_expr (ptr->expr_str_u.expr_op->left);
	  printc (" <= ");
	  real_print_expr (ptr->expr_str_u.expr_op->right);
	  printc (")");
	}
      break;

    case ET_EXPR_OP_GREATER_THAN_EQ:
      if (isCharExpr( ptr->expr_str_u.expr_op->left) || isCharExpr( ptr->expr_str_u.expr_op->right)) 
	{
	  // String comparison..
	  printc ("CompareString(");
	  real_print_expr (ptr->expr_str_u.expr_op->left);
	  printc (",");
	  real_print_expr (ptr->expr_str_u.expr_op->right);
	  printc (",");
	  printc ("\">=\"");
	  printc (")");
	}
      else
	{
	  printc ("(");
	  real_print_expr (ptr->expr_str_u.expr_op->left);
	  printc (" >= ");
	  real_print_expr (ptr->expr_str_u.expr_op->right);
	  printc (")");
	}
      break;

    case ET_EXPR_OP_OR:

      //if (ptr->expr_str_u.expr_op->left->expr_type!=ptr->expr_str_u.expr_op->right->expr_type) {
      //printc ("( ", ptr->expr_str_u.expr_op->left->expr_type, ptr->expr_str_u.expr_op->right->expr_type);
      //}

      real_print_expr (ptr->expr_str_u.expr_op->left);
      printc (" || ");
      real_print_expr (ptr->expr_str_u.expr_op->right);

      //if (ptr->expr_str_u.expr_op->left->expr_type!=ptr->expr_str_u.expr_op->right->expr_type) {
      //printc (")");
      //}
      break;

    case ET_EXPR_OP_AND:
      printc ("( ");
      real_print_expr (ptr->expr_str_u.expr_op->left);
      printc (" && ");
      real_print_expr (ptr->expr_str_u.expr_op->right);
      printc (") ");
      break;

    case ET_EXPR_LITERAL_EMPTY_STRING:
      printc ("\"\"");
      break;

    case ET_EXPR_OP_USING:
      printc ("Using(");
      real_print_expr (ptr->expr_str_u.expr_op->left);
      printc (",");
      real_print_expr (ptr->expr_str_u.expr_op->right);
      printc (")");
      break;
    case ET_EXPR_OP_MOD:

      real_print_expr (ptr->expr_str_u.expr_op->left);
      printc (" %% ");
      real_print_expr (ptr->expr_str_u.expr_op->right);
      break;
    case ET_EXPR_OP_POWER:

      printc ("Pow(");
      real_print_expr (ptr->expr_str_u.expr_op->left);
      printc (",");
      real_print_expr (ptr->expr_str_u.expr_op->right);
      printc (")");
      break;
    case ET_EXPR_OP_CONCAT:
      real_print_expr (ptr->expr_str_u.expr_op->left);
      printc (",");
      real_print_expr (ptr->expr_str_u.expr_op->right);
      break;

    case ET_EXPR_OP_YEAR:
      printc ("UnitsYear(");
      real_print_expr (ptr->expr_str_u.expr_expr);
      printc (")");
      break;

    case ET_EXPR_OP_MONTH:
      printc ("UnitsMonth(");
      real_print_expr (ptr->expr_str_u.expr_expr);
      printc (")");
      break;

    case ET_EXPR_OP_DAY:
      printc ("UnitsDay(");
      real_print_expr (ptr->expr_str_u.expr_expr);
      printc (")");
      break;

    case ET_EXPR_OP_HOUR:
      printc ("UnitsHour(");
      real_print_expr (ptr->expr_str_u.expr_expr);
      printc (")");
      break;

    case ET_EXPR_OP_MINUTE:
      printc ("UnitsMinute(");
      real_print_expr (ptr->expr_str_u.expr_expr);
      printc (")");
      break;

    case ET_EXPR_OP_SECOND:
      printc ("UnitsSecond(");
      real_print_expr (ptr->expr_str_u.expr_expr);
      printc (")");
      break;
    case ET_EXPR_CURRENT:
      printc ("Current(\"CURRENT %s TO %s\")", decode_current1 (ptr->expr_str_u.expr_current->from),
	      decode_current2 (ptr->expr_str_u.expr_current->to));
      break;

    case ET_EXPR_OP_SPACES:
      real_print_expr (ptr->expr_str_u.expr_expr);
      printc (" SPACES");
      break;

      break;

    case ET_EXPR_CONCAT_LIST:
      A4GL_assertion (1, "CONCAT_LIST NOT IMPLEMENTED YET");
      break;

    case ET_EXPR_CAST:
      {
	int done = 0;
	if (ptr->expr_str_u.expr_cast->target_dtype == DTYPE_TEXT && ptr->expr_str_u.expr_cast->src_dtype == DTYPE_BYTE) {
	    real_print_expr (ptr->expr_str_u.expr_cast->expr);
	    done++;
	}
	if (ptr->expr_str_u.expr_cast->target_dtype == DTYPE_BYTE && ptr->expr_str_u.expr_cast->src_dtype == DTYPE_TEXT) {
	    real_print_expr (ptr->expr_str_u.expr_cast->expr);
	    done++;
	}

	if (ptr->expr_str_u.expr_cast->target_dtype == 2 && ptr->expr_str_u.expr_cast->src_dtype == 1)
	  {			// smallint->int
	    done++;
	    real_print_expr (ptr->expr_str_u.expr_cast->expr);
	  }

	if ((ptr->expr_str_u.expr_cast->target_dtype & DTYPE_MASK) == DTYPE_DECIMAL)
	  {
	    done++;
	    printc ("AsDecimal(");
	    real_print_expr (ptr->expr_str_u.expr_cast->expr);
	    printc (")");
	  }


	if (ptr->expr_str_u.expr_cast->target_dtype == 0 && ptr->expr_str_u.expr_cast->src_dtype == 2)
	  {			// smallint->int
	    done++;
	    printc ("AsChar(");
	    real_print_expr (ptr->expr_str_u.expr_cast->expr);
	    printc (")");
	  }

	if (ptr->expr_str_u.expr_cast->target_dtype == 0 && ptr->expr_str_u.expr_cast->src_dtype == 1)
	  {			// smallint->int
	    done++;
	    printc ("AsChar(");
	    real_print_expr (ptr->expr_str_u.expr_cast->expr);
	    printc (")");
	  }


	if (ptr->expr_str_u.expr_cast->target_dtype == DTYPE_DATE)
	  {			// bool->int
	    done++;
	    printc ("AsDate(");
	    real_print_expr (ptr->expr_str_u.expr_cast->expr);
	    printc (")");
	  }

	if (ptr->expr_str_u.expr_cast->target_dtype == DTYPE_DTIME)
	  {			// bool->int
	    done++;
	    printc ("AsDateTime(");
	    real_print_expr (ptr->expr_str_u.expr_cast->expr);
	    printc (")");
	  }

	if (ptr->expr_str_u.expr_cast->target_dtype == 2 && ptr->expr_str_u.expr_cast->src_dtype == 90)
	  {			// bool->int
	    done++;
	    printc ("/*cast1*/ AsInt(");
	    real_print_expr (ptr->expr_str_u.expr_cast->expr);
	    printc (")");
	  }
	if (ptr->expr_str_u.expr_cast->target_dtype == 90 && ptr->expr_str_u.expr_cast->src_dtype == 2)
	  {			// int->bool
	    printc ("AsBool(");
	    real_print_expr (ptr->expr_str_u.expr_cast->expr);
	    printc (")");
	    done++;
	  }

	if (ptr->expr_str_u.expr_cast->target_dtype == DTYPE_CHAR && ptr->expr_str_u.expr_cast->src_dtype == DTYPE_DTIME)
	  {
	    done++;
	    printc ("(");
	    real_print_expr (ptr->expr_str_u.expr_cast->expr);
	    printc (").ToString()");
	  }

	// Theres an implicit cast from integers to floats
	if (ptr->expr_str_u.expr_cast->target_dtype == DTYPE_FLOAT && ptr->expr_str_u.expr_cast->src_dtype == DTYPE_SMINT)
	  {
	    real_print_expr (ptr->expr_str_u.expr_cast->expr);
	    done++;
	  }
	if (ptr->expr_str_u.expr_cast->target_dtype == DTYPE_FLOAT && ptr->expr_str_u.expr_cast->src_dtype == DTYPE_INT)
	  {
	    real_print_expr (ptr->expr_str_u.expr_cast->expr);
	    done++;
	  }
	if (ptr->expr_str_u.expr_cast->target_dtype == DTYPE_SMFLOAT && ptr->expr_str_u.expr_cast->src_dtype == DTYPE_SMINT)
	  {
	    real_print_expr (ptr->expr_str_u.expr_cast->expr);
	    done++;
	  }
	if (ptr->expr_str_u.expr_cast->target_dtype == DTYPE_SMFLOAT && ptr->expr_str_u.expr_cast->src_dtype == DTYPE_INT)
	  {
	    real_print_expr (ptr->expr_str_u.expr_cast->expr);
	    done++;
	  }

	if (!done)
	  {
	    switch (ptr->expr_str_u.expr_cast->target_dtype)
	      {
	      case DTYPE_SMINT:
	      case DTYPE_INT:
		done++;
		printc ("/*cast2 */ AsInt(");
		real_print_expr (ptr->expr_str_u.expr_cast->expr);
		printc (")");
		break;
	      case DTYPE_CHAR:
		done++;
		if (ptr->expr_str_u.expr_cast->src_dtype != DTYPE_CHAR)
		  {
		    printc ("AsString(");
		    real_print_expr (ptr->expr_str_u.expr_cast->expr);
		    printc (")");
		  }
		else
		  {
		    real_print_expr (ptr->expr_str_u.expr_cast->expr);
		  }
		break;
	      case 90:
		done++;
		if (ptr->expr_str_u.expr_cast->src_dtype == 90)
		  {
		    real_print_expr (ptr->expr_str_u.expr_cast->expr);
		  }
		else
		  {
		    printc ("AsBool(");
		    real_print_expr (ptr->expr_str_u.expr_cast->expr);
		    printc (")");
		    break;
		  }
	      }
	  }





	if (!done)
	  {

	    printc ("%s(", explicitCastFunction (ptr->expr_str_u.expr_cast->target_dtype));
	    real_print_expr (ptr->expr_str_u.expr_cast->expr);
	    printc (")");
	  }
      }
      //A4GL_assertion (1, "CAST NOT IMPLEMENTED YET");
      break;


    case ET_EXPR_DTVAL:
      printc ("Datetime(%s, %d)", ptr->expr_str_u.expr_datetime->dtval, ptr->expr_str_u.expr_datetime->extend);
      break;

    case ET_EXPR_YEAR_FUNC:
      printc ("Year(");
      real_print_expr (ptr->expr_str_u.expr_expr);
      printc (")");
      break;

    case ET_EXPR_DATE_FUNC:
      printc ("Date(");
      real_print_expr (ptr->expr_str_u.expr_expr);
      printc (")");
      break;

    case ET_EXPR_MONTH_FUNC:
      printc ("Month(");
      real_print_expr (ptr->expr_str_u.expr_expr);
      printc (")");
      break;

    case ET_EXPR_DAY_FUNC:
      printc ("Day(");
      real_print_expr (ptr->expr_str_u.expr_expr);
      printc (")");
      break;

    case ET_EXPR_TIME_FUNC:
      printc ("Time(");
      real_print_expr (ptr->expr_str_u.expr_expr);
      printc (")");
      break;

    case ET_EXPR_INFIELD:
      printc ("%s.Infield(%s) /*%d*/", get_ui_context (),
	      field_name_list_as_char (ptr->expr_str_u.expr_infield->field_list), (int) ptr->expr_str_u.expr_infield->sio_id);
      break;


    case ET_EXPR_FIELD_TOUCHED:
      printc ("%s.FieldTouched(%s);", get_ui_context (), field_name_list_as_char (ptr->expr_str_u.expr_field_touched->field_list));
      break;

    case ET_EXPR_NOT_FIELD_TOUCHED:
      printc ("%s.NotFieldTouched(%s);", get_ui_context (),
	      field_name_list_as_char (ptr->expr_str_u.expr_field_touched->field_list));
      break;

    case ET_EXPR_IVAL_VAL:
      printc ("Interval(%s, \"%s TO %s\")", ptr->expr_str_u.expr_interval->intval,
	      decode_ival_define1 (ptr->expr_str_u.expr_interval->extend),
	      decode_ival_define2 (ptr->expr_str_u.expr_interval->extend));
      break;


    case ET_EXPR_FGL_SIZEOF:
      A4GL_assertion (1, "Not implemented");
      break;

    case ET_EXPR_FGL_ADDRESSOF:
      A4GL_assertion (1, "Not implemented");
      break;

    case ET_EXPR_FGL_ISDYNARR_ALLOCATED:
      A4GL_assertion (1, "Not implemented");
      break;

    case ET_EXPR_FGL_DYNARR_EXTENTSIZE:
      A4GL_assertion (1, "Not implemented");
      break;

    case ET_EXPR_FIELDTOWIDGET:
      A4GL_assertion (1, "Not implemented");
      break;

    case ET_EXPR_ID_TO_INT:
      A4GL_assertion (1, "Not implemented");
      break;


    case ET_EXPR_GET_FLDBUF:
      printc ("%s.UILib_getfldbuf(%s)",get_ui_context(),
	       field_name_list_as_char (ptr->expr_str_u.expr_get_fldbuf->field_list));
      break;

    case ET_EXPR_MODULE_FUNC:
      printc ("A4GL_push_char(_module_name);");
      break;


    case ET_EXPR_VARIABLE_USAGE:
      printc ("%s", decode_varbind (ptr, 'r', 0));
      break;

    case ET_E_V_OR_LIT_STRING:
      printc ("%s", ptr->expr_str_u.expr_string);
      break;
    case ET_EXPR_BRACKET:
      set_nonewlines ();
      printc ("(");
      real_print_expr (ptr->expr_str_u.expr_expr);
      printc (")");
      clr_nonewlines ();
      break;

    case ET_EXPR_IDENTIFIER:
      printc ("FGLIdent(\"%s\")", ptr->expr_str_u.expr_string);
      break;

    case ET_EXPR_MENU_ALL:
      printc ("UILib_Menu.MenuAll");
      break;

    default:

      printf ("Expression type : %d", ptr->expr_type);
      A4GL_assertion (1, "Unhandled expression type");

    }

}
#endif













static void
real_print_expr_list_with_separator (struct expr_str_list *l, char *s)
{
  int a;
  l = A4GL_rationalize_list (l);
  if (l)
    {
      for (a = 0; a < l->list.list_len; a++)
	{
	  if (a)
	    printc ("%s", s);

	//if (strcmp(s,"+")==0) {
		//ensure_dtype(0,0,l->list.list_val[a],DTYPE_CHAR,0);
	//}

	  real_print_expr (l->list.list_val[a]);
	}
    }
}



/**
 *
 * @todo Describe function
 */
static void
real_print_func_call (t_expr_str * fcall, int close)
{
  //char lib[255]="<not set>";
  int args_cnt;

//  NOTE - ANYTHING IN HERE SHOULD PROBABLY BE DUPLICATED IN THE 'real_print_expr' ROUTINE...
//



  if (fcall->expr_type == ET_EXPR_FCALL)
    {
      struct s_expr_function_call *p;
      p = fcall->expr_str_u.expr_function_call;

      p->parameters = A4GL_rationalize_list (p->parameters);
      args_cnt = A4GL_new_list_get_count (p->parameters);

      set_nonewlines ();
      printc ("%s(", map_fname (p->functionname));

      ensure_parameters (p->functionname, p->parameters);
      real_print_expr_list_with_separator (p->parameters, ",");

      if (close)
	printc (")");
      clr_nonewlines ();
      return;
    }

  if (fcall->expr_type == ET_EXPR_GET_FLDBUF)
    {
      struct s_expr_get_fldbuf *p;
      p = fcall->expr_str_u.expr_get_fldbuf;
      printc ("getfldbuf(%s)", field_name_list_as_char (p->field_list));
      return;
    }



  A4GL_assertion (1, "Internal error - expecting a function call");
}




static void
print_init_var (struct variable *v, char *prefix, int alvl, int explicit, int PrefixIncludesName, int expand_array, int tonull)
{
  char buff[1000];
  char prefix2[1000];
  int d1;
  int size;
  int a;
  char buff_id[200];


  strcpy (buff, prefix);
  if (v->escope == E_SCOPE_LOCAL)
    {
      if (PrefixIncludesName)
	{
	  sprintf (prefix2, "$%s", check_name (prefix));
	}
      else
	{
	  if (strlen (prefix) == 0)
	    {
	      sprintf (prefix2, "$%s", check_name (v->names.names.names_val[0].name));
	    }
	  else
	    {
	      sprintf (prefix2, "%s['%s']", prefix, v->names.names.names_val[0].name);
	    }
	}
    }
  else
    {
      if (PrefixIncludesName)
	{
	  if (v->escope == E_SCOPE_MODULE)
	    {
	      sprintf (prefix2, "$%s", check_name (prefix));
	    }
	  else
	    {
	      sprintf (prefix2, "$GLOBALS['%s']", check_name (prefix));
	    }
	}
      else
	{
	  if (strlen (prefix) == 0)
	    {

	      if (v->escope == E_SCOPE_MODULE)
		{
		  sprintf (prefix2, "$GLOBALS['M_%s']['%s']", cleaned_fname (compiling_module ()),
			   check_name (v->names.names.names_val[0].name));
		}
	      else
		{
		  sprintf (prefix2, "$GLOBALS['%s']", check_name (v->names.names.names_val[0].name));
		}
	    }
	  else
	    {
	      sprintf (prefix2, "%s['%s']", prefix, v->names.names.names_val[0].name);
	    }
	}
    }



  if (v->arr_subscripts.arr_subscripts_len && expand_array)
    {
      if (v->arr_subscripts.arr_subscripts_val[0] == -1)
	{
	  // dynamic array 
	  if (!explicit)
	    return;
	}

      //printc ("{");
      /*
         for (a = 0; a < v->arr_subscripts.arr_subscripts_len; a++)
         {

         SPRINTF2 (buff_id, "_fglcnt_%d_%d", alvl, a);
         //printc ("int %s;\n", buff_id);
         }
       */

      for (a = 0; a < v->arr_subscripts.arr_subscripts_len; a++)
	{
	  SPRINTF2 (buff_id, "$_fglcnt_%d_%d", alvl, a);

	  printc ("for (%s=0;%s<%d;%s++) {", buff_id, buff_id, v->arr_subscripts.arr_subscripts_val[a], buff_id);
	  if (a == 0)
	    {
	      strcat (prefix2, "[");
	    }
	  else
	    {
	      strcat (prefix2, ",");
	    }

	  strcat (prefix2, buff_id);

	  if (a == v->arr_subscripts.arr_subscripts_len - 1)
	    {
	      strcat (prefix2, "]");
	    }
	  tmp_ccnt++;
	}
      alvl++;
    }


  switch (v->var_data.variable_type)
    {
    case VARIABLE_TYPE_CONSTANT:
      // Can't initialize a constant ;-)
      break;

    case VARIABLE_TYPE_SIMPLE:
      {
	d1 = v->var_data.variable_data_u.v_simple.datatype & DTYPE_MASK;
	size = DECODE_SIZE (v->var_data.variable_data_u.v_simple.datatype);

	if (1 || size == 0)
	  {
	    A4GL_assertion (size, "Expecting size to be zero...");
	    // need to get it from the dimensions...?
	    size = v->var_data.variable_data_u.v_simple.dimensions[0];
	  }

	if (tonull == 0)
	  {
	    switch (d1 & DTYPE_MASK)
	      {
	      case 90:
		printc ("%s=false;", prefix2);
		break;

	      case DTYPE_INT:
	      case DTYPE_SMINT:
		printc ("%s=0;", prefix2);
		break;
	      case DTYPE_FLOAT:
	      case DTYPE_SMFLOAT:
		printc ("%s=0.0;", prefix2);
		break;

	      case DTYPE_DATE:
		printc ("%s=SQLToday();\n", prefix2);
		break;

	      case DTYPE_DTIME:
		printc ("%s=SQLCurrent();\n", prefix2);
		break;

	      case DTYPE_MONEY:
	      case DTYPE_DECIMAL:
		printc ("%s=0;\n", prefix2);
		break;

	      case DTYPE_CHAR:
	      case DTYPE_VCHAR:
	      case DTYPE_NCHAR:
		printc ("%s=" ";\n", prefix2);
		break;

	      default:
		printc ("%s=null;\n", prefix2);
	      }
	  }
	else
	  {
	    if (explicit == 0 && (d1 == DTYPE_INT || d1 == DTYPE_SMINT || d1 == DTYPE_FLOAT || d1 == DTYPE_SMFLOAT))	//  || d1 == DTYPE_DECIMAL || d1 == DTYPE_MONEY))
	      {
		if (d1 == DTYPE_INT || d1 == DTYPE_SMINT)
		  {
		    printc ("%s=0;", prefix2);
		  }
		else
		  {
		    if (d1 == DTYPE_MONEY || d1 == DTYPE_DECIMAL)
		      {
			printc ("%s=0;\n", prefix2);
		      }
		    else
		      {
			printc ("%s=0.0;", prefix2);
		      }
		  }
	      }
	    else
	      {
		if (d1 == 90)
		  {
		    printc ("%s=false;\n", prefix2);
		  }
		else
		  {
		    printc ("%s=null;\n", prefix2);
		  }
	      }
	  }
      }
      break;

    case VARIABLE_TYPE_RECORD:
      {
	int a;
	//strcat (prefix2, ".");
	for (a = 0; a < v->var_data.variable_data_u.v_record.variables.variables_len; a++)
	  {
	    print_init_var (v->var_data.variable_data_u.v_record.variables.variables_val[a], prefix2, alvl, explicit, 0, 1, tonull);
	  }
      }
      break;

    case VARIABLE_TYPE_ASSOC:
      {
	struct variable *nextvar;
	nextvar = v->var_data.variable_data_u.v_assoc.variable;
	print_init_var (nextvar, prefix2, alvl, explicit, 1, 1, tonull);
      }
      break;


    default:
      A4GL_assertion (1, "Not handled");

    }

  if (v->arr_subscripts.arr_subscripts_len && expand_array)
    {
      for (a = 0; a < v->arr_subscripts.arr_subscripts_len; a++)
	{
	  tmp_ccnt--;
	  printc ("}\n");
	  alvl--;
	}
      //printc ("}\n", buff_id);
    }



  return;

}





/* ***************************************************************************/
/* INPUT */
/* ***************************************************************************/

int
print_let_manyvars_g (t_expr_str_list * expr_list, expr_str_list * varlist)
{
  int from_exprs;
  int to_vars;
  int a;
  A4GL_debug ("1");
  expr_list = A4GL_rationalize_list (expr_list);

  from_exprs = A4GL_new_list_get_count (expr_list);
  to_vars = varlist->list.list_len;

  if (to_vars != from_exprs && to_vars > 1)
    {
      A4GL_debug ("to_Vars = %d from_Exprs = %d\n", to_vars, from_exprs);
      return 0;
    }

  if (to_vars == 1 && from_exprs > 1)
    {				// concatenation...
      enum e_scope scope;
      set_nonewlines ();

      scope = get_var_expr_scope (varlist->list.list_val[0]);
      printc ("%s", decode_varbind (varlist->list.list_val[0], 'w', 0));
      real_print_expr_list_with_separator (expr_list, " . ");
      printc ("%s", decode_varbind (varlist->list.list_val[0], ')', 0));
      printc (";");
      clr_nonewlines ();
      return 0;
    }

  for (a = 0; a < to_vars; a++)
    {
      enum e_scope scope;

      scope = get_var_expr_scope (varlist->list.list_val[a]);


      if (expr_list == NULL)
	{
	  init_var (varlist->list.list_val[a]);
	  continue;
	}
      else
	{
	  if (expr_list->list.list_val[a]->expr_type == ET_EXPR_NULL)
	    {
	      // LET x = NULL  - bad progammer, go to the back of the class...
	      init_var (varlist->list.list_val[a]);
	      continue;
	    }
	}

      // Quick check for ++ or --
      {
	char buff[20000];
	char buff1[20000];
	// get the expression as a string..
	sprintf (buff, "%s", expr_as_string_when_possible (expr_list->list.list_val[a]));

	// Generate what it would look like if it was this variable + 1
	sprintf (buff1, "%s+ 1", expr_as_string_when_possible (varlist->list.list_val[a]));
	// And compare to what we have...
	if (strcmp (buff, buff1) == 0)
	  {
	    printc ("$%s++;", local_expr_as_string (varlist->list.list_val[a]));
	    continue;
	  }
	// Generate what it would look like if it was this variable - 1
	sprintf (buff1, "%s- 1", expr_as_string_when_possible (varlist->list.list_val[a]));
	// And compare to what we have...
	if (strcmp (buff, buff1) == 0)
	  {
	    printc ("$%s--;", local_expr_as_string (varlist->list.list_val[a]));
	    continue;
	  }

      }


      set_nonewlines ();
      printc ("%s", decode_varbind (varlist->list.list_val[a], 'w', a));
      ensure_dtype (" ", 0, expr_list->list.list_val[a], get_binding_dtype (varlist->list.list_val[a]), 0);
      real_print_expr (expr_list->list.list_val[a]);
      printc ("%s", decode_varbind (varlist->list.list_val[0], ')', 0));
      printc (";");
      clr_nonewlines ();
    }
  return 1;
}


/* *************************** REPORT **********************/










/**
 * Print in the generated C output code an option change.
 *
 * For now its onlu used to change the menu line.
 *
 * @param n The parameter type:
 *   - M : Menu
 * @param s The parameter value
 *   - Now just the menu line
 */
static void
print_options (char n, char *s, expr_str * ptr)
{
  if (s == 0 && ptr)
    {
      s = local_expr_as_string (ptr);
    }
  else
    {
      static char buff[200];
      if (s[0] != '"')
	{
	  sprintf (buff, "\"%s\"", s);
	  s = buff;
	}
    }
  switch (n)
    {
    case 'W':
      printc ("UILib_Options(\"INPUT WRAP\",%s);",s);
      break;
    //case 'w':
      //printc ("UILib_Options(\"INPUT WRAP\",false);");
      //break;
    case 'm':
      printc ("UILib_Options(\"MESSAGE LINE\",%s);", s);
      break;
    case 'A':
      printc ("UILib_Options(\"ACCEPT KEY\",%s);", s);
      break;
    case 'D':
      printc ("UILib_Options(\"DELETE KEY\",%s);", s);
      break;
    case 'I':
      printc ("UILib_Options(\"INSERT KEY\",%s);", s);
      break;
    case 'H':
      printc ("UILib_Options(\"HELP KEY\",%s);", s);
      break;
    case 'h':
      printc ("UILib_Options(\"HELP FILE\",%s);", s);
      break;
    case 'C':
      printc ("UILib_Options(\"COMMENT LINE\",%s);", s);
      break;
    case 'P':
      printc ("UILib_Options(\"PROMPT LINE\",%s);", s);
      break;
    case 'f':
      printc ("UILib_Options(\"FIELD ORDER CONSTRAINED\",%s);", s);
      break;

    case 'S':
      if (atoi (s))
	{
	  printc ("SQLOptionsSqlInterruptOn();");
	}
      else
	{
	  printc ("SQLOptionsSqlInterruptOff();");
	}
      break;

    default: 
      printc ("UILib_Options(\"%c\",%s);", n, s);
	
    }
}



/**
 * Print the C code that implements the declaration of an associative array.
 *
 * Executed when the parser found a declaration of an associative variable.
 *
 * @param variable The variable name.
 * @param size The number of elements of the array.
 * @param n The size in number  of characters of the associate key.
 */
static void
print_declare_associate_1 (char *variable, char *size, char *n)
{
  printc ("DEF_ASS (_usg%s,%s+1);\n", downshift (variable), size);
  printc
    ("#define ASSOCIATE_%s(w,rw) %s[A4GL_ass_hash(_usg%s,%s+1,%s,w,sizeof(_usg%s),rw)]\n",
     upshift (variable), downshift (variable), downshift (variable), n, size, downshift (variable));
}



/**
 * Print the declaration of a char variable.
 *
 * The type of the variable comes in the first parameter.
 *
 * @param var The variable name and type.
 * @param size The size of the variable.
 * @param isstatic_extern The storage class used:
 *   - 1 : Static
 *   - 2 : Extern
 *   - Otherwise : Not static and not extern
 */
static void print_define_char (char *varo, int size, int isstatic_extern, int lvl, int vno, char *defsrc, char *arrvar)
{
  char buff[20];
  char *comma;
  char var[300];
  strcpy (buff, "");
  strcpy (var, varo);
//if (strlen(arrvar)) { strcat(var,"[]"); }
  if (vno)
    comma = "";
  else
    comma = "";

  if (lvl==0 && strstr(varo," G_") && A4GL_isyes(acl_getenv("A4GL_COMPILING_LIBRARY"))) {
		strcpy(buff,"public "); // protected
  }

  if (isstatic_extern == 1)
    {
      //strcat (buff, "static ");
    }

  if (isstatic_extern == 2)
    {
      return;
      //strcat (buff, "extern ");
      if (internal_var (var))
	return;
    }



  if (lvl)
    {
      if (strlen (defsrc))
	{
	  char buffx[2000];
	  sprintf (buffx, "     public %s%s%s%s;\n", buff, var, arrvar, comma);
	  //printf("lvl: %d\n",lvl);
	  strcat (membuffer[lvl - 1], buffx);
	}
      else
	{
	  char buffx[2000];
	  sprintf (buffx, "     public %s%s%s%s;\n", buff, var, arrvar, comma);
	  strcat (membuffer[lvl - 1], buffx);
	}
    }
  else
    {
      if (strlen (defsrc))
	{
	  printc ("%s%s%s%s; \n", buff, var, arrvar, comma);
	}
      else
	{
	  printc ("%s%s%s%s; \n", buff, var, arrvar, comma);
	}
    }
  //if (vno) printc(",");
}

/**
 * Prints a variable declaration to the generated file.
 *
 * The type of the variable comes in the first parameter.
 *
 * @param varstring String with variable declaration
 * @param isstatic_extern The modifier of variable:
 *   - 1 : Variable should be declared as static
 *   - 2 : Variable should be declared as extern
 */
static void
print_define (char *varstring, int isstatic_extern, int lvl, int vno, char *arrvar)
{
  char buff[20];
  char *comma;

  if (vno)
    comma = "";
  else
    comma = "";

  strcpy (buff, "");

  if (lvl==0 && strstr(varstring," G_") && A4GL_isyes(acl_getenv("A4GL_COMPILING_LIBRARY"))) {
		strcpy(buff,"public "); // protected
  }

  if (isstatic_extern == 1)
    {
      //strcat (buff, "static ");

    }

  if (isstatic_extern == 2)
    {
      return;
      //strcat (buff, "extern ");
      if (internal_var (varstring))
	return;
    }



  if (lvl)
    {
      char buffx[2000];
      sprintf (buffx, "     public %s%s%s%s;\n", buff, varstring, arrvar, comma);
      strcat (membuffer[lvl - 1], buffx);
    }
  else
    {
      printc ("%s%s%s%s;\n", buff, varstring, arrvar, comma);
    }
}

char *
cleaned_fname (char *s)
{
  static char buff[2000];

  if (rindex (s, '/'))
    {
      strcpy (buff, rindex (s, '/') + 1);
    }
  else
    {
      strcpy (buff, s);
    }
  return buff;
}

/**
 * Print in the C generated file the begining of declaration of a record
 * implementation.
 *
 * @param isstatic_extern The storage class used:
 *   - 1 : Static
 *   - 2 : Extern
 *   - Otherwise : Not static and not extern
 * @param varname The record variable name. Not used
 */
static void
print_start_record (int isstatic_extern, char *varname, char *arrsize, int level, char *defsrc)
{
  char buff[20] = "";
  static int reccnt = 0;
  //char *last_membuff;



/*int n;*/
  if (isstatic_extern == 1) {
    strcat (buff, "static ");
  }


  if (isstatic_extern == 2)
    {

      tmp_ccnt++;
      return;
      /*
         On Windows, "complex" variables must be explicitly exported, since they cannot be
         auto-imported. dll_import macro is defined in a4gl_incl_4gldef.h


       */
      if (strcmp (varname, "a4gl_sqlca") == 0)
	{
	  return;
	}
    }

  if (A4GL_isyes (acl_getenv ("COMPILING_DBSCHEMA")))
    {
      char buff[200];
      char *ptr;
      strcpy (buff, defsrc);
      ptr = strstr (buff, ".*");
      *ptr = 0;
      sprintf (recname[level], "T_%s", buff);
    }
  else
    {
      sprintf (recname[level], "Rec%s%d", cleaned_fname (compiling_module ()), reccnt++);
    }
//printf("record @ %d = %s\n", level,recname[level]);

  if (level == 0)
    {

	//char buff[200]="protected ";
	char buff[200]=" ";
  if (A4GL_isyes (acl_getenv ("COMPILING_DBSCHEMA"))) {
		strcpy(buff,"");
	}
	

      printc ("#");
      if (strcmp (arrsize, "-1") != 0)
	{
	  sprintf (membuffer[0], "public %sstruct %s {\n", buff, recname[level]);
	}
      else
	{
	  sprintf (membuffer[0], "public %sstruct %s {\n", buff, recname[level]);
	}
    }
  else
    {
      if (strcmp (arrsize, "-1") != 0)
	{
	  sprintf (membuffer[level], "public struct %s {\n", recname[level]);
	}
      else
	{
	  sprintf (membuffer[level], "public struct %s {\n", recname[level]);
	}
    }
  tmp_ccnt++;
}

/**
 * Finishes the declaration of a record.
 *
 * @param vname The record variable name
 * @param arrsize The array size if is a record array
 */
static void
print_end_record (char *vname, struct variable *v, int level)
{
  //int cnt;
  char smbuff[10000];
  //int arrsizes[10];
  tmp_ccntminus ();

  if (A4GL_isyes (acl_getenv ("COMPILING_DBSCHEMA")))
    {
      strcat (membuffer[level], "   };\n");
      fprintf (hfile, "   public %s\n\n\n", membuffer[level]);
      return;
    }


  if (v->arr_subscripts.arr_subscripts_len == 0)
    {
      strcat (membuffer[level], "   };\n");
      if (level == 0)
	{
	char buff[200]="";
  		if ( strstr(vname,"G_") && A4GL_isyes(acl_getenv("A4GL_COMPILING_LIBRARY"))) {
				strcpy(buff,"public "); // protected
  		}
	  printc ("%s%s %s; //2 - %d\n", buff, recname[level], vname, level);
	}
      else
	{
	  sprintf (smbuff, "     public %s %s;\n", recname[level], vname);
	  strcat (membuffer[level - 1], smbuff);
	}
    }
  else
    {
      char buff[2000];
      char buff_comma[2000]="";
      char smbuff[2000];
      int a;
      strcpy (buff, "");
      for (a = 0; a < v->arr_subscripts.arr_subscripts_len; a++)
	{
	  if (a) {
	    	strcat (buff, ",");
		strcat(buff_comma,",");
	  }
	  sprintf (smbuff, "%d", v->arr_subscripts.arr_subscripts_val[a]);
	  strcat (buff, smbuff);
	}

      strcat (membuffer[level], "   };\n");

      if (level == 0)
	{
	  printc ("%s [%s]%s=new %s[%s];\n", recname[level], buff_comma,vname, recname[level], buff);
	}
      else
	{
	  sprintf (smbuff, "public %s [%s]%s; /* @FIXME ?? */\n", recname[level], vname, buff_comma,recname[level]);
	  strcat (membuffer[level - 1], smbuff);
	}
    }

  fprintf (hfile, "   %s\n\n\n", membuffer[level]);
  printc ("#");
}





/**
 *
 * @todo Describe function
 */
static void
print_cmd_start ()
{
}





static void add_function_to_header (char *identifier, int params, char *is_static)
{

  return;
  if (is_builtin_func (identifier))
    return;


  if (!A4GL_has_pointer (identifier, 'X'))
    {
      A4GL_add_pointer (identifier, 'X', (void *) 1);

      if (params == 1)		/* Normal Function */
	{
	  printh ("A4GL_FUNCTION %s int %s%s (int n);\n", is_static, local_get_namespace_internal (identifier), identifier);

	}

      if (params == 2)		/* Report... */
	printh ("A4GL_REPORT void %s%s (int n,int a);\n", local_get_namespace_internal (identifier), identifier);
    }


}





/*
int
A4GL_doing_pcode (void)
{
  if (strcmp (acl_getenv ("LEXTYPE"), "PCODEC") == 0)
    return 1;

  return 0;
}


int
doing_cs (void)
{
  if (strcmp (acl_getenv ("LEXTYPE"), "CS") == 0)
    return 1;
  return 0;
}

*/






















static void
print_Constant_1 (char *name, struct constant_data *c)
{
  //A4GL_assertion (1, "Not implemented yet");
}


static int local_is_system_variable (char *s)
{
  //if (strcmp (s, "int_flag") == 0) return 1;
  //if (strcmp (s, "quit_flag") == 0) return 1;

  if (strcmp (s, "a4gl_status") == 0)
    return 1;
  if (strncmp (s, "a4gl_sqlca", 10) == 0)
    return 1;
  if (strcmp (s, "int_flag") == 0)
    return 1;
  if (strcmp (s, "quit_flag") == 0)
    return 1;
  if (strcmp (s, "notfound") == 0)
    return 1;
  if (strcmp (s, "false") == 0)
    return 1;
  if (strcmp (s, "true") == 0)
    return 1;
  if (strcmp (s, "today") == 0)
    return 1;
  if (strcmp (s, "user") == 0)
    return 1;
  if (strcmp (s, "pageno") == 0)
    return 1;
  if (strcmp (s, "lineno") == 0)
    return 1;
  if (strcmp (s, "time") == 0)
    return 1;
  if (strcmp (s, "usrtime") == 0)
    return 1;
  if (strcmp (s, "curr_hwnd") == 0)
    return 1;
  if (strcmp (s, "curr_form") == 0)
    return 1;
  if (strcmp (s, "err_file_name") == 0)
    return 1;
  if (strcmp (s, "err_file_no") == 0)
    return 1;
  if (strcmp (s, "curr_file_name") == 0)
    return 1;
  if (strcmp (s, "curr_line_no") == 0)
    return 1;
  if (strcmp (s, "err_status") == 0)
    return 1;
  if (strcmp (s, "aiplib_status") == 0)
    return 1;
  return 0;
}



static void
process_tmpbuff_for_simple_var (char *name, int static_extern_flg, char *defsrc, int dtype, int dim0, int level, int vno,
				char *tbuff)
{
  char tmpbuff[256] = "";
  char stmpbuff[256] = "";
  char *s="";

return ;

  //s = irettype_integer (defsrc, dtype);

  switch (dtype & DTYPE_MASK)
    {
    case DTYPE_DECIMAL:
      if (strstr (s, "LIKE"))
	{
	  sprintf (stmpbuff, " %s", s);
	}
      else
	{
	  sprintf (stmpbuff, " %s ", s); /*, dim0 >> 8, dim0 & 255); */
	}
      strcat (tmpbuff, stmpbuff);
      break;

    case DTYPE_DTIME:
      if (strstr (s, "LIKE"))
	{
	  sprintf (stmpbuff, " %s", s);
	}
      else
	{
	  sprintf (stmpbuff, " %s /* %s TO %s */", s, decode_dt (dim0, 1), decode_dt (dim0, 2));

	}

      strcat (tmpbuff, stmpbuff);
      break;

    case DTYPE_INTERVAL:
      if (strstr (s, "LIKE"))
	{
	  sprintf (stmpbuff, " %s", s);
	}
      else
	{
	  int n;
	  n = dim0;

	if (n) {
	  if (((n >> 4) & 0xf) <= 2)
	    {
	      sprintf (stmpbuff, " IfxMonthSpan? /* %sTO%s */", decode_ival_define1 (dim0), decode_ival_define2 (dim0));
	    }
	  else
	    {
	      sprintf (stmpbuff, " IfxTimeSpan? /* %sTO%s */", decode_ival_define1 (dim0), decode_ival_define2 (dim0));
	    }
	} else {
      		sprintf(stmpbuff, "IfxInterval?");
		}
	}
      strcat (tmpbuff, stmpbuff);
      break;




    default:
      SPRINTF1 (stmpbuff, " %s", irettype_integer (defsrc, dtype));
      strcat (tmpbuff, stmpbuff);
    }


  strcat (tmpbuff, " ");

  if (strlen (tbuff))
    {
	int a;
	int mode=0;
	
      strcat (tmpbuff, "[/* 1 */");
	for (a=0;a<strlen(tbuff);a++) {
		if (tbuff[a]=='[') mode=1;
		if (tbuff[a]==']') mode=2;
		if (mode==1 && tbuff[a]==',')  strcat(tmpbuff,",");
	}
      strcat (tmpbuff, "] ");
	//A4GL_pause_execution();
    }
  strcat (tmpbuff, name);

  if (dtype == DTYPE_CHAR || dtype == DTYPE_VCHAR)
    {				/* Its a 'char' (may need varchar & friends too... */


      if (dtype == DTYPE_CHAR)
	{

	  print_define_char (tmpbuff, dim0, static_extern_flg, level, vno, defsrc, tbuff);
	}
      else
	{
	  print_define_char (tmpbuff, dim0, static_extern_flg, level, vno, defsrc, tbuff);	// Allow extra space to store the size...
	}
    }
  else
    {
      print_define (tmpbuff, static_extern_flg, level, vno, tbuff);
    }

}







static void
make_arr_str (char *s, struct variable *v)
{
  int a;
  char buff[256];
  strcpy (s, "");
  for (a = 0; a < v->arr_subscripts.arr_subscripts_len; a++)
    {
      if (a)
	{
	  strcat (s, ",");
	}
      SPRINTF1 (buff, "%d", v->arr_subscripts.arr_subscripts_val[a]);
      strcat (s, buff);
    }
}

void
print_variable_new (struct variable *v, char scope, int level, int vno)
{
  int static_extern_flg;
  char arrbuff[256];
  char name[256];
//printf("In print_variable_new %s\n", v->names.names.names_val[0].name);



  return;



  if (!A4GL_isyes (acl_getenv ("COMPILING_DBSCHEMA"))) {
  	if (scope=='M' && v->usage==0  && v->assigned==0 && level==0) return;
  	if (scope=='L' && v->usage==0  && v->assigned==0 && level==0) return;
  }


  static_extern_flg = 0;
  A4GL_assertion (v == 0, "No variable to print");
  if (level == 0
      && local_is_system_variable (v->names.names.names_val[0].name)
      && (strcasecmp (v->names.names.names_val[0].name, "int_flag") == 0 || strcasecmp (v->names.names.names_val[0].name, "quit_flag") == 0)
)
    {
      // Ignore all system variables
      return;
    }
  strcpy (arrbuff, "-1");
  /* are we dealing with the sqlca variable ? */
  A4GL_debug ("v->names.name=%s", v->names.names.names_val[0].name);
  if (level == 0 && strcmp (v->names.names.names_val[0].name, "sqlca") == 0)
    {
#ifdef DEBUG
      A4GL_debug ("SQLCA!!!\n");
#endif
      if (strcmp (acl_getenv ("A4GL_LEXTYPE"), "EC") == 0)
	{
	  return;
	}
    }

  if (scope == 'G')
    return;

  if (scope == 'G' && strcasecmp (v->names.names.names_val[0].name, "time") == 0 && level == 0)
    {
#ifdef DEBUG
      A4GL_debug ("Ignore time....\n");
#endif
      return;
    }


  if (v->arr_subscripts.arr_subscripts_len)
    {
      make_arr_str (arrbuff, v);
    }
  else
    {
      strcpy (arrbuff, "-1");
    }







  if (level == 0)		/* We only print 'static' or 'extern' at the start of a record/variable - not a nested record */
    {
      if (scope == 'G')
	{
	  static_extern_flg += 2;
	}

      if (scope == 'M')
	{
	  static_extern_flg += 1;
	}
      else
	{

	  if (v->is_static == 1 && !isInReport ())
	    {
	      static_extern_flg += 1;
	    }
	}
    }


  if (level == 0)
    {
      strcpy (name, check_name (v->names.names.names_val[0].name));
    }
  else
    {
      strcpy (name, v->names.names.names_val[0].name);
    }



  if (level == 0 && (A4GL_isyes (acl_getenv ("MARK_SCOPE")) || A4GL_isyes (acl_getenv ("MARK_SCOPE_MODULE"))))
    {
      if (local_is_system_variable (name));
      else
	{
	  if (v->escope == E_SCOPE_IMPORTED_GLOBAL || v->escope == E_SCOPE_EXPORTED_GLOBAL)
	    {
	      SPRINTF1 (name, "G_%s", v->names.names.names_val[0].name);
	    }
	  if (v->escope == E_SCOPE_MODULE)
	    {
	      if (A4GL_isyes (acl_getenv ("MARK_SCOPE_MODULE")))
		{
		  SPRINTF2 (name, "M_%s_%s", cleaned_fname (compiling_module ()), v->names.names.names_val[0].name);
		}
	      else
		{
		  SPRINTF1 (name, "M_%s", v->names.names.names_val[0].name);
		}
	    }
	  if (v->escope == E_SCOPE_LOCAL)
	    {
	      SPRINTF1 (name, "L_%s", v->names.names.names_val[0].name);
	    }
	}
    }

  if (v->var_data.variable_type == VARIABLE_TYPE_SIMPLE)
    {
      char tmpbuff[256] = "";
      //char stmpbuff[256] = "";
      char tbuff[200] = "";
      char *s;


      //sprintf (tmpbuff, "%s", name);
      strcpy (tmpbuff, "");
      if (v->arr_subscripts.arr_subscripts_len)
	{
	  if (strchr (arrbuff, '-') == 0)
	    {
	      s = irettype_integer (v->defsrc, v->var_data.variable_data_u.v_simple.datatype);
	      strcat (tmpbuff, "");
	      sprintf (tbuff, "=new %s[%s]", s, arrbuff);
	      //strcat (tmpbuff, arrbuff);
	      //strcat (tmpbuff, "]");
	    }
	  else
	    {
	      A4GL_assertion (1, "BAD 4GL generation");
#ifdef OLD
	      SPRINTF2 (tmpbuff, "%s *%s", irettype_integer (v->defsrc, v->var_data.variable_data_u.v_simple.datatype), name);
#endif
	    }
	}






      process_tmpbuff_for_simple_var (name, static_extern_flg, v->defsrc, v->var_data.variable_data_u.v_simple.datatype,
				      v->var_data.variable_data_u.v_simple.dimensions[0], level, vno, tbuff);



      return;
    }

  if (v->var_data.variable_type == VARIABLE_TYPE_RECORD || v->var_data.variable_type == VARIABLE_TYPE_OBJECT)
    {
      int a;
      if (strcmp (name, "a4gl_sqlca") != 0)
	{
	  if (strstr (v->defsrc, ".*") && A4GL_isyes (acl_getenv ("RECORDLIKES")) && level==0)
	    {
	      char buff[200];
	      char *ptr;
		char buff_prot[200]="";


		if (strstr(name,"G_")  && A4GL_isyes(acl_getenv("A4GL_COMPILING_LIBRARY"))) {
			strcpy(buff_prot,"public "); // protected
		}

	      strcpy (buff, v->defsrc);
	      ptr = strstr (buff, ".*");
	      *ptr = 0;
	      if (strcmp (arrbuff, "-1") == 0)
		{
		  printc ("%sDBSchema.T_%s %s;", buff_prot, buff, name);
		}
	      else
		{
		  printc ("%sDBSchema.T_%s[] %s=new DBSchema.T_%s[%s];", buff_prot, buff, name, buff,arrbuff);
		}
	    }
	  else
	    {
	      print_start_record (static_extern_flg, name, arrbuff, level, v->defsrc);
	      for (a = 0; a < v->var_data.variable_data_u.v_record.variables.variables_len; a++)
		{
		  struct variable *next_v;
		  next_v = v->var_data.variable_data_u.v_record.variables.variables_val[a];
		  print_variable_new (next_v, scope, level + 1, a != v->var_data.variable_data_u.v_record.variables.variables_len - 1);
		}
	      print_end_record (name, v, level);
	    }
	}
      return;
    }

  if (v->var_data.variable_type == VARIABLE_TYPE_ASSOC)
    {
      struct variable v2;
      char buff1[20];
      char buff2[20];

      SPRINTF1 (buff1, "%d", v->var_data.variable_data_u.v_assoc.char_size);
      SPRINTF1 (buff2, "%d", v->var_data.variable_data_u.v_assoc.size);

      print_declare_associate_1 (v->names.names.names_val[0].name, buff2, buff1);
      //print_declare_associate_2 (v->names.names.names_val[0].name,buff1,buff2);


      memcpy (&v2, v->var_data.variable_data_u.v_assoc.variable, sizeof (struct variable));

      //v2.names.next = 0;
      v2.names.names.names_len = v->names.names.names_len;
      v2.names.names.names_val = v->names.names.names_val;

      print_variable_new (&v2, scope, level + 1, 0);
      clr_suppress_lines ();
      return;
    }


  if (v->var_data.variable_type == VARIABLE_TYPE_CONSTANT)
    {
      /* Maybe we should print out #define's for these ? */
      /* Maybe not - they should already have been converted by lexer.c */
      print_Constant_1 (v->names.names.names_val[0].name, &v->var_data.variable_data_u.v_const);
    }


}


#ifdef NOTNEEDED

/**
 *  * Gets the C data type corresponding to 4gl data type
 *   *
 *    * @param s A string with the numeric 4gl data type (@see find_type())
 *     * @return The string (static) with the C declaration
 *      */
static char *
local_rettype (char *s)
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
    strcpy (rs, "string");
  if (strcmp (s, "90") == 0)
    strcpy (rs, "bool");
  if (strcmp (s, "1") == 0)
    strcpy (rs, "int?");
  if (strcmp (s, "2") == 0)
    strcpy (rs, "int?");
  if (strcmp (s, "3") == 0)
    strcpy (rs, "double?");
  if (strcmp (s, "4") == 0)
    strcpy (rs, "float?");
  if (strcmp (s, "5") == 0)
    strcpy (rs, "CMDecimal?");
  if (strcmp (s, "6") == 0)
    strcpy (rs, "int?");
  if (strcmp (s, "7") == 0)
    strcpy (rs, "IfxDate?");
  if (strcmp (s, "8") == 0)
    strcpy (rs, "IfxMoney?");
  if (strcmp (s, "10") == 0)
    strcpy (rs, "IfxDateTime?");
  if (strcmp (s, "11") == 0)
    strcpy (rs, "IfxByte");
  if (strcmp (s, "12") == 0)
    strcpy (rs, "IfxByte");
  if (strcmp (s, "13") == 0)
    strcpy (rs, "string");
  if (strcmp (s, "14") == 0)
    strcpy (rs, "IfxIntervalx?");
  return strdup (rs);
}
#endif








int
LEX_initlib (void)
{

  A4GL_assertion (1, "Didnt think this is called");
  return 1;
}





int
internal_var (char *s)
{
  if (strcmp (s, "int_flag INTEGER") == 0)
    return 1;
  if (strcmp (s, "quit_flag INTEGER") == 0)
    return 1;
  if (strcmp (s, "a4gl_status INTEGER") == 0)
    return 1;
  if (strcmp (s, "today DATE") == 0)
    return 1;
  if (strcmp (s, "fgl_user CHAR") == 0)
    return 1;
  if (strcmp (s, "pageno INTEGER") == 0)
    return 1;
  if (strcmp (s, "lineno INTEGER") == 0)
    return 1;
  if (strcmp (s, "usrtime INTEGER") == 0)
    return 1;
  if (strcmp (s, "curr_hwnd INTEGER") == 0)
    return 1;
  if (strcmp (s, "curr_form INTEGER") == 0)
    return 1;
  if (strcmp (s, "err_file_name CHAR") == 0)
    return 1;
  if (strcmp (s, "err_file_no INTEGER") == 0)
    return 1;
  if (strcmp (s, "curr_file_name CHAR") == 0)
    return 1;
  if (strcmp (s, "curr_line_no INTEGER") == 0)
    return 1;
  if (strcmp (s, "err_status INTEGER") == 0)
    return 1;
  if (strcmp (s, "aiplib_status INTEGER") == 0)
    return 1;
  return 0;
}


void set_nonewlines (void)
{
  if (nonewlines == 0)
    {
      print_space ();
    }
  nonewlines++;

}

void
clr_nonewlines (void)
{
  nonewlines--;
  A4GL_assertion (nonewlines < 0, "nonewlines < 0");
  if (nonewlines == 0)
    {
      printc ("#");
      daylight = 0;
    }
}





static void tmp_ccntminus ()
{
  tmp_ccnt--;
  if (tmp_ccnt < 0)
    {
      A4GL_assertion (1, "tmp_ccnt<0");
    }

}










/*
char *
get_namespace_internal (char *s)
{
  char *ptr;
  ptr = local_get_namespace (s);
  if (strcmp (ptr, "aclfgl_") == 0)
    {
      return "";
    }


  return ptr;
}
*/

static char * map_fname (char *s)
{
  if (strcmp (s, "length") == 0)
    {
      return "length";
    }
  if (strcmp (s, "arg_val") == 0)
    {
      return "arg_val";
    }
  if (strcmp (s, "num_args") == 0)
    {
      return "num_args";
    }
  if (strcmp (s, "fgl_getenv") == 0)
    {
      return "fgl_getenv";
    }
  if (strcmp (s, "ASCII") == 0)
    {
      return "Ascii";
    }
  if (strcmp (s, "set_count") == 0)
    {
      return "set_count";
    }
  return s;
}

static int
print_whenever_style (int code, char *whento)
{
  return 0;
  need_daylight ();
  switch (code)
    {
    case 0x12:
      if (strcmp (whento, "get_error_record") == 0)
	{
	  when_set_to_call = 1;
	}
      else
	{
	  when_set_to_call = 0;
	}

      printc ("WHENEVER ERROR CALL %s", whento);
      need_daylight ();
      return 0;
    case 0x11:
      printc ("WHENEVER ERROR STOP");
      need_daylight ();
      when_set_to_call = 0;
      return 0;
    case 0x10:
      printc ("WHENEVER ERROR CONTINUE");
      when_set_to_call = 0;
      need_daylight ();
      return 0;

    case 0x20:
      printc ("WHENEVER ANY ERROR CONTINUE");
      need_daylight ();
      return 0;
    case 0x21:
      printc ("WHENEVER ANY ERROR STOP");
      need_daylight ();
      return 0;
    case 0x22:
      printc ("WHENEVER ANY ERROR CALL %s", whento);
      need_daylight ();
      return 0;
    }
  printc ("WHENEVER 0x%x %s\n", code, whento);
  return 0;
}






/******************************************************************************/
static int
print_sql_block_cmd (struct_sql_block_cmd * cmd_data)
{
  int a;
  struct expr_str_list *into_list = 0;
  char buff[20000] = "";
  int i;
  char *ptr;
  //static int sqlblock;
  //char tmpbuff[200];
  //struct struct_execute_cmd exec_cmd;
  print_cmd_start ();

  clr_bindings ();

// Collect any 'intos...'
  for (a = 0; a < cmd_data->list->list.list_len; a++)
    {
      expr_str *e;
      e = cmd_data->list->list.list_val[a];
      //printf("%d - %s\n",a, decode_e_expr_type(e->expr_type));
      switch (e->expr_type)
	{

	case ET_EXPR_SQLBLOCK_INTO:
	  if (into_list)
	    {
	      a4gl_yyerror ("More than one INTO is not supported");
	    }
	  into_list = e->expr_str_u.expr_list;
	  break;

	case ET_EXPR_VARIABLE_USAGE:
	  A4GL_new_append_ptr_list (input_bind, e);
	  break;

	default:
	  break;
	}
    }

  for (a = 0; a < cmd_data->list->list.list_len; a++)
    {
      expr_str *e;
      e = cmd_data->list->list.list_val[a];
      switch (e->expr_type)
	{

	case ET_EXPR_SQLBLOCK_INTO:
	  break;
	case ET_EXPR_VARIABLE_USAGE:
	  strcat (buff, "?");
	  break;

	case ET_EXPR_SQLBLOCK_TEXT:
	  if (strlen (buff))
	    {
	      strcat (buff, " ");
	    }
	  strcat (buff, e->expr_str_u.expr_string);
	  break;

	default:
	  A4GL_assertion (1, "Not implemented");
	}
    }

  output_bind = into_list;
  ptr = buff;
  i = 0;

  if (input_bind && input_bind->list.list_len)
    {
      i += 1;
    }
  if (output_bind && output_bind->list.list_len)
    {
      i += 2;
    }


  if (i)
    {
      printc ("{ /* Has inbind */");
      tmp_ccnt++;
    }


  if (i & 1)
    {
      print_in_binding (input_bind);
    }

  if (i & 2)
    {
      printc ("$RSet=null;");
    }

  print_when_sql_start ();
  switch (i)
    {
    case 0:
      printc ("SQLExecute(\"%s\");", escape_quotes_and_remove_nl (ptr, 0));
      break;
    case 1:
      printc ("SQLExecute(\"%s\",$InBind);", escape_quotes_and_remove_nl (ptr, 0));
      break;
    case 2:
      printc ("$RSet=SQLExecuteInto(\"%s\");", escape_quotes_and_remove_nl (ptr, 0));
      break;
    case 3:
      printc ("$RSet=SQLExecuteInto(\"%s\",$InBind);", escape_quotes_and_remove_nl (ptr, 0));
      break;

    }
  print_when_sql_end ();
  if (i & 2)
    {
      printc ("if ($RSet!=null) {");
      tmp_ccnt++;
      print_copy_fromRSet (output_bind);
      printc ("$RSet.Dispose();");
      tmp_ccnt--;
      printc ("}");
    }

  if (i)
    {
      tmp_ccnt--;
      printc ("}");
    }




  return 1;
}




static char * decode_dt (int a, int b)
{
  static char buff1[200];
  static char buff2[200];
  int c;
  if (a == 0)
    {
      if (b == 1)
	return "\"DateTimeYear\"";
      return "\"DateTimeSecond\"";
    }

  if (b == 1)
    {
      c = a >> 4;
      sprintf (buff1, "%x %x (b=%d)", c, a, b);
      switch (c)
	{
	case 1:
	  strcpy (buff1, "\"DateTimeQual.DateTimeYear\"");
	  break;
	case 2:
	  strcpy (buff1, "\"DateTimeQual.DateTimeMonth\"");
	  break;
	case 3:
	  strcpy (buff1, "\"DateTimeQual.DateTimeDay\"");
	  break;
	case 4:
	  strcpy (buff1, "\"DateTimeQual.DateTimeHour\"");
	  break;
	case 5:
	  strcpy (buff1, "\"DateTimeQual.DateTimeMinute\"");
	  break;
	case 6:
	  strcpy (buff1, "\"DateTimeQual.DateTimeSecond\"");
	  break;
	case 7:
	  strcpy (buff1, "\"DateTimeQual.DateTimeFraction1\"");
	  break;
	case 8:
	  strcpy (buff1, "\"DateTimeQual.DateTimeFraction2\"");
	  break;
	case 9:
	  strcpy (buff1, "\"DateTimeQual.DateTimeFraction3\"");
	  break;
	case 10:
	  strcpy (buff1, "\"DateTimeQual.DateTimeFraction4\"");
	  break;
	case 11:
	  strcpy (buff1, "\"DateTimeQual.DateTimeFraction5\"");
	  break;
	}
      return buff1;
    }
  else
    {
      c = a & 0xf;
      sprintf (buff2, "%x %x (b=%d)", c, a, b);
      switch (c)
	{
	case 1:
	  strcpy (buff2, "\"DateTimeQual.DateTimeYear\"");
	  break;
	case 2:
	  strcpy (buff2, "\"DateTimeQual.DateTimeMonth\"");
	  break;
	case 3:
	  strcpy (buff2, "\"DateTimeQual.DateTimeDay\"");
	  break;
	case 4:
	  strcpy (buff2, "\"DateTimeQual.DateTimeHour\"");
	  break;
	case 5:
	  strcpy (buff2, "\"DateTimeQual.DateTimeMinute\"");
	  break;
	case 6:
	  strcpy (buff2, "\"DateTimeQual.DateTimeSecond\"");
	  break;
	case 7:
	  strcpy (buff2, "\"DateTimeQual.DateTimeFraction1\"");
	  break;
	case 8:
	  strcpy (buff2, "\"DateTimeQual.DateTimeFraction2\"");
	  break;
	case 9:
	  strcpy (buff2, "\"DateTimeQual.DateTimeFraction3\"");
	  break;
	case 10:
	  strcpy (buff2, "\"DateTimeQual.DateTimeFraction4\"");
	  break;
	case 11:
	  strcpy (buff2, "\"DateTimeQual.DateTimeFraction5\"");
	  break;
	}
      return buff2;
    }
}





static int
is_substring_variable_usage (variable_usage * u, expr_str ** s, expr_str ** e)
{
  *s = 0;
  *e = 0;

  while (u)
    {
      if (u->next == 0)
	break;
      u = u->next;
    }

  *s = NULL;
  *e = NULL;

  if (u->substrings_start.substrings_start)
    {
      *s = u->substrings_start.substrings_start;
      *e = u->substrings_end.substrings_end;

      return 1;
    }

  return 0;

}



static int
is_substring_variable_usage_in_expr (expr_str * v, expr_str ** s, expr_str ** e)
{
  struct variable_usage *u = 0;
  if (v->expr_type == ET_EXPR_VARIABLE_USAGE)
    {
      u = v->expr_str_u.expr_variable_usage;
    }
  if (v->expr_type == ET_EXPR_VARIABLE_USAGE_WITH_ASC_DESC)
    {
      u = v->expr_str_u.expr_variable_usage_with_asc_desc->var_usage;
    }
  A4GL_assertion (u == 0, "Not a variable usage");
  return is_substring_variable_usage (u, s, e);
}


char * decode_varbind (struct expr_str *t, char read_or_write, int pos)
{
  char buff[9000];
  //char ptr[2000];
  int substring = 0;
  struct variable_usage *u;
  expr_str *substring_start;
  expr_str *substring_end;

  u = t->expr_str_u.expr_variable_usage;


  substring = is_substring_variable_usage_in_expr (t, &substring_start, &substring_end);
  strcpy (buff, generation_get_variable_usage (t));

  if (read_or_write == ')')
    {

      if (substring)
	return ")";
      return "";
    }


// Make sure its not a reserved word...
//strcpy(ptr,check_name(buff));
//strcpy(buff,ptr);

  //sprintf (buff, "%s", t->varname);

  if (strcmp (buff, "a4gl_status") == 0)
    {
      if (read_or_write == 'w')
	{
	  return "$IfxStatus= ";
	}
      else
	{
	  return "$IfxStatus";
	}
    }
  if (strcmp (buff, "int_flag") == 0)
    {
      if (read_or_write == 'w')
	{
	  return "$int_flag= ";
	}
      else
	{
	  return "$int_flag";
	}
    }
  if (strcmp (buff, "quit_flag") == 0)
    {
      if (read_or_write == 'w')
	{
	  return "$quit_flag= ";
	}
      else
	{
	  return "$quit_flag";
	}
    }

  if (strncmp (buff, "a4gl_sqlca", 10) == 0)
    {
      char buff2[2000];
      if (read_or_write == 'w')
	{
	  sprintf (buff2, "$%s= ", &buff[5]);
	}
      else
	{
	  sprintf (buff2, "$%s", &buff[5]);
	}
      strcpy (buff, buff2);
      return strdup(buff);
    }




  if (read_or_write == 'w' && !substring)
    {
	char buff2[2000];
	
      sprintf (buff2, "$%s= ", buff);
	strcpy(buff,buff2);
    }

  A4GL_trim (buff);


  if (substring)
    {
      char buff2[2000];
      char *p1;
      char *p2;
//printc("SUBSTRING....\n");
      p1 = strdup (local_expr_as_string (substring_start));
      if (substring_end)
	{
	  p2 = strdup (local_expr_as_string (substring_end));
	}
      else
	{
	  p2 = p1;
	}

      if (read_or_write == 'r')
	{
	  sprintf (buff2, "GetSubstring($%s,%s,%s)", buff, p1, p2);
	}
      else
	{
	  sprintf (buff2, "$%s=WriteSubstring($%s,%s,%s,", buff, buff, p1, p2);
	}
      strcpy (buff, buff2);
    } else {
  if (buff[0]!='$') {
		char buff2[2000];
	sprintf(buff2,"$%s",buff);
	strcpy(buff,buff2);
  }
	}
  return strdup(buff);

}







static char *
decode_ival_define1 (int n)
{
  static char buff[256];
  int l;

  if (n == 0x602)
    return "IfxIntervalQual.IfxIntervalYear";
  if (n == 0x84a)
    return "IfxIntervalQual.IfxIntervalDay";
  if (n == 0xa6d)
    return "IfxIntervalQual.IfxIntervalHour3";

  //printf("-->%x (n==0x602)=%d \n",n, n==0x602);

  l = (n >> 8) & 0xf;
  if (l == 6)
    {
      switch ((n >> 4) & 0xf)
	{
	case 1:
	  return "IfxIntervalQual.IfxIntervalYear";
	case 2:
	  return "IfxIntervalQual.IfxIntervalMONTH";
	case 3:
	  return "IfxIntervalQual.IfxIntervalDAY";
	case 4:
	  return "IfxIntervalQual.IfxIntervalHOUR";
	case 5:
	  return "IfxIntervalQual.IfxIntervalMINUTE";
	case 6:
	  return "IfxIntervalQual.IfxIntervalSECOND";
	case 7:
	  return "IfxIntervalQual.IfxIntervalFraction1";
	case 8:
	  return "IfxIntervalQual.IfxIntervalFraction2";
	case 9:
	  return "IfxIntervalQual.IfxIntervalFraction3";
	case 10:
	  return "IfxIntervalQual.IfxIntervalFraction4";
	case 11:
	  return "IfxIntervalQual.IfxIntervalFraction5";
	}
    }
  else
    {
      switch ((n >> 4) & 0xf)
	{
	case 1:
	  sprintf (buff, "IfxIntervalQual.IfxIntervalYear%d", l);
	  return buff;
	case 2:
	  sprintf (buff, "IfxIntervalQual.IfxIntervalMonth%d", l);
	  return buff;
	case 3:
	  sprintf (buff, "IfxIntervalQual.IfxIntervalDay%d", l);
	  return buff;
	case 4:
	  sprintf (buff, "IfxIntervalQual.IfxIntervalHour%d", l);
	  return buff;
	case 5:
	  sprintf (buff, "IfxIntervalQual.IfxIntervalMinute%d", l);
	  return buff;
	case 6:
	  sprintf (buff, "IfxIntervalQual.IfxIntervalSecond%d", l);
	  return buff;

	}

    }
  printf ("%x @ %d\n", n, yylineno);
  A4GL_assertion (1, "Unknown CURRENT 9.1");
  return "";
}



static char *
decode_ival_define2 (int n)
{
  if (n == 0x602)
    return "IfxIntervalQual.IfxIntervalMonth";
  if (n == 0x84a)
    return "IfxIntervalQual.IfxIntervalSecond";
  if (n == 0xa6d)
    return "IfxIntervalQual.IfxIntervalFraction3";
  switch (n & 0xf)
    {
    case 1:
      return "IfxIntervalQual.IfxIntervalYear";
    case 2:
      return "IfxIntervalQual.IfxIntervalMonth";
    case 3:
      return "IfxIntervalQual.IfxIntervalDay";
    case 4:
      return "IfxIntervalQual.IfxIntervalHour";
    case 5:
      return "IfxIntervalQual.IfxIntervalMinute";
    case 6:
      return "IfxIntervalQual.IfxIntervalSecond";
    case 7:
      return "IfxIntervalQual.IfxIntervalFraction1";
    case 8:
      return "IfxIntervalQual.IfxIntervalFraction2";
    case 9:
      return "IfxIntervalQual.IfxIntervalFraction3";
    case 10:
      return "IfxIntervalQual.IfxIntervalFraction4";
    case 11:
      return "IfxIntervalQual.IfxIntervalFraction5";
    }
  A4GL_assertion (1, "Unknown CURRENT 8.1");
  return "";
}


static char * decode_current1 (int n)
{
  switch (n)
    {
    case 1:
      return "YEAR";
    case 2:
      return "MONTH";
    case 3:
      return "DAY";
    case 4:
      return "HOUR";
    case 5:
      return "MINUTE";
    case 6:
      return "SECOND";
    case 7:
      return "FRACTION(1)";
    case 8:
      return "FRACTION(2)";
    case 9:
      return "FRACTION(3)";
    case 10:
      return "FRACTION(4)";
    case 11:
      return "FRACTION(5)";
    }
  printf ("LINE : %d %d\n", yylineno, n);
  A4GL_assertion (1, "BAD Current");
  return "";
}

static char * decode_current2 (int n)
{

  switch (n)
    {
    case 1:
      return "YEAR";
    case 2:
      return "MONTH";
    case 3:
      return "DAY";
    case 4:
      return "HOUR";
    case 5:
      return "MINUTE";
    case 6:
      return "SECOND";
    case 7:
      return "FRACTION(1)";
    case 8:
      return "FRACTION(2)";
    case 9:
      return "FRACTION(3)";
    case 10:
      return "FRACTION(4)";
    case 11:
      return "FRACTION(5)";
    }

  printf ("LINE : %d n=%d\n", yylineno, n);

  A4GL_assertion (1, "BAD Current");
  return "";
}


static char * decode_extend (int n)
{
  static char buff[200];
  char *start;
  char *end;
  start = decode_current1 (n >> 4);
  end = decode_current2 (n & 0xf);
  sprintf (buff, "%s TO %s", start, end);
  return buff;
}





/*
static void
print_attributes (attrib * x)
{

  printc_safe_to_split_at_comma ("%s", get_attributes_as_string (x));
}
*/

static void
print_input_binding (char *buff, struct expr_str_list *list)
{
  int a;
  //printc ("IfxBinding InBind=BuildIfxBinding();");
  if (list == 0)
    return;
  if (list->list.list_len == 0)
    return;
  for (a = 0; a < list->list.list_len; a++)
    {
      int dtype_sz;
      dtype_sz = get_binding_dtype (list->list.list_val[a]) >> 16;
      switch (get_binding_dtype (list->list.list_val[a]) & DTYPE_MASK)
	{
	case DTYPE_SMINT:
	  printc ("%s->InBind->AppendInt($%s);", buff, generation_get_variable_usage (list->list.list_val[a]));
	  break;
	case DTYPE_INT:
	case DTYPE_SERIAL:
	  printc ("%s->InBind->AppendInt($%s);", buff, generation_get_variable_usage (list->list.list_val[a]));
	  break;
	case DTYPE_FLOAT:
	  printc ("%s->InBind->AppendDouble($%s);", buff, generation_get_variable_usage (list->list.list_val[a]));
	  break;
	case DTYPE_SMFLOAT:
	  printc ("%s->InBind->AppendFloat($%s);", buff, generation_get_variable_usage (list->list.list_val[a]));
	  break;
	case DTYPE_DECIMAL:
	  printc ("%s->InBind->AppendDecimal($%s,%d,%d);", buff, generation_get_variable_usage (list->list.list_val[a]), dtype_sz >> 8,
		  dtype_sz & 255);
	  break;
	case DTYPE_DATE:
	  printc ("%s->InBind->AppendDate($%s);", buff, generation_get_variable_usage (list->list.list_val[a]));
	  break;
	case DTYPE_DTIME:
	  printc ("%s->InBind->AppendDtime($%s,%s,%s);", buff, generation_get_variable_usage (list->list.list_val[a]), decode_dt (dtype_sz, 1),
		  decode_dt (dtype_sz, 2));
	  break;
	case DTYPE_INTERVAL:
	  printc ("%s->InBind->AppendInterval($%s,%s,%s);", buff, generation_get_variable_usage (list->list.list_val[a]),
		  decode_ival_define1 (dtype_sz), decode_ival_define2 (dtype_sz));
	  break;
	case DTYPE_CHAR:
	  printc ("%s->InBind->AppendString($%s, %d);", buff, generation_get_variable_usage (list->list.list_val[a]), dtype_sz);
	  break;
	case DTYPE_VCHAR:
	  printc ("%s->InBind->AppendVarChar($%s, %d);", buff, generation_get_variable_usage (list->list.list_val[a]), dtype_sz);
	  break;
	case DTYPE_BYTE:
	  printc ("%s->InBind->AppendBlob($%s);", buff, generation_get_variable_usage (list->list.list_val[a]));
	  break;
	case DTYPE_TEXT:
	  printc ("%s->InBind->AppendBlob($%s);", buff, generation_get_variable_usage (list->list.list_val[a]));
	  break;
	case 90:
	  printc ("%s->InBind->AppendBoolean($%s);", buff, generation_get_variable_usage (list->list.list_val[a]));
	  break;

	default:
	  printc ("%s->InBind->AppendUnknown%d($%s, %d);", buff, get_binding_dtype (list->list.list_val[a]) & DTYPE_MASK,
		  generation_get_variable_usage (list->list.list_val[a]), dtype_sz);
	  break;
	}
    }
}


static void
print_input_array_binding (char *buff, int a, int dtype,int dtype_sz)
{
  //Oint a;
      //dtype_sz = get_binding_dtype (list->list.list_val[a]) >> 16;
      switch (dtype)
	{
	case DTYPE_SMINT:
	  printc ("%s->InBind->AppendInt();", buff);
	  break;
	case DTYPE_INT:
	case DTYPE_SERIAL:
	  printc ("%s->InBind->AppendInt();", buff);
	  break;
	case DTYPE_FLOAT:
	  printc ("%s->InBind->AppendDouble();", buff);
	  break;
	case DTYPE_SMFLOAT:
	  printc ("%s->InBind->AppendFloat();", buff);
	  break;
	case DTYPE_DECIMAL:
	  printc ("%s->InBind->AppendDecimal(%d,%d);", buff,  dtype_sz >> 8, dtype_sz & 255);
	  break;
	case DTYPE_DATE:
	  printc ("%s->InBind->AppendDate();", buff);
	  break;
	case DTYPE_DTIME:
	  printc ("%s->InBind->AppendDtime(%s,%s);", buff, decode_dt (dtype_sz, 1), decode_dt (dtype_sz, 2));
	  break;
	case DTYPE_INTERVAL:
	  printc ("%s->InBind->AppendInterval(%s,%s);", buff, decode_ival_define1 (dtype_sz), decode_ival_define2 (dtype_sz));
	  break;
	case DTYPE_CHAR:
	  printc ("%s->InBind->AppendString(%d);", buff , dtype_sz);
	  break;
	case DTYPE_VCHAR:
	  printc ("%s->InBind->AppendVarChar(%d);", buff,  dtype_sz);
	  break;
	case DTYPE_BYTE:
	  printc ("%s->InBind->AppendBlob();", buff);
	  break;
	case DTYPE_TEXT:
	  printc ("%s->InBind->AppendBlob();", buff);
	  break;
	case 90:
	  printc ("%s->InBind->AppendBoolean();", buff);
	  break;

	default:
	  printc ("%s->InBind->AppendUnknown%d();", buff, dtype);
	  break;
	}

}
void
print_in_binding_using (struct expr_str_list *list) {
  int a;
  printc ("{");
  tmp_ccnt++;

print_in_binding(list);

return ;


  printc("$InBind=BuildSQLBinding(); ");
  if (list == 0)
    return;
  if (list->list.list_len == 0)
    return;
  for (a = 0; a < list->list.list_len; a++)
    {
      int dtype_sz;
      dtype_sz = get_binding_dtype (list->list.list_val[a]) >> 16;
      switch (get_binding_dtype (list->list.list_val[a]) & DTYPE_MASK)
	{
	case DTYPE_SMINT:
	  printc ("$InBind->AppendInt($%s);", generation_get_variable_usage (list->list.list_val[a]));
	  break;
	case DTYPE_INT:
	case DTYPE_SERIAL:
	  printc ("$InBind->AppendInt($%s);", generation_get_variable_usage (list->list.list_val[a]));
	  break;
	case DTYPE_FLOAT:
	  printc ("$InBind->AppendDouble($%s);", generation_get_variable_usage (list->list.list_val[a]));
	  break;
	case DTYPE_SMFLOAT:
	  printc ("$InBind->AppendFloat($%s);", generation_get_variable_usage (list->list.list_val[a]));
	  break;
	case DTYPE_DECIMAL:
	  printc ("$InBind->AppendDecimal($%s,%d,%d);", generation_get_variable_usage (list->list.list_val[a]), dtype_sz >> 8,
		  dtype_sz & 255);
	  break;
	case DTYPE_DATE:
	  printc ("$InBind->AppendDate($%s);", generation_get_variable_usage (list->list.list_val[a]));
	  break;
	case DTYPE_DTIME:
	  printc ("$InBind->AppendDtime($%s,%s,%s);", generation_get_variable_usage (list->list.list_val[a]), decode_dt (dtype_sz, 1),
		  decode_dt (dtype_sz, 2));
	  break;
	case DTYPE_INTERVAL:
	  printc ("$InBind->AppendInterval($%s,%s,%s);", generation_get_variable_usage (list->list.list_val[a]),
		  decode_ival_define1 (dtype_sz), decode_ival_define2 (dtype_sz));
	  break;
	case DTYPE_CHAR:
	  printc ("$InBind->AppendString($%s, %d);", generation_get_variable_usage (list->list.list_val[a]), dtype_sz);
	  break;
	case DTYPE_VCHAR:
	  printc ("$InBind->AppendVarChar($%s, %d);", generation_get_variable_usage (list->list.list_val[a]), dtype_sz);
	  break;
	case DTYPE_BYTE:
	  printc ("$InBind->AppendBlob($%s);", generation_get_variable_usage (list->list.list_val[a]));
	  break;
	case DTYPE_TEXT:
	  printc ("$InBind->AppendBlob($%s);", generation_get_variable_usage (list->list.list_val[a]));
	  break;
	default:
	  printc ("$InBind->AppendUnknown%d($%s, %d);", get_binding_dtype (list->list.list_val[a]) & DTYPE_MASK,
		  generation_get_variable_usage (list->list.list_val[a]), dtype_sz);
	  break;
	}
    }

}

void
print_in_binding (struct expr_str_list *list)
{
  int a;
  printc ("$InBind=BuildSQLBinding();");
  if (list == 0)
    return;
  if (list->list.list_len == 0)
    return;
  for (a = 0; a < list->list.list_len; a++)
    {
      int dtype_sz;
	set_nonewlines();
      dtype_sz = get_binding_dtype (list->list.list_val[a]) >> 16;
      switch (get_binding_dtype (list->list.list_val[a]) & DTYPE_MASK)
	{
	case DTYPE_SMINT:
	  printc ("$InBind->AppendInt(");
	  break;
	case DTYPE_INT:
	case DTYPE_SERIAL:
	  printc ("$InBind->AppendInt(");
	  break;
	case DTYPE_FLOAT:
	  printc ("$InBind->AppendDouble(");
	  break;
	case DTYPE_SMFLOAT:
	  printc ("$InBind->AppendFloat(");
	  break;
	case DTYPE_DECIMAL:
	  printc ("$InBind->AppendDecimal(%d,%d,", dtype_sz >> 8,
		  dtype_sz & 255);
	  break;
	case DTYPE_DATE:
	  printc ("$InBind->AppendDate(");
	  break;
	case DTYPE_DTIME:
	  printc ("$InBind->AppendDtime(%s,%s,",  decode_dt (dtype_sz, 1),
		  decode_dt (dtype_sz, 2));
	  break;
	case DTYPE_INTERVAL:
	  printc ("$InBind->AppendInterval(%s,%s,",
		  decode_ival_define1 (dtype_sz), decode_ival_define2 (dtype_sz));
	  break;
	case DTYPE_CHAR:
	  printc ("$InBind->AppendString(%d,",  dtype_sz);
	  break;
	case DTYPE_VCHAR:
	  printc ("$InBind->AppendVarChar(%d,",  dtype_sz);
	  break;
	case DTYPE_BYTE:
	  printc ("$InBind->AppendBlob(" );
	  break;
	case DTYPE_TEXT:
	  printc ("$InBind->AppendBlob(");
	  break;

	default:
	  printc ("$InBind->AppendUnknown%d(%d,", get_binding_dtype (list->list.list_val[a]) & DTYPE_MASK,
		   dtype_sz);
	  break;
	}
	real_print_expr(list->list.list_val[a]);
	printc(");");
	clr_nonewlines();
    }

}

static void print_copy_frombuff_RSet (char *buff, struct expr_str_list *list) {


  int a;
  int dtype_sz;
  if (list == 0)
    return;
  if (list->list.list_len == 0)
    return;
  for (a = 0; a < list->list.list_len; a++)
    {
      dtype_sz = get_binding_dtype (list->list.list_val[a]) >> 16;
      switch (get_binding_dtype (list->list.list_val[a]) & DTYPE_MASK)
	{
	case DTYPE_SMINT:
	  printc ("%s=%s.GetDataInt(%d);", decode_varbind (list->list.list_val[a], 'R', a), buff,a);
	  break;
	case 90:
	  //printc ("RSet.GetDataBool(%d);", a, decode_varbind (list->list.list_val[a], 'R', a));
	  printc ("%s=%s.GetDataBoolean(%d);", decode_varbind (list->list.list_val[a], 'R', a),buff,a);
	  break;
	case DTYPE_SERIAL:
	case DTYPE_INT:
	  printc ("%s=%s.GetDataInt(%d);", decode_varbind (list->list.list_val[a], 'R', a), buff,a);
	  break;
	case DTYPE_FLOAT:
	  printc ("%s=%s.GetDataDouble(%d);", decode_varbind (list->list.list_val[a], 'R', a), buff,a);
	  break;
	case DTYPE_SMFLOAT:
	  printc ("%s=%s.GetDataFloat(%d);", decode_varbind (list->list.list_val[a], 'R', a), buff,a);
	  break;
	case DTYPE_DECIMAL:
	  printc ("%s=%s.GetDataDecimal(%d,%d,%d);", decode_varbind (list->list.list_val[a], 'R', a), buff,a,
		  dtype_sz >> 8, dtype_sz & 255);
	  break;
	case DTYPE_DATE:
	  printc ("%s=%s.GetDataDate(%d);", decode_varbind (list->list.list_val[a], 'R', a), buff,a);
	  break;
	case DTYPE_DTIME:
	  printc ("%s=%s.GetDataDtime(%d,%s,%s);", decode_varbind (list->list.list_val[a], 'R', a), buff,a,
		  decode_dt (dtype_sz, 1), decode_dt (dtype_sz, 2));
	  break;

	case DTYPE_INTERVAL:
	{
		int sz;
		sz=dtype_sz;
	  if (sz) {
	  if (((sz >> 4) & 0xf) <= 2)
	  	printc ("%s=%s.GetDataMonthSpan(%d,%s,%s);", decode_varbind (list->list.list_val[a], 'R', a), buff,a, decode_ival_define1 (dtype_sz), decode_ival_define2 (dtype_sz));
	else
	  	printc ("%s=%s.GetDataTimeSpan(%d,%s,%s);", decode_varbind (list->list.list_val[a], 'R', a), buff,a, decode_ival_define1 (dtype_sz), decode_ival_define2 (dtype_sz));
		
	  } else {
	  	printc ("%s=%s.GetDataInterval(%d,%s,%s);", decode_varbind (list->list.list_val[a], 'R', a), buff,a, decode_ival_define1 (dtype_sz), decode_ival_define2 (dtype_sz));
	  }
	}
	  break;

	case DTYPE_NCHAR:
	case DTYPE_CHAR:
	  printc ("%s=%s.GetDataString(%d,%d);", decode_varbind (list->list.list_val[a], 'R', a), buff,a, dtype_sz);
	  break;
	case DTYPE_VCHAR:
	  printc ("%s=%s.GetDataVarString(%d,%d);", decode_varbind (list->list.list_val[a], 'R', a), buff,a, dtype_sz);
	  break;
	case DTYPE_BYTE:
	  printc ("%s.GetDataBlob(%d,%s);", buff, a, decode_varbind (list->list.list_val[a], 'R', a));
	  break;
	case DTYPE_TEXT:
	  printc ("%s.GetDataBlob(%d,%s);", buff, a, decode_varbind (list->list.list_val[a], 'R', a));
	  break;

	default:
	  printc ("%s=%s.GetDataUnknown%d(%d);", decode_varbind (list->list.list_val[a], 'R', a),buff,
		  get_binding_dtype (list->list.list_val[a]) & DTYPE_MASK, a);
	}
    }

}


void
print_copy_fromRSet (struct expr_str_list *list)
{
	print_copy_frombuff_RSet("$RSet",list);
}


static void
print_when_sql_start ()
{
  printc ("try {");
  tmp_ccnt++;
}


static void
print_when_sql_end ()
{
  tmp_ccnt--;
  if (mod_whencode[1] == 2)
    {				// Call...

      printc ("} catch (Exception $e) {");

      printc ("       SQLSetError($e);");
      if (strcmp (mod_whento[1], "get_error_record") == 0)
	{
	  printc ("       SQLReportError($e);");
	}
      else
	{
	  printc ("       %s();", mod_whento[1]);
	}
      printc ("}");
    }

  if (mod_whencode[1] == 1)
    {				// Stop
      printc ("} catch (Exception $e) {");
      printc ("       SQLSetError($e);");
      printc ("       throw; /* STOP */");
      printc ("}");
    }
  if (mod_whencode[1] == 0)
    {				// continue
      printc ("} catch (Exception $e) {");
      printc ("       SQLSetError($e);");
      printc ("       ; /* CONTINUE */ ");
      printc ("}");
    }

}


static void
stradd (char *s1, char *s2)
{
  if (strlen (s1))
    {
      if (strcmp (s1, "\"") == 0);
      else
	{
	  strcat (s1, ",");
	}
    }
  strcat (s1, s2);
}

static void
print_window_attributes (attrib * x)
{
  if (x == NULL)
    {
      printc ("false,0,0,0,0,0,0,\"\",\"\"");
      return;
    }
  if (x->border == EB_TRUE)
    {
      printc ("true");
    }
  else
    {
      printc ("false");
    }
  printc (",");
  if (x->comment_line != NULL)
    {
      real_print_expr (x->comment_line);
    }
  else
    {
      printc ("0");
    }
  printc (",");
  if (x->form_line != NULL)
    {
      real_print_expr (x->form_line);
    }
  else
    {
      printc ("0");
    }
  printc (",");
  if (x->error_line != NULL)
    {
      real_print_expr (x->error_line);
    }
  else
    {
      printc ("0");
    }
  printc (",");
  if (x->menu_line != NULL)
    {
      real_print_expr (x->menu_line);
    }
  else
    {
      printc ("0");
    }
  printc (",");
  if (x->message_line != NULL)
    {
      real_print_expr (x->message_line);
    }
  else
    {
      printc ("0");
    }
  printc (",");
  if (x->prompt_line != NULL)
    {
      real_print_expr (x->prompt_line);
    }
  else
    {
      printc ("0");
    }
  printc (",");
  if (x->var_attrib != NULL)
    {
      real_print_expr (x->var_attrib);
    }
  else
    {
      printc ("\"\"");
    }
  printc (",");
  printc ("%s", get_attributes_as_string (x));
}

char *
get_attributes_as_string (attrib * x)
{
  //int printed = 0;
  //static char buff[1000];
  //char smbuff[256];
  static char buff[10000] = "";

  if (x == NULL)
    return "\"\"";


  if (x->color != -1)
    {
      sprintf (buff, "\"COLOUR=%d", x->color);
    }
  else
    {
      strcpy (buff, "\"");
    }

  if (x->nonewlines == EB_TRUE || x->no_new_lines == EB_TRUE)
    {
      stradd (buff, "NO NEW LINES");
    }
  if (x->bold == EB_TRUE)
    {
      stradd (buff, "BOLD");
    }
  if (x->blink == EB_TRUE)
    {
      stradd (buff, "BLINK");
    }
  if (x->reverse == EB_TRUE)
    {
      stradd (buff, "REVERSE");
    }
  if (x->dim == EB_TRUE)
    {
      stradd (buff, "DIM");
    }
  if (x->invisible == EB_TRUE)
    {
      stradd (buff, "INVISIBLE");
    }
  if (x->underline == EB_TRUE)
    {
      stradd (buff, "UNDERLINE");
    }
  if (x->normal == EB_TRUE)
    {
      stradd (buff, "NORMAL");
    }
  if (x->allow_insert == EB_TRUE)
    {
      stradd (buff, "ALLOW INSERT");
    }
  if (x->allow_delete == EB_TRUE)
    {
      stradd (buff, "ALLOW DELETE");
    }
  strcat (buff, "\"");
  return buff;
}


static void
init_var (struct expr_str *b)
{
  int dtype;
  dtype = get_binding_dtype (b);

  if ((dtype & DTYPE_MASK) == 10)
    {
      printc ("%s=null;", decode_varbind (b, 'R', 0));
      return;
    }

  if ((dtype & DTYPE_MASK) ==90) // Boolean
    {
      printc ("%s=false;", decode_varbind (b, 'R', 0));
      return;
    }

  if ((dtype & DTYPE_MASK) == DTYPE_INTERVAL)
    {
      printc ("%s=null;", decode_varbind (b, 'R', 0));
      return;
    }
  if ((dtype & DTYPE_MASK) == 2)
    {
      printc ("%s=null;", decode_varbind (b, 'R', 0));
      return;
    }
  if ((dtype & DTYPE_MASK) == DTYPE_DECIMAL)
    {
      printc ("%s=null;", decode_varbind (b, 'R', 0));
      return;
    }
  if ((dtype & DTYPE_MASK) == 1)
    {
      printc ("%s=null;", decode_varbind (b, 'R', 0));
      return;
    }
  if ((dtype & DTYPE_MASK) == 0)
    {
      printc ("%s=null;", decode_varbind (b, 'R', 0));
      return;
    }
  printc ("%s=null;", decode_varbind (b, 'R', 0));
}


char *
A4GL_field_name_as_char (char *fname, char *sub)
{
  static char buff[256];
  SPRINTF2 (buff, "new AubitField(\"%s\",%s)", fname, sub);
  return buff;
}



char *
field_name_as_char (fh_field_entry * fh)
{
  //char a[200];
  //char b[200];
  if (fh->fieldsub.fieldsub)
    {
      return A4GL_field_name_as_char (get_ident (fh->field.field,0), local_expr_as_string (fh->fieldsub.fieldsub));
    }
  else
    {
      return A4GL_field_name_as_char (get_ident (fh->field.field,0), "1");
    }

}



static struct variable * local_find_variable_from_usage (struct variable_usage *u)
{
  struct variable *v = 0;

// If this assertion fails - make sure you've run the expression containing the
// variable usage through the "ensure_variable" function to set up the scope/datatype and variable ids..
  A4GL_assertion (u->variable_id < 0, "Variable has not been previously found..");


  switch (u->escope)
    {
    case E_SCOPE_LOCAL:	// list_local_cnt
      A4GL_assertion (u->variable_id >= current_entry_variables->variables.variables_len, "Invalid VARIABLE ID");
      v = current_entry_variables->variables.variables_val[u->variable_id];
      break;
    case E_SCOPE_MODULE:	// list_module
      A4GL_assertion (u->variable_id >= curr_module->module_variables.variables.variables.variables_len, "Invalid VARIABLE ID");
      v = curr_module->module_variables.variables.variables.variables_val[u->variable_id];
      break;
    case E_SCOPE_EXPORTED_GLOBAL:	// list_globals
      A4GL_assertion (u->variable_id >= curr_module->exported_global_variables.variables.variables.variables_len, "Invalid VARIABLE ID");
      v = curr_module->exported_global_variables.variables.variables.variables_val[u->variable_id];
      break;
    case E_SCOPE_IMPORTED_GLOBAL:	// list_imported_global
      A4GL_assertion (u->variable_id >= curr_module->imported_global_variables.variables.variables.variables_len, "Invalid VARIABLE ID");
      v = curr_module->imported_global_variables.variables.variables.variables_val[u->variable_id];
      break;


    default:
      A4GL_assertion (1, "Unexpected scope type...");

    }
  if (v == 0)
    {
      A4GL_assertion (1, "Couldn't find variable");
    }

// Quick double check...
  if (strcmp (u->variable_name, v->names.names.names_val[0].name) != 0)
    {
      // Looks different..
      A4GL_assertion (1, "Variable name doesnt match");
    }


  if (u->next)
    {
      // We're expecting the variable to be a record...
      A4GL_assertion (v->var_data.variable_type != VARIABLE_TYPE_RECORD, "Expecting a record");
      while (u->next)
	{
	  u = u->next;
	  A4GL_assertion (u->variable_id < 0, "Variable not ensured...");
	  A4GL_assertion (u->variable_id > v->var_data.variable_data_u.v_record.variables.variables_len, "Variable out of range");
	  v = v->var_data.variable_data_u.v_record.variables.variables_val[u->variable_id];
	}

    }

  return v;
}


static int
print_init_cmd (struct_init_cmd * cmd_data)
{
  print_cmd_start ();
  int a;
  int printed = 0;
  //struct expr_str_list* varlist;
  //str_list* tablist;
  for (a = 0; a < cmd_data->varlist->list.list_len; a++)
    {
      struct variable_usage *u;
      struct variable_usage *u_bottom;
      struct variable *v;
      printed = 0;

      A4GL_assertion (cmd_data->varlist->list.list_val[a]->expr_type != ET_EXPR_VARIABLE_USAGE, "Expecting a variable usage");
      u = cmd_data->varlist->list.list_val[a]->expr_str_u.expr_variable_usage;

      v = local_find_variable_from_usage (u);

      u_bottom = u;

      while (u_bottom->next)
	{
	  u_bottom = u_bottom->next;
	}


      if (v->arr_subscripts.arr_subscripts_len)
	{

	  // The variable is an array..
	  if (u_bottom->subscripts.subscripts_len == 0)
	    {
	      // We need to null the whole variable
	      print_init_var (v, generation_get_variable_usage_as_string (u), 0, 1, 1, 1, cmd_data->tonull);
	    }
	  else
	    {
	      struct variable v2;
	      if (u_bottom->subscripts.subscripts_len != v->arr_subscripts.arr_subscripts_len)
		{
		  a4gl_yyerror ("Subscript mismatch");
		  return 0;
		}
	      // We need to null the this specific on..
	      memcpy (&v2, v, sizeof (v2));
	      v2.arr_subscripts.arr_subscripts_len = 0;
	      v2.arr_subscripts.arr_subscripts_val = 0;


	      if (cmd_data->tablist)
		{
		  if (cmd_data->init_like_exprlist && cmd_data->init_like_exprlist->list.list_len <= a)
		    {
		      if (cmd_data->init_like_exprlist->list.list_val[a])
			{
			  printc ("%s", decode_varbind (cmd_data->varlist->list.list_val[a], 'w', 0));
			  ensure_dtype (" ", 0, cmd_data->init_like_exprlist->list.list_val[a],
					get_binding_dtype (cmd_data->varlist->list.list_val[a]), 0);
			  real_print_expr (cmd_data->init_like_exprlist->list.list_val[a]);
			  printc (";");
			  printed = 1;
			}
		    }
		}


	      if (!printed)
		{
		  print_init_var (v, generation_get_variable_usage_as_string (u), 0, 1, 1, 0, cmd_data->tonull);
		}
	    }
	}
      else
	{
	  if (cmd_data->tablist)
	    {
	      if (cmd_data->init_like_exprlist && a < cmd_data->init_like_exprlist->list.list_len)
		{
		  if (cmd_data->init_like_exprlist->list.list_val[a])
		    {
		      printc ("%s", decode_varbind (cmd_data->varlist->list.list_val[a], 'w', 0));
		      ensure_dtype (" ", 0, cmd_data->init_like_exprlist->list.list_val[a],
				    get_binding_dtype (cmd_data->varlist->list.list_val[a]), 0);
		      real_print_expr (cmd_data->init_like_exprlist->list.list_val[a]);
		      printed = 1;
		    }
		}
	    }
	  if (!printed)
	    {
	      char *s;
	      s = generation_get_variable_usage_as_string (u);
	      // Its not an array..
	      print_init_var (v, s, 0, 1, 1, 1, cmd_data->tonull);
	    }
	}

    }

  //print_copy_status_not_sql (0);
  return 1;
}




static int
dump_cmd (struct command *r, struct command *parent)
{
  int a;
  //char *cprefix;
  A4GL_assertion (r->module == 0, "No module");
/*
  if (isInReport ())
    {
      cprefix = "thisApp";
    }
  else
    {
      cprefix = "this";
    }
*/


  //printf ("Dumping command type : %d (%s %d)\n", r->cmd_data.type, r->module, r->lineno);
  A4GL_debug ("Dumping command type : %d (%s %d)\n", r->cmd_data.type, r->module, r->lineno);
printc("/* %s.%d : %s */",  r->module, r->lineno, decode_cmd_type(r->cmd_data.type));
  yylineno = r->lineno;

  dump_comments (r->lineno);

  switch (r->cmd_data.type)
    {

    case E_CMD_STOP_RPC_CMD:
      printc ("// ...");
      break;
      printc ("STOP ALL EXTERNAL");
      break;
    case E_CMD_PAUSE_SCREEN_ON_CMD:
      printc ("// ...");
      break;
      printc ("SET PAUSE MODE ON");
      break;
    case E_CMD_PAUSE_SCREEN_OFF_CMD:
      printc ("// ...");
      break;
      printc ("SET PAUSE MODE OFF");
      break;

    case E_CMD_SKIP_TO_TOP_CMD:
      printc ("Driver.SkipToTopOfPage();");
      break;




    case E_CMD_CALL_CMD:
      {
	int has_parm = 0;
	int usingMappingVariables = 0;
	struct expr_str *fcall;
	char *fname = "<unknown>";
	int needClose = 0;
	char **outvars = 0;
	long *forceDatatypes = 0;


	fcall = r->cmd_data.command_data_u.call_cmd.fcall;


	if (fcall->expr_type==ET_EXPR_GET_FLDBUF) {
		fname="get_fldbuf";
		printc("//@ FGLCHECK FIXME - get_fldbuf not callable yet");	
		break;
	}


	if (fcall->expr_type == ET_EXPR_FCALL)
	  {
	    fname = fcall->expr_str_u.expr_function_call->functionname;
	    //funcno = is_bolton_function (fcall->expr_str_u.expr_function_call->functionname);
	  }


	//nrets = get_bolton_nrets (funcno);

	if (r->cmd_data.command_data_u.call_cmd.returning)
	  {

	    if (r->cmd_data.command_data_u.call_cmd.returning->list.list_len == 0)
	      {
		printc ("/* no returned values */");
		set_nonewlines ();
	      }

	    if (r->cmd_data.command_data_u.call_cmd.returning->list.list_len == 1)
	      {
		set_nonewlines ();
		    	printc ("%s=", decode_varbind (r->cmd_data.command_data_u.call_cmd.returning->list.list_val[0], 'r', 0));
		//clr_nonewlines ();
	      }
	    

	    if (r->cmd_data.command_data_u.call_cmd.returning->list.list_len > 1) {
		int a;
		set_nonewlines();
		printc("list(");
		for (a=0;a<r->cmd_data.command_data_u.call_cmd.returning->list.list_len ;a++) {
			if (a) printc(",");
	     		printc ("%s", decode_varbind (r->cmd_data.command_data_u.call_cmd.returning->list.list_val[a], 'r', 0));
		}
		printc(")=");
		//clr_nonewlines();
            }
	  }
	else
	  {
	    set_nonewlines ();
	  }






	if (r->cmd_data.command_data_u.call_cmd.fcall->expr_str_u.expr_function_call->parameters)
	  {
	    if (r->cmd_data.command_data_u.call_cmd.fcall->expr_str_u.expr_function_call->parameters->list.list_len)
	      has_parm++;
	  }

	real_print_func_call (r->cmd_data.command_data_u.call_cmd.fcall, 0);

	printc (");");
	clr_nonewlines ();

      }
      break;


    case E_CMD_CASE_CMD:
      {
	int uses_exit = 0;
        int cant_use_switch=0;

	case_level++;
	case_id[case_level] = case_num++;
	printc ("#");

	// SWITCH in C# can only work with constant values
	// so if anything is not a literal - we can't use it for a switch
	if (r->cmd_data.command_data_u.case_cmd.case_expr) {
	for (a = 0; a < r->cmd_data.command_data_u.case_cmd.whens->whens.whens_len; a++) {
		switch (r->cmd_data.command_data_u.case_cmd.whens->whens.whens_val[a]->when_expr->expr_type) {
    			case ET_EXPR_LITERAL_EMPTY_STRING:
    			case ET_EXPR_LITERAL_STRING:
    			case ET_EXPR_LITERAL_LONG:
 			case ET_EXPR_LITERAL_DOUBLE_STR:
				continue;
			default:
				printf("Cant use 'switch' because of %s\n", expr_name(r->cmd_data.command_data_u.case_cmd.whens->whens.whens_val[a]->when_expr->expr_type));
				cant_use_switch=1;
				break;
		}
		if (cant_use_switch) break;

	}

        } else {
		cant_use_switch=1;
	}

	if (cant_use_switch==0) 
	  {
	int dtype;
	    printc ("//CASE CMD (with expression)");
	    set_nonewlines ();
	    printc ("switch( ");
			dtype=expr_datatype(0,0,r->cmd_data.command_data_u.case_cmd.case_expr) & DTYPE_MASK;
		if (dtype==DTYPE_CHAR || dtype==DTYPE_VCHAR) {
			printc("SwitchTrim(");
	    		real_print_expr (r->cmd_data.command_data_u.case_cmd.case_expr);
			printc(")");
		} else {
	    		real_print_expr (r->cmd_data.command_data_u.case_cmd.case_expr);
		}
	    printc (") {");
	    clr_nonewlines ();
	  }
	else
	  {
		cant_use_switch=1;
		if (r->cmd_data.command_data_u.case_cmd.case_expr) {
	    		printc ("/* FGLCHECK: CASE CMD (with expression - but variable WHENs) */");
		} else {
	    		printc ("/* FGLCHECK: CASE CMD (with no expression) */");
		}
	    //printc ("while (true) {");
	  }

	tmp_ccnt++;

	for (a = 0; a < r->cmd_data.command_data_u.case_cmd.whens->whens.whens_len; a++)
	  {
	    if (cant_use_switch==0)
	      {
		set_nonewlines ();
		printc ("case ");
		real_print_expr (r->cmd_data.command_data_u.case_cmd.whens->whens.whens_val[a]->when_expr);
		printc (":");
		clr_nonewlines ();
		tmp_ccnt++;

		if (uses_exit_case (r->cmd_data.command_data_u.case_cmd.whens->whens.whens_val[a]->when_commands))
		  uses_exit++;

		dump_cmds (r->cmd_data.command_data_u.case_cmd.whens->whens.whens_val[a]->when_commands, r);
		tmp_ccnt--;
		printc ("break;");
	      }
	    else
	      {
		set_nonewlines ();

		if (r->cmd_data.command_data_u.case_cmd.case_expr==0) {
			// Theres no expression - so it must be boolean for each WHEN
			//ensure_bool (r->module, r->lineno, r->cmd_data.command_data_u.case_cmd.whens->whens.whens_val[a]->when_expr, 1);
		}

		if (a)
		  printc ("else if (");
		else
		  printc ("if (");


		if (r->cmd_data.command_data_u.case_cmd.case_expr==0) {
			real_print_expr (r->cmd_data.command_data_u.case_cmd.whens->whens.whens_val[a]->when_expr);
		} else {
			struct expr_str p;
			struct s_expr_op o;
			p.expr_str_u.expr_op=&o;
			p.expr_type=ET_EXPR_OP_EQUAL;
			p.expr_str_u.expr_op->left=r->cmd_data.command_data_u.case_cmd.case_expr;
			p.expr_str_u.expr_op->right=r->cmd_data.command_data_u.case_cmd.whens->whens.whens_val[a]->when_expr;
			real_print_expr (&p);
		}

		printc (") {");
		clr_nonewlines ();
		tmp_ccnt++;
		if (uses_exit_case (r->cmd_data.command_data_u.case_cmd.whens->whens.whens_val[a]->when_commands))
		  uses_exit++;
		dump_cmds (r->cmd_data.command_data_u.case_cmd.whens->whens.whens_val[a]->when_commands, r);
		tmp_ccnt--;
		printc ("}");
	      }
	  }

	if (r->cmd_data.command_data_u.case_cmd.otherwise)
	  {
	    if (uses_exit_case (r->cmd_data.command_data_u.case_cmd.otherwise))
	      uses_exit++;

	    if (cant_use_switch==0)
	      {

		printc ("default: ");
		tmp_ccnt++;
		dump_cmds (r->cmd_data.command_data_u.case_cmd.otherwise, r);
		printc ("break;");
		tmp_ccnt--;
		printc ("}");
	      }
	    else
	      {
		printc ("else {");
		dump_cmds (r->cmd_data.command_data_u.case_cmd.otherwise, r);
		printc ("}");
		//printc ("break;");

	      }
	  }
	else
	  {

	    if (cant_use_switch==0) {
		printc ("}");
	      }
	    //printc ("break; /* No otherwise */");
	  }


	/* A4GL_warn("Coding Standards: CASE has no OTHERWISE"); */


	tmp_ccnt--;

	//printc ("}");
	if (uses_exit)
	  {
	    printc ("end_case_%d: ; ", case_id[case_level]);
	  }
	case_level--;
	printc ("// END CASE");
	printc ("#");

	break;
      }

    case E_CMD_CLOSE_CMD:
      switch (r->cmd_data.command_data_u.close_cmd.cl_type)
	{
	case E_CT_WINDOW:
	  printc ("UILib_CloseWindow(\"%s\");", get_ident (r->cmd_data.command_data_u.close_cmd.ident,0));
	  break;
	case E_CT_FORM:
	  printc ("UILib_CloseForm(\"%s\");", get_ident (r->cmd_data.command_data_u.close_cmd.ident,0));
	  break;
	case E_CT_STATUSBOX:
	  printc ("// CLOSE STATUSBOX %s", get_ident (r->cmd_data.command_data_u.close_cmd.ident,0));
	  break;
	}
      break;

    case E_CMD_CLOSE_SQL_CMD:
      switch (r->cmd_data.command_data_u.close_cmd.cl_type)
	{
	case E_CT_DATABASE:
	  printc ("CloseDatabase();");
	  break;
	case E_CT_SESSION:
	  printc ("CloseSession(); /* %s */", get_ident (r->cmd_data.command_data_u.close_cmd.ident,0));
	  break;
	case E_CT_CURS_OR_PREP:
	  printc ("$Cursor_%s.Close();", A4GL_strip_quotes (get_ident (r->cmd_data.command_data_u.close_cmd.ident,1)));
	  break;
	}
      break;

    case E_CMD_CODE_CMD:
      printc ("%s", r->cmd_data.command_data_u.code_cmd.contents);
      break;

    case E_CMD_DEFER_CMD:

      if (r->cmd_data.command_data_u.defer_cmd.what == EDEFER_QUIT)
	{
	  printc ("// DEFER QUIT");
	}
      if (r->cmd_data.command_data_u.defer_cmd.what == EDEFER_INTERRUPT)
	{
	  printc ("// DEFER INTERRUPT");
	}
      break;



    case E_CMD_DISPLAY_CMD:	/* UI */
      switch (r->cmd_data.command_data_u.display_cmd.where->dttype)
	{
	case DT_DISPLAY_TYPE_LINE:
	{
		int expr_dt;
	  set_nonewlines ();
	  printc ("UILib_Display(");
	             expr_dt=expr_datatype(0,0,r->cmd_data.command_data_u.display_cmd.exprs->list.list_val[0]) & DTYPE_MASK;
		//if (expr_dt==DTYPE_CHAR || expr_dt==DTYPE_VCHAR) ;
		//else {
			//printc("\"\"+");
		//}
	  real_print_expr_list_with_separator (r->cmd_data.command_data_u.display_cmd.exprs, ".");
	  printc (");");
	  clr_nonewlines ();
	}
	  break;

	case DT_DISPLAY_TYPE_AT:
	{
		int expr_dt;
	  set_nonewlines ();
	  printc ("UILib_DisplayAtXY(");
	  real_print_expr (r->cmd_data.command_data_u.display_cmd.where->dt_display_u.x_y.x);
	  printc (",");
	  real_print_expr (r->cmd_data.command_data_u.display_cmd.where->dt_display_u.x_y.y);
	  printc (",");

	expr_dt=expr_datatype(0,0,r->cmd_data.command_data_u.display_cmd.exprs->list.list_val[0]) & DTYPE_MASK;
		/*
		if (expr_dt==DTYPE_CHAR || expr_dt==DTYPE_VCHAR) ;
		else {
			printc("\"\"+");
		}
		*/
	  real_print_expr_list_with_separator (r->cmd_data.command_data_u.display_cmd.exprs, ".");
	  printc (");");
	  clr_nonewlines ();
	}
	  break;

	case DT_DISPLAY_TYPE_FIELD_LIST:
		printc("{");
	tmp_ccnt++;
		print_in_binding(r->cmd_data.command_data_u.display_cmd.exprs);
		set_nonewlines();
		printc("UILib_DisplayField(%s,$InBind", get_attributes_as_string (r->cmd_data.command_data_u.display_cmd.attributes));
      		//real_print_expr_list_with_separator (r->cmd_data.command_data_u.display_cmd.exprs,",");
		printc(",%s", field_name_list_as_char (r->cmd_data.command_data_u.display_cmd.where->dt_display_u.field_list));
		printc(");");
		clr_nonewlines();
	tmp_ccnt--;
		printc("}");

        if (r->cmd_data.command_data_u.display_cmd.attributes  && r->cmd_data.command_data_u.display_cmd.attributes->var_attrib) {
			A4GL_assertion(1,"Dynamic attributes not handled yet");
        }

	break;

	default:
	  printc ("/* UI display Not handled yet */");
	  //A4GL_assertion(1,"UI display Not handled yet");
	  break;
	}
      break;






    case E_CMD_ERROR_CMD:
      {
	set_nonewlines ();
	printc ("Error(");
	real_print_expr_list_with_separator (r->cmd_data.command_data_u.error_cmd.expr_list, ".");
	printc (");");
	clr_nonewlines ();
      }
      break;

    case E_CMD_EXT_CMD:
      switch (r->cmd_data.command_data_u.ext_cmd.what)
	{
	case EBC_WHILE:
		print_goto_comment();
	  printc ("goto end_while_%d;", r->cmd_data.command_data_u.ext_cmd.block_id);
	  break;
	case EBC_FOR:
		print_goto_comment();
	  printc ("goto end_for_%d;", r->cmd_data.command_data_u.ext_cmd.block_id);
	  break;

	case EBC_INPUT:
		print_goto_comment();
	  printc ("%s.Exit(); goto continue_input_%d;", get_ui_context (),  r->cmd_data.command_data_u.ext_cmd.block_id);


	  //print_exit_loop ('-', r->cmd_data.command_data_u.ext_cmd.block_id, "INPUT");
	  //printc ("EXIT INPUT");
	  break;
	case EBC_FOREACH:
		print_goto_comment();
	  printc ("goto end_foreach_%d; /* EXIT FOREACH */", r->cmd_data.command_data_u.ext_cmd.block_id);
	  break;
	case EBC_CONSTRUCT:
		print_goto_comment();
	  printc ("%s.Exit(); goto continue_construct_%d;", get_ui_context (), r->cmd_data.command_data_u.ext_cmd.block_id);
	  //print_exit_loop ('-', r->cmd_data.command_data_u.ext_cmd.block_id, "CONSTRUCT");
	  //printc ("EXIT CONSTRUCT");
	  break;
	case EBC_DISPLAY:
		print_goto_comment();
	  printc ("%s.Exit(); goto continue_display_%d;", get_ui_context (),  r->cmd_data.command_data_u.ext_cmd.block_id);
	  //print_exit_loop ('-', r->cmd_data.command_data_u.ext_cmd.block_id, "DISPLAY");
	  //printc ("EXIT DISPLAY");
	  break;
	case EBC_MENU:
		print_goto_comment();
      	printc ("%s.ExitMenu(); goto continue_menu_%d;", get_menu_context (),  r->cmd_data.command_data_u.ext_cmd.block_id);
	  //printc ("EXIT MENU");
	  break;

	case EBC_PROMPT:
	  printc ("%s.Exit();", get_ui_context ());

	  //print_exit_loop ('P', r->cmd_data.command_data_u.ext_cmd.block_id, "PROMPT");
	  //printc ("EXIT PROMPT");
	  break;
	case EBC_CASE:
		print_goto_comment();
	  printc ("goto end_case_%d; /* EXIT CASE */", case_id[case_level]);
	  //printc ("// EXIT CASE ", r->cmd_data.command_data_u.ext_cmd.block_id);
	  break;

	case EBC_SPL_FOR:
	case EBC_SPL_WHILE:
	case EBC_SPL_FOREACH:
		A4GL_assertion(1,"Shouldn't be using SPL commands here");

	}
      break;

    case E_CMD_CONTINUE_CMD:
      switch (r->cmd_data.command_data_u.continue_cmd.what)
	{
	case EBC_WHILE:
		print_goto_comment();
	  printc ("goto continue_while_%d;", r->cmd_data.command_data_u.continue_cmd.block_id);
	  break;
	case EBC_FOR:
		print_goto_comment();
	  printc ("goto continue_for_%d;", r->cmd_data.command_data_u.continue_cmd.block_id);
	  break;
	case EBC_FOREACH:
		print_goto_comment();
	  printc ("goto continue_foreach_%d;", r->cmd_data.command_data_u.continue_cmd.block_id);
	  break;
	case EBC_INPUT:
		print_goto_comment();
	  printc ("%s.Continue(); goto continue_input_%d;", get_ui_context (), r->cmd_data.command_data_u.continue_cmd.block_id);
	  //print_continue_loop (r->cmd_data.command_data_u.continue_cmd.block_id, "INPUT");
	  //printc ("CONTINUE INPUT");
	  break;
	  //case EBC_FOREACH:
	  //print_continue_loop (r->cmd_data.command_data_u.continue_cmd.block_id, "FOREACH");
	  //printc ("CONTINUE FOREACH");
	  //break;
	case EBC_CONSTRUCT:
		print_goto_comment();
	  printc ("%s.Continue(); goto continue_construct_%d;", get_ui_context (),r->cmd_data.command_data_u.continue_cmd.block_id);
	  //print_continue_loop (r->cmd_data.command_data_u.continue_cmd.block_id, "CONSTRUCT");
	  //printc ("CONTINUE CONSTRUCT");
	  break;
	case EBC_DISPLAY:
		print_goto_comment();
	  printc ("%s.Continue(); goto continue_display_%d;", get_ui_context (),r->cmd_data.command_data_u.continue_cmd.block_id);
	  //print_continue_loop (r->cmd_data.command_data_u.continue_cmd.block_id, "DISPLAY");
	  //printc ("CONTINUE DISPLAY");
	  break;
	case EBC_MENU:
		print_goto_comment();
	  printc ("%s.Continue(); goto continue_menu_%d;", get_menu_context (),r->cmd_data.command_data_u.continue_cmd.block_id);
	  //print_continue_loop (r->cmd_data.command_data_u.continue_cmd.block_id, "MENU");
	  //printc ("CONTINUE MENU");
	  break;

	case EBC_PROMPT:
	  printc ("%s.Continue(); continue;", get_ui_context ());
	  //print_continue_loop (r->cmd_data.command_data_u.continue_cmd.block_id, "DISPLAY");
	  //print_continue_loop (r->cmd_data.command_data_u.continue_cmd.block_id, "PROMPT");
	  //printc ("CONTINUE PROMPT");
	  break;
	case EBC_CASE:
	  printc ("CONTINUE CASE");
	  break;
	case EBC_SPL_FOR:
	case EBC_SPL_WHILE:
	case EBC_SPL_FOREACH:
		A4GL_assertion(1,"Shouldn't be using SPL commands here");
	}
      break;


    case E_CMD_EXIT_PROG_CMD:

      if (1)
	{
	  if (current_func == 0)
	    {
	      A4GL_warn ("Coding Standards: EXIT PROGRAM must not be used directly - use CALL exit_prog instead");
	    }
	  else
	    {
	      if (strcmp (current_func->funcname, "exit_prog") != 0)
		{
		  A4GL_warn ("Coding Standards: EXIT PROGRAM must not be used directly - use CALL exit_prog instead");
		}
	    }

	  if (r->cmd_data.command_data_u.exit_prog_cmd.exit_val)
	    {
	      set_nonewlines ();
	      printc ("ExitProgram(");
	      real_print_expr (r->cmd_data.command_data_u.exit_prog_cmd.exit_val);
	      printc (");");
	      clr_nonewlines ();
	    }
	  else
	    {
	      printc ("ExitProgram();");
	      //printc ("EXIT PROGRAM");
	    }
	}
      else
	{
	  if (parent != 0)
	    {
	      A4GL_warn ("Coding Standards: EXIT PROGRAM must only be in main");
	    }
	  else
	    {
	      if (current_func == 0)
		{
		  A4GL_warn ("Coding Standards: EXIT PROGRAM must only be in main");
		}
	      else
		{
		  if (A4GL_aubit_strcasecmp (current_func->funcname, "MAIN") != 0)
		    {
		      A4GL_warn ("Coding Standards: EXIT PROGRAM must only be in main");
		    }
		}
	    }

	  if (r->cmd_data.command_data_u.exit_prog_cmd.exit_val)
	    {
	      set_nonewlines ();
	      printc ("ExitProgram(");
	      real_print_expr (r->cmd_data.command_data_u.exit_prog_cmd.exit_val);
	      printc (");");
	      clr_nonewlines ();
	    }
	  else
	    {
	      printc ("ExitProgram();");
	    }
	}
      break;


    case E_CMD_FOR_CMD:
      {
	int need_step = 1;
	//int for_var_is_module = 0;
	int step_amount;
	int uses_int_step=0;
	enum e_scope scope;
	need_daylight ();
	//printc ("#");
	scope = get_var_expr_scope (r->cmd_data.command_data_u.for_cmd.var);

	need_step = 1;
	if (r->cmd_data.command_data_u.for_cmd.step->expr_type == ET_EXPR_LITERAL_LONG)
	  {
		step_amount=r->cmd_data.command_data_u.for_cmd.step->expr_str_u.expr_long;
		uses_int_step=1;

	    if (r->cmd_data.command_data_u.for_cmd.step->expr_str_u.expr_long == 1)
	      {
		need_step = 0;
	      }
	  }

	if (uses_int_step) {
		set_nonewlines ();
		printc ("for (%s=", decode_varbind (r->cmd_data.command_data_u.for_cmd.var, 'R', 0));
	
		ensure_dtype (r->module, r->lineno,r->cmd_data.command_data_u.for_cmd.start,expr_datatype(0,0,r->cmd_data.command_data_u.for_cmd.var),0);
		real_print_expr (r->cmd_data.command_data_u.for_cmd.start);
		ensure_dtype (r->module, r->lineno,r->cmd_data.command_data_u.for_cmd.end,expr_datatype(0,0,r->cmd_data.command_data_u.for_cmd.var),0);
	
		if (step_amount>0) {
			printc (";%s<=", decode_varbind (r->cmd_data.command_data_u.for_cmd.var, 'R', 0));
		} else {
			printc (";%s>=", decode_varbind (r->cmd_data.command_data_u.for_cmd.var, 'R', 0));
		}
		real_print_expr (r->cmd_data.command_data_u.for_cmd.end);
		if (step_amount>0) {
		printc (";%s+=%d", decode_varbind (r->cmd_data.command_data_u.for_cmd.var, 'R', 0), step_amount);
		} else {
		printc (";%s-=%d", decode_varbind (r->cmd_data.command_data_u.for_cmd.var, 'R', 0), step_amount*-1);
		}
		//real_print_expr (r->cmd_data.command_data_u.for_cmd.step);
		printc (") {");
		clr_nonewlines ();
		tmp_ccnt++;
		dump_cmds (r->cmd_data.command_data_u.for_cmd.for_commands, r);
		if (uses_loop (r->cmd_data.command_data_u.for_cmd.for_commands, 'C', r->cmd_data.command_data_u.for_cmd.block_id))
	  	{
	    	printc ("continue_for_%d: ; ", r->cmd_data.command_data_u.for_cmd.block_id);
	  	}
		tmp_ccnt--;
		printc ("}");
		if (uses_loop (r->cmd_data.command_data_u.for_cmd.for_commands, 'E', r->cmd_data.command_data_u.for_cmd.block_id))
	  	{
	    	printc ("end_for_%d: ; ", r->cmd_data.command_data_u.for_cmd.block_id);
	  	}
	//printc ("#");
		need_daylight ();
	} else {
		set_nonewlines();
		printc ("%s=", decode_varbind (r->cmd_data.command_data_u.for_cmd.var, 'R', 0));
		ensure_dtype (r->module, r->lineno,r->cmd_data.command_data_u.for_cmd.start,expr_datatype(0,0,r->cmd_data.command_data_u.for_cmd.var),0);
		real_print_expr (r->cmd_data.command_data_u.for_cmd.start);
		printc(";");
		clr_nonewlines();

		printc("while (true) {");
		printc("%s _step_%d,_end_%d;", return_datatype(expr_datatype(0,0,r->cmd_data.command_data_u.for_cmd.var)),  
				r->cmd_data.command_data_u.for_cmd.block_id,  r->cmd_data.command_data_u.for_cmd.block_id);

		ensure_dtype (r->module, r->lineno,r->cmd_data.command_data_u.for_cmd.end,expr_datatype(0,0,r->cmd_data.command_data_u.for_cmd.var),0);
		ensure_dtype (r->module, r->lineno,r->cmd_data.command_data_u.for_cmd.step,expr_datatype(0,0,r->cmd_data.command_data_u.for_cmd.var),0);
		tmp_ccnt++;

		set_nonewlines();
		printc ("_step_%d=", r->cmd_data.command_data_u.for_cmd.block_id);
		real_print_expr (r->cmd_data.command_data_u.for_cmd.step);
		printc(";");
		clr_nonewlines();

		set_nonewlines();
		printc ("_end_%d=", r->cmd_data.command_data_u.for_cmd.block_id);
		real_print_expr (r->cmd_data.command_data_u.for_cmd.end);
		printc(";");
		clr_nonewlines();

		printc(" if (_step_%d>=0 && %s>_end_%d) break;", 
			r->cmd_data.command_data_u.for_cmd.block_id,
			 decode_varbind (r->cmd_data.command_data_u.for_cmd.var, 'R', 0),
			r->cmd_data.command_data_u.for_cmd.block_id
		);
		printc(" if (_step_%d<0 && %s<_end_%d) break;", 
			r->cmd_data.command_data_u.for_cmd.block_id,
			 decode_varbind (r->cmd_data.command_data_u.for_cmd.var, 'R', 0),
			r->cmd_data.command_data_u.for_cmd.block_id
		);
		dump_cmds (r->cmd_data.command_data_u.for_cmd.for_commands, r);
	    	printc ("continue_for_%d: ; ", r->cmd_data.command_data_u.for_cmd.block_id);
		printc("%s+=_step_%d;", 
			 decode_varbind (r->cmd_data.command_data_u.for_cmd.var, 'R', 0),
			r->cmd_data.command_data_u.for_cmd.block_id);

		tmp_ccnt--;
		printc("}");
	    	printc ("end_for_%d: ; ", r->cmd_data.command_data_u.for_cmd.block_id);

	}
      }
      break;



    case E_CMD_FOREACH_CMD:
      {
	struct expr_str_list *has_binding = 0;
	//printc ("#");
	need_daylight ();
	printc ("// Foreach");
	if (r->cmd_data.command_data_u.foreach_cmd.inputvals)
	  {
	    if (r->cmd_data.command_data_u.foreach_cmd.inputvals->list.list_len)
	      {
		printc ("// Foreach has its own binding...");
		has_binding = r->cmd_data.command_data_u.foreach_cmd.inputvals;
	      }
	  }
	if (!has_binding)
	  {
	    int a;
	    // look for it on the declare instead...
	    a = hasDeclare (get_ident (r->cmd_data.command_data_u.foreach_cmd.cursorname,1));
	    if (a >= 0)
	      {			// Its -1 if not found....
		printc ("// Foreach doesn't have its own binding - but the declare does...");
		has_binding = Declares[a].inbind;
	      }
	  }

	if (has_binding)
	  {
	    //printc ("{");
	    //tmp_ccnt++;
	    print_in_binding_using (has_binding);
	    print_when_sql_start ();
	    printc ("$Cursor_%s.Open($InBind);", A4GL_strip_quotes (get_ident (r->cmd_data.command_data_u.foreach_cmd.cursorname,1)));
	    print_when_sql_end ();
	    tmp_ccnt--;
	    printc ("}");
	  }
	else
	  {
	    print_when_sql_start ();
	    printc ("$Cursor_%s.Open();", A4GL_strip_quotes (get_ident (r->cmd_data.command_data_u.foreach_cmd.cursorname,1)));
	    print_when_sql_end ();
	  }

	printc ("#");
	printc ("while (true) {");
	tmp_ccnt++;
	print_when_sql_start ();
	printc ("$RSet=$Cursor_%s.Fetch();", A4GL_strip_quotes (get_ident (r->cmd_data.command_data_u.foreach_cmd.cursorname,1)));
	tmp_ccnt++;
	printc ("if ($RSet==null) break;");
	has_binding = r->cmd_data.command_data_u.foreach_cmd.outputvals;

	if (has_binding)
	  {
	    if (has_binding->list.list_len == 0)
	      has_binding = 0;
	  }
	if (!has_binding)
	  {
	    int a;
	    a = hasDeclare (A4GL_strip_quotes (get_ident (r->cmd_data.command_data_u.foreach_cmd.cursorname,1)));
	    if (a >= 0)
	      {
		has_binding = Declares[a].outbind;
	      }
	  }

	print_copy_fromRSet (has_binding);
	tmp_ccnt--;
	print_when_sql_end ();
	printc ("#");
	//tmp_ccnt++;
	printc ("// FOREACH COMMANDS");
	dump_cmds (r->cmd_data.command_data_u.foreach_cmd.foreach_commands, r);
	printc ("// END OF FOREACH COMMANDS");
	//tmp_ccnt--;
	if (uses_loop
	    (r->cmd_data.command_data_u.foreach_cmd.foreach_commands, 'C', r->cmd_data.command_data_u.foreach_cmd.block_id))
	  {
	    printc ("continue_foreach_%d: ; ", r->cmd_data.command_data_u.foreach_cmd.block_id);
	  }
	tmp_ccnt--;
	printc ("}");
	if (uses_loop
	    (r->cmd_data.command_data_u.foreach_cmd.foreach_commands, 'E', r->cmd_data.command_data_u.foreach_cmd.block_id))
	  {

	    printc ("end_foreach_%d: ; ", r->cmd_data.command_data_u.foreach_cmd.block_id);
	  }
	printc ("$Cursor_%s.Close();", A4GL_strip_quotes (get_ident (r->cmd_data.command_data_u.foreach_cmd.cursorname,1)));
	need_daylight ();
	//printc ("#");
      }
      break;


    case E_CMD_FREE_BLOB_CMD:
	  printc ("$%s.Free(); /* FGLCHECK: Freeing a blob */",decode_varbind (r->cmd_data.command_data_u.free_blob_cmd.var, 'R', 0) );
      break;

    case E_CMD_FREE_CMD:
      if (hasDeclare (A4GL_strip_quotes (get_ident (r->cmd_data.command_data_u.free_cmd.cursorname,1))) >= 0)
	{
	  printc ("$Cursor_%s=null; /* FREE */", A4GL_strip_quotes (get_ident (r->cmd_data.command_data_u.free_cmd.cursorname,1)));
	}
      else
	{
	  printc ("$Statement_%s=null; /* FREE */", A4GL_strip_quotes (get_ident (r->cmd_data.command_data_u.free_cmd.cursorname,1)));
	}
      break;

    case E_CMD_GOTO_CMD:
		print_goto_comment();
      printc ("goto %s;", r->cmd_data.command_data_u.goto_cmd.label);
      break;

    case E_CMD_IF_CMD:
      printc ("#");
      for (a = 0; a < r->cmd_data.command_data_u.if_cmd.truths.conditions.conditions_len; a++)
	{
	  set_nonewlines ();
	  if (a == 0)
	    {
	      printc ("if ( ");
	    }
	  else
	    {
	      printc ("elseif ");
	    }
	  //ensure_bool (r->module, r->lineno, r->cmd_data.command_data_u.if_cmd.truths.conditions.conditions_val[a].test_expr, 1);
	  real_print_expr (r->cmd_data.command_data_u.if_cmd.truths.conditions.conditions_val[a].test_expr);
	  printc (") {");
	  clr_nonewlines ();
	  tmp_ccnt++;
	  dump_cmds (r->cmd_data.command_data_u.if_cmd.truths.conditions.conditions_val[a].whentrue, r);
	  tmp_ccnt--;
	}

      if (r->cmd_data.command_data_u.if_cmd.whenfalse)
	{
	  printc ("} else {");
	  tmp_ccnt++;
	  dump_cmds (r->cmd_data.command_data_u.if_cmd.whenfalse, r);
	  tmp_ccnt--;
	}
      printc ("}");
      printc ("#");

      break;

    case E_CMD_LABEL_CMD:
      need_daylight ();
      printc ("%s: ; ", r->cmd_data.command_data_u.label_cmd.label);
      break;


    case E_CMD_MLET_CMD:
	set_nonewlines();
	for (a=0;a<r->cmd_data.command_data_u.mlet_cmd.vars->list.list_len;a++) {
		if (a) printc("=");
		printc("%s", decode_varbind (r->cmd_data.command_data_u.mlet_cmd.vars->list.list_val[a], 'R', a));
	}
	printc("=");
	real_print_expr(r->cmd_data.command_data_u.mlet_cmd.val);
	printc(";");
	clr_nonewlines();
	break;

    case E_CMD_LET_CMD:

      print_let_manyvars_g (r->cmd_data.command_data_u.let_cmd.vals, r->cmd_data.command_data_u.let_cmd.vars);
      break;


    case E_CMD_LOCATE_CMD:
	if (r->cmd_data.command_data_u.locate_cmd.where.where == E_LOC_MEMORY) {
         for (a = 0; a < r->cmd_data.command_data_u.locate_cmd.variables->list.list_len; a++)
         {
         	printc ("%s.LocateInMemory();",
         	decode_varbind (r->cmd_data.command_data_u.locate_cmd.variables->list.list_val[a], 'R', a));
         }
         } else {
		printc("%s.LocateInFile(", decode_varbind (r->cmd_data.command_data_u.locate_cmd.variables->list.list_val[0], 'R', 0));
         	real_print_expr (r->cmd_data.command_data_u.locate_cmd.where.locate_pos_u.filename);
		printc(");");
         }

      /*
         if (r->cmd_data.command_data_u.locate_cmd.where.where == E_LOC_FILE)
         {
         for (a = 0; a < r->cmd_data.command_data_u.locate_cmd.variables->list.list_len; a++)
         {
         set_nonewlines ();
         printc ("LOCATE %s IN FILE ",
         decode_varbind (r->cmd_data.command_data_u.locate_cmd.variables->list.list_val[a], 'R', a));
         real_print_expr (r->cmd_data.command_data_u.locate_cmd.where.locate_pos_u.filename, "");
         clr_nonewlines ();
         }
         }

         if (r->cmd_data.command_data_u.locate_cmd.where.where == E_LOC_MEMORY)
         {
         for (a = 0; a < r->cmd_data.command_data_u.locate_cmd.variables->list.list_len; a++)
         {
         printc ("LOCATE %s IN MEMORY",
         decode_varbind (r->cmd_data.command_data_u.locate_cmd.variables->list.list_val[a], 'R', a));
         }
         }
       */

      break;

    case E_CMD_RETURN_CMD:
      returns++;

      if (r->cmd_data.command_data_u.return_cmd.retvals && r->cmd_data.command_data_u.return_cmd.retvals->list.list_len)
	{
	  if (Currnrets < r->cmd_data.command_data_u.return_cmd.retvals->list.list_len)
	    {
	      printc ("/* FGLCHECK: Ignored some original return values - as we are not expecting that many... */");
	    }

	  if (Currnrets == 1)
	    {
	      set_nonewlines ();
	      printc ("return ");
	      ensure_dtype (" ", 0, r->cmd_data.command_data_u.return_cmd.retvals->list.list_val[0], dtypes[0], 0);
	      real_print_expr (r->cmd_data.command_data_u.return_cmd.retvals->list.list_val[0]);
	      printc (";");
	      clr_nonewlines ();
	    }
	  else
	    {
	      int a;
		set_nonewlines();
	      printc ("return array(");
	      for (a = 0; a < r->cmd_data.command_data_u.return_cmd.retvals->list.list_len; a++)
		{
			if (a) printc(",");
		      	real_print_expr (r->cmd_data.command_data_u.return_cmd.retvals->list.list_val[a]);
		
		}
		printc(");");
		clr_nonewlines();
	    }
	}
      else
	{
	  if (Currnrets == 1)
	    {
		// We need to return something...
		printc("{");
		if (dtypes[0]==90) {
		printc ("%s fake_rval=false; /* FGLCHECK: - the function needs to return a value but there is a 4gl RETURN without any values.... */", return_datatype (dtypes[0]));
		} else {
		printc ("%s fake_rval=null; /* FGLCHECK: - the function needs to return a value but there is a 4gl RETURN without any values.... */", return_datatype (dtypes[0]));
		}
		printc("return fake_rval;");
		printc("}");
	    } else {
	  		printc ("return;");
	   }
	}
      break;







    case E_CMD_NEXT_OPTION_CMD:
      {
	expr_str *s;
	s = r->cmd_data.command_data_u.next_option_cmd.menuoption;
	set_nonewlines ();
	printc ("%s.NextOption(", get_menu_context ());
	real_print_expr (s);
	printc (");");
	clr_nonewlines ();
      }
      break;

    case E_CMD_HIDE_OPTION_CMD:
      {
	expr_str_list *s;
	s = r->cmd_data.command_data_u.hide_option_cmd.menuoptions;

	for (a = 0; a < s->list.list_len; a++)
	  {
	    set_nonewlines ();
	    printc ("%s.HideOption(", get_menu_context ());
	    real_print_expr (s->list.list_val[a]);
	    printc (");");
	    clr_nonewlines ();
	  }
      }
      break;

    case E_CMD_SHOW_OPTION_CMD:
      {
	expr_str_list *s;
	s = r->cmd_data.command_data_u.show_option_cmd.menuoptions;

	for (a = 0; a < s->list.list_len; a++)
	  {
	    set_nonewlines ();
	    printc ("%s.ShowOption(", get_menu_context ());
	    real_print_expr (s->list.list_val[a]);
	    printc (");");
	    clr_nonewlines ();
	  }
      }
      break;

    case E_CMD_WHENEVER_CMD:
      //mod_whencode=r->cmd_data.command_data_u.whenever_cmd.whencode;
      mod_whento[r->cmd_data.command_data_u.whenever_cmd.whencode >> 4] = r->cmd_data.command_data_u.whenever_cmd.whento;
      mod_whencode[r->cmd_data.command_data_u.whenever_cmd.whencode >> 4] = r->cmd_data.command_data_u.whenever_cmd.whencode & 0xf;
      print_whenever_style (r->cmd_data.command_data_u.whenever_cmd.whencode, r->cmd_data.command_data_u.whenever_cmd.whento);
      break;



    case E_CMD_OPEN_WINDOW_CMD:
      {

	switch (r->cmd_data.command_data_u.open_window_cmd.wt.wintype)
	  {

	  case EWT_ROWSCOLS:
	    {
	      //fprintf (hfile, "   private FglWindow Window_%s;\n", local_expr_as_string(r->cmd_data.command_data_u.open_window_cmd.windowname));
	      set_nonewlines ();
	      printc ("UILib_CreateFglWindow("); //, local_expr_as_string (r->cmd_data.command_data_u.open_window_cmd.windowname));
	      real_print_expr (r->cmd_data.command_data_u.open_window_cmd.windowname);	// print_quoted_ident
	      printc (",");
	      real_print_expr (r->cmd_data.command_data_u.open_window_cmd.y);
	      printc (",");
	      real_print_expr (r->cmd_data.command_data_u.open_window_cmd.x);
	      printc (" , ");
	      real_print_expr (r->cmd_data.command_data_u.open_window_cmd.wt.windowtype_u.rowscols.rows);
	      printc (" , ");
	      real_print_expr (r->cmd_data.command_data_u.open_window_cmd.wt.windowtype_u.rowscols.columns);
	      clr_nonewlines ();
	      tmp_ccnt++;
	      set_nonewlines ();

	      printc (",new FglWindowAttribute(");
	      print_window_attributes (r->cmd_data.command_data_u.open_window_cmd.attributes);
	      printc (")");
	      printc (");");
	      tmp_ccnt--;


	      //printc (" ,%s", get_attributes_as_string (r->cmd_data.command_data_u.open_window_cmd.attributes));
	      clr_nonewlines ();
	    }
	    break;

	  case EWT_FORM:
	    //fprintf (hfile, "   private FglWindow Window_%s;\n", local_expr_as_string(r->cmd_data.command_data_u.open_window_cmd.windowname));
	    set_nonewlines ();
	    printc (" UILib_CreateFglWindow("); // , local_expr_as_string (r->cmd_data.command_data_u.open_window_cmd.windowname));

	    real_print_expr (r->cmd_data.command_data_u.open_window_cmd.windowname);	// print_quoted_ident
	    printc (",");
	    real_print_expr (r->cmd_data.command_data_u.open_window_cmd.y);
	    printc (",");
	    real_print_expr (r->cmd_data.command_data_u.open_window_cmd.x);
	    printc (",");
	    real_print_expr (r->cmd_data.command_data_u.open_window_cmd.wt.windowtype_u.formfilename);
	    clr_nonewlines ();
	    tmp_ccnt++;
	    set_nonewlines ();
	    printc (",new FglWindowAttribute("); //, local_expr_as_string (r->cmd_data.command_data_u.open_window_cmd.windowname));
	    print_window_attributes (r->cmd_data.command_data_u.open_window_cmd.attributes);
	    printc ("));");
	    clr_nonewlines ();
	    tmp_ccnt--;
	  }
      }
      break;

    case E_CMD_NEED_CMD:
      set_nonewlines ();
      printc ("Driver.NeedLines( ");
      real_print_expr (r->cmd_data.command_data_u.need_cmd.expr);
      printc (");");
      clr_nonewlines ();
      break;

    case E_CMD_SKIP_CMD:
      set_nonewlines ();
      printc ("Driver.SkipLines(");
      real_print_expr (r->cmd_data.command_data_u.skip_cmd.skip_amt);
      printc (");");
      clr_nonewlines ();
      break;

    case E_CMD_PRINT_CMD:
      set_nonewlines ();

      if (r->cmd_data.command_data_u.print_cmd.semi == EB_TRUE)
	{
	  printc ("Driver.PrintNoNewLine(");
	}
      else
	{
	  printc ("Driver.Print(");
	}

      real_print_expr_list_with_separator (r->cmd_data.command_data_u.print_cmd.print_expr, ".");

      printc (");");
      clr_nonewlines ();
      break;

    case E_CMD_PRINT_FILE_CMD:
      set_nonewlines ();
      printc ("Driver.PrintFile(");
      real_print_expr (r->cmd_data.command_data_u.print_file_cmd.filename);
      if (r->cmd_data.command_data_u.print_file_cmd.semi == EB_TRUE)
	{
	  printc (",true); /* No NL */");
	}
      else
	{
	  printc (",false);");
	}

      clr_nonewlines ();

      break;

    case E_CMD_PAUSE_CMD:
      set_nonewlines ();
      printc ("Driver.Pause(");
      real_print_expr (r->cmd_data.command_data_u.pause_cmd.pause_msg);
      printc (");");
      clr_nonewlines ();
      break;

    case E_CMD_RUN_CMD:
      set_nonewlines ();
      if (r->cmd_data.command_data_u.run_cmd.returning)
	{
	  printc ("%s", decode_varbind (r->cmd_data.command_data_u.run_cmd.returning, 'w', 0));
	}
      printc ("ExecuteCmd(");
      real_print_expr (r->cmd_data.command_data_u.run_cmd.run_string);
      printc (");");
      clr_nonewlines ();
      break;

    case E_CMD_SLEEP_CMD:
      set_nonewlines ();
      printc ("UILib_Sleep(");
      real_print_expr (r->cmd_data.command_data_u.sleep_cmd.sleep_expr);
      printc (");");
      clr_nonewlines ();
      break;



    case E_CMD_WHILE_CMD:
      need_daylight ();
      set_nonewlines ();
      printc ("while (");
      //ensure_bool (r->module, r->lineno, r->cmd_data.command_data_u.while_cmd.while_expr, 1);
      real_print_expr (r->cmd_data.command_data_u.while_cmd.while_expr);
      printc (") {");
      clr_nonewlines ();
      tmp_ccnt++;
      dump_cmds (r->cmd_data.command_data_u.while_cmd.while_commands, r);
      if (uses_loop (r->cmd_data.command_data_u.while_cmd.while_commands, 'C', r->cmd_data.command_data_u.while_cmd.block_id))
	{
	  printc ("continue_while_%d: ; ", r->cmd_data.command_data_u.while_cmd.block_id);
	}
      tmp_ccnt--;
      printc ("}");
      if (uses_loop (r->cmd_data.command_data_u.while_cmd.while_commands, 'E', r->cmd_data.command_data_u.while_cmd.block_id))
	{
	  printc ("end_while_%d: ; ", r->cmd_data.command_data_u.while_cmd.block_id);
	}
      need_daylight ();
      break;

    case E_CMD_MESSAGE_CMD:
      set_nonewlines ();
      printc ("AubitMessage(");
      real_print_expr_list_with_separator (r->cmd_data.command_data_u.message_cmd.message_expr, ".");
      printc (");");

      clr_nonewlines ();
      break;


    case E_CMD_INIT_CMD:
      print_init_cmd (&r->cmd_data.command_data_u.init_cmd);
      module_var_binding (r->cmd_data.command_data_u.init_cmd.varlist, COPY_DATA_FROM_TMPS_INTO_MODVARS);
      break;

    case E_CMD_NEXT_FIELD_CMD:
      switch (r->cmd_data.command_data_u.next_field_cmd.rel)
	{
	case -1:
	  printc ("%s.Nextfield(new AubitField(\"PREVIOUS\",0));", get_ui_context ());

	  break;
	case 1:
	  printc ("%s.Nextfield(new AubitField(\"NEXT\",0));", get_ui_context ());
	  break;

	case 0:
	  printc ("%s.Nextfield(%s);", get_ui_context (), field_name_as_char (r->cmd_data.command_data_u.next_field_cmd.nextfield));
	  break;
	}
      break;


    case E_CMD_SCROLL_CMD:
      A4GL_assertion (1, "Scroll command not implemented");
      break;

    case E_CMD_OPEN_FORM_CMD:
      set_nonewlines ();
      printc ("UILib_OpenForm(");
      real_print_expr (r->cmd_data.command_data_u.open_form_cmd.formname);
      printc (",");
      real_print_expr (r->cmd_data.command_data_u.open_form_cmd.form_filename);
      printc (");");
      clr_nonewlines ();
      break;



    case E_CMD_OPEN_CURSOR_CMD:
      {
	int a;
	struct expr_str_list *has_binding = 0;

	a = hasDeclare (A4GL_strip_quotes (get_ident (r->cmd_data.command_data_u.open_cursor_cmd.cursorname,1)));

	module_var_binding (r->cmd_data.command_data_u.open_cursor_cmd.using_bind, COPY_DATA_FROM_MODVARS_INTO_TMPS);
	if (r->cmd_data.command_data_u.open_cursor_cmd.using_bind)
	  {
	    if (r->cmd_data.command_data_u.open_cursor_cmd.using_bind->list.list_len)
	      {
		has_binding = r->cmd_data.command_data_u.open_cursor_cmd.using_bind;
	      }
	  }

	if (!has_binding )
	  {
	    if (a >= 0)
	      {			// Its -1 if not found....
			// If the declare is for an explicit INSERT
			// then the values go in at the PUT stage - not now...
		if ( Declares[a].type!=DECLARE_INSERT) { 
			has_binding = Declares[a].inbind;
		}
	      }
	  }

	if (has_binding)
	  {
	    //printc ("{");
	    print_when_sql_start ();
	    print_in_binding_using (has_binding);	// or look in cursor...
	    //tmp_ccnt++;
	    printc ("$Cursor_%s.Open($InBind);",
		    A4GL_strip_quotes (get_ident (r->cmd_data.command_data_u.open_cursor_cmd.cursorname,1)));
	    tmp_ccnt--;
	    printc ("} /* END OF USING FOR OPEN */");
	    print_when_sql_end ();
	  }
	else
	  {
	    print_when_sql_start ();
	    printc ("$Cursor_%s.Open();", A4GL_strip_quotes (get_ident (r->cmd_data.command_data_u.open_cursor_cmd.cursorname,1)));
	    print_when_sql_end ();
	  }
      }
      break;


    case E_CMD_OPTIONS_CMD:
      for (a = 0; a < r->cmd_data.command_data_u.options_cmd.options->options.options_len; a++)
	{
	  print_options (r->cmd_data.command_data_u.options_cmd.options->options.options_val[a]->option[0],
			 r->cmd_data.command_data_u.options_cmd.options->options.options_val[a]->value,
			 r->cmd_data.command_data_u.options_cmd.options->options.options_val[a]->expr);
	}
      break;

    case E_CMD_PREPARE_CMD:
      need_daylight ();
      print_prepare_cmd (&r->cmd_data.command_data_u.prepare_cmd);


      break;

    case E_CMD_EXECUTE_CMD:

      module_var_binding (r->cmd_data.command_data_u.execute_cmd.inbind, COPY_DATA_FROM_MODVARS_INTO_TMPS);
      //if (!when_set_to_call) { A4GL_warn("Coding Standards: Must use 'WHENEVER ERROR CALL get_error_record' before using SQL"); }
      if (r->cmd_data.command_data_u.execute_cmd.outbind == 0)
	{
	  //printc ("{");
	  //tmp_ccnt++;
	  print_in_binding_using (r->cmd_data.command_data_u.execute_cmd.inbind);
	  print_when_sql_start ();
	  printc ("SQLExecute(Statement_%s,$InBind);", A4GL_strip_quotes (get_ident (r->cmd_data.command_data_u.execute_cmd.sql_stmtid,1)));
	  print_when_sql_end ();
	  tmp_ccnt--;
	  printc ("}");
	}
      else
	{
	  //printc ("{");
	  //tmp_ccnt++;
	  print_in_binding_using (r->cmd_data.command_data_u.execute_cmd.inbind); // {
	  //printc ("IfxResult RSet=null;");
	  print_when_sql_start ();
	  printc ("$RSet=SQLExecuteInto($Statement_%s,$InBind);", A4GL_strip_quotes (get_ident (r->cmd_data.command_data_u.execute_cmd.sql_stmtid,1)));
	  tmp_ccnt++;
	  printc ("if ($RSet!=null) {");
	  tmp_ccnt++;
	  print_copy_fromRSet (r->cmd_data.command_data_u.execute_cmd.outbind);
	  tmp_ccnt--;
	  printc ("}");
	  print_when_sql_end ();
	  tmp_ccnt--;
	  printc ("}");
	}

      module_var_binding (r->cmd_data.command_data_u.execute_cmd.outbind, COPY_DATA_FROM_TMPS_INTO_MODVARS);
      break;

    case E_CMD_EXECUTE_IMMEDIATE_CMD:
      set_nonewlines ();
      print_when_sql_start ();
      printc ("SQLExecute(");
      real_print_expr (r->cmd_data.command_data_u.execute_immediate_cmd.sql_stmt);
      printc (");");
      print_when_sql_end ();
      clr_nonewlines ();
      break;



    case E_CMD_START_CMD:
      printc ("%s=new _%s(this);", r->cmd_data.command_data_u.start_cmd.repname, r->cmd_data.command_data_u.start_cmd.repname);
      set_nonewlines ();
      printc ("%s.startReport(", r->cmd_data.command_data_u.start_cmd.repname);

      if (r->cmd_data.command_data_u.start_cmd.sc_c)
	{
	  struct startrep *s;
	  int with = 0;
	  s = r->cmd_data.command_data_u.start_cmd.sc_c;
	  switch (s->towhat)
	    {

	    case 0:
	      break;
	    case '-':
	      break;
	    case 'S':
	      printc ("\"\",\"Screen\"");
	      //printc (" TO SCREEN");
	      break;
	    case 'P':
	    case '|':
	      if (s->s1->expr_type == ET_EXPR_REPORT_PRINTER)
		{
		  printc ("\"\",\"Printer\"");
		}
	      else
		{
		  real_print_expr (s->s1);
		  printc (",\"PIPE\"");
		}
	      break;


	    case '@':
	      printc ("\"\",\"EMAIL\"");
	      //printc (" TO EMAIL");
	      break;

	    case 'C':
	      printc ("\"\",\"CONVERTIBLE\"");
	      //printc (" AS CONVERTIBLE");
	      break;

	    case 'F':
	      real_print_expr (s->s1);
	      printc (",\"FILE\"");
	      break;
	    }
	  printc (");");

/*
	  if (s->with_page_length != -1)
	    with++;
	  if (s->with_left_margin != -1)
	    with++;
	  if (s->with_right_margin != -1)
	    with++;
	  if (s->with_top_margin != -1)
	    with++;
	  if (s->with_bottom_margin != -1)
	    with++;
	  if (strcmp (s->with_top_of_page, "") != 0)
	    with++;
*/

	      //int printed = 0;
	      if (s->page_length_e )
		{
		  printc ("%s%s.", local_get_namespace_internal (r->cmd_data.command_data_u.start_cmd.repname),
			  r->cmd_data.command_data_u.start_cmd.repname);
		
		  printc ("setPageLength(%d);",local_expr_as_string( s->page_length_e));
		}

	      if (s->left_margin_e )
		{
		  printc ("%s%s.", local_get_namespace_internal (r->cmd_data.command_data_u.start_cmd.repname),
			  r->cmd_data.command_data_u.start_cmd.repname);
		  printc ("setLeftMargin(%d);", local_expr_as_string(s->left_margin_e));
		}
	      if (s->right_margin_e)
		{
		  printc ("%s%s.", local_get_namespace_internal (r->cmd_data.command_data_u.start_cmd.repname),
			  r->cmd_data.command_data_u.start_cmd.repname);
		  printc ("setRightMargin(%d);", local_expr_as_string(s->right_margin_e));
		}
	      if (s->top_margin_e)
		{
		  printc ("%s%s.", local_get_namespace_internal (r->cmd_data.command_data_u.start_cmd.repname),
			  r->cmd_data.command_data_u.start_cmd.repname);
		  printc ("setTopMargin(%d);", local_expr_as_string( s->top_margin_e));
		}
	      if (s->bottom_margin_e )
		{
		  printc ("%s%s.", local_get_namespace_internal (r->cmd_data.command_data_u.start_cmd.repname),
			  r->cmd_data.command_data_u.start_cmd.repname);
		  printc ("setTopMargin(%d);", local_expr_as_string(s->bottom_margin_e));
		}

 		if (strcmp (s->top_of_page, "") != 0)
		{
		  printc ("%s%s.", local_get_namespace_internal (r->cmd_data.command_data_u.start_cmd.repname),
			  r->cmd_data.command_data_u.start_cmd.repname);
		  printc ("setTopMargin(%s);", local_expr_as_string(s->top_of_page));
		}

	}
      clr_nonewlines ();
      break;

    case E_CMD_CONVERT_CMD:
      //r->cmd_data.command_data_u.convert_cmd 
      break;

    case E_CMD_FREE_REP_CMD:
      printc ("/* FREE REPORT %s */", r->cmd_data.command_data_u.free_rep_cmd.repname);
      break;

    case E_CMD_OUTPUT_CMD:
      set_nonewlines ();
      printc ("%s.SendData(", r->cmd_data.command_data_u.output_cmd.repname);
      real_print_expr_list_with_separator (r->cmd_data.command_data_u.output_cmd.expressions, ",");
      printc (");");
      clr_nonewlines ();
      break;

    case E_CMD_FINISH_CMD:
      printc ("%s.finishReport();", r->cmd_data.command_data_u.finish_cmd.repname);
      break;

    case E_CMD_TERM_REP_CMD:
      printc ("%s.terminateReport();", r->cmd_data.command_data_u.term_rep_cmd.repname);
      break;

    case E_CMD_CLEAR_CMD:
      switch (r->cmd_data.command_data_u.clear_cmd.clr_data.clr_type)
	{
	case E_CLR_SCREEN:
	  printc ("UILib_ClearScreen();");
	  break;
	case E_CLR_WINDOW:
	  printc ("UILib_ClearWindow(\"%s\");",
		  A4GL_strip_quotes (get_ident (r->cmd_data.command_data_u.clear_cmd.clr_data.clear_data_u.window,0)));
	  break;
	case E_CLR_STATUS:
	  printc ("// CLEAR STATUSBOX %s",
		  A4GL_strip_quotes (get_ident (r->cmd_data.command_data_u.clear_cmd.clr_data.clear_data_u.window,0)));
	  break;

	case E_CLR_FORM:
	  printc ("UILib_ClearForm(false);");
	  break;

	case E_CLR_FORM_DEFAULTS:
	  printc ("Uilib_ClearForm(true);");
	  break;

	case E_CLR_FIELDS:
	  printc_safe_to_split_at_comma ("UILib_ClrFields(%s,%s);",
					 r->cmd_data.command_data_u.clear_cmd.todefaults ? "true" : "false",
					 field_name_list_as_char (r->cmd_data.command_data_u.clear_cmd.clr_data.clear_data_u.  fields)
					);
	  break;

	case E_CLR_FIELDS_TO_DEFAULT:
	  printc_safe_to_split_at_comma ("UILib_ClrFields(true,%s);",
					 field_name_list_as_char (r->cmd_data.command_data_u.clear_cmd.clr_data.clear_data_u.
								  fields)
			);
	  break;
	}
      break;

    case E_CMD_CURRENT_WIN_CMD:
      if (r->cmd_data.command_data_u.current_win_cmd.windowname == 0)
	{
	  printc ("UILib_CurrentWindow(\"SCREEN\");");
	}
      else
	{
	  set_nonewlines ();
	  printc ("UILib_CurrentWindow(");
	  real_print_expr (r->cmd_data.command_data_u.current_win_cmd.windowname);	// print_quoted_ident
	  printc (");");
	  clr_nonewlines ();
	}
      break;


    case E_CMD_PUT_CMD:
      {

	struct expr_str_list *bind;

	bind = r->cmd_data.command_data_u.put_cmd.values;
	if (bind && bind->list.list_len == 0)
	  {
	    bind = 0;
	  }

	printc ("{ /* PUT %s */", A4GL_strip_quotes (get_ident (r->cmd_data.command_data_u.put_cmd.cursorname,1)));
	tmp_ccnt++;
	printc ("$InBind=BuildSQLBinding();");
	if (bind == 0)
	  {
	    int a;
	    a = hasDeclare (A4GL_strip_quotes (get_ident (r->cmd_data.command_data_u.put_cmd.cursorname,1)));
	    if (a >= 0)
	      {			// Its -1 if not found....
		bind = Declares[a].inbind;
	      }
	  }

	if (bind)
	  {
	    //int bcnt = 0;
	    for (a = 0; a < bind->list.list_len; a++)
	      {

		int dtype_sz;
		dtype_sz = get_binding_dtype (bind->list.list_val[a]) >> 16;
		switch (get_binding_dtype (bind->list.list_val[a]) & DTYPE_MASK)
		  {
		  case DTYPE_SMINT:
		    printc ("$InBind->AppendInt($%s);", generation_get_variable_usage (bind->list.list_val[a]));
		    break;
		  case DTYPE_SERIAL:
		  case DTYPE_INT:
		    printc ("$InBind->AppendInt($%s);", generation_get_variable_usage (bind->list.list_val[a]));
		    break;
		  case DTYPE_FLOAT:
		    printc ("$InBind->AppendDouble($%s);", generation_get_variable_usage (bind->list.list_val[a]));
		    break;
		  case DTYPE_SMFLOAT:
		    printc ("$InBind->AppendFloat($%s);", generation_get_variable_usage (bind->list.list_val[a]));
		    break;
		  case DTYPE_DECIMAL:
		    printc ("$InBind->AppendDecimal($%s,%d,%d);",
			    generation_get_variable_usage (bind->list.list_val[a]), dtype_sz >> 8, dtype_sz & 255);
		    break;
		  case DTYPE_DATE:
		    printc ("$InBind->AppendDate($%s);", generation_get_variable_usage (bind->list.list_val[a]));
		    break;
		  case DTYPE_DTIME:
		    printc ("$InBind->AppendDtime($%s,%s,%s);",
			    generation_get_variable_usage (bind->list.list_val[a]), decode_dt (dtype_sz, 1), decode_dt (dtype_sz,
															2));
		    break;
		  case DTYPE_INTERVAL:
		    printc ("$InBind->AppendInterval($%s);", generation_get_variable_usage (bind->list.list_val[a]));
		    break;
		  case DTYPE_CHAR:
		    printc ("$InBind->AppendString($%s, %d);", generation_get_variable_usage (bind->list.list_val[a]), dtype_sz);
		    break;
		  case 90:
		    printc ("$InBind->AppendBoolean($%s);", generation_get_variable_usage (bind->list.list_val[a]));
		    break;
		  default:
		    printc ("$InBind->AppendUnknown%d($%s, %d);",
			    get_binding_dtype (bind->list.list_val[a]) & DTYPE_MASK,
			    generation_get_variable_usage (bind->list.list_val[a]), dtype_sz);
		    break;
		  }
	      }
	  }
	print_when_sql_start ();
	printc ("$Cursor_%s.Put($InBind);", A4GL_strip_quotes (get_ident (r->cmd_data.command_data_u.put_cmd.cursorname,1)));
	print_when_sql_end ();
	tmp_ccnt--;
	printc ("}");
      }
      break;

    case E_CMD_UNLOAD_CMD:
      print_unload_cmd (&r->cmd_data.command_data_u.unload_cmd);
      break;

    case E_CMD_LOAD_CMD:
      print_load_cmd (&r->cmd_data.command_data_u.load_cmd);
      break;


    case E_CMD_SQL_CMD:
      print_when_sql_start ();
      printc ("SQLExecute(\"%s\");", escape_quotes_and_remove_nl (r->cmd_data.command_data_u.sql_cmd.sql, 0));
      print_when_sql_end ();
      //clr_nonewlines ();
      break;


    case E_CMD_SQL_TRANSACT_CMD:
      print_when_sql_start ();
      set_nonewlines ();
      switch (r->cmd_data.command_data_u.sql_transact_cmd.trans)
	{
	case -1:
	  printc ("SQLBeginWork();");
	  break;
	case 0:
	  printc ("SQLRollbackWork();");
	  break;
	case 1:
	  printc ("SQLCommitWork();");
	  break;
	}
      clr_nonewlines ();
      print_when_sql_end ();
      break;


    case E_CMD_FLUSH_CMD:

      set_nonewlines ();
      printc ("$Cursor_%s.Flush();", A4GL_strip_quotes (get_ident (r->cmd_data.command_data_u.flush_cmd.cursorname,1)));
      clr_nonewlines ();
      break;

    case E_CMD_DECLARE_CMD:
      {
	//char *s;
	//char *p;
	int declaretype;
	//int p1;
	clr_bindings ();

	printc ("#");
	set_nonewlines ();

	//fprintf (hfile, "   private IfxCursor Cursor_%s;\n", A4GL_strip_quotes (get_ident (r->cmd_data.command_data_u.declare_cmd.cursorname,1)));
	// r->cmd_data.command_data_u.declare_cmd.into_bind
	// r->cmd_data.command_data_u.declare_cmd.using_bind

	if (r->cmd_data.command_data_u.declare_cmd.declare_dets->insert_cmd)
	  {
	    printc ("$Cursor_%s=BuildSQLCursor(SQLCursorType.InsertCursor,",
		    A4GL_strip_quotes (get_ident (r->cmd_data.command_data_u.declare_cmd.cursorname,1)));
	    print_insert_cmd (r->cmd_data.command_data_u.declare_cmd.declare_dets->insert_cmd);
	    declaretype = DECLARE_INSERT;
	  }
	else
	  {
	    printc ("$Cursor_%s=BuildSQLCursor(SQLCursorType.",
		    A4GL_strip_quotes (get_ident (r->cmd_data.command_data_u.declare_cmd.cursorname,1)));

	    if (r->cmd_data.command_data_u.declare_cmd.scroll == EB_TRUE)
	      {
	    	if (r->cmd_data.command_data_u.declare_cmd.with_hold == EB_TRUE)
	      	{
			printc ("ScrollCursor");
	      	} else {
			printc ("ScrollCursorWithHold");
		}
	      }
	    else
	      {
	    	if (r->cmd_data.command_data_u.declare_cmd.with_hold == EB_TRUE)
		{
			printc ("CursorWithHold");
		} else {
			printc ("Cursor");
		}
	      }


	    printc (",");
	    if (r->cmd_data.command_data_u.declare_cmd.declare_dets->ident)
	      {
		printc ("Statement_%s", get_ident (r->cmd_data.command_data_u.declare_cmd.declare_dets->ident,1));
		declaretype = DECLARE_PREPARED;
	      }
	    else
	      {
		declaretype = DECLARE_SELECT;
		tmp_ccnt++;
		clr_bindings ();
		preprocess_sql_statement (r->cmd_data.command_data_u.declare_cmd.declare_dets->select);
		//search_variables (&r->cmd_data.command_data_u.declare_cmd.declare_dets->select->list_of_items);
		search_sql_variables (&r->cmd_data.command_data_u.declare_cmd.declare_dets->select->list_of_items, 'i');
		printc ("\"");

		print_select (r->cmd_data.command_data_u.declare_cmd.declare_dets->select,
			      r->cmd_data.command_data_u.declare_cmd.declare_dets->forUpdate);
		printc ("\"");
		tmp_ccnt--;
	      }
	  }


	printc (");");
	clr_nonewlines ();

	if (output_bind)
	  {
	    module_var_binding (output_bind, COPY_DATA_FROM_TMPS_INTO_MODVARS);
	  }
	addDeclare (A4GL_strip_quotes (get_ident (r->cmd_data.command_data_u.declare_cmd.cursorname,1)), input_bind, output_bind,declaretype);
      }


      printc ("#");
      break;



    case E_CMD_SET_DATABASE_CMD:

      set_nonewlines ();
      printc ("Connect(");
      real_print_expr (r->cmd_data.command_data_u.set_database_cmd.set_dbname);
      printc (");");
      clr_nonewlines ();
      break;

    case E_CMD_FETCH_CMD:
      {
	struct expr_str_list *has_binding = 0;
	//if (!when_set_to_call) { A4GL_warn("Coding Standards: Must use 'WHENEVER ERROR CALL get_error_record' before using SQL"); }
	print_when_sql_start ();
	set_nonewlines ();
	printc ("$RSet=$Cursor_%s.", A4GL_strip_quotes (get_ident (r->cmd_data.command_data_u.fetch_cmd.fetch->cursorname,1)));

	switch (r->cmd_data.command_data_u.fetch_cmd.fetch->fp->ab_rel)
	  {
	  case FETCH_RELATIVE:
	    if (A4GL_is_just_int_literal (r->cmd_data.command_data_u.fetch_cmd.fetch->fp->fetch_expr, 1))
	      {
		printc ("Fetch();");
	      }
	    else
	      {
		printc ("FetchRelative(");
		real_print_expr (r->cmd_data.command_data_u.fetch_cmd.fetch->fp->fetch_expr);
		printc (");");
	      }
	    break;

	  case FETCH_ABSOLUTE:
	    if (A4GL_is_just_int_literal (r->cmd_data.command_data_u.fetch_cmd.fetch->fp->fetch_expr, 1))
	      {
		printc ("FetchFirst();");
		break;

	      }
	    if (A4GL_is_just_int_literal (r->cmd_data.command_data_u.fetch_cmd.fetch->fp->fetch_expr, -1))
	      {
		printc ("FetchLast();");
		break;
	      }

	    if (A4GL_is_just_int_literal (r->cmd_data.command_data_u.fetch_cmd.fetch->fp->fetch_expr, 0))
	      {
		printc ("FetchCurrent();");
		break;
	      }

	    printc ("FetchAbsolute(");
	    real_print_expr (r->cmd_data.command_data_u.fetch_cmd.fetch->fp->fetch_expr);
	    printc (");");

	    break;

	  }
	//tmp_ccnt++;
	clr_nonewlines ();
	has_binding = r->cmd_data.command_data_u.fetch_cmd.outbind;
	if (has_binding)
	  {
	    if (has_binding->list.list_len == 0)
	      has_binding = 0;
	  }
	if (!has_binding)
	  {
	    int a;
	    a = hasDeclare (A4GL_strip_quotes (get_ident (r->cmd_data.command_data_u.fetch_cmd.fetch->cursorname,1)));
	    if (a >= 0)
	      {
		has_binding = Declares[a].outbind;
	      }
	  }


	printc ("if (RSet!=null) {");
	tmp_ccnt++;
	print_copy_fromRSet (has_binding);
	tmp_ccnt--;
	printc ("}");
	print_when_sql_end ();

      }
      break;

    case E_CMD_UPDATE_CMD:
      {
	char *ptr;
	int converted;
	clr_bindings ();
	ptr = get_update_cmd (&r->cmd_data.command_data_u.update_cmd, &converted);
	if (input_bind && input_bind->list.list_len)
	  {
	    printc ("{");
	    tmp_ccnt++;
	    print_in_binding (input_bind);
	    print_when_sql_start ();
	    printc ("SQLExecute(\"%s\",$InBind);", escape_quotes_and_remove_nl (ptr, 0));
	    print_when_sql_end ();
	    tmp_ccnt--;
	    printc ("}");
	  }
	else
	  {
	    print_when_sql_start ();
	    printc ("SQLExecute(\"%s\");", escape_quotes_and_remove_nl (ptr, 0));
	    print_when_sql_end ();
	  }
      }
      break;

    case E_CMD_INSERT_CMD:
      {
	char *ptr;
	int converted;
	clr_bindings ();

	ptr = get_insert_cmd (&r->cmd_data.command_data_u.insert_cmd, &converted);
	if (input_bind && input_bind->list.list_len)
	  {
	    printc ("{");
	    tmp_ccnt++;
	    print_in_binding (input_bind);
	    print_when_sql_start ();
	    printc ("SQLExecute(\"%s\",$InBind);", escape_quotes_and_remove_nl (ptr, 0));
	    print_when_sql_end ();
	    tmp_ccnt--;
	    printc ("}");
	  }
	else
	  {
	    print_when_sql_start ();
	    printc ("SQLExecute(\"%s\");", escape_quotes_and_remove_nl (ptr, 0));
	    print_when_sql_end ();
	  }
      }
      break;

    case E_CMD_DELETE_CMD:
      {
	char *ptr;
	int converted;
	clr_bindings ();
	ptr = get_delete_cmd (&r->cmd_data.command_data_u.delete_cmd, &converted);
	if (input_bind && input_bind->list.list_len)
	  {
	    printc ("{");
	    tmp_ccnt++;
	    print_in_binding (input_bind);
	    print_when_sql_start ();
	    printc ("SQLExecute(\"%s\",$InBind);", escape_quotes_and_remove_nl (ptr, 0));
	    print_when_sql_end ();
	    tmp_ccnt--;
	    printc ("}");
	  }
	else
	  {
	    print_when_sql_start ();
	    printc ("SQLExecute(\"%s\");", escape_quotes_and_remove_nl (ptr, 0));
	    print_when_sql_end ();
	  }
      }
      break;

    case E_CMD_SELECT_CMD:
      {
	char *ptr;
	//int converted;
	int i;
	//char forUpdate[2000] = "";
	struct s_select *s;
	clr_bindings ();
	s = r->cmd_data.command_data_u.select_cmd.sql;

	output_bind = s->into;
	preprocess_sql_statement (s);
	//search_variables (&s->list_of_items);
	search_sql_variables (&s->list_of_items, 'i');

	ptr = get_select (r->cmd_data.command_data_u.select_cmd.sql, r->cmd_data.command_data_u.select_cmd.forupdate);
	i = 0;

	if (input_bind && input_bind->list.list_len)
	  {
	    i += 1;
	  }
	if (output_bind && output_bind->list.list_len)
	  {
	    i += 2;
	  }

	if (i)
	  {
	    printc ("{ ");
	    tmp_ccnt++;
	  }
	if (i & 2)
	  {
	    printc ("$RSet=null;");
	  }

	if (i & 1)
	  {
	    print_in_binding (input_bind);
	  }


	print_when_sql_start ();
	switch (i)
	  {
	  case 0:
	    printc ("SQLExecute(\"%s\");", escape_quotes_and_remove_nl (ptr, 0));
	    break;
	  case 1:
	    printc ("SQLExecute(\"%s\",$InBind);", escape_quotes_and_remove_nl (ptr, 0));
	    break;
	  case 2:
	    printc ("$RSet=SQLExecuteInto(\"%s\");", escape_quotes_and_remove_nl (ptr, 0));
	    break;
	  case 3:
	    printc ("$RSet=SQLExecuteInto(\"%s\",$InBind);", escape_quotes_and_remove_nl (ptr, 0));
	    break;

	  }
	print_when_sql_end ();
	if (i & 2)
	  {
	    printc ("if ($RSet!=null) {");
	    tmp_ccnt++;
	    print_copy_fromRSet (output_bind);
	    printc ("$RSet.Dispose();");
	    tmp_ccnt--;
	    printc ("}");
	  }

	if (i)
	  {
	    tmp_ccnt--;
	    printc ("}");
	  }
      }
      break;

    case E_CMD_SQL_BLOCK_CMD:
      print_sql_block_cmd (&r->cmd_data.command_data_u.sql_block_cmd);
      break;



// UI STUFF
    case E_CMD_DISPLAY_FORM_CMD:	/* UI */
      set_nonewlines ();
      printc ("UILib_DisplayForm(");
      real_print_expr (r->cmd_data.command_data_u.display_form_cmd.formname);
      printc (",%s);", get_attributes_as_string (r->cmd_data.command_data_u.display_form_cmd.attributes));
      clr_nonewlines ();
      break;


    case E_CMD_MENU_CMD:
      {
	char buff[200];
	int variableTitle = 1;
	need_daylight ();
	sprintf (buff, "$menu_%d", r->cmd_data.command_data_u.menu_cmd.sio);
	push_menu_context (buff);
	printc ("// MENU");	//@ FIXME
	printc ("%s=new UILib_Menu(%s);", buff, get_attributes_as_string (r->cmd_data.command_data_u.menu_cmd.menu_attrib));
	//tmp_ccnt++;

	if (r->cmd_data.command_data_u.menu_cmd.menu_title)
	  {
	    if (r->cmd_data.command_data_u.menu_cmd.menu_title->expr_type == ET_EXPR_LITERAL_STRING
		|| r->cmd_data.command_data_u.menu_cmd.menu_title->expr_type == ET_E_V_OR_LIT_STRING)
	      {
		set_nonewlines ();
		printc ("%s->SetTitle(", buff);
		real_print_expr (r->cmd_data.command_data_u.menu_cmd.menu_title);
		printc (");");
		variableTitle = 0;
		clr_nonewlines ();
	      }
	  }
	print_uievents (buff, r->cmd_data.command_data_u.menu_cmd.events, 0, r);
	printc ("#");
	printc ("while (%s->RunMenu()) {", buff);
	tmp_ccnt++;

	if (variableTitle)
	  {
	    printc (" // The title may change if its a variable or function call");
	    set_nonewlines ();
	    printc ("%s->SetTitle(", buff);
	    real_print_expr (r->cmd_data.command_data_u.menu_cmd.menu_title);
	    printc (");");
	    clr_nonewlines ();
	  }

	printc ("switch(%s->GetEventID()) {", buff);
	tmp_ccnt++;
	print_uievents (buff, r->cmd_data.command_data_u.menu_cmd.events, 1, r);
	printc (" default : break;  // Does nothing - just a placeholder...");
	tmp_ccnt--;
	printc ("}");
	printc("continue_menu_%d: ;", r->cmd_data.command_data_u.menu_cmd.blockid);
	tmp_ccnt--;
	printc ("}");
	//tmp_ccnt--;
	//printc ("}");
	pop_menu_context ();
      }
      break;

    case E_CMD_INPUT_CMD:
      need_daylight ();
      {
	char buff[200];
	char rsetbuff[200];
	//int b;
	sprintf (buff, "$%s_input_%d", cleaned_fname (compiling_module ()), r->cmd_data.command_data_u.input_cmd.blockid);
	push_ui_context (buff);
	//printc ("{");
	//tmp_ccnt++;


	set_nonewlines ();
	printc ("%s=new UILib_Input(%s, %d, ", buff, get_attributes_as_string (r->cmd_data.command_data_u.input_cmd.attributes), r->cmd_data.command_data_u.input_cmd.helpno);

	if (r->cmd_data.command_data_u.input_cmd.without_defaults == EB_TRUE)
	  {
	    printc ("true");
	  }
	else
	  {
	    printc ("false");
	  }
	printc (");");
	clr_nonewlines ();
	//tmp_ccnt++;

	//if (r->cmd_data.command_data_u.input_cmd.without_defaults == EB_TRUE) {
		//printc("{");
		//printc("}");
		//print_copy_fromRSet (r->cmd_data.command_data_u.input_cmd.variables);
	//}

	//for (b = 0; b < r->cmd_data.command_data_u.input_cmd.field_list->field_list_entries.field_list_entries_len; b++)
	  //{
		printc("%s->SetFields(%s);", buff,field_name_list_as_char (r->cmd_data.command_data_u.input_cmd.field_list));
	    //printc ("%s.SetField(%s);", buff, field_name_as_char (&r->cmd_data.command_data_u.input_cmd.field_list->field_list_entries.  field_list_entries_val[b]));
	  //}

	print_uievents (buff, r->cmd_data.command_data_u.input_cmd.events, 0, r);
	printc ("#");
	printc ("while (true) {");
	tmp_ccnt++;
        	printc("if (%s->WantNewData()) {",buff);
		tmp_ccnt++;
		print_input_binding(buff,r->cmd_data.command_data_u.input_cmd.variables);
		printc("%s->SetInitialData();",buff);
		tmp_ccnt--;
		printc("}");
	//printc ("IfxResult RSet;");
	printc("%s->WaitForEvent();",buff);
	//printc (" // Copy variables ?");
	//printc("{");
	//tmp_ccnt++;
	//printc ("RSet=%s.CopyVariables();", buff);
	printc ("if (%s->RSet!=null) {",buff);
	tmp_ccnt++;
	sprintf(rsetbuff,"%s->RSet",buff);
	print_copy_frombuff_RSet (rsetbuff,r->cmd_data.command_data_u.input_cmd.variables);
	tmp_ccnt--;
	printc("}");
	//tmp_ccnt--;
	//printc("}");
	printc ("if (!%s->RunInput()) {break;}", buff);

	printc ("switch(%s->GetEventID()) {", buff);
	tmp_ccnt++;
	print_uievents (buff, r->cmd_data.command_data_u.input_cmd.events, 1, r);
	printc (" default : break;  // Does nothing - just a placeholder...");
	tmp_ccnt--;
	printc ("}");
	printc("continue_input_%d: ;", r->cmd_data.command_data_u.input_cmd.blockid);
	tmp_ccnt--;
	printc ("}");
	//tmp_ccnt--;
	//printc ("}");
	//tmp_ccnt--;
	//printc ("}");
	pop_ui_context ();
      }

      break;



    case E_CMD_CONSTRUCT_CMD:
      need_daylight ();
      {
	char buff[200];
	int b;
	sprintf (buff, "$construct_%d", r->cmd_data.command_data_u.construct_cmd.sio);
	push_ui_context (buff);

	printc ("%s=new UILib_Construct(%s, %d);", buff,
		get_attributes_as_string (r->cmd_data.command_data_u.construct_cmd.attributes),
		r->cmd_data.command_data_u.construct_cmd.helpno);

	//tmp_ccnt++;
	for (b = 0; b < r->cmd_data.command_data_u.construct_cmd.list->field_list_entries.field_list_entries_len; b++)
	  {
	    printc ("%s->SetField(%s);", buff,
		    field_name_as_char (&r->cmd_data.command_data_u.construct_cmd.list->field_list_entries.
					field_list_entries_val[b]));
	  }


	print_uievents (buff, r->cmd_data.command_data_u.construct_cmd.events, 0, r);
	printc ("#");
	printc ("while (%s->RunConstruct())  {", buff);
	tmp_ccnt++;
	printc ("switch(%s->GetEventID()) {", buff);
	tmp_ccnt++;
	print_uievents (buff, r->cmd_data.command_data_u.construct_cmd.events, 1, r);
	printc (" default : break;  // Does nothing - just a placeholder...");
	tmp_ccnt--;

	printc ("}");
	printc("continue_construct_%d: ;", r->cmd_data.command_data_u.construct_cmd.blockid);
	tmp_ccnt--;
	printc ("}");
	printc ("if (%s->HasConstructResult()) {", buff);
	printc ("  %s=%s->GetConstructResult();", decode_varbind (r->cmd_data.command_data_u.construct_cmd.constr_var, 'r', 0),
		buff);
	printc ("}");
	//tmp_ccnt--;
	//printc ("}");
	pop_ui_context ();
      }
      break;


    case E_CMD_DISPLAY_ARRAY_CMD:
      need_daylight ();
      {
	need_daylight ();
	push_ui_context ("Display");
	set_nonewlines ();
	printc ("$Display=new UILib_DisplayArray(");
	real_print_expr (r->cmd_data.command_data_u.display_array_cmd.srec);
	printc (",");
	real_print_expr (r->cmd_data.command_data_u.display_array_cmd.arrayname);
	printc (",");
	printc ("%s,", get_attributes_as_string (r->cmd_data.command_data_u.display_array_cmd.attributes));
	printc ("%d);", r->cmd_data.command_data_u.display_array_cmd.helpno);
	clr_nonewlines ();
	//tmp_ccnt++;

	print_uievents ("$Display", r->cmd_data.command_data_u.display_array_cmd.events, 0, r);

	printc ("while ($Display->RunDisplay()) {");
	tmp_ccnt++;
	printc ("switch ($Display->GetEventID()) {");
	tmp_ccnt++;
	print_uievents ("$Display", r->cmd_data.command_data_u.display_array_cmd.events, 1, r);
	printc (" default : break;  // Does nothing - just a placeholder...");

	tmp_ccnt--;
	printc ("}");
	printc("continue_display_%d: ;", r->cmd_data.command_data_u.display_array_cmd.blockid);
	tmp_ccnt--;
	printc ("}");
	//tmp_ccnt--;
	//printc ("}");
	pop_ui_context ();
      }
      break;

    case E_CMD_PROMPT_CMD:
      {
	expr_str *ptr;
	need_daylight ();
	set_nonewlines ();
	printc ("$Prompt=new UILib_Prompt(");
	real_print_expr_list_with_separator (r->cmd_data.command_data_u.prompt_cmd.prompt_str, ".");
	printc (",");
	printc ("%s,", get_attributes_as_string (r->cmd_data.command_data_u.prompt_cmd.prompt_str_attrib));
	printc ("%s,", get_attributes_as_string (r->cmd_data.command_data_u.prompt_cmd.prompt_fld_attrib));
	push_ui_context ("Prompt");

	if (r->cmd_data.command_data_u.prompt_cmd.for_char == EB_TRUE)
	  {
	    printc ("true,");
	  }
	else
	  {
	    printc ("false,");
	  }

	printc ("%d);", r->cmd_data.command_data_u.prompt_cmd.helpno);
	//tmp_ccnt++;
	clr_nonewlines ();
	print_uievents ("$Prompt", r->cmd_data.command_data_u.prompt_cmd.events, 0, r);
	printc ("$Prompt.DoPrompt();");

	printc ("if ($Prompt.gotResult) {");
	tmp_ccnt++;
	ptr = r->cmd_data.command_data_u.prompt_cmd.promptvar;

	if ((expr_datatype (0, 0, ptr) & DTYPE_MASK) != DTYPE_CHAR)
	  {			// the variable is not a string
	    printc ("%s=%s($Prompt.GetResult());", decode_varbind (ptr, 'r', 0),
		    explicitCastFunction (expr_datatype (0, 0, ptr) & DTYPE_MASK));
	  }
	else
	  {
	    printc ("%s=$Prompt.GetResult();", decode_varbind (ptr, 'r', 0));
	  }
	tmp_ccnt--;
	printc ("} else { // ON KEY pressed...");
	tmp_ccnt++;
	printc ("switch ($Prompt.GetEventID()) {");
	tmp_ccnt++;
	print_uievents ("$Prompt", r->cmd_data.command_data_u.prompt_cmd.events, 1, r);
	printc (" default : break;  // Does nothing - just a placeholder...");
	tmp_ccnt--;
	printc ("}");
	tmp_ccnt--;
	printc ("}");
	//tmp_ccnt--;
	//printc ("}");
	pop_ui_context ();
      }
      break;


    case E_CMD_INPUT_ARRAY_CMD:
      need_daylight ();
      {
	char buff[200];
	//int b;
 struct variable *v;

	sprintf (buff, "$input_%d", r->cmd_data.command_data_u.input_array_cmd.sio);
	push_ui_context (buff);
	set_nonewlines ();
	printc ("%s=new UILib_InputArray(%s, %d, ", buff,
		get_attributes_as_string (r->cmd_data.command_data_u.input_array_cmd.attributes),
		r->cmd_data.command_data_u.input_array_cmd.helpno);

	if (r->cmd_data.command_data_u.input_array_cmd.without_defaults == EB_TRUE)
	  {
	    printc ("true");
	  }
	else
	  {
	    printc ("false");
	  }
	printc (",");
	real_print_expr (r->cmd_data.command_data_u.input_array_cmd.srec);
	printc (",");
	real_print_expr (r->cmd_data.command_data_u.input_array_cmd.arrayname);
	printc (");");
	//tmp_ccnt++;
	clr_nonewlines ();

/* We dont get passed in a real binding - just the variable
 * so we need to generate our own binding....
 *
 * The array can be one of two types
 * 1) A simple array ( eg ARRAY OF char(20))
 * 2) A record array ( eg ARRAY OF RECORD ... END RECORD )
 *
 * So - lets first have a look and see which type we've got
 * */
  v=local_find_variable_from_usage(r->cmd_data.command_data_u.input_array_cmd.arrayname->expr_str_u.expr_variable_usage);
  if (v->var_data.variable_type==VARIABLE_TYPE_RECORD) {
	int a;
	struct variable *v2;
	//struct variable_usage *vu_top;
	//struct variable_usage *vu_next;
	//struct expr_str *vu_as_expr;
	

	/* Its an array of RECORD */
	//cnt=v->var_data.variable_data_u.v_record.variables.variables_len;
	/* First - we need to print the 'obind' - which has the types */
	for (a=0;a<v->var_data.variable_data_u.v_record.variables.variables_len;a++) {
		//int dtype;
		v2=v->var_data.variable_data_u.v_record.variables.variables_val[a];
		if (v2->var_data.variable_type!=VARIABLE_TYPE_SIMPLE) {
			a4gl_yyerror("Expecting only simple types in the array");
			return 0;
		}
		//dtype=encode_variable_datatype(v2->var_data.variable_data_u.v_simple.datatype, v2->var_data.variable_data_u.v_simple.dimensions[0], v2->var_data.variable_data_u.v_simple.dimensions[1]);
		 print_input_array_binding(buff, a, v2->var_data.variable_data_u.v_simple.datatype, v2->var_data.variable_data_u.v_simple.dimensions[0]);
		//dtype&DTYPE_MASK,DECODE_SIZE(dtype));
		//printc("%s.atatype(%d,%d,%d);", a, dtype&DTYPE_MASK,DECODE_SIZE(dtype));

	}
  } else {
	// Its a simple array of a single datatype
	// just a little easier than the record !
  	//cnt = 1;
	int dtype;
		dtype=encode_variable_datatype(v->var_data.variable_data_u.v_simple.datatype, v->var_data.variable_data_u.v_simple.dimensions[0], v->var_data.variable_data_u.v_simple.dimensions[1]);
		 print_input_array_binding(buff, 0,dtype&DTYPE_MASK,DECODE_SIZE(dtype));
  }

	print_uievents (buff, r->cmd_data.command_data_u.input_array_cmd.events, 0, r);
	printc ("#");
	printc ("while (true) {");
	tmp_ccnt++;
	printc ("if (!%s.RunInput()) {break;}", buff);
	printc ("switch(%s.GetEventID()) {", buff);
	tmp_ccnt++;
	print_uievents (buff, r->cmd_data.command_data_u.input_array_cmd.events, 1, r);
	printc (" default : break;  // Does nothing - just a placeholder...");
	tmp_ccnt--;
	printc ("}");
	printc("continue_input_%d: ;", r->cmd_data.command_data_u.display_array_cmd.blockid);
	tmp_ccnt--;
	printc ("}");
	//tmp_ccnt--;
	//printc ("}");
	pop_ui_context ();
      }
      break;

    case E_CMD_CANCEL_CMD:
      printc ("// CANCEL CMD <------------------------------------------------------");	// @FIXME
      printc ("@FIXME - CANCEL");
      break;



// These are all Aubit4GL or 4Js extensions  and shouldnt be needed
// for standard Informix4GL...
    case E_CMD_ALLOC_ARR_CMD:
    case E_CMD_RESIZE_ARR_CMD:
    case E_CMD_DEALLOC_ARR_CMD:
    case E_CMD_CONNECT_CMD:
    case E_CMD_AT_TERM_CMD:
    case E_CMD_CHECK_MENU_CMD:
    case E_CMD_DISABLE_MENU_CMD:
    case E_CMD_DISPLAY_B_N_CMD:
    case E_CMD_ENABLE_MENU_CMD:
    case E_CMD_HIDE_CMD:
    case E_CMD_MOVE_CMD:
    case E_CMD_MSG_BOX_CMD:
    case E_CMD_NEXT_FORM_CMD:
    case E_CMD_OPEN_FORM_GUI_CMD:
    case E_CMD_OPEN_STATUSBOX_CMD:
    case E_CMD_PRINT_IMG_CMD:
    case E_CMD_SHOW_CMD:
      //case E_CMD_SHOW_OPTION_CMD:
    case E_CMD_SKIP_BY_CMD:
    case E_CMD_SKIP_TO_CMD:
    case E_CMD_START_RPC_CMD:
    case E_CMD_UNCHECK_MENU_CMD:
    case E_CMD_VALIDATE_CMD:
    case E_CMD_SHOW_MENU_CMD:
    case E_CMD_ENABLE_CMD:
    case E_CMD_ENABLE_FORM_CMD:
    case E_CMD_DISABLE_CMD:
    case E_CMD_DISABLE_FORM_CMD:
    case E_CMD_PDF_CALL_CMD:
    case E_CMD_SET_SESSION_CMD:
    case E_CMD_RUN_WAITING_FOR_CMD:
    case E_CMD_SQL_DEBUG_FILE_CMD:
    case E_CMD_LINT_IGNORE_CMD:
    case E_CMD_SORT_CMD:
    case E_CMD_CREATE_PROCEDURE_CMD:
    case E_CMD_SPL_IF_CMD:
    case E_CMD_SPL_FOR_CMD:
    case E_CMD_SPL_TRACE_CMD:
    case E_CMD_SPL_BLOCK_CMD:
    case E_CMD_LINT_EXPECT_CMD:
    case E_CMD_COPYBACK_CMD:
    case E_CMD_SPL_SYSTEM_CMD:
    case E_CMD_SPL_FOREACH_SELECT_CMD:
    case E_CMD_SPL_FOREACH_EXECUTE_CMD:
    case E_CMD_SPL_LET_CMD:
    case E_CMD_SPL_RAISE_EXCEPTION_CMD:
    case E_CMD_SPL_ON_EXCEPTION_CMD:
    case E_CMD_SPL_WHILE_CMD:
    case E_CMD_SPL_CALL_CMD:
    case E_CMD_SPL_RETURN_CMD:
    case E_CMD_EXECUTE_PROCEDURE_CMD:

    case E_CMD_LAST:


      printc ("@FIXME Unhandled...");
      break;


      //default:
      //printc ("// Not defined");
      //break;

    }

  return 1;
}



int
dump_cmds (struct s_commands *c, struct command *parent)
{
  int a;
int loop=1;
  if (c == 0)
    return 1;

  for (a = 0; a < c->cmds.cmds_len; a++)
    {

	if (loop==0) {
		switch (c->cmds.cmds_val[a]->cmd_data.type) {
			case E_CMD_LABEL_CMD:
				loop=1;
				break;

			default: 
				break;
		}
	}

	if (loop) {
        	if (!dump_cmd (c->cmds.cmds_val[a], parent)) {
			return 0;
		} 
	} else {
		if (c->cmds.cmds_val[a]->cmd_data.type==E_CMD_WHENEVER_CMD || c->cmds.cmds_val[a]->cmd_data.type==E_CMD_LABEL_CMD) ;
		else {
			printc("/* FGLCHECK:  IGNORE %s.%d : %s as dead code */",  c->cmds.cmds_val[a]->module, c->cmds.cmds_val[a]->lineno, decode_cmd_type(c->cmds.cmds_val[a]->cmd_data.type));
		}
	}

	if (c->cmds.cmds_val[a]->cmd_data.type==E_CMD_WHENEVER_CMD || c->cmds.cmds_val[a]->cmd_data.type==E_CMD_LABEL_CMD) ;
	else {
		last_was_return=0;
	}

	// Theres no point in dumping dead code...
	// so - if theres nothing after this one - 
	// exit out :-)
	switch (c->cmds.cmds_val[a]->cmd_data.type) {
	        case E_CMD_EXIT_PROG_CMD:
        	case E_CMD_CONTINUE_CMD:
        	case E_CMD_EXT_CMD:
        	case E_CMD_GOTO_CMD:
			loop=0;
			break;

        	case E_CMD_RETURN_CMD:
			loop=0;
			last_was_return=1;
			break;
		default: 
			break;
	}
    }
  return 1;
}


char *
tr_dot_to_underscore (char *s)
{
  static char buff[2000];
  char *ptr;
  strcpy (buff, s);

  while (1)
    {
	int changed=0;
      	ptr = strchr (buff, '.'); if (ptr) {*ptr= '_'; changed++;}
      	ptr = strchr (buff, '['); if (ptr) {*ptr= '_'; changed++;}
      	ptr = strchr (buff, ']'); if (ptr) {*ptr= '_'; changed++;}
      	ptr = strchr (buff, '\''); if (ptr) {*ptr= '_'; changed++;}

      	if (!changed) break;
    }
//printf("tr_dot_to_underscore (%s)=%s\n",s,buff);

  return buff;
}


#ifdef OLD
char *
return_datatype (int a)
{
  static char buff[200];
  int olda;
int sz;
  olda = a;
  sz=a>>16;
  a = a & DTYPE_MASK;

  switch (a)
    {
    case 0:
      return "string";

    case DTYPE_VCHAR:
      return "string";

    case DTYPE_SMINT:
      return "int?";

    case DTYPE_INT:
    case DTYPE_SERIAL:		// serial..
      return "int?";

    case DTYPE_DATE:
      return "IfxDate?";

    case DTYPE_DECIMAL:
      return "CMDecimal?";

    case DTYPE_INTERVAL:

//A4GL_pause_execution();

	if (sz) {
	  if (((sz >> 4) & 0xf) <= 2)
      		return "IfxMonthSpan?";
	else
      		return "IfxTimeSpan?";
	} else {
      		return "IfxInterval?";
	}

    case DTYPE_DTIME:
      return "IfxDateTime?";

    case DTYPE_SMFLOAT:
      return "float?";

    case DTYPE_FLOAT:
      return "double?";

    case DTYPE_BYTE:
      return "IfxByte";

    case DTYPE_TEXT:
      return "IfxByte";

    case 90:
      return "bool";
    }

  sprintf (buff, "unknown_%d", a);
  return buff;
}
#endif


static int
single_rec_return (struct s_commands *func_cmds)
{
  int a;
  int cnt;
  int rentry;
  struct command *r = 0;
  struct command *rret = 0;
  int nreturns = 0;
  struct expr_str *e;
  //int b;
  char *val;
  char left[200];
  char buff[200] = "";
  cnt = 0;

  if (func_cmds == 0)
    return 0;

  for (a = 0; a < func_cmds->cmds.cmds_len; a++)
    {
      r = func_cmds->cmds.cmds_val[a];

      if (r->cmd_data.type == E_CMD_RETURN_CMD)
	{
	  rret = r;
	  if (r->cmd_data.command_data_u.return_cmd.retvals == 0)
	    return 0;		// no returns
	  nreturns = r->cmd_data.command_data_u.return_cmd.retvals->list.list_len;
	  if (nreturns <= 1)
	    {
	      return 0;
	    }			// single or no value..
	  if (cnt)
	    return 0;		// multiple returns
	  rentry = a;
	  cnt++;
	}
    }

  r = rret;
  if (nreturns <= 1)
    {
      return 0;
    }				// single or no value..
  if (r == 0)
    return 0;

  a = rentry;
  if (nreturns)
    dtypes = realloc (dtypes, sizeof (int) * nreturns);

  for (a = 0; a < nreturns; a++)
    {
      char *ptr;
      e = r->cmd_data.command_data_u.return_cmd.retvals->list.list_val[a];

      if (e->expr_type != ET_EXPR_VARIABLE_USAGE)
	{
	  return 0;
	}
      val = local_expr_as_string (e);
      if (a == 0)
	{

	  strcpy (left, val);
	  ptr = strchr (left, '.');
	  if (ptr)
	    *ptr = 0;
	  ptr = strchr (left, '[');
	  if (ptr)
	    *ptr = 0;
	  continue;
	}
      else
	{
	  strcpy (buff, val);
	  ptr = strchr (buff, '.');
	  if (ptr)
	    *ptr = 0;
	  ptr = strchr (buff, '[');
	  if (ptr)
	    *ptr = 0;
	}
      if (strcmp (left, buff) != 0)
	return 0;
    }
  last_rret = rret;
  return 1;
}

static int
single_rec_parameter (struct expr_str_list *l)
{
  int a;
  char left[200];
  char buff[200] = "";
  char *ptr;
  if (l == NULL)
    return 0;
  if (l->list.list_len <= 1)
    return 0;

  for (a = 0; a < l->list.list_len; a++)
    {
      if (a == 0)
	{
	  strcpy (left, generation_get_variable_usage (l->list.list_val[a]));
	  ptr = strchr (left, '.');
	  if (ptr)
	    *ptr = 0;
	  ptr = strchr (left, '[');
	  if (ptr)
	    *ptr = 0;
	  continue;
	}
      else
	{
	  strcpy (buff, generation_get_variable_usage (l->list.list_val[a]));
	  ptr = strchr (buff, '.');
	  if (ptr)
	    *ptr = 0;
	  ptr = strchr (buff, '[');
	  if (ptr)
	    *ptr = 0;
	}
      if (strcmp (left, buff) != 0)
	return 0;

    }
  return 1;
}









static int
dump_function (struct s_function_definition *function_definition, int ismain)
{
  struct s_commands *func_cmds = 0;
  struct expr_str_list *expanded_params;

  int a;
  int funcno;
  int need_Comma = 0;
  expr_str_list *function_parameters = 0;
  int flag = 0;

  expanded_params = expand_parameters (&function_definition->variables, function_definition->parameters);
  if (tmp_ccnt)
    {
      A4GL_assertion (1, "tmp_ccnt shouldn't be set (beginning of function)");
    }

  if (nonewlines)
    {
      A4GL_assertion (1, "nonewlines shouldn't be set (beginning of function)");
    }

  fprintf (hfile, "   /*********************************************************************\n");
  fprintf (hfile, "   From function %s:\n", function_definition->funcname);
  fprintf (hfile, "   *********************************************************************/\n");
  printc ("#");
  printc ("#");
  printc ("#");
  dump_comments (function_definition->lineno);

  current_func = function_definition;
  when_set_to_call = 0;
  current_pdf_report = 0;
  current_report = 0;

  returns = 0;


  if (ismain || A4GL_aubit_strcasecmp (function_definition->funcname, "MAIN") == 0)
    {

      printc ("function AppEntry() {");
      //printc ("%s", initModVariables);
    }
  else
    {
      struct command *r;



      funcno = is_bolton_function (function_definition->funcname);

      func_cmds = linearise_commands (0, 0);
      linearise_commands (func_cmds, function_definition->func_commands);


      if (funcno == -1)
	{
	  nreturns = 0;




	  for (a = 0; a < func_cmds->cmds.cmds_len; a++)
	    {
	      r = func_cmds->cmds.cmds_val[a];

	      if (r->cmd_data.type == E_CMD_RETURN_CMD)
		{

		  if (r->cmd_data.command_data_u.return_cmd.retvals)
		    {
		      int b;
		      nreturns = r->cmd_data.command_data_u.return_cmd.retvals->list.list_len;
		      if (nreturns)
			{
			  dtypes = realloc (dtypes, sizeof (int) * nreturns);
			}

		      for (b = 0; b < nreturns; b++)
			{
			  dtypes[b] = expr_datatype (0, 0, r->cmd_data.command_data_u.return_cmd.retvals->list.list_val[b]);
			  //if (dtypes[b] == 90)
			    //{
			      //dtypes[b] = DTYPE_INT;
			    //}
			}
		    }

		  break;
		}
	    }
	}
      else
	{
	  int b;
	  nreturns = get_bolton_nrets (funcno);
	  if (nreturns)
	    {
	      dtypes = realloc (dtypes, sizeof (int) * nreturns);
	    }
	  else
	    {
	      dtypes = 0;
	    }
	  for (b = 0; b < nreturns; b++)
	    {
	      dtypes[b] = get_bolton_rtype (funcno, b);
	      //if (dtypes[b] == 90) { dtypes[b] = DTYPE_INT; }
	    }

	}



      Currnrets = nreturns;

set_nonewlines();
	  printc ("function %s (", function_definition->funcname);


      // We'll create a separate list of parameter variables
      if (function_definition->parameters)
	{
	  function_parameters = expand_parameters (&function_definition->variables, function_definition->parameters);

	  //int skipped;
	  //char isrec[256] = "";
	  for (a = 0; a < function_parameters->list.list_len; a++)
	    {
	      if (a)
		printc (",");

		//if (strcmp(tr_dot_to_underscore (generation_get_variable_usage (function_parameters->list.list_val[a])),"L_lb_awb_debug")==0) {
			//A4GL_pause_execution();
		//}


	      printc ("$InVar_%s", tr_dot_to_underscore (generation_get_variable_usage (function_parameters->list.list_val[a])));
	      //need_Comma++;
	    }
	}

      printc (") {");
      clr_nonewlines ();


    }
  //printc ("/* FUNCTION %s */", function_definition->funcname);
// local variables...

  if (function_definition->variables.variables.variables_len)
    {
      for (a = 0; a < function_definition->variables.variables.variables_len; a++)
	{
	  print_variable_new (function_definition->variables.variables.variables_val[a], 'L', 0, 0);
	}
    }


  tmp_ccnt++;
  print_function_variable_init (&function_definition->variables);

  // We've printed our variables - now copy in the parameters...
  if (function_parameters)
    {
      //int skipped;
      //char isrec[256] = "";
      for (a = 0; a < function_parameters->list.list_len; a++)
	{
	  printc ("$%s=$InVar_%s;", generation_get_variable_usage (function_parameters->list.list_val[a]),
		  tr_dot_to_underscore (generation_get_variable_usage (function_parameters->list.list_val[a])));
	}
    }


  printc ("#");
  if (ismain || A4GL_aubit_strcasecmp (function_definition->funcname, "MAIN") == 0)
    {
      char *db;
      db = curr_module->mod_dbname;
      if (db)
	{
	  if (!(curr_module->schema_only == EB_TRUE))
	    {
	      printc ("DBConnect(\"%s\");", db);
	    }
	}
    }


  //{
  //}

  if (function_definition->func_commands)
    {
	dump_cmds (function_definition->func_commands, NULL);

	/*
      for (a = 0; a < function_definition->func_commands->cmds.cmds_len; a++)
	{
	  dump_cmd (function_definition->func_commands->cmds.cmds_val[a], 0);
	}
	*/
    }

  if (nreturns==1) {
		if (!last_was_return) {
			/* Lets add a fake return - just to keep the C# compiler happy */
			switch (dtypes[0]&DTYPE_MASK)  {
				case DTYPE_SMINT:
				case DTYPE_FLOAT:
				case DTYPE_SMFLOAT:
				case DTYPE_MONEY:
				case DTYPE_SERIAL:
				case DTYPE_INT: printc("return 0; /* FGLCHECK:  drop through RETURN value */"); break;

		
				case 90: printc("return false; /* FGLCHECK: drop through RETURN value */"); break;

				case DTYPE_DECIMAL:
					 printc("return null; /* FGLCHECK: drop through RETURN value */"); break;
				
				case DTYPE_DATE: printc("return null; /* FGLCHECK: drop through RETURN value */"); break;
				case DTYPE_STRING: printc("return \"\"; /* FGLCHECK: drop through RETURN value */"); break;
			
			}
		
		}
  }

  dump_comments (function_definition->lastlineno);

  if (ismain || A4GL_aubit_strcasecmp (function_definition->funcname, "MAIN") == 0)
    {
      tmp_ccnt--;
      printc ("#");
    }
  else
    {
      tmp_ccnt--;
      printc ("#");
    }


  if (tmp_ccnt)
    {
	printf("Function : %s\n", function_definition->funcname);
      A4GL_assertion (1, "tmp_ccnt shouldn't be set... ");
    }

  if (nonewlines)
    {
      A4GL_assertion (1, "nonewlines shouldn't be set...");
    }
  printc ("}");

  return 1;
}


static int isInReport ()
{
  return isReport;
  return 0;
}


int
LEXLIB_A4GL_write_generated_code (struct module_definition *m)
{
  int a;
  int mentry;
  curr_module = m;

  open_outfile ();
  //create_protos_from_module (m);
  A4GL_debug ("Dump 1");
  dump_comments (1);

  print_module_variable_init (&m->module_variables.variables);


  if (m->exported_global_variables.variables.variables.variables_len)
    {
      //printc ("GLOBALS");

      tmp_ccnt++;
      for (a = 0; a < m->exported_global_variables.variables.variables.variables_len; a++)
	{
	  print_variable_new (m->exported_global_variables.variables.variables.variables_val[a], 'g', 0, 0);
	}
      tmp_ccnt--;
      //printc ("END GLOBALS");
    }

  A4GL_debug ("Dump 2");

  if (m->module_variables.variables.variables.variables_len)
    {
      for (a = 0; a < m->module_variables.variables.variables.variables_len; a++)
	{
	  print_variable_new (m->module_variables.variables.variables.variables_val[a], 'M', 0, 0);
	}
    }
  A4GL_debug ("Dump 3");

//printf("DUMPING %d entries\n", m->module_entries.module_entries_len);
  for (mentry = 0; mentry < m->module_entries.module_entries_len; mentry++)
    {
      int ok = 1;

      current_func = 0;
      current_pdf_report = 0;
      current_report = 0;

      isReport = 0;
      //printf("DUMPING entry %d\n", mentry);

      switch (m->module_entries.module_entries_val[mentry]->met_type)
	{
	  // case E_MET_IMPORT_FUNCTION_DEFINITION:  struct s_import_function_definition import_function_definition;
	  // case E_MET_IMPORT_LEGACY_DEFINITION:    struct s_import_legacy_definition       import_legacy_definition;

	case E_MET_REPORT_DEFINITION:
	  currfuncname = m->module_entries.module_entries_val[mentry]->module_entry_u.report_definition.funcname;
	  current_entry_variables = &m->module_entries.module_entries_val[mentry]->module_entry_u.report_definition.variables;
	  isReport = 1;
	  ok = dump_report (&m->module_entries.module_entries_val[mentry]->module_entry_u.report_definition);
	  //printf("REP OK=%d\n",ok);
	  break;
	case E_MET_PDF_REPORT_DEFINITION:
	  isReport = 1;
	  currfuncname = m->module_entries.module_entries_val[mentry]->module_entry_u.pdf_report_definition.funcname;
	  current_entry_variables = &m->module_entries.module_entries_val[mentry]->module_entry_u.pdf_report_definition.variables;
	  ok = dump_pdf_report (&m->module_entries.module_entries_val[mentry]->module_entry_u.pdf_report_definition);
	  //printf("PDF OK=%d\n",ok);
	  break;
	case E_MET_CMD:
	  currfuncname = 0;
	  ok = dump_cmd (m->module_entries.module_entries_val[mentry]->module_entry_u.cmd, 0);
	  //printf("CMD OK=%d\n",ok);
	  break;
	case E_MET_MAIN_DEFINITION:
	  currfuncname = "MAIN";
	  current_entry_variables = &m->module_entries.module_entries_val[mentry]->module_entry_u.function_definition.variables;
	  ok = dump_function (&m->module_entries.module_entries_val[mentry]->module_entry_u.function_definition, 1);
	  //printf("MAIN OK=%d\n",ok);
	  break;
	case E_MET_FUNCTION_DEFINITION:
	  currfuncname = m->module_entries.module_entries_val[mentry]->module_entry_u.function_definition.funcname;
	  current_entry_variables = &m->module_entries.module_entries_val[mentry]->module_entry_u.function_definition.variables;

	  ok = dump_function (&m->module_entries.module_entries_val[mentry]->module_entry_u.function_definition, 0);
	  //printf("FUNC OK=%d\n",ok);
	  break;
	default:
	  break;
	}

      A4GL_debug ("Dump 4");
      if (!ok)
	{
	  printf ("Not ok...\n");
	  return 0;
	}
    }

  A4GL_debug ("Dump 5");
  dump_comments (1000000);
  //fprintf(outfile, "\n\n\n}\n");
  //fprintf(hfile, "\n\n\n}\n");
  A4GL_debug ("Dump 6");
  //tmp_ccnt--;
  printc("?>");
  if (outfile)
    {
      fclose (outfile);
      outfile = 0;
    }


  if (hfile)
    {
      fclose (hfile);
      hfile = 0;
    }

  A4GL_debug ("Dump 7");
  merge_files ();
  A4GL_debug ("Dump 8");
  return 1;
}







char *
field_name_list_as_char (struct fh_field_list *fl)
{
  int a;
  char *ptr = 0;
  char *ptr_field;
  char *buff;

  ptr = acl_malloc2 (10);	/* Set it up initially... */
  strcpy (ptr, "");
  for (a = 0; a < fl->field_list_entries.field_list_entries_len; a++)
    {
      ptr_field = field_name_as_char (&fl->field_list_entries.field_list_entries_val[a]);
      ptr = acl_realloc (ptr, strlen (ptr) + strlen (ptr_field) + 2);
      if (strlen (ptr))
	strcat (ptr, ",");
      strcat (ptr, ptr_field);
    }

  buff=malloc(strlen(ptr)+1000);

  //sprintf(buff,"new CMField[]{%s}",ptr); 
  sprintf(buff,"%s",ptr); 
  free(ptr);
  return buff;
  //return ptr;
}


static int isCharExpr(expr_str *e) {
int dtype;
dtype=expr_datatype (0, 0, e)  & DTYPE_MASK;
if (dtype==DTYPE_CHAR) return 1;
if (dtype==DTYPE_VCHAR) return 1;
return 0;
}






#ifdef NOT_NEEDED
static char *
local_rettype_integer (int n)
{
  char s[200];

  /*static char rs[20] = "long"; */
  /*int a; */

  A4GL_debug ("rettype_integer : %d\n", n);

  SPRINTF1 (s, "%d", n);
  return local_rettype (s);
}
#endif


#ifdef NOT_NEEDED
char *
irettype_integer (char *s, int n)
{
  static char buff[256];
  if (strlen (s) && 0)
    {
      sprintf (buff, "LIKE %s", s);
      return buff;
    }
  return local_rettype_integer (n);
}
#endif


void dump_comments (int n)
{
  char *ptr;
  char type;
  int printed = 0;
  char buff[20];
  int in_multi = 0;
  int nd = 0;

  while (1)
    {
      //printc("n=%d\n",n);

      ptr = local_has_comment (n, 0, &type);

      if (in_multi && ptr == 0)
	{
	  n += 2;
	  ptr = local_has_comment (n, 0, &type);
	}
      A4GL_assertion (ptr == 0 && in_multi, "Didn't read next line of multiline comment");
      if (ptr == 0)

	return;


      if (nd == 0)
	{
	  nd++;
	  need_daylight ();
	}
      //if (!printed) {
      switch (type)
	{
	case '-':
	  strcpy (buff, "//");
	  break;
	case '{':
	  strcpy (buff, "/*");
	  in_multi++;
	  break;
	case '}':
	  strcpy (buff, "*/");
	  in_multi--;
	  break;
	case '#':
	  strcpy (buff, "//");
	  break;
	case '.':
	  strcpy (buff, "");
	  break;
	default:
	  sprintf (buff, "// (%c)", type);
	  break;
	}
      //}


      printed++;
      if (strlen (ptr) > 1 && buff[0] == '{')
	{
	  char *p;
	  p = strdup (ptr);
	  //A4GL_lrtrim(p);
	  //printc ("#");
	  if (outfile)
	    FPRINTF (outfile, "{\n");
	  //printc ( "{\n", buff,p);
	  free (p);
	}
      else
	{
	  char *p;
	  //int c;
	  p = strdup (ptr);

	  //A4GL_lrtrim(p);
	  /*
	     if (strcmp(buff,"#")==0) {
	     strcpy(buff,"# ");
	     }
	     if (type=='.' && strlen(p)==0) { // Blank link...
	     strcpy(buff,"#");
	     }
	   */


	  if (outfile)
	    FPRINTF (outfile, "%s%s\n", buff, p);

	  //printc ("%s%s", buff, p, strlen(buff),buff[0]);
	  free (p);
	}
    }
}



char *
local_expr_as_string (expr_str * ptr)
{
  static char buff[2067];
  char *ptr1;
  char *ptr2;
  switch (ptr->expr_type)
    {
    case ET_EXPR_LITERAL_LONG:
      sprintf (buff, "%ld", ptr->expr_str_u.expr_long);
      return buff;

    case ET_EXPR_IDENTIFIER:
    case ET_E_V_OR_LIT_STRING:

      return ptr->expr_str_u.expr_string;

    case ET_EXPR_BRACKET:
      {
	char buff2[2000];
	sprintf (buff2, "(%s)", local_expr_as_string (ptr->expr_str_u.expr_expr));
	strcpy (buff, buff2);
	return buff;
      }

    case ET_EXPR_TRUE:
      return "true";

    case ET_EXPR_FALSE:
      return "true";

    case ET_EXPR_LITERAL_STRING:
      {
	char buff2[2000];
	sprintf (buff2, "%s", escape_quotes_and_remove_nl (ptr->expr_str_u.expr_string, 0));
	strcpy (buff, buff2);
	return buff;
      }

    case ET_EXPR_OP_ADD:
		
      	if (isCharExpr( ptr->expr_str_u.expr_op->left)) { ensure_dtype(0,0,ptr->expr_str_u.expr_op->left, DTYPE_FLOAT,1); }
      	if (isCharExpr( ptr->expr_str_u.expr_op->right)) { ensure_dtype(0,0,ptr->expr_str_u.expr_op->right, DTYPE_FLOAT,1); }

      		ptr1 = strdup (local_expr_as_string (ptr->expr_str_u.expr_op->left));
      		ptr2 = strdup (local_expr_as_string (ptr->expr_str_u.expr_op->right));
      		sprintf (buff, "(%s+%s)", ptr1, ptr2);
	
	
      free (ptr1);
      free (ptr2);
      return buff;

    case ET_EXPR_OP_SUB:
      ptr1 = strdup (local_expr_as_string (ptr->expr_str_u.expr_op->left));
      ptr2 = strdup (local_expr_as_string (ptr->expr_str_u.expr_op->right));
      sprintf (buff, "(%s-%s)", ptr1, ptr2);
      free (ptr1);
      free (ptr2);
      return buff;
    case ET_EXPR_OP_MULT:
      ptr1 = strdup (local_expr_as_string (ptr->expr_str_u.expr_op->left));
      ptr2 = strdup (local_expr_as_string (ptr->expr_str_u.expr_op->right));
      sprintf (buff, "(%s*%s)", ptr1, ptr2);
      free (ptr1);
      free (ptr2);
      return buff;

    case ET_EXPR_OP_DIV:
      ptr1 = strdup (local_expr_as_string (ptr->expr_str_u.expr_op->left));
      ptr2 = strdup (local_expr_as_string (ptr->expr_str_u.expr_op->right));
      sprintf (buff, "(%s/%s)", ptr1, ptr2);
      free (ptr1);
      free (ptr2);
      return buff;

    case ET_EXPR_OP_MOD:
      ptr1 = strdup (local_expr_as_string (ptr->expr_str_u.expr_op->left));
      ptr2 = strdup (local_expr_as_string (ptr->expr_str_u.expr_op->right));
      sprintf (buff, "(%s MOD %s)", ptr1, ptr2);
      free (ptr1);
      free (ptr2);
      return buff;

    case ET_EXPR_CAST:
      {
	char b2[1000];
	strcpy (b2, local_expr_as_string (ptr->expr_str_u.expr_cast->expr));
	sprintf (buff, "%s", b2);
	return buff;
      }

    case ET_EXPR_VARIABLE_USAGE:
      sprintf (buff, "$%s", generation_get_variable_usage_as_string (ptr->expr_str_u.expr_variable_usage));
      //printf ("-->%s\n", buff);
      return buff;



    default:
      printf ("Unhandled array subscript expression --->%d %s\n", ptr->expr_type, expr_name (ptr->expr_type));
      A4GL_assertion (1, "Unhandled array subscript expression");

    }
  return "";
}


/*
static void
A4GL_warn (char *s)
{
  if (!A4GL_isyes (acl_getenv ("SUPPRESSWARNINGS")))
    {
      fprintf (stderr, "Warning : %s @ line %d\n", s, yylineno);
    }
}
*/

/*
static void
A4GL_lint (char *s)
{
  if (!A4GL_isyes (acl_getenv ("SUPPRESSLINT")))
    {
      fprintf (stderr, "LINT Warning : %s @ line %d\n", s, yylineno);
    }
}
*/



char *
local_has_comment (int n, int c, char *type)
{
  int a;
  for (a = 0; a < curr_module->comment_list.comment_list_len; a++)
    {
      if (curr_module->comment_list.comment_list_val[a].printed)
	continue;

      if (curr_module->comment_list.comment_list_val[a].lineno < n)
	{
	  curr_module->comment_list.comment_list_val[a].printed++;
	  *type = curr_module->comment_list.comment_list_val[a].type;
	  return curr_module->comment_list.comment_list_val[a].comment;
	}
      if (curr_module->comment_list.comment_list_val[a].lineno == n && c < curr_module->comment_list.comment_list_val[a].colno)
	{
	  *type = curr_module->comment_list.comment_list_val[a].type;
	  curr_module->comment_list.comment_list_val[a].printed++;
	  return curr_module->comment_list.comment_list_val[a].comment;
	}
    }
  return 0;
}


struct variable *
find_var (char *s)
{
  int a;
  char buff1[2000];
  char *ptr;
  strcpy (buff1, s);
  ptr = strchr (buff1, '[');
  if (ptr)
    {
      *ptr = 0;
    }
  ptr = strchr (buff1, '.');
  if (ptr)
    {
      *ptr = 0;
    }

  if (current_func)
    {
      for (a = 0; a < current_func->variables.variables.variables_len; a++)
	{
	  if (strcmp (buff1, current_func->variables.variables.variables_val[a]->names.names.names_val[0].name) == 0)
	    {			// Found it...
	      return current_func->variables.variables.variables_val[a];
	    }
	}
    }


  for (a = 0; a < curr_module->imported_global_variables.variables.variables.variables_len; a++)
    {
      if (strcmp (buff1, curr_module->imported_global_variables.variables.variables.variables_val[a]->names.names.names_val[0].name) == 0)
	{			// Found it...
	  return curr_module->imported_global_variables.variables.variables.variables_val[a];
	}
    }

  for (a = 0; a < curr_module->module_variables.variables.variables.variables_len; a++)
    {
      if (strcmp (buff1, curr_module->module_variables.variables.variables.variables_val[a]->names.names.names_val[0].name) == 0)
	{			// Found it...
	  return curr_module->module_variables.variables.variables.variables_val[a];
	}
    }

  return 0;
}


static void
module_var_binding (struct expr_str_list *l, int stage)
{
  int a;
  int n = 0;

  if (!A4GL_isyes (acl_getenv ("REMOVEMODVARS")))
    {
      return;
    }
  if (l == 0)
    return;


  if (stage == COPY_DATA_FROM_MODVARS_INTO_TMPS)
    {
      for (a = 0; a < l->list.list_len; a++)
	{
	  if (tolower (get_var_expr_scope (l->list.list_val[a])) == 'm')
	    {
	      if (n == 0)
		printc ("#");
	      n++;
	      printh ("#REQUIRETEMP %s lv_tmpi_%x_%d %d\n", currfuncname, get_binding_dtype (l->list.list_val[a]), a,
		      get_binding_dtype (l->list.list_val[a]));
	      printc ("LET lv_tmpi_%x_%d=%s", get_binding_dtype (l->list.list_val[a]), a,
		      decode_varbind (l->list.list_val[a], 'R', a));
	    }
	}
    }

  if (stage == COPY_DATA_FROM_TMPS_INTO_MODVARS)
    {
      for (a = 0; a < l->list.list_len; a++)
	{
	  if (tolower (get_var_expr_scope (l->list.list_val[a])) == 'm')
	    {
	      if (n == 0)
		{
		  printc ("#");
		  n++;
		}
	      printh ("#REQUIRETEMP %s lv_tmpo_%x_%d %d\n", currfuncname, get_binding_dtype (l->list.list_val[a]), a,
		      get_binding_dtype (l->list.list_val[a]));
	      printc ("CALL %s lv_tmpo_%x_%d)", decode_varbind (l->list.list_val[a], 'W', a),
		      get_binding_dtype (l->list.list_val[a]), a);
	    }
	}
    }

}


struct def
{
  char *vname;
  int dtype;
  char *str;
};

struct extra_defines
{
  char *function;
  struct def *define_lines;
  int ndefine_lines;
};

struct extra_defines *funcs = 0;
int nfuncs = 0;

static int
ensure_func (char *s)
{
  int a;
  if (nfuncs != 0)
    {
      for (a = 0; a < nfuncs; a++)
	{
	  if (strcmp (funcs[a].function, s) == 0)
	    return a;
	}
    }
  nfuncs++;
  funcs = realloc (funcs, sizeof (struct extra_defines) * nfuncs);
  funcs[nfuncs - 1].function = strdup (s);
  funcs[nfuncs - 1].define_lines = 0;
  funcs[nfuncs - 1].ndefine_lines = 0;
  return nfuncs - 1;
}


#ifdef OLD
static void
add_vname (char *f, char *v, int dtype)
{
  int a;
  int cnt;
  char buff[256];
  char buff_dtype[256];
  int dtype_sz;
  a = ensure_func (f);
  for (cnt = 0; cnt < funcs[a].ndefine_lines; cnt++)
    {
      if (strcmp (funcs[a].define_lines[cnt].vname, v) == 0)
	return;			// already there...
    }
  funcs[a].ndefine_lines++;
  funcs[a].define_lines = realloc (funcs[a].define_lines, sizeof (struct def) * funcs[a].ndefine_lines);
  funcs[a].define_lines[funcs[a].ndefine_lines - 1].vname = strdup (v);
  funcs[a].define_lines[funcs[a].ndefine_lines - 1].dtype = dtype;

  dtype_sz = dtype >> 16;
  dtype = dtype & 0xffff;
  switch (dtype)
    {
    case DTYPE_CHAR:
      sprintf (buff_dtype, "string");
      break;
    case DTYPE_VCHAR:
      sprintf (buff_dtype, "varchar");
      break;
    case DTYPE_INT:
      sprintf (buff_dtype, "int");
      break;
    case DTYPE_SMINT:
      sprintf (buff_dtype, "int");
      break;
    case DTYPE_DATE:
      sprintf (buff_dtype, "Ifxdate");
      break;
    case DTYPE_FLOAT:
      sprintf (buff_dtype, "double");
      break;
    case DTYPE_SMFLOAT:
      sprintf (buff_dtype, "float");
      break;


    case DTYPE_DECIMAL:
      sprintf (buff_dtype, " CMDecimal%d%d", dtype_sz >> 8, dtype_sz & 255);
      break;

    case DTYPE_DTIME:
      sprintf (buff_dtype, " IfxDateTime%sTO%s", decode_dt (dtype_sz, 1), decode_dt (dtype_sz, 2));
      break;

    case DTYPE_INTERVAL:
      sprintf (buff_dtype, " IfxInterval%sTO%s", decode_ival_define1 (dtype_sz), decode_ival_define2 (dtype_sz));
      break;


    default:
      printf ("Unhandled define in module variable removal... variable dtype : %d (%x)\n", dtype, dtype);
      A4GL_assertion (1, "Unhandled define in module variable removal...");

    }
  sprintf (buff, "%s %s;", buff_dtype, v);
  funcs[a].define_lines[funcs[a].ndefine_lines - 1].str = strdup (buff);

}
#endif


static void
merge_files (void)
{
  FILE *h;
  FILE *c;
  char buff[10010];
  char fname[200];
  char vname[200];
  int vtype;
  char *baseClass = 0;
  char *thisNamespace = 0;


  if (A4GL_isyes (acl_getenv ("A4GL_NOCFILE")))
    {
      A4GL_debug (">>> NO C FILES... ");
      return;
    }


  A4GL_assertion (strlen (filename_cfile) == 0, "No cfile defined");
  A4GL_assertion (strlen (filename_hfile) == 0, "No hfile defined");
  A4GL_assertion (strlen (filename_outfile) == 0, "No outfile defined");
  c = fopen (filename_cfile, "r");
  h = fopen (filename_hfile, "r");
  unlink (filename_outfile);
  final_o = fopen (filename_outfile, "wb");
  if (c == 0)
    {
      printf ("Can't open %s\n", filename_cfile);
      exit (1);
    }

  if (h == 0)
    {
      printf ("Can't open %s\n", filename_hfile);
      exit (1);
    }

  if (final_o == 0)
    {
      printf ("Can't open %s\n", filename_outfile);
      exit (1);
    }


      fprintf (final_o, "<?php\n");
      //fprintf (final_o, "using System.Collections;\n");
      //fprintf (final_o, "using System.Collections.Generic;\n");
      //fprintf (final_o, "using IBM.Data.Informix;\n");
      //fprintf (final_o, "using CM.Informix.Library;\n");
      //fprintf (final_o, "using CM.Informix.Library.UI;\n");
    


  thisNamespace = acl_getenv_not_set_as_0 ("NAMESPACE");


  while (1)
    {
      fgets (buff, 10000, h);
      if (feof (h))
	break;
      A4GL_trim (buff);
      if (A4GL_strstartswith (buff, "#REQUIRETEMP "))
	{
	  // Add this to our define list...
	  sscanf (buff, "#REQUIRETEMP %s %s %d", fname, vname, &vtype);
	  printf ("%s %s %d\n", fname, vname, vtype);
	  ensure_func (fname);
	  add_vname (fname, vname, vtype);
	}
      else
	{
	  if (final_o)
	    FPRINTF (final_o, "%s\n", buff);
	}
    }
  fclose (h);
  unlink (filename_hfile);

  while (1)
    {
      fgets (buff, 10000, c);
      if (feof (c))
	break;
      A4GL_trim (buff);

      if (A4GL_strstartswith (buff, "#!!FUNCTION "))
	{
	  int a;
	  char *p;
	  char *c1;
	  char *c2;
	  int cnt;
	  p = strdup (buff);
	  c1 = strchr (p, ' ');
	  c1++;			// now points to function name
	  c2 = strchr (p, '(');
	  if (c2)
	    {
	      *c2 = 0;
	    }
	  A4GL_trim (c1);
	  a = ensure_func (c1);
	  if (A4GL_isyes (acl_getenv ("REMOVEMODVARS")))
	    {
	      if (final_o)
		FPRINTF (final_o, "###################################################################\n");
	      if (final_o)
		FPRINTF (final_o, "# LOCAL VARIABLES DEFINED AS TEMPORARY MODULE VARIABLE REPLACEMENTS\n");
	      if (final_o)
		FPRINTF (final_o, "###################################################################\n");
	    }
	  for (cnt = 0; cnt < funcs[a].ndefine_lines; cnt++)
	    {

	      if (final_o)
		FPRINTF (final_o, "  %s\n", funcs[a].define_lines[cnt].str);
	    }
	  if (A4GL_isyes (acl_getenv ("REMOVEMODVARS")))
	    {
	      if (final_o)
		FPRINTF (final_o, "###################################################################\n");
	      if (final_o)
		FPRINTF (final_o, "# END OF TEMPORARY MODULE VARIABLE REPLACEMENTS\n");
	      if (final_o)
		FPRINTF (final_o, "###################################################################\n");
	    }
	  continue;
	}

      if (final_o)
	FPRINTF (final_o, "%s\n", buff);

    }

  fclose (c);
  unlink (filename_cfile);
  fclose (final_o);

}







int
LEXLIB_LEX_initlib (void)
{
  int a;
  char *fname;
  return 1;
}






int
hasDeclare (char *s)
{
  int a;
  if (strcmp (s, "c_oktd") == 0)
    {
      A4GL_pause_execution ();
    }

  for (a = 0; a < nDeclares; a++)
    {
      if (strcmp (s, Declares[a].ident) == 0)
	{
	  // found it
	  return a;
	}

    }
  printf ("%s not found as a cursor\n", s);
  return -1;
}

int
addDeclare (char *s, struct expr_str_list *inbind, struct expr_str_list *outbind, int type)
{
  nDeclares++;
  if (strcmp (s, "c_oktd") == 0)
    {
      A4GL_pause_execution ();
    }
  Declares = realloc (Declares, sizeof (struct sDeclares) * nDeclares);
  strcpy (Declares[nDeclares - 1].ident, s);
  Declares[nDeclares - 1].inbind = inbind;
  Declares[nDeclares - 1].outbind = outbind;

  Declares[nDeclares - 1].type = type;

  if (Declares[nDeclares - 1].inbind)
    {
      if (Declares[nDeclares - 1].inbind->list.list_len == 0)
	{
	  Declares[nDeclares - 1].inbind = 0;
	}
    }


  if (Declares[nDeclares - 1].outbind)
    {
      if (Declares[nDeclares - 1].outbind->list.list_len == 0)
	{
	  Declares[nDeclares - 1].outbind = 0;
	}
    }


  return 1;
}

/********************************************************************************/
static int
find_function (char *s)
{
  int a;

  for (a = 0; a < curr_module->module_entries.module_entries_len; a++)
    {
      struct module_entry *m;
      m = curr_module->module_entries.module_entries_val[a];
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


static int
system_function_dtype (char *funcname)
{

  int a;
  a = is_bolton_function (funcname);
  if (a != -1)
    {
      return get_bolton_rtype (a, 0);
    }

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
  if (A4GL_aubit_strcasecmp (funcname, "startlog") == 0)
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
  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_set_application_xml") == 0)
    return -1;
  if (A4GL_aubit_strcasecmp (funcname, "fgl_settitle") == 0)
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
  if (A4GL_aubit_strcasecmp (funcname, "lastkeypress") == 0)
    return DTYPE_INT;

  if (A4GL_aubit_strcasecmp (funcname, "aclfgl_sendfile_to_ui") == 0)
    return DTYPE_INT;


  if (A4GL_aubit_strcasecmp (funcname, "winexec") == 0)
    return DTYPE_SMINT;


  if (A4GL_aubit_strcasecmp (funcname, "mdy") == 0)
    return DTYPE_DATE;
  if (A4GL_aubit_strcasecmp (funcname, "return_wfproc_date") == 0)
    return DTYPE_DATE;

  if (A4GL_aubit_strcasecmp (funcname, "a4gl_get_info") == 0)
    return DTYPE_CHAR;
  if (A4GL_aubit_strcasecmp (funcname, "a4gl_get_page") == 0)
    return DTYPE_CHAR;
  if (A4GL_aubit_strcasecmp (funcname, "a4gl_get_ui_mode") == 0)
    return DTYPE_CHAR;
  if (A4GL_aubit_strcasecmp (funcname, "arg_val") == 0)
    return DTYPE_CHAR;
  if (A4GL_aubit_strcasecmp (funcname, "get_envvar") == 0)
    return DTYPE_CHAR;
  if (A4GL_aubit_strcasecmp (funcname, "bmktemp") == 0)
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



static int uses_exit_case (struct s_commands *cmds)
{
  struct s_commands *f_cmds;
  struct command *r;
  int a;
  f_cmds = linearise_commands (0, 0);
  linearise_commands (f_cmds, cmds);

  for (a = 0; a < f_cmds->cmds.cmds_len; a++)
    {
      r = f_cmds->cmds.cmds_val[a];
      if (r->cmd_data.command_data_u.continue_cmd.what == EBC_CASE)
	return 1;
    }

  return 0;
}


static int
uses_loop (struct s_commands *cmds, char type, int blockid)
{
  struct s_commands *f_cmds;
  struct command *r;
  int a;
  f_cmds = linearise_commands (0, 0);
  linearise_commands (f_cmds, cmds);

  for (a = 0; a < f_cmds->cmds.cmds_len; a++)
    {
      r = f_cmds->cmds.cmds_val[a];
      if (r->cmd_data.type == E_CMD_CONTINUE_CMD && type == 'C')
	{
	  if (r->cmd_data.command_data_u.continue_cmd.block_id == blockid)
	    return 1;
	}
      if (r->cmd_data.type == E_CMD_EXT_CMD && type == 'E')
	{
	  if (r->cmd_data.command_data_u.ext_cmd.block_id == blockid)
	    return 1;
	}
    }

  return 0;
}


static void
ensure_parameters (char *fname, struct expr_str_list *parameters)
{
  int e;
  struct s_function_definition *function_definition;
  int a;
  expr_str_list *function_parameters;

return;
  a = is_bolton_function (fname);

  if (a != -1)
    {
      int nparam;
      int c;
      nparam = get_bolton_nparam (a);
	// If the prototype has the parameter of just '-1' - just ignore the whole thing
	// its being implemented as a C# function with overloading
	// to handled the required datatypes..
	if (nparam==1 && get_bolton_param(a,0)==-1) {
		return;
	}

	if (parameters) {
		if (parameters->list.list_len>nparam) {
		  	printc("/* FGLCHECK:  Too many parameters %d > %d */", parameters->list.list_len,nparam);
		 	parameters->list.list_len=nparam;
		}
	} else {
		if (nparam) {
			a4gl_yyerror("Function is expecting parameters - and none have been passed at all");
			return;
		}
	}

      for (c = 0; c < nparam; c++)
	{
	  ensure_dtype (" ", 0, parameters->list.list_val[c], get_bolton_param (a, c), 0);
	}
      return;
    }



  if (system_function (fname))
    {
      // @TODO - ensure the datatypes of parameters
      // to builtin functions...
      return;
    }



  e = find_function (fname);
  if (e < 0)
    {
      printf ("Cant find function : %s\n", fname);
      return;
    }

  if (parameters == 0)
    return;

  function_definition = &curr_module->module_entries.module_entries_val[e]->module_entry_u.function_definition;
  function_parameters = expand_parameters (&function_definition->variables, function_definition->parameters);


  if (function_parameters->list.list_len != parameters->list.list_len)
    {
      a4gl_yyerror ("Incorrect number of parameters..");
      return;
    }

  for (a = 0; a < parameters->list.list_len; a++)
    {

      ensure_dtype (" ", 0, parameters->list.list_val[a], get_binding_dtype (function_parameters->list.list_val[a]), 0);
    }
}

int
find_function_single_rtype (char *funcname)
{

  int e;
  struct s_commands *func_cmds;
  struct command *r;
  struct s_function_definition *function_definition;
  int a;
  int dtype;

  if (system_function (funcname))
    {
      return system_function_dtype (funcname);
    }

  a = is_bolton_function (funcname);
  if (a != -1)
    {
      if (get_bolton_nrets (a) == 1)
	{
	  return get_bolton_rtype (a, 0);
	}
      else
	{
	  printf ("Unexpected number of return values for function %s - expecting 1\n", funcname);
	  return DTYPE_INT;
	}
    }


  e = find_function (funcname);
  if (e < 0)
    {
      printf ("find_function_single_rtype->%s\n", funcname);
      return 91;
    }
  function_definition = &curr_module->module_entries.module_entries_val[e]->module_entry_u.function_definition;
  func_cmds = linearise_commands (0, 0);
  linearise_commands (func_cmds, function_definition->func_commands);
  nreturns = 0;
  for (a = 0; a < func_cmds->cmds.cmds_len; a++)
    {
      r = func_cmds->cmds.cmds_val[a];

      if (r->cmd_data.type == E_CMD_RETURN_CMD)
	{

	  if (r->cmd_data.command_data_u.return_cmd.retvals)
	    {
	      //int b;
	      nreturns = r->cmd_data.command_data_u.return_cmd.retvals->list.list_len;

	      if (nreturns != 1)
		{
		  printf ("Unexpected number of return values for function %s - expecting 1\n", funcname);
		  return DTYPE_INT;
		}

	      dtype = expr_datatype (0, 0, r->cmd_data.command_data_u.return_cmd.retvals->list.list_val[0]);
	      //if (dtype == 90)
		//{
		  //dtype = DTYPE_INT;
		//}
	      return dtype;
	    }

	  break;
	}
    }



  return 91;

}










void
LEXLIB_A4GL_initlex (void)
{



}


void
print_prepare_cmd (struct_prepare_cmd * p)
{
  //fprintf (hfile, "   private IfxPrepare Statement_%s;\n", A4GL_strip_quotes (get_ident (p->stmtid,1)));
  print_when_sql_start ();
  set_nonewlines ();
  printc ("$Statement_%s=BuildSQLPrepare(", A4GL_strip_quotes (get_ident (p->stmtid,1)));
  real_print_expr (p->sql);
  printc (");");
  clr_nonewlines ();
  print_when_sql_end ();
}


static void
print_nullify (char type, variable_list * v)
{
int a;
  if (v->variables.variables_len == 0)
    return;

  if (v->variables.variables_val == 0)
    return;

  for (a = 0; a < v->variables.variables_len; a++)
    {
      char *name;
        name = v->variables.variables_val[a]->names.names.names_val[0].name;
/*
	if (v->variables.variables_val[a]->assigned==0 && v->variables.variables_val[a]->usage==0 && type==E_SCOPE_MODULE) {
		continue;
        }
	if (v->variables.variables_val[a]->assigned==0 && v->variables.variables_val[a]->usage==0 && type=='F') {
		continue;
        }
*/

	  print_init_var (v->variables.variables_val[a], "", 0, 0, 0, 1, 1);

    }

}

static void
print_function_variable_init (variable_list * fvars)
{
  printc ("#");
  printc ("%s", initModVariables);
  print_nullify ('F', fvars);
}


static char * cleaned_name (char *s)
{
  static char buff[2000];
  int b = 0;
  int a;
  char *ptr;
  ptr = strrchr (s, '/');
  if (ptr)
    s = ptr + 1;

  for (a = 0; a < strlen (s); a++)
    {
      if (s[a] >= 'a' && s[a] <= 'z')
	{
	  buff[b++] = s[a];
	  continue;
	}
      if (s[a] >= '0' && s[a] <= '9')
	{
	  buff[b++] = s[a];
	  continue;
	}
      if (s[a] >= 'A' && s[a] <= 'Z')
	{
	  buff[b++] = s[a];
	  continue;
	}
    }
  buff[b] = 0;
  return buff;
}


static void
print_module_variable_init (variable_list * mvars)
{
  char cleanedName[2000];
  int a;
  char buff1[2000];
  char buff2[2000];

  set_suppress_lines ("print_module_variable_init");

  printc ("#");

  if (curr_module->moduleIsInLibrary) {
  	sprintf (cleanedName,"F%s", cleaned_name (curr_module->module_name));
  } else {
  	strcpy (cleanedName, cleaned_name (curr_module->module_name));
  }

  if (mvars->variables.variables_len==0) {
		strcpy(initModVariables,"");
		return;
  }

  printc ("$Done_init_module_variables_%s=0;\n",  cleanedName);
  printc ("#");
  printc ("function Init_module_variables_%s() {", cleanedName);
  tmp_ccnt++;
  printc ("if ($Done_init_module_variables_%s) {return;}",  cleanedName);
  printc ("$Done_init_module_variables_%s=1;",  cleanedName);
  //setting_module_to_null = 1;
  //print_nullify ('M')
  print_nullify (E_SCOPE_MODULE, mvars);
  tmp_ccnt--;
  printc ("}");
  printc ("\n");
  printc ("#");
  sprintf (initModVariables, "init_module_variables_%s();", cleanedName);
  clr_suppress_lines ();
}







static int print_insert_cmd (struct_insert_cmd * cmd_data)
{

  //char *ptr;
  //int c;
  int converted;

  printc ("\"%s\"", escape_quotes_and_remove_nl (get_insert_cmd (cmd_data, &converted), 1));


  return 1;
}
static void print_goto_comment(void) {
static int gc=0;
if (gc) return;
gc++;
printc("// GOTO is only available with PHP 5.3");
}

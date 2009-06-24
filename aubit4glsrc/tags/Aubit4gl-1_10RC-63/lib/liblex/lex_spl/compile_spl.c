#include "a4gl_libaubit4gl.h"
#include "a4gl_API_lex_lib.h"
#include "compile_spl.h"
#include "ctype.h"
#include "a4gl_expr.h"
#include "./common.h"

// DEFINES
//

#define LIST_BLACKLIST 1
#define LIST_WHITELIST 2

#define COPY_DATA_FROM_MODVARS_INTO_TMPS 1
#define COPY_DATA_FROM_TMPS_INTO_MODVARS 3

#define CONTEXT_INPUT 0
#define CONTEXT_MENU 1
#define CONTEXT_CONSTRUCT 2
#define CONTEXT_PROMPT 3
#define FAKE_DTYPE_BOOL 90

#define MAX_RETURN_VALUES 256

int xps = 0;


char *record_headers[100];

struct variable_usage *usage_bottom_level (variable_usage * u);	// parsehelp.c
struct commands *linearise_commands (struct commands *master_list, struct commands *cmds);
expr_str_list *expand_parameters (struct variable_list *var_list, expr_str_list * parameters);
char *current_stmt_table = 0;
struct expr_str *input_array_variable = 0;
void not_in_spl (void);
extern int yylineno;
static int loop_descent_level = 0;


/* STRUCTURES */
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

int printing_expr = 0;

/* VARIABLES */
struct module_definition *curr_module;
int tmp_ccnt = 0;
char *ofilename = "";
static FILE *outfile = 0;
static FILE *hfile = 0;	/** Pointer to the output header (.h) file */
char filename_hfile[256] = "";
char filename_cfile[256] = "";
char filename_outfile[256] = "";
FILE *final_o;
char cmodname[256] = "";
char clobber[256];
int nonewlines = 0;
int curr_yylineno = 0;
struct module_entry *current_entry = 0;
int when_set_to_call = 0;
struct extra_defines *funcs = 0;
int nfuncs = 0;
char last_context[10][200] = { "", "", "", "", "", "", "", "", "", "" };
struct command *command_nest[2000];
int command_nest_cnt = 0;
int use_input_array_star = 0;
char input_list[20000];
int nblacklist = 0;
char **blacklist = 0;
int nwhitelist = 0;
char **whitelist = 0;
int doing_input_array = 0;

// External ...
char *make_sql_string_and_free (char *first, ...);

/* STATIC FUNCTIONS PROTOTYPES */
static void open_outfile (void);
static void print_variable_new (struct variable *v, enum e_scope scope, int level);
static char *decode_dt (int a, int b);
static char *decode_ival_define1 (int n);
static char *decode_ival_define2 (int n);
static void print_varbind (expr_str * var_usage, char dir, int no);
static char *local_has_comment (int n, int c, char *type);
static int dump_report (struct s_report_definition *report_definition);
static int dump_cmds (struct commands *c, struct command *parent);
static int dump_pdf_report (struct s_pdf_report_definition *pdf_report_definition);
static int dump_cmd (struct command *r, struct command *parent);
static int dump_function (struct s_function_definition *function_definition, int ismain);
static char get_var_expr_scope (struct expr_str *p);
static int get_var_expr_dtype (struct expr_str *p);
static int print_whenever_style (int code, char *whento);
static void printc_safe_to_split_at_comma (char *fmt, ...);
static void print_attributes (attrib * x);
static char *attributes_as_string (attrib * x);
static char *get_attributes_as_string (attrib * x);
static struct expr_str_list *A4GL_rationalize_list_concat (struct expr_str_list *l);
static void real_print_field_list_with_separator (struct fh_field_list *fl, char *sep);
static void A4GL_warn (char *s);
static void print_events (on_events * es, struct command *parent);
static int has_before_menu (on_events * es);
static void real_print_expr (struct expr_str *ptr);
static void local_a4gl_yyerror (char *s);
static void print_connid (struct expr_str *e);
static void print_options (char n, char *s, struct expr_str *expr);
static void real_print_binding_with_separator (expr_str_list * s, char read_or_write, char *sep);
static void real_print_expr_list_with_separator (struct expr_str_list *l, char *s);
static void print_var_usage (struct variable_usage *var_usage, char dir, int no);
static char *local_get_expr_as_string (struct expr_str *ptr);
static char *get_variable_usage (struct variable_usage *var_usage);
static char *local_get_expr_as_string_list_with_separator (struct expr_str_list *l, char *sep);
static void search_variables (struct s_select_list_item_list *l);
static char *xfield_name_as_char (struct fh_field_entry *f);
static char *local_field_name_as_char (char *fname, expr_str * sub);
static void print_input_array (struct expr_str *arrvar, int helpno, int defs, struct expr_str *srec, attrib * attrib, char *slice);
static char *xfield_name_list_as_char (struct fh_field_list *fl);


/* These functions are for whitelist/blacklist handling of functions - in normal usage - they are not normally required ;-) */
static void load_blacklist (void);
static void load_blacklist_from (char *ptr);
static int is_on_list (int list, char *s);
static void add_to_list (int list, char *s);
static char *get_orig_from_clobber (char *s);



/******************************************************************/
/*                            FUNCTIONS                           */
/******************************************************************/
char *
map_fname (char *s)
{
  return s;
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
	  set_yytext (get_variable_usage_as_string (u));
	  a4gl_yyerror ("Invalid variable usage");
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
	  set_yytext (get_variable_usage_as_string (u));
	  a4gl_yyerror ("Invalid variable usage");
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


static char *
get_currfuncname (void)
{
  if (current_entry)
    {
      switch (current_entry->met_type)
	{
	case E_MET_REPORT_DEFINITION:
	  return current_entry->module_entry_u.report_definition.funcname;
	  break;
	case E_MET_PDF_REPORT_DEFINITION:
	  return current_entry->module_entry_u.pdf_report_definition.funcname;
	  break;
	case E_MET_CMD:
	  A4GL_assertion (1, "Shouldn't happen");
	  break;
	case E_MET_MAIN_DEFINITION:
	  return "MAIN";
	  break;
	case E_MET_FUNCTION_DEFINITION:
	  return current_entry->module_entry_u.function_definition.funcname;
	  break;
	default:
	  return "NotSet";

	}
    }
  return "NotSet";

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
  ccnt = tmp_ccnt;
  memset (buff, ' ', 255);
  buff[ccnt * 4] = 0;
  if (outfile)
    FPRINTF (outfile, "%s", buff);
}



static void
set_nonewlines (void)
{
  if (nonewlines == 0)
    {
      print_space ();
    }
  nonewlines++;

}

static void
clr_nonewlines (void)
{
  nonewlines--;
  if (nonewlines == 0)
    {
      printc ("#");
      daylight = 0;
    }
}



static void
need_daylight (void)
{
  if (daylight)
    return;
  printc ("#");

}

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
      sprintf (buff_dtype, "CHAR(%d)", dtype_sz);
      break;
    case DTYPE_VCHAR:
      sprintf (buff_dtype, "VARCHAR(%d)", dtype_sz);
      break;
    case DTYPE_INT:
      sprintf (buff_dtype, "INTEGER");
      break;
    case DTYPE_SMINT:
      sprintf (buff_dtype, "SMALLINT");
      break;
    case DTYPE_DATE:
      sprintf (buff_dtype, "DATE");
      break;
    case DTYPE_FLOAT:
      sprintf (buff_dtype, "FLOAT");
      break;
    case DTYPE_SMFLOAT:
      sprintf (buff_dtype, "SMALLFLOAT");
      break;

    case DTYPE_DECIMAL:
      sprintf (buff_dtype, " DECIMAL(%d,%d)", dtype_sz >> 8, dtype_sz & 255);
      break;

    case DTYPE_DTIME:
      sprintf (buff_dtype, " DATETIME %s TO %s", decode_dt (dtype_sz, 1), decode_dt (dtype_sz, 2));
      break;

    case DTYPE_INTERVAL:
      sprintf (buff_dtype, " INTERVAL %s TO %s", decode_ival_define1 (dtype_sz), decode_ival_define2 (dtype_sz));
      break;


    default:
      printf ("Unhandled define in module variable removal... variable dtype : %d (%x)\n", dtype, dtype);
      A4GL_assertion (1, "Unhandled define in module variable removal...");

    }
  sprintf (buff, "DEFINE %-16s %s;", v, buff_dtype);
  funcs[a].define_lines[funcs[a].ndefine_lines - 1].str = strdup (buff);

}


static void
tmp_ccntminus (void)
{
  tmp_ccnt--;
  if (tmp_ccnt < 0)
    {
      A4GL_assertion (1, "tmp_ccnt<0");
    }

}


static void
A4GL_set_clobber (char *s)
{
  strcpy (clobber, s);
}

static void
A4GL_internal_lex_printc (char *fmt, va_list * ap)
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
      fprintf (stderr, "Internal error - string too big\n");
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
	      if (outfile)
		FPRINTF (outfile, "%s", ptr);

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

static void
merge_files (void)
{
  FILE *h;
  FILE *c;
  char buff[2000];
  char fname[200];
  char vname[200];
  int vtype;


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
  while (1)
    {
      fgets (buff, 1000, h);
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
      fgets (buff, 1000, c);
      if (feof (c))
	break;
      A4GL_trim (buff);

      if (final_o)
	FPRINTF (final_o, "%s\n", buff);

    }

  fclose (c);
  unlink (filename_cfile);
  fclose (final_o);

}





static void
printc_safe_to_split_at_comma (char *fmt, ...)
{
  int a;
  va_list ap;
  va_start (ap, fmt);
  static char buff[40960] = "ERROR-empty init";
  char *ptr;
  int inquote = 0;
  int l;
  va_start (ap, fmt);
  vsnprintf (buff, sizeof (buff), fmt, ap);
  set_nonewlines ();
  ptr = buff;
  l = strlen (buff);
  for (a = 0; a < l; a++)
    {
      if (buff[a] == ',' && inquote == 0)
	{

	  buff[a] = 0;
	  printc ("%s,", ptr);
	  a++;
	  ptr = &buff[a];
	}
      if (buff[a] == '"')
	{
	  if (inquote == 0)
	    {
	      inquote = 1;
	    }
	  else
	    {
	      if (inquote == 1)
		inquote = 0;
	    }

	}
      if (buff[a] == '\'')
	{
	  if (inquote == 0)
	    {
	      inquote = 2;
	    }
	  else
	    {
	      if (inquote == 2)
		inquote = 0;
	    }

	}
    }
  printc ("%s", ptr);
  clr_nonewlines ();

}


void
printc (char *fmt, ...)
{
  va_list ap;
  /*A4GL_debug("via printc (a) in lib\n"); */


  va_start (ap, fmt);
  A4GL_internal_lex_printc (fmt, &ap);
}


static void
A4GL_internal_lex_printh (char *fmt, va_list * ap)
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


/******************************************************************/
/* ATTRIBUTE HANDLING */
/******************************************************************/


static int
is_plain_line (struct expr_str *line)
{
  if (line->expr_type == ET_EXPR_LITERAL_LONG)
    return 1;
  return 0;
}

static int
get_plain_line (struct expr_str *line)
{
  A4GL_assertion (!is_plain_line (line), "Not a plain line");
  return line->expr_str_u.expr_long;
}





/******************************************************************/
/* EXPR HANDLING */
/******************************************************************/
static char *
get_select (struct s_select *s, char *forUpdate)
{
  char *str;
  char *ptr;
  char into_buff[65000] = "";

  if (forUpdate == 0)
    forUpdate = "";
  if (s->into)
    {
      sprintf (into_buff, "\nINTO %s\n", local_get_expr_as_string_list_with_separator (s->into, ","));
    }
  str = make_select_stmt_v2 (0, s, into_buff);

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




static void
search_variables (struct s_select_list_item_list *l)
{
  int a;
  if (l == 0)
    return;
  for (a = 0; a < l->list.list_len; a++)
    {
      if (l->list.list_val[a]->data.type == E_SLI_VARIABLE_USAGE)
	{
	  l->list.list_val[a]->data.type = E_SLI_VARIABLE;
	  l->list.list_val[a]->data.s_select_list_item_data_u.expression =
	    get_variable_usage (l->list.list_val[a]->data.s_select_list_item_data_u.var_usage);

	}
      //
    }
}


static void
print_select (struct s_select *s, char *forUpdate)
{
  char *str;
  str = get_select (s, forUpdate);
  printc ("%s", str);
  free (str);
}

static char *
get_exists_subquery (int i, struct s_expr_exists_sq *e)
{
  if (i)
    {
      return make_sql_string_and_free (acl_strdup ("EXISTS("), get_select (e->subquery, ""), acl_strdup (")"), NULL);
    }
  else
    {
      return make_sql_string_and_free (acl_strdup ("NOT EXISTS("), get_select (e->subquery, ""), acl_strdup (")"), NULL);
    }
}

static char *
get_in_subquery (int i, struct s_expr_in_sq *e)
{
  if (i)
    {
      return make_sql_string_and_free (local_get_expr_as_string (e->expr), acl_strdup (" IN ("), get_select (e->subquery, ""),
				       acl_strdup (")"), NULL);
    }
  else
    {
      return make_sql_string_and_free (local_get_expr_as_string (e->expr), acl_strdup (" NOT IN ("), get_select (e->subquery, ""),
				       acl_strdup (")"), NULL);
    }
}


static void
real_print_select_list_item_list_with_separator (struct s_select *select, struct s_select_list_item_list *slist, char *sep)
{
  int a;
  if (slist == 0)
    return;

  for (a = 0; a < slist->list.list_len; a++)
    {
      char *rval;
      if (a)
	printc ("%s", sep);
      rval = get_select_list_item (select, slist->list.list_val[a]);
      printc ("%s", rval);
      free (rval);
    }
}


static char *
decode_current1 (int n)
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
  printf ("LINE : %d %d\n", curr_yylineno, n);
  A4GL_assertion (1, "BAD Current");
  return "";
}

static char *
decode_current2 (int n)
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

  printf ("LINE : %d n=%d\n", curr_yylineno, n);

  A4GL_assertion (1, "BAD Current");
  return "";
}


static char *
decode_extend (int n)
{
  static char buff[200];
  char *start;
  char *end;
  start = decode_current1 (n >> 4);
  end = decode_current2 (n & 0xf);
  sprintf (buff, "%s TO %s", start, end);
  return buff;
}


static char *
A4GL_get_expr_list_sep (struct expr_str_list *l, char *sep)
{
  int a;
  struct expr_str *p;
  //struct expr_str *p2;
  //struct expr_str_list *l2;
  //int b;
  int printed = 0;
  char *str = 0;

  if (l == 0)
    return acl_strdup ("");

  l = A4GL_rationalize_list (l);

  for (a = 0; a < l->list.list_len; a++)
    {
      p = l->list.list_val[a];
      if (p->expr_type == ET_EXPR_REDUCED)
	continue;

      if (a)
	{
	  str = make_sql_string_and_free (str, acl_strdup (sep), local_get_expr_as_string (l->list.list_val[a]), NULL);
	}
      else
	{
	  str = local_get_expr_as_string (l->list.list_val[a]);
	}
      printed++;

    }

  return str;
}


static char *
A4GL_get_expr_list_concat (struct expr_str_list *l)
{
  l = A4GL_rationalize_list_concat (l);
  A4GL_get_expr_list_sep (l, ",");
}



static void
real_print_binding_with_separator (expr_str_list * s, char read_or_write, char *sep)
{
  int a;
  if (s == 0)
    return;
  for (a = 0; a < s->list.list_len; a++)
    {
      if (a)
	printc ("%s", sep);
      print_varbind (s->list.list_val[a], read_or_write, a);
    }
}


static void
real_print_str_list_with_separator (str_list * s, char *sep)
{
  int a;
  if (s == 0)
    return;
  for (a = 0; a < s->str_list_entry.str_list_entry_len; a++)
    {
      if (a)
	printc ("%s", sep);
      printc ("%s", s->str_list_entry.str_list_entry_val[a]);
    }
}



static struct expr_str_list *
expand_binding (struct expr_str_list *slist)
{
  A4GL_assertion (1, "FIXME - expand_binding");
  return 0;
}


static void
real_print_variable_or_literal (expr_str * s, char *notsetval)
{
  if (s == 0)
    {
      printc ("%s", notsetval);
      return;
    }

  switch (s->expr_type)
    {

    case ET_E_V_OR_LIT_NOVALUE:
      printc ("%s", notsetval);
      return;
    case ET_EXPR_VARIABLE_USAGE:
    case ET_E_V_OR_LIT_VAR:
      print_varbind (s, 'w', 0);
      break;
    case ET_E_V_OR_LIT_INT:
      printc ("%d", s->expr_str_u.i);
      break;
    case ET_E_V_OR_LIT_STRING:


      if (s->expr_str_u.s[0] == '"')
	{
	  printc ("%s", s->expr_str_u.s);
	}
      else
	{
	  printc ("\"%s\"", s->expr_str_u.s);
	}
      break;
    case ET_E_V_OR_LIT_VAR_AS_STRING:
      printc ("%s", s->expr_str_u.sv);
      break;
    case ET_E_V_OR_LIT_IDENT:
      printf ("2---->%s\n", s->expr_str_u.s);
      printc ("%s", s->expr_str_u.si);
      break;

    default:
      A4GL_assertion (1, "Not a variable or literal");
    }
}


static void
print_ident (struct expr_str *ptr)
{
  if (ptr->expr_type == ET_EXPR_IDENTIFIER)
    {
      printc ("%s", get_orig_from_clobber (ptr->expr_str_u.expr_string));
      return;
    }

  if (ptr->expr_type == ET_EXPR_VARIABLE_IDENTIFIER)
    {
      printc ("_VARIABLE(");
      real_print_expr (ptr->expr_str_u.expr_expr);
      printc (")");
      return;
    }
  if (ptr->expr_type == ET_EXPR_VARIABLE_USAGE)
    {
      printc ("%s", get_variable_usage (ptr->expr_str_u.expr_variable_usage));
      return;
    }


  A4GL_assertion (1, "print_ident not implemented yet");
  return;
}

static void
print_quoted_ident (struct expr_str *ptr)
{

  if (ptr->expr_type == ET_EXPR_IDENTIFIER)
    {
      printc ("\"%s\"", ptr->expr_str_u.expr_string);
      return;
    }

  if (ptr->expr_type == ET_EXPR_VARIABLE_IDENTIFIER)
    {
      //printc("_VARIABLE(");
      real_print_expr (ptr->expr_str_u.expr_expr);
      //printc(")");
      return;
    }


  A4GL_assertion (1, "print_quoted_ident not implemented yet");
}




static void
real_print_expr (struct expr_str *ptr)
{
  char *str;
  printing_expr = 1;
  str = local_get_expr_as_string (ptr);

  {
    int a;
    for (a = 0; a < strlen (str); a++)
      {
	if (str[a] < 31 && str[a] != '\n' && str[a] != '\r' && str[a] != '\t')
	  {

	    A4GL_pause_execution ();
	    break;
	  }
      }
  }







  printc ("%s", str, ptr->expr_type);
  printing_expr = 0;

  free (str);
}

static char *
local_get_expr_as_string (struct expr_str *ptr)
{
  char buff[20000] = "";
  int a;
  char *str;
  //void *optr;
  //int a;
  A4GL_assertion (ptr == 0, "can't print a null pointer...");
  switch (ptr->expr_type)
    {
    case ET_EXPR_OP_IN:
    case ET_EXPR_OP_NOT_IN:
      if (ptr->expr_type == ET_EXPR_OP_IN)
	{

	  str = make_sql_string_and_free (local_get_expr_as_string (ptr->expr_str_u.expr_in->expr), acl_strdup (" IN ("), NULL);
	}
      else
	{
	  str = make_sql_string_and_free (local_get_expr_as_string (ptr->expr_str_u.expr_in->expr), acl_strdup (" NOT IN ("), NULL);
	}
      for (a = 0; a < ptr->expr_str_u.expr_in->elist->list.list_len; a++)
	{
	  if (a)
	    {
	      str = make_sql_string_and_free (str, acl_strdup (","), NULL);
	    }
	  str = make_sql_string_and_free (str, local_get_expr_as_string (ptr->expr_str_u.expr_in->elist->list.list_val[a]), NULL);
	}
      str = make_sql_string_and_free (str, acl_strdup (")"), NULL);
      return str;
      break;


    case ET_EXPR_NOT_EXISTS_SUBQUERY:
      return get_exists_subquery (0, ptr->expr_str_u.expr_exists_sq);
      break;
    case ET_EXPR_EXISTS_SUBQUERY:
      return get_exists_subquery (1, ptr->expr_str_u.expr_exists_sq);
      break;
    case ET_EXPR_OP_NOTIN_SUBQUERY:
      return get_in_subquery (0, ptr->expr_str_u.expr_in_sq);
      break;
    case ET_EXPR_OP_IN_SUBQUERY:
      return get_in_subquery (1, ptr->expr_str_u.expr_in_sq);
      break;

    case ET_EXPR_STRING:
      return acl_strdup (ptr->expr_str_u.expr_string);
      break;


    case ET_EXPR_TIME:
      return acl_strdup ("TIME");
      break;
    case ET_EXPR_NULL:
      return acl_strdup ("NULL");
      break;
    case ET_EXPR_TRUE:
      return acl_strdup ("TRUE");
      break;
    case ET_EXPR_FALSE:
      return acl_strdup ("FALSE");
      break;

    case ET_EXPR_NOT:
      sprintf (buff, "NOT(%s)", local_get_expr_as_string (ptr->expr_str_u.expr_expr));
      return acl_strdup (buff);
      break;
    case ET_EXPR_BRACKET:
      sprintf (buff, "(%s)\n", local_get_expr_as_string (ptr->expr_str_u.expr_expr));
      return acl_strdup (buff);
      break;

    case ET_EXPR_NEG:
      sprintf (buff, "(0-%s)", local_get_expr_as_string (ptr->expr_str_u.expr_expr));
      return acl_strdup (buff);
      break;
    case ET_EXPR_UPSHIFT:
      sprintf (buff, "UPSHIFT(%s)", local_get_expr_as_string (ptr->expr_str_u.expr_expr));
      return acl_strdup (buff);
      break;
    case ET_EXPR_DOWNSHIFT:
      sprintf (buff, "DOWNSHIFT(%s)", local_get_expr_as_string (ptr->expr_str_u.expr_expr));
      return acl_strdup (buff);
      break;

    case ET_EXPR_DATE_EXPR:
      return acl_strdup ("DATE");
      break;

    case ET_EXPR_COLUMN:
      not_in_spl ();
      return acl_strdup ("");

      break;
    case ET_EXPR_TIME_EXPR:
      return acl_strdup ("TIME");
      break;

    case ET_EXPR_TODAY:
      A4GL_warn ("Coding Standards: Use of builtin TODAY variable");
      return acl_strdup ("TODAY");
      break;

    case ET_EXPR_ASCII:
      sprintf (buff, "ASCII %s", local_get_expr_as_string (ptr->expr_str_u.expr_expr));
      return acl_strdup (buff);
      break;

    case ET_EXPR_EXTEND:
      sprintf (buff, "EXTEND(%s,%s)", local_get_expr_as_string (ptr->expr_str_u.expr_extend->expr),
	       decode_extend (ptr->expr_str_u.expr_extend->to));
      return acl_strdup (buff);

      break;



    case ET_EXPR_AGGREGATE:
      switch (ptr->expr_str_u.expr_agg->agg_type)
	{
	case 'S':
	  sprintf (buff, "%sSUM(%s)", ptr->expr_str_u.expr_agg->in_group ? "GROUP " : "",
		   local_get_expr_as_string (ptr->expr_str_u.expr_agg->agg_expr));
	  break;
	case 'A':
	  sprintf (buff, "%sAVERAGE(%s)", ptr->expr_str_u.expr_agg->in_group ? "GROUP " : "",
		   local_get_expr_as_string (ptr->expr_str_u.expr_agg->agg_expr));
	  break;
	case 'X':
	  sprintf (buff, "%sMAX(%s)", ptr->expr_str_u.expr_agg->in_group ? "GROUP " : "",
		   local_get_expr_as_string (ptr->expr_str_u.expr_agg->agg_expr));
	  break;
	case 'N':
	  sprintf (buff, "%sMIN(%s)", ptr->expr_str_u.expr_agg->in_group ? "GROUP " : "",
		   local_get_expr_as_string (ptr->expr_str_u.expr_agg->agg_expr));
	  break;
	case 'P':
	  sprintf (buff, "%sPERCENT(%s)", ptr->expr_str_u.expr_agg->in_group ? "GROUP " : "",
		   local_get_expr_as_string (ptr->expr_str_u.expr_agg->agg_expr));
	  break;
	case 'C':
	  sprintf (buff, "%sCOUNT(*)", ptr->expr_str_u.expr_agg->in_group ? "GROUP " : "");
	  break;

	default:
	  sprintf (buff, "**AGG**");
	}

      if (ptr->expr_str_u.expr_agg->expr_where)
	{
	  char buff2[100000];
	  sprintf (buff2, "(%s WHERE %s)", buff, local_get_expr_as_string (ptr->expr_str_u.expr_agg->expr_where));
	  strcpy (buff, buff2);
	}
      return acl_strdup (buff);


      break;

    case ET_EXPR_PAGENO:
      not_in_spl ();
      return acl_strdup ("");

    case ET_EXPR_LINENO:
      not_in_spl ();
      return acl_strdup ("");

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
	       local_get_expr_as_string (l->list[a]);
	       }
	       }
	     */
	  }

	params = A4GL_new_list_get_count (ptr->expr_str_u.expr_function_call->parameters);
	sprintf (buff, "%s(%s)", map_fname (ptr->expr_str_u.expr_function_call->fname),
		 A4GL_get_expr_list_sep (ptr->expr_str_u.expr_function_call->parameters, ",\n"));

      }
      return acl_strdup (buff);
      break;

    case ET_EXPR_REPORT_PRINTER:
      not_in_spl ();
      return acl_strdup ("");

    case ET_EXPR_REPORT_EMAIL:
      not_in_spl ();
      return acl_strdup ("");


    case ET_EXPR_LITERAL_LONG:
      sprintf (buff, "%ld", ptr->expr_str_u.expr_long);
      return acl_strdup (buff);
      break;

    case ET_EXPR_LITERAL_STRING:
      {
	char buff[60000];
	sprintf (buff, "\"%s\"", A4GL_strip_quotes (ptr->expr_str_u.expr_string));
	return acl_strdup (buff);
      }
      break;

    case ET_EXPR_QUOTED_STRING:
      return acl_strdup (ptr->expr_str_u.expr_string);
      break;

    case ET_EXPR_LITERAL_DOUBLE_STR:
      return acl_strdup (ptr->expr_str_u.expr_string);
      break;

    case ET_EXPR_OP_CLIP:
      //return make_sql_string_and_free (local_get_expr_as_string
      //(ptr->expr_str_u.expr_expr), acl_strdup (" CLIPPED"), NULL);
      
      //ASK - fix for CLIPPED verb
      sprintf( buff,
	       "RTRIM( %s )",
	       local_get_expr_as_string (ptr->expr_str_u.expr_expr));
      return acl_strdup (buff);
      break;
    case ET_EXPR_OP_ISNULL:
      sprintf (buff, "%s IS NULL", local_get_expr_as_string (ptr->expr_str_u.expr_expr));
      return acl_strdup (buff);
      break;
    case ET_EXPR_OP_ISNOTNULL:
      sprintf (buff, "%s IS NOT NULL", local_get_expr_as_string (ptr->expr_str_u.expr_expr));
      return acl_strdup (buff);
      break;
    case ET_EXPR_OP_MATCHES:
      if (ptr->expr_str_u.expr_op->escape)
	{
	  sprintf (buff, "%s MATCHES %s ESCAPE %s",
		   local_get_expr_as_string (ptr->expr_str_u.expr_op->left),
		   local_get_expr_as_string (ptr->expr_str_u.expr_op->right),
		   local_get_expr_as_string (ptr->expr_str_u.expr_op->escape));
	}
      else
	{
	  sprintf (buff, "%s MATCHES %s",
		   local_get_expr_as_string (ptr->expr_str_u.expr_op->left),
		   local_get_expr_as_string (ptr->expr_str_u.expr_op->right));

	}
      return acl_strdup (buff);
      break;

    case ET_EXPR_OP_NOT_MATCHES:
      if (ptr->expr_str_u.expr_op->escape)
	{
	  sprintf (buff, "%s NOT MATCHES %s ESCAPE %s",
		   local_get_expr_as_string (ptr->expr_str_u.expr_op->left),
		   local_get_expr_as_string (ptr->expr_str_u.expr_op->right),
		   local_get_expr_as_string (ptr->expr_str_u.expr_op->escape));
	}
      else
	{
	  sprintf (buff, "%s NOT MATCHES %s",
		   local_get_expr_as_string (ptr->expr_str_u.expr_op->left),
		   local_get_expr_as_string (ptr->expr_str_u.expr_op->right));
	}
      return acl_strdup (buff);
      break;


    case ET_EXPR_OP_LIKE:
      if (ptr->expr_str_u.expr_op->escape)
	{
	  sprintf (buff, "%s LIKE %s ESCAPE %s",
		   local_get_expr_as_string (ptr->expr_str_u.expr_op->left),
		   local_get_expr_as_string (ptr->expr_str_u.expr_op->right),
		   local_get_expr_as_string (ptr->expr_str_u.expr_op->escape));
	}
      else
	{
	  sprintf (buff, "%s LIKE %s",
		   local_get_expr_as_string (ptr->expr_str_u.expr_op->left),
		   local_get_expr_as_string (ptr->expr_str_u.expr_op->right));
	}
      return acl_strdup (buff);
      break;
    case ET_EXPR_OP_NOT_LIKE:
      if (ptr->expr_str_u.expr_op->escape)
	{
	  sprintf (buff, "%s NOT LIKE %s ESCAPE %s",
		   local_get_expr_as_string (ptr->expr_str_u.expr_op->left),
		   local_get_expr_as_string (ptr->expr_str_u.expr_op->right),
		   local_get_expr_as_string (ptr->expr_str_u.expr_op->escape));
	}
      else
	{
	  sprintf (buff, "%s NOT LIKE %s",
		   local_get_expr_as_string (ptr->expr_str_u.expr_op->left),
		   local_get_expr_as_string (ptr->expr_str_u.expr_op->right));
	}
      return acl_strdup (buff);
      break;



    case ET_EXPR_OP_ADD:
      sprintf (buff, "%s+%s",
	       local_get_expr_as_string (ptr->expr_str_u.expr_op->left), local_get_expr_as_string (ptr->expr_str_u.expr_op->right));
      return acl_strdup (buff);
      break;
    case ET_EXPR_OP_SUB:
      sprintf (buff, "%s-%s",
	       local_get_expr_as_string (ptr->expr_str_u.expr_op->left), local_get_expr_as_string (ptr->expr_str_u.expr_op->right));
      return acl_strdup (buff);
      break;
    case ET_EXPR_OP_DIV:

      sprintf (buff, "%s/%s",
	       local_get_expr_as_string (ptr->expr_str_u.expr_op->left), local_get_expr_as_string (ptr->expr_str_u.expr_op->right));
      return acl_strdup (buff);
      break;

    case ET_EXPR_OP_MULT:
      sprintf (buff, "%s*%s",
	       local_get_expr_as_string (ptr->expr_str_u.expr_op->left), local_get_expr_as_string (ptr->expr_str_u.expr_op->right));
      return acl_strdup (buff);
      break;


    case ET_EXPR_OP_LESS_THAN:
      sprintf (buff, "%s<%s",
	       local_get_expr_as_string (ptr->expr_str_u.expr_op->left), local_get_expr_as_string (ptr->expr_str_u.expr_op->right));
      return acl_strdup (buff);
      break;

    case ET_EXPR_OP_GREATER_THAN:
      sprintf (buff, "%s>%s",
	       local_get_expr_as_string (ptr->expr_str_u.expr_op->left), local_get_expr_as_string (ptr->expr_str_u.expr_op->right));
      return acl_strdup (buff);
      break;
    case ET_EXPR_OP_EQUAL:
      sprintf (buff, "%s=%s",
	       local_get_expr_as_string (ptr->expr_str_u.expr_op->left), local_get_expr_as_string (ptr->expr_str_u.expr_op->right));
      return acl_strdup (buff);
      break;
    case ET_EXPR_OP_NOT_EQUAL:
      sprintf (buff, "%s!=%s",
	       local_get_expr_as_string (ptr->expr_str_u.expr_op->left), local_get_expr_as_string (ptr->expr_str_u.expr_op->right));
      return acl_strdup (buff);
      break;
    case ET_EXPR_OP_LESS_THAN_EQ:
      sprintf (buff, "%s<=%s",
	       local_get_expr_as_string (ptr->expr_str_u.expr_op->left), local_get_expr_as_string (ptr->expr_str_u.expr_op->right));
      return acl_strdup (buff);
      break;

    case ET_EXPR_OP_GREATER_THAN_EQ:
      sprintf (buff, "%s>=%s",
	       local_get_expr_as_string (ptr->expr_str_u.expr_op->left), local_get_expr_as_string (ptr->expr_str_u.expr_op->right));
      return acl_strdup (buff);
      break;

    case ET_EXPR_OP_OR:
      sprintf (buff, "%s OR %s",
	       local_get_expr_as_string (ptr->expr_str_u.expr_op->left), local_get_expr_as_string (ptr->expr_str_u.expr_op->right));
      return acl_strdup (buff);
      break;
    case ET_EXPR_OP_AND:
      sprintf (buff, "%s AND %s\n",
	       local_get_expr_as_string (ptr->expr_str_u.expr_op->left), local_get_expr_as_string (ptr->expr_str_u.expr_op->right));
      return acl_strdup (buff);
      break;

    case ET_EXPR_LITERAL_EMPTY_STRING:
      return acl_strdup ("\"\"");
      break;

    case ET_EXPR_OP_USING:
      sprintf (buff, "%s USING %s",
	       local_get_expr_as_string (ptr->expr_str_u.expr_op->left), local_get_expr_as_string (ptr->expr_str_u.expr_op->right));
      return acl_strdup (buff);
      break;
    case ET_EXPR_OP_MOD:
      sprintf (buff, "%s MOD %s",
	       local_get_expr_as_string (ptr->expr_str_u.expr_op->left), local_get_expr_as_string (ptr->expr_str_u.expr_op->right));
      return acl_strdup (buff);

      break;
    case ET_EXPR_OP_POWER:
      sprintf (buff, "%s ** %s",
	       local_get_expr_as_string (ptr->expr_str_u.expr_op->left), local_get_expr_as_string (ptr->expr_str_u.expr_op->right));
      return acl_strdup (buff);
      break;
    case ET_EXPR_OP_CONCAT:
      sprintf (buff, "%s||%s",
	       local_get_expr_as_string (ptr->expr_str_u.expr_op->left), local_get_expr_as_string (ptr->expr_str_u.expr_op->right));
      return acl_strdup (buff);
      break;

    case ET_EXPR_OP_YEAR:
      sprintf (buff, "%s UNITS YEAR", local_get_expr_as_string (ptr->expr_str_u.expr_expr));
      return acl_strdup (buff);
      break;

    case ET_EXPR_OP_MONTH:
      sprintf (buff, "%s UNITS MONTH", local_get_expr_as_string (ptr->expr_str_u.expr_expr));
      return acl_strdup (buff);
      break;

    case ET_EXPR_OP_DAY:
      sprintf (buff, "%s UNITS DAY", local_get_expr_as_string (ptr->expr_str_u.expr_expr));
      return acl_strdup (buff);
      break;

    case ET_EXPR_OP_HOUR:
      sprintf (buff, "%s UNITS HOUR", local_get_expr_as_string (ptr->expr_str_u.expr_expr));
      return acl_strdup (buff);
      break;

    case ET_EXPR_OP_MINUTE:
      sprintf (buff, "%s UNITS MINUTE", local_get_expr_as_string (ptr->expr_str_u.expr_expr));
      return acl_strdup (buff);
      break;

    case ET_EXPR_OP_SECOND:
      sprintf (buff, "%s UNITS SECOND", local_get_expr_as_string (ptr->expr_str_u.expr_expr));
      return acl_strdup (buff);
      break;
    case ET_EXPR_CURRENT:
      sprintf (buff, "CURRENT %s TO %s",
	       decode_current1 (ptr->expr_str_u.expr_current->from), decode_current2 (ptr->expr_str_u.expr_current->to));
      return acl_strdup (buff);
      break;

    case ET_EXPR_OP_SPACES:
      not_in_spl ();
      return acl_strdup ("");

    case ET_EXPR_MENU_ALL:
      not_in_spl ();
      return acl_strdup ("");

    case ET_EXPR_DTVAL:
      sprintf (buff, "DATETIME(%s) %d", ptr->expr_str_u.expr_datetime->dtval, ptr->expr_str_u.expr_datetime->extend);
      return acl_strdup (buff);
      break;

    case ET_EXPR_YEAR_FUNC:
      sprintf (buff, "YEAR(%s)", local_get_expr_as_string (ptr->expr_str_u.expr_expr));
      return acl_strdup (buff);
      break;

    case ET_EXPR_DATE_FUNC:
      sprintf (buff, "DATE(%s)", local_get_expr_as_string (ptr->expr_str_u.expr_expr));
      return acl_strdup (buff);
      break;

    case ET_EXPR_MONTH_FUNC:
      sprintf (buff, "MONTH(%s)", local_get_expr_as_string (ptr->expr_str_u.expr_expr));
      return acl_strdup (buff);
      break;

    case ET_EXPR_DAY_FUNC:
      sprintf (buff, "DAY(%s)", local_get_expr_as_string (ptr->expr_str_u.expr_expr));
      return acl_strdup (buff);
      break;

    case ET_EXPR_TIME_FUNC:
      sprintf (buff, "TIME(%s)", local_get_expr_as_string (ptr->expr_str_u.expr_expr));
      return acl_strdup (buff);
      break;

    case ET_EXPR_IVAL_VAL:
      sprintf (buff, "INTERVAL(%s) %s TO %s", A4GL_strip_quotes (ptr->expr_str_u.expr_interval->intval),
	       decode_ival_define1 (ptr->expr_str_u.expr_interval->extend),
	       decode_ival_define2 (ptr->expr_str_u.expr_interval->extend));
      return acl_strdup (buff);
      break;

    case ET_EXPR_FIELD_TOUCHED:
    case ET_EXPR_INFIELD:
    case ET_EXPR_NOT_FIELD_TOUCHED:
    case ET_EXPR_FGL_SIZEOF:
    case ET_EXPR_FGL_ADDRESSOF:
    case ET_EXPR_FGL_ISDYNARR_ALLOCATED:
    case ET_EXPR_FGL_DYNARR_EXTENTSIZE:
    case ET_EXPR_FIELDTOWIDGET:
    case ET_EXPR_ID_TO_INT:
    case ET_EXPR_GET_FLDBUF:
    case ET_EXPR_MODULE_FUNC:
    case ET_EXPR_PDF_FCALL:
      not_in_spl ();
      return acl_strdup ("");


    case ET_EXPR_VARIABLE_USAGE:
      return acl_strdup (get_variable_usage (ptr->expr_str_u.expr_variable_usage));
      break;

    case ET_EXPR_VARIABLE_USAGE_WITH_ASC_DESC:
      strcpy (buff, get_variable_usage (ptr->expr_str_u.expr_variable_usage_with_asc_desc->var_usage));
      if (ptr->expr_str_u.expr_variable_usage_with_asc_desc->asc_desc == 'D')
	{
	  strcat (buff, " DESC");
	}
      else
	{
	  strcat (buff, " ASC");
	}
      return acl_strdup (buff);
      break;

    case ET_EXPR_SQLBLOCK:
      return acl_strdup (local_get_expr_as_string_list_with_separator (ptr->expr_str_u.expr_list, " "));
      break;

    case ET_EXPR_SQLBLOCK_TEXT:
      sprintf (buff, "%s", ptr->expr_str_u.expr_string);
      return acl_strdup (buff);
      break;

    case ET_EXPR_SQLBLOCK_INTO:
      sprintf (buff, " INTO %s", local_get_expr_as_string_list_with_separator (ptr->expr_str_u.expr_list, ","));
      return acl_strdup (buff);
      break;

    case ET_EXPR_VARIABLE_IDENTIFIER:
      not_in_spl ();
      return acl_strdup ("");

    case ET_E_V_OR_LIT_VAR_AS_STRING:
      sprintf (buff, "%s", ptr->expr_str_u.sv);
      return acl_strdup (buff);
      break;

    case ET_E_V_OR_LIT_VAR:
      return acl_strdup (local_get_expr_as_string (ptr->expr_str_u.var));
      break;

    case ET_E_V_OR_LIT_INT:
      sprintf (buff, "%d", ptr->expr_str_u.i);
      return acl_strdup (buff);
      break;

    case ET_E_V_OR_LIT_STRING:
      sprintf (buff, "%s", ptr->expr_str_u.s);
      return acl_strdup (buff);
      break;

    case ET_E_V_OR_LIT_IDENT:
      sprintf (buff, "%s", ptr->expr_str_u.si);
      return acl_strdup (buff);
      break;

    case ET_E_V_OR_LIT_NOVALUE:
      A4GL_assertion (1, "SHouldn't print these...");
      break;

    case ET_EXPR_CACHED:
      A4GL_assertion (1, "SHouldn't print these...");
      break;

      // These will never be implemented - because they dont make sense..
    case ET_EXPR_REDUCED:
      A4GL_assertion (1, "ET_EXPR_REDUCED should never be printed");
      return "";
      break;
    case ET_EXPR_LAST:
      return "";
      A4GL_assertion (1, "ET_EXPR_LAST should never be printed");
      break;
    case ET_EXPR_EXPR_LIST:
      return "";
      A4GL_assertion (1, "ET_EXPR_EXPR_LIST can't be printed - print using A4GL_print_expr_list or A4GL_print_expr_list_concat");
      break;

    case ET_EXPR_WORDWRAP:
      {
	struct s_expr_wordwrap *w;
	w = ptr->expr_str_u.expr_wordwrap;
	if (w->wrap_at)
	  {
	    if (w->wrap_at->expr_type == ET_EXPR_LITERAL_LONG && w->wrap_at->expr_str_u.expr_long == 0)
	      {
		sprintf (buff, "%s WORDWRAP", local_get_expr_as_string (w->expr));
	      }
	    else
	      {
		sprintf (buff, "%s WORDWRAP %s", local_get_expr_as_string (w->expr), local_get_expr_as_string (w->wrap_at));
	      }
	  }
	else
	  {
	    sprintf (buff, "%s", local_get_expr_as_string (w->expr));
	  }
      }
      return acl_strdup (buff);;
      // Wordwraps shouldn't be printed - in the report_print - the wrapped expression should be printed...
      A4GL_assertion (1, "ET_EXPR_WORDWRAP should never be printed");
      break;


      // These should be implemented - but aren't yet... 
    case ET_EXPR_EXTERNAL:
      return "";
      A4GL_assertion (1, "ET_EXPR_EXTERNAL has not been implented as an expression yet");
      break;

    case ET_EXPR_TEMP:
      A4GL_assertion (1, "SHouldn't print these ? ");
      //expr_tmp
      break;
    case ET_EXPR_IDENTIFIER:
      A4GL_assertion (1, "SHouldn't print these ? ");
      //expr_string

    case ET_EXPR_PARAMETER:
      A4GL_assertion (1, "SHouldn't print these ? ");
      //expr_string
      break;

    case ET_EXPR_SELECT_LIST_ITEM:
      {
	struct s_select_list_item *s;
	char *str;
	s = ptr->expr_str_u.sl_item;
	switch (s->data.type)
	  {
	  case E_SLI_QUERY:
	    str = make_select_stmt_v2 (0, s->data.s_select_list_item_data_u.subquery, "");
	    return str;

	  default:
	    A4GL_assertion (1, "SHouldn't print these ? ");

	  }

      }
      //sl_item


    case ET_EXPR_CONCAT_LIST:
      A4GL_assertion (1, "CONCAT_LIST NOT IMPLEMENTED YET");
      break;

    case ET_EXPR_CAST:
      A4GL_assertion (1, "CASE NOT IMPLEMENTED YET");
      break;


    case ET_EXPR_SHARED_FCALL:
      A4GL_assertion (1, "Not implemented");
      break;

    case ET_EXPR_BOUND_FCALL:
      A4GL_assertion (1, "Not implemented");
      break;


    case ET_EXPR_MEMBER_FCALL:
      A4GL_assertion (1, "Not implemented");
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
    case ET_EXPR_FIELDNAME:
      A4GL_assertion (1, "Not implemented");
      break;

    }
  A4GL_assertion (1, "Bad..");
  return "..";
}


static void
real_print_expr_list_pipes (struct expr_str_list *l)
{
  int a;
  l = A4GL_rationalize_list (l);
  printc ("(");
  if (l)
    {
      for (a = 0; a < l->list.list_len; a++)
	{
	  if (a)
	    printc (")||(");
	  real_print_expr (l->list.list_val[a]);
	}
    }
  printc (")");

}


static void
real_print_trimmed_str_list_with_separator (str_list * s, char *sep)
{
  int a;
  if (s == 0)
    return;
  for (a = 0; a < s->str_list_entry.str_list_entry_len; a++)
    {
      if (a)
	printc ("%s", sep);
      printc ("%s", A4GL_strip_quotes (s->str_list_entry.str_list_entry_val[a]));
    }
}

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

	  if (strcmp (s, "||") == 0)
	    {
	      printc ("(");
	    }
	  real_print_expr (l->list.list_val[a]);
	  if (strcmp (s, "||") == 0)
	    {
	      printc (")");
	    }
	}
    }

}

static char *
local_get_expr_as_string_list_with_separator (struct expr_str_list *l, char *sep)
{
  char buff[65000] = "";
  strcpy (buff, "");

  int a;
  l = A4GL_rationalize_list (l);
  if (l)
    {
      for (a = 0; a < l->list.list_len; a++)
	{
	  if (a)
	    strcat (buff, sep);
	  strcat (buff, local_get_expr_as_string (l->list.list_val[a]));
	}
    }
  //  printf("lgeaslws: Buff=%s\n",buff);  // ASK s/b commented
  return strdup (buff);
}


static struct expr_str_list *
A4GL_rationalize_list_concat (struct expr_str_list *l)
{
  int a;
  struct expr_str *p;
  struct expr_str *p2;
  struct expr_str_list *l2;
  //int b;
  //int printed = 0;

  if (l == 0)
    return 0;
  l = A4GL_rationalize_list (l);

  if ((l->list.list_len) > 1)
    {
      for (a = 0; a < l->list.list_len - 1; a++)
	{
	  p = l->list.list_val[a];
	  p2 = l->list.list_val[a + 1];

	  if (p->expr_type == ET_EXPR_LITERAL_STRING && p2->expr_type == ET_EXPR_LITERAL_STRING && 0)
	    {
	      // They're concating two literal strings - lets make the second one empty..
	      // and concat the strings *now* rather than runtime...
	      char *x1;
	      char *x2;
	      char *x3;
	      x1 = p->expr_str_u.expr_string;
	      x2 = p2->expr_str_u.expr_string;
	      x3 = malloc (strlen (x1) + strlen (x2) + 1);
	      strcpy (x3, x1);
	      strcat (x3, x2);
	      p->expr_type = ET_EXPR_REDUCED;
	      p2->expr_str_u.expr_string = x3;
	    }
	}
    }


  l2 = A4GL_new_ptr_list (0);

  for (a = 0; a < l->list.list_len; a++)
    {
      p = l->list.list_val[a];
      if (p->expr_type != ET_EXPR_REDUCED)
	{
	  A4GL_new_append_ptr_list (l2, p);
	}
    }

  l = l2;

  return l;
}

/******************************************************************/
/* FIELD HANDLING */
/******************************************************************/




/******************************************************************/
/* VARIABLE HANDLING */
/******************************************************************/


static char
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

static int
get_var_expr_dtype (struct expr_str *p)
{
  struct variable_usage *u;
  char errbuff[200];
  if (p->expr_type != ET_EXPR_VARIABLE_USAGE)
    {
      A4GL_assertion (1, "Should be ET_EXPR_VARIABLE_USAGE");
    }
  return get_variable_dtype_from_variable_usage_expression (errbuff, p);
  u = p->expr_str_u.expr_variable_usage;
  return u->datatype;
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
		need_daylight ();	//printc ("#");
	      n++;
	      printh ("#REQUIRETEMP %s lv_tmpi_%x_%d %d\n", get_currfuncname (), get_var_expr_dtype (l->list.list_val[a]), a,
		      get_var_expr_dtype (l->list.list_val[a]));
	      printc ("LET lv_tmpi_%x_%d=", get_var_expr_dtype (l->list.list_val[a]), a);
	      print_varbind (l->list.list_val[a], 'R', a);
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
		  need_daylight ();	//printc ("#");
		  n++;
		}
	      printh ("#REQUIRETEMP %s lv_tmpo_%x_%d %d\n", get_currfuncname (), get_var_expr_dtype (l->list.list_val[a]), a,
		      get_var_expr_dtype (l->list.list_val[a]));
	      printc ("CALL ");
	      print_varbind (l->list.list_val[a], 'W', a);
	      printc ("lv_tmpo_%x_%d)", get_var_expr_dtype (l->list.list_val[a]), a);
	      A4GL_assertion (get_var_expr_dtype (l->list.list_val[a]) == -2, "-2 detected");
	    }
	}
    }

}


static int
local_is_system_variable (char *s)
{
  //if (strcmp (s, "int_flag") == 0) return 1;
  //if (strcmp (s, "quit_flag") == 0) return 1;

  if (strcmp (s, "a4gl_status") == 0)
    return 1;
  if (strncmp (s, "a4gl_sqlca", 10) == 0)
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


static char *
decode_dt (int a, int b)
{
  static char buff1[200];
  static char buff2[200];
  int c;
  if (a == 0)
    {
      if (b == 1)
	return "YEAR";
      return "SECOND";
    }

  if (b == 1)
    {
      c = a >> 4;
      sprintf (buff1, "%x %x (b=%d)", c, a, b);
      switch (c)
	{
	case 1:
	  strcpy (buff1, "YEAR");
	  break;
	case 2:
	  strcpy (buff1, "MONTH");
	  break;
	case 3:
	  strcpy (buff1, "DAY");
	  break;
	case 4:
	  strcpy (buff1, "HOUR");
	  break;
	case 5:
	  strcpy (buff1, "MINUTE");
	  break;
	case 6:
	  strcpy (buff1, "SECOND");
	  break;
	case 7:
	  strcpy (buff1, "FRACTION(1)");
	  break;
	case 8:
	  strcpy (buff1, "FRACTION(2)");
	  break;
	case 9:
	  strcpy (buff1, "FRACTION(3)");
	  break;
	case 10:
	  strcpy (buff1, "FRACTION(4)");
	  break;
	case 11:
	  strcpy (buff1, "FRACTION(5)");
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
	  strcpy (buff2, "YEAR");
	  break;
	case 2:
	  strcpy (buff2, "MONTH");
	  break;
	case 3:
	  strcpy (buff2, "DAY");
	  break;
	case 4:
	  strcpy (buff2, "HOUR");
	  break;
	case 5:
	  strcpy (buff2, "MINUTE");
	  break;
	case 6:
	  strcpy (buff2, "SECOND");
	  break;
	case 7:
	  strcpy (buff2, "FRACTION(1)");
	  break;
	case 8:
	  strcpy (buff2, "FRACTION(2)");
	  break;
	case 9:
	  strcpy (buff2, "FRACTION(3)");
	  break;
	case 10:
	  strcpy (buff2, "FRACTION(4)");
	  break;
	case 11:
	  strcpy (buff2, "FRACTION(5)");
	  break;
	}
      return buff2;
    }
}

static char *
decode_ival_define1 (int n)
{
  static char buff[256];
  int l;

  if (n == 0x602)
    return "YEAR";
  if (n == 0x84a)
    return "DAY";
  if (n == 0xa6d)
    return "HOUR(3)";

  //printf("-->%x (n==0x602)=%d \n",n, n==0x602);

  l = (n >> 8) & 0xf;
  if (l == 6)
    {
      switch ((n >> 4) & 0xf)
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
    }
  else
    {
      switch ((n >> 4) & 0xf)
	{
	case 1:
	  sprintf (buff, "YEAR(%d)", l);
	  return buff;
	case 2:
	  sprintf (buff, "MONTH(%d)", l);
	  return buff;
	case 3:
	  sprintf (buff, "DAY(%d)", l);
	  return buff;
	case 4:
	  sprintf (buff, "HOUR(%d)", l);
	  return buff;
	case 5:
	  sprintf (buff, "MINUTE(%d)", l);
	  return buff;
	case 6:
	  sprintf (buff, "SECOND(%d)", l);
	  return buff;

	}

    }
  printf ("%x @ %d\n", n, curr_yylineno);
  A4GL_assertion (1, "Unknown CURRENT 9.1");
  return "";
}


static char *
decode_ival_define2 (int n)
{
  if (n == 0x602)
    return "MONTH";
  if (n == 0x84a)
    return "SECOND";
  if (n == 0xa6d)
    return "FRACTION(3)";
  switch (n & 0xf)
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
  A4GL_assertion (1, "Unknown CURRENT 8.1");
  return "";
}



/**
 *  * Gets the C data type corresponding to 4gl data type
 *   *
 *    * @param s A string with the numeric 4gl data type (@see find_type())
 *     * @return The string (static) with the C declaration
 *      */
static char *
lexlib_rettype (char *s)
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



static char *
local_rettype_integer (int n)
{
  char s[200];

  /*static char rs[20] = "long"; */
  /*int a; */

  A4GL_debug ("rettype_integer : %d\n", n);

  SPRINTF1 (s, "%d", n);
  return lexlib_rettype (s);
}


static char *
irettype_integer (char *s, int n)
{
  static char buff[256];
  if (strlen (s))
    {
      sprintf (buff, "LIKE %s", s);
      return buff;
    }
  return local_rettype_integer (n);
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
      sprintf (buff, "%d", v->arr_subscripts.arr_subscripts_val[a]);
      strcat (s, buff);
    }
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
static void
print_define_char (char *var, int size, int isstatic_extern, int lvl, int vno, char *defsrc, enum e_scope scope)
{
  char buff[20];
  char *comma;
  char *globalstr;
  char *globaldef;
  strcpy (buff, "");
  if (vno)
    comma = ",";
  else
    comma = "";

  if (isstatic_extern == 1)
    {
      //strcat (buff, "static ");
    }

  if (isstatic_extern == 2)
    {
      return;
    }

  if (scope == 'g' || scope == 'G' || scope == 'M' || scope == 'm')
    {
      globalstr = " GLOBAL";
      globaldef = " DEFAULT NULL";
    }
  else
    {
      globalstr = "";
      globaldef = "";
    }

  if (lvl && 0)
    {
      if (strlen (defsrc))
	{
	  printc ("%s%s%s\n", var, buff, comma);
	}
      else
	{
	  printc ("%s%s(%d)%s\n", var, buff, size, comma);
	}
    }
  else
    {
      if (strlen (defsrc))
	{
	  printc ("DEFINE%s %s%s%s;\n", globalstr, var, buff, globaldef);
	}
      else
	{
	  printc ("DEFINE%s %s%s(%d)%s;\n", globalstr, var, buff, size, globaldef);
	}
    }
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
print_define (char *varstring, int isstatic_extern, int lvl, int vno, enum e_scope scope)
{
  char buff[20];
  char *comma;
  char *globalstr;
  char *globaldef;

  if (scope == 'g' || scope == 'G' || scope == 'M' || scope == 'm')
    {
      globalstr = " GLOBAL";
      globaldef = " DEFAULT NULL";
    }
  else
    {
      globalstr = "";
      globaldef = "";
    }
  if (vno)
    comma = ",";
  else
    comma = "";

  strcpy (buff, "");

  if (isstatic_extern == 1)
    {
      //strcat (buff, "static ");

    }

  if (isstatic_extern == 2)
    {
      return;
    }



  if (lvl && 0)
    {
      printc ("%-18s%s\n", varstring, buff);
    }
  else
    {
      printc ("DEFINE%s %s%s%s;\n", globalstr, varstring, buff,globaldef);
    }
}

/**
 * Print in the 4gl generated file the begining of declaration of a record
 * implementation.
 *
 * @param isstatic_extern The storage class used:
 *   - 1 : Static
 *   - 2 : Extern
 *   - Otherwise : Not static and not extern
 * @param varname The record variable name. Not used
 */
static void
print_start_record (int isstatic_extern, char *varname, struct variable *v, int level)
{
  char buff[20] = "";

  if (isstatic_extern == 1)
    strcat (buff, "static ");

  if (isstatic_extern == 2)
    {

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

  if (level == 0)
    {
      need_daylight ();		//printc ("#");
      if (v->arr_subscripts.arr_subscripts_len)
	{
	  char arrbuff[256];
	  A4GL_yyerror ("Can't use arrays in SPL");
	  return;

	  //make_arr_str (arrbuff, v);
	  //printc ("DEFINE %s ARRAY[%s] OF RECORD \n", varname, arrbuff);
	}
      else
	{
	  record_headers[level] = strdup (varname);
	  //printc ("DEFINE %s RECORD \n", varname);
	}
    }
  else
    {
      if (v->arr_subscripts.arr_subscripts_len)
	{
	  char arrbuff[256];
	  A4GL_yyerror ("Can't use arrays in SPL");
	  return;
	  //make_arr_str (arrbuff, v);
	  //printc ("%s ARRAY[%s] OF RECORD \n", varname, arrbuff);
	}
      else
	{
	  record_headers[level] = strdup (varname);
	  //printc ("%s RECORD \n", varname);
	}
    }
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
  //int arrsizes[10];
  //printc ("END RECORD\n");
  need_daylight ();		//printc ("#");
}



static void
print_Constant_1 (char *name, struct constant_data *c)
{
  switch (c->consttype)
    {
    case CONST_TYPE_CHAR:
      printc ("DEFINE %s CONSTANT %s", name, c->constant_data_u.data_c);
      break;
    case CONST_TYPE_IDENT:
      printc ("DEFINE %s CONSTANT %s", name, c->constant_data_u.data_ident);
      break;
    case CONST_TYPE_INTEGER:
      printc ("DEFINE %s CONSTANT %d", name, c->constant_data_u.data_i);
      break;
    case CONST_TYPE_FLOAT:
      printc ("DEFINE %s CONSTANT %lf", name, c->constant_data_u.data_f);
      break;

    }
}


static void
print_variable_new_internal (struct variable *v, enum e_scope scope, int level, int vno)
{
  int static_extern_flg;
  char name[256];
  static_extern_flg = 0;
  A4GL_assertion (v == 0, "No variable to print");

  if (strcasecmp (v->names.names.names_val[0].name, "int_flag") == 0)
    {
      // Ignore all system variables
      return;
    }

  // ASK - added ignore SQLCODE for SPL
  if (strcasecmp (v->names.names.names_val[0].name, "sqlcode") == 0)
    {
      // Ignore all system variables
      return;
    }

  //strcpy (arrbuff, "-1");


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

/*
  if (v->arr_subscripts.arr_subscripts_len)
    {
      make_arr_str (arrbuff, v);
    }
  else
    {
      strcpy (arrbuff, "-1");
    }
*/



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

	  if (v->is_static == 1)
	    {
	      static_extern_flg += 1;
	    }
	}
    }

  if (scope == 'M')
    {
      sprintf (name, "M%s__%s", curr_module->module_name, v->names.names.names_val[0].name);
    }
  else
    {
      strcpy (name, v->names.names.names_val[0].name);
    }

  if (v->var_data.variable_type == VARIABLE_TYPE_SIMPLE)
    {
      char tmpbuff[256] = "";
      char stmpbuff[256] = "";
      char *s;
      int a;

      sprintf (stmpbuff, "%s", name);


      for (a = 0; a < level; a++)
	{
	  if (strlen (tmpbuff))
	    {
	      strcat (tmpbuff, "_");
	    }
	  strcat (tmpbuff, record_headers[a]);
	}


      if (strlen (tmpbuff))
	{
	  strcat (tmpbuff, "_");
	}


      strcat (tmpbuff, stmpbuff);

      if (v->arr_subscripts.arr_subscripts_len)
	{
	  A4GL_yyerror ("Can't use arrays in SPL");
	  return;
	}


      s = irettype_integer (v->defsrc, v->var_data.variable_data_u.v_simple.datatype);
      switch (v->var_data.variable_data_u.v_simple.datatype & DTYPE_MASK)
	{

	case DTYPE_DECIMAL:
	  if (strstr (s, "LIKE"))
	    {
	      sprintf (stmpbuff, " %s", s);
	    }
	  else
	    {
	      sprintf (stmpbuff, " %s(%d,%d)", s, v->var_data.variable_data_u.v_simple.dimensions[0] >> 8,
		       v->var_data.variable_data_u.v_simple.dimensions[0] & 255);
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
	      sprintf (stmpbuff, " %s %s TO %s", s,
		       decode_dt (v->var_data.variable_data_u.v_simple.
				  dimensions[0], 1), decode_dt (v->var_data.variable_data_u.v_simple.dimensions[0], 2));

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
	      sprintf (stmpbuff, " INTERVAL %s TO %s",
		       decode_ival_define1 (v->var_data.variable_data_u.
					    v_simple.dimensions[0]),
		       decode_ival_define2 (v->var_data.variable_data_u.v_simple.dimensions[0]));
	    }
	  strcat (tmpbuff, stmpbuff);
	  break;



	default:
	  SPRINTF1 (stmpbuff, " %s", irettype_integer (v->defsrc, v->var_data.variable_data_u.v_simple.datatype));
	  strcat (tmpbuff, stmpbuff);
	}



      if (v->var_data.variable_data_u.v_simple.datatype == DTYPE_CHAR
	  || v->var_data.variable_data_u.v_simple.datatype == DTYPE_VCHAR)
	{			/* Its a 'char' (may need varchar & friends too... */


	  if (v->var_data.variable_data_u.v_simple.datatype == DTYPE_CHAR)
	    {

	      print_define_char (tmpbuff,
				 v->var_data.variable_data_u.v_simple.dimensions[0], static_extern_flg, level, vno, v->defsrc,
				 scope);
	    }
	  else
	    {
	      print_define_char (tmpbuff, v->var_data.variable_data_u.v_simple.dimensions[0], static_extern_flg, level, vno, v->defsrc, scope);	// Allow extra space to store the size...
	    }
	}
      else
	{
	  print_define (tmpbuff, static_extern_flg, level, vno, scope);
	}

      return;
    }

  if (v->var_data.variable_type == VARIABLE_TYPE_RECORD || v->var_data.variable_type == VARIABLE_TYPE_OBJECT)
    {
      int a;
      if (strcmp (name, "a4gl_sqlca") != 0)
	{
	  print_start_record (static_extern_flg, name, v, level);
	  for (a = 0; a < v->var_data.variable_data_u.v_record.variables.variables_len; a++)
	    {
	      struct variable *next_v;
	      next_v = v->var_data.variable_data_u.v_record.variables.variables_val[a];
	      print_variable_new_internal (next_v, scope, level + 1,
					   a != v->var_data.variable_data_u.v_record.variables.variables_len - 1);
	    }
	  print_end_record (name, v, level);
	  //if (vno) printc (",");
	}
      return;
    }

  if (v->var_data.variable_type == VARIABLE_TYPE_ASSOC)
    {
      struct variable v2;
      char buff1[20];
      char buff2[20];
      not_in_spl ();
      return;
    }

  if (v->var_data.variable_type == VARIABLE_TYPE_CONSTANT)
    {

      not_in_spl ();
      return;
    }


}






/******************************************************************************/
static void
print_variable_new (struct variable *v, enum e_scope scope, int level)
{
  dump_comments (v->lineno);
  //printf("Dump comments up to %d\n", v->lineno);
  print_variable_new_internal (v, scope, level, 0);
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
  //char *ptr;
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
  strcat (filename_outfile, ".sql");

  if (override)
    {
      strcpy (filename_outfile, override);
    }

  strcat (filename_for_c, ".splt");
  strcat (filename_for_h, ".splh");

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

  hfile = A4GL_mja_fopen (filename_for_h, "wb");
  strcpy (filename_hfile, filename_for_h);
  if (hfile == 0)
    {
      printf ("Unable to open file %s (Check permissions)\n", filename_for_h);
      exit (3);
    }

}


static char *
get_orig_from_clobber (char *s)
{
  int a;
  for (a = 0; a < curr_module->clobberings.clobberings_len; a++)
    {
      if (strcmp (curr_module->clobberings.clobberings_val[a].newval, s) == 0)
	{
	  return curr_module->clobberings.clobberings_val[a].important;
	}
    }
  return s;
}

int
LEXLIB_A4GL_write_generated_code (struct module_definition *m)
{
  int a;
  int mentry;
  curr_module = m;

  open_outfile ();

  A4GL_debug ("Dump 1");
  dump_comments (1);

/*
  for (a = 0; a < m->global_files->str_list_entry.str_list_entry_len; a++)
    {
      printc ("GLOBALS \"%s.4gl\"", m->global_files->str_list_entry.str_list_entry_val[a]);
    }

  if (m->exported_global_variables.variables.variables_len)
    {
      printc ("GLOBALS");
      tmp_ccnt++;
      for (a = 0; a < m->exported_global_variables.variables.variables_len; a++)
	{
	  print_variable_new (m->exported_global_variables.variables.variables_val[a], 'g', 0);
	}
      tmp_ccnt--;
      printc ("END GLOBALS");
    }
  if (ui_as_calls ())
    {
      printc ("DEFINE gc_arr_cnt INTEGER");
    }
  A4GL_debug ("Dump 2");
*/

  A4GL_debug ("Dump 3");

  for (mentry = 0; mentry < m->module_entries.module_entries_len; mentry++)
    {
      int ok = 1;

      current_entry = m->module_entries.module_entries_val[mentry];

      switch (m->module_entries.module_entries_val[mentry]->met_type)
	{

	case E_MET_REPORT_DEFINITION:
	  not_in_spl ();
	  continue;
	  //ok = dump_report (&m->module_entries.module_entries_val[mentry]->module_entry_u.report_definition);
	  //break;
	case E_MET_PDF_REPORT_DEFINITION:
	  not_in_spl ();
	  continue;
	  //ok = dump_pdf_report (&m->module_entries.module_entries_val[mentry]->module_entry_u.pdf_report_definition);
	  //break;

	case E_MET_CMD:
	  not_in_spl ();
	  continue;

	case E_MET_MAIN_DEFINITION:
	  not_in_spl ();
	  continue;
	  //ok = dump_function (&m->module_entries.module_entries_val[mentry]->module_entry_u.function_definition, 1);
	  //break;

	case E_MET_FUNCTION_DEFINITION:
	  ok = dump_function (&m->module_entries.module_entries_val[mentry]->module_entry_u.function_definition, 0);
	  break;

	default:
	  A4GL_assertion (1, "dumping Not implemented");
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
  A4GL_debug ("Dump 6");
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

void
dump_comments (int n)
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


      switch (type)
	{
	case '-':
	  if (ptr[0] == '@')
	    {
	      strcpy (buff, "-- ");
	    }
	  else
	    {
	      strcpy (buff, "--");
	    }
	  break;
	case '{':
	  strcpy (buff, "{");
	  in_multi++;
	  break;
	case '}':
	  strcpy (buff, "}");
	  if (!in_multi)
	    {
	      strcpy (buff, "{}");
	    }
	  else
	    {
	      in_multi--;
	    }
	  break;

	case '#':
	  strcpy (buff, "--");
	  break;

	case '.':
	  strcpy (buff, "");
	  break;
	default:
	  sprintf (buff, "-- (%c)", type);
	  break;
	}
      //}

      printed++;
      if (strlen (ptr) > 1 && buff[0] == '{')
	{
	  char *p;
	  p = strdup (ptr);
	  //A4GL_lrtrim(p);
	  need_daylight ();	////printc ("#");
	  if (outfile)
	    FPRINTF (outfile, "{\n");
	  //printc ( "{\n", buff,p);
	  free (p);
	}
      else
	{
	  char *p;
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

static char *
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



static char *
get_variable_usage_1 (struct variable_usage *var_usage, int lvl)
{
  char buff[20000];
  char *l;



  if (strcmp (var_usage->variable_name, "a4gl_sqlca") == 0)
    {
      sprintf (buff, "sqlca");
    }
  else
    {
      if (strcmp (var_usage->variable_name, "a4gl_status") == 0)
	{
	  sprintf (buff, "SQLCODE");
	}
      else
	{
	  if (var_usage->escope == E_SCOPE_MODULE && lvl == 0)
	    {
	      sprintf (buff, "M%s__%s", curr_module->module_name, var_usage->variable_name);
	    }
	  else
	    {
	      sprintf (buff, "%s", var_usage->variable_name);
	    }
	}
    }
  if (var_usage->subscripts.subscripts_len)
    {
      int a;
      A4GL_yyerror ("Can't use arrays in SPL");
    }

  if (var_usage->substrings_start)
    {
      l = local_get_expr_as_string (var_usage->substrings_start);
      strcat (buff, "[");
      strcat (buff, l);
      free (l);
      if (var_usage->substrings_end)
	{
	  strcat (buff, ",");
	  l = local_get_expr_as_string (var_usage->substrings_end);
	  strcat (buff, l);
	  free (l);
	}
      strcat (buff, "]");
    }

  if (var_usage->next)
    {
      char *p;
      strcat (buff, "_");
      p = get_variable_usage_1 (var_usage->next, lvl + 1);
      strcat (buff, p);
      free (p);
    }
  return strdup (buff);
}

static char *
get_variable_usage (struct variable_usage *var_usage)
{
  return get_variable_usage_1 (var_usage, 0);
}

static void
print_variable_usage (struct variable_usage *var_usage)
{
  char *l;
  l = get_variable_usage (var_usage);

  printc ("%s", l);

  free (l);
}



static void
print_var_usage (struct variable_usage *var_usage, char dir, int no)
{
  print_variable_usage (var_usage);
}

static void
print_varbind (expr_str * var_usage, char dir, int no)
{
  if (var_usage->expr_type == ET_EXPR_VARIABLE_USAGE)
    {
      print_var_usage (var_usage->expr_str_u.expr_variable_usage, dir, no);
    }
  else
    {
      real_print_expr (var_usage);
    }
}


static int
dump_cmds (struct commands *c, struct command *parent)
{
  int a;
  if (c == 0)
    return 1;

  command_nest[command_nest_cnt] = parent;
  command_nest_cnt++;

  if (c->cmds.cmds_len > 1 || A4GL_isyes (acl_getenv ("TRACESPL")))
    {
      printc ("BEGIN");
      tmp_ccnt++;
    }


  for (a = 0; a < c->cmds.cmds_len; a++)
    {
      if (!dump_cmd (c->cmds.cmds_val[a], parent))
	return 0;
    }

  if (c->cmds.cmds_len > 1 || A4GL_isyes (acl_getenv ("TRACESPL")))
    {
      tmp_ccnt--;
      printc ("END");
    }

  command_nest_cnt--;
  A4GL_assertion (command_nest_cnt < 0, "command_nest_cnt corrupted");
  command_nest[command_nest_cnt] = 0;
  return 1;
}


static char *
get_spl_dtype (int dtype)
{
  int dtype_sz;
  static char buff_dtype[200];
  dtype_sz = dtype >> 16;
  dtype = dtype & 0xffff;

  switch (dtype)
    {
    case DTYPE_CHAR:
      sprintf (buff_dtype, "CHAR(%d)", dtype_sz);
      break;
    case DTYPE_VCHAR:
      sprintf (buff_dtype, "VARCHAR(%d)", dtype_sz);
      break;
    case DTYPE_INT:
      sprintf (buff_dtype, "INTEGER");
      break;
    case DTYPE_SMINT:
      sprintf (buff_dtype, "SMALLINT");
      break;
    case DTYPE_DATE:
      sprintf (buff_dtype, "DATE");
      break;
    case DTYPE_FLOAT:
      sprintf (buff_dtype, "FLOAT");
      break;
    case DTYPE_SMFLOAT:
      sprintf (buff_dtype, "SMALLFLOAT");
      break;

    case DTYPE_DECIMAL:
      sprintf (buff_dtype, " DECIMAL(%d,%d)", dtype_sz >> 8, dtype_sz & 255);
      break;

    case DTYPE_DTIME:
      sprintf (buff_dtype, " DATETIME %s TO %s", decode_dt (dtype_sz, 1), decode_dt (dtype_sz, 2));
      break;

    case DTYPE_INTERVAL:
      sprintf (buff_dtype, " INTERVAL %s TO %s", decode_ival_define1 (dtype_sz), decode_ival_define2 (dtype_sz));
      break;


    default:
      printf ("Unhandled define in module variable removal... variable dtype : %d (%x)\n", dtype, dtype);
      A4GL_assertion (1, "Unhandled define in module variable removal...");

    }


  return buff_dtype;

}


static void
print_spl_dtype (int dtype)
{
  printc ("%s", get_spl_dtype (dtype));
}



static char *
get_dump_function_returning (struct s_function_definition *function_definition)
{
  struct commands *func_cmds = 0;
  struct command *r;
  int dtypes_new[MAX_RETURN_VALUES];
  int dtypes_cur[MAX_RETURN_VALUES];
  int a;
  int have_return = 0;
  int nreturns;
  int n;
  static char buff[20000];

  strcpy (buff, "");

  for (n = 0; n < MAX_RETURN_VALUES; n++)
    {
      dtypes_new[n] = -1;
      dtypes_cur[n] = -1;
    }

  func_cmds = linearise_commands (0, 0);

  linearise_commands (func_cmds, function_definition->func_commands);
  nreturns = 0;

  for (a = 0; a < func_cmds->cmds.cmds_len; a++)
    {
      r = func_cmds->cmds.cmds_val[a];

      if (r->cmd_data.type == E_CMD_RETURN_CMD)
	{
	  for (n = 0; n < MAX_RETURN_VALUES; n++)
	    {
	      dtypes_new[n] = -1;
	    }

	  if (r->cmd_data.command_data_u.return_cmd.retvals)
	    {
	      int b;
	      nreturns = r->cmd_data.command_data_u.return_cmd.retvals->list.list_len;
	      if (nreturns >= MAX_RETURN_VALUES)
		{
		  yylineno = r->lineno;
		  A4GL_yyerror ("Too many return values");
		  return;
		}
	      for (b = 0; b < nreturns; b++)
		{
		  dtypes_new[b] = expr_datatype (r->module,r->lineno, r->cmd_data.command_data_u.return_cmd.retvals->list.list_val[b]);
		  if (dtypes_new[b] == FAKE_DTYPE_BOOL)
		    {		// always return a int instead..
		      dtypes_new[b] = DTYPE_INT;
		    }
		}
	    }


	  if (have_return)
	    {
	      // Lets compare :-)
	      int n;
	      for (n = 0; n < MAX_RETURN_VALUES; n++)
		{
		  if (dtypes_new[n] != dtypes_cur[n])
		    {
		      yylineno = r->lineno;
		      a4gl_yyerror ("Return types differ");
		      return;
		    }
		}
	    }
	  else
	    {
	      memcpy (dtypes_cur, dtypes_new, sizeof (dtypes_cur));
	    }

	}
    }

  if (nreturns)
    {
      strcpy (buff, " RETURNING ");
      for (n = 0; n < nreturns; n++)
	{
	  if (n)
	    strcat (buff, ",");
	  strcat (buff, get_spl_dtype (dtypes_cur[n]));
	}
      strcat (buff, ";");
    }
  return buff;
}



char *
tr_dot_to_underscore (char *s)
{
  static char buff[2000];
  char *ptr;
  strcpy (buff, s);
  while (1)
    {
      ptr = strchr (buff, '.');
      if (ptr == 0)
	break;
      *ptr = '_';
    }

  return buff;
}



static int
dump_function (struct s_function_definition *function_definition, int ismain)
{

  int a;
  char *returning;
  expr_str_list *function_parameters = NULL;
  printc ("#");
  printc ("#");
  printc ("#");
  dump_comments (function_definition->lineno);

  when_set_to_call = 0;

  if (ismain || strcmp (function_definition->funcname, "MAIN") == 0)
    {
      A4GL_assertion (1, "Not expecting a 'MAIN'");
    }


  set_nonewlines ();

  returning = get_dump_function_returning (function_definition);

  if (strlen (returning))
    {
      // It returns somethings
      printc ("CREATE PROCEDURE %s (", function_definition->funcname);
    }
  else
    {
      printc ("CREATE PROCEDURE %s (", function_definition->funcname);
    }

  if (function_definition->parameters)
    {
      function_parameters = expand_parameters (&function_definition->variables, function_definition->parameters);

      //int skipped;
      //char isrec[256] = "";
      for (a = 0; a < function_definition->parameters->list.list_len; a++)
	{
	  if (a)
	    printc (",");

	  printc ("In_%s %s",
		  tr_dot_to_underscore (get_variable_usage (function_parameters->list.list_val[a]->expr_str_u.expr_variable_usage)),
		  get_spl_dtype (get_binding_dtype (function_parameters->list.list_val[a])));
	}
    }
  printc (")");

  printc ("%s", returning);

  clr_nonewlines ();

// local variables...

  if (function_definition->variables.variables.variables_len)
    {
      for (a = 0; a < function_definition->variables.variables.variables_len; a++)
	{
	  print_variable_new (function_definition->variables.variables.variables_val[a], 'L', 0);
	}
    }


  if (curr_module->module_variables.variables.variables_len)
    {
      for (a = 0; a < curr_module->module_variables.variables.variables_len; a++)
	{
	  print_variable_new (curr_module->module_variables.variables.variables_val[a], 'M', 0);
	}
    }


  tmp_ccnt++;

  need_daylight ();		//printc ("#");

  if (function_parameters)
    {

      printc ("-- #####################################");
      printc ("-- Copy parameters into real variables");

      for (a = 0; a < function_parameters->list.list_len; a++)
	{
	  printc ("LET %s=In_%s;",
		  tr_dot_to_underscore (get_variable_usage (function_parameters->list.list_val[a]->expr_str_u.expr_variable_usage)),
		  tr_dot_to_underscore (get_variable_usage
					(function_parameters->list.list_val[a]->expr_str_u.expr_variable_usage)));
	}
      printc ("-- #####################################");
    }


  if (A4GL_isyes (acl_getenv ("TRACESPL")))
    {
      printc ("TRACE     \"In function %s\";", function_definition->funcname);
    }


  if (function_definition->func_commands)
    {
      for (a = 0; a < function_definition->func_commands->cmds.cmds_len; a++)
	{
	  dump_cmd (function_definition->func_commands->cmds.cmds_val[a], 0);
	}
    }

  dump_comments (function_definition->lastlineno);

  tmp_ccnt--;
  need_daylight ();		//printc ("#");
  if (tmp_ccnt)
    {
      A4GL_assertion (1, "tmp_ccnt shouldn't be set...");
    }
  if (nonewlines)
    {
      A4GL_assertion (1, "nonewlines shouldn't be set...");
    }
  if (A4GL_isyes (acl_getenv ("TRACESPL")))
    {
      printc ("TRACE \"END FUNCTION\";");
    }


  if (strlen (returning))
    {
      printc ("END PROCEDURE");
    }
  else
    {
      printc ("END PROCEDURE");
    }

  return 1;
}

/**********************************************************************/
/* EVENT HANDLING */
/**********************************************************************/
static int
chk_context (int cnt)
{
  if (strlen (last_context[cnt]))
    {
      char buff[256];
      sprintf (buff, "Expecting last context to be blank: %d - %s", cnt, last_context[cnt]);
      fprintf (stderr, "%s", buff);
      exit (20);
      //a4gl_yyerror (buff);
      return 0;
    }
  return 1;
}







/**********************************************************************/
/* COMMAND HANDLING */
/**********************************************************************/

static struct variable *
find_top_var (struct expr_str *se)
{
  int a;
  char buff1[2000];
  char *ptr;
  char buff2[2000];
  char *s;
  strcpy (buff1, local_get_expr_as_string (se));

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

  if (current_entry)
    {
      struct variable_list *vl = 0;
      switch (current_entry->met_type)
	{
	case E_MET_REPORT_DEFINITION:
	  vl = &current_entry->module_entry_u.report_definition.variables;
	  break;
	case E_MET_PDF_REPORT_DEFINITION:
	  vl = &current_entry->module_entry_u.pdf_report_definition.variables;
	  break;
	case E_MET_MAIN_DEFINITION:
	  vl = &current_entry->module_entry_u.function_definition.variables;
	  break;
	case E_MET_FUNCTION_DEFINITION:
	  vl = &current_entry->module_entry_u.function_definition.variables;
	  break;

	}
      for (a = 0; a < vl->variables.variables_len; a++)
	{
	  if (strcmp (buff1, vl->variables.variables_val[a]->names.names.names_val[0].name) == 0)
	    {			// Found it...
	      return vl->variables.variables_val[a];
	    }
	}
    }

  for (a = 0; a < curr_module->module_variables.variables.variables_len; a++)
    {
      if (strcmp (buff1, curr_module->module_variables.variables.variables_val[a]->names.names.names_val[0].name) == 0)
	{			// Found it...
	  return curr_module->module_variables.variables.variables_val[a];
	}
    }

  for (a = 0; a < curr_module->exported_global_variables.variables.variables_len; a++)
    {
      if (strcmp (buff1, curr_module->exported_global_variables.variables.variables_val[a]->names.names.names_val[0].name) == 0)
	{			// Found it...
	  return curr_module->exported_global_variables.variables.variables_val[a];
	}
    }


  for (a = 0; a < curr_module->imported_global_variables.variables.variables_len; a++)
    {
      if (strcmp (buff1, curr_module->imported_global_variables.variables.variables_val[a]->names.names.names_val[0].name) == 0)
	{			// Found it...
	  return curr_module->imported_global_variables.variables.variables_val[a];
	}
    }

  return 0;
}





static void
print_insert_cmd (struct struct_insert_cmd *insertCmd)
{
  print_connid (insertCmd->connid);
  current_stmt_table = insertCmd->table;
  set_nonewlines ();
  printc ("INSERT INTO %s", insertCmd->table);
  if (insertCmd->column_list)
    {
      printc ("(");
      real_print_str_list_with_separator (insertCmd->column_list, ",");
      printc (")");
    }
  clr_nonewlines ();

  // Collect all our inbinds..
  if (insertCmd->value_list)
    {
      search_variables (insertCmd->value_list);
    }
  else
    {
      preprocess_sql_statement (insertCmd->subselect);
      search_variables (&insertCmd->subselect->list_of_items);
    }

  if (insertCmd->value_list)
    {
      tmp_ccnt++;
      set_nonewlines ();
      printc (" VALUES (");
      real_print_select_list_item_list_with_separator (NULL, insertCmd->value_list, ",");
      printc (")");
      clr_nonewlines ();
      tmp_ccnt--;
    }
  else
    {
      print_select (insertCmd->subselect, "");
    }
}



/**
 * The parser found a LET 4gl statement and implements the C code for it.
 *
 * @param nexprs The number of variable to be assigned.
 */
static int
print_let_manyvars_g (expr_str_list * expr_list, expr_str_list * varlist)
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

      if (scope == 'm' && A4GL_isyes (acl_getenv ("REMOVEMODVARS")))
	{

	  //printc("{SCOPE=%c remove=%s varname=%s}\n",scope, acl_getenv("REMOVEMODVARS"), varlist->bindings.bindings_val[0].varname);
	  printc ("CALL ");
	  print_varbind (varlist->list.list_val[0], 'W', 0);
	  real_print_expr_list_with_separator (expr_list, "||");
	  printc (")");
	}
      else
	{
	  printc ("LET ");
	  print_varbind (varlist->list.list_val[0], 'w', 0);
	  printc ("=");
	  real_print_expr_list_with_separator (expr_list, ",");
	}
      printc (";");
      clr_nonewlines ();
      return 0;
    }

  for (a = 0; a < to_vars; a++)
    {
      enum e_scope scope;

      //scope = get_var_expr_scope (varlist->list.list_val[a]);
      //printc("{ SCOPE =%c REMOVEMODVARS=%s varname=%s bindscope=%c}", scope, acl_getenv ("REMOVEMODVARS"),varlist->bindings.bindings_val[a].varname , varlist->bindings.bindings_val[a].scope);
      scope = get_var_expr_scope (varlist->list.list_val[a]);
      set_nonewlines ();
      printc ("LET ");
      print_varbind (varlist->list.list_val[a], 'w', a);
      printc ("=");
      if (expr_list)
	{
	  real_print_expr (expr_list->list.list_val[a]);
	}
      else
	{
	  printc ("NULL");
	}
      printc (";");
      clr_nonewlines ();
    }
  return 1;
}


static int
chk_for_inner_while (int n)
{
  int z;
  char *s;
  int ccnt;

  return 0;

#ifdef FIXME
  ccnt = A4GL_get_ccnt ();

  for (z = ccnt; z >= n; z--)
    {
      s = command_type_for_stack_pos (z);
      if (strcmp (s, "WHILE") == 0)
	{
	  local_a4gl_yyerror ("Cant handle an inner while");
	  return 1;
	}
    }
  return 0;
#endif
}




static void
print_connid (struct expr_str *e)
{
  if (e)
    {
      printc ("USE SESSION ");
      switch (e->expr_type)
	{
	case ET_EXPR_IDENTIFIER:
	  printc ("%s", e->expr_str_u.expr_string);
	  break;
	default:
	  A4GL_assertion (1, "Can't use anything for a session except ET_EXPR_IDENTIFIER atm");
	}
      printc (" FOR ");
    }
}


/**
 * Print the C instruction that implements the specific continue loop.
 *
 * The loop(s) are implemented with while(s), label(s) and goto(s) in C
 *
 * @param n The loop number
 */
static void
print_continue_loop (int n, char *cmd_type)
{

  printc ("CONTINUE %s;", cmd_type);
  return;

}


/**
 * Print the C instruction that implements the specific exit loop.
 *
 * Some loop(s) are implemented with while(s) label(s) and goto(s) in C.
 * Menu is implemented with a while and switch
 * The prompt is implemented with while
 * There are one label in the begining and one at the end.
 *
 * @param type The loop type:
 *   - M : Menu
 *   - P : Prompt
 *   - 0 : Other loop type
 * @param n The loop number
 */
static void
print_exit_loop (int type, int n, char *cmdtype)
{

  if (type == 0)
    {
      printc ("EXIT %s;", cmdtype);
    }
}



static int
dump_cmd (struct command *r, struct command *parent)
{
  int a;
  static int last_command_type = -1;
  static command *last_parent = (void *) -1;

  A4GL_assertion (r->module == 0, "No module");
  //printf ("Dumping command type : %d (%s %d)\n", r->cmd_data.type, r->module, r->lineno);
  A4GL_debug ("Dumping command type : %d (%s %d)\n", r->cmd_data.type, r->module, r->lineno);

  if (last_parent != parent)
    {
      last_command_type = r->cmd_data.type;
      last_parent = parent;
      //need_daylight();
    }
  else
    {
      if (last_command_type != r->cmd_data.type)
	{
	  need_daylight ();
	  last_command_type = r->cmd_data.type;
	}
    }


  curr_yylineno = r->lineno;
  A4GL_set_sql_lineno (r->lineno);

  dump_comments (r->lineno);

  if (A4GL_isyes (acl_getenv ("TRACESPL")))
    {
      if (r->cmd_data.type == E_CMD_IF_CMD || r->cmd_data.type == E_CMD_WHILE_CMD || r->cmd_data.type == E_CMD_LET_CMD);
      else
	{
	  printc ("TRACE \"%s Line %d\";", r->module, r->lineno);
	}
    }



  switch (r->cmd_data.type)
    {

    case E_CMD_CURRENT_WIN_CMD:
    case E_CMD_OUTPUT_CMD:
    case E_CMD_LINT_IGNORE_CMD:
    case E_CMD_LINT_EXPECT_CMD:

    case E_CMD_PAUSE_SCREEN_OFF_CMD:
    case E_CMD_SKIP_TO_TOP_CMD:
    case E_CMD_STOP_RPC_CMD:
    case E_CMD_PAUSE_SCREEN_ON_CMD:
      not_in_spl ();
      return 0;




    case E_CMD_CALL_CMD:
      {
	struct expr_str *ptr;
	int b;
	int params;
	struct expr_str_list *l = 0;
	int nret = 0;

	if (r->cmd_data.command_data_u.call_cmd.returning)
	  {
	    nret = r->cmd_data.command_data_u.call_cmd.returning->list.list_len;
	  }

	if (nret > 1)
	  need_daylight ();
	if (r->cmd_data.command_data_u.call_cmd.fcall->expr_type == ET_EXPR_FCALL)
	  {
	    if (A4GL_isyes (acl_getenv ("TRACESPL")))
	      {
		printc ("TRACE \"CALL %s\";", r->cmd_data.command_data_u.call_cmd.fcall->expr_str_u.expr_function_call->fname);
	      }
	  }
	set_nonewlines ();
	printc ("CALL ");

	//real_print_expr (r->cmd_data.command_data_u.call_cmd.fcall);
	b = 0;

	ptr = r->cmd_data.command_data_u.call_cmd.fcall;
	switch (r->cmd_data.command_data_u.call_cmd.fcall->expr_type)
	  {
	  case ET_EXPR_FCALL:
	    if (ptr)
	      {
		l = ptr->expr_str_u.expr_function_call->parameters;
		l = A4GL_rationalize_list (l);
	      }

	    //params = A4GL_new_list_get_count (ptr->expr_str_u.expr_function_call->parameters);
	    printc ("%s(", map_fname (ptr->expr_str_u.expr_function_call->fname));
	    if (l)
	      {
		int a;
		for (a = 0; a < l->list.list_len; a++)
		  {
		    if (a)
		      printc (",");
		    real_print_expr (l->list.list_val[a]);
		  }
	      }
	    printc (")");
	    break;



	  default:
	    A4GL_assertion (1, "Can't handle it..");
	  }


	if (r->cmd_data.command_data_u.call_cmd.returning)
	  {
	    if (r->cmd_data.command_data_u.call_cmd.returning->list.list_len)
	      {
		enum e_scope scope;
		int used_tmp;
		struct expr_str_list *l;
		l = r->cmd_data.command_data_u.call_cmd.returning;

		if (nret > 1)
		  {
		    clr_nonewlines ();
		    set_nonewlines ();
		  }
		printc (" RETURNING ");
		used_tmp = 0;

		/* l=expand_variables_in_expr_str_list(l, 1); */
		for (a = 0; a < l->list.list_len; a++)
		  {
		    if (a)
		      printc (",");

		    scope = get_var_expr_scope (l->list.list_val[a]);

		    print_varbind (l->list.list_val[a], 'r', a);
		  }
		clr_nonewlines ();
	      }
	    else
	      {
		clr_nonewlines ();
	      }
	  }
	else
	  {
	    clr_nonewlines ();
	  }
	if (nret > 1)
	  need_daylight ();
      }
      break;

    case E_CMD_CANCEL_CMD:
      not_in_spl ();
      return 0;


    case E_CMD_CASE_CMD:

      need_daylight ();		//printc ("#");


      if (xps)
	{
	  if (r->cmd_data.command_data_u.case_cmd.case_expr)
	    {
	      set_nonewlines ();
	      printc ("CASE ");
	      real_print_expr (r->cmd_data.command_data_u.case_cmd.case_expr);
	      clr_nonewlines ();
	    }
	  else
	    {
	      printc ("CASE");
	    }
	  tmp_ccnt++;
	  for (a = 0; a < r->cmd_data.command_data_u.case_cmd.whens->whens.whens_len; a++)
	    {
	      need_daylight ();
	      set_nonewlines ();
	      printc ("WHEN ");
	      real_print_expr (r->cmd_data.command_data_u.case_cmd.whens->whens.whens_val[a]->when_expr);
	      printc (" THEN ");
	      clr_nonewlines ();
	      tmp_ccnt++;
	      dump_cmds (r->cmd_data.command_data_u.case_cmd.whens->whens.whens_val[a]->when_commands, r);
	      tmp_ccnt--;
	    }

	  if (r->cmd_data.command_data_u.case_cmd.otherwise)
	    {
	      need_daylight ();
	      printc ("OTHERWISE");
	      tmp_ccnt++;
	      dump_cmds (r->cmd_data.command_data_u.case_cmd.otherwise, r);
	      tmp_ccnt--;
	    }

	  tmp_ccnt--;
	  need_daylight ();
	  printc ("END CASE");
	  need_daylight ();
	} else {

	/*
          if (r->cmd_data.command_data_u.case_cmd.case_expr)
            {
              set_nonewlines ();
              printc ("IF ");
              real_print_expr (r->cmd_data.command_data_u.case_cmd.case_expr);
              clr_nonewlines ();
            }
          else
            {
              printc ("CASE");
            }
	*/

          for (a = 0; a < r->cmd_data.command_data_u.case_cmd.whens->whens.whens_len; a++)
            {
              need_daylight ();
              set_nonewlines ();
		if (a) {
          		tmp_ccnt--;
              		printc ("ELIF ");
          		tmp_ccnt++;
		} else {
              		printc ("IF ");
          		tmp_ccnt++;
		}
	if (r->cmd_data.command_data_u.case_cmd.case_expr) {
              real_print_expr (r->cmd_data.command_data_u.case_cmd.case_expr);
		printc("=");
	}
              real_print_expr (r->cmd_data.command_data_u.case_cmd.whens->whens.whens_val[a]->when_expr);
              printc (" THEN ");
              clr_nonewlines ();
              tmp_ccnt++;
              dump_cmds (r->cmd_data.command_data_u.case_cmd.whens->whens.whens_val[a]->when_commands, r);
              tmp_ccnt--;
            }

          if (r->cmd_data.command_data_u.case_cmd.otherwise)
            {
              need_daylight ();
              printc ("ELSE");
              tmp_ccnt++;
              dump_cmds (r->cmd_data.command_data_u.case_cmd.otherwise, r);
              tmp_ccnt--;
            }

          tmp_ccnt--;
          need_daylight ();
          printc ("END IF;");
          need_daylight ();


	}
      need_daylight ();		//printc ("#");

      break;

    case E_CMD_CLOSE_CMD:
      not_in_spl ();
      return 0;


    case E_CMD_CLOSE_SQL_CMD:
      switch (r->cmd_data.command_data_u.close_cmd.cl_type)
	{
	case E_CT_DATABASE:
	  printc ("CLOSE DATABASE");
	  break;
	case E_CT_SESSION:
	  set_nonewlines ();
	  printc ("CLOSE SESSION ");
	  print_ident (r->cmd_data.command_data_u.close_cmd.ident);
	  clr_nonewlines ();
	  break;
	case E_CT_CURS_OR_PREP:
	  set_nonewlines ();
	  printc ("CLOSE ");
	  print_ident (r->cmd_data.command_data_u.close_cmd.ident);
	  printc (";");
	  clr_nonewlines ();
	  break;
	}
      break;

    case E_CMD_CODE_CMD:
      if (outfile)
	FPRINTF (outfile, "%s", r->cmd_data.command_data_u.code_cmd.contents);
      break;

    case E_CMD_DEFER_CMD:
      not_in_spl ();
      return 0;


    case E_CMD_DISPLAY_CMD:	/* UI */

      not_in_spl ();
      return 0;


    case E_CMD_DISPLAY_FORM_CMD:	/* UI */
      not_in_spl ();
      return 0;
    case E_CMD_ERROR_CMD:
      not_in_spl ();
      return 0;

    case E_CMD_EXT_CMD:
      switch (r->cmd_data.command_data_u.ext_cmd.what)
	{
	case EBC_WHILE:
	  printc ("EXIT WHILE;");
	  break;
	case EBC_FOR:
	  printc ("EXIT FOR;");
	  break;
	case EBC_INPUT:
	  print_exit_loop ('-', r->cmd_data.command_data_u.ext_cmd.block_id, "INPUT");
	  //printc ("EXIT INPUT");
	  break;
	case EBC_FOREACH:
	  printc ("EXIT FOREACH;");
	  break;
	case EBC_CONSTRUCT:
	  print_exit_loop ('-', r->cmd_data.command_data_u.ext_cmd.block_id, "CONSTRUCT");
	  //printc ("EXIT CONSTRUCT");
	  break;
	case EBC_DISPLAY:
	  print_exit_loop ('-', r->cmd_data.command_data_u.ext_cmd.block_id, "DISPLAY");
	  //printc ("EXIT DISPLAY");
	  break;
	case EBC_MENU:
	  print_exit_loop ('M', r->cmd_data.command_data_u.ext_cmd.block_id, "MENU");
	  //printc ("EXIT MENU");
	  break;
	case EBC_PROMPT:
	  print_exit_loop ('P', r->cmd_data.command_data_u.ext_cmd.block_id, "PROMPT");
	  //printc ("EXIT PROMPT");
	  break;
	case EBC_CASE:
	  printc ("EXIT CASE;");
	  break;
	}
      break;

    case E_CMD_CONTINUE_CMD:
      switch (r->cmd_data.command_data_u.ext_cmd.what)
	{
	case EBC_WHILE:
	  printc ("CONTINUE WHILE;");
	  break;
	case EBC_FOR:
	  printc ("CONTINUE FOR;");
	  break;
	case EBC_INPUT:
	  print_continue_loop (r->cmd_data.command_data_u.ext_cmd.block_id, "INPUT");
	  //printc ("CONTINUE INPUT");
	  break;
	case EBC_FOREACH:
	  printc ("CONTINUE FOREACH;");
	  break;

	case EBC_CONSTRUCT:
	  print_continue_loop (r->cmd_data.command_data_u.ext_cmd.block_id, "CONSTRUCT");
	  //printc ("CONTINUE CONSTRUCT");
	  break;
	case EBC_DISPLAY:
	  print_continue_loop (r->cmd_data.command_data_u.ext_cmd.block_id, "DISPLAY");
	  //printc ("CONTINUE DISPLAY");
	  break;
	case EBC_MENU:
	  print_continue_loop (r->cmd_data.command_data_u.ext_cmd.block_id, "MENU");
	  //printc ("CONTINUE MENU");
	  break;
	case EBC_PROMPT:
	  print_continue_loop (r->cmd_data.command_data_u.ext_cmd.block_id, "PROMPT");
	  //printc ("CONTINUE PROMPT");
	  break;
	case EBC_CASE:
	  printc ("CONTINUE CASE;");
	  break;
	}
      break;


    case E_CMD_EXIT_PROG_CMD:
      if (r->cmd_data.command_data_u.exit_prog_cmd.exit_val)
	{
	  set_nonewlines ();
	  printc ("RAISE EXCEPTION ");
	  real_print_expr (r->cmd_data.command_data_u.exit_prog_cmd.exit_val);
	  printc (";");
	  clr_nonewlines ();

	}
      else
	{
	  printc ("RAISE EXCEPTION -706;");
	}
      break;


    case E_CMD_FOR_CMD:
      {
	int need_step = 1;
	int for_var_is_module = 0;
	enum e_scope scope;

	loop_descent_level++;
	need_daylight ();
	//printc ("#");
	set_nonewlines ();
	scope = get_var_expr_scope (r->cmd_data.command_data_u.for_cmd.var);
	printc ("FOR ");
	print_varbind (r->cmd_data.command_data_u.for_cmd.var, 'w', 0);
	printc ("=");
	real_print_expr (r->cmd_data.command_data_u.for_cmd.start);
	printc (" TO ");
	real_print_expr (r->cmd_data.command_data_u.for_cmd.end);
	need_step = 1;
	if (r->cmd_data.command_data_u.for_cmd.step->expr_type == ET_EXPR_LITERAL_LONG)
	  {
	    if (r->cmd_data.command_data_u.for_cmd.step->expr_str_u.expr_long == 1)
	      {
		need_step = 0;
	      }
	  }
	if (need_step)
	  {
	    printc (" STEP ");
	    real_print_expr (r->cmd_data.command_data_u.for_cmd.step);
	  }
	clr_nonewlines ();
	tmp_ccnt++;

	if (for_var_is_module)
	  {
	    printc ("CALL");
	    print_varbind (r->cmd_data.command_data_u.for_cmd.var, 'W', 0);
	    printc ("lv_tmp_%x)", get_var_expr_dtype (r->cmd_data.command_data_u.for_cmd.var));

	  }
	dump_cmds (r->cmd_data.command_data_u.for_cmd.for_commands, r);
	loop_descent_level--;
	tmp_ccnt--;
	printc ("END FOR");
	//printc ("#");
	need_daylight ();
      }
      break;


    case E_CMD_FOREACH_CMD:
      //printc ("#");
      need_daylight ();


      loop_descent_level++;
      need_daylight ();		//printc ("#");
      set_nonewlines ();
      printc ("FOREACH ");
      print_ident (r->cmd_data.command_data_u.foreach_cmd.cursorname);
      clr_nonewlines ();
      if (r->cmd_data.command_data_u.foreach_cmd.inputvals)
	{

	  if (r->cmd_data.command_data_u.foreach_cmd.inputvals->list.list_len)
	    {
	      set_nonewlines ();
	      printc (" USING ");
	      for (a = 0; a < r->cmd_data.command_data_u.foreach_cmd.inputvals->list.list_len; a++)
		{
		  if (a)
		    printc (",");

		  print_varbind (r->cmd_data.command_data_u.foreach_cmd.inputvals->list.list_val[a], 'r', a);
		}
	      clr_nonewlines ();
	    }
	}

      if (r->cmd_data.command_data_u.foreach_cmd.outputvals && r->cmd_data.command_data_u.foreach_cmd.outputvals->list.list_len)
	{
	  int module_var_used = 0;
	  set_nonewlines ();
	  printc (" INTO ");
	  for (a = 0; a < r->cmd_data.command_data_u.foreach_cmd.outputvals->list.list_len; a++)
	    {
	      if (a)
		printc (",");

	      print_varbind (r->cmd_data.command_data_u.foreach_cmd.outputvals->list.list_val[a], 'w', a);
	    }
	  clr_nonewlines ();
	}
      need_daylight ();		//printc ("#");
      tmp_ccnt++;
      dump_cmds (r->cmd_data.command_data_u.foreach_cmd.foreach_commands, r);
      loop_descent_level--;
      tmp_ccnt--;
      need_daylight ();
      printc ("END FOREACH");
      need_daylight ();
      //printc ("#");
      break;



    case E_CMD_FREE_CMD:
      set_nonewlines ();
      printc ("FREE ");
      print_ident (r->cmd_data.command_data_u.free_cmd.cursorname);
      printc (";");
      clr_nonewlines ();
      break;

    case E_CMD_GOTO_CMD:
      printc ("GOTO :%s", r->cmd_data.command_data_u.goto_cmd.label);
      break;

    case E_CMD_IF_CMD:
      need_daylight ();
      for (a = 0; a < r->cmd_data.command_data_u.if_cmd.truths.conditions.conditions_len; a++)
	{
	  set_nonewlines ();
	  if (a == 0)
	    {
	      printc ("IF ");
	    }
	  else
	    {
	      printc ("ELIF ");
	    }
	  real_print_expr (r->cmd_data.command_data_u.if_cmd.truths.conditions.conditions_val[a].test_expr);
	  printc (" THEN");
	  dump_comments (r->cmd_data.command_data_u.if_cmd.truths.conditions.conditions_val[a].lineno);
	  clr_nonewlines ();
	  tmp_ccnt++;
	  //if (A4GL_isyes (acl_getenv ("TRACESPL"))) { printc ("TRACE \"IF statement is TRUE @ %s %d\";", r->module, r->lineno); }
	  dump_cmds (r->cmd_data.command_data_u.if_cmd.truths.conditions.conditions_val[a].whentrue, r);
	  tmp_ccnt--;
	}

      if (r->cmd_data.command_data_u.if_cmd.whenfalse)
	{
	  dump_comments (r->cmd_data.command_data_u.if_cmd.else_lineno);
	  printc ("ELSE");
	  tmp_ccnt++;

	  //if (A4GL_isyes (acl_getenv ("TRACESPL"))) { printc ("TRACE     \"IF statement is FALSE %s %d (ELSE @ %d)\";", r->module, r->lineno, r->cmd_data.command_data_u.if_cmd.lineno); }

	  dump_cmds (r->cmd_data.command_data_u.if_cmd.whenfalse, r);
	  tmp_ccnt--;
	}

      dump_comments (r->cmd_data.command_data_u.if_cmd.lineno);
      printc ("END IF");
      need_daylight ();

      break;

    case E_CMD_LABEL_CMD:
      need_daylight ();
      printc ("LABEL %s:", r->cmd_data.command_data_u.label_cmd.label);
      break;

    case E_CMD_LET_CMD:

      print_let_manyvars_g (r->cmd_data.command_data_u.let_cmd.vals, r->cmd_data.command_data_u.let_cmd.vars);
      break;


    case E_CMD_LOCATE_CMD:
      if (r->cmd_data.command_data_u.locate_cmd.where.where == E_LOC_FILE)
	{
	  for (a = 0; a < r->cmd_data.command_data_u.locate_cmd.variables->list.list_len; a++)
	    {
	      set_nonewlines ();
	      printc ("LOCATE ");
	      print_varbind (r->cmd_data.command_data_u.locate_cmd.variables->list.list_val[a], 'w', a);
	      printc (" IN FILE ");
	      real_print_variable_or_literal (r->cmd_data.command_data_u.locate_cmd.where.locate_pos_u.filename, "");
	      clr_nonewlines ();
	    }
	}

      if (r->cmd_data.command_data_u.locate_cmd.where.where == E_LOC_MEMORY)
	{
	  for (a = 0; a < r->cmd_data.command_data_u.locate_cmd.variables->list.list_len; a++)
	    {
	      printc ("LOCATE ");
	      print_varbind (r->cmd_data.command_data_u.locate_cmd.variables->list.list_val[a], 'w', a);
	      printc (" IN MEMORY");
	    }
	}

      break;

    case E_CMD_RETURN_CMD:
      //returns++;
      /*
         if (returns>1) {
         A4GL_warn("Coding Standards: Multiple RETURNs in function");
         }
       */

      if (A4GL_isyes (acl_getenv ("TRACESPL")))
	{
	  printc ("TRACE \"RETURN from function\";");
	}

      if (r->cmd_data.command_data_u.return_cmd.retvals && r->cmd_data.command_data_u.return_cmd.retvals->list.list_len)
	{
	  set_nonewlines ();
	  printc ("RETURN ");
	  real_print_expr_list_with_separator (r->cmd_data.command_data_u.return_cmd.retvals, ",");

	if (r->cmd_data.command_data_u.return_cmd.with_resume)  {
	    printc (" WITH RESUME;" );
	} else {
	    printc (";");
	}


	  clr_nonewlines ();
	}
      else
	{
	  printc ("RETURN;");
	}
      break;


    case E_CMD_MENU_CMD:
    case E_CMD_NEXT_OPTION_CMD:
    case E_CMD_HIDE_OPTION_CMD:
    case E_CMD_SHOW_OPTION_CMD:
    case E_CMD_OPEN_WINDOW_CMD:
    case E_CMD_NEED_CMD:
    case E_CMD_SKIP_CMD:
    case E_CMD_PRINT_CMD:
    case E_CMD_PRINT_FILE_CMD:
    case E_CMD_PAUSE_CMD:
    case E_CMD_MESSAGE_CMD:
    case E_CMD_NEXT_FIELD_CMD:
    case E_CMD_SCROLL_CMD:
    case E_CMD_OPEN_FORM_CMD:
    case E_CMD_OPTIONS_CMD:
      not_in_spl ();
      return 0;




    case E_CMD_WHENEVER_CMD:
      print_whenever_style (r->cmd_data.command_data_u.whenever_cmd.whencode, r->cmd_data.command_data_u.whenever_cmd.whento);
      break;




    case E_CMD_RUN_CMD:
      if (A4GL_isyes (acl_getenv ("TRACESPL")))
	{
	  printc ("TRACE    \"RUNNING SOMETHING\";");
	}
      set_nonewlines ();
      printc ("SYSTEM ");
      real_print_expr (r->cmd_data.command_data_u.run_cmd.run_string);


      if (r->cmd_data.command_data_u.run_cmd.wait == EB_FALSE)
	{
	  printc (" WITHOUT WAITING");
	}
      else
	{
	  if (r->cmd_data.command_data_u.run_cmd.run_mode == ERM_LINE_MODE)
	    {
	      printc (" IN LINE MODE");
	    }
	  if (r->cmd_data.command_data_u.run_cmd.run_mode == ERM_FORM_MODE)
	    {
	      printc (" IN FORM MODE");
	    }


	  if (r->cmd_data.command_data_u.run_cmd.returning)
	    {

	      printc (" RETURNING ");
	      print_varbind (r->cmd_data.command_data_u.run_cmd.returning, 'w', a);
	      if (A4GL_isyes (acl_getenv ("TRACESPL")))
		{
		  printc ("TRACE \"Return code = \"||(");
		  print_varbind (r->cmd_data.command_data_u.run_cmd.returning, 'w', a);
		  printc ("  using \"#####&\";");
		}
	    }

	}
      printc (";");
      clr_nonewlines ();

      break;

    case E_CMD_SLEEP_CMD:
      set_nonewlines ();
      printc ("SLEEP ");
      real_print_expr (r->cmd_data.command_data_u.sleep_cmd.sleep_expr);
      clr_nonewlines ();
      break;



    case E_CMD_WHILE_CMD:
      need_daylight ();
      loop_descent_level++;
      set_nonewlines ();
      printc ("WHILE ");
      real_print_expr (r->cmd_data.command_data_u.while_cmd.while_expr);
      clr_nonewlines ();
      tmp_ccnt++;
      dump_cmds (r->cmd_data.command_data_u.while_cmd.while_commands, r);
      loop_descent_level--;
      tmp_ccnt--;
      printc ("END WHILE");
      need_daylight ();
      break;



    case E_CMD_INIT_CMD:
      {
	struct expr_str_list *use_binding;
	int expand = 0;
	set_nonewlines ();



	use_binding = r->cmd_data.command_data_u.init_cmd.varlist;

	if (expand)
	  {
	    use_binding = expand_binding (r->cmd_data.command_data_u.init_cmd.varlist);
	  }

	printc ("INITIALIZE ");
	for (a = 0; a < use_binding->list.list_len; a++)
	  {
	    int scope;
	    if (a)
	      printc (",");

	    scope = get_var_expr_scope (use_binding->list.list_val[a]);
	    print_varbind (use_binding->list.list_val[a], 'w', a);
	  }




	if (r->cmd_data.command_data_u.init_cmd.tablist)
	  {
	    printc (" LIKE ");
	    for (a = 0; a < r->cmd_data.command_data_u.init_cmd.tablist->str_list_entry.str_list_entry_len; a++)
	      {
		if (a)
		  printc (",");
		printc ("%s", r->cmd_data.command_data_u.init_cmd.tablist->str_list_entry.str_list_entry_val[a]);
	      }
	  }
	else
	  {
	    printc (" TO NULL");
	  }
	clr_nonewlines ();


	module_var_binding (use_binding, COPY_DATA_FROM_TMPS_INTO_MODVARS);

	/*
	   for (a = 0; a < r->cmd_data.command_data_u.init_cmd.varlist->list.list_len; a++)
	   {
	   if (find_scope(r->cmd_data.command_data_u.init_cmd.  varlist->list.list_val[a].varname)=='m') {
	   printc ("CALL %s lv_tmp_%x_%d)", decode_varbind (&r->cmd_data.command_data_u.init_cmd.  varlist->list.list_val[a], 'W'), r->cmd_data.command_data_u.init_cmd.  varlist->list.list_val[a].dtype,a);
	   }

	   }
	 */

      }
      break;


    case E_CMD_OPEN_CURSOR_CMD:

      module_var_binding (r->cmd_data.command_data_u.open_cursor_cmd.using_bind, COPY_DATA_FROM_MODVARS_INTO_TMPS);

      set_nonewlines ();
      printc ("OPEN ");
      print_ident (r->cmd_data.command_data_u.open_cursor_cmd.cursorname);

      if (r->cmd_data.command_data_u.open_cursor_cmd.using_bind)
	{
	  if (r->cmd_data.command_data_u.open_cursor_cmd.using_bind->list.list_len)
	    {
	      printc (" USING ");
	      for (a = 0; a < r->cmd_data.command_data_u.open_cursor_cmd.using_bind->list.list_len; a++)
		{
		  if (a)
		    printc (",");

		  print_varbind (r->cmd_data.command_data_u.open_cursor_cmd.using_bind->list.list_val[a], 'r', a);
		}
	    }
	}
      printc (";");
      clr_nonewlines ();
      break;




    case E_CMD_PREPARE_CMD:

      set_nonewlines ();
      if ((r->cmd_data.command_data_u.prepare_cmd.connid))
	{
	  print_connid (r->cmd_data.command_data_u.prepare_cmd.connid);
	}
      printc ("PREPARE ");
      print_ident (r->cmd_data.command_data_u.prepare_cmd.stmtid);
      printc (" FROM ");
      real_print_variable_or_literal (r->cmd_data.command_data_u.prepare_cmd.sql, "\"\"");
      printc (";");
      clr_nonewlines ();
      break;

    case E_CMD_EXECUTE_CMD:

      module_var_binding (r->cmd_data.command_data_u.execute_cmd.inbind, COPY_DATA_FROM_MODVARS_INTO_TMPS);
      set_nonewlines ();
      //if (!when_set_to_call) { A4GL_warn("Coding Standards: Must use 'WHENEVER ERROR CALL get_error_record' before using SQL"); }
      printc ("EXECUTE ");
      print_ident (r->cmd_data.command_data_u.execute_cmd.sql_stmtid);

      if (r->cmd_data.command_data_u.execute_cmd.inbind)
	{
	  if (r->cmd_data.command_data_u.execute_cmd.inbind->list.list_len)
	    {

	      printc (" USING ");
	      for (a = 0; a < r->cmd_data.command_data_u.execute_cmd.inbind->list.list_len; a++)
		{
		  if (a)
		    printc (",");

		  print_varbind (r->cmd_data.command_data_u.execute_cmd.inbind->list.list_val[a], 'r', a);
		}
	    }
	}

      if (r->cmd_data.command_data_u.execute_cmd.outbind)
	{
	  if (r->cmd_data.command_data_u.execute_cmd.outbind->list.list_len)
	    {
	      clr_nonewlines ();
	      set_nonewlines ();
	      printc (" INTO ");
	      for (a = 0; a < r->cmd_data.command_data_u.execute_cmd.outbind->list.list_len; a++)
		{
		  if (a)
		    printc (",");
		  print_varbind (r->cmd_data.command_data_u.execute_cmd.outbind->list.list_val[a], 'w', a);
		}
	    }
	}
      printc (";");
      clr_nonewlines ();
      module_var_binding (r->cmd_data.command_data_u.execute_cmd.outbind, COPY_DATA_FROM_TMPS_INTO_MODVARS);

      break;

    case E_CMD_EXECUTE_IMMEDIATE_CMD:
      set_nonewlines ();
      if ((r->cmd_data.command_data_u.execute_immediate_cmd.connid))
	{
	  print_connid (r->cmd_data.command_data_u.execute_immediate_cmd.connid);
	}

      if (r->cmd_data.command_data_u.execute_immediate_cmd.sql_stmt->expr_type == ET_E_V_OR_LIT_STRING)
	{
	  if (r->cmd_data.command_data_u.execute_immediate_cmd.sql_stmt->expr_str_u.s[0] != '"')
	    {
	      printc ("%s", r->cmd_data.command_data_u.execute_immediate_cmd.sql_stmt->expr_str_u.s);
	    }
	  else
	    {
	      printc ("EXECUTE IMMEDIATE %s", r->cmd_data.command_data_u.execute_immediate_cmd.sql_stmt->expr_str_u.s);
	    }
	}
      else
	{
	  printc ("EXECUTE IMMEDIATE ");
	  real_print_variable_or_literal (r->cmd_data.command_data_u.execute_immediate_cmd.sql_stmt, "\"\"");
	}
      printc (";");
      clr_nonewlines ();
      break;

    case E_CMD_INPUT_CMD:
    case E_CMD_INPUT_ARRAY_CMD:
    case E_CMD_CONSTRUCT_CMD:
    case E_CMD_DISPLAY_ARRAY_CMD:
    case E_CMD_PROMPT_CMD:
    case E_CMD_START_CMD:
    case E_CMD_CONVERT_CMD:
    case E_CMD_FREE_REP_CMD:
    case E_CMD_FINISH_CMD:
    case E_CMD_TERM_REP_CMD:
    case E_CMD_CLEAR_CMD:
      not_in_spl ();
      return 0;


    case E_CMD_PUT_CMD:

      if (r->cmd_data.command_data_u.put_cmd.values)
	{
	  if (r->cmd_data.command_data_u.put_cmd.values->list.list_len)
	    {
	      module_var_binding (r->cmd_data.command_data_u.put_cmd.values, COPY_DATA_FROM_MODVARS_INTO_TMPS);
	    }
	}

      set_nonewlines ();
      if ((r->cmd_data.command_data_u.put_cmd.connid))
	{
	  print_connid (r->cmd_data.command_data_u.put_cmd.connid);
	}

      printc ("PUT ");
      print_ident (r->cmd_data.command_data_u.put_cmd.cursorname);

      if (r->cmd_data.command_data_u.put_cmd.values)
	{
	  if (r->cmd_data.command_data_u.put_cmd.values->list.list_len)
	    {
	      printc (" FROM ");
	      for (a = 0; a < r->cmd_data.command_data_u.put_cmd.values->list.list_len; a++)
		{
		  if (a)
		    printc (",");

		  if (r->cmd_data.command_data_u.put_cmd.values->list.list_val[a]->expr_type == ET_E_V_OR_LIT_VAR)
		    {
		      print_varbind (r->cmd_data.command_data_u.put_cmd.values->list.list_val[a], 'w', 0);
		    }
		  else
		    {
		      if (r->cmd_data.command_data_u.put_cmd.values->list.list_val[a])
			{
			  real_print_expr (r->cmd_data.command_data_u.put_cmd.values->list.list_val[a]);
			}
		      else
			{
			  printc ("\"\"");
			}
		    }
		}
	    }
	}
      printc (";");
      clr_nonewlines ();

      break;

    case E_CMD_UNLOAD_CMD:
      set_nonewlines ();
      if (r->cmd_data.command_data_u.unload_cmd.connid)
	{
	  print_connid (r->cmd_data.command_data_u.unload_cmd.connid);
	}

      printc ("UNLOAD TO ");
      real_print_variable_or_literal (r->cmd_data.command_data_u.unload_cmd.filename, "\"\"");

      if (r->cmd_data.command_data_u.unload_cmd.delimiter)
	{
	  printc (" DELIMITER ");
	  real_print_variable_or_literal (r->cmd_data.command_data_u.unload_cmd.delimiter, "\"|\"");
	}

      if (r->cmd_data.command_data_u.unload_cmd.sql->expr_type == ET_EXPR_SELECT_LIST_ITEM)
	{			// Its a select..
	  struct s_select *S;
	  S = r->cmd_data.command_data_u.unload_cmd.sql->expr_str_u.sl_item->data.s_select_list_item_data_u.subquery;
	  preprocess_sql_statement (S);
	  search_variables (&S->list_of_items);
	}
      printc (" ");
      clr_nonewlines ();
      real_print_expr (r->cmd_data.command_data_u.unload_cmd.sql);

      //printc (" %s", replace_bind (r->cmd_data.command_data_u.unload_cmd.sql, r->cmd_data.command_data_u.unload_cmd.inbind, 'r'));

      break;

    case E_CMD_LOAD_CMD:
      //str connid;
      //variable_or_literal* filename;
      //variable_or_literal* delimiter;
      //str sqlvar; /* We'll use either sqlvar or tabname/collist */
      //str tabname;

      //r->cmd_data.command_data_u.load_cmd 
      //
      set_nonewlines ();
      if ((r->cmd_data.command_data_u.load_cmd.connid))
	{
	  print_connid (r->cmd_data.command_data_u.load_cmd.connid);
	}
      printc ("LOAD FROM ");
      real_print_variable_or_literal (r->cmd_data.command_data_u.load_cmd.filename, "\"\"");
      if (r->cmd_data.command_data_u.load_cmd.delimiter)
	{
	  if (r->cmd_data.command_data_u.load_cmd.delimiter->expr_type == ET_EXPR_FUNC)
	    {
	      printc (" USING FILTER %s", r->cmd_data.command_data_u.load_cmd.delimiter->expr_str_u.expr_func.funcname);
	    }
	  else
	    {
	      printc (" DELIMITER ");
	      real_print_variable_or_literal (r->cmd_data.command_data_u.load_cmd.delimiter, "\"|\"");
	    }
	}
      if (strlen (r->cmd_data.command_data_u.load_cmd.tabname))
	{
	  printc (" INSERT INTO %s", r->cmd_data.command_data_u.load_cmd.tabname);
	  if (r->cmd_data.command_data_u.load_cmd.collist)
	    {
	      printc ("(");
	      real_print_str_list_with_separator (r->cmd_data.command_data_u.load_cmd.collist, ",");
	      printc (")");
	    }
	}
      else
	{
	  printc ("%s", r->cmd_data.command_data_u.load_cmd.sqlvar);
	}
      printc (";");
      clr_nonewlines ();
      break;


    case E_CMD_SQL_CMD:
      set_nonewlines ();
      if ((r->cmd_data.command_data_u.sql_cmd.connid))
	{
	  print_connid (r->cmd_data.command_data_u.sql_cmd.connid);
	}
      printc ("%s", r->cmd_data.command_data_u.sql_cmd.sql);
      clr_nonewlines ();
      break;


    case E_CMD_SQL_TRANSACT_CMD:
      set_nonewlines ();
      //if (!when_set_to_call) { A4GL_warn("Coding Standards: Must use 'WHENEVER ERROR CALL get_error_record' before using SQL"); }
      if ((r->cmd_data.command_data_u.sql_transact_cmd.connid))
	{
	  print_connid (r->cmd_data.command_data_u.sql_transact_cmd.connid);
	}
      switch (r->cmd_data.command_data_u.sql_transact_cmd.trans)
	{
	case -1:
	  //if (strcmp(current_func->funcname,"begin_work")!=0) { A4GL_warn("Coding Standards: BEGIN WORK used directly"); }
	  printc ("BEGIN WORK;");
	  break;
	case 0:
	  //if (strcmp(current_func->funcname,"rollback_work")!=0) { A4GL_warn("Coding Standards: ROLLBACK WORK used directly"); }
	  printc ("ROLLBACK WORK;");
	  break;
	case 1:
	  //if (strcmp(current_func->funcname,"commit_work")!=0) { A4GL_warn("Coding Standards: COMMIT WORK used directly"); }
	  printc ("COMMIT WORK;");
	  break;
	default:
	  printc (" BAD TRANS : %d\n", r->cmd_data.command_data_u.sql_transact_cmd.trans);
	}
      clr_nonewlines ();
      break;


    case E_CMD_FLUSH_CMD:

      set_nonewlines ();
      if ((r->cmd_data.command_data_u.flush_cmd.connid))
	{
	  print_connid (r->cmd_data.command_data_u.flush_cmd.connid);
	}

      printc ("FLUSH ");
      print_ident (r->cmd_data.command_data_u.flush_cmd.cursorname);
      printc (";");
      clr_nonewlines ();
      break;


    case E_CMD_DECLARE_CMD:
      {

	need_daylight ();	//printc ("#");
	set_nonewlines ();
	if ((r->cmd_data.command_data_u.declare_cmd.connid))
	  {
	    print_connid (r->cmd_data.command_data_u.declare_cmd.connid);
	  }

	printc ("DECLARE ");
	print_ident (r->cmd_data.command_data_u.declare_cmd.cursorname);

	if (r->cmd_data.command_data_u.declare_cmd.scroll == EB_TRUE)
	  {
	    printc (" SCROLL CURSOR");
	  }
	else
	  {
	    printc (" CURSOR");
	  }

	if (r->cmd_data.command_data_u.declare_cmd.with_hold == EB_TRUE)
	  {
	    printc (" WITH HOLD");
	  }


	printc (" FOR ");
	if (r->cmd_data.command_data_u.declare_cmd.declare_dets->insert_cmd)
	  {
	    print_insert_cmd (r->cmd_data.command_data_u.declare_cmd.declare_dets->insert_cmd);
	    clr_nonewlines ();
	  }
	else
	  {
	    if (r->cmd_data.command_data_u.declare_cmd.declare_dets->ident)
	      {
		print_ident (r->cmd_data.command_data_u.declare_cmd.declare_dets->ident);
		clr_nonewlines ();
	      }
	    else
	      {
		clr_nonewlines ();
		tmp_ccnt++;
		preprocess_sql_statement (r->cmd_data.command_data_u.declare_cmd.declare_dets->select);
		search_variables (&r->cmd_data.command_data_u.declare_cmd.declare_dets->select->list_of_items);
		print_select (r->cmd_data.command_data_u.declare_cmd.declare_dets->select,
			      r->cmd_data.command_data_u.declare_cmd.declare_dets->forUpdate);
		tmp_ccnt--;
	      }
	  }

	printc (";");
      }
      need_daylight ();		//printc ("#");
      break;



    case E_CMD_SET_DATABASE_CMD:

      set_nonewlines ();
      printc ("DATABASE ");
      real_print_expr (r->cmd_data.command_data_u.set_database_cmd.set_dbname);
      if (r->cmd_data.command_data_u.set_database_cmd.exclusive_mode == EB_TRUE)
	{
	  printc (" EXCLUSIVE");
	}
      clr_nonewlines ();
      break;

    case E_CMD_FETCH_CMD:
      //if (!when_set_to_call) { A4GL_warn("Coding Standards: Must use 'WHENEVER ERROR CALL get_error_record' before using SQL"); }
      set_nonewlines ();
      switch (r->cmd_data.command_data_u.fetch_cmd.fetch->fp->ab_rel)
	{
	case FETCH_RELATIVE:
	  if (A4GL_is_just_int_literal (r->cmd_data.command_data_u.fetch_cmd.fetch->fp->fetch_expr, 1))
	    {
	      printc ("FETCH ");
	      print_ident (r->cmd_data.command_data_u.fetch_cmd.fetch->cname);
	    }
	  else
	    {
	      printc ("FETCH RELATIVE ");
	      real_print_expr (r->cmd_data.command_data_u.fetch_cmd.fetch->fp->fetch_expr);
	      printc (" ");
	      print_ident (r->cmd_data.command_data_u.fetch_cmd.fetch->cname);
	    }
	  break;

	case FETCH_ABSOLUTE:
	  if (A4GL_is_just_int_literal (r->cmd_data.command_data_u.fetch_cmd.fetch->fp->fetch_expr, 1))
	    {
	      printc ("FETCH FIRST ");
	      print_ident (r->cmd_data.command_data_u.fetch_cmd.fetch->cname);
	      break;

	    }
	  if (A4GL_is_just_int_literal (r->cmd_data.command_data_u.fetch_cmd.fetch->fp->fetch_expr, -1))
	    {
	      printc ("FETCH LAST ");
	      print_ident (r->cmd_data.command_data_u.fetch_cmd.fetch->cname);
	      break;
	    }

	  if (A4GL_is_just_int_literal (r->cmd_data.command_data_u.fetch_cmd.fetch->fp->fetch_expr, 0))
	    {
	      printc ("FETCH CURRENT ");
	      print_ident (r->cmd_data.command_data_u.fetch_cmd.fetch->cname);
	      break;
	    }

	  printc ("FETCH ABSOLUTE ");
	  real_print_expr (r->cmd_data.command_data_u.fetch_cmd.fetch->fp->fetch_expr);
	  printc (" ");
	  print_ident (r->cmd_data.command_data_u.fetch_cmd.fetch->cname);
	  break;

	}


      if (r->cmd_data.command_data_u.fetch_cmd.outbind)
	{
	  if (r->cmd_data.command_data_u.fetch_cmd.outbind->list.list_len)
	    {
	      printc (" INTO ");
	      real_print_binding_with_separator (r->cmd_data.command_data_u.fetch_cmd.outbind, 'w', ",");
	    }
	}
      printc (";");
      clr_nonewlines ();


      if (r->cmd_data.command_data_u.fetch_cmd.outbind)
	{
	  if (r->cmd_data.command_data_u.fetch_cmd.outbind->list.list_len)
	    {
	      module_var_binding (r->cmd_data.command_data_u.fetch_cmd.outbind, COPY_DATA_FROM_TMPS_INTO_MODVARS);
	    }
	}
      break;


// Probably not used commands

    case E_CMD_DISPLAY_B_N_CMD:
      not_in_spl ();
      return 0;
      break;

    case E_CMD_VALIDATE_CMD:
      not_in_spl ();
      return 0;
      break;


// ENHANCED COMMANDS....
    case E_CMD_CONNECT_CMD:
      not_in_spl ();
      return 0;

    case E_CMD_CHECK_MENU_CMD:
    case E_CMD_UNCHECK_MENU_CMD:
    case E_CMD_DISABLE_MENU_CMD:
    case E_CMD_ENABLE_MENU_CMD:
    case E_CMD_SKIP_BY_CMD:
    case E_CMD_SKIP_TO_CMD:
    case E_CMD_AT_TERM_CMD:
    case E_CMD_PRINT_IMG_CMD:
      not_in_spl ();
      return 0;

    case E_CMD_SELECT_CMD:
      need_daylight ();
      print_connid (r->cmd_data.command_data_u.select_cmd.connid);
      preprocess_sql_statement (r->cmd_data.command_data_u.select_cmd.sql);
      search_variables (&r->cmd_data.command_data_u.select_cmd.sql->list_of_items);
      print_select (r->cmd_data.command_data_u.select_cmd.sql, r->cmd_data.command_data_u.select_cmd.forupdate);
      break;

    case E_CMD_UPDATE_CMD:
      {
	int a;
	char *rval;
	struct struct_update_cmd *u;
	struct s_select fake_select;
	struct s_select_list_item_list l;
	struct s_table t;
	u = &r->cmd_data.command_data_u.update_cmd;


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

	fake_select.first->tabname = r->cmd_data.command_data_u.update_cmd.table;
	fake_select.first->alias = fake_select.first->tabname;

	fake_select.first->next = NULL;
	fake_select.first->outer_next = NULL;

	fake_select.table_elements.tables.tables_len = 0;
	fake_select.table_elements.tables.tables_val = 0;


	fake_select.where_clause = 0;	/* r->cmd_data.command_data_u.update_cmd.where_clause->expr_str_u.sl_item; */
	if (r->cmd_data.command_data_u.update_cmd.where_clause)
	  {
	    fake_select.where_clause = r->cmd_data.command_data_u.update_cmd.where_clause->expr_str_u.sl_item;
	  }
	fake_select.group_by = 0;
	fake_select.next = 0;
	fake_select.sf = 0;
	fake_select.into = 0;
	fake_select.union_op = 0;
	fake_select.extra_statement = 0;
	fake_select.select_list = u->value_list;
	A4GLSQLPARSE_from_clause_collect_tables (&fake_select, fake_select.first, &fake_select.table_elements);
	preprocess_sql_statement (&fake_select);
	search_variables (&fake_select.list_of_items);


	need_daylight ();
	print_connid (u->connid);
	printc ("UPDATE %s ", u->table);
	set_nonewlines ();
	printc ("SET ");
	A4GL_assertion (u->value_list == 0, "No value list");


	if (u->column_list == 0)
	  {
	    printc (" * = (");
	    clr_nonewlines ();
	    for (a = 0; a < u->value_list->list.list_len; a++)
	      {
		char comma[2] = ",";
		rval = get_select_list_item (0, u->value_list->list.list_val[a]);
		if (a == u->value_list->list.list_len - 1)
		  {
		    strcpy (comma, "");
		  }
		printc ("    %s%s", rval, comma);
	      }
	    printc (")");


	  }
	else
	  {

	    if (u->value_list->list.list_len == u->column_list->str_list_entry.str_list_entry_len)
	      {
		// Same length..
		for (a = 0; a < u->value_list->list.list_len; a++)
		  {
		    if (a)
		      {
			printc (",");
			clr_nonewlines ();
			set_nonewlines ();
		      }
		    rval = get_select_list_item (0, u->value_list->list.list_val[a]);
		    if (a != 0)
		      {
			printc ("    ");
		      }
		    printc ("%-18s=%s", u->column_list->str_list_entry.str_list_entry_val[a], rval);
		    free (rval);
		  }
	      }
	    else
	      {
		clr_nonewlines ();
		set_nonewlines ();
		printc ("(");
		for (a = 0; a < u->column_list->str_list_entry.str_list_entry_len; a++)
		  {
		    if (a)
		      printc (",");
		    printc ("%s", u->column_list->str_list_entry.str_list_entry_val[a]);
		  }
		printc (")=(");
		for (a = 0; a < u->value_list->list.list_len; a++)
		  {
		    if (a)
		      printc (",");
		    rval = get_select_list_item (0, u->value_list->list.list_val[a]);
		    printc ("%s", rval);
		    free (rval);
		  }
		printc (")");

	      }
	    clr_nonewlines ();
	  }

	if (r->cmd_data.command_data_u.update_cmd.where_clause)
	  {
	    //set_nonewlines ();
	    if (r->cmd_data.command_data_u.update_cmd.where_clause->expr_type == ET_EXPR_WHERE_CURRENT_OF)
	      {
		set_nonewlines ();
		printc ("WHERE CURRENT OF ");
		print_ident (r->cmd_data.command_data_u.update_cmd.where_clause->expr_str_u.expr_expr);
		clr_nonewlines ();
	      }
	    else
	      {
		printc ("WHERE %s",
			get_select_list_item (&fake_select,
					      r->cmd_data.command_data_u.update_cmd.where_clause->expr_str_u.sl_item));
	      }
	    //clr_nonewlines ();
	  }
      }
      break;

    case E_CMD_INSERT_CMD:
      need_daylight ();
      print_insert_cmd (&r->cmd_data.command_data_u.insert_cmd);
      break;

    case E_CMD_DELETE_CMD:

      print_connid (r->cmd_data.command_data_u.delete_cmd.connid);
      printc ("DELETE FROM %s ", r->cmd_data.command_data_u.delete_cmd.table);

      if (r->cmd_data.command_data_u.delete_cmd.where_clause != NULL)
	{

	  if (r->cmd_data.command_data_u.delete_cmd.where_clause->expr_type == ET_EXPR_WHERE_CURRENT_OF)
	    {
	      set_nonewlines ();
	      printc ("WHERE CURRENT OF ");
	      print_ident (r->cmd_data.command_data_u.delete_cmd.where_clause->expr_str_u.expr_expr);
	      clr_nonewlines ();
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

	      fake_select.first->tabname = r->cmd_data.command_data_u.delete_cmd.table;
	      fake_select.first->alias = fake_select.first->tabname;
	      fake_select.first->next = NULL;
	      fake_select.first->outer_next = NULL;
	      fake_select.table_elements.tables.tables_len = 0;
	      fake_select.table_elements.tables.tables_val = 0;

	      fake_select.where_clause = r->cmd_data.command_data_u.delete_cmd.where_clause->expr_str_u.sl_item;
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
	      search_variables (&fake_select.list_of_items);

	      printc (" WHERE %s",
		      get_select_list_item (&fake_select, r->cmd_data.command_data_u.delete_cmd.where_clause->expr_str_u.sl_item));
	      //current_stmt_table=r->cmd_data.command_data_u.delete_cmd.table;
	      //real_print_expr(r->cmd_data.command_data_u.delete_cmd.where_clause);
	    }
	}
      break;

    case E_CMD_SQL_BLOCK_CMD:
      real_print_expr_list_with_separator (r->cmd_data.command_data_u.sql_block_cmd.list, " ");
      break;

    case E_CMD_SHOW_MENU_CMD:
      not_in_spl ();
      return 0;
    case E_CMD_ENABLE_CMD:	// NIY
    case E_CMD_ENABLE_FORM_CMD:	// NIY
    case E_CMD_DISABLE_CMD:	// NIY
    case E_CMD_DISABLE_FORM_CMD:	// NIY
    case E_CMD_PDF_CALL_CMD:
    case E_CMD_NEXT_FORM_CMD:	// NIY
    case E_CMD_MSG_BOX_CMD:	// NIY
    case E_CMD_OPEN_STATUSBOX_CMD:	// NIY
    case E_CMD_OPEN_FORM_GUI_CMD:	// NIY
    case E_CMD_SET_SESSION_CMD:
    case E_CMD_START_RPC_CMD:
    case E_CMD_ALLOC_ARR_CMD:
    case E_CMD_DEALLOC_ARR_CMD:
    case E_CMD_RESIZE_ARR_CMD:
    case E_CMD_SHOW_CMD:
    case E_CMD_HIDE_CMD:
    case E_CMD_MOVE_CMD:
      not_in_spl ();
      return 0;
    }
  return 1;
}


/****************************************************************/
/* LIST HANDLING */
/****************************************************************/
static void
add_to_list (int list, char *s)
{
  if (list == LIST_BLACKLIST)
    {
      nblacklist++;
      blacklist = realloc (blacklist, sizeof (char *) * nblacklist);
      blacklist[nblacklist - 1] = strdup (s);
      return;
    }
  A4GL_assertion (1, "Not implemented");
}


static int
is_on_list (int list, char *s)
{
  int a;
  if (list == LIST_BLACKLIST)
    {
      for (a = 0; a < nblacklist; a++)
	{
	  if (A4GL_aubit_strcasecmp (blacklist[a], s) == 0)
	    return 1;
	}
      return 0;
    }
  A4GL_assertion (1, "Not implemented");
  return 0;
}



/************************************************************************/
/* ERROR HANDLING ***/
/************************************************************************/


static int
print_whenever_style (int code, char *whento)
{
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


void
A4GL_warn (char *s)
{
  fprintf (stderr, "%s\n", s);

}



void
LEXLIB_A4GL_initlex (void)
{
  int a;
  for (a = 0; a < 100; a++)
    {
      record_headers[a] = 0;
    }
}


static void
local_a4gl_yyerror (char *s)
{
  fprintf (stderr, "%s", s);
  exit (2);
}



void
not_in_spl ()
{
}

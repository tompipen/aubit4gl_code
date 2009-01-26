#include "a4gl_libaubit4gl.h"
#include "a4gl_API_lex_lib.h"
#include "compile_4gl.h"
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


char *current_stmt_table = 0;
struct expr_str *input_array_variable = 0;


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

int printing_expr=0;

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
static enum e_scope get_var_expr_scope (struct expr_str *p);
static int get_var_expr_dtype (struct expr_str *p);
static int print_whenever_style (int code, char *whento);
static void printc_safe_to_split_at_comma (char *fmt, ...);
static void print_attributes (attrib * x);
static char *attributes_as_string (attrib * x);
static char *get_attributes_as_string (attrib * x);
//static struct expr_str_list *A4GL_rationalize_list_concat (struct expr_str_list *l);
static void real_print_field_list_with_separator (struct fh_field_list *fl, char *sep);
static void A4GL_warn (char *s);
static void print_events (on_events * es, struct command *parent);
static int has_before_menu (on_events * es);
static void real_print_expr (struct expr_str *ptr);
static void print_connid (struct expr_str *e);
static void print_options (char n, char *s, struct expr_str *expr);
static void real_print_binding_with_separator (expr_str_list * s, char read_or_write, char *sep);
static void real_print_expr_list_with_separator (struct expr_str_list *l, char *s);
static void print_var_usage (struct variable_usage *var_usage, char dir, int no);
static int ui_as_calls (void);
static char *local_get_expr_as_string (struct expr_str *ptr);
static char *get_variable_usage (struct variable_usage *var_usage);
static char *local_get_expr_as_string_list_with_separator (struct expr_str_list *l, char *sep);
static void search_variables (struct s_select_list_item_list *l);
static char *xfield_name_as_char (struct fh_field_entry *f);
static void print_input_array (struct expr_str *arrvar, int helpno, int defs, struct expr_str *srec, attrib * attrib, char *slice);
static char *xfield_name_list_as_char (struct fh_field_list *fl);


/* These functions are for whitelist/blacklist handling of functions - in normal usage - they are not normally required ;-) */
static void load_blacklist (void);
static void load_blacklist_from (char *ptr);
static int is_on_list (int list, char *s);
static void add_to_list (int list, char *s);
static char *get_orig_from_clobber(char *s) ;



/******************************************************************/
/*                            FUNCTIONS                           */
/******************************************************************/
static char * map_fname (char *s)
{
  if (ui_as_calls ())
    {
      if (strcmp (s, "scr_line") == 0)
	{
	  return "UILIB_scr_line";
	}

      if (strcmp (s, "arr_line") == 0)
	{
	  return "UILIB_arr_line";
	}

      if (strcmp (s, "arr_count") == 0)
	{
	  return "UILIB_arr_count";
	}
      if (strcmp (s, "set_count") == 0)
	{
	  return "UILIB_set_count";
	}
      if (strcmp (s, "arr_curr") == 0)
	{
	  return "UILIB_arr_curr";
	}
      if (strcmp (s, "fgl_drawbox") == 0)
	{
	  return "UILIB_fgl_drawbox";
	}
      if (strcmp (s, "aclfgl_fgl_drawbox") == 0)
	{
	  return "UILIB_fgl_drawbox";
	}
    }
  return s;
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
  sprintf (buff, "DEFINE %-16s %s", v, buff_dtype);
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



static int
ui_as_calls (void)
{
  static int uimode = -1;
  if (uimode == -1)
    {
      if (A4GL_isyes (acl_getenv ("FGLCUICALL")) || 0)
	{
	  uimode = 1;
	}
      else
	{
	  uimode = 0;
	}
    }
  return uimode;
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


static void
print_attributes (attrib * x)
{
  printc_safe_to_split_at_comma ("%s", get_attributes_as_string (x));
}

static char *
attributes_as_string (attrib * x)
{
  static char buff[2000];
  sprintf (buff, "\"%s\"", get_attributes_as_string (x));
  return buff;
}

static char *
get_attributes_as_string (attrib * x)
{
  int printed = 0;
  static char buff[1000];
  char smbuff[256];


  strcpy (buff, "");
  if (x == 0)
    return buff;
  if (x->color == attr_code ("BLACK"))
    {

      strcpy (buff, "BLACK");
      printed++;
    }
  if (x->color == attr_code ("BLUE"))
    {
      strcpy (buff, "BLUE");
      printed++;
    }
  if (x->color == attr_code ("CYAN"))
    {
      strcpy (buff, "CYAN");
      printed++;
    }
  if (x->color == attr_code ("GREEN"))
    {
      strcpy (buff, "GREEN");
      printed++;
    }
  if (x->color == attr_code ("MAGENTA"))
    {
      strcpy (buff, "MAGENTA");
      printed++;
    }
  if (x->color == attr_code ("RED"))
    {
      strcpy (buff, "RED");
      printed++;
    }
  if (x->color == attr_code ("YELLOW"))
    {
      strcpy (buff, "YELLOW");
      printed++;
    }
  if (x->color == attr_code ("WHITE"))
    {
      strcpy (buff, "WHITE");
      printed++;
    }

  if (x->reverse == EB_TRUE)
    {
      if (printed)
	strcat (buff, ",");
      strcat (buff, "REVERSE");
      printed++;
    }
  if (x->blink == EB_TRUE)
    {
      if (printed)
	strcat (buff, ",");
      strcat (buff, "BLINK");
      printed++;
    }
  if (x->underline == EB_TRUE)
    {
      if (printed)
	strcat (buff, ",");
      strcat (buff, "UNDERLINE");
      printed++;
    }
  if (x->bold == EB_TRUE)
    {
      if (printed)
	strcat (buff, ",");
      strcat (buff, "BOLD");
      printed++;
    }
  if (x->normal == EB_TRUE)
    {
      if (printed)
	strcat (buff, ",");
      strcat (buff, "NORMAL");
      printed++;
    }
  if (x->invisible == EB_TRUE)
    {
      if (printed)
	strcat (buff, ",");
      strcat (buff, "INVISIBLE");
      printed++;
    }
  if (x->dim == EB_TRUE)
    {
      if (printed)
	strcat (buff, ",");
      strcat (buff, "DIM");
      printed++;
    }
  if (x->no_new_lines == EB_TRUE)
    {
      if (printed)
	strcat (buff, ",");
      strcat (buff, "NO NEW LINES");
      printed++;
    }

  if (x->style && strlen (x->style))
    {

      if (printed)
	strcat (buff, ",");
      strcat (buff, "STYLE=");
      strcat (buff, x->style);
      printed++;
    }

  if (x->border == EB_TRUE)
    {
      if (printed)
	{
	  strcat (buff, ",");
	}
      strcat (buff, "BORDER");
      printed++;
    }
  if (x->pad)
    {
      if (strlen (x->pad))
	{
	  if (printed)
	    {
	      strcat (buff, ",");
	    }
	  strcat (buff, "PAD=");
	  strcat (buff, x->pad);
	  printed++;
	}
    }

  if (x->text)
    {
      if (strlen (x->text))
	{
	  if (printed)
	    {
	      strcat (buff, ",");
	    }
	  strcat (buff, "TEXT=");
	  strcat (buff, x->text);
	  printed++;
	}
    }


  if (x->comment_line)
    {
      int x_comment_line;

      if (!is_plain_line (x->comment_line))
	{
	  A4GL_assertion (1, "Can only print plain lines atm");
	}
      else
	{
	  x_comment_line = get_plain_line (x->comment_line);

	  if (x_comment_line != 255)
	    {
	      if (x_comment_line > 0)
		{
		  if (printed)
		    strcat (buff, ",");

		  sprintf (smbuff, "COMMENT LINE %d", x_comment_line);
		  strcat (buff, smbuff);
		  printed++;
		}
	      else
		{
		  if (x_comment_line != -1)
		    {
		      if (printed)
			strcat (buff, ",");
		      sprintf (smbuff, "COMMENT LINE LAST%d", x_comment_line + 1);
		      strcat (buff, smbuff);
		      printed++;
		    }
		  else
		    {
		      if (printed)
			strcat (buff, ",");
		      strcat (buff, "COMMENT LINE LAST");
		      printed++;
		    }
		}
	    }
	}
    }

  if (x->form_line)
    {
      int x_form_line;
      if (!is_plain_line (x->form_line))
	{
	  A4GL_assertion (1, "Can only print plain lines atm");
	}
      else
	{
	  x_form_line = get_plain_line (x->form_line);
	  if (x_form_line != 255)
	    {
	      if (x_form_line > 0)
		{
		  if (printed)
		    strcat (buff, ",");
		  sprintf (smbuff, "FORM LINE %d", x_form_line);
		  strcat (buff, smbuff);
		  printed++;
		}
	      else
		{
		  if (x_form_line != -1)
		    {
		      if (printed)
			strcat (buff, ",");
		      sprintf (smbuff, "FORM LINE LAST%d", x_form_line + 1);
		      strcat (buff, smbuff);
		      printed++;
		    }
		  else
		    {
		      if (printed)
			strcat (buff, ",");
		      strcat (buff, "FORM LINE LAST");
		      printed++;
		    }
		}
	    }
	}
    }
  if (x->error_line)
    {
      int x_error_line;
      if (!is_plain_line (x->error_line))
	{
	  A4GL_assertion (1, "Can only print plain lines atm");
	}
      else
	{
	  x_error_line = get_plain_line (x->error_line);
	  if (x_error_line != 255)
	    {
	      if (x_error_line > 0)
		{
		  if (printed)
		    strcat (buff, ",");
		  sprintf (smbuff, "ERROR LINE %d", x_error_line);
		  strcat (buff, smbuff);
		  printed++;
		}
	      else
		{
		  if (x_error_line != -1)
		    {
		      if (printed)
			strcat (buff, ",");
		      sprintf (smbuff, "ERROR LINE LAST%d", x_error_line + 1);
		      strcat (buff, smbuff);
		      printed++;
		    }
		  else
		    {
		      if (printed)
			strcat (buff, ",");
		      strcat (buff, "ERROR LINE LAST");
		      printed++;
		    }
		}
	    }
	}
    }
  if (x->menu_line)
    {
      int x_menu_line;
      if (!is_plain_line (x->menu_line))
	{
	  A4GL_assertion (1, "Can only print plain lines atm");
	}
      else
	{
	  x_menu_line = get_plain_line (x->menu_line);
	  if (x_menu_line != 255)
	    {
	      if (x_menu_line > 0)
		{
		  if (printed)
		    strcat (buff, ",");
		  sprintf (smbuff, "MENU LINE %d", x_menu_line);
		  strcat (buff, smbuff);
		  printed++;
		}
	      else
		{
		  if (x_menu_line != -1)
		    {
		      if (printed)
			strcat (buff, ",");
		      sprintf (smbuff, "MENU LINE LAST%d", x_menu_line + 1);
		      strcat (buff, smbuff);
		      printed++;
		    }
		  else
		    {
		      if (printed)
			strcat (buff, ",");
		      strcat (buff, "MENU LINE LAST");
		      printed++;
		    }
		}
	    }
	}
    }
  if (x->message_line)
    {
      int x_message_line;
      if (!is_plain_line (x->message_line))
	{
	  A4GL_assertion (1, "Can only print plain lines atm");
	}
      else
	{
	  x_message_line = get_plain_line (x->message_line);

	  if (x_message_line != 255)
	    {
	      if (x_message_line > 0)
		{
		  if (printed)
		    strcat (buff, ",");
		  sprintf (smbuff, "MESSAGE LINE %d", x_message_line);
		  strcat (buff, smbuff);
		  printed++;
		}
	      else
		{
		  if (x_message_line != -1)
		    {
		      if (printed)
			strcat (buff, ",");
		      sprintf (smbuff, "MESSAGE LINE LAST%d", x_message_line + 1);
		      strcat (buff, smbuff);
		      printed++;
		    }
		  else
		    {
		      if (printed)
			strcat (buff, ",");
		      strcat (buff, "MESSAGE LINE LAST");
		      printed++;
		    }
		}
	    }
	}
    }
  if (x->prompt_line)
    {
      int x_prompt_line;
      if (!is_plain_line (x->prompt_line))
	{
	  A4GL_assertion (1, "Can only print plain lines atm");
	}
      else
	{
	  x_prompt_line = get_plain_line (x->prompt_line);

	  if (x_prompt_line != 255)
	    {
	      if (x_prompt_line > 0)
		{
		  if (printed)
		    strcat (buff, ",");
		  sprintf (smbuff, "PROMPT LINE %d", x_prompt_line);
		  strcat (buff, smbuff);
		  printed++;
		}
	      else
		{
		  if (x_prompt_line != -1)
		    {
		      if (printed)
			strcat (buff, ",");
		      sprintf (smbuff, "PROMPT LINE LAST%d", x_prompt_line + 1);
		      strcat (buff, smbuff);
		      printed++;
		    }
		  else
		    {
		      if (printed)
			strcat (buff, ",");
		      strcat (buff, "PROMPT LINE LAST");
		      printed++;
		    }
		}
	    }
	}
    }
  return buff;

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


static char * A4GL_get_expr_list_sep (struct expr_str_list *l, char *sep)
{
  int a;
  struct expr_str *p;
  //struct expr_str *p2;
  //struct expr_str_list *l2;
  //int b;
  int printed = 0;
  char *str = 0;

  if (l == 0) return acl_strdup ("");

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


/*
static char * A4GL_get_expr_list_concat (struct expr_str_list *l) {
  	l = A4GL_rationalize_list_concat (l);
	A4GL_get_expr_list_sep(l,",");
}
*/




//struct expr_str_list *replace_

/*
static void
A4GL_print_expr_list_concat (struct expr_str_list *l)
{

printc("%s", A4GL_get_expr_list_concat(l));
}*/


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
      printc ("%s", get_orig_from_clobber(ptr->expr_str_u.expr_string));
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
  printing_expr=1;
  str = local_get_expr_as_string (ptr);

{
int a;
for (a=0;a<strlen(str);a++) {
	if (str[a]<31 && str[a]!='\n' && str[a]!='\r' && str[a]!='\t') {
		
		A4GL_pause_execution();
		break;
	}
}
}







  printc ("%s", str);
  printing_expr=0;

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
      if (nonewlines)
	{
	  sprintf (buff, "COLUMN %s", local_get_expr_as_string (ptr->expr_str_u.expr_expr));
	}
      else
	{
	  sprintf (buff, "COLUMN %s", local_get_expr_as_string (ptr->expr_str_u.expr_expr));
	}
      return acl_strdup (buff);

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
      return acl_strdup ("PAGENO");
      break;

    case ET_EXPR_LINENO:
      return acl_strdup ("LINENO");
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
	       local_get_expr_as_string (l->list[a]);
	       }
	       }
	     */
	  }

	if (strcmp (ptr->expr_str_u.expr_function_call->fname, "fgl_lastkey") == 0 && ui_as_calls ())
	  {
	    sprintf (buff, "fgl_keyval(UILIB_lastkey())");
	  }
	else
	  {
	    params = A4GL_new_list_get_count (ptr->expr_str_u.expr_function_call->parameters);
	    sprintf (buff, "%s(%s)", map_fname (ptr->expr_str_u.expr_function_call->fname),
		     A4GL_get_expr_list_sep (ptr->expr_str_u.expr_function_call->parameters,",\n"));

	  }
      }
      return acl_strdup (buff);
      break;

    case ET_EXPR_REPORT_PRINTER:
      return acl_strdup ("PRINTER");
      break;

    case ET_EXPR_REPORT_EMAIL:
      return acl_strdup ("TO EMAIL");
      break;


    case ET_EXPR_LITERAL_LONG:
      sprintf (buff, "%ld", ptr->expr_str_u.expr_long);
      return acl_strdup (buff);
      break;

    case ET_EXPR_LITERAL_STRING:
	{
		char buff[60000];
		sprintf(buff,"\"%s\"", A4GL_strip_quotes(ptr->expr_str_u.expr_string));
		return acl_strdup(buff);
	}
      break;

    case ET_EXPR_QUOTED_STRING:
      return acl_strdup (ptr->expr_str_u.expr_string);
      break;

    case ET_EXPR_LITERAL_DOUBLE_STR:
      return acl_strdup (ptr->expr_str_u.expr_string);
      break;

    case ET_EXPR_OP_CLIP:
      return make_sql_string_and_free (local_get_expr_as_string (ptr->expr_str_u.expr_expr), acl_strdup (" CLIPPED"), NULL);
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
      sprintf (buff, "%s SPACES", local_get_expr_as_string (ptr->expr_str_u.expr_expr));
      return acl_strdup (buff);
      break;

    case ET_EXPR_MENU_ALL:
      if (ui_as_calls ())
	{
	  return acl_strdup ("\"ALL\"");
	}
      else
	{
	  return acl_strdup ("ALL");
	}
      break;

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

    case ET_EXPR_INFIELD:
      if (ui_as_calls ())
	{
	  if (ptr->expr_str_u.expr_infield->sio_id != -1)
	    {
	      sprintf (buff, "UILIB_INFIELD(UILIB_GET_CONTEXT(%s), %s) { %d } ",
		       last_context[CONTEXT_INPUT],
		       xfield_name_list_as_char (ptr->expr_str_u.expr_infield->field_list), (int)ptr->expr_str_u.expr_infield->sio_id);
	    }
	  else
	    {
	      if (strlen (last_context[CONTEXT_INPUT]) == 0)
		{
		  sprintf (buff, "UILIB_INFIELD(-1,%s) { 0 } ",
			   xfield_name_list_as_char (ptr->expr_str_u.expr_infield->field_list));
		}
	      else
		{
		  sprintf (buff, "UILIB_INFIELD(UILIB_GET_CONTEXT(%s), %s) { 0 } ",
			   last_context[CONTEXT_INPUT], xfield_name_list_as_char (ptr->expr_str_u.expr_infield->field_list));
		}
	    }
	}
      else
	{
	  sprintf (buff, "infield(%s)", xfield_name_list_as_char (ptr->expr_str_u.expr_infield->field_list));
	}
      return acl_strdup (buff);
      break;


    case ET_EXPR_FIELD_TOUCHED:
      if (ui_as_calls ())
	{
	  sprintf (buff, "UILIB_field_touched(UILIB_GET_CONTEXT(%s),%s)",
		   last_context[CONTEXT_INPUT], xfield_name_list_as_char (ptr->expr_str_u.expr_field_touched->field_list));
	}
      else
	{
	  sprintf (buff, "field_touched(%s)", xfield_name_list_as_char (ptr->expr_str_u.expr_field_touched->field_list));
	}
      return acl_strdup (buff);
      break;

    case ET_EXPR_NOT_FIELD_TOUCHED:
      if (ui_as_calls ())
	{
	  sprintf (buff, "NOT UILIB_field_touched(UILIB_GET_CONTEXT(%s),%s)",
		   last_context[CONTEXT_INPUT], xfield_name_list_as_char (ptr->expr_str_u.expr_field_touched->field_list));
	}
      else
	{
	  sprintf (buff, "NOT field_touched(%s)", xfield_name_list_as_char (ptr->expr_str_u.expr_field_touched->field_list));
	}
      return acl_strdup (buff);
      break;

    case ET_EXPR_IVAL_VAL:
      sprintf (buff, "INTERVAL(%s) %s TO %s", A4GL_strip_quotes (ptr->expr_str_u.expr_interval->intval),
	       decode_ival_define1 (ptr->expr_str_u.expr_interval->extend),
	       decode_ival_define2 (ptr->expr_str_u.expr_interval->extend));
      return acl_strdup (buff);
      break;


    case ET_EXPR_FGL_SIZEOF:
      sprintf (buff, "sizeof(%s)", ptr->expr_str_u.expr_string);
      return acl_strdup (buff);
      break;






    case ET_EXPR_FGL_ADDRESSOF:
      sprintf (buff, "A4GL_push_long(&(%s));", ptr->expr_str_u.expr_string);
      return acl_strdup (buff);
      break;

    case ET_EXPR_FGL_ISDYNARR_ALLOCATED:
      sprintf (buff, "A4GL_isdynarr_allocated(&%s);", ptr->expr_str_u.expr_string);
      return acl_strdup (buff);
      break;

    case ET_EXPR_FGL_DYNARR_EXTENTSIZE:
      sprintf (buff, "A4GL_dynarr_extent(&%s,%d);", local_get_expr_as_string (ptr->expr_str_u.expr_dynarr_extent->var),
	       ptr->expr_str_u.expr_dynarr_extent->n);
      return acl_strdup (buff);
      break;

    case ET_EXPR_FIELDTOWIDGET:
      sprintf (buff, "A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));", xfield_name_as_char (ptr->expr_str_u.expr_field_entry));
      return acl_strdup (buff);
      break;

    case ET_EXPR_ID_TO_INT:
      sprintf (buff, "A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));", xfield_name_as_char (ptr->expr_str_u.expr_field_entry));
      return acl_strdup (buff);
      break;


    case ET_EXPR_GET_FLDBUF:
      if (ui_as_calls ())
	{
	  sprintf (buff, "UILIB_getfldbuf(UILIB_GET_CONTEXT(%s),%s)",
		   last_context[CONTEXT_INPUT], xfield_name_list_as_char (ptr->expr_str_u.expr_get_fldbuf->field_list));
	}
      else
	{
	  sprintf (buff, "get_fldbuf(%s)", xfield_name_list_as_char (ptr->expr_str_u.expr_get_fldbuf->field_list));
	}
      return acl_strdup (buff);
      break;

    case ET_EXPR_MODULE_FUNC:
      sprintf (buff, "A4GL_push_char(_module_name);");
      return acl_strdup (buff);
      break;

    case ET_EXPR_PDF_FCALL:
      if (ptr->expr_str_u.expr_pdf_function_call->parameters)
	{
	  sprintf (buff, "PDF_FUNCTION (%s", ptr->expr_str_u.expr_pdf_function_call->fname);
	  sprintf (buff, ",%s", A4GL_get_expr_list_sep (ptr->expr_str_u.expr_pdf_function_call->parameters,",\n"));
	}
      else
	{
	  sprintf (buff, "PDF_FUNCTION (%s)", ptr->expr_str_u.expr_pdf_function_call->fname);
	}
	return acl_strdup(buff);
      break;


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
      sprintf (buff, "_VARIABLE(%s)", local_get_expr_as_string (ptr->expr_str_u.expr_expr));
      return acl_strdup (buff);
      //expr_string

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

	default: 
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
//printf("Buff=%s\n",buff);
  return strdup (buff);
}


#ifdef OLD
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

static char *
local_field_name_as_char (char *fname, expr_str * sub)
{
  static char buff[256];
  if (ui_as_calls ())
    {

      if (sub != 0)
	{
	  if (strchr (fname, '.') == 0)
	    {
	      //SPRINTF2 (buff, "%s[%s]", A4GL_strip_quotes (fname), local_get_expr_as_string (sub));
	      //SPRINTF2 (buff, "\"%s[\"||(%s USING \"<<<<<\")||\"]\"", A4GL_strip_quotes (fname), local_get_expr_as_string (sub));
	      SPRINTF2 (buff, "\"%s.\"||(%s USING \"<<<<<\")", A4GL_strip_quotes (fname), local_get_expr_as_string (sub));
	    }
	  else
	    {
	      char *ptr;
	      char *ptr2;
	      ptr = strdup (A4GL_strip_quotes (fname));
	      ptr2 = strchr (ptr, '.');
	      *ptr2 = 0;
	      ptr2++;
	      SPRINTF3 (buff, "\"%s.%s.\"||(%s USING \"<<<<<\")", ptr, ptr2, local_get_expr_as_string (sub));
	      free (ptr);
	    }
	}
      else
	{
	  SPRINTF1 (buff, "\"%s\"", A4GL_strip_quotes (fname));
	}
    }
  else
    {
      if (sub != 0)
	{
	  if (strchr (fname, '.') == 0)
	    {
	      SPRINTF2 (buff, "%s[%s]", A4GL_strip_quotes (fname), local_get_expr_as_string (sub));
	    }
	  else
	    {
	      char *ptr;
	      char *ptr2;
	      ptr = strdup (A4GL_strip_quotes (fname));
	      ptr2 = strchr (ptr, '.');
	      *ptr2 = 0;
	      ptr2++;
	      SPRINTF3 (buff, "%s[%s].%s", ptr, local_get_expr_as_string (sub), ptr2);
	      free (ptr);
	    }
	}
      else
	{
	  SPRINTF1 (buff, "%s", A4GL_strip_quotes (fname));
	}
    }
  return buff;
}
#endif

static char *
xfield_name_list_as_char (struct fh_field_list *fl)
{
  int a;
  static char buff[65000];
  if (fl == 0)
    return "";
  if (fl->field_list_entries.field_list_entries_len == 0)
    return "";
  strcpy (buff, "");
  for (a = 0; a < fl->field_list_entries.field_list_entries_len; a++)
    {
      if (a)
	strcat (buff, ",");
      strcat (buff, xfield_name_as_char (&fl->field_list_entries.field_list_entries_val[a]));
    }

  return buff;
}

static char *
xfield_name_as_char (struct fh_field_entry *f)
{
  struct expr_str *p;
  static char buff[2000];
  static char next[2000];
	char *ptr;
  if (f == 0)
    return "";
  p = f->field;
  strcpy (buff, p->expr_str_u.expr_string);
  ptr=strchr(buff,'.');

  if (ptr)  {
	*ptr=0;
	ptr++;
	sprintf(next,".%s",ptr);
  }

  if (f->fieldsub)
    {
      strcat (buff, "[");
      strcat(buff, local_get_expr_as_string (f->fieldsub));
      strcat (buff, "]");
    }

  if (ptr) strcat(buff,next);

  // s = local_field_name_as_char (f->field_name, f->field_sub);
  return buff;
}



static void
real_print_field_list_with_separator (struct fh_field_list *fl, char *sep)
{
  int a;
  for (a = 0; a < fl->field_list_entries.field_list_entries_len; a++)
    {
      if (a)
	printc ("%s", sep);
      printc ("%s", xfield_name_as_char (&fl->field_list_entries.field_list_entries_val[a]));
    }
}

static void
real_print_field_list (struct fh_field_list *fl)
{
  int a;
  for (a = 0; a < fl->field_list_entries.field_list_entries_len; a++)
    {
      if (a)
	printc (",");
      printc ("%s", xfield_name_as_char (&fl->field_list_entries.field_list_entries_val[a]));
    }
}



/******************************************************************/
/* VARIABLE HANDLING */
/******************************************************************/


static enum e_scope get_var_expr_scope (struct expr_str *p)
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
return get_variable_dtype_from_variable_usage_expression(errbuff, p);
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
		need_daylight(); //printc ("#");
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
		  need_daylight(); //printc ("#");
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
print_define_char (char *var, int size, int isstatic_extern, int lvl, int vno, char *defsrc)
{
  char buff[20];
  char *comma;
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



  if (lvl)
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
	  printc ("DEFINE %-18s%s%s\n", var, buff, comma);
	}
      else
	{
	  printc ("DEFINE %-18s%s(%d)%s\n", var, buff, size, comma);
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
print_define (char *varstring, int isstatic_extern, int lvl, int vno)
{
  char buff[20];
  char *comma;

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



  if (lvl)
    {
      printc ("%-18s%s%s\n", varstring, buff, comma);
    }
  else
    {
      printc ("DEFINE %-18s%s%s\n", varstring, buff, comma);
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

  if (level == 0)
    {
      need_daylight(); //printc ("#");
      if (v->arr_subscripts.arr_subscripts_len)
	{
	  char arrbuff[256];
	  make_arr_str (arrbuff, v);
	  printc ("DEFINE %s ARRAY[%s] OF RECORD \n", varname, arrbuff);
	}
      else
	{
	  printc ("DEFINE %s RECORD \n", varname);
	}
    }
  else
    {
      if (v->arr_subscripts.arr_subscripts_len)
	{
	  char arrbuff[256];
	  make_arr_str (arrbuff, v);
	  printc ("%s ARRAY[%s] OF RECORD \n", varname, arrbuff);
	}
      else
	{
	  printc ("%s RECORD \n", varname);
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
  //int arrsizes[10];
  tmp_ccntminus ();
  printc ("END RECORD\n");
  need_daylight(); //printc ("#");
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
  if (level == 0
      && local_is_system_variable (v->names.names.names_val[0].name)
      && (strcmp (acl_getenv ("A4GL_LEXTYPE"), "CM") == 0 || strcasecmp (v->names.names.names_val[0].name, "int_flag") == 0))
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
  strcpy (name, v->names.names.names_val[0].name);
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
		  SPRINTF2 (name, "M_%s_%s", A4GL_compiling_module (), v->names.names.names_val[0].name);
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
      char stmpbuff[256] = "";
      char *s;

      sprintf (tmpbuff, "%-18s", name);
      if (v->arr_subscripts.arr_subscripts_len)
	{
	  char arrbuff[256];
	  strcat (tmpbuff, " ARRAY");
	  strcat (tmpbuff, "[");
	  make_arr_str (arrbuff, v);
	  strcat (tmpbuff, arrbuff);
	  strcat (tmpbuff, "] OF");
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
				 v->var_data.variable_data_u.v_simple.dimensions[0], static_extern_flg, level, vno, v->defsrc);
	    }
	  else
	    {
	      print_define_char (tmpbuff, v->var_data.variable_data_u.v_simple.dimensions[0], static_extern_flg, level, vno, v->defsrc);	// Allow extra space to store the size...
	    }
	}
      else
	{
	  print_define (tmpbuff, static_extern_flg, level, vno);
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
	  if (vno)
	    printc (",");
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

      /*print_declare_associate_2 (v->names.name,buff1,buff2); */

      memcpy (&v2, v->var_data.variable_data_u.v_assoc.variable, sizeof (struct variable));

      /* v2.names.next = 0; */
      v2.names.names.names_val[0].name = v->names.names.names_val[0].name;

      print_variable_new (&v2, scope, level + 1);
      return;
    }

  if (v->var_data.variable_type == VARIABLE_TYPE_CONSTANT)
    {
      /* Maybe we should print out #define's for these ? */
      /* Maybe not - they should already have been converted by lexer.c */
      print_Constant_1 (v->names.names.names_val[0].name, &v->var_data.variable_data_u.v_const);
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
  strcat (filename_outfile, ".fgl");

  if (override)
    {
      strcpy (filename_outfile, override);
    }

  strcat (filename_for_c, ".fglt");
  strcat (filename_for_h, ".fglh");

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


static char *get_orig_from_clobber(char *s) {
int a;
	for (a=0;a<curr_module->clobberings.clobberings_len;a++) {
		if (strcmp(curr_module->clobberings.clobberings_val[a].newval,s)==0) {
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

  if (m->mod_dbname && strlen (m->mod_dbname) && m->global_files->str_list_entry.str_list_entry_len == 0)
    {
      if (m->schema_only == EB_TRUE)
	{
	  printc ("SCHEMA %s", m->mod_dbname);
	}
      else
	{
	  if (m->global_files->str_list_entry.str_list_entry_len == 0)
	    {			// We'll assume its set in a globals instead...
	      printc ("DATABASE %s", m->mod_dbname);
	    }
	}
    }

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

  if (m->module_variables.variables.variables_len)
    {
      for (a = 0; a < m->module_variables.variables.variables_len; a++)
	{
	  print_variable_new (m->module_variables.variables.variables_val[a], 'M', 0);
	}
    }
  A4GL_debug ("Dump 3");

//printf("DUMPING %d entries\n", m->module_entries.module_entries_len);
  for (mentry = 0; mentry < m->module_entries.module_entries_len; mentry++)
    {
      int ok = 1;

      current_entry = m->module_entries.module_entries_val[mentry];
      //printf("DUMPING entry %d\n", mentry);

      switch (m->module_entries.module_entries_val[mentry]->met_type)
	{
	  // case E_MET_IMPORT_FUNCTION_DEFINITION:  struct s_import_function_definition import_function_definition;
	  // case E_MET_IMPORT_LEGACY_DEFINITION:    struct s_import_legacy_definition       import_legacy_definition;

	case E_MET_REPORT_DEFINITION:
	  ok = dump_report (&m->module_entries.module_entries_val[mentry]->module_entry_u.report_definition);
	  break;
	case E_MET_PDF_REPORT_DEFINITION:
	  ok = dump_pdf_report (&m->module_entries.module_entries_val[mentry]->module_entry_u.pdf_report_definition);
	  break;
	case E_MET_CMD:
	  ok = dump_cmd (m->module_entries.module_entries_val[mentry]->module_entry_u.cmd, 0);
	  break;
	case E_MET_MAIN_DEFINITION:
	  ok = dump_function (&m->module_entries.module_entries_val[mentry]->module_entry_u.function_definition, 1);
	  break;
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
      //if (!printed) {
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
	  strcpy (buff, "#");
	  break;
	case '.':
	  strcpy (buff, "");
	  break;
	default:
	  sprintf (buff, "# (%c)", type);
	  break;
	}
      //}

      printed++;
      if (strlen (ptr) > 1 && buff[0] == '{')
	{
	  char *p;
	  p = strdup (ptr);
	  //A4GL_lrtrim(p);
	  need_daylight(); ////printc ("#");
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
get_variable_usage (struct variable_usage *var_usage)
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
	  sprintf (buff, "status");
	}
      else
	{
	  sprintf (buff, "%s", var_usage->variable_name);
	}
    }
  if (var_usage->subscripts.subscripts_len)
    {
      int a;
      strcat (buff, "[");
      for (a = 0; a < var_usage->subscripts.subscripts_len; a++)
	{
	  if (a)
	    strcat (buff, ",");
	  l = local_get_expr_as_string (var_usage->subscripts.subscripts_val[a]);
	  strcat (buff, l);
	  free (l);
	}
      strcat (buff, "]");
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
      strcat (buff, ".");
      p = get_variable_usage (var_usage->next);
      strcat (buff, p);
      free (p);
    }
  return strdup (buff);
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
dump_report (struct s_report_definition *report_definition)
{
  int a;
  printc ("#");
  printc ("#");
  printc ("#");
  dump_comments (report_definition->lineno);
  set_nonewlines ();
  printc ("REPORT %s (", report_definition->funcname);

  if (report_definition->parameters)
    {
      if (report_definition->parameters->list.list_len)
	{
	  //int skipped;
	  //char isrec[256] = "";
	  for (a = 0; a < report_definition->parameters->list.list_len; a++)
	    {
	      struct expr_str *param;
	      if (a)
		printc (",");
	      param = report_definition->parameters->list.list_val[a];
	      A4GL_assertion (param->expr_type != ET_EXPR_PARAMETER, "Invalid parameter type");
	      printc ("%s", report_definition->parameters->list.list_val[a]->expr_str_u.expr_string);
	    }
	}

    }
  printc (")");
  clr_nonewlines ();
  tmp_ccnt++;

  if (report_definition->variables.variables.variables_len)
    {
      for (a = 0; a < report_definition->variables.variables.variables_len; a++)
	{
	  print_variable_new (report_definition->variables.variables.variables_val[a], 'L', 0);
	}
    }

  need_daylight(); //printc ("#");
  if (report_definition->report_output_section != 0)
    {
      printc ("OUTPUT");

      tmp_ccnt++;
      switch (report_definition->report_output_section->towhat)
	{
	case '-':
	  break;

	case 'P':
	case '|':
	  if (report_definition->report_output_section->s1->expr_type == ET_EXPR_REPORT_PRINTER)
	    {
	      printc ("REPORT TO PRINTER");
	    }
	  else
	    {
	      set_nonewlines ();
	      printc ("REPORT TO PIPE ");
	      real_print_expr (report_definition->report_output_section->s1);
	      clr_nonewlines ();
	    }
	  break;

	case '@':
	  printc ("REPORT TO EMAIL");
	  break;

	case 'F':
	  set_nonewlines ();
	  printc ("REPORT TO ");
	  if (report_definition->report_output_section->s1->expr_type == ET_EXPR_LITERAL_STRING)
	    {
	      printc ("%s", report_definition->report_output_section->s1->expr_str_u.expr_string);
	    }
	  else
	    {
	      real_print_expr (report_definition->report_output_section->s1);
	    }
	  clr_nonewlines ();
	  break;
	}
      printc ("PAGE LENGTH %d", report_definition->report_output_section->with_page_length);
      printc ("LEFT MARGIN %d", report_definition->report_output_section->with_left_margin);
      printc ("RIGHT MARGIN %d", report_definition->report_output_section->with_right_margin);
      printc ("TOP MARGIN %d", report_definition->report_output_section->with_top_margin);
      printc ("BOTTOM MARGIN %d", report_definition->report_output_section->with_bottom_margin);

      if (strlen (report_definition->report_output_section->with_top_of_page))
	{
	  printc ("TOP OF PAGE %s ", report_definition->report_output_section->with_top_of_page);
	}

      tmp_ccnt--;
    }

// orderby
  if (report_definition->report_orderby_section->rord_type)
    {
      need_daylight(); //printc ("#");
      switch (report_definition->report_orderby_section->rord_type)
	{
	case REPORT_ORDERBY_IMPLICIT:
	  break;
	case REPORT_ORDERBY_EXTERNAL:
	  set_nonewlines ();

	  printc ("ORDER EXTERNAL BY ");
	  for (a = 0; a < report_definition->report_orderby_section->variables->list.list_len; a++)
	    {
		struct expr_str *e;
		struct variable_usage_with_asc_desc *v;
		e=report_definition->report_orderby_section->variables->list.list_val[a];
		A4GL_assertion(e->expr_type!=ET_EXPR_VARIABLE_USAGE_WITH_ASC_DESC,"Expecting a ET_EXPR_VARIABLE_USAGE_WITH_ASC_DESC");
		v=e->expr_str_u.expr_variable_usage_with_asc_desc;

	      if (a)
		printc (",");

	      if (v->asc_desc == 'D')
		{
		  print_varbind (e, 'r', a);
		  printc (" DESC");
		}
	      else
		{
		  print_varbind (e, 'r', a);

		}
	    }
	  clr_nonewlines ();
	  break;

	case REPORT_ORDERBY:
	  set_nonewlines ();
	  printc ("ORDER BY ");
	  for (a = 0; a < report_definition->report_orderby_section->variables->list.list_len; a++)
	    {
		struct expr_str *e;
		struct variable_usage_with_asc_desc *v;
		e=report_definition->report_orderby_section->variables->list.list_val[a];
		A4GL_assertion(e->expr_type!=ET_EXPR_VARIABLE_USAGE_WITH_ASC_DESC,"Expecting a ET_EXPR_VARIABLE_USAGE_WITH_ASC_DESC");
		v=e->expr_str_u.expr_variable_usage_with_asc_desc;

	      if (a) printc (",");

	      if (v->asc_desc == 'D')
		{
		  print_varbind (e, 'r', a);
		  printc ("DESC");
		}
	      else
		{
		  print_varbind (e, 'r', a);

		}
	    }
	  clr_nonewlines ();
	  break;

	}
    }


// format
  need_daylight(); //printc ("#");
  printc ("FORMAT");
  tmp_ccnt++;
  for (a = 0; a < report_definition->report_format_section->entries.entries_len; a++)
    {
      report_format_section_entry *re;
      re = report_definition->report_format_section->entries.entries_val[a];
      need_daylight(); //printc ("#");
      switch (re->rb_block.rb)
	{
	case RB_FIRST_PAGE_HEADER:
	  printc ("FIRST PAGE HEADER");
	  break;
	case RB_PAGE_HEADER:
	  printc ("PAGE HEADER");
	  break;
	case RB_PAGE_TRAILER:
	  printc ("PAGE TRAILER");
	  break;
	case RB_ON_EVERY_ROW:
	  printc ("ON EVERY ROW");
	  break;
	case RB_ON_LAST_ROW:
	  printc ("ON LAST ROW");
	  break;

	case RB_FORMAT_EVERY_ROW:
	  printc ("EVERY ROW");
	  break;

	case RB_BEFORE_GROUP_OF:
	  printc ("BEFORE GROUP OF ");
	  print_varbind (re->rb_block.report_block_data_u.bf_variable, 'r', a);
	  break;
	case RB_AFTER_GROUP_OF:
	  printc ("AFTER GROUP OF ");
	  print_varbind (re->rb_block.report_block_data_u.bf_variable, 'r', a);
	  break;
	}
      tmp_ccnt++;
      dump_cmds (re->rep_sec_commands, NULL);
      tmp_ccnt--;
    }
  tmp_ccnt--;			// FORMAT


  tmp_ccnt--;			// REPORT
  printc ("END REPORT");
  return 1;
}


static int
dump_cmds (struct commands *c, struct command *parent)
{
  int a;
  if (c == 0)
    return 1;

  command_nest[command_nest_cnt] = parent;
  command_nest_cnt++;

  for (a = 0; a < c->cmds.cmds_len; a++)
    {
      if (!dump_cmd (c->cmds.cmds_val[a], parent))
	return 0;
    }

  command_nest_cnt--;
  A4GL_assertion (command_nest_cnt < 0, "command_nest_cnt corrupted");
  command_nest[command_nest_cnt] = 0;
  return 1;
}

static int
dump_pdf_report (struct s_pdf_report_definition *pdf_report_definition)
{
  return 1;
}

static int
dump_function (struct s_function_definition *function_definition, int ismain)
{

  int a;
  printc ("#");
  printc ("#");
  printc ("#");
  dump_comments (function_definition->lineno);
  if (is_on_list (LIST_BLACKLIST, function_definition->funcname))
    {
      printc ("# Skipping function %s", function_definition->funcname);
      dump_comments (function_definition->lastlineno);
      return 1;
    }

  when_set_to_call = 0;

  if (ismain || strcmp (function_definition->funcname, "MAIN") == 0)
    {
      printc ("MAIN");
    }
  else
    {
      set_nonewlines ();
      printc ("FUNCTION %s (", function_definition->funcname);

      if (function_definition->parameters)
	{
	  //int skipped;
	  //char isrec[256] = "";
	  for (a = 0; a < function_definition->parameters->list.list_len; a++)
	    {
	      struct expr_str *param;
	      if (a)
		printc (",");
	      param = function_definition->parameters->list.list_val[a];
	      A4GL_assertion (param->expr_type != ET_EXPR_PARAMETER, "Invalid parameter type");
	      printc ("%s", function_definition->parameters->list.list_val[a]->expr_str_u.expr_param.expr_string);
	    }
	}
      printc (")");
      clr_nonewlines ();
    }


  printc ("#!!FUNCTION %s", function_definition->funcname);
// local variables...

  if (function_definition->variables.variables.variables_len)
    {
      for (a = 0; a < function_definition->variables.variables.variables_len; a++)
	{
	  print_variable_new (function_definition->variables.variables.variables_val[a], 'L', 0);
	}
    }

  tmp_ccnt++;

  need_daylight(); //printc ("#");

  if (ismain || strcmp (function_definition->funcname, "MAIN") == 0)
    {
      if (ui_as_calls ())
	{
	  printc ("IF NOT UILIB_START(arg_val(0)) THEN");
	  tmp_ccnt++;
	  printc ("DISPLAY \"UNABLE TO START UI PROCESS\"");
	  printc ("EXIT PROGRAM 1");
	  tmp_ccnt--;
	  printc ("END IF");
	  need_daylight(); //printc ("#");

	}
    }

  if (A4GL_isyes (acl_getenv ("TRACE4GL")))
    {
      printc ("CALL trace_4gl(\"In function %s\")", function_definition->funcname);
    }

  if (function_definition->func_commands)
    {
      for (a = 0; a < function_definition->func_commands->cmds.cmds_len; a++)
	{
	  dump_cmd (function_definition->func_commands->cmds.cmds_val[a], 0);
	}
    }

  dump_comments (function_definition->lastlineno);

  if (ismain || strcmp (function_definition->funcname, "MAIN") == 0)
    {
      if (ui_as_calls ())
	{
	  printc ("CALL UILIB_PROGRAM_EXIT(0)");
	}
      tmp_ccnt--;

      need_daylight(); //printc ("#");
      printc ("END MAIN");
    }
  else
    {
      tmp_ccnt--;
      need_daylight(); //printc ("#");
      if (tmp_ccnt)
	{
	  A4GL_assertion (1, "tmp_ccnt shouldn't be set...");
	}
      if (nonewlines)
	{
	  A4GL_assertion (1, "nonewlines shouldn't be set...");
	}
      if (A4GL_isyes (acl_getenv ("TRACE4GL")))
	{
	  printc ("CALL trace_4gl(\"END FUNCTION\")");
	}
      printc ("END FUNCTION");
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
      A4GL_assertion (1, "Unhandled event type");
    }

  A4GL_assertion (1, "UNKNOWN event ID");
  return "";

}

static void  print_menu_option (expr_str *s) {
        switch (s->expr_type) {
                case ET_EXPR_MENU_ALL:
                        printc("ALL");
                        break;
                case ET_EXPR_LITERAL_STRING:
                        printc("%s", s->expr_str_u.expr_string);
                        break;
                default:
                        printc("%s", local_get_expr_as_string(s));
                        break;
        }
        //A4GL_assertion(1,"Not implemented");
}

static void print_menu_option_list(expr_str_list *slist ) {
        int a;
        for (a=0;a<slist->list.list_len;a++) {
                if (a) printc(",");
                print_menu_option(slist->list.list_val[a]);
        }
}


static void
print_event_list (on_events * e, int isMenu)
{
  int an_event;
  //int n;
  int b;
  //int *keys;
//char comma=' ';
  //char **fields;

  if (!ui_as_calls ())
    return;
  if (e == 0)
    return;


  if (!isMenu)
    printc ("CALL UILIB_START_EVENTS()");

  for (an_event = 0; an_event < e->event.event_len; an_event++)
    {
      on_event *ee;
      ee = e->event.event_val[an_event];



      switch (ee->evt_data.event_type)
	{

	case EVENT_BEFORE_INPUT:
	case EVENT_BEFORE_MENU:
	case EVENT_BEFORE_DISPLAY:
	case EVENT_BEFORE_CONSTRUCT:
	  break;		// Do nothing - its handled internally

	case EVENT_KEY_PRESS:
	  for (b = 0; b < ee->evt_data.event_data_u.key->str_list_entry.str_list_entry_len; b++)
	    {
	      printc ("CALL UILIB_EVENT(%d,\"ONKEY\",\"%s\")", an_event + 1,
		      ee->evt_data.event_data_u.key->str_list_entry.str_list_entry_val[b]);
	    }
	  break;

	case EVENT_AFTER_INPUT:
	case EVENT_AFTER_DISPLAY:
	case EVENT_AFTER_CONSTRUCT:
	case EVENT_BEF_ROW:
	case EVENT_AFT_ROW:
	case EVENT_BEFORE_DELETE:
	case EVENT_AFTER_DELETE:
	case EVENT_BEFORE_INSERT:
	case EVENT_AFTER_INSERT:
	case EVENT_BEFORE_INSERT_DELETE:
	case EVENT_AFTER_INSERT_DELETE:
	case EVENT_ANYKEY_PRESS:
	  printc ("CALL UILIB_EVENT(%d,\"%s\",\"\")", an_event + 1, decode_event_id (ee->evt_data.event_type));
	  break;

	case EVENT_BEFORE_FIELD:
	  for (b = 0; b < ee->evt_data.event_data_u.before_field->field_list_entries.field_list_entries_len; b++)
	    {
	      printc ("CALL UILIB_EVENT(%d,\"%s\",%s)", an_event + 1,
		      decode_event_id (ee->evt_data.event_type),
		      xfield_name_as_char (&ee->evt_data.event_data_u.before_field->field_list_entries.field_list_entries_val[b]));
	    }
	  break;
	case EVENT_AFTER_FIELD:
	  for (b = 0; b < ee->evt_data.event_data_u.after_field->field_list_entries.field_list_entries_len; b++)
	    {
	      printc ("CALL UILIB_EVENT(%d,\"%s\",%s)", an_event + 1,
		      decode_event_id (ee->evt_data.event_type),
		      xfield_name_as_char (&ee->evt_data.event_data_u.after_field->field_list_entries.field_list_entries_val[b]));
	    }
	  break;

	case EVENT_ON_ACTION :
		printc("ON ACTION...");
		break;
	case EVENT_MENU_COMMAND:

	  {
	    menuoption *m;
	    m = ee->evt_data.event_data_u.mnoption;
	    set_nonewlines ();
	    printc ("CALL UILIB_MENU_ADD(UILIB_GET_CONTEXT(%s),%d,", last_context[CONTEXT_MENU], an_event + 1);
	    clr_nonewlines ();
	    tmp_ccnt++;
	    set_nonewlines ();
	    // If we have a BEFORE MENU - we'll send the real values later...
	    if (has_before_menu (e))
	      {
		printc ("\"[PLACEHOLDER%d]\"", an_event + 1);
	      }
	    else
	      {
		real_print_variable_or_literal (m->shortname, "\"\"");
	      }
	    printc (", \"");
	    real_print_trimmed_str_list_with_separator (m->keys, ",");
	    printc ("\",");
	    if (has_before_menu (e))
	      {
		printc ("\"[PLACEHOLDER%d]\"", an_event + 1);
	      }
	    else
	      {
		real_print_variable_or_literal (m->longname, "\"\"");
	      }
	    printc (",%d) #2", m->helpno);
	    tmp_ccnt--;
	    clr_nonewlines ();
	  }
	  break;

	default:
	  A4GL_assertion (1, "Unhandled event type");
	}
    }


  if (!isMenu)
    printc ("CALL UILIB_END_EVENTS()");
}



static char *
chk_key (char *s)
{
  static char buff[200];
  if (strncmp (s, "\"CONTROL -", 10) == 0)
    {
      sprintf (buff, "\"CONTROL-%s", &s[11]);
      return buff;
    }
  if (strncmp (s, "CONTROL -", 9) == 0)
    {
      sprintf (buff, "CONTROL-%s", &s[10]);
      return buff;
    }
  return s;
}



static int
has_before_menu (on_events * es)
{
  int cnt;
  for (cnt = 0; cnt < es->event.event_len; cnt++)
    {
      if (es->event.event_val[cnt]->evt_data.event_type == EVENT_BEFORE_MENU)
	return 1;
    }
  return 0;

}

static void
print_events_as_calls (on_events * es, struct command *parent)
{
  int cnt;
  on_event *e;
  if (es == 0)
    return;

  for (cnt = 0; cnt < es->event.event_len; cnt++)
    {
      need_daylight(); //printc ("#");
      e = es->event.event_val[cnt];

      dump_comments (e->lineno);

      if (e->evt_data.event_type == EVENT_BEFORE_MENU)
	{			// a before menu can change menu options - so resend them
	  int an_event;
	  printc ("WHEN -2 # After a BEFORE MENU");
	  tmp_ccnt++;
	  for (an_event = 0; an_event < es->event.event_len; an_event++)
	    {
	      if (es->event.event_val[an_event]->evt_data.event_type == EVENT_MENU_COMMAND)
		{
		  menuoption *m;
		  m = es->event.event_val[an_event]->evt_data.event_data_u.mnoption;
		  set_nonewlines ();
		  printc ("CALL UILIB_MENU_SET(UILIB_GET_CONTEXT(%s),%d,", last_context[CONTEXT_MENU], an_event + 1);
		  real_print_variable_or_literal (m->shortname, "\"\"");
		  printc (",");
		  real_print_variable_or_literal (m->longname, "\"\"");
		  printc (")");
		  clr_nonewlines ();
		}
	    }
	  tmp_ccnt--;
	}

      switch (e->evt_data.event_type)
	{
	case EVENT_BEFORE_MENU:


	case EVENT_BEFORE_INPUT:
	case EVENT_BEFORE_CONSTRUCT:
	  printc ("WHEN 0");
	  break;
	default:
	  printc ("WHEN %d", cnt + 1);
	}
      tmp_ccnt++;

      if (e->evt_data.event_type != EVENT_BEFORE_MENU && e->evt_data.event_type != EVENT_BEFORE_INPUT
	  && e->evt_data.event_type != EVENT_BEFORE_CONSTRUCT)
	{
	  if (parent->cmd_data.type == E_CMD_INPUT_ARRAY_CMD)
	    {
	      printc ("WHILE TRUE # JUST RETRIVE VALUES THAT HAVE CHANGED");
	      printc ("   LET gc_arr_cnt=UILIB_HAS_ARRAY_VALUES(UILIB_GET_CONTEXT(%s))", last_context[CONTEXT_INPUT]);
	      printc ("   IF gc_arr_cnt<=0 THEN");
	      printc ("       EXIT WHILE");
	      printc ("   END IF");
	      if (use_input_array_star)
		{
		  printc ("   CALL UILIB_INPUT_GET_ARRAY_VALUES(UILIB_GET_CONTEXT(%s),gc_arr_cnt) RETURNING %s[gc_arr_cnt].* ",
			  last_context[CONTEXT_INPUT], input_list);
		}
	      else
		{
		  printc ("   CALL UILIB_INPUT_GET_ARRAY_VALUES(UILIB_GET_CONTEXT(%s),gc_arr_cnt) RETURNING %s[gc_arr_cnt] ",
			  last_context[CONTEXT_INPUT], input_list);
		}
	      printc ("END WHILE");

	    }
	  if (parent->cmd_data.type == E_CMD_INPUT_CMD)
	    {
	      printc_safe_to_split_at_comma ("CALL UILIB_INPUT_GET_VALUES(UILIB_GET_CONTEXT(%s)) RETURNING %s #2",
					     last_context[CONTEXT_INPUT], input_list);

	    }
	}

      //if (A4GL_isyes(acl_getenv("TRACE4GL"))) {
      //printc("CALL trace_4gl('EVENT %d fired')", cnt+1);
      //}

      dump_cmds (e->on_event_commands, parent);
      tmp_ccnt--;
    }
}



static void
print_events_as_4gl (on_events * es, struct command *parent)
{
  int cnt;
  int a;
  on_event *e;
  if (es == 0)
    return;

  for (cnt = 0; cnt < es->event.event_len; cnt++)
    {
      need_daylight(); //printc ("#");
      e = es->event.event_val[cnt];

      dump_comments (e->lineno);

      switch (e->evt_data.event_type)
	{
	case EVENT_BEF_ROW:
	  printc ("BEFORE ROW");
	  break;

	case EVENT_AFT_ROW:
	  printc ("AFTER ROW");
	  break;

	case EVENT_BEFORE_DELETE:
	  printc ("BEFORE DELETE");
	  break;

	case EVENT_AFTER_DELETE:
	  printc ("AFTER DELETE");
	  break;

	case EVENT_BEFORE_INSERT:
	  printc ("BEFORE INSERT");
	  break;

	case EVENT_AFTER_INSERT:
	  printc ("AFTER INSERT");
	  break;

	case EVENT_BEFORE_INSERT_DELETE:
	  printc ("BEFORE INSERT DELETE");
	  break;

	case EVENT_AFTER_INSERT_DELETE:
	  printc ("AFTER INSERT DELETE");
	  break;

	case EVENT_ANYKEY_PRESS:
	  printc ("ON ANY KEY");
	  break;


	case EVENT_ON_IDLE:
	  printc ("ON IDLE (%d)", e->evt_data.event_data_u.idle_n);

	case EVENT_ON_INTERVAL:
	  printc ("ON INTERVAL (%d)", e->evt_data.event_data_u.interval_n);

	case EVENT_ON_TIME:
	  printc ("ON TIME(%d)", e->evt_data.event_data_u.time_n);

	case EVENT_KEY_PRESS:
	  set_nonewlines ();
	  printc (" ON KEY (");
	  for (a = 0; a < e->evt_data.event_data_u.key->str_list_entry.str_list_entry_len; a++)
	    {
	      if (a)
		printc (",");
	      printc ("%s", chk_key (e->evt_data.event_data_u.key->str_list_entry.str_list_entry_val[a]));
	    }
	  printc (")");
	  clr_nonewlines ();
	  break;

	case EVENT_ON_ACTION:
	  set_nonewlines ();
	  printc (" ON ACTION %s", e->evt_data.event_data_u.on_action);
	  clr_nonewlines ();
	  break;

	case EVENT_AFTER_INPUT:
	  printc ("AFTER INPUT");
	  break;

	case EVENT_BEFORE_INPUT:
	  printc ("BEFORE INPUT");
	  break;

	case EVENT_AFTER_DISPLAY:
	  printc ("AFTER DISPLAY");
	  break;

	case EVENT_BEFORE_DISPLAY:
	  printc ("BEFORE DISPLAY");
	  break;

	case EVENT_AFTER_CONSTRUCT:
	  printc ("AFTER CONSTRUCT");
	  break;

	case EVENT_BEFORE_CONSTRUCT:
	  printc ("BEFORE CONSTRUCT");
	  break;

	case EVENT_BEFORE_MENU:
	  printc ("BEFORE MENU");
	  break;

	case EVENT_BEFORE_EVENT:
	  printc ("BEFORE EVENT");
	  break;
	case EVENT_AFTER_EVENT:
	  printc ("AFTER EVENT");
	  break;
	case EVENT_BEFORE_OPEN_FORM:
	  printc ("BEFORE OPEN FORM");
	  break;
	case EVENT_BEFORE_CLOSE_FORM:
	  printc ("BEFORE CLOSE FORM");
	  break;
	case EVENT_BEFORE_ANY:
	  printc ("BEFORE ANY");
	  break;
	case EVENT_AFTER_ANY:
	  printc ("AFTER ANY");
	  break;
	case EVENT_BEFORE:
	  {
	    int a;
	    set_nonewlines ();
	    printc ("BEFORE ");
	    for (a = 0; a < e->evt_data.event_data_u.before->str_list_entry.str_list_entry_len; a++)
	      {
		if (a)
		  printc (",");
		printc ("%s", e->evt_data.event_data_u.before->str_list_entry.str_list_entry_val[a]);
	      }
	    clr_nonewlines ();
	  }
	  break;

	case EVENT_AFTER:
	  {
	    int a;
	    set_nonewlines ();
	    printc ("AFTER ");
	    for (a = 0; a < e->evt_data.event_data_u.after->str_list_entry.str_list_entry_len; a++)
	      {
		if (a)
		  printc (",");
		printc ("%s", e->evt_data.event_data_u.after->str_list_entry.str_list_entry_val[a]);
	      }
	    clr_nonewlines ();
	  }
	  break;

	case EVENT_ON:
	  {
	    int a;
	    set_nonewlines ();
	    printc ("ON ");
	    for (a = 0; a < e->evt_data.event_data_u.after->str_list_entry.str_list_entry_len; a++)
	      {
		if (a)
		  printc (",");
		printc ("%s", e->evt_data.event_data_u.on->str_list_entry.str_list_entry_val[a]);
	      }
	    clr_nonewlines ();
	  }
	  break;


	case EVENT_AFTER_INP_CLEAN:
	  // internal - not used...
	  break;



	case EVENT_BEFORE_FIELD:
	  set_nonewlines ();
	  printc ("BEFORE FIELD ");
	  real_print_field_list (e->evt_data.event_data_u.before_field);
	  clr_nonewlines ();
	  break;

	case EVENT_AFTER_FIELD:
	  set_nonewlines ();
	  printc ("AFTER FIELD ");
	  real_print_field_list (e->evt_data.event_data_u.before_field);
	  clr_nonewlines ();
	  break;

	case EVENT_MENU_COMMAND:
	  set_nonewlines ();
	  printc ("COMMAND");
	  if (e->evt_data.event_data_u.mnoption->keys)
	    {
	      if (e->evt_data.event_data_u.mnoption->keys->str_list_entry.str_list_entry_len)
		{
		  printc (" KEY (");
		  for (a = 0; a < e->evt_data.event_data_u.mnoption->keys->str_list_entry.str_list_entry_len; a++)
		    {
		      if (a)
			printc (",");
		      printc ("\"%s\"", chk_key (e->evt_data.event_data_u.mnoption->keys->str_list_entry.str_list_entry_val[a]));
		    }
		  printc (")");
		}
	    }

	  if (e->evt_data.event_data_u.mnoption->shortname)
	    {
	      printc (" ");
	      real_print_variable_or_literal (e->evt_data.event_data_u.mnoption->shortname, "\"\"");
	      if (e->evt_data.event_data_u.mnoption->longname)
		{
		  printc (" ");
		  real_print_variable_or_literal (e->evt_data.event_data_u.mnoption->longname, "\"\"");
		}
	    }

	  if (e->evt_data.event_data_u.mnoption->helpno)
	    {
	      printc (" HELP %d", e->evt_data.event_data_u.mnoption->helpno);
	    }
	  clr_nonewlines ();
	  break;
	}
      tmp_ccnt++;
      dump_cmds (e->on_event_commands, parent);
      tmp_ccnt--;
    }
}

static void
print_events (on_events * es, struct command *parent)
{
  if (ui_as_calls ())
    {
      print_events_as_calls (es, parent);

    }
  else
    {
      print_events_as_4gl (es, parent);
    }

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
	default: 
		A4GL_assertion(1,"Not expecting this MET type");
		exit(3);

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


/**
 * Print the generated C code that implements the INPUT ARRAY 4gl statement.
 *
 * @param arrvar
 * @param helpno
 * @param defs
 * @param srec
 * @param attr
 */
static void
print_input_array (struct expr_str *arrvar, int helpno, int defs, struct expr_str *srec, attrib * attrib, char *slice)
{
  int a0;
  struct variable *v;
  int rec_len;
  doing_input_array++;



  input_array_variable = arrvar;
  v = find_top_var (arrvar);
  A4GL_assertion (v == 0, "Cant find variable for input array");
  A4GL_assertion (v->arr_subscripts.arr_subscripts_len != 1, "Variable is not an array");
  if (v->var_data.variable_type == VARIABLE_TYPE_SIMPLE)
    {
      rec_len = 1;
    }
  else
    {
      rec_len = v->var_data.variable_data_u.v_record.variables.variables_len;
    }
  a0 = v->arr_subscripts.arr_subscripts_val[0];
  if (ui_as_calls ())
    {
      chk_context (CONTEXT_INPUT);
      sprintf (last_context[CONTEXT_INPUT], "\"%s\",%d", ofilename, curr_yylineno);
      printc_safe_to_split_at_comma ("CALL UILIB_SET_FIELD_LIST(\"");
      print_ident (srec);
      printc (".*\")");
      printc ("CALL UILIB_INPUT_ARRAY_START(%s, %d,%s,%d,%d)", last_context[CONTEXT_INPUT], defs, attributes_as_string (attrib), a0,
	      rec_len);
      printc ("WHILE TRUE # INPUT ARRAY");
      tmp_ccnt++;
      need_daylight(); //printc ("#");
      if (defs)
	{
	  //printc("CALL UILIB_ARRAY_LINES_START()");
	  printc ("FOR gc_arr_cnt=1 TO UILIB_arr_count()");
	  if (v->var_data.variable_type == VARIABLE_TYPE_RECORD)
	    {
	      printc ("   CALL UILIB_INPUT_ARRAY_SYNC(UILIB_GET_CONTEXT(%s), gc_arr_cnt, %s[gc_arr_cnt].*)",
		      last_context[CONTEXT_INPUT], local_get_expr_as_string(arrvar));
	      use_input_array_star = 1;
	    }
	  else
	    {
	      printc ("   CALL UILIB_INPUT_ARRAY_SYNC(UILIB_GET_CONTEXT(%s), gc_arr_cnt, %s[gc_arr_cnt])",
		      last_context[CONTEXT_INPUT], local_get_expr_as_string(arrvar));
	      use_input_array_star = 0;
	    }
	  printc ("END FOR");
	  //printc("CALL UILIB_ARRAY_LINES_END()");
	}
      need_daylight(); //printc ("#");
      printc ("CASE UILIB_INPUT_ARRAY_LOOP(UILIB_GET_CONTEXT(%s)) ", last_context[CONTEXT_INPUT]);
      need_daylight(); //printc ("#");
      sprintf (input_list, "%s", local_get_expr_as_string (arrvar));
      tmp_ccnt++;
      printc ("WHEN -100 # ACCEPT (2)");
      if (A4GL_isyes (acl_getenv ("TRACE4GL")))
	{
	  printc ("CALL trace_4gl(\"ACCEPT PRESSED\")");
	}
      tmp_ccnt++;
      printc ("WHILE TRUE # JUST RETRIVE VALUES THAT HAVE CHANGED");
      printc ("   LET gc_arr_cnt=UILIB_HAS_ARRAY_VALUES(UILIB_GET_CONTEXT(%s))", last_context[CONTEXT_INPUT]);
      printc ("   IF gc_arr_cnt<=0 THEN");
      printc ("       EXIT WHILE");
      printc ("   END IF");
      if (use_input_array_star)
	{
	  printc ("   CALL UILIB_INPUT_GET_ARRAY_VALUES(UILIB_GET_CONTEXT(%s),gc_arr_cnt) RETURNING %s[gc_arr_cnt].* ",
		  last_context[CONTEXT_INPUT], input_list);
	}
      else
	{
	  printc ("   CALL UILIB_INPUT_GET_ARRAY_VALUES(UILIB_GET_CONTEXT(%s),gc_arr_cnt) RETURNING %s[gc_arr_cnt] ",
		  last_context[CONTEXT_INPUT], input_list);
	}
      printc ("END WHILE");
      tmp_ccnt--;
      printc ("   EXIT WHILE");
      need_daylight(); //printc ("#");
      printc ("WHEN -101 # INTERRUPT");
      if (A4GL_isyes (acl_getenv ("TRACE4GL")))
	{
	  printc ("CALL trace_4gl(\"INTERRUPT PRESSED\")");
	}
      printc ("   LET int_flag=TRUE");
      printc ("   EXIT WHILE");
      need_daylight(); //printc ("#");
      strcpy (input_list, local_get_expr_as_string (arrvar));
    }
  else
    {
      set_nonewlines ();
      if (defs)
	{
	  printc ("INPUT ARRAY ");
	  real_print_expr (arrvar);
	  printc (" WITHOUT DEFAULTS FROM ");
	  print_ident (srec);
	  printc (".*");
	}
      else
	{
	  printc ("INPUT ARRAY ");
	  real_print_expr (arrvar);
	  printc (" FROM ");
	  print_ident (srec);
	  printc (".*");
	}
      if (helpno)
	{
	  printc (" HELP %d", helpno);
	}
      if (attrib)
	{
	  if (strlen (get_attributes_as_string (attrib)))
	    {
	      printc (" ATTRIBUTES(");
	      print_attributes (attrib);
	      printc (")");
	    }
	}
      clr_nonewlines ();
      tmp_ccnt++;
    }
}


/**
 *  * The parser found END INPUT and generate all the C code that implements
 *   * the rest of the instruction.
 *    *
 *     * @param s The generated code to call the form loop
 *      *   (generated by get_formloop_str())
 *       */
static void
print_input_2 (void *events)
{

  if (ui_as_calls ())
    {
      need_daylight(); //printc ("#");
      printc ("WHEN -1 # Initialisation");
      tmp_ccnt++;
      print_event_list (events, 0);
      if (doing_input_array)
	{
	  printc ("CALL UILIB_INPUT_ARRAY_INITIALISED()");
	}
      else
	{
	  printc ("CALL UILIB_INPUT_INITIALISED()");
	}
      tmp_ccnt--;
      tmp_ccnt--;

      printc ("END CASE");
      tmp_ccnt--;
      printc ("END WHILE");
      if (doing_input_array)
	{
	  printc ("CALL UILIB_FREE_INPUT_ARRAY(UILIB_GET_CONTEXT(%s))", last_context[CONTEXT_INPUT]);
	}
      else
	{
	  printc ("CALL UILIB_FREE_INPUT(UILIB_GET_CONTEXT(%s))", last_context[CONTEXT_INPUT]);
	}
      doing_input_array = 0;
    }
  else
    {
      tmp_ccnt--;
      if (events)
	{
	  printc ("END INPUT");
	}
      need_daylight(); //printc ("#");
    }
  strcpy (last_context[CONTEXT_INPUT], "");
}

/**
 * The parser found the specification of fields, attributes, help, variables
 * of the INPUT 4gl statement.
 *
 * Prints the C implementation in the generated output file.
 *
 * @param byname Flag that indicates if its an INPUT BY NAME or not:
 *   - 0 : Its not BY NAME.
 *   - Otherwise : Its BY NAME.
 * @param defs : Flag that indicates if its WHITHOUT DEFAULTS INPUT:
 *   - 0 : Its not WHITHOUT DEFAULTS.
 *   - Otherwise : Its WHITHOUT DEFAULTS.
 * @param helpno The help number.
 * @param fldlist The form field list from where the input is made.
 */
static void
print_input_fl_g (int byname, int defs, int helpno, fh_field_list * fldlist_fh, struct attrib *attr, expr_str_list * bind)
{
  //int sio_id;
  int a;
  char *fldlist = 0;

  if (!byname)
    {
      fldlist = xfield_name_list_as_char (fldlist_fh);
    }
  else
    {
      fldlist = "";
    }

  need_daylight(); //printc ("#");

  if (!ui_as_calls ())
    {
      set_nonewlines ();;
      if (byname)
	{
	  printc ("INPUT BY NAME ");
	}
      else
	{
	  printc ("INPUT ");
	}

      for (a = 0; a < bind->list.list_len; a++)
	{
	  if (a)
	    printc (",");
	  print_varbind (bind->list.list_val[a], 'w', a);
	}

      if (defs)
	{
	  printc (" WITHOUT DEFAULTS ");
	}
      clr_nonewlines ();

      if (!byname)
	{
	  printc (" FROM %s", fldlist);
	}

      if (helpno)
	{
	  printc (" HELP %d", helpno);
	}
      tmp_ccnt++;
    }
  else
    {
      //push_blockcommand ("INPUT");
      printc_safe_to_split_at_comma ("CALL UILIB_SET_FIELD_LIST(%s)", fldlist);
      chk_context (CONTEXT_INPUT);
      sprintf (last_context[CONTEXT_INPUT], "\"%s\",%d", ofilename, curr_yylineno);

      printc ("CALL UILIB_INPUT_START(%s, %d,%s)", last_context[CONTEXT_INPUT], defs, attributes_as_string (attr));
      printc ("WHILE TRUE # INPUT");
      tmp_ccnt++;
      if (A4GL_isyes (acl_getenv ("TRACE4GL")))
	{
	  printc ("CALL trace_4gl(\"INPUT LOOP\")");
	}
      set_nonewlines ();;
      printc ("CASE UILIB_INPUT_LOOP(UILIB_GET_CONTEXT(%s),", last_context[CONTEXT_INPUT]);
      strcpy (input_list, "");

      for (a = 0; a < bind->list.list_len; a++)
	{
	  if (a)
	    {
	      printc (",");
	      strcat (input_list, ", ");
	    }
	  print_varbind (bind->list.list_val[a], 'w', a);
	  strcat (input_list, get_variable_usage (bind->list.list_val[a]->expr_str_u.expr_variable_usage));
	}
      printc (")");
      clr_nonewlines ();;
      tmp_ccnt++;
      need_daylight(); //printc ("#");
      printc ("WHEN -100 # ACCEPT (1)");
      if (A4GL_isyes (acl_getenv ("TRACE4GL")))
	{
	  printc ("CALL trace_4gl(\"ACCEPT PRESSED\")");
	}
      printc_safe_to_split_at_comma ("   CALL UILIB_INPUT_GET_VALUES(\n   UILIB_GET_CONTEXT(%s)) ", last_context[CONTEXT_INPUT]);

      printc ("      RETURNING %s #3", input_list);
      printc ("   EXIT WHILE");
      printc ("WHEN -101 # INTERRUPT");
      if (A4GL_isyes (acl_getenv ("TRACE4GL")))
	{
	  printc ("CALL trace_4gl(\"INTERRUPT PRESSED\")");
	}
      printc ("   LET int_flag=TRUE");
      printc ("   EXIT WHILE");

    }
  need_daylight(); //printc ("#");

}


/**
 * Print the third phase of the CONSTRUCT C implementation in the
 * generated C output file.
 *
 * @param byname Flag that indicates if the A4GL_construct is made or not BY NAME:
 *    - 0 : Its not BY NAME.
 *    - 1 : Its BY NAME.
 * @param constr_str : The name of the string where the where is to be build
 * after the user typed the QBE.
 * @param attr The attribute list to be used.
 */
static void
print_construct_fl_g (e_boolean byname, expr_str * bind, t_field_list * field_list, attrib * attrib, cons_list * clist, int helpno)
{
  //int ccc;
  //int k;
  int a;
  char *fld_list = "";

  if (field_list)
    {
      fld_list = xfield_name_list_as_char (field_list);
    }


  if (ui_as_calls ())
    {
      printc_safe_to_split_at_comma ("CALL UILIB_SET_FIELD_LIST(%s)", fld_list);

      set_nonewlines ();
      chk_context (CONTEXT_INPUT);
      sprintf (last_context[CONTEXT_INPUT], "\"%s\",%d", ofilename, curr_yylineno);
      printc ("CALL UILIB_CONSTRUCT_START(%s,", last_context[CONTEXT_INPUT]);
      for (a = 0; a < clist->list.list_len; a++)
	{
	  if (strlen (clist->list.list_val[a]->tabname))
	    {

	      printc ("\"%s.%s\",", clist->list.list_val[a]->tabname, clist->list.list_val[a]->colname);
	    }
	  else
	    {
	      printc ("\"%s\",", clist->list.list_val[a]->colname);
	    }
	}
      printc ("%s)", attributes_as_string (attrib));
      clr_nonewlines ();
      printc ("WHILE TRUE # CONSTRUCT");
      tmp_ccnt++;
      printc ("CASE UILIB_CONSTRUCT_LOOP(UILIB_GET_CONTEXT(%s))", last_context[CONTEXT_INPUT]);
      tmp_ccnt++;
      printc ("WHEN -100 # ACCEPT (3)");
      if (A4GL_isyes (acl_getenv ("TRACE4GL")))
	{
	  printc ("CALL trace_4gl(\"ACCEPT PRESSED\")");
	}
      printc_safe_to_split_at_comma ("   CALL UILIB_CONSTRUCT_QUERY(UILIB_GET_CONTEXT(%s)) #1", last_context[CONTEXT_INPUT]);
      printc ("      RETURNING ");
      print_varbind (bind, 'w', 0);
      printc ("   EXIT WHILE");
      printc ("WHEN -101 # INTERRUPT");
      if (A4GL_isyes (acl_getenv ("TRACE4GL")))
	{
	  printc ("CALL trace_4gl(\"INTERRUPT PRESSED\")");
	}
      printc ("   LET int_flag=TRUE");
      printc ("   EXIT WHILE");


    }
  else
    {
      set_nonewlines ();
      if (byname)
        {
      		printc ("CONSTRUCT BY NAME ");
        }
      else
        {
      		printc ("CONSTRUCT ");
        }

      print_varbind (bind, 'w', 0);
      printc (" ON ");
      for (a = 0; a < clist->list.list_len; a++)
	{
	  if (a)
	    printc (",");
	  if (strlen (clist->list.list_val[a]->tabname))
	    {

	      printc ("%s.%s", clist->list.list_val[a]->tabname, clist->list.list_val[a]->colname);
	    }
	  else
	    {
	      printc ("%s", clist->list.list_val[a]->colname);
	    }
	}

      clr_nonewlines ();
	if (!byname) {
      		printc (" FROM %s", fld_list);
	}
      if (attrib)
	{
	  printc (" ATTRIBUTES(");
	  print_attributes (attrib);
	  printc (")");
	}
      if (helpno)
	{
	  printc (" HELP %d", helpno);
	}
      tmp_ccnt++;
    }
  /* start_bind ('i', 0); */
}


/**
 * Print the second part of 4GL implementation of CONSTRUCT statement
 *
 * @param driver
 */
static void
print_construct_2 (on_events * events)
{
//int sio_id;
  if (ui_as_calls ())
    {
      need_daylight(); //printc ("#");
      printc ("WHEN -1 # Initialisation");
      tmp_ccnt++;
      print_event_list (events, 0);
      printc ("CALL UILIB_CONSTRUCT_INITIALISED()");
      tmp_ccnt--;
      tmp_ccnt--;
      printc ("END CASE");
      tmp_ccnt--;
      printc ("END WHILE");
      printc ("CALL UILIB_FREE_INPUT(UILIB_GET_CONTEXT(%s))", last_context[CONTEXT_INPUT]);
    }
  else
    {
      if (events)
	{
	  printc ("END CONSTRUCT");
	}
      tmp_ccnt--;
    }
  strcpy (last_context[CONTEXT_INPUT], "");
  need_daylight(); //printc ("#");
}



/**
 * The parser found the DISPLAY ARRAY instruction in the source file.
 *
 * It generates the Code for the
 *
 * @todo - Define what is array variable
 *
 * @param arrvar The array variable
 * @param srec The screen record name in the form
 * @param attr The attributes
 */
static void
print_display_array_p1 (expr_str * arrvar, expr_str * srec, char *scroll, attrib * attrib, char *slice)
{
  struct variable *v;
  int rec_len;
  v = find_top_var (arrvar);
  A4GL_assertion (v == 0, "Cant find variable for input array");
  A4GL_assertion (v->arr_subscripts.arr_subscripts_len != 1, "Variable is not an array");
  if (v->var_data.variable_type == VARIABLE_TYPE_SIMPLE)
    {
      rec_len = 1;
    }
  else
    {
      rec_len = v->var_data.variable_data_u.v_record.variables.variables_len;
    }




  if (ui_as_calls ())
    {
      chk_context (CONTEXT_INPUT);
      sprintf (last_context[CONTEXT_INPUT], "\"%s\",%d", ofilename, curr_yylineno);
      printc_safe_to_split_at_comma ("CALL UILIB_SET_FIELD_LIST(\"");
      print_ident (srec);
      printc (".*\")");
      printc ("CALL UILIB_DISPLAY_ARRAY_START(%s,%s)", last_context[CONTEXT_INPUT], attributes_as_string (attrib));
      printc ("CALL UILIB_ARRAY_LINES_START()");
      printc ("FOR gc_arr_cnt=1 TO UILIB_arr_count()");
      if (v->var_data.variable_type == VARIABLE_TYPE_SIMPLE)
	{
	  printc ("   CALL UILIB_DISPLAY_ARRAY_LINE(gc_arr_cnt, %s[gc_arr_cnt])", local_get_expr_as_string(arrvar));
	}
      else
	{
	  printc ("   CALL UILIB_DISPLAY_ARRAY_LINE(gc_arr_cnt, %s[gc_arr_cnt].*)", local_get_expr_as_string(arrvar));
	}
      printc ("END FOR");
      printc ("CALL UILIB_ARRAY_LINES_END()");
      need_daylight(); //printc ("#");
      printc ("WHILE TRUE # DISPLAY ARRAY");
      tmp_ccnt++;
      need_daylight(); //printc ("#");
      printc ("CASE UILIB_DISPLAY_ARRAY_LOOP(UILIB_GET_CONTEXT(%s)) ", last_context[CONTEXT_INPUT]);
      need_daylight(); //printc ("#");
      tmp_ccnt++;
      printc ("WHEN -100 # ACCEPT (4)");
      if (A4GL_isyes (acl_getenv ("TRACE4GL")))
	{
	  printc ("CALL trace_4gl(\"ACCEPT PRESSED\")");
	}
      printc ("   EXIT WHILE");
      need_daylight(); //printc ("#");
      printc ("WHEN -101 # INTERRUPT");
      if (A4GL_isyes (acl_getenv ("TRACE4GL")))
	{
	  printc ("CALL trace_4gl(\"INTERRUPT PRESSED\")");
	}
      printc ("   LET int_flag=TRUE");
      printc ("   EXIT WHILE");
      need_daylight(); //printc ("#");
      tmp_ccnt--;

    }
  else
    {
	set_nonewlines();
      printc ("DISPLAY ARRAY ");
      real_print_expr (arrvar);
      printc (" TO ");
      print_ident (srec);
      printc (".*");
      if (attrib)
	{
	  if (strlen (get_attributes_as_string (attrib)))
	    {
	      printc (" ATTRIBUTES(");
	      print_attributes (attrib);
	      printc (")");
	    }
	}
	clr_nonewlines();
    }

  tmp_ccnt++;
}

/**
 * Prints the second part of C generated code to implement the INPUT ARRAY
 * 4gl statement.
 *
 * Called when the parser found the rest of DISPLAY ARRAY (<field_commands> END
 * INPUT or nothing).
 *
 */
static void
print_display_array_p2 (on_events * events)
{
  if (ui_as_calls ())
    {
      need_daylight(); //printc ("#");
      printc ("WHEN -1 # Initialisation");
      tmp_ccnt++;
      print_event_list (events, 0);
      printc ("CALL UILIB_DISPLAY_ARRAY_INITIALISED()");
      tmp_ccnt--;
      tmp_ccnt--;
      printc ("END CASE");
      tmp_ccnt--;
      printc ("END WHILE");
      need_daylight(); //printc ("#");
    }
  else
    {
      if (events)
	{
	  printc ("END DISPLAY");

	}
      tmp_ccnt--;
    }
  strcpy (last_context[CONTEXT_INPUT], "");
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

static void
print_convert (struct convert *conv_c)
{
  switch (conv_c->towhat)
    {
    case '@':
      printc ("TO EMAIL");
      break;
    case 'F':
      printc ("TO FILE");
      break;
    case 'P':
      printc ("TO PRINTER");
      break;
    case '|':
      printc ("TO PIPE");
      break;
    case 'f':
      printc ("VIA");
      break;
    default:
      A4GL_assertion (1, "Unhandled print_convert type");
    }
  if (conv_c->s1)
    {
      printc (" ");
      real_print_expr (conv_c->s1);
    }
  if (conv_c->conv_type)
    {
      printc (" AS ");
      real_print_expr (conv_c->conv_type);
    }
  if (conv_c->filter)
    {
      printc (" USING");
      real_print_expr (conv_c->filter);
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
      clr_nonewlines ();
      return 0;
    }

  for (a = 0; a < to_vars; a++)
    {
      enum e_scope scope;

      //scope = get_var_expr_scope (varlist->list.list_val[a]);
      //printc("{ SCOPE =%c REMOVEMODVARS=%s varname=%s bindscope=%c}", scope, acl_getenv ("REMOVEMODVARS"),varlist->bindings.bindings_val[a].varname , varlist->bindings.bindings_val[a].scope);
      scope = get_var_expr_scope (varlist->list.list_val[a]);
      if (tolower (scope) == 'm' && A4GL_isyes (acl_getenv ("REMOVEMODVARS")))
	{
	if (expr_list ==0) {
		  // Fools - They want to set a variable to null -
		  // and they're assigning it - thats very very naughty....
		  printh ("#REQUIRETEMP %s lv_tmp_%x %d\n", get_currfuncname (), get_var_expr_dtype (varlist->list.list_val[0]),
			  get_var_expr_dtype (varlist->list.list_val[0]));
		  printc ("INITIALIZE lv_tmp_%x TO NULL", get_var_expr_dtype (varlist->list.list_val[0]));
		  printc ("CALL ");
		  print_varbind (varlist->list.list_val[0], 'W', 0);
		  printc (" lv_tmp_%x)", get_var_expr_dtype (varlist->list.list_val[0]));
		  continue;
	} else {
	  if (expr_list->list.list_len == 1)
	    {
	      if (expr_list->list.list_val[0]->expr_type == ET_EXPR_NULL)
		{
		  // Fools - They want to set a variable to null -
		  // and they're assigning it - thats very very naughty....
		  printh ("#REQUIRETEMP %s lv_tmp_%x %d\n", get_currfuncname (), get_var_expr_dtype (varlist->list.list_val[0]),
			  get_var_expr_dtype (varlist->list.list_val[0]));
		  printc ("INITIALIZE lv_tmp_%x TO NULL", get_var_expr_dtype (varlist->list.list_val[0]));
		  printc ("CALL ");
		  print_varbind (varlist->list.list_val[0], 'W', 0);
		  printc (" lv_tmp_%x)", get_var_expr_dtype (varlist->list.list_val[0]));
		  continue;
		}
	    }
		}


	  set_nonewlines ();
	  printc ("CALL ");
	  print_varbind (varlist->list.list_val[a], 'W', a);
	  real_print_expr (expr_list->list.list_val[a]);
	  printc (")");
	  clr_nonewlines ();
	}
      else
	{
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
	  clr_nonewlines ();
	}
    }
  return 1;
}


static int
chk_for_inner_while (int n)
{

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


static int
chk_for_inner_input (int n)
{

#ifdef FIXME
  if (ui_as_calls ())
    {
      ccnt = A4GL_get_ccnt ();

      for (z = ccnt; z >= n; z--)
	{
	  s = command_type_for_stack_pos (z);
	  if (strcmp (s, "INPUT") == 0 || strcmp (s, "INPUTREQ") == 0 || strcmp (s, "MENU") == 0)
	    {
	      local_a4gl_yyerror ("Cant handle an inner INPUT or MENU");
	      return 1;
	    }
	}
    }
#endif
  return 0;
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
 *  * Print in the generated C output code an option change.
 *   *
 *    * For now its onlu used to change the menu line.
 *     *
 *      * @param n The parameter type:
 *       *   - M : Menu
 *        * @param s The parameter value
 *         *   - Now just the menu line
 *          */
static void
print_options (char n, char *s, struct expr_str *expr)
{
  int a;
  if (ui_as_calls ())
    {
      switch (n)
	{
	case 'W':
	  printc ("CALL UILIB_OPTIONS(\"INPUT WRAP\",1)");
	  break;
	case 'w':
	  printc ("CALL UILIB_OPTIONS(\"INPUT WRAP\",0)");
	  break;
	case 'm':
	  printc ("CALL UILIB_OPTIONS(\"MESSAGE LINE\",%s)", s);
	  break;
	case 'A':
	  printc ("CALL UILIB_OPTIONS(\"ACCEPT KEY\",\"%s\")", s);
	  break;
	case 'D':
	  printc ("CALL UILIB_OPTIONS(\"DELETE KEY\",\"%s\")", s);
	  break;
	case 'I':
	  printc ("CALL UILIB_OPTIONS(\"INSERT KEY\",\"%s\")", s);
	  break;
	case 'N':
	  printc ("CALL UILIB_OPTIONS(\"NEXT KEY\",\"%s\")", s);
	  break;
	case 'p':
	  printc ("CALL UILIB_OPTIONS(\"PREVIOUS KEY\",\"%s\")", s);
	  break;
	case 'H':
	  printc ("CALL UILIB_OPTIONS(\"HELP KEY\",\"%s\")", s);
	  break;
	case 'C':
	  printc ("CALL UILIB_OPTIONS(\"COMMENT LINE\",%s)", s);
	  break;
	case 'P':
	  printc ("CALL UILIB_OPTIONS(\"PROMPT LINE\",%s)", s);
	  break;

	case 'E':
	  printc ("CALL UILIB_OPTIONS(\"ERROR LINE\",%s)", s);
	  break;
	case 'S':
	  if (atoi (s))
	    {
	      printc ("OPTIONS SQL INTERRUPT ON");
	    }
	  else
	    {
	      printc ("OPTIONS SQL INTERRUPT OFF");
	    }
	  break;



	default:
	  printc ("CALL UILIB_OPTIONS(\"%c\",\"%s\")", n, s);
	}
    }
  else
    {
      switch (n)
	{
	case 'W':
	  printc ("OPTIONS INPUT WRAP");
	  break;
	case 'w':
	  printc ("OPTIONS INPUT NOWRAP");
	  break;
	case 'A':
	  printc ("OPTIONS ACCEPT KEY %s", s);
	  break;

	case 'I':
	  printc ("OPTIONS INSERT KEY %s", s);
	  break;

	case 'H':
	  printc ("OPTIONS HELP KEY %s", s);
	  break;

	case 'h':
	set_nonewlines();
	  printc ("OPTIONS HELP FILE ");
		real_print_expr(expr);
	clr_nonewlines();
	  break;

	case 'L':
	  printc ("OPTIONS LANGUAGE FILE");
		real_print_expr(expr);
	  break;


	case 'D':
	  printc ("OPTIONS DELETE KEY %s", s);
	  break;

	case 'f':
	  if (atoi (s))
	    {
	      printc ("OPTIONS FIELD ORDER CONSTRAINED");
	    }
	  else
	    {
	      printc ("OPTIONS FIELD ORDER UNCONSTRAINED");
	    }
	  break;
	case 'S':
	  if (atoi (s))
	    {
	      printc ("OPTIONS SQL INTERRUPT ON");
	    }
	  else
	    {
	      printc ("OPTIONS SQL INTERRUPT OFF");
	    }
	  break;

	case 'm':
	  if (!is_plain_line (expr))
	    {
	      A4GL_assertion (1, "Can only print plain lines atm");
	    }
	  else
	    {
	      a = get_plain_line (expr);
	    }

	  if (a < 0)
	    {
	      if (a == -1)
		{
		  printc ("OPTIONS MESSAGE LINE LAST");
		}
	      else
		{
		  printc ("OPTIONS MESSAGE LINE LAST%d", a + 1);
		}
	    }
	  else
	    {
	      printc ("OPTIONS MESSAGE LINE %d", a);
	    }
	  break;


	case 'M':
	  if (!is_plain_line (expr))
	    {
	      A4GL_assertion (1, "Can only print plain lines atm");
	    }
	  else
	    {
	      a = get_plain_line (expr);
	    }

	  if (a < 0)
	    {
	      if (a == -1)
		{
		  printc ("OPTIONS MENU LINE LAST");
		}
	      else
		{
		  printc ("OPTIONS MENU LINE LAST%d", a + 1);
		}
	    }
	  else
	    {
	      if (a <= 1)
		{
		  printc ("OPTIONS MENU LINE FIRST");
		}
	      else
		{
		  printc ("OPTIONS MENU LINE %d", a);
		}
	    }
	  break;

	case 'E':
	  if (!is_plain_line (expr))
	    {
	      A4GL_assertion (1, "Can only print plain lines atm");
	    }
	  else
	    {
	      a = get_plain_line (expr);
	    }

	  if (a < 0)
	    {
	      if (a == -1)
		{
		  printc ("OPTIONS ERROR LINE LAST");
		}
	      else
		{
		  printc ("OPTIONS ERROR LINE LAST%d", a + 1);
		}
	    }
	  else
	    {
	      if (a == 1)
		{
		  printc ("OPTIONS ERROR LINE FIRST");
		}
	      else
		{
		  printc ("OPTIONS ERROR LINE %d", a);
		}
	    }
	  break;

	case 'F':
	  if (!is_plain_line (expr))
	    {
	      A4GL_assertion (1, "Can only print plain lines atm");
	    }
	  else
	    {
	      a = get_plain_line (expr);
	    }

	  if (a < 0)
	    {
	      if (a == -1)
		{
		  printc ("OPTIONS FORM LINE LAST");
		}
	      else
		{
		  printc ("OPTIONS FORM LINE LAST%d", a + 1);
		}
	    }
	  else
	    {
	      if (a == 1)
		{
		  printc ("OPTIONS FORM LINE FIRST");
		}
	      else
		{
		  printc ("OPTIONS FORM LINE %d", a);
		}
	    }
	  break;


	case 'P':
	  if (!is_plain_line (expr))
	    {
	      A4GL_assertion (1, "Can only print plain lines atm");
	    }
	  else
	    {
	      a = get_plain_line (expr);
	    }

	  if (a < 0)
	    {
	      if (a == -1)
		{
		  printc ("OPTIONS PROMPT LINE LAST");
		}
	      else
		{
		  printc ("OPTIONS PROMPT LINE LAST%d", a + 1);
		}
	    }
	  else
	    {
	      printc ("OPTIONS PROMPT LINE %d", a);
	    }
	  break;


	case 'C':
	  if (!is_plain_line (expr))
	    {
	      A4GL_assertion (1, "Can only print plain lines atm");
	    }
	  else
	    {
	      a = get_plain_line (expr);
	    }

	  if (a < 0)
	    {
	      if (a == -1)
		{
		  printc ("OPTIONS COMMENT LINE LAST");
		}
	      else
		{
		  printc ("OPTIONS COMMENT LINE LAST%d", a + 1);
		}
	    }
	  else
	    {
	      printc ("OPTIONS COMMENT LINE %d", a);
	    }
	  break;

	case 'N':
		printc("OPTIONS NEXT KEY %s",s);
		break;

	case 'p':
		printc("OPTIONS PREVIOUS KEY %s",s);
		break;


	default:
	  printc ("OPTIONS %c %d", n, a);
	}
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

  if (strcmp (cmd_type, "INPUT") == 0)
    {
      if (ui_as_calls ())
	{
	  chk_for_inner_while (n);
	  printc ("CONTINUE WHILE");
	}
      else
	{
	  printc ("CONTINUE INPUT");
	}
      return;
    }

  if (strcmp (cmd_type, "INPUTREQ") == 0 || strcmp (cmd_type, "CONSTRUCT") == 0)
    {
      if (ui_as_calls ())
	{
	  chk_for_inner_while (n);
	  printc ("CONTINUE WHILE");
	}
      else
	{
	  printc ("CONTINUE CONSTRUCT");
	}
      return;
    }

  if (strcmp (cmd_type, "MENU") == 0)
    {
      if (ui_as_calls ())
	{
	  chk_for_inner_while (n);
	  printc ("CONTINUE WHILE");
	}
      else
	{
	  printc ("CONTINUE MENU");
	}
      return;
    }

  if (strcmp (cmd_type, "WHILE") == 0)
    {
      chk_for_inner_input (n);
    }
  printc ("CONTINUE %s", cmd_type);
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
  if (type == 'M')
    {
      //printc ("cmd_no_%d= -3;goto MENU_START_%d;\n", n, n);
    }
  if (type == 'P')
    {
      if (ui_as_calls ())
	{
	  printc ("EXIT WHILE");
	}
      else
	{
	  printc ("EXIT PROMPT");
	}
      //printc ("SET(\"s_prompt\",_sio_%d,\"mode\",1);\n",get_sio_ids("PROMPT"));
    }

  if (strcmp (cmdtype, "INPUT") == 0)
    {
      if (ui_as_calls ())
	{
	  chk_for_inner_while (n);
	  printc ("EXIT WHILE # exit input");
	}
      else
	{
	  printc ("EXIT INPUT");
	}
      return;
    }
  if (strcmp (cmdtype, "DISPLAY") == 0)
    {
      if (ui_as_calls ())
	{
	  chk_for_inner_while (n);
	  printc ("EXIT WHILE # exit display");
	  return;
	}
      else
	{
	  printc ("EXIT DISPLAY");
	}
    }

  if (strcmp (cmdtype, "INPUTREQ") == 0)
    {
      if (ui_as_calls ())
	{
	  chk_for_inner_while (n);
	  printc ("EXIT WHILE # exit input");
	  return;
	}
      else
	{
	  printc ("EXIT CONSTRUCT");
	}
    }
  if (strcmp (cmdtype, "MENU") == 0)
    {
      if (ui_as_calls ())
	{
	  chk_for_inner_while (n);
	  printc ("EXIT WHILE # exit menu");
	  return;
	}
      else
	{
	  printc ("EXIT MENU");
	}
    }

  if (strcmp (cmdtype, "WHILE") == 0)
    {
      chk_for_inner_input (n);
    }

  if (type == 0)
    {
      printc ("EXIT %s", cmdtype);
    }
}



static int
dump_cmd (struct command *r, struct command *parent)
{
  int a;
static int last_command_type=-1;
static command *last_parent=(void *)-1;

  A4GL_assertion (r->module == 0, "No module");
  //printf ("Dumping command type : %d (%s %d)\n", r->cmd_data.type, r->module, r->lineno);
  A4GL_debug ("Dumping command type : %d (%s %d)\n", r->cmd_data.type, r->module, r->lineno);

if (last_parent!=parent) {
		last_command_type=r->cmd_data.type;
		last_parent=parent;
		//need_daylight();
} else {
  if (last_command_type!= r->cmd_data.type) {
		need_daylight();
		last_command_type=r->cmd_data.type;
  }
	}
 

  curr_yylineno = r->lineno;
  A4GL_set_sql_lineno (r->lineno);

  dump_comments (r->lineno);
  if (A4GL_isyes (acl_getenv ("TRACE4GL")))
    {
      if (r->cmd_data.type == E_CMD_IF_CMD || r->cmd_data.type == E_CMD_WHILE_CMD || r->cmd_data.type == E_CMD_LET_CMD);
      else
	{
	  printc ("CALL trace_4gl(\"%s Line %d\")", r->module, r->lineno);
	}
    }
  switch (r->cmd_data.type)
    {
    case E_CMD_STOP_RPC_CMD:
      printc ("STOP ALL EXTERNAL");
      break;
    case E_CMD_PAUSE_SCREEN_ON_CMD:
      printc ("SET PAUSE MODE ON");
      break;
    case E_CMD_PAUSE_SCREEN_OFF_CMD:
      printc ("SET PAUSE MODE OFF");
      break;
    case E_CMD_SKIP_TO_TOP_CMD:
      printc ("SKIP TO TOP OF PAGE");
      break;


    case E_CMD_LINT_IGNORE_CMD:
	{
	int b;
	set_nonewlines ();
	printc("LINT IGNORE ");
	for (b=0;b<r->cmd_data.command_data_u.lint_ignore_cmd.values->str_list_entry.str_list_entry_len;b++) {
		if (b) printc(",");

		printc("%s",r->cmd_data.command_data_u.lint_ignore_cmd.values->str_list_entry.str_list_entry_val[b]);
	}
	clr_nonewlines ();
	}
	break;

    case E_CMD_LINT_EXPECT_CMD:
	{
	int b;
	set_nonewlines ();
	printc("LINT EXPECT ");
	for (b=0;b<r->cmd_data.command_data_u.lint_expect_cmd.values->str_list_entry.str_list_entry_len;b++) {
		if (b) printc(",");

		printc("%s",r->cmd_data.command_data_u.lint_expect_cmd.values->str_list_entry.str_list_entry_val[b]);
	}
	clr_nonewlines ();
	}
	break;



    case E_CMD_CALL_CMD:
      {
	struct expr_str *ptr;
	int b;
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
	    if (A4GL_isyes (acl_getenv ("TRACE4GL")))
	      {
		printc ("CALL trace_4gl(\"CALL %s\")",
			r->cmd_data.command_data_u.call_cmd.fcall->expr_str_u.expr_function_call->fname);
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

	    if (strcmp (ptr->expr_str_u.expr_function_call->fname, "fgl_lastkey") == 0 && ui_as_calls ())
	      {
		printc ("fgl_keyval(UILIB_lastkey())");
	      }
	    else
	      {
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

	      }
	    break;


	
	  case ET_EXPR_GET_FLDBUF:
	    printc ("get_fldbuf(");
	    real_print_field_list_with_separator (ptr->expr_str_u.expr_get_fldbuf->field_list, ",");
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

		    if (tolower (scope) == 'm' && A4GL_isyes (acl_getenv ("REMOVEMODVARS")))
		      {
			printh ("#REQUIRETEMP %s lv_tmp_%x_%d %d\n", get_currfuncname (), get_var_expr_dtype (l->list.list_val[a]),
				a, get_var_expr_dtype (l->list.list_val[a]));
			printc ("lv_tmp_%x_%d", get_var_expr_dtype (l->list.list_val[a]), a);
			used_tmp++;
		      }
		    else
		      {
			print_varbind (l->list.list_val[a], 'r', a);
		      }
		  }
		clr_nonewlines ();
		if (used_tmp)
		  {
		    for (a = 0; a < l->list.list_len; a++)
		      {
			scope = get_var_expr_scope (l->list.list_val[a]);
			if (tolower (scope) == 'm' && A4GL_isyes (acl_getenv ("REMOVEMODVARS")))
			  {
			    set_nonewlines ();
			    printc ("CALL ");
			    print_varbind (l->list.list_val[a], 'W', a);
			    printc ("lv_tmp_%x_%d)", get_var_expr_dtype (l->list.list_val[a]), a);
			    clr_nonewlines ();
			  }
		      }
		  }
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
      if (r->cmd_data.command_data_u.cancel_cmd.c == CT_INSERT)
	{
	  if (ui_as_calls ())
	    {
	      printc ("CALL UILIB_CANCEL_INSERT()\n");
	    }
	  else
	    {
	      printc ("CANCEL INSERT");
	    }
	}
      if (r->cmd_data.command_data_u.cancel_cmd.c == CT_DELETE)
	{
	  if (ui_as_calls ())
	    {
	      printc ("CALL UILIB_CANCEL_DELETE()\n");
	    }
	  else
	    {
	      printc ("CANCEL DELETE");
	    }
	}
      break;

    case E_CMD_CASE_CMD:
      need_daylight(); //printc ("#");
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


      /* A4GL_warn("Coding Standards: CASE has no OTHERWISE"); */


      tmp_ccnt--;
      need_daylight ();
      printc ("END CASE");
      need_daylight ();
      need_daylight(); //printc ("#");

      break;

    case E_CMD_CLOSE_CMD:
      switch (r->cmd_data.command_data_u.close_cmd.cl_type)
	{
	case E_CT_WINDOW:
	  if (ui_as_calls ())
	    {
	      printc ("CALL UILIB_CLOSE_WINDOW(");
	      print_quoted_ident (r->cmd_data.command_data_u.close_cmd.ident);
	      printc (")\n");
	    }
	  else
	    {

	      set_nonewlines ();
	      printc ("CLOSE WINDOW ");
	      print_ident (r->cmd_data.command_data_u.close_cmd.ident);
	      clr_nonewlines ();
	    }
	  break;
	case E_CT_FORM:
	  if (ui_as_calls ())
	    {
	      printc ("CALL UILIB_CLOSE_FORM(");
	      print_quoted_ident (r->cmd_data.command_data_u.close_cmd.ident);
	      printc (")");
	    }
	  else
	    {
	      set_nonewlines ();
	      printc ("CLOSE FORM ");
	      print_ident (r->cmd_data.command_data_u.close_cmd.ident);
	      clr_nonewlines ();
	    }
	  break;
	case E_CT_STATUSBOX:
	  set_nonewlines ();
	  printc ("CLOSE STATUSBOX ");
	  print_ident (r->cmd_data.command_data_u.close_cmd.ident);
	  clr_nonewlines ();
	  break;
	}
      break;



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
	  clr_nonewlines ();
	  break;
	}
      break;

    case E_CMD_CODE_CMD:
      if (outfile)
	FPRINTF (outfile, "\ncode\n");
      FPRINTF (outfile, "%s", r->cmd_data.command_data_u.code_cmd.contents);
      //printc ("%s", r->cmd_data.command_data_u.code_cmd.contents);
      if (outfile)
	FPRINTF (outfile, "\nendcode\n\n");
      break;

    case E_CMD_DEFER_CMD:

      if (r->cmd_data.command_data_u.defer_cmd.what == EDEFER_QUIT)
	{
	  printc ("DEFER QUIT");
	}
      if (r->cmd_data.command_data_u.defer_cmd.what == EDEFER_INTERRUPT)
	{
	  printc ("DEFER INTERRUPT");
	}
      break;



    case E_CMD_DISPLAY_CMD:	/* UI */

      switch (r->cmd_data.command_data_u.display_cmd.where->dttype)
	{
	case DT_DISPLAY_TYPE_LINE:
	  if (ui_as_calls ())
	    {
	      set_nonewlines ();
	      printc ("CALL UILIB_DISPLAY(");
	      real_print_expr_list_pipes (r->cmd_data.command_data_u.display_cmd.exprs);
	      printc (")");
	      clr_nonewlines ();
	    }
	  else
	    {
	      set_nonewlines ();
	      printc ("DISPLAY ");
	      real_print_expr_list_with_separator (r->cmd_data.command_data_u.display_cmd.exprs, ",");
	      clr_nonewlines ();
	    }
	  break;


	case DT_DISPLAY_TYPE_AT:
	  if (ui_as_calls ())
	    {
	      set_nonewlines ();
	      printc ("CALL UILIB_DISPLAYAT( ");
	      real_print_expr_list_pipes (r->cmd_data.command_data_u.display_cmd.exprs);

	      printc (",%s,", attributes_as_string (r->cmd_data.command_data_u.display_cmd.attributes));

	      real_print_expr (r->cmd_data.command_data_u.display_cmd.where->dt_display_u.x_y.y);
	      printc (",");
	      real_print_expr (r->cmd_data.command_data_u.display_cmd.where->dt_display_u.x_y.x);
	      printc (")");
	      clr_nonewlines ();
	    }
	  else
	    {
	      set_nonewlines ();
	      printc ("DISPLAY ");
	      real_print_expr_list_with_separator (r->cmd_data.command_data_u.display_cmd.exprs, ",");
	      printc (" AT ");
	      real_print_expr (r->cmd_data.command_data_u.display_cmd.where->dt_display_u.x_y.y);
	      printc (",");
	      real_print_expr (r->cmd_data.command_data_u.display_cmd.where->dt_display_u.x_y.x);
	      if (r->cmd_data.command_data_u.display_cmd.attributes)
		{
		  printc (" ATTRIBUTES(");
		  print_attributes (r->cmd_data.command_data_u.display_cmd.attributes);
		  printc (")");
		}
	      clr_nonewlines ();
	    }
	  break;

	case DT_DISPLAY_TYPE_FIELD_LIST:
	  if (ui_as_calls ())
	    {
	      set_nonewlines ();
	      printc_safe_to_split_at_comma ("CALL UILIB_SET_FIELD_LIST(");
	      real_print_field_list_with_separator (r->cmd_data.command_data_u.display_cmd.where->dt_display_u.field_list, ",");
	      printc (")");
	      clr_nonewlines ();

	      set_nonewlines ();
	      printc ("CALL UILIB_DISPLAY_VALUES( ");
	      real_print_expr_list_with_separator (r->cmd_data.command_data_u.display_cmd.exprs, ",");

	      printc (",%s)", attributes_as_string (r->cmd_data.command_data_u.display_cmd.attributes));
	      clr_nonewlines ();
	    }
	  else
	    {

	      set_nonewlines ();
	      if (r->cmd_data.command_data_u.display_cmd.by_name)
		{
		  printc ("DISPLAY BY NAME ");
		  real_print_expr_list_with_separator (r->cmd_data.command_data_u.display_cmd.exprs, ",");
		  //printc (" TO ");
		  //real_print_field_list_with_separator (r->cmd_data.command_data_u.display_cmd.where->dt_display_u.field_list, ",");
		}
	      else
		{
		  printc ("DISPLAY ");
		  real_print_expr_list_with_separator (r->cmd_data.command_data_u.display_cmd.exprs, ",");
		  printc (" TO ");
		  real_print_field_list_with_separator (r->cmd_data.command_data_u.display_cmd.where->dt_display_u.field_list, ",");
		}

	      if (r->cmd_data.command_data_u.display_cmd.attributes)
		{
		  printc (" ATTRIBUTES(");
		  print_attributes (r->cmd_data.command_data_u.display_cmd.attributes);
		  printc (")");
		}
	      clr_nonewlines ();
	    }
	  break;



	case DT_DISPLAY_TYPE_MENUITEM:
	  A4GL_assertion (1, "Not implemented yet");
	  break;
	case DT_DISPLAY_TYPE_MAIN_CAPTION:
	  A4GL_assertion (1, "Not implemented yet");
	  break;
	case DT_DISPLAY_TYPE_FORM_FIELD:
	  A4GL_assertion (1, "Not implemented yet");
	  break;
	case DT_DISPLAY_TYPE_FORM_CAPTION:
	  A4GL_assertion (1, "Not implemented yet");
	  break;
	case DT_DISPLAY_TYPE_STATUSBOX:
	  A4GL_assertion (1, "Not implemented yet");
	  break;

	}

      break;



    case E_CMD_DISPLAY_FORM_CMD:	/* UI */

      if (ui_as_calls ())
	{
	  printc ("CALL UILIB_DISPLAY_FORM(");
	  print_quoted_ident (r->cmd_data.command_data_u.display_form_cmd.formname);
	  printc (",%s)", attributes_as_string (r->cmd_data.command_data_u.display_form_cmd.attributes));
	}
      else
	{


	  set_nonewlines ();
	  printc ("DISPLAY FORM ");
	  print_ident (r->cmd_data.command_data_u.display_form_cmd.formname);

	  if (r->cmd_data.command_data_u.display_form_cmd.attributes)
	    {
	      printc (" ATTRIBUTES(");
	      print_attributes (r->cmd_data.command_data_u.display_form_cmd.attributes);
	      printc (")");
	    }
	  clr_nonewlines ();
	}
      break;



    case E_CMD_ERROR_CMD:
      set_nonewlines ();
      if (ui_as_calls ())
	{
	  printc ("CALL UILIB_ERROR(");
	  real_print_expr_list_with_separator (r->cmd_data.command_data_u.error_cmd.expr_list, "||");
	  printc (")");

	}
      else
	{
	  printc ("ERROR ");
	  real_print_expr_list_with_separator (r->cmd_data.command_data_u.error_cmd.expr_list, ",");
	  if (r->cmd_data.command_data_u.error_cmd.attributes)
	    {
	      printc (" ATTRIBUTES(");
	      print_attributes (r->cmd_data.command_data_u.error_cmd.attributes);
	      printc (")");
	    }
	}
      clr_nonewlines ();
      break;

    case E_CMD_EXT_CMD:
      switch (r->cmd_data.command_data_u.ext_cmd.what)
	{
	case EBC_WHILE:
	  printc ("EXIT WHILE");
	  break;
	case EBC_FOR:
	  printc ("EXIT FOR");
	  break;
	case EBC_INPUT:
	  print_exit_loop ('-', r->cmd_data.command_data_u.ext_cmd.block_id, "INPUT");
	  //printc ("EXIT INPUT");
	  break;
	case EBC_FOREACH:
	  printc ("EXIT FOREACH");
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
	  printc ("EXIT CASE");
	  break;
	}
      break;

    case E_CMD_CONTINUE_CMD:
      switch (r->cmd_data.command_data_u.ext_cmd.what)
	{
	case EBC_WHILE:
	  printc ("CONTINUE WHILE");
	  break;
	case EBC_FOR:
	  printc ("CONTINUE FOR");
	  break;
	case EBC_INPUT:
	  print_continue_loop (r->cmd_data.command_data_u.ext_cmd.block_id, "INPUT");
	  //printc ("CONTINUE INPUT");
	  break;
	case EBC_FOREACH:
	  printc ("CONTINUE FOREACH");
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
	  printc ("CONTINUE CASE");
	  break;
	}
      break;


    case E_CMD_EXIT_PROG_CMD:
      if (1)
	{
	  if (current_entry == 0)
	    {
	      A4GL_warn ("Coding Standards: EXIT PROGRAM must not be used directly - use CALL exit_prog instead");
	    }
	  else
	    {
	      if (strcmp (get_currfuncname (), "exit_prog") != 0)
		{
		  A4GL_warn ("Coding Standards: EXIT PROGRAM must not be used directly - use CALL exit_prog instead");
		}
	    }

	  if (r->cmd_data.command_data_u.exit_prog_cmd.exit_val)
	    {

	      if (ui_as_calls ())
		printc ("CALL UILIB_PROGRAM_EXIT(0)");
	      set_nonewlines ();
	      printc ("EXIT PROGRAM ");
	      real_print_expr (r->cmd_data.command_data_u.exit_prog_cmd.exit_val);
	      clr_nonewlines ();
	    }
	  else
	    {
	      if (ui_as_calls ())
		printc ("CALL UILIB_PROGRAM_EXIT(0)");
	      printc ("EXIT PROGRAM");
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
	      if (current_entry == 0)
		{
		  A4GL_warn ("Coding Standards: EXIT PROGRAM must only be in main");
		}
	      else
		{
		  if (strcmp (get_currfuncname (), "MAIN") != 0)
		    {
		      A4GL_warn ("Coding Standards: EXIT PROGRAM must only be in main");
		    }
		}
	    }

	  if (r->cmd_data.command_data_u.exit_prog_cmd.exit_val)
	    {
	      set_nonewlines ();
	      printc ("EXIT PROGRAM ");
	      real_print_expr (r->cmd_data.command_data_u.exit_prog_cmd.exit_val);
	      clr_nonewlines ();
	    }
	  else
	    {
	      printc ("EXIT PROGRAM");
	    }
	}
      break;


    case E_CMD_FOR_CMD:
      {
	int need_step = 1;
	int for_var_is_module = 0;
	enum e_scope scope;
	need_daylight ();
	//printc ("#");
	set_nonewlines ();
	scope = get_var_expr_scope (r->cmd_data.command_data_u.for_cmd.var);
	//printf("for scope=%c\n", r->cmd_data.command_data_u.for_cmd.var->scope);
	if (tolower (scope) == 'm' && A4GL_isyes (acl_getenv ("REMOVEMODVARS")))
	  {
	    printh ("#REQUIRETEMP %s lv_tmp_%x %d\n", get_currfuncname (),
		    get_var_expr_dtype (r->cmd_data.command_data_u.for_cmd.var),
		    get_var_expr_dtype (r->cmd_data.command_data_u.for_cmd.var));
	    printc ("FOR lv_tmp_%x=", get_var_expr_dtype (r->cmd_data.command_data_u.for_cmd.var));
	    for_var_is_module++;
	  }
	else
	  {
	    printc ("FOR ");
	    print_varbind (r->cmd_data.command_data_u.for_cmd.var, 'w', 0);
	    printc ("=");
	  }
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
	tmp_ccnt--;
	printc ("END FOR");
	//printc ("#");
	need_daylight ();
      }
      break;


    case E_CMD_FOREACH_CMD:
      //printc ("#");
      need_daylight ();
      if (r->cmd_data.command_data_u.foreach_cmd.inputvals)
	{
	  if (r->cmd_data.command_data_u.foreach_cmd.inputvals->list.list_len)
	    {

	      for (a = 0; a < r->cmd_data.command_data_u.foreach_cmd.inputvals->list.list_len; a++)
		{
		  if (tolower
		      (get_var_expr_scope (r->cmd_data.command_data_u.foreach_cmd.inputvals->list.list_val[a])) == 'm'
		      && A4GL_isyes (acl_getenv ("REMOVEMODVARS")))
		    {
		      printh ("#REQUIRETEMP %s lv_tmpu_%x_%d %d\n", get_currfuncname (),
			      get_var_expr_dtype (r->cmd_data.command_data_u.foreach_cmd.inputvals->list.list_val[a]), a,
			      get_var_expr_dtype (r->cmd_data.command_data_u.foreach_cmd.inputvals->list.list_val[a]));
		      printc ("LET lv_tmpu_%x_%d=",
			      get_var_expr_dtype (r->cmd_data.command_data_u.foreach_cmd.inputvals->list.list_val[a]), a);

		      print_varbind (r->cmd_data.command_data_u.foreach_cmd.inputvals->list.list_val[a], 'R', a);
		    }
		}
	    }
	}


      need_daylight(); //printc ("#");
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
		  if (tolower
		      (get_var_expr_scope (r->cmd_data.command_data_u.foreach_cmd.inputvals->list.list_val[a])) == 'm'
		      && A4GL_isyes (acl_getenv ("REMOVEMODVARS")))
		    {
		      printc ("lv_tmpu_%x_%d",
			      get_var_expr_dtype (r->cmd_data.command_data_u.foreach_cmd.inputvals->list.list_val[a]), a);
		    }
		  else
		    {
		      print_varbind (r->cmd_data.command_data_u.foreach_cmd.inputvals->list.list_val[a], 'r', a);
		    }
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

		  if (tolower (get_var_expr_scope (r->cmd_data.command_data_u.foreach_cmd.outputvals->
						   list.list_val[a])) == 'm' && A4GL_isyes (acl_getenv ("REMOVEMODVARS")))
		    {
		      printh ("#REQUIRETEMP %s lv_tmpi_%x_%d %d\n", get_currfuncname (),
			      get_var_expr_dtype (r->cmd_data.command_data_u.foreach_cmd.outputvals->list.list_val[a]), a,
			      get_var_expr_dtype (r->cmd_data.command_data_u.foreach_cmd.outputvals->list.list_val[a]));
		      printc ("lv_tmpi_%x_%d",
			      get_var_expr_dtype (r->cmd_data.command_data_u.foreach_cmd.outputvals->list.list_val[a]), a);
		      module_var_used++;
		    }
		  else
		    {
		      print_varbind (r->cmd_data.command_data_u.foreach_cmd.outputvals->list.list_val[a], 'w', a);
		    }
		}
	      clr_nonewlines ();

	      if (module_var_used)
		{
		  need_daylight(); //printc ("#");
		  tmp_ccnt++;
		  for (a = 0; a < r->cmd_data.command_data_u.foreach_cmd.outputvals->list.list_len; a++)
		    {
		      if (tolower
			  (get_var_expr_scope (r->cmd_data.command_data_u.foreach_cmd.outputvals->
					       list.list_val[a])) == 'm' && A4GL_isyes (acl_getenv ("REMOVEMODVARS")))
			{
			  printc ("CALL ");
			  print_varbind (r->cmd_data.command_data_u.foreach_cmd.outputvals->list.list_val[a], 'W', a);
			  printc (" lv_tmpi_%x_%d)",
				  get_var_expr_dtype (r->cmd_data.command_data_u.foreach_cmd.outputvals->list.list_val[a]), a);

			}
		    }

		  tmp_ccnt--;
		}


	}
      need_daylight(); //printc ("#");
      tmp_ccnt++;
      dump_cmds (r->cmd_data.command_data_u.foreach_cmd.foreach_commands, r);
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
      clr_nonewlines ();
      break;

    case E_CMD_GOTO_CMD:
      printc ("GOTO :%s", r->cmd_data.command_data_u.goto_cmd.label);
      break;

    case E_CMD_IF_CMD:
	need_daylight();
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
	  if (A4GL_isyes (acl_getenv ("TRACE4GL")))
	    {
	      printc ("CALL trace_4gl(\"IF statement is TRUE @ %s %d\")", r->module, r->lineno);
	    }
	  dump_cmds (r->cmd_data.command_data_u.if_cmd.truths.conditions.conditions_val[a].whentrue, r);
	  tmp_ccnt--;
	}

      if (r->cmd_data.command_data_u.if_cmd.whenfalse)
	{
	  dump_comments (r->cmd_data.command_data_u.if_cmd.else_lineno);
	  printc ("ELSE");
	  tmp_ccnt++;

	  if (A4GL_isyes (acl_getenv ("TRACE4GL")))
	    {
	      printc ("CALL trace_4gl(\"IF statement is FALSE %s %d (ELSE @ %d)\")", r->module, r->lineno,
		      r->cmd_data.command_data_u.if_cmd.lineno);
	    }

	  dump_cmds (r->cmd_data.command_data_u.if_cmd.whenfalse, r);
	  tmp_ccnt--;
	}
      dump_comments (r->cmd_data.command_data_u.if_cmd.lineno);
      printc ("END IF");
	need_daylight();

      break;

    case E_CMD_LABEL_CMD:
      need_daylight ();
      printc ("LABEL %s:", r->cmd_data.command_data_u.label_cmd.label);
      break;

    case E_CMD_LET_CMD:

      print_let_manyvars_g (r->cmd_data.command_data_u.let_cmd.vals, r->cmd_data.command_data_u.let_cmd.vars);
      //printc("CALL trace_4gl(\"Done let %s Line %d\" )", r->module, r->lineno);
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

      if (A4GL_isyes (acl_getenv ("TRACE4GL")))
	{
	  printc ("CALL trace_4gl(\"RETURN from function\")");
	}

      if (r->cmd_data.command_data_u.return_cmd.retvals && r->cmd_data.command_data_u.return_cmd.retvals->list.list_len)
	{
	  set_nonewlines ();
	  printc ("RETURN ");
	  real_print_expr_list_with_separator (r->cmd_data.command_data_u.return_cmd.retvals, ",");
	  clr_nonewlines ();
	}
      else
	{
	  switch (current_entry->met_type)
	    {
	    case E_MET_REPORT_DEFINITION:
	      printc ("EXIT REPORT");
	    default:
	      printc ("RETURN");
	    }
	}
      break;


    case E_CMD_MENU_CMD:
      if (ui_as_calls ())
	{
	  char last_real_context[2000] = "";
	  if (strlen (last_context[CONTEXT_MENU]))
	    {
	      // This is a fudge..
	      // we're already in a menu - so we need to pretend we're not..
	      strcpy (last_real_context, last_context[CONTEXT_MENU]);
	      strcpy (last_context[CONTEXT_MENU], "");
	    }
	  chk_context (CONTEXT_MENU);
	  sprintf (last_context[CONTEXT_MENU], "\"%s\",%d", ofilename, curr_yylineno);
	  set_nonewlines ();
	  printc ("CALL UILIB_MENU_START(%s,", last_context[CONTEXT_MENU]);
	  real_print_variable_or_literal (r->cmd_data.command_data_u.menu_cmd.menu_title, "\"\"");
	  printc (")");
	  clr_nonewlines ();
	  printc ("WHILE TRUE # MENU ");
	  tmp_ccnt++;
	  printc ("CASE UILIB_MENU_LOOP(UILIB_GET_CONTEXT(%s))", last_context[CONTEXT_MENU]);
	  tmp_ccnt++;
	  printc ("WHEN -1 # INITIALISATION");
	  tmp_ccnt++;

	  print_event_list (r->cmd_data.command_data_u.menu_cmd.events, 1);

	  printc ("CALL UILIB_MENU_INITIALISED(UILIB_GET_CONTEXT(%s))", last_context[CONTEXT_MENU]);
	  tmp_ccnt--;
	  tmp_ccnt--;
	  print_events (r->cmd_data.command_data_u.menu_cmd.events, r);
	  printc ("END CASE");
	  tmp_ccnt--;
	  printc ("END WHILE");
	  printc ("CALL UILIB_FREE_MENU(UILIB_GET_CONTEXT(%s))", last_context[CONTEXT_MENU]);
	  if (strlen (last_real_context))
	    {
	      strcpy (last_context[CONTEXT_MENU], last_real_context);
	    }
	  else
	    {
	      strcpy (last_context[CONTEXT_MENU], "");
	    }


	}
      else
	{
	  need_daylight ();
	  set_nonewlines ();


	  printc ("MENU ");
	  real_print_variable_or_literal (r->cmd_data.command_data_u.menu_cmd.menu_title, "\"\"");
	  if (r->cmd_data.command_data_u.menu_cmd.menu_attrib)
	    {
	      printc (" ATTRIBUTES(");
	      print_attributes (r->cmd_data.command_data_u.menu_cmd.menu_attrib);
	      printc (")");
	    }
	  clr_nonewlines ();
	  tmp_ccnt++;
	  print_events (r->cmd_data.command_data_u.menu_cmd.events, r);
	  tmp_ccnt--;
	  //printc ("#");
	  need_daylight ();
	  printc ("END MENU");
	  strcpy (last_context[CONTEXT_MENU], "");
	  need_daylight ();
	}

      break;




    case E_CMD_NEXT_OPTION_CMD:
      if (ui_as_calls ())
	{
	  expr_str *s;
	  s = r->cmd_data.command_data_u.next_option_cmd.menuoption;
	  printc ("CALL UILIB_NEXT_OPTION (UILIB_GET_CONTEXT(%s),", last_context[CONTEXT_MENU]);
	  real_print_expr (s);
	  printc (")");
	}
      else
	{
	  set_nonewlines ();
	  printc ("NEXT OPTION ");
	  real_print_expr (r->cmd_data.command_data_u.next_option_cmd.menuoption);
	  clr_nonewlines ();
	}
      break;

    case E_CMD_SHOW_OPTION_CMD:
      {
	expr_str_list *s;

	if (ui_as_calls ())
	  {
	    s = r->cmd_data.command_data_u.show_option_cmd.menuoptions;

	    for (a = 0; a < s->list.list_len; a++)
	      {
		printc ("CALL UILIB_SHOW_OPTION (UILIB_GET_CONTEXT(%s),", last_context[CONTEXT_MENU]);
		real_print_expr (s->list.list_val[a]);
		printc (")");
	      }
	  }
	else
	  {
	    set_nonewlines ();
	    s = r->cmd_data.command_data_u.show_option_cmd.menuoptions;
	    printc ("SHOW OPTION ");
		print_menu_option_list(s);
		/*
	    for (a = 0; a < s->list.list_len; a++)
	      {
		if (a)
		  printc (",");
		real_print_expr (s->list.list_val[a]);

	      }
		*/
	    clr_nonewlines ();
	  }
      }
      break;

    case E_CMD_HIDE_OPTION_CMD:
      {
	expr_str_list *s;
	if (ui_as_calls ())
	  {
	    s = r->cmd_data.command_data_u.hide_option_cmd.menuoptions;

	    for (a = 0; a < s->list.list_len; a++)
	      {
		printc ("CALL UILIB_HIDE_OPTION (UILIB_GET_CONTEXT(%s),", last_context[CONTEXT_MENU]);
		real_print_expr (s->list.list_val[a]);
		printc (")");
	      }
	  }
	else
	  {
	    set_nonewlines ();
	    s = r->cmd_data.command_data_u.hide_option_cmd.menuoptions;
	    printc ("HIDE OPTION ");
		print_menu_option_list(s);
		/*
	    for (a = 0; a < s->list.list_len; a++)
	      {
		if (a)
		  printc (",");
		real_print_expr (s->list.list_val[a]);
	      }
			*/
	    clr_nonewlines ();
	  }
      }
      break;

    case E_CMD_WHENEVER_CMD:
      print_whenever_style (r->cmd_data.command_data_u.whenever_cmd.whencode, r->cmd_data.command_data_u.whenever_cmd.whento);
      break;



    case E_CMD_OPEN_WINDOW_CMD:
      {
	//char *name;

	if (r->cmd_data.command_data_u.open_window_cmd.wt.wintype == EWT_ROWSCOLS)
	  {
	    if (ui_as_calls ())
	      {

		set_nonewlines ();
		printc ("CALL UILIB_OPEN_WINDOW(");
		print_quoted_ident (r->cmd_data.command_data_u.open_window_cmd.windowname);
		printc (",");
		real_print_expr (r->cmd_data.command_data_u.open_window_cmd.y);
		printc (",");
		real_print_expr (r->cmd_data.command_data_u.open_window_cmd.x);
		printc (" , ");
		real_print_expr (r->cmd_data.command_data_u.open_window_cmd.wt.windowtype_u.rowscols.rows);
		printc (" , ");
		real_print_expr (r->cmd_data.command_data_u.open_window_cmd.wt.windowtype_u.rowscols.columns);
		printc (" ,%s", attributes_as_string (r->cmd_data.command_data_u.open_window_cmd.attributes));
		printc (")");
		clr_nonewlines ();
	      }
	    else
	      {
		set_nonewlines ();
		printc ("OPEN WINDOW ");
		print_ident (r->cmd_data.command_data_u.open_window_cmd.windowname);
		printc (" AT ");
		real_print_expr (r->cmd_data.command_data_u.open_window_cmd.y);
		printc (",");
		real_print_expr (r->cmd_data.command_data_u.open_window_cmd.x);

		printc (" WITH ");
		real_print_expr (r->cmd_data.command_data_u.open_window_cmd.wt.windowtype_u.rowscols.rows);
		printc (" ROWS, ");
		real_print_expr (r->cmd_data.command_data_u.open_window_cmd.wt.windowtype_u.rowscols.columns);
		printc (" COLUMNS");
		if (r->cmd_data.command_data_u.open_window_cmd.attributes)
		  {
		    printc (" ATTRIBUTES(");
		    print_attributes (r->cmd_data.command_data_u.open_window_cmd.attributes);
		    printc (")");
		  }
		clr_nonewlines ();

	      }
	  }

	if (r->cmd_data.command_data_u.open_window_cmd.wt.wintype == EWT_FORM)
	  {
	    if (ui_as_calls ())
	      {
		set_nonewlines ();
		printc ("CALL UILIB_OPEN_WINDOW_WITH_FORM(");
		print_quoted_ident (r->cmd_data.command_data_u.open_window_cmd.windowname);
		printc (",");
		real_print_expr (r->cmd_data.command_data_u.open_window_cmd.y);
		printc (",");
		real_print_expr (r->cmd_data.command_data_u.open_window_cmd.x);
		printc (",");
		real_print_expr (r->cmd_data.command_data_u.open_window_cmd.wt.windowtype_u.formfilename);
		printc (",%s", attributes_as_string (r->cmd_data.command_data_u.open_window_cmd.attributes));
		printc (")");
		clr_nonewlines ();
	      }
	    else
	      {
		set_nonewlines ();
		printc ("OPEN WINDOW ");
		print_ident (r->cmd_data.command_data_u.open_window_cmd.windowname);
		printc (" AT ");
		real_print_expr (r->cmd_data.command_data_u.open_window_cmd.y);
		printc (",");
		real_print_expr (r->cmd_data.command_data_u.open_window_cmd.x);
		clr_nonewlines ();
		set_nonewlines ();
		printc ("   WITH FORM ");
		real_print_expr (r->cmd_data.command_data_u.open_window_cmd.wt.windowtype_u.formfilename);

		if (r->cmd_data.command_data_u.open_window_cmd.attributes)
		  {
		    printc (" ATTRIBUTES(");
		    print_attributes (r->cmd_data.command_data_u.open_window_cmd.attributes);
		    printc (")");
		  }
		clr_nonewlines ();
	      }
	  }
      }
      break;


    case E_CMD_NEED_CMD:
      set_nonewlines ();
      printc ("NEED ");
      real_print_expr (r->cmd_data.command_data_u.need_cmd.expr);
      printc (" LINES");
      clr_nonewlines ();
      break;

    case E_CMD_SKIP_CMD:
      printc ("SKIP %d LINES", r->cmd_data.command_data_u.skip_cmd.lines);
      break;

    case E_CMD_PRINT_CMD:
	{
	struct expr_str_list *l;
      	set_nonewlines ();
	
      	printc ("PRINT ");
	
      	tmp_ccnt++;
	l=r->cmd_data.command_data_u.print_cmd.print_expr;
	if (l) {
		int printed=0;
      		for (a = 0; a < l->list.list_len; a++) {
			if (a) printc(",");
			if (l->list.list_val[a]->expr_type==ET_EXPR_COLUMN && printed!=0) {
				clr_nonewlines();
				set_nonewlines();
			}
			real_print_expr(l->list.list_val[a]);
			printed++;
		}
	}
      	if (r->cmd_data.command_data_u.print_cmd.semi == EB_TRUE)
		{
	  	printc (";");
		}
      	tmp_ccnt--;
      	clr_nonewlines ();
	}
      break;

    case E_CMD_PRINT_FILE_CMD:
      set_nonewlines ();
      printc ("PRINT FILE ");
      real_print_variable_or_literal (r->cmd_data.command_data_u.print_file_cmd.filename, "\"\"");
      if (r->cmd_data.command_data_u.print_file_cmd.semi == EB_TRUE)
	{
	  printc (";");
	}
      clr_nonewlines ();

      break;

    case E_CMD_PAUSE_CMD:
      set_nonewlines ();
      printc ("PAUSE ");
      real_print_variable_or_literal (r->cmd_data.command_data_u.pause_cmd.pause_msg, "\"\"");
      clr_nonewlines ();
      break;

    case E_CMD_RUN_CMD:
      if (A4GL_isyes (acl_getenv ("TRACE4GL")))
	{
	  printc ("CALL trace_4gl(\"RUNNING SOMETHING\")");
	}
      set_nonewlines ();
      printc ("RUN ");
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
	      if (tolower (get_var_expr_scope (r->cmd_data.command_data_u.run_cmd.returning)) == 'm'
		  && A4GL_isyes (acl_getenv ("REMOVEMODVARS")))
		{
		  printh ("#REQUIRETEMP %s lv_tmp_%x_%d %d\n", get_currfuncname (),
			  get_var_expr_dtype (r->cmd_data.command_data_u.run_cmd.returning),
			  a, get_var_expr_dtype (r->cmd_data.command_data_u.run_cmd.returning));

		  A4GL_assertion (get_var_expr_dtype (r->cmd_data.command_data_u.run_cmd.returning) == -2, "-2 detected");

		  printc ("lv_tmp_%x_%d", get_var_expr_dtype (r->cmd_data.command_data_u.run_cmd.returning), 0);
		}
	      else
		{
		  print_varbind (r->cmd_data.command_data_u.run_cmd.returning, 'w', a);
		  if (A4GL_isyes (acl_getenv ("TRACE4GL")))
		    {
		      printc ("CALL trace_4gl(\"Return code = \"||(");
		      print_varbind (r->cmd_data.command_data_u.run_cmd.returning, 'w', a);
		      printc ("  using \"#####&\"))");
		    }
		}
	    }

	}
      clr_nonewlines ();

      if (r->cmd_data.command_data_u.run_cmd.returning)
	{
	  if (tolower
	      (get_var_expr_scope
	       (r->cmd_data.command_data_u.run_cmd.returning)) == 'm' && A4GL_isyes (acl_getenv ("REMOVEMODVARS")))
	    {
	      set_nonewlines ();
	      printc ("CALL ");
	      print_varbind (r->cmd_data.command_data_u.run_cmd.returning, 'W', a);
	      printc ("lv_tmp_%x_%d)", get_var_expr_dtype (r->cmd_data.command_data_u.run_cmd.returning), a);
	      clr_nonewlines ();
	    }
	}
      break;

    case E_CMD_SLEEP_CMD:
      set_nonewlines ();
      printc ("SLEEP ");
      real_print_expr (r->cmd_data.command_data_u.sleep_cmd.sleep_expr);
      clr_nonewlines ();
      break;



    case E_CMD_WHILE_CMD:
      need_daylight ();
      set_nonewlines ();
      printc ("WHILE ");
      real_print_expr (r->cmd_data.command_data_u.while_cmd.while_expr);
      clr_nonewlines ();
      tmp_ccnt++;
      dump_cmds (r->cmd_data.command_data_u.while_cmd.while_commands, r);
      tmp_ccnt--;
      printc ("END WHILE");
      need_daylight ();
      break;

    case E_CMD_MESSAGE_CMD:
      set_nonewlines ();
      if (ui_as_calls ())
	{
	  printc ("CALL UILIB_MESSAGE(");
	  real_print_expr_list_with_separator (r->cmd_data.command_data_u.message_cmd.message_expr, "||");
	  printc (",\"\")");	// @ FIXME - MESSAGE ATTRIBUTE....
	}
      else
	{
	  printc ("MESSAGE ");
	  real_print_expr_list_with_separator (r->cmd_data.command_data_u.message_cmd.message_expr, ",");
	  if (r->cmd_data.command_data_u.message_cmd.attributes)
	    {
	      printc (" ATTRIBUTES (");
	      print_attributes (r->cmd_data.command_data_u.message_cmd.attributes);
	      printc (")");
	    }
	  if (r->cmd_data.command_data_u.message_cmd.wait == EB_TRUE)
	    {
	      printc (" WAIT FOR KEY");
	    }
	}
      clr_nonewlines ();
      break;


    case E_CMD_INIT_CMD:
      {
	struct expr_str_list *use_binding;
	int expand = 0;
	set_nonewlines ();


	if (A4GL_isyes (acl_getenv ("REMOVEMODVARS")))
	  {
	    for (a = 0; a < r->cmd_data.command_data_u.init_cmd.varlist->list.list_len; a++)
	      {
		if (get_var_expr_scope (r->cmd_data.command_data_u.init_cmd.varlist->list.list_val[a]) == 'm')
		  expand = 1;
	      }

	  }

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
	    if (A4GL_isyes (acl_getenv ("REMOVEMODVARS")) && scope == 'm')
	      {
		printh ("#REQUIRETEMP %s lv_tmp_%x_%d %d\n", get_currfuncname (),
			get_var_expr_dtype (use_binding->list.list_val[a]), a, get_var_expr_dtype (use_binding->list.list_val[a]));
		printc ("lv_tmp_%x_%d", get_var_expr_dtype (use_binding->list.list_val[a]), a);
		A4GL_assertion (get_var_expr_dtype (use_binding->list.list_val[a]) == -2, "-2 detected");
	      }
	    else
	      {
		print_varbind (use_binding->list.list_val[a], 'w', a);
	      }
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

    case E_CMD_NEXT_FIELD_CMD:
      switch (r->cmd_data.command_data_u.next_field_cmd.rel)
	{
	case -1:
	  if (ui_as_calls ())
	    {
	      printc ("CALL UILIB_NEXT_FIELD(\"-\")");
	    }
	  else
	    {
	      printc ("NEXT FIELD PREVIOUS");
	    }

	  break;
	case 1:
	  if (ui_as_calls ())
	    {
	      printc ("CALL UILIB_NEXT_FIELD(\"+\")");

	    }
	  else
	    {
	      printc ("NEXT FIELD NEXT");
	    }
	  break;

	case 0:
	  if (ui_as_calls ())
	    {
	      printc ("CALL UILIB_NEXT_FIELD(%s)", xfield_name_as_char (r->cmd_data.command_data_u.next_field_cmd.nextfield));
	    }
	  else
	    {
	      printc ("NEXT FIELD %s", xfield_name_as_char (r->cmd_data.command_data_u.next_field_cmd.nextfield));
	    }
	  break;
	}
      break;


    case E_CMD_SCROLL_CMD:
      set_nonewlines ();
      printc ("SCROLL %s UP BY ", xfield_name_list_as_char (r->cmd_data.command_data_u.scroll_cmd.srec));
      real_print_expr (r->cmd_data.command_data_u.scroll_cmd.val);
      clr_nonewlines ();
      break;

    case E_CMD_OPEN_FORM_CMD:
      set_nonewlines ();
      if (ui_as_calls ())
	{
	  printc ("CALL UILIB_OPEN_FORM(");
	  print_quoted_ident (r->cmd_data.command_data_u.open_form_cmd.formname);
	  printc (",");
	  real_print_expr (r->cmd_data.command_data_u.open_form_cmd.form_filename);
	  printc (")");
	}
      else
	{
	  printc ("OPEN FORM ");
	  print_ident (r->cmd_data.command_data_u.open_form_cmd.formname);
	  printc (" FROM ");
	  real_print_expr (r->cmd_data.command_data_u.open_form_cmd.form_filename);
	}
      clr_nonewlines ();
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
      clr_nonewlines ();
      break;


    case E_CMD_OPTIONS_CMD:
      for (a = 0; a < r->cmd_data.command_data_u.options_cmd.options->options.options_len; a++)
	{
	  print_options (r->cmd_data.command_data_u.options_cmd.options->
			 options.options_val[a]->option[0],
			 r->cmd_data.command_data_u.options_cmd.options->options.options_val[a]->value,
			 r->cmd_data.command_data_u.options_cmd.options->options.options_val[a]->expr);
	}
      break;

    case E_CMD_PREPARE_CMD:

      //if (!when_set_to_call) { A4GL_warn("Coding Standards: Must use 'WHENEVER ERROR CALL get_error_record' before using SQL"); }


      if (r->cmd_data.command_data_u.prepare_cmd.sql->expr_type == ET_E_V_OR_LIT_VAR
	  && tolower (get_var_expr_scope (r->cmd_data.command_data_u.prepare_cmd.sql->expr_str_u.var) == 'm')
	  && A4GL_isyes (acl_getenv ("REMOVEMODVARS")))
	{
	  printc ("LET lv_tmp_%x=", get_var_expr_dtype (r->cmd_data.command_data_u.prepare_cmd.sql->expr_str_u.var));
	  print_varbind (r->cmd_data.command_data_u.prepare_cmd.sql->expr_str_u.var, 'R', 0);
	  printh ("#REQUIRETEMP %s lv_tmp_%x %d\n", get_currfuncname (),
		  get_var_expr_dtype (r->cmd_data.command_data_u.prepare_cmd.sql->expr_str_u.var),
		  get_var_expr_dtype (r->cmd_data.command_data_u.prepare_cmd.sql->expr_str_u.var));
	  set_nonewlines ();

	  if (r->cmd_data.command_data_u.prepare_cmd.connid)
	    {
	      print_connid (r->cmd_data.command_data_u.prepare_cmd.connid);
	    }
	  printc ("PREPARE");
	  print_ident (r->cmd_data.command_data_u.prepare_cmd.stmtid);
	  printc (" FROM lv_tmp_%x", get_var_expr_dtype (r->cmd_data.command_data_u.prepare_cmd.sql->expr_str_u.var));
	}
      else
	{
	  set_nonewlines ();
	  if ((r->cmd_data.command_data_u.prepare_cmd.connid))
	    {
	      print_connid (r->cmd_data.command_data_u.prepare_cmd.connid);
	    }
	  printc ("PREPARE ");
	  print_ident (r->cmd_data.command_data_u.prepare_cmd.stmtid);
	  printc (" FROM ");
	  real_print_variable_or_literal (r->cmd_data.command_data_u.prepare_cmd.sql, "\"\"");
	}
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
      clr_nonewlines ();
      break;

    case E_CMD_INPUT_CMD:
      need_daylight ();
      print_input_fl_g (r->cmd_data.command_data_u.input_cmd.by_name,
			r->cmd_data.command_data_u.input_cmd.without_defaults,
			r->cmd_data.command_data_u.input_cmd.helpno,
			r->cmd_data.command_data_u.input_cmd.field_list,
			r->cmd_data.command_data_u.input_cmd.attributes, r->cmd_data.command_data_u.input_cmd.variables);

      print_events (r->cmd_data.command_data_u.input_cmd.events, r);
      doing_input_array = 0;
      print_input_2 (r->cmd_data.command_data_u.input_cmd.events);
      need_daylight ();

      break;

    case E_CMD_INPUT_ARRAY_CMD:
      need_daylight ();
      print_input_array (r->cmd_data.command_data_u.input_array_cmd.arrayname,
			 r->cmd_data.command_data_u.input_array_cmd.helpno,
			 r->cmd_data.command_data_u.input_array_cmd.without_defaults == EB_TRUE,
			 r->cmd_data.command_data_u.input_array_cmd.srec,
			 r->cmd_data.command_data_u.input_array_cmd.attributes, r->cmd_data.command_data_u.input_array_cmd.slice
			 /* r->cmd_data.command_data_u.input_array_cmd.bind */
	);
      print_events (r->cmd_data.command_data_u.input_array_cmd.events, r);
      doing_input_array = 1;
      print_input_2 (r->cmd_data.command_data_u.input_array_cmd.events);
      need_daylight ();
      break;


    case E_CMD_CONSTRUCT_CMD:
/*
        binding_comp* constr_var;
        cons_list* con_columns;
        fh_field_list* list;
        struct on_events* events;
        struct attrib *attributes;
        e_boolean without_defaults;
        int helpno;
*/
      need_daylight ();
      print_construct_fl_g (r->cmd_data.command_data_u.construct_cmd.by_name,
				r->cmd_data.command_data_u.construct_cmd.constr_var,
			    r->cmd_data.command_data_u.construct_cmd.list,
			    r->cmd_data.command_data_u.construct_cmd.
			    attributes,
			    r->cmd_data.command_data_u.construct_cmd.con_columns, r->cmd_data.command_data_u.construct_cmd.helpno);
      print_events (r->cmd_data.command_data_u.construct_cmd.events, r);
      print_construct_2 (r->cmd_data.command_data_u.construct_cmd.events);
      need_daylight ();
      break;

    case E_CMD_DISPLAY_ARRAY_CMD:
      need_daylight ();
      print_display_array_p1 (r->cmd_data.command_data_u.display_array_cmd.arrayname,
			      r->cmd_data.command_data_u.display_array_cmd.srec,
			      xfield_name_as_char (r->cmd_data.command_data_u.display_array_cmd.scroll_using),
			      r->cmd_data.command_data_u.display_array_cmd.attributes,
			      r->cmd_data.command_data_u.display_array_cmd.slice);
      //r->cmd_data.command_data_u.display_array_cmd 
      print_events (r->cmd_data.command_data_u.display_array_cmd.events, r);
      print_display_array_p2 (r->cmd_data.command_data_u.display_array_cmd.events);
      need_daylight ();
      break;


    case E_CMD_PROMPT_CMD:
      need_daylight ();
      //print_prompt_1 (t_expr_str_list * expr, char *a1, char *a2, char *a3, char *a4, int timeout, char *Style, char *Var)
      if (ui_as_calls ())
	{
	  set_nonewlines ();
	  chk_context (CONTEXT_PROMPT);
	  sprintf (last_context[CONTEXT_PROMPT], "\"%s\",%d", ofilename, curr_yylineno);
	  printc ("CALL UILIB_PROMPT_START(%s,", last_context[CONTEXT_PROMPT]);
	  real_print_expr_list_pipes (r->cmd_data.command_data_u.prompt_cmd.prompt_str);

	  if (r->cmd_data.command_data_u.prompt_cmd.prompt_str_attrib)
	    {
	      printc (",%s", get_attributes_as_string(r->cmd_data.command_data_u.prompt_cmd.prompt_str_attrib));
	    }
	  else
	    {
	      printc (",\"\"");

	    }
	  if (r->cmd_data.command_data_u.prompt_cmd.prompt_fld_attrib)
	    {
	      printc (",%s)", get_attributes_as_string(r->cmd_data.command_data_u.prompt_cmd.prompt_fld_attrib));
	    }
	  else
	    {
	      printc (",\"\")");
	    }
	  clr_nonewlines ();
	  printc ("WHILE TRUE # PROMPT");
	  tmp_ccnt++;
	  printc ("CASE UILIB_PROMPT_LOOP(UILIB_GET_CONTEXT(%s))", last_context[CONTEXT_PROMPT]);
	  tmp_ccnt++;
	  need_daylight(); //printc ("#");
	  printc ("WHEN -1");
	  tmp_ccnt++;
	  //print_event_list (NULL);
	  print_events (r->cmd_data.command_data_u.prompt_cmd.events, r);
	  printc ("CALL UILIB_PROMPT_INITIALISED()");
	  tmp_ccnt--;

	  need_daylight(); //printc ("#");
	  printc ("WHEN -100  # Accept");
	  printc ("   LET ");
	  print_varbind (r->cmd_data.command_data_u.prompt_cmd.promptvar, 'w', a);
	  printc ("=UILIB_GET_PROMPT_RESULT(UILIB_GET_CONTEXT(%s))", last_context[CONTEXT_PROMPT]);
	  if (A4GL_isyes (acl_getenv ("TRACE4GL")))
	    {
	      printc ("CALL trace_4gl(\"prompt returns \"||");
	      print_varbind (r->cmd_data.command_data_u.prompt_cmd.promptvar, 'r', a);
	      printc (")");
	    }
	  printc ("   EXIT WHILE");
	  need_daylight(); //printc ("#");
	  printc ("WHEN -101  # Interrupt");
	  printc ("   LET int_flag=TRUE");
	  printc ("   EXIT WHILE");

	  printc ("OTHERWISE ");
	  printc ("    CALL errorlog(\"Unexpected prompt loop return\")");
	  tmp_ccnt--;
	  printc ("END CASE");
	  tmp_ccnt--;
	  printc ("END WHILE");
	  printc ("CALL UILIB_FREE_PROMPT(UILIB_GET_CONTEXT(%s))", last_context[CONTEXT_PROMPT]);
	  strcpy (last_context[CONTEXT_PROMPT], "");


	}
      else
	{


	  set_nonewlines ();
	  printc ("PROMPT ");
	  real_print_expr_list_with_separator (r->cmd_data.command_data_u.prompt_cmd.prompt_str, ",");
	  if (r->cmd_data.command_data_u.prompt_cmd.prompt_str_attrib)
	    {
	      printc (" ATTRIBUTES (");
	      print_attributes (r->cmd_data.command_data_u.prompt_cmd.prompt_str_attrib);
	      printc (")");
	    }
	  if (r->cmd_data.command_data_u.prompt_cmd.for_char == EB_TRUE)
	    {
	      printc (" FOR CHAR ");
	    }
	  else
	    {
	      printc (" FOR ");
	    }

	  print_varbind (r->cmd_data.command_data_u.prompt_cmd.promptvar, 'w', a);
	  if (r->cmd_data.command_data_u.prompt_cmd.helpno)
	    {
	      printc (" HELP %d", r->cmd_data.command_data_u.prompt_cmd.helpno);
	    }

	  if (r->cmd_data.command_data_u.prompt_cmd.prompt_fld_attrib)
	    {
	      printc (" ATTRIBUTES (");
	      print_attributes (r->cmd_data.command_data_u.prompt_cmd.prompt_fld_attrib);
	      printc (")");
	    }
	  clr_nonewlines ();

	  if (r->cmd_data.command_data_u.prompt_cmd.events)
	    {
	      print_events (r->cmd_data.command_data_u.prompt_cmd.events, r);
	      printc ("END PROMPT");
	    }
	}
      need_daylight ();

      break;


    case E_CMD_START_CMD:
      set_nonewlines ();
      printc ("START REPORT %s", r->cmd_data.command_data_u.start_cmd.repname);
      if (r->cmd_data.command_data_u.start_cmd.sc_c)
	{
	  struct startrep *s;
	  int with = 0;
	  s = r->cmd_data.command_data_u.start_cmd.sc_c;
	  switch (s->towhat)
	    {

	    case 0:
	    case 'D':
	      break;
	    case '-':
	      break;
	    case 'S':
	      printc (" TO SCREEN");
	      break;
	    case 'P':
	    case '|':
	      if (s->s1->expr_type == ET_EXPR_REPORT_PRINTER)
		{
		  printc (" TO PRINTER");
		}
	      else
		{
		  set_nonewlines ();
		  printc (" TO PIPE ");
		  real_print_expr (s->s1);
		  clr_nonewlines ();
		}
	      break;


	    case '@':
	      printc (" TO EMAIL");
	      break;

	    case 'C':
	      printc (" AS CONVERTIBLE");
	      break;
	    case 'F':
	      set_nonewlines ();
	      printc (" TO ");
	      real_print_expr (s->s1);
	      clr_nonewlines ();
	      break;
	    }
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

	  if (with)
	    {
	      int printed = 0;
	      printc (" WITH");
	      if (s->with_page_length != -1)
		{
		  printc (" PAGE LEGTH %d", s->with_page_length);
		  printed++;
		}

	      if (s->with_left_margin != -1)
		{
		  if (printed)
		    printc (",");
		  printc (" LEFT MARGIN %d", s->with_left_margin);
		  printed++;
		}
	      if (s->with_right_margin != -1)
		{
		  if (printed)
		    printc (",");
		  printc ("  RIGHT MARGIN %d", s->with_right_margin);
		  printed++;
		}
	      if (s->with_top_margin != -1)
		{
		  if (printed)
		    printc (",");
		  printc ("  TOP MARGIN %d", s->with_top_margin);
		  printed++;
		}
	      if (s->with_bottom_margin != -1)
		{
		  if (printed)
		    printc (",");
		  printc ("  BOTTOM MARGIN %d", s->with_bottom_margin);
		  printed++;
		}
	      if (strcmp (s->with_top_of_page, "") != 0)
		{
		  if (printed)
		    printc (",");
		  printc (" TOP OF PAGE %s", s->with_top_of_page);
		  printed++;
		}

	    }
	}
      clr_nonewlines ();
      break;

    case E_CMD_CONVERT_CMD:
      set_nonewlines ();
      printc ("CONVERT REPORT %s ", r->cmd_data.command_data_u.convert_cmd.repname);
      print_convert (r->cmd_data.command_data_u.convert_cmd.conv_c);
      clr_nonewlines ();
      //r->cmd_data.command_data_u.convert_cmd 
      break;

    case E_CMD_FREE_REP_CMD:
      printc ("FREE REPORT %s", r->cmd_data.command_data_u.free_rep_cmd.repname);
      break;

    case E_CMD_OUTPUT_CMD:
      set_nonewlines ();
      printc ("OUTPUT TO REPORT %s(", r->cmd_data.command_data_u.output_cmd.repname);
      real_print_expr_list_with_separator (r->cmd_data.command_data_u.output_cmd.expressions, ",");
      printc (")");
      clr_nonewlines ();
      break;

    case E_CMD_FINISH_CMD:
      printc ("FINISH REPORT %s", r->cmd_data.command_data_u.finish_cmd.repname);
      if (r->cmd_data.command_data_u.finish_cmd.conv_c)
	{
	  printc (" CONVERTING TO... ");
	}
      break;

    case E_CMD_TERM_REP_CMD:
      printc ("TERMINATE REPORT %s", r->cmd_data.command_data_u.term_rep_cmd.repname);
      break;

    case E_CMD_CLEAR_CMD:
      switch (r->cmd_data.command_data_u.clear_cmd.clr_data.clr_type)
	{
	case E_CLR_SCREEN:
	  if (ui_as_calls ())
	    {
	      printc ("CALL UILIB_CLEAR_SCREEN()");
	    }
	  else
	    {
	      printc ("CLEAR SCREEN");
	    }
	  break;
	case E_CLR_WINDOW:
	  if (ui_as_calls ())
	    {
	      printc ("CALL UILIB_CLEAR_WINDOW(");
	      print_quoted_ident (r->cmd_data.command_data_u.clear_cmd.clr_data.clear_data_u.window);
	      printc (")");
	    }
	  else
	    {
	      printc ("CLEAR WINDOW ");
	      print_ident (r->cmd_data.command_data_u.clear_cmd.clr_data.clear_data_u.window);
	    }
	  break;
	case E_CLR_STATUS:
	  printc ("CLEAR STATUSBOX ");
	  print_ident (r->cmd_data.command_data_u.clear_cmd.clr_data.clear_data_u.statwindow);
	  break;

	case E_CLR_FORM:
	  if (ui_as_calls ())
	    {
	      printc ("CALL UILIB_CLEAR_FORM(0)");
	    }
	  else
	    {
	      printc ("CLEAR FORM");
	    }
	  break;

	case E_CLR_FORM_DEFAULTS:
	  if (ui_as_calls ())
	    {
	      printc ("CALL UILIB_CLEAR_FORM(1)");
	    }
	  else
	    {
	      printc ("CLEAR FORM TO DEFAULTS");
	    }
	  break;

	case E_CLR_FIELDS:
	  if (ui_as_calls ())
	    {
	      printc_safe_to_split_at_comma ("CALL UILIB_SET_FIELD_LIST(%s)",
					     xfield_name_list_as_char (r->
								       cmd_data.
								       command_data_u.clear_cmd.clr_data.clear_data_u.fields));
	      if (r->cmd_data.command_data_u.clear_cmd.todefaults)
		{
		  printc ("CALL UILIB_CLEAR_TO_DEFAULTS()");
		}
	      else
		{
		  printc ("CALL UILIB_CLEAR()");
		}
	    }
	  else
	    {


	      set_nonewlines ();
	      printc ("CLEAR %s", xfield_name_list_as_char (r->cmd_data.command_data_u.clear_cmd.clr_data.clear_data_u.fields));
	      if (r->cmd_data.command_data_u.clear_cmd.todefaults)
		{
		  printc (" TO DEFAULTS");
		}
	      clr_nonewlines ();
	    }
	  break;

	case E_CLR_FIELDS_TO_DEFAULT:
	  if (ui_as_calls ())
	    {
	      printc_safe_to_split_at_comma ("CALL UILIB_SET_FIELD_LIST(%s)",
					     xfield_name_list_as_char (r->
								       cmd_data.
								       command_data_u.clear_cmd.clr_data.clear_data_u.fields));
	      printc ("CALL UILIB_CLEAR_TO_DEFAULTS()");
	    }
	  else
	    {
	      set_nonewlines ();
	      printc ("CLEAR %s TO DEFAULTS",
		      xfield_name_list_as_char (r->cmd_data.command_data_u.clear_cmd.clr_data.clear_data_u.fields));
	      clr_nonewlines ();
	    }
	}
      break;


    case E_CMD_CURRENT_WIN_CMD:
      if (r->cmd_data.command_data_u.current_win_cmd.windowname == 0)
	{
	  if (ui_as_calls ())
	    {
	      printc ("CALL UILIB_CURRENT_WINDOW(\"SCREEN\")\n");
	    }
	  else
	    {
	      printc ("CURRENT WINDOW IS SCREEN\n");
	    }
	}
      else
	{
	  set_nonewlines ();
	  if (ui_as_calls ())
	    {
	      printc ("CALL UILIB_CURRENT_WINDOW(");
	      print_quoted_ident (r->cmd_data.command_data_u.current_win_cmd.windowname);
	      printc (")");
	    }
	  else
	    {
	      printc ("CURRENT WINDOW IS ");
	      print_ident (r->cmd_data.command_data_u.current_win_cmd.windowname);
	    }
	  clr_nonewlines ();
	}

      break;

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
		      if (tolower (get_var_expr_scope (r->cmd_data.command_data_u.put_cmd.values->list.list_val[a])) == 'm'
			  && A4GL_isyes (acl_getenv ("REMOVEMODVARS")))
			{
			  printc ("lv_tmpi_%x_%d", get_var_expr_dtype (r->cmd_data.command_data_u.put_cmd.values->list.list_val[a]),
				  a);
			}
		      else
			{
			  print_varbind (r->cmd_data.command_data_u.put_cmd.values->list.list_val[a], 'w', 0);
			}
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
      
      if (r->cmd_data.command_data_u.unload_cmd.sql->expr_type==ET_EXPR_SELECT_LIST_ITEM) { 	// Its a select..
		struct s_select *S;
		S=r->cmd_data.command_data_u.unload_cmd.sql->expr_str_u.sl_item->data.s_select_list_item_data_u.subquery;
      		preprocess_sql_statement (S);
      		search_variables (&S->list_of_items);
	} 
	printc(" ");
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
		if (r->cmd_data.command_data_u.load_cmd.delimiter->expr_type==ET_EXPR_FUNC) {
			printc(" USING FILTER %s", r->cmd_data.command_data_u.load_cmd.delimiter->expr_str_u.expr_func.funcname);
		} else {
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
	  printc ("%s", local_get_expr_as_string(r->cmd_data.command_data_u.load_cmd.sqlvar));
	}
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
	  printc ("BEGIN WORK");
	  break;
	case 0:
	  //if (strcmp(current_func->funcname,"rollback_work")!=0) { A4GL_warn("Coding Standards: ROLLBACK WORK used directly"); }
	  printc ("ROLLBACK WORK");
	  break;
	case 1:
	  //if (strcmp(current_func->funcname,"commit_work")!=0) { A4GL_warn("Coding Standards: COMMIT WORK used directly"); }
	  printc ("COMMIT WORK");
	  break;
	default:
	  printc (" BAD TRANS : %d\n", r->cmd_data.command_data_u.sql_transact_cmd.trans);
	}
      clr_nonewlines ();
      break;


#ifdef NOT_YET
    case E_CMD_SELECT_CMD:
      {

	char *s;
	char *p;
	char *p2;
	int a;
	module_var_binding (r->cmd_data.command_data_u.select_cmd.inbind, COPY_DATA_FROM_MODVARS_INTO_TMPS);
	need_daylight ();
	set_nonewlines ();

	//if (!when_set_to_call) { A4GL_warn("Coding Standards: Must use 'WHENEVER ERROR CALL get_error_record' before using SQL"); }
	if ((r->cmd_data.command_data_u.select_cmd.connid))
	  {
	    print_connid (r->cmd_data.command_data_u.select_cmd.connid);
	  }

	s = replace_bind (r->cmd_data.command_data_u.select_cmd.sql, r->cmd_data.command_data_u.select_cmd.inbind, 'r');

	p = find_into_ptr (s);

	if (p == 0)
	  {
	    p = strstr (s, " FROM ");
	    while (1)
	      {
		p2 = strstr (p + 5, " FROM ");
		if (p2)
		  {
		    char *punion;
		    // theres more than one from - either a UNION or a subselect...
		    punion = strstr (s, "UNION ");
		    if (punion)
		      {
			if (punion < p2)
			  {	// the from is in the union - keep the original..
			    break;
			  }
		      }
		    // It looks like a subselect..
		    p = p2;
		    continue;
		  }
		else
		  {
		    break;
		  }
	      }
	  }

	if (p)
	  {
	    *p = 0;
	    p++;
	    printc_safe_to_split_at_comma ("%s", mung_select (s));
	    if (r->cmd_data.command_data_u.select_cmd.outbind)
	      {
		if (r->cmd_data.command_data_u.select_cmd.outbind->list.list_len)
		  {
		    clr_nonewlines ();
		    set_nonewlines ();
		    printc ("INTO ");
		    real_print_binding_with_separator (r->cmd_data.command_data_u.select_cmd.outbind, 'w', ",");
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


	    printc ("%s", mung_select (p));
	    module_var_binding (r->cmd_data.command_data_u.select_cmd.outbind, COPY_DATA_FROM_TMPS_INTO_MODVARS);
	  }
	else
	  {
	    // Should have found it...
	    A4GL_assertion (1, " INTO not placeable");
	  }
	if (nonewlines)
	  {
	    A4GL_assertion (1, "nonewlines still set\n");

	  }
      }
      need_daylight(); //printc ("#");
      break;
#endif

    case E_CMD_FLUSH_CMD:

      set_nonewlines ();
      if ((r->cmd_data.command_data_u.flush_cmd.connid))
	{
	  print_connid (r->cmd_data.command_data_u.flush_cmd.connid);
	}

      printc ("FLUSH ");
      print_ident (r->cmd_data.command_data_u.flush_cmd.cursorname);
      clr_nonewlines ();
      break;


    case E_CMD_DECLARE_CMD:
      {

	need_daylight(); //printc ("#");
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

/*
	A4GL_assertion (r->cmd_data.command_data_u.declare_cmd.sql == 0, "No sql for declare (1)");
	A4GL_assertion (strlen (r->cmd_data.command_data_u.declare_cmd.sql) == 0, "No sql for declare (2)");
*/

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

      }
      need_daylight(); //printc ("#");
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
      A4GL_assertion (1, "Shouldn't use E_CMD_DISPLAY_B_N_CMD");
      break;


/*
    case E_CMD_OPEN_SESSION_CMD:
      // OPEN_SESSION conn_id_p TO_DATABASE var_ident_vl [AS char_or_var_vl PASSWORD char_or_var_vl ]

      set_nonewlines ();
      printc ("OPEN SESSION ");
      print_ident (r->cmd_data.command_data_u.open_session_cmd.connid);
      printc (" TO DATABASE ");
      print_ident (r->cmd_data.command_data_u.open_session_cmd.db);

      if (r->cmd_data.command_data_u.open_session_cmd.userdets->username)
	{
	  printc (" AS ");
	  real_print_expr (r->cmd_data.command_data_u.open_session_cmd.userdets->username);
	  printc (" PASSWORD ");
	  real_print_expr (r->cmd_data.command_data_u.open_session_cmd.userdets->password);
	}

      clr_nonewlines ();
      //r->cmd_data.command_data_u.open_session_cmd 
      break;
*/

    case E_CMD_VALIDATE_CMD:
      for (a = 0; a < r->cmd_data.command_data_u.validate_cmd.list->list.list_len; a++)
	{
	  set_nonewlines ();
	  printc ("VALIDATE ");
	  print_varbind (r->cmd_data.command_data_u.validate_cmd.list->list.list_val[a], 'w', 0);
	  printc (" LIKE %s", r->cmd_data.command_data_u.validate_cmd.tablist->str_list_entry.str_list_entry_val[a]);
	  clr_nonewlines ();
	}
      break;





// ENHANCED COMMANDS....
    case E_CMD_CONNECT_CMD:
      set_nonewlines ();
      printc ("CONNECT TO ");
      print_ident (r->cmd_data.command_data_u.connect_cmd.conn_dbname);
      if (r->cmd_data.command_data_u.connect_cmd.conn_name)
	{
	  printc (" AS ");
	  print_ident (r->cmd_data.command_data_u.connect_cmd.conn_dbname);
	}

      if (r->cmd_data.command_data_u.connect_cmd.username)
	{
	  printc (" USER ");
	  real_print_expr (r->cmd_data.command_data_u.connect_cmd.username);
	  printc (" USING ");
	  real_print_expr (r->cmd_data.command_data_u.connect_cmd.username);
	}

      clr_nonewlines ();
      //r->cmd_data.command_data_u.connect_cmd
      break;

    case E_CMD_CHECK_MENU_CMD:
      set_nonewlines ();
      printc ("CHECK MENUITEM ");
      real_print_str_list_with_separator (r->cmd_data.command_data_u.check_menu_cmd.strlist, ",");
      clr_nonewlines ();
      break;
    case E_CMD_UNCHECK_MENU_CMD:
      set_nonewlines ();
      printc ("CHECK MENUITEM ");
      real_print_str_list_with_separator (r->cmd_data.command_data_u.check_menu_cmd.strlist, ",");
      clr_nonewlines ();
      break;

    case E_CMD_DISABLE_MENU_CMD:
      set_nonewlines ();
      printc ("DISABLE MENUITEM ");
      real_print_str_list_with_separator (r->cmd_data.command_data_u.check_menu_cmd.strlist, ",");
      clr_nonewlines ();
      //r->cmd_data.command_data_u.disable_menu_cmd 
      break;
    case E_CMD_ENABLE_MENU_CMD:
      set_nonewlines ();
      printc ("ENABLE MENUITEM ");
      real_print_str_list_with_separator (r->cmd_data.command_data_u.check_menu_cmd.strlist, ",");
      clr_nonewlines ();
      //r->cmd_data.command_data_u.enable_menu_cmd 
      break;

    case E_CMD_SKIP_BY_CMD:
	  set_nonewlines ();
      printc ("SKIP BY ");
	real_print_expr( r->cmd_data.command_data_u.skip_by_cmd.skip_amt);
	  clr_nonewlines ();
      break;
    case E_CMD_SKIP_TO_CMD:
	  set_nonewlines ();
      printc ("SKIP TO ");
		real_print_expr( r->cmd_data.command_data_u.skip_to_cmd.skip_amt);
	  clr_nonewlines ();
      break;

    case E_CMD_AT_TERM_CMD:
      printc ("AT TERMINATION CALL %s", r->cmd_data.command_data_u.at_term_cmd.funcname);
      break;


    case E_CMD_PRINT_IMG_CMD:
      set_nonewlines ();
      printc ("PRINT IMAGE ");
      print_varbind (r->cmd_data.command_data_u.print_img_cmd.var, 'r', 0);
      if (strcmp (r->cmd_data.command_data_u.print_img_cmd.img_type, "tiff") == 0)
	{
	  printc (" AS TIFF");
	}
      if (strcmp (r->cmd_data.command_data_u.print_img_cmd.img_type, "gif") == 0)
	{
	  printc (" AS GIF");
	}
      if (strcmp (r->cmd_data.command_data_u.print_img_cmd.img_type, "png") == 0)
	{
	  printc (" AS PNG");
	}
      if (strcmp (r->cmd_data.command_data_u.print_img_cmd.img_type, "jpeg") == 0)
	{
	  printc (" AS JPEG");
	}
      if (r->cmd_data.command_data_u.print_img_cmd.scale_x)
	{			// Always come as a pair...
	  printc (" SCALED BY ");
	  real_print_expr (r->cmd_data.command_data_u.print_img_cmd.scale_x);
	  printc (",");
	  real_print_expr (r->cmd_data.command_data_u.print_img_cmd.scale_y);
	}

      if (r->cmd_data.command_data_u.print_img_cmd.semi == EB_TRUE)
	{
	  printc (";");
	}
      clr_nonewlines ();

      //r->cmd_data.command_data_u.print_img_cmd 
      break;


    case E_CMD_SELECT_CMD:
	need_daylight();
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


	if (u->column_list==0) {
		printc(" * = (");
		clr_nonewlines();
	    for (a = 0; a < u->value_list->list.list_len; a++) {
		char comma[2]=",";
		rval = get_select_list_item (0, u->value_list->list.list_val[a]);
		if (a==u->value_list->list.list_len-1) {
			strcpy(comma,"");
		}
		printc("    %s%s",rval,comma);
		}
		printc(")");
		
		
	} else {
	
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
      set_nonewlines ();
      printc ("SHOW MENU %s USING %s", r->cmd_data.command_data_u.show_menu_cmd.menuname,
	      r->cmd_data.command_data_u.show_menu_cmd.menuhandler);
      if (r->cmd_data.command_data_u.show_menu_cmd.mn_file)
	{
	  printc (" FROM ");
	  real_print_expr (r->cmd_data.command_data_u.show_menu_cmd.mn_file);
	}
      clr_nonewlines ();
      //r->cmd_data.command_data_u.show_menu_cmd 
      break;

    case E_CMD_ENABLE_CMD:	// NIY
      //r->cmd_data.command_data_u.enable_cmd 
      break;
    case E_CMD_ENABLE_FORM_CMD:	// NIY
      //r->cmd_data.command_data_u.enable_form_cmd 
      break;
    case E_CMD_DISABLE_CMD:	// NIY
      //r->cmd_data.command_data_u.disable_cmd 
      break;

    case E_CMD_DISABLE_FORM_CMD:	// NIY
      //r->cmd_data.command_data_u.disable_form_cmd 
      break;

    case E_CMD_PDF_CALL_CMD:
      //r->cmd_data.command_data_u.pdf_call_cmd 
      break;

    //case E_CMD_CALL_SHARED_CMD:	//NIY
      //r->cmd_data.command_data_u.call_shared_cmd 
      //break;
    case E_CMD_NEXT_FORM_CMD:	// NIY
      //r->cmd_data.command_data_u.next_form_cmd 
      break;
    case E_CMD_MSG_BOX_CMD:	// NIY
      //r->cmd_data.command_data_u.msg_box_cmd 
      break;
    //case E_CMD_GUI_PROMPT_CMD:	// NIY
      //r->cmd_data.command_data_u.gui_prompt_cmd 
      //break;
    case E_CMD_OPEN_STATUSBOX_CMD:	// NIY
      //r->cmd_data.command_data_u.open_statusbox_cmd 
      break;
    case E_CMD_OPEN_FORM_GUI_CMD:	// NIY
      //r->cmd_data.command_data_u.open_form_gui_cmd 
      break;


    //case E_CMD_FORM_IS_COMPILED_CMD:
      //A4GL_assertion (1, "No longer used");
      //r->cmd_data.command_data_u.form_is_compiled_cmd 
      //break;

    case E_CMD_SET_SESSION_CMD:
      set_nonewlines ();

      if (strcmp (r->cmd_data.command_data_u.set_session_cmd.session_type, "session") == 0)
	{
	  printc ("SET SESSION TO ");
	  real_print_expr (r->cmd_data.command_data_u.set_session_cmd.s1);
	}
      if (strcmp (r->cmd_data.command_data_u.set_session_cmd.session_type, "conn") == 0)
	{
	  printc ("SET SESSION");
	  if (r->cmd_data.command_data_u.set_session_cmd.s1)
	    {
	      printc (" ");
	      real_print_expr (r->cmd_data.command_data_u.set_session_cmd.s1);
	    }
	  printc (" OPTION ");
	  real_print_expr (r->cmd_data.command_data_u.set_session_cmd.s2);
	  printc (" TO ");
	  real_print_expr (r->cmd_data.command_data_u.set_session_cmd.s3);
	}
      if (strcmp (r->cmd_data.command_data_u.set_session_cmd.session_type, "stmt") == 0)
	{
	  printc ("SET CURSOR ");
	  real_print_expr (r->cmd_data.command_data_u.set_session_cmd.s1);
	  printc (" OPTION ");
	  real_print_expr (r->cmd_data.command_data_u.set_session_cmd.s2);
	  printc (" TO ");
	  real_print_expr (r->cmd_data.command_data_u.set_session_cmd.s3);
	}


      clr_nonewlines ();
      //r->cmd_data.command_data_u.set_session_cmd 
      break;

    case E_CMD_START_RPC_CMD:
      {
	int a;
	set_nonewlines ();
	printc ("START EXTERNAL FUNCTION [");
	real_print_expr (r->cmd_data.command_data_u.start_rpc_cmd.valid_port);
	printc ("] FOR ");
	for (a = 0; a < r->cmd_data.command_data_u.start_rpc_cmd.remote_func_list.name.name_len; a++)
	  {
	    if (a)
	      printc (",");
	    printc ("%s", r->cmd_data.command_data_u.start_rpc_cmd.remote_func_list.name.name_val[a]);
	  }
	clr_nonewlines ();
      }
      //dump_cmd_start_rpc (r->cmd_data.command_data_u.start_rpc_cmd);
      break;

    case E_CMD_ALLOC_ARR_CMD:
      set_nonewlines ();
      printc ("ALLOCATE ARRAY ");
      print_varbind (r->cmd_data.command_data_u.resize_arr_cmd.variable, 'w', 0);
      clr_nonewlines ();
      //r->cmd_data.command_data_u.alloc_arr_cmd 
      break;

    case E_CMD_DEALLOC_ARR_CMD:
      set_nonewlines ();
      printc ("DEALLOCATE ARRAY ");
      print_varbind (r->cmd_data.command_data_u.resize_arr_cmd.variable, 'w', 0);
      clr_nonewlines ();
      //r->cmd_data.command_data_u.dealloc_arr_cmd 
      break;

    case E_CMD_RESIZE_ARR_CMD:
      set_nonewlines ();
      printc ("RESIZE ARRAY ");
      print_varbind (r->cmd_data.command_data_u.resize_arr_cmd.variable, 'w', 0);
      clr_nonewlines ();
      //r->cmd_data.command_data_u.resize_arr_cmd 
      break;

    case E_CMD_SHOW_CMD:
      set_nonewlines ();
      printc ("SHOW WINDOW ");
      print_ident (r->cmd_data.command_data_u.show_cmd.windowname);
      clr_nonewlines ();
      //r->cmd_data.command_data_u.show_cmd 
      break;

    case E_CMD_HIDE_CMD:
      set_nonewlines ();
      printc ("HIDE WINDOW ");
      print_ident (r->cmd_data.command_data_u.hide_cmd.windowname);
      clr_nonewlines ();
      //r->cmd_data.command_data_u.hide_cmd 
      break;

    case E_CMD_MOVE_CMD:
      set_nonewlines ();
      printc ("MOVE WINDOW ");
      print_ident (r->cmd_data.command_data_u.move_cmd.windowname);
      if (r->cmd_data.command_data_u.move_cmd.relative == EB_TRUE)
	{
	  printc (" BY ");
	  real_print_expr (r->cmd_data.command_data_u.move_cmd.y);
	  printc (",");
	  real_print_expr (r->cmd_data.command_data_u.move_cmd.x);
	}
      else
	{
	  printc (" TO ");
	  real_print_expr (r->cmd_data.command_data_u.move_cmd.y);
	  printc (",");
	  real_print_expr (r->cmd_data.command_data_u.move_cmd.x);
	}
      clr_nonewlines ();
      //r->cmd_data.command_data_u.move_cmd 
      break;

case E_CMD_LAST:
	A4GL_assertion(1,"Should never happen");
	break;
      //default:      printc("UNHANDLED CMD: %d\n",r->cmd_data.type);
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


static void
load_blacklist_from (char *ptr)
{
  FILE *f;
  char buff[2000];
  f = A4GL_open_file_dbpath (ptr);
  if (f == 0)
    {
      fprintf (stderr, "Unable to open blacklist file (%s)\n", ptr);
      return;
    }
  while (1)
    {
      if (feof (f))
	break;
      strcpy (buff, "");
      fgets (buff, sizeof (buff), f);
      if (strlen (buff))
	{
	  A4GL_trim_nl (buff);
	  add_to_list (LIST_BLACKLIST, buff);
	}
    }
}




//
// Load a list of functions that we will *not* output
// this is typically generated as the result of a lint pass
//
static void
load_blacklist (void)
{
  static int loaded = 0;
  char *ptr;
  if (loaded)
    return;
  loaded++;
  ptr = acl_getenv_not_set_as_0 ("A4GL_BLACKLIST");
  if (ptr == 0)
    return;			// That was easy - no blacklist
  load_blacklist_from (ptr);

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
  load_blacklist ();
}





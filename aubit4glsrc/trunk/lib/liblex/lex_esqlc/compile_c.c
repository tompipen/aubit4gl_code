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
# $Id: compile_c.c,v 1.476 2009-02-17 07:56:51 mikeaubury Exp $
# @TODO - Remove rep_cond & rep_cond_expr from everywhere and replace
# with struct expr_str equivalent
*/
#ifndef lint
	static char const module_id[] =
		"$Id: compile_c.c,v 1.476 2009-02-17 07:56:51 mikeaubury Exp $";
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

int do_subscript_range_check=-1;
#define FGL_PLUS_PLUS
#define set_nonewlines() set_nonewlines_full(__LINE__)
#define a4gl_sizeof(x) ((long)sizeof(x))
//int get_ccnt(void);
//static void print_define_char (char *var, int size, int isstatic_extern);
//static void print_define (char *varstring, int isstatic_extern);
//static void print_start_record (int isstatic_extern, char *varname, char *arrsize, int level);
char * local_rettype (char *s);
//int isin_command (char *cmd_type);
//static int print_bind_expr_portion (void *ptr, char i, int portion);
//
int tmp_ccnt=0;

int set_dont_use_indicators=0;

extern int yylineno;


#define rettype_integer ERROR
//char *rettype_integer (int n);
//void A4GL_initlex(void);

char *last_print_bind_dir_definition_g_rval[255];


//char *get_force_ui(void);
//void A4GL_set_compile_time_convert(int a);

//char *get_debug_filename(void);
int class_cnt=0;
int need_cursorname=0;
struct module_definition *current_module;
int assoc_write=0;
int daylight=0;
static struct command *current_cmd = 0;
int suppress_lines=0;
int new_lines=0;
//char **get_field_codes(char *fields) ;
char *get_curr_report_stack_why(void);
//struct expr_str *A4GL_add_validation_elements_to_expr(struct expr_str *ptr,char *val);
void A4GL_get_event(int n,int *i,char **s) ;
int A4GL_get_nevents(void) ;
//int *get_key_codes(char *keys) ;
//int doing_cs (void);
//int get_validate_list_cnt(void) ;
//char *A4GL_get_important_from_clobber(char *s);
//void add_class_function_to_header (char *identifier, int params,char* is_static);
//void print_reset_state_after_call(int n);
//static void pr_nongroup_report_agg_clr (void);
//char *pdtype(int n) ;
//int doing_report_print=0;
//static struct expr_str_list *A4GL_rationalize_list_concat(struct expr_str_list *l) ;
char cmodname[256]="";
//void A4GL_set_clobber(char *c);
int curr_lineno=0;
//int doing_a_report=0;
//static int find_slice(char *av, char *s, int w) ;
//void merge_files (void);
char this_module_name[256]="";
char filename_for_h[132];
char filename_for_c[132];
char filename_for_output[132];
static int putvalcnt=0;
int returns = 0;
int line_for_cmd = 0;
struct command *parent_stack[1024];
int parent_stack_cnt=0;
char *make_sql_string_and_free (char *first, ...);

struct module_entry *current_entry = 0;


struct variable_list * current_entry_variables=0;

//char *generate_ispdf(void) ;


/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_lib_lex_esqlc_int.h"
#define ONE_NOT_ZERO(x) (x?x:1)

#include "field_handling.h"
#include "compile_c.h"

#include "cmd_funcs.h"
#include "fgl_enums.h"
/*
int when_code[8] = { WHEN_STOP,
  WHEN_NOTSET,
  WHEN_STOP,
  WHEN_CONTINUE,
  WHEN_CONTINUE,
  WHEN_CONTINUE,
  WHEN_NOTSET,
  WHEN_NOTSET
};
char when_to_tmp[64] = "";
char when_to[8][128] = { "", "", "", "", "", "", "", "" };
*/
int LEX_initlib(void) ;
//int dump_command(struct command_data *cd) ;
//void print_variable_usage(expr_str *v) ;
//char *local_expr_as_string(expr_str *s) ;
//void print_push_variable_usage (expr_str *ptr);
char *get_dbg_variable_name(expr_str *v) ;
//expr_str_list *expand_parameters(struct variable_list *var_list, expr_str_list *parameters);
//static void order_by_report_stack (int report_stack_cnt);
static void A4GL_internal_lex_printc (char *fmt, int isjustblankline, va_list * ap);
//void A4GL_internal_lex_printh (char *fmt, va_list * ap);
//void A4GL_internal_lex_printcomment (char *fmt, va_list * ap);
//void print_rep_ret (int report_cnt,int addit);
//void dump_comments (int n);
//int local_is_system_variable (struct variable *v);
//static void print_output_rep (struct rep_structure *rep, int report_cnt,char *curr_rep_name);
void print_nullify (char type, variable_list * v);

//void print_Constant_1 (char *name, struct constant_data *c);
//void print_returning_g (int from_where, struct expr_str_list *bind,int allow_one_or_zero);
//int print_bind_dir_definition_g (struct expr_str_list *lbind,int ignore_esql, char lbind_type);
//static void print_output_rep (struct rep_structure *rep, int report_cnt,char *curr_rep_name);
static void print_end_record (char *vname, struct variable *v, int level);

int rep_print_code;
int last_orderby_type = -1;
//void print_report_table (char *repname, char type, int c,char*asc_desc,struct expr_str_list *funcbind, struct expr_str_list *orderbind);
//int local_print_bind_set_value_g (struct expr_str_list *bind,int ignore_esqlc,int only_native);
//int local_print_bind_set_value_g (struct expr_str_list *bind,int ignore_esqlc,int only_native, char type);
extern int get_rep_no_orderby (void);
//int A4GL_doing_pcode (void);
//int print_bind_set_value_g (struct expr_str_list *bind,char type) ;
//int print_bind_definition_g (struct expr_str_list *l,char i );
//void print_event_list (struct on_events*  evtlist);
//static int gen_ord (char *s);
//int is_substring_variable_usage_in_expr(expr_str *v, expr_str **s, expr_str **e) ;
void print_variable_usage_for_bind(expr_str *v) ;
static void print_function_variable_init (variable_list * fvars);
int chk_ibind_select_internal(struct s_select *s);
//char *get_variable_usage_as_string(struct variable_usage *u ) ;
/*
=====================================================================
                    Variables definitions
=====================================================================
*/

struct command *last_cmd=NULL;
static FILE *outfile = 0;
char mv_repname[256];
int cs_ticker = 0;
int current_ordbindcnt = 0;
static int idle_cnt=0;
/** Pointer to the output C file */

/** Pointer to the output header (.h) file */
static FILE *hfile = 0;

/** The output file name */
//extern char *this_module_name;
//extern char curr_func[];
//extern char *infilename;

/** The source code linenumber */
//extern int lastlineno;
//extern int inp_flags;

//char *expr_name(enum e_expr_type e);


//dll_import struct rep_structure rep_struct;


//extern struct pdf_rep_structure pdf_rep_struct;
//dll_import struct pdf_rep_structure pdf_rep_struct;



/*
=====================================================================
                    Functions prototypes
=====================================================================
*/


static void real_print_expr (struct expr_str *ptr);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

char *
c_generation_trans_quote (char *s)
{
static char buff[2000];
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

static int local_isGenStackInfo(void) {
return current_module->genStackInfo==EB_TRUE;
}
int local_is_system_variable (struct variable *v) {
	return v->user_system=='S';
}

static void set_doing_a_report_call(void) {
	if (is_in_report()==2) {
		printc("{void *_old_rep=A4GL_get_curr_report(); A4GL_set_curr_report(&_rep);");
	}
}

static void clr_doing_a_report_call(int n) {
	if (is_in_report()==2) {
		printc("A4GL_set_curr_report(&_old_rep);} /* %d */",n);
	}
}



char *get_last_print_bind_dir_definition_g_rval(char dir) {
	return last_print_bind_dir_definition_g_rval[(int)dir];
}




/**
 * Print spaces to the increment acording to scope level generated in
 * target C code.
 */
static void
print_space (void)
{
  static char buff[2560];
  int ccnt;
  ccnt=A4GL_get_ccnt()+tmp_ccnt;
A4GL_assertion(tmp_ccnt<0, "tmp_ccnt<0");
  A4GL_assertion (ccnt*3>=sizeof (buff), "Not enough space for spaces") ;
  memset (buff, ' ', sizeof(buff));
  buff[ccnt * 3] = 0;
  FPRINTF (outfile, "%s", buff);
}


void set_suppress_lines(void) {
	suppress_lines++;
}

void clr_suppress_lines(void) {
	suppress_lines--;
	A4GL_assertion(suppress_lines<0,"suppress_lines<0");
}



void
set_nonewlines_full (long l)
{
  if (new_lines == 0)
    {
      printc ("#"); //This is primarily for when INLCINES is set; force the printing of a blank line along with '#line ...' the first time that set_nonewlines is called.
      print_space ();
    }

  //printc ("/*NONEWLINES : %d */", l);
  new_lines++;
}

void
clr_nonewlines (void)
{
  new_lines--;

  if ( new_lines== 0)

    {
      printc ("#");
      daylight = 0;
    }

}


char *get_current_module_name(void) {
	return current_module->module_name;
}

// Returns a cleaned up module name
// with no leading directory or .4gl 
//
char *get_current_module_name_clean(void) {
	char *ptr;
	static char buff[2000];
	static char buff2[2000];

	strcpy(buff,get_current_module_name());
	ptr=strchr(buff,'/');
	while (ptr) {
		*ptr=0;
		ptr++;
		strcpy(buff2,ptr);
		strcpy(buff,buff2);
		ptr=strchr(buff,'/');
	}

	ptr=strchr(buff,'\\');
	while (ptr) {
		*ptr=0;
		ptr++;
		strcpy(buff2,ptr);
		strcpy(buff,buff2);
		ptr=strchr(buff,'\\');
	}

	// We should be pretty much at a string string - any
	// leading directory should be removed
	// now remove any .4gl at the end...
	ptr=strchr(buff,'.');
	if (ptr) *ptr=0;
	return buff;
}

void print_copy_status_not_sql(int l) {

	//printc("a4gl_status=a4gl_lib_status;");

	if (l)  {
		A4GL_prchkerr (l,0);
	} else {
		A4GL_prchkerr (line_for_cmd,0);
	}
}

void print_copy_status_with_sql(int l) {
	print_generation_copy_status();
	//printc("a4gl_status=a4gl_sqlca.sqlcode;");
	if (l)  {
		A4GL_prchkerr (l,1);
	} else {
		A4GL_prchkerr (line_for_cmd,1);
	}
}


static int
dump_cmd (struct command *r)
{
  int ok;
 int last_line=0;
  A4GL_assertion (r->module == 0, "No module");
  A4GL_debug ("Dumping command type : %d (%s %d)\n", r->cmd_data.type, r->module, r->lineno);


  if (r->cmd_data.type==E_CMD_LINT_IGNORE_CMD || r->cmd_data.type==E_CMD_LINT_EXPECT_CMD) {
		// This is just internal - no need to worry about it...
		return 1;
	}

  last_line=line_for_cmd;

  line_for_cmd = r->lineno;
  yylineno=line_for_cmd;

  parent_stack[parent_stack_cnt++]=r;

  /*
  if (r->cmd_data.type != E_CMD_CODE_CMD)
    {
      printc ("\n\naclfgli_clr_err_flg(); //%d \n\n", line_for_cmd);
    }
  */

  current_cmd = r;
  dump_comments (r->lineno);
	switch (current_entry->met_type) {
        	case E_MET_REPORT_DEFINITION:
        	case E_MET_PDF_REPORT_DEFINITION:
        	case E_MET_MAIN_DEFINITION:
       		case E_MET_FUNCTION_DEFINITION:
  			printc("/* CMD : %s Line %d %s */\n", decode_cmd_type(r->cmd_data.type), r->lineno, decode_module_entry_type(current_entry->met_type));
  			printc("A4GLSTK_setCurrentLine(_module_name,%d);", r->lineno);

			break;
		default: break;
	}	
  ok=dump_command(&r->cmd_data);
  parent_stack_cnt--;
  line_for_cmd=last_line;
  return ok;
}




static char *
local_has_comment (int n, int c)
{
  int a;
  for (a = 0; a < current_module->comment_list.comment_list_len; a++)
    {
      if (current_module->comment_list.comment_list_val[a].printed)
        continue;

      if (current_module->comment_list.comment_list_val[a].lineno < n)
        {
          current_module->comment_list.comment_list_val[a].printed++;
          return current_module->comment_list.comment_list_val[a].comment;
        }
      if (current_module->comment_list.comment_list_val[a].lineno == n
          && c < current_module->comment_list.comment_list_val[a].colno)
        {
          current_module->comment_list.comment_list_val[a].printed++;
          return current_module->comment_list.comment_list_val[a].comment;
        }
    }
  return 0;
}



void
dump_comments (int n)
{
  char *ptr;
  char *p;
  int printed = 0;



return ;



  while (1)
    {
      ptr = local_has_comment (n, 0);

      if (ptr == 0)
        return;

      if (!printed)
        {
          printc ("#");
        }

      printed++;
      while (1) 
        {
	  p = strstr (ptr, "/*");
		if (p==NULL) break;
          *(p + 1) = '+';
        }
      while (1) 
        {
	p = strstr (ptr, "*/");
		if (p==NULL) break;
          *p = '+';
        }
      printc ("/* %s */", ptr);
    }
}






static void
open_outfile (void)
{
  char err[132];
  char *ptr;
  char *logtxt;
  char *outputfilename;
  char *override;
time_t ttime;
char buff[256];
  override = acl_getenv_not_set_as_0 ("OVERRIDE_OUTPUT");
  outputfilename = current_module->module_name;


  if (strlen(this_module_name) == 0)
    {
      A4GL_assertion (1,"NO output file name");
    }

  if (override)
    {
		strcpy(this_module_name,override);
    }


  if (!A4GL_env_option_set("A4GL_LOCALOUTPUT")) {
  	strcpy (filename_for_c, this_module_name);
  	strcpy (filename_for_h, this_module_name);
  	strcpy (err, this_module_name);
  } else {
	  char *ptr;
	  // Local output will strip any directory from the output
	  // files and create them in the local directory instead...
	  ptr=this_module_name;
	  if (rindex(ptr,'/')) { ptr=rindex(ptr,'/')+1; }
	  strcpy (filename_for_c, ptr);
          strcpy (filename_for_h, ptr);
          strcpy (err, ptr);
  }

  

  //if ( A4GL_isno(acl_getenv ("A4GL_NOCLOBBER")) ||A4GL_isno(acl_getenv ("A4GL_NOSQLCLOBBER")) )
    //{
      A4GL_debug ("Clobbering...");


      //A4GL_set_clobber (this_module_name);



    //}
    

  A4GL_debug ("Opening output map");

  //openmap (this_module_name);

  ptr = acl_getenv ("A4GL_NOCFILE");
  if (strlen (ptr))
    {
      if (ptr[0] == 'Y' || ptr[0] == 'y')
	{
	  A4GL_debug (">>> NO C FILES... %s", ptr);
	  return;
	}
    }

  if (doing_esql ())
    {
	int lv_esql_type;
	lv_esql_type=esql_type();
	/* We'll get rid of this switch statement soon - use it to check our get_esql_ext function for now though */

      switch (lv_esql_type)
	{
	case E_DIALECT_NONE: A4GL_assertion(1,"No ESQL/C Dialect"); break;

	case E_DIALECT_INFORMIX:
	  if (strcmp(A4GL_get_esql_ext(),".ec")!=0)  printf("Unexpected extension for informix\n");
  		break;

	case E_DIALECT_POSTGRES:
	  if (strcmp(A4GL_get_esql_ext(),".cpc")!=0)  printf("Unexpected extension for postgres\n");
	  break;

	case E_DIALECT_SAPDB:		/* SAPDB pre-compiler also uses .cpc extension */
	  if (strcmp(A4GL_get_esql_ext(),".cpc")!=0)  printf("Unexpected extension for SAP\n");
	  break;

	case E_DIALECT_INGRES:
	  if (strcmp(A4GL_get_esql_ext(),".sc")!=0)  printf("Unexpected extension for INGRES\n");
  		break;

	case E_DIALECT_INFOFLEX:
	  if (strcmp(A4GL_get_esql_ext(),".ec")!=0)  printf("Unexpected extension for infoflex\n");
  		break;
	default : 
		A4GL_assertion(1,"Unhandled esql type");

	}
	strcat(filename_for_c,A4GL_get_esql_ext());
	strcpy(filename_for_output,filename_for_c);
	strcat(filename_for_c,"tmp");
    }
  else
    {
      if (strcmp (acl_getenv ("A4GL_LEXTYPE"), "CS") == 0)
	{
	  /* C#*/
	  strcat (filename_for_c, ".csp");
	  strcpy (filename_for_output, filename_for_c);
	strcat(filename_for_c,"tmp");
	}
      else
	{
	  strcat (filename_for_c, ".c");
	  strcpy (filename_for_output, filename_for_c);
	  strcat(filename_for_c,"tmp");
	}
    }

  if (A4GL_isyes(acl_getenv("DOING_CM"))) {
  	strcat (filename_for_h, "_xxx.h");
  } else {
  	strcat (filename_for_h, ".htmp");
  }

  strcat (err, ".err");


  hfile = A4GL_mja_fopen (filename_for_h, "w");
  if (hfile == 0)
    {
      printf ("Unable to open file %s (Check permissions)\n", filename_for_h);
      exit (3);
    }

  if (acl_getenv_not_set_as_0("A4GL_TARGETDIALECT")) {
  	FPRINTF (hfile, "#define TARGETDIALECT \"%s\"\n", acl_getenv_not_set_as_0("A4GL_TARGETDIALECT"));
  } 
  

  outfile = A4GL_mja_fopen (filename_for_c, "w");
  if (outfile == 0)
    {
      printf ("Unable to open file %s (Check permissions)\n", filename_for_c);
      exit (3);
    }

  A4GL_debug ("Output file is %s", filename_for_c);


  FPRINTF (outfile, "#define fgldate long\n");
	logtxt=acl_getenv_not_set_as_0("FGLLOGTXT");
	if (logtxt==0) logtxt="Not Set";
time(&ttime);
	strcpy(buff,ctime(&ttime));
	A4GL_trim_nl(buff);
	
  FPRINTF (outfile, "static char const _rcsid[]=\"$FGLIdent: %s.4gl Compiler-%s%d Time:%s Log:%s $\";\n",this_module_name, A4GL_internal_version(),A4GL_internal_build(),buff, logtxt);

  FPRINTF (outfile, "static void a4gl_show_compiled_version(void) {\n");
  FPRINTF (outfile, "printf(\"Log: %s\\n\");\n",escape_quotes_and_remove_nl(logtxt));
  FPRINTF (outfile, "printf(\"Aubit4GL Version: %s%d\\n\");\n",A4GL_internal_version(),A4GL_internal_build());
	
  FPRINTF (outfile, "printf(\"Compiled Time %s\\n\");\n",buff);
  FPRINTF (outfile, "exit(0);\n");
  FPRINTF (outfile, "}\n\n");

  

  if (doing_esql ())
    {
      switch (esql_type ())
	{
	case E_DIALECT_NONE: A4GL_assertion(1,"No ESQL/C Dialect"); break;

	case E_DIALECT_INFORMIX:
	  FPRINTF (hfile, "#define DIALECT_INFORMIX\n");
	  if (!A4GL_isno(acl_getenv("ALWAYS_CONVERT_PREPARED"))) {
		  FPRINTF(hfile,"#define ALWAYS_CONVERT_PREPARED\n");
	  }
	  break;
	case E_DIALECT_POSTGRES:
	  FPRINTF (hfile, "#define DIALECT_POSTGRES\n");
	  break;
	case E_DIALECT_SAPDB:
	  FPRINTF (hfile, "#define DIALECT_SAPDB\n");
	  break;
	case E_DIALECT_INGRES:
	  FPRINTF (hfile, "#define DIALECT_INGRES\n");
	  FPRINTF (hfile, "EXEC SQL INCLUDE SQLCA;\n");
	  break;
	case E_DIALECT_INFOFLEX:
	  FPRINTF (hfile, "#define DIALECT_INFOFLEX\n");
	  break;
	default : 
		A4GL_assertion(1,"Unhandled esql type");

	}
    }


  if (strcmp (acl_getenv ("LEXTYPE"), "CS") == 0)
    {
      FPRINTF (hfile, "#define THIS_MODULE %s\n", this_module_name);
      FPRINTF (hfile, "#include \"cs_header.h\"\n");
    }
  else
    {
      FPRINTF (hfile, "#include \"a4gl_incl_4glhdr.h\"\n");
      FPRINTF (hfile, "extern int a4gl_lib_status;\n");
    }

  if (doing_esql ())
    {
      if (A4GLSQLCV_check_requirement ("USE_INDICATOR")) {
      		FPRINTF (hfile, "#define ESQL_USING_INDICATORS\n");
	}
	if (esql_type()==4) {
      		FPRINTF (hfile, "EXEC SQL WHENEVER SQLERROR CONTINUE;\n");
	}
      FPRINTF (hfile, "#include \"a4gl_esql.h\"\n");
    }

/*
  if (strchr (filename_for_h, '/') != 0)
    FPRINTF (outfile, "#include \"%s\"\n", strrchr (filename_for_h, '/') + 1);
  else
    FPRINTF (outfile, "#include \"%s\"\n", filename_for_h);
*/


  if (doing_cs ())
    {
      FPRINTF (hfile, "static string module_name=\"%s.4gl\";\n",
	       this_module_name);

    }
  else
    {
	    char *buff;
	    buff=strdup(this_module_name);

	    if (strchr(buff,'/')) {
			buff=strrchr(buff,'/')+1;
	    }

	    if (strchr(buff,'\\')) {
			buff=strrchr(buff,'\\')+1;
	    }

     	FPRINTF (hfile, "static char *_module_name=\"%s.4gl\";\n", buff);
    }
  SPRINTF1(cmodname,"%s.4gl",this_module_name);
  if (A4GL_isyes(acl_getenv("GLOBALCURS"))) {
		set_global_curs();
  }

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
  /*A4GL_debug("via printc (a) in lib\n");*/
  va_start (ap, fmt);
  if (strcmp(fmt,"#")==0) {
  	A4GL_internal_lex_printc (fmt, 1, &ap);
  } else {
  	A4GL_internal_lex_printc (fmt, 0, &ap);
  }
}





static void
A4GL_internal_lex_printc (char *fmt, int isjustblankline, va_list * ap)
{
  static char buff[40960] = "ERROR-empty init";
  //static char buff2[40960];
  char *ptr;
  int os;

  if (outfile == 0)
    {
      open_outfile ();
      if (outfile == 0)
	return;
    }

  os = vsnprintf (buff, sizeof (buff), fmt, *ap);
  if (os >= sizeof (buff))
    {
      yylineno = line_for_cmd;
      a4gl_yyerror ("Internal error - string too big\n");
      exit (0);
    }


  if (isjustblankline)
    {
      FPRINTF (outfile, "\n");

      if (A4GL_isyes (acl_getenv ("INCLINES")))
        {
	  if (suppress_lines ==0 && new_lines==0)
            {
	      if (line_for_cmd>0)
                {
		  if (current_module && current_module->module_name != 0)
		    {
		      FPRINTF (outfile, "#line %d \"%s.4gl\"\n", line_for_cmd, current_module->module_name);
		    }
		  else
		    {
		      FPRINTF (outfile, "#line %d \"null\"\n", line_for_cmd);	/* curr_infilename); */
		    }
		}
	    }
	}
      return;
    }

  ptr = strtok (buff, "\n");
  while (ptr)
    {
      if (new_lines == 0)
        {
          if (A4GL_isyes (acl_getenv ("INCLINES")))
            {
	      if (suppress_lines == 0 && strstr (buff, "EXEC SQL") == 0)
	        {
	          if (line_for_cmd>0)
                    {
	              if (current_module && current_module->module_name != 0)
	                {
	                  FPRINTF (outfile, "#line %d \"%s.4gl\"\n", line_for_cmd, current_module->module_name);
	                }
	              else
	                {
	                  FPRINTF (outfile, "#line %d \"null\"\n", line_for_cmd);	/* curr_infilename); */
	                }
	            }
                }
            }

          print_space ();
          FPRINTF (outfile, "%s\n", ptr);
        }
        else
	  FPRINTF (outfile, "%s", ptr);

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

void
/* printh (char *fmt, ...) */
A4GL_internal_lex_printh (char *fmt, va_list * ap)
{

  VFPRINTF (hfile, fmt, *ap);

}

/**
 * Print comments to the C output file.
 *
 * If the output file is not opened call the open function.
 *
 * @param fmt the format to be passed to vSPRINTF
 * @param ... The variadic parameters to be passed to vSPRINTF
 */
void
printcomment (char *fmt, ...)
{
  va_list ap;
  va_start (ap, fmt);
  A4GL_internal_lex_printcomment (fmt, &ap);
}

void A4GL_internal_lex_printcomment (char *fmt, va_list * ap)
{
#ifdef USE_PRINTCOMMENT
/*  va_list args; */
  if (outfile == 0)
    {
      open_outfile ();
    }

  if (outfile == 0)
    return;

  if (acl_getenv ("COMMENTS"))
    {
      /*
         va_start (args, fmt);
         vFPRINTF (outfile, fmt, args);
       */
      VFPRINTF (outfile, fmt, ap);
    }
#else
	/**
	 * Empty function for linking purposes when compiling without generation of
	 * comments in the output C module
	 */

  /* Do nothing... */

#endif
}







/**
 *  Print the C code corresponding to the last A4GL_action in a format A4GL_action of
 *  a report.
 */
void print_rep_ret (int report_cnt,int addit)
{
  if (addit) printc("A4GL_%spop_report_section(&_rep,%d);",generate_ispdf (), rep_print_code++);
  printc ("goto report%d_ctrl; /* G1 */\n\n", report_cnt);
}


void print_report_2_1() {
	// Does nothing in this output module - needed by API
}



/**
 * Do not do nothing. - called from /compilers/4glc/mod.c
 */
void
print_clr_status (void)
{
  /* printc ("A4GLSQL_set_status(0);\n"); */
}



char *field_name_as_char(fh_field_entry *fh) {
	//char a[200];
	//char b[200];
	if (fh->fieldsub) {
		return A4GL_field_name_as_char(local_ident_as_string(fh->field,1), local_expr_as_string(fh->fieldsub));
	} else {
		return A4GL_field_name_as_char(local_ident_as_string(fh->field,1), "1");
	}

}


/**
 * Print the generated C code with the implementation of an expression.
 * called from API
 * @param ptr A pointer to an expr_str expression (structure that describes
 * an expression).
 */
void
print_expr (void *ptr)
{
#ifdef DEBUG
  A4GL_debug ("via print_expr in lib");
#endif
  real_print_expr (ptr);
}

char * print_arr_expr_fcall(void *optr) {
struct expr_str *ptr;
static int arr_print=0;
static char buff[256];
ptr=optr;
printh("int _arr_fcall_%d;",arr_print);
printc("/* START FCALL */\n");
real_print_expr(ptr);
printc("_arr_fcall_%d=A4GL_pop_long();",arr_print);
printc("/* END FCALL */\n");
SPRINTF1(buff,"_arr_fcall_%d",arr_print);
arr_print++;
return buff;
}

static void
real_print_expr (struct expr_str *ptr)
{
  void *optr;
  int a;
  A4GL_debug ("Print expr... %p", ptr);

  A4GL_assertion (ptr == 0, "can't print a null pointer...");

  //while (ptr)
    //{
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
		yylineno=line_for_cmd; a4gl_yyerror("Unexpected LIST");
		return;
	  A4GL_assertion (1, "ET_EXPR_EXPR_LIST can't be printed - print using A4GL_print_expr_list or A4GL_print_expr_list_concat");
	  break;

	case ET_EXPR_WORDWRAP:
	  // Wordwraps shouldn't be printed - in the report_print - the wrapped expression should be printed...
	  A4GL_assertion (1, "ET_EXPR_WORDWRAP should never be printed");
	  break;


	  // These should be implemented - but aren't yet... 
	case ET_EXPR_EXTERNAL:
	  A4GL_assertion (1,
			  "ET_EXPR_EXTERNAL has not been implented as an expression yet");
	  break;

	case ET_EXPR_OP_IN:
	  	real_print_expr (ptr->expr_str_u.expr_in->expr);
		for (a=0;a<ptr->expr_str_u.expr_in->elist->list.list_len;a++) {
	  			real_print_expr (ptr->expr_str_u.expr_in->elist->list.list_val[a]);
		}
	  	printc ("A4GL_push_int(%d);",ptr->expr_str_u.expr_in->elist->list.list_len);
	  	printc ("A4GL_pushop(OP_IN);");
	  break;
	case ET_EXPR_OP_NOT_IN:
	  	real_print_expr (ptr->expr_str_u.expr_in->expr);
		for (a=0;a<ptr->expr_str_u.expr_in->elist->list.list_len;a++) {
	  			real_print_expr (ptr->expr_str_u.expr_in->elist->list.list_val[a]);
		}
	  	printc ("A4GL_push_int(%d);",ptr->expr_str_u.expr_in->elist->list.list_len);
	  	printc ("A4GL_pushop(OP_NOTIN);");
	  break;


	case ET_EXPR_NOT_EXISTS_SUBQUERY: 	print_exists_subquery(0, ptr->expr_str_u.expr_exists_sq); break;
	case ET_EXPR_EXISTS_SUBQUERY: 		print_exists_subquery(1, ptr->expr_str_u.expr_exists_sq); break;
	case ET_EXPR_OP_NOTIN_SUBQUERY: 	print_in_subquery(0, ptr->expr_str_u.expr_in_sq); break;
	case ET_EXPR_OP_IN_SUBQUERY: 		print_in_subquery(1, ptr->expr_str_u.expr_in_sq); break;

	case ET_EXPR_STRING:
	  printc ("%s", ptr->expr_str_u.expr_string);
	  free (ptr->expr_str_u.expr_string);
	  break;

	case ET_EXPR_VARIABLE_USAGE:
		print_push_variable_usage(ptr);
	  break;
	case ET_EXPR_TIME:
	  printc ("A4GL_push_time();");
	  break;
	case ET_EXPR_NULL:
	  printc ("A4GL_push_null(2,0);");
	  break;
	case ET_EXPR_TRUE:
	  printc ("A4GL_push_int(1);");
	  break;
	case ET_EXPR_FALSE:
	  printc ("A4GL_push_int(0);");
	  break;
	case ET_EXPR_NOT:
	  real_print_expr (ptr->expr_str_u.expr_expr);
	  printc ("A4GL_pushop(OP_NOT);");
	  break;
	case ET_EXPR_NEG:
	  printc ("A4GL_push_int(0);");
	  real_print_expr (ptr->expr_str_u.expr_expr);
	  printc ("A4GL_pushop(OP_SUB);");
	  break;
	case ET_EXPR_UPSHIFT:
	  real_print_expr (ptr->expr_str_u.expr_expr);
	  printc ("A4GL_upshift_stk();");
	  break;
	case ET_EXPR_DOWNSHIFT:
	  real_print_expr (ptr->expr_str_u.expr_expr);
	  printc ("A4GL_downshift_stk();");
	  break;

	case ET_EXPR_DATE_EXPR:
	  printc ("A4GL_push_date_expr();");
	  break;
	case ET_EXPR_COLUMN:
	  real_print_expr (ptr->expr_str_u.expr_expr);
	  if (current_cmd->cmd_data.type==E_CMD_PRINT_CMD)
	    {
	      printc ("A4GL_%sset_column(&_rep);", generate_ispdf ());
	    }
	  else
	    {
		if (current_cmd->cmd_data.type==E_CMD_LET_CMD) {
	      		printc ("A4GL_ensure_let_column();");
		} else {
	      		printc ("A4GL_ensure_column();");
		}
	    }
	  break;
	case ET_EXPR_TIME_EXPR:
	  printc ("A4GL_push_time_expr();");
	  break;
	case ET_EXPR_TODAY:
	  printc ("A4GL_push_today();");
	  break;

	case ET_EXPR_ASCII:
	  real_print_expr (ptr->expr_str_u.expr_expr);
	  printc ("A4GL_push_ascii();");
	  break;
	case ET_EXPR_EXTEND:
	  real_print_expr (ptr->expr_str_u.expr_extend->expr);
	  printc("A4GL_push_int(%d);",ptr->expr_str_u.expr_extend->to);
	  printc ("aclfgli_extend();");
	  break;



	case ET_EXPR_AGGREGATE :
		if (ptr->expr_str_u.expr_agg->agg_type == 'C') { 
			//printc("A4GL_push_int(_g%d);\n",ptr->expr_str_u.expr_agg->expr_num);
			printc("A4GL_push_agg('C',2, &_g%d, 1);\n",ptr->expr_str_u.expr_agg->expr_num);
		}

		if (ptr->expr_str_u.expr_agg->agg_type == 'P') { 
			printc("A4GL_push_agg('P',2, &_g%d, _gpc%d);\n",ptr->expr_str_u.expr_agg->expr_num,ptr->expr_str_u.expr_agg->expr_num);
			//printc("A4GL_push_double((double)(_g%d*100)/(double)_g%d);\n",ptr->expr_str_u.expr_agg->expr_num,ptr->expr_str_u.expr_agg->expr_num+1); 
		}

		if (ptr->expr_str_u.expr_agg->agg_type == 'S') { 
			printc("A4GL_push_agg('S',_gt_%d, _g%d, _g%dused);\n",ptr->expr_str_u.expr_agg->expr_num, ptr->expr_str_u.expr_agg->expr_num,ptr->expr_str_u.expr_agg->expr_num);
			//printc("if (_g%dused) A4GL_push_double(_g%d); else A4GL_push_null(1,0);\n",ptr->expr_str_u.expr_agg->expr_num,ptr->expr_str_u.expr_agg->expr_num); 
		}

		if (ptr->expr_str_u.expr_agg->agg_type == 'N') {
			printc("A4GL_push_agg('N',_gt_%d, _g%d, _g%dused);\n",ptr->expr_str_u.expr_agg->expr_num, ptr->expr_str_u.expr_agg->expr_num,ptr->expr_str_u.expr_agg->expr_num);
			//printc("A4GL_push_double(_g%d);\n",ptr->expr_str_u.expr_agg->expr_num);
		}

		if (ptr->expr_str_u.expr_agg->agg_type == 'X') {
			printc("A4GL_push_agg('X',_gt_%d, _g%d, _g%dused);\n",ptr->expr_str_u.expr_agg->expr_num, ptr->expr_str_u.expr_agg->expr_num,ptr->expr_str_u.expr_agg->expr_num);
			//printc("A4GL_push_double(_g%d);\n",ptr->expr_str_u.expr_agg->expr_num);
		}


 		if (ptr->expr_str_u.expr_agg->agg_type == 'A') {
			printc("A4GL_push_agg('A',_gt_%d, _g%d, _gavg%d);\n",ptr->expr_str_u.expr_agg->expr_num, ptr->expr_str_u.expr_agg->expr_num,ptr->expr_str_u.expr_agg->expr_num);
			//printc("A4GL_push_double(_g%d/(double)_g%d);\n",ptr->expr_str_u.expr_agg->expr_num,ptr->expr_str_u.expr_agg->expr_num+1);
		}
 		break;
	      


	case ET_EXPR_MM:
	  real_print_expr (ptr->expr_str_u.expr_expr);
	  printc ("A4GL_push_double(-2.83465);A4GL_pushop(OP_MULT);");
	  break;
	case ET_EXPR_CM:
	  real_print_expr (ptr->expr_str_u.expr_expr);
	  printc ("A4GL_push_double(-28.3465);A4GL_pushop(OP_MULT);");

	case ET_EXPR_INCHES:
	  real_print_expr (ptr->expr_str_u.expr_expr);
	  printc ("A4GL_push_double(-72.0);A4GL_pushop(OP_MULT);");
	  break;
	case ET_EXPR_POINTS:
	  real_print_expr (ptr->expr_str_u.expr_expr);
	  printc ("A4GL_push_double(-1);A4GL_pushop(OP_MULT);");
	  break;

	case ET_EXPR_PAGENO:
		if (is_in_report()) {
	  		printc ("A4GL_push_long(_rep.page_no + (_rep.line_no > _rep.page_length ? 1 : 0));");
	    	} else {
			printc("A4GL_push_long(lineno);");
		}
	  break;

	case ET_EXPR_LINENO:
		if (is_in_report()) {
	  		printc ("{static long _ln; _ln=A4GL_report_lineno(&_rep);A4GL_push_long(_ln);}");
	    	} else {
			printc("A4GL_push_long(lineno);");
		}
	  break;

	case ET_EXPR_FCALL:

	  {
	    int a;
	    int b;
	    char lib[255];
	    int params;
	    struct expr_str_list *l;
	    b = 0;
	    if (ptr)
	      {
		l = ptr->expr_str_u.expr_function_call->parameters;
		l = A4GL_rationalize_list (l);
		if (l)
		  {
		    for (a = 0; a < l->list.list_len; a++)
		      {
			real_print_expr (l->list.list_val[a]);
		      }
		  }
	      }

	    params =
	      A4GL_new_list_get_count (ptr->expr_str_u.expr_function_call->
				       parameters);

  		if (is_in_report()) { set_doing_a_report_call(); }
	    if (A4GL_doing_pcode ())
	      {
		printc ("ECALL(\"%s%s\",%d,%d);",
			get_namespace (ptr->expr_str_u.expr_function_call->fname),
			ptr->expr_str_u.expr_function_call->fname,
			ptr->expr_str_u.expr_function_call->line, params);
	      }
	    else
	      {
		if (A4GL_module_has_function (current_module, ptr->expr_str_u.expr_function_call->fname, lib, 0))
		  {
		    // Call shared...
		    printc ("{");
		    printc ("int _retvars;");
		    printc ("A4GLSQL_set_status(0,0);");
		    printc ("_retvars=A4GL_call_4gl_dll(%s,\"%s\",%d); ",
			    lib, ptr->expr_str_u.expr_function_call->fname,
			    params);
		    printc ("if (_retvars!= 1 && a4gl_status==0 ) {");
		    printc ("A4GLSQL_set_status(-3001,0);");
		    printc ("A4GL_chk_err(%d,_module_name);",
			    ptr->expr_str_u.expr_function_call->line);
		    printc ("}");
		    if (strcmp(ptr->expr_str_u.expr_function_call->fname,"set_count")!=0) {printc ("%s", get_reset_state_after_call (0));}
		    printc ("}");

		  }
		else
		  {
		    printc ("{ // FCALL 1");
		    printc ("int _retvars;");
		    printc ("_retvars=%s%s(%d); ", get_namespace (ptr->expr_str_u.expr_function_call-> fname),
			    ptr->expr_str_u.expr_function_call->fname, params);
		    printc ("{");
		    printc ("if (_retvars!= 1 && a4gl_status==0 ) {");
		    printc ("A4GLSQL_set_status(-3001,0);");
		    printc ("A4GL_chk_err(%d,_module_name);", ptr->expr_str_u.expr_function_call->line);
		    printc ("}");
		    printc ("}");
		    if (strcmp(ptr->expr_str_u.expr_function_call->fname,"set_count")!=0) { printc ("%s", get_reset_state_after_call (0)); }
		    printc ("} // FCALL 2");
		  }
		add_function_to_header (ptr->expr_str_u.expr_function_call->fname, ptr->expr_str_u.expr_function_call->namespace, 1, 0);
	      }

  		if (is_in_report()) { clr_doing_a_report_call(1); }
	}
	    break;



	case ET_EXPR_PDF_FCALL:
	{
        	struct s_expr_pdf_function_call *p;
        	p=ptr->expr_str_u.expr_pdf_function_call;
        	real_print_expr_list (p->parameters);
        	printc ("{int _retvars;A4GLSQL_set_status(0,0);\n");
        	if (is_in_report ())
        	{
                	printc ("_retvars=A4GL_pdf_pdffunc(&_rep,%s,%d);\n", p->fname,  p->parameters->list.list_len);
        	}
        	else
        	{
                	printc ("_retvars=A4GL_pdf_pdffunc(0,%s,%d);\n", p->fname, p->parameters->list.list_len);
        	}
		printc ("if (_retvars!= 1 && a4gl_status==0 ) {");
		printc ("A4GLSQL_set_status(-3001,0);");
		printc ("A4GL_chk_err(%d,_module_name);", ptr->expr_str_u.expr_function_call->line);
		printc ("}");
		printc("}");

	}
	break;


	case ET_EXPR_SHARED_FCALL:
	    {
	      int a;
	      struct expr_str_list *l;
	      struct s_expr_shared_function_call *p;
	      if (ptr)
		{
		  p = ptr->expr_str_u.expr_shared_function_call;
		  l = p->parameters;
		  if (l)
		    {
		      for (a = 0; a < l->list.list_len; a++)
			{
			  real_print_expr (l->list.list_val[a]);
			}
		    }
		}
  		if (is_in_report()) { set_doing_a_report_call(); }
	      printc ("  {");
	      printc ("  int _retvars;");
	      printc ("  _retvars=A4GL_call_4gl_dll(\"%s\",\"%s\",%d);",
		      p->lib, p->fname,
		      A4GL_new_list_get_count (p->parameters));
	      printc ("  if (_retvars!=1) {");
	      printc ("      A4GLSQL_set_status(-3001,0);");
	      printc ("      A4GL_chk_err(%d,\"%s\");", p->line, p->module);
	      printc ("      A4GL_pop_args(_retvars);");
	      printc ("      A4GL_push_null(2,0);");
	      printc ("  }");
	      printc ("}");
  		if (is_in_report()) { clr_doing_a_report_call(2); }
	    }
	    break;

	case ET_EXPR_BOUND_FCALL : 
		{
		//extern long a_ibind;
		//extern long a_ebind;
		struct expr_str_list i;
		struct expr_str_list e;

		struct s_expr_bound_fcall *f;
		//int ni;
		//int ne;
  		if (is_in_report()) { set_doing_a_report_call(); }
		f=ptr->expr_str_u.expr_bound_fcall;
	        printc("{ /*X1*/");
		
		i.list.list_len=1;
		i.list.list_val=malloc(sizeof(struct expr_str *));
		i.list.list_val[0]=f->channel;
		if (f->values==0) {
			//A4GL_assertion(1,"No values");
			f->values=&e;
			e.list.list_len=0;
			e.list.list_val=0;
		}

  			print_bind_definition_g (&i,'i');
  			print_bind_definition_g (f->values,'e');

  			print_bind_set_value_g (&i,'i');

  			print_bind_set_value_g (f->values,'e');
	        printc("  A4GLSQL_set_status(0,0);");
		printc("  if (A4GL_call_4gl_dll_bound(%s,%s,%d,ibind,%d,ebind)!=1 && a4gl_status==0) { ",f->lib, f->fname,1,f->values->list.list_len);
		printc("    A4GLSQL_set_status(-3001,0);");
		printc("    A4GL_chk_err(%d,_module_name);",f->line);
		printc("  }");
	   	printc("}");
  		if (is_in_report()) { clr_doing_a_report_call(3); }
		break;
		}



	case ET_EXPR_MEMBER_FCALL:
	    {
	      int a;
		struct expr_str *vu_e;
			int nparam=0;
	      struct expr_str_list *l;
	struct variable_usage *vu;
	struct variable_usage *vu_top;
	struct variable *v;
	//char errbuff[256];
	//enum e_scope scope;
	struct variable_usage *vu_n;
	      struct s_expr_member_function_call *p;
	char *func;
	char *s;
	int datatype;
        char errbuff[256];
        enum e_scope scope;

	struct variable_usage *vu_bottom;
		  p = ptr->expr_str_u.expr_member_function_call;
		  l = p->parameters;
		nparam=0;
		  if (l)
		    {
			nparam=l->list.list_len;
		      for (a = 0; a < l->list.list_len; a++)
			{
			  real_print_expr (l->list.list_val[a]);
			}
		    }
	      printc ("{");
	      printc ("      int _retvars;");
		vu_e=p->var_usage_ptr;
		vu=0;
		switch (vu_e->expr_type) {
			case ET_EXPR_VARIABLE_USAGE : 
				vu_top=vu_e->expr_str_u.expr_variable_usage;
				break;
			default: break;
		}
		if (vu_top==0) {
				a4gl_yyerror("Unable to get variable usage");
				return;
		}
			vu=vu_top;

		while (vu->next) {
			vu_n=vu;
			vu=vu->next;
		}
		// When  we get to here vu_n should be the last portion of the variale
		// vu should be the function
		vu_n->next=0;
		func=vu->variable_name;
		s=generation_get_variable_usage_as_string(vu_top);
		//v=local_find_variable_from_usage(vu_top);
		v=find_variable_vu_ptr(errbuff, vu_top, &scope,0);
		vu_bottom=usage_bottom_level(vu_top);
		datatype=vu_bottom->datatype & DTYPE_MASK;
  	      printc ("_retvars=A4GL_call_datatype_function_i(&%s,0x%x,\"%s\",%d);\n", s, datatype,func, nparam);

	      printc ("      if (_retvars!=1) {");
	      printc ("          A4GLSQL_set_status(-3001,0);");
	      printc ("          A4GL_chk_err(%d,\"%s\");", p->line, p->module);
	      printc ("          A4GL_pop_args(_retvars);");
	      printc ("          A4GL_push_null(2,0);");
	      printc ("      }");
	      printc ("}");
	  }

	  break;

	case ET_EXPR_REPORT_PRINTER:
	  printc ("A4GL_push_char(acl_getenv(\"DBPRINT\"));");
	  break;
	case ET_EXPR_REPORT_EMAIL:
	  printc ("A4GL_push_char(A4GL_get_tmp_rep(_module_name,\"%s\"));",
		  ptr->expr_str_u.expr_string);
	  break;


	case ET_EXPR_LITERAL_LONG:
	  printc ("A4GL_push_long(%ld);", ptr->expr_str_u.expr_long);
	  break;

	case ET_EXPR_LITERAL_STRING:
		//printf("ptr->expr_str_u.expr_string=%s\n", ptr->expr_str_u.expr_string);
	  printc ("A4GL_push_char(\"%s\");", ptr->expr_str_u.expr_string);
	  break;
	case ET_EXPR_QUOTED_STRING:
	  printc ("A4GL_push_char(%s);", ptr->expr_str_u.expr_string);
	  break;
	case ET_EXPR_LITERAL_DOUBLE_STR:
	  printc ("A4GL_push_double_str(\"%s\");", ptr->expr_str_u.expr_string);
	  break;
	case ET_EXPR_OP_CLIP:
	  real_print_expr (ptr->expr_str_u.expr_expr);
	  printc ("A4GL_pushop(OP_CLIP);");
	  break;
	case ET_EXPR_OP_ISNULL:
	  real_print_expr (ptr->expr_str_u.expr_expr);
	  printc ("A4GL_pushop(OP_ISNULL);");
	  break;
	case ET_EXPR_OP_ISNOTNULL:
	  real_print_expr (ptr->expr_str_u.expr_expr);
	  printc ("A4GL_pushop(OP_ISNOTNULL);");
	  break;
	case ET_EXPR_OP_MATCHES:
	  real_print_expr (ptr->expr_str_u.expr_op->left);
	  real_print_expr (ptr->expr_str_u.expr_op->right);
	  if (ptr->expr_str_u.expr_op->escape)
	    {
	      real_print_expr (ptr->expr_str_u.expr_op->escape);
	    }
	  else
	    {
	      printc ("A4GL_push_char(\"\\\\\");");
	    }
	  printc ("A4GL_pushop(OP_MATCHES);");
	  break;
	case ET_EXPR_OP_NOT_MATCHES:
	  real_print_expr (ptr->expr_str_u.expr_op->left);
	  real_print_expr (ptr->expr_str_u.expr_op->right);
	  if (ptr->expr_str_u.expr_op->escape)
	    {
	      real_print_expr (ptr->expr_str_u.expr_op->escape);
	    }
	  else
	    {
	      printc ("A4GL_push_char(\"\\\\\");");
	    }
	  printc ("A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);");
	  break;



	case ET_EXPR_OP_LIKE:
	  real_print_expr (ptr->expr_str_u.expr_op->left);
	  real_print_expr (ptr->expr_str_u.expr_op->right);
	  if (ptr->expr_str_u.expr_op->escape)
	    {
	      real_print_expr (ptr->expr_str_u.expr_op->escape);
	    }
	  else
	    {
	      printc ("A4GL_push_char(\"\\\\\");");
	    }
	  printc ("A4GL_pushop(OP_LIKE);");
	  break;
	case ET_EXPR_OP_NOT_LIKE:
	  real_print_expr (ptr->expr_str_u.expr_op->left);
	  real_print_expr (ptr->expr_str_u.expr_op->right);
	  if (ptr->expr_str_u.expr_op->escape)
	    {
	      real_print_expr (ptr->expr_str_u.expr_op->escape);
	    }
	  else
	    {
	      printc ("A4GL_push_char(\"\\\\\");");
	    }
	  printc ("A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);");
	  break;



	case ET_EXPR_OP_ADD:
	  real_print_expr (ptr->expr_str_u.expr_op->left);
	  real_print_expr (ptr->expr_str_u.expr_op->right);
	  printc ("A4GL_pushop(OP_ADD);");
	  break;
	case ET_EXPR_OP_SUB:
	  real_print_expr (ptr->expr_str_u.expr_op->left);
	  real_print_expr (ptr->expr_str_u.expr_op->right);
	  printc ("A4GL_pushop(OP_SUB);");
	  break;
	case ET_EXPR_OP_DIV:
	  real_print_expr (ptr->expr_str_u.expr_op->left);
	  real_print_expr (ptr->expr_str_u.expr_op->right);
	  printc ("A4GL_pushop(OP_DIV);");
	  break;

	case ET_EXPR_OP_MULT:
	  real_print_expr (ptr->expr_str_u.expr_op->left);
	  real_print_expr (ptr->expr_str_u.expr_op->right);
	  printc ("A4GL_pushop(OP_MULT);");
	  break;


	case ET_EXPR_OP_LESS_THAN:
	  real_print_expr (ptr->expr_str_u.expr_op->left);
	  real_print_expr (ptr->expr_str_u.expr_op->right);
	  printc ("A4GL_pushop(OP_LESS_THAN);");
	  break;

	case ET_EXPR_OP_GREATER_THAN:
	  real_print_expr (ptr->expr_str_u.expr_op->left);
	  real_print_expr (ptr->expr_str_u.expr_op->right);
	  printc ("A4GL_pushop(OP_GREATER_THAN);");
	  break;
	case ET_EXPR_OP_EQUAL:
	  real_print_expr (ptr->expr_str_u.expr_op->left);
	  real_print_expr (ptr->expr_str_u.expr_op->right);
	  printc ("A4GL_pushop(OP_EQUAL);");
	  break;
	case ET_EXPR_OP_NOT_EQUAL:
	  real_print_expr (ptr->expr_str_u.expr_op->left);
	  real_print_expr (ptr->expr_str_u.expr_op->right);
	  printc ("A4GL_pushop(OP_NOT_EQUAL);");
	  break;
	case ET_EXPR_OP_LESS_THAN_EQ:
	  real_print_expr (ptr->expr_str_u.expr_op->left);
	  real_print_expr (ptr->expr_str_u.expr_op->right);
	  printc ("A4GL_pushop(OP_LESS_THAN_EQ);");
	  break;

	case ET_EXPR_OP_GREATER_THAN_EQ:
	  real_print_expr (ptr->expr_str_u.expr_op->left);
	  real_print_expr (ptr->expr_str_u.expr_op->right);
	  printc ("A4GL_pushop(OP_GREATER_THAN_EQ);");
	  break;

	case ET_EXPR_OP_OR:
	  real_print_expr (ptr->expr_str_u.expr_op->left);
	  real_print_expr (ptr->expr_str_u.expr_op->right);
	  printc ("A4GL_pushop(OP_OR);");
	  break;
	case ET_EXPR_OP_AND:
	  real_print_expr (ptr->expr_str_u.expr_op->left);
	  real_print_expr (ptr->expr_str_u.expr_op->right);
	  printc ("A4GL_pushop(OP_AND);");
	  break;

	case ET_EXPR_LITERAL_EMPTY_STRING:
	  printc ("A4GL_push_empty_char();");
	  break;

	case ET_EXPR_OP_USING:
	  real_print_expr (ptr->expr_str_u.expr_op->left);
	  real_print_expr (ptr->expr_str_u.expr_op->right);
	  printc ("A4GL_pushop(OP_USING);");
	  break;
	case ET_EXPR_OP_MOD:
	  real_print_expr (ptr->expr_str_u.expr_op->left);
	  real_print_expr (ptr->expr_str_u.expr_op->right);
	  printc ("A4GL_pushop(OP_MOD);");
	  break;
	case ET_EXPR_OP_POWER:
	  real_print_expr (ptr->expr_str_u.expr_op->left);
	  real_print_expr (ptr->expr_str_u.expr_op->right);
	  printc ("A4GL_pushop(OP_POWER);");
	  break;
	case ET_EXPR_OP_CONCAT:
	  real_print_expr (ptr->expr_str_u.expr_op->left);
	  real_print_expr (ptr->expr_str_u.expr_op->right);
	  printc ("A4GL_pushop(OP_CONCAT);");
	  break;
	case ET_EXPR_OP_YEAR:
	  real_print_expr (ptr->expr_str_u.expr_expr);
	  printc ("A4GL_pushop(OP_YEAR);");
	  break;
	case ET_EXPR_OP_MONTH:
	  real_print_expr (ptr->expr_str_u.expr_expr);
	  printc ("A4GL_pushop(OP_MONTH);");
	  break;
	case ET_EXPR_OP_DAY:
	  real_print_expr (ptr->expr_str_u.expr_expr);
	  printc ("A4GL_pushop(OP_DAY);");
	  break;
	case ET_EXPR_OP_HOUR:
	  real_print_expr (ptr->expr_str_u.expr_expr);
	  printc ("A4GL_pushop(OP_HOUR);");
	  break;
	case ET_EXPR_OP_MINUTE:
	  real_print_expr (ptr->expr_str_u.expr_expr);
	  printc ("A4GL_pushop(OP_MINUTE);");
	  break;
	case ET_EXPR_OP_SECOND:
	  real_print_expr (ptr->expr_str_u.expr_expr);
	  printc ("A4GL_pushop(OP_SECOND);");
	  break;
	case ET_EXPR_CURRENT:
	  printc ("A4GL_push_current(%d,%d);", ptr->expr_str_u.expr_current->from,
		  ptr->expr_str_u.expr_current->to);
	  break;

	case ET_EXPR_OP_SPACES:
	  real_print_expr (ptr->expr_str_u.expr_expr);
	  printc ("A4GL_add_spaces();");
	  break;


	case ET_EXPR_CONCAT_LIST:
	  	A4GL_assertion(1,"CONCAT_LIST NOT IMPLEMENTED YET"); break;

	case ET_EXPR_CAST:
		real_print_expr(ptr->expr_str_u.expr_cast->expr);
		printc("A4GL_cast_top_of_stack_to_dtype(%d);",ptr->expr_str_u.expr_cast->target_dtype);
		break;


	case ET_EXPR_DTVAL:
		printc("acli_datetime(%s,%d);",ptr->expr_str_u.expr_datetime->dtval,ptr->expr_str_u.expr_datetime->extend);
		break;

	case ET_EXPR_YEAR_FUNC:
	  	real_print_expr (ptr->expr_str_u.expr_expr);
		printc("aclfgl_year(1);");break;

	case ET_EXPR_DATE_FUNC:
	  	real_print_expr (ptr->expr_str_u.expr_expr);
		printc("aclfgl_date(1);");break;

	case ET_EXPR_MONTH_FUNC:
	  	real_print_expr (ptr->expr_str_u.expr_expr);
		printc("aclfgl_month(1);");break;

	case ET_EXPR_DAY_FUNC:
	  	real_print_expr (ptr->expr_str_u.expr_expr);
		printc("aclfgl_day(1);");break;

	case ET_EXPR_TIME_FUNC:
	  	real_print_expr (ptr->expr_str_u.expr_expr);
		printc("aclfgl_time(1);");break;


	case ET_EXPR_INFIELD:
		if (A4GL_doing_pcode()) {
		if (ptr->expr_str_u.expr_infield->sio_id!=-1) {
			printc("A4GL_pushint_fgl_infield(&_sio_%d,_inp_io_type,%s,NULL,0);",(int)ptr->expr_str_u.expr_infield->sio_id,local_field_name_list_as_char(ptr->expr_str_u.expr_infield->field_list));
		} else {
			printc("A4GL_pushint_fgl_infield(NULL,0,%s,NULL,0);",local_field_name_list_as_char(ptr->expr_str_u.expr_infield->field_list));
		}
		} else {
		if (ptr->expr_str_u.expr_infield->sio_id!=-1) {
			printc("A4GL_push_int(A4GL_fgl_infield(&_sio_%d,_inp_io_type,%s,NULL,0));",(int)ptr->expr_str_u.expr_infield->sio_id,local_field_name_list_as_char(ptr->expr_str_u.expr_infield->field_list));
		} else {
			printc("A4GL_push_int(A4GL_fgl_infield(NULL,0,%s,NULL,0));",local_field_name_list_as_char(ptr->expr_str_u.expr_infield->field_list));
		}
		}
	  	break;


	case ET_EXPR_TEMP:
			A4GL_assertion(1,"Not used for ESQL/C");
			break;

	case ET_EXPR_FIELD_TOUCHED:
		printc("A4GL_push_int(A4GL_fgl_fieldtouched(&_sio_%d,_inp_io_type,%s,NULL,0));",(int)ptr->expr_str_u.expr_field_touched->sio_id,local_field_name_list_as_char(ptr->expr_str_u.expr_field_touched->field_list));
		break;

	case ET_EXPR_NOT_FIELD_TOUCHED:
		printc("A4GL_push_int(!A4GL_fgl_fieldtouched(&_sio_%d,_inp_io_type,%s,NULL,0));",(int)ptr->expr_str_u.expr_field_touched->sio_id,local_field_name_list_as_char(ptr->expr_str_u.expr_field_touched->field_list));
		break;

	case ET_EXPR_IVAL_VAL:
		printc("acli_interval(%s,%d);",ptr->expr_str_u.expr_interval->intval,ptr->expr_str_u.expr_interval->extend);
		break;


	case ET_EXPR_FGL_SIZEOF:
                printc("A4GL_push_long(sizeof(%s));",generation_get_variable_usage_as_string(ptr->expr_str_u.expr_expr->expr_str_u.expr_variable_usage));
		break;






        case ET_EXPR_FGL_ADDRESSOF:
                printc("A4GL_push_long(&(%s));",generation_get_variable_usage_as_string(ptr->expr_str_u.expr_expr->expr_str_u.expr_variable_usage));
		break;

        case ET_EXPR_FGL_ISDYNARR_ALLOCATED:
                printc("A4GL_isdynarr_allocated(&%s);",generation_get_variable_usage_as_string(ptr->expr_str_u.expr_expr->expr_str_u.expr_variable_usage));
		break;

        case ET_EXPR_FGL_DYNARR_EXTENTSIZE:
                printc("A4GL_dynarr_extent(&%s,%d);",generation_get_variable_usage_as_string(ptr->expr_str_u.expr_dynarr_extent->var->expr_str_u.expr_variable_usage),ptr->expr_str_u.expr_dynarr_extent->n);
		break;
        
        case ET_EXPR_FIELDTOWIDGET:
                printc("A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",field_name_as_char(ptr->expr_str_u.expr_field_entry));
		break;

        case ET_EXPR_ID_TO_INT:
                printc("A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",field_name_as_char(ptr->expr_str_u.expr_field_entry)); 
		break;

	case ET_EXPR_REFERENCE:	
		{
		char *var_usage_str;
		expr_str *referenced_expression;
		referenced_expression=ptr->expr_str_u.expr_expr;
		if (referenced_expression->expr_type!=ET_EXPR_VARIABLE_USAGE) {
			a4gl_yyerror("Cant apply a reference to a non-variable expression");
		} 
		var_usage_str=generation_get_variable_usage_as_string(ptr->expr_str_u.expr_expr->expr_str_u.expr_variable_usage);
		printc("A4GL_push_reference(&%s,sizeof(%s));",var_usage_str,var_usage_str);
		}
		break;
	case ET_EXPR_GET_FLDBUF: 
	  printc ("{");
	  printc ("int _retvars;");
	  printc ("_retvars=A4GL_fgl_getfldbuf(&_sio_%d,_inp_io_type,_fldlist, %s,NULL,0);",
		  (int)ptr->expr_str_u.expr_get_fldbuf->sio_id,
	  	local_field_name_list_as_char (ptr->expr_str_u.expr_get_fldbuf->field_list)
		  );
		
	  printc
	    ("if (_retvars != 1 ) {A4GLSQL_set_status(-3001,0);A4GL_chk_err(%d,\"%s\");}",
	     ptr->expr_str_u.expr_get_fldbuf->line,
	     ptr->expr_str_u.expr_get_fldbuf->module);
		

	  printc ("}");
	  break;

	case ET_EXPR_BRACKET:
		real_print_expr(ptr->expr_str_u.expr_expr); break;


	case ET_EXPR_MODULE_FUNC:
		printc("A4GL_push_char(_module_name);");break;
		break;

	case ET_E_V_OR_LIT_STRING:
		printc("A4GL_push_char(%s);",  ptr->expr_str_u.s);
		break;

	case ET_E_V_OR_LIT_INT:
		printc("A4GL_push_long(%d);",  ptr->expr_str_u.i);
		break;

	case ET_EXPR_IDENTIFIER:
		printc("A4GL_push_char(\"%s\");",  ptr->expr_str_u.expr_string);
		break;
	case ET_EXPR_VARIABLE_IDENTIFIER:
		print_expr(ptr->expr_str_u.expr_expr);
		break;

	case ET_EXPR_CURSOR_NAME_FUNCTION:
		need_cursorname++;
		print_expr(ptr->expr_str_u.expr_expr);
		printc("acl_get_cursorname();");
		break;


        case ET_EXPR_PDF_X:
		print_expr(ptr->expr_str_u.expr_expr);
		if (is_in_report ()) {
			printc("A4GL_convert_to_pdf_x(&_rep);");
		} else {
			printc("A4GL_convert_to_pdf_x(NULL);");
		}
		break;

        case ET_EXPR_PDF_Y:
		print_expr(ptr->expr_str_u.expr_expr);
		if (is_in_report ()) {
			printc("A4GL_convert_to_pdf_y(&_rep);");
		} else {
			printc("A4GL_convert_to_pdf_y(NULL);");
		}
		break;

        case ET_EXPR_PDF_CURRENT_X:
		if (is_in_report ()) {
			printc("A4GL_get_current_pdf_x(&_rep);");
		} else {
			printc("A4GL_get_current_pdf_x(NULL);");
		}
		break;

        case ET_EXPR_PDF_CURRENT_Y:
		if (is_in_report ()) {
			printc("A4GL_get_current_pdf_y(&_rep);");
		} else {
			printc("A4GL_get_current_pdf_y(NULL);");
		}
		break;

		
	      default: 
					       	
			printf("Expression type : %d (%s) \n",ptr->expr_type, decode_e_expr_type(ptr->expr_type));
		      A4GL_assertion(1,"Unhandled expression type");

	}

      optr = ptr;

      //free (optr);		// <----      THIS FREE SHOULD BE OK

      //
      //  if valgrind indicates its a problem - check
      //  you've got a 'break' after the case's above....
      //
    //}
}


/*
int
attributes_as_int (struct attrib *a)
{
int attr;
  if (a==0) return -1;
  attr=a->color;
  if (a->normal==EB_TRUE)
    attr += AUBIT_ATTR_NORMAL;
  if (a->reverse==EB_TRUE)
    attr += AUBIT_ATTR_REVERSE;
  if (a->underline==EB_TRUE )
    attr += AUBIT_ATTR_UNDERLINE;
  if (a->bold==EB_TRUE)
    attr += AUBIT_ATTR_BOLD;
  if (a->blink==EB_TRUE)
    attr += AUBIT_ATTR_BLINK;
  if (a->dim==EB_TRUE)
    attr += AUBIT_ATTR_DIM;
  if (a->invisible==EB_TRUE)
    attr += AUBIT_ATTR_INVISIBLE;
 
	//A4GL_assertion(1,"FIXME");
  return attr;
  return 0;
}
*/


/**
 * Print the form attributes to the generated C code in the output file.
 *
 * @param form_attrib A Pointer to the structure form_attrib that describes
 * the form attributes.
 */
void
print_form_attrib_v2 (int iswindow, struct attrib *form_attrib)
{
//int frm_attr;
char *buffer[20];
if (form_attrib==0) {
	printc("%d,255,255,255,255,0,255,255,(0xffff)", iswindow);
	return;
}

buffer[0]=strdup(form_attrib->form_line?local_expr_as_string(form_attrib->form_line):"255");
buffer[1]=strdup(form_attrib->error_line?local_expr_as_string(form_attrib->error_line):"255");
buffer[2]=strdup(form_attrib->prompt_line?local_expr_as_string(form_attrib->prompt_line):"255");
buffer[3]=strdup(form_attrib->menu_line?local_expr_as_string(form_attrib->menu_line):"255");
buffer[4]=strdup(form_attrib->comment_line?local_expr_as_string(form_attrib->comment_line):"255");
buffer[5]=strdup(form_attrib->message_line?local_expr_as_string(form_attrib->message_line): "255");


	//frm_attr=attributes_as_int(form_attrib);

  printc ("%d,%s,%s,%s,%s,%d,%s,%s,_attr",
	  iswindow,
	buffer[0],
	buffer[1],
	buffer[2],
	buffer[3],
	  form_attrib->border==EB_TRUE,
	buffer[4],
	buffer[5]
	);
free(buffer[0]);
free(buffer[1]);
free(buffer[2]);
free(buffer[3]);
free(buffer[4]);
free(buffer[5]);
#ifdef DEBUG
  A4GL_debug ("Printing attributes\n");
  A4GL_debug ("%d,%d,%d,%d,%d,%d,%d,%d,%s", form_attrib->iswindow,
	      form_attrib->form_line, form_attrib->error_line,
	      form_attrib->prompt_line, form_attrib->menu_line,
	      form_attrib->border, form_attrib->comment_line,
	      form_attrib->message_line, frm_attr);
#endif
}





struct expr_str_list *A4GL_rationalize_list_concat(struct expr_str_list *l) {
  int a;
  struct expr_str *p;
  struct expr_str *p2;
  struct expr_str_list *l2;

  if (l == 0)
    return 0;
  l = A4GL_rationalize_list (l);

  if ((l->list.list_len) > 1)
    {
      for (a = 0; a < l->list.list_len - 1; a++)
	{
	  p = l->list.list_val[a];
	  p2 = l->list.list_val[a + 1];

	  if (p->expr_type == ET_EXPR_LITERAL_STRING
	      && p2->expr_type == ET_EXPR_LITERAL_STRING)
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




void
A4GL_print_expr_list_concat (struct expr_str_list *l)
{
  int a;
  struct expr_str *p;
  int printed = 0;

  if (l == 0)
    return;
  l = A4GL_rationalize_list_concat (l);

  for (a = 0; a < l->list.list_len; a++)
    {
      p = l->list.list_val[a];
      if (p->expr_type == ET_EXPR_REDUCED)
	continue;

      print_expr (l->list.list_val[a]);

      if (printed)
	{
	  printc ("A4GL_pushop(OP_CONCAT); /* 1 */");
	}
      printed++;

    }

}


struct variable_usage *usage_bottom_level( variable_usage *u) {
	while (u->next) u=u->next;
	return u;

}

int get_binding_dtype(expr_str *e) {
struct  variable_usage *u;


switch (e->expr_type) {
	case ET_EXPR_LINENO:
	case ET_EXPR_PAGENO:
			return DTYPE_INT;
	case ET_EXPR_TODAY:
			return DTYPE_DATE;

	case ET_EXPR_PARAMETER:
		A4GL_assertion(1,"Should have been expanded away...");
		break;

	case ET_EXPR_VARIABLE_USAGE_WITH_ASC_DESC:
		// If this assert fails - we've not found the variable previously and
		// the datatype isnt set :-(
		u=e->expr_str_u.expr_variable_usage_with_asc_desc->var_usage;
		u=usage_bottom_level(u);
		if(u->datatype<0) {
			set_yytext(generation_get_variable_usage_as_string(u));
			a4gl_yyerror("Invalid variable usage");
			return 0;
		}
		//A4GL_assertion(u->datatype<0,"Invalid datatype") ;
		return u->datatype;


	case ET_EXPR_VARIABLE_USAGE:
		// If this assert fails - we've not found the variable previously and
		// the datatype isnt set :-(
		u=e->expr_str_u.expr_variable_usage;
		u=usage_bottom_level(u);
		if(u->datatype<0) {
			set_yytext(generation_get_variable_usage_as_string(u));
			a4gl_yyerror("Invalid variable usage");
			return 0;
		}
		A4GL_assertion(u->datatype<0,"Invalid datatype") ;
		return u->datatype;

	case ET_EXPR_LITERAL_EMPTY_STRING:
		return DTYPE_CHAR+ENCODE_SIZE(1);

	case ET_E_V_OR_LIT_STRING:
	case ET_EXPR_LITERAL_STRING:
		// Can happen on a PUT  - but its never a substring...
		return DTYPE_CHAR + ENCODE_SIZE(strlen(e->expr_str_u.expr_string));

	case ET_EXPR_NULL:
		// Can happen on a PUT  - but its never a substring...
		return DTYPE_CHAR+ENCODE_SIZE(1);

	case ET_EXPR_LITERAL_LONG:
		return 2;

	default:
		A4GL_assertion(1,"Not implemented");
}
return 0;

}


static char  *get_start_char_subscript (expr_str *e) {
struct  variable_usage *u;
static char buff[1024];
switch (e->expr_type) {
	case ET_EXPR_PARAMETER:
		A4GL_assertion(1,"Should have been expanded away...");
		break;



	case ET_EXPR_VARIABLE_USAGE_WITH_ASC_DESC:
		// If this assert fails - we've not found the variable previously and
		// the datatype isnt set :-(
		 u=e->expr_str_u.expr_variable_usage_with_asc_desc->var_usage;
		u=usage_bottom_level(u);
		if(u->datatype<0) {
			set_yytext(generation_get_variable_usage_as_string(u));
			a4gl_yyerror("Invalid variable usage");
			return 0;
		}
		A4GL_assertion(u->datatype<0,"Invalid datatype") ;
		if (u->substrings_start==0) return "0";
		return local_expr_as_string(u->substrings_start);


	case ET_EXPR_VARIABLE_USAGE:
		// If this assert fails - we've not found the variable previously and
		// the datatype isnt set :-(
		u=e->expr_str_u.expr_variable_usage;
		u=usage_bottom_level(u);
		if(u->datatype<0) {
			set_yytext(generation_get_variable_usage_as_string(u));
			a4gl_yyerror("Invalid variable usage");
			return 0;
		}
		A4GL_assertion(u->datatype<0,"Invalid datatype") ;
		if (u->substrings_start==0) return "0";
		strcpy(buff, local_expr_as_string(u->substrings_start));
		return buff;

	case ET_EXPR_NULL:
	case ET_EXPR_LITERAL_EMPTY_STRING:
	case ET_EXPR_LITERAL_STRING:
	case ET_EXPR_LITERAL_LONG:
	case ET_E_V_OR_LIT_STRING:
		// Can happen on a PUT  - but its never a substring...
		return "0";

	default:
		A4GL_assertion(1,"Not implemented");
}
return 0;
}

static char  *get_end_char_subscript (expr_str *e) {
struct  variable_usage *u;
static char buff[1024];
switch (e->expr_type) {
	case ET_EXPR_PARAMETER:
		A4GL_assertion(1,"Should have been expanded away...");
		break;
	case ET_EXPR_VARIABLE_USAGE_WITH_ASC_DESC:
		// If this assert fails - we've not found the variable previously and
		// the datatype isnt set :-(
		u=e->expr_str_u.expr_variable_usage_with_asc_desc->var_usage;
		u=usage_bottom_level(u);
		if(u->datatype<0) {
			set_yytext(generation_get_variable_usage_as_string(u));
			a4gl_yyerror("Invalid variable usage");
			return 0;
		}
		A4GL_assertion(u->datatype<0,"Invalid datatype") ;
		if (u->substrings_end==0) return "0";
		return local_expr_as_string(u->substrings_end);

	case ET_EXPR_VARIABLE_USAGE:
		// If this assert fails - we've not found the variable previously and
		// the datatype isnt set :-(
		u=e->expr_str_u.expr_variable_usage;
		u=usage_bottom_level(u);
		if(u->datatype<0) {
			set_yytext(generation_get_variable_usage_as_string(u));
			a4gl_yyerror("Invalid variable usage");
			return 0;
		}
		A4GL_assertion(u->datatype<0,"Invalid datatype") ;
		if (u->substrings_end==0) return "0";
		strcpy(buff, local_expr_as_string(u->substrings_end));
		return buff;


	case ET_EXPR_LITERAL_EMPTY_STRING:
	case ET_EXPR_NULL:
	case ET_EXPR_LITERAL_STRING:
	case ET_EXPR_LITERAL_LONG:
	case ET_E_V_OR_LIT_STRING:
		// Can happen on a PUT  - but its never a substring...
		return "0";

	default:
		A4GL_assertion(1,"Not implemented");
}
return 0;
}





static char *get_bottom_level_variable_name( expr_str *e) {
struct variable_usage *u=0;
if ( e->expr_type== ET_EXPR_VARIABLE_USAGE ) {
	u=e->expr_str_u.expr_variable_usage;
}
if (e->expr_type== ET_EXPR_VARIABLE_USAGE_WITH_ASC_DESC ) {
	u=e->expr_str_u.expr_variable_usage_with_asc_desc->var_usage;
}
	
if ( u==0) {
	A4GL_assertion(1,"Expecting a VARIABLE_USAGE");
}

while (u->next) u=u->next;
return u->variable_name;
// Check e is a variable usage - and return the last portion (ie the last bit after the '.')
A4GL_assertion(1,"Not implemented yet");
return 0;
}
/**
 * Generates the C implementation for 4gl function parameters.
 *
 * The parser found the begining of a function declaration until the end of
 * local variables.
 *
 * @param i The storage type of the function:
 *   - f : Normal function.
 *   - r : Static.
 * @return The number of parameters of the function.
 */
int
print_param_g (char i,char*fname, struct expr_str_list *bind)
{
  int a;
  int b;
  char *ptr;
  struct expr_str_list empty;
  empty.list.list_len=0;
  empty.list.list_val=0;
  if (bind==0) {
	bind=&empty;
  }



  if (i=='r') {
    	printc ("static struct BINDING _rbind[%d]={ /*print_param_g */ \n", ONE_NOT_ZERO(bind->list.list_len));
  } else {
    	printc ("struct BINDING _%cbind[%d]={ /* %d print_param_g */\n", i, ONE_NOT_ZERO(bind->list.list_len),bind->list.list_len);
  }
      if (bind->list.list_len == 0)
	{
		set_suppress_lines();
	  printc ("{NULL,0,0,0,0,0}");
	} else {
		set_suppress_lines();
  		for (a = 0; a < bind->list.list_len; a++)
    		{
		int dtype;
		dtype=get_binding_dtype(bind->list.list_val[a]);
      		if (a > 0)
			printc (",\n");
      		printc ("{NULL,%d,%d,0,0,0}", (int) dtype & 0xffff, (int) dtype >> 16);
				
    		}
	}
  printc ("\n}; ");
	printcomment("/* end of binding.6 */\n");
  if (i == 'r')
    {
      printc ("static char *_rbindvarname[%d]={ /*print_param_g */\n", ONE_NOT_ZERO(bind->list.list_len));
	if (bind->list.list_len==0) {printc("0");}

      for (b = 0; b < bind->list.list_len; b++)
	{
			// Get the last portion of the variable name if its a record...
	  ptr = get_bottom_level_variable_name( bind->list.list_val[b]); 
	  if (b)
	    printc (",");

	  printc ("\"%s\"", ptr);
	}
      printc ("};\n");
    }


if (!A4GL_doing_pcode()) {
  printc ("char *_paramnames[%d]={ /* %d */ /*print_param_g */", bind->list.list_len+1,bind->list.list_len);

  for (a = 0; a < bind->list.list_len; a++)
    {
      printc ("  \"%s\",", get_dbg_variable_name(bind->list.list_val[a]));
    }
    printc("0");
  printc ("};");
}
	clr_suppress_lines();

  for (a=0;a<bind->list.list_len;a++) {
        int dtype;
        dtype=get_binding_dtype(bind->list.list_val[a]);
	if (i=='r') {
		set_nonewlines();
    		printc ("_rbind[%d].ptr= (&", a);
		print_variable_usage(bind->list.list_val[a]);
    		printc (");\n");
		clr_nonewlines();
		if ((dtype & DTYPE_MASK)==DTYPE_DYNAMIC_ARRAY) {
			set_nonewlines();
    			printc ("_rbind[%d].size= sizeof(struct _dynelem_%s);",  a,get_bottom_level_variable_name( bind->list.list_val[a])); 
			clr_nonewlines();
		}
	} else {
		set_nonewlines();
    		printc ("_fbind[%d].ptr= &", a);
		print_variable_usage(bind->list.list_val[a]);
    		printc (";");
		clr_nonewlines();

		if ((dtype & DTYPE_MASK)==DTYPE_REFERENCE) {
			set_nonewlines();
    			printc ("_fbind[%d].size= sizeof(",a);
			print_variable_usage(bind->list.list_val[a]);
			printc(");");
			clr_nonewlines();
		}

		if ((dtype & DTYPE_MASK)==DTYPE_DYNAMIC_ARRAY) {
			set_nonewlines();
    			printc ("_fbind[%d].size= sizeof(struct _dynelem_%s);",  a,get_bottom_level_variable_name( bind->list.list_val[a])); 
			clr_nonewlines();
		}

	}
  }


  return a;
}






/**
 * Print the C implementation of the returning substatement of CALL statement.
 */
void print_returning_g (int from_where,struct expr_str_list *bind,int allow_one_or_zero)
{
  int cnt;
   printc("/* pr %d */",from_where);


  if (bind) {
  if (bind->list.list_len) {
  	printc ("{ /* print_returning */\n");
	cnt=print_bind_dir_definition_g(bind,1,'i');
  	//cnt = print_bind_definition_g (bind);
  	
local_print_bind_set_value_g (bind,1,0,'i');
  } else {
	  cnt=0;
  }
  } else {
	cnt=0;
  }


  if (cnt) {
	  if (A4GL_doing_pcode()) {
		printc("if (_retvars!= %d) {if (_retvars!=-1||1) {if (a4gl_status==0) A4GLSQL_set_status(-3001,0);A4GL_pop_args(_retvars);}} else {A4GLSQL_set_status(0,0);A4GL_pop_params(ibind,%d);}",cnt,cnt);
	  } else {
  		printc("CHECK_RETURN_AND_POP(%d);",cnt);
	  }
	printc("}");
  } else {
	  if (A4GL_doing_pcode()) { 
		  printc("if (_retvars!= 0) {");
		  printc("  if (_retvars!=-1||1) {");
		  printc("    if (a4gl_status==0) A4GLSQL_set_status(-3001,0);");
		  printc("    A4GL_pop_args(_retvars);");
	          printc("  }");
	          printc("} else {");
		  printc("    A4GLSQL_set_status(0,0);");
		  printc("}");
	  } else {
		if (allow_one_or_zero) {
			if (cnt) {
  				printc("CHECK_ONE_OR_NO_RETURN_POP;");
			} else {
  				printc("CHECK_ONE_OR_NO_RETURN;");
			}
		} else {
  			printc("CHECK_NO_RETURN;");
		}
	  }

  }
  printc ("}\n");
}




void real_print_expr_list (struct expr_str_list *l)
{
  int a;
      l=A4GL_rationalize_list(l);
      if (l)
	{
	  for (a = 0; a < l->list.list_len; a++)
	    {
	      real_print_expr (l->list.list_val[a]);
	    }
	}

}



/**
 *
 * @todo Describe function
 */
void
real_print_func_call (t_expr_str * fcall)
{
  char lib[255]="<not set>";
  int args_cnt;
  
//  NOTE - ANYTHING IN HERE SHOULD PROBABLY BE DUPLICATED IN THE 'real_print_expr' ROUTINE...
//
 


  if (fcall->expr_type == ET_EXPR_FCALL)
    {
      struct s_expr_function_call *p;
      p = fcall->expr_str_u.expr_function_call;
      p->parameters=A4GL_rationalize_list(p->parameters);
      args_cnt = A4GL_new_list_get_count (p->parameters);


      real_print_expr_list (p->parameters);
      printc ("/* done print expr */");
      add_function_to_header (p->fname, p->namespace,1, 0);


      if (A4GL_module_has_function (current_module, p->fname, lib, 0))
	{
	  printc ("{int _retvars;\n");
  		if (is_in_report()) { set_doing_a_report_call(); }
	  if (A4GL_doing_pcode()) {
  		printc ("A4GLSTK_setCurrentLine(\"%s\",%d);", cmodname, p->line);
	  } else {
	  	printc ("A4GLSTK_setCurrentLine(_module_name,%d);", p->line);
	  }
	  printc
	    ("A4GLSQL_set_status(0,0);_retvars=A4GL_call_4gl_dll(%s,\"%s\",%d); /* 1 */\n",
	     lib, p->fname, args_cnt);
	}
      else
	{
	  printc ("{int _retvars;A4GLSQL_set_status(0,0);\n");
  		if (is_in_report()) { set_doing_a_report_call(); }
	  if (A4GL_doing_pcode()) {
  		printc ("A4GLSTK_setCurrentLine(\"%s\",%d);", cmodname, p->line);
	  } else {
	  	printc ("A4GLSTK_setCurrentLine(_module_name,%d);", p->line);
	  }
	  if (A4GL_doing_pcode()) {
	  	printc ("_retvars=%s%s(%d);\n", get_namespace (p->fname), p->fname, args_cnt);
	  } else {
	  	printc ("_retvars=%s%s(%d);\n", get_namespace (p->fname), p->fname, args_cnt);
	  }
	}
  	if (is_in_report()) { clr_doing_a_report_call(4); }
      if (strcmp(p->fname,"set_count")!=0) {print_reset_state_after_call (0);}
      return;
    }

  if (fcall->expr_type==ET_EXPR_BOUND_FCALL)  {

	  printc ("{int _retvars=1; \n");
	  printc("/* EXPR_BOUND_FCALL */");
	  real_print_expr (fcall);
	  printc("/* END EXPR_BOUND_FCALL */");
	  return;

  }


  if (fcall->expr_type==ET_EXPR_MEMBER_FCALL)  {
      struct s_expr_member_function_call *p;
      //struct expr_str_list *expr;
      //int nargs;
	      int a;
		struct expr_str *vu_e;
			int nparam=0;
	      struct expr_str_list *l;
	struct variable_usage *vu;
	struct variable_usage *vu_top;
	struct variable *v;
	char errbuff[256];
	enum e_scope scope;
	struct variable_usage *vu_n;
	char *func;
	char *s;
	int datatype;
	struct variable_usage *vu_bottom;

      		p=fcall->expr_str_u.expr_member_function_call;
		  //p = ptr->expr_str_u.expr_member_function_call;
		  l = p->parameters;
		nparam=0;
		  if (l)
		    {
			nparam=l->list.list_len;
		      for (a = 0; a < l->list.list_len; a++)
			{
			  real_print_expr (l->list.list_val[a]);
			}
		    }
	      printc ("{");
	      printc ("      int _retvars;");
		vu_e=p->var_usage_ptr;
		vu=0;
		switch (vu_e->expr_type) {
			case ET_EXPR_VARIABLE_USAGE : 
				vu_top=vu_e->expr_str_u.expr_variable_usage;
				break;
			default: break;
		}
		if (vu_top==0) {
				a4gl_yyerror("Unable to get variable usage");
				return;
		}
			vu=vu_top;

		while (vu->next) {
			vu_n=vu;
			vu=vu->next;
		}
		// When  we get to here vu_n should be the last portion of the variale
		// vu should be the function
		vu_n->next=0;
		func=vu->variable_name;
		s=generation_get_variable_usage_as_string(vu_top);
		v=find_variable_vu_ptr(errbuff, vu_top, &scope,0);
		vu_bottom=usage_bottom_level(vu_top);
		datatype=vu_bottom->datatype & DTYPE_MASK;
      		printc ("A4GLSTK_setCurrentLine(_module_name,%d);", p->line);
  	      printc ("A4GLSQL_set_status(0,0); _retvars=A4GL_call_datatype_function_i(&%s,0x%x,\"%s\",%d);\n", s, datatype,func, nparam);

      print_reset_state_after_call(0);

	return;
  }


  if (fcall->expr_type==ET_EXPR_SHARED_FCALL)  {
      struct s_expr_shared_function_call *p;
      int nargs;
      struct expr_str_list *expr;
      p = fcall->expr_str_u.expr_shared_function_call;
      expr=A4GL_rationalize_list(p->parameters);
      nargs = A4GL_new_list_get_count (expr);
      printc ("{int _retvars;\n");
      real_print_expr_list (expr);
	  if (A4GL_doing_pcode()) {
  		printc ("A4GLSTK_setCurrentLine(\"%s\",%d);", cmodname, p->line);
	  } else {
      		printc ("A4GLSTK_setCurrentLine(_module_name,%d);", p->line);
	  }
      printc ("A4GLSQL_set_status(0,0);_retvars=A4GL_call_4gl_dll(\"%s\",\"%s\",%d); /* 2 */\n", p->lib, p->fname, nargs);
      print_reset_state_after_call(0);
      return;
  }

  if (fcall->expr_type==ET_EXPR_GET_FLDBUF) {
	struct s_expr_get_fldbuf *p;
	p=fcall->expr_str_u.expr_get_fldbuf;
	printc("{");
	printc("   int _retvars;");
	A4GL_pause_execution();
	printc("   _retvars=A4GL_fgl_getfldbuf(&_sio_%d,_inp_io_type,_fldlist, %s,NULL,0);",(int)p->sio_id, local_field_name_list_as_char(p->field_list));
	/* 
	printc("   if (_retvars != 1 ) {");
	printc("      A4GLSQL_set_status(-3001,0);");
	printc("      A4GL_chk_err(%d,\"%s\");",p->line,p->module);
  	printc("   }");
	*/
        print_reset_state_after_call(0);
	return;
  }


  if (fcall->expr_type==ET_EXPR_EXTERNAL) {
	struct s_expr_external_call *p;
	struct expr_str_list *expr;
	int nargs;
	p=fcall->expr_str_u.expr_external_call;
        expr=A4GL_rationalize_list(p->parameters);
	real_print_expr_list(expr); 
	nargs=A4GL_new_list_get_count(expr);
  	printc ("{int _retvars;\n");
        printc("int _port;");
	print_expr(p->port);
	printc("_port=A4GL_pop_long();");
	  if (A4GL_doing_pcode()) {
  		printc ("A4GLSTK_setCurrentLine(\"%s\",%d);", cmodname, p->line);
	  } else {
  		printc ("A4GLSTK_setCurrentLine(_module_name,%d);", p->line);
	}
  	printc ("_retvars=A4GL_remote_func_call(%s,%d,%s,_port,%d);\n", p->host, p->without_waiting,p->func,  nargs);
	print_reset_state_after_call(0);
	return;
  }

  if (fcall->expr_type==ET_EXPR_FORM_IS_COMPILED) {
		struct s_expr_form_is_compiled *x;
		x=fcall->expr_str_u.expr_form_is_compiled;
		printc("{char *_packer; char *_formtype;int _retvars=0;");
		print_expr(x->params->list.list_val[0]);
		printc("_packer=A4GL_char_pop();");
		print_expr(x->params->list.list_val[1]);
		printc("_formtype=A4GL_char_pop();");
		printc("A4GL_add_compiled_form(\"%s\",_formtype,_packer,compiled_form_%s);",
			x->formname->expr_str_u.expr_string,
			x->formname->expr_str_u.expr_string);
		printc("free(_packer);free(_formtype);");
		printh ("extern char compiled_form_%s[];\n", x->formname->expr_str_u.expr_string);
		return ;
  }


  if (fcall->expr_type==ET_EXPR_PDF_FCALL) {	
	struct s_expr_pdf_function_call *p;
	p=fcall->expr_str_u.expr_pdf_function_call;
  	real_print_expr_list (p->parameters);
  	printc ("{int _retvars;A4GLSQL_set_status(0,0);\n");
  	if (is_in_report ())
    	{
      		printc ("_retvars=A4GL_pdf_pdffunc(&_rep,%s,%d);\n", p->fname, p->parameters->list.list_len);
    	}
  	else
    	{
      		printc ("_retvars=A4GL_pdf_pdffunc(NULL,%s,%d);\n", p->fname, p->parameters->list.list_len);
    	}

	return;
  }

  A4GL_assertion (1, "Internal error - expecting a function call");
}







/**
 * Print the C implementation of the WHEN from the CASE 4gl statement.
 *
 * @param has_expr Flag that indicates if the WHEN have a specific expression:
 *   - 0 : Does not have expression.
 *   - 1 : Have expression.
 */
void
print_when (int has_expr,t_expr_str *expr)
{

  if (!has_expr) { // We'd expect some form of test then...
	switch (expr->expr_type) {
		// Does it look like a string ? 
		case ET_EXPR_LITERAL_STRING:
		case ET_EXPR_LITERAL_EMPTY_STRING:
		case ET_EXPR_OP_CLIP:
		case ET_EXPR_OP_USING: 
		case ET_EXPR_UPSHIFT:
		case ET_EXPR_DOWNSHIFT:
		case ET_EXPR_STRING:
		case ET_EXPR_OP_CONCAT:
		case ET_EXPR_OP_SPACES:
		case ET_EXPR_LITERAL_DOUBLE_STR:
		case ET_EXPR_GET_FLDBUF:
		case ET_EXPR_WORDWRAP:
		case ET_EXPR_CONCAT_LIST:
			A4GL_warn("Use of string for WHEN in a CASE with no expression"); break;

		case ET_EXPR_VARIABLE_USAGE:
			if ((get_binding_dtype(expr) & DTYPE_MASK)!=DTYPE_INT && (get_binding_dtype(expr)&DTYPE_MASK)!=DTYPE_SMINT)  {
				A4GL_warn("Unexpected variable - would expect an INTEGER or SMALLINT for WHEN in a CASE with no expression");
			}
			break;



		case ET_EXPR_TRUE:
			A4GL_warn("WHEN is always TRUE"); break;
		case ET_EXPR_FALSE:
			A4GL_warn("WHEN is always FALSE"); break;

		default: break;



	}
  }

  if (has_expr)
    {

      real_print_expr(expr);
      printc ("A4GL_push_char(_s);");
      printc ("A4GL_pushop(OP_EQUAL);\n");

    } else {
  	real_print_expr(expr);
    }

  printc ("if (A4GL_pop_bool()) {\n");
  tmp_ccnt++;
}


char *l_arrvar; char *l_srec; char *l_scroll; char *l_attr;


void print_init_var_from_expr (struct expr_str *v, char *prefix, int alvl,int explicit)
{
//
A4GL_assertion(1,"FIXME");
}

void
print_init_var (struct variable *v, char *prefix, int alvl, int explicit, int PrefixIncludesName, int expand_array, int tonull)
{
  char buff[1000];
  char prefix2[1000];
  strcpy (buff, prefix);
  if (PrefixIncludesName)
    {
      sprintf (prefix2, "%s", prefix);
    }
  else
    {
      sprintf (prefix2, "%s%s", prefix, v->names.names.names_val[0].name);
    }

  int d1;
  int size;
  int a;
  char buff_id[200];


  if (v->arr_subscripts.arr_subscripts_len && expand_array)
    {
      if (v->arr_subscripts.arr_subscripts_val[0] == -1)
	{
	  // dynamic array 
	  if (!explicit)
	    return;
	}

      printc ("{");
      for (a = 0; a < v->arr_subscripts.arr_subscripts_len; a++)
	{

	  SPRINTF2 (buff_id, "_fglcnt_%d_%d", alvl, a);
	  printc ("int %s;\n", buff_id);
	}

      for (a = 0; a < v->arr_subscripts.arr_subscripts_len; a++)
	{
	  SPRINTF2 (buff_id, "_fglcnt_%d_%d", alvl, a);

	  printc ("for (%s=0;%s<%d;%s++) {", buff_id, buff_id, v->arr_subscripts.arr_subscripts_val[a], buff_id);
	  strcat (prefix2, "[");
	  strcat (prefix2, buff_id);
	  strcat (prefix2, "]");
	  tmp_ccnt++;
	}
      alvl++;
    }


  switch (v->var_data.variable_type)
    {
    case VARIABLE_TYPE_CONSTANT:
      // Can't initialize a constant ;-)
      break;
    case VARIABLE_TYPE_TYPE_DECLARATION:
	// Or a type declaration ;-)
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

//printf("tonull=%d\n",tonull);
	if (tonull == 0)
	  {
		switch (d1 & DTYPE_MASK) {
		case DTYPE_INT:
		case DTYPE_SMINT:
			printc ("%s=0;", prefix2);
			break;
		case DTYPE_FLOAT:
		case DTYPE_SMFLOAT:
			printc ("%s=0.0;", prefix2);
			break;

		case DTYPE_DATE:
                        printc ("A4GL_push_today();");
                        printc ("A4GL_pop_var2(&%s,%d,0x%x);\n", prefix2, d1, size);
			break;

		case DTYPE_DTIME:
                        printc ("A4GL_push_current(1,6);");
                        printc ("A4GL_pop_var2(&%s,%d,0x%x);\n", prefix2, d1, size);
			break;
	
		case DTYPE_MONEY:
		case DTYPE_DECIMAL:
                        printc ("A4GL_push_int(0);");
                        printc ("A4GL_pop_var2(&%s,%d,0x%x);\n", prefix2, d1, size);
			break;
		case DTYPE_CHAR:
		case DTYPE_VCHAR:
		case DTYPE_NCHAR:
                        printc ("A4GL_push_char(\" \");");
                        printc ("A4GL_pop_var2(&%s,%d,0x%x);\n", prefix2, d1, size);
			break;

		default : 
			printc ("A4GL_setnull(%d,&%s,0x%x); /*1 */ \n", d1, prefix2, size);
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
			printc ("A4GL_push_int(0);");
			printc ("A4GL_pop_var2(&%s,%d,0x%x);\n", prefix2, d1, size);
		      }
		    else
		      {
			printc ("%s=0.0;", prefix2);
		      }
		  }
	      }
	    else
	      {
		printc ("A4GL_setnull(%d,&%s,0x%x); /*1 */ \n", d1, prefix2, size);
	      }
	  }
      }
      break;

    case VARIABLE_TYPE_RECORD:
      {
	int a;
	strcat (prefix2, ".");
	for (a = 0; a < v->var_data.variable_data_u.v_record.variables.variables_len; a++)
	  {
	    print_init_var (v->var_data.variable_data_u.v_record.variables.variables_val[a], prefix2, alvl, explicit, 0, 1, tonull);
	  }
      }
      break;
	

    case VARIABLE_TYPE_ASSOC:
      {
		struct variable *nextvar;
		nextvar=v->var_data.variable_data_u.v_assoc.variable;
	    print_init_var (nextvar, prefix2, alvl, explicit, 1, 1, tonull);
      }
      break;

    case VARIABLE_TYPE_OBJECT:
      {
		struct variable *nextvar;
		strcat(prefix2,".");
		nextvar=v->var_data.variable_data_u.v_object.definition;
	    	print_init_var (nextvar, prefix2, alvl, explicit, 0, 1, tonull);
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
      printc ("}\n");
    }



}




/**
 * Print in the generated C code the reference to instruction not 
 * implemented yet.
 *
 * @param type A string with the statement that is not implemented
 */
void
print_niy (char *type)
{
  printc ("#error Not Implemented Yet %s", type);
}


void LEXLIB_print_niy(char *type) {
	print_niy(type);
}

/**
 * Generate the C push code of the menu file definition.
 *
 * It is used for the menu extensions to informix 4gl.
 */
void *get_def_mn_file (void) {
	struct expr_str *ptr;
	ptr=A4GL_new_literal_string("menu");

	//ptr=A4GL_new_expr("A4GL_push_char(\"menu\");");
	return ptr;
}


/**
 * If defined (as compiler option) print the C code for the call to the
 * initialization function to the calling stack.
 */
void
printInitFunctionStack (void)
{
  if (!local_isGenStackInfo ())
    return;
  if (!A4GL_doing_pcode ())
    printc ("A4GLSTK_initFunctionCallStack();");
}

/**
 * If defined (as compiler option) print the C code for the call to the
 * declaration function to the calling stack.
 */
void
printDeclareFunctionStack (char *_functionName)
{
#ifdef FGL_PLUS_PLUS
  //extern int class_cnt;
#endif
#ifdef DEBUG
  A4GL_debug ("Function %s\n", _functionName);
#endif

#ifdef FGL_PLUS_PLUS

  
  	if (class_cnt) {
	CLASS_add_method(_functionName,"");
  }
 
#endif
  if (local_isGenStackInfo ())
    {
      if (doing_cs ())
	{
	  printc ("\nstring _functionName = \"%s\";\n", _functionName);
	}
      else
	{
	  printc ("\nstatic char *_functionName = \"%s\";\n", _functionName);
	}
    }
}

/**
 * If defined (as compiler option) print the C code for the call to the
 * push function to the calling stack.
 */
void
printPushFunction (int yylineno)
{
  if (!local_isGenStackInfo ())
    return;
if (A4GL_doing_pcode()) { return;}
  printc ("A4GLSTK_pushFunction(_functionName,_paramnames,_nargs,_module_name,%d);\n",yylineno);
  //printc ("A4GLSTK_setCurrentLine(_module_name,%d);", yylineno);
}

/**
 * Print the C C code to the call to the pop function of the calling stack.
 *
 * It only does it if defined as compiler option.
 */
void
printPopFunction (int nrets,int lineno)
{
  if (!local_isGenStackInfo ())
    return;

if (A4GL_doing_pcode()) { return;}
  printc ("A4GLSTK_popFunction_nl(%d,%d);\n",nrets,lineno);
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
void print_define_char (char *var, int size, int isstatic_extern)
{
  char buff[20];
  strcpy (buff, "");


  if (isstatic_extern == 1)
    {
      strcat (buff, "static ");
    }

  if (isstatic_extern == 2)
    {
      strcat (buff, "extern ");
    }


  if (doing_cs ())
    {
      printc ("%sA4GL_cs_%s;\n", buff, var);
    }
  else
    {
      printc ("%s%s [%d+1];\n", buff, var, size);
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
void print_define (char *varstring, int isstatic_extern)
{
  char buff[20];
  strcpy (buff, "");

  if (isstatic_extern == 1)
    {
      strcat (buff, "static ");
    }

  if (isstatic_extern == 2)
    {
      strcat (buff, "extern ");
    }


  printc ("%s%s ; \n", buff, varstring);
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
void print_start_record (int isstatic_extern, char *varname, char *arrsize, int level)
{
  char buff[20] = "";
/*int n;*/
  if (isstatic_extern == 1)
    strcat (buff, "static ");
  if (isstatic_extern == 2)
    {

      /*
         On Windows, "complex" variables must be explicitly exported, since they cannot be
         auto-imported. dll_import macro is defined in a4gl_incl_4gldef.h


       */
#ifdef __NEED_DLL_IMPORT__
      if (strcmp (varname, "a4gl_sqlca") == 0 && !A4GL_doing_pcode())
	{
	  strcat (buff, "dll_import ");
	}
      else
	{
	  strcat (buff, "extern ");
	}
#else
      strcat (buff, "extern ");
#endif

    }
  if (doing_cs ())
    {
      cs_ticker++;
      if (level)
	{
	  if (arrsize && strcmp (arrsize, "-1") == 0)
	    {
	      printc ("priv_c_%d %s;", cs_ticker, varname);
	    }
	  else
	    {
	      printc ("priv_c_%d %s[]=new priv_c_%d[%s];", cs_ticker, varname,
		      cs_ticker, arrsize);
	    }
	  printc ("%sprivate class priv_c_%s { /* %d */\n", buff, varname,
		  level);
	}
      else
	{
	  printc ("pub_c_%d %s;", cs_ticker, varname);
	  printc ("%spublic class pub_c_%s { /* %d */\n", buff, varname,
		  level);
	}
    }
  else
    {
	if (strcmp(varname,"THIS")!=0) {
      		printc ("%sstruct {\n", buff);
	} else {
      		printc ("%sstruct this_class_var {\n", buff);
	}
    }
}

/**
 * Finishes the declaration of a record.
 *
 * @param vname The record variable name
 * @param arrsize The array size if is a record array
 */
void print_end_record (char *vname, struct variable *v, int level)
{
  //int cnt;
  //int arrsizes[10];
  
  if (v->arr_subscripts.arr_subscripts_len == 0)
    {
      if (doing_cs ())
	{
	  printc ("} ;\n");
	}
      else
	{


	  if (strcmp(vname,"THIS")==0 ) {
	  	printc ("};\n");

	  } else {

	  	printc ("} %s;\n", vname);
	  }
	}
    }
  else
    {
      if (doing_cs ())
	{
	  printc ("} ;\n");
	}
      else
	{
		char buff[2000];
		char smbuff[2000];
		int a;
		strcpy(buff,"");
		for (a=0;a<v->arr_subscripts.arr_subscripts_len;a++) {
			if (a) strcat(buff,"][");
			sprintf(smbuff,"%d",v->arr_subscripts.arr_subscripts_val[a]);
			strcat(buff,smbuff);
		}
	  if (v->arr_subscripts.arr_subscripts_len >= 0 && strcmp(buff,"-1")!=0)
	    {
	      printc ("} %s[%s]; /* 1 */\n", vname, buff);
	    }
	  else
	    {
	      printc ("} *%s;\n", vname); // Dynamic array...
	    }
	}
    }
}


/**
 *
 * @todo Describe function
 */
enum e_dialect esql_type ()
{

  if (strcmp (acl_getenv ("A4GL_LEXDIALECT"), "INFORMIX") == 0)
    {
      return E_DIALECT_INFORMIX;
    }

  if (strcmp (acl_getenv ("A4GL_LEXDIALECT"), "POSTGRES") == 0)
    {
      return E_DIALECT_POSTGRES;
    }

  if (strcmp (acl_getenv ("A4GL_LEXDIALECT"), "SAPDB") == 0)
    {
      return E_DIALECT_SAPDB;
    }

  if (strcmp (acl_getenv ("A4GL_LEXDIALECT"), "INGRES") == 0)
    {
      return E_DIALECT_INGRES;
    }

  if (strcmp (acl_getenv ("A4GL_LEXDIALECT"), "INFOFLEX") == 0)
    {
      return E_DIALECT_INFOFLEX;
    }

  return E_DIALECT_INFORMIX;			/* Assume informix*/
}




/**
 *
 * @todo Describe function
 */
void
A4GL_lex_parsed_fgl ()
{
  if (strcmp (acl_getenv ("LEXTYPE"), "CS") == 0)
    {
      printc ("#include \"cs_trailer.h\"");
    }
  if (outfile) {
  	fprintf(outfile,"/* END OF MODULE */\n");
    	fclose (outfile);
    }
  if (hfile)
    fclose (hfile);

  merge_files();
}

void
print_import_legacy (char *s)
{
  printc ("\n");
  printc ("\n");
  printc ("\n\nA4GL_FUNCTION int %s%s(int n) {\nreturn %s(n);\n}\n", get_namespace (s), s, s);
  printc ("\n");
  printc ("\n");
}


void
add_function_to_header (char *identifier, char *namespace, int params,int is_static)
{

  if (is_builtin_func (identifier))
    return;


  if (!A4GL_has_pointer (identifier, FEATURE_USED))
    {
      A4GL_add_pointer (identifier, FEATURE_USED, (void *) 1);

      if (params == 1)		/* Normal Function*/ {
		printh ("A4GL_FUNCTION%s int %s%s (int n);\n",is_static?" static":"", namespace , identifier);

      }

      if (params == 2)		/* Report...*/
	printh ("A4GL_REPORT%s void %s%s (int n,int a);\n", is_static?" static":"", namespace, identifier);
    }


}

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


void
print_realloc_arr (char *s, char *d)
{
  char *ptr;
  int a;
  int l;
  int dim[5] = { 0, 0, 0, 0, 0 };
  int dimcnt = 0;
  l = strlen (d);
  ptr = d;
  for (a = 0; a < l; a++)
    {
      if (d[a] == '(' && a == 0)
	{
	  ptr = &d[a + 1];
	  continue;
	}

      if (d[a] == '[' && d[a + 1] == '(')
	{
	  ptr = &d[a + 2];
	  continue;
	}

      if (d[a] == ')' && d[a + 1] == '-' && d[a + 2] == '1'
	  && d[a + 3] == ']')
	{
	  d[a] = 0;
	  a += 3;
	  dim[dimcnt++] = atoi (ptr);

	}
    }
  printc ("/* ALLOC ARR %s -> %d %d %d */", s, dim[0], dim[1], dim[2]);
  if (dim[4] == 0)
    {
      dim[4] = 1;
    }
  if (dim[3] == 0)
    {
      dim[3] = 1;
    }
  if (dim[2] == 0)
    {
      dim[2] = 1;
    }
  if (dim[1] == 0)
    {
      dim[1] = 1;
    }
  if (dim[0] == 0)
    {
      dim[0] = 1;
    }
  l = dim[0] * dim[1] * dim[2] * dim[3] * dim[4];
  printc ("%s=A4GL_alloc_dynarr(&%s,%s,%d,%d,%d,%d,%d,%d * sizeof(%s[0]),1);", s,s, s,dim[0],dim[1],dim[2],dim[3],dim[4],l, s);
}





void print_event_actions (char *loopvar, struct on_events*events) {
  int a;
  int n;
  if (events==0) return;
  n = events->event.event_len;
  if (n==0) return ;
  for (a = 0; a < n; a++)
    {
	struct on_event *evt;
        evt = events->event.event_val[a];


	switch (events->event.event_val[a]->evt_data.event_type) {
      		default: 
			dump_comments(evt->lineno);
			printc("if (_exec_block==%d) {",a+1);
			tmp_ccnt++;
			dump_commands(evt->on_event_commands);

	if (current_cmd->cmd_data.type==E_CMD_PROMPT_CMD && events->event.event_val[a]->evt_data.event_type==EVENT_KEY_PRESS ) {
		// Special handling of an ON KEY in a prompt - it'll also exit the prompt...
		printc ("SET(\"s_prompt\",_sio_%d,\"mode\",1);\n",current_cmd->cmd_data.command_data_u.prompt_cmd.sio);
	}

	if (current_cmd->cmd_data.type==E_CMD_INPUT_ARRAY_CMD) {
			printc ("_fld_dr= -1;_exec_block= -1;\n");
	}

			tmp_ccnt--;
			printc("}");

	}

   }
}



void
print_event_list (struct on_events*events)
{
  int a;
  int n;
  int b;
  //int event_id;
  //char *event_dets;
  int *keys;
//char comma=' ';
  //char **fields;

  if (events==0) n=0; 
  else {
  	n = events->event.event_len;
  }


  if (n == 0)
    {
      if (A4GL_doing_pcode ())
	{
	  printc ("struct aclfgl_event_list _sio_evt[1]={");
	}
      else
	{
	  printc ("static struct aclfgl_event_list _sio_evt[]={");
	}

  	if (current_cmd->cmd_data.type==E_CMD_DISPLAY_ARRAY_CMD) {
		printc("{-94,1,0,\"\"},"); /* EVENT_AFTER_INP_CLEAN */
	}
  	if (current_cmd->cmd_data.type==E_CMD_INPUT_CMD|| current_cmd->cmd_data.type==E_CMD_CONSTRUCT_CMD ||  current_cmd->cmd_data.type==E_CMD_INPUT_ARRAY_CMD) {
		printc("{-94,1,0,\"\"},"); /* EVENT_AFTER_INP_CLEAN */
	}
      printc (" {0}};");
      return;
    }





  if (A4GL_doing_pcode ())
    {
      printc ("struct aclfgl_event_list _sio_evt[%d]={", n+1);
    }
  else
    {
      printc ("static struct aclfgl_event_list _sio_evt[]={");
    }

  for (a = 0; a < n; a++)
    {
	  struct on_event *evt;
          evt = events->event.event_val[a];
        //A4GL_get_event (a, &event_id, &event_dets);
	switch (events->event.event_val[a]->evt_data.event_type) {
	
      		case EVENT_KEY_PRESS: 
			{
	  		int c;
	  		for (c=0;c<evt->evt_data.event_data_u.key->str_list_entry.str_list_entry_len;c++) {
	  			keys = get_key_codes (evt->evt_data.event_data_u.key->str_list_entry.str_list_entry_val[c]);
	  			for (b = 0; keys[b]; b++)
	    			{
					if (keys[b]==-1) { 	// Invalid key code...
						set_yytext(evt->evt_data.event_data_u.key->str_list_entry.str_list_entry_val[c]);
						a4gl_yyerror("Invalid Key");
					}
	      				printc ("{%d,%d,%d,NULL},", A4GL_EVENT_KEY_PRESS , a + 1, keys[b]);
	    			}
	   		}
			}
	  		break;

     		case EVENT_ON_IDLE:
			{
	    		printh("static long a4gl_idle%d=0;\n",idle_cnt);
	    		printc ("{%d,%d,%d,(void *)&a4gl_idle%d},", A4GL_EVENT_ON_IDLE, a + 1, evt->evt_data.event_data_u.idle_n,idle_cnt++);
	    		break;
			}

      		case EVENT_ON_INTERVAL: 
			{
	    		printh("static long a4gl_idle%d=0;\n",idle_cnt);
	    		printc ("{%d,%d,%d,(void *)&a4gl_idle%d},", A4GL_EVENT_ON_INTERVAL, a + 1, evt->evt_data.event_data_u.interval_n ,idle_cnt++);
	    		break;
			}

        	case EVENT_BEF_ROW: 
	    		printc ("{%d,%d,0,NULL},", A4GL_EVENT_BEF_ROW, a + 1 );
			break;

        	case EVENT_AFT_ROW: 
	    		printc ("{%d,%d,0,NULL},", A4GL_EVENT_AFT_ROW, a + 1 );
			break;

        	case EVENT_BEFORE_DELETE: 
	    		printc ("{%d,%d,0,NULL},", A4GL_EVENT_BEFORE_DELETE, a + 1 );
			break;
        	case EVENT_AFTER_DELETE: 
	    		printc ("{%d,%d,0,NULL},", A4GL_EVENT_AFTER_DELETE, a + 1 );
			break;
        	case EVENT_BEFORE_INSERT: 
	    		printc ("{%d,%d,0,NULL},", A4GL_EVENT_BEFORE_INSERT, a + 1 );
			break;
        	case EVENT_AFTER_INSERT: 
	    		printc ("{%d,%d,0,NULL},", A4GL_EVENT_AFTER_INSERT, a + 1 );
			break;
        	case EVENT_BEFORE_INSERT_DELETE: 
	    		printc ("{%d,%d,0,NULL},", A4GL_EVENT_BEF_INSERT_DELETE, a + 1 );
			break;
        	case EVENT_AFTER_INSERT_DELETE: 
	    		printc ("{%d,%d,0,NULL},", A4GL_EVENT_AFT_INSERT_DELETE, a + 1 );
			break;


        	case EVENT_MENU_COMMAND: 
        	case EVENT_BEFORE_MENU: 
			A4GL_assertion(1,"Menu events are handled in the print_menu");
			break;


        	case EVENT_BEFORE_INPUT: 
        	case EVENT_BEFORE_DISPLAY: 
        	case EVENT_BEFORE_CONSTRUCT: 
	    		printc ("{%d,%d,0,NULL},", A4GL_EVENT_BEFORE_INP, a + 1 );
			break;

        	case EVENT_AFTER_DISPLAY: 
        	case EVENT_AFTER_CONSTRUCT: 
        	case EVENT_AFTER_INPUT: 	
	    		printc ("{%d,%d,0,NULL},", A4GL_EVENT_AFTER_INP, a + 1 );
			break;
			

        	case EVENT_ON_ACTION: //str on_action; //A4GL_EVENT_ON_ACTION
	    		printc ("{%d,%d,0,\"%s\"}, //", A4GL_EVENT_ON_ACTION, a + 1 ,  evt->evt_data.event_data_u.on_action);
			break;
			

		// Form handler events
        	case EVENT_BEFORE: //str_list *before;
        	case EVENT_AFTER: //str_list *after;
        	case EVENT_BEFORE_ANY: 
        	case EVENT_AFTER_ANY: 
        	case EVENT_BEFORE_CLOSE_FORM: 
        	case EVENT_AFTER_EVENT: 
        	case EVENT_BEFORE_EVENT:
        	case EVENT_BEFORE_OPEN_FORM: 
        	case EVENT_ON: 
			/* these are handled differently */
			break;



        case EVENT_ON_TIME: //int time_n;
		A4GL_assertion(1,"Not handled yet");
		break;

        case EVENT_BEFORE_FIELD: //struct fh_field_list *before_field;
			{
			int b;
			for(b=0;b<evt->evt_data.event_data_u.before_field->field_list_entries.field_list_entries_len;b++) {
				printc ("{%d,%d,0,%s},", A4GL_EVENT_BEFORE_FIELD, a + 1, local_expr_as_string(evt->evt_data.event_data_u.before_field->field_list_entries.field_list_entries_val[b].field));
			}
			}
			break;
        case EVENT_AFTER_FIELD: //struct fh_field_list *after_field;
			{
			int b;
			for(b=0;b<evt->evt_data.event_data_u.before_field->field_list_entries.field_list_entries_len;b++) {
				printc ("{%d,%d,0,%s},", A4GL_EVENT_AFTER_FIELD, a + 1, local_expr_as_string(evt->evt_data.event_data_u.before_field->field_list_entries.field_list_entries_val[b].field));
			}
			}
			break;

	default:
        	//case EVENT_ANYKEY_PRESS: 
        	//case EVENT_AFTER_INP_CLEAN: 
			A4GL_assertion(1,"UNHANDLED EVENT TYPE");
			break;


	/*
      		fields = get_field_codes (event_dets);
      		for (b = 0; fields[b]; b++)
			{
	  		if (strlen (fields[b]) != 0)
	    		{
	      		printc ("{%d,%d,0,%s},", event_id, a + 1, fields[b]);
	    		}
	  		else
	    		{
	      				printc ("{%d,%d,0,\"\"},", event_id, a + 1);
	    		}
			}
    		}
	*/
	}
   }

  if (current_cmd->cmd_data.type==E_CMD_DISPLAY_ARRAY_CMD) {
		printc("{-94,%d,0,\"\"},",n+1); /* EVENT_AFTER_INP_CLEAN */
  }
 if (current_cmd->cmd_data.type==E_CMD_INPUT_CMD|| current_cmd->cmd_data.type==E_CMD_CONSTRUCT_CMD ||  current_cmd->cmd_data.type==E_CMD_INPUT_ARRAY_CMD) {
		printc("{-94,%d,0,\"\"},",n+1); /* EVENT_AFTER_INP_CLEAN */
  }

  printc ("{0}");
  printc ("};");
}


int *get_key_codes(char *keys) {
char s[1024];
char *k;
char *k1;
static int *x=0;
int xcnt=0;

if (x) {free(x);x=0;}

  strcpy (s, keys);
  A4GL_trim(s);
  strcat (s, "||");
  A4GL_debug ("Chk keys %s\n", s);

  if (strcmp (keys, "->ANY") == 0) { x=acl_malloc2(sizeof(int)*2); x[0]=0xffff; x[1]=0; return x;}

  k=s;

  while (1) {
  	k1=k;
  	k = strstr (k1, "||");
	if (k==0) break;
  	*k=0;
	k+=2;
	xcnt++;
	x=realloc(x,sizeof(int)*xcnt);
	x[xcnt-1]= A4GL_key_val (k1);
  }
	

	xcnt++;
	x=realloc(x,sizeof(int)*xcnt);
	x[xcnt-1]= 0;
  return x;
}


char **get_field_codes(char *fields) {
char s[10240];
char *k;
char *k1;
static char **x=0;
char *p;
int xcnt=0;

if (x) {free(x);x=0;}

  strcpy (s, fields);
  A4GL_trim(s);
  strcat (s, "||");
  k=s;

  while (1) {
  	k1=k;
  	k = strstr (k1, "||");
	if (k==0) break;
  	*k=0;
	k+=2;
	xcnt++;
	x=realloc(x,sizeof(char *)*xcnt);
	p=strchr(k1,',');
	if (p) *p=0;
	x[xcnt-1]= strdup(k1);
  }
	

	xcnt++;
	x=realloc(x,sizeof(char *)*xcnt);
	x[xcnt-1]= 0;
  return x;
}



/**
 * Print the declaration of bind structure array in the generated C source code
 * and its initialization values.
 *
 * @param i The binding type:
 *   i : Use the array ibind.
 *   N : Null binding.
 *   o : Use the array obind.
 *   O : Use the array ordbind.
 */
int print_bind_definition_g (struct expr_str_list *l,char i )
{

	switch (i) {
		case 'i': return print_bind_dir_definition_g(l,0,i);
		case 'o': return print_bind_dir_definition_g(l,0,i); 
		case 'O': return print_bind_dir_definition_g(l,0,i); 
		case 'N': return print_bind_dir_definition_g(l,0,i); 
		case 'e': return print_bind_dir_definition_g(l,0,i); 
		case 'r': return print_bind_dir_definition_g(l,0,i); 
		default : A4GL_assertion(1,"Unhandled print_bind_definition");
	}
	return -1;
}



int
print_bind_dir_definition_g (struct expr_str_list *lbind, int ignore_esql, char lbind_type)
{
  int a;
  struct expr_str_list empty;
  empty.list.list_len = 0;
  empty.list.list_val = 0;
  if (lbind == 0)
    {
      lbind = &empty;
    }

  set_suppress_lines ();
#ifdef DEBUG
  A4GL_debug ("/* %c */\n", i);
#endif
  if (lbind_type == 'i' || lbind_type == 'o' || lbind_type == 'O' || lbind_type == 'N' || lbind_type == 'e' || lbind_type=='r')

    {
      printc ("\n");
      switch (lbind_type)
	{
	case 'i':
	  printc ("static struct BINDING ibind[%d]={\n ", ONE_NOT_ZERO (lbind->list.list_len));
	  break;
	case 'o':
	  printc ("static struct BINDING obind[%d]={\n ", ONE_NOT_ZERO (lbind->list.list_len));
	  break;
	case 'e':
	  printc ("struct BINDING ebind[%d]={\n ", ONE_NOT_ZERO (lbind->list.list_len));
	  break;

	case 'r':
		// Its already printed - we're just calling this function to print out the native binding stuff...
	  break;

	case 'O':
	  printc ("static struct BINDING _ordbind[%d]={\n", ONE_NOT_ZERO (lbind->list.list_len));
	  break;
	case 'N':
	  printc ("struct BINDING nullbind[%d]={\n", ONE_NOT_ZERO (lbind->list.list_len));
	  break;
	}


	if (lbind_type!='r') {
      if (lbind->list.list_len == 0)

	{
	  printc ("{NULL,0,0,0,0,0}");
	}

      for (a = 0; a < lbind->list.list_len; a++)

	{
	  if (lbind_type == 'N')
	    {
	      // chk_init_var (lbind->list.list_val[a].varname);
	      A4GL_assertion (1, "check_initvar was previously called");
	      printc ("{NULL,%d,%d,0,0,0}%c", (int) get_binding_dtype (lbind->list.list_val[a]) & 0xffff,
		      (int) get_binding_dtype (lbind->list.list_val[a]) >> 16, (a < lbind->list.list_len - 1) ? ',' : ' ');
	    }
	  else
	    {

	      printc ("{NULL,%d,%d,0,0,0}%c",
		      (int) get_binding_dtype (lbind->list.list_val[a]) & 0xffff,
		      (int) get_binding_dtype (lbind->list.list_val[a]) >> 16,
		/*
		      get_start_char_subscript (lbind->list.list_val[a]),
		      get_end_char_subscript (lbind->list.list_val[a]), 
		*/
			(a < lbind->list.list_len - 1) ? ',' : ' ');
	}} printc ("\n}; \n");


      if (lbind_type == 'O')
	{
	  current_ordbindcnt = lbind->list.list_len;
	}
	}
      clr_suppress_lines ();


      if (lbind_type != 'N')
	{
	  if (doing_esql () && !ignore_esql)

	    {
	      char *ptr;
	      set_suppress_lines ();
	      ptr = make_sql_bind_g (lbind, lbind_type);

	      if (last_print_bind_dir_definition_g_rval[(int)lbind_type])
		free (last_print_bind_dir_definition_g_rval[(int)lbind_type]);
	      if (ptr)
		{
		  last_print_bind_dir_definition_g_rval[(int)lbind_type] = strdup (ptr);
		}
	      else
		{
		  last_print_bind_dir_definition_g_rval[(int)lbind_type] = 0;
		}
	      clr_suppress_lines ();
	    }
	}
      //A4GL_assertion (lbind->str==0, "string is empty");
      return a;
    }

  printf ("UNEXPECTED BINDING %c\n", lbind_type);
  A4GL_assertion (1, "Unexpected binding");
  exit (3);
  return 0;
}



int local_print_bind_set_value_g (struct expr_str_list *bind,int ignore_esqlc,int only_native, char type)
{
  int a;
  struct expr_str_list empty;
	char *start_chr;
	char *end_chr;
  empty.list.list_len=0;
  empty.list.list_val=0;
  if (bind==0) {
	bind=&empty;
  }

#ifdef DEBUG
  A4GL_debug ("/* %c */\n", i);
#endif

  if (type == 'i')
    {
      for (a = 0; a < bind->list.list_len; a++)
        {
	if (!ignore_esqlc && doing_esql()) {
          printc ("native_binding_i[%d].ptr= &_vi_%d; ", a,a);
          if (A4GLSQLCV_check_requirement ("USE_INDICATOR")) {
                printc ("native_binding_i_ind[%d].ptr= &_vii_%d; ", a,a);
          }
	}
	if (only_native) continue;
	switch(bind->list.list_val[a]->expr_type) {

			case ET_EXPR_VARIABLE_USAGE_WITH_ASC_DESC:
				set_nonewlines();
          			printc ("ibind[%d].ptr=&", a);
				print_variable_usage_for_bind(bind->list.list_val[a]);
				printc(";");
				clr_nonewlines();
		      		start_chr=get_start_char_subscript (bind->list.list_val[a]);
				if (start_chr && strcmp(start_chr,"0")!=0) {
					printc("ibind[%d].start_char_subscript=%s;\n", a, start_chr);
				}
		      		end_chr=get_end_char_subscript (bind->list.list_val[a]); 
				if (end_chr && strcmp(end_chr,"0")!=0) {
					printc("ibind[%d].end_char_subscript=%s;\n", a, end_chr);
				}


				break;

			case ET_EXPR_VARIABLE_USAGE: 
				set_nonewlines();
          			printc ("ibind[%d].ptr=&",a);
				print_variable_usage_for_bind(bind->list.list_val[a]);
				printc(";");
				clr_nonewlines();

		      		start_chr=get_start_char_subscript (bind->list.list_val[a]);
				if (start_chr && strcmp(start_chr,"0")!=0) {
					printc("ibind[%d].start_char_subscript=%s;\n", a, start_chr);
				}
		      		end_chr=get_end_char_subscript (bind->list.list_val[a]); 
				if (end_chr && strcmp(end_chr,"0")!=0) {
					printc("ibind[%d].end_char_subscript=%s;\n", a, end_chr);
				}

				break;

			case ET_EXPR_LITERAL_EMPTY_STRING:
				printh("static char a4gl_putval_%d[]=\"\"; // ****\n",putvalcnt);
          			printc ("ibind[%d].ptr= &a4gl_putval_%d;", a, putvalcnt);
				putvalcnt++;
				break;

			case ET_EXPR_LITERAL_STRING:
				printh("static char a4gl_putval_%d[]=%s; // ****\n",putvalcnt, local_expr_as_string(bind->list.list_val[a]));
          			printc ("ibind[%d].ptr= &a4gl_putval_%d;", a, putvalcnt);
				putvalcnt++;
				break;

			case ET_EXPR_LITERAL_LONG:
				printh("static int a4gl_putval_%d=%s; // ****\n",putvalcnt, local_expr_as_string(bind->list.list_val[a]));
          			printc ("ibind[%d].ptr= &a4gl_putval_%d;", a, putvalcnt);
				putvalcnt++;
				break;

			case ET_EXPR_NULL:
				printh("static char a4gl_putval_%d[2]=\" \";\n",putvalcnt);
				printc("A4GL_setnull(0,&a4gl_putval_%d,1);", putvalcnt);
          			printc ("ibind[%d].ptr= &a4gl_putval_%d;", a, putvalcnt);
				putvalcnt++;
				break;
			default:
				A4GL_assertion(1,"Internal error - Unexpected expression type");
			
	}
        }
      return a;
    }


  if (type == 'o' || type=='r')
    {
      for (a = 0; a < bind->list.list_len; a++)
        {
	if (!ignore_esqlc && doing_esql()) {
          printc ("native_binding_o[%d].ptr= &_vo_%d; ", a,a);
          if (A4GLSQLCV_check_requirement ("USE_INDICATOR")) {
                printc ("native_binding_o_ind[%d].ptr= &_voi_%d; _voi_%d= -2; ", a,a,a);
          }
	
	}
	if (only_native) continue;

	if (type=='o') {
	set_nonewlines();
          printc ("obind[%d].ptr= & ", a);
		print_variable_usage_for_bind(bind->list.list_val[a]);
		printc(";");
	clr_nonewlines();
	}

          if (doing_esql()) {
                if ((get_binding_dtype(bind->list.list_val[a])&DTYPE_MASK)==DTYPE_BYTE) {
			if (type=='o') {
                        	printc("A4GL_init_out_byte(obind[%d].ptr,native_binding_o[%d].ptr);",a,a);
			} else {
                        	printc("A4GL_init_out_byte(obind_dup[%d].ptr,native_binding_o[%d].ptr);",a,a);
			}
                }
                if ((get_binding_dtype(bind->list.list_val[a])&DTYPE_MASK)==DTYPE_TEXT) {
			if (type=='o') {
                        printc("A4GL_init_out_text(obind[%d].ptr,native_binding_o[%d].ptr);",a,a);
			} else {
                        printc("A4GL_init_out_text(obind_dup[%d].ptr,native_binding_o[%d].ptr);",a,a);
			}
                }
          }
        }
      return a;
    }





  if (type == 'O')
    {
      for (a = 0; a < bind->list.list_len; a++)
        {
	set_nonewlines();
          printc ("_ordbind[%d].ptr=&", a);
		print_variable_usage_for_bind(bind->list.list_val[a]);
		printc(";");
	clr_nonewlines();
        }
      return a;
    }


  if (type == 'r')
    {
      for (a = 0; a < bind->list.list_len; a++)
        {
		set_nonewlines();
          	printc ("obind_dup[%d].ptr=&", a);
		print_variable_usage_for_bind(bind->list.list_val[a]);
		printc(";");
		clr_nonewlines();
        }
      return a;
    }



  if (type == 'N')
    {
      for (a = 0; a < bind->list.list_len; a++)
        {
	set_nonewlines();
          printc ("nullbind[%d].ptr=&", a);
		print_variable_usage_for_bind(bind->list.list_val[a]);
		printc(";");
	clr_nonewlines();
        }
      return a;
    }

  if (type == 'e')
    {
      for (a = 0; a < bind->list.list_len; a++)
        {
	set_nonewlines();
          printc ("ebind[%d].ptr=&", a);
		print_variable_usage_for_bind(bind->list.list_val[a]);
		printc(";");
	clr_nonewlines();
        }
      return a;
    }

printf("BINDTYPE=%c\n",type);
A4GL_assertion(1,"Invalid bindtype");
  return 0;
}


int print_bind_set_value_g (struct expr_str_list *bind,char type) {
	return local_print_bind_set_value_g(bind,0,0, type);
}

char* get_reset_state_after_call(int n ) {
       static char buff[255];
int a;
n++;
   for (a=parent_stack_cnt-n;a>=0;a--) {
		int sio_id;
		switch  (parent_stack[a]->cmd_data.type) {
			case E_CMD_DISPLAY_ARRAY_CMD:
				sio_id=parent_stack[a]->cmd_data.command_data_u.display_array_cmd.sio;
               			SPRINTF2(buff, "{char *_p; _p=A4GL_get_currwin_name(); A4GL_ensure_current_window_is(_curr_win); A4GL_reset_state_for(&_sio_%d,_sio_kw_%d);  A4GL_ensure_current_window_is(_p);}",sio_id,sio_id);
               			return buff;

			case E_CMD_INPUT_ARRAY_CMD:
				sio_id=parent_stack[a]->cmd_data.command_data_u.input_array_cmd.sio;
               			SPRINTF2(buff, "{char *_p; _p=A4GL_get_currwin_name(); A4GL_ensure_current_window_is(_curr_win); A4GL_reset_state_for(&_sio_%d,_sio_kw_%d);  A4GL_ensure_current_window_is(_p);}",sio_id,sio_id);
               			return buff;

			case E_CMD_INPUT_CMD:
				sio_id=parent_stack[a]->cmd_data.command_data_u.input_cmd.sio;
               			SPRINTF2(buff, "{char *_p; _p=A4GL_get_currwin_name(); A4GL_ensure_current_window_is(_curr_win); A4GL_reset_state_for(&_sio_%d,_sio_kw_%d);  A4GL_ensure_current_window_is(_p);}",sio_id,sio_id);
               			return buff;

			case E_CMD_CONSTRUCT_CMD:
				sio_id=parent_stack[a]->cmd_data.command_data_u.construct_cmd.sio;
               			SPRINTF2(buff, "{char *_p; _p=A4GL_get_currwin_name(); A4GL_ensure_current_window_is(_curr_win); A4GL_reset_state_for(&_sio_%d,_sio_kw_%d);  A4GL_ensure_current_window_is(_p);}",sio_id,sio_id);
               			return buff;
			default: break;  // the switch anyway, Keep going through the while - there might be something else...

		}
	
   }
/*
   if (isin_command ("INPUT")  || isin_command ("CONSTRUCT")||isin_command ("DISPLAY")) {
       int sio_id;
               sio_id=get_sio_ids("ALL");
	
   }
*/
   return "";
}


void print_reset_state_after_call(int n) {
       printc("%s",get_reset_state_after_call(n));
}



void print_convert_report_via(char *repname,char *fname) {
	add_function_to_header(fname,"namespace", 1,0);
	printc("A4GL_via_functionname(\"%s\",&%s%s,&%s%s);",repname,get_namespace(repname),repname,get_namespace(fname),fname);
}


void print_convert_report(char *repname, char* fname,char *otype, char *layout,char *file_or_pipe) {

	if (strcmp(file_or_pipe,"EMAIL")==0) {	
		printc("A4GL_push_int(2);");
	} else {
		if (strcmp(file_or_pipe,"PIPE")==0) {	
			printc("A4GL_push_int(1);");
		} else {
			printc("A4GL_push_int(0);");
		}
	}
	printc("A4GL_push_char(%s);A4GL_push_char(%s);A4GL_push_char(%s);%s%s(3,REPORT_CONVERT);",fname,otype,layout,get_namespace (repname),repname);
}

void print_free_convertible(char *repname) {
	printc("%s%s(3,REPORT_FREE);", get_namespace (repname),repname);
}


/**
 * Generate in the C output file the implementation of the IMPORT FUNCTION
 * statement.
 *
 * This statement is not a informix 4gl original.
 *
 * @param func The function name to be imported.
 * @param nargs The number of arguments that the function imported receive.
 */
void
print_import (char *func, int nargs,int yylineno)
{
  int a;
  char buff[1024];
  char buff2[1024];
  printc ("\n\nA4GL_FUNCTION %s%s (int _nargs) {\n", get_namespace (func),
	  func);
  printc ("long _argc[%d];\n", nargs);
  printc ("long _retval;");
  printc ("   if (_nargs!=%d) {A4GLSQL_set_status(-3002,0);A4GL_pop_args(_nargs);return -1;}\n", nargs);
  for (a = 1; a <= nargs; a++)
    {
      printc ("   _argc[%d]=A4GL_pop_long();\n", nargs - a);
    }
  SPRINTF1 (buff, "_retval=(long)%s(", func);
  for (a = 0; a <= nargs - 1; a++)
    {
      if (a > 0)
	strcat (buff, ",");
      SPRINTF1 (buff2, "_argc[%d]", a);
      strcat (buff, buff2);
    }
  strcat (buff, ");\n   A4GL_push_int(_retval);\n   return 1;\n");
  strcat (buff, "}\n\n\n");
  printc ("%s",buff);
}

char *pdtype(int n) {
	static char buff[40];
	switch (n&DTYPE_MASK) {
		case DTYPE_CHAR: return "String";
		case DTYPE_SMINT: return "short";
		case DTYPE_SERIAL: 
		case DTYPE_INT: return "long";
		case DTYPE_DATE: return "Date";
		case DTYPE_SMFLOAT: return "float";
		case DTYPE_FLOAT: return "double";
		case DTYPE_INT8: return "int8";
	}
	SPRINTF1(buff,"DTYPE_%x",n);
	return buff;
}












void print_nullify (char type, variable_list * v)
{
  int a;
  //printf ("print_nullify called :%c\n", type);
  A4GL_debug ("AUTONULL ?");

  printc ("/* Print nullify */\n");

  a = A4GL_isyes (acl_getenv ("AUTONULL"));
  A4GL_debug ("isyes returns %d ", a);

  if (!a)
    return;

  if (v->variables.variables_len == 0)
    return;

  if (v->variables.variables_val == 0)
    return;

  for (a = 0; a < v->variables.variables_len; a++)
    {
      char *name;
      //int print = 0;
      name = v->variables.variables_val[a]->names.names.names_val[0].name;

      //if (v->variables.variables_val[a]->var_data.variable_type == VARIABLE_TYPE_SIMPLE)
        //{
          print_init_var ( v->variables.variables_val[a], "", 0, 0,0,1,1);
          //continue;
        //}

      //if (v->variables.variables_val[a]->var_data.variable_type == VARIABLE_TYPE_RECORD)
        //{
          //print_init_record (name, v->variables.variables_val[a]);
	//
        //}

    }

}




void print_Constant_1 (char *name, struct constant_data *c)
{
  if (c->consttype == CONST_TYPE_CHAR)
    {
      print_Constant (1, name);
    }
  if (c->consttype == CONST_TYPE_FLOAT)
    {
      print_Constant (2, name);
    }
  if (c->consttype == CONST_TYPE_INTEGER)
    {
      print_Constant (3, name);
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
              strcat (s, "][");
            }
          SPRINTF1 (buff, "%d", v->arr_subscripts.arr_subscripts_val[a]);
          strcat (s, buff);
    }
}


static char *
local_rettype_integer (int n)
{
  char s[200];


  SPRINTF1 (s, "%d", n );
  return local_rettype (s);
}


/******************************************************************************/
void
print_variable_new (struct variable *v, enum e_scope scope, int level)
{
  int static_extern_flg;
  char arrbuff[256];
  char name[256];
  static_extern_flg = 0;
      if (level==0 && local_is_system_variable (v)&&(strcmp(acl_getenv("A4GL_LEXTYPE"),"CM")==0 )) {
	      // Ignore all system variables
	      return ;
      }

set_suppress_lines();

  strcpy (arrbuff, "-1");
  /* are we dealing with the sqlca variable ?*/
	A4GL_debug("v->names.name=%s",v->names.names.names_val[0].name);
  if (level == 0 && strcmp (v->names.names.names_val[0].name, "sqlca") == 0)
    {
#ifdef DEBUG
      A4GL_debug ("SQLCA!!!\n");
#endif
      if (strcmp (acl_getenv ("A4GL_LEXTYPE"), "EC") == 0)
	{
clr_suppress_lines();
	  return;
	}
    }

    if (local_bad_identifiers(v->names.names.names_val[0].name)) {
		yylineno=v->lineno;

		set_yytext(v->names.names.names_val[0].name);
                a4gl_yyerror("You can't use this identifier as it is a reserved word in the target language");
		return;
    }


  if (scope == E_SCOPE_IMPORTED_GLOBAL && level == 0) {
	int skip=0;
	if (strcasecmp (v->names.names.names_val[0].name, "time") == 0 ) skip++; 
	if (strcasecmp (v->names.names.names_val[0].name, "pageno") == 0 ) skip++; 
	if (strcasecmp (v->names.names.names_val[0].name, "lineno") == 0 ) skip++; 
	if (strcasecmp (v->names.names.names_val[0].name, "today") == 0 ) skip++; 
	if (strcasecmp (v->names.names.names_val[0].name, "usrtime") == 0 ) skip++; 
	if (strcasecmp (v->names.names.names_val[0].name, "fgl_user") == 0 ) skip++; 
	if (strcasecmp (v->names.names.names_val[0].name, "curr_file_name") == 0 ) skip++; 
	if (strcasecmp (v->names.names.names_val[0].name, "curr_line_no") == 0 ) skip++; 

	if (skip) {
		clr_suppress_lines();
      		return;
	}
    }


  if (v->arr_subscripts.arr_subscripts_len )
    {
      make_arr_str (arrbuff, v);
    }
  else
    {
      strcpy (arrbuff, "-1");
    }




  if (level == 0)		/* We only print 'static' or 'extern' at the start of a record/variable - not a nested record*/
    {
      if (scope == E_SCOPE_IMPORTED_GLOBAL )
	{
	  static_extern_flg += 2;
	}

      if (scope == E_SCOPE_MODULE)
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
  if (level == 0 && (A4GL_isyes (acl_getenv ("MARK_SCOPE"))|| A4GL_isyes (acl_getenv ("MARK_SCOPE_MODULE")))  )
    {
      /*printf("%s %c %c %c\n",name,v->user_system,v->scope,scope);*/
      if (local_is_system_variable (v));
      else
	{
	  if (v->escope == E_SCOPE_IMPORTED_GLOBAL || v->escope == E_SCOPE_EXPORTED_GLOBAL)
	    {
	      SPRINTF1 (name, "G_%s", v->names.names.names_val[0].name);
	    }

	  if (v->escope == E_SCOPE_MODULE)
	    {
		if (A4GL_isyes (acl_getenv ("MARK_SCOPE_MODULE"))) {	
	      		SPRINTF2 (name, "M_%s_%s", get_current_module_name_clean(),v->names.names.names_val[0].name);
		} else {
	      		SPRINTF1 (name, "M_%s", v->names.names.names_val[0].name);
		}
	    }
	  if (v->escope == E_SCOPE_LOCAL)
	    {
	      SPRINTF1 (name, "L_%s", v->names.names.names_val[0].name);
	    }
	}
    }


  if (v->arr_subscripts.arr_subscripts_len ) {
		if (v->arr_subscripts.arr_subscripts_val[0]==-1) { // Dynamic array
			struct variable *nv;
			nv=v;
			if (nv->var_data.variable_type==VARIABLE_TYPE_OBJECT) {
				nv=nv->var_data.variable_data_u.v_object.definition;
			}

		switch (nv->var_data.variable_type) {
			case VARIABLE_TYPE_SIMPLE:
      				if (nv->var_data.variable_data_u.v_simple.datatype == DTYPE_CHAR || nv->var_data.variable_data_u.v_simple.datatype==DTYPE_VCHAR || nv->var_data.variable_data_u.v_simple.datatype==DTYPE_NCHAR ) {
					printc("struct _dynelem_%s { char dummyname[%d];};", name,nv->var_data.variable_data_u.v_simple.dimensions[0]+1);
					printc("char **%s=0;",name);
				} else {
					printc("struct _dynelem_%s { %s dummyname;};", name, local_rettype_integer (nv->var_data.variable_data_u.v_simple.datatype));
					printc("%s *%s=0;",local_rettype_integer (nv->var_data.variable_data_u.v_simple.datatype),name);
				}
				break;
				
			case VARIABLE_TYPE_RECORD:
			{
			int a;
			printc("struct _dynelem_%s {",name);
      			for (a = 0; a < nv->var_data.variable_data_u.v_record.variables.variables_len; a++) {
	  		struct variable *next_v;
	  			next_v = nv->var_data.variable_data_u.v_record.variables.variables_val[a];
	  					tmp_ccnt++;
	        		print_variable_new (next_v, scope, level + 1);
				tmp_ccnt--;
			}
			printc("};");
			printc("struct _dynelem_%s *%s=0;",name,name);
			}
			break;




			default:
				A4GL_assertion(1,"Not expecting this type of variable");
			break;
		}
		return;
  }
	}




  if (v->var_data.variable_type == VARIABLE_TYPE_SIMPLE)
    {
      char tmpbuff[256];
      SPRINTF2 (tmpbuff, "%s %s", local_rettype_integer (v->var_data.variable_data_u.v_simple.datatype), name);
      if (v->arr_subscripts.arr_subscripts_len)
	{
	  if (strchr (arrbuff, '-') == 0)
	    {
	      strcat (tmpbuff, "[");
	      strcat (tmpbuff, arrbuff);
	      strcat (tmpbuff, "]");
	    }
	  else
	    {
	              SPRINTF2 (tmpbuff, "%s *%s", local_rettype_integer (v->var_data.variable_data_u.v_simple.datatype), name);
	    }
	}

      if (v->var_data.variable_data_u.v_simple.datatype == DTYPE_CHAR || v->var_data.variable_data_u.v_simple.datatype==DTYPE_VCHAR  || v->var_data.variable_data_u.v_simple.datatype==DTYPE_NCHAR)
	{			/* Its a 'char' (may need varchar & friends too...*/


		if ( v->var_data.variable_data_u.v_simple.datatype==DTYPE_NCHAR) {
	  		print_define_char (tmpbuff, v->var_data.variable_data_u.v_simple.dimensions[0]*4, static_extern_flg);
		} else {
			if (v->var_data.variable_data_u.v_simple.datatype == 0) {
	  			print_define_char (tmpbuff, v->var_data.variable_data_u.v_simple.dimensions[0], static_extern_flg);
			} else {
	  			print_define_char (tmpbuff, v->var_data.variable_data_u.v_simple.dimensions[0], static_extern_flg); // Allow extra space to store the size...
			}
		}
	}
      else
	{
		
	  print_define (tmpbuff, static_extern_flg);
	}

clr_suppress_lines();
      return;
    }

   if ( v->var_data.variable_type == VARIABLE_TYPE_OBJECT) {
      print_start_record (static_extern_flg, name, arrbuff, level);
	        print_variable_new (v->var_data.variable_data_u.v_object.definition, scope, level+1);
      		print_end_record (name, v, level);
		return;
   }

  if (v->var_data.variable_type == VARIABLE_TYPE_RECORD) 
    {
      int a;
      print_start_record (static_extern_flg, name, arrbuff, level);
      for (a = 0; a < v->var_data.variable_data_u.v_record.variables.variables_len; a++)
	{
	  struct variable *next_v;
	  	next_v = v->var_data.variable_data_u.v_record.variables.variables_val[a];
	  	tmp_ccnt++;
	        print_variable_new (next_v, scope, level + 1);
		tmp_ccnt--;
	}
      print_end_record (name, v, level);
      clr_suppress_lines();
      return;
    }

  if (v->var_data.variable_type == VARIABLE_TYPE_ASSOC)
    {
      struct variable v2;
      char buff1[20];
      char buff2[20];

      SPRINTF1 (buff1, "%d", v->var_data.variable_data_u.v_assoc.char_size);
      SPRINTF1 (buff2, "%d", v->var_data.variable_data_u.v_assoc.size);

      print_declare_associate_1 (v->names.names.names_val[0].name,buff2,buff1);
      //print_declare_associate_2 (v->names.names.names_val[0].name,buff1,buff2);


      memcpy (&v2, v->var_data.variable_data_u.v_assoc.variable, sizeof (struct variable));

      //v2.names.next = 0;
      v2.names.names.names_len = v->names.names.names_len;
      v2.names.names.names_val = v->names.names.names_val;

      print_variable_new (&v2, scope, level + 1);
clr_suppress_lines();
      return;
    }

  if (v->var_data.variable_type == VARIABLE_TYPE_CONSTANT)
    {
      /* Maybe we should print out #define's for these ?*/
      /* Maybe not - they should already have been converted by lexer.c*/
		print_Constant_1(v->names.names.names_val[0].name,&v->var_data.variable_data_u.v_const);
    }

clr_suppress_lines();

}



/**
 *  * Gets the C data type corresponding to 4gl data type
 *   *
 *    * @param s A string with the numeric 4gl data type (@see find_type())
 *     * @return The string (static) with the C declaration
 *      */
char * local_rettype (char *s)
{
    static int initialized = 0;
    static char *vals[]={
	"char",        // 0 
	"short",       // 1 
	"long",        // 2 
	"double",      // 3 
	"float",       // 4 
	"fgldecimal",  // 5 
	"long",        // 6 
	"fgldate",     // 7 
	"fglmoney",    // 8 
	"",            // 9
	"struct_dtime",// 10 
	"fglbyte",     // 11 
	"fgltext",     // 12 
	"fglvarchar",        // 13 
	"struct_ival",  // 14 
	"char", //15
	"nvarchar",
	"int8", // 17
	"serial8", // 18
	0
    };
    int i;

    A4GL_debug("In rettype : %s", A4GL_null_as_null(s));

    if (! initialized)
    {
	A4GL_debug ("In rettype - initializing type names");
	for (i = 0; vals[i]; i++)
	{
	    if (A4GL_has_datatype_function_i (i, "OUTPUT"))
	    {
		char *(*function) (void);
		function = A4GL_get_datatype_function_i (i, "OUTPUT");
		vals[i] = strdup(function());
	    }
	}
	initialized = 1;

    }

    if (sscanf(s, "%d", &i) != 1) {
	yylineno=line_for_cmd;a4gl_yyerror("Internal error - type conversion error\n");
	}

    if (i < sizeof(vals)/sizeof(char*)) {
	return vals[i];
     }


    yylineno=line_for_cmd;


    a4gl_yyerror("Unsupported type id");
    return NULL;
}


char *get_keyval_str(char *s) {
	static char buff[256];
 	SPRINTF1(buff,"A4GL_key_val(\"%s\")",s);
	return buff;
}





int local_print_agg_defines(char t,int a) {

       printh ("/* local_print_agg_defines - %c %d  */\n", t, a);

  if (t == 'C') /* Count */
    {
          printh ("static long _g%d=0;\n", a);

	  //SPRINTF(usage,"A4GL_push_int(_g%d);\n",a);

      return 1;
    }

  if (t == 'P') /* Percent */
    {
          printh ("static long _g%d=0,_gpc%d=0;\n", a, a);
	//sprintf(usage,"A4GL_push_double((double)_g%d/(double)_g%d);\n",a,a+1);
      return 2;
    }

  if (t == 'S') /* Sum */
    {
          printh ("static long _g%dused=0;\n", a);
          printh ("static void* _g%d=0;\n", a);
          printh ("static long _gt_%d=0;\n", a);
	//sprintf(usage,"if (_g%dused) A4GL_push_double(_g%d); else A4GL_push_null(1,0);\n",a,a);
      return 1;
    }

  if (t == 'N' || t == 'X') /* Min/Max */
    {
          printh ("static void *_g%d=0;\n", a);
          printh ("static long _gt_%d=0;\n", a);
          printh ("static long _g%dused=0;\n", a);
	//sprintf(usage,"A4GL_push_double(_g%d);\n",a);
      return 1;
    }

  if (t == 'A') 	/* Average */
    {
          printh ("static void *_g%d=0;\n", a);
          printh ("static long _gt_%d=0;\n", a);
          printh ("static long   _gavg%d=0;\n", a);
	//sprintf(usage,"A4GL_push_double(_g%d/(double)_g%d);\n",a,a+1);

      return 2;
    }


return 0;
}

int LEXLIB_LEX_initlib() {
	LEXLIB_A4GL_initlex();
	return 1;
}

void LEXLIB_A4GL_initlex(void) {
	/* does nothing - but required by the API...
	calling this function will force initlib to be called - which is what we're really after.... */
	LEX_initlib();
}

void A4GL_whenchange(int n) {
	// does nothing but required by the API
}

int LEX_initlib(void) {
int c;
  if (A4GL_doing_pcode()) {
    	A4GL_setenv ("MARK_SCOPE_MODULE", "Y", 1);
    	A4GL_setenv ("NAMESPACE", "", 1);
    	//A4GL_setenv ("REPORT_VARS_AT_MODULE", "Y", 1);
  }
  if (doing_esql()) {
	  // Can we have compile time conversions please....
	A4GL_set_compile_time_convert(1);
	if (esql_type()!=E_DIALECT_INFORMIX) {
    		A4GL_setenv ("FIXUPDATE", "Y", 1);
	}
  } else {
	A4GL_set_compile_time_convert(0);
  }
for (c=0;c<255;c++) {
	last_print_bind_dir_definition_g_rval[c]=0;
}

return 1;
}



char *A4GL_field_name_as_char(char*fname,char *sub) {
static char buff[256];
SPRINTF2(buff,"%s,%s",fname,sub);
return buff;
}


char *get_array_rebase(char *s) {
	char *a;
	a=malloc(strlen(s)+20);
	SPRINTF1(a,"%s-1",s);
	return a;
}


void print_loaded_globals_file(char *s) {
	// Does nothing - required by the API
}



void print_start_globals(void) {
	// Does nothing - required by the API
}

void print_end_globals(void) {
	// Does nothing - required by the API
}

void print_cancel(char *s) {
	A4GL_assertion(1,"CANCEL not implemented yet");
}

int get_whenever_style(int code, char*whento) {
	// We want the callbacks - so return 1
	return 1;
}


static enum e_scope local_find_variable_scope(expr_str *e) {
	A4GL_assertion(e->expr_type!=ET_EXPR_VARIABLE_USAGE,"Not a variable usage...");
	return e->expr_str_u.expr_variable_usage->escope;
}


int check_binding(struct expr_str_list *l, char *fromwhere,int yylineno) {
char c;
int a;
if (l==0) return 0;
for (a=0;a<l->list.list_len;a++) {
        c=local_find_variable_scope(l->list.list_val[a]);
        if (c==E_SCOPE_MODULE||c==E_SCOPE_EXPORTED_GLOBAL|| c==E_SCOPE_IMPORTED_GLOBAL) {
                if (A4GL_isyes(acl_getenv("WARNGLOBMODBINDING"))) {
                        if (c==E_SCOPE_MODULE) {
                                fprintf(stderr, "Use of module variable (%s) @%d (%s)\n",get_dbg_variable_name(l->list.list_val[a]),yylineno,fromwhere);
                        }
                        if (c==E_SCOPE_EXPORTED_GLOBAL || c==E_SCOPE_IMPORTED_GLOBAL) {
                                fprintf(stderr, "Use of global variable (%s) @%d (%s)\n",get_dbg_variable_name(l->list.list_val[a]),yylineno,fromwhere);
                        }
                }
        }
}
return 0;
}





void merge_files (void)
{
  FILE *h;
  FILE *c;
  char buff[100001];
  FILE *final_o;


  if (A4GL_isyes (acl_getenv ("A4GL_NOCFILE")))
    {
      A4GL_debug (">>> NO C FILES... ");
      return;
    }


  A4GL_assertion (strlen (filename_for_c) == 0, "No cfile defined");
  A4GL_assertion (strlen (filename_for_h) == 0, "No hfile defined");
  A4GL_assertion (strlen (filename_for_output) == 0, "No outfile defined");
  c = fopen (filename_for_c, "r");
  h = fopen (filename_for_h, "r");

  final_o = fopen (filename_for_output, "wb");
  if (c == 0)
    {
      printf ("Can't open %s\n", filename_for_c);
      exit (1);
    }

  if (h == 0)
    {
      printf ("Can't open %s\n", filename_for_h);
      exit (1);
    }

  if (final_o == 0)
    {
      printf ("Can't open %s\n", filename_for_output);
      exit (1);
    }

  while (1)
    {
      fgets (buff, 100000, h);
      if (feof (h))
	break;
      A4GL_trim (buff);
	  if (final_o)
	    FPRINTF (final_o, "%s\n", buff);
    }
  fclose (h);
  unlink (filename_for_h);

  while (1)
    {
      fgets (buff, 100000, c);
      if (feof (c))
	break;
      A4GL_trim (buff);
      if (final_o)
	FPRINTF (final_o, "%s\n", buff);

    }
  fclose (c);
  unlink (filename_for_c);
  fclose (final_o);
}



static void
print_module_variable_init (variable_list * mvars)
{
set_suppress_lines() ;
if (!A4GL_doing_pcode()) {
  printc("#");
  printc ("static int _done_init_module_variables=1;\n");
  printc ("A4GL_INTERNAL_FUNCTION static void init_module_variables(void) {");
  tmp_ccnt++;
  printc ("if (_done_init_module_variables==0) return;");
  printc ("_done_init_module_variables=0;");

  printc("A4GL_check_version(_module_name,\"%s\",%d);",A4GL_internal_version(),A4GL_internal_build()); 
  printc("A4GL_check_dependant_tables(_module_name, _CompileTimeSQLType, _dependantTables);"); 

  print_nullify (E_SCOPE_MODULE, mvars);
  tmp_ccnt--;
  printc ("}");
  printc("#");
}
clr_suppress_lines() ;
}



void dump_command_list(struct command **clist, int nvals) { // another way to call dump_commands when we only have a list and a count
struct commands c;
c.cmds.cmds_val=clist;
c.cmds.cmds_len=nvals;
dump_commands(&c);
}



void dump_commands(commands *c) {
int a;
      if (c==0) return;
      last_cmd=NULL;

      for (a = 0; a < c->cmds.cmds_len; a++)
        {
          dump_cmd (c->cmds.cmds_val[a]);
	  last_cmd=c->cmds.cmds_val[a];
        }

}

static int
dump_function (struct s_function_definition *function_definition, int ismain)
{

  int a;
expr_str_list *expanded_params;
  printc ("#");
  printc ("#");
  printc ("#");
  dump_comments (function_definition->lineno);
  returns = 0;
  line_for_cmd = function_definition->lineno;
	parent_stack_cnt=0;

  if (ismain || strcmp (function_definition->funcname, "MAIN") == 0)
    {
      if (doing_cs ())
        {
          printc ("\n\npublic static void Main(string argv[]) {\n");
          printc ("string[] _paramnames=new string[1]; _paramnames[0]={\"\"};");
          printc ("int _nargs=0;");
        }
      else
        {

          if (A4GL_doing_pcode ())
            {
              printc ("\n\nA4GL_MAIN int main(int _nargs) {\n");
		printc("void *_blobdata=0;");
              printc ("char *_paramnames[1]={\"\"};");
            }
          else
            {


              printc ("\n\nA4GL_MAIN int main(int argc,char *argv[]) {\n");
              printc ("char *_paramnames[1]={\"\"};");
		printc("void *_blobdata=0;");
              printc ("int _nargs=0;");
            }
        }
      printDeclareFunctionStack ("MAIN");
      tmp_ccnt++;
// local variables...
      if (function_definition->variables.variables.variables_len)
        {
          for (a = 0; a < function_definition->variables.variables.variables_len; a++)
            {
              print_variable_new (function_definition->variables.variables.variables_val[a], E_SCOPE_LOCAL, 0);
            }
        }
      print_fgllib_start (current_module->mod_dbname, current_module->schema_only==EB_TRUE,  current_module->force_ui ,current_module->debug_filename);
      print_function_variable_init (&function_definition->variables);
      printInitFunctionStack ();
      printPushFunction (function_definition->lineno);

    }
  else
    {
             //set_nonewlines ();
      printc ("\nA4GL_FUNCTION %sint %s%s (int _nargs){ \n",
              function_definition->isstatic==EB_TRUE ? "static " : "", function_definition->namespace, function_definition->funcname);
	printc("void *_blobdata=0;");

      //printc ("\nstatic char *_functionName = \"%s\";\n", function_definition->funcname);

      //clr_nonewlines ();
      printDeclareFunctionStack (function_definition->funcname);
      add_function_to_header (function_definition->funcname, function_definition->namespace, 1, function_definition->isstatic==EB_TRUE);

// local variables...
//
      if (function_definition->variables.variables.variables_len)
        {
          for (a = 0; a < function_definition->variables.variables.variables_len; a++)
            {
              print_variable_new (function_definition->variables.variables.variables_val[a], E_SCOPE_LOCAL, 0);
            }
        }
      printc ("#");
	expanded_params=expand_parameters(&function_definition->variables,function_definition->parameters);
		yylineno=function_definition->lineno;
      print_param_g ('f', function_definition->funcname, expanded_params );

      if (local_isGenStackInfo ())
        {
          if (!A4GL_doing_pcode ())
            {
              //printc ("A4GLSTK_setCurrentLine(_module_name,%d);", function_definition->lineno);
              printc ("A4GLSTK_pushFunction(_functionName,_paramnames,_nargs,_module_name,%d);\n",function_definition->lineno);
            }
        }


      if (A4GL_doing_pcode ())
        {
          printc
            ("if (_nargs!=%d) {A4GLSQL_set_status(-3002,0);A4GL_pop_args(_nargs);return -1;}\n",
             expanded_params->list.list_len);
        }
      else
        {
          printc
            ("if (_nargs!=%d) {A4GLSQL_set_status(-3002,0);A4GL_pop_args(_nargs);A4GLSTK_popFunction_nl(0,%d);return -1;}\n",
             expanded_params->list.list_len, function_definition->lineno);
        }
      tmp_ccnt++;
      print_function_variable_init (&function_definition->variables);
      printc("{int _lstatus=a4gl_status;");
      printc ("A4GL_pop_params_and_save_blobs(_fbind,%d,&_blobdata);\n", expanded_params->list.list_len);
      printc("if (_lstatus!=a4gl_status) { A4GL_chk_err(%d,_module_name);  }",function_definition->lineno );
      printc("}");

    }

  printc ("#");

  if (function_definition->func_commands)
    {
	dump_command_list(function_definition->func_commands->cmds.cmds_val, function_definition->func_commands->cmds.cmds_len);

	/*
      for (a = 0; a < function_definition->func_commands->cmds.cmds_len; a++)
        {
          dump_cmd (function_definition->func_commands->cmds.cmds_val[a]);
        }
	*/
    }

  dump_comments (function_definition->lastlineno);

  if (ismain || strcmp (function_definition->funcname, "MAIN") == 0)
    {
      if (doing_esql ())
        {
		struct_close_sql_cmd cmd_data;
		cmd_data.cl_type=E_CT_DATABASE;
          printc ("if (A4GL_esql_db_open(-1,0,0,\"\")) {");

          tmp_ccnt++;
	  
 	print_close_sql_cmd(&cmd_data,1);
          tmp_ccnt--;
          printc ("}");
        }
      printc ("A4GL_fgl_end_4gl_0();");
      printc ("return 0;");
      tmp_ccnt--;
      printc ("}\n");

    }
  else
    {
	printPopFunction(0,function_definition->lastlineno);
      printc("A4GL_copy_back_blobs(_blobdata,0);");
      printc ("return 0;\n");
      tmp_ccnt--;
      printc ("}");
      printcomment ("/* END OF FUNCTION */\n\n\n\n");
      printc ("#");
    }

return 1;
}

static int
dump_formhandler (struct s_formhandler_definition *function_definition)
{
static int printed_gtk=0;
  int a;
char *name;
//expr_str_list *expanded_params;
  printc ("#");
  printc ("#");
  printc ("#");
  //dump_comments (function_definition->lineno);
  returns = 0;
  //line_for_cmd = function_definition->lineno;
	parent_stack_cnt=0;
name=function_definition->formhandler_name;

if (!printed_gtk) {
      printh ("#define ON_FIELD(x) (A4GL_widget_name_match(widget,x)&&event==0&&(A4GL_strnullcmp(data,\"on\")==0||A4GL_strnullcmp(data,\"clicked\")==0))\n");
      printh ("#define BEFORE_OPEN_FORM  (event==0&&widget==0&&data==0)\n");
      printh ("#define BEFORE_CLOSE_FORM  (isevent==1&&(A4GL_is_event_close(event)) )\n");
      printed_gtk++;
}
  printh ("int hnd_e_%s(void *widget,void *event,void * data);\n", name);
  printh ("int hnd_c_%s(void *widget,void * data);\n", name);
  printh ("int hnd_%s (void *widget, int isevent,void *event,void * data);\n", name);
  printc ("int hnd_e_%s(void *widget,void *event,void * data) {\n", name);
  printc ("  hnd_%s(widget,1,event,data);\n", name);
  printc ("return 0;}\n");
  printc ("int hnd_c_%s(void *widget,void * data) {\n", name);
  printc ("  return hnd_%s(widget,0,0,data);\n", name);
  printc ("}\n");
  printc ("int hnd_%s (void *widget, int isevent,void *event,void * data) {\n", name);
  tmp_ccnt++;

// local variables...
//
      if (function_definition->variables.variables.variables_len)
        {
          for (a = 0; a < function_definition->variables.variables.variables_len; a++)
            {
              print_variable_new (function_definition->variables.variables.variables_val[a], E_SCOPE_LOCAL, 0);
            }
        }
  printc ("static char this_win[64]=\"\";char cwin[64]; strcpy(cwin,A4GL_get_currwin_name());\n");
  printc ("if (strlen(this_win)==0) strcpy(this_win,A4GL_get_currwin_name());\n");
  printc ("if (strcmp(this_win,cwin)!=0) A4GL_current_window(this_win);");


  printc("A4GL_assertion(1,\"FIXME\");");
/*
  if (function_definition->func_commands)
    {
      for (a = 0; a < function_definition->func_commands->cmds.cmds_len; a++)
        {
          dump_cmd (function_definition->func_commands->cmds.cmds_val[a]);
        }
    }
*/

  //dump_comments (function_definition->lastlineno);

  tmp_ccnt--;
  printc ("}");
return 1;
}



static void dump_function_prototypes(module_definition *m) {
  int a;
  for (a = 0; a < m->module_entries.module_entries_len; a++) {
      switch (m->module_entries.module_entries_val[a]->met_type)
        {

           case E_MET_IMPORT_FUNCTION_DEFINITION:  
		add_function_to_header (m->module_entries.module_entries_val[a]->module_entry_u.import_function_definition.funcname, 
					get_namespace(m->module_entries.module_entries_val[a]->module_entry_u.import_function_definition.funcname),
					1,0);
		break;

          case E_MET_IMPORT_LEGACY_DEFINITION:    
		 add_function_to_header(m->module_entries.module_entries_val[a]->module_entry_u.import_legacy_definition.funcname,
			 		get_namespace(m->module_entries.module_entries_val[a]->module_entry_u.import_legacy_definition.funcname),1,0);
		break;

        case E_MET_REPORT_DEFINITION:
		add_function_to_header(
				m->module_entries.module_entries_val[a]->module_entry_u.report_definition.funcname,
				m->module_entries.module_entries_val[a]->module_entry_u.report_definition.namespace,
				2,
				m->module_entries.module_entries_val[a]->module_entry_u.report_definition.isstatic==EB_TRUE	
				);

          	break;

        case E_MET_PDF_REPORT_DEFINITION:
		add_function_to_header(
				m->module_entries.module_entries_val[a]->module_entry_u.pdf_report_definition.funcname,
				m->module_entries.module_entries_val[a]->module_entry_u.pdf_report_definition.namespace,
				2,
				m->module_entries.module_entries_val[a]->module_entry_u.pdf_report_definition.isstatic==EB_TRUE	
				);
          	break;


        case E_MET_MAIN_DEFINITION:
              printh ("\n\nA4GL_MAIN int main(int argc,char *argv[]);\n");
          	break;

        case E_MET_FUNCTION_DEFINITION:
		add_function_to_header(
				m->module_entries.module_entries_val[a]->module_entry_u.function_definition.funcname,
				m->module_entries.module_entries_val[a]->module_entry_u.function_definition.namespace,
				1,
				m->module_entries.module_entries_val[a]->module_entry_u.function_definition.isstatic==EB_TRUE	
				);
          break;


		// We can ignore all of these...
        case E_MET_CMD:
	case E_MET_FORMHANDLER_DEFINITION:
	case E_MET_CLASS_DEFINITION:
	case E_MET_IMPORT_DATATYPE:
	case E_MET_IMPORT_PACKAGE:
          	break;

	}
  }
}

int
LEXLIB_A4GL_write_generated_code (struct module_definition *m)
{
int a;
char buff1[1000];
char buff2[2000];
LEX_initlib();
strcpy(this_module_name,m->module_name);
 current_module = m;
	set_namespace(current_module->namespace);

      open_outfile () ; // this_module_name);
      if (outfile == 0)
	return 0;
      dump_function_prototypes(m);




printc("static const char *_CompileTimeSQLType=\"%s\";\n", m->compile_time_sqltype);
printc("static const struct sDependantTable _dependantTables[]= {");
for (a=0;a<m->dependant_tables.dependant_tables_len;a++) {
	strcpy(buff1, escape_quotes_and_remove_nl(m->dependant_tables.dependant_tables_val[a].tabname));
	strcpy(buff2,escape_quotes_and_remove_nl(m->dependant_tables.dependant_tables_val[a].checksuminfo));
	printc("  {\"%s\",\"%s\"},",buff1,buff2);
}
printc("  {0,0}");
printc("};");
printc("#");


  if (m->imported_global_variables.variables.variables_len)
    {
      for (a = 0; a < m->imported_global_variables.variables.variables_len; a++)
        {
          print_variable_new (m->imported_global_variables.variables.variables_val[a], E_SCOPE_IMPORTED_GLOBAL, 0);
        }
    }

  if (m->exported_global_variables.variables.variables_len)
    {
      for (a = 0; a < m->exported_global_variables.variables.variables_len; a++)
        {
          print_variable_new (m->exported_global_variables.variables.variables_val[a], E_SCOPE_EXPORTED_GLOBAL, 0);
        }
    }

  if (m->module_variables.variables.variables_len)
    {
      for (a = 0; a < m->module_variables.variables.variables_len; a++)
        {
          print_variable_new (m->module_variables.variables.variables_val[a], E_SCOPE_MODULE, 0);
        }
    }


  print_module_variable_init (&m->module_variables);


  for (a = 0; a < m->module_entries.module_entries_len; a++)
    {
      int ok = 1;
	char *s;

	parent_stack_cnt=0;

      current_entry = m->module_entries.module_entries_val[a];

      switch (m->module_entries.module_entries_val[a]->met_type)
        {
		case E_MET_IMPORT_PACKAGE:
			// Does nothing - just keep the -Wall option happy..
			break;
           case E_MET_IMPORT_FUNCTION_DEFINITION:  
		
		print_import(
			m->module_entries.module_entries_val[a]->module_entry_u.import_function_definition.funcname,
			m->module_entries.module_entries_val[a]->module_entry_u.import_function_definition.nparam,
			m->module_entries.module_entries_val[a]->module_entry_u.import_function_definition.lineno
			);
		//struct s_import_function_definition import_function_definition;
		break;
	case E_MET_IMPORT_DATATYPE:
		s=m->module_entries.module_entries_val[a]->module_entry_u.import_datatype_definition.dtype_name;
	  	A4GLEXDATA_initlib (s);
  		if (A4GL_has_datatype_function_n (s, "INCLUDE")) {
			char ss[25600];
			  char *(*function) (void);

      			function = A4GL_get_datatype_function_n (s, "INCLUDE");
      			A4GL_debug ("function=%p\n", function);
      			strcpy (ss, function ());
		  	printh ("#include <%s.h>\n", ss);
		}
		break;

          case E_MET_IMPORT_LEGACY_DEFINITION:    
		print_import_legacy( m->module_entries.module_entries_val[a]->module_entry_u.import_legacy_definition.funcname);
		break;

        case E_MET_REPORT_DEFINITION:
		current_entry_variables=&m->module_entries.module_entries_val[a]->module_entry_u.report_definition.variables;
          ok = dump_report (&m->module_entries.module_entries_val[a]->module_entry_u.report_definition);

          break;
        case E_MET_PDF_REPORT_DEFINITION:
		current_entry_variables=&m->module_entries.module_entries_val[a]->module_entry_u.pdf_report_definition.variables;
          ok = dump_pdf_report (&m->module_entries.module_entries_val[a]->module_entry_u.pdf_report_definition);
          break;
        case E_MET_CMD:
          ok = dump_cmd (m->module_entries.module_entries_val[a]->module_entry_u.cmd);
          break;
        case E_MET_MAIN_DEFINITION:
		current_entry_variables=&m->module_entries.module_entries_val[a]->module_entry_u.function_definition.variables;
          ok = dump_function (&m->module_entries.module_entries_val[a]->module_entry_u.function_definition, 1);
          break;

        case E_MET_FUNCTION_DEFINITION:
		current_entry_variables=&m->module_entries.module_entries_val[a]->module_entry_u.function_definition.variables;
          ok = dump_function (&m->module_entries.module_entries_val[a]->module_entry_u.function_definition, 0);
          break;

	case E_MET_FORMHANDLER_DEFINITION:
		ok=dump_formhandler(&m->module_entries.module_entries_val[a]->module_entry_u.formhandler_definition);
		break;

	case E_MET_CLASS_DEFINITION:
		A4GL_assertion(1,"Not implemented yet");
		break;

        }

      if (!ok) {
		a4gl_yyerror("Some error...");
        return 0;
	}

    }

	/* if the code includes the 'CURSOR_NAME' function with a variable - we
		need to be able to look up the new name from the original name
		we do this by searching through the clobberings as a list and returning that
	*/
    if ( need_cursorname) {
		int a;
		printh("static void acl_get_cursorname(void);\n");
		printc("/* Automatically generated function called by CURSOR_NAME(..) */");
		printc("static void acl_get_cursorname(void) {");
		printc("char *s; char *p; s=A4GL_char_pop();");
		printc("p=s;");
		printc("A4GL_trim(s);");
		for (a=0;a<m->clobberings.clobberings_len;a++) {
			printc("if (strcmp(s,\"%s\")==0) p=\"%s\";",  m->clobberings.clobberings_val[a].important,  m->clobberings.clobberings_val[a].newval);
		}
		printc("A4GL_push_char(p);");
		printc("free(s);");
		printc("}");
    }

  dump_comments (1000000);

A4GL_lex_parsed_fgl();
  outfile = 0;
  return 1;


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
void
print_declare_associate_1 (char *variable, char *size, char *n)
{
  printc ("DEF_ASS (_usg%s,%s+1);\n", downshift (variable), size);
  printc
    ("#define ASSOCIATE_%s(w,rw) %s[A4GL_ass_hash(_usg%s,%s+1,%s,w,sizeof(_usg%s),rw)]\n",
     upshift (variable), downshift (variable), downshift (variable),
     n, size, downshift (variable));
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
void
print_declare_associate_2 (char *variable, char *size, char *n)
{
  printc
    ("#define ASSOCIATE_%s(w) %s[A4GL_ass_hash(_usg%s,%s,%s+1,w,sizeof(_usg%s))]\n",
     upshift (variable), downshift (variable),
     downshift (variable), n, size, downshift (variable));
}




char *get_dbg_variable_name(expr_str *v) {
static char buff[1000];
struct variable_usage *u;
strcpy(buff,"");

	A4GL_assertion(v->expr_type!=ET_EXPR_VARIABLE_USAGE,"Not a variable usage");
	u=v->expr_str_u.expr_variable_usage;
	while (u)  {
		strcat(buff,u->variable_name);
		if (u->subscripts.subscripts_len) {
			strcat(buff,"[]");
		}
		if(u->next==0) break;
		strcat(buff,".");
		u=u->next;
	}
	return buff;
}


static int is_substring_variable_usage(variable_usage *u, expr_str **s, expr_str **e) {
	*s=0;
	*e=0;

	while (u)  {
		if(u->next==0) break;
		u=u->next;
	}
	if (u->substrings_start) {
		*s=u->substrings_start;
		*e=u->substrings_end;
		
		return 1;
	}

return 0;

}



static int is_substring_variable_usage_in_expr(expr_str *v, expr_str **s, expr_str **e) {
struct variable_usage *u=0;
        if (v->expr_type==ET_EXPR_LINENO) return 0;
        if (v->expr_type==ET_EXPR_PAGENO) return 0;
        if (v->expr_type==ET_EXPR_TODAY) return 0;

	if (v->expr_type==ET_EXPR_VARIABLE_USAGE) {
		u=v->expr_str_u.expr_variable_usage;
	}
	if (v->expr_type==ET_EXPR_VARIABLE_USAGE_WITH_ASC_DESC) {
		u=v->expr_str_u.expr_variable_usage_with_asc_desc->var_usage;
	}
	A4GL_assertion(u==0,"Not a variable usage");
	return is_substring_variable_usage(u,s,e);
}



//struct variable_usage *sgs_top=NULL;

static struct variable *set_get_subscript_as_string_top(struct variable_usage *u) {
	struct variable_usage t;
	struct variable *sgs_topvar=NULL;
	//sgs_top=u;
	memcpy(&t,u,sizeof(t));
	t.next=0;
	if (u->escope!=E_SCOPE_NOTSET && u->variable_id!=-1) {
		sgs_topvar=local_find_variable_from_usage(&t);
	}
	return sgs_topvar;
}



static int subscript_range_check(void) {
if (do_subscript_range_check>=0) return do_subscript_range_check;

if (A4GL_isno(acl_getenv("FGLCRANGECHK"))) {
	do_subscript_range_check=0;
} else {
	do_subscript_range_check=1;
}
return do_subscript_range_check;
}

static struct variable * set_get_subscript_as_string_next(struct variable *sgs_topvar, struct variable_usage *u) {
	if (subscript_range_check()==0) return NULL;
	if (sgs_topvar==NULL) return NULL;

	if ( sgs_topvar->var_data.variable_type == VARIABLE_TYPE_RECORD) {
		sgs_topvar=sgs_topvar->var_data.variable_data_u.v_record.variables.variables_val[u->variable_id];
	} else {
		sgs_topvar=NULL;
	}
	return sgs_topvar;
}

static char *get_subscript_as_string_with_check(struct variable *sgs_topvar, int a, expr_str *u) {
static char buff[256];
char smbuff[256];
	if (subscript_range_check()==0) sgs_topvar=NULL;


	if (sgs_topvar)  {
		int upperbound;
		upperbound=sgs_topvar->arr_subscripts.arr_subscripts_val[a];
		if (u->expr_type==ET_EXPR_LITERAL_LONG) {
			// We can make the 'long's look a little neater as we can subtract the 1..
			sprintf(smbuff, "A4GL_bounds_check(%ld,%ld)", (long)u->expr_str_u.expr_long-1,(long)upperbound);
		} else {
			sprintf(smbuff, "(A4GL_bounds_check(%s-1,%ld))", local_expr_as_string(u),(long)upperbound);
		}
	} else {
		if (u->expr_type==ET_EXPR_LITERAL_LONG) {
			// We can make the 'long's look a little neater as we can subtract the 1..
			sprintf(smbuff, "%ld", u->expr_str_u.expr_long-1);
		} else {
			sprintf(smbuff, "(%s-1", local_expr_as_string(u));
		}
	}


	strcpy(buff,smbuff);
	return buff;
}



void
print_pop_usage_prompt (expr_str * v)
{
int d;
  d=get_binding_dtype (v);

  if (A4GL_is_numeric_datatype(d)) { 
  		printc("A4GL_ensure_numeric_prompt_var(%d);",d);
  		print_pop_usage(v);
  } else {
  		print_pop_usage(v);
  }
}

void
print_pop_usage (expr_str * v)
{
  int substring = 0;
  struct variable_usage *u;
  expr_str *substring_start;
  expr_str *substring_end;
struct variable *sgs_topvar;

  u = v->expr_str_u.expr_variable_usage;
  A4GL_assertion (get_binding_dtype (v) == -1, "Usage not ensured...");
  if (v->expr_type==ET_EXPR_LINENO) {
  	printc("A4GL_pop_var2(&_rep.line_no,2,0);");
  	return;
  }
  if (v->expr_type==ET_EXPR_PAGENO) {
  	printc("A4GL_pop_var2(&_rep.page_no,2,0);");
  	return;
  }
  if (v->expr_type==ET_EXPR_TODAY) {
  	a4gl_yyerror("TODAY is a read only variable");
  	return;
  }
  set_nonewlines ();
  substring = is_substring_variable_usage_in_expr (v, &substring_start, &substring_end);
  if (substring)
    {
      printc ("a4gl_let_substr(");
    }
  else
    {
      printc ("A4GL_pop_var2(&");
    }


	sgs_topvar=set_get_subscript_as_string_top(u);

      while (u)
	{

  if (u->subscripts.subscripts_len && u->subscripts.subscripts_val[0]->expr_type == ET_EXPR_ASSOC)
    {
      assoc_write = 1;
      printc ("%s", local_expr_as_string (u->subscripts.subscripts_val[0]));
      assoc_write = 0;
	} else {

	  printc ("%s", u->variable_name);
	  if (u->subscripts.subscripts_len)
	    {
	      int a;
	      printc ("[");
	      for (a = 0; a < u->subscripts.subscripts_len; a++)
		{
		  if (a)
		    printc ("][");
		  printc ("%s", get_subscript_as_string_with_check (sgs_topvar, a, u->subscripts.subscripts_val[a]));
		  /*
		     if (u->subscripts.subscripts_val[a]->expr_type==ET_EXPR_LITERAL_LONG) {      
		     // We can make the 'long's look a little neater as we can subtract the 1..
		     printc("%d", u->subscripts.subscripts_val[a]->expr_str_u.expr_long-1);
		     } else {
		     printc("(%s)-1", local_expr_as_string(u->subscripts.subscripts_val[a]));
		     }
		   */
		}
	      printc ("]");
	    }
	}
	  if (u->next == 0)
	    break;
	  printc (".");
	  u = u->next;
		sgs_topvar=set_get_subscript_as_string_next(sgs_topvar, u);
	}

      if (substring)
	{
	  if (!substring_end)
	    {
	      printc (",%d,%s,0);", get_binding_dtype (v), local_expr_as_string (substring_start));
	    }
	  else
	    {
	      char *p1;
	      char *p2;
	      p1 = strdup (local_expr_as_string (substring_start));
	      p2 = strdup (local_expr_as_string (substring_end));

	      printc (",%d,%s,%s);", get_binding_dtype (v), p1, p2);
	      free (p1);
	      free (p2);
	    }
	}
      else
	{
	  printc (",%d,%d);", get_binding_dtype (v) & DTYPE_MASK, get_binding_dtype (v) >> 16);
	}
  clr_nonewlines ();


}

char *local_ident_as_string(expr_str *f,int quote) {
static char buff[2000];
	switch (f->expr_type) {
		case ET_EXPR_IDENTIFIER:
			if (quote) {	
				sprintf(buff,"\"%s\"", f->expr_str_u.expr_string);
			} else {
				sprintf(buff,"%s", f->expr_str_u.expr_string);
			}
			return buff;
		case ET_E_V_OR_LIT_STRING:
			sprintf(buff,"%s", f->expr_str_u.expr_string);
			return buff;

		case ET_EXPR_VARIABLE_USAGE:
			sprintf(buff,"%s", generation_get_variable_usage_as_string(f->expr_str_u.expr_variable_usage));
			return buff;
		
		default:
			A4GL_assertion(1,"Not handled");
	}
	return "";
}




static void print_variable_usage_gen(expr_str *v,int err_if_substring) {
struct variable_usage *u=0;
int substring=0;
expr_str *substring_start;
expr_str *substring_end;
struct variable *sgs_topvar;
	if (v->expr_type==ET_EXPR_LINENO) {
		printc("lineno");
		return;
	}
	if (v->expr_type==ET_EXPR_PAGENO) {
		printc("pageno");
		return;
	}
	set_nonewlines();

	if (v->expr_type==ET_EXPR_VARIABLE_USAGE) {
		u=v->expr_str_u.expr_variable_usage;
	}
	if (v->expr_type==ET_EXPR_VARIABLE_USAGE_WITH_ASC_DESC) {
		u=v->expr_str_u.expr_variable_usage_with_asc_desc->var_usage;
	}
	A4GL_assertion(u==0,"Not a variable usage");


	substring=is_substring_variable_usage_in_expr(v,&substring_start, &substring_end);


	if (substring) {
		
		//printc("A4GL_push_substr(");
		
	}

	sgs_topvar=set_get_subscript_as_string_top(u);
	while (u)  {
  		if (u->subscripts.subscripts_len && u->subscripts.subscripts_val[0]->expr_type == ET_EXPR_ASSOC)
    		{
      		assoc_write = 1;
      		printc ("%s", local_expr_as_string (u->subscripts.subscripts_val[0]));
      		assoc_write = 0;
			} else {
		printc("%s",u->variable_name);
		if (u->subscripts.subscripts_len) {
			int a;
			printc("[");
			for (a=0;a<u->subscripts.subscripts_len;a++) { 
				if (a) printc("][");
				printc("%s", get_subscript_as_string_with_check(sgs_topvar, a,u->subscripts.subscripts_val[a]));
				/*
				if (u->subscripts.subscripts_val[a]->expr_type==ET_EXPR_LITERAL_LONG) {
					// We can make the 'long's look a little neater as we can subtract the 1..
					printc("%d", u->subscripts.subscripts_val[a]->expr_str_u.expr_long-1);
				} else {
					printc("(%s)-1", local_expr_as_string(u->subscripts.subscripts_val[a]));
				}
				*/
			}
			printc("]");
		}
		}
		if(u->next==0) break;
		printc(".");
		u=u->next;
		sgs_topvar=set_get_subscript_as_string_next(sgs_topvar, u);
	}

	if (substring && 0) {
		if (!substring_end) {
			printc(",%d,%s,0)", get_binding_dtype(v) , local_expr_as_string(substring_start));
		} else {
			printc(",%d)", get_binding_dtype(v) );
			// We'll split these off because local_expr_as_string only has a single return buffer
			printc(",%s", local_expr_as_string(substring_start));
			printc(",%s)", local_expr_as_string(substring_end));
		}
	}
	clr_nonewlines();
}

void print_variable_usage(expr_str *v) {
	print_variable_usage_gen(v,1) ;
}

void print_variable_usage_for_bind(expr_str *v) {
	print_variable_usage_gen(v,0) ;
}


// Are we in a report - and and if so - what prefix
// should be use?
// If its a pdfreport - most of the calls are prefixed with 'pdf_'
// to distiguish them from the normal report...
char *generate_ispdf() {
      switch (current_entry->met_type) {
	case E_MET_REPORT_DEFINITION: return "";
	case E_MET_PDF_REPORT_DEFINITION: return "pdf_";
	default: break;
	}
	A4GL_assertion(1,"ispdf called when not in a report");

return ""; // Can't happen - keep gcc -Wall happy though..
}


// Are we in a report ? 
int is_in_report() {
      switch (current_entry->met_type) {
	case E_MET_REPORT_DEFINITION: return 1;
	case E_MET_PDF_REPORT_DEFINITION: return 2;
	default :
		return 0;
	}
	return 0;
}



// Get the menu ID associate with the most recent menu 
int get_last_menuid(void) {
int z;
for (z=parent_stack_cnt-1;z>=0;z--) {
	if (parent_stack[z]->cmd_data.type==E_CMD_MENU_CMD) {
		// 
		return parent_stack[z]->cmd_data.command_data_u.menu_cmd.blockid;
	}
}
return -1;
}



void print_push_variable_usage (expr_str *ptr) {
struct variable_usage *u;
int substring=0;
//struct variable *v_var;
//char errbuff[255];
//char scope;
expr_str *substring_start;
expr_str *substring_end;

       	A4GL_assertion(ptr->expr_type!=ET_EXPR_VARIABLE_USAGE,"Not a variable usage");
	set_nonewlines();
	u=ptr->expr_str_u.expr_variable_usage;

       	substring=is_substring_variable_usage_in_expr(ptr,&substring_start, &substring_end);


	if (!substring) {

		switch (get_binding_dtype(ptr) & DTYPE_MASK) {
	  		case DTYPE_INT: printc ("A4GL_push_long("); 
					print_variable_usage(ptr);
					printc("); ");
				break;
	  		case DTYPE_SMINT: printc ("A4GL_push_int("); 
					print_variable_usage(ptr);
					printc(");");
					break;
	  		case DTYPE_FLOAT: printc ("A4GL_push_double("); 
					print_variable_usage(ptr);
					printc(");");
					break;
	  		case DTYPE_SMFLOAT: printc ("A4GL_push_float("); 
					print_variable_usage(ptr);
					printc(");");
					break;
	  		case DTYPE_DYNAMIC_ARRAY: 
					printc ("A4GL_push_dynamic_array("); 
					print_variable_usage(ptr);
					printc(",sizeof(struct _dynelem_%s)",generation_get_variable_usage_as_string(ptr->expr_str_u.expr_variable_usage));
					printc(");");
					break;
	  		default: 
				
				printc ("A4GL_push_variable(&");
					print_variable_usage(ptr);
	  			 printc (",0x%x);",get_binding_dtype(ptr) );
		}
	} else {
		struct variable *sgs_topvar;
		sgs_topvar=set_get_subscript_as_string_top(u);
		printc("A4GL_push_substr(");
		while (u)  {
			printc("%s",u->variable_name);
			if (u->subscripts.subscripts_len) {
				int a;
				printc("[");
				for (a=0;a<u->subscripts.subscripts_len;a++) { 
					if (a) printc("][");
					printc("%s", get_subscript_as_string_with_check(sgs_topvar, a, u->subscripts.subscripts_val[a]));
					//printc("(%s)-1", local_expr_as_string(u->subscripts.subscripts_val[a]));
				}
				printc("]");
			}
			if(u->next==0) break;
			printc(".");
			u=u->next;
		sgs_topvar=set_get_subscript_as_string_next(sgs_topvar, u);
		}

		if (substring_end==0) {
			printc(",%d,%s,0,0);", get_binding_dtype(ptr) , local_expr_as_string(substring_start));
		} else {
			printc(",%d", get_binding_dtype(ptr));
			// We'll split these off because local_expr_as_string only has a single return buffer
			printc(",%s", local_expr_as_string(substring_start));
			printc(",%s,0);", local_expr_as_string(substring_end));
		}
	}
	clr_nonewlines();
}



char *generation_get_variable_usage_as_string(struct variable_usage *u ) {
static char rbuff[2000];
int substring=0;
char buff[2000];
expr_str *substring_start;
expr_str *substring_end;
struct variable *sgs_topvar;
		substring=is_substring_variable_usage(u,&substring_start, &substring_end);

		if (substring) {
			A4GL_assertion(1,"Cant use a substring here");
			printc("A4GL_push_substr(");
		}

		strcpy(buff,"");
		sgs_topvar=set_get_subscript_as_string_top(u);
		while (u)  {
			strcat(buff,u->variable_name);
			if (u->subscripts.subscripts_len) {
				int a;
				strcat(buff, "[");
				for (a=0;a<u->subscripts.subscripts_len;a++) { 
					if (a) strcat(buff, "][");
					strcat(buff,  get_subscript_as_string_with_check(sgs_topvar, a, u->subscripts.subscripts_val[a]));
					//strcat(buff, local_expr_as_string(u->subscripts.subscripts_val[a]));
					//strcat(buff, "-1");
				}
				strcat(buff, "]");
			}
			if(u->next==0) break;
			strcat(buff,".");
			u=u->next;
		sgs_topvar=set_get_subscript_as_string_next(sgs_topvar, u);
		}
		strcpy(rbuff,buff);
	return rbuff;
}



char *local_expr_as_string(expr_str *s) {
static char rbuff[2000];
//char buff[2000];
char buff_l[2000];
char buff_r[2000];
struct variable_usage *u;
//int substring=0;
//expr_str *substring_start;
//expr_str *substring_end;

switch (s->expr_type) {
	case ET_EXPR_LINENO:
		return "lineno";
	case ET_EXPR_PAGENO:
		return "pageno";
	case ET_EXPR_LITERAL_LONG: 
			sprintf(rbuff,"%ld", s->expr_str_u.expr_long); 
			return rbuff;
	case ET_EXPR_OP_MULT: 
			strcpy(buff_l, local_expr_as_string(s->expr_str_u.expr_op->left));
			strcpy(buff_r, local_expr_as_string(s->expr_str_u.expr_op->right));
			sprintf(rbuff,"%s*%s", buff_l,buff_r);
			return rbuff;
	case ET_EXPR_OP_DIV: 
			strcpy(buff_l, local_expr_as_string(s->expr_str_u.expr_op->left));
			strcpy(buff_r, local_expr_as_string(s->expr_str_u.expr_op->right));
			sprintf(rbuff,"%s/%s", buff_l,buff_r);
			return rbuff;
	case ET_EXPR_OP_ADD: 
			strcpy(buff_l, local_expr_as_string(s->expr_str_u.expr_op->left));
			strcpy(buff_r, local_expr_as_string(s->expr_str_u.expr_op->right));
			sprintf(rbuff,"%s+%s", buff_l,buff_r);
			return rbuff;
	case ET_EXPR_OP_SUB: 
			strcpy(buff_l, local_expr_as_string(s->expr_str_u.expr_op->left));
			strcpy(buff_r, local_expr_as_string(s->expr_str_u.expr_op->right));
			sprintf(rbuff,"%s-%s", buff_l,buff_r);
			return rbuff;

	case ET_EXPR_BRACKET: 
			strcpy(buff_l, local_expr_as_string(s->expr_str_u.expr_expr));
			sprintf(rbuff,"(%s)", buff_l);
			return rbuff;

	case ET_EXPR_ASSOC: 
			strcpy(buff_l, local_expr_as_string(s->expr_str_u.expr_assoc_subscript->subscript_value));
			if (assoc_write) {
			sprintf(rbuff,"ASSOCIATE_%s(%s,0)", s->expr_str_u.expr_assoc_subscript->subscript_string, buff_l);
			} else {
			sprintf(rbuff,"ASSOCIATE_%s(%s,1)", s->expr_str_u.expr_assoc_subscript->subscript_string, buff_l);
			}
			return rbuff;
	
	case ET_EXPR_VARIABLE_USAGE:
		u=s->expr_str_u.expr_variable_usage;
		strcpy(rbuff,generation_get_variable_usage_as_string(u));
		return rbuff;

	case ET_E_V_OR_LIT_STRING:
		//sprintf(rbuff,"\"%s\"",s->expr_str_u.s); 
		return s->expr_str_u.s;

	case ET_EXPR_IDENTIFIER:
			sprintf(rbuff,"\"%s\"",s->expr_str_u.expr_string);
		return rbuff;
	case ET_EXPR_LITERAL_STRING:
			sprintf(rbuff,"\"%s\"",s->expr_str_u.expr_string);
		return rbuff;
		return s->expr_str_u.expr_string;
	case ET_EXPR_FCALL:
		{
		struct s_expr_function_call *fcall;
		fcall=s->expr_str_u.expr_function_call;
		A4GL_assertion(fcall==0,"No function call found");


		if (fcall->parameters==0 || (fcall->parameters && fcall->parameters->list.list_len==0)) {
			sprintf(rbuff, "A4GL_get_single_int_returned_from_call(%s%s(0))", fcall->namespace, fcall->fname);
			return rbuff;
		}

		if (fcall->parameters && strcmp(fcall->fname,"length")==0 &&  fcall->parameters->list.list_len==1) {
              char buff[20000];
              sprintf(buff,"A4GL_get_length(%s)",local_expr_as_string(fcall->parameters->list.list_val[0]));
              strcpy(rbuff,buff);
			return rbuff;
		}

		yylineno=line_for_cmd;
		set_yytext(fcall->fname);
		a4gl_yyerror("You can't use a function requiring parameters in this context");
		return 0;
		}
		return 0;
		
	default :
	
			yylineno=line_for_cmd;
		a4gl_yyerror("this type of expression cannot be used in this place");
		return  0;

		A4GL_assertion(1,"this type of expression cannot be used in this place");
	}

}


void print_field(struct fh_field_entry*field ) {
	set_nonewlines();
	print_ident(field->field);
	if (field->fieldsub) {
		printc(",");
		real_print_expr(field->fieldsub);
	} else {
		printc(",0");
	}
	clr_nonewlines();
}


void print_field_list(struct fh_field_list *flist) {
int a;
	set_nonewlines();
	for (a=0;a<flist->field_list_entries.field_list_entries_len;a++) {
		if (a) printc(",");
		print_field(&flist->field_list_entries.field_list_entries_val[a]);
	}
	clr_nonewlines();
}


void remove_field_subscripts_from_field_list(struct fh_field_list *flist) {
int a;
	for (a=0;a<flist->field_list_entries.field_list_entries_len;a++) {
		struct fh_field_entry*field ;
		field=&flist->field_list_entries.field_list_entries_val[a];
		if (field->fieldsub) {
			field->fieldsub=0;
		}
	}
}
void
print_ident (struct expr_str *ptr)
{

  if (ptr->expr_type == ET_EXPR_IDENTIFIER)
    {
      printc ("\"%s\"", ptr->expr_str_u.expr_string);
      return;
    }

  if (ptr->expr_type == ET_EXPR_VARIABLE_IDENTIFIER) // a _VARIABLE
    {
      printc("aclfgli_str_to_id(%s)", local_expr_as_string (ptr->expr_str_u.expr_expr));

      return;
    }
  if (ptr->expr_type == ET_EXPR_VARIABLE_USAGE)
    {
	print_variable_usage(ptr);
      //printc ("%s", get_variable_usage (ptr->expr_str_u.expr_variable_usage));
      return;
    }

  if (ptr->expr_type == ET_EXPR_SELECT_LIST_ITEM) {
			if (ptr->expr_str_u.sl_item->data.s_select_list_item_data_u.column.tabname==0) {
				printc("\"%s\"", ptr->expr_str_u.sl_item->data.s_select_list_item_data_u.column.colname);
				return;
			} 
		
  }

  A4GL_assertion (1, "print_ident not implemented yet");
  return;
}


char * get_ident_as_string (struct expr_str *ptr)
{
static char buff[2000];
  if (ptr->expr_type == ET_EXPR_IDENTIFIER)
    {
       sprintf(buff, "\"%s\"", ptr->expr_str_u.expr_string);
	return buff;
    }

  if (ptr->expr_type == ET_EXPR_VARIABLE_IDENTIFIER) // a _VARIABLE
    {
	static char buff[2000];
	sprintf(buff,"aclfgli_str_to_id(%s)", local_expr_as_string (ptr->expr_str_u.expr_expr));
	return buff;
    }

  if (ptr->expr_type == ET_EXPR_VARIABLE_USAGE)
    {
	return generation_get_variable_usage_as_string(ptr->expr_str_u.expr_variable_usage);
    }

  if (ptr->expr_type ==ET_EXPR_SELECT_LIST_ITEM) {
		if (ptr->expr_str_u.sl_item->data.type==E_SLI_COLUMN) {
			if (ptr->expr_str_u.sl_item->data.s_select_list_item_data_u.column.tabname==0) {
				sprintf(buff,"\"%s\"", ptr->expr_str_u.sl_item->data.s_select_list_item_data_u.column.colname);
				return  buff;
			} else {
				sprintf(buff,"\"%s.%s\"", ptr->expr_str_u.sl_item->data.s_select_list_item_data_u.column.tabname,
			  		ptr->expr_str_u.sl_item->data.s_select_list_item_data_u.column.colname);
				return buff;
			}
		}
  }

  A4GL_assertion (1, "get_ident_as_string not implemented for this expression type yet");
  return 0;
}



struct variable *local_find_variable_from_usage(struct variable_usage *u) {
struct variable *v=0;

// If this assertion fails - make sure you've run the expression containing the
// variable usage through the "ensure_variable" function to set up the scope/datatype and variable ids..
A4GL_assertion(u->variable_id<0,"Variable has not been previously found..");


switch (u->escope) {
	case E_SCOPE_LOCAL:  // list_local_cnt
		A4GL_assertion(u->variable_id>=current_entry_variables->variables.variables_len,"Invalid VARIABLE ID");
		v=current_entry_variables->variables.variables_val[u->variable_id];
		break;
	case E_SCOPE_MODULE:  // list_module
		A4GL_assertion(u->variable_id>=current_module->module_variables.variables.variables_len,"Invalid VARIABLE ID");
		v=current_module->module_variables.variables.variables_val[u->variable_id];
		break;
	case E_SCOPE_EXPORTED_GLOBAL:  // list_globals
		A4GL_assertion(u->variable_id>=current_module->exported_global_variables.variables.variables_len,"Invalid VARIABLE ID");
		v=current_module->exported_global_variables.variables.variables_val[u->variable_id];
		break;
	case E_SCOPE_IMPORTED_GLOBAL:  // list_imported_global
		A4GL_assertion(u->variable_id>=current_module->imported_global_variables.variables.variables_len,"Invalid VARIABLE ID");
		v=current_module->imported_global_variables.variables.variables_val[u->variable_id];
		break;


	default:
		A4GL_assertion(1,"Unexpected scope type...");

}
if (v==0) {
	A4GL_assertion(1,"Couldn't find variable");
}

// Quick double check...
if (strcmp(u->variable_name,v->names.names.names_val[0].name)!=0) {
	// Looks different..
	A4GL_assertion(1,"Variable name doesnt match");
}


if (u->next) {
	// We're expecting the variable to be a record...
	A4GL_assertion (v->var_data.variable_type!=VARIABLE_TYPE_RECORD,"Expecting a record");
	while (u->next) {
		u=u->next;
		A4GL_assertion(u->variable_id<0,"Variable not ensured...");
		A4GL_assertion(u->variable_id>v->var_data.variable_data_u.v_record.variables.variables_len,"Variable out of range");
		v=v->var_data.variable_data_u.v_record.variables.variables_val[u->variable_id];
	}
	
}

return v;
}



void print_str_list(str_list *list) {
	int a;
	set_nonewlines();
	for (a=0;a<list->str_list_entry.str_list_entry_len;a++) {
		if (a) printc(",");
		printc("%s", list->str_list_entry.str_list_entry_val[a]);
	}
	clr_nonewlines();
}

char *get_str_list_as_string(str_list *list,char *sep) {
char *rbuff=0;
int a;
        for (a=0;a<list->str_list_entry.str_list_entry_len;a++) {
                if (a) rbuff=make_sql_string_and_free(rbuff,strdup(sep),list->str_list_entry.str_list_entry_val[a], NULL);
                else rbuff=make_sql_string_and_free(list->str_list_entry.str_list_entry_val[a],NULL);
        }
return rbuff;
}


/* REALLY REQUIRED */



static void print_function_variable_init (variable_list * fvars)
{
  if (!A4GL_doing_pcode ())
    {
      printc ("#");
      printc ("init_module_variables();");
      print_nullify ('F', fvars);
    }
}





/**
 * The parser found the MAIN and the local variable definition and
 * it will generate the C code that initializes the fgl at run time.
 *
 * @param db The header database name (DATABASE statement outside functions).
 */
void print_fgllib_start (char *db, int is_schema,char *force_ui, char *debug_filename)
{
  //extern int is_schema;
  printc ("A4GLSTK_setCurrentLine(0,0);");
  if (force_ui && strlen(force_ui)) {
	    printc("A4GL_setenv (\"A4GL_UI\",\"%s\", 1);",force_ui);
  }
  if (debug_filename && strlen(debug_filename)) {
	    printc("A4GL_setenv (\"A4GL_DEBUGFILE\",\"%s\", 1);",debug_filename);
  }

  if (doing_esql()) {
	int t;
	t=tmp_ccnt;
	tmp_ccnt=0;
	set_suppress_lines();
	
	printc("#ifdef LEXDIALECT_TYPE");
	printc("    A4GL_setenv (\"A4GL_LEXDIALECT\",LEXDIALECT_TYPE, 1);");
	printc("#endif");
	tmp_ccnt=t;
	clr_suppress_lines();
  }

  if (!A4GL_doing_pcode ())
    {
      if (doing_cs ())
	{
	  printc ("\nA4GL_fgl_start(argv.Count(),argv);\n");
	}
      else
	{
	  printc ("\nif (A4GL_fgl_start(argc,argv)) {a4gl_show_compiled_version();}\n");
	}
    }

  if (db)
    {
      if (!is_schema)
	{
		struct_set_database_cmd  dbcmd;
		dbcmd.set_dbname=A4GL_new_literal_string(db);
		dbcmd.exclusive_mode=0;
		print_set_database_cmd (&dbcmd);

          //print_init_conn (A4GL_new_literal_string(db),"");


	  if (A4GL_doing_pcode()) {
	  	printc ("if (a4gl_sqlca.sqlcode<0) A4GL_chk_err(%d,\"%s\");\n", 0,cmodname);
	  } else {
	  	printc ("if (a4gl_sqlca.sqlcode<0) A4GL_chk_err(%d,_module_name);\n",0);
	  }
	}
      else
	{
	  printc ("/* NO DATABASE - SCHEMA ONLY */");
	}
    }
  //print_function_variable_init ();
}




static void check_for_variable(struct s_select_list_item *l,char dir) {
switch (l->data.type)  {
 	case E_SLI_VARIABLE_USAGE:
          l->data.type = E_SLI_VARIABLE;
          l->data.s_select_list_item_data_u.expression = strdup(get_sql_variable_usage (l->data.s_select_list_item_data_u.var_usage,dir));
	  return;
      case E_SLI_VARIABLE_USAGE_IN_SELECT_LIST:
          l->data.type = E_SLI_VARIABLE;
	  set_dont_use_indicators=1;
          l->data.s_select_list_item_data_u.expression = strdup(get_sql_variable_usage (l->data.s_select_list_item_data_u.var_usage,dir));
	  set_dont_use_indicators=0;
	  return;

       case E_SLI_OP:
      		check_for_variable (l->data.s_select_list_item_data_u.complex_expr.left,dir),
                check_for_variable(l->data.s_select_list_item_data_u.complex_expr.right,dir);
		return;

    case E_SLI_NOT_IN_SELECT:
    case E_SLI_IN_SELECT:
      	check_for_variable (l->data.s_select_list_item_data_u.complex_expr.left,dir);
	return;

    case E_SLI_NOT_IN_VALUES:
    case E_SLI_IN_VALUES:
      check_for_variable (l->data.s_select_list_item_data_u.slil_expr.left,dir);
      search_sql_variables (l->data.s_select_list_item_data_u.slil_expr.right_list,dir);
      break;

    case E_SLI_REGEX_MATCHES:
    case E_SLI_REGEX_NOT_MATCHES:
    case E_SLI_REGEX_LIKE:
    case E_SLI_REGEX_NOT_LIKE:
    case E_SLI_REGEX_ILIKE:
    case E_SLI_REGEX_NOT_ILIKE:
      check_for_variable (l->data.s_select_list_item_data_u.regex.val,dir);
      check_for_variable (l->data.s_select_list_item_data_u.regex.regex,dir);
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
      check_for_variable (l->data.s_select_list_item_data_u.expr,dir);
      break;

    case E_SLI_BUILTIN_FUNC_YEAR:
    case E_SLI_BUILTIN_FUNC_MONTH:
    case E_SLI_BUILTIN_FUNC_DAY:
    case E_SLI_BUILTIN_FUNC_DOW:
    case E_SLI_BUILTIN_FUNC_WEEKDAY:
    case E_SLI_BUILTIN_FUNC_MDY:
    case E_SLI_BUILTIN_FUNC_DATE:
      search_sql_variables ( l->data.s_select_list_item_data_u.builtin_fcall.params,dir);
      break;


    case E_SLI_BUILTIN_AGG_AVG:
    case E_SLI_BUILTIN_AGG_MAX:
    case E_SLI_BUILTIN_AGG_MIN:
    case E_SLI_BUILTIN_AGG_SUM:
    case E_SLI_BUILTIN_AGG_COUNT:
      check_for_variable (l->data.s_select_list_item_data_u.agg_expr.expr,dir);
      break;

    case E_SLI_NOT_BETWEEN:
    case E_SLI_BETWEEN:
      check_for_variable (l->data.s_select_list_item_data_u.between_expr.val,dir);
      check_for_variable (l->data.s_select_list_item_data_u.between_expr.from,dir);
      check_for_variable (l->data.s_select_list_item_data_u.between_expr.to,dir);
      break;


    case E_SLI_FCALL:
      search_sql_variables (l->data.s_select_list_item_data_u.fcall.params,dir);
      break;


    case E_SLI_EXTEND:
      check_for_variable (l->data.s_select_list_item_data_u.extend.expr,dir);
      break;

    case E_SLI_SUBQUERY_EXPRESSION:
      check_for_variable (l->data.s_select_list_item_data_u.sq_expression.sq,dir);
      break;

    case E_SLI_CAST_EXPR:
      check_for_variable (l->data.s_select_list_item_data_u.casting.expr,dir);
      break;




    default: break;

}


}


// This function is used by INSERT,UPDATE And DELETE to find any embedded variables usages (E_SLI_VARIABLE_USAGE)
// and replace them with proper variable subsitutions as required...
void
search_sql_variables (struct s_select_list_item_list *l,char dir)
{
  int a;
  if (l == 0)
    return;

  for (a = 0; a < l->list.list_len; a++)
    {
	check_for_variable(l->list.list_val[a],dir);
    }
}




static char *get_select_list_item_list_with_separator (struct s_select *select, struct s_select_list_item_list *slist, char *sep)
{
  int a;
  char *rval;
  if (slist == 0)
    return "";

  for (a = 0; a < slist->list.list_len; a++)
    {
      if (a) {
		rval=make_sql_string_and_free(rval, strdup(sep), strdup(get_select_list_item (select, slist->list.list_val[a])),NULL);
	} else {
		rval=strdup(get_select_list_item (select, slist->list.list_val[a]));
	}
    }
    return rval;
}




//
// This function checks for the usage of variables in the select list
// eg
//
// DEFINE a INTEGER
//
//   SELECT a*b FROM sometab
//
//   as this isn't portable and causes issues with some esql/c generation..
//
int chk_ibind_select_internal(struct s_select *s) {
int a;
int ok=1;
struct s_select snew;
//struct s_select_list_item_list *slist;
struct s_select_list_item *ptr;
struct s_select *next;
memcpy(&snew,s,sizeof(snew));
snew.list_of_items.list.list_len=0;
snew.list_of_items.list.list_val=0;
snew.where_clause=0;
snew.having=0;
snew.group_by=0;
next=snew.next;
snew.next=0;

preprocess_sql_statement (&snew);

if (next) {
	if (!chk_ibind_select_internal(next)) {
		ok=0;
	}
}


for (a=0;a<snew.list_of_items.list.list_len;a++) {
	ptr=snew.list_of_items.list.list_val[a];

	if (ptr->data.type==E_SLI_VARIABLE_USAGE) {
		//printf("%s\n",generation_get_variable_usage_as_string (ptr->data.s_select_list_item_data_u.var_usage));
		ptr->data.type=E_SLI_VARIABLE_USAGE_IN_SELECT_LIST;
		ok=0;
	}

}

return ok;
}


int chk_ibind_select(struct s_select *s) {
	if (!chk_ibind_select_internal(s)) {
        	if (!A4GL_isno(acl_getenv("NOSELECTVARWARNING"))) {
                	a4gl_yyerror("You can't SELECT a variable (perhaps you could rename the variable, or prefix the column in the SELECT list ?)");
        	} else {
                	A4GL_warn("Selecting a variable in a select list is not portable");
        	}
	return 0;
	}
        return 1;
}



char *
get_select (struct s_select *s, char *forUpdate)
{
  char *str;
  char *ptr;
  char into_buff[65000] = "";

  if (forUpdate == 0)
    forUpdate = "";

  if (s->into)
    {
	strcpy(into_buff, get_sql_into_buff(s->into));
        //sprintf (into_buff, "\nINTO %s\n", local_get_expr_as_string_list_with_separator (s->into, ","));
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
  return lowlevel_chk_sql(ptr);
}




char *
get_insert_cmd (struct struct_insert_cmd *insertCmd,int *converted)
{
  static char buff[64000];
  char *ptr;
  char smbuff[256];
  *converted=0;


  sprintf (smbuff, "INSERT INTO %s ", insertCmd->table);
  if (insertCmd->column_list)
    {
	sprintf(buff,"%s(%s) ", smbuff, get_str_list_as_string(insertCmd->column_list,","));
    } else {
	strcpy(buff, smbuff);
    }

  // Collect all our inbinds..
  if (insertCmd->value_list)
    {
      search_sql_variables (insertCmd->value_list,'i');
    }
  else
    {
      preprocess_sql_statement (insertCmd->subselect);
      search_sql_variables (&insertCmd->subselect->list_of_items,'i');
    }

  if (insertCmd->value_list)
    {
	char *p;
	//char *p2;
	p=get_select_list_item_list_with_separator (NULL, insertCmd->value_list, ",\n   ");
	A4GL_assertion(p==0,"No values list!");
	strcat(buff,"VALUES (\n   ");
	strcat(buff,p);
	strcat(buff,")");
    }
  else
    {
      strcat(buff,get_select (insertCmd->subselect, ""));
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

return strdup(ptr);
}

char *get_update_cmd(struct struct_update_cmd *updateCmd, int *converted) {
	int a;
	char *rval;
	//struct struct_update_cmd *u;
	struct s_select fake_select;
	//struct s_select_list_item_list l;
	struct s_table t;
	char *ptr;
static char buff[64000];
char smbuff[2000];

      *converted=0;
strcpy(buff,"");

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
	search_sql_variables (&fake_select.list_of_items,'i');

	sprintf(buff,"UPDATE %s SET ",updateCmd->table);
	A4GL_assertion (updateCmd->value_list == 0, "No value list");

	if (updateCmd->column_list==0) {
		A4GL_warn("UPDATE * is not portable when the table does not exist in the database at compile time");
		strcat(buff,"*=(");

	    // Same length..
	    for (a = 0; a < updateCmd->value_list->list.list_len; a++)
	      {
		char commabuff[2]=",";

		if (a==updateCmd->value_list->list.list_len-1)
		  {
			strcpy(commabuff,"");
		  }
		rval = get_select_list_item (0, updateCmd->value_list->list.list_val[a]);
		sprintf (smbuff, "%s%s\n", rval, commabuff);
		strcat(buff,smbuff);
		free (rval);
	      }
		strcat(buff,")");
	} else {



	if (updateCmd->value_list->list.list_len == updateCmd->column_list->str_list_entry.str_list_entry_len)
	  {
	    // Same length..
	    for (a = 0; a < updateCmd->value_list->list.list_len; a++)
	      {
		if (a)
		  {
			strcat(buff,",");
		  }
		rval = get_select_list_item (0, updateCmd->value_list->list.list_val[a]);
		sprintf (smbuff, "%s=%s\n", updateCmd->column_list->str_list_entry.str_list_entry_val[a], rval);
		strcat(buff,smbuff);
		free (rval);
	      }
	  }
	else
	  {
		strcat(buff,"(");
	    for (a = 0; a < updateCmd->column_list->str_list_entry.str_list_entry_len; a++)
	      {
		if (a) {
			strcat(buff,",\n");
		}
		strcat(buff, updateCmd->column_list->str_list_entry.str_list_entry_val[a]);
	      }
	    strcat (buff, ")=(");
	    for (a = 0; a < updateCmd->value_list->list.list_len; a++)
	      {
		if (a) {
			strcat(buff,",\n");
		}
		rval = get_select_list_item (0, updateCmd->value_list->list.list_val[a]);
		strcat(buff,rval);
		free (rval);
	      }
		strcat(buff,")");

	  }
        }

	if (updateCmd->where_clause)
	  {
	    if (updateCmd->where_clause->expr_type == ET_EXPR_WHERE_CURRENT_OF)
	      {
		struct expr_str *e;
		strcat (buff, " WHERE CURRENT OF ");
		e=updateCmd->where_clause->expr_str_u.expr_expr;
		A4GL_assertion(e->expr_type!=ET_EXPR_IDENTIFIER,"Expecting an identifier");
		strcat(buff,e->expr_str_u.expr_string);
		//strcat(buff,get_ident_as_string(updateCmd->where_clause->expr_str_u.expr_expr));
	      }
	    else
	      {
		strcat(buff," WHERE ");
			strcat(buff, get_select_list_item (&fake_select,
					      updateCmd->where_clause->expr_str_u.sl_item));
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
return strdup(ptr);
}

char * get_delete_cmd (struct struct_delete_cmd *deleteCmd, int *converted) {
char topbuff[64000]="";
char smbuff[64000]="";
char *ptr;


      *converted=0;

      sprintf (topbuff, "DELETE FROM %s", deleteCmd->table);

      if (deleteCmd->where_clause != NULL)
	{

	  if (deleteCmd->where_clause->expr_type == ET_EXPR_WHERE_CURRENT_OF)
	    {
		//char buff[2000];
		if (deleteCmd->where_clause->expr_str_u.expr_expr->expr_type==ET_EXPR_VARIABLE_IDENTIFIER) {
			yylineno=line_for_cmd;
			a4gl_yyerror("You cant use a variable id in this position...");
			return "<badsql>";
		} else {
			//printf("decode=%s\n", decode_e_expr_type(deleteCmd->where_clause->expr_str_u.expr_expr->expr_type));	
			sprintf(smbuff," WHERE CURRENT OF %s",deleteCmd->where_clause->expr_str_u.expr_expr->expr_str_u.expr_string);
		}
		/*
		if (deleteCmd->where_clause->expr_str_u.expr_type==ET_EXPR_
      		ptr = A4GLSQLCV_check_sql (topbuff, converted);
		strcpy(topbuff,buff);
		sprintf(buff,
		strcpy(topbuff,"_r");
		*/

		
		//,get_ident_as_string (deleteCmd->where_clause->expr_str_u.expr_expr));
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
	      search_sql_variables (&fake_select.list_of_items,'i');

	      sprintf (smbuff, " WHERE %s", get_select_list_item (&fake_select, deleteCmd->where_clause->expr_str_u.sl_item));

   }
	strcat(topbuff,smbuff);
  }



  if (A4GL_compile_time_convert ())
    {
      ptr = A4GLSQLCV_check_sql (topbuff, converted);
    }
  else
    {
      ptr = topbuff;
    }
return strdup(ptr);
}



char *escape_quotes_and_remove_nl(char *s) {
static char *buffer=0;
static int oldlen=0;
int a;
int b=0;
int newlen;
newlen=strlen(s)*2+1;
if (newlen>oldlen) {
        oldlen=newlen;
        buffer=realloc(buffer,newlen);
}
for (a=0;a<strlen(s);a++) {
      if (s[a] == '"')
        {
          buffer[b++] = '\\';
        }
        if (s[a]=='\n') {if (buffer[b-1]==' ' || s[a+1]==' ') {continue;} buffer[b++]=' '; continue;}

        buffer[b++]=s[a];
}
buffer[b]=0;
return buffer;
}



struct command *get_last_cmd(void ) {
	return last_cmd;
}



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
# | contact afalout@ihug.co.nz                                           |
# +----------------------------------------------------------------------+
#
# $Id: compile_c.c,v 1.393 2008-02-12 17:01:07 mikeaubury Exp $
# @TODO - Remove rep_cond & rep_cond_expr from everywhere and replace
# with struct expr_str equivalent
*/
#ifndef lint
	static char const module_id[] =
		"$Id: compile_c.c,v 1.393 2008-02-12 17:01:07 mikeaubury Exp $";
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

#define FGL_PLUS_PLUS
#define set_nonewlines() set_nonewlines_full(__LINE__)
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
char this_module_name[256];
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
static void A4GL_internal_lex_printc (char *fmt, va_list * ap);
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
//char *get_variable_usage_as_string(struct variable_usage *u ) ;
/*
=====================================================================
                    Variables definitions
=====================================================================
*/

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
}



void
set_nonewlines_full (long l)
{
  if (new_lines == 0)
    {
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
  //int a;
  //int cnt;
  int ok;
  //int need_err_chk = 1;
  A4GL_assertion (r->module == 0, "No module");
  //printf ("Dumping command type : %d (%s %d)\n", r->cmd_data.type, r->module, r->lineno);
  A4GL_debug ("Dumping command type : %d (%s %d)\n", r->cmd_data.type, r->module, r->lineno);


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
  return ok;
}


#ifdef NOT_REQUIRED
static int is_just_expr_clipped(struct expr_str *v,struct expr_str_list *ptr) {
	struct expr_str *p;
	if (ptr->list.list_len!=1) {
		return 0;
	}
	p=ptr->list.list_val[0];

	if (p->expr_type==ET_EXPR_OP_CLIP) {
		p=p->expr_str_u.expr_expr;
		if (p->expr_type==ET_EXPR_VARIABLE_USAGE) { //@FIXME
			A4GL_assertion(1,"Fix checking if a variable usage is just clipped..");
			//if (strcmp(p->expr_str_u.expr_push_variable->variable,v)==0) {
				//return 1;
			//}
		}

	}
	return 0;

}
#endif

#ifdef NOT_REQUIRED
static char *starts_with_single_string(struct expr_str_list *ptr) {
        struct expr_str *p;
        int a;
        char *buff=0;
        // LAST_STRING <- USE TO SEARCH...!

        if (ptr->list.list_len==1) {
                p=ptr->list.list_val[0];
                if (p->expr_type==ET_EXPR_VARIABLE_USAGE)        { return "Yes"; }
                if (p->expr_type==ET_EXPR_LITERAL_STRING)       { return p->expr_str_u.expr_string; }
                if (p->expr_type==ET_EXPR_LITERAL_EMPTY_STRING) { return ""; }
        }

        for (a=0;a<1;a++) {
                p=ptr->list.list_val[a];

                if (p->expr_type==ET_EXPR_OP_CLIP) {
                        p=p->expr_str_u.expr_expr; // We'll ignore any clipping for the sake of determining if its a single string...
                }

                if (p->expr_type==ET_EXPR_OP_USING) {
                        p=p->expr_str_u.expr_op->left; // We'll ignore any USING string and just use it as is..
                }

                if (p->expr_type==ET_EXPR_LITERAL_STRING) {
                        if (buff) {
                                        buff=realloc(buff,(strlen(buff)+strlen(p->expr_str_u.expr_string)+1));
                                        strcat(buff,p->expr_str_u.expr_string);
                        } else {
                                buff=strdup(p->expr_str_u.expr_string);
                        }
                        continue;
                }

                if (p->expr_type==ET_EXPR_VARIABLE_USAGE) {
                        // If we're using variables here - we really ought to store them somewhere
                        // as we're replacing them with a '?'
                        return 0;
			
                }

                //printf("Nope - %d. %d %s\n",a,p->expr_type,expr_name(p->expr_type));
                return 0;
        }

        return buff;
}
#endif

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

#ifdef OBSOLETE
static char *is_single_string(struct expr_str_list *ptr) {
	struct expr_str *p;
	int a;
	char *buff=0;
	// LAST_STRING <- USE TO SEARCH...!

	if (ptr->list.list_len==1) { 
		p=ptr->list.list_val[0];
		if (p->expr_type==ET_EXPR_VARIABLE_USAGE) 	{ return "Yes"; }
		if (p->expr_type==ET_EXPR_LITERAL_STRING) 	{ return p->expr_str_u.expr_string; }
		if (p->expr_type==ET_EXPR_LITERAL_EMPTY_STRING) { return ""; }
	}

	for (a=0;a<ptr->list.list_len;a++) {
		p=ptr->list.list_val[a];

		if (p->expr_type==ET_EXPR_OP_CLIP) {
			p=p->expr_str_u.expr_expr; // We'll ignore any clipping for the sake of determining if its a single string...
		}

		if (p->expr_type==ET_EXPR_OP_USING) {
			p=p->expr_str_u.expr_op->left; // We'll ignore any USING string and just use it as is..
		}

		if (p->expr_type==ET_EXPR_LITERAL_STRING) {
			if (buff) {
					buff=realloc(buff,(strlen(buff)+strlen(p->expr_str_u.expr_string)+1));
					strcat(buff,p->expr_str_u.expr_string);
			} else {
				buff=strdup(p->expr_str_u.expr_string);
			}
			continue;
		}

		if (p->expr_type==ET_EXPR_VARIABLE_USAGE) {
			// If we're using variables here - we really ought to store them somewhere
			// as we're replacing them with a '?'
			return 0;
		}
		
		//printf("Nope - %d. %d %s\n",a,p->expr_type,expr_name(p->expr_type));
		return 0; 
	}

	return buff;
}
#endif





static void
open_outfile (void)
{
  char err[132];
  char *ptr;
  char *outputfilename;
  char *override;
  override = acl_getenv_not_set_as_0 ("OVERRIDE_OUTPUT");
  outputfilename = current_module->module_name;


  if (this_module_name == 0)
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


  outfile = A4GL_mja_fopen (filename_for_c, "w");
  if (outfile == 0)
    {
      printf ("Unable to open file %s (Check permissions)\n", filename_for_c);
      exit (3);
    }

  A4GL_debug ("Output file is %s", filename_for_c);

  FPRINTF (outfile, "#define fgldate long\n");
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
  A4GL_internal_lex_printc (fmt, &ap);
}


#ifdef V1
void A4GL_internal_lex_printc (char *fmt, va_list * ap)
{
  static char buff[40960] = "ERROR-empty init";
  //static char buff2[40960];
  char *ptr;
  int a;
int os;

  if (outfile == 0)
    {
		A4GL_assertion(1,"No output file");
    }

  os=VSNPRINTF (buff, sizeof(buff),fmt, *ap);
  if (strcmp (buff, "#") == 0)
    {
      FPRINTF (outfile, "\n");
      return;
    }

if (os>=sizeof(buff)) {
			yylineno=line_for_cmd;
	a4gl_yyerror("Internal error - string too big\n");
	exit(0);
} 



  if (A4GL_isyes (acl_getenv ("INCLINES")))
    {
      static int last_line=-1;
	  int lastwas=0;
     
      for (a = 0; a < strlen (buff); a++)
	{
	  if (buff[a] == '\n' )
	    {
		lastwas=1;
		if (suppress_lines==0 && strstr(buff,"EXEC SQL")==0) {
			if (new_lines==0) { 
				FPRINTF (outfile, "\n#line %d \"%s.4gl\"\n", curr_lineno, this_module_name); 
			}
		} else {
			if (new_lines==0) { 
	      			FPRINTF (outfile, "\n");
			}
		}
	    }
	  else
	    {
		lastwas=0;
	      FPRINTF (outfile, "%c", buff[a]);
	    }
	}
	if (!lastwas && strlen(buff)>1) {
		
	      FPRINTF (outfile, "\n");
		}
    }
  else
    {
	int looped=0;
      ptr = strtok (buff, "\n");

      while (ptr)
        {
		
          if (new_lines == 0) {
			print_space ();
	  }
          if (new_lines == 0)
            {
              		FPRINTF (outfile, "%s\n", ptr);
            }
          else {
		if (looped) {
            		FPRINTF (outfile, " %s", ptr);
		} else {
            		FPRINTF (outfile, "%s", ptr);
		}
	  }
	looped++;
          ptr = strtok (0, "\n");
        }

    }

  /* Having this will really slow it down - only enable it if we are debugging... */
  if (strcmp (acl_getenv ("DEBUG"), "ALL") == 0) {
    fflush (outfile);
  }
}

#endif




static void
A4GL_internal_lex_printc (char *fmt, va_list * ap)
{
  static char buff[40960] = "ERROR-empty init";
  //static char buff2[40960];
  char *ptr;
  int a;
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
	yylineno=line_for_cmd; a4gl_yyerror ("Internal error - string too big\n");
      exit (0);
    }


  if (strcmp (buff, "#") == 0)
    {
      FPRINTF (outfile, "\n");
      return;
    }

  if (A4GL_isyes (acl_getenv ("INCLINES")))
    {
      static int last_line = -1;

      for (a = 0; a < strlen (buff); a++)
	{
	  if (buff[a] == '\n')
	    {
	      if (suppress_lines == 0 && strstr (buff, "EXEC SQL") == 0)
		{
		  last_line = line_for_cmd;
		  if (current_module && current_module->module_name!= 0)
		    {
		      FPRINTF (outfile, "\n#line %d \"%s.4gl\"\n", line_for_cmd, current_module->module_name);
		    }
		  else
		    {
		      FPRINTF (outfile, "\n#line %d \"null\"\n", line_for_cmd);	/* curr_infilename); */
		    }
		}
	      else
		{
		  if (new_lines == 0)
		    {
		      FPRINTF (outfile, "\n");
		    }
		}
	    }
	  else
	    {
	      FPRINTF (outfile, "%c", buff[a]);
	    }
	}
    }
  else
    {
      ptr = strtok (buff, "\n");
      while (ptr)
	{
	  if (new_lines == 0)
	    print_space ();
	  if (new_lines == 0)
	    {
	      FPRINTF (outfile, "%s\n", ptr);
	    }
	  else
	    FPRINTF (outfile, "%s", ptr);
	  ptr = strtok (0, "\n");
	}
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
  if (addit) printc("A4GL_%spop_report_section(&_rep,%d);",ispdf (), rep_print_code++);
  printc ("goto report%d_ctrl; /* G1 */\n\n", report_cnt);
}


void print_report_2_1() {
	// Does nothing in this output module - needed by API
}


#ifdef MOVED
/**
 * Called by print_report_2() generate the C code taht implements the 
 * assignments that should be done when an output to report is executed.
 *
 * This implementation is specific for text only reports.
 *
 * @param rep The report control structure.
 */
static void print_output_rep (struct rep_structure *rep, int report_cnt,char *curr_rep_name)
{
  printc ("output_%d:\n", report_cnt);
  printc ("_rep.lines_in_header=-1;\n");
  printc ("_rep.lines_in_trailer=-1;\n");
  printc ("_rep.lines_in_first_header=-1;\n");
  printc ("_rep.print_section=0;\n");
  printc ("_rep.top_margin= A4GL_set_report_dim_int(\"TOP MARGIN\",%d);\n", rep->top_margin);
  printc ("_rep.bottom_margin= A4GL_set_report_dim_int(\"BOTTOM MARGIN\",%d);\n", rep->bottom_margin);
  printc ("_rep.left_margin= A4GL_set_report_dim_int(\"LEFT MARGIN\",%d);\n", rep->left_margin);
  printc ("_rep.right_margin= A4GL_set_report_dim_int(\"RIGHT MARGIN\",%d);\n", rep->right_margin);

  printc ("_rep.page_length= A4GL_set_report_dim_int(\"PAGE LENGTH\",%d);\n", rep->page_length);

  if (rep->top_of_page &&strlen(rep->top_of_page)) {
	  printc ("strcpy(_rep.top_of_page, %s);", rep->top_of_page); 
  } else {
	  printc ("strcpy(_rep.top_of_page, \"\");", rep->top_of_page); 
  }

  printc ("_rep.header=0;\n");
  printc ("_rep.finishing=0;\n");
  printc ("_rep.nblocks=0;\n");
  printc ("_rep.blocks=0;\n");
  printc ("_rep.repName=_reportName;\n");
  printc ("_rep.modName=_module_name;\n");
  printc ("_rep.page_no=%d;\n", rep->page_no);
  printc ("_rep.printed_page_no=%d;\n", rep->printed_page_no);
  printc ("_rep.line_no=%d;\n", rep->line_no);
  printc ("_rep.col_no=%d;\n", rep->col_no);
  printc ("if (strlen(_rout2)==0)\n");
  printc ("strcpy(_rep.output_loc_str,%s);\n", rep->output_loc);
  printc ("else strcpy(_rep.output_loc_str,_rout2);\n");
  printc ("if (strlen(_rout1)==0)\n");
  printc ("_rep.output_mode='%c';\n", rep->output_mode);
  printc ("else _rep.output_mode=_rout1[0];\n");
  if (A4GL_doing_pcode()) {
  	printc ("_rep.report=0;\n", curr_rep_name );
  } else {
  	printc ("_rep.report=(void *)&%s;\n", curr_rep_name );
  }
  printc ("A4GL_trim(_rep.output_loc_str);");
  printc ("A4GL_%srep_print(&_rep,-1,-1,-1,-1);",ispdf());
  print_rep_ret (report_cnt,0);
}
#endif


#ifdef MOVED
/**
 * Called by print_report_2() generate the C code taht implements the
 * assignments that should be done when an output to report is executed.
 *
 * This implementation is specific for pdf reports only.
 *
 * @param rep The report control structure.
 */
static void
pdf_print_output_rep (struct pdf_rep_structure *rep, int report_cnt,char * curr_rep_name)
{
  printc ("output_%d:\n", report_cnt);
  printc ("strcpy(_rep.font_name,%s);\n", rep->font_name);
  printc ("_rep.font_size=%f;\n", rep->font_size);
  printc ("_rep.paper_size=%d;\n", rep->paper_size);
  printc ("_rep.header=0;\n");
  printc ("_rep.lines_in_header=-1;\n");
  printc ("_rep.lines_in_trailer=-1;\n");
  printc ("_rep.lines_in_first_header=-1;\n");
  printc ("_rep.print_section=0;\n");
  printc ("_rep.finishing=0;\n");
  printc ("_rep.nblocks=0;\n");
  printc ("_rep.blocks=0;\n");
  printc ("_rep.repName=_reportName;\n");
  printc ("_rep.modName=_module_name;\n");

  printc ("_rep.top_margin=A4GL_pdf_size(%f,'l',&_rep);\n", rep->top_margin);
  printc ("_rep.bottom_margin=A4GL_pdf_size(%f,'l',&_rep);\n",
	  rep->bottom_margin);
  printc ("_rep.page_length=A4GL_pdf_size(%f,'l',&_rep);\n", rep->page_length);
  printc ("_rep.left_margin=A4GL_pdf_size(%f,'c',&_rep);\n", rep->left_margin);
  printc ("_rep.right_margin=A4GL_pdf_size(%f,'c',&_rep);\n",
	  rep->right_margin);
  printc ("_rep.page_width=A4GL_pdf_size(%f,'c',&_rep);\n", rep->page_width);

  printc ("_rep.page_no=%d;\n", rep->page_no);
  printc ("_rep.printed_page_no=%d;\n", rep->printed_page_no);

  printc ("_rep.line_no=%f;\n", rep->line_no);
  printc ("_rep.col_no=%f;\n", rep->col_no);

  printc ("if (strlen(_rout2)==0)\n");
  printc ("strcpy(_rep.output_loc_str,%s);\n", rep->output_loc);
  printc ("else strcpy(_rep.output_loc_str,_rout2);\n");
  printc ("if (strlen(_rout1)==0)\n");
  printc ("_rep.output_mode='%c';\n", rep->output_mode);
  printc ("else _rep.output_mode=_rout1[0];\n");
  printc ("_rep.report=(void *)&%s;\n", curr_rep_name );
  printc ("A4GL_trim(_rep.output_loc_str);");
  print_rep_ret (report_cnt,0);
}
#endif

/*
static void pr_report_agg_clr (void)  {
A4GL_assertion(1,"FIXME");
}
*/

/*
static void
pr_nongroup_report_agg_clr (void)
{
A4GL_assertion(1,"FIXME");
}
*/

#ifdef NEEDS_REPLACING
/**
 * Prints the generated C code that implements the AFTER GROUP(s) actions
 */
static void
pr_report_agg (int sreports_cnt)
{
  int z;
  int a;
  int t;
/*
  char s1[5024];
  char s2[5024];
*/


  for (z = 0; z < sreports_cnt; z++)
    {

      /*strcpy (s2, sreports[z].rep_cond);*/
      /*strcpy (s1, sreports[z].rep_expr);*/

      a = sreports[z].a;
      t = sreports[z].t;

#ifdef DEBUG
      A4GL_debug ("pr_report_agg - %c %d z=%d\n", t, a, z);
#endif


      if (t == 'C') /* Count */
	{
	  print_expr (sreports[z].rep_where_expr);
	  printc ("if (A4GL_pop_bool()) _g%d++;\n", a);
	}

      if (t == 'P') /* Percent */
	{
	  printc ("_gpc%d++;", a);
	  print_expr (sreports[z].rep_where_expr);
	  printc (" if (A4GL_pop_bool()) _g%d++; \n", a);
	}

      if (t == 'S') /* SUM */
	{
	  print_expr (sreports[z].rep_where_expr);
	  printc ("if (A4GL_pop_bool()) {double _res;");
	  print_expr (sreports[z].rep_cond_expr);
  	  printc ("A4GL_set_agg('S',&_gt_%d,&_g%d,&_g%dused);",a,a,a);
	  printc("}");
		/*
 	  	if (A4GL_doing_pcode()) {
	 		printc ("A4GL_pop_into_double_null_as_zero(&_res);");
	  	} else {
	  		printc ("_res=A4GL_pop_double_null_as_zero();");
	  	}
		*/

	  //printc ("_g%dused++; _g%d+=_res;}\n ", a,a);
	}

      if (t == 'A') /* Average */
	{
	  print_expr (sreports[z].rep_where_expr);
	  printc ("if (A4GL_pop_bool()) {");
	  print_expr (sreports[z].rep_cond_expr);
  	  printc ("A4GL_set_agg('A',&_gt_%d,&_g%d,&_gavg%d);",a,a,a);
	  printc("}");
	  //printc ("if (!A4GL_isnull(3,&_res)) { _g%d+=_res;_g%d++;}}\n", a, a + 1);
	}

      if (t == 'N') /* Min */
	{
	  print_expr (sreports[z].rep_where_expr);
	  printc ("if (A4GL_pop_bool()) {double _res;");
	  print_expr (sreports[z].rep_cond_expr);
  	  printc ("A4GL_set_agg('N',&_gt_%d,&_g%d,&_g%dused);",a,a,a);
	  printc("}");

	/*
 	  if (A4GL_doing_pcode()) {
	  	printc ("A4GL_pop_double_into(&_res); ");
	  } else {
	  	printc ("_res=A4GL_pop_double();");
	  }
	  printc ("if (_res<_g%d||_g%dused==0) {_g%d=_res;_g%dused=1;}}\n", a, a, a, a);
	*/
	}

      if (t == 'X') /* Max */
	{
	  print_expr (sreports[z].rep_where_expr);
	  printc ("if (A4GL_pop_bool()) {double _res;");
	  print_expr (sreports[z].rep_cond_expr);
  	  printc ("A4GL_set_agg('X',&_gt_%d,&_g%d,&_g%dused);",a,a,a);
	  printc("}");
	/*
 	  if (A4GL_doing_pcode()) {
	  	printc ("A4GL_pop_double_into(&_res); ");
	  } else {
	  	printc ("_res=A4GL_pop_double();");
	  }
	  printc ("if (_res>_g%d||_g%dused==0) {_g%d=_res;_g%dused=1;}}\n", a, a, a, a);
		*/
	}

    }
}

static void
pr_nongroup_report_agg_clr (void)
{
  int z;
  int a;
  int t;
  int in_b;
  char b[255];
  for (z = 0; z < sreports_cnt; z++)
    {
      a = sreports[z].a;
      t = sreports[z].t;
      SPRINTF1(b,"%d",sreports[z].in_b);
      in_b = gen_ord(b);
      
      if (in_b == 0)
	{
	  if (t == 'C' || t == 'N' || t == 'X' || t == 'S')
	    {
	      printc ("_g%d=0;\n", a);
	    }

	  if (t == 'N' || t == 'X' || t=='S')
	    {
	      printc ("_g%dused=0;\n", a);
	    }

	  if (t == 'P' ) { printc ("_g%d=0;_gpc%d=0;\n", a , a); }
	  if (t == 'A') { printc ("_g%d=0;_gavg%d=0;\n", a , a); }
	}
    }
}


/**
 * Generate the C code to clear the report agregate conditions.
 */ 
static void 
pr_report_agg_clr (void) 
{
  int z;
  int a;
  int t;
  int in_b;
  char b[255];
  for (z = 0; z < sreports_cnt; z++)
    
    {
      a = sreports[z].a;
      t = sreports[z].t;
      SPRINTF1 (b, "%d", sreports[z].in_b);
      in_b = gen_ord (b);
      if (in_b > 0)
	
	{
	  printc ("if (_nargs==-%d&&acl_ctrl==REPORT_AFTERGROUP) {\n", in_b);

	  if (t == 'C' || t == 'N' || t == 'X' || t == 'S')
	    
	    {
	      if (t == 'C') 
		{
		  printc ("_g%d=0;\n", a, a);
		} else {
		  printc ("A4GL_init_agg(&_g%d,_gt_%d);\n", a, a);
		}
	    }

	  if (t == 'N' || t == 'X' || t == 'S')
	    
	    {
	      printc ("_g%dused=0;\n", a);
	    }

	  if (t == 'P')
	    {
	      printc ("_gpc%d=0;", a );
	      printc ("_g%d=0;\n", a);
	    }

	  if (t == 'A')
	    {
	      printc ("A4GL_init_agg(&_g%d,_gt_%d);\n", a, a);
	      printc ("_gavg%d=0;", a );
	    }

	  printc ("}\n");
	}
    }
}
#endif


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
	  	printc ("A4GL_pushop(OP_IN);",ptr->expr_str_u.expr_in->elist->list.list_len);
	  break;
	case ET_EXPR_OP_NOT_IN:
	  	real_print_expr (ptr->expr_str_u.expr_in->expr);
		for (a=0;a<ptr->expr_str_u.expr_in->elist->list.list_len;a++) {
	  			real_print_expr (ptr->expr_str_u.expr_in->elist->list.list_val[a]);
		}
	  	printc ("A4GL_push_int(%d);",ptr->expr_str_u.expr_in->elist->list.list_len);
	  	printc ("A4GL_pushop(OP_NOTIN);",ptr->expr_str_u.expr_in->elist->list.list_len);
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
	      printc ("A4GL_%sset_column(&_rep);", ispdf ());
	    }
	  else
	    {
	      printc ("A4GL_ensure_column();");
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
	  printc ("A4GL_push_double(-28.3465);A4GL_pushop(OP_MULT);");
	  break;
	case ET_EXPR_INCHES:
	  real_print_expr (ptr->expr_str_u.expr_expr);
	  printc ("A4GL_push_double(-72.0);A4GL_pushop(OP_MULT);");
	  break;
	case ET_EXPR_POINTS:
	  real_print_expr (ptr->expr_str_u.expr_expr);
	  printc ("A4GL_push_double(-1);A4GL_pushop(OP_MULT);");
	  break;

	case ET_EXPR_PAGENO:
	  printc ("A4GL_push_long(_rep.page_no + (_rep.line_no > _rep.page_length ? 1 : 0));");
	  break;
	case ET_EXPR_LINENO:
	  printc
	    ("{static long _ln; _ln=A4GL_report_lineno(&_rep);A4GL_push_long(_ln);}");
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
		printc ("ECALL(\"%s%s\",%d,%ld);",
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
		    printc ("_retvars=A4GL_call_4gl_dll(%s,\"%s\",%ld); ",
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
		    printc ("_retvars=%s%s(%ld); ",
			    get_namespace (ptr->expr_str_u.expr_function_call->
					   fname),
			    ptr->expr_str_u.expr_function_call->fname, params);
		    printc ("{");
		    printc ("if (_retvars!= 1 && a4gl_status==0 ) {");
		    printc ("A4GLSQL_set_status(-3001,0);");
		    printc ("A4GL_chk_err(%d,_module_name);",
			    ptr->expr_str_u.expr_function_call->line);
		    printc ("}");
		    printc ("}");
		    if (strcmp(ptr->expr_str_u.expr_function_call->fname,"set_count")!=0) { printc ("%s", get_reset_state_after_call (0)); }
		    printc ("} // FCALL 2");
		  }
		add_function_to_header (ptr->expr_str_u.expr_function_call->fname, ptr->expr_str_u.expr_function_call->namespace,
					1, 0);
	      }

  		if (is_in_report()) { clr_doing_a_report_call(1); }
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
	      printc ("  if (_retvars!=1) {", p->lib, p->fname,
		      A4GL_new_list_get_count (p->parameters));
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
		A4GL_assertion(1,"Not implemented yet");
#ifdef FIXME
	      int a;
	      struct expr_str_list *l;
	      struct s_expr_member_function_call *p;
	      if (ptr)
		{
		  p = ptr->expr_str_u.expr_member_function_call;
		  l = p->parameters;
		  if (l)
		    {
		      for (a = 0; a < l->list.list_len; a++)
			{
			  real_print_expr (l->list.list_val[a]);
			}
		    }
		}
	      printc ("{");
	      printc ("      int _retvars;");

  	      printc ("_retvars=A4GL_call_datatype_function_i(&%s,%d,\"%s\",%d);\n", p->lib, scan_variable (p->lib), p->fname, A4GL_new_list_get_count (p->parameters));

	      printc ("      if (_retvars!=1) {");
	      printc ("          A4GLSQL_set_status(-3001,0);");
	      printc ("          A4GL_chk_err(%d,\"%s\");", p->line, p->module);
	      printc ("          A4GL_pop_args(_retvars);");
	      printc ("          A4GL_push_null(2,0);");
	      printc ("      }");
	      printc ("}");
	    }
#endif
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
	  printc ("A4GL_push_long(%d);", ptr->expr_str_u.expr_long);
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
	  	A4GL_assertion(1,"CASE NOT IMPLEMENTED YET"); break;


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
			printc("A4GL_pushint_fgl_infield(_sio_%d,_inp_io_type,%s,NULL,0);",ptr->expr_str_u.expr_infield->sio_id,local_field_name_list_as_char(ptr->expr_str_u.expr_infield->field_list));
		} else {
			printc("A4GL_pushint_fgl_infield(NULL,0,%s,NULL,0);",local_field_name_list_as_char(ptr->expr_str_u.expr_infield->field_list));
		}
		} else {
		if (ptr->expr_str_u.expr_infield->sio_id!=-1) {
			printc("A4GL_push_int(A4GL_fgl_infield(_sio_%d,_inp_io_type,%s,NULL,0));",ptr->expr_str_u.expr_infield->sio_id,local_field_name_list_as_char(ptr->expr_str_u.expr_infield->field_list));
		} else {
			printc("A4GL_push_int(A4GL_fgl_infield(NULL,0,%s,NULL,0));",local_field_name_list_as_char(ptr->expr_str_u.expr_infield->field_list));
		}
		}
	  	break;


	case ET_EXPR_TEMP:
			A4GL_assertion(1,"Not used for ESQL/C");
			break;

	case ET_EXPR_FIELD_TOUCHED:
		printc("A4GL_push_int(A4GL_fgl_fieldtouched(_sio_%d,_inp_io_type,%s,NULL,0));",ptr->expr_str_u.expr_field_touched->sio_id,local_field_name_list_as_char(ptr->expr_str_u.expr_field_touched->field_list));
		break;

	case ET_EXPR_NOT_FIELD_TOUCHED:
		printc("A4GL_push_int(!A4GL_fgl_fieldtouched(_sio_%d,_inp_io_type,%s,NULL,0));",ptr->expr_str_u.expr_field_touched->sio_id,local_field_name_list_as_char(ptr->expr_str_u.expr_field_touched->field_list));
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


	case ET_EXPR_GET_FLDBUF: 
	  printc ("{");
	  printc ("int _retvars;");

	  printc ("_retvars=A4GL_fgl_getfldbuf(_sio_%d,_inp_io_type,%s,NULL,0);",
		  ptr->expr_str_u.expr_get_fldbuf->sio_id,
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
int frm_attr;
//char buff[256];

if (form_attrib==0) {
	printc("%d,255,255,255,255,0,255,255,(0xffff)", iswindow);
	return;
}

	frm_attr=attributes_as_int(form_attrib);

  printc ("%d,%s,%s,%s,%s,%d,%s,%s,%d",
	  iswindow,
	  form_attrib->form_line? local_expr_as_string(form_attrib->form_line):"255",
	  form_attrib->error_line?local_expr_as_string(form_attrib->error_line):"255",
	  form_attrib->prompt_line?local_expr_as_string(form_attrib->prompt_line):"255",
	  form_attrib->menu_line?local_expr_as_string(form_attrib->menu_line):"255",
	  form_attrib->border==EB_TRUE,
	  form_attrib->comment_line?local_expr_as_string(form_attrib->comment_line):"255",
	  form_attrib->message_line?local_expr_as_string(form_attrib->message_line): "255",
	frm_attr
	);
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



	set_suppress_lines();
  if (i=='r') {
    	printc ("static struct BINDING _rbind[%d]={ /*print_param_g */ \n", ONE_NOT_ZERO(bind->list.list_len));
  } else {
    	printc ("struct BINDING _%cbind[%d]={ /* %d print_param_g */\n", i, ONE_NOT_ZERO(bind->list.list_len),bind->list.list_len);
  }
      if (bind->list.list_len == 0)
	{
	  printc ("{NULL,0,0,0,0,0}");
	} else {
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

  for (a=0;a<bind->list.list_len;a++) {
	if (i=='r') {
		set_nonewlines();
    		printc ("_rbind[%d].ptr= (&", a);
		print_variable_usage(bind->list.list_val[a]);
    		printc (");\n");
		clr_nonewlines();
	} else {
		set_nonewlines();
    		printc ("_fbind[%d].ptr= &", a);
		print_variable_usage(bind->list.list_val[a]);
    		printc (";");
		clr_nonewlines();

	}
  }

	clr_suppress_lines();

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
      //struct s_expr_member_function_call *p;
      //struct expr_str_list *expr;
      //int nargs;
	A4GL_assertion(1,"FIXME");
/*
      p=fcall->expr_str_u.expr_member_function_call;
      expr=A4GL_rationalize_list(p->parameters);
      nargs = A4GL_new_list_get_count (expr);
      real_print_expr_list (expr);

	real_print_class_func_call (p->lib, p->fname,0, nargs);
*/
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
	printc("   _retvars=A4GL_fgl_getfldbuf(_sio_%d,_inp_io_type,%s,NULL,0);",p->sio_id,
					local_field_name_list_as_char(p->field_list));
	printc("   if (_retvars != 1 ) {");
	printc("      A4GLSQL_set_status(-3001,0);");
	printc("      A4GL_chk_err(%d,\"%s\");",p->line,p->module);
  	printc("   }");
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

  A4GL_assertion (1, "Internal error - expecting a function call");
}


#ifdef OBSOLETE
/**
 *
 * @todo Describe function
 */
static void real_print_class_func_call (char *var, char *identifier, struct expr_str *args, int args_cnt,int yylineno)
{
  printcomment ("/* printing parameters */");
  if (args) real_print_expr (args);
  printcomment ("/* done printing parameters */");
  printc ("{int _retvars;A4GLSQL_set_status(0,0);\n");
	  if (A4GL_doing_pcode()) {
  		printc ("A4GLSTK_setCurrentLine(\"%s\",%d);", cmodname, yylineno);
	  } else {
  		printc ("A4GLSTK_setCurrentLine(_module_name,%d);", yylineno);
	  }

  printc ("_retvars=A4GL_call_datatype_function_i(&%s,%d,\"%s\",%d);\n", var, scan_variable (var), identifier, args_cnt);
print_reset_state_after_call(0);

}
#endif


#ifdef NOT_YET
static void real_print_pdf_call (char *a1, struct expr_str_list *args, char *a3,int yylineno)
{
  real_print_expr_list (args);
  printc ("{int _retvars;A4GLSQL_set_status(0,0);\n");
	  if (A4GL_doing_pcode()) {
  		printc ("A4GLSTK_setCurrentLine(\"%s\",%d);", cmodname,yylineno);
	  } else {
  		printc ("A4GLSTK_setCurrentLine(_module_name,%d);", yylineno);
	  }

  if (is_in_report()) {
  		printc ("_retvars=A4GL_pdf_pdffunc(&_rep,%s,%s); /* %d */\n", a1, a3,is_in_report());
  } else {
  		printc ("_retvars=A4GL_pdf_pdffunc(0,%s,%s);\n", a1, a3);
  }

}
#endif



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

  real_print_expr(expr);
  if (has_expr)
    {
	
      printc ("A4GL_push_char(_s);");
      printc ("A4GL_pushop(OP_EQUAL);\n");
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
print_init_var (struct variable *v, char *prefix, int alvl, int explicit,int PrefixIncludesName)
{
  char buff[1000];
  char prefix2[1000];
  strcpy (buff, prefix);
	if (PrefixIncludesName) {
  		sprintf (prefix2, "%s", prefix);
	} else {
  		sprintf (prefix2, "%s%s", prefix, v->names.names.names_val[0].name);
	}

  int d1;
  int size;
  int a;
  char buff_id[200];


  if (v->arr_subscripts.arr_subscripts_len)
    {

	if (v->arr_subscripts.arr_subscripts_val[0]==-1) {
			// dynamic array 
			if (!explicit) return;
	}


      printc ("{");
      for (a = 0; a < v->arr_subscripts.arr_subscripts_len; a++)
	{

	  SPRINTF2 (buff_id, "_fglcnt_%d_%d", alvl , a);
	  printc ("int %s;\n", buff_id);
	}

      for (a = 0; a < v->arr_subscripts.arr_subscripts_len; a++)
	{
	  SPRINTF2 (buff_id, "_fglcnt_%d_%d", alvl,a);
	
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

    case VARIABLE_TYPE_SIMPLE:
      {
	d1 = v->var_data.variable_data_u.v_simple.datatype & DTYPE_MASK;
	size = DECODE_SIZE (v->var_data.variable_data_u.v_simple.datatype);
	if (1 || size==0 ) {
		A4GL_assertion(size,"Expecting size to be zero...");
		// need to get it from the dimensions...?
		size=v->var_data.variable_data_u.v_simple.dimensions[0];
	}
	if (explicit == 0
	    && (d1 == DTYPE_INT || d1 == DTYPE_SMINT || d1 == DTYPE_FLOAT || d1 == DTYPE_SMFLOAT || d1 == DTYPE_DECIMAL
		|| d1 == DTYPE_MONEY))
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
	    printc ("A4GL_setnull(%d,&%s,0x%x);\n", d1, prefix2, size);
	  }
      }
      break;

    case VARIABLE_TYPE_RECORD:
      {
	int a;
		strcat(prefix2,".");
	for (a=0;a<v->var_data.variable_data_u.v_record.variables.variables_len;a++) {
		print_init_var (v->var_data.variable_data_u.v_record.variables.variables_val[a], prefix2,  alvl,  explicit,0);
	}
      }
	break;

    case VARIABLE_TYPE_ASSOC:
		{
		int a;
		if (v->var_data.variable_data_u.v_record.variables.variables_len) { // Its a record
			strcat(prefix2,".");
			for (a=0;a<v->var_data.variable_data_u.v_assoc.variables.variables_len;a++) {
				print_init_var (v->var_data.variable_data_u.v_assoc.variables.variables_val[a], prefix2,  alvl,  explicit,0);
			}
		} else {
			print_init_var (v->var_data.variable_data_u.v_assoc.variables.variables_val[0], prefix2,  alvl,  explicit,1);
		}
		}
		break;


    default:
      A4GL_assertion (1, "Not handled");

    }

  if (v->arr_subscripts.arr_subscripts_len)
    {
      for (a = 0; a < v->arr_subscripts.arr_subscripts_len; a++)
	{
	  tmp_ccnt--;
	  printc ("}\n", buff_id);
	  alvl--;
	}
      printc ("}\n", buff_id);
    }



}


#ifdef OBSOLETE
/**
 * Print in the generated output file the C implementation of the 
 * INITIALIZE <variable_list> TO NULL 4gl statement.
 */
void
print_init_g (struct expr_str_list *bind, int explicit)
{
  int cnt;
  printc ("{\n");


  for (cnt = 0; cnt < bind->list.list_len; cnt++)
    {
      print_init_var_from_expr (bind->list.list_val[cnt], "", 0,explicit);
    }

  printc ("}\n");
}
#endif


#ifdef SHOULD_BE_MOVED_TO_COMPILER
/**
 * Print the C implementation of the INITIALIZE LIKE 4gl statement.
 *
 * @param s The column list. Not used now.
 */
void
print_init_table_g (struct expr_str_list *b, char *s)
{
  int cnt;
  struct expr_str_list bnew;
  bnew.nbind=0;
  bnew.list.list_val=malloc(sizeof(bnew.bind[0])*b->list.list_len);
  //bnew.type=b->type;
  for (cnt=0;cnt<b->list.list_len;cnt++) {
	char buff[200];
	char *ptr;
	char *tab;
	char *col;
	strcpy(buff, A4GL_4glc_get_gen(INITCOL,cnt));
	tab=&buff[0];
	col=strchr(tab,'.');
	if (!col) {
		yylineno=line_for_cmd; a4gl_yyerror("Unable to find table/column");
		return;
	}
	*col=0;
	col++;
	ptr=A4GLSQL_syscolval_expr(tab,col,"DEFAULT");
	if (ptr==0) {
		bnew.nbind++;
		bnew.bind[bnew.nbind-1]=b->list.list_val[cnt];
	} else {
		int n;
		n=strlen(ptr);
		A4GL_trim(ptr);
		if (strlen(ptr)==0 && n) {
			ptr=" ";
		}
		printc("A4GL_push_char(\"%s\");",c_generation_trans_quote(ptr));
	      	printc ("A4GL_pop_var2(&%s,%d,0x%x);\n", b->list.list_val[cnt].varname, (int) b->list.list_val[cnt].dtype & 0xffff, (int) b->list.list_val[cnt].dtype >> 16);
	}
  }
  if (bnew.nbind) {
  	printc ("{\n");
  	cnt = print_bind_definition_g (&bnew);
  	cnt = print_bind_set_value_g (&bnew);
  	printc ("A4GL_set_init(nullbind,%d);\n", cnt);
  	printc ("}\n");
	}
}

void
print_validate_g (struct expr_str_list *bind,char *tablist)
{
  int cnt;
  int z;
  int a;
  int b;

  z = bind->list.list_len;
  cnt=get_validate_list_cnt();
  if (z!=cnt) {
	  set_yytext("");
	
	  A4GL_debug(" validate mismatch : %d %d\n",z,cnt);
	  yylineno=line_for_cmd;a4gl_yyerror ("Mismatch in number of variables and number of columns");
	  return;
  }
  printc("/* VALIDATE */");
  printc ("    A4GLSQL_set_status(0,0);\n");
  for (a=0;a<z;a++) {
        //char buff[256];
	struct expr_str_list *p;
	p=(struct expr_str_list *)A4GL_get_validate_expr(a);
	if (p==0) continue;
	printc ("A4GL_push_variable(&%s,0x%x);\n", bind->list.list_val[a].varname, bind->list.list_val[a].dtype );
	for (b=0;b<p->list.list_len;b++) {
		print_expr(p->list.list_val[b]);
	}
        printc("A4GL_push_int(%d);",p->list.list_len);
        printc("A4GL_pushop(OP_IN);");
	printc("if (!A4GL_pop_bool()) {A4GLSQL_set_status(-1321,0);}");
  }
}
#endif

#ifdef MOVED
/**
 * Called in the middle of the REPORT definition after the parser found
 * the optional output and (or) order external by.
 * @param pdf :
 *   - 0 : Its not a PDF report.
 *   - 1 : Its a PDF report.
 * @param repordby
 */
void
print_report_2_g (int pdf, char *repordby,char *asc_desc,struct expr_str_list *bind, struct expr_str_list *orderbind, int report_cnt, char *curr_rep_name)
{
  int cnt;
  int a;
  if (pdf) {
  	//doing_a_report=2;
    printc ("static struct pdf_rep_structure _rep;\n");
  } else {
  	//doing_a_report=1;
    printc ("static struct rep_structure _rep;\n");
  }

  printc ("static char _rout1[256];\n");
  printc ("static char _rout2[256];\n");
  printc ("static int _useddata=0;\n");
  printc ("static int _started=0;\n");
  printc ("static int _assigned_ordbind=0;\n");


  cnt = print_param_g ('r',"report",bind);


if (!A4GL_doing_pcode()) {
  printc ("init_module_variables();");
}
  printc(" if (_assigned_ordbind==0) { _assigned_ordbind=1;"); print_bind_set_value_g(orderbind,'O'); printc("}");

  printc ("if (acl_ctrl==REPORT_SENDDATA&&_started==0&&fgl_rep_orderby!=1) {");
  printc ("    A4GLSQL_set_status(-5555,0);\n");
  printc ("    return;\n");
  printc ("    }\n");
  printc ("if (_nargs!=%d&&acl_ctrl==REPORT_SENDDATA) {", cnt);
  printc
    ("A4GL_fglerror(ERR_BADNOARGS,ABORT);A4GL_pop_args(_nargs);return ;}\n");
  printc ("if (acl_ctrl==REPORT_LASTDATA) {\n   int _p;\n");
  printc
    ("   if (_useddata) {for (_p=acl_rep_ordcnt;_p>=1;_p--) %s(_p,REPORT_AFTERGROUP);}\n",
     curr_rep_name );
  printc ("}\n");

  if (last_orderby_type == 1)
    {
      printc ("if (acl_ctrl==REPORT_SENDDATA&&fgl_rep_orderby==1) {");
      for (a = 0; a < cnt; a++)
	{
	  printc
	    ("A4GL_setnull(_rbind[%d].dtype,_rbind[%d].ptr,_rbind[%d].size);", a,
	     a, a);
	}
      printc ("A4GL_pop_params(_rbind,%d);", cnt);
      print_report_table (mv_repname, 'R', cnt,asc_desc,bind,orderbind);
      printc ("return;");
      printc("}");
    }

  printc ("if (acl_ctrl==REPORT_SENDDATA) {\n");
  printc ("   int _g;int _p;\n");


  /* This was put in to force a page header if*/
  /* data was sent - but not used..*/
  /* But this prints too early here...*/
  /*printc ("   A4GL_rep_print(&_rep,0,1,0,-1);");*/


  printc ("   _g=A4GL_chk_params(_rbind,%d,_ordbind,acl_rep_ordcnt);\n", cnt);
  printc
    ("   if (_g>0&&_useddata) {for (_p=acl_rep_ordcnt;_p>=_g;_p--) %s(_p,REPORT_AFTERGROUP);}\n",
     curr_rep_name );
  printc ("   A4GL_pop_params(_rbind,%d);\n", cnt);
  printc ("               %s(0,REPORT_AFTERDATA);", curr_rep_name );
  printc ("   if (_useddata==0) {_g=1;}\n");
  printc ("   if (_g>0) {");
  printc ("    A4GL_%srep_print(&_rep,0,1,0,-1);\n",ispdf()); // Mantis ID 573
  printc ("        _useddata=1;");
  printc ("        for (_p=_g;_p<=acl_rep_ordcnt;_p++) ");
  printc ("               %s(_p,REPORT_BEFOREGROUP);", curr_rep_name );
  printc ("   }");


  printc ("   _useddata=1;\n");

  print_rep_ret (report_cnt,0);
  printc ("}\n\n");
  printc ("if (acl_ctrl==REPORT_FINISH) {\n");

  if (last_orderby_type == 1)
    {

      printc ("    if (fgl_rep_orderby==1) {\n");
      printc ("        struct BINDING *reread;\n");
      printc ("        fgl_rep_orderby=-1;\n");
      printc ("        A4GL_push_char(_rout1);\n");
      printc ("        A4GL_push_char(_rout2);\n");
      printc ("        %s(2,REPORT_RESTART);\n", curr_rep_name );

      /*printc ("        A4GL_init_report_table(_rbind,%d,_ordbind,acl_rep_ordcnt,&reread);\n", cnt);*/
      print_report_table (mv_repname, 'I', cnt,asc_desc,bind,orderbind);

      /*printc ("        while (A4GL_report_table_fetch(reread,%d,_rbind))",cnt);*/
      print_report_table (mv_repname, 'F', cnt,asc_desc,bind,orderbind);

      printc ("                    %s(%d,REPORT_SENDDATA);\n",
	      curr_rep_name , cnt);
      printc (" }");
      printc ("        %s(0,REPORT_FINISH);\n", curr_rep_name );

      /*printc ("        A4GL_end_report_table(_rbind,%d,reread);",cnt);*/
      print_report_table (mv_repname, 'E', cnt,asc_desc,bind,orderbind);

      printc ("        return;");
      printc ("    }\n");

    }

  printc ("}\n");



  printc (" ");
  printc("if (acl_ctrl==REPORT_CONVERT) {");
  printc("char *_f; char *_o; char *_l; int _to_pipe; _l=A4GL_char_pop(); _o=A4GL_char_pop(); _f=A4GL_char_pop(); _to_pipe=A4GL_pop_int();\n");
  printc("A4GL_convert_report(&_rep,_f,_o,_l,_to_pipe);");
  printc("return ;");
  printc("}");
  printc("if (acl_ctrl==REPORT_FREE) {");
  printc("A4GL_free_report(&_rep);");
  printc("return ;");
  printc("}");
  printc ("if (acl_ctrl==REPORT_START||acl_ctrl==REPORT_RESTART) {\n");
  printc ("   A4GL_pop_char(_rout2,254);A4GL_trim(_rout2);\n");
  printc ("   A4GL_pop_char(_rout1,254);A4GL_trim(_rout1);\n");
  if (last_orderby_type == 1)
    {
      printc ("   if (acl_ctrl==REPORT_START) {fgl_rep_orderby=1;}\n");
      printc ("   if (fgl_rep_orderby==1) {");
      print_report_table (mv_repname, 'M', cnt,asc_desc,bind,orderbind);
      printc ("       return;");
      printc ("   }\n");
    }


  printc ("   _useddata=0;\n");
  printc ("   _started=1;\n");
  printc ("goto output_%d;\n", report_cnt);
  printc ("}\n\n");
  print_rep_ret (report_cnt,0);
  if (pdf)
    pdf_print_output_rep (&pdf_rep_struct,report_cnt, curr_rep_name);
  else
    print_output_rep (&rep_struct ,report_cnt, curr_rep_name);
}
#endif


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
  printc ("A4GLSTK_setCurrentLine(_module_name,%d);", yylineno);
  printc ("A4GLSTK_pushFunction(_functionName,_paramnames,_nargs);\n");
}

/**
 * Print the C C code to the call to the pop function of the calling stack.
 *
 * It only does it if defined as compiler option.
 */
void
printPopFunction (void)
{
  if (!local_isGenStackInfo ())
    return;

if (A4GL_doing_pcode()) { return;}
  printc ("A4GLSTK_popFunction();\n");
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
      printc ("%sA4GL_cs_%s;\n", buff, var, size);
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
	  if (v->arr_subscripts.arr_subscripts_len >= 0)
	    {
	      printc ("} %s[%s]; /*1 */\n", vname, buff);
	    }
	  else
	    {
	      printc ("} *%s;\n", vname); // Dynamic array...
	    }
	}
    }
}


#ifdef MOVED
/**
 *
 * @todo Describe function
 */
int
doing_esql ()
{
  if (strcmp (acl_getenv ("A4GL_LEXTYPE"), "EC") == 0)
    {
      return 1;
    }


  return 0;
}
#endif


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
  	fprintf(outfile,"\n\n\n/* END OF MODULE */\n");
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
  printc ("\n\nA4GL_FUNCTION int %s%s(int n) {\nreturn %s(n);\n}\n",
	  get_namespace (s), s, s);
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

#ifdef OLD

int *ordbyfields = 0;
int ordbyfieldscnt = 0;

static void
add_to_ordbyfields (int n)
{
  int a;
  for (a = 0; a < ordbyfieldscnt; a++)
    {
      if (ordbyfields[a] == n)
	return;
    }
  ordbyfieldscnt++;
  ordbyfields = realloc (ordbyfields, sizeof (int) * ordbyfieldscnt);
  ordbyfields[ordbyfieldscnt - 1] = n;

}


/* 
If the report doesn't specify an explicit order by, there
may be an implicit one in the order that BEFORE GROUP/AFTER GROUPs were
added in the format section

We're going to use the fact that the _ordbind will contain all the variables,
and we have the variable numbers from the before and after groups.

If we copy the ordbind, then reassemble the ordbind using these - we should be ok again
*/

static void order_by_report_stack (int report_stack_cnt)
{
  int a;
  static int fiddle = 0;
  if (ordbyfields)
    free (ordbyfields);		/* From a previous report..*/
  ordbyfields = 0;		/* clear it all down...*/
  ordbyfieldscnt = 0;



/* This only applies if we're doing an order external (implicit for no order by at all */
  if (last_orderby_type != 2)
    return;

  if (!get_rep_no_orderby ())
    return;


/* Find our group order */
  for (a = 0; a < report_stack_cnt; a++)
    {
      if (get_report_stack_whytype (a) == 'B'
	  || get_report_stack_whytype (a) == 'A')
	{
	  add_to_ordbyfields (atoi (get_report_stack_why (a)));
	}
    }


/* At this point we'll know if they used before/after groups */

/* We only want to do this if we haven't done it before... */
  printc ("if (acl_rep_ordcnt==-1) {");

  if (ordbyfieldscnt == 0)
    {
      printc ("acl_rep_ordcnt=0;");	/* Nothing to do - there isn't any...*/
    }
  else
    {
      /* Because of where this needs to go - we're going to shove a function
         into the header file we can call 
       */

      /* C File */
      printc ("acl_rep_ordcnt=%d; /* 1 */", ordbyfieldscnt);
      /* And assign the values*/
      fiddle++;
      printc ("acl_exchange_rep_ordby%d(_ordbind,%d);", fiddle,
	      current_ordbindcnt);
/* H file... */
      printh
	("static void acl_exchange_rep_ordby%d(struct BINDING *ord,int cnt) {\n",
	 fiddle);
      printh ("struct BINDING *copy;\n");
      printh ("copy=(struct BINDING *)acl_malloc2(sizeof(struct BINDING)*cnt);\n");
      printh ("memcpy(copy,ord,sizeof(struct BINDING)*cnt);\n");
      /* We've got our copy - now we can splat the original! */
      for (a = 0; a < ordbyfieldscnt; a++)
	{
	  printh ("memcpy(&ord[%d],&copy[%d],sizeof(struct BINDING));\n", a, ordbyfields[a] - 1);	/* fields are numbered from 1 for before/after group variables */
	}
      printh ("free(copy);\n");
      printh ("}\n");
    }
  printc ("}");

}


static int
gen_ord (char *s)
{
  int a;
  int n;
  n = atoi (s);
  if (last_orderby_type != 2)
    return n;
  if (!get_rep_no_orderby ())
    return n;
  for (a = 0; a < ordbyfieldscnt; a++)
    {
      if (n == ordbyfields[a])
	return a + 1;
    }

  return n;			/* Fall back - shouldn't happen!!*/
}

#endif

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



#ifdef NOTUSED_and_or_broken
// FIXME - should return expr_str_list...
struct expr_str *A4GL_add_validation_elements_to_expr(struct expr_str *ptr,char *val) {
char *ptr2;
char *ptrn;
//char buff[256];
A4GL_trim(val);
ptr2=val;
while (1) {
        ptrn=strtok(ptr2,",");
        if (ptrn==0) break;
        if (ptr2) {ptr2=0;}

        //SPRINTF1(buff,"A4GL_push_char(\"%s\");",ptrn);

        if (ptr==0) {
		ptr=A4GL_new_literal_string(ptrn);
                //ptr=A4GL_new_expr(buff);
        } else {
		struct expr_str *e;
		e=A4GL_new_literal_string(ptrn);
                ptr=A4GL_append_expr_expr(ptr,e);
        }

}
return ptr;
}

#endif

#ifdef OLD
void
print_event_list ()
{
  int a;
  int n;
  int b;
  int event_id;
  char *event_dets;
  int *keys;
//char comma=' ';
  char **fields;

  n = A4GL_get_nevents ();
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
      A4GL_get_event (a, &event_id, &event_dets);

      if (event_id == A4GL_EVENT_KEY_PRESS)
	{
	  keys = get_key_codes (event_dets);
	  for (b = 0; keys[b]; b++)
	    {
	      printc ("{%d,%d,%d,0},", event_id, a + 1, keys[b]);
	    }
	  continue;
	}

      if (event_id == A4GL_EVENT_ON_IDLE)
	{
	    printh("static long a4gl_idle%d=0;\n",idle_cnt);
	    printc ("{%d,%d,%s,(void *)&a4gl_idle%d},", event_id, a + 1, event_dets,idle_cnt++);
	    continue;
	}

      if (event_id == A4GL_EVENT_ON_INTERVAL)
	{
	    printh("static long a4gl_idle%d=0;\n",idle_cnt);
	    printc ("{%d,%d,%s,(void *)&a4gl_idle%d},", event_id, a + 1, event_dets,idle_cnt++);
	    continue;
	}



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
  printc ("{0}");
  printc ("};");
}

#endif

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

	      printc ("{NULL,%d,%d,%s,%s,0}%c",
		      (int) get_binding_dtype (lbind->list.list_val[a]) & 0xffff,
		      (int) get_binding_dtype (lbind->list.list_val[a]) >> 16,
		      get_start_char_subscript (lbind->list.list_val[a]),
		      get_end_char_subscript (lbind->list.list_val[a]), (a < lbind->list.list_len - 1) ? ',' : ' ');
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
				break;

			case ET_EXPR_VARIABLE_USAGE: 
				set_nonewlines();
          			printc ("ibind[%d].ptr=&",a);
				print_variable_usage_for_bind(bind->list.list_val[a]);
				printc(";");
				clr_nonewlines();
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
				printh("static char a4gl_putval_%d[2]=\" \";\n");
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
                        printc("A4GL_init_out_byte(obind[%d].ptr,native_binding_o[%d].ptr);",a,a);
                }
                if ((get_binding_dtype(bind->list.list_val[a])&DTYPE_MASK)==DTYPE_TEXT) {
                        printc("A4GL_init_out_text(obind[%d].ptr,native_binding_o[%d].ptr);",a,a);
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
          printc ("nullbind[%d].ptr=&%s;", a);
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
  printc
    ("   if (_nargs!=%d) {A4GLSQL_set_status(-3002,0);A4GL_pop_args(_nargs);return -1;}\n",
     nargs, yylineno);
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
  printc (buff);
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
          print_init_var ( v->variables.variables_val[a], "", 0, 0,0);
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


  SPRINTF1 (s, "%d", n);
  return local_rettype (s);
}


/******************************************************************************/
void
print_variable_new (struct variable *v, char scope, int level)
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

  if (scope == 'G' && strcasecmp (v->names.names.names_val[0].name, "time") == 0 && level == 0)
    {
#ifdef DEBUG
      A4GL_debug ("Ignore time....\n");
#endif
clr_suppress_lines();
      return;
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
  if (level == 0 && (A4GL_isyes (acl_getenv ("MARK_SCOPE"))|| A4GL_isyes (acl_getenv ("MARK_SCOPE_MODULE")))  )
    {
      /*printf("%s %c %c %c\n",name,v->user_system,v->scope,scope);*/
      if (local_is_system_variable (v));
      else
	{
	  if (v->scope == 'G' || v->scope == 'g')
	    {
	      SPRINTF1 (name, "G_%s", v->names.names.names_val[0].name);
	    }
	  if (v->scope == 'M' || v->scope == 'm')
	    {
		if (A4GL_isyes (acl_getenv ("MARK_SCOPE_MODULE"))) {	
	      		SPRINTF2 (name, "M_%s_%s", get_current_module_name_clean(),v->names.names.names_val[0].name);
		} else {
	      		SPRINTF1 (name, "M_%s", v->names.names.names_val[0].name);
		}
	    }
	  if (v->scope == 'L' || v->scope == 'l')
	    {
	      SPRINTF1 (name, "L_%s", v->names.names.names_val[0].name);
	    }
/*
	  if (v->scope == 'C' || v->scope == 'c')
	    {
	      SPRINTF (name, "_this->%s", v->names.name);
	    }
*/
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
	      SPRINTF2 (tmpbuff, "%s *%s",
		       local_rettype_integer (v->var_data.variable_data_u.v_simple.datatype), name);
	    }
	}

      if (v->var_data.variable_data_u.v_simple.datatype == DTYPE_CHAR || v->var_data.variable_data_u.v_simple.datatype==DTYPE_VCHAR)
	{			/* Its a 'char' (may need varchar & friends too...*/


		if (v->var_data.variable_data_u.v_simple.datatype == 0) {
	  		print_define_char (tmpbuff, v->var_data.variable_data_u.v_simple.dimensions[0], static_extern_flg);
		} else {
	  		print_define_char (tmpbuff, v->var_data.variable_data_u.v_simple.dimensions[0], static_extern_flg); // Allow extra space to store the size...
		}
	}
      else
	{
		
	  print_define (tmpbuff, static_extern_flg);
	}

clr_suppress_lines();
      return;
    }

  if (v->var_data.variable_type == VARIABLE_TYPE_RECORD ||v->var_data.variable_type == VARIABLE_TYPE_OBJECT)
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

      memcpy (&v2, v->var_data.variable_data_u.v_assoc.variables.variables_val[0], sizeof (struct variable));

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
	"nchar", //15
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
	if (A4GLSQLCV_check_requirement("ODBC_LONGVARCHAR_AS_CHAR"))
	    vals[12] = vals[0];

    }

    if (sscanf(s, "%d", &i) != 1) {
	yylineno=line_for_cmd;a4gl_yyerror("Internal error - type conversion error\n");
	}

    if (i < sizeof(vals)/sizeof(char*)) {
	return vals[i];
     }
	yylineno=line_for_cmd;
    a4gl_yyerror("Unsupported type id\n");
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


static char local_find_variable_scope(expr_str *e) {
	A4GL_assertion(e->expr_type!=ET_EXPR_VARIABLE_USAGE,"Not a variable usage...");
	return e->expr_str_u.expr_variable_usage->scope;
}


int check_binding(struct expr_str_list *l, char *fromwhere,int yylineno) {
char c;
int a;
if (l==0) return 0;
for (a=0;a<l->list.list_len;a++) {
        c=local_find_variable_scope(l->list.list_val[a]);
        if (c=='M'||c=='G') {
                if (A4GL_isyes(acl_getenv("WARNGLOBMODBINDING"))) {
                        if (c=='M') {
                                fprintf(stderr, "Use of module variable (%s) @%d (%s)\n",get_dbg_variable_name(l->list.list_val[a]),yylineno,fromwhere);
                        }
                        if (c=='G') {
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
  print_nullify ('M', mvars);
  tmp_ccnt--;
  printc ("}");
  printc("#");
}
clr_suppress_lines() ;
}






void dump_commands(commands *c) {
int a;
	if (c==0) return;
      for (a = 0; a < c->cmds.cmds_len; a++)
        {
          dump_cmd (c->cmds.cmds_val[a]);
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
              printc ("char *_paramnames[1]={\"\"};");
            }
          else
            {


              printc ("\n\nA4GL_MAIN int main(int argc,char *argv[]) {\n");
              printc ("char *_paramnames[1]={\"\"};");
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
              print_variable_new (function_definition->variables.variables.variables_val[a], 'L', 0);
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
              print_variable_new (function_definition->variables.variables.variables_val[a], 'L', 0);
            }
        }
      printc ("#");
	expanded_params=expand_parameters(&function_definition->variables,function_definition->parameters);
      print_param_g ('f', function_definition->funcname, expanded_params );

      if (local_isGenStackInfo ())
        {
          if (!A4GL_doing_pcode ())
            {
              printc ("A4GLSTK_setCurrentLine(_module_name,%d);", function_definition->lineno);
              printc ("A4GLSTK_pushFunction(_functionName,_paramnames,_nargs);\n");
            }
        }


      if (A4GL_doing_pcode ())
        {
          printc
            ("if (_nargs!=%d) {A4GLSQL_set_status(-3002,0);A4GL_pop_args(_nargs);return -1;}\n",
             expanded_params->list.list_len, function_definition->lineno);
        }
      else
        {
          printc
            ("if (_nargs!=%d) {A4GLSQL_set_status(-3002,0);A4GL_pop_args(_nargs);A4GLSTK_popFunction();return -1;}\n",
             expanded_params->list.list_len, function_definition->lineno);
        }
      tmp_ccnt++;
      print_function_variable_init (&function_definition->variables);
      printc ("A4GL_pop_params(_fbind,%d);\n", expanded_params->list.list_len);

    }

  printc ("#");


  if (function_definition->func_commands)
    {
      for (a = 0; a < function_definition->func_commands->cmds.cmds_len; a++)
        {
          dump_cmd (function_definition->func_commands->cmds.cmds_val[a]);
        }
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
	printPopFunction();

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
              print_variable_new (function_definition->variables.variables.variables_val[a], 'L', 0);
            }
        }
  printc ("static char this_win[64]=\"\";char cwin[64]; strcpy(cwin,A4GL_get_currwin_name());\n", name);
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




int
LEXLIB_A4GL_write_generated_code (struct module_definition *m)
{
int a;
LEX_initlib();
strcpy(this_module_name,m->module_name);
 current_module = m;
	set_namespace(current_module->namespace);

      open_outfile () ; // this_module_name);
      if (outfile == 0)
	return 0;
  if (m->imported_global_variables.variables.variables_len)
    {
      for (a = 0; a < m->imported_global_variables.variables.variables_len; a++)
        {
          print_variable_new (m->imported_global_variables.variables.variables_val[a], 'G', 0);
        }
    }

  if (m->exported_global_variables.variables.variables_len)
    {
      for (a = 0; a < m->exported_global_variables.variables.variables_len; a++)
        {
          print_variable_new (m->exported_global_variables.variables.variables_val[a], 'g', 0);
        }
    }

  if (m->module_variables.variables.variables_len)
    {
      for (a = 0; a < m->module_variables.variables.variables_len; a++)
        {
          print_variable_new (m->module_variables.variables.variables_val[a], 'M', 0);
        }
    }


  print_module_variable_init (&m->module_variables);


  for (a = 0; a < m->module_entries.module_entries_len; a++)
    {
      int ok = 1;

	parent_stack_cnt=0;

      current_entry = m->module_entries.module_entries_val[a];

      switch (m->module_entries.module_entries_val[a]->met_type)
        {
           case E_MET_IMPORT_FUNCTION_DEFINITION:  
		
		print_import(
			m->module_entries.module_entries_val[a]->module_entry_u.import_function_definition.funcname,
			m->module_entries.module_entries_val[a]->module_entry_u.import_function_definition.nparam,
			m->module_entries.module_entries_val[a]->module_entry_u.import_function_definition.lineno
			);
		//struct s_import_function_definition import_function_definition;
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
	if (v->expr_type==ET_EXPR_VARIABLE_USAGE) {
		u=v->expr_str_u.expr_variable_usage;
	}
	if (v->expr_type==ET_EXPR_VARIABLE_USAGE_WITH_ASC_DESC) {
		u=v->expr_str_u.expr_variable_usage_with_asc_desc->var_usage;
	}
	A4GL_assertion(u==0,"Not a variable usage");
	return is_substring_variable_usage(u,s,e);
}


static char *get_subscript_as_string(expr_str *u) {
static char buff[256];
char smbuff[256];

	if (u->expr_type==ET_EXPR_LITERAL_LONG) {
			// We can make the 'long's look a little neater as we can subtract the 1..
			sprintf(smbuff, "%ld", u->expr_str_u.expr_long-1);
	} else {
			sprintf(smbuff, "(%s)-1", local_expr_as_string(u));
	}
strcpy(buff,smbuff);
return buff;
}




void
print_pop_usage (expr_str * v)
{
  int substring = 0;
  struct variable_usage *u;
  expr_str *substring_start;
  expr_str *substring_end;

  u = v->expr_str_u.expr_variable_usage;
  A4GL_assertion (get_binding_dtype (v) == -1, "Usage not ensured...");

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
		    printc (",");
		  printc ("%s", get_subscript_as_string (u->subscripts.subscripts_val[a]));
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
				if (a) printc(",");
				printc("%s", get_subscript_as_string(u->subscripts.subscripts_val[a]));
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
char *ispdf() {
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
	  		default: 
				
				printc ("A4GL_push_variable(&");
					print_variable_usage(ptr);
	  			 printc (",0x%x);",get_binding_dtype(ptr) );
		}
	} else {
	
		printc("A4GL_push_substr(");
		while (u)  {
			printc("%s",u->variable_name);
			if (u->subscripts.subscripts_len) {
				int a;
				printc("[");
				for (a=0;a<u->subscripts.subscripts_len;a++) { 
					if (a) printc(",");
					printc("%s", get_subscript_as_string(u->subscripts.subscripts_val[a]));
					//printc("(%s)-1", local_expr_as_string(u->subscripts.subscripts_val[a]));
				}
				printc("]");
			}
			if(u->next==0) break;
			printc(".");
			u=u->next;
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
		substring=is_substring_variable_usage(u,&substring_start, &substring_end);

		if (substring) {
			A4GL_assertion(1,"Cant use a substring here");
			printc("A4GL_push_substr(");
		}

		strcpy(buff,"");
		while (u)  {
			strcat(buff,u->variable_name);
			if (u->subscripts.subscripts_len) {
				int a;
				strcat(buff, "[");
				for (a=0;a<u->subscripts.subscripts_len;a++) { 
					if (a) strcat(buff, ",");
					strcat(buff,  get_subscript_as_string(u->subscripts.subscripts_val[a]));
					//strcat(buff, local_expr_as_string(u->subscripts.subscripts_val[a]));
					//strcat(buff, "-1");
				}
				strcat(buff, "]");
			}
			if(u->next==0) break;
			strcat(buff,".");
			u=u->next;
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

		yylineno=line_for_cmd;
		a4gl_yyerror("You can use a function requiring parameters in this context");
		return 0;
		}
		
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
      printc("%s", local_expr_as_string (ptr->expr_str_u.expr_expr));

      return;
    }
  if (ptr->expr_type == ET_EXPR_VARIABLE_USAGE)
    {
	print_variable_usage(ptr);
      //printc ("%s", get_variable_usage (ptr->expr_str_u.expr_variable_usage));
      return;
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
      return local_expr_as_string (ptr->expr_str_u.expr_expr);
    }

  if (ptr->expr_type == ET_EXPR_VARIABLE_USAGE)
    {
	return generation_get_variable_usage_as_string(ptr->expr_str_u.expr_variable_usage);
    }


  A4GL_assertion (1, "get_ident_as_string not implemented for this expression type yet");
  return 0;
}



struct variable *local_find_variable_from_usage(struct variable_usage *u) {
struct variable *v=0;

// If this assertion fails - make sure you've run the expression containing the
// variable usage through the "ensure_variable" function to set up the scope/datatype and variable ids..
A4GL_assertion(u->variable_id<0,"Variable has not been previously found..");


switch (u->scope) {
	case 'L':  // list_local_cnt
		A4GL_assertion(u->variable_id>=current_entry_variables->variables.variables_len,"Invalid VARIABLE ID");
		v=current_entry_variables->variables.variables_val[u->variable_id];
		break;
	case 'M':  // list_module
		A4GL_assertion(u->variable_id>=current_module->module_variables.variables.variables_len,"Invalid VARIABLE ID");
		v=current_module->module_variables.variables.variables_val[u->variable_id];
		break;
	case 'G':  // list_globals
		A4GL_assertion(u->variable_id>=current_module->exported_global_variables.variables.variables_len,"Invalid VARIABLE ID");
		v=current_module->exported_global_variables.variables.variables_val[u->variable_id];
		break;
	case 'g':  // list_imported_global
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
	u=u->next;
	A4GL_assertion(u->variable_id<0,"Variable not ensured...");
	A4GL_assertion(u->variable_id>v->var_data.variable_data_u.v_record.variables.variables_len,"Variable out of range");
	v=v->var_data.variable_data_u.v_record.variables.variables_val[u->variable_id];
	
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
	  printc ("\nA4GL_fgl_start(argc,argv);\n");
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



void
search_sql_variables (struct s_select_list_item_list *l,char dir)
{
  int a;
  if (l == 0)
    return;
  for (a = 0; a < l->list.list_len; a++)
    {

      if (l->list.list_val[a]->data.type == E_SLI_VARIABLE_USAGE)
        {
          l->list.list_val[a]->data.type = E_SLI_VARIABLE;
          l->list.list_val[a]->data.s_select_list_item_data_u.expression = strdup(get_sql_variable_usage (l->list.list_val[a]->data.s_select_list_item_data_u.var_usage,dir));
        }
      if (l->list.list_val[a]->data.type == E_SLI_VARIABLE_USAGE_IN_SELECT_LIST)
        {
          l->list.list_val[a]->data.type = E_SLI_VARIABLE;
	  set_dont_use_indicators=1;
          l->list.list_val[a]->data.s_select_list_item_data_u.expression = strdup(get_sql_variable_usage (l->list.list_val[a]->data.s_select_list_item_data_u.var_usage,dir));
	  set_dont_use_indicators=0;
        }

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
//   this isn't portable and causes issues with some esql/c generation..
//
int chk_ibind_select_internal(struct s_select *s) {
int a;
int ok=1;
struct s_select snew;
struct s_select_list_item_list *slist;
struct s_select_list_item *ptr;

memcpy(&snew,s,sizeof(snew));
snew.where_clause=0;
snew.having=0;
snew.group_by=0;

if (snew.next) {
	if (!chk_ibind_select(snew.next)) {
		ok=0;
	}
}

for (a=0;a<snew.list_of_items.list.list_len;a++) {
	ptr=snew.list_of_items.list.list_val[a];

	if (ptr->data.type==E_SLI_VARIABLE_USAGE) {
		ptr->data.type=E_SLI_VARIABLE_USAGE_IN_SELECT_LIST;

		return 0;
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
  return ptr;
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

	A4GL_assertion (updateCmd->column_list == 0, "No column list");
	A4GL_assertion (updateCmd->value_list == 0, "No value list");

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






#ifdef OBSOLETE














/**
 * Print the spaces corresponding to the scope level to have good
 * identation in the output source.
 */
void
xxx_deleteme_A4GL_incprint (void)
{
  int a;

  for (a = 0; a <= getinc (); a++)
    {
      printc ("   ");
    }
}

/**
 * Print the begining of a report control block.
 *
 * A report block is one of the control blocks:
 *   - FIRST PAGE HEADER
 *   - PAGE TRAILER
 *   - PAGE HEADER
 *   - ON EVERY ROW
 *   - ON LAST ROW
 *   - BEFORE GROUP
 *   - AFTER GROUP
 */
void
xxx_deleteme_print_repctrl_block (int report_cnt, int report_stack_cnt,int curr_lineno)
{
  printc ("rep_ctrl%d_%d:\n", report_cnt, report_stack_cnt);

printc("A4GL_%spush_report_section(&_rep,_module_name,_reportName,%d,'%c',\"%s\",%d);",ispdf (), curr_lineno,get_curr_report_stack_whytype(),get_curr_report_stack_why(),rep_print_code);


}


/**
 * Print the C include statement for header file
 */
void
xxx_deleteme_print_include (char *s)
{
  printc ("#include <%s.h>\n", s);
}

/**
 * Print the C implementation of the current report control block
 */
void
xxx_deleteme_print_report_ctrl (int report_cnt, char *curr_rep_name,int rep_type, int report_stack_cnt)
{
  int a;
  int printed_every;
  A4GL_debug
    ("/* ********************************************************** */\n");
  A4GL_debug
    ("/*                 Report Control Block                       */\n");
  A4GL_debug
    ("/* ********************************************************** */\n");
  printc ("report%d_ctrl:\n", report_cnt);
  printc ("if (_rep.lines_in_header      ==-1) _rep.lines_in_header=%d;",
	  rep_struct.lines_in_header);
  printc ("if (_rep.lines_in_first_header==-1) _rep.lines_in_first_header=%d;",
	  rep_struct.lines_in_first_header);
  printc ("if (_rep.lines_in_trailer     ==-1) _rep.lines_in_trailer=%d;",
	  rep_struct.lines_in_trailer);


  order_by_report_stack (report_cnt);

  //printc ("A4GL_debug(\"ctrl=%%d _nargs=%%d\",acl_ctrl,_nargs);\n");
  printc ("    if (acl_ctrl==REPORT_OPS_COMPLETE) return;\n\n");
  printc ("    if (acl_ctrl==REPORT_SENDDATA) {\n");
  printc ("   /* check for after group of */\n");
  printc ("       %s(0,REPORT_DATA);\n", curr_rep_name );
  printc ("   /* check for before group of */\n");
  printc ("    }\n\n");


  printc ("if (acl_ctrl==REPORT_FINISH && _started==0) {");
  printc ("    A4GLSQL_set_status(-5555,0);\n");
  printc ("    return;\n");
  printc ("    }\n");
  printc ("if (acl_ctrl==REPORT_FINISH && _started) {%s(0,REPORT_LASTDATA);return;}\n",
	  curr_rep_name);

  if (rep_type == REP_TYPE_NORMAL)
    {
      printc ("if (acl_ctrl==REPORT_LASTDATA) {");
      printc ("  if (_useddata || A4GL_always_output_report(&_rep)) {");

      printc ("   /*if (_useddata)*/ {%s(0,REPORT_LASTROW);}", curr_rep_name );

      printc ("   if (_rep.page_no<=1&&_rep.page_length>1 &&_rep.header ) {A4GL_%srep_print(&_rep,0,1,0,-1);A4GL_%srep_print(&_rep,0,0,0,-1);}",ispdf(),ispdf());	/* MJA 13092003*/

      printc ("   _rep.finishing=1;");
      printc ("   A4GL_skip_top_of_page(&_rep,999);");
      printc ("}");
      printc ("  _started=0;");
      printc ("  if (_rep.output) {A4GL_close_report_file(&_rep);}");
      printc ("  return;");
      printc ("}\n");

    }
  else
    {
      printc
	("if (acl_ctrl==REPORT_LASTDATA) {if (_useddata) %s(0,REPORT_LASTROW);_started=0;A4GL_pdf_rep_close(&_rep);return;}\n",
	 curr_rep_name);

    }

  if (rep_type == REP_TYPE_NORMAL)
    {
      printc
	("if (acl_ctrl==REPORT_TERMINATE) {_started=0;if (_rep.output) {A4GL_close_report_file(&_rep);}return;}\n",
	 curr_rep_name );
    }
  else
    {
      printc
	("if (acl_ctrl==REPORT_TERMINATE) {_started=0;A4GL_pdf_rep_close(&_rep);return;}\n",
	 curr_rep_name );

    }


  printc ("    if (acl_ctrl==REPORT_AFTERDATA ) {\n");
  pr_report_agg ();
  printc ("    return;");
  printc ("    }\n");


  printed_every=0;

  // We need to clear down any counters...
  printc(" if (acl_ctrl==REPORT_START||acl_ctrl==REPORT_RESTART) {");
pr_nongroup_report_agg_clr();
  printc("}");


  for (a = 0; a < report_stack_cnt; a++)
    {
      if (get_report_stack_whytype (a) == 'P') // First page header - ensure its printed before the page header..
              printc ("if (acl_ctrl==REPORT_PAGEHEADER&&_rep.page_no==1) {acl_ctrl=0;goto rep_ctrl%d_%d;}\n", report_cnt, a);
    }



  for (a = 0; a < report_stack_cnt; a++)
    {
      /* on last row */



      if (get_report_stack_whytype (a) == 'L')
	printc
	  ("if (acl_ctrl==REPORT_LASTROW) { acl_ctrl=0;goto rep_ctrl%d_%d;}\n",
	   report_cnt, a);

      /* on every row */
      if (get_report_stack_whytype (a) == 'E') {
	printed_every=1;
	printc ("if (acl_ctrl==REPORT_DATA) {acl_ctrl=REPORT_NOTHING; goto rep_ctrl%d_%d;}\n", report_cnt, a);
	}

      /* before group of */
      if (get_report_stack_whytype (a) == 'B')
	printc
	  ("if (acl_ctrl==REPORT_BEFOREGROUP&&_nargs==%d) {_nargs=-1*_nargs;goto rep_ctrl%d_%d;}\n",
	   gen_ord (get_report_stack_why (a)), report_cnt, a);

      /* after group of */
      if (get_report_stack_whytype (a) == 'A')
	printc
	  ("if (acl_ctrl==REPORT_AFTERGROUP&&_nargs==%d) {_nargs=-1*_nargs;goto rep_ctrl%d_%d;}\n",
	   gen_ord (get_report_stack_why (a)), report_cnt, a);

      if (get_report_stack_whytype (a) == 'T')
	printc
	  ("if (acl_ctrl==REPORT_PAGETRAILER) {acl_ctrl=0;goto rep_ctrl%d_%d;}\n",
	   report_cnt, a);


      if (get_report_stack_whytype (a) == 'p')
	printc
	  ("if (acl_ctrl==REPORT_PAGEHEADER&&(_rep.page_no!=1||(_rep.page_no==1&&_rep.has_first_page==0))) {acl_ctrl=0;goto rep_ctrl%d_%d;}\n",
	   report_cnt, a);
    }
	if (!printed_every) {
		printc ("if (acl_ctrl==REPORT_DATA) {acl_ctrl=REPORT_NOTHING;\n", report_cnt);
		print_rep_ret (report_cnt,0);
		printc("}");
	}
  pr_report_agg_clr ();
}


/**
 * This function is only called by scan_arr_variable that is not used.
 *
 * @todo : If scan_arr_variable() removed then remove this one to.
 */
void
xxx_deleteme_print_range_check (char *var, char *size)
{
  printc ("A4GL_range_chk(%s,%d);\n", var, atoi (size));
}

/**
 * Print a C label to mark a start block
 *
 * @param n The block sequential number (used for the name of label)
 */
void
xxx_deleteme_print_start_block (int n)
{
  printc ("\n");
  //printc ("START_BLOCK_%d:\n", n,n);
}

/**
 * Print the C implementation of a CONTINUE statement.
 *
 * @param n The block sequential number for having unique label name.
 * @param brace Controls if should generate and end brace:
 *   - 0 : Dot not generate end brace "}"
 *   - Otherwise : Generate end brace
 */
void
xxx_deleteme_print_continue_block (int n, int brace,char *why)
{
  printc ("\n");
  if (A4GL_doing_pcode()) {
  	printc ("CONTINUE_BLOCK_%d:    ;   /* add_continue */ ", n,n);
  } else {
  	printc ("CONTINUE_BLOCK_%d:    ;   /* add_continue */ ", n,n);
  }
  if (brace)
    printc ("}\n");
}

/**
 * Generate the C implementation of a end block.
 *
 * This implementation is a C label where we can go to.
 *
 * @param n The block sequential number.
 */
void
xxx_deleteme_print_end_block (int n)
{
  printc ("END_BLOCK_%d: ;\n\n", n,n);
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
void
xxx_deleteme_print_exit_loop (int type, int n,char *cmdtype)
{
  if (type == 'M')
    {
      printc ("cmd_no_%d= -3;goto MENU_START_%d;\n", n, n);
    }
  if (type == 'P')
    {
      printc ("SET(\"s_prompt\",_sio_%d,\"mode\",1);\n",get_sio_ids("PROMPT"));
    }
  if (type == 0)
    {
      printc ("goto END_BLOCK_%d;", n);
    }
}


char *
xxx_deleteme_change_arr_elem (char *s)
{
	  static char buff[1024];
	    int a;
	      char buff2[2];
	        buff2[1] = 0;
		  buff[0] = 0;
		    strcpy (buff, "(");
		      A4GL_debug ("change_arr_elem: %s", s);
		        for (a = 0; a < strlen (s); a++)
				    {
					          if (s[a] == ',')
							          {
									            strcat (buff, ")-1][(");
										            }
						        else
								        {
										          buff2[0] = s[a];
											            strcat (buff, buff2);
												            }
							    }
			  strcat (buff, ")-1");
			    A4GL_debug ("Generated... %s", buff);
			      return buff;
}



/**
 * Prints a call to the corresponding pdf report in the generated C code
 *
 * @param a1 The pdf function name
 * @param args The pdf function arguments
 * @param a3 The returning values
 */
void
xxx_deleteme_print_pdf_call_g (char *a1, struct expr_str_list *args, char *a3, struct expr_str_list *returning_values,int yylineno)
{
  A4GL_debug ("via print_pdf_call in lib");
  real_print_pdf_call (a1, args, a3,yylineno);
  print_returning_g(2,returning_values,0);
}


/**
 * Print the C implementation of a call to a function that is in a DLL.
 *
 * Called by the parser when it founds CALL SHARED <id> IN <id>()
 *
 * @param libfile The library file name (without .so)
 * @param funcname The function name
 * @param _nargs Number of arguments.
 */
void
xxx_deleteme_print_call_shared_g (t_expr_str_list *expr, char *libfile, char *funcname,struct expr_str_list *returning_values,int yylineno)
{
  int nargs;
  printc ("{int _retvars;\n");
  expr=A4GL_rationalize_list(expr);
  real_print_expr_list (expr);
  nargs=A4GL_new_list_get_count(expr);

  if (is_in_report()) { set_doing_a_report_call(); }
  if (A4GL_doing_pcode()) {
	printc ("A4GLSTK_setCurrentLine(\"%s\",%d);", cmodname,yylineno);
  } else {
  	printc ("A4GLSTK_setCurrentLine(_module_name,%d);", yylineno);
  }
  printc ("A4GLSQL_set_status(0,0);_retvars=A4GL_call_4gl_dll(%s,%s,%d);\n",
	  libfile, funcname, nargs);
  print_reset_state_after_call(0);
  print_returning_g(3,returning_values,0);
  if (is_in_report()) { clr_doing_a_report_call(5); }
}



/**
 * Generate a string with the C code corresponding to the optional AT or TO from
 * display 4gl statement.
 *
 * The string generated should be used with a SPRINTF because is generated
 * a format string (with %s, etc).
 *
 * Foreach diferent type the generated C could call a diferent library function.
 *
 * @param type
 *   - 0 : Not AT substatement found.
 *   - 1 : Found AT <screen_coordinates>.
 *   - 2 : Found TO <field_list> substatement.
 *   - 3 : Found TO FORM <formname> FIELD <field_list>
 *   - 4 : Found TO MAIN CAPTION
 *   - 5 : Found TO FORM <formname> CAPTION
 * @param s The field list.
 *   - 0 : No .
 * @param f The form name (in 3 type only)
 *   - 0 : No form name.
 */
char *
xxx_deleteme_A4GL_get_display_str (int type, char *s, char *f)
{
  static char buff[1024];
  if (type == 0)
    strcpy (buff, "A4GL_display_at(%d,%s);\n");
  if (type == 1)
    strcpy (buff, "A4GL_display_at(%d,%s);");
  if (type == 2)
    SPRINTF1 (buff, "A4GL_disp_fields(%%d,%%s,%s,NULL);\n", s);
  if (type == 3)
    SPRINTF2 (buff, "A4GL_disp_form_fields(%%d,%%s,\"%s\",%s,NULL);\n", f, s);
  if (type == 4)
    SPRINTF0 (buff, "A4GL_disp_main_caption();\n");
  if (type == 5)
    SPRINTF1 (buff, "A4GL_disp_form_caption(%s);\n", s);
  return buff;
}



/**
 * Print to the generated C output file the implementation of DISPLAY
 * 4gl statement.
 *
 * @param fmt The strng generated by get_display_str().
 * @param expr The expression to be displayed.
 * @param attr The attributes used in display.
 */
void
xxx_deleteme_print_display_new (t_expr_str_list *expr, struct dt_display *disp,  char *attr,char *Style)
{
	int nexpr;
	int cnt;
	struct fh_field_list *fh;
        expr=A4GL_rationalize_list(expr);
	nexpr=A4GL_new_list_get_count(expr);
	

	switch(disp->dttype) {
		case DT_DISPLAY_TYPE_LINE		: 
				real_print_expr_list(expr);
				printc("A4GL_push_int(-1);");
				printc("A4GL_push_int(-1);");
				printc("A4GL_display_at(%d,%s);",nexpr,attr);
				break;

		case DT_DISPLAY_TYPE_AT			:
				real_print_expr_list(expr);
				real_print_expr(disp->dt_display_u.x_y.y);
				real_print_expr(disp->dt_display_u.x_y.x);
				printc("A4GL_display_at(%d,%s);",nexpr,attr);
				      
				break;

		case DT_DISPLAY_TYPE_MENUITEM		:
				//real_print_expr_list(expr);
				printc("#error not implemented yet");
				break;
					// My 4 year old son wanted typed this in:
					// james

		case DT_DISPLAY_TYPE_MAIN_CAPTION	:
				real_print_expr_list(expr);
  				printc ("A4GL_disp_main_caption();\n");
				break;

		case DT_DISPLAY_TYPE_FIELD_LIST		:
			                fh=disp->dt_display_u.field_list;
                			//if (nexpr!=fh->nfields) {
						//printf("FIELDMISMATCH %d != %d\n",nexpr,fh->nfields);
					//}

				real_print_expr_list(expr);
					if (A4GL_doing_pcode()) {
					for (cnt=fh->field_list_entries.field_list_entries_len-1;cnt>=0;cnt--) {
					char *ptr_field;
					        ptr_field=A4GL_field_name_as_char(&fh->field_list_entries.field_list_entries_val[cnt]);
  						printc ("A4GL_disp_fields(%d,%s,%s,NULL);\n", nexpr,attr,ptr_field);
					}
	}
					else {
					printc ("A4GL_disp_fields(%d,%s,%s,NULL);\n", nexpr,attr,local_field_name_list_as_char(disp->dt_display_u.field_list));
					}
				break;

		case DT_DISPLAY_TYPE_FORM_FIELD		:
				real_print_expr_list(expr);
    				printc ("A4GL_disp_form_fields(%d,%s,\"%s\",%s,0);\n", nexpr,attr,disp->dt_display_u.fldform_field.form, 
								local_field_name_list_as_char(disp->dt_display_u.fldform_field.field_list));

				break;

		case DT_DISPLAY_TYPE_FORM_CAPTION	:
				printc("A4GL_disp_form_caption(%s);\n",disp->dt_display_u.caption);
				break;

		case DT_DISPLAY_TYPE_STATUSBOX		:
				printc("#error not implemented yet");
				break;
	}
  	//printc (fmt, nexpr, attr);
}

/**
 * Print to the generated C output file, the implementation of the DISPLAY
 * FORM 4gl statement.
 *
 * @param s The name of the form.
 * @param a The attributes used to open the form.
 */
void
xxx_deleteme_print_display_form (char *s, char *a,char *Style)
{
  printc ("A4GL_disp_form(%s,%s);\n", s, a);
}



/**
 * Generate the C implementation of boolean OR expression.
 *
 * Its only used in INPUT and CONSTRUCT 4gl statements.
 *
 * @param out The pointer of the variable where the code it will be writed.
 * @param in1 The left part of boolean expression.
 * @param in2 The right part of boolean expression.
 */
void
xxx_deleteme_A4GL_generate_or (char *out, char *in1, char *in2)
{
  SPRINTF2 (out, "%s||%s", in1, in2);
}



/* ***************************************************************************/
/* INPUT */
/* ***************************************************************************/

/**
 * The parser found the first part of the INPUT 4gl statement.
 *
 * It generates the C implementation for the statement.
 */
void
xxx_deleteme_print_input_1 (void)
{
  printc ("} /* end of initialization */\n");
}

/**
 * The parser found END INPUT and generate all the C code that implements 
 * the rest of the instruction.
 *
 * @param s The generated code to call the form loop 
 *   (generated by get_formloop_str())
 */
void
xxx_deleteme_print_input_2 (char *s)
{
 int sio_id;
  A4GL_add_event(A4GL_EVENT_AFTER_INP_CLEAN,"");
  printc("if (_exec_block==%d) { break; } ",A4GL_get_nevents());
  printc("{");
  print_event_list(NULL);
  printc("A4GL_ensure_current_window_is(_curr_win);");
  printc ("_exec_block=%s;_forminit=0;\n", s);
  
  printc("if (_exec_block>0) _fld_dr=_sio_evt[_exec_block-1].event_type; else _fld_dr= -1;");
  printc("}");


  add_continue_blockcommand ("INPUT");
  printc ("\n}\n");
  sio_id=get_sio_ids("INPUT");
  pop_blockcommand ("INPUT");
  printc("A4GL_finish_screenio(&_sio_%d,_sio_kw_%d);",sio_id,sio_id);

  printc ("}\n");

  /* print_reset_state_after_call(); */


  /*}*/
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
void
xxx_deleteme_print_input_fl_g (int byname, char *defs, char *helpno, struct fh_field_list *fldlist_fh, char *sattr,char *Style,struct expr_str_list *bind)
{
  int ccc;
  int sio_id;
char *fldlist=0;
  if (fldlist_fh) {
	fldlist=local_field_name_list_as_char(fldlist_fh);
  }
  printc ("/*");
  push_blockcommand ("INPUT"); 
  printc ("*/");
  sio_id=get_sio_ids("INPUT");
  printc ("{\nint _fld_dr= -100;\nint _exec_block= 0;\nchar *_fldname;char *_curr_win;\n");
  ccc = print_bind_dir_definition_g (bind,1,'i');
  printc("char _sio_%d[%d];", sio_id,sizeof (struct s_screenio) + 10);
  printc("char _inp_io_type='I';");
  printc("char *_sio_kw_%d=\"s_screenio\";", sio_id);
  printc ("int _forminit=1;\n");
  printc ("while(_fld_dr!=0){\n");
  printc ("if (_fld_dr== -100) {\n");
  printc ("/* input by name */");
  local_print_bind_set_value_g (bind,1,0,'i');
  printc ("_curr_win=A4GL_get_currwin_name();\n");
  printc ("SET(\"s_screenio\",&_sio_%d,\"currform\",A4GL_get_curr_form(1));\n",sio_id);
  printc ("if (GET_AS_INT(\"s_screenio\",&_sio_%d,\"currform\")==0) break;\n",sio_id);
  printc ("SET(\"s_screenio\",&_sio_%d,\"vars\",ibind);\n",sio_id);
  printc ("SET(\"s_screenio\",&_sio_%d,\"attrib\",%s);\n",sio_id, sattr);
  printc ("SET(\"s_screenio\",&_sio_%d,\"novars\",%d);\n",sio_id, ccc);
  printc ("SET(\"s_screenio\",&_sio_%d,\"help_no\",%s);\n",sio_id, helpno);

  printc ("SET(\"s_screenio\",&_sio_%d,\"processed_onkey\",0);\n",sio_id);
  printc ("SET(\"s_screenio\",&_sio_%d,\"field_list\",0);\n",sio_id);

  printc ("SET(\"s_screenio\",&_sio_%d,\"currentfield\",0);\n",sio_id);
  printc ("SET(\"s_screenio\",&_sio_%d,\"currentmetrics\",0);\n",sio_id);
  printc ("SET(\"s_screenio\",&_sio_%d,\"mode\",%d+%s);\n",sio_id, MODE_INPUT, defs);


// @FIXME...
A4GL_assertion(1,"field list should be set for a byname too");
  if (byname)
    {
      printc
	("SET(\"s_screenio\",&_sio_%d,\"nfields\",A4GL_gen_field_chars((void ***)GETPTR(\"s_screenio\",&_sio_%d,\"field_list\"),(void *)GET(\"s_screenio\",&_sio_%d,\"currform\"),",sio_id,sio_id,sio_id);
      print_field_bind (bind);
      printc
	(",NULL));\nif (GET_AS_INT(\"s_screenio\",&_sio_%d,\"nfields\")==-1) break;\n",sio_id);
    }
  else
    {
      printc
	("SET(\"s_screenio\",&_sio_%d,\"nfields\",A4GL_gen_field_chars((void ***)GETPTR(\"s_screenio\",&_sio_%d,\"field_list\"),(void *)GET(\"s_screenio\",&_sio_%d,\"currform\"),%s,NULL));\n", sio_id,sio_id,sio_id,
	 fldlist);
      printc
	("if (GET_AS_INT(\"s_screenio\",&_sio_%d,\"nfields\")==-1) break;\n",sio_id);
    }
  printc
    ("{int _sf; _sf=A4GL_set_fields(&_sio_%d); A4GL_debug(\"_sf=%%d\",_sf);if(_sf==0) {_fld_dr=0;break;}\n}\n",sio_id);
  printc ("_fld_dr= -1;_exec_block=0;\n");
}

#ifdef MOVED
/**
 * Print the generated C code that implements the INPUT ARRAY 4gl statement.
 *
 * @param arrvar
 * @param helpno
 * @param defs
 * @param srec
 * @param attr
 */
char *
xxx_deleteme_print_input_array (char *arrvar, char *helpno, char *defs, char *srec, char *attr, void *v_input_attr,char *Style,struct expr_str_list* bind,char *slice,int inp_flags, int start_slice, int end_slice)
{
  static char buff2[256];
  int cnt;
  int sio_id;
  int i_defs;
  struct input_array_attribs *ptr_input_attr;
  ptr_input_attr = (struct input_array_attribs *) v_input_attr;
  printc ("/*");
   
   push_blockcommand ("INPUT"); 
  sio_id=get_sio_ids("INPUT");
  printc ("*/");
  i_defs=atoi(defs);
  printcomment ("/* input */\n");
  printc ("{int _fld_dr= -100;int _exec_block= 0;\nchar *_fldname;char *_curr_win; \nint _forminit=1;");
  printc ("char _sio_%d[%d];char _inp_io_type='A';char *_sio_kw_%d=\"s_inp_arr\";\n",sio_id,
	  sizeof (struct s_inp_arr) + 10,sio_id);
  cnt = print_arr_bind_g (bind,'o');
  printc ("while (_fld_dr!=0) {\n");
  printc ("if (_exec_block==0) {\n");
  printc ("_curr_win=A4GL_get_currwin_name();\n");
  if (i_defs) {
  	printc ("SET(\"s_inp_arr\",_sio_%d,\"no_arr\",A4GL_get_count());\n",sio_id);
  } else {
  	printc ("SET(\"s_inp_arr\",_sio_%d,\"no_arr\",0);\n",sio_id);
  }
  printc ("SET(\"s_inp_arr\",_sio_%d,\"binding\",obind);\n",sio_id);
  printc ("SET(\"s_inp_arr\",_sio_%d,\"nbind\",%d);\n",sio_id, cnt);
  printc ("SET(\"s_inp_arr\",_sio_%d,\"srec\",0);\n",sio_id);
  printc ("SET(\"s_inp_arr\",_sio_%d,\"scr_dim\",0);\n",sio_id);
  printc ("SET(\"s_inp_arr\",_sio_%d,\"inp_flags\",%d);\n",sio_id, inp_flags);
  printc ("SET(\"s_inp_arr\",_sio_%d,\"help_no\",%s);\n",sio_id, helpno);
  printc
    ("SET(\"s_inp_arr\",_sio_%d,\"arr_elemsize\",sizeof(%s[0]));\n",sio_id, arrvar);
  printc
    ("SET(\"s_inp_arr\",_sio_%d,\"arr_size\",sizeof(%s)/sizeof(%s[0]));\n",sio_id,
     arrvar, arrvar);
  printc ("SET(\"s_inp_arr\",_sio_%d,\"currform\",A4GL_get_curr_form(1));\n",sio_id);
  printc ("SET(\"s_inp_arr\",_sio_%d,\"inp_flags\",%d);\n",sio_id, inp_flags);
  printc ("if (GET_AS_INT(\"s_inp_arr\",_sio_%d,\"currform\")==0) break;\n",sio_id);
  printc ("SET(\"s_inp_arr\",_sio_%d,\"currentfield\",0);\n",sio_id);


  	printc ("SET(\"s_inp_arr\",_sio_%d,\"start_slice\",%d);\n",sio_id,start_slice);
  	printc ("SET(\"s_inp_arr\",_sio_%d,\"end_slice\",%d);\n",sio_id,end_slice);

  printc ("SET(\"s_inp_arr\",_sio_%d,\"mode\",%d+%s);\n",sio_id, MODE_INPUT, defs);

  if (ptr_input_attr->curr_row_display && strlen(ptr_input_attr->curr_row_display))
    printc ("SET(\"s_inp_arr\",_sio_%d,\"curr_display\",%s);\n",sio_id,
	    ptr_input_attr->curr_row_display);
  else
    printc ("SET(\"s_inp_arr\",_sio_%d,\"curr_display\",0);\n",sio_id);


  if (ptr_input_attr->count)
    {
      printc ("SET(\"s_inp_arr\",_sio_%d,\"count\",%s);\n",sio_id,
	      ptr_input_attr->count);
      printc ("A4GL_push_long(%s); aclfgl_set_count(1);\n",
	      ptr_input_attr->count);
    }
  else
    printc ("SET(\"s_inp_arr\",_sio_%d,\"count\",-1);\n",sio_id);

  if (ptr_input_attr->maxcount)
    printc ("SET(\"s_inp_arr\",_sio_%d,\"maxcount\",%s);\n",sio_id,
	    ptr_input_attr->maxcount);
  else
    printc ("SET(\"s_inp_arr\",_sio_%d,\"maxcount\",-1);\n",sio_id);

  printc ("SET(\"s_inp_arr\",_sio_%d,\"allow_insert\",%d);\n",sio_id,
	  ptr_input_attr->allow_insert);
  printc ("SET(\"s_inp_arr\",_sio_%d,\"allow_delete\",%d);\n",sio_id,
	  ptr_input_attr->allow_delete);

  printc ("SET(\"s_inp_arr\",_sio_%d,\"nfields\",A4GL_gen_field_chars((void ***)GETPTR(\"s_inp_arr\",_sio_%d,\"field_list\"),(void *)GET(\"s_inp_arr\",_sio_%d,\"currform\"),A4GL_add_dot_star(%s),NULL,0));\n",sio_id,sio_id,sio_id, srec);

 
  printc ("_fld_dr= -1;");
  printc("_exec_block=-1;");
  printc("ERR_CHK_ERROR { break;} ");
  printc("continue;\n");
   print_reset_state_after_call(0); 
  SPRINTF4 (buff2, "A4GL_inp_arr_v2(&_sio_%d,%s,%s,%s,_forminit,_sio_evt);\n", sio_id,defs, srec, attr);
  return buff2;
}

/**
 * Prints the C code that implements the call to form loop.
 *
 * Called by the parser when found the first part of the INPUT 4gl statement.
 *
 * @param type :
 *   - 0 : INPUT, INPUT BY NAME.
 *   - Otherwise : Never called with other values.
 * @return A string with the C code that calls form_loop().
 */
char *
xxx_deleteme_A4GL_get_formloop_str (int type)
{
static char buff[256];
  if (type == 0)		/* Input, Input by name */ {
	SPRINTF1(buff, "A4GL_form_loop_v2(&_sio_%d,_forminit,_sio_evt)",get_sio_ids("ALLINPUT"));
	return buff;
  }

  return "";
}
#endif

/**
 * The parser found the SCROLL 4gl statement (screen arrays).
 *
 * Print the C code that implements it.
 *
 * @param flds The field list to be scrolled.
 * @param updown A string that indicates if the sroll should be made up in the
 * form or down.
 */
void
xxx_deleteme_print_scroll (char *flds, char *updown)
{
  printc ("A4GL_acli_scroll(%s,%s,NULL,0);\n", updown,flds);
}


/**
 * Print the C implementation to the LABEL 4gl statement in the generated output
 * file.
 *
 * @param s The label name.
 */
void
xxx_deleteme_print_label (char *s)
{
  printc ("%s: /* LABEL */\n", s);
  printc("aclfgli_clr_err_flg();");
}

/**
 * The parser found a LET 4gl statement and implements the C code for it.
 *
 * @param nexprs The number of variable to be assigned.
 */
int
xxx_deleteme_print_let_manyvars_g (t_expr_str_list *ptr,struct expr_str_list *bind)
{
  int from_exprs;
  int to_vars;
  A4GL_debug ("1");
  real_print_expr_list(ptr);
  from_exprs=A4GL_new_list_get_count(ptr);
  printc ("{");
  to_vars = print_bind_dir_definition_g (bind,1,'o');
  local_print_bind_set_value_g (bind,1,0,'o');

  if (to_vars != from_exprs)
    {
      A4GL_debug ("to_Vars = %d from_Exprs = %d\n", to_vars, from_exprs);
      return 0;
    }

  printc ("A4GL_pop_params(obind,%d);\n", from_exprs);
  printc ("}\n");
  return 1;
}

/**
 * When an assignment is made to null this functions is called so the C
 * implementation push a null to the stack.
 */
void
xxx_deleteme_print_push_null (void)
{
  printc ("A4GL_push_null(2,0);\n");
}

/* Linked stuff */




/* *************************** REPORT **********************/

/**
 * The parser found the START REPORT 4gl statement.
 *
 * Generates the C implementation in the C output file.
 * 
 * @param where Where to be outputed the report:
 *   - P : Printer (piped to lp command) or Pipe.
 *   - F : File.
 *   - "" : Standard output.
 * @param out The name of the output file or piped command.
 * @param repname The report name.
 */
void
xxx_deleteme_print_start_report (char *where, t_expr_str *out, char *repname,char *dim)
{
	
  add_function_to_header (repname, "namespace", 2,0);
  // @ todo - fixup 'out' handling
  // Background - historically, 'out' was a string  (either literal or a string variable)
  // we can now use an expression instead - but all we've done here is a quick hack to pop
  // the expression from the stack and then put it back in the right place (ie in the order the report is expected it - after the 'where')
  // We need to do this properly by not popping it at all and just getting the start report to pop them off in the right 
  // order - but this might break previously compiled code 
  // (So we're leaving it to work with this kludge for now)


  printc ("A4GL_push_char(\"%s\");\n", where);
  printc(" /* rout... */");

  if (out) { 
	 	print_expr(out); 
  } else {
  	printc ("A4GL_push_char(\"%s\");\n", where);
  }

  printc ("A4GL_set_report_dim(%s);", dim);
  //printc("if (_rout_to) free(_rout_to);}");
  printc ("%s%s(2,REPORT_START);", get_namespace (repname), repname);
}


/**
 * Generate the C implementation of the OUTPUT TO REPORT statement.
 *
 * @param repname The name of the report
 * @param nvalues The number of parameters to be passed to the report (they
 * should be pushed to the stack).
 */
void
xxx_deleteme_print_output_to_report (t_expr_str_list *expr, char *repname)
{
long nvalues;

        expr=A4GL_rationalize_list(expr);
nvalues=A4GL_new_list_get_count(expr);
real_print_expr_list(expr);
  add_function_to_header (repname, "namespace", 2,0);
  printc ("%s%s(%d,REPORT_SENDDATA);\n", get_namespace (repname), repname,
	  nvalues);
}

/**
 * The parser found the FINISH REPORT statement.
 *
 * Generate the C implementation.
 *
 * @param repname The name of the report.
 */
void
xxx_deleteme_print_finish_report (char *repname)
{
  add_function_to_header (repname, "namespace", 2,0);
  printc ("%s%s(0,REPORT_FINISH);\n", get_namespace (repname), repname);
}

/**
 * The parser found the TERMINATE REPORT statement.
 *
 * Generate the C implementation.
 *
 * @param repname The name of the report.
 */
void
xxx_deleteme_print_terminate_report (char *repname)
{
  add_function_to_header (repname, "namespace", 2,0);
  printc ("%s%s(0,REPORT_TERMINATE);\n", get_namespace (repname), repname);
}


/**
 * The parser found the ON EVERY ROW instruction from reports.
 *
 * Generate the C implementation to the output file.
 */
void
xxx_deleteme_print_format_every_row (struct expr_str_list* bind, int report_cnt)
{
  push_report_block ("EVERY", 'E',"");

  printc ("{int _rr;for (_rr=0;_rr<%d;_rr++) {", bind->list.list_len);
  printc ("A4GL_push_char(_rbindvarname[_rr]);\n");
  printc ("A4GL_%srep_print(&_rep,1,1,0,-1); A4GL_push_long(19); A4GL_set_column(&_rep);A4GL_%srep_print(&_rep,1,1,0,-1); \n",ispdf(),ispdf());
  printc ("A4GL_push_variable(_rbind[_rr].ptr,_rbind[_rr].dtype);");
  printc ("A4GL_%srep_print(&_rep,1,1,0,-1); A4GL_%srep_print(&_rep,0,0,0,-1);\n",ispdf(),ispdf());
  printc ("}");
  printc ("A4GL_push_char(\" \");");
  printc ("A4GL_%srep_print(&_rep,1,1,0,-1); A4GL_%srep_print(&_rep,0,0,0,-1);",ispdf(),ispdf());
  printc ("}");
  print_rep_ret (report_cnt,0);

}

/**
 * Print the C implementation of NEED <number> LINES statement.
 */
void
xxx_deleteme_print_need_lines (t_expr_str *expr)
{
	real_print_expr(expr);
  printc ("A4GL_%sneed_lines(&_rep);\n", ispdf ());
}

/**
 * Print the C implementation of SKIP <number> LINES statement.
 */
void
xxx_deleteme_print_skip_lines (double d)
{
  printc ("A4GL_push_int(%d);", (int) d);
  printc ("A4GL_%saclfgli_skip_lines(&_rep);\n", ispdf ());
}

/**
 * Print the C implementation of the SKIP TO TOP OF PAGE statement.
 */
void
xxx_deleteme_print_skip_top (void)
{
  printc ("A4GL_%sskip_top_of_page(&_rep,0);\n", ispdf ());
}

/**
 * Print the C implementation of SKIP BY statement.
 */
void
xxx_deleteme_print_skip_by (double nval)
{
  printc ("A4GL_pdf_skip_by(&_rep,%f);\n", nval);
}



/**
 * Defines in the generated C code, the type of the order by used.
 *
 * @param type The type of order by:
 *   - 1 : Normal order by or not defined.
 *   - 2 : The order is external to the report (made in the select statement).
 */
int
xxx_deleteme_print_order_by_type (int type, int size,struct expr_str_list *ordbind)
{
int a;

  a=print_bind_dir_definition_g(ordbind,1,'O');
  if (size==0) size=a;
  printc ("static int acl_rep_ordcnt=%d;\n", size);
	if (type==1) {
  		last_orderby_type = 1;
  		printc ("static int fgl_rep_orderby=1;\n", type);
	} else {
  		last_orderby_type = 2;
  		printc ("static int fgl_rep_orderby=2;\n", type); // external - no further ordering required
	}

  return a;

}

/**
 * Called after the REPORT <reportName> and open bracket found in the 
 * source code.
 *
 * Generate the necessary C code that is the begining of the C function that
 * implements the report.
 *
 * The function name is mangled with acl_fglr_ before the 4gl report name.
 *
 * @param name The name of the report.
 */
void
xxx_deleteme_print_report_1 (char *name)
{
  strcpy (mv_repname, name);
  add_function_to_header (name,"namespace",  2,0);
  printc ("A4GL_REPORT void %s%s (int _nargs,int acl_ctrl) {\n", get_namespace (name), name, name);
  printc("static char *_reportName=\"%s\";\n",name);
  rep_print_code=0;
}

/**
 * The parser found the END REPORT and closes the generated C function.
 */
void
xxx_deleteme_print_report_end (void)
{


  printc ("\n} /* end of report */\n");
  //doing_a_report=0;
}

/**
 * Print the generated C code of the PAUSE report statement.
 *
 * The pause report is when the report is showed to the stdout and the
 * user gets a pause between pages and strike new lineto pass to the next one.
 *
 * @pause msg The message to display when it pauses.
 */
void
xxx_deleteme_print_pause (char *msg)
{
  printc ("A4GL_pause(%s);\n", msg);
}

/* MISC */

/**
 * Called when sleep instruction is found prints the target language sleep
 * function call.
 */
void
xxx_deleteme_print_sleep (t_expr_str* expr)
{
  real_print_expr(expr);
  printc ("A4GLSQL_set_status(0,0); A4GL_sleep_i();\n");
}


/* EXPRESSIONS */

/**
 *
 * @todo Describe function
 */
void
xxx_deleteme_print_op (char *type)
{
  printc ("A4GL_pushop(%s);\n", type);
}




/**
 * Generates the C implementation of the MESSAGE statement.
 *
 * @param type Allways 0.
 * @param attr Attributes used in message.
 * @param wait The time that it waits.
 */
void
xxx_deleteme_print_message (t_expr_str_list *expr, int type, char *attr, int wait,char *Style) 
{
	int exprs;
        expr=A4GL_rationalize_list(expr);
	exprs=A4GL_new_list_get_count(expr);
  real_print_expr_list(expr);
  if (type == 0)
    printc ("aclfgli_pr_message(%s,%d,%d);\n", attr, wait, exprs);
  else
    printc ("aclfgli_pr_message_cap(%d,%d,%d);\n", attr, wait, exprs);
}




/**
 *
 */
void
xxx_deleteme_print_undo_use (char *s)
{
  printc (s);
}






/**
 * FIXME: what is this?
 *
 * @param s
 */
char *
xxx_deleteme_A4GL_decode_array_string (char *var,char *s)
{
  static char buff[2000] = "";
  int a;
  char tmp[2] = "X";		/*  Just to get a terminator on it */
  strcpy (buff, "(");

  for (a = 0; a < strlen (s); a++)
    {
      if (s[a] == ',')
	{
	  strcat (buff, ")-1][(");
	}
      else
	{
	  tmp[0] = s[a];
	  strcat (buff, tmp);
	}
    }
  strcat (buff, ")-1");
  return buff;
}



/**
 *
 * @todo Describe function
 */
char *
xxx_deleteme_A4GL_get_into_part (int doing_declare, int no)
{
  static char buffer[40000];
  int a;
  if (doing_esql ())
    {
      char buff[300];


      if (no == 0)
	return "";

      SPRINTF0 (buffer, "INTO \n");
      for (a = 0; a < no; a++)
	{
	  if (! A4GLSQLCV_check_requirement ("USE_INDICATOR"))
	    {
	      SPRINTF1 (buff, "\t:_vo_%d\n", a);
	    }
	  else
	    {
		
	  if (esql_type()==E_DIALECT_INFOFLEX) {
	      SPRINTF2 (buff, "\t:_vo_%d  :_voi_%d\n", a, a);
		 } else {
	      SPRINTF2 (buff, "\t:_vo_%d INDICATOR :_voi_%d\n", a, a);
		}
	    }
	  if (a)
	    strcat (buffer, ",");
	  strcat (buffer, buff);
	}
    }
  else
    {
      return "";
    }
  return buffer;
}

/**
 *
 * @todo Describe function
 */
char *
xxx_deleteme_A4GL_set_var_sql (int doing_declare, int n, char *current_upd_table)
{
  int a;
  static char buff[64000];
  //extern char *current_upd_table;
#define UPDVAL2 4

  if (doing_esql ())
    {
      int z;
      z = get_bind_cnt ('i');
      strcpy (buff, "");
      for (a = z - n; a < z; a++)
	{
	  char buff_small[80];
	  if (a != z - n)
	    {
	      strcat (buff, ",");
	    }

      if (A4GLSQLCV_check_requirement ("USE_INDICATOR") && !A4GL_isno(acl_getenv("USE_INDICATOR"))) {
	  if (esql_type()==E_DIALECT_INFOFLEX) {
	  SPRINTF2 (buff_small, " :_vi_%d  :_vii_%d \n", a,a);
	  } else {
	  SPRINTF2 (buff_small, " :_vi_%d INDICATOR :_vii_%d \n", a,a);
          }
	} else {
	  SPRINTF1 (buff_small, " :_vi_%d\n", a);
	}

	  strcat (buff, buff_small);

	  if (current_upd_table)
	    {
	      A4GL_4glc_push_gen (UPDVAL2, buff_small);
	    }
	}
      return buff;
    }
  else
    {
      strcpy (buff, "");
      for (a = 0; a < n; a++)
	{
	  if (a > 0)
	    {
	      strcat (buff, ",");
	    }

	  if (current_upd_table)
	    {
	      A4GL_4glc_push_gen (UPDVAL2, "?");
	    }
	  strcat (buff, "?");
	}
      return buff;
    }
}



void
xxx_deleteme_add_class_function_to_header (char *identifier, int params,char* is_static)
{

char buff[255];
SPRINTF1(buff,"CLASSFUNC_%s",identifier);
identifier=buff;
  if (is_builtin_func (identifier))
    return;


  if (!A4GL_has_pointer (identifier, FEATURE_USED))
    {
      A4GL_add_pointer (identifier, FEATURE_USED, (void *) 1);
      if (params == 1)		/* Normal Function*/
	printh ("A4GL_FUNCTION %s int %s%s (int n);\n",is_static,
		get_namespace (identifier), identifier);
      if (params == 2)		/* Report...*/
	printh ("A4GL_REPORT void %s%s (int n,int a);\n",
		get_namespace (identifier), identifier);
    }


}



void
xxx_deleteme_print_foreach_close (char *cname)
{
  printc("if (_cursoropen) {");
  print_close ('C', cname);
  printc("if (a4gl_status == 0) { if (_fetcherr) {A4GLSQL_set_status(_fetcherr,1);}}");
  printc("if (a4gl_status == 100) { if (_fetcherr) {a4gl_sqlca.sqlcode = a4gl_status=_fetcherr;} else {a4gl_sqlca.sqlcode = a4gl_status = 0; }}");
  printc("}");

  printc("}");
}


void
xxx_deleteme_print_empty_bind (char *name)
{
  printc ("static struct BINDING *%s=0;\n", name);
}


void
xxx_deleteme_print_execute_immediate (char *stmt)
{
  static int cnt = 0;
  char buff[256];
  if (A4GLSQLCV_check_requirement ("FAKE_IMMEDIATE") || !doing_esql ())
    {
      SPRINTF2 (buff, "\"p_%d_%lx\"", cnt++, time (0));
      print_prepare (buff, stmt);
      print_execute_g (buff, 0,empty_genbind('i'),empty_genbind('o'));
    }
  else
    {
      if (stmt[0] == '"')
	{
	  printc ("EXEC SQL EXECUTE IMMEDIATE '%s';", A4GL_strip_quotes(stmt));
	}
      else
	{
	  printc ("{");
	  printc ("EXEC SQL BEGIN DECLARE SECTION;");
	  printc ("char *acl_ei_s;");
	  printc ("EXEC SQL END DECLARE SECTION;");
	  printc ("acl_ei_s=%s;", stmt);
	  printc ("EXEC SQL EXECUTE IMMEDIATE :acl_ei_s;");
	  printc ("}");
	}
    }
}



void
xxx_deleteme_print_alloc_arr (char *s, char *d)
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
  printc ("%s=A4GL_alloc_dynarr(&%s,%s,%d,%d,%d,%d,%d,%d * sizeof(%s[0]),0);", s,s, s,dim[0],dim[1],dim[2],dim[3],dim[4],l, s);
  /*printc ("%s=acl_malloc2(%d * sizeof(%s[0]));", s, l, s);*/
}

void
xxx_deleteme_print_dealloc_arr (char *s)
{
  printc ("A4GL_dynarr_free(&%s,%s);", s,s);
}


#endif

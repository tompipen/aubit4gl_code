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
# $Id: compile_c.c,v 1.232 2005-06-24 09:19:01 mikeaubury Exp $
# @TODO - Remove rep_cond & rep_cond_expr from everywhere and replace
# with struct expr_str equivalent
*/
#ifndef lint
	static char const module_id[] =
		"$Id: compile_c.c,v 1.232 2005-06-24 09:19:01 mikeaubury Exp $";
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
int isin_command (char *cmd_type);
int print_bind_expr_portion (void *ptr, char i, int portion);

int suppress_lines=0;
char **get_field_codes(char *fields) ;
char *get_curr_report_stack_why(void);
struct expr_str *A4GL_add_validation_elements_to_expr(struct expr_str *ptr,char *val);
void A4GL_get_event(int n,int *i,char **s) ;
int A4GL_get_nevents(void) ;
void print_event_list (void);
int *get_key_codes(char *keys) ;
int rep_print_entry=0;
int doing_cs (void);
int get_validate_list_cnt(void) ;
char *A4GL_get_important_from_clobber(char *s);
void add_class_function_to_header (char *identifier, int params,char* is_static);
char* get_reset_state_after_call(void);
void print_reset_state_after_call(void);
static void
pr_nongroup_report_agg_clr (void);


/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_lib_lex_esqlc_int.h"

#define ONE_NOT_ZERO(x) (x?x:1)


int rep_print_code;
int last_orderby_type = -1;
void print_report_table (char *repname, char type, int c);
extern int get_rep_no_orderby (void);
int A4GL_doing_pcode (void);
static int gen_ord (char *s);
/*
=====================================================================
                    Variables definitions
=====================================================================
*/

char mv_repname[256];
int cs_ticker = 0;
int current_ordbindcnt = 0;
/** Pointer to the output C file */
static FILE *outfile = 0;

/** Pointer to the output header (.h) file */
static FILE *hfile = 0;

/** The output file name */
extern char *outputfilename;
extern char *curr_func;
extern char *infilename;

/** The source code linenumber */
extern int yylineno;
extern int lastlineno;
extern int inp_flags;


dll_import struct rep_structure rep_struct;


extern struct pdf_rep_structure pdf_rep_struct;
extern struct form_attr form_attrib;
extern int menu_cnt;
extern int ccnt;					/**< Block counter - defined in lexer.c */
extern char mmtitle[132][132];		/** Menu titles */
extern int report_stack_cnt;
extern int report_cnt;
extern int rep_type;
extern int sreports_cnt;
extern char when_to_tmp[64];
extern int ordbindcnt;
extern int ibindcnt;
extern int nullbindcnt;
extern int obindcnt;
extern int ebindcnt;
extern int fbindcnt;
extern int constr_cnt;


dll_import int when_code[8];
dll_import struct s_report sreports[1024];
dll_import struct s_menu_stack menu_stack[MAXMENU][MAXMENUOPTS];
dll_import struct binding_comp ibind[NUMBINDINGS];
dll_import struct binding_comp nullbind[NUMBINDINGS];
dll_import struct binding_comp obind[NUMBINDINGS];
dll_import struct binding_comp ebind[NUMBINDINGS];
dll_import struct binding_comp fbind[NUMBINDINGS];
dll_import struct binding_comp ordbind[NUMBINDINGS];
dll_import struct s_constr_buff constr_buff[256];
dll_import char when_to[8][128];
int doing_esql (void);
void make_sql_bind (char *sql, char *type);
char *make_sql_bind_expr (char *sql, char *type);
/*long get_variable_dets (char *s, int *type, int *arrsize, int *size, int *level, char *arr);*/
int split_arrsizes (char *s, int *arrsizes);
int esql_type (void);
void print_function_variable_init (void);
static void order_by_report_stack (void);

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

void printc (char *fmt, ...);
static void print_output_rep (struct rep_structure *rep);
static void print_form_attrib (struct form_attr *form_attrib);
static int print_field_bind (int ccc);
static int print_arr_bind (char i);
static int print_constr (void);
static int print_field_bind_constr (void);
static int pr_when_do (char *when_str, int when_code, int l, char *f,
		       char *when_to);
static void pr_report_agg (void);
static void pr_report_agg_clr (void);
static void print_menu (int mn, int n);


static void real_print_expr (struct expr_str *ptr);
static void real_print_func_call (char *identifier, struct expr_str *args,
				  int args_cnt);
static void real_print_class_func_call (char *var, char *identifier,
					struct expr_str *args, int args_cnt);
static void real_print_pdf_call (char *a1, struct expr_str *args, char *a3);

void printh (char *fmt, ...);

void add_function_to_header (char *identifier, int parms,char *is_static);
char *get_namespace (char *s);
void print_init_var (char *name, char *prefix, int alvl);
void printcomment (char *fmt, ...);
void LEXLIB_print_onaction_1 (char *key_list_str);
void LEXLIB_print_onaction_2 (void);
//int is_builtin_func (char *s);


/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * Print spaces to the increment acording to scope level generated in
 * target C code.
 */
static void
print_space (void)
{
  static char buff[256];
  memset (buff, ' ', 255);
  buff[ccnt * 3] = 0;
  fprintf (outfile, "%s", buff);
}


void set_suppress_lines(void) {
	suppress_lines++;
}

void clr_suppress_lines(void) {
	suppress_lines--;
}


/**
 * Open the ouput target C file
 */
static void
open_outfile (void)
{
  char h[132];
  char c[132];
  char err[132];
  char *ptr;

  if (outputfilename == 0)
    {
      A4GL_debug ("NO output file name");
    }

  strcpy (c, outputfilename);
  strcpy (h, outputfilename);
  strcpy (err, outputfilename);

  if (strcmp (acl_getenv ("NOCLOBBER"), "N") == 0)
    {
      A4GL_debug ("Clobbering...");
      set_clobber (outputfilename);
    }

  A4GL_debug ("Opening output map");

  openmap (outputfilename);

  ptr = acl_getenv ("NOCFILE");
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



	/* We'll get rid of this switch statement soon - use it to check our get_esql_ext function for now though */

      switch (esql_type ())
	{

	case 1:
	  if (strcmp(A4GL_get_esql_ext(),".ec")!=0)  printf("Unexpected extension for informix\n");
  		break;

	case 2:
	  if (strcmp(A4GL_get_esql_ext(),".cpc")!=0)  printf("Unexpected extension for postgres\n");
	  break;

	case 3:		/* SAPDB pre-compiler also uses .cpc extension */
	  if (strcmp(A4GL_get_esql_ext(),".cpc")!=0)  printf("Unexpected extension for SAP\n");
	  break;

	case 4:
	  if (strcmp(A4GL_get_esql_ext(),".sc")!=0)  printf("Unexpected extension for INGRES\n");
  		break;

	}
	strcat(c,A4GL_get_esql_ext());
    }
  else
    {
      if (strcmp (acl_getenv ("A4GL_LEXTYPE"), "CS") == 0)
	{
	  /* C#*/
	  strcat (c, ".csp");
	}
      else
	{
	  strcat (c, ".c");
	}
    }

  strcat (h, ".h");
  strcat (err, ".err");

  outfile = A4GL_mja_fopen (c, "w");
  if (outfile == 0)
    {
      printf ("Unable to open file %s (Check permissions)\n", c);
      exit (3);
    }

  A4GL_debug ("Output file is %s", c);

  fprintf (outfile, "#define fgldate long\n");
  if (doing_esql ())
    {
      switch (esql_type ())
	{
	case 1:
	  fprintf (outfile, "#define DIALECT_INFORMIX\n");
	  break;
	case 2:
	  fprintf (outfile, "#define DIALECT_POSTGRES\n");
	  break;
	case 3:
	  fprintf (outfile, "#define DIALECT_SAPDB\n");
	  break;
	case 4:
	  fprintf (outfile, "#define DIALECT_INGRES\n");
	  fprintf (outfile, "EXEC SQL INCLUDE SQLCA;\n");
	  break;

	}
    }


  if (strcmp (acl_getenv ("LEXTYPE"), "CS") == 0)
    {
      fprintf (outfile, "#define THIS_MODULE %s\n", outputfilename);
      fprintf (outfile, "#include \"cs_header.h\"\n");
    }
  else
    {
      fprintf (outfile, "#include \"a4gl_incl_4glhdr.h\"\n");
    }

  if (doing_esql ())
    {
      if (A4GLSQLCV_check_requirement ("USE_INDICATOR")) {
      		fprintf (outfile, "#define ESQL_USING_INDICATORS\n");
	}
	if (esql_type()==4) {
      		fprintf (outfile, "EXEC SQL WHENEVER SQLERROR CONTINUE;\n");
	}
      fprintf (outfile, "#include \"a4gl_esql.h\"\n");
    }

  if (strchr (h, '/') != 0)
    fprintf (outfile, "#include \"%s\"\n", strrchr (h, '/') + 1);
  else
    fprintf (outfile, "#include \"%s\"\n", h);


  if (doing_cs ())
    {
      fprintf (outfile, "static string module_name=\"%s.4gl\";\n",
	       outputfilename);
    }
  else
    {
      fprintf (outfile, "static char *_module_name=\"%s.4gl\";\n",
	       outputfilename);
    }


  hfile = A4GL_mja_fopen (h, "w");
  if (hfile == 0)
    {
      printf ("Unable to open file %s (Check permissions)\n", h);
      exit (3);
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
 * @param fmt the format to be passed to vsprintf
 * @param ... The variadic parameters to be passed to vsprintf
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

void
LEXLIB_A4GL_internal_lex_printc (char *fmt, va_list * ap)
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

  os=vsnprintf (buff, sizeof(buff),fmt, *ap);
if (os>=sizeof(buff)) {
	a4gl_yyerror("Internal error - string too big\n");
	exit(0);
} 



  if (A4GL_isyes (acl_getenv ("INCLINES")))
    {
      for (a = 0; a < strlen (buff); a++)
	{
	  if (buff[a] == '\n' )
	    {
		if (suppress_lines==0) {
	      		if (infilename != 0) { fprintf (outfile, "\n#line %d \"%s.4gl\"\n", yylineno, outputfilename); }
	      		else { fprintf (outfile, "\n#line %d \"null\"\n", yylineno); /* outputfilename); */ }
		} else {
	      		fprintf (outfile, "\n");
		}
	    }
	  else
	    {
	      fprintf (outfile, "%c", buff[a]);
	    }
	}
    }
  else
    {
      ptr = strtok (buff, "\n");
      while (ptr)
	{
	  print_space ();
	  fprintf (outfile, "%s\n", ptr);
	  ptr = strtok (0, "\n");
	}
    }

  /* Having this will really slow it down - only enable it if we are debugging... */
  if (strcmp (acl_getenv ("DEBUG"), "ALL") == 0) {
    fflush (outfile);
  }
}


/**
 * Print the generated definitions to the target header file (.h)
 *
 * If the output file is not opened call the open function.
 *
 * @param fmt the format to be passed to vsprintf
 * @param ... The variadic parameters to be passed to vsprintf
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
LEXLIB_A4GL_internal_lex_printh (char *fmt, va_list * ap)
{
/* va_list args; */
  if (outfile == 0)
    {
      open_outfile ();
    }
  if (outfile == 0)
    return;

  /* va_start (args, fmt);
     vfprintf (hfile, fmt, args);
   */

  vfprintf (hfile, fmt, *ap);

}

/**
 * Print comments to the C output file.
 *
 * If the output file is not opened call the open function.
 *
 * @param fmt the format to be passed to vsprintf
 * @param ... The variadic parameters to be passed to vsprintf
 */
void
printcomment (char *fmt, ...)
{
  va_list ap;
  va_start (ap, fmt);
  A4GL_internal_lex_printcomment (fmt, &ap);
}

void
/* A4GL_internal_printcomment (char *fmt,...) */
LEXLIB_A4GL_internal_lex_printcomment (char *fmt, va_list * ap)
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
         vfprintf (outfile, fmt, args);
       */
      vfprintf (outfile, fmt, ap);
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
 * Print the spaces corresponding to the scope level to have good
 * identation in the output source.
 */
void
LEXLIB_A4GL_incprint (void)
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
LEXLIB_print_repctrl_block (void)
{
  printc ("rep_ctrl%d_%d:\n", report_cnt, report_stack_cnt);

printc("A4GL_push_report_section(&_rep,_module_name,_reportName,%d,'%c',\"%s\",%d);",yylineno,get_curr_report_stack_whytype(),get_curr_report_stack_why(),rep_print_code);
rep_print_entry=0;

}


/**
 * Print the C include statement for header file
 */
void
LEXLIB_print_include (char *s)
{
  printc ("#include <%s.h>\n", s);
}

/**
 * Print the C implementation of the current report control block
 */
void
LEXLIB_print_report_ctrl (void)
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

  order_by_report_stack ();

  printc ("A4GL_debug(\"ctrl=%%d _nargs=%%d\",acl_ctrl,_nargs);\n");
  printc ("    if (acl_ctrl==REPORT_OPS_COMPLETE) return;\n\n");
  printc ("    if (acl_ctrl==REPORT_SENDDATA) {\n");
  printc ("   /* check for after group of */\n");
  printc ("       %s(0,REPORT_DATA);\n", get_curr_rep_name ());
  printc ("   /* check for before group of */\n");
  printc ("    }\n\n");


  printc ("if (acl_ctrl==REPORT_FINISH && _started==0) {");
  printc ("    A4GLSQL_set_status(-5555,0);\n");
  printc ("    return;\n");
  printc ("    }\n");
  printc ("if (acl_ctrl==REPORT_FINISH && _started) {%s(0,REPORT_LASTDATA);return;}\n",
	  get_curr_rep_name ());

  if (rep_type == REP_TYPE_NORMAL)
    {
      printc ("if (acl_ctrl==REPORT_LASTDATA) {");
      printc ("  if (_useddata) {");

      printc ("   %s(0,REPORT_LASTROW);", get_curr_rep_name ());
      printc ("   if (_rep.page_no<=1&&_rep.page_length>1) {A4GL_%srep_print(&_rep,0,1,0,-1);A4GL_%srep_print(&_rep,0,0,0,-1);}",ispdf(),ispdf());	/* MJA 13092003*/
      printc ("   _rep.finishing=1;");
      printc ("   A4GL_skip_top_of_page(&_rep,999);");
      printc ("}");
      printc ("  _started=0;");
      printc ("  if (_rep.output) {fflush(_rep.output); fclose(_rep.output);_rep.output=0;}");
      printc ("  return;");
      printc ("}\n");

    }
  else
    {
      printc
	("if (acl_ctrl==REPORT_LASTDATA) {if (_useddata) %s(0,REPORT_LASTROW);_started=0;A4GL_pdf_rep_close(&_rep);return;}\n",
	 get_curr_rep_name ());

    }

  if (rep_type == REP_TYPE_NORMAL)
    {
      printc
	("if (acl_ctrl==REPORT_TERMINATE) {_started=0;if (_rep.output) {fflush(_rep.output); fclose(_rep.output);_rep.output=0;}return;}\n",
	 get_curr_rep_name ());
    }
  else
    {
      printc
	("if (acl_ctrl==REPORT_TERMINATE) {_started=0;A4GL_pdf_rep_close(&_rep);return;}\n",
	 get_curr_rep_name ());

    }


  printc ("    if (acl_ctrl==REPORT_AFTERDATA ) {\n");
  pr_report_agg ();
  printc ("    }\n");


  printed_every=0;

  // We need to clear down any counters...
  printc(" if (acl_ctrl==REPORT_START||acl_ctrl==REPORT_RESTART) {");
pr_nongroup_report_agg_clr();
  printc("}");
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
	printc ("if (acl_ctrl==REPORT_DATA) {acl_ctrl=REPORT_AFTERDATA;goto rep_ctrl%d_%d;}\n", report_cnt, a);
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

      if (get_report_stack_whytype (a) == 'P')
	printc
	  ("if (acl_ctrl==REPORT_PAGEHEADER&&_rep.page_no==1) {acl_ctrl=0;goto rep_ctrl%d_%d;}\n",
	   report_cnt, a);

      if (get_report_stack_whytype (a) == 'p')
	printc
	  ("if (acl_ctrl==REPORT_PAGEHEADER&&(_rep.page_no!=1||(_rep.page_no==1&&_rep.has_first_page==0))) {acl_ctrl=0;goto rep_ctrl%d_%d;}\n",
	   report_cnt, a);
    }
	if (!printed_every) {
		printc ("if (acl_ctrl==REPORT_DATA) {acl_ctrl=REPORT_AFTERDATA;\n", report_cnt);
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
LEXLIB_print_range_check (char *var, char *size)
{
  printc ("A4GL_range_chk(%s,%d);\n", var, atoi (size));
}

/**
 * Print a C label to mark a start block
 *
 * @param n The block sequential number (used for the name of label)
 */
void
LEXLIB_print_start_block (int n)
{
  printc ("\n");
  printc ("START_BLOCK_%d: ;\n", n,n);
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
LEXLIB_print_continue_block (int n, int brace)
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
LEXLIB_print_end_block (int n)
{
  printc ("END_BLOCK_%d: ;\n\n", n,n);
}

/**
 * Print the C instruction that implements the specific continue loop.
 *
 * The loop(s) are implemented with while(s), label(s) and goto(s) in C
 *
 * @param n The loop number
 */
void
LEXLIB_print_continue_loop (int n, char *cmd_type)
{
  if (strcmp (cmd_type, "INPUT") == 0 || strcmp (cmd_type, "CONSTRUCT") == 0)
    {
      printc
	("if (_fld_dr==-95) {A4GL_req_field(&_sio_%d,_inp_io_type,'0',\"0\",0,0);} /* re-enter INPUT if we're in an AFTER INPUT */ \n",get_sio_id(cmd_type));
      printc ("_fld_dr= -1;_exec_block= -1;\n");
    }

  if (strcmp (cmd_type, "INPUTREQ") == 0
      || strcmp (cmd_type, "CONSTRUCTREQ") == 0)
    {
      printc ("_fld_dr= -1;_exec_block= -1;\n");
    }


  printc ("goto CONTINUE_BLOCK_%d;", n);
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
LEXLIB_print_exit_loop (int type, int n)
{
  if (type == 'M')
    {
      printc ("cmd_no_%d= -3;goto MENU_START_%d;\n", n, n);
    }
  if (type == 'P')
    {
      printc ("SET(\"s_prompt\",_sio_%d,\"mode\",1);\n",get_sio_id("PROMPT"));
    }
  if (type == 0)
    {
      printc ("goto END_BLOCK_%d;", n);
    }
}


/**
 *  Print the C code corresponding to the last A4GL_action in a format A4GL_action of
 *  a report.
 */
void
/* print_rep_ret (void) */
LEXLIB_print_rep_ret (int report_cntx,int addit)
{
  if (addit) printc("A4GL_pop_report_section(&_rep,%d);",rep_print_code++);
  printc ("goto report%d_ctrl; /* G1 */\n\n", report_cnt);
}

/**
 * Called by print_report_2() generate the C code taht implements the 
 * assignments that should be done when an output to report is executed.
 *
 * This implementation is specific for text only reports.
 *
 * @param rep The report control structure.
 */
static void
print_output_rep (struct rep_structure *rep)
{
  printc ("output_%d:\n", report_cnt);
  //print_bind_set_value('O');
  printc ("_rep.lines_in_header=-1;\n");
  printc ("_rep.lines_in_trailer=-1;\n");
  printc ("_rep.lines_in_first_header=-1;\n");
  printc ("_rep.print_section=0;\n");
  printc ("_rep.top_margin= A4GL_set_report_dim_int(\"TOP MARGIN\",%d);\n", rep->top_margin);
  printc ("_rep.bottom_margin= A4GL_set_report_dim_int(\"BOTTOM MARGIN\",%d);\n", rep->bottom_margin);
  printc ("_rep.left_margin= A4GL_set_report_dim_int(\"LEFT MARGIN\",%d);\n", rep->left_margin);
  printc ("_rep.right_margin= A4GL_set_report_dim_int(\"RIGHT MARGIN\",%d);\n", rep->right_margin);
  printc ("_rep.page_length= A4GL_set_report_dim_int(\"PAGE LENGTH\",%d);\n", rep->page_length);
  printc ("_rep.header=0;\n");
  printc ("_rep.finishing=0;\n");
  printc ("_rep.repName=_reportName;\n");
  printc ("_rep.modName=_module_name;\n");
  printc ("_rep.page_no=%d;\n", rep->page_no);
  printc ("_rep.printed_page_no=%d;\n", rep->printed_page_no);
  printc ("_rep.line_no=%d;\n", rep->line_no);
  printc ("_rep.col_no=%d;\n", rep->col_no);
  printc ("if (strlen(_rout2)==0)\n");
  printc ("strcpy(_rep.output_loc,%s);\n", rep->output_loc);
  printc ("else strcpy(_rep.output_loc,_rout2);\n");
  printc ("if (strlen(_rout1)==0)\n");
  printc ("_rep.output_mode='%c';\n", rep->output_mode);
  printc ("else _rep.output_mode=_rout1[0];\n");
  printc ("_rep.report=(void *)&%s;\n", get_curr_rep_name ());
  printc ("A4GL_trim(_rep.output_loc);");
  printc ("A4GL_%srep_print(&_rep,-1,-1,-1,-1);",ispdf());
  print_rep_ret (report_cnt,0);
}

/**
 * Called by print_report_2() generate the C code taht implements the
 * assignments that should be done when an output to report is executed.
 *
 * This implementation is specific for pdf reports only.
 *
 * @param rep The report control structure.
 */
static void
pdf_print_output_rep (struct pdf_rep_structure *rep)
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
  printc ("strcpy(_rep.output_loc,%s);\n", rep->output_loc);
  printc ("else strcpy(_rep.output_loc,_rout2);\n");
  printc ("if (strlen(_rout1)==0)\n");
  printc ("_rep.output_mode='%c';\n", rep->output_mode);
  printc ("else _rep.output_mode=_rout1[0];\n");
  printc ("_rep.report=&%s;\n", get_curr_rep_name ());
  printc ("A4GL_trim(_rep.output_loc);");
  print_rep_ret (report_cnt,0);
}

/**
 * Prints the generated C code that implements the AFTER GROUP(s) actions
 */
static void
pr_report_agg (void)
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

      if (t == 'C')
	{
	  print_expr (sreports[z].rep_where_expr);
	  printc ("if (A4GL_pop_bool()) _g%d++;\n", a);
	}

      if (t == 'P')
	{
	  printc ("_g%d++;", a + 1);
	  print_expr (sreports[z].rep_where_expr);
	  printc (" if (A4GL_pop_bool()) _g%d++; \n", a);
	}

      if (t == 'S')
	{
	  A4GL_debug ("X0");
	  print_expr (sreports[z].rep_where_expr);
	  A4GL_debug ("X1");
	  printc ("if (A4GL_pop_bool()) {double _res;");
	  A4GL_debug ("X2");
	  print_expr (sreports[z].rep_cond_expr);
	  A4GL_debug ("X3");
	  printc ("_res=A4GL_pop_double_null_as_zero(); _g%dused++; _g%d+=_res;}\n ", a,a);
	}

      if (t == 'A')
	{
	  print_expr (sreports[z].rep_where_expr);
	  printc ("if (A4GL_pop_bool()) {double _res;");
	  print_expr (sreports[z].rep_cond_expr);

	  printc ("_res=A4GL_pop_double(); if (!A4GL_isnull(3,&_res)) { _g%d+=_res;_g%d++;}}\n", a, a + 1);
	}

      if (t == 'N')
	{
	  print_expr (sreports[z].rep_where_expr);
	  printc ("if (A4GL_pop_bool()) {double _res;");
	  print_expr (sreports[z].rep_cond_expr);
	  printc
	    ("_res=A4GL_pop_double(); if (_res<_g%d||_g%dused==0) {_g%d=_res;_g%dused=1;}}\n",
	     a, a, a, a);
	}

      if (t == 'X')
	{
	  print_expr (sreports[z].rep_where_expr);
	  printc ("if (A4GL_pop_bool()) {double _res;");
	  print_expr (sreports[z].rep_cond_expr);
	  printc
	    ("_res=A4GL_pop_double(); if (_res>_g%d||_g%dused==0) {_g%d=_res;_g%dused=1;}}\n",
	     a, a, a, a);
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
      sprintf(b,"%d",sreports[z].in_b);
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

	  if (t == 'P' || t == 'A')
	    {
	      printc ("_g%d=0;_g%d=0;\n", a + 1, a);
	    }
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
/*
      strcpy (s2, sreports[z].rep_cond);
      strcpy (s1, sreports[z].rep_expr);
*/
      a = sreports[z].a;
      t = sreports[z].t;
	sprintf(b,"%d",sreports[z].in_b);
      in_b = gen_ord(b);
      
      if (in_b > 0)
	{
	  printc ("if (_nargs==-%d&&acl_ctrl==REPORT_AFTERGROUP) {\n", in_b);
	  printc ("/* t=%c */\n", t);
	  if (t == 'C' || t == 'N' || t == 'X' || t == 'S')
	    {
	      printc ("_g%d=0;\n", a);
	    }

	  if (t == 'N' || t == 'X' || t=='S')
	    {
	      printc ("_g%dused=0;\n", a);
	    }

	  if (t == 'P' || t == 'A')
	    {
	      printc ("_g%d=0;_g%d=0;\n", a + 1, a);
	    }
	  printc ("}\n");
	}
    }
}

/**
 * Do not do nothing. - called from /compilers/4glc/mod.c
 */
void
LEXLIB_print_clr_status (void)
{
  /* printc ("A4GLSQL_set_status(0);\n"); */
}

/**
 * Called by the parser, in rules generated by the script mkyacc that joins all
 * the rules into one big yacc gramar.
 *
 * Generate the C code to output file that handles the error and warning
 * management controled by WHENEVER 4gl statememt.
 *
 * @param l The line number of the 4gl source code.
 * @param f The source 4gl file name.
 */
void
LEXLIB_A4GL_prchkerr (int l, char *f)
{
  int a;
/* 0 = continue
 * 1 = stop
 * 2 = call
 * 3 = goto 
 */
  if (A4GL_isyes(acl_getenv("FUDGE_STATUS"))) {
  	printc("if (!aclfgli_get_err_flg()) {a4gl_status=0;}");
  }

  if (A4GL_doing_pcode () && 1)
    {
      char buff[2000];
      char tbuff[2000];
      sprintf (tbuff, "ERRCHK(%d,\"%s\"", l, f);
      strcpy (buff, tbuff);
      sprintf (tbuff, ",%d,\"%s\"", when_code[A_WHEN_SUCCESS], when_to[A_WHEN_SUCCESS]);
      strcat (buff, tbuff);
      sprintf (tbuff, ",%d,\"%s\"", when_code[A_WHEN_NOTFOUND], when_to[A_WHEN_NOTFOUND]);
      strcat (buff, tbuff);
      sprintf (tbuff, ",%d,\"%s\"", when_code[A_WHEN_SQLERROR], when_to[A_WHEN_SQLERROR]);
      strcat (buff, tbuff);
      sprintf (tbuff, ",%d,\"%s\"", when_code[A_WHEN_ERROR], when_to[A_WHEN_ERROR]);
      strcat (buff, tbuff);
      sprintf (tbuff, ",%d,\"%s\"", when_code[A_WHEN_WARNING], when_to[A_WHEN_WARNING]);
      strcat (buff, tbuff);
      sprintf (tbuff, ");");
      strcat (buff, tbuff);
      printc ("%s", buff);
      return;
    }

#ifdef DEBUG
  A4GL_debug ("MJA A4GL_prchkerr %d %s", l, f);
#endif
  printc
    ("if (aclfgli_get_err_flg()&&(a4gl_sqlca.sqlcode !=0 || a4gl_status !=0 || %d)) {\n",
     when_code[A_WHEN_SUCCESS] == WHEN_CALL
     || when_code[A_WHEN_SQLSUCCESS] == WHEN_CALL);
  /*printc("A4GL_debug(\"a4gl_status=%%d a4gl_sqlca.sqlcode=%%d\",a4gl_status,a4gl_sqlca.sqlcode);\n"); */
  printcomment ("/* NOTFOUND */");

  a =
    pr_when_do ("   if (a4gl_sqlca.sqlcode==100)",
		when_code[A_WHEN_NOTFOUND], l, f, when_to[A_WHEN_NOTFOUND]);
  printcomment ("/* SQLERROR */");

  a =
    pr_when_do
    ("   if (a4gl_sqlca.sqlcode<0&&a4gl_status==a4gl_sqlca.sqlcode)",
     when_code[A_WHEN_SQLERROR], l, f, when_to[A_WHEN_SQLERROR]);

#ifdef ANYERRORISCAUSINGPROBS
  printcomment ("/* ANYERROR */");

  a =
    pr_when_do ("   if (a4gl_status<0||a4gl_sqlca.sqlcode<0)",
		when_code[A_WHEN_ANYERROR], l, f, when_to[A_WHEN_ANYERROR]);
#endif

  printcomment ("/* ERROR */");
  a =
    pr_when_do ("   if (a4gl_status<0) ", when_code[A_WHEN_ERROR], l, f,
		when_to[A_WHEN_ERROR]);
  printcomment ("/* SQLWARNING */");
  a =
    pr_when_do ("   if (a4gl_sqlca.sqlcode==0&&a4gl_sqlca.sqlawarn[0]=='W')",
		when_code[A_WHEN_SQLWARNING], l, f,
		when_to[A_WHEN_SQLWARNING]);
  printcomment ("/* WARNING */");
  a =
    pr_when_do
    ("   if (aclfgli_get_err_flg()&&a4gl_sqlca.sqlcode==0&&(a4gl_sqlca.sqlawarn[0]=='w'||a4gl_sqlca.sqlawarn[0]=='W'))",
     when_code[A_WHEN_WARNING], l, f, when_to[A_WHEN_WARNING]);
  printcomment ("/* SQLSUCCESS */");
  a =
    pr_when_do ("   if (a4gl_sqlca.sqlcode==0&&a4gl_status==0)",
		when_code[A_WHEN_SQLSUCCESS], l, f,
		when_to[A_WHEN_SQLSUCCESS]);
  printcomment ("/* SUCCESS */");
  a = pr_when_do ("   if (a4gl_sqlca.sqlcode==0&&a4gl_status==0)",
		  when_code[A_WHEN_SUCCESS], l, f, when_to[A_WHEN_SUCCESS]);
  printc ("}\n");
}

/**
 * Print to the generated C code the specific instructions of WHENEVER 
 * statement implementation.
 *
 * @param when_str The string that contains the C comparison expresion
 *   to check if there was an error.
 * @param when_code The integer code of specific WHENEVER
 * @param l The line number on the 4gl source code.
 * @param f The 4gl source file name.
 * @param when_to
 */
static int
pr_when_do (char *when_str, int when_code, int l, char *f, char *when_to)
{

  if ((when_code & 15) == WHEN_CONTINUE)
    return 0;
  if ((when_code & 15) == WHEN_NOTSET)
    return 0;
  if (when_code == WHEN_STOP)
    {
      printc ("%s A4GL_chk_err(%d,_module_name); \n", when_str, l, f);
      printcomment ("/* WHENSTOP */");
    }
  if (when_code == WHEN_CALL)
    {
	char buff[256];
	strcpy(buff,when_to);	
	A4GL_convlower(buff);
      printc ("%s {A4GL_log_error(%d,_module_name,a4gl_status);%s%s(0); }\n", when_str, l,get_namespace (when_to), buff);
      add_function_to_header (when_to, 1,"");
      printcomment ("/* WHENCALL */");
    }

  if (when_code == WHEN_GOTO)
    {
	char buff[256];
	strcpy(buff,when_to);	
	A4GL_convlower(buff);
      printc ("%s {A4GL_log_error(%d,_module_name,a4gl_status); goto %s;}\n", when_str,l, buff);
      printcomment ("/* WHENGOTO */");
    }
  return 1;
}

/**
 * Print the generated C code with the implementation of an expression.
 * called from API
 * @param ptr A pointer to an expr_str expression (structure that describes
 * an expression).
 */
void
LEXLIB_print_expr (void *ptr)
{
#ifdef DEBUG
  A4GL_debug ("via print_expr in lib");
#endif
  real_print_expr (ptr);
}

char * LEXLIB_print_arr_expr_fcall(void *optr) {
struct expr_str *ptr;
static int arr_print=0;
static char buff[256];
ptr=optr;
printh("int _arr_fcall_%d;",arr_print);
printc("/* START FCALL */\n");
real_print_expr(ptr);
printc("_arr_fcall_%d=A4GL_pop_long();",arr_print);
printc("/* END FCALL */\n");
sprintf(buff,"_arr_fcall_%d",arr_print);
arr_print++;
return buff;
}

static void
real_print_expr (struct expr_str *ptr)
{
  void *optr;
  A4GL_debug ("Print expr... %p", ptr);
  while (ptr)
    {
      A4GL_debug ("Printing %p", ptr->expr);
      printc ("%s\n", ptr->expr);

      free (ptr->expr);
      optr = ptr;
      A4GL_debug ("going to %p", ptr->next);
      ptr = ptr->next;
      A4GL_debug ("Freeing old value %p", optr);
      free (optr);
    }
}

/**
 * Print the form attributes to the generated C code in the output file.
 *
 * @param form_attrib A Pointer to the structure form_attrib that describes
 * the form attributes.
 */
static void
print_form_attrib (struct form_attr *form_attrib)
{
char *frm_attr;
char buff[256];
if (form_attrib->attrib_str==0) {
	sprintf(buff,"(0x%x)",form_attrib->attrib);
	frm_attr=buff;
} else {
	frm_attr=form_attrib->attrib_str;
}

  printc ("%d,%d,%d,%d,%d,%d,%d,%d,%s",
	  form_attrib->iswindow,
	  form_attrib->form_line,
	  form_attrib->error_line,
	  form_attrib->prompt_line,
	  form_attrib->menu_line,
	  form_attrib->border,
	  form_attrib->comment_line,
	  form_attrib->message_line, frm_attr);
#ifdef DEBUG
  A4GL_debug ("Printing attributes\n");
  A4GL_debug ("%d,%d,%d,%d,%d,%d,%d,%d,%s", form_attrib->iswindow,
	      form_attrib->form_line, form_attrib->error_line,
	      form_attrib->prompt_line, form_attrib->menu_line,
	      form_attrib->border, form_attrib->comment_line,
	      form_attrib->message_line, frm_attr);
#endif
}

/**
 *
 * @param ccc
 * @return
 */
static int
print_field_bind (int ccc)
{
  char tabname[40];
  char colname[40];
  int a;
  A4GL_debug ("%d\n", ibindcnt);
  for (a = 0; a < ccc; a++)
    {
      A4GL_bname (ibind[a].varname, tabname, colname);
      if (a > 0)
	printc (",");
      if (colname[0] != 0)
	printc ("\"%s\",1", colname);
      else
	printc ("\"%s\",1", tabname);
    }
  return a;
}

/**
 * @param i The bind type:
 *   - i : Input bind (4gl variables to be read).
 *   - o : Output bind (4gl variables to be assigned.
 */
void
LEXLIB_print_bind_pop1 (char i)
{
  int a;
  a = 0;



  if (i == 'i')
    {
#ifdef DEBUG
      /*A4GL_debug ("print_bind_pop1 i='i'\n");*/
#endif
      if (scan_variable (obind[a].varname) != -1)
	printc ("A4GL_pop_var2(&%s,%d,0x%x);\n", ibind[a].varname, (int) ibind[a].dtype & 0xffff, (int) ibind[a].dtype >> 16);
      else
	printc ("%s;\n", ibind[a].varname);
    }

  if (i == 'o')
    {
#ifdef DEBUG
      /*A4GL_debug ("print_bind_pop1 i='o'\n");*/
#endif
      if (scan_variable (obind[a].varname) != -1)
	printc ("A4GL_pop_var2(&%s,%d,0x%x);\n", obind[a].varname,
		(int) obind[a].dtype & 0xffff, (int) obind[a].dtype >> 16);
      else
	printc ("%s;\n", obind[a].varname);
    }

}


/**
 * Print to the generated C code, the declaration and initialization of an
 * bind array.
 *
 * @param i The bind type:
 *   - i : Input bind (4gl variables to be read).
 *   - o : Output bind (4gl variables to be assigned.
 * @return The number of elements in the binding array, 0 if invalid bind type.
 */
static int
print_arr_bind (char i)
{
  int a;

#ifdef DEBUG
  A4GL_debug ("/* %c */\n", i);
#endif
  /* dump_vars (); */
  if (i == 'i')
    {
      printc ("\n");
      printc ("struct BINDING ibind[%d]={\n", ibindcnt);
      for (a = 0; a < ibindcnt; a++)
	{
	  if (a > 0)
	    printc (",\n");
	  printc ("{0,%d,%d}", 
		  (int) ibind[a].dtype & 0xffff, (int) ibind[a].dtype >> 16);
	}
      printc ("\n}; \n");
	printcomment("/* end of binding */\n");
      for (a = 0; a < ibindcnt; a++)
	{
	printc("ibind[%d].ptr= &%s;", a,ibind[a].varname);
	}
      return a;
    }

  if (i == 'o')
    {
      printc ("\n");
      printc ("struct BINDING obind[%d]={\n", obindcnt);
      for (a = 0; a < obindcnt; a++)
	{
	  if (a > 0) printc (",\n");
	  printc ("{0,%d,%d}", (int) obind[a].dtype & 0xffff, (int) obind[a].dtype >> 16);
	}
      printc ("\n}; ");
	printcomment("/* end of binding */\n");
      for (a = 0; a < obindcnt; a++)
	{
	printc("obind[%d].ptr= &%s;", a,obind[a].varname);
	}
      return a;
    }
  return 0;
}


/**
 *
 * @todo Describe function
 */
static int
print_constr (void)
{
  int a;
  printc
    ("struct s_constr_list constr_flds[%d]={\n",
     constr_cnt);
  for (a = 0; a < constr_cnt; a++)
    {
      if (a > 0)
	printc (",\n");
      printc ("{\"%s\",\"%s\"}", constr_buff[a].tab, constr_buff[a].col);
    }
  printc ("\n};");
  return a;
}

/**
 *
 * @todo Describe function
 */
static int
print_field_bind_constr (void)
{
  int a;
  for (a = 0; a < constr_cnt; a++)
    {
      if (a > 0)
	printc (",");
      if (constr_buff[a].tab[0] != 0) {
		//printc ("\"%s.%s\",1", constr_buff[a].tab, constr_buff[a].col);
		printc ("\"%s\",1",  constr_buff[a].col);
	}
      else
	printc ("\"%s\",1", constr_buff[a].col);
    }
  return a;
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
LEXLIB_print_param (char i)
{
  int a;
  int b;
  char *ptr;
  A4GL_debug ("Expanding binding.. - was %d entries", fbindcnt);
  expand_bind (&fbind[0], 'F', fbindcnt);
  A4GL_debug ("Expanded - now %d entries", fbindcnt);
  if (i == 'r')
    {
      printc ("static ");
    }

  if (i=='r') {
    	printc ("struct BINDING _rbind[%d]={ \n", ONE_NOT_ZERO(fbindcnt));
  } else {
    	printc ("struct BINDING %cbind[%d]={ /* %d */\n", i, ONE_NOT_ZERO(fbindcnt),fbindcnt);
  }
      if (fbindcnt == 0)
	{
	  printc ("{0,0,0}");
	} else {
  		for (a = 0; a < fbindcnt; a++)
    		{
		
      		fbind[a].dtype = scan_variable (fbind[a].varname);
      		if (a > 0)
			printc (",\n");
      		/* printc ("{&%s,%d,%d}", fbind[a].varname, (int) fbind[a].dtype & 0xffff, (int) fbind[a].dtype >> 16); */
      		printc ("{0,%d,%d}", (int) fbind[a].dtype & 0xffff, (int) fbind[a].dtype >> 16);
				
    		}
	}
  printc ("\n}; ");
	printcomment("/* end of binding */\n");
  if (i == 'r')
    {
      printc ("static char *_rbindvarname[%d]={\n", ONE_NOT_ZERO(fbindcnt));
	if (fbindcnt==0) {printc("0");}


      for (b = 0; b < fbindcnt; b++)
	{

	  ptr = strrchr (fbind[b].varname, '.');
	  if (ptr == 0)
	    ptr = fbind[b].varname;
	  else
	    ptr++;		/* Skip over the '.' */

	  if (b)
	    printc (",");

	  printc ("\"%s\"", ptr);
	}
      printc ("};\n");
    }

  printc ("char *_paramnames[%d]={ /* %d */", fbindcnt+1,fbindcnt);

  for (a = 0; a < fbindcnt; a++)
    {
      printc ("\"%s\",", fbind[a].varname);
    }
    printc("0");
  printc ("};");

  for (a=0;a<fbindcnt;a++) {
	if (i=='r') {
    		printc ("_rbind[%d].ptr=&%s;\n", a,fbind[a].varname);
	} else {
    		printc ("fbind[%d].ptr=&%s;\n", a,fbind[a].varname);

	}
  }


  return a;
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
int
LEXLIB_print_bind (char i)
{
  int a;
#ifdef DEBUG
  A4GL_debug ("/* print_bind %c */\n", i);
#endif
  if (i == 'i')
    {
      printc ("\n");
      printc ("struct BINDING ibind[%d]={\n ",
	      ONE_NOT_ZERO (ibindcnt), ibindcnt);
      if (ibindcnt == 0)
	{
	  printc ("{0,0,0}");
	}
      for (a = 0; a < ibindcnt; a++)
	{
	  if (a > 0)
	    printc (",\n");
	  printc ("{&%s,%d,%d,%d,%d}", ibind[a].varname,
		  (int) ibind[a].dtype & 0xffff, (int) ibind[a].dtype >> 16,
		  ibind[a].start_char_subscript, ibind[a].end_char_subscript);
	}
      printc ("\n}; ");
	printcomment("/* end of binding */\n");
      if (doing_esql ())
	{
	  make_sql_bind (0, "i");
	}
      start_bind (i, 0);
      return a;
    }

  if (i == 'N')
    {
      expand_bind (&nullbind[0], 'N', nullbindcnt);
      printc ("\n");
      printc ("struct BINDING nullbind[%d]={\n /* nullbind %d*/",
	      ONE_NOT_ZERO (nullbindcnt), nullbindcnt);
      if (nullbindcnt == 0)
	{
	  printc ("{0,0,0}");
	}
      for (a = 0; a < nullbindcnt; a++)
	{
	  if (a > 0)
	    printc (",\n");
	  chk_init_var (nullbind[a].varname);
	  printc ("{&%s,%d,%d}", nullbind[a].varname,
		  (int) nullbind[a].dtype & 0xffff,
		  (int) nullbind[a].dtype >> 16);
	}
      printc ("\n}; /* end of binding */\n");
      start_bind (i, 0);
      return a;
    }

  if (i == 'o')
    {
      printc ("\n");
      printc ("struct BINDING obind[%d]={\n", ONE_NOT_ZERO (obindcnt));
      if (obindcnt == 0)
	{
	  printc ("{0,0,0}");
	}

      for (a = 0; a < obindcnt; a++)
	{
	  if (a > 0)
	    printc (",\n");
	  printc ("{&%s,%d,%d,%d,%d}", obind[a].varname,
		  (int) obind[a].dtype & 0xffff, (int) obind[a].dtype >> 16,
		  ibind[a].start_char_subscript, ibind[a].end_char_subscript);
	}
      printc ("\n}; /* end of binding */\n");
      if (doing_esql ())
	{
	  make_sql_bind (0, "o");
	}
      start_bind (i, 0);
      return a;
    }

  if (i == 'O')
    {
      printc ("\n");
      	expand_bind (&ordbind[0], 'O', ordbindcnt);


      printc ("static struct BINDING _ordbind[%d]={\n", ONE_NOT_ZERO (ordbindcnt));
      if (ordbindcnt == 0)
	{
	  printc ("{0,0,0}");
	}

      for (a = 0; a < ordbindcnt; a++)
	{
	  if (a > 0)
	    printc (",\n");
	  printc ("{&%s,%d,%d}", ordbind[a].varname,
		  (int) ordbind[a].dtype & 0xffff,
		  (int) ordbind[a].dtype >> 16);
	}
      printc ("\n}; /* end of binding */\n");
      current_ordbindcnt = ordbindcnt;
      start_bind (i, 0);

      return a;
    }
  return 0;
}


/**
 *
 * @todo Describe function
 */
int LEXLIB_print_bind_expr (void *ptr, char i)
{
  int a;

  char buff[256];
  if (i == 'i')
    {
      sprintf (buff, "struct BINDING ibind[%d]={", ONE_NOT_ZERO (ibindcnt));
      A4GL_append_expr (ptr, buff);
      if (ibindcnt == 0)
	{
	  A4GL_append_expr (ptr, "{0,0,0}");
	}
      for (a = 0; a < ibindcnt; a++)
	{
	  if (a > 0)
	    A4GL_append_expr (ptr, ",");
	  sprintf (buff, "{0,%d,%d}", 
		   (int) ibind[a].dtype & 0xffff, (int) ibind[a].dtype >> 16);
	  A4GL_append_expr (ptr, buff);
	}
      A4GL_append_expr (ptr, "};");

      if (doing_esql ())
        {
          A4GL_append_expr(ptr,make_sql_bind_expr (0, "i"));
        }

      for (a=0;a<ibindcnt;a++) {
      		sprintf(buff,"ibind[%d].ptr=&%s;",a,ibind[a].varname);
	  	A4GL_append_expr (ptr, buff);
      }

      start_bind (i, 0);
      return a;

    }


  if (i == 'o')
    {
      sprintf (buff, "struct BINDING obind[%d]={", ONE_NOT_ZERO (obindcnt));
      A4GL_append_expr (ptr, buff);
      if (obindcnt == 0)
	{
	  A4GL_append_expr (ptr, "{0,0,0}");
	}
      for (a = 0; a < obindcnt; a++)
	{
	  if (a > 0)
	    A4GL_append_expr (ptr, ",");
	  sprintf (buff, "{0,%d,%d}", 
		   (int) obind[a].dtype & 0xffff, (int) obind[a].dtype >> 16);
	  A4GL_append_expr (ptr, buff);
	}
      A4GL_append_expr (ptr, "};");

      if (doing_esql ())
        {
          A4GL_append_expr(ptr,make_sql_bind_expr (0, "i"));
        }
      for (a=0;a<obindcnt;a++) {
      		sprintf(buff,"obind[%d].ptr=&%s;",a,obind[a].varname);
	  	A4GL_append_expr (ptr, buff);
      }
      start_bind (i, 0);
      return a;
    }

  if (i == 'e')
    {
      sprintf (buff, "struct BINDING ebind[%d]={", ONE_NOT_ZERO (ebindcnt));
      A4GL_append_expr (ptr, buff);
      if (ebindcnt == 0)
	{
	  A4GL_append_expr (ptr, "{0,0,0}");
	}
      for (a = 0; a < ebindcnt; a++)
	{
	  if (a > 0)
	    A4GL_append_expr (ptr, ",");
	  sprintf (buff, "{0,%d,%d}", 
		   (int) ebind[a].dtype & 0xffff, (int) ebind[a].dtype >> 16);
	  A4GL_append_expr (ptr, buff);
	}
      A4GL_append_expr (ptr, "};");

      for (a=0;a<ebindcnt;a++) {
      		sprintf(buff,"ebind[%d].ptr=&%s;",a,ebind[a].varname);
	  	A4GL_append_expr (ptr, buff);
      }
      start_bind (i, 0);
      return a;
    }



  return 0;
}

int print_bind_expr_portion (void *ptr, char i, int portion)
{
  int a=0;

  char buff[256];
  if (i == 'i')
    {

      if (portion == 1)
	{
	  sprintf (buff, "struct BINDING ibind[%d]={",
		   ONE_NOT_ZERO (ibindcnt));
	  A4GL_append_expr (ptr, buff);
	  if (ibindcnt == 0)
	    {
	      A4GL_append_expr (ptr, "{0,0,0}");
	    }
	  for (a = 0; a < ibindcnt; a++)
	    {
	      if (a > 0)
		A4GL_append_expr (ptr, ",");
	      sprintf (buff, "{0,%d,%d}",
		       (int) ibind[a].dtype & 0xffff,
		       (int) ibind[a].dtype >> 16);
	      A4GL_append_expr (ptr, buff);
	    }
	  A4GL_append_expr (ptr, "};");

	  if (doing_esql ())
	    {
	      A4GL_append_expr (ptr, make_sql_bind_expr (0, "i"));
	    }

	}

      if (portion == 2)
	{
	  for (a = 0; a < ibindcnt; a++)
	    {
	      sprintf (buff, "ibind[%d].ptr=&%s;", a, ibind[a].varname);
	      A4GL_append_expr (ptr, buff);
	    }
	  start_bind (i, 0);
	}
      return a;

    }


  if (i == 'o')
    {


      if (portion == 1)
	{
	  sprintf (buff, "struct BINDING obind[%d]={",
		   ONE_NOT_ZERO (obindcnt));
	  A4GL_append_expr (ptr, buff);

	  if (obindcnt == 0)
	    {
	      A4GL_append_expr (ptr, "{0,0,0}");
	    }

	  for (a = 0; a < obindcnt; a++)
	    {
	      if (a > 0)
		A4GL_append_expr (ptr, ",");
	      sprintf (buff, "{0,%d,%d}",
		       (int) obind[a].dtype & 0xffff,
		       (int) obind[a].dtype >> 16);
	      A4GL_append_expr (ptr, buff);
	    }
	  A4GL_append_expr (ptr, "};");

	  if (doing_esql ())
	    {
	      A4GL_append_expr (ptr, make_sql_bind_expr (0, "i"));
	    }
	}
      if (portion == 2)
	{
	  for (a = 0; a < obindcnt; a++)
	    {
	      sprintf (buff, "obind[%d].ptr=&%s;", a, obind[a].varname);
	      A4GL_append_expr (ptr, buff);
	    }
	  start_bind (i, 0);
	}
      return a;
    }

  if (i == 'e')
    {
      if (portion == 1)
	{
	  sprintf (buff, "struct BINDING ebind[%d]={",
		   ONE_NOT_ZERO (ebindcnt));
	  A4GL_append_expr (ptr, buff);
	  if (ebindcnt == 0)
	    {
	      A4GL_append_expr (ptr, "{0,0,0}");
	    }
	  for (a = 0; a < ebindcnt; a++)
	    {
	      if (a > 0)
		A4GL_append_expr (ptr, ",");
	      sprintf (buff, "{0,%d,%d}",
		       (int) ebind[a].dtype & 0xffff,
		       (int) ebind[a].dtype >> 16);
	      A4GL_append_expr (ptr, buff);
	    }
	  A4GL_append_expr (ptr, "};");
	}

      if (portion == 2)
	{
	  for (a = 0; a < ebindcnt; a++)
	    {
	      sprintf (buff, "ebind[%d].ptr=&%s;", a, ebind[a].varname);
	      A4GL_append_expr (ptr, buff);
	    }
	  start_bind (i, 0);
	}
      return a;
    }



  return 0;
}

/* ***************************************************************************/
/* The rest of this file is the stuff called from the parser..               */
/* ****************************************************************************/

/**
 * Generate the C implementation of SET PAUSE MODE 4gl statement.
 *
 * @param n The A4GL_action to do:
 *   - 0 : ON.
 *   - 1 : OFF.
 */
void
LEXLIB_print_screen_mode (int n)
{
  printc ("A4GL_screen_mode(%d);", n);
}

/**
 * Generate the C implementation of START EXTERN FUNCTION 4gl statement.
 *
 * The START EXTERN FUNCTION is an extension and gives 4gl the ability to
 * execute Remote Procedures.
 *
 * In this case start a behavior of acting as RPC server.
 *
 * @param port The IP port to open
 * @param funclist The name of remote functions to be served separated by
 * comma.
 */
void
LEXLIB_print_start_server (char *port, char *funclist)
{
  printc ("A4GL_server_run(%s+0x2000000);", port);

  printc ("%s\n", funclist);
}


/**
 * Print the C implementation of the STOP ALL EXTERNAL statement.
 *
 * This statement makes that the program stops to act as a RPC server.
 */
void
LEXLIB_print_stop_external (void)
{
  printc ("A4GL_stop_serving();");
}

/**
 * Print the C code for remote function availability.
 *
 * @param identifier The 4gl function name.
 */
void
LEXLIB_print_remote_func (char *identifier)
{
  /*printh ("int %s%s(int np);\n", get_namespace(identifier),identifier);*/
  add_function_to_header (identifier, 1,"");
  printc
    ("a4gl_status=0;A4GL_register_func(\"%s\",%s%s);if (a4gl_status<0) A4GL_chk_err(%d,_module_name);\n",
     identifier, get_namespace (identifier), identifier,yylineno);
}



/**
 * Print the C implementation of a variable pop().
 *
 * @param s The variable name.
 */
void
LEXLIB_print_pop_variable (char *s)
{
  printc ("A4GL_pop_var(&%s,%d);\n", s, scan_variable (s));
}


/**
 * Print the C implementation of the call to fgl_getfldbuff() internal
 * 4gl function.
 *
 * Called after the parser found a call to getfldbuff() function
 *
 * @param fields The field list 
 */
void
LEXLIB_print_getfldbuf (char *fields)
{
  printc ("{int _retvars;\n");
  printc ("_retvars=A4GL_fgl_getfldbuf(_sio_%d,_inp_io_type,%s,0,0);\n",get_sio_id("ALL"), fields);
  start_bind ('i', 0);
}

/**
 * Print the C implementation of the returning substatement of CALL statement.
 */
void
LEXLIB_print_returning (void)
{
  int cnt;
  printc ("{\n");
  cnt = print_bind_definition ('i');
   print_bind_set_value ('i');
  printc
    /* warning! :       void    A4GLSQL_set_status      (int a, int sql); */
/* I've added the check back in - even if its -1....*/
/* I'm not sure why it went in...*/
    ("if (_retvars!= %d) {if (_retvars!=-1||1) {if (a4gl_status==0) A4GLSQL_set_status(-3001,0);\nA4GL_pop_args(_retvars);}\n} else {A4GLSQL_set_status(0,0);\n",
     cnt);
  printc ("A4GL_pop_params(ibind,%d);}\n", cnt);
  printc ("}\n");
  printc ("}\n");
}


/**
 *
 * @todo Describe function
 */
void
LEXLIB_print_form_is_compiled (char *s, char *packer, char *formtype)
{
  printc ("A4GL_add_compiled_form(\"%s\",%s,%s,compiled_form_%s);\n", s,
	  packer, formtype, s);
  printh ("extern char compiled_form_%s[];\n", s);
}

/**
 * Print to the generated output file the C implementation of the fields
 * functions.
 *
 * @todo : Fix the fgl_infield() call with only one parameter.
 *
 * @param type The type of the field function:
 *   - I : infield() function used.
 *   - T : fieldtouched() function used.
 */
void
LEXLIB_print_field_func (char type, char *name, char *var)
{
  printc ("A4GLSTK_setCurrentLine(_module_name,%d);", yylineno);
  if (!isin_command ("INPUT") && !isin_command ("CONSTRUCT"))
    {

      if (type == 'I')
	printc ("A4GL_push_int(A4GL_fgl_infield(0,0,%s,0,0));", name);

      if (type == 'T')
	return;

    }

  if (type == 'I')
    printc ("A4GL_push_int(A4GL_fgl_infield(_sio_%d,_inp_io_type,%s,0,0));",get_sio_id("ALL"), name);

  if (type == 'T')
    printc
      ("A4GL_push_int(A4GL_fgl_fieldtouched(_sio_%d,_inp_io_type,%s,0,0));",get_sio_id("ALL"),
       name);


  print_pop_variable (var);
}


/**
 * Prints the function call in C language.
 *
 * @param identifier The function name 
 * @param args The arguments
 * @param args_cnt The number of arguments
 */
void
LEXLIB_print_func_call (char *identifier, void *args, int args_cnt)
{
  A4GL_debug ("via print_func_call in lib");
  real_print_func_call (identifier, args, args_cnt);
}

/**
 *
 * @todo Describe function
 */
void
LEXLIB_print_class_func_call (char *var, char *identifier, void *args, int args_cnt)
{
  A4GL_debug ("via print_func_call in lib");
  real_print_class_func_call (var, identifier, args, args_cnt);
}



/**
 *
 * @todo Describe function
 */
static void
real_print_func_call (char *identifier, struct expr_str *args, int args_cnt)
{
char lib[255];
  real_print_expr (args);
  printc ("/* done print expr */");
  add_function_to_header (identifier, 1,"");


if (has_function(identifier,lib,0)) {

  printc ("{int _retvars;\n");
  printc ("A4GLSTK_setCurrentLine(_module_name,%d);", yylineno);
  printc ("A4GLSQL_set_status(0,0);_retvars=A4GL_call_4gl_dll(%s,\"%s\",%d);\n", lib, identifier, args_cnt);


} else {
  printc ("{int _retvars;A4GLSQL_set_status(0,0);\n");
  printc ("A4GLSTK_setCurrentLine(_module_name,%d);", yylineno);
  printc ("_retvars=%s%s(%d);\n", get_namespace (identifier), identifier, args_cnt);
}
print_reset_state_after_call();

}

/**
 *
 * @todo Describe function
 */
static void
real_print_class_func_call (char *var, char *identifier,
			    struct expr_str *args, int args_cnt)
{
  printcomment ("/* printing parameters */");
  real_print_expr (args);
  printcomment ("/* done printing parameters */");
  printc ("{int _retvars;A4GLSQL_set_status(0,0);\n");
  printc ("A4GLSTK_setCurrentLine(_module_name,%d);", yylineno);

  printc ("_retvars=A4GL_call_datatype_function_i(&%s,%d,\"%s\",%d);\n",
	  var, scan_variable (var), identifier, args_cnt);
print_reset_state_after_call();

}

/**
 * Prints a call to the corresponding pdf report in the generated C code
 *
 * @param a1 The pdf function name
 * @param args The pdf function arguments
 * @param a3 The returning values
 */
void
LEXLIB_print_pdf_call (char *a1, void *args, char *a3)
{
  A4GL_debug ("via print_pdf_call in lib");
  real_print_pdf_call (a1, args, a3);
}
static void
real_print_pdf_call (char *a1, struct expr_str *args, char *a3)
{
  real_print_expr (args);
  printc ("{int _retvars;A4GLSQL_set_status(0,0);\n");
  printc ("A4GLSTK_setCurrentLine(_module_name,%d);", yylineno);
  printc ("_retvars=A4GL_pdf_pdffunc(&_rep,%s,%s);\n", a1, a3);
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
LEXLIB_print_call_shared (char *libfile, char *funcname, int nargs)
{
  printc ("{int _retvars;\n");
  printc ("A4GLSTK_setCurrentLine(_module_name,%d);", yylineno);
  printc ("A4GLSQL_set_status(0,0);_retvars=A4GL_call_4gl_dll(%s,%s,%d);\n",
	  libfile, funcname, nargs);
print_reset_state_after_call();
}

void
LEXLIB_print_call_shared_bound (char *libfile, char *funcname)
{
int ni,no;
  printc ("{int _retvars;\n");
  ni = print_bind_definition ('i');
  no = print_bind_definition ('o');
  print_bind_set_value ('i');
  print_bind_set_value ('o');
  printc ("A4GLSTK_setCurrentLine(_module_name,%d);", yylineno);
  printc ("A4GLSQL_set_status(0,0);_retvars=A4GL_call_4gl_dll_bound(%s,%s,%d,ibind,%d,obind);}\n", libfile, funcname, ni,no);
print_reset_state_after_call();
}

void *
LEXLIB_get_call_shared_bound_expr(char *lname,char *fname) { 
	char buff_small[200];
	int ni;
	int no;
	void *ptr;
	ptr=A4GL_new_expr("{");
	print_bind_expr_portion(ptr,'i',1);
	print_bind_expr_portion(ptr,'e',1);
	ni=print_bind_expr_portion(ptr,'i',2);
	no=print_bind_expr_portion(ptr,'e',2);
	sprintf(buff_small,"{int _retvars; A4GLSQL_set_status(0,0);_retvars=A4GL_call_4gl_dll_bound(%s,%s,%d,ibind,%d,ebind);if (_retvars!= 1 && a4gl_status==0 ) {A4GLSQL_set_status(-3001,0);A4GL_chk_err(%d,_module_name);}}}\n", lname, fname, ni,no,yylineno);
  	return A4GL_append_expr(ptr,buff_small);
}



/**
 * Print the C implementation of the last part of Shared library function
 * call.
 */
void
LEXLIB_print_end_call_shared (void)
{
  /* printc ("}\n"); */
}

/**
 * Print the C implementation of a call to a remote function (RPC call).
 *
 * @param host The hostname where the RPC server is working.
 * @param func The remote function name to e called.
 * @param port The TCP portnumber where the server is receiving requests.
 * @param nargs The number of arguments to pass to the remote function.
 */
void
LEXLIB_print_call_external (char *host, char *func, char *port, int nargs)
{
  printc ("{int _retvars;\n");
  printc ("A4GLSTK_setCurrentLine(_module_name,%d);", yylineno);
  printc ("_retvars=A4GL_remote_func_call(%s,%s,%s,%d);\n", host, func,
	  port, nargs);
print_reset_state_after_call();
}

/**
 * Print the C implementation of te last part of a call to a remote function.
 */
void
LEXLIB_print_end_call_external (void)
{
  printc ("\n");
}

/**
 * Print the C implementation to the CASE 4gl statement.
 *
 * @param has_expr Defines if the case have an expression:
 *   - 0 : Does not have expression for the case (just for WHEN).
 *   - Otherwise : Have cas expression.
 */
void
LEXLIB_print_case (int has_expr)
{
  if (has_expr)
    printc ("while (1==1) {char *s=0;if (s==0) {s=A4GL_char_pop();}\n");
  else
    printc ("while (1==1) {\n");
}


/**
 * Print the C implementation after each WHEN.
 *
 * @param endofblock The type of block where it was called:
 *   - 0 : After WHEN
 *   - 1 : After OTHERWISE or END CASE
 */
void
LEXLIB_print_after_when (int endofblock)
{
  printc ("break;\n");
  if (endofblock)
    {
      printc ("}");
    }
}


/**
 * Print the C implementation of the WHEN from the CASE 4gl statement.
 *
 * @param has_expr Flag that indicates if the WHEN have a specific expression:
 *   - 0 : Does not have expression.
 *   - 1 : Have expression.
 */
void
LEXLIB_print_when (int has_expr)
{
  if (has_expr)
    {
      printc ("A4GL_push_char(s);");
      printc ("A4GL_pushop(OP_EQUAL);\n");
    }
  printc ("if (A4GL_pop_bool()) {\n");
}



/**
 * Print the C implementation of the first part of CONSTRUCT statement.
 */
void
LEXLIB_print_construct_1 (void)
{
  printc ("} /* end of initialization */\n");
}



/**
 * Print the second part of C implementation of CONSTRUCT statement
 *
 * @param driver
 */
void
LEXLIB_print_construct_2 (char *driver)
{
int sio_id;
  /*printc ("if (_fld_dr== -95) {\n");*/
  /*printc ("   break;\n}\n");*/
  /*printc ("if (_fld_dr== -197) {\n");*/
  /*printc ("   fldname=A4GL_char_pop(); A4GL_set_infield_from_stack();");*/
  /*printc ("   _fld_dr= -97;continue;\n}\n");*/

  A4GL_add_event(-94,"");
  printc("if (_exec_block== %d) { break; } ",A4GL_get_nevents());
  printc("{");
  print_event_list();
  printc ("_exec_block = %s;_forminit=0;\n", driver);
  printc("if (_exec_block>0) _fld_dr=_sio_evt[_exec_block-1].event_type; else _fld_dr= -1;");
  printc("}");






  /*printc ("if (_fld_dr==0) {\n");*/
  /*printc ("   _fld_dr= -95;continue;\n}\n");*/

  add_continue_blockcommand ("CONSTRUCT");
  printc ("\n}\n");
  sio_id=get_sio_id("CONSTRUCT");
  pop_blockcommand ("CONSTRUCT");
  printc (" A4GL_push_constr(&_sio_%d);\n ",sio_id);
  printc (" A4GL_pop_params(ibind,1);");
  printc ("}\n");
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
void
LEXLIB_print_construct_3 (int byname, char *constr_str, char *fld_list, char *attr,
		   int cattr)
{
  int ccc;
  int k;
  int sio_id;
  printc ("{\n");
  start_bind ('i', constr_str);
  k = print_bind_definition ('i');
  ccc = print_constr ();
  sio_id=get_sio_id("CONSTRUCT");
  printc ("int _fld_dr= -100;int _exec_block= 0;char *fldname;");
  printc("char _sio_%d[%d]; char _inp_io_type='C'; char *_sio_kw_%d=\"s_screenio\";\n", get_sio_id("CONSTRUCT"),sizeof (struct s_screenio) + 10,sio_id);
  printc ("int _forminit=1;\n");
   print_bind_set_value ('i');
  printc ("while(_fld_dr!=0){\n");
  printc ("if (_exec_block == 0) {\n");
  printc ("SET(\"s_screenio\",_sio_%d,\"vars\",ibind);\n",sio_id);
  printc ("SET(\"s_screenio\",_sio_%d,\"novars\",%d);\n", sio_id,ccc);
  printc ("SET(\"s_screenio\",_sio_%d,\"attrib\",%d);\n", sio_id,cattr);
  printc
    ("SET(\"s_screenio\",_sio_%d,\"currform\",A4GL_get_curr_form(1));\n",sio_id);
  printc ("SET(\"s_screenio\",_sio_%d,\"currentfield\",0);\n",sio_id);
  printc ("SET(\"s_screenio\",_sio_%d,\"currentmetrics\",0);\n",sio_id);
  printc ("SET(\"s_screenio\",_sio_%d,\"constr\",constr_flds);\n",sio_id);
  printc ("SET(\"s_screenio\",_sio_%d,\"mode\",%d);\n",sio_id, MODE_CONSTRUCT);
  printc ("SET(\"s_screenio\",_sio_%d,\"processed_onkey\",0);\n",sio_id);
  printc ("SET(\"s_screenio\",_sio_%d,\"field_list\",0);\n",sio_id);

  if (byname == 1)
    {
      printc (" /* byname */");

      printc
	("SET(\"s_screenio\",_sio_%d,\"nfields\",A4GL_gen_field_chars((void ***)GETPTR(\"s_screenio\",_sio_%d,\"field_list\"),(void *)GET(\"s_screenio\",_sio_%d,\"currform\"),",sio_id,sio_id,sio_id);
      print_field_bind_constr ();
      printc (" ,0));\n");
    }
  else
    {
      printc (" /* not byname */");
      printc
	("SET(\"s_screenio\",_sio_%d,\"nfields\",A4GL_gen_field_chars((void ***)GETPTR(\"s_screenio\",_sio_%d,\"field_list\"),(void *)GET(\"s_screenio\",_sio_%d,\"currform\"),%s,0));\n",sio_id,sio_id,sio_id,
	 fld_list);
    }

  printc
    ("{int _sf; _sf=A4GL_set_fields(&_sio_%d); A4GL_debug(\"_sf=%%d\",_sf);if(_sf==0) {_fld_dr=0;break;}\n}\n",sio_id);
  printc ("_fld_dr= -1;\n");
}


/**
 * Print the firsr part of the C implementation of the AFTER/BEFORE FIELD
 * in the CONSTRUCT statement.
 *
 * @param fieldexpr The field name (eventualy in an expression).
 */
void
LEXLIB_print_befaft_field_1 (char *fieldexpr)
{
int n;
  n=A4GL_get_nevents();
  /*printc ("if (%s) {", fieldexpr);*/
  printc ("if (_exec_block==%d) { /* %s */\n", n,fieldexpr);
}

/**
 * Print the second part of the C implementation of AFTER/BEFORE FIELD
 * in the A4GL_construct statement.
 */
void
LEXLIB_print_befaft_field_2 (void)
{
  printc ("}\n");
}

/**
 * Print the generated C code for the first part of ON KEY in the CONSTRUCT
 * statement.
 *
 * @param key_list_str The Key list.
 */
void
LEXLIB_print_onkey_1 (char *key_list_str)
{
  int n;
  n=A4GL_get_nevents();
  printc ("if (_exec_block==%d) { /* %s */\n", n,key_list_str);
}

/**
 * Print the second part of the generated C code for ON KEY in CONSTRUCT 
 * statement.
 */
void
LEXLIB_print_onkey_2 (void)
{
  continue_loop ("INPUTREQ");
  printc ("}\n");
}

void
LEXLIB_print_onkey_2_prompt (void)
{
  print_exit_loop ('P', 0);
  printc ("}");
}


void
LEXLIB_print_onaction_1 (char *key_list_str)
{
	  int n;
	    n=A4GL_get_nevents();
	      printc ("if (_exec_block==%d) { /* %s */\n", n,key_list_str);
}

void
LEXLIB_print_onaction_2 (void)
{
	  continue_loop ("INPUTREQ");
	    printc ("}\n");
}


/**
 * Print the C implementation for the defer instruction.
 *
 * @param quit The signal to be deferred:
 *   - 1 : QUIT
 *   - 0 : INTERRUPT
 */
void
LEXLIB_print_defer (int quit)
{
  if (quit)
    printc ("A4GL_def_quit();");
  else
    printc ("A4GL_def_int();");
}


/**
 * The parser found the DISPLAY <message> without AT specification.
 *
 * Generate the C code that implements it.
 */
void
LEXLIB_print_display_line (void)
{
  printc ("A4GL_push_int(-1);A4GL_push_int(-1);\n");
}


/**
 * Print the generated C code for implementation of DISPLAY BY NAME statement.
 *
 * @param attr The attributes used on the display.
 */
void
LEXLIB_print_display_by_name (char *attr)
{
  int a;
  printc ("{\n");
  a = print_bind_definition ('i');
  print_bind_set_value ('i');
  printc ("A4GL_push_disp_bind(&ibind,%d);\n", a);
  printc ("A4GL_disp_fields(%d,%s,", a, attr);
  print_field_bind (a);
  printc (",0);\n");
  printc ("}\n");
}


/**
 * Generate a string with the C code corresponding to the optional AT or TO from
 * display 4gl statement.
 *
 * The string generated should be used with a sprintf because is generated
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
LEXLIB_A4GL_get_display_str (int type, char *s, char *f)
{
  static char buff[1024];
  if (type == 0)
    strcpy (buff, "A4GL_display_at(%s,%s);\n");
  if (type == 1)
    strcpy (buff, "A4GL_display_at(%s,%s);");
  if (type == 2)
    sprintf (buff, "A4GL_disp_fields(%%s,%%s,%s,0);\n", s);
  if (type == 3)
    sprintf (buff, "A4GL_disp_form_fields(%%s,%%s,\"%s\",%s,0);\n", f, s);
  if (type == 4)
    sprintf (buff, "A4GL_disp_main_caption();\n");
  if (type == 5)
    sprintf (buff, "A4GL_disp_form_caption(%s);\n", s);
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
LEXLIB_print_display (char *fmt, char *expr, char *attr)
{
  printc (fmt, expr, attr);
}

/**
 * Print to the generated C output file, the implementation of the DISPLAY
 * FORM 4gl statement.
 *
 * @param s The name of the form.
 * @param a The attributes used to open the form.
 */
void
LEXLIB_print_display_form (char *s, char *a)
{
  printc ("A4GL_disp_form(%s,%s);\n", s, a);
}



char *l_arrvar; char *l_srec; char *l_scroll; char *l_attr;

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
void
LEXLIB_print_display_array_p1 (char *arrvar, char *srec, char *scroll, char *attr, void *v_input_attr)
{
  int cnt;
  struct input_array_attribs *ptr_input_attr;
  int sio_id;
	l_arrvar=strdup(arrvar);
	l_srec=strdup(srec);
	l_attr=strdup(attr);
	l_scroll=strdup(scroll);

  ptr_input_attr = (struct input_array_attribs *) v_input_attr;
  printcomment ("/* Display array */\n");
  sio_id=get_sio_id("DISPLAY");
  printc ("{int _fld_dr;int _exec_block= 0;\nchar _sio_%d[%d];char *_sio_kw_%d=\"s_disp_arr\";\n",sio_id,
	  sizeof (struct s_disp_arr) + 10,sio_id);
  cnt = print_arr_bind ('o');
  printc ("SET(\"s_disp_arr\",_sio_%d,\"no_arr\",A4GL_get_count());\n",sio_id);
  printc ("SET(\"s_disp_arr\",_sio_%d,\"binding\",obind);\n",sio_id);
  printc ("SET(\"s_disp_arr\",_sio_%d,\"nbind\",%d);\n",sio_id, cnt);
  printc ("SET(\"s_disp_arr\",_sio_%d,\"srec\",0);\n",sio_id);
  printc
    ("SET(\"s_disp_arr\",_sio_%d,\"arr_elemsize\",sizeof(%s[0]));\n",sio_id, arrvar);
  printc ("_fld_dr= -1;_exec_block=0;\n");
  printc ("while (1) {\n");
}

/**
 * Prints the second part of C generated code to implement the INPUT ARRAY
 * 4gl statement.
 *
 * Called when the parser found the rest of DISPLAY ARRAY (<field_commands> END
 * INPUT or nothing).
 *
 */
void
LEXLIB_print_display_array_p2 (void)
{
  int sio_id;
  A4GL_add_event(-94,"");
  sio_id=get_sio_id("DISPLAY");
  printc("if (_exec_block==%d) { break; } ",A4GL_get_nevents());
  printc("{");
  print_event_list();
  printc ("_exec_block=A4GL_disp_arr_v2(&_sio_%d,%s,%s,%s /* attr */ ,%s /*scroll */,_sio_evt);\n", sio_id,l_arrvar, l_srec, l_attr, l_scroll);
	free(l_arrvar);
	free(l_srec);
	free(l_attr);
	free(l_scroll);
  printc("}");
  printc ("}\n}\n");
  printcomment ("/* end display */\n");
}

/**
 * The parser found a complete ERROR 4gl statement and print in the generated
 * output file the C implementation.
 *
 * @param s The attributes used to display the error.
 * @param wait The flag that indicates that should wait for some key.
 */
void
LEXLIB_print_error (char *s, int wait)
{
  printc ("A4GL_display_error(%s,%d);\n", s, wait);
}

/**
 * Print in the generated output C file the implementation of the EXIT PROGRAM
 * 4gl statement.
 *
 * @para has_expr The flag that indicates if it have an expression to calculate
 * the exit status:
 *   - 0 : Does not have exit status
 *   - Otherwise : Have and expression, so need to pop the value.
 */
void
LEXLIB_print_exit_program (int has_expr)
{


  if (doing_esql ())
    {
      printc ("if (A4GL_esql_db_open(-1,0,0,\"\")) {");
      print_close ('D', "");
      printc ("}");
    }

  if (has_expr)
    printc ("A4GL_fgl_end();exit(A4GL_pop_long());");
  else
    printc ("A4GL_fgl_end();exit(0);");
}


/**
 * Print in the generated C output file the begining of a FOR 4gl statement.
 *
 * Called by the parser when it found the FOR <variable> = <expression> TO
 * <expression> STEP <expression>.
 *
 * @param var The 4gl variable name used as iterator variable.
 */
void
LEXLIB_print_for_start (char *var)
{
  printc
    ("\n{int _s;int _e;int _step;\n_step=A4GL_pop_long();_e=A4GL_pop_long();_s=A4GL_pop_long();\n");
  printc
    ("for (%s=_s; (%s<=_e&&_step>0)||(%s>=_e&&_step<0);%s+=_step) {\n",
     var, var, var, var);
}

/**
 *  The parser found the END FOR 4gl substatement and generate the C 
 *  implementation.
 *
 *  Just finishes a C block.
 */
void
LEXLIB_print_for_end (void)
{
  printc ("}\n");
}

/**
 * The parser did not found a explicit STEP substatement in FOR statement and
 * it generates a push of 1 as default.
 */
void
LEXLIB_print_for_default_step (void)
{
  printc ("A4GL_push_int(1);\n");
}

/**
 * Generate in the generated C output file, the implementation of the first
 * part of FOREACH 4gl statement.
 *
 * Called by the parser when it found FOREACH <cursor_name>.
 */
void
LEXLIB_print_foreach_start (void)
{
  printc ("{");
}


#ifdef MOVED_TO_SQL
/**
 * The parser found END FOREACH.
 *
 * Prints to the generated output file the C implementation of the end of 
 * this statement (that is a C block close with }).
 */
void
print_foreach_end (void)
{
  printc ("}");
  printcomment ("/* end of foreach while loop */\n");

  printc ("}\n");
}
#endif


/**
 * For some statement, the C implementation need to push a string to the
 * internal stack.
 *
 * Prints the call to library push_char() to the output file.
 *
 * @param s The string to be pushed.
 */
void
LEXLIB_print_pushchar (char *s)
{
  printc ("A4GL_push_char(%s);/* 1*/ \n", s);
}

/**
 * Some of the statements are implemented with label mark in the generated C
 * output file and goto(s) to implement the cicle.
 *
 * Print the goto in the output file.
 *
 * @param label The C label name.
 */
void
LEXLIB_print_goto (char *label)
{
  printc ("goto %s;\n", label);
}

/**
 * Print the C implementation of actions to GUI specific menuitems.
 *
 * @param list Menu item list
 * @param mode: Mode to set.
 *   - C : Check menuitems.
 *   - U : Uncheck menuitems.
 *   - D : Disable menuitems.
 *   - E : Enable menuitems.
 */
void
LEXLIB_print_gui_do_menuitems (char *list, int mode)
{
if (A4GL_doing_pcode()) {
  if (mode == 'U') printc ("@UNCHECK (%s,0)\n", list);
  if (mode == 'C') printc ("@CHECK (%s,0)\n", list);
  if (mode == 'D') printc ("@ENDIS (0,%s,0);\n", list);
  if (mode == 'E') printc ("@ENDIS (1,%s,0);\n", list);
} else {
  if (mode == 'U') printc ("A4GL_uncheck_menuitems(%s,0);\n", list);
  if (mode == 'C') printc ("A4GL_check_menuitems(%s,0);\n", list);
  if (mode == 'D') printc ("A4GL_endis_menuitems(0,%s,0);\n", list);
  if (mode == 'E') printc ("A4GL_endis_menuitems(1,%s,0);\n", list);
}
}

/**
 * Print the C implementation of actions to the GUI fields specific statements.
 *
 * @param list The list of the fields.
 * @param mode The mode to be set:
 *   - D : Disable.
 *   - E : Enable. 
 */
void
LEXLIB_print_gui_do_fields (char *list, int mode)
{
  if (mode == 'D')
    printc ("A4GL_endis_fields(0,%s,0);\n", list);
  if (mode == 'E')
    printc ("A4GL_endis_fields(1,%s,0);\n", list);
}

/**
 * Print the C implementation for actions to do to GUI forms.
 *
 * @param name The form name.
 * @param list The field list to be afected.
 * @param mode The A4GL_action to be set:
 *   - D : Disable.
 *   - E : Enable.
 */
void
LEXLIB_print_gui_do_form (char *name, char *list, int mode)
{
  if (mode == 'D')
    printc ("A4GL_endis_form(0,%s,%s,0);\n", name, list);
  if (mode == 'E')
    printc ("A4GL_endis_form(1,%s,%s,0);\n", name, list);
}

/**
 * Print the first part of implementation of the IF 4gl statement.
 *
 * Called by the parser after found IF <expression> THEN.
 *
 * The execution of expression is made before the C if itself and use the
 * stack mechanism to get the boolean result of the expression evaluation.
 *
 */
void
LEXLIB_print_if_start (void)
{
  printc ("if (A4GL_pop_bool()) {\n");
}

/**
 * Print the first part of ELSE substatement implementation.
 *
 * Generate the C implementation to the generated output file.
 */
void
LEXLIB_print_if_else (void)
{
  printc ("} else {\n");
}

/**
 * The parser found END IF and it generate the corresponding C end of block.
 */
void
LEXLIB_print_if_end (void)
{
  printc ("}");
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
LEXLIB_print_import (char *func, int nargs)
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
  sprintf (buff, "_retval=(long)%s(", func);
  for (a = 0; a <= nargs - 1; a++)
    {
      if (a > 0)
	strcat (buff, ",");
      sprintf (buff2, "_argc[%d]", a);
      strcat (buff, buff2);
    }
  strcat (buff, ");\n   A4GL_push_int(_retval);\n   return 1;\n");
  strcat (buff, "}\n\n\n");
  printc (buff);
}


int
split_arrsizes (char *s, int *arrsizes)
{
  char *ptrs[10];
  char buff[200];
  int cnt = 1;
  int a;


  strcpy (buff, s);
  ptrs[0] = buff;

  for (a = 0; a < 10; a++)
    arrsizes[a] = 0;

  for (a = 0; a < strlen (s); a++)
    {
      if (s[a] == ']')
	{
	  buff[a] = 0;
	  ptrs[cnt++] = &s[a + 2];
	}

    }


  for (a = 0; a < cnt; a++)
    {
      arrsizes[a] = atoi (ptrs[a]);
    }
  return cnt;

}

void
print_init_var (char *name, char *prefix, int alvl)
{
  int d;
  int a;
  int size;
  int lvl;
  char arr[256];
  int x;
  /*char buff[1024];*/
  char prefix2[1024];
  int arrsizes[10];
  int cnt = 0;
  int acnt;
  int printing_arr;
  int dont_print = 0;




  printing_arr = 0;
  /* Have we got a record ?*/
  if (strchr (name, '.'))
    {
      char buffx[1024];
      char *ptr;

      /* OK - we're going to break this down...*/
      strcpy (buffx, name);
      ptr = strchr (buffx, '.');
      /* We've found the next '.'*/
      /* put the LHS onto 'prefix'*/
      /* and the RHS into name...*/
      *ptr = 0;
      ptr++;
      strcpy (prefix2, prefix);
      if (strlen (prefix2))
	{
	  strcat (prefix2, ".");
	}
      strcat (prefix2, buffx);

      x = get_variable_dets (prefix2, &d, &a, &size, &lvl, arr);

      if (x == -1)
	{
	  a4gl_yyerror ("Couldn't find variable to null it...[2]");
	  return;
	}
      if (x != -2)
	{
	  a4gl_yyerror ("I was expecting a record...");
	  return;
	}

      /* is this an array ?*/
      if (a && prefix2[strlen (prefix2) - 1] != ']')
	{
	  char buff_id[256];
	  printing_arr = 1;
	  cnt = split_arrsizes (arr, (int *) &arrsizes);
	  if (arrsizes[0] > 0)
	    {
	      for (acnt = 0; acnt < cnt; acnt++)
		{
		  sprintf (buff_id, "_fglcnt_%d", alvl);
		  printc ("{int %s;\n", buff_id);
		  printc ("for (%s=0;%s<%d;%s++) { /* 1 */", buff_id, buff_id,
			  arrsizes[acnt], buff_id);
		  strcat (prefix2, "[");
		  strcat (prefix2, buff_id);
		  strcat (prefix2, "]");
		  alvl++;
		}
	    }
	  else
	    {
	      dont_print = 1;
	    }
	}

      if (dont_print==0)
	print_init_var (ptr, prefix2, alvl);

      if (printing_arr && dont_print==0)
	{
	  for (acnt = 0; acnt < cnt; acnt++)
	    {
	      printc ("} /* End init for */\n}\n");
	      alvl--;
	    }
	}

      return;
    }


/* If we've got to here we can only be dealing with a leaf on a record*/
  strcpy (prefix2, prefix);
  if (strlen (prefix2))
    {
      strcat (prefix2, ".");
    }
  strcat (prefix2, name);



  x = get_variable_dets (prefix2, &d, &a, &size, &lvl, arr);

  if (x < 0)
    {
      a4gl_yyerror ("Couldn't find variable to null it...[1]");
      return;
    }

  dont_print=0;

  if (a && prefix2[strlen (prefix2) - 1] != ']')
    {
      char buff_id[256];
      printing_arr = 1;
      cnt = split_arrsizes (arr, (int *) &arrsizes);
      if (arrsizes[0] >= 0)
	{
	  for (acnt = 0; acnt < cnt; acnt++)
	    {
	      sprintf (buff_id, "_fglcnt_%d", alvl);
	      printc ("{int %s;\n", buff_id);
	      printc ("for (%s=0;%s<%d;%s++) { /* 2 */", buff_id, buff_id,
		      arrsizes[acnt], buff_id);
	      strcat (prefix2, "[");
	      strcat (prefix2, buff_id);
	      strcat (prefix2, "]");
	      alvl++;
	    }
	} else {
		dont_print=1;
	}
    }

  if (dont_print==0) printc ("A4GL_setnull(%d,&%s,%d);\n", d & 0xffff, prefix2, size);

  if (printing_arr && !dont_print)
    {
      for (acnt = 0; acnt < cnt; acnt++)
	{
	  printc ("} /* End init for */\n}\n");
	  alvl--;
	}
    }

}

/**
 * Print in the generated output file the C implementation of the 
 * INITIALIZE <variable_list> TO NULL 4gl statement.
 */
void
LEXLIB_print_init (void)
{
  int cnt;
  printc ("{\n");

  expand_bind (&nullbind[0], 'N', nullbindcnt);

  for (cnt = 0; cnt < nullbindcnt; cnt++)
    {
      print_init_var (nullbind[cnt].varname, "", 0);
    }

  /*cnt = print_bind ('N');*/
  /*printc ("A4GL_set_init(nullbind,%d);\n", cnt);*/
  printc ("}\n");
}

/**
 * Print the C implementation of the INITIALIZE LIKE 4gl statement.
 *
 * @param s The column list. Not used now.
 */
void
LEXLIB_print_init_table (char *s)
{
  int cnt;
  printc ("{\n");
  cnt = print_bind_definition ('N');
  cnt = print_bind_set_value ('N');
  printc ("A4GL_set_init(nullbind,%d);\n", cnt);
  printc ("}\n");
}

void
LEXLIB_print_validate ()
{
  int cnt;
  int z;
  int a;

  z = get_bind_cnt ('N');
  cnt=get_validate_list_cnt();
  if (z!=cnt) {
	  set_yytext("");
	  A4GL_debug(" validate mismatch : %d %d\n",z,cnt);
	  a4gl_yyerror ("Mismatch in number of variables and number of columns");
	  return;
  }
  printc("/* VALIDATE */");
  printc ("    A4GLSQL_set_status(0,0);\n");
  for (a=0;a<z;a++) {
        char buff[256];
	struct expr_str *p;
	p=(struct expr_str *)A4GL_get_validate_expr(a);
	if (p==0) continue;
	printc ("A4GL_push_variable(&%s,0x%x);\n", nullbind[a].varname, nullbind[a].dtype );
        sprintf(buff,"A4GL_push_int(%d);",length_expr(p));
        p=A4GL_append_expr(p,buff);
        p=A4GL_append_expr(p,"A4GL_pushop(OP_IN);");
	print_expr(p);
	printc("if (!A4GL_pop_bool()) {A4GLSQL_set_status(-1321,0);}");
  }
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
LEXLIB_A4GL_generate_or (char *out, char *in1, char *in2)
{
  sprintf (out, "%s||%s", in1, in2);
}


/**
 * Generate the C code implementation of the NEXT FIELD command for INPUT 4gl
 * statement.
 *
 * Called after the parser found NEXT FIELD <fieldName> 
 *
 * @param s The name of the field where the input should jump to.
 */
void
LEXLIB_print_next_field (char *s)
{
  int sio_id;

  sio_id=get_sio_id("ALLINPUT"); 
  
  if (strcmp (s, "\"+\"") == 0)
    {
      printc ("A4GL_req_field(&_sio_%d,_inp_io_type,'+',%s,0,0);\n", sio_id,s);
    }
  else
    {
      if (strcmp (s, "\"-\"") == 0)
	{
	  printc ("A4GL_req_field(&_sio_%d,_inp_io_type,'-',%s,0,0);\n", sio_id,s);
	}
      else
	{
	  printc ("A4GL_req_field(&_sio_%d,_inp_io_type,'!',%s,0,0);\n", sio_id,s);
	}
    }

  if (isin_command ("INPUT") > isin_command ("CONSTRUCT"))
    {
      continue_loop ("INPUTREQ");
    }
  else
    {
      continue_loop ("CONSTRUCTREQ");
    }
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
LEXLIB_print_input_1 (void)
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
LEXLIB_print_input_2 (char *s)
{
 int sio_id;
  A4GL_add_event(-94,"");
  printc("if (_exec_block==%d) { break; } ",A4GL_get_nevents());
  printc("{");
  print_event_list();
  printc ("_exec_block=%s;_forminit=0;\n", s);
  printc("if (_exec_block>0) _fld_dr=_sio_evt[_exec_block-1].event_type; else _fld_dr= -1;");
  printc("}");


  add_continue_blockcommand ("INPUT");
  printc ("\n}\n");
  sio_id=get_sio_id("INPUT");
  pop_blockcommand ("INPUT");
  printc("A4GL_finish_screenio(_sio_%d,_sio_kw_%d);",sio_id,sio_id);

  printc ("}\n");


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
LEXLIB_print_input (int byname, char *defs, char *helpno, char *fldlist, int attr)
{
  int ccc;
  int sio_id;
  printc ("/*");
  push_blockcommand ("INPUT");
  printc ("*/");
  sio_id=get_sio_id("INPUT");
  printc
    ("{int _fld_dr= -100;int _exec_block= 0;char *fldname;char _sio_%d[%d]; char _inp_io_type='I';char *_sio_kw_%d=\"s_screenio\";", sio_id,sizeof (struct s_screenio) + 10,sio_id);
  printc ("int _forminit=1;\n");
  printc ("while(_fld_dr!=0){\n");
  printc ("if (_fld_dr== -100) {\n");
  printc ("/* input by name */");
  ccc = print_bind_definition ('i');
  print_bind_set_value ('i');
  printc
    ("SET(\"s_screenio\",_sio_%d,\"currform\",A4GL_get_curr_form(1));\n",sio_id);
  printc ("if ((int)GET(\"s_screenio\",_sio_%d,\"currform\")==0) break;\n",sio_id);
  printc ("SET(\"s_screenio\",_sio_%d,\"vars\",ibind);\n",sio_id);
  printc ("SET(\"s_screenio\",_sio_%d,\"attrib\",%d);\n",sio_id, attr);
  printc ("SET(\"s_screenio\",_sio_%d,\"novars\",%d);\n",sio_id, ccc);
  printc ("SET(\"s_screenio\",_sio_%d,\"help_no\",%s);\n",sio_id, helpno);

  printc ("SET(\"s_screenio\",_sio_%d,\"processed_onkey\",0);\n",sio_id);
  printc ("SET(\"s_screenio\",_sio_%d,\"field_list\",0);\n",sio_id);

  printc ("SET(\"s_screenio\",_sio_%d,\"currentfield\",0);\n",sio_id);
  printc ("SET(\"s_screenio\",_sio_%d,\"currentmetrics\",0);\n",sio_id);
  printc ("SET(\"s_screenio\",_sio_%d,\"mode\",%d+%s);\n",sio_id, MODE_INPUT, defs);
  if (byname)
    {
      printc
	("SET(\"s_screenio\",_sio_%d,\"nfields\",A4GL_gen_field_chars((void ***)GETPTR(\"s_screenio\",_sio_%d,\"field_list\"),(void *)GET(\"s_screenio\",_sio_%d,\"currform\"),",sio_id,sio_id,sio_id);
      print_field_bind (ccc);
      printc
	(",0)); if ((int)GET(\"s_screenio\",_sio_%d,\"nfields\")==-1) break;\n",sio_id);
    }
  else
    {
      printc
	("SET(\"s_screenio\",_sio_%d,\"nfields\",A4GL_gen_field_chars((void ***)GETPTR(\"s_screenio\",_sio_%d,\"field_list\"),(void *)GET(\"s_screenio\",_sio_%d,\"currform\"),%s,0));\n", sio_id,sio_id,sio_id,
	 fldlist);
      printc
	("if ((int)GET(\"s_screenio\",_sio_%d,\"nfields\")==-1) break;\n",sio_id);
    }
  printc
    ("{int _sf; _sf=A4GL_set_fields(&_sio_%d); A4GL_debug(\"_sf=%%d\",_sf);if(_sf==0) {_fld_dr=0;break;}\n}\n",sio_id);
  printc ("_fld_dr= -1;_exec_block=0;\n");
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
char *
LEXLIB_print_input_array (char *arrvar, char *helpno, char *defs, char *srec,
		   char *attr, void *v_input_attr)
{
  static char buff2[256];
  int cnt;
  int sio_id;
  struct input_array_attribs *ptr_input_attr;
  ptr_input_attr = (struct input_array_attribs *) v_input_attr;
  printc ("/*");
  push_blockcommand ("INPUT");
  sio_id=get_sio_id("INPUT");
  printc ("*/");
  printcomment ("/* input */\n");
  printc ("{int _fld_dr= -100;int _exec_block= 0;\nchar *fldname;\nint _forminit=1;");
  printc ("char _sio_%d[%d];char _inp_io_type='A';char *_sio_kw_%d=\"s_inp_arr\";\n",sio_id,
	  sizeof (struct s_inp_arr) + 10,sio_id);
  cnt = print_arr_bind ('o');
  printc ("while (_fld_dr!=0) {\n");
  printc ("if (_exec_block==0) {\n");
  printc ("SET(\"s_inp_arr\",_sio_%d,\"no_arr\",A4GL_get_count());\n",sio_id);
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
  printc ("if ((int)GET(\"s_inp_arr\",_sio_%d,\"currform\")==0) break;\n",sio_id);
  printc ("SET(\"s_inp_arr\",_sio_%d,\"currentfield\",0);\n",sio_id);
  printc ("SET(\"s_inp_arr\",_sio_%d,\"currentmetrics\",0);\n",sio_id);
  printc ("SET(\"s_inp_arr\",_sio_%d,\"mode\",%d+%s);\n",sio_id, MODE_INPUT, defs);

  if (ptr_input_attr->curr_row_display)
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


  printc
    ("SET(\"s_inp_arr\",_sio_%d,\"nfields\",A4GL_gen_field_chars((void ***)GETPTR(\"s_inp_arr\",_sio_%d,\"field_list\"),(void *)GET(\"s_inp_arr\",_sio_%d,\"currform\"),A4GL_add_dot_star(%s),0,0));\n",sio_id,sio_id,sio_id, srec);
  printc ("_fld_dr= -1;_exec_block=-1;continue;\n");
  sprintf (buff2, "A4GL_inp_arr_v2(&_sio_%d,%s,%s,%s,_forminit,_sio_evt);\n", sio_id,defs, srec, attr);
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
LEXLIB_A4GL_get_formloop_str (int type)
{
static char buff[256];
  if (type == 0)		/* Input, Input by name */ {
	sprintf(buff, "A4GL_form_loop_v2(&_sio_%d,_forminit,_sio_evt)",get_sio_id("ALLINPUT"));
	return buff;
  }

  return "";
}

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
LEXLIB_print_scroll (char *flds, char *updown)
{
  printc ("A4GL_acli_scroll(%s,%s,0,0);\n", updown,flds);
}


/**
 * Print the C implementation to the LABEL 4gl statement in the generated output
 * file.
 *
 * @param s The label name.
 */
void
LEXLIB_print_label (char *s)
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
LEXLIB_print_let_manyvars (char *nexprs)
{
  int from_exprs;
  int to_vars;
  A4GL_debug ("1");
  A4GL_debug ("In print_let_manyvars : %s\n", nexprs);
  printc ("{");
  to_vars = print_bind_definition ('o');
  print_bind_set_value ('o');

  from_exprs = atoi (nexprs);

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
LEXLIB_print_push_null (void)
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
LEXLIB_print_start_report (char *where, char *out, char *repname,char *dim)
{
  add_function_to_header (repname, 2,"");
  // @ todo - fixup 'out' handling
  // Background - historically, 'out' was a string  (either literal or a string variable)
  // we can now use an expression instead - but all we've done here is a quick hack to pop
  // the expression from the stack and then put it back in the right place (ie in the order the report is expected it - after the 'where')
  // We need to do this properly by not popping it at all and just getting the start report to pop them off in the right 
  // order - but this might break previously compiled code 
  // (So we're leaving it to work with this kludge for now)
  printc("{");
	  printc("char *_rout_to=0;");
  if (strlen(out)==0) {
	  printc("_rout_to=A4GL_char_pop();");
  }

  printc ("A4GL_push_char(\"%s\");\n", where);

  if (strlen(out)) {
	  	printc ("A4GL_push_char(%s);\n", out);
  } else { 
	  	printc ("A4GL_push_char(_rout_to);\n", out);
  }

  printc ("A4GL_set_report_dim(%s);", dim);
  printc("if (_rout_to) free(_rout_to);}");
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
LEXLIB_print_output_to_report (char *repname, char *nvalues)
{
  add_function_to_header (repname, 2,"");
  printc ("%s%s(%s,REPORT_SENDDATA);\n", get_namespace (repname), repname,
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
LEXLIB_print_finish_report (char *repname)
{
  add_function_to_header (repname, 2,"");
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
LEXLIB_print_terminate_report (char *repname)
{
  add_function_to_header (repname, 2,"");
  printc ("%s%s(0,REPORT_TERMINATE);\n", get_namespace (repname), repname);
}


/**
 * The parser found the ON EVERY ROW instruction from reports.
 *
 * Generate the C implementation to the output file.
 */
void
LEXLIB_print_format_every_row (void)
{
  push_report_block ("EVERY", 'E');


  printc ("{int _rr;for (_rr=0;_rr<%d;_rr++) {", fbindcnt);
  printc ("A4GL_push_char(_rbindvarname[_rr]);\n");
  printc ("A4GL_%srep_print(&_rep,1,1,0,-1); A4GL_push_long(19); A4GL_set_column(&_rep);A4GL_%srep_print(&_rep,1,1,0,-1); \n",ispdf(),ispdf());
  printc ("A4GL_push_variable(_rbind[_rr].ptr,_rbind[_rr].dtype);");
  printc ("A4GL_%srep_print(&_rep,1,1,0,-1); A4GL_%srep_print(&_rep,0,0,0,-1);\n",ispdf(),ispdf());
  printc ("}");
  printc
    ("A4GL_push_char(\" \");A4GL_%srep_print(&_rep,1,1,0,-1); A4GL_%srep_print(&_rep,0,0,0,-1);",ispdf(),ispdf());
  printc ("}");
  /* printc ("#error FORMAT EVERY ROW not implemented yet");
     print_rep_ret (); */
  print_rep_ret (report_cnt,0);

}

/**
 * Print the C implementation of NEED <number> LINES statement.
 */
void
LEXLIB_print_need_lines (void)
{
  printc ("A4GL_%sneed_lines(&_rep);\n", ispdf ());
}

/**
 * Print the C implementation of SKIP <number> LINES statement.
 */
void
LEXLIB_print_skip_lines (double d)
{
  printc ("A4GL_push_int(%d);", (int) d);
  printc ("A4GL_%saclfgli_skip_lines(&_rep);\n", ispdf ());
}

/**
 * Print the C implementation of the SKIP TO TOP OF PAGE statement.
 */
void
LEXLIB_print_skip_top (void)
{
  printc ("A4GL_%sskip_top_of_page(&_rep,0);\n", ispdf ());
}

/**
 * Print the C implementation of SKIP BY statement.
 */
void
LEXLIB_print_skip_by (double nval)
{
  printc ("A4GL_pdf_skip_by(&_rep,%f);\n", nval);
}

/**
 * Print the C implementation of the SKIP TO statement.
 */
void
LEXLIB_print_skip_to (char *nval)
{
  printc ("A4GL_pdf_skip_to(&_rep,%s);\n", nval);
}

/**
 * The parser found a complete PRINT report statement.
 *
 * Prints the C implementation to the output file.
 *
 * @param type 
 *   - 0 :
 *   - 1 :
 * @param semi Flag that indicates if a semicolon was found at the end (
 * indicates if should generate a NEW LINE after when run) :
 *   - 0 : Do not have semicolon.
 *   - 1 : Have semicolon
 * @param wordwrap
 */
void
LEXLIB_print_report_print (int type, char *semi, char *wordwrap)
{
int semi_i;
 
  if (semi==0) semi_i=0; else semi_i=1;
  if (type == 0)
    printc ("A4GL_%srep_print(&_rep,0,%s,0,-1);\n", ispdf (), semi);

  if (type == 1)
    printc ("A4GL_%srep_print(&_rep,1,1,%s,%d);\n", ispdf (), wordwrap,rep_print_entry++);
}

/**
 * The parser found a PRINT FILE statement.
 *
 * Generate the implementing C code to the output file.
 *
 * @param fname The filename to include in the report.
 * @param semi:
 *   - 0 : No semicolon after (put a new line after image).
 *   - 1 : Semicolon after (do not change to other line).
 */
void
LEXLIB_print_report_print_file (char *fname, char *semi)
{
  printc ("%sA4GL_rep_file_print(&_rep,%s,%s);\n", ispdf (), fname, semi);
}

/**
 * Generate the C implementation to the PRINT IMAGE 4gl statement.
 *
 * This instruction is an extension to informix 4gl.
 *
 * @param scaling The optional scaling definition.
 * @param blob The blob variable.
 * @param type The image type:
 *   - TIFF
 *   - GIF
 *   - PNG
 *   - JPEG
 * @param semi:
 *   - 0 : No semicolon after (put a new line after image).
 *   - 1 : Semicolon after (do not change to other line).
 */
void
LEXLIB_print_report_print_img (char *scaling, char *blob, char *type, char *semi)
{
  printc ("%s pdf_blob_print(&_rep,&%s,\"%s\",%s);\n", scaling,
	  blob, type, semi);
}

/**
 *  The parser did not found the SCALED BY statement.
 *
 *  It generates a default scale to the generated C code.
 */
char *
LEXLIB_A4GL_get_default_scaling (void)
{
  return "A4GL_push_double(1.0);A4GL_push_double(1.0);";
}

/**
 * Defines in the generated C code, the type of the order by used.
 *
 * @param type The type of order by:
 *   - 1 : Normal order by or not defined.
 *   - 2 : The order is external to the report (made in the select statement).
 */
void
LEXLIB_print_order_by_type (int type, int size)
{
  last_orderby_type = type;
  printc ("static int acl_rep_ordcnt=%d;\n", size);
  printc ("static int fgl_rep_orderby=%d;\n", type);
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
LEXLIB_print_report_1 (char *name)
{
  strcpy (mv_repname, name);
  add_function_to_header (name, 2,"");
  printc ("A4GL_REPORT void %s%s (int _nargs,int acl_ctrl) {\n", get_namespace (name), name, name);
  printc("static char *_reportName=\"%s\";\n",name);
  rep_print_code=0;
  rep_print_entry=0;
}

/**
 * The parser found the END REPORT and closes the generated C function.
 */
void
LEXLIB_print_report_end (void)
{


  printc ("\n} /* end of report */\n");
}

/**
 * Called in the middle of the REPORT definition after the parser found
 * the optional output and (or) order external by.
 * @param pdf :
 *   - 0 : Its not a PDF report.
 *   - 1 : Its a PDF report.
 * @param repordby
 */
void
LEXLIB_print_report_2 (int pdf, char *repordby)
{
  int cnt;
  int a;
  if (pdf)
    printc ("static struct pdf_rep_structure _rep;\n");
  else
    printc ("static struct rep_structure _rep;\n");

  printc ("static char _rout1[256];\n");
  printc ("static char _rout2[256];\n");
  printc ("static int _useddata=0;\n");
  printc ("static int _started=0;\n");
  printc ("static int _assigned_ordbind=0;\n");
  cnt = print_param ('r');
if (!A4GL_doing_pcode()) {
  printc ("init_module_variables();");
}
  printc(" if (_assigned_ordbind==0) { _assigned_ordbind=1;"); print_bind_set_value('O'); printc("}");

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
     get_curr_rep_name ());
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
      print_report_table (mv_repname, 'R', cnt);
      printc ("return;}");
    }

  printc ("if (acl_ctrl==REPORT_SENDDATA) {\n");
  printc ("   int _g,_p;\n");


  /* This was put in to force a page header if*/
  /* data was sent - but not used..*/
  /* But this prints too early here...*/
  /*printc ("   A4GL_rep_print(&_rep,0,1,0,-1);");*/


  printc ("   _g=A4GL_chk_params(_rbind,%d,_ordbind,acl_rep_ordcnt);\n", cnt);
  printc
    ("   if (_g>0&&_useddata) {for (_p=acl_rep_ordcnt;_p>=_g;_p--) %s(_p,REPORT_AFTERGROUP);}\n",
     get_curr_rep_name ());
  printc ("   A4GL_pop_params(_rbind,%d);\n", cnt);
  printc ("   if (_useddata==0) {_g=1;}\n");
  printc ("   if (_g>0) {");
  printc ("    A4GL_%srep_print(&_rep,0,1,0,-1);\n",ispdf()); // Mantis ID 573
  printc ("        _useddata=1;");
  printc ("        for (_p=_g;_p<=acl_rep_ordcnt;_p++) ");
  printc ("               %s(_p,REPORT_BEFOREGROUP);", get_curr_rep_name ());
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
      printc ("        %s(2,REPORT_RESTART);\n", get_curr_rep_name ());

      /*printc ("        A4GL_init_report_table(_rbind,%d,_ordbind,acl_rep_ordcnt,&reread);\n", cnt);*/
      print_report_table (mv_repname, 'I', cnt);

      /*printc ("        while (A4GL_report_table_fetch(reread,%d,_rbind))",cnt);*/
      print_report_table (mv_repname, 'F', cnt);

      printc ("                    %s(%d,REPORT_SENDDATA);\n",
	      get_curr_rep_name (), cnt);
      printc (" }");
      printc ("        %s(0,REPORT_FINISH);\n", get_curr_rep_name ());

      /*printc ("        A4GL_end_report_table(_rbind,%d,reread);",cnt);*/
      print_report_table (mv_repname, 'E', cnt);

      printc ("        return;");
      printc ("    }\n");
    }

  printc ("}\n");



  printc (" ");
  printc("if (acl_ctrl==REPORT_CONVERT) {");
  printc("char *_f; char *_o; char *_l; int _to_pipe; _l=A4GL_char_pop(); _o=A4GL_char_pop(); _f=A4GL_char_pop(); _to_pipe=A4GL_pop_int();\n");
  printc("A4GL_convert_report(&_rep,_f,_o,_l,_to_pipe);");
  printc("return ;}");
  printc("if (acl_ctrl==REPORT_FREE) {");
  printc("A4GL_free_report(&_rep);");
  printc("return ;}");
  printc ("if (acl_ctrl==REPORT_START||acl_ctrl==REPORT_RESTART) {\n");
  printc ("   A4GL_pop_char(_rout2,254);A4GL_trim(_rout2);\n");
  printc ("   A4GL_pop_char(_rout1,254);A4GL_trim(_rout1);\n");
  if (last_orderby_type == 1)
    {
      printc ("   if (acl_ctrl==REPORT_START) {fgl_rep_orderby=1;}\n");
      printc ("   if (fgl_rep_orderby==1) {");
      print_report_table (mv_repname, 'M', cnt);
      printc ("       return;");
      printc ("   }\n");
    }


  printc ("   _useddata=0;\n");
  printc ("   _started=1;\n");
  printc ("goto output_%d;\n", report_cnt);
  printc ("}\n\n");
  print_rep_ret (report_cnt,0);
  if (pdf)
    pdf_print_output_rep (&pdf_rep_struct);
  else
    print_output_rep (&rep_struct);
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
LEXLIB_print_pause (char *msg)
{
  printc ("A4GL_pause(%s);\n", msg);
}

/* MISC */

/**
 * Called when sleep instruction is found prints the target language sleep
 * function call.
 */
void
LEXLIB_print_sleep (void)
{
  printc ("A4GL_sleep_i();\n");
}


/* EXPRESSIONS */

/**
 *
 * @todo Describe function
 */
void
LEXLIB_print_op (char *type)
{
  printc ("A4GL_pushop(%s);\n", type);
}



/**
 * Print in the generated C code the reference to instruction not 
 * implemented yet.
 *
 * @param type A string with the statement that is not implemented
 */
void
LEXLIB_print_niy (char *type)
{
  printc ("#error Not Implemented Yet %s", type);
}


/**
 * Not used? but it is called from /compilers/4glc/fgl.yacc
 */
void
LEXLIB_print_push_variable (char *s)
{
  printc ("A4GL_push_param(&%s,0x%x);\n", s, scan_variable (s));
}

/**
 * Generates the C implementation of the MESSAGE statement.
 *
 * @param type Allways 0.
 * @param attr Attributes used in message.
 * @param wait The time that it waits.
 */
void
LEXLIB_print_message (int type, char *attr, int wait, int exprs)
{
  if (type == 0)
    printc ("aclfgli_pr_message(%s,%d,%d);\n", attr, wait, exprs);
  else
    printc ("aclfgli_pr_message_cap(%d,%d,%d);\n", attr, wait, exprs);
}

/**
 * The parser found a SYSTEM 4gl instruction.
 * The call to A4GL_system_run function in C mode it will be generated.
 *
 * @param type The type of the run:
 *   - 0 : Normal run
 *   - 1 : With returning of exit status
 *   - 2 : In background
 * @param rvar The variable name to where the exit status should be returned.
 */
void
LEXLIB_print_system_run (int type, char *rvar)
{
  printc ("A4GL_system_run(%d);", type);

  if (rvar)
    print_pop_variable (rvar);
}


/**
 * Print the C implementation for the options of SET SESSION and 
 * SET CURSOR OPTION statements.
 *
 * @param type The type of set options to generate:
 *   - conn : SET SESSION statement.
 *   - stmt : SET CURSOR statement.
 * @param id The cursor name or the connection id.
 * @param var
 * @param val
 */
void
LEXLIB_print_set_options (char *type, char *id, char *var, char *val)
{
  printc ("A4GL_set_%s_options(%s,%s,%s);\n", type, id, var, val);
}

/**
 * Called by the parser after it found the keyword (and just the keyword)
 * WHILE.
 */
void
LEXLIB_print_while_1 (void)
{
  printc ("while (1==1) {\n");
}

/**
 * Executed by the parser after found the expression in an WHILE statement.
 *
 * Generate the C corresponding implementation.
 */
void
LEXLIB_print_while_2 (void)
{
  printc ("if (!(A4GL_pop_bool())) break;\n");
}

/**
 * for future enhancement! 
 */
void
LEXLIB_print_while_3 (void)
{
  /* for future enhancement! */
}




/**
 *
 */
void
LEXLIB_print_undo_use (char *s)
{
  printc (s);
}


/**
 * The parser found the first part of normal prompt instruction.
 *
 * This first part is: 
 *   PROMPT "Title" <attributes> FOR [char] variable <attributes>
 *
 * @param a1 The attributes
 * @param a2 Optional character (cbreak()) indication
 * @param a3 The help number
 * @param a4 The prompt attributes
 */
void
LEXLIB_print_prompt_1 (char *a1, char *a2, char *a3, char *a4, int timeout)
{
  printc ("{char _sio_%d[%d];int _fld_dr= -9999;int _exec_block= 0;char *_sio_kw_%d=\"s_prompt\";int _acl_prompt_timeout=%d;\n",get_sio_id("PROMPT"), sizeof (struct s_prompt),get_sio_id("PROMPT"),timeout);
  printc ("A4GL_start_prompt(&_sio_%d,%s,%s,%s,%s);\n", get_sio_id("PROMPT"),a1, a2, a3, a4);
  printc ("while (1) {");
}

/**
 * Print the C implementation of PROMPT FOR CHAR cbreak prompt.
 * 
 * I think this code is obsolete and should be done in the
 * libui instead of here...
 */
void
LEXLIB_print_prompt_forchar (void)
{
  /*printc ("if (_fld_dr) {\n");*/
  /*print_exit_loop ('P', 0);*/
  /*printc ("}\n");*/
}

/**
 * The parser found a END PROMPT in the proper context
 *
 * This function generates the C implementaion for the command found in 
 * the source file.
 *
 * @param s The name of the variable where the result pressed wil be inserted
 */
void
LEXLIB_print_prompt_end (char *s)
{
  printc("{");
  print_event_list();
  printc("if ((int)GET(\"s_prompt\",_sio_%d,\"mode\")==2) break;",get_sio_id("PROMPT"));
  printc("_exec_block=A4GL_prompt_loop_v2(&_sio_%d,_acl_prompt_timeout,_sio_evt);\n",get_sio_id("PROMPT"));
  printc ("}\n");
  printc("}");
  print_pop_variable (s);
  printc ("}\n");
}

/**
 * The Parser found a complete open window fgl instruction.
 *
 * It generates the C code that implements the open window.
 *
 * Uses the form attribute(s) current in the global variable (form_attrib).
 *
 * @param The window name
 * @param type I think it is allways fixed with "cr_window"
 */
void
LEXLIB_print_open_window (char *name, char *type)
{
  printc ("%s(%s,", type, name);
  print_form_attrib (&form_attrib);
  printc (");\n");
}

/**
 * Executed by the parser when the all 4gl OPEN FORM was identified.
 *
 * @param ftm The rest (the form file name and some attributes).
 * @param a1 The form name.
 * @param a2 The form name (again ?).
 */
void
LEXLIB_print_open_form (char *fmt, char *a1, char *a2)
{
if (strncmp(fmt,"A4GL_open_gui_form",strlen("A4GL_open_gui_form") )==0) {
	//char buff[256];
	//char *ptr;


	if (A4GL_isyes(acl_getenv("NOCLOBBER")) && 0) {
		printf("Hello World\n");
        	if (scan_variable (a1) == -1) {
	  		set_yytext(a1);
	  		a4gl_yyerror ("Form variable not defined");
	  		return;
		}
  		printc (fmt, a1, a2);
	} else {
        	if (scan_variable (A4GL_get_important_from_clobber(a1)) == -1) {
	  		set_yytext(A4GL_get_important_from_clobber(a1));
	  		a4gl_yyerror ("Form variable not defined");
	  		return;
		}
  		printc (fmt, A4GL_get_important_from_clobber(a1), a2);
	}
} else {
  	printc (fmt, a1, a2);
}
}



/**
 * Generate the C code to clear a window.
 *
 * @param s The window name.
 */
void
LEXLIB_print_clr_window (char *s)
{
  printc ("A4GL_clr_window(%s);\n", s);
}

/**
 * Generate the C code with implementation of the for clear.
 *
 * Called when the parser found the CLEAR FORM statement.
 *
 * @param formname The name of the form
 * @param clr The fields to be cleared. 0 if none.
 * @param defs
 *   - 1 : Clear the fields to defaults table.
 *   - 0 : Do not use the defaults table.
 */
void
LEXLIB_print_clr_form (char *formname, char *clr, char *defs)
{
  if (formname == 0)
    printc ("A4GL_clr_form(%d);", atoi (defs));
  else
    /*print_niy ("Clear Form fields");*/
    printc ("A4GL_clr_form_fields(%d,%s);", atoi (defs), clr);
}

/**
 * Generate the C code to the CLEAR field implementation.
 *
 * This is not yet implemented.
 *
 * @param flds The field list
 * @param defs :
 *   - 1 : Clear the fields to defaults table.
 *   - 0 : Do not use the defaults table.
 */
void
LEXLIB_print_clr_fields (char *flds, char *defs)
{

  printc ("A4GL_clr_fields(%d,%s,0,0);", atoi (defs), flds);

  /*print_niy ("Clear Fields");*/
}

/**
 * The parser found a CURRENT WINDOW IS and called this function.
 *
 * It generates the implementation calling the cosrresponding library function
 * current_window().
 *
 * @param s The window name.
 */
void
LEXLIB_print_current_window (char *s)
{
  printc ("A4GL_current_window(%s);\n", s);
}

/**
 * Print the C implementation corresponding to the founded SHOW WINDOW
 * 4gl statement found.
 *
 * @param s The window name.
 */
void
LEXLIB_print_show_window (char *s)
{
  printc ("A4GL_show_window(%s);\n", s);
}

/**
 * Print the C implementation corresponding to the founded HIDE WINDOW
 * 4gl statement found.
 *
 * @param s The window name.
 */
void
LEXLIB_print_hide_window (char *s)
{
  printc ("A4GL_hide_window(%s);\n", s);
}

/**
 * The parser found a SHOW MENU instruction and generates the C code
 * implementation for it.
 *
 * @param mname The name of the menu.
 * @param mhand The menu handler name.
 */
void
LEXLIB_print_show_menu (char *mname, char *mhand)
{
  printh ("void aclfglmn_%s(char *);\n", mhand);
  printc ("A4GL_show_menu(\"%s\",aclfglmn_%s);\n", mname, mhand);
}

/**
 * Generate the C push code of the menu file definition.
 *
 * It is used for the menu extensions to informix 4gl.
 */
void
LEXLIB_print_def_mn_file (void)
{
  printc ("A4GL_push_char(\"menu\"); /* default menu file */\n");
}

/**
 * The parser found the MOVE WINDOW statement and it generate the C 
 * implementation.
 *
 * This implementation is a call to the movewin() function.
 *
 * @param n The window name.
 * @param rel
 *   - 0 : The move is abosulte in the screen.
 *   - 1 : The move is relative to the current position.
 */
void
LEXLIB_print_move_window (char *n, int rel)
{
  if (rel == 0)
    printc ("A4GL_movewin(%s,1);", n);
  else
    printc ("A4GL_movewin(%s,0);", n);
}

/* ********** MENU *********/

/**
 * The parser found the begining of the menu.
 *
 *
 * Generates the menu implementation in C.
 *
 * This function is called directly by the parser in the menu rule, when it
 * founds the MENU keyword.
 */
void
LEXLIB_print_menu_1 (int n)
{
  printc ("{void *m_%d=0;\n\nint cmd_no_%d= -1; /* n=%d */\n", n, n, n);
  printc ("MENU_START_%d: ;", n);
  printc ("while (cmd_no_%d!= -3) {\n", n);

}

void
LEXLIB_print_menu_1b (int n)
{
  /*printc (" switch(cmd_no_%d)  {\n", n);*/
}

/**
 * Print the generated C code to implement the 4gl menu statement.
 *
 * @param mn The index of the menu information in the menu stack, filled
 * by the parser.
 */
static void
print_menu (int mn, int n)
{
  int a;
  int c;
  c = 0;
  for (a = 0;
       menu_stack[mn][a].menu_title[0] != 0 ||
       menu_stack[mn][a].menu_key[0] != 0 ||
       menu_stack[mn][a].menu_help[0] != 0; a++)
    c = a;
  printc ("m_%d=(void *)A4GL_new_menu_create(%s,1,1,%d,0);\n", n, mmtitle[mn],
	  2);
  for (a = 0;
       menu_stack[mn][a].menu_title[0] != 0
       || menu_stack[mn][a].menu_key[0] != 0
       || menu_stack[mn][a].menu_help[0] != 0; a++)
    {

      printc ("A4GL_add_menu_option(m_%d, %s,%s,%s,%d,0);\n", n,
	      menu_stack[mn][a].menu_title,
	      menu_stack[mn][a].menu_key,
	      menu_stack[mn][a].menu_help, menu_stack[mn][a].menu_helpno);
    }

  printc
    ("A4GL_finish_create_menu(m_%d);\nA4GL_disp_h_menu(m_%d);cmd_no_%d= -2;continue;\n",
     n, n, n);
}


/**
 * The parser found END MENU in apropriate context.
 *
 * This function implements the C code to terminate the menu scope
 */
void
LEXLIB_print_end_menu_1 (int n)
{
  /*printc ("\n}");*/
  printcomment (" /*end switch */\n");
  printc ("if (cmd_no_%d== -1) {\n", n);
  print_menu (menu_cnt, n);
  printc ("}\n");
}

/**
 * Print the execution of the menu loop to the generated C code.
 */
void
LEXLIB_print_end_menu_2 (int n)
{
  printc ("cmd_no_%d=A4GL_menu_loop_v2(m_%d,0);\n}A4GL_free_menu(m_%d);\n", n, n,
	  n);
  printcomment ("/* end cwhile */\n");
  printcomment ("/* end menu */\n \n");
  printc ("}\n");
}

/**
 * Print in the C output file the implementation of the menu block.
 *
 * The menu blocks are implemented with a C case of a switch.
 *
 * @param n The menu block number:
 *   - -2 : BEFORE MENU.
 *   - Otherwise : The menu stack block position.
 *
 */
void
LEXLIB_print_menu_block (int menu, int n)
{
	A4GL_assertion(n==-1,"N=-1?");
  printc (" if (cmd_no_%d==%d) { \n", menu, n);
}

/**
 * Generate the C implementation to the finish of a menu block end.
 *
 * Since the menu is generated with a C switch, here it just breaks.
 * The menu blocks are:
 *   - BEFORE MENU 
 *   - COMMAND.
 */
void
LEXLIB_print_menu_block_end (int n)
{
  printc ("cmd_no_%d= -4;goto MENU_START_%d; } ", n, n);
}

/**
 * Generate the C code for the OPTION instructions of the MENU statement.
 *
 * Its executed when the parser found in the 4gl source NEXT OPTION, 
 * HIDE OPTION or SHOW OPTION.
 *
 * @todo : Understand if in the H type should call A4GL_menu_hide instead.
 *
 * @param type The type of instruction:
 *   - N : Next option.
 *   - S : Show option.
 *   - H : Hide option.
 * @param n The option name list (wich is just one if NEXT OPTION).
 */
void
LEXLIB_print_option_op (int type, char *n, int mn)
{
  if (type == 'N')
    printc ("A4GL_next_option(m_%d,%s);\n", mn, n);

  if (type == 'S')
    printc ("A4GL_menu_show(m_%d,%s,0);\n", mn, n);

  if (type == 'H')
    printc ("A4GL_menu_hide(m_%d,%s,0);\n", mn, n);
}

/**
 * The parser found the AT TERMINATION CALL statement.
 *
 * This is not implemented yet and its an extension to Informix 4gl.
 *
 * @param f The function name.
 */
void
LEXLIB_print_at_termination (char *f)
{
  print_niy ("AT TERMINATION");
}

/**
 * If defined (as compiler option) print the C code for the call to the
 * initialization function to the calling stack.
 */
void
LEXLIB_printInitFunctionStack (void)
{
  if (!isGenStackInfo ())
    return;
  if (!A4GL_doing_pcode ())
    printc ("A4GLSTK_initFunctionCallStack();");
}

/**
 * If defined (as compiler option) print the C code for the call to the
 * declaration function to the calling stack.
 */
void
LEXLIB_printDeclareFunctionStack (char *_functionName)
{
#ifdef FGL_PLUS_PLUS
  extern int class_cnt;
#endif
#ifdef DEBUG
  A4GL_debug ("Function %s\n", _functionName);
#endif

#ifdef FGL_PLUS_PLUS

  if (class_cnt) {
	LEXLIB_CLASS_add_method(_functionName,"");
  }
#endif
  if (isGenStackInfo ())
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
LEXLIB_printPushFunction (void)
{
  if (!isGenStackInfo ())
    return;
  printc ("A4GLSTK_setCurrentLine(_module_name,%d);", yylineno);
  printc ("A4GLSTK_pushFunction(_functionName,_paramnames,_nargs);\n");
}

/**
 * Print the C C code to the call to the pop function of the calling stack.
 *
 * It only does it if defined as compiler option.
 */
void
LEXLIB_printPopFunction (void)
{
  if (!isGenStackInfo ())
    return;
  printc ("A4GLSTK_popFunction();\n");
}


/**
 * The parser found the FUNCTION keyword folowed by is name and the 
 * open bracket.
 *
 * It will generate the C code function that implements the 4gl function.
 *
 * The function name in C is mangled with aclfgl_ or aclfglm_ in the begining.
 *
 * @param isstatic "static" id the function is a LOCAL FUNCTION 
 *   (not informix 4gl syntax)
 * @param fname The 4gl function name
 * @param type The type of the function:
 *   - 0 : Normal 4gl function
 *   - 1 : Is a member function
 */
void
LEXLIB_print_func_start (char *isstatic, char *fname, int type)
{
extern int class_cnt;

  printc (" \n");
  printc (" \n");
  printc (" \n");

  if (type == 0) {
	if (class_cnt==0) {
    		printc ("\n A4GL_FUNCTION %sint %s%s (int _nargs){ \n", isstatic, get_namespace (fname), fname);
		add_function_to_header(fname,1,isstatic);

	} else {
    		printc ("\n A4GL_FUNCTION %sint CLASSFUNC_%s%s (struct this_class_var *CLASS_COPY,int _nargs){ \n", isstatic, get_namespace (fname), fname);
		add_class_function_to_header(fname,1,isstatic);

	}
  }


  if (type == 1) {
    printc ("\n A4GL_REPORT %sint %s%s (int _nargs){ \n", isstatic, get_namespace (fname), fname);
	add_function_to_header(fname,2,isstatic);
  }
}

/**
 * The parser found the parameter declaration inside () and it generates
 * the implementation C code.
 *
 * @param c The number of parameters from the 4gl function
 */
void
LEXLIB_print_func_args (int c)
{

// cc 2005.01.25 return 0 changed to -1 to catch wrong parameter size
  printc
    ("if (_nargs!=%d) {A4GLSQL_set_status(-3002,0);A4GL_pop_args(_nargs);A4GLSTK_popFunction();return -1;}\n",
     c, yylineno);
  print_function_variable_init ();
  printc ("A4GL_pop_params(fbind,%d);\n", c);

}


/**
 * The parser found the END of a FUNCTION and it generates the return in
 * the C generated code.
 */
void
LEXLIB_print_func_defret0 (void)
{
  printc ("return 0;\n");
}

/**
 * The parser found the END FUNCTION and it closes the C function generated.
 */
void
LEXLIB_print_func_end (void)
{
  printc ("}");
	printcomment("/* END OF FUNCTION */\n\n\n\n");
}

/**
 * The parser found the MAIN keyword and now it will generate the begining 
 * of C main function in the generated file.
 */
void
LEXLIB_print_main_1 (void)
{
  if (doing_cs ())
    {
      printc ("\n\npublic static void Main(string argv[]) {\n");
      printc ("string[] _paramnames=new string[1]; _paramnames[0]={\"\"};");
      printc ("int _nargs=0;");
      return;
    }
  if (A4GL_doing_pcode ())
    {
      printc ("\n\nA4GL_MAIN int main(int _nargs) {\n");
      printc ("char *_paramnames[1]={\"\"};");
      return;
    }


  printc ("\n\nA4GL_MAIN int main(int argc,char *argv[]) {\n");
  printc ("char *_paramnames[1]={\"\"};");
  printc ("int _nargs=0;");
}

/**
 * The parser found the MAIN and the local variable definition and
 * it will generate the C code that initializes the fgl at run time.
 *
 * @param db The header database name (DATABASE statement outside functions).
 */
void
LEXLIB_print_fgllib_start (char *db)
{
  extern int is_schema;
  printc ("A4GLSTK_setCurrentLine(0,0);", yylineno);
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

  if (db[0] != 0)
    {
      if (!is_schema)
	{
	  print_init_conn (db);
	  printc
	    ("if (a4gl_sqlca.sqlcode<0) A4GL_chk_err(%d,_module_name);\n",
	     lastlineno);
	}
      else
	{
	  printc ("/* NO DATABASE - SCHEMA ONLY */");
	}
    }
  print_function_variable_init ();
}

/**
 * The parser found the END MAIN and it will generate the implementation to 
 * the output C file.
 *
 * Prints the call to the fgl_end() function.
 */
void
LEXLIB_print_main_end (void)
{
  if (doing_esql ())
    {
      printc ("if (A4GL_esql_db_open(-1,0,0,\"\")) {");
      print_close ('D', "");
      printc ("}");
    }
  printc ("A4GL_fgl_end_4gl_0();");
  printc ("return 0;}\n");
}

/**
 * The parser found a RETURN 4gl statement and now it will generate the C
 * implementation to the generated output file.
 *
 * This function is called when the parser founds the complete return
 * instruction.
 *
 * The values or variables contents returned are done using the stack mechanism.
 *
 * @param n : The number of returning values.
 */
void
LEXLIB_print_return (int n)
{
int z;
char *s;
  
  for (z=ccnt;z>=0;z--) {
	s=command_type_for_stack_pos(z);
    	if (strcmp(s,"INPUT")==0)  { printc("A4GL_finish_screenio(_sio_%d,_sio_kw_%d);",get_sio_id(s),get_sio_id(s)); }
    	if (strcmp(s,"CONSTRUCT")==0)  { printc("A4GL_finish_screenio(_sio_%d,_sio_kw_%d);",get_sio_id(s),get_sio_id(s)); }
    	if (strcmp(s,"DISPLAY")==0)  { printc("A4GL_finish_screenio(_sio_%d,_sio_kw_%d);",get_sio_id(s),get_sio_id(s)); }
    	if (strcmp(s,"PROMPT")==0)  { printc("A4GL_finish_screenio(_sio_%d,_sio_kw_%d);",get_sio_id(s),get_sio_id(s)); }
    	//if (strcmp(s,"MENU")==0)  { printc("A4GL_finish_screenio(_m,\"MENU\");",get_sio_id(s),get_sio_id(s)); }
  }

  if (!isin_command ("REPORT"))
    printc ("return %d;", n);
  else
    printc ("return ;");
}

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
void
LEXLIB_print_options (char n, char *s)
{
  printc ("A4GL_set_option_value('%c',%s);\n", n, s);
}

/**
 * Print in the C generated code the change of the help file.
 *
 * Called by the parser when it founds the OPTIONS HELP FILE statement.
 *
 * @param s The help file name.
 */
void
LEXLIB_print_set_helpfile (char *s)
{
  printc ("A4GL_set_help_file(%s);\n", s);
}

/**
 * Print in the C generated code the change of the language file.
 *
 * Called by the parser when it founds the OPTIONS LANGUAGE FILE statement.
 *
 * @param s The help file name.
 */
void
LEXLIB_print_set_langfile (char *s)
{
  printc ("A4GL_set_lang_file(%s);\n", s);
}


/**
 * Print in the first part of the fecth implementation to generated C output
 * file.
 *
 * Executed by the parser imediatly after found the keyword FETCH.
 */
void
LEXLIB_print_fetch_1 (void)
{
  printc ("{");
}

/**
 * Executed by the parser when it founds the cursor name and the type of
 * the fetch.
 *
 * Prints a new part in the output C file.
 */
void
LEXLIB_print_fetch_2 (void)
{
  printc ("{");
  print_bind_definition('o');
  print_bind_set_value('o');
}









/**
 * Print the implementation in C code to 4gl statement NEXT FORM FIELD.
 *
 * This statement is not yet implemented.
 *
 * This statement is not part of original informix 4gl.
 *
 * @param form The form name
 * @param field The field name
 */
void
LEXLIB_print_next_form_field (char *form, char *field)
{
  print_niy ("NEXT FORM FIELD");
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
LEXLIB_print_declare_associate_1 (char *variable, char *size, char *n)
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
LEXLIB_print_declare_associate_2 (char *variable, char *size, char *n)
{
  printc
    ("#define ASSOCIATE_%s(w) %s[A4GL_ass_hash(_usg%s,%s,%s+1,w,sizeof(_usg%s))]\n",
     upshift (variable), downshift (variable),
     downshift (variable), n, size, downshift (variable));
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
void
LEXLIB_print_define_char (char *var, int size, int isstatic_extern)
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
void
LEXLIB_print_define (char *varstring, int isstatic_extern)
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
void
LEXLIB_print_start_record (int isstatic_extern, char *varname, char *arrsize,
		    int level)
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
      if (strcmp (varname, "a4gl_sqlca") == 0)
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
void
LEXLIB_print_end_record (char *vname, char *arrsize, int level)
{
  int cnt;
  int arrsizes[10];
  if (strcmp (arrsize, "-1") == 0)
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
	  cnt = split_arrsizes (arrsize, (int *) &arrsizes);
	  if (arrsizes[0] >= 0)
	    {
	      printc ("} %s[%s]; /*1 */\n", vname, arrsize);
	    }
	  else
	    {
	      printc ("} *%s;\n", vname);
	    }
	}
    }
}

/**
 * Print the push of a literal to the stack in generated C code.
 *
 * @param type The type of the literal found:
 *   - D : Double value
 *   - L : Integer value
 *   - S : Char/String value
 * @param value The value of the literal
 */
char *
/* char */
LEXLIB_A4GL_get_push_literal (char type, char *value)
{
  static char buff[80];
  strcpy (buff, "SOME ERROR");
  if (type == 'D')		/* Double */
    {
	//printf("-->%s\n",value);
        sprintf (buff, "A4GL_push_double_str(\"%s\");\n", value);
	//printf("=%s\n",buff);
	
    }

  if (type == 'L')		/* Integer (Long) */
    {
      sprintf (buff, "A4GL_push_long(%d);\n", atoi (value));
    }

  if (type == 'S')		/* Char/String */
    {
      sprintf (buff, "A4GL_push_char(%s);\n", value);
    }

  if (type == 'N')		/* Empty ("") Char/String */
    {
      sprintf (buff, "A4GL_push_empty_char();");
    }

  /* FIXME: and if it's not D, L or S? */

  return buff;
}

/**
 * FIXME: what is this?
 *
 * @param s
 */
char *
LEXLIB_A4GL_decode_array_string (char *s)
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
void
LEXLIB_print_cmd_start ()
{
  printc ("\n\naclfgli_clr_err_flg();\n\n");
}

/**
 *
 * @todo Describe function
 */
void
LEXLIB_print_cmd_end ()
{
  /*printc("\naclfgli_clr_err_flg()\n\n");*/
  printcomment ("\n/* End command */\n");
}

/**
 *
 * @todo Describe function
 */
char *
LEXLIB_A4GL_get_into_part (int doing_declare, int no)
{
  static char buffer[10000];
  int a;
  if (doing_esql ())
    {
      char buff[30];


      if (no == 0)
	return "";

      sprintf (buffer, "INTO \n");
      for (a = 0; a < no; a++)
	{
	  if (! A4GLSQLCV_check_requirement ("USE_INDICATOR"))
	    {
	      sprintf (buff, "\t:_vo_%d\n", a);
	    }
	  else
	    {
	      sprintf (buff, "\t:_vo_%d INDICATOR :_voi_%d\n", a, a);
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
LEXLIB_A4GL_set_var_sql (int doing_declare, int n)
{
  int a;
  static char buff[8000];
  extern char *current_upd_table;
#define UPDVAL2 4

  if (doing_esql ())
    {
      int z;
      z = get_bind_cnt ('i');
      strcpy (buff, "");
      for (a = z - n; a < z; a++)
	{
	  char buff_small[20];
	  if (a != z - n)
	    {
	      strcat (buff, ",");
	    }

      if (A4GLSQLCV_check_requirement ("USE_INDICATOR")) {
	  sprintf (buff_small, " :_vi_%d INDICATOR :_vii_%d \n", a,a);
	} else {
	  sprintf (buff_small, " :_vi_%d\n", a);
	}

	  strcat (buff, buff_small);

	  if (current_upd_table)
	    {
	      push_gen (UPDVAL2, buff_small);
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
	      push_gen (UPDVAL2, "?");
	    }
	  strcat (buff, "?");
	}
      return buff;
    }
}


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


/**
 *
 * @todo Describe function
 */
int
esql_type ()
{

  if (strcmp (acl_getenv ("A4GL_LEXDIALECT"), "INFORMIX") == 0)
    {
      return 1;
    }

  if (strcmp (acl_getenv ("A4GL_LEXDIALECT"), "POSTGRES") == 0)
    {
      return 2;
    }

  if (strcmp (acl_getenv ("A4GL_LEXDIALECT"), "SAPDB") == 0)
    {
      return 3;
    }

  if (strcmp (acl_getenv ("A4GL_LEXDIALECT"), "INGRES") == 0)
    {
      return 4;
    }

  return 1;			/* Assume informix*/
}

/**
 *
 * @todo Describe function
 */
void
LEXLIB_A4GL_lex_parsed_fgl ()
{
  if (strcmp (acl_getenv ("LEXTYPE"), "CS") == 0)
    {
      printc ("#include \"cs_trailer.h\"");
    }

  if (outfile)
    fclose (outfile);
  if (hfile)
    fclose (hfile);
}

void
LEXLIB_print_import_legacy (char *s)
{
  printc ("\n");
  printc ("\n");
  printc ("\n\nA4GL_FUNCTION int %s%s(int n) {\nreturn %s(n);\n}\n",
	  get_namespace (s), s, s);
  printc ("\n");
  printc ("\n");
}


void
add_function_to_header (char *identifier, int params,char* is_static)
{

  if (is_builtin_func (identifier))
    return;


  if (!A4GL_has_pointer (identifier, 'X'))
    {
      A4GL_add_pointer (identifier, 'X', (void *) 1);
      if (params == 1)		/* Normal Function*/
	printh ("A4GL_FUNCTION %s int %s%s (int n);\n",is_static,
		get_namespace (identifier), identifier);
      if (params == 2)		/* Report...*/
	printh ("A4GL_REPORT void %s%s (int n,int a);\n",
		get_namespace (identifier), identifier);
    }


}


void
add_class_function_to_header (char *identifier, int params,char* is_static)
{

char buff[255];
sprintf(buff,"CLASSFUNC_%s",identifier);
identifier=buff;
  if (is_builtin_func (identifier))
    return;


  if (!A4GL_has_pointer (identifier, 'X'))
    {
      A4GL_add_pointer (identifier, 'X', (void *) 1);
      if (params == 1)		/* Normal Function*/
	printh ("A4GL_FUNCTION %s int %s%s (int n);\n",is_static,
		get_namespace (identifier), identifier);
      if (params == 2)		/* Report...*/
	printh ("A4GL_REPORT void %s%s (int n,int a);\n",
		get_namespace (identifier), identifier);
    }


}

char *
LEXLIB_A4GL_expr_for_call (char *ident, char *params, int line, char *file)
{
  static char buff[2048];
  char lib[255];

  if (A4GL_doing_pcode ())
    {
      sprintf (buff, "ECALL(\"%s%s\",%d,%s);", get_namespace (ident), ident,
	       line, params);
    }
  else
    {

	if (has_function(ident,lib,0)) {
		// Call shared...
  	sprintf(buff, "{int _retvars; A4GLSQL_set_status(0,0);_retvars=A4GL_call_4gl_dll(%s,\"%s\",%s); if (_retvars!= 1 && a4gl_status==0 ) {A4GLSQL_set_status(-3001,0);A4GL_chk_err(%d,_module_name);}\n%s}",  lib, ident, params,line,get_reset_state_after_call());

	} else {
      		sprintf (buff, "{int _retvars;\n_retvars=%s%s(%s); {\nif (_retvars!= 1 && a4gl_status==0 ) {A4GLSQL_set_status(-3001,0);A4GL_chk_err(%d,_module_name);}\n}\n%s}\n",
	       get_namespace (ident), ident, params, line, get_reset_state_after_call());
	}
    }
  add_function_to_header (ident, 1,"");
  return buff;
}


void
LEXLIB_print_foreach_close (char *cname)
{
  print_close ('C', cname);
}


int
A4GL_doing_pcode (void)
{
  if (strcmp (acl_getenv ("LEXTYPE"), "PCODE") == 0)
    return 1;
  if (strcmp (acl_getenv ("FAKELEXTYPE"), "PCODE") == 0)
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
LEXLIB_print_empty_bind (char *name)
{
  printc ("static struct BINDING *%s=0;\n", name);
}


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

static void
order_by_report_stack ()
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
      printc ("acl_rep_ordcnt=%d;", ordbyfieldscnt);
      /* And assign the values*/
      fiddle++;
      printc ("acl_exchange_rep_ordby%d(_ordbind,%d);", fiddle,
	      current_ordbindcnt);
/* H file... */
      printh
	("static void acl_exchange_rep_ordby%d(struct BINDING *ord,int cnt) {\n",
	 fiddle);
      printh ("struct BINDING *copy;\n");
      printh ("copy=(struct BINDING *)malloc(sizeof(struct BINDING)*cnt);\n");
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

void
LEXLIB_print_execute_immediate (char *stmt)
{
  static int cnt = 0;
  char buff[256];
  if (A4GLSQLCV_check_requirement ("FAKE_IMMEDIATE") || !doing_esql ())
    {
      sprintf (buff, "\"p_%d_%lx\"", cnt++, time (0));
      print_prepare (buff, stmt);
      print_execute (buff, 0);
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
LEXLIB_print_alloc_arr (char *s, char *d)
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
  /*printc ("%s=malloc(%d * sizeof(%s[0]));", s, l, s);*/
}



void
LEXLIB_print_realloc_arr (char *s, char *d)
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

void
LEXLIB_print_dealloc_arr (char *s)
{
  printc ("A4GL_dynarr_free(&%s,%s);", s,s);
}

struct expr_str *A4GL_add_validation_elements_to_expr(struct expr_str *ptr,char *val) {
char *ptr2;
char *ptrn;
char buff[256];
A4GL_trim(val);
ptr2=val;
while (1) {
        ptrn=strtok(ptr2,",");
        if (ptrn==0) break;
        if (ptr2) {ptr2=0;}

        sprintf(buff,"A4GL_push_char(\"%s\");",ptrn);

        if (ptr==0) {
                ptr=A4GL_new_expr(buff);
        } else {
                A4GL_append_expr(ptr,buff);
        }

}
return ptr;
}


void print_event_list () {
int a;
int n;
int b;
int event_id;
char *event_dets;
int *keys;
//char comma=' ';
char **fields;

n=A4GL_get_nevents();
if (n==0) {
	if (A4GL_doing_pcode()) {
		printc("struct aclfgl_event_list _sio_evt[1]={");
	} else {
		printc("static struct aclfgl_event_list _sio_evt[]={");
	}
	printc(" {0}};");
	return ;
}

if (A4GL_doing_pcode()) {
	printc("struct aclfgl_event_list _sio_evt[%d]={",n);
} else {
	printc("static struct aclfgl_event_list _sio_evt[]={");
}
for (a=0;a<n;a++) {
	A4GL_get_event(a,&event_id,&event_dets);
	if (event_id==-90) {
		keys=get_key_codes(event_dets);
		for (b=0;keys[b];b++) {
			printc("{%d,%d,%d,0},",event_id,a+1,keys[b]);
		}
	} else {
		fields=get_field_codes(event_dets);
		for (b=0;fields[b];b++) {
			if (strlen(fields[b])!=0) {
				printc("{%d,%d,0,%s},",event_id,a+1,fields[b]);
			} else {
				printc("{%d,%d,0,\"\"},",event_id,a+1);
			}
		}
	}
}
	printc("{0}");
	printc("};");
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

  if (strcmp (keys, "->ANY") == 0) { x=malloc(sizeof(int)*2); x[0]=0xffff; x[1]=0; return x;}

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
	x=realloc(x,sizeof(int)*xcnt);
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
int
LEXLIB_print_bind_definition (char i)
{
  int a;
#ifdef DEBUG
  A4GL_debug ("/* %c */\n", i);
#endif
  if (i == 'i')
    {
      printc ("\n");
      printc ("struct BINDING ibind[%d]={\n ", ONE_NOT_ZERO (ibindcnt), ibindcnt);
      if (ibindcnt == 0)
	{
	  printc ("{0,0,0}");
	}
      for (a = 0; a < ibindcnt; a++)
	{
	  //if (a > 0) printc (",\n");
	  printc ("{0,%d,%d,%d,%d}%c", 
		  (int) ibind[a].dtype & 0xffff, (int) ibind[a].dtype >> 16,
		  ibind[a].start_char_subscript, ibind[a].end_char_subscript,(a<ibindcnt-1)?',':' ');
	}
      printc ("\n}; \n");
      if (doing_esql ())
	{
	  make_sql_bind (0, "i");
	}
      return a;
    }

  if (i == 'o')
    {
      printc ("\n");
      printc ("struct BINDING obind[%d]={\n", ONE_NOT_ZERO (obindcnt));
      if (obindcnt == 0)
	{
	  printc ("{0,0,0}");
	}

      for (a = 0; a < obindcnt; a++)
	{
	  printc ("{0,%d,%d,%d,%d}%c", 
		  (int) obind[a].dtype & 0xffff, (int) obind[a].dtype >> 16,
		  obind[a].start_char_subscript, obind[a].end_char_subscript, (a<obindcnt-1)?',':' '
);
	}
      printc ("\n}; /* end of binding */\n");
      if (doing_esql ())
	{
	  make_sql_bind (0, "o");
	}
      return a;
    }
  if (i == 'O')
    {
      printc ("\n");
      
      expand_bind (&ordbind[0], 'O', ordbindcnt);
      printc ("static struct BINDING _ordbind[%d]={\n", ONE_NOT_ZERO (ordbindcnt));
      if (ordbindcnt == 0)
	{
	  printc ("{0,0,0}");
	}

      for (a = 0; a < ordbindcnt; a++)
	{
	  printc ("{0,%d,%d,%d,%d}%c", 
		  (int) ordbind[a].dtype & 0xffff, (int) ordbind[a].dtype >> 16,
		  ordbind[a].start_char_subscript, ordbind[a].end_char_subscript, (a<ordbindcnt-1)?',':' '
);
	}
      printc ("\n}; /* end of binding */\n");
      current_ordbindcnt = ordbindcnt;
      if (doing_esql ())
	{
	  make_sql_bind (0, "O");
	}
      return a;
    }

  if (i == 'N')
    {
      expand_bind (&nullbind[0], 'N', nullbindcnt);
      printc ("\n");
      printc ("struct BINDING nullbind[%d]={\n /* nullbind %d*/",
              ONE_NOT_ZERO (nullbindcnt), nullbindcnt);
      if (nullbindcnt == 0)
        {
          printc ("{0,0,0}");
        }
      for (a = 0; a < nullbindcnt; a++)
        {
          if (a > 0)
            printc (",\n");
          chk_init_var (nullbind[a].varname);
          printc ("{0,%d,%d}", 
                  (int) nullbind[a].dtype & 0xffff,
                  (int) nullbind[a].dtype >> 16);
        }
      printc ("\n}; /* end of binding */\n");
      return a;
    }

    printf("UNEXPECTED BINDING %c\n",i);
    exit(3);

  return 0;
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
int
LEXLIB_print_bind_set_value (char i)
{
  int a;
#ifdef DEBUG
  A4GL_debug ("/* %c */\n", i);
#endif
  if (i == 'i')
    {
      for (a = 0; a < ibindcnt; a++)
	{
	  printc ("ibind[%d].ptr= &%s;", a,ibind[a].varname);
	}
      start_bind (i, 0);
      return a;
    }


  if (i == 'o')
    {
      for (a = 0; a < obindcnt; a++)
	{
	  printc ("obind[%d].ptr= &%s;", a,obind[a].varname);
	}
      start_bind (i, 0);
      return a;
    }
  if (i == 'O')
    {
      for (a = 0; a < current_ordbindcnt; a++)
	{
	  printc ("_ordbind[%d].ptr=&%s;", a,ordbind[a].varname);
	}
      start_bind (i, 0);
      return a;
    }

  if (i == 'N')
    {
      for (a = 0; a < nullbindcnt; a++)
        {
	  printc ("nullbind[%d].ptr=&%s;", a,nullbind[a].varname);
        }
      start_bind (i, 0);
      return a;
    }
  return 0;
}




char* get_reset_state_after_call(void ) {
   if (isin_command ("INPUT")  || isin_command ("CONSTRUCT")) {
       int sio_id;
       static char buff[255];
               sio_id=get_sio_id("ALLINPUT");
               sprintf(buff, "A4GL_reset_state_for(_sio_%d,_sio_kw_%d);",sio_id,sio_id);
               return buff;
   }
   return "";
}


void print_reset_state_after_call(void) {
       printc("%s",get_reset_state_after_call());
}


void LEXLIB_print_convert_report(char *repname, char* fname,char *otype, char *layout,char *file_or_pipe) {

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

void LEXLIB_print_free_convertable(char *repname) {
	printc("%s%s(3,REPORT_FREE);", get_namespace (repname),repname);
}


/* =========================== EOF ================================ */
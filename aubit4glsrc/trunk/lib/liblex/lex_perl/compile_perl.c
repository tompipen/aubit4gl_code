/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-1 Aubit Development Team (See Credits file)       |
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
# $Id: compile_perl.c,v 1.18 2002-08-13 11:56:48 afalout Exp $
#
*/

/**
 * @file
 * Generate .pl modules from 4GL source code
 *
 * VERY EARLY STAGES OF DEVELOPMENT!
 *
 *
 */

/*
=====================================================================








                WHEN EDITING THIS FILE, PLEASE REMEMBER TO DO
                THE SAME CHANGES TO EQUIVALENT FILE(s) IN OTHER
                LANGUAGE OUTPUT TARGETS, LIKE:

                    compile_c.c
                    compile_c_gtk.c
                    compile_perl.c
                    ...etc...












=====================================================================
*/



/*
=====================================================================
		                    Includes
=====================================================================
*/





#ifdef OLD_INCL

	#include <stdio.h>
	#include "a4gl_dbform.h"
	#include "a4gl_report.h"
	#include "a4gl_oform.h"
	#include "a4gl_attributes.h"
	#include "a4gl_errors.h"
	#include "a4gl_constats.h"
	#include "a4gl_prompt.h"
	#include "a4gl_aubit_lib.h"
	#include "../lex_c/a4gl_lex_print_protos_c.h"
	#include "a4gl_4glc_4glc.h"
	#include "a4gl_debug.h"

#else

    #include "a4gl_lib_lex_perl_int.h"

#endif

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

FILE *outfile = 0;
FILE *hfile = 0;
extern char *outputfilename;
extern char *curr_func;
extern char *infilename;
extern int yylineno;
extern int lastlineno;
extern int inp_flags;
extern struct rep_structure rep_struct;
extern struct pdf_rep_structure pdf_rep_struct;
extern struct form_attr form_attrib;
extern int menu_cnt;
extern int ccnt;				/* Block counter */
extern char mmtitle[132][132];

extern struct s_menu_stack menu_stack[MAXMENU][MAXMENUOPTS];
extern struct s_report_stack report_stack[REPORTSTACKSIZE];
extern int report_stack_cnt;
extern int report_cnt;
extern int rep_type;
extern int when_code[8];

extern struct s_report sreports[1024];
extern int sreports_cnt;
extern char when_to_tmp[64];

extern char when_to[64][8];

extern struct binding_comp ibind[NUMBINDINGS];
extern struct binding_comp nullbind[NUMBINDINGS];
extern struct binding_comp obind[NUMBINDINGS];
extern struct binding_comp fbind[NUMBINDINGS];
extern struct binding_comp ordbind[NUMBINDINGS];

extern int ordbindcnt;

extern int ibindcnt;
extern int nullbindcnt;
extern int obindcnt;

extern int fbindcnt;

extern struct s_constr_buff constr_buff[256];
extern int constr_cnt;
char unwind[256][256];
int unwindcnt = 0;
int printing_record = 0;

char lname[256];


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

static void print_space (void);
void open_outfile (void);


static void print_output_rep (struct rep_structure *rep);
static void print_form_attrib (struct form_attr *form_attrib);
static int print_field_bind (int ccc);
static int print_arr_bind (char i);
static int print_constr (void);
static int print_field_bind_constr (void);
static int pr_when_do (char *when_str, int when_code, int l, char *f, char *when_to);
static void pr_report_agg (void);
static void pr_report_agg_clr (void);
static void print_menu (int mn);


/* static void real_lex_printc(char *fmt, va_list *ap); */

void printh (char *fmt, ...);
static void printcomment (char *fmt,...);
void dump_unwind(void);


void internal_lex_printc(char *fmt, va_list *ap);
void internal_lex_printcomment(char *fmt, va_list *ap);
void internal_lex_printh(char *fmt, va_list *ap);

static void real_print_expr (struct expr_str *ptr);
static void real_print_func_call (char *identifier, struct expr_str *args, int args_cnt);
static void real_print_pdf_call (char *a1, struct expr_str *args, char *a3);



/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/* this one is used only form this file */
static void
printc(char* fmt,... )
{
va_list ap;
	debug("via printc in lib");
	va_start(ap,fmt);
	/* real_lex_printc(fmt,&ap); */
	internal_lex_printc(fmt,&ap);
}

/* this oen gets called freom API */
/*
void
internal_lex_printc(char* fmt,... )
{
va_list ap;
	debug("via lex_printc (2) in lib");
	va_start(ap,fmt);
	real_lex_printc(fmt,&ap);
        debug("Done....");
}
*/


/**
 *
 * @param
 * @return
 */
/*
static void
real_lex_printc(char *fmt, va_list *ap)
*/
void
internal_lex_printc (char *fmt, va_list *ap)
/*
void
printc (char *fmt, ...)
*/
{
/*  va_list args; */
char buff[40960];
char *ptr;
int a;
char buff2[40960];

	if (outfile == 0)
    {
      open_outfile ();
    }

	if (outfile == 0)
	    return;
	
	/* va_start (args, fmt); */
	vsprintf (buff, fmt, *ap);

	debug("buff in lib=%s\n",buff);
	strcpy(buff2,fmt);
	debug("fmt in lib=%s\n",buff2);


	if (acl_getenv ("INCLINES"))
    {
    	/* vsprintf (buff, fmt, args); */
        for (a = 0; a < strlen (buff); a++)
		{
			if (buff[a] == '\n')
			{
				if (infilename != 0)
                {
					fprintf(outfile,"\n");
					//fprintf (outfile, "\n#line %d \"%s.4gl\"\n", yylineno,
					//outputfilename);
                }
				else
                {
					fprintf(outfile,"\n");
					//fprintf (outfile, "\n#line %d \"null\"\n", yylineno);
					/*  outputfilename); */
                }
			}
			else
			{
				fprintf (outfile, "%c", buff[a]);
				fflush (outfile);
			}
        }
	}
	else
    {
		/* vsprintf (buff, fmt, args); */
		ptr = strtok (buff, "\n");

		while (ptr)
        {
			print_space ();
			fprintf (outfile, "%s\n", ptr);
			ptr = strtok (0, "\n");
        }
	}
}

/**
 *
 * @param
 * @return
 */
static void
print_space (void)
{
  char buff[256];
  memset (buff, ' ', 255);
  buff[ccnt * 3] = 0;
  fprintf (outfile, "%s", buff);
}

/**
 *
 * @param
 * @return
 */
void
printh (char *fmt, ...)
{
  va_list args;
  if (outfile == 0)
    {
      open_outfile ();
    }
  if (outfile == 0)
    return;

  va_start (args, fmt);
  vfprintf (hfile, fmt, args);
}

/**
 *
 * @param
 * @return
 */
void
open_outfile (void)
{
  char h[132];
  char c[132];
  char err[132];
  char *ptr;
  if (outputfilename == 0)
    {
      debug ("NO output file name");
    }

  strcpy (c, outputfilename);
  strcpy (h, outputfilename);
  strcpy (err, outputfilename);

  if (strcmp (acl_getenv ("NOCLOBBER"), "N") == 0)
    {
      debug ("Clobbering...");
      set_clobber (outputfilename);
    }

  debug ("Opening output map");

  openmap (outputfilename);

  ptr = acl_getenv ("NOCFILE");
  if (strlen (ptr))
    {
      if (ptr[0] == 'Y' || ptr[0] == 'y')
	{
	  debug (">>> NO C FILES... %s", ptr);
	  return;
	}
    }

  strcat (c, ".pl");
  strcat (h, ".pm");
  strcat (err, ".err");
  outfile = mja_fopen (c, "w");
  if (outfile == 0)
    {
      printf ("Unable to open file %s (Check permissions)\n", c);
      exit (3);
    }

  fprintf (outfile, "#!/usr/bin/perl\n");
  fprintf (outfile, "require aubit4gl;\n");
  fprintf(outfile,"package aubit4gl_pl;\n");
  if (strcmp(acl_getenv ("AUBITGUI"),"GTK")==0)
     fprintf (outfile, "require aubit4gl_gtk\n"); 
/*  fprintf (outfile, "$aubit_compiler_ser=\"%s\";\n", get_serno ()); */
  fprintf (outfile, "$aubit_module_name=\"%s.4gl\";\n", outputfilename);
  hfile = mja_fopen (h, "w");
}


/**
 *
 * @param
 * @return
 */
void
incprint (void)
{

  int a;

  for (a = 0; a <= getinc (); a++)
    {

      printc ("   ");

    }
}

/**
 *
 * @param
 * @return
 */
void
print_repctrl_block (void)
{
  printc ("rep_ctrl%d_%d:\n", report_cnt, report_stack_cnt);
}


/**
 *
 * @param
 * @return
 */
void
print_report_ctrl (void)
{
  int a;
  debug
    ("/* ********************************************************** */\n");
  debug
    ("/*                 Report Control Block                       */\n");
  debug
    ("/* ********************************************************** */\n");
  printc ("report%d_ctrl:\n", report_cnt);
  //printc ("debug(\"ctrl=%%d nargs=%%d\",acl_ctrl,nargs);\n");
/*
   printc("    if (acl_ctrl==REPORT_START) goto start_%d;\n",report_cnt);
   printc("    if (acl_ctrl==REPORT_FINISH) goto finish_%d;\n",report_cnt);
 */
  printc ("    if (acl_ctrl==REPORT_OPS_COMPLETE) return;\n\n");
  printc ("    if (acl_ctrl==REPORT_SENDDATA) {\n");
  printc ("   /* check for after group of */\n");
  printc ("       %s(0,REPORT_DATA);\n", get_curr_rep_name ());
  printc ("   /* check for before group of */\n");
  printc ("    }\n\n");

  /*if (report_stack[a].whytype=='F') printc("if (acl_ctrl==REPORT_FINISH) call %s(0,REPORT_LASTROW)\n", report_cnt,a); */

  printc ("if (acl_ctrl==REPORT_FINISH) {%s(0,REPORT_LASTDATA);return;}\n",
	  get_curr_rep_name ());
  if (rep_type == REP_TYPE_NORMAL)
    {
      printc
	("if (acl_ctrl==REPORT_LASTDATA) {%s(0,REPORT_LASTROW);_started=0;fclose(rep.output);return;}\n",
	 get_curr_rep_name ());
    }
  else
    {
      printc
	("if (acl_ctrl==REPORT_LASTDATA) {%s(0,REPORT_LASTROW);_started=0;pdf_rep_close(&rep);return;}\n",
	 get_curr_rep_name ());

    }
  printc ("    if (acl_ctrl==REPORT_AFTERDATA ) {\n");
  pr_report_agg ();
  printc ("    }\n");

  for (a = 0; a < report_stack_cnt; a++)
    {
/* on last row */
      if (report_stack[a].whytype == 'L')
	printc
	  ("if (acl_ctrl==REPORT_LASTROW) { acl_ctrl=0;goto rep_ctrl%d_%d;}\n",
	   report_cnt, a);

/* on every row */
      if (report_stack[a].whytype == 'E')
	printc
	  ("if (acl_ctrl==REPORT_DATA) {acl_ctrl=REPORT_AFTERDATA;goto rep_ctrl%d_%d;}\n",
	   report_cnt, a);

/* before group of */
      if (report_stack[a].whytype == 'B')
	printc
	  ("if (acl_ctrl==REPORT_BEFOREGROUP && nargs==%s) {nargs=-1*nargs;goto rep_ctrl%d_%d;}\n",
	   report_stack[a].why, report_cnt, a);

/* after group of */
      if (report_stack[a].whytype == 'A')
	printc
	  ("if (acl_ctrl==REPORT_AFTERGROUP && nargs==%s) {nargs=-1*nargs;goto rep_ctrl%d_%d;}\n",
	   report_stack[a].why, report_cnt, a);

      if (report_stack[a].whytype == 'T')
	printc
	  ("if (acl_ctrl==REPORT_PAGETRAILER) {acl_ctrl=REPORT_PAGEHEADER;goto rep_ctrl%d_%d;}\n",
	   report_cnt, a);

      if (report_stack[a].whytype == 'P')
	printc
	  ("if (acl_ctrl==REPORT_PAGEHEADER && rep.page_no==1) {acl_ctrl=0;goto rep_ctrl%d_%d;}\n",
	   report_cnt, a);

      if (report_stack[a].whytype == 'p')
	printc
	  ("if (acl_ctrl==REPORT_PAGEHEADER && (rep.page_no!=1||(rep.page_no==1 && rep.has_first_page==0))) {acl_ctrl=0;goto rep_ctrl%d_%d;}\n",
	   report_cnt, a);
    }
  pr_report_agg_clr ();
}




/**
 *
 * @param
 * @return
 */
void
print_range_check (char *var, char *size)
{
  printc ("range_chk(%s,%d);\n", var, atoi (size));
}

/**
 *
 * @param
 * @return
 */
void
print_start_block (int n)
{
  printc ("\n");
  printc ("START_BLOCK_%d:\n", n);
}

/**
 *
 * @param
 * @return
 */
void
print_continue_block (int n, int brace)
{
  printc ("\n");
  printc ("CONTINUE_BLOCK_%d:  ", n);
  if (brace)
    printc ("}\n");
}

/**
 *
 * @param
 * @return
 */
void
print_end_block (int n)
{
  printc ("END_BLOCK_%d: ;\n\n", n);
}

/**
 *
 * @param
 * @return
 */
void
print_continue_loop (int n)
{
  printc ("goto CONTINUE_BLOCK_%d;", n);
}


/**
 *
 * @param
 * @return
 */
void
print_exit_loop (int type, int n)
{
  if (type == 'M')
    {
      printc ("$cmd_no=-3;next;\n");
    }
  if (type == 'P')
    {
      printc ("_p.mode=1;\n");
    }
  if (type == 0)
    {
      printc ("goto END_BLOCK_%d;", n);
    }
}


/**
 *
 * @param
 * @return
 */
void
print_rep_ret (int report_cnt)
{
  printc ("goto report%d_ctrl;\n\n", report_cnt);
}

/**
 *
 * @param
 * @return
 */
static void
print_output_rep (struct rep_structure *rep)
{
  printc ("output_%d:\n", report_cnt);
  printc ("rep.top_margin=%d;\n", rep->top_margin);
  printc ("rep.bottom_margin=%d;\n", rep->bottom_margin);
  printc ("rep.left_margin=%d;\n", rep->left_margin);
  printc ("rep.right_margin=%d;\n", rep->right_margin);
  printc ("rep.page_length=%d;\n", rep->page_length);
  printc ("rep.page_no=%d;\n", rep->page_no);
  printc ("rep.printed_page_no=%d;\n", rep->printed_page_no);
  printc ("rep.line_no=%d;\n", rep->line_no);
  printc ("rep.col_no=%d;\n", rep->col_no);
  printc ("if (strlen(_rout2)==0)\n");
  printc ("strcpy(rep.output_loc,%s);\n", rep->output_loc);
  printc ("else strcpy(rep.output_loc,_rout2);\n");
  printc ("if (strlen(_rout1)==0)\n");
  printc ("rep.output_mode='%c';\n", rep->output_mode);
  printc ("else rep.output_mode=_rout1[0];\n");
  printc ("rep.report=&%s;\n", get_curr_rep_name ());
  printc ("trim(rep.output_loc);");
  print_rep_ret (report_cnt);

}

/**
 *
 * @param
 * @return
 */
static void
pdf_print_output_rep (struct pdf_rep_structure *rep)
{
  printc ("output_%d:\n", report_cnt);
  printc ("strcpy(rep.font_name,%s);\n", rep->font_name);
  printc ("rep.font_size=%f;\n", rep->font_size);
  printc ("rep.paper_size=%d;\n", rep->paper_size);

  printc ("rep.top_margin=pdf_size(%f,'l',&rep);\n", rep->top_margin);
  printc ("rep.bottom_margin=pdf_size(%f,'l',&rep);\n", rep->bottom_margin);
  printc ("rep.page_length=pdf_size(%f,'l',&rep);\n", rep->page_length);
  printc ("rep.left_margin=pdf_size(%f,'c',&rep);\n", rep->left_margin);
  printc ("rep.right_margin=pdf_size(%f,'c',&rep);\n", rep->right_margin);
  printc ("rep.page_width=pdf_size(%f,'c',&rep);\n", rep->page_width);

  printc ("rep.page_no=%d;\n", rep->page_no);
  printc ("rep.printed_page_no=%d;\n", rep->printed_page_no);

  printc ("rep.line_no=%f;\n", rep->line_no);
  printc ("rep.col_no=%f;\n", rep->col_no);

  printc ("if (strlen(_rout2)==0)\n");
  printc ("strcpy(rep.output_loc,%s);\n", rep->output_loc);
  printc ("else strcpy(rep.output_loc,_rout2);\n");
  printc ("if (strlen(_rout1)==0)\n");
  printc ("rep.output_mode='%c';\n", rep->output_mode);
  printc ("else rep.output_mode=_rout1[0];\n");
  printc ("rep.report=&%s;\n", get_curr_rep_name ());
  printc ("trim(rep.output_loc);");
  print_rep_ret (report_cnt);
}

/**
 *
 * @param
 * @return
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

      //strcpy (s2, sreports[z].rep_cond);
      //strcpy (s1, sreports[z].rep_expr);

      a = sreports[z].a;
      t = sreports[z].t;

      if (t == 'C')
        {
          print_expr(sreports[z].rep_where_expr);
          printc ("if (pop_bool()) {_g%d++;}\n",  a);
        }

      if (t == 'P')
        {
          printc ("_g%d++;",a+1);
          print_expr(sreports[z].rep_where_expr);
          printc(" if (pop_bool()) {_g%d++;} \n",  a);
        }

      if (t == 'S')
        {
          print_expr(sreports[z].rep_where_expr);
          printc("if (pop_bool()) {double _res;");
          print_expr(sreports[z].rep_cond_expr);
          printc("_res=pop_double(); _g%d+=_res;}\n ", a);
        }

      if (t == 'A')
        {
          print_expr(sreports[z].rep_where_expr);
          printc ("if (pop_bool()) {double _res;");
          print_expr(sreports[z].rep_cond_expr);

          printc ("_res=pop_double(); _g%d+=_res;_g%d++;}\n", a, a + 1);
        }

      if (t == 'N')
        {
          print_expr(sreports[z].rep_where_expr);
          printc ("if (pop_bool()) {double _res;");
          print_expr(sreports[z].rep_cond_expr);
          printc("_res=pop_double(); if (_res<_g%d||_g%dused==0) {_g%d=_res;_g%dused=1;}}\n", a, a, a, a);
        }

      if (t == 'X')
        {
          print_expr(sreports[z].rep_where_expr);
          printc ("if (pop_bool()) {double _res;");
          print_expr(sreports[z].rep_cond_expr);
          printc ("_res=pop_double(); if (_res>_g%d||_g%dused==0) {_g%d=_res;_g%dused=1;}}\n", a, a, a, a);
        }

    }
}

/**
 *
 * @param
 * @return
 */
static void
pr_report_agg_clr (void)
{
  int z;
  int a;
  int t;
  int in_b;

/*
  char s1[1024];
  char s2[1024];
*/

  for (z = 0; z < sreports_cnt; z++)
    {
/*
      strcpy (s2, sreports[z].rep_cond);
      strcpy (s1, sreports[z].rep_expr);
*/
      a = sreports[z].a;
      t = sreports[z].t;
      in_b = sreports[z].in_b;
      if (in_b > 0)
        {
          printc ("if (nargs==-%d&&acl_ctrl==REPORT_AFTERGROUP) {\n", in_b);
          printc ("/* t=%c */\n", t);
          if (t == 'C' || t == 'N' || t == 'X' || t == 'S')
            {
              printc ("_g%d=0;\n", a);
            }

          if (t == 'N' || t == 'X')
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
 *
 * @param
 * @return
 */
void
print_clr_status (void)
{
  printc ("xset_status(0);\n");
}


/**
 *
 * @param
 * @return
 */
void
prchkerr (int l, char *f)
{
  int a;
/* 0 = continue */
/* 1 = stop */
/* 2 = call */
/* 3 = goto */
  debug ("MJA prchkerr %d %s", l, f);
  printc
    ("if ($aubit4gl_pl::sqlca_sqlcode !=0 || $aubit4gl_pl::status !=0 || %d) {\n",
     when_code[A_WHEN_SUCCESS] == WHEN_CALL
     || when_code[A_WHEN_SQLSUCCESS] == WHEN_CALL);
  /*printc("debug(\"status=%%d sqlca_sqlcode=%%d\",status,sqlca_sqlcode);\n"); */
  printcomment ("/* NOTFOUND */");
  a =
    pr_when_do ("   if ($aubit4gl_pl::sqlca_sqlcode==100)",
		when_code[A_WHEN_NOTFOUND], l, f, when_to[A_WHEN_NOTFOUND]);
  printcomment ("/* SQLERROR */");
  a =
    pr_when_do
    ("   if ($aubit4gl_pl::sqlca_sqlcode<0 && $aubit4gl_pl::status==$aubit4gl_pl::sqlca_sqlcode)",
     when_code[A_WHEN_SQLERROR], l, f, when_to[A_WHEN_SQLERROR]);
  printcomment ("/* ANYERROR */");
  a =
    pr_when_do
    ("   if ($aubit4gl_pl::status<0 || $aubit4gl_pl::sqlca_sqlcode<0)",
     when_code[A_WHEN_ANYERROR], l, f, when_to[A_WHEN_ANYERROR]);
  printcomment ("/* ERROR */");
  a =
    pr_when_do ("   if ($aubit4gl_pl::status<0)", when_code[A_WHEN_ERROR], l,
		f, when_to[A_WHEN_ERROR]);
  printcomment ("/* SQLWARNING */");
  a =
    pr_when_do
    ("   if ($aubit4gl_pl::sqlca_sqlcode==0 && $aubit4gl_pl::sqlca_sqlawarn[0]=='W')",
     when_code[A_WHEN_SQLWARNING], l, f, when_to[A_WHEN_SQLWARNING]);
  printcomment ("/* WARNING */");
  a =
    pr_when_do
    ("   if ($aubit4gl_pl::sqlca_sqlcode==0 && ($aubit4gl_pl::sqlca_sqlawarn[0]=='w'||$aubit4gl_pl::sqlca_sqlawarn[0]=='W'))",
     when_code[A_WHEN_WARNING], l, f, when_to[A_WHEN_WARNING]);
  printcomment ("/* SQLSUCCESS */");
  a =
    pr_when_do
    ("   if ($aubit4gl_pl::sqlca_sqlcode==0 && $aubit4gl_pl::status==0)",
     when_code[A_WHEN_SQLSUCCESS], l, f, when_to[A_WHEN_SQLSUCCESS]);
  printcomment ("/* SUCCESS */");
  a =
    pr_when_do
    ("   if ($aubit4gl_pl::sqlca_sqlcode==0 && $aubit4gl_pl::status==0)",
     when_code[A_WHEN_SUCCESS], l, f, when_to[A_WHEN_SUCCESS]);
  printc ("}\n");
}

/**
 *
 * @param
 * @return
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
      printc ("%s {aubit4gl_pl::chk_err(%d,aubit_module_name);}\n", when_str,
	      l, f);
      printcomment ("/* WHENSTOP */");
    }
  if (when_code == WHEN_CALL)
    {
      printc ("%s aclfgl_%s(0);\n", when_str, when_to);
      printcomment ("/* WHENCALL */");
    }

  if (when_code == WHEN_GOTO)
    {
      printc ("%s goto %s;\n", when_str, when_to);
      printcomment ("/* WHENGOTO */");
    }
  return 1;
}


/**
 *
 * @param
 * @return
 */
void
print_expr(void* ptr)
{
	debug("via print_expr in lib");
	real_print_expr(ptr);
}
static void
real_print_expr (struct expr_str *ptr)
{
  void *optr;
  debug ("Print expr... %p", ptr);
  while (ptr)
    {
      debug ("Printing %p", ptr->expr);
      printc ("%s\n", ptr->expr);
      free (ptr->expr);
      optr = ptr;
      debug ("going to %p", ptr->next);
      ptr = ptr->next;
      free (optr);
    }
}

/**
 *
 * @param
 * @return
 */
static void
print_form_attrib (struct form_attr *form_attrib)
{
  printc ("%d,%d,%d,%d,%d,%d,%d,%d,(0x%x)",
	  form_attrib->iswindow,
	  form_attrib->form_line,
	  form_attrib->error_line,
	  form_attrib->prompt_line,
	  form_attrib->menu_line,
	  form_attrib->border,
	  form_attrib->comment_line,
	  form_attrib->message_line, form_attrib->attrib);
  debug ("Printing attributes\n");
  debug ("%d,%d,%d,%d,%d,%d,%d,%d,(0x%x)", form_attrib->iswindow,
	 form_attrib->form_line, form_attrib->error_line,
	 form_attrib->prompt_line, form_attrib->menu_line,
	 form_attrib->border, form_attrib->comment_line,
	 form_attrib->message_line, form_attrib->attrib);
}

/**
 *
 * @param
 * @return
 */
static int
print_field_bind (int ccc)
{
  char tabname[40];
  char colname[40];
  int a;
  debug ("%d\n", ibindcnt);
  for (a = 0; a < ccc; a++)
    {
      bname (ibind[a].varname, tabname, colname);
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
 *
 * @param
 * @return
 */
void
print_bind_pop1 (char i)
{
  int a;
  a = 0;
  if (i == 'i')
    {
      if (scan_variable (obind[a].varname) != -1)
	printc ("%s=pop_var2(%d,%d);\n", ibind[a].varname,
		(int) ibind[a].dtype & 0xffff, (int) ibind[a].dtype >> 16);
      else
	printc ("%s;\n", ibind[a].varname);
    }

  if (i == 'o')
    {
      if (scan_variable (obind[a].varname) != -1)
	printc ("%s=pop_var2(%d,%d);\n", obind[a].varname,
		(int) obind[a].dtype & 0xffff, (int) obind[a].dtype >> 16);
      else
	printc ("%s;\n", obind[a].varname);
    }

}



/**
 *
 * @param
 * @return
 */
static int
print_arr_bind (char i)
{
int a;

  debug ("/* %c */\n", i);
  /* dump_vars (); */
  if (i == 'i')
    {
      printc ("\n");
      printc ("struct BINDING ibind[]={\n");
      for (a = 0; a < ibindcnt; a++)
	{
	  if (a > 0)
	    printc (",\n");
	  printc ("{%s,%d,%d}", ibind[a].varname,
		  (int) ibind[a].dtype & 0xffff, (int) ibind[a].dtype >> 16);
	}
      printc ("\n}; # /* end of binding */\n");
      return a;
    }

  if (i == 'o')
    {
      printc ("\n");
      printc ("struct BINDING obind[]={\n");
      for (a = 0; a < obindcnt; a++)
	{
	  if (a > 0)
	    printc (",\n");
	  printc ("{%s,%d,%d}", obind[a].varname,
		  (int) obind[a].dtype & 0xffff, (int) obind[a].dtype >> 16);
	}
      printc ("\n}; # /* end of binding */\n");
      return a;
    }

return 0;
}



/**
 *
 * @param
 * @return
 */
static int
print_constr (void)
{
  int a;
  printc
    ("struct s_constr_list {char *tabname;char *colname;} constr_flds[]={\n");
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
 * @param
 * @return
 */
static int
print_field_bind_constr (void)
{
int a;
  
  for (a = 0; a < constr_cnt; a++)
    {
      if (a > 0)
	printc (",");
      if (constr_buff[a].tab[0] != 0)
	printc ("\"%s.%s\",1", constr_buff[a].tab, constr_buff[a].col);
      else
	printc ("\"%s\",1", constr_buff[a].col);
    }
  return a;
}





/**
 *
 * @param
 * @return
 */
int
print_param (char i)
{
int a;

  debug ("Expanding binding.. - was %d entries", fbindcnt);
  expand_bind ((void *)&fbind, 'F', fbindcnt);
  debug ("Expanded - now %d entries", fbindcnt);
  if (i == 'r')
    {
      printc ("static ");
    }

  printc ("my @%cbind=[ ", i);
  for (a = 0; a < fbindcnt; a++)
    {

      fbind[a].dtype = scan_variable (fbind[a].varname);
      if (a > 0)
	printc (",\n");
      printc ("[\\%s,%d,%d]", fbind[a].varname,
	      (int) fbind[a].dtype & 0xffff, (int) fbind[a].dtype >> 16);
    }
  printc ("\n]; # /* end of binding */\n");
  return a;
}




/**
 *
 * @param
 * @return
 */
int
print_bind (char i)
{
int a;
int bcnt;
char name[256];

  if (i == 'i')
    {
      strcpy (name, "ibind");
      bcnt = ibindcnt;
    }

  unwindcnt=0;

  debug ("/* %c */\n", i);
  if (i == 'i')
    {
      printc ("\n");
      printc ("my $ibind=aubit4gl_pl::dif_start_bind();\n");
      for (a = 0; a < ibindcnt; a++)
	{
	  switch (ibind[a].dtype & 0xffff)
	    {
	    case 0:
	      printc ("aubit4gl_pl::dif_add_bind_char($ibind,$%s,%d);\n",
		      ibind[a].varname, ibind[a].dtype >> 16);
	      sprintf(unwind[unwindcnt++],"$%s=aubit4gl_pl::dif_pop_bind_char($ibind);",ibind[a].varname);
	      break;
	    case 1:
	      printc ("aubit4gl_pl::dif_add_bind_smint($ibind,$%s);\n",
		      ibind[a].varname, ibind[a].dtype >> 16);
	      sprintf(unwind[unwindcnt++],"$%s=aubit4gl_pl::dif_pop_bind_smint($ibind);",ibind[a].varname);
	      break;
	    case 2:
	      printc ("aubit4gl_pl::dif_add_bind_int($ibind,$%s);\n",
		      ibind[a].varname, ibind[a].dtype >> 16);
	      sprintf(unwind[unwindcnt++],"$%s=aubit4gl_pl::dif_pop_bind_int($ibind);",ibind[a].varname);
	      break;
	    case 3:
	      printc ("aubit4gl_pl::dif_add_bind_float($ibind,$%s);\n",
		      ibind[a].varname, ibind[a].dtype >> 16);
	      sprintf(unwind[unwindcnt++],"$%s=aubit4gl_pl::dif_pop_bind_float($ibind);",ibind[a].varname);
	      break;
	    case 4:
	      printc ("aubit4gl_pl::dif_add_bind_smfloat($ibind,$%s);\n",
		      ibind[a].varname, ibind[a].dtype >> 16);
	      sprintf(unwind[unwindcnt++],"$%s=aubit4gl_pl::dif_pop_bind_smfloat($ibind);",ibind[a].varname);
	      break;
	    case 5:
	      printc ("aubit4gl_pl::dif_add_bind_dec($ibind,$%s,%d);\n",
		      ibind[a].varname, ibind[a].dtype >> 16);
	      sprintf(unwind[unwindcnt++],"$%s=aubit4gl_pl::dif_pop_bind_dec($ibind);",ibind[a].varname);
	      break;
	    case 6:
	      printc ("aubit4gl_pl::dif_add_bind_int($ibind,$%s);\n",
		      ibind[a].varname, ibind[a].dtype >> 16);
	      sprintf(unwind[unwindcnt++],"$%s=aubit4gl_pl::dif_pop_bind_int($ibind);",ibind[a].varname);
	      break;
	    case 7:
	      printc ("aubit4gl_pl::dif_add_bind_date($ibind,$%s);\n",
		      ibind[a].varname, ibind[a].dtype >> 16);
	      sprintf(unwind[unwindcnt++],"$%s=aubit4gl_pl::dif_pop_bind_date($ibind);",ibind[a].varname);
	      break;
	    case 8:
	      printc ("aubit4gl_pl::dif_add_bind_money($ibind,$%s,%d);\n",
		      ibind[a].varname, ibind[a].dtype >> 16);
	      sprintf(unwind[unwindcnt++],"$%s=aubit4gl_pl::dif_pop_bind_money($ibind);",ibind[a].varname);
	      break;
	    case 10:
	      printc ("aubit4gl_pl::dif_add_bind_dtime($ibind,$%s,%d);\n",
		      ibind[a].varname, ibind[a].dtype >> 16);
	      sprintf(unwind[unwindcnt++],"$%s=aubit4gl_pl::dif_pop_bind_dtime($ibind);",ibind[a].varname);
	      break;
	    case 11:
	      printc ("aubit4gl_pl::dif_add_bind_byte($ibind,$%s);\n",
		      ibind[a].varname, ibind[a].dtype >> 16);
	      sprintf(unwind[unwindcnt++],"$%s=aubit4gl_pl::dif_pop_bind_byte($ibind);",ibind[a].varname);
	      break;
	    case 12:
	      printc ("aubit4gl_pl::dif_add_bind_text($ibind,$%s);\n",
		      ibind[a].varname, ibind[a].dtype >> 16);
	      sprintf(unwind[unwindcnt++],"$%s=aubit4gl_pl::dif_pop_bind_text($ibind);",ibind[a].varname);
	      break;
	    case 13:
	      printc ("aubit4gl_pl::dif_add_bind_vchar($ibind,$%s,%d);\n",
		      ibind[a].varname, ibind[a].dtype >> 16);
	      sprintf(unwind[unwindcnt++],"$%s=aubit4gl_pl::dif_pop_bind_vchar($ibind);",ibind[a].varname);
	      break;
	    case 14:
	      printc ("aubit4gl_pl::dif_add_bind_interval($ibind,$%s,%d);\n",
		      ibind[a].varname, ibind[a].dtype >> 16);
	      sprintf(unwind[unwindcnt++],"$%s=aubit4gl_pl::dif_pop_bind_interval($ibind);",ibind[a].varname);
	      break;
	    }

	}
      printc (" #  end of binding \n");
      start_bind (i, 0);
      return a;
    }

  if (i == 'N')
    {
	  expand_bind ((void *)&nullbind, 'N', nullbindcnt);
      printc ("\n");
      printc ("struct BINDING nullbind[]={\n /* nullbind %d*/", nullbindcnt);
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
		  (int) nullbind[a].dtype >> 16);}
      printc ("\n}; # /* end of binding */\n");
      start_bind (i, 0);
      return a;
    }

  if (i == 'o')
    {

      printc ("\n");
      printc ("struct BINDING obind[]={\n");
      if (obindcnt == 0)
	{
	  printc ("{0,0,0}");
	}

      for (a = 0; a < obindcnt; a++)
	{
	  if (a > 0)
	    printc (",\n");
	  printc ("{&%s,%d,%d}", obind[a].varname,
		  (int) obind[a].dtype & 0xffff, (int) obind[a].dtype >> 16);
	}
      printc ("\n}; # /* end of binding */\n");
      start_bind (i, 0);
      return a;
    }

  if (i == 'O')
    {
      printc ("\n");
	  expand_bind ( (void *)&ordbind, 'O', ordbindcnt);
      printc ("static struct BINDING _ordbind[]={\n");
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
		  (int) ordbind[a].dtype >> 16);}
      printc ("\n}; # /* end of binding */\n");
      start_bind (i, 0);
      return a;
    }

return 0;
}

/**
 *
 * @param
 * @return
 */
void
dump_unwind(void)
{
int a;
	for (a=unwindcnt-1;a>=0;a--)
	{
		printc("%s",unwind[a]);
	}
}

/**
 *
 * @param
 * @return
 */
int
print_bind_expr (void *ptr, char i)
{
  int a;
  char buff[256];
  if (i == 'i')
    {
      append_expr (ptr, "struct BINDING ibind[]={");
		if (ibindcnt == 0)
        {
			append_expr (ptr, "{0,0,0}");
        }

		for (a = 0; a < ibindcnt; a++)
		{
		  if (a > 0)
			append_expr (ptr, ",");
		  sprintf (buff, "{&%s,%d,%d}", ibind[a].varname,
			   (int) ibind[a].dtype & 0xffff, (int) ibind[a].dtype >> 16);
		  append_expr (ptr, buff);
		}

	  append_expr (ptr, "};");
      start_bind (i, 0);
      return a;
    }

return 0;
}


/************************************************************************/
/* The rest of this file is the stuff called from the parser..               */
/************************************************************************/



/**
 *
 * @param
 * @return
 */
void
print_screen_mode (int n)
{
  printc ("screen_mode(%d);", n);
}

/**
 *
 * @param
 * @return
 */
void 
print_start_server (char * port, char *funclist)
/* void print_start_server (int port, char *funclist) */
{
  printc ("server_run(%s+0x2000000);", port);

  printc ("%s\n", funclist);
}


/**
 *
 * @param
 * @return
 */
void
print_stop_external (void)
{
  printc ("stop_serving();");
}


/**
 *
 * @param
 * @return
 */
void
print_remote_func (char *identifier)
{
  printh ("int aclfgl_%s(int np);\n", identifier);
  printc
    ("$aubit4gl_pl::status=0;register_func(\"%s\",aclfgl_%s);if ($aubit4gl_pl::status<0) {aubit4gl_pl::chk_err(%d,aubit_module_name);}\n",
     identifier, identifier, yylineno);
}



/**
 *
 * @param
 * @return
 */
void
print_exec_sql (char *s)
{
  printc ("execute_implicit_sql(prepare_glob_sql(\"%s\",0,0));\n", s);
}

/**
 *
 * @param
 * @return
 */
void
print_exec_sql_bound (char *s)
{
  int c;
  printc ("{\n");
  c = print_bind ('i');
  printc ("execute_implicit_sql(prepare_glob_sql(\"%s\",%d,ibind));\n", s, c);
  printc ("}\n");
}


/**
 *
 * @param
 * @return
 */
void
print_pop_variable (char *s)
{
  printc ("pop_var(&%s,%d);\n", s, scan_variable (s));
}



/**
 *
 * @param
 * @return
 */
void
print_getfldbuf (char *fields)
{
  printc ("{$a4gl_retvars;\n");
  printc ("$a4gl_retvars=fgl_getfldbuf(%s);\n", fields);
  start_bind ('i', 0);
}


/**
 *
 * @param
 * @return
 */
void
print_returning (void)
{
  int cnt;
  printc ("{\n");
  cnt = print_bind ('i');
  printc
    ("if ($a4gl_retvars!= %d ) {if ($a4gl_retvars!=-1) {aubit4gl_pl::xset_status(-3001);aubit4gl_pl::pop_args($a4gl_retvars);}\n} else {aubit4gl_pl::xset_status(0);\n",
     cnt);
  printc ("aubit4gl_pl::pop_params(aubit4gl::dif_get_bind($ibind),%d);}\n", cnt);
  dump_unwind();
  printc("aubit4gl_pl::dif_free_bind($ibind);");
  printc ("}\n");
  printc ("}\n");
}



/**
 *
 * @param
 * @return
 */
void
print_form_is_compiled (char *s)
{
  printc ("add_compiled_form(\"%s\",compiled_form_%s);\n", s, s);
  printh ("extern char compiled_form_%s[];\n", s);
}


/**
 *
 * @param
 * @return
 */
void
print_field_func (char type, char *name, char *var)
{
  if (type == 'I')
    printc ("aubit4gl_pl::push_int(aubit4gl_pl::fgl_infield(%s));", name);
  if (type == 'T')
    printc ("aubit4gl_pl::push_int(aubit4gl_pl::fgl_fieldtouched(%s));",
	    name);

  print_pop_variable (var);
}


/**
 * Prints the function call in perl language.
 *
 * @param identifier The function name 
 * @param args The arguments
 * @param args_cnt The number of arguments
 */
void
print_func_call(char *identifier, void* args, int args_cnt)
{
	debug("via print_func_call in lib");
	real_print_func_call(identifier,args,args_cnt);
}
static void
real_print_func_call (char *identifier, struct expr_str *args, int args_cnt)
{
  real_print_expr (args);
  printc ("{my $a4gl_retvars; aubit4gl_pl::xset_status(0);\n");
  printc ("$a4gl_retvars=aclfgl_%s(%d);\n", identifier, args_cnt);
}

/**
 * Prints a call to the corresponding pdf report in the generated perl code
 *
 * @param a1 The pdf function name
 * @param args The pdf function arguments
 * @param a3 The returning values
 */
void
print_pdf_call(char *a1, void* args, char *a3)
{
	debug("via print_pdf_call in lib");
	real_print_pdf_call(a1,args,a3);
}
static void
real_print_pdf_call (char *a1, struct expr_str *a2, char *a3)
{
  printc ("%s {int _retvars;xset_status(0);\n", a2);
  printc ("_retvars=aclpdf(&rep,%s,%s);\n", a1, a3);
}


/**
 *
 * @param
 * @return
 */
void
print_call_shared (char *libfile, char *funcname, int nargs)
{
  printc ("{int _retvars;\n");
  printc ("xset_status(0);_retvars=call_4gl_dll(%s,%s,%d);\n",
	  libfile, funcname, nargs);
}

/**
 *
 * @param
 * @return
 */
void
print_end_call_shared (void)
{
  printc ("}\n");
}


/**
 *
 * @param
 * @return
 */
void
print_call_external (char *host, char *func, char *port, int nargs)
{
  printc ("{int _retvars;\n");
  printc ("_retvars=remote_func_call(%s,%s,%s,%s);\n", host, func,
	  port, nargs);}

/**
 *
 * @param
 * @return
 */
void
print_end_call_external (void)
{
  printc ("}\n");
}


/**
 *
 * @param
 * @return
 */
void
print_case (int has_expr)
{
  if (has_expr)
    printc ("while (1==1) {char *s=0;if (s==0) {s=char_pop();}\n");
  else
    printc ("while (1==1) {\n");
}



/**
 *
 * @param
 * @return
 */
void
print_after_when (int endofblock)
{
  printc ("break;\n");
  if (endofblock)
    {
      printc ("}");
    }
}



/**
 *
 * @param
 * @return
 */
void
print_when (int has_expr)
{
  if (has_expr)
    {
      printc ("push_char(s);");
      printc ("pushop(OP_EQUAL);\n");
    }
  printc ("if (aubit4gl_pl::pop_bool()) {\n");
}



/**
 *
 * @param
 * @return
 */
void
print_close (char type, char *name)
{
  switch (type)
    {
    case 'F':
      printc ("aubit4gl_pl::close_form(%s);\n", name);
      break;
    case 'W':
      printc ("aubit4gl_pl::remove_window(%s);\n", name);
      break;
    case 'D':
      printc ("aubit4gl_pl::close_database();\n");
      break;
    case 'S':
      printc ("aubit4gl_pl::close_session(%s);\n", name);
      break;
    case 'C':
      printc ("aubit4gl_pl::close_cursor(%s);\n", name);
      break;
    }
}


/**
 *
 * @param
 * @return
 */
void
print_construct_1 (void)
{
  printc ("} # end of initialization \n");
}




/**
 *
 * @param
 * @return
 */
void
print_construct_2 (char *driver)
{
  printc ("if (_fld_dr==-95) {\n");
  printc ("   break;\n}\n");
  printc ("if (_fld_dr==-98) {\n");
  printc ("   fldname=char_pop(); _fld_dr=-97;continue;\n}\n");
  printc ("_fld_dr=%s;\n", driver);
  printc ("if (_fld_dr==-1) {\n");
  printc ("   fldname=char_pop(); _fld_dr=-98;continue;\n}\n");
  printc ("if (_fld_dr==0) {\n");
  printc ("   _fld_dr=-95;continue;\n}\n");
  add_continue_blockcommand ("CONSTRUCT");
  //printc ("debug(\"form_loop=%%d\",_fld_dr);");
  printc
    ("\n}\n push_constr(&_inp_io);\n aubit4gl_pl::pop_params(ibind,1);\n }\n");
  pop_blockcommand ("CONSTRUCT");	/* FIXME */
}


/**
 *
 * @param
 * @return
 */
void
print_construct_3 (int byname, char *constr_str, char *attr)
{
  int ccc;
  int k;
  printc ("{\n");
  start_bind ('i', constr_str);
  k = print_bind ('i');
  ccc = print_constr ();
  printc ("int _fld_dr=-100;char *fldname;char _inp_io[%d];\n",
	  sizeof (struct s_screenio) + 10);
  printc ("while(_fld_dr!=0){\n");
  printc ("if (_fld_dr==-100) {\n");
  printc ("SET(\"s_screenio\",\"_inp_io\",\"vars\",ibind);\n");
  printc ("SET(\"s_screenio\",\"_inp_io\",\"novars\",%d);\n", ccc);
  printc ("SET(\"s_screenio\",\"_inp_io\",\"currform\",get_curr_form());\n");
  printc ("SET(\"s_screenio\",\"_inp_io\",\"currentfield\",0);\n");
  printc ("SET(\"s_screenio\",\"_inp_io\",\"currentmetrics\",0);\n");
  printc ("SET(\"s_screenio\",\"_inp_io\",\"constr\",constr_flds);\n");
  printc ("SET(\"s_screenio\",\"_inp_io\",\"mode\",%d);\n", MODE_CONSTRUCT);
  if (byname == 1)
    {
      printc
	("SET(\"s_screenio\",\"_inp_io\",\"nfields\",gen_field_chars(GETPTR(\"s_screenio\",_inp_io,\"field_list\"),GET(\"s_screenio\",_inp_io,\"currform\"),");
      print_field_bind_constr ();
      printc (" /* */,0));\n");
    }
  else
    {
      printc
	("SET(\"s_screenio\",_inp_io,\"nfields\",gen_field_chars(GETPTR(\"s_screenio\",_inp_io,\"field_list\"),GET(\"s_screenio\",_inp_io,\"currform\"),%s,0));\n",
	 attr);}

  printc
    ("{int _sf; _sf=set_fields(&_inp_io); debug(\"_sf=%d\",_sf);if(_sf==0) break;\n}\n");
  printc ("_fld_dr=-99;\n");
}



/**
 *
 * @param
 * @return
 */
void
print_befaft_field_1 (char *fieldexpr)
{
  printc ("if (%s) {", fieldexpr);
}


/**
 *
 * @param
 * @return
 */
void
print_befaft_field_2 (void)
{
  printc ("}\n");
}


/**
 *
 * @param
 * @return
 */
void
print_onkey_1 (char *key_list_str)
{
  printc ("ON_KEY(\"%s\") {\n", key_list_str);
}


/**
 *
 * @param
 * @return
 */
void
print_onkey_2 (void)
{
  printc ("}\n");
}


/**
 *
 * @param
 * @return
 */
void
print_onkey_2_prompt (void)
{
  printc ("continue;}\n");
}


/**
 *
 * @param
 * @return
 */
void
print_defer (int quit)
{
  if (quit)
    printc ("def_quit();");
  else
    printc ("def_int();");
}



/**
 *
 * @param
 * @return
 */
void
print_display_line (void)
{
  printc ("aubit4gl_pl::push_int(-1);aubit4gl_pl::push_int(-1);\n");
}


/**
 *
 * @param
 * @return
 */
void 
print_display_by_name (char * attr)
/* void print_display_by_name (int attr) */
{
  int a;
  printc ("{\n");
  a = print_bind ('i');
  printc ("push_disp_bind(&ibind,%d);\n", a);
  printc ("disp_fields(%d,%d,", a, attr);
  print_field_bind (a);
  printc (",0);\n");
  printc ("}\n");
}


/**
 *
 * @param
 * @return
 */
char *
get_display_str (int type, char *s, char *f)
{
  static char buff[1024];
  if (type == 0)
    strcpy (buff, "aubit4gl_pl::display_at(%s,%s);\n");
  if (type == 1)
    strcpy (buff, "aubit4gl_pl::display_at(%s,%s);");
  if (type == 2)
    sprintf (buff, "aubit4gl_pl::disp_fields(%%s,%%s,%s,0);\n", s);
  if (type == 3)
    sprintf (buff, "aubit4gl_pl::disp_form_fields(%%s,%%s,%s,%s,0);\n", f, s);
  if (type == 4)
    sprintf (buff, "aubit4gl_pl::disp_main_caption();\n");
  if (type == 5)
    sprintf (buff, "aubit4gl_pl::disp_form_caption(%s);\n", s);
  return buff;
}

/**
 *
 * @param
 * @return
 */
void
print_display (char *fmt, char *expr, char *attr)
{
  printc (fmt, expr, attr);
}


/**
 *
 * @param
 * @return
 */
void
print_display_form (char *s, char *a)
{
  printc ("disp_form(%s,%s);\n", s, a);
}


/**
 *
 * @param
 * @return
 */
void print_display_array_p1 (char *arrvar, char *srec, char *scrollfield,char *attr)
/* void print_display_array_p1 (char *arrvar, char *srec, char *attr) */
{
  int cnt;
  printcomment ("/* Display array */\n");
  printc ("{int _fld_dr;\nchar _dispio[%d];\n",
	  sizeof (struct s_disp_arr) + 10);
  cnt = print_arr_bind ('o');
  printc ("SET(\"s_disp_arr\",_dispio,\"no_arr\",get_count());\n");
  printc ("SET(\"s_disp_arr\",_dispio,\"binding_comp\",obind);\n");
  printc ("SET(\"s_disp_arr\",_dispio,\"nbind\",%d);\n", cnt);
  printc ("SET(\"s_disp_arr\",_dispio,\"srec\",0);\n");
  printc
    ("SET(\"s_disp_arr\",_dispio,\"arr_elemsize\",sizeof(%s[0]));\n",
     arrvar); printc ("_fld_dr=-1;\n");
  printc ("while (_fld_dr!=0) {\n");
  printc ("_fld_dr=disp_arr(&_dispio,%s,\"%s\",%s);\n", arrvar, srec, attr);
}


/**
 *
 * @param
 * @return
 */
void
print_display_array_p2 (void)
{
  printc ("}\n}\n");
  printcomment ("/* end display */\n");

  pop_blockcommand ("DISPLAY");
}


/**
 *
 * @param
 * @return
 */
void
print_error (char *s, int wait)
{
  printc ("display_error(%s,%d);\n", s, wait);
}


/**
 *
 * @param
 * @return
 */
void
print_exit_program (int has_expr)
{
  if (has_expr)
    printc ("fgl_end();exit(pop_int());");
  else
    printc ("fgl_end();exit(0);");
}



/**
 *
 * @param
 * @return
 */
void
print_for_start (char *var)
{
  printc
    ("\n{int _s,_e,_step;\n_step=pop_int();_e=pop_int();_s=pop_int();\n");
  printc
    ("for (%s=_s; (%s<=_e && _step>0)||(%s>=_e &&  _step<0);%s+=_step) {\n",
     var, var, var, var);
}


/**
 *
 * @param
 * @return
 */
void
print_for_end (void)
{
  printc ("}\n");
}


/**
 *
 * @param
 * @return
 */
void
print_for_default_step (void)
{
  printc ("aubit4gl_pl::push_int(1);\n");
}


/**
 *
 * @param
 * @return
 */
void
print_foreach_start (void)
{
  printc ("{");
}


/**
 *
 * @param
 * @return
 */
void
print_foreach_next (char *cursorname, char *into)
{
  printc ("set_sqlca_sqlcode(0);\n");
  printc ("open_cursor(0,%s);\n", cursorname);
  printc ("while (1) {\n");
  printc ("fetch_cursor(%s,%d,1,%s);\n", cursorname, FETCH_RELATIVE, into);
  printc
    ("if ($aubit4gl_pl::sqlca_sqlcode<0||$aubit4gl_pl::sqlca_sqlcode==100) break;\n");
}


/**
 *
 * @param
 * @return
 */
void
print_foreach_end (void)
{
  printc ("}");
  printcomment ("# end of foreach while loop \n");

  printc ("}\n");
}


/**
 *
 * @param
 * @return
 */
void
print_free_cursor (char *s)
{
  printc ("/* FREE CUROSR .. FIXME */\n");
}


/**
 *
 * @param
 * @return
 */
void
print_pushchar (char *s)
{
  printc ("aubit4gl_pl::push_char(%s);\n", s);
}


/**
 *
 * @param
 * @return
 */
void
print_goto (char *label)
{
  printc ("goto %s;\n", label);
}


/**
 *
 * @param
 * @return
 */
void
print_gui_do_menuitems (char *list, int mode)
{
  if (mode == 'U')
    printc ("aubit4gl_pl::uncheck_menuitems(%s,0);\n", list);
  if (mode == 'C')
    printc ("aubit4gl_pl::check_menuitems(%s,0);\n", list);
  if (mode == 'D')
    printc ("aubit4gl_pl::endis_menuitems(0,%s,0);\n", list);
  if (mode == 'E')
    printc ("aubit4gl_pl::endis_menuitems(1,%s,0);\n", list);
}


/**
 *
 * @param
 * @return
 */
void
print_gui_do_fields (char *list, int mode)
{
  if (mode == 'D')
    printc ("aubit4gl_pl::endis_fields(0,%s,0);\n", list);
  if (mode == 'E')
    printc ("aubit4gl_pl::endis_fields(1,%s,0);\n", list);
}


/**
 *
 * @param
 * @return
 */
void
print_gui_do_form (char *name, char *list, int mode)
{
  if (mode == 'D')
    printc ("aubit4gl_pl::endis_form(0,%s,%s,0);\n", name, list);
  if (mode == 'E')
    printc ("aubit4gl_pl::endis_form(1,%s,%s,0);\n", name, list);
}


/**
 *
 * @param
 * @return
 */
void
print_if_start (void)
{
  printc ("if (aubit4gl_pl::pop_bool()) {\n");
}

/**
 *
 * @param
 * @return
 */
void
print_if_else (void)
{
  printc ("} else {\n");
}

/**
 *
 * @param
 * @return
 */
void
print_if_end (void)
{
  printc ("}");
}


/**
 *
 * @param
 * @return
 */
void
print_import (char *func, int nargs)
{
  int a;
  char buff[1024];
  char buff2[1024];
  printc ("\n\naclfgl_%s (int nargs) {\n", func);
  printc ("my _argc[%s];\n", nargs);
  printc ("my _retval;");
  printc
    ("   if (nargs!=%d) {$aubit4gl_pl::status=-30174;pop_args(nargs);return 0;}\n",
     nargs, yylineno);
  for (a = 1; a <= nargs; a++)
    {
      printc ("   _argc[%d]=aubit4gl_pl::pop_int();\n", nargs - a);
    }
  sprintf (buff, "_retval=%s(", func);
  for (a = 0; a <= nargs - 1; a++)
    {
      if (a > 0)
	strcat (buff, ",");
      sprintf (buff2, "_argc[%d]", a);
      strcat (buff, buff2);
    }
  strcat (buff, ");\n   aubit4gl_pl::push_int(_retval);\n   return 1;\n");
  strcat (buff, "}\n\n\n");
  printc (buff);
}


/**
 *
 * @param
 * @return
 */
void
print_init (void)
{
  int cnt;
  printc ("{\n");
  cnt = print_bind ('N');
  printc ("aubit4gl_pl::set_init(nullbind,%d);\n", cnt);
  printc ("}\n");
}

/**
 *
 * @param
 * @return
 */
void
print_init_table (char *s)
{
  int cnt;
  printc ("{\n");
  cnt = print_bind ('N');
  printc ("aubit4gl_pl::set_init(nullbind,%d);\n", cnt);
  printc ("}\n");
}



/**
 *
 * @param
 * @return
 */
void
generate_or (char *out, char *in1, char *in2)
{
  sprintf (out, "%s||%s", in1, in2);
}

/**
 *
 * @param
 * @return
 */
void
print_next_field (char *s)
{
  printc ("aubit4gl_pl::req_field(&_inp_io,%s);\n", s);
}

/************************************************************************/
/* INPUT */
/************************************************************************/

/**
 *
 * @param
 * @return
 */
void
print_input_1 (void)
{
  printc ("} # /* end of initialization */\n");
}

/**
 *
 * @param
 * @return
 */
void
print_input_2 (char *s)
{
  printc ("if (_fld_dr==-95) {/* after input */\n");
  printc ("   break;\n}\n");
  printc ("if (_fld_dr==-98) {/* before field */\n");
  printc ("   fldname=aubit4gl_pl::char_pop(); _fld_dr=-97;continue;\n}\n");
  printc ("_fld_dr=%s;_forminit=0;\n", s);
  printc ("if (_fld_dr==-1) {/* after field */\n");
  printc ("   fldname=aubit4gl_pl::char_pop(); _fld_dr=-98;continue;\n}\n");
  printc ("if (_fld_dr==0) { /* after input 2 */\n");
  printc ("   _fld_dr=-95;continue;\n}\n");
  add_continue_blockcommand ("INPUT");
  printc ("\n}\n");
  pop_blockcommand ("INPUT");
  printc ("}\n");
}


/**
 *
 * @param
 * @return
 */
void
print_input (int byname, char *defs, char *helpno, char *fldlist)
{
  int ccc;
  printc ("{int _fld_dr=-100;char *fldname;char _inp_io[%d];",
	  sizeof (struct s_screenio));
  printc ("int _forminit=1;\n");
  printc ("while(_fld_dr!=0){\n");
  printc ("if (_fld_dr==-100) {\n");
  printc ("/*");
  push_blockcommand ("INPUT");
  printc ("*/");
  printc ("/* input by name */");
  ccc = print_bind ('i');
  printc
    ("SET(\"s_screenio\",_inp_io,\"currform\",aubit4gl_pl::get_curr_form());\n");
  printc ("if (GET(\"s_screenio\",_inp_io,\"currform\")==0) break;\n");
  printc ("SET(\"s_screenio\",_inp_io,\"vars\",ibind);\n");
  printc ("SET(\"s_screenio\",_inp_io,\"novars\",%d);\n", ccc);
  printc ("SET(\"s_screenio\",_inp_io,\"help_no\",%s);\n", helpno);
  printc ("SET(\"s_screenio\",_inp_io,\"currentfield\",0);\n");
  printc ("SET(\"s_screenio\",_inp_io,\"currentmetrics\",0);\n");
  printc ("SET(\"s_screenio\",_inp_io,\"mode\",%d+%s);\n", MODE_INPUT, defs);
  if (byname)
    {
      printc
	("SET(\"s_screenio\",_inp_io,\"nfields\",gen_field_chars(GETPTR(\"s_screenio\",_inp_io,\"field_list\"),GET(\"s_screenio\",_inp_io,\"currform\"),");
      print_field_bind (ccc);
      printc
	(",0)); if (GET(\"s_screenio\",_inp_io,\"nfields\")==-1) break;\n");
    }
  else
    {
      printc
	("SET(\"s_screenio\",_inp_io,\"nfields\",gen_field_chars(GETPTR(\"s_screenio\",_inp_io,\"field_list\"),GET(\"s_screenio\",_inp_io,\"currform\"),%s,0));\n",
	 fldlist);
      printc ("if (GET(\"s_screenio\",_inp_io,\"nfields\")==-1) break;\n");
    }
  printc
    ("{int _sf; _sf=set_fields(&_inp_io); debug(\"_sf=%d\",_sf);if(_sf==0) break;\n}\n");
  printc ("_fld_dr=-99;\n");
}

/**
 *
 * @param
 * @return
 */
char *
print_input_array (char *arrvar, char *helpno, char *defs, char *srec,
		   char *attr)
{
  static char buff2[256];
  int cnt;
  printc ("/*");
  push_blockcommand ("INPUT");
  printc ("*/");
  printcomment ("/* input */\n");
  printc ("{int _fld_dr=-100;\nchar *fldname;\nint _forminit;");
  printc ("char _inp_io[%d];\n", sizeof (struct s_inp_arr));
  cnt = print_arr_bind ('o');
  printc ("while (_fld_dr!=0) {\n");
  printc ("if (_fld_dr==-100) {\n");
  printc ("SET(\"s_inp_arr\",_inp_io,\"no_arr\",get_count());\n");
  printc ("SET(\"s_inp_arr\",_inp_io,\"binding_comp\",obind);\n");
  printc ("SET(\"s_inp_arr\",_inp_io,\"nbind\",%d);\n", cnt);
  printc ("SET(\"s_inp_arr\",_inp_io,\"srec\",0);\n");
  printc ("SET(\"s_inp_arr\",_inp_io,\"inp_flags\",%d);\n", inp_flags);
  printc ("SET(\"s_inp_arr\",_inp_io,\"help_no\",%s);\n", helpno);
  printc
    ("SET(\"s_inp_arr\",_inp_io,\"arr_elemsize\",sizeof(%s[0]));\n", arrvar);
  printc
    ("SET(\"s_inp_arr\",_inp_io,\"arr_size\",sizeof(%s)/sizeof(%s[0]));\n",
     arrvar, arrvar);
  printc ("SET(\"s_inp_arr\",_inp_io,\"currform\",get_curr_form());\n");
  printc ("SET(\"s_inp_arr\",_inp_io,\"inp_flags\",%d);\n", inp_flags);
  printc ("if (GET(\"s_inp_arr\",_inp_io,\"currform\")==0) break;\n");
  printc ("SET(\"s_inp_arr\",_inp_io,\"currentfield\",0);\n");
  printc ("SET(\"s_inp_arr\",_inp_io,\"currentmetrics\",0);\n");
  printc ("SET(\"s_inp_arr\",_inp_io,\"mode\",%d+%s);\n", MODE_INPUT, defs);
  printc
    ("SET(\"s_inp_arr\",_inp_io,\"nfields\",gen_field_chars(GETPTR(\"s_inp_arr\",_inp_io,\"field_list\"),GET(\"s_inp_arr\",_inp_io,\"currform\"),\"%s.*\",0,0));\n",
     srec); printc ("_fld_dr=-1;continue;\n");
  sprintf (buff2, "inp_arr(&_inp_io,%s,\"%s\",%s);\n", defs, srec, attr);
  return buff2;
}

/**
 *
 * @param
 * @return
 */
char *
get_formloop_str (int type)
{
  if (type == 0)		/* Input, Input by name */
    return "form_loop(&_inp_io,_forminit)";

return 0;
}


/**
 *
 * @param
 * @return
 */
void
print_scroll (char *flds, char *updown)
{
  printc ("scroll(gen_field_chars(%s),%s,%s);\n", flds, updown);
}



/**
 *
 * @param
 * @return
 */
void
print_label (char *s)
{
  printc ("%s:\n", s);
}

/**
 *
 * @param
 * @return
 */
int
print_let_manyvars (char *nexprs)
{
  int from_exprs;
  int to_vars;
  printc ("{");
  to_vars = print_bind ('o');
  from_exprs = atoi (nexprs);
  if (to_vars != from_exprs)
    {
      return 0;
    }
  printc ("aubit4gl_pl::pop_params(obind,%d);\n", from_exprs);
  printc ("}\n");
  return 1;
}

/**
 *
 * @param
 * @return
 */
void
print_push_null ()
{
  printc ("push_null();\n");
}

/* Linked stuff */


/**
 *
 * @param
 * @return
 */
int
print_linked_cmd (int type, char *var)
{
  char tabname[64];
  char pklist[256];
  int ni;
  if (last_var_is_linked (tabname, pklist))
    {
      char buff[80];
      char buff2[80];
      int no = 0;
      int no_keys;
      int azcnt;
      printc ("{\n");
      if (type == 'S')
	{
	  start_bind ('o', 0);
	  sprintf (buff, "%s.*", var);
	  add_bind ('o', buff);
	}

      debug ("Finding number of keys...\n");
      no_keys = linked_split (pklist, 0, 0);
      debug ("No of keys=%d", no_keys);
      start_bind ('i', 0);
      if (type == 'U')
	{
	  char buffer[256];
	  set_pklist (pklist);
	  sprintf (buffer, "%s.*", var);
	  push_bind_rec (buffer, 'u');
	}
      for (azcnt = 1; azcnt <= no_keys; azcnt++)
	{
	  debug ("Getting key no %d", azcnt);
	  linked_split (pklist, azcnt, buff2);
	  sprintf (buff, "%s.%s", var, buff2);
	  debug ("Adding linked %s", buff);
	  add_bind ('i', buff);
	  debug (" key count %d %d\n", azcnt, no_keys);
	}
      if (type == 'S')
	no = print_bind ('o');
      ni = print_bind ('i');
      if (type == 'S')
	sprintf (buff, "SELECT * FROM %s WHERE ", tabname);
      if (type == 'D')
	sprintf (buff, "DELETE FROM %s WHERE ", tabname);
      if (type == 'U')
	sprintf (buff, "UPDATE %s SET (%s)=(%s) WHERE ", tabname,
		 get_upd_using_notpk (), get_upd_using_queries ());
      for (azcnt = 1; azcnt <= no_keys; azcnt++)
	{
	  if (azcnt > 1)
	    strcat (buff, "AND");
	  linked_split (pklist, azcnt, buff2);
	  strcat (buff, " ");
	  strcat (buff, buff2);
	  strcat (buff, "=? ");
	}
      if (type == 'S')
	printc
	  ("execute_implicit_select(prepare_select(ibind,%d,obind,%d,\"%s\"));",
	   ni, no, buff);
      if (type == 'D' || type == 'U')
	printc
	  ("execute_implicit_sql(prepare_glob_sql(\"%s\",%d,ibind));",
	   buff, ni); printc ("}\n");
    }
  else
    {
      return 0;
    }
  return 1;
}



/**
 *
 * @param
 * @return
 */
void
print_locate (char where, char *var, char *fname)
{
  printc ("locate_var(&%s,'%c',%s);\n", var, where, fname);
}


/**************************** REPORT **********************/

/**
 *
 * @param
 * @return
 */
void
print_start_report (char *repname, char *where, char *out)
{
  printc ("push_char(\"%s\");\n", where);
  printc ("push_char(%s);\n", out);
  printc ("acl_fglr_%s(2,REPORT_START);", repname);
}


/**
 *
 * @param
 * @return
 */
void
print_output_to_report (char *repname, char *nvalues)
{
  printc ("acl_fglr_%s(%s,REPORT_SENDDATA);\n", repname, nvalues);
}


/**
 *
 * @param
 * @return
 */
void
print_finish_report (char *repname)
{
  printc ("acl_fglr_%s(0,REPORT_FINISH);\n", repname);
}

/**
 *
 * @param
 * @return
 */
void
print_format_every_row (void)
{
  printc ("#error FORMAT EVERY ROW not implemented yet");
}

/**
 *
 * @param
 * @return
 */
void
print_need_lines (void)
{
  printc ("%sneed_lines(&rep);\n", ispdf ());
}

/**
 *
 * @param
 * @return
 */
void
print_skip_lines (void)
{
  printc ("%saclfgli_skip_lines(&rep);\n", ispdf ());
}

/**
 *
 * @param
 * @return
 */
void
print_skip_top (void)
{
  printc ("%sskip_top_of_page(&rep);\n", ispdf ());
}

/**
 *
 * @param
 * @return
 */
void
print_skip_by (char *nval)
{
  printc ("pdf_skip_by(&rep,%s);\n", nval);
}

/**
 *
 * @param
 * @return
 */
void
print_skip_to (char *nval)
{
  printc ("pdf_skip_to(&rep,%s);\n", nval);
}

/**
 *
 * @param
 * @return
 */
void
print_report_print (int type, char *semi, char *wordwrap)
{

  if (type == 0)
    printc ("%srep_print(&rep,0,%s,0);\n", ispdf (), semi);
  if (type == 1)

    printc ("%srep_print(&rep,1,1,%s);\n", ispdf (), wordwrap);
}

/**
 *
 * @param
 * @return
 */
void
print_report_print_file (char *fname, char *semi)
{
  printc ("%srep_file_print(&rep,%s,%s);\n", ispdf (), fname, semi);
}

/**
 *
 * @param
 * @return
 */
void
print_report_print_img (char *scaling, char *blob, char *type, char *semi)
{
  printc ("%s pdf_blob_print(&rep,&%s,\"%s\",%s);\n", scaling,
	  blob, type, semi);}

/**
 *
 * @param
 * @return
 */
char *
get_default_scaling (void)
{
  return "push_double(1.0);push_double(1.0);";
}


/**
 *
 * @param
 * @return
 */
void
print_order_by_type (int type)
{
  printc ("static int fgl_rep_orderby=%d;\n", type);
}


/**
 *
 * @param
 * @return
 */
void
print_report_1 (char *name)
{
  printc ("int acl_fglr_%s (int nargs,int acl_ctrl) {\n", name, name);
}

/**
 *
 * @param
 * @return
 */
void
print_report_end (void)
{
  printc ("\n} # /* end of report */\n");
}

void
print_report_2 (int pdf, char *repordby)
{
  int cnt;
  printc ("static struct rep_structure rep;\n");
  printc ("static char _rout1[256];\n");
  printc ("static char _rout2[256];\n");
  printc ("static int _useddata=0;\n");
  printc ("static int _started=0;\n");
  cnt = print_param ('r');
  printc
    ("if (acl_ctrl==REPORT_SENDDATA&&_started==0&&fgl_rep_orderby!=1) {");
  printc ("   aubit4gl_pl::xsetstatus(-5555);\n");
  printc ("    return;\n");
  printc ("    }\n");
  printc ("if (nargs!=%d&&acl_ctrl==REPORT_SENDDATA) {", cnt);
  printc ("fglerror(ERR_BADNOARGS,ABORT);pop_args(nargs);return 0;}\n");
  printc ("if (acl_ctrl==REPORT_LASTDATA) {\n   int _p;\n");
  printc
    ("   if (_useddata) {for (_p=sizeof(_ordbind)/sizeof(struct BINDING);_p>=1;_p--) %s(_p,REPORT_AFTERGROUP);}\n",
     get_curr_rep_name ());
  printc ("}\n");
  printc ("if (acl_ctrl==REPORT_SENDDATA&&fgl_rep_orderby==1) {");
  printc
    ("aubit4gl_pl::pop_params(rbind,%d);add_row_report(&rbind,%d);\nreturn;}",
     cnt, cnt);
  printc ("if (acl_ctrl==REPORT_SENDDATA) {\n");
  printc ("   int _g,_p;\n");
  printc ("   _g=chk_params(&rbind,%d,&_ordbind,%s);\n", cnt, repordby);
  printc
    ("   if (_g>0&&_useddata) {for (_p=sizeof(_ordbind)/sizeof(struct BINDING);_p>=_g;_p--) %s(_p,REPORT_AFTERGROUP);}\n",
     get_curr_rep_name ());
  printc ("   aubit4gl_pl::pop_params(rbind,%d);\n", cnt);
  printc ("   if (_useddata==0) {_g=1;}\n");
  printc
    ("   if (_g>0) { _useddata=1;for (_p=_g;_p<=(sizeof(_ordbind)/sizeof(struct BINDING));_p++) %s(_p,REPORT_BEFOREGROUP);}\n",
     get_curr_rep_name ());
  printc ("   _useddata=1;\n");
  print_rep_ret (report_cnt);
  printc ("}\n\n");
  printc ("if (acl_ctrl==REPORT_FINISH) {\n");
  printc ("    if (fgl_rep_orderby==1) {\n");
  printc ("        struct BINDING *reread;\n");
  printc ("        fgl_rep_orderby=-1;\n");
  printc ("   push_char(_rout1,254);\n");
  printc ("   push_char(_rout2,254);\n");
  printc ("        %s(2,REPORT_START);\n", get_curr_rep_name ());
  printc
    ("        init_report_table(&rbind,%d,_ordbind,sizeof(_ordbind)/sizeof(struct BINDING),&reread);\n",
     cnt);
  printc
    ("        while (report_table_fetch(reread,%d,&rbind)) %s(%d,REPORT_SENDDATA);\n",
     cnt, get_curr_rep_name (), cnt);
  printc ("        %s(0,REPORT_FINISH);\n", get_curr_rep_name ());
  printc ("        end_report_table(&rbind,%d,reread);\nreturn;", cnt);
  printc ("    }\n");
  printc ("}\n");
  printc ("if (acl_ctrl==REPORT_START) {\n");
  printc ("   pop_char(_rout2,254);\n");
  printc ("   pop_char(_rout1,254);\n");
  printc
    ("    if (fgl_rep_orderby==1) {make_report_table(&rbind,%d);return;}\n",
     cnt); printc ("   _useddata=0;\n");
  printc ("   _started=1;\n");
  printc ("goto output_%d;\n", report_cnt);
  printc ("}\n\n");
  print_rep_ret (report_cnt);
  if (pdf)
    pdf_print_output_rep (&pdf_rep_struct);
  else
    print_output_rep (&rep_struct);
}

/**
 *
 * @param
 * @return
 */
void
print_pause (char *msg)
{
  printc ("acllib_pause(%s);\n", msg);
}

/* MISC */

/**
 *
 * @param
 * @return
 */
void
print_sleep (void)
{
  printc ("aubit4gl_pl::sleep_i();\n");
}


/* EXPRESSIONS */

/**
 *
 * @param
 * @return
 */
void
print_op (char *type)
{
  printc ("aubit4gl_pl::pushop(%s);\n", type);
}



/**
 *
 * @param
 * @return
 */
void
print_niy (char *type)
{
  printc ("#error Not Implemented Yet %s", type);
}


/**
 *
 * @param
 * @return
 */
void
print_push_variable (char *s)
{
  printc ("aubit4gl_pl::push_param(&%s,0x%x);\n", s, scan_variable (s));
}

/**
 *
 * @param
 * @return
 */
void
print_message (int type, char *attr, int wait)
{
  if (type == 0)
    printc ("aubit4gl_pl::aclfgli_pr_message(%s,%d);\n", attr, wait);
  else
    printc ("aubit4gl_pl::aclfgli_pr_message_cap(%d,%d);\n", attr, wait);
}

/**
 *
 * @param
 * @return
 */
void
print_system_run (int type, char *rvar)
{
  printc ("aubit4gl_pl::system_run(%d);", type);

  if (rvar)
    print_pop_variable (rvar);
}


/**
 *
 * @param
 * @return
 */
void
print_set_conn (char *conn)
{
  printc ("aubit4gl_pl::set_conn(%s);\n", conn);
}

/**
 *
 * @param
 * @return
 */
void
print_set_options (char *type, char *id, char *var, char *val)
{
  printc ("aubit4gl_pl::set_%s_options(%s,%s,%s);\n", type, id, var, val);
}

/**
 *
 * @param
 * @return
 */
void
print_while_1 (void)
{
  printc ("while (1==1) {\n");
}

/**
 *
 * @param
 * @return
 */
void
print_while_2 (void)
{
  printc ("if (!(aubit4gl_pl::pop_bool())) break;\n");
}

/**
 *
 * @param
 * @return
 */
void
print_while_3 (void)
{
  /* for future enhancement! */
}

/**
 *
 * @param
 * @return
 */
void
print_put (void)
{
  int n;
  printc ("{\n");
  n = print_bind ('i');
  printc ("aubit4gl_pl::put_insert(&ibind,%d);\n", n);
  printc ("}\n");
}


/**
 *
 * @param
 * @return
 */
void
print_prepare (char *stmt, char *sqlvar)
{
  printc ("aubit4gl_pl::add_prepare(%s,aubit4gl_pl::prepare_sql(%s));\n",
	  stmt, sqlvar);
}


/**
 *
 * @param
 * @return
 */
void
print_undo_use (char *s)
{
  printc (s);
}

/**
 *
 * @param
 * @return
 */
void
print_execute (char *stmt, int using)
{
  int ni;
  if (using == 0)
    printc ("aubit4gl_pl::execute_sql(%s,0,0);\n", stmt);
  else
    {
      printc ("{\n");
      ni = print_bind ('i');
      printc ("aubit4gl_pl::execute_sql(%s,%d,ibind);\n", stmt, ni);
      printc ("}\n");
    }

}


/**
 *
 * @param
 * @return
 */
void
print_prompt_1 (char *a1, char *a2, char *a3, char *a4)
{
  printc ("{char _p[%d];int _fld_dr;\n", sizeof (struct s_prompt));
  printc ("aubit4gl_pl::start_prompt(&_p,%s,%s,%s,%s);\n", a1, a2, a3, a4);
  printc
    ("while (GET(\"s_prompt\",_p,\"mode\")!=2) {_fld_dr=aubit4gl_pl::prompt_loop(&_p);\n");
}

/**
 *
 * @param
 * @return
 */
void
print_prompt_forchar (void)
{
  printc ("if (_fld_dr) break;\n");
}

/**
 *
 * @param
 * @return
 */
void
print_prompt_end (char *s)
{
  printc ("}\n");
  print_pop_variable (s);
  printc ("}\n");
}

/**
 *
 * @param
 * @return
 */
void
print_open_window (char *name, char *type)
{
  printc ("aubit4gl_pl::%s(%s,", type, name);
  print_form_attrib (&form_attrib);
  printc (");\n");
}

/**
 *
 * @param
 * @return
 */
void
print_open_form (char *fmt, char *a1, char *a2)
{
  printc (fmt, a1, a2);
}


/**
 *
 * @param
 * @return
 */
void
print_open_session (char *s, char *v, char *user)
{
  printc ("aubit4gl_pl::init_session(%s", s);
  if (strcmp (user, "?") == 0)
    {
      printc (",aubit4gl_pl::char_pop(),%s);\n", user);
    }
  else
    {
      printc (",\"%s\",%s);\n", v, user);
    }
}

/**
 *
 * @param
 * @return
 */
void
print_open_cursor (char *cname, char *using)
{
  printc ("aubit4gl_pl::open_cursor(%s,%s);\n", using, cname);
}


/**
 *
 * @param
 * @return
 */
void
print_clr_window (char *s)
{
  printc ("aubit4gl_pl::clr_window(%s);\n", s);
}

/**
 *
 * @param
 * @return
 */
void
print_clr_form (char *formname, char *clr, char *defs)
{
  print_niy ("Clear Form");
}

/**
 *
 * @param
 * @return
 */
void
print_clr_fields (char *flds, char *defs)
{
  print_niy ("Clear Fields");
}

/**
 *
 * @param
 * @return
 */
void
print_current_window (char *s)
{
  printc ("aubit4gl_pl::current_window(%s);\n", s);
}

/**
 *
 * @param
 * @return
 */
void
print_show_window (char *s)
{
  printc ("aubit4gl_pl::show_window(%s);\n", s);
}

/**
 *
 * @param
 * @return
 */
void
print_hide_window (char *s)
{
  printc ("aubit4gl_pl::hide_window(%s);\n", s);
}

/**
 *
 * @param
 * @return
 */
void
print_show_menu (char *mname, char *mhand)
{
  printh ("void aclfglmn_%s(char *);\n", mhand);
  printc ("aubit4gl_pl::show_menu(\"%s\",aclfglmn_%s);\n", mname, mhand);
}

/**
 *
 * @param
 * @return
 */
void
print_def_mn_file (void)
{
  printc ("aubit4gl_pl::push_char(\"menu\"); /* default menu file */\n");
}

/**
 *
 * @param
 * @return
 */
void
print_move_window (char *n, int rel)
{
  if (rel == 0)
    printc ("aubit4gl_pl::movewin(%s,1);", n);
  else
    printc ("aubit4gl_pl::movewin(%s,0);", n);
}

/*********** MENU *********/

/**
 *
 * @param
 * @return
 */
void
print_menu_1 (void)
{
  printc ("{my ($m);\n\nmy ($cmd_no);\n$cmd_no=-1;\n");
  printc ("while ($cmd_no!=-3) {\nMENU_WHILE_LABEL:\n");
}

/**
 *
 * @param
 * @return
 */
void
print_end_menu_1 (void)
{
  printc ("if ($cmd_no==-1) {\n");
  print_menu (menu_cnt);
  printc ("}\n");
}

/**
 *
 * @param
 * @return
 */
void
print_end_menu_2 (void)
{
  printc
    ("$cmd_no=aubit4gl_pl::menu_loop($m);\n}\naubit4gl_pl::free_menu($m);\n");
  printcomment ("/* end cwhile */\n");
  printcomment ("/* end menu */\n \n");
  printc ("}\n");
}

/**
 *
 * @param
 * @return
 */
void
print_menu_block (int n)
{
  printc (" if ($cmd_no==%d) {\n", n);
}

/**
 *
 * @param
 * @return
 */
void
print_menu_block_end (void)
{
  printc ("}\n");
}

/**
 *
 * @param
 * @return
 */
void
print_option_op (int type, char *n)
{
  if (type == 'N')
    printc ("aubit4gl_pl::next_option(m,%s);\n", n);
  if (type == 'S')
    printc ("aubit4gl_pl::menu_show(m,%s,0);\n", n);
  if (type == 'H')
    printc ("aubit4gl_pl::menu_show(m,%s,0);\n", n);
}

/**
 *
 * @param
 * @return
 */
void
print_at_termination (char *f)
{
  print_niy ("AT TERMINATION");
}

/**
 *
 * @param
 * @return
 */
void
print_func_start (char *isstatic, char *fname, int type)
{
  printc (" \n");
  printc (" \n");
  printc (" \n");
  if (type == 0)
    printc ("\nsub aclfgl_%s () { my $nargs=$_[0];\n", fname);
  if (type == 1)
    printc ("\nsub aclfglm_%s () { my $nargs=$_[0];\n", fname);
}

/**
 *
 * @param
 * @return
 */
void
print_func_args (int c)
{
  printc
    ("if ($nargs!=%d) {$aubit4gl_pl::status=-30174;aubit4gl_pl::pop_args($nargs);return 0;}\n",
     c, yylineno); printc ("aubit4gl_pl::pop_params(fbind,%d);\n", c);
}


/**
 *
 * @param
 * @return
 */
void
print_func_defret0 (void)
{
  printc ("return 0;\n");
}

/**
 *
 * @param
 * @return
 */
void
print_func_end (void)
{
  printc ("}\n");
}

/**
 *
 * @param
 * @return
 */
void
print_main_1 (void)
{
  printc ("\n\nsub a4gl_main() {\n");
}

/**
 *
 * @param
 * @return
 */
void
print_fgllib_start (char *db)
{
  printc ("\naubit4gl_pl::fgl_start(0,$ARGS);\n");
  if (db[0] != 0)
    {
      print_init_conn (db);
      printc
	("if ($aubit4gl_pl::sqlca_sqlcode<0) {aubit4gl_pl::chk_err(%d,aubit_module_name);}\n",
	 lastlineno);
    }
}

/**
 *
 * @param
 * @return
 */
void
print_main_end (void)
{
  printc ("aubit4gl_pl::fgl_end();\n}");
}

/**
 *
 * @param
 * @return
 */
void
print_return (int n)
{
  printc ("return %d;", n);
}

/**
 *
 * @param
 * @return
 */
void
print_options (char n, char *s)
{
  printc ("set_option_value('%c',%s);\n", n, s);
}

/**
 *
 * @param
 * @return
 */
void
print_set_helpfile (char *s)
{
  printc ("set_help_file(%s);\n", s);
}

/**
 *
 * @param
 * @return
 */
void
print_sql_commit (int t)
{
  printc ("commit_rollback(%d);\n", t);
}

/**
 *
 * @param
 * @return
 */
void
print_fetch_1 (void)
{
  printc ("{");
}

/**
 *
 * @param
 * @return
 */
void
print_fetch_2 (void)
{
  printc ("{");
}


/**
 *
 * @param
 * @return
 */
void
print_fetch_3 (char *ftp, char *into)
{
  printc ("fetch_cursor(%s,%s);}\n}\n", ftp, into);
}

/**
 *
 * @param
 * @return
 */
void
print_init_conn (char *db)
{
  if (db == 0)
    printc ("init_connection(char_pop());\n");
  else
    printc ("init_connection(\"%s\");\n", db);
}


/**
 *
 * @param
 * @return
 */
void
print_do_select (char *s)
{
  printc ("execute_implicit_select(%s);\n}\n", s);
}

/**
 *
 * @param
 * @return
 */
void
print_flush_cursor (char *s)
{
  printc ("flush_cursor(%s);\n\n", s);
}

/**
 *
 * @param
 * @return
 */
void
print_declare (char *a1, char *a2, char *a3, int h1, int h2)
{
  printc ("declare_cursor(%s+%d,%s,%d,%s);\n}\n", a1, h1, a2, h2, a3);
}

/**
 *
 * @param
 * @return
 */
char *
print_curr_spec (int type, char *s)
{
  static char buff[3000];
  printc ("{\n");
  if (type == 1)
    sprintf (buff, "prepare_sql(\"%s\")", s);
  if (type == 2)

    sprintf (buff, "find_prepare(%s)", s);
  return buff;
}


/**
 *
 * @param
 * @return
 */
char *
print_select_all (char *buff)
{
  int ni, no;
  static char b2[2000];
  printc ("{\n");
  ni = print_bind ('i');
  no = print_bind ('o');
  sprintf (b2, "prepare_select(ibind,%d,obind,%d,\"%s\")", ni, no, buff);
  return b2;
}



/**
 *
 * @param
 * @return
 */
void
print_unload (char *file, char *delim, char *sql)
{
  printc ("unload_data(%s,%s, /*1*/ \"%s\" /*2*/);\n", file, delim, sql);
}

/**
 *
 * @param
 * @return
 */
void
print_load (char *file, char *delim, char *tab, char *list)
{
  printc ("load_data(%s,%s,\"%s\",%s);\n", file, delim, tab, list);
}

/**
 *
 * @param
 * @return
 */
void
print_use_session (char *sess)
{
  printc ("{char _sav_cur_conn[32];\n");
  printc ("strcpy(_sav_cur_conn,get_curr_conn());\n");
  printc ("set_conn(%s);\n", sess);
}


/**
 *
 * @param
 * @return
 */
char *
get_undo_use (void)
{
  return "set_conn(_sav_cur_conn);}";
}


/**
 *
 * @param
 * @return
 */
void
print_next_form_field (char *form, char *field)
{
  print_niy ("NEXT FORM FIELD");
}

/************************************************************************/
/*                                     Ex mod.c stuff                   */
/************************************************************************/

/**
 *
 * @param
 * @return
 */
void
print_declare_associate_1 (char *variable, char *size, char *n)
{
  printc ("DEF_ASS (_usg%s,%s+1);\n", downshift (variable), size);
  printc
    ("#define ASSOCIATE_%s(w,rw) %s[ass_hash(_usg%s,%s+1,%s,w,sizeof(_usg%s),rw)]\n",
     upshift (variable), downshift (variable), downshift (variable),
     n, size, downshift (variable));
}

/**
 *
 * @param
 * @return
 */
void
print_declare_associate_2 (char *variable, char *size, char *n)
{
  printc
    ("#define ASSOCIATE_%s(w) %s[ass_hash(_usg%s,%s,%s+1,w,sizeof(_usg%s))]\n",
     upshift (variable), downshift (variable),
     downshift (variable), n, size, downshift (variable));
}



/**
 *
 * @param
 * @return
 */
void
print_define_char (char *var, int size, int isstatic_extern)
{
  /*
  if (isstatic_extern == 1)
  printc ("static ");
  if (isstatic_extern == 2)
  printc ("extern ");
  */
  if (!printing_record)
    {
      printc ("my $%s;\n", var, size);
    }
  else
    {
      printc ("%s => '$',\n", var, size);
    }

}

/**
 *
 * @param
 * @return
 */
void
print_define (char *varstring, int isstatic_extern)
{
  char dtype[32];
  char vname[32];
  /*
  if (isstatic_extern == 1)
  printc ("static ");
  if (isstatic_extern == 1)
  printc ("extern ");
  */
  sscanf (varstring, "%s %s", dtype, vname);
  if (!printing_record)
    printc ("my $%s;\n", vname);
  else
    printc ("%s => '$',\n", vname);
}

/**
 *
 * @param
 * @return
 */
void
print_start_record (int isstatic_extern, char *vname)
{
  printing_record++;
  /*
  if (isstatic_extern == 1)
  printc ("static ");
  if (isstatic_extern == 2)
  printc ("extern ");
  */
  printh ("struct a4glStruct_%s => {\n", vname);
}

/**
 *
 * @param
 * @return
 */
void
print_end_record (char *vname, int arrsize)
{
  printing_record--;
  if (arrsize == -1)
    {
      printc ("} \n", vname);
    }
  else
    {
      printc ("} %s[%d];\n", vname, arrsize);
    }

  printc ("my $vname=a4glStruct_%s->new();", vname);
}



/**
 *
 * @param
 * @return
 */
static void
print_menu (int mn)
{

  int a;
  int c;
  c = 0;
	/*
	Just so you all know...
	I really hate the way this does this - this will change to a menu item
	binding I think..
	*/
  for (a = 0; menu_stack[mn][a].menu_title[0] != 0 ||
       menu_stack[mn][a].menu_key[0] != 0 ||
       menu_stack[mn][a].menu_help[0] != 0; a++)
    c = a;
  printc ("$m=aubit4gl_pl::new_menu_create(%s,1,1,%d,0);\n", mmtitle[mn], 2);
  for (a = 0;
       menu_stack[mn][a].menu_title[0] != 0
       || menu_stack[mn][a].menu_key[0] != 0
       || menu_stack[mn][a].menu_help[0] != 0; a++)
    {
      printc ("aubit4gl_pl::add_menu_option($m, %s,%s,%s,%d,0);\n",
	      menu_stack[mn][a].menu_title,
	      menu_stack[mn][a].menu_key,
	      menu_stack[mn][a].menu_help, menu_stack[mn][a].menu_helpno);
    }

  printc
    ("aubit4gl_pl::finish_create_menu($m);\naubit4gl_pl::disp_h_menu($m);$cmd_no=-2;goto MENU_WHILE_LABEL;\n");
}

/**
 *
 * @param
 * @return
 */
char *
get_push_literal (char type, char *value)
{
  static char buff[80];
  if (type == 'D')
    {
      sprintf (buff, "aubit4gl_pl::push_double(%f);\n", atof (value));
    }

  if (type == 'L')
    {
      sprintf (buff, "aubit4gl_pl::push_long(%d);\n", atoi (value));
    }

  if (type == 'S')
    {
      sprintf (buff, "aubit4gl_pl::push_char(%s);\n", value);
    }
  return buff;
}

/**
 * FIXME: what is this?
 *
 * @param s
 */
char*
decode_array_string(char *s)
{
/*
static char buff[2000]="";
int a;
char tmp[2]="X"; // Just to get a terminator on it
strcpy(buff,"(");

	for (a=0;a<strlen(s);a++) {
		if (s[a]==',') {
			strcat(buff,")-1][(");
		} else {
			tmp[0]=s[a];
			strcat(buff,tmp);
		}
	}
	strcat(buff,")-1");
return buff;
*/

    exitwith ("decode_array_string not implemented");

    return 0;
}


/**
 * Print in the C generated code the change of the language file.
 *
 * Called by the parser when it founds the OPTIONS LANGUAGE FILE statement.
 *
 * @param s The help file name.
 */
void
print_set_langfile (char *s)
{
	/*  printc ("set_lang_file(%s);\n", s); */
    exitwith ("print_set_langfile not implemented");
}


/* =========== below: copied from print_c.c ===================== */


/**
 * Print comments to the C output file.
 *
 * If the output file is not opened call the open function.
 *
 * @param fmt the format to be passed to vsprintf
 * @param ... The variadic parameters to be passed to vsprintf
 */
static void
printcomment(char* fmt,... )
{
va_list ap;
	va_start(ap,fmt);
	internal_lex_printcomment(fmt,&ap);
}
void
/* internal_printcomment (char *fmt,...) */
internal_lex_printcomment(char *fmt, va_list *ap)
{

return;

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
 * If defined (as compiler option) print the C code for the call to the
 * initialization function to the calling stack.
 */
void printInitFunctionStack(void)
{
    return;

  if (!isGenStackInfo())
    return;
  printc("A4GLSTK_initFunctionCallStack();");

}


/**
 * If defined (as compiler option) print the C code for the call to the
 * declaration function to the calling stack.
 */
void printDeclareFunctionStack(char *_functionName)
{

  return;

  printf("Function %s\n",_functionName);
  if (isGenStackInfo())
    printc ("\nstatic char _functionName[] = \"%s\";\n",_functionName);
}


/**
 * If defined (as compiler option) print the C code for the call to the
 * push function to the calling stack.
 */
void printPushFunction(void)
{
  return;

  if (!isGenStackInfo())
    return;
  printc("A4GLSTK_pushFunction(_functionName,_paramnames,nargs);\n");
}

/**
 * Print the C C code to the call to the pop function of the calling stack.
 *
 * It only does it if defined as compiler option.
 */
void printPopFunction(void)
{
  return;

  if (!isGenStackInfo())
    return;
  printc("A4GLSTK_popFunction();\n");
}





/* ================================ EOF ============================== */


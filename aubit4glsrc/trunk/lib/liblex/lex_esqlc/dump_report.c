#include "a4gl_lib_lex_esqlc_int.h"
#define ONE_NOT_ZERO(x) (x?x:1)
#include "field_handling.h"
#include "compile_c.h"
#define set_nonewlines() set_nonewlines_full(__LINE__)
extern int tmp_ccnt;
static int report_cnt=0;
static int *ordbyfields = 0;
static int ordbyfieldscnt = 0;
extern int yylineno;



static int
gen_ord (int n)
{
  int a;

  if (ordbyfieldscnt==0) return n;

  for (a = 0; a < ordbyfieldscnt; a++)
    {
      if (n == ordbyfields[a])
        return a + 1;
    }

  return n;                     /* Fall back - shouldn't happen!!*/
}



/* Aggregate handling... */

static void
pr_nongroup_report_agg_clr (struct expr_str_list *aggregates)
{
  int z;
  int a;
  int t;
  int in_b;
  //char b[255];
  for (z = 0; z < aggregates->list.list_len; z++)
    {
      	struct s_expr_agg *agg;
	A4GL_assertion(aggregates->list.list_val[z]->expr_type!=ET_EXPR_AGGREGATE,"Expecting an aggregate");
	agg=aggregates->list.list_val[z]->expr_str_u.expr_agg;

      a = agg->expr_num;
      t = agg->agg_type;  
      //SPRINTF1(b,"%d",agg->blockid);

      in_b = gen_ord(agg->blockid);

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

          if (t == 'P') { printc ("_gpc%d=0;_g%d=0;\n", a, a); }
          if (t == 'A') { printc ("_gavg%d=0;_g%d=0;\n", a, a); }
        }
    }
}


/**
 *  * Prints the generated C code that implements the AFTER GROUP(s) actions
 *   */
static void
pr_report_agg (struct expr_str_list *aggregates)
{
  int z;
  int a;
  int t;
/*
 *   char s1[5024];
 *     char s2[5024];
 *     */


  for (z = 0; z < aggregates->list.list_len; z++)
    {
      	struct s_expr_agg *agg;
	A4GL_assertion(aggregates->list.list_val[z]->expr_type!=ET_EXPR_AGGREGATE,"Expecting an aggregate");
	agg=aggregates->list.list_val[z]->expr_str_u.expr_agg;

      a = agg->expr_num;
      t = agg->agg_type;  

      if (t == 'C') /* Count */
        { 
	  if (agg->expr_where) {
          	print_expr (agg->expr_where);
          	printc ("if (A4GL_pop_bool()) _g%d++;\n", a);
	  } else {
          	printc ("_g%d++;\n", a);
	  }
        }

      if (t == 'P') /* Percent */
        {
          printc ("_gpc%d++;", a );
	  
	  if (agg->expr_where) {
          	print_expr (agg->expr_where);
          	printc (" if (A4GL_pop_bool()) _g%d++; \n", a);
          } else {
          	printc ("_g%d++; \n", a);
		// Very odd - it'll always be 100%!
	  }
        }

      if (t == 'S') /* SUM */
        {
	  if (agg->expr_where) {
          	print_expr (agg->expr_where);
          	printc ("if (A4GL_pop_bool()) {");
          	print_expr (agg->agg_expr);
          	printc ("A4GL_set_agg('S',&_gt_%d,&_g%d,&_g%dused);",a,a,a);
          	printc("}");
	  } else {
          	print_expr (agg->agg_expr);
          	printc ("A4GL_set_agg('S',&_gt_%d,&_g%d,&_g%dused);",a,a,a);
	  }
        }

      if (t == 'A') /* Average */
        {
	  if (agg->expr_where) {
          	print_expr (agg->expr_where);
          	printc ("if (A4GL_pop_bool()) {");
          	print_expr (agg->agg_expr);
          	printc ("A4GL_set_agg('A',&_gt_%d,&_g%d,&_gavg%d);",a,a,a);
          	printc("}");
	  } else {
          	print_expr (agg->agg_expr);
          	printc ("A4GL_set_agg('A',&_gt_%d,&_g%d,&_gavg%d);",a,a,a);
	  }
        }

      if (t == 'N') /* Min */
        {
	  if (agg->expr_where) {
          	print_expr (agg->expr_where);
          	printc ("if (A4GL_pop_bool()) {");
          	print_expr (agg->agg_expr);
          	printc ("A4GL_set_agg('N',&_gt_%d,&_g%d,&_g%dused);",a,a,a);
          	printc("}");
          } else {
          	print_expr (agg->agg_expr);
          	printc ("A4GL_set_agg('N',&_gt_%d,&_g%d,&_g%dused);",a,a,a);
	  }

        }

      if (t == 'X') /* Max */
        {
	  if (agg->expr_where) {
          	print_expr (agg->expr_where);
          	printc ("if (A4GL_pop_bool()) {");
          	print_expr (agg->agg_expr);
          	printc ("A4GL_set_agg('X',&_gt_%d,&_g%d,&_g%dused);",a,a,a);
          	printc("}");
	} else {
          	print_expr (agg->agg_expr);
          	printc ("A4GL_set_agg('X',&_gt_%d,&_g%d,&_g%dused);",a,a,a);
	}
        }

    }
}


/**
 *  * Generate the C code to clear the report agregate conditions.
 *   */
static void
pr_report_agg_clr (struct expr_str_list *aggregates)
{
  int z;
  int a;
  int t;
  int in_b;
  //char b[255];
  for (z = 0; z < aggregates->list.list_len; z++)

    {
      	struct s_expr_agg *agg;
	A4GL_assertion(aggregates->list.list_val[z]->expr_type!=ET_EXPR_AGGREGATE,"Expecting an aggregate");
	agg=aggregates->list.list_val[z]->expr_str_u.expr_agg;
      a = agg->expr_num;
      t = agg->agg_type;  
      //SPRINTF1(b,"%d",agg->blockid);


      in_b = gen_ord (agg->blockid);
      if (in_b > 0)

        {
          printc ("if (_nargs==-%d&&acl_ctrl==REPORT_AFTERGROUP) {\n", in_b);

          if (t == 'C' || t == 'N' || t == 'X' || t == 'S')

            {
              if (t == 'C')
                {
                  printc ("_g%d=0;\n", a);
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
              printc ("_gpc%d=0;", a);
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


         //U pr_report_agg
         //U pr_report_agg_clr


/* 
If the report doesn't specify an explicit order by, there
may be an implicit one in the order that BEFORE GROUP/AFTER GROUPs were
added in the format section

We're going to use the fact that the _ordbind will contain all the variables,
and we have the variable numbers from the before and after groups.

If we copy the ordbind, then reassemble the ordbind using these - we should be ok again
*/

static void order_by_report_stack (int report_cnt, int rord_type, report_format_section *rf, struct s_report_orderby_section *report_orderby_section)
{
  //int a;
  static int fiddle = 0;


 if (rord_type!=REPORT_ORDERBY_IMPLICIT) return;



/* At this point we'll know if they used before/after groups */

/* We only want to do this if we haven't done it before... */
  printc ("if (acl_rep_ordcnt==-1) {");

  if (report_orderby_section->variables==0 || (report_orderby_section->variables && report_orderby_section->variables->list.list_len == 0))
    {
      printc ("acl_rep_ordcnt=0;");	/* Nothing to do - there isn't any...*/
    }
  else
    {
      /* Because of where this needs to go - we're going to shove a function
         into the header file we can call 
       */

      /* C File */
      printc ("acl_rep_ordcnt=%d; /* 1 */", report_orderby_section->variables->list.list_len);
      /* And assign the values*/
      fiddle++;
    }
  printc ("}");

}




/**
 * Print the C implementation of the current report control block
 */
static void
print_report_ctrl (int report_cnt, int rord_type, char *curr_rep_name,int rep_type, report_format_section *rf, struct s_report_orderby_section *report_orderby_section, struct expr_str_list *aggregates)
{
  int a;
  int printed_every;

#ifdef DEBUG
  A4GL_debug ("/* ********************************************************** */\n");
  A4GL_debug ("/*                 Report Control Block                       */\n");
  A4GL_debug ("/* ********************************************************** */\n");
#endif
  printc ("report%d_ctrl:\n", report_cnt);
  printc ("if (_rep.lines_in_header      ==-1) _rep.lines_in_header=%d;", rf->lines_in_header);
  printc ("if (_rep.lines_in_first_header==-1) _rep.lines_in_first_header=%d;", rf->lines_in_first_header);
  printc ("if (_rep.lines_in_trailer     ==-1) _rep.lines_in_trailer=%d;", rf->lines_in_trailer);


  order_by_report_stack (report_cnt, rord_type, rf, report_orderby_section);

  //printc ("A4GL_debug(\"ctrl=%%d _nargs=%%d\",acl_ctrl,_nargs);\n");
  printc ("    if (acl_ctrl==REPORT_OPS_COMPLETE) return;\n\n");
  printc ("    if (acl_ctrl==REPORT_SENDDATA) {\n");
  printc ("   /* check for after group of */\n");
  printc ("       %s(0,REPORT_DATA);\n", curr_rep_name );
  printc ("   /* check for before group of */\n");
  printc ("    }\n\n");


  printc ("if (acl_ctrl==REPORT_FINISH && _started==0) {");
  printc ("    A4GL_exitwith(\"You cannot FINISH REPORT - because the report has not been started\");");
  printc ("    return;\n");
  printc ("    }\n");
  printc ("if (acl_ctrl==REPORT_FINISH && _started) {%s(0,REPORT_LASTDATA);return;}\n", curr_rep_name);

  if (rep_type == REP_TYPE_NORMAL)
    {
      printc ("if (acl_ctrl==REPORT_LASTDATA) {");
      printc ("  if (_useddata || A4GL_always_output_report(&_rep)) {");

      printc ("   /*if (_useddata)*/ {%s(0,REPORT_LASTROW);}", curr_rep_name );

      printc ("   if (_rep.page_no<=1&&_rep.page_length>1 &&_rep.header ) {A4GL_rep_print(&_rep,0,1,0,-1);A4GL_rep_print(&_rep,0,0,0,-1);}");	/* MJA 13092003*/

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
	("if (acl_ctrl==REPORT_LASTDATA) {if (_useddata) %s(0,REPORT_LASTROW);", curr_rep_name);
	printc("        _rep.finishing=1; A4GL_pdf_skip_top_of_page(&_rep,999);");

	printc("_started=0;A4GL_pdf_rep_close(&_rep);return;}\n");

    }

  if (rep_type == REP_TYPE_NORMAL)
    {
      printc
	("if (acl_ctrl==REPORT_TERMINATE) {_started=0;if (_rep.output) {A4GL_close_report_file(&_rep);}return;}\n");
    }
  else
    {
      printc
	("if (acl_ctrl==REPORT_TERMINATE) {_started=0;A4GL_pdf_rep_close(&_rep);return;}\n" );

    }


  	printc ("    if (acl_ctrl==REPORT_AFTERDATA ) {\n");
  	pr_report_agg (aggregates);
  	printc ("    return;");
  	printc ("    }\n");


  printed_every=0;

  // We need to clear down any counters...
  printc(" if (acl_ctrl==REPORT_START||acl_ctrl==REPORT_RESTART) {");
pr_nongroup_report_agg_clr(aggregates);
  printc("}");


  for (a = 0; a < rf->entries.entries_len; a++)
    {
      if (rf->entries.entries_val [a]->rb_block.rb == RB_FIRST_PAGE_HEADER) // First page header - ensure its printed before the page header..
              printc ("if (acl_ctrl==REPORT_PAGEHEADER&&_rep.page_no==1) {acl_ctrl=0;goto rep_ctrl%d_%d;}\n", report_cnt, a);
    }



  for (a = 0; a < rf->entries.entries_len; a++)
    {
      /* on last row */

      if (rf->entries.entries_val  [a]->rb_block.rb == RB_ON_LAST_ROW)
	printc ("if (acl_ctrl==REPORT_LASTROW) { acl_ctrl=0;goto rep_ctrl%d_%d;}\n", report_cnt, a);

      /* on every row */
      if (rf->entries.entries_val  [a]->rb_block.rb == RB_ON_EVERY_ROW) {
	printed_every=1;
	printc ("if (acl_ctrl==REPORT_DATA) {acl_ctrl=REPORT_NOTHING; goto rep_ctrl%d_%d;}\n", report_cnt, a);
	}

      /* on every row */
      if (rf->entries.entries_val  [a]->rb_block.rb == RB_FORMAT_EVERY_ROW) {
	printed_every=1;
	printc ("if (acl_ctrl==REPORT_DATA) {acl_ctrl=REPORT_NOTHING; goto rep_ctrl%d_%d;}\n", report_cnt, a);
      }

      /* before group of */
      if (rf->entries.entries_val  [a]->rb_block.rb ==  RB_BEFORE_GROUP_OF)
	printc
	  ("if (acl_ctrl==REPORT_BEFOREGROUP&&_nargs==%d) {_nargs=-1*_nargs;goto rep_ctrl%d_%d;}\n",
	    (rf->entries.entries_val  [a]->orderby_var_no), report_cnt, a);

      /* after group of */
      if (rf->entries.entries_val  [a]->rb_block.rb == RB_AFTER_GROUP_OF)
	printc
	  ("if (acl_ctrl==REPORT_AFTERGROUP&&_nargs==%d) {_nargs=-1*_nargs;goto rep_ctrl%d_%d;}\n",
	    (rf->entries.entries_val  [a]->orderby_var_no), report_cnt, a);

      if (rf->entries.entries_val  [a]->rb_block.rb == RB_PAGE_TRAILER)
	printc
	  ("if (acl_ctrl==REPORT_PAGETRAILER) {acl_ctrl=0;goto rep_ctrl%d_%d;}\n",
	   report_cnt, a);


      if (rf->entries.entries_val  [a]->rb_block.rb == RB_PAGE_HEADER)
	printc
	  ("if (acl_ctrl==REPORT_PAGEHEADER&&(_rep.page_no!=1||(_rep.page_no==1&&_rep.has_first_page==0))) {acl_ctrl=0;goto rep_ctrl%d_%d;}\n",
	   report_cnt, a);
    }
	if (!printed_every) {
		printc ("if (acl_ctrl==REPORT_DATA) {acl_ctrl=REPORT_NOTHING;"); //goto rep_ctrl%d_%d;\n", report_cnt,0);
		print_rep_ret (report_cnt,0);
		printc("}");
	}
  pr_report_agg_clr (aggregates );
}




static void print_output_rep_pdf(struct pdf_startrep *rep, int report_cnt,char *namespaced_rep_name) {

struct pdf_startrep rep_default;


  if (rep==0) {
  	rep_default.top_margin_e = A4GL_new_literal_long_long( -36);
  	rep_default.bottom_margin_e =  A4GL_new_literal_long_long(-36);
  	rep_default.left_margin_e =  A4GL_new_literal_long_long(-36);
  	rep_default.page_length_e =  A4GL_new_literal_long_long(-842);    /* A4 */
  	rep_default.page_width_e =  A4GL_new_literal_long_long(-595);     /* A4 */
  	rep_default.right_margin_e =  A4GL_new_literal_long_long(-595+72); // rep_default.with_page_width - (2 * rep_default.with_left_margin);
  	rep_default.font_size = 10;
  	rep_default.paper_size = 0;
	rep_default.bluebar.style=E_BLUEBAR_NONE;
	rep_default.bluebar.r=0;
	rep_default.bluebar.g=0;
	rep_default.bluebar.b=0;

  	rep_default.font_name= "\"Helvetica\"";

        rep_default.towhat='F';
	rep_default.s1=A4GL_new_literal_string("stdout");
	rep=&rep_default;
  }





  printc ("output_%d:\n", report_cnt);
  printc("{");
  printc ("float _tm; float _bm; float _pw; float _pl; float _lm; float _rm;");
  print_expr(rep->top_margin_e);
  printc("_tm=A4GL_pop_float();");

  print_expr(rep->bottom_margin_e);
  printc("_bm=A4GL_pop_float();");

  print_expr(rep->page_width_e);
  printc("_pw=A4GL_pop_float();");

  print_expr(rep->page_length_e);
  printc("_pl=A4GL_pop_float();");

  print_expr(rep->left_margin_e);
  printc("_lm=A4GL_pop_float();");
  print_expr(rep->right_margin_e);
  printc("_rm=A4GL_pop_float();");

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
  printc ("_rep.rb_stack[0]=0;\n");
  printc ("_rep.rb_stack_level=0;\n");

  printc ("_rep.bluebar_r=%lf;\n",rep->bluebar.r);
  printc ("_rep.bluebar_g=%lf;\n",rep->bluebar.g);
  printc ("_rep.bluebar_b=%lf;\n",rep->bluebar.b);
  printc ("_rep.bluebar_style=%d;\n",rep->bluebar.style);

  printc ("_rep.repName=_reportName;\n");
  printc ("_rep.modName=_module_name;\n");

  printc ("_rep.top_margin=A4GL_pdf_size(_tm,'l',&_rep);\n");
  printc ("_rep.bottom_margin=A4GL_pdf_size(_bm,'l',&_rep);\n");
  printc ("_rep.page_length=A4GL_pdf_size(_pl,'l',&_rep);\n");
  printc ("_rep.left_margin=A4GL_pdf_size(_lm,'c',&_rep);\n");
  printc ("_rep.right_margin=A4GL_pdf_size(_rm,'c',&_rep);\n");
  printc ("_rep.page_width=A4GL_pdf_size(_pw,'c',&_rep);\n");

  printc ("_rep.page_no=0;\n");
  printc ("_rep.printed_page_no=0;\n");

  printc ("_rep.line_no=0;\n");
  printc ("_rep.col_no=0;\n");
  printc("}");


  printc ("if (strlen(_rout2)==0) {\n");
  if (rep->s1) {
  	printc ("char *_r;\n");
  	print_expr(rep->s1);
  	printc ("_r=A4GL_char_pop(); strcpy(_rep.output_loc_str,_r);free(_r);\n");
  } else {
  	printc ("strcpy(_rep.output_loc_str,\"\");\n");
  }
  printc ("} else {");
  printc ("     strcpy(_rep.output_loc_str,_rout2);\n");
  printc ("}");
  printc ("if (strlen(_rout1)==0){\n");
  printc ("_rep.output_mode='%c';\n", rep->towhat);
  printc ("} else {");
  printc ("_rep.output_mode=_rout1[0];\n");
  printc("}");







  printc ("_rep.report=(void *)&%s;\n", namespaced_rep_name);



  printc ("A4GL_trim(_rep.output_loc_str);");
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
static void print_output_rep_normal (struct startrep *rep, int report_cnt,char *namespaced_rep_name)
{
struct startrep rep_default;


	
  printc ("output_%d:\n", report_cnt);
  printc ("_rep.lines_in_header=-1;\n");
  printc ("_rep.lines_in_trailer=-1;\n");
  printc ("_rep.lines_in_first_header=-1;\n");
  printc ("_rep.print_section=0;\n");
  printc ("_rep.rb_stack[0]=0;\n");
  printc ("_rep.rb_stack_level=0;\n");

  if (rep==0) {  

        rep_default.towhat='F';
        rep_default.s1=A4GL_new_literal_string("stdout");
        rep_default.page_length_e=A4GL_new_literal_long_long(66);
        rep_default.left_margin_e=A4GL_new_literal_long_long(5);
        rep_default.right_margin_e=A4GL_new_literal_long_long(132);
        rep_default.top_margin_e=A4GL_new_literal_long_long(3);
        rep_default.bottom_margin_e=A4GL_new_literal_long_long(3);
        rep_default.top_of_page=0;
	rep=&rep_default;
  }


  printc("{");
  printc("long _pl; int _lm; int _rm; int _tm; int _bm;");
  print_expr( rep->page_length_e);
  printc("_pl=A4GL_pop_long();");

  print_expr( rep->left_margin_e);
  printc("_lm=A4GL_pop_long();");
  print_expr( rep->right_margin_e);
  printc("_rm=A4GL_pop_long();");
  print_expr( rep->top_margin_e);
  printc("_tm=A4GL_pop_long();");
  print_expr( rep->bottom_margin_e);
  printc("_bm=A4GL_pop_long();");

  printc ("_rep.top_margin= A4GL_set_report_dim_int(\"TOP MARGIN\",_tm);\n");
  printc ("_rep.bottom_margin= A4GL_set_report_dim_int(\"BOTTOM MARGIN\",_bm);\n");
  printc ("_rep.left_margin= A4GL_set_report_dim_int(\"LEFT MARGIN\",_lm);\n");
  printc ("_rep.right_margin= A4GL_set_report_dim_int(\"RIGHT MARGIN\",_rm);\n");
  printc ("_rep.page_length= A4GL_set_report_dim_int(\"PAGE LENGTH\",_pl);\n");

  if (rep->top_of_page &&strlen(rep->top_of_page)) {
	  printc ("strcpy(_rep.top_of_page, %s);", rep->top_of_page); 
  } else {
	  printc ("strcpy(_rep.top_of_page, \"\");"); 
  }

  printc ("_rep.header=0;\n");
  printc ("_rep.finishing=0;\n");
  printc ("_rep.nblocks=0;\n");
  printc ("_rep.blocks=0;\n");
  printc ("_rep.repName=_reportName;\n");
  printc ("_rep.modName=_module_name;\n");
  printc ("_rep.page_no=0;\n");
  printc ("_rep.printed_page_no=0;\n");
  printc ("_rep.line_no=0;\n");
  printc ("_rep.col_no=0;\n");
  printc("}");

  printc ("if (strlen(_rout2)==0) {\n");
  if (rep->s1) {
  	printc ("char *_r;\n");
  	print_expr(rep->s1);
  	printc ("_r=A4GL_char_pop(); strcpy(_rep.output_loc_str,_r);free(_r);\n");
  } else {
  	printc ("strcpy(_rep.output_loc_str,\"stdout\");\n");
  }
  printc ("} else {");
  printc ("     strcpy(_rep.output_loc_str,_rout2);\n");
  printc ("}");
  printc ("if (strlen(_rout1)==0){\n");
	if ( rep->towhat=='-') rep->towhat='F';
  printc ("_rep.output_mode='%c';\n", rep->towhat);
  printc ("} else {");
  printc ("_rep.output_mode=_rout1[0];\n");
  printc("}");

  if (A4GL_doing_pcode()) {
  	printc ("_rep.report=0;\n");
  } else {
  	printc ("_rep.report=(void *)&%s;\n", namespaced_rep_name );
  }
  printc ("A4GL_trim(_rep.output_loc_str);");
  printc ("A4GL_rep_print(&_rep,-1,-1,-1,-1);");

  printc ("goto report%d_ctrl; /* G1 */\n\n", report_cnt);
}





static char decode_whytype(report_block_data rb_block) {
switch (rb_block.rb) {
	case RB_FIRST_PAGE_HEADER:      return 'P';
        case RB_PAGE_HEADER:            return 'p';
        case RB_PAGE_TRAILER:           return 'T';
        case RB_ON_EVERY_ROW:           return 'E';
        case RB_ON_LAST_ROW:            return 'L';
        case RB_BEFORE_GROUP_OF:        return 'B';
        case RB_AFTER_GROUP_OF:         return 'A';
        case RB_FORMAT_EVERY_ROW:       return 'E';

}
A4GL_assertion(1,"Invalid");
return '-';
}

static char *decode_why(report_block_data rb_block,int varno) {
static char buff[256];
switch (rb_block.rb) {
	case RB_FIRST_PAGE_HEADER:      return "FIRST";
        case RB_PAGE_HEADER:            return "HEADER";
        case RB_PAGE_TRAILER:           return "TRAILER";
        case RB_ON_EVERY_ROW:           return "EVERY";
        case RB_ON_LAST_ROW:            return "LAST";
        case RB_FORMAT_EVERY_ROW:       return "EVERY";

        case RB_BEFORE_GROUP_OF:        
			sprintf(buff,"%d", varno+1);
			return buff;
        case RB_AFTER_GROUP_OF:         
			sprintf(buff,"%d", varno+1);
			return buff;

}

A4GL_assertion(1,"Invalid");
return "";

}

/**
 *  * The parser found the ON EVERY ROW instruction from reports.
 *   *
 *    * Generate the C implementation to the output file.
 *     */
static void
print_format_every_row (expr_str_list* bind,char *ispdf_str)
{

  if( bind==0) return;
  if(bind->list.list_len==0) return;
  printc ("{int _rr;for (_rr=0;_rr<%d;_rr++) {", bind->list.list_len);
  printc ("A4GL_push_char(_rbindvarname[_rr]);\n");
  printc ("A4GL_%srep_print(&_rep,1,1,0,-1); A4GL_push_long(19); A4GL_set_column(&_rep);A4GL_%srep_print(&_rep,1,1,0,-1); \n",ispdf_str,ispdf_str);
  printc ("A4GL_push_variable(_rbind[_rr].ptr,_rbind[_rr].dtype);");
  printc ("A4GL_%srep_print(&_rep,1,1,0,-1); A4GL_%srep_print(&_rep,0,0,0,-1);\n",ispdf_str,ispdf_str);
  printc ("}");
  printc ("A4GL_push_char(\" \");");
  printc ("A4GL_%srep_print(&_rep,1,1,0,-1); A4GL_%srep_print(&_rep,0,0,0,-1);",ispdf_str,ispdf_str);
  printc ("}");

}









static void
print_format_section (report_format_section * report_format_section, int report_cnt, int rep_type,expr_str_list *parameters)
{
  int a;
  char *ispdf_str;
  if (rep_type == REP_TYPE_NORMAL)
    {
      ispdf_str = "";
    }
  else
    {
      ispdf_str = "pdf_";
    }
  printcomment ("/* FORMAT SECTION */");

  for (a = 0; a < report_format_section->entries.entries_len; a++)
    {

      dump_comments (report_format_section->entries.entries_val[a]->lineno);
      printc ("#");
      printc ("rep_ctrl%d_%d:\n", report_cnt, a);
      clr_rep_print_entry ();
      tmp_ccnt++;
      printc ("A4GL_%spush_report_section(&_rep,_module_name,_reportName,%d,'%c',\"%s\",%d);", ispdf_str,
	      report_format_section->entries.entries_val[a]->lineno,
	      decode_whytype (report_format_section->entries.entries_val[a]->rb_block),
	      decode_why (report_format_section->entries.entries_val[a]->rb_block,
			  report_format_section->entries.entries_val[a]->orderby_var_no), a);



	if (report_format_section->entries.entries_val[a]->rb_block.rb==RB_FORMAT_EVERY_ROW) {
		printc("/* FORMAT EVERY ROW */");

		print_format_every_row(parameters, ispdf_str);

        } else {
      		dump_commands (report_format_section->entries.entries_val[a]->rep_sec_commands);
	}

      printc ("A4GL_%spop_report_section(&_rep,%d);", ispdf_str, a);
      printc ("goto report%d_ctrl; /* G1 */\n\n", report_cnt);
      tmp_ccnt--;
    }

}



static int dump_report_generic (char *namespace,char *funcname, int isstatic,int rep_type, 
expr_str_list *parameters,
struct variable_list *variables,
s_report_orderby_section *report_orderby_section, void *report_output_section , report_format_section *report_format_section, struct expr_str_list *aggregates

) {
int a;
int cnt;
int order_by_type=0;
char *asc_desc=NULL;
char namespaced_report_name[256];
int force_two_pass=0;



if (aggregates) {
	// Scan the aggregates and see if we need to force a two pass report
	// to calculate aggregates in the first pass - for display in the second.
	// This only applies to report wide (ie - non GROUP) aggregates..
	// when used anywhere except the "ON LAST ROW"
	//
	for (a=0;a< aggregates->list.list_len; a++) {
        struct s_expr_agg *agg;
        //int a;
        A4GL_assertion(aggregates->list.list_val[a]->expr_type!=ET_EXPR_AGGREGATE,"Expecting an aggregate");
        agg=aggregates->list.list_val[a]->expr_str_u.expr_agg;

	if (agg->in_group) continue;
	A4GL_assertion(agg->blockid_always <0 || agg->blockid_always>=report_format_section->entries.entries_len,"Invalid blockid");
	if (report_format_section->entries.entries_val[agg->blockid_always]->rb_block.rb==RB_ON_LAST_ROW) continue;
	force_two_pass=1;
	yylineno=agg->lineno;
	A4GL_warn("Use of non-group aggregate outside of ON LAST ROW block is not compatible");
	}
}


report_cnt++;

  clr_rep_print_entry();
  sprintf(namespaced_report_name,"%s%s", namespace, funcname);
  printc ("A4GL_REPORT void %s (int _nargs,int acl_ctrl) {\n", namespaced_report_name);

  printc("static char *_reportName=\"%s\";\n",funcname);
      add_function_to_header (funcname, namespace, 2, isstatic);

// print local variables...
//
      if (variables->variables.variables_len)
        {
          for (a = 0; a < variables->variables.variables_len; a++)
            {
              print_variable_new (variables->variables.variables_val[a], 'L', 0);
            }
        }
      printc ("#");

  dump_objdata(variables,1);


  A4GL_assertion(report_orderby_section==0, "No order by section (not even implicit)");
  if (report_orderby_section->variables) {
  	a=report_orderby_section->variables->list.list_len;
  	print_bind_dir_definition_g(report_orderby_section->variables,1,'O');
  } else {
	printc("static void *_ordbind;");
	a=0;
  }



  switch ( report_orderby_section->rord_type ) {
        case REPORT_ORDERBY_IMPLICIT: 	
  printc ("static int acl_rep_ordcnt=%d; // 1\n",a);
					order_by_type=2; break;
        case REPORT_ORDERBY_EXTERNAL: 	
  printc ("static int acl_rep_ordcnt=%d; // 2\n",a);
					order_by_type=2; break;
        case REPORT_ORDERBY: 		
  printc ("static int acl_rep_ordcnt=%d; // 3\n",a);
					order_by_type=1; break;
  }

  


  if (order_by_type==1) {
                printc ("static int fgl_rep_orderby=1;\n");
        } else {
                printc ("static int fgl_rep_orderby=2;\n"); // external - no further ordering required
  }


  if (rep_type == REP_TYPE_NORMAL) {
  	printc ("static struct rep_structure _rep;\n");
  } else {
    	printc ("static struct pdf_rep_structure _rep;\n");
  }
  printc ("static char _rout1[256];\n");
  printc ("static char _rout2[1024];\n");
  printc ("static int _useddata=0;\n");
  printc ("static int _started=0;\n");
  printc ("static void *_blobdata=0;\n");
  printc ("static int _assigned_ordbind=0;\n");

  cnt=print_param_g ('r',"report",parameters);
  tmp_ccnt++;

  if (!A4GL_doing_pcode()) {
      printc ("init_module_variables();");
  }
  printc(" if (_assigned_ordbind==0) { _assigned_ordbind=1;"); 
  if (report_orderby_section->variables) {
  	print_bind_set_value_g(report_orderby_section->variables,'O'); 
  }
  printc("}");
  printc("A4GL_register_module_objects(_reportName, _objData);");


  printc ("if (acl_ctrl==REPORT_SENDDATA&&_started==0&&fgl_rep_orderby!=1) {");
  printc ("    A4GL_exitwith(\"A report cannot accept data as it has not been started\");");
  printc ("    return;\n");
  printc ("    }\n");
  printc ("if (_nargs!=%d&&acl_ctrl==REPORT_SENDDATA) {", cnt);
  printc ("A4GL_fglerror(ERR_BADNOARGS,ABORT);A4GL_pop_args(_nargs);return ;}\n");
  printc ("if (acl_ctrl==REPORT_LASTDATA) {\n   int _p;\n"); printc ("   if (_useddata) {for (_p=acl_rep_ordcnt;_p>=1;_p--) %s(_p,REPORT_AFTERGROUP);}\n",
     namespaced_report_name);
  printc ("}\n");

  if (order_by_type == 1)
    {
      printc ("if (acl_ctrl==REPORT_SENDDATA&&fgl_rep_orderby==1) {");
      for (a = 0; a < cnt; a++)
	{
	  printc
	    ("A4GL_setnull(_rbind[%d].dtype,_rbind[%d].ptr,_rbind[%d].size);", a,
	     a, a);
	}
        printc ("A4GL_pop_params_and_save_blobs(_rbind,%d,&_blobdata);", cnt);
	if (report_orderby_section->variables) {
	asc_desc=malloc(report_orderby_section->variables->list.list_len+1);
	for (a=0;a<report_orderby_section->variables->list.list_len;a++) {
		asc_desc[a]=report_orderby_section->variables->list.list_val[a]->expr_str_u.expr_variable_usage_with_asc_desc->asc_desc;
	}
	asc_desc[a]=0;
	} else {
		asc_desc="";
	}
      print_report_table (funcname , 'R', cnt,asc_desc,parameters,report_orderby_section->variables);
      //printc("A4GL_dec_refcount(_objData);");
	printc("A4GL_copy_back_blobs(_blobdata,0);");
      printc ("return;");
      printc("}");
    }

  printc ("if (acl_ctrl==REPORT_SENDDATA) {\n");
  printc ("   int _g=0;int _p;\n");
  if (cnt) {
  printc ("   _g=A4GL_chk_params(_rbind,%d,_ordbind,acl_rep_ordcnt);\n", cnt);
  }
  printc
    ("   if (_g>0&&_useddata) {for (_p=acl_rep_ordcnt;_p>=_g;_p--) %s(_p,REPORT_AFTERGROUP);}\n", namespaced_report_name);
  printc ("   A4GL_pop_params_and_save_blobs(_rbind,%d,&_blobdata);\n", cnt);
  printc ("               %s(0,REPORT_AFTERDATA);", namespaced_report_name);
  printc ("   if (_useddata==0) {_g=1;}\n");
  printc ("   if (_g>0) {");
  if (rep_type == REP_TYPE_NORMAL) {
  	printc ("    A4GL_rep_print(&_rep,0,1,0,-1);\n"); // Mantis ID 573
  } else {
  	printc ("    A4GL_pdf_rep_print(&_rep,0,1,0,-1);\n" ); // Mantis ID 573
  }
  printc ("        _useddata=1;");
  printc ("        for (_p=_g;_p<=acl_rep_ordcnt;_p++) ");
  printc ("               %s(_p,REPORT_BEFOREGROUP);", namespaced_report_name);
  printc ("   }");
  printc ("   _useddata=1;\n");

  printc ("goto report%d_ctrl; /* G1 */\n\n", report_cnt);
  printc ("}\n\n");
  printc ("if (acl_ctrl==REPORT_FINISH) {\n");

  if (order_by_type == 1)
    {

      printc ("    if (fgl_rep_orderby==1) {\n");
      printc ("        struct BINDING *reread;\n");
      printc ("        fgl_rep_orderby=-1;\n");
      printc ("        A4GL_push_char(_rout1);\n");
      printc ("        A4GL_push_char(_rout2);\n");
      printc ("        %s(2,REPORT_RESTART);\n", namespaced_report_name );
      print_report_table (funcname , 'I', cnt,asc_desc,parameters,report_orderby_section->variables);
      print_report_table (funcname , 'F', cnt,asc_desc,parameters,report_orderby_section->variables);
      printc ("                    %s(%d,REPORT_SENDDATA);\n", namespaced_report_name, cnt);
      printc (" }");
      printc ("        %s(0,REPORT_FINISH);\n", namespaced_report_name);
	      print_report_table (funcname , 'E', cnt,asc_desc,parameters,report_orderby_section->variables);
      //printc("A4GL_dec_refcount(_objData);");
	printc("A4GL_copy_back_blobs(_blobdata,0);");
	      printc ("        return;");
	      printc ("    }\n");

	    }

	  printc ("}\n");



	  printc (" ");


  if (rep_type == REP_TYPE_NORMAL) {
  printc("if (acl_ctrl==REPORT_CONVERT) {");
  printc("char *_f; char *_o; char *_l; int _to_pipe; _l=A4GL_char_pop(); _o=A4GL_char_pop(); _f=A4GL_char_pop(); _to_pipe=A4GL_pop_int();\n");
  printc("A4GL_convert_report(&_rep,_f,_o,_l,_to_pipe);");
      //printc("A4GL_dec_refcount(_objData);");
	printc("A4GL_copy_back_blobs(_blobdata,0);");
  printc("return ;");
  printc("}");
  }


  if (rep_type == REP_TYPE_NORMAL) {
  printc("if (acl_ctrl==REPORT_FREE) {");
  printc("A4GL_free_report(&_rep);");
      //printc("A4GL_dec_refcount(_objData);");
	printc("A4GL_copy_back_blobs(_blobdata,0);");
  printc("return ;");
  printc("}");
  }


  printc ("if (acl_ctrl==REPORT_START||acl_ctrl==REPORT_RESTART) {\n");
  printc ("   A4GL_pop_char(_rout2,1023);A4GL_trim(_rout2);\n");
  printc ("   A4GL_pop_char(_rout1,254);A4GL_trim(_rout1);\n");
  if (order_by_type == 1)
    {
      printc ("   if (acl_ctrl==REPORT_START) {fgl_rep_orderby=1;}\n");
      printc ("   if (fgl_rep_orderby==1) {");
      print_report_table (funcname , 'M', cnt,asc_desc,parameters,report_orderby_section->variables);
      //printc("A4GL_dec_refcount(_objData);");
	printc("A4GL_copy_back_blobs(_blobdata,0);");
      printc ("       return;");
      printc ("   }\n");
    }


  printc ("   _useddata=0;\n");
  printc ("   _started=1;\n");
  printc ("goto output_%d;\n", report_cnt);
  printc ("}\n\n");

  printc ("goto report%d_ctrl; /* G1 */\n\n", report_cnt);

  if (rep_type == REP_TYPE_NORMAL) {
   	print_output_rep_normal (report_output_section, report_cnt, namespaced_report_name);
  } else {
    	print_output_rep_pdf (report_output_section, report_cnt, namespaced_report_name);
  }


  print_format_section(report_format_section,report_cnt,rep_type, parameters);

if (aggregates) {
int z;
  for (z = 0; z < aggregates->list.list_len; z++) {
        struct s_expr_agg *agg;
	char t;
	int a;
        A4GL_assertion(aggregates->list.list_val[z]->expr_type!=ET_EXPR_AGGREGATE,"Expecting an aggregate");
        agg=aggregates->list.list_val[z]->expr_str_u.expr_agg;
      	a = agg->expr_num;
      	t = agg->agg_type;
	
	 local_print_agg_defines(t,a);
  }
}
  print_report_ctrl (report_cnt, report_orderby_section->rord_type, namespaced_report_name,rep_type, report_format_section, report_orderby_section, aggregates);

  tmp_ccnt--;
      //printc("A4GL_dec_refcount(_objData);");
	printc("A4GL_copy_back_blobs(_blobdata,0);");
  printc ("\n} /* end of report */\n");
  return 1;
}








int dump_report (struct s_report_definition *report_definition) {
//int a;
//int cnt;
//int order_by_type;
//char *asc_desc;
expr_str_list *parameters;
//char namespaced_report_name[256];

parameters=expand_parameters(&report_definition->variables, report_definition->parameters);

return dump_report_generic (report_definition->n_namespace,report_definition->funcname, report_definition->function_type==E_FTYPE_STATIC, REP_TYPE_NORMAL,
parameters,
 &report_definition->variables,
report_definition->report_orderby_section, report_definition->report_output_section , report_definition->reportFormatSection, &report_definition->aggregates

);


}



int dump_pdf_report (struct s_pdf_report_definition *report_definition) {
expr_str_list *parameters;
parameters=expand_parameters(&report_definition->variables, report_definition->parameters);
return dump_report_generic (
			report_definition->n_namespace,report_definition->funcname, report_definition->function_type==E_FTYPE_STATIC, REP_TYPE_PDF,
			parameters, &report_definition->variables,
			report_definition->report_orderby_section, 
			report_definition->report_output_section , report_definition->reportFormatSection, &report_definition->aggregates

);

}



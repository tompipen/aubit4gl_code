#include <stdio.h>
#include <string.h>
#include "../../common/dataio/report.xs.h"
#include "a4gl_memhandling.h"
FILE *fout = 0;
int printing_agg_functions=0;
int compat=0; 			// Create a temp table so we can do report aggregates during the run like ace, rather
				// than use the SUM/COUNT etc in 4gl which give running totals..
int use_insert_cursor=0;  	// Use an insert cursor to insert into that temp table we're using for ACE compatibility
int format_section_is_last=0;
int batch_size=100;
/*
# 4GL code generator
#
#   This program will decompile an ace report (compiled using aace) to
#   the 4GL code required to generate the same report from 4GL
#   
#   Usage 
#     $ aace myreport.ace
#     $ aace_4gl myreport.aarc > myreport.4gl
#
# The generated report should be compatible with all the normal 4GL compilers
#
#
# (c) 2002 Aubit Computing Ltd
#
# NOTE : This code is not covered by the GPL and is not part of the core
#        Aubit4gl system or maintained by the Aubit4GL team.
#
#        If you wish to use this code the following condition applies :
#
#          You must NOT use this code or any code that is generated in any 
#          commercial application without prior consent of Aubit Computing Ltd
#
# For full details of the licensing terms - please contact Aubit Computing Ltd
#
*/

int lvl = 0;
struct report this_report;


char *replace_vars_sql (struct select_stmts *ptr);
char *reporderby = 0;

void decode_agg (int aggid);
void decode_block (struct commands *cmd);
void decode_compare (struct compare_expr *e);
void decode_complex (struct complex_expr *e);
void decode_expr (struct expr *e);
void decode_fcall (struct expr_call *e);
void decode_for (struct cmd_for *cmd);
void decode_if (struct cmd_if *cmd);
void decode_let (struct cmd_let *cmd);
void decode_list (struct expr_list *e);
void decode_need (struct cmd_need *cmd);
void decode_pause (struct cmd_pause *cmd);
void decode_print (struct cmd_print *cmd);
void decode_printfile (struct cmd_printfile *cmd);
void decode_simple (struct simple_expr *e);
void decode_skip (struct cmd_skip *cmd);
void decode_while (struct cmd_while *cmd);
void dump_ascii (void);
void dump_command (struct command *cmd);
void dump_commands (struct commands *cmd);
void dump_format (void);
void dump_functions (void);
void dump_getdata (void);
void dump_output (void);
void dump_report (void);
void print_inputs (void);
void print_lvl (void);
void print_set_params (void);
void print_variable (int a, struct expr *e1, struct expr *e2);
void print_variables (int class, int inrec);
char *generate_order_by (struct select_stmts *ptr);
char *decode_op (int op);
void decode_call (struct cmd_call *cmd);
void decode_column (struct format *f);
int A4GL_read_data_from_file (char *datatype, void *ptr, char *filename);
char *trans (char *s);
void A4GL_make_downshift(char* s);
static void print_aggs(void) ;
static int need_print_aggs(void) ;

void *A4GL_build_user_resources (void);

static char *
downshift (char *s)
{
  static char buff[256];
  strcpy (buff, s);
  A4GL_make_downshift (buff);
  return buff;
}

int
main (int argc, char *argv[])
{
  /*FILE *f; */
  int a;
  int *used;
  int nused;
  char *name_param;
  fout = stdout;
  used=malloc(sizeof(int)*argc);
  for (a=0;a<argc;a++) {
		used[a]=0;
	}
  used[0]=1;

  if (argc>2) {
	for (a=1;a<argc-1;a++) {
		if (strcmp(argv[a],"-o")==0) {
			used[a]=1;
			used[a+1]=1;
			fout=fopen(argv[a+1],"w");
			a++;
			continue;
		}
		if (strcmp(argv[a],"-B")==0) {
			used[a]=1;
			used[a+1]=1;
			batch_size=atoi(argv[a+1]);
			if (batch_size<=0) {
				fprintf(stderr,"Batch size must be a positive integer\n");
				exit(3);
			}
			a++;
			continue;
		}

		if (strcmp(argv[a],"-C")==0) {
			used[a]=1;
			compat++;
			continue;
		}

		if (strcmp(argv[a],"-I")==0) {
			used[a]=1;
			use_insert_cursor++;
			continue;
		}

		if (strcmp(argv[a],"-CI")==0) {
			used[a]=1;
			compat++;
			use_insert_cursor++;
			continue;
		}
	}
  } 



  nused=0;
  for (a=0;a<argc;a++) {
	if (used[a]==0) nused++;
  }
  if (nused != 1)
    {
      fprintf (stderr, "Usage %s [options] filename [-o output] ( Where filename is a compile report eg. simple.aarc )\n", argv[0]);
	fprintf(stderr,"    options :  -C  ACE Aggregate compatibilty mode\n");
	fprintf(stderr,"               -C -I  Use INSERT cursor for compatibilty mode\n");
	fprintf(stderr,"                         (required Transaction logging\n");
	fprintf(stderr,"               -C -I -B n  Batch into 'n' inserts per transaction\n");

      exit (0);
    }

  for (a=1;a<argc;a++) {
	if (used[a]==0) name_param=argv[a];
  }

  A4GL_build_user_resources ();

  memset (&this_report, 0, sizeof (struct report));

  a = A4GL_read_data_from_file ("report", &this_report, name_param);

  if (!a)
    {
      fprintf (stderr, "Bad format\n");
      exit (1);
    }


  if (!need_print_aggs()) compat=0;

  if (compat==0) use_insert_cursor=0; // cant use_insert_cursor if not compatible mode...

  dump_report ();
  exit (0);
}



char *
generate_order_by (struct select_stmts *ptr)
{
  static char buff[10000];
  int a;
  int b;

  if (ptr->orderby_list.orderby_list_len == 0)
    {
      strcpy (buff, "");
      return buff;
    }
  strcpy (buff, "ORDER EXTERNAL BY\n");
  
  for (a = 0; a < ptr->orderby_list.orderby_list_len; a++)
    {
      b = ptr->orderby_list.orderby_list_val[a];
      if (b<0) {
		fprintf(stderr,"***************************************************\n");
		fprintf(stderr,"ERROR : Unable to get variable from orderby list\n");
		fprintf(stderr,"Using subscripts in the order by can cause this...\n");
		fprintf(stderr,"***************************************************\n");
		exit(30);
	}
      if (a)
	strcat (buff, ",\n");
      strcat (buff, "  lr_data.");
      strcat (buff, this_report.variables.variables_val[b].name);
    }
  reporderby = buff;
  return buff;
}


void
dump_report ()
{

  fprintf (fout, "GLOBALS \"global.4gl\"\n");
  fprintf (fout, "# PARAM\n");
  print_variables (CAT_PARAM, 0);
  fprintf (fout, "# VARIABLE\n");
  print_variables (CAT_VARIABLE, 0);
  fprintf (fout, "\n");
  fprintf (fout, "MAIN\n");
  fprintf (fout, "DEFINE lr_data RECORD\n");
  print_variables (CAT_SQL, 1);
  fprintf (fout, "END RECORD\n");
  fprintf (fout, "DEFINE lv_rid INTEGER\n");
  fprintf (fout, "DEFINE lv_cnt INTEGER\n");
//  print_variables (CAT_PARAM, 0);
//  print_variables (CAT_VARIABLE, 0);
  fprintf (fout, "\n");
  fprintf (fout, "  IF NOT job_init() THEN\n");
  fprintf (fout, "    EXIT PROGRAM\n");
  fprintf (fout, "  END IF\n");
  fprintf (fout, "\n");
  fprintf (fout, "# start of initialisation\n");
  fprintf (fout,"  LET lv_cnt=0\n");

  if (compat) {
        fprintf(fout,"  WHENEVER ERROR CONTINUE\n");
        fprintf(fout,"  DROP TABLE tmp_data\n");
        fprintf(fout,"  CREATE TEMP TABLE tmp_data (\n");
        fprintf(fout,"   a4gl_rid INTEGER,\n");
        print_variables (CAT_SQL, 1);
        fprintf(fout,") WITH NO LOG\n");

        if (use_insert_cursor) {
                fprintf(fout,"  DECLARE c_i_%s CURSOR WITH HOLD FOR INSERT INTO tmp_data VALUES(lv_rid, lr_data.*)\n", this_report.report_name);
        }

        fprintf(fout,"  DECLARE c_t_%s CURSOR FOR SELECT * FROM tmp_data ORDER BY a4gl_rid\n", this_report.report_name);
        fprintf(fout,"  WHENEVER ERROR STOP\n");
  }

  print_set_params ();
  print_inputs ();
  fprintf (fout, "# end of initialisation\n");
  fprintf (fout, "\n");
  dump_getdata ();
  fprintf (fout, "\n");
  fprintf (fout, "  CALL job_prnt()\n");
  fprintf (fout, "END MAIN\n");
  fprintf (fout, "\n");

  fprintf (fout, "REPORT rep_%s(lr_data)\n", this_report.report_name);
  fprintf (fout, "DEFINE lr_data RECORD\n");
  print_variables (CAT_SQL, 1);
  fprintf (fout, "END RECORD\n");
  fprintf (fout, "\n");
  dump_output ();
  fprintf (fout, "\n");
  fprintf (fout, "\n");
  dump_format ();
  fprintf (fout, "\nEND REPORT\n\n");
  if (compat) print_aggs() ;
}


void
dump_ascii ()
{
  fprintf (stderr, "Dump Ascii not implemented\n");
}

void
dump_functions ()
{
  int a;
  fprintf (stderr,"Functions\n");
  fprintf (stderr,"---------\n");
  for (a = 0; a < this_report.functions.functions_len; a++)
    {
      fprintf (stderr,"Function : %s\n", this_report.functions.functions_val[a].name);

    }
}

void
print_variables (int class, int inrec)
{
  int a;
  int k = 0;

  for (a = 0; a < this_report.variables.variables_len; a++)
    {
      if (this_report.variables.variables_val[a].category == class)
	{

	  if (k && inrec)
	    fprintf (fout, ",\n");

	  if (inrec)
	    fprintf (fout, "   ");
	  else
	    fprintf (fout, "DEFINE ");


	  if (inrec)
	    {
	      fprintf (fout, "%s %s",
		      this_report.variables.variables_val[a].name,
		      this_report.variables.variables_val[a].datatype_string);
	    }
	  else
	    {
	      fprintf (fout, "mv_%s %s",
		      this_report.variables.variables_val[a].name,
		      this_report.variables.variables_val[a].datatype_string);
	    }

	  k++;
	  if (!inrec)
	    fprintf (fout, "\n");
	}

    }
  if (inrec)
    fprintf (fout, "\n");
}


void
print_set_params ()
{
  int a;
  for (a = 0; a < this_report.variables.variables_len; a++)
    {
      if (this_report.variables.variables_val[a].category == CAT_PARAM)
	fprintf (fout, "LET mv_%s=arg_val(%d)\n",
		this_report.variables.variables_val[a].name,
		this_report.variables.variables_val[a].param_no);

    }
}


void
print_inputs ()
{
  int a;
  for (a = 0; a < this_report.inputs.inputs_len; a++)
    {
      fprintf (fout, "PROMPT \"%s\" FOR ", this_report.inputs.inputs_val[a].prompt);
      print_variable (this_report.inputs.inputs_val[a].varid, NULL, NULL);
      fprintf (fout, "\n");
    }
}



void
dump_output ()
{




  fprintf (fout, "OUTPUT\n");
  fprintf
    (fout, "  TOP MARGIN %d\n  BOTTOM MARGIN %d\n  LEFT MARGIN %d\n  RIGHT MARGIN %d\n",
     this_report.output.top_margin, this_report.output.bottom_margin,
     this_report.output.left_margin, this_report.output.right_margin);
  fprintf (fout, "  PAGE LENGTH %d\n", this_report.output.page_length);

  if (this_report.output.top_of_page
      && strlen (this_report.output.top_of_page))
    {
      fprintf (fout, "  TOP OF PAGE \"%s\"\n", this_report.output.top_of_page);
    }

  if (this_report.output.report_to_where == 1)
    fprintf (fout, " REPORT TO PRINTER");
  if (this_report.output.report_to_where == 2)
    fprintf (fout, " REPORT TO PIPE %s\n", this_report.output.report_to_filename);
  if (this_report.output.report_to_where == 3)
    fprintf (fout, " REPORT TO \"%s\"\n", this_report.output.report_to_filename);

  if (reporderby)
    {
      fprintf (fout, "\n%s\n", reporderby);
    }
}


void
dump_getdata ()
{
  int a;
  /*int b; */

  struct select_stmts *ptr;

  if (this_report.getdata.select_or_read == 0)
    {
      for (a = 0; a < this_report.getdata.get_data_u.selects.selects_len; a++)
	{
	  ptr = &this_report.getdata.get_data_u.selects.selects_val[a];


	  if (a == this_report.getdata.get_data_u.selects.selects_len - 1)
	    {
	      fprintf (fout, "  DECLARE c_%s CURSOR ",this_report.report_name);
		if (use_insert_cursor) {
			fprintf(fout," WITH HOLD ");
		} 
	      fprintf (fout, "FOR\n   %s\n\n", replace_vars_sql (ptr));
	      generate_order_by (ptr);
	    }
	  else
	    {
	      if (strlen (ptr->temp_tab_name))
		{
		  fprintf
		    (fout, "WHENEVER ERROR CONTINUE\nDROP TABLE %s\nLET status=0\nLET sqlca.sqlcode=0\nWHENEVER ERROR STOP\n",
		     ptr->temp_tab_name);
		}
	      fprintf (fout, "%s\n", replace_vars_sql (ptr));
	    }


	}
      fprintf (fout, "  START REPORT rep_%s\n\n", this_report.report_name);
      if (!compat) {
      		fprintf (fout, "  FOREACH c_%s INTO lr_data.*\n", this_report.report_name);
      		fprintf (fout, "    OUTPUT TO REPORT rep_%s (lr_data.*)\n", this_report.report_name);
      		fprintf (fout, "  END FOREACH\n\n");
      } else {
      		fprintf (fout, "# For compatibility mode - we need to create a full copy of our data...\n\n");
		if (use_insert_cursor) {
  			fprintf(fout,"BEGIN WORK\n");
  			fprintf(fout,"OPEN c_i_%s\n", this_report.report_name);
		}
      		fprintf (fout, "LET lv_rid=0\n");
      		fprintf (fout, "FOREACH c_r_%s INTO lr_data.*\n", this_report.report_name);
		if (use_insert_cursor) {
  			fprintf(fout,  "   LET lv_cnt=lv_cnt+1\n");
			if (batch_size<100000) { // If its more than this - don't batch it at all...
  				fprintf(fout,  "  IF lv_cnt>%d THEN # Batches of %d\n    LET lv_cnt=0\n    COMMIT WORK\n    BEGIN WORK\n  END IF\n",batch_size,batch_size);
			}
      			fprintf (fout, "   PUT c_i_%s\n", this_report.report_name);
		} else {
      			fprintf (fout, "   INSERT INTO tmp_data VALUES(lv_rid, lr_data.*)\n");
		}
      		fprintf (fout, "   LET lv_rid=lv_rid+1\n");
      		fprintf (fout, "END FOREACH\n");
		if (use_insert_cursor) {
  			fprintf(fout,"CLOSE c_i_%s\n", this_report.report_name);
			fprintf(fout,"COMMIT WORK\n");
		}
      		fprintf (fout, "\n");
      		fprintf (fout, "# we can now read our data (again) to generate the report\n\n");
      		fprintf (fout, "FOREACH c_t_%s INTO lv_rid, lr_data.*\n", this_report.report_name);
      		fprintf (fout, "  OUTPUT TO REPORT rep_%s (lr_data.*)\n", this_report.report_name);
      		fprintf (fout, "END FOREACH\n");
      }
      fprintf (fout, "  FINISH REPORT rep_%s\n", this_report.report_name);
//      fprintf (fout, "END FUNCTION\n\n");
    }
  else
    {
      fprintf (stderr, "Using Read statement\n");
      fprintf (stderr, "Dump NIY\n");
      exit (2);
    }
}



void
print_lvl ()
{
  int a;
  for (a = 0; a < lvl; a++)
    {
      fprintf (fout, "   ");
    }
}



char *
decode_op (int op)
{
  switch (op)
    {
    case EXPR_AND:
      return "AND";
    case EXPR_OR:
      return "OR";
    case EXPR_ADD:
      return "+";
    case EXPR_SUB:
      return "-";
    case EXPR_MUL:
      return "*";
    case EXPR_DIV:
      return "/";
    case EXPR_POW:
      return "**";

    case EXPR_CLIP:
      return "CLIPPED";
    case EXPR_USING:
      return "USING";

    case EXPR_COLUMN:
      return "COLUMN";

    case EXPR_ASCII:
      return "ASCII";

    case EXPR_SPACES:
      return "SPACES";
    case EXPR_CONCAT:
      return ",";
    case EXPR_ISNULL:
      return "IS NULL";
    case EXPR_ISNOTNULL:
      return "IS NOT NULL";
    }

  return "Dont know(?!)";

}

void
decode_complex (struct complex_expr *e)
{
  if (e->operand != EXPR_CONCAT)
    fprintf (fout, "(");
  decode_expr (&e->expr1);
  fprintf (fout, " %s ", decode_op (e->operand));

  decode_expr (&e->expr2);

  if (e->operand != EXPR_CONCAT)
    fprintf (fout, ")");
}


void
decode_compare (struct compare_expr *e)
{
  fprintf (fout, "(");
  decode_expr (&e->expr1);
  fprintf (fout, "%s", e->method);
  decode_expr (&e->expr2);
  fprintf (fout, ")");
}

void
decode_simple (struct simple_expr *e)
{
  if (e->operand == EXPR_CLIP || e->operand == EXPR_SPACES
      || e->operand == EXPR_ISNULL || e->operand == EXPR_ISNOTNULL)
    {
      decode_expr (&e->expr);
      fprintf (fout, " %s ", decode_op (e->operand));
    }
  else
    {
      if (e->operand == EXPR_COLUMN || e->operand == EXPR_ASCII)
	{
	  fprintf (fout, " %s ", decode_op (e->operand));
	  decode_expr (&e->expr);
	}
      else
	{
	  fprintf (fout, " %s ", decode_op (e->operand));
	  decode_expr (&e->expr);
	}
    }
}



static void
decode_agg_compat (int aggid)
{
  fprintf(fout,"agg_%d()", aggid);
}


static int need_print_aggs(void) {
int a;
for (a=0;a<this_report.aggs.aggs_len;a++) {
int fmt;
  // we dont care about BEFORE/AFTER GROUP OF
  if (this_report.aggs.aggs_val[a].isgroup) continue;

  // we dont care about ON LAST ROW either...
  fmt=this_report.aggs.aggs_val[a].format_id;
  if (this_report.fmt.fmt_val[fmt].category==FORMAT_ON_LAST_ROW) continue;

  return 1;
}
return 0;
}


static void print_aggs(void) {
int a;
printing_agg_functions=1;
for (a=0;a<this_report.aggs.aggs_len;a++) {
  if (this_report.aggs.aggs_val[a].isgroup) continue;

  fprintf(fout,"\n\nFUNCTION agg_%d()\n", a);
  switch (this_report.aggs.aggs_val[a].type)
    {
    case AGG_COUNT: 	fprintf(fout,"DEFINE lv_var INTEGER\n"); break;
    case AGG_AVG:
    case AGG_TOTAL:
    case AGG_PERCENT: 	fprintf(fout,"DEFINE lv_var FLOAT\n"); break;

    case AGG_MIN:
    case AGG_MAX:
    default: 		fprintf(fout,"DEFINE lv_var VARCHAR(256)\n"); break;
    }

  fprintf(fout, "SELECT ");

  switch (this_report.aggs.aggs_val[a].type)
    {
    case AGG_COUNT:
      fprintf (fout, "COUNT(*)");
      break;
    case AGG_PERCENT:
      fprintf (fout, "PERCENT(*) ");
      break;

    case AGG_AVG:
      fprintf (fout, "AVERAGE(");
      decode_expr (this_report.aggs.aggs_val[a].expr);
      fprintf (fout, ")");
      break;
    case AGG_TOTAL:
      fprintf (fout, "SUM(");
      decode_expr (this_report.aggs.aggs_val[a].expr);
      fprintf (fout, ")");
      break;
    case AGG_MIN:
      fprintf (fout, "MIN(");
      decode_expr (this_report.aggs.aggs_val[a].expr);
      fprintf (fout, ")");
      break;
    case AGG_MAX:
      fprintf (fout, "MAX(");
      decode_expr (this_report.aggs.aggs_val[a].expr);
      fprintf (fout, ")");
      break;
    }
  
  fprintf (fout, "\nINTO lv_var FROM tmp_data ");

  if (this_report.aggs.aggs_val[a].wexpr)
   {
      fprintf (fout, " WHERE ");
      decode_expr (this_report.aggs.aggs_val[a].wexpr);
   }
   fprintf(fout,"\n");
   fprintf(fout,"RETURN lv_var\n");
   fprintf(fout,"END FUNCTION\n");
}

printing_agg_functions=0;
}


static void
decode_agg_notcompat (int aggid)
{
  /*this_report.aggs.aggs_val[aggid]. */
  if (this_report.aggs.aggs_val[aggid].isgroup)
    {
      fprintf (fout, " GROUP ");
    }


  switch (this_report.aggs.aggs_val[aggid].type)
    {
    case AGG_COUNT:

      fprintf (fout, "COUNT(*)");
      break;
    case AGG_PERCENT:
      fprintf (fout, "PERCENT(*) ");
      break;

    case AGG_AVG:
      fprintf (fout, "AVERAGE(");
      decode_expr (this_report.aggs.aggs_val[aggid].expr);
      fprintf (fout, ")");
      break;
    case AGG_TOTAL:
      fprintf (fout, "SUM(");
      decode_expr (this_report.aggs.aggs_val[aggid].expr);
      fprintf (fout, ")");
      break;
    case AGG_MIN:
      fprintf (fout, "MIN(");
      decode_expr (this_report.aggs.aggs_val[aggid].expr);
      fprintf (fout, ")");
      break;
    case AGG_MAX:
      fprintf (fout, "MAX(");
      decode_expr (this_report.aggs.aggs_val[aggid].expr);
      fprintf (fout, ")");
      break;
    }

  if (this_report.aggs.aggs_val[aggid].wexpr)
    {
      fprintf (fout, " WHERE ");
      decode_expr (this_report.aggs.aggs_val[aggid].wexpr);
    }

}


void decode_agg (int aggid) {
	if (compat) {
		 if (! this_report.aggs.aggs_val[aggid].isgroup)  {
			decode_agg_compat(aggid);
		} else {
			decode_agg_notcompat(aggid);
		}
	} else {
		if (need_print_aggs()) {
			if (this_report.aggs.aggs_val[aggid].isgroup==0) {
               			fprintf(stderr,"WARNING: Use of non-'GROUP' aggregates behaves differently in ACE and 4GL\n");
               			fprintf(stderr,"         unless used in an ON LAST ROW\n");
				fprintf(stderr,"Use -C option to force compatibility\n");
			}
		}
		decode_agg_notcompat(aggid);
	}
}


void
decode_list (struct expr_list *e)
{
  int a;
  for (a = 0; a < e->elem.elem_len; a++)
    {
      if (a)
	fprintf (fout, ", ");
      decode_expr (&e->elem.elem_val[a]);
    }
}

void
decode_fcall (struct expr_call *e)
{
  fprintf (fout," %s(", e->fname);
  decode_list (e->lexpr);
  fprintf (fout,")");
}

void
decode_expr (struct expr *e)
{
  switch (e->type)
    {

    case EXPRTYPE_INT:
      fprintf (fout,"%d", e->expr_u.i);
      break;

    case EXPRTYPE_DOUBLE:
      fprintf (fout,"%f", e->expr_u.d);
      break;

    case EXPRTYPE_STRING:
      fprintf (fout,"\"%s\"", trans (e->expr_u.s));
      break;

    case EXPRTYPE_VARIABLE:
      print_variable (e->expr_u.varid, 0, 0);
      break;

    case EXPRTYPE_VARIABLE_SUB:
      print_variable (e->expr_u.var_usage->varid,
		      e->expr_u.var_usage->subscript1,
		      e->expr_u.var_usage->subscript2);
      break;

    case EXPRTYPE_BUILTIN:
      fprintf (fout,"%s", e->expr_u.name);
      break;

    case EXPRTYPE_COMPLEX:
      decode_complex (e->expr_u.expr);
      break;

    case EXPRTYPE_COMPARE:
      decode_compare (e->expr_u.cexpr);
      break;

    case EXPRTYPE_SIMPLE:
      decode_simple (e->expr_u.sexpr);
      break;

    case EXPRTYPE_LIST:
      decode_list (e->expr_u.lexpr);
      break;

    case EXPRTYPE_FCALL:
      decode_fcall (e->expr_u.fcall);
      break;

    case EXPRTYPE_AGG:
      decode_agg (e->expr_u.aggid);
      break;

    case EXPRTYPE_NULL:
      decode_fcall (e->expr_u.fcall);
      break;
    }

}

void
decode_for (struct cmd_for *cmd)
{
  fprintf (fout,"FOR ");
  print_variable (cmd->varid, NULL, NULL);
  fprintf (fout," = ");
  decode_expr (&cmd->start);
  fprintf (fout," TO ");
  decode_expr (&cmd->finish);
  fprintf (fout," STEP ");
  decode_expr (&cmd->step);
  fprintf (fout,"\n");
  lvl++;
  dump_command (cmd->command);
  lvl--;
  print_lvl ();
  fprintf (fout,"END FOR\n\n");
}

void
decode_if (struct cmd_if *cmd)
{
  fprintf (fout,"IF ");
  /*printf (""); */
  decode_expr (&cmd->condition);
  fprintf (fout," THEN \n");
  lvl++;
  dump_command (cmd->command);
  lvl--;
  if (cmd->elsecommand->cmd_type != CMD_NULL)
    {
      print_lvl ();
      fprintf (fout," ELSE \n");
      lvl++;
      dump_command (cmd->elsecommand);
      lvl--;
    }
  print_lvl ();
  fprintf (fout,"END IF\n\n");
}

void
decode_while (struct cmd_while *cmd)
{
  fprintf (fout,"WHILE ");
  decode_expr (&cmd->condition);
  fprintf (fout,"\n");
  lvl++;
  dump_command (cmd->command);
  lvl--;
  print_lvl ();
  fprintf (fout,"END WHILE\n\n");
}


void
decode_let (struct cmd_let *cmd)
{
  fprintf (fout,"LET ");
  print_variable (cmd->varid, NULL, NULL);
  if (cmd->sub1)
    {
      fprintf (fout,"[");
      decode_expr (cmd->sub1);
      if (cmd->sub2)
	{
	  fprintf (fout,",");
	  decode_expr (cmd->sub2);
	}
      fprintf (fout,"]");
    }
  fprintf (fout,"=");
  decode_expr (cmd->value);
  fprintf (fout,"\n");
}

void
decode_need (struct cmd_need *cmd)
{
  fprintf (fout,"NEED %d LINES\n", cmd->nlines);
}


void
decode_pause (struct cmd_pause *cmd)
{
  fprintf (fout,"PAUSE \"%s\"\n", cmd->message);
}


void
decode_skip (struct cmd_skip *cmd)
{
  if (cmd->nlines < 0)
    fprintf (fout,"SKIP TO TOP OF PAGE\n");
  else
    fprintf (fout,"SKIP %d LINES\n", cmd->nlines);
}


void
decode_print (struct cmd_print *cmd)
{
  fprintf (fout,"PRINT ");
  decode_expr (&cmd->print);
  if (cmd->printnl == 0)
    fprintf (fout,";");
  fprintf (fout,"\n");
}

void
decode_printfile (struct cmd_printfile *cmd)
{
  fprintf (fout,"PRINT FILE \"%s\"\n", cmd->filename);
}

void
decode_block (struct commands *cmd)
{
  int a;
  for (a = 0; a < cmd->commands.commands_len; a++)
    {
      dump_command (&cmd->commands.commands_val[a]);
    }
}

void
decode_call (struct cmd_call *cmd)
{
  fprintf (fout,"CALL %s (", cmd->fcall->fname);
  decode_list (cmd->fcall->lexpr);
  fprintf (fout,")\n");
}

void
dump_command (struct command *cmd)
{
  int a;
  a = cmd->cmd_type;
  print_lvl ();
  switch (a)
    {
    case CMD_FOR:
      decode_for (&cmd->command_u.cmd_for);
      break;
    case CMD_IF:
      decode_if (&cmd->command_u.cmd_if);
      break;
    case CMD_WHILE:
      decode_while (&cmd->command_u.cmd_while);
      break;
    case CMD_LET:
      decode_let (&cmd->command_u.cmd_let);
      break;
    case CMD_NEED:
      decode_need (&cmd->command_u.cmd_need);
      break;
    case CMD_PAUSE:
      decode_pause (&cmd->command_u.cmd_pause);
      break;
    case CMD_SKIP:
      decode_skip (&cmd->command_u.cmd_skip);
      break;
    case CMD_PRINT:
      decode_print (&cmd->command_u.cmd_print);
      break;
    case CMD_PRINTFILE:
      decode_printfile (&cmd->command_u.cmd_printfile);
      break;
    case CMD_BLOCK:
      decode_block (&cmd->command_u.commands);
      break;
    case CMD_CALL:
      decode_call (&cmd->command_u.cmd_call);
      break;
    }
}

void
dump_commands (struct commands *cmd)
{
  int a;
  for (a = 0; a < cmd->commands.commands_len; a++)
    {
      dump_command (&cmd->commands.commands_val[a]);
    }
}


void
decode_column (struct format *f)
{
  //s", f->column.column_val[0]->varname);
  //return buff;
  decode_expr (f->column);
//print_variable( f->column->varid, f->column->subscript1, f->column->subscript2);

}

void
dump_format ()
{
  int a;
  fprintf (fout,"FORMAT\n");
  for (a = 0; a < this_report.fmt.fmt_len; a++)
    {


      switch (this_report.fmt.fmt_val[a].category)
	{
	case FORMAT_PAGE_HEADER:
	format_section_is_last=0;
	  fprintf (fout,"\nPAGE HEADER\n");
	  break;
	case FORMAT_FIRST_PAGE_HEADER:
	format_section_is_last=0;
	  fprintf (fout,"\nFIRST PAGE HEADER\n");
	  break;
	case FORMAT_PAGE_TRAILER:
	format_section_is_last=0;
	  fprintf (fout,"\nPAGE TRAILER\n");
	  break;
	case FORMAT_EVERY_ROW:
	format_section_is_last=0;
	  fprintf (fout,"\nEVERY ROW\n");
	  break;
	case FORMAT_ON_EVERY_ROW:
	format_section_is_last=0;
	  fprintf (fout,"\nON EVERY ROW\n");
	  break;
	case FORMAT_BEFORE_GROUP:
	format_section_is_last=0;
	  fprintf (fout,"\nBEFORE GROUP OF ");
	  decode_column (&this_report.fmt.fmt_val[a]);
	  fprintf (fout,"\n");
	  break;
	case FORMAT_AFTER_GROUP:
	format_section_is_last=0;
	  fprintf (fout,"\nAFTER GROUP OF ");
	  decode_column (&this_report.fmt.fmt_val[a]);
	  fprintf (fout,"\n");
	  break;
	case FORMAT_ON_LAST_ROW:
	format_section_is_last=1;
	  fprintf (fout,"\nON LAST ROW\n");
	  break;
	}
      lvl++;
      dump_commands (&this_report.fmt.fmt_val[a].commands);
      lvl--;

    }
}



void
print_variable (int a, struct expr *sub1, struct expr *sub2)
{
  int printed = 0;
  if (a == -1)
    {
      fprintf (fout, "Unknown...\n");
    }
  else
    {


      if (this_report.variables.variables_val[a].category == CAT_BUILTIN
	  && !printed)
	{
	  fprintf (fout, "%s", this_report.variables.variables_val[a].name);
	  printed++;
	}

      if (this_report.variables.variables_val[a].category == CAT_SQL
	  && !printed)
	{
	  printed++;

	if (printing_agg_functions) {
	  	fprintf (fout, "tmp_data.%s", downshift (this_report.variables.variables_val[a].name));
	} else {
	  	fprintf (fout, "lr_data.%s", downshift (this_report.variables.variables_val[a].name));
	}
	}

      if (this_report.variables.variables_val[a].category != CAT_SQL
	  && !printed)
	{
	  printed++;
	  fprintf (fout, "mv_%s",
		  downshift (this_report.variables.variables_val[a].name));
	}


      if (sub1)
	{
	  if (sub2)
	    {
	      fprintf (fout, "[");
	      decode_expr (sub1);
	      fprintf (fout, ",");
	      decode_expr (sub2);
	      fprintf (fout, "]");
	    }
	  else
	    {
	      fprintf (fout, "[");
	      decode_expr (sub1);
	      fprintf (fout, "]");
	    }
	}
    }
}


/*
This function takes the known positions of the variables in the
select statement and puts them back in where the compiler had replaced them
with a '?'
*/
char *
replace_vars_sql (struct select_stmts *ptr)
{
  static char buff[30000];
  char *cptr;
  int a;
  char *lpos;
  strcpy (buff, "");

/* Do we actually have anything to do ? */

  if (ptr->varids.varids_len == 0)
    return ptr->statement;

  cptr = acl_strdup (ptr->statement);

  lpos = &cptr[0];
  for (a = 0; a < ptr->varpos.varpos_len; a++)
    {
      /* Firstly - split our string into segments */
      /* by blanking out the '?' to /0 */
       /**/ cptr[ptr->varpos.varpos_val[a]] = 0;
      strcat (buff, lpos);
      strcat (buff, "mv_");
      strcat (buff,
	      this_report.variables.variables_val[ptr->varids.
						  varids_val[a]].name);
      lpos = &cptr[ptr->varpos.varpos_val[a] + 1];
    }

  strcat (buff, lpos);
  free (cptr);

  return buff;
}


char *
trans (char *s)
{
  static char buff[256];
  int a;
  int c = 0;
  for (a = 0; a < strlen (s); a++)
    {
      if (s[a] == '"')
	{
	  buff[c++] = '\\';
	}
      buff[c++] = s[a];
    }
  buff[c] = 0;
  return buff;
}


char *
acl_strdup_full (void *a, char *r, char *f, int l)
{
  char *p;
  p = strdup (a);
  if (p == 0)
    {
      fprintf (stderr, "Unable to allocate memory\n");
      exit (1);
    }
  return p;
}

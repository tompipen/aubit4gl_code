#include <stdio.h>
#include "report.h"

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
void dump_ascii (void );
void dump_command (struct command *cmd);
void dump_commands (struct commands *cmd);
void dump_format (void );
void dump_functions (void );
void dump_getdata (void );
void dump_output (void );
void dump_report (void );
void print_inputs ();
void print_lvl (void );
void print_set_params (void );
void print_variable (int a);
void print_variables (int class, int inrec);


int
main (int argc, char *argv[])
{
  FILE *f;
  int a;

  if (argc != 2)
    {
      printf ("Usage %s filename [ Where filename is a compile report eg. simple.aarc ]\n", argv[0]);
      exit (0);
    }


  memset (&this_report, 0, sizeof (struct report));

  a = read_data_from_file ("report", &this_report, argv[1]);

  if (!a)
    {
      printf ("Bad format\n");
      exit (1);
    }


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
  strcpy (buff, "ORDER EXTERNAL BY ");

  for (a = 0; a < ptr->orderby_list.orderby_list_len; a++)
    {
      b = ptr->orderby_list.orderby_list_val[a];
      if (a)
	strcat (buff, ",");
      strcat (buff, "lv_data.x_");
      strcat (buff, this_report.variables.variables_val[b].name);
    }
  reporderby = buff;
  return buff;
}


void
dump_report ()
{
  printf ("DATABASE %s\n", this_report.dbname);
  print_variables (CAT_PARAM, 0);
  print_variables (CAT_VARIABLE, 0);
  printf ("\n\n");
  printf ("MAIN\n");
  printf ("   CALL run_report_%s()\n", this_report.report_name);
  printf ("END MAIN\n");
  printf ("\n");


  printf ("FUNCTION run_report_%s()\n", this_report.report_name);
  printf ("# Variables\n");
  printf ("DEFINE lv_data RECORD\n");
  print_variables (CAT_SQL, 1);
  printf ("END RECORD\n");
  print_set_params ();
  print_inputs ();
  printf ("# end of initialisation\n");
  printf ("\n");
  dump_getdata ();

  printf ("REPORT rep_%s(lv_data)\n", this_report.report_name);
  printf ("DEFINE lv_data RECORD\n");
  print_variables (CAT_SQL, 1);
  printf ("END RECORD\n");
  dump_output ();
  printf ("\n");
  printf ("\n");
  dump_format ();
  printf ("\nEND REPORT\n\n");
}


void
dump_ascii ()
{
  printf ("Dump Ascii not implemented\n");
}

void
dump_functions ()
{
  int a;
  printf ("Functions\n");
  printf ("---------\n");
  for (a = 0; a < this_report.functions.functions_len; a++)
    {
      printf ("Function : %s\n", this_report.functions.functions_val[a].name);

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
	    printf (",\n");

	  if (inrec)
	    printf ("   ");
	  else
	    printf ("DEFINE ");


	  printf ("x_%s %s",
		  this_report.variables.variables_val[a].name,
		  this_report.variables.variables_val[a].datatype_string);

	  k++;
	  if (!inrec)
	    printf ("\n");
	}

    }
  if (inrec)
    printf ("\n");
}


void
print_set_params ()
{
  int a;
  for (a = 0; a < this_report.variables.variables_len; a++)
    {
      if (this_report.variables.variables_val[a].category == CAT_PARAM)
	printf ("LET x_%s=arg_val(%d)\n",
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
      printf ("PROMPT \"%s\" FOR ", this_report.inputs.inputs_val[a].prompt);
      print_variable (this_report.inputs.inputs_val[a].varid);
      printf ("\n");
    }
}



void
dump_output ()
{




  printf ("OUTPUT\n");
  printf
    ("  TOP MARGIN %d\n  BOTTOM MARGIN %d\n  LEFT MARGIN %d\n  RIGHT MARGIN %d\n",
     this_report.output.top_margin, this_report.output.bottom_margin,
     this_report.output.left_margin, this_report.output.right_margin);

  printf ("  TOP OF PAGE \"%s\"\n", this_report.output.top_of_page);

  if (this_report.output.report_to_where == 1)
    printf (" REPORT TO PRINTER");
  if (this_report.output.report_to_where == 2)
    printf (" REPORT TO PIPE %s\n", this_report.output.report_to_filename);
  if (this_report.output.report_to_where == 3)
    printf (" REPORT TO \"%s\"\n", this_report.output.report_to_filename);

  if (reporderby)
    {
      printf ("\n%s\n", reporderby);
    }
}


void
dump_getdata ()
{
  int a;
  int b;

  struct select_stmts *ptr;

  if (this_report.getdata.select_or_read == 0)
    {
      for (a = 0; a < this_report.getdata.get_data_u.selects.selects_len; a++)
	{
	  ptr = &this_report.getdata.get_data_u.selects.selects_val[a];


	  if (a == this_report.getdata.get_data_u.selects.selects_len - 1)
	    {
	      printf ("DECLARE c_r_%s CURSOR FOR\n   %s\n\n",
		      this_report.report_name, replace_vars_sql (ptr));
	      generate_order_by (ptr);
	    }
	  else
	    {
	      if (strlen (ptr->temp_tab_name))
		{
		  printf
		    ("WHENEVER ERROR CONTINUE\nDROP TABLE %s\nLET status=0\nLET sqlca.sqlcode=0\nWHENEVER ERROR STOP\n",
		     ptr->temp_tab_name);
		}
	      printf ("%s\n", replace_vars_sql (ptr));
	    }


	}
      printf ("START REPORT rep_%s\n\n", this_report.report_name);
      printf ("FOREACH c_r_%s INTO lv_data.*\n\n", this_report.report_name);
      printf ("  OUTPUT TO REPORT rep_%s (lv_data.*)\n",
	      this_report.report_name);
      printf ("END FOREACH\n\n");
      printf ("FINISH REPORT rep_%s\n\n", this_report.report_name);
      printf ("END FUNCTION\n\n");
    }
  else
    {
      printf ("Using Read statement\n");
      printf ("Dump NIY\n");
      exit (2);
    }
}



void
print_lvl ()
{
  int a;
  for (a = 0; a < lvl; a++)
    {
      printf ("   ");
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
    printf ("(");
  decode_expr (&e->expr1);
  printf (" %s ", decode_op (e->operand));
  decode_expr (&e->expr2);

  if (e->operand != EXPR_CONCAT)
    printf (")");
}


void
decode_compare (struct compare_expr *e)
{
  printf ("(");
  decode_expr (&e->expr1);
  printf ("%s", e->method);
  decode_expr (&e->expr2);
  printf (")");
}

void
decode_simple (struct simple_expr *e)
{
if (e->operand==EXPR_COLUMN||e->operand==EXPR_ASCII) {
  printf(" %s ",decode_op (e->operand));
  decode_expr (&e->expr);
} else {
  printf(" %s ",decode_op (e->operand));
  decode_expr (&e->expr);
}
}



void
decode_agg (int aggid)
{
  //this_report.aggs.aggs_val[aggid].
  if (this_report.aggs.aggs_val[aggid].isgroup)
    {
      printf (" GROUP ");
    }
  switch (this_report.aggs.aggs_val[aggid].type)
    {
    case AGG_COUNT:
      printf ("COUNT(*)");
      break;
    case AGG_PERCENT:
      printf ("PERCENT(*) ");
      break;

    case AGG_AVG:
      printf ("AVERAGE(");
      decode_expr (this_report.aggs.aggs_val[aggid].expr);
      printf (")");
      break;
    case AGG_TOTAL:
      printf ("SUM(");
      decode_expr (this_report.aggs.aggs_val[aggid].expr);
      printf (")");
      break;
    case AGG_MIN:
      printf ("MIN(");
      decode_expr (this_report.aggs.aggs_val[aggid].expr);
      printf (")");
      break;
    case AGG_MAX:
      printf ("MAX(");
      decode_expr (this_report.aggs.aggs_val[aggid].expr);
      printf (")");
      break;
    }

  if (this_report.aggs.aggs_val[aggid].wexpr)
    {
      printf (" WHERE ");
      decode_expr (this_report.aggs.aggs_val[aggid].wexpr);
    }

}


void
decode_list (struct expr_list *e)
{
  int a;
  for (a = 0; a < e->elem.elem_len; a++)
    {
      if (a)
	printf (", ");
      decode_expr (&e->elem.elem_val[a]);
    }
}

void
decode_fcall (struct expr_call *e)
{
  printf (" %s(", e->fname);
  decode_list (e->lexpr);
  printf (")");
}

void
decode_expr (struct expr *e)
{
  switch (e->type)
    {

    case EXPRTYPE_INT:
      printf ("%d", e->expr_u.i);
      break;
    case EXPRTYPE_DOUBLE:
      printf ("%f", e->expr_u.d);
      break;
    case EXPRTYPE_STRING:
      printf ("\"%s\"", e->expr_u.s);
      break;
    case EXPRTYPE_VARIABLE:
      print_variable (e->expr_u.varid);
      break;
    case EXPRTYPE_BUILTIN:
      printf ("%s", e->expr_u.name);
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
  printf ("FOR ");
  print_variable (cmd->varid);
  decode_expr (&cmd->start);
  printf (" TO ");
  decode_expr (&cmd->finish);
  printf (" STEP ");
  decode_expr (&cmd->step);
  lvl++;
  dump_command (cmd->command);
  lvl--;
  print_lvl ();
  printf ("END FOR\n\n");
}

void
decode_if (struct cmd_if *cmd)
{
  printf ("IF ");
  printf ("");
  decode_expr (&cmd->condition);
  printf (" THEN \n");
  lvl++;
  dump_command (cmd->command);
  lvl--;
  if (cmd->elsecommand->cmd_type != CMD_NULL)
    {
      print_lvl ();
      printf (" ELSE \n");
      lvl++;
      dump_command (cmd->elsecommand);
      lvl--;
    }
  print_lvl ();
  printf ("END IF\n\n");
}

void
decode_while (struct cmd_while *cmd)
{
  printf ("WHILE ");
  decode_expr (&cmd->condition);
  printf ("\n");
  lvl++;
  dump_command (cmd->command);
  lvl--;
  print_lvl ();
  printf ("END WHILE\n\n");
}


void
decode_let (struct cmd_let *cmd)
{
  printf ("LET ");
  print_variable (cmd->varid);
  printf ("=");
  decode_expr (&cmd->value);
  printf ("\n");
}

void
decode_need (struct cmd_need *cmd)
{
  printf ("NEED %d LINES\n", cmd->nlines);
}


void
decode_pause (struct cmd_pause *cmd)
{
  printf ("PAUSE \"%s\"\n", cmd->message);
}


void
decode_skip (struct cmd_skip *cmd)
{
  if (cmd->nlines < 0)
    printf ("SKIP TO TOP OF PAGE\n");
  else
    printf ("SKIP %d LINES\n", cmd->nlines);
}


void
decode_print (struct cmd_print *cmd)
{
  printf ("PRINT ");
  decode_expr (&cmd->print);
  if (cmd->printnl == 0)
    printf (";");
  printf ("\n");
}

void
decode_printfile (struct cmd_printfile *cmd)
{
  printf ("PRINTFILE\n");
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

decode_call (struct cmd_call *cmd)
{
  printf ("CALL %s (", cmd->fcall->fname);
  decode_list (cmd->fcall->lexpr);
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


char *
decode_column (struct format *f)
{
  static char buff[256];
  sprintf (buff, "%s", f->column);
  return buff;
}

void
dump_format ()
{
  int a;
  printf ("FORMAT\n");
  for (a = 0; a < this_report.fmt.fmt_len; a++)
    {


      switch (this_report.fmt.fmt_val[a].category)
	{
	case FORMAT_PAGE_HEADER:
	  printf ("\nPAGE HEADER\n");
	  break;
	case FORMAT_FIRST_PAGE_HEADER:
	  printf ("\nFIRST PAGE HEADER\n");
	  break;
	case FORMAT_PAGE_TRAILER:
	  printf ("\nPAGE TRAILER\n");
	  break;
	case FORMAT_EVERY_ROW:
	  printf ("\nEVERY ROW\n");
	  break;
	case FORMAT_ON_EVERY_ROW:
	  printf ("\nON EVERY ROW\n");
	  break;
	case FORMAT_BEFORE_GROUP:
	  printf ("\nBEFORE GROUP OF lv_data.x_%s\n",
		  decode_column (&this_report.fmt.fmt_val[a]));
	  break;
	case FORMAT_AFTER_GROUP:
	  printf ("\nAFTER GROUP OF lv_data.x_%s\n",
		  decode_column (&this_report.fmt.fmt_val[a]));
	  break;
	case FORMAT_ON_LAST_ROW:
	  printf ("\nON LAST ROW\n");
	  break;
	}
      lvl++;
      dump_commands (&this_report.fmt.fmt_val[a].commands);
      lvl--;

    }
}



void
print_variable (int a)
{
  if (a == -1)
    {
      printf ("Unknown...\n");
    }
  else
    {


      if (this_report.variables.variables_val[a].category == CAT_BUILTIN)
	{
	  printf ("%s", this_report.variables.variables_val[a].name);
	  return;
	}

      if (this_report.variables.variables_val[a].category == CAT_SQL)
	{
	  printf ("lv_data.x_%s",
		  this_report.variables.variables_val[a].name);
	  return;
	}

      if (this_report.variables.variables_val[a].category != CAT_SQL)
	{
	  printf ("x_%s", this_report.variables.variables_val[a].name);
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
  int c;
  char *lpos;
  strcpy (buff, "");

/* Do we actually have anything to do ? */

  if (ptr->varids.varids_len == 0)
    return ptr->statement;

  cptr = strdup (ptr->statement);

  lpos = &cptr[0];
  for (a = 0; a < ptr->varpos.varpos_len; a++)
    {
      // Firstly - split our string into segments
      // by blanking out the '?' to /0
      //
      cptr[ptr->varpos.varpos_val[a]] = 0;
      strcat (buff, lpos);
      strcat (buff, "x_");
      strcat (buff,
	      this_report.variables.variables_val[ptr->varids.
						  varids_val[a]].name);
      lpos = &cptr[ptr->varpos.varpos_val[a] + 1];
    }

  strcat (buff, lpos);
  free (cptr);

  return buff;
}

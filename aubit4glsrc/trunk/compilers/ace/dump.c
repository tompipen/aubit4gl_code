#include <stdio.h>
#include "report.h"

int lvl = 0;
struct report this_report;


void dump_command (struct command *cmd);
void decode_expr (struct expr *e);

main (int argc, char *argv[])
{
  FILE *f;




  XDR xdrp;
  int a;

  if (argc != 2)
    {
      printf ("Usage %s filename\n", argv[0]);
      exit (0);
    }

  f = fopen (argv[1], "rb");

  if (f == 0)
    {
      printf ("Unable to open file %s\n", argv[1]);
      exit (2);
    }

  memset (&this_report, 0, sizeof (struct report));

  xdrstdio_create (&xdrp, f, XDR_DECODE);

  a = xdr_report (&xdrp, &this_report);	//in lib/libform/form_xdr/formwrite2.c

  if (!a)
    {
      printf ("Bad format\n");
      exit (1);
    }


  dump_report ();
}



dump_report ()
{
  printf ("Magic  : %s\n", this_report.magic);
  printf ("dbname : %s\n", this_report.dbname);
  dump_ascii ();
  printf ("\n");
  dump_functions ();
  printf ("\n");
  dump_variables ();
  printf ("\n");
  dump_inputs ();
  printf ("\n");
  dump_output ();
  printf ("\n");
  dump_getdata ();
  printf ("\n");
  dump_format ();
}


dump_ascii ()
{
  printf ("Dump Ascii not implemented\n");
}

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

dump_variables ()
{
  int a;
  printf ("Variables\n");
  printf ("---------\n");
  printf ("\n");

  for (a = 0; a < this_report.variables.variables_len; a++)
    {
      printf ("%s %s %d %d %d %d\n",
	      this_report.variables.variables_val[a].name,
	      this_report.variables.variables_val[a].datatype_string,
	      this_report.variables.variables_val[a].category,
	      this_report.variables.variables_val[a].param_no,
	      this_report.variables.variables_val[a].datatype,
	      this_report.variables.variables_val[a].dataspace);

    }
}



dump_inputs ()
{
  int a;
  printf ("Inputs\n");
  printf ("---------\n");
  printf ("\n");

  for (a = 0; a < this_report.inputs.inputs_len; a++)
    {
      printf ("Prompt=%s Variable=%s (ID=%d)\n",
	      this_report.inputs.inputs_val[a].prompt,
	      this_report.inputs.inputs_val[a].variable_name,
	      this_report.inputs.inputs_val[a].varid);

    }
}



dump_output ()
{
  printf ("Output\n");
  printf ("------\n");
  printf ("tm=%d bm=%d lm=%d rm=%d rtw=%d top=%s rf=%s\n",
	  this_report.output.top_margin,
	  this_report.output.bottom_margin,
	  this_report.output.left_margin,
	  this_report.output.right_margin,
	  this_report.output.report_to_where,
	  this_report.output.top_of_page,
	  this_report.output.report_to_filename);

}


dump_getdata ()
{
  int a;
  int b;
  struct select_stmts *ptr;

  if (this_report.getdata.select_or_read == 0)
    {
      printf ("Using Select Statements\n");
      
      for (a = 0; a < this_report.getdata.get_data_u.selects.selects_len; a++)
	{
	  ptr=&this_report.getdata.get_data_u.selects.selects_val[a];

	  printf ("%s\n", ptr->statement);
	  if (ptr->wherepos1) {
	  	for (b=0;b<ptr->wherepos1-1;b++) printf(" ");
		printf("^");
	  }

	  if (ptr->wherepos2) {
	  	for (b=ptr->wherepos1;b<ptr->wherepos2-1;b++) printf(" ");
		printf("^");
	  }

	  if (ptr->wherepos1) {
		printf("\n");
	  }

	  if (ptr->has_where) {
			printf("Has a where clause\n");
	  }

	  if (ptr->varids.varids_len) {
		printf("OPEN USING :");
		for (b=0;b<ptr->varids.varids_len;b++) {
			if (b) printf(",");
			print_variable(ptr->varids.varids_val[b]);
		}
	  }

	  if (strlen(ptr->temp_tab_name)) printf("Temp table : %s\n",ptr->temp_tab_name);

	}

    }
  else
    {
      printf ("Using Read statement\n");
      printf ("Dump NIY\n");
    }
}



print_lvl ()
{
  int a;
  for (a = 0; a < lvl; a++)
    {
      printf ("   ");
    }
}



char *decode_op(int op) {
switch(op) {
	case EXPR_AND: return "AND";
        case EXPR_OR: return "OR";
	case EXPR_ADD: return "+";
        case EXPR_SUB: return "-";
        case EXPR_MUL: return "*";
        case EXPR_DIV: return "/";
        case EXPR_POW: return "**";

        case EXPR_CLIP: return "CLIPPED";
        case EXPR_USING: return "USING";
        case EXPR_COLUMN: return "COLUMN";
        case EXPR_SPACES: return "SPACES";
        case EXPR_CONCAT: return ",";
        case EXPR_ISNULL: return "IS NULL";
        case EXPR_ISNOTNULL: return "IS NOT NULL";
}

return "Dont know(?!)";

}

decode_complex(struct complex_expr *e) {
	decode_expr(&e->expr1);
	printf("%s (%d)",decode_op(e->operand),e->operand);
	decode_expr(&e->expr2);
}


decode_compare(struct compare_expr *e) {
	printf("(");
	decode_expr(&e->expr1);
	printf("%s",e->method);
	decode_expr(&e->expr2);
	printf(")");
}

decode_simple(struct simple_expr *e) {
	decode_expr(&e->expr);
	decode_op(e->operand);
}


decode_list(struct expr_list *e) {
int a;
for (a=0;a<e->elem.elem_len;a++) {
	if (a) printf(", ");
	decode_expr(&e->elem.elem_val[a]);
}
}

decode_fcall(struct expr_call *e) {
printf(" %s(",e->fname);
decode_list(e->lexpr);
printf(")");
}

void decode_expr (struct expr *e)
{
  switch(e->type) {
	case EXPRTYPE_INT    : printf("%d",e->expr_u.i); break;
	case EXPRTYPE_DOUBLE : printf("%f",e->expr_u.d); break;
	case EXPRTYPE_STRING : printf("%s",e->expr_u.s); break;
	case EXPRTYPE_VARIABLE : print_variable(e->expr_u.varid); break;
	case EXPRTYPE_BUILTIN  : printf("%s",e->expr_u.name); break;
	case EXPRTYPE_COMPLEX: decode_complex(e->expr_u.expr);break;
	case EXPRTYPE_COMPARE: decode_compare(e->expr_u.cexpr);break;
	case EXPRTYPE_SIMPLE: decode_simple(e->expr_u.sexpr);break;
	case EXPRTYPE_LIST: decode_list(e->expr_u.lexpr);break;
	case EXPRTYPE_FCALL: decode_fcall(e->expr_u.fcall);break;
}

}

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
  printf ("\n");
}

decode_if (struct cmd_if *cmd)
{
  printf ("IF \n");
  printf ("(");
  decode_expr (&cmd->condition);
  printf (") THEN \n");
  dump_command (cmd->command);
  if (cmd->elsecommand->cmd_type != CMD_NULL)
    {
      printf (" ELSE \n");
      dump_command (cmd->elsecommand);
    }
}

decode_while (struct cmd_while *cmd)
{
  printf ("WHILE (");
  decode_expr (&cmd->condition);
  printf (") DO\n");
  dump_command (cmd->command);
}


decode_let (struct cmd_let *cmd)
{
  printf ("LET ");
  print_variable (cmd->varid);
  printf ("=");
  decode_expr (&cmd->value);
  printf ("\n");
}

decode_need (struct cmd_need *cmd)
{
  printf ("NEED %d LINES\n", cmd->nlines);
}


decode_pause (struct cmd_pause *cmd)
{
  printf ("PAUSE \"%s\"\n", cmd->message);
}


decode_skip (struct cmd_skip *cmd)
{
  if (cmd->nlines < 0)
    printf ("SKIP TO TOP OF PAGE\n");
  else
    printf ("SKIP %d LINES\n", cmd->nlines);
}


decode_print (struct cmd_print *cmd)
{
  printf ("PRINT ");
  decode_expr (&cmd->print);
  if (cmd->printnl == 0)
    printf (";");
  printf ("\n");
}

decode_printfile (struct cmd_printfile *cmd)
{
  printf ("PRINTFILE\n");
}

decode_block (struct commands *cmd)
{
  int a;
  printf ("BEGIN\n");
  for (a = 0; a < cmd->commands.commands_len; a++)
    {
      dump_command (&cmd->commands.commands_val[a]);
    }
  printf ("END\n");
}

decode_call (struct cmd_call *cmd)
{
  printf ("CALL %s (",cmd->fcall->fname);
  decode_list(cmd->fcall->lexpr);
}

void
dump_command (struct command *cmd)
{
  int a;
  a = cmd->cmd_type;
  print_lvl ();
  lvl++;
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
  lvl--;
}

dump_commands (struct commands *cmd)
{
  int a;
  for (a = 0; a < cmd->commands.commands_len; a++)
    {
      dump_command (&cmd->commands.commands_val[a]);
    }
}


char *
decode_column(struct format *f) {
static char buff[256];
	sprintf(buff,"%s",f->column);
	return buff;
}

dump_format ()
{
  int a;
  printf ("Format\n");
  printf ("------\n");
  for (a = 0; a < this_report.fmt.fmt_len; a++)
    {


      switch(this_report.fmt.fmt_val[a].category) {
	case FORMAT_PAGE_HEADER : printf("PAGE HEADER\n"); break;
	case FORMAT_FIRST_PAGE_HEADER : printf("FIRST PAGE HEADER\n"); break;
	case FORMAT_PAGE_TRAILER : printf("PAGE TRAILER\n"); break;
	case FORMAT_EVERY_ROW : printf("EVERY ROW\n"); break;
	case FORMAT_ON_EVERY_ROW: printf("ON EVERY ROW\n"); break;
	case FORMAT_BEFORE_GROUP: printf("BEFORE GROUP OF %s\n",decode_column(&this_report.fmt.fmt_val[a])); break;
	case FORMAT_AFTER_GROUP : printf("AFTER GROUP OF %s\n",decode_column(&this_report.fmt.fmt_val[a])); break;
	case FORMAT_ON_LAST_ROW : printf("ON LAST ROW\n"); break;
      }
//fflush(stdout);
	lvl++;
      dump_commands (&this_report.fmt.fmt_val[a].commands);
	lvl--;

    }
}



print_variable (int a)
{
if (a==-1) {
	printf("Unknown...\n");
} else {
	      printf("%s",this_report.variables.variables_val[a].name);
}
}

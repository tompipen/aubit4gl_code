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
# $Id: dump.c,v 1.4 2002-10-18 07:54:51 afalout Exp $
#*/

/**
 * @file
 *
 *
 *
 *
 * @todo Doxygen comments to add to functions
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_ace_int.h"

	#ifdef __CYGWIN__
	    /* missing from rpcgen generated form_x.h on CygWin: */
		#define bool_t int
		#define u_int unsigned int


		#include <rpc/rpc.h>

	#endif


/*
=====================================================================
                    Variables definitions
=====================================================================
*/


int lvl = 0;
struct report this_report;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

void dump_command (struct command *cmd);
void decode_expr (struct expr *e);
void print_variable (int a);
void decode_for (struct cmd_for *cmd);
void decode_if (struct cmd_if *cmd);
void decode_while (struct cmd_while *cmd);
void decode_let (struct cmd_let *cmd);
void decode_need (struct cmd_need *cmd);
void decode_pause (struct cmd_pause *cmd);
void decode_skip (struct cmd_skip *cmd);
void decode_print (struct cmd_print *cmd);
void decode_printfile (struct cmd_printfile *cmd);
void decode_block (struct commands *cmd);
void decode_call (struct cmd_call *cmd);
void dump_commands (struct commands *cmd);
char * decode_column(struct format *f);
void dump_format (void);
void print_lvl (void);
char * decode_op(int op);
void decode_complex(struct complex_expr *e);
void decode_compare(struct compare_expr *e);
void decode_simple(struct simple_expr *e);
void decode_list(struct expr_list *e);
void decode_fcall(struct expr_call *e);
void dump_getdata (void);
void dump_inputs (void);
void dump_functions (void);
void dump_ascii (void);
void dump_output (void);
void dump_variables (void);
void dump_report (void);


/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 *
 * @todo Describe function
 */
int
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

  return 0;

}





/**
 *
 * @todo Describe function
 */
void
dump_report (void)
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


/**
 *
 * @todo Describe function
 */
void
dump_ascii (void)
{
  printf ("Dump Ascii not implemented\n");
}


/**
 *
 * @todo Describe function
 */
void
dump_functions (void)
{
  int a;
  printf ("Functions\n");
  printf ("---------\n");
  for (a = 0; a < this_report.functions.functions_len; a++)
    {
      printf ("Function : %s\n", this_report.functions.functions_val[a].name);

    }
}

/**
 *
 * @todo Describe function
 */
void
dump_variables (void)
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



/**
 *
 * @todo Describe function
 */
void
dump_inputs (void)
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



/**
 *
 * @todo Describe function
 */
void
dump_output (void)
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


/**
 *
 * @todo Describe function
 */
void
dump_getdata (void)
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



/**
 *
 * @todo Describe function
 */
void
print_lvl (void)
{
  int a;
  for (a = 0; a < lvl; a++)
    {
      printf ("   ");
    }
}


/**
 *
 * @todo Describe function
 */
char *
decode_op(int op)
{
	switch(op)
	{
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

/**
 *
 * @todo Describe function
 */
void
decode_complex(struct complex_expr *e)
{
	decode_expr(&e->expr1);
	printf("%s (%d)",decode_op(e->operand),e->operand);
	decode_expr(&e->expr2);
}


/**
 *
 * @todo Describe function
 */
void
decode_compare(struct compare_expr *e)
{
	printf("(");
	decode_expr(&e->expr1);
	printf("%s",e->method);
	decode_expr(&e->expr2);
	printf(")");
}

/**
 *
 * @todo Describe function
 */
void
decode_simple(struct simple_expr *e)
{
	decode_expr(&e->expr);
	decode_op(e->operand);
}


/**
 *
 * @todo Describe function
 */
void
decode_list(struct expr_list *e)
{
int a;
	for (a=0;a<e->elem.elem_len;a++) {
		if (a) printf(", ");
		decode_expr(&e->elem.elem_val[a]);
	}
}


/**
 *
 * @todo Describe function
 */
void
decode_fcall(struct expr_call *e)
{
	printf(" %s(",e->fname);
	decode_list(e->lexpr);
	printf(")");
}

/**
 *
 * @todo Describe function
 */
void 
decode_expr (struct expr *e)
{
  switch(e->type) 
  {
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

    /*
    dump.c:478: warning: enumeration value `EXPRTYPE_NULL' not handled in switch
	dump.c:478: warning: enumeration value `EXPRTYPE_AGG' not handled in switch
    */

   	case EXPRTYPE_NULL: break;
	case EXPRTYPE_AGG: break;


  }

}

/**
 *
 * @todo Describe function
 */
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
  printf ("\n");
}

/**
 *
 * @todo Describe function
 */
void
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

/**
 *
 * @todo Describe function
 */
void
decode_while (struct cmd_while *cmd)
{
  printf ("WHILE (");
  decode_expr (&cmd->condition);
  printf (") DO\n");
  dump_command (cmd->command);
}


/**
 *
 * @todo Describe function
 */
void
decode_let (struct cmd_let *cmd)
{
  printf ("LET ");
  print_variable (cmd->varid);
  printf ("=");
  decode_expr (&cmd->value);
  printf ("\n");
}

/**
 *
 * @todo Describe function
 */
void
decode_need (struct cmd_need *cmd)
{
  printf ("NEED %d LINES\n", cmd->nlines);
}


/**
 *
 * @todo Describe function
 */
void
decode_pause (struct cmd_pause *cmd)
{
  printf ("PAUSE \"%s\"\n", cmd->message);
}


/**
 *
 * @todo Describe function
 */
void
decode_skip (struct cmd_skip *cmd)
{
  if (cmd->nlines < 0)
    printf ("SKIP TO TOP OF PAGE\n");
  else
    printf ("SKIP %d LINES\n", cmd->nlines);
}


/**
 *
 * @todo Describe function
 */
void
decode_print (struct cmd_print *cmd)
{
  printf ("PRINT ");
  decode_expr (&cmd->print);
  if (cmd->printnl == 0)
    printf (";");
  printf ("\n");
}

/**
 *
 * @todo Describe function
 */
void
decode_printfile (struct cmd_printfile *cmd)
{
  printf ("PRINTFILE\n");
}

/**
 *
 * @todo Describe function
 */
void
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

/**
 *
 * @todo Describe function
 */
void
decode_call (struct cmd_call *cmd)
{
  printf ("CALL %s (",cmd->fcall->fname);
  decode_list(cmd->fcall->lexpr);
}

/**
 *
 * @todo Describe function
 */
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

/**
 *
 * @todo Describe function
 */
void
dump_commands (struct commands *cmd)
{
  int a;
  for (a = 0; a < cmd->commands.commands_len; a++)
    {
      dump_command (&cmd->commands.commands_val[a]);
    }
}


/**
 *
 * @todo Describe function
 */
char *
decode_column(struct format *f)
{
static char buff[256];
	sprintf(buff,"%s",f->column);
	return buff;
}

/**
 *
 * @todo Describe function
 */
void
dump_format (void)
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
	/* fflush(stdout); */
	lvl++;
      dump_commands (&this_report.fmt.fmt_val[a].commands);
	lvl--;

    }
}



/**
 *
 * @todo Describe function
 */
void
print_variable (int a)
{
	if (a==-1) 
	{
		printf("Unknown...\n");
	} else {
		      printf("%s",this_report.variables.variables_val[a].name);
	}
}


/* =============================== EOF =========================== */

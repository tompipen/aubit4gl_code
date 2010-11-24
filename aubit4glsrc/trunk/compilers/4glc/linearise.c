#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "commands.h"
#include "a4gl_4glc_int.h"
#include "lint.h"
#include "linearise.h"

static void linearise_expression(expr_str_list *l,  expr_str *e ) ;
static void linearise_expression_list(expr_str_list *l1, expr_str_list *srclist) ;


void
linearise_commands_from_events (struct s_commands *master_list, struct on_events *evt_list)
{
  int a;

  A4GL_assertion (master_list == 0, "Master list not set");

  if (evt_list == 0)
    return;

  for (a = 0; a < evt_list->event.event_len; a++)
    {
      linearise_commands (master_list, evt_list->event.event_val[a]->on_event_commands);
    }

}

struct s_commands *
linearise_commands (struct s_commands *master_list, struct s_commands *cmds)
{
  int a;
  int cnt;
  struct on_events *evt_list;

  if (master_list == 0)
    {
      master_list = malloc (sizeof (struct s_commands));
      master_list->cmds.cmds_val = 0;
      master_list->cmds.cmds_len = 0;
    }
  if (cmds == 0)
    return master_list;

  for (a = 0; a < cmds->cmds.cmds_len; a++)
    {

      master_list->cmds.cmds_len++;
      master_list->cmds.cmds_val = realloc (master_list->cmds.cmds_val, sizeof (struct command) * master_list->cmds.cmds_len);
      master_list->cmds.cmds_val[master_list->cmds.cmds_len - 1] = cmds->cmds.cmds_val[a];

      switch (cmds->cmds.cmds_val[a]->cmd_data.type)
	{
	case E_CMD_FOR_CMD:
	  linearise_commands (master_list, cmds->cmds.cmds_val[a]->cmd_data.command_data_u.for_cmd.for_commands);
	  break;

	case E_CMD_IF_CMD:
	  for (cnt = 0; cnt < cmds->cmds.cmds_val[a]->cmd_data.command_data_u.if_cmd.truths.conditions.conditions_len; cnt++)
	    {
	      linearise_commands (master_list,
				  cmds->cmds.cmds_val[a]->cmd_data.command_data_u.if_cmd.truths.conditions.conditions_val[cnt].
				  whentrue);
	    }
	  linearise_commands (master_list, cmds->cmds.cmds_val[a]->cmd_data.command_data_u.if_cmd.whenfalse);
	  break;

	case E_CMD_FOREACH_CMD:
	  linearise_commands (master_list, cmds->cmds.cmds_val[a]->cmd_data.command_data_u.foreach_cmd.foreach_commands);
	  break;

	case E_CMD_WHILE_CMD:
	  linearise_commands (master_list, cmds->cmds.cmds_val[a]->cmd_data.command_data_u.while_cmd.while_commands);
	  break;


	case E_CMD_CASE_CMD:
	  for (cnt = 0; cnt < cmds->cmds.cmds_val[a]->cmd_data.command_data_u.case_cmd.whens->whens.whens_len; cnt++)
	    {
	      linearise_commands (master_list,
				  cmds->cmds.cmds_val[a]->cmd_data.command_data_u.case_cmd.whens->whens.whens_val[cnt]->
				  when_commands);
	    }
	  linearise_commands (master_list, cmds->cmds.cmds_val[a]->cmd_data.command_data_u.case_cmd.otherwise);
	  break;


	case E_CMD_MENU_CMD:
	  evt_list = cmds->cmds.cmds_val[a]->cmd_data.command_data_u.menu_cmd.events;
	  linearise_commands_from_events (master_list, evt_list);
	  break;
	case E_CMD_PROMPT_CMD:
	  evt_list = cmds->cmds.cmds_val[a]->cmd_data.command_data_u.prompt_cmd.events;
	  linearise_commands_from_events (master_list, evt_list);
	  break;

	case E_CMD_DISPLAY_ARRAY_CMD:
	  evt_list = cmds->cmds.cmds_val[a]->cmd_data.command_data_u.display_array_cmd.events;
	  linearise_commands_from_events (master_list, evt_list);
	  break;

	case E_CMD_INPUT_CMD:
	  evt_list = cmds->cmds.cmds_val[a]->cmd_data.command_data_u.input_cmd.events;
	  linearise_commands_from_events (master_list, evt_list);
	  break;

	case E_CMD_INPUT_ARRAY_CMD:
	  evt_list = cmds->cmds.cmds_val[a]->cmd_data.command_data_u.input_array_cmd.events;
	  linearise_commands_from_events (master_list, evt_list);
	  break;
	case E_CMD_CONSTRUCT_CMD:
	  evt_list = cmds->cmds.cmds_val[a]->cmd_data.command_data_u.construct_cmd.events;
	  linearise_commands_from_events (master_list, evt_list);
	  break;

	default:
	  // dont need to do anything - these don't embed Commands..
	  break;
	}

    }

  return master_list;
}


struct s_commands *
linearise_report (struct s_commands *all_cmds, report_format_section * report_format_section)
{
  int b;
  if (all_cmds == 0)
    {
      all_cmds = linearise_commands (0, 0);
    }
  for (b = 0; b < report_format_section->entries.entries_len; b++)
    {
      linearise_commands (all_cmds, report_format_section->entries.entries_val[b]->rep_sec_commands);
    }
  return all_cmds;
}

void
linearise_module (struct s_commands *all_cmds, module_definition * d)
{
  int a;
//int b;
  for (a = 0; a < d->module_entries.module_entries_len; a++)
    {
      //struct s_function_definition *f;


      switch (d->module_entries.module_entries_val[a]->met_type)
	{

	case E_MET_MAIN_DEFINITION:
	case E_MET_FUNCTION_DEFINITION:
	  linearise_commands (all_cmds, d->module_entries.module_entries_val[a]->module_entry_u.function_definition.func_commands);
	  break;

	case E_MET_REPORT_DEFINITION:
	  linearise_report (all_cmds,
			    d->module_entries.module_entries_val[a]->module_entry_u.report_definition.reportFormatSection);
	  break;

	case E_MET_PDF_REPORT_DEFINITION:
	  linearise_report (all_cmds,
			    d->module_entries.module_entries_val[a]->module_entry_u.pdf_report_definition.reportFormatSection);
	  break;

	  // We dont need to worry about these commands....
	case E_MET_CMD:
	case E_MET_IMPORT_FUNCTION_DEFINITION:
	case E_MET_CLASS_DEFINITION:
	case E_MET_IMPORT_LEGACY_DEFINITION:
	case E_MET_FORMHANDLER_DEFINITION:
	case E_MET_IMPORT_DATATYPE:
	case E_MET_IMPORT_PACKAGE:

	  break;

	}
    }

}




static void linearise_expression(expr_str_list *l,  expr_str *e ) {
  if (e==NULL) return;

  A4GL_new_append_ptr_list(l,e);
  switch (e->expr_type)
    {
      //case ET_EXPR_LITERAL_EMPTY_STRING:
    case ET_EXPR_LITERAL_STRING:
    case ET_EXPR_IDENTIFIER:
    case ET_EXPR_LITERAL_LONG:
    case ET_EXPR_GET_FLDBUF:
    case ET_EXPR_FIELD_TOUCHED:
    case ET_EXPR_NOT_FIELD_TOUCHED:
      break;



	case ET_EXPR_VARIABLE_USAGE_WITH_ASC_DESC:
		break;

    	case ET_EXPR_OP_IN:
    	case ET_EXPR_OP_NOT_IN:
		linearise_expression(l,  e->expr_str_u.expr_in->expr);
		linearise_expression_list(l,  e->expr_str_u.expr_in->elist);
		break;



    case ET_EXPR_VARIABLE_USAGE:
      break;

    case ET_EXPR_EXPR_LIST:
      {
	int a;
	for (a = 0; a < e->expr_str_u.expr_list->list.list_len; a++)
	  {
	    linearise_expression (l, e->expr_str_u.expr_list->list.list_val[a]);
	  }
      }
      break;

    case ET_EXPR_FCALL:
      {

	int a;
	if (e->expr_str_u.expr_function_call->parameters)
	  {
	    for (a = 0;
		 a <
		 e->expr_str_u.expr_function_call->parameters->list.list_len;
		 a++)
	      {
		linearise_expression (l, e->expr_str_u.  expr_function_call->parameters->list.  list_val[a]);
	      }
	  }
      }

      break;


    case ET_EXPR_OP_ADD:
    case ET_EXPR_OP_AND:
    case ET_EXPR_OP_CONCAT:
    case ET_EXPR_OP_DIV:
    case ET_EXPR_OP_EQUAL:
    case ET_EXPR_OP_GREATER_THAN:
    case ET_EXPR_OP_GREATER_THAN_EQ:
    case ET_EXPR_OP_LESS_THAN:
    case ET_EXPR_OP_LESS_THAN_EQ:
    case ET_EXPR_OP_LIKE:
    case ET_EXPR_OP_MATCHES:
    case ET_EXPR_OP_MOD:
    case ET_EXPR_OP_MULT:
    case ET_EXPR_OP_NOT_EQUAL:
    case ET_EXPR_OP_NOT_LIKE:
    case ET_EXPR_OP_NOT_MATCHES:
    case ET_EXPR_OP_OR:
    case ET_EXPR_OP_POWER:
    case ET_EXPR_OP_SUB:
    case ET_EXPR_OP_USING:

        linearise_expression (l, e->expr_str_u.expr_op->left);
        linearise_expression (l, e->expr_str_u.expr_op->right);
      break;


    case ET_EXPR_INFIELD:
      break;

    case ET_EXPR_EXTEND:
      linearise_expression (l, e->expr_str_u.expr_extend->expr);
      break;




    case ET_EXPR_LITERAL_DOUBLE_STR:
      break;





    case ET_EXPR_FGL_ISDYNARR_ALLOCATED:
    case ET_EXPR_BRACKET:
    case ET_EXPR_TIME_FUNC:
    case ET_EXPR_MONTH_FUNC:
    case ET_EXPR_DAY_FUNC:
    case ET_EXPR_YEAR_FUNC:
    case ET_EXPR_UPSHIFT:
    case ET_EXPR_CURSOR_NAME_FUNCTION:
    case ET_EXPR_DOWNSHIFT:
    case ET_EXPR_ASCII:
    case ET_EXPR_POINTS:
    case ET_EXPR_CM:
    case ET_EXPR_MM:
    case ET_EXPR_INCHES:
    case ET_EXPR_DATE_FUNC:
    case ET_EXPR_COLUMN:
    case ET_EXPR_OP_SPACES:
    case ET_EXPR_OP_ISNULL:
    case ET_EXPR_OP_ISNOTNULL:
    case ET_EXPR_NOT:
    case ET_EXPR_OP_CLIP:
    case ET_EXPR_OP_YEAR:
    case ET_EXPR_OP_MONTH:
    case ET_EXPR_OP_DAY:
    case ET_EXPR_OP_HOUR:
    case ET_EXPR_OP_MINUTE:
    case ET_EXPR_VARIABLE_IDENTIFIER:
    case ET_EXPR_OP_SECOND:
    case ET_EXPR_WHERE_CURRENT_OF:
    case ET_EXPR_REFERENCE:
    case ET_EXPR_PDF_X:
    case ET_EXPR_PDF_Y:
      linearise_expression (l, e->expr_str_u.expr_expr);
      break;

    case ET_EXPR_TODAY:
    case ET_EXPR_DATE_EXPR:
    case ET_EXPR_CURRENT:
    case ET_EXPR_TIME:
    case ET_EXPR_LINENO:
    case ET_EXPR_PAGENO:
    case ET_EXPR_NULL:
    case ET_EXPR_TRUE:
    case ET_EXPR_FALSE:
    case ET_EXPR_REDUCED:
    case ET_EXPR_REPORT_PRINTER:
    case ET_EXPR_STRING:
    case ET_EXPR_LITERAL_EMPTY_STRING:
    case ET_EXPR_TIME_EXPR:
    case ET_EXPR_RETURN_NULL:
    case ET_EXPR_MENU_ALL:
    case ET_E_V_OR_LIT_NOVALUE:
    case ET_EXPR_MODULE_FUNC:
    case ET_EXPR_PDF_CURRENT_X:
    case ET_EXPR_PDF_CURRENT_Y:
    case ET_EXPR_SQLERRMESSAGE:
      break;


    case ET_EXPR_CAST:
      linearise_expression (l, e->expr_str_u.expr_cast->expr);
      break;

    case ET_EXPR_ASSOC:
    case ET_EXPR_PARAMETER:
    case ET_EXPR_BOUND_FCALL:
    case ET_EXPR_SHARED_FCALL:
    case ET_EXPR_MEMBER_FCALL_NEW:
    case ET_EXPR_DYNARR_FCALL_NEW:
      break;


    default:
      break;
      //printf ("Unhandled expression in dynamic sql(%s)\n", expr_name (e->expr_type));
    }
}

static void linearise_expression_list(expr_str_list *l1, expr_str_list *srclist) {
  int a;
  //int cnt = 0;
  if (srclist == 0)
    return ;
  if (srclist->list.list_len == 0)
    return ;

  for (a = 0; a < srclist->list.list_len; a++)
    {
	linearise_expression(l1, srclist->list.list_val[a]);
    }
}

static void add_expressions_cmd (struct s_commands *cmds,expr_str_list *l)
{
  int a;

  for (a = 0; a < cmds->cmds.cmds_len; a++)
    {
      struct command *c;
      c = cmds->cmds.cmds_val[a];



      switch (c->cmd_data.type)
	{
	case E_CMD_DISPLAY_CMD:
	  {
	    struct_display_cmd *disp;
	    disp = &c->cmd_data.command_data_u.display_cmd;
	    linearise_expression_list (l, disp->exprs);
	    if (disp->where->dttype == DT_DISPLAY_TYPE_AT)
	      {
		linearise_expression (l, disp->where->dt_display_u.x_y.x);
		linearise_expression (l, disp->where->dt_display_u.x_y.y);
	      }
	  }
	  break;


	case E_CMD_ERROR_CMD:
	  linearise_expression_list (l,
				 c->cmd_data.command_data_u.error_cmd.
				 expr_list);
	  break;

	case E_CMD_SLEEP_CMD:
	  linearise_expression (l,
			    c->cmd_data.command_data_u.sleep_cmd.sleep_expr);
	  break;

	case E_CMD_MOVE_CMD:
	  linearise_expression (l,
			    c->cmd_data.command_data_u.move_cmd.x);
	  linearise_expression (l,
			    c->cmd_data.command_data_u.move_cmd.y);
	  break;

	case E_CMD_SHOW_MENU_CMD:
	  linearise_expression (l,
			    c->cmd_data.command_data_u.show_menu_cmd.mn_file);
	  break;

	case E_CMD_RUN_CMD:
	  linearise_expression (l,
			    c->cmd_data.command_data_u.run_cmd.run_string);
	  break;

	case E_CMD_RUN_WAITING_FOR_CMD:
	  linearise_expression (l,
			    c->cmd_data.command_data_u.run_waiting_for_cmd.
			    run_string);
	  linearise_expression (l,
			    c->cmd_data.command_data_u.run_waiting_for_cmd.
			    sleep);
	  linearise_expression (l,
			    c->cmd_data.command_data_u.run_waiting_for_cmd.
			    msg_repeat_every);
	  linearise_expression (l,
			    c->cmd_data.command_data_u.run_waiting_for_cmd.
			    msg_text);
	  break;

	case E_CMD_SCROLL_CMD:
	  linearise_expression (l,
			    c->cmd_data.command_data_u.scroll_cmd.val);
	  break;

	case E_CMD_EXIT_PROG_CMD:
	  linearise_expression (l,
			    c->cmd_data.command_data_u.exit_prog_cmd.
			    exit_val);
	  break;

	case E_CMD_RETURN_CMD:
	  linearise_expression_list (l,
				 c->cmd_data.command_data_u.return_cmd.retvals);
	  break;

	case E_CMD_MESSAGE_CMD:
	  linearise_expression_list (l,
				 c->cmd_data.command_data_u.message_cmd.
				 message_expr);
	  break;

	case E_CMD_FOR_CMD:
	  linearise_expression (l,
			    c->cmd_data.command_data_u.for_cmd.start);
	  linearise_expression (l,
			    c->cmd_data.command_data_u.for_cmd.end);
	  linearise_expression (l,
			    c->cmd_data.command_data_u.for_cmd.step);
	  break;

	case E_CMD_CALL_CMD:
	  linearise_expression (l,
			    c->cmd_data.command_data_u.call_cmd.fcall);
	  break;

	case E_CMD_PDF_CALL_CMD:
	  linearise_expression (l, c->cmd_data.command_data_u.pdf_call_cmd.fcall);
	  break;

	case E_CMD_INIT_CMD:
	  		linearise_expression_list (l, c->cmd_data.command_data_u.init_cmd.varlist);
	  		linearise_expression_list (l, c->cmd_data.command_data_u.init_cmd.init_like_exprlist);
		break;

	case E_CMD_LET_CMD:
	  linearise_expression_list (l, c->cmd_data.command_data_u.let_cmd.vars);
	  linearise_expression_list (l, c->cmd_data.command_data_u.let_cmd.vals);
	  break;

	case E_CMD_IF_CMD:
	  {
	    struct struct_if_cmd *ifcmd;
	    int b;
	    ifcmd = &c->cmd_data.command_data_u.if_cmd;
	    for (b = 0; b < ifcmd->truths.conditions.conditions_len; b++)
	      {
			linearise_expression (l, ifcmd->truths.conditions.conditions_val[b].  test_expr);
	      }
	  }
	  break;

	case E_CMD_CASE_CMD:
	  {
	    struct struct_case_cmd *casecmd;
	    int b;
	    casecmd = &c->cmd_data.command_data_u.case_cmd;
	    linearise_expression (l, casecmd->case_expr);

	    for (b = 0; b < casecmd->whens->whens.whens_len; b++)
	      {
		linearise_expression (l, casecmd->whens->whens.whens_val[b]-> when_expr);
	      }
	  }
	  break;


	case E_CMD_TODO_CMD:
	  {
	    struct struct_todo_cmd *todocmd;
	    int b;
	    todocmd = &c->cmd_data.command_data_u.todo_cmd;
	    linearise_expression (l, todocmd->todo_expr);

	    for (b = 0; b < todocmd->whens->whens.whens_len; b++)
	      {
		linearise_expression ( l, todocmd->whens->whens.whens_val[b]-> when_expr);
	      }
	  }
	  break;


	case E_CMD_OPEN_WINDOW_CMD:
	  linearise_expression (l,
			    c->cmd_data.command_data_u.open_window_cmd.x);
	  linearise_expression (l,
			    c->cmd_data.command_data_u.open_window_cmd.y);
	  if (c->cmd_data.command_data_u.open_window_cmd.wt.wintype ==
	      EWT_FORM)
	    {
	      linearise_expression (l,
				c->cmd_data.command_data_u.open_window_cmd.wt.
				windowtype_u.formfilename);
	    }
	  break;

	case E_CMD_FETCH_CMD:
	  if (c->cmd_data.command_data_u.fetch_cmd.fetch)
	    {
	      if (c->cmd_data.command_data_u.fetch_cmd.fetch->fp)
		{
		  linearise_expression (l,
				    c->cmd_data.command_data_u.fetch_cmd.
				    fetch->fp->fetch_expr);
		}
	    }
	  break;

	case E_CMD_OPEN_FORM_CMD:
	  linearise_expression (l,
			    c->cmd_data.command_data_u.open_form_cmd.
			    form_filename);
	  break;

	case E_CMD_WHILE_CMD:
	  linearise_expression (l,
			    c->cmd_data.command_data_u.while_cmd.while_expr);
	  break;

	case E_CMD_OUTPUT_CMD:
	  linearise_expression_list (l,
				 c->cmd_data.command_data_u.output_cmd.
				 expressions);
	  break;

	case E_CMD_SET_DATABASE_CMD:
	  linearise_expression (l,
			    c->cmd_data.command_data_u.set_database_cmd.
			    set_dbname);
	  break;

	case E_CMD_NEED_CMD:
	  linearise_expression (l,
			    c->cmd_data.command_data_u.need_cmd.expr);
	  break;

	case E_CMD_PRINT_CMD:
	  linearise_expression_list (l,
				 c->cmd_data.command_data_u.print_cmd.
				 print_expr);
	  break;

	case E_CMD_PRINT_IMG_CMD:
	  linearise_expression (l,
			    c->cmd_data.command_data_u.print_img_cmd.scale_x);
	  linearise_expression (l,
			    c->cmd_data.command_data_u.print_img_cmd.scale_y);
	  break;

	default:
	  break;
	}

    }
}


void linearise_expressions_in_commands(struct s_commands *cmds, expr_str_list *list) {
struct s_commands *all_cmds;
  all_cmds = linearise_commands (0, 0); 
  linearise_commands (all_cmds, cmds);
  add_expressions_cmd(all_cmds,list);
}

#include "a4gl_lib_lex_esqlc_int.h"
#define ONE_NOT_ZERO(x) (x?x:1)
#include "field_handling.h"
#include "compile_c.h"
#include "cmd_funcs.h"
#define set_nonewlines() set_nonewlines_full(__LINE__)

static int idle_cnt = 0;


extern int tmp_ccnt;
extern int line_for_cmd;
extern int parent_stack_cnt;
extern command *parent_stack[];
static int rep_print_entry=0;



int clr_rep_print_entry(void) {
	rep_print_entry=0;
	return 1;
}


char *local_field_name_list_as_char(struct fh_field_list *fl) {
int a;
char *ptr=0;
char *ptr_field;

A4GL_assertion(fl==0,"No field list...");

ptr=acl_malloc2(10); /* Set it up initially...*/
strcpy(ptr,"");
for (a=0;a<fl->field_list_entries.field_list_entries_len;a++) {
	if (fl->field_list_entries.field_list_entries_val[a].fieldsub) {
        	ptr_field=A4GL_field_name_as_char(local_ident_as_string(fl->field_list_entries.field_list_entries_val[a].field,1), local_expr_as_string(fl->field_list_entries.field_list_entries_val[a].fieldsub));
	} else {
        	ptr_field=A4GL_field_name_as_char(local_ident_as_string(fl->field_list_entries.field_list_entries_val[a].field,1), "1");

	}
        ptr=acl_realloc(ptr,strlen(ptr)+strlen(ptr_field)+2);
        if (strlen(ptr)) strcat(ptr,",");
        strcat(ptr,ptr_field);
}

return ptr;
}



void
print_cmd_start (void)
{
  printc ("\n\naclfgli_clr_err_flg();");
}

/******************************************************************************/
int
print_stop_rpc_cmd (void)
{
  print_cmd_start ();
  printc ("A4GL_stop_serving();");
  print_copy_status_not_sql (0);
  return 1;
}


/******************************************************************************/
int
print_pause_screen_on_cmd (void)
{
  print_cmd_start ();
  printc ("A4GL_screen_mode(1);");
  print_copy_status_not_sql (0);
  return 1;
}


/******************************************************************************/
int
print_pause_screen_off_cmd (void)
{
  print_cmd_start ();
  printc ("A4GL_screen_mode(1);");
  print_copy_status_not_sql (0);
  return 1;
}


/******************************************************************************/
int
print_skip_to_top_cmd (void)
{
  print_cmd_start ();
  printc ("A4GL_%sskip_top_of_page(&_rep,0);\n", ispdf ());
  print_copy_status_not_sql (0);
  return 1;
}


/******************************************************************************/
int
print_start_rpc_cmd (struct_start_rpc_cmd * cmd_data)
{
  int a;
  print_cmd_start ();
  for (a = 0; a < cmd_data->remote_func_list.name.name_len; a++)
    {
      char *identifier;
	char *namespace;
      identifier = cmd_data->remote_func_list.name.name_val[a];
	namespace=cmd_data->remote_func_list.namespaces.namespaces_val[a];
      add_function_to_header (identifier, namespace, 1, 0);
      printc ("A4GL_register_func(\"%s\",%s%s);if (a4gl_status<0) A4GL_chk_err(%d,_module_name);\n", identifier, namespace, identifier,
	      line_for_cmd);
    }

  printc ("{");
	printc("int _port; ");
  print_expr (cmd_data->valid_port);
  printc ("_port=A4GL_pop_long()+0x2000000;");
  printc ("A4GL_server_run(_port);");
  printc("}");

  for (a = 0; a < cmd_data->remote_func_list.name.name_len; a++)
    {
      char *identifier;
      identifier = cmd_data->remote_func_list.name.name_val[a];
      printc ("A4GL_unregister_func(\"%s\");\n", identifier);
    }
  print_copy_status_not_sql (0);
  return 1;
}

/******************************************************************************/
int
print_call_cmd (struct_call_cmd * cmd_data)
{
  enum e_expr_type t;
  print_cmd_start ();

  t = cmd_data->fcall->expr_type;

  real_print_func_call (cmd_data->fcall);
  if (t == ET_EXPR_BOUND_FCALL)
    {
      print_returning_g (1, cmd_data->returning, 1);
    }
  else
    {
      print_returning_g (1, cmd_data->returning, 0);
    }

  print_copy_status_not_sql (0);
  return 1;
}


/******************************************************************************/
int
print_cancel_cmd (struct_cancel_cmd * cmd_data)
{
  print_cmd_start ();
  A4GL_assertion (1, "CANCEL not implemented yet");
  return 0;
}


/******************************************************************************/
int
print_case_cmd (struct_case_cmd * cmd_data)
{
  int a;

  print_cmd_start ();
  if (cmd_data->case_expr)
    {
      printc ("{char *_s=0;");
      print_expr (cmd_data->case_expr);
      printc ("while (1==1) {if (_s==0) {_s=A4GL_char_pop();}\n");
    }
  else
    {
      printc ("while (1==1) {\n");
    }

  tmp_ccnt++;
  for (a = 0; a < cmd_data->whens->whens.whens_len; a++)
    {
      dump_comments (cmd_data->whens->whens.whens_val[a]->lineno);
      print_when (cmd_data->case_expr != 0, cmd_data->whens->whens.whens_val[a]->when_expr);
      dump_commands (cmd_data->whens->whens.whens_val[a]->when_commands);
	 tmp_ccnt--;
      printc ("break;");
	printc("}");
	
    }
  printc("/* OTHERWISE... */");
  dump_commands (cmd_data->otherwise);
  printc ("break;");
  tmp_ccnt--;
  printc ("} /* end of the while for the case */");

  if (cmd_data->case_expr)
    {
      printc ("if (_s) free(_s);");
      printc ("}");
    }


  print_copy_status_not_sql (0);
  return 1;
}


/******************************************************************************/
int
print_close_cmd (struct_close_cmd * cmd_data)
{
  print_cmd_start ();
  set_nonewlines ();
  switch (cmd_data->cl_type)
    {
    case E_CT_WINDOW:
      printc ("A4GL_remove_window(\n");
      print_ident (cmd_data->ident);
      printc (");");
      break;
    case E_CT_FORM:
      printc ("A4GL_close_form(\n");
      print_ident (cmd_data->ident);
      printc (");");
      break;

    case E_CT_STATUSBOX:
      printc ("A4GL_remove_window(\n");
      print_ident (cmd_data->ident);
      printc (");");
      break;
    }
  clr_nonewlines ();
  print_copy_status_not_sql (0);
  return 1;
}


/******************************************************************************/
int
print_code_cmd (struct_code_cmd * cmd_data)
{
  printc ("%s", cmd_data->contents);
  return 1;
}


/******************************************************************************/
int
print_defer_cmd (struct_defer_cmd * cmd_data)
{
  switch (cmd_data->what)
    {
    case EDEFER_QUIT:
      printc ("A4GL_def_quit();");
      break;
    case EDEFER_INTERRUPT:
      printc ("A4GL_def_int();");
      break;
    }
  print_copy_status_not_sql (0);
  return 1;
}


/******************************************************************************/
int
print_display_b_n_cmd (struct_display_b_n_cmd * cmd_data)
{
  print_cmd_start ();
  A4GL_assertion (1, "Should be converted to a display");
  return 1;
}


/******************************************************************************/
int
print_display_cmd (struct_display_cmd * cmd_data)
{
  print_cmd_start ();
  print_clr_status ();
  switch (cmd_data->where->dttype)
    {
    case DT_DISPLAY_TYPE_LINE:
      real_print_expr_list (cmd_data->exprs);
      printc ("A4GL_push_int(-1);");
      printc ("A4GL_push_int(-1);");
      printc ("A4GL_display_at(%d,0x%x);", cmd_data->exprs->list.list_len, attributes_as_int (cmd_data->attributes));
      break;


    case DT_DISPLAY_TYPE_AT:
      real_print_expr_list (cmd_data->exprs);
      set_nonewlines ();
      print_expr (cmd_data->where->dt_display_u.x_y.y);
      clr_nonewlines ();

      set_nonewlines ();
      print_expr (cmd_data->where->dt_display_u.x_y.x);
      clr_nonewlines ();
      printc ("A4GL_display_at(%d,0x%x);", cmd_data->exprs->list.list_len, attributes_as_int (cmd_data->attributes));
      break;


    case DT_DISPLAY_TYPE_FIELD_LIST:
      real_print_expr_list (cmd_data->exprs);

      printc ("A4GL_disp_fields(%d,0x%x,%s,NULL);",
	      cmd_data->exprs->list.list_len,
	      attributes_as_int (cmd_data->attributes), local_field_name_list_as_char (cmd_data->where->dt_display_u.field_list));

      break;
    case DT_DISPLAY_TYPE_MENUITEM:
      A4GL_assertion (1, "Not implemented yet");
      break;

    case DT_DISPLAY_TYPE_MAIN_CAPTION:
      A4GL_assertion (1, "Not implemented yet");
      break;

    case DT_DISPLAY_TYPE_FORM_FIELD:
      A4GL_assertion (1, "Not implemented yet");
      break;

    case DT_DISPLAY_TYPE_FORM_CAPTION:
      A4GL_assertion (1, "Not implemented yet");
      break;

    case DT_DISPLAY_TYPE_STATUSBOX:
      A4GL_assertion (1, "Not implemented yet");
      break;

    }
  print_copy_status_not_sql (0);
  return 1;
}


/******************************************************************************/
int
print_display_form_cmd (struct_display_form_cmd * cmd_data)
{
  print_cmd_start ();
  set_nonewlines ();
  printc ("A4GL_disp_form(");
  print_ident (cmd_data->formname);
  printc (",%d);\n", attributes_as_int (cmd_data->attributes));
  clr_nonewlines ();
  print_copy_status_not_sql (0);
  return 1;
}


/******************************************************************************/
int
print_error_cmd (struct_error_cmd * cmd_data)
{
  print_cmd_start ();
  A4GL_print_expr_list_concat (cmd_data->expr_list);
  printc ("A4GL_display_error(%d,%d);\n", attributes_as_int (cmd_data->attributes), cmd_data->wait_for_key==EB_TRUE);
  print_copy_status_not_sql (0);
  return 1;
}


/******************************************************************************/
int
print_ext_cmd (struct_ext_cmd * cmd_data)
{

  if (cmd_data->what == EBC_MENU)
    {
      printc ("cmd_no_%d= -3;goto MENU_START_%d;\n", cmd_data->block_id, cmd_data->block_id);
      return 1;
    }
  if (cmd_data->what == EBC_PROMPT)
    {
      printc ("SET(\"s_prompt\",_sio_%d,\"mode\",1);\n", cmd_data->block_id);
      return 1;
    }


  printc ("goto END_BLOCK_%d;", cmd_data->block_id);
  return 1;

}


/******************************************************************************/
int
print_continue_cmd (struct_continue_cmd * cmd_data)
{
  //enum e_block_cmd what;
  //int block_id;
  if (cmd_data->what == EBC_INPUT || cmd_data->what == EBC_CONSTRUCT)
    {
      printc ("if (_fld_dr==-95) {A4GL_req_field(&_sio_%d,_inp_io_type,'0',\"0\",NULL,0);} /* re-enter INPUT if we're in an AFTER INPUT */ \n", cmd_data->sio_id);
      printc ("_fld_dr= -1;_exec_block= -1;\n");
      return 1;
    }

  printc ("goto CONTINUE_BLOCK_%d;", cmd_data->block_id);
  return 1;
}


/******************************************************************************/
int
print_exit_prog_cmd (struct_exit_prog_cmd * cmd_data)
{

  print_cmd_start ();
  if (cmd_data->exit_val)
    {
      print_expr (cmd_data->exit_val);
    }
  else
    {

    }

  if (doing_esql ())
    {
      struct_close_sql_cmd cmd_data;
      printc ("if (A4GL_esql_db_open(-1,0,0,\"\")) {");
	cmd_data.cl_type=E_CT_DATABASE;
	print_close_sql_cmd(&cmd_data,1);
      printc ("}");
    }

  if (cmd_data->exit_val)
    printc ("A4GL_fgl_end();exit(A4GL_pop_long());");
  else
    printc ("A4GL_fgl_end();exit(0);");

  print_copy_status_not_sql (0);
  return 1;
}




/******************************************************************************/
int
print_for_cmd (struct_for_cmd * cmd_data)
{
  struct expr_str *from;
  struct expr_str *to;
  struct expr_str *step;
  int have_from = 0;
  int have_to = 0;
  int have_step = 0;
  int from_l = 0;
  int to_l = 0;
  int step_l = 0;

  print_cmd_start ();
  from = cmd_data->start;
  to = cmd_data->end;
  step = cmd_data->step;

  if (from->expr_type == ET_EXPR_LITERAL_LONG)
    {
      have_from = 1;
      from_l = from->expr_str_u.expr_long;
    }
  if (to->expr_type == ET_EXPR_LITERAL_LONG)
    {
      have_to = 1;
      to_l = to->expr_str_u.expr_long;
    }
  if (step)
    {
      if (step->expr_type == ET_EXPR_LITERAL_LONG)
	{
	  have_step = 1;
	  step_l = step->expr_str_u.expr_long;
	}
    }
  else
    {
      have_step = 1;
      step_l = 1;
    }
  printc ("{");
  tmp_ccnt++;
  if (!have_from)
    printc ("int _s;");
  else
    printc ("int _s=%ld;", from_l);

  if (!have_to)
    printc ("int _e;");
  else
    printc ("int _e=%ld;", to_l);

  if (!have_step)
    printc ("int _step;");
  else
    printc ("int _step=%ld;", step_l);

  if (!have_from)
    {
      print_expr (from);
      printc ("_s=A4GL_pop_long();");
    }

  printc ("%s=_s;", local_expr_as_string (cmd_data->var));
  printc ("while (1) {");
  tmp_ccnt++;

  if (!have_to)
    {
      print_expr (to);
      printc ("_e=A4GL_pop_long();");
    }
  if (have_step)
    {
      if (step_l >= 0)
	{
	  printc ("  if (%s>_e) break;", local_expr_as_string (cmd_data->var));
	}
      else
	{
	  printc ("  if (%s<_e) break;", local_expr_as_string (cmd_data->var));
	}
    }
  else
    {
      print_expr (step);
      printc ("  _step=A4GL_pop_long();");
      printc ("  if (%s>_e && _step>=0) break;", local_expr_as_string (cmd_data->var));
      printc ("  if (%s<_e && _step<0) break;", local_expr_as_string (cmd_data->var));
    }


  dump_commands (cmd_data->for_commands);
  printc("CONTINUE_BLOCK_%d:    ; ", cmd_data->block_id);

  printc ("%s+=_step;", local_expr_as_string (cmd_data->var));
  tmp_ccnt--;
  printc ("}");
  tmp_ccnt--;
  printc ("}\n");
  printc("END_BLOCK_%d:    ; ", cmd_data->block_id);

  return 1;
}


/******************************************************************************/
int
print_goto_cmd (struct_goto_cmd * cmd_data)
{				// 30%
  printc ("goto %s;\n", cmd_data->label);
  return 1;
}


/******************************************************************************/
int
print_check_menu_cmd (struct_check_menu_cmd * cmd_data)
{
// str_list* strlist;
  print_cmd_start ();
  printc ("A4GL_check_menuitems(");
  print_str_list (cmd_data->strlist);
  printc (",NULL);");
  print_copy_status_not_sql (0);
  return 1;

}


/******************************************************************************/
int
print_uncheck_menu_cmd (struct_uncheck_menu_cmd * cmd_data)
{
  print_cmd_start ();
  printc ("A4GL_uncheck_menuitems(");
  print_str_list (cmd_data->strlist);
  printc (",NULL);");
  print_copy_status_not_sql (0);
  return 1;


}


/******************************************************************************/
int
print_disable_menu_cmd (struct_disable_menu_cmd * cmd_data)
{
//str_list*  strlist;
  print_cmd_start ();
  printc ("A4GL_endis_menuitems(0,");
  print_str_list (cmd_data->strlist);
  printc (",NULL);");
  print_copy_status_not_sql (0);
  return 1;
}


/******************************************************************************/
int
print_enable_menu_cmd (struct_enable_menu_cmd * cmd_data)
{
  print_cmd_start ();
  printc ("A4GL_endis_menuitems(1,");
  print_str_list (cmd_data->strlist);
  printc (",NULL);");
  print_copy_status_not_sql (0);
  return 1;
}


/******************************************************************************/
int
print_msg_box_cmd (struct_msg_box_cmd * cmd_data)
{
  //struct expr_str_list *msg;
  //struct expr_str_list *caption;
  //int icon;
  //int buttons;
  //int default_button;
  //int disable;
  //struct expr_str *returning;

  A4GL_assertion (1, "Not implemented");
  return 0;
}


/******************************************************************************/
int
print_if_cmd (struct_if_cmd * cmd_data)
{
  int uses_elif = 0;
  int a;

  print_cmd_start ();

  //if_conds truths;
  //int lineno;
  //int else_lineno;
  //commands *whenfalse;
  if (cmd_data->truths.conditions.conditions_len > 1)
    {
      uses_elif = 1;
      printc ("while (1) {");	// Give us something to break to..
    }

  for (a = 0; a < cmd_data->truths.conditions.conditions_len; a++)
    {
      dump_comments (cmd_data->truths.conditions.conditions_val[a].lineno);
      print_expr (cmd_data->truths.conditions.conditions_val[a].test_expr);
      printc ("if (A4GL_pop_bool()) {\n");
      tmp_ccnt++;
      dump_commands (cmd_data->truths.conditions.conditions_val[a].whentrue);
      if (uses_elif)
	{
	  printc ("break;");
	}
      tmp_ccnt--;
      printc ("}");
    }

  if (uses_elif)
    {
      // If we get to here in the generated code - its failed all the previous tests..
      if (cmd_data->whenfalse)
	{
	  dump_commands (cmd_data->whenfalse);
	}
      printc ("break;");
      printc("}");

    }
  else
    {
      if (cmd_data->whenfalse)
	{
	  dump_comments (cmd_data->else_lineno);
	  printc (" else {\n");
	  tmp_ccnt++;
	  dump_commands (cmd_data->whenfalse);
	  tmp_ccnt--;
	  printc ("}");
	}
    }
  print_copy_status_not_sql (0);
 return 1;
}


/******************************************************************************/
int
print_next_field_cmd (struct_next_field_cmd * cmd_data)
{
  print_cmd_start ();
  set_nonewlines ();

  if (cmd_data->rel == 1)
    {
      printc ("A4GL_req_field(&_sio_%d,_inp_io_type,'+',\"+\",NULL,0);\n", cmd_data->sio);
    }
  else
    {
      if (cmd_data->rel == -1)
	{
	  printc ("A4GL_req_field(&_sio_%d,_inp_io_type,'-',\"-\",NULL,0);\n", cmd_data->sio);
	}
      else
	{
	  printc ("A4GL_req_field(&_sio_%d,_inp_io_type,'!',", cmd_data->sio);
	  print_field (cmd_data->nextfield);
	  printc (",NULL,0);\n");
	}
    }

  clr_nonewlines ();

  printc ("_fld_dr= -1;_exec_block= -1;\n");
  print_copy_status_not_sql (0);
  return 1;
}


/******************************************************************************/
int
print_next_form_cmd (struct_next_form_cmd * cmd_data)
{
  print_cmd_start ();
  //str form;
  //str field;
  print_niy ("NEXT FORM FIELD");

  return 0;
}


/******************************************************************************/
int
print_scroll_cmd (struct_scroll_cmd * cmd_data)
{				// 40%
  print_cmd_start ();
  //struct fh_field_list *srec;
  //struct expr_str* val;
  set_nonewlines ();
  printc("{int _scrollval;");
  print_expr (cmd_data->val);
	printc("_scrollval=A4GL_pop_long();");
  printc ("A4GL_acli_scroll(_scrollval,\n");
  print_field_list (cmd_data->srec);
  printc (",NULL,0);\n");
  printc("}");
  clr_nonewlines ();
  print_copy_status_not_sql (0);
  return 1;
}


/******************************************************************************/
int
print_label_cmd (struct_label_cmd * cmd_data)
{
  printc ("%s: ;\n", cmd_data->label);
  print_cmd_start ();
  return 1;
}


/******************************************************************************/
int
print_let_cmd (struct_let_cmd * cmd_data)
{				// 50% !
  //struct expr_str_list* vars;

  print_cmd_start ();
  if (cmd_data->vars->list.list_len > 1)
    {
      struct expr_str_list *ptr;
      int from_exprs;
      int to_vars;

      ptr = A4GL_rationalize_list (cmd_data->vals);
      from_exprs = A4GL_new_list_get_count (ptr);
      real_print_expr_list (ptr);
      printc ("{");
      to_vars = print_bind_dir_definition_g (cmd_data->vars, 1, 'o');
      local_print_bind_set_value_g (cmd_data->vars, 1, 0, 'o');

      if (to_vars != from_exprs)
	{
	  A4GL_assertion (1, "Should be right by here...");
	  A4GL_debug ("to_Vars = %d from_Exprs = %d\n", to_vars, from_exprs);
	  return 0;
	}
      printc ("A4GL_pop_params(obind,%d);", from_exprs);
      printc ("}");
    }
  else
    {
      if (cmd_data->vals==NULL) { // LET x = NULL
		printc ("A4GL_push_null(2,0);\n");
      		print_pop_usage (cmd_data->vars->list.list_val[0]);
      } else {
      		A4GL_print_expr_list_concat (cmd_data->vals);
      		print_pop_usage (cmd_data->vars->list.list_val[0]);
      }
    }


  print_copy_status_not_sql (0);
  return 1;

}




/******************************************************************************/
int
print_at_term_cmd (struct_at_term_cmd * cmd_data)
{
  print_cmd_start ();
  print_niy ("AT TERMINATION");
  return 0;
}


/******************************************************************************/
int
print_return_cmd (struct_return_cmd * cmd_data)
{
  struct expr_str_list *expr;
  int n;
  int z;

  print_cmd_start ();

	printPopFunction();
  expr = A4GL_rationalize_list (cmd_data->retvals);
  n = A4GL_new_list_get_count (expr);

  real_print_expr_list (expr);


  for (z = 0; z < parent_stack_cnt; z++)
    {
      // If we're returning - we need to close out any outstanding screen IO
      switch (parent_stack[z]->cmd_data.type)
	{
	case E_CMD_INPUT_ARRAY_CMD:
	  printc ("A4GL_finish_screenio(&_sio_%d,_sio_kw_%d);",
		  parent_stack[z]->cmd_data.command_data_u.input_array_cmd.sio,
		  parent_stack[z]->cmd_data.command_data_u.input_array_cmd.sio);
	  break;
	case E_CMD_INPUT_CMD:
	  printc ("A4GL_finish_screenio(&_sio_%d,_sio_kw_%d);",
		  parent_stack[z]->cmd_data.command_data_u.input_cmd.sio, parent_stack[z]->cmd_data.command_data_u.input_cmd.sio);
		break;
	case E_CMD_CONSTRUCT_CMD:
	  printc ("A4GL_finish_screenio(&_sio_%d,_sio_kw_%d);",
		  parent_stack[z]->cmd_data.command_data_u.construct_cmd.sio,
		  parent_stack[z]->cmd_data.command_data_u.construct_cmd.sio);
		break;
	case E_CMD_DISPLAY_ARRAY_CMD:
	  printc ("A4GL_finish_screenio(&_sio_%d,_sio_kw_%d);",
		  parent_stack[z]->cmd_data.command_data_u.display_array_cmd.sio,
		  parent_stack[z]->cmd_data.command_data_u.display_array_cmd.sio);
		break;
	case E_CMD_PROMPT_CMD:
	  printc ("A4GL_finish_screenio(&_sio_%d,_sio_kw_%d);",
		  parent_stack[z]->cmd_data.command_data_u.prompt_cmd.sio, parent_stack[z]->cmd_data.command_data_u.prompt_cmd.sio);
		break;
	default:
		// We dont care about other commands
		break;
	}
    }


  if (!is_in_report ())
    printc ("return %d;", n);
  else
    printc ("return ;");


  return 1;
}



/******************************************************************************/

static void  print_menu_option (expr_str *s) {
	switch (s->expr_type) {
		case ET_EXPR_MENU_ALL:
			printc("MENU_ALL");
			break;
		case ET_EXPR_LITERAL_STRING:
			printc("%s", s->expr_str_u.expr_string);
			break;
		default:
			printc("%s", local_expr_as_string(s));
			break;
	}
	//A4GL_assertion(1,"Not implemented");
}

static void print_menu_option_list(expr_str_list *slist ) {
	int a;
	for (a=0;a<slist->list.list_len;a++) {
		if (a) printc(",");
		print_menu_option(slist->list.list_val[a]);
	}
}


/******************************************************************************/
int
print_next_option_cmd (struct_next_option_cmd * cmd_data)
{
  int mn;
  print_cmd_start ();
  mn = get_last_menuid ();
  if (mn < 0)
    {
      a4gl_yyerror ("Not in a menu");
      return 0;
    }

  set_nonewlines ();
  printc ("A4GL_next_option(m_%d, ", mn);
  print_menu_option (cmd_data->menuoption);
  printc (");");
  clr_nonewlines ();

  print_copy_status_not_sql (0);
  return 1;

}


/******************************************************************************/
int
print_show_option_cmd (struct_show_option_cmd * cmd_data)
{
  int mn;
  print_cmd_start ();
  mn = get_last_menuid ();
  if (mn < 0)
    {
      a4gl_yyerror ("Not in a menu");
      return 0;
    }

  set_nonewlines ();
  printc ("A4GL_menu_show(m_%d,", mn);
  print_menu_option_list (cmd_data->menuoptions);
  printc (",NULL);");
  clr_nonewlines ();
  print_copy_status_not_sql (0);
  return 1;
}


/******************************************************************************/
int
print_hide_option_cmd (struct_hide_option_cmd * cmd_data)
{
  int mn;
  print_cmd_start ();
  mn = get_last_menuid ();
  if (mn < 0)
    {
      a4gl_yyerror ("Not in a menu");
      return 0;
    }

  set_nonewlines ();
  printc ("A4GL_menu_hide(m_%d,", mn);
  print_menu_option_list (cmd_data->menuoptions);
  printc (",NULL);");

  clr_nonewlines ();

  print_copy_status_not_sql (0);
  return 1;
}


/******************************************************************************/
int
print_message_cmd (struct_message_cmd * cmd_data)
{
  struct expr_str_list *expr;
  int exprs;
  int wait;
  print_cmd_start ();
  expr = A4GL_rationalize_list (cmd_data->message_expr);
  exprs = A4GL_new_list_get_count (expr);
  real_print_expr_list (expr);
  if (cmd_data->wait==EB_TRUE) {
		wait=1;
	} else {
		wait=0;
	}

  printc ("aclfgli_pr_message(%d,%d,%d);\n", attributes_as_int (cmd_data->attributes), wait, exprs);

  print_copy_status_not_sql (0);
  return 1;

}


/******************************************************************************/
int
print_open_window_cmd (struct_open_window_cmd * cmd_data)
{
  set_nonewlines ();
  print_cmd_start ();
  if (cmd_data->wt.wintype == EWT_ROWSCOLS)
    {
      print_expr (cmd_data->y);
      print_expr (cmd_data->x);
      print_expr (cmd_data->wt.windowtype_u.rowscols.rows);
      print_expr (cmd_data->wt.windowtype_u.rowscols.columns);
      printc ("A4GL_cr_window(");
      print_ident (cmd_data->windowname);
      printc (",");
    }
  if (cmd_data->wt.wintype == EWT_FORM)
    {
      print_expr (cmd_data->y);
      print_expr (cmd_data->x);
      print_expr (cmd_data->wt.windowtype_u.formfilename);
      printc ("A4GL_cr_window_form(");
      print_ident (cmd_data->windowname);
      printc (",");

    }


  print_form_attrib_v2 (1, cmd_data->attributes);
  if (cmd_data->attributes && cmd_data->attributes->style && strlen(cmd_data->attributes->style))
    {
      printc (",\"%s\"", cmd_data->attributes->style);
    }
  else
    {
      printc (",0");
    }
  if (cmd_data->attributes && cmd_data->attributes->text && strlen(cmd_data->attributes->text))
    {
      printc (",\"%s\"", cmd_data->attributes->text);
    }
  else
    {
      printc (",0");
    }
  printc (");\n");

  clr_nonewlines ();
  print_copy_status_not_sql (0);
  return 1;
}


/******************************************************************************/
int
print_open_statusbox_cmd (struct_open_statusbox_cmd * cmd_data)
{
  print_cmd_start ();
  print_niy ("OPEN_STATUSBOX");
  return 0;
}


/******************************************************************************/
int
print_open_form_cmd (struct_open_form_cmd * cmd_data)
{
  //struct expr_str* formname;
  //struct expr_str* form_filename;

  print_cmd_start ();
  set_nonewlines ();
  print_expr (cmd_data->form_filename);
  printc ("A4GL_open_form(");
  print_ident (cmd_data->formname);
  printc (");");
  clr_nonewlines ();

  print_copy_status_not_sql (0);
  return 1;

}


/******************************************************************************/
int
print_open_form_gui_cmd (struct_open_form_gui_cmd * cmd_data)
{
  //struct expr_str *form;
  //struct expr_str *y;
  //struct expr_str *x;
  //struct expr_str *like;
  //int disable;
  //str formhandler;

  print_cmd_start ();
set_nonewlines();
  printc ("A4GL_open_gui_form(&");
  printc("%s",A4GL_strip_quotes(get_ident_as_string (cmd_data->form)));
  printc (",");
  printc("%s",get_ident_as_string (cmd_data->form));
  printc (",");
	if (cmd_data->x) {
  		print_expr (cmd_data->x);
	} else {
		printc("0");
	}
  	printc (",");
	if (cmd_data->y) {
  		print_expr (cmd_data->y);
	} else {
		printc("0");
	}
  printc (",");
	if (cmd_data->like) {
  		print_expr (cmd_data->like);
	} else {
		printc("0");
	}
  printc (",");
  printc ("%d,hnd_e_%s,hnd_c_%s);", cmd_data->disable, cmd_data->formhandler, cmd_data->formhandler);

clr_nonewlines();
  print_copy_status_not_sql (0);
  return 1;
}





/******************************************************************************/
int
print_start_cmd (struct_start_cmd * cmd_data)
{
  expr_str *out;
  char where;
  print_cmd_start ();

  where = cmd_data->sc_c->towhat;
  out = cmd_data->sc_c->s1;



  add_function_to_header (cmd_data->repname, cmd_data->namespace, 2, 0);

  if (where==0)  {
  	printc ("A4GL_push_char(\"\");\n");
  	printc ("A4GL_push_char(\"\");\n");
		 
  } else {

  	printc ("A4GL_push_char(\"%c\");\n", where);
  			if (out)
    	{
      	print_expr (out);
    	}
  	else
    	{
      	printc ("A4GL_push_char(\"%c\");\n", where);
    	}
  }

  printc ("A4GL_set_report_dim(%d,%d,%d,%d,%d,\"%s\");",
	  cmd_data->sc_c->with_page_length,
	  cmd_data->sc_c->with_left_margin,
	  cmd_data->sc_c->with_right_margin,
	  cmd_data->sc_c->with_top_margin, cmd_data->sc_c->with_bottom_margin, cmd_data->sc_c->with_top_of_page);
  printc ("%s%s(2,REPORT_START);", cmd_data->namespace, cmd_data->repname);

  print_copy_status_with_sql (0); /* Can have an ORDER BY which causes a series of SQL statements */
  return 1;
}


/******************************************************************************/
int
print_convert_cmd (struct_convert_cmd * cmd_data)
{
  //str repname;
  //str namespace;
  //struct convert *conv_c;

  print_cmd_start ();

  if (cmd_data->conv_c->towhat == 'f') {
		char *str;
		// Convert via...
		//
		str=cmd_data->conv_c->s1->expr_str_u.expr_string;
		        add_function_to_header(str,"",1,0);
        		printc("A4GL_via_functionname(\"%s\",&%s%s,&%s);",cmd_data->repname,cmd_data->namespace,cmd_data->repname,str);
			
			// A4GL_via_functionname("r1",&aclfgl_r1,&aclfgl_test1);
		
		return 1;
  }
  if (cmd_data->conv_c->towhat == '@')
    {
      printc ("A4GL_push_int(2);");
    }
  else
    {
      if (cmd_data->conv_c->towhat == '|' || cmd_data->conv_c->towhat == 'P')
	{			// Pipe or Printer...
	  printc ("A4GL_push_int(1);");
	}
      else
	{
	  printc ("A4GL_push_int(0);");
	}
    }

  if (cmd_data->conv_c->s1)
    {
      print_expr (cmd_data->conv_c->s1);
    }
  else
    {
      printc ("A4GL_push_char(\"\");");
    }

  if (cmd_data->conv_c->conv_type)
    {
      print_expr (cmd_data->conv_c->conv_type);
    }
  else
    {
      printc ("A4GL_push_char(\"\");");
    }

  if (cmd_data->conv_c->filter)
    {
      print_expr (cmd_data->conv_c->filter);
    }
  else
    {
      printc ("A4GL_push_char(\"\");");
    }

  printc ("%s%s(3,REPORT_CONVERT);", cmd_data->namespace, cmd_data->repname);
  print_copy_status_not_sql (0);
  return 1;

}


/******************************************************************************/
int
print_free_rep_cmd (struct_free_rep_cmd * cmd_data)
{
  print_cmd_start ();
  printc ("%s%s(3,REPORT_FREE);", cmd_data->namespace, cmd_data->repname);
  print_copy_status_not_sql (0);
  return 1;

}

/******************************************************************************/
int
print_run_cmd (struct_run_cmd * cmd_data)
{
  int type;

  print_cmd_start ();
  type = 0;

  if (cmd_data->returning)
    type += 1;

  if (cmd_data->wait == EB_FALSE) // Default is to wait...
    type += 2;

  if (cmd_data->run_mode == ERM_FORM_MODE)
    {
      type += 512;
    }
  if (cmd_data->run_mode == ERM_LINE_MODE)
    {
      type += 256;
    }
  print_expr (cmd_data->run_string);
  printc ("A4GL_system_run(%d);", type);

  if (cmd_data->returning)
    {
      print_pop_usage (cmd_data->returning);
    }
  print_copy_status_not_sql (0);
  return 1;



}


/******************************************************************************/
int
print_sleep_cmd (struct_sleep_cmd * cmd_data)
{
  print_cmd_start ();
  print_expr (cmd_data->sleep_expr);
  printc ("A4GL_sleep_i();\n");

  print_copy_status_not_sql (0);
  return 1;

}




/******************************************************************************/
int
print_validate_cmd (struct_validate_cmd * cmd_data)
{
  int z;
  int a;
  int b;

  print_cmd_start ();
  z = cmd_data->list->list.list_len;
  for (a = 0; a < z; a++)
    {
      //char buff[256];
      struct expr_str *e;
      struct expr_str_list *p = 0;
      e = cmd_data->validate_list->list.list_val[a];
      if (e)
	{
	  A4GL_assertion (e->expr_type != ET_EXPR_EXPR_LIST, "Expecting a list");
	  p = e->expr_str_u.expr_list;
	}
      if (p == 0)
	continue;
      print_push_variable_usage (cmd_data->list->list.list_val[a]);
      for (b = 0; b < p->list.list_len; b++)
	{
	  print_expr (p->list.list_val[b]);
	}
      printc ("A4GL_push_int(%d);", p->list.list_len);
      printc ("A4GL_pushop(OP_IN);");
      printc ("if (!A4GL_pop_bool()) {A4GLSQL_set_status(-1321,0);}");
    }
  print_copy_status_not_sql (0);
  return 1;

}


/******************************************************************************/
int
print_whenever_cmd (struct_whenever_cmd * cmd_data)
{
  //set_whento (cmd_data->whencode);
  set_whenever (cmd_data->whencode, cmd_data->whento);
  return 1;
}


/******************************************************************************/
int
print_while_cmd (struct_while_cmd * cmd_data)
{
  print_cmd_start ();
  printc ("while (1==1) {\n");
  tmp_ccnt++;
  print_expr (cmd_data->while_expr);
  printc ("if (!(A4GL_pop_bool())) break;\n");
  dump_commands (cmd_data->while_commands);
  printc("CONTINUE_BLOCK_%d:    ;", cmd_data->block_id);
  tmp_ccnt--;
  printc ("}");
  printc("END_BLOCK_%d:    ;", cmd_data->block_id);
  return 1;
}

/******************************************************************************/
int
print_options_cmd (struct_options_cmd * cmd_data)
{
  int a;
  int i;
  print_cmd_start ();
//options
  for (a = 0; a < cmd_data->options->options.options_len; a++)
    {
      struct single_option *o;
      o = cmd_data->options->options.options_val[a];
      i = (int) o->option[0];
      switch (i)
	{

	case 'A': // Accept key
		printc("A4GL_set_option_value('A',A4GL_key_val(\"%s\"));",o->value); break;
	case 'D': // Delete key
		printc("A4GL_set_option_value('D',A4GL_key_val(\"%s\"));",o->value); break;
	case 'I': // Insert Key
		printc("A4GL_set_option_value('I',A4GL_key_val(\"%s\"));",o->value); break;
	case 'N': // Next Key
		printc("A4GL_set_option_value('N',A4GL_key_val(\"%s\"));",o->value); break;
	case 'p': // Previous Key
		printc("A4GL_set_option_value('p',A4GL_key_val(\"%s\"));",o->value); break;
	case 'H': // Help Key

		printc("A4GL_set_option_value('D',A4GL_key_val(\"%s\"));",o->value); break;

	case 'd':
	  	printc ("A4GL_set_option_value('%s',%s);", o->option, o->value);
		printc("A4GL_set_option_value('Z',0);");
		break;
	case 'i':
	  	printc ("A4GL_set_option_value('%s',%s);", o->option, o->value);
		printc("A4GL_set_option_value('Y',0);");

		break;

	case 'C':		//COMMENT_LINE
	case 'E':		//ERROR_LINE
	case 'F':		//FORM_LINE
	case 'M':		//MENU_LINE
	case 'm':		//MESSAGE_LINE
	case 'P':		//PROMPT_LINE
		set_nonewlines();
	  printc ("{long _val;");
	  print_expr (o->expr);
	  printc ("_val=A4GL_pop_long();");
	  printc ("A4GL_set_option_value('%c',_val);\n", i);
	  printc ("}");
		clr_nonewlines();
	  break;

	case 'h':		// HELP_FILE
	case 'L':		// LANG_FILE
		set_nonewlines();
	  printc ("{char *_val;");
	  print_expr (o->expr);
	  printc ("_val=A4GL_char_pop();");
	  if (i == 'h')
	    {
	      printc ("A4GL_set_help_file(_val);");
	    }
	  if (i == 'L')
	    {
	      printc ("A4GL_set_lang_file(_val);");
	    }
	  printc ("free(_val);}");
		clr_nonewlines();
	break;
	default:
	  printc ("A4GL_set_option_value('%s',%s);", o->option, o->value);
	}
    }

  print_copy_status_not_sql (0);
  return 1;

}

/******************************************************************************/
int
print_clear_cmd (struct_clear_cmd * cmd_data)
{

  print_cmd_start ();
  switch (cmd_data->clr_data.clr_type)
    {

    case E_CLR_SCREEN:
      printc ("A4GL_current_window(\"screen\");");
      printc ("A4GL_clr_window(\"screen\");\n");
      break;

    case E_CLR_FORM:
	    printc ("A4GL_clr_form(0);");
      break;

    case E_CLR_FORM_DEFAULTS:
	    printc ("A4GL_clr_form(1);");
      //printc ("A4GL_clr_form_fields(1,0);");
      break;

    case E_CLR_WINDOW:
      set_nonewlines ();
      printc ("A4GL_clr_window(");
      print_ident (cmd_data->clr_data.clear_data_u.window);
      printc (");");
      clr_nonewlines ();
      break;

    case E_CLR_STATUS:
      set_nonewlines ();
      printc ("A4GL_clr_window(");
      print_ident (cmd_data->clr_data.clear_data_u.statwindow);
      printc (");");
      clr_nonewlines ();
      break;

    case E_CLR_FIELDS:
      {
	char *flds;
	flds = local_field_name_list_as_char (cmd_data->clr_data.clear_data_u.fields);
	printc ("A4GL_clr_fields(%d,%s,NULL,0);", cmd_data->todefaults==EB_TRUE, flds);
      }
      break;


    case E_CLR_FIELDS_TO_DEFAULT:
      A4GL_assertion (1, "Not used - marked for deletion");
      break;

    }

  print_copy_status_not_sql (0);
  return 1;
}


/******************************************************************************/
int
print_current_win_cmd (struct_current_win_cmd * cmd_data)
{
  print_cmd_start ();
  set_nonewlines ();
  printc ("A4GL_current_window(");
	if (cmd_data->windowname) {
  		print_ident (cmd_data->windowname);
	} else {
		printc("\"screen\"");
	}
  printc (");");
  clr_nonewlines ();
  print_copy_status_not_sql (0);
  return 1;
}


/******************************************************************************/
int
print_show_cmd (struct_show_cmd * cmd_data)
{
  print_cmd_start ();
  set_nonewlines ();
  printc ("A4GL_show_window(");
  print_ident (cmd_data->windowname);
  printc (");");
  clr_nonewlines ();
  print_copy_status_not_sql (0);
  return 1;

}


/******************************************************************************/
int
print_hide_cmd (struct_hide_cmd * cmd_data)
{
  print_cmd_start ();
  set_nonewlines ();
  printc ("A4GL_hide_window(");
  print_ident (cmd_data->windowname);
  printc (");");
  clr_nonewlines ();
  print_copy_status_not_sql (0);
  return 1;

}


/******************************************************************************/
int
print_move_cmd (struct_move_cmd * cmd_data)
{				// 90 %

  print_cmd_start ();
  print_expr (cmd_data->y);
  print_expr (cmd_data->x);

  set_nonewlines ();
  printc ("A4GL_movewin(");
  print_ident (cmd_data->windowname);
  printc (",%d);", cmd_data->relative == 0);
  clr_nonewlines ();

  print_copy_status_not_sql (0);
  return 1;
}



/******************************************************************************/
int
print_show_menu_cmd (struct_show_menu_cmd * cmd_data)
{
  print_cmd_start ();
  print_expr (cmd_data->mn_file);
  printh ("void aclfglmn_%s(char *);\n", cmd_data->menuhandler);
  printc ("A4GL_show_menu(\"%s\",aclfglmn_%s);\n", cmd_data->menuname, cmd_data->menuhandler);
  print_copy_status_not_sql (0);
  return 1;

}


/******************************************************************************/
int
print_enable_cmd (struct_enable_cmd * cmd_data)
{
  print_cmd_start ();
  printc ("A4GL_endis_fields(1,%s,NULL,0);\n", local_field_name_list_as_char (cmd_data->srec));
  print_copy_status_not_sql (0);
  return 1;
}


/******************************************************************************/
int
print_enable_form_cmd (struct_enable_form_cmd * cmd_data)
{
  print_cmd_start ();
  set_nonewlines ();
  printc ("A4GL_endis_form(1,");
  print_ident (cmd_data->formname);
  printc (",%s,0);\n", local_field_name_list_as_char (cmd_data->srec));
  clr_nonewlines ();

  print_copy_status_not_sql (0);
  return 1;
}


/******************************************************************************/
int
print_disable_cmd (struct_disable_cmd * cmd_data)
{
  print_cmd_start ();
  printc ("A4GL_endis_fields(0,%s,NULL,0);\n", local_field_name_list_as_char (cmd_data->srec));
  print_copy_status_not_sql (0);
  return 1;
}


/******************************************************************************/
int
print_disable_form_cmd (struct_disable_form_cmd * cmd_data)
{
  print_cmd_start ();
  set_nonewlines ();
  printc ("A4GL_endis_form(1,");
  print_ident (cmd_data->formname);
  printc (",%s,0);\n", local_field_name_list_as_char (cmd_data->srec));
  clr_nonewlines ();

  print_copy_status_not_sql (0);
  return 1;
}


/******************************************************************************/
int
print_pdf_call_cmd (struct_pdf_call_cmd * cmd_data)
{
  struct s_expr_pdf_function_call *p;
  print_cmd_start ();
  A4GL_assertion (cmd_data->fcall->expr_type != ET_EXPR_PDF_FCALL, "Expected a ET_EXPR_PDF_FCALL");
  p = cmd_data->fcall->expr_str_u.expr_pdf_function_call;

  real_print_expr_list (p->parameters);
  printc ("{int _retvars;A4GLSQL_set_status(0,0);\n");
  if (is_in_report ())
    {
      printc ("_retvars=A4GL_pdf_pdffunc(&_rep,%s,%s);\n", p->fname, p->fname, p->parameters->list.list_len);
    }
  else
    {
      printc ("_retvars=A4GL_pdf_pdffunc(0,%s,%s);\n", p->fname, p->parameters->list.list_len);
    }

  print_returning_g (2, cmd_data->returning, 0);

  print_copy_status_not_sql (0);
  return 1;

}





/******************************************************************************/
int
print_init_cmd (struct_init_cmd * cmd_data)
{
  print_cmd_start ();
      int a;
			int printed=0;
  //struct expr_str_list* varlist;
  //str_list* tablist;
      for (a = 0; a < cmd_data->varlist->list.list_len; a++)
	{
	  struct variable_usage *u;
	  struct variable_usage *u_bottom;
	  struct variable *v;
		printed=0;
	  A4GL_assertion (cmd_data->varlist->list.list_val[a]->expr_type != ET_EXPR_VARIABLE_USAGE, "Expecting a variable usage");
	  u = cmd_data->varlist->list.list_val[a]->expr_str_u.expr_variable_usage;

	  v = local_find_variable_from_usage (u);

	  u_bottom = u;

	  while (u_bottom->next) {
	    u_bottom = u_bottom->next;
	   }

	  if (v->arr_subscripts.arr_subscripts_len)
	    {
	      // The variable is an array..
	      if (u_bottom->subscripts.subscripts_len == 0)
		{
		  // We need to null the whole variable
		  print_init_var (v, generation_get_variable_usage_as_string (u), 0, 1, 1,1);
		}
	      else
		{
		  struct variable v2;
		  if (u_bottom->subscripts.subscripts_len != v->arr_subscripts.arr_subscripts_len)
		    {
		      a4gl_yyerror ("Subscript mismatch");
		      return 0;
		    }
		  // We need to null the this specific on..
		  memcpy (&v2, v, sizeof (v2));
		  v2.arr_subscripts.arr_subscripts_len = 0;
		  v2.arr_subscripts.arr_subscripts_val = 0;


		  if (cmd_data->tablist) {
			if (cmd_data->init_like_exprlist && cmd_data->init_like_exprlist->list.list_len<=a) {
				if ( cmd_data->init_like_exprlist->list.list_val[a]) {
					print_expr(cmd_data->init_like_exprlist->list.list_val[a]);
					print_pop_usage(cmd_data->varlist->list.list_val[a]);
					printed=1;
				}
			}
		  }

		  if (!printed) {
		 	print_init_var (v, generation_get_variable_usage_as_string (u), 0, 1, 1,0);
		  }
		}
	    }
	  else
	    {
		  if (cmd_data->tablist) {
			if (cmd_data->init_like_exprlist && a<cmd_data->init_like_exprlist->list.list_len) {
				if ( cmd_data->init_like_exprlist->list.list_val[a]) {
					print_expr(cmd_data->init_like_exprlist->list.list_val[a]);
					print_pop_usage(cmd_data->varlist->list.list_val[a]);
					printed=1;
				}
			}
		  }
		  if (!printed) {
			char *s;
			s=generation_get_variable_usage_as_string(u);
	      		// Its not an array..
	      		print_init_var (v, s, 0, 1, 1,1);
		}
	    }

	}

  print_copy_status_not_sql (0);
return 1;
}

static int encode_variable_datatype(int dtype, int size1,int size2) {
A4GL_assertion(size2>0,"Expecting size2 to always be 0");
	return dtype+(size1<<16);
}



/******************************************************************************/
int
print_display_array_cmd (struct_display_array_cmd * cmd_data)
{
  int cnt;
  int nevents;
//int a;
  int sio_id;
  struct variable *v;

  //struct expr_str * srec;
  //struct expr_str * arrayname;
  //struct attrib *attributes;
  //struct on_events* events;
  //struct fh_field_entry* scroll_using;
  //int sio;
  //int blockid;
  //str slice;
  //int slice_start;
  //int slice_end;
  print_cmd_start ();

  sio_id=cmd_data->sio;
  nevents=0;
  if (cmd_data->events) {
		nevents=cmd_data->events->event.event_len;
   }
// void LEXLIB_print_display_array_p1 (char *arrvar, char *srec, char *scroll, char *attr, void *v_input_attr,char *Style,t_binding_comp_list *bind,char *slice) {



  printcomment ("/* Display array */\n");
  printc ("{");
	tmp_ccnt++;
  printc ("int _fld_dr;int _exec_block= 0;\nchar *_curr_win=0;char _sio_%d[%d];char *_sio_kw_%d=\"s_disp_arr\";\n",sio_id, sizeof (struct s_disp_arr) + 10,sio_id);
  print_event_list(cmd_data->events);


  A4GL_assertion(cmd_data->arrayname->expr_type!=ET_EXPR_VARIABLE_USAGE,"Expecting a variable usage");


/* We dont get passed in a real binding - just the variable
 * so we need to generate our own binding....
 *
 * The array can be one of two types
 * 1) A simple array ( eg ARRAY OF char(20))
 * 2) A record array ( eg ARRAY OF RECORD ... END RECORD )
 *
 * So - lets first have a look and see which type we've got
 * */
  v=local_find_variable_from_usage(cmd_data->arrayname->expr_str_u.expr_variable_usage);
  if (v->var_data.variable_type==VARIABLE_TYPE_RECORD) {
	int a;
	struct variable *v2;
	struct variable_usage *vu_top;
	struct variable_usage *vu_next;
	struct expr_str *vu_as_expr;

	/* Its an array of RECORD */
	cnt=v->var_data.variable_data_u.v_record.variables.variables_len;
	printc("static struct BINDING obind[%d]={",cnt);

	/* First - we need to print the 'obind' - which has the types */
	for (a=0;a<v->var_data.variable_data_u.v_record.variables.variables_len;a++) {
		int dtype;
		v2=v->var_data.variable_data_u.v_record.variables.variables_val[a];
		if (v2->var_data.variable_type!=VARIABLE_TYPE_SIMPLE) {
			a4gl_yyerror("Expecting only simple types in the array");
			return 0;
		}
		dtype=encode_variable_datatype(v2->var_data.variable_data_u.v_simple.datatype, v2->var_data.variable_data_u.v_simple.dimensions[0], v2->var_data.variable_data_u.v_simple.dimensions[1]);

	 	printc("{NULL,%d,%d,0,0,0}%s", dtype&DTYPE_MASK,DECODE_SIZE(dtype), (a==v->var_data.variable_data_u.v_record.variables.variables_len)?"":",");
	}
	printc("};");

	/* Now - we need to print the array itself..
 		we could assume the array is a top level array and just display it directly
		but what I'm trying to do here is to generate a 'variable_usage' for each
		line so we can print that instead..
		in theory - it means we can display array an array which is inside another record/array...
	*/
	for (a=0;a<v->var_data.variable_data_u.v_record.variables.variables_len;a++) {
			v2=v->var_data.variable_data_u.v_record.variables.variables_val[a];
	                vu_top=clone_variable_usage(cmd_data->arrayname->expr_str_u.expr_variable_usage);
                        vu_next=vu_top;
                        while (vu_next->next) {
                                vu_next=vu_next->next;
                        }
		        vu_next->subscripts.subscripts_len=1;
                        vu_next->subscripts.subscripts_val=malloc(sizeof(struct expr_str *));
			vu_next->subscripts.subscripts_val[0]=A4GL_new_literal_long_long(1);
                        vu_next->next=malloc(sizeof(struct variable_usage));
                        vu_next->next->variable_name=v->var_data.variable_data_u.v_record.variables.variables_val[a]->names.names.names_val[0].name;
                        vu_next->next->subscripts.subscripts_len=0;
                        vu_next->next->subscripts.subscripts_val=0;
                        vu_next->next->substrings_start=0;
                        vu_next->next->substrings_end=0;
                        vu_next->next->next=0;
                        vu_next->next->datatype=v2->var_data.variable_data_u.v_simple.datatype;
                        vu_next->next->scope=cmd_data->arrayname->expr_str_u.expr_variable_usage->scope;
                        vu_next->next->variable_id=a;
			vu_as_expr=A4GL_new_expr_push_variable(vu_top);
			set_nonewlines();
			printc("obind[%d].ptr= &",a);
			print_variable_usage(vu_as_expr);
			printc(";");
			clr_nonewlines();

	}
  } else {
	// Its a simple array of a single datatype
	// just a little easier than the record !
  	cnt = 1;
	printc("static struct BINDING obind[1]={ {NULL,%d,%d,0,0,0} };",v->var_data.variable_data_u.v_simple.datatype &DTYPE_MASK,DECODE_SIZE(v->var_data.variable_data_u.v_simple.datatype));
	set_nonewlines();
	printc("obind[0].ptr= &");
	print_variable_usage(cmd_data->arrayname);
	printc("[0];");
	clr_nonewlines();
  }




/* Now onto the rest of it... */

  printc ("_curr_win=A4GL_get_currwin_name();\n");
  printc ("SET(\"s_disp_arr\",_sio_%d,\"no_arr\",A4GL_get_count());\n",sio_id);
  printc ("SET(\"s_disp_arr\",_sio_%d,\"binding\",obind);\n",sio_id);
  printc ("SET(\"s_disp_arr\",_sio_%d,\"nbind\",%d);\n",sio_id, cnt);
  printc ("SET(\"s_disp_arr\",_sio_%d,\"srec\",0);\n",sio_id);
  printc ("SET(\"s_disp_arr\",_sio_%d,\"start_slice\",%d);\n",sio_id,cmd_data->slice_start);
  printc ("SET(\"s_disp_arr\",_sio_%d,\"end_slice\",%d);\n",sio_id,cmd_data->slice_end);

   if (cmd_data->attributes && cmd_data->attributes->currentrowdisplay && strlen(cmd_data->attributes->currentrowdisplay))
    printc ("SET(\"s_disp_arr\",_sio_%d,\"curr_display\",%s);\n",sio_id, cmd_data->attributes->currentrowdisplay);
  else
    printc ("SET(\"s_disp_arr\",_sio_%d,\"curr_display\",0);\n",sio_id);
  

  set_nonewlines();
  printc ("SET(\"s_disp_arr\",_sio_%d,\"arr_elemsize\",sizeof(",sio_id);
	print_variable_usage(cmd_data->arrayname);
	printc("[0]));\n");
  clr_nonewlines();
  printc ("_fld_dr= -1;_exec_block=0;\n");
  printc ("while (1) {\n");
   tmp_ccnt++;
print_event_actions("_fld_dr",cmd_data->events);

	printc("CONTINUE_BLOCK_%d: ; ", cmd_data->blockid);

if (cmd_data->events) {
	nevents=cmd_data->events->event.event_len;
} else {
	nevents=0;
}

  printc("if (_exec_block==%d) { break; } ",nevents+1);

  printc("A4GL_ensure_current_window_is(_curr_win);");
  print_reset_state_after_call(0);

  set_nonewlines();
  printc ("_exec_block=A4GL_disp_arr_v2(&_sio_%d,", sio_id);
  print_variable_usage(cmd_data->arrayname);
  printc(",");
  print_ident(cmd_data->srec);
  printc(",%d,", attributes_as_int(cmd_data->attributes));
  if (cmd_data->scroll_using) {
  	print_field(cmd_data->scroll_using);
  } else {
	printc("NULL,0");
  }
  printc(",_sio_evt);");
  clr_nonewlines();

  printc("if (_exec_block==-999)  {break;}");
	tmp_ccnt--;
  printc ("}\n");
	tmp_ccnt--;
  printc ("}\n");
printc("END_BLOCK_%d:;", cmd_data->blockid);

  //print_reset_state_after_call();
  printcomment ("/* end display */\n");




  print_copy_status_not_sql (0);
  return 1;

}





/******************************************************************************/
int
print_construct_cmd (struct_construct_cmd * cmd_data)
{
int sio_id;
int nevents;
int ccc;
  int a;
struct expr_str_list *li;
  //enum e_boolean by_name;
  //struct expr_str* constr_var;
  //cons_list* con_columns;
  //struct fh_field_list* list;
  //struct on_events* events;
  //struct attrib *attributes;
  //enum e_boolean without_defaults;
  //int helpno;
  //int sio;
  //int blockid;
  sio_id=cmd_data->sio;
  nevents=0;

  if (cmd_data->events) {
                nevents=cmd_data->events->event.event_len;
  }

  print_cmd_start ();

  printc("{");
  tmp_ccnt++;
/* print_bind_dir_definition_g expects a list of variables - not just a singleton
 * so we need to make it into a list before we pass it in */
  li= A4GL_new_ptr_list (cmd_data->constr_var);
  print_bind_dir_definition_g(li,1,'i'); // LEXLIB_print_bind_definition_g (bind); // print_bind_dir_definition_g

/* from print_constr */
  printc ("struct s_constr_list constr_flds[%d]={\n", cmd_data->con_columns->list.list_len);
  for (a = 0; a < cmd_data->con_columns->list.list_len; a++)
    {
      if (a > 0)
        printc (",\n");
      printc ("{\"%s\",\"%s\"}", cmd_data->con_columns->list.list_val[a]->tabname, cmd_data->con_columns->list.list_val[a]->colname);
    }
  printc ("\n};");
  ccc = cmd_data->con_columns->list.list_len;


  sio_id=cmd_data->sio;
  printc ("int _fld_dr= -100;int _exec_block= 0;char *_fldname;int _sf;");
  printc("char _sio_%d[%d]; char *_curr_win=0; char _inp_io_type='C'; char *_sio_kw_%d=\"s_screenio\";\n", sio_id,sizeof (struct s_screenio) + 10,sio_id);
  printc ("int _forminit=1;\n");
print_event_list(cmd_data->events);
   local_print_bind_set_value_g (li,1,0,'i');
  printc ("while(_fld_dr!=0){\n");
  tmp_ccnt++;
  printc ("if (_exec_block == 0) {\n");
  tmp_ccnt++;
  printc ("_curr_win=A4GL_get_currwin_name();\n");
  printc ("SET(\"s_screenio\",_sio_%d,\"vars\",ibind);\n",sio_id);
  printc ("SET(\"s_screenio\",_sio_%d,\"novars\",%d);\n", sio_id,ccc);
  printc ("SET(\"s_screenio\",_sio_%d,\"attrib\",%d);\n", sio_id,attributes_as_int(cmd_data->attributes));
  printc
    ("SET(\"s_screenio\",_sio_%d,\"currform\",A4GL_get_curr_form(1));\n",sio_id);
  printc ("SET(\"s_screenio\",_sio_%d,\"currentfield\",0);\n",sio_id);
  printc ("SET(\"s_screenio\",_sio_%d,\"currentmetrics\",0);\n",sio_id);
  printc ("SET(\"s_screenio\",_sio_%d,\"constr\",constr_flds);\n",sio_id);
  printc ("SET(\"s_screenio\",_sio_%d,\"mode\",%d);\n",sio_id, MODE_CONSTRUCT);
  printc ("SET(\"s_screenio\",_sio_%d,\"processed_onkey\",0);\n",sio_id);
  printc ("SET(\"s_screenio\",_sio_%d,\"field_list\",0);\n",sio_id);

      printc
        ("SET(\"s_screenio\",_sio_%d,\"nfields\",A4GL_gen_field_chars((void ***)GETPTR(\"s_screenio\",_sio_%d,\"field_list\"),(void *)GET(\"s_screenio\",_sio_%d,\"currform\"),%s,NULL));\n",sio_id,sio_id,sio_id,
         local_field_name_list_as_char(cmd_data->list ));

  printc
    ("_sf=A4GL_set_fields(&_sio_%d); A4GL_debug(\"_sf=%%d\",_sf);if(_sf==0) {_fld_dr=0;break;}\n",sio_id);
  printc ("_fld_dr= -1;\n");
  tmp_ccnt--;
  printc ("} /* end of initialization */\n");

  print_event_actions ("_exec_block", cmd_data->events);

  printc("if (_exec_block== %d) { break; } ",nevents+1);

  printc("A4GL_ensure_current_window_is(_curr_win);");
  printc ("_exec_block = A4GL_form_loop_v2(&_sio_%d,_forminit,_sio_evt);_forminit=0;\n", sio_id);
  printc("if (_exec_block>0) _fld_dr=_sio_evt[_exec_block-1].event_type; else _fld_dr= -1;");
  printc("CONTINUE_BLOCK_%d:    ;   /* add_continue */",cmd_data->blockid);
 tmp_ccnt--;
  printc ("\n}\n");
  printc("END_BLOCK_%d:    ;   /* add_continue */",cmd_data->blockid);
  printc (" A4GL_push_constr(&_sio_%d);\n ",sio_id);
  printc (" A4GL_pop_params(ibind,1);");
 tmp_ccnt--;
  printc ("}\n");
  print_reset_state_after_call(1);

  print_copy_status_not_sql (0);
  return 1;

}



/******************************************************************************/
int
print_input_cmd (struct_input_cmd * cmd_data)
{
int sio_id;
int nevents;
int ccc;
  //struct expr_str_list* variables;
  //struct fh_field_list* field_list;
  //struct on_events* events;
  //struct attrib *attributes;
  //enum e_boolean by_name;
  //enum e_boolean without_defaults;
  //int helpno;
  //int sio;
  //int blockid;

  sio_id=cmd_data->sio;
  nevents=0;
  if (cmd_data->events) {
		nevents=cmd_data->events->event.event_len;
   }
  print_cmd_start ();

  printc ("{\nint _fld_dr= -100;\nint _exec_block= 0;\nchar *_fldname;char *_curr_win;int _sf;\n");
  ccc=cmd_data->variables->list.list_len;
  print_bind_dir_definition_g (cmd_data->variables,1,'i');
  printc("char _sio_%d[%d];", sio_id,sizeof (struct s_screenio) + 10);
  printc("char _inp_io_type='I';");
  printc("char *_sio_kw_%d=\"s_screenio\";", sio_id);
  printc ("int _forminit=1;\n");
  print_event_list(cmd_data->events);
  printc ("while(_fld_dr!=0){\n");
  tmp_ccnt++;
  printc ("if (_fld_dr== -100) {\n");
  tmp_ccnt++;
  printc ("/* input by name */");
  local_print_bind_set_value_g (cmd_data->variables,1,0,'i');
  printc ("_curr_win=A4GL_get_currwin_name();\n");
  printc ("SET(\"s_screenio\",&_sio_%d,\"currform\",A4GL_get_curr_form(1));\n",sio_id);
  printc ("if (GET_AS_INT(\"s_screenio\",&_sio_%d,\"currform\")==0) break;\n",sio_id);
  printc ("SET(\"s_screenio\",&_sio_%d,\"vars\",ibind);\n",sio_id);
  printc ("SET(\"s_screenio\",&_sio_%d,\"attrib\",%d);\n",sio_id, attributes_as_int(cmd_data->attributes) );
  printc ("SET(\"s_screenio\",&_sio_%d,\"novars\",%d);\n",sio_id, ccc);
  printc ("SET(\"s_screenio\",&_sio_%d,\"help_no\",%d);\n",sio_id, cmd_data->helpno);

  printc ("SET(\"s_screenio\",&_sio_%d,\"processed_onkey\",0);\n",sio_id);
  printc ("SET(\"s_screenio\",&_sio_%d,\"field_list\",0);\n",sio_id);

  printc ("SET(\"s_screenio\",&_sio_%d,\"currentfield\",0);\n",sio_id);
  printc ("SET(\"s_screenio\",&_sio_%d,\"currentmetrics\",0);\n",sio_id);
  printc ("SET(\"s_screenio\",&_sio_%d,\"mode\",%d);\n",sio_id, MODE_INPUT + (cmd_data->without_defaults==EB_TRUE));
      printc
        ("SET(\"s_screenio\",&_sio_%d,\"nfields\",A4GL_gen_field_chars((void ***)GETPTR(\"s_screenio\",&_sio_%d,\"field_list\"),(void *)GET(\"s_screenio\",&_sio_%d,\"currform\"),%s,NULL));\n", sio_id,sio_id,sio_id, local_field_name_list_as_char(cmd_data->field_list));
      printc
        ("if (GET_AS_INT(\"s_screenio\",&_sio_%d,\"nfields\")==-1) break;\n",sio_id);
  printc ("_sf=A4GL_set_fields(&_sio_%d); A4GL_debug(\"_sf=%%d\",_sf);if(_sf==0) {_fld_dr=0;break;}\n",sio_id);
  printc ("_fld_dr= -1;_exec_block=0;\n");

  tmp_ccnt--;

  printc ("} /* end of initialization */\n");
print_event_actions ("_exec_block", cmd_data->events);


  printc("if (_exec_block==%d) { break; } ",nevents+1);
  printc("A4GL_ensure_current_window_is(_curr_win);");
  printc ("_exec_block=A4GL_form_loop_v2(&_sio_%d,_forminit,_sio_evt);_forminit=0;\n",sio_id);

  printc("if (_exec_block>0) _fld_dr=_sio_evt[_exec_block-1].event_type; else _fld_dr= -1;");

printc("CONTINUE_BLOCK_%d:    ;   /* add_continue */",cmd_data->blockid);
  tmp_ccnt--;
  printc ("\n}\n");

printc("END_BLOCK_%d:    ;   /* add_continue */",cmd_data->blockid);
  printc("A4GL_finish_screenio(&_sio_%d,_sio_kw_%d);",sio_id,sio_id);

  printc ("}\n");

// Construct has one of these - do we need one here too ? 
  /* print_reset_state_after_call(); */



  print_copy_status_not_sql (0);
  return 1;

}


/******************************************************************************/
int
print_input_array_cmd (struct_input_array_cmd * cmd_data)
{
int sio_id=-1;
int nevents=-1;
//int ccc=-1;
int cnt=-1;
int inp_flags=0;
 struct variable *v;

  //struct expr_str *srec;
  //struct expr_str *arrayname;
  //struct attrib *attrib;
  //struct on_events *events;
  //e_boolean without_defaults;
  //int helpno;
  //int sio;
  //int blk;
  //str slice;
  //int slice_start;
  //int slice_end;

  sio_id=cmd_data->sio;
  nevents=0;
  if (cmd_data->events) {
                nevents=cmd_data->events->event.event_len;
   }

  print_cmd_start ();

  A4GL_assertion(cmd_data->arrayname->expr_type!=ET_EXPR_VARIABLE_USAGE,"Expecting a variable usage");





  printc ("{");
  tmp_ccnt++;
  printc("int _fld_dr= -100;int _exec_block= 0;\nchar *_fldname;char *_curr_win; \nint _forminit=1;int _tmp_int=0;");
  printc ("char _sio_%d[%d];char _inp_io_type='A';char *_sio_kw_%d=\"s_inp_arr\";\n",sio_id, sizeof (struct s_inp_arr) + 10,sio_id);
  print_event_list(cmd_data->events);



/* We dont get passed in a real binding - just the variable
 * so we need to generate our own binding....
 *
 * The array can be one of two types
 * 1) A simple array ( eg ARRAY OF char(20))
 * 2) A record array ( eg ARRAY OF RECORD ... END RECORD )
 *
 * So - lets first have a look and see which type we've got
 * */
  v=local_find_variable_from_usage(cmd_data->arrayname->expr_str_u.expr_variable_usage);
  if (v->var_data.variable_type==VARIABLE_TYPE_RECORD) {
	int a;
	struct variable *v2;
	struct variable_usage *vu_top;
	struct variable_usage *vu_next;
	struct expr_str *vu_as_expr;

	/* Its an array of RECORD */
	cnt=v->var_data.variable_data_u.v_record.variables.variables_len;
	printc("static struct BINDING obind[%d]={",cnt);

	/* First - we need to print the 'obind' - which has the types */
	for (a=0;a<v->var_data.variable_data_u.v_record.variables.variables_len;a++) {
		int dtype;
		v2=v->var_data.variable_data_u.v_record.variables.variables_val[a];
		if (v2->var_data.variable_type!=VARIABLE_TYPE_SIMPLE) {
			a4gl_yyerror("Expecting only simple types in the array");
			return 0;
		}
		dtype=encode_variable_datatype(v2->var_data.variable_data_u.v_simple.datatype, v2->var_data.variable_data_u.v_simple.dimensions[0], v2->var_data.variable_data_u.v_simple.dimensions[1]);

	 	printc("{NULL,%d,%d,0,0,0}%s", dtype&DTYPE_MASK,DECODE_SIZE(dtype), (a==v->var_data.variable_data_u.v_record.variables.variables_len)?"":",");
	}
	printc("};");

	/* Now - we need to print the array itself..
 		we could assume the array is a top level array and just display it directly
		but what I'm trying to do here is to generate a 'variable_usage' for each
		line so we can print that instead..
		in theory - it means we can display array an array which is inside another record/array...
	*/
	for (a=0;a<v->var_data.variable_data_u.v_record.variables.variables_len;a++) {
			v2=v->var_data.variable_data_u.v_record.variables.variables_val[a];
	                vu_top=clone_variable_usage(cmd_data->arrayname->expr_str_u.expr_variable_usage);
                        vu_next=vu_top;
                        while (vu_next->next) {
                                vu_next=vu_next->next;
                        }
		        vu_next->subscripts.subscripts_len=1;
                        vu_next->subscripts.subscripts_val=malloc(sizeof(struct expr_str *));
			vu_next->subscripts.subscripts_val[0]=A4GL_new_literal_long_long(1);
                        vu_next->next=malloc(sizeof(struct variable_usage));
                        vu_next->next->variable_name=v->var_data.variable_data_u.v_record.variables.variables_val[a]->names.names.names_val[0].name;
                        vu_next->next->subscripts.subscripts_len=0;
                        vu_next->next->subscripts.subscripts_val=0;
                        vu_next->next->substrings_start=0;
                        vu_next->next->substrings_end=0;
                        vu_next->next->next=0;
                        vu_next->next->datatype=v2->var_data.variable_data_u.v_simple.datatype;
                        vu_next->next->scope=cmd_data->arrayname->expr_str_u.expr_variable_usage->scope;
                        vu_next->next->variable_id=a;
			vu_as_expr=A4GL_new_expr_push_variable(vu_top);
			set_nonewlines();
			printc("obind[%d].ptr= &",a);
			print_variable_usage(vu_as_expr);
			printc(";");
			clr_nonewlines();

	}
  } else {
	// Its a simple array of a single datatype
	// just a little easier than the record !
  	cnt = 1;
	printc("static struct BINDING obind[1]={ {NULL,%d,%d,0,0,0} };",v->var_data.variable_data_u.v_simple.datatype &DTYPE_MASK,DECODE_SIZE(v->var_data.variable_data_u.v_simple.datatype));
	set_nonewlines();
	printc("obind[0].ptr= &");
	print_variable_usage(cmd_data->arrayname);
	printc("[0];");
	clr_nonewlines();
  }


  // cnt = print_arr_bind_g (bind);


  printc ("while (_fld_dr!=0) {\n");
  tmp_ccnt++;
  printc ("if (_exec_block==0) {\n");
	tmp_ccnt++;
  printc ("_curr_win=A4GL_get_currwin_name();\n");
  if (cmd_data->without_defaults==EB_TRUE) {
        printc ("SET(\"s_inp_arr\",_sio_%d,\"no_arr\",A4GL_get_count());\n",sio_id);
  } else {
        printc ("SET(\"s_inp_arr\",_sio_%d,\"no_arr\",0);\n",sio_id);
  }
  printc ("SET(\"s_inp_arr\",_sio_%d,\"binding\",obind);\n",sio_id);
  printc ("SET(\"s_inp_arr\",_sio_%d,\"nbind\",%d);\n",sio_id, cnt);
  printc ("SET(\"s_inp_arr\",_sio_%d,\"srec\",0);\n",sio_id);
  printc ("SET(\"s_inp_arr\",_sio_%d,\"scr_dim\",0);\n",sio_id);
  printc ("SET(\"s_inp_arr\",_sio_%d,\"help_no\",%d);\n",sio_id, cmd_data->helpno);
set_nonewlines();
  printc ("SET(\"s_inp_arr\",_sio_%d,\"arr_elemsize\",sizeof(",sio_id); print_variable_usage(cmd_data->arrayname); printc("[0]));\n");
clr_nonewlines();

  if ( cmd_data->attributes  && (cmd_data->attributes->no_new_lines==EB_TRUE)) {
	inp_flags+=1;
  }



set_nonewlines();
  printc ("SET(\"s_inp_arr\",_sio_%d,\"arr_size\",sizeof(", sio_id);
	 print_variable_usage(cmd_data->arrayname);
	printc(")/sizeof(");
	 print_variable_usage(cmd_data->arrayname);
	printc("[0]));");
clr_nonewlines();
  printc ("SET(\"s_inp_arr\",_sio_%d,\"currform\",A4GL_get_curr_form(1));\n",sio_id);
  printc ("SET(\"s_inp_arr\",_sio_%d,\"inp_flags\",%d);\n",sio_id, inp_flags);
  printc ("if (GET_AS_INT(\"s_inp_arr\",_sio_%d,\"currform\")==0) break;\n",sio_id);
  printc ("SET(\"s_inp_arr\",_sio_%d,\"currentfield\",0);\n",sio_id);

  printc ("SET(\"s_inp_arr\",_sio_%d,\"start_slice\",%d);\n",sio_id,cmd_data->slice_start);
  printc ("SET(\"s_inp_arr\",_sio_%d,\"end_slice\",%d);\n",sio_id,cmd_data->slice_end);

  printc ("SET(\"s_inp_arr\",_sio_%d,\"mode\",%d);\n",sio_id, MODE_INPUT+ (cmd_data->without_defaults==EB_TRUE));


   if (cmd_data->attributes && cmd_data->attributes->currentrowdisplay && strlen(cmd_data->attributes->currentrowdisplay))
    printc ("SET(\"s_inp_arr\",_sio_%d,\"curr_display\",%s);\n",sio_id, cmd_data->attributes->currentrowdisplay);
  else
    printc ("SET(\"s_inp_arr\",_sio_%d,\"curr_display\",0);\n",sio_id);




  if (cmd_data->attributes && cmd_data->attributes->count)
    {
	print_expr(cmd_data->attributes->count);
	printc("_tmp_int=A4GL_pop_long();");
        printc ("SET(\"s_inp_arr\",_sio_%d,\"count\",_tmp_int);\n",sio_id);
	print_expr(cmd_data->attributes->count);
        printc ("aclfgl_set_count(1);\n");
    }
  else {
    printc ("SET(\"s_inp_arr\",_sio_%d,\"count\",-1);\n",sio_id);
  }

  if (cmd_data->attributes && cmd_data->attributes->maxcount) {
            	print_expr(cmd_data->attributes->maxcount);
		printc("_tmp_int=A4GL_pop_long();");
    		printc ("SET(\"s_inp_arr\",_sio_%d,\"maxcount\",_tmp_int);\n",sio_id);
	}
  else {
    printc ("SET(\"s_inp_arr\",_sio_%d,\"maxcount\",-1);\n",sio_id);
	}

  if (cmd_data->attributes) {
  	printc ("SET(\"s_inp_arr\",_sio_%d,\"allow_insert\",%d);\n",sio_id, cmd_data->attributes->allow_insert!=EB_FALSE);
  } else {
  	printc ("SET(\"s_inp_arr\",_sio_%d,\"allow_insert\",%d);\n",sio_id, 1);
  }

  if (cmd_data->attributes) {
  	printc ("SET(\"s_inp_arr\",_sio_%d,\"allow_delete\",%d);\n",sio_id, cmd_data->attributes->allow_delete!=EB_FALSE);
  } else {
  	printc ("SET(\"s_inp_arr\",_sio_%d,\"allow_delete\",%d);\n",sio_id, 1);
  }

set_nonewlines();
  printc ("SET(\"s_inp_arr\",_sio_%d,\"nfields\",A4GL_gen_field_chars((void ***)GETPTR(\"s_inp_arr\",_sio_%d,\"field_list\"),(void *)GET(\"s_inp_arr\",_sio_%d,\"currform\"),A4GL_add_dot_star(",
		sio_id,
		sio_id,
		sio_id
 );
  print_ident(cmd_data->srec);
  printc("),NULL,0));\n");
clr_nonewlines();


  printc ("_fld_dr= -1;");
  printc("_exec_block=-1;");
  printc("ERR_CHK_ERROR { break;} ");
  printc("continue;\n");
  print_reset_state_after_call(0);
  tmp_ccnt--;
  printc ("} /* end of initialization */\n");


print_event_actions ("_exec_block", cmd_data->events);


  printc("if (_exec_block==%d) { break; } ",nevents+1);
  printc("A4GL_ensure_current_window_is(_curr_win);");



set_nonewlines();
  printc ("_exec_block= A4GL_inp_arr_v2(&_sio_%d,%d,", sio_id, cmd_data->without_defaults==TRUE);
  print_ident(cmd_data->srec);
  printc(",%d,_forminit,_sio_evt);_forminit=0;\n",attributes_as_int(cmd_data->attributes));
clr_nonewlines();



  printc("if (_exec_block>0) _fld_dr=_sio_evt[_exec_block-1].event_type; else _fld_dr= -1;");

printc("CONTINUE_BLOCK_%d:    ;   /* add_continue */",cmd_data->blockid);
  tmp_ccnt--;
  printc ("\n}\n");

printc("END_BLOCK_%d:    ;   /* add_continue */",cmd_data->blockid);
  printc("A4GL_finish_screenio(&_sio_%d,_sio_kw_%d);",sio_id,sio_id);


  tmp_ccnt--;
  printc("}");
  
  print_copy_status_not_sql (0);
  return 1;

}


/******************************************************************************/
int
print_prompt_cmd (struct_prompt_cmd * cmd_data)
{
  int timeout = 0;
  //struct expr_str_list*prompt_str;
  //struct attrib *prompt_str_attrib;
  //struct attrib *prompt_fld_attrib;
  //enum e_boolean for_char;
  //struct expr_str* promptvar;
  //int helpno;
  //struct on_events* events;
  //int sio;
  //int blockid;
  //
  //                              prattrib   4char   hlp     fldattr                   var
  /* print_prompt_1($<ptr_list>2, $<str>3, $<str>5,  $<str>7,  $<str>8,      0,last_style,$<str>6) ; */
  //t_expr_str_list *expr,       char *a1, char *a2, char *a3, char *a4, int timeout,char *Style,char *promptvar)

  print_cmd_start ();
  printc ("{");
  tmp_ccnt++;
  printc("char _sio_%d[%d];int _fld_dr= -9999;int _exec_block= 0;char *_sio_kw_%d=\"s_prompt\";int _acl_prompt_timeout=%d;\n", cmd_data->sio, sizeof (struct s_prompt), cmd_data->sio, timeout);
  print_event_list (cmd_data->events);
  A4GL_print_expr_list_concat (cmd_data->prompt_str);
  printc ("if (A4GL_start_prompt(&_sio_%d,%d,%d,%d,%d)) {\n", cmd_data->sio, attributes_as_int (cmd_data->prompt_str_attrib), cmd_data->for_char==EB_TRUE, cmd_data->helpno, attributes_as_int (cmd_data->prompt_fld_attrib));
  tmp_ccnt++;
  printc ("while (1) {");
  tmp_ccnt++;
  print_event_actions ("_exec_block", cmd_data->events);
  printc("CONTINUE_BLOCK_%d: ;", cmd_data->blockid);
  printc ("if (GET_AS_INT(\"s_prompt\",_sio_%d,\"mode\")==2) break;", cmd_data->sio);
  printc ("_exec_block=A4GL_prompt_loop_v2(&_sio_%d,_acl_prompt_timeout,_sio_evt);\n", cmd_data->sio);
  tmp_ccnt--;
  printc ("}");
  print_pop_usage (cmd_data->promptvar);
  tmp_ccnt--;
  printc ("}\n");
  tmp_ccnt--;
  printc ("}\n");
  printc("END_BLOCK_%d: ;", cmd_data->blockid);

  print_copy_status_not_sql (0);
  return 1;
}



/******************************************************************************/
int
print_menu_cmd (struct_menu_cmd * cmd_data)
{
  //struct expr_str *menu_title;
  //struct attrib *menu_attrib;
  //struct on_events* events;
  //int sio;
  //int blockid;
  //        struct expr_str *menu_attrib_comment;
  //                struct expr_str *menu_attrib_style;
  //                        struct expr_str *menu_attrib_image;
  //
  //
  int menu_no;


  print_cmd_start ();
  menu_no = cmd_data->blockid;
  printc ("{\nvoid *m_%d=0;\n\nint cmd_no_%d= -1; /* n=%d */\n", menu_no, menu_no, menu_no);
  tmp_ccnt++;
  printc ("MENU_START_%d: ;", menu_no);
  printc ("while (cmd_no_%d!= -3) {\n", menu_no);
  tmp_ccnt++;

  if (cmd_data->events)		// Should always be true though !
    {
      int a;
      int opt_cnt = 0;
      for (a = 0; a < cmd_data->events->event.event_len; a++)
	{
	  struct on_event *evt;
	  evt = cmd_data->events->event.event_val[a];

	  if (evt->evt_data.event_type == EVENT_BEFORE_MENU)
	    {
	      dump_comments (evt->lineno);
	      printc ("if (cmd_no_%d==-2) {", menu_no);
	      tmp_ccnt++;
	      printc ("A4GL_disp_h_menu(m_%d);", menu_no);
	      dump_commands (evt->on_event_commands);
	      printc ("/* FORCE AROUND MENU LOOP AGAIN */ cmd_no_%d= -4;goto MENU_START_%d;  /* %d */", menu_no, menu_no, menu_no);
	      tmp_ccnt--;
	      printc ("}");
	    }
	  else
	    {
	      dump_comments (evt->lineno);
	      printc (" if (cmd_no_%d==%d) { \n", menu_no, opt_cnt++);
	      tmp_ccnt++;
	      dump_commands (evt->on_event_commands);
	      printc ("/* FORCE AROUND MENU LOOP AGAIN */ cmd_no_%d= -4;goto MENU_START_%d;  /* %d */", menu_no, menu_no, menu_no);
	      tmp_ccnt--;
	      printc ("}");
	    }
	}


    }

  printcomment (" /*end switch */\n");
  printc ("if (cmd_no_%d== -1) {\n", menu_no);
  tmp_ccnt++;
  printc ("char *_mntitle;");
  printc ("char *_mnoptiontitle;");
  if (cmd_data->menu_title)
    {
      printc ("/* PRINT EXPR */");
      print_expr (cmd_data->menu_title);
      printc ("/* END PRINT EXPR */");
    }
  else
    {
      printc ("/* PUSH NOTHING */");

      printc ("A4GL_push_char(\"\");");
    }
  printc ("_mntitle=A4GL_char_pop(); /* ... */");

  if (cmd_data->menu_attrib_comment || cmd_data->menu_attrib_style || cmd_data->menu_attrib_image)
    {
      printc ("{");
      printc ("char *_comment;");
      printc ("char *_style;");
      printc ("char *_image;");
      if (cmd_data->menu_attrib_comment)
	{
	  print_expr (cmd_data->menu_attrib_comment);
	}
      else
	{
	  printc ("A4GL_push_char(\"\");");
	}
      printc ("_comment=A4GL_char_pop();");

      if (cmd_data->menu_attrib_style)
	{
	  print_expr (cmd_data->menu_attrib_style);
	}
      else
	{
	  printc ("A4GL_push_char(\"\");");
	}
      printc ("_style=A4GL_char_pop();");

      if (cmd_data->menu_attrib_image)
	{
	  print_expr (cmd_data->menu_attrib_image);
	}
      else
	{
	  printc ("A4GL_push_char(\"\");");
	}
      printc ("_image=A4GL_char_pop();");
      printc ("m_%d=(void *)A4GL_new_menu_create_with_attr(_mntitle,1,1,%d,0,_comment, _style,_image);", menu_no, 2);
      printc ("free(_comment);");
      printc ("free(_style);");
      printc ("free(_image);");
      printc ("free(_mn_title);");
      printc ("}");
    }
  else
    {
      printc ("m_%d=(void *)A4GL_new_menu_create_with_attr(_mntitle,1,1,%d,0,\"\",\"\",\"\");\n", menu_no, 2);
      printc ("free(_mntitle);");
    }

  if (cmd_data->events)
    {
      int a;
      for (a = 0; a < cmd_data->events->event.event_len; a++)
	{
	  struct on_event *evt;
	  evt = cmd_data->events->event.event_val[a];

	  switch (evt->evt_data.event_type)
	    {
	    case EVENT_ON_ACTION:
	      printc ("A4GL_add_menu_action(m_%d, %s,%d);\n", menu_no, evt->evt_data.event_data_u.on_action, a);
	      break;

	    case EVENT_MENU_COMMAND:
	      set_nonewlines ();
	      printc ("A4GL_add_menu_option(m_%d, ", menu_no);

	      if (evt->evt_data.event_data_u.mnoption->shortname)
		{
		  printc ("%s", local_expr_as_string (evt->evt_data.event_data_u.mnoption->shortname));
		}
	      else
		{
		  printc ("\"\"");
		}
	      printc (",");

	      if (evt->evt_data.event_data_u.mnoption->keys)
		{
		  if (evt->evt_data.event_data_u.mnoption->keys->str_list_entry.str_list_entry_len)
		    {
		      int b;
		      printc ("\"");
		      for (b = 0; b < evt->evt_data.event_data_u.mnoption->keys->str_list_entry.str_list_entry_len; b++)
			{
			  if (b)
			    printc ("||");
			  printc ("%s", evt->evt_data.event_data_u.mnoption->keys->str_list_entry.str_list_entry_val[b]);
			}
		      printc ("\"");
		    }
		  else
		    {
		      printc ("\"EMPTY\"");
		    }
		}
	      else
		{
		  printc ("\"EMPTY\"");

		}
	      printc (",");
	      if (evt->evt_data.event_data_u.mnoption->longname)
		{
		  printc ("%s", local_expr_as_string (evt->evt_data.event_data_u.mnoption->longname));
		}
	      else
		{
		  printc ("\"\"");
		}
	      printc (",%d,0);", evt->evt_data.event_data_u.mnoption->helpno);
	      clr_nonewlines ();
	      break;

	    case EVENT_ON_IDLE:
	      printh ("static long a4gl_mn_idle%d=0;\n", idle_cnt);
	      printc ("A4GL_add_menu_timeout(m_%d, 'D',%d,%d,&a4gl_mn_idle%d);a4gl_mn_idle%d=0;\n", menu_no,
		      evt->evt_data.event_data_u.idle_n, a, idle_cnt, idle_cnt);
	      idle_cnt++;
	      break;

	    case EVENT_ON_INTERVAL:
	      printh ("static long a4gl_mn_idle%d=0;\n", idle_cnt);
	      printc ("A4GL_add_menu_timeout(m_%d, 'V',%d,%d,&a4gl_mn_idle%d);a4gl_mn_idle%d=0;\n", menu_no,
		      evt->evt_data.event_data_u.interval_n, a, idle_cnt, idle_cnt);
	      idle_cnt++;
	      break;

	    case EVENT_BEFORE_MENU:
	      // this one is handled implicitly - 
	      // the loop variable will be set to -2 during startup
	      break;

	    default:
	      A4GL_assertion (1, "Unexpected event type in a menu");
	    }
	}
    }


  printc ("A4GL_finish_create_menu(m_%d); ", menu_no);
  //printc("A4GL_disp_h_menu(m_%d);  ",n);
  printc ("cmd_no_%d= -2;", menu_no);
  printc ("continue;");
  tmp_ccnt--;


/*


			case EVENT_BEFORE_MENU:
				printc("if (cmd_no_%d==-2) {",n);
				printc("}");
				break;
*/

  printc ("}\n");
	printc("CONTINUE_BLOCK_%d:    ;", cmd_data->blockid);
  printc ("cmd_no_%d=A4GL_menu_loop_v2(m_%d,0);\n", menu_no, menu_no);
  tmp_ccnt--;
  printc ("}\n");
  printc ("A4GL_free_menu(m_%d);\n", menu_no);

  printcomment ("/* end cwhile */\n");
  printcomment ("/* end menu */\n \n");
  tmp_ccnt--;

  printc ("}");
	printc("END_BLOCK_%d:    ;", cmd_data->blockid);

//print_end_menu_1(menu_blk[menu_cnt], menu_attrib_comment,menu_attrib_style, menu_attrib_image);
//print_end_menu_2(menu_blk[menu_cnt]);

  print_copy_status_not_sql (0);
  return 1;


}



/******************************************************************************/
int print_output_cmd(struct_output_cmd *cmd_data) {
int n;
  print_cmd_start ();
  if (cmd_data->expressions) {
  	n=cmd_data->expressions->list.list_len;
  	real_print_expr_list(cmd_data->expressions );
  } else {
	n=0;
  }
  add_function_to_header (cmd_data->repname,cmd_data->namespace, 2,0);
  printc ("%s%s(%d,REPORT_SENDDATA);\n", cmd_data->namespace, cmd_data->repname, n);
  print_copy_status_with_sql (0); /* Can have an ORDER BY which causes a series of SQL statements */
  return 1;
}

/******************************************************************************/
int print_finish_cmd(struct_finish_cmd *cmd_data) {
  print_cmd_start ();
  add_function_to_header (cmd_data->repname,cmd_data->namespace, 2,0);
  printc ("%s%s(0,REPORT_FINISH);\n", cmd_data->namespace, cmd_data->repname);
  print_copy_status_with_sql (0); /* Can have an ORDER BY which causes a series of SQL statements */
  return 1;
}

/******************************************************************************/
int print_term_rep_cmd(struct_term_rep_cmd *cmd_data) {
  print_cmd_start ();
  add_function_to_header (cmd_data->repname,cmd_data->namespace, 2,0);
  printc ("%s%s(0,REPORT_TERMINATE);\n", cmd_data->namespace, cmd_data->repname);
  print_copy_status_not_sql (0);
  return 1;
}

/******************************************************************************/
int print_need_cmd(struct_need_cmd *cmd_data) {
  print_cmd_start ();
  print_expr(cmd_data->expr);
  printc ("A4GL_%sneed_lines(&_rep);\n", ispdf ());
  print_copy_status_not_sql (0);
  return 1;
}

/******************************************************************************/
int print_skip_cmd(struct_skip_cmd *cmd_data) {
  print_cmd_start ();
  printc ("A4GL_push_int(%d);", cmd_data->lines );
  printc ("A4GL_%saclfgli_skip_lines(&_rep);\n", ispdf ());
  print_copy_status_not_sql (0);
  return 1;
}


/******************************************************************************/
int print_skip_by_cmd(struct_skip_by_cmd *cmd_data) {
  print_cmd_start ();
  printc ("A4GL_pdf_skip_by(&_rep,%f);\n", cmd_data->lines);
  print_copy_status_not_sql (0);
  return 1;
}

/******************************************************************************/
int print_skip_to_cmd(struct_skip_to_cmd *cmd_data) {
  print_cmd_start ();
  printc ("A4GL_pdf_skip_to(&_rep,%f);\n", cmd_data->lines);
  print_copy_status_not_sql (0);
  return 1;
}


/******************************************************************************/
int print_print_cmd(struct_print_cmd *cmd_data) {
int semi_i;
char *wrap="0";
int a;

  print_cmd_start ();

  if (cmd_data->semi==EB_TRUE) semi_i=1; else semi_i=0;

  if (cmd_data->print_expr) {
  for (a=0;a<cmd_data->print_expr->list.list_len;a++) {
		struct expr_str *e;
		e=cmd_data->print_expr->list.list_val[a];
		if (e->expr_type == ET_EXPR_WORDWRAP) {
			// We're not printing the WORDWRAP - we need to decode the
			// wordwrap and change our print accordingly...
			print_expr(e->expr_str_u.expr_wordwrap->expr);
			
    			printc ("A4GL_%srep_print(&_rep,1,1,%s,%d);\n", ispdf (),local_expr_as_string(e->expr_str_u.expr_wordwrap->wrap_at),rep_print_entry++);
		} else {
			print_expr(e);
    			printc ("A4GL_%srep_print(&_rep,1,1,%s,%d);\n", ispdf (), wrap,rep_print_entry++);
		}
  }
  }
  printc ("A4GL_%srep_print(&_rep,0,%d,0,-1);\n", ispdf (), cmd_data->semi==EB_TRUE);


  print_copy_status_not_sql (0);
  return 1;
}


/******************************************************************************/
int print_print_file_cmd(struct_print_file_cmd *cmd_data) {
  print_cmd_start ();
  printc("{");
  printc("char *_r;");
  print_expr(cmd_data->filename);
  printc("_r=A4GL_char_pop();");
  printc ("%sA4GL_rep_file_print(&_rep,_r,%d);\n", ispdf (), cmd_data->semi==EB_TRUE);
  printc("free(_r);");
  printc("}");
  print_copy_status_not_sql (0);
  return 1;
}


/******************************************************************************/
int print_print_img_cmd(struct_print_img_cmd *cmd_data) {
  print_cmd_start ();
  print_expr(cmd_data->scale_x);
  print_expr(cmd_data->scale_y);
	set_nonewlines();
  printc ("A4GL_pdf_blob_print(&_rep,&");
  print_variable_usage(cmd_data->var); 
  printc(",\"%s\",%d);\n",  cmd_data->img_type, cmd_data->semi==EB_TRUE);
	clr_nonewlines();
  print_copy_status_not_sql (0);
  return 1;
}


/******************************************************************************/
int print_pause_cmd(struct_pause_cmd *cmd_data) {
  print_cmd_start ();
  printc("{");
  printc("char *_r;");
  print_expr(cmd_data->pause_msg);
  printc("_r=A4GL_char_pop();");
  printc ("A4GL_pause(_r);\n");
  printc("free(_r);");
  printc("}");
  print_copy_status_not_sql (0);
  return 1;
}


/******************************************************************************/
/*                                SQL COMMANDS                                */
/* are in compile_c_sql.c  AND compile_c_esqlc.c - depending on LEXTYPE       */
/*                         being generated                                    */
/******************************************************************************/





/*----------------------------------------------------------------------------*/
/*                             ADVANCED COMMANDS                              */
/*----------------------------------------------------------------------------*/


/******************************************************************************/
int
print_alloc_arr_cmd (struct_alloc_arr_cmd * cmd_data)
{
struct variable_usage *u_bottom;
struct variable_usage *u;
struct expr_str **subs;
int nsubs;
char *ptr;
//char *dim[5];
  //struct expr_str *variable;
  print_cmd_start ();

   u=cmd_data->variable->expr_str_u.expr_variable_usage; 
   u_bottom=u;
   while (u_bottom->next) {
	    u_bottom = u_bottom->next;
   }
   nsubs=u_bottom->subscripts.subscripts_len;
   subs=u_bottom->subscripts.subscripts_val;

   u_bottom->subscripts.subscripts_len=0;
   u_bottom->subscripts.subscripts_val=0;
   ptr=generation_get_variable_usage_as_string(u);
   
   printc("{");
   printc("int _d0=1;");
   printc("int _d1=1;");
   printc("int _d2=1;");
   printc("int _d3=1;");
   printc("int _d4=1;");
   if(nsubs>=1)  {print_expr(subs[0]);printc("_d0=A4GL_pop_long();");}
   if(nsubs>=2)  {print_expr(subs[1]);printc("_d1=A4GL_pop_long();");}
   if(nsubs>=3)  {print_expr(subs[2]);printc("_d2=A4GL_pop_long();");}
   if(nsubs>=4)  {print_expr(subs[3]);printc("_d3=A4GL_pop_long();");}
   if(nsubs>=5)  {print_expr(subs[4]);printc("_d4=A4GL_pop_long();");}

   printc ("%s=A4GL_alloc_dynarr(&%s,%s,_d0,_d1,_d2,_d3,_d4,(_d0*_d1*_d2*_d3*_d4) * sizeof(%s[0]),0);", ptr, ptr, ptr, ptr);
   printc("}");



  print_copy_status_not_sql (0);
  return 1;
}


/******************************************************************************/
int
print_dealloc_arr_cmd (struct_dealloc_arr_cmd * cmd_data)
{

struct variable_usage *u_bottom;
struct variable_usage *u;
//struct expr_str **subs;
//int nsubs;
char *ptr;
//char *dim[5];
  //struct expr_str *variable;
  print_cmd_start ();

   u=cmd_data->variable->expr_str_u.expr_variable_usage;
   u_bottom=u;
   while (u_bottom->next) {
            u_bottom = u_bottom->next;
   }
   ptr=generation_get_variable_usage_as_string(u);

 printc ("A4GL_dynarr_free(&%s,%s);", ptr,ptr);




  print_copy_status_not_sql (0);
  return 1;
}


/******************************************************************************/
int
print_resize_arr_cmd (struct_resize_arr_cmd * cmd_data)
{
struct variable_usage *u_bottom;
struct variable_usage *u;
struct expr_str **subs;
int nsubs;
char *ptr;
//char *dim[5];
  //struct expr_str *variable;
  print_cmd_start ();

   u=cmd_data->variable->expr_str_u.expr_variable_usage; 
   u_bottom=u;
   while (u_bottom->next) {
	    u_bottom = u_bottom->next;
   }
   nsubs=u_bottom->subscripts.subscripts_len;
   subs=u_bottom->subscripts.subscripts_val;

   u_bottom->subscripts.subscripts_len=0;
   u_bottom->subscripts.subscripts_val=0;
   ptr=generation_get_variable_usage_as_string(u);
   
   printc("{");
   printc("int _d0=1;");
   printc("int _d1=1;");
   printc("int _d2=1;");
   printc("int _d3=1;");
   printc("int _d4=1;");
   if(nsubs>=1)  {print_expr(subs[0]);printc("_d0=A4GL_pop_long();");}
   if(nsubs>=2)  {print_expr(subs[1]);printc("_d1=A4GL_pop_long();");}
   if(nsubs>=3)  {print_expr(subs[2]);printc("_d2=A4GL_pop_long();");}
   if(nsubs>=4)  {print_expr(subs[3]);printc("_d3=A4GL_pop_long();");}
   if(nsubs>=5)  {print_expr(subs[4]);printc("_d4=A4GL_pop_long();");}

   printc ("%s=A4GL_alloc_dynarr(&%s,%s,_d0,_d1,_d2,_d3,_d4,(_d0*_d1*_d2*_d3*_d4) * sizeof(%s[0]),1);", ptr, ptr, ptr, ptr);
   printc("}");

  print_copy_status_not_sql (0);
  return 1;
}


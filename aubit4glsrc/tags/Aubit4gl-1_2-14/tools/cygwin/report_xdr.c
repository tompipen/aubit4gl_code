/*
 * Please do not A4GL_edit this file.
 * It was generated using rpcgen.
 */

#include "report.h"

bool_t
xdr_cmdtypes (XDR * xdrs, cmdtypes * objp)
{
  register int32_t *buf;

  if (!xdr_enum (xdrs, (enum_t *) objp))
    return FALSE;
  return TRUE;
}

bool_t
xdr_varcats (XDR * xdrs, varcats * objp)
{
  register int32_t *buf;

  if (!xdr_enum (xdrs, (enum_t *) objp))
    return FALSE;
  return TRUE;
}

bool_t
xdr_aggtypes (XDR * xdrs, aggtypes * objp)
{
  register int32_t *buf;

  if (!xdr_enum (xdrs, (enum_t *) objp))
    return FALSE;
  return TRUE;
}

bool_t
xdr_expr_operands (XDR * xdrs, expr_operands * objp)
{
  register int32_t *buf;

  if (!xdr_enum (xdrs, (enum_t *) objp))
    return FALSE;
  return TRUE;
}

bool_t
xdr_exprtype (XDR * xdrs, exprtype * objp)
{
  register int32_t *buf;

  if (!xdr_enum (xdrs, (enum_t *) objp))
    return FALSE;
  return TRUE;
}

bool_t
xdr_expr (XDR * xdrs, expr * objp)
{
  register int32_t *buf;

  if (!xdr_exprtype (xdrs, &objp->type))
    return FALSE;
  switch (objp->type)
    {
    case EXPRTYPE_NULL:
      if (!xdr_int (xdrs, &objp->expr_u.null))
	return FALSE;
      break;
    case EXPRTYPE_INT:
      if (!xdr_int (xdrs, &objp->expr_u.i))
	return FALSE;
      break;
    case EXPRTYPE_DOUBLE:
      if (!xdr_double (xdrs, &objp->expr_u.d))
	return FALSE;
      break;
    case EXPRTYPE_STRING:
      if (!xdr_string (xdrs, &objp->expr_u.s, ~0))
	return FALSE;
      break;
    case EXPRTYPE_VARIABLE:
      if (!xdr_int (xdrs, &objp->expr_u.varid))
	return FALSE;
      break;
    case EXPRTYPE_BUILTIN:
      if (!xdr_string (xdrs, &objp->expr_u.name, ~0))
	return FALSE;
      break;
    case EXPRTYPE_COMPLEX:
      if (!xdr_pointer
	  (xdrs, (char **) &objp->expr_u.expr, sizeof (struct complex_expr),
	   (xdrproc_t) xdr_complex_expr))
	return FALSE;
      break;
    case EXPRTYPE_COMPARE:
      if (!xdr_pointer
	  (xdrs, (char **) &objp->expr_u.cexpr, sizeof (struct compare_expr),
	   (xdrproc_t) xdr_compare_expr))
	return FALSE;
      break;
    case EXPRTYPE_SIMPLE:
      if (!xdr_pointer
	  (xdrs, (char **) &objp->expr_u.sexpr, sizeof (struct simple_expr),
	   (xdrproc_t) xdr_simple_expr))
	return FALSE;
      break;
    case EXPRTYPE_LIST:
      if (!xdr_pointer
	  (xdrs, (char **) &objp->expr_u.lexpr, sizeof (struct expr_list),
	   (xdrproc_t) xdr_expr_list))
	return FALSE;
      break;
    case EXPRTYPE_FCALL:
      if (!xdr_pointer
	  (xdrs, (char **) &objp->expr_u.fcall, sizeof (struct expr_call),
	   (xdrproc_t) xdr_expr_call))
	return FALSE;
      break;
    case EXPRTYPE_AGG:
      if (!xdr_int (xdrs, &objp->expr_u.aggid))
	return FALSE;
      break;
    default:
      return FALSE;
    }
  return TRUE;
}

bool_t
xdr_expr_list (XDR * xdrs, expr_list * objp)
{
  register int32_t *buf;

  if (!xdr_array
      (xdrs, (char **) &objp->elem.elem_val, (u_int *) & objp->elem.elem_len,
       ~0, sizeof (expr), (xdrproc_t) xdr_expr))
    return FALSE;
  return TRUE;
}

bool_t
xdr_expr_call (XDR * xdrs, expr_call * objp)
{
  register int32_t *buf;

  if (!xdr_string (xdrs, &objp->fname, ~0))
    return FALSE;
  if (!xdr_pointer
      (xdrs, (char **) &objp->lexpr, sizeof (expr_list),
       (xdrproc_t) xdr_expr_list))
    return FALSE;
  return TRUE;
}

bool_t
xdr_complex_expr (XDR * xdrs, complex_expr * objp)
{
  register int32_t *buf;

  if (!xdr_expr (xdrs, &objp->expr1))
    return FALSE;
  if (!xdr_expr_operands (xdrs, &objp->operand))
    return FALSE;
  if (!xdr_expr (xdrs, &objp->expr2))
    return FALSE;
  return TRUE;
}

bool_t
xdr_compare_expr (XDR * xdrs, compare_expr * objp)
{
  register int32_t *buf;

  if (!xdr_string (xdrs, &objp->method, ~0))
    return FALSE;
  if (!xdr_expr (xdrs, &objp->expr1))
    return FALSE;
  if (!xdr_expr (xdrs, &objp->expr2))
    return FALSE;
  return TRUE;
}

bool_t
xdr_simple_expr (XDR * xdrs, simple_expr * objp)
{
  register int32_t *buf;

  if (!xdr_expr (xdrs, &objp->expr))
    return FALSE;
  if (!xdr_expr_operands (xdrs, &objp->operand))
    return FALSE;
  return TRUE;
}

bool_t
xdr_variable (XDR * xdrs, variable * objp)
{
  register int32_t *buf;


  if (xdrs->x_op == XDR_ENCODE)
    {
      if (!xdr_string (xdrs, &objp->name, ~0))
	return FALSE;
      if (!xdr_string (xdrs, &objp->datatype_string, ~0))
	return FALSE;
      buf = XDR_INLINE (xdrs, 5 * BYTES_PER_XDR_UNIT);
      if (buf == NULL)
	{
	  if (!xdr_int (xdrs, &objp->category))
	    return FALSE;
	  if (!xdr_int (xdrs, &objp->param_no))
	    return FALSE;
	  if (!xdr_int (xdrs, &objp->datatype))
	    return FALSE;
	  if (!xdr_int (xdrs, &objp->dim))
	    return FALSE;
	  if (!xdr_int (xdrs, &objp->dataspace))
	    return FALSE;
	}
      else
	{
	  IXDR_PUT_LONG (buf, objp->category);
	  IXDR_PUT_LONG (buf, objp->param_no);
	  IXDR_PUT_LONG (buf, objp->datatype);
	  IXDR_PUT_LONG (buf, objp->dim);
	  IXDR_PUT_LONG (buf, objp->dataspace);
	}
      return TRUE;
    }
  else if (xdrs->x_op == XDR_DECODE)
    {
      if (!xdr_string (xdrs, &objp->name, ~0))
	return FALSE;
      if (!xdr_string (xdrs, &objp->datatype_string, ~0))
	return FALSE;
      buf = XDR_INLINE (xdrs, 5 * BYTES_PER_XDR_UNIT);
      if (buf == NULL)
	{
	  if (!xdr_int (xdrs, &objp->category))
	    return FALSE;
	  if (!xdr_int (xdrs, &objp->param_no))
	    return FALSE;
	  if (!xdr_int (xdrs, &objp->datatype))
	    return FALSE;
	  if (!xdr_int (xdrs, &objp->dim))
	    return FALSE;
	  if (!xdr_int (xdrs, &objp->dataspace))
	    return FALSE;
	}
      else
	{
	  objp->category = IXDR_GET_LONG (buf);
	  objp->param_no = IXDR_GET_LONG (buf);
	  objp->datatype = IXDR_GET_LONG (buf);
	  objp->dim = IXDR_GET_LONG (buf);
	  objp->dataspace = IXDR_GET_LONG (buf);
	}
      return TRUE;
    }

  if (!xdr_string (xdrs, &objp->name, ~0))
    return FALSE;
  if (!xdr_string (xdrs, &objp->datatype_string, ~0))
    return FALSE;
  if (!xdr_int (xdrs, &objp->category))
    return FALSE;
  if (!xdr_int (xdrs, &objp->param_no))
    return FALSE;
  if (!xdr_int (xdrs, &objp->datatype))
    return FALSE;
  if (!xdr_int (xdrs, &objp->dim))
    return FALSE;
  if (!xdr_int (xdrs, &objp->dataspace))
    return FALSE;
  return TRUE;
}

bool_t
xdr_ascii (XDR * xdrs, ascii * objp)
{
  register int32_t *buf;

  if (!xdr_array
      (xdrs, (char **) &objp->variables.variables_val,
       (u_int *) & objp->variables.variables_len, ~0, sizeof (variable),
       (xdrproc_t) xdr_variable))
    return FALSE;
  return TRUE;
}

bool_t
xdr_input_vals (XDR * xdrs, input_vals * objp)
{
  register int32_t *buf;

  if (!xdr_string (xdrs, &objp->prompt, ~0))
    return FALSE;
  if (!xdr_string (xdrs, &objp->variable_name, ~0))
    return FALSE;
  if (!xdr_int (xdrs, &objp->varid))
    return FALSE;
  return TRUE;
}

bool_t
xdr_output (XDR * xdrs, output * objp)
{
  register int32_t *buf;


  if (xdrs->x_op == XDR_ENCODE)
    {
      buf = XDR_INLINE (xdrs, 5 * BYTES_PER_XDR_UNIT);
      if (buf == NULL)
	{
	  if (!xdr_int (xdrs, &objp->right_margin))
	    return FALSE;
	  if (!xdr_int (xdrs, &objp->top_margin))
	    return FALSE;
	  if (!xdr_int (xdrs, &objp->left_margin))
	    return FALSE;
	  if (!xdr_int (xdrs, &objp->bottom_margin))
	    return FALSE;
	  if (!xdr_int (xdrs, &objp->page_length))
	    return FALSE;

	}
      else
	{
	  IXDR_PUT_LONG (buf, objp->right_margin);
	  IXDR_PUT_LONG (buf, objp->top_margin);
	  IXDR_PUT_LONG (buf, objp->left_margin);
	  IXDR_PUT_LONG (buf, objp->bottom_margin);
	  IXDR_PUT_LONG (buf, objp->page_length);
	}
      if (!xdr_string (xdrs, &objp->top_of_page, ~0))
	return FALSE;
      if (!xdr_int (xdrs, &objp->report_to_where))
	return FALSE;
      if (!xdr_string (xdrs, &objp->report_to_filename, ~0))
	return FALSE;
      return TRUE;
    }
  else if (xdrs->x_op == XDR_DECODE)
    {
      buf = XDR_INLINE (xdrs, 5 * BYTES_PER_XDR_UNIT);
      if (buf == NULL)
	{
	  if (!xdr_int (xdrs, &objp->right_margin))
	    return FALSE;
	  if (!xdr_int (xdrs, &objp->top_margin))
	    return FALSE;
	  if (!xdr_int (xdrs, &objp->left_margin))
	    return FALSE;
	  if (!xdr_int (xdrs, &objp->bottom_margin))
	    return FALSE;
	  if (!xdr_int (xdrs, &objp->page_length))
	    return FALSE;

	}
      else
	{
	  objp->right_margin = IXDR_GET_LONG (buf);
	  objp->top_margin = IXDR_GET_LONG (buf);
	  objp->left_margin = IXDR_GET_LONG (buf);
	  objp->bottom_margin = IXDR_GET_LONG (buf);
	  objp->page_length = IXDR_GET_LONG (buf);
	}
      if (!xdr_string (xdrs, &objp->top_of_page, ~0))
	return FALSE;
      if (!xdr_int (xdrs, &objp->report_to_where))
	return FALSE;
      if (!xdr_string (xdrs, &objp->report_to_filename, ~0))
	return FALSE;
      return TRUE;
    }

  if (!xdr_int (xdrs, &objp->right_margin))
    return FALSE;
  if (!xdr_int (xdrs, &objp->top_margin))
    return FALSE;
  if (!xdr_int (xdrs, &objp->left_margin))
    return FALSE;
  if (!xdr_int (xdrs, &objp->bottom_margin))
    return FALSE;
  if (!xdr_int (xdrs, &objp->page_length))
    return FALSE;
  if (!xdr_string (xdrs, &objp->top_of_page, ~0))
    return FALSE;
  if (!xdr_int (xdrs, &objp->report_to_where))
    return FALSE;
  if (!xdr_string (xdrs, &objp->report_to_filename, ~0))
    return FALSE;
  return TRUE;
}

bool_t
xdr_select_stmts (XDR * xdrs, select_stmts * objp)
{
  register int32_t *buf;


  if (xdrs->x_op == XDR_ENCODE)
    {
      if (!xdr_string (xdrs, &objp->statement, ~0))
	return FALSE;
      buf = XDR_INLINE (xdrs, 3 * BYTES_PER_XDR_UNIT);
      if (buf == NULL)
	{
	  if (!xdr_int (xdrs, &objp->has_where))
	    return FALSE;
	  if (!xdr_int (xdrs, &objp->wherepos1))
	    return FALSE;
	  if (!xdr_int (xdrs, &objp->wherepos2))
	    return FALSE;

	}
      else
	{
	  IXDR_PUT_LONG (buf, objp->has_where);
	  IXDR_PUT_LONG (buf, objp->wherepos1);
	  IXDR_PUT_LONG (buf, objp->wherepos2);
	}
      if (!xdr_array
	  (xdrs, (char **) &objp->varids.varids_val,
	   (u_int *) & objp->varids.varids_len, ~0, sizeof (int),
	   (xdrproc_t) xdr_int))
	return FALSE;
      if (!xdr_array
	  (xdrs, (char **) &objp->varpos.varpos_val,
	   (u_int *) & objp->varpos.varpos_len, ~0, sizeof (int),
	   (xdrproc_t) xdr_int))
	return FALSE;
      if (!xdr_string (xdrs, &objp->temp_tab_name, ~0))
	return FALSE;
      if (!xdr_array
	  (xdrs, (char **) &objp->orderby_list.orderby_list_val,
	   (u_int *) & objp->orderby_list.orderby_list_len, ~0, sizeof (int),
	   (xdrproc_t) xdr_int))
	return FALSE;
      return TRUE;
    }
  else if (xdrs->x_op == XDR_DECODE)
    {
      if (!xdr_string (xdrs, &objp->statement, ~0))
	return FALSE;
      buf = XDR_INLINE (xdrs, 3 * BYTES_PER_XDR_UNIT);
      if (buf == NULL)
	{
	  if (!xdr_int (xdrs, &objp->has_where))
	    return FALSE;
	  if (!xdr_int (xdrs, &objp->wherepos1))
	    return FALSE;
	  if (!xdr_int (xdrs, &objp->wherepos2))
	    return FALSE;

	}
      else
	{
	  objp->has_where = IXDR_GET_LONG (buf);
	  objp->wherepos1 = IXDR_GET_LONG (buf);
	  objp->wherepos2 = IXDR_GET_LONG (buf);
	}
      if (!xdr_array
	  (xdrs, (char **) &objp->varids.varids_val,
	   (u_int *) & objp->varids.varids_len, ~0, sizeof (int),
	   (xdrproc_t) xdr_int))
	return FALSE;
      if (!xdr_array
	  (xdrs, (char **) &objp->varpos.varpos_val,
	   (u_int *) & objp->varpos.varpos_len, ~0, sizeof (int),
	   (xdrproc_t) xdr_int))
	return FALSE;
      if (!xdr_string (xdrs, &objp->temp_tab_name, ~0))
	return FALSE;
      if (!xdr_array
	  (xdrs, (char **) &objp->orderby_list.orderby_list_val,
	   (u_int *) & objp->orderby_list.orderby_list_len, ~0, sizeof (int),
	   (xdrproc_t) xdr_int))
	return FALSE;
      return TRUE;
    }

  if (!xdr_string (xdrs, &objp->statement, ~0))
    return FALSE;
  if (!xdr_int (xdrs, &objp->has_where))
    return FALSE;
  if (!xdr_int (xdrs, &objp->wherepos1))
    return FALSE;
  if (!xdr_int (xdrs, &objp->wherepos2))
    return FALSE;
  if (!xdr_array
      (xdrs, (char **) &objp->varids.varids_val,
       (u_int *) & objp->varids.varids_len, ~0, sizeof (int),
       (xdrproc_t) xdr_int))
    return FALSE;
  if (!xdr_array
      (xdrs, (char **) &objp->varpos.varpos_val,
       (u_int *) & objp->varpos.varpos_len, ~0, sizeof (int),
       (xdrproc_t) xdr_int))
    return FALSE;
  if (!xdr_string (xdrs, &objp->temp_tab_name, ~0))
    return FALSE;
  if (!xdr_array
      (xdrs, (char **) &objp->orderby_list.orderby_list_val,
       (u_int *) & objp->orderby_list.orderby_list_len, ~0, sizeof (int),
       (xdrproc_t) xdr_int))
    return FALSE;
  return TRUE;
}

bool_t
xdr_read_stmt (XDR * xdrs, read_stmt * objp)
{
  register int32_t *buf;

  if (!xdr_string (xdrs, &objp->filename, ~0))
    return FALSE;
  if (!xdr_string (xdrs, &objp->delimiters, ~0))
    return FALSE;
  if (!xdr_string (xdrs, &objp->orderby, ~0))
    return FALSE;
  return TRUE;
}

bool_t
xdr_get_data (XDR * xdrs, get_data * objp)
{
  register int32_t *buf;

  if (!xdr_int (xdrs, &objp->select_or_read))
    return FALSE;
  switch (objp->select_or_read)
    {
    case 0:
      if (!xdr_array
	  (xdrs, (char **) &objp->get_data_u.selects.selects_val,
	   (u_int *) & objp->get_data_u.selects.selects_len, ~0,
	   sizeof (select_stmts), (xdrproc_t) xdr_select_stmts))
	return FALSE;
      break;
    case 1:
      if (!xdr_read_stmt (xdrs, &objp->get_data_u.read_data))
	return FALSE;
      break;
    default:
      return FALSE;
    }
  return TRUE;
}

bool_t
xdr_cmd_for (XDR * xdrs, cmd_for * objp)
{
  register int32_t *buf;

  if (!xdr_int (xdrs, &objp->varid))
    return FALSE;
  if (!xdr_expr (xdrs, &objp->start))
    return FALSE;
  if (!xdr_expr (xdrs, &objp->finish))
    return FALSE;
  if (!xdr_expr (xdrs, &objp->step))
    return FALSE;
  if (!xdr_pointer
      (xdrs, (char **) &objp->command, sizeof (struct command),
       (xdrproc_t) xdr_command))
    return FALSE;
  return TRUE;
}

bool_t
xdr_cmd_if (XDR * xdrs, cmd_if * objp)
{
  register int32_t *buf;

  if (!xdr_expr (xdrs, &objp->condition))
    return FALSE;
  if (!xdr_pointer
      (xdrs, (char **) &objp->command, sizeof (struct command),
       (xdrproc_t) xdr_command))
    return FALSE;
  if (!xdr_pointer
      (xdrs, (char **) &objp->elsecommand, sizeof (struct command),
       (xdrproc_t) xdr_command))
    return FALSE;
  return TRUE;
}

bool_t
xdr_cmd_call (XDR * xdrs, cmd_call * objp)
{
  register int32_t *buf;

  if (!xdr_pointer
      (xdrs, (char **) &objp->fcall, sizeof (expr_call),
       (xdrproc_t) xdr_expr_call))
    return FALSE;
  return TRUE;
}

bool_t
xdr_cmd_while (XDR * xdrs, cmd_while * objp)
{
  register int32_t *buf;

  if (!xdr_expr (xdrs, &objp->condition))
    return FALSE;
  if (!xdr_pointer
      (xdrs, (char **) &objp->command, sizeof (struct command),
       (xdrproc_t) xdr_command))
    return FALSE;
  return TRUE;
}

bool_t
xdr_cmd_let (XDR * xdrs, cmd_let * objp)
{
  register int32_t *buf;

  if (!xdr_int (xdrs, &objp->varid))
    return FALSE;
  if (!xdr_expr (xdrs, &objp->value))
    return FALSE;
  if (!xdr_expr (xdrs, &objp->sub1))
    return FALSE;
  if (!xdr_expr (xdrs, &objp->sub2))
    return FALSE;
  return TRUE;
}

bool_t
xdr_cmd_need (XDR * xdrs, cmd_need * objp)
{
  register int32_t *buf;

  if (!xdr_int (xdrs, &objp->nlines))
    return FALSE;
  return TRUE;
}

bool_t
xdr_cmd_pause (XDR * xdrs, cmd_pause * objp)
{
  register int32_t *buf;

  if (!xdr_string (xdrs, &objp->message, ~0))
    return FALSE;
  return TRUE;
}

bool_t
xdr_cmd_skip (XDR * xdrs, cmd_skip * objp)
{
  register int32_t *buf;

  if (!xdr_int (xdrs, &objp->nlines))
    return FALSE;
  return TRUE;
}

bool_t
xdr_cmd_print (XDR * xdrs, cmd_print * objp)
{
  register int32_t *buf;

  if (!xdr_expr (xdrs, &objp->print))
    return FALSE;
  if (!xdr_int (xdrs, &objp->printnl))
    return FALSE;
  return TRUE;
}

bool_t
xdr_cmd_printfile (XDR * xdrs, cmd_printfile * objp)
{
  register int32_t *buf;

  if (!xdr_string (xdrs, &objp->filename, ~0))
    return FALSE;
  return TRUE;
}

bool_t
xdr_function (XDR * xdrs, function * objp)
{
  register int32_t *buf;

  if (!xdr_string (xdrs, &objp->name, ~0))
    return FALSE;
  return TRUE;
}

bool_t
xdr_commands (XDR * xdrs, commands * objp)
{
  register int32_t *buf;

  if (!xdr_array
      (xdrs, (char **) &objp->commands.commands_val,
       (u_int *) & objp->commands.commands_len, ~0, sizeof (struct command),
       (xdrproc_t) xdr_command))
    return FALSE;
  return TRUE;
}

bool_t
xdr_command (XDR * xdrs, command * objp)
{
  register int32_t *buf;

  if (!xdr_cmdtypes (xdrs, &objp->cmd_type))
    return FALSE;
  switch (objp->cmd_type)
    {
    case CMD_NULL:
      if (!xdr_int (xdrs, &objp->command_u.null))
	return FALSE;
      break;
    case CMD_FOR:
      if (!xdr_cmd_for (xdrs, &objp->command_u.cmd_for))
	return FALSE;
      break;
    case CMD_IF:
      if (!xdr_cmd_if (xdrs, &objp->command_u.cmd_if))
	return FALSE;
      break;
    case CMD_WHILE:
      if (!xdr_cmd_while (xdrs, &objp->command_u.cmd_while))
	return FALSE;
      break;
    case CMD_LET:
      if (!xdr_cmd_let (xdrs, &objp->command_u.cmd_let))
	return FALSE;
      break;
    case CMD_NEED:
      if (!xdr_cmd_need (xdrs, &objp->command_u.cmd_need))
	return FALSE;
      break;
    case CMD_PAUSE:
      if (!xdr_cmd_pause (xdrs, &objp->command_u.cmd_pause))
	return FALSE;
      break;
    case CMD_SKIP:
      if (!xdr_cmd_skip (xdrs, &objp->command_u.cmd_skip))
	return FALSE;
      break;
    case CMD_PRINT:
      if (!xdr_cmd_print (xdrs, &objp->command_u.cmd_print))
	return FALSE;
      break;
    case CMD_PRINTFILE:
      if (!xdr_cmd_printfile (xdrs, &objp->command_u.cmd_printfile))
	return FALSE;
      break;
    case CMD_BLOCK:
      if (!xdr_commands (xdrs, &objp->command_u.commands))
	return FALSE;
      break;
    case CMD_CALL:
      if (!xdr_cmd_call (xdrs, &objp->command_u.cmd_call))
	return FALSE;
      break;
    default:
      return FALSE;
    }
  return TRUE;
}

bool_t
xdr_formattype (XDR * xdrs, formattype * objp)
{
  register int32_t *buf;

  if (!xdr_enum (xdrs, (enum_t *) objp))
    return FALSE;
  return TRUE;
}

bool_t
xdr_format (XDR * xdrs, format * objp)
{
  register int32_t *buf;

  if (!xdr_formattype (xdrs, &objp->category))
    return FALSE;
  if (!xdr_string (xdrs, &objp->column, ~0))
    return FALSE;
  if (!xdr_commands (xdrs, &objp->commands))
    return FALSE;
  return TRUE;
}

bool_t
xdr_agg_val (XDR * xdrs, agg_val * objp)
{
  register int32_t *buf;

  if (!xdr_int (xdrs, &objp->format_id))
    return FALSE;
  if (!xdr_aggtypes (xdrs, &objp->type))
    return FALSE;
  if (!xdr_bool (xdrs, &objp->isgroup))
    return FALSE;
  if (!xdr_pointer
      (xdrs, (char **) &objp->expr, sizeof (expr), (xdrproc_t) xdr_expr))
    return FALSE;
  if (!xdr_pointer
      (xdrs, (char **) &objp->wexpr, sizeof (expr), (xdrproc_t) xdr_expr))
    return FALSE;
  return TRUE;
}

bool_t
xdr_report (XDR * xdrs, report * objp)
{
  register int32_t *buf;

  if (!xdr_string (xdrs, &objp->magic, ~0))
    return FALSE;
  if (!xdr_string (xdrs, &objp->report_name, ~0))
    return FALSE;
  if (!xdr_string (xdrs, &objp->dbname, ~0))
    return FALSE;
  if (!xdr_ascii (xdrs, &objp->ascii))
    return FALSE;
  if (!xdr_array
      (xdrs, (char **) &objp->functions.functions_val,
       (u_int *) & objp->functions.functions_len, ~0, sizeof (function),
       (xdrproc_t) xdr_function))
    return FALSE;
  if (!xdr_array
      (xdrs, (char **) &objp->variables.variables_val,
       (u_int *) & objp->variables.variables_len, ~0, sizeof (variable),
       (xdrproc_t) xdr_variable))
    return FALSE;
  if (!xdr_array
      (xdrs, (char **) &objp->inputs.inputs_val,
       (u_int *) & objp->inputs.inputs_len, ~0, sizeof (input_vals),
       (xdrproc_t) xdr_input_vals))
    return FALSE;
  if (!xdr_output (xdrs, &objp->output))
    return FALSE;
  if (!xdr_get_data (xdrs, &objp->getdata))
    return FALSE;
  if (!xdr_array
      (xdrs, (char **) &objp->fmt.fmt_val, (u_int *) & objp->fmt.fmt_len, ~0,
       sizeof (format), (xdrproc_t) xdr_format))
    return FALSE;
  if (!xdr_array
      (xdrs, (char **) &objp->aggs.aggs_val, (u_int *) & objp->aggs.aggs_len,
       ~0, sizeof (agg_val), (xdrproc_t) xdr_agg_val))
    return FALSE;
  return TRUE;
}

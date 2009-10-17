/*
 * Please do not A4GL_edit this file.
 * It was generated using rpcgen.
 */

#ifndef _REPORT_H_RPCGEN
#define _REPORT_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C"
{
#endif

#define AACE_XDR_VERSION 100
#define AACE_XDR_MAGIC 0xa4ac1234

  enum cmdtypes
  {
    CMD_NULL = 0,
    CMD_FOR = 1,
    CMD_IF = 2,
    CMD_WHILE = 3,
    CMD_LET = 4,
    CMD_NEED = 5,
    CMD_SKIP = 6,
    CMD_PAUSE = 7,
    CMD_PRINT = 8,
    CMD_PRINTFILE = 9,
    CMD_BLOCK = 10,
    CMD_CALL = 11,
  };
  typedef enum cmdtypes cmdtypes;

  enum varcats
  {
    CAT_NULL = 0,
    CAT_INTERNAL = 1,
    CAT_PARAM = 2,
    CAT_VARIABLE = 3,
    CAT_SQL = 4,
    CAT_FUNCTION = 5,
    CAT_BUILTIN = 6,
  };
  typedef enum varcats varcats;

  enum aggtypes
  {
    AGG_COUNT = 0,
    AGG_PERCENT = 1,
    AGG_AVG = 2,
    AGG_TOTAL = 3,
    AGG_MIN = 4,
    AGG_MAX = 5,
  };
  typedef enum aggtypes aggtypes;

  enum expr_operands
  {
    EXPR_AND = 0,
    EXPR_OR = 1,
    EXPR_ADD = 2,
    EXPR_SUB = 3,
    EXPR_MUL = 4,
    EXPR_DIV = 5,
    EXPR_POW = 6,
    EXPR_MOD = 7,
    EXPR_CLIP = 8,
    EXPR_USING = 9,
    EXPR_COLUMN = 10,
    EXPR_SPACES = 11,
    EXPR_CONCAT = 12,
    EXPR_ISNULL = 13,
    EXPR_ISNOTNULL = 14,
    EXPR_ASCII = 15,
    EXPR_POSITION = 16,
  };
  typedef enum expr_operands expr_operands;

  enum exprtype
  {
    EXPRTYPE_NULL = 0,
    EXPRTYPE_INT = 1,
    EXPRTYPE_DOUBLE = 2,
    EXPRTYPE_STRING = 3,
    EXPRTYPE_VARIABLE = 4,
    EXPRTYPE_BUILTIN = 5,
    EXPRTYPE_COMPLEX = 6,
    EXPRTYPE_SIMPLE = 7,
    EXPRTYPE_LIST = 8,
    EXPRTYPE_COMPARE = 9,
    EXPRTYPE_FCALL = 10,
    EXPRTYPE_AGG = 11,
  };
  typedef enum exprtype exprtype;

  struct expr
  {
    exprtype type;
    union
    {
      int null;
      int i;
      double d;
      char *s;
      int varid;
      char *name;
      struct complex_expr *expr;
      struct compare_expr *cexpr;
      struct simple_expr *sexpr;
      struct expr_list *lexpr;
      struct expr_call *fcall;
      int aggid;
    }
    expr_u;
  };
  typedef struct expr expr;

  struct expr_list
  {
    struct
    {
      u_int elem_len;
      struct expr *elem_val;
    }
    elem;
  };
  typedef struct expr_list expr_list;

  struct expr_call
  {
    char *fname;
    struct expr_list *lexpr;
  };
  typedef struct expr_call expr_call;

  struct complex_expr
  {
    struct expr expr1;
    enum expr_operands operand;
    struct expr expr2;
  };
  typedef struct complex_expr complex_expr;

  struct compare_expr
  {
    char *method;
    struct expr expr1;
    struct expr expr2;
  };
  typedef struct compare_expr compare_expr;

  struct simple_expr
  {
    struct expr expr;
    enum expr_operands operand;
  };
  typedef struct simple_expr simple_expr;

  struct variable
  {
    char *name;
    char *datatype_string;
    int category;
    int param_no;
    int datatype;
    int dim;
    int dataspace;
  };
  typedef struct variable variable;

  struct ascii
  {
    struct
    {
      u_int variables_len;
      struct variable *variables_val;
    }
    variables;
  };
  typedef struct ascii ascii;

  struct input_vals
  {
    char *prompt;
    char *variable_name;
    int varid;
  };
  typedef struct input_vals input_vals;

  struct output
  {
    int right_margin;
    int top_margin;
    int left_margin;
    int bottom_margin;
    int page_length;
    char *top_of_page;
    int report_to_where;
    char *report_to_filename;
  };
  typedef struct output output;

  struct select_stmts
  {
    char *statement;
    int has_where;
    int wherepos1;
    int wherepos2;
    struct
    {
      u_int varids_len;
      int *varids_val;
    }
    varids;
    struct
    {
      u_int varpos_len;
      int *varpos_val;
    }
    varpos;
    char *temp_tab_name;
    struct
    {
      u_int orderby_list_len;
      int *orderby_list_val;
    }
    orderby_list;
  };
  typedef struct select_stmts select_stmts;

  struct read_stmt
  {
    char *filename;
    char *delimiters;
    char *orderby;
  };
  typedef struct read_stmt read_stmt;

  struct get_data
  {
    int select_or_read;
    union
    {
      struct
      {
	u_int selects_len;
	struct select_stmts *selects_val;
      }
      selects;
      struct read_stmt read_data;
    }
    get_data_u;
  };
  typedef struct get_data get_data;

  struct cmd_for
  {
    int varid;
    struct expr start;
    struct expr finish;
    struct expr step;
    struct command *command;
  };
  typedef struct cmd_for cmd_for;

  struct cmd_if
  {
    struct expr condition;
    struct command *command;
    struct command *elsecommand;
  };
  typedef struct cmd_if cmd_if;

  struct cmd_call
  {
    struct expr_call *fcall;
  };
  typedef struct cmd_call cmd_call;

  struct cmd_while
  {
    struct expr condition;
    struct command *command;
  };
  typedef struct cmd_while cmd_while;

  struct cmd_let
  {
    int varid;
    struct expr value;
    struct expr sub1;
    struct expr sub2;
  };
  typedef struct cmd_let cmd_let;

  struct cmd_need
  {
    int nlines;
  };
  typedef struct cmd_need cmd_need;

  struct cmd_pause
  {
    char *message;
  };
  typedef struct cmd_pause cmd_pause;

  struct cmd_skip
  {
    int nlines;
  };
  typedef struct cmd_skip cmd_skip;

  struct cmd_print
  {
    struct expr print;
    int printnl;
  };
  typedef struct cmd_print cmd_print;

  struct cmd_printfile
  {
    char *filename;
  };
  typedef struct cmd_printfile cmd_printfile;

  struct function
  {
    char *name;
  };
  typedef struct function function;

  struct commands
  {
    struct
    {
      u_int commands_len;
      struct command *commands_val;
    }
    commands;
  };
  typedef struct commands commands;

  struct command
  {
    cmdtypes cmd_type;
    union
    {
      int null;
      struct cmd_for cmd_for;
      struct cmd_if cmd_if;
      struct cmd_while cmd_while;
      struct cmd_let cmd_let;
      struct cmd_need cmd_need;
      struct cmd_pause cmd_pause;
      struct cmd_skip cmd_skip;
      struct cmd_print cmd_print;
      struct cmd_printfile cmd_printfile;
      struct commands commands;
      struct cmd_call cmd_call;
    }
    command_u;
  };
  typedef struct command command;

  enum formattype
  {
    FORMAT_PAGE_HEADER = 0,
    FORMAT_FIRST_PAGE_HEADER = 1,
    FORMAT_PAGE_TRAILER = 2,
    FORMAT_EVERY_ROW = 3,
    FORMAT_ON_EVERY_ROW = 4,
    FORMAT_BEFORE_GROUP = 5,
    FORMAT_AFTER_GROUP = 6,
    FORMAT_ON_LAST_ROW = 7,
  };
  typedef enum formattype formattype;

  struct format
  {
    enum formattype category;
    char *column;
    struct commands commands;
  };
  typedef struct format format;

  struct agg_val
  {
    int format_id;
    enum aggtypes type;
    bool_t isgroup;
    struct expr *expr;
    struct expr *wexpr;
  };
  typedef struct agg_val agg_val;

  struct report
  {
    char *magic;
    char *report_name;
    char *dbname;
    struct ascii ascii;
    struct
    {
      u_int functions_len;
      struct function *functions_val;
    }
    functions;
    struct
    {
      u_int variables_len;
      struct variable *variables_val;
    }
    variables;
    struct
    {
      u_int inputs_len;
      struct input_vals *inputs_val;
    }
    inputs;
    struct output output;
    struct get_data getdata;
    struct
    {
      u_int fmt_len;
      struct format *fmt_val;
    }
    fmt;
    struct
    {
      u_int aggs_len;
      struct agg_val *aggs_val;
    }
    aggs;
  };
  typedef struct report report;

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
  extern bool_t xdr_cmdtypes (XDR *, cmdtypes *);
  extern bool_t xdr_varcats (XDR *, varcats *);
  extern bool_t xdr_aggtypes (XDR *, aggtypes *);
  extern bool_t xdr_expr_operands (XDR *, expr_operands *);
  extern bool_t xdr_exprtype (XDR *, exprtype *);
  extern bool_t xdr_expr (XDR *, expr *);
  extern bool_t xdr_expr_list (XDR *, expr_list *);
  extern bool_t xdr_expr_call (XDR *, expr_call *);
  extern bool_t xdr_complex_expr (XDR *, complex_expr *);
  extern bool_t xdr_compare_expr (XDR *, compare_expr *);
  extern bool_t xdr_simple_expr (XDR *, simple_expr *);
  extern bool_t xdr_variable (XDR *, variable *);
  extern bool_t xdr_ascii (XDR *, ascii *);
  extern bool_t xdr_input_vals (XDR *, input_vals *);
  extern bool_t xdr_output (XDR *, output *);
  extern bool_t xdr_select_stmts (XDR *, select_stmts *);
  extern bool_t xdr_read_stmt (XDR *, read_stmt *);
  extern bool_t xdr_get_data (XDR *, get_data *);
  extern bool_t xdr_cmd_for (XDR *, cmd_for *);
  extern bool_t xdr_cmd_if (XDR *, cmd_if *);
  extern bool_t xdr_cmd_call (XDR *, cmd_call *);
  extern bool_t xdr_cmd_while (XDR *, cmd_while *);
  extern bool_t xdr_cmd_let (XDR *, cmd_let *);
  extern bool_t xdr_cmd_need (XDR *, cmd_need *);
  extern bool_t xdr_cmd_pause (XDR *, cmd_pause *);
  extern bool_t xdr_cmd_skip (XDR *, cmd_skip *);
  extern bool_t xdr_cmd_print (XDR *, cmd_print *);
  extern bool_t xdr_cmd_printfile (XDR *, cmd_printfile *);
  extern bool_t xdr_function (XDR *, function *);
  extern bool_t xdr_commands (XDR *, commands *);
  extern bool_t xdr_command (XDR *, command *);
  extern bool_t xdr_formattype (XDR *, formattype *);
  extern bool_t xdr_format (XDR *, format *);
  extern bool_t xdr_agg_val (XDR *, agg_val *);
  extern bool_t xdr_report (XDR *, report *);

#else				/* K&R C */
  extern bool_t xdr_cmdtypes ();
  extern bool_t xdr_varcats ();
  extern bool_t xdr_aggtypes ();
  extern bool_t xdr_expr_operands ();
  extern bool_t xdr_exprtype ();
  extern bool_t xdr_expr ();
  extern bool_t xdr_expr_list ();
  extern bool_t xdr_expr_call ();
  extern bool_t xdr_complex_expr ();
  extern bool_t xdr_compare_expr ();
  extern bool_t xdr_simple_expr ();
  extern bool_t xdr_variable ();
  extern bool_t xdr_ascii ();
  extern bool_t xdr_input_vals ();
  extern bool_t xdr_output ();
  extern bool_t xdr_select_stmts ();
  extern bool_t xdr_read_stmt ();
  extern bool_t xdr_get_data ();
  extern bool_t xdr_cmd_for ();
  extern bool_t xdr_cmd_if ();
  extern bool_t xdr_cmd_call ();
  extern bool_t xdr_cmd_while ();
  extern bool_t xdr_cmd_let ();
  extern bool_t xdr_cmd_need ();
  extern bool_t xdr_cmd_pause ();
  extern bool_t xdr_cmd_skip ();
  extern bool_t xdr_cmd_print ();
  extern bool_t xdr_cmd_printfile ();
  extern bool_t xdr_function ();
  extern bool_t xdr_commands ();
  extern bool_t xdr_command ();
  extern bool_t xdr_formattype ();
  extern bool_t xdr_format ();
  extern bool_t xdr_agg_val ();
  extern bool_t xdr_report ();

#endif				/* K&R C */

#ifdef __cplusplus
}
#endif

#endif				/* !_REPORT_H_RPCGEN */

#include "a4gl_API_sqlparse_lib.h"
#include "a4gl_libaubit4gl.h"
#include "sql_compiler_util.h"
#include "commands.h"

struct command *new_command (enum cmd_type ct) {
        struct command *c;
        //char *ptr;
        c=malloc(sizeof(struct command));
        memset(c,0,sizeof(struct command));
        c->cmd_data.type=ct;
        c->colno=0;
                c->lineno=0;
                c->colno=0;
        c->module="internal";
        c->comment="";
        c->ignore_error_list=NULL;

        return c;
}


struct command *new_sql_transact_cmd(expr_str * connid, int p_trans) {
struct command *c;
   c=new_command(E_CMD_SQL_TRANSACT_CMD);
   c->cmd_data.command_data_u.sql_transact_cmd.connid=connid;
   c->cmd_data.command_data_u.sql_transact_cmd.trans=p_trans;
   return c;
}

struct command *new_set_database_cmd(expr_str* p_dbname,e_boolean p_exclusive,struct expr_str *p_sqltype) {
struct command *c;
   c=new_command(E_CMD_SET_DATABASE_CMD);
   c->cmd_data.command_data_u.set_database_cmd.set_dbname=p_dbname;
   c->cmd_data.command_data_u.set_database_cmd.exclusive_mode=p_exclusive;
   c->cmd_data.command_data_u.set_database_cmd.sqltype=p_sqltype;
   return c;
}



struct command *new_select_cmd(expr_str *p_connid, struct s_select * p_sql,char *forupdate) {
struct command *c;
   c=new_command(E_CMD_SELECT_CMD);
   c->cmd_data.command_data_u.select_cmd.connid=p_connid;
   c->cmd_data.command_data_u.select_cmd.sql=p_sql;
   c->cmd_data.command_data_u.select_cmd.forupdate=strdup(forupdate);
//@  FIXME - inc_var_usage
   return c;
}

struct command *new_sql_cmd(expr_str *p_connid, char * p_sql) {
struct command *c;
   c=new_command(E_CMD_SQL_CMD);
   c->cmd_data.command_data_u.sql_cmd.connid=p_connid;
   c->cmd_data.command_data_u.sql_cmd.sql=strdup(p_sql);
   return c;
}


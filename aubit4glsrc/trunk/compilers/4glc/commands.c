
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "a4gl_4glc_int.h"
#include "lint.h"
#include "parsehelp.h"

extern int yylineno;
extern int token_read_on_line;
extern int token_read_on_col;
struct commands * linearise_commands(struct commands *master_list, struct commands *cmds) ;
//static char *get_expr_list_as_string(struct expr_str_list *l) ;
//static void linearise_commands_from_events(struct commands *master_list, struct on_events* evt_list) ;
//char *A4GL_get_current_comments();
static int get_exit_loop (char *cmd_type);
//struct expr_str *A4GL_new_expr_list_with_list(expr_str_list *l);
extern struct expr_str_list list_of_aggregates;
extern struct call_list *this_functions_call_list;

int llineno=0;

int set_cmdlineno(int n) {
	if (n==0) {
		n=yylineno;
	} 
	llineno=n;
	return llineno;
}

struct command *new_command (enum cmd_type ct) {
	struct command *c;
	//char *ptr;
	c=malloc(sizeof(struct command));
	memset(c,0,sizeof(struct command));
	c->cmd_data.type=ct;
	c->colno=0;
	if (llineno!=0) {
		c->lineno=llineno;
		llineno=0;
	} else {
		c->lineno=token_read_on_line;
		c->colno=token_read_on_col;
	}
	c->module=A4GL_compiling_module_basename();
	c->comment=A4GL_get_current_comments(c->lineno, c->colno);
	return c;
}


char *cmds_get_variable_usage_as_string (struct variable_usage *var_usage) {
	char buff[2000];

        sprintf(buff, "%s",var_usage->variable_name);
        if (var_usage->subscripts.subscripts_len) {
                int a;
                strcat(buff, "[");
                for (a=0;a<var_usage->subscripts.subscripts_len;a++) {
                        if(a) strcat(buff, ",");
			strcat(buff, expr_as_string_when_possible(var_usage->subscripts.subscripts_val[a]));
                }
                strcat(buff, "]");
        }
        if (var_usage->substrings_start) {
                strcat(buff, "[");
                strcat(buff, expr_as_string_when_possible(var_usage->substrings_start));
                if (var_usage->substrings_end) {
                        strcat(buff, ",");
                        strcat(buff, expr_as_string_when_possible(var_usage->substrings_end));
                }
                strcat(buff, "]");
        }
        if (var_usage->next) {
		char *ptr;
                strcat(buff,".");
		ptr=cmds_get_variable_usage_as_string(var_usage->next);
                strcat(buff, ptr);
		free(ptr);
        }

	return strdup(buff);
}


char *A4GL_get_current_comments(int lineno,int colno) {
	char *ptr;
	char buff[200000]="";
	strcpy(buff,"");
	ptr=A4GL_has_comment(lineno,colno);
	while (ptr) {
		if (strlen(buff)) strcat(buff,"\n");
		strcat(buff, ptr);
		ptr=A4GL_has_comment(lineno,colno);
	}
	if (strlen(buff)) {
		return strdup(buff);
	} else {
		return "";
	}
}



char *expr_as_string_when_possible(expr_str *e) {

FILE *f;
  switch (e->expr_type)
    {
    case ET_EXPR_LITERAL_EMPTY_STRING:
      return "";
    /*case ET_EXPR_SUBSTRING:
      return "?"; */
    case ET_EXPR_LITERAL_STRING:
      return e->expr_str_u.expr_string;
      break;


    case ET_EXPR_VARIABLE_USAGE:

      {
		return cmds_get_variable_usage_as_string(e->expr_str_u.expr_variable_usage);
		//return "FGLvariable"; 
      }
      break;

    case ET_EXPR_LITERAL_LONG:

      {
        static char smbuff[200];
        sprintf (smbuff, "%d", e->expr_str_u.expr_long);
        return smbuff;
      }
      break;
    case ET_EXPR_OP_USING:
      return "?";               // a date or a number - we dont care...
      break;
    case ET_EXPR_OP_CLIP:

      {
        char *p;
        p = strdup (expr_as_string_when_possible (e->expr_str_u.expr_expr));
        A4GL_trim (p);
        return p;
      }
      break;
    case ET_EXPR_GET_FLDBUF:
    case ET_EXPR_ASCII:
    case ET_EXPR_FCALL:
      return "?";

        case ET_EXPR_FALSE: return "0";
        case ET_EXPR_TRUE: return "1";

        case ET_EXPR_OP_CONCAT:
                      {
                char buff[2000];
                sprintf(buff,"%s,%s", expr_as_string_when_possible (e->expr_str_u.expr_op->left), expr_as_string_when_possible (e->expr_str_u.expr_op->right));
                return strdup(buff);
                }
                break;

        case ET_EXPR_OP_EQUAL:
                                {
                char buff[2000];
                sprintf(buff,"%s=%s", expr_as_string_when_possible (e->expr_str_u.expr_op->left), expr_as_string_when_possible (e->expr_str_u.expr_op->right));
                return strdup(buff);
                }
                break;


        case ET_EXPR_DATE_EXPR:
                return "DATE";

        case ET_EXPR_DATE_FUNC:
      {
        char buff[256];
        sprintf (buff, "DATE(%s)", expr_as_string_when_possible (e->expr_str_u.expr_expr));
        return strdup (buff);
      }
      break;
        case ET_EXPR_MONTH_FUNC:
      {
        char buff[256];
        sprintf (buff, "MONTH(%s)", expr_as_string_when_possible (e->expr_str_u.expr_expr));
        return strdup (buff);
      }
      break;

        case ET_EXPR_LITERAL_DOUBLE_STR:
      {
        char buff[256];
        sprintf (buff, "\"%s\"", e->expr_str_u.expr_string);
        return strdup (buff);
      }

        case ET_EXPR_OP_DAY:
                return "?";
        case ET_EXPR_OP_MONTH:
                return "?";


        case ET_EXPR_OP_MINUTE:
                return "?";

        case ET_EXPR_COLUMN:
                return "";

        case ET_EXPR_CURRENT:
                return " CURRENT";
        case ET_EXPR_OP_MULT:
                {
                char buff[2000];
                sprintf(buff,"%s*%s", expr_as_string_when_possible (e->expr_str_u.expr_op->left), expr_as_string_when_possible (e->expr_str_u.expr_op->right));
                return strdup(buff);
                }
                break;
        case ET_EXPR_OP_DIV:
                {
                char buff[2000];
                sprintf(buff,"%s/%s", expr_as_string_when_possible (e->expr_str_u.expr_op->left), expr_as_string_when_possible (e->expr_str_u.expr_op->right));
                return strdup(buff);
                }
                break;

        case ET_EXPR_OP_ADD:
                {
                char buff[2000];
                sprintf(buff,"%s+%s", expr_as_string_when_possible (e->expr_str_u.expr_op->left), expr_as_string_when_possible (e->expr_str_u.expr_op->right));
                return strdup(buff);
                }
                break;
        case ET_EXPR_OP_SUB:
                {
                char buff[2000];
                sprintf(buff,"%s+%s", expr_as_string_when_possible (e->expr_str_u.expr_op->left), expr_as_string_when_possible (e->expr_str_u.expr_op->right));
                return strdup(buff);
                }
                break;

        case ET_EXPR_OP_SPACES:
                return " ";

        case ET_EXPR_TIME_EXPR: return "TIME";
        case ET_EXPR_TODAY: return "TODAY";
	case ET_EXPR_ASSOC:
      {
        char *p;
        char buff[256];
        sprintf (buff, "<<%s>>", expr_as_string_when_possible (e->expr_str_u.expr_assoc_subscript->subscript_value));
        return strdup (buff);
      }
		

    case ET_EXPR_NULL:
      return "NULL";

        case ET_EXPR_DAY_FUNC:
      {
        char *p;
        char buff[256];
        sprintf (buff, "DAY(%s)", expr_as_string_when_possible (e->expr_str_u.expr_expr));
        return strdup (buff);
      }
      break;

    case ET_EXPR_YEAR_FUNC:

      {
        char *p;
        char buff[256];
        sprintf (buff, "YEAR(%s)", expr_as_string_when_possible (e->expr_str_u.expr_expr));
        return strdup (buff);
      }
      break;
    case ET_EXPR_UPSHIFT:

      {
        char *p;
        p = strdup (expr_as_string_when_possible (e->expr_str_u.expr_expr));
        upshift (p);
        return p;
      }
      break;
    case ET_EXPR_DOWNSHIFT:

      {
        char *p;
        p = strdup (expr_as_string_when_possible (e->expr_str_u.expr_expr));
        downshift (p);
        return p;
      }
      break;

    default:
                f=fopen("/tmp/bad_expr","a");
                fprintf(f,"%s %d - %s\n", A4GL_compiling_module_basename(), yylineno, expr_name (e->expr_type));
                fclose(f);
        printf ("Unhandled expression in dynamic sql(%s) - line %d\n", expr_name (e->expr_type), yylineno);
        return "?";
      //exit (2);
      //    }
      }
return "X";
}
struct module_entry *new_module_entry(enum module_entry_type met_type) {
struct module_entry *c;
   c=malloc(sizeof(module_entry));
   c->met_type=met_type;
   return c;
}

struct single_option *new_option (char c, char *v,int isKey) {
	struct single_option *s;
	s=malloc(sizeof(single_option));
	s->option=malloc(2);
	s->option[0]=c;
	s->option[1]=0;
	s->value=strdup(v);
	s->isKey=isKey;
	s->expr=0;
	return s;
};


struct single_option *new_option_expr (char c, struct expr_str *v,int isKey) {
	struct single_option *s;
	s=malloc(sizeof(single_option));
	s->option=malloc(2);
	s->option[0]=c;
	s->option[1]=0;
	s->value=0; //strdup(v);
	s->isKey=isKey;
	s->expr=v;
	return s;
};



struct expr_str *new_variable_or_literal (enum e_expr_type t, char *s) {
struct expr_str *l;

switch (t) {
        case ET_E_V_OR_LIT_VAR:
        case ET_E_V_OR_LIT_INT:
        case ET_E_V_OR_LIT_STRING:
        case ET_E_V_OR_LIT_VAR_AS_STRING:
        case ET_E_V_OR_LIT_IDENT:
        case ET_E_V_OR_LIT_NOVALUE: break;
	default: A4GL_assertion(1,"Invalid expression type for new_variable_or_literal"); return 0;
}

l=A4GL_new_expr_simple(t);
	switch (t) {
                case ET_E_V_OR_LIT_INT:            l->expr_str_u.i  = atoi(s);break;
                case ET_E_V_OR_LIT_STRING:         l->expr_str_u.s=strdup(s);break;
                case ET_E_V_OR_LIT_VAR_AS_STRING:  l->expr_str_u.sv=strdup(s);inc_var_usage(l);break;
	
                case ET_E_V_OR_LIT_IDENT:  	l->expr_str_u.si=strdup(s);break;

                case ET_E_V_OR_LIT_VAR: 		
				A4GL_assertion(1,"Not yet");
			/*
				l->expr_str_u.var=(expr_str* )make_bind(s);inc_var_usage(s);
				if (l->expr_str_u.var->scope==0) {
					l->expr_str_u.var->scope=' ';
				}
			*/
			break;

	        //case ET_E_V_OR_LIT_NULL:	break;

	        case ET_E_V_OR_LIT_NOVALUE:  
			A4GL_assertion(1, "Not implemented");
	default: A4GL_assertion(1,"Invalid expression type for new_variable_or_literal"); return 0;

	}
return l;
}

void clr_attrib(struct attrib *attr ) {
        attr->color=-1;
        attr->nonewlines=EB_NOTSET;
        attr->bold=EB_NOTSET;
        attr->blink=EB_NOTSET;
        attr->reverse=EB_NOTSET;
        attr->dim=EB_NOTSET;
        attr->invisible=EB_NOTSET;
        attr->underline=EB_NOTSET;
        attr->normal=EB_NOTSET;
        attr->style="";
        attr->currentrowdisplay="";
        attr->count=0;
        attr->maxcount=0;
        attr->allow_insert=EB_NOTSET;
        attr->allow_delete=EB_NOTSET;
        attr->no_new_lines=EB_NOTSET;
        attr->border=EB_NOTSET;
        attr->text="";
        attr->pad="";
        attr->comment_line=0;
        attr->form_line=0;
        attr->error_line=0;
        attr->menu_line=0;
        attr->message_line=0;
        attr->prompt_line=0;
        attr->var_attrib=0;
}




/* The following code was generatd using the m1.awk script... */
/* 
/^struct .*_cmd/ {
	gsub("struct_","",$2)
	structname=$2;
	delete arr;
	row=1
	next;
	}


/^}/ {
	if (structname=="") { next;}

	printf("struct command *new_%s(", structname)
	for (a=1;a<row;a++) {
		if (a>1) printf(",");
		printf("%s p_%s",dtypes[a], dnames[a]);
	}
	printf(") {\n");
        print "struct command *c;"
        print "   c=new_command(E_CMD_" toupper(structname) ");"

	for (a=1;a<row;a++) {
		printf("   c->cmd_data.command_data_u.%s.%s=",structname, dnames[a]);
		if (dtypes[a]=="char *") {
			printf("strdup(%s);\n", dnames[a]);
		} else {
			printf("p_%s;\n", dnames[a]);
		}
	}
        print "   return c;"
	print "}"
	structname="";
	print " "
	next;
}


(structname!="") {
	
	gsub(";","",$0)
	if (NF==3) {
		dtype=$1 " " $2
		var=$3
	} else {
		dtype=$1
		var=$2
	}

	if (dtype=="str") dtype="char *";
	dtypes[row]=dtype
	dnames[row]=var
	row++;
}
*/


// These are 'voids' and implemnted using new_command(E_CMD_....);
// new_pause_screen_on_cmd
// new_pause_screen_off_cmd
// new_stop_rpc_cmd
// new_skip_to_top_cmd


struct command *new_cancel_cmd(enum cancel_type p_c) { //!
struct command *c;
   c=new_command(E_CMD_CANCEL_CMD);
   c->cmd_data.command_data_u.cancel_cmd.c=p_c;
   return c;
}
 
struct command *new_close_cmd(enum e_close_type_nosql p_type,expr_str * p_ident) { //!
struct command *c;
   c=new_command(E_CMD_CLOSE_CMD);
   c->cmd_data.command_data_u.close_cmd.cl_type=p_type;
   c->cmd_data.command_data_u.close_cmd.ident=p_ident;
   return c;
}
 
struct command *new_close_sql_cmd(enum e_close_type_withsql p_type,expr_str * p_ident) { //!
struct command *c;
   c=new_command(E_CMD_CLOSE_SQL_CMD);
   c->cmd_data.command_data_u.close_sql_cmd.cl_type=p_type;
   c->cmd_data.command_data_u.close_sql_cmd.ident=p_ident;
   return c;
}
struct command *new_free_cmd(expr_str *p_connid, expr_str *p_cursorname) { //!
struct command *c;
   c=new_command(E_CMD_FREE_CMD);
   c->cmd_data.command_data_u.free_cmd.cursorname=p_cursorname;
   c->cmd_data.command_data_u.free_cmd.connid=p_connid;
   return c;
}
 
struct command *new_continue_cmd(enum e_block_cmd p_what) { //!
struct command *c;
int block_no=0;
int sio_id=0;
 
   c=new_command(E_CMD_CONTINUE_CMD);
   c->cmd_data.command_data_u.continue_cmd.what=p_what;
    switch (p_what) {
	case EBC_WHILE:  
		block_no=get_exit_loop("WHILE");
		break;
	case EBC_FOR:           // Exit FOR
		block_no=get_exit_loop("FOR");
		break;
	case EBC_INPUT:         // Exit INPUT
		sio_id=get_sio_id("INPUT");
		block_no=get_exit_loop("INPUT");
		break;
	case EBC_FOREACH:       // Exit FOREACH
		block_no=get_exit_loop("FOREACH");
		break;
	case EBC_CONSTRUCT:     // Exit CONSTRUCT
		sio_id=get_sio_id("CONSTRUCT");
		block_no=get_exit_loop("CONSTRUCT");
		break;
	case EBC_DISPLAY:       // Exit DISPLAY
		block_no=get_exit_loop("DISPLAY");
		break;
	case EBC_MENU:          // Exit MENU
		block_no=get_exit_loop("MENU");
		break;
	case EBC_PROMPT:        // Exit PROMPT
		block_no=get_exit_loop("PROMPT");
		break;
	case EBC_CASE:          // Exit CASE
		block_no=get_exit_loop("CASE");
		break;
   }

   c->cmd_data.command_data_u.continue_cmd.block_id=block_no;
   c->cmd_data.command_data_u.continue_cmd.sio_id=sio_id;
   return c;
}


/**
 *  * The parser found a EXIT instruction for a specific loop command.
 *  *
 *  * One example could be EXIT WHILE.
 *  *
 *  * The loop commands could be:
 *  *   - WHILE
 *  *   - INPUT
 *  *   - FOREACH
 *  *   - FOR
 *  *   - CONSTRUCT
 *  *   - DISPLAY
 *  *   - MENU
 *  *
 *  *   Finds backwards the opened corresponding command.
 *  *   This means that if we have a EXIT WHILE then it belongs to the
 *  *   last founded (and not yet closed) WHILE.
 *  *
 *  * @param cmd_type The string containing the type name of the loop used
 *  */
static int get_exit_loop (char *cmd_type)
{
  int a;
  int ccnt;
  int g = 0;
  int printed = 0;
  ccnt = A4GL_get_ccnt ();

  for (a = ccnt - 1; a >= 0; a--)
    {
      if (strcmp (command_type_for_stack_pos(a), cmd_type) == 0)
        {
          g = 1;
          break;
        }
    }

  if (g == 0)
    {
      printf ("wanted to exit a %s but wasnt in one!\n", cmd_type);
      A4GL_debug ("/* wanted to exit a %s but wasnt in one! */", cmd_type);
      return 0;
    }

  if (strcmp (cmd_type, "MENU") == 0)
    {
	return get_block_no(a) ;
    }

  if (strcmp (cmd_type, "PROMPT") == 0)
    {
	return get_sio_ids("PROMPT") ;
	//A4GL_assertion(1,"EXIT PROMPT ?");
      //printed = 1;
    }

  if (printed == 0)
    {
	return get_block_no(a); // command_stack[a].block_no;
    }
return 0;
}


 
struct command *new_ext_cmd(enum e_block_cmd p_what) { //!
struct command *c;
int block_no=-1;
    switch (p_what) {
	case EBC_WHILE:  
		block_no=get_exit_loop("WHILE");
		break;
	case EBC_FOR:           // Exit FOR
		block_no=get_exit_loop("FOR");
		break;
	case EBC_INPUT:         // Exit INPUT
		block_no=get_exit_loop("INPUT");
		break;
	case EBC_FOREACH:       // Exit FOREACH
		block_no=get_exit_loop("FOREACH");
		break;
	case EBC_CONSTRUCT:     // Exit CONSTRUCT
		block_no=get_exit_loop("CONSTRUCT");
		break;
	case EBC_DISPLAY:       // Exit DISPLAY
		block_no=get_exit_loop("DISPLAY");
		break;
	case EBC_MENU:          // Exit MENU
		block_no=get_exit_loop("MENU");
		break;
	case EBC_PROMPT:        // Exit PROMPT
		block_no=get_exit_loop("PROMPT");
		break;
	case EBC_CASE:          // Exit CASE
		block_no=get_exit_loop("CASE");
		break;
   }
   A4GL_assertion(block_no<0, "Could not find block number");
   c=new_command(E_CMD_EXT_CMD);
   c->cmd_data.command_data_u.ext_cmd.what=p_what;
   c->cmd_data.command_data_u.ext_cmd.block_id=block_no;
   return c;
}
 
struct command *new_defer_cmd(e_defer p_what) { //!
struct command *c;
   c=new_command(E_CMD_DEFER_CMD);
   c->cmd_data.command_data_u.defer_cmd.what=p_what;
   return c;
}
 
struct command *new_code_cmd(char * p_contents) { //!
struct command *c;
   c=new_command(E_CMD_CODE_CMD);
   c->cmd_data.command_data_u.code_cmd.contents=strdup(p_contents);
   return c;
}
 
struct command *new_disable_menu_cmd(str_list* p_list) { //!
struct command *c;
   c=new_command(E_CMD_DISABLE_MENU_CMD);
   c->cmd_data.command_data_u.disable_menu_cmd.strlist=p_list;
   return c;
}
 
struct command *new_enable_menu_cmd(str_list* p_list) { //!
struct command *c;
   c=new_command(E_CMD_ENABLE_MENU_CMD);
   c->cmd_data.command_data_u.enable_menu_cmd.strlist=p_list;
   return c;
}
 
struct command *new_check_menu_cmd(str_list* p_list) { //!
struct command *c;
   c=new_command(E_CMD_CHECK_MENU_CMD);
   c->cmd_data.command_data_u.check_menu_cmd.strlist=p_list;
   return c;
}
 
struct command *new_uncheck_menu_cmd(str_list* p_list) { //!
struct command *c;
   c=new_command(E_CMD_UNCHECK_MENU_CMD);
   c->cmd_data.command_data_u.uncheck_menu_cmd.strlist=p_list;
   return c;
}
 
struct command *new_goto_cmd(char * p_label) { //!
struct command *c;
   c=new_command(E_CMD_GOTO_CMD);
	//A4GL_lint("Coding Standards: Use of GOTO is not recommended"); // COMMENENTED OUT
   c->cmd_data.command_data_u.goto_cmd.label=strdup(p_label);
   return c;
}
 
struct command *new_label_cmd(char * p_label) { //!
struct command *c;
   c=new_command(E_CMD_LABEL_CMD);
   c->cmd_data.command_data_u.label_cmd.label=strdup(p_label);
   return c;
}
 
 
 
 
struct command *new_sleep_cmd(expr_str* p_expr) { //!
struct command *c;
   c=new_command(E_CMD_SLEEP_CMD);
   c->cmd_data.command_data_u.sleep_cmd.sleep_expr=p_expr;
   return c;
}
 
struct command *new_move_cmd(expr_str * p_windowname,expr_str* p_x,expr_str* p_y,e_boolean relative) { //!
struct command *c;
   c=new_command(E_CMD_MOVE_CMD);
   c->cmd_data.command_data_u.move_cmd.windowname=p_windowname;
   c->cmd_data.command_data_u.move_cmd.x=p_x;
   c->cmd_data.command_data_u.move_cmd.y=p_y;
   c->cmd_data.command_data_u.move_cmd.relative=relative;
   return c;
}
 
struct command *new_show_menu_cmd(char * p_menuname,char * p_menuhandler,expr_str* p_mn_file) { //!
struct command *c;
   c=new_command(E_CMD_SHOW_MENU_CMD);
   c->cmd_data.command_data_u.show_menu_cmd.menuname=strdup(p_menuname);
   c->cmd_data.command_data_u.show_menu_cmd.menuhandler=strdup(p_menuhandler);
   c->cmd_data.command_data_u.show_menu_cmd.mn_file=p_mn_file;
   return c;
}
 
struct command *new_show_cmd(expr_str * p_windowname) { //!
struct command *c;
   c=new_command(E_CMD_SHOW_CMD);
   c->cmd_data.command_data_u.show_cmd.windowname=p_windowname;
   return c;
} //!
 
struct command *new_hide_cmd(expr_str * p_windowname) { //!
struct command *c;
   c=new_command(E_CMD_HIDE_CMD);
   c->cmd_data.command_data_u.hide_cmd.windowname=p_windowname;
   return c;
}
 
struct command *new_run_cmd(expr_str* p_run_string,e_boolean p_wait,enum run_mode p_run_mode,struct expr_str *p_returning) { //!
struct command *c;
   c=new_command(E_CMD_RUN_CMD);
   c->cmd_data.command_data_u.run_cmd.run_string=p_run_string;
   c->cmd_data.command_data_u.run_cmd.wait=p_wait;
   c->cmd_data.command_data_u.run_cmd.run_mode=p_run_mode;
   c->cmd_data.command_data_u.run_cmd.returning=p_returning;
	inc_var_assigned(p_returning);
   return c;
}
 
struct command *new_scroll_cmd(fh_field_list* p_srec,expr_str* p_val) { //!
struct command *c;
   c=new_command(E_CMD_SCROLL_CMD);
   c->cmd_data.command_data_u.scroll_cmd.srec=p_srec;
   c->cmd_data.command_data_u.scroll_cmd.val=p_val;
   return c;
}
 
struct command *new_exit_prog_cmd(expr_str* p_exit_val) { //!
struct command *c;
   c=new_command(E_CMD_EXIT_PROG_CMD);
   c->cmd_data.command_data_u.exit_prog_cmd.exit_val=p_exit_val;
   return c;
}
 

struct command *
new_prepare_cmd (expr_str *connid, expr_str *p_stmtid, expr_str * p_sql)
{				//!
  struct command *c;
	//char *xx;

  /* xx = strdup (A4GL_strip_quotes (p_stmtid)); */

  c = new_command (E_CMD_PREPARE_CMD);
  c->cmd_data.command_data_u.prepare_cmd.connid = connid;
  c->cmd_data.command_data_u.prepare_cmd.stmtid = p_stmtid;
  c->cmd_data.command_data_u.prepare_cmd.sql = p_sql;

  switch (p_sql->expr_type)
    {
	case ET_EXPR_VARIABLE_USAGE:
    case ET_E_V_OR_LIT_VAR:
      {
		/* //@FIXME - map_prepare...
	if (A4GL_has_pointer (p_sql->expr_str_u.var->varname, LAST_STRING_EXPR))
	  {
	    map_prepare (xx, A4GL_find_pointer (p_sql->expr_str_u.var->varname, LAST_STRING_EXPR));
	  }
	else
	  {
	    map_prepare (xx, p_sql->expr_str_u.var->varname);
	  }
		*/
      }
	break;

    case ET_E_V_OR_LIT_STRING:
      /* map_prepare (xx, A4GL_strip_quotes (p_sql->expr_str_u.s)); */
	break;
    case ET_E_V_OR_LIT_VAR_AS_STRING:
      {
	if (A4GL_has_pointer (p_sql->expr_str_u.sv, LAST_STRING_EXPR))
	  {
	    /* map_prepare (xx, A4GL_find_pointer (p_sql->expr_str_u.sv, LAST_STRING_EXPR)); */
	  }
	else
	  {
	    /* map_prepare (xx, p_sql->expr_str_u.sv); */
	  }
      }
	break;

    case ET_E_V_OR_LIT_IDENT:
      /* map_prepare (xx, A4GL_strip_quotes (p_sql->expr_str_u.si)); */
	break;

    default : 
		A4GL_assertion(1,"Invalid expression type for a prepare...");
    }

  return c;
}

struct command *new_init_cmd(struct expr_str_list* p_varlist,str_list *p_tablist) { //!
struct command *c;
//struct expr_str_list* p_varlist_expanded;
extern int nullbindcnt;
char errbuff[256];
int a;
   c=new_command(E_CMD_INIT_CMD);

	p_varlist=expand_variables_in_expr_str_list(p_varlist,1,0);

	for (a=0;a<p_varlist->list.list_len;a++) {
			ensure_variable(errbuff, p_varlist->list.list_val[a],0);
	}
   c->cmd_data.command_data_u.init_cmd.varlist=p_varlist;
   c->cmd_data.command_data_u.init_cmd.init_like_exprlist=0;

   if (p_tablist && p_tablist->str_list_entry.str_list_entry_len)  {
   		c->cmd_data.command_data_u.init_cmd.init_like_exprlist=malloc(sizeof(struct expr_str_list));
		 c->cmd_data.command_data_u.init_cmd.init_like_exprlist->list.list_len=p_tablist->str_list_entry.str_list_entry_len;
		 c->cmd_data.command_data_u.init_cmd.init_like_exprlist->list.list_val=malloc(sizeof(struct expr_str *)*p_tablist->str_list_entry.str_list_entry_len);
	
   	for (a=0;a<p_tablist->str_list_entry.str_list_entry_len;a++) {
		char buff[200];
		char *tab;
		char *col;
		char *p;
		expr_str *ptr=0;
		strcpy(buff, p_tablist->str_list_entry.str_list_entry_val[a]);
		tab=buff;
		p=strchr(buff,'.');
		if (p) {
			char *rstring;
			*p=0;
			col=p+1;
        		rstring=A4GLSQL_syscolval_expr(tab,col,"DEFAULT");
			if (rstring) {
			ptr=A4GL_new_literal_string(rstring);
			}
		}
		c->cmd_data.command_data_u.init_cmd.init_like_exprlist->list.list_val[a]=ptr;
	}

   }



   //p_varlist_expanded=malloc(sizeof(struct expr_str_list));
   //p_varlist_expanded->bindings.bindings_len=p_varlist->bindings.bindings_len;
   //p_varlist_expanded->bindings.bindings_val=malloc(sizeof(struct expr_str)* p_varlist_expanded->bindings.bindings_len); 

	//memcpy( p_varlist_expanded->bindings.bindings_val, p_varlist->bindings.bindings_val, sizeof(struct expr_str)* p_varlist_expanded->bindings.bindings_len); 
	//p_varlist_expanded->abind= p_varlist->abind;
	//p_varlist_expanded->type= p_varlist->type;
	//p_varlist_expanded->data= p_varlist->data;
	//start_bind('N',0);
	//p_varlist_expanded->type='n';
        //c->cmd_data.command_data_u.init_cmd.expanded_varlist=p_varlist_expanded;
        //expand_bind_g( c->cmd_data.command_data_u.init_cmd.expanded_varlist);

//.bindings_val, 'n', c->cmd_data.command_data_u.init_cmd.expanded_varlist->bindings.bindings_len,0);

	inc_var_assigned_from_binding_list(p_varlist);
   c->cmd_data.command_data_u.init_cmd.tablist=p_tablist;
   return c;
}
 
struct command *new_next_field_cmd(int p_rel,fh_field_entry* p_fieldname) {
struct command *c;
  int sio_id;

  sio_id=get_sio_id("ALLINPUT");

   c=new_command(E_CMD_NEXT_FIELD_CMD);
   c->cmd_data.command_data_u.next_field_cmd.rel=p_rel;
   c->cmd_data.command_data_u.next_field_cmd.nextfield=p_fieldname;
   c->cmd_data.command_data_u.next_field_cmd.sio=sio_id;

   return c;
}

struct command *new_at_term_cmd(char * p_funcname) { //!
struct command *c;
   c=new_command(E_CMD_AT_TERM_CMD);
   c->cmd_data.command_data_u.at_term_cmd.funcname=strdup(p_funcname);
   return c;
}
 
struct command *new_next_option_cmd(expr_str * p_menuoption) { //!
struct command *c;
   c=new_command(E_CMD_NEXT_OPTION_CMD);
   c->cmd_data.command_data_u.next_option_cmd.menuoption=p_menuoption;
   return c;
}
 
struct command *new_show_option_cmd(expr_str_list* p_menuoptions) { //!
struct command *c;
   c=new_command(E_CMD_SHOW_OPTION_CMD);
   c->cmd_data.command_data_u.show_option_cmd.menuoptions=p_menuoptions;
   return c;
}
 
struct command *new_hide_option_cmd(expr_str_list* p_menuoptions) { //!
struct command *c;
   c=new_command(E_CMD_HIDE_OPTION_CMD);
   c->cmd_data.command_data_u.hide_option_cmd.menuoptions=p_menuoptions;
   return c;
}
 
 
struct command *new_display_form_cmd(expr_str * p_formname,attrib *p_attributes) { //!
struct command *c;
   c=new_command(E_CMD_DISPLAY_FORM_CMD);
   c->cmd_data.command_data_u.display_form_cmd.formname=p_formname;
   c->cmd_data.command_data_u.display_form_cmd.attributes=p_attributes;
   return c;
}
 
struct command *new_options_cmd(manyoptions* p_options) { //!
struct command *c;
   c=new_command(E_CMD_OPTIONS_CMD);
   c->cmd_data.command_data_u.options_cmd.options=p_options;
   return c;
}

 
struct command *new_finish_cmd(char * p_repname,struct convert *p_c) { //!
struct command *c;
   c=new_command(E_CMD_FINISH_CMD);
   c->cmd_data.command_data_u.finish_cmd.repname=strdup(p_repname);
   c->cmd_data.command_data_u.finish_cmd.namespace=strdup(get_namespace(p_repname));
   c->cmd_data.command_data_u.finish_cmd.conv_c=p_c;
   return c;
}
 
struct command *new_start_cmd(char * p_repname,struct startrep *p_c) {
struct command *c;
   c=new_command(E_CMD_START_CMD);
   c->cmd_data.command_data_u.start_cmd.repname=strdup(p_repname);
   c->cmd_data.command_data_u.start_cmd.namespace=strdup(get_namespace(p_repname));
   c->cmd_data.command_data_u.start_cmd.sc_c=p_c;
   return c;
}
 
 
struct command *new_open_window_cmd(expr_str * p_windowname,expr_str* p_x,expr_str* p_y,windowtype *p_wt,struct attrib *p_attrib) { //!
struct command *c;
   c=new_command(E_CMD_OPEN_WINDOW_CMD);
   c->cmd_data.command_data_u.open_window_cmd.windowname=p_windowname;
   c->cmd_data.command_data_u.open_window_cmd.x=p_x;
   c->cmd_data.command_data_u.open_window_cmd.y=p_y;
   memcpy(&c->cmd_data.command_data_u.open_window_cmd.wt,p_wt,sizeof(windowtype));
   c->cmd_data.command_data_u.open_window_cmd.attributes=p_attrib;
   return c;
}
 
struct command *new_open_form_cmd(expr_str * p_formname,expr_str* p_filename) { //!
struct command *c;
   c=new_command(E_CMD_OPEN_FORM_CMD);
   c->cmd_data.command_data_u.open_form_cmd.formname=p_formname;
   c->cmd_data.command_data_u.open_form_cmd.form_filename=p_filename;
   return c;
}
 
struct command *new_open_form_gui_cmd(struct expr_str *p_form, struct expr_str *p_y, struct expr_str *p_x, struct expr_str *p_like, int p_disable, char* p_formhandler) {
struct command *c;
   c=new_command(E_CMD_OPEN_FORM_GUI_CMD);
   c->cmd_data.command_data_u.open_form_gui_cmd.form=p_form;
   c->cmd_data.command_data_u.open_form_gui_cmd.y=p_y;
   c->cmd_data.command_data_u.open_form_gui_cmd.x=p_x;
   c->cmd_data.command_data_u.open_form_gui_cmd.like=p_like;
   c->cmd_data.command_data_u.open_form_gui_cmd.disable=p_disable;
   c->cmd_data.command_data_u.open_form_gui_cmd.formhandler=strdup(p_formhandler);
   return c;
}
 
struct command *new_unload_cmd(expr_str *connid, expr_str * p_sql, struct expr_str *p_filename, struct expr_str *p_delimiter) {
struct command *c;
   c=new_command(E_CMD_UNLOAD_CMD);
   c->cmd_data.command_data_u.unload_cmd.connid=connid;
   c->cmd_data.command_data_u.unload_cmd.sql=p_sql;
   c->cmd_data.command_data_u.unload_cmd.filename=p_filename;
   c->cmd_data.command_data_u.unload_cmd.delimiter=p_delimiter;
   //c->cmd_data.command_data_u.unload_cmd.inbind=p_inbind;


//@  FIXME - inc_var_usage


   return c;
}
 
struct command *new_load_cmd(expr_str *connid, struct expr_str *p_filename, struct expr_str *p_delimiter, struct expr_str *p_sqlvar, char *p_tabname, str_list* p_collist) {
struct command *c;
   c=new_command(E_CMD_LOAD_CMD);
   c->cmd_data.command_data_u.load_cmd.connid=connid;
   c->cmd_data.command_data_u.load_cmd.filename=p_filename;
   c->cmd_data.command_data_u.load_cmd.delimiter=p_delimiter;
   c->cmd_data.command_data_u.load_cmd.sqlvar=p_sqlvar;
	if (p_tabname) {
   		c->cmd_data.command_data_u.load_cmd.tabname=strdup(p_tabname);
	} else {
   		c->cmd_data.command_data_u.load_cmd.tabname=0;
	}
   c->cmd_data.command_data_u.load_cmd.collist=p_collist;
   return c;
}
 
struct command *new_current_win_cmd(expr_str * p_windowname) { //!
struct command *c;
   c=new_command(E_CMD_CURRENT_WIN_CMD);
   c->cmd_data.command_data_u.current_win_cmd.windowname=p_windowname;
   return c;
}
 
 
struct command *new_open_cursor_cmd(expr_str *p_connid, expr_str * p_cursorname,struct expr_str_list *p_using_bind) { //!
struct command *c;
   c=new_command(E_CMD_OPEN_CURSOR_CMD);

   c->cmd_data.command_data_u.open_cursor_cmd.cursor_type='S';
	if (p_cursorname->expr_type==ET_EXPR_IDENTIFIER) {
		c->cmd_data.command_data_u.open_cursor_cmd.cursor_type=A4GL_cursor_type(p_cursorname);
	}
   c->cmd_data.command_data_u.open_cursor_cmd.cursorname=p_cursorname;
   c->cmd_data.command_data_u.open_cursor_cmd.using_bind=p_using_bind;
   c->cmd_data.command_data_u.open_cursor_cmd.connid=p_connid;
	inc_var_usage_from_binding_list(p_using_bind);
   return c;
}
 
 
struct command *new_declare_cmd(expr_str *p_connid,expr_str *p_cursorname, struct s_cur_def *p_declare_dets, e_boolean p_with_hold,e_boolean p_scroll,e_boolean p_isstmt) {
struct command *c;
int forupdate=0;
if (p_declare_dets->forUpdate && strlen(p_declare_dets->forUpdate)) {
	forupdate=1;
}

if (p_scroll==EB_TRUE && forupdate) {
	a4gl_yyerror("Can't have FOR UPDATE on a SCROLL cursor");
	return 0;
}


   c=new_command(E_CMD_DECLARE_CMD);
   c->cmd_data.command_data_u.declare_cmd.connid=p_connid;
   c->cmd_data.command_data_u.declare_cmd.cursorname=p_cursorname;
   c->cmd_data.command_data_u.declare_cmd.declare_dets=A4GL_memdup(p_declare_dets, sizeof(struct s_cur_def));
   c->cmd_data.command_data_u.declare_cmd.with_hold=p_with_hold;
   c->cmd_data.command_data_u.declare_cmd.scroll=p_scroll;
   c->cmd_data.command_data_u.declare_cmd.isstmt=p_isstmt;
   c->cmd_data.command_data_u.declare_cmd.cursor_type='S';
   if (p_cursorname->expr_type==ET_EXPR_IDENTIFIER) {
		c->cmd_data.command_data_u.declare_cmd.cursor_type=A4GL_cursor_type(p_cursorname);
   }

//@  FIXME - inc_var_usage
   

   return c;
}


 
 
 
struct command *new_term_rep_cmd(char * p_reportname) { //!
struct command *c;
   c=new_command(E_CMD_TERM_REP_CMD);
   c->cmd_data.command_data_u.term_rep_cmd.repname=strdup(p_reportname);
   c->cmd_data.command_data_u.term_rep_cmd.namespace=strdup(get_namespace(p_reportname));
   return c;
}
 
struct command *new_sql_cmd(expr_str *p_connid, char * p_sql) {
struct command *c;
   c=new_command(E_CMD_SQL_CMD);
   c->cmd_data.command_data_u.sql_cmd.connid=p_connid;
   c->cmd_data.command_data_u.sql_cmd.sql=strdup(p_sql);
   return c;
}
 
/*
struct command *new_sql_bound_cmd(char *p_connid, char * p_sql) {
struct command *c;
   c=new_command(E_CMD_SQL_BOUND_CMD);
   c->cmd_data.command_data_u.sql_bound_cmd.connid=p_connid;
   c->cmd_data.command_data_u.sql_bound_cmd.sql=strdup(p_sql);
   c->cmd_data.command_data_u.sql_bound_cmd.inbind=copy_togenbind('i');
   return c;
}
*/
 


struct command *new_select_cmd(expr_str *p_connid, struct s_select * p_sql,char *forupdate) {
struct command *c;
   c=new_command(E_CMD_SELECT_CMD);
   c->cmd_data.command_data_u.select_cmd.connid=p_connid;
   c->cmd_data.command_data_u.select_cmd.sql=p_sql;
   c->cmd_data.command_data_u.select_cmd.forupdate=strdup(forupdate);
//@  FIXME - inc_var_usage
   return c;
}

struct command *new_let_cmd(expr_str_list* p_vars,expr_str_list *p_vals) {
struct command *c;
int a;
   	c=new_command(E_CMD_LET_CMD);
   	c->cmd_data.command_data_u.let_cmd.vars=p_vars;
	if (c->cmd_data.command_data_u.let_cmd.vars->list.list_len>1) {
		p_vals=make_fgl_expr_list(p_vals);
		if (p_vars->list.list_len!=p_vals->list.list_len) {
			yylineno=c->lineno;
			a4gl_yyerror("Number of variables does not match number of values");
		}
	}
   	c->cmd_data.command_data_u.let_cmd.vals=p_vals;

   inc_var_assigned_from_binding_list(p_vars);

   return c;
}

struct command *new_case_cmd(expr_str* p_case_expr,struct whens *p_whens,commands *p_otherwise) {
struct command *c;
   c=new_command(E_CMD_CASE_CMD);
   c->cmd_data.command_data_u.case_cmd.case_expr=p_case_expr;
   c->cmd_data.command_data_u.case_cmd.whens=p_whens;
   c->cmd_data.command_data_u.case_cmd.otherwise=p_otherwise;
   return c;
}

struct command *new_validate_cmd(expr_str_list* p_list, str_list* p_tablist) {
struct command *c;
int a;
int cnt;
   c=new_command(E_CMD_VALIDATE_CMD);
	
   c->cmd_data.command_data_u.validate_cmd.list=expand_variables_in_expr_str_list(p_list, 1,1);
   c->cmd_data.command_data_u.validate_cmd.tablist=p_tablist;

   c->cmd_data.command_data_u.validate_cmd.validate_list=A4GL_new_ptr_list(0);
   cnt=get_validate_list_cnt();
   if (cnt!=p_list->list.list_len) {
          set_yytext("");
          a4gl_yyerror ("Mismatch in number of variables and number of columns");
          return 0;
   }

	for (a=0;a<p_list->list.list_len;a++) {
		A4GL_new_append_ptr_list(c->cmd_data.command_data_u.validate_cmd.validate_list, A4GL_new_expr_list_with_list(A4GL_get_validate_expr(a)));
	}


   return c;
}

struct command *new_display_b_n_cmd(expr_str_list* p_vars,attrib *p_attributes) {
struct command *c;
   c=new_command(E_CMD_DISPLAY_B_N_CMD);
   c->cmd_data.command_data_u.display_b_n_cmd.vars=p_vars;
   c->cmd_data.command_data_u.display_b_n_cmd.attributes=p_attributes;
   return c;
}

struct command *new_foreach_cmd(expr_str *p_connid, expr_str * p_cursorname,expr_str_list* p_inputvals,expr_str_list* p_outputvals,commands *p_cmds) {
struct command *c;
   c=new_command(E_CMD_FOREACH_CMD);
   c->cmd_data.command_data_u.foreach_cmd.cursorname=p_cursorname;
   c->cmd_data.command_data_u.foreach_cmd.inputvals=p_inputvals;
   c->cmd_data.command_data_u.foreach_cmd.outputvals=p_outputvals;
   c->cmd_data.command_data_u.foreach_cmd.foreach_commands=p_cmds;
   c->cmd_data.command_data_u.foreach_cmd.block_id=get_block_no(A4GL_get_ccnt());
   c->cmd_data.command_data_u.foreach_cmd.connid=p_connid;
   return c;
}

struct command *new_connect_cmd(struct expr_str *p_dbname,struct expr_str *p_conn_name,struct expr_str *p_username,struct expr_str *p_password) {
struct command *c;
   c=new_command(E_CMD_CONNECT_CMD);
   c->cmd_data.command_data_u.connect_cmd.conn_dbname=p_dbname;
   c->cmd_data.command_data_u.connect_cmd.conn_name=p_conn_name;
   c->cmd_data.command_data_u.connect_cmd.username=p_username;
   c->cmd_data.command_data_u.connect_cmd.password=p_password;
   return c;
}
























struct command *new_input_cmd(expr_str_list* p_variables,fh_field_list* p_field_list,struct on_events* p_events,struct attrib *p_attrib,e_boolean p_without_defaults,int p_helpno,int p_sio) {
struct command *c;
   c=new_command(E_CMD_INPUT_CMD);
	p_variables=expand_variables_in_expr_str_list(p_variables,1,1);
   c->cmd_data.command_data_u.input_cmd.variables=p_variables;
   c->cmd_data.command_data_u.input_cmd.events=p_events;
   c->cmd_data.command_data_u.input_cmd.attributes=p_attrib;
   c->cmd_data.command_data_u.input_cmd.without_defaults=p_without_defaults;
	if (p_field_list==0) {
		int a;
		struct fh_field_list *fl;
		struct fh_field_entry *fe=0;
		struct variable_usage *vu;
		c->cmd_data.command_data_u.input_cmd.by_name=EB_TRUE;
		// we need to generate our field list...
		fl=new_field_list();
		for (a=0;a<p_variables->list.list_len;a++) {
			char *colname;
			struct expr_str *f;
			A4GL_assertion(p_variables->list.list_val[a]->expr_type!=ET_EXPR_VARIABLE_USAGE,"Expecting a variable");
			vu=p_variables->list.list_val[a]->expr_str_u.expr_variable_usage;
			while (vu->next) vu=vu->next;
			colname=vu->variable_name;
			fe= new_field_entry(A4GL_new_expr_simple_string(colname,ET_EXPR_IDENTIFIER), NULL,1);
			append_field_to_list(fl,fe);
		}
		p_field_list=fl;
		
	} else {
		c->cmd_data.command_data_u.input_cmd.by_name=EB_FALSE;
	}
   c->cmd_data.command_data_u.input_cmd.field_list=p_field_list;
   c->cmd_data.command_data_u.input_cmd.helpno=p_helpno;
   c->cmd_data.command_data_u.input_cmd.sio=p_sio;
   c->cmd_data.command_data_u.input_cmd.blockid=0;
   return c;
}


struct command *new_construct_cmd(e_boolean byname, expr_str* p_constr_var,cons_list* p_columns,fh_field_list* p_list,struct on_events* p_events,struct attrib *p_attrib,e_boolean p_without_defaults,int p_helpno,int p_sio) {

struct command *c;
   c=new_command(E_CMD_CONSTRUCT_CMD);
   c->cmd_data.command_data_u.construct_cmd.by_name=byname;
   c->cmd_data.command_data_u.construct_cmd.constr_var=p_constr_var;
   c->cmd_data.command_data_u.construct_cmd.con_columns=p_columns;

        if (p_list==0) {
                int a;
                struct fh_field_list *fl;
                struct fh_field_entry *fe=0;
                struct variable_usage *vu;
                c->cmd_data.command_data_u.input_cmd.by_name=EB_TRUE;
                // we need to generate our field list...
                fl=new_field_list();
                for (a=0;a<p_columns->list.list_len;a++) {
                        fe= new_field_entry(A4GL_new_expr_simple_string(p_columns->list.list_val[a]->colname,ET_EXPR_IDENTIFIER), NULL,1);
                        append_field_to_list(fl,fe);
                }
                p_list=fl;
	}
   c->cmd_data.command_data_u.construct_cmd.list=p_list;
   c->cmd_data.command_data_u.construct_cmd.events=p_events;
   c->cmd_data.command_data_u.construct_cmd.attributes=p_attrib;
   c->cmd_data.command_data_u.construct_cmd.without_defaults=p_without_defaults;
   c->cmd_data.command_data_u.construct_cmd.helpno=p_helpno;
   c->cmd_data.command_data_u.construct_cmd.sio=p_sio;
   c->cmd_data.command_data_u.construct_cmd.blockid=get_sio_ids("CONSTRUCT");
   return c;
}


static int find_slice(expr_str *arr, char *s, int w) {
struct variable *v;
int dtype=0;
int size=0;
int is_array=0;
char buff[256];
char *ptr;
int a;
char scope;
char errbuff[256];
if (s==0) return -1;
if (strlen(s)==0) return -1;

strcpy(buff,s);
ptr=strchr(buff,':');
A4GL_assertion(ptr==0, "No thru separator");
*ptr=0;
ptr++;

if (w==0) ptr=buff; // start
// otherwise - we want the end portion...
A4GL_assertion(arr->expr_type!=ET_EXPR_VARIABLE_USAGE,"Unexpected expression type");
v=find_variable_vu_ptr(errbuff, arr->expr_str_u.expr_variable_usage, &scope,0);
if (v==0) {
        a4gl_yyerror(errbuff);
        return -1;
}
//find_variable(av, &dtype,&size,&is_array, &v );
if (!v->arr_subscripts.arr_subscripts_len) {
        a4gl_yyerror("Not an array");
        return -1;
}

if (v->var_data.variable_type!=VARIABLE_TYPE_RECORD) {
        a4gl_yyerror("Not an array of record");
        return -1;
}

for (a=0;a<v->var_data.variable_data_u.v_record.variables.variables_len;a++) {
        if (A4GL_aubit_strcasecmp(v->var_data.variable_data_u.v_record.variables.variables_val[a]->names.names.names_val[0].name, ptr)==0) return a;
}

// Not found.
return -1;
}


struct command *new_input_array_cmd(struct expr_str* p_srec,struct expr_str * p_arrayname,struct attrib *p_attrib,struct on_events* p_events,e_boolean p_without_defaults,int p_helpno,int p_sio,int p_blk,char *slice) {
struct command *c;
   c=new_command(E_CMD_INPUT_ARRAY_CMD);
   c->cmd_data.command_data_u.input_array_cmd.srec=p_srec;
   c->cmd_data.command_data_u.input_array_cmd.arrayname=p_arrayname;
   c->cmd_data.command_data_u.input_array_cmd.attributes=p_attrib;
   c->cmd_data.command_data_u.input_array_cmd.events=p_events;
   c->cmd_data.command_data_u.input_array_cmd.without_defaults=p_without_defaults;
   c->cmd_data.command_data_u.input_array_cmd.helpno=p_helpno;
   c->cmd_data.command_data_u.input_array_cmd.sio=p_sio;
   c->cmd_data.command_data_u.input_array_cmd.blockid= p_blk;
   c->cmd_data.command_data_u.input_array_cmd.slice=strdup(slice);
   c->cmd_data.command_data_u.input_array_cmd.slice_start=find_slice(p_arrayname, slice,0);
   c->cmd_data.command_data_u.input_array_cmd.slice_end=find_slice(p_arrayname, slice,1);
   return c;
}

 
struct command *new_sql_transact_cmd(expr_str * connid, int p_trans) {
struct command *c;
   c=new_command(E_CMD_SQL_TRANSACT_CMD);
   c->cmd_data.command_data_u.sql_transact_cmd.connid=connid;
   c->cmd_data.command_data_u.sql_transact_cmd.trans=p_trans;
   return c;
}
 
struct command *new_set_database_cmd(expr_str* p_dbname,e_boolean p_exclusive) {
struct command *c;
   c=new_command(E_CMD_SET_DATABASE_CMD);
   c->cmd_data.command_data_u.set_database_cmd.set_dbname=p_dbname;
   c->cmd_data.command_data_u.set_database_cmd.exclusive_mode=p_exclusive;
   return c;
}
 
struct command *new_whenever_cmd(int p_whencode,char * p_whento) {
struct command *c;

static int local_last_whencode[10]={-1,-1,-1,-1,-1,-1,-1};
static char *local_last_whento[10]={0,0,0,0,0,0,0,0,0,0};
int type;

//printf("new_whenever_cmd\n");
if (p_whencode==-1 && p_whento==0) {
	int a;
	for (a=0;a<10;a++) {
		local_last_whencode[a]=-1;
		local_last_whento[a]=0;
	} 
	return 0;
}

type=p_whencode>>4;
if (local_last_whencode[type]==-1) {
	local_last_whencode[type]=p_whencode;
	local_last_whento[type]=p_whento;
} else {

	if (local_last_whencode[type]==p_whencode) {
		if (local_last_whento[type]==0 && p_whento==0) {
			//A4GL_lint("Coding Standards: Resetting WHENEVER ... to same settings"); // COMMENTED OUT
		} 
		if (local_last_whento[type]!=0 && p_whento!=0) {
			if (strcmp(local_last_whento[type],p_whento)==0) {
				//A4GL_lint("Coding Standards: Resetting WHENEVER ... to same settings"); // COMMENTED OUT
			}
		}
	}
}


   c=new_command(E_CMD_WHENEVER_CMD);
   c->cmd_data.command_data_u.whenever_cmd.whencode=p_whencode;
   c->cmd_data.command_data_u.whenever_cmd.whento=strdup(p_whento);
   return c;
}
 
 
struct command *new_skip_cmd(int p_lines) { //!
struct command *c;
   c=new_command(E_CMD_SKIP_CMD);
   c->cmd_data.command_data_u.skip_cmd.lines=p_lines;
   return c;
}
 
struct command *new_skip_by_cmd(double p_lines) { //!
struct command *c;
   c=new_command(E_CMD_SKIP_BY_CMD);
   c->cmd_data.command_data_u.skip_by_cmd.lines=p_lines;
   return c;
}
 
struct command *new_skip_to_cmd(double p_lines) { //!
struct command *c;
   c=new_command(E_CMD_SKIP_TO_CMD);
   c->cmd_data.command_data_u.skip_to_cmd.lines=p_lines;
   return c;
}
 
struct command *new_need_cmd(expr_str* p_expr) { //!
struct command *c;
   c=new_command(E_CMD_NEED_CMD);
   c->cmd_data.command_data_u.need_cmd.expr=p_expr;
   return c;
}
 
 
struct command *new_print_file_cmd(struct expr_str *p_filename,e_boolean p_semi) { //!
struct command *c;
   c=new_command(E_CMD_PRINT_FILE_CMD);
   c->cmd_data.command_data_u.print_file_cmd.filename=p_filename;
   c->cmd_data.command_data_u.print_file_cmd.semi=p_semi;
   return c;
}
 
struct command *new_print_img_cmd(struct expr_str * p_var,expr_str* p_scale_x,expr_str* p_scale_y,char * p_img_type,e_boolean p_semi) { //!
struct command *c;
   c=new_command(E_CMD_PRINT_IMG_CMD);
   c->cmd_data.command_data_u.print_img_cmd.var=p_var;
   c->cmd_data.command_data_u.print_img_cmd.scale_x=p_scale_x;
   c->cmd_data.command_data_u.print_img_cmd.scale_y=p_scale_y;
   c->cmd_data.command_data_u.print_img_cmd.img_type=strdup(p_img_type);
   c->cmd_data.command_data_u.print_img_cmd.semi=p_semi;
   return c;
}
 
struct command *new_pause_cmd(struct expr_str * p_pause_msg) { //!
struct command *c;
   c=new_command(E_CMD_PAUSE_CMD);
   c->cmd_data.command_data_u.pause_cmd.pause_msg=p_pause_msg;
   return c;
}
 
 /*
struct command *new_open_session_cmd(expr_str * p_connid,struct expr_str* p_db,user_details* p_userdets) {
struct command *c;
   c=new_command(E_CMD_OPEN_SESSION_CMD);
   c->cmd_data.command_data_u.open_session_cmd.connid=p_connid;
   c->cmd_data.command_data_u.open_session_cmd.db=p_db;
   c->cmd_data.command_data_u.open_session_cmd.userdets=p_userdets;
   return c;
}
*/

 
struct command *new_msg_box_cmd(struct expr_str_list *msg, struct expr_str_list *caption, int icon, int buttons, int default_button, int disable, struct expr_str *returning) {
struct command *c;
   c=new_command(E_CMD_MSG_BOX_CMD);
   c->cmd_data.command_data_u.msg_box_cmd.msg=msg;
   c->cmd_data.command_data_u.msg_box_cmd.caption=caption;
   c->cmd_data.command_data_u.msg_box_cmd.icon=icon;
   c->cmd_data.command_data_u.msg_box_cmd.buttons=buttons;
   c->cmd_data.command_data_u.msg_box_cmd.default_button=default_button;
   c->cmd_data.command_data_u.msg_box_cmd.disable=disable;
   c->cmd_data.command_data_u.msg_box_cmd.returning=returning;
   return c;
}
 
struct command *new_next_form_cmd(char *form,char *field) {
struct command *c;
   c=new_command(E_CMD_NEXT_FORM_CMD);
   c->cmd_data.command_data_u.next_form_cmd.form=strdup(form);
   c->cmd_data.command_data_u.next_form_cmd.field=strdup(field);
   return c;
}
 
struct command *new_open_statusbox_cmd ( str name, expr_str *at_x, expr_str *at_y, expr_str *sz_width, expr_str *sz_height) {
struct command *c;
   c=new_command(E_CMD_OPEN_STATUSBOX_CMD);
   c->cmd_data.command_data_u.open_statusbox_cmd.name=strdup(name);
   c->cmd_data.command_data_u.open_statusbox_cmd.at_x=at_x;
   c->cmd_data.command_data_u.open_statusbox_cmd.at_y=at_y;
   c->cmd_data.command_data_u.open_statusbox_cmd.sz_width=sz_width;
   c->cmd_data.command_data_u.open_statusbox_cmd.sz_height=sz_height;
   return c;
}
 
 
 
struct command *new_free_rep_cmd(char * p_repname) {
struct command *c;
   c=new_command(E_CMD_FREE_REP_CMD);
   c->cmd_data.command_data_u.free_rep_cmd.repname=strdup(p_repname);
   c->cmd_data.command_data_u.free_rep_cmd.namespace=strdup(get_namespace(p_repname));
   return c;
}

/************************************/

struct command *new_execute_immediate_cmd(expr_str *connid, struct expr_str *p_sql_stmt) {
struct command *c;
   c=new_command(E_CMD_EXECUTE_IMMEDIATE_CMD);
   c->cmd_data.command_data_u.execute_immediate_cmd.connid=connid;
   c->cmd_data.command_data_u.execute_immediate_cmd.sql_stmt=p_sql_stmt;
   return c;
}
 
struct command *new_flush_cmd(expr_str *connid, expr_str *p_cursorname) {
struct command *c;
   c=new_command(E_CMD_FLUSH_CMD);
   c->cmd_data.command_data_u.flush_cmd.connid=connid;
   c->cmd_data.command_data_u.flush_cmd.cursorname=p_cursorname;
   return c;
}


struct command *new_start_rpc_cmd(struct expr_str *p_valid_port,funcname_list p_remote_func_list) {
struct command *c;
int a;
int b;
   c=new_command(E_CMD_START_RPC_CMD);
   c->cmd_data.command_data_u.start_rpc_cmd.valid_port=p_valid_port;
   c->cmd_data.command_data_u.start_rpc_cmd.remote_func_list=p_remote_func_list;
	a=p_remote_func_list.name.name_len;

	 c->cmd_data.command_data_u.start_rpc_cmd.remote_func_list.namespaces.namespaces_len=a;
	 c->cmd_data.command_data_u.start_rpc_cmd.remote_func_list.namespaces.namespaces_val=malloc(sizeof(char*)*a);
	for (b=0;b<a;b++) {
		c->cmd_data.command_data_u.start_rpc_cmd.remote_func_list.namespaces.namespaces_val[b]=strdup(get_namespace( c->cmd_data.command_data_u.start_rpc_cmd.remote_func_list.name.name_val[b]));
	}
   return c;
}


struct command *new_for_cmd(expr_str*var, expr_str* p_start,expr_str* p_end,expr_str* p_step,commands *p_commands,int lineno) { //!
struct command *c;
   c=new_command(E_CMD_FOR_CMD);

   c->cmd_data.command_data_u.for_cmd.var=var;
   c->cmd_data.command_data_u.for_cmd.start=p_start;
   c->cmd_data.command_data_u.for_cmd.end=p_end;
   c->cmd_data.command_data_u.for_cmd.step=p_step;
   c->cmd_data.command_data_u.for_cmd.for_commands=p_commands;
   c->cmd_data.command_data_u.for_cmd.block_id=get_block_no(A4GL_get_ccnt());
   c->lineno=lineno;
	c->colno=0;
   return c;
}




struct command *new_print_cmd(expr_str_list *p_print_expr,e_boolean p_semi) {
struct command *c;
   c=new_command(E_CMD_PRINT_CMD);
   c->cmd_data.command_data_u.print_cmd.print_expr=p_print_expr;
   c->cmd_data.command_data_u.print_cmd.semi=p_semi;
   return c;
}


struct command *new_error_cmd(expr_str_list* p_expr_list,e_boolean p_wait_for_key,attrib *p_attributes) { //!
struct command *c;
   c=new_command(E_CMD_ERROR_CMD);
   c->cmd_data.command_data_u.error_cmd.expr_list=p_expr_list;
   c->cmd_data.command_data_u.error_cmd.wait_for_key=p_wait_for_key;
   c->cmd_data.command_data_u.error_cmd.attributes=p_attributes;
   return c;
}


struct command *new_put_cmd(expr_str * p_connid,expr_str *p_cursorname,struct expr_str_list* p_list) {
struct command *c;
   c=new_command(E_CMD_PUT_CMD);
   c->cmd_data.command_data_u.put_cmd.connid=p_connid;
   c->cmd_data.command_data_u.put_cmd.cursorname=p_cursorname;
   c->cmd_data.command_data_u.put_cmd.values=p_list;
	 inc_var_usage_from_binding_list(p_list);
   return c;
}

struct command *new_while_cmd(expr_str* p_expr,commands *p_commands) {
struct command *c;
   c=new_command(E_CMD_WHILE_CMD);
   c->cmd_data.command_data_u.while_cmd.while_expr=p_expr;
   c->cmd_data.command_data_u.while_cmd.while_commands=p_commands;
   c->cmd_data.command_data_u.while_cmd.block_id=get_block_no(A4GL_get_ccnt());
   return c;
}





struct command *new_locate_cmd(expr_str_list* p_variables,locate_pos *p_where) {
struct command *c;
int a;
   c=new_command(E_CMD_LOCATE_CMD);
   for (a=0;a<p_variables->list.list_len;a++) {
		if (p_variables->list.list_val[a]->expr_type!=ET_EXPR_VARIABLE_USAGE) {
			a4gl_yyerror("Not a variable");
			return 0;
		}
		switch (p_variables->list.list_val[a]->expr_str_u.expr_variable_usage->datatype&DTYPE_MASK) {
			case DTYPE_TEXT:
			case DTYPE_BYTE: break;
			default:
				//  Its not a byte or a text...
				set_yytext(expr_as_string_when_possible(p_variables->list.list_val[a]));
				a4gl_yyerror("Only TEXT and BYTE variables can be located");
			return 0;
		}
	}

   c->cmd_data.command_data_u.locate_cmd.variables=p_variables;
   memcpy(&c->cmd_data.command_data_u.locate_cmd.where, p_where,sizeof(locate_pos));
   return c;
}

struct command *new_message_cmd(expr_str_list *p_expr,attrib *p_attributes,e_boolean p_wait) {
struct command *c;
   c=new_command(E_CMD_MESSAGE_CMD);
   c->cmd_data.command_data_u.message_cmd.message_expr=p_expr;
   c->cmd_data.command_data_u.message_cmd.attributes=p_attributes;
   c->cmd_data.command_data_u.message_cmd.wait=p_wait;
   return c;
}

struct command *new_return_cmd(expr_str_list *p_retvals) {
struct command *c;
   c=new_command(E_CMD_RETURN_CMD);
   c->cmd_data.command_data_u.return_cmd.retvals=p_retvals;
   return c;
}

struct command *new_execute_cmd(expr_str *p_connid, expr_str_list* p_inbind,expr_str_list* p_outbind,expr_str * p_sql_stmtid) {
struct command *c;
   c=new_command(E_CMD_EXECUTE_CMD);
   c->cmd_data.command_data_u.execute_cmd.inbind=p_inbind;
   inc_var_usage_from_binding_list(p_inbind);
   c->cmd_data.command_data_u.execute_cmd.outbind=p_outbind;
   inc_var_assigned_from_binding_list(p_outbind);
   c->cmd_data.command_data_u.execute_cmd.sql_stmtid=p_sql_stmtid;
   c->cmd_data.command_data_u.execute_cmd.connid=p_connid;
   return c;
}

struct command *new_sql_block_cmd(expr_str *p_connid, expr_str_list* p_list) {
struct command *c;
   c=new_command(E_CMD_SQL_BLOCK_CMD);
   c->cmd_data.command_data_u.sql_block_cmd.list=p_list;
   c->cmd_data.command_data_u.sql_block_cmd.connid=p_connid;

//@  FIXME - inc_var_usage

	//inc_var_usage_from_binding_list(p_inbind);
	//inc_var_assigned_from_binding_list(p_outbind);
   return c;
}

struct command *new_if_cmd(if_conds *p_truths,commands *p_whenfalse,int else_lineno, int lineno) {
struct command *c;
   c=new_command(E_CMD_IF_CMD);
   memcpy(&c->cmd_data.command_data_u.if_cmd.truths,p_truths,sizeof(if_conds));
   c->cmd_data.command_data_u.if_cmd.whenfalse=p_whenfalse;
   c->cmd_data.command_data_u.if_cmd.lineno=lineno;
   c->cmd_data.command_data_u.if_cmd.else_lineno=else_lineno;
   return c;
}

struct command *new_enable_cmd (struct fh_field_list *srec) {
struct command *c;
	 c=new_command(E_CMD_DISABLE_FORM_CMD);
	c->cmd_data.command_data_u.enable_cmd.srec=srec;
   return c;
}
struct command *new_enable_form_cmd ( struct expr_str* formname, struct fh_field_list *srec) {
struct command *c;
	 c=new_command(E_CMD_DISABLE_FORM_CMD);
	c->cmd_data.command_data_u.enable_form_cmd.formname=formname;
	c->cmd_data.command_data_u.enable_form_cmd.srec=srec;
   return c;
}
struct command *new_disable_cmd ( struct fh_field_list *srec ) {
struct command *c;
	 c=new_command(E_CMD_DISABLE_FORM_CMD);
	c->cmd_data.command_data_u.disable_cmd.srec=srec;
   return c;
}
struct command *new_disable_form_cmd ( struct expr_str* formname, struct fh_field_list *srec ) {
struct command *c;
	 c=new_command(E_CMD_DISABLE_FORM_CMD);
	c->cmd_data.command_data_u.disable_form_cmd.formname=formname;
	c->cmd_data.command_data_u.disable_form_cmd.srec=srec;
   return c;
}

struct command *new_call_cmd(expr_str* p_fcall,expr_str_list* p_returning) {
struct command *c;
   	c=new_command(E_CMD_CALL_CMD);
   	c->cmd_data.command_data_u.call_cmd.fcall=p_fcall;

	//if (p_fcall->expr_str_u.expr_function_call->parameters) {
		//p_fcall->expr_str_u.expr_function_call->parameters=A4GL_rationalize_list(p_fcall->expr_str_u.expr_function_call->parameters);
	//}

   c->cmd_data.command_data_u.call_cmd.returning=p_returning;

   //inc_var_assigned_from_binding_list(p_returning);
   add_to_call_list_by_call(c);
   return c;
}

struct command *new_pdf_call_cmd(expr_str* p_fcall,expr_str_list* p_returning) {
struct command *c;
   c=new_command(E_CMD_PDF_CALL_CMD);
   c->cmd_data.command_data_u.pdf_call_cmd.fcall=p_fcall;
   c->cmd_data.command_data_u.pdf_call_cmd.returning=p_returning;
	inc_var_assigned_from_binding_list(p_returning);
   return c;
}



struct command *new_display_cmd(expr_str_list* p_exprs,dt_display *p_where,attrib *p_attributes,e_boolean byName) {
struct command *c;
   c=new_command(E_CMD_DISPLAY_CMD);
   c->cmd_data.command_data_u.display_cmd.exprs=p_exprs;
   c->cmd_data.command_data_u.display_cmd.where=p_where;
   c->cmd_data.command_data_u.display_cmd.attributes=p_attributes;
   c->cmd_data.command_data_u.display_cmd.by_name=byName;
   return c;
}


struct on_event *new_event(e_event event_type, void *data, commands *cmds,int lineno) {
	on_event *oe;
	oe=malloc(sizeof(on_event));
	oe->evt_data.event_type=event_type;
	oe->lineno=lineno;
	oe->colno=0;

	switch(event_type) {
        case EVENT_BEF_ROW: 
        case EVENT_AFT_ROW: 
        case EVENT_AFTER_DISPLAY: 
        case EVENT_BEFORE_DISPLAY: 
        case EVENT_AFTER_CONSTRUCT:
        case EVENT_BEFORE_CONSTRUCT:
        case EVENT_BEFORE_MENU: 

        case EVENT_BEFORE_DELETE:
        case EVENT_AFTER_DELETE:
        case EVENT_BEFORE_INSERT: 
        case EVENT_AFTER_INSERT: 
        case EVENT_BEFORE_INSERT_DELETE: 
        case EVENT_AFTER_INSERT_DELETE: 
        case EVENT_AFTER_INPUT: 
	case EVENT_ANYKEY_PRESS:
	case EVENT_AFTER_INP_CLEAN:
	case EVENT_BEFORE_OPEN_FORM:
        case EVENT_BEFORE_INPUT: break; // no extra data...


        case EVENT_ON_IDLE: 		oe->evt_data.event_data_u.idle_n=(int) data; break;

        case EVENT_ON_INTERVAL:		oe->evt_data.event_data_u.interval_n=(int) data; break;
        case EVENT_ON_TIME: 		oe->evt_data.event_data_u.time_n=(int) data; break;

        case EVENT_KEY_PRESS: 		oe->evt_data.event_data_u.key=(str_list *)data; break;
        case EVENT_ON_ACTION:	 	oe->evt_data.event_data_u.on_action=(char *)data; break;

        case EVENT_ON:	 	oe->evt_data.event_data_u.on=(str_list *)data; break;
        case EVENT_BEFORE:	 	oe->evt_data.event_data_u.before=(str_list *)data; break;
        case EVENT_AFTER:	 	oe->evt_data.event_data_u.after=(str_list *)data; break;

        case EVENT_BEFORE_FIELD:	oe->evt_data.event_data_u.before_field=(fh_field_list *)data; break;
        case EVENT_AFTER_FIELD: 	oe->evt_data.event_data_u.after_field=(fh_field_list *)data; break;
        case EVENT_MENU_COMMAND: 	oe->evt_data.event_data_u.mnoption  =(menuoption *)data; break;

	default : A4GL_assertion(1,"Unexpected event");
	}
	
	oe->on_event_commands=cmds;
	return oe;
}


struct menuoption *new_menu_option(str_list  *keys, struct expr_str *mnoption, struct expr_str *mndescription, int helpno) {
	menuoption *m;
	m=malloc(sizeof(menuoption));
	m->keys=keys;
	m->helpno=helpno;
	m->shortname=mnoption;
	m->longname=mndescription;
	return m;
}


struct command *new_prompt_cmd(expr_str_list* p_prompt_str ,struct attrib* p_prompt_str_attrib,struct attrib* p_prompt_fld_attrib,e_boolean p_for_char,expr_str* p_promptvar,int p_helpno,struct on_events* p_events,int p_sio,int p_blk) {
struct command *c;
char errbuff[256];
   c=new_command(E_CMD_PROMPT_CMD);
	if (!ensure_variable(errbuff, p_promptvar,1)) {
		a4gl_yyerror(errbuff);
		return 0;
	}
   c->cmd_data.command_data_u.prompt_cmd.prompt_str=p_prompt_str;
   c->cmd_data.command_data_u.prompt_cmd.prompt_str_attrib=p_prompt_str_attrib;
   c->cmd_data.command_data_u.prompt_cmd.prompt_fld_attrib=p_prompt_fld_attrib;
   c->cmd_data.command_data_u.prompt_cmd.for_char=p_for_char;
   c->cmd_data.command_data_u.prompt_cmd.promptvar=p_promptvar;
   c->cmd_data.command_data_u.prompt_cmd.helpno=p_helpno;
   c->cmd_data.command_data_u.prompt_cmd.events=p_events;
   c->cmd_data.command_data_u.prompt_cmd.sio=p_sio;
   c->cmd_data.command_data_u.prompt_cmd.blockid=p_blk; //get_sio_ids("PROMPT");
   return c;
}

struct command *new_menu_cmd(struct expr_str* p_menu_title,struct attrib *p_menu_attrib,struct on_events* p_events,int p_sio,
struct expr_str * menu_attrib_comment,struct expr_str *menu_attrib_style, struct expr_str *menu_attrib_image
) {
struct command *c;
   c=new_command(E_CMD_MENU_CMD);
   c->cmd_data.command_data_u.menu_cmd.menu_title=p_menu_title;
   c->cmd_data.command_data_u.menu_cmd.menu_attrib=p_menu_attrib;

   c->cmd_data.command_data_u.menu_cmd.menu_attrib_comment=menu_attrib_comment;
   c->cmd_data.command_data_u.menu_cmd.menu_attrib_style=menu_attrib_style;
   c->cmd_data.command_data_u.menu_cmd.menu_attrib_image=menu_attrib_image;
	
   c->cmd_data.command_data_u.menu_cmd.events=p_events;
   c->cmd_data.command_data_u.menu_cmd.sio=p_sio;
   c->cmd_data.command_data_u.menu_cmd.blockid=get_sio_ids("MENU");
   return c;
}


struct command *new_clear_cmd(e_clear e, void *data ,e_boolean todefaults) {
struct command *c;
   c=new_command(E_CMD_CLEAR_CMD);
	
   c->cmd_data.command_data_u.clear_cmd.clr_data.clr_type=e;
   c->cmd_data.command_data_u.clear_cmd.todefaults=todefaults;
   switch (e) {

	case E_CLR_FORM_DEFAULTS: break;
	case E_CLR_FORM: break;
	case E_CLR_SCREEN: break;

	case E_CLR_WINDOW: c->cmd_data.command_data_u.clear_cmd.clr_data.clear_data_u.window=(expr_str *)data; break;
	case E_CLR_STATUS: c->cmd_data.command_data_u.clear_cmd.clr_data.clear_data_u. statwindow=(expr_str *)data; break;
	case E_CLR_FIELDS: c->cmd_data.command_data_u.clear_cmd.clr_data.clear_data_u.fields=data; break;
	case E_CLR_FIELDS_TO_DEFAULT: c->cmd_data.command_data_u.clear_cmd.clr_data.clear_data_u.deffields=data; break;
   }
return c;
}

struct command *new_convert_cmd(char * p_repname,struct convert* p_c) {
struct command *c;
   c=new_command(E_CMD_CONVERT_CMD);
   c->cmd_data.command_data_u.convert_cmd.repname=strdup(p_repname);
   c->cmd_data.command_data_u.convert_cmd.namespace=strdup(get_namespace(p_repname));
   c->cmd_data.command_data_u.convert_cmd.conv_c=p_c;
   return c;
}


struct report_format_section_entry* new_report_format_section_entry(report_blocks rb, void *variable, commands* cmds, int orderby_var_no,int lineno) {
	struct report_format_section_entry*r;
	r=malloc(sizeof(struct report_format_section_entry));
	memset(r,0,sizeof(report_format_section_entry));
	r->rb_block.rb=rb;
	r->orderby_var_no=orderby_var_no;
	r->lineno=lineno;
	if (rb==RB_BEFORE_GROUP_OF) {
		r->rb_block.report_block_data_u.bf_variable=variable;
	}
	if (rb==RB_AFTER_GROUP_OF) {
		r->rb_block.report_block_data_u.af_variable=variable;
	}
	if (rb==RB_FORMAT_EVERY_ROW) {
		r->rb_block.report_block_data_u.variables=variable;
	}
	r->rep_sec_commands=cmds;
	return r;
}


struct command *new_output_cmd(char * p_reportname,expr_str_list* p_expressions) {
struct command *c;
   c=new_command(E_CMD_OUTPUT_CMD);
   c->cmd_data.command_data_u.output_cmd.repname=strdup(p_reportname);
   c->cmd_data.command_data_u.output_cmd.namespace=strdup(get_namespace(p_reportname));
   c->cmd_data.command_data_u.output_cmd.expressions=p_expressions;
   return c;
}


struct report_orderby_section *new_report_orderby_section(e_report_orderby p_type,expr_str_list* p_variables) {
struct report_orderby_section *c;
	c=malloc(sizeof(report_orderby_section));
   	c->variables=p_variables;
	c->rord_type=p_type;
   return c;
}


struct command *new_display_array_cmd( struct expr_str * p_srec,struct expr_str *p_arrayname,struct attrib *p_attrib,struct on_events* p_events,fh_field_entry* p_scroll_using,int p_sio, char *slice)  {
struct command *c;
   c=new_command(E_CMD_DISPLAY_ARRAY_CMD);
   c->cmd_data.command_data_u.display_array_cmd.srec=p_srec;
   c->cmd_data.command_data_u.display_array_cmd.arrayname=p_arrayname;
   c->cmd_data.command_data_u.display_array_cmd.attributes=p_attrib;
   c->cmd_data.command_data_u.display_array_cmd.events=p_events;
   c->cmd_data.command_data_u.display_array_cmd.helpno=0; // Help numbers dont seem to be in the spec for Informix4GL(tm) for a DISPLAY ARRAY
   c->cmd_data.command_data_u.display_array_cmd.scroll_using=p_scroll_using;
   c->cmd_data.command_data_u.display_array_cmd.sio=p_sio;
   c->cmd_data.command_data_u.display_array_cmd.blockid=get_sio_ids("DISPLAY");
   c->cmd_data.command_data_u.display_array_cmd.slice=strdup(slice);
   c->cmd_data.command_data_u.display_array_cmd.slice_start=find_slice(p_arrayname, slice,0);
   c->cmd_data.command_data_u.display_array_cmd.slice_end=find_slice(p_arrayname, slice,1);
   return c;
}





struct module_entry *new_import_function_definition(char * p_funcname,int p_nparam,int lineno) {
struct module_entry *c;
char buff[256];
   c=new_module_entry(E_MET_IMPORT_FUNCTION_DEFINITION);
	if (strlen(get_namespace(p_funcname))){
	sprintf(buff,"%s%s", get_namespace(p_funcname), p_funcname);
	} else {
		strcpy(buff, p_funcname);
	}
   c->module_entry_u.import_function_definition.funcname=strdup(buff);
   c->module_entry_u.import_function_definition.nparam=p_nparam;
   c->module_entry_u.import_function_definition.module=A4GL_compiling_module_basename();
   c->module_entry_u.import_function_definition.lineno=lineno;
	c->module_entry_u.import_function_definition.colno=0;
   return c;
}

struct module_entry *new_import_legacy_definition(char * p_funcname,int lineno) {
struct module_entry *c;
   c=new_module_entry(E_MET_IMPORT_LEGACY_DEFINITION);
   c->module_entry_u.import_legacy_definition.funcname=strdup(p_funcname);
   c->module_entry_u.import_legacy_definition.module=A4GL_compiling_module_basename();
   c->module_entry_u.import_legacy_definition.lineno=lineno;
   c->module_entry_u.import_legacy_definition.colno=0;
   return c;
}

struct module_entry *new_module_code_cmd(struct command *cmd)  {
struct module_entry *c;
   c=new_module_entry(E_MET_CMD);
   c->module_entry_u.cmd=cmd;
   return c;
}

struct module_entry *new_formhandler_definition(char *name, struct str_list *fld_list, on_events *fld_events, on_events *before_events, on_events *after_events ) {
struct module_entry *c;
   	c=new_module_entry(E_MET_FORMHANDLER_DEFINITION);
	c->module_entry_u.formhandler_definition.formhandler_name=strdup(name);
	c->module_entry_u.formhandler_definition.before_events=before_events;
	c->module_entry_u.formhandler_definition.after_events=after_events;
	c->module_entry_u.formhandler_definition.field_op_events=fld_events;
	c->module_entry_u.formhandler_definition.extra_warnings.extra_warnings_len=0;
	c->module_entry_u.formhandler_definition.extra_warnings.extra_warnings_val=0;
	

	return  c;
}


struct module_entry *new_function_definition(char * p_funcname,e_boolean p_isstatic,expr_str_list* p_parameters,commands* p_commands,int lineno) {
struct module_entry *c;
int a;
   c=new_module_entry(E_MET_FUNCTION_DEFINITION);
   c->module_entry_u.function_definition.funcname=strdup(p_funcname);
   c->module_entry_u.function_definition.namespace=strdup(get_namespace(p_funcname));
   c->module_entry_u.function_definition.isstatic=p_isstatic;
   c->module_entry_u.function_definition.variables.variables.variables_len=0;
   c->module_entry_u.function_definition.variables.variables.variables_val=NULL;
   c->module_entry_u.function_definition.expression_list.list.list_len=0;
   c->module_entry_u.function_definition.expression_list.list.list_val=0;
   c->module_entry_u.function_definition.extra_warnings.extra_warnings_len=0;
   c->module_entry_u.function_definition.extra_warnings.extra_warnings_val=0;

   A4GL_ensure_dtype_variables(p_parameters);
   if (p_parameters==0) {
		p_parameters=malloc(sizeof(struct expr_str_list));
		p_parameters->list.list_len=0;
		p_parameters->list.list_val=0;
    }
   c->module_entry_u.function_definition.parameters=p_parameters;

   c->module_entry_u.function_definition.func_commands=p_commands;
   c->module_entry_u.function_definition.module=A4GL_compiling_module_basename();
   c->module_entry_u.function_definition.lineno=lineno;
   c->module_entry_u.function_definition.lastlineno=yylineno;
   c->module_entry_u.function_definition.call_list.calls_by_call.calls_by_call_len=this_functions_call_list->calls_by_call.calls_by_call_len;
   c->module_entry_u.function_definition.call_list.calls_by_call.calls_by_call_val=this_functions_call_list->calls_by_call.calls_by_call_val;
   c->module_entry_u.function_definition.call_list.calls_by_expr.calls_by_expr_len=this_functions_call_list->calls_by_expr.calls_by_expr_len;
   c->module_entry_u.function_definition.call_list.calls_by_expr.calls_by_expr_val=this_functions_call_list->calls_by_expr.calls_by_expr_val;
   A4GL_set_extra_warnings( &c->module_entry_u.function_definition.extra_warnings.extra_warnings_len, &c->module_entry_u.function_definition.extra_warnings.extra_warnings_val);

   return c;
}




struct module_entry *new_main_definition(commands* p_commands,int lineno) {
struct module_entry *c;
   c=new_module_entry(E_MET_MAIN_DEFINITION);
   c->module_entry_u.function_definition.funcname=strdup("MAIN");
   c->module_entry_u.function_definition.namespace=strdup(get_namespace("MAIN"));
   c->module_entry_u.function_definition.isstatic=EB_FALSE;
   c->module_entry_u.function_definition.variables.variables.variables_len=0;
   c->module_entry_u.function_definition.variables.variables.variables_val=NULL;
   c->module_entry_u.function_definition.parameters=0;
   c->module_entry_u.function_definition.func_commands=p_commands;
   c->module_entry_u.function_definition.module=A4GL_compiling_module_basename();
   c->module_entry_u.function_definition.lineno=lineno;
   c->module_entry_u.function_definition.expression_list.list.list_len=0;
   c->module_entry_u.function_definition.expression_list.list.list_val=0;
   //c->module_entry_u.function_definition.colno=0;
   c->module_entry_u.function_definition.lastlineno=yylineno;
	c->module_entry_u.function_definition.extra_warnings.extra_warnings_len=0;
	c->module_entry_u.function_definition.extra_warnings.extra_warnings_val=0;


   c->module_entry_u.function_definition.call_list.calls_by_call.calls_by_call_len=this_functions_call_list->calls_by_call.calls_by_call_len;
   c->module_entry_u.function_definition.call_list.calls_by_call.calls_by_call_val=this_functions_call_list->calls_by_call.calls_by_call_val;
   c->module_entry_u.function_definition.call_list.calls_by_expr.calls_by_expr_len=this_functions_call_list->calls_by_expr.calls_by_expr_len;
   c->module_entry_u.function_definition.call_list.calls_by_expr.calls_by_expr_val=this_functions_call_list->calls_by_expr.calls_by_expr_val;
	A4GL_set_extra_warnings( &c->module_entry_u.function_definition.extra_warnings.extra_warnings_len, &c->module_entry_u.function_definition.extra_warnings.extra_warnings_val);
   return c;
}


struct command *new_alloc_arr_cmd(expr_str *p_variable) {
struct command *c;
struct variable_usage *u;
struct variable_usage *u_bottom;

   c=new_command(E_CMD_ALLOC_ARR_CMD);
	                /*
			//@FIXME  - Need to add this  logic here and return 0 if it fails..
                char buff[256];
                char *s;
                add_feature("ALLOCATE_ARRAY");
                strcpy(buff,$<str>2);
                s=strchr(buff,'[');
                if (!s) {
                        printf("Got : %s\n", buff);
                        a4gl_yyerror("Expecting an array and size");
                        YYERROR;
                }
                *s=0;
                s++;

                $<cmd>$=new_alloc_arr_cmd(make_bind(buff),s);
                */
  u=p_variable->expr_str_u.expr_variable_usage;
  u_bottom=u;
  while (u_bottom->next) {
            u_bottom = u_bottom->next;
   }

  if (u_bottom->subscripts.subscripts_len==0) {
	a4gl_yyerror("Expecting an array and size");
	return 0;
  }

  c->cmd_data.command_data_u.alloc_arr_cmd.variable=p_variable;

  /* c->cmd_data.command_data_u.alloc_arr_cmd.sz=strdup(p_sz); */
   return c;
}

struct command *new_dealloc_arr_cmd(expr_str * p_variable) {
struct command *c;
   c=new_command(E_CMD_DEALLOC_ARR_CMD);
   c->cmd_data.command_data_u.dealloc_arr_cmd.variable=p_variable;
   return c;
}

struct command *new_resize_arr_cmd(expr_str *p_variable) {
struct command *c;
   c=new_command(E_CMD_RESIZE_ARR_CMD);
                    /*
			//@FIXME  - Need to add this  logic here and return 0 if it fails..
                        char buff[256];
                        char *s;
                        add_feature("RESIZE_ARRAY");
                        strcpy(buff,$<str>2);
                        s=strchr(buff,'[');
                        if (!s) {
                                a4gl_yyerror("Expecting an array and size");
                                YYERROR;
                        }
                        *s=0;
                        s++;
                */

   c->cmd_data.command_data_u.resize_arr_cmd.variable=p_variable;
   /* c->cmd_data.command_data_u.resize_arr_cmd.sz=strdup(p_sz); */
   return c;
}

struct command *new_set_session_cmd(char * p_type,expr_str* p_s1,expr_str * p_s2,expr_str * p_s3) {
struct command *c;
   c=new_command(E_CMD_SET_SESSION_CMD);
   c->cmd_data.command_data_u.set_session_cmd.session_type=strdup(p_type);
   c->cmd_data.command_data_u.set_session_cmd.s1=p_s1;
   c->cmd_data.command_data_u.set_session_cmd.s2=p_s2;
   c->cmd_data.command_data_u.set_session_cmd.s3=p_s3;
   return c;
}


struct command *new_fetch_cmd(expr_str * p_connid, struct s_fetch* p_fetch,expr_str_list* p_outbind) {
struct command *c;
   c=new_command(E_CMD_FETCH_CMD);
   c->cmd_data.command_data_u.fetch_cmd.connid=p_connid;
   c->cmd_data.command_data_u.fetch_cmd.fetch=p_fetch;
   c->cmd_data.command_data_u.fetch_cmd.outbind=p_outbind;
	inc_var_assigned_from_binding_list(p_outbind);
   return c;
}


struct module_entry *new_pdf_report_definition(char * p_funcname,e_boolean p_isstatic,expr_str_list* p_parameters,pdf_startrep* p_report_output_section,report_orderby_section *p_report_orderby_section,report_format_section *p_report_format_section,int lineno ) {
struct module_entry *c;
   c=new_module_entry(E_MET_PDF_REPORT_DEFINITION);
   c->module_entry_u.pdf_report_definition.funcname=strdup(p_funcname);
   c->module_entry_u.pdf_report_definition.namespace=strdup(get_namespace(p_funcname));
   c->module_entry_u.pdf_report_definition.isstatic=p_isstatic;
   A4GL_ensure_dtype_variables(p_parameters);
   if (p_parameters==0) {
		p_parameters=malloc(sizeof(struct expr_str_list));
		p_parameters->list.list_len=0;
		p_parameters->list.list_val=0;
    }


   c->module_entry_u.pdf_report_definition.parameters=p_parameters;
   c->module_entry_u.pdf_report_definition.report_output_section=p_report_output_section;
   c->module_entry_u.pdf_report_definition.report_orderby_section=p_report_orderby_section;
   if (p_report_orderby_section) {
		expand_variables_in_expr_str_list(p_report_orderby_section->variables,1,1);
   }
   c->module_entry_u.pdf_report_definition.report_format_section=p_report_format_section;
   c->module_entry_u.pdf_report_definition.module=A4GL_compiling_module_basename();
   c->module_entry_u.pdf_report_definition.lineno=lineno;
   c->module_entry_u.pdf_report_definition.colno=0;
   c->module_entry_u.pdf_report_definition.lastlineno=yylineno;
   c->module_entry_u.pdf_report_definition.expression_list.list.list_len=0;
   c->module_entry_u.pdf_report_definition.expression_list.list.list_val=0;
	c->module_entry_u.pdf_report_definition.extra_warnings.extra_warnings_len=0;
	c->module_entry_u.pdf_report_definition.extra_warnings.extra_warnings_val=0;
  //this_module.expression_list.expression_list_val=0;
   c->module_entry_u.report_definition.aggregates.list.list_len=list_of_aggregates.list.list_len;
   c->module_entry_u.report_definition.aggregates.list.list_val=list_of_aggregates.list.list_val;
	list_of_aggregates.list.list_len=0;
	list_of_aggregates.list.list_val=0;

   c->module_entry_u.pdf_report_definition.call_list.calls_by_call.calls_by_call_len=this_functions_call_list->calls_by_call.calls_by_call_len;
   c->module_entry_u.pdf_report_definition.call_list.calls_by_call.calls_by_call_val=this_functions_call_list->calls_by_call.calls_by_call_val;
   c->module_entry_u.pdf_report_definition.call_list.calls_by_expr.calls_by_expr_len=this_functions_call_list->calls_by_expr.calls_by_expr_len;
   c->module_entry_u.pdf_report_definition.call_list.calls_by_expr.calls_by_expr_val=this_functions_call_list->calls_by_expr.calls_by_expr_val;
	A4GL_set_extra_warnings( &c->module_entry_u.pdf_report_definition.extra_warnings.extra_warnings_len, &c->module_entry_u.pdf_report_definition.extra_warnings.extra_warnings_val);
   return c;
}


struct module_entry *new_report_definition(char * p_funcname,e_boolean p_isstatic,expr_str_list* p_parameters,startrep* p_report_output_section,report_orderby_section *p_report_orderby_section,report_format_section *p_report_format_section,int lineno) {
struct module_entry *c;
   c=new_module_entry(E_MET_REPORT_DEFINITION);
   c->module_entry_u.report_definition.funcname=strdup(p_funcname);
   c->module_entry_u.report_definition.namespace=strdup(get_namespace(p_funcname));
   c->module_entry_u.report_definition.isstatic=p_isstatic;
   A4GL_ensure_dtype_variables(p_parameters);
   if (p_parameters==0) {
		p_parameters=malloc(sizeof(struct expr_str_list));
		p_parameters->list.list_len=0;
		p_parameters->list.list_val=0;
    }
   c->module_entry_u.report_definition.parameters=p_parameters;

   if (p_report_orderby_section) {
		expand_variables_in_expr_str_list(p_report_orderby_section->variables,1,1);
   }
	
   c->module_entry_u.report_definition.aggregates.list.list_len=list_of_aggregates.list.list_len;
   c->module_entry_u.report_definition.aggregates.list.list_val=list_of_aggregates.list.list_val;



	list_of_aggregates.list.list_len=0;
	list_of_aggregates.list.list_val=0;

   c->module_entry_u.report_definition.report_output_section=p_report_output_section;
   c->module_entry_u.report_definition.report_orderby_section=p_report_orderby_section;
   c->module_entry_u.report_definition.report_format_section=p_report_format_section;
   c->module_entry_u.report_definition.module=A4GL_compiling_module_basename();
   c->module_entry_u.report_definition.lineno=lineno;
   c->module_entry_u.report_definition.colno=0;
   c->module_entry_u.report_definition.lastlineno=yylineno;
   c->module_entry_u.report_definition.expression_list.list.list_len=0;
   c->module_entry_u.report_definition.expression_list.list.list_val=0;
	c->module_entry_u.report_definition.extra_warnings.extra_warnings_len=0;
	c->module_entry_u.report_definition.extra_warnings.extra_warnings_val=0;

   c->module_entry_u.report_definition.call_list.calls_by_call.calls_by_call_len=this_functions_call_list->calls_by_call.calls_by_call_len;
   c->module_entry_u.report_definition.call_list.calls_by_call.calls_by_call_val=this_functions_call_list->calls_by_call.calls_by_call_val;
   c->module_entry_u.report_definition.call_list.calls_by_expr.calls_by_expr_len=this_functions_call_list->calls_by_expr.calls_by_expr_len;
   c->module_entry_u.report_definition.call_list.calls_by_expr.calls_by_expr_val=this_functions_call_list->calls_by_expr.calls_by_expr_val;
   A4GL_set_extra_warnings( &c->module_entry_u.report_definition.extra_warnings.extra_warnings_len, &c->module_entry_u.report_definition.extra_warnings.extra_warnings_val);

   return c;
}


void dump_list(expr_str_list *l) {
}

int is_valid_identifier(expr_str *l) {
	return 1;
}


/*
static char *get_expr_list_as_string(struct expr_str_list *l) {
static char buff[20000];
int a;
  if (l == 0)
    return "";

     l = A4GL_rationalize_list (l);
        strcpy(buff,"");

  for (a = 0; a < l->list.list_len; a++)
    {
  struct expr_str *p;
                char *ptr;
      p = l->list.list_val[a];
      if (p->expr_type == ET_EXPR_REDUCED)
        continue;

        ptr=expr_as_string_when_possible(p);
        if (ptr && strlen(ptr))  {
        strcat(buff, " ");
                        strcat(buff,ptr);
                }
  }
        return strdup(buff);
}
*/


#ifdef MOVED
/*
void linearise_commands_from_events(struct commands *master_list, struct on_events* evt_list) {
int a;

A4GL_assertion(master_list==0, "Master list not set");

if (evt_list==0) return;

for (a=0;a<evt_list->event.event_len;a++) {
	linearise_commands(master_list, evt_list->event.event_val[a]->on_event_commands);
}

}



struct commands * linearise_commands(struct commands *master_list, struct commands *cmds) {
int a;
int cnt;
struct on_events* evt_list;

	if (master_list==0) {	
		master_list=malloc(sizeof(struct commands));
		master_list->cmds.cmds_val=0;
		master_list->cmds.cmds_len=0;
	}
	if (cmds==0) return master_list;

	for (a=0;a<cmds->cmds.cmds_len;a++) {

		master_list->cmds.cmds_len++;
		master_list->cmds.cmds_val=realloc(master_list->cmds.cmds_val, sizeof(struct command)* master_list->cmds.cmds_len);
		master_list->cmds.cmds_val[master_list->cmds.cmds_len-1]=cmds->cmds.cmds_val[a];

		switch ( cmds->cmds.cmds_val[a]->cmd_data.type) {
			case E_CMD_FOR_CMD:
				linearise_commands(master_list, cmds->cmds.cmds_val[a]->cmd_data.command_data_u.for_cmd.for_commands);
				break;
	
			case E_CMD_IF_CMD:
				for (cnt=0;cnt<cmds->cmds.cmds_val[a]->cmd_data.command_data_u.if_cmd.truths.conditions.conditions_len;cnt++) {
					linearise_commands(master_list, cmds->cmds.cmds_val[a]->cmd_data.command_data_u.if_cmd.truths.conditions.conditions_val[cnt].whentrue);
				}
				linearise_commands(master_list, cmds->cmds.cmds_val[a]->cmd_data.command_data_u.if_cmd.whenfalse);
				break;

			case E_CMD_FOREACH_CMD:
				linearise_commands(master_list, cmds->cmds.cmds_val[a]->cmd_data.command_data_u.foreach_cmd.foreach_commands);
				break;
	
			case E_CMD_WHILE_CMD:
				linearise_commands(master_list, cmds->cmds.cmds_val[a]->cmd_data.command_data_u.while_cmd.while_commands);
				break;


			case E_CMD_CASE_CMD:
				for (cnt=0;cnt<cmds->cmds.cmds_val[a]->cmd_data.command_data_u.case_cmd.whens->whens.whens_len ;cnt++) {
					linearise_commands(master_list, cmds->cmds.cmds_val[a]->cmd_data.command_data_u.case_cmd.whens->whens.whens_val[cnt]->when_commands);
				}
				linearise_commands(master_list, cmds->cmds.cmds_val[a]->cmd_data.command_data_u.case_cmd.otherwise);
				break;
	

			case E_CMD_MENU_CMD:
				evt_list=cmds->cmds.cmds_val[a]->cmd_data.command_data_u.menu_cmd.events;
				linearise_commands_from_events(master_list, evt_list);
				break;

			case E_CMD_PROMPT_CMD:
				evt_list=cmds->cmds.cmds_val[a]->cmd_data.command_data_u.prompt_cmd.events;
				linearise_commands_from_events(master_list, evt_list);
				break;

			case E_CMD_DISPLAY_ARRAY_CMD:
				evt_list=cmds->cmds.cmds_val[a]->cmd_data.command_data_u.display_array_cmd.events;
				linearise_commands_from_events(master_list, evt_list);
				break;
	
			case E_CMD_INPUT_CMD:
				evt_list=cmds->cmds.cmds_val[a]->cmd_data.command_data_u.input_cmd.events;
				linearise_commands_from_events(master_list, evt_list);
				break;

			case E_CMD_INPUT_ARRAY_CMD:
				evt_list=cmds->cmds.cmds_val[a]->cmd_data.command_data_u.input_array_cmd.events;
				linearise_commands_from_events(master_list, evt_list);
				break;
			case E_CMD_CONSTRUCT_CMD:
				evt_list=cmds->cmds.cmds_val[a]->cmd_data.command_data_u.construct_cmd.events;
				linearise_commands_from_events(master_list, evt_list);
				break;

			default : 
				// dont need to do anything - these don't embed Commands..
				break;
		}
		
	}

return master_list;
}






static void commands_check_function (struct s_function_definition *f) {
struct commands *func_cmds=0;
struct command *r;
int a;
int b;
int nreturns=0;
int nretvals=0;

   func_cmds=linearise_commands(0, 0);
   linearise_commands(func_cmds, f->func_commands);


   // first - check for multiple return paths..
   for (a=0;a<func_cmds->cmds.cmds_len;a++) {
	r=func_cmds->cmds.cmds_val[a];
	if (r->cmd_data.type==E_CMD_RETURN_CMD) {
		if (nreturns) {
			yylineno=r->lineno;
			A4GL_lint("Coding Standards: Multiple RETURNs in function"); // COMMENTED OUT
			if (r->cmd_data.command_data_u.return_cmd.retvals->list.list_len!=nretvals) {
				A4GL_warn("Function RETURNs different numbers of values");
			}
		} else {
			nretvals=r->cmd_data.command_data_u.return_cmd.retvals->list.list_len;
			nreturns++;
	
		}
	}


	if (r->cmd_data.type==E_CMD_CASE_CMD) {

	      	for (b = 0; b < r->cmd_data.command_data_u.case_cmd.whens->whens.whens_len; b++) {
			if (A4GL_is_just_int_literal(r->cmd_data.command_data_u.case_cmd.whens->whens.whens_val[b]->when_expr,0)) {
				yylineno=r->lineno;
				A4GL_lint("WHEN condition is always FALSE"); // COMMENTED OUT
			}
			if (A4GL_is_just_int_literal(r->cmd_data.command_data_u.case_cmd.whens->whens.whens_val[b]->when_expr,1)) {
				yylineno=r->lineno;
				A4GL_lint("WHEN condition is always TRUE"); // COMMENTED OUT
			}
		}

		if (!r->cmd_data.command_data_u.case_cmd.otherwise) {
			yylineno=r->lineno;
			A4GL_lint("Coding Standards: CASE has no OTHERWISE"); // COMMENTED OUT
		}
	}

	if (r->cmd_data.type==E_CMD_LET_CMD) {
		t_expr_str_list * expr_list;
                expr_str_list * varlist;
		  int from_exprs;
		expr_list=r->cmd_data.command_data_u.let_cmd.vals;
		  expr_list = A4GL_rationalize_list (expr_list);
  		from_exprs = A4GL_new_list_get_count (expr_list);

		
              	varlist=r->cmd_data.command_data_u.let_cmd.vars;
		if ( from_exprs!=varlist->bindings.bindings_len && varlist->bindings.bindings_len!=1) {
			yylineno=r->lineno;
			A4GL_warn("Mismatch in number of parameters (1)");
		}

		  for (b = 0; b < varlist->bindings.bindings_len; b++) {
			if ( strncmp(varlist->bindings.bindings_val[b].varname,"a4gl_sqlca",10)==0) {
				yylineno=r->lineno;
                        	A4GL_lint("Coding Standards: Direct assignment to SQLCA record entry"); // COMMENTED OUT
        		}

		        if ( strcmp(varlist->bindings.bindings_val[b].varname,"int_flag")==0) {
                        	if (A4GL_is_just_int_literal(expr_list->list.list_val[b],0) || A4GL_is_just_int_literal(expr_list->list.list_val[b],1)) ;
                        	else {
					yylineno=r->lineno;
                                	A4GL_lint("Coding Standards: 'int_flag' set to value which is neither TRUE or FALSE"); // COMMENTED OUT
                        	}
			}

		        if ( strcmp(varlist->bindings.bindings_val[b].varname,"quit_flag")==0) {
                        	if (A4GL_is_just_int_literal(expr_list->list.list_val[b],0) || A4GL_is_just_int_literal(expr_list->list.list_val[b],1)) ;
                        	else {
					yylineno=r->lineno;
                                	A4GL_lint("Coding Standards: 'quit_flag' set to value which is neither TRUE or FALSE"); // COMMENTED OUT
                        	}
			}
		}
	}


   }

}




void check_module(struct module_definition *d) {
struct commands *all_cmds=0;
int a;
int b;
struct report_format_section *report_format_section;

   all_cmds=linearise_commands(0, 0);

   for (a=0;a<d->module_variables.variables.variables_len;a++) {

		if (d->module_variables.variables.variables_val[a]->usage==0 && d->module_variables.variables.variables_val[a]->assigned==0) {
			char buff[256];
			yylineno=1;
			d->module_variables.variables.variables_val[a]->flags|=VARFLAG_DEF_NOT_USED;
			//sprintf(buff, "Module variable (%s) is defined but not used", d->module_variables.variables.variables_val[a]->names.names.names_val[0].name);
			//A4GL_lint(buff); // COMMENTED OUT
		}

		if (d->module_variables.variables.variables_val[a]->usage==0 && d->module_variables.variables.variables_val[a]->assigned) {
			char buff[256];
			yylineno=1;
			d->module_variables.variables.variables_val[a]->flags|=VARFLAG_ASSIGNED_NOT_USED;
			//sprintf(buff, "Module variable (%s) is assigned a value but not used", d->module_variables.variables.variables_val[a]->names.names.names_val[0].name);
			//A4GL_lint(buff);
		}

		//printf("%s - %d\n", d->module_variables.variables.variables_val[a]->names.names.names_val[0].name, d->module_variables.variables.variables_val[a]->usage);
   }



   for (a=0;a<d->module_entries.module_entries_len;a++) {
		struct s_function_definition *f;


	switch (d->module_entries.module_entries_val[a]->met_type) {

        	case E_MET_MAIN_DEFINITION:
        	case E_MET_FUNCTION_DEFINITION:     
			commands_check_function (&d->module_entries.module_entries_val[a]->module_entry_u.function_definition);

   for (b=0;b<d->module_entries.module_entries_val[a]->module_entry_u.function_definition.variables.variables.variables_len;b++) {
		f=&d->module_entries.module_entries_val[a]->module_entry_u.function_definition;
		
		if ( f->variables.variables.variables_val[b]->usage==0 && f->variables.variables.variables_val[b]->assigned==0) {
			char buff[256];
			yylineno=f->variables.variables.variables_val[b]->lineno;
			f->variables.variables.variables_val[b]->flags |=VARFLAG_DEF_NOT_USED;

			//sprintf(buff, "Local variable (%s) is defined but not used", d->module_entries.module_entries_val[a]->module_entry_u.function_definition.variables.variables.variables_val[b]->names.names.names_val[0].name);
			//A4GL_lint(buff); // COMMENTED OUT
		}

		if ( f->variables.variables.variables_val[b]->usage==0 && f->variables.variables.variables_val[b]->assigned) {
			char buff[256];
			yylineno=f->variables.variables.variables_val[b]->lineno;
			f->variables.variables.variables_val[b]->flags |=VARFLAG_ASSIGNED_NOT_USED;
			//yylineno=1;
			//yylineno=d->module_entries.module_entries_val[a]->module_entry_u.function_definition.lineno;
			//sprintf(buff, "Local variable (%s) is assigned a value but not used", d->module_entries.module_entries_val[a]->module_entry_u.function_definition.variables.variables.variables_val[b]->names.names.names_val[0].name);
			//A4GL_lint(buff);
		}
   }

			linearise_commands(all_cmds, d->module_entries.module_entries_val[a]->module_entry_u.function_definition.func_commands);
			break;

        	case E_MET_REPORT_DEFINITION:    
			report_format_section=d->module_entries.module_entries_val[a]->module_entry_u.report_definition.report_format_section;
			for (b=0;b<report_format_section->entries.entries_len;b++) {
				linearise_commands(all_cmds, report_format_section->entries.entries_val[b]->rep_sec_commands);
			}
			break;

        	case E_MET_PDF_REPORT_DEFINITION:       
			report_format_section=d->module_entries.module_entries_val[a]->module_entry_u.pdf_report_definition.report_format_section;
			for (b=0;b<report_format_section->entries.entries_len;b++) {
				linearise_commands(all_cmds, report_format_section->entries.entries_val[b]->rep_sec_commands);

			}
			break;

		// We dont need to worry about these commands....
		case E_MET_CMD:
		case E_MET_IMPORT_FUNCTION_DEFINITION:
		case E_MET_IMPORT_LEGACY_DEFINITION: break;

	}
   }

   
   // Look for Prepared but not used...
   for (a=0;a<all_cmds->cmds.cmds_len;a++) {
	if (all_cmds->cmds.cmds_val[a]->cmd_data.type==E_CMD_PREPARE_CMD) {
		int used=0;
		for (b=0;b<all_cmds->cmds.cmds_len;b++) {

			// Prepares can be used for DECLARE or for EXECUTE
			if ( all_cmds->cmds.cmds_val[b]->cmd_data.type==E_CMD_EXECUTE_CMD) {
				if (strcmp(all_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.prepare_cmd.stmtid, all_cmds->cmds.cmds_val[b]->cmd_data.command_data_u.execute_cmd.sql_stmtid)==0) {
					used++;
				}
			}

			if ( all_cmds->cmds.cmds_val[b]->cmd_data.type==E_CMD_DECLARE_CMD) {
				if (strcmp(all_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.prepare_cmd.stmtid, all_cmds->cmds.cmds_val[b]->cmd_data.command_data_u.declare_cmd.sql)==0) {
					used++;
				}
			}

		}


		if (!used) {
			char buff[256];
			yylineno=all_cmds->cmds.cmds_val[a]->lineno;
			sprintf(buff,"Prepared statement (%s) is not used", A4GL_strip_quotes(all_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.prepare_cmd.stmtid));
			A4GL_lint(buff); // COMMENTED OUT
		}

	}
   }


   // Look for DECLAREd but not used...
   for (a=0;a<all_cmds->cmds.cmds_len;a++) {
	if (all_cmds->cmds.cmds_val[a]->cmd_data.type==E_CMD_DECLARE_CMD) {
		int used=0;
		for (b=0;b<all_cmds->cmds.cmds_len;b++) {

			// Prepares can be used for DECLARE or for EXECUTE
			if ( all_cmds->cmds.cmds_val[b]->cmd_data.type==E_CMD_OPEN_CURSOR_CMD) {
				if (strcmp(all_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.declare_cmd.cursorname, all_cmds->cmds.cmds_val[b]->cmd_data.command_data_u.open_cursor_cmd.cursorname)==0) {
					used++;
				}
			}


			if ( all_cmds->cmds.cmds_val[b]->cmd_data.type==E_CMD_FOREACH_CMD) {
				if (strcmp(all_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.declare_cmd.cursorname, all_cmds->cmds.cmds_val[b]->cmd_data.command_data_u.foreach_cmd.cursorname)==0) {
					used++;
				}
			}
		}

		if (!used) {
			char buff[256];
			yylineno=all_cmds->cmds.cmds_val[a]->lineno;
			sprintf(buff,"Cursor (%s) is DECLAREd but not OPENed", A4GL_strip_quotes(all_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.declare_cmd.cursorname));
			A4GL_lint(buff); // COMMENTED OUT
		}
	}
   }



   // Look for OPEN FORM but not DISPLAYed...
   for (a=0;a<all_cmds->cmds.cmds_len;a++) {
	if (all_cmds->cmds.cmds_val[a]->cmd_data.type==E_CMD_OPEN_FORM_CMD) {
		int used=0;
		for (b=0;b<all_cmds->cmds.cmds_len;b++) {

			// Prepares can be used for DECLARE or for EXECUTE
			if ( all_cmds->cmds.cmds_val[b]->cmd_data.type==E_CMD_DISPLAY_FORM_CMD) {
				if (strcmp(all_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.open_form_cmd.formname, all_cmds->cmds.cmds_val[b]->cmd_data.command_data_u.display_form_cmd.formname)==0) {
					used++;
				}
			}
		}

		if (!used) {
			char buff[256];
			yylineno=all_cmds->cmds.cmds_val[a]->lineno;
			sprintf(buff,"FORM (%s) is OPENed but not DISPLAYed", A4GL_strip_quotes(all_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.open_form_cmd.formname));
			A4GL_lint(buff); // COMMENTED OUT
		}
	}
   }

   // CURRENT WINDOW IS or CLOSE WINDOW but not OPENED...
   for (a=0;a<all_cmds->cmds.cmds_len;a++) {
	int found_something=0;
	char *cwindow="undefined";
	char *action="undefined";
	if (all_cmds->cmds.cmds_val[a]->cmd_data.type==E_CMD_CURRENT_WIN_CMD) {
				found_something++;
				cwindow=all_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.current_win_cmd.windowname;
				action="has been made CURRENT";
	}
	if (all_cmds->cmds.cmds_val[a]->cmd_data.type==E_CMD_CLOSE_CMD) {
				found_something++;
			if (all_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.close_cmd.cl_type==E_CT_WINDOW) {
				cwindow=all_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.close_cmd.ident;
				action="has been CLOSEd";
			}
	}


	if (found_something) {
		int used=0;
		for (b=0;b<all_cmds->cmds.cmds_len;b++) {
			if ( all_cmds->cmds.cmds_val[b]->cmd_data.type==E_CMD_OPEN_WINDOW_CMD) {
				if (strcmp(cwindow, all_cmds->cmds.cmds_val[b]->cmd_data.command_data_u.open_window_cmd.windowname)==0) {
					used++;
				}
			}
		}

		if (!used) {
			char buff[256];
			yylineno=all_cmds->cmds.cmds_val[a]->lineno;
			sprintf(buff,"Window (%s) %s but has not been OPENed", cwindow,action);
			A4GL_lint(buff); // COMMENTED OUT
		}
	}
   }



}
*/
#endif

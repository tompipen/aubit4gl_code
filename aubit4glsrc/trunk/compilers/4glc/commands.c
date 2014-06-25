
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "a4gl_4glc_int.h"
#include "lint.h"
#include "parsehelp.h"
#include "variables_new.h"

//extern char infilename[];
extern int yylineno;
extern int token_read_on_line;
extern int token_read_on_col;

extern int rep_type;

struct s_commands * linearise_commands(struct s_commands *master_list, struct s_commands *cmds) ;
void linearise_expression(expr_str_list *l,  expr_str *e );
//static char *get_expr_list_as_string(struct expr_str_list *l) ;
//static void linearise_commands_from_events(struct s_commands *master_list, struct on_events* evt_list) ;
//char *A4GL_get_current_comments();
static int get_exit_loop (char *cmd_type);
//struct expr_str *A4GL_new_expr_list_with_list(expr_str_list *l);
extern struct expr_str_list list_of_aggregates;
extern struct s_call_list *this_functions_call_list;
extern int lastlineno;
int llineno=0;

int set_cmdlineno(int n) {
	if (n==0) {
		n=yylineno;
	} 
	llineno=n;
	if (n>lastlineno) {
		lastlineno=n;
	}
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
	if (A4GL_isyes(acl_getenv("LOGCOMMANDS"))) {
		printf("Command @ line : %d\n",c->lineno);
	}
	c->module=A4GL_compiling_module_basename();
	c->comment=A4GL_get_current_comments(c->lineno, c->colno);

	c->ignore_error_list=NULL;

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
        if (var_usage->substrings_start.substrings_start) {
                strcat(buff, "[");
                strcat(buff, expr_as_string_when_possible(var_usage->substrings_start.substrings_start));
                if (var_usage->substrings_end.substrings_end) {
                        strcat(buff, ",");
                        strcat(buff, expr_as_string_when_possible(var_usage->substrings_end.substrings_end));
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
	if (A4GL_isyes(acl_getenv("DONTSAVECOMMENTS"))) {
		return "";	
	}
	ptr=A4GL_has_comment(lineno,colno);


   int sl=0;



	while (ptr) {
      sl+=strlen(ptr)+1;
      if (sl>=sizeof(buff)) {
               //char wn[200];
                  //sprintf(wn,"Size of comment is too large @ line %d", lineno);
                  A4GL_warn("Size of comment is too large" );
                 break;
      }
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



#define ET_EXPR_VARIABLE_USAGE_call cmds_get_variable_usage_as_string

#ifdef OLD
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

	case ET_EXPR_LINENO:
		return "lineno";

		case ET_EXPR_PAGENO:
			return "pageno";

    case ET_EXPR_LITERAL_LONG:
      {
        static char smbuff[200];
        sprintf (smbuff, "%ld", (long)e->expr_str_u.expr_long);
        return smbuff;
      }
      break;

    case ET_EXPR_BRACKET:
      {
        static char smbuff[1024];
	char *ptr;
	ptr=strdup(expr_as_string_when_possible(e->expr_str_u.expr_expr));
        sprintf (smbuff, "(%s)", ptr);
	free(ptr);
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

        case ET_EXPR_OP_MOD:
                {
                char buff[2000];
                sprintf(buff,"%s MOD %s", expr_as_string_when_possible (e->expr_str_u.expr_op->left), expr_as_string_when_possible (e->expr_str_u.expr_op->right));
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
                sprintf(buff,"%s-%s", expr_as_string_when_possible (e->expr_str_u.expr_op->left), expr_as_string_when_possible (e->expr_str_u.expr_op->right));
                return strdup(buff);
                }
                break;

        case ET_EXPR_OP_SPACES:
                return " ";
	case ET_EXPR_PARAMETER:
		if ( e->expr_str_u.expr_param.isReference==EB_TRUE) {
			char buff[200];
			sprintf(buff,"REFERENCE %s", e->expr_str_u.expr_param.expr_string);
			return strdup(buff);
		} else {
			return e->expr_str_u.expr_param.expr_string;
		}

        case ET_EXPR_TIME_EXPR: return "TIME";
        case ET_EXPR_TODAY: return "TODAY";
	case ET_EXPR_ASSOC:
      {
        //char *p;
        char buff[256];
        sprintf (buff, "<<%s>>", expr_as_string_when_possible (e->expr_str_u.expr_assoc_subscript->subscript_value));
        return strdup (buff);
      }
		

    case ET_EXPR_NULL:
      return "NULL";

        case ET_EXPR_DAY_FUNC:
      {
        //char *p;
        char buff[256];
        sprintf (buff, "DAY(%s)", expr_as_string_when_possible (e->expr_str_u.expr_expr));
        return strdup (buff);
      }
      break;

    case ET_EXPR_YEAR_FUNC:

      {
        //char *p;
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

        case ET_EXPR_FIELD_TOUCHED:
                return "FIELD_TOUCHED(...)";
        case ET_EXPR_NOT_FIELD_TOUCHED:
                return "NOT_FIELD_TOUCHED(...)";

	

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
#endif
#include "expr_as_string_when_possible.c"


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
        attr->style_expr=NULL;
        attr->currentrowdisplayexpr=NULL;
        attr->current_field_display=NULL;
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


struct command *new_execute_procedure_cmd(expr_str *p_connid, char *nm, s_select_list_item_list *parameters) { //!
struct command *c;
   c=new_command(E_CMD_EXECUTE_PROCEDURE_CMD);
   c->cmd_data.command_data_u.execute_procedure_cmd.connid=p_connid;
   c->cmd_data.command_data_u.execute_procedure_cmd.funcname=strdup(nm);
   c->cmd_data.command_data_u.execute_procedure_cmd.parameters=parameters;
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


struct command *new_free_blob_cmd(expr_str *p_var) { //!
struct command *c;
   c=new_command(E_CMD_FREE_BLOB_CMD);
   c->cmd_data.command_data_u.free_blob_cmd.var=p_var;
   return c;
}
 

struct command *new_lint_ignore_cmd(str_list *list) {
	struct command *c;
	c=new_command(E_CMD_LINT_IGNORE_CMD);
	c->cmd_data.command_data_u.lint_ignore_cmd.values=list;
	return c;
}

struct command *new_copyback_cmd(expr_str *var) {
	struct command *c;
	c=new_command(E_CMD_COPYBACK_CMD);
	c->cmd_data.command_data_u.copyback_cmd.variable=var;
	return c;
}

struct command *new_lint_expect_cmd(str_list *list) {
	struct command *c;
	c=new_command(E_CMD_LINT_EXPECT_CMD);
	c->cmd_data.command_data_u.lint_expect_cmd.values=list;
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
		sio_id=get_sio_id("PROMPT");
		block_no=get_exit_loop("PROMPT");
		break;
	case EBC_CASE:          // Exit CASE
		block_no=get_exit_loop("CASE");
		break;
	case EBC_TODO:          // Exit TODO
		block_no=get_exit_loop("TODO");
		break;
	case EBC_DIALOG:          // Exit DIALOG
		block_no=get_exit_loop("DIALOG");
		break;

	case EBC_SPL_WHILE:
	case EBC_SPL_FOREACH:
	case EBC_SPL_FOR:
		block_no=0;
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
int depth;
  ccnt = A4GL_get_ccnt ();

depth=0;
  for (a = ccnt - 1; a >= 0; a--)
    {
	depth++;
      if (strcmp (command_type_for_stack_pos(a), cmd_type) == 0)
        {
	if (A4GL_isyes(acl_getenv("SHOWDEPTH"))) {
	if (depth>1) {
		printf("EXIT DEPTH : %d %s [%d]\n", depth, cmd_type,yylineno );
		int b;
  		for (b = ccnt - 1; b >= a; b--) {
			printf("   %s\n", command_type_for_stack_pos(b));
		}
	}
	}
          g = 1;
          break;
        }
    }

  if (g == 0)
    {
      printf ("wanted to exit a %s but wasnt in one!\n", cmd_type);
#ifdef DEBUG
      A4GL_debug ("/* wanted to exit a %s but wasnt in one! */", cmd_type);
#endif
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
	case EBC_TODO:          // Exit TODO
		block_no=get_exit_loop("TODO");
		break;
	case EBC_DIALOG:          // Exit TODO
		block_no=get_exit_loop("DIALOG");
		break;
	case EBC_SPL_WHILE:
	case EBC_SPL_FOREACH:
	case EBC_SPL_FOR:
		block_no=0;
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



struct command *new_accept_cmd(void) {
struct command *c;
   c=new_command(E_CMD_ACCEPT_CMD);
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


struct command *new_sort_cmd(expr_str *variable, expr_str *callback,expr_str *limit) {
struct command *c;
	c=new_command(E_CMD_SORT_CMD);
	c->cmd_data.command_data_u.sort_cmd.variable=variable;
	c->cmd_data.command_data_u.sort_cmd.callback=callback;
	c->cmd_data.command_data_u.sort_cmd.limit=limit;
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
 
 
struct command *new_done_cmd(void) { //!
struct command *c;
   c=new_command(E_CMD_DONE_CMD);
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
 

struct command *new_run_waiting_for_cmd(expr_str *p_run_string, expr_str *p_sleep, expr_str *p_msg_repeat_every, int p_msg_type, expr_str *p_msgtext) {
struct command *c;
   c=new_command(E_CMD_RUN_WAITING_FOR_CMD);
   c->cmd_data.command_data_u.run_waiting_for_cmd.run_string=p_run_string;
   c->cmd_data.command_data_u.run_waiting_for_cmd.sleep=p_sleep;
   c->cmd_data.command_data_u.run_waiting_for_cmd.msg_repeat_every=p_msg_repeat_every;
   c->cmd_data.command_data_u.run_waiting_for_cmd.msg_type=p_msg_type;
   c->cmd_data.command_data_u.run_waiting_for_cmd.msg_text=p_msgtext;
 
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
		inc_var_usage(p_sql);
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

struct command *new_init_cmd(struct expr_str_list* p_varlist,str_list *p_tablist,int tonull) { //!
struct command *c;
//struct expr_str_list* p_varlist_expanded;
//extern int nullbindcnt;
char errbuff[256];
int a;
   c=new_command(E_CMD_INIT_CMD);
//printf("p_varlist->list.list_len=%d\n", p_varlist->list.list_len);
//
//
	

p_varlist=expand_variables_in_expr_str_list(p_varlist,1,0);

	for (a=0;a<p_varlist->list.list_len;a++) {
			ensure_variable(errbuff, p_varlist->list.list_val[a],0);
	}
   c->cmd_data.command_data_u.init_cmd.varlist=p_varlist;
   c->cmd_data.command_data_u.init_cmd.init_like_exprlist=0;
   c->cmd_data.command_data_u.init_cmd.tonull=tonull;

   if (p_varlist->list.list_len>5000) {
	char buff[3000];
	sprintf(buff, "Large INITIALIZE in 4gl code (%d entries)\nIf initializing an array - consider doing the subscriptions explicitly", p_varlist->list.list_len);
	A4GL_warn(buff);
   }

   if (p_tablist && p_tablist->str_list_entry.str_list_entry_len)  {
   		c->cmd_data.command_data_u.init_cmd.init_like_exprlist=malloc(sizeof(struct expr_str_list));

		 c->cmd_data.command_data_u.init_cmd.init_like_exprlist->list.list_len=p_tablist->str_list_entry.str_list_entry_len;
		 c->cmd_data.command_data_u.init_cmd.init_like_exprlist->list.list_val=malloc(sizeof(struct expr_str *)*p_tablist->str_list_entry.str_list_entry_len);
			
		c->cmd_data.command_data_u.init_cmd.init_like_exprlist->unexpanded_list.list.list_len=0;
		c->cmd_data.command_data_u.init_cmd.init_like_exprlist->unexpanded_list.list.list_val=0;

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
	
				ptr=A4GL_new_literal_string(A4GL_strip_quotes(rstring));
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
   c->cmd_data.command_data_u.finish_cmd.n_namespace=strdup(get_namespace(p_repname));
   c->cmd_data.command_data_u.finish_cmd.conv_c=p_c;

   		add_to_call_list_by_call(c);

   return c;
}
 
struct command *new_start_cmd(char * p_repname,struct startrep *p_c) {
struct command *c;
   c=new_command(E_CMD_START_CMD);
   c->cmd_data.command_data_u.start_cmd.repname=strdup(p_repname);
   c->cmd_data.command_data_u.start_cmd.n_namespace=strdup(get_namespace(p_repname));
   c->cmd_data.command_data_u.start_cmd.sc_c=p_c;

   		add_to_call_list_by_call(c);

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
   c->cmd_data.command_data_u.term_rep_cmd.n_namespace=strdup(get_namespace(p_reportname));
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
new_spl_proc
new_spl_raise_exception_cmd
new_spl_on_exception_cmd
new_list_of_integers
new_spl_foreach_select
new_spl_foreach_execute
new_spl_execute
new_spl_fcall
new_spl_trace_cmd
*/

struct command *new_sql_debug_file_to_cmd(expr_str *p_connid, expr_str *p_filename) {
struct command *c;
   c=new_command(E_CMD_SQL_DEBUG_FILE_CMD);
   c->cmd_data.command_data_u.sql_debug_file_cmd.connid=p_connid;
   c->cmd_data.command_data_u.sql_debug_file_cmd.debugfile=p_filename;
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

struct command *new_let_cmd(expr_str_list* p_vars,expr_str_list *p_vals) {
struct command *c;
   	c=new_command(E_CMD_LET_CMD);
   	c->cmd_data.command_data_u.let_cmd.vars=p_vars;
	p_vals=make_fgl_expr_list(p_vals);

	if (c->cmd_data.command_data_u.let_cmd.vars->list.list_len>1 && p_vals) {
		if (p_vars->list.list_len!=p_vals->list.list_len) {
			yylineno=c->lineno;
			a4gl_yyerror("Number of variables does not match number of values");
		}
	}
   	c->cmd_data.command_data_u.let_cmd.vals=p_vals;

   inc_var_assigned_from_binding_list(p_vars);

   return c;
}


struct command *new_mlet_cmd(expr_str_list* p_vars,expr_str *p_val) {
struct command *c;
   	c=new_command(E_CMD_MLET_CMD);
   	c->cmd_data.command_data_u.mlet_cmd.vars=p_vars;
   	c->cmd_data.command_data_u.mlet_cmd.val=p_val;

   	inc_var_assigned_from_binding_list(p_vars);

   return c;
}


struct command *new_case_cmd(expr_str* p_case_expr,struct whens *p_whens,s_commands *p_otherwise,int block_id) {
struct command *c;
   c=new_command(E_CMD_CASE_CMD);
   c->cmd_data.command_data_u.case_cmd.case_expr=p_case_expr;
   c->cmd_data.command_data_u.case_cmd.whens=p_whens;
   c->cmd_data.command_data_u.case_cmd.otherwise=p_otherwise;
   c->cmd_data.command_data_u.case_cmd.block_id=block_id;
   return c;
}


struct command *new_todo_cmd(expr_str* p_todo_expr,struct whens *p_whens,s_commands *p_always, int block_id) {
struct command *c;
   c=new_command(E_CMD_TODO_CMD);
   c->cmd_data.command_data_u.todo_cmd.todo_expr=p_todo_expr;
   c->cmd_data.command_data_u.todo_cmd.whens=p_whens;
   c->cmd_data.command_data_u.todo_cmd.always=p_always;
   c->cmd_data.command_data_u.todo_cmd.block_id=block_id;
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

struct command *new_foreach_cmd(expr_str *p_connid, expr_str * p_cursorname,expr_str_list* p_inputvals,expr_str_list* p_outputvals,s_commands *p_cmds) {
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

struct command *new_foreach_with_select_cmd(expr_str *p_connid, s_select * select,s_commands *p_cmds) {
struct command *c;
   c=new_command(E_CMD_FOREACH_WITH_SELECT_CMD);
   c->cmd_data.command_data_u.foreach_with_select_cmd.select=select;
   c->cmd_data.command_data_u.foreach_with_select_cmd.foreach_commands=p_cmds;
   c->cmd_data.command_data_u.foreach_with_select_cmd.block_id=get_block_no(A4GL_get_ccnt());
   c->cmd_data.command_data_u.foreach_with_select_cmd.connid=p_connid;
   return c;
}

struct command *new_connect_cmd(struct expr_str *p_dbname,struct expr_str *p_conn_name,struct expr_str *p_username,struct expr_str *p_password,struct expr_str *p_sqltype) {
struct command *c;
   c=new_command(E_CMD_CONNECT_CMD);
   c->cmd_data.command_data_u.connect_cmd.conn_dbname=p_dbname;
   c->cmd_data.command_data_u.connect_cmd.conn_name=p_conn_name;
   c->cmd_data.command_data_u.connect_cmd.username=p_username;
   c->cmd_data.command_data_u.connect_cmd.password=p_password;
   c->cmd_data.command_data_u.connect_cmd.sqltype=p_sqltype;
   return c;
}
























struct command *new_input_cmd(expr_str_list* p_variables,fh_field_list* p_field_list,struct on_events* p_events,struct attrib *p_attrib,e_boolean p_without_defaults,int p_helpno,int p_sio) {
struct command *c;
   c=new_command(E_CMD_INPUT_CMD);
	p_variables=expand_variables_in_expr_str_list(p_variables,1,1);
	
   c->cmd_data.command_data_u.input_cmd.variables=p_variables;

if (p_without_defaults==EB_TRUE) {
	inc_var_usage_from_binding_list(p_variables);

}
	inc_var_assigned_from_binding_list(p_variables);
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
			//struct expr_str *f;
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



struct command *new_construct_cmd(e_boolean byname, expr_str* p_constr_var,cons_list* p_columns,fh_field_list* p_list,struct on_events* p_events,struct attrib *p_attrib,e_boolean p_without_defaults,int p_helpno,int p_sio, expr_str *p_callback_function) {

struct command *c;
   c=new_command(E_CMD_CONSTRUCT_CMD);
   c->cmd_data.command_data_u.construct_cmd.by_name=byname;
   c->cmd_data.command_data_u.construct_cmd.constr_var=p_constr_var;
   c->cmd_data.command_data_u.construct_cmd.con_columns=p_columns;

   inc_var_assigned( p_constr_var);

        if (p_list==0) {
                int a;
                struct fh_field_list *fl;
                struct fh_field_entry *fe=0;
                //struct variable_usage *vu;
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
   c->cmd_data.command_data_u.construct_cmd.callback_function=p_callback_function;

   return c;
}


static int find_slice(expr_str *arr, char *s, int w) {
struct variable *v;
//int dtype=0;
//int size=0;
//int is_array=0;
char buff[256];
char *ptr;
int a;
enum e_scope scope;
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
if (p_without_defaults==EB_TRUE) {
	inc_var_usage(p_arrayname);
}
	inc_var_assigned(p_arrayname);
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
 
struct command *new_set_database_cmd(expr_str* p_dbname,e_boolean p_exclusive,struct expr_str *p_sqltype) {
struct command *c;
   c=new_command(E_CMD_SET_DATABASE_CMD);
   c->cmd_data.command_data_u.set_database_cmd.set_dbname=p_dbname;
   c->cmd_data.command_data_u.set_database_cmd.exclusive_mode=p_exclusive;
   c->cmd_data.command_data_u.set_database_cmd.sqltype=p_sqltype;
   return c;
}
 
struct command *new_whenever_cmd(int p_whencode,char * p_whento) {
struct command *c;

//static int local_last_whencode[10]={-1,-1,-1,-1,-1,-1,-1};
//static char *local_last_whento[10]={0,0,0,0,0,0,0,0,0,0};
//int type;
if (p_whencode==-1 && p_whento==NULL) {
	return NULL;
}

   c=new_command(E_CMD_WHENEVER_CMD);
   c->cmd_data.command_data_u.whenever_cmd.whencode=p_whencode;
   c->cmd_data.command_data_u.whenever_cmd.whento=strdup(p_whento);
   return c;
}

struct command *new_whenever_signal_cmd(int sigtype,char * func_name) {
struct command *c;

   c=new_command(E_CMD_WHENEVER_SIGNAL_CMD);
   c->cmd_data.command_data_u.whenever_signal_cmd.function_name=strdup(func_name);
   c->cmd_data.command_data_u.whenever_signal_cmd.sigtype=sigtype;
   return c;
}
 
struct command *new_skip_cmd(expr_str * p_lines) { //!
struct command *c;
   c=new_command(E_CMD_SKIP_CMD);
   c->cmd_data.command_data_u.skip_cmd.skip_amt=p_lines;
   return c;
}
 
struct command *new_skip_by_cmd(expr_str *p_lines) { //!
struct command *c;
   c=new_command(E_CMD_SKIP_BY_CMD);
   c->cmd_data.command_data_u.skip_by_cmd.skip_amt=p_lines;
   return c;
}
 
struct command *new_skip_to_cmd(expr_str *p_lines) { //!
struct command *c;
   c=new_command(E_CMD_SKIP_TO_CMD);
   c->cmd_data.command_data_u.skip_to_cmd.skip_amt=p_lines;
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
   c->cmd_data.command_data_u.free_rep_cmd.n_namespace=strdup(get_namespace(p_repname));
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


struct command *new_for_cmd(expr_str*var, expr_str* p_start,expr_str* p_end,expr_str* p_step,s_commands *p_commands,int lineno) { //!
struct command *c;
   c=new_command(E_CMD_FOR_CMD);

   c->cmd_data.command_data_u.for_cmd.var=var;
	//inc_var_assigned(var);
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

struct command *new_while_cmd(expr_str* p_expr,s_commands *p_commands) {
struct command *c;
   c=new_command(E_CMD_WHILE_CMD);
   c->cmd_data.command_data_u.while_cmd.while_expr=p_expr;
   c->cmd_data.command_data_u.while_cmd.while_commands=p_commands;
   c->cmd_data.command_data_u.while_cmd.block_id=get_block_no(A4GL_get_ccnt());
   return c;
}





struct command *new_locate_cmd(expr_str_list* p_variables,locate_pos *p_where) {
struct command *c;
int dtype;
char errbuff[256];
int a;
   c=new_command(E_CMD_LOCATE_CMD);
   for (a=0;a<p_variables->list.list_len;a++) {
		if (p_variables->list.list_val[a]->expr_type!=ET_EXPR_VARIABLE_USAGE) {
			a4gl_yyerror("Not a variable");
			return 0;
		}
		dtype=get_variable_dtype_from_variable_usage_expression(errbuff, p_variables->list.list_val[a]) & DTYPE_MASK;
//printf("--->%d\n", p_variables->list.list_val[a]->expr_str_u.expr_variable_usage->datatype);
		switch (dtype) {
			case DTYPE_TEXT:
			case DTYPE_BYTE: break;
			default:
				//  Its not a byte or a text...
				set_yytext(expr_as_string_when_possible(p_variables->list.list_val[a]));
				a4gl_yyerror("Only TEXT and BYTE variables can be located");
			return 0;
		}
	}
   inc_var_usage_from_binding_list(p_variables);
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

struct command *new_return_cmd(expr_str_list *p_retvals,int p_with_resume) {
struct command *c;
   c=new_command(E_CMD_RETURN_CMD);
   c->cmd_data.command_data_u.return_cmd.retvals=p_retvals;
	/* With resume is only used with the SPL target language - as an extension to normal 4gl... */
   c->cmd_data.command_data_u.return_cmd.with_resume=p_with_resume;
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

struct command *new_sql_block_cmd(expr_str *p_connid, expr_str_list* p_list,int convert) {
struct command *c;
   c=new_command(E_CMD_SQL_BLOCK_CMD);
   c->cmd_data.command_data_u.sql_block_cmd.list=p_list;
   c->cmd_data.command_data_u.sql_block_cmd.connid=p_connid;
   c->cmd_data.command_data_u.sql_block_cmd.convert=convert;

//@  FIXME - inc_var_usage

	//inc_var_usage_from_binding_list(p_inbind);
	//inc_var_assigned_from_binding_list(p_outbind);
   return c;
}

struct command *new_if_cmd(if_conds *p_truths,s_commands *p_whenfalse,int else_lineno, int lineno) {
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
	 c=new_command(E_CMD_ENABLE_CMD);
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
	 c=new_command(E_CMD_DISABLE_CMD);
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

int A4GL_check_fcall_for_builtin_functions(expr_str* p_fcall,char *buff,struct expr_str_list* returning,int isFuncCall  ) {
struct builtin_functions_to_check {
	char *fname;
	int nparams;
	int rvals;
} funcs[]={
	{"mdy",3,1},
	{"length",1,1},
	{"weekday",1,1},
	{NULL,0,0}
};

int a;

if (p_fcall->expr_type==ET_EXPR_FCALL) {
	struct s_expr_function_call *fcall;
	fcall= p_fcall->expr_str_u.expr_function_call;
	for (a=0;funcs[a].fname;a++) {
		if (strcmp( funcs[a].fname,fcall->functionname)==0) {
			int np=0;
			if (fcall->parameters ) {
				np=fcall->parameters->list.list_len;
			}
			
			
			if (np !=funcs[a].nparams && funcs[a].nparams!=-1) {
				sprintf(buff,"Builtin function '%s' expects %d parameters but is only being passed in %d.", 
						funcs[a].fname,funcs[a].nparams,fcall->parameters->list.list_len);
				return 0;
			} else {
				return 1;
			}

			if (isFuncCall==0) {
				// Its an expression - so we expect 1 value back...
				if (funcs[a].rvals!=1 && funcs[a].rvals!=-1) {
					sprintf(buff,"Builtin function '%s' returns %d values not 1 values.", 
						funcs[a].fname,funcs[a].rvals);
					return 0;
				} else {
					return 1;
				}
			}


			if (returning==NULL) continue;

			if (returning->list.list_len !=funcs[a].rvals && funcs[a].rvals!=-1) {
				sprintf(buff,"Builtin function '%s' returns %d values not %d.", 
						funcs[a].fname,funcs[a].rvals,returning->list.list_len);
				return 0;
			} else {
				return 1;
			}

		}
	}
	
}
return 1;
}

struct command *new_call_cmd(expr_str* p_fcall,expr_str_list* p_returning) {
struct command *c;
char buff[256];

	c=check_for_member_call_alias(p_fcall,p_returning);
	if (c!=NULL) {
		return c;
	}

	if (!A4GL_check_fcall_for_builtin_functions(p_fcall,buff, p_returning,1)) {
		a4gl_yyerror(buff);
		return NULL;
	}

	if (c==NULL) {
   		c=new_command(E_CMD_CALL_CMD);
   		c->cmd_data.command_data_u.call_cmd.fcall=p_fcall;
   		c->cmd_data.command_data_u.call_cmd.returning=p_returning;
   		add_to_call_list_by_call(c);
	}
   return c;
}



struct command *new_pdf_call_cmd(expr_str* p_fcall,expr_str_list* p_returning) {
struct command *c;
	A4GL_assertion(1,"No longer used?");
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


struct on_event *new_event(e_event event_type, void *data, s_commands *cmds,int lineno) {
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
	case EVENT_BEFORE_CLOSE_FORM:
        case EVENT_BEFORE_INPUT: break; // no extra data...


        case EVENT_ON_IDLE: 		oe->evt_data.event_data_u.idle_n=(int) data; break;

        case EVENT_ON_INTERVAL:		oe->evt_data.event_data_u.interval_n=(int) data; break;
        case EVENT_ON_TIME: 		oe->evt_data.event_data_u.time_n=(int) data; break;

        case EVENT_KEY_PRESS: 		oe->evt_data.event_data_u.slist=(str_list *)data; break;
        case EVENT_ON_ACTION:	 	oe->evt_data.event_data_u.on_action_s=(s_onaction *)data; break;

        case EVENT_ON:	 	oe->evt_data.event_data_u.slist=(str_list *)data; break;
        case EVENT_BEFORE:	 	oe->evt_data.event_data_u.slist=(str_list *)data; break;
        case EVENT_AFTER:	 	oe->evt_data.event_data_u.slist=(str_list *)data; break;

        case EVENT_BEFORE_FIELD:	oe->evt_data.event_data_u.before_after_field=(fh_field_list *)data; break;
        case EVENT_AFTER_FIELD: 	oe->evt_data.event_data_u.before_after_field=(fh_field_list *)data; break;
        case EVENT_ON_CHANGE: 	oe->evt_data.event_data_u.before_after_field=(fh_field_list *)data; break;
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
	inc_var_assigned(p_promptvar);
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
struct expr_str * menu_attrib_comment,struct expr_str *menu_attrib_style, struct expr_str *menu_attrib_image,
struct expr_str *menu_attrib_normal,
struct expr_str *menu_attrib_highlight
) {
struct command *c;
   c=new_command(E_CMD_MENU_CMD);
   c->cmd_data.command_data_u.menu_cmd.menu_title=p_menu_title;
   c->cmd_data.command_data_u.menu_cmd.menu_attrib=p_menu_attrib;

   c->cmd_data.command_data_u.menu_cmd.menu_attrib_comment=menu_attrib_comment;
   c->cmd_data.command_data_u.menu_cmd.menu_attrib_style=menu_attrib_style;
   c->cmd_data.command_data_u.menu_cmd.menu_attrib_image=menu_attrib_image;
   c->cmd_data.command_data_u.menu_cmd.menu_attrib_normal=menu_attrib_normal;
   c->cmd_data.command_data_u.menu_cmd.menu_attrib_highlight=menu_attrib_highlight;
	
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
	case E_CLR_STATUS: c->cmd_data.command_data_u.clear_cmd.clr_data.clear_data_u.window=(expr_str *)data; break;
	case E_CLR_FIELDS: c->cmd_data.command_data_u.clear_cmd.clr_data.clear_data_u.fields=data; break;
	case E_CLR_FIELDS_TO_DEFAULT: c->cmd_data.command_data_u.clear_cmd.clr_data.clear_data_u.fields=data; break;
   }
return c;
}

struct command *new_convert_cmd(char * p_repname,struct convert* p_c) {
struct command *c;
   c=new_command(E_CMD_CONVERT_CMD);
   c->cmd_data.command_data_u.convert_cmd.repname=strdup(p_repname);
   c->cmd_data.command_data_u.convert_cmd.n_namespace=strdup(get_namespace(p_repname));
   c->cmd_data.command_data_u.convert_cmd.conv_c=p_c;
   return c;
}


struct report_format_section_entry* new_report_format_section_entry(report_blocks rb, void *variable, s_commands* cmds, int orderby_var_no,int lineno) {
	struct report_format_section_entry*r;
	r=malloc(sizeof(struct report_format_section_entry));
	memset(r,0,sizeof(report_format_section_entry));
	r->rb_block.rb=rb;
	r->orderby_var_no=orderby_var_no;
	r->lineno=lineno;
	if (rb==RB_BEFORE_GROUP_OF) {
		r->rb_block.report_block_data_u.f_variable=variable;
	}
	if (rb==RB_AFTER_GROUP_OF) {
		r->rb_block.report_block_data_u.f_variable=variable;
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
   c->cmd_data.command_data_u.output_cmd.n_namespace=strdup(get_namespace(p_reportname));
   c->cmd_data.command_data_u.output_cmd.expressions=p_expressions;

   		add_to_call_list_by_call(c);

   return c;
}


struct s_report_orderby_section *new_report_orderby_section(e_report_orderby p_type,expr_str_list* p_variables) {
struct s_report_orderby_section *c;
	c=malloc(sizeof(s_report_orderby_section));
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
	// These are C functions so wont be namespaced...
		strcpy(buff, p_funcname);

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


struct module_entry *new_import_package(char *package ,int lineno) {
struct module_entry *c;
   c=new_module_entry(E_MET_IMPORT_PACKAGE);
   c->module_entry_u.import_package_definition.package_name=strdup(package);
   c->module_entry_u.import_package_definition.module=A4GL_compiling_module_basename();
   c->module_entry_u.import_package_definition.lineno=lineno;
   return c;
}

struct module_entry *new_import_datatype(char *dtype_name ,int lineno) {
struct module_entry *c;
   c=new_module_entry(E_MET_IMPORT_DATATYPE);
   c->module_entry_u.import_datatype_definition.dtype_name=strdup(dtype_name);
   c->module_entry_u.import_datatype_definition.module=A4GL_compiling_module_basename();
   c->module_entry_u.import_datatype_definition.usedDtypeNumber=A4GL_find_datatype(upshift(c->module_entry_u.import_datatype_definition.dtype_name));
   c->module_entry_u.import_datatype_definition.lineno=lineno;
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

        c->module_entry_u.formhandler_definition.variables.variables.variables_len=0;
        c->module_entry_u.formhandler_definition.variables.variables.variables_val=NULL;
        c->module_entry_u.formhandler_definition.variables.sorted_list=0;
	
	

	return  c;
}


struct module_entry *new_function_definition(char * p_funcname,e_function_type p_type,expr_str_list* p_parameters,s_commands* p_commands,int lineno,char *doc4glcomment) {
struct module_entry *c;
//int a;
   c=new_module_entry(E_MET_FUNCTION_DEFINITION);
   c->module_entry_u.function_definition.funcname=strdup(p_funcname);
   c->module_entry_u.function_definition.n_namespace=strdup(get_namespace(p_funcname));
   c->module_entry_u.function_definition.function_type=p_type;
   c->module_entry_u.function_definition.variables.variables.variables_len=0;
   c->module_entry_u.function_definition.variables.sorted_list=0;
   c->module_entry_u.function_definition.variables.variables.variables_val=NULL;
   c->module_entry_u.function_definition.expression_list.list.list_len=0;
   c->module_entry_u.function_definition.expression_list.list.list_val=0;
   c->module_entry_u.function_definition.expression_list.unexpanded_list.list.list_len=0;
   c->module_entry_u.function_definition.expression_list.unexpanded_list.list.list_val=0;
   c->module_entry_u.function_definition.extra_warnings.extra_warnings_len=0;
   c->module_entry_u.function_definition.extra_warnings.extra_warnings_val=0;
   c->module_entry_u.function_definition.comment=doc4glcomment;

   A4GL_ensure_dtype_variables(p_parameters);
   if (p_parameters==0) {
		p_parameters=malloc(sizeof(struct expr_str_list));
		p_parameters->list.list_len=0;
		p_parameters->list.list_val=0;
		p_parameters->unexpanded_list.list.list_len=0;
		p_parameters->unexpanded_list.list.list_val=0;
    }
   c->module_entry_u.function_definition.parameters=p_parameters;
   c->module_entry_u.function_definition.expanded_parameters=0;

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




struct module_entry *new_main_definition(s_commands* p_commands,int lineno,char *doc4glcomment) {
struct module_entry *c;
   c=new_module_entry(E_MET_MAIN_DEFINITION);
   c->module_entry_u.function_definition.funcname=strdup("MAIN");
   c->module_entry_u.function_definition.n_namespace=strdup(get_namespace("MAIN"));
   c->module_entry_u.function_definition.function_type=E_FTYPE_NORMAL;
   c->module_entry_u.function_definition.variables.variables.variables_len=0;
   c->module_entry_u.function_definition.variables.variables.variables_val=NULL;
   c->module_entry_u.function_definition.variables.sorted_list=0;
   c->module_entry_u.function_definition.parameters=0;
   c->module_entry_u.function_definition.expanded_parameters=0;
   c->module_entry_u.function_definition.func_commands=p_commands;
   c->module_entry_u.function_definition.module=A4GL_compiling_module_basename();
   c->module_entry_u.function_definition.lineno=lineno;
   c->module_entry_u.function_definition.expression_list.list.list_len=0;
   c->module_entry_u.function_definition.expression_list.list.list_val=0;
   c->module_entry_u.function_definition.expression_list.unexpanded_list.list.list_len=0;
   c->module_entry_u.function_definition.expression_list.unexpanded_list.list.list_val=0;
   c->module_entry_u.function_definition.comment=doc4glcomment;
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



struct command * new_pdf_specific_cmd (char *p_type, struct expr_str_list *return_values, ...)
{
  struct command *c;
  struct expr_str_list *parameters = NULL;
  struct expr_str *parameter;
  struct expr_str *function_call_expr;
  va_list ap;
  char buff[200];
  va_start (ap, return_values);

 if (rep_type==REP_TYPE_NORMAL) {
	a4gl_yyerror("You can't use this command is a normal REPORT");
	return NULL;
 }
  // Firstly - lets collect any parameters...
  parameters = A4GL_new_ptr_list (NULL);
  while (1)
    {
      parameter = va_arg (ap, expr_str*);
      if (parameter == NULL)
	break;
      parameters = A4GL_new_append_ptr_list (parameters, parameter);
    }

  va_end(ap);
  sprintf(buff,"\"%s\"", p_type);

  // Now - create an expression for the function call...
  function_call_expr = A4GL_new_expr_pdf_fcall (buff,parameters,A4GL_compiling_module_basename (),yylineno,get_namespace(buff));

  // Now - create the function call itself
  c=new_call_cmd(chk_expr(function_call_expr),return_values);

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

static int
check_for_non_parameter_variables (expr_str_list * p_parameters, expr_str_list * exprs,int lineno)
{
  int a;
  // Go through all the expressions looking for any VARIABLE_USAGE
  for (a = 0; a < exprs->list.list_len; a++)
    {
      if (exprs->list.list_val[a]->expr_type == ET_EXPR_VARIABLE_USAGE)
	{
	  // Got a variable usage
	  // as a quick hack - get the variable as a string
	  // and check it against the string parameter name we have..
	  char *str = cmds_get_variable_usage_as_string (exprs->list.list_val[a]->expr_str_u.expr_variable_usage);
	  char *ptr;
	  ptr = strchr (str, '[');
	  if (ptr)
	    *ptr = 0;
	  ptr = strchr (str, '.');
	  if (ptr)
	    *ptr = 0;
	  int b;
	  int ok=0;
	  for (b = 0; b < p_parameters->list.list_len; b++)
	    {

	      if (strcmp (p_parameters->list.list_val[b]->expr_str_u.expr_param.expr_string, str) == 0)
		{
		  ok = 1;
		  break;
		}

	    }
	  free (str);
	  if (!ok) {
	  	char *str = cmds_get_variable_usage_as_string (exprs->list.list_val[a]->expr_str_u.expr_variable_usage);
		char buff[100000];
		int n;
		n=yylineno;
		yylineno=lineno;
			sprintf(buff,"Possibly dangerous variable usage in aggregate (%s)",str);
			A4GL_warn(buff);
		yylineno=n;
	  }
	}
    }
  return 0;
}

static void check_agg_for_non_parameter_variables(expr_str_list* p_parameters, expr_str_ptr* aggregateExpressions, int aggregateExpressions_len) {
	int a;
	for (a=0;a<aggregateExpressions_len;a++) {
		if (aggregateExpressions[a]->expr_type==ET_EXPR_AGGREGATE)  {
			 struct s_expr_agg *expr_agg;
			expr_agg=aggregateExpressions[a]->expr_str_u.expr_agg;
			expr_str_list l;
			l.list.list_len=0;
			l.list.list_val=0;
			if (expr_agg->agg_expr) {
			 	linearise_expression(&l, expr_agg->agg_expr);
			} 
			if ( expr_agg->expr_where) {
			 	linearise_expression(&l, expr_agg->expr_where);
			}
			check_for_non_parameter_variables(p_parameters, &l, expr_agg->lineno);
		} else {
			A4GL_debug("Odd - expecting an aggregate..");
		}
	}
}

struct module_entry *new_pdf_report_definition(char * p_funcname,e_function_type p_function_type,expr_str_list* p_parameters,pdf_startrep* p_report_output_section,s_report_orderby_section *p_report_orderby_section,report_format_section *p_report_format_section,int lineno ,char *doc4glcomment) {
struct module_entry *c;
   c=new_module_entry(E_MET_PDF_REPORT_DEFINITION);
   c->module_entry_u.pdf_report_definition.funcname=strdup(p_funcname);
   c->module_entry_u.pdf_report_definition.n_namespace=strdup(get_namespace(p_funcname));
   c->module_entry_u.pdf_report_definition.function_type=p_function_type;
   c->module_entry_u.pdf_report_definition.comment=doc4glcomment;

   A4GL_ensure_dtype_variables(p_parameters);
   if (p_parameters==0) {
		p_parameters=malloc(sizeof(struct expr_str_list));
		p_parameters->list.list_len=0;
		p_parameters->list.list_val=0;
		p_parameters->unexpanded_list.list.list_len=0;
		p_parameters->unexpanded_list.list.list_val=0;
    }


   c->module_entry_u.pdf_report_definition.parameters=p_parameters;
   c->module_entry_u.pdf_report_definition.report_output_section=p_report_output_section;
   c->module_entry_u.pdf_report_definition.report_orderby_section=p_report_orderby_section;
   if (p_report_orderby_section) {
		expand_variables_in_expr_str_list(p_report_orderby_section->variables,1,1);
   }
   c->module_entry_u.pdf_report_definition.reportFormatSection=p_report_format_section;
   c->module_entry_u.pdf_report_definition.module=A4GL_compiling_module_basename();
   c->module_entry_u.pdf_report_definition.lineno=lineno;
   c->module_entry_u.pdf_report_definition.colno=0;
   c->module_entry_u.pdf_report_definition.lastlineno=yylineno;
   c->module_entry_u.pdf_report_definition.expression_list.list.list_len=0;
   c->module_entry_u.pdf_report_definition.expression_list.list.list_val=0;
   c->module_entry_u.pdf_report_definition.expression_list.unexpanded_list.list.list_len=0;
   c->module_entry_u.pdf_report_definition.expression_list.unexpanded_list.list.list_val=0;
	c->module_entry_u.pdf_report_definition.extra_warnings.extra_warnings_len=0;
	c->module_entry_u.pdf_report_definition.extra_warnings.extra_warnings_val=0;
  //this_module.expression_list.expression_list_val=0;
   c->module_entry_u.report_definition.aggregates.list.list_len=list_of_aggregates.list.list_len;
   c->module_entry_u.report_definition.aggregates.list.list_val=list_of_aggregates.list.list_val;

   if (A4GL_isyes(acl_getenv("A4GL_WARNAGG"))) {
    check_agg_for_non_parameter_variables(p_parameters, list_of_aggregates.list.list_val, list_of_aggregates.list.list_len);
  }

   c->module_entry_u.report_definition.aggregates.unexpanded_list.list.list_len=list_of_aggregates.unexpanded_list.list.list_len;
   c->module_entry_u.report_definition.aggregates.unexpanded_list.list.list_val=list_of_aggregates.unexpanded_list.list.list_val;
	list_of_aggregates.list.list_len=0;
	list_of_aggregates.list.list_val=0;
	list_of_aggregates.unexpanded_list.list.list_len=0;
	list_of_aggregates.unexpanded_list.list.list_val=0;
   c->module_entry_u.report_definition.variables.variables.variables_len=0;
   c->module_entry_u.report_definition.variables.variables.variables_val=NULL;
   c->module_entry_u.report_definition.variables.sorted_list=0;

   c->module_entry_u.pdf_report_definition.call_list.calls_by_call.calls_by_call_len=this_functions_call_list->calls_by_call.calls_by_call_len;
   c->module_entry_u.pdf_report_definition.call_list.calls_by_call.calls_by_call_val=this_functions_call_list->calls_by_call.calls_by_call_val;
   c->module_entry_u.pdf_report_definition.call_list.calls_by_expr.calls_by_expr_len=this_functions_call_list->calls_by_expr.calls_by_expr_len;
   c->module_entry_u.pdf_report_definition.call_list.calls_by_expr.calls_by_expr_val=this_functions_call_list->calls_by_expr.calls_by_expr_val;
	A4GL_set_extra_warnings( &c->module_entry_u.pdf_report_definition.extra_warnings.extra_warnings_len, &c->module_entry_u.pdf_report_definition.extra_warnings.extra_warnings_val);
   return c;
}


struct module_entry *new_report_definition(char * p_funcname,e_function_type p_function_type,expr_str_list* p_parameters,startrep* p_report_output_section,s_report_orderby_section *p_report_orderby_section,report_format_section *p_report_format_section,int lineno,char *doc4glcomment) {
struct module_entry *c;
   c=new_module_entry(E_MET_REPORT_DEFINITION);
   c->module_entry_u.report_definition.funcname=strdup(p_funcname);
   c->module_entry_u.report_definition.n_namespace=strdup(get_namespace(p_funcname));
   c->module_entry_u.report_definition.function_type=p_function_type;
   c->module_entry_u.report_definition.comment=doc4glcomment;

   A4GL_ensure_dtype_variables(p_parameters);
   if (p_parameters==0) {
		p_parameters=malloc(sizeof(struct expr_str_list));
		p_parameters->list.list_len=0;
		p_parameters->list.list_val=0;
		p_parameters->unexpanded_list.list.list_len=0;
		p_parameters->unexpanded_list.list.list_val=0;
    }
   c->module_entry_u.report_definition.parameters=p_parameters;

   if (p_report_orderby_section) {
		expand_variables_in_expr_str_list(p_report_orderby_section->variables,1,1);
   }
	
   c->module_entry_u.report_definition.aggregates.list.list_len=list_of_aggregates.list.list_len;
   c->module_entry_u.report_definition.aggregates.list.list_val=list_of_aggregates.list.list_val;


   if (A4GL_isyes(acl_getenv("A4GL_WARNAGG"))) {
   	check_agg_for_non_parameter_variables(p_parameters, list_of_aggregates.list.list_val, list_of_aggregates.list.list_len);
   }


	list_of_aggregates.list.list_len=0;
	list_of_aggregates.list.list_val=0;
   c->module_entry_u.report_definition.aggregates.unexpanded_list.list.list_len=list_of_aggregates.unexpanded_list.list.list_len;
   c->module_entry_u.report_definition.aggregates.unexpanded_list.list.list_val=list_of_aggregates.unexpanded_list.list.list_val;
	list_of_aggregates.unexpanded_list.list.list_len=0;
	list_of_aggregates.unexpanded_list.list.list_val=0;

   c->module_entry_u.report_definition.report_output_section=p_report_output_section;
   c->module_entry_u.report_definition.report_orderby_section=p_report_orderby_section;
   c->module_entry_u.report_definition.reportFormatSection=p_report_format_section;
   c->module_entry_u.report_definition.module=A4GL_compiling_module_basename();
   c->module_entry_u.report_definition.lineno=lineno;
   c->module_entry_u.report_definition.colno=0;
   c->module_entry_u.report_definition.lastlineno=yylineno;
   c->module_entry_u.report_definition.expression_list.list.list_len=0;
   c->module_entry_u.report_definition.expression_list.list.list_val=0;
   c->module_entry_u.report_definition.expression_list.unexpanded_list.list.list_len=0;
   c->module_entry_u.report_definition.expression_list.unexpanded_list.list.list_val=0;
	c->module_entry_u.report_definition.extra_warnings.extra_warnings_len=0;
	c->module_entry_u.report_definition.extra_warnings.extra_warnings_val=0;
   c->module_entry_u.report_definition.variables.variables.variables_len=0;
   c->module_entry_u.report_definition.variables.variables.variables_val=NULL;
   c->module_entry_u.report_definition.variables.sorted_list=0;

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

static struct ilist *generate_ilist_from_variable_usage(struct variable_usage *u) {
	struct ilist *ilist=0;
	if (u->subscripts.subscripts_len) {
		int a;
		ilist=malloc(sizeof(struct ilist));
		ilist->i0=u->subscripts.subscripts_len; ilist->i1=-1; ilist->i2=-1; ilist->i3=-1; ilist->i4=-1; ilist->i5=-1;
		for (a=0;a<u->subscripts.subscripts_len;a++) {
			long l;
			A4GL_assertion(u->subscripts.subscripts_val[a]==0,"Expecting an expression");
			if (u->subscripts.subscripts_val[a]->expr_type!=ET_EXPR_LITERAL_LONG) {
				a4gl_yyerror("You can only use a literal number in this context");
				return 0;
			}
			l=u->subscripts.subscripts_val[a]->expr_str_u.expr_long;
			switch (a) {
				case 0 : ilist->i1=l; break;
				case 1 : ilist->i2=l; break;
				case 2 : ilist->i3=l; break;
				case 3 : ilist->i4=l; break;
				case 4 : ilist->i5=l; break;
			}
		}
	//printf("%d %d %d %d %d\n", ilist->i0,ilist->i1,ilist->i2,ilist->i3,ilist->i4);
	}
	return ilist;
}


struct expr_str *generate_sql_expr(struct expr_str *p) {
char *ident;
//char buff[2000];
struct variable_usage *u;
struct expr_str *rval=0;
if (!is_valid_identifier(p))  return 0;
A4GL_assertion(p->expr_type!=ET_EXPR_VARIABLE_USAGE,"Expecting a variable usage") ;
u=p->expr_str_u.expr_variable_usage;

if (u->next==0) { // Looks simple enough..
	struct s_select_list_item *i;
	char *s;
	s=u->variable_name;
	if (strcmp(s,"a4gl_status")==0) { s="status"; }
	if (strcmp(s,"a4gl_sqlca")==0) { s="sqlca"; }
	i=new_select_list_item_col(0, s, generate_ilist_from_variable_usage(u));
	rval=A4GL_new_select_list_item_expr(i);
}
if (u->next!=0 && u->next->next==0) {  // Table.column 
	struct s_select_list_item *i;
	struct variable_usage *tab;
	struct variable_usage *col;
	tab=u;
	col=u->next;
	if (tab->subscripts.subscripts_len) {
		a4gl_yyerror("You cant use subscripts here");
		return 0;
	}
	i=new_select_list_item_col(tab->variable_name, col->variable_name, generate_ilist_from_variable_usage(col));
	rval=A4GL_new_select_list_item_expr(i);
}


if (rval==0) {
	ident=get_id_from_variable_usage_expression(p);
	rval=A4GL_new_expr_simple_string(ident, ET_EXPR_IDENTIFIER);
}
return rval;
}



struct command *set_cmd_comment(struct command *cmd,char *s) {
	if (s) {
		cmd->comment=s;
	}
	return cmd;
}


struct command *set_cmd_errors(struct command *cmd,struct cmd_int_list *ilist) {
	if (ilist && cmd->cmd_data.type==E_CMD_RETURN_CMD) {
		a4gl_yyerror("You cannot use an IGNORE ERRORS .. on a RETURN");
		return cmd;
	}
	cmd->ignore_error_list=ilist;
	return cmd;
}

void set_module_comment(char *s) {
	// does nothing yet
}


struct cmd_int_list *new_cmd_int_list(void) {
struct  cmd_int_list *n;
n=malloc(sizeof(cmd_int_list));
n->int_vals.int_vals_len=0;
n->int_vals.int_vals_val=NULL;
return n;
}

void append_cmd_int_list(struct cmd_int_list *list, int l) {
list->int_vals.int_vals_len++;
list->int_vals.int_vals_val=realloc(list->int_vals.int_vals_val, sizeof(list->int_vals.int_vals_val[0])*list->int_vals.int_vals_len);
list->int_vals.int_vals_val[list->int_vals.int_vals_len-1]=l;
}


int has_cmd_int_list(struct cmd_int_list *list, int l) {
int a;
if (list==NULL) return 0;
for (a=0;a<list->int_vals.int_vals_len;a++) {
	if ( list->int_vals.int_vals_val[0]==l) return 1;
}
return 0;
}


struct list_of_integers *append_list_of_integers(struct list_of_integers *p, int a) {
	p->list.list_len++;
	p->list.list_val=realloc(p->list.list_val, sizeof(p->list.list_val[0]*p->list.list_len));
	p->list.list_val[p->list.list_len-1]=a;
	return p;
}

struct list_of_integers *new_list_of_integers(int a) {
	struct list_of_integers *p;
	p=malloc(sizeof(struct list_of_integers));
	p->list.list_val=0;
	p->list.list_len=0;
	append_list_of_integers(p,a);
	return p;
}

// SPL stuff...
struct create_proc_data*set_spl_proc_name(struct create_proc_data *cpd, char *name,int isDba) {
	cpd->funcname=strdup(name);
	if (isDba) {
		cpd->isDBA=EB_TRUE;
	} else {
		cpd->isDBA=EB_FALSE;
	}
	return cpd;
}

struct create_proc_data* new_spl_proc(struct variable_list* parameters, struct variable_list *returning, struct s_spl_block *block,expr_str_list *document, expr_str *listing) {
	struct create_proc_data* cpd;
	cpd=malloc(sizeof(struct create_proc_data));
	cpd->funcname=NULL;

	cpd->params.parameters.parameters_len=0;
	cpd->params.parameters.parameters_val=NULL;
	if (parameters!=NULL) {
		cpd->params.parameters.parameters_len=parameters->variables.variables_len;
		cpd->params.parameters.parameters_val=parameters->variables.variables_val;
	}

	cpd->returning.returning.returning_len=0;
	cpd->returning.returning.returning_val=NULL;
	if (returning!=NULL) {
		cpd->returning.returning.returning_len=returning->variables.variables_len;
		cpd->returning.returning.returning_val=returning->variables.variables_val;
	}

	cpd->block=block;
	cpd->document=document;
	cpd->listing=listing;
	cpd->isDBA=EB_FALSE;


	return cpd;
}

struct s_spl_execute * new_spl_execute(char *proc_name, struct expr_str_list* parameters) {
	struct s_spl_execute *p;
	p=malloc(sizeof(struct s_spl_execute));
	p->proc_name=strdup(proc_name);
	p->parameters=parameters;
	return p;
}




struct variable *new_references_blobtype(char *reftype, expr_str *default_value){
	struct variable *v;
	if (strstr(reftype,"text") || strstr(reftype,"TEXT")) {
		v=new_simple_variable(NULL, DTYPE_TEXT,0,0);
	} else {
		v=new_simple_variable(NULL, DTYPE_BYTE,0,0);
	}
	set_variable_default(v,default_value);
	return v;
}

void set_variable_default (variable *v, expr_str *defaultValue) {
	if (v==NULL || defaultValue==NULL) return;
	if (v->var_data.variable_type==VARIABLE_TYPE_SIMPLE) {
		v->var_data.variable_data_u.v_simple.defaultvalue=defaultValue;
	} else {
		a4gl_yyerror("You cant set the default value for anything other than a simple variable");
	}
}

struct s_spl_block *new_spl_block(struct variable_list*defines, struct s_commands * commands ) {
struct s_spl_block *p;
	p=malloc(sizeof(struct s_spl_block));
	p->variables.sorted_list=0;
	if (defines) {
		p->variables.variables.variables_len=defines->variables.variables_len;
		p->variables.variables.variables_val=defines->variables.variables_val;
	} else {
		p->variables.variables.variables_len=0;
		p->variables.variables.variables_val=NULL;
	}
	p->commands=commands;
	return p;
}



// --------------------------------------------------------------------------------
//
struct command *new_spl_system_cmd (expr_str *p_cmd) {
   struct command *c;
   c=new_command(E_CMD_SPL_SYSTEM_CMD);
   c->cmd_data.command_data_u.spl_system_cmd.cmd=p_cmd;
   return c;
}

struct command *new_spl_raise_exception_cmd(expr_str *sql_err, expr_str *isam_err, expr_str *err_text) {
   struct command *c;
   c=new_command(E_CMD_SPL_RAISE_EXCEPTION_CMD);
   c->cmd_data.command_data_u.spl_raise_exception_cmd.sql_err =sql_err ;
   c->cmd_data.command_data_u.spl_raise_exception_cmd.isam_err =isam_err ;
   c->cmd_data.command_data_u.spl_raise_exception_cmd.err_text =err_text ;
   return c;
}

struct command *new_spl_on_exception_cmd(list_of_integers *exception_list,str_list * set_list, struct s_spl_block *block, int resume ) {
   struct command *c;
   c=new_command(E_CMD_SPL_ON_EXCEPTION_CMD);
   c->cmd_data.command_data_u.spl_on_exception_cmd.exception_list=exception_list ;
   c->cmd_data.command_data_u.spl_on_exception_cmd.set_list=set_list ;
   c->cmd_data.command_data_u.spl_on_exception_cmd.block=block;
   c->cmd_data.command_data_u.spl_on_exception_cmd.resume=resume;

   return c;
}

struct command *new_spl_return_cmd(expr_str_list *rvals, int withResume) {
   struct command *c;
   c=new_command(E_CMD_SPL_RETURN_CMD);
   c->cmd_data.command_data_u.spl_return_cmd. rvals=  rvals ;
   c->cmd_data.command_data_u.spl_return_cmd. withResume=  withResume ;
   return c;
}

struct command *new_spl_trace_cmd(expr_str *trace_type ) {
   struct command *c;
   c=new_command(E_CMD_SPL_TRACE_CMD);
   c->cmd_data.command_data_u.spl_trace_cmd.trace_expr =trace_type ;
   return c;
}

struct command *new_spl_foreach_execute_cmd(struct s_spl_execute *proc, str_list *into_vars, struct s_spl_block *block ) {
   struct command *c;
   c=new_command(E_CMD_SPL_FOREACH_EXECUTE_CMD);
   c->cmd_data.command_data_u.spl_foreach_execute_cmd.fcall  = proc  ;
   c->cmd_data.command_data_u.spl_foreach_execute_cmd.into_vars  = into_vars  ;
   c->cmd_data.command_data_u.spl_foreach_execute_cmd.block  = block  ;
   return c;
}

struct command *new_spl_foreach_select_cmd( char *cursorname, int withHold, struct s_select *p_select, struct s_spl_block *block) {
   struct command *c;
   c=new_command(E_CMD_SPL_FOREACH_SELECT_CMD);
   if (cursorname==NULL) cursorname="";
   c->cmd_data.command_data_u.spl_foreach_select_cmd.cursorName  = cursorname  ;
   c->cmd_data.command_data_u.spl_foreach_select_cmd.withHold  = withHold  ;
   c->cmd_data.command_data_u.spl_foreach_select_cmd.select_stmt  =p_select   ;
   c->cmd_data.command_data_u.spl_foreach_select_cmd.block  = block  ;
   return c;
}

struct command *new_spl_while_cmd(expr_str *expr, struct s_spl_block *block ) {
   struct command *c;
   c=new_command(E_CMD_SPL_WHILE_CMD);
   c->cmd_data.command_data_u.spl_while_cmd.condition =expr   ;
   c->cmd_data.command_data_u.spl_while_cmd.block     =block   ;
   return c;
}

struct command *new_spl_fcall_cmd( struct s_spl_execute *proc, str_list *returning) {
   struct command *c;
   c=new_command(E_CMD_SPL_CALL_CMD);
   c->cmd_data.command_data_u.spl_call_cmd.fcall  = proc  ;
   c->cmd_data.command_data_u.spl_call_cmd.return_variables  = returning  ;
   return c;
}

struct command *new_spl_block_cmd(struct s_spl_block *block ) {
   struct command *c;
   c=new_command(E_CMD_SPL_BLOCK_CMD);
   c->cmd_data.command_data_u.spl_block_cmd.block =  block ;
   return c;
}

struct command *new_spl_for_cmd(char *vname, expr_str_list *list, struct s_spl_block *block ) {
   struct command *c;
   c=new_command(E_CMD_SPL_FOR_CMD);
   c->cmd_data.command_data_u.spl_for_cmd.vname  = vname  ;
   c->cmd_data.command_data_u.spl_for_cmd.value_list  = list  ;
   c->cmd_data.command_data_u.spl_for_cmd.block  = block  ;
   return c;
}

struct command *new_spl_let_cmd(str_list *vars, expr_str_list *vals) {
   struct command *c;
   c=new_command(E_CMD_SPL_LET_CMD);
   c->cmd_data.command_data_u.spl_let_cmd.vars  =  vars ;
   c->cmd_data.command_data_u.spl_let_cmd.values  =  vals ;
   return c;
}

struct command *new_create_procedure_cmd(expr_str *connid, struct create_proc_data *cpd ) {
   struct command *c;
   c=new_command(E_CMD_CREATE_PROCEDURE_CMD);
   c->cmd_data.command_data_u.create_proc_cmd.connid  =  connid ;
   c->cmd_data.command_data_u.create_proc_cmd.create_proc  =  cpd ;
   return c;
}

struct command *new_spl_if_cmd (spl_if_conds *conditions) {
struct command *c;
struct spl_if_conds *reordered_conditions;
int a;
int b;
   c=new_command(E_CMD_SPL_IF_CMD);
	reordered_conditions=&c->cmd_data.command_data_u.spl_if_cmd.conditions;
	reordered_conditions->conditions.conditions_val=malloc(sizeof(conditions->conditions.conditions_val[0])*conditions->conditions.conditions_len);
	reordered_conditions->conditions.conditions_len=conditions->conditions.conditions_len;

// When we get the list - the list is actually in reverse order (because of the way the parser works)
// So - before we create the IF statement - lets reorder it to how it should be...
	b=reordered_conditions->conditions.conditions_len-1;
	for (a=0;a<reordered_conditions->conditions.conditions_len;a++) {
		
		memcpy(&reordered_conditions->conditions.conditions_val[a], &conditions->conditions.conditions_val[b--], sizeof(spl_if_cond));
	}

   return c;
}


struct spl_if_conds *append_spl_if_conds(struct spl_if_conds *conditions, spl_if_cond *testcase ) {
	if (conditions==0) {
		conditions=malloc(sizeof(struct spl_if_conds));
		conditions->conditions.conditions_len=0;
		conditions->conditions.conditions_val=NULL;
	}
	conditions->conditions.conditions_len++;
	conditions->conditions.conditions_val=realloc(conditions->conditions.conditions_val, sizeof(conditions->conditions.conditions_val[0])*conditions->conditions.conditions_len);
	memcpy(&conditions->conditions.conditions_val[conditions->conditions.conditions_len-1],testcase,sizeof(spl_if_cond));
	return conditions;
}

struct spl_if_cond *new_spl_if_cond (struct expr_str *test_expr, struct s_spl_block *commands ) {
	struct spl_if_cond *p;
	p=malloc(sizeof(struct spl_if_cond));
	p->test_expr=test_expr;
	p->commands=commands;
	return p;
}



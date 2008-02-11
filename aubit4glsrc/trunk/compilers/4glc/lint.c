#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"
#include "a4gl_4glc_int.h"
#include "lint.h"
#include "linearise.h"
expr_str_list *expand_parameters(struct variable_list *var_list, expr_str_list *parameters) ;
int nomain=0;

//expr_str* get_expr_datatype(int n);
extern int yylineno;
static int dbg=0;
char *lint_module=0;
static void load_boltons(char *fname);
static int find_function(char *s) ;
//void log_proto( struct  expr_str *fcall, struct binding_comp_list *ret) ;

//void dump_prototypes(void) ;
//static struct commands * linearise_commands(struct commands *master_list, struct commands *cmds) ;
//static void linearise_commands_from_events(struct commands *master_list, struct on_events* evt_list) ;
static char *get_lint_filename(char *s) ;
static char *local_xml_escape(char *s) ;
static void cache_expressions(struct expr_str_list *list, struct commands *cmds) ;
static void cache_expression(struct expr_str_list *list, struct expr_str **eptr) ;
static void cache_expression_list(struct expr_str_list *list, struct expr_str_list *srclist) ;
extern module_definition this_module;
int expr_datatype (struct expr_str *p);

static void scan_functions(char *infuncname, int calltree_entry,int *calltree, struct call_list *f,struct commands *calling_funcs_commands) ;
static void set_lint_module (char *s) ;

static void check_variable_name(char *modname, char *scope, struct variable *v) ;
static void check_cmds_for_dead_code( struct commands *cmds) ;
//int has_variable (struct variable_list *v, char *name) ;
//int get_lint_style(void) ;
FILE *lintfile=0;

#define PROTO_FUNCTION 		1
#define PROTO_REPORT 		2
#define PROTO_PDF_REPORT 	3

//void A4GL_lint (char *module, int line, char *code, char *type, char *extra);
static char * A4GL_transform_basename (char *s);
//void gen_function_prototypes(int e, struct s_function_definition *function_definition) ;

struct s_function_prototype {
	int proto_type;
	char *pname;
	int nparams;
	int *param_dtypes;
	int nreturns;
	int *return_dtypes;
};

static int system_function(char *funcname) ;
struct s_function_prototype *fprototypes=0;

struct s_function_prototype *fboltons=0;
int nboltons=0;
static int is_bolton_function(char *s) ;


struct global_variable_function {
	char *function;
	char *module;
	int line;
};

struct global_variable_assignement {
	char *varname;
	struct global_variable_function  *function_list;
	int nfunction_list;
};

struct global_variable_assignement *gass=0;
int ngass=0;


int add_global_variable_assignement(char *s,char *currfunc,char *module, int line) {
int a;
// We want to keep a track of all the assignments to global variables
// and flag whenever we have more than one function assigning it a value

// DOnt worry about these ones...
if (strcmp(s,"int_flag")==0) return 0;
if (strcmp(s,"quit_flag")==0) return 0;
if (strcmp(s,"locked")==0) return 0;
if (strcmp(s,"error_occured")==0) return 0;
if (strcmp(s,"err_line")==0) return 0;

	for (a=0;a<ngass;a++) {
		if (strcmp(gass[a].varname,s)==0) {	// we've found it...
			int b;
			//int found=0;
			for (b=0;b<gass[a].nfunction_list;b++) {
				if (strcmp(currfunc, gass[a].function_list[b].function)==0) {return 1;}
			}
			gass[a].nfunction_list++;
			
			gass[a].function_list=realloc(gass[a].function_list,sizeof(struct global_variable_function) * gass[a].nfunction_list);
			gass[a].function_list[gass[a].nfunction_list-1].function=strdup(currfunc);
			gass[a].function_list[gass[a].nfunction_list-1].module=strdup(module);
			gass[a].function_list[gass[a].nfunction_list-1].line=line;
			return 1;
		}
	}
	ngass++;
	gass=realloc(gass, sizeof(gass[0])*ngass);
	gass[ngass-1].varname=strdup(s);
	gass[ngass-1].nfunction_list=1;
	gass[ngass-1].function_list=malloc(sizeof(struct global_variable_function));
	gass[ngass-1].function_list[0].function=strdup(currfunc);
	gass[ngass-1].function_list[0].module=strdup(module);
	gass[ngass-1].function_list[0].line=line;
	
	
	return 0;
}

/*
static void set_assigned_binding_var(struct binding_comp *v,char *currfunc,char *module, int line) {
	if (v->scope=='G' || v->scope=='g') {
			char buff[2000];
			char *ptr;
			strcpy(buff,v->varname);
			ptr=strchr(buff,'[');
			if (ptr) *ptr=0;
			add_global_variable_assignement(buff,currfunc,module,line);
			//printf("ASSIGNMENT OF GLOBALS %s\n",buff);
	}
}

static void set_assigned_binding(struct binding_comp_list *vlist, char *currfunc, char *module, int line) {
int a;
	if (vlist==0) return;
	if (vlist->list.list_len==0) return;
	for (a=0;a<vlist->list.list_len;a++) {
		set_assigned_binding_var(&vlist->list.list_val[a],currfunc,module,line);
	}


	//
}
*/

expr_str_list *expr_cache=0;
static int promoteable(int a, int b) ;

static void set_expr_cache(expr_str_list *n) {
	expr_cache=n;
}

expr_str* get_expr_datatype(int n) {
	A4GL_assertion(expr_cache==0,"No expression cache");
	if (n>expr_cache->list.list_len || n<0) {
			A4GL_assertion(1,"Expression cache subscript out of range");
	}
	return expr_cache->list.list_val[n];
}

char *lint_get_variable_usage_as_string (struct variable_usage *var_usage) {
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
                ptr=lint_get_variable_usage_as_string(var_usage->next);
                strcat(buff, ptr);
                free(ptr);
        }

        return strdup(buff);
}



char *dtype_as_string(int dtype) {
	if (dtype==90) {
		return "Boolean";
	}
	switch (dtype&DTYPE_MASK) {
 		case DTYPE_CHAR      : return "char";
 		case DTYPE_SMINT     : return "smallint";
 		case DTYPE_INT       : return "integer";
 		case DTYPE_FLOAT     : return "float";
 		case DTYPE_SMFLOAT   : return "smallfloat";
 		case DTYPE_DECIMAL   : return "decimal";
 		case DTYPE_SERIAL    : return "serial";
 		case DTYPE_DATE      : return "date";
 		case DTYPE_MONEY     : return "money";
 		case DTYPE_NULL    : return "null";
 		case DTYPE_DTIME     : return "datetime";
 		case DTYPE_BYTE    : return "byte";
 		case DTYPE_TEXT     : return "text";
 		case DTYPE_VCHAR    : return "varchar";
 		case DTYPE_INTERVAL  : return "interval";
 		case DTYPE_NCHAR  : return "nchar";
	}
	return "Unknown";
	
}



static void check_cmds_for_dead_code_from_events(struct on_events *evt_list) {
int a;

if (evt_list==0) return;

for (a=0;a<evt_list->event.event_len;a++) {

	check_cmds_for_dead_code(evt_list->event.event_val[a]->on_event_commands);
}

}


static void check_cmds_for_dead_code( struct commands *cmds) {
int a;
int cnt;
int ignore=0;
int reported=0;
struct on_events* evt_list;

	if (cmds==0) return ;

	for (a=0;a<cmds->cmds.cmds_len;a++) {

		if (ignore && cmds->cmds.cmds_val[a]->cmd_data.type!=E_CMD_WHENEVER_CMD && cmds->cmds.cmds_val[a]->cmd_data.type!=E_CMD_LABEL_CMD) {
			yylineno=cmds->cmds.cmds_val[a]->lineno;
			A4GL_lint (cmds->cmds.cmds_val[a]->module, cmds->cmds.cmds_val[a]->lineno, "DEAD","Dead code detected", 0);
			reported++;
			return;
		}

		switch ( cmds->cmds.cmds_val[a]->cmd_data.type) {
			
			case E_CMD_FOR_CMD:
				check_cmds_for_dead_code(cmds->cmds.cmds_val[a]->cmd_data.command_data_u.for_cmd.for_commands);
				break;
	
			case E_CMD_IF_CMD:
				for (cnt=0;cnt<cmds->cmds.cmds_val[a]->cmd_data.command_data_u.if_cmd.truths.conditions.conditions_len;cnt++) {
					check_cmds_for_dead_code(cmds->cmds.cmds_val[a]->cmd_data.command_data_u.if_cmd.truths.conditions.conditions_val[cnt].whentrue);
				}
				check_cmds_for_dead_code(cmds->cmds.cmds_val[a]->cmd_data.command_data_u.if_cmd.whenfalse);
				break;

			case E_CMD_FOREACH_CMD:
				check_cmds_for_dead_code(cmds->cmds.cmds_val[a]->cmd_data.command_data_u.foreach_cmd.foreach_commands);
				break;
	
			case E_CMD_WHILE_CMD:
				check_cmds_for_dead_code(cmds->cmds.cmds_val[a]->cmd_data.command_data_u.while_cmd.while_commands);
				break;


			case E_CMD_CASE_CMD:
				for (cnt=0;cnt<cmds->cmds.cmds_val[a]->cmd_data.command_data_u.case_cmd.whens->whens.whens_len ;cnt++) {
					check_cmds_for_dead_code(cmds->cmds.cmds_val[a]->cmd_data.command_data_u.case_cmd.whens->whens.whens_val[cnt]->when_commands);
				}
				check_cmds_for_dead_code(cmds->cmds.cmds_val[a]->cmd_data.command_data_u.case_cmd.otherwise);
				break;
	

			case E_CMD_MENU_CMD:
				evt_list=cmds->cmds.cmds_val[a]->cmd_data.command_data_u.menu_cmd.events;
				check_cmds_for_dead_code_from_events(evt_list);
				break;

			case E_CMD_PROMPT_CMD:
				evt_list=cmds->cmds.cmds_val[a]->cmd_data.command_data_u.prompt_cmd.events;
				check_cmds_for_dead_code_from_events(evt_list);
				break;

			case E_CMD_DISPLAY_ARRAY_CMD:
				evt_list=cmds->cmds.cmds_val[a]->cmd_data.command_data_u.display_array_cmd.events;
				check_cmds_for_dead_code_from_events(evt_list);
				break;
	
			case E_CMD_INPUT_CMD:
				evt_list=cmds->cmds.cmds_val[a]->cmd_data.command_data_u.input_cmd.events;
				check_cmds_for_dead_code_from_events(evt_list);
				break;

			case E_CMD_INPUT_ARRAY_CMD:
				evt_list=cmds->cmds.cmds_val[a]->cmd_data.command_data_u.input_array_cmd.events;
				check_cmds_for_dead_code_from_events(evt_list);
				break;
			case E_CMD_CONSTRUCT_CMD:
				evt_list=cmds->cmds.cmds_val[a]->cmd_data.command_data_u.construct_cmd.events;
				check_cmds_for_dead_code_from_events(evt_list);
				break;


			case E_CMD_EXIT_PROG_CMD:
			case E_CMD_CONTINUE_CMD:
			case E_CMD_EXT_CMD:
			case E_CMD_RETURN_CMD:	
			case E_CMD_GOTO_CMD:
				ignore++;
				break;

			case E_CMD_LABEL_CMD: 
				// If we jumped to this label - it'd always be in live code again..
				ignore=0;
				break;

			default : 
				// dont need to do anything - these don't embed Commands..
				break;
		}
		
	}
}






static int is_char_dtype(int dtype) {
dtype=dtype&DTYPE_MASK;
if (dtype==DTYPE_CHAR) return 1;
if (dtype==DTYPE_NCHAR) return 1;
if (dtype==DTYPE_VCHAR) return 1;
return 0;
}



static void check_function_for_complexity(struct module_definition *d, struct s_function_definition *f) {
int ncomments=0;
int a;
struct commands *func_cmds=0;
int flow=0;
for (a=0; a<d->comment_list.comment_list_len;a++) {
	if (d->comment_list.comment_list_val[a].lineno >= f->lineno && d->comment_list.comment_list_val[a].lineno<=f->lastlineno) ncomments++;
}

//printf("%d comments in function\n",ncomments);
//printf("%d lines in function\n",f->lastlineno-  f->lineno);

func_cmds=linearise_commands(0, 0);
linearise_commands(func_cmds, f->func_commands);


for (a=0;a<func_cmds->cmds.cmds_len;a++) {
	switch(func_cmds->cmds.cmds_val[a]->cmd_data.type) {
		case E_CMD_WHILE_CMD:
		case E_CMD_FOR_CMD:
		case E_CMD_FOREACH_CMD:
		case E_CMD_CASE_CMD:
		case E_CMD_IF_CMD:
		case E_CMD_MENU_CMD:
			flow++;
			break;

		default : break;
	}
}
if (flow>10 || f->lastlineno-f->lineno>250) {
	A4GL_lint (f->module, f->lineno, "TOOCOMPLEX","Function is too complex", f->funcname);
}

//printf("V(G)=%d, %d commands, Complexity : %lf\n",flow+1, func_cmds->cmds.cmds_len,(double)(flow)/(double)func_cmds->cmds.cmds_len );

}


static void check_function (struct module_definition *d, struct s_function_definition *f) {
struct commands *func_cmds=0;
struct command *r;
int a;
int b;
int nreturns=0;
int nretvals=0;
char *currfunc;
int local_last_whencode[10]={-1,-1,-1,-1,-1,-1,-1};
char *local_last_whento[10]={0,0,0,0,0,0,0,0,0,0};
        for (a=0;a<10;a++) {
                local_last_whencode[a]=-1;
                local_last_whento[a]=0;
        }

   	check_cmds_for_dead_code(f->func_commands);

currfunc=f->funcname;

   for (a=0;a<f->variables.variables.variables_len;a++) {
		char *localname;
		localname=f->variables.variables.variables_val[a]->names.names.names_val[0].name;

		check_variable_name(d->module_name, "Local", f->variables.variables.variables_val[a]);

		if (has_variable(&d->imported_global_variables, localname)) {
				A4GL_lint (f->module, f->variables.variables.variables_val[a]->lineno, "CS.VARHIDE","Coding Standards: Local variable hides an imported Global variable", f->variables.variables.variables_val[a]->names.names.names_val[0].name);
		}

		if (has_variable(&d->exported_global_variables, localname)) {
				A4GL_lint (f->module, f->variables.variables.variables_val[a]->lineno, "CS.VARHIDE","Coding Standards: Local variable hides an exported Global variable", f->variables.variables.variables_val[a]->names.names.names_val[0].name);
		}
		if (has_variable(&d->module_variables, localname)) {
				A4GL_lint (f->module, f->variables.variables.variables_val[a]->lineno, "CS.VARHIDE","Coding Standards: Local variable hides a Module variable", f->variables.variables.variables_val[a]->names.names.names_val[0].name);
		}

	
		if ( f->variables.variables.variables_val[a]->flags&1) {
                                A4GL_lint (f->module, f->variables.variables.variables_val[a]->lineno, "VARUSED","Local variable is used before its assigned a value", 
			f->variables.variables.variables_val[a]->names.names.names_val[0].name);
		}

		if ( f->variables.variables.variables_val[a]->usage==0 && f->variables.variables.variables_val[a]->assigned==0) {
				A4GL_lint (f->module, f->variables.variables.variables_val[a]->lineno, "VARNOTUSED","Local variable is defined but not used", f->variables.variables.variables_val[a]->names.names.names_val[0].name);
		}

		if ( f->variables.variables.variables_val[a]->usage==0 && f->variables.variables.variables_val[a]->assigned) {
				A4GL_lint (f->module,  f->variables.variables.variables_val[a]->lineno, "VARASSNOTUSED","Local variable is assigned a value but not used",
			f->variables.variables.variables_val[a]->names.names.names_val[0].name);
		}
   }


   func_cmds=linearise_commands(0, 0);
   linearise_commands(func_cmds, f->func_commands);

   cache_expressions(&f->expression_list, func_cmds);

/*
	printf("Here.......................................................... %d\n", f->expression_list.list.list_len);
   for (a=0;a<f->expression_list.list.list_len;a++) {
		if (f->expression_list.list.list_val[a]->expr_type==ET_EXPR_OP_USING){
			printf("Got a using\n");
		}
  }
*/

   set_expr_cache(&f->expression_list);

   // first - check for multiple return paths..
   for (a=0;a<func_cmds->cmds.cmds_len;a++) {
	r=func_cmds->cmds.cmds_val[a];
	yylineno=r->lineno;
	if (r->cmd_data.type==E_CMD_RETURN_CMD) {
		if (nreturns) {
			int nvals;
			yylineno=r->lineno;

			A4GL_lint (f->module, r->lineno, "CS.MRET","Coding Standards: Multiple RETURNs in function", 0);

			//A4GL_lint("Coding Standards: Multiple RETURNs in function");
			
			if (r->cmd_data.command_data_u.return_cmd.retvals) {
				nvals=r->cmd_data.command_data_u.return_cmd.retvals->list.list_len;
			} else {
				nvals=0;
			}
			if (nvals!=nretvals) {
				// Already reported ? 
				/* A4GL_lint (f->module, r->lineno, "MRETVAL","Function RETURNs different numbers of values", 0); */
			}
		} else {
			if (r->cmd_data.command_data_u.return_cmd.retvals) {
				nretvals=r->cmd_data.command_data_u.return_cmd.retvals->list.list_len;
			} else {
				nretvals=0;
			}
			nreturns++;
	
		}
	}
	if (r->cmd_data.type==E_CMD_WHENEVER_CMD) {
		int p_whencode;char * p_whento;
		int type;
		p_whencode=r->cmd_data.command_data_u.whenever_cmd.whencode;
		p_whento=r->cmd_data.command_data_u.whenever_cmd.whento;
		type=p_whencode>>4;

		 if (local_last_whencode[type]==p_whencode) {
                		if (local_last_whento[type]==0 && p_whento==0) {
					A4GL_lint (f->module, r->lineno, "CS.WHENRESET","Resetting WHENEVER ... to same settings", 0);
                        		//A4GL_lint("Coding Standards: Resetting WHENEVER ... to same settings");
                		}

                if (local_last_whento[type]!=0 && p_whento!=0) {
                        if (A4GL_aubit_strcasecmp(local_last_whento[type],p_whento)==0) {
					A4GL_lint (f->module, r->lineno, "CS.WHENRESET","Resetting WHENEVER ... to same settings", 0);
                                //A4GL_lint("Coding Standards: Resetting WHENEVER ... to same settings");
                        }
                }
        	}

	}


	if (r->cmd_data.type==E_CMD_LABEL_CMD) {
		struct command *r2;
		int isused=0;
   		for (b=0;b<func_cmds->cmds.cmds_len;b++) {
			r2=func_cmds->cmds.cmds_val[b];
			if (r2->cmd_data.type==E_CMD_GOTO_CMD) {
				if (A4GL_aubit_strcasecmp(r2->cmd_data.command_data_u.goto_cmd.label,r->cmd_data.command_data_u.label_cmd.label)==0) {
					isused++;
				}
			}
		}
		if (!isused) {
			A4GL_lint (f->module, r->lineno, "LABELNOTUSED","Label defined but not used", r->cmd_data.command_data_u.label_cmd.label);
		}
	}

	if (r->cmd_data.type==E_CMD_IF_CMD) {
		int b;
		struct if_conds *if_c;
		if_c=&r->cmd_data.command_data_u.if_cmd.truths;

		for (b=0;b<if_c->conditions.conditions_len;b++) {
			expr_str *e;
			ensure_bool(if_c->conditions.conditions_val[b].test_expr,0);
			if (A4GL_is_just_int_literal(if_c->conditions.conditions_val[b].test_expr,0)) {
				yylineno=r->lineno;
					A4GL_lint (f->module, r->lineno, "IFFALSE","IF condition is always FALSE", 0);
				//A4GL_lint("IF condition is always FALSE");
			}
			e=if_c->conditions.conditions_val[b].test_expr;
			if (e->expr_type==ET_EXPR_OP_EQUAL) {
				expr_str *l_e;
				expr_str *r_e;
				l_e=e->expr_str_u.expr_op->left;
				r_e=e->expr_str_u.expr_op->right;
				if (A4GL_is_just_int_literal(r_e,100)) {
					if (l_e->expr_type==ET_EXPR_VARIABLE_USAGE) {
						if (A4GL_aubit_strcasecmp(l_e->expr_str_u.expr_variable_usage->variable_name,"status")==0) {
							A4GL_lint (f->module, r->lineno, "CHKSTATUS","Checking 'status' for NOTFOUND", 0);
						}
						if (A4GL_aubit_strcasecmp(l_e->expr_str_u.expr_variable_usage->variable_name,"a4gl_status")==0) {
							A4GL_lint (f->module, r->lineno, "CHKSTATUS","Checking 'status' for NOTFOUND", 0);
						}
					}
					
				}
			}
		}

		for (b=0;b<if_c->conditions.conditions_len;b++) {
			if (A4GL_is_just_int_literal(if_c->conditions.conditions_val[b].test_expr,1)) {
				yylineno=r->lineno;
					A4GL_lint (f->module, r->lineno, "IFTRUE","IF condition is always TRUE", 0);
				//A4GL_lint("IF condition is always TRUE");
			}
		}
	}


	if (r->cmd_data.type==E_CMD_GOTO_CMD) {
					A4GL_lint (f->module, r->lineno, "CS.GOTO","Use of GOTO is not recommended", 0);
		//A4GL_lint("Coding Standards: Use of GOTO is not recommended");
	}


	if (r->cmd_data.type==E_CMD_FOR_CMD) {
			//set_assigned_binding_var(r->cmd_data.command_data_u.for_cmd.var,currfunc, r->module,r->lineno);
	}

	if (r->cmd_data.type==E_CMD_RUN_CMD) {
			//set_assigned_binding(r->cmd_data.command_data_u.run_cmd.returning,currfunc, r->module,r->lineno);
	}

	if (r->cmd_data.type==E_CMD_INIT_CMD) {
			//set_assigned_binding(r->cmd_data.command_data_u.init_cmd.expanded_varlist,currfunc, r->module,r->lineno);
	}
	if (r->cmd_data.type==E_CMD_DECLARE_CMD) {
			//set_assigned_binding(r->cmd_data.command_data_u.declare_cmd.into_bind,currfunc, r->module,r->lineno);
	}
	if (r->cmd_data.type==E_CMD_SELECT_CMD) {
			//set_assigned_binding(r->cmd_data.command_data_u.select_cmd.outbind,currfunc, r->module,r->lineno);
	}
	if (r->cmd_data.type==E_CMD_LET_CMD) {
			//set_assigned_binding(r->cmd_data.command_data_u.let_cmd.vars,currfunc, r->module,r->lineno);
	}

	if (r->cmd_data.type==E_CMD_EXECUTE_CMD) {
			//set_assigned_binding(r->cmd_data.command_data_u.execute_cmd.outbind,currfunc, r->module,r->lineno);
	}

	if (r->cmd_data.type==E_CMD_SQL_BLOCK_CMD) {
			//set_assigned_binding(r->cmd_data.command_data_u.sql_block_cmd.outbind,currfunc, r->module,r->lineno);
	}
	if (r->cmd_data.type==E_CMD_CALL_CMD) { // E_CMD_CALL_CMD is referenced a little later too - 
						// just in case this ever makes it to a 'switch' statement!
			//set_assigned_binding(r->cmd_data.command_data_u.call_cmd.returning,currfunc, r->module,r->lineno);
	}
	if (r->cmd_data.type==E_CMD_PDF_CALL_CMD) {
			//set_assigned_binding(r->cmd_data.command_data_u.pdf_call_cmd.returning,currfunc, r->module,r->lineno);
	}
	if (r->cmd_data.type==E_CMD_FETCH_CMD) {
			//set_assigned_binding(r->cmd_data.command_data_u.fetch_cmd.outbind,currfunc, r->module,r->lineno);
	}
	if (r->cmd_data.type==E_CMD_RUN_CMD) {
			//set_assigned_binding(r->cmd_data.command_data_u.run_cmd.returning,currfunc, r->module,r->lineno);
	}

	if (r->cmd_data.type==E_CMD_CASE_CMD) {
		if (r->cmd_data.command_data_u.case_cmd.case_expr==0) {
	      		for (b = 0; b < r->cmd_data.command_data_u.case_cmd.whens->whens.whens_len; b++) {
				expr_str *expr;
				//int is_string;
				expr=r->cmd_data.command_data_u.case_cmd.whens->whens.whens_val[b]->when_expr;
				/*
        				switch (expr->expr_type) {
                				// Does it look like a string ?
                				case ET_EXPR_LITERAL_STRING:
                				case ET_EXPR_LITERAL_EMPTY_STRING:
                				case ET_EXPR_OP_CLIP:
                				case ET_EXPR_OP_USING:
                				case ET_EXPR_UPSHIFT:
                				case ET_EXPR_DOWNSHIFT:
                				case ET_EXPR_STRING:
                				case ET_EXPR_OP_CONCAT:
                				case ET_EXPR_OP_SPACES:
                				case ET_EXPR_LITERAL_DOUBLE_STR:
                				case ET_EXPR_GET_FLDBUF:
                				case ET_EXPR_WORDWRAP:
                				case ET_EXPR_SUBSTRING:
                				case ET_EXPR_CONCAT_LIST:
							yylineno=r->lineno;
                        				A4GL_lint("Use of string for WHEN in a CASE with no expression"); break;
						default: break;
					}
				*/
	
				yylineno=r->lineno;
				if (expr_datatype(expr)==DTYPE_CHAR || expr_datatype(expr)==DTYPE_VCHAR) {
							A4GL_lint (f->module, r->cmd_data.command_data_u.case_cmd.whens->whens.whens_val[b]->lineno, 
									"CASESTR","Use of String for WHEN in a CASE with no expression", 0);
                        				//A4GL_lint("Use of String for WHEN in a CASE with no expression"); break;
				}
				
	
				if (A4GL_is_just_int_literal(expr,0)) {
					yylineno=r->lineno;
							A4GL_lint (f->module, r->cmd_data.command_data_u.case_cmd.whens->whens.whens_val[b]->lineno, 
									"CASEFALSE","WHEN condition is always FALSE", 0);
					//A4GL_lint("WHEN condition is always FALSE");
				}
				if (A4GL_is_just_int_literal(expr,1)) {
					yylineno=r->lineno;
							A4GL_lint (f->module, r->cmd_data.command_data_u.case_cmd.whens->whens.whens_val[b]->lineno, 
									"CASETRUE","WHEN condition is always TRUE", 0);
					//A4GL_lint("WHEN condition is always TRUE");
				}
			}
		}

		if (!r->cmd_data.command_data_u.case_cmd.otherwise) {
			yylineno=r->lineno;
					A4GL_lint (f->module, r->lineno, "CS.NOOTHERWISE","CASE has no OTHERWISE", 0);
		}
	}
	if (r->cmd_data.type==E_CMD_CALL_CMD) 
                                        {
					int cnt1;
				int cnt2;

                                        struct  expr_str *fcall;
					char *funcname;
                                        fcall=r->cmd_data.command_data_u.call_cmd.fcall;
					funcname=fcall->expr_str_u.expr_function_call->fname;
                                        b=find_function(fcall->expr_str_u.expr_function_call->fname);

                                        if (b==-1) {
                                                if (! system_function(fcall->expr_str_u.expr_function_call->fname) && is_bolton_function(fcall->expr_str_u.expr_function_call->fname)==-1) {
                                                                char buff[200];
                                                                sprintf(buff, "Function %s was called but is not defined", fcall->expr_str_u.expr_function_call->fname);
								A4GL_lint (f->module, r->lineno, "FUNCNOTDEF", "Function was called but is not defined",fcall->expr_str_u.expr_function_call->fname);
								log_proto(fcall, r->cmd_data.command_data_u.call_cmd.returning);
                                                }
                                        } else {
						// We know the function
						if( is_bolton_function(funcname)!=-1) {
							int a;
							a=is_bolton_function(funcname);


							if ( fboltons[a].nreturns>0 && r->cmd_data.command_data_u.call_cmd.returning ==0) {
								A4GL_lint (f->module, r->lineno, "FUNCRETCNT", "Function returns too many values ", funcname);
								continue;
							} 

							if(fboltons[a].nreturns>r->cmd_data.command_data_u.call_cmd.returning->list.list_len) {
								A4GL_lint (f->module, r->lineno, "FUNCRETCNT", "Function returns too few values ", funcname);
								continue;
							}
							if(fboltons[a].nreturns<r->cmd_data.command_data_u.call_cmd.returning->list.list_len) {
								A4GL_lint (f->module, r->lineno, "FUNCRETCNT", "Function returns too many values ", funcname);
								continue;
							}
						} else {
							cnt1=fprototypes[b].nreturns;
							if (r->cmd_data.command_data_u.call_cmd.returning) {
								cnt2=r->cmd_data.command_data_u.call_cmd.returning->list.list_len;
							} else {
								cnt2=0;
							}

							if(cnt1<cnt2) {
								A4GL_lint (f->module, r->lineno, "FUNCRETCNT", "Function returns too few values", funcname);
								continue;
							}
							if(cnt1>cnt2) {
								A4GL_lint (f->module, r->lineno, "FUNCRETCNT", "Function returns too many values", funcname);
								continue;
							}
						}
					
						// If we've got to here - we've got the right number of return variables...
						if (r->cmd_data.command_data_u.call_cmd.returning==0)  { // 
							// Nothing else to check...
							continue;
						}
						if (r->cmd_data.command_data_u.call_cmd.returning->list.list_len==0)  { // 
							// Nothing else to check...
							continue;
						}

						if( is_bolton_function(funcname)!=-1) {
							// Its a bolton
							//int a;
					
						} else {
							// Its not a bolton
							int a;
							int etype;
							struct expr_str_list *varlist;
							varlist=r->cmd_data.command_data_u.call_cmd.returning;
							for (a=0;a<varlist->list.list_len;a++) {
								int vlist_dtype;


								etype= fprototypes[b].return_dtypes[a] & DTYPE_MASK; 
								vlist_dtype= expr_datatype (varlist->list.list_val[a]);
								if (promoteable(etype, vlist_dtype)==-1) {

		
									char buff[200];
									// Mismatch in return types..
									sprintf(buff, "%s - types expression (%s) != variable (%s) @ %d", 
										lint_get_variable_usage_as_string(varlist->list.list_val[a]->expr_str_u.expr_variable_usage), 
											dtype_as_string(etype), dtype_as_string(vlist_dtype),a+1);
									A4GL_lint (r->module, r->lineno, "CALLRETEXPR","Expression is not directly compatible with Variable",buff);
								}
							}
						}
					}

                                        break;
                                        }



	if (r->cmd_data.type==E_CMD_LET_CMD) {
		expr_str_list * expr_list=0;
                expr_str_list * varlist;
		  int from_exprs;
		expr_list=r->cmd_data.command_data_u.let_cmd.vals;
		expr_list = A4GL_rationalize_list (expr_list);
  		from_exprs = A4GL_new_list_get_count (expr_list);

		
              	varlist=r->cmd_data.command_data_u.let_cmd.vars;

		if ( from_exprs!=varlist->list.list_len && varlist->list.list_len!=1) {
			yylineno=r->lineno;
				A4GL_lint (f->module, r->lineno, "LETCOUNT","Mismatch in number of parameters", 0);
			//A4GL_lint("Mismatch in number of parameters");
		}


		for (b = 0; b < varlist->list.list_len; b++) {
			if ( strncmp(expr_as_string_when_possible(varlist->list.list_val[b]),"a4gl_sqlca",10)==0) {
				yylineno=r->lineno;
				A4GL_lint (f->module, r->lineno, "CS.WRITESQLCA","Direct assignment to SQLCA record entry", 0);
                        	//A4GL_lint("Coding Standards: Direct assignment to SQLCA record entry");
        		}

		        if ( A4GL_aubit_strcasecmp(expr_as_string_when_possible(varlist->list.list_val[b]),"int_flag")==0) {
                        	if (A4GL_is_just_int_literal(expr_list->list.list_val[b],0) || A4GL_is_just_int_literal(expr_list->list.list_val[b],1)) ;
                        	else {
					yylineno=r->lineno;
					A4GL_lint (f->module, r->lineno, "CS.WRITEINTFLAG","'int_flag' set to value which is neither TRUE or FALSE", 0);
                                	//A4GL_lint("Coding Standards: 'int_flag' set to value which is neither TRUE or FALSE");
                        	}
			}

		        if ( A4GL_aubit_strcasecmp(expr_as_string_when_possible(varlist->list.list_val[b]),"quit_flag")==0) {
                        	if (A4GL_is_just_int_literal(expr_list->list.list_val[b],0) || A4GL_is_just_int_literal(expr_list->list.list_val[b],1)) ;
                        	else {
					yylineno=r->lineno;
					A4GL_lint (f->module, r->lineno, "CS.WRITEQUITFLAG","'quit_flag' set to value which is neither TRUE or FALSE", 0);
                                	//A4GL_lint("Coding Standards: 'quit_flag' set to value which is neither TRUE or FALSE");
                        	}
			}
		}

		if (varlist->list.list_len && varlist->list.list_len==1) { // single variable
				char buff[256];
			//int e;
			
			if (from_exprs>1) { // This should be a string concat
				if (!is_char_dtype( expr_datatype(varlist->list.list_val[0]))) {
					A4GL_lint (f->module, r->lineno, "CONCATTONONSTR","Assigning a string concentenation to a non-character variable", expr_as_string_when_possible(varlist->list.list_val[0]));
					//sprintf(buff, "Assigning a string concentenation to a non-character variable '%s'", varlist->list.list_val[0].varname);
					//A4GL_lint(buff);
				} else {
					int ecnt;
					// It is a string - so all our expressions should really be strings
					// we know we can convert between integers and strings - but this is a lint
					// checker - maybe they should consider using a USING ? 
					for (ecnt=0;ecnt<from_exprs;ecnt++) {
						int etype;
						yylineno=r->lineno;
						etype=expr_datatype(expr_list->list.list_val[ecnt]);
						if (!is_char_dtype(etype)) {
							sprintf(buff,"%d expression", ecnt+1);	
							A4GL_lint (f->module, r->lineno, "CONCATFROMNONSTR","Expression in string concatenation assignment, is not a string", buff);
							//A4GL_lint(buff);
						}
					}
				}
			}  else {
			//  single value going into a single variable...
				int etype;
				if ( expr_list->list.list_val[0]->expr_type==ET_EXPR_NULL) {
					etype= expr_datatype(varlist->list.list_val[0]);
				} else {
						yylineno=r->lineno;
						etype=expr_datatype(expr_list->list.list_val[0]);
				}
			
				if (promoteable(etype, expr_datatype(varlist->list.list_val[0]))==-1) {
							char buff[256];
							sprintf(buff, "%s - types expression (%s) != variable (%s)", expr_as_string_when_possible(varlist->list.list_val[0]), dtype_as_string(etype), 
dtype_as_string(expr_datatype(varlist->list.list_val[0])));
							A4GL_lint (r->module, r->lineno, "LETEXPR","Expression is not directly compatible with Variable",buff);
							//sprintf(buff, "Expression is not directly compatible with Variable '%s'", varlist->list.list_val[0].varname);
							//A4GL_lint(buff);
				}
			}
			
		} else {
				//char buff[256];
			// More than one expression - more than one variable..
			if (varlist->list.list_len && varlist->list.list_len==from_exprs) {
				int ecnt;
				for (ecnt=0;ecnt<from_exprs;ecnt++) {
					int etype;
					if (expr_list->list.list_val[ecnt]->expr_type==ET_EXPR_NULL) {
						etype=expr_datatype(varlist->list.list_val[ecnt]);
					} else {
						yylineno=r->lineno;
						etype=expr_datatype(expr_list->list.list_val[ecnt]);
					}
					if (promoteable(etype, expr_datatype(varlist->list.list_val[ecnt]))==-1) {
						char buff[256];
						sprintf(buff, "Assignement to '%s', record element %d (%s %s)", expr_as_string_when_possible(varlist->list.list_val[ecnt]), ecnt+1, dtype_as_string(etype), 
dtype_as_string(expr_datatype(varlist->list.list_val[ecnt])));
						A4GL_lint (f->module, r->lineno, "LETEXPR","Expression is not directly compatible with Variable", buff);

						//A4GL_lint(buff);
					}
					
				}
			}
		}
	}


   }
   set_expr_cache(0);

}



static int
local_print_whenever_style (int code, char *whento, int *when_set_to_call)
{


  switch (code)
    {
    case 0x12:
        if (A4GL_aubit_strcasecmp(whento, "get_error_record")==0) { *when_set_to_call=1; } else { *when_set_to_call=0;}

      return 0;

    case 0x11:
               *when_set_to_call=0;
      return 0;

    case 0x10:
                *when_set_to_call=0;
      return 0;

    case 0x20:
      return 0;
    case 0x21:
      return 0;
    case 0x22:
      return 0;
    }

  A4GL_assertion(1,"Unhandled whenever");

  return 0;


}




// This goes through all the functions in a module and checks that WHENEVER ERROR CALL get_error_record
// has been called before any SQL statements are used 
static void
check_whenever_abuse (module_definition * d)
{
  int a;
  //int b;
  int cmd;
  struct commands *all_cmds = 0;
  struct command *c;
  int when_set_to_call = 0;
  //struct report_format_section *report_format_section;
  char *curr_func = "";


  for (a = 0; a < d->module_entries.module_entries_len; a++)
    {
      //struct s_function_definition *f;
      all_cmds = 0;

      curr_func = "";

      switch (d->module_entries.module_entries_val[a]->met_type)
	{

	case E_MET_MAIN_DEFINITION:
	case E_MET_FUNCTION_DEFINITION:
	  all_cmds = linearise_commands (0, 0);
	  linearise_commands (all_cmds,
			      d->module_entries.module_entries_val[a]->
			      module_entry_u.function_definition.
			      func_commands);
	  curr_func = d->module_entries.module_entries_val[a]->
	    module_entry_u.function_definition.funcname;
	  break;

	case E_MET_REPORT_DEFINITION:
		linearise_report(all_cmds, d->module_entries.module_entries_val[a]->module_entry_u.  report_definition.report_format_section);

	  break;

	case E_MET_PDF_REPORT_DEFINITION:
		linearise_report(all_cmds, d->module_entries.module_entries_val[a]->module_entry_u.  pdf_report_definition.report_format_section);
	  break;
	case E_MET_FORMHANDLER_DEFINITION:
		printf("Not implemented yet (E_MET_FORMHANDLER_DEFINITION,2) \n");
		exit(4);
	  break;

	case E_MET_CMD:
	  c = d->module_entries.module_entries_val[a]->module_entry_u.cmd;
	  if (c->cmd_data.type == E_CMD_WHENEVER_CMD)
	    {
		  local_print_whenever_style (c->cmd_data.command_data_u.  whenever_cmd.whencode, c->cmd_data.command_data_u.  whenever_cmd.whento, &when_set_to_call);
	    }
	  break;

	  // We dont need to worry about these commands....
	case E_MET_IMPORT_FUNCTION_DEFINITION:
	case E_MET_IMPORT_LEGACY_DEFINITION:
	case E_MET_CLASS_DEFINITION:
	  break;

	}


      if (all_cmds)
	{
	  struct command *r;
	  for (cmd = 0; cmd < all_cmds->cmds.cmds_len; cmd++)
	    {
	      r = all_cmds->cmds.cmds_val[cmd];

	      switch (r->cmd_data.type)
		{
		 case E_CMD_EXIT_PROG_CMD:
			if (A4GL_aubit_strcasecmp (curr_func, "exit_prog") != 0) {
                                        	//A4GL_lint("Coding Standards: EXIT PROGRAM must not be used directly - use CALL exit_prog instead");
						A4GL_lint (d->module_name, r->lineno, "CS.EXITDIRECT","EXIT PROGRAM must not be used directly - use CALL exit_prog instead", 0);
                        }

			
			if (A4GL_aubit_strcasecmp (curr_func, "main") != 0) {
						A4GL_lint (d->module_name, r->lineno, "CS.EXITNOTMAIN","EXIT PROGRAM must only be in main", 0);
							//A4GL_lint("Coding Standards: EXIT PROGRAM must only be in main");
			}
			break;

		case E_CMD_WHENEVER_CMD:
		  local_print_whenever_style (r->cmd_data.command_data_u.  whenever_cmd.whencode, r->cmd_data.command_data_u.  whenever_cmd.whento, &when_set_to_call);
		  break;


		// Transactions should only be done in functions called 'begin_work', 'rollback_work', and 'commit_work'....
		case E_CMD_SQL_TRANSACT_CMD:
		  if (!when_set_to_call)
		    {
						A4GL_lint (d->module_name, r->lineno, "CS.GETERRORRECORD","Must use 'WHENEVER ERROR CALL get_error_record' before using SQL", 0);
		      				//A4GL_lint ("Coding Standards: Must use 'WHENEVER ERROR CALL get_error_record' before using SQL");
		    }
		  break;


		  switch (r->cmd_data.command_data_u.sql_transact_cmd.trans)
		    {
		    case -1:
		      if (A4GL_aubit_strcasecmp (curr_func, "begin_work") != 0)
			{
						A4GL_lint (d->module_name, r->lineno, "CS.DIRECTTRANS", "BEGIN WORK used directly", 0);
			  			//A4GL_lint ("Coding Standards: BEGIN WORK used directly");
			}
		      break;
		    case 0:
		      if (A4GL_aubit_strcasecmp (curr_func, "rollback_work") != 0)
			{
					A4GL_lint (d->module_name, r->lineno, "CS.DIRECTTRANS", "ROLLBACK WORK used directly", 0);
			  		//A4GL_lint ("Coding Standards: ROLLBACK WORK used directly");
			}
		      break;
		    case 1:
		      if (A4GL_aubit_strcasecmp (curr_func, "commit_work") != 0)
			{
					A4GL_lint (d->module_name, r->lineno, "CS.DIRECTTRANS", "COMMIT WORK used directly", 0);
			  		//A4GL_lint ("Coding Standards: COMMIT WORK used directly");
			}
		      break;
		    }
			break;




		case E_CMD_SELECT_CMD:
		case E_CMD_FETCH_CMD:
		case E_CMD_SQL_BLOCK_CMD:
		case E_CMD_SQL_CMD:
		case E_CMD_EXECUTE_CMD:
		case E_CMD_PREPARE_CMD:
		  if (!when_set_to_call)
		    {
		      				//A4GL_lint ("Coding Standards: Must use 'WHENEVER ERROR CALL get_error_record' before using SQL");
					A4GL_lint (d->module_name, r->lineno, "CS.GETERRORRECORD","Must use 'WHENEVER ERROR CALL get_error_record' before using SQL", 0);
		    }
		  break;

		default:
			break;
			// Don't care -they are not SQL commands...

		}
	    }
	}


    }


}




void lint_warnings(int n,  struct lint_warning *v) {
int a;
for (a=0;a<n;a++) {
	A4GL_lint(0,v->lineno,"CTIME",v->warning,0);
}
}

static void check_functions_in_module(int *calltree, module_definition *d) {
int a;
struct module_entry *m;
//int b;




   for (a=0;a<d->module_entries.module_entries_len;a++) {
	//struct s_function_definition *f;

	switch (d->module_entries.module_entries_val[a]->met_type) {

        	case E_MET_MAIN_DEFINITION:
        	case E_MET_FUNCTION_DEFINITION:     
			m=this_module.module_entries.module_entries_val[a];
			set_lint_module(m->module_entry_u.function_definition.module);
			lint_warnings( d->module_entries.module_entries_val[a]->module_entry_u.function_definition.extra_warnings.extra_warnings_len, d->module_entries.module_entries_val[a]->module_entry_u.function_definition.extra_warnings.extra_warnings_val );
			if (calltree[a]!=0 || nomain) {
				printf("Check : %s\n", d->module_entries.module_entries_val[a]->module_entry_u.function_definition.funcname);
				check_function (d, &d->module_entries.module_entries_val[a]->module_entry_u.function_definition);
			}
			break;

        	case E_MET_REPORT_DEFINITION:    
			lint_warnings( d->module_entries.module_entries_val[a]->module_entry_u.report_definition.extra_warnings.extra_warnings_len, d->module_entries.module_entries_val[a]->module_entry_u.report_definition.extra_warnings.extra_warnings_val );
			break;

        	case E_MET_PDF_REPORT_DEFINITION:       
			lint_warnings( d->module_entries.module_entries_val[a]->module_entry_u.pdf_report_definition.extra_warnings.extra_warnings_len, d->module_entries.module_entries_val[a]->module_entry_u.pdf_report_definition.extra_warnings.extra_warnings_val );
			break;
		case E_MET_FORMHANDLER_DEFINITION:
			printf("Not implemented yet (E_MET_FORMHANDLER_DEFINITION.3)\n");
			exit(4);
			break;
		// We dont need to worry about these commands....
		case E_MET_CMD:
		case E_MET_IMPORT_FUNCTION_DEFINITION:
		case E_MET_CLASS_DEFINITION:
		case E_MET_IMPORT_LEGACY_DEFINITION: break;

	}
   }

   for (a=0;a<ngass;a++) {
		if (gass[a].nfunction_list>1) {
			//char buff[2000];
			int b;
			for(b=0;b<gass[a].nfunction_list;b++) {
				A4GL_lint(gass[a].function_list[b].module,gass[a].function_list[b].line,"ASSGLOBALS","Global variable has been assigned in multiple functions",gass[a].varname);
			}

		}
   }
	
	//A4GL_setenv("A4GL_PACKER","XML2",1);

//if (A4GL_isyes(acl_getenv("DUMPOUTPUT"))) {
  //write_module_definition(d, "test1.xml");
//}

	
}


static void check_functions_in_module_for_complexity(module_definition *d) {
int a;
//struct module_entry *m;
//int b;
   for (a=0;a<d->module_entries.module_entries_len;a++) {
	//struct s_function_definition *f;

	switch (d->module_entries.module_entries_val[a]->met_type) {

        	case E_MET_MAIN_DEFINITION:
        	case E_MET_FUNCTION_DEFINITION:     
				check_function_for_complexity (d, &d->module_entries.module_entries_val[a]->module_entry_u.function_definition);
			break;

		// We dont need to worry about these commands....
        	case E_MET_REPORT_DEFINITION:    
        	case E_MET_PDF_REPORT_DEFINITION:       
		case E_MET_CMD:
		case E_MET_IMPORT_FUNCTION_DEFINITION:
		case E_MET_CLASS_DEFINITION:
		case E_MET_IMPORT_LEGACY_DEFINITION: break;

		case E_MET_FORMHANDLER_DEFINITION:
			printf("Not implemented yet (E_MET_FORMHANDLER_DEFINITION.4) \n");
			exit(4);
			break;

	}
   }
	
	//A4GL_setenv("A4GL_PACKER","XML2",1);

//if (A4GL_isyes(acl_getenv("DUMPOUTPUT"))) {
  //write_module_definition(d, "test1.xml");
//}

	
}




static int local_is_system_variable (char *s) {
  //if (strcmp (s, "int_flag") == 0) return 1;
  //if (strcmp (s, "quit_flag") == 0) return 1;

  if (A4GL_aubit_strcasecmp (s, "a4gl_status") == 0)
    return 1;
  if (strncmp (s, "a4gl_sqlca", 10) == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (s, "notfound") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (s, "false") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (s, "true") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (s, "today") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (s, "user") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (s, "pageno") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (s, "lineno") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (s, "time") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (s, "usrtime") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (s, "curr_hwnd") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (s, "curr_form") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (s, "err_file_name") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (s, "err_line_no") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (s, "curr_file_name") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (s, "curr_line_no") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (s, "err_status") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (s, "aiplib_status") == 0)
    return 1;
  return 0;
}



int
local_is_valid_vname (struct variable *v, char scope)
{
  char *nm;
  nm = v->names.names.names_val[0].name;

  if (strlen (nm) < 4)
    return 0;			// too short for sn_
  if (nm[2] != '_')
    return 0;

  if (nm[1] == 'v')
    {
      return 1;
    }

  switch (v->var_data.variable_type)
    {
    case VARIABLE_TYPE_SIMPLE:
      switch (v->var_data.variable_data_u.v_simple.datatype & DTYPE_MASK)
	{
	case DTYPE_CHAR:
	  if (nm[1] != 'c')
	    return 0;
	  else
	    return 1;
	case DTYPE_SMINT:
	  if (nm[1] != 'b' && nm[1] != 's')
	    return 0;
	  else
	    return 1;
	case DTYPE_SERIAL:
	case DTYPE_INT:
	  if (nm[1] != 'n')
	    return 0;
	  else
	    return 1;
	case DTYPE_DATE:
	  if (nm[1] != 'd')
	    return 0;
	  else
	    return 1;
	case DTYPE_DECIMAL:
	  if (nm[1] != 'l')
	    return 0;
	  else
	    return 1;
	case DTYPE_INTERVAL:
	  if (nm[1] != 'i')
	    return 0;
	  else
	    return 1;
	}
      // No specific rule - so must be ok...
      return 1;

    case VARIABLE_TYPE_RECORD:
      if (nm[1] != 'r')
	return 0;
      else
	return 1;



    case VARIABLE_TYPE_ASSOC:
    case VARIABLE_TYPE_CONSTANT:
    case VARIABLE_TYPE_FUNCTION_DECLARE:
    case VARIABLE_TYPE_OBJECT:
    case VARIABLE_TYPE_LINKED:
      return 1;


      //case VARIABLE_TYPE_ARRAY:
      //if (nm[1]!='a') return 0; else return 1;
    }

  return 1;
}

char * get_ident_as_string (struct expr_str *ptr)
{

static char buff[2000];
  if (ptr->expr_type == ET_EXPR_IDENTIFIER)
    {
       sprintf(buff, "\"%s\"", ptr->expr_str_u.expr_string);
        return strdup(buff);
    }

  if (ptr->expr_type == ET_EXPR_VARIABLE_IDENTIFIER) // a _VARIABLE
    {
      return strdup(expr_as_string_when_possible (ptr->expr_str_u.expr_expr));
    }

  if (ptr->expr_type == ET_EXPR_VARIABLE_USAGE)
    {
        return strdup(lint_get_variable_usage_as_string(ptr->expr_str_u.expr_variable_usage));
    }


  A4GL_assertion (1, "get_ident_as_string not implemented for this expression type yet");
  return 0;
}



void check_variable_name(char *modname, char *scope, struct variable *v) {
int issystem;
//char buff[256];

      if (v->var_data.variable_type == VARIABLE_TYPE_SIMPLE
          || v->var_data.variable_type == VARIABLE_TYPE_RECORD
          || v->var_data.variable_type == VARIABLE_TYPE_OBJECT
          || v->var_data.variable_type == VARIABLE_TYPE_ASSOC) ;
	else return;

        issystem=local_is_system_variable( v->names.names.names_val[0].name);
	
	//printf("%s - %d\n", v->names.names.names_val[0].name, v->lineno);
        if (A4GL_aubit_strcasecmp(v->names.names.names_val[0].name,"int_flag")==0) issystem=1;
        if (A4GL_aubit_strcasecmp(v->names.names.names_val[0].name,"quit_flag")==0) issystem=1;
        if (A4GL_aubit_strcasecmp(v->names.names.names_val[0].name,"fgl_user")==0) issystem=1;

	if (issystem) return;

	if (A4GL_aubit_strcasecmp(scope,"ImportedGlobal")==0) {
		// These should be picked up in the module in which they are exported...
		return ;
	}


	if (A4GL_aubit_strcasecmp(scope,"Global")==0) {
		if ( v->names.names.names_val[0].name[0]!='g' ) {
	
			A4GL_lint (v->src_module,  v->lineno, "CS.VNAME","Global variable does not begin with 'g'", v->names.names.names_val[0].name);
	        	//sprintf(buff, "Coding Standards: Global variable (%s) does not begin with 'g'", v->names.names.names_val[0].name);
                	//A4GL_lint(buff);
		}

                if (!local_is_valid_vname(v, 'g')) {
				A4GL_lint (v->src_module,  v->lineno, "CS.VNAME","Variable is not in the form sn_xxxx", v->names.names.names_val[0].name);
                                       //sprintf(buff, "Coding Standards: Variable (%s) is not in the form sn_xxxx ", v->names.names.names_val[0].name);
                                       //A4GL_lint(buff);
                }

		return;
		
	}

	if (A4GL_aubit_strcasecmp(scope,"Module")==0) {
		// Module level variable
		if ( v->names.names.names_val[0].name[0]!='m' ) {
			A4GL_lint (v->src_module,  v->lineno, "CS.VNAME","Module variable does not begin with 'm'", v->names.names.names_val[0].name);
	        	//sprintf(buff, "Coding Standards: Module variable (%s) does not begin with 'm'", v->names.names.names_val[0].name);
                	//A4GL_lint(buff);
		}
                if (!local_is_valid_vname(v, 'm')) {
				A4GL_lint (v->src_module,  v->lineno, "CS.VNAME","Variable is not in the form sn_xxxx", v->names.names.names_val[0].name);
                                       //sprintf(buff, "Coding Standards: Variable (%s) is not in the form sn_xxxx ", v->names.names.names_val[0].name);
                                       //A4GL_lint(buff);
                }
		return;
	}

	if (A4GL_aubit_strcasecmp(scope,"Local")==0) {
		// Module level variable
		if ( v->names.names.names_val[0].name[0]!='l' ) {
			A4GL_lint (v->src_module,  v->lineno, "CS.VNAME","Local variable does not begin with 'l'", v->names.names.names_val[0].name);
	        	//sprintf(buff, "Coding Standards: Local variable (%s) does not begin with 'l'", v->names.names.names_val[0].name);
                	//A4GL_lint(buff);
		}
                if (!local_is_valid_vname(v, 'l')) {
				A4GL_lint (v->src_module,  v->lineno, "CS.VNAME","Variable is not in the form sn_xxxx", v->names.names.names_val[0].name);
                                       //sprintf(buff, "Coding Standards: Variable (%s) is not in the form sn_xxxx ", v->names.names.names_val[0].name);
                                       //A4GL_lint(buff);
                }
		return;
	}



	printf("Unexpected scope : %s -->%s\n", scope, v->names.names.names_val[0].name);
	exit(1);
}


int has_variable (struct variable_list *v, char *name) {
int a;
   for (a=0;a<v->variables.variables_len;a++) {
		if (A4GL_aubit_strcasecmp(v->variables.variables_val[a]->names.names.names_val[0].name,name)==0) return 1;
   }
   return 0;
}

void check_module(struct module_definition *d) {
struct commands *all_cmds=0;
int a;
int b;


   all_cmds=linearise_commands(0, 0);

   for (a=0;a<d->imported_global_variables.variables.variables_len;a++) {
   	check_variable_name(d->module_name, "ImportedGlobal", d->imported_global_variables.variables.variables_val[a]);
   }

   for (a=0;a<d->exported_global_variables.variables.variables_len;a++) {
   	check_variable_name(d->module_name, "Global", d->exported_global_variables.variables.variables_val[a]);
	if (has_variable(&d->imported_global_variables, d->exported_global_variables.variables.variables_val[a]->names.names.names_val[0].name)) {
                                //char buff[256];
				A4GL_lint (0,  d->exported_global_variables.variables.variables_val[a]->lineno, "CS.VARHIDE","Global variable hides an imported Global variable", d->exported_global_variables.variables.variables_val[a]->names.names.names_val[0].name);
                                //sprintf(buff, "Coding Standards: Global variable (%s) hides an imported Global variable", d->exported_global_variables.variables.variables_val[a]->names.names.names_val[0].name);
                                //A4GL_lint(buff);
	}
   }


   for (a=0;a<d->module_variables.variables.variables_len;a++) {

		check_variable_name(d->module_name, "Module", d->module_variables.variables.variables_val[a]);

		if (has_variable(&d->imported_global_variables, d->module_variables.variables.variables_val[a]->names.names.names_val[0].name)) {
                                //char buff[256];
				A4GL_lint (d->module_name,  d->module_variables.variables.variables_val[a]->lineno, "CS.VARHIDE","Module variable hides an imported Global variable", d->module_variables.variables.variables_val[a]->names.names.names_val[0].name);
                                //sprintf(buff, "Coding Standards: Module variable (%s) hides an imported Global variable", d->module_variables.variables.variables_val[a]->names.names.names_val[0].name);
                                //A4GL_lint(buff);
		}

		if (has_variable(&d->exported_global_variables, d->module_variables.variables.variables_val[a]->names.names.names_val[0].name)) {
                                //char buff[256];
				A4GL_lint (d->module_name,  d->module_variables.variables.variables_val[a]->lineno, "CS.VARHIDE","Module variable hides an exported Global variable", d->module_variables.variables.variables_val[a]->names.names.names_val[0].name);
                                //sprintf(buff, "Coding Standards: Module variable (%s) hides an exported Global variable", d->module_variables.variables.variables_val[a]->names.names.names_val[0].name);
                                //A4GL_lint(buff);
		}

		if (d->module_variables.variables.variables_val[a]->usage==0 && d->module_variables.variables.variables_val[a]->assigned==0) {
			//char buff[256];
			yylineno=1;
			A4GL_lint (d->module_name,  d->module_variables.variables.variables_val[a]->lineno, "VARNOTUSED","Module variable is defined but not used", d->module_variables.variables.variables_val[a]->names.names.names_val[0].name);
			//sprintf(buff, "Module variable (%s) is defined but not used", d->module_variables.variables.variables_val[a]->names.names.names_val[0].name);
			//A4GL_lint(buff);
		}

		if (d->module_variables.variables.variables_val[a]->usage==0 && d->module_variables.variables.variables_val[a]->assigned) {
			//char buff[256];
			yylineno=1;
			A4GL_lint (d->module_name,  d->module_variables.variables.variables_val[a]->lineno, "VARASSNOTUSED","Module variable is assigned a value but not used", d->module_variables.variables.variables_val[a]->names.names.names_val[0].name);
			//sprintf(buff, "Module variable (%s) is assigned a value but not used", d->module_variables.variables.variables_val[a]->names.names.names_val[0].name);
			//A4GL_lint(buff);
		}


		//printf("%s - %d\n", d->module_variables.variables.variables_val[a]->names.names.names_val[0].name, d->module_variables.variables.variables_val[a]->usage);
   }

  



  check_functions_in_module_for_complexity(d);


  linearise_module(all_cmds, d);
   
   // Look for Prepared but not used...
   for (a=0;a<all_cmds->cmds.cmds_len;a++) {
	if (all_cmds->cmds.cmds_val[a]->cmd_data.type==E_CMD_PREPARE_CMD) {
		int used=0;
		for (b=0;b<all_cmds->cmds.cmds_len;b++) {

			// Prepares can be used for DECLARE or for EXECUTE
			if ( all_cmds->cmds.cmds_val[b]->cmd_data.type==E_CMD_EXECUTE_CMD) {
				if (A4GL_aubit_strcasecmp(
				get_ident_as_string(all_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.prepare_cmd.stmtid )
					, 
				get_ident_as_string(all_cmds->cmds.cmds_val[b]->cmd_data.command_data_u.execute_cmd.sql_stmtid)
					)==0) {
					used++;
				}
			}

			if ( all_cmds->cmds.cmds_val[b]->cmd_data.type==E_CMD_DECLARE_CMD) {
				if(all_cmds->cmds.cmds_val[b]->cmd_data.command_data_u.declare_cmd.declare_dets->ident==NULL) continue;
				if (A4GL_aubit_strcasecmp(
					get_ident_as_string(all_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.prepare_cmd.stmtid)
					, 
					get_ident_as_string(all_cmds->cmds.cmds_val[b]->cmd_data.command_data_u.declare_cmd.declare_dets->ident)
						)==0) {
					used++;
				}
			}

		}

		if (!used) {
			//char buff[256];
			yylineno=all_cmds->cmds.cmds_val[a]->lineno;
			A4GL_lint (0, all_cmds->cmds.cmds_val[a]->lineno, "PREPARENOTUSED", "Prepared statement is not used",  
				A4GL_strip_quotes(get_ident_as_string(all_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.prepare_cmd.stmtid)));
			
			//sprintf(buff,"Prepared statement (%s) is not used", A4GL_strip_quotes(all_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.prepare_cmd.stmtid));
			//A4GL_lint(buff);
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
				if (A4GL_aubit_strcasecmp(
	get_ident_as_string(all_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.declare_cmd.cursorname), 
		get_ident_as_string(all_cmds->cmds.cmds_val[b]->cmd_data.command_data_u.open_cursor_cmd.cursorname)
		)==0) {
					used++;
				}
			}


			if ( all_cmds->cmds.cmds_val[b]->cmd_data.type==E_CMD_FOREACH_CMD) {
				if (A4GL_aubit_strcasecmp(
get_ident_as_string(all_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.declare_cmd.cursorname)
, 
get_ident_as_string(all_cmds->cmds.cmds_val[b]->cmd_data.command_data_u.foreach_cmd.cursorname)
)==0) {
					used++;
				}
			}
		}

		if (!used) {
			//char buff[256];
			yylineno=all_cmds->cmds.cmds_val[a]->lineno;
			A4GL_lint (0, all_cmds->cmds.cmds_val[a]->lineno, "DECLARENOTUSED", "Cursor is DECLAREd but not OPENed",   A4GL_strip_quotes(
get_ident_as_string(all_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.declare_cmd.cursorname)
));
			//sprintf(buff,"Cursor (%s) is DECLAREd but not OPENed", A4GL_strip_quotes(all_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.declare_cmd.cursorname));
			//A4GL_lint(buff);
		}
	}
   }


}























/********************************************************************************/
// LINT CHECKS FOR A PROGRAM (not a module )

static void add_all_module_entry( module_entry *m) {
	// For this call - this_module is defined in link.c
	// add_all_module_entry shouldn't be called during normal compilation- so it won't 
	// apply to the one defintion in the compiler (in parsehelp.c)
       if (m) {
                   this_module.module_entries.module_entries_len++;
                   this_module.module_entries.module_entries_val=realloc(this_module.module_entries.module_entries_val, sizeof(module_entry *)*this_module.module_entries.module_entries_len);
                   this_module.module_entries.module_entries_val[this_module.module_entries.module_entries_len-1]=m;
       }
}


static int system_function_dtype(char *funcname) {

// Dont return anything
        if (A4GL_aubit_strcasecmp(funcname,"aclfgl_add_keymap")==0) return -1;
        if (A4GL_aubit_strcasecmp(funcname,"aclfgl_closeiem")==0) return -1;
        if (A4GL_aubit_strcasecmp(funcname,"a4gl_dump_screen")==0) return -1;
        if (A4GL_aubit_strcasecmp(funcname,"a4gl_load_datatype")==0) return -1;
        if (A4GL_aubit_strcasecmp(funcname,"a4gl_run_gui")==0) return -1;
        if (A4GL_aubit_strcasecmp(funcname,"a4gl_set_page")==0) return -1;
        if (A4GL_aubit_strcasecmp(funcname,"a4gl_show_help")==0) return -1;
        if (A4GL_aubit_strcasecmp(funcname,"aclfgl_dump_screen")==0) return -1;
        if (A4GL_aubit_strcasecmp(funcname,"aclfgl_fetchiem")==0) return -1;
        if (A4GL_aubit_strcasecmp(funcname,"aclfgl_get_curr_height")==0) return -1;
        if (A4GL_aubit_strcasecmp(funcname,"aclfgl_get_curr_width")==0) return -1;
        if (A4GL_aubit_strcasecmp(funcname,"aclfgl_get_user")==0) return -1;
        if (A4GL_aubit_strcasecmp(funcname,"aclfgl_libhelp_showhelp")==0) return -1;
        if (A4GL_aubit_strcasecmp(funcname,"aclfgl_openiem")==0) return -1;
        if (A4GL_aubit_strcasecmp(funcname,"aclfgl_random")==0) return -1;
        if (A4GL_aubit_strcasecmp(funcname,"aclfgl_read_pipe")==0) return -1;
        if (A4GL_aubit_strcasecmp(funcname,"aclfgl_set_color")==0) return -1;
        if (A4GL_aubit_strcasecmp(funcname,"aclfgl_setenv")==0) return -1;
        if (A4GL_aubit_strcasecmp(funcname,"fgl_scr_size")==0) return -1;
        if (A4GL_aubit_strcasecmp(funcname,"fgl_getkey_wait")==0) return -1;
        if (A4GL_aubit_strcasecmp(funcname,"fgl_keysetlabel")==0) return -1;
        if (A4GL_aubit_strcasecmp(funcname,"ddeconnect")==0) return -1;
        if (A4GL_aubit_strcasecmp(funcname,"ddeexecute")==0) return -1;
        if (A4GL_aubit_strcasecmp(funcname,"ddefinish")==0) return -1;
        if (A4GL_aubit_strcasecmp(funcname,"ddefinishall")==0) return -1;
        if (A4GL_aubit_strcasecmp(funcname,"ddegeterror")==0) return -1;
        if (A4GL_aubit_strcasecmp(funcname,"ddepeek")==0) return -1;
        if (A4GL_aubit_strcasecmp(funcname,"ddepoke")==0) return -1;
        if (A4GL_aubit_strcasecmp(funcname,"err_print")==0) return -1;
        if (A4GL_aubit_strcasecmp(funcname,"err_quit")==0) return -1;
        if (A4GL_aubit_strcasecmp(funcname,"errorlog")==0) return -1;
        if (A4GL_aubit_strcasecmp(funcname,"fgl_dialog_setbuffer")==0) return -1;
        if (A4GL_aubit_strcasecmp(funcname,"fgl_dialog_setcurrline")==0) return -1;
        if (A4GL_aubit_strcasecmp(funcname,"fgl_dialog_setkeylabel")==0) return -1;
        if (A4GL_aubit_strcasecmp(funcname,"fgl_prtscr")==0) return -1;
        if (A4GL_aubit_strcasecmp(funcname,"fgl_set_arrline")==0) return -1;
        if (A4GL_aubit_strcasecmp(funcname,"fgl_set_scrline")==0) return -1;
        if (A4GL_aubit_strcasecmp(funcname,"fgl_setkeylabel")==0) return -1;
        if (A4GL_aubit_strcasecmp(funcname,"fgl_strtosend")==0) return -1;
        if (A4GL_aubit_strcasecmp(funcname,"fgl_winmessage")==0) return -1;
        if (A4GL_aubit_strcasecmp(funcname,"fgl_drawbox")==0) return -1;
        if (A4GL_aubit_strcasecmp(funcname,"set_count")==0) return -1;
        if (A4GL_aubit_strcasecmp(funcname,"showhelp")==0) return -1;
        if (A4GL_aubit_strcasecmp(funcname,"startlog")==0) return -1;

// INTs
	if (A4GL_aubit_strcasecmp(funcname,"length")==0) return DTYPE_INT;
        if (A4GL_aubit_strcasecmp(funcname,"weekday")==0) return DTYPE_INT;
        if (A4GL_aubit_strcasecmp(funcname,"year")==0) return DTYPE_INT;
        if (A4GL_aubit_strcasecmp(funcname,"arr_count")==0) return DTYPE_INT;
        if (A4GL_aubit_strcasecmp(funcname,"arr_curr")==0) return DTYPE_INT;
        if (A4GL_aubit_strcasecmp(funcname,"day")==0) return DTYPE_INT;
        if (A4GL_aubit_strcasecmp(funcname,"length")==0) return DTYPE_INT;
        if (A4GL_aubit_strcasecmp(funcname,"month")==0) return DTYPE_INT;

        if (A4GL_aubit_strcasecmp(funcname,"winexec")==0) return DTYPE_SMINT;


        if (A4GL_aubit_strcasecmp(funcname,"mdy")==0) return DTYPE_DATE;

        if (A4GL_aubit_strcasecmp(funcname,"a4gl_get_info")==0) return DTYPE_CHAR;
        if (A4GL_aubit_strcasecmp(funcname,"a4gl_get_page")==0) return DTYPE_CHAR;
        if (A4GL_aubit_strcasecmp(funcname,"a4gl_get_ui_mode")==0) return DTYPE_CHAR;
        if (A4GL_aubit_strcasecmp(funcname,"arg_val")==0) return DTYPE_CHAR;



        if (A4GL_aubit_strcasecmp(funcname,"aclfgl_byte_as_str")==0) return DTYPE_CHAR;



        if (A4GL_aubit_strcasecmp(funcname,"ascii")==0) return DTYPE_CHAR;
        if (A4GL_aubit_strcasecmp(funcname,"date")==0) return DTYPE_DATE;
        if (A4GL_aubit_strcasecmp(funcname,"dbms_dialect")==0) return DTYPE_CHAR;
        if (A4GL_aubit_strcasecmp(funcname,"downshift")==0) return DTYPE_CHAR;
        if (A4GL_aubit_strcasecmp(funcname,"err_get")==0) return DTYPE_CHAR;

        if (A4GL_aubit_strcasecmp(funcname,"aclfgl_expand_env_vars_in_cmdline")==0) return DTYPE_CHAR;
        if (A4GL_aubit_strcasecmp(funcname,"fgl_buffertouched")==0) return  DTYPE_INT;
        if (A4GL_aubit_strcasecmp(funcname,"fgl_compare")==0) return DTYPE_INT;

        if (A4GL_aubit_strcasecmp(funcname,"fgl_dialog_getbuffer")==0) return DTYPE_CHAR;
        if (A4GL_aubit_strcasecmp(funcname,"fgl_dialog_getfieldname")==0) return DTYPE_CHAR;
        if (A4GL_aubit_strcasecmp(funcname,"fgl_getenv")==0) return DTYPE_CHAR;
        if (A4GL_aubit_strcasecmp(funcname,"fgl_getkey")==0) return DTYPE_CHAR;
        if (A4GL_aubit_strcasecmp(funcname,"fgl_keyval")==0) return DTYPE_INT;
        if (A4GL_aubit_strcasecmp(funcname,"fgl_lastkey")==0) return DTYPE_INT;
        if (A4GL_aubit_strcasecmp(funcname,"fgl_round")==0) return DTYPE_INT;


        if (A4GL_aubit_strcasecmp(funcname,"ord")==0) return DTYPE_INT;
        if (A4GL_aubit_strcasecmp(funcname,"num_args")==0) return DTYPE_INT;
        if (A4GL_aubit_strcasecmp(funcname,"scr_line")==0) return DTYPE_INT;
        if (A4GL_aubit_strcasecmp(funcname,"upshift")==0) return DTYPE_CHAR;



        if (A4GL_aubit_strcasecmp(funcname,"abs")==0) return DTYPE_FLOAT;
        if (A4GL_aubit_strcasecmp(funcname,"sqrt")==0) return DTYPE_FLOAT;

return -2;
}


static int system_function(char *funcname) {
	if (system_function_dtype(funcname)!=-2) {
		return 1;
	}
	return 0;
}



/********************************************************************************/
static int find_function(char *s) {
int a;
	
	for (a=0;a< this_module.module_entries.module_entries_len;a++) {
		struct module_entry *m;
		m=this_module.module_entries.module_entries_val[a];
		switch (m->met_type) {
			case E_MET_MAIN_DEFINITION:
        		case E_MET_FUNCTION_DEFINITION:  
				if (A4GL_aubit_strcasecmp(m->module_entry_u.function_definition.funcname,s)==0) return a;

        		case E_MET_REPORT_DEFINITION:  
				if (A4GL_aubit_strcasecmp(m->module_entry_u.report_definition.funcname,s)==0) return a;

        		case E_MET_PDF_REPORT_DEFINITION:  
				if (A4GL_aubit_strcasecmp(m->module_entry_u.pdf_report_definition.funcname,s)==0) return a;
		
			case E_MET_FORMHANDLER_DEFINITION:
					//printf("Not implemented yet (E_MET_FORMHANDLER_DEFINITION.5)\n");
					//exit(4);
			break;

			default: 
		
				// Dont care - cant be a function or report anyway...
				break;
		}
	}
	return -1;
}




int
find_function_single_rtype (char *funcname)
{
  int calltree_entry;
static  int callstack=0;

  if (system_function (funcname))
    {
      return system_function_dtype (funcname);
    }

  calltree_entry = find_function (funcname);

  if (calltree_entry == -1)
    {
		if (is_bolton_function(funcname)!=-1) {
			int a;
			a=is_bolton_function(funcname);

			if(fboltons[a].nreturns>1) {
				A4GL_lint (0, 0, "FUNCRETMANY", "Function returns more than one value but is being used where it should return only one", funcname);
				return -1;
			}

			if(fboltons[a].nreturns<1) {
				A4GL_lint (0, 0, "FUNCNOTRET", "Function does not return a value but is being used where it should return a value", funcname);
				return -1;
			}
			
			return  fboltons[a].return_dtypes[0];
		} else {
			printf("WARNING : No calltree entry for %s...)\n", funcname);
			return DTYPE_CHAR;
		}
	/*
      int a;
      for (a = 0; a < this_module.module_entries.module_entries_len; a++)
	{
	  struct module_entry *m;
	  m = this_module.module_entries.module_entries_val[a];
	  switch (m->met_type)
	    {
	    case E_MET_MAIN_DEFINITION:
	    case E_MET_FUNCTION_DEFINITION:
	      //printf ("%s (%d) %s\n", m->module_entry_u.function_definition.module,  m->module_entry_u.function_definition.lineno,     m->module_entry_u.function_definition.funcname); break;
		default: break;
	    }
	}
      exit (2);
	*/
    }

  if (fprototypes==0)  {
		printf("Faking dtype to be CHAR for %s\n",funcname);
		return DTYPE_CHAR; /* Well - it might be ;-) */
  }

  if (fprototypes[calltree_entry].nreturns == -1)
    {
		//int b;

				if (! system_function(funcname) && is_bolton_function(funcname)==-1) {
						callstack++;
						if (callstack<5) {
							gen_function_prototypes(calltree_entry, &this_module.module_entries.module_entries_val[calltree_entry]->module_entry_u.function_definition);
					   }
						callstack--;
				}
	}

  if (fprototypes[calltree_entry].nreturns == -1)
    {
      printf ("Functions (%s) return values  have not been 'described' yet -assuming single int\n", funcname);
	return DTYPE_INT;
      //exit (2);
    }

  if (fprototypes[calltree_entry].nreturns == 0)
    {
      //char buff[256];
      //sprintf (buff, "Function %s does not return a value but is being used where it should return a value", funcname);

	A4GL_lint (0, 0, "FUNCNOTRET", "Function does not return a value but is being used where it should return a value", funcname);
      //A4GL_lint (buff);
      return -1;
    }

  if (fprototypes[calltree_entry].nreturns != 1)
    {
      //char buff[256];
	A4GL_lint (0, 0, "FUNCRETMANY", "Function returns more than one value but is being used where it should return only one", funcname);
      //sprintf (buff, "Function %s returns %d values but is being used where it should return only one", funcname, fprototypes[calltree_entry].nreturns);
      //A4GL_lint (buff);
      return -1;
    }

  return fprototypes[calltree_entry].return_dtypes[0];

}


/********************************************************************************/

static void scan_module_entry(int *calltree, int a) {
		struct module_entry *m;
		struct commands *rep_commands=0;

		m=this_module.module_entries.module_entries_val[a];

		switch (m->met_type) {
			case E_MET_MAIN_DEFINITION: 
					//A4GL_lint("MAIN shouldn't be called from MAIN!");
					A4GL_lint (0, 0, "MAINMAIN", "MAIN shouldnt be called from MAIN", 0);
					break;

			case E_MET_FUNCTION_DEFINITION: 
				set_lint_module(m->module_entry_u.function_definition.module);
				scan_functions(m->module_entry_u.function_definition.funcname, a,calltree, &m->module_entry_u.function_definition.call_list,m->module_entry_u.function_definition.func_commands); 
				break;

			case E_MET_REPORT_DEFINITION: 
				set_lint_module(m->module_entry_u.report_definition.module);
				rep_commands=linearise_report(0, m->module_entry_u.  pdf_report_definition.report_format_section);
				scan_functions(m->module_entry_u.report_definition.funcname, a,calltree, &m->module_entry_u.report_definition.call_list,rep_commands); 
				break;

			case E_MET_PDF_REPORT_DEFINITION: 
				set_lint_module(m->module_entry_u.pdf_report_definition.module);
				rep_commands=linearise_report(0, m->module_entry_u.  pdf_report_definition.report_format_section);
				scan_functions(m->module_entry_u.pdf_report_definition.funcname, a,calltree, &m->module_entry_u.pdf_report_definition.call_list,rep_commands); 
				break;

		case E_MET_FORMHANDLER_DEFINITION:
			printf("Not implemented yet (E_MET_FORMHANDLER_DEFINITION.6)\n");
			exit(4);
			break;

			default: 
				break;
	
		}
}


/********************************************************************************/
static int promoteable(int a, int b) {
A4GL_assertion(a==DTYPE_SERIAL||b==DTYPE_SERIAL,"No serials in here..");
if (a==b) return a;

a=a&DTYPE_MASK;
b=b&DTYPE_MASK;

if (a==DTYPE_DTIME && b==DTYPE_DTIME) return DTYPE_DTIME;
if (a==DTYPE_CHAR && b==DTYPE_CHAR) return DTYPE_CHAR;
if (a==DTYPE_CHAR && b==DTYPE_VCHAR) return DTYPE_VCHAR;
if (a==DTYPE_VCHAR && b==DTYPE_CHAR) return DTYPE_VCHAR;
if (a==DTYPE_VCHAR && b==DTYPE_VCHAR) return DTYPE_VCHAR;

if (a==DTYPE_DATE && b==DTYPE_DATE) return DTYPE_DATE;
if (a==DTYPE_SERIAL) a=DTYPE_INT;
if (b==DTYPE_SERIAL) b=DTYPE_INT;

if (a==DTYPE_SMINT) {
	if (b==DTYPE_SMINT) return DTYPE_SMINT;
	if (b==DTYPE_INT) return DTYPE_INT;
	if (b==DTYPE_FLOAT) return DTYPE_FLOAT;
	if (b==DTYPE_SMFLOAT) return DTYPE_SMFLOAT;
	if (b==DTYPE_DECIMAL) return DTYPE_DECIMAL;
	if (b==DTYPE_MONEY) return DTYPE_MONEY;
	if (b==90) return DTYPE_SMINT;
}

if (a==DTYPE_INT) {
	if (b==DTYPE_SMINT) return DTYPE_INT;
	if (b==DTYPE_INT) return DTYPE_INT;
	if (b==DTYPE_FLOAT) return DTYPE_FLOAT;
	if (b==DTYPE_SMFLOAT) return DTYPE_SMFLOAT;
	if (b==DTYPE_DECIMAL) return DTYPE_DECIMAL;
	if (b==DTYPE_MONEY) return DTYPE_MONEY;
	if (b==90) return DTYPE_INT;
}

if (a==DTYPE_FLOAT) {
	if (b==DTYPE_SMINT) return DTYPE_FLOAT;
	if (b==DTYPE_INT) return DTYPE_FLOAT;
	if (b==DTYPE_FLOAT) return DTYPE_FLOAT;
	if (b==DTYPE_SMFLOAT) return DTYPE_FLOAT;
	if (b==DTYPE_DECIMAL) return DTYPE_DECIMAL;
	if (b==DTYPE_MONEY) return DTYPE_MONEY;
}

if (a==DTYPE_SMFLOAT) {
	if (b==DTYPE_SMINT) return DTYPE_SMFLOAT;
	if (b==DTYPE_INT) return DTYPE_SMFLOAT;
	if (b==DTYPE_FLOAT) return DTYPE_FLOAT;
	if (b==DTYPE_SMFLOAT) return DTYPE_SMFLOAT;
	if (b==DTYPE_DECIMAL) return DTYPE_DECIMAL;
	if (b==DTYPE_MONEY) return DTYPE_MONEY;
}

if (a==DTYPE_DECIMAL) {
	if (b==DTYPE_SMINT) return DTYPE_DECIMAL;
	if (b==DTYPE_INT) return DTYPE_DECIMAL;
	if (b==DTYPE_FLOAT) return DTYPE_DECIMAL;
	if (b==DTYPE_SMFLOAT) return DTYPE_DECIMAL;
	if (b==DTYPE_DECIMAL) return DTYPE_DECIMAL;
	if (b==DTYPE_MONEY) return DTYPE_DECIMAL;
}

if (a==DTYPE_MONEY) {
	if (b==DTYPE_SMINT) return DTYPE_DECIMAL;
	if (b==DTYPE_INT) return DTYPE_DECIMAL;
	if (b==DTYPE_FLOAT) return DTYPE_DECIMAL;
	if (b==DTYPE_SMFLOAT) return DTYPE_DECIMAL;
	if (b==DTYPE_DECIMAL) return DTYPE_DECIMAL;
	if (b==DTYPE_MONEY) return DTYPE_MONEY;
}
if (a==90) {
	if (b==DTYPE_SMINT) return DTYPE_DECIMAL;
	if (b==DTYPE_INT) return DTYPE_DECIMAL;
	if (b==90) return 90;
}
return -1;
}

//
// go through all the calls made by this function 
// and ensure that they are marked as called
//
static void scan_functions(char *infuncname, int calltree_entry, int *calltree, struct call_list *f, struct commands *calling_funcs_cmds) {
int a;
int b;
struct commands *func_cmds=0;
struct command *r=0;
if (dbg) {printf("DBG:In scan functions : %s %d\n", infuncname,calltree_entry); fflush(stdout);}

	/*
	for (a=0;a<f->calls_by_call.calls_by_call_len;a++) {
		struct command *c;
		c=f->calls_by_call.calls_by_call_val[a];

		if (c->cmd_data.type==E_CMD_CALL_CMD) {
			expr_str *e;
			e=c->cmd_data.command_data_u.call_cmd.fcall;
			if (e->expr_type==ET_EXPR_FCALL) {
				b=find_function(e->expr_str_u.expr_function_call->fname);
				if (b==-1) {
					char buff[256];
					yylineno=e->expr_str_u.expr_function_call->line;
					sprintf(buff, "Function %s was called but is not defined ", e->expr_str_u.expr_function_call->fname);
					A4GL_lint(buff);
					continue;
				}
				printf("Function found @ %d\n",b);
				// Have we called this function before ? 
				if (calltree[b]==0) {
					// No - ok - spider down into this function to get all the functions that it calls...
					calltree[b]++;
					printf("Finding function calls in function\n");
					scan_module_entry(calltree, b);
				}
				continue;
			}
			printf("Unexpected expression type : %d while checking for function calls\n", e->expr_type); exit(3);
		}
		printf("Unexpected call type : %d while checking for function calls\n", c->cmd_data.type); exit(3);
	}
	*/


	// We only need to check the calls by expr for now - as these will include all the calls_by_call - 
	// we just cant check the return values just yet...
	for (a=0;a<f->calls_by_expr.calls_by_expr_len;a++) {
		expr_str *e;
		int nparam;
		e= f->calls_by_expr.calls_by_expr_val[a];
		if (e->expr_type==ET_EXPR_FCALL) {
			b=find_function(e->expr_str_u.expr_function_call->fname);
			if (b==-1) {
				if (! system_function(e->expr_str_u.expr_function_call->fname) && is_bolton_function(e->expr_str_u.expr_function_call->fname)==-1) {
					//char buff[256];
					yylineno=e->expr_str_u.expr_function_call->line;
					A4GL_lint (e->expr_str_u.expr_function_call->module, e->expr_str_u.expr_function_call->line, "FUNCNOTDEF", "Function was called but is not defined",  e->expr_str_u.expr_function_call->fname);
								log_proto(e, 0);
					//sprintf(buff, "Function %s was called but is not defined", e->expr_str_u.expr_function_call->fname);
					//A4GL_lint(buff);
					continue;
				}
				continue;
			}
			if (dbg) printf("DBG: Function found @ %d\n",b);
			if (e->expr_str_u.expr_function_call->parameters) {
				e->expr_str_u.expr_function_call->parameters=A4GL_rationalize_list(e->expr_str_u.expr_function_call->parameters);
				nparam=e->expr_str_u.expr_function_call->parameters->list.list_len;
			} else {
				nparam=0;
			}
			
			// Now - we have the function prototypes in fprototypes - lets see if we have the right number of parameters
			if ( nparam != fprototypes[b].nparams) {
				char buff[256];
				yylineno=e->expr_str_u.expr_function_call->line;
				sprintf(buff, "Function %s expected %d passed %d", e->expr_str_u.expr_function_call->fname, fprototypes[b].nparams, nparam);
				A4GL_lint (e->expr_str_u.expr_function_call->module, e->expr_str_u.expr_function_call->line, "FUNCPARMCNT", "Function called with wrong number of parameters", buff);
				//sprintf(buff, "Function %s expected %d parameters but is being passed %d", e->expr_str_u.expr_function_call->fname, fprototypes[b].nparams, nparam);
				//A4GL_lint(buff);
			} else {
				int ecnt;
				A4GL_assertion(nparam!=fprototypes[b].nparams,"If test ?");
				for (ecnt=0;ecnt<nparam;ecnt++) {
					int etype;
					yylineno=e->expr_str_u.expr_function_call->line;
					etype= expr_datatype(e->expr_str_u.expr_function_call->parameters->list.list_val[ecnt]) &DTYPE_MASK;

					if (promoteable(etype, fprototypes[b].param_dtypes[ecnt])==-1) {
						char buff[256];
						char smbuff[256]="";
#ifdef DUMP_PROTOTYPE
						int c;
						strcpy(smbuff," ");
						strcat(smbuff,e->expr_str_u.expr_function_call->fname);
						strcat(smbuff,"(");
						for (c=0;c<nparam;c++) {
							if (c) strcat(smbuff,",");
							sprintf(buff,"%d", fprototypes[b].param_dtypes[c]);
							strcat(smbuff,buff);
						}
						strcat(smbuff,")"); 
#endif
						sprintf(buff, "Function %s expects %s got %s @ %d parameter", e->expr_str_u.expr_function_call->fname,
								dtype_as_string(fprototypes[b].param_dtypes[ecnt]), 
								//fprototypes[b].param_dtypes[ecnt], 
								dtype_as_string(etype),
								//etype
								ecnt+1
								);
						if (strlen(smbuff)) strcat(buff,smbuff);
						A4GL_lint (e->expr_str_u.expr_function_call->module, e->expr_str_u.expr_function_call->line, "FUNCPARMTYPE", "Incompatible parameter for function", buff);
						//A4GL_lint(buff);
					}
				}
			}
			
			// Have we called this function before ? 
			if (calltree[b]==0) {
				// No - ok - spider down into this function to get all the functions that it calls...
				calltree[b]++;
				if (dbg) printf("DBG: Finding function calls in function\n");
				scan_module_entry(calltree, b);
			}
			continue;
		}
		printf("Unexpected expression type : %d while checking for function calls\n", e->expr_type); exit(3);
	}




   	func_cmds=linearise_commands(0, 0);
 	linearise_commands(func_cmds, calling_funcs_cmds);


	// Now - lets have a look and see if we call any reports...
   	for (a=0;a<func_cmds->cmds.cmds_len;a++) {
			r=func_cmds->cmds.cmds_val[a];

			if (r->cmd_data.type==E_CMD_START_CMD) { // 
					int b;
					b=find_function(r->cmd_data.command_data_u.start_cmd.repname);
					A4GL_assertion(b<0,"Couldnt find report");
					if (calltree[b]==0) {
						// No - ok - spider down into this function to get all the functions that it calls...
						calltree[b]++;
						if (dbg) printf("DBG: Finding function calls in function\n");
						scan_module_entry(calltree, b);
					}
			}

			if (r->cmd_data.type==E_CMD_FINISH_CMD) { // 
					int b;
					//printf("%s\n", r->cmd_data.command_data_u.finish_cmd.repname);
					b=find_function(r->cmd_data.command_data_u.finish_cmd.repname);
					A4GL_assertion(b<0,"Couldnt find report");
					if (calltree[b]==0) {
						// No - ok - spider down into this function to get all the functions that it calls...
						calltree[b]++;
						if (dbg) printf("DBG: Finding function calls in function\n");
						scan_module_entry(calltree, b);
					}
		
			}

			if (r->cmd_data.type==E_CMD_WHENEVER_CMD) {
				int b;
				if (r->cmd_data.command_data_u.whenever_cmd.whencode &0x2) { // WHENEVER ERROR CALL
					b=find_function(r->cmd_data.command_data_u.whenever_cmd.whento);
					if (calltree[b]==0) {
						calltree[b]++;
						scan_module_entry(calltree, b);
					}
				}
			}
			if (r->cmd_data.type==E_CMD_OUTPUT_CMD) { // 
					int b;
					//printf("%s\n", r->cmd_data.command_data_u.output_cmd.repname);
					b=find_function(r->cmd_data.command_data_u.output_cmd.repname);
					A4GL_assertion(b<0,"Couldnt find report");
					if (calltree[b]==0) {
						// No - ok - spider down into this function to get all the functions that it calls...
						calltree[b]++;
						if (dbg) printf("DBG: Finding function calls in function\n");
						scan_module_entry(calltree, b);
					}
			}


	}

	// We should now have scanned all our called function...
	// return types should therefore have been set - we can look to see what we're returning...
	if (dbg) printf("DBG : Examining return values\n");


	// Have we already processed the return values for this function ? 
	if (fprototypes[calltree_entry].nreturns==-1) {
		// No - we havent lets get all the commands in a list
		// so we can easily go through them

		//printf("Function %s contains %d commands\n", infuncname, func_cmds->cmds.cmds_len);
   		for (a=0;a<func_cmds->cmds.cmds_len;a++) {
			r=func_cmds->cmds.cmds_val[a];



			//printf("Cmd %d - type = %d\n", a, r->cmd_data.type);
			// Its a return
			if (r->cmd_data.type==E_CMD_RETURN_CMD) {
				if (dbg) {printf("DBG: Got a return in %s @ %d\n", infuncname, r->lineno);  fflush(stdout);}
				if (dbg) {printf("DBG: fprototypes[calltree_entry].nreturns=%d\n", fprototypes[calltree_entry].nreturns);}
				if (fprototypes[calltree_entry].nreturns==-1) {
					int nrets;
					if (r->cmd_data.command_data_u.return_cmd.retvals) {
						nrets=r->cmd_data.command_data_u.return_cmd.retvals->list.list_len;
					} else {
						nrets=0;
					}
					fprototypes[calltree_entry].nreturns=nrets;
					fprototypes[calltree_entry].return_dtypes=malloc(sizeof(long)*fprototypes[calltree_entry].nreturns);

					for (b=0;b<nrets;b++)  {
						expr_str *e;
						e=r->cmd_data.command_data_u.return_cmd.retvals->list.list_val[b];
						yylineno=r->lineno;
						fprototypes[calltree_entry].return_dtypes[b]=expr_datatype(e);
					}
				} else {
					int nrets;
					yylineno=r->lineno;
					if ( r->cmd_data.command_data_u.return_cmd.retvals==0) {
						nrets=0;
					} else {
						nrets=r->cmd_data.command_data_u.return_cmd.retvals->list.list_len;
					}
					if (fprototypes[calltree_entry].nreturns!=nrets) {
						//A4GL_lint("Function returns different numbers of values");
						A4GL_lint (r->module, r->lineno, "FUNCRETCNT", "Function RETURNs different numbers of values(7)", 0);
					} else {
						for (b=0;b<nrets;b++)  {
							expr_str *e;
							int dtype1;
							int dtype2;
	
							e=r->cmd_data.command_data_u.return_cmd.retvals->list.list_val[b];
							dtype1=fprototypes[calltree_entry].return_dtypes[b];
						yylineno=r->lineno;
							dtype2=expr_datatype(e);
							
							if (dtype1!=dtype2) {
								int final_dtype;
								char buff[256];	
								// if we've previously returned a smallint and now are returning an integer
								// that should be fine - we just need to change our prototype...
								final_dtype=promoteable(dtype1,dtype2);
								if (final_dtype==-1) {
									sprintf(buff,"Expression %d type %s!=%s", b+1, dtype_as_string(dtype1),dtype_as_string(dtype2));
									A4GL_lint (r->module, r->lineno, "FUNCRETTYPE", "Return value has a different type", buff);
									//A4GL_lint(buff);
								} else {
									fprototypes[calltree_entry].return_dtypes[b]=final_dtype;
								}
							}
						}
				
					}
				}
			}
		}
	}

}



int check_program(module_definition *mods, int nmodules) {
char *dbname=0;
int a;
int b;
int *calltree;
int bad_load=0;
int main_cnt=0;
struct commands *all_cmds=0;
char *fname;


fname=acl_getenv_not_set_as_0("CFUNCSFILE");
if (fname)  {
	load_boltons(fname);
} else {
	printf("WARNING - not CFUNCSFILE file specified\n");
}
	this_module.module_name="COMPOSITE";
	this_module.module_entries.module_entries_len=0;
	this_module.module_entries.module_entries_val=0;
	yylineno=0;
	
	for (a=0;a<nmodules;a++) {
		for (b=a+1;b<nmodules;b++) {
			if (A4GL_aubit_strcasecmp(mods[a].module_name,mods[b].module_name)==0) {
				bad_load++;
				printf("Module :%s loaded more than once...\n", mods[a].module_name);
			}
		}
	}
	if (bad_load) {
		exit(1);
	}

	for (a=0;a<nmodules;a++) {
			char buff1[256];
			char buff2[256];
		for (b=a+1;b<nmodules;b++) {

			if (mods[a].module_name[0]=='F') { strcpy(buff1,&mods[a].module_name[1]); }else { strcpy(buff1,mods[a].module_name); }	
			if (mods[b].module_name[0]=='F') { strcpy(buff2,&mods[b].module_name[1]); }else { strcpy(buff2,mods[b].module_name); }	

			if (A4GL_aubit_strcasecmp(buff1,buff2)==0) {
						A4GL_lint (mods[a].module_name, 0, "MODNAME", "Module name used for Function and non-function module",buff1);
			}
		}
	}

	for (a=0;a<nmodules;a++) {
		if (mods[a].mod_dbname) {
			if (dbname==0) dbname=mods[a].mod_dbname;
			else {
				if (A4GL_aubit_strcasecmp(dbname, mods[a].mod_dbname)) {
					char buff[256];
					if (strlen(mods[a].mod_dbname) && strlen(dbname))  {
						sprintf(buff,"%s!=%s", dbname, mods[a].mod_dbname);
						A4GL_lint (mods[a].module_name, 0, "DBDIFF", "Module compiled against a different database", buff);
					}
					if (strlen(dbname)==0 && strlen(mods[a].mod_dbname)>0) {
						dbname=mods[a].mod_dbname;
					}
					//A4GL_lint(buff);
				}
			}
		}

		printf("Module : %s.4gl\n", mods[a].module_name);
		for (b=0;b<mods[a].module_entries.module_entries_len;b++) {
			add_all_module_entry(mods[a].module_entries.module_entries_val[b]);
		}

	}
	for (a=0;a<nmodules;a++) {
		lint_module=mods[a].module_name;
		check_module(&mods[a]);
	}

	printf("Program\n");


	lint_module="PROGRAM";


	// Create and clear down some cache informaton for 
	// function definitions/calls
	calltree=malloc(sizeof(int)* this_module.module_entries.module_entries_len);
	fprototypes=malloc(sizeof(struct s_function_prototype)* this_module.module_entries.module_entries_len);



	for (a=0;a< this_module.module_entries.module_entries_len;a++) {
		calltree[a]=0;

		fprototypes[a].proto_type	=0;
		fprototypes[a].pname	=0;
		fprototypes[a].nparams		=-1;
		fprototypes[a].nreturns		=-1;
		fprototypes[a].param_dtypes 	=0;
		fprototypes[a].return_dtypes	=0;
	}


	// Go through and generate our function prototypes - 
	// so we can check these really quickly
	for (a=0;a< this_module.module_entries.module_entries_len;a++) {
		struct module_entry *m;
		m=this_module.module_entries.module_entries_val[a];
		switch (m->met_type) {
			case E_MET_FUNCTION_DEFINITION: 
				{
				struct s_function_definition *f;
				f=&m->module_entry_u.function_definition;
				fprototypes[a].proto_type=PROTO_FUNCTION;
				fprototypes[a].pname=f->funcname;

				f->parameters=expand_parameters(&f->variables, f->parameters);
				if (f->parameters==0) {
					fprototypes[a].nparams=0;
				} else {
					fprototypes[a].nparams=f->parameters->list.list_len;
				}

				if (fprototypes[a].nparams) {
					fprototypes[a].param_dtypes=malloc(sizeof(long)* fprototypes[a].nparams);

					for (b=0;b<f->parameters->list.list_len;b++) {
						fprototypes[a].param_dtypes[b] =expr_datatype(f->parameters->list.list_val[b])&DTYPE_MASK ;
					}

				}
				gen_function_prototypes(a, f);
				}
				break;

			case E_MET_MAIN_DEFINITION: 
				{
				struct s_function_definition *f;
				f=&m->module_entry_u.function_definition;
				fprototypes[a].proto_type=PROTO_FUNCTION;
				fprototypes[a].pname=f->funcname;
				if (f->parameters==0) {
					fprototypes[a].nparams=0;
				} else {
					fprototypes[a].nparams=f->parameters->list.list_len;
				}

				if (fprototypes[a].nparams) {
					fprototypes[a].param_dtypes=malloc(sizeof(long)* fprototypes[a].nparams);
					for (b=0;b<f->parameters->list.list_len;b++) {
						fprototypes[a].param_dtypes[b] =expr_datatype(f->parameters->list.list_val[b]) &DTYPE_MASK;
					}
				}
				}
				break;
			
			case E_MET_REPORT_DEFINITION: 
				{
				struct s_report_definition *fr;
				fr=&m->module_entry_u.report_definition;
				fprototypes[a].proto_type=PROTO_REPORT;
				fprototypes[a].pname=fr->funcname;
				if (fr->parameters==0) {
					fprototypes[a].nparams=0;
				} else {
					fprototypes[a].nparams=fr->parameters->list.list_len;
				}

				if (fprototypes[a].nparams) {
					fprototypes[a].param_dtypes=malloc(sizeof(long)* fprototypes[a].nparams);
					for (b=0;b<fr->parameters->list.list_len;b++) {
						fprototypes[a].param_dtypes[b] =expr_datatype(fr->parameters->list.list_val[b]) &DTYPE_MASK;
					}
				}
				}
				break;

			case E_MET_PDF_REPORT_DEFINITION: 
				{
				struct s_pdf_report_definition *fr;
				fr=&m->module_entry_u.pdf_report_definition;
				fprototypes[a].proto_type=PROTO_REPORT;
				fprototypes[a].pname=fr->funcname;
				if (fr->parameters==0) {
					fprototypes[a].nparams=0;
				} else {
					fprototypes[a].nparams=fr->parameters->list.list_len;
				}

				if (fprototypes[a].nparams) {
					fprototypes[a].param_dtypes=malloc(sizeof(long)* fprototypes[a].nparams);
					for (b=0;b<fr->parameters->list.list_len;b++) {
						fprototypes[a].param_dtypes[b] =expr_datatype(fr->parameters->list.list_val[b]) & DTYPE_MASK;
					}
				}
				}
				break;
		case E_MET_FORMHANDLER_DEFINITION:
			printf("Not implemented yet (E_MET_FORMHANDLER_DEFINITION.1)\n");
			exit(4);
			break;
		default : break;  // Cant have a function prototype
		}
	}


	bad_load=0;
	// lets look for any duplicates...
	for (a=0;a<this_module.module_entries.module_entries_len;a++) {
			char *mod_a="Unknown";
			int yylineno_a=-1;
			char *mod_b="Unknown";
			int yylineno_b=-1;
				switch (this_module.module_entries.module_entries_val[a]->met_type) {
					case E_MET_PDF_REPORT_DEFINITION: 
						yylineno_a=this_module.module_entries.module_entries_val[a]->module_entry_u.pdf_report_definition.lineno;
						mod_a=this_module.module_entries.module_entries_val[a]->module_entry_u.pdf_report_definition.module;
						break;
					case E_MET_REPORT_DEFINITION: 
						yylineno_a=this_module.module_entries.module_entries_val[a]->module_entry_u.report_definition.lineno;
						mod_a=this_module.module_entries.module_entries_val[a]->module_entry_u.report_definition.module;
						break;
					case E_MET_FUNCTION_DEFINITION: 
						yylineno_a=this_module.module_entries.module_entries_val[a]->module_entry_u.function_definition.lineno;
						mod_a=this_module.module_entries.module_entries_val[a]->module_entry_u.function_definition.module;
						break;

					default: break;
				}
		if (fprototypes[a].pname==0) continue;

		for (b=a+1;b<this_module.module_entries.module_entries_len;b++) {
			if (fprototypes[b].pname==0) continue;
			if (A4GL_aubit_strcasecmp(fprototypes[a].pname, fprototypes[b].pname)==0) {
				char buff[256];
				switch (this_module.module_entries.module_entries_val[b]->met_type) {
					case E_MET_PDF_REPORT_DEFINITION: 
						yylineno_b=this_module.module_entries.module_entries_val[b]->module_entry_u.pdf_report_definition.lineno;
						mod_b=this_module.module_entries.module_entries_val[b]->module_entry_u.pdf_report_definition.module;
						break;
					case E_MET_REPORT_DEFINITION: 
						yylineno_b=this_module.module_entries.module_entries_val[b]->module_entry_u.report_definition.lineno;
						mod_b=this_module.module_entries.module_entries_val[b]->module_entry_u.report_definition.module;
						break;
					case E_MET_FUNCTION_DEFINITION: 
						yylineno_b=this_module.module_entries.module_entries_val[b]->module_entry_u.function_definition.lineno;
						mod_b=this_module.module_entries.module_entries_val[b]->module_entry_u.function_definition.module;
						break;
					default: break;
				}
				yylineno=yylineno_b;
				bad_load++;


				sprintf(buff,"%s First in %s.4gl Lines %d (%s.4gl %d, %d %d)",fprototypes[a].pname,  mod_a,yylineno_a, mod_b, yylineno_b, a,b);
				 A4GL_lint (mod_b, yylineno_b, "FUNCDUP", "Function name is duplicated", buff);

			}
		}
	}

	if (bad_load) {
		printf("Aborting further lint checks\n");
		exit(2);
	}

	// Ok - starting with our 'main' - call any functions called by this one...
	for (a=0;a< this_module.module_entries.module_entries_len;a++) {
		struct module_entry *m;
		m=this_module.module_entries.module_entries_val[a];
		switch (m->met_type) {
			case E_MET_MAIN_DEFINITION: 
				main_cnt++;
				set_lint_module(m->module_entry_u.function_definition.module);
				calltree[a]++;
				scan_functions("MAIN", a,calltree, &m->module_entry_u.function_definition.call_list, m->module_entry_u.function_definition.func_commands); break;
			default: break;
		}
	}

	// Did we find any main ? 
	if (main_cnt==0) {
			 A4GL_lint ("PROGRAM", 0, "NOMAIN", "Program has no MAIN", 0);
		nomain++;
	}


	// Did we find more than one!
	if (main_cnt>1) {
			 A4GL_lint ("PROGRAM", 0, "MAINDUP", "Program has more than one MAIN",0);
	}

	// Right - we should have searched all our functions
	// and all the functions called by our functions etc
	// whats not been called at all ? 
	for (a=0;a< this_module.module_entries.module_entries_len;a++) {
		struct module_entry *m;
		m=this_module.module_entries.module_entries_val[a];
		if (calltree[a]==0) {
			switch (m->met_type) {
				case E_MET_FUNCTION_DEFINITION: 
					yylineno= m->module_entry_u.function_definition.lineno;
					A4GL_lint (m->module_entry_u.function_definition.module, m->module_entry_u.function_definition.lineno, "FUNCNOTCALLED", "Function is defined but never called", m->module_entry_u.function_definition.funcname);
					break;
				default: // dont care
					break;
			}
		}
	}
	


	for (a=0;a<nmodules;a++) {
		int mod_used=0;
		for (b=0;b<mods[a].module_entries.module_entries_len;b++) {
			struct module_entry *m;
			int fno;
			m=mods[a].module_entries.module_entries_val[b];
			switch (m->met_type) {
			case E_MET_FUNCTION_DEFINITION:
				fno=find_function(m->module_entry_u.function_definition.funcname);
				if (calltree[fno]) mod_used++;
				break;

			default: mod_used++;
			}
		}
		if (mod_used==0) {
			A4GL_lint (mods[a].module_name, 0, "MODNOTCALLED", "No Functions are called",0 );
		}
	}



	for (a=0;a<nmodules;a++) {
		check_whenever_abuse (&mods[a]);
	}

  all_cmds=linearise_commands(0, 0);

  linearise_module(all_cmds, &this_module);
  check_functions_in_module(calltree, &this_module);





   // Look for OPEN FORM but not DISPLAYed...
   for (a=0;a<all_cmds->cmds.cmds_len;a++) {
	if (all_cmds->cmds.cmds_val[a]->cmd_data.type==E_CMD_OPEN_FORM_CMD) {
		int used=0;
		for (b=0;b<all_cmds->cmds.cmds_len;b++) {

			// Prepares can be used for DECLARE or for EXECUTE
			if ( all_cmds->cmds.cmds_val[b]->cmd_data.type==E_CMD_DISPLAY_FORM_CMD) {
				if (A4GL_aubit_strcasecmp(
					get_ident_as_string(all_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.open_form_cmd.formname)
					, 
					get_ident_as_string(all_cmds->cmds.cmds_val[b]->cmd_data.command_data_u.display_form_cmd.formname)
					)==0) {
					used++;
				}
			}
		}

		if (!used) {
			yylineno=all_cmds->cmds.cmds_val[a]->lineno;
			A4GL_lint (all_cmds->cmds.cmds_val[a]->module, yylineno, "FORMNOTDISP", "FORM is OPENed but not DISPLAYed",get_ident_as_string(all_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.open_form_cmd.formname));
			//sprintf(buff,"FORM (%s) is OPENed but not DISPLAYed", A4GL_strip_quotes(all_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.open_form_cmd.formname));
		}
	}
   }

   // CURRENT WINDOW IS or CLOSE WINDOW but not OPENED...
   for (a=0;a<all_cmds->cmds.cmds_len;a++) {
	int found_something=0;
	char *cwindow="undefined";
	char *action="undefined";
	if (all_cmds->cmds.cmds_val[a]->cmd_data.type==E_CMD_CURRENT_WIN_CMD) {
				if (A4GL_aubit_strcasecmp(get_ident_as_string(all_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.current_win_cmd.windowname),"screen")!=0) {
					// CURRENT WINDOW IS SCREEN should always be ok :-)
					found_something++;
					cwindow=get_ident_as_string(all_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.current_win_cmd.windowname);
					action="has been made CURRENT";
				}
	}
	if (all_cmds->cmds.cmds_val[a]->cmd_data.type==E_CMD_CLOSE_CMD) {
			if (all_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.close_cmd.cl_type==E_CT_WINDOW) {
				found_something++;
				cwindow=get_ident_as_string(all_cmds->cmds.cmds_val[a]->cmd_data.command_data_u.close_cmd.ident);
				action="has been CLOSEd";
			}
	}


	if (found_something) {
		int used=0;
		for (b=0;b<all_cmds->cmds.cmds_len;b++) {
			if ( all_cmds->cmds.cmds_val[b]->cmd_data.type==E_CMD_OPEN_WINDOW_CMD) {
				if (A4GL_aubit_strcasecmp(cwindow, get_ident_as_string(all_cmds->cmds.cmds_val[b]->cmd_data.command_data_u.open_window_cmd.windowname))==0) {
					used++;
				}
			}
		}

		if (!used) {
			yylineno=all_cmds->cmds.cmds_val[a]->lineno;
			if (A4GL_aubit_strcasecmp(action, "has been made CURRENT")==0) {
				A4GL_lint (all_cmds->cmds.cmds_val[a]->module, yylineno, "WINDOWNOTOPEN", "CURRENT WINDOW for window which is never OPENed", cwindow);
			}
			if (A4GL_aubit_strcasecmp(action, "has been CLOSEd")==0) {
				A4GL_lint (all_cmds->cmds.cmds_val[a]->module, yylineno, "WINDOWNOTOPEN", "CLOSE WINDOW for window which is never OPENed", cwindow);
			}
		}
	}
   }


   return 1;
}


void set_lint_module (char *s) {
	lint_module=s;
}


void A4GL_lint (char *module_in, int lintline, char *code, char *type, char *extra)
{
char buff[256];
char module[255];

  if (module_in==0) {
		printf("WARNING : %s does not pass in a module!\n", code);
		module_in=lint_module;
	}
  if (module_in==0) {
		module_in="unknown";
  }

 if (lintline==0) {
		lintline=yylineno;
  }

  if (strchr(module_in,'/')) {
	module_in=A4GL_transform_basename(module_in);
  }


  strcpy(module,module_in);

	if (strstr(module,".4gl")) {
		char *ptr;
		ptr=strstr(module,".4gl");
		*ptr=0;
	}


  if (!A4GL_isyes (acl_getenv ("SUPPRESSLINT")))
    {
	
	switch (get_lint_style()) {
		
	case 0:
  		sprintf(buff,"%s.4gl Line %d",module,lintline);
		if (extra) {
      			fprintf (stderr, "  LINT : %-30s %-20s %s (%s)\n", buff, code, type, extra);
		} else {
      			fprintf (stderr, "  LINT : %-30s %-20s %s \n", buff, code, type);
		}
		break;
	case 1:
  		sprintf(buff,"%s.4gl:%d",module,lintline);
		if (extra) {
      			fprintf (lintfile, "%-20s, %-20s %s (%s)\n", buff, code, type, extra);
		} else {
      			fprintf (lintfile, "%-20s, %-20s %s \n", buff, code, type);
		}
		break;


	case 2:
		if (extra==0) extra=" ";
			if (lintfile) {
				fprintf(lintfile,"<LINT MODULE='%s.4gl' LINE='%d' CODE='%s'><DESCRIPTION>%s</DESCRIPTION><DETAILS>%s</DETAILS></LINT>\n", module,lintline, code, local_xml_escape(type), local_xml_escape(extra));
			}
		break;


	case 3:
		if (extra==0) extra=" ";
			if (lintfile) {
				fprintf(lintfile,"%s.4gl|%d|%s|%s|%s|\n", module,lintline, code, type, extra);
			}
		break;

	default:
		printf("Unhandled LINT style\n");
	}

    }


}


void open_lintfile(char *s) {
char *fname;
if (get_lint_style()==0) return ;
fname=get_lint_filename(s);
lintfile=fopen(fname,"w");
if (lintfile==0) {
	printf("Unable to open lintfile\n");
}

if (get_lint_style()==2) {
	fprintf(lintfile,"<?xml version=\"1.0\" encoding=\"utf-8\"?>\n");
	fprintf(lintfile,"<LINTS>\n");
}
	
}

void close_lintfile() {

	if (get_lint_style()==0) return ;

	if (get_lint_style()==2) {
		fprintf(lintfile,"</LINTS>\n");
	}
	if (lintfile) {
		fclose(lintfile);
	}
}


static char *get_lint_filename(char *s) {
static char buff[3000];
	if (s==0) { // no program name...
		switch (get_lint_style()) {
			case 1: // Text 
				return "lint.txt";
			case 2: // XML
				return "lint.xml";
			case 3: // UNL
				return "lint.unl";
			default: printf("Unhandled lint style\n");  return "lint.txt";
		}
	}

// No name specified
	switch (get_lint_style()) {
			case 1: // Text 
				sprintf(buff,"%s.txt", s); return buff;
			case 2: // XML
				sprintf(buff,"%s.xml", s); return buff;
			case 3: // UNL
				sprintf(buff,"%s.unl", s); return buff;
			default: printf("Unhandled lint style\n");  return "lint.txt";
	}
}



int get_lint_style(void) {
static int lintoutputstyle=-1;
if (lintoutputstyle==-1) {
        lintoutputstyle=0;

        if (A4GL_isyes(acl_getenv("LINTASTXT"))) {
                lintoutputstyle=1;
		return lintoutputstyle;
        }

        if (A4GL_isyes(acl_getenv("LINTASXML"))) {
                lintoutputstyle=2;
		return lintoutputstyle;
        }

        if (A4GL_isyes(acl_getenv("LINTASUNL"))) {
                lintoutputstyle=3;
		return lintoutputstyle;
        }
}
	return lintoutputstyle;
}



static char *local_xml_escape(char *s) {
static char *buff=0;
static int last_len=0;
int c;
int a;
int l;
int b;
c=0;
if (strchr(s,'&')) c++;
if (strchr(s,'<')) c++;
if (strchr(s,'>')) c++;
if (strchr(s,'\'')) c++;

if (c==0) {
        return s;
}

l=strlen(s);
if (l>last_len) {
        buff=realloc(buff, l*5+1);
        last_len=l;
}

b=0;
for (a=0;a<l;a++) {
        if (s[a]=='\'') { buff[b++]='&'; buff[b++]='a'; buff[b++]='p'; buff[b++]='o'; buff[b++]='s';buff[b++]=';';continue;}
        if (s[a]=='>') { buff[b++]='&'; buff[b++]='g'; buff[b++]='t'; buff[b++]=';';continue;}
        if (s[a]=='<') { buff[b++]='&'; buff[b++]='l'; buff[b++]='t'; buff[b++]=';';continue;}
        if (s[a]=='&') { buff[b++]='&'; buff[b++]='a';buff[b++]='m';buff[b++]='p';buff[b++]=';';continue;}
        buff[b++]=s[a];
}

buff[b]=0;
//printf("ESCAPE (%s)=%s\n",s,buff);
return buff;
}

static char * A4GL_transform_basename (char *s)
{
  static char buff[256];
  if (strrchr (s, '/') == 0)
    return s;
  else
    {
      sprintf (buff, "F%s", strrchr (s, '/') + 1);
      return buff;
      return strrchr (s, '/') + 1;
    }

  return  s;
}


void dump_prototypes(void) {
int b;
int a;

for (a=0;a<this_module.module_entries.module_entries_len;a++) {
	printf("FUNCTION %s ", fprototypes[a].pname);
	printf("PARAMETERS  (");
	for (b=0;b<fprototypes[a].nparams;b++) {
		if (b)printf(",");
  		printf("%d", fprototypes[a].param_dtypes[b]);
	}
	printf(") RETURNS (");
	for (b=0;b<fprototypes[a].nreturns;b++) {
		if (b)printf(",");
  		printf("%d", fprototypes[a].return_dtypes[b]);
	}
	printf(")\n");
}
}


int is_bolton_function(char *s) {
int a;
for (a=0;a<nboltons;a++) {
	if (A4GL_aubit_strcasecmp(s,fboltons[a].pname)==0) {
		return a;
	}
}
return -1;
}


/*
int is_bolton_function_ret(char *s,int r) {
	if (A4GL_aubit_strcasecmp(s,"push_server_call_arg")==0) {
		if (r==0) {
			return 0;
		}
	}
}
*/


static void add_bolton(char *fname, char*params, char *rets) {
char *p_params[200];
char *p_rets[200];
int pcnt=0;
int rcnt=0;
int l;
int a;
nboltons++;

fboltons=realloc(fboltons, sizeof(fboltons[0])*nboltons);

l=strlen(params);

if (l==0) {
	pcnt=0;
} else {
	
	pcnt=0;
	p_params[0]=params;
	for (a=0;a<=l;a++) {
		if (params[a]==','||params[a]==0) {
			params[a]=0;
			pcnt++;
			p_params[pcnt]=&params[a+1];
			continue;
		}
	}
}

l=strlen(rets);
if (l==0) {
	rcnt=0;
} else {
	
	rcnt=0;
	p_rets[0]=rets;
	for (a=0;a<=l;a++) {
		if (rets[a]==','||rets[a]==0) {
			rets[a]=0;
			rcnt++;
			p_rets[rcnt]=&rets[a+1];
			continue;
		}
	}
}

fboltons[nboltons-1].pname=strdup(fname);
fboltons[nboltons-1].proto_type=0;
fboltons[nboltons-1].nparams=pcnt;
if (pcnt) {
	fboltons[nboltons-1].param_dtypes=malloc(sizeof(int)*pcnt);
	for(a=0;a<pcnt;a++) {fboltons[nboltons-1].param_dtypes[a]=atoi(p_params[a]);}
} else {
	fboltons[nboltons-1].param_dtypes=0;
}


fboltons[nboltons-1].nreturns=rcnt;
if (rcnt) {
	fboltons[nboltons-1].return_dtypes=malloc(sizeof(int)*rcnt);
	for(a=0;a<rcnt;a++) {fboltons[nboltons-1].return_dtypes[a]=atoi(p_rets[a]);}
} else {
	fboltons[nboltons-1].return_dtypes=0;
}

/*
	int nparams;
	int *param_dtypes;
	int nreturns;
	int *return_dtypes;
};
*/
}

static void load_boltons(char *fname) {
FILE *f;
int lineno=0;
//char *funcname;
//int nparam;
//int nret;
//char *params;
//char *rets;
int printed;
char buff[256];
if (fname==0) return;
if (strlen(fname)==0) return;
f=fopen(fname,"r");
if (f==0) return;

while (1) {
	char *p[3];
	fgets(buff,255,f);
	lineno++;
	if (feof(f)) break;
	A4GL_trim(buff);
	printed=0;

	p[0]=buff;
	p[1]=strchr(buff,'|');
	if (p[1]) {
		*p[1]=0;
		p[1]++;
		p[2]=strchr(p[1],'|');
		if (p[2]) {
			*p[2]=0;
			p[2]++;
			//printf("Loading : %s %s %s\n",p[0],p[1],p[2]);
			printed++;
			add_bolton(p[0],p[1],p[2]);
		}
	} 

	if (!printed) {
		printf("Bad line : %s @ %d\n",buff,lineno);
		continue;
	}
}
}
/*
struct s_function_prototype {
	char *pname;
	int nparams;
	int *param_dtypes;
	int nreturns;
	int *return_dtypes;
};
*/



// EXPRESSION HANDLING....
// 
// To make life easier for our lint checker its a good idea to get all our functions expressions in one place
// we can do that by moving them all to the functions 'expressions_list' - we should probably be doing something
// like this at compile time - but this is the next best thing...
// So - we need to go through all the commands that use an expression and pull out that expression data
// the - we need to go through those expressions and pull out any that are used in those expressions...
// we should end up with a list of expressions at the top - which only reference cached expressions or literals


static void
linearise_expressions (struct expr_str_list *list)
{
int b;
  if (list == 0)
    return;

  if (list->list.list_len == 0)
    return;

  for (b = 0; b < list->list.list_len; b++)
    {
      if (list->list.list_val[b] == 0)
	continue;
      if (list->list.list_val[b]->expr_type == ET_EXPR_CACHED)
	continue;

      switch (list->list.list_val[b]->expr_type)
	{
	  // We're looking here for any compound expressions (ie - expressions containing another expression)

	case ET_EXPR_EXTEND:
	  {
	    	struct s_expr_extend *expr_extend;
		expr_extend=list->list.list_val[b]->expr_str_u.expr_extend;
		cache_expression(list, &expr_extend->expr);
	  }
	  break;


	case ET_EXPR_EXPR_LIST:
	case ET_EXPR_CONCAT_LIST:
	  {
	    	struct expr_str_list *expr_list;
		expr_list=list->list.list_val[b]->expr_str_u.expr_list;
		cache_expression_list(list, expr_list);
	  }
	break;

	case ET_EXPR_FCALL:
	  {
	    	struct s_expr_function_call *expr_function_call;
		expr_function_call=list->list.list_val[b]->expr_str_u.expr_function_call;
		cache_expression_list(list, expr_function_call->parameters);
	  }
	break;

	case ET_EXPR_PDF_FCALL:
	  {
	    struct s_expr_pdf_function_call *expr_pdf_function_call;
		expr_pdf_function_call=list->list.list_val[b]->expr_str_u.expr_pdf_function_call;
		cache_expression_list(list, expr_pdf_function_call->parameters);
	  }
	  break;

	case ET_EXPR_SHARED_FCALL:
	  {
	    struct s_expr_shared_function_call *expr_shared_function_call;
		expr_shared_function_call=list->list.list_val[b]->expr_str_u.expr_shared_function_call;
		cache_expression_list(list, expr_shared_function_call->parameters);
	  }
	  break;

	case ET_EXPR_MEMBER_FCALL:
	  {
	    struct s_expr_member_function_call *expr_member_function_call;
		expr_member_function_call=list->list.list_val[b]->expr_str_u.expr_member_function_call;
		cache_expression_list(list, expr_member_function_call->parameters);
	  }
	  break;

	case ET_EXPR_EXTERNAL:
	  {
	    struct s_expr_external_call *expr_external_call;
		expr_external_call=list->list.list_val[b]->expr_str_u.expr_external_call;
		cache_expression_list(list, expr_external_call->parameters);
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
	  {
	    	struct s_expr_op *expr_op;
		expr_op=list->list.list_val[b]->expr_str_u.expr_op;

		cache_expression(list, &expr_op->left);
		cache_expression(list, &expr_op->right);
		cache_expression(list, &expr_op->escape);
	  }
	  break;


	case ET_EXPR_WORDWRAP:
	  {
	    struct s_expr_wordwrap *expr_wordwrap;
		expr_wordwrap=list->list.list_val[b]->expr_str_u.expr_wordwrap;
		cache_expression(list, &expr_wordwrap->expr);
	  }
	  break;

	case ET_EXPR_OP_IN:
	case ET_EXPR_OP_NOT_IN:
	  {
	    struct s_expr_in *expr_in;
		expr_in=list->list.list_val[b]->expr_str_u.expr_in;
		cache_expression(list, &expr_in->expr);
		cache_expression_list(list, expr_in->elist);
	  }
	  break;


	case ET_EXPR_OP_IN_SUBQUERY:
	case ET_EXPR_OP_NOTIN_SUBQUERY:
	  {
	    	struct s_expr_in_sq *expr_in_sq;
		expr_in_sq=list->list.list_val[b]->expr_str_u.expr_in_sq;
		cache_expression(list, &expr_in_sq->expr);
	  }
	  break;


	case ET_EXPR_CAST:
	  {
	    	struct s_expr_cast *expr_cast;
		expr_cast=list->list.list_val[b]->expr_str_u.expr_cast;
		cache_expression(list, &expr_cast->expr);
	  }
	  break;


	case ET_EXPR_TIME_FUNC:
	case ET_EXPR_MONTH_FUNC:
	case ET_EXPR_DAY_FUNC:
	case ET_EXPR_YEAR_FUNC:
	case ET_EXPR_UPSHIFT:
	case ET_EXPR_DOWNSHIFT:
	case ET_EXPR_ASCII:
	case ET_EXPR_POINTS:
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
	case ET_EXPR_OP_SECOND:
	case ET_EXPR_NEG:
	  {
	    	struct expr_str *expr_expr;
		expr_expr=list->list.list_val[b]->expr_str_u.expr_expr;
		cache_expression(list, &expr_expr);
	  }
	  break;



	case ET_EXPR_GET_FLDBUF:
	  {
	    struct s_expr_get_fldbuf *expr_get_fldbuf;
		expr_get_fldbuf=list->list.list_val[b]->expr_str_u.expr_get_fldbuf;
		//@ FIXME
	  }
	  break;

	case ET_EXPR_INFIELD:
	  {
	    struct s_expr_infield *expr_infield;
		expr_infield=list->list.list_val[b]->expr_str_u.expr_infield;
		//@ FIXME
	  }
	  break;
	case ET_EXPR_FIELD_TOUCHED:
	case ET_EXPR_NOT_FIELD_TOUCHED:
	  {
	    struct s_expr_field_touched *expr_field_touched;
		expr_field_touched=list->list.list_val[b]->expr_str_u.expr_field_touched;
		//@ FIXME
	  }
	  break;


	case ET_EXPR_ID_TO_INT:
	case ET_EXPR_FIELDTOWIDGET:
	  {
	    	struct fh_field_entry *expr_field_entry;
		expr_field_entry=list->list.list_val[b]->expr_str_u.expr_field_entry;
		//@ FIXME
	  }
	  break;







	default: break;

	}

    }

}


static int add_cache_expression(struct expr_str_list *list, expr_str *e) {
int a;
if (list->list.list_len) {
	for (a=0;a<list->list.list_len;a++) {
		if (list->list.list_val[a]==e) return a;
	}
}

list->list.list_len++;
list->list.list_val=realloc(list->list.list_val, sizeof(expr_str *)*list->list.list_len);
list->list.list_val[list->list.list_len-1]=e;

return list->list.list_len-1;
}

static void cache_expression(struct expr_str_list *list, struct expr_str **eptr) {
	struct expr_str *e;
	struct expr_str *enew;
	e=*eptr;
	if (e==0) return;
	if (e->expr_type==ET_EXPR_CACHED) return ;
	enew=malloc(sizeof(struct expr_str));
	enew->expr_type=ET_EXPR_CACHED;
	enew->expr_str_u.expr_long=add_cache_expression(list, e);
	*eptr=enew;
}

static void cache_expression_list(struct expr_str_list *list, struct expr_str_list *srclist) {
int a;
	if (srclist==0) return;
	if (srclist->list.list_len==0) return;

	for (a=0;a<srclist->list.list_len;a++) {
		 cache_expression(list, &srclist->list.list_val[a]);
	}
}



static void cache_expressions(struct expr_str_list *list, struct commands *cmds) {
int a;
int b;
struct struct_display_cmd *disp;
list->list.list_len=0;
list->list.list_val=0;
return ;

for (a=0;a<cmds->cmds.cmds_len;a++) {
	struct command *c;
	c=cmds->cmds.cmds_val[a];


	switch (c->cmd_data.type) {
		case E_CMD_DISPLAY_CMD:  disp=&c->cmd_data.command_data_u.display_cmd;
					 cache_expression_list(list, disp->exprs); 
					 if (disp->where->dttype==DT_DISPLAY_TYPE_AT) {
						cache_expression(list, &disp->where->dt_display_u.x_y.x);
						cache_expression(list, &disp->where->dt_display_u.x_y.y);
					 }
					break;
			
		
		case E_CMD_ERROR_CMD: 	
					cache_expression_list(list, c->cmd_data.command_data_u.error_cmd.expr_list); 
					break;

		case E_CMD_SLEEP_CMD: 	
					cache_expression(list, &c->cmd_data.command_data_u.sleep_cmd.sleep_expr); 
					break;

		case E_CMD_MOVE_CMD: 
					cache_expression(list, &c->cmd_data.command_data_u.move_cmd.x); 
					cache_expression(list, &c->cmd_data.command_data_u.move_cmd.y); 
					break;

		case E_CMD_SHOW_MENU_CMD: 
					cache_expression(list, &c->cmd_data.command_data_u.show_menu_cmd.mn_file); 
					break;

		case E_CMD_RUN_CMD: 
					cache_expression(list, &c->cmd_data.command_data_u.run_cmd.run_string); 
					break;

		case E_CMD_SCROLL_CMD: 
					cache_expression(list, &c->cmd_data.command_data_u.scroll_cmd.val); 
					break;

		case E_CMD_EXIT_PROG_CMD: 
					cache_expression(list, &c->cmd_data.command_data_u.exit_prog_cmd.exit_val); 
					break;

		case E_CMD_RETURN_CMD: 
					cache_expression_list(list, c->cmd_data.command_data_u.return_cmd.retvals);
					break;

		case E_CMD_MESSAGE_CMD: 
					cache_expression_list(list, c->cmd_data.command_data_u.message_cmd.message_expr);
					break;

		case E_CMD_FOR_CMD: 
					cache_expression(list, &c->cmd_data.command_data_u.for_cmd.start);
					cache_expression(list, &c->cmd_data.command_data_u.for_cmd.end);
					cache_expression(list, &c->cmd_data.command_data_u.for_cmd.step);
					break;

		case E_CMD_CALL_CMD: 
					cache_expression(list, &c->cmd_data.command_data_u.call_cmd.fcall);
					break;

		case E_CMD_PDF_CALL_CMD: 
					cache_expression(list, &c->cmd_data.command_data_u.pdf_call_cmd.fcall);
					break;

		case E_CMD_LET_CMD: 
					cache_expression_list(list, c->cmd_data.command_data_u.let_cmd.vals);
					break;

		case E_CMD_IF_CMD: 	
					{
						struct struct_if_cmd *ifcmd;
						ifcmd=&c->cmd_data.command_data_u.if_cmd;
						for (b=0;b<ifcmd->truths.conditions.conditions_len;b++) {
							ensure_bool(ifcmd->truths.conditions.conditions_val[b].test_expr,0);
							cache_expression(list, &ifcmd->truths.conditions.conditions_val[b].test_expr);
						}
					}
					break;

		case E_CMD_CASE_CMD: 	
					{
						struct struct_case_cmd *casecmd;
						casecmd=&c->cmd_data.command_data_u.case_cmd;
						cache_expression(list, &casecmd->case_expr);
			
						for (b=0;b<casecmd->whens->whens.whens_len;b++) {
							cache_expression(list, &casecmd->whens->whens.whens_val[b]->when_expr);
						}
					}
					break;

		
		case E_CMD_OPEN_WINDOW_CMD: 
					cache_expression(list, &c->cmd_data.command_data_u.open_window_cmd.x);
					cache_expression(list, &c->cmd_data.command_data_u.open_window_cmd.y);
					if (c->cmd_data.command_data_u.open_window_cmd.wt.wintype==EWT_FORM) {
						cache_expression(list, &c->cmd_data.command_data_u.open_window_cmd.wt.windowtype_u.formfilename);
					}
					break;

		case E_CMD_FETCH_CMD: 	
					if (c->cmd_data.command_data_u.fetch_cmd.fetch) {
						if (c->cmd_data.command_data_u.fetch_cmd.fetch->fp) {
							cache_expression(list, &c->cmd_data.command_data_u.fetch_cmd.fetch->fp->fetch_expr);
						}
					}
					break;

		case E_CMD_OPEN_FORM_CMD: 
					cache_expression(list, &c->cmd_data.command_data_u.open_form_cmd.form_filename);
					break;

		case E_CMD_WHILE_CMD:
					cache_expression(list, &c->cmd_data.command_data_u.while_cmd.while_expr);
					break;
	
		case E_CMD_OUTPUT_CMD: 
					cache_expression_list(list, c->cmd_data.command_data_u.output_cmd.expressions);
					break;

		case E_CMD_SET_DATABASE_CMD: 
					cache_expression(list, &c->cmd_data.command_data_u.set_database_cmd.set_dbname);
					break;

		case E_CMD_NEED_CMD: 
					cache_expression(list, &c->cmd_data.command_data_u.need_cmd.expr);
					break;

		case E_CMD_PRINT_CMD: 
					cache_expression_list(list, c->cmd_data.command_data_u.print_cmd.print_expr);
					break;

		case E_CMD_PRINT_IMG_CMD:
					cache_expression(list, &c->cmd_data.command_data_u.print_img_cmd.scale_x);
					cache_expression(list, &c->cmd_data.command_data_u.print_img_cmd.scale_y);
					break;

		/*
		case E_CMD_PAUSE_CMD: 
					cache_expression(list, &c->cmd_data.command_data_u.pause_cmd.prompt_str);
					break;
		*/

		default: break;
	}
		
}
linearise_expressions(list);
}



void gen_function_prototypes(int e, struct s_function_definition *function_definition) {
struct commands *func_cmds;
int nreturns;
int a;
struct command *r;
int *dtypes=0;
        func_cmds=linearise_commands(0, 0);

        linearise_commands(func_cmds, function_definition->func_commands);
        nreturns=0;
        for (a=0;a<func_cmds->cmds.cmds_len;a++) {
                r=func_cmds->cmds.cmds_val[a];

                if (r->cmd_data.type==E_CMD_RETURN_CMD) {

                        if (r->cmd_data.command_data_u.return_cmd.retvals) {
                        int b;
                               nreturns=r->cmd_data.command_data_u.return_cmd.retvals->list.list_len;

				fprototypes[e].nreturns=nreturns;
				if (nreturns) {
					fprototypes[e].return_dtypes=malloc(sizeof(long)*fprototypes[e].nreturns);
                                	dtypes=realloc(dtypes,sizeof(int)*nreturns);
				} else {
					fprototypes[e].return_dtypes=0;
				}

                                for (b=0;b<nreturns;b++) {
                                                dtypes[b]=expr_datatype(r->cmd_data.command_data_u.return_cmd.retvals->list.list_val[b]);
                                                if (dtypes[b]==90) { // always return a int instead..
                                                        dtypes[b]=DTYPE_INT;
                                                }
						fprototypes[e].return_dtypes[b]= dtypes[b];
                                }
	
                        }

                        break;
                }
        }
				if (fprototypes[e].nreturns==-1) {
					fprototypes[e].nreturns=0;	
			}
}


void create_protos_from_module(module_definition *this_module) {
int a;
printf("CREATE\n");
	fprototypes=malloc(sizeof(struct s_function_prototype)* this_module->module_entries.module_entries_len);
	for (a=0;a< this_module->module_entries.module_entries_len;a++) {
		fprototypes[a].proto_type	=0;
		fprototypes[a].pname	=0;
		fprototypes[a].nparams		=-1;
		fprototypes[a].nreturns		=-1;
		fprototypes[a].param_dtypes 	=0;
		fprototypes[a].return_dtypes	=0;
	gen_function_prototypes(a, &this_module->module_entries.module_entries_val[a]->module_entry_u.function_definition);
	}

}

void log_proto( struct  expr_str *fcall, struct expr_str_list *ret) {
int a;
if (A4GL_isyes(acl_getenv("LOGPROTOS"))) {
	struct expr_str_list *l;
	FILE *f;
	f=fopen("protos.out","a");
	fprintf(f,"%s|",fcall->expr_str_u.expr_function_call->fname);
	l=A4GL_rationalize_list(fcall->expr_str_u.expr_function_call->parameters);
	for (a=0;a<l->list.list_len;a++) {
		if (a) fprintf(f,",");
		fprintf(f,"%d",expr_datatype(l->list.list_val[a])&DTYPE_MASK);
	}
	fprintf(f,"|");
	if (ret!=0) {	
		for (a=0;a<ret->list.list_len;a++) {
		if (a) fprintf(f,",");
			fprintf(f,"%d",expr_datatype(ret->list.list_val[a])&DTYPE_MASK);
		}
	}
	fprintf(f,"\n");
}
}

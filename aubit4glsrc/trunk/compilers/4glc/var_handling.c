//#include "fgl.xs.h"
#include "variables.h"
#include "a4gl_4glc_int.h"
#include "var_handling.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//static void variable_usage_as_string_int (struct variable_usage *var, char *buff, int ident_flg);



static void add_subscript(struct variable_usage *var) {
	var->subscripts.subscripts_len++;
	if (var->subscripts.subscripts_len==1) {
		var->subscripts.subscripts_val=malloc(sizeof(var->subscripts.subscripts_val[0]));
	} else {
		var->subscripts.subscripts_val=realloc(var->subscripts.subscripts_val, var->subscripts.subscripts_len*sizeof(var->subscripts.subscripts_val[0]));
	}
	var->subscripts.subscripts_val[var->subscripts.subscripts_len-1]=0;
}

void
set_variable_usage_subscript (struct variable_usage *var, int sub, expr_str *val)
{
  while (var->subscripts.subscripts_len<=sub) {
		add_subscript(var);
  }
  var->subscripts.subscripts_val[sub] = val;
}


void
set_variable_usage_substr (struct variable_usage *var, int sub, expr_str *val)
{
  if (sub > 1)
    {
      a4gl_yyerror ("Substring expression expected to be start or start,end");
      return;
    }

  if (sub==0) {
	var->substrings_start.substrings_start=val; 
  } 

  if (sub==1) {
	var->substrings_end.substrings_end=val; 
  }

}




int A4GL_check_isobject_name(char *s) {
// If adding more objects - be sure to check in 
// isBuiltinObjectType(..) in  variables.c
  if (strcasecmp (s, "base.channel") == 0)
    return DTYPE_OBJECT;
  if (strcasecmp (s, "ui.window") == 0)
    return DTYPE_OBJECT;
  if (strcasecmp (s, "ui.form") == 0)
    return DTYPE_OBJECT;
  if (strcasecmp (s, "ui.interface") == 0)
    return DTYPE_OBJECT;
  if (strcasecmp (s, "ui.combobox") == 0)
    return DTYPE_OBJECT;

  if (A4GL_ObjectTypeExists(s)) {
    return DTYPE_OBJECT;
  }

  return 0;
}


// Check to see if an expression is a Member function call - and if it is - does it have
// an alias.
//
// For example
// 	CALL lv_var.Clear() 
//
// is a 'member' function call - which does an initialize - so we might as well issue an
// initialize command instead !
struct command *check_for_member_call_alias(expr_str *p_fcall,expr_str_list *p_returning) {
	//struct variable_usage *u;
	//struct variable_usage *utop;
	//struct variable_usage *ubottom;
	if (p_fcall->expr_type!=ET_EXPR_MEMBER_FCALL_NEW) {
		return NULL;
	}


	if (A4GL_aubit_strcasecmp(p_fcall->expr_str_u.expr_member_function_call_n->funcName, "clear")==0) {
			struct expr_str_list *plist;
			if (strcmp(p_fcall->expr_str_u.expr_member_function_call_n->objectType,"ui.combobox")==0) {
				// Dont do this for the ui.combobox - it means clear the list of items...
			} else {
				plist=A4GL_new_ptr_list(p_fcall->expr_str_u.expr_member_function_call_n->var_usage_ptr);
				// Its really an INITIALIZE not a clear...
				return new_init_cmd(plist,NULL,1);
			}
	}


	return NULL;
}


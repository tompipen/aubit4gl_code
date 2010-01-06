/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-2005 Aubit Development Team (See Credits file)    |
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
# | contact licensing@aubit.com                                           |
# +----------------------------------------------------------------------+
#
# $Id: variables.c,v 1.114 2010-01-06 17:48:58 mikeaubury Exp $
#
*/

/**
 * @file
 *
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_4glc_int.h"
#include "variables.h"
#include "variables_new.h"
#include "var_handling.h"
#include <ctype.h>


/* CONFIGURABLE...*/
#define RECORD_LEVELS 128
/* */

extern int token_read_on_line;
extern char *outputfilename;
//#define PRINT_CONSTANTS
//char scopes[200];
//int scopes_cnt = 0;
//int has_fbind(char *s) ;


int class_cnt = 0;
extern module_definition this_module;

int mv_uses_constants=0; /* No of constants in module/globals */
int lv_uses_constants=0; /* No of constants local to this function/report */

static int isCreateProcedure=0;
int procVariableListCnt=0;
#define MAXPROCVARIABLESLEVELS 100
struct variable_list *procVariableList[MAXPROCVARIABLESLEVELS];

/******************************************************************************/
/* Prototypes of static functions in this module...*/
//static int has_name (struct vname_name_list *namelist, char *name);
char get_variable_user_system (void);
//static struct variable *make_constant (char *name, char *value, char *int_or_char);
//static void initialize_v (void);
//static void set_arr_subscripts (char *s, int record_cnt);
//static int add_to_scope (int record_cnt, int unroll);
//static void dump_variable_records (struct variable **v, int cnt, int lvl);
//static struct variable *find_variable_in (char *s, struct variable **list, int cnt);
//struct variable * find_variable_vu_in (char *errbuff, struct variable_usage *vu, struct variable **list, int cnt);

//struct variable * find_variable_vu_in (char *errbuff, struct variable_usage *vu, struct variable **list, int cnt,int err_if_whole_array);

//enum e_scope A4GL_get_current_variable_scope (void);

void make_arr_str (char *s, struct variable *v);
//void A4GL_strip_bracket (char *s);
char *rettype_integer (int n);
static char * describe_record(struct record_variable *v_record) ;
//static struct record_list *add_to_record_list (struct record_list **list_ptr, char *prefix_buff, struct variable *v, char bindtype);
int is_valid_vname(struct variable *v, enum e_scope scope);
//char *remap_top_level_variables(char *invarname) ;
void make_function (char *name, int record_cnt);
//int has_fbind(char *s) ;
int chk_already_defined(char *s, enum e_scope scope);

int is_system_variable (char *s);

//struct variable *find_dim(char *s);

void print_class_variables (void);
//void dump_variable_records (struct variable **v, int cnt, int lvl);
void set_last_class_var (char *s);
/******************************************************************************/

//char *A4GL_unscope(char *s);
int A4GL_findex (char *str, char c);
/*void dump_gvars (void);*/
//void set_yytext (char *s);
//int isin_command (char *s);
//char *rettype (char *s);
int last_record_cnt = 0;
static char last_class_var[1024];
extern int nreturn_values;


#define ASSOC_INTERNAL "Internal"

extern int in_define;

/* Are we setting User variables or System Variables ?*/
//char system_or_user = '-';










struct variable_list *local_variables=NULL;
enum e_scope variable_scope = E_SCOPE_MODULE;




void set_local_variables(struct variable_list *vlist) {
	local_variables=vlist;
	if (local_variables) {
        	sort_variables_v(local_variables);
	}
}

void make_constant_available(struct variable *v) {
char *name;
	name=v->names.names.names_val[0].name;

  	if (A4GL_aubit_strcasecmp(name,"notfound")==0) return;
	if (A4GL_aubit_strcasecmp(name,"true")==0)     return;
 	if (A4GL_aubit_strcasecmp(name,"false")==0)    return;

	lv_uses_constants++;
}



static int count_constants_in_list (struct variable_list *v) {
int cnt=0;
	int a;
	if (v==NULL) return 0 ;
	if (v->variables.variables_len==0) return 0;
	for (a=0;a<v->variables.variables_len;a++) {
		if (v->variables.variables_val[a]->var_data.variable_type == VARIABLE_TYPE_CONSTANT) {
			char *name;
			name= v->variables.variables_val[a]->names.names.names_val[0].name;
   			if (A4GL_aubit_strcasecmp(name,"notfound")==0) continue;
 			if (A4GL_aubit_strcasecmp(name,"true")==0)     continue;
 			if (A4GL_aubit_strcasecmp(name,"false")==0)    continue;
			A4GL_debug("CONSTANT: %s\n", v->variables.variables_val[a]->names.names.names_val[0].name);
			cnt++;

		}
	}
	return cnt;
}

static int uses_constants(void) {
	if (mv_uses_constants) { 
		// something added as a module, or global variable
		return 1;
	}
	if (lv_uses_constants) return 1;

	return 0;
}

void set_uses_constants(struct variable_list *v) {
	mv_uses_constants+=count_constants_in_list(v);
}




/******************************************************************************/





char *
A4GL_unscope (char *s)
{
  static char buff[1024];
  int sl = -1;
  sl = 0;
  strcpy (buff, s);
  if (s[0] >= 'A' && s[0] <= 'Z' && s[1] == '_')
    {

      if (A4GL_isyes (acl_getenv ("REPORT_VARS_AT_MODULE")) && s[0] == 'R')
	{
	  char b[200];
	  //int c;
	  extern char curr_func[];
	  SPRINTF2 (b, "%s_%s", A4GL_compiling_module_basename (), curr_func);

	  if (strncmp (&s[2], b, strlen (b)) == 0)
	    {
	      strcpy (buff, &s[strlen (b)] + 3);
	      return buff;
	    }
	  else
	    {
	      A4GL_assertion (1, "Didn't start as I'd expect");
	    }

	}

      if (A4GL_isyes (acl_getenv ("MARK_SCOPE_MODULE")) && s[0] == 'M')
	{
	  if (strncmp
	      (&s[2], A4GL_compiling_module_basename (),
	       strlen (A4GL_compiling_module_basename ())) == 0)
	    {
	      sl = strlen (A4GL_compiling_module_basename ()) + 3;
	      strcpy (buff, &s[sl]);
	      return buff;
	    }
	}
      else
	{
	  sl = 2;
	  strcpy (buff, &s[sl]);
	}
    }
  return buff;
}














void set_current_variable_scope (enum e_scope n)
{
  variable_scope = n;
}

/******************************************************************************/
enum e_scope
A4GL_get_current_variable_scope (void)
{
  enum e_scope scope = E_SCOPE_MODULE;
  int is_inreport = 0;

  
  if (variable_scope == E_SCOPE_TYPE)
    return E_SCOPE_TYPE;

  if (isin_command ("REPORT"))
    {
      is_inreport = 1;
      if (A4GL_isyes (acl_getenv ("REPORT_VARS_AT_MODULE")))
	{
	  is_inreport = 0;
	  return E_SCOPE_REPORT_LOCAL;
	}
      else
	{
	  scope = E_SCOPE_MODULE;
	}
    }


  if (isin_command ("FUNC") || is_inreport || isin_command ("FORMHANDLER") || isin_command ("MENUHANDLER") || isin_command ("MAIN"))
    {
      scope = E_SCOPE_LOCAL;
    }
  else
    {
      if (variable_scope == E_SCOPE_EXPORTED_GLOBAL || variable_scope=='g')
	{
	  scope = E_SCOPE_EXPORTED_GLOBAL;
	}

      if (variable_scope == E_SCOPE_CLASS)	// Class
	{
	  scope = E_SCOPE_CLASS;
	}

      if (variable_scope == E_SCOPE_CLASS_PARENT)	// Class Parent
	{
	  scope = E_SCOPE_CLASS_PARENT;
	}

      if (variable_scope == E_SCOPE_IMPORTED_GLOBAL)
	{
	  scope = E_SCOPE_IMPORTED_GLOBAL;
	}

      if (variable_scope == E_SCOPE_MODULE)
	{
	  scope = E_SCOPE_MODULE;
	}

      if (variable_scope == E_SCOPE_REPORT_LOCAL)
	{
	  scope = E_SCOPE_REPORT_LOCAL;
	}
    }

  return scope;

}






struct variable_usage *make_variable_usage_from_string(char *buff) {
	struct variable_usage *vu;

 // we cant search on the name - we need to search on a variable usage..
 // this should probably be expanded to search for '.' and split on a record etc..
 //
  	vu=new_variable_usage(0,buff,0); 
	return vu;
}




struct variable *find_dim_in_variable_list(struct variable_list *v,char *name) {
	int a;
	if (v==NULL) return NULL;
	for (a=0;a<v->variables.variables_len;a++) {
		if (v->variables.variables_val[a]->var_data.variable_type==VARIABLE_TYPE_TYPE_DECLARATION) {
			if (A4GL_aubit_strcasecmp(name,v->variables.variables_val[a]->names.names.names_val[0].name)==0) {
				return v->variables.variables_val[a];
			}
		}
	}
	return NULL;
}

struct variable *find_dim (char *name) {
  struct variable_usage *vu;
  struct variable *v=NULL;
		char errbuff[256];
  vu=make_variable_usage_from_string(name);

  // look to see if we've define it locally
  if (local_variables) {

		strcpy(errbuff,"");
		v=find_dim_in_variable_list(local_variables,name);
  }
  
  if (v==NULL) { v=find_dim_in_variable_list(&this_module.module_variables,name); }
  if (v==NULL) { v=find_dim_in_variable_list(&this_module.exported_global_variables,name); }
  if (v==NULL) { v=find_dim_in_variable_list(&this_module.imported_global_variables,name); }

  if (v==NULL) return NULL;

  if (v->var_data.variable_type != VARIABLE_TYPE_TYPE_DECLARATION) {
	printf("Bad type\n");
	// We found something with that name - but its not a type...
	return NULL;
  }

  return v->var_data.variable_data_u.type_declaration;
}


/******************************************************************************/
int
check_for_constant (char *name, char *buff)
{
  struct variable *v=NULL;
  int dbg = 0;
  struct variable_usage *vu;
  char errbuff[256];
  enum e_scope scope;
  /*char buff2[256]; */


  if (dbg)
    {
      if (in_define)
	{
	  PRINTF ("In define..\n");
	}
    }


  if (in_define)
    return 0;

// Constants can be costly to search for..
// if we're not using them (over the builtin ones) - we can ignore this expense..
  if (uses_constants()==0 && !A4GL_isno(acl_getenv("CONSTANT_OPTIMISE"))){  
		int builtin_Constant_usage=0;

   		if (A4GL_aubit_strcasecmp(name,"notfound")==0) builtin_Constant_usage++;
 		if (A4GL_aubit_strcasecmp(name,"true")==0)     builtin_Constant_usage++;
 		if (A4GL_aubit_strcasecmp(name,"false")==0)    builtin_Constant_usage++;

	 	if (!builtin_Constant_usage) return 0; // none defined - so no point in searching
  }

//A4GL_pause_execution();

  strcpy (buff, name);
  A4GL_convlower (buff);


vu = make_variable_usage_from_string(buff);

  // look to see if we've define it locally
  if (local_variables) {
		strcpy(errbuff,"");
		v=find_variable_vu_in_list (errbuff, vu, local_variables, 1,0);
  }

  
  if (v==NULL) {
  	v = find_variable_vu_ptr (errbuff, vu,&scope,1);
  }




  if (dbg)
    {
      PRINTF ("v=%p\n", v);
    }

  if (v == 0)
    return 0;

  if (v->var_data.variable_type != VARIABLE_TYPE_CONSTANT)
    return 0;

  if (v->var_data.variable_data_u.v_const.consttype == CONST_TYPE_CHAR
      || v->var_data.variable_data_u.v_const.consttype == CONST_TYPE_IDENT)
    {


      if (v->var_data.variable_data_u.v_const.consttype == CONST_TYPE_CHAR)
	{
	  strcpy (buff,
		  v->var_data.variable_data_u.v_const.constant_data_u.data_c);
	  return 1;
	}

      if (v->var_data.variable_data_u.v_const.consttype == CONST_TYPE_IDENT)
	{
	  strcpy (buff,
		  v->var_data.variable_data_u.v_const.constant_data_u.data_ident);
	  return 4;
	}
    }

  if (v->var_data.variable_data_u.v_const.consttype == CONST_TYPE_FLOAT)
    {
      SPRINTF1 (buff, "%lf",
		v->var_data.variable_data_u.v_const.constant_data_u.data_f);
      return 2;
    }

  if (v->var_data.variable_data_u.v_const.consttype == CONST_TYPE_INTEGER)
    {
      SPRINTF1 (buff, "%d",
		v->var_data.variable_data_u.v_const.constant_data_u.data_i);
      return 3;
    }


/* Shouldn't get to here...*/

  return 0;
}











/******************************************************************************/
/* 
* This function does a look through from a starting variable to a finishing variable
* within a record
*/
/******************************************************************************/

struct variable *
get_next_variable (struct variable *record, struct variable *v1,
		   struct variable *v2)
{
  struct variable *v_return;
  int a;

  if (v1 == v2)
    return 0;

  for (a = 0;
       a < record->var_data.variable_data_u.v_record.variables.variables_len; a++)
    {
      if (record->var_data.variable_data_u.v_record.variables.variables_val[a] ==
	  v1)
	{
	  a++;
	  v_return =
	    record->var_data.variable_data_u.v_record.variables.variables_val[a];
	  return v_return;
	}
    }
  a4gl_yyerror ("Can't find variable in record...");
  return 0;
}



/******************************************************************************/
void
clr_function_constants ()
{

  /* Here - we need to clear down the current 'locals' lists... */
  /* as a quick fix - we'll just zero everything */
  /* but these *really* should be 'freed' properly..... */
  local_variables=0;
  //clr_current_constants();
  nreturn_values = -1;
}





int inc_var_usage(expr_str *s_orig) {
struct variable *v;
struct variable_usage *u=0;
struct variable_usage *utop;



if (s_orig->expr_type==ET_EXPR_VARIABLE_USAGE) {
	u=s_orig->expr_str_u.expr_variable_usage;
}
if (s_orig->expr_type==ET_EXPR_VARIABLE_USAGE_WITH_ASC_DESC) {
	u=s_orig->expr_str_u.expr_variable_usage_with_asc_desc->var_usage;
}

if (u==0) return 0;


utop=u;
while (1) {
	char errbuff[256];
	enum e_scope scope;
	struct variable_usage *unext;
	unext=u->next;
	u->next=0;
	v=find_variable_vu_ptr(errbuff,utop,&scope,0);
	if (v) {
		v->usage++;
		if (!v->assigned) {
		if (scope==E_SCOPE_LOCAL) { v->flags|=1; }
		}
	} else {
		break;
	}
	if (unext==0) break;
	u->next=unext;
	u=unext;
}
return 1;
}


int inc_var_assigned(expr_str *s) {
struct variable *v;
struct variable_usage *u=0;
struct variable_usage *utop;
if (s==0) return 1;
if (s->expr_type==ET_EXPR_VARIABLE_USAGE_WITH_ASC_DESC) {
	u=s->expr_str_u.expr_variable_usage_with_asc_desc->var_usage;
}
if (s->expr_type==ET_EXPR_VARIABLE_USAGE) {
	u=s->expr_str_u.expr_variable_usage;
}

if (u==0) {
	return 1;
}
utop=u;
while (1) {
	char errbuff[256];
	enum e_scope scope;
	struct variable_usage *unext;
	unext=u->next;
	u->next=0;
	v=find_variable_vu_ptr(errbuff,utop,&scope,0);
	if (v) {
		v->assigned++;
	} else {
		break;
	}
	if (unext==0) break;
	u->next=unext;
	u=unext;
}
return 1;
}

int
is_system_variable (char *s)
{

  if (strcmp (s, "a4gl_status") == 0)
    return 1;
  if (strncmp (s, "a4gl_sqlca", 10) == 0)
    return 1;
  if (strcmp (s, "notfound") == 0)
    return 1;
  if (strcmp (s, "false") == 0)
    return 1;
  if (strcmp (s, "true") == 0)
    return 1;
  if (strcmp (s, "today") == 0)
    return 1;
  if (strcmp (s, "user") == 0)
    return 1;
  if (strcmp (s, "pageno") == 0)
    return 1;
  if (strcmp (s, "lineno") == 0)
    return 1;
  if (strcmp (s, "time") == 0)
    return 1;
  if (strcmp (s, "usrtime") == 0)
    return 1;
  if (strcmp (s, "curr_hwnd") == 0)
    return 1;
  if (strcmp (s, "curr_form") == 0)
    return 1;
  if (strcmp (s, "err_file_name") == 0)
    return 1;
  if (strcmp (s, "err_line_no") == 0)
    return 1;
  if (strcmp (s, "curr_file_name") == 0)
    return 1;
  if (strcmp (s, "curr_line_no") == 0)
    return 1;
  if (strcmp (s, "err_status") == 0)
    return 1;
  if (strcmp (s, "sqlerrmessage") == 0)
    return 1;
  if (strcmp (s, "aiplib_status") == 0)
    return 1;
  return 0;
}



void
set_last_class_var (char *s)
{
  strcpy (last_class_var, s);
}

char *
get_last_class_var (void)
{
  return last_class_var;
}







 char *remap_top_level_variables(char *invarname) {
	if (strcmp(invarname,"index")==0) {
		return "a4gl_index";
	}

	return 0;
}


struct variable_usage *check_var_usage (struct variable_usage *v) {
char *ptr;

if (strcmp(v->variable_name,"sqlca")==0) {
	v->variable_name="a4gl_sqlca";
}

if (strcmp(v->variable_name,"status")==0) {
	v->variable_name="a4gl_status";
}

ptr=remap_top_level_variables(v->variable_name);


if (ptr) {
	v->variable_name=ptr;
}

return v;
}






char *describe_subscripts(int n, int *nvals ){ 
static char buff[2000];
int a;
if (n==0) return "";
strcpy(buff,"[");
for (a=0;a<n;a++) {
	char smbuff[256];
	if (a)strcat(buff,",");
	sprintf(smbuff,"%d",nvals[a]);
	strcat(buff,smbuff);
}
strcat(buff,"]");
return buff;

}

// This function 'describes' a variable so we can compare if two record structures are alike
// The format does not bother with variable names - just datatypes and array sizes
// the format is 
//              {DTYPE:DTYPESIZE}
//      we use [ARRSIZE,ARRSIZE] for an array
//      we use ( ... ) for a record
//
// If we dont think we can copy any part - we'll just return 0...
//
char *
describe_variable (struct variable *v)
{
  char buff[20000];
  char *ptr;
  strcpy (buff, "");
  switch (v->var_data.variable_type)
    {
    case VARIABLE_TYPE_SIMPLE:
      sprintf (buff, "{%d:%d}", v->var_data.variable_data_u.v_simple.datatype & DTYPE_MASK, v->var_data.variable_data_u.v_simple.dimensions[0]);
      break;

    case VARIABLE_TYPE_TYPE_DECLARATION:
    case VARIABLE_TYPE_OBJECT:
      return 0;

    case VARIABLE_TYPE_RECORD:
      ptr = describe_record (&v->var_data.variable_data_u.v_record);
      if (ptr)
	{
	  sprintf (buff, "(%s)%s", ptr,
		   describe_subscripts (v->arr_subscripts.arr_subscripts_len, v->arr_subscripts.arr_subscripts_val));
	  free (ptr);
	}
      else
	{
	  return 0;
	}

    case VARIABLE_TYPE_ASSOC:
      return 0;

    case VARIABLE_TYPE_CONSTANT:
      sprintf (buff, "CONSTANT");
	break;


    case VARIABLE_TYPE_FUNCTION_DECLARE:
      strcpy (buff, "");
      break;
    }

  return strdup (buff);
}



static char *
describe_record (struct record_variable *v_record)
{
  int a;
  char buff[20000];
  char *ptr;
  strcpy (buff, "(");
  for (a = 0; a < v_record->variables.variables_len; a++)
    {
      ptr = describe_variable (v_record->variables.variables_val[a]);
      if (ptr)
	{
	  if (a)
	    strcat (buff, ",");
	  strcat (buff, ptr);
	  free (ptr);
	}
      else
	{
	  return 0;
	}
    }
  strcat (buff, "}");
  return strdup (buff);
}




char *describe_variable_usage(variable_usage *u) {
	struct variable *v;
	enum e_scope scope;
	char errbuff[256];
	v=find_variable_vu_ptr(errbuff,u,&scope,0);
	if (v==0) return 0;
	
return " ";
}

struct variable * find_variable_vu_in_list(char *errbuff, struct variable_usage *v, struct variable_list *vlist, int err_if_while_array,int level) {
	return find_variable_vu_in(errbuff,v,vlist->variables.variables_val, vlist->variables.variables_len,err_if_while_array,level,vlist);
}


/* 
 * 
 * v = variable usage to look for
 * scope = pointer to character to store the scope..
 *
 */
struct variable *find_variable_vu_ptr(char *errbuff, struct variable_usage *v, enum e_scope *scope, int err_if_whole_array) {
  struct variable *ptr=NULL;
  strcpy(errbuff,"");

  if (isCreateProcedure) {
	if (procVariableListCnt) {
		int a;
		for (a=procVariableListCnt-1;a>=0;a--) {
			if (procVariableList[a]) {
  				ptr = find_variable_vu_in_list (errbuff, v, procVariableList[a], err_if_whole_array,0);
				if (ptr) break;
			}
		}
	}
	return ptr;
  }

  if (local_variables) {
  	ptr = find_variable_vu_in_list (errbuff, v, local_variables, err_if_whole_array,0);
  }

  if (ptr)
    {
	v->escope=E_SCOPE_LOCAL;
	*scope=E_SCOPE_LOCAL;
        A4GL_debug ("local variable");
        return ptr;
    }

  ptr = find_variable_vu_in_list (errbuff, v, &this_module.module_variables, err_if_whole_array,0);
  if (ptr)
    {
	v->escope=E_SCOPE_MODULE;
	*scope=E_SCOPE_MODULE;
      A4GL_debug ("Module variable");
      return ptr;
    }

  ptr = find_variable_vu_in_list (errbuff, v, &this_module.exported_global_variables, err_if_whole_array,0);
  if (ptr)
    {
	v->escope=E_SCOPE_EXPORTED_GLOBAL;
	*scope=E_SCOPE_EXPORTED_GLOBAL;
      A4GL_debug ("Global variable");
      return ptr;
    }

  ptr = find_variable_vu_in_list (errbuff, v,  &this_module.imported_global_variables, err_if_whole_array,0);
  if (ptr)
    {
	v->escope=E_SCOPE_IMPORTED_GLOBAL;
	*scope=E_SCOPE_IMPORTED_GLOBAL;
      A4GL_debug ("Global variable");
      return ptr;
    }
  return ptr; /* Will be NULL - or it would have been returned already... */
}



// This function is called when we process a 'create procedure'
// to turn off all other variable checking
// except that in the create procedure variable list
void set_in_create_procedure(void) {
	isCreateProcedure=1;
	set_sli_variable_usage_as_string(1);
}

// This function claars the flag so that variables are processed as
// normal again after the create procedure has been used..
void clr_in_create_procedure(void) {
	isCreateProcedure=0;
	set_sli_variable_usage_as_string(0);
}

// This function pushes a block of variables onto the variable stack
// this means we can use variables local to a 'block' within the procedure
// as well as those defined at the top of it...
void push_spl_block_variables(struct variable_list *p) {
	A4GL_assertion(procVariableListCnt>=MAXPROCVARIABLESLEVELS,"Too many block levels in procedure");
	procVariableListCnt++;
	procVariableList[procVariableListCnt-1]=p;
}


// This function removes any functions associated with the current block
// Its called when the block ends and therefore the contained variabled go out of scope
void pop_spl_block_variables(struct variable_list *p) {
	A4GL_assertion(procVariableListCnt<=0,"No variable list to pop!");
	A4GL_assertion (procVariableList[procVariableListCnt-1]!=p,"Create procedure variable list is not the one I expected");
	procVariableList[procVariableListCnt-1]=NULL;
	procVariableListCnt--;
}


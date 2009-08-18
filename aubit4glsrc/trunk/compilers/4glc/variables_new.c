
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
# $Id: variables_new.c,v 1.13 2009-08-18 13:33:46 mikeaubury Exp $
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
#include "variables_new.h"
#include <ctype.h>
#include "trim_spaces.h"

extern int token_read_on_line;
extern char *outputfilename;

char system_or_user = '-';


/* CONFIGURABLE...*/

#define RECORD_LEVELS 128
/**/


void
set_variable_user_system (char n)
{
  system_or_user = n;
}




static char
get_variable_user_system (void)
{
  return system_or_user;
}




static int strsplit(char *orig,char *srch, ...) {
char **p;
char *buff;
int a;
static va_list args;
char *ptr;


buff=strdup(orig);
p=malloc((strlen(srch)+1)*sizeof(int));
p[0]=buff;
for (a=0;a<strlen(srch);a++) {
        p[a+1]=strchr(p[a],srch[a]);
        if (p[a+1]) {
                *p[a+1]=0;
                p[a+1]++;
        } else {
                free(p);
                free(buff);
                return 0;
        }
}
va_start (args, srch);



ptr=va_arg(args, char*);
a=0;
while (ptr && a<=strlen(srch)) {
        strcpy(ptr, p[a]);
        a++;
        ptr=va_arg(args, char*);
}
va_end(args);
return strlen(srch)+1;
}



/// Define a simple variable
//
// @param dtype  = datatype
// @param scale1 = normal scale (eg 20 for a CHAR(20))
// @param scale2 = extended scale (reserved for future enhancement ;-)
//

static struct variable * new_base_variable(char *name) {
	struct variable *v;
	v=malloc(sizeof(struct variable));
	v->names.names.names_len=0;
	v->names.names.names_val=NULL;

	if (name) {
               	v->names.names.names_len=1;
               	v->names.names.names_val=malloc(sizeof(vname));
               	v->names.names.names_val[0].name=strdup(name);
               	v->names.names.names_val[0].alias="";
	}
	
	v->is_static=0;
	
          if (isin_command ("REPORT") || isin_command ("FORMHANDLER")
              || isin_command ("MENUHANDLER"))
            {
             v->is_static = 1;
            }

	v->is_extern=0;
	v->defsrc="";
	v->user_system=get_variable_user_system();
		
	v->arr_subscripts.arr_subscripts_len=0;
	v->arr_subscripts.arr_subscripts_val=0;
	v->escope=A4GL_get_current_variable_scope();
	v->usage=0;
	v->assigned=0;
	v->flags=0;
  	v->lineno = token_read_on_line;
	v->src_module = outputfilename;
	v->var_data.variable_type=-1;

	return v;
}

struct variable * new_simple_variable(char *name, int dtype,int dim1,int dim2) {
struct variable *v;
	v=new_base_variable(name);
        v->var_data.variable_type=VARIABLE_TYPE_SIMPLE;
        v->var_data.variable_data_u.v_simple.datatype=dtype;
        v->var_data.variable_data_u.v_simple.dimensions[0]=dim1;
        v->var_data.variable_data_u.v_simple.dimensions[1]=dim2;
        return v;
}




// Create a new "struct variable" containing the definition for a constant
// @param name = name of the constant
// @param value = value for the constant as a string
// 
// @param int_or_char = constant type - i for integer, c for character string, C for identifier, f for Floating point number
//
struct variable * new_constant (char int_or_char, char *value, char *name)
{
  struct variable *local_v;

  local_v=new_base_variable(name);

  //local_v = (struct variable *) acl_malloc2 (sizeof (struct variable));
  //local_v->names.names.names_val = malloc (sizeof (vname));
  //local_v->names.names.names_len = 1;
  //local_v->names.names.names_val[0].name = acl_strdup (name);
  //local_v->names.names.names_val[0].alias = 0;


  local_v->var_data.variable_type = VARIABLE_TYPE_CONSTANT;
  local_v->user_system = get_variable_user_system ();
  local_v->defsrc = "";
  local_v->is_static = 0;
  local_v->is_extern = 0;
  local_v->usage = 0;
  local_v->assigned = 0;
  local_v->flags = 0;
  local_v->lineno = token_read_on_line;
  local_v->src_module = outputfilename;

  local_v->arr_subscripts.arr_subscripts_val = 0;
  local_v->arr_subscripts.arr_subscripts_len = 0;


  if (int_or_char == 'c')
    {
      local_v->var_data.variable_data_u.v_const.consttype = CONST_TYPE_CHAR;
      local_v->var_data.variable_data_u.v_const.constant_data_u.data_c =
	acl_strdup (value);
    }

  if (int_or_char == 'C')
    {
      local_v->var_data.variable_data_u.v_const.consttype = CONST_TYPE_IDENT;
      local_v->var_data.variable_data_u.v_const.constant_data_u.data_ident =
	acl_strdup (value);
    }

  if (int_or_char == 'i')
    {
      local_v->var_data.variable_data_u.v_const.consttype = CONST_TYPE_INTEGER;
      local_v->var_data.variable_data_u.v_const.constant_data_u.data_i =
	atoi (value);
    }

  if (int_or_char == 'f')
    {
      local_v->var_data.variable_data_u.v_const.consttype = CONST_TYPE_FLOAT;
      local_v->var_data.variable_data_u.v_const.constant_data_u.data_f =
	atof (value);
    }

  if (A4GL_aubit_strcasecmp (name, "TRUE") == 0 || strcasecmp (name, "FALSE") == 0 || A4GL_aubit_strcasecmp (name, "NOTFOUND") == 0);
  else
    {

      if (A4GL_isyes (acl_getenv ("CONSTANT2DEFINES")))
	{
	  char buff[256];
	  strcpy (buff, upshift (name));
	  PRINTF ("#define %s %s\n", buff, value);
	}
    }

  make_constant_available(local_v);

  return local_v;
}




// Create a variable list
struct variable_list *new_variable_list(struct variable *ptr) {
	struct variable_list *vlist;
	vlist=malloc(sizeof(struct variable_list));
	vlist->variables.variables_len=0;
	vlist->variables.variables_val=NULL;

	if (ptr) {
		return append_variable_list(vlist, ptr);
	}
	return vlist;
}



static int list_already_has(struct variable_list *list, char *name) {
int a;
if (list==NULL) return 0;

for (a=0;a<list->variables.variables_len;a++) {	
	struct variable *p;
	int b;
	p=list->variables.variables_val[a];
	for (b=0;b<p->names.names.names_len;b++) {
		if (A4GL_aubit_strcasecmp(p->names.names.names_val[b].name,name)==0) {
			set_yytext(name);
			return 1;
		}
	}
}
return 0;
}

// Add a variable to a variable list
struct variable_list *append_variable_list(struct variable_list *list, struct variable *ptr) {
	// Do we already have a variable list ? 
	if (list==NULL) {
		// Create one then...
		return new_variable_list(ptr);
	}

	if (ptr==NULL) {
		// Nothing to add ? 
		return list;
	}
	
	if (ptr->names.names.names_len>1) {
		// We don't unroll here..
		A4GL_assertion(1,"Not unrolled");
	}

	if (ptr->names.names.names_len==0) {
		A4GL_assertion(1,"Variable has no name...");
	}

	if (list_already_has(list, ptr->names.names.names_val[0].name)) {
		if (A4GL_get_current_variable_scope() == E_SCOPE_EXPORTED_GLOBAL && A4GL_isyes(acl_getenv("IGNDUPGLOBALS"))) {
			fprintf(stderr,"Ignoring variable : %s - already exists\n", ptr->names.names.names_val[0].name);
			return list;
		} else {
			a4gl_yyerror("A variable with this name already exists");
			return NULL;
		}
	}
	list->variables.variables_len++;
	list->variables.variables_val=realloc(list->variables.variables_val, list->variables.variables_len*sizeof(list->variables.variables_val[0]));
	list->variables.variables_val[list->variables.variables_len-1]=ptr;

	return list;
}


// Create a new blank 'RECORD' variable...
struct variable *new_variable_record(char *name, struct variable_list *vlist) {
	struct variable *v;
	v=new_base_variable(NULL);
	v->var_data.variable_type=VARIABLE_TYPE_RECORD;
	v->var_data.variable_data_u.v_record.record_alloc=0;
	v->var_data.variable_data_u.v_record.linked=NULL;
	v->var_data.variable_data_u.v_record.user_ptr=NULL;
	
	if (vlist) {
		v->var_data.variable_data_u.v_record.variables.variables_len=vlist->variables.variables_len;
		v->var_data.variable_data_u.v_record.variables.variables_val=vlist->variables.variables_val;
	} else {
		v->var_data.variable_data_u.v_record.variables.variables_len=0;
		v->var_data.variable_data_u.v_record.variables.variables_val=NULL;
	}

        if (name) {
		set_variable_name(v, name);
	}
	
	return v;
}




// create a "RECORD" variable "LIKE" a table..
struct variable *new_variable_pushLikeAllTableColumns(char *tableName,str_list *linked_to_list) {
struct variable *v;
  int rval;
  int isize = 0;
  int idtype = 0;
  char colname[256] = "";
  char buff[300];
  char *ccol = 0;
  int ncol = 0;
  struct variable_list *vlist;

  //v=new_base_variable(NULL);
  //v->var_data.variable_type=VARIABLE_TYPE_RECORD;
  //v->var_data.variable_data_u.v_record.record_alloc=0;
  
  vlist=new_variable_list(NULL);

  rval = A4GLSQL_get_columns (tableName, colname, &idtype, &isize);

  if (rval == 0 && tableName)
    {
      SPRINTF1 (buff, "%s does not exist in the database", tableName);
      a4gl_yyerror (buff);
      return NULL;
    }

  A4GL_debug ("Rval (%d) !=0", rval);

  while (1)
    {
	int isnotnull=0;

      colname[0] = 0;

      ccol = 0;
      rval = A4GLSQL_next_column (&ccol, &idtype, &isize);
      if (rval == 0)
	{
	  A4GL_debug ("Got rval back from next_column as 0");
	  break;
	}

      ncol++;

      A4GL_assertion (ccol == 0, "No column name set");

      A4GL_debug ("next column for table '%p' is '%p'", tableName, ccol);
      A4GL_debug ("next column for table '%s' is '%s'", A4GL_null_as_null (tableName), A4GL_null_as_null (ccol));
      strcpy (colname, ccol);
      trim_spaces (colname);

	if (idtype&256) { // Not null...
		idtype-=256;
		isnotnull=1;
	}

	if (idtype>DTYPE_MASK) {
		printf("Unexpected datatype : %d\n", idtype);
		A4GL_pause_execution(); // Safe to commit
	}

       v=new_simple_variable(colname, idtype,isize,0);

       SPRINTF2(buff,"%s.%s", tableName, colname);
       v->defsrc=strdup(buff);
       append_variable_list(vlist,v);
    }

  A4GL_debug ("ncol=%d\n", ncol);

  if (ncol == 0)
    {

      SPRINTF1 (buff, "%s does not exist in the database", tableName);
      a4gl_yyerror (buff);
      return NULL;
    }

  A4GLSQL_end_get_columns ();
 // Now - create the record itself...
 v=new_variable_record(NULL, vlist);

 // And we might as well mark the defsrc too..
 SPRINTF1(buff,"%s.*", tableName);
 v->defsrc=strdup(buff);

 // Copy across any linked columns...
 if (linked_to_list) {
	int a;
	v->var_data.variable_data_u.v_record.linked=malloc(sizeof(struct linked_variable));
	v->var_data.variable_data_u.v_record.linked->col_list.names.names_len=linked_to_list->str_list_entry.str_list_entry_len;
	v->var_data.variable_data_u.v_record.linked->col_list.names.names_val=malloc(linked_to_list->str_list_entry.str_list_entry_len*sizeof(struct vname));

	for (a=0;a<linked_to_list->str_list_entry.str_list_entry_len;a++) {
		v->var_data.variable_data_u.v_record.linked->col_list.names.names_val[a].name=strdup(linked_to_list->str_list_entry.str_list_entry_val[a]);
		v->var_data.variable_data_u.v_record.linked->col_list.names.names_val[a].alias=NULL;
	}

 }

 return v;
}



// Create a variable "LIKE" a tablename.columname
struct variable *new_variable_pushLikeTableColumn(char *tableName,char *columnName) {
  int rval;
  int idtype;
  int isize;
  char buff[300];
  int a;
  char s_tab[200];
  char s_db[200];
  char s_instance[200];


  char *cname;
  struct variable *v;

  A4GL_debug ("pushLikeTableColumn()");
  if (strchr(tableName,'@')) {
        if (strchr(tableName,':')) {
                        a=strsplit(tableName, "@:",s_db,s_instance,s_tab);
                        if (a==3) {
                                strcpy(s_tab, A4GLSQLCV_db_tablename(s_db, s_instance, s_tab ));
                                tableName=s_tab;
                        }
        }  else {
                        a=strsplit(tableName, "@",s_instance,s_tab);
                        if (a==2) {
                                strcpy(s_tab, A4GLSQLCV_db_tablename(NULL,s_instance, s_tab ));
                                tableName=s_tab;
                        }
        }
  } else {
        if ( strchr(tableName,':')) {
                        a=strsplit(tableName, ":",s_db,s_tab);
                        if (a==2) {
                                strcpy(s_tab,A4GLSQLCV_db_tablename( s_db,NULL, s_tab));
                                tableName=s_tab;
                        }
        }  else {
                strcpy(s_tab,A4GLSQLCV_db_tablename( NULL,NULL, tableName));
                tableName=s_tab;
        }
  }

  rval = A4GL_read_columns (tableName, columnName, &idtype, &isize);
  cname = A4GL_confirm_colname (tableName, columnName);

  if (rval == 0)
    {
      SPRINTF2 (buff, "%s.%s does not exist in the database", tableName, columnName);
      a4gl_yyerror (buff);
      return 0;
    }

  trim_spaces (cname);
  SPRINTF2(buff,"%s.%s",tableName, columnName);

  v= new_simple_variable(NULL, idtype&DTYPE_MASK ,isize,0);

  v->defsrc=strdup(buff);
  return v;
}



// Create a variable LIKE a table.column
struct variable *new_variable_like(char *tabcol) {
  char buff[300];
  char *tableName;
  char *columnName;
  char t[256];

  if (A4GL_db_used () == 0)
    {
      SPRINTF0 (buff, "You cannot use LIKE without specifying a database");
      a4gl_yyerror (buff);
      return NULL;
    }

  strcpy (t, tabcol);
  strcpy (buff, t);
  strcat (buff, ".");

  tableName = strtok (buff, ".");       /* table name */
  columnName = strtok (0, "."); /* column name */
  A4GL_debug ("a='%s' b='%s'", A4GL_null_as_null (tableName), A4GL_null_as_null (columnName));

  if (columnName)
    {
      return new_variable_pushLikeTableColumn (tableName, columnName);
    }


 A4GL_assertion(1,"Call via new_variable_pushLikeAllTableColumns direct");
  return new_variable_pushLikeAllTableColumns (tableName,NULL);
}



void set_variable_name(struct variable *v, char *name) {

	if (v->names.names.names_len==0) {
		char *mapped_name;
               	v->names.names.names_len=1;
               	v->names.names.names_val=malloc(sizeof(vname));

		/* Do we need to remap a variable name (maybe its a common builtin name */
		mapped_name=remap_top_level_variables(name);
		if (mapped_name) {
			char buf[2000];
			sprintf(buf,"Remapped variable '%s' to be '%s' to avoid possible conflicts", name,mapped_name);
				A4GL_warn(buf);
				name=mapped_name;
		}
               	v->names.names.names_val[0].name=strdup(name);
               	v->names.names.names_val[0].alias="";
	}  else {
		A4GL_assertion(1,"Not expecting an existing name");
	}
}


// Create a new type which can be subsequently be used by a DEFINE
//
// @param name = Name of the type
// @param type = variable structure holding the definition for the variable
//
struct variable *make_new_type(char *name, struct variable *type) {
	struct variable *v;
	v=new_base_variable(name);
	v->var_data.variable_type=VARIABLE_TYPE_TYPE_DECLARATION;
	v->var_data.variable_data_u.type_declaration=type;
	return v;

}


// Create a new variable based on a type defined + added via add_new_type
struct variable *new_variable_dim(char *name) {
	struct variable *v=NULL;

	v=find_dim(name);
	if (v) {
		// We've found it!
		struct variable *vnew;
		vnew=malloc(sizeof(struct variable));
		memcpy(vnew,v,sizeof(struct variable));
		
		// We dont have a name for our variable yet - just the type
		vnew->names.names.names_len=0;
		vnew->names.names.names_val=NULL;
		return vnew;
	}

	// Not found...
	return NULL;
}



// Take all the variables in 'list2' and append them to the list in list1
// This is used in lots of places - for example to add to the current list of DEFINEd variabled : 
//
// DEFINE a,b,c INTEGER
// DEFINE c,e,f INTEGER
// 
//
struct variable_list *merge_variable_list(struct variable_list *list, struct variable_list *list2) {

	if (list==NULL) {
		list=malloc(sizeof(struct variable_list));
		list->variables.variables_len=0;
		list->variables.variables_val=NULL;
	}

	if (list2) {
		int a;
		for (a=0;a<list2->variables.variables_len;a++) {
			append_variable_list(list,list2->variables.variables_val[a]);
		}
	}

	return list;
}

// Create a list of variables from a list of names
// and the definition for the variable.
// Each variable in the list is just a copy of 'var' with the name from the list applied
// this is used to handle situations like : 
//
// DEFINE a,b,c ...
//
struct variable_list *create_variable_list(str_list *name_list,struct variable *var) {
	struct variable_list *vlist=NULL;
	int a;
	A4GL_assertion(name_list==NULL,"No name list..");


	if (name_list->str_list_entry.str_list_entry_len==1) { // Its a straight usage..
		set_variable_name(var,name_list->str_list_entry.str_list_entry_val[0]);
		return new_variable_list(var);
	}


	// Create an empty list...
	vlist=new_variable_list(NULL);
	for (a=0;a<name_list->str_list_entry.str_list_entry_len;a++) {
		struct variable *v;
		// Duplicate the variable data
		v=malloc(sizeof(struct variable));
		memcpy(v,var,sizeof(struct variable));
		set_variable_name(v,name_list->str_list_entry.str_list_entry_val[a]);
		append_variable_list(vlist,v);
	}
	return vlist;
}



// recursively go through a variable list and ensure all scopes are set to 'scope'
//
void set_variable_scope_for_variable_list(variable_list *list,enum e_scope escope) {
	int a;
	if (list==NULL) return;
	for (a=0;a<list->variables.variables_len;a++) {
		struct variable *v;
		struct variable *v2;
		struct variable_list vlist;
		v=list->variables.variables_val[a];
		v->escope=escope;

		switch (v->var_data.variable_type) {
			case VARIABLE_TYPE_SIMPLE:
			case VARIABLE_TYPE_CONSTANT:
			case VARIABLE_TYPE_FUNCTION_DECLARE:
			case VARIABLE_TYPE_TYPE_DECLARATION:
				break;
	
			case VARIABLE_TYPE_ASSOC:
				v2=v->var_data.variable_data_u.v_assoc.variable;
				if (v2->var_data.variable_type==VARIABLE_TYPE_RECORD) {
						vlist.variables.variables_len=v2->var_data.variable_data_u.v_record.variables.variables_len;
						vlist.variables.variables_val=v2->var_data.variable_data_u.v_record.variables.variables_val;
						set_variable_scope_for_variable_list(&vlist,escope);
				}
				break;
			
			case VARIABLE_TYPE_OBJECT:
				v2=v->var_data.variable_data_u.v_object.definition;
				if (v2->var_data.variable_type==VARIABLE_TYPE_RECORD) {
						vlist.variables.variables_len=v2->var_data.variable_data_u.v_record.variables.variables_len;
						vlist.variables.variables_val=v2->var_data.variable_data_u.v_record.variables.variables_val;
						set_variable_scope_for_variable_list(&vlist,escope);
				}
				break;

			case VARIABLE_TYPE_RECORD:
				vlist.variables.variables_len=v->var_data.variable_data_u.v_record.variables.variables_len;
				vlist.variables.variables_val=v->var_data.variable_data_u.v_record.variables.variables_val;
				set_variable_scope_for_variable_list(&vlist,escope);
				break;
				
		}
	}

}


// ------------------------------------------------------ TO DO LIST --------------------------------------------------------------




// Create a variable containing an associative array
// @param assoc_char_size Size of the string to associate with the array
// @param assoc_arr_size  Total size of the associative array
// @param ptr             Variable ptr for the description of the array
struct variable *new_associate_variable(int assoc_char_size,int assoc_arr_size,struct variable *ptr) {
	struct variable *v;

	v=new_base_variable(NULL);
	v->var_data.variable_type=VARIABLE_TYPE_ASSOC;
	v->var_data.variable_data_u.v_assoc.size=assoc_arr_size;
	v->var_data.variable_data_u.v_assoc.char_size=assoc_char_size;
	v->var_data.variable_data_u.v_assoc.variable=ptr;

	ptr->arr_subscripts.arr_subscripts_len=1;
	ptr->arr_subscripts.arr_subscripts_val=malloc(sizeof(ptr->arr_subscripts.arr_subscripts_val[0]));
	ptr->arr_subscripts.arr_subscripts_val[0]=assoc_arr_size;
	return v;
}

static struct variable *find_class(char *name) {
	return new_simple_variable("objectid",DTYPE_INT,0,0);
}

// Create a variable containing an Object of type 'name'...
struct variable *new_variable_object(char *name) {
struct variable *v;
	v=new_base_variable(NULL);
	v->var_data.variable_type=VARIABLE_TYPE_OBJECT;
        v->var_data.variable_data_u.v_object.class_name=strdup(name);
        v->var_data.variable_data_u.v_object.definition=find_class(name);

	return v;

}


int check_for_bad_report_variables(struct variable_list *report_vars) {
int a;
if (report_vars==NULL) return 0;
if (report_vars->variables.variables_len==0) return 0;
for (a=0;a<report_vars->variables.variables_len;a++) {
	struct variable *v;
	v=report_vars->variables.variables_val[a];
	if (A4GL_aubit_strcasecmp(v->names.names.names_val[0].name,"pageno")==0) {
		set_yytext(v->names.names.names_val[0].name);
		return 1;
	}
	if (A4GL_aubit_strcasecmp(v->names.names.names_val[0].name,"lineno")==0) {
		set_yytext(v->names.names.names_val[0].name);
		return 1;
	}
}


return 0;
}

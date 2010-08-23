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
# $Id: class.c,v 1.21 2010-08-23 17:23:21 mikeaubury Exp $
#
*/

/**
 * @file
 * 
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_4glc_int.h"
#include "variables.h"
#include "commands.h"
#include "parsehelp.h"

/*
=====================================================================
		                    Variables
=====================================================================
*/

/* This is from 4glc.c */
char *allbuff = 0;
int allbuffsize = 0;
char **class_variable_data;
char **class_members;
struct variable **list_parent = 0;
extern struct variable **list_class;	/* Our List */
extern int is_schema;
extern int list_class_cnt;
  //extern int list_class_cnt;	/* Our List */
  extern int list_class_alloc;	/* Our List */

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/


/* Externally callable (non-static) functions */


//andrej int read_class (char *s,int is_parent);

/* static functions declared here */
//static void write_variable_header (struct variable *v);
//static void write_variable_simple (struct variable *v);
//static void write_variable_linked (struct variable *v);
//static void write_variable_record (struct variable *v);
//static void write_variable_object (struct variable *v);
//static void write_variable_assoc (struct variable *v);
//static void write_variable_constant (struct variable *v);
//static void read_class_int (char *name, int *val);
//static void read_class_string (char *name, char **val, int alloc);
//static void read_class_char (char *name, char *val);
//static void read_class_float (char *name, double *val);
//static void read_variable_header (struct variable *v);
//static void read_variable_simple (struct variable *v);
//static void read_variable_linked (struct variable *v);
//static void read_variable_record (struct variable *v);
//static void read_variable_object (struct variable *v);
//static void read_variable_assoc (struct variable *v);
//static void read_variable_constant (struct variable *v);
//static void generate_globals_for (char *s);
//static void write_variable_function (struct variable *v);
//static void read_variable_function (struct variable *v);
//static void do_append (void);
//andrej void dump_class (void);
int class_call(char *s,char *f,int args);

struct s_class_definition *this_class;
/*
=====================================================================
                    Functions definitions
=====================================================================
*/

char tmpbuff[1024] = "";


/*
void
do_append (void)
{
  int init = 0;
  if (allbuffsize == 0)
    init = 1;
  allbuffsize += strlen (tmpbuff) + 10;
  allbuff = acl_realloc (allbuff, allbuffsize);
  if (init)
    strcpy (allbuff, tmpbuff);
  else
    strcat (allbuff, tmpbuff);
}
*/


int 
class_call(char *s,char *f,int args) {
char buff[512];
char *fname;
	strcpy(buff,s);
	strcat(buff,acl_getenv("A4GL_DLL_EXT"));
	fname=A4GL_fullpath_classpath(buff);
	if (fname==0) {
		a4gl_yyerror("Unable to open class file");
		return 0;
	}
#ifndef MSVC
	return A4GL_call_4gl_dll(fname,f,args);
#else
	A4GL_assertion(1,"Not implemented : class_call");
#endif
}




/*
static void escape (char *buff) {
char buff2[1024];
int a;
int b=0;
for (a=0;a<strlen(buff);a++) {
	if (buff[a]=='"') buff2[b++]='\\';
	buff2[b++]=buff[a];
}
buff2[b]=0;
strcpy(buff,buff2);

}
*/



void
class_set_parent (void)
{
  //int a;
  //struct variable *v;
  //int s;


  // Does nothing ?
}



char *
rm_class_copy (char *s)
{
  static char buff[1024];
  char *ptr = 0;
  if (strncmp (s, "CLASS_COPY->", 12) != 0)
    return s;
  strcpy (buff, &s[12]);
  ptr = buff;
  return ptr;
  while (strncmp (s, "parent", 6) == 0)
    ptr += 6;
  return ptr;
}



#ifdef OLD
int isclassvariable(char *s) {
	int dtype;
	int size;
	int vval;
	struct variable *ptr;

	vval=find_variable (s, &dtype, &size, 0, &ptr);

	if (vval!=-2) {
		return 0; // We're expecting a record/object
	}

	if (ptr->var_data.variable_type != VARIABLE_TYPE_OBJECT) {
		return 0; // We're expecting an object
	}

	return 1;
}

int isclassmember(char *s,char *f) {
	int dtype;
	int size;
	int vval;
	int a;
	struct variable *ptr;

	vval=find_variable (s, &dtype, &size, 0, &ptr);

	if (vval!=-2) {
		return 0; // We're expecting a record/object
	}
	if (ptr->var_data.variable_type != VARIABLE_TYPE_OBJECT) {
		return 0; // We're expecting an object
	}

	//
	
  	class_members = CLASS_get_members (s);


	// Second - is this a method of a  'superclass'
	if ((long) class_members==-1 || (long) class_members==0) ; 
	else {
		for (a=0;class_members[a];a++) {if (A4GL_aubit_strcasecmp(f,class_members[a])==0) return 1;}
	}
	return 0;
}
#endif

void add_class_module_entry(void) {
	struct module_entry *e;
	e=new_module_entry(E_MET_CLASS_DEFINITION);
	memcpy(&e->module_entry_u.class_definition, this_class,sizeof(struct s_class_definition));
	add_module_entry(e);
	this_class=0;
}

void add_class_entry(struct module_entry *e) {
	this_class->class_entries.class_entries_len++;
	this_class->class_entries.class_entries_val=realloc(this_class->class_entries.class_entries_val, sizeof(struct module_entry *)* this_class->class_entries.class_entries_len);
	this_class->class_entries.class_entries_val[this_class->class_entries.class_entries_len-1]=e;
}

void new_class(char *cname, char *pname) {
	this_class=malloc(sizeof(struct s_class_definition));
	this_class->classname=strdup(cname);
	this_class->parentname=strdup(pname);
	//this_class->public_variables.variables.variables_len=0;
	this_class->private_variables.variables.variables_len=0;
	this_class->class_entries.class_entries_len=0;
	this_class->class_entries.class_entries_val=0;
}





int read_class (char *s, int is_parent)
{
A4GL_assertion(1,"Not implemented yet");
return 0;
}


struct s_module_entry_ptr_list  * new_module_entry_list(struct  module_entry *p) {
	struct s_module_entry_ptr_list  *l;
	l=malloc(sizeof(struct s_module_entry_ptr_list));
	l->module_entry_ptr_list.module_entry_ptr_list_len=0;
	l->module_entry_ptr_list.module_entry_ptr_list_val=0;
	if (p)  {
		append_module_entry_list(l,p);
	}
	return l;

}
struct s_module_entry_ptr_list  * append_module_entry_list(struct s_module_entry_ptr_list  *l, struct  module_entry *p) {
	if (p!=NULL) {
		 l->module_entry_ptr_list.module_entry_ptr_list_len++;
		 l->module_entry_ptr_list.module_entry_ptr_list_val=realloc( l->module_entry_ptr_list.module_entry_ptr_list_val, sizeof( l->module_entry_ptr_list.module_entry_ptr_list_val[0])* l->module_entry_ptr_list.module_entry_ptr_list_len);
		 l->module_entry_ptr_list.module_entry_ptr_list_val[ l->module_entry_ptr_list.module_entry_ptr_list_len-1]=p;
	}
	return l;
}

/* ================================ EOF =================================== */


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
# | contact afalout@ihug.co.nz                                           |
# +----------------------------------------------------------------------+
#
# $Id: field_handling.c,v 1.11 2008-02-11 17:13:06 mikeaubury Exp $
#*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "a4gl_libaubit4gl.h"
#include "a4gl_memhandling.h"
#include "API_lex_int.h"
#include "field_handling.h"

//char *acl_strdup(char *x);
//char *strcat(char *x,char *y);


struct fh_field_entry *new_field_entry(expr_str *f,struct expr_str *n,int needs_quoting) {
	struct fh_field_entry *field;
	char buff[256];
	field=acl_malloc2(sizeof(struct fh_field_entry));
	field->field =f;
	field->fieldsub  =n;
	return field;
}

void free_field(struct fh_field_entry *field) {
	//
	//
	//@ FIXME - more to free ?
	free(field);
}

struct fh_field_list *new_field_list() {
	struct fh_field_list *field_list;
	field_list=acl_malloc2(sizeof(struct fh_field_list));
	field_list->field_list_entries.field_list_entries_val=0;
	field_list->field_list_entries.field_list_entries_len=0;
	return field_list;
};


struct fh_field_list *append_field_to_list(struct fh_field_list *field_list, struct fh_field_entry *field) {
	field_list->field_list_entries.field_list_entries_len ++;
	field_list->field_list_entries.field_list_entries_val=acl_realloc(field_list->field_list_entries.field_list_entries_val,sizeof(struct fh_field_entry)*field_list->field_list_entries.field_list_entries_len);
	memcpy(&field_list->field_list_entries.field_list_entries_val[field_list->field_list_entries.field_list_entries_len-1],field,sizeof(struct fh_field_entry));
	return field_list;
}


#ifdef OBSOLETE
struct fh_field_list *append_field_name_to_list (struct fh_field_list *field_list,char *n,struct expr_str *s,int quoteit) {
	struct fh_field_entry *field;
	if (field_list==0) {
		field_list=new_field_list();
	}
	field=new_field_entry(n,s,quoteit);
	append_field_to_list(field_list,field);
	return field_list;
}
#endif

#ifdef OLD
char *field_name_as_char(struct fh_field_entry *f) {
	char *s;
	s=A4GL_field_name_as_char(f->field_name,f->field_sub);
	return s;

	//SPRINTF2(buff,"%s,%s",f->field_name,f->field_sub);
	//return buff;
}


char *field_name_list_as_char(struct fh_field_list *fl) {
int a;
char *ptr=0;
char *ptr_field;
ptr=acl_malloc2(10); /* Set it up initially...*/
strcpy(ptr,"");
for (a=0;a<fl->field_list_entries.field_list_entries_len;a++) {
	ptr_field=field_name_as_char(&fl->field_list_entries.field_list_entries_val[a]);
	ptr=acl_realloc(ptr,strlen(ptr)+strlen(ptr_field)+2);
	if (strlen(ptr)) strcat(ptr,",");
	strcat(ptr,ptr_field);
}

return ptr;
}

char *field_name_list_as_quoted_char_list(struct fh_field_list *fl) {
int a;
char *ptr=0;
char *ptr_field;
ptr=acl_malloc2(10); /* Set it up initially...*/
strcpy(ptr,"\"");
for (a=0;a<fl->field_list_entries.field_list_entries_len;a++) {
	ptr_field=field_name_as_char(&fl->field_list_entries.field_list_entries_val[a]);
	ptr=acl_realloc(ptr,strlen(ptr)+strlen(ptr_field)+10);
	if (a) strcat(ptr,"\",\"");
	strcat(ptr,ptr_field);
}
strcat(ptr,"\"");
return ptr;
}




char *field_name_list_as_or_char(struct fh_field_list *fl) {
int a;
char *ptr=0;
char *ptr_field;
ptr=acl_malloc2(10); /* Set it up initially...*/
strcpy(ptr,"");
for (a=0;a<fl->field_list_entries.field_list_entries_len;a++) {
	ptr_field=field_name_as_char(&fl->field_list_entries.field_list_entries_val[a]);
	ptr=acl_realloc(ptr,strlen(ptr)+strlen(ptr_field)+4);
	if (strlen(ptr)) strcat(ptr,"||");
	strcat(ptr,ptr_field);
}

return ptr;

}
#endif


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
# $Id: field_handling.c,v 1.4 2005-03-09 15:14:14 mikeaubury Exp $
#*/

#include "field_handling.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//char *strdup(char *x);
//char *strcat(char *x,char *y);


struct fh_field_entry *new_field_entry(char *f,char *n,int needs_quoting) {
	struct fh_field_entry *field;
	char buff[256];
	field=malloc(sizeof(struct fh_field_entry));
	if (needs_quoting) {
		sprintf(buff,"\"%s\"",f);
	} else {
		sprintf(buff,"%s",f);
	}
	field->field_name =strdup(buff);
	field->field_sub  =strdup(n);
	return field;
}

void free_field(struct fh_field_entry *field) {
	free(field->field_name);
	free(field->field_sub);
	free(field);
}

struct fh_field_list *new_field_list() {
	struct fh_field_list *field_list;
	field_list=malloc(sizeof(struct fh_field_list));
	field_list->fields=0;
	field_list->nfields=0;
	return field_list;
};


struct fh_field_list *append_field_to_list(struct fh_field_list *field_list, struct fh_field_entry *field) {
	field_list->nfields++;
	field_list->fields=realloc(field_list->fields,sizeof(struct fh_field_entry)*field_list->nfields);
	memcpy(&field_list->fields[field_list->nfields-1],field,sizeof(struct fh_field_entry));
	return field_list;
}


struct fh_field_list *append_field_name_to_list (struct fh_field_list *field_list,char *n,char *s,int quoteit) {
	struct fh_field_entry *field;
	if (field_list==0) {
		field_list=new_field_list();
	}
	field=new_field_entry(n,s,quoteit);
	append_field_to_list(field_list,field);
	return field_list;
}

char *field_name_as_char(struct fh_field_entry *f) {
	static char buff[256];
	sprintf(buff,"%s,%s",f->field_name,f->field_sub);
	return buff;
}


char *field_name_list_as_char(struct fh_field_list *fl) {
int a;
char *ptr=0;
char *ptr_field;
ptr=malloc(10); /* Set it up initially...*/
strcpy(ptr,"");
for (a=0;a<fl->nfields;a++) {
	ptr_field=field_name_as_char(&fl->fields[a]);
	ptr=realloc(ptr,strlen(ptr)+strlen(ptr_field)+2);
	if (strlen(ptr)) strcat(ptr,",");
	strcat(ptr,ptr_field);
}

return ptr;

}


char *field_name_list_as_or_char(struct fh_field_list *fl) {
int a;
char *ptr=0;
char *ptr_field;
ptr=malloc(10); /* Set it up initially...*/
strcpy(ptr,"");
for (a=0;a<fl->nfields;a++) {
	ptr_field=field_name_as_char(&fl->fields[a]);
	ptr=realloc(ptr,strlen(ptr)+strlen(ptr_field)+4);
	if (strlen(ptr)) strcat(ptr,"||");
	strcat(ptr,ptr_field);
}

return ptr;

}

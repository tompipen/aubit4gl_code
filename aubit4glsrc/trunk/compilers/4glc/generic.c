/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-1 Aubit Development Team (See Credits file)       |
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
# $Id: generic.c,v 1.4 2004-01-23 09:53:43 mikeaubury Exp $
#*/

/**
 * @file
 *
 * Describe this file here
 *
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "generic.h"

struct generic_entry_ident *
new_ident (char *identifier)
{
  struct generic_entry_ident *i;
  i = malloc (sizeof (struct generic_entry_ident));
  strcpy (i->identifier, identifier);
  return i;
}


struct generic_entry_variable *
new_variable (void)
{
  struct generic_entry_variable *i;
  i = malloc (sizeof (struct generic_entry_variable));
  return i;
}


// Type can be s,i,d or n (for null)
struct generic_entry_literal *
new_literal (char type, char *ptr)
{
  struct generic_entry_literal *i;

  i = malloc (sizeof (struct generic_entry_literal));

  i->type = type;
  if (type == 's')
    {
      i->data.s = strdup (ptr);
    }

  if (type == 'i')
    {
      i->data.i = atoi (ptr);
    }

  if (type == 'd')
    {
      i->data.d = atof (ptr);
    }
  return i;
}

struct generic_entry_expression2 *
new_expression2 (struct generic_entry *l, struct generic_entry *r, char op)
{
  struct generic_entry_expression2 *i;
  i = malloc (sizeof (struct generic_entry_expression2));
  i->lhs = l;
  i->rhs = r;
  i->op = op;
  return i;
}

struct generic_entry_expression1 *
new_expression1 (struct generic_entry *l, char op)
{
  struct generic_entry_expression1 *i;
  i = malloc (sizeof (struct generic_entry_expression1));
  i->lhs = l;
  i->op = op;
  return i;
}


struct generic_entry_expression_f *
new_functioncall (char *functionname, struct generic_entry_list *l)
{
  struct generic_entry_expression_f *i;
  i = malloc (sizeof (struct generic_entry_expression_f));
  strcpy (i->function_name, functionname);
  i->operands = l;
  return i;
}


struct generic_entry_expression *
new_expression (char type, void *expr)
{
  struct generic_entry_expression *i;
  i = malloc (sizeof (struct generic_entry_expression));
  i->type = type;
  if (type == '1')
    {
      i->data.e1 = expr;
    }
  if (type == '2')
    {
      i->data.e2 = expr;
    }
  if (type == 'f')
    {
      i->data.ef = expr;
    }
  return i;
}




struct generic_entry *
new_entry (char type, void *entry)
{
  struct generic_entry *i;
  i = malloc (sizeof (struct generic_entry));
  i->type = type;
  if (type == 'i')
    {
      i->data.ident = entry;
    }
  if (type == 'v')
    {
      i->data.variable = entry;
    }
  if (type == 'i')
    {
      i->data.literal = entry;
    }
  if (type == 'L')
    {
      i->data.list = entry;
    }
  if (type == 'e')
    {
      i->data.expr = entry;
    }
  return i;

}



struct generic_entry_list *
new_list (struct generic_entry *entry)
{
  struct generic_entry_list *i;
  i = malloc (sizeof (struct generic_entry_list));
  i->entry = entry;
  i->next = 0;
  return i;
}

void
append_list (struct generic_entry_list *orig, struct generic_entry *entry)
{
  struct generic_entry_list *i;
  struct generic_entry_list *ptr;
  ptr = orig;
  while (ptr->next)
    ptr = ptr->next;

  i = malloc (sizeof (struct generic_entry_list));
  i->entry = entry;
  i->next = 0;
  ptr->next = i;
}


struct field_entry *new_field_entry(char *f,char *n,int needs_quoting) {
	struct field_entry *field;
	char buff[256];
	field=malloc(sizeof(struct field_entry));
	if (needs_quoting) {
		sprintf(buff,"\"%s\"",f);
	} else {
		sprintf(buff,"%s",f);
	}
	field_entry.field_name=strdup(buff);
	field_entry.field_sub=strdup(n);
	return field_entry;
}

void free_field(struct field_entry *field) {
	free(field_entry.field_name);
	free(field_entry.field_sub);
	free(field_entry);
}

struct field_list *new_field_list() {
	struct field_list *field_list;
	field_list=malloc(sizeof(struct field_list));
	field_list.fields=0;
	field_list.nfields=0;
	return field_list;
};


struct field_list *append_field_to_list(struct field_list *field_list, struct field_entry *field) {
	field_list.nfields++;
	field_list.fields=realloc(field_list.fields,sizeof(struct field_entry)*field_list.nfields);
	return field_list;
}


struct field_list *append_field_name_to_list (struct field_list *field_list,char *n,char *s) {
	struct field_entry *field;
	if (field_list==0) {
		field_list=new_field_list();
	}
	field=new_field(n,s);
	append_field_to_list(field_list,field);
	return field_list;
}

char *field_name_as_char(struct field_entry *f) {
return "";
}


char *field_name_list_as_char(struct field_list *fl) {
return "";
}


char *field_name_list_as_or_char(struct field_list *fl) {
return "";
}

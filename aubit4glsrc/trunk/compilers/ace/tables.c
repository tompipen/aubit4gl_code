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
# $Id: tables.c,v 1.6 2004-01-29 08:35:41 mikeaubury Exp $
#*/

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

#include "a4gl_ace_int.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

/* extern int status; */

struct select_columns
{
  char *table;
  char *column;
  char *alias;
  struct select_columns *next;
};

struct column
{
  char *colname;
  int size;
  int dtype;
  struct column *next;
};

struct table
{
  char *tablename;
  char *alias;
  struct column *first_col;
  struct table *next;
};


struct table *tables = 0;
struct table *last_table = 0;

struct select_columns *sel_col_start = 0;


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

int add_columns (char *tabname, struct table *table);
void add_column (struct table *table, char *colname, int size, int dtype);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 *
 */
void
reset_sql_stuff (void)
{
  tables = 0;
  last_table = 0;
  sel_col_start = 0;
}

/**
 *
 */
void
check_sql_columns (void)
{
  struct select_columns *ptr_last;
  ptr_last = sel_col_start;
  while (ptr_last->next != 0)
    {
      /*printf(" COLUMN : %s\n",ptr_last->alias); */
      ptr_last = ptr_last->next;
    }
}


/**
 *
 */
void
add_select_column (char *colname, char *alias)
{
  struct select_columns *ptr;
  struct select_columns *ptr_last;
/*char buff1[256];
char buff2[256];
char buff3[256];*/
  /*printf("Adding  %s %s\n",colname,alias); */
  ptr = malloc (sizeof (struct select_columns));
  ptr->table = 0;
  ptr->column = strdup (colname);
  ptr->alias = strdup (alias);
  ptr->next = 0;
  if (sel_col_start == 0)
    {
      /*printf("Add start\n"); */
      sel_col_start = ptr;
    }
  else
    {
      ptr_last = sel_col_start;
      /*printf("Append\n"); */
      while (ptr_last->next != 0)
	{
	  ptr_last = ptr_last->next;
	}
      ptr_last->next = ptr;
    }
}

/**
 *
 */
int
add_columns (char *tabname, struct table *table)
{
  int rval;
  int isize = 0;
  int idtype = 0;
  char colname[256] = "";
  char ccol[200] = "";
  char buff[512];
  rval = A4GLSQL_get_columns (tabname, colname, &idtype, &isize);
  if (rval == 0 && tabname)
    {
      sprintf (buff, "%s does not exist in the database", tabname);
      a4gl_ace_yyerror (buff);
      return 1;
    }

  while (1)
    {
      /*        int A4GLSQL_next_column(char **colname, int *dtype,int *size); */
      rval = A4GLSQL_next_column ((char **) ccol, &idtype, &isize);

      if (rval == 0)
	break;
      strcpy (colname, ccol);
      /* free(ccol); */
      add_column (table, colname, isize, idtype);
    }
  A4GLSQL_end_get_columns ();
  return 1;
}

/**
 *
 */
void
add_column (struct table *table, char *colname, int size, int dtype)
{
  struct column *col;
  struct column *ptr;
  ptr = malloc (sizeof (struct column));

  ptr->colname = strdup (colname);
  ptr->size = size;
  ptr->dtype = dtype;
  ptr->next = 0;

  col = table->first_col;

  if (col)
    {
      while (col->next)
	{
	  col = col->next;
	}
      col->next = ptr;
    }
  else
    {
      table->first_col = ptr;
    }

}

/**
 *
 /opt/aubit/aubit4glsrc/incl/a4gl_API_form.h:129: warning: previous declaration of `add_table'
 */
/*had to rename function: */
int
ace_add_table (char *tabname, char *alias)
{
  struct table *ptr;
  ptr = malloc (sizeof (struct table));
  ptr->next = 0;
  ptr->first_col = 0;
  ptr->tablename = strdup (tabname);
  ptr->alias = strdup (alias);

  if (last_table == 0)
    {
      last_table = ptr;
      tables = ptr;
    }
  else
    {
      last_table->next = ptr;
      last_table = ptr;
    }
  return add_columns (tabname, ptr);
}


/* ============================= EOF ================================ */

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
# $Id: schema_in_file.c,v 1.33 2010-01-12 09:01:49 mikeaubury Exp $
#*/

/**
 * @file
 *
 * Module with implementations for sql functions for compilation
 * where the database is not currently available.
 * This reads from a flat file named 'db.schema' containing
 *
 * 	[tablename] 
 *          COLUMN_NAME AUBITDATATYPE AUBITSIZE
 *          COLUMN_NAME AUBITDATATYPE AUBITSIZE
 *          .
 *          .
 */

 /*
    =====================================================================
    Includes
    =====================================================================
  */

#include "a4gl_lib_sql_int.h"
#include "a4gl_expr.h"
extern sqlca_struct a4gl_sqlca;
/*
=====================================================================
                    Variables definitions
=====================================================================
*/


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

FILE *f_db_in;
char *A4GL_global_A4GLSQL_get_sqlerrm (void);
//static struct expr_str_list *A4GL_add_validation_elements_to_expr (struct expr_str_list *ptr, char *val);
//void * A4GL_new_expr (char *value);
//void * A4GL_append_expr (struct expr_str *orig_ptr, char *value);
/* We only need to implement the functions used by the compiler :

         A4GLSQL_end_get_columns
         A4GLSQL_get_columns
         A4GLSQL_get_sqlerrm
         A4GLSQL_get_status
         A4GLSQL_init_connection
         A4GLSQL_initlib 		** NOT REQUIRED - allow_missing
         A4GLSQL_next_column
         A4GLSQL_read_columns
         A4GLSQL_set_status

*/




/**
 *
 * @todo Describe function
 */
int
A4GLSQLLIB_A4GLSQL_init_connection_internal (char *dbName)
{
  char fname[256];
  char *f;
  sprintf (fname, "%s",dbName);
  f=acl_getenv_not_set_as_0("A4GL_SCHEMA_EXT");
  if (f==0) {
	  f=".schema";
  }
  strcpy(fname, dbName);
	A4GL_trim(fname);
  strcat(fname,f);
  A4GL_debug("OPEN SCHEMA : %s",fname);
  f_db_in = A4GL_open_file_dbpath (fname);
  if (f_db_in == 0)
    {
      A4GL_set_errm (fname);
      A4GL_exitwith ("Couldn't open schema file");
      printf ("Couldn't open schema file %s in DBPATH\n", fname);
      exit (1);
    }

  return 0;
}

int A4GLSQLLIB_SQL_initlib(void) {
	return 1;
}

#ifdef MOVED
/**
 *
 * @todo Describe function
 */
int
A4GLSQL_get_status (void)
{
  return a4gl_sqlca.sqlcode;
}
#endif

/**
 *
 * @todo Describe function
 */
char *
A4GLSQLLIB_A4GLSQL_get_sqlerrm (void)
{
  return A4GL_global_A4GLSQL_get_sqlerrm ();
}



#ifdef OBSOLETE
/**
 *
 *
 * @todo Describe function
 */
int
A4GLSQLLIB_A4GLSQL_read_columns (char *tabname, char *colname, int *dtype,
				 int *size)
{
  char *buff;
  if (f_db_in == 0)
    {
      A4GL_exitwith ("Not connected to database");
      return 0;
    }
  A4GL_debug ("READ COLUMNS\n");
  A4GLSQLLIB_A4GLSQL_get_columns (tabname, colname, dtype, size);

  while (A4GLSQL_next_column (&buff, dtype, size))
    {
      if (strcasecmp (colname, buff) == 0)
	return 1;
    }
  return 0;
}
#endif

/**
 *
 * @todo Describe function
 */
int
A4GLSQL_initsqllib (void)
{
  return 1;
}

int
A4GLSQLLIB_A4GLSQL_get_columns (char *tabname, char *colname, int *dtype,
				int *size)
{
  char buff[256];
  char tname[256];
  if (f_db_in == 0)
    {
      A4GL_exitwith ("Not connected to database");
      return 0;
    }

  rewind (f_db_in);

  while (1)
    {
      if (feof (f_db_in))
	break;
      fgets (buff, 255, f_db_in);
      A4GL_debug ("%s\n", buff);
      if (buff[0] == '[')
	{
	  char *ptr;
	  strcpy (tname, &buff[1]);
	  ptr = strchr (tname, ']');
	  if (!ptr)
	    {
	      A4GL_exitwith ("Parse error in schema file - no ']'");
	      return 0;
	    }

	  *ptr = 0;
	  ptr = strchr (tname, ' ');
	  if (ptr)
	    *ptr = 0;

	  A4GL_debug ("Checking table : %s %s\n", tname, tabname);
	  if (strcasecmp (tname, tabname) == 0)
	    {
	      // Found it...
	      return 1;
	    }
	}
    }
  A4GL_set_errm (tabname);
	A4GL_debug("tabname : %s not found",tabname);
  A4GL_exitwith ("Table not found\n");
  return 0;
}



int
A4GLSQLLIB_A4GLSQL_end_get_columns (void)
{
  return 0;
}

int
A4GLSQLLIB_A4GLSQL_next_column (char **colname, int *dtype, int *size)
{
  char buff[256];
  static char cname[256];
  int a;
  if (f_db_in == 0)
    {
      A4GL_exitwith ("Not connected to database");
      return 0;
    }

// We should already be at the right spot....
  fgets (buff, 255, f_db_in);

// Is this a valid line ?
  if (buff[0] == '[' || feof (f_db_in))
    return 0;			// Obviously not - its another table...
  a = sscanf (buff, "%s %d %d", cname, dtype, size);
  if (a != 3)
    return 0;

  *dtype=((*dtype) & DTYPE_MASK);
  *colname = cname;

  A4GL_debug ("Got cname as %s dtype=%d\n", cname,*dtype);
  return 1;

}



t_expr_str_list *
A4GLSQLLIB_A4GLSQL_get_validation_expr (char *tabname, char *colname)
{
  printf
    ("Warning Validation feature not implemented in SCHEMA_IN_FILE  SQL Driver");
  return 0;
}

char *
A4GLSQLLIB_A4GLSQL_dbms_dialect (void)
{
  /* this is set in make_connection */
  return "FILE";
}


char *
A4GLSQLLIB_A4GLSQL_syscolval_expr (char *tabname, char *colname, char *typ)
{
  return 0;
}


char *
A4GLSQLLIB_A4GLSQL_get_errmsg (int a)
{
  return 0;
}

char *A4GLSQLLIB_A4GLSQL_get_table_checksum(char *s) {
        return s; // dont worry - we'll try later to implement something 'proper'
}


void A4GLSQLLIB_A4GLSQL_free_prepare_internal (void* sid ) {
/* does nothing in this driver */
 }
int A4GLSQLLIB_A4GLSQL_cancel ()
{
    return 1;
}


char *A4GLSQLLIB_A4GLSQL_fixup_descriptor(char *s) {
        return s;
}

/* =============================== EOF ============================== */

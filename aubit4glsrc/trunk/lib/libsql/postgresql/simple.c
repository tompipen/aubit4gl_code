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
# $Id: simple.c,v 1.3 2003-05-12 14:24:26 mikeaubury Exp $
#*/


/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_lib_sql_int.h"
#include "libpq-fe.h"
#include "sql3types.h"
#define DTYPE_CHAR      0
#define DTYPE_SMINT     1
#define DTYPE_INT       2
#define DTYPE_FLOAT     3
#define DTYPE_SMFLOAT   4
#define DTYPE_DECIMAL   5
#define DTYPE_SERIAL    6
#define DTYPE_DATE      7
#define DTYPE_MONEY     8
#define DTYPE_DTIME     10
#define DTYPE_BYTE      11
#define DTYPE_TEXT      12
#define DTYPE_VCHAR     13
#define DTYPE_INTERVAL  14


//extern sqlca_struct sqlca;
int sqlcode;
static void fixtype (char *ptr, int *d, int *s);

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

char lasterrorstr[1024] = "";
int curr_colno = 0;
/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

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


PGconn *con;
PGresult *res;
char *pghost = "";
char *pgport = NULL;
char *pgoptions = NULL;
char *pgtty = NULL;
char *login = NULL;
char *pwd = NULL;



/**
 *
 * @todo Describe function
 */
int
A4GLSQL_init_connection (char *dbName)
{
  char buff2[256];
  con = PQsetdbLogin (pghost, pgport, pgoptions, pgtty, dbName, login, pwd);
  if (con == NULL)
    {

      set_errm (dbName);
      exitwith ("Could not connect to database");
      return -1;
    }

  if (PQstatus (con) == CONNECTION_BAD)
    {
      if (PQerrorMessage (con))
	sprintf (buff2, "%s - %s", PQerrorMessage (con), dbName);
      else
	sprintf (buff2, "%s - No explanation from the backend", dbName);

      set_errm (buff2);
      exitwith ("Could not connect to database ");
      return -1;

    }

  return 0;
}

/**
 *
 * @todo Describe function
 */
int
A4GLSQL_get_status (void)
{
  return sqlcode;
}

/**
 *
 * @todo Describe function
 */
char *
A4GLSQL_get_sqlerrm (void)
{
  return (char *) global_A4GLSQL_get_sqlerrm ();
}

/**
 *
 * @todo Describe function
 */
int
A4GLSQL_read_columns (char *tabname, char *colname, int *dtype, int *size)
{
  char *buff;
  if (con == 0)
    {
      exitwith ("Not connected to database");
      return 0;
    }
  A4GLSQL_get_columns (tabname, colname, dtype, size);

  while (A4GLSQL_next_column (&buff, dtype, size))
    {
      if (strcasecmp (colname, buff) == 0)
	return 1;
    }
  return 0;
}

/**
 *
 * @todo Describe function
 */
int
A4GLSQL_initsqllib (void)
{
  return 1;
}


PGresult *res;
int nfields = 0;

int
A4GLSQL_get_columns (char *tabname, char *colname, int *dtype, int *size)
{
  char buff[2048];
  char tname[256];
  curr_colno = 0;
  if (con == 0)
    {
      exitwith ("Not connected to database");
      return 0;
    }

// This is nicked from psql ...
  sprintf (buff,
	   "SELECT a.attname, pg_catalog.format_type(a.atttypid, a.atttypmod), a.attnotnull, a.atthasdef, a.attnum FROM pg_catalog.pg_attribute a,pg_class b WHERE a.attrelid = b.oid AND a.attnum > 0 AND NOT a.attisdropped AND b.relname='%s' ORDER BY a.attnum",
	   tabname);

  res = PQexec (con, buff);



  switch (PQresultStatus (res))
    {
    case PGRES_COMMAND_OK:
    case PGRES_TUPLES_OK:
      nfields = PQntuples (res);
      debug ("Returns %d fields", nfields);
      return 1;
    }
  set_errm (tabname);
  exitwith ("Table not found\n");
  return 0;
}



int
A4GLSQL_end_get_columns (void)
{
  PQclear (res);
  return 0;
}

int
A4GLSQL_next_column (char **colname, int *dtype, int *size)
{
  char buff[256];
  static char cname[256];
  int a;
  char *colptr;
  if (con == 0)
    {
      exitwith ("Not connected to database");
      return 0;
    }
  if (curr_colno >= nfields)
    return 0;

  colptr = PQgetvalue (res, curr_colno, 0);
  strcpy (cname, colptr);
  *colname = cname;
  colptr = PQgetvalue (res, curr_colno, 1);
  fixtype (colptr, dtype, size);

  curr_colno++;
  return 1;
}



A4GLSQL_initlib ()
{
  // Does nothing but we need it
}


char *
A4GLSQL_dbms_dialect ()
{
  return "POSTGRES";
}



static void
fixtype (char *type, int *d, int *s)
{
  PGresult *r;
  char buff[256];
  char *typname;
  char *typinput;
  char *typoutput;
  char *l1 = "";
  char *l2 = "";
  strcpy (buff, type);

  if (strchr (buff, '('))
    {
      l1 = strchr (buff, '(');
      *l1 = 0;
      l1++;
    }

  if (strchr (l1, ','))
    {
      l2 = strchr (l1, ',');
      *l2 = 0;
      l2++;
    }

  if (strchr (buff, ' '))
    {
      char *ptr;
      ptr = strchr (buff, ' ');
      *ptr = 0;
    }


  if (strcmp (buff, "character") == 0)
    {
      *d = DTYPE_CHAR;
      *s = atoi (l1);
    }

  if (strcmp (buff, "integer") == 0)
    {
      *d = DTYPE_INT;
    }

  if (strcmp (buff, "smallint") == 0)
    {
      *d = DTYPE_SMINT;
    }

  if (strcmp (buff, "numeric") == 0)
    {
      *d = DTYPE_DECIMAL;
      *s = (atoi (l1) * 16 + atoi (l2));
    }

  if (strcmp (buff, "date") == 0)
    {
      *d = DTYPE_DATE;
    }

  if (strcmp (buff, "money") == 0)
    {
      *d = DTYPE_MONEY;
    }

  if (strcmp (buff, "timestamp") == 0)
    {
      *d = DTYPE_DTIME;
      *s = 0x16000a;
    }

  if (strcmp (buff, "real") == 0)
    {
      *d = DTYPE_SMFLOAT;
    }

  if (strcmp (buff, "double") == 0)
    {
      *d = DTYPE_FLOAT;
    }

  if (strcmp (buff, "interval") == 0)
    {
      *d = DTYPE_INTERVAL;
      *s = 0x249000e;
    }


  if (*d == -1)
    {
      printf ("BAD DATATYPE");
      debug ("Ooops - Unknown datatype : %s", type);
      exitwith ("Invalid datatype for Aubit4GL");
    }
  return;

}


/* =============================== EOF ============================== */

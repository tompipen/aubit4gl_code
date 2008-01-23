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
# $Id: pg8.c,v 1.19 2008-01-23 18:17:29 mikeaubury Exp $
#*/


/*
=====================================================================
		                    Includes
=====================================================================
*/
#include "libpq-fe.h"
#include "pg_config.h"
//#include "postgresql/server/catalog/pg_type.h"
#include "a4gl_lib_sql_int.h"
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
char unloadBuffer[BUFSIZ];
//extern sqlca_struct sqlca;
int sqlcode;
static void fixtype (char *ptr, int *d, int *s);
char *A4GL_global_A4GLSQL_get_sqlerrm (void);
static void defaultNoticeProcessor (void *arg, const char *message);
static void SetErrno (PGresult * res);


#define BPCHAROID             1042
#define VARCHAROID            1043
#define INT4OID                       23
#define INT2OID                       21
#define FLOAT8OID 701
#define FLOAT4OID 700
#define TIMESTAMPOID  1114
#define DATEOID                       1082
#define NUMERICOID                       1700
#define TEXTOID                       25


#define INPUT_OUTPUT_BIND               0
#define INPUT_BIND                      1
#define OUTPUT_BIND                     2
#define NO_BIND                         3


#define PHASE_PRE_FETCH 0
#define PHASE_POST_FETCH 1
#define STMT_CANT_PREPARE -1
#define STMT_DATABASE -2
char *last_msg = 0;
int last_msg_no = 0;
int currServerVersion = 0;
char warnings[9];

int truncated = 0;
int CanUseSavepoints = 0;

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

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
         A4GLSQL_init_connection_internal
         A4GLSQL_initlib 		** NOT REQUIRED - allow_missing
         A4GLSQL_next_column
         A4GLSQL_read_columns
         A4GLSQL_set_status

*/


PGconn *con;
PGresult *resGC = 0;
char *pghost = "";
char *pgport = NULL;
char *pgoptions = NULL;
char *pgtty = NULL;
//char *login = NULL;
//char *pwd = NULL;
static struct expr_str_list *A4GL_add_validation_elements_to_expr (struct
								   expr_str_list
								   *ptr,
								   char *val);


static Oid *Oids (int nbind, struct BINDING *b);	// reserved for future enhancement :-)
PGresult *Execute (char *s, int freeit);
static char *replace_ibind (char *stmt, int ni, struct BINDING *ibind,int type);
static int inTransaction (void);
static int copy_to_obind (PGresult * res, int no, struct BINDING *obind,
			  int row);
//typedef void (*PQnoticeProcessor) (void *arg, const char *message);
static int chk_res (PGresult * res);
static struct s_cid * A4GLSQL_find_cursor (char *cname);

struct s_prepare
{
  int ni;
  struct BINDING *ibind;
  int no;
  struct BINDING *obind;
  char *name;
  char *sql;
  void **data_area_in;
  void **data_area_out;
  char **paramvals;
  int *paramlen;
  int *paramform;
  int reallyprepared;
  PGresult *last_result;
};
//static int setParams (struct s_prepare *p);


/**
 *
 * @todo Describe function
 */
int
A4GLSQLLIB_A4GLSQL_init_connection_internal (char *dbName)
{
  char buff2[256];
  char *envname;
  char *envport;
  char *envhost;
  char tmpDb[256];
char *u = NULL;
char *p = NULL;
    char uname_acl[256];
    char passwd_acl[256];
static int loaded=0;


  int i;


  A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (0);

if (!loaded) {
	loaded++;
A4GLSQLCV_load_convert("INFORMIX","POSTGRES8");
}

  envname = acl_getenv ("PG_DBPATH");

  if (envname)
    {
      /*
         Note: for same purpose ecpg uses this too:

         export PG_DBPATH=dbname[@server][:port]

         This will override any DATABASE statements in the .cpc (This is part of ecpg
         - not aubit4gl)

         see the sourcecode - I found some :
         http://jonathangardner.net/PostgreSQL/doxygen/7.4/connect_8c-source.html
       */

      //WARNING: if dbName contatins anything more then a database name
      //for example [@server][:port] - connct will fail!

      //we would in such case have to sepatate components ourselves, into
      //pgport, dbName and pghost!!!

      //Because this conflicts with the need to be able to specify FULL
      // PG_DBPATH=dbname[@server][:port] in Aubit run_test script (as ecpg 
      // needs this) I am commenting this out for the moment:

      if (strlen (envname))
	{
	  strcpy (tmpDb, envname);
	  dbName = tmpDb;

	  if (strchr (dbName, ':'))
	    {
	      char *ptr;
	      ptr = strchr (dbName, ':');
	      *ptr = 0;
	      ptr++;
	      pgport = ptr;
	    }

	  if (strchr (dbName, '@'))
	    {
	      char *ptr;
	      ptr = strchr (dbName, '@');
	      *ptr = 0;
		ptr++;
		pghost=ptr;
	    }
	}
    }

  envport = acl_getenv ("PG_PORT");
  if (envport)
    {
      A4GL_debug
	("Using a different database port %s specified from the environment",
	 envport);
      if (strlen (envport))
	pgport = envport;
    }

  envhost = acl_getenv ("PG_HOST");
  if (envhost)
    {
      if (strlen (envhost)) {
        A4GL_debug ("Using a different database host %s specified from the environment", envhost);
	pghost = envhost;
	}
    }



    if (A4GL_sqlid_from_aclfile (dbName, uname_acl, passwd_acl))
    {
        A4GL_dbg ("Found in ACL File...");
        u = 0;
        p = 0;
        u = acl_getenv_only ("A4GL_SQLUID");
        p = acl_getenv_only ("A4GL_SQLPWD");
        if (u && strlen (u) == 0) u = NULL;
        if (p && strlen (p) == 0) p = NULL;
        if (!u || !p)
        {
            u = uname_acl;
            p = passwd_acl;
        }
    } else {
        u = acl_getenv_only ("A4GL_SQLUID");
        p = acl_getenv_only ("A4GL_SQLPWD");
        if (u && strlen (u) == 0) u = NULL;
        if (p && strlen (p) == 0) p = NULL;
    }


  if (pghost)
    A4GL_debug ("Host=%s", pghost);
  if (pgport)
    A4GL_debug ("Port=%s", pgport);
  if (dbName)
    A4GL_debug ("dbName=%s", dbName);

  if (u)
    A4GL_debug ("login=%s", u);
  if (p)
    A4GL_debug ("passwd=%s", p);

  con = PQsetdbLogin (pghost, pgport, pgoptions, pgtty, dbName, u,p);
  if (con == NULL)
    {

      A4GL_set_errm (dbName);
      A4GL_exitwith_sql ("Could not connect to database");
      return -1;
    }

  if (PQstatus (con) == CONNECTION_BAD)
    {
      if (PQerrorMessage (con))
	SPRINTF2 (buff2, "%s - %s", PQerrorMessage (con), dbName);
      else
	SPRINTF1 (buff2, "%s - No explanation from the backend", dbName);

      A4GL_set_errm (buff2);
      A4GL_exitwith_sql ("Could not connect to database ");
      return -1;

    }
  PQsetNoticeProcessor (con, defaultNoticeProcessor, 0);
  CanUseSavepoints = 0;
  if (con)
    {
      PGresult *res = 0;
      PGresult *res2 = 0;

#if  ( PG_VERSION_NUM > 80100 )
      currServerVersion = PQserverVersion (con);
      if (currServerVersion >= 80100)
	{
	  if (!A4GL_isyes (acl_getenv ("DISABLESAVEPOINTS")))
	    {
	      CanUseSavepoints = 1;
	    }
	}
#else
      // work it out by trying it..
      res2 = PQexec (con, "BEGIN WORK");
      PQclear (res2);
      res = PQexec (con, "SAVEPOINT pr1");
      res2 = PQexec (con, "COMMIT WORK");
      PQclear (res2);
      if (PQresultStatus (res) == PGRES_COMMAND_OK)
	{
	  if (!A4GL_isyes (acl_getenv ("DISABLESAVEPOINTS")))
	    {
	      CanUseSavepoints = 1;
	    }
	}
#endif
    }


  A4GL_add_pointer ("default", SESSCODE, con);
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

int
A4GLSQLLIB_A4GLSQL_close_session_internal (char *sessname)
{
  PGconn *con=0;
  A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (0);

  con = (PGconn *) A4GL_find_pointer (sessname, SESSCODE);

  if (con)
    {
      PQfinish (con);
  	A4GL_del_pointer (sessname, SESSCODE);
    }
  return 1;

}



/**
 *
 * @todo Describe function
 */
char *
A4GLSQLLIB_A4GLSQL_get_sqlerrm (void)
{
  return (char *) A4GL_global_A4GLSQL_get_sqlerrm ();
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


int nfieldsForGetColumns = 0;

int
A4GLSQLLIB_A4GLSQL_get_columns (char *tabname, char *colname, int *dtype,
				int *size)
{
  char buff[2048];
  char tname[256];
  curr_colno = 0;

  if (strchr (tabname, ':'))
    {
      strcpy (tname, strchr (tabname, ':') + 1);
      tabname = tname;
    }


  if (A4GL_esql_db_open (-1, 0, 0, ""))
    {
      con = A4GL_esql_dbopen_connection ();
    }
  if (con == 0)
    {
      A4GL_exitwith_sql ("Not connected to database");
      return 0;
    }

// This is nicked from psql ...
  SPRINTF1 (buff,
	    "SELECT a.attname, pg_catalog.format_type(a.atttypid, a.atttypmod), a.attnotnull, a.atthasdef, a.attnum FROM pg_catalog.pg_attribute a,pg_class b WHERE a.attrelid = b.oid AND a.attnum > 0 AND NOT a.attisdropped AND b.relname='%s' ORDER BY a.attnum",
	    tabname);

  resGC = PQexec (con, buff);



  switch (PQresultStatus (resGC))
    {
    case PGRES_COMMAND_OK:
    case PGRES_TUPLES_OK:
      nfieldsForGetColumns = PQntuples (resGC);
      A4GL_debug ("Returns %d fields", nfieldsForGetColumns);
      if (nfieldsForGetColumns)
	return 1;

    case PGRES_EMPTY_QUERY:
    case PGRES_COPY_OUT:
    case PGRES_COPY_IN:
    case PGRES_BAD_RESPONSE:
    case PGRES_NONFATAL_ERROR:
    case PGRES_FATAL_ERROR:
      A4GL_set_errm (tabname);
      A4GL_exitwith_sql ("Unexpected postgres return code1\n");
      return 0;
    }
  A4GL_set_errm (tabname);
  A4GL_exitwith_sql ("Table not found\n");
  return 0;
}



int
A4GLSQLLIB_A4GLSQL_end_get_columns (void)
{
  PQclear (resGC);
  return 0;
}

int
A4GLSQLLIB_A4GLSQL_next_column (char **colname, int *dtype, int *size)
{
  //char buff[256];
  static char cname[256];
  //int a;
  char *colptr;
  strcpy (cname, "");
  *colname = cname;
  *dtype = 0;
  *size = 0;

  if (A4GL_esql_db_open (-1, 0, 0, ""))
    {
      con = A4GL_esql_dbopen_connection ();
    }
  if (con == 0)
    {
      A4GL_exitwith_sql ("Not connected to database");
      return 0;
    }
  if (curr_colno >= nfieldsForGetColumns)
    return 0;

  colptr = PQgetvalue (resGC, curr_colno, 0);
  if (colptr)
    {
      strcpy (cname, colptr);
      *colname = cname;
    }
  else
    {
      strcpy (cname, "UNKNOWN");
      *colname = cname;

    }
  colptr = PQgetvalue (resGC, curr_colno, 1);
  if (!colptr)
    {
      colptr = "character(1)";
    }
  fixtype (colptr, dtype, size);


  curr_colno++;
  if (*dtype == -1)
    return 0;
  return 1;
}

//obsolete comment - remove:
/* Prototype for tis function is unfortunately printed into API_sql.c and into
API_sql.h, so we cant include it here. Since they are generated by dlmagic,
changing this would affest all other APIs, so since we are lazy, we will 
put proto here too, and hope it will never change... :-(
*/
//int A4GLSQL_initlib (void);
int
A4GLSQL_initlib (void)
{
  // Does nothing but we need it
  return 1;
}


char *
A4GLSQLLIB_A4GLSQL_dbms_dialect (void)
{
  /* 
     WARNING - make sure we use names as per file naming in
     etc/convertsql/
     This string will be used in /lib/libaubit4gl/sqlconvert.c 
     to form file name
   */

  return "POSTGRES8";
}



static void
fixtype (char *type, int *d, int *s)
{
  //PGresult *r;
  char buff[256];
  //char *typname;
  //char *typinput;
  //char *typoutput;

  char *l1 = "";
  char *l2 = "";
  *s = 0;
  *d = -1;
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


  if (strcmp (buff, "interval day to day") == 0) { *d = DTYPE_INTERVAL; *s = 0x233; return; }
  if (strcmp (buff, "interval day to hour") == 0) { *d = DTYPE_INTERVAL; *s = 0x234; return; }
  if (strcmp (buff, "interval day to minute") == 0) { *d = DTYPE_INTERVAL; *s = 0x235; return; }
  if (strcmp (buff, "interval day to second") == 0) { *d = DTYPE_INTERVAL; *s = 0x236; return; }
  if (A4GL_strstartswith (buff, "interval day to fraction")) { *d = DTYPE_INTERVAL; *s = 0x239; return; }

  if (strcmp (buff, "interval hour to hour") == 0) { *d = DTYPE_INTERVAL; *s = 0x244; return; }
  if (strcmp (buff, "interval hour to minute") == 0) { *d = DTYPE_INTERVAL; *s = 0x245; return; }
  if (strcmp (buff, "interval hour to second") == 0) { *d = DTYPE_INTERVAL; *s = 0x246; return; }
  if (A4GL_strstartswith (buff, "interval hour to fraction")) { *d = DTYPE_INTERVAL; *s = 0x249; return; }
  if (strcmp (buff, "interval minute to minute") == 0) { *d = DTYPE_INTERVAL; *s = 0x255; return; }
  if (strcmp (buff, "interval minute to second") == 0) { *d = DTYPE_INTERVAL; *s = 0x256; return; }
  if (A4GL_strstartswith (buff, "interval minute to fraction")) { *d = DTYPE_INTERVAL; *s = 0x259; return; }
  if (strcmp (buff, "interval second to second") == 0) { *d = DTYPE_INTERVAL; *s = 0x266; return; }
  if (A4GL_strstartswith (buff, "interval second to fraction")) { *d = DTYPE_INTERVAL; *s = 0x269; return; }


  if (A4GL_strstartswith (buff, "character varying"))
    {
      buff[9] = '_';
      *d = DTYPE_VCHAR;
      if (strlen (l1) != 0)
	{
	  *s = atoi (l1);
	}
      else
	{
	  *s = 255;
	}

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

  if (strcmp (buff, "integer") == 0 || strcmp (buff, "bigint") == 0)
    {
      *d = DTYPE_INT;
      *s = sizeof (long);
    }

  if (strcmp (buff, "smallint") == 0)
    {
      *d = DTYPE_SMINT;
      *s = sizeof (short);
    }

  if (strcmp (buff, "numeric") == 0)
    {
      *d = DTYPE_DECIMAL;
      *s = ((atoi (l1) << 8) + atoi (l2));
    }

  if (strcmp (buff, "date") == 0)
    {
      *d = DTYPE_DATE;
      *s = sizeof (long);
    }

  if (strcmp (buff, "money") == 0)
    {
      *d = DTYPE_MONEY;
    }

  if (strcmp (buff, "timestamp") == 0)
    {
      *d = DTYPE_DTIME;
      *s = 22;
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
      *s = 0x249; //000e;
    }


  if (*d == -1)
    {
      *d = DTYPE_VCHAR;
      *s = 0xff;


      A4GL_debug ("Ooops - Unknown datatype : %s", type);
      //A4GL_exitwith_sql ("Invalid datatype for Aubit4GL");
    }
  return;

}



static struct expr_str_list *
A4GL_add_validation_elements_to_expr (struct expr_str_list *ptr, char *val)
{
  char *ptr2;
  char *ptrn;
  //char buff[256];
  A4GL_trim (val);
  ptr2 = val;
  while (1)
    {
      ptrn = strtok (ptr2, ",");
      if (ptrn == 0)
	break;
      if (ptr2)
	{
	  ptr2 = 0;
	}


      if (ptr == 0)
	{
	  ptr = A4GL_new_ptr_list (A4GL_new_literal_string (ptrn));
	  //ptr = A4GL_new_expr (buff);
	}
      else
	{
	  ptr =
	    A4GL_new_append_ptr_list (ptr, A4GL_new_literal_string (ptrn));
	}


    }
  return ptr;
}

t_expr_str_list *
A4GLSQLLIB_A4GLSQL_get_validation_expr (char *tabname, char *colname)
{
  char buff[300];
  char val[65];
  struct expr_str_list *ptr = 0;
  int nrows = 0;
  int a;
  PGresult *res2;

  SPRINTF3 (buff,
	    "select attrval from %s where attrname='INCLUDE' and tabname='%s' and colname='%s'",
	    acl_getenv ("A4GL_SYSCOL_VAL"), tabname, colname);
  A4GL_debug ("buff=%s", buff);
  res2 = PQexec (con, buff);

  switch (PQresultStatus (res2))
    {
    case PGRES_COMMAND_OK:
    case PGRES_TUPLES_OK:
      nrows = PQntuples (res2);
      A4GL_debug ("Returns %d fields", nrows);
      break;
    case PGRES_NONFATAL_ERROR:
      return 0;
    case PGRES_EMPTY_QUERY:
    case PGRES_COPY_OUT:
    case PGRES_COPY_IN:
    case PGRES_BAD_RESPONSE:
    case PGRES_FATAL_ERROR:
      A4GL_debug ("Got : %d", PQresultStatus (res2));
      A4GL_set_errm (tabname);
      A4GL_exitwith_sql ("Unexpected postgres return code2\n");
      //return -1;
      return (void *) -1;
      // warning: return makes pointer from integer without a cast
    }

  if (!nrows)
    {
      return 0;
    }
  for (a = 0; a < nrows; a++)
    {
      strcpy (val, PQgetvalue (res2, a, 0));
      ptr = A4GL_add_validation_elements_to_expr (ptr, val);
    }
  return ptr;
}

char *
A4GLSQLLIB_A4GLSQL_get_errmsg (int a)
{
  if (a == last_msg_no)
    return last_msg;
  else
    return "Unknown Error";
}


char *
A4GLSQLLIB_A4GLSQL_syscolval_expr (char *tabname, char *colname, char *typ)
{
  return 0;
}


#ifdef NDEF
int
printField (FILE * outputFile, int idx, char *descName)
{
  EXEC SQL BEGIN DECLARE SECTION;
  int dataType;
  int index;
  short indicator;
  char buffer[32000] = "";
  int length;
  int COUNT;
  int INTVAR, BOOLVAR;
  int INDICATOR;
  int TYPE, LENGTH, OCTET_LENGTH, PRECISION, SCALE, NULLABLE,
    RETURNED_OCTET_LENGTH;
  int DATETIME_INTERVAL_CODE;
  char NAME[120];
  char STRINGVAR[1024];
  float FLOATVAR;
  double DOUBLEVAR;
  EXEC SQL END DECLARE SECTION;
  char buff[255];
  char fmt[255];
  int rc = 0;
  index = idx;

  A4GL_debug ("Getting details for index %d", index);
exec sql get descriptor descExec value:index:TYPE = type,: LENGTH = length,: OCTET_LENGTH = octet_length,: RETURNED_OCTET_LENGTH = returned_octet_length,: PRECISION = precision,: SCALE = scale,: NULLABLE = nullable,: NAME = name,:INDICATOR =
    indicator;
  cp_sqlca ();

  A4GL_debug ("%2d\t%s (type: %d length: %d precision: %d scale: %d\n"
	      "\toctet_length: %d returned_octet_length: %d nullable: %d)\n\t= ",
	      index, NAME, TYPE, LENGTH, PRECISION, SCALE, OCTET_LENGTH,
	      RETURNED_OCTET_LENGTH, NULLABLE);
  if (INDICATOR == -1)
    SPRINTF (buffer, "");
  else
    switch (TYPE)
      {
      case SQL3_BOOLEAN:
      exec sql get descriptor descExec value: index:BOOLVAR = data;
	cp_sqlca ();
	if (display_mode != DISPLAY_UNLOAD)
	  {
	    SPRINTF1 (buffer, "%s", BOOLVAR ? "true" : "false");
	  }
	else
	  {
	    SPRINTF1 (buffer, "%d", BOOLVAR);
	  }
	break;


      case SQL3_NUMERIC:
      case SQL3_DECIMAL:
	if (SCALE == 0)
	  {
	    exec sql get descriptor descExec value:index:INTVAR = data;
	    cp_sqlca ();
	    if (display_mode == DISPLAY_DOWN)
	      {
		SPRINTF1 (buffer, "%d", INTVAR);
	      }
	    else
	      {
		SPRINTF1 (buffer, "%*d", columnWidths[idx - 1], INTVAR);
	      }
	    if (display_mode == DISPLAY_UNLOAD)
	      ltrim (buffer);
	  }
	else
	  {

	    exec sql get descriptor descExec value:index:FLOATVAR = data;
	    cp_sqlca ();

	    if (display_mode == DISPLAY_DOWN)
	      {
		SPRINTF1 (buffer, "%f", FLOATVAR);
	      }
	    else
	      {
		SPRINTF1 (buffer, "%*f", columnWidths[idx - 1], FLOATVAR);
	      }
	    if (display_mode == DISPLAY_UNLOAD)
	      ltrim (buffer);
	  }
	break;
      case SQL3_INTEGER:
      case SQL3_SMALLINT:
      exec sql get descriptor descExec value: index:INTVAR = data;
	cp_sqlca ();


	if (display_mode == DISPLAY_DOWN)
	  {
	    SPRINTF1 (buffer, "%d", INTVAR);
	  }
	else
	  {
	    SPRINTF1 (buffer, "%*d", columnWidths[idx - 1], INTVAR);
	  }
	if (display_mode == DISPLAY_UNLOAD)
	  ltrim (buffer);
	break;
      case SQL3_FLOAT:
      case SQL3_REAL:
      exec sql get descriptor descExec value: index:FLOATVAR = data;
	cp_sqlca ();
	SPRINTF1 (buffer, "%.*f", PRECISION, FLOATVAR);
	if (display_mode == DISPLAY_UNLOAD)
	  ltrim (buffer);
	break;
      case SQL3_DOUBLE_PRECISION:
      exec sql get descriptor descExec value: index:DOUBLEVAR = data;
	cp_sqlca ();
	SPRINTF1 (buffer, "%.*f", PRECISION, DOUBLEVAR);
	if (display_mode == DISPLAY_UNLOAD)
	  ltrim (buffer);
	break;
      case SQL3_DATE_TIME_TIMESTAMP:
      exec sql get descriptor descExec value: index: DATETIME_INTERVAL_CODE = datetime_interval_code,:STRINGVAR =
	  data;
	cp_sqlca ();
	SPRINTF1 (buffer, "%s", STRINGVAR);
	break;
      case SQL3_INTERVAL:
      exec sql get descriptor descExec value: index:STRINGVAR = data;
	cp_sqlca ();
	SPRINTF1 (buffer, "%s", STRINGVAR);
	break;
      case SQL3_CHARACTER:
      case SQL3_CHARACTER_VARYING:
      exec sql get descriptor descExec value: index:STRINGVAR = data;
	cp_sqlca ();
	SPRINTF1 (buffer, "%s", STRINGVAR);
	A4GL_trim (buffer);
	break;
      default:
      exec sql get descriptor descExec value: index:STRINGVAR = data;
	cp_sqlca ();
	SPRINTF1 (buffer, "%s", STRINGVAR);
	if (display_mode == DISPLAY_UNLOAD)
	  A4GL_trim (buffer);
	break;
      }

  A4GL_debug ("BUFFER=%s", buffer);

  if (INDICATOR != -1 && strlen (buffer) == 0
      && display_mode == DISPLAY_UNLOAD)
    {
      strcpy (buffer, " ");
    }
  if (display_mode == DISPLAY_DOWN)
    {
      SPRINTF2 (fmt, "%%-%d.%ds %%s\n", colnamesize + 1, colnamesize + 1);

      if (get_exec_mode_c () == EXEC_MODE_INTERACTIVE)
	{
	  FPRINTF (outputFile, fmt, columnNames[idx - 1], buffer);
	}
      else
	{
	  FPRINTF (exec_out, fmt, columnNames[idx - 1], buffer);
	}
      outlines++;
    }

  if (display_mode == DISPLAY_UNLOAD)
    {
      FPRINTF (unloadFile, "%s%s", escape_delim (buffer), delim);
    }

  if (display_mode == DISPLAY_ACROSS)
    {
      if (get_exec_mode_c () == EXEC_MODE_INTERACTIVE)
	{

	  A4GL_debug ("EXECO '%s' '%20s' '%-20s'", buffer, buffer, buffer);
	  FPRINTF (outputFile, "%-*s", columnWidths[idx - 1], buffer);
	}
      else
	FPRINTF (exec_out, "%-*s", columnWidths[idx - 1], buffer);
    }


  return 0;
}

#endif

/**
 * Unload the data to a file acording to SQL statemement with
 * columns separated by a delimiter.
 *
 * @todo : Implement the unload
 * @todo : Merge the code to a connector library in order to have just
 *         one function to do it.
 *
 * @param fname The name where the data is to be inserted.
 * @param delims The row delimiter.
 * @param sql1 The SQL to generate the data.
 *
 * @return
 *   - 1 : There was an error unloading the data.
 *   - 0 : Data unloaded to file.
 */
/*      void A4GLSQL_unload_data(char *fname,char *delims, char *sql1); */
/* int */
void
A4GLSQLLIB_A4GLSQL_unload_data_internal (char *fname_o, char *delims,
					 char *sqlStr_o, int nbind,
					 void *vibind)
{
  FILE *unloadFile;
  int nrows = 0;
  struct BINDING *ibind;
  int colcnt;
  int *column_types = 0;
  int *column_sizes = 0;
  PGresult *res2;
  char *fname;
  int nfields = 0;
  char *sqlStr;
  int a;
  int b;

  if (A4GL_esql_db_open (-1, 0, 0, ""))
    {
      con = A4GL_esql_dbopen_connection ();
    }

  if (con == 0)
    {
      A4GL_exitwith_sql ("Database not open");
      return;
    }


  ibind = vibind;

  A4GL_debug ("Unload data..");

  if (nbind)
    {
	//printf("Replacing in : %s (%d)\n",sqlStr_o, nbind);
	sqlStr= replace_ibind (sqlStr_o, nbind, ibind,0);
	//printf("Replace gives : %s\n",sqlStr);
	sqlStr=strdup(sqlStr);
    } else {
  	sqlStr = strdup (sqlStr_o);
  	A4GL_trim (sqlStr);
    }

//printf("%s\n", sqlStr);

  fname = strdup (fname_o);
  A4GL_trim (fname);
  unloadFile = (FILE *) A4GL_mja_fopen (fname, "wt");
  a4gl_status = 0;

  if (unloadFile == (FILE *) 0)
    {
    /** @todo : Generate some error code compatible with informix 4gl */
      free (fname);
      free (sqlStr);
      A4GL_exitwith_sql ("Unable to open file for unload");
      return;			/* return 1; */
    }

  setbuf (unloadFile, unloadBuffer);
  A4GL_debug ("prepare : %s", sqlStr);



  res2 = PQexec (con, sqlStr);

  switch (PQresultStatus (res2))
    {
    case PGRES_COMMAND_OK:
    case PGRES_TUPLES_OK:
      nrows = PQntuples (res2);
      nfields = PQnfields (res2);
      break;

    case PGRES_EMPTY_QUERY:
    case PGRES_COPY_OUT:
    case PGRES_COPY_IN:
    case PGRES_BAD_RESPONSE:
    case PGRES_NONFATAL_ERROR:
    case PGRES_FATAL_ERROR:
      A4GL_debug ("Got : %d (%s)", PQresultStatus (res2),
		  PQerrorMessage (con));
      SetErrno (res2);
      //A4GL_exitwith_sql ("Unexpected postgres return code3\n");
      free (fname);
      free (sqlStr);
      return;
    }



  column_types = malloc (sizeof (int) * nfields);
  column_sizes = malloc (sizeof (int) * nfields);

  for (colcnt = 0; colcnt < nfields; colcnt++)
    {
      //int dataType;
      //int length;
      //int index;
      //int indicator;
      //index=colcnt+1;
      column_types[colcnt] = PQftype (res2, colcnt);
      column_sizes[colcnt] = PQfmod (res2, colcnt);

    }


  for (a = 0; a < nrows; a++)
    {
      for (b = 0; b < nfields; b++)
	{
	  if (PQgetisnull (res2, a, b))
	    {
	      FPRINTF (unloadFile, "%s", delims);
	    }
	  else
	    {
	      static char *s = 0;
	      static int sl = -1;
	      int nsl;
	      char *ptr;

	      ptr = PQgetvalue (res2, a, b);
	      nsl = strlen (ptr);
	      if (nsl >= sl)
		{
		  sl = nsl;
		  s = realloc (s, sl + 2);
		}
	      strcpy (s, ptr);
	      A4GL_trim (s);
	      if (strlen (s))
		{
		  FPRINTF (unloadFile, "%s%s", s, delims);
		}
	      else
		{
		  FPRINTF (unloadFile, " %s", delims);
		}
	    }
	}
      FPRINTF (unloadFile, "\n");
    }
  fclose (unloadFile);
  PQclear (res2);
  free (fname);
  free (sqlStr);
  free (column_sizes);
  free (column_types);


  return;			/* return 0; */
}

static Oid *
Oids (int nbind, struct BINDING *b)
{
  Oid *ptr;
  int a;
  if (nbind == 0)
    return 0;
  ptr = malloc (sizeof (Oid) * nbind);
  for (a = 0; a < nbind; a++)
    {
      switch (b[a].dtype & DTYPE_MASK)
	{
	case DTYPE_CHAR:
	  ptr[a] = BPCHAROID;
	  break;
	case DTYPE_VCHAR:
	  ptr[a] = VARCHAROID;
	  break;
	case DTYPE_INT:
	  ptr[a] = INT4OID;
	  break;
	case DTYPE_SMINT:
	  ptr[a] = INT2OID;
	  break;
	case DTYPE_SMFLOAT:
	  ptr[a] = FLOAT4OID;
	  break;
	case DTYPE_FLOAT:
	  ptr[a] = FLOAT8OID;
	  break;
	case DTYPE_DECIMAL:
	  ptr[a] = FLOAT8OID;
	  break;
	case DTYPE_MONEY:
	  ptr[a] = FLOAT8OID;
	  break;
	case DTYPE_DATE:
	  ptr[a] = VARCHAROID;
	  break;
	case DTYPE_DTIME:
	  ptr[a] = VARCHAROID;
	  break;

	default:
	  A4GL_assertion (1, "Unhandled datatype");
	  ptr[a] = 0;
	}
    }

  return ptr;

}



void * A4GLSQLLIB_A4GLSQL_prepare_select_internal (void *ibind, int ni, void *obind, int no, char *s, char *uniqid,int singleton)
{
  struct s_prepare *n;
  int l;
  int b;
  char buff[20000];
  int a;
  int ccnt = 1;
  n = malloc (sizeof (struct s_prepare));
  n->ni = ni;
  n->no = no;
  n->ibind = ibind;
  n->obind = obind;
  n->last_result=0;
  //n->hstmt=0;

  if (A4GL_esql_db_open (-1, 0, 0, ""))
    {
      con = A4GL_esql_dbopen_connection ();
    }


  if (!con)
    {
      // no connection..
      if (last_msg)
	free (last_msg);
      last_msg = strdup ("No connection");
      last_msg_no = -349;
      A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (-349);
      return 0;
    }


  l = strlen (s);
  b = 0;
  for (a = 0; a < l; a++)
    {
      char c[20];
      if (s[a] == '?')
	{
	  buff[b++] = '$';
	  buff[b] = 0;
	  SPRINTF1 (c, "%d", ccnt++);
	  strcat (buff, c);
	  b = strlen (buff);

	}
      else
	{
	  buff[b++] = s[a];

	}
    }
  buff[b] = 0;
  n->sql = strdup (buff);
  n->name = strdup (uniqid);
  n->reallyprepared = 0;

  n->data_area_in = 0;
  n->data_area_out = 0;

  if (ni)
    {
      n->data_area_in = A4GL_alloc_associated_mem (n, sizeof (void *) * ni);
    }
  if (no)
    {
      n->data_area_out = A4GL_alloc_associated_mem (n, sizeof (void *) * no);
    }

  if (A4GL_has_pointer (uniqid, PREPAREPG))
    {
      //SPRINTF1 (buff, "DEALLOCATE %s", n->name);
      //PQexec (con, buff);
    }

  A4GL_add_pointer (uniqid, PREPAREPG, n);


  // Might have prepared it before - so get rid...

  A4GL_debug ("-->%s\n", n->sql);
  A4GL_debug ("Prepare : %s\n", n->sql);

#ifdef Lah
  switch (PQresultStatus (res))
    {
    case PGRES_BAD_RESPONSE:
      A4GL_debug ("Bad response %s\n", PQerrorMessage (con));
      //A4GL_exitwith_sql ("Unexpected postgres return code4\n");
      return 0;
    case PGRES_NONFATAL_ERROR:
      A4GL_debug ("nonfatal error %s \n", PQerrorMessage (con));
      //A4GL_exitwith_sql ("Unexpected postgres return code4\n");
      return 0;
    case PGRES_FATAL_ERROR:
      A4GL_debug ("fatal error %s\n", PQerrorMessage (con));
      //A4GL_exitwith_sql ("Unexpected postgres return code4\n");
      return 0;
    }
#endif
  A4GL_debug ("OK..\n");
  return n;
}


#ifdef OBSOLETE
static int
setParams (struct s_prepare *p)
{
  int a;
  int d, m, y;
  char *c;
  for (a = 0; a < p->ni; a++)
    {

      if (A4GL_isnull (p->ibind[a].dtype, p->ibind[a].ptr))
	{
	  p->paramvals[a] = 0;
	  continue;
	}

      switch (p->ibind[a].dtype & DTYPE_MASK)
	{
	case DTYPE_CHAR:
	  p->paramvals[a] = p->ibind[a].ptr;
	  p->paramform[a] = 0;
	  break;
	case DTYPE_VCHAR:
	  p->paramvals[a] = p->ibind[a].ptr;
	  p->paramlen[a] = strlen (p->ibind[a].ptr);
	  p->paramform[a] = 0;
	  break;
	case DTYPE_INT:
	  p->paramvals[a] = A4GL_alloc_associated_mem (p, 20);
	  SPRINTF1 (p->paramvals[a], "%d", *(int *) p->ibind[a].ptr);
	  p->paramlen[a] = 4;
	  p->paramform[a] = 0;
	  break;
	case DTYPE_SMINT:
	  p->paramvals[a] = A4GL_alloc_associated_mem (p, 20);
	  SPRINTF1 (p->paramvals[a], "%d", *(short *) p->ibind[a].ptr);
	  p->paramlen[a] = strlen (p->paramvals[a]);
	  p->paramform[a] = 0;
	  break;

	case DTYPE_SMFLOAT:
	  p->paramvals[a] = p->ibind[a].ptr;
	  SPRINTF1 (p->paramvals[a], "%16.8f", *(float *) p->ibind[a].ptr);
	  p->paramlen[a] = strlen (p->paramvals[a]);
	  p->paramform[a] = 0;
	  break;

	case DTYPE_FLOAT:
	  p->paramvals[a] = p->ibind[a].ptr;
	  SPRINTF1 (p->paramvals[a], "%16.8lf", *(double *) p->ibind[a].ptr);
	  p->paramlen[a] = strlen (p->paramvals[a]);
	  p->paramform[a] = 0;
	  break;

	case DTYPE_DECIMAL:
	  p->paramvals[a] = p->ibind[a].ptr;
	  A4GL_push_dec (p->ibind[a].ptr, 0, p->ibind[a].size);
	  c = A4GL_char_pop ();
	  strcpy (p->paramvals[a], c);
	  free (c);

	  p->paramlen[a] = strlen (p->paramvals[a]);
	  p->paramform[a] = 0;
	  break;

	case DTYPE_MONEY:
	  p->paramvals[a] = p->ibind[a].ptr;
	  A4GL_push_dec (p->ibind[a].ptr, 1, p->ibind[a].size);
	  c = A4GL_char_pop ();
	  strcpy (p->paramvals[a], c);
	  free (c);
	  p->paramlen[a] = strlen (p->paramvals[a]);
	  p->paramform[a] = 0;
	  break;

	case DTYPE_DATE:
	  p->paramvals[a] = A4GL_alloc_associated_mem (p, 20);
	  A4GL_get_date (*(long *) p->ibind[a].ptr, &d, &m, &y);
	  SPRINTF3 (p->paramvals[a], "%04d-%02d-%02d", y, m, d);
	  p->paramlen[a] = strlen (p->paramvals[a]);
	  p->paramform[a] = 0;
	  break;

	case DTYPE_DTIME:
	  p->paramvals[a] = A4GL_alloc_associated_mem (p, 20);

	  A4GL_push_dtime (p->ibind[a].ptr);
	  c = A4GL_char_pop ();
	  strcpy (p->paramvals[a], c);
	  free (c);

	  p->paramlen[a] = strlen (p->paramvals[a]);
	  p->paramform[a] = 0;
	  break;

	default:
	  A4GL_assertion (1, "Unhandled datatype");
	}


    }
  return 0;
}
#endif

int
A4GLSQLLIB_A4GLSQL_execute_implicit_sql (void *vsid, int singleton, int ni,
					 void *binding)
{
  Oid oid;
  struct s_prepare *n;
  //int resultFormat = 0;
  int ok = 0;
  char *sql;
  int setSavepoint = 0;
  char *isInsert;
  int use_insert_return = 0;
  PGresult *res;

  A4GL_debug ("Execute\n");

  if (vsid == 0)
    {				// nothing doing..
      return 0;
    }

  if (A4GL_esql_db_open (-1, 0, 0, ""))
    {
      con = A4GL_esql_dbopen_connection ();
    }

  if (!con)
    {
      // no connection..
      if (last_msg)
	free (last_msg);
      last_msg = strdup ("No connection");
      last_msg_no = -349;
      A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (-349);
      return 0;
    }

  n = vsid;

  if (ni)
    {
      n->ni = ni;
      n->ibind = binding;
    }


  if (strlen (n->sql) == 0)
    return 0;

  A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (0);

  strcpy (warnings, "       ");
  A4GL_copy_sqlca_sqlawarn_string8 (warnings);


  if (currServerVersion >= 80200)
    {
      use_insert_return = 1;
      isInsert = strdup (n->sql);
      A4GL_convlower (isInsert);
      if (A4GL_strstartswith (isInsert, "insert ") && use_insert_return == 1)
	{
	  sql = replace_ibind (n->sql, n->ni, n->ibind,1);
	  strcat (sql, " returning *");
	}
      else
	{
	  sql = replace_ibind (n->sql, n->ni, n->ibind,1);
	}


    }
  else
    {
      use_insert_return = 0;
      sql = replace_ibind (n->sql, n->ni, n->ibind,1);
    }

  if (inTransaction ())
    {
      setSavepoint++;
      if (CanUseSavepoints) { Execute ("SAVEPOINT preExec", 1); }
    }
  A4GL_debug ("%s ni=%d\n", sql, n->ni);

  res = PQexec (con, sql);
   n->last_result=res;

  A4GL_debug ("::: %s - %d\n", n->sql, PQresultStatus (res));

  if (n->no)
    {
      A4GL_assertion (n->no, "Cant execute into anything...");
    }

  switch (PQresultStatus (res))
    {
    case PGRES_COMMAND_OK:
      ok = 1;
      break;
    case PGRES_TUPLES_OK:
      ok = 1;
      break;

    default:
      A4GL_debug ("Bad : %s ", PQerrorMessage (con));
      SetErrno (res);
      ok = 0;
    }

  A4GL_set_a4gl_sqlca_errd (0, atoi (PQcmdTuples (res)));
  A4GL_set_a4gl_sqlca_errd (2, atoi (PQcmdTuples (res)));
  A4GL_set_a4gl_sqlca_errd (1, 0);

  A4GL_set_a4gl_sqlca_errd (5, 0);


  if (PQresultStatus (res) == PGRES_COMMAND_OK
      || PQresultStatus (res) == PGRES_TUPLES_OK)
    {
      int a;
      if (use_insert_return)
	{
	  if (PQresultStatus (res) == PGRES_TUPLES_OK)
	    {
	      int nfields;
	      nfields = PQnfields (res);
	      // Found out row !
	      for (a = 0; a < nfields; a++)
		{
		  if (PQftype (res, a) == 23)
		    {
		      // any serial column must be the first integer...
		      A4GL_set_a4gl_sqlca_errd (1, atoi (PQgetvalue (res, 0, a)));
		      break;
		    }
		}
	    }
	  else
	    {
	      // not found...
	      A4GL_set_a4gl_sqlca_errd (1, 0);
	    }

	}
      else
	{
	  oid = PQoidValue (res);
	  if (oid != InvalidOid)
	    {
	      PGresult *res2;
	      char *s;
	      char *p;
	      int l;
	      s = strdup (n->sql);
	      A4GL_convupper (s);
	      l = strlen (s);
	      p = strstr (s, " VALUES");
	      if (p)
		*p = 0;
	      p = strstr (s, " SELECT");
	      if (p)
		*p = 0;


	      for (a = 0; a < l; a++)
		{
		  if (A4GL_strstartswith (&s[a], "INSERT "))
		    {
		      s[a] = ' ';
		      s[a + 1] = ' ';
		      s[a + 2] = ' ';
		      s[a + 3] = ' ';
		      s[a + 4] = ' ';
		      s[a + 5] = ' ';
		      s[a + 6] = ' ';
		    }
		  if (A4GL_strstartswith (&s[a], " INTO "))
		    {
		      s[a] = ' ';
		      s[a + 1] = ' ';
		      s[a + 2] = ' ';
		      s[a + 3] = ' ';
		      s[a + 4] = ' ';
		      s[a + 5] = ' ';
		    }
		}
	      A4GL_lrtrim (s);
	      if (strchr (s, ' ') == 0)
		{
		  char sql[2000];
		  A4GL_convlower (s);
		  SPRINTF2 (sql, "SELECT * FROM %s WHERE OID=%ld", s, oid);
		  res2 = PQexec (con, sql);


		  if (PQresultStatus (res2) == PGRES_TUPLES_OK)
		    {
		      int nfields;
		      nfields = PQnfields (res2);
		      // Found out row !
		      for (a = 0; a < nfields; a++)
			{
			  if (PQftype (res2, a) == 23)
			    {
			      // any serial column must be the first integer...
			      A4GL_set_a4gl_sqlca_errd (1,
							atoi (PQgetvalue
							      (res2, 0, a)));
			      break;
			    }
			}
		    }
		  else
		    {
		      // not found...
		      A4GL_set_a4gl_sqlca_errd (1, 0);
		    }
		  free (s);
		}
	      A4GL_set_a4gl_sqlca_errd (5, oid);
	    }
	}
    }


  if (ok)
    {
      if (setSavepoint)
	{
	  if (CanUseSavepoints)
	    {
	      Execute ("RELEASE SAVEPOINT preExec", 1);
	    }
	}

      return 0;
    }

  if (setSavepoint)
    {
      if (CanUseSavepoints)
	{
	  Execute ("ROLLBACK TO SAVEPOINT preExec", 1);
	}
    }
  return 1;
}




static int
copy_to_obind (PGresult * res, int no, struct BINDING *obind, int row)
{
  int b;
  int nrows;
  int nfields;

  nrows = PQntuples (res);
  if (row > nrows)
    return 0;

  nfields = PQnfields (res);
  if (nfields > no)
    {
      nfields = no;
    }
  if (nfields != no)
    {
      warnings[0] = 'W';
      warnings[3] = 'W';
    }

  for (b = 0; b < nfields; b++)
    {
      if (PQgetisnull (res, row, b))
	{
	  A4GL_setnull (obind[b].dtype, (char *) obind[b].ptr, obind[b].size);
	}
      else
	{
	  static char *s = 0;
	  static int sl = -1;
	  int nsl;
	  char *ptr;

	  ptr = PQgetvalue (res, row, b);
	  nsl = strlen (ptr);
	  if (nsl >= sl)
	    {
	      sl = nsl;
	      s = realloc (s, sl + 2);
	    }

	  if (obind[b].dtype == DTYPE_DATE)
	    {
	      char buff[2000];
	      strcpy (buff, ptr);
	      if (buff[4] == '-' && buff[7] == '-')
		{
		  int m, d, y;
		  buff[4] = 0;
		  buff[7] = 0;
		  y = atoi (buff);
		  m = atoi (&buff[5]);
		  d = atoi (&buff[8]);
		  *(long *) obind[b].ptr = A4GL_gen_dateno (d, m, y);
		}
	      else
		{
		  A4GL_push_char (ptr);
		  A4GL_pop_param (obind[b].ptr, obind[b].dtype,
				  obind[b].size);
		}
	    }
	  else
	    {
	      char *s;
	      if (obind[b].dtype == DTYPE_CHAR)
		{
		  s = strdup (ptr);
		  A4GL_trim (s);
		  if (strlen (s) > obind[b].size)
		    {
		      // Too large -it'll get truncated...
		      warnings[0] = 'W';
		      warnings[1] = 'W';
		      A4GL_copy_sqlca_sqlawarn_string8 (warnings);
		    }
		}
	      A4GL_push_char (ptr);
	      A4GL_pop_param (obind[b].ptr, obind[b].dtype, obind[b].size);
	    }
	}
    }
  return 0;
}




int
A4GLSQLLIB_A4GLSQL_execute_implicit_select (void *vsid, int singleton)
{
  struct s_prepare *n;
  int ok;
  int nrows;
  int nfields;
  int setSavepoint = 0;
  char *sql;
  PGresult *res;

  n = vsid;

  if (n == 0)
    {
      return 1;
    }

  if (A4GL_esql_db_open (-1, 0, 0, ""))
    {
      con = A4GL_esql_dbopen_connection ();
    }
  if (!con)
    {
      // no connection..
      if (last_msg)
	free (last_msg);
      last_msg = strdup ("No connection");
      last_msg_no = -349;
      A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (-349);
      return 1;
    }

  A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (0);

  strcpy (warnings, "       ");
  A4GL_copy_sqlca_sqlawarn_string8 (warnings);

  A4GL_debug ("Exec sql : %s", n->sql);
  if (inTransaction ())
    {
      setSavepoint++;
      A4GL_debug ("Set savepoint");
      if (CanUseSavepoints)
	{
	  Execute ("SAVEPOINT preExecSelect", 1);
	}
    }

  sql = n->sql;
  if (n->ni)
    {
      sql = replace_ibind (sql, n->ni, n->ibind,1);
    }

  res = PQexec (con, sql);
  n->last_result=res;
  A4GL_debug ("res=%p\n", res);
  A4GL_set_a4gl_sqlca_errd (0, PQntuples (res));
  A4GL_set_a4gl_sqlca_errd (2, atoi (PQcmdTuples (res)));
  A4GL_set_a4gl_sqlca_errd (1, 0);

  n->last_result=res;

  switch (PQresultStatus (res))
    {
    case PGRES_COMMAND_OK:
      ok = 1;
      break;
    case PGRES_TUPLES_OK:
      ok = 1;
      break;

    default:
      A4GL_debug ("BAD\n");
      SetErrno (res);
      ok = 0;
    }


  if (ok)
    {
      nrows = PQntuples (res);
      nfields = PQnfields (res);

      if (nrows == 0)
	{
	  A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (100);
	}


      if (singleton)
	{
	  free (n->name);
	  free (n->sql);
	  A4GL_free_associated_mem (n);
	  //free(n);
	}

      if (nrows > 1)
	{
	  A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (-284);	// A subquery has returned not exactly one row.
	  return 1;
	}

      A4GL_debug ("Copy...");
      if (nrows)
	{
	  copy_to_obind (res, n->no, n->obind, 0);
	}
      A4GL_debug ("nrows=%d nfields=%d\n", nrows, nfields);

      if (setSavepoint)
	{
	  if (CanUseSavepoints)
	    {
	      Execute ("RELEASE SAVEPOINT preExecSelect", 1);
	    }
	}

      return 0;
    }

  if (setSavepoint)
    {
      if (CanUseSavepoints)
	{
	  Execute ("ROLLBACK TO SAVEPOINT preExecSelect", 1);
	}
    }
  return 1;
}



/*
=====================================================================
                    Function prototypes
=====================================================================
*/

int A4GL_fill_array_databases (int mx, char *arr1, int szarr1, char *arr2,
			       int szarr2);
int A4GL_fill_array_tables (int mx, char *arr1, int szarr1, char *arr2,
			    int szarr2, int mode);
int A4GL_fill_array_columns (int mx, char *arr1, int szarr1, char *arr2,
			     int szarr2, int mode, char *info);


/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * Fill database array
 *
 * @param mx        maximum number of rows to fill in in arr1/arr2
 * @param arr1      address of array 1
 * @param szarr1    size of each item in array 1 (eg ARRAY[20] of char(30) : mx=20, szarr1=30)
 * @param arr2      address of array 2
 * @param szarr2    size of each item in array 2
 *
 * @return Number of rows filled
 */
int
A4GL_fill_array_databases (int mx, char *arr1, int szarr1, char *arr2,
			   int szarr2)
{
  int cnt = 0;
  int a;
  int fake_db = 0;
  int nrows;
  PGresult *res;
  char *sql =
    "SELECT d.datname , u.usename FROM pg_catalog.pg_database d LEFT JOIN pg_catalog.pg_user u ON d.datdba = u.usesysid ORDER BY 1;";
  if (A4GL_esql_db_open (-1, 0, 0, ""))
    {
      con = A4GL_esql_dbopen_connection ();
    }
  if (!con)
    {
      A4GLSQLLIB_A4GLSQL_init_connection_internal ("template1");

      if (!con)
	{
	  return 0;		// no connection
	}
      fake_db++;
    }

  res = Execute (sql, 0);
  nrows = PQntuples (res);
  if (nrows > mx)
    nrows = mx;

  for (a = 0; a < nrows; a++)
    {
      if (arr1 != 0)
	{
	  strncpy (&arr1[cnt * (szarr1 + 1)], PQgetvalue (res, a, 0), szarr1);
	  arr1[cnt * (szarr1 + 1) + szarr1] = 0;
	  A4GL_convlower (&arr1[cnt * (szarr1 + 1)]);
	  //A4GL_trim(&arr1[cnt * (szarr1 + 1)]);
	}
      cnt++;

      if (cnt >= nrows)
	break;
    }

  if (fake_db)
    {
      PQfinish (con);
      con = 0;
    }

  return cnt;

}


/**
 * Fill table array
 *
 * @param mx        maximum number of rows to fill in in arr1/arr2
 * @param arr1      address of array 1
 * @param szarr1    size of each item in array 1 (eg ARRAY[20] of char(30) : mx=20, szarr1=30)
 * @param arr2      address of array 2
 * @param szarr2    size of each item in array 2
 * @param mode      specific to service , when used by TABLES = exclude system tables
 *
 * @return Number of rows filled
 */
int
A4GL_fill_array_tables (int mx, char *arr1, int szarr1, char *arr2,
			int szarr2, int mode)
{
  //char tq[256];
  //char to[256];
  //char tn[256];
  //char tt[256];
  //char tr[256];
  int a;
  //int rc;
  int cnt = 0;
  int nrows;
  PGresult *res;
  char *sql =
    " SELECT c.relname, n.nspname FROM pg_catalog.pg_class c LEFT JOIN pg_catalog.pg_user u ON u.usesysid = c.relowner LEFT JOIN pg_catalog.pg_namespace n ON n.oid = c.relnamespace WHERE c.relkind IN ('r','v') AND n.nspname NOT IN ('pg_catalog', 'pg_toast')";

  if (A4GL_esql_db_open (-1, 0, 0, ""))
    {
      con = A4GL_esql_dbopen_connection ();
    }
  if (con == 0)
    {
      A4GL_exitwith_sql ("Not connected to database");
      return 0;
    }

  res = Execute (sql, 0);
  nrows = PQntuples (res);
  if (nrows > mx)
    nrows = mx;

  for (a = 0; a < nrows; a++)
    {
      if (arr1 != 0)
	{
	  strncpy (&arr1[a * (szarr1 + 1)], PQgetvalue (res, a, 0), szarr1);
	  arr1[a * (szarr1 + 1) + szarr1] = 0;
	  A4GL_convlower (&arr1[a * (szarr1 + 1)]);
	}
      cnt++;

      if (cnt >= nrows)
	break;
    }

  return nrows;
}


int
conv_sqldtype (int pgtype, int pglen, int *a4gl_dtype, int *a4gl_len)
{
  switch (pgtype)
    {
    case BPCHAROID:
      *a4gl_dtype = DTYPE_CHAR;
      *a4gl_len = pglen;
      break;
    case VARCHAROID:
      *a4gl_dtype = DTYPE_VCHAR;
      *a4gl_len = pglen;
      break;
    case INT4OID:
      *a4gl_dtype = DTYPE_INT;
      *a4gl_len = pglen;
      break;
    case INT2OID:
      *a4gl_dtype = DTYPE_SMINT;
      *a4gl_len = pglen;
      break;
    case FLOAT8OID:
      *a4gl_dtype = DTYPE_FLOAT;
      *a4gl_len = pglen;
      break;
    case FLOAT4OID:
      *a4gl_dtype = DTYPE_SMFLOAT;
      *a4gl_len = pglen;
      break;
    case TIMESTAMPOID:
      *a4gl_dtype = DTYPE_DTIME;
      *a4gl_len = pglen;
      break;
    case DATEOID:
      *a4gl_dtype = DTYPE_DATE;
      *a4gl_len = pglen;
      break;

#ifdef NUMERICOID
    case NUMERICOID:
	if (pglen==-1)  {
      		*a4gl_dtype = DTYPE_FLOAT;
      		*a4gl_len = pglen;
	} else { 
		// Length,scale ? 
      		*a4gl_dtype = DTYPE_FLOAT;
      		*a4gl_len = pglen;
	}
      break;
#endif
#ifdef TEXTOID
    case TEXTOID:
	if (pglen==-1)  {
      		*a4gl_dtype = DTYPE_TEXT;
      		*a4gl_len = pglen;
	} else { 
		// Length,scale ? 
      		*a4gl_dtype = DTYPE_TEXT;
      		*a4gl_len = pglen;
	}
      break;
#endif
    default:
	fprintf(stderr,"WARNING : Unrecognised postgres datatype : %d - please add to pg8.c\n", pgtype);
	// Char(20) should cover most things..
      *a4gl_dtype = DTYPE_VCHAR;
      *a4gl_len = 20;
      break;
    }
  return 1;
}


/**
 * Fill column array
 *
 * @param mx        maximum number of rows to fill in in arr1/arr2
 * @param arr1      address of array 1
 * @param szarr1    size of each item in array 1 (eg ARRAY[20] of char(30) : mx=20, szarr1=30)
 * @param arr2      address of array 2
 * @param szarr2    size of each item in array 2
 * @param mode      specific to service , when used by TABLES = exclude system tables
 * @param info      specific to service , when used by COLUMNS specifies the table name
 *
 * @return Number of rows filled
 */
int
A4GL_fill_array_columns (int mx, char *arr1, int szarr1, char *arr2,
			 int szarr2, int mode, char *info)
{
  int cnt = 0;
  char buff[2048];
  char tname[256];
  char *tabname;
  int nrows;
  int a;
  PGresult *res;
  curr_colno = 0;


  tabname = info;
  if (strchr (tabname, ':'))
    {
      strcpy (tname, strchr (tabname, ':') + 1);
      tabname = tname;
    }

  if (A4GL_esql_db_open (-1, 0, 0, ""))
    {
      con = A4GL_esql_dbopen_connection ();
    }
  if (con == 0)
    {
      A4GL_exitwith_sql ("Not connected to database");
      return 0;
    }
  A4GL_trim (tabname);

  SPRINTF1 (buff,
	    "SELECT a.attname, pg_catalog.format_type(a.atttypid, a.atttypmod), a.attnotnull, a.atthasdef, a.attnum , a.atttypid, a.atttypmod FROM pg_catalog.pg_attribute a,pg_class b WHERE a.attrelid = b.oid AND a.attnum > 0 AND NOT a.attisdropped AND b.relname='%s' ORDER BY a.attnum",
	    tabname);

  res = Execute (buff, 0);
  nrows = PQntuples (res);

  for (a = 0; a < nrows; a++)
    {
      int dtype;
      int prc;
      cnt = a;
      fixtype (PQgetvalue (res, a, 1), &dtype, &prc);

      if (arr1 != 0)
	{
	  strncpy (&arr1[cnt * (szarr1 + 1)], PQgetvalue (res, a, 0), szarr1);
	  arr1[cnt * (szarr1 + 1) + szarr1] = 0;
	  A4GL_convlower (&arr1[cnt * (szarr1 + 1)]);
	}

      if (arr2 != 0)
	{
	  switch (mode)
	    {
	    case 0:
	      SPRINTF1 (&arr2[cnt * (szarr2 + 1)], "%d",
			atoi (PQgetvalue (res, a, 7)));
	      break;

	    case 1:
	      SPRINTF1 (&arr2[cnt * (szarr2 + 1)], "%d", dtype);
	      break;

	    case 2:
	      strncpy (&arr2[cnt * (szarr2 + 1)], PQgetvalue (res, a, 1),
		       szarr2);
	      arr2[cnt * (szarr2 + 1) + szarr2] = 0;
	      break;

	    default:
	      strncpy (&arr2[cnt * (szarr2 + 1)], PQgetvalue (res, a, 0),
		       szarr2);
	      arr2[cnt * (szarr2 + 1) + szarr2] = 0;
	      A4GL_convlower (&arr2[cnt * (szarr2 + 1)]);
	      break;
	    }
	}

    }

  return nrows;
}



/**
 * Fill array - depending on service specified, invokes appropriate function
 * that does the work
 *
 * @param mx        maximum number of rows to fill in in arr1/arr2
 * @param arr1      address of array 1
 * @param szarr1    size of each item in array 1 (eg ARRAY[20] of char(30) : mx=20, szarr1=30)
 * @param arr2      address of array 2
 * @param szarr2    size of each item in array 2
 * @param service   what to fill in : DATABASES, TABLES, COLUMNS
 * @param mode      specific to service , when used by TABLES = exclude system tables
 * @param info      specific to service , when used by COLUMNS specifies the table name
 *
 * @return Number of rows filled
 */
int
A4GLSQLLIB_A4GLSQL_fill_array (int mx, char *arr1, int szarr1, char *arr2,
			       int szarr2, char *service, int mode,
			       char *info)
{
#ifdef DEBUG
  A4GL_debug ("Fill array.... mode = %d", mode);
#endif

/*

array.c:435: warning: passing arg 2 of `fill_array_databases' from incompatible pointer type
array.c:435: warning: passing arg 4 of `fill_array_databases' from incompatible pointer type
array.c:443: warning: passing arg 2 of `fill_array_tables' from incompatible pointer type
array.c:443: warning: passing arg 4 of `fill_array_tables' from incompatible pointer type
array.c:451: warning: passing arg 2 of `fill_array_columns' from incompatible pointer type
array.c:451: warning: passing arg 4 of `fill_array_columns' from incompatible pointer type

*/



  if (strcmp (service, "DATABASES") == 0)
    {
#ifdef DEBUG
      A4GL_debug ("Get Databases");
#endif
      return A4GL_fill_array_databases (mx, arr1, szarr1, arr2, szarr2);
    }

  if (strcmp (service, "TABLES") == 0)
    {
#ifdef DEBUG
      A4GL_debug ("Get Tables");
#endif
      return A4GL_fill_array_tables (mx, arr1, szarr1, arr2, szarr2, mode);
    }

  if (strcmp (service, "COLUMNS") == 0)
    {
      int rval;
#ifdef DEBUG
      A4GL_debug ("Get columns");
#endif
      rval =
	A4GL_fill_array_columns (mx, arr1, szarr1, arr2, szarr2, mode, info);
      A4GL_debug ("Got %d\n", rval);
      return rval;
    }
#ifdef DEBUG
  A4GL_debug ("****** ERROR unknown service :%s", service);
#endif
  return (0);
}

void *
A4GLSQLLIB_A4GLSQL_declare_cursor (int upd_hold, void *vsid, int scroll,
				   char *cursname)
{
  /* struct s_sid *nsid; */
  struct s_cid *cid;
  struct s_prepare *sid;
  char buff[20560];
  char *ptr;
  sid = vsid;

  if (sid == 0)
    {
      A4GL_exitwith_sql ("Can't declare cursor for non-prepared statement");
      return 0;
    }
  if (A4GL_esql_db_open (-1, 0, 0, ""))
    {
      con = A4GL_esql_dbopen_connection ();
    }

  if (!con)
    {
      // no connection..
      if (last_msg)
	free (last_msg);
      last_msg = strdup ("No connection");
      last_msg_no = -349;
      A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (-349);
      return 0;
    }

  cid = (struct s_cid *) A4GL_find_pointer_val (cursname, CURCODE);
  if (cid) {
	// already exists...
  	if (cid->mode & 0x1000) {
      		char buff[256];
      		A4GL_debug ("DEALLOCATE %s", cursname);
      		SPRINTF1 (buff, "DEALLOCATE %s", cursname);
      		PQexec (con, buff);
      		cid->mode -= 0x1000;
    		}
  	if (cid->mode & 0x7000)
    {
      char buff[256];
      SPRINTF1 (buff, "CLOSE %s", cursname);
      PQexec (con, buff);
      cid->mode -= 0x7000;
	}
	free(cid);
  }

  cid = acl_malloc2 (sizeof (struct s_cid));

  cid->statement = (void *) sid;
  cid->hstmt = 0;
  cid->mode = upd_hold + (scroll * 256);
  cid->o_ibind = 0;
  cid->o_obind = 0;
  cid->o_ni = 0;
  cid->o_no = 0;
  cid->DeclareSql = 0;

  A4GL_add_pointer (cursname, CURCODE, cid);


  if (scroll)
    {
      if (upd_hold)
	{
	  SPRINTF2 (buff, " DECLARE %s SCROLL CURSOR WITH HOLD FOR %s",
		    cursname, sid->sql);
	}
      else
	{
	  int ttype;
	  ttype = PQtransactionStatus (con);
	  if (ttype == PQTRANS_ACTIVE || ttype == PQTRANS_INTRANS)
	    {
	      SPRINTF2 (buff, " DECLARE %s SCROLL CURSOR FOR %s", cursname,
			sid->sql);
	    }
	  else
	    {
	      SPRINTF2 (buff, " DECLARE %s SCROLL CURSOR WITH HOLD FOR %s",
			cursname, sid->sql);
	    }
	}
    }
  else
    {
      if (upd_hold)
	{
	  SPRINTF2 (buff, " DECLARE %s CURSOR WITH HOLD FOR %s", cursname,
		    sid->sql);
	}
      else
	{
	  int ttype;
	  ttype = PQtransactionStatus (con);
	  if (ttype == PQTRANS_ACTIVE || ttype == PQTRANS_INTRANS)
	    {
	      SPRINTF2 (buff, " DECLARE %s CURSOR FOR %s", cursname,
			sid->sql);
	    }
	  else
	    {
	      SPRINTF2 (buff, " DECLARE %s CURSOR WITH HOLD FOR %s", cursname,
			sid->sql);
	    }
	}
    }

  ptr = strdup (sid->sql);
  A4GL_convlower (ptr);

  if (strstr (ptr, "insert into"))
    {
      cid->DeclareSql = strdup (sid->sql);
      cid->mode |= 0x100;
    }
  else
    {
      cid->DeclareSql = strdup (buff);
      if ((cid->mode & 0x100))
	{
	  cid->mode = cid->mode - 0x100;
	}
    }
  free (ptr);
  //PQexec(con, buff);
  return cid;


}

static struct s_cid * A4GLSQL_find_cursor (char *cname)
{
  struct s_cid *ptr;

  ptr = (struct s_cid *) A4GL_find_pointer_val (cname, CURCODE);
  if (ptr)
    return ptr;
  A4GL_exitwith_sql ("Cursor not found");
  return 0;
}

void
A4GLSQLLIB_A4GLSQL_flush_cursor (char *cursor)
{
  A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (0);

  strcpy (warnings, "       ");
  A4GL_copy_sqlca_sqlawarn_string8 (warnings);

}




int
A4GLSQLLIB_A4GLSQL_open_cursor (char *s, int ni, void *vibind)
{
  struct s_cid *cid;
  struct BINDING *ibind;
  //int nresultcols;
  //int copy_out_n;
  //int nrows;
  //char *ptr;
  //char *ptr2;
  char *buff2;
//struct s_prepare *nnew;
  struct s_prepare *n;

  // Here - we'll bind the inputs
  // and then execute the statement...
  ibind = vibind;
  A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (0);
  cid = (struct s_cid *) A4GLSQL_find_cursor (s);


  strcpy (warnings, "       ");
  A4GL_copy_sqlca_sqlawarn_string8 (warnings);
  if (A4GL_esql_db_open (-1, 0, 0, ""))
    {
      con = A4GL_esql_dbopen_connection ();
    }

  if (!con)
    {
      // no connection..
      if (last_msg)
	free (last_msg);
      last_msg = strdup ("No connection");
      last_msg_no = -349;
      A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (-349);
      return 0;
    }

  if (cid == 0)
    {
      A4GL_exitwith_sql ("Can't open cursor that hasn't been defined");
      return -1;
    }

  if (cid->mode & 0x100)
    {
      // Its an insert cursor - we'll just do inserts later 
      // so we can ignore this for now...
      return 1;
    }

  if (cid->mode & 0x7000)
    {
      char buff[256];
      SPRINTF1 (buff, "CLOSE %s", s);
      PQexec (con, buff);
      cid->mode -= 0x7000;
    }


  if (cid->mode & 0x1000)
    {
      char buff[256];

      SPRINTF1 (buff, "DEALLOCATE %s", s);
      PQexec (con, buff);
      cid->mode -= 0x1000;
    }


  n = (struct s_prepare *) cid->statement;

  if (ni == 0)
    {
      ni = n->ni;
      ibind = n->ibind;
    }


  //memcpy(nnew, n,sizeof(*n));
  //nnew->ni=ni;
  //nnew->ibind=vibind;
  //nnew->paramvals=malloc(sizeof(char *)*n->ni);
  //nnew->paramlen=malloc(sizeof(int)*n->ni);
  //nnew->paramform=malloc(sizeof(int)*n->ni);

  buff2 = replace_ibind (cid->DeclareSql, ni, ibind,1);
  A4GL_debug ("cid->DeclareSql=%s buff2=%s\n", cid->DeclareSql, buff2);
  cid->hstmt = PQexec (con, buff2);

  switch (PQresultStatus (cid->hstmt))
    {
    case PGRES_COMMAND_OK:
    case PGRES_TUPLES_OK:
      A4GL_debug ("Ok");
      break;

    default:
      A4GL_debug ("Bad prepare %s", PQerrorMessage (con));
      SetErrno (cid->hstmt);
      //A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (-1);
      return 0;
    }

  cid->mode |= 0x7000;
  cid->mode |= 0x1000;

  return 1;
}


static void
defaultNoticeProcessor (void *arg, const char *message)
{
  A4GL_debug ("Postgres says : %s", message);
}


/*****************************************************************************/
void
A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (int a)
{
  if (a > 0 && a != 100)
    a = 0 - a;
  A4GL_set_a4gl_status (a);	// a4gl_status = a;
  A4GL_set_a4gl_sqlca_sqlcode (a);
  A4GLSQL_set_status (a, 1);
}



/*****************************************************************************/
int
A4GLSQLLIB_A4GLSQL_fetch_cursor (char *cursor_name, int fetch_mode,
				 int fetch_when, int nobind, void *vobind)
{
  struct BINDING *obind;
  struct s_cid *cid;
  //int v_for_ptr;
  //int nresultcols;
  //int copy_out_n;
  char buff[256];
  PGresult *res;

  obind = vobind;

  cid = A4GLSQL_find_cursor (cursor_name);
  if (cid == 0)
    {
      A4GL_exitwith_sql ("Cursor not found");
      return 0;
    }

  switch (fetch_mode)
    {
    case FETCH_ABSOLUTE:
      if (fetch_when == -1)
	{
	  SPRINTF1 (buff, "FETCH LAST FROM %s", cursor_name);
	}
      else
	{
	  SPRINTF2(buff, "FETCH ABSOLUTE %d FROM %s", fetch_when, cursor_name);
	}
      break;

    case FETCH_RELATIVE:
      if (fetch_when != 1)
	{
	  SPRINTF2 (buff, "FETCH RELATIVE %d FROM %s", fetch_when, cursor_name);
	}
      else
	{
	  SPRINTF1 (buff, "FETCH %s", cursor_name);
	}
      break;
    }

  A4GL_debug ("Executing :%s\n", buff);

  res = PQexec (con, buff);
  A4GL_debug ("%s - %d \n", buff, PQresultStatus (res));

  if (cid->statement) {
	struct s_prepare *n;
		n= (struct s_prepare *) cid->statement;
		n->last_result=res;
  }

  switch (PQresultStatus (res))
    {
    case PGRES_COMMAND_OK:
    case PGRES_TUPLES_OK:
      A4GL_debug ("Good");
      break;

    default:
      A4GL_debug ("Bad %s", PQerrorMessage (con));
      SetErrno (res);
      //A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (-1);
      A4GL_exitwith_sql ("Unexpected postgres return code1\n");
      return 0;
    }


  A4GL_debug ("RES : %d\n", PQntuples (res));

  if (PQntuples (res) == 0)
    {
      A4GL_debug ("No rows found..");
      A4GL_set_a4gl_sqlca_errd (2, 0);
      A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (100);
      return 0;
    }
  else
    {

      A4GL_debug ("rows found..");
      A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (0);
      if (nobind)
	{
	  copy_to_obind (res, nobind, vobind, 0);
	}
      else
	{
	  struct s_prepare *p;
	  p = (struct s_prepare *) cid->statement;
	  copy_to_obind (res, p->no, p->obind, 0);
	}
    }
  return 1;
}


int
A4GLSQLLIB_A4GLSQL_close_cursor (char *currname)
{
  struct s_cid *ptr;
  A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (0);


  strcpy (warnings, "       ");
  A4GL_copy_sqlca_sqlawarn_string8 (warnings);

  ptr = A4GL_find_pointer_val (currname, CURCODE);

  if (ptr == 0)
    {
      A4GL_exitwith_sql ("Can't close cursor that hasn't been defined");
      return -1;
    }

  if (ptr->mode & 0x7000)
    {
      char buff[256];
      SPRINTF1 (buff, "CLOSE %s", currname);
      PQexec (con, buff);
      ptr->mode -= 0x7000;
      //A4GL_free_associated_mem (ptr->DeclareSql);
    }


  //ptr->DeclareSql = 0;
  return 1;
}


char *
pgescape_str (char *s)
{
  int err;
  static int l = 0;
  int sl;
  static char *buff = 0;
  sl = strlen (s);
  if (l < sl || l == 0 || buff == 0)
    {
      l = sl;
      buff = realloc (buff, sl * 2 + 1);
    }
#ifdef USE_ESCAPE_STRING_CONN
  // this is documented - but doesn't seem to exist!
  PQescapeStringConn (con, buff, s, sl, &err);
#else
  err = 0;
  PQescapeString (buff, s, sl);
#endif

  if (err == 0)
    return buff;		// Everything is ok...

// Some error...
  return s;
}


char *
replace_ibind (char *stmt, int ni, struct BINDING *ibind,int type)
{
  static char buff2[64000];
  char buff3[200];
  if (ni)
    {
      int a;
      int buff2cnt = 0;
	int next_param=0;
      int param;
      for (a = 0; a < strlen (stmt); a++)
	{
	int has_match;
	has_match=0;


	  if (stmt[a] == '$' && type==1)
	    {
	      int c;
	      char x[10];
	      for (c = 0; c < 10; c++)
		{
		  x[c] = stmt[a + c + 1];
		  if (x[c] < '0' || x[c] > '9')
		    {
		      break;
		    }

		}
	      x[c] = 0;
	      param = atoi (x) - 1;
	      has_match=1;
	      a += c;
	      buff2[buff2cnt] = 0;
	}

	if  (stmt[a] == '?' && type==0) {
		param=next_param++;
		has_match=1;
	      a ++;
	      buff2[buff2cnt] = 0;
		
	}

	if (has_match) {
	      char *str;


	      if (A4GL_isnull
		  (ibind[param].dtype & DTYPE_MASK, ibind[param].ptr))
		{
		  strcat (buff2, "NULL");
		}
	      else
		{

		  switch (ibind[param].dtype)
		    {
		    case DTYPE_CHAR:
		    case DTYPE_DTIME:
		    case DTYPE_INTERVAL:
		      A4GL_push_param (ibind[param].ptr, ibind[param].dtype);
		      str = A4GL_char_pop ();
		      strcat (buff2, "'");
		      A4GL_trim (str);
		      strcat (buff2, pgescape_str (str));
		      strcat (buff2, "'");
		      free (str);
		      break;

		    case DTYPE_VCHAR:
		      A4GL_push_param (ibind[param].ptr, ibind[param].dtype);
		      str = A4GL_char_pop ();
		      strcat (buff2, "'");
		      strcat (buff2, pgescape_str (str));
		      strcat (buff2, "'");
		      free (str);
		      break;

		    case DTYPE_DECIMAL:
		      A4GL_push_param (ibind[param].ptr,
				       ibind[param].dtype +
				       ENCODE_SIZE (ibind[param].size));
		      str = A4GL_char_pop ();
		      A4GL_lrtrim (str);
		      strcat (buff2, pgescape_str (str));
		      free (str);
		      break;

		    case DTYPE_SMFLOAT:
		      sprintf (buff3, "%16.8f", *(float *) ibind[param].ptr);
		      strcat (buff2, buff3);
		      break;

		    case DTYPE_FLOAT:
		      sprintf (buff3, "%16.8lf",
			       *(double *) ibind[param].ptr);
		      strcat (buff2, buff3);
		      break;

		    case DTYPE_DATE:
		      strcat (buff2, "to_date('");
		      strcat (buff2,
			      A4GL_using_date (*((long *) ibind[param].ptr),
					       "yyyy-mm-dd"));
		      strcat (buff2, "','YYYY-MM-DD')");
		      break;

		    default:
		      A4GL_push_param (ibind[param].ptr,
				       ibind[param].dtype +
				       ENCODE_SIZE (ibind[param].size));
		      str = A4GL_char_pop ();
		      A4GL_trim (str);
		      strcat (buff2, pgescape_str (str));
		      free (str);
		      break;

		    }
		}


	      buff2cnt = strlen (buff2);

	    }
	  else
	    {
	      buff2[buff2cnt++] = stmt[a];
	    }

	}
      buff2[buff2cnt++] = 0;
    }
  else
    {
      strcpy (buff2, stmt);
    }
  return buff2;
}


void
A4GLSQLLIB_A4GLSQL_commit_rollback (int mode)
{
//PGresult *res;
  if (mode == -1)
    {
      Execute ("BEGIN WORK", 1);
    }
  if (mode == 0)
    {
      Execute ("ROLLBACK WORK", 1);
    }
  if (mode == 1)
    {
      Execute ("COMMIT WORK", 1);
    }
}


PGresult *
Execute (char *s, int freeit)
{
  PGresult *res;
  A4GL_debug ("EXECUTE %s", s);
  res = PQexec (con, s);
  chk_res (res);

  if (freeit)
    {
      PQclear (res);
      return 0;
    }
  else
    {
      return res;
    }
}


static int
chk_res (PGresult * res)
{
  switch (PQresultStatus (res))
    {
    case PGRES_COMMAND_OK:
    case PGRES_TUPLES_OK:
      A4GL_debug ("Good");
      return 1;
      break;

    default:
      A4GL_debug ("Bad %s", PQerrorMessage (con));
      if (res)
	{
	  SetErrno (res);
	}
      else
	{
	  A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (-1);
	}
      return 0;
    }
}

int
inTransaction ()
{
  int ttype;
  ttype = PQtransactionStatus (con);
  if (ttype == PQTRANS_ACTIVE || ttype == PQTRANS_INTRANS)
    return 1;

  return 0;
}

void
A4GLSQLLIB_A4GLSQL_free_cursor (char *currname)
{
  struct s_cid *ptr;
  A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (0);

  strcpy (warnings, "       ");
  A4GL_copy_sqlca_sqlawarn_string8 (warnings);

  ptr = A4GL_find_pointer_val (currname, CURCODE);

  if (ptr == 0)
    {

      ptr = A4GL_find_pointer_val (currname, PRECODE);

      if (ptr == 0)
	{
	  A4GL_exitwith_sql ("Can't free cursor that hasn't been defined");
	}

      return;
    }

  if (ptr->hstmt)
    {
      //
    }




}


static void
SetErrno (PGresult * res)
{
  char *thisstate;
  int a;
  char *s;
  struct known_states
  {
    char *code;
    char *meaning;
    int compat_err;
  } states[] =
  {
    {
    "00000", "SUCCESSFUL COMPLETION", 0},
    {
    "01000", "WARNING", 0},
    {
    "0100C", "WARNING DYNAMIC RESULT SETS RETURNED", 0},
    {
    "01008", "WARNING IMPLICIT ZERO BIT PADDING", 0},
    {
    "01003", "WARNING NULL VALUE ELIMINATED IN SET FUNCTION", 0},
    {
    "01004", "WARNING STRING DATA RIGHT TRUNCATION", 0},
    {
    "02000", "NO DATA", -1},
    {
    "02001", "NO ADDITIONAL DYNAMIC RESULT SETS RETURNED", -1},
    {
    "03000", "SQL STATEMENT NOT YET COMPLETE", -1},
    {
    "08000", "CONNECTION EXCEPTION", -1},
    {
    "08003", "CONNECTION DOES NOT EXIST", -1},
    {
    "08006", "CONNECTION FAILURE", -1},
    {
    "08001", "SQLCLIENT UNABLE TO ESTABLISH SQLCONNECTION", -1},
    {
    "08004", "SQLSERVER REJECTED ESTABLISHMENT OF SQLCONNECTION", -1},
    {
    "08007", "TRANSACTION RESOLUTION UNKNOWN", -1},
    {
    "08P01", "PROTOCOL VIOLATION", -1},
    {
    "09000", "TRIGGERED ACTION EXCEPTION", -1},
    {
    "0A000", "FEATURE NOT SUPPORTED", -1},
    {
    "0B000", "INVALID TRANSACTION INITIATION", -1},
    {
    "0F000", "LOCATOR EXCEPTION", -1},
    {
    "0F001", "INVALID SPECIFICATION", -1},
    {
    "0L000", "INVALID GRANTOR", -1},
    {
    "0LP01", "INVALID GRANT OPERATION", -1},
    {
    "0P000", "INVALID ROLE SPECIFICATION", -1},
    {
    "21000", "CARDINALITY VIOLATION", -284},
    {
    "22000", "DATA EXCEPTION", -1},
    {
    "2202E", "ARRAY ELEMENT ERROR", -1},
    {
    "22021", "CHARACTER NOT IN REPERTOIRE", -1},
    {
    "22008", "DATETIME FIELD OVERFLOW", -1},
    {
    "22012", "DIVISION BY ZERO", -1},
    {
    "22005", "ERROR IN ASSIGNMENT", -1},
    {
    "2200B", "ESCAPE CHARACTER CONFLICT", -1},
    {
    "22022", "INDICATOR OVERFLOW", -1},
    {
    "22015", "INTERVAL FIELD OVERFLOW", -1},
    {
    "22018", "INVALID CHARACTER VALUE FOR CAST", -1},
    {
    "22007", "INVALID DATETIME FORMAT", -1},
    {
    "22019", "INVALID ESCAPE CHARACTER", -1},
    {
    "2200D", "INVALID ESCAPE OCTET", -1},
    {
    "22025", "INVALID ESCAPE SEQUENCE", -1},
    {
    "22010", "INVALID INDICATOR PARAMETER VALUE", -1},
    {
    "22020", "INVALID LIMIT VALUE", -1},
    {
    "22023", "INVALID PARAMETER VALUE", -1},
    {
    "2201B", "INVALID REGULAR EXPRESSION", -1},
    {
    "22009", "INVALID TIME ZONE DISPLACEMENT VALUE", -1},
    {
    "2200C", "INVALID USE OF ESCAPE CHARACTER", -1},
    {
    "2200G", "MOST SPECIFIC TYPE MISMATCH", -1},
    {
    "22004", "NULL VALUE NOT ALLOWED", -1},
    {
    "22002", "NULL VALUE NO INDICATOR PARAMETER", -1},
    {
    "22003", "NUMERIC VALUE OUT OF RANGE", -1},
    {
    "22026", "STRING DATA LENGTH MISMATCH", -1},
    {
    "22001", "STRING DATA RIGHT TRUNCATION", -1},
    {
    "22011", "SUBSTRING ERROR", -1},
    {
    "22027", "TRIM ERROR", -1},
    {
    "22024", "UNTERMINATED C STRING", -1},
    {
    "2200F", "ZERO LENGTH CHARACTER STRING", -1},
    {
    "22P01", "FLOATING POINT EXCEPTION", -1},
    {
    "22P02", "INVALID TEXT REPRESENTATION", -1},
    {
    "22P03", "INVALID BINARY REPRESENTATION", -1},
    {
    "22P04", "BAD COPY FILE FORMAT", -1},
    {
    "22P05", "UNTRANSLATABLE CHARACTER", -1},
    {
    "23000", "INTEGRITY CONSTRAINT VIOLATION", -1},
    {
    "23001", "RESTRICT VIOLATION", -1},
    {
    "23502", "NOT NULL VIOLATION", -1},
    {
    "23503", "FOREIGN KEY VIOLATION", -1},
    {
    "23505", "UNIQUE VIOLATION", -239},
    {
    "23514", "CHECK VIOLATION", -1},
    {
    "24000", "INVALID CURSOR STATE", -1},
    {
    "25000", "INVALID TRANSACTION STATE", -1},
    {
    "25001", "ACTIVE SQL TRANSACTION", -1},
    {
    "25002", "BRANCH TRANSACTION ALREADY ACTIVE", -1},
    {
    "25008", "HELD CURSOR REQUIRES SAME ISOLATION LEVEL", -1},
    {
    "25003", "INAPPROPRIATE ACCESS MODE FOR BRANCH TRANSACTION", -1},
    {
    "25004", "INAPPROPRIATE ISOLATION LEVEL FOR BRANCH TRANSACTION", -1},
    {
    "25005", "NO ACTIVE SQL TRANSACTION FOR BRANCH TRANSACTION", -1},
    {
    "25006", "READ ONLY SQL TRANSACTION", -1},
    {
    "25007", "SCHEMA AND DATA STATEMENT MIXING NOT SUPPORTED", -1},
    {
    "25P01", "NO ACTIVE SQL TRANSACTION", -1},
    {
    "25P02", "IN FAILED SQL TRANSACTION", -1},
    {
    "26000", "INVALID SQL STATEMENT NAME", -1},
    {
    "27000", "TRIGGERED DATA CHANGE VIOLATION", -1},
    {
    "28000", "INVALID AUTHORIZATION SPECIFICATION", -1},
    {
    "2B000", "DEPENDENT PRIVILEGE DESCRIPTORS STILL EXIST", -1},
    {
    "2BP01", "DEPENDENT OBJECTS STILL EXIST", -1},
    {
    "2D000", "INVALID TRANSACTION TERMINATION", -1},
    {
    "2F000", "SQL ROUTINE EXCEPTION", -1},
    {
    "2F005", "FUNCTION EXECUTED NO RETURN STATEMENT", -1},
    {
    "2F002", "MODIFYING SQL DATA NOT PERMITTED", -1},
    {
    "2F003", "PROHIBITED SQL STATEMENT ATTEMPTED", -1},
    {
    "2F004", "READING SQL DATA NOT PERMITTED", -1},
    {
    "34000", "INVALID CURSOR NAME", -1},
    {
    "38000", "EXTERNAL ROUTINE EXCEPTION", -1},
    {
    "38001", "CONTAINING SQL NOT PERMITTED", -1},
    {
    "38002", "MODIFYING SQL DATA NOT PERMITTED", -1},
    {
    "38003", "PROHIBITED SQL STATEMENT ATTEMPTED", -1},
    {
    "38004", "READING SQL DATA NOT PERMITTED", -1},
    {
    "39000", "EXTERNAL ROUTINE INVOCATION EXCEPTION", -1},
    {
    "39001", "INVALID SQLSTATE RETURNED", -1},
    {
    "39004", "NULL VALUE NOT ALLOWED", -1},
    {
    "39P01", "TRIGGER PROTOCOL VIOLATED", -1},
    {
    "39P02", "SRF PROTOCOL VIOLATED", -1},
    {
    "3D000", "INVALID CATALOG NAME", -1},
    {
    "3F000", "INVALID SCHEMA NAME", -1},
    {
    "40000", "TRANSACTION ROLLBACK", -1},
    {
    "40002", "INTEGRITY CONSTRAINT VIOLATION", -1},
    {
    "40001", "SERIALIZATION FAILURE", -1},
    {
    "40003", "STATEMENT COMPLETION UNKNOWN", -1},
    {
    "40P01", "DEADLOCK DETECTED", -1},
    {
    "42000", "SYNTAX ERROR OR ACCESS RULE VIOLATION", -201},
    {
    "42601", "SYNTAX ERROR", -201},
    {
    "42501", "INSUFFICIENT PRIVILEGE", -1},
    {
    "42846", "CANNOT COERCE", -1},
    {
    "42803", "GROUPING ERROR", -1},
    {
    "42830", "INVALID FOREIGN KEY", -1},
    {
    "42602", "INVALID NAME", -1},
    {
    "42622", "NAME TOO LONG", -1},
    {
    "42939", "RESERVED NAME", -1},
    {
    "42804", "DATATYPE MISMATCH", -1},
    {
    "42P18", "INDETERMINATE DATATYPE", -1},
    {
    "42809", "WRONG OBJECT TYPE", -1},
    {
    "42703", "UNDEFINED COLUMN", -1},
    {
    "42883", "UNDEFINED FUNCTION", -1},
    {
    "42P01", "UNDEFINED TABLE", -1},
    {
    "42P02", "UNDEFINED PARAMETER", -1},
    {
    "42704", "UNDEFINED OBJECT", -1},
    {
    "42701", "DUPLICATE COLUMN", -1},
    {
    "42P03", "DUPLICATE CURSOR", -1},
    {
    "42P04", "DUPLICATE DATABASE", -1},
    {
    "42723", "DUPLICATE FUNCTION", -1},
    {
    "42P05", "DUPLICATE PSTATEMENT", -1},
    {
    "42P06", "DUPLICATE SCHEMA", -1},
    {
    "42P07", "DUPLICATE TABLE", -1},
    {
    "42712", "DUPLICATE ALIAS", -1},
    {
    "42710", "DUPLICATE OBJECT", -1},
    {
    "42702", "AMBIGUOUS COLUMN", -1},
    {
    "42725", "AMBIGUOUS FUNCTION", -1},
    {
    "42P08", "AMBIGUOUS PARAMETER", -1},
    {
    "42P09", "AMBIGUOUS ALIAS", -1},
    {
    "42P10", "INVALID COLUMN REFERENCE", -1},
    {
    "42611", "INVALID COLUMN DEFINITION", -1},
    {
    "42P11", "INVALID CURSOR DEFINITION", -1},
    {
    "42P12", "INVALID DATABASE DEFINITION", -1},
    {
    "42P13", "INVALID FUNCTION DEFINITION", -1},
    {
    "42P14", "INVALID PSTATEMENT DEFINITION", -1},
    {
    "42P15", "INVALID SCHEMA DEFINITION", -1},
    {
    "42P16", "INVALID TABLE DEFINITION", -1},
    {
    "42P17", "INVALID OBJECT DEFINITION", -1},
    {
    "44000", "WITH CHECK OPTION VIOLATION", -1},
    {
    "53000", "INSUFFICIENT RESOURCES", -1},
    {
    "53100", "DISK FULL", -1},
    {
    "53200", "OUT OF MEMORY", -1},
    {
    "53300", "TOO MANY CONNECTIONS", -1},
    {
    "54000", "PROGRAM LIMIT EXCEEDED", -1},
    {
    "54001", "STATEMENT TOO COMPLEX", -1},
    {
    "54011", "TOO MANY COLUMNS", -1},
    {
    "54023", "TOO MANY ARGUMENTS", -1},
    {
    "55000", "OBJECT NOT IN PREREQUISITE STATE", -1},
    {
    "55006", "OBJECT IN USE", -1},
    {
    "55P02", "CANT CHANGE RUNTIME PARAM", -1},
    {
    "57000", "OPERATOR INTERVENTION", -1},
    {
    "57014", "QUERY CANCELED", -1},
    {
    "57P01", "ADMIN SHUTDOWN", -1},
    {
    "57P02", "CRASH SHUTDOWN", -1},
    {
    "57P03", "CANNOT CONNECT NOW", -1},
    {
    "58030", "IO ERROR", -1},
    {
    "58P01", "UNDEFINED FILE", -1},
    {
    "58P02", "DUPLICATE FILE", -1},
    {
    "F0000", "CONFIG FILE ERROR", -1},
    {
    "F0001", "LOCK FILE EXISTS", -1},
    {
    "XX000", "INTERNAL ERROR", -1},
    {
    "XX001", "DATA CORRUPTED", -1},
    {
    "XX002", "INDEX CORRUPTED", -1},
    {
    0, 0, 0}
  };

  A4GL_debug ("In SetErrno - res=%p", res);

  if (res == 0)
    {
      if (last_msg)
	free (last_msg);
      last_msg = strdup ("");
      last_msg_no = 0;
      return;
    }

  thisstate = PQresultErrorField (res, PG_DIAG_SQLSTATE);
  A4GL_debug ("This state=%s\n", thisstate);

  if (thisstate == 0)
    {
      if (last_msg)
	free (last_msg);
      last_msg = strdup ("");
      last_msg_no = 0;
      return;
    }


  A4GL_debug ("Postgres says : %s %s", thisstate,
	      PQresultErrorField (res, PG_DIAG_MESSAGE_PRIMARY));
  A4GL_debug ("And Postgres says : %s",
	      PQresultErrorField (res, PG_DIAG_MESSAGE_DETAIL));
  A4GL_debug ("And Postgres also says : %s",
	      PQresultErrorField (res, PG_DIAG_MESSAGE_HINT));

  if (A4GL_strstartswith (thisstate, "01"))
    {
      warnings[0] = 'W';
      A4GL_copy_sqlca_sqlawarn_string8 (warnings);
    }


  if (last_msg)
    free (last_msg);
  s = PQresultErrorField (res, PG_DIAG_MESSAGE_PRIMARY);

  A4GL_set_a4gl_sqlca_errd (4, 0);
  if (res)
    {
      char *r;
      r = PQresultErrorField (res, PG_DIAG_STATEMENT_POSITION);
      if (r)
	{
	  A4GL_set_a4gl_sqlca_errd (4, atoi (r));
	}
    }

  if (s)
    {
      last_msg = strdup (PQresultErrorField (res, PG_DIAG_MESSAGE_PRIMARY));
    }
  else
    {
      last_msg = strdup ("");
    }


  for (a = 0; states[a].code; a++)
    {
      if (strcmp (thisstate, states[a].code) == 0)
	{
	  A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (states[a].compat_err);
	  last_msg_no = states[a].compat_err;
	  break;
	}
    }
}



long
A4GL_describecolumn (PGresult * res, int colno, int type)
{
  int dtype;
  int prc;
  int column_count;
  int rval=0;


  if (type == 6)
    return atoi (PQcmdTuples (res));

  if (type == 5)
    return PQnfields (res);


  column_count = PQnfields (res);

  if (colno > column_count)
    {
      A4GL_exitwith_sql ("Column out of range");
      return 0;
    }


  switch (type)
    {
    case 0:
      conv_sqldtype (PQftype (res, colno), PQfsize (res, colno), &dtype,
		     &prc);
      rval = dtype;
      break;

    case 1:
      rval = (long) PQfname (res, colno);
      break;

    case 2:
      rval = PQfmod (res, colno);
      break;

    case 3:
      rval = PQfsize (res, colno);
      break;

    case 4:
      rval = 1;
      break;			// Nullable ?
    }

  return rval;
}

/*****************************************************************************/

long
A4GLSQLLIB_A4GLSQL_describe_stmt (char *stmt, int colno, int type)
{
  struct s_sid *sid;
  struct s_cid *cid;
	struct s_prepare *n=0;
  PGresult *res;
  int z;
  sid = A4GLSQL_find_prepare (stmt);
  if (sid == 0)
    {
	A4GL_debug("Not found as a prepare - look for a cursor...");
      cid = A4GLSQL_find_cursor (stmt);
      if (cid == 0)
	{
	  A4GL_exitwith_sql ("Could not find statement or cursor specified");
	  return 0;

	}
      res = cid->hstmt;
	n=(struct s_prepare *)cid->statement;
	if (n) {
		if (n->last_result) {
				res=n->last_result;
		}
	}

    }
  else
    {
      res = sid->hstmt;
	n=(struct s_prepare *)sid ;
	if (n->last_result) {
		res=n->last_result;
	}
    }

  if (sid == 0 && cid == 0)
    {
      A4GL_exitwith_sql ("Statement could not be found");
    }

  if (res == 0) {
	A4GL_debug("No result");
    return 0;
   }
  
  z = A4GL_describecolumn (res, colno-1, type);

  return z;
}

void
A4GLSQLLIB_A4GLSQL_put_insert (void *vibind, int n)
{
  struct BINDING *ibind = 0;
  char *cursorName;
  struct s_cid *cid;
  struct s_prepare *sid;
  int ni = 0;
  char *newstr;
  ibind = vibind;

  A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (0);

  strcpy (warnings, "       ");
  A4GL_copy_sqlca_sqlawarn_string8 (warnings);

  cursorName = A4GL_char_pop ();
  cid = A4GLSQL_find_cursor (cursorName);
  free (cursorName);
  if (cid == 0)
    return;

  if (n)
    {
      ibind = vibind;
      ni = n;
    }
  else
    {
      ni = cid->statement->ni;
      ibind = cid->statement->ibind;
    }


  sid = (struct s_prepare *) cid->statement;
  if (ni == 0)
    {
      ni = sid->ni;
      ibind = sid->ibind;
    }

  newstr = replace_ibind (sid->sql, ni, ibind,1);

  Execute (newstr, 1);		// we may need to add our errd[2] serial number checking here too...

}



/* =============================== EOF ============================== */

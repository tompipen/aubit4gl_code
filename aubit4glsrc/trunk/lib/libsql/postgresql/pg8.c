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
# $Id: pg8.c,v 1.122 2013-11-10 09:28:21 mikeaubury Exp $
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
#include <sys/stat.h>

#include "a4gl_expr.h"
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
static void fixtype (char *ptr, int *d, int *s,char *defaultval);
char *A4GL_global_A4GLSQL_get_sqlerrm (void);

static char currentConName[200]="default";
PGconn *current_con=NULL;



static void defaultNoticeProcessor (void *arg, const char *message);
static void SetErrno (PGresult * res);
static int loaded=0;
//char *A4GL_getTimecode (void);

/*
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
*/


int dtype_bpcharoid=-1;
int dtype_varcharoid=-1;
int dtype_int4oid=-1;
int dtype_int2oid=-1;
int dtype_int8oid=-1;
int dtype_float8oid=-1;
int dtype_float4oid=-1;
int dtype_timestampoid=-1;
int dtype_dateoid=-1;
int dtype_numericoid=-1;
int dtype_textoid=-1;



#define BPCHAROID       dtype_bpcharoid
#define VARCHAROID      dtype_varcharoid
#define INT4OID         dtype_int4oid
#define INT2OID         dtype_int2oid
#define INT8OID         dtype_int8oid
#define FLOAT8OID 	dtype_float8oid
#define FLOAT4OID 	dtype_float4oid
#define TIMESTAMPOID  	dtype_timestampoid
#define DATEOID         dtype_dateoid
#define NUMERICOID      dtype_numericoid
#define TEXTOID         dtype_textoid



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

struct s_typelist {
	int type;
	char typename[65];
};

struct s_typelist *types=0;

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


static int charcpy (unsigned char *target, unsigned char *source, long len,char delim);
static void ensure_types(void) ;
static void clr_types(void) ;
PGresult *resGC = 0;
char *pghost = "";
char *pgport = NULL;
char *pgoptions = NULL;
char *pgtty = NULL;
static struct expr_str_list *A4GL_add_validation_elements_to_expr (struct
								   expr_str_list
								   *ptr,
								   char *val);


PGresult *Execute (char *s, int freeit);
static char *replace_ibind (char *stmt, int ni, struct BINDING *ibind,int type);
static int inTransaction (void);
static int copy_to_obind (PGresult * res, int no, struct BINDING *obind, int row);
static int chk_res (PGresult * res);

struct s_pgextra
{
  void **data_area_in;
  void **data_area_out;
  char **paramvals;
  int *paramlen;
  int *paramform;
  int reallyprepared;
  PGresult *last_result;
};

#define SQFILENAME "sqexplain.out"

#define SET_EXPLAIN_FINISHED set_explain("**FINISHED**")

static char *set_explain(char *s) {
static int set_explain_mode=-1;
static int executing=0;
static int then=0;
int setSavepoint=0;

if (set_explain_mode==-1) {
	if (A4GL_isyes(acl_getenv("PG8EXPLAIN"))) { //@env PG8EXPLAIN, automatically 'SET EXPLAIN ON'
		set_explain_mode=1;
	} else {
		set_explain_mode=0;
	}
}


if (strcmp(s,"SET EXPLAIN ON")==0) { set_explain_mode=1; return "select 1";}
if (strcmp(s,"SET EXPLAIN OFF")==0) { set_explain_mode=0; return "select 1";}

if (strcmp(s,"**FINISHED**")==0) {
	if (executing) {
		executing=0;
                FILE *f;
                f=fopen(SQFILENAME,"a");
                if (f) {
			fprintf(f,"\n\nQUERY COMPLETE\n");
			if (then) {
				then=time(NULL)-then;
				fprintf(f,"Timecode: %s (~%ds)\n\n\n",A4GL_getTimecode(),then);
			} else {
				fprintf(f,"Timecode: %s\n\n\n",A4GL_getTimecode());
			}
			fclose(f);
		}
	}
	then=0;
	return NULL;
}

if (set_explain_mode) {
	char buff[65000];
	PGresult *res;
	ExecStatusType rstat;
	then=time(NULL);
	sprintf(buff,"EXPLAIN %s",s);
	res=PQexec(current_con,buff);
	rstat=PQresultStatus(res);
	
	
  	if (inTransaction ())
    	{
      		setSavepoint++;
      		if (CanUseSavepoints) { Execute ("SAVEPOINT preExplain", 1); }
    	}


	if (rstat==PGRES_TUPLES_OK) {
		int ntuples;
		int nfields;
		int field;
		int tuple;
		ntuples=PQntuples (res);
		nfields=PQnfields (res);
		if (ntuples && nfields) {
			FILE *f;
			f=fopen(SQFILENAME,"a");

			if (f) {
				executing=1;

				fprintf(f,"\n\n--------------------------------------------------------------------------------\n");
				fprintf(f,"Timecode: %s\n",A4GL_getTimecode());
				fprintf(f,"QUERY:\n");
				fprintf(f,"------\n");
				fprintf(f,"%s\n",s);

				for (tuple=0;tuple<ntuples;tuple++) {
					for (field=0;field<nfields;field++) {
						if (field) fprintf(f," ");
						fprintf(f,"%s",PQgetvalue (res, tuple, field));
					}
					fprintf(f,"\n");
				}
				fclose(f);
			} else {
				A4GL_exitwith("Unable to open sqexplain.out file");
			}
		}
	} else {
		if (rstat==PGRES_FATAL_ERROR) {
			FILE *f;
			f=fopen(SQFILENAME,"a");

			if (f) {
				executing=1;
				fprintf(f,"\n\n--------------------------------------------------------------------------------\n");
				fprintf(f,"Timecode: %s\n",A4GL_getTimecode());
				fprintf(f,"QUERY:\n");
				fprintf(f,"------\n");
				fprintf(f,"%s\n",s);
				fprintf(f,"  ERROR IN SQL %s - %s\n", PQresStatus(rstat), PQresultErrorMessage(res));
				fclose(f);
			}

		} else {
			// Not an EXPLAINable statement ....
			// In my tests - this happened with an 'ANALYZE' command..
		}
	}


      if (setSavepoint)
	{
	  if (CanUseSavepoints)
	    {
	      Execute ("ROLLBACK TO SAVEPOINT preExplain", 1);
	    }
	}
}
return s;
}


static PGconn *local_PQsetdbLogin(const char *pghost, const char *pgport,
                         const char *pgoptions, const char *pgtty,
                         const char *inDbName,
                         const char *login, const char *pwd) {

char tmpDb[2000];
const char *dbName;

dbName=inDbName;

if (pgport) { if (strlen(pgport)==0) { pgport=NULL; } }
if (pghost) { if (strlen(pghost)==0) { pghost=NULL; } }

      if (strlen (dbName) )
	{
	  strcpy (tmpDb, (char *)dbName);
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


A4GL_debug("Connecting %s %s %s %s %s %s %s", pghost, pgport,pgoptions,pgtty, dbName,login,pwd);

return PQsetdbLogin( pghost, pgport,pgoptions,pgtty, dbName,login,pwd);

}



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
      PGresult *res = 0;
char versionBuff[200];
char *ptr;

  //int i;

  clr_types();
  A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (0);

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



    if (A4GL_sqlid_from_aclfile (dbName, uname_acl, passwd_acl,NULL))
    {
	/* 
         * Here we only want to overwrite the Username and password
 	 * if its explicitly set in the environment 
 	 **/
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
	/* Here - we've not found any ACLFILE - so we can look using the normal rules
 	 * in either the environment or aubitrc files
 	 */
        u = acl_getenv ("A4GL_SQLUID");
        p = acl_getenv ("A4GL_SQLPWD");
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

  A4GL_set_connection_username(u);

  current_con = local_PQsetdbLogin (pghost, pgport, pgoptions, pgtty, dbName, u,p);
  if (current_con == NULL)
    {

      A4GL_set_errm (dbName);
      A4GL_exitwith_sql ("Could not connect to database");
      return -1;
    }

  if (PQstatus (current_con) == CONNECTION_BAD)
    {
      if (PQerrorMessage (current_con)) {
	SPRINTF2 (buff2, "%s - %s", PQerrorMessage (current_con), dbName);
      A4GL_set_errm (buff2);
      A4GL_exitwith_sql_detail ("Could not connect to database",PQerrorMessage(current_con));
	}
      else {
	SPRINTF1 (buff2, "%s - No explanation from the backend", dbName);
      A4GL_set_errm (buff2);
      A4GL_exitwith_sql ("Could not connect to database ");
	}

      return -1;

    }
  PQsetNoticeProcessor (current_con, defaultNoticeProcessor, 0);


  currServerVersion=0;

#ifndef  PG_VERSION_NUM
// PG_VERSION_NUM doesn't seem to be set on earlier version...
// so lets turn off some stuff that needs a later version..
	A4GL_setenv("PG8USEINSERTRETURN","N",1);
	A4GL_setenv("DISABLESAVEPOINTS","Y",1);
#endif

  CanUseSavepoints = 0;
  if (current_con)
    {


#if  ( PG_VERSION_NUM > 80100 )
        currServerVersion = PQserverVersion (current_con);
	
      if (currServerVersion >= 80100)
	{
	
	  if (!A4GL_isyes (acl_getenv ("DISABLESAVEPOINTS")))
	    {
	      CanUseSavepoints = 1;
	    }
	}
#else
	{
      PGresult *res2 = 0;
	//char *ptr;
      // work it out by trying it..
      res2 = PQexec (current_con, "BEGIN WORK");
      PQclear (res2);

      res = PQexec (current_con, "SAVEPOINT pr1");
      res2 = PQexec (current_con, "COMMIT WORK");
      PQclear (res2);

      if (PQresultStatus (res) == PGRES_COMMAND_OK)
	{
	  if (!A4GL_isyes (acl_getenv ("DISABLESAVEPOINTS")))
	    {
	      CanUseSavepoints = 1;
	    }
	}

      	PQclear (res);



	}
#endif
    }

	res=PQexec(current_con, "SELECT version()");
	ptr=PQgetvalue (res, 0, 0);
	if (strstr(ptr,"7.4informix1.8")) {
  			A4GL_setenv("A4GL_PATCHEDPG","Y",1);
  			A4GL_setenv("A4GL_PGVERSION","70408",1);
	} else {
		ptr=strchr(ptr,' ');
		if (ptr) {
			char buff2[200];
			int maj,min,rev;
			int a;
			//int b=0;
  			SPRINTF1(buff2,"%s",ptr+1);
			ptr=strchr(buff2,' ');
			if (ptr) {*ptr=0; }
			a=sscanf(buff2,"%d.%d.%d",&maj,&min,&rev);
			if (a==3) {
				SPRINTF3(versionBuff,"%d%02d%02d",maj,min,rev);
  				A4GL_setenv("A4GL_PGVERSION",versionBuff,1);
				if (currServerVersion==0) {
					currServerVersion=atol(versionBuff);
				}
			}
		}
        	PQclear (res);
	}

  if (!loaded) {
	loaded++;
	A4GLSQLCV_load_convert("INFORMIX","POSTGRES8");
  }

  strcpy(currentConName, "default");
  A4GL_add_pointer ("default", SESSCODE, current_con);
  return 0;
}

/**
 *  * Init a new connection to the database and associate with an explicit
 *   * session name.
 *    *
 *     * If the user identification was not set gets the values fromthe environment.
 *      *
 *       * @param sessname The name to be tied to the session. This is the name of
 *        *   the connection
 *         * @param dsn The database name.
 *          * @param usr The user name to establish the connection.
 *           * @param pwd The password of the user to set the connection.
 *            */
int
A4GLSQLLIB_A4GLSQL_init_session_internal (char *sessname, char *dsn, char *usr, char *pwd)
{
char *u;
char *p;
    char uname_acl[256];
    char passwd_acl[256];
  A4GL_debug("sessname=%s dsn=%s usr=%s pwd=%s", sessname,dsn,usr,pwd);

  clr_types();

  A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (0);

    if (A4GL_sqlid_from_aclfile (dsn, uname_acl, passwd_acl,NULL))
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

  if (usr && strlen(usr)) { u=usr; }
  if (pwd && strlen(pwd)) { p=pwd; }


  current_con = local_PQsetdbLogin (pghost, pgport, pgoptions, pgtty, dsn, u,p);

  if (current_con == NULL)
    {

      A4GL_set_errm (dsn);
      A4GL_exitwith_sql ("Could not connect to database");
      return 1;
    }
  A4GL_set_connection_username(u);

  strcpy(currentConName, sessname);
  A4GL_add_pointer (sessname, SESSCODE, current_con);

  if (!loaded) {
	loaded++;
	A4GLSQLCV_load_convert("INFORMIX","POSTGRES8");
  }

return 0; /* OK */
}


char *
A4GLSQLLIB_A4GLSQL_get_curr_conn (void)
{
A4GL_debug("currentConName=%s",currentConName);
  return currentConName ;
}

int A4GLSQLLIB_A4GLSQL_set_conn_internal (char *sessname) {
  PGconn *con=0;
  A4GL_debug("Set conn %s", sessname);
  con = (PGconn *) A4GL_find_pointer (sessname, SESSCODE);

  if (con) {	
	current_con=con;
  	strcpy(currentConName, sessname);
	A4GL_debug("Found it - used it..");
	return 0;
  }
A4GL_debug("Not found");
return 1;
}


int
A4GLSQLLIB_A4GLSQL_close_session_internal (char *sessname)
{
  PGconn *con=0;
A4GL_debug("Close session %s", sessname);
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
  char schemaname[2000]="";
  char search_path[2000]="";
  int rval;
  curr_colno = 0;

  if (strchr (tabname, ':'))
    {
      strcpy (tname, strchr (tabname, ':') + 1);
      tabname = tname;
    }



  if (A4GL_esql_db_open (-1, 0, 0, ""))
    {
      current_con = A4GL_esql_dbopen_connection ();
    }

  if (current_con == 0)
    {
      A4GL_exitwith_sql ("Not connected to database");
      return 0;
    }

	// are they specifying a 'schema' ?
  if (strchr (tabname, '.'))
    {
	char *ptr;
	PGresult *res;
	strcpy(schemaname,tabname);
	// extract the schema name and add it to the search path
	// Its not exact - but it will do for now.. 
	ptr=strchr(schemaname,'.');
	if (ptr) {
		*ptr=0;
	}
	
	res=PQexec(current_con, "show search_path");
	strcpy(search_path,PQgetvalue(res,0,0));
	PQclear(res);
      	strcpy (tname, strchr (tabname, '.') + 1);
      	tabname = tname;
	SPRINTF2(buff,"set search_path TO %s, %s", schemaname, search_path);
	//printf ("Executin : %s\n", buff);
	res=PQexec(current_con, buff);
	//printf("tabname=%s\n",tabname);
	PQclear(res);
    }

// This is nicked from psql ...
  SPRINTF1 (buff,
	    "SELECT a.attname, pg_catalog.format_type(a.atttypid, a.atttypmod), a.attnotnull, a.atthasdef, a.attnum, (SELECT substring(pg_catalog.pg_get_expr(d.adbin, d.adrelid) for 128) FROM pg_catalog.pg_attrdef d WHERE d.adrelid = a.attrelid AND d.adnum = a.attnum AND a.atthasdef) FROM pg_catalog.pg_attribute a,pg_class b WHERE a.attrelid = b.oid and pg_table_is_visible(b.oid) AND a.attnum > 0 AND NOT a.attisdropped AND b.relname='%s' ORDER BY a.attnum",
	    tabname);

  resGC = PQexec (current_con, buff);


  rval=-1;
  switch (PQresultStatus (resGC))
    {
    case PGRES_COMMAND_OK:
    case PGRES_TUPLES_OK:
      nfieldsForGetColumns = PQntuples (resGC);
      A4GL_debug ("Returns %d fields", nfieldsForGetColumns);
      if (nfieldsForGetColumns) {
			rval=1; break;
		}

    case PGRES_EMPTY_QUERY:
    case PGRES_COPY_OUT:
    case PGRES_COPY_IN:
    case PGRES_BAD_RESPONSE:
    case PGRES_NONFATAL_ERROR:
    case PGRES_FATAL_ERROR:
      A4GL_set_errm (tabname);
      A4GL_exitwith_sql ("Unexpected postgres return code1\n");
      rval=0; break;
    }

	if (strlen(search_path)) {
		PGresult *res;
		SPRINTF1(buff,"set search_path TO %s", search_path);
		res=PQexec(current_con, buff);
		PQclear(res);
	}

	if (rval==-1) {
  		A4GL_set_errm (tabname);
  		A4GL_exitwith_sql ("Table not found\n");
  		return 0;
  	}

  return rval;
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
      current_con = A4GL_esql_dbopen_connection ();
    }
  if (current_con == 0)
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
  fixtype (colptr, dtype, size,  PQgetvalue (resGC, curr_colno, 5));


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

static void ensure_dot_format_for_decimal_string(char *s) {
if (strchr(s,',') && !strchr(s,'.')) {
        char buff[200];
        int a;
        strcpy(buff,s);
        for (a=0;a<strlen(s);a++) {
                if (s[a]==',') buff[a]='.';
                if (s[a]=='.') buff[a]=',';
        }
        strcpy(s,buff);
        return;
}

}


static void
fixtype (char *type, int *d, int *s,char *defaultval)
{
FILE *errd;
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
  if (A4GL_strstartswith (type, "timestamp without time zone")) { *d = DTYPE_DTIME; *s = 24; return; }
  if (A4GL_strstartswith (type, "timestamp(0) without time zone")) { *d = DTYPE_DTIME; *s = 22; return; }
  if (A4GL_strstartswith (type, "timestamp(1) without time zone")) { *d = DTYPE_DTIME; *s = 23; return; }
  if (A4GL_strstartswith (type, "timestamp(2) without time zone")) { *d = DTYPE_DTIME; *s = 24; return; }
  if (A4GL_strstartswith (type, "timestamp(3) without time zone")) { *d = DTYPE_DTIME; *s = 25; return; }
  if (A4GL_strstartswith (type, "timestamp(4) without time zone")) { *d = DTYPE_DTIME; *s = 26; return; }
  if (A4GL_strstartswith (type, "timestamp(5) without time zone")) { *d = DTYPE_DTIME; *s = 27; return; }
  if (A4GL_strstartswith (buff, "timestamp")) { *d = DTYPE_DTIME; *s = 24; return; }

  if (A4GL_strstartswith (type, "time without time zone")) { *d = DTYPE_DTIME; *s = 72; return; }
  if (A4GL_strstartswith (type, "time(0) without time zone")) { *d = DTYPE_DTIME; *s = 70; return; }
  if (A4GL_strstartswith (type, "time(1) without time zone")) { *d = DTYPE_DTIME; *s = 71; return; }
  if (A4GL_strstartswith (type, "time(2) without time zone")) { *d = DTYPE_DTIME; *s = 72; return; }
  if (A4GL_strstartswith (type, "time(3) without time zone")) { *d = DTYPE_DTIME; *s = 73; return; }
  if (A4GL_strstartswith (type, "time(4) without time zone")) { *d = DTYPE_DTIME; *s = 74; return; }
  if (A4GL_strstartswith (type, "time(5) without time zone")) { *d = DTYPE_DTIME; *s = 75; return; }
  if (A4GL_strstartswith (buff, "time")) { *d = DTYPE_DTIME; *s = 72; return; }


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
          if (A4GLSQLCV_check_requirement("PG_UNLIMITED_VARCHAR_AS_TEXT"))
            {
              *d = DTYPE_TEXT;
              *s = 0x0;
            }
          else
            {
             *s = 255;
            }
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
	if (strstr(defaultval,"nextval")) { // A serial is normally a integer nextval('...'::text)
      		*d = DTYPE_SERIAL;
	} else {
      		*d = DTYPE_INT;
	}
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
	if (strlen(l1)==0) {
		// assume 16,2
		*s=0x1002;
	} else {
      		*s = ((atoi (l1) << 8) + atoi (l2));
	}
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

  if (strcmp (buff, "text") == 0)
    {
      *d = DTYPE_TEXT;
      *s = 0x0; //000e;
    }

  if (strcmp (buff, "boolean") == 0)
    {
      *d = DTYPE_SMINT;
      *s = 0x0; //000e;
    }


  if (*d == -1)
    {
      *d = DTYPE_VCHAR;
      *s = 0xff;


      A4GL_debug ("Ooops - Unknown datatype : %s", type);
      errd=fopen("/tmp/errdtypes.out","a");
      if (errd) {
		FPRINTF(errd,"%s\n", type);
		fclose(errd);
      }
     chmod("/tmp/errdtypes.out",0666);
      

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
  res2 = PQexec (current_con, buff);

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
static char buff[2000];
char *cptr;
PGresult *res2;
int nrows=-1;

cptr=acl_getenv("A4GL_SYSCOL_VAL");

if (cptr==0) return 0;
if (strlen(cptr)==0) return 0;
if (strcmp(cptr,"NONE")==0) return 0;

   SPRINTF4(buff,"select attrval from %s where attrname='%s' and tabname='%s' and colname='%s'", cptr ,typ,tabname,colname);

   res2 = PQexec (current_con, buff);

  switch (PQresultStatus (res2))
    {
    case PGRES_COMMAND_OK:
    case PGRES_TUPLES_OK:
      nrows = PQntuples (res2);
      break;
	default: break;
    }

if (nrows<1) return 0;

strcpy(buff,"");

if (!PQgetisnull(res2,0,0)) {
	strcpy(buff, PQgetvalue (res2, 0, 0));
	A4GL_trim(buff);
}

return buff;
}



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
A4GLSQLLIB_A4GLSQL_unload_data_internal (char *fname_o, char *delims, void* filterFunc,
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
      current_con = A4GL_esql_dbopen_connection ();
    }

  if (current_con == 0)
    {
      A4GL_exitwith_sql ("Database not open");
      return;
    }


  ibind = vibind;

  A4GL_debug ("Unload data..");

  if (nbind)
    {
	sqlStr= replace_ibind (sqlStr_o, nbind, ibind,0);
	sqlStr=strdup(sqlStr);
    } else {
  	sqlStr = strdup (sqlStr_o);
  	A4GL_trim (sqlStr);
    }


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



  res2 = PQexec (current_con, set_explain(sqlStr));
	SET_EXPLAIN_FINISHED;

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
		  PQerrorMessage (current_con));
      SetErrno (res2);
		A4GL_set_sqlerrmessage( PQerrorMessage (current_con));
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
		char dtype;
		dtype=PQftype(res2, b);

	        ptr = PQgetvalue (res2, a, b);

		if (PQftype(res2, b) == dtype_dateoid && A4GLSQLCV_check_requirement("UNLDATEASDBDATE")) {
	    			static char buff[2000];
				int m, d, y;
				int dt;
	    			strcpy (buff, ptr);
	    			if (buff[4] == '-' && buff[7] == '-')
	      			{
		
					buff[4] = 0;
					buff[7] = 0;
					y = atoi (buff);
					m = atoi (&buff[5]);
					d = atoi (&buff[8]);
					dt = A4GL_gen_dateno (d, m, y);
	      			}
	    			else
	      			{
					A4GL_push_char (ptr);
					A4GL_pop_param (&dt,DTYPE_DATE,sizeof(dt));
	      			}
				
				A4GL_push_date(dt);
				// Fiddle about to get it back to an aubit date...
				ptr=A4GL_char_pop();
				strcpy(buff,ptr);
				free(ptr); // It was malloc'd - we dont want to waste memory
				ptr=buff;
		}

		if (dtype==dtype_varcharoid || dtype==dtype_textoid) ; 
		else { A4GL_trim (ptr);} // Standard CHAR..
	      nsl = strlen (ptr);
	      if (nsl >= sl)
		{
		  sl = nsl;
		  s = realloc (s, sl*2 + 2);
		}



	      charcpy ((unsigned char *)s, (unsigned char *)ptr,nsl,delims[0]);
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
	A4GL_set_a4gl_sqlca_errd(2,nrows);
 //sqlca.sqlerrd[1] = nrows;


  return;			/* return 0; */
}


#ifdef NDEF
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
#endif



void * A4GLSQLLIB_A4GLSQL_prepare_select_internal (void *ibind, int ni, void *obind, int no, char *s, char *uniqid,int singleton)
{
  struct s_pgextra *pg_extra;
  int l;
  int b;
  char buff[20000];
  int a;
  int ccnt = 1;
  struct s_sid *n;
  int instr=0;
  // we dont do much here - so lets clear the sqlca.sqlcode down...
  A4GL_set_a4gl_sqlca_sqlcode (0); 

  if (A4GL_esql_db_open (-1, 0, 0, ""))
    {
      current_con = A4GL_esql_dbopen_connection ();
    }

  if (A4GL_strstartswith(s,"DATABASE ")) {
	// DATABASE dbname ...
  } else {

  	if (!current_con)
    	{
      		// no connection..
      		if (last_msg)
			free (last_msg);
      		last_msg = strdup ("No connection");
      		last_msg_no = -349;
      		A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (-349);
      		return 0;
    	}
  }

  n = malloc (sizeof (struct s_sid));

  pg_extra = A4GL_alloc_associated_mem (n, sizeof (struct s_pgextra));
  n->extra_info=pg_extra;
  n->inputDescriptorName=0;
  n->outputDescriptorName=0;
  n->ni = ni;
  n->no = no;
  n->ibind = ibind;
  n->obind = obind;

  pg_extra->last_result=0;


  l = strlen (s);
  b = 0;
  instr=0;


  for (a = 0; a < l; a++)
    {
      char c[20];
	int escp=0;
	int isPlaceholder=0;
	
	if (a ) {
		if (s[a-1]=='\\') {
			escp=1;
		}
	}

	if (s[a]=='"' && (instr==0 || instr==1) && !escp) {
		if ( instr==1) {
			instr=0;
		}  else {
			instr=1;
		}
	}

	if (s[a]=='\'' && (instr==0 || instr==2) && !escp) {
		if ( instr==2) {
			instr=0;
		}  else {
			instr=2;
		}
	}


      if (s[a] == '?' && instr==0 && !escp) {
		isPlaceholder=1;
	}

      if (isPlaceholder)
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
  n->select = strdup (buff);
	A4GL_set_associated_mem(n,n->select);
  strcpy(n->statementName ,uniqid);
  pg_extra->reallyprepared = 0;

  pg_extra->data_area_in = 0;
  pg_extra->data_area_out = 0;

  if (ni)
    {
      pg_extra->data_area_in = A4GL_alloc_associated_mem (n, sizeof (void *) * ni);
    }
  if (no)
    {
      pg_extra->data_area_out = A4GL_alloc_associated_mem (n, sizeof (void *) * no);
    }

  A4GL_debug("uniqid=%s", uniqid);
  


  // Might have prepared it before - so get rid...

  A4GL_debug ("-->%s\n", n->select);
  A4GL_debug ("Prepare : %s\n", n->select);

  A4GL_debug ("OK..\n");
  return n;
}





int
A4GLSQLLIB_A4GLSQL_execute_implicit_sql (void *vsid, int singleton, int ni,
					 void *binding)
{
  Oid oid;
  struct s_sid *n;
  struct s_pgextra *pgextra;
  //int resultFormat = 0;
  int ok = 0;
  char *sql;
  int setSavepoint = 0;
  char *isInsert=NULL;
  int use_insert_return = 0;
  PGresult *res=0;
  char *statementName;
  if (res) PQclear(res);
  A4GL_debug ("Execute\n");

  ensure_types(); // Make sure we've got the datatypes loaded...

  n = vsid;
  if (vsid == 0)
    {				// nothing doing..
      return 0;
    }

  if (A4GL_esql_db_open (-1, 0, 0, ""))
    {
      current_con = A4GL_esql_dbopen_connection ();
    }



  if (n && A4GL_strstartswith(n->select,"DATABASE ")) {
	char dbname[2000];
	int a;
	int ok=1;
	a=sscanf(n->select,"database %s",dbname);
	if (a==1) {
		A4GL_init_connection (dbname);
	} else {
		ok=0;
	}
	
  	statementName =n->statementName;
  	if (singleton) { A4GL_free_cursor(statementName,1); }
	return ok;
  } else {



  if (!current_con)
    {
      // no connection..
      if (last_msg)
	free (last_msg);
      last_msg = strdup ("No connection");
      last_msg_no = -349;
      A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (-349);
      return 0;
    }
  }


  if (ni)
    {
      n->ni = ni;
      n->ibind = binding;
    }
  statementName =n->statementName;

  if (strlen (n->select) == 0)
    return 0;


  pgextra=n->extra_info;

  A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (0);

  strcpy (warnings, "       ");
  A4GL_copy_sqlca_sqlawarn_string8 (warnings);


  if (currServerVersion >= 80200 || !A4GL_isno(acl_getenv("PG8USEINSERTRETURN")))
    {

      use_insert_return = 1;
      isInsert = strdup (n->select);
      A4GL_convlower (isInsert);
      if (A4GL_strstartswith (isInsert, "insert ") && use_insert_return == 1)
	{
		A4GL_debug("Using insert return");
	  sql = replace_ibind (n->select, n->ni, n->ibind,1);
	  strcat (sql, " returning *");
	}
      else
	{
	A4GL_debug("Doesn't look like an insert or use_insert_return=0");
	  sql = replace_ibind (n->select, n->ni, n->ibind,1);
	}
	free(isInsert);


    }
  else
    {
      use_insert_return = 0;
      sql = replace_ibind (n->select, n->ni, n->ibind,1);
	A4GL_debug("Not using insert return");
    }

  if (inTransaction ())
    {
      setSavepoint++;
      if (CanUseSavepoints) { Execute ("SAVEPOINT preExec", 1); }
    }
  A4GL_debug ("%s ni=%d\n", sql, n->ni);
  

  res = PQexec (current_con, set_explain(sql));

		//A4GL_debug("ERR: %s\n",PQerrorMessage (current_con));

   SET_EXPLAIN_FINISHED;
   pgextra->last_result=res;

  A4GL_debug ("::: %s - %d\n", n->select, PQresultStatus (res));

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
      A4GL_debug ("Bad : %s ", PQerrorMessage (current_con));
      SetErrno (res);
		A4GL_set_sqlerrmessage( PQerrorMessage (current_con));
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
	  oid = PQoidValue (res);
	A4GL_debug("Scan return for serials - got OID=%d",oid);
  		A4GL_set_a4gl_sqlca_errd (5,oid);
	      A4GL_set_a4gl_sqlca_errd (1, 0);

	  if (PQresultStatus (res) == PGRES_TUPLES_OK)
	    {
	      int nfields;
	      nfields = PQnfields (res);
	      // Found out row !
	      for (a = 0; a < nfields; a++)
		{
		int type;
		type=PQftype (res, a);
		A4GL_debug("Scan return for serials - field=%d type=%d",a,type);

		  if (type == dtype_int4oid)
		    {
			int i;
			char *ptr;
			ptr=PQgetvalue (res, 0, a);
			if (ptr) {
			i=atoi(ptr);

			A4GL_debug("Found out serial column @%d : %s",a,PQgetvalue (res, 0, a));
		      // any serial column must be the first integer...
		      A4GL_set_a4gl_sqlca_errd (1, i);
			}
		      break;
		    }
		}
	    }
	  else
	    {
		A4GL_debug("Not found");
	      // not found...
	      A4GL_set_a4gl_sqlca_errd (1, 0);
	    }

	}
      else
	{
		A4GL_debug("Not using use_insert_return - need to check via OID");
	  oid = PQoidValue (res);
  		A4GL_set_a4gl_sqlca_errd (5,oid);
		A4GL_debug("OID=%d",oid);

	  if (oid != InvalidOid)
	    {
	      PGresult *res2=NULL;
	      static char *s=NULL;
	      char *p;
	      int l;
		if(s) free(s);
	      s = strdup (n->select);
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
		long oid_long;
		  A4GL_convlower (s);
			oid_long=oid;
		

		  SPRINTF2 (sql, "SELECT * FROM %s WHERE OID=%ld", s, oid_long);
		A4GL_debug("Executing %s",sql);
		  res2 = PQexec (current_con, sql);


		  if (PQresultStatus (res2) == PGRES_TUPLES_OK)
		    {
		      int nfields;
		      nfields = PQnfields (res2);
			A4GL_debug("Found a row : %d",nfields);
		      // Found out row !
		      for (a = 0; a < nfields; a++)
			{
			A4GL_debug("Found a row : field %d type=%d",a, PQftype (res2, a));
			  if (PQftype (res2, a) == dtype_int4oid)
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
		s=0;
		}
	      A4GL_set_a4gl_sqlca_errd (5, oid);
		if (res2) { PQclear(res2); }
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
 	if (res) { PQclear(res); res=0; }
  	if (singleton) { A4GL_free_cursor(statementName,1); }
      return 0;
    }



  if (setSavepoint)
    {
      if (CanUseSavepoints)
	{
	  	Execute ("ROLLBACK TO SAVEPOINT preExec", 1);
	      	Execute ("RELEASE SAVEPOINT preExec", 1);
	}
    }


   if (res) { PQclear(res); res=0; }


  if (singleton) { A4GL_free_cursor(statementName,1); }

  return 1;
}




static int
copy_to_obind (PGresult * res, int no, struct BINDING *obind, int row)
{
  int b;
  int nrows;
  int nfields;
  int ok=1;
  static int isMdy=-1;

  if (isMdy==-1) {
	// figure out if the current datestyle is MDY...
	// We only do this once - so lets hope the user doesn't change it !
	PGresult *resmdy;
	char *val;
	resmdy=PQexec(current_con, "show datestyle");
	val=PQgetvalue(resmdy,0,0);
	isMdy=0;

	if (strstr(val,"mdy") || strstr(val,"MDY")) {
		isMdy=1;
	}
	PQclear(resmdy);
	//printf("isMdy=%d\n",isMdy);
  }

  nrows = PQntuples (res);
  if (row > nrows)
    return 0;

  nfields = PQnfields (res);

  if (nfields != no)
    {
      warnings[0] = 'W';
      warnings[3] = 'W';
    }

  if (nfields > no)
    {
      nfields = no;
    }


  for (b = 0; b < nfields; b++)
    {
      static char *s = 0;
      static int sl = -1;
      int nsl;
      char *ptr;
      if (PQgetisnull (res, row, b))
	{
	  A4GL_setnull (obind[b].dtype, (char *) obind[b].ptr, obind[b].size);
	  continue;
	}

      ptr = PQgetvalue (res, row, b);
      nsl = strlen (ptr);
      if (nsl >= sl)
	{
	  sl = nsl;
	  s = realloc (s, sl + 2);
	}

A4GL_debug("COPY DTYPE : %d %s\n", obind[b].dtype &DTYPE_MASK,ptr);
      switch (obind[b].dtype)
	{

	case DTYPE_DATE:
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
		// Might need to tweak here if datestyle is different to DBDATE ? 
		A4GL_push_char (ptr);
		A4GL_pop_param (obind[b].ptr, obind[b].dtype, obind[b].size);
	      }
	    break;
	  }

	case DTYPE_CHAR:
	  {
	    char *s;
	    s = strdup (ptr);
	    A4GL_trim (s);
	    if (strlen (s) > obind[b].size)
	      {
		// Too large -it'll get truncated...
		warnings[0] = 'W';
		warnings[1] = 'W';
		A4GL_copy_sqlca_sqlawarn_string8 (warnings);
	      }
	    A4GL_push_char (ptr);
	    A4GL_pop_param (obind[b].ptr, obind[b].dtype, obind[b].size);
	    free (s);
	    break;
	  }



	case DTYPE_TEXT:
	case DTYPE_BYTE:
	  {
	    struct fgl_int_loc *a4gl;
	    a4gl = obind[b].ptr;


	    if (strlen (ptr))
	      a4gl->isnull = 'N';

	    if (a4gl->where == 'F')
	      {
		FILE *f;
		f = fopen (a4gl->filename, "w");
		if (f) {
			fwrite (ptr, 1, strlen (ptr), f);
			fclose (f);
		} else {
			A4GL_exitwith_sql("Unable to open blobfile");
		}
	      }
	    else
	      {
		a4gl->memsize = strlen (ptr) + 1;
		a4gl->ptr = A4GL_memdup (ptr, a4gl->memsize);
	      }
	    break;
	  }



	case DTYPE_DTIME:
		{
	A4GL_debug("Here - we've got a DTIME");
			char buff[2000];
				//printf("Ptr=%s\n",ptr);
			if (ptr[2]=='/' && ptr[5]=='/') { // Its datestyle SQL == dd/mm/yy hh:mm:ss
				strcpy(buff,ptr);
				// eg : 
				// 04/20/2008 10:34:53
				// 0123456789
				// 2008-04-20 10:34:53
				buff[0]=ptr[6];
				buff[1]=ptr[7];
				buff[2]=ptr[8];
				buff[3]=ptr[9];
				buff[4]='-';
				buff[7]='-';
				if (isMdy) {
					buff[5]=ptr[0];
					buff[6]=ptr[1];
					buff[8]=ptr[3];
					buff[9]=ptr[4];
				} else {
					buff[5]=ptr[3];
					buff[6]=ptr[4];
					buff[8]=ptr[0];
					buff[9]=ptr[1];
				}
	  			A4GL_push_char (buff);
	  			A4GL_pop_param (obind[b].ptr, obind[b].dtype, obind[b].size);
			} else {
	  			A4GL_push_char (ptr);
	  			A4GL_pop_param (obind[b].ptr, obind[b].dtype, obind[b].size);
			}
		break;
		}

	case DTYPE_DECIMAL:
	case DTYPE_MONEY:
		{
	    	char buff[2000];
	    	strcpy (buff, ptr);
		ensure_dot_format_for_decimal_string(buff);
		A4GL_setnull(obind[b].dtype,obind[b].ptr,obind[b].size);
      		A4GL_str_dot_to_dec (buff, (void *)obind[b].ptr);
		}
	break;


	case DTYPE_SMINT:
	{
		long long_val;
	 	char *eptr;

		long_val =  strtol (ptr, &eptr, 10);

    		if (long_val < SHRT_MIN || long_val > SHRT_MAX)
       		{
			A4GL_set_a4gl_sqlca_sqlcode(-1214);
			*(short *) obind[b].ptr = 0;
                } else {
			*(short *) obind[b].ptr = long_val;
		}
	}
		break;

	case DTYPE_INTERVAL:
	{
	  	A4GL_push_char (ptr);
	  	ok=A4GL_pop_param (obind[b].ptr, obind[b].dtype, obind[b].size);
		
	}

		//@ fixme
		break;

	default:
	  A4GL_push_char (ptr);
	  ok=A4GL_pop_param (obind[b].ptr, obind[b].dtype, obind[b].size);
	
	

	    break;
	}
    }
  return 0;
}


static void free_prepare(struct s_sid *n) {
   A4GL_free_associated_mem (n);
}

int
A4GLSQLLIB_A4GLSQL_execute_implicit_select (void *vsid, int singleton)
{
  struct s_sid *n;
  struct s_pgextra *pgextra;
  int ok;
  int nrows=0;
  int nfields;
  int setSavepoint = 0;
  char *sql;
  static PGresult *res=0;
  if (res) {PQclear(res); res=0;}
  n = vsid;

  if (n == 0)
    {
      return 1;
    }

  if (A4GL_esql_db_open (-1, 0, 0, ""))
    {
      current_con = A4GL_esql_dbopen_connection ();
    }
  if (!current_con)
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

  A4GL_debug ("Exec sql : %s", n->select);
  if (inTransaction ())
    {
      setSavepoint++;
      A4GL_debug ("Set savepoint");
      if (CanUseSavepoints)
	{
	  Execute ("SAVEPOINT preExecSelect", 1);
	}
    }

  sql = n->select;
  if (n->ni)
    {
      sql = replace_ibind (sql, n->ni, n->ibind,1);
    }
  pgextra=n->extra_info;


  A4GL_debug("replaced = %s",sql);
  res = PQexec (current_con, set_explain(sql));
	SET_EXPLAIN_FINISHED;
  pgextra->last_result=res;
  A4GL_debug ("res=%p\n", res);
  A4GL_set_a4gl_sqlca_errd (0, PQntuples (res));
  A4GL_set_a4gl_sqlca_errd (2, atoi (PQcmdTuples (res)));
  A4GL_set_a4gl_sqlca_errd (1, 0);

  pgextra->last_result=res;

  switch (PQresultStatus (res))
    {
    case PGRES_COMMAND_OK:
		A4GL_debug("OK");
      ok = 1;
      break;
    case PGRES_TUPLES_OK:
		A4GL_debug("OK");
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
	A4GL_debug("nrows=%d nfields=%d", nrows, nfields);
      if (nrows == 0)
	{
	  A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (100);
	}


      if (singleton)
	{
	}

      if (nrows > 1)
	{
	  A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (-284);	// A subquery has returned not exactly one row.
		if (singleton) { A4GL_free_associated_mem(n); free_prepare(n); }

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
	if (singleton) { A4GL_free_associated_mem(n); free_prepare(n); }

  A4GL_copy_sqlca_sqlawarn_string8 (warnings);
      return 0;
    }

  if (setSavepoint)
    {
      if (CanUseSavepoints)
	{
	  	Execute ("ROLLBACK TO SAVEPOINT preExecSelect", 1);
	      	Execute ("RELEASE SAVEPOINT preExecSelect", 1);
	}
    }
	if (singleton) { A4GL_free_associated_mem(n); free_prepare(n); }
  A4GL_copy_sqlca_sqlawarn_string8 (warnings);
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
      current_con = A4GL_esql_dbopen_connection ();
    }
  if (!current_con)
    {
      A4GLSQLLIB_A4GLSQL_init_connection_internal ("template1");

      if (!current_con)
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
      PQfinish (current_con);
  	A4GL_del_pointer ("default", SESSCODE);
      current_con = 0;
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
      current_con = A4GL_esql_dbopen_connection ();
    }
  if (current_con == 0)
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


static int
conv_sqldtype (int pgtype, int pglen, int *a4gl_dtype, int *a4gl_len)
{
  ensure_types(); // Make sure we've got the datatypes loaded...

  if (pgtype == dtype_bpcharoid)
    {
	if (pglen==-1) {
		// Indeterminate for some reason
      		*a4gl_dtype = DTYPE_VCHAR;
      		*a4gl_len = 255;
	} else {
      		*a4gl_dtype = DTYPE_CHAR;
      		*a4gl_len = pglen;
	}
      return 1;
    }

  if (pgtype == dtype_varcharoid)
    {
      if (pglen==-1) pglen=255;
      *a4gl_dtype = DTYPE_VCHAR;
      *a4gl_len = pglen;
      return 1;
    }
  if (pgtype == dtype_int4oid || pgtype==26)
    {
      *a4gl_dtype = DTYPE_INT;
      *a4gl_len = pglen;
      return 1;
    }
  if (pgtype == dtype_int2oid)
    {
      *a4gl_dtype = DTYPE_SMINT;
      *a4gl_len = pglen;
      return 1;
    }
  if (pgtype == dtype_int8oid)
    {
      *a4gl_dtype = DTYPE_INT; // This should probably be a 'BIGINT' - but its used as a count(*) result - and INT8 isn't as well established yet..
      *a4gl_len = pglen;
      return 1;
    }
  if (pgtype == dtype_float8oid)
    {
      *a4gl_dtype = DTYPE_FLOAT;
      *a4gl_len = pglen;
      return 1;
    }
  if (pgtype == dtype_float4oid)
    {
      *a4gl_dtype = DTYPE_SMFLOAT;
      *a4gl_len = pglen;
      return 1;
    }
  if (pgtype == dtype_timestampoid)
    {
      *a4gl_dtype = DTYPE_DTIME;
      *a4gl_len = pglen;
      return 1;
    }
  if (pgtype == dtype_dateoid)
    {
      *a4gl_dtype = DTYPE_DATE;
      *a4gl_len = pglen;
      return 1;
    }

  if (pgtype == dtype_numericoid)
    {
      if (pglen == -1)
	{
	  *a4gl_dtype = DTYPE_FLOAT;
	  *a4gl_len = pglen;
	}
      else
	{
	  // Length,scale ? 
	  *a4gl_dtype = DTYPE_FLOAT;
	  *a4gl_len = pglen;
	}
      return 1;
    }

  if (pgtype == dtype_textoid)
    {
      if (pglen == -1)
	{
	  *a4gl_dtype = DTYPE_TEXT;
	  *a4gl_len = pglen;
	}
      else
	{
	  // Length,scale ? 
	  *a4gl_dtype = DTYPE_TEXT;
	  *a4gl_len = pglen;
	}
      return 1;
    }


#ifndef __WIN32__
  FPRINTF (stderr, "WARNING : Unrecognised postgres datatype : %d - please add to pg8.c\n", pgtype);
#endif


  // Char(20) should cover most things..
  *a4gl_dtype = DTYPE_VCHAR;
  *a4gl_len = 20;

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

  char schemaname[2000]="";
  char search_path[2000]="";

  curr_colno = 0;


  tabname = info;
  if (strchr (tabname, ':'))
    {
      strcpy (tname, strchr (tabname, ':') + 1);
      tabname = tname;
    }

  if (A4GL_esql_db_open (-1, 0, 0, ""))
    {
      current_con = A4GL_esql_dbopen_connection ();
    }
  if (current_con == 0)
    {
      A4GL_exitwith_sql ("Not connected to database");
      return 0;
    }
  A4GL_trim (tabname);

        // are they specifying a 'schema' ?
  if (strchr (tabname, '.'))
    {
        char *ptr;
        PGresult *res;
        strcpy(schemaname,tabname);
        // extract the schema name and add it to the search path
        // Its not exact - but it will do for now..
        ptr=strchr(schemaname,'.');
        if (ptr) {
                *ptr=0;
        }

        res=PQexec(current_con, "show search_path");
        strcpy(search_path,PQgetvalue(res,0,0));
        PQclear(res);
        strcpy (tname, strchr (tabname, '.') + 1);
        tabname = tname;
        SPRINTF2(buff,"set search_path TO %s, %s", schemaname, search_path);
        //printf ("Executin : %s\n", buff);
        res=PQexec(current_con, buff);
        //printf("tabname=%s\n",tabname);
        PQclear(res);
    }




  SPRINTF1 (buff,
	    "SELECT a.attname, pg_catalog.format_type(a.atttypid, a.atttypmod), a.attnotnull, a.atthasdef, a.attnum , a.atttypid, a.atttypmod, (SELECT substring(pg_catalog.pg_get_expr(d.adbin, d.adrelid) for 128) FROM pg_catalog.pg_attrdef d WHERE d.adrelid = a.attrelid AND d.adnum = a.attnum AND a.atthasdef)   FROM pg_catalog.pg_attribute a,pg_class b WHERE a.attrelid = b.oid AND a.attnum > 0 AND NOT a.attisdropped AND b.relname='%s' and pg_table_is_visible(b.oid) ORDER BY a.attnum",
	    tabname);

  res = Execute (buff, 0);
  nrows = PQntuples (res);

  for (a = 0; a < nrows; a++)
    {
      int dtype;
      int prc;
      cnt = a;
      fixtype (PQgetvalue (res, a, 1), &dtype, &prc, PQgetvalue (res, a, 7));

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


        if (strlen(search_path)) {
                PGresult *res;
        SPRINTF1(buff,"set search_path TO %s", search_path);
        res=PQexec(current_con, buff);
        PQclear(res);
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


// This function is used to execute some
// internal sql statements when we dont really care if they succeed for fail
//
static void
execute_dont_care (PGconn * conn, char *sql)
{
  int setSavepoint = 0;
  PGresult *res;
  int ok;

  if (inTransaction () && CanUseSavepoints)
    {
      setSavepoint++;
	  Execute ("SAVEPOINT predcExec", 1);
    }

  res = PQexec (conn, sql);
  ok = 0;
  if (res)
    {
      switch (PQresultStatus (res))
	{
	case PGRES_COMMAND_OK:
	case PGRES_TUPLES_OK:
	case PGRES_EMPTY_QUERY:
	  ok = 1;
	break;
	default: ok=0; break;
	}
      PQclear (res);
    }

  if (setSavepoint)
    {
	if (ok) {
	  Execute ("RELEASE SAVEPOINT predcExec", 1);
	} else {
	  	Execute ("ROLLBACK TO SAVEPOINT predcExec", 1);
	      	Execute ("RELEASE SAVEPOINT predcExec", 1);
	}
    }
}


void *
A4GLSQLLIB_A4GLSQL_declare_cursor_internal (int upd_hold, void *vsid, int scroll,
				   char *cursname)
{
  /* struct s_sid *nsid; */
  struct s_cid *cid;
  struct s_sid *sid;
  char buff[20560];
  char *ptr;
  sid = vsid;
  if (A4GL_esql_db_open (-1, 0, 0, ""))
    {
      current_con = A4GL_esql_dbopen_connection ();
    }

  if (!current_con)
    {
      // no connection..
      if (last_msg)
	free (last_msg);
      last_msg = strdup ("No connection");
      last_msg_no = -349;
      A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (-349);
      return 0;
    }

  cid = acl_malloc2 (sizeof (struct s_cid));

  cid->statement = (void *) sid;
  cid->hstmt = 0;
  cid->mode = upd_hold + (scroll * 256);
  cid->isScroll=scroll;
  cid->o_ibind = 0;
  cid->o_obind = 0;
  cid->o_ni = 0;
  cid->o_no = 0;
  cid->DeclareSql = 0;
 cid->o_lastopenibind=NULL;
  cid->o_lastopenni=0;

  cid->cursorState=E_CURSOR_DECLARED;



  if (scroll)
    {
      if (upd_hold &2 ) // Explicit WITH HOLD
	{
	  SPRINTF2 (buff, " DECLARE %s SCROLL CURSOR WITH HOLD FOR %s", cursname, sid->select);
	}
      else
	{
	  int ttype;
	  ttype = PQtransactionStatus (current_con);
	  if (ttype == PQTRANS_ACTIVE || ttype == PQTRANS_INTRANS)
	    {
	      SPRINTF2 (buff, " DECLARE %s SCROLL CURSOR FOR %s", cursname, sid->select);
	    }
	  else
	    {
	      SPRINTF2 (buff, " DECLARE %s SCROLL CURSOR WITH HOLD FOR %s", cursname, sid->select);
	    }
	}
    }
  else
    {
      if (upd_hold & 2) // Explicit WITH HOLD
	{
	  SPRINTF2 (buff, " DECLARE %s CURSOR WITH HOLD FOR %s", cursname, sid->select);
	}
      else
	{
	  int ttype;
	  int use_with_hold=1;

	
	  ttype = PQtransactionStatus (current_con);

	  if (ttype == PQTRANS_ACTIVE || ttype == PQTRANS_INTRANS)
	    {
		use_with_hold=0;
		}

	if (strstr(sid->select," FOR UPDATE ")  ) {
			use_with_hold=0;
	}

	if (!use_with_hold) {
	      SPRINTF2 (buff, " DECLARE %s CURSOR FOR %s", cursname,
			sid->select);
	    }
	  else
	    {
	      SPRINTF2 (buff, " DECLARE %s CURSOR WITH HOLD FOR %s", cursname,
			sid->select);
	    }
	}
    }

  ptr = strdup (sid->select);
  A4GL_convlower (ptr);

  if (strstr (ptr, "insert into"))
    {
      cid->DeclareSql = strdup (sid->select);
      cid->mode |= 0x100;
    }
  else
    {

        cid->DeclareSql = strdup (buff);
	A4GL_set_associated_mem(cid, cid->DeclareSql);


      if ((cid->mode & 0x100))
	{
	  cid->mode = cid->mode - 0x100;
	}
    }
  free (ptr);
  return cid;


}

void
A4GLSQLLIB_A4GLSQL_flush_cursor_internal (char *cursor)
{
  A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (0);

  strcpy (warnings, "       ");
  A4GL_copy_sqlca_sqlawarn_string8 (warnings);

}




int
A4GLSQLLIB_A4GLSQL_open_cursor_internal (char *s1, int ni, void *vibind)
{
  struct s_cid *cid;
  struct BINDING *ibind;
	char s[2000];
  char *buff2;
  struct s_sid *n;





A4GL_debug("ni=%d\n",ni);
	strcpy(s,s1);
	A4GL_trim(s);

  // Here - we'll bind the inputs
  // and then execute the statement...
  ibind = vibind;
  A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (0);
  cid = (struct s_cid *) A4GL_find_cursor (s);


  strcpy (warnings, "       ");
  A4GL_copy_sqlca_sqlawarn_string8 (warnings);
  if (A4GL_esql_db_open (-1, 0, 0, ""))
    {
      current_con = A4GL_esql_dbopen_connection ();
    }

  if (!current_con)
    {
      // no connection..
      if (last_msg)
	free (last_msg);
      last_msg = strdup ("No connection");
      last_msg_no = -349;
      A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (-349);
      return 1;
    }

  if (cid == 0)
    {
      A4GL_exitwith_sql ("Can't open cursor that hasn't been defined");
      return 1;
    }

  if (cid->mode & 0x100)
    {
      // Its an insert cursor - we'll just do inserts later 
      // so we can ignore this for now...
      return 0;
    }



  n = (struct s_sid *) cid->statement;

  if (ni == 0)
    {
      ni = n->ni;
      ibind = n->ibind;
    }
  
  if(ni==0) { 
	// Still 0 - maybe they did an OPEN before  - and this is a foreach..
	if (cid->o_lastopenni) {
		if (strstr(cid->DeclareSql,"$1")) {
		// Looks like it uses a parameter...
			ni=cid->o_lastopenni;
			ibind=cid->o_lastopenibind;
		}
	}
  }


  cid->o_lastopenibind=ibind;
  cid->o_lastopenni=ni;

  A4GL_debug("before replace_ibind ni =%d",ni);

  buff2 = replace_ibind (cid->DeclareSql, ni, ibind,1);

  A4GL_debug ("cid->DeclareSql=%s buff2=%s\n", cid->DeclareSql, buff2);
  cid->hstmt = PQexec (current_con, set_explain(buff2));
	SET_EXPLAIN_FINISHED;

  A4GL_set_a4gl_sqlca_errd(2,0);
  cid->nrows=0;
  switch (PQresultStatus (cid->hstmt))
    {
    case PGRES_COMMAND_OK:
    case PGRES_TUPLES_OK:	
      A4GL_debug ("Ok");
      break;

    default:
      A4GL_debug ("Bad prepare %s", PQerrorMessage (current_con));
      SetErrno (cid->hstmt);
		A4GL_set_sqlerrmessage( PQerrorMessage (current_con));
      return 1;
    }

  cid->mode |= 0x4000;



  return 0;
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
  A4GL_set_status (a, 1);
}



/*****************************************************************************/
int
A4GLSQLLIB_A4GLSQL_fetch_cursor_internal (char *cursor_name_s, int fetch_mode,
				 int fetch_when, int nobind, void *vobind)
{
  struct BINDING *obind;
  struct s_cid *cid;
  char buff[256];
char cursor_name[2000];
  static PGresult *res=NULL;
  strcpy(cursor_name, cursor_name_s);
A4GL_trim(cursor_name);

  obind = vobind;
  if (res) {
		PQclear(res);
		res=NULL;
	}

  cid = A4GL_find_cursor (cursor_name);
  if (cid == 0)
    {
      A4GL_exitwith_sql ("Cursor not found");
      return 1;
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
  

  res = PQexec (current_con, set_explain(buff));
	SET_EXPLAIN_FINISHED;
  A4GL_debug ("%s - %d \n", buff, PQresultStatus (res));

  if (cid->statement) {
	struct s_sid *n;
	struct s_pgextra *pgextra;
		n= (struct s_sid *) cid->statement;
		pgextra=n->extra_info;
		pgextra->last_result=res;
  }
 A4GL_set_a4gl_sqlca_errd(2,0);

  switch (PQresultStatus (res))
    {
    case PGRES_COMMAND_OK:
    case PGRES_TUPLES_OK:
  	cid->nrows++;
	 A4GL_set_a4gl_sqlca_errd(2,cid->nrows);
      A4GL_debug ("Good");
      break;

    default:
      A4GL_debug ("Bad %s", PQerrorMessage (current_con));
      SetErrno (res);
      A4GL_exitwith_sql_detail ("Unexpected postgres return code1\n",  PQerrorMessage (current_con));
      return 1;
    }


  A4GL_debug ("RES : %d\n", PQntuples (res));

  if (PQntuples (res) == 0)
    {
      A4GL_debug ("No rows found..");
      A4GL_set_a4gl_sqlca_errd (2, 0);
      A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (100);
      if (cid->isScroll) { // SCROLL cursor
	if (fetch_mode==FETCH_RELATIVE) {
		// Postgresql will go past the first and last entries so the next
		// fetch previous/fetch next will reread the last one at that point..
		// eg :
		//     create temp table sometab ( a integer);
		//     insert into sometab values(1);
		//     insert into sometab values(2);
		//     insert into sometab values(3);
		//     begin work;
		//
		//     declare c1 scroll cursor for select * from sometab;
		//     fetch next from c1;
		//     fetch next from c1;
		//     fetch next from c1;
		//     fetch next from c1;
		//     fetch prior from c1;
		//     fetch prior from c1;
		//     fetch prior from c1;
		//     fetch next from c1;
		//
		//     would return 1,2,3, (notfound), 3,2,1,(notfound),1,
		//     Informix would return 1,2,3,(notfound),2,1,(notfound),2
		// 
		// So - in order to emulate that - if we've got a 100 (notfound) on a scroll cursor
		// then refetch the first or last to reposition the cursor...
		
		if (fetch_when==1) { // We were doing a FETCH NEXT - so we must be at the end of the list
  			PGresult *res;
	  		SPRINTF1 (buff, "FETCH LAST FROM %s", cursor_name);
  			res = PQexec (current_con, buff);
			// We dont care if these work - we're just trying to emulate informix...
      			//if (res) {PQclear (res); res=NULL;}
		} else {
  			PGresult *res;
	  		SPRINTF1 (buff, "FETCH FIRST FROM %s", cursor_name);
			// We dont care if these work - we're just trying to emulate informix...
  			res = PQexec (current_con, buff);
		}
	}
      }
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
	  struct s_sid *p;
	  p = cid->statement;
	  copy_to_obind (res, p->no, p->obind, 0);
	}
    }
  return 0;
}


int
A4GLSQLLIB_A4GLSQL_close_cursor_internal (char *currname,int explicit)
{
  struct s_cid *ptr;
int lstatus;


  lstatus=A4GL_get_a4gl_sqlca_sqlcode();


  strcpy (warnings, "       ");
  A4GL_copy_sqlca_sqlawarn_string8 (warnings);

  ptr = A4GL_find_cursor(currname);

  if (ptr->mode & 0x4000)
    {
      char buff[256];
	strcpy(buff,"CLOSE ");
	strcat(buff, currname);
      execute_dont_care (current_con, buff);
      ptr->mode -= 0x4000;
    }

    ptr->mode=0;

  if (lstatus<0) {
  	A4GLSQL_set_sqlca_sqlcode (lstatus);
  }
  if (ptr && explicit) {
  	ptr->o_lastopenibind=NULL;
  	ptr->o_lastopenni=0;
  }

  return 1;
}


static char *
pgescape_str (char *s,int sl)
{
  int err;
  static int l = 0;
  //int sl;
  static char *buff = 0;
  //sl = strlen (s);
  if (l < sl || l == 0 || buff == 0)
    {
      l = sl;
      buff = realloc (buff, sl * 2 + 1);
    }
#ifdef USE_ESCAPE_STRING_CONN
  // this is documented - but doesn't seem to exist!
  PQescapeStringConn (current_con, buff, s, sl, &err);
#else
  err = 0;
  PQescapeString (buff, s, sl);
#endif

  if (err == 0) {
    return buff;		// Everything is ok...
}
// Some error...
  return s;
}


char *
replace_ibind (char *stmt, int ni, struct BINDING *ibind, int type)
{
  static char buff2[64000];
  long bloblen;
  char *blobptr;
  char buff3[200];

  if (ni)
    {
      int a;
      int buff2cnt = 0;
      int next_param = 0;
      int param=0;
	int instr=0;
      int sl;
	sl= strlen (stmt);
      for (a = 0; a < sl; a++)
	{
	  int has_match;
	  has_match = 0;

	  if (stmt[a]=='\'' ) {
		if (instr) {
			instr=0;
		} else {
			instr=1;
		}
	  }

	  if (stmt[a] == '$' && type == 1 && ! instr)
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
	      has_match = 1;
	      a += c;
	      buff2[buff2cnt] = 0;
	    }

	  if (stmt[a] == '?' && type == 0 && ! instr)
	    {
	      param = next_param++;
	      has_match = 1;
	      a++;
	      buff2[buff2cnt] = 0;

	    }

	  if (has_match)
	    {
	      char *str;
		A4GL_assertion(param<0 || param>ni,"param out of range");


	      if (A4GL_isnull (ibind[param].dtype & DTYPE_MASK, ibind[param].ptr) || (ibind[param].dtype==0 && ibind[param].size==0 /* a special case - might be used with a LOAD */ ))
		{

		  switch (ibind[param].dtype)
		    {


		    case DTYPE_DATE:
		      strcat (buff2, "(NULL::date)");
		      break;
		    default:
		      strcat (buff2, "NULL");
		      break;
		    }
		}
	      else
		{

A4GL_debug("COPY DTYPE : %d\n", ibind[param].dtype &DTYPE_MASK);

		  switch (ibind[param].dtype)
		    {
		    case DTYPE_CHAR:
		    case DTYPE_NCHAR:
			{
		      //A4GL_push_param (ibind[param].ptr, ibind[param].dtype);
		      //str = A4GL_char_pop ();
  			static char buff3[64000];
  			static char buff4[64000];
			strcpy(buff3,ibind[param].ptr);
		        A4GL_trim (buff3);
		      	sprintf (buff4, "'%s'",pgescape_str(buff3, strlen(buff3)));
			strcat(buff2,buff4);
			}
		      //strcat (buff2, pgescape_str (str, strlen (str)));
		      //strcat (buff2, "'");
		      //free (str);
		      break;


		    case DTYPE_DTIME:
		    case DTYPE_INTERVAL:
		      A4GL_push_param (ibind[param].ptr, ibind[param].dtype);
		      str = A4GL_char_pop ();
		      strcat (buff2, "'");
		      A4GL_trim (str);
		      strcat (buff2, pgescape_str (str, strlen (str)));
		      strcat (buff2, "'");
		      free (str);
		      break;

		    case DTYPE_VCHAR:
                      A4GL_push_param (ibind[param].ptr, ibind[param].dtype);
                      str = A4GL_char_pop ();
                      strcat (buff2, "'");
                      strcat (buff2, pgescape_str (str, strlen (str)));
                      strcat (buff2, "'");
                      free (str);
                      break;
/*
  			//static char buff3[64000];
			//strcpy(buff3,ibind[param].ptr);
		        //A4GL_trim (buff3);
		        //A4GL_pause_execution();
	//printf("'%s'\n", ibind[param].ptr);
		      	sprintf (buff3, "'%s'",pgescape_str(ibind[param].ptr, strlen(ibind[param].ptr)));
			strcat(buff2,buff3);

		      //A4GL_push_param (ibind[param].ptr, ibind[param].dtype);
		      //str = A4GL_char_pop ();
		      //strcat (buff2, "'");
		      //strcat (buff2, pgescape_str (str, strlen (str)));
		      //strcat (buff2, "'");
		      //free (str);
		      
		      break;
*/

		    case DTYPE_MONEY:
		    case DTYPE_DECIMAL:
		      A4GL_push_param (ibind[param].ptr, DTYPE_DECIMAL + ENCODE_SIZE (ibind[param].size));
		      str = A4GL_char_pop ();
		      A4GL_lrtrim (str);
			strcat(buff2,"(");
		      strcat (buff2, pgescape_str (str, strlen (str)));
			strcat(buff2,")");
		      free (str);
		      break;

		    case DTYPE_SMFLOAT:
		      SPRINTF1 (buff3, "(%16.8f)", *(float *) ibind[param].ptr);
		      strcat (buff2, buff3);
		      break;

		    case DTYPE_FLOAT:
		      SPRINTF1 (buff3, "(%16.8lf)", *(double *) ibind[param].ptr);
		      strcat (buff2, buff3);
		      break;

		    case DTYPE_INT:
		      SPRINTF1 (buff3, "(%d)", *(int *) ibind[param].ptr);
		      strcat (buff2, buff3);
			break;

		    case DTYPE_SMINT:
		      SPRINTF1 (buff3, "(%d)", *(short *) ibind[param].ptr);
		      strcat (buff2, buff3);
			break;

		    case DTYPE_DATE:
		      strcat (buff2, "to_date('");
		      strcat (buff2, A4GL_using_date (*((long *) ibind[param].ptr), "yyyy-mm-dd"));
		      strcat (buff2, "','YYYY-MM-DD')");
		      break;

		    case DTYPE_BYTE:
		      A4GL_get_blob_data (ibind[param].ptr, &blobptr, &bloblen);
		      strcat (buff2, "'");
		      strcat (buff2, pgescape_str (blobptr, bloblen));
		      strcat (buff2, "'");
		      free (blobptr);
		      break;

		    case DTYPE_TEXT:
		      A4GL_get_blob_data (ibind[param].ptr, &blobptr, &bloblen);
		      strcat (buff2, "'");
		      strcat (buff2, pgescape_str (blobptr, bloblen));
		      strcat (buff2, "'");
		      free (blobptr);
		      break;


		    default:
		      A4GL_push_param (ibind[param].ptr, ibind[param].dtype + ENCODE_SIZE (ibind[param].size));
		      str = A4GL_char_pop ();
		      A4GL_trim (str);
		      strcat (buff2, pgescape_str (str, strlen (str)));
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
  res = PQexec (current_con, set_explain(s));
	SET_EXPLAIN_FINISHED;
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
      A4GL_debug ("Bad %s", PQerrorMessage (current_con));
      if (res)
	{
	  SetErrno (res);
		A4GL_set_sqlerrmessage( PQerrorMessage (current_con));
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
  ttype = PQtransactionStatus (current_con);
  if (ttype == PQTRANS_ACTIVE || ttype == PQTRANS_INTRANS)
    return 1;

  return 0;
}

void
A4GLSQLLIB_A4GLSQL_free_cursor_internal (char *currname)
{
  struct s_cid *ptr;
  A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (0);

  strcpy (warnings, "       ");
  A4GL_copy_sqlca_sqlawarn_string8 (warnings);

  ptr = A4GL_find_cursor(currname);
  if (ptr == 0)
    {
      return;
    }
  if (ptr->hstmt) {
		PQclear(ptr->hstmt);
	}
/*
  if (ptr->mode & 0x4000) {
		// Close any open cursor..
		A4GLSQLLIB_A4GLSQL_close_cursor(currname);
  }
*/
}


static void
SetErrno (PGresult * res)
{
  char *thisstate;
  int a;
int isset=0;
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
    "08003", "CONNECTION DOES NOT EXIST", -349},
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
    "25000", "INVALID TRANSACTION STATE", -255},
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
    "25005", "NO ACTIVE SQL TRANSACTION FOR BRANCH TRANSACTION", -255},
    {
    "25006", "READ ONLY SQL TRANSACTION", -1},
    {
    "25007", "SCHEMA AND DATA STATEMENT MIXING NOT SUPPORTED", -1},
    {
    "25P01", "NO ACTIVE SQL TRANSACTION", -255},
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
    "42P01", "UNDEFINED TABLE", -206},
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
    "42P07", "DUPLICATE TABLE", -310},
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

  if (res == NULL)
    {
	char *s;
		s=PQerrorMessage (current_con);
		A4GL_set_sqlerrmessage(s);
		A4GL_debug("No resultset - s=%s\n", s);
	  	A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (-349);
      if (last_msg) free (last_msg);
      last_msg = strdup (s);
      last_msg_no = -349;
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
	  last_msg_no = A4GL_remap_nativeerror(states[a].compat_err, thisstate);
	  A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (last_msg_no);
		isset++;
	  break;
	}
    } 

  if (!isset) {
  	last_msg_no = A4GL_remap_nativeerror(-1, thisstate);
  	A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (last_msg_no);
  }

}



static long A4GL_describecolumn (PGresult * res, int colno, int type)
{
  int dtype;
  int prc;
  int column_count;
  int rval=0;

  if (type == 6)
    return atoi (PQcmdTuples (res));

  if (type == 5)
    return PQnfields (res);


A4GL_assertion(colno<0,"colno<0");

  column_count = PQnfields (res);

  if (colno > column_count)
    {
      A4GL_exitwith_sql ("Column out of range");
      return 0;
    }


  switch (type)
    {
    case 0:
      conv_sqldtype (PQftype (res, colno), PQfsize (res, colno), &dtype, &prc);
      rval = dtype;
      break;

    case 1:
      rval = (long) PQfname (res, colno);
      break;

    case 2:
      rval = PQfmod (res, colno);
	if (rval==-1) {
      		conv_sqldtype (PQftype (res, colno), PQfsize (res, colno), &dtype, &prc);
		if (dtype==DTYPE_VCHAR) {
			rval=255;
		}
	}
      break;

    case 3:
      rval = PQfsize (res, colno);
	if (rval==-1) {
      		conv_sqldtype (PQftype (res, colno), PQfsize (res, colno), &dtype, &prc);
		if (dtype==DTYPE_VCHAR) {
			rval=255;
		}
	}
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
	struct s_sid *n=0;
  PGresult *res;
  int z;
struct s_pgextra *pgextra;
  sid = A4GL_find_prepare (stmt);
  if (sid == 0)
    {
	A4GL_debug("Not found as a prepare - look for a cursor...");
      cid = A4GL_find_cursor (stmt);
      if (cid == 0)
	{
	  A4GL_exitwith_sql ("Could not find statement or cursor specified");
	  return 0;

	}
      res = cid->hstmt;
	n=cid->statement;

	if (n) {
		pgextra=sid->extra_info;
		if (pgextra->last_result) {
				res=pgextra->last_result;
		}
	}

    }
  else
    {
      res = sid->hstmt;
	n=sid ;
	pgextra=sid->extra_info;
	if (pgextra->last_result) {
		res=pgextra->last_result;
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
A4GLSQLLIB_A4GLSQL_put_insert_internal (char *cursorName, void *vibind, int n)
{
  struct BINDING *ibind = 0;
  //char *cursorName;
  struct s_cid *cid;
  struct s_sid *sid;
  int ni = 0;
  char *newstr;
  ibind = vibind;

  A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (0);

  strcpy (warnings, "       ");
  A4GL_copy_sqlca_sqlawarn_string8 (warnings);

  cid = A4GL_find_cursor (cursorName);


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


  sid =  cid->statement;
  if (ni == 0)
    {
      ni = sid->ni;
      ibind = sid->ibind;
    }

  newstr = replace_ibind (sid->select, ni, ibind,1);

  Execute (newstr, 1);		// we may need to add our errd[2] serial number checking here too...

}


char *A4GLSQLLIB_A4GLSQL_get_table_checksum(char *s) {
char sqlstmt[200];
static char buff[200];
char *ptr;
PGresult *res;
if (!current_con) return s;

SPRINTF1(sqlstmt,"SELECT oid FROM pg_class  WHERE pg_table_is_visible(oid) AND relname='%s'",s);
res=PQexec(current_con,sqlstmt);
if (!res) return s;

switch (PQresultStatus (res)) {
	case PGRES_TUPLES_OK:
	case PGRES_COMMAND_OK:
		// We're ok !
		ptr=PQgetvalue(res,0,0);
		if (ptr==0) ptr="<notfound>";
		strcpy(buff,ptr);
       		PQclear (res);
		return buff;
	default: break;
}

PQclear (res);
return s;
}


void A4GLSQLLIB_A4GLSQL_free_prepare_internal (void* sid ) {
		// does nothing in this driver
}

static void clr_types(void) {
	if (types) {free(types);}
	types=NULL;
}



static void ensure_types(void) {
   PGresult *res;
   int a;
   int nrows;

	if (types) return; // Already loaded...
	if (current_con==NULL) return; // Nothing to load against..


// Clear these down..
	dtype_bpcharoid=-1;
	dtype_varcharoid=-1;
	dtype_int4oid=-1;
	dtype_int2oid=-1;
	dtype_int8oid=-1;
	dtype_float8oid=-1;
	dtype_float4oid=-1;
	dtype_timestampoid=-1;
	dtype_dateoid=-1;
	dtype_numericoid=-1;
	dtype_textoid=-1;

	res=PQexec(current_con,"select oid, typname from pg_type");
	if (res==NULL) {
		return;
	}

	switch (PQresultStatus (res)) {
		case PGRES_TUPLES_OK:
		case PGRES_COMMAND_OK:
			// We're ok !
			break;
		default:
			// We're not ok !
			PQclear(res);
			return ;
	}
	
  nrows = PQntuples (res);
  types=realloc(types, sizeof(struct s_typelist)*nrows);

  for (a = 0; a < nrows; a++)
    {
	types[a].type=atol(PQgetvalue (res, a, 0));
	strcpy(types[a].typename,PQgetvalue (res, a, 1));
	if (strcmp("int4",types[a].typename)==0) 	{ dtype_int4oid=types[a].type; }
	if (strcmp("int2",types[a].typename)==0) 	{ dtype_int2oid=types[a].type; }
	if (strcmp("int8",types[a].typename)==0) 	{ dtype_int8oid=types[a].type; }
	if (strcmp("float4",types[a].typename)==0) 	{ dtype_float4oid=types[a].type; }
	if (strcmp("float8",types[a].typename)==0) 	{ dtype_float8oid=types[a].type; }
	if (strcmp("text",types[a].typename)==0) 	{ dtype_textoid=types[a].type; }
	if (strcmp("bpchar",types[a].typename)==0) 	{ dtype_bpcharoid=types[a].type; }
	if (strcmp("varchar",types[a].typename)==0) 	{ dtype_varcharoid=types[a].type; }
	if (strcmp("timestamp",types[a].typename)==0) 	{ dtype_timestampoid=types[a].type; }
	if (strcmp("date",types[a].typename)==0) 	{ dtype_dateoid=types[a].type; }
	if (strcmp("numeric",types[a].typename)==0) 	{ dtype_numericoid=types[a].type; }
    }
	PQclear(res);
}

static int charcpy (unsigned char *target, unsigned char *source, long len,char delim)
{
  int rlen = 0;


  while (len)
    {
      int processed = 0;

      if (*source == '\\')
        {
          *target++ = '\\';
          *target = *source;
          target++;
          processed++;
        }


      if (!processed && *source == delim)
        {
          *target++ = '\\';
          *target = *source;
          target++;
          processed++;
        }

      if (!processed && (*source < ' ' || *source > '~'))
        {
          /*
 *            * Non-printable, convert to hex.
 *                       */
          target += SPRINTF1 ((char *) target, "\\%2.2x", *source);
          processed++;
        }

      if (!processed)
        {
          *target = *source;
          target++;
        }
      source++;
      len--;
      rlen++;
    }
  *target = (char) 0;
  rlen++;

  return rlen;
}

int A4GLSQLLIB_A4GLSQL_cancel ()
{
    return 1;
}

char *A4GLSQLLIB_A4GLSQL_fixup_descriptor(char *s) {
        return s;
}


/* =============================== EOF ============================== */

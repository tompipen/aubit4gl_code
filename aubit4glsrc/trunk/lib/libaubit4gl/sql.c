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
# $Id: sql.c,v 1.23 2004-12-04 09:21:45 mikeaubury Exp $
#
*/

#include "a4gl_libaubit4gl_int.h"
extern sqlca_struct a4gl_sqlca;


/*
=====================================================================
                    Variables definitions
=====================================================================
*/

//struct expr_str *A4GLSQL_get_validation_expr(char *tabname, char *colname);
/* typedef unsigned char UCHAR; in a4gl_dlsql.h */

/* list of open sessions - the current session is always first
 */
struct sess
{
  char sessname[64];
  char dbms_dialect[64];
  struct sess *next;
};
struct sess *curr_sess = NULL;

/* dialect of SQL currently being used in the 4GL program */
static char source_dialect[64] = "INFORMIX";

/* 'must_convert' tells us if we must try syntax conversion.
 * It is set if SQLCONVERT and the DBMS' dialect
 * differs from the 4GL source dialect.
 * */
static int must_convert = 0;


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

char *A4GL_global_A4GLSQL_get_sqlerrm (void);

extern void aclfgli_set_err_flg (void);

char *A4GL_apisql_strdup (char *sql);
void A4GL_apisql_add_sess (char *sessname);
void A4GL_apisql_set_sess (char *sessname);
void A4GL_apisql_drop_sess (char *sessname);
char *A4GL_apisql_dflt_dialect (void);
void A4GL_apisql_must_convert (void);
extern int A4GL_nullfunc (void);
int A4GLSQL_loadConnector (char *name);

void A4GL_global_A4GLSQL_set_sqlcode (int n);
void A4GLSQL_set_sqlerrm( char *m,char *p);
struct s_sid * A4GLSQL_prepare_select (struct BINDING *ibind, int ni,
    struct BINDING *obind, int no, char *s);
struct s_sid * A4GLSQL_prepare_glob_sql (char *s, int ni, struct BINDING *ibind);
void *A4GLSQL_prepare_glob_sql_internal (char *s, int ni, void  *ibind);
void *A4GLSQL_find_prepare (char *pname);
int A4GLSQL_add_prepare (char *pname, void *vsid);
/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * Assign a value to the status internal 4gl variable.
 *
 * @param a The value to assign to status.
 * @param sql A flag that indicate if the sqlca.sqlcode should be assigned.
 *   - 0 : Not SQL
 *   - Otherwise : SQL
 */
void
A4GLSQL_set_status (int a, int sql)
{
  A4GL_debug ("A4GLSQL_set_status(%d,%d)",a, sql);

 if ((!aclfgli_get_err_flg ()) || a>=0) {
  a4gl_status = a;

  if (sql)
    a4gl_sqlca.sqlcode = a;

  if (a != 0 ) { // || s!=0
    		aclfgli_set_err_flg ();
    }
  A4GL_debug ("Status set to %d", a);
} else {
	A4GL_debug("Status set to %d and errflg is set - not setting it to %d/%d",a4gl_status,a,sql);
}
}


void A4GLSQL_set_sqlerrm( char *m,char *p) {
static FILE *flog=0;
if (A4GL_isyes(acl_getenv("A4GL_LOGSQLERR")) && (strlen(m)||strlen(p))) {
	if (flog==0) {
		flog=fopen("/tmp/flog.err","a");
	}
	if (flog) {
		fprintf(flog,"%d - %s - %s\n",a4gl_sqlca.sqlcode,m,p);
	}
}
        A4GL_debug("A4GLSQL_set_sqlerrm('%s','%s')", m, p);
        if(!m || !p) {
          A4GL_debug("Nullpointer, doing nothing!");
          return;
        }
	strcpy(a4gl_sqlca.sqlerrm,m);
	strncpy(a4gl_sqlca.sqlerrp,p,8);
	a4gl_sqlca.sqlerrp[8]=0;
}	




void A4GLSQL_set_sqlerrd( int a0, int a1, int a2, int a3, int a4, int a5) {

        A4GL_debug("A4GLSQL_set_sqlerrd(%d,%d,%d,%d,%d,%d)", a0, a1, a2, a3, a4, a5);
	a4gl_sqlca.sqlerrd[0]=a0;
	a4gl_sqlca.sqlerrd[1]=a1;
	a4gl_sqlca.sqlerrd[2]=a2;
	a4gl_sqlca.sqlerrd[3]=a3;
	a4gl_sqlca.sqlerrd[4]=a4;

	if (A4GLSQLCV_check_requirement("SWAP_SQLCA62")) {
		a4gl_sqlca.sqlerrd[5]=a1;
	} else {
		a4gl_sqlca.sqlerrd[5]=a5;
	}
}

/**
 *
 *
 * @param
 * @return
 */
void
A4GLSQL_xset_status (int a)
{
  A4GL_debug ("A4GLSQL_xset_status(%d)",a);
  A4GLSQL_set_status (a, 0);
}

/**
 * Initialize a connection to the database.
 * This is the same as init_session("default", ... )
 *
 * Called by the generated C code to implement the DATABASE 4gl statement.
 *
 * @param dbName The database name.
 * @return
 */
int
A4GLSQL_init_connection (char *dbName)
{
int rc;
  rc = A4GLSQL_init_connection_internal(dbName);
  if (rc == 0) A4GL_apisql_add_sess ("default");
  return rc;
}

/**
 * Get the value of the 4gl status variable.
 *
 * @return The status value.
 */
int
A4GLSQL_get_status (void)
{
  A4GL_debug ("Status=%d sqlca.sqlcode=%d", a4gl_status, a4gl_sqlca.sqlcode);

  if (a4gl_status == 0 && a4gl_sqlca.sqlcode < 0)
    a4gl_status = a4gl_sqlca.sqlcode;

  return a4gl_status;
}







/**
 * Init a new connection to the database and associate with an explicit 
 * session name.
 *
 * @param sessname The name to be tied to the session.
 * @param dsn The data source name.
 * @param usr The user name to establish the connection.
 * @param pwd The password of the user to set the connection.
 */
int
A4GLSQL_init_session (char *sessname, char *dsn, char *usr, char *pwd)
{
  int rc;
  rc = A4GLSQL_init_session(sessname,dsn,usr,pwd);
  if (rc == 0) A4GL_apisql_add_sess (sessname);
  return rc;
}

/**
 * Sets the connection to use in the execution of the next SQL statement.
 *
 * @param sessname The session name.
 */
int
A4GLSQL_set_conn (char *sessname)
{
  int rc;
  rc = A4GLSQL_set_conn_internal (sessname);
  if (rc) A4GL_apisql_set_sess (sessname);
  return rc;
}


/**
 * Prepare a global SQL statement (not named).
 *
 * @param s A string with the SQL statement.
 * @param ni The number of input bind elements.
 * @param ibind A pointer to the input bind array.
 * @return A statement identification structure pointer.
 */
/* int -- struct s_sid * in sql.c */

#ifdef NO_LONGER_USED
struct s_sid *
A4GLSQL_prepare_glob_sql (char *s, int ni, struct BINDING *ibind)
{
  if (must_convert)
    {
	A4GL_debug("curr_sess->dbms_dialect=%s",curr_sess->dbms_dialect);
      s=A4GL_convert_sql_new (source_dialect, curr_sess->dbms_dialect, s);
    }
  return (struct s_sid *) A4GLSQL_prepare_glob_sql_internal (s, ni, ibind);
}
#endif


/**
 * Close a named connection.
 *
 * @param sessname The session/connection name.
 * @return
 *  - 0 : Connection closed.
 *  - 1 : Connection does not exist or error ocurred.
 */
int
A4GLSQL_close_session (char *sessname)
{
  int rc;
  rc = A4GLSQL_close_session_internal (sessname);
  if (rc) A4GL_apisql_drop_sess (sessname);
  return rc;
}



/**
 * Prepare an sql statement.
 *
 * @param s a string with the statement to be prepared.
 * @return
 */
/* int --- struct s_sid * in sql.c */
struct s_sid* A4GLSQL_prepare_sql (char *s)
{
  if (must_convert)
    {
      //s = A4GL_apisql_strdup (s);
	A4GL_debug("curr_sess->dbms_dialect=%s",curr_sess->dbms_dialect);
      s=A4GL_convert_sql_new (source_dialect, curr_sess->dbms_dialect, s);
    }
  return (struct s_sid *) A4GLSQL_prepare_select (0,0,0,0,s);
}



#ifdef NO_LONGER_USED
/**
 * Used from load.c
 *
 * @param prepared statement name.
 * @param ni Number of binded input parameters.
 * @param The input bind array.
 * @return Allways 0
 */
int
A4GLSQL_execute_sql_from_ptr (char *pname, int ni, char **ibind)
{
  return A4GLSQL_execute_sql_from_ptr_internal (pname, ni, *ibind);
}
#endif



/**
 * Prepare a select statement.
 *
 * @param ibind The input bind array.
 * @param ni Number of elements in the input bind array.
 * @param obind The output bind array.
 * @param no The number of elements in the output bind array.
 * @param s A string containing the select statement.
 * @return A pointer to the statement identification structure.
 */
/* int -- struct s_sid * in sql.c */
struct s_sid *
A4GLSQL_prepare_select (struct BINDING *ibind, int ni, struct BINDING *obind,
			int no, char *s)
{
	A4GL_debug("must_convert=%d\n",must_convert);
  if (must_convert)
    {
      //s = A4GL_apisql_strdup (s);
	A4GL_debug("curr_sess->dbms_dialect=%s",curr_sess->dbms_dialect);
      s=A4GL_convert_sql_new (source_dialect, curr_sess->dbms_dialect, s);
    }
  return (struct s_sid *) A4GLSQL_prepare_select_internal (ibind, ni, obind, no, s);
}





/**
 *
 *
 * @param
 * @return
 */
/* int -- void in sql;.c */
void
A4GLSQL_unload_data (char *fname, char *delims, char *sql1,int nbind,struct BINDING *ibind)
{
  if (must_convert)
    {
      //sql1 = A4GL_apisql_strdup (sql1);
	A4GL_debug("curr_sess->dbms_dialect=%s",curr_sess->dbms_dialect);
      sql1=A4GL_convert_sql_new (source_dialect, curr_sess->dbms_dialect, sql1);
    }
  A4GL_trim(fname);
  A4GLSQL_unload_data_internal (fname, delims, sql1,nbind,ibind);
}




/* moved here from nosql.c/sql.c to work around prblem with automatic exporting
of globals when making windows .dll
*/
/**
 *
 *
 * @param
 * @return
 */
char *
A4GL_global_A4GLSQL_get_sqlerrm (void)
{
  return a4gl_sqlca.sqlerrm;
}


void
A4GL_global_A4GLSQL_set_sqlcode (int n)
{
  a4gl_sqlca.sqlcode = n;
  a4gl_status = n;
}



/**
 * Set the dialect of SQL being used in the 4GL program,
 *
 * @param	char string, eg. "INFORMIX", "ORACLE", "SAPDB"
 */
void
A4GLSQL_set_dialect (char *dialect)
{
  A4GL_debug("set_dialect");
  if (dialect && (*dialect > 0))
    {
      strcpy (source_dialect, dialect);
    }
  else
    {
      strcpy (source_dialect, A4GL_apisql_dflt_dialect ());
    }
  A4GL_apisql_must_convert ();
}

/*======================= (private functions) ========================*/

/**
 * Make a copy of a SQL statement string, but with extra space
 * in case of any syntax conversions.  Somewhat like strdup().
 * The copy is malloc'ed and padded with spaces to its new length.
 * 
 * @param	pointer to original sql
 * @return	pointer to copy
 */
char *
A4GL_apisql_strdup (char *sql)
{
  char *p = NULL;
  int n1, n2;

  /* the copy is about 1.5 times the length of the original */
  n1 = strlen (sql);
  n2 = 20 + (n1 * 3 / 2);

  /* malloc space for the new string, copy it and pad with spaces */
  if ((p = malloc (n2 + 1)))
    {
      p = memcpy (memset (p, ' ', n2), sql, n1);
      p[n2] = '\0';
    }
  return p;
}

/**
 * Add the named session to the sessions list and make it current
 * 
 * @param	session name
 */
void
A4GL_apisql_add_sess (char *sessname)
{
  struct sess *next;
  next = curr_sess;
  A4GL_debug("Add session : %s\n",sessname);
  curr_sess = (struct sess *) malloc (sizeof (struct sess));
  strcpy (curr_sess->sessname, sessname);
  strcpy (curr_sess->dbms_dialect, A4GLSQL_dbms_dialect ());
  curr_sess->next = next;
  A4GL_apisql_must_convert ();
}

/**
 * Moves the named session to the front of the sessions list
 * 
 * @param	session name
 */
void
A4GL_apisql_set_sess (char *sessname)
{
  struct sess *p;
  struct sess *p2 = NULL;
  p2 = NULL;
  p = curr_sess;
  while (p != NULL)
    {

      if (strcmp (p->sessname, sessname) != 0)
	{
	  p2 = p;
	  p = p->next;
	  continue;
	}
	if (p2) {
      		p2->next = p->next;
	}
      p->next = curr_sess;
      curr_sess = p;
      A4GL_apisql_must_convert ();
      break;
    }
}

/**
 * Drop the named session from the sessions list
 * 
 * @param	session name
 */
void
A4GL_apisql_drop_sess (char *sessname)
{
  struct sess *p;
  struct sess *p2 = NULL;
  p = curr_sess;
  while (p != NULL)
    {
      if (strcmp (p->sessname, sessname) != 0)
	{
	  p2 = p;
	  p = p->next;
	  continue;
	}
      if (p2 == NULL)
	{
	  curr_sess = p->next;
	}
      else
	{
	  p2->next = p->next;
	}
      free (p);
      break;
    }
}

/**
 * Returns the default SQL dialect expected from the program,
 * which is either set from $SQLDIALECT, or is "INFORMIX"
 * 
 * @param	session name
 */
char *
A4GL_apisql_dflt_dialect (void)
{
  char *p;
  p = acl_getenv ("SQLDIALECT");
  if (p && *p > 0)
    return p;
  return "INFORMIX";
}

/**
 * Checks source and DBMS SQL dialects and determines
 * if we must convert
 * 
 * @param	session name
 */
void
A4GL_apisql_must_convert (void)
{

 A4GL_debug("Here");
  /* if no source dialect is set, use the default */
  if (*source_dialect == '\0')
    {
      strcpy (source_dialect, A4GL_apisql_dflt_dialect ());
    }
  /* SQLCONVERT=YES must be set, and source/DBMS dialects must differ
   */
  must_convert = 0;
	A4GL_debug("SQLCONVERT=%s source_dialect='%s' dbms_dialect='%s'",acl_getenv ("SQLCONVERT"),source_dialect,curr_sess->dbms_dialect);
  if (A4GL_isyes(acl_getenv ("SQLCONVERT")) && (source_dialect[0] > '\0') && (curr_sess->dbms_dialect[0] > '\0') &&
      (strcmp (curr_sess->dbms_dialect, source_dialect) != 0))
    {
	A4GL_debug("Setting Must convert");
      must_convert = 1;
    } else {
	A4GL_debug("Not setting must convert");
    }
}


int A4GLSQL_swap_bind_stmt(char *stmt, char t, char **sb,int *sc,void *bind, int cnt) {
struct s_sid *p;
p=A4GLSQL_find_prepare(stmt);
A4GL_debug("p=%p",p) ;
if (p) {
if (sb) {
	if (t=='i') { *sb=(char *)p->ibind; }
	if (t=='o') { *sb=(char *)p->obind; }
}
if (sc) {
	if (t=='i') { *sc=p->ni; }
	if (t=='o') { *sc=p->no; }
}
if (t=='i') { p->ibind=bind; p->ni=cnt; }
if (t=='o') { p->obind=bind; p->no=cnt; }
}
return 1;
}



int
A4GLSQL_add_prepare (char *pname, void *vsid)
{
  struct s_sid *sid;
  sid = vsid;
  if (sid)
    {
      A4GL_add_pointer (pname, PRECODE, sid);
      return 1;
    }
  else
    {
      return 0;
    }
}


/*
void*
A4GLSQL_prepare_glob_sql_internal (char *s, int ni, void  *ibind)
{
  return A4GLSQL_prepare_select (ibind, ni, (struct BINDING *) 0, 0, s);
}
*/

/*
void * A4GLSQL_prepare_sql (char *s)
{
  return A4GLSQL_prepare_select ((void *) 0, 0, (void *) 0, 0, s);
}
*/

int
A4GLSQL_execute_sql (char *pname, int ni, void *vibind)
{
  struct s_sid *sid;
  struct BINDING *ibind;
  ibind = vibind;
  A4GL_debug ("ESQL : A4GLSQL_execute_sql");
  sid = A4GLSQL_find_prepare (pname);	// ,0
  if (sid!=0) {
  	sid->ibind = ibind;
  	sid->ni = ni;
  	return A4GLSQL_execute_implicit_sql (sid);
  } else {
	A4GL_exitwith("Invalid prepared statement");
	return 0;
  }

}


/**
 *  * Find a prepared statement.
 *  *
 *  * There should be a global strucutre or array where to store all the
 *  * prepared statements.
 *  *
 *  * @todo : The mode should be used for something.
 *  *
 *  * @param pname The statement name.
 *  * @param mode
 *  * @return
 *  *   - A pointer to the structure found in the tree.
 *  *   - 0 : The structure was not found
 *  */
void *
A4GLSQL_find_prepare (char *pname)
{
  struct s_sid *ptr;

  A4GL_set_errm (pname);
  ptr = (struct s_sid *) A4GL_find_pointer_val (pname, PRECODE);
  if (ptr)
    return (void *) ptr;
  return (void *) 0;
//struct s_sid 
}




/* =============================== EOF ============================== */

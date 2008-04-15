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
# $Id: sql_common.c,v 1.54 2008-04-15 08:57:54 mikeaubury Exp $
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

char save_esql_session[256];

//char *find_table (struct s_select *select, struct s_select_list_item *i);

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

int A4GL_sqlid_encrypt (void);
char *A4GL_global_A4GLSQL_get_sqlerrm (void);

//extern int A4GL_nullfunc (void);
extern void aclfgli_set_err_flg (void);

char *A4GL_apisql_strdup (char *sql);
void A4GL_apisql_add_sess (char *sessname);
void A4GL_apisql_set_sess (char *sessname);
void A4GL_apisql_drop_sess (char *sessname);
char *A4GL_apisql_dflt_dialect (void);
void A4GL_apisql_must_convert (void);
int A4GLSQL_loadConnector (char *name);

void A4GL_global_A4GLSQL_set_sqlcode (int n);
void A4GLSQL_set_sqlerrm (char *m, char *p);


struct s_sid *A4GLSQL_prepare_glob_sql (char *s, int ni,
					struct BINDING *ibind);
void *A4GLSQL_prepare_glob_sql_internal (char *s, int ni, void *ibind);



//struct s_sid * A4GLSQL_prepare_select (struct BINDING *ibind, int ni,
//struct BINDING *obind, int no, char *s, int singleton);
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
 * @return
 *   - 1 : status was altered
 *   - 0 : status was not altered
 */
int
A4GLSQL_set_status (int a, int sql)
{
  if (aclfgli_get_err_flg() )
  {
      A4GL_debug("set_status: errflg is set - not setting new status %d", a);
      return 0;
  }

  A4GL_debug ("A4GLSQL_set_status(%d,%d)", a, sql);

  if ((!aclfgli_get_err_flg ()) || a >= 0)
    {
      a4gl_status = a;
      if (sql)
        a4gl_sqlca.sqlcode = a;

      if (a < 0)
	  aclfgli_set_err_flg ();
      A4GL_debug ("Status set to %d", a);
      return 1;
    }
  else
    {
      if (a4gl_status > 0)
	{
	  a4gl_status = a;
	  if (sql)
	    a4gl_sqlca.sqlcode = a;
	  return 1;
	}
      else
	{
	  A4GL_debug
	    ("Status set to %d and errflg is set - not setting it to %d/%d",
	     a4gl_status, a, sql);
	  return 0;
	}
    }
}


void A4GL_status_ok(int sql_too) {
	//
}

void
A4GLSQL_set_sqlerrm (char *m, char *p)
{
  static FILE *flog = 0;
  if (A4GL_isyes (acl_getenv ("A4GL_LOGSQLERR"))
      && (strlen (m) || strlen (p)))
    {
      if (flog == 0)
	{
	  flog = fopen ("/tmp/flog.err", "a");
	}
      if (flog)
	{
	  FPRINTF (flog, "%ld - %s - %s\n", a4gl_sqlca.sqlcode, m, p);
	}
    }
  A4GL_debug ("A4GLSQL_set_sqlerrm('%s','%s')", m, p);
  if (!m || !p)
    {
      A4GL_debug ("Nullpointer, doing nothing!");
      return;
    }
  strncpy (a4gl_sqlca.sqlerrm, m,sizeof(a4gl_sqlca.sqlerrm));
  a4gl_sqlca.sqlerrm[sizeof(a4gl_sqlca.sqlerrm)]=0;
  strncpy (a4gl_sqlca.sqlerrp, p, 8);
  a4gl_sqlca.sqlerrp[8] = 0;
}




void
A4GLSQL_set_sqlerrd (int a0, int a1, int a2, int a3, int a4, int a5)
{

  A4GL_debug ("A4GLSQL_set_sqlerrd(%d,%d,%d,%d,%d,%d)", a0, a1, a2, a3, a4, a5);
  a4gl_sqlca.sqlerrd[0] = a0;
  a4gl_sqlca.sqlerrd[1] = a1;
  a4gl_sqlca.sqlerrd[2] = a2;
  a4gl_sqlca.sqlerrd[3] = a3;
  a4gl_sqlca.sqlerrd[4] = a4;

  if (A4GLSQLCV_check_requirement ("SWAP_SQLCA62"))
    {
      a4gl_sqlca.sqlerrd[5] = a1;
    }
  else
    {
      a4gl_sqlca.sqlerrd[5] = a5;
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
  A4GL_debug ("A4GLSQL_xset_status(%d)", a);
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
  rc = A4GLSQL_init_connection_internal (dbName);
  if (rc == 0)
    A4GL_apisql_add_sess ("default");
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
  rc = A4GLSQL_init_session_internal (sessname, dsn, usr, pwd);
  if (rc == 0)
    A4GL_apisql_add_sess (sessname);
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
  if (rc)
    A4GL_apisql_set_sess (sessname);
  return rc;
}




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
  if (rc)
    A4GL_apisql_drop_sess (sessname);
  return rc;
}



#ifdef REMOVED_NO_LONGER_REQUIRED
/**
 * Prepare an sql statement.
 *
 * @param s a string with the statement to be prepared.
 * @return
 */
/* int --- struct s_sid * in sql.c */
struct s_sid *
XxxA4GLSQL_prepare_sql (char *s)
{
	A4GL_assertion(1,"FIXME");
  return (struct s_sid *) A4GLSQL_prepare_select (0, 0, 0, 0, s,"__prepare",0,0);
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
A4GLSQL_prepare_select (struct BINDING *ibind, int ni, struct BINDING *obind, int no, char *s,char *mod,int line,int converted, int singleton)
{
	char buff[256];
  char uniq_id[100];
  char *ptr;
  A4GL_debug ("must_convert=%d\n", must_convert);

  SPRINTF1(buff,"%s",mod);

  ptr=strchr(buff,'.');

  if (ptr) {
	 *ptr=0;
  }
  
  if (must_convert)
    {
      //s = A4GL_apisql_strdup (s);
      A4GL_debug ("curr_sess->dbms_dialect=%s", curr_sess->dbms_dialect);
      s = A4GL_convert_sql_new (source_dialect, curr_sess->dbms_dialect, s,converted);
    }
  SPRINTF2(uniq_id,"a4gl_st_%s_%d",buff,line);
  return (struct s_sid *) A4GLSQL_prepare_select_internal (ibind, ni, obind, no, s,uniq_id, singleton); 
}



/**
 *
 *
 * @param
 * @return
 */
/* int -- void in sql;.c */
void
A4GLSQL_unload_data (char *fname, char *delims, char *sql1, int nbind, struct BINDING *ibind,int converted)
{
  if (must_convert)
    {
      //sql1 = A4GL_apisql_strdup (sql1);
      A4GL_debug ("curr_sess->dbms_dialect=%s", curr_sess->dbms_dialect);
      sql1 =
	A4GL_convert_sql_new (source_dialect, curr_sess->dbms_dialect, sql1,converted);
    }
  A4GL_trim (fname);
  A4GLSQL_unload_data_internal (fname, delims, sql1, nbind, ibind);
}



/**
 *
 *
 * @param
 * @return
 */
/* int -- void in sql;.c */
char *
A4GLSQL_translate (char *sql1)
{
   char *s;
    s = A4GL_convert_sql_new (source_dialect, curr_sess->dbms_dialect, sql1,0);
	if (s) return s;
return sql1;
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
  A4GL_debug ("set_dialect");
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
  if ((p = acl_malloc2 (n2 + 1)))
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
  A4GL_debug ("Add session : %s\n", sessname);
  curr_sess = (struct sess *) acl_malloc2 (sizeof (struct sess));
  strcpy (curr_sess->sessname, sessname);
  strcpy (curr_sess->dbms_dialect, A4GLSQL_dbms_dialect ());
  curr_sess->next = next;
  A4GL_apisql_must_convert ();
}


int
A4GL_apisql_has_sess (char *sessname) {
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
	return 1;
    }
return 0;
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
    struct sess *pprev = NULL;
    struct sess *pprev_curr = NULL;

    p = curr_sess;
    while (p != NULL)
    {
	if (strcmp (p->sessname, sessname) == 0)
	{
	    if (pprev)
		pprev->next = p->next;
	    else
		break; // already on top
	    pprev_curr = curr_sess;
	    curr_sess = p;
	    curr_sess->next = pprev_curr;
	    break;
	}
	pprev = p;
	p = p->next;
    }
    A4GL_apisql_must_convert ();
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

  A4GL_debug ("Here");
  /* if no source dialect is set, use the default */
  if (*source_dialect == '\0')
    {
      strcpy (source_dialect, A4GL_apisql_dflt_dialect ());
    }
  /* SQLCONVERT=YES must be set, and source/DBMS dialects must differ
   */
  must_convert = 0;
  if (A4GL_compile_time_convert()==0) {
		return;
  }
  A4GL_debug ("SQLCONVERT=%s source_dialect='%s' dbms_dialect='%s'",
	      acl_getenv ("SQLCONVERT"), source_dialect,
	      curr_sess->dbms_dialect);
  if (A4GL_isyes (acl_getenv ("SQLCONVERT")) && (source_dialect[0] > '\0')
      && (curr_sess->dbms_dialect[0] > '\0')
      && ((strcmp (curr_sess->dbms_dialect, source_dialect) != 0)
	  || A4GL_isyes (acl_getenv ("ALWAYS_CONVERT"))))
    {
      A4GL_debug ("Setting Must convert");
      if (A4GLSQLCV_check_requirement ("NEVER_CONVERT"))
	{
	  must_convert = 0;
	}
      else
	{
	  must_convert = 1;
	}
    }
  else
    {
      A4GL_debug ("Not setting must convert");
    }
}


int
A4GLSQL_swap_bind_stmt (char *stmt, char t, char **sb, int *sc, void *bind,
			int cnt)
{
  struct s_sid *p;
  p = A4GLSQL_find_prepare (stmt);
  A4GL_debug ("p=%p", p);
  if (p)
    {
      if (sb)
	{
	  if (t == 'i')
	    {
	      *sb = (char *) p->ibind;
	    }
	  if (t == 'o')
	    {
	      *sb = (char *) p->obind;
	    }
	}
      if (sc)
	{
	  if (t == 'i')
	    {
	      *sc = p->ni;
	    }
	  if (t == 'o')
	    {
	      *sc = p->no;
	    }
	}
      if (t == 'i')
	{
	  p->ibind = bind;
	  p->ni = cnt;
	}
      if (t == 'o')
	{
	  p->obind = bind;
	  p->no = cnt;
	}
    }
  return 1;
}



int
A4GLSQL_add_prepare (char *pname, void *vsid)
{
  struct s_sid *sid;
  sid = vsid;


  //if (A4GL_has_pointer (pname, PRECODE))  {
	  //A4GLSQL_free_cursor(pname);
  //}


  if (sid)
    {
      char rname[256];
      A4GL_debug ("Adding prepare - %s - %p", pname, vsid);
      SPRINTF1 (rname, "%p", sid);
      A4GL_add_pointer (pname, PRECODE, sid);
      A4GL_add_pointer (rname, PRECODE_R, pname);
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
  return A4GLSQL_prepare_select (ibind, ni, (struct BINDING *) 0, 0, s,0);
}
*/

/*
void * A4GLSQL_prepare_sql (char *s)
{
  return A4GLSQL_prepare_select ((void *) 0, 0, (void *) 0, 0, s,0);
}
*/

int
A4GLSQL_execute_sql (char *pname, int ni, void *vibind)
{
  void *sid;
  struct BINDING *ibind;
  ibind = vibind;
  A4GL_debug ("ESQL : A4GLSQL_execute_sql");
  sid = A4GLSQL_find_prepare (pname);	// ,0
  
  if (sid != 0)
    {
      //sid->ibind = ibind;
      //sid->ni = ni;
      return A4GLSQL_execute_implicit_sql (sid, 0, ni, ibind);
    }
  else
    {
      A4GL_exitwith ("Invalid prepared statement");
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
  A4GL_debug ("Find prepare : %s\n", pname);
  A4GL_set_errm (pname);
  ptr = (struct s_sid *) A4GL_find_pointer_val (pname, PRECODE);
  if (ptr)
    {
      A4GL_debug ("Found it : %p", ptr);
      return (void *) ptr;
    }
  A4GL_debug ("Not found");
  return (void *) 0;
//struct s_sid 
}


#ifdef NDEF
/* 
 * This function takes a piece of SQL (normally from a PREPARE statement
 * and logs it to a file
 */
void
A4GL_log_sql_prepared (char *s)
{
  char *fname;
  FILE *fout;
  char buff[256];
  fname = acl_getenv ("LOGSQL");
  if (fname == 0)
    return;
  if (strlen (fname) == 0)
    return;

  // Firstly - MAPSQL should be a directory...
  SPRINTF3 (buff, "%s/%s_%d.log", fname, A4GL_get_running_program (),
	    getpid ());
  fout = fopen (buff, "a");
  if (fout == 0)
    {				// Maybe - its just a file ?
      SPRINTF1 (buff, "%s", fname);
      fout = fopen (buff, "a");
    }
  if (fout == 0)
    return;
  // if we've got to here - we've got a file to write to...
  //
  FPRINTF (fout, "%s\n", s);
  fclose (fout);
}
#endif

void
A4GL_log_sql_prepared_map (char *s)
{
  static char logfname[256] = "<not_set>";
  static int logfnameset = 0;
  char *fname = 0;
  FILE *fout = 0;
  char buff[256];


  if (logfnameset == -1)
    return;

  fname = acl_getenv ("MAPSQL");
  if (fname == 0)
    {
      logfnameset = -1;
      return;
    }
  if (strlen (fname) == 0)
    {
      logfnameset = -1;
      return;
    }

  if (logfnameset == 1)
    {
      fout = fopen (logfname, "a");
      if (fout == 0)
	return;			// should have been able to ... very odd..
    }

  if (logfnameset == 0)
    {
      // Firstly - MAPSQL should be a directory...
      SPRINTF3 (buff, "%s/%s_%d.map", fname, A4GL_get_running_program (),
		getpid ());
      fout = fopen (buff, "a");
      if (fout == 0)
	{			// Maybe - its just a file ?
	  SPRINTF1 (buff, "%s", fname);
	  fout = fopen (buff, "a");
	}
      if (fout == 0)
	{
	  logfnameset = -1;
	  return;
	}

      // buff should be our current file - so copy it into out stored name
      logfnameset = 1;
      strcpy (logfname, buff);
    }

  A4GL_assertion (fout == 0, "fout not set - shouldn't happen");
  // if we've got to here - we've got a file to write to...
  //
  FPRINTF (fout, "%s\n", s);
  fclose (fout);
}



char *
A4GLSQLCV_convert_sql (char *target_dialect, char *sql)
{
  return A4GLSQLCV_convert_sql_ml (target_dialect, sql, "unknown", 0);
}


/* Create a s_table structure holding a tablename and its alias */
struct s_table *
A4GLSQLPARSE_new_tablename (char *tname, char *alias)
{
  struct s_table *ptr;

  ptr = acl_malloc2 (sizeof (struct s_table));
  ptr->tabname = acl_strdup (tname);
  if (alias)
    {
      ptr->alias = acl_strdup (alias);
    }
  else
    {
      ptr->alias = 0;
    }
  ptr->next = 0;
  ptr->outer_next = 0;
  ptr->outer_type = E_OUTER_NONE;
  ptr->outer_join_condition = NULL;
  return ptr;
}



/* Add a table structure to a structure representing the FROM clause of a select */
struct s_table *
A4GLSQLPARSE_append_tablename (struct s_table *t1, struct s_table *t2, e_outer_type is_outer,struct s_select_list_item *outer_join_condition)
{
  struct s_table *p;
  struct s_table *o;
  p = t1;

  if (is_outer)
    {
      o = A4GLSQLPARSE_new_tablename ("@", "@");
      o->outer_next = t2;
	o->outer_type=is_outer;
	o->outer_join_condition=outer_join_condition;
      o->next = 0;
      t2 = o;
    }

  while (t1->next)
    t1 = t1->next;
  t1->next = t2;
  //t1->outer_type=E_OUTER_NONE;


  return p;
}

/*
 * In order to make processing of the SQL select statement easier - we want to keep a flat
 * list of all the tables we've encountered in our SQL statement
 * 
*/

struct s_table_list *
A4GLSQLPARSE_add_table_to_table_list (struct s_table_list *tl, char *t,
				      char *a)
{
  if (tl == 0)
    {
      tl = acl_malloc2 (sizeof (struct s_table_list));
      tl->tables.tables_len = 0;
      tl->tables.tables_val = 0;
    }
  tl->tables.tables_len++;
  tl->tables.tables_val = acl_realloc (tl->tables.tables_val, sizeof (struct s_table_list_element) * tl->tables.tables_len);
  tl->tables.tables_val[tl->tables.tables_len - 1].tabname = 0;
  tl->tables.tables_val[tl->tables.tables_len - 1].alias = 0;
  if (t)
    {
      tl->tables.tables_val[tl->tables.tables_len - 1].tabname = acl_strdup (t);
    }
  if (a)
    {
      tl->tables.tables_val[tl->tables.tables_len - 1].alias = acl_strdup (a);
    }
  return tl;
}

/* Generate the string representing the FROM clause for a SELECT */
int
A4GLSQLPARSE_from_clause_collect_tables (struct s_select *select,
					 struct s_table *t,
					 struct s_table_list *tl)
{
  int a = 0;

  while (t)
    {
      /* A tablename of '@' is a placeholder for an outer - so we don't need
       * to print it...
       * */
      if (strcmp (t->tabname, "@") != 0)
	{
	  A4GLSQLPARSE_add_table_to_table_list (tl, t->tabname, t->alias);
	  a++;
	}

      if (t->outer_next)
	{
	  A4GLSQLPARSE_from_clause_collect_tables (select, t->outer_next, tl);
	}
      t = t->next;
    }
  return 1;
}




int
A4GLSQLPARSE_from_outer_clause (struct s_select *select, char *left,
				struct s_table *t, char *fill,
				struct s_table_list *tl)
{
  char buff[2000];
  int a = 0;
  char outer[2000];
  char join[2000];

  strcpy (buff, "");

  if (strcmp (t->tabname, "@") != 0)
    {
      if (a)
	strcat (buff, ",");
      strcat (buff, A4GLSQLCV_make_tablename (t->tabname, t->alias));
      a++;
    }

  SPRINTF1 (buff, " %s", t->tabname);
  a++;
  strcpy (outer, "");

  strcpy (join, "");
  for (a = 0; a < select->list_of_items.list.list_len; a++)
    {
      if (select->list_of_items.list.list_val[a]->data.type == E_SLI_JOIN)
	{
	  struct s_select_list_item *p;
	  struct s_select_list_item *l;
	  struct s_select_list_item *r;
	  char *lt;
	  char *rt;
	  p = select->list_of_items.list.list_val[a];
	  l = p->data.s_select_list_item_data_u.complex_expr.left;
	  r = p->data.s_select_list_item_data_u.complex_expr.right;
	  lt = l->data.s_select_list_item_data_u.column.tabname;
	  rt = r->data.s_select_list_item_data_u.column.tabname;

	  if (strcmp (t->tabname, lt) == 0 && strcmp (left, rt) == 0)
	    {
	      char tmpbuff[256];
	      SPRINTF4 (tmpbuff, " ON %s.%s=%s.%s",
			l->data.s_select_list_item_data_u.column.tabname,
			l->data.s_select_list_item_data_u.column.colname,
			r->data.s_select_list_item_data_u.column.tabname, r->data.s_select_list_item_data_u.column.colname);
	      if (strlen (join))
		strcat (join, " AND ");
	      strcat (join, tmpbuff);
	      p->data.type = E_SLI_BUILTIN_CONST_TRUE;

	    }

	  if (strcmp (t->tabname, rt) == 0 && strcmp (left, lt) == 0)
	    {
	      char tmpbuff[256];
	      SPRINTF4 (tmpbuff, " ON %s.%s=%s.%s",
			l->data.s_select_list_item_data_u.column.tabname,
			l->data.s_select_list_item_data_u.column.colname,
			r->data.s_select_list_item_data_u.column.tabname, r->data.s_select_list_item_data_u.column.colname);
	      if (strlen (join))
		strcat (join, " AND ");
	      strcat (join, tmpbuff);
	      p->data.type = E_SLI_BUILTIN_CONST_TRUE;
	    }
	}
    }
  strcat (buff, join);
  strcpy (fill, buff);


  return 1;
}



// Debugging routing to print the where clause out...
static void A4GL_print_from_clause(struct s_table *t,int lvl) {
int a;
for (a=0;a<lvl;a++) { printf("   "); }
printf("%s\n", t->tabname);
if (t->outer_next) {
	for (a=0;a<lvl;a++) { printf("   "); }
	
	printf("=>");
	A4GL_print_from_clause(t->outer_next,lvl+1);
}
if (t->next) {
	for (a=0;a<lvl;a++) { printf("   "); }
	printf("->");
	A4GL_print_from_clause (t->next,lvl+1);
}
printf("\n");
}


/* Generate the string representing the FROM clause for a SELECT */
int
A4GLSQLPARSE_from_clause (struct s_select *select, struct s_table *t, char *fill, struct s_table_list *tl)
{
  char buff[2000];
  char lastt[2000];
  int a = 0;

  if (A4GLSQLCV_check_requirement ("FIX_OUTER_JOINS"))
    {
      a = A4GLSQLPARSE_from_clause_join (select, t, fill, tl);
 	if (a==0) {
			printf("Cant do :\n");
			A4GL_print_from_clause(t,0);
	}
    }

  if (a)
    return a;

  strcpy (buff, "");

  while (t)
    {
      /* A tablename of '@' is a placeholder for an outer - so we don't need
       * to print it...
       * */
      if (strcmp (t->tabname, "@") != 0)
	{
	  if (a)
	    strcat (buff, ",");
	  strcat (buff, A4GLSQLCV_make_tablename (t->tabname, t->alias));
	  a++;
	}

      if (t->outer_next)
	{
	  switch (t->outer_type)
	    {
	    case E_OUTER_NONE:	
		{
		char outer[2000];
		A4GLSQLPARSE_from_clause (select, t->outer_next, outer, tl);
			strcat(buff,outer);
		}
	      break;

	    case E_OUTER_NORMAL:
	      {
		char outer[2000];
		if (a)
		  strcat (buff, ",");
		a++;
		strcpy (outer, "");
		A4GLSQLPARSE_from_clause (select, t->outer_next, outer, tl);
		strcat (buff, " OUTER (");
		strcat (buff, outer);
		strcat (buff, ")");
		break;
	      }

	    case E_OUTER_LEFT_OUTER:
	      {
		char outer[2000];
		char *ptr;
/*
	      if (a)
		strcat (buff, ",");
*/

		a++;
		strcpy (outer, "");
		A4GLSQLPARSE_from_clause (select, t->outer_next, outer, tl);
		strcat (buff, " LEFT OUTER JOIN (");
		strcat (buff, outer);
		ptr = get_select_list_item (select, t->outer_join_condition);
		if (t->outer_join_condition->data.type==E_SLI_BRACKET_EXPR) {
			strcat (buff, ") ON ");
			strcat (buff, ptr);
	
		} else {
			strcat (buff, ") ON (");
			strcat (buff, ptr);
			strcat (buff, ")");
		}
			acl_free (ptr);
		break;
	      }

	    default:
	      A4GL_assertion (1, "OUTER JOIN situtation not handled");

	    }
	}
      strcpy (lastt, t->tabname);
      t = t->next;
    }
  strcpy (fill, buff);
  return 1;
}

int
A4GLSQL_read_columns (char *tabname, char *xcolname, int *dtype, int *size)
{
  char *buff;
  int rval = 0;
  char cname[2000];
  strcpy (cname, xcolname);
  A4GL_trim (cname);

  A4GL_debug ("READ COLUMNS\n");

  if (A4GLSQL_get_columns (tabname, cname, dtype, size))
    {

      while (A4GLSQL_next_column (&buff, dtype, size))
	{
	  char b2[2000];
	  strcpy (b2, buff);
	  A4GL_trim (b2);
	  if (strcasecmp (cname, b2) == 0)
	    {
	      rval = 1;
	      break;
	    }
	}

      A4GLSQL_end_get_columns ();
    }

  // NCHAR ? 
  if (*dtype == DTYPE_NCHAR)
    *dtype = DTYPE_CHAR;
  return rval;
}



int
A4GL_sqlid_from_aclfile (char *dbname, char *uname, char *passwd)
{
  FILE *f;
  char fname[256];
  char buff[300];
  char *ptr_fields[3];
  char *ptr;
  char *ptr_next;


  // First off - lets make sure the file is encrypted...
  A4GL_sqlid_encrypt();

  ptr = acl_getenv_not_set_as_0 ("A4GL_SQLACL");
	if (ptr) {
		if (!A4GL_file_exists(ptr)) ptr=0;
	}

  if (ptr==0) {
		ptr = acl_getenv_not_set_as_0 ("A4GL_ACLFILE");
		if (ptr) {
			if (!A4GL_file_exists(ptr)) ptr=0;
		}
  }

  if (ptr == 0)
    {
#if defined( __MINGW32__ ) || defined(MSVC)
      if (strlen (fname) == 0)
	{
		char *aubitdir;
		aubitdir=acl_getenv("AUBITDIR");
		if (aubitdir) {
			if (strlen(aubitdir)) {
				strcpy(fname,aubitdir);
				strcat(fname,"/etc/aubit4gl.acl");
			}
		}
	  	if (strlen(fname)==0) {
			strcpy (fname, "c:\\aubit4gl\\aubit4gl.acl");
		}
	}
#else
      strcpy (fname, acl_getenv ("HOME"));
      if (strlen (fname) == 0)
	{
	  strcpy (fname, "/etc/aubit4gl.acl");
	}
      else
	{
	  strcat (fname, "/.aubit4gl.acl");
	}
#endif
    }
  else
    {
      strcpy (fname, ptr);
    }
  f = fopen (fname, "r");
  if (f == 0)
    return 0;

  while (1)
    {
      if (!fgets (buff, 256, f))
	break;
      A4GL_debug ("Read : %s\n", buff);
      ptr = strchr (buff, '#');
      if (ptr)
	{
	  *ptr = 0;
	}
      ptr = strchr (buff, '\n');
      if (ptr)
	{
	  *ptr = 0;
	}
      ptr = &buff[0];

      // File should contain fields like this :
      // dbname:username:passwd
      ptr_next = strchr (buff, ':');	// end of dbname

      ptr_fields[0] = 0;
      ptr_fields[1] = 0;
      ptr_fields[2] = 0;

      ptr_fields[0] = &buff[0];
      if (ptr_next != 0)
	{
	  *ptr_next = 0;
	  A4GL_debug ("compare dbname : %s to %s\n", buff, dbname);
	  if (strcmp (buff, dbname) != 0)
	    {
	      continue;
	    }

	  ptr = ptr_next + 1;

	  ptr_fields[1] = ptr;

	  ptr_next = strchr (ptr, ':');	// end of username

	  if (ptr_next != 0)
	    {
	      *ptr_next = 0;
	      ptr = ptr_next + 1;
	      ptr_fields[2] = ptr;

	      ptr_next = strchr (ptr, ':');	// chances are this isn't there...

	      if (ptr_next != 0)
		{
		  *ptr_next = 0;
		  ptr = ptr_next + 1;
		}

	      // if we've got to here - we've got the username as password..
	      A4GL_debug ("uname=%s passwd=%s", ptr_fields[1], ptr_fields[2]);
	      strcpy (uname, ptr_fields[1]);
	      strcpy (passwd, ptr_fields[2]);
	      if (passwd[0] == '!')
		{
		  char buff[256];
		  strcpy (buff, A4GL_tea_string_decipher (&passwd[1]));
		  strcpy (passwd, buff);
		}
	      fclose (f);
	      return 1;
	    }

	}

    }
  fclose (f);
  return 0;
}



int
A4GL_sqlid_encrypt (void)
{
  FILE *f;
  char fname[256];
  char buff[300];
  char buff_orig[300];
  char *ptr_fields[3];
  char *ptr;
  char *ptr_next;
  int printed = 0;
  FILE *fout;
  ptr = acl_getenv_not_set_as_0 ("A4GL_SQLACL");

  if (ptr==0) {
		ptr = acl_getenv_not_set_as_0 ("A4GL_ACLFILE");
		if (ptr) {
			if (!A4GL_file_exists(ptr)) ptr=0;
		}
  }



  if (ptr == 0)
    {
#if defined( __MINGW32__ ) || defined(MSVC)
      if (strlen (fname) == 0)
	{
	  strcpy (fname, "c:\\aubit4gl\\aubit4gl.acl");
	}
#else
      strcpy (fname, acl_getenv ("HOME"));
      if (strlen (fname) == 0)
	{
	  strcpy (fname, "/etc/aubit4gl.acl");
	}
      else
	{
	  strcat (fname, "/.aubit4gl.acl");
	}
#endif
    }
  else
    {
      strcpy (fname, ptr);
    }
  f = fopen (fname, "r");

  if (f == 0)
    return 0;

  fout = fopen ("encrypted.aclfile", "w");
  if (fout == 0)
    {
      return 0;
    }

  while (1)
    {
      printed = 0;

      if (!fgets (buff, 256, f))
	break;

      strcpy (buff_orig, buff);

      A4GL_debug ("Read : %s\n", buff);
      ptr = strchr (buff, '#');
      if (ptr)
	{
	  *ptr = 0;
	}
      ptr = strchr (buff, '\n');
      if (ptr)
	{
	  *ptr = 0;
	}
      ptr = &buff[0];
      // File should contain fields like this :
      // dbname:username:passwd
      ptr_next = strchr (buff, ':');	// end of dbname

      ptr_fields[0] = 0;
      ptr_fields[1] = 0;
      ptr_fields[2] = 0;

      ptr_fields[0] = &buff[0];

      if (ptr_next != 0)
	{
	  *ptr_next = 0;
	  ptr = ptr_next + 1;
	  ptr_fields[1] = ptr;
	  ptr_next = strchr (ptr, ':');	// end of username
	  if (ptr_next != 0)
	    {
	      char uname[256];
	      char passwd[256];
	      *ptr_next = 0;
	      ptr = ptr_next + 1;
	      ptr_fields[2] = ptr;

	      ptr_next = strchr (ptr, ':');	// chances are this isn't there...

	      if (ptr_next != 0)
		{
		  *ptr_next = 0;
		  ptr = ptr_next + 1;
		}

	      // if we've got to here - we've got the username as password..
	      A4GL_debug ("uname=%s passwd=%s", ptr_fields[1], ptr_fields[2]);
	      strcpy (uname, ptr_fields[1]);
	      strcpy (passwd, ptr_fields[2]);
	      if (passwd[0] != '!')
		{
		  char buff[256];
		  strcpy (buff, A4GL_tea_string_encipher (passwd));
		  SPRINTF1 (passwd, "!%s", buff);
		}
	      printed = 1;
	      FPRINTF (fout,"%s:%s:%s\n", ptr_fields[0], uname, passwd);
	    }
	}

      if (!printed)
	{
	  // Don't recognise it - put back what we got  in
	  FPRINTF (fout, "%s", buff_orig);
	}


    }

  fclose (fout);
  fclose (f);

  if (unlink(fname)==0) { // All good!
  	rename("encrypted.aclfile",fname);
  } else {
	A4GL_exitwith("Unable to remove original ACL file");
	return 0;
  }

  return 1;
}


char *A4GL_get_esql_connection(void) {
	return save_esql_session;
}

void A4GL_set_esql_connection(char *s) {
	strcpy(save_esql_session,s);
}


/*
struct s_select_list *A4GLSQLPARSE_new_select_list_str(char *expr,char *alias) {
	struct s_select_list *ptr;
	ptr=malloc(sizeof(struct s_select_list));
	ptr->type=0;
	ptr->data.s_select_list_item_data_u.expression=strdup(expr);
	if (alias) {
		ptr->alias=strdup(alias);
	} else {
		ptr->alias=0;
	}
	return ptr;
}
*/



/*
*/

int A4GL_ESQL_cursor_is_open(char *s) {
	if (A4GL_has_pointer(s,ESQL_CURSOR_OPEN)) {
		return 1;
	}
return 0;

}

void A4GL_ESQL_set_cursor_is_open(char *s) {
	if (!A4GL_has_pointer(s,ESQL_CURSOR_OPEN)) {
		A4GL_add_pointer(s,ESQL_CURSOR_OPEN,(void *)1);
	}
}

void A4GL_ESQL_set_cursor_is_closed(char *s) {
	if (A4GL_has_pointer(s,ESQL_CURSOR_OPEN)) {
		A4GL_del_pointer(s,ESQL_CURSOR_OPEN);
	}
}









char *A4GL_get_syscolatt(char *tabname,char *colname,int seq, char *attr) {
      static int cntsql_0 = 0;
      char cname[256];
      static char tmpvar[256];
	int tmpvar_i;
      char tmpSql[2000];
	char syscolatt[2000];
	int cnt=0;


      struct BINDING ibind_str[] = {
	{&tmpvar, 0, 255,0,0,0}
      };			/* end of binding */
      struct BINDING ibind_int[] = {
	{&tmpvar_i, 2, 0,0,0,0}
      };			/* end of binding */

	strcpy(syscolatt, acl_getenv("A4GL_SYSCOL_ATT"));

      SPRINTF1 (cname, "chkscatt_%d", cntsql_0++);
      sprintf(tmpSql,"select %s.%s from %s WHERE tabname='%s' AND colname='%s' ORDER BY seqno",syscolatt, attr,syscolatt,tabname,colname);

      A4GLSQL_declare_cursor (0,(void *) A4GLSQL_prepare_select (NULL, 0, NULL, 0, tmpSql,"__internal_stack",1,0,0), 0, cname);
      
      if (a4gl_status != 0)
	{
		return 0;
	}
      A4GLSQL_set_sqlca_sqlcode (0);
      A4GLSQL_open_cursor (cname,0,0);
      if (a4gl_status != 0)
	{
	return 0;
	}
	cnt=0;

      while (1)
	{
		strcpy(tmpvar,"");
		if (strcmp(attr,"color")==0) {
	  		A4GLSQL_fetch_cursor (cname, 2, 1, 1, ibind_int);
		} else {
	  		A4GLSQL_fetch_cursor (cname, 2, 1, 1, ibind_str);
		}
	  	if (a4gl_status != 0) break;
	  	if (cnt==seq) {
			A4GL_trim(tmpvar);
			if (strcmp(attr,"color")==0) {
				sprintf(tmpvar,"%d",tmpvar_i);
			}
			//printf("%s-->%s\n",attr, tmpvar);
			return tmpvar;
		}
	  cnt++;
	}

      return 0;
    }

// ================================ EOF ================================

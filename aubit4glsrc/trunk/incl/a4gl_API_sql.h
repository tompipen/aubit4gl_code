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
# $Id: a4gl_API_sql.h,v 1.16 2003-07-09 16:19:00 mikeaubury Exp $
#
*/

/**
 * @file
 *
 * Header with prototypes of Dynamic Libraries loading for sql API access functions (API_sql.c)
 *
 */

/* all SQL drivers define there own UCHAR - maybe we should not
define it in any case? */
#ifndef __UCHAR_DEFINED__
#define __UCHAR_DEFINED__
typedef unsigned char UCHAR;
#endif


#ifndef DLSQLDEF_INCL
#define DLSQLDEF_INCL

/* ==================== from a4gl_database.h ============== */

#ifdef __cplusplus
extern "C"
{
#endif
	/**
	 * An SQL statement identification structure.
	 */
  struct s_sid
  {
    struct BINDING *ibind;		    /**< The input bind array */
    struct BINDING *obind;		    /**< The output bind array */
    int ni;				    /**< Number of elements in the input bind array*/
    int no;				    /**< Number of elements in the output bind array*/
    char *inputDescriptorName;		    /**< Name of input descriptor (ESQL) */
    char *outputDescriptorName;		    /**< Name of output descriptor (ESQL) */
    char *select;			    /**< The SQL statement content */
    void *hstmt;			    /**< A pointer to the statement handle */
    char *statementName;		    /**< The name of the SQL statement */
  };

	/** A better name to the statement descriptor structure */
  typedef struct s_sid A4glStatememnt;


	/**
	 * The cursor identification structure.
	 */
  struct s_cid
  {
    struct s_sid *statement;	    /**< The statement used to declare the cursor */
    int mode;			    /**< The cursor mode */
    void *hstmt;		    /**< A pointer to the satetement handle */
  };

	/** A better name to the cursor descriptor */
  typedef struct s_cid A4glCursor;

  int A4GLSQL_initlib (void);
  int A4GLSQL_initsqllib (void);	/* << from sql.c */
  void A4GLSQL_xset_status (int a);
  int A4GLSQL_init_connection (char *dbName);
  int A4GLSQL_get_status (void);
  char *A4GLSQL_get_curr_conn (void);
  char *A4GLSQL_get_sqlerrm (void);
  int A4GLSQL_read_columns (char *tabname, char *colname, int *dtype,
			    int *size);
  int A4GLSQL_make_connection (UCHAR * server, UCHAR * uid_p, UCHAR * pwd_p);
  int A4GLSQL_get_datatype (char *db, char *tab, char *col);
  int A4GLSQL_init_session (char *sessname, char *dsn, char *usr, char *pwd);
  int A4GLSQL_set_conn (char *sessname);
  char *A4GLSQL_dbms_name (void);
  char *A4GLSQL_dbms_dialect (void);
  void A4GLSQL_set_dialect (char *dialect);
  int A4GLSQL_close_session (char *sessname);
  int A4GLSQL_add_prepare (char *pname, struct s_sid *sid);
  int A4GLSQL_open_cursor (int ni, char *s);
  void A4GLSQL_put_insert (struct BINDING *ibind, int n);
  void A4GLSQL_unload_data (char *fname, char *delims, char *sql1,int nbind,struct BINDING *ibind);
  void A4GLSQL_commit_rollback (int mode);
  void A4GLSQL_flush_cursor (char *cursor);
  char *A4GLSQL_get_currdbname (void);
  int A4GLSQL_execute_sql (char *pname, int ni, struct BINDING *ibind);
  long A4GLSQL_describe_stmt (char *stmt, int colno, int type);
  int A4GLSQL_end_get_columns (void);
  int A4GLSQL_next_column (char **colname, int *dtype, int *size);
  int A4GLSQL_get_columns (char *tabname, char *colname, int *dtype,
			   int *size);
  void A4GLSQL_set_status (int a, int sql);
  void A4GLSQL_set_sqlerrd(int a0,int a1,int a2,int a3,int a4,int a5);
  int A4GLSQL_close_cursor (char *cname);

  int A4GLSQL_execute_implicit_sql (struct s_sid *sid);
  int A4GLSQL_execute_sql_from_ptr (char *pname, int ni, char **ibind);
  int A4GLSQL_execute_implicit_select (struct s_sid *sid);
  void A4GLSQL_set_sqlca_sqlcode (int a);

  struct s_sid *A4GLSQL_prepare_glob_sql (char *s, int ni,
					  struct BINDING *ibind);
  struct s_sid *A4GLSQL_find_prepare (char *pname);
  struct s_sid *A4GLSQL_prepare_sql (char *s);
  struct s_sid *A4GLSQL_prepare_select (struct BINDING *ibind, int ni,
					struct BINDING *obind, int no,
					char *s);
  struct s_cid *A4GLSQL_declare_cursor (int upd_hold, struct s_sid *sid,
					int scroll, char *cursname);

  int A4GLSQL_fetch_cursor (char *cursor_name, int fetch_mode, int fetch_when,
			    int nibind, struct BINDING *ibind);

  int A4GLSQL_fill_array (int mx, char *arr1, int szarr1,
			  char *arr2, int szarr2, char *service, int mode,
			  char *info);

  // used only in Informix ESQL plug-in
  int A4GLSQL_close_connection (void);

/* ======================= sqlconvert.c ==================== */

  void A4GL_convert_sql (char *source_dialect, char *target_dialect, char *sql);

#ifdef __cplusplus
}
#endif
#endif				/* ifndef DLSQLDEF_INCL */

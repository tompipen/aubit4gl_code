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
# $Id: a4gl_API_sql.h,v 1.3 2002-08-13 11:56:48 afalout Exp $
#
*/

/**
 * @file
 *
 * Header with prototypes of Dynamic Libraries loading for sql API access functions (API_sql.c)
 *
 */


/*
In file included from /usr/include/sql.h:17,
                 from sql.c:74:
/usr/include/sqltypes.h:149: redefinition of `UCHAR'
../../libincl/a4gl_dlsql.h:39: `UCHAR' previously declared here

typedef unsigned char UCHAR;
*/

/*
In file included from ../../libincl/a4gl_dlsql.h:48,
                 from sql.c:93:
/usr/include/sqltypes.h:40: conflicting types for `HWND'
/opt/informix/incl/cli/infxsql.h:90: previous declaration of `HWND'
/usr/include/sqltypes.h:41: redefinition of `CHAR'
/opt/informix/incl/cli/infxsql.h:113: `CHAR' previously declared here
/usr/include/sqltypes.h:45: redefinition of `TCHAR'
/opt/informix/incl/cli/infxsql.h:117: `TCHAR' previously declared here
...etc... so we cannot include sqltypes.h here !

#include "sqltypes.h" --defines UCHAR
*/

/* all SQL drivers define there own UCHAR - maybe we should not
define it in any case? */
#ifndef __UCHAR_DEFINED__
#define __UCHAR_DEFINED__
	typedef unsigned char UCHAR;
#endif


#ifndef DLSQLDEF_INCL
#define DLSQLDEF_INCL

	int A4GLSQL_initlib (void);
	/* void A4GLSQL_set_status (int a, int sql); -- moved to a4gl_aubit_lib since it is used extensively, and not only in SQL API */

	int A4GLSQL_initsqllib(void); 			/* << from sql.c */
	void A4GLSQL_xset_status(int a);
	int A4GLSQL_init_connection   (char *dbName);
	int A4GLSQL_get_status   (void);
	char * A4GLSQL_get_curr_conn (void);
	char *A4GLSQL_get_sqlerrm (void);


	int A4GLSQL_read_columns(char *tabname, char *colname, int *dtype, int *size);
	int A4GLSQL_make_connection(UCHAR * server, UCHAR * uid_p, UCHAR * pwd_p);
	int A4GLSQL_get_datatype   (char *db, char *tab, char *col);
	int A4GLSQL_init_session   (char *sessname, char *dsn, char *usr, char *pwd);
	int A4GLSQL_set_conn   (char *sessname);
    struct s_sid * A4GLSQL_prepare_glob_sql (char *s, int ni, struct BINDING *ibind);



	int A4GLSQL_execute_implicit_sql   (struct s_sid *sid);
	int A4GLSQL_close_session   (char *sessname);
	int A4GLSQL_fill_array     (int mx, char **arr1, int szarr1,
	  char **arr2, int szarr2, char *service, int mode, char *info  
	);
	struct s_sid * A4GLSQL_prepare_sql (char *s);

	int A4GLSQL_add_prepare   (char *pname, struct s_sid *sid);
	int A4GLSQL_execute_sql_from_ptr   (char *pname, int ni, char **ibind);
	int A4GLSQL_execute_implicit_select   (struct s_sid *sid);

	struct s_sid *
	A4GLSQL_prepare_select (
	      struct BINDING *ibind, int ni, struct BINDING *obind, int no, char *s);

	struct s_cid *
	A4GLSQL_declare_cursor(int upd_hold,struct s_sid *sid,int scroll,char *cursname);

	void A4GLSQL_set_sqlca_sqlcode(int a);
	int A4GLSQL_open_cursor   (int ni, char *s);
	int A4GLSQL_fetch_cursor(
		char *cursor_name, int fetch_mode, int fetch_when, 
		int nibind, struct BINDING *ibind
	);
	void A4GLSQL_put_insert(struct BINDING *ibind,int n);
	void A4GLSQL_unload_data(char *fname,char *delims, char *sql1);
	void A4GLSQL_commit_rollback (int mode);
	struct s_sid * 	A4GLSQL_find_prepare (char *pname);
	void A4GLSQL_flush_cursor(char *cursor);
	char *A4GLSQL_get_currdbname(void);
	int A4GLSQL_execute_sql   (char *pname, int ni, struct BINDING *ibind);
	long A4GLSQL_describe_stmt (char *stmt, int colno, int type);
	int A4GLSQL_end_get_columns(void);

	int A4GLSQL_next_column(char **colname, int *dtype,int *size);

	int A4GLSQL_get_columns (char *tabname, char *colname, int *dtype, int *size);



#endif /* ifndef DLSQLDEF_INCL */



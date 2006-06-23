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
# $Id: nosql.c,v 1.40 2006-06-23 14:08:47 mikeaubury Exp $
#*/

/**
 * @file
 *
 * Dummy module with empty implementations for sql functions without
 * specific SQL dinamic library built.
 */

 /*
    =====================================================================
    Includes
    =====================================================================
  */

#include "a4gl_lib_sql_int.h"
extern sqlca_struct a4gl_sqlca;
/*
=====================================================================
                    Variables definitions
=====================================================================
*/

char lasterrorstr[1024] = "";

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/


/*
=====================================================================
                    Functions definitions
=====================================================================
*/


static void
A4GL_local_exitwith (char *s)
{
#ifdef DEBUG
	  {
		      A4GL_debug ("ending because : %s", s);
		        }
#endif
	    printf ("\n\n\n");
	      exit (1);

}



#define NOPE0   {A4GL_local_exitwith ("Function can't be called  - nosql build"); return 0;}
#define NOPE   {A4GL_local_exitwith ("Function can't be called  - nosql build"); return;}

char* A4GLSQLLIB_A4GLSQL_dbms_dialect(void ) NOPE0
char* A4GLSQLLIB_A4GLSQL_dbms_name(void ) NOPE0
char* A4GLSQLLIB_A4GLSQL_get_curr_conn(void ) NOPE0
char* A4GLSQLLIB_A4GLSQL_get_currdbname(void ) NOPE0
char* A4GLSQLLIB_A4GLSQL_get_errmsg(int a) NOPE0
char* A4GLSQLLIB_A4GLSQL_get_sqlerrm(void ) NOPE0
char* A4GLSQLLIB_A4GLSQL_syscolval_expr(char* tabname,char* colname,char* typ) NOPE0
int A4GLSQLLIB_A4GLSQL_close_cursor(char* currname) NOPE0
int A4GLSQLLIB_A4GLSQL_close_session_internal(char* sessname) NOPE0
int A4GLSQLLIB_A4GLSQL_end_get_columns(void ) NOPE0
int A4GLSQLLIB_A4GLSQL_execute_implicit_select(void* sid,int singleton) NOPE0
int A4GLSQLLIB_A4GLSQL_execute_implicit_sql(void* sid,int singleton) NOPE0
int A4GLSQLLIB_A4GLSQL_fetch_cursor(char* cursor_name,int fetch_mode,int fetch_when,int nibind,void* ibind) NOPE0
int A4GLSQLLIB_A4GLSQL_fill_array(int mx,char* arr1,int szarr1,char* arr2,int szarr2,char* service,int mode,char* info) NOPE0
int A4GLSQLLIB_A4GLSQL_get_columns(char* tabname,char* colname,int* dtype,int* size) NOPE0
int A4GLSQLLIB_A4GLSQL_init_connection_internal(char* dbName) NOPE0
int A4GLSQLLIB_A4GLSQL_init_session_internal(char* sessname,char* dsn,char* usr,char* pwd) NOPE0
int A4GLSQLLIB_A4GLSQL_next_column(char** colname,int* dtype,int* size) NOPE0
int A4GLSQLLIB_A4GLSQL_open_cursor(char* s,int no,void* vibind) NOPE0
int A4GLSQLLIB_A4GLSQL_read_columns(char* tabname,char* colname,int* dtype,int* size) NOPE0
int A4GLSQLLIB_A4GLSQL_set_conn_internal(char* sessname) NOPE0
long A4GLSQLLIB_A4GLSQL_describe_stmt(char* stmt,int colno,int type) NOPE0

void A4GLSQLLIB_A4GLSQL_commit_rollback(int mode) NOPE
void A4GLSQLLIB_A4GLSQL_flush_cursor(char* cursor) NOPE
void A4GLSQLLIB_A4GLSQL_free_cursor(char* cursor_name) NOPE
void A4GLSQLLIB_A4GLSQL_put_insert(void* ibind,int n) NOPE
void A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode(int a) NOPE
void A4GLSQLLIB_A4GLSQL_unload_data_internal(char* fname,char* delims,char* sql1,int nbind,void* ibind) NOPE

void* A4GLSQLLIB_A4GLSQL_declare_cursor(int upd_hold,void* sid,int scroll,char* cursname) NOPE0
t_expr_str_list* A4GLSQLLIB_A4GLSQL_get_validation_expr(char* tabname,char* colname) NOPE0
void* A4GLSQLLIB_A4GLSQL_prepare_select_internal(void* ibind,int ni,void* obind,int no,char* s,char* uniqid) NOPE0

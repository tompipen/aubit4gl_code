
/*
 * lib=SQL env=A4GL_SQLTYPE lib_prefix= api_prefix=
 * @file
 * Function prototypes
 *
 * This file was created from .spec file of same name, using dlmagic script
 * - if you need to edit it, edit .spec file instad, and use [make filename.h]
 * to re-create it.
 *
 * @todo See if the functions are static
 * or to be externally seen
 */

/*******************************************************************
* (c) 1997-2002 Aubit Computing Ltd.
*
*
********************************************************************/

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

#ifndef __SQL_H__
#define __SQL_H__
#ifdef __cplusplus
extern "C"
{
#endif

int A4GLSQL_add_prepare(char* pname,void* sid);

int A4GLSQL_close_connection(void );

int A4GLSQL_close_cursor(char* currname);

int A4GLSQL_close_session_internal(char* sessname);

void A4GLSQL_commit_rollback(int mode);

char* A4GLSQL_dbms_dialect(void );

char* A4GLSQL_dbms_name(void );

void* A4GLSQL_declare_cursor(int upd_hold,void* sid,int scroll,char* cursname);

long A4GLSQL_describe_stmt(char* stmt,int colno,int type);

int A4GLSQL_end_get_columns(void );

int A4GLSQL_execute_implicit_select(void* sid);

int A4GLSQL_execute_implicit_sql(void* sid);

int A4GLSQL_execute_sql(char* pname,int ni,void* ibind);

int A4GLSQL_execute_sql_from_ptr_internal(char* pname,int ni,char* ibind);

int A4GLSQL_fetch_cursor(char* cursor_name,int fetch_mode,int fetch_when,int nibind,void* ibind);

int A4GLSQL_fill_array(int mx,char* arr1,int szarr1,char* arr2,int szarr2,char* service,int mode,char* info);

void* A4GLSQL_find_prepare(char* pname);

void A4GLSQL_flush_cursor(char* cursor);

int A4GLSQL_get_columns(char* tabname,char* colname,int* dtype,int* size);

char* A4GLSQL_get_curr_conn(void );

char* A4GLSQL_get_currdbname(void );

int A4GLSQL_get_datatype(char* db,char* tab,char* col);

char* A4GLSQL_get_sqlerrm(void );

void* A4GLSQL_get_validation_expr(char* tabname,char* colname);

int A4GLSQL_init_connection_internal(char* dbName);

int A4GLSQL_init_session_internal(char* sessname,char* dsn,char* usr,char* pwd);

int A4GLSQL_make_connection(char* server,char* uid_p,char* pwd_p);

int A4GLSQL_next_column(char** colname,int* dtype,int* size);

int A4GLSQL_open_cursor(int ni,char* s);

void* A4GLSQL_prepare_glob_sql_internal(char* s,int ni,void* ibind);

void* A4GLSQL_prepare_select_internal(void* ibind,int ni,void* obind,int no,char* s);

void* A4GLSQL_prepare_sql_internal(char* s);

void A4GLSQL_put_insert(void* ibind,int n);

int A4GLSQL_read_columns(char* tabname,char* colname,int* dtype,int* size);

int A4GLSQL_set_conn_internal(char* sessname);

void A4GLSQL_set_sqlca_sqlcode(int a);

void A4GLSQL_unload_data_internal(char* fname,char* delims,char* sql1,int nbind,void* ibind);

char* A4GLSQL_get_errmsg(int a);

#ifdef __cplusplus
}
#endif
#endif  /* #ifdef __ lib _H__  */


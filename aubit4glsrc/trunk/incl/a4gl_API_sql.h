
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

char* A4GLSQL_dbms_dialect(void );

char* A4GLSQL_dbms_name(void );

int A4GLSQL_get_columns(char* tabname,char* colname,int* dtype,int* size);

int A4GLSQL_end_get_columns(void );

char* A4GLSQL_get_sqlerrm(void );

int A4GLSQL_init_connection_internal(char* dbName);

int A4GLSQL_next_column(char** colname,int* dtype,int* size);

int A4GLSQL_read_columns(char* tabname,char* colname,int* dtype,int* size);

void* A4GLSQL_get_validation_expr(char* tabname,char* colname);

void A4GLSQL_commit_rollback(int mode);

int A4GLSQL_init_session_internal(char* sessname,char* dsn,char* usr,char* pwd);

int A4GLSQL_set_conn_internal(char* sessname);

int A4GLSQL_close_session_internal(char* sessname);

int A4GLSQL_execute_implicit_select(void* sid);

int A4GLSQL_execute_implicit_sql(void* sid);

int A4GLSQL_fetch_cursor(char* cursor_name,int fetch_mode,int fetch_when,int nibind,void* ibind);

int A4GLSQL_open_cursor(int ni,char* s);

void A4GLSQL_flush_cursor(char* cursor);

int A4GLSQL_close_cursor(char* currname);

void* A4GLSQL_declare_cursor(int upd_hold,void* sid,int scroll,char* cursname);

void* A4GLSQL_prepare_select_internal(void* ibind,int ni,void* obind,int no,char* s);

char* A4GLSQL_get_curr_conn(void );

char* A4GLSQL_get_currdbname(void );

void A4GLSQL_put_insert(void* ibind,int n);

void A4GLSQL_set_sqlca_sqlcode(int a);

void A4GLSQL_unload_data_internal(char* fname,char* delims,char* sql1,int nbind,void* ibind);

char* A4GLSQL_get_errmsg(int a);

long A4GLSQL_describe_stmt(char* stmt,int colno,int type);

int A4GLSQL_fill_array(int mx,char* arr1,int szarr1,char* arr2,int szarr2,char* service,int mode,char* info);

#ifdef __cplusplus
}
#endif
#endif  /* #ifdef __ lib _H__  */


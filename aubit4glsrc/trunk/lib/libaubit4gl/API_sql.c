/*
 * lib=SQL env=A4GL_SQLTYPE lib_prefix= api_prefix=
 * @file
 * File definition
 *
 * This file was created from .spec file of same name, using dlmagic script
 * - if you need to edit it, edit .spec file instad, and use [make filename.c]
 * to re-create it.
 *
 * @todo Add Doxygen comments to file
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 */

/*******************************************************************
* (c) 1997-2002 Aubit Computing Ltd.
*
*
********************************************************************/


#include "a4gl_libaubit4gl_int.h"

static void *libptr=0;
static int (*func)();
int A4GLSQL_initlib (void);
void A4GLSQL_clrlibptr (void);
int dlclose (void *__handle);

/**
 * Library init function.
 *
 * @todo : explain ussage and parameters.
 * @return .
 */

void A4GLSQL_clrlibptr (void) {
    if (libptr) {dlclose(libptr);}
    libptr=0;
}

int A4GLSQL_initlib (void) {
   libptr=(void *)A4GL_dl_openlibrary("SQL",acl_getenv("A4GL_SQLTYPE"));
   if (libptr==0) {
      A4GL_exitwith("Unable to open  library...");
      return 0;
   }
   func=A4GL_find_func_allow_missing(libptr,"A4GLSQL_initlib");

   if (func)
      return func();
   else
      return 1;
}


int A4GLSQL_add_prepare(char* pname,void* sid) {
int rval;
#ifdef DEBUG
A4GL_debug("Call to int A4GLSQL_add_prepare((%s),%p)\n",pname,sid);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func=A4GL_find_func(libptr,"A4GLSQL_add_prepare");
   rval=(int)func(pname,sid);
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

int A4GLSQL_close_connection() {
int rval;
#ifdef DEBUG
A4GL_debug("Call to int A4GLSQL_close_connection()\n");
#endif
   if (libptr==0) A4GLSQL_initlib();
   func=A4GL_find_func(libptr,"A4GLSQL_close_connection");
   rval=(int)func();
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

int A4GLSQL_close_cursor(char* currname) {
int rval;
#ifdef DEBUG
A4GL_debug("Call to int A4GLSQL_close_cursor((%s))\n",currname);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func=A4GL_find_func(libptr,"A4GLSQL_close_cursor");
   rval=(int)func(currname);
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

int A4GLSQL_close_session_internal(char* sessname) {
int rval;
#ifdef DEBUG
A4GL_debug("Call to int A4GLSQL_close_session_internal((%s))\n",sessname);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func=A4GL_find_func(libptr,"A4GLSQL_close_session_internal");
   rval=(int)func(sessname);
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

void A4GLSQL_commit_rollback(int mode) {
#ifdef DEBUG
A4GL_debug("Call to void A4GLSQL_commit_rollback(%d)\n",mode);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func=A4GL_find_func(libptr,"A4GLSQL_commit_rollback");
   func(mode);
}

char* A4GLSQL_dbms_dialect() {
char* rval;
#ifdef DEBUG
A4GL_debug("Call to char* A4GLSQL_dbms_dialect()\n");
#endif
   if (libptr==0) A4GLSQL_initlib();
   func=A4GL_find_func(libptr,"A4GLSQL_dbms_dialect");
   rval=(char*)func();
#ifdef DEBUG
A4GL_debug("Returning (%s)",rval);

#endif
return rval;
}

char* A4GLSQL_dbms_name() {
char* rval;
#ifdef DEBUG
A4GL_debug("Call to char* A4GLSQL_dbms_name()\n");
#endif
   if (libptr==0) A4GLSQL_initlib();
   func=A4GL_find_func(libptr,"A4GLSQL_dbms_name");
   rval=(char*)func();
#ifdef DEBUG
A4GL_debug("Returning (%s)",rval);

#endif
return rval;
}

void* A4GLSQL_declare_cursor(int upd_hold,void* sid,int scroll,char* cursname) {
void* rval;
#ifdef DEBUG
A4GL_debug("Call to void* A4GLSQL_declare_cursor(%d,%p,%d,(%s))\n",upd_hold,sid,scroll,cursname);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func=A4GL_find_func(libptr,"A4GLSQL_declare_cursor");
   rval=(void*)func(upd_hold,sid,scroll,cursname);
#ifdef DEBUG
A4GL_debug("Returning (%p)",rval);

#endif
return rval;
}

long A4GLSQL_describe_stmt(char* stmt,int colno,int type) {
long rval;
#ifdef DEBUG
A4GL_debug("Call to long A4GLSQL_describe_stmt((%s),%d,%d)\n",stmt,colno,type);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func=A4GL_find_func(libptr,"A4GLSQL_describe_stmt");
   rval=(long)func(stmt,colno,type);
#ifdef DEBUG
A4GL_debug("Returning Unknown %p",rval);

#endif
return rval;
}

int A4GLSQL_end_get_columns() {
int rval;
#ifdef DEBUG
A4GL_debug("Call to int A4GLSQL_end_get_columns()\n");
#endif
   if (libptr==0) A4GLSQL_initlib();
   func=A4GL_find_func(libptr,"A4GLSQL_end_get_columns");
   rval=(int)func();
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

int A4GLSQL_execute_implicit_select(void* sid) {
int rval;
#ifdef DEBUG
A4GL_debug("Call to int A4GLSQL_execute_implicit_select(%p)\n",sid);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func=A4GL_find_func(libptr,"A4GLSQL_execute_implicit_select");
   rval=(int)func(sid);
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

int A4GLSQL_execute_implicit_sql(void* sid) {
int rval;
#ifdef DEBUG
A4GL_debug("Call to int A4GLSQL_execute_implicit_sql(%p)\n",sid);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func=A4GL_find_func(libptr,"A4GLSQL_execute_implicit_sql");
   rval=(int)func(sid);
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

int A4GLSQL_execute_sql(char* pname,int ni,void* ibind) {
int rval;
#ifdef DEBUG
A4GL_debug("Call to int A4GLSQL_execute_sql((%s),%d,%p)\n",pname,ni,ibind);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func=A4GL_find_func(libptr,"A4GLSQL_execute_sql");
   rval=(int)func(pname,ni,ibind);
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

int A4GLSQL_execute_sql_from_ptr_internal(char* pname,int ni,char* ibind) {
int rval;
#ifdef DEBUG
A4GL_debug("Call to int A4GLSQL_execute_sql_from_ptr_internal((%s),%d,(%s))\n",pname,ni,ibind);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func=A4GL_find_func(libptr,"A4GLSQL_execute_sql_from_ptr_internal");
   rval=(int)func(pname,ni,ibind);
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

int A4GLSQL_fetch_cursor(char* cursor_name,int fetch_mode,int fetch_when,int nibind,void* ibind) {
int rval;
#ifdef DEBUG
A4GL_debug("Call to int A4GLSQL_fetch_cursor((%s),%d,%d,%d,%p)\n",cursor_name,fetch_mode,fetch_when,nibind,ibind);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func=A4GL_find_func(libptr,"A4GLSQL_fetch_cursor");
   rval=(int)func(cursor_name,fetch_mode,fetch_when,nibind,ibind);
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

int A4GLSQL_fill_array(int mx,char* arr1,int szarr1,char* arr2,int szarr2,char* service,int mode,char* info) {
int rval;
#ifdef DEBUG
A4GL_debug("Call to int A4GLSQL_fill_array(%d,(%s),%d,(%s),%d,(%s),%d,(%s))\n",mx,arr1,szarr1,arr2,szarr2,service,mode,info);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func=A4GL_find_func(libptr,"A4GLSQL_fill_array");
   rval=(int)func(mx,arr1,szarr1,arr2,szarr2,service,mode,info);
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

void* A4GLSQL_find_prepare(char* pname) {
void* rval;
#ifdef DEBUG
A4GL_debug("Call to void* A4GLSQL_find_prepare((%s))\n",pname);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func=A4GL_find_func(libptr,"A4GLSQL_find_prepare");
   rval=(void*)func(pname);
#ifdef DEBUG
A4GL_debug("Returning (%p)",rval);

#endif
return rval;
}

void A4GLSQL_flush_cursor(char* cursor) {
#ifdef DEBUG
A4GL_debug("Call to void A4GLSQL_flush_cursor((%s))\n",cursor);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func=A4GL_find_func(libptr,"A4GLSQL_flush_cursor");
   func(cursor);
}

int A4GLSQL_get_columns(char* tabname,char* colname,int* dtype,int* size) {
int rval;
#ifdef DEBUG
A4GL_debug("Call to int A4GLSQL_get_columns((%s),(%s),%p,%p)\n",tabname,colname,dtype,size);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func=A4GL_find_func(libptr,"A4GLSQL_get_columns");
   rval=(int)func(tabname,colname,dtype,size);
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

char* A4GLSQL_get_curr_conn() {
char* rval;
#ifdef DEBUG
A4GL_debug("Call to char* A4GLSQL_get_curr_conn()\n");
#endif
   if (libptr==0) A4GLSQL_initlib();
   func=A4GL_find_func(libptr,"A4GLSQL_get_curr_conn");
   rval=(char*)func();
#ifdef DEBUG
A4GL_debug("Returning (%s)",rval);

#endif
return rval;
}

char* A4GLSQL_get_currdbname() {
char* rval;
#ifdef DEBUG
A4GL_debug("Call to char* A4GLSQL_get_currdbname()\n");
#endif
   if (libptr==0) A4GLSQL_initlib();
   func=A4GL_find_func(libptr,"A4GLSQL_get_currdbname");
   rval=(char*)func();
#ifdef DEBUG
A4GL_debug("Returning (%s)",rval);

#endif
return rval;
}

int A4GLSQL_get_datatype(char* db,char* tab,char* col) {
int rval;
#ifdef DEBUG
A4GL_debug("Call to int A4GLSQL_get_datatype((%s),(%s),(%s))\n",db,tab,col);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func=A4GL_find_func(libptr,"A4GLSQL_get_datatype");
   rval=(int)func(db,tab,col);
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

char* A4GLSQL_get_sqlerrm() {
char* rval;
#ifdef DEBUG
A4GL_debug("Call to char* A4GLSQL_get_sqlerrm()\n");
#endif
   if (libptr==0) A4GLSQL_initlib();
   func=A4GL_find_func(libptr,"A4GLSQL_get_sqlerrm");
   rval=(char*)func();
#ifdef DEBUG
A4GL_debug("Returning (%s)",rval);

#endif
return rval;
}

void* A4GLSQL_get_validation_expr(char* tabname,char* colname) {
void* rval;
#ifdef DEBUG
A4GL_debug("Call to void* A4GLSQL_get_validation_expr((%s),(%s))\n",tabname,colname);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func=A4GL_find_func(libptr,"A4GLSQL_get_validation_expr");
   rval=(void*)func(tabname,colname);
#ifdef DEBUG
A4GL_debug("Returning (%p)",rval);

#endif
return rval;
}

int A4GLSQL_init_connection_internal(char* dbName) {
int rval;
#ifdef DEBUG
A4GL_debug("Call to int A4GLSQL_init_connection_internal((%s))\n",dbName);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func=A4GL_find_func(libptr,"A4GLSQL_init_connection_internal");
   rval=(int)func(dbName);
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

int A4GLSQL_init_session_internal(char* sessname,char* dsn,char* usr,char* pwd) {
int rval;
#ifdef DEBUG
A4GL_debug("Call to int A4GLSQL_init_session_internal((%s),(%s),(%s),(%s))\n",sessname,dsn,usr,pwd);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func=A4GL_find_func(libptr,"A4GLSQL_init_session_internal");
   rval=(int)func(sessname,dsn,usr,pwd);
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

int A4GLSQL_make_connection(char* server,char* uid_p,char* pwd_p) {
int rval;
#ifdef DEBUG
A4GL_debug("Call to int A4GLSQL_make_connection((%s),(%s),(%s))\n",server,uid_p,pwd_p);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func=A4GL_find_func(libptr,"A4GLSQL_make_connection");
   rval=(int)func(server,uid_p,pwd_p);
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

int A4GLSQL_next_column(char** colname,int* dtype,int* size) {
int rval;
#ifdef DEBUG
A4GL_debug("Call to int A4GLSQL_next_column(%p,%p,%p)\n",colname,dtype,size);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func=A4GL_find_func(libptr,"A4GLSQL_next_column");
   rval=(int)func(colname,dtype,size);
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

int A4GLSQL_open_cursor(int ni,char* s) {
int rval;
#ifdef DEBUG
A4GL_debug("Call to int A4GLSQL_open_cursor(%d,(%s))\n",ni,s);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func=A4GL_find_func(libptr,"A4GLSQL_open_cursor");
   rval=(int)func(ni,s);
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

void* A4GLSQL_prepare_glob_sql_internal(char* s,int ni,void* ibind) {
void* rval;
#ifdef DEBUG
A4GL_debug("Call to void* A4GLSQL_prepare_glob_sql_internal((%s),%d,%p)\n",s,ni,ibind);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func=A4GL_find_func(libptr,"A4GLSQL_prepare_glob_sql_internal");
   rval=(void*)func(s,ni,ibind);
#ifdef DEBUG
A4GL_debug("Returning (%p)",rval);

#endif
return rval;
}

void* A4GLSQL_prepare_select_internal(void* ibind,int ni,void* obind,int no,char* s) {
void* rval;
#ifdef DEBUG
A4GL_debug("Call to void* A4GLSQL_prepare_select_internal(%p,%d,%p,%d,(%s))\n",ibind,ni,obind,no,s);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func=A4GL_find_func(libptr,"A4GLSQL_prepare_select_internal");
   rval=(void*)func(ibind,ni,obind,no,s);
#ifdef DEBUG
A4GL_debug("Returning (%p)",rval);

#endif
return rval;
}

void* A4GLSQL_prepare_sql_internal(char* s) {
void* rval;
#ifdef DEBUG
A4GL_debug("Call to void* A4GLSQL_prepare_sql_internal((%s))\n",s);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func=A4GL_find_func(libptr,"A4GLSQL_prepare_sql_internal");
   rval=(void*)func(s);
#ifdef DEBUG
A4GL_debug("Returning (%p)",rval);

#endif
return rval;
}

void A4GLSQL_put_insert(void* ibind,int n) {
#ifdef DEBUG
A4GL_debug("Call to void A4GLSQL_put_insert(%p,%d)\n",ibind,n);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func=A4GL_find_func(libptr,"A4GLSQL_put_insert");
   func(ibind,n);
}

int A4GLSQL_read_columns(char* tabname,char* colname,int* dtype,int* size) {
int rval;
#ifdef DEBUG
A4GL_debug("Call to int A4GLSQL_read_columns((%s),(%s),%p,%p)\n",tabname,colname,dtype,size);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func=A4GL_find_func(libptr,"A4GLSQL_read_columns");
   rval=(int)func(tabname,colname,dtype,size);
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

int A4GLSQL_set_conn_internal(char* sessname) {
int rval;
#ifdef DEBUG
A4GL_debug("Call to int A4GLSQL_set_conn_internal((%s))\n",sessname);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func=A4GL_find_func(libptr,"A4GLSQL_set_conn_internal");
   rval=(int)func(sessname);
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

void A4GLSQL_set_sqlca_sqlcode(int a) {
#ifdef DEBUG
A4GL_debug("Call to void A4GLSQL_set_sqlca_sqlcode(%d)\n",a);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func=A4GL_find_func(libptr,"A4GLSQL_set_sqlca_sqlcode");
   func(a);
}

void A4GLSQL_unload_data_internal(char* fname,char* delims,char* sql1,int nbind,void* ibind) {
#ifdef DEBUG
A4GL_debug("Call to void A4GLSQL_unload_data_internal((%s),(%s),(%s),%d,%p)\n",fname,delims,sql1,nbind,ibind);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func=A4GL_find_func(libptr,"A4GLSQL_unload_data_internal");
   func(fname,delims,sql1,nbind,ibind);
}


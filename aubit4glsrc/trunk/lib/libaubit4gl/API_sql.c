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
int (*func)(void);
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
static int (*func_1)(char *  ,void *  );
#ifdef DEBUG
A4GL_debug("Call to int A4GLSQL_add_prepare((%s)),%p)\n",A4GL_null_as_null(pname),sid);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func_1=A4GL_find_func(libptr,"A4GLSQL_add_prepare");
   rval=(int)func_1 (pname,sid);
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

int A4GLSQL_close_connection() {
int rval;
static int (*func_2)();
#ifdef DEBUG
A4GL_debug("Call to int A4GLSQL_close_connection()\n");
#endif
   if (libptr==0) A4GLSQL_initlib();
   func_2=A4GL_find_func(libptr,"A4GLSQL_close_connection");
   rval=(int)func_2 ();
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

int A4GLSQL_close_cursor(char* currname) {
int rval;
static int (*func_3)(char *  );
#ifdef DEBUG
A4GL_debug("Call to int A4GLSQL_close_cursor((%s)))\n",A4GL_null_as_null(currname));
#endif
   if (libptr==0) A4GLSQL_initlib();
   func_3=A4GL_find_func(libptr,"A4GLSQL_close_cursor");
   rval=(int)func_3 (currname);
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

int A4GLSQL_close_session_internal(char* sessname) {
int rval;
static int (*func_4)(char *  );
#ifdef DEBUG
A4GL_debug("Call to int A4GLSQL_close_session_internal((%s)))\n",A4GL_null_as_null(sessname));
#endif
   if (libptr==0) A4GLSQL_initlib();
   func_4=A4GL_find_func(libptr,"A4GLSQL_close_session_internal");
   rval=(int)func_4 (sessname);
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

void A4GLSQL_commit_rollback(int mode) {
static void (*func_5)(int );
#ifdef DEBUG
A4GL_debug("Call to void A4GLSQL_commit_rollback(%d)\n",mode);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func_5=A4GL_find_func(libptr,"A4GLSQL_commit_rollback");
   func_5(mode);
}

char* A4GLSQL_dbms_dialect() {
char* rval;
static char* (*func_6)();
#ifdef DEBUG
A4GL_debug("Call to char* A4GLSQL_dbms_dialect()\n");
#endif
   if (libptr==0) A4GLSQL_initlib();
   func_6=A4GL_find_func(libptr,"A4GLSQL_dbms_dialect");
   rval=(char*)func_6 ();
#ifdef DEBUG
A4GL_debug("Returning (%s)",A4GL_null_as_null(rval));

#endif
return rval;
}

char* A4GLSQL_dbms_name() {
char* rval;
static char* (*func_7)();
#ifdef DEBUG
A4GL_debug("Call to char* A4GLSQL_dbms_name()\n");
#endif
   if (libptr==0) A4GLSQL_initlib();
   func_7=A4GL_find_func(libptr,"A4GLSQL_dbms_name");
   rval=(char*)func_7 ();
#ifdef DEBUG
A4GL_debug("Returning (%s)",A4GL_null_as_null(rval));

#endif
return rval;
}

void* A4GLSQL_declare_cursor(int upd_hold,void* sid,int scroll,char* cursname) {
void* rval;
static void* (*func_8)(int ,void *  ,int ,char *  );
#ifdef DEBUG
A4GL_debug("Call to void* A4GLSQL_declare_cursor(%d,%p,%d,(%s)))\n",upd_hold,sid,scroll,A4GL_null_as_null(cursname));
#endif
   if (libptr==0) A4GLSQL_initlib();
   func_8=A4GL_find_func(libptr,"A4GLSQL_declare_cursor");
   rval=(void*)func_8 (upd_hold,sid,scroll,cursname);
#ifdef DEBUG
A4GL_debug("Returning (%p)",rval);

#endif
return rval;
}

long A4GLSQL_describe_stmt(char* stmt,int colno,int type) {
long rval;
static long (*func_9)(char *  ,int ,int );
#ifdef DEBUG
A4GL_debug("Call to long A4GLSQL_describe_stmt((%s)),%d,%d)\n",A4GL_null_as_null(stmt),colno,type);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func_9=A4GL_find_func(libptr,"A4GLSQL_describe_stmt");
   rval=(long)func_9 (stmt,colno,type);
#ifdef DEBUG
A4GL_debug("Returning Unknown %p",rval);

#endif
return rval;
}

int A4GLSQL_end_get_columns() {
int rval;
static int (*func_10)();
#ifdef DEBUG
A4GL_debug("Call to int A4GLSQL_end_get_columns()\n");
#endif
   if (libptr==0) A4GLSQL_initlib();
   func_10=A4GL_find_func(libptr,"A4GLSQL_end_get_columns");
   rval=(int)func_10 ();
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

int A4GLSQL_execute_implicit_select(void* sid) {
int rval;
static int (*func_11)(void *  );
#ifdef DEBUG
A4GL_debug("Call to int A4GLSQL_execute_implicit_select(%p)\n",sid);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func_11=A4GL_find_func(libptr,"A4GLSQL_execute_implicit_select");
   rval=(int)func_11 (sid);
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

int A4GLSQL_execute_implicit_sql(void* sid) {
int rval;
static int (*func_12)(void *  );
#ifdef DEBUG
A4GL_debug("Call to int A4GLSQL_execute_implicit_sql(%p)\n",sid);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func_12=A4GL_find_func(libptr,"A4GLSQL_execute_implicit_sql");
   rval=(int)func_12 (sid);
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

int A4GLSQL_execute_sql(char* pname,int ni,void* ibind) {
int rval;
static int (*func_13)(char *  ,int ,void *  );
#ifdef DEBUG
A4GL_debug("Call to int A4GLSQL_execute_sql((%s)),%d,%p)\n",A4GL_null_as_null(pname),ni,ibind);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func_13=A4GL_find_func(libptr,"A4GLSQL_execute_sql");
   rval=(int)func_13 (pname,ni,ibind);
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

int A4GLSQL_execute_sql_from_ptr_internal(char* pname,int ni,char* ibind) {
int rval;
static int (*func_14)(char *  ,int ,char *  );
#ifdef DEBUG
A4GL_debug("Call to int A4GLSQL_execute_sql_from_ptr_internal((%s)),%d,(%s)))\n",A4GL_null_as_null(pname),ni,A4GL_null_as_null(ibind));
#endif
   if (libptr==0) A4GLSQL_initlib();
   func_14=A4GL_find_func(libptr,"A4GLSQL_execute_sql_from_ptr_internal");
   rval=(int)func_14 (pname,ni,ibind);
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

int A4GLSQL_fetch_cursor(char* cursor_name,int fetch_mode,int fetch_when,int nibind,void* ibind) {
int rval;
static int (*func_15)(char *  ,int ,int ,int ,void *  );
#ifdef DEBUG
A4GL_debug("Call to int A4GLSQL_fetch_cursor((%s)),%d,%d,%d,%p)\n",A4GL_null_as_null(cursor_name),fetch_mode,fetch_when,nibind,ibind);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func_15=A4GL_find_func(libptr,"A4GLSQL_fetch_cursor");
   rval=(int)func_15 (cursor_name,fetch_mode,fetch_when,nibind,ibind);
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

int A4GLSQL_fill_array(int mx,char* arr1,int szarr1,char* arr2,int szarr2,char* service,int mode,char* info) {
int rval;
static int (*func_16)(int ,char *  ,int ,char *  ,int ,char *  ,int ,char *  );
#ifdef DEBUG
A4GL_debug("Call to int A4GLSQL_fill_array(%d,(%s)),%d,(%s)),%d,(%s)),%d,(%s)))\n",mx,A4GL_null_as_null(arr1),szarr1,A4GL_null_as_null(arr2),szarr2,A4GL_null_as_null(service),mode,A4GL_null_as_null(info));
#endif
   if (libptr==0) A4GLSQL_initlib();
   func_16=A4GL_find_func(libptr,"A4GLSQL_fill_array");
   rval=(int)func_16 (mx,arr1,szarr1,arr2,szarr2,service,mode,info);
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

void* A4GLSQL_find_prepare(char* pname) {
void* rval;
static void* (*func_17)(char *  );
#ifdef DEBUG
A4GL_debug("Call to void* A4GLSQL_find_prepare((%s)))\n",A4GL_null_as_null(pname));
#endif
   if (libptr==0) A4GLSQL_initlib();
   func_17=A4GL_find_func(libptr,"A4GLSQL_find_prepare");
   rval=(void*)func_17 (pname);
#ifdef DEBUG
A4GL_debug("Returning (%p)",rval);

#endif
return rval;
}

void A4GLSQL_flush_cursor(char* cursor) {
static void (*func_18)(char *  );
#ifdef DEBUG
A4GL_debug("Call to void A4GLSQL_flush_cursor((%s)))\n",A4GL_null_as_null(cursor));
#endif
   if (libptr==0) A4GLSQL_initlib();
   func_18=A4GL_find_func(libptr,"A4GLSQL_flush_cursor");
   func_18(cursor);
}

int A4GLSQL_get_columns(char* tabname,char* colname,int* dtype,int* size) {
int rval;
static int (*func_19)(char *  ,char *  ,int *  ,int *  );
#ifdef DEBUG
A4GL_debug("Call to int A4GLSQL_get_columns((%s)),(%s)),%p,%p)\n",A4GL_null_as_null(tabname),A4GL_null_as_null(colname),dtype,size);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func_19=A4GL_find_func(libptr,"A4GLSQL_get_columns");
   rval=(int)func_19 (tabname,colname,dtype,size);
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

char* A4GLSQL_get_curr_conn() {
char* rval;
static char* (*func_20)();
#ifdef DEBUG
A4GL_debug("Call to char* A4GLSQL_get_curr_conn()\n");
#endif
   if (libptr==0) A4GLSQL_initlib();
   func_20=A4GL_find_func(libptr,"A4GLSQL_get_curr_conn");
   rval=(char*)func_20 ();
#ifdef DEBUG
A4GL_debug("Returning (%s)",A4GL_null_as_null(rval));

#endif
return rval;
}

char* A4GLSQL_get_currdbname() {
char* rval;
static char* (*func_21)();
#ifdef DEBUG
A4GL_debug("Call to char* A4GLSQL_get_currdbname()\n");
#endif
   if (libptr==0) A4GLSQL_initlib();
   func_21=A4GL_find_func(libptr,"A4GLSQL_get_currdbname");
   rval=(char*)func_21 ();
#ifdef DEBUG
A4GL_debug("Returning (%s)",A4GL_null_as_null(rval));

#endif
return rval;
}

int A4GLSQL_get_datatype(char* db,char* tab,char* col) {
int rval;
static int (*func_22)(char *  ,char *  ,char *  );
#ifdef DEBUG
A4GL_debug("Call to int A4GLSQL_get_datatype((%s)),(%s)),(%s)))\n",A4GL_null_as_null(db),A4GL_null_as_null(tab),A4GL_null_as_null(col));
#endif
   if (libptr==0) A4GLSQL_initlib();
   func_22=A4GL_find_func(libptr,"A4GLSQL_get_datatype");
   rval=(int)func_22 (db,tab,col);
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

char* A4GLSQL_get_sqlerrm() {
char* rval;
static char* (*func_23)();
#ifdef DEBUG
A4GL_debug("Call to char* A4GLSQL_get_sqlerrm()\n");
#endif
   if (libptr==0) A4GLSQL_initlib();
   func_23=A4GL_find_func(libptr,"A4GLSQL_get_sqlerrm");
   rval=(char*)func_23 ();
#ifdef DEBUG
A4GL_debug("Returning (%s)",A4GL_null_as_null(rval));

#endif
return rval;
}

void* A4GLSQL_get_validation_expr(char* tabname,char* colname) {
void* rval;
static void* (*func_24)(char *  ,char *  );
#ifdef DEBUG
A4GL_debug("Call to void* A4GLSQL_get_validation_expr((%s)),(%s)))\n",A4GL_null_as_null(tabname),A4GL_null_as_null(colname));
#endif
   if (libptr==0) A4GLSQL_initlib();
   func_24=A4GL_find_func(libptr,"A4GLSQL_get_validation_expr");
   rval=(void*)func_24 (tabname,colname);
#ifdef DEBUG
A4GL_debug("Returning (%p)",rval);

#endif
return rval;
}

int A4GLSQL_init_connection_internal(char* dbName) {
int rval;
static int (*func_25)(char *  );
#ifdef DEBUG
A4GL_debug("Call to int A4GLSQL_init_connection_internal((%s)))\n",A4GL_null_as_null(dbName));
#endif
   if (libptr==0) A4GLSQL_initlib();
   func_25=A4GL_find_func(libptr,"A4GLSQL_init_connection_internal");
   rval=(int)func_25 (dbName);
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

int A4GLSQL_init_session_internal(char* sessname,char* dsn,char* usr,char* pwd) {
int rval;
static int (*func_26)(char *  ,char *  ,char *  ,char *  );
#ifdef DEBUG
A4GL_debug("Call to int A4GLSQL_init_session_internal((%s)),(%s)),(%s)),(%s)))\n",A4GL_null_as_null(sessname),A4GL_null_as_null(dsn),A4GL_null_as_null(usr),A4GL_null_as_null(pwd));
#endif
   if (libptr==0) A4GLSQL_initlib();
   func_26=A4GL_find_func(libptr,"A4GLSQL_init_session_internal");
   rval=(int)func_26 (sessname,dsn,usr,pwd);
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

int A4GLSQL_make_connection(char* server,char* uid_p,char* pwd_p) {
int rval;
static int (*func_27)(char *  ,char *  ,char *  );
#ifdef DEBUG
A4GL_debug("Call to int A4GLSQL_make_connection((%s)),(%s)),(%s)))\n",A4GL_null_as_null(server),A4GL_null_as_null(uid_p),A4GL_null_as_null(pwd_p));
#endif
   if (libptr==0) A4GLSQL_initlib();
   func_27=A4GL_find_func(libptr,"A4GLSQL_make_connection");
   rval=(int)func_27 (server,uid_p,pwd_p);
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

int A4GLSQL_next_column(char** colname,int* dtype,int* size) {
int rval;
static int (*func_28)(char * *  ,int *  ,int *  );
#ifdef DEBUG
A4GL_debug("Call to int A4GLSQL_next_column(%p,%p,%p)\n",colname,dtype,size);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func_28=A4GL_find_func(libptr,"A4GLSQL_next_column");
   rval=(int)func_28 (colname,dtype,size);
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

int A4GLSQL_open_cursor(int ni,char* s) {
int rval;
static int (*func_29)(int ,char *  );
#ifdef DEBUG
A4GL_debug("Call to int A4GLSQL_open_cursor(%d,(%s)))\n",ni,A4GL_null_as_null(s));
#endif
   if (libptr==0) A4GLSQL_initlib();
   func_29=A4GL_find_func(libptr,"A4GLSQL_open_cursor");
   rval=(int)func_29 (ni,s);
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

void* A4GLSQL_prepare_glob_sql_internal(char* s,int ni,void* ibind) {
void* rval;
static void* (*func_30)(char *  ,int ,void *  );
#ifdef DEBUG
A4GL_debug("Call to void* A4GLSQL_prepare_glob_sql_internal((%s)),%d,%p)\n",A4GL_null_as_null(s),ni,ibind);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func_30=A4GL_find_func(libptr,"A4GLSQL_prepare_glob_sql_internal");
   rval=(void*)func_30 (s,ni,ibind);
#ifdef DEBUG
A4GL_debug("Returning (%p)",rval);

#endif
return rval;
}

void* A4GLSQL_prepare_select_internal(void* ibind,int ni,void* obind,int no,char* s) {
void* rval;
static void* (*func_31)(void *  ,int ,void *  ,int ,char *  );
#ifdef DEBUG
A4GL_debug("Call to void* A4GLSQL_prepare_select_internal(%p,%d,%p,%d,(%s)))\n",ibind,ni,obind,no,A4GL_null_as_null(s));
#endif
   if (libptr==0) A4GLSQL_initlib();
   func_31=A4GL_find_func(libptr,"A4GLSQL_prepare_select_internal");
   rval=(void*)func_31 (ibind,ni,obind,no,s);
#ifdef DEBUG
A4GL_debug("Returning (%p)",rval);

#endif
return rval;
}

void* A4GLSQL_prepare_sql_internal(char* s) {
void* rval;
static void* (*func_32)(char *  );
#ifdef DEBUG
A4GL_debug("Call to void* A4GLSQL_prepare_sql_internal((%s)))\n",A4GL_null_as_null(s));
#endif
   if (libptr==0) A4GLSQL_initlib();
   func_32=A4GL_find_func(libptr,"A4GLSQL_prepare_sql_internal");
   rval=(void*)func_32 (s);
#ifdef DEBUG
A4GL_debug("Returning (%p)",rval);

#endif
return rval;
}

void A4GLSQL_put_insert(void* ibind,int n) {
static void (*func_33)(void *  ,int );
#ifdef DEBUG
A4GL_debug("Call to void A4GLSQL_put_insert(%p,%d)\n",ibind,n);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func_33=A4GL_find_func(libptr,"A4GLSQL_put_insert");
   func_33(ibind,n);
}

int A4GLSQL_read_columns(char* tabname,char* colname,int* dtype,int* size) {
int rval;
static int (*func_34)(char *  ,char *  ,int *  ,int *  );
#ifdef DEBUG
A4GL_debug("Call to int A4GLSQL_read_columns((%s)),(%s)),%p,%p)\n",A4GL_null_as_null(tabname),A4GL_null_as_null(colname),dtype,size);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func_34=A4GL_find_func(libptr,"A4GLSQL_read_columns");
   rval=(int)func_34 (tabname,colname,dtype,size);
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

int A4GLSQL_set_conn_internal(char* sessname) {
int rval;
static int (*func_35)(char *  );
#ifdef DEBUG
A4GL_debug("Call to int A4GLSQL_set_conn_internal((%s)))\n",A4GL_null_as_null(sessname));
#endif
   if (libptr==0) A4GLSQL_initlib();
   func_35=A4GL_find_func(libptr,"A4GLSQL_set_conn_internal");
   rval=(int)func_35 (sessname);
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

void A4GLSQL_set_sqlca_sqlcode(int a) {
static void (*func_36)(int );
#ifdef DEBUG
A4GL_debug("Call to void A4GLSQL_set_sqlca_sqlcode(%d)\n",a);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func_36=A4GL_find_func(libptr,"A4GLSQL_set_sqlca_sqlcode");
   func_36(a);
}

void A4GLSQL_unload_data_internal(char* fname,char* delims,char* sql1,int nbind,void* ibind) {
static void (*func_37)(char *  ,char *  ,char *  ,int ,void *  );
#ifdef DEBUG
A4GL_debug("Call to void A4GLSQL_unload_data_internal((%s)),(%s)),(%s)),%d,%p)\n",A4GL_null_as_null(fname),A4GL_null_as_null(delims),A4GL_null_as_null(sql1),nbind,ibind);
#endif
   if (libptr==0) A4GLSQL_initlib();
   func_37=A4GL_find_func(libptr,"A4GLSQL_unload_data_internal");
   func_37(fname,delims,sql1,nbind,ibind);
}


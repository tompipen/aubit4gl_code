
LIBRARY SQL
* Name of the variable which will have second part of library name to load:
VARIABLE A4GL_SQLTYPE

# A4GLSQL_add_prepare char* pname void* sid -> int
# A4GLSQL_close_connection -> int

A4GLSQL_close_session_internal char* sessname -> int
A4GLSQL_close_cursor char* currname -> int

A4GLSQL_commit_rollback int mode -> void

A4GLSQL_dbms_dialect -> char*
A4GLSQL_dbms_name -> char*

A4GLSQL_declare_cursor int upd_hold void* sid int scroll char* cursname -> void*

A4GLSQL_describe_stmt char* stmt int colno int type -> long



A4GLSQL_execute_implicit_select void* sid -> int
A4GLSQL_execute_implicit_sql void* sid -> int

#A4GLSQL_execute_sql char* pname int ni void* ibind -> int


A4GLSQL_fetch_cursor char* cursor_name int fetch_mode int fetch_when int nibind void* ibind -> int

#A4GLSQL_find_prepare char* pname -> void*
#
A4GLSQL_flush_cursor char* cursor -> void

A4GLSQL_fill_array int mx char* arr1 int szarr1 char* arr2 int szarr2 char* service int mode char* info -> int
A4GLSQL_get_columns char* tabname char* colname int* dtype int* size -> int
A4GLSQL_end_get_columns -> int

A4GLSQL_get_curr_conn -> char*
A4GLSQL_get_currdbname -> char*
A4GLSQL_get_datatype char* db char* tab char* col -> int
A4GLSQL_get_sqlerrm -> char*
A4GLSQL_get_validation_expr char* tabname char* colname -> void*
A4GLSQL_init_connection_internal char* dbName -> int
A4GLSQL_init_session_internal char* sessname char* dsn char* usr char* pwd -> int
A4GLSQL_make_connection char* server char* uid_p char* pwd_p -> int
A4GLSQL_next_column char** colname int* dtype int* size -> int
A4GLSQL_open_cursor int ni char* s -> int

A4GLSQL_prepare_glob_sql_internal char* s int ni void* ibind -> void*
A4GLSQL_prepare_select_internal void* ibind int ni void* obind int no char* s -> void*
A4GLSQL_prepare_sql_internal char* s -> void*


A4GLSQL_put_insert void* ibind int n -> void
A4GLSQL_read_columns char* tabname char* colname int* dtype int* size -> int
A4GLSQL_set_conn_internal char* sessname -> int
A4GLSQL_set_sqlca_sqlcode int a -> void
A4GLSQL_unload_data_internal char* fname char* delims char* sql1 int nbind void* ibind -> void
A4GLSQL_get_errmsg int a -> char* errmsg

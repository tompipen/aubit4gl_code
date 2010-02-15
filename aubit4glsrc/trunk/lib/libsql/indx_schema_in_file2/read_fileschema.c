// This reads a file previously generated with '
//                  index_fileschema
// which is a "processed" fileschema output
// The idea is to make searching a fileschema's schema substantially faster
// and therefore speed up compilation times
#include "a4gl_lib_sql_int.h"
#include "a4gl_expr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileschema.h"
extern sqlca_struct a4gl_sqlca;


static int readOk=0;
static struct s_idx_tables current_tables;
static struct s_idx_table *currTable=NULL;
static int currCol=0;





/*
=====================================================================
                    Variables definitions
=====================================================================
*/


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

char *A4GL_global_A4GLSQL_get_sqlerrm (void);
//static struct expr_str_list *A4GL_add_validation_elements_to_expr (struct expr_str_list *ptr, char *val);
//void * A4GL_new_expr (char *value);
//void * A4GL_append_expr (struct expr_str *orig_ptr, char *value);
/* We only need to implement the functions used by the compiler :

         A4GLSQL_end_get_columns
         A4GLSQL_get_columns
         A4GLSQL_get_sqlerrm
         A4GLSQL_get_status
         A4GLSQL_init_connection
         A4GLSQL_initlib 		** NOT REQUIRED - allow_missing
         A4GLSQL_next_column
         A4GLSQL_read_columns
         A4GLSQL_set_status

*/


static int compare_tabnames(const void *va, const void *vb) {
const struct s_idx_table *a;
const struct s_idx_table *b;
a=(const struct s_idx_table *)va;
b=(const struct s_idx_table *)vb;
        return strcmp(a->tablename,b->tablename);
}




/**
 *
 * @todo Describe function
 */
int
A4GLSQLLIB_A4GLSQL_init_connection_internal (char *dbName)
{
  char fname[256];
  char *f;
  sprintf (fname, "%s",dbName);


  f=acl_getenv_not_set_as_0("A4GL_INDXSCHEMA_EXT");
  if (f==0) {
	  f=".schidx";
  }
  strcpy(fname, dbName);
	A4GL_trim(fname);
  strcat(fname,f);
  A4GL_debug("OPEN SCHEMA : %s",fname);

   if (!read_s_idx_tables(&current_tables,fname)) {
      A4GL_set_errm (fname);
      A4GL_exitwith ("Couldn't open schema file");
	readOk=0;
      return 1;
    } else {
	readOk=1;
	}


  return 0;
}

int A4GLSQLLIB_SQL_initlib(void) {
	return 1;
}

/**
 *
 * @todo Describe function
 */
char *
A4GLSQLLIB_A4GLSQL_get_sqlerrm (void)
{
  return A4GL_global_A4GLSQL_get_sqlerrm ();
}



/**
 *
 * @todo Describe function
 */
int
A4GLSQL_initsqllib (void)
{
  return 1;
}

int
A4GLSQLLIB_A4GLSQL_get_columns (char *tabname, char *colname, int *dtype,
				int *size)
{
  //char buff[256];
  //char tname[256];
  //void *r;
struct s_idx_table tab_search;

strcpy(tab_search.tablename,tabname);
tab_search.tabid=0;
tab_search.partnum=0;
tab_search.columns.columns_len=0;
tab_search.columns.columns_val=0;


  if (readOk == 0)
    {
      A4GL_exitwith ("Not connected to database");
      return 0;
    }

/*
for (a=0;a<current_tables.tables.tables_len;a++) {
	printf("%d. %s\n", a, current_tables.tables.tables_val[a].tablename);
}
*/



    currTable=(struct s_idx_table *)bsearch(
			&tab_search,
			current_tables.tables.tables_val, 
			current_tables.tables.tables_len, 
				sizeof(current_tables.tables.tables_val[0]),
			compare_tabnames);
    currCol=0;

    if (currTable) {
	      return 1;
    } else {
  	A4GL_set_errm (tabname);
	A4GL_debug("tabname : %s not found",tabname);
  	A4GL_exitwith ("Table not found\n");
  	return 0;
    }
}



int
A4GLSQLLIB_A4GLSQL_end_get_columns (void)
{
  return 0;
}

int
A4GLSQLLIB_A4GLSQL_next_column (char **colname, int *dtype, int *size)
{
  if (readOk == 0)
    {
      A4GL_exitwith ("Not connected to database");
      return 0;
    }

  if (currTable==NULL)  {
      A4GL_exitwith ("No current table");
      return 0;
  }

  if (currCol<0 || currCol >= currTable->columns.columns_len) {
	return 0;
  }

  *dtype= currTable->columns.columns_val[currCol].datatype & DTYPE_MASK;
  *size= currTable->columns.columns_val[currCol].size;
  *colname= currTable->columns.columns_val[currCol].columnName;

  currCol++;

  return 1;

}



t_expr_str_list *
A4GLSQLLIB_A4GLSQL_get_validation_expr (char *tabname, char *colname)
{
  printf
    ("Warning Validation feature not implemented in SCHEMA_IN_FILE  SQL Driver");
  return 0;
}

char *
A4GLSQLLIB_A4GLSQL_dbms_dialect (void)
{
  /* this is set in make_connection */
  return "FILE";
}


char *
A4GLSQLLIB_A4GLSQL_syscolval_expr (char *tabname, char *colname, char *typ)
{
  return 0;
}


char *
A4GLSQLLIB_A4GLSQL_get_errmsg (int a)
{
  return 0;
}

char *A4GLSQLLIB_A4GLSQL_get_table_checksum(char *s) {
        return s; // dont worry - we'll try later to implement something 'proper'
}


void A4GLSQLLIB_A4GLSQL_free_prepare_internal (void* sid ) {
/* does nothing in this driver */
 }
int A4GLSQLLIB_A4GLSQL_cancel ()
{
    return 1;
}


char *A4GLSQLLIB_A4GLSQL_fixup_descriptor(char *s) {
        return s;
}



char *A4GLSQLLIB_A4GLSQL_dbms_name() {
	return "INDXFILESCHEMA";
}


int A4GLSQLLIB_A4GLSQL_next_column_detailed(char** colname,int* dtype,int* size,int* prec,int* raw_dtype) {
return 0;
}
void A4GLSQLLIB_A4GLSQL_commit_rollback(int mode) {
}
int A4GLSQLLIB_A4GLSQL_init_session_internal(char* sessname,char* dsn,char* usr,char* pwd) {
	return 0;
}
int A4GLSQLLIB_A4GLSQL_set_conn_internal(char* sessname) {
return 0;
}
int A4GLSQLLIB_A4GLSQL_close_session_internal(char* sessname) {
return 0;
}
int A4GLSQLLIB_A4GLSQL_execute_implicit_select(void* sid,int singleton) {
return 0;
}
int A4GLSQLLIB_A4GLSQL_execute_implicit_sql(void* sid,int singleton,int no,void* ibind) {
return 0;
}

void A4GLSQLLIB_A4GLSQL_free_cursor_internal(char* cursor_name) {
}
int A4GLSQLLIB_A4GLSQL_fetch_cursor_internal(char* cursor_name,int fetch_mode,int fetch_when,int nibind,void* ibind) {
return 0;
}
int A4GLSQLLIB_A4GLSQL_open_cursor_internal(char* s,int no,void* vibind) {
return 0;
}
void A4GLSQLLIB_A4GLSQL_flush_cursor_internal(char* cursor){
}
int A4GLSQLLIB_A4GLSQL_close_cursor_internal(char* currname,int explicit_){
return 0;
}
void* A4GLSQLLIB_A4GLSQL_declare_cursor_internal(int upd_hold,void* sid,int scroll,char* cursname){
return NULL;
}
void* A4GLSQLLIB_A4GLSQL_prepare_select_internal(void* ibind,int ni,void* obind,int no,char* s,char* uniqid,int singleton){
return NULL;
}
char* A4GLSQLLIB_A4GLSQL_get_curr_conn(void ){
return NULL;
}
char* A4GLSQLLIB_A4GLSQL_get_currdbname(void ){
return NULL;
}
void A4GLSQLLIB_A4GLSQL_put_insert_internal(char* cursorname,void* ibind,int n) {
}
void A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode(int a){
}
void A4GLSQLLIB_A4GLSQL_unload_data_internal(char* fname,char* delims,char* sql1,int nbind,void* ibind){
}
long A4GLSQLLIB_A4GLSQL_describe_stmt(char* stmt,int colno,int type){
return 0;
}
int A4GLSQLLIB_A4GLSQL_fill_array(int mx,char* arr1,int szarr1,char* arr2,int szarr2,char* service,int mode,char* info){
return 0;
}
void A4GLSQLLIB_A4GLSQL_map_tname(char* code,char* db){
}
void A4GLSQLLIB_A4GLSQL_unmap_tname(char* code){
}
int A4GLSQLLIB_A4GLSQL_is_tname_mapped(char* code) {
return 0;
}


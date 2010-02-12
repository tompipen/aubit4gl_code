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
#include "fileschema.x.h"
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
  void *r;
struct s_idx_table tab_search;

tab_search.tablename=tabname;
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

    if (r) {
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

/* =============================== EOF ============================== */

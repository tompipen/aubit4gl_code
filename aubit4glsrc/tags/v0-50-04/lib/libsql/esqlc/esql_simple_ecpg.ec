#include "a4gl_lib_sql_esqlc_int.h"
#include "sql3types.h"

//void global_A4GLSQL_set_sqlcode (int n);


static int getColumnsMax = 0;
static int getColumnsOrder = 0;

#define DTYPE_CHAR      0
#define DTYPE_SMINT     1
#define DTYPE_INT       2
#define DTYPE_FLOAT     3
#define DTYPE_SMFLOAT   4
#define DTYPE_DECIMAL   5
#define DTYPE_SERIAL    6
#define DTYPE_DATE      7
#define DTYPE_MONEY     8
#define DTYPE_DTIME     10
#define DTYPE_BYTE      11
#define DTYPE_TEXT      12
#define DTYPE_VCHAR     13
#define DTYPE_INTERVAL  14

#define isSqlError() isSqlError_full(__FILE__,__LINE__)
int
isSqlError_full (char *f,int l)
{
  A4GL_debug("sqlca.sqlcode=%d - %s %d\n", sqlca.sqlcode,f,l);
  A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (sqlca.sqlcode);

  if (sqlca.sqlcode < 0)
    return 1;
  return 0;
}


char *
A4GLSQLLIB_A4GLSQL_get_sqlerrm (void)
{
  static char msg[2000];
  strcpy (msg, sqlca.sqlerrm.sqlerrmc);
  return msg;
}


/**
 * Initialize the default connection to the database.
 *
 * @todo : Merge the functions in only one that connects calling from
 *         others.
 *
 * @param dbName The database name.
 * @return
 *  - 1 : An error ocurred.
 *  - 0 : Connection estabilished.
 */
int
A4GLSQLLIB_A4GLSQL_init_connection_internal (char *dbName)
{
  static int have_connected = 0;

  EXEC SQL BEGIN DECLARE SECTION;
  char *db = dbName;
  EXEC SQL END DECLARE SECTION;

// Have we got an active db session ?
  if (have_connected)
    {
      EXEC SQL DISCONNECT 'default';
      // Not any more we haven't...
    }

  EXEC SQL connect to:db as 'default';
  printf ("COnnected : %d to %s\n", sqlca.sqlcode, db);
  if (isSqlError ())
    return 1;

  have_connected = 1;
  return 0;
}

/**
 * Close the default connection.
 *
 * @param sessname The session/connection name.
 * @return
 *  - 0 : Connection closed.
 *  - 1 : Connection does not exist or error ocurred.
 */
int
A4GLSQL_close_connection (void)
{
  EXEC SQL DISCONNECT 'default';
}




/**
 * Start getting information about all columns from a table in the database 
 * engine.
 *
 * This is used to declare record like table.*
 *
 * @param tabname The table that we wish to get information about it.
 * @param colname The column name to get information about it.
 *                It is not used, now.
 * @param dtype A pointer to the variable where to put the data type.
 * @param size A pointer to the variable where to put the size of the column
 *  returned by the database.
 * @return 
 *   - 1 : Information readed.
 *   - 0 : Error ocurred.
 */

int
A4GLSQLLIB_A4GLSQL_get_columns (char *tabname, char *colname, int *dtype, int *size)
{
  EXEC SQL BEGIN DECLARE SECTION;
  char strSelect[640];
  int numberOfColumns;
  int MaxColumns = 254;		//we will be able to process tables with maximum 254 columns
  EXEC SQL END DECLARE SECTION;

  printf ("Get_columns - tabname=%s\n", tabname);
  printf ("              colname=%s\n", colname);


/*

SELECT a.attname, pg_catalog.format_type(a.atttypid, a.atttypmod), a.attnotnull, a.atthasdef, a.attnum FROM pg_catalog.pg_attribute a,pg_class b WHERE a.attrelid = b.oid AND a.attnum > 0 AND NOT a.attisdropped AND b.relname='tab1' ORDER BY a.attnum
*/


  sprintf (strSelect, "select * from %s", tabname);
  A4GL_debug ("strSelect : %s\n", strSelect);
  printf ("SELECT : %s\n", strSelect);

  EXEC SQL PREPARE stReadAllColumns FROM:strSelect;
  if (isSqlError ())
    {
      return 0;
    }

  EXEC SQL ALLOCATE DESCRIPTOR descReadAllColumns;	/*1 */
  if (isSqlError ())
    {
      return 0;
    }

  printf ("Declare\n");

  EXEC SQL BEGIN WORK;
  EXEC SQL DECLARE c_getCols CURSOR FOR stReadAllColumns;

  if (isSqlError ())
    {
      EXEC SQL ROLLBACK WORK;
      return 0;
    }

  printf ("Open\n");

  EXEC SQL OPEN c_getCols;

  printf ("Opened - %d %s\n", sqlca.sqlcode, sqlca.sqlerrm.sqlerrmc);

  if (isSqlError ())
    {
      EXEC SQL ROLLBACK WORK;
      return 0;
    }
  printf ("before fetch\n");

  EXEC SQL FETCH in c_getCols INTO sql descriptor descReadAllColumns;
  if (isSqlError ())
    {
      EXEC SQL ROLLBACK WORK;
      return 0;
    }
  printf ("after fetch\n");

  EXEC SQL GET DESCRIPTOR descReadAllColumns:numberOfColumns = COUNT;
  if (isSqlError ())
    {
      EXEC SQL ROLLBACK WORK;
      return 0;
    }

  if (isSqlError ())
    {
#ifdef DEBUG
      A4GL_debug ("Error in EXEC SQL GET DESCRIPTOR, numberOfColumns = %s",
	     numberOfColumns);
      A4GL_debug ("ESQL/C Error message:%s", A4GLSQLLIB_A4GLSQL_get_sqlerrm ());
#endif
      return 0;
    }

  getColumnsMax = numberOfColumns;
  getColumnsOrder = 1;
  A4GL_debug ("COlumns max=%d", numberOfColumns);
  return 1;
}

/**
 * Convert the length qualifiers for a datetime from the
 *  informix notation to the A4GL notation
 */
int
Infx_dt_to_A4gl_dt (int n)
{
  // Shouldn't get to here
  return 3;
}

/**
 *
 * @param length The length of the datatype.
 * @param dtype The data type.
 * @return The lnegth calculated.
 */
static long
fixlength (int dtype, int length)
{
int n1, n2;
switch (dtype) {
        case SQL3_CHARACTER : return length;
        case SQL3_NUMERIC: return 0xff; // @todo FIXME
        case SQL3_DECIMAL: return 0xff; // @todo FIXME
        case SQL3_INTEGER: return 4;
        case SQL3_SMALLINT: return 2;
        case SQL3_FLOAT: return 4;
        case SQL3_REAL: return 4;
        case SQL3_DOUBLE_PRECISION: return 8;
        case SQL3_DATE_TIME_TIMESTAMP: return DTYPE_DTIME;
        case SQL3_INTERVAL: return DTYPE_INTERVAL;
        case SQL3_CHARACTER_VARYING: return DTYPE_VCHAR;
        case SQL3_ENUMERATED: return DTYPE_INT;
        case SQL3_BIT: return DTYPE_SMINT;
        case SQL3_BIT_VARYING: return DTYPE_SMINT;
        case SQL3_BOOLEAN: return DTYPE_SMINT;
}

  return length;
}


static long fixtype(int dtype) {
	printf("DTYPE = %x (SI=%d I=%d)\n",dtype,SQL3_INTEGER,SQL3_SMALLINT);

switch (dtype) {
        case SQL3_CHARACTER : return DTYPE_CHAR;
        case SQL3_NUMERIC: return DTYPE_DECIMAL;
        case SQL3_DECIMAL: return DTYPE_DECIMAL;
        case SQL3_INTEGER: return DTYPE_INT;
        case SQL3_SMALLINT: return DTYPE_SMINT;
        case SQL3_FLOAT: return DTYPE_SMFLOAT;
        case SQL3_REAL: return DTYPE_SMFLOAT;
        case SQL3_DOUBLE_PRECISION: return DTYPE_FLOAT;
        case SQL3_DATE_TIME_TIMESTAMP: return DTYPE_DTIME;
        case SQL3_INTERVAL: return DTYPE_INTERVAL;
        case SQL3_CHARACTER_VARYING: return DTYPE_VCHAR;
        case SQL3_ENUMERATED: return DTYPE_INT;
        case SQL3_BIT: return DTYPE_SMINT;
        case SQL3_BIT_VARYING: return DTYPE_SMINT;
        case SQL3_BOOLEAN: return DTYPE_SMINT;
}

A4GL_debug("Ooops - Unknown datatype : %d",dtype);
A4GL_exitwith("Invalid datatype for Aubit4GL");
return 0;

}


/**
 * Iterate in getting information about all columns from a table from the
 * database engine.
 *
 * A4GLSQL_get_columns(char *tabname) should be called before this one.
 *
 * This is used to declare record like table.*
 *
 * @param colname The place where to put the column name
 * @param dtype A pointer to the variable where to put the data type.
 * @param size A pointer to the variable where to put the size of the column
 *  returned by the database.
 * @return 
 *   - 1 : Information readed.
 *   - 0 : Error ocurred.
 */
int
A4GLSQLLIB_A4GLSQL_next_column (char **colname, int *dtype, int *size)
{
  EXEC SQL BEGIN DECLARE SECTION;
  int idx = getColumnsOrder;
  int dataType;
  int length;
  static char columnName[64];
  EXEC SQL END DECLARE SECTION;

  if (idx > getColumnsMax)
    return 0;

  EXEC SQL GET DESCRIPTOR descReadAllColumns VALUE:idx:columnName =
    NAME,:dataType = TYPE,:length = LENGTH;
  printf("sqlca.sqlcode=%d\n",sqlca.sqlcode);
  if (isSqlError ())
    return 0;

printf("1\n");
  *dtype = fixtype(dataType);
  *colname = columnName;
  *size = fixlength (dataType, length);
  printf ("dtype=%d size=%d colname=%s\n", *dtype, *size, *colname);
  getColumnsOrder++;
  return 1;
}

/**
 * Free all resources allocated in getting information about columns
 *
 * @return 
 *   - 0 : Descriptor dealocated
 *   - 1 : Error ocurred.
 */
int
A4GLSQLLIB_A4GLSQL_end_get_columns (void)
{
  EXEC SQL COMMIT WORK;
  EXEC SQL DEALLOCATE DESCRIPTOR descReadAllColumns;
  if (isSqlError ())
    {
      return 0;
    }
  return 1;
}


/**
 * Gets information about columns from a table in the database engine.
 *
 * @todo : Put this working with .*
 * @todo : Remove if not used.
 *
 * @param tabname The table that we wish to get information about it.
 * @param colname The column name to get information about it.
 * @param dtype A pointer to the variable where to put the data type.
 * @param size A pointer to the variable where to put the size of the column
 *  returned by the database.
 * @return 
 *   - 0 : Information readed.
 *   - 1 : Error ocurred.
 */
static int
getSQLDataType (char *connName, char *tabname, char *colname,
		int *dtype, int *size)
{
  EXEC SQL BEGIN DECLARE SECTION;
  char strSelect[640];
  int dataType;
  int length;
  EXEC SQL END DECLARE SECTION;

printf("getSQLDataType\n");
  sprintf (strSelect, "select %s from %s", colname, tabname);
  A4GL_debug ("SQL = %s", strSelect);
  EXEC SQL PREPARE stReadColumns FROM:strSelect;
  if (isSqlError ())
    {
      return 1;
    }

  EXEC SQL ALLOCATE DESCRIPTOR descReadColumns;
  if (isSqlError ()) { return 1; }

  EXEC SQL DECLARE c_rc CURSOR FOR stReadColumns;
  if (isSqlError ()) { return 1; }
  EXEC SQL OPEN c_rc;
  if (isSqlError ()) { return 1; }
  EXEC SQL FETCH in c_rc INTO sql descriptor descReadColumns;
  if (isSqlError ()||sqlca.sqlcode==100) { return 1; }
  EXEC SQL CLOSE c_rc;
  if (isSqlError ()) { return 1; }

  EXEC SQL GET DESCRIPTOR descReadColumns VALUE 0:dataType = TYPE,:length =
    LENGTH;


  if (isSqlError ()) { return 1; }

  EXEC SQL DEALLOCATE DESCRIPTOR descReadColumns;

  if (isSqlError ())
    {
      return 1;
    }
printf("2\n");
  *dtype = fixtype(dataType);
  *size = fixlength (dataType, length);
  return 0;
}



/**
 * Gets information about columns from a table in the database engine.
 *
 * Aparently the compiler is waiting for an iteration in the columns of a
 * table.
 *
 * @todo : Put this working with .*
 * @todo : Use the getSQLDataType()
 *
 * @param tabname The table that we wish to get information about it.
 * @param colname The column name to get information about it.
 * @param dtype A pointer to the variable where to put the data type.
 * @param size A pointer to the variable where to put the size of the column
 *  returned by the database.
 * @return
 *   - 1 : Information readed.
 *   - 0 : Error ocurred.
 */
int
A4GLSQLLIB_A4GLSQL_read_columns (char *tabname, char *colname, int *dtype, int *size)
{
  EXEC SQL BEGIN DECLARE SECTION;
  char strSelect[640];
  int dataType;
  int length;
  EXEC SQL END DECLARE SECTION;

  EXEC SQL BEGIN WORK;
  *dtype=-1;
  *size=0;
  sprintf (strSelect, "select %s.%s from %s", tabname,colname, tabname);
A4GL_debug("%s",strSelect);
  EXEC SQL PREPARE stXReadColumns FROM:strSelect;
  if (isSqlError ())
    {
	EXEC SQL ROLLBACK WORK;
      return 0;
    }

  EXEC SQL ALLOCATE DESCRIPTOR descReadColumns2;
  if (isSqlError ())
    {
	EXEC SQL ROLLBACK WORK;
      return 0;
    }

  EXEC SQL DECLARE c_rCols CURSOR FOR stXReadColumns;
  if (isSqlError ())
    {
	EXEC SQL ROLLBACK WORK;
      return 0;
    }
  EXEC SQL OPEN c_rCols;
  if (isSqlError ())
    {
	EXEC SQL ROLLBACK WORK;
      return 0;
    }
  EXEC SQL FETCH in c_rCols INTO sql descriptor descReadColumns2;
  if (isSqlError ()||sqlca.sqlcode==100) { EXEC SQL ROLLBACK WORK; return 0; }



  EXEC SQL GET DESCRIPTOR descReadColumns2 VALUE 1:dataType = TYPE,:length = LENGTH;
  if (isSqlError ()) { EXEC SQL ROLLBACK WORK; return 0; }


  EXEC SQL DEALLOCATE DESCRIPTOR descReadColumns2;
  if (isSqlError ())
    {
	EXEC SQL ROLLBACK WORK;
      return 0;
    }
printf("3\n");
  *dtype = fixtype(dataType);
  *size = fixlength (dataType, length);
  A4GL_debug("Got DTYPE=%d %d ",*dtype,*size);
EXEC SQL COMMIT WORK;

  return 1;
}

/**
 * Get the datatype of a column in the database engine.
 *
 * @todo : Understand if this function is used somewhere.
 *
 * @param db The database name.
 * @param tab The table name.
 * @param col The column name.
 * @return
 *   - -1 : An error ocurred.
 *   - Otherwise : The datatype code.
 */
int
A4GLSQL_get_datatype (char *db, char *tab, char *col)
{
  int dataType;
  int length;
  char *connectionName;

  if (getSQLDataType (connectionName, tab, col, &dataType, &length) == 1)
    return -1;

  return dataType;
}


#define COLUMN_SIZE 0
#define DATA_TYPE   1

/**
 * Fill the array for columns.
 * 
 * @param tableName The name of the table to be checked.
 * @param max The max of columns that can be readed.
 */
static int
fillColumnsArray (char *tableName, int max, char *colArray,
		  int sizeColArray, char *array2, int sizeArray2, int mode)
{
  static char colname[64];
  int dtype;
  int size;
  int rv;
  int i = 0;
  char *ccol;

  strcpy (colname, "");
  rv = A4GLSQLLIB_A4GLSQL_get_columns (tableName, colname, &dtype, &size);
  while (rv == 1)
    {
      rv = A4GLSQLLIB_A4GLSQL_next_column (&ccol, &dtype, &size);
      strcpy (colname, ccol);

      strncpy (&colArray[i * (sizeColArray + 1)], colname, sizeColArray);


      if (array2 != (char *) 0)
	{


	  switch (mode)
	    {

	    case COLUMN_SIZE:
	      sprintf (&array2[i * (sizeArray2 + 1)], "%d", size);
	      break;

	    case DATA_TYPE:
	      sprintf (&array2[i * (sizeArray2 + 1)], "%d", dtype);
	      break;

	    default:
	      A4GL_exitwith ("Could not fill_array - Wrong mode asked!");
	    }
	}
      i++;
      if (i >= max)
	break;
    }
  rv = A4GLSQLLIB_A4GLSQL_end_get_columns ();
  return rv;
}

/**
 *
 * The fill_array are supposed to populate an array with information on
 * databases, tables or columns.
 * 
 * The returns are into an char[szarr], so arr1 should really be something like
 * char arr1[mx][szarr1] (if you see what I mean)...
 * 
 * The main interface is via fill_array where 'service' points to one of
 * the other functions (DATABASES, TABLES or COLUMNS)...
 * 
 * With service = DATABASES
 *   Mode  - not used
 *   Info - not used
 *   Arr1 = DBName
 *   Arr2 = Description ?
 * 
 * With service = TABLES
 *   Mode =1 Exclude system tables
 *   otherwise include them
 * 
 *   arr1 = Table name
 *   arr2 = Table description
 * 
 * With servce = COLUMNS
 *   Mode= 0 - Fill arr2 with colsize
 *         1 - Fill arr2 with datatype name
 *   Otherwise - fill it with the table name
 *   Info - Table name we're looking at
 *   arr1 = Column name
 * 
 * In all cases if the pointer the the array(arr1 or arr2) is 0 (or C-NULL) then
 * don't bother to fill it :-)
 *
 *
 * @param mx Maximum rows to fill in arr1/arr2.
 *
 * @param arr1 The adress where to return the information asked:
 *    DBName if service = DATABASES.
 *    Table name if service = TABLES.
 *    Column name if service = COLUMNS
 *
 * @param szarr1 Size of each item in array 1.
 *
 * @param arr2 adress of second array used to return information:
 *    - Description if service = DATABASES
 *    - Table description if service = TABLES
 *
 * @param szarr2 Size of each item in array 2.
 * @param service A string that defines the service wanted:
 *                  - DATABASES
 *                  - TABLES
 *                  - COLUMNS
 * @param mode specifies what data to load into the arrays.
 *   With service = TABLES
 *     - 1 Exclude system tables.
 *   With service = COLUMNS
 *     - 0 - Fill arr2 with colsize.
 *     - 1 - Fill arr2 with datatype name.
 * @param info passes some extra details into the functions (like table names 
 *             etc).
 *    With service = COLUMNS
 *      - Table name we're looking at
 *
 * @return The number of rows filled.
 * 
 */
int
A4GLSQLLIB_A4GLSQL_fill_array (int mx, char *arr1, int szarr1, char *arr2, int szarr2,
		    char *service, int mode, char *info)
{
  if (strcmp (service, "DATABASES") == 0)
    A4GL_exitwith ("Could not fill_array - DATABASES service not implemented !");
  else if (strcmp (service, "TABLES") == 0)
    A4GL_exitwith ("Could not fill_array - TABLES service not implemented !");
  // This is the important to implement
  else if (strcmp (service, "COLUMNS") == 0)
    return fillColumnsArray (info, mx, arr1, szarr1, arr2, szarr2, mode);
  else
    A4GL_exitwith ("Could not fill_array - Invalid service asked !");
  return 0;
}

/**
 * Assign the sqlca.sqlcode with a value.
 *
 * @todo : this function MUST call a function outside ESQL in order to use the
 * other sqlca that is not the informix one.
 *
 * @param a The value to be assigned to sqlca.sqlcode
 * @return Allways 0
 */
/* 	void A4GLSQL_set_sqlca_sqlcode(int a); */
/* int */
void
A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (int a)
{
  A4GL_debug ("In set_sqlca_sqlcode : %d\n", a);
  A4GL_set_a4gl_status(a);
  //global_A4GLSQL_set_sqlcode (a);
  if (a == 0)
    {
      A4GL_set_a4gl_status(a);
    }
  else
    {
      //printf ("--->%d\n", a);
    }
  /* return 0; */
}

/**
 * Returns the dialect of SQL spoken by the currently
 * connected DBMS.
 *
 * @return  a char string "INFORMIX"
 */
char *
A4GLSQLLIB_A4GLSQL_dbms_dialect (void)
{
  return "POSTGRES";
}

A4GLSQL_initlib (){
}

A4GLSQL_initsqllib() {
}

void *A4GL_add_validation_elements_to_expr(void *ptr,char *val) {
char *ptr2;
char *ptrn;
char buff[256];
A4GL_trim(val);

	ptr2=val;
	while (1) {
			ptrn=strtok(ptr2,",");
			if (ptrn==0) break;
			if (ptr2) {ptr2=0;}
	
			sprintf(buff,"A4GL_push_char(\"%s\");",ptrn);
	
			if (ptr==0) {
					//ptr=A4GL_new_expr(buff);
					ptr=A4GL_new_expr((char *)buff);
					/*
					warning: assignment makes pointer from integer without a cast
					void * A4GL_new_expr (char *value);
					void *ptr
					*/
			} else {
					A4GL_append_expr(ptr,buff);
			}
	
	}
	return ptr;
}


void *
A4GLSQL_get_validation_expr(char *tabname,char *colname) 
{
EXEC SQL BEGIN DECLARE SECTION;
char buff[300];
char val[65];
char *ptr=0;
EXEC SQL END DECLARE SECTION;
int cnt;
	sprintf(buff,"select attrval from %s where attrname='INCLUDE' and tabname='%s' and colname='%s'",acl_getenv("A4GL_SYSCOL_VAL"),tabname,colname);
	EXEC SQL PREPARE p_get_val FROM :buff;
	if (sqlca.sqlcode!=0) return 0;
	EXEC SQL DECLARE c_get_val CURSOR FOR p_get_val;
	if (sqlca.sqlcode!=0) return 0;
	EXEC SQL OPEN c_get_val ;
	if (sqlca.sqlcode!=0) return 0;

	while (1) {
		EXEC SQL FETCH c_get_val INTO  :val;
		if (sqlca.sqlcode!=0) break;
		ptr=A4GL_add_validation_elements_to_expr(ptr,val);
		// Process it...
	}
	return ptr;
}

/* ================================= EOF ============================== */

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
# $Id: simple.c,v 1.28 2005-05-21 16:18:51 mikeaubury Exp $
#*/


/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_lib_sql_int.h"
#include "libpq-fe.h"
#include "sql3types.h"
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
char unloadBuffer[BUFSIZ];
//extern sqlca_struct sqlca;
int sqlcode;
static void fixtype (char *ptr, int *d, int *s);
char *A4GL_global_A4GLSQL_get_sqlerrm (void);
/*
=====================================================================
                    Variables definitions
=====================================================================
*/

char lasterrorstr[1024] = "";
int curr_colno = 0;
/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

/* We only need to implement the functions used by the compiler :

         A4GLSQL_end_get_columns
         A4GLSQL_get_columns
         A4GLSQL_get_sqlerrm
         A4GLSQL_get_status
         A4GLSQL_init_connection_internal
         A4GLSQL_initlib 		** NOT REQUIRED - allow_missing
         A4GLSQL_next_column
         A4GLSQL_read_columns
         A4GLSQL_set_status

*/


PGconn *con;
PGresult *res=0;
char *pghost = "";
char *pgport = NULL;
char *pgoptions = NULL;
char *pgtty = NULL;
char *login = NULL;
char *pwd = NULL;
static struct expr_str *A4GL_add_validation_elements_to_expr(struct expr_str *ptr,char *val) ;



/**
 *
 * @todo Describe function
 */
int
A4GLSQLLIB_A4GLSQL_init_connection_internal (char *dbName)
{
  char buff2[256];
  char *envname;
  envname=acl_getenv("PG_DBPATH");
  if (envname) {
	A4GL_debug("Using a different database %s specified from the environment",envname);
	if (strlen(envname))  dbName=envname;
  }

  con = PQsetdbLogin (pghost, pgport, pgoptions, pgtty, dbName, login, pwd);
  if (con == NULL)
    {

      A4GL_set_errm (dbName);
      A4GL_exitwith ("Could not connect to database");
      return -1;
    }

  if (PQstatus (con) == CONNECTION_BAD)
    {
      if (PQerrorMessage (con))
	sprintf (buff2, "%s - %s", PQerrorMessage (con), dbName);
      else
	sprintf (buff2, "%s - No explanation from the backend", dbName);

      A4GL_set_errm (buff2);
      A4GL_exitwith ("Could not connect to database ");
      return -1;

    }
 
 A4GL_add_pointer ("default", SESSCODE,con);

  return 0;
}

/**
 *
 * @todo Describe function
 */
int
A4GLSQL_get_status (void)
{
  return sqlcode;
}

int A4GLSQLLIB_A4GLSQL_close_session_internal (char *sessname) {
 PGconn  *con;
 con=(PGconn *)A4GL_find_pointer (sessname, SESSCODE);
 if (con) {
 PQfinish(con);
 }
 return 1;

}



/**
 *
 * @todo Describe function
 */
char *
A4GLSQLLIB_A4GLSQL_get_sqlerrm (void)
{
  return (char *) A4GL_global_A4GLSQL_get_sqlerrm ();
}

/**
 *
 * @todo Describe function
 */
int
A4GLSQLLIB_A4GLSQL_read_columns (char *tabname, char *colname, int *dtype, int *size)
{
  char *buff;
  if (con == 0)
    {
      A4GL_exitwith ("Not connected to database");
      return 0;
    }
  A4GLSQLLIB_A4GLSQL_get_columns (tabname, colname, dtype, size);

  while (A4GLSQL_next_column (&buff, dtype, size))
    {
      if (strcasecmp (colname, buff) == 0)
	return 1;
    }
  return 0;
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


int nfields = 0;

int
A4GLSQLLIB_A4GLSQL_get_columns (char *tabname, char *colname, int *dtype, int *size)
{
  char buff[2048];
  char tname[256];
  curr_colno = 0;
  
  if (strchr(tabname,':')) {
		strcpy(tname,strchr(tabname,':')+1);
		tabname=tname;
  }


  if (con == 0)
    {
      A4GL_exitwith ("Not connected to database");
      return 0;
    }

// This is nicked from psql ...
  sprintf (buff,
	   "SELECT a.attname, pg_catalog.format_type(a.atttypid, a.atttypmod), a.attnotnull, a.atthasdef, a.attnum FROM pg_catalog.pg_attribute a,pg_class b WHERE a.attrelid = b.oid AND a.attnum > 0 AND NOT a.attisdropped AND b.relname='%s' ORDER BY a.attnum",
	   tabname);

  res = PQexec (con, buff);



  switch (PQresultStatus (res))
    {
    	case PGRES_COMMAND_OK:
    	case PGRES_TUPLES_OK:
      		nfields = PQntuples (res);
      		A4GL_debug ("Returns %d fields", nfields);
		if (nfields) return 1;

	case PGRES_EMPTY_QUERY:
	case PGRES_COPY_OUT:
	case PGRES_COPY_IN:
	case PGRES_BAD_RESPONSE:
	case PGRES_NONFATAL_ERROR:
	case PGRES_FATAL_ERROR:
  		A4GL_set_errm (tabname);
  		A4GL_exitwith ("Unexpected postgres return code\n");
		return 0;
    }
  A4GL_set_errm (tabname);
  A4GL_exitwith ("Table not found\n");
  return 0;
}



int
A4GLSQLLIB_A4GLSQL_end_get_columns (void)
{
  PQclear (res);
  return 0;
}

int
A4GLSQLLIB_A4GLSQL_next_column (char **colname, int *dtype, int *size)
{
  //char buff[256];
  static char cname[256];
  //int a;
  char *colptr;
strcpy(cname,"");
  *colname=cname;
  *dtype=0;
  *size=0;

  if (con == 0)
    {
      A4GL_exitwith ("Not connected to database");
      return 0;
    }
  if (curr_colno >= nfields)
    return 0;

  colptr = PQgetvalue (res, curr_colno, 0);
  if (colptr) {
  	strcpy (cname, colptr);
  	*colname = cname;
  } else {
  	strcpy (cname, "UNKNOWN");
  	*colname = cname;
	
  }
  colptr = PQgetvalue (res, curr_colno, 1);
  if (!colptr) {
	colptr="character(1)";
  }
  fixtype (colptr, dtype, size);
  
//printf("dtype=%d size=%d\n",*dtype,*size);

  curr_colno++;
  return 1;
}

//obsolete comment - remove:
/* Prototype for tis function is unfortunately printed into API_sql.c and into
API_sql.h, so we cant include it here. Since they are generated by dlmagic,
changing this would affest all other APIs, so since we are lazy, we will 
put proto here too, and hope it will never change... :-(
*/
//int A4GLSQL_initlib (void);
int A4GLSQL_initlib (void) {
  // Does nothing but we need it
  return 1;
}


char *
A4GLSQLLIB_A4GLSQL_dbms_dialect (void)
{
	/* 
	WARNING - make sure we use names as per file naming in
	etc/convertsql/
	This string will be used in /lib/libaubit4gl/sqlconvert.c 
	to form file name
	*/
	
	return "POSTGRESQL";
}



static void
fixtype (char *type, int *d, int *s)
{
  //PGresult *r;
  char buff[256];
  //char *typname;
  //char *typinput;
  //char *typoutput;
  
  char *l1 = "";
  char *l2 = "";
  *s=0;
  strcpy (buff, type);

  if (strchr (buff, '('))
    {
      l1 = strchr (buff, '(');
      *l1 = 0;
      l1++;
    }

  if (strchr (l1, ','))
    {
      l2 = strchr (l1, ',');
      *l2 = 0;
      l2++;
    }

  if (strchr (buff, ' '))
    {
      char *ptr;
      ptr = strchr (buff, ' ');
      *ptr = 0;
    }


  if (strcmp (buff, "character") == 0)
    {
      *d = DTYPE_CHAR;
      *s = atoi (l1);
    }

  if (strcmp (buff, "integer") == 0)
    {
      *d = DTYPE_INT;
	*s=sizeof(long);
    }

  if (strcmp (buff, "smallint") == 0)
    {
      *d = DTYPE_SMINT;
	*s=sizeof(short);
    }

  if (strcmp (buff, "numeric") == 0)
    {
      *d = DTYPE_DECIMAL;
      *s = ((atoi (l1) <<8) + atoi (l2));
    }

  if (strcmp (buff, "date") == 0)
    {
      *d = DTYPE_DATE;
	*s=sizeof(long);
    }

  if (strcmp (buff, "money") == 0)
    {
      *d = DTYPE_MONEY;
    }

  if (strcmp (buff, "timestamp") == 0)
    {
      *d = DTYPE_DTIME;
      *s = 22;
    }

  if (strcmp (buff, "real") == 0)
    {
      *d = DTYPE_SMFLOAT;
    }

  if (strcmp (buff, "double") == 0)
    {
      *d = DTYPE_FLOAT;
    }

  if (strcmp (buff, "interval") == 0)
    {
      *d = DTYPE_INTERVAL;
      *s = 0x249000e;
    }


  if (*d == -1)
    {
      printf ("BAD DATATYPE");
      A4GL_debug ("Ooops - Unknown datatype : %s", type);
      A4GL_exitwith ("Invalid datatype for Aubit4GL");
    }
  return;

}



static struct expr_str *
A4GL_add_validation_elements_to_expr(struct expr_str *ptr,char *val) {
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
					ptr=(struct expr_str *)A4GL_new_expr(buff);
			} else {
					A4GL_append_expr(ptr,buff);
			}
	
	}
	return ptr;
}

void *
A4GLSQL_get_validation_expr(char *tabname,char *colname) 
{
char buff[300];
char val[65];
struct expr_str *ptr=0;
int nrows=0;
int a;
PGresult *res2;
	
	sprintf(buff, "select attrval from %s where attrname='INCLUDE' and tabname='%s' and colname='%s'", acl_getenv("A4GL_SYSCOL_VAL"),tabname,colname);
	A4GL_debug("buff=%s",buff);
	res2 = PQexec (con, buff);

	switch (PQresultStatus (res2)) {
		case PGRES_COMMAND_OK:
		case PGRES_TUPLES_OK:
			nrows = PQntuples (res2);
			A4GL_debug ("Returns %d fields", nfields);break;
		case PGRES_NONFATAL_ERROR:
			return 0;
		case PGRES_EMPTY_QUERY:
		case PGRES_COPY_OUT:
		case PGRES_COPY_IN:
		case PGRES_BAD_RESPONSE:
		case PGRES_FATAL_ERROR:
			A4GL_debug("Got : %d",PQresultStatus (res2));
			A4GL_set_errm (tabname);
			A4GL_exitwith ("Unexpected postgres return code\n");
			//return -1;
			return (void *)-1;
			// warning: return makes pointer from integer without a cast
    }

	if (!nrows) {
		return 0;
	}
	for (a=0;a<nrows;a++) {
		strcpy(val,PQgetvalue(res2,a,0));
		ptr=A4GL_add_validation_elements_to_expr(ptr,val);
	}
	return ptr;
}

char* A4GLSQL_get_errmsg(int a) { return 0; }


char *A4GLSQL_syscolval_expr(char *tabname,char *colname,char *typ) {
        return 0;
}


#ifdef NDEF
int
printField (FILE * outputFile, int idx, char *descName)
{
  EXEC SQL BEGIN DECLARE SECTION;
  int dataType;
  int index ;
  short indicator;
  char buffer[32000]="";
  int length;
  int COUNT;
  int INTVAR, BOOLVAR;
  int INDICATOR;
  int TYPE,LENGTH,OCTET_LENGTH,PRECISION,SCALE,NULLABLE,RETURNED_OCTET_LENGTH;
  int DATETIME_INTERVAL_CODE;
  char NAME[120];
  char STRINGVAR[1024];
  float FLOATVAR;
  double DOUBLEVAR;
  EXEC SQL END DECLARE SECTION;
  char buff[255];
char fmt[255];
  int rc = 0;
index=idx;

A4GL_debug("Getting details for index %d",index);
 exec sql get descriptor descExec value :index
         :TYPE = type,
         :LENGTH = length, :OCTET_LENGTH=octet_length,
         :RETURNED_OCTET_LENGTH=returned_octet_length,
         :PRECISION = precision, :SCALE=scale,
         :NULLABLE=nullable, :NAME=name,
         :INDICATOR=indicator;cp_sqlca();

 A4GL_debug("%2d\t%s (type: %d length: %d precision: %d scale: %d\n"
 "\toctet_length: %d returned_octet_length: %d nullable: %d)\n\t= "
                 ,index,NAME,TYPE,LENGTH,PRECISION,SCALE
                 ,OCTET_LENGTH,RETURNED_OCTET_LENGTH,NULLABLE);
        if (INDICATOR==-1) sprintf(buffer,"");
        else switch (TYPE)
        {
          case SQL3_BOOLEAN:
                exec sql get descriptor descExec value :index :BOOLVAR=data;cp_sqlca();
                if (display_mode!=DISPLAY_UNLOAD) {
                        sprintf(buffer,"%s",BOOLVAR ? "true":"false");
                } else {
                        sprintf(buffer,"%d",BOOLVAR);
                }
                break;


           case SQL3_NUMERIC:
           case SQL3_DECIMAL:
                if (SCALE==0)
                {  exec sql get descriptor descExec value :index :INTVAR=data;cp_sqlca();
                        if (display_mode==DISPLAY_DOWN) {
                                sprintf (buffer, "%d", INTVAR);
                        } else {
                                sprintf (buffer, "%*d", columnWidths[idx-1],INTVAR);
                        }
                   //sprintf(buffer,"%-10d",INTVAR);
                        if (display_mode==DISPLAY_UNLOAD) ltrim(buffer);
                }
                else
                {

                        exec sql get descriptor descExec value :index :FLOATVAR=data;cp_sqlca();

                        if (display_mode==DISPLAY_DOWN) {
                                sprintf (buffer, "%f", FLOATVAR);
                        } else {
                                sprintf (buffer, "%*f", columnWidths[idx-1],FLOATVAR);
                        }
                                if (display_mode==DISPLAY_UNLOAD) ltrim(buffer);
                }
                break;
           case SQL3_INTEGER:
           case SQL3_SMALLINT:
                exec sql get descriptor descExec value :index :INTVAR=data;cp_sqlca();


                if (display_mode==DISPLAY_DOWN) {
                        sprintf (buffer, "%d", INTVAR);
                } else {
                        sprintf (buffer, "%*d", columnWidths[idx-1],INTVAR);
                }
                if (display_mode==DISPLAY_UNLOAD) ltrim(buffer);
                break;
           case SQL3_FLOAT:
           case SQL3_REAL:
                exec sql get descriptor descExec value :index :FLOATVAR=data;cp_sqlca();
                sprintf(buffer,"%.*f",PRECISION,FLOATVAR);
                if (display_mode==DISPLAY_UNLOAD) ltrim(buffer);
                break;
           case SQL3_DOUBLE_PRECISION:
                exec sql get descriptor descExec value :index :DOUBLEVAR=data;cp_sqlca();
                sprintf(buffer,"%.*f",PRECISION,DOUBLEVAR);
                        if (display_mode==DISPLAY_UNLOAD) ltrim(buffer);
                break;
           case SQL3_DATE_TIME_TIMESTAMP:
                exec sql get descriptor descExec value :index
                        :DATETIME_INTERVAL_CODE=datetime_interval_code,
                        :STRINGVAR=data;cp_sqlca();
                sprintf(buffer,"%s",STRINGVAR);
                break;
           case SQL3_INTERVAL:
                exec sql get descriptor descExec value :index :STRINGVAR=data;cp_sqlca();
                sprintf(buffer,"%s",STRINGVAR);
                break;
           case SQL3_CHARACTER:
           case SQL3_CHARACTER_VARYING:
                exec sql get descriptor descExec value :index :STRINGVAR=data;cp_sqlca();
                sprintf(buffer,"%s",STRINGVAR);
                A4GL_trim(buffer);
                break;
           default:
                exec sql get descriptor descExec value :index :STRINGVAR=data;cp_sqlca();
                sprintf(buffer,"%s",STRINGVAR);
                if (display_mode==DISPLAY_UNLOAD) A4GL_trim(buffer);
                break;
        }

A4GL_debug("BUFFER=%s",buffer);

if (INDICATOR !=-1 && strlen(buffer)==0 &&display_mode==DISPLAY_UNLOAD) {
        strcpy(buffer," ");
}
        if (display_mode==DISPLAY_DOWN) {
                sprintf(fmt,"%%-%d.%ds %%s\n",colnamesize+1,colnamesize+1);

                if (get_exec_mode_c()==EXEC_MODE_INTERACTIVE)  {
                        fprintf(outputFile,fmt,columnNames[idx-1],buffer);
                } else {
                        fprintf(exec_out,fmt,columnNames[idx-1],buffer);
                }
                outlines++;
        }

        if (display_mode==DISPLAY_UNLOAD) {
                        fprintf(unloadFile,"%s%s",escape_delim(buffer),delim);
        }

        if (display_mode==DISPLAY_ACROSS) {
                if (get_exec_mode_c()==EXEC_MODE_INTERACTIVE)  {

                        A4GL_debug("EXECO '%s' '%20s' '%-20s'",buffer,buffer,buffer);
                        fprintf(outputFile,"%-*s",columnWidths[idx-1],buffer);
                }
                else
                        fprintf(exec_out,"%-*s",columnWidths[idx-1],buffer);
        }


  return 0;
}

#endif

/**
 * Unload the data to a file acording to SQL statemement with
 * columns separated by a delimiter.
 *
 * @todo : Implement the unload
 * @todo : Merge the code to a connector library in order to have just
 *         one function to do it.
 *
 * @param fname The name where the data is to be inserted.
 * @param delims The row delimiter.
 * @param sql1 The SQL to generate the data.
 *
 * @return
 *   - 1 : There was an error unloading the data.
 *   - 0 : Data unloaded to file.
 */
/*      void A4GLSQL_unload_data(char *fname,char *delims, char *sql1); */
/* int */
void
A4GLSQLLIB_A4GLSQL_unload_data_internal (char *fname_o, char *delims, char *sqlStr_o, int nbind, void *vibind)
{
  FILE *unloadFile;
  int nrows=0;
  struct BINDING *ibind;
  int colcnt;
  int *column_types=0;
  int *column_sizes=0;
  PGresult *res2;
  char *fname;
  int nfields=0;
  char*sqlStr;
  int a;
  int b;

  if (A4GL_esql_db_open(-1,0,0,"")) {
	con=A4GL_esql_dbopen_connection();
  }

  if (con==0) {
	A4GL_exitwith("Database not open");
	return ;
  }
	

  ibind=vibind;

  A4GL_debug ("Unload data..");
  if (nbind) {
	A4GL_exitwith("Currently unable to unload a statement that uses variables");
	return ;
  }


  fname=strdup(fname_o); A4GL_trim(fname);
  sqlStr=strdup(sqlStr_o); A4GL_trim(sqlStr);
  unloadFile = (FILE *) A4GL_mja_fopen (fname, "wt");
  a4gl_status=0;

  if (unloadFile == (FILE *) 0)
    {
    /** @todo : Generate some error code compatible with informix 4gl */
        free(fname); free(sqlStr);
        A4GL_exitwith("Unable to open file for unload");
      return;                   /* return 1; */
    }

  setbuf(unloadFile, unloadBuffer);
  A4GL_debug("prepare : %s",sqlStr);



  res2=PQexec(con,sqlStr);

  switch (PQresultStatus (res2)) {
    	case PGRES_COMMAND_OK:
    	case PGRES_TUPLES_OK: 
		nrows = PQntuples (res2);
		nfields = PQnfields (res2);
		break;

	case PGRES_EMPTY_QUERY:
	case PGRES_COPY_OUT:
	case PGRES_COPY_IN:
	case PGRES_BAD_RESPONSE:
	case PGRES_NONFATAL_ERROR:
	case PGRES_FATAL_ERROR:
		A4GL_debug("Got : %d (%s)",PQresultStatus (res2),PQerrorMessage(con));
  		A4GL_exitwith ("Unexpected postgres return code\n");
        	free(fname); free(sqlStr);
		return ;
  }



  column_types=malloc(sizeof(int) * nfields);
  column_sizes=malloc(sizeof(int) * nfields);

  for (colcnt=0;colcnt<nfields;colcnt++) {
                //int dataType;
                //int length;
                //int index;
                //int indicator;
                //index=colcnt+1;
		column_types[colcnt]=PQftype(res2,colcnt);
		column_sizes[colcnt]=PQfmod(res2,colcnt);
		
  }


  for (a=0;a<nrows;a++) {
  	for (b=0;b<nfields;b++) {
		if (PQgetisnull(res2,a,b)) {
			fprintf(unloadFile,"%s",delims);
		} else {
			static char *s=0;
			static int sl=-1;
			int nsl;
			char *ptr;

			ptr=PQgetvalue(res2,a,b);
			nsl=strlen(ptr);
			if (nsl>=sl) {
				sl=nsl;
				s=realloc(s,sl+2);
			}
			strcpy(s,ptr);
			A4GL_trim(s);
			if (strlen(s)) {
				fprintf(unloadFile,"%s%s", s,delims);
			} else {
				fprintf(unloadFile," %s", delims);
			}
		}
        }
	fprintf(unloadFile,"\n");
  }
  fclose(unloadFile);
  PQclear(res2);
  free(fname); free(sqlStr);
  free(column_sizes);
  free(column_types);
	

  return;                       /* return 0; */
}



/* =============================== EOF ============================== */

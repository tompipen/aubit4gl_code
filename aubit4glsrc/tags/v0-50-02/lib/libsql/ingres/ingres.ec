/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-1 Aubit Development Team (See Credits file)       |
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
# $Id: ingres.ec,v 1.1 2005-01-23 19:53:52 mikeaubury Exp $
#*/


/*
=====================================================================
		                    Includes
=====================================================================
*/
#define _SQLCA_DEFINED_

EXEC SQL INCLUDE SQLCA;
EXEC SQL INCLUDE SQLDA;
#include "a4gl_lib_sql_int.h"

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

static void
fixtype (char *a,int b,int c, int *d, int *s);

//extern sqlca_struct sqlca;
int sqlcode;
int con=0;
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




/**
 *
 * @todo Describe function
 */
int
A4GLSQL_init_connection_internal (char *dbName)
{
EXEC SQL BEGIN DECLARE SECTION;
  char buff2[256];
EXEC SQL END DECLARE SECTION;

EXEC SQL WHENEVER SQLERROR CONTINUE;

strcpy(buff2,dbName);

EXEC SQL  CONNECT :buff2;

A4GL_debug("status=%d\n",sqlca.sqlcode);

if (sqlca.sqlcode!=0) {
      A4GL_set_errm (dbName);
      A4GL_exitwith ("Could not connect to database");
	con=0;
      return -1;

    }
  con=1;
  return 0;
}

/**
 *
 * @todo Describe function
 */
int
A4GLSQL_get_status (void)
{
  return sqlca.sqlcode;
}

/**
 *
 * @todo Describe function
 */
char *
A4GLSQL_get_sqlerrm (void)
{
  return (char *) A4GL_global_A4GLSQL_get_sqlerrm ();
}

/**
 *
 * @todo Describe function
 */
int
A4GLSQL_read_columns (char *tabname, char *colname, int *dtype, int *size)
{
  char *buff;
  if (con == 0)
    {
      A4GL_exitwith ("Not connected to database");
      return 0;
    }
  A4GLSQL_get_columns (tabname, colname, dtype, size);

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
A4GLSQL_get_columns (char *tabname, char *colname, int *dtype, int *size)
{
int a;
	EXEC SQL BEGIN DECLARE SECTION;
	struct {
    		char column_name[256 + 1];
    		char column_datatype[256 + 1];
    		int column_length;
    		int column_scale;
    		char column_nulls[2];
    		char column_defaults[2];
    		int column_sequence;
    		short column_ingdatatype;
  		} atti;


  	short nulli[18];

	char table_name[64];
	char column_name[64];
	EXEC SQL END DECLARE SECTION;


  char buff[2048];
  int c;



  strcpy(table_name,tabname);
  strcpy(column_name,colname);
  curr_colno = 0;

  if (con == 0)
    {
      A4GL_exitwith ("Not connected to database");
      return 0;
    }


	EXEC SQL WHENEVER SQLERROR CONTINUE;

	EXEC SQL DECLARE cxx CURSOR FOR SELECT
                                        column_name,
                                        column_datatype,
                                        column_length,
                                        column_scale,
                                        column_nulls,
                                        column_defaults,
                                        column_sequence,
                                        column_ingdatatype
                                FROM iicolumns
                                WHERE table_name = :table_name 
                                ORDER BY column_sequence;

/* AND ( :column_name = ' ' OR :column_name = '*' OR column_name = :column_name OR column_name IS NULL OR column_name='' ) */
	A4GL_debug("table_name=%s column_name=%s\n",table_name,column_name);

	if (sqlca.sqlcode!=0) { A4GL_set_errm (table_name); A4GL_exitwith ("Unexpected ingres return code (D)\n"); return 0; }

	EXEC SQL OPEN cxx;
	if (sqlca.sqlcode!=0) { A4GL_set_errm (table_name); A4GL_exitwith ("Unexpected ingres return code (D)\n"); return 0; }
	c=0;
	while (1) {
		EXEC SQL FETCH cxx INTO 	
                                        :atti.column_name:nulli[2],
                                        :atti.column_datatype:nulli[3],
                                        :atti.column_length:nulli[4],
                                        :atti.column_scale:nulli[5],
                                        :atti.column_nulls:nulli[6],
                                        :atti.column_defaults:nulli[7],
                                        :atti.column_sequence:nulli[8],
                                        :atti.column_ingdatatype:nulli[11];


		if (sqlca.sqlcode!=0) break;
		c++;
	}
	EXEC SQL CLOSE cxx;
	if (sqlca.sqlcode!=0) { A4GL_set_errm (table_name); A4GL_exitwith ("Unexpected ingres return code (O) \n"); return 0; }
	EXEC SQL OPEN cxx;
	if (sqlca.sqlcode!=0) { A4GL_set_errm (table_name); A4GL_exitwith ("Unexpected ingres return code (O) \n"); return 0; }
	//printf("Total of %d columns\n",c);
	return c;
}



int
A4GLSQL_end_get_columns (void)
{
 EXEC SQL CLOSE cxx;

  return 0;
}

int
A4GLSQL_next_column (char **colname, int *dtype, int *size)
{
EXEC SQL BEGIN DECLARE SECTION;
	struct {
    		char column_name[256 + 1];
    		char column_datatype[256 + 1];
    		int column_length;
    		int column_scale;
    		char column_nulls[2];
    		char column_defaults[2];
    		int column_sequence;
    		short column_ingdatatype;
  		} atti2;
EXEC SQL END DECLARE SECTION;
  static char cname[256];
  char *colptr;
  short xi;


  	short nulli[18];
	memset(&atti2,0,sizeof(atti2));


	EXEC SQL FETCH cxx INTO
                                        :atti2.column_name:nulli[2],
                                        :atti2.column_datatype:nulli[3],
                                        :atti2.column_length:nulli[4],
                                        :atti2.column_scale:nulli[5],
                                        :atti2.column_nulls:nulli[6],
                                        :atti2.column_defaults:nulli[7],
                                        :atti2.column_sequence:nulli[8],
                                        :atti2.column_ingdatatype:nulli[11];


	if (sqlca.sqlcode==100) return 0;
	if (sqlca.sqlcode!=0) { A4GL_exitwith ("Unexpected ingres return code (F2)\n"); return 0; }

  //printf("%d %s\n",nulli[2],atti2.column_name);


  A4GL_trim(atti2.column_name);
  strcpy(cname,atti2.column_name);
  *colname=cname;

  fixtype (atti2.column_datatype,atti2.column_length,atti2.column_scale, dtype, size);
	A4GL_debug("Returning : %s %d %d \n",*colname,*dtype,*size);
  curr_colno++;
  return 1;
}



int A4GLSQL_initlib ()
{
  // Does nothing but we need it
return 1;
}


char *
A4GLSQL_dbms_dialect ()
{
	/* 
	WARNING - make sure we use names as per file naming in
	etc/convertsql/
	This string will be used in /lib/libaubit4gl/sqlconvert.c 
	to form file name
	*/
	
	return "INGRES";
}



static void
fixtype (char *a,int b,int c, int *d, int *s)
{
char buff[200];
strcpy(buff,a);
A4GL_trim(buff);
*d=0;
*s=10;

//printf("FIX : a='%s' b=%d c=%d \n",a,b,c);
if (strcmp(buff,"CHAR")==0)    { *d=DTYPE_CHAR; *s=b; return;}
if (strcmp(buff,"VARCHAR")==0) { *d=DTYPE_VCHAR; *s=b; return;}
if (strcmp(buff,"INTEGER")==0) { *d=DTYPE_INT; *s=b; return;}
if (strcmp(buff,"DATE")==0)    { *d=DTYPE_DATE; *s=b; return;}
if (strcmp(buff,"MONEY")==0)    { *d=DTYPE_FLOAT; *s=0; return;}
if (strcmp(buff,"FLOAT")==0)    { *d=DTYPE_FLOAT; *s=0; return;}
if (strcmp(buff,"LONG VARCHAR")==0)    { *d=DTYPE_TEXT; *s=b; return;}
if (strcmp(buff,"TEXT")==0)    { *d=DTYPE_TEXT; *s=b; return;}
if (strcmp(buff,"BYTE")==0)    { *d=DTYPE_CHAR; *s=1; return;} // Dodgey...
if (strcmp(buff,"C")==0)       { *d=DTYPE_CHAR; *s=b; return;} 
if (strcmp(buff,"BYTE VARYING")==0)    { *d=DTYPE_BYTE; *s=b; return;}
if (strcmp(buff,"LONG BYTE")==0)    { *d=DTYPE_BYTE; *s=b; return;}
if (strcmp(buff,"DECIMAL")==0)    { *d=DTYPE_DECIMAL; *s=((b<<8)+c); return;}
printf("UNKNOWN : %s %d %d\n",a,b,c);
}



static struct expr_str *A4GL_add_validation_elements_to_expr(struct expr_str *ptr,char *val) {
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
char *ptr=0;
int nrows=0;
int a;
	
	
  sprintf(buff, "select attrval from %s where attrname='INCLUDE' and tabname='%s' and colname='%s'", acl_getenv("A4GL_SYSCOL_VAL"),tabname,colname);
  A4GL_exitwith("get_Validation not implemented yet for Ingres");
  return 0;
	
}

char* A4GLSQL_get_errmsg(int a) { return 0; }



/* $Header:
 *
 *    Copyright (c) 1989, Larry Wall
 *
 *    You may distribute under the terms of the GNU General Public License
 *    as specified in the README file that comes with the perl 3.0 kit.
 *
 */

int SqlDataLen;
char *SqlData;

exec sql begin declare section;
char *SqlBuf;
char errbuf[150];
exec sql end declare section;

IISQLDA *sqlda = (IISQLDA *)0;

int
do_sql_prepare(char *sb)
{
  EXEC SQL BEGIN DECLARE SECTION;
	char *sb2;
  EXEC SQL END DECLARE SECTION;

  int len;
  int save = SqlDataLen;
  int templen = 0;
  int done;
  int i;
  sb2=strdup(sb);

	/* If there isn't one around, allocate the initial sqlda: */
  if (sqlda == (IISQLDA *)0)
    {
      sqlda = (IISQLDA *)malloc (sizeof (IISQLDA));
      if (sqlda == (IISQLDA *)0)
	{
	  return 1;
	}
      sqlda -> sqln = IISQ_MAX_COLS;
    }

	/* Prepare and describe the statement.   If there isn't space,
	   make more space. */
  for (done = 0; !done; )
    {
      exec sql prepare stmt from :sb2;
      if (sqlca.sqlcode < 0)
	{
	  return 1;
	}
      exec sql describe stmt into :sqlda;
      if (sqlca.sqlcode < 0)
	{
	  return 1;
	}

      if (sqlda -> sqld < sqlda -> sqln) {
	done = 1;
	} else {
	i = sqlda -> sqld;
	free (sqlda);
	sqlda = (IISQLDA *)malloc (sizeof (IISQLDA) + (i - IISQ_MAX_COLS) * sizeof (IISQLVAR));
	if (sqlda == (IISQLDA *)0) { return 1; }
	sqlda -> sqln = i;
      } /* End if */
    } /* End for */

/* sqlda -> sqld will be zero if it wasn't a select statement.  If that happens to be the case, just execute the statement and return an error code. */


  if (sqlda -> sqld == 0)
    {
      exec sql execute stmt;
      if (sqlca.sqlcode < 0)
	{
	  return 1;
	}
      else
	return 0;
    }
	/* Otherwise, go down the sqlda allocating storage for things: */
  else
    {
      char *typename = "heck";

      for (i = 0; i < sqlda -> sqld; i++)
	{
	  int len;
	  int ind;
	  int type;
	  int baggage;

	  if (sqlda -> sqlvar [i].sqltype < 0)
	    {
	      ind = 1;
	      type = -sqlda -> sqlvar [i].sqltype;
	    }
	  else
	    {
	      ind = 0;
	      type = sqlda -> sqlvar [i].sqltype;
	    }

	  switch (type)
	    {
	    case 30:	/* integer */
	      typename = "INT";
	      len = sizeof (int);
	      sqlda -> sqlvar [i].sqltype = ind ? -30 : 30;
	      break;

	    case 31:	/* float */
	    case 5:		/* money */
	      typename = "FLOAT";
	      len = sizeof (double);
	      sqlda -> sqlvar [i].sqltype = ind ? -31 : 31;
	      break;

	    case 3:		/* date */
	      typename = "DATE";
	      len = 30;
	      sqlda -> sqlvar [i].sqltype = ind ? -21 : 21;
	      break;

	    case 20:	/* char */
	      typename = "CHAR";
	      len = sqlda -> sqlvar [i].sqllen;
	      baggage = 1;
	      break;

	    case 21:	/* varchar */
	      typename = "VARCHAR(%d)";
	      baggage = 1;
	      len = sqlda -> sqlvar [i].sqllen + 2;
	      break;
	    }

		/* For sqlind, make sure we're on a 16-bit boundary: */
	  if (templen & 1)
	    templen = (templen + 1) & ~1;

	  if (ind)
	    {
	      sqlda -> sqlvar [i].sqlind = (short *)templen;
	      templen += 2;
	    }
	  else
	    {
	      sqlda -> sqlvar [i].sqlind = (short *)0;
	    }

		/* For sqldata, make sure we're on a 32-bit boundary: */
	  if (templen & 3)
	    templen = (templen + 3) & ~3;

	  sqlda -> sqlvar [i].sqldata = (char *)templen;
	  templen += len + baggage;
	}

	/* Now that we've figured out how big everything is, let's make
	   sure there's space for it: */
      if (save < templen)
	{
	  	/* Free the old hunk if there is one, and then
		   allocate a new one of the appropriate size: */
	  if (SqlData != (char *)0)
	    free (SqlData);
	  SqlData = (char *)malloc (templen);
	  SqlDataLen = templen;
	  if (SqlData == (char *)0)
	    {
	      return 1;
	    }
	}
      else
	{
		/* There's more than enough space, so remember the old
		   size... */
	  SqlDataLen = save;
	} /* End if */

      for (i = 0; i < sqlda -> sqld; i++)
	{
	  if (sqlda -> sqlvar [i].sqltype < 0)
	    {
	      sqlda -> sqlvar [i].sqlind =
		(short *)(SqlData + (int)(sqlda -> sqlvar [i].sqlind));
	    } /* End if */

	  sqlda -> sqlvar [i].sqldata =
	    SqlData + (int)(sqlda -> sqlvar [i].sqldata);
	} /* End for */
    }

  exec sql declare curs cursor for stmt;
  if (sqlca.sqlcode < 0)
    {
      return 1;
    }

  exec sql open curs;
  if (sqlca.sqlcode < 0)
    {
      return 1;
    }
  return 0;
} /* End do_sql_prepare() */





#ifdef DO_SQL_FETCH
int
do_sql_fetch(sp, items)
     register int sp;
     register int items;
{
  register STR *str;
  STR **st = stack->ary_array + sp;
  register ARRAY *ary = stack;
  register int i;
  register char *tmps;
  register STR *Str;		/* used in str_get and str_gnum macros */
  unsigned long len;

#ifdef DEBUG_SQL
printf ("Fetch:\n");
#endif
  exec sql fetch curs using descriptor :sqlda;

  if (sqlca.sqlcode != 0)
    {
      exec sql close curs;
#ifdef DEBUG_SQL
printf ("Done fetching\n");
#endif
      return sp-1;		/* Need this to return a null array */
    }
  
#ifdef DEBUG_SQL
  printf ("(");
#endif
  for (i = 0; i < sqlda -> sqld; i++)
    {
      int type;
      IISQLVAR *var = &sqlda -> sqlvar [i];
      union _data {
	char *c;
	double *f;
	float *sf;
	struct {
	  short l;
	  char c;
	} *v;
	int *i;
      } data;
      
#ifdef DEBUG_SQL
      if (i)
	printf (" ");
#endif

      data.c = var -> sqldata;
	      
      if (var -> sqltype < 0 && *(var -> sqlind) < 0)
	{
	  (void)astore(ary, sp++, str = str_mortal(&str_no));
	  str_set(str, "");
#ifdef DEBUG_SQL
	  printf ("<null value>");
#endif
	}
      else
	{
	  if (var -> sqltype < 0)
	    type = -var -> sqltype;
	  else
	    type = var -> sqltype;
	  
	  switch (type)
	    {
	    case 30:	/* int */
	      (void)astore(ary, sp++, str = str_mortal(&str_no));
	      str_numset(str, (double)(*data.i));
#ifdef DEBUG_SQL
	      printf ("%d", *data.i);
#endif
	      break;
		      
	    case 31:	/* float */
	      (void)astore(ary, sp++, str = str_mortal(&str_no));
	      if (var -> sqllen == sizeof (float))
		{
		  str_numset (str, (double)(*data.sf));
#ifdef DEBUG_SQL
	          printf ("%f", (double)(*data.sf));
#endif
		}
	      else
		{
	          str_numset(str, *data.f);
#ifdef DEBUG_SQL
	          printf ("%f", *data.f);
#endif
		}
	      break;
		      
	    case 20:	/* char */
	      data.c [var -> sqllen] = 0;
	      (void)astore(ary, sp++, str = str_mortal(&str_no));
	      str_set(str, data.c);
#ifdef DEBUG_SQL
	      printf ("'%s'", data.c);
#endif
	      break;

	    case 21:	/* varchar */
	      (&(data.v -> c)) [data.v -> l] = 0;
	      (void)astore(ary, sp++, str = str_mortal(&str_no));
	      str_set(str, &(data.v -> c));
#ifdef DEBUG_SQL
	      printf ("'%s'", data.v -> c);
#endif
	      break;
	    }
	}
    }
#ifdef DEBUG_SQL
  printf (")\n");
#endif
  return --sp;
}

#endif















/* =============================== EOF ============================== */

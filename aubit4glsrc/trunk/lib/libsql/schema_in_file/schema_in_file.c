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
# $Id: schema_in_file.c,v 1.1 2003-02-19 11:49:04 mikeaubury Exp $
#*/

/**
 * @file
 *
 * Module with implementations for sql functions for compilation
 * where the database is not currently available.
 * This reads from a flat file named 'db.schema' containing
 *
 * 	[tablename] 
 *          COLUMN_NAME AUBITDATATYPE AUBITSIZE
 *          COLUMN_NAME AUBITDATATYPE AUBITSIZE
 *          .
 *          .
 */

 /*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_lib_sql_int.h"
extern sqlca_struct sqlca;
/*
=====================================================================
                    Variables definitions
=====================================================================
*/

char lasterrorstr[1024] = "";

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

FILE *f_db_in;

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

/**
 *
 * @todo Describe function
 */
void
A4GLSQL_set_status (int a, int sql)
{
  status = a;
  if (sql) sqlca.sqlcode = a;
  debug ("Status set to %d", a);
}

/**
 *
 * @todo Describe function
 */
int
A4GLSQL_init_connection (char *dbName)
{
char fname[256];
  sprintf(fname,"%s.schema",dbName);
  f_db_in=open_file_dbpath(fname);
  if (f_db_in==0) {
		set_errm(fname);
		exitwith("Couldn't open schema file");
  }
	
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
	return global_A4GLSQL_get_sqlerrm ();
}

/**
 *
 * @todo Describe function
 */
int
A4GLSQL_read_columns (char *tabname, char *colname, int *dtype, int *size)
{
char *buff;
	if (f_db_in==0) { exitwith("Not connected to database"); return 0; }
debug("READ COLUMNS\n");
  A4GLSQL_get_columns(tabname,colname,dtype,size);

  while (A4GLSQL_next_column(&buff,dtype,size)) {
		if (strcasecmp(colname,buff)==0) return 1;
  }
return 0;
}

/**
 *
 * @todo Describe function
 */
int
A4GLSQL_initsqllib(void)
{
	return 1;
}

int
A4GLSQL_get_columns (char *tabname, char *colname, int *dtype, int *size) {
char buff[256];
char tname[256];
if (f_db_in==0) { exitwith("Not connected to database"); return 0; }

rewind(f_db_in);

while (1) {
	if (feof(f_db_in)) break;
	fgets(buff,255,f_db_in);
	debug("%s\n",buff);
	if (buff[0]=='[') {
		char *ptr;
		strcpy(tname,&buff[1]);
		ptr=strchr(tname,']');
		if (!ptr) {
			exitwith("Parse error in schema file - no ']'");
			return 0;
		}

		*ptr=0;

		debug("Checking table : %s %s\n",tname,tabname);
		if (strcasecmp(tname,tabname)==0) {
			// Found it...
			return 1;
		}
	}
}
set_errm(tabname);
exitwith("Table not found\n");
return 0;
}



int
A4GLSQL_end_get_columns(void)
{
  return 0;
}

int
A4GLSQL_next_column(char **colname, int *dtype,int *size) {
char buff[256];
static char cname[256];
int a;
if (f_db_in==0) { exitwith("Not connected to database"); return 0; }

// We should already be at the right spot....
fgets(buff,255,f_db_in);

// Is this a valid line ?
if (buff[0]=='[') return 0; // Obviously not - its another table...
a=sscanf(buff,"%s %d %d",cname,dtype,size);
if (a!=3) return 0;
*colname=cname;
debug("Got cname as %s\n",cname);
return 1;

}
/* =============================== EOF ============================== */

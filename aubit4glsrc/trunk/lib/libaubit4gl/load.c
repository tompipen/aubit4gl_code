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
# $Id: load.c,v 1.5 2002-05-18 11:56:47 afalout Exp $
#
*/

/**
 * @file
 * Load instruction implementation functions
 *
 * This is part of the run-time for 4gl programs.
 * Its called by generated program.
 *
 */


/*
=====================================================================
		                    Includes
=====================================================================
*/

#include <stdarg.h>
#include <stdio.h>
#include <string.h> //strlen() strcopy() strcat()

#include "a4gl_aubit_lib.h"
#include "a4gl_debug.h"
#include "a4gl_dlsql.h" //A4GLSQL_fill_array()

/*
=====================================================================
                    Constants definitions
=====================================================================
*/

/* tuneable */
#define MAXLOADCOLS 256
#define MAXCOLLENGTH 32
#define LOADBUFFSIZE 32000


/*
=====================================================================
                    Variables definitions
=====================================================================
*/


extern int status;

/// Buffer that contains the current line being loaded
char loadbuff[LOADBUFFSIZE];

/// Column name list where information is to be loaded
char col_list[MAXLOADCOLS][MAXCOLLENGTH];

/// Array with pointers to each delimiter in current load line
char *colptr[MAXLOADCOLS];


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/


/**
 * Find the delimiters in the line to be loaded.
 *
 * @param delim The delimiter that separates columns
 * @return The number of fields found
 */
static int 
find_delims(char delim)
{
  int cnt=1;
  int a;
//  char *ptr;
  colptr[0]=&loadbuff[0];

  for (a=0;a<strlen(loadbuff);a++)
  {
     if (loadbuff[a]==delim||loadbuff[a]==0)
     {
        colptr[cnt++]=&loadbuff[a+1];
     }
  }

  cnt--;

  for (a=1;a<=cnt;a++) *(colptr[a]-1)=0;

  for (a=0;a<cnt;a++) {
    debug("Field %d = %s",a,colptr[a]);
  }
  return cnt;
}

/**
 * Generates the column list to the sql insert statement
 *
 * @param cnt The count of columns
 * @return A pointer to a static buffer that contains twh column list generated
 */
static char *
collist_to_str(int cnt)
{
  static char colliststr[32000];
  int a;
  strcpy(colliststr,"");
  for (a=0;a<cnt;a++) 
  {
    if (a>0) strcat(colliststr,",");
    strcat(colliststr,col_list[a]);
  }
  return colliststr;
}

/**
 * Generate the insert instruction to inserting the current row
 *
 * @param tabname The table name
 * @param ncols The number of columns
 * @return The SQL insert string
 */
static char *
gen_insert_for_load(char *tabname,int ncols)
{
  static char inserttxt[6000];
  int a;
  strcpy(inserttxt,"");
  sprintf(inserttxt,
    "insert into %s (%s) values (",tabname,collist_to_str(ncols)
  );
  for (a=0;a<ncols;a++) 
  {
    if (a>0) strcat(inserttxt,",?");
    else strcat(inserttxt,"?");
  }
  strcat(inserttxt,")");
  return inserttxt;
}

/**
 * Strip the new line from the end of a string.
 *
 * If it finds a delimiter at the end - 2 put another one at new line place.
 *
 * @todo Take the fixed definition of pipe delimiter
 *
 * @param s The string where to strip new line
 */
static void 
stripnlload(char *s)
{
  int a;
  a=strlen(s);
  if (s[a-1]=='\n') 
  {
    if (s[a-2]!='|') 
        s[a-1]='|';
    else
        s[a-1]=0;
  }
}

/**
 * Implementation of the 4gl load instruction.
 *
 * Open the file, split the fields and insert them in the table
 * (of the database of course).
 *
 * @param fname The file name
 * @param delims The column delimiters. If the string is bigger then 1 only
 *               the first character is used as delimiter.
 * @param tabname The table name where we want to insert the values
 * @param ... Column list names as varargs
 * @return The sucess or not of the operation:
 *    - 0 : Error executing the load
 *    - 1 : OK
 */
int
A4GLSQL_load_data(char *fname,char *delims,char *tabname,...)
{
  va_list ap;
  char *colname;
  int cnt=0;
  char delim;
//  int linelength;
  int nfields;
  int lineno=0;
  char *insertstr;
  char filename[256];
  FILE *p;
  char buff[255];
  delim=delims[0];
  
  debug("In load_data");
  strcpy(filename,fname);
  trim(filename);
  p=mja_fopen(filename,"r");

  if (p==0) {
     exitwith("Could not open file for load");
     return 0;
  }

  va_start (ap, tabname);
  while (1) {
     colname=va_arg(ap,char *);
     if (colname==0) break;
     strcpy(col_list[cnt],colname);
     cnt++;
  }
  va_end(ap);
  if (cnt==0) {
     /* get columns from database */
     debug("Getting columns from database");
	// cnt=fill_array(MAXLOADCOLS,col_list,MAXCOLLENGTH-1,0,0,"COLUMNS",0,tabname);
     cnt=A4GLSQL_fill_array(MAXLOADCOLS,(char **)col_list,MAXCOLLENGTH-1,0,0,"COLUMNS",0,tabname);


     /*
      warning: passing arg 2 of `A4GLSQL_fill_array' from incompatible pointer type


	 int A4GLSQL_fill_array     (int mx, char **arr1, int szarr1,
	  char **arr2, int szarr2, char *service, int mode, char *info
	);

    /// Column name list where information is to be loaded
	char col_list[MAXLOADCOLS][MAXCOLLENGTH];



    */

  }

  debug("Read %d columns",cnt);

  if (cnt==0) {
         exitwith("Error in getting number of columns for load");
	 return 0;
  }

  insertstr=gen_insert_for_load(tabname,cnt);

  if  (A4GLSQL_add_prepare("_load",A4GLSQL_prepare_sql(insertstr))!=1) {
      exitwith("Internal Error : Error generating insert string for load");
      return 0;
  }

  debug("Insert string=%s & prepared\n",insertstr);

  while (1) {
      lineno++;
      fgets(loadbuff,LOADBUFFSIZE-1,p);
      if (feof(p)) {
            debug("Got to end of the file");
            break;
      }
      stripnlload(loadbuff);
      debug("Read line '%s'",loadbuff);
      nfields=find_delims(delim);
      debug("nfields=%d number of columns=%d",nfields,cnt);
      if (nfields!=cnt) {
	 sprintf(buff,"%d",cnt);
         set_errm(buff);
         exitwith("Number of fields in load file does not equal the number of columns %s");
         return 0;
      }

	A4GLSQL_set_status(0,1);

      A4GLSQL_execute_sql_from_ptr("_load",cnt,colptr);
      if (status!=0) {
	   sprintf(buff,"%d",cnt);
           set_errm(buff);
           exitwith("Error reading load file at line %s");
      }
  }
  fclose(p);
  return 1;
}


// ============================== EOF ================================

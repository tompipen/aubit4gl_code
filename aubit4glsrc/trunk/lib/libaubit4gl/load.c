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
# $Id: load.c,v 1.27 2005-03-09 15:14:40 mikeaubury Exp $
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

#include "a4gl_libaubit4gl_int.h"
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


/* Buffer that contains the current line being loaded */
char loadbuff[LOADBUFFSIZE];

/* Column name list where information is to be loaded */
char col_list[MAXLOADCOLS][MAXCOLLENGTH];

/* Array with pointers to each delimiter in current load line */
char *colptr[MAXLOADCOLS];


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

int A4GLSQL_load_data (char *fname, char *delims, char *tabname, ...);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * Find the delimiters in the line to be loaded.
 *
 * @param delim The delimiter that separates columns
 * @return The number of fields found
 */
static int
find_delims (char delim)
{
  int cnt = 1;
  int a;
  colptr[0] = &loadbuff[0];

  for (a = 0; a < strlen (loadbuff); a++)
    {
      if (loadbuff[a] == delim || loadbuff[a] == 0)
	{
	  colptr[cnt++] = &loadbuff[a + 1];
	}
    }

  cnt--;

  for (a = 1; a <= cnt; a++)
    *(colptr[a] - 1) = 0;

  for (a = 0; a < cnt; a++)
    {
      A4GL_debug ("Field %d = %s", a, colptr[a]);
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
collist_to_str (int cnt)
{
  static char colliststr[32000];
  int a;
  strcpy (colliststr, "");
  for (a = 0; a < cnt; a++)
    {
      if (a > 0)
	strcat (colliststr, ",");
      strcat (colliststr, col_list[a]);
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
gen_insert_for_load (char *tabname, int ncols)
{
  static char inserttxt[6000];
  int a;
  strcpy (inserttxt, "");
  sprintf (inserttxt, "INSERT INTO %s (%s) values (", tabname, collist_to_str (ncols));
  for (a = 0; a < ncols; a++)
    {
      if (a > 0)
	strcat (inserttxt, ",?");
      else
	strcat (inserttxt, "?");
    }
  strcat (inserttxt, ")");
  return inserttxt;
}

/**
 * Strip the new line from the end of a string.
 *
 * If it finds a delimiter at the end - put another one at new line place.
 *
 * @todo Take the fixed definition of pipe delimiter
 *
 * @param s The string where to A4GL_strip new line
 */
static void
stripnlload (char *s, char delim)
{
  int a;
  a = strlen (s);
  if (s[a - 1] == '\n')
    {
      if (s[a - 2] != delim)
	s[a - 1] = delim;
      else
	s[a - 1] = 0;
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
A4GLSQL_load_data (char *fname, char *delims, char *tabname, ...)
{
  va_list ap;
  char *colname;
  int cnt = 0;
  char delim;
  int nfields;
  int lineno = 0;
 
  char *insertstr;
  char filename[1024];
  FILE *p;
  struct BINDING *ibind = 0;
  char buff[255];
  int a;

//void *v;

  delim = delims[0];


  A4GL_debug ("In load_data");
  strncpy (filename, fname,sizeof(filename));
  filename[1023]=0; // Just to make sure...

  A4GL_trim (filename);
  p = A4GL_mja_fopen (filename, "r");

  if (p == 0)
    {
      A4GL_exitwith ("Could not open file for load");
      return 0;
    }

  va_start (ap, tabname);
  while (1)
    {
      colname = va_arg (ap, char *);
      if (colname == 0)
	break;
      A4GL_debug ("Adding %s to col_list", colname);
      strcpy (col_list[cnt], colname);
      cnt++;
    }
  va_end (ap);
  if (cnt == 0)
    {
      /* get columns from database */
      A4GL_debug ("Getting columns from database");
      cnt =
	A4GLSQL_fill_array (MAXLOADCOLS, (char *) col_list, MAXCOLLENGTH - 1,
			    0, 0, "COLUMNS", 0, tabname);

    }

  A4GL_debug ("Read %d columns", cnt);

  if (cnt == 0)
    {
      A4GL_exitwith ("Error in getting number of columns for load");
      return 0;
    }
  A4GL_debug ("Calling gen_insert_for_load %s %d\n", tabname, cnt);

  insertstr = gen_insert_for_load (tabname, cnt);


  A4GL_debug ("Adding prepare.. for %s",insertstr);


  if (A4GLSQL_add_prepare ("load", A4GLSQL_prepare_sql (insertstr)) != 1) { A4GL_exitwith ("Internal Error : Error generating insert string for load"); return 0; }


  while (1)
    {
      lineno++;
      fgets (loadbuff, LOADBUFFSIZE - 1, p);



      if (feof (p))
	{
	  A4GL_debug ("Got to end of the file");
	  break;
	}
      stripnlload (loadbuff, delim);
      A4GL_debug ("Read line '%s'", loadbuff);
      nfields = find_delims (delim);
      A4GL_debug ("nfields=%d number of columns=%d", nfields, cnt);
	if (nfields==0 && delim==0) nfields=1; // No delimiter - whole line...

      if (nfields != cnt)
	{
	  sprintf (buff, "%d", cnt);
	  A4GL_set_errm (buff);
	  A4GL_exitwith ("Number of fields in load file does not equal the number of columns %s");
	  return 0;
	}

      A4GLSQL_set_status (0, 1);

      if (ibind) { free (ibind); }

      ibind = malloc (sizeof (struct BINDING) * cnt);
      for (a = 0; a < cnt; a++)
	{
	  A4GL_debug ("Binding %s @ %d", colptr[a], a);


	  ibind[a].ptr = colptr[a];
	  ibind[a].dtype = 0;
	
	  if (strlen(colptr[a])==0) {
	  ibind[a].size = 1;
	  } else {
	  ibind[a].size = strlen (colptr[a]);
	  }
	}


      A4GLSQL_execute_sql ("load", cnt, ibind);

	//printf("EXECUTE : %d %d\n",lineno,a4gl_status);

      if (a4gl_status != 0 || A4GL_get_a4gl_sqlca_sqlcode()!=0)
	{
	  sprintf (buff, "%d", cnt);
	  A4GL_set_errm (buff);
	  A4GL_exitwith ("Error reading load file at line %s");
  		fclose (p);
	  return 0;
	}
    }

  fclose (p);
  return 1;
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
A4GLSQL_load_data_str (char *fname, char *delims, char *sqlstmt_orig)
{
  //va_list ap;
  //char *colname;
  int cnt = 0;
  char delim;
  int nfields;
  int lineno = 0;
  //char *insertstr;
  char filename[256];
  FILE *p;
  struct BINDING *ibind = 0;
  char buff[255];
  int a;
  int prepared=0;
  static char *sqlstmt=0;
  delim = delims[0];

  if (sqlstmt) free(sqlstmt);
  sqlstmt=strdup(sqlstmt_orig);
  A4GL_debug ("In load_data");
  strcpy (filename, fname);
  A4GL_trim (filename);
  p = A4GL_mja_fopen (filename, "r");

  if (p == 0)
    {
      A4GL_exitwith ("Could not open file for load");
      return 0;
    }
  cnt=0;

  for (a=0;a<strlen(sqlstmt);a++) { if (sqlstmt[a]=='?') cnt++; }


  while (1)
    {
      lineno++;
      fgets (loadbuff, LOADBUFFSIZE - 1, p);
      if (feof (p))
	{
	  A4GL_debug ("Got to end of the file");
	  break;
	}
      stripnlload (loadbuff, delim);
      A4GL_debug ("Read line '%s'", loadbuff);
      nfields = find_delims (delim);
      A4GL_debug ("nfields=%d number of columns=%d", nfields, cnt);

      if (nfields != cnt && cnt)
	{
	  sprintf (buff, "%d", cnt);
	  A4GL_set_errm (buff);
	  A4GL_exitwith ("Number of fields in load file does not equal the number of columns %s");
	  return 0;
	}

      if (!prepared) {
		prepared=1;
		if (cnt==0) {
			int a;
			free(sqlstmt);
			sqlstmt=malloc(strlen(sqlstmt_orig)+ (nfields * 4) + 10000);
			
			strcpy(sqlstmt,sqlstmt_orig);
			A4GL_trim(sqlstmt);
			strcat(sqlstmt," VALUES (");
			for (a=0;a<nfields;a++) {
				if (a) strcat(sqlstmt,",");
				strcat(sqlstmt,"?");
			}
			strcat(sqlstmt,")");
		}

  		if (A4GLSQL_add_prepare ("load", A4GLSQL_prepare_sql (sqlstmt)) != 1) { 
			A4GL_exitwith ("Internal Error : Error generating insert string for load"); 
			return 0; 
		}

      }

      A4GLSQL_set_status (0, 1);
      if (ibind)
	{
	  free (ibind);
	}
      ibind = malloc (sizeof (struct BINDING) * nfields);
      for (a = 0; a < nfields; a++)
	{
	  A4GL_debug ("Binding %s @ %d", colptr[a], a);
	  ibind[a].ptr = colptr[a];
	  ibind[a].dtype = 0;
	  ibind[a].size = strlen (colptr[a]);
	}
      A4GL_debug ("EXECUTE SQL nfields=%d", nfields);
      A4GLSQL_execute_sql ("load", nfields, ibind);

      if (a4gl_status != 0)
	{
	  sprintf (buff, "%d", nfields);
	  A4GL_set_errm (buff);
	  A4GL_exitwith ("Error reading load file at line %s");
	}
    }
  fclose (p);
  return 1;
}


/* ============================== EOF ================================ */

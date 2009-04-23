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
# | contact licensing@aubit.com                                           |
# +----------------------------------------------------------------------+
#
# $Id: load.c,v 1.57 2009-02-23 17:31:50 mikeaubury Exp $
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
#define MAXLOADCOLS 1024
#define MAXCOLLENGTH 32
#define LOADBUFFSIZE 32000


static int doing_load = 0;
/*
=====================================================================
                    Variables definitions
=====================================================================
*/


/* Buffer that contains the current line being loaded */
static char loadbuff[LOADBUFFSIZE];

/* Column name list where information is to be loaded */
static char col_list[MAXLOADCOLS][MAXCOLLENGTH];

/* Array with pointers to each delimiter in current load line */
static char *colptr[MAXLOADCOLS];
extern sqlca_struct a4gl_sqlca;


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

//int A4GLSQL_load_data (char *fname, char *delims, char *tabname, ...);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/




#define LOAD_ORIG
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
  int ml;

  ml = strlen (loadbuff);
  /* Convert to unix format - if its msdos */
  if (loadbuff[ml - 2] == '\r' && loadbuff[ml - 1] == '\n')
    {
      ml--;
      loadbuff[ml - 2] = '\n';
      loadbuff[ml - 1] = 0;
    }
  colptr[0] = &loadbuff[0];
  for (a = 0; a < ml; a++)
    {
	
	char last_char=0;
	if (a) {
		last_char=loadbuff[a-1];
		if (a>1) {
			if (last_char=='\\' && loadbuff[a-2]=='\\') {
				// Escape the escape..
				last_char=0;
			}
		}
	}
      if ((loadbuff[a] == delim && last_char!='\\') || loadbuff[a] == 0)
	{
	  colptr[cnt++] = &loadbuff[a + 1];
	}
    }

  cnt--;

  for (a = 1; a <= cnt; a++)
    *(colptr[a] - 1) = 0;

  for (a = 0; a < cnt; a++)
    {
      //printf ("Field %d = %s\n", a, colptr[a]);
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
  SPRINTF2 (inserttxt, "INSERT INTO %s (%s) values (", tabname, collist_to_str (ncols));
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
  if (strchr (s, '\r'))
    {
      int a;
      char *p;
      int b = 0;
      p = strdup (s);
      for (a = 0; a < strlen (s); a++)
	{
	  if (s[a] != '\r')
	    {
	      p[b++] = s[a];
	    }
	}
      p[b] = 0;
      strcpy (s, p);
      free (p);
    }

  a = strlen (s);

//printf("strlen=%d actual=%d s[a-1]=%d\n",a,strlen(s), s[a-1]);
  if (s[a - 1] == '\n')
    {
      if (s[a - 2] != delim)
	{
	  s[a - 1] = delim;
	}
      else
	s[a - 1] = 0;
    }
//printf("s='%s'\n",s);
}




static int
clr_colptr (int freeit)
{
  int a;
  for (a = 0; a < MAXLOADCOLS; a++)
    {
      if (freeit)
	{
	  if (colptr[a])
	    {
	      free (colptr[a]);
	    }
	}
      colptr[a] = NULL;
    }
  return 1;
}

#ifdef LOAD_ORIG
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
A4GL_load_data (char *fname, char *delims, void *filterfunc, char *tabname, ...)
{
  va_list ap;
  char *colname;
  int cnt = 0;
  char delim = 0;
  int nfields;
  int lineno = 0;

  char *insertstr;
  char filename[1024];
  FILE *p;
  struct BINDING *ibind = 0;
  char buff[255];
char nullbuff[200];
  int a;
//printf("%d %s\n",doing_load,fname);

  if (doing_load)
    {
      A4GL_exitwith ("Cant do a load within a load...");
      return 0;
    }
  doing_load++;

//void *v;
  if (delims)
    {
      delim = delims[0];
    }


  A4GL_debug ("In load_data - LOAD_ORIG");
  strncpy (filename, fname, sizeof (filename));
  filename[1023] = 0;		// Just to make sure...

  A4GL_trim (filename);
  p = A4GL_mja_fopen (filename, "r");

  if (p == 0)
    {
      A4GL_exitwith ("Could not open file for load");
      doing_load = 0;
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
      cnt = A4GLSQL_fill_array (MAXLOADCOLS, (char *) col_list, MAXCOLLENGTH - 1, 0, 0, "COLUMNS", 0, tabname);

    }

  A4GL_debug ("Read %d columns", cnt);

  if (cnt == 0)
    {
      aclfgli_clr_err_flg ();
      a4gl_sqlca.sqlcode = 0;
      a4gl_status = 0;
      A4GL_set_errm (tabname);
      A4GL_exitwith ("Error in getting number of columns for load (does the table '%s' exist?)");
      doing_load = 0;
      return 0;
    }
  A4GL_debug ("Calling gen_insert_for_load %s %d\n", tabname, cnt);

  insertstr = gen_insert_for_load (tabname, cnt);


  A4GL_debug ("Adding prepare.. for %s", insertstr);


  if (A4GL_add_prepare ("load", A4GL_prepare_select (0, 0, 0, 0, insertstr, "__internal_load", 23, 0, 0)) != 1)
    {
      A4GL_exitwith ("Internal Error : Error generating insert string for load");
      doing_load = 0;
      return 0;
    }

  if (filterfunc)
    {
      clr_colptr (0);
    }


  A4GL_setnull (DTYPE_CHAR, nullbuff, 1);
  while (1)
    {
      strcpy (loadbuff, "");
      fgets (loadbuff, LOADBUFFSIZE - 1, p);
      A4GL_debug ("Read line '%s'\n", loadbuff);
      if (feof (p) && strlen (loadbuff))
	{
	  if (loadbuff[strlen (loadbuff) - 1] != '\n')
	    {
	      strcat (loadbuff, "\n");
	    }
	}

      if (strlen (loadbuff) == 0)
	break;

      lineno++;
      stripnlload (loadbuff, delim);
      A4GL_debug ("Read line '%s'\n", loadbuff);
      if (filterfunc)
	{
	  // We're using a filter function.
	  // this is a special 4gl function which we pass in the string
	  // and it returns the values to insert
	  //
	  // If the function returns no values - then we skip the line.....
	  //
	  int a;
	  int (*func) (int);
	  int ml;
	  func = filterfunc;
	  clr_colptr (1);

	  ml = strlen (loadbuff);
	  if (loadbuff[ml - 2] == '\r' && loadbuff[ml - 1] == '\n')
	    {
	      loadbuff[ml - 2] = 0;
	    }
	  if (loadbuff[ml - 1] == '\n')
	    {
	      loadbuff[ml - 1] = 0;
	    }

	  // Push the current line 
	  A4GL_push_char (loadbuff);
	  // Call the function with 1 parameter
	  nfields = func (1);
	  // Did we get any values ? 
	  if (nfields == 0)
	    continue;		/* We're skipping this line.. */
	  // Put them into our column data pointers...
	  // we'll need to free these - hence all the clr_colptr's around...
	  for (a = nfields - 1; a >= 0; a--)
	    {
	      colptr[a] = A4GL_char_pop ();
	    }
	}
      else
	{
	  nfields = find_delims (delim);
	}
      A4GL_debug ("nfields=%d number of columns=%d", nfields, cnt);
      if (nfields == 0 && delim == 0)
	nfields = 1;		// No delimiter - whole line...

      if (nfields != cnt)
	{
	  if (filterfunc)
	    {
	      clr_colptr (1);
	    }
	  SPRINTF3 (buff, "%d!=%d @ %d", nfields, cnt, lineno);
	  A4GL_set_errm (buff);
	  A4GL_exitwith ("Number of fields in load file does not equal the number of columns %s");
	  doing_load = 0;
	  return 0;
	}

      A4GL_set_status (0, 1);

      if (ibind)
	{
	  free (ibind);
	}

      ibind = acl_malloc2 (sizeof (struct BINDING) * cnt);
      for (a = 0; a < cnt; a++)
	{
	int b;
	
	  A4GL_debug ("Binding %s @ %d", colptr[a], a);


	  ibind[a].ptr = colptr[a];
	  ibind[a].dtype = DTYPE_CHAR;
	  ibind[a].start_char_subscript = 0;
	  ibind[a].end_char_subscript = 0;
	  ibind[a].libptr = 0;

	  if (strlen (colptr[a]) == 0)
	    {
	      ibind[a].size = 1;
		ibind[a].ptr=nullbuff;
	      //A4GL_setnull (ibind[a].dtype, ibind[a].ptr, 1);
	    }
	  else
	    {
	      ibind[a].size = strlen (colptr[a]);
	    }
	}


      A4GL_execute_sql ("load", cnt, ibind);


      if (a4gl_status != 0 || A4GL_get_a4gl_sqlca_sqlcode () != 0)
	{
	  if (filterfunc)
	    {
	      clr_colptr (1);
	    }
	  SPRINTF1 (buff, "%d", cnt);
	  A4GL_set_errm (buff);
	  A4GL_exitwith ("Error reading load file at line %s");
	  fclose (p);
	  doing_load = 0;
	  return 0;
	}
      if (feof (p))
	{
	  A4GL_debug ("Got to end of the file");
	  break;
	}
    }
  a4gl_sqlca.sqlerrd[2] = lineno;	// sqlerrd[3] in 4gl
  fclose (p);
  if (filterfunc)
    {
      clr_colptr (1);
    }
  doing_load = 0;
  return 1;
}



#else



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
A4GL_load_data (char *fname, char *delims, void *filterfunc, char *tabname, ...)
{
  va_list ap;
  char *colname;
  int cnt = 0;
  char delim = 0;
  int nfields;
  int lineno = 0;

  char *insertstr;
  char filename[1024];
  FILE *p;
  struct BINDING *ibind = 0;
  char buff[255];
  int a;
  struct BINDING fake_ibind[1] = { {0, 0, 0, 0, 0, 0} };
  int use_insert_cursor = -1;

  if (doing_load)
    {
      A4GL_exitwith ("Cant do a load within a load...");
      return 0;
    }
  doing_load = 1;


  A4GL_assertion (filterfunc != NULL, "Not implemented - thought we were using LOAD_ORIG");

  if (use_insert_cursor == -1)
    {
      if (A4GL_isyes (acl_getenv ("USECURSORFORLOAD")))
	{
	  use_insert_cursor = 1;
	}
      else
	{
	  use_insert_cursor = 0;
	}
    }

//void *v;

  delim = delims[0];


  A4GL_debug ("In load_data");
  strncpy (filename, fname, sizeof (filename));
  filename[1023] = 0;		// Just to make sure...

  A4GL_trim (filename);
  p = A4GL_mja_fopen (filename, "r");

  if (p == 0)
    {
      A4GL_exitwith ("Could not open file for load");
      doing_load = 0;
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
      cnt = A4GLSQL_fill_array (MAXLOADCOLS, (char *) col_list, MAXCOLLENGTH - 1, 0, 0, "COLUMNS", 0, tabname);

    }

  A4GL_debug ("Read %d columns", cnt);

  if (cnt == 0)
    {
      A4GL_exitwith ("Error in getting number of columns for load");
      doing_load = 0;
      return 0;
    }
  A4GL_debug ("Calling gen_insert_for_load %s %d\n", tabname, cnt);

  insertstr = gen_insert_for_load (tabname, cnt);


  A4GL_debug ("Adding prepare.. for %s", insertstr);


  if (use_insert_cursor)
    {
      ibind = acl_malloc2 (sizeof (struct BINDING) * cnt);
      for (a = 0; a < cnt; a++)
	{
	  ibind[a].ptr = colptr[a];
	  colptr[a] = "";
	  ibind[a].dtype = DTYPE_CHAR;
	  ibind[a].start_char_subscript = 0;
	  ibind[a].end_char_subscript = 0;
	}
      A4GL_debug ("Declare..\n");

      A4GL_add_prepare ("a4gl_pload", (void *) A4GL_prepare_select (0, 0, 0, 0, insertstr, "__internal_load", 1, 0));

      A4GL_declare_cursor (0 + 0, A4GL_find_prepare ("a4gl_pload"), 0, "a4gl_load");

      A4GL_debug ("Open..\n");

      A4GL_open_cursor ("a4gl_load", 0, 0);

    }
  else
    {
      if (A4GL_add_prepare ("load", A4GL_prepare_select (0, 0, 0, 0, insertstr, "__internal_load", 22, 0)) != 1)
	{
	  A4GL_exitwith ("Internal Error : Error generating insert string for load");
	  doing_load = 0;
	  return 0;
	}
    }



  while (1)
    {
      strcpy (loadbuff, "");
      fgets (loadbuff, LOADBUFFSIZE - 1, p);


      if (feof (p))
	{
	  A4GL_debug ("Got to end of the file");
	  break;
	}
      lineno++;
      stripnlload (loadbuff, delim);
      //printf ("Read line '%s'", loadbuff);
      nfields = find_delims (delim);
      A4GL_debug ("nfields=%d number of columns=%d", nfields, cnt);
      if (nfields == 0 && delim == 0)
	nfields = 1;		// No delimiter - whole line...

      if (nfields != cnt)
	{
	  SPRINTF1 (buff, "%d!=%d @ %d", nfields, cnt, lineno);
	  A4GL_set_errm (buff);
	  A4GL_exitwith ("Number of fields in load file does not equal the number of columns %s");
	  doing_load = 0;
	  return 0;
	}

      A4GL_set_status (0, 1);

      //if (ibind) { free (ibind); }


      if (!use_insert_cursor)
	{
	  if (ibind == 0)
	    {
	      ibind = acl_malloc2 (sizeof (struct BINDING) * cnt);
	      for (a = 0; a < cnt; a++)
		{
		  colptr[a] = "";
		  ibind[a].ptr = colptr[a];

		  ibind[a].dtype = DTYPE_CHAR;
		  ibind[a].start_char_subscript = 0;
		  ibind[a].end_char_subscript = 0;
		}
	    }
	}



      for (a = 0; a < cnt; a++)
	{
	  A4GL_debug ("Binding %s @ %d", colptr[a], a);

	  ibind[a].ptr = colptr[a];
	  if (strlen (colptr[a]) == 0)
	    {
	      ibind[a].size = 1;
	    }
	  else
	    {
	      ibind[a].size = strlen (colptr[a]);
	    }
	}


      if (use_insert_cursor)
	{
	  A4GL_debug ("Put");
	  A4GL_push_char ("a4gl_load");
	  A4GL_put_insert (ibind, cnt);
	}
      else
	{
	  A4GL_execute_sql ("load", cnt, ibind);
	}


      if (a4gl_status != 0 || A4GL_get_a4gl_sqlca_sqlcode () != 0)
	{
	  SPRINTF1 (buff, "%d", cnt);
	  A4GL_set_errm (buff);
	  A4GL_exitwith ("Error reading load file at line %s");
	  fclose (p);
	  doing_load = 0;
	  return 0;
	}
    }

  if (use_insert_cursor)
    {
      A4GL_debug ("Close");
      A4GL_close_cursor ("a4gl_load");
    }

  if (ibind)
    free (ibind);
  a4gl_sqlca.sqlerrd[2] = lineno;	// sqlerrd[3] in 4gl
  fclose (p);
  doing_load = 0;
  return 1;
}



#endif


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
A4GL_load_data_str (char *fname, char *delims, void *filterfunc, char *sqlstmt_orig)
{
  //va_list ap;
  //char *colname;
  int cnt = 0;
  char delim = 0;
  int nfields;
  int lineno = 0;
  //char *insertstr;
  char filename[256];
  FILE *p;
  struct BINDING *ibind = 0;
  char buff[255];
  int a;
  int l;
  int prepared = 0;
  static char *sqlstmt = 0;

  if (doing_load)
    {
      A4GL_exitwith ("Cant do a load within a load...");
      return 0;
    }
  doing_load = 1;
  if (delims)
    {
      delim = delims[0];
    }

  if (sqlstmt)
    free (sqlstmt);
  sqlstmt = acl_strdup (sqlstmt_orig);
  A4GL_debug ("In load_data");
  strcpy (filename, fname);
  A4GL_trim (filename);
  p = A4GL_mja_fopen (filename, "r");
  if (p == 0)
    {
      A4GL_exitwith ("Could not open file for load");
      doing_load = 0;
      return 0;
    }
  cnt = 0;
  l = strlen (sqlstmt);
  for (a = 0; a < l; a++)
    {
      if (sqlstmt[a] == '?')
	cnt++;
    }
  if (filterfunc)
    {
      clr_colptr (0);
    }


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
      if (filterfunc)
	{
	  // We're using a filter function.
	  // this is a special 4gl function which we pass in the string
	  // and it returns the values to insert
	  //
	  // If the function returns no values - then we skip the line.....
	  //
	  int a;
	  int (*func) (int);
	  int ml;
	  func = filterfunc;
	  clr_colptr (1);

	  ml = strlen (loadbuff);
	  if (loadbuff[ml - 2] == '\r' && loadbuff[ml - 1] == '\n')
	    {
	      loadbuff[ml - 2] = 0;
	    }
	  if (loadbuff[ml - 1] == '\n')
	    {
	      loadbuff[ml - 1] = 0;
	    }

	  // Push the current line 
	  A4GL_push_char (loadbuff);
	  // Call the function with 1 parameter
	  nfields = func (1);
	  // Did we get any values ? 
	  if (nfields == 0)
	    continue;		/* We're skipping this line.. */
	  // Put them into our column data pointers...
	  // we'll need to free these - hence all the clr_colptr's around...
	  for (a = nfields - 1; a >= 0; a--)
	    {
	      colptr[a] = A4GL_char_pop ();
	    }
	}
      else
	{
	  nfields = find_delims (delim);
	}
      A4GL_debug ("nfields=%d number of columns=%d", nfields, cnt);

      if (nfields != cnt && cnt)
	{
	  SPRINTF3 (buff, "%d!=%d @ %d", nfields, cnt, lineno);
	  A4GL_set_errm (buff);
	  A4GL_exitwith ("Number of fields in load file does not equal the number of columns %s");
	  if (filterfunc)
	    {
	      clr_colptr (1);
	    }
	  doing_load = 0;
	  return 0;
	}

      if (!prepared)
	{
	  prepared = 1;
	  if (cnt == 0)
	    {
	      int a;
	      free (sqlstmt);
	      sqlstmt = acl_malloc2 (strlen (sqlstmt_orig) + (nfields * 4) + 10000);

	      strcpy (sqlstmt, sqlstmt_orig);
	      A4GL_trim (sqlstmt);
	      strcat (sqlstmt, " VALUES (");
	      for (a = 0; a < nfields; a++)
		{
		  if (a)
		    strcat (sqlstmt, ",");
		  strcat (sqlstmt, "?");
		}
	      strcat (sqlstmt, ")");
	    }

	  if (A4GL_add_prepare ("load", A4GL_prepare_select (0, 0, 0, 0, sqlstmt, "_internal_load", 24, 0, 0)) != 1)
	    {
	      if (filterfunc)
		{
		  clr_colptr (1);
		}
	      A4GL_exitwith ("Internal Error : Error generating insert string for load");
	      doing_load = 0;
	      return 0;
	    }

	}

      A4GL_set_status (0, 1);
      if (ibind)
	{
	  free (ibind);
	}
      ibind = acl_malloc2 (sizeof (struct BINDING) * nfields);
      for (a = 0; a < nfields; a++)
	{
	  A4GL_debug ("Binding %s @ %d", colptr[a], a);
	  ibind[a].ptr = colptr[a];
	  ibind[a].dtype = DTYPE_CHAR;
	  ibind[a].size = strlen (colptr[a]);
	ibind[a].start_char_subscript=0;
	ibind[a].end_char_subscript=0;
	ibind[a].libptr=0;
	}
      A4GL_debug ("EXECUTE SQL nfields=%d", nfields);
      A4GL_execute_sql ("load", nfields, ibind);

      if (a4gl_status != 0)
	{
	  SPRINTF1 (buff, "%d", nfields);
	  A4GL_set_errm (buff);
	  A4GL_exitwith ("Error reading load file at line %s");
	}
    }
  fclose (p);
  if (filterfunc)
    {
      clr_colptr (1);
    }
  doing_load = 0;
  return 1;
}





#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LBUFSIZ 1000



int
aclfgl_aclfgl_parse_csv (int n)
{

  static char *line1 = 0;
  static char *line2 = 0;
  static char *line3 = 0;	/* Each field in the line */
  char *stptr;
  int idx = 0;
  int lcount = 0;		/* Cell Seperator */
  int xcnt = 0;


  if (line1)
    {
      free (line1);
      line1 = 0;
    }
  if (line2)
    {
      free (line2);
      line2 = 0;
    }
  if (line3)
    {
      free (line3);
      line3 = 0;
    }

  line1 = A4GL_char_pop ();
  line2 = strdup (line1);
  line3 = strdup (line1);

  lcount = 0;
  strcpy (line2, line1);
  stptr = line2;

/* start going character by character thro the line */
  while (*stptr != '\0')
    {
      lcount++;
/* If field begins with " */
      if (*stptr == '"')
	{
	  int flag = 0;
	  idx = 0;
	  while (flag == 0)
	    {

	      stptr++;
/* Find corresponding closing " */
	      while (*stptr != '"')
		{
		  line3[idx] = *stptr;
		  idx++;
		  stptr++;
		}

	      stptr++;
	      if (*stptr != '\0' && *stptr == ',')
		{

		  line3[idx] = '\0';
		  xcnt++;
		  A4GL_push_char (line3);
		  flag = 1;
		}
	      else if (*stptr != '\0' && *stptr == '"')
		{
		  line3[idx] = *stptr;
		  idx++;
		}
	      else
		{

		  line3[idx] = '\0';
		  xcnt++;
		  A4GL_push_char (line3);
		  flag = 1;
		}
	    }
	}
      else
	{
	  idx = 0;
	  while (*stptr != '\0' && *stptr != ',')
	    {
	      line3[idx] = *stptr;
	      idx++;
	      stptr++;
	    }
	  line3[idx] = '\0';
	  xcnt++;
	  A4GL_push_char (line3);
	}
      if (*stptr != '\0' && *stptr == ',')
	stptr++;
      strcpy (line2, stptr);
      stptr = line2;
    }

  return xcnt;


}

int
aclfgl_aclfgl_split_on_delimiter (int n)
{
  int cnt = 1;
  int a;
  int ml;
  char *delim = "|";
  char *cptr[MAXLOADCOLS];
  char *lbuff;

  if (n == 1)
    {
      lbuff = A4GL_char_pop ();
    }
  if (n == 2)
    {
      lbuff = A4GL_char_pop ();
      delim = A4GL_char_pop ();
    }

  ml = strlen (lbuff);
  /* Convert to unix format - if its msdos */
  if (lbuff[ml - 2] == '\r' && lbuff[ml - 1] == '\n')
    {
      ml--;
      lbuff[ml - 2] = '\n';
      lbuff[ml - 1] = 0;
    }
  cptr[0] = &lbuff[0];
  for (a = 0; a <= ml; a++)
    {
      if (lbuff[a] == delim[0] || lbuff[a] == 0)
	{
	  cptr[cnt++] = &lbuff[a + 1];
	}
    }

  cnt--;

  for (a = 1; a <= cnt; a++)
    *(cptr[a] - 1) = 0;

  for (a = 0; a < cnt; a++)
    {
      A4GL_push_char (cptr[a]);
    }


  free (lbuff);
  return cnt;
}

/* ============================== EOF ================================ */

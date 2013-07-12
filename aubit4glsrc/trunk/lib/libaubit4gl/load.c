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
# $Id: load.c,v 1.66 2013-07-12 13:00:29 mikeaubury Exp $
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
#include <ctype.h>
/*
=====================================================================
                    Constants definitions
=====================================================================
*/

/* tuneable */
#define MAXLOADCOLS 1024
#define MAXCOLLENGTH 32
#define LOADBUFFSIZE 64000


static int doing_load = 0;
/*
=====================================================================
                    Variables definitions
=====================================================================
*/


/* Buffer that contains the current line being loaded */
static char loadbuff[LOADBUFFSIZE];
static char loadbufftmp[LOADBUFFSIZE];

/* Column name list where information is to be loaded */
static char col_list[MAXLOADCOLS][MAXCOLLENGTH];
static int col_list_types[MAXLOADCOLS];

/* Array with pointers to each delimiter in current load line */
static char *colptr[MAXLOADCOLS];
extern sqlca_struct a4gl_sqlca;

fgltext text_vars[MAXLOADCOLS];
fglbyte byte_vars[MAXLOADCOLS];

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

static int isHex(char c) {
if (c>='0' && c<='9') return 1;
if (c>='A' && c<='Z') return 1;
if (c>='a' && c<='z') return 1;
return 0;
}

static char mkHex(char c1,char c2) {
int l;
int r;
	c1=tolower(c1);
	c2=tolower(c2);
	if (c2>='0' && c2<='9') r=c2-'0'; else { r=c2-'a'+10;}
	if (c1>='0' && c1<='9') l=c1-'0'; else { l=c1-'a'+10;}
	return l*16+r;
}

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
  char *lbuff;
  ml = strlen (loadbuff);
  /* Convert to unix format - if its msdos */
  if (loadbuff[ml - 2] == '\r' && loadbuff[ml - 1] == '\n')
    {
      ml--;
      loadbuff[ml - 2] = '\n';
      loadbuff[ml - 1] = 0;
    }
  colptr[0] = &loadbuff[0];
  int b=0;
int copiedNonPrintableData=0;
	// Do we have any non-printable characters ? 
  if (strchr(loadbuff,'\\')) {
  	lbuff=malloc(ml+1);
  	for (a = 0; a <= ml; a++)
    	{
		if (a<ml-2 && loadbuff[a]=='\\' && isHex(loadbuff[a+1]) &&  isHex(loadbuff[a+2])) {
			
			lbuff[b++]=mkHex(loadbuff[a+1], loadbuff[a+2]);
			copiedNonPrintableData=1;
			a+=2;
			continue;
		}
		lbuff[b++]=loadbuff[a];
    	}
	if (copiedNonPrintableData) {
		//printf("Got %s instead of %s\n",lbuff,loadbuff);
		strcpy(loadbuff, lbuff);
  		ml = strlen (loadbuff);
	}
	free(lbuff);
  }

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
#ifdef DEBUG
      A4GL_debug ("Field %d = %s", a, colptr[a]);
#endif
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


// Check if the line ends in a slash - 
// but ignore any trailing \n or \r in the line..
static int endswithslash(char*s) {
int sl;
sl=strlen(s)-1;
	while (1) {
		if (s[sl]=='\n') {sl--; continue;}
		if (s[sl]=='\r') {sl--; continue;}
		break;
	}
	if (s[sl]=='\\') {
		return sl;
	}
	return 0;
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


if (strstr(tabname,"\".")) {
	char buff[200];
	char *ptr;
	strcpy(buff,tabname);
	ptr=strstr(buff,"\".");
	if (ptr) {
		ptr++;
		*ptr=0;
		ptr++;
		//printf("%s %s\n", buff,ptr);
		tabname=A4GLSQLCV_ownerize_tablename(buff,ptr);
	}
	
}

//printf("%s\n",tabname);
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


#ifdef DEBUG
  A4GL_debug ("In load_data - LOAD_ORIG");
#endif
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
#ifdef DEBUG
      A4GL_debug ("Adding %s to col_list", colname);
#endif
      strcpy (col_list[cnt], colname);
      cnt++;
    }
  va_end (ap);
  if (cnt == 0)
    {
      /* get columns from database */
#ifdef DEBUG
      A4GL_debug ("Getting columns from database");
#endif
      cnt = A4GLSQL_fill_array (MAXLOADCOLS, (char *) col_list, MAXCOLLENGTH - 1, 0, 0, "COLUMNS", 0, tabname);

    }

#ifdef DEBUG
  A4GL_debug ("Read %d columns", cnt);
#endif

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
#ifdef DEBUG
  A4GL_debug ("Calling gen_insert_for_load %s %d\n", tabname, cnt);
#endif

  for (a=0;a<cnt;a++) {
	//int idtype;
	int isize;
	col_list_types[a]=DTYPE_CHAR;
	A4GL_read_columns (tabname, col_list[a], &col_list_types[a], &isize);
  }

  insertstr = gen_insert_for_load (tabname, cnt);


#ifdef DEBUG
  A4GL_debug ("Adding prepare.. for %s", insertstr);
#endif


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

   ibind = acl_malloc2 (sizeof (struct BINDING) * cnt);

   for (a = 0; a < cnt; a++)
	{
	//int b;
	
#ifdef DEBUG
	  A4GL_debug ("Binding %s @ %d", colptr[a], a);
#endif

	 switch (col_list_types[a]&DTYPE_MASK) {
		case DTYPE_BYTE:
	  		ibind[a].ptr = &byte_vars[a];
			A4GL_locate_var(ibind[a].ptr,'M',NULL);
			byte_vars[a].memsize=0;
			byte_vars[a].ptr=0;
			byte_vars[a].isnull='Y';
	  		ibind[a].dtype = DTYPE_BYTE;
			break;
		case DTYPE_TEXT:
	  		ibind[a].ptr = &text_vars[a];
			text_vars[a].memsize=0;
			text_vars[a].ptr=0;
			text_vars[a].isnull='Y';
			A4GL_locate_var(ibind[a].ptr,'M',NULL);
	  		ibind[a].dtype = DTYPE_TEXT;
			break;
		default:
	  		ibind[a].dtype = DTYPE_CHAR;
			break;
	  }
	  ibind[a].start_char_subscript = 0;
	  ibind[a].end_char_subscript = 0;
	  ibind[a].libptr = 0;
  }


  A4GL_setnull (DTYPE_CHAR, nullbuff, 1);
  while (1)
    {
     char *readBytes;
        strcpy (loadbuff, "");
 	readBytes=fgets (loadbuff, LOADBUFFSIZE - 1, p);
	
	while (readBytes) {
	int sl;
			sl=endswithslash(loadbuff) ;
			if (sl) {loadbuff[sl]=0;} 
			else {
				break;
			}
			
      			readBytes=fgets (loadbufftmp, LOADBUFFSIZE - 1, p);
			if (readBytes) {
				strcat(loadbuff,loadbufftmp);
			}
	}

#ifdef DEBUG
      A4GL_debug ("Read line '%s'\n", loadbuff);
#endif


      if (feof (p) && strlen (loadbuff)) // If its the last line - make sure we've got a whole line with a trailing \n
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
#ifdef DEBUG
      A4GL_debug ("Read line '%s'\n", loadbuff);
#endif
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
#ifdef DEBUG
      A4GL_debug ("nfields=%d number of columns=%d", nfields, cnt);
#endif
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



      for (a = 0; a < cnt; a++)
	{
	//int b;
	
#ifdef DEBUG
	  A4GL_debug ("Binding %s @ %d", colptr[a], a);
#endif

	 switch (col_list_types[a]&DTYPE_MASK) {
		case DTYPE_BYTE:
			byte_vars[a].memsize=strlen(colptr[a])+1;
			byte_vars[a].ptr=colptr[a];
			ibind[a].dtype=DTYPE_BYTE; // Reset - just in case it was NULL and set to CHAR later on...
			if (byte_vars[a].memsize) {
				byte_vars[a].isnull='N';
			} else {
				byte_vars[a].isnull='Y';
			}
			break;

		case DTYPE_TEXT:
			ibind[a].dtype=DTYPE_TEXT; // Reset - just in case it was NULL and set to CHAR later on...
			text_vars[a].memsize=strlen(colptr[a])+1;
			text_vars[a].ptr=colptr[a];
			if (text_vars[a].memsize) {
				text_vars[a].isnull='N';
			} else {
				text_vars[a].isnull='Y';
			}
			break;

		default:
	  		ibind[a].ptr = colptr[a];
			break;
	  }

	  //ibind[a].start_char_subscript = 0;
	  //ibind[a].end_char_subscript = 0;
	  //ibind[a].libptr = 0;

	  if (strlen (colptr[a]) == 0)
	    {
	       ibind[a].size = 1;
		ibind[a].ptr=nullbuff;
		ibind[a].dtype=DTYPE_CHAR;
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
  		free(ibind);
	  doing_load = 0;
	  return 0;
	}
      if (feof (p))
	{
#ifdef DEBUG
	  A4GL_debug ("Got to end of the file");
#endif
	  break;
	}
    }
  a4gl_sqlca.sqlerrd[2] = lineno;	// sqlerrd[3] in 4gl
  fclose (p);
  if (filterfunc)
    {
      clr_colptr (1);
    }
  free(ibind);
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


#ifdef DEBUG
  A4GL_debug ("In load_data");
#endif
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
#ifdef DEBUG
      A4GL_debug ("Adding %s to col_list", colname);
#endif
      strcpy (col_list[cnt], colname);
      cnt++;
    }
  va_end (ap);
  if (cnt == 0)
    {
      /* get columns from database */
#ifdef DEBUG
      A4GL_debug ("Getting columns from database");
#endif
      cnt = A4GLSQL_fill_array (MAXLOADCOLS, (char *) col_list, MAXCOLLENGTH - 1, 0, 0, "COLUMNS", 0, tabname);

    }

#ifdef DEBUG
  A4GL_debug ("Read %d columns", cnt);
#endif

  if (cnt == 0)
    {
      A4GL_exitwith ("Error in getting number of columns for load");
      doing_load = 0;
      return 0;
    }
#ifdef DEBUG
  A4GL_debug ("Calling gen_insert_for_load %s %d\n", tabname, cnt);
#endif

  insertstr = gen_insert_for_load (tabname, cnt);


#ifdef DEBUG
  A4GL_debug ("Adding prepare.. for %s", insertstr);
#endif


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
#ifdef DEBUG
      A4GL_debug ("Declare..\n");
#endif

      A4GL_add_prepare ("a4gl_pload", (void *) A4GL_prepare_select (0, 0, 0, 0, insertstr, "__internal_load", 1, 0));

      A4GL_declare_cursor (0 + 0, A4GL_find_prepare ("a4gl_pload"), 0, "a4gl_load");

#ifdef DEBUG
      A4GL_debug ("Open..\n");
#endif

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
#ifdef DEBUG
	  A4GL_debug ("Got to end of the file");
#endif
	  break;
	}
      lineno++;
      stripnlload (loadbuff, delim);
      //printf ("Read line '%s'", loadbuff);
      nfields = find_delims (delim);
#ifdef DEBUG
      A4GL_debug ("nfields=%d number of columns=%d", nfields, cnt);
#endif
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
#ifdef DEBUG
	  A4GL_debug ("Binding %s @ %d", colptr[a], a);
#endif

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
#ifdef DEBUG
	  A4GL_debug ("Put");
#endif
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
#ifdef DEBUG
      A4GL_debug ("Close");
#endif
      A4GL_close_cursor ("a4gl_load",1);
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
char nullbuff[200];

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

  A4GL_setnull (DTYPE_CHAR, nullbuff, 1);


  if (sqlstmt)
    free (sqlstmt);
  sqlstmt = acl_strdup (sqlstmt_orig);
#ifdef DEBUG
  A4GL_debug ("In load_data");
#endif
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
#ifdef DEBUG
	  A4GL_debug ("Got to end of the file");
#endif
	  break;
	}
      stripnlload (loadbuff, delim);
#ifdef DEBUG
      A4GL_debug ("Read line '%s'", loadbuff);
#endif
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
#ifdef DEBUG
      A4GL_debug ("nfields=%d number of columns=%d", nfields, cnt);
#endif

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
#ifdef DEBUG
	  A4GL_debug ("Binding %s @ %d", colptr[a], a);
#endif
	  ibind[a].ptr = colptr[a];
	  ibind[a].dtype = DTYPE_CHAR;
	  if (strlen (colptr[a]) == 0)
	    {
	       ibind[a].size = 1;
		ibind[a].ptr=nullbuff;
		ibind[a].dtype=DTYPE_CHAR;
	} else {
	  	ibind[a].size = strlen (colptr[a]);
	}

	ibind[a].start_char_subscript=0;
	ibind[a].end_char_subscript=0;
	ibind[a].libptr=0;
	}
#ifdef DEBUG
      A4GL_debug ("EXECUTE SQL nfields=%d", nfields);
#endif
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

int aclfgl_aclfgl_unload_csv_no_headers(int n) {
char **buff;
static char buffRet[200000];
int a;
int *type;
buff=malloc(sizeof(char *)*n);
type=malloc(sizeof(int)*n);

A4GL_debug_print_stack();
strcpy(buffRet,"");

for (a=n-1;a>=0;a--) {
	int d1;
	int s1;
	void *ptr1;
	A4GL_get_top_of_stack (1, &d1, &s1, (void *) &ptr1);
	switch (d1&DTYPE_MASK) {
		case DTYPE_INT:
		case DTYPE_SMINT:
		case DTYPE_FLOAT:
		case DTYPE_SMFLOAT:
		case DTYPE_DECIMAL:
			type[a]=0;
			break;
		default:
			type[a]=1;
			break;
	}
	buff[a]=A4GL_char_pop();
}


for (a=0;a<n;a++) {
	if (a) { strcat(buffRet,","); }
	if (type[a]) { strcat(buffRet,"\""); }
	else {
		A4GL_trim(buff[a]);
	}
	strcat(buffRet,buff[a]);
	if (type[a]) { strcat(buffRet,"\""); }
	free(buff[a]);
}

strcat(buffRet,"\n");

free(buff);
free(type);
A4GL_push_char(buffRet);
return 1;
}



int aclfgl_aclfgl_unload_csv(int n) {
char **buff;
static char buffRet[200000];
int a;
int *type;
buff=malloc(sizeof(char *)*n);
type=malloc(sizeof(int)*n);

A4GL_debug_print_stack();
strcpy(buffRet,"");

for (a=n-1;a>=0;a--) {
	int d1;
	int s1;
	void *ptr1;
	A4GL_get_top_of_stack (1, &d1, &s1, (void *) &ptr1);
	switch (d1&DTYPE_MASK) {
		case DTYPE_INT:
		case DTYPE_SMINT:
		case DTYPE_FLOAT:
		case DTYPE_SMFLOAT:
		case DTYPE_DECIMAL:
			type[a]=0;
			break;
		default:
			type[a]=1;
			break;
	}
	buff[a]=A4GL_char_pop();
}


for (a=0;a<n;a++) {
	if (a) { strcat(buffRet,","); }
	if (type[a]) { strcat(buffRet,"\""); }
	else {
		A4GL_trim(buff[a]);
	}
	strcat(buffRet,buff[a]);
	if (type[a]) { strcat(buffRet,"\""); }
	free(buff[a]);
}

strcat(buffRet,"\n");

free(buff);
free(type);
A4GL_push_char(buffRet);
return 1;
}

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
  char *lbuff=NULL;

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

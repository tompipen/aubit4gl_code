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
# $Id: helper.c,v 1.80 2009-02-05 15:30:52 mikeaubury Exp $
#
*/

/**
 * @file
 *
 * @todo Add Doxygen comments to file
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#define EXTERN_CONVFMTS
#include "a4gl_libaubit4gl_int.h"
#include <ctype.h>
void A4GLPACKER_clrlibptr (void);
void A4GLFORM_clrlibptr (void);
static void tea_8c_encipher (const unsigned long *const v, unsigned long *const w, const unsigned long *const k);
static void tea_8c_decipher (const unsigned long *const v, unsigned long *const w, const unsigned long *const k);

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

void A4GL_strip_pc (char *s, char *d);
int A4GL_extract_numeral (char *s);

//LIBEXPORT int aclfgl_get_info         (int np);

LIBPRIVATE int int_get_info_form (char *ptr, char *info);



/*
=====================================================================
                    Variables definitions
=====================================================================
*/

LIBPRIVATE int used_value = 0;
LIBPRIVATE char last_field[256];

LIBPRIVATE char *a_get_info_types[] = {
  "Window",
  "Form",
  "Connection",
  "Statement",
  "Cursor",
  0
};

LIBPRIVATE char *a_get_info_window[] = {
  "Height",
  "Width",
  "BeginX",
  "BeginY",
  "Border",
  "Metrics",
  "CommentLine",
  "MenuLine",
  "PromptLine",
  "FormLine",
  "MessageLine",
  "Color",
  0
};

LIBPRIVATE char *a_get_info_statement[] = {
  "NoColumns",
  "NoRows",
  "Name%",
  "Type%",
  "Scale%",
  "Nullable%",
  "Length%",
  0
};

LIBPRIVATE char *a_get_info_form[] = {
  "Database",			// 0
  "Delimiters",
  "ScreenRecordCount",
  "ScreenRecordName%",
  "FieldCount",
  "FieldName%",			//5 
  "AttributesCount",
  "CurrentField",
  "Width",
  "Height",
  "Field%",			// 10
  "ScreenName%",
  "TableName%",
  "AliasName%",
  "FieldType%",
  "FieldSize%",			//15
  "FieldBytes%",
  "FieldDets%",
  "Screens",
  0
};


LIBPRIVATE char *a_get_info_connection[] = {
  "Database",
  "ActiveConnections",
  "ActiveStatements",
  "DataSourceName",
  "DriverHenv",
  "DriverHstmt",
  "DriverName",
  "DriverVer",
  "FetchDirection",
  "ODBCAPIConform",
  "ODBCSAGConform",
  "ODBCSQLConform",
  "ODBCOPTIEF",
  "ODBCVer",
  "Procedures",
  "RowUpdates",
  "SearchPatternEscape",
  "ServerName",
  "DatabaseName",
  "DBMSName",
  "DBMSVer",
  "AccessibleTables",
  "AccessibleProcedures",
  "ConcatNull",
  "CursorCommit",
  "CursorRollback",
  "ReadOnly",
  "DefaultIsolation",
  "ExpressionsInOrderBy",
  "IdentifierCase",
  "IndentifierQuoteChar",
  "MaxColumnNameLen",
  "MaxCursorNameLen",
  "MaxOwnerNameLen",

  0
};


struct s_windows
{
  int x, y, w, h;
  void *pan;
  void *win;
  char name[20];
  struct s_form_dets *form;
  struct s_form_attr winattr;
};


//int A4GL_setenv(char *name, char *value, int overwrite);

//static long *ptr;

/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/**
 *
 * @param str
 * @param arr
 * @return
 */
LIBPRIVATE int
str_inarray (char *str, char **arr)
{
  int a;
  char buff[128];
  char data[128];
  int digit;

  strcpy (data, str);
  digit = A4GL_extract_numeral (data);
  used_value = digit;
#ifdef DEBUG
  /* {DEBUG} */
  {
    A4GL_debug ("Digit = %d", digit);
  }
#endif

  for (a = 0; arr[a]; a++)
    {
      if (a_strchr (arr[a], '%'))
	{
	  A4GL_strip_pc (arr[a], buff);
#ifdef DEBUG
	  /* {DEBUG} */
	  {
	    A4GL_debug ("Removed %% from string.. %s", buff);
	  }
#endif
	}
      else
	{
	  strcpy (buff, arr[a]);
	}

#ifdef DEBUG
      /* {DEBUG} */
      {
	A4GL_debug ("Checking %s %s\n", data, buff);
      }
#endif
      if (STRIEQ (data, buff))
	return a + 1;
    }
  return 0;
}


/**
 * Finds an opened form and.
 *
 * @param ptr The name of the form
 * @param info
 * @return 
 */
LIBPRIVATE int
int_get_info_form (char *ptr, char *info)
{
  struct s_form_dets *p;
  int params;
  int a;
  char buff[132];

#ifdef DEBUG
  /* {DEBUG} */
  {
    A4GL_debug ("In get_info_form %s %s", ptr, info);
  }
#endif
  p = (struct s_form_dets *) A4GL_find_pointer (ptr, S_FORMDETSCODE);
#ifdef DEBUG
  /* {DEBUG} */
  {
    A4GL_debug ("P=%p", p);
  }
#endif
  if (p == 0)
    {
#ifdef DEBUG
      /* {DEBUG} */
      {
	A4GL_debug ("Form was not found... %s", ptr);
      }
#endif
      A4GL_exitwith ("Form was not found");
      return 0;
    }
  params = 1;
  a = str_inarray (info, a_get_info_form);
#ifdef DEBUG
  /* {DEBUG} */
  {
    A4GL_debug ("a=%d\n", a);
  }
#endif

  switch (a)
    {
    case 1:			// DBNAME
      A4GL_push_char (p->fileform->dbname);
      break;
    case 2:			// DELIMITERS
      A4GL_push_char (p->fileform->delim);
      break;

    case 3:			// SCREENRECORDCOUNT
      A4GL_push_int (p->fileform->records.records_len);
      break;

    case 4:			// SCREENRECORDNAME
    case 12:
      if (used_value < p->fileform->snames.snames_len)
	A4GL_push_char (p->fileform->snames.snames_val[used_value].name);
      else
	A4GL_push_char ("");

      break;


    case 5:			// FIELDCOUNT
      A4GL_push_int (p->fileform->fields.fields_len);
      break;

    case 6:			// FIELDNAME
      if (used_value < p->fileform->attributes.attributes_len)
	{
	  SPRINTF2 (buff, "%s.%s",
		    p->fileform->attributes.attributes_val[used_value].tabname,
		    p->fileform->attributes.attributes_val[used_value].colname);
	  A4GL_push_char (buff);
	}
      else
	{
	  A4GL_push_char ("");
	}
      break;

    case 15:			// FIELDTYPE
      if (used_value < p->fileform->attributes.attributes_len)
	{
	  A4GL_push_int (p->fileform->attributes.attributes_val[used_value].datatype);
	}
      else
	{
	  A4GL_push_int (0);
	}
      break;

    case 16:			// FIELDTYPE
      if (used_value < p->fileform->attributes.attributes_len)
	{
	  A4GL_push_int (p->fileform->attributes.attributes_val[used_value].dtype_size);
	}
      else
	{
	  A4GL_push_int (0);
	}
      break;

    case 17:			// FIELDTYPE
      if (used_value < p->fileform->attributes.attributes_len)
	{
	  A4GL_push_int (2048);
	}
      else
	{
	  A4GL_push_int (0);
	}
      break;


    case 18:			// FIELDDETS
      if (used_value < p->fileform->attributes.attributes_len)
	{
	  A4GL_push_long ((long) &p->fileform->attributes.attributes_val[used_value]);
	}
      else
	{
	  A4GL_push_int (0);
	}
      break;


    case 19:			// Screens
      A4GL_push_long (p->fileform->snames.snames_len);
      break;

    case 7:			// ATTRIBUTECOUNT
      A4GL_push_int (p->fileform->attributes.attributes_len);
      break;
    /** @todo Understand if the push of a pointer as if it was 
	   *  pointer is correct and if not correct it
		 *  I think that this is not called.
	   */

    case 8:			// CUREENTFIELD
      //A4GL_push_int ((int) p->currentfield);
      A4GL_push_long ((long) p->currentfield);
      break;

    case 9:			// WIDTH
      A4GL_push_int (p->fileform->maxcol);
      break;

    case 10:			// HEIGHT
      A4GL_push_int (p->fileform->maxline);
      break;

    case 11:			// Field
      A4GL_push_long (p->fileform->metrics.metrics_val[p->fileform->fields.fields_val[used_value].metric.metric_val[0]].field);
      break;

    case 13:			// Table name
      if (used_value < p->fileform->tables.tables_len)
	if (p->fileform->tables.tables_val[used_value].tabname)
	  {
	    A4GL_push_char (p->fileform->tables.tables_val[used_value].tabname);
	  }
	else
	  {
	    A4GL_push_char (" ");
	  }
      else
	A4GL_push_char ("");
      break;

    case 14:			// Alias name
      if (used_value < p->fileform->tables.tables_len)
	if (p->fileform->tables.tables_val[used_value].alias)
	  {
	    A4GL_push_char (p->fileform->tables.tables_val[used_value].alias);
	  }
	else
	  {
	    A4GL_push_char (" ");
	  }
      else
	A4GL_push_char ("");


      break;



    case 0:
      A4GL_exitwith ("Invalid Form info request");
      return 0;
    }
  return params;
}


/**
 *
 * @param
 * @return
 */
LIBPRIVATE int
int_get_info_connection (char *ptr, char *info)
{
  int params;
  int a;

#ifdef DEBUG
  /* {DEBUG} */
  {
    A4GL_debug ("In get_info_connection %s %s", ptr, info);
  }
#endif

  params = 1;
  a = str_inarray (info, a_get_info_connection);
#ifdef DEBUG
  /* {DEBUG} */
  {
    A4GL_debug ("a=%d\n", a);
  }
#endif
  switch (a)
    {
    case 1:
      A4GL_push_char (A4GLSQL_get_currdbname ());
      return 1;
      break;
    case 0:
      A4GL_exitwith ("Invalid Connection info request");
      return 0;
    }

  return 0;

}

/**
 *
 * @param
 * @return
 */
LIBPRIVATE int
int_get_info_statement (char *ptr, char *info)
{
  int params;
  int a;
  char *p;

  params = 1;
  a = str_inarray (info, a_get_info_statement);
#ifdef DEBUG
  /* {DEBUG} */
  {
    A4GL_debug ("info statement a=%d\n", a);
  }
#endif
  switch (a)
    {
    case 1:
      A4GL_push_int (A4GLSQL_describe_stmt (ptr, 0, 5));
      break;
    case 2:
      A4GL_push_int (A4GLSQL_describe_stmt (ptr, 0, 6));
      break;
    case 3:
      {
#ifdef DEBUG
	/* {DEBUG} */
	{
	  A4GL_debug ("Column name for column %d", used_value);
	}
#endif
	p = (char *) A4GLSQL_describe_stmt (ptr, used_value, 1);
#ifdef DEBUG
	/* {DEBUG} */
	{
	  A4GL_debug ("Got p as %p", p);
	}
#endif
#ifdef DEBUG
	/* {DEBUG} */
	{
	  A4GL_debug ("Pushing onto stack");
	}
#endif
	if (p != 0)
	  A4GL_push_char (p);
	else
	  A4GL_push_char ("");
#ifdef DEBUG
	/* {DEBUG} */
	{
	  A4GL_debug ("Pushed onto stack");
	}
#endif
	break;
      }
    case 4:
      A4GL_push_int (A4GLSQL_describe_stmt (ptr, used_value, 0));
      break;
    case 5:
      A4GL_push_int (A4GLSQL_describe_stmt (ptr, used_value, 2));
      break;
    case 6:
      A4GL_push_int (A4GLSQL_describe_stmt (ptr, used_value, 4));
      break;
    case 7:
      A4GL_push_int (A4GLSQL_describe_stmt (ptr, used_value, 3));
      break;
    case 0:
      A4GL_exitwith ("Invalid statement info request");
      return 0;
    }
  return params;
}

/**
 *
 * @param
 * @return
 */
LIBPRIVATE int
int_get_info_cursor (void)
{
  return 0;
}

/**
 *
 * @param
 * @return
 */
LIBPRIVATE int
int_get_info_window (char *ptr, char *info)
{
  struct s_windows *p;
  int params;
  int a;

#ifdef DEBUG
  {
    A4GL_debug ("In get_info_window %s %s", ptr, info);
  }
#endif
  p = (struct s_windows *) A4GL_find_pointer (ptr, S_WINDOWSCODE);
#ifdef DEBUG
  {
    A4GL_debug ("P=%p", p);
  }
#endif
  if (p == 0)
    {
#ifdef DEBUG
      {
	A4GL_debug ("Window was not found... %s", ptr);
      }
#endif
      A4GL_exitwith ("Window was not found");
      return 0;
    }
  params = 1;
  a = str_inarray (info, a_get_info_window);
#ifdef DEBUG
  {
    A4GL_debug ("a=%d\n", a);
  }
#endif
  switch (a)
    {
    case 1:
      if (strcmp (ptr, "screen") == 0)
	{
	  A4GL_push_int (p->h + 1);
	}
      else
	{
	  A4GL_push_int (p->h);
	}
      break;
    case 2:
      if (strcmp (ptr, "screen") == 0)
	{
	  A4GL_push_int (p->w + 1);
	}
      else
	{
	  A4GL_push_int (p->w);
	}
      break;
    case 3:
      A4GL_push_int (p->x);
      break;
    case 4:
      A4GL_push_int (p->y);
      break;
    case 5:
      A4GL_push_int (p->winattr.border);
      break;
    case 6:
      A4GL_push_int (p->x);
      A4GL_push_int (p->y);
      A4GL_push_int (p->w);
      A4GL_push_int (p->h);
      params = 4;
      break;
    case 0:
      A4GL_exitwith ("Invalid Window info request");
      return 0;
    }
  A4GL_debug ("params=%d", params);
  return params;

}

/**
 *
 * @param
 * @return
 */
LIBPRIVATE int
int_get_info (char *type, char *ptr, char *info)
{
  int a;
#ifdef DEBUG
  /* {DEBUG} */
  {
    A4GL_debug ("Looking for type %s", type);
  }
#endif
  A4GL_trim (type);
  A4GL_trim (ptr);
  A4GL_trim (info);
  a = str_inarray (type, a_get_info_types);
#ifdef DEBUG
  /* {DEBUG} */
  {
    A4GL_debug ("Returns %d", a);
  }
#endif
  switch (a)
    {
    case 0:
      A4GL_exitwith ("Invalid type called in get_info");
      return 0;
    case 1:
      return int_get_info_window (ptr, info);
    case 2:
      return int_get_info_form (ptr, info);
    case 3:
      return int_get_info_connection (ptr, info);
    case 4:
      return int_get_info_statement (ptr, info);
    case 5:
      return int_get_info_cursor ();
    }

  return 0;
}

/**
 * @todo Understand why this functions is not called and if not 
 * remove it and all the tree of functions not used
 */
LIBEXPORT int
aclfgl_a4gl_get_info (int np)
{
  char *d, *p, *i;
  int a;
  if (np != 3)
    {
      A4GL_exitwith ("Wrong number of arguments");
      return 0;
    }
  d = A4GL_char_pop ();
  p = A4GL_char_pop ();
  i = A4GL_char_pop ();
  A4GL_trim (d);
  A4GL_trim (p);
  A4GL_trim (i);
#ifdef DEBUG
  /* {DEBUG} */
  {
    A4GL_debug ("Get info called with %s %s %s", d, p, i);
  }
#endif
  a = int_get_info (i, p, d);
  acl_free (d);
  acl_free (p);
  acl_free (i);
  return a;
}


/**
 * not used
 * @param
 * @return
 */
/*
LIBPRIVATE void
set_val(char *str,char *buff)
{
int a;
	strcpy(buff,str);
	for (a=0;a<=strlen(str);a++) {
	if (buff[a]=='%') buff[a]=0;
	}
}
*/

/**
 *
 * @param
 * @return
 */
int
A4GL_extract_numeral (char *s)
{
  char *p = 0;
  int a;

#ifdef DEBUG
  /* {DEBUG} */
  {
    A4GL_debug ("Extracting numerals from %s", s);
  }
#endif

  for (a = strlen (s) - 1; a >= 0; a--)
    {
      if (s[a] >= '0' && s[a] <= '9')
	{
#ifdef DEBUG
	  /* {DEBUG} */
	  {
	    A4GL_debug ("digit at %d", a);
	  }
#endif
	  continue;
	}
#ifdef DEBUG
      /* {DEBUG} */
      {
	A4GL_debug ("Last non-numeric=%d", a);
      }
#endif
      p = &s[a + 1];
#ifdef DEBUG
      /* {DEBUG} */
      {
	A4GL_debug ("Numeric=%s", p);
      }
#endif
      break;
    }

  if (p)
    {
      a = atoi (p);
#ifdef DEBUG
      /* {DEBUG} */
      {
	A4GL_debug ("Setting number to %d", a);
      }
#endif
      *p = 0;
#ifdef DEBUG
      /* {DEBUG} */
      {
	A4GL_debug ("Setting string to %s", s);
      }
#endif
    }
  else
    {
#ifdef DEBUG
      /* {DEBUG} */
      {
	A4GL_debug ("No numbers found");
      }
#endif
      a = 0;
    }
  return a;
}


/**
 *
 * @param
 * @return
 */
void
A4GL_strip_pc (char *s, char *d)
{
  int a;
  strcpy (d, s);
  for (a = 0; a < strlen (d); a++)
    {
      if (d[a] == '%')
	{
	  d[a] = 0;
	  break;
	}
    }
}


/*
**  usr_funcs.c - 'C' functions required by programs generated by db4glgen
**  Copyright (C) 1989-1995  David A. Snyder
**
**  This library is free software; you can redistribute it and/or
**  modify it under the terms of the GNU Library General Public
**  License as published by the Free Software Foundation; version
**  2 of the License.
**
**  This library is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
**  Library General Public License for more details.
**
**  You should have received a copy of the GNU Library General Public
**  License along with this library; if not, write to the Free
**  Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/
#ifdef INCLUDE_USR_FUNCS

/* Some bits stripped out */

/**
 *
 * @param
 * @return
 */
int
aclfgl_i_rowid_s (int arg)
{
  if ((ptr = (long *) acl_malloc2 (sizeof (long))) != NULL)
    A4GL_push_int (0);
  else
    A4GL_push_int (1);
  return (1);

}


/**
 *
 * @param
 * @return
 */
int
aclfgl_m_rowid_s (int arg)
{
  int i, q_cur, q_cnt;

  q_cnt = A4GL_pop_int ();
  q_cur = A4GL_pop_int ();

  for (i = q_cur; i < q_cnt; i++)
    ptr[i] = ptr[i + 1];

  return (0);
}


/**
 *
 * @param
 * @return
 */
int
aclfgl_r_rowid_s (int arg)
{
  int pos;

  pos = A4GL_pop_int ();
  A4GL_push_int (ptr[pos]);
  return (1);
}


/**
 *
 * @param
 * @return
 */
int
aclfgl_s_rowid_s (int arg)
{
  int size;

  size = A4GL_pop_int ();
  if ((ptr = (long *) realloc ((char *) ptr, (unsigned) (size + 1) * sizeof (long))) != NULL)
    A4GL_push_int (0);
  else
    A4GL_push_int (1);
  return (1);
}


/**
 *
 * @param
 * @return
 */
int
aclfgl_w_rowid_s (int arg)
{
  int pos, value;

  value = A4GL_pop_int ();
  pos = A4GL_pop_int ();
  ptr[pos] = value;
  return (0);
}
#endif //----------------------------------- ifdef INCLUDE_USR_FUNCS

/**
 *
 * @param
 * @return
 */
int
aclfgl_fgl_prtscr (int n)
{
  return aclfgl_aclfgl_dump_screen (n);
}


/**
 *
 * @param
 * @return
 */
void
A4GL_set_last_field_name (char *s)
{
  strcpy (last_field, s);
}


/**
 *
 * @param
 * @return
 */
char *
A4GL_get_last_field_name (char *s)
{
  return last_field;
}

/**
 *
 * @param
 * @return
 */
void
A4GL_add_compiled_form (char *s, char *formtype, char *packer, char *frm)
{
  A4GL_debug ("Adding compiled form name='%s' ptr=%p\n", s, frm);
  if (!(A4GL_has_pointer (s, COMPILED_FORM)))
    {
      A4GL_add_pointer (s, COMPILED_FORM, frm);
      A4GL_add_pointer (s, COMPILED_FORM_PACKER, strdup (packer));
      A4GL_add_pointer (s, COMPILED_FORM_FORMTYPE, strdup (formtype));
    }
}


/**
 *
 * @param
 * @return
 */
void *
A4GL_read_form (char *s, char *p)
{
  char old_packer[256] = "";
  char old_formtype[256] = "";
  char buff[256];
  void *ptr;
  char formpath[256];
  int found = 0;
  FILE *f;

#ifdef DEBUG
  A4GL_debug ("read_form %s %s", s, p);
#endif
  if (A4GL_has_pointer (s, COMPILED_FORM))
    {
      char *formtype;
      char *packer;
      A4GL_debug ("COMPILED_FORM!");
      strcpy (old_packer, acl_getenv ("A4GL_PACKER"));
      strcpy (old_formtype, acl_getenv ("A4GL_FORMTYPE"));
      A4GL_debug ("Saved old packer=%s formtype=%s", old_packer, old_formtype);
      A4GLFORM_clrlibptr ();
      A4GLPACKER_clrlibptr ();
      formtype = A4GL_find_pointer_val (s, COMPILED_FORM_FORMTYPE);
      packer = A4GL_find_pointer_val (s, COMPILED_FORM_PACKER);
      A4GL_setenv ("A4GL_FORMTYPE", formtype, 1);
      A4GL_setenv ("A4GL_PACKER", packer, 1);
    }
  strcpy (buff, s);



  strcpy (formpath, acl_getenv ("A4GL_FRM_BASE_LIST"));

  if (strlen (formpath))
    {
      char *ptr1;
      char *ptr2;
      char buff_path[256];
      char buff_file[512];

      strcpy (buff_path, formpath);
      ptr1 = strchr (buff_path, ':');
      ptr2 = &buff_path[0];

      while (ptr1)
	{
	  *ptr1 = 0;
	  strcpy (buff_file, buff);
	  strcat (buff_file, ptr2);
	  f = A4GL_open_file_dbpath (buff_file);
	  if (f)
	    {
	      found = 1;
	      strcpy (buff, buff_file);
	      break;
	    }

	  ptr2 = ptr1 + 1;
	  ptr1 = strchr (ptr2, ':');
	}
      if (!found)
	{
	  strcpy (buff_file, buff);
	  strcat (buff_file, ptr2);
	  f = A4GL_open_file_dbpath (buff_file);
	  if (f)
	    {
	      strcpy (buff, buff_file);
	    }
	  else
	    {
	      strcat (buff, acl_getenv ("A4GL_FRM_BASE_EXT"));
	    }
	}
    }
  else
    {
      strcat (buff, acl_getenv ("A4GL_FRM_BASE_EXT"));
    }
  ptr = A4GL_read_form_internal (buff, p);




  if (A4GL_has_pointer (s, COMPILED_FORM))
    {
      A4GL_debug ("Restoring old packer & formtype");
      A4GL_setenv ("A4GL_PACKER", old_packer, 1);
      A4GL_setenv ("A4GL_FORMTYPE", old_formtype, 1);
      A4GLFORM_clrlibptr ();
      A4GLPACKER_clrlibptr ();
    }
  return ptr;
}

/**
 *
 * @param
 * @return
 */
int
A4GL_setenv (char *name, char *value, int overwrite)
{
  int ret;
  char prefixed_name[256];
/* DO NOT USE A4GL_DEBUG IN THIS FUNCTION !!! */
  SPRINTF1 (prefixed_name, "A4GL_%s", name);
  /* Clear the current cache if there is one.. */


  if (A4GL_has_pointer (name, STR_RESOURCE_VAL))
    {
      A4GL_del_pointer (name, STR_RESOURCE_VAL);
    }

/* DO NOT USE A4GL_DEBUG IN THIS FUNCTION !!! */
  if (A4GL_has_pointer (prefixed_name, STR_RESOURCE_VAL))
    {
      A4GL_del_pointer (prefixed_name, STR_RESOURCE_VAL);
    }

/* DO NOT USE A4GL_DEBUG IN THIS FUNCTION !!! */
#if HAVE_SETENV
  ret = setenv (name, value, overwrite);
#else
#if HAVE_PUTENV
  {
    char buff[1024];
    SPRINTF2 (buff, "%s=%s", name, value);
    ret = putenv (acl_strdup (buff));
  }
#else
  return 1;
#endif
#endif

/* DO NOT USE A4GL_DEBUG IN THIS FUNCTION !!! */
  A4GL_log_changed_envvar (name, value);
  return ret;
}





// Send some text to the UI
int
aclfgl_aclfgl_send_to_ui (int n)
{
  char *s;
  s = A4GL_char_pop ();
  A4GL_direct_to_ui ("SEND", s);
  return 0;
}

int
aclfgl_aclfgl_client_set (int n)
{
  A4GL_direct_to_ui ("SET", "");
  return 0;
}

int
aclfgl_aclfgl_client_execute (int n)
{
  char *s;
  s = A4GL_char_pop ();
  A4GL_direct_to_ui ("EXECUTE", s);
  return 0;
}


int
aclfgl_aclfgl_sendfile_to_ui (int n)
{
  char *s;
  if (n == 1)
    {
      s = A4GL_char_pop ();
      A4GL_direct_to_ui ("FILE", s);
    }
  else
    {
      A4GL_direct_to_ui ("NAMEDFILE", "");
    }
  return 1;
}

int
aclfgl_aclfgl_getclientfile (int n)
{
  //char *s;
  A4GL_direct_to_ui ("GETFILE", "");
  return 1;
}



int
aclfgl_aclfgl_flushinp (int n)
{
  //char *s;
  A4GL_direct_to_ui ("FLUSHINP", "");
  return 0;
}

int
aclfgl_aclfgl_embed_barcode (int _nargs)
{
  //static char *_functionName = "embed_barcode";
  double x;
  double y;
  double w;
  double h;
  char *s;

  s = A4GL_char_pop ();
  h = A4GL_pop_double ();
  w = A4GL_pop_double ();
  y = A4GL_pop_double ();
  x = A4GL_pop_double ();

  A4GL_push_char ("##BARCODE(");
  A4GL_push_double (x);
  A4GL_push_char ("<<<&.&&");
  A4GL_pushop (OP_USING);
  A4GL_pushop (OP_CONCAT);
  A4GL_push_char (",");
  A4GL_pushop (OP_CONCAT);
  A4GL_push_double (y);
  A4GL_push_char ("<<<&.&&");
  A4GL_pushop (OP_USING);
  A4GL_pushop (OP_CONCAT);
  A4GL_push_char (",");
  A4GL_pushop (OP_CONCAT);
  A4GL_push_double (w);
  A4GL_push_char ("<<<&.&&");
  A4GL_pushop (OP_USING);
  A4GL_pushop (OP_CONCAT);
  A4GL_push_char (",");
  A4GL_pushop (OP_CONCAT);
  A4GL_push_double (h);
  A4GL_push_char ("<<<&.&&");
  A4GL_pushop (OP_USING);
  A4GL_pushop (OP_CONCAT);
  A4GL_push_char (",");
  A4GL_pushop (OP_CONCAT);
  A4GL_push_char (s);
  acl_free (s);
  A4GL_pushop (OP_CONCAT);
  A4GL_push_char (")##");
  A4GL_pushop (OP_CONCAT);
  return 1;
}


int
aclfgl_aclfgl_setenv (int n)
{
  char *a;
  char *b;
  b = A4GL_char_pop ();
  a = A4GL_char_pop ();
  A4GL_trim (a);
/* A4GL_trim(b); */
  A4GL_setenv (a, b, 1);
  return 0;
}


int
a4gl_toupper (int n)
{
  int nnew = n;
  if (n >= 0 && n <= 255)
    nnew = toupper (n);
  A4GL_debug ("toupper : %d %d (%c %c)", n, nnew, n, nnew);
  return nnew;
}

int
a4gl_tolower (int n)
{
  if (n >= 0 && n <= 255)
    n = tolower (n);
  return n;
}

int
a4gl_isalpha (int n)
{
  if (n >= 0 && n <= 255)
    return isalpha (n);
  else
    return 0;
}

int
a4gl_islower (int n)
{
  if (n >= 0 && n <= 255)
    return islower (n);
  else
    return 0;
}

int
a4gl_isupper (int n)
{
  if (n >= 0 && n <= 255)
    return isupper (n);
  else
    return 0;
}

static char
hex_digit (int n)
{
  if (n >= 0 && n <= 9)
    return n + '0';
  if (n == 10)
    return 'a';
  if (n == 11)
    return 'b';
  if (n == 12)
    return 'c';
  if (n == 13)
    return 'd';
  if (n == 14)
    return 'e';
  if (n == 15)
    return 'f';
  return 'x';
}


char *
A4GL_tea_string_encipher (char *s)
{
  char buff[1000];
  static char buff_out[1000];
  char smbuff[20];
  int a;
  long key[4];
  char rbuff[10];
  long *x;
  //long b[10];
  memset (rbuff, 0, sizeof (rbuff));

  memset (&key[0], 0, sizeof (key));
  key[0] = 0x12447469;
  key[1] = 0x87873739;
  key[2] = 0x908acd69;
  key[3] = 0xfc892782;

  memset (buff, 0, 1000);
  strcpy (buff, s);
  strcpy (buff_out, "");

  for (a = 0; a < strlen (buff); a += 8)
    {
      x = (long *) rbuff;
      tea_8c_encipher (( long *) &buff[a], x, key);
      smbuff[8] = 0;
      smbuff[7] = hex_digit (x[0] & 0xf);
      x[0] = x[0] >> 4;		// 0x???????X
      smbuff[6] = hex_digit (x[0] & 0xf);
      x[0] = x[0] >> 4;		// 0x??????X
      smbuff[5] = hex_digit (x[0] & 0xf);
      x[0] = x[0] >> 4;		// 0x?????X
      smbuff[4] = hex_digit (x[0] & 0xf);
      x[0] = x[0] >> 4;		// 0x????X
      smbuff[3] = hex_digit (x[0] & 0xf);
      x[0] = x[0] >> 4;		// 0x???X
      smbuff[2] = hex_digit (x[0] & 0xf);
      x[0] = x[0] >> 4;		// 0x??X.
      smbuff[1] = hex_digit (x[0] & 0xf);
      x[0] = x[0] >> 4;		// 0x?X..
      smbuff[0] = hex_digit (x[0] & 0xf);
      x[0] = x[0] >> 4;		// 0xX...
      strcat (buff_out, smbuff);

      smbuff[8] = 0;
      smbuff[7] = hex_digit (x[1] & 0xf);
      x[1] = x[1] >> 4;		// 0x???????X
      smbuff[6] = hex_digit (x[1] & 0xf);
      x[1] = x[1] >> 4;		// 0x??????X
      smbuff[5] = hex_digit (x[1] & 0xf);
      x[1] = x[1] >> 4;		// 0x?????X
      smbuff[4] = hex_digit (x[1] & 0xf);
      x[1] = x[1] >> 4;		// 0x????X
      smbuff[3] = hex_digit (x[1] & 0xf);
      x[1] = x[1] >> 4;		// 0x???X
      smbuff[2] = hex_digit (x[1] & 0xf);
      x[1] = x[1] >> 4;		// 0x??X.
      smbuff[1] = hex_digit (x[1] & 0xf);
      x[1] = x[1] >> 4;		// 0x?X..
      smbuff[0] = hex_digit (x[1] & 0xf);
      x[1] = x[1] >> 4;		// 0xX...
      strcat (buff_out, smbuff);

    }
  return buff_out;
}


static int
hexToInt (int h)
{
  if (h >= '0' && h <= '9')
    {
      return h - '0';
    }
  else if (h >= 'a' && h <= 'f')
    {
      return h - 'a' + 10;
    }
  else if (h >= 'A' && h <= 'F')
    {
      return h - 'A' + 10;
    }
  else
    {
      return 0;
    }
}


char *
A4GL_tea_string_decipher (char *s)
{
  char buff[1000];
  static char buff_out[1000];
  char smbuff[5];
  int a;
  long key[4];
  char rbuff[9];
  int l;
  long lgptr[2];

  memset (&key[0], 0, sizeof (key));
  key[0] = 0x12447469;
  key[1] = 0x87873739;
  key[2] = 0x908acd69;
  key[3] = 0xfc892782;
  memset (buff, 0, 1000);
  strcpy (buff, s);
  strcpy (buff_out, "");

  for (a = 0; a < strlen (buff); a += 16)
    {
      l = hexToInt (buff[a]);
      l = (l * 16) + hexToInt (buff[a + 1]);
      l = (l * 16) + hexToInt (buff[a + 2]);
      l = (l * 16) + hexToInt (buff[a + 3]);
      l = (l * 16) + hexToInt (buff[a + 4]);
      l = (l * 16) + hexToInt (buff[a + 5]);
      l = (l * 16) + hexToInt (buff[a + 6]);
      l = (l * 16) + hexToInt (buff[a + 7]);
      lgptr[0] = l;

      l = hexToInt (buff[a + 8]);
      l = (l * 16) + hexToInt (buff[a + 9]);
      l = (l * 16) + hexToInt (buff[a + 10]);
      l = (l * 16) + hexToInt (buff[a + 11]);
      l = (l * 16) + hexToInt (buff[a + 12]);
      l = (l * 16) + hexToInt (buff[a + 13]);
      l = (l * 16) + hexToInt (buff[a + 14]);
      l = (l * 16) + hexToInt (buff[a + 15]);
      lgptr[1] = l;

      tea_8c_decipher (&lgptr[0], (long *) &rbuff[0], &key[0]);
      smbuff[0] = rbuff[0];
      smbuff[1] = rbuff[1];
      smbuff[2] = rbuff[2];
      smbuff[3] = rbuff[3];
      smbuff[4] = rbuff[4];
      smbuff[5] = rbuff[5];
      smbuff[6] = rbuff[6];
      smbuff[7] = rbuff[7];
      smbuff[8] = 0;
      strcat (buff_out, smbuff);
    }
  return buff_out;
}

void
tea_8c_encipher (const unsigned long *v, unsigned long *w, const unsigned long *k)
{
  unsigned long y;
  unsigned long z;
  unsigned long sum;
  unsigned long delta;
  unsigned long n;
  //unsigned long l;
  y = v[0];
  z = v[1];
  sum = 0;
  delta = 0x9E3779B9;
  n = 32;

  while ((n--) > 0)
    {
      y += ((z << 4) ^ (z >> 5)) + (z ^ sum) + k[sum & 3];
      sum += delta;
      z += ((y << 4) ^ (y >> 5)) + (y ^ sum) + k[(sum >> 11) & 3];
    }

  w[0] = y;
  w[1] = z;
}



void
tea_8c_decipher (const unsigned long *const v, unsigned long *const w, const unsigned long *const k)
{
  register unsigned long y = v[0], z = v[1], sum = 0xC6EF3720, delta = 0x9E3779B9, n = 32;

  /* sum = delta<<5, in general sum = delta * n */

  while (n-- > 0)
    {
      z -= (y << 4 ^ y >> 5) + (y ^ sum) + k[sum >> 11 & 3];
      sum -= delta;
      y -= (z << 4 ^ z >> 5) + (z ^ sum) + k[sum & 3];
    }

  w[0] = y;
  w[1] = z;
}






// Base64 encoding/decoding - lifted pretty much verbatim from CURL (license says this is fine...)

static void
decodeQuantum (unsigned char *dest, const char *src)
{
  unsigned int x = 0;
  int i;
  for (i = 0; i < 4; i++)
    {
      if (src[i] >= 'A' && src[i] <= 'Z')
	x = (x << 6) + (unsigned int) (src[i] - 'A' + 0);
      else if (src[i] >= 'a' && src[i] <= 'z')
	x = (x << 6) + (unsigned int) (src[i] - 'a' + 26);
      else if (src[i] >= '0' && src[i] <= '9')
	x = (x << 6) + (unsigned int) (src[i] - '0' + 52);
      else if (src[i] == '+')
	x = (x << 6) + 62;
      else if (src[i] == '/')
	x = (x << 6) + 63;
      else if (src[i] == '=')
	x = (x << 6);
    }

  dest[2] = (unsigned char) (x & 255);
  x >>= 8;
  dest[1] = (unsigned char) (x & 255);
  x >>= 8;
  dest[0] = (unsigned char) (x & 255);
}


/*
 *  * A4GL/Curl_base64_decode() (renamed to avoid any potential clashes...)
 *   *
 *    * Given a base64 string at src, decode it and return an allocated memory in
 *     * the *outptr. Returns the length of the decoded data.
 *      */


size_t
A4GL_base64_decode (const char *src, unsigned char **outptr)
{
  int length = 0;
  int equalsTerm = 0;
  int i;
  int numQuantums;
  unsigned char lastQuantum[3];
  size_t rawlen = 0;
  unsigned char *newstr;

  *outptr = NULL;

  while ((src[length] != '=') && src[length])
    length++;
  /* A maximum of two = padding characters is allowed */
  if (src[length] == '=')
    {
      equalsTerm++;
      if (src[length + equalsTerm] == '=')
	equalsTerm++;
    }
  numQuantums = (length + equalsTerm) / 4;

  /* Don't allocate a buffer if the decoded length is 0 */
  if (numQuantums <= 0)
    return 0;

  rawlen = (numQuantums * 3) - equalsTerm;

  /* The buffer must be large enough to make room for the last quantum
   *   (which may be partially thrown out) and the zero terminator. */
  newstr = malloc (rawlen + 4);
  if (!newstr)
    return 0;

  *outptr = newstr;

  /* Decode all but the last quantum (which may not decode to a
   *   multiple of 3 bytes) */
  for (i = 0; i < numQuantums - 1; i++)
    {
      decodeQuantum ((unsigned char *) newstr, src);
      newstr += 3;
      src += 4;
    }

  /* This final decode may actually read slightly past the end of the buffer
   *   if the input string is missing pad bytes.  This will almost always be
   *     harmless. */
  decodeQuantum (lastQuantum, src);
  for (i = 0; i < 3 - equalsTerm; i++)
    newstr[i] = lastQuantum[i];

  newstr[i] = 0;		/* zero terminate */
  return rawlen;
}

/* ---- Base64 Encoding --- */
static const char table64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";



/*
 *  * A4GL/Curl_base64_encode()
 *   *
 *    * Returns the length of the newly created base64 string. The third argument
 *     * is a pointer to an allocated area holding the base64 data. If something
 *      * went wrong, -1 is returned.
 *       *
 *        */
size_t
A4GL_base64_encode (const char *inp, size_t insize, char **outptr)
{
  unsigned char ibuf[3];
  unsigned char obuf[4];
  int i;
  int inputparts;
  char *output;
  char *base64data;

  char *indata = (char *) inp;

  *outptr = NULL;		/* set to NULL in case of failure before we reach the end */

  if (0 == insize)
    insize = strlen (indata);

  base64data = output = (char *) malloc (insize * 4 / 3 + 4);
  if (NULL == output)
    return 0;

  while (insize > 0)
    {
      for (i = inputparts = 0; i < 3; i++)
	{
	  if (insize > 0)
	    {
	      inputparts++;
	      ibuf[i] = *indata;
	      indata++;
	      insize--;
	    }
	  else
	    ibuf[i] = 0;
	}
      obuf[0] = (ibuf[0] & 0xFC) >> 2;
      obuf[1] = ((ibuf[0] & 0x03) << 4) | ((ibuf[1] & 0xF0) >> 4);
      obuf[2] = ((ibuf[1] & 0x0F) << 2) | ((ibuf[2] & 0xC0) >> 6);
      obuf[3] = ibuf[2] & 0x3F;

      switch (inputparts)
	{
	case 1:		/* only one byte read */
	  snprintf (output, 5, "%c%c==", table64[obuf[0]], table64[obuf[1]]);
	  break;
	case 2:		/* two bytes read */
	  snprintf (output, 5, "%c%c%c=", table64[obuf[0]], table64[obuf[1]], table64[obuf[2]]);
	  break;
	default:
	  snprintf (output, 5, "%c%c%c%c", table64[obuf[0]], table64[obuf[1]], table64[obuf[2]], table64[obuf[3]]);
	  break;
	}
      output += 4;
    }
  *output = 0;
  *outptr = base64data;		/* make it return the actual data memory */

  return strlen (base64data);	/* return the length of the new data */
}

/* ---- End of Base64 Encoding ---- */




void
A4GL_change_trailing_zeros_for_leading_spaces (char *s)
{
  int dp = -1;
  int len;
  char buff[2000];
  int newlen;
  int a;
  len = strlen (s);
  for (a = 0; a < len; a++)
    {
      if (s[a] == a4gl_convfmts.printf_decfmt.decsep)
	{
	  dp = a;
	  break;
	}
    }
  if (dp == -1)
    return;

  for (a = len - 1; a > dp + 1; a--)
    {
      if (s[a] == '0')
	s[a] = ' ';
      else
	break;
    }
  A4GL_trim (s);
  newlen = strlen (s);
  if (newlen < len)
    {
      memset (buff, ' ', sizeof (buff));
      buff[sizeof (buff) - 1] = 0;
      strcpy (&buff[len - newlen], s);
      strcpy (s, buff);
    }

}

void
A4GL_remove_trailing_zeros_and_leading_spaces (char *s)
{
  int dp = -1;
  int len;
  //char buff[2000];
  //int newlen;
  int a;
  A4GL_lrtrim (s);
  len = strlen (s);
  for (a = 0; a < len; a++)
    {
      if (s[a] == a4gl_convfmts.printf_decfmt.decsep)
	{
	  dp = a;
	  break;
	}
    }
  if (dp == -1)
    return;

  for (a = len - 1; a > dp + 1; a--)
    {
      if (s[a] == '0')
	s[a] = ' ';
      else
	break;
    }
  A4GL_trim (s);

}



void
A4GL_convert_to_pdf_y (void)
{
  double d;
  d = A4GL_pop_double ();
  d *= -1.0;
  A4GL_push_double (d);
}

void
A4GL_convert_to_pdf_x (void)
{
  double d;
  d = A4GL_pop_double ();
  d *= -1.0;

  A4GL_push_double (d);
}



static int
get_inc_quotes (int a)
{
  if ((a & DTYPE_MASK) == DTYPE_CHAR || (a & DTYPE_MASK) == DTYPE_VCHAR)
    return 1;
  if ((a & DTYPE_MASK) == DTYPE_DATE)
    return 2;
  if ((a & DTYPE_MASK) == DTYPE_DTIME)
    return 3;
  if ((a & DTYPE_MASK) == DTYPE_INTERVAL)
    return 4;
  return 0;
}




/// Gets a "construct" style query string for a table/column for the specified value of the specified type/length, called in 4gl as :
//         call aclfgl_get_construct_element(tabname,colname,value,dtype,dtype_length) returning lv_str
//
// Heres a test program : 
// main
// define lv_s chaR(40)
//         call aclfgl_get_construct_element("systables","tabid",">1", 0,4) returning lv_s
//         display lv_s
//         call aclfgl_get_construct_element("systables","tabid","1|2|3", 0,4) returning lv_s
//         display lv_s
//  end main
//
// This generates : 
//
// systables.tabid>'1'
// systables.tabid in ('1','2','3')
//
//
// Eventually - this will be used in callbacks to 4gl CONSTRUCTs
int aclfgl_aclfgl_get_construct_element(int n) {
char *tabname;
char *colname;
char *value;
int dtype;
int dtype_length;

if (n!=5) {A4GLSQL_set_status(-3002,0);A4GL_pop_args(n);A4GL_push_char("");return 1;}


dtype_length=A4GL_pop_long();
dtype=A4GL_pop_long();
value=A4GL_char_pop();
colname=A4GL_char_pop();
tabname=A4GL_char_pop();
A4GL_trim(colname);
A4GL_trim(tabname);
A4GL_trim(value);
A4GL_push_char(A4GL_construct (tabname, colname, value, get_inc_quotes (dtype), dtype & DTYPE_MASK, dtype_length,NULL));
return 1;

}


int aclfgl_aclfgl_trim_nl(int n) {
char *p;
p=A4GL_char_pop();

A4GL_trim_nl(p);
A4GL_push_char(p);
free(p);
return 1;
}

/* =================================== EOF ============================= */

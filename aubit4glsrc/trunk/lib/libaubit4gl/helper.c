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
# $Id: helper.c,v 1.26 2004-03-17 13:33:55 mikeaubury Exp $
#
*/

/**
 * @file
 *
 * @todo Add Doxygen A4GL_comments to file
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen A4GL_comments to add to functions
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/


#include "a4gl_libaubit4gl_int.h"
void A4GLPACKER_clrlibptr (void);
void A4GLFORM_clrlibptr (void);

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
  "Database",
  "Delimiters",
  "ScreenRecordCount",
  "ScreenRecordName%",
  "FieldCount",
  "FieldName%",
  "AttributesCount",
  "CurrentField",
  "Width",
  "Height",
  "Field%",
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

int A4GL_setenv(char *name, char *value, int overwrite);

static long *ptr;

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
      if (strchr (arr[a], '%'))
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
    case 1:
      A4GL_push_char (p->fileform->dbname);
      break;
    case 2:
      A4GL_push_char (p->fileform->delim);
      break;
    case 3:
      A4GL_push_int (p->fileform->records.records_len);
      break;
    case 4:
      params = 0;
      break;			/* not implemented yet! */
    case 5:
      A4GL_push_int (p->fileform->fields.fields_len);
      break;
    case 6:
      sprintf (buff, "%s.%s",
	       p->fileform->attributes.attributes_val[used_value].tabname,
	       p->fileform->attributes.attributes_val[used_value].colname);
      A4GL_push_char (buff);
      break;
    case 7:
      A4GL_push_int (p->fileform->attributes.attributes_len);
      break;
    /** @todo Understand if the push of a pointer as if it was 
	   *  pointer is correct and if not correct it
		 *  I think that this is not called.
	   */
    case 8:
      A4GL_push_int ((int) p->currentfield);
      break;
    case 9:
      A4GL_push_int (p->fileform->maxcol);
      break;
    case 10:
      A4GL_push_int (p->fileform->maxline);
      break;
    case 11:
      A4GL_push_int (p->fileform->metrics.
		metrics_val[p->fileform->fields.fields_val[used_value].metric.
			    metric_val[0]].field);
      break;

    case 0:
      A4GL_exitwith ("Invalid Window info request");
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
      break;
    case 0:
      A4GL_exitwith ("Invalid Window info request");
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
      A4GL_push_int (p->h);
      break;
    case 2:
      A4GL_push_int (p->w);
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

  return 0;

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


/* Some bits stripped out */

/**
 *
 * @param
 * @return
 */
int
aclfgl_i_rowid_s (int arg)
{
  if ((ptr = (long *) malloc (sizeof (long))) != NULL)
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
  if ((ptr =
       (long *) realloc ((char *) ptr,
			 (unsigned) (size + 1) * sizeof (long))) != NULL)
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

/**
 *
 * @param
 * @return
 */
int
aclfgl_fgl_prtscr (int n)
{
  return 0;
}


/**
 *
 * @param
 * @return
 */
char last_field[256];
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
A4GL_add_compiled_form (char *s, char *packer, char *formtype, char *frm)
{
  A4GL_debug ("Adding compiled form name='%s' ptr=%p\n", s, frm);
  if (!(A4GL_has_pointer (s, COMPILED_FORM)))
    {
      A4GL_add_pointer (s, COMPILED_FORM, frm);
      A4GL_add_pointer (s, COMPILED_FORM_PACKER, packer);
      A4GL_add_pointer (s, COMPILED_FORM_FORMTYPE, formtype);
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

#ifdef DEBUG
  A4GL_debug ("read_form %s %s", s, p);
#endif
  if (A4GL_has_pointer (s, COMPILED_FORM))
    {
      A4GL_debug ("COMPILED_FORM!");
      sprintf (old_packer, acl_getenv ("A4GL_PACKER"));
      sprintf (old_formtype, acl_getenv ("A4GL_FORMTYPE"));
      A4GL_debug ("Saved old packer=%s formtype=%s", old_packer, old_formtype);
      A4GLFORM_clrlibptr ();
      A4GLPACKER_clrlibptr ();
      A4GL_setenv ("A4GL_FORMTYPE", A4GL_find_pointer_val (s, COMPILED_FORM_FORMTYPE), 1);
      A4GL_setenv ("A4GL_PACKER", A4GL_find_pointer_val (s, COMPILED_FORM_PACKER), 1);
    }
  strcpy (buff, s);
  strcat (buff, acl_getenv ("A4GL_FRM_BASE_EXT"));
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



/* -------------------------------------------------------------------------- */
/* fgl_setenv()                                                               */
/*                                                                            */
/* This function allows to set or reset the value of environment variables.   */
/* It expects one parameter : a string like VARIABLE=value with maximum 1024  */
/* characters.  If the environment variable does not exists, it is created.   */
/*                                                                            */
/* Example : call fgl_setenv("DBPATH=/usr/app/appx")                          */
/*
	Writen by: (posted on 4Js mailing list)
	Dragan Kovac
	Centric Bussiness Solusions
	Dragan.Kovac@kramers.nl
	010-217-03-54
	010-217-04-00

   On some machines (e.g. SCO Unix) putenv(C) makes the argument string
   part of the environment, so if you change the string ,
   the environment changes.
   Therefore we must malloc a new string for each call of fgl_setenv.
	
*/

/* -------------------------------------------------------------------------- */
/*
int 
fgl_setenv(int noarg)
{
char *putvar ;

  putvar=(char *)malloc(1025);

  popquote(i_s,sizeof(i_s));
  clip(i_s);
  if (putenv(i_s))
    {
    fprintf(stderr,"\nFGL_SETENV(%s) : Failed.\n",i_s);
    _efemode();
    exit(1);
    }
  return(0);
  }
*/
  
int
A4GL_setenv(char *name, char *value, int overwrite)
{
//char* buff;
char buff[1024]; /* YES THIS IS USED - DONT LET THE COMPILER TELL YOU OTHERWISE!!! */
int ret;
char prefixed_name[256];
char *ptr;
sprintf (prefixed_name, "A4GL_%s", name);
/* Clear the current cache if there is one.. */
ptr=(char *)A4GL_has_pointer (name,STR_RESOURCE_VAL);
if (ptr) {
	A4GL_del_pointer(name,STR_RESOURCE_VAL);
}
ptr=(char *)A4GL_has_pointer (prefixed_name,STR_RESOURCE_VAL);
if (ptr) {
	A4GL_del_pointer(prefixed_name,STR_RESOURCE_VAL);
}


//#ifndef __MINGW32__		//No setenv() on MinGW
#if HAVE_SETENV
	//int setenv(const char *name, const char *value, int overwrite);
	ret = setenv (name,value,overwrite);
#else
	#if HAVE_PUTENV
		sprintf (buff,"%s=%s",name,value);
		//int putenv(char *string);
		//ret = putenv(buff);
		ret = putenv(strdup(buff));
	#else
		A4GL_debug ("No setenv() or putenv() - cannot set environment variable %s", name);
		return 1;
	#endif
#endif

	return ret;
}
  
  
/* =================================== EOF ============================= */

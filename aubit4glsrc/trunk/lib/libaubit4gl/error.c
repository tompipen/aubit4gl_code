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
# $Id: error.c,v 1.18 2003-05-12 14:24:05 mikeaubury Exp $
#
*/

/**
 * @file
 * Error handling (there are several files)
 * WARNING: errno renamed to a4gl_errno here and in mkerrors because of the
 * conflict with function mane in errno.h
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

#include "../generated/tmperrs.h"
#include "a4gl_libaubit4gl_int.h"

/*
=====================================================================
                    Constants definitions
=====================================================================
*/

/* 
DO NOT USE e-x-i-t-w-i-t-h as word - it will confuse mkerrors script@
this would prevent exit-with call from exiting program. If you need it
please use -DIGNOREEXITWITH on compile line, do not hard-code it! */
/* #define IGNOREEXITWITH */

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

char errorbuff[256] = "";
char lasterrorstr[1024] = "";
int cache_status = 0;
int cache_statusno = 0;
int int_err_flg;
void aclfgli_clr_err_flg (void);
void aclfgli_set_err_flg (void);
int aclfgli_get_err_flg (void);

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

char *get_errm (int z);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/



/**
 *
 * @todo Describe function
 */
void
// IGNOREEXITWITH exit-with(char *s)
exitwith (char *s)
{
  int a;

#ifdef DEBUG
  {
    debug ("Error... %s", s);
  }
#endif

#ifndef IGNOREEXITWITH

  for (a = 0; errors[a].a4gl_errno; a++)
    {
      if (strcmp (s, errors[a].errmsg) == 0)
	{
#ifdef DEBUG
	  {
	    debug ("Found error = %d", errors[a].a4gl_errno);
	  }
#endif
	  debug ("Setting status");
	  A4GLSQL_set_status (-1 * (errors[a].a4gl_errno + 30000), 0);
	  debug ("Setting cache_status");
	  cache_status = (errors[a].a4gl_errno + 30000);
	  debug ("Setting statusno");
	  cache_statusno = a;
	  return;
	  printf ("Error:\n %s \nSTOP\n ", s);
	  debug ("Exiting program.");
	  exit (errors[a].a4gl_errno);
	}
    }

  exitwith ("Unknown error");
#endif
}

/**
 *
 * @todo Describe function
 */
void
//IGNOREEXITWITH exitwith_sql(char *s)
exitwith_sql (char *s)
{
  int a;

#ifdef DEBUG
  {
    debug ("Error... %s", s);
  }
#endif

#ifndef IGNOREEXITWITH

  for (a = 0; errors[a].a4gl_errno; a++)
    {
      if (strcmp (s, errors[a].errmsg) == 0)
	{
#ifdef DEBUG
	  {
	    debug ("Found error = %d", errors[a].a4gl_errno);
	  }
#endif
	  A4GLSQL_set_status (-1 * (errors[a].a4gl_errno + 30000), 1);
	  cache_status = (errors[a].a4gl_errno + 30000);
	  cache_statusno = a;
	}
    }
  /* for now, until error handling and logging routines are completed,
   * display the error message to standard output
   */

  printf ("Error: %s\n", s);

  exit (errors[a].a4gl_errno);

#endif
}

/**
 *
 * @todo Describe function
 */
void
set_error (char *fmt, ...)
{
  va_list args;
  va_start (args, fmt);
  vsprintf (errorbuff, fmt, args);
#ifdef DEBUG
  /* {DEBUG} */
  {
    debug ("%s", errorbuff);
  }
#endif
}

/**
 *
 * @todo Describe function
 */
char *
get_errm (int z)
{
  int a = 0;
  debug ("In get errm");
  if (z == cache_status)
    {
      debug ("Cached...");
      return errors[cache_statusno].errmsg;
    }

  debug ("Looking up error... %d", a);
  for (a = 0; errors[a].a4gl_errno; a++)
    {
      if (errors[a].a4gl_errno + 30000 == z)
	{
	  return errors[a].errmsg;
	}
    }
  debug ("Not found...");
  debug ("Returning %p", lasterrorstr);
  debug ("Returning %s", lasterrorstr);
  return lasterrorstr;
}


/**
 *
 * @todo Describe function
 */
void
aclfgli_clr_err_flg (void)
{
  int_err_flg = 0;
}

/**
 *
 * @todo Describe function
 */
void
aclfgli_set_err_flg (void)
{
  int_err_flg = 1;
}

/**
 *
 * @todo Describe function
 */
int
aclfgli_get_err_flg (void)
{
  return int_err_flg;
}

/* ======================== EOF ======================= */

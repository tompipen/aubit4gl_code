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
# $Id: error.c,v 1.33 2005-11-21 18:29:41 mikeaubury Exp $
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


#include "a4gl_libaubit4gl_int.h"
#ifndef  FILE_TMPERRS_H
#define FILE_TMPERRS_H "../generated/tmperrs.h"
#endif
#ifndef SIMPLIFIED
#include FILE_TMPERRS_H
#else
#include "tmperrs.h"
#endif

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
static char lasterrorstr[1024] = "";
int cache_status = 0;
int cache_statusno = 0;
static int int_err_flg;
//void aclfgli_clr_err_flg (void);
void aclfgli_set_err_flg (void);
//int aclfgli_get_err_flg (void);

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

char *A4GL_get_errm (int z);

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
A4GL_exitwith (char *s)
{
int a;

	#ifdef DEBUG
		A4GL_debug ("Error: %s", s);
	#endif

#ifndef IGNOREEXITWITH

  for (a = 0; errors[a].a4gl_errno; a++) {
      if (strcmp (s, errors[a].errmsg) == 0) {
		#ifdef DEBUG
			A4GL_debug ("Found error = %d", errors[a].a4gl_errno);
		#endif
		A4GL_debug ("Setting status");
		A4GLSQL_set_status (-1 * (errors[a].a4gl_errno + 30000), 0);
		A4GL_debug ("Setting cache_status");
		cache_status = (errors[a].a4gl_errno + 30000);
		A4GL_debug ("Setting statusno");
		cache_statusno = a;


		return;



	  }
  }

  A4GL_exitwith ("Unknown error");
#endif
}

/**
 *
 * @todo Describe function
 */
void
//IGNOREEXITWITH exitwith_sql(char *s)
A4GL_exitwith_sql (char *s)
{
  int a;

#ifdef DEBUG
  {
    A4GL_debug ("Error... %s", s);
  }
#endif

#ifndef IGNOREEXITWITH

  for (a = 0; errors[a].a4gl_errno; a++)
    {
      if (strcmp (s, errors[a].errmsg) == 0)
	{
		#ifdef DEBUG
	    	A4GL_debug ("Found error = %d", errors[a].a4gl_errno);
		#endif
	  A4GLSQL_set_status (-1 * (errors[a].a4gl_errno + 30000), 1);
	  cache_status = (errors[a].a4gl_errno + 30000);
	  cache_statusno = a;
	}
    }
  /* for now, until error handling and logging routines are completed,
   * display the error message to standard output
   */

  return;

  #ifdef DEBUG
  	A4GL_debug ("About to exit with code %d %d", errors[a].a4gl_errno,errors[cache_statusno].a4gl_errno);
  #endif

  A4GL_fgl_die (errors[cache_statusno].a4gl_errno);

#endif
}

/**
 *
 * @todo Describe function
 */
void
A4GL_set_error (char *fmt, ...)
{
  va_list args;
  va_start (args, fmt);
  VSPRINTF (errorbuff, fmt, args);
#ifdef DEBUG
  /* {DEBUG} */
  {
    A4GL_debug ("%s", errorbuff);
  }
#endif
}

/**
 *
 * @todo Describe function
 */
char *
A4GL_get_errm (int z)
{
  int a = 0;
char *ptr;
  A4GL_debug ("In get errm");
  if (z == cache_status)
    {
      A4GL_debug ("Cached...");
      return errors[cache_statusno].errmsg;
    }

  A4GL_debug ("Looking up error... %d", a);
  for (a = 0; errors[a].a4gl_errno; a++)
    {
      if (errors[a].a4gl_errno + 30000 == z)
	{
	  return errors[a].errmsg;
	}
    }
  A4GL_debug ("Not found...");
  A4GL_debug ("Returning %p", lasterrorstr);
  A4GL_debug ("Returning %s", lasterrorstr);
  ptr=A4GLSQL_get_errmsg(0-z);
  if (ptr) return ptr;

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

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
# $Id: error.c,v 1.40 2007-02-20 18:46:37 gyver309 Exp $
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
char lasterrorstr[1024] = "";
static int cache_status = 0;
static char * cache_errmsg = "";
static int int_err_flg;
//void aclfgli_clr_err_flg (void);
void aclfgli_set_err_flg (void);
struct s_err * A4GL_get_errdesc_for_errstr (char *s);
//int aclfgli_get_err_flg (void);

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

char *A4GL_get_errmsg (int z);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/**
 *
 * @todo Describe function
 */
struct s_err * A4GL_get_err_for_errstr (char *s)
{
    static struct s_err err_default = {"Unknown error", -1};
    int a;
    A4GL_debug ("Looking for error desc for errmsg=\"%s\"", s);
    for (a = 0; errors[a].a4gl_errno; a++)
    {
	if (strcmp (s, errors[a].errmsg) == 0)
	{
	    A4GL_debug ("Found error desc, a4gl_errno=%i", errors[a].a4gl_errno);
	    return &errors[a];
	}
    }
    A4GL_debug ("Error desc not found, returning default");
    return &err_default;
}

/**
 *
 * @todo Describe function
 */
int A4GL_get_errcode_for_errstr (char *s)
{
    int retval = -1;
    retval = A4GL_get_err_for_errstr(s)->a4gl_errno;
    if (retval == -1)
	return -1;
    return A4GL_ERR_BASE + retval;
}

/**
 *
 * @todo Describe function
 */
void
A4GL_exitwith (char *s)
{
#ifndef IGNOREEXITWITH
    struct s_err *errdesc;
    errdesc = A4GL_get_err_for_errstr(s);

    A4GL_debug ("Setting status, cache_status, cache_errmsg");
    cache_errmsg =      errdesc->errmsg; // static, read-only - safe
    if (errdesc->a4gl_errno == -1) //not found
    {
	A4GLSQL_set_status (-1, 0);
	cache_status       = -1;
    }
    else
    {
	A4GLSQL_set_status (-1 * (A4GL_ERR_BASE + errdesc->a4gl_errno), 0);
	cache_status =            A4GL_ERR_BASE + errdesc->a4gl_errno;
    }
//    A4GL_fgl_die (1);
#endif
}

/**
 *
 * @todo Describe function
 */
void
A4GL_exitwith_sql (char *s)
{
#ifndef IGNOREEXITWITH
    struct s_err *errdesc;
    errdesc = A4GL_get_err_for_errstr(s);

    A4GL_debug ("Setting status, cache_status, cache_errmsg");
    cache_errmsg = errdesc->errmsg; // static, read-only - safe
    if (errdesc->a4gl_errno == -1) //not found
    {
	A4GLSQL_set_status (-1, 0);
	cache_status       = -1;
    }
    else
    {
	A4GLSQL_set_status (-1 * (A4GL_ERR_BASE + errdesc->a4gl_errno), 1);
	cache_status =            A4GL_ERR_BASE + errdesc->a4gl_errno;
    }
//    A4GL_fgl_die (errdesc->a4gl_errno);
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


void A4GL_set_lasterrorstr(char *s) {
	strcpy(lasterrorstr,s);
}

/**
 *
 * @todo Describe function
 */
char *
A4GL_get_errmsg (int z)
{
  int a = 0;
  char *ptr;
  A4GL_debug ("In get errm");
  if (z == cache_status)
    {
      A4GL_debug ("Cached...");
      return cache_errmsg;
    }

  A4GL_debug ("Looking up error... %d", a);
  for (a = 0; errors[a].a4gl_errno; a++)
    {
      if (errors[a].a4gl_errno + A4GL_ERR_BASE == z)
	{
	  return errors[a].errmsg;
	}
    }
  A4GL_debug ("Not found...");
  ptr = A4GLSQL_get_errmsg(0-z);
  if (ptr)
  {
      A4GL_debug ("Returning A4GLSQL_get_errmsg \"%s\"", lasterrorstr);
      return ptr;
  }

  A4GL_debug ("Returning lasterror %p \"%s\"", lasterrorstr, lasterrorstr);
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
  //if (a4gl_status!=0) {
	  //A4GL_assertion(1,"should status be reset here ?");
  //}
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

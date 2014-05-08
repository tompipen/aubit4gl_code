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
# $Id: error.c,v 1.59 2010-11-19 15:15:02 mikeaubury Exp $
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

static char *err_txt;
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
static char *cache_errmsg = "";
static int int_err_flg = 0;
static char sqlerrmessage[2560]="";
//void aclfgli_clr_err_flg (void);
void aclfgli_set_err_flg (void);
struct s_err *A4GL_get_errdesc_for_errstr (char *s);

int *ignoreList=NULL;
int nIgnoreList=0;


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
static int is_in_ignore_list(int l);



#define ERR_UNDEF  -30001

/**
 *
 * @todo Describe function
 */
static struct s_err *
A4GL_get_err_for_errstr (char *s)
{
  static struct s_err err_default = { "Unknown error", ERR_UNDEF };
  int a;
#ifdef DEBUG
  A4GL_debug ("Looking for error desc for errmsg=\"%s\"", s);
#endif
  for (a = 0; errors[a].a4gl_errno; a++)
    {
      if (strcmp (s, errors[a].errmsg) == 0)
	{
#ifdef DEBUG
	  A4GL_debug ("Found error desc, a4gl_errno=%i", errors[a].a4gl_errno);
#endif
	  return &errors[a];
	}
    }
#ifdef DEBUG
  A4GL_debug ("Error desc not found, returning default");
#endif
  return &err_default;
}

/**
 *
 * @todo Describe function
 */
int
A4GL_get_errcode_for_errstr (char *s)
{
  int retval = ERR_UNDEF;
  retval = A4GL_get_err_for_errstr (s)->a4gl_errno;
  if (retval == ERR_UNDEF)
    return ERR_UNDEF;
  if (retval>0) {
  return A4GL_ERR_BASE + retval;
  } else {
	return retval*-1;
  }
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
  errdesc = A4GL_get_err_for_errstr (s);

#ifdef DEBUG
  A4GL_debug ("Setting status, cache_status, cache_errmsg");
#endif


  cache_errmsg = errdesc->errmsg;	// static, read-only - safe
  if (errdesc->a4gl_errno == ERR_UNDEF)	//not found
    {
      A4GL_set_status (ERR_UNDEF, 0);
      cache_status = ERR_UNDEF;
    }
  else
    {
	if (errdesc->a4gl_errno>0) {
      		A4GL_set_status (-1 * (A4GL_ERR_BASE + errdesc->a4gl_errno), 0);
      		cache_status = A4GL_ERR_BASE + errdesc->a4gl_errno;
	} else {
      		A4GL_set_status (errdesc->a4gl_errno, 0);
      		cache_status = -1*errdesc->a4gl_errno;
	}
    }


#endif
}

void
A4GL_exitwith_sql_detail (char *s,char *detail) {
char buff[20000];
A4GL_exitwith_sql(s);
sprintf(buff,"%s:%s",s,detail);
buff[sizeof(sqlerrmessage)-1]=0;
strcpy(sqlerrmessage,buff);
A4GL_trim(sqlerrmessage);
}

void A4GL_set_sqlerrmessage(char *s) {
char buff[20000];
strcpy(buff,s);
buff[sizeof(sqlerrmessage)-1]=0;
strcpy(sqlerrmessage,buff);
A4GL_trim(sqlerrmessage);
}


void A4GL_push_sqlerrmessage(void) {
	A4GL_push_char(sqlerrmessage);
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
  errdesc = A4GL_get_err_for_errstr (s);

  strcpy(sqlerrmessage,s);

#ifdef DEBUG
  A4GL_debug ("Setting status, cache_status, cache_errmsg");
#endif
  cache_errmsg = errdesc->errmsg;	// static, read-only - safe
  if (errdesc->a4gl_errno == ERR_UNDEF)	//not found
    {
      A4GL_set_status (ERR_UNDEF, 0);
      cache_status = ERR_UNDEF;
    }
  else
    {
	if (errdesc->a4gl_errno>0) {
      		A4GL_set_status (-1 * (A4GL_ERR_BASE + errdesc->a4gl_errno), 1);
      		cache_status = A4GL_ERR_BASE + errdesc->a4gl_errno;
	} else {
      		A4GL_set_status ( errdesc->a4gl_errno, 1);
      		cache_status = -1*errdesc->a4gl_errno;
	}
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


void
A4GL_set_lasterrorstr (const char *s)
{
  strcpy (lasterrorstr, (char *)s);
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
#ifdef DEBUG
  A4GL_debug ("In get errm");
#endif
  if (z == cache_status)
    {
#ifdef DEBUG
      A4GL_debug ("Cached...");
#endif
      return cache_errmsg;
    }

#ifdef DEBUG
  A4GL_debug ("Looking up error... %d", a);
#endif
  for (a = 0; errors[a].a4gl_errno; a++)
    {
      if (errors[a].a4gl_errno + A4GL_ERR_BASE == z)
	{
	  return errors[a].errmsg;
	}
    }
#ifdef DEBUG
  A4GL_debug ("Not found...");
#endif
  ptr = A4GLSQL_get_errmsg (0 - z);
  if (ptr)
    {
#ifdef DEBUG
      A4GL_debug ("Returning A4GLSQL_get_errmsg \"%s\"", lasterrorstr);
#endif
      return ptr;
    }

#ifdef DEBUG
  A4GL_debug ("Returning lasterror %p \"%s\"", lasterrorstr, lasterrorstr);
#endif
  return lasterrorstr;
}


char *
A4GL_get_err_txt (void)
{
  return err_txt;
}


void
A4GL_set_err_txt (char *s)
{
  if (err_txt)
    free (err_txt);
  if (s)
    {
      err_txt = strdup (s);
      A4GL_trim (err_txt);
    }
  else
    {
      err_txt = 0;
    }
}

/**
 *
 * @todo Describe function
 */
void
aclfgli_clr_err_flg (void)
{
  int_err_flg = 0;

  A4GL_set_err_txt (0);
//printf("clr errflag : %d\n", int_err_flg);

}

/**
 *
 * @todo Describe function
 */
void
aclfgli_set_err_flg (void)
{

  if (is_in_ignore_list(a4gl_status)) return;
  int_err_flg = 1;
}

/**
 *
 * @todo Describe function
 */
int
aclfgli_get_err_flg (void)
{
//printf("get errflag : %d\n", int_err_flg);
  return int_err_flg;
}



void A4GL_clr_ignore_error_list(void ) {
	if (ignoreList) {
		free(ignoreList);
	}
	ignoreList=NULL;
	nIgnoreList=0;

}

static void add_to_ignore_list(int l) {
	if (ignoreList==NULL) {
		ignoreList=malloc(sizeof(int)) ;
		ignoreList[0]=l;
		nIgnoreList=1;
		return;
	}

	nIgnoreList++;
	ignoreList=realloc(ignoreList,sizeof(int)*nIgnoreList);
	ignoreList[nIgnoreList-1]=l;
}

static int is_in_ignore_list(int l) {
int a;
	if (ignoreList==NULL) {
		return 0;
	}
	for (a=0;a<nIgnoreList;a++) {
		if (ignoreList[a]==l) return 1;
	}
	return 0;
}



void A4GL_set_ignore_error_list(int n,...) {
  va_list ap;
  int l;

  A4GL_clr_ignore_error_list();


  // Add the first integer
  add_to_ignore_list(n);
  va_start (ap, n);

  while (1)
    {
        l = va_arg (ap, int);
	// Keep going until we get a '0'...
        if (l==0) return;
	add_to_ignore_list(l);
    }
  va_end(ap);
}

/* ======================== EOF ======================= */

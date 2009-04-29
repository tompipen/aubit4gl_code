/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0   root makefile              |
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
# $Id: aubit-config.c,v 1.31 2009-03-14 14:30:58 mikeaubury Exp $
#
*/

/**
 * @file
 *
 * aubit-config.c gets compiled up with
 * resource.c to form the "aubit-config" program
 *
 *
 * This should be the first thing made and can then be used for the makefiles
 * where required.
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include <stdarg.h>
#include <stdio.h>
#include <string.h>		/* strcmp() */
#include <stdlib.h>		/* exit() */
#include <ctype.h>		/* isprint() */

#ifndef PRINTF
#define PRINTF printf
#endif

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

/* replacements for functions normally in libaubit4gl */
void A4GL_debug_full_extended_ln (char *s, long l, const char *level, const char * func, char *fmt, ...);
int A4GL_set_line_extended (char *s, long l, const char *level, const char * func);
int A4GL_sprintf (char *f,int l, char *dest,size_t sdest,char *fmt, ...) ;



extern void A4GL_build_user_resources (void);
extern void A4GL_exitwith (void);
extern void A4GL_dump_all_resource_vars (int export);
extern char *acl_getenv (char *s);
char *A4GL_acl_getenv_setfrom(void);
void A4GL_trim_nl (char *p);
void A4GL_debug_full (char *fmt, ...);
void A4GL_debug_full_extended (char *fmt, ...);
void A4GL_set_line (void);
void A4GL_set_extended (void);
char *A4GL_strip_quotes (char *s);
void *A4GL_find_pointer(char *s,char c);
int A4GL_has_pointer(char *s,char c);
int A4GL_del_pointer(char *s,char c);
int A4GL_add_pointer(char *s,char c,void *x);
char *A4GL_strcpy(char *dest,char *src,char *f,int l);
void A4GL_pause_execution(void );
//char * DEBUG_CFG;

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

static void usage(void) {
      PRINTF ("\n");
      PRINTF ("Usage:\n");
      PRINTF ("     aubit-config [VARIABLE_NAME | -a]\n");
      PRINTF ("        -a: show all set variables\n");
      PRINTF ("        -ae: show all set variables as 'export VARIABLE=\n");
      PRINTF ("\n");
      exit (1);
}

int
main (int argc, char *argv[])
{
int debug=0;
int c=1;



//      DEBUG_CFG = acl_getenv ("DEBUG_CFG");

  /* load settings from config file(s): */
  A4GL_build_user_resources ();
  if (argc>1) {
  if (strcmp(argv[1],"-verbose") ==0) {
		c++;
		debug=1;
  }
  }


  if (argc != c+1) {
	usage();
	exit(20);
    }

  if (strcmp (argv[c], "-a") == 0)
    {
      A4GL_dump_all_resource_vars (0);
      exit (0);
    }

  if (strcmp (argv[c], "-ae") == 0)
    {
      A4GL_dump_all_resource_vars (1);
      exit (0);
    }

  if (debug) {
	char *r;
	r=acl_getenv(argv[c]);
  		PRINTF ("'%s'\n", r);
		PRINTF("Set from : %s\n", A4GL_acl_getenv_setfrom());
		if (strchr(r,'\r')) {	
			printf("WARNING : contains a carriage return\n");
		}
		if (strchr(r,'\n')) {	
			printf("WARNING : contains a newline\n");
		}
		
  } else {
#ifdef WIN32
  	PRINTF ("%s", acl_getenv (argv[c]));
#else
  	PRINTF ("%s\n", acl_getenv (argv[c]));
#endif
  }

  exit (0);
}

/**
 *  Take of the last new line in a string.
 *
 *  @param p The string to be trimmed.
 */
void
A4GL_trim_nl (char *p)
{
  int a;
  for (a = strlen (p) - 1; a >= 0; a--)
    {
      if (p[a] != ' ' && p[a] != '\n' && p[a] != '\r')
	break;
      p[a] = 0;
    }
}

/**
 * Simplified version of same function from libaubit4gl, to avoid linking
 * with libaubit4gl
 */
void
A4GL_debug_full (char *fmt, ...)
{
  va_list args;
  static char buff[4096];

  /* Problem here is that when DEBUG is set, this will A4GL_dump ALL settings
     to stdout. But when we are debugging, for instance, 4glc, and set DEBUG,
     we need aubit-config to return us things like AUBITDIR.

     As temporary sollution, I renamed DEBUG here to DEBUG_CFG.

   */


  if (strcmp ("ALL", acl_getenv ("DEBUG_CFG")) == 0)
//      if (strcmp ("ALL", DEBUG_CFG) == 0 )
    {
      va_start (args, fmt);
      vsprintf (buff, fmt, args);
      PRINTF ("%s\n", buff);
    }
}

void
A4GL_debug_full_extended_ln (char *fname, long lineno, const char *level, const char *func,char *fmt, ...)
{
  va_list args;
  static char buff[4096];

  /* Problem here is that when DEBUG is set, this will A4GL_dump ALL settings
     to stdout. But when we are debugging, for instance, 4glc, and set DEBUG,
     we need aubit-config to return us things like AUBITDIR.

     As temporary sollution, I renamed DEBUG here to DEBUG_CFG.

   */


  if (strcmp ("ALL", acl_getenv ("DEBUG_CFG")) == 0)
//      if (strcmp ("ALL", DEBUG_CFG) == 0 )
    {
      va_start (args, fmt);
      vsprintf (buff, fmt, args);
      PRINTF ("%s\n", buff);
    }
}

/**
 * Dummy function
 */
void
A4GL_exitwith (void)
{
}

/**
 * Dummy function
 */
void
A4GL_set_line (void)
{
}

/**
 * Dummy function
 */
int A4GL_set_line_extended (char *s, long l, const char *level, const char * func)
{
return 1;
}


/**
 *
 * @todo Describe function
 */
char *
A4GL_strip_quotes (char *s)
{
  static char buff[1024];
  if ((s[0] == '"' || s[0] == '\'') && s[strlen (s) - 1] == s[0])
    {
      strcpy (buff, &s[1]);
      buff[strlen (buff) - 1] = 0;
    }
  else
    {
      strcpy (buff, s);
    }
  //A4GL_debug ("Returning %s", buff);
  return buff;
}


void *A4GL_find_pointer(char *s,char c) {
	return 0;
}
int A4GL_has_pointer(char *s,char c) {
	return 0;
}

int A4GL_del_pointer(char *s,char c) {
	return 0;
}

int A4GL_add_pointer(char *s,char c,void *x) {
return 0;
}



#ifdef strcpy
#undef strcpy
#endif
//copy of function from funcs_d.c
char *A4GL_strcpy(char *dest,char *src,char *f,int l) {
	int a;
	strcpy(dest,src);

	if (strcmp(f,"dmy.c")==0) return dest;
	if (strlen(src)>255) {
		//A4GL_debug("Long string : %s\n",src);
	}
	for (a=0;a<strlen(src);a++) {
		if (!isprint(src[a])) {
			//A4GL_debug("bad char @%d for string '%s' (%d)\n",a,src,strlen(src));
		}
	}
	
	return dest;
}

void A4GL_pause_execution(void ) {
// Does nothing - only here so the thing will link
}


int A4GL_sprintf (char *f,int l, char *dest,size_t sdest,char *fmt, ...) {
int x;
char *c;
va_list args;
char xbuff[10000];

        if (sdest>sizeof(char *)) { // We do this one...
              va_start (args, fmt);
              c=malloc(sdest);
	      if (c==0) {
		      		PRINTF("Unable to allocate memory..\n");
				exit(1);
		}
              x=vsprintf(c,fmt,args);
              if (x>=sdest) {
			PRINTF("sprintf trying to exceed allocated space @ %s (line %d)",f,l);
			exit(1);
		
              }
              strncpy(dest,c,sdest);
              free(c);
        } else {
              va_start (args, fmt);
              x=vsprintf(xbuff,fmt,args);
                if (x>sizeof(xbuff)) {
                        PRINTF("sprintf > 10,000 characters when using a pointer...");
                }
              strcpy(dest,xbuff);
        }
        return x;
}


int A4GL_setenv(char *n,char *v,int o) {
	// normally part of libaubit4gl - but we dont need it here...
	return 0;
}

/* -------------------------- EOF ------------------------ */

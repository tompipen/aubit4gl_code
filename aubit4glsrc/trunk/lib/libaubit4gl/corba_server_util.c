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
# $Id: corba_server_util.c,v 1.1 2004-12-29 11:42:13 afalout Exp $
#
*/

/**
 * @file
 * 
 * This file contains 2 sections:
 * 
 * 1) Collections of primitive (or near primitive) functions we need in BOTH
 *    libaubit4gl AND when making CORBA server (to support dlopen functionality)
 * 
 * 2) Collections of utility functions for Aubit CORBA servers, in #ifdef __CAPI__ 
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
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
                    Variables definitions
=====================================================================
*/

int dying=0;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

//--- from funcs_d.c
#ifdef strcpy
#undef strcpy
#endif
char *A4GL_strcpy(char *dest,char *src,char *f,int l,int sd) {
  	int lsrc;
	A4GL_assertion(src==0,"No source for strcpy..");

	lsrc=strlen(src);
	if (sd!=sizeof(char *)) {
		if (lsrc>=sd) {
			A4GL_debug("String overflow detected : %s %d (%d>=%d)",f,l,strlen(src),sd);
			A4GL_assertion(1,"String overflow detected");
		}
	}
	strcpy(dest,src);


#ifdef DEBUG
{
// This just adds some debugging stuff - but this 
// isn't applicable when called from the routines in dmy.c 
// as they put some funny characters in the string as placeholders
//
	if (strcmp(f,"dmy.c")==0) return dest;


// Quick - is it big ?
	if (lsrc>255) {
		char buff[3000];
		strncpy(buff,src,2999);
		buff[2999]=0;
		A4GL_debug("Long string : %s\n",buff);
	}

// Does it look Good ?
{
	int a;
	for (a=0;a<lsrc;a++) {
		if (!isprint(src[a])&&src[a]!='\n'&&!ispunct(src[a])) {
			A4GL_debug("bad char @%d for string '%s' (%d)\n",a,src,strlen(src));
		}
	}
}
}
#endif
	
	return dest;
}

//--from string.c
char *A4GL_null_as_null(char *s) {
if (s==0) return "(null)";
return s;
}


// --- from fglwrap.c
void
A4GL_fgl_die_with_msg(int n,char *s)
{
if (dying) return;
dying++;
if (dying>1) { exit(n); }
  if (A4GL_isscrmode ())
    {
#ifdef DEBUG
      A4GL_debug ("In screen mode - ending curses...");
#endif
      A4GL_gotolinemode ();
    }
  A4GL_close_database ();
  A4GL_close_errorlog_file ();
  A4GL_debug ("End of program - exit(%d).",n);
  printf("%s\n",s);
  exit (n);
}

void
A4GL_fgl_die(int n)
{
if (dying) return;
dying++;
if (dying>1) { exit(n); }
  if (A4GL_isscrmode ())
    {
#ifdef DEBUG
      A4GL_debug ("In screen mode - ending curses...");
#endif
      A4GL_gotolinemode ();
    }
  A4GL_close_database ();
  A4GL_close_errorlog_file ();
  A4GL_debug ("End of program - exit(%d).",n);
  exit (n);
}


// from funcs_d.c
/**
 * Trim the spaces and new lines at the rigth side of a string.
 *
 * @param p The string to be trimmed.
 */
void
A4GL_trim_nl (char *p)
{
  int a;
  for (a = strlen (p) - 1; a >= 0; a--)
    {
      if (p[a] != ' ' && p[a] != '\n' && p[a] != '\r' && p[a] != '\t')
	break;
      p[a] = 0;
    }
}

/**
 * Trim the spaces at the rigth side of a string
 *
 * @param p The string to be trimmed.
 */
void
A4GL_trim (char *p)
{
  int a;
  for (a = strlen (p) - 1; a >= 0; a--)
    {
      if (p[a] != ' ' && p[a] != '\t' && p[a] != '\n' && p[a] != '\r')
	break;
      p[a] = 0;
    }
}



// --- from fglwrap.c
/**
 * Checks if the string have some sort of yes (y,Y,1,true).
 *
 * @param s The string to be checked
 * @return - 1 : Is yes
 *         - 0 : Otherwise
 */
int
A4GL_isyes (char *s)
{
  if (s == 0)
    {
      //debug("isyes = false");
      return 0;
    }
  //debug("isyes called with %s\n",s);
  if (s[0] == 0)
    {
      //debug("isyes = false");
      return 0;
    }
  if (s[0] == 'y' || s[0] == 'Y' || s[0] == '1'
      || A4GL_aubit_strcasecmp (s, "true") == 0)
    {
      //debug("isyes = true");
      return 1;
    }
  //debug("isyes = false");
  return 0;
}

//-- from match.c


/**
 *
 * @todo Describe function
 */
int
A4GL_aubit_strcasecmp (char *a, char *b)
{
  int c;
  int l1;
  int l2;
  int m;
   
  l1=strlen(a);
  l2=strlen(b);

  if (l1>l2) m=l2;
	else m=l1;
  
  for (c = 0; c <= m; c++)
    {
      if (toupper (a[c]) > toupper (b[c]))
	return 1;
      if (toupper (a[c]) < toupper (b[c]))
	return -1;
    }

  if (l1 == l2) return 0;
  if (l1 > l2 ) return 1;

  return -1;
}


/*
=====================================================================
                    CORBA server support ONLY
=====================================================================
*/

#ifdef __CAPI__

/* first, dummy finctions we don't need in CORBA server */

//
void A4GL_assertion(int a, char *s) {}
//
int A4GL_isscrmode() { return 0; }
//
void A4GL_gotolinemode() {}
//
void A4GL_close_database() {}
//
void A4GL_close_errorlog_file() {}
//debug.c:
void A4GL_debug_full(char *fmt, ...) {}
//debug.c:
int A4GL_set_line(char *fname, long lineno) {  return 0; }
//sql.c:
void A4GLSQL_set_status (int a, int sql) {}
//API_sql.spec
char* A4GLSQL_get_errmsg( int a) { return 0; } 


/* Then, copies of some functions we DO need, but don't want to move from there
	original .c file, and linking that .c file in causes bunch of new dependencies
	we dont want to introduce
*/


/*
gcc -L/usr/local/lib -L/usr/lib -L/usr/lib -lORBit -lIIOP -lORBitutil -lglib -lnsl -lm -o sqlparse-server CAPI_sqlparse-common.o CAPI_sqlparse-skels.o CAPI_sqlparse-skelimpl.o CAPI_sqlparse-server.o ../../libaubit4gl/API_sqlparse.o ../../libaubit4gl/calldll.o ../../resource/resource.o ../../libaubit4gl/error.o ../../libaubit4gl/pointers.o LOCAL_corba_server_util.o -ldl -lm

../../libaubit4gl/API_sqlparse.o: In function `A4GLSQLPARSE_clrlibptr':
/opt/aubit/aubit4glsrc/lib/libaubit4gl/API_sqlparse.c:42:multiple definition of `A4GLSQLPARSE_clrlibptr'
CAPI_sqlparse-server.o:/opt/aubit/aubit4glsrc/lib/libui/ui_highlevel/CAPI_sqlparse-server.c:8: first defined here

../../libaubit4gl/API_sqlparse.o: In function `A4GLSQLPARSE_initlib':
/opt/aubit/aubit4glsrc/lib/libaubit4gl/API_sqlparse.c:47: multiple definition of `A4GLSQLPARSE_initlib'
CAPI_sqlparse-server.o:/opt/aubit/aubit4glsrc/lib/libui/ui_highlevel/CAPI_sqlparse-server.c:13: first defined here


/usr/lib/gcc-lib/i386-redhat-linux/2.96/../../../crt1.o: In function `_start':
/usr/lib/gcc-lib/i386-redhat-linux/2.96/../../../crt1.o(.text+0x18): undefined reference to `main'
collect2: ld returned 1 exit status
make: *** [sqlparse-server] Error 1


*/


#endif //__CAPI__
// ---------------------------------- EOF ---------------------------------

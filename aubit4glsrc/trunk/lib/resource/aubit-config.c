/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0   root makefile              |
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
# $Id: aubit-config.c,v 1.3 2002-05-20 11:41:13 afalout Exp $
#
*/

/**
 * @file
 *
 * aubit-config.c gets compiled up with
 * resource.c to form the "aubit-config" program
 *
 * $ aubit-config DBDATE
 * dmy4/
 *
 * This should be the first thing made and can then be used for the makefiles
 * where required..
 */

#include <stdarg.h>
#include <stdio.h>
#include <string.h> //strcmp()
#include <stdlib.h> //exit()

/*
extern int strcmp (const char *, const char *);
extern int strlen(char);
extern void exit(int);
*/

extern void build_user_resources(void);
extern void exitwith(void);
extern void dump_all_resource_vars(void);
extern char *acl_getenv (char *s);

int
main(int argc,char *argv[]) 
{

	//load settings from config file(s):
	build_user_resources();

	if (argc!=2) {
		printf("Usage : %s [ VARIABLE_NAME | -a ] (-a = all)\n",argv[0]);
		exit(1);
	}

	if (strcmp(argv[1],"-a")==0)
		dump_all_resource_vars();
	else
		printf("%s\n",acl_getenv(argv[1]));

	exit(0);
}

/**
 *  Take of the last new line in a string.
 *
 *  @param p The string to be trimmed.
 */
void
trim_nl(char *p) 
{
        int a;
        for (a=strlen(p)-1;a>=0;a--) {
                if (p[a]!=' '&&p[a]!='\n'&&p[a]!='\r')  break;
                p[a]=0;
        }
}

/**
 * Simplified version of same function from libaubit4gl, to avoid linking
 * with libaubit4gl
 */
void
debug_full (char *fmt,...)
{
  va_list args;
  static char buff[4096];

  /* Problem here is that when DEBUG is set, this will dump ALL settings
  to stdout. But when we aer debuggung, for instance, 4glc, ans set DEBUG,
  we need aubit-config to return us things like AUBITDIR.

  As temporary sollution, I renamed DEBUG here to DEBUG_CFG.

  */

  if (strcmp ("ALL", acl_getenv ("DEBUG_CFG")) == 0 )
    {
	  va_start (args, fmt);
	  vsprintf (buff, fmt, args);
      printf("%s\n",buff);
    }
}

/**
 * Dummy function
 */
void
exitwith(void) {
}

/**
 * Dummy function
 */
void
set_line(void) {
}


//-------------------------- EOF ------------------------

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
# $Id: main.c,v 1.2 2005-03-25 12:48:31 afalout Exp $
#
*/

/**
 * @file
 * 
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include <stdio.h>
#include <stdlib.h>               /* exit() */
#ifdef NDEF
	#include "ilist.h"
	#include "y.tab.h"
	extern char* yytext;
	extern FILE *yyin;
	int process(void) ;
	char *sql_string;
	int sql_type;
	extern int was_ok=0;
#endif

extern int asql_yydebug;
char * A4GLSQLCV_convert_file (char *target_dialect, char *sql); 
	
/**
 * The main entry point function of SQL conversion command-line utility executable
 *
 * @param argc The argument count
 * @param argv The argument values
 */
int
main(int argc,char *argv[]) {
char *snew;
	if (argc!=2) {
		printf("Usage : %s filename\n",argv[0]);
		exit(2);
	}
	snew=A4GLSQLCV_convert_file("POSTGRES",argv[1]);
	printf("%s\n",snew);
	return 0;
}


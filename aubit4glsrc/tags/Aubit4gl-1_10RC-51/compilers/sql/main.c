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
# $Id: main.c,v 1.17 2009-02-23 17:31:49 mikeaubury Exp $
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
#include <stdarg.h>
#include <string.h>
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
#include "a4gl_libaubit4gl.h"
#include "sql_compiler_util.h"
extern int db_used;

extern int sqlparse_yydebug;
//char * A4GLSQLCV_convert_file (char *target_dialect, char *sql); 
	
/**
 * The main entry point function of SQL conversion command-line utility executable
 *
 * @param argc The argument count
 * @param argv The argument values
 */
int
main(int argc,char *argv[]) {
char *snew;
char *dialect;
char *default_database;
int pcnt=0;
int converted=0;

	if (argc<2) {
		printf("Usage : %s filename [dbname [dialect]]\n",argv[0]);
		exit(2);
	}
	A4GL_init_gen_stack();
	if (A4GL_isyes(acl_getenv("DOING_CM")) ) {
  		A4GL_setenv ("EXPAND_COLUMNS", "Y", 1);
  		A4GL_setenv ("FULL_INSERT", "Y", 1);
	}
	set_write_std_err_on_error();
	dialect=acl_getenv_not_set_as_0("A4GL_TARGETDIALECT");

	// Load any explicit temp table names
	load_temp_table();
	//if (dialect==0) dialect="POSTGRES";
	if (A4GL_isyes(acl_getenv("YYDEBUG"))) {
		printf("YYDEBUG\n");
		sqlparse_yydebug=1;
	}

	if (argc>=3) {
		default_database=acl_getenv_not_set_as_0("DEFAULT_DATABASE");
		if (default_database==0) {
			default_database=argv[2];
			if (strlen(default_database)==0) {
				default_database=0;
			} else {
				if (strcmp(default_database,"-")==0) {
					default_database=0;
				}
			}
		}

		if (default_database) {
	        	A4GL_set_status (0, 1);
  			A4GL_init_connection (default_database);
  			if (A4GL_get_status () != 0) {
				printf("Couldn't connect to database\n");
				exit(1);
    			}
			//printf("Opened database : %s\n",default_database);
			db_used=1;
		}

	}

	if (argc>=4) {
		dialect=argv[3];
	}
	
	snew=A4GLSQLCV_convert_file(dialect,argv[1]);
	if (snew==0) {
		fprintf(stderr,"Fatal error...\n");
		exit(2);
	}
	if (strcmp(snew,"<err>")==0) { exit(1); }
	
	snew=A4GLSQLCV_check_sql(snew,&converted); 
	while (1) {
		char *ptr;
		ptr=strstr(snew,"?@@PARAM@@?");
		if (ptr==0) break;
		if (ptr) {
			char buff[256];
			      //      ?@@PARAM@@?
			sprintf(buff,"@param_%04d",pcnt++);
			strncpy(ptr,buff,strlen(buff));
		}
	}
	printf("%s\n",snew);
	return 0;
}

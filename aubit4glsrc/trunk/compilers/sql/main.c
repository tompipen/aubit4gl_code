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
# $Id: main.c,v 1.9 2005-10-31 19:05:52 mikeaubury Exp $
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
extern int db_used;

extern int sqlparse_yydebug;
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
char *dialect;
char *default_database;
int pcnt=0;

	if (argc<2) {
		printf("Usage : %s filename [dbname]\n",argv[0]);
		exit(2);
	}
	A4GL_init_gen_stack();
	if (A4GL_isyes(acl_getenv("DOING_CM")) ) {
  		A4GL_setenv ("EXPAND_COLUMNS", "Y", 1);
  		A4GL_setenv ("FULL_INSERT", "Y", 1);
	}

	dialect=acl_getenv_not_set_as_0("A4GL_TARGETDIALECT");
	load_temp_table();
	if (dialect==0) dialect="POSTGRES";
	if (A4GL_isyes(acl_getenv("YYDEBUG"))) {
		printf("YYDEBUG\n");
		sqlparse_yydebug=1;
	}

	if (argc==3) {
		default_database=acl_getenv_not_set_as_0("DEFAULT_DATABASE");
		if (default_database==0) {
			default_database=argv[2];
		}
	        A4GLSQL_set_status (0, 1);
  		A4GLSQL_init_connection (default_database);
  		if (A4GLSQL_get_status () != 0) {
			printf("Couldn't connect to database\n");
			exit(1);
    		}
		//printf("Opened database : %s\n",default_database);
		db_used=1;

	}

	
	snew=A4GLSQLCV_convert_file(dialect,argv[1]);
	if (snew==0) {
		fprintf(stderr,"Fatal error...\n");
		exit(2);
	}
	if (strcmp(snew,"<err>")==0) { exit(1); }
	
	snew=A4GLSQLCV_check_sql(snew); 
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

/*

char *A4GL_strcpy  (char *d,char *s,char *fname,int l,int sdest) {
		strcpy(s,d);
}
char *A4GL_strcat  (char *d,char *s,char *fname,int l,int sdest) {
		strcat(s,d);
}



int A4GL_sprintf (char *f,int l, char *dest,size_t sdest,char *fmt, ...) {
char buff[256];
int x;
char *c;
va_list args;
char xbuff[10000];


              va_start (args, fmt);
              x=vsprintf(xbuff,fmt,args);
              strcpy(dest,xbuff);
        return x;
}
*/

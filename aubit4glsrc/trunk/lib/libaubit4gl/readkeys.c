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
# $Id: readkeys.c,v 1.2 2003-06-18 11:07:22 mikeaubury Exp $
#*/

/**
 * @file
 * This file can be used for batch processing a series of
 * keystrokes (mainly intended for testing purposes)
 *
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_libaubit4gl_int.h"

int have_keyfile=-1;
FILE *keyfile;
static void open_keyfile(void) ;

long key_delay=100000;


static void open_keyfile(void) {
	char *fname;
	char *delay;
	have_keyfile=0;

	fname=acl_getenv("KEYFILE");
	if (fname==0) return;
	if (strlen(fname)==0) return ;
	keyfile=(FILE *) A4GL_open_file_dbpath (fname);

	if (keyfile==0) {
		A4GL_set_errm(fname);
		A4GL_exitwith("Unable to open key file");
		A4GL_chk_err (0,"Unknown");
		return;
	}

	have_keyfile=1;
	delay=acl_getenv("KEYDELAY");
	if (delay) {
		key_delay=atol(delay);
	}
}


int A4GL_readkey(void) {
	int a;
	char buff[256];

	if (have_keyfile==-1) {
		open_keyfile();
	}

	if (!have_keyfile) return 0;

	a=0;
	while (a==0) {
		a=fgetc(keyfile);
		if (feof(keyfile)) {

				if(A4GL_isyes(acl_getenv("NEEDALLKEYS"))) {
					A4GL_set_errm(""); 
					A4GL_exitwith("Ran out of keys");
					A4GL_chk_err (0,"Unknown"); 
				}
				have_keyfile=0;
				return 0; 
				}
		if (a=='\r') a=0;
		if (a=='\t') a=0;
		if (a=='\n') a=0;
	}

	if (a=='\\') {
		int cnt=0;
		A4GL_debug("Getting keyval");
		while (1) {
			buff[cnt]=fgetc(keyfile);
			if (buff[cnt]==';'||buff[cnt]=='\n'||buff[cnt]=='\r'||buff[cnt]==' '|| buff[cnt]==','||buff[cnt]=='\\'||feof(keyfile)) {
				buff[cnt]=0;
				break;
			}
			cnt++;
			buff[cnt]=0;
		}
		A4GL_debug("Getting keyval - %s",buff);
		a=A4GL_key_val(buff);
		if (a==-1) {
			A4GL_set_errm(buff);
			A4GL_exitwith("Unknown Key");
			A4GL_chk_err (0,"Unknown");
			return 0;
		}
			
	}
	usleep(key_delay);
	return a;
}

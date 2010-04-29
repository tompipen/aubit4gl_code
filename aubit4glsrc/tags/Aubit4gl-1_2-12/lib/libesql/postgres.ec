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
# $Id: postgres.ec,v 1.2 2009-05-11 15:30:06 mikeaubury Exp $
#
*/

/*

WARNING !!!! Informix esqlc compiler on Windows DOES NOT ACCEPT C++ stype commnets
				( "//" ) in EXEC SQL - please do not use them in this file 

*/


/**
 * @file
 *
 *
 */


#include "a4gl_libaubit4gl.h"
#include "a4gl_esql.h"
#include "a4gl_API_esql_lib.h"

void ESQLAPI_A4GL_afterexec_possible_serial(void) {
	/* Get last serial number generated ??? */
		EXEC SQL BEGIN DECLARE SECTION;
		int last_ser;
		EXEC SQL END DECLARE SECTION;

		//$whenever sqlerror stop;
		EXEC SQL SELECT lastval() INTO :last_ser;
		A4GL_set_a4gl_sqlca_errd(1,last_ser);
}

void ensure_nextval(void ) {
	EXEC SQL CREATE TEMPORARY SEQUENCE aubit4glblah_seq;
	EXEC SQL select nextval('aubit4glblah_seq');
}

/* ============================================ EOF ========================================= */


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
# $Id: a4gl_incl_4gldef.h,v 1.9 2002-08-19 07:58:18 afalout Exp $
*/

/**
 * @file
 *
 * Definition of structures and typedefs necessary in both lib and generated
 * C code.
 *
 * Header file used to include in the generated c files with origin
 * in the 4gl source files.
 *
 * This file is included from:
 * a4gl_incl_4glhdr.h (included by 4glc compiled 4gl code)
 * and
 * a4gl_libaubit4gl.h (included from the most of Aubit compiler and libraries code)
 *
 */

#ifndef FGLDEF_INCL
#define FGLDEF_INCL

	/**
	 * Binding information structure definition.
	 * Used to bind values to and from SQL.
	 * Need to be here because a4gl_API_sql.h needs it
	 */
	struct BINDING {
		void *ptr; /**< A pointer to the variable bounded */
		int dtype; /**< The data type of the variable bounded */
		long size; /**< The size in bytes of the variable bounded */
	};


	/** SQLCA structure definition */
	typedef struct {
		int sqlcode;
		char sqlerrm[73];
		char sqlerrp[9];
		int sqlerrd[6];
		char sqlawarn[9];
		char sqlstate[10];
	} sqlca_struct;

	/**
	 * Decimal 4gl data type variable definition
	 */
	typedef struct  {
		char data[64]; /**< The value stored in decimal variable */
	} fgldecimal;

	/** This type name is just to have some pattern in type names */
	typedef fgldecimal FglDecimal;

	typedef fgldecimal FglMoney;

	/**
	 * Money 4gl data type variable definition
	 */
	typedef struct  {
		char data[64]; /**< The value stored in money variable */
	} fglmoney;


	#define fglbyte struct fgl_int_loc

	/** 4gl Byte data type */
	typedef struct fgl_int_loc FglByte;

	#define fgltext struct fgl_int_loc

	/** 4gl Text data type */
	typedef struct fgl_int_loc FglText;

	/** Date data type */
	typedef long FglDate;

	/**
	 * Datetime value variable type.
	 *
	 * The name was chaged due to imcompatibility with esql/c
	 * 
	 * The values in qualifiers are :
	 *   - 1 : YEAR
	 *   - 2 : MONTH
	 *   - 3 : DAY
	 *   - 4 : HOUR
	 *   - 5 : MINUTE
	 *   - 6 : SECOND
	 *   - > 6 FRACTION + precision of fraction (2 by default)
	 */
	struct A4GLSQL_dtime {
	    int stime;     /**< The start qualifier */
	    int ltime;     /**< The end qualifier */
	    char data[32]; /**< The information in the var */
	};

	/** Date time defined without typedef. To be deprecated */
	#define struct_dtime struct A4GLSQL_dtime

	/** 4gl Interval data type definition */
	typedef struct A4GLSQL_dtime FglDatetime;

	/**
	 * Interval variable data type.
	 */

	struct ival {
	    int stime;     /**< The start qualifier */
	    int ltime;     /**< The end qualifier */
	    char data[32]; /**< The value of the interval variable */
	};

	#define struct_ival struct ival

	/** 4gl Datetime data type definition */
	typedef struct ival FglInterval;


#endif /* #ifndef FGLDEF_INCL */

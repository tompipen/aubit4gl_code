/*
 * +----------------------------------------------------------------------+
 * | Aubit 4gl Language Compiler Version $.0                              |
 * +----------------------------------------------------------------------+
 * | Copyright (c) 2000-4 Aubit Development Team (See Credits file)       |
 * +----------------------------------------------------------------------+
 * | This program is free software; you can redistribute it and/or modify |
 * | it under the terms of one of the following licenses:                 |
 * |                                                                      |
 * |  A) the GNU General Public License as published by the Free Software |
 * |     Foundation; either version 2 of the License, or (at your option) |
 * |     any later version.                                               |
 * |                                                                      |
 * |  B) the Aubit License as published by the Aubit Development Team and |
 * |     included in the distribution in the file: LICENSE                |
 * |                                                                      |
 * | This program is distributed in the hope that it will be useful,      |
 * | but WITHOUT ANY WARRANTY; without even the implied warranty of       |
 * | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        |
 * | GNU General Public License for more details.                         |
 * |                                                                      |
 * | You should have received a copy of both licenses referred to here.   |
 * | If you did not, or have any questions about Aubit licensing, please  |
 * | contact licences@aubit4gl.org
 * +----------------------------------------------------------------------+
 *
 * $Id: decimal.h,v 1.1 2004-05-11 14:02:13 saferreira Exp $
 */

/**
 * @file
 * Header file to define data types and macros to allow legacy c source files
 * to work without any change in an Informix 4gl to aubit 4gl porting.
 */

#ifndef _DECIMAL_H
#define _DECIMAL_H

#ifdef __cplusplus
extern "C"
{
#endif


/** Define the informix decimal type as the aubit4gl type */
typedef FglDecimal dec_t;

/** Convert a C char type do decimal type */
#define 


#ifdef __cplusplus
}
#endif

#endif

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
# $Id: a4gl_4gl_callable.h,v 1.1 2003-07-26 11:12:37 mikeaubury Exp $
*/

/**
 * @file
 * Header file used to include in the generated c files with origin
 * in the 4gl source files.
 *
 * This file is NOT included from anywhere else - compile_c.c prints
 * include statemennt for this file when outputing C code that is result
 * of compiling 4gl code by 4glc
 *
 * Therefore, this file contains definitions and prototypes that are
 * needed ONLY when compiling/running compiled programs, and NOT anywhere else in
 * Aubit compiler or libraries code.
 *
 */

#ifndef FGLINCLDEF_INCL
#define FGLINCLDEF_INCL

#ifdef __cplusplus
extern "C"
{
#endif

#include "a4gl_API_esql.h"
#include "a4gl_API_exdata.h"
#include "a4gl_API_exreport.h"
#include "a4gl_API_form.h"
#include "a4gl_API_help.h"
#include "a4gl_API_lex.h"
#include "a4gl_API_menu.h"
#include "a4gl_API_msg.h"
#include "a4gl_API_packer.h"
#include "a4gl_API_rpc.h"
#include "a4gl_API_sql.h"
#include "a4gl_API_ui.h"

#ifdef __cplusplus
}
#endif
#endif				/* #ifndef FGLHDR_INCL */

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
# $Id: std_funcs.c,v 1.5 2003-05-12 14:24:01 mikeaubury Exp $
#
*/


/**
 * @file
 * Array contatining list of all built in functions
 *
 * @todo Describe purpose and ussage
 * @todo Should this be a .h file? Maybe just a part of a4gl_incl_4gldefs.h ?
 */

 /*
    =====================================================================
    Variables definitions
    =====================================================================
  */


char *builtin_aclfgl_functions[] = {
  "a4gl_dump_screen",
  "a4gl_get_info",
  "a4gl_show_help",
  "abs",
  "arg_val",
  "arr_count",
  "arr_curr",
  "ascii",
  "date",
  "day",
  "dbms_dialect",
  "downshift",
  "err_get",
  "err_print",
  "err_quit",
  "fgl_drawbox",
  "fgl_getenv",
  "fgl_keyval",
  "fgl_lastkey",
  "fgl_prtscr",
  "a4gl_get_page",
  "a4gl_get_ui_mode",
  "hex",
  "i_rowid_s",
  "startlog",
  "errorlog",
  "length",
  "a4gl_load_datatype",
  "m_rowid_s",
  "mdy",
  "month",
  "num_args",
  "r_rowid_s",
  "root",
  "a4gl_run_gui",
  "s_rowid_s",
  "scr_line",
  "set_count",
  "set_page",
  "set_window_title",
  "showhelp",
  "sqrt",
  "upshift",
  "w_rowid_s",
  "weekday",
  "year",
  0
};


/* ================================= EOF ============================== */

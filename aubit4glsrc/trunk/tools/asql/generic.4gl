

# +----------------------------------------------------------------------+
# | Aubit SQL Acess Program ASQL                                         |
# +----------------------------------------------------------------------+
# | Copyright (c) 2003 Aubit Computing Ltd                               |
# +----------------------------------------------------------------------+
# | Production of this software was sponsored by                         |
# |                 Cassens Transport Company                            |
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



code

FILE *unloadFile=0;

int firstFetchInit=0;
int need_cursor_free=0;
#include "simple.h"
endcode



function check_db(dbname)
define dbname char(255)
return dbname
end function

function connection_connect()
error "Not Implemented connection_connect"
end function

FUNCTION do_paginate()
define rpaginate integer
MESSAGE ""
code
   while (1) {
        extern int outlines;

             if (outlines<=0) break;
             aclfgl_paginate(0);
             rpaginate=A4GL_pop_int();
             if (rpaginate!=0) break;
   }
endcode

END FUNCTION



function drop_db()
	error "Not implemented drop_db"
end function

function qry_translate()
	error "Not Implemented qry_translate"
end function

function get_db_err_msg(lv_code)
define lv_code integer
define lv_err1 char(255)
define lv_err2 char(255)
code
A4GLSQL_get_errmsg(lv_code);
A4GL_trim(lv_err2);
endcode
return lv_err2
end function


function load_info_columns()
error "Not Implemented Yet load_info_columns"
end function

function load_info_indexes()
error "Not Implemented Yet load_info_indexes"
end function

function load_info_priv()
error "Not Implemented Yet load_info_priv"
end function

function load_info_status()
error "Not Implemented Yet load_info_status"
end function

function load_info_tables()
error "Not Implemented Yet load_info_tables"
end function

function table_info()
error "Not Implemented Yet table_info"
end function

function table_select()
error "Not Implemented Yet table_select"
end function


function select_db()
define lv_arr array[100] of char(100);
define lv_num_dbs integer
define lv_cnt integer
define lv_curr_db char(255)
define lv_name char(255)
define lv_newname char(255)
define a integer
let lv_curr_db=get_db();

code
lv_num_dbs=A4GLSQL_fill_array(100,lv_arr,100,0,0,"DATABASES",0,0);
endcode
for a=1 to lv_num_dbs
	call set_pick(a,lv_arr[a])
end for
call set_pick_cnt(lv_num_dbs)

let lv_newname=prompt_pick("SELECT DATABASE >>","")
if lv_newname is null then
        let lv_newname=lv_curr_db
end if

if lv_newname is not null and lv_newname not matches " " then
        whenever error continue

        close database
        database lv_newname
        whenever error stop

        if sqlca.sqlcode=0 then
                call set_curr_db(lv_newname)
                call display_banner()
                message "Database Opened"
        else
                if check_and_report_error() then
                        return
                end if
        end if
end if
end function




function sql_select_db(lv_dbname)
define lv_dbname char(64)
database lv_dbname
end function





code
asql_explain(struct element *e) {
// Not implemented - use set explain on/set explain off instead...
}


int asql_load_data(struct element *e) {
}



int prepare_query_1(char *s,char type) {
static int prepared;
char *p;
int qry_type;
p=s;

   if (strncasecmp(s,"database",8)==0) { return 1; }
   if (type>='1'&&type<='9') return 255;
   qry_type=0;
   if (type!='S'&&type!='s') qry_type=255;

	//A4GL_push_char(s);
	//aclfgl_prepareit(1);
   //P0REPARE stExec from :p;
	A4GL_trim(p);
   A4GLSQL_add_prepare("generic_stexec",(void *)A4GLSQL_prepare_select(0,0,0,0,s));
   cp_sqlca();


   if (a4gl_sqlca.sqlcode>=0) prepared=1;
   else prepared=0;


   if (type=='S') qry_type=0;
   if (type=='s') qry_type=0;

   if (type=='u') qry_type=4;
   if (type=='d') qry_type=5;
   if (type=='I') qry_type=6;

   if (type=='U') qry_type=33;
   if (type=='D') qry_type=32;

   if (type=='T') qry_type=3;
   if (type=='t') qry_type=3;

   if (prepared) return qry_type;
   return -1;
}


int execute_query_1(int *raffected) {
                *raffected=0;
		A4GLSQL_execute_sql("m1_stexec",0,0);
		if (a4gl_sqlca.sqlcode!=0)  return 0;
                *raffected=a4gl_sqlca.sqlerrd[0];
        	return 1;
}


execute_select_free() {
	aclfgl_execute_select_free(0);
	if (a4gl_sqlca.sqlcode<0) return 0;
	return 1;
}


get_sqlcode() {
	return a4gl_sqlca.sqlcode;
}

set_sqlcode(int a) {
	a4gl_sqlca.sqlcode=a;
}




int execute_select_prepare() {
static int done_alloc=0;
open_display_file_c();
if (need_cursor_free) {
    execute_select_free();
}


A4GLSQL_declare_cursor(0+0,A4GLSQL_find_prepare("stExec"),0,"crExec");
cp_sqlca();
      if (a4gl_sqlca.sqlcode<0) {A4GL_debug("Err3"); return 0;}

      need_cursor_free=1;
   	A4GLSQL_open_cursor("crExec",0,0);
        if (a4gl_sqlca.sqlcode<0) {A4GL_debug("Err3"); return 0;}
        need_cursor_free=3;

        firstFetchInit=1;
return 1;
}



execute_sql_fetch() {
	aclfgl_sql_fetch(0);
}

cp_sqlca() {
// Do nothing - 'cos we don't need too...
}

endcode


function sql_fetch()
let sqlca.sqlcode=100;
end function

function execute_select_free()
          CLOSE crExec
          FREE stExec;
          FREE crExec; 
end function

function prepareit(p)
define p char(20000)
   PREPARE stExec from p
end function


function set_current_db(lv_name)
define lv_name char(200)
return lv_name
end function


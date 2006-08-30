# +----------------------------------------------------------------------+
# | Aubit SQL Access Program ASQL                                        |
# +----------------------------------------------------------------------+
# | Copyright (c) 2003-5 Aubit Computing Ltd                             |
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
#include "simple.h"
char **read_directory(char *dir,char *spec);
endcode

################################################################################
function query_menu()
define lv_action integer
define lv_runnext integer
define lv_option char(20)
	call init_filename()


let lv_runnext=0
	
	if not has_db() then
		call select_db()
	end if
	if not has_db() then
		error "No database selected"
		#return
	end if

while true
	set pause mode off

	if lv_runnext then
		let lv_action=1
	end if

	if fgl_getenv("SQLCNVPATH") is null or fgl_getenv("SQLCNVPATH") = " " then
		let lv_option= query_menu_int(lv_action)
	else
		let lv_option= query_menu_translate_int(lv_action)
	end if
			

	let lv_runnext=0
	case lv_option

		when "New" 		let lv_action=0 
			if qry_new() then
				let lv_runnext=1
			end if
			call display_tmp_file()

		when "Run" 		let lv_action=1 
			Call set_exec_mode(0)
			call open_tmpfile("SQL","r")
			call qry_run()
			let lv_runnext=1

		when "Modify" 		let lv_action=2 
			if qry_modify("MODIFY") then
				let lv_runnext=1
			end if
			call display_tmp_file()

		when "Use-editor" 	let lv_action=3
			if qry_edit() then
				let lv_runnext=1
			end if

		when "Output" 		let lv_action=4
			Call set_exec_mode(2)
			if not qry_output() then
				error "Some SQL error"
			end if
			Call set_exec_mode(0)
			call display_tmp_file()

		when "Choose" 		let lv_action=5
			if qry_choose() then
				let lv_runnext=1
			end if
			call display_tmp_file()

		when "Save" 		let lv_action=6
			call qry_save()
			call display_tmp_file()

		when "Info" 		let lv_action=7
			call qry_info()

		when "Drop" 		let lv_action=8
			call qry_drop()
			call display_tmp_file()

		when "Translate" 	let lv_action=9
			call qry_translate()
			call display_tmp_file()

		when "Exit" 		let lv_action=10
			exit while
		otherwise
			error "Unexpected menu code:",lv_option
	end case

end while

	call clear_screen_portion()
end function




################################################################################
function qry_new()
	# Clear down our temporary file
	call open_tmpfile("SQL","w")
	call close_tmpfile("SQL")
	return qry_modify("NEW")
end function





################################################################################
function qry_run()
define a integer
code
{
extern FILE *asql_yyin;
extern struct element *list;
extern int list_cnt;


asql_yyin=(FILE *)get_curr_mvfin("SQL");
clr_stmt();
a=my_pretend_yyparse();
a=list_cnt;
}
endcode

if get_exec_mode()=0 then
	if a>0 then
		message a using "<<<<"," statements to execute"
	else
		message "No statements to execute"
	end if
end if

if a then
	if not execute_queries(0) then
		if get_exec_mode()=0 then
			#error "Error Executing.."
			#
		end if
	end if
end if

end function


################################################################################
function qry_edit()
define lv_systemstr char(255)
define lv_stat integer

let lv_systemstr=fgl_getenv("DBEDIT")
if lv_systemstr is null or lv_systemstr is null matches " " then
	let lv_systemstr="vi"
end if

let lv_systemstr=lv_systemstr clipped," ", get_tmp_fname("SQL")

run lv_systemstr returning lv_stat

call display_tmp_file()

return 1
end function


################################################################################
function qry_output()
define lv_query_out integer
define lv_name char(256)
define lv_fmode char(1)
define lv_amode char(1)
define a integer


MENU "OUTPUT" 
		command "Printer" "Send query output to printer"
			LET lv_query_out=1 exit menu
		command "New-File" "Send query output to new file"
			LET lv_query_out=2 exit menu
		command "Append-File" "Append query output to an existing file"
			LET lv_query_out=3 exit menu
		command "To-pipe" "Send output to the input of a program"
			LET lv_query_out=4 exit menu
		command "Exit" "Return to the SQL menu"
			LET lv_query_out=0 exit menu
end menu
if lv_query_out=0 then 
	return 1
end if

call set_pick_cnt(0)
let lv_name="NONE"

case lv_query_out
	when 2 call prompt_pick("OUTPUT NEW-FILE >>","") returning lv_name
	when 3 call prompt_pick("OUTPUT APPEND-FILE >>","") returning lv_name
	when 4 call prompt_pick("OUTPUT PIPE >>","") returning lv_name
end case

if lv_name is null or lv_name matches " " THEN
	error "Output aborted"
	return 1
end if
IF lv_query_out=1 THEN
        let lv_query_out=4
        let lv_name=fgl_getenv("DBPRINT")

        if lv_name is null or lv_name = " " then
                let lv_name="lp "
        end if
end if

case lv_query_out
        when 1 # Printer
                error "Shouldn't happen"  return

        when 2 # New file
                let lv_fmode="f"
                let lv_amode="w"

        when 3 # Append File
                let lv_fmode="f"
                let lv_amode="a"
        when 4  # To-Pipe
                let lv_fmode="p"
                let lv_amode="w"
end case

call open_tmpfile("SQL","r")
code
{
extern FILE *asql_yyin;
extern struct element *list;
extern int list_cnt;
asql_yyin=(FILE *)get_curr_mvfin("SQL");
clr_stmt();
a=my_pretend_yyparse();
a=list_cnt;
}
endcode



return execute_output(lv_name,lv_fmode,lv_amode)
	
end function


################################################################################
function qry_choose()
define lv_fname char(255)
define a integer

display "Choose a file to load","" at 2,1
let a=0
code
{
	char **dir;
	dir=read_directory(".",".sql");
        if (dir) {
		for (a=0;dir[a];a++) {
			A4GL_debug("READ FILE: %s",dir[a]);
			strcpy(lv_fname,dir[a]);
endcode
			call set_pick(a+1,lv_fname);
code
		}
		free_directory(dir);
	}
}
endcode

call set_pick_cnt(a);

call prompt_pick("CHOOSE >> ","") returning lv_fname
if lv_fname is not null then
	let lv_fname=lv_fname clipped,".sql"
	error "Filename : ",lv_fname
	call copy_file(lv_fname,get_tmp_fname("SQL"),".sql",1)
	call display_tmp_file()
	return 1
end if
return 0

end function


################################################################################
function execute_file(lv_fname)
define lv_fname char(255)
	call init_filename()
	call set_exec_mode(1)

	if lv_fname!="-" then
		call copy_file(lv_fname,get_tmp_fname("SQL"),".sql",1)
		call open_tmpfile("SQL","r")
	else
		call open_tmpfile_as_stdin("SQL")
	end if
	call qry_run()
end function

################################################################################
function qry_save()
define lv_fname char(255)
call set_pick_cnt(0)
call prompt_pick("SAVE >> ","") returning lv_fname
if lv_fname not matches "*.sql" then
	let lv_fname=lv_fname clipped,".sql"
end if

if lv_fname != " " then
	call copy_file(get_tmp_fname("SQL"),lv_fname,".sql",0)
end if
end function

################################################################################
function qry_info()
 	call table_info()
end function

################################################################################
function qry_drop()
define lv_fname char(255)
define a integer

display "Choose a file to drop","" at 2,1

code
{
	char **dir;
	dir=read_directory(".",".sql");
        if (dir) {
		for (a=0;dir[a];a++) {
			strcpy(lv_fname,dir[a]);
endcode
			call set_pick(a+1,lv_fname);
code
		}
		free_directory(dir);
	}
}
endcode

call set_pick_cnt(a);

call prompt_pick("DROP >> ","") returning lv_fname


if lv_fname is not null then
	let lv_fname=lv_fname clipped,".sql"
MENU "CONFIRM" 
	command "No" "No - I don't want to drop it"
		exit menu
	command "Yes" "Yes - I do want to drop it"
	
code
	A4GL_trim(lv_fname);
	unlink(lv_fname);
endcode
	exit menu
end menu
end if

end function







################################################################################
function qry_modify(p_modify)
define p_modify char(6)

	set pause mode off
	call clear_screen_portion()
	let int_flag=false
	if not edit_load_file() then
		call edit(p_modify)
	else
		error "Internal Error..."
	end if
	call display_banner()
	call display_tmp_file()

	
	if int_flag=true then
		return 0
	else
		return 1
	end if

end function


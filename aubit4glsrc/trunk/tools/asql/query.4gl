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
#include "simple.h"
char **read_directory(char *dir,char *spec);
endcode

################################################################################
function query_menu()
define lv_action integer
define lv_runnext integer
	call init_filename()


let lv_runnext=0
	
	if not has_db() then
		call select_db()
	end if

while true
	set pause mode off

	menu "SQL"
		before menu 
			if lv_runnext then
				next option "Run"
			end if

		command "New" "Type in new SQL commands"
			let lv_action=1 exit menu

		command "Run" "Run the SQL commands"
			let lv_action=2 exit menu


		command "Modify" "Modify the SQL commands"
			let lv_action=3 exit menu


		command "Use-editor" "Use the editor to modify SQL"
			let lv_action=4 exit menu


		command "Output" "Output the results of the SQL"
			let lv_action=5 exit menu



		command "Choose" "Choose an SQL file"
			let lv_action=6 exit menu



		command "Save" "Save an SQL file"
			let lv_action=7 exit menu


		command "Info" "Info for tables"
			let lv_action=8 exit menu



		command "Drop" "Drop an SQL file"
			let lv_action=9  exit menu


		command "Exit" "Return to ADBACCESS menu" 
			let lv_action=10
			exit menu
	end menu


	let lv_runnext=0
	case lv_action
		when 1
			if qry_new() then
				let lv_runnext=1
			end if
			call display_tmp_file()
	
		when 2
			Call set_exec_mode(0)
			call open_tmpfile("r")
			call qry_run()
			let lv_runnext=1

		when 3
			if qry_modify("MODIFY") then
				let lv_runnext=1
			end if
			call display_tmp_file()
		when 4
			if qry_edit() then
				let lv_runnext=1
			end if

		when 5
			Call set_exec_mode(2)
			if not qry_output() then
				error "Some SQL error"
			end if
			Call set_exec_mode(0)
			call display_tmp_file()

		when 6
			if qry_choose() then
				let lv_runnext=1
			end if
			call display_tmp_file()

		when 7
			call qry_save()
			call display_tmp_file()

		when 8
			call qry_info()
	
		when 9
			call qry_drop()
			call display_tmp_file()

		when 10 exit while
	end case
end while

	call clear_screen_portion()
end function




################################################################################
function qry_new()
	# Clear down our temporary file
	call open_tmpfile("w")
	call close_tmpfile()
	return qry_modify("NEW")
end function





################################################################################
function qry_run()
define a integer
code
{
extern FILE *yyin;
extern struct element *list;
extern int list_cnt;


yyin=(FILE *)get_curr_mvfin();
clr_stmt();
a=yyparse();
a=list_cnt;
}
endcode

if get_exec_mode()=0 then
message a using "<<<<"," statements to execute"
end if


if not execute_queries(0) then
	if get_exec_mode()=0 then
		#error "Error Executing.."
		#
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
let lv_systemstr=lv_systemstr clipped," ", get_tmp_fname()
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


menu "OUTPUT" 
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
	return
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
	return
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

call open_tmpfile("r")
code
{
extern FILE *yyin;
extern struct element *list;
extern int list_cnt;
yyin=(FILE *)get_curr_mvfin();
clr_stmt();
a=yyparse();
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
	call copy_file(lv_fname,get_tmp_fname())
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
		call copy_file(lv_fname,get_tmp_fname())
		call open_tmpfile("r")
	else
		call open_tmpfile_as_stdin()
	end if
	sleep 1
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
	call copy_file(get_tmp_fname(),lv_fname)
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
menu "CONFIRM" 
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


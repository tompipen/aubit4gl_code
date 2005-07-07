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
define mv_username,mv_passwd char(255)


function database_menu()
menu "DATABASE"
	command "Select" "Select a database to work with."
		call select_db() 

	command "Create"  "Create a new database."
		call create_db()

	command "Info"  "Retrieve information about a database."
		error "Not Implemented - Info"

	command "Drop"  "Drop a database."
		call drop_db()

	command "cLose"  "Close the current database."
		call do_disconnect()

	command "Exit" "Return to the ADBACCESS menu."
		exit menu
end menu
end function


function create_db()
define lv_dbname char(255)
define lv_dbspace char(255)
define lv_log char(255)
let int_flag=false

prompt "CREATE DATABASE >>" for lv_dbname

if int_flag=true then
	return
end if

let lv_dbspace=""
let lv_log=""

menu "CREATE DATABASE"
	command "Dbspace" "Select a dbspace for storing the databases's data."
		let lv_dbspace=get_dbspace()

	command "Log" "Specify the type of transaction logging."
		let lv_log=get_log()

	command "Exit" "Return to the Database Menu."
		exit menu
end menu


menu "EXIT"
	command "Create-new-database" "Create-new-database"
		call do_create_db(lv_dbname,lv_dbspace,lv_log)
		exit menu
	
	command "Discard-new-database" "Discard-new-database"
		exit menu
end menu
end function



function get_dbspace()
return ""
end function



function get_log()
menu "LOG"
	command "None"
		return ""
	command "Log"
		return "WITH LOG"
	command "Buffered_log"
		return "WITH BUFFERED LOG"
	command "log_Mode_ansi"
		return "LOG MODE ANSI"
end menu
end function



# lv_log
#     WITH LOG
#     WITH BUFFERED LOG
#     LOG MODE ANSI
function do_create_db(lv_dbname,lv_dbspace,lv_log)
define lv_dbname,lv_dbspace,lv_log char(255)
define lv_str char(255)
let lv_str="CREATE DATABASE ",lv_dbname

if lv_dbspace is not null and lv_dbspace != " " then
	let lv_str=lv_str clipped," IN ",lv_dbspace
end if
if lv_log is not null and lv_log not matches " " then	
	let lv_str=lv_str clipped," ",lv_log
end if

display "--->",lv_str clipped at 10,1

# @ todo - set current database...

end function





function set_username(p_username,p_passwd)
define p_username,p_passwd char(255)
let mv_username=p_username
let mv_passwd=p_passwd
end function

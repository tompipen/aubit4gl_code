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

define mc_version constant "0.32"

define mv_curr_db char(256)
define lv_args array[100] of char(100)
define lv_args_cnt integer
define lv_input char(255)
define lv_quiet integer
define lv_echo integer

function is_echo()
	return lv_echo
end function

code
is_echo_c() {
return lv_echo;
}
endcode

main
define lv_a integer
define lv_cnt integer
define lv_dummy char(255)
initialize mv_curr_db to null
call edit_init()


# if you don't want to see the banner
# ever then set this to 1
let lv_quiet=0


let lv_echo=0

defer interrupt
defer quit
code
A4GL_setenv("A4GL_AUTOBANG","Y",1);
endcode

let lv_cnt=1
if num_args() then
	for lv_a=1 to num_args()
		
		if arg_val(lv_a)="-d" then
			let lv_a=lv_a+1
			let mv_curr_db=arg_val(lv_a)
			call open_db()
			continue for
		end if

		if arg_val(lv_a)="-q" then
			call  get_version() returning lv_dummy
			let lv_quiet=1
			continue for
		end if

		if arg_val(lv_a)="-e" then
			let lv_echo=1
			continue for
		end if

		if arg_val(lv_a)="-v" or arg_val(lv_a)="-V" then
			display "(c) 2003 Aubit Computing Ltd"
			display get_version()
			exit program
		end if

		let lv_args[lv_cnt]=arg_val(lv_a)
		let lv_cnt=lv_cnt+1
	end for

	let lv_args_cnt=lv_cnt-1
end if



if lv_args_cnt then
	let mv_curr_db=get_next_arg()
	call open_db()
end if


if lv_args_cnt then
	let lv_input=get_next_arg()
	call execute_file(lv_input)
	exit program
end if

code
if (!isatty(fileno(stdin))) {
endcode
	#display "ASSUME STDIN"
	call  execute_file("-")
	exit program
code
}
endcode

options message line last


if not lv_quiet then
	call copyright_banner()
end if

call main_menu()

call remove_tmpfile("ALL")
end main


function open_db()
	define lv_db char(255)
	whenever error continue
	call check_db(mv_curr_db) returning lv_db
	database mv_curr_db

	if sqlca.sqlcode<0 then
		error "Unable to connect to database ",mv_curr_db
	else
		call set_curr_db(lv_db)
	end if
end function

################################################################################
function set_curr_db(p_dbname) 
define p_dbname char(255)
if p_dbname is null or length(p_dbname)=0 then
	initialize mv_curr_db to null
else
	let p_dbname=check_db(p_dbname)
	let mv_curr_db=p_dbname
end if
end function

################################################################################
function has_db()
	if mv_curr_db is null then
		return 0
	else
		return 1
	end if
end function


function get_db()
	if mv_curr_db is null then
		return ""
	else
		return mv_curr_db
	end if
end function


################################################################################
function get_next_arg()
define lv_rval char(255)
if lv_args_cnt then
	let lv_rval=lv_args[1]
	call shift_args()
	return lv_rval
else
	initialize lv_rval to null
	return lv_rval
end if
end function

################################################################################
function shift_args()
define lv_a integer
for lv_a=1 to lv_args_cnt-1
	let lv_args[lv_a]=lv_args[lv_a+1]
end for
let lv_args_cnt=lv_args_cnt-1
end function


################################################################################
function display_banner()
display "------------------------------------------------ Press CTRL-W for Help --------" at 4,1
if mv_curr_db is not null then
	display " ",mv_curr_db clipped," " at 4,25
end if
end function


################################################################################
function check_and_report_error()
define lv_a integer
define lv_err1 char(255)
define lv_err2 char(255)


if sqlca.sqlcode>=0 then
	return 0
end if

let lv_err2=get_db_err_msg(sqlca.sqlcode)

if get_exec_mode()=0 then
	error lv_err2
	sleep 1 # After an error (check and report)
#else
	#display lv_err2
end if
return 1
end function




function clear_screen_portion()
define lv_y integer
define lv_maxy integer
code
lv_maxy=A4GL_get_curr_height();

endcode
set pause mode on
for lv_y=6 to lv_maxy
	display " ","" at lv_y,1
end for
set pause mode off
end function


function middle(s) 
define s char(255)
define s1 char(255)
define w integer
define a integer
code
w=A4GL_get_curr_width();
endcode
let a=w-length(s)
let a=a/2
let s1[a,255]=s
return s1
end function



function get_version() 
define lv_str char(80)
define lv_dialect char(80)
let lv_dialect="ODBC"
code
#ifdef DIALECT_INFORMIX
strcpy(lv_dialect,"INFX ESQL/C");
#endif

#ifdef DIALECT_POSTGRES
strcpy(lv_dialect,"POSTGRES");
aclfgl_set_translations(0);
#endif
endcode

let lv_str="ACL ASQL Version ",mc_version," ", lv_dialect clipped
return lv_str
end function

function copyright_banner()

clear screen
display middle(get_version()) at 7,1

display middle("(c) 2003 Aubit Computing Ltd") at 9,1
display middle("http://www.aubit.com") at 10,1
display middle("Latest version available at:") at 13,1
display middle("http://aubit4gl.sourceforge.net") at 14,1
display middle("Development sponsored by Cassens Transport Company") at 16,1
display middle("http://www.cassens.com") at 17,1
sleep 2 # Splash Screen 
clear screen
end function

function set_translations()
define a char(255)
define sqlcnvpath char(255)
let sqlcnvpath=fgl_getenv("SQLCNVPATH")
if sqlcnvpath is null or sqlcnvpath matches " " THEN
	let sqlcnvpath=fgl_getenv("AUBITDIR")
	let sqlcnvpath=sqlcnvpath clipped,"/etc/convertsql"
code
{
static char buff[256];

		A4GL_trim(sqlcnvpath);
		//sprintf(buff,"SQLCNVPATH=%s",sqlcnvpath);
		A4GL_setenv("SQLCNVPATH",sqlcnvpath,1);
}
endcode
end if
end function

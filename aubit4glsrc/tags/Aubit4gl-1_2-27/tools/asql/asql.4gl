# +----------------------------------------------------------------------+
# | Aubit SQL Access Program ASQL                                        |
# +----------------------------------------------------------------------+
# | Copyright (c) 2003-7 Aubit Computing Ltd                             |
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

define mc_version constant "0.50"

define mv_curr_db char(256)
define lv_args array[100] of char(100)
define lv_args_cnt integer
define lv_input char(255)
define lv_quiet integer
define lv_echo integer
{
define lv_actions  array[100] of record
		type char(1),
		details char(80)
end record
define lv_actions_cnt integer
define lv_actions_used integer
}
define first_init integer

function is_echo()
	return lv_echo
end function

code
is_echo_c() {
return lv_echo;
}

void bye(void) {
	clean_up_temp_files();
}
endcode

main
define lv_a integer
define lv_cnt integer
define lv_dummy char(255)
initialize mv_curr_db to null

#let lv_actions_cnt=0
#let lv_actions_used=0


#if fgl_getenv("A4GL_UI")="HL_GTK" or fgl_getenv("A4GL_UI")="XML" or fgl_getenv("A4GL_USE_FORMS")="Y" then
#	call set_use_form()
#else
#	call clr_use_form()
#end if

IF LENGTH(fgl_getenv("A4GL_ASQLERRLOG"))>0 THEN
	CALL startlog(fgl_getenv("A4GL_ASQLERRLOG"))
END IF

call form_is_compiled(splash,"MEMPACKED","GENERIC")
#call form_is_compiled(pick10,"MEMPACKED","GENERIC")
#call form_is_compiled(pick20,"MEMPACKED","GENERIC")
#call form_is_compiled(pick38,"MEMPACKED","GENERIC")
#call form_is_compiled(pick78,"MEMPACKED","GENERIC")

call edit_init()


# if you don't want to see the banner
# ever then set this to 1
let lv_quiet=0


let lv_echo=0

defer interrupt
defer quit
code
A4GL_setenv("A4GL_AUTOBANG","Y",1);
A4GL_setenv("HIDEEMPTYBUTTONS","Y",1);
atexit(bye);
endcode

initialize mv_curr_db to null
call open_db()

let lv_cnt=1
if num_args()>0 then
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
			call  get_version() returning lv_dummy
			let lv_quiet=1
			continue for
		end if
	
		if arg_val(lv_a)="-?" then
			display "asql [-d dbname ] [-q] [-e] [dbname] [scriptname]"
			exit program
		end if

		if arg_val(lv_a)="-v" or arg_val(lv_a)="-V" then
			display "(c) 2003-7 Aubit Computing Ltd"
			display get_version()
			exit program
		end if

		if arg_val(lv_a) matches "-*" and arg_val(lv_a)!="-" then
			if arg_need_next(lv_a) then
				exit for
			end if
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

	if was_all_ok() then
		exit program 0
	else
		exit program 1
	end if
end if

code
if (!isatty(fileno(stdin))) {
endcode
	#display "ASSUME STDIN"
	call  execute_file("-")
	if was_all_ok() then
		exit program 0
	else
		exit program 1
	end if
code
}
endcode

if lv_echo then
	#Just connect and exit...
	if mv_curr_db is not null then
		exit program 0
	end if
end if

options message line last


if upshift(fgl_getenv("ASQL_BANNER"))="N" THEN
	call  get_version() returning lv_dummy
	let lv_quiet=1
end if

if not lv_quiet then
	call copyright_banner()
end if

call main_menu()

call remove_tmp_files("ALL")
end main


function open_db()
	define lv_db char(255)
	define lv_exit integer
	whenever error continue
	if first_init is null or first_init=0 then
		call init_sql()
		let first_init=1
	end if
	if mv_curr_db is null then
		return
	end if
	call check_db(mv_curr_db) returning lv_db
	database mv_curr_db
	whenever error stop
	if sqlca.sqlcode<0 then

code
if (!isatty(fileno(stdin))) { lv_exit=1; }
if (!isatty(fileno(stdout))) { lv_exit=1; }
endcode
		if lv_exit or is_echo() then
			display "Unable to connect to database ",mv_curr_db
			exit program 2
		end if
		error "Unable to connect to database ",mv_curr_db

	else
		call set_curr_db(lv_db)
	end if
end function

################################################################################
function set_curr_db(p_dbname) 
define p_dbname char(255)

call set_current_db(p_dbname) returning p_dbname

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
{
function display_banner()
define lv_disp_in_trans integer

let lv_disp_in_trans= get_began_work() 

if NOT fgl_getenv("SHOWINWORK")="Y" THEN
	let lv_disp_in_trans=false
end if


if lv_disp_in_trans then
	call display_to_separator("************************************************ Press CTRL-W for Help ********")
else
	call display_to_separator("------------------------------------------------ Press CTRL-W for Help --------")
end if

end function
}


################################################################################
function check_and_report_error()
define lv_a integer
define lv_err1 char(255)
define lv_err2 char(255)
define lv_isam_err integer
code
lv_isam_err=get_isam_error();
endcode

if sqlca.sqlcode>=0 then
	return 0
end if

let lv_err2=get_db_err_msg(sqlca.sqlcode)

if get_exec_mode()=0 then
	if lv_isam_err<0 then
		error sqlca.sqlcode using "######",lv_isam_err using "######",": ",lv_err2 clipped
	else
		error sqlca.sqlcode using "######",": ",lv_err2 clipped
	end if
	sleep 1 # After an error (check and report)
end if
return 1
end function




function middle_in(s,w) 
define s char(255)
define s1 char(255)
define i integer
define w integer
define a integer
let a=w-length(s)
let a=a/2
let s1[a,255]=s
return s1
end function


function middle(s) 
define s char(255)
define w integer
code
w=A4GL_get_curr_width();
endcode
return middle_in(s,w)

end function



function get_version() 
define lv_str char(80)
define lv_dialect char(80)
let lv_dialect="GENERIC/ODBC"
code
#ifdef DIALECT_INFORMIX
strcpy(lv_dialect,"INFX ESQL/C");
#endif

#ifdef DIALECT_INFOFLEX
strcpy(lv_dialect,"INFOFLEX");
#endif

#ifdef DIALECT_POSTGRES
strcpy(lv_dialect,"POSTGRES");
aclfgl_set_translations(0);
#endif
endcode

let lv_str="ACL ASQL Version ",mc_version," ", lv_dialect clipped
return lv_str
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


{
function add_menu_actions(lv_s)
define lv_s char(80)
define a integer

for a=2 to length(lv_s)
	let lv_actions_cnt=lv_actions_cnt+1
	let lv_actions[lv_actions_cnt].type="M"
	let lv_actions[lv_actions_cnt].details=downshift(lv_s[a])
end for
end function


function show_actions()
define a integer
for a=1 to lv_actions_cnt
	if lv_actions[a].type="M" then
		display a," - mENU   : ", lv_actions[a].details
	elif lv_actions[a].type="P" then
		display a," - PROMPT : ", lv_actions[a].details
	else
		display a," - OTHER : ", lv_actions[a].details
	end if
end for
sleep 10
end function


function add_pick_actions(lv_s)
define lv_s char(80)
define a integer
let lv_actions_cnt=lv_actions_cnt+1
let lv_actions[lv_actions_cnt].type="P"
let lv_actions[lv_actions_cnt].details=lv_s
end function





function arg_need_next(lv_start)
define lv_a integer
define lv_start integer

for lv_a=lv_start to num_args()
	if arg_val(lv_a) matches "-*" then
		call add_menu_actions(arg_val(lv_a))
	else
		call add_pick_actions(arg_val(lv_a))
	end if
end for

let lv_actions_used=0

return 1

end function



function has_menu_action()
if lv_actions[lv_actions_used+1].type="M" then
	return true
else
	return false
end if
end function



function has_prompt_action()
if lv_actions[lv_actions_used+1].type="P" then
	return true
else
	return false
end if
end function


function clr_all_actions()
	
	error "Invalid command line option"
	sleep 1
end function


function get_menu_action()
if has_menu_action() then
	let lv_actions_used=lv_actions_used+1
	return lv_actions[lv_actions_used].details
else
	call clr_all_actions()
end if
return ""
end function



function has_any_action()
if has_prompt_action() or has_menu_action() then
	return true
else
	return false
end if
end function



function get_prompt_action()
if has_prompt_action() then
	let lv_actions_used=lv_actions_used+1
	return lv_actions[lv_actions_used].details
else
	if lv_actions_used<lv_actions_cnt then

		error "No prompt actions.." sleep 1
		call show_actions()
		sleep 2
	end if
	call clr_all_actions()
end if
return ""
end function
}


function niy()
error "Not implemented yet"
end function


















################################################################################
# Lets try to put things that 'display .. at' in one place...
################################################################################
{
function display_to_separator(lv_str)
define lv_str char(80)
define lv_db char(80)

if mv_curr_db is not null then
	let lv_db="_",mv_curr_db clipped,"_" # A string we can measure the length of
	let lv_str[25,25+length(lv_db)]= " ",mv_curr_db clipped," "
end if

display lv_str at 4,1
end function

}

################################################################################
{
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
}



function set_and_display_banner()
call set_pick_db(mv_curr_db)
call display_banner()
end function

################################################################################

function copyright_banner()
if get_use_form() then
	open window w_splash at 1,1 with form "splash"
	display middle_in(get_version(),60) to version
	sleep 2
	close window w_splash
else
	clear screen
	display middle(get_version()) at 7,1
	
	display middle("(c) 2003-8 Aubit Computing Ltd") at 9,1
	display middle("http://www.aubit.com") at 10,1
	display middle("Latest version available at:") at 13,1
	display middle("http://aubit4gl.sourceforge.net") at 14,1
	display middle("Development sponsored by Cassens Transport Company") at 16,1
	display middle("http://www.cassens.com") at 17,1
	sleep 2 # Splash Screen 
	clear screen
end if
end function

function display_to_line (lv_line,lv_str)
define lv_line integer
define lv_str char(512)
display lv_str clipped,"" at lv_line,1
end function





define mv_curr_db char(256)
define lv_args array[100] of char(100)
define lv_args_cnt integer
define lv_input char(255)

main
define lv_a integer
initialize mv_curr_db to null
defer interrupt
code
putenv("A4GL_AUTOBANG=Y");
endcode
if num_args() then
	for lv_a=1 to num_args()
		let lv_args[lv_a]=arg_val(lv_a)
	end for
	let lv_args_cnt=num_args()
end if



if lv_args_cnt then
	let mv_curr_db=get_next_arg()
	whenever error continue
	database mv_curr_db
	if sqlca.sqlcode<0 then
		error "Unable to connect to database ",mv_curr_db
	else
		call set_curr_db(mv_curr_db)
	end if
end if


if lv_args_cnt then
	let lv_input=get_next_arg()
	call execute_file(lv_input)
	exit program
end if
code
if (!isatty(fileno(stdin))) {
endcode
	call  execute_file("-")
	exit program
code
}
endcode

options message line last



call main_menu()

call remove_tmpfile()
end main



################################################################################
function set_curr_db(p_dbname) 
define p_dbname char(255)
if p_dbname is null or length(p_dbname=0) then
	initialize mv_curr_db to null
else
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
	sleep 1
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
	display "" at lv_y,1
end for
set pause mode off
end function

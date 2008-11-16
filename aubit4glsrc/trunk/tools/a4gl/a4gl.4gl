define mv_curr_db char(256)
define mc_version constant 0.8

main
defer interrupt


	#call generate_makefile("bibble","bibble.mk")
	#exit program
	call form_is_compiled(prog,"MEMPACKED","GENERIC")
	call form_is_compiled(entities,"MEMPACKED","GENERIC")
	call form_is_compiled(settings,"MEMPACKED","GENERIC")

	call copyright_banner()


	whenever error continue
	database syspgma4gl
	whenever error stop
	options message line last
	options input wrap

	if sqlca.sqlcode!=0 then
		whenever error continue
		execute immediate "create database syspgma4gl"
		database syspgma4gl
		whenever error stop
		if sqlca.sqlcode!=0 then
			display "Unable to create the syspgma4gl database"
			exit program 1
		end if
		call createtables()
	end if
		
	call main_menu()
end main


function createtables()
define lv_ok integer
	# try running our create script..
	run "adbaccess syspgma4gl $AUBITDIR/tools/a4gl/create_tables.sql" returning lv_ok
	if lv_ok>255 then
		let lv_ok=lv_ok/256
	end if
	if lv_ok!=0 then	
		display "Error creating tables"
		display "Please try to create them manually using $AUBITDIR/tools/a4gl/create_tables.sql"
		sleep 4
		exit program 1
	end if
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




function has_prompt_action()
return false
end function

function get_prompt_action()
return  ""
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



function check_and_report_error()
define lv_a integer
define lv_err1 char(255)
define lv_err2 char(255)
define lv_isam_err integer
if sqlca.sqlcode>=0 then
        return 0
end if
error "Unable to connect to database"
return 1
end function


function get_version()
define lv_str char(80)

let lv_str="ACL A4GL IDE  Version ",mc_version
return lv_str
end function


function copyright_banner()

clear screen
display middle(get_version()) at 7,1

display middle("(c) 2008 Aubit Computing Ltd") at 9,1
display middle("http://www.aubit.com") at 10,1
display middle("Latest version available at:") at 13,1
display middle("http://aubit4gl.sourceforge.net") at 14,1
display middle("Development sponsored by Fabrica de Jabon La Corona ") at 16,1
display middle("http://www.lacorona.com.mx/") at 17,1
sleep 2 # Splash Screen
clear screen
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

function add_default_setting(lv_name,lv_user,lv_s)
define lv_name char(16)
define lv_user char(8)
define lv_s char(32)
define lv_v char(70)
let lv_v=fgl_getenv(lv_s)

delete from afglsettings where name=lv_s
insert into afglsettings values(lv_name,lv_user,lv_s,lv_v)

end function



function add_default_settings(lv_name,lv_user)
define lv_name char(16)
define lv_user char(8)

call add_default_setting(lv_name,lv_user,"A4GL_EXE_EXT")
call add_default_setting(lv_name,lv_user,"A4GL_HLP_EXT")
call add_default_setting(lv_name,lv_user,"A4GL_FRM_BASE_EXT")
call add_default_setting(lv_name,lv_user,"A4GL_PACKED_EXT")
call add_default_setting(lv_name,lv_user,"A4GL_XML_EXT")
call add_default_setting(lv_name,lv_user,"A4GL_OBJ_EXT")
call add_default_setting(lv_name,lv_user,"A4GL_FORMTYPE")
call add_default_setting(lv_name,lv_user,"A4GL_PACKER")

if fgl_getenv("A4GL_LEXTYPE")="EC" then
	call add_default_setting(lv_name,lv_user,"A4GL_LEXTYPE")
	call add_default_setting(lv_name,lv_user,"A4GL_LEXDIALECT")
else
	call add_default_setting(lv_name,lv_user,"A4GL_LEXTYPE")
end if

end function

function get_setting(lv_prog,lv_name)
define lv_prog char(16)
define lv_name char(32)
define lv_v char(70)

	select value into lv_v from afglsettings 
	where progname=lv_prog
	and name=lv_name

	if sqlca.sqlcode=100 then
		return NULL
	else
		return lv_v
	end if
end function

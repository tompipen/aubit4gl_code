# +----------------------------------------------------------------------+
# | Aubit UPSCOL 
# +----------------------------------------------------------------------+
# | Copyright (c) 2003 Aubit Computing Ltd                               |
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

define mv_curr_db char(255)
define mv_curr_tab char(255)
define mv_curr_col char(255)

define mc_version constant "1.0"
define lv_quiet integer
main
initialize mv_curr_db to null
initialize mv_curr_tab to null
initialize mv_curr_col to null
# if you don't want to see the banner
# ever then set this to 1
let lv_quiet=1
defer interrupt
code
A4GL_setenv("A4GL_AUTOBANG","Y",1);
endcode

options message line last


if not lv_quiet then
	call copyright_banner()
end if

call main_menu()

end main

function open_db()
	whenever error continue
	database mv_curr_db

	if sqlca.sqlcode<0 then
		error "Unable to connect to database ",mv_curr_db
	else
		call set_curr_db(mv_curr_db)
	end if
end function

################################################################################
function set_curr_db(p_dbname) 
define p_dbname char(255)
if p_dbname is null or length(p_dbname)=0 then
	initialize mv_curr_db to null
else
	let mv_curr_db=p_dbname
end if
initialize mv_curr_tab to null
initialize mv_curr_col to null
end function


function get_curr_tab()
return mv_curr_tab
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


function set_tabname(p_tabname)
define p_tabname char(30)
let mv_curr_tab=p_tabname
initialize mv_curr_col to null
end function

function set_colname(p_colname)
define p_colname char(30)
let mv_curr_col=p_colname
end function

function get_tabname()
return mv_curr_tab
end function

function get_colname()
return mv_curr_col
end function


################################################################################
function display_banner()
display "------------------------------------------------ Press CTRL-W for Help --------" at 4,1
if mv_curr_db is not null then
	if mv_curr_tab is not null then
		if mv_curr_col is not null then
			display " ",mv_curr_db clipped,":",mv_curr_tab clipped,":",mv_curr_col clipped at 4,10
		else
			display " ",mv_curr_db clipped,":",mv_curr_tab clipped at 4,10
		end if
	else
		display " ",mv_curr_db clipped," " at 4,10
	end if
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
	display "" at lv_y,1
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
let lv_str="ACL UPSCOL Version ",mc_version
return lv_str
end function

function copyright_banner()

clear screen
display middle(get_version()) at 7,1
display middle("(c) 2004 Aubit Computing Ltd") at 9,1
display middle("http://www.aubit.com") at 10,1
display middle("Latest version available at:") at 13,1
display middle("http://aubit4gl.sourceforge.net") at 14,1
sleep 4
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
		sprintf(buff,"SQLCNVPATH=%s",sqlcnvpath);
		putenv(buff);
}
endcode
end if
end function


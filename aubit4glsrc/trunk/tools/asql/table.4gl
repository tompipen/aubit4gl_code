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

function table_menu()
        if not has_db() then
                call select_db()
        end if

	call table_menu_int()
end function




function table_drop()
define lv_tabname char(255)
define lv_rval INTEGER
call table_Select("DROP TABLE >>") returning lv_tabname
if lv_tabname matches " " or lv_tabname is null then
	return 
end if

let lv_tabname="DROP TABLE ",lv_tabname clipped

if confirm_drop() then 
	PREPARE p_droptable FROM lv_tabname
	IF check_and_report_error() THEN
		LET lv_rval=1
	else
		EXECUTE p_droptable
		LET lv_rval=check_and_report_error() 
	END IF
else
	let lv_rval=0 
end if

end function



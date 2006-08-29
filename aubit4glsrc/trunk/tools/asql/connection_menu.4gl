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

{
function connection_menu()
menu "CONNECTION" 
        BEFORE menu
                call display_banner()

	command "Connect" 	"Connect to a database environment."
		call connection_connect()

	command "Disconnect" 	"Disconnect from the current database environment."
		call connection_disconnect()

	command "Exit" 		"Returns to the DB-Access Menu."
	exit menu

end menu
end function


function connection_disconnect()
menu "DISCONNECT" 
	command "Yes" "Disconnect from current database environment."
		call do_disconnect()
		exit menu

	command "No"  "Do not disconnect from current database environment."
		exit menu
end menu
end function
}

function do_disconnect()
	whenever error continue
	close database
	if check_and_report_error() then
	call set_curr_db("")
	call display_banner()
	end if
end function	




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
FUNCTION main_menu()
	MENU "ADBACCESS" 

	BEFORE MENU 
		call display_banner()
		#hide option "Utilities"

	COMMAND "Query-language" "Use SQL query language."
		call query_menu()
		
	COMMAND "Connection" "Connect or disconnect from a database environment."
		call connection_menu()

	COMMAND "Database" "Select, Create, Info, Drop or Close a database."
		call database_menu()

	COMMAND "Table" "Create, Alter, or Drop a database table."
		call table_menu()

	COMMAND "Session" "Retrieve information about the current DB-Access session."
		call session_menu()

	COMMAND "Utilities" "Forms, Reports, User Menus etc."
		call tools_menu()

	COMMAND "Exit" "Exit ADBACCESS."
		exit menu
	end menu
end function


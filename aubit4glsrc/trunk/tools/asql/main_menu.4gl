FUNCTION main_menu()
	MENU "ADBACCESS" 

	BEFORE MENU 
		call display_banner()

	COMMAND "Query-language" "Use SQL query language."
		call query_menu()

	COMMAND "Connection" "Connect or disconnect from a database environment."
		call connection_menu()

	command "Database" "Select, Create, Info, Drop or Close a database."
		call database_menu()

	command "Table" "Create, Alter, or Drop a database table."
		call table_menu()

	command "Session" "Retrieve information about the current DB-Access session."
		call session_menu()

	command "Exit" "Exit ADBACCESS."
		exit menu
	end menu
end function



function connection_menu()
menu "CONNECTION" 
        BEFORE MENU
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

function do_disconnect()
	whenever error continue
	close database
	call check_and_report_error()
	call set_curr_db("")
	call display_banner()
end function	




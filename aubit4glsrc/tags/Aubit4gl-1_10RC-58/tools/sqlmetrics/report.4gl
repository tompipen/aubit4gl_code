################################################################################
function reports_menu()
  	call clear_screen_portion()
		MENU "Report"
			command "Suspicius" "Single SQL with longer time"
					next option "Exit"
			
			command "Expensive" "SQL executed many times with a cumulative time"
					next option "Exit"
		
			command "Invalid" "SQL statements with error"
					next option "Exit"

			command "Exit"  "Return to main menu"
				exit menu
		end menu
end function


################################################################################
function reports_menu()
  	call clear_screen_portion()
		MENU "Report"
			command "Suspicius" "Single SQL with longer time"
					error "Not implemented"
					next option "Exit"
			
			command "Expensive" "SQL executed many times with a cumulative time"
					error "Not implemented"
					next option "Exit"
		
			command "Invalid" "SQL statements with error"
					error "Not implemented"
					next option "Exit"

			command key(ESC,"E") "Exit"  "Return to main menu"
				exit menu
		end menu
end function

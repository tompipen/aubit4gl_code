################################################################################
function audit_menu()
  	call clear_screen_portion()
		MENU "Auditing"
			command "Query" "Search for a pattern in sqls"
                    error "Not implemented"
					next option "Exit"
			
			command "Tables" "Updates to a table in a period of time"
                    error "Not implemented"
					next option "Exit"
		
			command "User" "SQLs from a specific user in a period of time"
                    error "Not implemented"
					next option "Exit"
		
			command "Ideas?" "Please post to aubit4gl-discuss@lists.sourceforge.net"
					next option "Exit"

			command key("E",ESC) "Exit"  "Return to main menu"
				exit menu
		end menu
end function

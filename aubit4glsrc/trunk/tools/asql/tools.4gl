function tools_menu()
	menu "Utilities"
		command "Form" "Form maintenance"
			call form_menu()

		command "Report" "Reports maintenance"
			call report_menu()
	
		command "User-Menus" "User menus maintenance"
			call user_menu()

		command "Exit" "Return to main menu" exit menu

	end menu
end function

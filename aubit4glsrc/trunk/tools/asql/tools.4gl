function tools_menu()
	menu "Tools"
	command "Form" "Form maintenance"
		call form_menu()

	command "Report" "Reports"
		call report_menu()

	command "User-Menus" "User menus"
		call user_menu()

	command "Exit" exit menu
	end menu
end function

function main_menu()
define lv_queryprog char(512)
call display_banner()
menu "SQLMetrics" 
	command "Load" "Load sqlmetrics into analyze table"
		call load_menu()

	command "Analyze" "Analyze metrics already loaded"
		call analyze_menu()

	command "Report" "Reports from sqlmetrics loaded"
		call reports_menu()

	command "Exit" "Exit program"
		exit menu
end menu
end function

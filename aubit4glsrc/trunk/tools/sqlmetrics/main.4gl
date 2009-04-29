function main_menu()
define lv_queryprog char(512)
call display_banner()
menu "SQLMetrics" 
	command "Load" "Load sqlmetrics into analyze table"
		call load_menu()

	command "Purge" "Purge rows from  sqlmetrics table"
		call purge_menu()

	command "Analyze" "Analyze SQLMetrics already loaded (performace)"
		call analyze_menu()

	command "Report" "Reports from sqlmetrics loaded (performance)"
		call reports_menu()

	command key("U") "aUdit" "Auditing reports"
		call audit_menu()

	command key("E", esc) "Exit" "Exit program"
		exit menu
end menu
end function

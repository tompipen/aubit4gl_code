function main_menu()
define lv_queryprog char(512)
call display_banner()
menu "Aubit4GL" 
	command "Module" "Module handling routines"
		call module_menu()

	command "Form" "Form handling routines"
		call form_menu()

	command "Program" "Program handling routines"
		call program_menu()

	command "Query-language" "Start asql query language program"
		# Try to work out the program to run for the query language
		let lv_queryprog=fgl_getenv("DBQUERYPROG")

		# If we've already selected a database (maybe via a form generation?),
		# then make sure we use that if we can...
		if lv_queryprog matches "*%dbparam*" and has_db() then # Used if you need a '-d'
			let lv_queryprog=aclfgl_replace_in_string(lv_queryprog,"%dbparam", get_dbrpl() clipped)
		else
			let lv_queryprog=aclfgl_replace_in_string(lv_queryprog,"%dbparam", " ")
		end if

		if has_db() then
			let lv_queryprog=aclfgl_replace_in_string(lv_queryprog,"%dbname",get_db()) # Used if you dont need the -d
		else
			let lv_queryprog=aclfgl_replace_in_string(lv_queryprog,"%dbname"," ")
		end if
		run lv_queryprog

	command "Exit" "Exit program"
		exit menu
end menu
end function

function get_dbrpl()
define lv_dbrpl char(200)
let lv_dbrpl=fgl_getenv("A4GLDBPARAM")
if lv_dbrpl is null or lv_dbrpl matches " " then
	return "-d "||get_db()
else
	let lv_dbrpl=aclfgl_replace_in_string(lv_dbrpl,"%dbname",get_db())
	return lv_dbrpl clipped
end if

end function


function display_banner()
define lv_curr_db char(255)
set pause mode on
	display "------------------------------------------------ Press CTRL-W for Help --------" at 4,1
	let lv_curr_db=get_db()
	if lv_curr_db is not null then
        	display " ",lv_curr_db clipped," " at 4,25
	end if
set pause mode off

end function


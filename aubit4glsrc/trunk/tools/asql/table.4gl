function table_menu()
        if not has_db() then
                call select_db()
        end if

	MENU "TABLE"
		command "Create" "Create a new Table (not implemented)"
			error "Not Implemented"

		command "Alter" "Alter a table (not implemented)"
			error "Not Implemented"

		command "Info" "Info for a table"
			call table_info()
		
		command "Drop" "Drop a table"
			call table_drop()

		command "Exit" "Return to ADBACCESS Menu"
			exit menu
	END MENU
end function




function table_drop()
define lv_tabname char(255)
define lv_rval INTEGER
call table_Select("DROP TABLE >>") returning lv_tabname
let lv_tabname="DROP TABLE ",lv_tabname clipped
MENU "CONFIRM:"
	command "No"
		let lv_rval=0
		exit menu
		RETURN 0

	command "Yes"
		PREPARE p_droptable FROM lv_tabname
		IF check_and_report_error() THEN
			LET lv_rval=1
		else
			EXECUTE p_droptable
			LET lv_rval=check_and_report_error() 
		END IF
		exit menu
END MENU
return lv_rval
end function


function table_info()
define lv_tabname char(255)
	call table_select("INFO FOR TABLE >>") returning lv_tabname

	if lv_tabname is not null and lv_tabname not matches " " THEN
		call load_info(lv_tabname)
	end if

end function


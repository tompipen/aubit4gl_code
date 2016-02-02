function display_fk(lv_col,lv_val)
define lv_col,lv_val char(50)
define lv_desc char(80)

case lv_col
        when "authmode"
                case lv_val
			when "W" DISPLAY "WEB" TO authmode_desc
			when "N" DISPLAY "NONE" TO authmode_desc
			when "F" DISPLAY "FORM" TO authmode_desc
			otherwise 
				DISPLAY " "  TO authmode_desc
		end case

end case

end function


function validate_column(lv_col,lv_val,lv_upd)
define lv_col,lv_val char(50)
define lv_upd integer # Validation may depend on if this is an Add or an Update..
define lv_cnt integer

case lv_col
        when "authmode"
                case lv_val
                   when "W" return true
                   when "N" return true
                   when "F" return true
		end case
		error "authmode must be W, N or F"

	when "application*"
		if lv_val=" "  or lv_val is null then return true end if
		if lv_val="*"  or lv_val is null then return true end if
		select count(*) into lv_cnt from web_application
			where application=lv_val

		if lv_cnt then
			return true
		end if
		error "Application not found"

	when "username*"
		if lv_val=" " or lv_val is null then return true end if
		if lv_val="*"  or lv_val is null then return true end if
		select count(*) into lv_cnt from web_user
			where username=lv_val

		if lv_cnt then
			return true
		end if
		error "Username not found"
end case

return false
end function



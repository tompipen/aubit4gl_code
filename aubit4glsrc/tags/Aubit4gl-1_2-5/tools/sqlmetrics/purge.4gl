function purge_menu()
	MENU "Purge SQLMetrics"
		command "Before" "Delete rows BEFORE some timestamp"
				call delete_some_rows("<","before") 

		command "After" "Delete rows AFTER some timestamp"
				call delete_some_rows(">","after") 

		command "Slower" "Delete rows slower than a given time"
				call delete_by_elapsed_time() 

		command key("L") "aLl" "Delete ALL SQLMetrics data from table"
			if confirm_yes_no() = "Yes" then
				call delete_all_rows() 
			end if

		command key(esc,"E") "Exit"  "Return to previous  menu"
			exit menu

    END MENU
end function

function confirm_yes_no()
    MENU "CONFIRM"
      BEFORE MENU
        CALL display_banner()

      COMMAND KEY ("n",esc) "No" "No - I don't want to drop it"
      		RETURN "No"
      COMMAND KEY "y" "Yes" "Yes - I do want to drop it"
      		RETURN "Yes"
    END MENU
end function

function delete_all_rows()
delete from sql_log
end function

function delete_some_rows(p_op, p_title)
define p_op char(1)
define p_title char(6)
define lv_a_min, lv_a_max, lv_datetime datetime year to second
define lv_qty int
define lv_prep char(200)
select min(curtime), max(curtime), count(*) into lv_a_min, lv_a_max, lv_qty
      from sql_log
if lv_qty = 0 then
    error "No data to delete"
    sleep 1
    return
end if
open window v_purge at 4,4 with form "purge" attribute(border, form line 1)
display by name lv_a_min, lv_a_max, lv_qty
display p_title to title
let int_flag = 0
let lv_datetime = NULL
input by name lv_datetime 
close window v_purge
if int_flag or lv_datetime is null then
    error "No data deleted"
    sleep 1
    return
end if
let lv_prep = "delete from sql_log where curtime ", p_op, " '", lv_datetime, "'"
display lv_prep
error "Deleting data ...."
sleep 1
prepare ex_prep from lv_prep
execute ex_prep
error "rows deleted"
return
end function

function delete_by_elapsed_time() 
define lv_a_min, lv_a_max, lv_elatime double precision
define lv_qty int
select min(elatime), max(elatime), count(*) into lv_a_min, lv_a_max, lv_qty
      from sql_log
if lv_qty = 0 then
    error "No data to delete"
    sleep 1
    return
end if
open window v_purge at 4,4 with form "purge2" attribute(border, form line 2)
display by name lv_a_min, lv_a_max, lv_qty
input by name lv_elatime 
close window v_purge
if int_flag or lv_elatime is null then
    error "No data deleted"
    sleep 1
    return
end if
error "Deleting data ...."
sleep 1
delete from sql_log where elatime <= lv_elatime
error "rows deleted"
end function

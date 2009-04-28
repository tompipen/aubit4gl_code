function purge_menu()
	MENU "Purge SQLMetrics"
		command "Before" "Delete rows BEFORE some timestamp"
				call delete_some_rows("<","before") 

		command "After" "Delete rows AFTER some timestamp"
				call delete_some_rows(">","after") 

		command "All" "Delete ALL SQLMetrics data from table"
			if confirm_yes_no() = "Yes" then
				call delete_all_rows() 
				next option "All"
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
define lv_min, lv_max, lv_time double precision
define lv_a_min, lv_a_max datetime year to second
define lv_datetime datetime year to second
define lv_qty int
define lv_prep char(200)
select min(curtime), max(curtime), count(*) into lv_min, lv_max, lv_qty
      from sql_log
if lv_qty = 0 then
    error "No data to delete"
    sleep 1
    return
end if
open window v_purge at 4,4 with form "purge" attribute(border, form line 1)
let lv_a_min = epoch2str(lv_min)
display "min=", lv_a_min, lv_min
let lv_a_max = epoch2str(lv_max)
display "max=", lv_a_max, lv_max
display by name lv_a_min, lv_a_max, lv_qty
display p_title to title
let int_flag = 0
let lv_datetime = NULL
input by name lv_datetime 
end input
close window v_purge
if int_flag or lv_datetime is null then
    error "No data deleted"
    sleep 1
    return
end if
let lv_time = str2epoch(lv_datetime)
display "time=", lv_datetime, lv_time
let lv_prep = "delete from sql_log where curtime ", p_op, " ", lv_time USING "<<<<<<<<<<<<<<<<&"
display lv_prep
error "Deleting data ...."
prepare ex_prep from lv_prep
execute ex_prep
sleep 1
error "rows deleted"
return
end function

function epoch2str(p_time)
define p_time double precision
define lv_date char(20)
CODE
#include <time.h>
time_t epch;
epch = p_time;
strftime(lv_date,sizeof(lv_date)-1,"%F %T",gmtime(&epch));
ENDCODE
return lv_date clipped
end function

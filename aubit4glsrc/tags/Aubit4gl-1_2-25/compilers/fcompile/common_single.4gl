{----------------------------------------------------------------------+
| Common Modules                                                       |
+----------------------------------------------------------------------}

# $Id: common_single.4gl,v 1.1 2010-01-14 13:25:35 mikeaubury Exp $



FUNCTION prog_init()
DEFINE	i smallint

    OPTIONS
	    INPUT WRAP,
	    INSERT KEY F21,
	    DELETE KEY F22,
	    PREVIOUS KEY F23,
	    NEXT KEY F24,
		MESSAGE LINE LAST


	LET ga_rec_found = -1
	LET ga_rec_no = 0

END FUNCTION

###############################
# FUNCTION NAME : open_window()
###############################

FUNCTION open_window(lv_module)
define lv_module char(20)
DEFINE lv_window, lv_form CHAR(32)
    SET PAUSE MODE ON
	LET lv_window = "w_", lv_module CLIPPED
	LET lv_form   = "f_", lv_module CLIPPED
	OPEN WINDOW _variable(lv_window) AT 1,1 WITH 24 ROWS, 80 COLUMNS
	OPEN FORM _variable(lv_form) FROM ga_screen_name[1]
	IF STATUS <> 0 THEN
	    EXIT PROGRAM
	END IF
	DISPLAY FORM _variable(lv_form) #ATTRIBUTE (BLACK) #ga_screen_name[i,3])
    LET lv_window = "w_", lv_module CLIPPED
    CURRENT WINDOW IS _variable(lv_window)
    SET PAUSE MODE OFF
END FUNCTION

###############################
# FUNCTION NAME : close_window()
###############################

FUNCTION close_window(lv_module)
define lv_module char(20)
DEFINE lv_window CHAR(32)
    SET PAUSE MODE ON
    LET lv_window = "w_", lv_module CLIPPED
    CLOSE WINDOW _variable(lv_window)
    SET PAUSE MODE OFF
END FUNCTION

###############################
# FUNCTION NAME : display_menu()
###############################

FUNCTION display_menu(lv_module)
define lv_module char(20)
DEFINE lv_query, lv_next, lv_prev, lv_add, lv_update, lv_remove,
	lv_master, lv_detail, lv_screen CHAR(72),
	lv_window, lv_table CHAR(32),
	i, lv_has_master SMALLINT

    LET lv_window = "w_", lv_module CLIPPED
    CURRENT WINDOW IS _variable(lv_window)

    LET lv_query  = "Search the current table                    "
    LET lv_next   = "Shows the next row in the current table     "
    LET lv_prev   = "Shows the previous row in the current table "
    LET lv_add    = "Adds a row to the current table             "
    LET lv_update = "Changes a row in the current table          "
    LET lv_remove = "Deletes a row from the current table        "
    LET lv_screen = "Shows the next screen of the current table  "

    MENU ga_screen_name[2]
	BEFORE MENU
	    CALL display_record()

	COMMAND "Query" lv_query
	    CALL query_by_example()

	COMMAND "Next" lv_next
	    CALL display_next()

	COMMAND "Previous" lv_prev
	    CALL display_previous()

	COMMAND "Add" lv_add
	    CALL add_record()

	COMMAND "Update" lv_update
	    CALL update_record()

	COMMAND "Remove" lv_remove
	    CALL remove_record()

	COMMAND "Exit" "Exit Program"
	    EXIT MENU
    END MENU
END FUNCTION

###############################
# FUNCTION NAME : display_next()
###############################

FUNCTION display_next()

    IF ga_rec_found = 0 THEN
	CALL next_err_msg()
	RETURN
    END IF
    IF ga_rec_no >= ga_rec_found THEN
	CALL next_err_msg()
	RETURN
    END IF
    LET ga_rec_no = ga_rec_no + 1
    CALL get_record()

END FUNCTION

###############################
# FUNCTION NAME : display_previous()
###############################

FUNCTION display_previous()

    IF ga_rec_found = 0 THEN
	CALL prev_err_msg()
	RETURN
    END IF
    IF ga_rec_no <= 1 THEN
	CALL prev_err_msg()
	RETURN
    END IF
    LET ga_rec_no = ga_rec_no - 1
    CALL get_record()

END FUNCTION	

###############################
# FUNCTION NAME : get_color()
###############################

FUNCTION get_color(lv_idx)
DEFINE lv_idx INTEGER
	return "GREEN"
END FUNCTION

###############################
# FUNCTION NAME : set_delimiter()
###############################

FUNCTION set_delimiter(lv_table, lv_state)
DEFINE lv_table, lv_state INTEGER

	return "BLACK"
END FUNCTION

FUNCTION err_msg(str)
    DEFINE str CHAR(79)
    ERROR str ATTRIBUTE (RED, REVERSE)
END FUNCTION

FUNCTION show_comments(str,hasbell,isreverse)
    DEFINE str CHAR(79),
	hasbell, isreverse SMALLINT
    IF hasbell THEN
	LET str = str, ASCII 7
    END IF
    IF isreverse THEN
	ERROR str ATTRIBUTE (RED, REVERSE)
    ELSE
	ERROR str ATTRIBUTE (RED)
    END IF
END FUNCTION


FUNCTION abort_msg(lv_table)
DEFINE lv_table CHAR(32)
    ERROR "Input aborted for table ", lv_table CLIPPED
	ATTRIBUTE (RED, REVERSE)
END FUNCTION

FUNCTION notfound_msg()
    ERROR "There are no rows satisfying the conditions."
	ATTRIBUTE (RED, REVERSE)
END FUNCTION

FUNCTION next_err_msg()
    ERROR "There are no more rows going forward."
	ATTRIBUTE (RED, REVERSE)
END FUNCTION

FUNCTION prev_err_msg()
    ERROR "There are no more rows going backward."
	ATTRIBUTE (RED, REVERSE)
END FUNCTION

FUNCTION recpos_msg()
    MESSAGE 
        "Record ", ga_rec_no USING "<<<<<",
        " of ", ga_rec_found USING "<<<<<", " in ", ga_table_name[1] CLIPPED
	--ATTRIBUTE (RED, REVERSE)
END FUNCTION

FUNCTION ok_to_delete()
    PROMPT "OK TO DELETE ? " ATTRIBUTE(RED,BLINK) FOR CHAR answer
    IF answer MATCHES "[yY]" THEN
	RETURN TRUE
    ELSE
	RETURN FALSE
    END IF
END FUNCTION

FUNCTION add_msg(lv_table)
DEFINE lv_table char(32)
    DISPLAY "ADD:  ESCAPE adds new data.  INTERRUPT discards it.  ARROW keys move cursor.  " at 1,1
    DISPLAY "Adds new data to the active database table.  ** ",
	lv_table CLIPPED, " table **" AT 2,1
END FUNCTION

FUNCTION update_msg(lv_table)
DEFINE lv_table char(32)
    DISPLAY "UPDATE:  ESCAPE changes data.  INTERRUPT discards changes.                    " at 1,1
    DISPLAY "Changes this row in the active database table.  ** ",
	lv_table CLIPPED, " table **" AT 2,1
END FUNCTION

FUNCTION are_you_sure(prompt_msg)
    DEFINE prompt_msg CHAR(70)
    PROMPT prompt_msg CLIPPED ATTRIBUTE(MAGENTA) FOR CHAR answer
    IF answer MATCHES "[yY]" THEN
	RETURN TRUE
    ELSE
	RETURN FALSE
    END IF
END FUNCTION


{----------------------------------------------------------------------+
| Common Modules                                                       |
+----------------------------------------------------------------------}

# $Id: common.4gl,v 1.2 2010-01-14 07:41:41 mikeaubury Exp $


{ global.4gl will be added automagically..}
--GLOBALS "global.4gl"

#DEFINE lv_command, lv_buffer CHAR(256),
#	lv_ret_code INTEGER,
#	IDENT CHAR(40),
#	gr_sypkg RECORD LIKE sypkgcod.*,
#	gr_syspl RECORD LIKE spoolfil.*,
#	gr_job RECORD LIKE jobqueue.*,
#	gr_sec RECORD LIKE sysecfil.*,
#	gv_job_count SMALLINT

FUNCTION prog_init()
DEFINE	i smallint

#    CLOSE DATABASE
    OPTIONS
#	    PROMPT LINE LAST,	# TO SOLVE PROBLEM OF err_prompt
#	    MESSAGE LINE LAST-1,
#	    COMMENT LINE LAST-1,
#	    ERROR LINE LAST,
#	    FORM LINE 4,
	    INPUT WRAP,
#	    INPUT ATTRIBUTE (BLUE, REVERSE),
#	    DISPLAY ATTRIBUTE (BLACK),
#	    ACCEPT KEY F5,
	    INSERT KEY F21,
	    DELETE KEY F22,
	    PREVIOUS KEY F23,
	    NEXT KEY F24


    FOR i = 1 to gv_table_max
	LET ga_rec_found[i] = -1
	LET ga_rec_no[i] = 0
    END FOR

END FUNCTION

###############################
# FUNCTION NAME : open_window()
###############################

FUNCTION open_window(lv_module)
DEFINE lv_module char(20)
DEFINE i SMALLINT,
    lv_window, lv_form CHAR(32)
    SET PAUSE MODE ON
    FOR i = 1 TO gv_screen_max
	LET lv_window = "w_", lv_module CLIPPED, i USING "&&&"
	LET lv_form   = "f_", lv_module CLIPPED, i USING "&&&"
#display "lv_window=", lv_window clipped, " lv_form=", lv_form clipped
	OPEN WINDOW _variable(lv_window) AT 1,1 WITH 24 ROWS, 80 COLUMNS
#	    ATTRIBUTE (BLUE)
	OPEN FORM _variable(lv_form) FROM ga_screen_name[i,1]
#	OPEN WINDOW _variable(lv_window) AT 1,1 WITH FORM ga_screen_name[i,1]
	IF STATUS <> 0 THEN
	    EXIT PROGRAM
	END IF
	DISPLAY FORM _variable(lv_form) #ATTRIBUTE (BLACK) #ga_screen_name[i,3])
    END FOR
    LET lv_window = "w_", lv_module CLIPPED, ga_table_screen[gv_table_no] USING "&&&"
    CURRENT WINDOW IS _variable(lv_window)
    SET PAUSE MODE OFF
END FUNCTION

###############################
# FUNCTION NAME : close_window()
###############################

FUNCTION close_window(lv_module)
define lv_module char(20)
DEFINE i SMALLINT,
    lv_window CHAR(32)
    SET PAUSE MODE ON
    FOR i = gv_screen_max TO 1 STEP -1
	LET lv_window = "w_", lv_module CLIPPED, i USING "&&&"
	CLOSE WINDOW _variable(lv_window)
    END FOR
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

    LET lv_window = "w_", lv_module CLIPPED, gv_screen_no USING "&&&"
#display lv_window clipped sleep 3
    CURRENT WINDOW IS _variable(lv_window)

    LET lv_table = "    ** ", gv_table_no using "<<", ": ",
	ga_table_name[gv_table_no,1] CLIPPED, " table**"
    LET lv_query  = "Search the current table                    ", lv_table
    LET lv_next   = "Shows the next row in the current table     ", lv_table
    LET lv_prev   = "Shows the previous row in the current table ", lv_table
    LET lv_add    = "Adds a row to the current table             ", lv_table
    LET lv_update = "Changes a row in the current table          ", lv_table
    LET lv_remove = "Deletes a row from the current table        ", lv_table
    LET lv_master = "Selects the master table of current table   ", lv_table
    LET lv_detail = "Selects the detail table of current table   ", lv_table
    LET lv_screen = "Shows the next screen of the current table  ", lv_table

    MENU ga_screen_name[gv_screen_no,2]
	BEFORE MENU
	    IF gv_show_detail THEN
		CALL query_by_example()
		LET gv_show_detail = FALSE
	    ELSE
		CALL display_record()
	    END IF
	COMMAND "Query" lv_query
	    LET gv_show_detail = FALSE
	    CALL query_by_example()
	COMMAND "Next" lv_next
	    CALL display_next()
	COMMAND "Previous" lv_prev
	    CALL display_previous()
#	COMMAND "View" "Runs editor commands to display BLOB Contents"
#	    call err_msg("There are no BLOB fields to view.")
#	    CALL papatblb()
	COMMAND "Add" lv_add
	    CALL add_record()
	COMMAND "Update" lv_update
	    CALL update_record()
	COMMAND "Remove" lv_remove
	    CALL remove_record()
{ this is redundant? }
#	COMMAND "Table" "Selects the current table"
#	    CALL get_record()
#
	COMMAND "Screen" lv_screen
	    LET gv_screen_no = gv_screen_no + 1
	    IF gv_screen_no > gv_screen_max THEN
		LET gv_screen_no = 1
	    END IF
	    EXIT MENU
{ ??? }
#	COMMAND "Current" "Displays the current row of the current table"
#	    CALL get_record()
	COMMAND "Master" lv_master
	    LET lv_has_master = 0
	    FOR i = 1 TO gv_table_max
		IF ga_master_of[i] = gv_table_no THEN
		    LET gv_table_no = i
		    LET lv_has_master = 1
		    EXIT FOR
		END IF
	    END FOR
	    IF lv_has_master = 0 THEN
		CALL err_msg("The current table do not have a master table")
		CONTINUE MENU
	    END IF
	    # first screen to show when switching tables
	    LET gv_screen_no = ga_table_screen[gv_table_no]
	    EXIT MENU
	COMMAND "Detail" lv_detail
# allow detail even if no record found
	    IF ga_rec_found[gv_table_no] = 0 THEN
		CALL err_msg("No record found")
		CONTINUE MENU
	    END IF
	    IF ga_master_of[gv_table_no] = 0 THEN
		CALL err_msg("The current table do not have a detail table")
		CONTINUE MENU
	    END IF
	    LET gv_table_no = ga_master_of[gv_table_no]
	    # first screen to show when switching tables
	    LET gv_screen_no = ga_table_screen[gv_table_no]
	    LET gv_show_detail = TRUE
	    EXIT MENU
#	COMMAND "Output" "Print Report"
#	    CALL print_report()
	COMMAND "Exit" "Exit Program"
	    LET gv_screen_no = 0
	    EXIT MENU
    END MENU
END FUNCTION

###############################
# FUNCTION NAME : display_next()
###############################

FUNCTION display_next()

    IF ga_rec_found[gv_table_no] = 0 THEN
	CALL next_err_msg()
	RETURN
    END IF
    IF ga_rec_no[gv_table_no] >= ga_rec_found[gv_table_no] THEN
	CALL next_err_msg()
	RETURN
    END IF
    LET ga_rec_no[gv_table_no] = ga_rec_no[gv_table_no] + 1
    CALL get_record()

END FUNCTION

###############################
# FUNCTION NAME : display_previous()
###############################

FUNCTION display_previous()

    IF ga_rec_found[gv_table_no] = 0 THEN
	CALL prev_err_msg()
	RETURN
    END IF
    IF ga_rec_no[gv_table_no] <= 1 THEN
	CALL prev_err_msg()
	RETURN
    END IF
    LET ga_rec_no[gv_table_no] = ga_rec_no[gv_table_no] - 1
    CALL get_record()

END FUNCTION	

###############################
# FUNCTION NAME : get_color()
###############################

FUNCTION get_color(lv_idx)
DEFINE lv_idx INTEGER
    IF gv_table_no = lv_idx THEN
	return "GREEN"
    ELSE
	return "YELLOW"
    END IF
END FUNCTION

###############################
# FUNCTION NAME : set_delimiter()
###############################

FUNCTION set_delimiter(lv_table, lv_state)
DEFINE lv_table, lv_state INTEGER
    IF lv_table = 0 OR gv_table_no <> lv_table THEN
	IF lv_state = 1 THEN
            CALL aclfgl_set_display_field_delimiters("[]")
        ELSE
            CALL aclfgl_set_display_field_delimiters("  ")
        END IF
    END IF
    IF lv_table = 0 THEN
	return "BLACK"
    END IF
    IF gv_table_no = lv_table THEN
	return "GREEN"
    ELSE
	return "YELLOW"
    END IF

END FUNCTION

FUNCTION err_msg(str)
    DEFINE str CHAR(79)
    ERROR str ATTRIBUTE (RED, REVERSE)
#    ERROR str clipped ATTRIBUTE (REVERSE, BLUE)
#    MESSAGE str clipped ATTRIBUTE(REVERSE, RED)
#    SLEEP 1
#    MESSAGE ""
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
#    ERROR str clipped ATTRIBUTE (REVERSE, BLUE)
#    MESSAGE str clipped ATTRIBUTE(REVERSE, RED)
#    SLEEP 1
#    MESSAGE ""
END FUNCTION

#FUNCTION set_next_field(lv_field)
#DEFINE lv_field CHAR(32)
##    next field lv_field
#END FUNCTION

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
    ERROR ga_table_name[gv_table_no,1] CLIPPED,
        " record ", ga_rec_no[gv_table_no] USING "<<<<<",
        " of ", ga_rec_found[gv_table_no] USING "<<<<<"
	ATTRIBUTE (RED, REVERSE)
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
    display "ADD:  ESCAPE adds new data.  INTERRUPT discards it.  ARROW keys move cursor.  " at 1,1
    display "Adds new data to the active database table.  ** ",
	lv_table CLIPPED, " table **" at 2,1
END FUNCTION

FUNCTION update_msg(lv_table)
DEFINE lv_table char(32)
    display "UPDATE:  ESCAPE changes data.  INTERRUPT discards changes.                    " at 1,1
    display "Changes this row in the active database table.  ** ",
	lv_table CLIPPED, " table **" at 2,1
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


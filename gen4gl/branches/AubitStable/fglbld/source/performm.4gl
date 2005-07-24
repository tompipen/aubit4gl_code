{
	WHATSTR
	@(#)Built by: FGLBLDSTR
	@(#)Main control program for SPI on Xtable
}

DATABASE Xdbase

GLOBALS "Xformg.4gl"

MAIN

	DEFINE
		exit_status	INTEGER,	{ Program exit status }
		sccs		CHAR(1)		{ Identifier string }

	CALL std_options("XFORM")
	DEFER INTERRUPT
	DEFER QUIT

	IF wop_xtable() = 0 THEN
		CALL mnu_xtable()
		CALL wcl_xtable()
		LET exit_status = 0
	ELSE
		LET exit_status = 1
		LET sccs = "WHATSTR"
	END IF

	EXIT PROGRAM exit_status

END MAIN

{ Simplified Perform control function }
FUNCTION mnu_xtable()

	DEFINE
		offset	INTEGER,	{ Amount to jump by (next/previous) }
		junk	INTEGER

	CALL wmn_xtable(2)

	LET offset = 0

	{ If re-entering this query screen }
	IF ct_xtable.active_set > 0 THEN
		LET junk = csr_xtable('C', offset)
	END IF

	MENU "Xmenu"

	COMMAND "Query" "Select set of data" HELP 1
		CASE qry_xtable('Q')
		WHEN 0	NEXT OPTION "Query"
		WHEN 1	NEXT OPTION "Next"
		WHEN 2	NEXT OPTION "Previous"
		END CASE
		CALL check_interrupt()
		LET offset = 0

	COMMAND "Next" "Show next row of data" HELP 2
		LET ct_xtable.direction = 1 { Forwards }
		CASE csr_xtable('N', offset)
		WHEN 0	NEXT OPTION "Query"
		WHEN 1	NEXT OPTION "Next"
		WHEN 2	NEXT OPTION "Previous"
		END CASE
		CALL check_interrupt()
		LET offset = 0

	COMMAND "Previous" "Show previous row of data" HELP 3
		LET ct_xtable.direction = 2 { Backwards }
		CASE csr_xtable('P', offset)
		WHEN 0	NEXT OPTION "Query"
		WHEN 1	NEXT OPTION "Next"
		WHEN 2	NEXT OPTION "Previous"
		END CASE
		CALL check_interrupt()
		LET offset = 0

#Xopt_ins	COMMAND "Add" "Add new row of data" HELP 4
#Xopt_ins		CASE ins_xtable()
#Xopt_ins		WHEN 0	NEXT OPTION "Query"
#Xopt_ins		WHEN 1	NEXT OPTION "Next"
#Xopt_ins		WHEN 2	NEXT OPTION "Previous"
#Xopt_ins		END CASE
#Xopt_ins		CALL check_interrupt()
#Xopt_ins		LET offset = 0
#Xopt_ins
#Xopt_del	COMMAND "Delete" "Delete current record" HELP 5
#Xopt_del		CASE del_xtable()
#Xopt_del		WHEN 0	NEXT OPTION "Query"
#Xopt_del		WHEN 1	NEXT OPTION "Next"
#Xopt_del		WHEN 2	NEXT OPTION "Previous"
#Xopt_del		END CASE
#Xopt_del		CALL check_interrupt()
#Xopt_del		LET offset = 0
#Xopt_del
#Xopt_upd	COMMAND "Update" "Amend current record" HELP 6
#Xopt_upd		CASE upd_xtable()
#Xopt_upd		WHEN 0	NEXT OPTION "Query"
#Xopt_upd		WHEN 1	NEXT OPTION "Next"
#Xopt_upd		WHEN 2	NEXT OPTION "Previous"
#Xopt_upd		END CASE
#Xopt_upd		CALL check_interrupt()
#Xopt_upd		LET offset = 0
#Xopt_upd
#Xopt_rep	COMMAND "Report" "Print data from Xtable table" HELP 7
#Xopt_rep		CASE rdf_xtable()
#Xopt_rep		WHEN 0	NEXT OPTION "Query"
#Xopt_rep		WHEN 1	NEXT OPTION "Next"
#Xopt_rep		WHEN 2	NEXT OPTION "Previous"
#Xopt_rep		END CASE
#Xopt_rep		CALL check_interrupt()
#Xopt_rep		LET offset = 0
#Xopt_rep
	COMMAND "Exit" "Exit Xmenu Menu" HELP 8
		LET INT_FLAG = FALSE
		MESSAGE ""
		EXIT MENU


	COMMAND KEY('0') LET offset = inc_offset(0, offset, ct_xtable.active_set)
	COMMAND KEY('1') LET offset = inc_offset(1, offset, ct_xtable.active_set)
	COMMAND KEY('2') LET offset = inc_offset(2, offset, ct_xtable.active_set)
	COMMAND KEY('3') LET offset = inc_offset(3, offset, ct_xtable.active_set)
	COMMAND KEY('4') LET offset = inc_offset(4, offset, ct_xtable.active_set)
	COMMAND KEY('5') LET offset = inc_offset(5, offset, ct_xtable.active_set)
	COMMAND KEY('6') LET offset = inc_offset(6, offset, ct_xtable.active_set)
	COMMAND KEY('7') LET offset = inc_offset(7, offset, ct_xtable.active_set)
	COMMAND KEY('8') LET offset = inc_offset(8, offset, ct_xtable.active_set)
	COMMAND KEY('9') LET offset = inc_offset(9, offset, ct_xtable.active_set)

	COMMAND KEY('^') { "First" "Jump to first selected row" }
		CASE csr_xtable('F', offset)
		WHEN 0	NEXT OPTION "Query"
		WHEN 1	NEXT OPTION "Next"
		WHEN 2	NEXT OPTION "Previous"
		END CASE
		CALL check_interrupt()
		LET offset = 0

	COMMAND KEY('$') { "Last" "Jump to last selected row" }
		CASE csr_xtable('L', offset)
		WHEN 0	NEXT OPTION "Query"
		WHEN 1	NEXT OPTION "Next"
		WHEN 2	NEXT OPTION "Previous"
		END CASE
		CALL check_interrupt()
		LET offset = 0

	COMMAND KEY(G) { "Goto" "Jump to specified row" }
		CASE csr_xtable('G', offset)
		WHEN 0	NEXT OPTION "Query"
		WHEN 1	NEXT OPTION "Next"
		WHEN 2	NEXT OPTION "Previous"
		END CASE
		CALL check_interrupt()
		LET offset = 0

	COMMAND KEY(C) { "Current" "Re-fetch current row" }
		CASE csr_xtable('C', offset)
		WHEN 0	NEXT OPTION "Query"
		WHEN 1	NEXT OPTION "Next"
		WHEN 2	NEXT OPTION "Previous"
		END CASE
		CALL check_interrupt()
		LET offset = 0

#Xopt_sh	COMMAND KEY('!')
#Xopt_sh		CALL shell_escape()
#Xopt_sh		{ An interrupt may have terminated the shell }
#Xopt_sh		LET INT_FLAG = FALSE 
#Xopt_sh		LET offset = 0
#Xopt_sh
	COMMAND KEY(S) { "Same Query" "Re-execute enquiry" }
		CASE qry_xtable('S')
		WHEN 0	NEXT OPTION "Query"
		WHEN 1	NEXT OPTION "Next"
		END CASE
		CALL check_interrupt()
		LET offset = 0

	COMMAND KEY(CONTROL-Y)
		CALL do_screen_dump()

	COMMAND KEY(F9)
		CALL do_screen_dump()

	END MENU

	CALL wio_xtable(3)

END FUNCTION {do_xtable}

#Xopt_del{ Delete row }
#Xopt_delFUNCTION del_xtable()
#Xopt_del
#Xopt_del	DEFINE
#Xopt_del		junk			INTEGER,
#Xopt_del		op_status		INTEGER,
#Xopt_del		delete_failed	INTEGER
#Xopt_del
#Xopt_del	IF allowed_to_delete() = FALSE THEN
#Xopt_del		CALL immediate_error("You cannot delete data")
#Xopt_del		RETURN ct_xtable.direction
#Xopt_del	END IF
#Xopt_del
#Xopt_del	CALL wio_xtable(2)
#Xopt_del
#Xopt_del	IF ct_xtable.active_set <= 0 THEN
#Xopt_del		CALL immediate_error("No current row to delete")
#Xopt_del		LET ct_xtable.direction = 0 { Query }
#Xopt_del	ELSE
#Xopt_del		{ Assume delete fails until it succeeds }
#Xopt_del		LET delete_failed = TRUE
#Xopt_del		CALL begin_work()
#Xopt_del		IF gtu_xtable(xpkvalue) != 0 THEN
#Xopt_del			CALL immediate_error("Current row has already been deleted")
#Xopt_del			IF Xdel_key(ct_xtable.list_number) THEN
#Xopt_del				CALL internal_error("Error from Xdel_key in del_xtable")
#Xopt_del			END IF
#Xopt_del		ELSE
#Xopt_del			CALL dis_xtable()
#Xopt_del			CALL wmn_xtable(2)
#Xopt_del
#Xopt_del			MENU "DELETE"
#Xopt_del			COMMAND "No"
#Xopt_del					"No, I do not wish to delete this row"
#Xopt_del					HELP 10
#Xopt_del				EXIT MENU
#Xopt_del			COMMAND "Yes"
#Xopt_del					"Yes, I really do want to delete this row"
#Xopt_del					HELP 11
#Xopt_del				IF INT_FLAG = TRUE THEN
#Xopt_del					EXIT MENU
#Xopt_del				END IF
#Xopt_del				LET op_status = iud_xtable('D')
#Xopt_del				IF op_status != 0 THEN
#Xopt_del					CALL notify_errno(op_status)
#Xopt_del				ELSE
#Xopt_del					MESSAGE "Row deleted"
#Xopt_del					LET delete_failed = FALSE
#Xopt_del					IF Xdel_key(ct_xtable.list_number) THEN
#Xopt_del						CALL internal_error("Error from Xdel_key in del_xtable")
#Xopt_del					END IF
#Xopt_del				END IF
#Xopt_del				EXIT MENU
#Xopt_del			COMMAND KEY(CONTROL-Y)
#Xopt_del				CALL do_screen_dump()
#Xopt_del			COMMAND KEY(F9)
#Xopt_del				CALL do_screen_dump()
#Xopt_del			END MENU
#Xopt_del			CALL edu_xtable()
#Xopt_del		END IF
#Xopt_del
#Xopt_del		LET INT_FLAG = FALSE
#Xopt_del		CALL end_work(delete_failed)
#Xopt_del		LET junk = csr_xtable('D', 0)
#Xopt_del
#Xopt_del	END IF
#Xopt_del
#Xopt_del	RETURN ct_xtable.direction
#Xopt_del
#Xopt_delEND FUNCTION {del_xtable}
#Xopt_del
#Xopt_upd{ Change row }
#Xopt_updFUNCTION upd_xtable()
#Xopt_upd
#Xopt_upd	DEFINE
#Xopt_upd		xpkey	Xpktype,
#Xopt_upd		junk			Xpktype,
#Xopt_upd		op_status		INTEGER,
#Xopt_upd		update_failed	INTEGER
#Xopt_upd
#Xopt_upd	IF allowed_to_update() = FALSE THEN
#Xopt_upd		CALL immediate_error("You cannot update data")
#Xopt_upd		RETURN ct_xtable.direction
#Xopt_upd	END IF
#Xopt_upd
#Xopt_upd	CALL wio_xtable(2)
#Xopt_upd
#Xopt_upd	IF ct_xtable.active_set <= 0 THEN
#Xopt_upd		CALL immediate_error("No current row to update")
#Xopt_upd	ELSE
#Xopt_upd		{ Assume update fails until it succeeds }
#Xopt_upd		LET update_failed = TRUE
#Xopt_upd		CALL begin_work()
#Xopt_upd		IF gtu_xtable(xpkvalue) != 0 THEN
#Xopt_upd			CALL immediate_error("Someone else has deleted/altered this row")
#Xopt_upd			IF Xdel_key(ct_xtable.list_number) THEN
#Xopt_upd				CALL internal_error("Error from Xdel_key in del_xtable")
#Xopt_upd			END IF
#Xopt_upd		ELSE
#Xopt_upd			LET xpkey = xpkvalue
#Xopt_upd			{
#Xopt_upd			This call to dis_xtable() is not needed if it only
#Xopt_upd			displays the current record.  If, however, it
#Xopt_upd			displays data from other tables, this call is
#Xopt_upd			necessary to show the other details.  Leave it in
#Xopt_upd			the code unless there are good reasons to remove it.
#Xopt_upd			}
#Xopt_upd			CALL dis_xtable()
#Xopt_upd
#Xopt_upd			IF inp_xtable('U') THEN
#Xopt_upd				LET op_status = iud_xtable('U')
#Xopt_upd				IF op_status = 0 THEN
#Xopt_upd					MESSAGE "Record updated"
#Xopt_upd					LET update_failed = FALSE
#Xopt_upd#Xpkeydec					LET xpkvalue = SQLCA.SQLERRD[6]
#Xopt_upd					IF xpkvalue != xpkey THEN
#Xopt_upd						IF Xupd_key(ct_xtable.list_number, xpkvalue) THEN
#Xopt_upd							CALL internal_error("Error from Xupd_key in upd_xtable")
#Xopt_upd						END IF
#Xopt_upd					END IF
#Xopt_upd					LET cp_xtable.* = wr_xtable.*
#Xopt_upd				ELSE
#Xopt_upd					CALL notify_errno(op_status)
#Xopt_upd				END IF
#Xopt_upd			END IF
#Xopt_upd		END IF
#Xopt_upd
#Xopt_upd		CALL edu_xtable()
#Xopt_upd		CALL end_work(update_failed)
#Xopt_upd		LET junk = csr_xtable('U', 0)
#Xopt_upd
#Xopt_upd	END IF
#Xopt_upd
#Xopt_upd	RETURN ct_xtable.direction
#Xopt_upd
#Xopt_updEND FUNCTION {upd_xtable}
#Xopt_upd
#Xopt_ins{ Add new row(s) }
#Xopt_insFUNCTION ins_xtable()
#Xopt_ins
#Xopt_ins	DEFINE
#Xopt_ins		cpos		INTEGER,
#Xopt_ins		op_status	INTEGER,
#Xopt_ins		junk		INTEGER,
#Xopt_ins		iostatus	INTEGER,
#Xopt_ins		xpkey		Xpktype
#Xopt_ins
#Xopt_ins	IF allowed_to_insert() = FALSE THEN
#Xopt_ins		CALL immediate_error("You cannot insert data")
#Xopt_ins		RETURN ct_xtable.direction
#Xopt_ins	END IF
#Xopt_ins
#Xopt_ins	CALL wio_xtable(2)
#Xopt_ins
#Xopt_ins	{ Transaction will always be committed }
#Xopt_ins	CALL begin_work()
#Xopt_ins
#Xopt_ins	{ Save current position to be restored }
#Xopt_ins	LET cpos = Xnum_key(ct_xtable.list_number)
#Xopt_ins	IF cpos = 0 THEN
#Xopt_ins		LET cpos = 1
#Xopt_ins	END IF
#Xopt_ins
#Xopt_ins	LET INT_FLAG = FALSE
#Xopt_ins	WHILE TRUE
#Xopt_ins
#Xopt_ins		MESSAGE "Enter data: ESC to insert, INTR to abandon"
#Xopt_ins		LET wr_xtable.* = nr_xtable.*
#Xopt_ins		IF inp_xtable('I') = FALSE THEN
#Xopt_ins			EXIT WHILE
#Xopt_ins		END IF
#Xopt_ins		LET op_status = iud_xtable('I')
#Xopt_ins		IF op_status = 0 THEN
#Xopt_ins#SERIALONLY			LET xpkvalue = SQLCA.SQLERRD[2]
#Xopt_ins#SERIALONLY			DISPLAY BY NAME xpkvalue
#Xopt_ins#Xpkey_dec			LET xpkvalue = SQLCA.SQLERRD[6]
#Xopt_ins			IF Xins_key(ct_xtable.list_number, xpkvalue) THEN
#Xopt_ins				CALL internal_error("Error from Xins_key in ins_xtable")
#Xopt_ins			END IF
#Xopt_ins			LET cp_xtable.* = wr_xtable.*
#Xopt_ins			MESSAGE "Row inserted"
#Xopt_ins			SLEEP 2
#Xopt_ins		ELSE
#Xopt_ins			CALL notify_errno(op_status)
#Xopt_ins		END IF
#Xopt_ins
#Xopt_ins	END WHILE
#Xopt_ins
#Xopt_ins	LET INT_FLAG = FALSE
#Xopt_ins	CALL commit_work()
#Xopt_ins	CALL Xget_key(ct_xtable.list_number, 'A', cpos)	{ Restore current position }
#Xopt_ins		RETURNING iostatus, xpkey
#Xopt_ins	IF iostatus < -1 THEN
#Xopt_ins		{ -1: ENOLIST is acceptable if interrupted before first entry }
#Xopt_ins		CALL internal_error("Error from Xget_key in ins_xtable")
#Xopt_ins	END IF
#Xopt_ins	LET junk = csr_xtable('I', 0)
#Xopt_ins
#Xopt_ins	RETURN ct_xtable.direction
#Xopt_ins
#Xopt_insEND FUNCTION {ins_xtable}
#Xopt_ins
{ Move cursor in list -- does not use RDSQL cursors directly }
FUNCTION csr_xtable(action, offset)

	DEFINE
		action		CHAR(1),
		offset		INTEGER,
		get_code	CHAR(1),
		get_jump	INTEGER,
		iostatus	INTEGER,
		fstatus		INTEGER

	CALL wi1_xtable(2)

	LET get_code = 'R'	{ Relative move }
	LET get_jump = 0	{ No distance }

	IF offset = 0 THEN
		LET offset = 1
	END IF

	CASE
	WHEN action = 'I'
		IF ct_xtable.active_set = 0 THEN	{ No previous active list }
			LET get_code = 'F'
		ELSE
			LET get_jump = 1
		END IF
	WHEN action = 'D'
		IF ct_xtable.direction = 1 THEN	{ Forwards }
			LET get_jump = 0
		END IF
		IF ct_xtable.direction = 2 AND ct_xtable.active_row != ct_xtable.active_set THEN
			LET get_jump = -1
		END IF
	WHEN action = 'N'
		LET get_jump = offset
	WHEN action = 'P'
		LET get_jump = -offset
	WHEN action = 'F'
		LET get_code = 'F'
	WHEN action = 'L'
		LET get_code = 'L'
	WHEN action = 'U'
		LET get_code = 'C'
	WHEN action = 'C'
		LET get_code = 'C'
	WHEN action = 'G'
		LET get_code = 'A'
		LET get_jump = offset
	OTHERWISE
		CALL fatal_error("Invalid action code in csr_xtable")
	END CASE


	{ See if we can find the correct row }
	{ NB: someone else may have deleted or changed it }
	LET fstatus = TRUE
	WHILE fstatus

		LET ct_xtable.active_set = Xcnt_key(ct_xtable.list_number)
		IF ct_xtable.active_set <= 0 THEN
			{ No rows left in list }
			CASE
			WHEN action = 'D'
				MESSAGE "All selected rows deleted"
			WHEN action = 'W'
				MESSAGE "One or more rows have been deleted by someone else"
			WHEN action = 'E'
				MESSAGE "An internal error has lost the selected data"
			WHEN action = 'G'
				MESSAGE "Report has been produced"
			OTHERWISE
				MESSAGE "No rows selected"
			END CASE
			LET ct_xtable.direction = 0 { Query next }
			EXIT WHILE
		END IF

		{ Get key for requested row }
		CALL Xget_key(ct_xtable.list_number, get_code, get_jump)
			RETURNING iostatus, xpkvalue
		IF iostatus < 0 THEN
			CALL internal_error("Error from Xget_key in csr_xtable")
			LET iostatus = Xzap_key(ct_xtable.list_number)
			LET action = 'E'
			CONTINUE WHILE
		END IF

		LET ct_xtable.active_row = Xnum_key(ct_xtable.list_number)
		CASE
		WHEN ct_xtable.active_row = 1 AND action = 'P'
			MESSAGE "No more rows going backwards"
			LET ct_xtable.direction  = 1 { Forwards }
		WHEN ct_xtable.active_row = ct_xtable.active_set AND action = 'N'
			MESSAGE "No more rows going forwards"
			LET ct_xtable.direction  = 2 { Backwards }
		OTHERWISE
			MESSAGE ""
		END CASE

		{ Fetch the data from Xtable for Xpkey }
		LET fstatus = get_xtable(xpkvalue)
		IF fstatus != 0 THEN
			{ It wasn't there -- so remove it from the list }
			IF Xdel_key(ct_xtable.list_number) THEN
				CALL internal_error("Error from Xdel_key in csr_xtable")
				LET iostatus = Xzap_key(ct_xtable.list_number)
				LET action = 'E'
			ELSE
				{ Warn user and set up fetch of next row }
				LET action = 'W'
				LET get_code = 'R'
				IF ct_xtable.direction = 1 THEN
					LET get_jump = 1
				ELSE
					LET get_jump = -1
				END IF
			END IF
		END IF

	END WHILE

	IF fstatus = 0 THEN
		CALL dis_xtable()
#Xinput		LET cp_xtable.* = wr_xtable.*
		IF action = 'W' THEN
			MESSAGE "One or more rows have been deleted by someone else"
		END IF
	ELSE
		CLEAR FORM
#Xinput		LET cp_xtable.* = nr_xtable.*
	END IF

	LET ct_xtable.active_row = Xnum_key(ct_xtable.list_number)
	LET ct_xtable.active_set = Xcnt_key(ct_xtable.list_number)
	CALL display_counter(ct_xtable.active_row, ct_xtable.active_set)

	RETURN ct_xtable.direction

END FUNCTION {csr_xtable}

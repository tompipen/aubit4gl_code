{
	WHATSTR
	@(#)Built by: FGLBLDSTR
	@(#)RDSQL Cursor Manipulation for SPI on Xtable
}

DATABASE Xdbase

GLOBALS "Xformg.4gl"

DEFINE
	select_stmt	CHAR(512),
	sccs		CHAR(1)	{ Identifier string }

{ Initialize various bits and pieces }
FUNCTION wop_xtable()

	DEFINE
		braindamaged	CHAR(110)

	LET sccs = "WHATSTR"

	{ Create dlist }
	LET ct_xtable.list_number = Xmk_key()
	IF ct_xtable.list_number <= 0 THEN
		CALL fatal_error("Unable to create list in wop_xtable")
		RETURN 1 { Failure }
	END IF

	{ Open windows and forms }
	CALL wmn_xtable(0)
	CALL wbd_xtable(0)
	CALL wio_xtable(0)
	CALL wi1_xtable(0)
	CALL wi1_xtable(2)

#Xinput	{ Create null record }
#Xinput	INITIALIZE nr_xtable.* TO NULL
#Xinput	LET cp_xtable.* = nr_xtable.*
#Xinput	LET wr_xtable.* = nr_xtable.*
#Xinput	CALL dis_xtable()
#Xinput
	{ Create pre-defined cursors }
	{ Fetch current row from main database }
	LET braindamaged =
		" SELECT Xtable.*",
		" FROM Xtable",
		" WHERE Xtable.Xpkey = ?"
	PREPARE st_current FROM braindamaged
	DECLARE c_current CURSOR FOR st_current

#Xinput	{ Fetch current row from main database for update }
#Xinput	LET braindamaged =
#Xinput		" SELECT Xtable.*",
#Xinput		" FROM Xtable",
#Xinput		" WHERE Xtable.Xpkey = ?",
#Xinput		" FOR UPDATE"
#Xinput	PREPARE st_update FROM braindamaged
#Xinput	DECLARE c_update CURSOR FOR st_update
#Xinput
	{ Initialise counts etc }
	LET ct_xtable.active_set = 0 { No rows selected }
	LET ct_xtable.active_row = 0 { No current row }
	LET ct_xtable.direction  = 0 { Query }
	LET ct_xtable.query_done = 0 { No query constructed }
#Xopt_rep	LET ct_xtable.rep_query  = 0 { No report query constructed }
	RETURN 0 { Success }

END FUNCTION {wop_xtable}

{ Clean up }
FUNCTION wcl_xtable()

	DEFINE
		junk	INTEGER

	{ Close windows and forms }
	CALL wi1_xtable(1)
	CALL wio_xtable(1)
	CALL wbd_xtable(1)
	CALL wmn_xtable(1)

	{ Destroy dlist }
	LET junk =  Xrm_key(ct_xtable.list_number)
	LET ct_xtable.list_number = 0

END FUNCTION {wcl_xtable}

{ Create a select statement for the table }
FUNCTION cns_xtable()

	DEFINE
		wh		CHAR(300),
		retval	INTEGER

	CALL wi1_xtable(2)
	LET INT_FLAG = FALSE
	MESSAGE "Enter criteria: ESC to finish"
	CONSTRUCT wh ON Xtable.* FROM s_xtable.*
	MESSAGE ""
	IF INT_FLAG THEN
		MESSAGE "Interrupt detected -- ignored"
		LET INT_FLAG = FALSE
		LET retval = FALSE
	ELSE
		LET select_stmt =
					"SELECT Xpkey",
					" FROM Xtable",
					" WHERE ", wh CLIPPED,
					" ORDER BY 1"
					# Could be ORDER BY Xtable.Xpkey unless PK is Rowid
		LET retval = TRUE
	END IF

	RETURN retval

END FUNCTION {cns_xtable}

{ Query for set of rows }
FUNCTION qry_xtable(flag)

	DEFINE
		flag	CHAR(1)

	CASE
	WHEN flag = 'Q'
		{ Create new query }
		IF cns_xtable() THEN
			PREPARE s_generate FROM select_stmt
			DECLARE c_generate CURSOR FOR s_generate
			LET ct_xtable.query_done = TRUE
			CALL new_xtable()
		END IF

	WHEN ct_xtable.query_done
		{ Re-execute previous query }
		CALL new_xtable()

	OTHERWISE
		CALL immediate_error("No previous query to execute")
		LET ct_xtable.direction = 0 { Query }
	END CASE

	RETURN ct_xtable.direction

END FUNCTION {qry_xtable}

{ Generate list of rows satisfied by query condition }
FUNCTION new_xtable()

	DEFINE
		pkey	Xpktype

	{ Remove current data from active list }
	IF Xzap_key(ct_xtable.list_number) THEN
		CALL internal_error("Error from Xzap_key in new_xtable")
	END IF
	LET ct_xtable.active_set = 0
	LET ct_xtable.active_row = 0
	LET ct_xtable.direction  = 0

	{ Select primary key values into temporary table }
	FOREACH c_generate INTO pkey
		IF INT_FLAG THEN
			CALL immediate_error("Interrupt detected -- SELECT stopped")
			LET INT_FLAG = FALSE
			EXIT FOREACH
		END IF
		IF Xins_key(ct_xtable.list_number, pkey) THEN
			CALL internal_error("Error from Xins_key in new_xtable")
		END IF
	END FOREACH
	LET ct_xtable.active_set = Xcnt_key(ct_xtable.list_number)

	IF ct_xtable.active_set > 0 THEN
		LET ct_xtable.direction = csr_xtable('F', 0)
	ELSE
		MESSAGE "No rows selected"
		SLEEP 2
		LET ct_xtable.direction = 0 { Query }
	END IF

END FUNCTION {new_xtable}

{ Change data in Xtable }
FUNCTION iud_xtable(flag)

	DEFINE
		flag		CHAR(1),
		op_status	INTEGER

	WHENEVER ERROR CONTINUE
	CASE
	WHEN flag = 'I'
		INSERT INTO Xtable VALUES (wr_xtable.*)
		LET op_status = STATUS
	WHEN flag = 'U'
		UPDATE Xtable
			SET Xtable.* = wr_xtable.*
			WHERE CURRENT OF c_update
		LET op_status = STATUS
	WHEN flag = 'D'
		DELETE FROM Xtable
			WHERE CURRENT OF c_update
		LET op_status = STATUS
	OTHERWISE
		CALL fatal_error("Invalid command passed to iud_xtable")
	END CASE

	WHENEVER ERROR STOP
	RETURN op_status

END FUNCTION {iud_xtable}
#Xinput
#XinputFUNCTION gtu_xtable(pkey)
#Xinput
#Xinput	DEFINE
#Xinput		pkey	Xpktype
#Xinput
#Xinput	WHENEVER ERROR CONTINUE
#Xinput	OPEN c_update USING pkey
#Xinput	IF STATUS != 0 THEN
#Xinput		RETURN STATUS
#Xinput	END IF
#Xinput	FETCH c_update INTO wr_xtable.*
#Xinput	WHENEVER ERROR STOP
#Xinput	RETURN STATUS
#Xinput
#XinputEND FUNCTION {gtu_xtable}
#Xinput
#XinputFUNCTION edu_xtable()
#Xinput
#Xinput	WHENEVER ERROR CONTINUE
#Xinput	CLOSE c_update
#Xinput	WHENEVER ERROR STOP
#Xinput
#XinputEND FUNCTION {edu_xtable}

FUNCTION get_xtable(pkey)

	DEFINE
		pkey	Xpktype,
		fstatus	INTEGER

	WHENEVER ERROR CONTINUE
	OPEN c_current USING pkey
	LET fstatus = STATUS
	IF STATUS = 0 THEN
		FETCH c_current INTO wr_xtable.*
		LET fstatus = STATUS
		CLOSE c_current
	END IF
	WHENEVER ERROR STOP
	RETURN fstatus

END FUNCTION {get_xtable}
#Xopt_rep
#Xopt_rep{ Construct a new report enquiry }
#Xopt_repFUNCTION rnq_xtable()
#Xopt_rep
#Xopt_rep	DEFINE
#Xopt_rep		retval	INTEGER
#Xopt_rep
#Xopt_rep	LET retval = FALSE
#Xopt_rep	IF cns_xtable() THEN
#Xopt_rep		PREPARE s_repquery FROM select_stmt
#Xopt_rep		DECLARE c_repquery CURSOR FOR s_repquery
#Xopt_rep		LET ct_xtable.rep_query = TRUE
#Xopt_rep		LET retval = TRUE
#Xopt_rep	END IF
#Xopt_rep
#Xopt_rep	RETURN retval
#Xopt_rep
#Xopt_repEND FUNCTION {rnq_xtable}
#Xopt_rep
#Xopt_rep{ Report driver function }
#Xopt_repFUNCTION rdf_xtable()
#Xopt_rep
#Xopt_rep	DEFINE
#Xopt_rep		i			INTEGER,
#Xopt_rep		n			INTEGER,
#Xopt_rep		cpos		INTEGER,
#Xopt_rep		c			CHAR(1),
#Xopt_rep		rdest		INTEGER,
#Xopt_rep		pkey		Xpktype,
#Xopt_rep		iostatus	INTEGER
#Xopt_rep
#Xopt_rep	LET c = rch_xtable()
#Xopt_rep
#Xopt_rep	IF c = 'E' THEN
#Xopt_rep		RETURN ct_xtable.direction
#Xopt_rep	END IF
#Xopt_rep
#Xopt_rep	{ Choose where report should go }
#Xopt_rep	CALL report_destination()
#Xopt_rep		RETURNING ct_xtable.report_dest, ct_xtable.report_name
#Xopt_rep	LET rdest = ct_xtable.report_dest
#Xopt_rep	CASE rdest
#Xopt_rep	WHEN 0
#Xopt_rep		START REPORT rpf_xtable
#Xopt_rep	WHEN 1
#Xopt_rep		START REPORT rpf_xtable TO PRINTER
#Xopt_rep	WHEN 2
#Xopt_rep		START REPORT rpf_xtable TO ct_xtable.report_name
#Xopt_rep	WHEN 3
#Xopt_rep		START REPORT rpf_xtable TO PIPE ct_xtable.report_name
#Xopt_rep	OTHERWISE
#Xopt_rep		MESSAGE "Abandoning report"
#Xopt_rep		RETURN ct_xtable.direction
#Xopt_rep	END CASE
#Xopt_rep
#Xopt_rep	{ Save current position }
#Xopt_rep	LET cpos = Xnum_key(ct_xtable.list_number)	
#Xopt_rep
#Xopt_rep	CASE
#Xopt_rep	WHEN c = 'C'	{ Current list }
#Xopt_rep		LET n = Xcnt_key(ct_xtable.list_number)
#Xopt_rep		FOR i = 1 TO n
#Xopt_rep			CALL Xget_key(ct_xtable.list_number, 'A', i)
#Xopt_rep				RETURNING iostatus, pkey
#Xopt_rep			IF iostatus < 0 THEN
#Xopt_rep				CALL internal_error("Error from Xget_key in rdf_xtable")
#Xopt_rep				EXIT CASE
#Xopt_rep			END IF
#Xopt_rep			IF rln_xtable(rdest, i, pkey) = FALSE THEN
#Xopt_rep				EXIT FOR
#Xopt_rep			END IF
#Xopt_rep		END FOR
#Xopt_rep
#Xopt_rep	WHEN c = 'S'	{ Same (main) query }
#Xopt_rep		LET i = 0
#Xopt_rep		FOREACH c_generate INTO pkey
#Xopt_rep			LET i = i + 1
#Xopt_rep			IF rln_xtable(rdest, i, pkey) = FALSE THEN
#Xopt_rep				EXIT FOREACH
#Xopt_rep			END IF
#Xopt_rep		END FOREACH
#Xopt_rep
#Xopt_rep	WHEN c = 'R'	{ (Re)use report enquiry }
#Xopt_rep		LET i = 0
#Xopt_rep		FOREACH c_repquery INTO pkey
#Xopt_rep			LET i = i + 1
#Xopt_rep			IF rln_xtable(rdest, i, pkey) = FALSE THEN
#Xopt_rep				EXIT FOREACH
#Xopt_rep			END IF
#Xopt_rep		END FOREACH
#Xopt_rep
#Xopt_rep	WHEN c = 'A'	{ All rows }
#Xopt_rep		DECLARE c_report CURSOR FOR
#Xopt_rep			SELECT Xtable.Xpkey FROM Xtable ORDER BY 1
#Xopt_rep			# Could be ORDER BY Xtable.Xpkey unless PK is Rowid
#Xopt_rep		LET i = 0
#Xopt_rep		FOREACH c_report INTO pkey
#Xopt_rep			LET i = i + 1
#Xopt_rep			IF rln_xtable(rdest, i, pkey) = FALSE THEN
#Xopt_rep				EXIT FOREACH
#Xopt_rep			END IF
#Xopt_rep		END FOREACH
#Xopt_rep
#Xopt_rep	END CASE
#Xopt_rep
#Xopt_rep	FINISH REPORT rpf_xtable
#Xopt_rep
#Xopt_rep	IF rdest = 3 THEN
#Xopt_rep		CALL redraw_screen()
#Xopt_rep	END IF
#Xopt_rep
#Xopt_rep	{ Restore current position }
#Xopt_rep	LET ct_xtable.direction = csr_xtable('G', cpos)
#Xopt_rep
#Xopt_rep	RETURN ct_xtable.direction
#Xopt_rep
#Xopt_repEND FUNCTION {rdf_xtable}
#Xopt_rep
#Xopt_rep{ Choose report option }
#Xopt_repFUNCTION rch_xtable()
#Xopt_rep
#Xopt_rep	DEFINE
#Xopt_rep		choice	CHAR(1),
#Xopt_rep		n		INTEGER
#Xopt_rep
#Xopt_rep	LET INT_FLAG = FALSE
#Xopt_rep
#Xopt_rep	LET n = Xcnt_key(ct_xtable.list_number)
#Xopt_rep	LET choice = report_type(ct_xtable.query_done, ct_xtable.rep_query, n)
#Xopt_rep
#Xopt_rep	IF choice = 'Q' THEN
#Xopt_rep		IF rnq_xtable() = FALSE THEN
#Xopt_rep			LET choice = 'E'
#Xopt_rep		ELSE
#Xopt_rep			LET choice = 'R'	{ Re-use enquiry just set up }
#Xopt_rep		END IF
#Xopt_rep	END IF
#Xopt_rep
#Xopt_rep	RETURN choice
#Xopt_rep
#Xopt_repEND FUNCTION {rch_xtable}
#Xopt_rep
#Xopt_repFUNCTION rln_xtable(rdest, i, pkey)
#Xopt_rep
#Xopt_rep	DEFINE
#Xopt_rep		rdest		INTEGER,
#Xopt_rep		i			INTEGER,
#Xopt_rep		pkey		Xpktype,
#Xopt_rep		retval		INTEGER
#Xopt_rep
#Xopt_rep	LET retval = FALSE
#Xopt_rep	IF INT_FLAG THEN
#Xopt_rep		CALL immediate_error("Interrupt detected -- report abandoned")
#Xopt_rep	ELSE
#Xopt_rep		IF rdest != 0 AND i MOD 10 = 0 THEN
#Xopt_rep			MESSAGE "Processing row ", i USING "<<<<"
#Xopt_rep		END IF
#Xopt_rep		IF get_xtable(pkey) = 0 THEN
#Xopt_rep			IF ct_xtable.report_dest = 0 THEN
#Xopt_rep				OUTPUT TO REPORT scr_xtable(wr_xtable.*)
#Xopt_rep			ELSE
#Xopt_rep				OUTPUT TO REPORT rpf_xtable(wr_xtable.*)
#Xopt_rep			END IF
#Xopt_rep			LET retval = TRUE
#Xopt_rep		END IF
#Xopt_rep	END IF
#Xopt_rep
#Xopt_rep	RETURN retval
#Xopt_rep
#Xopt_repEND FUNCTION {rln_xtable}

{ Manipulate I/O portion of screen }
FUNCTION wio_xtable(cmd)

    DEFINE
		cmd		INTEGER

    CASE cmd
	WHEN 0     { display the border }
		OPEN WINDOW w_io_xtable AT 5,3 WITH 18 ROWS, 76 COLUMNS
			ATTRIBUTE (FORM LINE FIRST)
	WHEN 1     { close the screen }
		CLOSE WINDOW w_io_xtable
	WHEN 2     { make form window current }
		CURRENT WINDOW IS w_io_xtable
	WHEN 3		{ Clear window }
		CLEAR WINDOW w_io_xtable
	OTHERWISE
		CALL fatal_error("Invalid command passed to wio_xtable")
	END CASE

END FUNCTION {wio_xtable}

{ Manipulate border portion of screen }
FUNCTION wbd_xtable(cmd)

    DEFINE
		cmd		INTEGER

    CASE cmd
	WHEN 0     { display the border }
		OPEN WINDOW w_bd_xtable AT 2,2 WITH 21 ROWS, 78 COLUMNS
			ATTRIBUTES (BORDER)
	WHEN 1     { close the screen }
		CLOSE WINDOW w_bd_xtable
	WHEN 2     { make form window current }
		CURRENT WINDOW IS w_bd_xtable
	WHEN 3		{ Clear window }
		CLEAR WINDOW w_bd_xtable
	OTHERWISE
		CALL fatal_error("Invalid command passed to wio_xtable")
	END CASE

END FUNCTION {wbd_xtable}

{ Manipulate menu portion of screen }
FUNCTION wmn_xtable(cmd)

    DEFINE
		cmd		INTEGER

    CASE cmd
	WHEN 0
		OPEN WINDOW w_mn_xtable AT 2,2 WITH 2 ROWS, 78 COLUMNS
			ATTRIBUTES (BORDER)
	WHEN 1
		CLOSE WINDOW w_mn_xtable
	WHEN 2
		CURRENT WINDOW IS w_mn_xtable
	WHEN 3		{ Clear window }
		CLEAR WINDOW w_mn_xtable
	OTHERWISE
		CALL fatal_error("Invalid command passed to wmn_xtable")
    END CASE

END FUNCTION {wmn_xtable}

{
	@(#)fglsel.4gl	6.3 89/10/16
	@(#)FGLBLD: Create a select function
	@(#)Author: JL
}

GLOBALS "fglbldg.4gl"

DEFINE
	sccs	CHAR(1)

{ Get data for running creating a select function }
FUNCTION do_select()

	DEFINE
		retval		INTEGER,
		i			INTEGER,
		tabid		INTEGER,
		ltabname	CHAR(18),
		prev_field	CHAR(18)

	LET retval = 1
	LET sccs = "@(#)fglsel.4gl	6.3 89/10/16"
	OPEN WINDOW w_mkselect AT 7, 12
		WITH FORM "fglsel"
		ATTRIBUTES (BORDER, MESSAGE LINE FIRST)

	DISPLAY banner TO FORMONLY.heading
	DISPLAY "Create Select Row of Data Function" TO FORMONLY.subheading

	{ Let user choose database; once set, cannot be changed }
	LET dbase = get_dbase()
	IF dbase IS NULL THEN
		LET dbase = inp_dbase()
		IF dbase IS { still } NULL THEN
			CLOSE WINDOW w_mkselect
			RETURN retval
		END IF
	END IF
	DISPLAY BY NAME dbase

	LET prev_field = ""
	MESSAGE "Enter details of Fetch Function.  ESC to accept."
	INPUT details.tabname, details.pkcol, details.basename
		FROM s_input.* HELP 70

	ON KEY (F6, CONTROL-F)
		CALL hlp_fetch()

	BEFORE FIELD tabname
		LET pr_details.tabname = details.tabname

	AFTER FIELD tabname
		IF details.tabname IS NULL THEN
			ERROR "You must specify the table next"
			LET details.tabname = pr_details.tabname
			DISPLAY details.tabname TO FORMONLY.tabname
			NEXT FIELD tabname
		END IF

		IF details.tabname != pr_details.tabname OR pr_details.tabname IS NULL THEN
			LET ltabname = DOWNSHIFT(details.tabname)
			SELECT Systables.Tabid INTO tabid FROM Systables
				WHERE Systables.Tabname = ltabname
				  AND (Systables.Tabtype = 'T' OR Systables.Tabtype = 'V')
			IF STATUS != 0 THEN
				ERROR "Failed to find table ", details.tabname CLIPPED
				NEXT FIELD tabname
			END IF
			LET details.pkcol = NULL
			LET typestr = NULL
			DISPLAY details.pkcol, typestr
				TO FORMONLY.pkcol, FORMONLY.pktype
			CALL fetch_columns(tabid)
		END IF

	BEFORE FIELD pkcol
		LET pr_details.pkcol = details.pkcol

	AFTER FIELD pkcol
		IF details.pkcol IS NULL THEN
			ERROR "You must specify the primary key column next"
			LET details.pkcol = pr_details.pkcol
			DISPLAY details.pkcol TO FORMONLY.pkcol
			NEXT FIELD pkcol
		END IF

		IF details.pkcol != pr_details.pkcol OR pr_details.pkcol IS NULL THEN
			LET typestr = chk_column(details.pkcol)
			IF typestr IS NULL THEN
				ERROR "Unknown column ", details.pkcol CLIPPED
				NEXT FIELD pkcol
			ELSE
				DISPLAY typestr TO FORMONLY.pktype
			END IF
		END IF

	AFTER FIELD basename
		CALL set_file(details.basename)

	ON KEY (F5, CONTROL-B)
		CASE
		WHEN INFIELD(tabname)
			LET details.tabname = ch_systables()
			DISPLAY BY NAME details.tabname
			NEXT FIELD pkcol
		WHEN INFIELD(pkcol)
			CALL ch_syscolumns(details.tabname)
				RETURNING details.pkcol, typestr
			DISPLAY details.pkcol, typestr TO FORMONLY.pkcol, FORMONLY.pktype
			NEXT FIELD basename
		OTHERWISE
			MESSAGE "Sorry: there is no pop-up facility for this field"
		END CASE

	ON KEY (CONTROL-P)
		CASE
		WHEN INFIELD(tabname)
			LET details.tabname = cp_details.tabname
			DISPLAY BY NAME details.tabname
			NEXT FIELD pkcol
		WHEN INFIELD(pkcol)
			LET details.pkcol = cp_details.pkcol
			DISPLAY BY NAME details.pkcol
			DISPLAY typestr TO FORMONLY.pktype
			NEXT FIELD basename
		WHEN INFIELD(basename)
			LET details.basename = cp_details.basename
			DISPLAY BY NAME details.basename
			CALL set_file(details.basename)
			NEXT FIELD tabname
		END CASE

	END INPUT

	CLOSE WINDOW w_mkselect
	CALL show_file()

	IF INT_FLAG != 0 THEN
		MESSAGE "Interrupt detected -- input abandoned"
		SLEEP 2
		MESSAGE ""
		LET INT_FLAG = 0
		LET retval = 1
	ELSE
		LET cp_details.* = details.*
		LET retval = rd_fglbld2("mkselect.alt")
	END IF

	RETURN retval

END FUNCTION {do_select}

FUNCTION hlp_fetch()

	CASE
	WHEN INFIELD(tabname)		CALL SHOWHELP(400)
	WHEN INFIELD(pkcol)			CALL SHOWHELP(401)
	WHEN INFIELD(basename)		CALL SHOWHELP(403)
	END CASE

END FUNCTION {hlp_fetch}

{
	@(#)fglpopup.4gl	6.5 89/10/16
	@(#)FGLBLD: Create pop-up choice functions
	@(#)Author: JL
}

GLOBALS "fglbldg.4gl"

DEFINE
	cp_name_selected	CHAR(30)

FUNCTION do_popup()

	DEFINE
		dbase	CHAR(10),
		junk	INTEGER

	LET dbase = "@(#)fglpopup.4gl	6.5 89/10/16"

	MENU "POP-UP TYPE"

	COMMAND "Conditional"
			"Generate code which allows user to specify what should be shown"
			HELP 151
		LET junk = do_cpopup("cpopup.alt")
		CALL show_file()

	COMMAND "Unconditional"
			"Generate code which always shows the same data unconditionally"
			HELP 152
		LET junk = do_upopup("upopup.alt")
		CALL show_file()

	COMMAND "Database"
			"Specify name of database"
			HELP 30		{ Re-use message }
		LET dbase = inp_dbase()
		CALL show_file()

	COMMAND KEY('!')
		CALL shell_escape()

	COMMAND "Exit"
			"Leave POP-UP TYPE menu"
			HELP 153
		EXIT MENU

	END MENU

	LET INT_FLAG = FALSE

END FUNCTION {do_popup}

{ Generate conditional popup code }
FUNCTION do_cpopup(progname)

	DEFINE
		progname	CHAR(14),
		retval		INTEGER,
		i			INTEGER,
		tabid		INTEGER,
		ltabname	CHAR(18),
		prev_field	CHAR(18)

	LET retval = 1
	OPEN WINDOW w_cpopup AT 7, 10
		WITH FORM "fglcpop"
		ATTRIBUTES (BORDER, MESSAGE LINE FIRST)

	DISPLAY banner TO FORMONLY.heading
	DISPLAY "Create Conditional Pop-up Function" TO FORMONLY.subheading

	{ Let user choose database; once set, cannot be changed }
	LET dbase = get_dbase()
	IF dbase IS NULL THEN
		LET dbase = inp_dbase()
		IF dbase IS { still } NULL THEN
			CLOSE WINDOW w_cpopup
			RETURN retval
		END IF
	END IF
	DISPLAY BY NAME dbase

	LET prev_field = ""
	MESSAGE "Enter details of Conditional Popup.  ESC to accept."
	INPUT details.tabname, details.pkcol, details.menuname,
			details.basename, name_selected FROM s_input.* HELP 50

	ON KEY (F6, CONTROL-F)
		CALL hlp_cpopup()

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
			NEXT FIELD menuname
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
			NEXT FIELD menuname
		WHEN INFIELD(menuname)
			LET details.menuname = cp_details.menuname
			DISPLAY BY NAME details.menuname
			NEXT FIELD basename
		WHEN INFIELD(basename)
			LET details.basename = cp_details.basename
			DISPLAY BY NAME details.basename
			CALL set_file(details.basename)
			NEXT FIELD selected
		WHEN INFIELD(selected)
			LET name_selected = cp_name_selected
			DISPLAY name_selected TO selected
			NEXT FIELD tabname
		END CASE

	END INPUT

	CLOSE WINDOW w_cpopup
	CALL show_file()

	IF INT_FLAG != 0 THEN
		MESSAGE "Interrupt detected -- input abandoned"
		SLEEP 2
		MESSAGE ""
		LET INT_FLAG = 0
		LET retval = 1
	ELSE
		LET cp_details.* = details.*
		LET cp_name_selected = name_selected
		LET cp_optlist.* = optlist.*
		LET retval = rd_fglbld3(progname)
	END IF

	RETURN retval

END FUNCTION {do_cpopup}

FUNCTION hlp_upopup()

	CASE
	WHEN INFIELD(tabname)		CALL SHOWHELP(300)
	WHEN INFIELD(pkcol)			CALL SHOWHELP(301)
	WHEN INFIELD(basename)		CALL SHOWHELP(302)
	WHEN INFIELD(selected)		CALL SHOWHELP(303)
	END CASE

END FUNCTION {hlp_upopup}

FUNCTION hlp_cpopup()

	CASE
	WHEN INFIELD(tabname)		CALL SHOWHELP(200)
	WHEN INFIELD(pkcol)			CALL SHOWHELP(201)
	WHEN INFIELD(menuname)		CALL SHOWHELP(202)
	WHEN INFIELD(basename)		CALL SHOWHELP(203)
	WHEN INFIELD(selected)		CALL SHOWHELP(204)
	END CASE

END FUNCTION {hlp_cpopup}

{ Generate unconditional popup code }
FUNCTION do_upopup(progname)

	DEFINE
		progname	CHAR(14),
		retval		INTEGER,
		i			INTEGER,
		tabid		INTEGER,
		ltabname	CHAR(18),
		prev_field	CHAR(18)

	LET retval = 1
	OPEN WINDOW w_upopup AT 7, 10
		WITH FORM "fglupop"
		ATTRIBUTES (BORDER, MESSAGE LINE FIRST)

	DISPLAY banner TO FORMONLY.heading
	DISPLAY "Create Unconditional Pop-up Function" TO FORMONLY.subheading

	{ Let user choose database; once set, cannot be changed }
	LET dbase = get_dbase()
	IF dbase IS NULL THEN
		LET dbase = inp_dbase()
		IF dbase IS { still } NULL THEN
			CLOSE WINDOW w_upopup
			RETURN retval
		END IF
	END IF
	DISPLAY BY NAME dbase

	LET prev_field = ""
	MESSAGE "Enter details of Unconditional Popup.  ESC to accept."
	INPUT details.tabname, details.pkcol,
			details.basename, name_selected FROM s_input.* HELP 60

	ON KEY(F6, CONTROL-F)
		CALL hlp_upopup()

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
			NEXT FIELD selected
		WHEN INFIELD(selected)
			LET name_selected = cp_name_selected
			DISPLAY name_selected TO selected
			NEXT FIELD tabname
		END CASE

	END INPUT

	CLOSE WINDOW w_upopup
	CALL show_file()

	IF INT_FLAG != 0 THEN
		MESSAGE "Interrupt detected -- input ignored"
		SLEEP 2
		LET INT_FLAG = 0
		LET retval = 1
	ELSE
		LET cp_details.* = details.*
		LET cp_name_selected = name_selected
		LET cp_optlist.* = optlist.*
		LET retval = rd_fglbld3(progname)
	END IF

	RETURN retval

END FUNCTION {do_upopup}

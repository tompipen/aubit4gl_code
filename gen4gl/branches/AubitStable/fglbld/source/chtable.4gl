{
	@(#)chtable.4gl	6.3 89/11/14
	@(#)FGLBLD: Choose table from pop-up list
	@(#)Author: JL
}

DEFINE
	sccs			CHAR(32),
	dr_systables	ARRAY[30] OF RECORD
					tabname CHAR(18),
					tabid   INTEGER
					END RECORD,
	nu_systables	INTEGER

{ Use DISPLAY ARRAY to select a choice from Systables }
FUNCTION ch_systables()

	DEFINE
		n		INTEGER,
		retval	CHAR(18)

	LET sccs = "@(#)chtable.4gl	6.3 89/11/14"
	OPEN WINDOW w_systables AT 10, 17
		WITH FORM "systab"
		ATTRIBUTE(BORDER, MESSAGE LINE FIRST)

	LET retval = NULL
	IF nu_systables > 0 THEN
		IF mn_systables() THEN
			CLOSE WINDOW w_systables
			RETURN retval
		END IF
	ELSE
		CALL co_systables()
		IF nu_systables = 0 THEN
			IF mn_systables() THEN
				CLOSE WINDOW w_systables
				RETURN retval
			END IF
		END IF
	END IF

	LET n = NULL
	IF INT_FLAG = FALSE THEN
		MESSAGE "Use cursor keys to choose table name: ESC to select"
		CALL SET_COUNT(nu_systables)
		DISPLAY ARRAY dr_systables TO s_systables.*
		IF INT_FLAG = FALSE THEN
			LET n = ARR_CURR()
		END IF
		MESSAGE ""
	END IF

	LET INT_FLAG = FALSE

	IF n IS NOT NULL THEN
		LET retval = dr_systables[n].tabname
		CALL fetch_columns(dr_systables[n].tabid)
	END IF

	CLOSE WINDOW w_systables
	RETURN retval

END FUNCTION {ch_systables}

FUNCTION co_systables()

	DEFINE
		wh		CHAR(250),
		sel		CHAR(350),
		i		INTEGER

	MESSAGE "Enter criteria: ESC to finish"
	CONSTRUCT wh ON Systables.Tabname, Systables.Tabid FROM s_systables.*
	MESSAGE ""
	IF INT_FLAG THEN
		MESSAGE "Interrupt detected -- construct abandoned"
		LET INT_FLAG = FALSE
		RETURN
	ELSE
		LET sel =	"SELECT Tabname, Tabid ",
					" FROM Systables",
					" WHERE ", wh CLIPPED,
					" AND (Systables.Tabtype = 'T' OR",
					" Systables.Tabtype = 'V')",
					" AND Systables.Tabid >= 100",
					" ORDER BY Tabname"
		PREPARE st_systables FROM sel
		DECLARE c_systables CURSOR FOR st_systables
	END IF

	LET INT_FLAG = FALSE
	LET i = 0
	FOREACH c_systables INTO dr_systables[i+1].*
		IF INT_FLAG THEN
			ERROR "Interrupt detected -- SELECT abandoned"
			LET INT_FLAG = FALSE
			EXIT FOREACH
		END IF
		LET i = i + 1
		IF i <= 5 THEN	{ 5: dimension of screen array }
			DISPLAY dr_systables[i].* TO s_systables[i].*
		END IF
		IF i >= 30 THEN	{ 30: dimension of program array }
			MESSAGE "Some Tabnames not displayed"
			SLEEP 2
			EXIT FOREACH
		END IF
	END FOREACH

	LET nu_systables = i
	IF nu_systables = 0 THEN
		ERROR "No values selected"
	END IF

END FUNCTION {co_systables}

FUNCTION mn_systables()

	DEFINE
		action	INTEGER

	LET action = -1
	MENU "TABLE NAMES"
	COMMAND "Query"
			"Make a new selection"
		CALL co_systables()
		IF nu_systables > 0 THEN
			LET action = 0
			EXIT MENU
		END IF
	COMMAND "Same again"
			"Use the same list as last time"
		LET action = 0
		EXIT MENU
	COMMAND "Exit"
			"Do not use this help mechanism"
		LET action = -1
		EXIT MENU
	END MENU
	LET INT_FLAG = FALSE
	RETURN action

END FUNCTION {mn_systables}


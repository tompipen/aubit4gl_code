{
	@(#)getdbase.4gl	6.1 89/08/16
	@(#)FGLBLD: Choose working database
	@(#)Author: JL
}

DEFINE
	sccs		CHAR(1),
	olddbase	CHAR(10)

{ Select working database }
FUNCTION inp_dbase()

	DEFINE
		newdbase	CHAR(10)

	LET sccs = "@(#)getdbase.4gl	6.1 89/08/16"

	OPEN WINDOW w_dbase AT 8, 25
		WITH FORM "getdbase"
		ATTRIBUTE(BORDER, FORM LINE 1)

	LET newdbase = olddbase
	LET INT_FLAG = FALSE

	DISPLAY BY NAME olddbase

	INPUT BY NAME newdbase WITHOUT DEFAULTS HELP 32

	ON KEY (F6, CONTROL-F)
		CALL SHOWHELP(33)

	AFTER FIELD newdbase
		CASE
		WHEN newdbase IS NULL
			LET newdbase = olddbase
			DISPLAY BY NAME newdbase
			IF newdbase IS NOT NULL THEN
				EXIT INPUT
			END IF
		WHEN newdbase = olddbase
			EXIT INPUT
		OTHERWISE
			IF open_db(newdbase) != 0 THEN
				ERROR "Failed to open database ", newdbase CLIPPED
			ELSE
				EXIT INPUT
			END IF
		END CASE

	ON KEY (F5, CONTROL-B)
		ERROR "Sorry -- no pop-up facility is available"

	ON KEY (CONTROL-P)
		LET newdbase = olddbase
		DISPLAY BY NAME newdbase
		NEXT FIELD newdbase

	END INPUT

	IF INT_FLAG THEN
		ERROR "Database selection interrupted"
		LET newdbase = NULL
		LET INT_FLAG = FALSE
	END IF

	IF newdbase IS NOT NULL THEN
		LET olddbase = newdbase
	END IF

	CLOSE WINDOW w_dbase
	RETURN newdbase

END FUNCTION {inp_dbase}

FUNCTION set_dbase(newdbase)

	DEFINE
		newdbase	CHAR(10)

	CASE
	WHEN newdbase IS NULL
		RETURN olddbase
	WHEN newdbase = olddbase
		RETURN olddbase
	OTHERWISE
		IF open_db(newdbase) != 0 THEN
			ERROR "Failed to open database ", newdbase CLIPPED
			SLEEP 3
			RETURN olddbase
		ELSE
			LET olddbase = newdbase
		END IF
	END CASE

	RETURN newdbase

END FUNCTION {set_dbase}

FUNCTION get_dbase()

	RETURN olddbase

END FUNCTION {get_dbase}

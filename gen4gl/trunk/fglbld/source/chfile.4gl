{
	@(#)chfile.4gl	6.1 89/08/16
	@(#)FGLBLD: Choose working file name
	@(#)Author: JL
}

DEFINE
	sccs	CHAR(1),
	oldname	CHAR(8),
	fline	CHAR(80)

{ Display line with current file name }
FUNCTION show_file()

	DEFINE
		i	INTEGER,
		p	CHAR(24),
		d	CHAR(28),
		s	CHAR(20),
		db	CHAR(10)

	LET s = "--------------------"
	IF oldname IS NULL THEN
		LET p = "------------------------"
	ELSE
		LET i = 9 - length(oldname)
		LET p = "-- Program: ", oldname clipped, " --",
				s[1,i]
	END IF

	LET db = get_dbase()
	IF db IS NULL THEN
		LET d = "----------------------------"
	ELSE
		LET i = 12 - length(db)
		LET d = "-- Database: ", db clipped, " --",
				s[1,i]
	END IF

	LET fline = p, d, "------ CONTROL-W for Help --"

	DISPLAY fline AT 4, 1

END FUNCTION {show_file}

{ Allow user to specify file name }
FUNCTION choose_file()

	DEFINE
		prog	CHAR(8)

	LET sccs = "@(#)chfile.4gl	6.1 89/08/16"
	LET prog = NULL
	LET INT_FLAG = FALSE
	IF oldname IS NULL THEN
		MESSAGE "There is no default file name"
	ELSE
		MESSAGE "Default file name: ", oldname CLIPPED
	END IF

	WHILE prog IS NULL AND INT_FLAG = FALSE
		PROMPT "Enter basename of program (blank to use default): "
			FOR prog
		IF prog IS NULL THEN
			LET prog = oldname
		END IF
		IF prog IS NULL AND INT_FLAG = FALSE THEN
			ERROR "No file specified"
		END IF
	END WHILE

	IF INT_FLAG THEN
		LET INT_FLAG = 0
		LET prog = NULL
		ERROR "Edit abandoned"
	ELSE
		CALL set_file(prog)
	END IF

	MESSAGE ""

	RETURN prog

END FUNCTION {choose_file}

{ Get the default file name }
FUNCTION get_file()

	RETURN oldname

END FUNCTION {get_file}

{ Set the default file name }
FUNCTION set_file(prog)

	DEFINE
		prog	CHAR(8)

	LET oldname = basename(prog)

END FUNCTION {set_file}

{ Establish basename of filename }
FUNCTION basename(filename)

	DEFINE
		filename	CHAR(512),
		i			INTEGER,
		j			INTEGER,
		l			INTEGER

	LET j = 0
	LET l = LENGTH(filename)
	FOR i = 1 TO l
		IF filename[i] = '/' THEN
			LET j = i
		END IF
	END FOR

	IF j > 0 AND j < l THEN
		LET filename = filename[j+1,l]
	END IF

	RETURN filename

END FUNCTION {basename}

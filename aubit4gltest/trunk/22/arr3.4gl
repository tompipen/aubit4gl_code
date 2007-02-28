
DEFINE	# global to this module
    medarr	ARRAY[4] OF RECORD
			description	CHAR(9),
			bal_amount	INTEGER,
			bal_units	INTEGER,
			price    	INTEGER,
			loan    	INTEGER
			END RECORD

MAIN
	DEFINE
		x	INTEGER,
		y	INTEGER

	OPTIONS
		INPUT WRAP,
    		MESSAGE LINE 1,
    		PROMPT LINE 23,
		COMMENT LINE 23,
		ERROR LINE 24

	OPEN FORM arr3 FROM "arr3"

	DISPLAY FORM arr3 ATTRIBUTE (CYAN)

	CALL fgl_drawbox(21,80,2,1,0)

	LET medarr[1].description = "Line 1"
	LET medarr[2].description = "Line 2"
	LET medarr[3].description = "Line 3"
	LET medarr[4].description = "Line 4"

	LET medarr[1].bal_amount = NULL
	LET medarr[1].price = NULL
	LET medarr[1].loan = NULL
	LET medarr[1].bal_units = NULL

	LET medarr[2].bal_amount = 0
	LET medarr[2].price = 0
	LET medarr[2].loan = 0
	LET medarr[2].bal_units = NULL

	LET medarr[3].bal_amount = 0
	LET medarr[3].price = 0
	LET medarr[3].loan = 0
	LET medarr[3].bal_units = NULL

	LET medarr[4].bal_amount = 0
	LET medarr[4].price = 0
	LET medarr[4].loan = 0
	LET medarr[4].bal_units = NULL

    CALL SET_COUNT(3)

    INPUT ARRAY medarr WITHOUT DEFAULTS FROM ftlbal.*

		ON KEY (F5)
			EXIT INPUT

		BEFORE ROW
			LET x = ARR_CURR()
			LET y = SCR_LINE()
			MESSAGE "ARR_CURR = ", x, " SCR_LINE = ", y

		ON KEY(f6)
			if infield(price) then exit program 1  end if
			if infield(loan) then exit program 0  end if

		BEFORE FIELD price
			error "Next field"
			NEXT FIELD loan

	END INPUT

	CLOSE FORM arr3

END MAIN

DEFINE	# global to this module
    medarr	ARRAY[4] OF RECORD
			description	CHAR(9),
			bal_amount	INTEGER,
			bal_units	INTEGER,
			price    	DECIMAL(8,0),
			loan    	INTEGER
			END RECORD

MAIN
	DEFINE
		x	INTEGER,
		y	INTEGER

define confirm char

	OPTIONS
		INPUT WRAP,
    	MESSAGE LINE 1,
    	PROMPT LINE 23,
		COMMENT LINE 23,
		ERROR LINE 24

	OPEN FORM arr4 FROM "ia"

	DISPLAY FORM arr4 ATTRIBUTE (CYAN)

	CALL fgl_drawbox(21,80,2,1,0)

	LET medarr[1].description = "Line 1"
	LET medarr[1].bal_amount = NULL
	LET medarr[1].price = NULL
	LET medarr[1].loan = NULL
	LET medarr[1].bal_units = NULL

	LET medarr[2].description = "Line 2"
	LET medarr[2].bal_amount = 0
	LET medarr[2].price = 0
	LET medarr[2].loan = 0
	LET medarr[2].bal_units = NULL

	LET medarr[3].description = "Line 3"
	LET medarr[3].bal_amount = 0
	LET medarr[3].price = 0
	LET medarr[3].loan = 0
	LET medarr[3].bal_units = NULL

	LET medarr[4].description = "Line 4"
	LET medarr[4].bal_amount = 0
	LET medarr[4].price = 0
	LET medarr[4].loan = 0
	LET medarr[4].bal_units = NULL

    CALL SET_COUNT(4)

    input array medarr without defaults from  ftlbal.*

		before field price
			error "before field price"
			sleep 1

		after field price
			error "after field price"
			sleep 1
		on key (F5)
			exit input

		BEFORE ROW
			LET x = ARR_CURR()
			LET y = SCR_LINE()
			MESSAGE "ARR_CURR = ", x, " SCR_LINE = ", y
			next field description


	END input

	CLOSE FORM arr4

END MAIN

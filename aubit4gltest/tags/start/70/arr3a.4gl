
DEFINE	# global to this module
    medarr	ARRAY[40] OF RECORD
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

define c integer

	OPTIONS
		INPUT WRAP,
    	MESSAGE LINE 1,
    	PROMPT LINE 23,
		COMMENT LINE 23,
		ERROR LINE 24,
		insert key control-b
		
call startlog("out1")
#, insert key (control-b)

	OPEN FORM arr3 FROM "arr3a"

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

    CALL SET_COUNT(4)

    INPUT ARRAY medarr WITHOUT DEFAULTS FROM ftlbal.* #attribute(red)

		ON KEY (F5)
			EXIT INPUT

		BEFORE ROW
			LET x = ARR_CURR()
			LET y = SCR_LINE()
			LET c=arr_count()
		
#	MESSAGE "ARR_CURR = ", x, " SCR_LINE = ", y, " Count=",c

			call errorlog("B ROW")

		BEFORE INSERT
			LET x = ARR_CURR()
			LET y = SCR_LINE()

			let medarr[x].description="New :",x
			let medarr[x].bal_amount=x
			let medarr[x].price=x
			let medarr[x].loan=x
			let medarr[x].bal_units=x
			display medarr[x].* to ftlbal[y].* attribute(reverse)
			call errorlog("b ins")
	
		after field loan
			call errorlog("a loan")

		after row 
			call errorlog("a row")

		before field loan
			call errorlog("b loan")

		AFTER INSERT
			call errorlog("a ins")
			Message "Done Insert..."
			sleep 1

		BEFORE FIELD price
#			NEXT FIELD loan
			NEXT FIELD NEXT

	END INPUT

	CLOSE FORM arr3

END MAIN

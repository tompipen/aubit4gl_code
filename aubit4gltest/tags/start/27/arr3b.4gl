
DEFINE	# global to this module
    medarr	RECORD
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

	OPEN FORM arr3 FROM "arr3b"

	DISPLAY FORM arr3 ATTRIBUTE (CYAN)

	CALL fgl_drawbox(21,80,2,1,0)

	initialize medarr.* to null

    CALL SET_COUNT(3)

    INPUT medarr WITHOUT DEFAULTS FROM ftlbal[1].*

		ON KEY (F5)
			EXIT INPUT

		#BEFORE ROW
			#LET x = ARR_CURR()
			#LET y = SCR_LINE()
			#MESSAGE "ARR_CURR = ", x, " SCR_LINE = ", y

		BEFORE FIELD price
#			NEXT FIELD loan
			NEXT FIELD NEXT

		ON KEY(f1) 
			if (infield(loan)) then exit program 0
			else exit program 1
			end if
			

	END INPUT

	CLOSE FORM arr3

END MAIN

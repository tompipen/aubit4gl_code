
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
		INPUT NO WRAP,
    	MESSAGE LINE 1,
    	PROMPT LINE 23,
		COMMENT LINE 23,
		ERROR LINE 24

	CALL startlog("m.log")

	OPEN FORM arr4 FROM "m"
	DISPLAY FORM arr4 ATTRIBUTE (CYAN)

display "XX" to al
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

    #initialize medarr to null
call errorlog("Going into input array")

    let x = -1
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
			if x = -1 then
				call errorlog("Before Input A")
			sleep 1
				call input_al()	
			sleep 1
				call errorlog("After Input A")
			
			end if
			LET x = ARR_CURR()
			LET y = SCR_LINE()
			MESSAGE "ARR_CURR = ", x, " SCR_LINE = ", y
			#next field description
	

		ON KEY (f12)
			LET x = ARR_CURR()
			LET y = SCR_LINE()
			call errorlog(x)
			call errorlog(y)


	END input

	CLOSE FORM arr4

END MAIN

function input_al()
	define al	char(2)

	OPTIONS INPUT NO WRAP

	input by name al without defaults
		on key (F5)
			exit input
	end input
	message "OK" sleep 1
end function


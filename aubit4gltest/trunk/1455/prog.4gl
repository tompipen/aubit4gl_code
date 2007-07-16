
DEFINE	# global to this module
    medarr	ARRAY[14] OF RECORD
			description	CHAR(10),
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

	OPEN FORM arr4 FROM "pict"

	DISPLAY FORM arr4 ATTRIBUTE (CYAN)

	CALL fgl_drawbox(21,80,2,1,0)

	LET medarr[1].description = "op1"
	LET medarr[1].bal_amount = NULL
	LET medarr[1].price = NULL
	LET medarr[1].loan = NULL
	LET medarr[1].bal_units = NULL

	LET medarr[2].description = "op2"
	LET medarr[2].bal_amount = 0
	LET medarr[2].price = 123456
	LET medarr[2].loan = 123456
	LET medarr[2].bal_units = NULL

	LET medarr[3].description = "op3"
	LET medarr[3].bal_amount = 0
	LET medarr[3].price = 0
	LET medarr[3].loan = 0
	LET medarr[3].bal_units = NULL

	LET medarr[4].description = "op4"
	LET medarr[4].bal_amount = 0
	LET medarr[4].price = 0
	LET medarr[4].loan = 0
	LET medarr[4].bal_units = NULL

    CALL SET_COUNT(4)

    input array medarr without defaults from ftlbal.*

	CLOSE FORM arr4
    if  medarr[4].description="op3" and  medarr[1].description="op5" then
		exit program 0
	else
		exit program 1
	end if
END MAIN

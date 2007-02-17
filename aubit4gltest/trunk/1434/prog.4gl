

DEFINE	# global to this module
    medarr	ARRAY[4] OF RECORD
			description	CHAR(1),
			bal_amount	INTEGER,
			bal_units	INTEGER,
			price    	DECIMAL(8,0),
			loan    	INTEGER
			END RECORD
define a integer

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

	OPEN FORM arr4 FROM "g_slice"

	DISPLAY FORM arr4 ATTRIBUTE (CYAN)

	CALL fgl_drawbox(21,80,2,1,0)

	LET medarr[1].description = "1"
	LET medarr[1].bal_amount = 1
	LET medarr[1].price = 1
	LET medarr[1].loan = 1
	LET medarr[1].bal_units = 1

	LET medarr[2].description = "2"
	LET medarr[2].bal_amount = 2
	LET medarr[2].price = 2
	LET medarr[2].loan = 2
	LET medarr[2].bal_units = 2

	LET medarr[3].description = "3"
	LET medarr[3].bal_amount = 3
	LET medarr[3].price = 3
	LET medarr[3].loan = 3
	LET medarr[3].bal_units = 3

	LET medarr[4].description = "4"
	LET medarr[4].bal_amount = 4
	LET medarr[4].price = 4
	LET medarr[4].loan = 4
	LET medarr[4].bal_units = 4

    CALL SET_COUNT(4)

    	input array medarr slice(bal_amount thru price) without defaults from ftlbal.*

	CLOSE FORM arr4

	for a=1 to 4
		display medarr[a].description,",",  medarr[a].bal_amount,",",medarr[a].bal_units,",", medarr[a].price,",", medarr[a].loan
	end for

	exit program 0

END MAIN


DEFINE	# global to this module
    medarr	ARRAY[4] OF RECORD
			description	CHAR(1)
END RECORD
define arr array[4] of record
			bal_amount	INTEGER,
			bal_units	INTEGER,
			price    	DECIMAL(8,0),
			loan    	INTEGER
			END RECORD

MAIN
	DEFINE
i integer,
		x	INTEGER,
		y	INTEGER,
oldx integer

	OPTIONS
		INPUT WRAP,
    	MESSAGE LINE 1,
    	PROMPT LINE 23,
		COMMENT LINE 23,
		ERROR LINE 24

	OPEN FORM arr4 FROM "g1"

	DISPLAY FORM arr4 ATTRIBUTE (CYAN)

	CALL fgl_drawbox(21,80,2,1,0)

	LET medarr[1].description = "1"
	LET arr[1].bal_amount = NULL
	LET arr[1].price = 1
	LET arr[1].loan = NULL
	LET arr[1].bal_units = NULL

	LET medarr[2].description = "2"
	LET arr[2].bal_amount = 0
	LET arr[2].price = 2
	LET arr[2].loan = 0
	LET arr[2].bal_units = NULL

	LET medarr[3].description = "3"
	LET arr[3].bal_amount = 0
	LET arr[3].price = 3
	LET arr[3].loan = 0
	LET arr[3].bal_units = NULL

	LET medarr[4].description = "4"
	LET arr[4].bal_amount = 0
	LET arr[4].price = 4
	LET arr[4].loan = 0
	LET arr[4].bal_units = NULL


for i = 1 to 3
display arr[i].* to ftl[i].*
end for
    CALL SET_COUNT(4)
let oldx = null
let x = null
    input array medarr without defaults from ftlbal.*

		on key(f4) call aclfgl_dump_screen("s1.out")
		on key(f5) call aclfgl_dump_screen("s2.out")
		on key(f6) call aclfgl_dump_screen("s3.out")
		on key(f7) call aclfgl_dump_screen("s4.out")
		on key (F6)
			continue input
		on key (F1)
			exit input

		BEFORE ROW
			let oldx = x
			LET x = ARR_CURR()
			LET y = SCR_LINE()
			MESSAGE "ARR_CURR = ", x, " SCR_LINE = ", y
#
# In our real application, it does not have the program array arr[4]
# Also, it does not use the event "after row"
# The purpose here is trying to synchronize the screen array with scroll
#    and display
#
if oldx is null then
continue input
end if
			if x > oldx and x = 4 then
				scroll ftl.* up by 1
				display arr[x].* to ftl[y].*
			end if
			if x < oldx and x = 1 then	
				scroll ftl.* down by 1
				display arr[x].* to ftl[y].*
			end if
		after row
			if x > 4 then
				next field description
			end if
	END input

	CLOSE FORM arr4
END MAIN

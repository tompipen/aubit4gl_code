
#DATABASE sabre

MAIN
	DEFINE
		ans	CHAR(1)

	OPTIONS
		MESSAGE LINE 23,
		PROMPT LINE 1

	MESSAGE "THIS IS 23"

	CALL displine ()
	CALL aclfgl_dump_screen("start.out");
	PROMPT "Ready? " FOR ans

	OPEN FORM x from "x"

	DISPLAY FORM x ATTRIBUTE (CYAN)

	CALL aclfgl_dump_screen("dispform1.out");

	CLOSE FORM x

	CALL aclfgl_dump_screen("close1.out");

	PROMPT "Seen enough of x? " FOR ans

	CALL displine ()


	PROMPT "Ready? " FOR ans

	CALL aclfgl_dump_screen("prompt1.out");
	OPEN FORM y from "y"

	DISPLAY FORM y ATTRIBUTE (RED)
	CALL aclfgl_dump_screen("dispform2.out");

	CLOSE FORM y

	PROMPT "Seen enough of y? " FOR ans
	CALL aclfgl_dump_screen("complete.out");

END MAIN


FUNCTION displine ()
	DISPLAY "01" AT 1,1
	DISPLAY "02" AT 2,1
	DISPLAY "03" AT 3,1
	DISPLAY "04" AT 4,1
	DISPLAY "05" AT 5,1
	DISPLAY "06" AT 6,1
	DISPLAY "07" AT 7,1
	DISPLAY "08" AT 8,1
	DISPLAY "09" AT 9,1
	DISPLAY "10" AT 10,1
	DISPLAY "11" AT 11,1
	DISPLAY "12" AT 12,1
	DISPLAY "13" AT 13,1
	DISPLAY "14" AT 14,1
	DISPLAY "15" AT 15,1
	DISPLAY "16" AT 16,1
	DISPLAY "17" AT 17,1
	DISPLAY "18" AT 18,1
	DISPLAY "19" AT 19,1
	DISPLAY "20" AT 20,1
	DISPLAY "21" AT 21,1
	DISPLAY "22" AT 22,1
	DISPLAY "23" AT 23,1
	DISPLAY "24" AT 24,1

	#DISPLAY "25" AT 25,1
END FUNCTION

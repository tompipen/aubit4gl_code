{
	@(#)$Id: dumptst.4gl,v 1.2 2002-06-14 09:23:17 afalout Exp $
	@(#)Test program for screen dump function
}

MAIN

	DEFINE
		val	DECIMAL

	OPEN FORM f_scrdmp FROM "dumptst"

	DISPLAY FORM f_scrdmp

	LET val = 23.03
	DISPLAY "Hello World", "This is a test", val, "29/12/1989"
		TO s_scrdmp.*
	
	CALL screen_dump("screen.out.1")
	MESSAGE "1st Screen Dumped"
	SLEEP 3

	LET val = 2391.31
	MESSAGE "Dumping 2nd screen to screen.out.2"
	DISPLAY "Goodbye World!", "This is the second test", val, "$Date: 2002-06-14 09:23:17 $"
		TO s_scrdmp.*
	CALL screen_dump("screen.out.2")
	MESSAGE "2nd screen dumped", ""
	SLEEP 3

	CLOSE FORM f_scrdmp
	CLEAR SCREEN

END MAIN

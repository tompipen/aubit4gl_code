
MAIN

	DEFINE
		ans CHAR(1),
		x INTEGER,
		str char(20)

	LET x = NULL

	OPEN FORM disp FROM "disp"

	DISPLAY FORM disp

	display "AA" at 8,1
	DISPLAY x USING "####" AT 8,8 ATTRIBUTE (GREEN)
	let str="####"
	display "BB" at 9,1
	DISPLAY x USING str AT 9,8 ATTRIBUTE (GREEN)

	let str=NULL
	display "CC" at 10,1
	DISPLAY x USING str AT 10,8 ATTRIBUTE (GREEN)

	CALL aclfgl_dump_screen("screen.out")
	CLOSE FORM disp

END MAIN

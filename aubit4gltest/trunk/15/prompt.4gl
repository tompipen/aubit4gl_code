
MAIN
	DEFINE
		ans			CHAR(2),
		acode		CHAR(5),
		bcode		CHAR(5),
		ccode		CHAR(5)

	OPTIONS
		INPUT WRAP,
    	MESSAGE LINE 2,
    	PROMPT LINE 2,
		COMMENT LINE 23,
		ERROR LINE 24

	OPEN FORM john FROM "prompt"

	DISPLAY FORM john

	DISPLAY "-" at 22,1
	DISPLAY "=" at 23,1
	DISPLAY "+" at 24,1

	OPEN WINDOW w_ok at 15, 2 WITH 1 ROWS, 78 COLUMNS ATTRIBUTE (GREEN, BORDER)
	PROMPT "Is this ok? " FOR ans ATTRIBUTE (GREEN)
	CALL aclfgl_dump_screen("prompt1.out")
	MESSAGE "Is this message ok? " ATTRIBUTE (YELLOW)
	SLEEP 1
	ERROR "Is this error ok? " ATTRIBUTE (RED)
	SLEEP 1

	CALL aclfgl_dump_screen("err2.out")
	CLOSE WINDOW w_ok

   	INPUT BY NAME acode, bcode, ccode

		ON KEY (F7)
			EXIT INPUT
		on key(f1)
			CALL aclfgl_dump_screen("inpc.out")
		AFTER FIELD acode
			PROMPT "How are you? " FOR ans
			MESSAGE "Your ans is ", ans

	END INPUT

	CALL aclfgl_dump_screen("inp3.out")
	CLOSE FORM john
	CALL aclfgl_dump_screen("close4.out")

END MAIN

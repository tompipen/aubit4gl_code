{
	@(#)$Id: scrndump.4gl,v 1.1 2002-06-20 09:10:42 afalout Exp $
	@(#)Interface to Screen Dump Utility
}

FUNCTION do_screen_dump()

	DEFINE
		sccs		CHAR(1),
		filename	CHAR(64),
		ans			CHAR(1)

	LET INT_FLAG = FALSE

	OPEN WINDOW w_screen_dump AT 2, 2
		WITH 2 ROWS, 78 COLUMNS
		ATTRIBUTE (BORDER, FORM LINE FIRST, COMMENT LINE LAST)
	OPEN FORM f_screen_dump FROM "scrndump"
	DISPLAY FORM f_screen_dump

	OPTIONS INPUT NO WRAP
	INPUT BY NAME filename
	OPTIONS INPUT WRAP

	IF INT_FLAG THEN
		ERROR "Not doing screen dump"
		LET sccs = "@(#)$Id: scrndump.4gl,v 1.1 2002-06-20 09:10:42 afalout Exp $"
		LET INT_FLAG = FALSE
		CLOSE WINDOW w_screen_dump
		CLOSE FORM   f_screen_dump
		RETURN
	END IF

	IF filename IS NULL THEN
		LET filename = mkfilename("/tmp/scrdumpXXXXXX")
		DISPLAY "Your dump file is: ", filename
		PROMPT "Hit return to continue" FOR CHAR ans
	END IF

	CLOSE WINDOW w_screen_dump
	CLOSE FORM   f_screen_dump

	CALL screendump(filename)

END FUNCTION {do_screen_dump}

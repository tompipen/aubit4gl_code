{
	@(#)$Id: phlpchk.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $
	@(#)Sphinx Informix Tools
	@(#)Test help file stack
	@(#)Author: JL
}

MAIN

	OPTIONS HELP FILE "phlpchk1.iem"

	CALL SHOWHELP(100)

	CALL push_helpfile()

	OPTIONS HELP FILE "phlpchk2.iem"

	CALL SHOWHELP(100)

	CALL pop_helpfile()

	CALL SHOWHELP(100)

END MAIN


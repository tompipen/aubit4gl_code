-- @(#)$Id: interr.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $
-- @(#)JLSS Informix Tools: General Library
-- @(#)Record internal, fatal, and program errors
-- @(#)Author: JL

{ Record irrecoverable error }
FUNCTION fatal_error(s)

	DEFINE
		s		CHAR(512),
		sccs	CHAR(1)

	LET sccs = "@(#)$Id: interr.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $"
	CALL logerror(s)
	ERROR "A serious internal error has occurred -- please report to DBA"
	SLEEP 5
	EXIT PROGRAM 1

END FUNCTION {fatal_error}

{ Record error which can be survived }
FUNCTION internal_error(s)

	DEFINE
		s	CHAR(512)

	CALL logerror(s)
	ERROR "An internal error has been detected -- please report to DBA"
	SLEEP 3

END FUNCTION {internal_error}

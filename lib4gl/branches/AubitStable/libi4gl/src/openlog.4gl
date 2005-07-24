-- @(#)$Id: openlog.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $
-- @(#)JLSS Informix Tools: General Library
-- @(#)Open log file reasonably reliably
-- @(#)Author: JL

FUNCTION open_logfile(filename)

	DEFINE
		filename	CHAR(64),
		cmd			CHAR(90),
		sccs		CHAR(1)

	WHENEVER ERROR CONTINUE
	CALL STARTLOG(filename)
	WHENEVER ERROR STOP

	IF STATUS != 0 THEN
		LET sccs = "@(#)$Id: openlog.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $"
		ERROR "Failed to open log file ", filename
		SLEEP 3
		EXIT PROGRAM 1
	END IF

	LET cmd = "sh -c 'exec chmod 666 ", filename CLIPPED, " 2>&1'"
	RUN cmd

END FUNCTION {open_logfile}

-- @(#)$Id: stdopt.4gl,v 1.2 2002-06-14 09:23:17 afalout Exp $
-- @(#)JLSS Informix Tools: General Library
-- @(#)Set standard options; log messages and errors
-- @(#)Author: JL

DEFINE
	sccs		CHAR(1),	{ SCCS version number }
	basedir		CHAR(64),	{ Base Directory of application }
	uname		CHAR(8),	{ User name }
	pname		CHAR(8)		{ Program name }

{ Set standard options, specify help file, open error log }
FUNCTION std_options(progname)

	DEFINE
		progname	CHAR(8),	# Name of program recorded in log files
		lprogname	CHAR(8),	# Lower-case version of progname
		hlpfile		CHAR(76),	# Name of help file
		logfile		CHAR(76)	# Name of log file

	{ Determine type of database which has been opened -- must be first }
	CALL set_databasetype()

	{ Set explain mode from DBEXPLAIN }
	CALL set_dbexplain()

	{ Set module variables for reuse }
	LET basedir   = get_base()
	LET sccs      = "@(#)$Id: stdopt.4gl,v 1.2 2002-06-14 09:23:17 afalout Exp $"
	LET uname     = username()
	LET pname     = UPSHIFT(progname)
	LET lprogname = DOWNSHIFT(progname)

	IF basedir = "." THEN
		LET logfile = basedir CLIPPED, "/", lprogname CLIPPED, ".log"
		LET hlpfile = basedir CLIPPED, "/", lprogname CLIPPED, ".iem"
	ELSE
		LET logfile = basedir CLIPPED, "/log/", lprogname CLIPPED, ".log"
		LET hlpfile = basedir CLIPPED, "/msg/", lprogname CLIPPED, ".iem"
	END IF
	CALL open_logfile(logfile)
	CALL psh_helpfile(hlpfile)

	{ Security clearance }
	IF allowed_to_do(pname) = FALSE THEN
		CALL logerror("Unauthorised use")
		ERROR "Sorry!"
		SLEEP 3
		EXIT PROGRAM 1
	ELSE
		CALL logmessage("Started")
	END IF

	OPTIONS
		PROMPT  LINE LAST,
		ERROR   LINE LAST,
		MESSAGE LINE LAST - 1,
		COMMENT LINE LAST,
		HELP     KEY CONTROL-W,	{ Standard }
		INSERT   KEY F1,		{ Standard }
		DELETE   KEY F2,		{ Standard }
		NEXT     KEY F3,		{ Standard }
		PREVIOUS KEY F4,		{ Standard }
		#ACCEPT   KEY ESCAPE,	{ Standard }
		INPUT WRAP

END FUNCTION {std_options}

{ Return name of program }
FUNCTION get_progname()

	RETURN pname CLIPPED

END FUNCTION {get_progname}

{ Log a message on log file }
FUNCTION logmessage(msg)

	DEFINE
		msg		CHAR(460),
		fullmsg	CHAR(512)

	{ ERRORLOG records Date and Time anyway }
	LET fullmsg = pname CLIPPED, ": ", uname CLIPPED, ": ", msg
	WHENEVER ERROR CONTINUE
	CALL ERRORLOG(fullmsg CLIPPED)
	WHENEVER ERROR STOP

	IF STATUS != 0 THEN
		ERROR "Failed to write to log file"
		SLEEP 3
		EXIT PROGRAM 1
	END IF

END FUNCTION {logmessage}

{ Log an error message on log file }
FUNCTION logerror(msg)

	DEFINE
		msg		CHAR(460),
		fullmsg	CHAR(512)

	{ ERRORLOG records Date and Time anyway }
	LET fullmsg = pname CLIPPED, ": ", uname CLIPPED, ": <ERROR> ", msg
	WHENEVER ERROR CONTINUE
	CALL ERRORLOG(fullmsg CLIPPED)
	WHENEVER ERROR STOP

	IF STATUS != 0 THEN
		ERROR "Failed to write to log file"
		SLEEP 3
		EXIT PROGRAM 1
	END IF

END FUNCTION {logerror}

{ Is user allowed to do a update }
FUNCTION allowed_to_update()

	DEFINE
		action	CHAR(12)

	LET action = pname CLIPPED, "_UPD"

	RETURN allowed_to_do(action)

END FUNCTION {allowed_to_update}

{ Is user allowed to do a insert }
FUNCTION allowed_to_insert()

	DEFINE
		action	CHAR(12)

	LET action = pname CLIPPED, "_INS"

	RETURN allowed_to_do(action)

END FUNCTION {allowed_to_insert}

{ Is user allowed to do a delete }
FUNCTION allowed_to_delete()

	DEFINE
		action	CHAR(12)

	LET action = pname CLIPPED, "_DEL"

	RETURN allowed_to_do(action)

END FUNCTION {allowed_to_delete}

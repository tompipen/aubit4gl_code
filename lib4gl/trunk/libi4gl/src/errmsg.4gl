-- @(#)$Id: errmsg.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $
-- @(#)JLSS Informix Software: General Library
-- @(#)Display messages and errors
-- @(#):PRODUCT:

{ Display literal error message; optionally delay, log it, exit program }
FUNCTION display_errtxt(txt, delay, log_it, exit_program)

	DEFINE
		txt				CHAR(80),
		delay			INTEGER,
		log_it			INTEGER,
		exit_program	INTEGER

	ERROR txt
	IF delay > 0 THEN
		SLEEP delay
	END IF
	IF log_it = TRUE THEN
		CALL logerror(txt)
	END IF
	IF exit_program = TRUE THEN
		ERROR "Program exiting"
		SLEEP 3
		EXIT PROGRAM 1
	END IF

END FUNCTION {display_errtxt}

{ Display I4GL error message }
FUNCTION display_err4gl(err, delay, log_it, exit_program)

	DEFINE
		err				INTEGER,
		delay			INTEGER,
		log_it			INTEGER,
		exit_program	INTEGER,
		txt				CHAR(80)

	LET txt = ERR_GET(err)
	CALL display_errtxt(txt, delay, log_it, exit_program)

END FUNCTION {display_err4gl}

{ Display application error message }
FUNCTION display_errnum(num, delay, log_it, exit_program)

	DEFINE
		num				INTEGER,
		delay			INTEGER,
		log_it			INTEGER,
		exit_program	INTEGER,
		txt				CHAR(80)

	LET txt = fgl_msgread(num)
	CALL display_errtxt(txt, delay, log_it, exit_program)

END FUNCTION {display_errnum}

{ Display literal message; optionally delay, log it }
FUNCTION display_msgtxt(txt, delay, log_it)

	DEFINE
		txt				CHAR(80),
		delay			INTEGER,
		log_it			INTEGER

	MESSAGE txt
	IF delay > 0 THEN
		SLEEP delay
	END IF
	IF log_it = TRUE THEN
		CALL logmessage(txt)
	END IF

END FUNCTION {display_msgtxt}

{ Display application message }
FUNCTION display_msgnum(num, delay, log_it)

	DEFINE
		num			INTEGER,
		delay		INTEGER,
		log_it		INTEGER,
		txt			CHAR(80)

	LET txt = fgl_msgread(num)
	CALL display_msgtxt(txt, delay, log_it)

END FUNCTION {display_msgnum}

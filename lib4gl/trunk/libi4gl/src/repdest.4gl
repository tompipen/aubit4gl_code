-- @(#)$Id: repdest.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $
-- @(#)JLSS Informix Tools: General Library
-- @(#)Select destination for report
-- @(#)Author: JL

{
	Return values of destination:
	NULL => abandon report
	0    => send to screen
	1    => send to printer
	2    => send to file
	3    => send to pipe
}

DEFINE
	old_name		CHAR(42)		{ old program/filename for CONTROL-P }
DEFINE
	prv_opt			CHAR(1),		{ Was previous option `View' }
	prv_file		CHAR(40)		{ Name of file to be viewed }

{ Select destination for report }
FUNCTION report_destination()

	DEFINE
		wrow		INTEGER,
		pipe_or_file	CHAR(80),
		destination		INTEGER

	LET wrow = 2
	OPEN WINDOW w_repdest1 AT 2, 2
		WITH 2 ROWS, 78 COLUMNS
		ATTRIBUTE (BORDER)
#	OPEN WINDOW w_repdest1 AT wrow, 2
#		WITH 2 ROWS, 78 COLUMNS
#		ATTRIBUTE (BORDER)

	LET prv_opt = NULL
	IF  prv_file IS NOT NULL THEN
		LET pipe_or_file = "rm -f ", prv_file
		RUN pipe_or_file WITHOUT WAITING
		LET prv_file = NULL
	END IF

	MENU "REPORT DESTINATION"

	COMMAND "Screen"
			"Send the report to standard output"
		LET pipe_or_file = "@(#)$Id: repdest.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $" { SCCS ID only }
		LET destination = 0
		LET pipe_or_file = NULL
		CALL set_plength(23)
		CALL set_tmargin(0)
		CALL set_bmargin(0)
		CALL set_lmargin(0)
		EXIT MENU

	COMMAND "Printer"
			"Send output of report to default printer"
		LET pipe_or_file = NULL
		LET destination = 1
		EXIT MENU

	COMMAND KEY(F)
			-- "File"
			-- "Send the report to a new file (over-writes existing file)"
		CALL get_pipe_or_fn(2, "F", wrow)
			RETURNING pipe_or_file, destination
		EXIT MENU

	COMMAND KEY(A)
			-- "Append"
			-- "Append the report to the end of a file (creates new file)"
		CALL get_pipe_or_fn(3, "F", wrow)
			RETURNING pipe_or_file, destination
		LET pipe_or_file = "cat >>", pipe_or_file CLIPPED
		EXIT MENU

	COMMAND "View"
			"Place the report in a file and run editor on file afterwards"
		LET destination = 2
		LET pipe_or_file = mkfilename("/tmp/view.XXXXXX")
		LET prv_file = pipe_or_file
		LET prv_opt  = 'V'
		EXIT MENU

	COMMAND KEY('|')
			{ "Pipe" "Pipe the report to a program (or pipeline)" }
		CALL get_pipe_or_fn(3, "P", wrow)
			RETURNING pipe_or_file, destination
		EXIT MENU

	COMMAND "Exit"
			"Exit without specifying destination -- abandon report"
		LET destination = NULL
		LET pipe_or_file = NULL
		EXIT MENU

	COMMAND KEY(F9)
		CALL do_screen_dump()

	COMMAND KEY(CONTROL-Y)
		CALL do_screen_dump()

	END MENU

	CLOSE WINDOW w_repdest1

	RETURN	destination, pipe_or_file

END FUNCTION {report_destination}

{ Get name of file or program to which report should be sent }
FUNCTION get_pipe_or_fn(dest, code, wrow)

	DEFINE
		wrow	integer,
		dest	INTEGER,
		code	CHAR(1),
		msg		CHAR(25),
		fn		CHAR(42)

	CASE
	WHEN code = "F"
		LET msg = "Enter name of print-file"
	WHEN code = "P"
		LET msg = "Enter name of program"
	END CASE

	LET fn = NULL
	OPEN WINDOW w_repdest2 AT 2, 2
		WITH FORM "repdest"
		ATTRIBUTE(FORM LINE FIRST, COMMENT LINE LAST)
#	OPEN WINDOW w_repdest2 AT wrow, 2
#		WITH FORM "repdest"
#		ATTRIBUTE(FORM LINE FIRST, COMMENT LINE LAST)
	DISPLAY msg AT 1,1

	OPTIONS INPUT NO WRAP
	INPUT BY NAME fn

	ON KEY (INTERRUPT)
		LET dest = NULL
		LET fn = NULL
		EXIT INPUT

	ON KEY (CONTROL-P)
		IF old_name IS NOT NULL THEN
			LET fn = old_name
			DISPLAY BY NAME fn
		END IF

	ON KEY(F9, CONTROL-Y)
		CALL do_screen_dump()

	END INPUT
	OPTIONS INPUT WRAP

	LET INT_FLAG = FALSE
	LET old_name = fn
	CLOSE WINDOW w_repdest2

	RETURN fn, dest

END FUNCTION {get_pipe_or_fn}

{ View saved report }
FUNCTION view_report()

	DEFINE
		cmd		CHAR(80),
		ed		CHAR(20)

	IF prv_opt = 'V' THEN
		LET ed = fgl_getenv("DBEDIT")
		IF ed IS NULL THEN
			LET ed = "vi"
		END IF
		LET cmd = ed clipped, " ", prv_file CLIPPED
		RUN cmd
		LET cmd = "rm -f ", prv_file CLIPPED
		RUN cmd WITHOUT WAITING
		LET prv_opt  = NULL
		LET prv_file = NULL
	END IF

END FUNCTION {view_report}

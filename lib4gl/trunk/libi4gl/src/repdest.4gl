head	2.10;
access;
symbols;
locks; strict;
comment	@# @;


2.10
date	92.10.25.12.07.30;	author jl;	state Exp;
branches;
next	2.9;

2.9
date	91.06.24.22.53.56;	author jl;	state Exp;
branches;
next	2.8;

2.8
date	91.05.17.13.25.38;	author johnl;	state Exp;
branches;
next	2.7;

2.7
date	90.03.01.18.35.10;	author john;	state Exp;
branches;
next	2.6;

2.6
date	90.02.08.18.19.13;	author john;	state Exp;
branches;
next	2.5;

2.5
date	90.01.12.14.05.44;	author john;	state Exp;
branches;
next	2.4;

2.4
date	89.09.27.19.23.14;	author john;	state Exp;
branches;
next	2.3;

2.3
date	89.09.27.18.51.12;	author john;	state Exp;
branches;
next	2.2;

2.2
date	89.08.03.09.42.11;	author john;	state Exp;
branches;
next	2.1;

2.1
date	89.07.13.18.27.48;	author john;	state Exp;
branches;
next	1.5;

1.5
date	88.08.02.23.35.24;	author john;	state Exp;
branches;
next	1.4;

1.4
date	88.08.02.23.32.48;	author john;	state Exp;
branches;
next	1.3;

1.3
date	88.08.02.23.28.47;	author john;	state Exp;
branches;
next	1.2;

1.2
date	88.08.02.23.12.45;	author john;	state Exp;
branches;
next	1.1;

1.1
date	88.04.21.17.55.05;	author john;	state Exp;
branches;
next	;


desc
@@


2.10
log
@Replace getenviron by fgl_getenv
@
text
@-- @@(#)$Id: repdest.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $
-- @@(#)JLSS Informix Tools: General Library
-- @@(#)Select destination for report
-- @@(#)Author: JL

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
		LET pipe_or_file = "@@(#)$Id: repdest.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $" { SCCS ID only }
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
@


2.9
log
@4.00.UE2 does not like OPEN WINDOW w_name AT var, const
@
text
@d174 1
a174 1
		LET ed = getenviron("DBEDIT")
@


2.8
log
@Revise menu (hide File, Append; introduce View)
@
text
@d1 4
a4 6
{
	@@(#)$Id: repdest.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $
	@@(#)JLSS Informix Tools: General Library
	@@(#)Select destination for report
	@@(#)Author: JL
}
d30 1
a30 1
	OPEN WINDOW w_repdest1 AT wrow, 2
d33 3
d130 1
a130 1
	OPEN WINDOW w_repdest2 AT wrow, 2
d133 3
d141 10
a150 10
		ON KEY (INTERRUPT)
			LET dest = NULL
			LET fn = NULL
			EXIT INPUT

		ON KEY (CONTROL-P)
			IF old_name IS NOT NULL THEN
				LET fn = old_name
				DISPLAY BY NAME fn
			END IF
d152 2
a153 2
		ON KEY(F9, CONTROL-Y)
			CALL do_screen_dump()
@


2.7
log
@FIx glitches; add screen dump code
@
text
@d3 1
a3 1
	@@(#)Sphinx Informix Tools: General Library
d5 1
a5 1
	@@(#)Author: JL/DMR
d19 3
d36 7
d62 3
a64 2
	COMMAND "File"
			"Send the report to a new file (over-writes existing file)"
d69 3
a71 2
	COMMAND "Append"
			"Append the report to the end of a file (creates new file)"
d77 8
d161 22
@


2.6
log
@Make window 78 chars long
@
text
@d77 6
d111 1
a111 1
		ATTRIBUTE(FORM LINE FIRST)
d116 1
d121 1
d127 4
@


2.5
log
@Reinstate calls to set_plength et al
@
text
@d30 1
a30 1
		WITH 2 ROWS, 70 COLUMNS
@


2.4
log
@Reduce width of window
@
text
@d40 4
@


2.3
log
@Use window around menu too
@
text
@d30 1
a30 1
		WITH 2 ROWS, 76 COLUMNS
@


2.2
log
@Rewrite to use form to get input (thanks Dave)
@
text
@d24 1
d28 5
d50 1
a50 1
		CALL get_pipe_or_fn(2, "F")
d56 1
a56 1
		CALL get_pipe_or_fn(3, "F")
d63 1
a63 1
		CALL get_pipe_or_fn(3, "P")
d75 2
d82 1
a82 1
FUNCTION get_pipe_or_fn(dest, code)
d85 1
d99 1
a99 1
	OPEN WINDOW w_repdest AT 1, 1
d120 1
a120 1
	CLOSE WINDOW w_repdest
@


2.1
log
@Retitle options; PIPE is on KEY("|"); add SCCS string
@
text
@d3 1
a3 1
	@@(#)KPI Database Project: General Library
d5 1
a5 1
	@@(#)Author: JL
a14 5

	N.B. Default report output configuration should be correct
	for printer.  This code sets the attributes appropriately for
	screen output.  The report function should call set_output()
	as the first action in first page header section.
a16 1
{ Module variables }
d18 1
a18 1
	old_name	CHAR(80)
d20 1
a20 1
{ Report driver for list Platts pub. date table }
a26 4
	LET pipe_or_file = "@@(#)$Id: repdest.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $" { SCCS ID only }
	LET pipe_or_file = NULL
	LET INT_FLAG = FALSE

d29 1
a29 1
    COMMAND "Screen"
d31 1
d33 1
a33 4
		CALL set_plength(23)
		CALL set_tmargin(0)
		CALL set_bmargin(0)
		CALL set_lmargin(0)
d36 1
a36 1
    COMMAND "Printer"
d38 1
d42 4
a45 16
    COMMAND "File"
			"Send the report to a new file (over-write existing file)"
		LET destination = 2
		WHILE pipe_or_file IS NULL AND INT_FLAG = FALSE
			PROMPT "Enter name of print-file " FOR pipe_or_file
			ON KEY (CONTROL-P)
				LET pipe_or_file = old_name
				IF pipe_or_file IS NOT NULL THEN
					MESSAGE "Using file name", pipe_or_file CLIPPED
					SLEEP 1
				END IF
			END PROMPT
			IF pipe_or_file IS NULL AND INT_FLAG = FALSE THEN
				ERROR "No name entered -- INTR to abandon"
			END IF
		END WHILE
d48 4
a51 16
    COMMAND "Append"
			"Append the report to the end of a file (create new file)"
		LET destination = 3
		WHILE pipe_or_file IS NULL AND INT_FLAG = FALSE
			PROMPT "Enter name of print-file " FOR pipe_or_file
			ON KEY (CONTROL-P)
				LET pipe_or_file = old_name
				IF pipe_or_file IS NOT NULL THEN
					MESSAGE "Using file name", pipe_or_file CLIPPED
					SLEEP 1
				END IF
			END PROMPT
			IF pipe_or_file IS NULL AND INT_FLAG = FALSE THEN
				ERROR "No name entered -- INTR to abandon"
			END IF
		END WHILE
d55 4
a58 16
    COMMAND KEY('|')
#			"Pipe the report to a program (or pipeline)"
		LET destination = 3
		WHILE pipe_or_file IS NULL AND INT_FLAG = FALSE
			PROMPT "Enter name of program " FOR pipe_or_file
			ON KEY (CONTROL-P)
				LET pipe_or_file = old_name
				IF pipe_or_file IS NOT NULL THEN
					MESSAGE "Using program name", pipe_or_file CLIPPED
					SLEEP 1
				END IF
			END PROMPT
			IF pipe_or_file IS NULL AND INT_FLAG = FALSE THEN
				ERROR "No name entered -- INTR to abandon"
			END IF
		END WHILE
d64 1
a68 9
	IF INT_FLAG THEN
		LET destination = NULL
		LET INT_FLAG = FALSE
	ELSE
		IF pipe_or_file IS NOT NULL THEN
			LET old_name = pipe_or_file
		END IF
	END IF

d72 44
@


1.5
log
@Add delay (1 sec) after message
@
text
@d33 1
d48 1
a48 1
    COMMAND "Default Printer"
d71 1
a71 1
    COMMAND "Append to File"
d90 2
a91 2
    COMMAND "Pipe"
			"Pipe the report to a program (or pipeline)"
@


1.4
log
@Confirm CONTROL-P name; works otherwise
@
text
@d61 1
d79 1
d97 2
a98 1
					MESSAGE "Using file name", pipe_or_file CLIPPED
@


1.3
log
@Add CONTROL-P facility (compiled but not tested)
@
text
@d59 3
d76 3
d94 3
@


1.2
log
@Make robust; check interrupts; change option name
@
text
@d22 4
d57 3
d71 3
d86 3
d105 4
@


1.1
log
@Initial revision
@
text
@d29 3
a36 1
		LET pipe_or_file = NULL
a44 1
		LET pipe_or_file = NULL
d48 1
a48 1
    COMMAND "New File"
d51 6
a56 1
		PROMPT "Enter name of print-file " FOR pipe_or_file
d62 6
a67 1
		PROMPT "Enter name of print-file " FOR pipe_or_file
d74 6
a79 1
		PROMPT "Enter name of program " FOR pipe_or_file
a84 1
		LET pipe_or_file = NULL
d88 5
@

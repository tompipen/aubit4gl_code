head	7.1;
access;
symbols;
locks; strict;
comment	@# @;


7.1
date	91.05.09.17.56.01;	author johnl;	state Exp;
branches;
next	;


desc
@@


7.1
log
@Initial revision
@
text
@-- @@(#)$Id: reptype.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $
-- @@(#)JLSS Informix Tools: FGLBLD Support Library
-- @@(#)Allow user to select data set for report
-- @@(#)Author: J Leffler

{ Choose report option }
FUNCTION report_type(mqdone, rqdone, nrows)

	DEFINE
		mqdone	INTEGER,	{ Boolean: main query done }
		rqdone	INTEGER,	{ Boolean: report query done }
		nrows	INTEGER,	{ Number of rows in current data }
		sccs	CHAR(1),	{ SCCS ID string }
		choice	CHAR(1)

	LET sccs = "@@(#)$Id: reptype.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $"
	LET INT_FLAG = FALSE

	MENU "REPORT DATA"

	COMMAND "Current-List"
			"Print all the data in the current list"
			HELP 30
		IF nrows <= 0 THEN
			ERROR "No current list"
			NEXT OPTION "Query"
		ELSE
			LET choice = 'C'
			EXIT MENU
		END IF

	COMMAND KEY(S)
			{ "Same Query" }
			{ "Re-execute the main query and report the data" }
			{ HELP 31 }
		IF NOT mqdone THEN
			ERROR "No query to repeat"
			NEXT OPTION "Query"
		ELSE
			LET choice = 'S'
			EXIT MENU
		END IF

	COMMAND "Query"
			"Specify a new enquiry and report the results"
			HELP 32
		LET choice = 'Q'	{ Re-use enquiry just set up }
		EXIT MENU

	COMMAND KEY(R)
			{ "Re-use Query" }
			{ "Re-use the report query specified previously" }
			{ HELP 33 }
		IF NOT rqdone THEN
			ERROR "No report query to re-use"
			NEXT OPTION "Query"
		ELSE
			LET choice = 'R'
			EXIT MENU
		END IF

	COMMAND "All"
			"Report on all the data in the table"
			HELP 34
		LET choice = 'A'
		EXIT MENU

	COMMAND "Exit"
			"Leave the REPORT DATA menu"
			HELP 35
		LET choice = 'E'
		EXIT MENU

	COMMAND KEY(F9)
		CALL do_screen_dump()

	COMMAND KEY(CONTROL-Y)
		CALL do_screen_dump()

	END MENU

	IF INT_FLAG THEN
		LET choice = 'E'
		LET INT_FLAG = FALSE
	END IF

	RETURN choice

END FUNCTION {report_type}
@

{
	@(#)fglbldm.4gl	6.9 89/11/14
	@(#)FGLBLD: Main program
	@(#)Author: JL
}

GLOBALS "fglbldg.4gl"

MAIN

	DEFINE
		dbase		CHAR(10),	{ Used to lose unwanted values }
		help_file	CHAR(64),
		junk		INTEGER		{ Used to lose unwanted values }

	LET dbase = "@(#)fglbldm.4gl	6.9 89/11/14"	{ SCCS ID only }
	LET help_file = getenviron("FGLBLDDIR")
	IF help_file IS NULL THEN
		LET help_file = "/usr/fglbld"
	END IF
	LET help_file = help_file CLIPPED, "/forms/fglbld.iem"

	OPTIONS
		HELP FILE help_file,
		HELP KEY CONTROL-W,
		INPUT WRAP,
		PROMPT LINE 24,
		ERROR LINE 24,
		MESSAGE LINE 22,
		COMMENT LINE 23,
		ACCEPT KEY ESCAPE

	DEFER INTERRUPT
	DEFER QUIT

	{ Allow program to be started as fglbld dbase to preselect database }
	IF NUM_ARGS() = 1 THEN
		LET dbase = set_dbase(arg_val(1))
	END IF
	IF NUM_ARGS() > 1 THEN
		CLEAR SCREEN
		ERROR "Usage: FGLBLD [dbase]"
		SLEEP 3
		CLEAR SCREEN
		EXIT PROGRAM 1
	END IF

	LET banner = "FGLBLD Version 6.12 (04/04/1990)"

	CALL show_file()

	MENU "FGLBLD"

	COMMAND "SPI"
			"Generate a Simplified Perform Interface"
			HELP 20
		IF do_fglbld() = 0 THEN
			NEXT OPTION "Run"
		END IF
		CALL show_file()

	COMMAND "Pop-up"
			"Generate code for a pop_up window to select data"
			HELP 21
		CALL do_popup()
		CALL show_file()

	COMMAND "Fetch"
			"Generate a routine to fetch a row of data given the primary key"
			HELP 29
		IF do_select() = 0 THEN
			NEXT OPTION "Modify"
		END IF
		CALL show_file()

	COMMAND "Database"
			"Specify database"
			HELP 30
		LET dbase = inp_dbase()
		CALL show_file()

	COMMAND "Modify"
			"Edit existing code"
			HELP 22
		CALL do_edit()
		CALL show_file()

	COMMAND "Build"
			"Compile a program"
			HELP 23
		IF comp_prog() THEN
			NEXT OPTION "Modify"
		ELSE
			NEXT OPTION "Run"
		END IF
		CALL show_file()

	COMMAND "Run"
			"Run a program"
			HELP 24
		LET junk = run_prog()
		CALL show_file()

	COMMAND "Name"
			"Change name of program"
			HELP 26
		LET dbase = choose_file()
		CALL show_file()

	COMMAND KEY('!')
		CALL shell_escape()

	COMMAND "Exit"
			"Leave the FGLBLD menu"
			HELP 25
		LET INT_FLAG = FALSE
		EXIT MENU

	END MENU

	CLEAR SCREEN

END MAIN

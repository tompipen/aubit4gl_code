{
	@(#)fgledit.4gl	6.4 89/08/17
	@(#)FGLBLD: Edit file(s)
	@(#)Author: JL
}

DEFINE
	sccs	CHAR(32),
	editor	CHAR(20)

FUNCTION do_edit()

	DEFINE
		cmd		CHAR(80),
		prog	CHAR(8),
		letter	CHAR(1),
		junk	INTEGER

	IF editor IS NULL THEN
		LET editor = getenviron("DBEDIT")
		IF editor IS NULL THEN
			LET sccs = "@(#)fgledit.4gl	6.4 89/08/17"
			LET editor = "vi"
		END IF
	END IF

	LET prog = get_file()
	IF prog IS NULL THEN
		LET prog = choose_file()
		IF prog IS NULL THEN
			RETURN
		END IF
		CALL show_file()
	END IF

	MENU "EDITING"

	COMMAND "Source"
			"Edit program source"
			HELP 530
		MENU "SOURCE FILE"
		COMMAND "Input" "Edit the INPUT code" HELP 540
			LET letter = "i"
			EXIT MENU
		COMMAND "Report" "Edit the report code" HELP 541
			LET letter = "r"
			EXIT MENU
		COMMAND "Cursor" "Edit the cursor handling code" HELP 542
			LET letter = "c"
			EXIT MENU
		COMMAND "Main" "Edit the main program and insert, delete, update code"
				HELP 543
			LET letter = "m"
			EXIT MENU
		COMMAND "Globals" "Edit the globals file" HELP 544
			LET letter = "g"
			EXIT MENU
		COMMAND "Other" "Edit a pop-up or fetch file" HELP 545
			LET letter = ""
			EXIT MENU
		COMMAND KEY('!')
			CALL shell_escape()
		COMMAND "Exit" "Leave the SOURCE FILE menu" HELP 546
			LET letter = "e"
			EXIT MENU
		END MENU
		CASE
		WHEN letter IS NULL
			LET cmd = editor CLIPPED, " ", prog CLIPPED, ".4gl"
			RUN cmd
		WHEN letter != "e"
			LET cmd = editor CLIPPED, " ", prog CLIPPED, letter, ".4gl"
			RUN cmd
		END CASE

	COMMAND "Form"
			"Edit screen form"
			HELP 531
		LET cmd = editor CLIPPED, " ", prog CLIPPED, ".4pr"
		RUN cmd

	COMMAND "Help"
			"Edit help message file"
			HELP 532
		LET cmd = editor CLIPPED, " ", prog CLIPPED, ".msg"
		RUN cmd

	COMMAND "Makefile"
			"Edit makefile for program"
			HELP 533
		LET cmd = editor CLIPPED, " ", prog CLIPPED, ".mk"
		RUN cmd

	COMMAND "Build"
			"Compile a program"
			HELP 534
		IF comp_prog() = 0 THEN
			NEXT OPTION "Run"
		END IF
		CALL show_file()

	COMMAND "Run"
			"Run a program"
			HELP 535
		LET junk = run_prog()
		CALL show_file()

	COMMAND "Name"
			"Change the base name of the files to be edited"
			HELP 536
		LET prog = choose_file()
		IF prog IS NULL THEN
			EXIT MENU
		END IF
		CALL show_file()

	COMMAND KEY('!')
		CALL shell_escape()

	COMMAND "Exit"
			"Leave EDITING menu"
			HELP 537
		EXIT MENU

	END MENU

END FUNCTION {do_edit}

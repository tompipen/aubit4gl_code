{
	@(#)$Id: d4glform.4gl,v 1.1.1.1 2001-08-20 02:37:06 afalout Exp $
	@(#)Alternative D4GL compiling front-end
	@(#)Form compiling functions
	@(#)Author: JL
}

GLOBALS "d4glglob.4gl"

FUNCTION form_compile_menu()

	MENU "FORM EDITING"

	COMMAND KEY('!')
		CALL shell_escape()

	COMMAND "Compile"
			"Compile current form"
			HELP 80
		CALL form_compile_cycle()
		NEXT OPTION "Build"
		CALL check_interrupt()

	COMMAND "Modify"
			"Modify current form"
			HELP 81
		IF form_modify_cycle() = 'Y' THEN
			NEXT OPTION "Build"
		ELSE
			NEXT OPTION "Form"
		END IF
		CALL check_interrupt()

	COMMAND "Form"
			"Change name of current form"
			HELP 82
		CALL set_formname()
		NEXT OPTION "Modify"
		CALL check_interrupt()

	COMMAND "Build"
			"Run MAKE on program"
			HELP 83
		IF run_make() = 0 THEN
			NEXT OPTION "Run"
		ELSE
			NEXT OPTION "Modify"
		END IF
		CALL check_interrupt()

	COMMAND "Run"
			"Run program"
			HELP 84
		CALL run_prog()
		CALL check_interrupt()

	COMMAND "Options"
			"Alter program controls"
			HELP 85
		CALL form_options_menu()
		CALL check_interrupt()

	COMMAND "Program"
			"Change name of current program"
			HELP 86
		CALL set_progname()
		NEXT OPTION "Run"
		CALL check_interrupt()

	COMMAND "Exit"
			"Exit FORM COMPILER menu"
			HELP 87
		EXIT MENU

	END MENU

END FUNCTION {form_compile_menu}

FUNCTION form_options_menu()

	MENU "FORM OPTIONS"

	COMMAND KEY('!')
		CALL shell_escape()

	COMMAND "Compiler"
			"Specify name of form compiler"
			HELP 90
		LET form_prog = get_input("Enter name of form compiler:", form_prog)
		CALL show_state()
		CALL check_interrupt()
		EXIT MENU

	COMMAND "Options"
			"Specify special flags for form compiler"
			HELP 91
		LET form_opts = get_input("Enter flags for form compiler:", form_opts)
		CALL show_state()
		CALL check_interrupt()
		EXIT MENU

	COMMAND "Build"
			"Specify name of MAKE program"
			HELP 92
		LET make_prog = get_input("Enter name of MAKE program:", make_prog)
		CALL show_state()
		CALL check_interrupt()
		EXIT MENU

	COMMAND "Target"
			"Specify target to be made by MAKE program"
			HELP 93
		LET make_targ = get_input("Enter target for MAKE:", make_targ)
		CALL show_state()
		CALL check_interrupt()
		EXIT MENU

	COMMAND "Flags"
			"Specify special flags for MAKE program"
			HELP 94
		LET make_opts = get_input("Enter flags for MAKE:", make_opts)
		CALL show_state()
		CALL check_interrupt()
		EXIT MENU

	COMMAND "Makefile"
			"Specify name of makefile"
			HELP 95
		LET make_file = get_input("Enter name of makefile:", make_file)
		CALL show_state()
		CALL check_interrupt()
		EXIT MENU

	COMMAND "Visual"
			"Specify name of editor"
			HELP 96
		LET edit_prog = get_input("Enter name of editor program:", edit_prog)
		CALL set_editopts()
		CALL show_state()
		CALL check_interrupt()
		EXIT MENU

	COMMAND "Exit"
			"Exit FORM OPTIONS menu"
			HELP 97
		CALL check_interrupt()
		EXIT MENU

	END MENU

END FUNCTION {form_options_menu}

FUNCTION set_formname()

	DEFINE
		i		INTEGER,
		j		INTEGER

	LET form_mode = 0
	LET form_name = get_input("Enter name of form file", form_name)
	IF form_name IS NOT NULL THEN
		LET i = find_string(form_name, form_ext1)
		LET j = find_string(form_name, form_ext2)
		IF i = 0 AND j = 0 THEN
			LET form_name = form_name CLIPPED, form_ext1
		END IF
	END IF
	CALL show_state()

END FUNCTION {set_formname}

FUNCTION form_compile_cycle()

	DEFINE
		s		INTEGER

	IF form_name IS NULL THEN
		CALL set_formname()
	END IF
	IF form_name IS NULL THEN
		RETURN
	END IF

	WHILE form_compile() != 0

		MENU "FAILED TO COMPILE"

		COMMAND KEY('!')
			CALL shell_escape()

		COMMAND "Correct"
				"Use the editor to correct any mistakes"
				HELP 100
			IF form_correct() = 'N' THEN
				RETURN
			END IF
			CALL check_interrupt()
			EXIT MENU

		COMMAND "Save-and-Exit"
				"Save current version of file and exit"
				HELP 101
			CALL save_form()
			CALL check_interrupt()
			RETURN

		COMMAND "Discard-and-Exit"
				"Discard current version of file (and any changes) and exit"
				HELP 102
			CALL form_discard()
			CALL check_interrupt()
			RETURN

		END MENU

	END WHILE

	MENU "COMPILATION SUCCEEDED"

	COMMAND KEY('!')
		CALL shell_escape()

	COMMAND "Save-and-Exit"
			"Save current version of file and exit"
			HELP 110
		CALL save_form()
		CALL check_interrupt()
		EXIT MENU

	COMMAND "Discard-and-Exit"
			"Discard current version of file (and any changes) and exit"
			HELP 111
		CALL form_discard()
		CALL check_interrupt()
		EXIT MENU

	END MENU

END FUNCTION {form_compile_cycle}

FUNCTION form_correct()

	DEFINE
		cflag	CHAR(1)

	LET cflag = 'Y'

	LET cflag = edit_errform()
	IF cflag = 'N' THEN
		RETURN 'N'
	END IF

	MENU "COMPILE"

	COMMAND KEY('!')
		CALL shell_escape()

	COMMAND "Compile"
			"Compile modified version of file"
			HELP 120
		CALL check_interrupt()
		EXIT MENU

	COMMAND "Save-and-Exit"
			"Save current version of file but do not compile it"
			HELP 121
		CALL save_form()
		CALL check_interrupt()
		LET cflag = 'N'
		EXIT MENU

	COMMAND "Discard-and-Exit"
			"Discard current version of file (and any changes) and exit"
			HELP 122
		CALL form_discard()
		CALL check_interrupt()
		LET cflag = 'N'
		EXIT MENU

	END MENU

	RETURN cflag

END FUNCTION {form_correct}

FUNCTION edit_errform()

	DEFINE
		cmd			CHAR(80),
		cmd_status	INTEGER

	IF form_save = FALSE THEN
		IF form_backup() = FALSE THEN
			RETURN 'N'
		END IF
	END IF

	CALL set_errform()
	LET form_mode = 1		{ Editing .err file }
	LET cmd = edit_prog CLIPPED, " ", edit_opts CLIPPED, " ", form_errs CLIPPED
	LET cmd_status = run_cmd(cmd)

	RETURN 'Y'

END FUNCTION {edit_errform}

FUNCTION form_edit()

	DEFINE
		cmd			CHAR(80),
		cmd_status	INTEGER

	IF form_name IS NULL THEN
		CALL set_formname()
	END IF
	IF form_name IS NULL THEN
		RETURN 'N'
	END IF

	IF form_save = FALSE THEN
		IF form_backup() = FALSE THEN
			RETURN 'N'
		END IF
	END IF

	LET cmd = edit_prog CLIPPED, " ", form_name CLIPPED
	LET cmd_status = run_cmd(cmd)

	RETURN 'Y'

END FUNCTION {form_edit}

FUNCTION form_modify_cycle()

	DEFINE
		flag	CHAR(1)

	IF form_mode = 0 THEN
		LET flag = form_edit()
	ELSE
		LET flag = edit_errform()
	END IF

	IF flag = 'N' THEN
		RETURN 'N'
	END IF

	CALL d4gl_init()

	MENU "FORM COMPILE"

	COMMAND KEY('!')
		CALL shell_escape()

	COMMAND "Compile"
			"Compile file"
			HELP 130
		CALL form_compile_cycle()
		CALL check_interrupt()
		EXIT MENU

	COMMAND "Save-and-Exit"
			"Save current version of file but do not compile it"
			HELP 131
		CALL save_form()
		CALL check_interrupt()
		EXIT MENU

	COMMAND "Discard-and-Exit"
			"Discard current version of file (and any changes) and exit"
			HELP 132
		CALL form_discard()
		CALL check_interrupt()
		EXIT MENU

	END MENU

	RETURN 'Y'

END FUNCTION {form_modify_cycle}

FUNCTION form_restore()

	DEFINE
		cmd			CHAR(80)

	-- Copy edited error file over source file
	-- D4GL form compiler generates | to mark errors
	-- I4GL form compiler generates # to mark errors
	LET cmd = "sed '/^[|#]/d' ", form_errs CLIPPED, " >", form_name CLIPPED
	RUN cmd
	LET cmd = "rm -f ", form_errs CLIPPED
	RUN cmd
	LET form_mode = 0

END FUNCTION {form_restore}

FUNCTION form_compile()

	DEFINE
		cmd			CHAR(80),
		cmd_status	INTEGER

	IF form_mode = 1 THEN
		CALL form_restore()
	END IF

	LET cmd = form_prog CLIPPED, " ", form_opts CLIPPED
	LET cmd = cmd CLIPPED, " ", form_name CLIPPED

	LET cmd_status = run_cmd(cmd)

	RETURN cmd_status

END FUNCTION {form_compile}

FUNCTION form_discard()

	DEFINE
		cmd			CHAR(80)

	IF form_save = TRUE THEN
		LET cmd = "cp ", form_back CLIPPED, " ", form_name CLIPPED,
					"; rm -f ", form_back CLIPPED
		RUN cmd
		LET form_save = FALSE
	END IF

END FUNCTION {form_discard}

FUNCTION save_form()

	DEFINE
		cmd			CHAR(80)

	IF form_mode = TRUE THEN
		CALL form_restore()	{ Copy error file back over source file }
	END IF

	IF form_save = TRUE THEN
		LET cmd = "rm -f ", form_back CLIPPED
		RUN cmd
		LET form_save = FALSE
	END IF

END FUNCTION {save_form}

FUNCTION form_backup()

	DEFINE
		cmd			CHAR(80),
		retval		INTEGER

	CALL set_backupform()

	CASE
	WHEN is_a_file(form_name) = FALSE
		LET retval = TRUE
	WHEN NOT is_file_writeable(form_name)
		ERROR "File ", form_name CLIPPED, " is not writeable"
		SLEEP 2
		LET retval = FALSE
	OTHERWISE
		LET cmd = "rm -f ", form_back CLIPPED, "; cp ", form_name CLIPPED, " ",
					form_back CLIPPED
		RUN cmd
		LET form_save = TRUE
		LET retval = TRUE
	END CASE

	RETURN retval

END FUNCTION {form_backup}

FUNCTION set_backupform()

	DEFINE
		i		INTEGER

	LET i = find_string(form_name, form_ext1)
	IF i = 0 THEN
		LET i = find_string(form_name, form_ext2)
	END IF
	IF i > 1 THEN
		LET i = i - 1
		LET form_back = form_name[1, i], form_bext
	ELSE
		LET form_back = NULL
	END IF

END FUNCTION {set_backupform}

FUNCTION set_errform()

	DEFINE
		i		INTEGER

	LET i = find_string(form_name, form_ext1)
	IF i = 0 THEN
		LET i = find_string(form_name, form_ext2)
	END IF
	IF i > 1 THEN
		LET i = i - 1
		LET form_errs = form_name[1, i], form_eext
	ELSE
		LET form_errs = NULL
	END IF

END FUNCTION {set_errform}

FUNCTION form_check()

	DEFINE
		cmd			CHAR(80),
		i			INTEGER,
		cmd_status	INTEGER

	LET i = find_string(form_name, form_ext1)
	IF i = 0 THEN
		LET i = find_string(form_name, form_ext2)
	END IF
	IF i = 0 THEN
		DISPLAY usestr CLIPPED
		EXIT PROGRAM 1
	END IF

	CALL set_errform()
	LET cmd_status = file_access(form_errs, 4)	-- File exists and is readable

	IF cmd_status = 0 THEN
		LET form_mode = 1	{ .err exists }
	ELSE
		LET form_mode = 0
	END IF

END FUNCTION {form_check}


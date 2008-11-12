{
	@(#)$Id: d4glfile.4gl,v 1.1.1.1 2001-08-20 02:37:06 afalout Exp $
	@(#)Alternative D4GL compiling front-end
	@(#)Control Program and support routines
	@(#)Author: JL
}

GLOBALS "d4glglob.4gl"

FUNCTION file_compile_menu()

	MENU "SOURCE EDITING"

	COMMAND KEY('!')
		CALL shell_escape()

	COMMAND "Compile"
			"Compile current module"
			HELP 20
		CALL file_compile_cycle()
		NEXT OPTION "Build"
		CALL check_interrupt()

	COMMAND "Modify"
			"Modify current module"
			HELP 21
		IF file_modify_cycle() = 'Y' THEN
			NEXT OPTION "Build"
		ELSE
			NEXT OPTION "File"
		END IF
		CALL check_interrupt()

	COMMAND "File"
			"Change name of current file"
			HELP 22
		CALL set_filename()
		NEXT OPTION "Modify"
		CALL check_interrupt()

	COMMAND "Build"
			"Run MAKE on program"
			HELP 23
		IF run_make() = 0 THEN
			NEXT OPTION "Run"
		ELSE
			NEXT OPTION "Modify"
		END IF
		CALL check_interrupt()

	COMMAND "Run"
			"Run program"
			HELP 24
		CALL run_prog()
		CALL check_interrupt()

	COMMAND "Options"
			"Alter program controls"
			HELP 25
		CALL file_options_menu()
		CALL check_interrupt()

	COMMAND "Program"
			"Change name of current program"
			HELP 26
		CALL set_progname()
		NEXT OPTION "Run"
		CALL check_interrupt()

	COMMAND "Exit"
			"Exit D4GL COMPILER menu"
			HELP 27
		EXIT MENU

	END MENU

END FUNCTION {file_compile_menu}

FUNCTION file_options_menu()

	MENU "D4GL OPTIONS"

	COMMAND KEY('!')
		CALL shell_escape()

	COMMAND "Compiler"
			"Specify name of D4GL compiler"
			HELP 30
		LET file_prog = get_input("Enter name of compiler:", file_prog)
		CALL show_state()
		CALL check_interrupt()
		EXIT MENU

	COMMAND "Options"
			"Specify special flags for D4GL compiler"
			HELP 31
		LET file_opts = get_input("Enter flags for D4GL:", file_opts)
		CALL show_state()
		CALL check_interrupt()
		EXIT MENU

	COMMAND "Build"
			"Specify name of MAKE program"
			HELP 32
		LET make_prog = get_input("Enter name of MAKE program:", make_prog)
		CALL show_state()
		CALL check_interrupt()
		EXIT MENU

	COMMAND "Target"
			"Specify target to be made by MAKE program"
			HELP 33
		LET make_targ = get_input("Enter target for MAKE:", make_targ)
		CALL show_state()
		CALL check_interrupt()
		EXIT MENU

	COMMAND "Flags"
			"Specify special flags for MAKE program"
			HELP 34
		LET make_opts = get_input("Enter flags for MAKE:", make_opts)
		CALL show_state()
		CALL check_interrupt()
		EXIT MENU

	COMMAND "Makefile"
			"Specify name of makefile"
			HELP 35
		LET make_file = get_input("Enter name of makefile:", make_file)
		CALL show_state()
		CALL check_interrupt()
		EXIT MENU

	COMMAND "Visual"
			"Specify name of editor"
			HELP 36
		LET edit_prog = get_input("Enter name of editor program:", edit_prog)
		CALL set_editopts()
		CALL show_state()
		CALL check_interrupt()
		EXIT MENU

	COMMAND "Exit"
			"Exit D4GL OPTIONS menu"
			HELP 37
		CALL check_interrupt()
		EXIT MENU

	END MENU

END FUNCTION {file_options_menu}

FUNCTION set_filename()

	DEFINE
		i		INTEGER,
		j		INTEGER

	LET file_mode = 0
	LET file_name = get_input("Enter name of D4GL source file", file_name)
	IF file_name IS NOT NULL THEN
		LET i = find_string(file_name, file_ext1)
		LET j = find_string(file_name, file_ext2)
		IF i = 0 AND j = 0 THEN
			LET file_name = file_name CLIPPED, file_ext1
		END IF
	END IF
	CALL show_state()

END FUNCTION {set_filename}

FUNCTION file_compile_cycle()

	DEFINE
		s		INTEGER

	IF file_name IS NULL THEN
		CALL set_filename()
	END IF
	IF file_name IS NULL THEN
		RETURN
	END IF

	WHILE file_compile() != 0

		MENU "FAILED TO COMPILE"

		COMMAND KEY('!')
			CALL shell_escape()

		COMMAND "Correct"
				"Use the editor to correct any mistakes"
				HELP 40
			IF file_correct() = 'N' THEN
				RETURN
			END IF
			CALL check_interrupt()
			EXIT MENU

		COMMAND "Save-and-Exit"
				"Save current version of file and exit"
				HELP 41
			CALL save_file()
			CALL check_interrupt()
			RETURN

		COMMAND "Discard-and-Exit"
				"Discard current version of file (and any changes) and exit"
				HELP 42
			CALL file_discard()
			CALL check_interrupt()
			RETURN

		END MENU

	END WHILE

	MENU "COMPILATION SUCCEEDED"

	COMMAND KEY('!')
		CALL shell_escape()

	COMMAND "Save-and-Exit"
			"Save current version of file and exit"
			HELP 50
		CALL save_file()
		CALL check_interrupt()
		EXIT MENU

	COMMAND "Discard-and-Exit"
			"Discard current version of file (and any changes) and exit"
			HELP 51
		CALL file_discard()
		CALL check_interrupt()
		EXIT MENU

	END MENU

END FUNCTION {file_compile_cycle}

FUNCTION file_correct()

	DEFINE
		cflag	CHAR(1)

	LET cflag = 'Y'

	LET cflag = edit_errfile()
	IF cflag = 'N' THEN
		RETURN 'N'
	END IF

	MENU "COMPILE"

	COMMAND KEY('!')
		CALL shell_escape()

	COMMAND "Compile"
			"Compile modified version of file"
			HELP 60
		CALL check_interrupt()
		EXIT MENU

	COMMAND "Save-and-Exit"
			"Save current version of file but do not compile it"
			HELP 61
		CALL save_file()
		CALL check_interrupt()
		LET cflag = 'N'
		EXIT MENU

	COMMAND "Discard-and-Exit"
			"Discard current version of file (and any changes) and exit"
			HELP 62
		CALL file_discard()
		CALL check_interrupt()
		LET cflag = 'N'
		EXIT MENU

	END MENU

	RETURN cflag

END FUNCTION {file_correct}

FUNCTION edit_errfile()

	DEFINE
		cmd			CHAR(80),
		cmd_status	INTEGER

	IF file_save = FALSE THEN
		IF file_backup() = FALSE THEN
			RETURN 'N'
		END IF
	END IF

	CALL set_errfile()
	LET file_mode = 1		{ Editing .err file }
	LET cmd = edit_prog CLIPPED, " ", edit_opts CLIPPED, " ", file_errs CLIPPED
	LET cmd_status = run_cmd(cmd)

	RETURN 'Y'

END FUNCTION {edit_errfile}

FUNCTION file_edit()

	DEFINE
		cmd			CHAR(80),
		cmd_status	INTEGER

	IF file_name IS NULL THEN
		CALL set_filename()
	END IF
	IF file_name IS NULL THEN
		RETURN 'N'
	END IF

	IF file_save = FALSE THEN
		IF file_backup() = FALSE THEN
			RETURN 'N'
		END IF
	END IF

	LET cmd = edit_prog CLIPPED, " ", file_name CLIPPED
	LET cmd_status = run_cmd(cmd)

	RETURN 'Y'

END FUNCTION {file_edit}

FUNCTION file_modify_cycle()

	DEFINE
		flag	CHAR(1)

	IF file_mode = 0 THEN
		LET flag = file_edit()
	ELSE
		LET flag = edit_errfile()
	END IF

	IF flag = 'N' THEN
		RETURN 'N'
	END IF

	CALL d4gl_init()

	MENU "COMPILE"

	COMMAND KEY('!')
		CALL shell_escape()

	COMMAND "Compile"
			"Compile file"
			HELP 70
		CALL file_compile_cycle()
		CALL check_interrupt()
		EXIT MENU

	COMMAND "Save-and-Exit"
			"Save current version of file but do not compile it"
			HELP 71
		CALL save_file()
		CALL check_interrupt()
		EXIT MENU

	COMMAND "Discard-and-Exit"
			"Discard current version of file (and any changes) and exit"
			HELP 72
		CALL file_discard()
		CALL check_interrupt()
		EXIT MENU

	END MENU

	RETURN 'Y'

END FUNCTION {file_modify_cycle}

FUNCTION file_restore()

	DEFINE
		cmd			CHAR(80)

	{ Copy edited error file over source file }
	LET cmd = "sed '/^|/d' ", file_errs CLIPPED, " >", file_name CLIPPED
	RUN cmd
	LET cmd = "rm -f ", file_errs CLIPPED
	RUN cmd
	LET file_mode = 0

END FUNCTION {file_restore}

FUNCTION file_compile()

	DEFINE
		cmd			CHAR(80),
		cmd_status	INTEGER

	IF file_mode = 1 THEN
		CALL file_restore()
	END IF

	LET cmd = file_prog CLIPPED, " -c ", file_opts CLIPPED, " ",
				file_name CLIPPED

	LET cmd_status = run_cmd(cmd)

	RETURN cmd_status

END FUNCTION {file_compile}

FUNCTION file_discard()

	DEFINE
		cmd			CHAR(80)

	IF file_save = TRUE THEN
		LET cmd = "cp ", file_back CLIPPED, " ", file_name CLIPPED,
					"; rm -f ", file_back CLIPPED
		RUN cmd
		LET file_save = FALSE
	END IF

END FUNCTION {file_discard}

FUNCTION save_file()

	DEFINE
		cmd			CHAR(80)

	IF file_mode = TRUE THEN
		CALL file_restore()	{ Copy error file back over source file }
	END IF

	IF file_save = TRUE THEN
		LET cmd = "rm -f ", file_back CLIPPED
		RUN cmd
		LET file_save = FALSE
	END IF

END FUNCTION {save_file}

FUNCTION file_backup()

	DEFINE
		cmd			CHAR(80),
		retval		INTEGER

	CALL set_backupfile()

	CASE
	WHEN is_a_file(file_name) = FALSE
		LET retval = TRUE
	WHEN NOT is_file_writeable(file_name)
		ERROR "File ", file_name CLIPPED, " is not writeable"
		SLEEP 2
		LET retval = FALSE
	OTHERWISE
		LET cmd = "rm -f ", file_back CLIPPED, "; cp ", file_name CLIPPED, " ",
					file_back CLIPPED
		RUN cmd
		LET file_save = TRUE
		LET retval = TRUE
	END CASE

	RETURN retval

END FUNCTION {file_backup}

FUNCTION set_backupfile()

	DEFINE
		i		INTEGER

	LET i = find_string(file_name, file_ext1)
	IF i = 0 THEN
		LET i = find_string(file_name, file_ext2)
	END IF
	IF i > 1 THEN
		LET i = i - 1
		LET file_back = file_name[1, i], file_bext
	ELSE
		LET file_back = NULL
	END IF

END FUNCTION {set_backupfile}

FUNCTION set_errfile()

	DEFINE
		i		INTEGER

	LET i = find_string(file_name, file_ext1)
	IF i = 0 THEN
		LET i = find_string(file_name, file_ext2)
	END IF
	IF i > 1 THEN
		LET i = i - 1
		LET file_errs = file_name[1, i], file_eext
	ELSE
		LET file_errs = NULL
	END IF

END FUNCTION {set_errfile}

FUNCTION file_check()

	DEFINE
		cmd			CHAR(80),
		i			INTEGER,
		cmd_status	INTEGER

	LET i = find_string(file_name, file_ext1)
	IF i = 0 THEN
		LET i = find_string(file_name, file_ext2)
	END IF
	IF i = 0 THEN
		DISPLAY usestr CLIPPED
		EXIT PROGRAM 1
	END IF

	CALL set_errfile()
	LET cmd_status = file_access(file_errs, 4)	-- File exists and is readable

	IF cmd_status = 0 THEN
		LET file_mode = 1	{ .err exists }
	ELSE
		LET file_mode = 0
	END IF

END FUNCTION {file_check}


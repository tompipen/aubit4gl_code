{
	@(#)$Id: d4glmain.4gl,v 1.1.1.1 2001-08-20 02:37:08 afalout Exp $
	@(#)Alternative D4GL compiling front-end
	@(#)Control Program and support routines
	@(#)Author: JL
}

GLOBALS "d4glglob.4gl"

DEFINE
	arg0		CHAR(20),	{ Name of program }
	prog_vers	CHAR(20),	{ Program version }
	disp_mode	INTEGER 	{ Form displayed? }
DEFINE
	wind_prfx	CHAR(40),
	wind_sffx	CHAR(40)

MAIN

	DEFINE
		rcs		CHAR(1),
		nfiles	INTEGER,
		iflag	CHAR(1),
		junk	CHAR(1),
		optstr	CHAR(20),
		optval	CHAR(1),
		optarg	CHAR(80)

	DEFER INTERRUPT
--# CALL fgl_init4js()
	OPTIONS PROMPT LINE 24
	CALL set_defaults()

	LET prog_vers = rcs_munge("D4GL $Revision: 1.1.1.1 $ $Date: 2001-08-20 02:37:08 $")
	LET rcs       = "@(#)$Id: d4glmain.4gl,v 1.1.1.1 2001-08-20 02:37:08 afalout Exp $"
	LET optstr    = "c:f:im:b:p:t:"
	LET nfiles    = 0
	LET iflag     = 'N'
	LET optval    = ' '

	WHILE optval IS NOT NULL
		CALL i4gl_getopt(optstr) RETURNING optval, optarg
		IF optval IS NULL THEN
			EXIT WHILE
		END IF
		CASE
		WHEN optval = 'c'
			LET file_prog = optarg
		WHEN optval = 'f'
			LET form_prog = optarg
		WHEN optval = 'i'
			LET iflag = 'Y'
		WHEN optval = 'm' or optval = 'b'
			LET make_prog = optarg
		WHEN optval = 'p'
			LET prog_name = optarg
		WHEN optval = 't'
			LET make_targ = optarg
		WHEN optval = '-'
			LET file_name = optarg
			CALL file_check()
			LET junk = file_modify_cycle()
			LET nfiles = nfiles + 1
		OTHERWISE
			DISPLAY usestr CLIPPED
			EXIT PROGRAM 1
		END CASE
	END WHILE

	IF nfiles = 0 OR iflag = 'Y' THEN
		CALL d4gl_init()
		CALL main_menu()
	END IF

	CALL d4gl_fini()
	EXIT PROGRAM 0

END MAIN

FUNCTION main_menu()

	MENU "MAIN MENU"

	COMMAND "Module"
			"Editing and compiling D4GL source files"
			HELP 2
		CALL file_compile_menu()
		NEXT OPTION "Build"

	COMMAND "Form"
			"Editing and compiling D4GL form files"
			HELP 3
		CALL form_compile_menu()
		NEXT OPTION "Build"
		CALL check_interrupt()

	COMMAND "Program"
			"Change name of current program"
			HELP 4
		CALL set_progname()
		NEXT OPTION "Build"
		CALL check_interrupt()

	COMMAND "Build"
			"Run MAKE on program"
			HELP 5
		IF run_make() = 0 THEN
			NEXT OPTION "Run"
		ELSE
			NEXT OPTION "Module"
		END IF
		CALL check_interrupt()

	COMMAND "Run"
			"Run program"
			HELP 6
		CALL run_prog()
		CALL check_interrupt()

	COMMAND "Options"
			"MAKE and RUN options"
			HELP 8
		CALL main_options_menu()
		CALL check_interrupt()

	COMMAND KEY('!')
		CALL shell_escape()

	COMMAND "Exit"
			"Exit MAIN MENU"
			HELP 7
		EXIT MENU

	END MENU

END FUNCTION {main_menu}

FUNCTION main_options_menu()

	MENU "D4GL OPTIONS"

	COMMAND KEY('!')
		CALL shell_escape()

	COMMAND "Program"
			"Change name of current program"
			HELP 4
		CALL set_progname()
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

END FUNCTION {main_options_menu}


FUNCTION chop_suffix(arg, sfx)

	DEFINE
		arg	CHAR(80),
		sfx	CHAR(4),
		len		INTEGER,
		i		INTEGER,
		j 		INTEGER

	LET i = find_string(arg, sfx)
	IF i > 0 THEN
		LET len = LENGTH(arg)
		FOR j = i TO len
			LET arg[j] = " "
		END FOR
	END IF

	RETURN arg

END FUNCTION {chop_suffix}

FUNCTION set_arg0()

	DEFINE
		arg		CHAR(80),
		len		INTEGER,
		i		INTEGER

	LET arg = ARG_VAL(0)
	LET arg = chop_suffix(arg, ".4ge")
	LET arg = chop_suffix(arg, ".4gi")
	LET arg = chop_suffix(arg, ".42r")
	LET arg = chop_suffix(arg, ".42e")

	LET i = instring(arg, '/')
	WHILE i > 0
		LET len = LENGTH(arg)
		LET i = i + 1
		LET arg = arg[i, len]
		LET i = instring(arg, '/')
	END WHILE

	RETURN arg

END FUNCTION {set_arg0}

FUNCTION is_a_file(file_name)

	DEFINE
		file_name	CHAR(80),
		cmd			CHAR(80),
		cmd_status	INTEGER

	IF file_name IS NOT NULL AND file_name != " " THEN
		LET cmd_status = file_access(file_name, 4) -- File is readable
	ELSE
		LET cmd_status = 1
	END IF

	RETURN (cmd_status = 0)

END FUNCTION {is_a_file}

FUNCTION is_file_writeable(file_name)

	DEFINE
		file_name	CHAR(80),
		cmd			CHAR(80),
		cmd_status	INTEGER

	LET cmd_status = file_access(file_name, 2) -- File is writeable

	RETURN (cmd_status = 0)

END FUNCTION {is_file_writeable}

FUNCTION get_input(pstring, istring)

	DEFINE
		pstring		CHAR(80),	{ Prompt }
		istring		CHAR(80),	{ Initial value }
		nstring		CHAR(80)	{ New value }

--# IF fgl_fglgui() THEN
--# 	OPEN WINDOW w_d4gl2 AT 23, 2
--# 		WITH 2 ROWS, 74 COLUMNS
--# 		ATTRIBUTE (FORM LINE FIRST, COMMENT LINE LAST, BORDER)
--# ELSE
		OPEN WINDOW w_d4gl2 AT 22, 2
			WITH 2 ROWS, 74 COLUMNS
			ATTRIBUTE (FORM LINE FIRST, COMMENT LINE LAST)
--# END IF

	OPEN FORM f_d4gl2 FROM "d4glinpt"
	DISPLAY FORM f_d4gl2

	LET INT_FLAG = FALSE
	LET nstring = istring

	DISPLAY pstring CLIPPED AT 1, 2

	INPUT nstring WITHOUT DEFAULTS FROM FORMONLY.input_field HELP 10

	IF INT_FLAG = TRUE THEN
		LET INT_FLAG = FALSE
		LET nstring = istring
	END IF

	CLOSE FORM f_d4gl2
	CLOSE WINDOW w_d4gl2

	RETURN nstring

END FUNCTION {get_input}

FUNCTION run_make()

	DEFINE
		cmd			CHAR(80),
		cmd_status	INTEGER

	LET cmd = make_prog CLIPPED, " ", make_opts CLIPPED
	IF make_file != "makefile" THEN
		LET cmd = cmd CLIPPED, " -f ", make_file CLIPPED
	END IF
	LET cmd = cmd CLIPPED, " ", make_targ CLIPPED

	LET cmd_status = run_cmd(cmd)

	RETURN cmd_status

END FUNCTION {run_make}

FUNCTION run_cmd(cmd)

	DEFINE
		cmd			CHAR(120),
		cmd_status	INTEGER

	IF disp_mode != 0 THEN
		MESSAGE cmd
	END IF

--# IF fgl_fglgui() THEN
--# 	IF wind_prfx IS NOT NULL THEN
--# 		LET cmd = wind_prfx CLIPPED, " sh -c '", cmd CLIPPED, wind_sffx CLIPPED, "'"
--# 	END IF
--# 	CALL fgl_system(cmd)
--# ELSE
		RUN cmd RETURNING cmd_status
--# END IF

	LET INT_FLAG = FALSE

	IF disp_mode != 0 THEN
		SLEEP 1
		MESSAGE ""
	END IF

	RETURN cmd_status

END FUNCTION {run_cmd}

FUNCTION d4gl_init()

	IF disp_mode = 0 THEN
		OPEN FORM f_d4gl1 FROM "d4glopts"
		DISPLAY FORM f_d4gl1
		CALL show_state()
		OPTIONS MESSAGE LINE LAST - 1
		LET disp_mode = 1
	END IF

END FUNCTION {d4gl_init}

FUNCTION d4gl_fini()

	IF disp_mode = 1 THEN
		CLOSE FORM f_d4gl1
	END IF
	CLEAR SCREEN

END FUNCTION {d4gl_fini}

FUNCTION show_state()

	DISPLAY BY NAME
		prog_vers,
		file_name, file_prog, file_opts,
		form_name, form_prog, form_opts,
		prog_name,
		make_prog, make_opts, make_file, make_targ,
		edit_prog

END FUNCTION {show_state}

FUNCTION run_prog()

	DEFINE
		cmd_status	INTEGER

	IF prog_name IS NULL THEN
		CALL set_progname()
	END IF
	IF prog_name IS NOT NULL THEN
		LET cmd_status = run_cmd(prog_name)
	END IF

END FUNCTION {run_prog}

FUNCTION set_defaults()

	DEFINE
		env		CHAR(80)

	LET file_mode = 0		{ Editing .4gl file  }
	LET disp_mode = FALSE	{ Form not displayed }
	LET file_save = FALSE	{ File not saved yet }

--# IF TRUE THEN
--#     OPTIONS HELP FILE "d4glhelp.42h"
--# ELSE
		OPTIONS HELP FILE "d4glhelp.iem"
--# END IF

	LET arg0 = set_arg0()
	LET usestr = "Usage: ", arg0 CLIPPED,
				 "[-c fgl2p] [-m make] [-p program] [-f form4gl] [-t target] [file.4gl ...]"

	{ D4GL related options }
	LET env = fgl_getenv("D4GL_SOURCE_COMPILER")
	IF env IS NULL OR env = " " THEN
		LET file_prog = "fgl2p"
	ELSE
		LET file_prog = env
	END IF
	LET env = fgl_getenv("D4GL_SOURCE_OPTIONS")
	IF env IS NULL OR env = " " THEN
		LET file_opts = ""
	ELSE
		LET file_opts = env
	END IF

	LET file_name = ""
	LET file_ext1 = ".4gl"
	LET file_ext2 = ".XXX"
	LET file_eext = ".err"
	LET file_bext = ".4gb"

	{ Form related options }
	LET env = fgl_getenv("D4GL_FORM_COMPILER")
	IF env IS NULL OR env = " " THEN
		LET form_prog = "fglform"
	ELSE
		LET form_prog = env
	END IF
	LET env = fgl_getenv("D4GL_FORM_OPTIONS")
	IF env IS NULL OR env = " " THEN
		LET form_opts = "-q"
	ELSE
		LET form_opts = env
	END IF

	LET form_name = ""
	LET form_ext1 = ".per"
	LET form_ext2 = ".XXX"
	LET form_eext = ".err"
	LET form_bext = ".4fb"

	{ Make related options }
	LET env = fgl_getenv("D4GL_MAKE_PROGRAM")
	IF env IS NULL OR env = " " THEN
		LET env = fgl_getenv("MAKE")
		IF env IS NOT NULL THEN
			LET make_prog = env
		ELSE
			LET make_prog = "make"
		END IF
	ELSE
		LET make_prog = env
	END IF
	LET env = fgl_getenv("D4GL_MAKE_OPTIONS")
	IF env IS NULL OR env = " " THEN
		LET make_opts = ""
	ELSE
		LET make_opts = env
	END IF
	LET env = fgl_getenv("D4GL_MAKE_TARGET")
	IF env IS NULL OR env = " " THEN
		LET form_opts = ""
	ELSE
		LET form_opts = env
	END IF
	LET env = fgl_getenv("D4GL_MAKE_MAKEFILE")
	IF env IS NULL OR env = " " THEN
		LET make_file = "Makefile"
	ELSE
		LET make_file = env
	END IF

	{ Program to be run }
	LET env = fgl_getenv("D4GL_PROGRAM_NAME")
	IF env IS NULL OR env = " " THEN
		LET prog_name = ""
	ELSE
		LET prog_name = env
	END IF

	{ Editor to be used }
	LET env = fgl_getenv("D4GL_EDITOR")
	IF env IS NULL OR env = " " THEN
		LET env = fgl_getenv("DBEDIT")
		IF env IS NOT NULL THEN
			LET edit_prog = env
		ELSE
			LET env = fgl_getenv("VISUAL")
			IF env IS NOT NULL THEN
				LET edit_prog = env
			ELSE
				LET edit_prog = "vi"
			END IF
		END IF
	ELSE
		LET edit_prog = env
	END IF

	CALL set_editopts()

	{ Windowing command - prefix and suffix }
--# IF fgl_fglgui() THEN
--# 	LET env = fgl_getenv("D4GL_WINDOWCMD_PREFIX")
--# 	IF env IS NULL OR env = " " THEN
--# 		LET wind_prfx = "xterm -sb -e"
--# 	ELSE
--# 		LET wind_prfx = env
--# 	END IF
--# 	LET env = fgl_getenv("D4GL_WINDOWCMD_SUFFIX")
--# 	IF env IS NULL OR env = " " THEN
--# 		LET wind_sffx = "; sleep 5"
--# 	ELSE
--# 		LET wind_sffx = env
--# 	END IF
--# ELSE
		LET wind_prfx = ""
		LET wind_sffx = ""
--# END IF

END FUNCTION {set_defaults}

FUNCTION set_editopts()

	IF edit_prog MATCHES "*/vi" OR edit_prog = "vi" THEN
		-- D4GL form compiler generates | to mark errors
		-- I4GL form compiler generates # to mark errors
		LET edit_opts = "'+/^|/'"
		LET file_srch = "'+/^|/'"
		LET form_srch = "'+/^[|#]/'"
	ELSE
		LET edit_opts = ""
		LET file_srch = ""
		LET form_srch = ""
	END IF

END FUNCTION {set_editopts}

FUNCTION set_progname()

	LET prog_name = get_input("Enter name of D4GL program", prog_name)
	CALL show_state()

END FUNCTION {set_progname}


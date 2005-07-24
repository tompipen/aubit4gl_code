{
	@(#)fglcomp.4gl	6.1 89/08/09
	@(#)FGLBLD: Compile or run program
	@(#)Author: JL
}

GLOBALS "fglbldg.4gl"

DEFINE
	sccs	CHAR(32)

{ Compile program specified by user }
FUNCTION comp_prog()

	DEFINE
		prog		CHAR(8),
		cmd			CHAR(30),
		i4gl		CHAR(4),
		make		CHAR(14),
		c_status	INTEGER,
		ans			CHAR(1)

	LET sccs = "@(#)fglcomp.4gl	6.1 89/08/09"
	LET prog = get_file()
	IF prog IS NULL THEN
		LET prog = choose_file()
		IF prog IS NULL THEN
			LET c_status = 1
		END IF
		CALL show_file()
	END IF
	LET i4gl = getenviron("FGLBLD_I4GL")
	IF i4gl IS NULL THEN
		LET i4gl = "rds"
	END IF
	LET make = getenviron("MAKE")
	IF make IS NULL THEN
		LET make = "make"
	END IF
	IF prog IS NOT NULL THEN
		LET cmd = make CLIPPED, " -f ", prog CLIPPED, ".mk ", i4gl
		DISPLAY cmd
		RUN cmd RETURNING c_status
		PROMPT "Hit return to continue" FOR CHAR ans
	END IF

	RETURN c_status

END FUNCTION {comp_prog}

{ Run program specified by user }
FUNCTION run_prog()

	DEFINE
		prog		CHAR(8),
		cmd			CHAR(20),
		c_status	INTEGER,
		i4gl		CHAR(10),
		ans			CHAR(1)

	LET prog = get_file()
	IF prog IS NULL THEN
		LET prog = choose_file()
		IF prog IS NULL THEN
			LET c_status = 1
		END IF
		CALL show_file()
	END IF

	LET i4gl = getenviron("FGLBLD_I4GL")
	IF i4gl IS NULL OR i4gl != "c4gl" THEN
		LET cmd = "fglgo ", prog
	ELSE
		LET cmd = prog
	END IF

	IF prog IS NOT NULL THEN
		DISPLAY cmd
		RUN cmd RETURNING c_status
		PROMPT "Hit return to continue" FOR CHAR ans
	END IF

	RETURN c_status

END FUNCTION {run_prog}

-- @(#)$Id: getopt.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $
-- @(#)Purpose:     Simulate GETOPT(3) in I4GL/D4GL
-- @(#)Author:      Jonathan Leffler
-- @(#)Product:     :PRODUCT:

{
Simulate GETOPT(3) in I4GL

Operation:
When called with an argument such as "abcf:t:x", the function scans
the command line argument list for the flags -a, -b -c or -x, or options -f and
-t.  The flags are boolean values; the options have a text string associated
with them.  This can be attached to the option argument (e.g. -ffilename) or in
the next argument (-f filename).

Differences from GETOPT(3):
1.  Function returns optval (CHAR(1)) containing the flag letter and optarg
    (CHAR(80)) containing option string.  GETOPT(3) just returns the flag letter
    and the global variable optarg points to the option string.
3.  The optval returned for no more arguments is NULL.
3.  The optval returned for a non-option (filename) argument is "-".
}

DEFINE
	argind  INTEGER,	{ Where we've got through list }
	argnum  INTEGER,	{ Corresponds to ARGC }
	argstr  CHAR(80),	{ Current argument }
	arglen	INTEGER,	{ Length of current argument }
	chridx  INTEGER,	{ How far through argstr we have analysed }
	no_opt	INTEGER		{ Has `--' argument been read? }

{
Test program which also indicates how GETOPT(3) is used.

MAIN

	DEFINE
		optval	CHAR(1),
		optarg	CHAR(80)

	CALL i4gl_getopt("abcf:t:x") RETURNING optval, optarg
	WHILE optval IS NOT NULL
		DISPLAY "optval = ", optval, " optarg = ", optarg CLIPPED
		CALL i4gl_getopt("abcf:t:x") RETURNING optval, optarg
	END WHILE

END MAIN
}

FUNCTION i4gl_getopt(optstr)

	DEFINE
		optstr  CHAR(20),   { List of options as for GETOPT(3) }
		optarg  CHAR(80),   { Returned option value }
		optval  CHAR(1),    { Returned option flag }
		rcs     CHAR(1),
		idx     INTEGER

	{ Initialisation }
	IF argind <= 0 THEN
		LET argind = 1
		LET argnum = NUM_ARGS()
		LET chridx = 1
		LET arglen = 0
		LET no_opt = FALSE
		LET rcs   = "@(#)$Id: getopt.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $"
	END IF

	LET optarg = NULL
	LET optval = NULL

	WHILE TRUE

		{ Step to next argument }
		IF chridx > arglen THEN
			IF argind > argnum THEN
				EXIT WHILE
			END IF
			LET argstr = ARG_VAL(argind)
			LET arglen = LENGTH(argstr)
			LET argind = argind + 1
			LET chridx = 2
		END IF

		IF argstr[1] != "-" OR no_opt = TRUE OR arglen = 1 THEN
			{ Non-option argument }
			LET optval = "-"
			LET optarg = argstr
			LET arglen = 0
			EXIT WHILE
		END IF

		IF argstr[2] == "-" THEN
			{ '--' argument.  All following arguments are file name arguments }
			LET no_opt = TRUE
			LET arglen = 0
			CONTINUE WHILE
		END IF

		LET optval = argstr[chridx]
		LET chridx = chridx + 1
		LET idx = instring(optstr, optval)
		IF idx = 0 THEN
			{ Unknown option }
			LET optval = "?"
			EXIT WHILE
		END IF

		IF optstr[idx+1] != ":" THEN
			{ Flag-only option }
			EXIT WHILE
		END IF

		IF arglen <= chridx THEN
			{ Need to use next argument for value }
			LET optarg = ARG_VAL(argind)
			LET argind = argind + 1
			LET arglen = 0	{ Use next argument next time round }
			EXIT WHILE
		END IF

		{ Value of option attached to current argument }
		LET optarg = argstr[chridx,arglen]
		LET arglen = 0	{ Use next argument next time round }
		EXIT WHILE

	END WHILE

	RETURN optval, optarg

END FUNCTION {i4gl_getopt}

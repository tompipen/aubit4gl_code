head	2.4;
access;
symbols;
locks; strict;
comment	@# @;


2.4
date	99.03.16.17.26.04;	author jleffler;	state Exp;
branches;
next	2.3;

2.3
date	98.08.20.20.19.20;	author jleffler;	state Exp;
branches;
next	2.2;

2.2
date	98.08.20.20.17.48;	author jleffler;	state Exp;
branches;
next	2.1;

2.1
date	98.07.08.18.56.30;	author jleffler;	state Exp;
branches;
next	1.5;

1.5
date	97.10.07.18.45.40;	author johnl;	state Exp;
branches;
next	1.4;

1.4
date	90.12.17.13.46.20;	author johnl;	state Exp;
branches;
next	1.3;

1.3
date	90.09.20.14.41.15;	author john;	state Exp;
branches;
next	1.2;

1.2
date	90.08.14.15.18.23;	author john;	state Exp;
branches;
next	1.1;

1.1
date	90.07.19.10.59.20;	author john;	state Exp;
branches;
next	;


desc
@@


2.4
log
@Remove unused variable i
@
text
@-- @@(#)$Id: getopt.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $
-- @@(#)Purpose:     Simulate GETOPT(3) in I4GL/D4GL
-- @@(#)Author:      Jonathan Leffler
-- @@(#)Product:     :PRODUCT:

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
		LET rcs   = "@@(#)$Id: getopt.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $"
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
@


2.3
log
@Detab new headers
@
text
@d1 1
a1 1
-- @@(#)$Id: getopt.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $
d57 1
a57 2
		idx     INTEGER,
		i       INTEGER
d66 1
a66 1
		LET rcs   = "@@(#)$Id: getopt.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $"
@


2.2
log
@Revamp headers with :PRODUCT: information.
@
text
@d1 4
a4 4
-- @@(#)$Id: getopt.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $
-- @@(#)Purpose:		Simulate GETOPT(3) in I4GL/D4GL
-- @@(#)Author:		Jonathan Leffler
-- @@(#)Product:		:PRODUCT:
d67 1
a67 1
		LET rcs   = "@@(#)$Id: getopt.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $"
@


2.1
log
@Change sccs to rcs and Sphinx to JLSS
@
text
@d1 4
a4 6
{
	@@(#)$Id: getopt.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $
	@@(#)JLSS Informix Tools: General Library
	@@(#)Simulate GETOPT(3)
	@@(#)Author: JL
}
d67 1
a67 1
		LET rcs   = "@@(#)$Id: getopt.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $"
@


1.5
log
@Update name and avoid conflict with C getopt() information
@
text
@d2 1
a2 1
	@@(#)$Id: getopt.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $
d58 1
a58 1
		sccs	CHAR(1),
d69 1
a69 1
		LET sccs   = "@@(#)$Id: getopt.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $"
@


1.4
log
@Fix to handle -ffile -abc correctly
@
text
@d2 2
a3 2
	@@(#)$Id: getopt.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $
	@@(#)Sphinx Informix Tools: General Library
d27 1
a27 1
	optind  INTEGER,	{ Where we've got through list }
d43 1
a43 1
	CALL getopt("abcf:t:x") RETURNING optval, optarg
d46 1
a46 1
		CALL getopt("abcf:t:x") RETURNING optval, optarg
d52 1
a52 1
FUNCTION getopt(optstr)
d63 2
a64 2
	IF optind <= 0 THEN
		LET optind = 1
d69 1
a69 1
		LET sccs   = "@@(#)$Id: getopt.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $"
d79 1
a79 1
			IF optind > argnum THEN
d82 1
a82 1
			LET argstr = ARG_VAL(optind)
d84 1
a84 1
			LET optind = optind + 1
d119 2
a120 2
			LET optarg = ARG_VAL(optind)
			LET optind = optind + 1
d134 1
a134 1
END FUNCTION {getopt}
@


1.3
log
@Handle special arguments - and -- correctly
@
text
@d75 1
a75 1
	WHILE optind <= argnum
d79 3
@


1.2
log
@Upgrade to work with -abd type arguments.
Include test program as sample of how it works (embedded in a comment).
@
text
@d31 2
a32 1
	chridx  INTEGER		{ How far through argstr we have analysed }
d68 2
a69 1
		LET sccs = "@@(#)$Id: getopt.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $"
d85 1
a85 1
		IF argstr[1] != "-" THEN
d91 7
@


1.1
log
@Initial revision
@
text
@a23 2
4.  There is no provision for multiple flags in one command line argument
    (i.e. -abc is treated as -a only.  This is a BUG (aka feature)!
d29 21
a49 1
	chridx  INTEGER		{ Will be where we reached in -abc }
d54 1
a54 1
		optstr  CHAR(20),   { List of options as for GTEOPT(3) }
d56 1
a56 2
		optval  CHAR(1),     { Returned option flag }
		argstr  CHAR(80),
d59 1
a59 2
		i       INTEGER,
		l       INTEGER
d65 2
d74 9
a82 2
		LET argstr = ARG_VAL(optind)
		LET optind = optind + 1
d87 1
d91 2
a92 1
		LET optval = argstr[2]
d105 1
a105 2
		LET l = length(argstr)
		IF l <= 2 THEN
d109 1
d114 2
a115 1
		LET optarg = argstr[3,l]
@

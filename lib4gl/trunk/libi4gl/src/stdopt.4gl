head	4.7;
access;
symbols;
locks; strict;
comment	@# @;


4.7
date	91.05.09.18.12.20;	author johnl;	state Exp;
branches;
next	4.6;

4.6
date	91.05.09.14.42.48;	author johnl;	state Exp;
branches;
next	4.5;

4.5
date	90.12.12.11.18.43;	author johnl;	state Exp;
branches;
next	4.4;

4.4
date	90.08.06.16.43.45;	author john;	state Exp;
branches;
next	4.3;

4.3
date	90.03.01.18.32.39;	author john;	state Exp;
branches;
next	4.2;

4.2
date	90.02.08.17.42.29;	author john;	state Exp;
branches;
next	4.1;

4.1
date	90.02.08.11.25.37;	author john;	state Exp;
branches;
next	1.5;

1.5
date	89.08.03.09.55.17;	author john;	state Exp;
branches;
next	1.4;

1.4
date	88.02.25.16.22.44;	author john;	state Exp;
branches;
next	1.3;

1.3
date	88.02.18.11.42.38;	author john;	state Exp;
branches;
next	1.2;

1.2
date	88.02.18.11.23.47;	author john;	state Exp;
branches;
next	1.1;

1.1
date	88.02.17.17.02.00;	author john;	state Exp;
branches;
next	;


desc
@@


4.7
log
@Upgrade
@
text
@-- @@(#)$Id: stdopt.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $
-- @@(#)JLSS Informix Tools: General Library
-- @@(#)Set standard options; log messages and errors
-- @@(#)Author: JL

DEFINE
	sccs		CHAR(1),	{ SCCS version number }
	basedir		CHAR(64),	{ Base Directory of application }
	uname		CHAR(8),	{ User name }
	pname		CHAR(8)		{ Program name }

{ Set standard options, specify help file, open error log }
FUNCTION std_options(progname)

	DEFINE
		progname	CHAR(8),	# Name of program recorded in log files
		lprogname	CHAR(8),	# Lower-case version of progname
		hlpfile		CHAR(76),	# Name of help file
		logfile		CHAR(76)	# Name of log file

	{ Determine type of database which has been opened -- must be first }
	CALL set_databasetype()

	{ Set explain mode from DBEXPLAIN }
	CALL set_dbexplain()

	{ Set module variables for reuse }
	LET basedir   = get_base()
	LET sccs      = "@@(#)$Id: stdopt.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $"
	LET uname     = username()
	LET pname     = UPSHIFT(progname)
	LET lprogname = DOWNSHIFT(progname)

	IF basedir = "." THEN
		LET logfile = basedir CLIPPED, "/", lprogname CLIPPED, ".log"
		LET hlpfile = basedir CLIPPED, "/", lprogname CLIPPED, ".iem"
	ELSE
		LET logfile = basedir CLIPPED, "/log/", lprogname CLIPPED, ".log"
		LET hlpfile = basedir CLIPPED, "/msg/", lprogname CLIPPED, ".iem"
	END IF
	CALL open_logfile(logfile)
	CALL psh_helpfile(hlpfile)

	{ Security clearance }
	IF allowed_to_do(pname) = FALSE THEN
		CALL logerror("Unauthorised use")
		ERROR "Sorry!"
		SLEEP 3
		EXIT PROGRAM 1
	ELSE
		CALL logmessage("Started")
	END IF

	OPTIONS
		PROMPT  LINE LAST,
		ERROR   LINE LAST,
		MESSAGE LINE LAST - 1,
		COMMENT LINE LAST,
		HELP     KEY CONTROL-W,	{ Standard }
		INSERT   KEY F1,		{ Standard }
		DELETE   KEY F2,		{ Standard }
		NEXT     KEY F3,		{ Standard }
		PREVIOUS KEY F4,		{ Standard }
		#ACCEPT   KEY ESCAPE,	{ Standard }
		INPUT WRAP

END FUNCTION {std_options}

{ Return name of program }
FUNCTION get_progname()

	RETURN pname CLIPPED

END FUNCTION {get_progname}

{ Log a message on log file }
FUNCTION logmessage(msg)

	DEFINE
		msg		CHAR(460),
		fullmsg	CHAR(512)

	{ ERRORLOG records Date and Time anyway }
	LET fullmsg = pname CLIPPED, ": ", uname CLIPPED, ": ", msg
	WHENEVER ERROR CONTINUE
	CALL ERRORLOG(fullmsg CLIPPED)
	WHENEVER ERROR STOP

	IF STATUS != 0 THEN
		ERROR "Failed to write to log file"
		SLEEP 3
		EXIT PROGRAM 1
	END IF

END FUNCTION {logmessage}

{ Log an error message on log file }
FUNCTION logerror(msg)

	DEFINE
		msg		CHAR(460),
		fullmsg	CHAR(512)

	{ ERRORLOG records Date and Time anyway }
	LET fullmsg = pname CLIPPED, ": ", uname CLIPPED, ": <ERROR> ", msg
	WHENEVER ERROR CONTINUE
	CALL ERRORLOG(fullmsg CLIPPED)
	WHENEVER ERROR STOP

	IF STATUS != 0 THEN
		ERROR "Failed to write to log file"
		SLEEP 3
		EXIT PROGRAM 1
	END IF

END FUNCTION {logerror}

{ Is user allowed to do a update }
FUNCTION allowed_to_update()

	DEFINE
		action	CHAR(12)

	LET action = pname CLIPPED, "_UPD"

	RETURN allowed_to_do(action)

END FUNCTION {allowed_to_update}

{ Is user allowed to do a insert }
FUNCTION allowed_to_insert()

	DEFINE
		action	CHAR(12)

	LET action = pname CLIPPED, "_INS"

	RETURN allowed_to_do(action)

END FUNCTION {allowed_to_insert}

{ Is user allowed to do a delete }
FUNCTION allowed_to_delete()

	DEFINE
		action	CHAR(12)

	LET action = pname CLIPPED, "_DEL"

	RETURN allowed_to_do(action)

END FUNCTION {allowed_to_delete}
@


4.6
log
@Use BP table nomenclature
@
text
@@


4.5
log
@Fix accept key as escape
@
text
@d1 4
a4 6
{
	@@(#)$Id: stdopt.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $
	@@(#)Sphinx Informix Tools: General Library
	@@(#)Set standard options; log messages and errors
	@@(#)Author: JL
}
d7 1
d13 1
a13 1
FUNCTION std_options(progname, seclevel)
a16 1
		seclevel	CHAR(12),	# Security clearance required
d18 8
a25 3
		hlpfile		CHAR(76),
		logfile		CHAR(76),
		errstring	CHAR(40)
d29 1
a29 1
	LET uname     = "@@(#)$Id: stdopt.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $"	# SCCS branding only
d31 1
a31 1
	LET pname     = progname
d45 5
a49 10
	IF seclevel != "NONE" THEN
		IF security(seclevel) = FALSE THEN
			LET errstring = "Unauthorised use: ", seclevel
			CALL logerror(errstring)
			ERROR "Sorry!"
			SLEEP 3
			EXIT PROGRAM 1
		ELSE
			CALL logmessage("Started")
		END IF
d57 2
a58 2
		MESSAGE LINE LAST - 2,
		COMMENT LINE LAST - 1,
d69 7
d80 2
a81 2
		msg		CHAR(160),
		fullmsg	CHAR(200)
d84 1
a84 1
	LET fullmsg =	pname CLIPPED, ": ", uname CLIPPED, ": ", msg
d86 1
a86 1
	CALL ERRORLOG(fullmsg)
d101 2
a102 2
		msg		CHAR(160),
		fullmsg	CHAR(200)
d105 1
a105 1
	LET fullmsg =	pname CLIPPED, ": ", uname CLIPPED, ": <ERROR> ", msg
d107 1
a107 1
	CALL ERRORLOG(fullmsg)
d117 36
@


4.4
log
@Revise again!
@
text
@d66 1
a66 1
		ACCEPT   KEY ESCAPE ,	{ Standard }
@


4.3
log
@Fix a couple of glitches
@
text
@d4 1
a4 3
	@@(#)Set standard options, log messages and errors,
	@@(#)enable/disable insert and delete keys,
	@@(#)specify parent directory for application
a7 1
{ Global to this file -- not accessible elsewhere }
a8 1
	baseenv		CHAR(32),	{ Variable defining base directory }
d14 1
a14 1
FUNCTION std_options(basevar, progname, seclevel)
a16 1
		basevar		CHAR(32),	# Environment variable defining base directory
d24 5
a28 5
	{ Set local global variables for reuse }
	CALL set_base(basevar)
	LET uname = "@@(#)$Id: stdopt.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $"	# SCCS branding only
	LET uname = username()
	LET pname = progname
d38 2
a39 1
	CALL STARTLOG(logfile)
a43 1
			{ Should really create another string variable, but what the hell }
d67 1
a67 2
		INPUT WRAP,
		HELP FILE hlpfile
d80 1
d82 7
d101 1
d103 1
d105 4
a108 23
END FUNCTION {logerror}

{ Return base directory for application }
FUNCTION get_base()

	CALL set_base(baseenv)

	RETURN basedir

END FUNCTION {get_base}

{ Set base directory for application }
FUNCTION set_base(basevar)

	DEFINE
		basevar	CHAR(32)

	IF baseenv IS NULL OR basevar != baseenv THEN
		LET baseenv = basevar
		LET basedir = getenviron(basevar)
		IF basedir IS NULL THEN
			LET basedir = "."
		END IF
d111 1
a111 1
END FUNCTION {set_base}
@


4.2
log
@Upgrade to detect . as base directory
@
text
@d24 1
d34 1
d37 2
a38 2
		LET logfile = basedir CLIPPED, progname CLIPPED, ".log"
		LET hlpfile = basedir CLIPPED, progname CLIPPED, ".iem"
d40 2
a41 2
		LET logfile = basedir CLIPPED, "/log/", progname CLIPPED, ".log"
		LET hlpfile = basedir CLIPPED, "/msg/", progname CLIPPED, ".iem"
d118 1
a118 1
	IF basedir IS NULL OR basevar != baseenv THEN
@


4.1
log
@Generalise
@
text
@d24 3
a26 1
		filename	CHAR(76)
d34 8
a41 4
	LET filename = basedir CLIPPED, "/log/", progname CLIPPED, ".log"
	CALL STARTLOG(filename)

	LET filename = basedir CLIPPED, "/msg/", progname CLIPPED, ".iem"
d47 2
a48 2
			LET filename = "Unauthorised use: ", seclevel
			CALL logerror(filename)
d71 1
a71 1
		HELP FILE filename
@


1.5
log
@Remove KPI-isms
@
text
@d5 2
a6 2
	@@(#)Enable/disable insert and delete keys,
	@@(#)Specify parent directory for application
a9 8
{
	This file normally needs editing for a particular project.
	All references to BASEDIRECTORY need to be changed to the
	name of the environment variable which specifies the base
	directory for the project.  The default directory (initially
	/usr/base) also needs setting for each project.
}

d12 2
a13 1
	basedir		CHAR(64),	{ BASEDIRECTORY }
d18 1
a18 1
FUNCTION std_options(progname, helpfile, logfile, seclevel)
d21 1
a22 2
		helpfile	CHAR(8),	# Help message file
		logfile		CHAR(8),	# Log file
d27 1
a27 1
	CALL set_base()
d32 1
a32 1
	LET filename = basedir CLIPPED, "/log/", logfile CLIPPED, ".log"
d35 1
a35 1
	LET filename = basedir CLIPPED, "/msg/", helpfile CLIPPED, ".iem"
d38 11
a48 7
	IF security(seclevel) = FALSE THEN
		{ Should really create another string variable, but what the hell }
		LET filename = "Unauthorised use: ", seclevel
		CALL logerror(filename)
		ERROR "Sorry!"
		SLEEP 3
		EXIT PROGRAM 1
d54 12
a65 12
		HELP FILE filename,
		PROMPT LINE 24,
		MESSAGE LINE 22,
		ERROR LINE 24,		{ Standard }
		COMMENT LINE 23,	{ Standard }
		HELP KEY CONTROL-W,	{ Standard }
		INSERT KEY F1,		{ Standard }
		DELETE KEY F2,		{ Standard }
		NEXT KEY F3,		{ Standard }
		PREVIOUS KEY F4,	{ Standard }
		ACCEPT KEY ESCAPE,	{ Standard }
		INPUT WRAP
d95 1
a95 19
{ Enable insert and delete keys }
FUNCTION idk_enable()

	OPTIONS
		INSERT KEY F1,		{ Standard }
		DELETE KEY F2		{ Standard }

END FUNCTION {idk_enable}

{ Disable insert and delete keys }
FUNCTION idk_disable()

	OPTIONS
		INSERT KEY F35,		{ Non-standard }
		DELETE KEY F36		{ Non-standard }

END FUNCTION {idk_disable}

{ Return parent directory for application }
d98 1
a98 1
	CALL set_base()
d104 5
a108 2
{ Discover parent directory for application }
FUNCTION set_base()
d110 3
a112 2
	IF basedir IS NULL THEN
		LET basedir = getenviron("BASEDIRECTORY")
d114 1
a114 1
			LET basedir = "/usr/base"
@


1.4
log
@Add idk_enable/disable
@
text
@d3 1
a3 1
	@@(#)KPI Database Project: General Library
d5 2
a6 1
	@@(#)enable/disable insert and delete keys
d10 8
d20 3
a22 3
	kpidir	CHAR(64),	{ KPIDIRECTORY }
	uname	CHAR(8),	{ User name }
	pname	CHAR(8)		{ Program name }
d25 1
a25 1
FUNCTION stdoptions(applname, progname)
d28 4
a31 2
		applname	CHAR(8),
		progname	CHAR(8),
d35 2
a36 1
	LET kpidir = getenviron("KPIDIRECTORY")
d40 1
a40 1
	LET filename = kpidir CLIPPED, "/log/", applname CLIPPED, ".log"
d43 1
a43 1
	CALL logmessage("Started")
d45 11
a55 1
	LET filename = kpidir CLIPPED, "/msg/", applname CLIPPED, ".iem"
d71 1
a71 1
END FUNCTION {stdoptions}
d81 1
a81 3
	LET fullmsg =	"Program: ", pname CLIPPED,
					" User: ", uname CLIPPED,
					" ", msg
d94 1
a94 3
	LET fullmsg =	"Program: ", pname CLIPPED,
					" User: ", uname CLIPPED,
					" <ERROR> ", msg
d97 1
a97 1
END FUNCTION {logmessage}
d116 21
@


1.3
log
@Add logerror; increase string sizes
@
text
@d4 2
a5 1
	@@(#)Set standard options and log messages and errors
d15 1
d80 18
@


1.2
log
@Refine interface -- include logmessage
@
text
@d4 1
a4 1
	@@(#)Set standard options
a7 2
DATABASE KPI

d53 2
a54 2
		msg		CHAR(80),
		fullmsg	CHAR(120)
d60 15
@


1.1
log
@Initial revision
@
text
@d10 7
a16 1
FUNCTION stdoptions(applname)
d20 2
a21 2
		kpidir		CHAR(64),
		msgfile		CHAR(76)
d23 1
d25 9
a33 2
	LET msgfile = kpidir CLIPPED, "/msg/", applname CLIPPED, ".iem"
	CALL openlog(applname)
d36 1
a36 1
		HELP FILE msgfile,
d50 15
@

head	1.2;
access;
symbols;
locks; strict;
comment	@# @;


1.2
date	91.05.09.15.06.58;	author johnl;	state Exp;
branches;
next	1.1;

1.1
date	90.08.06.16.45.35;	author john;	state Exp;
branches;
next	;


desc
@@


1.2
log
@Upgrade
@
text
@-- @@(#)$Id: openlog.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $
-- @@(#)JLSS Informix Tools: General Library
-- @@(#)Open log file reasonably reliably
-- @@(#)Author: JL

FUNCTION open_logfile(filename)

	DEFINE
		filename	CHAR(64),
		cmd			CHAR(90),
		sccs		CHAR(1)

	WHENEVER ERROR CONTINUE
	CALL STARTLOG(filename)
	WHENEVER ERROR STOP

	IF STATUS != 0 THEN
		LET sccs = "@@(#)$Id: openlog.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $"
		ERROR "Failed to open log file ", filename
		SLEEP 3
		EXIT PROGRAM 1
	END IF

	LET cmd = "sh -c 'exec chmod 666 ", filename CLIPPED, " 2>&1'"
	RUN cmd

END FUNCTION {open_logfile}
@


1.1
log
@Initial revision
@
text
@d1 4
a4 6
{
	@@(#)$Id: openlog.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $
	@@(#)Sphinx Informix Tools: General Library
	@@(#)Open log file reasonably reliably
	@@(#)Author: JL
}
d10 2
a11 1
		cmd			CHAR(80)
d18 1
d24 1
a24 1
	LET cmd = "chmod 666 ", filename CLIPPED, " 2>&1"
@

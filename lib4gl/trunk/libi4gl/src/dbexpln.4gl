head	1.3;
access;
symbols;
locks; strict;
comment	@# @;


1.3
date	92.10.25.12.07.27;	author jl;	state Exp;
branches;
next	1.2;

1.2
date	91.05.09.14.41.22;	author johnl;	state Exp;
branches;
next	1.1;

1.1
date	90.11.19.17.35.36;	author johnl;	state Exp;
branches;
next	;


desc
@@


1.3
log
@Replace getenviron by fgl_getenv
@
text
@{
	@@(#)$Id: dbexpln.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $
	@@(#)JLSS Informix Tools: General Library
	@@(#)Handle SET EXPLAIN mode
}

DEFINE
	expl_mode	INTEGER,
	sccs		CHAR(1)

{ Set explain mode from DBEXPLAIN environment variable }
FUNCTION set_dbexplain()

	DEFINE
		dbexpl	CHAR(3)

	LET dbexpl = fgl_getenv("DBEXPLAIN")
	LET dbexpl = DOWNSHIFT(dbexpl)
	IF dbexpl = "on" THEN
		SET EXPLAIN ON
		LET expl_mode = 1
	ELSE
		SET EXPLAIN OFF
		LET expl_mode = 0
		LET sccs = "@@(#)$Id: dbexpln.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $"
	END IF

END FUNCTION {set_dbexplain}

{ Set explain mode }
FUNCTION set_explain(dbexpl)

	DEFINE
		dbexpl	CHAR(3)

	LET dbexpl = DOWNSHIFT(dbexpl)
	IF dbexpl = "on" THEN
		SET EXPLAIN ON
		LET expl_mode = 1
	ELSE
		SET EXPLAIN OFF
		LET expl_mode = 0
	END IF

END FUNCTION {set_explain}

{ Get current explain mode }
FUNCTION get_explain()

	RETURN expl_mode

END FUNCTION {get_explain}
@


1.2
log
@Minor upgrade
@
text
@d17 1
a17 1
	LET dbexpl = getenviron("DBEXPLAIN")
@


1.1
log
@Initial revision
@
text
@d3 1
a3 1
	@@(#)Informix General Library
@

head	1.3;
access;
symbols;
locks; strict;
comment	@# @;


1.3
date	90.04.05.11.02.03;	author john;	state Exp;
branches;
next	1.2;

1.2
date	89.08.03.09.55.15;	author john;	state Exp;
branches;
next	1.1;

1.1
date	88.02.16.13.48.13;	author john;	state Exp;
branches;
next	;


desc
@@


1.3
log
@Add sccs string
@
text
@{
	@@(#)$Id: fileextn.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $
	@@(#)Sphinx Informix Tools: General Library
	@@(#)Return file name extension
	@@(#)Author: JL
}

{
	Find extension of filename.
	Extension only counts if it is less than half the length of
	the filename.  This stops "s.frederick" being given the extension
	".frederick".  It also means "a.out" has not got an extension.
}

FUNCTION fileextn(filename)

	DEFINE
		sccs		CHAR(1),
		filename	CHAR(14),
		extn		CHAR(14),
		flen		SMALLINT,
		dotidx		SMALLINT,
		i			SMALLINT

	LET flen = LENGTH(filename)
	LET dotidx = 0
	FOR i = 1 TO flen
		IF filename[i] = '.' THEN
			LET dotidx = i
		END IF
	END FOR

	IF flen < 2 * dotidx THEN
		LET extn = filename[dotidx, flen]
	ELSE
		LET sccs = "@@(#)$Id: fileextn.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $"
		LET extn = NULL
	END IF
	RETURN extn

END FUNCTION {fileextn}
@


1.2
log
@Remove KPI-isms
@
text
@d18 1
d36 1
@


1.1
log
@Initial revision
@
text
@d3 1
a3 1
	@@(#)KPI Database Project: General Library
@

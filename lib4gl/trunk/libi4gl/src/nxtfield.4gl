head	7.1;
access;
symbols;
locks; strict;
comment	@# @;


7.1
date	91.05.09.17.56.02;	author johnl;	state Exp;
branches;
next	;


desc
@@


7.1
log
@Initial revision
@
text
@-- @@(#)$Id: nxtfield.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $
-- @@(#)JLSS Informix Tools: FGLBLD Support Library
-- @@(#)Calculate which field to go next
-- @@(#)Author: J Leffler

FUNCTION next_field(c, p, n)

	DEFINE
		c		INTEGER,		{ Current field number }
		p		INTEGER,		{ Previous field number }
		n		INTEGER,		{ Number of fields }
		df		INTEGER,		{ Difference forwards }
		db		INTEGER,		{ Difference backwards }
		nxt		INTEGER,		{ Next field number }
		sccs	CHAR(1)

	{ Normalise c }
	IF c IS NULL THEN
		LET sccs = "@@(#)$Id: nxtfield.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $"
		LET c = 0
	END IF
	IF c < 0 OR c >= n THEN
		LET c = (n + (c MOD n)) MOD n
	END IF

	{ Normalise p }
	IF p IS NULL THEN
		LET p = 0
	END IF
	IF p < 0 OR p >= n THEN
		LET p = (n + (p MOD n)) MOD n
	END IF

	LET df = (n + (c - p)) MOD n
	LET db = (n - df) MOD n

	IF df <= db THEN
		LET nxt = (c + 1) MOD n
	ELSE
		LET nxt = (n + c - 1) MOD n
	END IF

	IF nxt = 0 THEN
		LET nxt = n
	END IF

	RETURN nxt

END FUNCTION {next_field}
@

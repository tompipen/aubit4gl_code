head	1.1;
access;
symbols;
locks; strict;
comment	@# @;


1.1
date	91.07.06.22.32.29;	author jl;	state Exp;
branches;
next	;


desc
@@


1.1
log
@Initial revision
@
text
@-- @@(#)$Id: username.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $
-- @@(#)JLSS Informix Tools: General Library
-- @@(#)Get user name (assuming database is open)
-- @@(#)Author: JL

DEFINE
	user_name	CHAR(8)		-- LIKE Sysusers.Username

FUNCTION username()

	DEFINE
		sccs	CHAR(1)

	IF user_name IS NULL THEN
		LET sccs = "@@(#)$Id: username.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $"
		WHENEVER ERROR CONTINUE
		SELECT USER FROM Systables WHERE 1 = 1;
		WHENEVER ERROR STOP
		LET SQLCA.SQLCODE = 0
		LET STATUS = 0
	END IF

	RETURN user_name

END FUNCTION {username}
@

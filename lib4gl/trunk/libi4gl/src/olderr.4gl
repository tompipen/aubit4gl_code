head	1.1;
access;
symbols;
locks; strict;
comment	@# @;


1.1
date	91.11.02.23.53.21;	author jl;	state Exp;
branches;
next	;


desc
@@


1.1
log
@Initial revision
@
text
@-- @@(#)$Id: olderr.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $
-- @@(#)JLSS Informix Tools: General Library
-- @@(#)Backwards-compatability module -- error handling
-- @@(#)Author: JL

{ Terminal error to be displayed to user }
FUNCTION program_error(s)

	DEFINE
		s		CHAR(80),
		sccs	CHAR(1)

	CALL display_errtxt(s, 5, TRUE, TRUE)
	LET sccs = "@@(#)$Id: olderr.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $"

END FUNCTION {program_error}

{ Report error with no delay }
FUNCTION immediate_error(s)

	DEFINE
		s	CHAR(80)

	CALL display_errtxt(s, 0, FALSE, FALSE)

END FUNCTION {immediate_error}

{ Report error with delay }
FUNCTION notify_error(s)

	DEFINE
		s	CHAR(80)

	CALL display_errtxt(s, 3, FALSE, FALSE)

END FUNCTION {notify_error}

{ Report error number with delay }
FUNCTION notify_errno(n)

	DEFINE
		n	INTEGER

	CALL display_err4gl(n, 3, FALSE, FALSE)

END FUNCTION {notify_errno}

{ Report error number with delay }
FUNCTION notify_msgno(n)

	DEFINE
		n	INTEGER

	CALL display_errnum(n, 3, FALSE, FALSE)

END FUNCTION {notify_msgno}

{ Record error which can be survived }
FUNCTION internal_msgno(n)

	DEFINE
		n	INTEGER

	CALL display_errnum(n, 3, TRUE, FALSE)

END FUNCTION {internal_msgno}
@

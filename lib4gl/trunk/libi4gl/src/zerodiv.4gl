head	1.2;
access;
symbols;
locks; strict;
comment	@# @;


1.2
date	90.05.21.13.42.54;	author john;	state Exp;
branches;
next	1.1;

1.1
date	90.05.21.13.18.56;	author john;	state Exp;
branches;
next	;


desc
@@


1.2
log
@Add SCCS tags
@
text
@{
	@@(#)$Id: zerodiv.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $
    @@(#)Sphinx Informix Tools: General Library
	@@(#)Protect against zero-division
	@@(#)Author: JL
}

{ Do division, possibly by zero, without terminating }
FUNCTION zero_divide(dividend, divisor)

	DEFINE
		dividend	DECIMAL(32),
		divisor		DECIMAL(32),
		quotient	DECIMAL(32),
		sccs		CHAR(1)

	CASE
	WHEN dividend = 0.0 and divisor = 0.0
		LET quotient = 0.0
	WHEN divisor = 0.0
		LET quotient = NULL
	OTHERWISE
		LET quotient = dividend / divisor
	END CASE

	RETURN quotient

	LET sccs = "@@(#)$Id: zerodiv.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $"

END FUNCTION {zero_divide}
@


1.1
log
@Initial revision
@
text
@d14 2
a15 1
		quotient	DECIMAL(32)
d27 2
@

head	1.1;
access;
symbols;
locks; strict;
comment	@# @;


1.1
date	99.04.23.00.33.21;	author jleffler;	state Exp;
branches;
next	;


desc
@Determine whether given date is in a leap year
@


1.1
log
@Initial revision
@
text
@-- @@(#)$Id: leapyear.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $
-- @@(#)JLSS Informix Tools: General Library
-- @@(#)Determine whether given date is in a leap year
-- @@(#)Author: JL

FUNCTION is_leap_year(d)

	DEFINE d	DATE
	DEFINE yyyy INTEGER

	LET yyyy = YEAR(d)

	CASE
	WHEN yyyy MOD   4 != 0 RETURN FALSE
	WHEN yyyy MOD 400 == 0 RETURN TRUE
	WHEN yyyy MOD 100 == 0 RETURN FALSE
	OTHERWISE              RETURN TRUE
	END CASE

END FUNCTION
@

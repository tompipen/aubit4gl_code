head	1.1;
access;
symbols;
locks; strict;
comment	@# @;


1.1
date	91.05.17.13.20.46;	author johnl;	state Exp;
branches;
next	;


desc
@@


1.1
log
@Initial revision
@
text
@-- @@(#)$Id: incoff.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $
-- @@(#)BP Ship Vetting System
-- @@(#)Increment offset for SPI
-- @@(#)Author: JL

{ Increment offset from present value }
FUNCTION inc_offset(digit, offset, max_offset)

	DEFINE
		digit		INTEGER,
		offset		INTEGER,
		max_offset	INTEGER,
		retval		INTEGER

	IF offset > 20000000 THEN
		-- Cannot multiply by ten without overflow
		LET retval = offset
	ELSE
		LET retval = 10 * offset + digit
		IF max_offset < 10 THEN
			-- Allows for things like 3S even when there is only one row
			LET max_offset = 10
		END IF
		IF retval > max_offset THEN
			LET retval = max_offset
		END IF
	END IF

	RETURN retval

END FUNCTION {inc_offset}
@

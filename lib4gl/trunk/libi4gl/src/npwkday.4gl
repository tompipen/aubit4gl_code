head	1.1;
access;
symbols;
locks; strict;
comment	@# @;


1.1
date	91.05.10.10.12.33;	author johnl;	state Exp;
branches;
next	;


desc
@@


1.1
log
@Initial revision
@
text
@{
	@@(#)$Id: npwkday.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $
	@@(#)Next/Previous Working Day
}

FUNCTION prev_working_day(e_date)

	DEFINE
		e_date	DATE,
		r_date	DATE,
		n		INTEGER

	LET r_date = e_date - 1
	LET n = WEEKDAY(r_date)
	IF n = 0 THEN
		LET r_date = r_date - 2
	END IF
	IF n = 6 THEN
		LET r_date = r_date -1
	END IF

	RETURN r_date

END FUNCTION {prev_working_day}

FUNCTION next_working_day(e_date)

	DEFINE
		e_date	DATE,
		r_date	DATE,
		n		INTEGER

	LET r_date = e_date + 1
	LET n = WEEKDAY(r_date)
	IF n = 0 THEN
		LET r_date = r_date + 1
	END IF
	IF n = 6 THEN
		LET r_date = r_date + 2
	END IF

	RETURN r_date

END FUNCTION {next_working_day}
@

head	1.1;
access;
symbols;
locks; strict;
comment	@# @;


1.1
date	88.04.26.11.07.33;	author john;	state Exp;
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
	@@(#)$Id: moneyval.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $
	@@(#)KPI Database Project: General Library
	@@(#)Convert money quantity from string
	@@(#)Author: JL
}

{ Convert entered string to number and string: income or expense }
FUNCTION money_val(s, c)

	DEFINE
		s	CHAR(80),	# Entered string
		c	CHAR(1),	# Indicator: I income, E expense
		r	CHAR(80),	# Result string
		i	INTEGER		# Result value

	LET i = s			# type conversion
	LET r = i			# type conversion
	CASE c
	WHEN 'I'
		IF i > 0 THEN
			LET r = '+', r
		END IF
	WHEN 'E'
		IF i > 0 AND fnb(s) != '+' THEN
			LET i = -i
			LET r = '-', r
		END IF
	OTHERWISE
		ERROR "Report a money_val problem to your system administrator"
		SLEEP 3
		LET r = "0"
		LET i = 0
	END CASE

	RETURN r, i

END FUNCTION {money_val}
@

head	1.4;
access;
symbols;
locks; strict;
comment	@# @;


1.4
date	90.04.05.11.02.05;	author john;	state Exp;
branches;
next	1.3;

1.3
date	89.10.10.16.53.34;	author john;	state Exp;
branches;
next	1.2;

1.2
date	89.10.10.16.33.46;	author john;	state Exp;
branches;
next	1.1;

1.1
date	89.08.23.13.45.09;	author john;	state Exp;
branches;
next	;


desc
@@


1.4
log
@Add sccs string
@
text
@{
	@@(#)$Id: ltmonth.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $
	@@(#)Sphinx Informix Tools: General Library
	@@(#)Find last day of this month
	@@(#)Author: JL
}

FUNCTION last_of_this_month(edate)

	DEFINE
		sccs	CHAR(1),
		edate	DATE		{ Effective date (frequently TODAY) }

	IF edate IS NULL THEN
		LET sccs = "@@(#)$Id: ltmonth.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $"
		RETURN edate
	END IF

	RETURN first_of_next_month(edate) - 1

END FUNCTION {last_of_this_month}
@


1.3
log
@Add null handling -- as per manual page
@
text
@d11 1
d15 1
@


1.2
log
@Chage KPGB header to Sphinx Informix Tools
@
text
@d13 4
@


1.1
log
@Initial revision
@
text
@d3 1
a3 1
	@@(#)KPGB Sales Analysis System: General Library
@

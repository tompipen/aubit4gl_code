head	1.2;
access;
symbols;
locks; strict;
comment	@# @;


1.2
date	91.05.09.18.12.19;	author johnl;	state Exp;
branches;
next	1.1;

1.1
date	90.07.19.11.08.06;	author john;	state Exp;
branches;
next	;


desc
@@


1.2
log
@Upgrade
@
text
@-- @@(#)$Id: mbetween.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $
-- @@(#)JLSS Informix Tools: General Library
-- @@(#)Calculate the number of months between two dates
-- @@(#)Author: JL

FUNCTION months_between(d1, d2)

	DEFINE
		d1		DATE,
		d2		DATE,
		m1		DATE,
		m2		DATE,
		sccs	CHAR(1)

	LET m1 = YEAR(d1) * 12 + MONTH(d1)
	LET m2 = YEAR(d2) * 12 + MONTH(d2)

	RETURN m2 - m1

	LET sccs = "@@(#)$Id: mbetween.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $"

END FUNCTION {months_between}
@


1.1
log
@Initial revision
@
text
@d1 4
a4 6
{
	@@(#)$Id: mbetween.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $
	@@(#)Sphinx Informix Tools: General Library
	@@(#)Calculate the number of months between two dates
	@@(#)Author: JL
}
d9 5
a13 4
		d1	DATE,
		d2	DATE,
		m1	DATE,
		m2	DATE
d19 2
@

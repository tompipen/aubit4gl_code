-- @(#)$Id: mbetween.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $
-- @(#)JLSS Informix Tools: General Library
-- @(#)Calculate the number of months between two dates
-- @(#)Author: JL

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

	LET sccs = "@(#)$Id: mbetween.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $"

END FUNCTION {months_between}

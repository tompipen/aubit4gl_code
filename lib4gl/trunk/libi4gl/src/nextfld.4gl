-- @(#)$Id: nextfld.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $
-- @(#)JLSS Informix Tools
-- @(#)Calculate which field to go next

FUNCTION next_field(c, p, mn, mx)

	DEFINE
		c		INTEGER,		{ Current field number }
		p		INTEGER,		{ Previous field number }
		mn		INTEGER,		{ Minimum field number }
		mx		INTEGER 		{ Maximum field number }
	DEFINE
		sccs	CHAR(1),
		n		INTEGER,		{ Number of fields }
		df		INTEGER,		{ Difference forwards }
		db		INTEGER,		{ Difference backwards }
		nxt		INTEGER			{ Next field number }

	LET n = mx - mn + 1

	{ Normalise c }
	IF c IS NULL OR c = 0 THEN
		{ This should not happen }
		LET sccs = "@(#)$Id: nextfld.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $"
		LET c = mn
	END IF
	LET c = c - mn + 1
	IF c < 0 OR c >= n THEN
		LET c = (n + (c MOD n)) MOD n
	END IF

	{ Normalise p }
	IF p IS NULL OR p = 0 THEN
		LET p = mn
	END IF
	LET p = p - mn + 1
	IF p < 0 OR p >= n THEN
		LET p = (n + (p MOD n)) MOD n
	END IF

	LET df = (n + (c - p)) MOD n
	LET db = (n - df) MOD n

	IF df <= db THEN
		LET nxt = (c + 1) MOD n
	ELSE
		LET nxt = (n + c - 1) MOD n
	END IF

	IF nxt = 0 THEN
		LET nxt = n
	END IF

	LET nxt = nxt + mn - 1

	RETURN nxt

END FUNCTION {next_field}

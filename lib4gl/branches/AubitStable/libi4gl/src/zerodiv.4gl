{
	@(#)$Id: zerodiv.4gl,v 1.2 2002-06-14 09:23:17 afalout Exp $
    @(#)Sphinx Informix Tools: General Library
	@(#)Protect against zero-division
	@(#)Author: JL
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

	LET sccs = "@(#)$Id: zerodiv.4gl,v 1.2 2002-06-14 09:23:17 afalout Exp $"

END FUNCTION {zero_divide}

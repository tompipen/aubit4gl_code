{
	@(#)$Id: checkint.4gl,v 1.1.1.1 2001-08-20 02:37:05 afalout Exp $
	@(#)JLSS Informix Tools: General Library
	@(#)Interrupt checker
	@(#)Author: JL
}

{ Warn about ignored interrupt if interrupt has occurred }
FUNCTION check_interrupt()

	DEFINE rcs CHAR(1)

	IF int_flag != 0 THEN
		LET rcs = "@(#)$Id: checkint.4gl,v 1.1.1.1 2001-08-20 02:37:05 afalout Exp $"
		ERROR "Interrupt detected -- ignored"
		LET int_flag = 0
	END IF

END FUNCTION {check_interrupt}


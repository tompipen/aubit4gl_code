{
	@(#)$Id: checkint.4gl,v 1.2 2002-09-20 10:06:05 mikeaubury Exp $
	@(#)JLSS Informix Tools: General Library
	@(#)Interrupt checker
	@(#)Author: JL
}

{ Warn about ignored interrupt if interrupt has occurred }
FUNCTION check_interrupt()

	DEFINE rcs CHAR(1)

	IF int_flag != 0 THEN
		LET rcs = "@(#)$Id: checkint.4gl,v 1.2 2002-09-20 10:06:05 mikeaubury Exp $"
		ERROR "Interrupt detected -- ignored : ",int_flag
		LET int_flag = 0
	END IF

END FUNCTION {check_interrupt}


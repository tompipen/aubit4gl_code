-- @(#)$Id: checkint.4gl,v 1.1 2002-06-20 09:10:42 afalout Exp $
-- @(#)Purpose:     Interrupt checker
-- @(#)Author:      Jonathan Leffler
-- @(#)Product:     :PRODUCT:

{ Warn about ignored interrupt if interrupt has occurred }
FUNCTION check_interrupt()

	DEFINE rcs CHAR(1)

	IF int_flag != 0 THEN
		LET rcs = "@(#)$Id: checkint.4gl,v 1.1 2002-06-20 09:10:42 afalout Exp $"
		ERROR "Interrupt detected -- ignored"
		LET int_flag = 0
	END IF

END FUNCTION {check_interrupt}

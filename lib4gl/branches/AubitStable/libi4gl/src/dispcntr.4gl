-- @(#)$Id: dispcntr.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $
-- @(#)JLSS Informix Tools: General Library
-- @(#)Display n out of m counter
-- @(#)Author: J Leffler

FUNCTION display_counter(row_num, num_rows)

	DEFINE
		row_num		INTEGER,
		num_rows	INTEGER,
		dis_str		CHAR(13),
		sccs		CHAR(1)

	IF num_rows > 0 THEN
		LET dis_str = "--", row_num USING "&&&&", "/",
							num_rows USING "&&&&", "--"
	ELSE
		LET dis_str = " "
		LET sccs = "@(#)$Id: dispcntr.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $"
	END IF

	DISPLAY dis_str AT 1, 64

END FUNCTION {display_counter}

{
	@@(#)$Id: adjchk.4gl,v 1.1 2002-06-14 05:03:45 afalout Exp $
	@@(#)Code to check that ADJINARR works correctly
	@@(#)Uses form adjchk.frm
}

MAIN

	DEFINE
		a	ARRAY[20] OF RECORD
			j	INTEGER,
			c	CHAR(20)
			END RECORD,
		i	INTEGER,
		s	CHAR(20)

	OPEN FORM f_adjchk FROM "adjchk"
	DISPLAY FORM f_adjchk

	LET s = "ABCDEFGHIJKLMNOPQRST"
	FOR i = 1 TO 20
		LET a[i].j = i
		LET a[i].c = s[1,i]
	END FOR

	MESSAGE "dimension set to 7"
	CALL SET_COUNT(7)
	CALL set_max_dimension(7)
	INPUT ARRAY a WITHOUT DEFAULTS FROM s_a.*

	MESSAGE "dimension set to 17"
	CALL SET_COUNT(12)
	CALL set_max_dimension(17)
	INPUT ARRAY a WITHOUT DEFAULTS FROM s_a.*

	CLOSE FORM f_adjchk
	CLEAR SCREEN

END MAIN


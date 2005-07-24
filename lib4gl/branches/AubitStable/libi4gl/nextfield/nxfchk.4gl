{
	@(#)$Id: nxfchk.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $
	@(#)Program to test whether next_field works
}

MAIN

	DEFINE
		field1	CHAR(4),
		field2	CHAR(4),
		field3	CHAR(4),
		field4	CHAR(4),
		field5	CHAR(4)

	OPEN FORM f_nxfchk FROM "nxfchk"
	DISPLAY FORM f_nxfchk

	MESSAGE "Default sequence is 1,3,5,4,2"

	INPUT field1, field2, field3, field4, field5 FROM FORMONLY.*
	AFTER FIELD field1
		CALL next_field("field3")
	AFTER FIELD field2
		CALL next_field("field1")
	AFTER FIELD field3
		CALL next_field("field5")
	AFTER FIELD field4
		CALL next_field("field2")
	AFTER FIELD field5
		CALL next_field("field4")
	END INPUT

	CLOSE FORM f_nxfchk
	CLEAR SCREEN

END MAIN

{
	@(#)$Id: opendb.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $
	@(#)Open a database reliably
	@(#)Author: JL
}

DEFINE
	current_database	CHAR(10)

FUNCTION open_db(dbase)

	DEFINE
		sccs	CHAR(1),
		dbase	CHAR(10),
		retval	INTEGER

	LET dbase  = DOWNSHIFT(dbase)
	LET retval = -1

	WHENEVER ERROR CONTINUE

	{ Close current database, if any, ignoring errors }
	CLOSE DATABASE
	LET current_database = NULL
	LET STATUS = 0

	{ Open new database }
	DATABASE dbase
	IF STATUS = 0 THEN
		{ DATABASE statement can fail and return zero status }
		SELECT COUNT(*)
			INTO retval
			FROM Systables
		IF STATUS = 0 THEN
			LET retval = 0
			LET current_database = dbase
			LET sccs = "@(#)$Id: opendb.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $"
		END IF
	END IF
	WHENEVER ERROR STOP

	RETURN retval

END FUNCTION {open_db}

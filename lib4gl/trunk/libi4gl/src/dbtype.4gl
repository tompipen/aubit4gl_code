{
	@(#)$Id: dbtype.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $
	@(#)JLSS Informix Tools: General Library
	@(#)Determine type of database
	@(#)Author: JL
}

{
The set_databasetype() function should be called after a database is opened
and before the next operation that alters the SQLCA record.  It will try
to determine whether the database is Version 4.00 or earlier than Version 4.00,
whether it is OnLine or Standard Engine, whether the database has logging
enabled, and whether the database is mode ANSI.

The other routines are used to interrogate the database type.

get_databasemode() returns true if the database is mode ANSI.
get_databasetype() returns true if the database is OnLine
get_databasevers() returns true if the database is Version 4.00 or later
get_databaselogs() returns true if the database is logged.
}

DEFINE
	db_init		INTEGER,
	db_mode		INTEGER,
	db_type		INTEGER,
	db_vers		INTEGER,
	db_logs		INTEGER,
	db_sccs		CHAR(1)

{ Establish characteristics of database }
{ It is assumed that the last statement was a DATABASE statement }
FUNCTION set_databasetype()

	DEFINE
		counter	INTEGER

	IF SQLCA.SQLAWARN[1] != 'W' THEN
		{ Damn; could be version 4.00 unlogged SE database in non-ANSI mode }
		{ Could be earlier version with or without logs }
		WHENEVER ERROR CONTINUE
		SELECT COUNT(*) INTO counter
			FROM Informix.Systables WHERE Tabid = 1
		IF STATUS < 0 THEN
			LET db_vers = FALSE { It clearly isn't a Version 4.00 database }
			LET db_mode = FALSE { It cannot therefore be mode ANSI }
			LET db_type = FALSE { It is assumed to be Standard Engine }
			SELECT COUNT(*) INTO counter
				FROM Systables WHERE Tabtype = 'L'
			LET db_logs = (counter = 1)
			LET db_sccs = "@(#)$Id: dbtype.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $"
		ELSE
			LET db_vers = TRUE { It must be Version 4.00 or later }
			SELECT COUNT(*) INTO counter
				FROM Informix.Syscolumns WHERE Tabid = 1
			IF counter >= 18 THEN
				LET db_type = TRUE	{ OnLine }
				LET db_logs = TRUE	{ Assumed to be logged! }
				LET db_mode = FALSE	{ Assumed to be non-ANSI mode }
			ELSE
				LET db_type = FALSE { Standard Engine }
				SELECT COUNT(*) INTO counter
					FROM Informix.Systables WHERE Tabtype = 'L'
				IF counter = 1 THEN
					LET db_logs = TRUE	{ It has a transaction log }
					SELECT COUNT(*) INTO counter
						FROM Informix.Systables WHERE Tabname = "ANSI"
					LET db_mode = (counter = 1)
				END IF
			END IF
		END IF
	ELSE
		{ Must be a version 4.00 database with all information at hand }
		LET db_vers = TRUE
		LET db_logs = (SQLCA.SQLAWARN[2] = "W")
		LET db_mode = (SQLCA.SQLAWARN[3] = "W")
		LET db_type = (SQLCA.SQLAWARN[4] = "W")
	END IF
	LET db_init = TRUE

END FUNCTION {set_databasetype}

FUNCTION get_databasetype()

	IF db_init = FALSE THEN
		LET SQLCA.SQLAWARN[1] = ' '
		CALL set_databasetype()
	END IF

	RETURN db_type

END FUNCTION {get_databasetype}

FUNCTION get_databaselogs()

	IF db_init = FALSE THEN
		LET SQLCA.SQLAWARN[1] = ' '
		CALL set_databasetype()
	END IF

	RETURN db_logs

END FUNCTION {get_databaselogs}

FUNCTION get_databasevers()

	IF db_init = FALSE THEN
		LET SQLCA.SQLAWARN[1] = ' '
		CALL set_databasetype()
	END IF

	RETURN db_vers

END FUNCTION {get_databasevers}

FUNCTION get_databasemode()

	IF db_init = FALSE THEN
		LET SQLCA.SQLAWARN[1] = ' '
		CALL set_databasetype()
	END IF

	RETURN db_mode

END FUNCTION {get_databasemode}

{
	@(#)$Id: locks.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $
	@(#)Sphinx Informix Tools: General Library
	@(#)Table Lock/Unlock
	@(#)Author: JL
}

{ Execute lock table in named mode }
FUNCTION lock_table(tabname, lock_mode)

	DEFINE
		tabname		CHAR(18),
		lock_mode	CHAR(10),
		lock_stmt	CHAR(40),
		sccs		CHAR(1)

	LET lock_stmt = "LOCK TABLE ", tabname CLIPPED,
					" IN ", lock_mode clipped, " MODE"

	LET STATUS = 0
	WHENEVER ERROR CONTINUE
	PREPARE s_lock FROM lock_stmt
	IF STATUS < 0 THEN
		LET sccs = "@(#)$Id: locks.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $"
		RETURN STATUS
	END IF

	EXECUTE s_lock
	WHENEVER ERROR STOP
	RETURN STATUS

END FUNCTION {lock_table}

{ Execute unlock table: ignore selected errors }
FUNCTION unlock_table(tabname)

	DEFINE
		tabname		CHAR(18),
		lock_stmt	CHAR(40)

	LET lock_stmt = "UNLOCK TABLE ", tabname CLIPPED

	LET STATUS = 0
	WHENEVER ERROR CONTINUE
	PREPARE s_unlock FROM lock_stmt
	IF STATUS < 0 THEN
		RETURN STATUS
	END IF

	EXECUTE s_unlock
	WHENEVER ERROR STOP
	IF STATUS = -327 THEN	{ -327: Cannot unlock table within a transaction }
		LET STATUS = 0		{ Presumably will be released by COMMIT WORK }
	END IF
	IF STATUS = -288 THEN	{ -288: Table not locked by current user }
		LET STATUS = 0		{ Presumably released by COMMIT WORK }
	END IF
	RETURN STATUS

END FUNCTION {unlock_table}

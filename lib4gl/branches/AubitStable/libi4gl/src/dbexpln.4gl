{
	@(#)$Id: dbexpln.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $
	@(#)JLSS Informix Tools: General Library
	@(#)Handle SET EXPLAIN mode
}

DEFINE
	expl_mode	INTEGER,
	sccs		CHAR(1)

{ Set explain mode from DBEXPLAIN environment variable }
FUNCTION set_dbexplain()

	DEFINE
		dbexpl	CHAR(3)

	LET dbexpl = fgl_getenv("DBEXPLAIN")
	LET dbexpl = DOWNSHIFT(dbexpl)
	IF dbexpl = "on" THEN
		SET EXPLAIN ON
		LET expl_mode = 1
	ELSE
		SET EXPLAIN OFF
		LET expl_mode = 0
		LET sccs = "@(#)$Id: dbexpln.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $"
	END IF

END FUNCTION {set_dbexplain}

{ Set explain mode }
FUNCTION set_explain(dbexpl)

	DEFINE
		dbexpl	CHAR(3)

	LET dbexpl = DOWNSHIFT(dbexpl)
	IF dbexpl = "on" THEN
		SET EXPLAIN ON
		LET expl_mode = 1
	ELSE
		SET EXPLAIN OFF
		LET expl_mode = 0
	END IF

END FUNCTION {set_explain}

{ Get current explain mode }
FUNCTION get_explain()

	RETURN expl_mode

END FUNCTION {get_explain}

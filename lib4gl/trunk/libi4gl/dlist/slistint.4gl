{
	@@(#)slistint.4gl	1.2 90/03/04
	@@(#)Scroll cursor version of D-List code
	@@(#)Integer List
}

DEFINE
	s				CHAR(80),
	c_state			INTEGER,
	c_current_idx	INTEGER,
	c_current_key	INTEGER,
	c_count			INTEGER

FUNCTION sc_mkint()

	DEFINE
		n	INTEGER

	IF c_state = 1 THEN
		{ A cursor is already active }
		RETURN 0
	END IF

	WHENEVER ERROR CONTINUE
	DROP TABLE Scroll_integer	{ Should fail }
	CREATE TEMP TABLE Scroll_integer
	(
		Key_value	INTEGER
	)
	IF STATUS != 0 THEN
		LET c_state = 0
		RETURN 0
	END IF

	DECLARE c_scroll SCROLL CURSOR FOR
		SELECT Key_value
			FROM Scroll_integer
			ORDER BY Key_value
	OPEN c_scroll
	LET c_current_idx = 0

	IF STATUS = 0 THEN
		LET c_state = 1
		RETURN 1
	ELSE
		LET c_state = 0
		RETURN 0
	END IF

END FUNCTION {sc_mkint}

FUNCTION sc_cntint(n)

	DEFINE
		n	INTEGER

	RETURN c_count

END FUNCTION {sc_cntint}

FUNCTION sc_delint(n)

	DEFINE
		n	INTEGER

	WHENEVER ERROR CONTINUE
	DELETE FROM Scroll_integer WHERE Scroll_integer.Key_value = c_current_key
	LET c_count = c_count - 1
	CLOSE c_scroll
	RETURN 0

END FUNCTION {sc_delint}

FUNCTION sc_getint(n, c, o)

	DEFINE
		n	INTEGER,
		c	CHAR(1),
		o	INTEGER,
		e	INTEGER

	WHENEVER ERROR CONTINUE
	CASE
	WHEN c = 'A'
		LET c_current_idx = o
	WHEN c = 'N'
		LET c_current_idx = c_current_idx + o
	WHEN c = 'P'
		LET c_current_idx = c_current_idx - o
	WHEN c = 'L'
		LET c_current_idx = c_count
	WHEN c = 'F'
		LET c_current_idx = 1
	WHEN c = 'R'
		LET c_current_idx = c_current_idx + o
	WHEN c = 'C'
		LET c_current_idx = c_current_idx
	OTHERWISE
		ERROR "sc_getint given arg ", c, "-- can't happen!"
		SLEEP 2
		{LET c_current_idx = c_current_idx}
	END CASE

	CASE
	WHEN c_current_idx <= 0
		IF c_count = 0 THEN
			LET c_current_idx = 0
		ELSE
			LET c_current_idx = 1
		END IF
	WHEN c_current_idx > c_count
		LET c_current_idx = c_count
	END CASE

	IF c_current_idx > 0 THEN
		FETCH ABSOLUTE c_current_idx c_scroll INTO c_current_key
		IF STATUS = -400 THEN
			# FETCH ON unopen CURSOR
			OPEN c_scroll
			CALL sc_getint(n, c, o) RETURNING e, c_current_key
		END IF
	ELSE
		LET e = -1
	END IF

	IF STATUS < 0 THEN
		LET e = -1
	ELSE
		LET e = 0
	END IF

	RETURN e, c_current_key

END FUNCTION {sc_getint}

FUNCTION sc_updint(n, n2)

	DEFINE
		n	INTEGER,
		n2	INTEGER

	WHENEVER ERROR CONTINUE
	UPDATE Scroll_integer
		SET   Key_value = n2
		WHERE Key_value = c_current_key
	CLOSE c_scroll
	RETURN 0

END FUNCTION {sc_updint}

FUNCTION sc_insint(n, n2)

	DEFINE
		n	INTEGER,
		n2	INTEGER

	WHENEVER ERROR CONTINUE
	INSERT INTO Scroll_integer VALUES (n2)
	LET c_count = c_count + 1
	CLOSE c_scroll
	RETURN 0

END FUNCTION {sc_insint}

FUNCTION sc_numint(n)

	DEFINE
		n	INTEGER

	RETURN c_current_idx

END FUNCTION {sc_numint}

FUNCTION sc_rmint(n)

	DEFINE
		n	INTEGER

	WHENEVER ERROR CONTINUE
	DROP TABLE Scroll_integer
	LET c_state = 0
	RETURN 0

END FUNCTION {sc_rmint}

FUNCTION sc_zapint(n)

	DEFINE
		n	INTEGER

	WHENEVER ERROR CONTINUE
	DELETE FROM Scroll_integer
	CLOSE c_scroll
	LET c_count = 0
	LET c_current_idx = 0
	LET c_current_key = 0
	RETURN 0

END FUNCTION {sc_zapint}


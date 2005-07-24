{
	@(#)$Id: dlisti.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $
	@(#)Test code to check functionality of D-lists -- INTEGERS
}

MAIN

	DEFINE
		list		ARRAY[4] OF INTEGER,
		sccs		CHAR(32),
		i,j,k,l,n	INTEGER
	
	LET sccs = "@(#)$Id: dlisti.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $"

	FOR i = 1 TO 4
		LET list[i] = sc_mkint()
		IF list[i] <= 0 THEN
			ERROR "Failed to create list[", i USING "&",
				  "] with status", list[i] USING "---&"
			SLEEP 3
			EXIT PROGRAM
		ELSE
			DISPLAY "created list[", i USING "&", "] with index = ",
					list[i] USING "&" AT i, 1
		END IF
	END FOR

	FOR i = 1 TO 100
		LET j = hash(i)
		LET n = hash(j+3)*4
		DISPLAY "get row ", n USING "##&", " from list ",
				j USING "&" AT 5, 1
		CALL sc_getint(list[j], 'A', hash(j+3)*4)
			RETURNING k, l
		IF k < -1 THEN
			ERROR "Failed to get row ", j USING "##&",
				  "from list[", i USING "&", "] with status", k USING "---&"
			SLEEP 3
		END IF
		IF sc_insint(list[j], i) < 0 THEN
			ERROR "Failed to insert into list[", j USING "&",
				  "] with status", list[j] USING "---&"
			SLEEP 3
		END IF
	END FOR

	FOR i = 1 TO 20
		LET j = hash(i+37)
		CALL sc_getint(list[j], 'A', hash(j+6)*4)
			RETURNING k, l
		IF k < -1 THEN
			ERROR "Failed to get row ", j USING "##&",
				  "from list[", i USING "&", "] with status", k USING "---&"
			SLEEP 3
		END IF
		LET k = sc_delint(list[j])
		IF k < 0 THEN
			ERROR "Failed to delete from list[", j USING "&",
				  "] with status", k USING "---&"
			SLEEP 3
		END IF
	END FOR

	FOR i = 1 TO 4
		DISPLAY "Dump of list number ", i USING "&" AT 6, 1
		LET n = sc_numint(list[i])
		DISPLAY "Number of entries = ", n USING "##&" AT 7, 1
		FOR j = 1 TO n
			CALL sc_getint(list[i], 'A', j) RETURNING k, l
			IF k < -1 THEN
				ERROR "Failed to get row ", j USING "##&",
					  "from list[", i USING "&", "] with status", k USING "---&"
				SLEEP 3
			END IF
			DISPLAY "Entry[", j USING "#&", "] = ", l USING "##&" AT 8, 1
		END FOR
	END FOR

END MAIN

FUNCTION hash(i)

	DEFINE
		i, j	INTEGER

	RETURN ((i * 41) / 7) MOD 4 + 1

END FUNCTION

{
	@(#)$Id: dlisti.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $
	@(#)Test code to check functionality of D-lists -- INTEGERS
}

DEFINE
	list		ARRAY[4] OF INTEGER,
	n_list		INTEGER,
	seed		INTEGER

MAIN

	DEFINE
		sccs		CHAR(32),
		i,j,k,l,m,n	INTEGER

	LET sccs = "@(#)$Id: dlisti.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $"
	LET n_list = 4

	FOR i = 1 TO n_list
		LET list[i] = sc_create()
		IF list[i] <= 0 THEN
			ERROR "Failed to create list[", i USING "&",
				  "] with status", list[i] USING "---&"
			SLEEP 3
			EXIT PROGRAM
		ELSE
			DISPLAY "created list[", i USING "&", "] with index = ",
					list[i] USING "&" AT i, 1
		END IF
		CALL slow_me_up()
	END FOR

	DISPLAY "Inserting rows" AT 5, 1
	FOR i = 1 TO 100
		DISPLAY "Inserting row ", i AT 5, 1
		LET j = i4gl_random() MOD n_list + 1
		LET n = i4gl_random() MOD (i / n_list + 1) + 1
		DISPLAY "get row ", n USING "--&", " from list ",
				j USING "-&&" AT 6, 1
		CALL sc_select(list[j], 'A', n)
			RETURNING k, l
		IF k < -1 THEN
			ERROR "Failed to get row ", j USING "--&",
				  "from list[", i USING "&", "] with status", k USING "---&"
			SLEEP 3
			ERROR "Continuing"
		ELSE
			DISPLAY "Select return: l = ", l USING "---&",
					" k = ", k USING "---&" AT 7, 30
		END IF
		IF sc_insert(list[j], i) < 0 THEN
			ERROR "Failed to insert into list[", j USING "&",
				  "] with status", list[j] USING "---&"
			SLEEP 3
			ERROR "Continuing"
		END IF
		LET l = sc_count(list[j])
		DISPLAY "List count ", l USING "--&" AT 7, 1
		CALL slow_me_up()
	END FOR
	DISPLAY "Insert finished" AT 7, 1
	SLEEP 1

	CALL dump_lists()
	SLEEP 1

	DISPLAY "Delete some rows" AT 8, 1
	FOR i = 1 TO 20
		LET j = i4gl_random() MOD n_list + 1
		LET n = i4gl_random() MOD ((100 - i) / n_list) + 1
		DISPLAY "get row ", n USING "--&", " from list ",
				j USING "--&" AT 9, 1
		CALL sc_select(list[j], 'A', n)
			RETURNING k, l
		IF k < -1 THEN
			ERROR "Failed to get row ", j USING "--&",
				  "from list[", i USING "&", "] with status", k USING "---&"
			SLEEP 3
			ERROR "Continuing"
		ELSE
			DISPLAY "Select return: l = ", l USING "---&",
					" k = ", k USING "---&" AT 10, 30
		END IF
		DISPLAY "Delete row ", l USING "--&" AT 11, 1
		LET k = sc_delete(list[j])
		IF k < 0 THEN
			ERROR "Failed to delete from list[", j USING "&",
				  "] with status", k USING "---&"
			SLEEP 3
			ERROR "Continuing"
		END IF
		CALL slow_me_up()
	END FOR
	DISPLAY "Delete finished" AT 10, 1
	SLEEP 1

	CALL dump_lists()
	SLEEP 1

END MAIN

FUNCTION dump_lists()

	DEFINE
		i,j,k,l,m,n	INTEGER

	DISPLAY "Dump lists" AT 12, 1
	FOR i = 1 TO n_list
		LET m = (i - 1) * 20 + 1
		DISPLAY "Dump list ", i USING "&" AT 13, m
		LET n = sc_count(list[i])
		DISPLAY "Entries = ", n USING "--&" AT 14, m
		FOR j = 1 TO n
			CALL sc_select(list[i], 'A', j) RETURNING k, l
			IF k < -1 THEN
				ERROR "Failed to get row ", j USING "--&",
					  "from list[", i USING "&", "] with status", k USING "---&"
				SLEEP 3
				ERROR "Continuing"
			END IF
			DISPLAY "Entry[", j USING "#&", "] = ", l USING "--&" AT 15, m
			CALL slow_me_up()
		END FOR
	END FOR
	DISPLAY "Dump complete" AT 16, 1

END FUNCTION {dump_lists}

FUNCTION slow_me_up()

	DEFINE
		i	INTEGER

	FOR i = 1 TO 2000
		LET i = i
	END FOR

END FUNCTION {slow_me_up}

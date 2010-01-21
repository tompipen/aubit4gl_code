DATABASE test1

MAIN
	DEFINE
		sql_string CHAR(255),
		this_name CHAR(10),
		this_date DATE

	CREATE TEMP TABLE test_table (
		tt_name CHAR(10),
		tt_date DATE
	)
	insert into test_table values("John",today)
	LET this_name = "John"
	LET this_date = today
	IF this_name IS NOT NULL THEN
		LET sql_string = 
			"SELECT tt_name, tt_date ",
			"FROM test_table ",
			"WHERE tt_name = ? "
	ELSE
		LET sql_string = 
			"SELECT tt_name, tt_date ",
			"FROM test_table ",
			"WHERE tt_date = ? "
	END IF
	PREPARE sql_query FROM sql_string
	DECLARE query_cursor CURSOR FOR sql_query
	IF this_name IS NOT NULL THEN
		OPEN query_cursor USING this_name
	ELSE
		OPEN query_cursor USING this_date
	END IF
	FOREACH query_cursor INTO this_name, this_date
		DISPLAY this_name, " - ", this_date
	END FOREACH
END MAIN

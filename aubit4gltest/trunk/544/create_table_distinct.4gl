DATABASE test1

MAIN
	WHENEVER ERROR CONTINUE
	DROP TABLE a_table
	WHENEVER ERROR STOP

	CREATE TABLE a_table (
	  a_column INTEGER,
		another_column CHAR(20),
		DISTINCT  (a_column,another_column)
	)
	DROP TABLE a_table

	CREATE TABLE a_table (
	  a_column INTEGER,
		another_column CHAR(20),
		UNIQUE (a_column,another_column)
	)
	DROP TABLE a_table
END MAIN

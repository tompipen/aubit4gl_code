DATABASE test1

MAIN
	WHENEVER ERROR CONTINUE
	DROP TABLE a_table
	WHENEVER ERROR STOP
  CREATE TABLE a_table (
	  a_column INTEGER NOT NULL,
		another_col CHAR(20),
		PRIMARY KEY (a_column,another_col)
	)
	DROP TABLE a_table
END MAIN

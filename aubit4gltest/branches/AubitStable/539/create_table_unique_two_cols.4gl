DATABASE test1

MAIN
	WHENEVER ERROR CONTINUE
	DROP TABLE a_table
	DROP TABLE another_table
	WHENEVER ERROR STOP
  CREATE TABLE a_table (
	  a_column INTEGER NOT NULL,
	  another_col INTEGER NOT NULL,
		UNIQUE (a_column,another_col)
	)
  CREATE TABLE another_table (
	  a_column INTEGER NOT NULL,
	  another_col INTEGER NOT NULL,
		DISTINCT (a_column,another_col)
	)
	DROP TABLE a_table
	DROP TABLE another_table
END MAIN

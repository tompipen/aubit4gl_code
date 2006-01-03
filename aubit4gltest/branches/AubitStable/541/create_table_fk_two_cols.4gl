DATABASE test1

MAIN
  DEFINE strSql CHAR(128)

	WHENEVER ERROR CONTINUE
	DROP TABLE a_table
	DROP TABLE another_table
	WHENEVER ERROR STOP

	CREATE TABLE a_table (
	  a_column INTEGER NOT NULL,
		another_column CHAR(3), 
		PRIMARY KEY (a_column,another_column)
	)

  CREATE TABLE another_table (
	  a_column INTEGER NOT NULL,
		another_col CHAR(3),
		FOREIGN KEY (a_column,another_col) 
		  REFERENCES a_table (a_column,another_column)
	)
	DROP TABLE a_table
	DROP TABLE another_table
END MAIN




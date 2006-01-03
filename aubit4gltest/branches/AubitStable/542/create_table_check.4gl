DATABASE test1

MAIN
  DEFINE strSql CHAR(128)

	WHENEVER ERROR CONTINUE
	DROP TABLE a_table
	WHENEVER ERROR STOP

	CREATE TABLE a_table (
	  a_column INTEGER NOT NULL,
		another_column CHAR(1) CHECK (another_column ="Y")
	)
	DROP TABLE a_table

	CREATE TABLE a_table (
	  a_column INTEGER NOT NULL CHECK (a_column >= 10),
		another_column CHAR(1) CHECK (another_column IN ("Y","N"))
	)
	DROP TABLE a_table
END MAIN




DATABASE test1

MAIN
  DEFINE strSql CHAR(128)

	WHENEVER ERROR CONTINUE
	DROP TABLE a_table
	DROP TABLE another_table
	WHENEVER ERROR STOP

	LET strSql = "CREATE TABLE a_table ( a_column INTEGER NOT NULL PRIMARY KEY)"
	PREPARE st FROM strSql
	EXECUTE st

  CREATE TABLE another_table (
	  a_column INTEGER NOT NULL REFERENCES a_table (a_column)
	)
	DROP TABLE a_table
	DROP TABLE another_table
END MAIN

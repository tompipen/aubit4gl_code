
DATABASE test1

MAIN
	WHENEVER ERROR CONTINUE
	DROP TABLE not_null_tbl
	WHENEVER ERROR STOP
  CREATE TABLE not_null_tbl (
	  aColumn INTEGER NOT NULL
	)
	DROP TABLE not_null_tbl
END MAIN

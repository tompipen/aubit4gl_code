
DATABASE test1

MAIN
	WHENEVER ERROR CONTINUE
	DROP TABLE xpto
	WHENEVER ERROR STOP
  CREATE TABLE xpto (
	  aColumn CHAR(5),
		secondColumn INTEGER
	)
	ALTER TABLE xpto ADD (
	  third_column SMALLINT BEFORE aColumn,
	  forth_column DECIMAL(16,2) NOT NULL BEFORE secondColumn
	)
	DROP TABLE xpto
END MAIN

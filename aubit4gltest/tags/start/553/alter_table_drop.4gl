
DATABASE test1

MAIN
	WHENEVER ERROR CONTINUE
	DROP TABLE xpto
	WHENEVER ERROR STOP
  CREATE TABLE xpto (
	  aColumn CHAR(5),
		secondColumn INTEGER,
	  third_column SMALLINT,
	  forth_column DECIMAL(16,2) NOT NULL
	)
	ALTER TABLE xpto DROP (
	  third_column,
	  forth_column
	)
	DROP TABLE xpto
END MAIN

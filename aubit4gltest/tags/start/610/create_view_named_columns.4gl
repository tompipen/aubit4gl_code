
DATABASE test1

MAIN
	WHENEVER ERROR CONTINUE 
	DROP TABLE xpto
	WHENEVER ERROR STOP 
  CREATE TABLE xpto (
	  firstColumn INTEGER,
		secondColumn CHAR(10)
	)

	CREATE VIEW vXpto (aVColumn,oVColumn) 
	  AS SELECT firstColumn, secondColumn FROM xpto
	DROP TABLE xpto
END MAIN


DATABASE test1

MAIN
	WHENEVER ERROR CONTINUE 
	DROP TABLE xpto
	DROP TABLE xpta
	WHENEVER ERROR STOP 
  CREATE TABLE xpto (
	  firstColumn INTEGER,
		secondColumn CHAR(10)
	)

  CREATE TABLE xpta (
	  firstColumn INTEGER,
		secondColumn CHAR(10)
	)

	CREATE VIEW vXpto (aVColumn,oVColumn) 
	  AS SELECT b.firstColumn, a.secondColumn FROM xpto a, xpta b
		  WHERE a.firstColumn = b.firstColumn
		WITH CHECK OPTION
	DROP TABLE xpto
	DROP TABLE xpta
END MAIN

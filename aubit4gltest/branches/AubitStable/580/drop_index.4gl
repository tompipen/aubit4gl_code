
DATABASE test1
MAIN
  WHENEVER ERROR CONTINUE
	DROP TABLE xpto
  WHENEVER ERROR STOP
  CREATE TABLE xpto (
	  firstColumn INTEGER,
		secondColumn CHAR(2)
	)
	CREATE INDEX idxXpto ON xpto (firstColumn)
	DROP INDEX idxXpto 
	DROP TABLE xpto
END MAIN



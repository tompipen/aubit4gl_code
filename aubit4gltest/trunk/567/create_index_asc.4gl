
DATABASE test1
MAIN
  WHENEVER ERROR CONTINUE
	DROP TABLE xpto
  WHENEVER ERROR STOP
  CREATE TABLE xpto (
	  firstColumn INTEGER,
		secondColumn CHAR(2)
	)
	CREATE INDEX firstIdxXpto ON xpto (firstColumn ASC)
	CREATE INDEX secondIdxXpto ON xpto (firstColumn ASC,secondColumn ASC)
	DROP TABLE xpto
END MAIN



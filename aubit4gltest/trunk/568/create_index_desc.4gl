
DATABASE test1
MAIN
  WHENEVER ERROR CONTINUE
	DROP TABLE xpto
  WHENEVER ERROR STOP
  CREATE TABLE xpto (
	  firstColumn INTEGER,
		secondColumn CHAR(2),
		thirdColumn CHAR(4)
	)
	CREATE INDEX firstIdxXpto ON xpto (firstColumn DESC)
	CREATE INDEX secondIdxXpto ON xpto (firstColumn DESC,secondColumn DESC)
	CREATE INDEX thirdIdxXpto ON xpto 
	  (firstColumn DESC,secondColumn ASC,thirdColumn DESC)
	DROP TABLE xpto
END MAIN

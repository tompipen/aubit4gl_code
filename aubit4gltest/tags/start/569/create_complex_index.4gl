
DATABASE test1
MAIN
  WHENEVER ERROR CONTINUE
	DROP TABLE xpto
  WHENEVER ERROR STOP
  CREATE TABLE xpto (
	  firstColumn INTEGER,
		secondColumn CHAR(2),
		thirdColumn SMALLINT,
		forthColumn VARCHAR(3)
	)
	CREATE UNIQUE CLUSTER INDEX idxXpto ON xpto 
	  (firstColumn ASC,secondColumn DESC,thirdColumn, forthColumn ASC)
		FILLFACTOR 50
	DROP TABLE xpto
END MAIN


DATABASE test1
MAIN
  WHENEVER ERROR CONTINUE
	DROP TABLE xpto
  WHENEVER ERROR STOP
  CREATE TABLE xpto (
	  firstColumn INTEGER,
		secondColumn CHAR(2),
		thirdColumn CHAR(3)
	)
	CREATE UNIQUE INDEX idxOneXpto ON xpto (firstColumn)
	CREATE UNIQUE INDEX idxTwoXpto ON xpto (firstColumn,secondColumn)
	CREATE DISTINCT INDEX idxThreeXpto ON xpto (firstColumn,thirdColumn)
	CREATE DISTINCT INDEX idxFourXpto ON xpto (thirdColumn)
	DROP TABLE xpto
END MAIN

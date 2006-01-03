
DATABASE test1
MAIN
  WHENEVER ERROR CONTINUE
	DROP TABLE xpto
  WHENEVER ERROR STOP
	CALL createXpto()
	CREATE UNIQUE CLUSTER INDEX idxOneXpto ON xpto (firstColumn)
	CALL dropXpto()

	CALL createXpto()
	CREATE UNIQUE CLUSTER INDEX idxTwoXpto ON xpto (firstColumn,secondColumn)
	CALL dropXpto()

	CALL createXpto()
	CREATE CLUSTER INDEX idxThreeXpto ON xpto (secondColumn,thirdColumn)
	CALL dropXpto()

	CALL createXpto()
	CREATE DISTINCT CLUSTER INDEX idxThreeXpto ON xpto (firstColumn,thirdColumn)
	CALL dropXpto()

	CALL createXpto()
	CREATE DISTINCT CLUSTER INDEX idxFourXpto ON xpto (thirdColumn)
	CALL dropXpto()

END MAIN

FUNCTION createXpto()
  CREATE TABLE xpto (
	  firstColumn INTEGER,
		secondColumn CHAR(2),
		thirdColumn CHAR(3)
	)
END FUNCTION

FUNCTION dropXpto()
	DROP TABLE xpto
END FUNCTION


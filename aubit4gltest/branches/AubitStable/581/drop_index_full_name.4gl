
DATABASE test1

MAIN
  WHENEVER ERROR CONTINUE
	DROP TABLE xpto
  WHENEVER ERROR STOP
	CREATE TABLE xpto (
	  firstColumn INTEGER,
	  secondColumn CHAR(10),
	  thirdColumn CHAR(10),
	  forthColumn CHAR(10)
	)
	CREATE INDEX test1:idxXpta ON xpto (firstColumn)
	CREATE INDEX test1:'informix'.idxXptb ON xpto (secondColumn)
	CREATE INDEX test1@unstable:'informix'.idxXptc ON xpto (thirdColumn)
	CREATE INDEX test1@unstable:'informix'.idxXptd ON xpto (forthColumn)

	DROP INDEX test1:idxXpta 
	DROP INDEX test1:'informix'.idxXptb 
	DROP INDEX test1@unstable:'informix'.idxXptc 
	DROP INDEX test1@unstable:'informix'.idxXptd 
	DROP TABLE xpto
END MAIN



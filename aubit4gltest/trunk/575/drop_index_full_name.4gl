
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

	CREATE INDEX test1:xpta ON xpto (firstColumn)
	DROP INDEX test1:xpta 

	CREATE INDEX test1:'informix'.xpta ON xpto (firstColumn)
	DROP INDEX test1:'informix'.xpta 

#
# The following two lines generate an error at runtime
# -556    Cannot create, drop, or modify an object on an another database server.
	CREATE INDEX test1@unstable:'informix'.xptb ON xpto (firstColumn)
	DROP INDEX test1@unstable:'informix'.xptb 

	DROP TABLE xpto
END MAIN



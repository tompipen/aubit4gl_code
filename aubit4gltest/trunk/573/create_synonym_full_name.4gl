
DATABASE test1

MAIN
  WHENEVER ERROR CONTINUE
	DROP TABLE xpto
  WHENEVER ERROR STOP
	CREATE TABLE xpto (
	  firstColumn INTEGER,
	  secondColumn CHAR(10)
	)
	CREATE SYNONYM test1:xpta FOR xpto
	CREATE SYNONYM test1:'informix'.xpta2 FOR xpto

# The following two generate :
# -556    Cannot create, drop, or modify an object on an another database server.
# at runtime...
	CREATE SYNONYM test1@unstable:'informix'.xptb3 FOR xpto
	CREATE SYNONYM test1@unstable:'informix'.xptb4 FOR xpto

	DROP TABLE xpto
END MAIN




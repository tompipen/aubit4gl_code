
DATABASE test1

MAIN
  WHENEVER ERROR CONTINUE
	DROP TABLE xpto
	DROP SYNONYM xpta 
	DROP SYNONYM xptb 
	DROP SYNONYM xptc 
	DROP SYNONYM xptd 

  WHENEVER ERROR STOP

	CREATE TABLE xpto (
	  firstColumn INTEGER,
	  secondColumn CHAR(10)
	)

	CREATE SYNONYM test1:xpta FOR xpto
	CREATE SYNONYM test1:'informix'.xptb FOR xpto


# The following generate -556 at runtime


	CREATE SYNONYM test1@unstable:'informix'.xptc FOR xpto
	CREATE SYNONYM test1@unstable:'informix'.xptd FOR xpto



	DROP SYNONYM test1:xpta 
	DROP SYNONYM test1:'informix'.xptb 


# The following generate -556 at runtime
	DROP SYNONYM test1@unstable:'informix'.xptc 
	DROP SYNONYM test1@unstable:'informix'.xptd 



	DROP TABLE xpto
END MAIN




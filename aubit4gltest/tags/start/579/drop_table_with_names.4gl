
DATABASE test1

MAIN
  WHENEVER ERROR CONTINUE
	DROP TABLE xpto
  WHENEVER ERROR STOP
	CREATE TABLE xpto (
	  firstColumn INTEGER,
	  secondColumn CHAR(10)
	)

	CREATE TABLE test1:xpta (
	  firstColumn INTEGER,
	  secondColumn CHAR(10)
	)

	CREATE TABLE test1:'informix'.xptb (
	  firstColumn INTEGER,
	  secondColumn CHAR(10)
	)

# Generate -556 at runtime
	CREATE TABLE test1@unstable:'informix'.xptc (
	  firstColumn INTEGER,
	  secondColumn CHAR(10)
	)

	CREATE TABLE test1@unstable:'informix'.xptd (
	  firstColumn INTEGER,
	  secondColumn CHAR(10)
	)

	DROP TABLE xpto
	DROP TABLE test1:xpta 
	DROP TABLE test1:'informix'.xptb 
	DROP TABLE test1@unstable:'informix'.xptc 
	DROP TABLE test1@unstable:'informix'.xptd 
END MAIN

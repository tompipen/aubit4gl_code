
DATABASE test1

MAIN
  WHENEVER ERROR CONTINUE
	DROP TABLE xpto
  WHENEVER ERROR STOP
	CREATE TABLE xpto (
	  firstColumn INTEGER,
	  secondColumn CHAR(10)
	)
	CREATE VIEW test1:xpta AS SELECT * FROM  xpto
	CREATE VIEW test1:'informix'.xptb AS SELECT * FROM  xpto
	CREATE VIEW test1@unstable:'informix'.xptc AS SELECT * FROM  xpto
	CREATE VIEW test1@unstable:'informix'.xptd AS SELECT * FROM  xpto
	DROP TABLE xpto
END MAIN




DATABASE test1

MAIN
  WHENEVER ERROR CONTINUE
	DROP TABLE xpto
  WHENEVER ERROR STOP
	CREATE TABLE test1@unstable:'informix'.xpto (
	  firstColumn INTEGER,
	  secondColumn CHAR(10)
	)
	CREATE VIEW vXpto AS SELECT * FROM xpto
  DROP VIEW test1:vXpto 
	CREATE VIEW 'informix'.vXpto AS SELECT * FROM xpto
	DROP VIEW  test1:'informix'.vXpto 
	CREATE VIEW 'informix'.vXpto AS SELECT * FROM xpto
	DROP VIEW  test1@unstable:'informix'.vXpto 
	DROP TABLE  xpto
END MAIN



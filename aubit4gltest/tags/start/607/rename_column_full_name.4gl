
DATABASE test1

MAIN
  WHENEVER ERROR CONTINUE
	DROP TABLE xpto
  WHENEVER ERROR STOP
	CREATE TABLE test1@unstable:'informix'.xpto (
	  firstColumn INTEGER,
	  secondColumn CHAR(10)
	)
	RENAME COLUMN test1:xpto.firstColumn TO otherColumn
	RENAME COLUMN 'informix'.xpto.otherColumn TO firstColumn
	RENAME COLUMN test1:'informix'.xpto.firstColumn TO otherColumn
	RENAME COLUMN 'informix'.xpto.otherColumn TO firstColumn
	RENAME COLUMN test1@unstable:'informix'.xpto.firstColumn TO otherColumn 
	DROP TABLE  xpto
END MAIN

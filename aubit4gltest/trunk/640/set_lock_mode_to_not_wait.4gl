
DATABASE test1

MAIN
	WHENEVER ERROR CONTINUE
	DROP TABLE xpto
	WHENEVER ERROR STOP
	CREATE TABLE xpto (
	  firstColumn SMALLINT,
    secondColumn CHAR(10)
	)

  SET LOCK MODE TO NOT WAIT 
	INSERT INTO xpto VALUES (1,"Xpto")

	DROP TABLE xpto
END MAIN

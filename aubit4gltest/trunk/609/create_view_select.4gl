
DATABASE test1

MAIN
	WHENEVER ERROR CONTINUE 
	DROP TABLE xpto
	DROP TABLE vxpto
	DROP view vxpto
	WHENEVER ERROR STOP 
	
  	CREATE TABLE xpto (
	  firstColumn INTEGER,
		secondColumn CHAR(10)
	)

	CREATE VIEW vXpto AS SELECT firstColumn, secondColumn FROM xpto

	
	DROP view vXpto
	DROP TABLE xpto
END MAIN




DATABASE test1

MAIN
  DEFINE intVar INTEGER
	DEFINE selVar INTEGER
	DEFINE chVar CHAR(10)

	WHENEVER ERROR CONTINUE
	DROP TABLE xpto
	WHENEVER ERROR STOP
	CREATE TABLE xpto (
	  firstColumn integer,
		secondColumn CHAR(10)
	)
	PREPARE st FROM "INSERT INTO xpto (firstColumn,secondColumn) VALUES (?,?)"
	LET intVar = 2
	LET chVar = "Hello"
	EXECUTE st USING intVar, chVar
	PREPARE stSel 
	  FROM "SELECT firstColumn,secondColumn FROM xpto WHERE firstColumn=?"
	DECLARE cr CURSOR FOR stSel
	FREE cr
	DROP TABLE xpto
END MAIN



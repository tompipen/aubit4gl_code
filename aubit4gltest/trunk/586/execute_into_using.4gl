
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
  	EXECUTE stSel INTO selVar, chVar USING intVar
	DROP TABLE xpto
	display selVar, chVar
	if selVar!=2 or chVar!="Hello" then
		exit program 1
	else
		exit program 0
	end if
END MAIN



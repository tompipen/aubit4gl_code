
MAIN
	DEFINE strSql CHAR(128)

	WHENEVER ERROR CONTINUE
  LET strSql = "CREATE DATABASE xpto"
	PREPARE st FROM strSql
	EXECUTE st
	WHENEVER ERROR STOP
	CLOSE DATABASE 
  DROP DATABASE xpto
END MAIN




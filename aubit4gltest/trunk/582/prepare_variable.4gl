#This test does not need a database
MAIN
  DEFINE str CHAR(20)

	LET str = "DATABASE test1sss"
	PREPARE st FROM str
END MAIN


MAIN
	DEFINE dbName CHAR(10)

  DATABASE test1
  DATABASE test1@unstable
	#DATABASE "//unstable/test1"
	LET dbName = "test1"
	DATABASE dbName
END MAIN

database test1
MAIN
	DEFINE i SMALLINT
	DEFINE str char(128)

	LET str = "select count(*) from systables"
	PREPARE st FROM str
	DECLARE cr CURSOR FOR st
  FOREACH cr into i
	  display "Count ", i
	END FOREACH
END MAIN

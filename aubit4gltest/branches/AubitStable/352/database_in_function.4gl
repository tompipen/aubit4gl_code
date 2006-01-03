
main
	call db_function()
end main


FUNCTION db_function()
	DEFINE db_name CHAR(10)

  DATABASE test1
	LET db_name = "test1"
	DATABASE db_name
END FUNCTION

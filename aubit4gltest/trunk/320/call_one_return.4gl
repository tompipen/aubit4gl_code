
MAIN
	DEFINE y SMALLINT

  call simpleFunction() RETURNING y
END MAIN

FUNCTION simpleFunction()
  DEFINE return_value SMALLINT

	RETURN return_value
END FUNCTION


MAIN
	DEFINE x SMALLINT
	DEFINE y CHAR(10)
	DEFINE z DECIMAL(10,2)

  call simpleFunction() RETURNING x,y,z
END MAIN

FUNCTION simpleFunction()
  DEFINE first_ret SMALLINT
  DEFINE second_ret CHAR(10)
  DEFINE third_ret DECIMAL(10,2)

	RETURN first_ret, second_ret, third_ret
END FUNCTION

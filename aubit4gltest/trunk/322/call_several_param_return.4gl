
MAIN
	DEFINE x SMALLINT
	DEFINE y CHAR(10)
	DEFINE z DECIMAL(10,2)

  call simpleFunction("Hello",3.2,6) RETURNING x,y,z
END MAIN

FUNCTION simpleFunction(first_param,second_param,third_param)
	DEFINE first_param CHAR(65)
	DEFINE second_param DECIMAL(8,3)
	DEFINE third_param INTEGER
  DEFINE first_ret SMALLINT
  DEFINE second_ret CHAR(10)
  DEFINE third_ret DECIMAL(10,2)

	RETURN first_ret, second_ret, third_ret
END FUNCTION


MAIN
  call simpleFunction(1,"Hello",2.45,NULL)
END MAIN

FUNCTION simpleFunction(first_argument,second_arg,third_arg,fourth_arg)
  DEFINE first_argument SMALLINT
  DEFINE second_arg CHAR(10)
  DEFINE third_arg DECIMAL(10,2)
  DEFINE fourth_arg INTEGER

  DISPLAY "Hello world"
  if fourth_arg is not null then
	exit program 1
  end if
END FUNCTION

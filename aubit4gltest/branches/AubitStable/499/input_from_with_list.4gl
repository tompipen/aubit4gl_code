
MAIN
	DEFINE a_field CHAR(10)
	DEFINE second_field integer
	DEFINE third_field smallint
	DEFINE ans CHAR(1)

  OPEN WINDOW w_ AT 2, 2 WITH FORM "a_form" ATTRIBUTE(BORDER)
	LET a_field = "Hello"
	LET second_field = 10
	LET third_field = 65
	INPUT a_field, second_field, third_field 
	 FROM a_field, second_field, third_field
END MAIN




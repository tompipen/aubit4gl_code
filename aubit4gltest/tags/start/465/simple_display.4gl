
MAIN
	DEFINE a_fieldVar CHAR(10)
	DEFINE ans CHAR(1)

  OPEN WINDOW w_ AT 2, 2 WITH FORM "a_form" ATTRIBUTE(BORDER)
	LET a_fieldVar = "Hello"
	DISPLAY a_fieldVar TO a_field
	#PROMPT "" FOR CHAR ans
END MAIN


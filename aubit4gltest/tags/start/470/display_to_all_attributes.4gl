
MAIN
	DEFINE my_a_field CHAR(10)
	DEFINE my_second_field integer
	DEFINE my_third_field smallint
	DEFINE ans CHAR(1)

  OPEN WINDOW w_ AT 2, 2 WITH FORM "a_form" ATTRIBUTE(BORDER)
	LET my_a_field = "Hello"
	LET my_second_field = 10
	LET my_third_field = 65
	DISPLAY my_a_field, my_second_field, my_third_field
	     TO a_field, second_field, third_field
	  ATTRIBUTE (
		  WHITE,YELLOW,MAGENTA,CYAN,GREEN,BLUE,BLACK,NORMAL,BOLD,DIM,
      REVERSE
		)
	#PROMPT "" FOR CHAR ans
END MAIN




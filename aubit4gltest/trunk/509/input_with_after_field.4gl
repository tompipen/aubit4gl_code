
MAIN
	DEFINE a_field CHAR(10)
	DEFINE second_field integer
	DEFINE third_field smallint
	DEFINE ans CHAR(1)

  OPEN WINDOW w_ AT 2, 2 WITH FORM "a_form" ATTRIBUTE(BORDER)
	LET a_field = "Hello"
	LET second_field = 10
	LET third_field = 65
	INPUT BY NAME a_field, second_field, third_field 
		WITHOUT DEFAULTS
	  BEFORE FIELD a_field, third_field
		  CASE
			  WHEN infield(a_field) 
		      ERROR "Before first field"
		    WHEN infield("third_field")
		      ERROR "Before third field"
	    END CASE
  END INPUT
END MAIN




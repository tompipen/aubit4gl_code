
MAIN
  DEFINE first_field INTEGER
  DEFINE second_field INTEGER
  DEFINE third_field INTEGER
  DEFINE forth_field INTEGER
  DEFINE fift_field INTEGER
  DEFINE sixt_field INTEGER
  DEFINE seven_field INTEGER
	DEFER INTERRUPT

  OPTIONS 
	  ACCEPT KEY F23 

  OPEN WINDOW w_ AT 2,2 WITH FORM "a_form" ATTRIBUTE(BORDER)
	LET int_flag = FALSE
	INPUT BY NAME first_field, second_field, third_field, forth_field,
                fift_field, sixt_field, seven_field

	  AFTER FIELD first_field, second_field, third_field, forth_field,
                fift_field, sixt_field, seven_field
			# Validações especificas
			CASE
		    WHEN infield(second_field)
				  ERROR "ON SECOND FIELD"
		    WHEN infield(third_field)
				  ERROR "ON SECOND FIELD"
			END CASE

      ERROR "Validações comuns"

			# Next field especifico
			CASE
			  WHEN fgl_lastkey() = fgl_keyval("RETURN") 
			    EXIT INPUT
		    WHEN infield(third_field)
					#NEXT FIELD first_field
				  ERROR "ON THIRD FIELD"
			END CASE

	  ON KEY(ESC,CONTROL-C)
	     LET int_flag = TRUE
       EXIT INPUT

	  AFTER INPUT
		  IF fgl_lastkey() = fgl_keyval("ACCEPT") THEN
				ERROR "ACCEPT"
			  CONTINUE INPUT
			END IF
		  IF int_flag THEN
				ERROR "INTERRUPT"
	      LET int_flag = FALSE
				EXIT INPUT
			END IF
	END INPUT
	CLOSE WINDOW w_
END MAIN

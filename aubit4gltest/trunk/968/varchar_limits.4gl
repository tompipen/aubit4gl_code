{**
 * Test the variable length character variable limits
 * @process DATA_TYPE
 *}

MAIN
  DEFINE varchar_variable VARCHAR(255)
  DEFINE varchar_max_variable VARCHAR(255,255)
  DEFINE varchar_zero_variable VARCHAR(255,0)
	DEFINE i SMALLINT
	DEFINE ch CHAR
	DEFINE exitStatus SMALLINT

	LET exitStatus = 0
  FOR i = 1 TO 255
	  LET varchar_variable[i] = intToChar(i)
	  LET varchar_max_variable[i] = intToChar(i)
	  LET varchar_zero_variable[i] = intToChar(i)
	END FOR

  FOR i = 1 TO 255
	  LET ch = varchar_variable[i] 
		IF ch != intToChar(i) THEN
		  LET exitStatus = 1
			DISPLAY "Error in character assigned"
			EXIT FOR
		END IF
	  LET ch = varchar_max_variable[i] 
		IF ch != intToChar(i) THEN
		  LET exitStatus = 1
			DISPLAY "Error in character assigned"
			EXIT FOR
		END IF
	  LET ch = varchar_zero_variable[i] 
		IF ch != intToChar(i) THEN
		  LET exitStatus = 1
			DISPLAY "Error in character assigned"
			EXIT FOR
		END IF
	END FOR

	EXIT PROGRAM exitStatus
END MAIN

{**
 * Convert a smallint to a comparable character.
 * Use ascii codes between 48 and 90.
 *}
FUNCTION intToChar(j)
  DEFINE j SMALLINT
  DEFINE k SMALLINT
  DEFINE val SMALLINT
	DEFINE ch CHAR

  LET k = (j/44) 
  LET val = j - 44 * k + 48 - 1
	LET ch = ASCII val
	RETURN ch
END FUNCTION

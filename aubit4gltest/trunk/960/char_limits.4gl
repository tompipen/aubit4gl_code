{**
 * Test the character variable limits
 * @process DATA_TYPE
 *}

MAIN
  DEFINE char_variable CHAR(32766)
	DEFINE i SMALLINT
	DEFINE ch CHAR
	DEFINE exitStatus SMALLINT

	LET exitStatus = 0
  FOR i = 1 TO 32766
	  LET char_variable[i] = intToChar(i)
	END FOR

  FOR i = 1 TO 32766
	  LET ch = char_variable[i] 
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

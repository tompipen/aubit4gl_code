{**
 * @file
 * Test if a poplocator function works ok
 *}

DATABASE test1

MAIN
	DEFINE exitStatus SMALLINT
  DEFINE a_byte BYTE 
  DEFINE a_text TEXT 
	DEFINE file_name CHAR(64)

	LOCATE a_byte IN FILE "byte.data"
	LOCATE a_text IN FILE "text.txt"

	LET file_name = pop_locator(a_byte)
	LET exitStatus = 0
	IF file_name != "byte.data" THEN
	  DISPLAY "Wrong file name passed by byte locator"
		LET exitStatus = 1
	END IF

	LET file_name = pop_locator(a_text)
	LET exitStatus = 0
	IF file_name != "text.txt" THEN
	  DISPLAY "Wrong file name passed by text locator"
		LET exitStatus = 1
	END IF

	EXIT PROGRAM exitStatus

END MAIN


{**
 * @file 
 * @test
 * Tests to exemplify the behaviour of cursor location with aubit and standard
 * 4gl.
 *}

DEFINE tLine SMALLINT
DEFINE retVal SMALLINT

MAIN
	LET retVal = FALSE
	CALL myGetKey("TAB",9) 
	CALL myGetKey("RETURN",13) 
	CALL myGetKey("CONTROL-W",23) 
	CALL myGetKey("ESC",27) 
	CALL myGetKey("SPACE",32) 
	CALL myGetKey("1",49) 
	CALL myGetKey("2",50) 
	CALL myGetKey("3",51) 
	CALL myGetKey("4",52) 
	CALL myGetKey("5",53) 
	CALL myGetKey("6",54) 
	CALL myGetKey("7",55) 
	CALL myGetKey("8",56) 
	CALL myGetKey("9",57) 
	CALL myGetKey("CONTROL-K",2000) 
	CALL myGetKey("CONTROL-J",2001) 
	CALL myGetKey("CONTROL-L",2003) 
	CALL myGetKey("CONTROL-H",2004) 

	CALL myGetKey("TAB",fgl_keyval("TAB")) 
	CALL myGetKey("RETURN",fgl_keyval("RETURN")) 
	CALL myGetKey("CONTROL-W",fgl_keyval("CONTROL-W")) 
	CALL myGetKey("ESC",fgl_keyval("ESC")) 
	CALL myGetKey("SPACE",fgl_keyval("SPACE")) 
	CALL myGetKey("CONTROL-K",fgl_keyval("CONTROL-K")) 
	CALL myGetKey("CONTROL-J",fgl_keyval("CONTROL-J")) 
	CALL myGetKey("CONTROL-L",fgl_keyval("CONTROL-L")) 
	CALL myGetKey("CONTROL-H",fgl_keyval("CONTROL-H")) 
	# 54, 52
	EXIT PROGRAM retVal
END MAIN

{**
 * Waits for a key to be pressed and check if the key hitted was correct
 *
 * @param keyName The name of the key.
 * @param keyVal The value expected for the key.
 *
 * @return TRUE : The value was the expected.
 *         FALSE : The value was not the expected.
 *}
FUNCTION myGetKey(keyName,keyVal)
  DEFINE keyName CHAR(30)
	DEFINE keyVal SMALLINT
	DEFINE ans SMALLINT

  DISPLAY "Hit ", keyName CLIPPED, " : " AT 1, 1
	LET ans = fgl_getkey()
	IF ans != keyVal THEN
		ERROR "Key ", keyName CLIPPED, " was ", ans, " and not ", keyVal
	  LET retVal = TRUE
	END IF
END FUNCTION





{**
 * @file 
 * @test
 * Testing if the values returned by fgl_keyval is equal to the values
 * of informix.
 *}

DEFINE tLine SMALLINT
DEFINE retVal SMALLINT

MAIN
	LET retVal = FALSE
	CALL checkLastKey("TAB",9) 
	CALL checkLastKey("RETURN",13) 
	--CALL checkLastKey("ENTER",13) 
	CALL checkLastKey("CONTROL-W",23) 
	CALL checkLastKey("ESC",27) 
	CALL checkLastKey("ESCAPE",27) 
	--CALL checkLastKey("SPACE",32) 
	CALL checkLastKey(" ",32) 
	CALL checkLastKey("1",49) 
	CALL checkLastKey("2",50) 
	CALL checkLastKey("3",51) 
	CALL checkLastKey("4",52) 
	CALL checkLastKey("5",53) 
	CALL checkLastKey("6",54) 
	CALL checkLastKey("7",55) 
	CALL checkLastKey("8",56) 
	CALL checkLastKey("9",57) 
	CALL checkLastKey("CONTROL-A",1) 
	CALL checkLastKey("CONTROL-B",2) 
	CALL checkLastKey("CONTROL-C",3) 
	CALL checkLastKey("CONTROL-D",4) 
	CALL checkLastKey("CONTROL-E",5) 
	CALL checkLastKey("CONTROL-F",6) 
	CALL checkLastKey("CONTROL-G",7) 
	CALL checkLastKey("CONTROL-H",8) 
	CALL checkLastKey("CONTROL-I",9) 
	CALL checkLastKey("CONTROL-J",10) 
	CALL checkLastKey("CONTROL-K",11) 
	CALL checkLastKey("CONTROL-L",12) 
	CALL checkLastKey("CONTROL-M",13) 
	CALL checkLastKey("CONTROL-N",14) 
	CALL checkLastKey("CONTROL-O",15) 
	CALL checkLastKey("CONTROL-P",16) 
	CALL checkLastKey("CONTROL-Q",17) 
	CALL checkLastKey("CONTROL-R",18) 
	CALL checkLastKey("CONTROL-S",19) 
	CALL checkLastKey("CONTROL-T",20) 
	CALL checkLastKey("CONTROL-U",21) 
	CALL checkLastKey("CONTROL-V",22) 
	CALL checkLastKey("CONTROL-W",23) 
	CALL checkLastKey("CONTROL-X",24) 
	CALL checkLastKey("CONTROL-Y",25) 
	CALL checkLastKey("CONTROL-Z",26) 
	CALL checkLastKey("UP",2000) 
	CALL checkLastKey("DOWN",2001) 
	CALL checkLastKey("LEFT",2002) 
	CALL checkLastKey("RIGHT",2003) 
	CALL checkLastKey("NEXTPAGE",2005) 
	CALL checkLastKey("PREVPAGE",2006) 
	CALL checkLastKey("HELP",2008) 
	CALL checkLastKey("F1",3000) 
	CALL checkLastKey("F2",3001) 
	CALL checkLastKey("F3",3002) 
	CALL checkLastKey("F4",3003) 
	CALL checkLastKey("F5",3004) 
	CALL checkLastKey("F6",3005) 
	CALL checkLastKey("F7",3006) 
	CALL checkLastKey("F8",3007) 
	CALL checkLastKey("F9",3008) 
	CALL checkLastKey("F10",3009) 
	-- .. F11 to F63 
	CALL checkLastKey("F64",3063) 
	CALL checkLastKey("INTERRUPT",2011) 
	CALL checkLastKey("INSERT",2014) 
	CALL checkLastKey("DELETE",2015) 
	CALL checkLastKey("ACCEPT",2016) 
	--CALL checkLastKey("NEXT",3009) 
	--CALL checkLastKey("PREVIOUS",3009) 
	--CALL checkLastKey("QUIT",3009) 
	# 54, 52
	EXIT PROGRAM retVal
END MAIN

{**
 * Compare the values of fgl_keyval and the hardcoded value tested against
 * informix.
 *
 * @param keyName The name of the key to be checked.
 * @param keyVal The value expected for the key.
 *
 * @return TRUE : The value was the expected.
 *         FALSE : The value was not the expected.
 *}
FUNCTION checkLastKey(keyName,keyVal)
  DEFINE keyName CHAR(20)
	DEFINE keyVal INTEGER
	DEFINE ans INTEGER

	LET ans = fgl_keyval(keyName)
	IF ans IS NULL THEN
	  DISPLAY "Invalid key ", keyName CLIPPED
	  LET retVal = TRUE
		RETURN
	END IF
	IF ans != keyVal THEN
		DISPLAY "Key ", keyName CLIPPED, " was ", ans, " and not ", keyVal
	  LET retVal = TRUE
	ELSE
		DISPLAY "Key ", keyName CLIPPED, " have the value ", ans
	END IF
END FUNCTION




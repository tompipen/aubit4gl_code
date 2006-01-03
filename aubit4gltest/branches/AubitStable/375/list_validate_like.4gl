{**
 * @file
 * Test if validate syntax is suported and if it works ok with the 
 * list of columns.
 *
 * @todo : The information on the syscolval should be loaded somewhere
 *}


DATABASE TEST1

MAIN
  DEFINE x integer
  DEFINE y char(8)
  DEFINE z CHAR(18)
	DEFINE exitStatus SMALLINT

	LET exitStatus = 0
	WHENEVER ERROR CONTINUE
	LET x = 1
	LET y = "XX"
	LET z = "YYY"
	VALIDATE x, y, z LIKE tab1.x, "test".tab1.y, tab1.z
	IF status != -4504 THEN
	  DISPLAY "Values not correctly validated (VALIDATE should return ",
		        "-4504 in status)"
	  LET exitStatus =1
	END IF
	LET x = 2
	LET y = "OK"
	LET z = "CORRECT VALUE"
	VALIDATE x, y, z LIKE tab1.x, "test".tab1.y, tab1.z
	IF status != -0 THEN
		DISPLAY "Validate did not returned zero as expected"
	  LET exitStatus =1
	END IF
	EXIT PROGRAM exitStatus
END MAIN

{**
 * @file
 * @process TEST_DECFUNC
 * Test if a decimal copy C function works OK
 *}
MAIN
  DEFINE original_decimal DECIMAL(32,16)
  DEFINE copied_decimal DECIMAL(32,16)
	DEFINE exitStatus SMALLINT

  LET exitStatus = 0
	LET original_decimal = 3.3

	LET copied_decimal = decimal_copy(original_decimal) 

	IF copied_decimal != 3.3 THEN
	  DISPLAY "The deccopy did not copy well a decimal to other"
		LET exitStatus = 1
	END IF
	EXIT PROGRAM exitStatus
END MAIN

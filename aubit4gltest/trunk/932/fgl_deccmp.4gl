{**
 * @file
 * @process TEST_DECFUNC
 * Test if a decimal comparison C function works OK
 *}
MAIN
  DEFINE a_decimal DECIMAL(32,16)
  DEFINE other_decimal DECIMAL(32,16)
	DEFINE ok_code SMALLINT
	DEFINE exitStatus SMALLINT

  LET exitStatus = 0
	LET a_decimal = 3.3
	LET other_decimal = 3.3
	LET ok_code = decimal_cmp(a_decimal,other_decimal)
	IF ok_code = 0 THEN
	  DISPLAY "The deccmp did not compared two equal decimals ok"
		LET exitStatus = 1
	END IF

	LET a_decimal = 3.3
	LET other_decimal = 2.2
	LET ok_code = decimal_cmp(a_decimal,other_decimal)
	IF ok_code <= 0 THEN
	  DISPLAY "The deccmp did not compared two diferent decimals ok"
		LET exitStatus = 1
	END IF

	LET a_decimal = 2.2
	LET other_decimal = 3.3
	LET ok_code = decimal_cmp(a_decimal,other_decimal)
	IF ok_code >= 0 THEN
	  DISPLAY "The deccmp did not compared two diferent decimals ok"
		LET exitStatus = 1
	END IF
	EXIT PROGRAM exitStatus
END MAIN

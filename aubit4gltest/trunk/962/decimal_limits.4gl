{**
 * Test the decimal variable limits.
 * @process DATA_TYPE
 *}

MAIN
  DEFINE dec_no_prec DECIMAL
  DEFINE dec_with_no_frac DECIMAL(32)
  DEFINE dec_with_frac DECIMAL(32,16)
  DEFINE dec_big_frac DECIMAL(32,32)
	DEFINE exitStatus SMALLINT

	LET exitStatus = 0

  LET dec_no_prec = 9e123
	IF dec_no_prec != 9e123 THEN
	  DISPLAY "Error on largest decimal comparison "
		LET exitStatus = 1
	END IF

  LET dec_no_prec = -9e123
	IF dec_no_prec != -9e123 THEN
	  DISPLAY "Error on lowest decimal comparison "
		LET exitStatus = 1
	END IF

  LET dec_no_prec = 1e-130
	IF dec_no_prec <= 0.0 THEN
	  DISPLAY "Error on near zero decimal comparison "
		LET exitStatus = 1
	END IF
	
  LET dec_no_prec = 0.0
	IF dec_no_prec != 0.0 THEN
	  DISPLAY "Error on zero decimal comparison "
		LET exitStatus = 1
	END IF

  --

  LET dec_with_no_frac = 9e123
	IF dec_with_no_frac != 9e123 THEN
	  DISPLAY "Error on largest decimal comparison "
		LET exitStatus = 1
	END IF

  LET dec_with_no_frac = -9e123
	IF dec_with_no_frac != -9e123 THEN
	  DISPLAY "Error on lowest decimal comparison "
		LET exitStatus = 1
	END IF

  LET dec_with_no_frac = 1e-130
	IF dec_with_no_frac <= 0.0 THEN
	  DISPLAY "Error on zero decimal comparison "
		LET exitStatus = 1
	END IF
	
  LET dec_with_no_frac = 0.0
	IF dec_with_no_frac != 0.0 THEN
	  DISPLAY "Error on zero decimal comparison "
		LET exitStatus = 1
	END IF

  --

  LET dec_with_frac = 9999999999999999.9999999999999999
	IF dec_with_frac != 9999999999999999.9999999999999999 THEN
	  DISPLAY "Error on dec_with_frac largest decimal comparison "
		LET exitStatus = 1
	END IF

	IF dec_with_frac = 9999999999999999.9999999999999998 THEN
	  DISPLAY "Error. Comparison did not detected the smallest fractional digit"
		LET exitStatus = 1
	END IF

  LET dec_with_frac = -9999999999999999.9999999999999999
	IF dec_with_frac != -9999999999999999.9999999999999999 THEN
	  DISPLAY "Error on dec_with_frac lowest decimal comparison "
		LET exitStatus = 1
	END IF

	IF dec_with_frac = -9999999999999999.9999999999999998 THEN
	  DISPLAY "Error. Comparison did not detected the smallest fractional digit"
		LET exitStatus = 1
	END IF

  LET dec_with_frac = 0.0000000000000001
	IF dec_with_frac <= 0.0 THEN
	  DISPLAY "Error on dec_with_frac near zero decimal comparison "
		LET exitStatus = 1
	END IF
	
  LET dec_with_frac = 0.0
	IF dec_with_frac != 0.0 THEN
	  DISPLAY "Error on dec_with_frac zero decimal comparison "
		LET exitStatus = 1
	END IF

	--

  LET dec_big_frac = 0.99999999999999999999999999999999
	IF dec_big_frac != 0.99999999999999999999999999999999 THEN
	  DISPLAY "Error on dec_big_frac largest decimal comparison "
		LET exitStatus = 1
	END IF

	IF dec_big_frac = 0.99999999999999999999999999999998 THEN
	  DISPLAY "Error. Comparison did not detected the smallest fractional digit"
		LET exitStatus = 1
	END IF

  LET dec_big_frac = -0.99999999999999999999999999999999
	IF dec_big_frac != -0.99999999999999999999999999999999 THEN
	  DISPLAY "Error on dec_big_frac lowest decimal comparison "
		LET exitStatus = 1
	END IF

	IF dec_big_frac = -0.99999999999999999999999999999998 THEN
	  DISPLAY "Error. Comparison did not detected the smallest fractional digit"
		LET exitStatus = 1
	END IF

  LET dec_big_frac = 0.00000000000000000000000000000001
	IF dec_big_frac <= 0.0 THEN
	  DISPLAY "Error on dec_big_frac near zero decimal comparison "
		LET exitStatus = 1
	END IF
	
  LET dec_big_frac = 0.00000000000000000000000000000000
	IF dec_big_frac != 0.0 THEN
	  DISPLAY "Error on dec_big_frac zero decimal comparison "
		LET exitStatus = 1
	END IF
	EXIT PROGRAM exitStatus
END MAIN


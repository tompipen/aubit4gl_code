{**
 * @file
 * @test
 * Check if a query with sql expression fetch the correct values.
 *}

DATABASE test1

MAIN
  DEFINE lv_keyColumn SMALLINT
	DEFINE a_float FLOAT
  DEFINE exitStatus SMALLINT

  LET exitStatus = 0
  WHENEVER ERROR CONTINUE
  DROP TABLE xpto
  WHENEVER ERROR STOP
  CREATE TABLE xpto (
    keyColumn SMALLINT,
		a_float FLOAT
  )
  INSERT INTO xpto (keyColumn,a_float) VALUES (1,5.1)
  SELECT ( (keyColumn * xpto.keyColumn + @a_float ) / @xpto.a_float )
    INTO a_float
    FROM xpto
    WHERE keyColumn = 1
  DROP TABLE xpto

  IF a_float > 1.21 OR a_float < 1.19 THEN
    DISPLAY "Diferent float value expected=1.2 != fetched=", 
		        a_float using "#.####"
    LET exitStatus = 1
  END IF
  EXIT PROGRAM exitStatus
END MAIN

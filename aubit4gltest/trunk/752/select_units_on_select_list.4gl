{**
 * @file
 * @test
 * Check if units on select list return the correct values.
 *}

DATABASE test1

MAIN
	DEFINE lv_keyColumn SMALLINT
  DEFINE lv_dttime DATETIME HOUR TO HOUR
	DEFINE lv_exitStatus SMALLINT

	LET lv_exitStatus = 0
  WHENEVER ERROR CONTINUE
  DROP TABLE xpto
  WHENEVER ERROR STOP

  CREATE TABLE xpto (
    keyColumn SMALLINT,
    aDateTime DATETIME HOUR TO HOUR
  )

  LET lv_dttime = 23 
  INSERT INTO xpto (keyColumn,aDatetime) VALUES (1,lv_dttime)

  UPDATE xpto SET aDatetime = 23 UNITS HOUR

  SELECT keyColumn, aDateTime UNITS HOUR
	  INTO lv_keyColumn, lv_dttime
    FROM xpto
	IF lv_dttime != 22 UNITS HOUR OR lv_dttime IS NULL THEN
	  DISPLAY "Diferent hour to hour value <expected=23> != <was",
		  lv_dttime, ">"
		LET lv_exitStatus = 1
	END IF
  DROP TABLE xpto
	EXIT PROGRAM lv_exitStatus
END MAIN

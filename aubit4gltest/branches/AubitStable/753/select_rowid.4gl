{**
 * @file
 * @test
 * Check if a simple select that uses the rowid fetch the correct values.
 * values.
 *}

DATABASE test1

MAIN
  DEFINE lv_keyColumn SMALLINT
  DEFINE lv_valueColumn CHAR(20)
  DEFINE lv_dateColumn DATE
  DEFINE lv_rowid INTEGER
  DEFINE lv_count SMALLINT
  DEFINE dt DATE
  DEFINE exitStatus SMALLINT

  LET exitStatus = 0
  WHENEVER ERROR CONTINUE
  DROP TABLE xpto
  DROP TABLE xpta
  WHENEVER ERROR STOP
  CREATE TABLE xpto (
    keyColumn SMALLINT,
    valueColumn CHAR(20),
    dateColumn DATE
  )

  LET dt = mdy(1,1,2000)
  INSERT INTO xpto (keyColumn,valueColumn,dateColumn) 
    VALUES (2,"the second",dt)

  INSERT INTO xpto (keyColumn,valueColumn,dateColumn) 
    VALUES (3,"the third",dt)

  INSERT INTO xpto (keyColumn,valueColumn,dateColumn) 
    VALUES (4,"the forth",dt)
	
	-- Rowid in a group by is an error to IDS. :-(
	DECLARE cr_ CURSOR FOR
    SELECT rowid, keyColumn, valueColumn, dateColumn --, count(*)
      FROM xpto
			--GROUP BY rowid, keyColumn, 3, 4
			ORDER BY rowid

	OPEN cr_
	FETCH cr_ INTO lv_rowid, lv_keyColumn, lv_valueColumn, lv_dateColumn

  -- First iteration
  IF lv_keyColumn != 2 THEN
    DISPLAY "Diferent key value on first iteration <", 
		  lv_keycolumn USING "<<", ">!=<2>"
    LET exitStatus = 1
  END IF
  IF lv_valueColumn != "the second" THEN
    DISPLAY "Diferent string value on first iteration"
    LET exitStatus = 1
  END IF
  IF lv_dateColumn != DATE(MDY(1,1,2000)) THEN
    DISPLAY "Diferent date value  on first iteration <", lv_dateColumn, ">"
    LET exitStatus = 1
  END IF
  
	-- Second iteration
	FETCH cr_ INTO lv_rowid, lv_keyColumn, lv_valueColumn, lv_dateColumn
	IF sqlca.sqlcode != 0 THEN
    DISPLAY "Did not make the second iteration "
    LET exitStatus = 1
	END IF
  IF lv_keyColumn != 3 THEN
    DISPLAY "Diferent key value on second iteration <", 
		  lv_keycolumn USING "<<", ">!=<2>"
    LET exitStatus = 1
  END IF
  IF lv_valueColumn != "the third" THEN
    DISPLAY "Diferent string value on second iteration"
    LET exitStatus = 1
  END IF
  IF lv_dateColumn != DATE(MDY(1,1,2000)) THEN
    DISPLAY "Diferent date value on second iteration <", lv_dateColumn, ">"
    LET exitStatus = 1
  END IF

	-- Third iteration
	FETCH cr_ INTO lv_rowid, lv_keyColumn, lv_valueColumn, lv_dateColumn
	IF sqlca.sqlcode != 0 THEN
    DISPLAY "Did not make the third iteration "
    LET exitStatus = 1
	END IF
  IF lv_keyColumn != 4 THEN
    DISPLAY "Diferent key value on third iteration <", 
		  lv_keycolumn USING "<<", ">!=<2>"
    LET exitStatus = 1
  END IF
  IF lv_valueColumn != "the forth" THEN
    DISPLAY "Diferent string value on third iteration"
    LET exitStatus = 1
  END IF
  IF lv_dateColumn != DATE(MDY(1,1,2000)) THEN
    DISPLAY "Diferent date value on second iteration <", lv_dateColumn, ">"
    LET exitStatus = 1
  END IF

	CLOSE cr_
  DROP TABLE xpto
  EXIT PROGRAM exitStatus
END MAIN

{**
 * @file
 * @test
 * Check if a simple select with rowid in select list fetch the 
 * correct values.
 *}

DATABASE test1

MAIN
  DEFINE lv_rowid INTEGER
  DEFINE lv_key SMALLINT
	DEFINE dt DATE
  DEFINE exitStatus SMALLINT

  LET exitStatus = 0
  WHENEVER ERROR CONTINUE
  DROP TABLE xpto
  WHENEVER ERROR STOP
  CREATE TABLE xpto (
    keyColumn SMALLINT,
		intColumn INTEGER,
		dateColumn DATE
  )

	LET dt = MDY(12,31,1999)
  INSERT INTO xpto (keyColumn,intColumn,dateColumn) 
    VALUES (1,2,dt)

	DECLARE cr_ CURSOR FOR
    SELECT keyColumn, ROWID
      FROM xpto
		  ORDER BY 1

	OPEN cr_
	FETCH cr_ INTO lv_key, lv_rowid
  IF lv_key != 1 THEN
    DISPLAY "Diferent rowid of distinct values <", 
		  lv_key USING "<<", ">!=<2>"
    LET exitStatus = 1
  END IF
	CLOSE cr_

  DROP TABLE xpto
  EXIT PROGRAM exitStatus
END MAIN

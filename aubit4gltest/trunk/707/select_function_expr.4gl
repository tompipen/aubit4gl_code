
DATABASE test1

MAIN
  DEFINE exitStatus SMALLINT
  DEFINE dt DATE
	DEFINE r_ RECORD 
			a_user CHAR(18),
			aDay SMALLINT,
			aMonth SMALLINT,
			aWeekday SMALLINT,
			aYear SMALLINT,
      aDate DATE,
			aDatetimeYearToDay DATETIME YEAR TO DAY,
			anotherDatetimeYearToDay DATETIME YEAR TO DAY,
			anotherDate DATE,
			aLength SMALLINT,
			aHex CHAR(3),
			aRound INTEGER,
			aTrunct INTEGER,
			aDbInfo CHAR(10),
			aExp FLOAT,
			aLogn FLOAT,
			aLogThen FLOAT,
			aCos FLOAT,
			aSin FLOAT,
			aTan FLOAT,
			aArcSin FLOAT,
			aArcCos FLOAT,
			aArcTan FLOAT,
			aArcTanTwo FLOAT
	END RECORD

  LET exitStatus = 0
  WHENEVER ERROR CONTINUE
  DROP TABLE function_expr
  WHENEVER ERROR STOP

  LET dt = mdy(12,31,1999)
  CREATE TABLE function_expr (
		keyColumn SMALLINT
	)

  INSERT INTO function_expr (keyColumn) VALUES (1)

  SELECT 
			user,
      day(mdy(12,31,1999)),
      month(mdy(12,31,1999)),
      weekday(mdy(12,31,1999)),
      year(mdy(12,31,1999)),
      date(mdy(12,31,1999)),
      extend(dt, YEAR TO DAY),
      extend(datetime(1999-12-31) YEAR TO DAY, 
        YEAR TO MINUTE) - INTERVAL(720) MINUTE(3) TO MINUTE,
      mdy(12,31,1999),
      length("Hello"),
      hex("1"),
      round(1.6),
      trunc(1.6),
      dbinfo('sqlca.sqlerrd1'),
      exp(10),
      logn(2),
      log10(10),
      cos(0),
      sin(90),
      tan(1),
      asin(1),
      acos(1),
      atan(1),
      atan2(1,1)
  INTO r_.*
  FROM function_expr 
  WHERE keyColumn = 1

	{
	IF r_.a_user != XXX THEN
    DISPLAY "Diferent value 1"
    LET exitStatus = 1
  END IF
	}
	IF r_.aDay != 31 THEN
    DISPLAY "Diferent value 1 : ", r_.aDay
    LET exitStatus = 1
  END IF
	IF r_.aMonth != 12 THEN
    DISPLAY "Diferent value 2 : ", r_.aMonth
    LET exitStatus = 1
  END IF
	IF r_.aWeekday != 5 THEN
    DISPLAY "Diferent value 3 : ", r_.aWeekday
    LET exitStatus = 1
  END IF
	IF r_.aYear != 1999 THEN
    DISPLAY "Diferent value 4 : ", r_.aYear
    LET exitStatus = 1
  END IF
  IF r_.aDate != mdy(12,31,1999) THEN
    DISPLAY "Diferent value 5 : ", r_.aDate
    LET exitStatus = 1
  END IF
	{
	IF r_.aDatetimeYearToDay != XXX THEN
    DISPLAY "Diferent value 6 : ", r_.aDatetimeYearToDay
    LET exitStatus = 1
  END IF
	IF r_.anotherDatetimeYearToDay != XXX THEN
    DISPLAY "Diferent value 7 : ", r_.anotherDatetimeYearToDay
    LET exitStatus = 1
  END IF
	IF r_.anotherDate != XXX THEN
    DISPLAY "Diferent value 8 : ", r_.anotherDate
    LET exitStatus = 1
  END IF
	}
	IF r_.aLength != 5 THEN
    DISPLAY "Diferent value 9 : ", r_.aLength
    LET exitStatus = 1
  END IF
	IF r_.aHex != "0xF" THEN
    DISPLAY "Diferent value 10 : ", r_.aHex
    LET exitStatus = 1
  END IF
	IF r_.aRound != 2 THEN
    DISPLAY "Diferent value 11 : ", r_.aRound
    LET exitStatus = 1
  END IF
	IF r_.aTrunct != 1 THEN
    DISPLAY "Diferent value 12 : ", r_.aTrunct
    LET exitStatus = 1
  END IF
{
	IF r_.aDbInfo != XXX THEN
    DISPLAY "Diferent value 13 : ", r_.aDbInfo
    LET exitStatus = 1
  END IF
	}
	IF r_.aExp != 62.40 THEN
    DISPLAY "Diferent value 14 : ", r_.aExp
    LET exitStatus = 1
  END IF
	IF r_.aLogn != 0.69 THEN
    DISPLAY "Diferent value 15 : ", r_.aLogn
    LET exitStatus = 1
  END IF
	IF r_.aLogThen != 1 THEN
    DISPLAY "Diferent value 16 : ", r_.aLogThen
    LET exitStatus = 1
  END IF
	IF r_.aCos != 1 THEN
    DISPLAY "Diferent value 17 : ", r_.aCos
    LET exitStatus = 1
  END IF
	IF r_.aSin != 90 THEN
    DISPLAY "Diferent value 18 : ", r_.aSin
    LET exitStatus = 1
  END IF
	IF r_.aTan != 1 THEN
    DISPLAY "Diferent value 19 : ", r_.aTan
    LET exitStatus = 1
  END IF
	IF r_.aArcSin != 1 THEN
    DISPLAY "Diferent value 20 : ", r_.aArcSin
    LET exitStatus = 1
  END IF
	IF r_.aArcCos != 1 THEN
    DISPLAY "Diferent value 21 : ", r_.aArcCos
    LET exitStatus = 1
  END IF
	IF r_.aArcTan != 1 THEN
    DISPLAY "Diferent value 22 : ", r_.aArcTan
    LET exitStatus = 1
  END IF
	IF r_.aArcTanTwo != 1 THEN
    DISPLAY "Diferent value 23 : ", r_.aArcTanTwo
    LET exitStatus = 1
  END IF
	DROP TABLE function_expr
  EXIT PROGRAM exitStatus
END MAIN

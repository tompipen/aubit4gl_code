
DATABASE test1

MAIN
  DEFINE str CHAR(18)
  DEFINE sm SMALLINT
  DEFINE dt DATE
  DEFINE dtt DATETIME YEAR TO MINUTE
  DEFINE it INTERVAL HOUR TO MINUTE

  WHENEVER ERROR CONTINUE
  DROP TABLE xpto
  WHENEVER ERROR STOP

  CREATE TABLE xpto (
    firstColumn SMALLINT,
    secondColumn CHAR(20),
    thirdColumn INTEGER,
    aUser CHAR(10),
    aDate DATE,
    aDateTime DATETIME YEAR TO MINUTE,
    anInterval INTERVAL HOUR TO MINUTE,
    aToday DATE,
    aCurrent DATETIME YEAR TO FRACTION(3),
    aSingleQuoteStr VARCHAR(50,10)
  )

  LET dt = mdy(12,31,1999)
  INSERT INTO xpto 
      (firstColumn,secondColumn,thirdColumn,aUser,aDate,aDatetime,anInterval,
         aToday,aCurrent,aSingleQuoteStr)
     VALUES (1,"Hello world",
         5,
         USER,
         dt,
         datetime(1999-12-31 23:59) YEAR TO MINUTE,
         interval(48:01) HOUR TO MINUTE,
         TODAY,
         CURRENT YEAR TO FRACTION(3),
         'Single quote'
        )

  UPDATE xpto 
      SET (secondColumn,thirdColumn,aUser,aDate,aDatetime,
           anInterval,aToday,aCurrent,aSingleQuoteStr)
     = (aUser,
         firstColumn+1/2*5,
         secondColumn,
         aDate-1,
         aDatetime - 1 UNITS HOUR,
         anInterval + 1 UNITS HOUR ,
         aToday - 1,
         CURRENT YEAR TO FRACTION(3),
         'Single quote'
        )
    WHERE firstColumn = 1 and (secondColumn = USER OR aCurrent = CURRENT)

  DECLARE cr CURSOR FOR 
    SELECT secondColumn, thirdColumn, aDate, aDateTime, anInterval
      FROM xpto
  FOREACH cr INTO str, sm, dt, dtt, it
    DISPLAY "<", str clipped, ">", "<", sm, ">", "<",  dt, ">", "<", dtt, ">",
      "<", it, ">"
  END FOREACH
  DROP TABLE xpto
END MAIN

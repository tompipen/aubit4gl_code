
DATABASE test1

MAIN
  DEFINE dtt DATETIME YEAR TO MINUTE
  DEFINE it INTERVAL HOUR TO MINUTE
  DEFINE lv_yyInterval   INTERVAL YEAR TO YEAR
  DEFINE lv_momoInterval  INTERVAL MONTH TO MONTH
  DEFINE lv_ddInterval   INTERVAL DAY TO DAY
  DEFINE lv_hhInterval    INTERVAL HOUR TO HOUR
  DEFINE lv_mmInterval  INTERVAL MINUTE TO MINUTE
  DEFINE lv_ssInterval    INTERVAL SECOND TO SECOND
  DEFINE lv_ffInterval INTERVAL FRACTION TO FRACTION(3)

  WHENEVER ERROR CONTINUE
  DROP TABLE xpto
  WHENEVER ERROR STOP

  CREATE TABLE xpto (
    firstColumn     SMALLINT,
    aDateTime       DATETIME YEAR TO MINUTE,
    yyInterval   INTERVAL YEAR TO YEAR,
    momoInterval  INTERVAL MONTH TO MONTH,
    ddInterval   INTERVAL DAY TO DAY,
    hhInterval    INTERVAL HOUR TO HOUR,
    mmInterval  INTERVAL MINUTE TO MINUTE,
    ssInterval    INTERVAL SECOND TO SECOND,
    ffInterval INTERVAL FRACTION TO FRACTION(3)
  )

  INSERT INTO xpto 
      (firstColumn,aDatetime)
     VALUES (1,datetime(1999-12-31 23:59) YEAR TO MINUTE)

  UPDATE xpto 
      SET (
        yyInterval,
        momoInterval,
        ddInterval,
        hhInterval,
        mmInterval,
        ssInterval{,
        ffInterval
	}
      ) = (
         interval(1999) YEAR TO YEAR + (1 UNITS YEAR),
         interval(12) MONTH TO MONTH + (1 UNITS MONTH),
         interval(31) DAY TO DAY + (1 UNITS DAY),
         interval(24) HOUR TO HOUR + (1 UNITS HOUR),
         interval(60) MINUTE TO MINUTE + (1 UNITS MINUTE),
         interval(60) SECOND TO SECOND + (1 UNITS SECOND){,
         interval(99) FRACTION TO FRACTION(3) + (1 UNITS FRACTION)
	 }
        )
    WHERE firstColumn = 1 

  DECLARE cr CURSOR FOR 
    SELECT 
        yyInterval,
        momoInterval,
        ddInterval,
        hhInterval,
        mmInterval,
        ssInterval,
        ffInterval
      FROM xpto
  FOREACH cr INTO 
        lv_yyInterval,
        lv_momoInterval,
        lv_ddInterval,
        lv_hhInterval,
        lv_mmInterval,
        lv_ssInterval,
        lv_ffInterval
    DISPLAY 
        "<", lv_yyInterval, ">",
        "<", lv_momoInterval, ">",
        "<", lv_ddInterval, ">",
        "<", lv_hhInterval, ">",
        "<", lv_mmInterval, ">",
        "<", lv_ssInterval, ">",
        "<", lv_ffInterval, ">"
  END FOREACH
  DROP TABLE xpto
END MAIN

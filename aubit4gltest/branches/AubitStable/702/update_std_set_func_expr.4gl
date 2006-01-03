
DATABASE test1

MAIN
  DEFINE lv_keyColumn SMALLINT
  DEFINE lv_aUser CHAR(10)
  DEFINE lv_aDate DATE
  DEFINE lv_aDateTime DATETIME YEAR TO MINUTE
  DEFINE lv_anInterval INTERVAL HOUR TO MINUTE
  DEFINE lv_aToday DATE
  DEFINE lv_aCurrent DATETIME YEAR TO FRACTION(3)
  DEFINE lv_aSingleQuoteStr VARCHAR(50,10)
  DEFINE lv_dayColumn SMALLINT
  DEFINE lv_monthColumn SMALLINT
  DEFINE lv_weekdayColumn SMALLINT
  DEFINE lv_yearColumn SMALLINT
  DEFINE lv_dateColumn DATE
  DEFINE lv_extendDate DATE
  DEFINE lv_extendeDatetime DATETIME YEAR TO SECOND
  DEFINE lv_mdyColumn DATE
  DEFINE lv_lengthColumn SMALLINT
  DEFINE lv_hexColumn CHAR(3)
  DEFINE lv_roundColumn INTEGER
  DEFINE lv_truncColumn INTEGER
  DEFINE lv_dbinfoColumn CHAR(10)
  DEFINE lv_expColumn FLOAT
  DEFINE lv_lognColumn FLOAT
  DEFINE lv_log10Column FLOAT
  DEFINE lv_cosColumn FLOAT
  DEFINE lv_sinColumn FLOAT
  DEFINE lv_tanColumn FLOAT
  DEFINE lv_asinColumn FLOAT
  DEFINE lv_acosColumn FLOAT
  DEFINE lv_atanColumn FLOAT
  DEFINE lv_atan2Column FLOAT
  DEFINE dt DATE

  WHENEVER ERROR CONTINUE
  DROP TABLE xpto
  WHENEVER ERROR STOP

  LET dt = mdy(12,31,1999)
  CREATE TABLE xpto (
    keyColumn SMALLINT,
    aUser CHAR(10),
    aDate DATE,
    aDateTime DATETIME YEAR TO MINUTE,
    anInterval INTERVAL HOUR TO MINUTE,
    aToday DATE,
    aCurrent DATETIME YEAR TO FRACTION(3),
    aSingleQuoteStr VARCHAR(50,10),
    dayColumn SMALLINT,
    monthColumn SMALLINT,
    weekdayColumn SMALLINT,
    yearColumn SMALLINT,
    dateColumn DATE,
    extendDate DATE,
    extendeDatetime DATETIME YEAR TO SECOND,
    mdyColumn DATE,
    lengthColumn SMALLINT,
    hexColumn CHAR(3),
    roundColumn INTEGER,
    truncColumn INTEGER,
    dbinfoColumn CHAR(10),
    expColumn FLOAT,
    lognColumn FLOAT,
    log10Column FLOAT,
    cosColumn FLOAT,
    sinColumn FLOAT,
    tanColumn FLOAT,
    asinColumn FLOAT,
    acosColumn FLOAT,
    atanColumn FLOAT, 
    atan2Column FLOAT
  )

  INSERT INTO xpto (keyColumn) VALUES (1)

  UPDATE xpto 
    SET
      dayColumn = day(mdy(12,31,1999)),
      monthColumn = month(mdy(12,31,1999)),
      weekdayColumn = weekday(mdy(12,31,1999)),
      yearColumn = year(mdy(12,31,1999)),
      dateColumn = date(mdy(12,31,1999)),
      extendDate = extend(dt, YEAR TO DAY),
      extendeDatetime = extend(datetime(1999-12-31) YEAR TO DAY, 
        YEAR TO MINUTE) - INTERVAL(720) MINUTE(3) TO MINUTE,
      mdyColumn = mdy(12,31,1999),
      lengthColumn = length("Hello"),
      hexColumn = hex(16),
      roundColumn = round(1.6),
      truncColumn = trunc(1.6),
      dbinfoColumn = dbinfo('sqlca.sqlerrd1'),
      expColumn =  exp(10),
      lognColumn = logn(2),
      log10Column = log10(10),
      cosColumn = cos(0),
      sinColumn = sin(1),
      tanColumn = tan(1),
      asinColumn = asin(1),
      acosColumn = acos(1),
      atanColumn = atan(1),
      atan2Column = atan2(1,1)
    WHERE keyColumn = 1 

  DECLARE cr CURSOR FOR 
    SELECT 
        keyColumn,
        aUser,
        aDate,
        aDateTime,
        anInterval,
        aToday,
        aCurrent,
        aSingleQuoteStr,
        dayColumn,
        monthColumn,
        weekdayColumn,
        yearColumn,
        dateColumn,
        extendDate,
        extendeDatetime,
        mdyColumn,
        lengthColumn,
        hexColumn,
        roundColumn,
        truncColumn,
        dbinfoColumn,
        expColumn,
        lognColumn,
        log10Column,
        cosColumn,
        sinColumn,
        tanColumn,
        asinColumn,
        acosColumn,
        atanColumn,
        atan2Column
      FROM xpto
  FOREACH cr INTO 
    lv_keyColumn,
    lv_aUser,
    lv_aDate,
    lv_aDateTime,
    lv_anInterval,
    lv_aToday,
    lv_aCurrent,
    lv_aSingleQuoteStr,
    lv_dayColumn,
    lv_monthColumn,
    lv_weekdayColumn,
    lv_yearColumn,
    lv_dateColumn,
    lv_extendDate,
    lv_extendeDatetime,
    lv_mdyColumn,
    lv_lengthColumn,
    lv_hexColumn,
    lv_roundColumn,
    lv_truncColumn,
    lv_dbinfoColumn,
    lv_expColumn,
    lv_lognColumn,
    lv_log10Column,
    lv_cosColumn,
    lv_sinColumn,
    lv_tanColumn,
    lv_asinColumn,
    lv_acosColumn,
    lv_atanColumn,
    lv_atan2Column
    DISPLAY "XX"
  END FOREACH
  DROP TABLE xpto
END MAIN




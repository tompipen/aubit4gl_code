
DATABASE test1

MAIN
  DEFINE str CHAR(64)
  DEFINE sm SMALLINT
  DEFINE lv_firstColumn INTEGER
  DEFINE dummyColumn CHAR(256)
  DEFINE lv_firstColExpr CHAR(64)
  DEFINE lv_secondColExpr CHAR(64)
  DEFINE lv_thirdColExpr CHAR(64)
  DEFINE lv_forthColExpr CHAR(64)
  DEFINE lv_fiftColExpr CHAR(64)
  DEFINE lv_sixtColExpr CHAR(64)
  DEFINE lv_sevenColExpr CHAR(64)
  DEFINE lv_eigthColExpr CHAR(64)
  DEFINE lv_nineColExpr CHAR(64)
  DEFINE lv_tenColExpr CHAR(64)
  DEFINE lv_twelveColExpr CHAR(64)
  DEFINE lv_tirteenColExpr CHAR(64)
  DEFINE lv_forteenColExpr CHAR(64)

  WHENEVER ERROR CONTINUE
  DROP TABLE xpto
  WHENEVER ERROR STOP
  CREATE TABLE xpto (
    firstColumn integer,
    firstColExpr CHAR(64),
    secondColExpr CHAR(64),
    thirdColExpr CHAR(64),
    forthColExpr CHAR(64),
    fiftColExpr CHAR(64),
    sixtColExpr CHAR(64),
    sevenColExpr CHAR(64),
    eigthColExpr CHAR(64),
    nineColExpr CHAR(64),
    tenColExpr CHAR(64),
    twelveColExpr CHAR(64),
    tirteenColExpr CHAR(64),
    forteenColExpr CHAR(64),
    dummyColumn CHAR(256)
  )
  INSERT INTO xpto (firstColumn,firstColExpr,dummyColumn) 
    VALUES (1,"Hello","DUMMY VALUE")


  LET dummyColumn = "VAR DUMMY"
  UPDATE xpto 
    SET firstColExpr = firstColExpr,
        secondColExpr = xpto.firstColExpr,
        thirdColExpr = dummyColumn,
        forthColExpr = @dummyColumn,
        fiftColExpr = @xpto.dummyColumn,
        sixtColExpr = xpto.dummyColumn,
        sevenColExpr = ROWID,
        eigthColExpr = xpto.ROWID,
        --nineColExpr = firstColExpr[1,3],
        --tenColExpr = firstColExpr[1,3],
        twelveColExpr = @dummyColumn[2,4],
        tirteenColExpr = @xpto.dummyColumn[2,4],
        forteenColExpr = xpto.dummyColumn[2,4]
    WHERE @firstColumn = 1
  DECLARE cr CURSOR FOR 
    SELECT 
      firstColExpr,
      secondColExpr,
      thirdColExpr,
      forthColExpr,
      fiftColExpr,
      sixtColExpr,
      sevenColExpr,
      eigthColExpr,
      nineColExpr,
      tenColExpr,
      twelveColExpr,
      tirteenColExpr,
      forteenColExpr,
      xpto.dummyColumn
      FROM xpto
  FOREACH cr INTO 
      lv_firstColExpr,
      lv_secondColExpr,
      lv_thirdColExpr,
      lv_forthColExpr,
      lv_fiftColExpr,
      lv_sixtColExpr,
      lv_sevenColExpr,
      lv_eigthColExpr,
      lv_nineColExpr,
      lv_tenColExpr,
      lv_twelveColExpr,
      lv_tirteenColExpr,
      lv_forteenColExpr,
      dummyColumn
    DISPLAY 
      "<", lv_firstColExpr, ">",
      "<", lv_secondColExpr, ">",
      "<", lv_thirdColExpr, ">",
      "<", lv_forthColExpr, ">",
      "<", lv_fiftColExpr, ">",
      "<", lv_sixtColExpr, ">",
      "<", lv_sevenColExpr, ">",
      "<", lv_eigthColExpr, ">",
      "<", lv_nineColExpr, ">",
      "<", lv_tenColExpr, ">",
      "<", lv_twelveColExpr, ">",
      "<", lv_tirteenColExpr, ">",
      "<", lv_forteenColExpr, ">",
      "<", dummyColumn, ">"
  END FOREACH
  DROP TABLE xpto
END MAIN

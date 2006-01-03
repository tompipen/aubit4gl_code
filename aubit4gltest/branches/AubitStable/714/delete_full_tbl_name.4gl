
DATABASE test1

MAIN
  WHENEVER ERROR CONTINUE
  DROP TABLE 'informix'.xpto
  DROP TABLE xpto
  DROP TABLE xpta
  WHENEVER ERROR STOP
  CREATE TABLE 'informix'.xpto (
    firstColumn SMALLINT,
    secondColumn CHAR(10)
  )
  CREATE TABLE xpta (
    firstColumn SMALLINT,
    secondColumn CHAR(10)
  )

  INSERT INTO 'informix'.xpto (firstColumn,secondColumn) 
    VALUES(1,"Hello")
  DELETE FROM test1:'informix'.xpto 
    WHERE firstColumn = 1
  #DELETE FROM test1@unstable:'informix'.xpto 
  INSERT INTO test1:xpta (firstColumn,secondColumn) 
    VALUES(4,"Hello")
  DELETE FROM test1:xpta WHERE firstColumn = 1
  #DELETE FROM test1@unstable:xpta (firstColumn,secondColumn) 
  DROP TABLE 'informix'.xpto
  DROP TABLE xpta
END MAIN

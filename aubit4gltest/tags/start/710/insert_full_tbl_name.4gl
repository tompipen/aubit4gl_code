
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
  INSERT INTO test1:'informix'.xpto (firstColumn,secondColumn) 
    VALUES(2,"Hello")
  #INSERT INTO test1@unstable:'informix'.xpto (firstColumn,secondColumn) 
    #VALUES(3,"Hello")
  INSERT INTO test1:xpta (firstColumn,secondColumn) 
    VALUES(4,"Hello")
  #INSERT INTO test1@unstable:xpta (firstColumn,secondColumn) 
    #VALUES(5,"Hello")
  DROP TABLE 'informix'.xpto
  DROP TABLE xpta
END MAIN

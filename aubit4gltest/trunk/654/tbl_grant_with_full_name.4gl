
DATABASE test1

MAIN
	WHENEVER ERROR CONTINUE
	DROP TABLE 'informix'.xpto
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

  GRANT DELETE ON 'informix'.xpto TO informix, root
  GRANT DELETE ON test1:'informix'.xpto TO informix, root
  GRANT DELETE ON test1@unstable:'informix'.xpto TO informix, root
  GRANT DELETE ON test1:xpta TO informix, root
  GRANT DELETE ON test1@unstable:xpta TO informix, root
	DROP TABLE 'informix'.xpto
	DROP TABLE xpta
END MAIN

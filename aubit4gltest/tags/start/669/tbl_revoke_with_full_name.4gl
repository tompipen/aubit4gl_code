
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
whenever error continue
  REVOKE DELETE ON 'informix'.xpto FROM informix, root
  REVOKE DELETE ON test1:'informix'.xpto FROM informix, root
  REVOKE DELETE ON test1@unstable:'informix'.xpto FROM informix, root
  REVOKE DELETE ON test1:xpta FROM informix, root
  REVOKE DELETE ON test1@unstable:xpta FROM informix, root
	DROP TABLE 'informix'.xpto
	DROP TABLE xpta
END MAIN

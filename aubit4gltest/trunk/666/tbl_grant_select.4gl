
DATABASE test1

MAIN
	WHENEVER ERROR CONTINUE
	DROP TABLE xpto
	WHENEVER ERROR STOP
	CREATE TABLE xpto (
	  firstColumn SMALLINT,
		secondColumn CHAR(10)
	)

  GRANT SELECT ON xpto TO PUBLIC
  GRANT SELECT (secondColumn) ON xpto TO PUBLIC
  GRANT SELECT (secondColumn,firstColumn) ON xpto TO PUBLIC
  GRANT SELECT ON xpto TO informix
  GRANT SELECT (firstColumn) ON xpto TO informix
  GRANT SELECT (firstColumn,secondColumn) ON xpto TO informix
  GRANT SELECT ON xpto TO informix, root
  GRANT SELECT (secondColumn) ON xpto TO informix, root
  GRANT SELECT (secondColumn,firstColumn) ON xpto TO informix, root
	DROP TABLE xpto
END MAIN

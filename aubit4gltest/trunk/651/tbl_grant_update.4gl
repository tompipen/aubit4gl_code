
DATABASE test1

MAIN
	WHENEVER ERROR CONTINUE
	DROP TABLE xpto
	WHENEVER ERROR STOP
	CREATE TABLE xpto (
	  firstColumn SMALLINT,
		secondColumn CHAR(10)
	)

  GRANT UPDATE ON xpto TO PUBLIC
  GRANT UPDATE (secondColumn) ON xpto TO PUBLIC
  GRANT UPDATE (secondColumn,firstColumn) ON xpto TO PUBLIC
  GRANT UPDATE ON xpto TO informix
  GRANT UPDATE (firstColumn) ON xpto TO informix
  GRANT UPDATE (firstColumn,secondColumn) ON xpto TO informix
  GRANT UPDATE ON xpto TO informix, root
  GRANT UPDATE (secondColumn) ON xpto TO informix, root
  GRANT UPDATE (secondColumn,firstColumn) ON xpto TO informix, root
	DROP TABLE xpto
END MAIN


DATABASE test1

MAIN
	DEFINE pr RECORD LIKE update_table_perm.*
	DEFINE str CHAR(18)
	DEFINE _int INTEGER
	DEFINE sm SMALLINT

	DELETE FROM update_table_perm
	INSERT INTO update_table_perm (firstColumn,secondColumn) VALUES (1,"Hello")

	INITIALIZE pr.* TO NULL
	LET pr.firstColumn = 1
	LET pr.secondColumn = "1 - Hello world"
	LET pr.thirdColumn = 3
	UPDATE update_table_perm SET * = pr.*
	  WHERE firstColumn = 1
	DECLARE cr CURSOR FOR 
	  SELECT secondColumn, thirdColumn
		  FROM update_table_perm
	FOREACH cr INTO str, sm
	  DISPLAY str clipped, sm
	END FOREACH
END MAIN

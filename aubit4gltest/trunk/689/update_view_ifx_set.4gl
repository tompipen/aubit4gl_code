
DATABASE test1

MAIN
  DEFINE pr RECORD LIKE v_upd_tbl_perm.*
  DEFINE str CHAR(18)
  DEFINE _int INTEGER
  DEFINE sm SMALLINT
	DEFINE exitStatus SMALLINT

	LET exitStatus = 0
  DELETE FROM update_table_perm
  INSERT INTO update_table_perm (firstColumn,secondColumn) VALUES (1,"Hello")

  INITIALIZE pr.* TO NULL
  LET pr.firstColumn = 1
  LET pr.secondColumn = "1 - Hello world"
  LET pr.thirdColumn = 3
  UPDATE v_upd_tbl_perm SET * = pr.*
    WHERE firstColumn = 1
  SELECT secondColumn, thirdColumn 
	  INTO str, sm
	  FROM v_upd_tbl_perm
	IF str != "1 - Hello world" THEN
		DISPLAY "String updated was diferent on table <", str clipped, ">"
	  LET exitStatus = 1
	END IF
	IF sm != 3 THEN
		DISPLAY "Smallint updated was diferent on table <", 
		  pr.thirdColumn using "<<<", "> != <", sm using "<<<", ">"
	  LET exitStatus = 1
	END IF
	EXIT PROGRAM exitStatus
END MAIN

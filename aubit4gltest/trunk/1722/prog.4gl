DATABASE test1

DEFINE
   var1  CHAR(10),
   var2  VARCHAR(10),
   var3  VARCHAR(10),
   flag  INTEGER,
   p_ldsc RECORD 
		program_name varchar(255)
	END RECORD

MAIN
   LET var1 = "min_fcst"
   LET var2 = "min_fcst"
   LET var3 = var1
   
   create temp table log_div_sel_cntl (
	program_name varchar(255)
  )
  insert into log_div_sel_cntl values('min_fcst');

   DISPLAY ""
   DISPLAY "Test: CHAR/VARCHAR variable comparison"
   IF var1 = var2 THEN
      DISPLAY "PASS: var1 = var2"
   ELSE
      DISPLAY "*** FAIL: var1 != var2"
   END IF
 
   DISPLAY ""
   DISPLAY "Test: Assign CHAR to VARCHAR, then do VARCHAR/VARCHAR comparison"
   IF var2 = var3 THEN
      DISPLAY "PASS: var2 = var3"
   ELSE
      DISPLAY "*** FAIL: var2 != var3"
   END IF
 

   PREPARE test_query FROM "SELECT * FROM log_div_sel_cntl WHERE program_name = ? "
   DISPLAY ""
   DISPLAY "Test: CHAR to database VARCHAR comparison using prepared query"
   EXECUTE test_query USING var1 INTO p_ldsc.*
   IF STATUS = NOTFOUND THEN
      DISPLAY "*** FAIL: No record found using cursor"
   ELSE
      DISPLAY "PASS: Record found using cursor"
   END IF

   DISPLAY ""
   DISPLAY "Test: VARCHAR to database VARCHAR comparison using prepared query"
   EXECUTE test_query USING var2 INTO p_ldsc.*
   IF STATUS = NOTFOUND THEN
      DISPLAY "*** FAIL: No record found using cursor"
   ELSE
      DISPLAY "PASS: Record found using cursor"
   END IF


   DISPLAY ""
   DISPLAY "Test: VARCHAR (from CHAR) to database VARCHAR comparison using prepared query"
   EXECUTE test_query USING var3 INTO p_ldsc.*
   IF STATUS = NOTFOUND THEN
      DISPLAY "*** FAIL: No record found using cursor"
   ELSE
      DISPLAY "PASS: Record found using cursor"
   END IF


   LET flag = 0
   DISPLAY ""
   DISPLAY "Test: CHAR to database VARCHAR comparison using declared cursor"
   DECLARE test_curs1
     CURSOR FOR
        SELECT * FROM log_div_sel_cntl WHERE program_name = var1 
   FOREACH test_curs1 INTO p_ldsc.*
      LET flag = 1
   END FOREACH 
   IF flag = 1 THEN
      DISPLAY "PASS: Record found using cursor"
   ELSE
      DISPLAY "*** FAIL: No record found using cursor"
   END IF

   LET flag = 0
   DISPLAY ""
   DISPLAY "Test: VARCHAR to database VARCHAR comparison using declared cursor"
   DECLARE test_curs2
     CURSOR FOR
        SELECT * FROM log_div_sel_cntl WHERE program_name = var2
   FOREACH test_curs2 INTO p_ldsc.*
      LET flag = 1
   END FOREACH 
   IF flag = 1 THEN
      DISPLAY "PASS: Record found using cursor"
   ELSE
      DISPLAY "*** FAIL: No record found using cursor"
   END IF

   LET flag = 0
   DISPLAY ""
   DISPLAY "Test: VARCHAR (from CHAR) to database VARCHAR comparison using declared cursor"
   DECLARE test_curs3
     CURSOR FOR
        SELECT * FROM log_div_sel_cntl WHERE program_name = var3
   FOREACH test_curs3 INTO p_ldsc.*
      LET flag = 1
   END FOREACH 
   IF flag = 1 THEN
      DISPLAY "PASS: Record found using cursor"
   ELSE
      DISPLAY "*** FAIL: No record found using cursor"
   END IF


END MAIN

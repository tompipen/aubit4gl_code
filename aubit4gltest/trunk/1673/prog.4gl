{**
 * @file
 * Input array of a single char get 'error in field'
 * @process TEST_GENERAL
 *}
 
MAIN
DEFINE wa_x ARRAY[10] OF CHAR(1), 
       i INT

OPEN WINDOW v_orco AT 1,1 WITH FORM "inpa" ATTRIBUTE(DIM)
CALL set_count(5)
INPUT ARRAY wa_x FROM sa_query.*
   BEFORE ROW
      LET i = arr_curr()
   AFTER FIELD x
      IF wa_x[i] = "X" THEN
         DISPLAY "ok"
         EXIT PROGRAM 2
      END IF
      LET wa_x[i] = " "
END INPUT
CLOSE window  v_orco
EXIT PROGRAM 1
END MAIN

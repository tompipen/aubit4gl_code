 MAIN

DEFINE test1 CHAR(80)

LET test1 = "Blubb"

CALL test(test1)

END MAIN

FUNCTION test(blub)

DEFINE blub CHAR(80)

IF blub IS NULL OR
   blub = 0
   THEN DISPLAY "Test"
END IF
END FUNCTION

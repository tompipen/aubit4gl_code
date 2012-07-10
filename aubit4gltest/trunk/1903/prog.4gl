{**
 * @file
 * Describe the test here
 * @process TEST_GENERAL
 *}
 
#if you need to use a database, use "test1"
#database test1
MAIN

DEFINE str   STRING
DEFINE i     INTEGER

LET str = "TEST"

FOR i = 1 TO str.getLength()
   IF str.getCharAt(i) = ASCII(10) OR
      str.getLength() = i
      THEN DISPLAY "1"
   END IF

   IF str.getLength() = i OR
      str.getCharAt(i) = ASCII(10)
      THEN DISPLAY "2"
   END IF

END FOR

#CALL aclfgl_dump_screen("out")
END MAIN

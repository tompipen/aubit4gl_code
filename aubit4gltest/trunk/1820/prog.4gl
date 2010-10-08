 MAIN

DEFINE test1 CHAR(1)
DEFINE str   STRING
DEFINE i     INTEGER

LET str = "TEST"

FOR i = 1 TO str.getLength()

display "i=",i

   IF str.getCharAt(i) = ASCII(10) OR str.getLength() = i THEN 
	DISPLAY "1"
   END IF

   IF str.getLength() = i OR str.getCharAt(i) = ASCII(10) THEN
         DISPLAY "2"
   END IF

END FOR

END MAIN

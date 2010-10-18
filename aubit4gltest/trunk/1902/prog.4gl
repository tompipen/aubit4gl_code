{**
 * @file
 * Describe the test here
 * @process TEST_GENERAL
 *}
 
MAIN
DEFINE test DYNAMIC ARRAY OF CHAR(10)
DEFINE i INTEGER

CALL test.appendElement()
LET test[1] = "TEST123"
CALL test.appendElement()
LET test[2] = "TEST456"
CALL test.insertElement(1)
LET test[1] = "TEST789"

FOR i = 1 TO test.getLength()
   DISPLAY test[i]
END FOR

DISPLAY test.getLength()

END MAIN

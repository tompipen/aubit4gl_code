
MAIN
	DEFINE var CHAR(50)
  DEFINE ans CHAR
	DEFINE i INTEGER
	DEFINE j SMALLINT

  LET var =  "Hello world in line 10, column 30" 
	LET i = (125 - 25) / 10
	LET j = 3 * 10
  DISPLAY var AT i, j
	#PROMPT "" FOR CHAR ans
END MAIN

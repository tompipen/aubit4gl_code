{**
 * @file
 * Testing a way to pass values between shell and 4gl using a temporary 
 * file.
 *}
DATABASE test1

MAIN
  DEFINE comm CHAR(64)
	DEFINE fileName CHAR(64)
	DEFINE exitStatus SMALLINT
	DEFINE firstVar INTEGER
  DEFINE secondVar CHAR(20)
  DEFINE ThirdVar SMALLINT

	LET fileName = "/tmp/xx.tmp"
	LET comm = "./a_script.sh ", fileName CLIPPED
	RUN comm RETURNING exitStatus
	CREATE TEMP TABLE ret_values (
	  first_var INTEGER,
		second_var CHAR(20),
		third_var SMALLINT
	)
	LOAD FROM fileName INSERT INTO ret_values
	SELECT first_var, second_var, third_var
	  INTO firstVar, secondVar, thirdVar
		FROM ret_values
	DISPLAY "First Var ", firstVar
	DISPLAY "Second Var ", secondVar
	DISPLAY "Third Var ", thirdVar
	LET comm = "rm ", fileName CLIPPED
	RUN comm RETURNING exitStatus
END MAIN

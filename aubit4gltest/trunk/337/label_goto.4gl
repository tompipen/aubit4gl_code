

MAIN
   DEFINE i smallint
   DEFINE j smallint

  let i = 1
	let j = 1

LABEL startLoop:
	 LET i = i + 1

	 IF i < 10 THEN
	   GOTO startLoop
	 END IF

LABEL otherLoop:
	 LET j = j + 1

	 IF i < 10 THEN
	   GOTO :otherLoop
	 END IF
END MAIN

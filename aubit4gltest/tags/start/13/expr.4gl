MAIN

	DEFINE
		x		INTEGER,
		y		DECIMAL(12,2),
		ans		CHAR(1)


	LET x=1 
	
	if x is null then
		display "Wrong 0.1"
	else
		display "Right 0.1"
	end if

	if x = 1 then
		display "Right 0.2"
	else
		display "Wrong 0.2"
	end if

	if x < 1 then
		display "Wrong 0.3"
	else
		display "Right 0.3"
	end if

	if x > 1 then
		display "Wrong 0.4"
	else
		display "Right 0.4"
	end if

	if x <= 1 then
		display "Right 0.5"
	else
		display "Wrong 0.5"
	end if

	if x >= 1 then
		display "Right 0.6"
	else
		display "Wrong 0.6"
	end if


	LET x = NULL
	LET y = NULL
	#initialize x to null



	IF x IS NOT NULL  THEN
		display "Wrong 1.0"
	else
		display "Right 1.1"
	END IF

	IF x >0   THEN
		display "Wrong 1.1"
	else
		display "Right 1.1"
	END IF

	IF x IS NOT NULL AND x > 0 THEN
		display "Wrong 1.2"
	ELSE
		display "Right 1.2"
	END IF


END MAIN


MAIN
	DEFINE comm CHAR(64)
	DEFINE retVal SMALLINT
	LET comm = "ls"
  RUN comm RETURNING retVal
	DISPLAY comm clipped, " returned ", retVal
END MAIN

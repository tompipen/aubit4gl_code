DATABASE test1


FUNCTION test_whenever()
  DEFINE i SMALLINT

	WHENEVER ERROR GOTO errorLabel
	SELECT count(*) INTO i FROM SYSTABLES
	WHENEVER ERROR GOTO :errorLabel
	SELECT count(*) INTO i FROM SYSTABLES
	WHENEVER ERROR GOTO errorLabel
	SELECT count(*) INTO i FROM SYSTABLES
	WHENEVER ERROR GO TO :errorLabel
	SELECT count(*) INTO i FROM SYSTABLES
  RETURN

LABEL errorLabel:
  display "ERROR"
END FUNCTION

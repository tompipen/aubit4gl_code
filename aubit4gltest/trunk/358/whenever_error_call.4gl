DATABASE test1


FUNCTION test_whenever()
  DEFINE i SMALLINT

	WHENEVER ERROR CALL error_handler
	SELECT count(*) INTO i FROM SYSTABLES
END FUNCTION


function error_handler()
display "Error handler called"
end function

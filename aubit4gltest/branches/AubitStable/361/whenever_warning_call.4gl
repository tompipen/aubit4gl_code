DATABASE test1


FUNCTION test_whenever()
  DEFINE i SMALLINT
database test1
	WHENEVER WARNING CALL warning_handler
	SELECT count(*) INTO i FROM SYSTABLES
END FUNCTION


function warning_handler()
	display "Warning handler called"
end function

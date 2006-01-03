MAIN
        DEFINE
                a CHAR(20),
                b CHAR(20),
                c CHAR(20)
    	LET a = "abc"
        LET b = "123"
	DISPLAY "Start"
        CALL FUN_WO_RETURN(a)
	DISPLAY "Should have errored"
        CALL FUN_W_RETURN(a) RETURNING c
	DISPLAY "Should have errored"
        DISPLAY c
END MAIN

FUNCTION FUN_W_RETURN(a, b)
        DEFINE
                a CHAR(20),
                b CHAR(20)
    RETURN "abc123"
END FUNCTION

FUNCTION FUN_WO_RETURN(a, b)
        DEFINE
                a CHAR(20),
                b CHAR(20)
END FUNCTION


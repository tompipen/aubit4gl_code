MAIN
    DEFINE
        a FLOAT,
        b DECIMAL(4,3)
                                                                                
    OPEN FORM testcase FROM "testcase"
    DISPLAY FORM testcase
                                                                                
    LET a = 1.234
    LET b = 1.234

    DISPLAY BY NAME a
    DISPLAY BY NAME b

    sleep 1

    INPUT BY NAME a, b WITHOUT DEFAULTS attribute(reverse)
        ON KEY(F1)
            EXIT INPUT
    END INPUT
                                                                                
    CLOSE FORM testcase
	if a!=1.234 then
		exit program 1
	end if

	if b!=1.234 then
		exit program 2
	end if
    
    DISPLAY "a is float........", a
    DISPLAY "b is decimal......", b
END MAIN

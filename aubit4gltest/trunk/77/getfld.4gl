MAIN

        DEFINE  num1    CHAR(20),
                        num2    CHAR(20)

        OPEN FORM f_getfldbuf FROM "getfld"
        DISPLAY FORM f_getfldbuf

        INITIALIZE num1, num2 TO NULL

	call startlog("gf.log")
        INPUT BY NAME num1, num2 WITHOUT DEFAULTS
                AFTER FIELD     num1
                        LET num1 = GET_FLDBUF(formonly.num1)
			if num1 is null then
				call errorlog("NULL")
			else
				call errorlog(num1)
			end if
        END INPUT

        CLOSE FORM f_getfldbuf

	
END MAIN


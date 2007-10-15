MAIN

        DEFINE  num1    MONEY(9,2),
                        num2    MONEY(9,2)

        OPEN FORM f_moneytype FROM "moneytype"
        DISPLAY FORM f_moneytype

        INITIALIZE num1, num2 TO NULL

        INPUT BY NAME num1, num2 WITHOUT DEFAULTS

        CLOSE FORM f_moneytype
	if num1=1 and num2=1 then
		exit program 0
	else
		display num1
		display num2
		exit program 1
	end if

END MAIN


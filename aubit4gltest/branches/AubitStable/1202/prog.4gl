MAIN
	DEFINE 
		a SMALLINT,
		b DECIMAL,
		c CHAR
		OPTIONS 
		#INPUT ATTRIBUTE (WHITE,REVERSE),
		#DISPLAY ATTRIBUTE (WHITE,REVERSE),
		INPUT WRAP,
		FORM LINE 	10,
		MESSAGE LINE 	23,
		COMMENT LINE	23,
		PROMPT LINE	23,
		ERROR LINE	24

	OPEN FORM alw_null FROM "alw_null"
	DISPLAY FORM alw_null ATTRIBUTE (CYAN) 
	INPUT BY NAME a, b, c  WITHOUT DEFAULTS
		ON KEY(F1) if not infield(a) then exit program 1 end if
		ON KEY(F2) if not infield(b) then exit program 1 end if
		ON KEY(F3) if not infield(c) then exit program 1 end if
		ON KEY(F4) exit program 0
		    EXIT INPUT
	END INPUT

	CLOSE FORM alw_null
END MAIN



DEFINE
    barr	ARRAY[7] OF RECORD
		bc	CHAR(9),
		bi	INTEGER
	END RECORD

MAIN
	DEFINE i INTEGER

	OPTIONS
		ACCEPT KEY F12,
		INPUT WRAP,
    	MESSAGE LINE 1,
    	PROMPT LINE 23,
		COMMENT LINE 23,
		ERROR LINE 24

	OPEN FORM arr12 FROM "arr12"

	DISPLAY FORM arr12 ATTRIBUTE (CYAN)

	CALL fgl_drawbox(21,80,2,1,0)

	FOR i = 1 TO 7
		INITIALIZE barr[i].* TO NULL
	END FOR
        Call startlog("arr12.log")

    INPUT ARRAY barr WITHOUT DEFAULTS FROM ba.*
		ATTRIBUTE (COUNT = 4)

		ON KEY (F7)
			EXIT INPUT

		AFTER FIELD bc
			LET i = ARR_CURR ()
			IF barr[i].bc IS NULL THEN
				call errorlog("char field ",i," is null")
			END IF
			IF barr[i].bc IS NOT NULL THEN
				call errorlog("char field ",i," is not null")

			END IF

		AFTER FIELD bi
			LET i = ARR_CURR ()
			IF barr[i].bi IS NULL THEN
				call errorlog("int field ",i," is null")
			END IF
			IF barr[i].bi IS NOT NULL THEN
				call errorlog("int field ",i," is not null")
			END IF

	END INPUT

	CLOSE FORM arr12

END MAIN



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
	call startlog("inp.log")

    INPUT  barr[1].* WITHOUT DEFAULTS FROM ba[1].*

		ON KEY (F7)
			EXIT INPUT

		AFTER FIELD bc
			IF barr[1].bc IS NULL THEN
				call errorlog("char field ",i," ISNULL")
			END IF
			IF barr[1].bc IS NOT NULL THEN
				call errorlog("char field ",i," ISNOTNULL")
			END IF

		AFTER FIELD bi
			IF barr[1].bi IS NULL THEN
				call errorlog("int field ",i," ISNULL")
			END IF
			IF barr[1].bi IS NOT NULL THEN
				call errorlog("int field ",i," ISNOTNULL")
			END IF

	END INPUT

	CLOSE FORM arr12

END MAIN

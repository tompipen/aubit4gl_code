
DEFINE	# global to this module
    med	ARRAY[4] OF RECORD
		ifldx		INTEGER,
		cfldx		CHAR(10),
		mfldx		MONEY(10,2)
	END RECORD

MAIN

	DEFINE
		ans			CHAR(3),
		ifldy		INTEGER,
		cfldy		CHAR(10),
		mfldy		MONEY(10,2)

	OPTIONS
		ACCEPT KEY F12,
		INPUT WRAP,
    	MESSAGE LINE 1,
    	PROMPT LINE 23,
		COMMENT LINE 23,
		ERROR LINE 24

	CALL startlog("ibt.out")

	OPEN FORM ibt FROM "ibt"

	DISPLAY FORM ibt ATTRIBUTE (CYAN)

	LET ans = "x"
	WHILE ans != "q"
	LET med[1].ifldx = NULL
	LET med[1].cfldx = NULL
	LET med[1].mfldx = NULL

	LET med[2].ifldx = NULL
	LET med[2].cfldx = NULL
	LET med[2].mfldx = NULL


		PROMPT "Test? (ii, ib, it, iai, iab, iat, q) " FOR ans

		CASE ans
			WHEN "ii"	# INPUT/INFIELD
				INPUT BY NAME ifldy, cfldy, mfldy
					ON KEY (F11)
						EXIT INPUT

					ON KEY (F1)
						IF INFIELD (ifldy) THEN
							call errorlog("INFIELD ifld")
						ELSE
							call errorlog( "NOT INFIELD ifld")
						END IF

					ON KEY (F2)
						IF INFIELD (cfldy) THEN
							call errorlog( "INFIELD cfld")
						ELSE
							call errorlog( "NOT INFIELD cfld")
						END IF

					ON KEY (F3)
						IF INFIELD (mfldy) THEN
							call errorlog( "INFIELD mfld")
						ELSE
							call errorlog( "NOT INFIELD mfld")
						END IF
				END INPUT

			WHEN "ib"	# INPUT/GET_FLDBUF
				INPUT BY NAME ifldy, cfldy, mfldy
					ON KEY (F11)
						EXIT INPUT

					ON KEY (F1)
						CALL GET_FLDBUF (ifldy) RETURNING ifldy
						call errorlog( "GET_FLDBUF ifld = ", ifldy)

					ON KEY (F2)
						CALL GET_FLDBUF (cfldy) RETURNING cfldy
						call errorlog( "GET_FLDBUF cfld = ", cfldy)

					ON KEY (F3)
						CALL GET_FLDBUF (mfldy) RETURNING mfldy
						call errorlog( "GET_FLDBUF mfld = ", mfldy)
				END INPUT

			WHEN "it"	# INPUT/FIELD_TOUCHED
				INPUT BY NAME ifldy, cfldy, mfldy
					ON KEY (F11)
						EXIT INPUT

					ON KEY (F1)
						IF FIELD_TOUCHED (ifldy) THEN
							call errorlog( "ifld touched")
						ELSE
							call errorlog( "ifld NOT touched")
						END IF

					ON KEY (F2)
						IF FIELD_TOUCHED (cfldy) THEN
							call errorlog( "cfld touched")
						ELSE
							call errorlog( "cfld NOT touched")
						END IF

					ON KEY (F3)
						IF FIELD_TOUCHED (mfldy) THEN
							call errorlog( "mfld touched")
						ELSE
							call errorlog( "mfld NOT touched")
						END IF
				END INPUT

			WHEN "iai"	# INPUT ARRAY/INFIELD

   		 		INPUT ARRAY med WITHOUT DEFAULTS FROM ftl.* ATTRIBUTE (COUNT = 2)
					ON KEY (F11)
						EXIT INPUT

					ON KEY (F1)
						IF INFIELD (ifldx) THEN
							call errorlog( "INFIELD ifld")
						ELSE
							call errorlog( "NOT INFIELD ifld")
						END IF
					ON KEY (F4)
						IF INFIELD (ftl.ifldx) THEN
							call errorlog( "INFIELD ftl.ifld")
						ELSE
							call errorlog( "NOT INFIELD ftl.ifld")
						END IF

					ON KEY (F2)
						IF INFIELD (cfldx) THEN
							call errorlog( "INFIELD cfld")
						ELSE
							call errorlog( "NOT INFIELD cfld")
						END IF
					ON KEY (F5)
						IF INFIELD (ftl.cfldx) THEN
							call errorlog( "INFIELD ftl.cfld")
						ELSE
							call errorlog( "NOT INFIELD ftl.cfld")
						END IF

					ON KEY (F3)
						IF INFIELD (mfldx) THEN
							call errorlog( "INFIELD mfld")
						ELSE
							call errorlog( "NOT INFIELD mfld")
						END IF
					ON KEY (F6)
						IF INFIELD (ftl.mfldx) THEN
							call errorlog( "INFIELD ftl.mfld")
						ELSE
							call errorlog( "NOT INFIELD ftl.mfld")
						END IF
				END INPUT

			WHEN "iab"	# INPUT ARRAY/GET_FLDBUF
				LET med[1].ifldx =1
				LET med[1].cfldx = "R1"
				LET med[1].mfldx = 1.1

				LET med[2].ifldx = 2
				LET med[2].cfldx = "R2"
				LET med[2].mfldx = 2.2

   		 		INPUT ARRAY med WITHOUT DEFAULTS FROM ftl.* ATTRIBUTE (COUNT = 2)
					ON KEY (F11)
						EXIT INPUT

					ON KEY (F1)
						CALL GET_FLDBUF (ifldx) RETURNING ifldy
						call errorlog( "GET_FLDBUF ifld = ", ifldy)
					ON KEY (F4)
						CALL GET_FLDBUF (ftl.ifldx) RETURNING ifldy
						call errorlog( "GET_FLDBUF ftl.ifld = ", ifldy)

					ON KEY (F2)
						CALL GET_FLDBUF (cfldx) RETURNING cfldy
						call errorlog( "GET_FLDBUF cfld = ", cfldy)
					ON KEY (F5)
						CALL GET_FLDBUF (ftl.cfldx) RETURNING cfldy
						call errorlog( "GET_FLDBUF cfld = ", cfldy)

					ON KEY (F3)
						CALL GET_FLDBUF (mfldx) RETURNING mfldy
						call errorlog( "GET_FLDBUF ftl.mfld = ", mfldy)
					ON KEY (F6)
						CALL GET_FLDBUF (ftl.mfldx) RETURNING mfldy
						call errorlog( "GET_FLDBUF ftl.mfld = ", mfldy)
				END INPUT

			WHEN "iat"	# INPUT ARRAY/FIELD_TOUCHED
   		 		INPUT ARRAY med WITHOUT DEFAULTS FROM ftl.* ATTRIBUTE (COUNT = 2)
					ON KEY (F11)
						EXIT INPUT

					ON KEY (F1)
						IF FIELD_TOUCHED (ifldx) THEN
							call errorlog( "ifld touched")
						ELSE
							call errorlog( "ifld NOT touched")
						END IF
					ON KEY (F4)
						IF FIELD_TOUCHED (ftl.ifldx) THEN
							call errorlog( "ftl.ifld touched")
						ELSE
							call errorlog( "ftl.ifld NOT touched")
						END IF

					ON KEY (F2)
						IF FIELD_TOUCHED (cfldx) THEN
							call errorlog( "cfld touched")
						ELSE
							call errorlog( "cfld NOT touched")
						END IF
					ON KEY (F5)
						IF FIELD_TOUCHED (ftl.cfldx) THEN
							call errorlog( "ftl.cfld touched")
						ELSE
							call errorlog( "ftl.cfld NOT touched")
						END IF

					ON KEY (F3)
						IF FIELD_TOUCHED (mfldx) THEN
							call errorlog( "mfld touched")
						ELSE
							call errorlog( "mfld NOT touched")
						END IF
					ON KEY (F6)
						IF FIELD_TOUCHED (ftl.mfldx) THEN
							call errorlog( "ftl.mfld touched")
						ELSE
							call errorlog( "ftl.mfld NOT touched")
						END IF
				END INPUT

		END CASE

	END WHILE

	CLOSE FORM ibt

END MAIN

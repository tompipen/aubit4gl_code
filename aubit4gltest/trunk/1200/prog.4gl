DATABASE sabre

MAIN
	OPTIONS 
		FORM LINE 	10,
		MESSAGE LINE 	23,
		COMMENT LINE	23,
		PROMPT LINE	23,
		ERROR LINE	24

	CREATE TEMP TABLE xxTEST (relrec integer, ename char(20), securityx integer)
	CREATE TEMP TABLE xxTEST1 (relrec integer, ename char(20))
	INSERT INTO xxTEST VALUES(1, 'name 1', 10)
	INSERT INTO xxTEST VALUES(2, 'name 2', 20)
	INSERT INTO xxTEST1 VALUES(1, 'sub 1-1')
	INSERT INTO xxTEST1 VALUES(1, 'sub 1-2')
	INSERT INTO xxTEST1 VALUES(2, 'sub 2-1')
	INSERT INTO xxTEST1 VALUES(2, 'sub 2-2')
	# do the one with data
	CALL TEST(10) 
	# now do the one where we expect no data
	CALL TEST(50)
	DROP TABLE xxTEST
	DROP TABLE xxTEST1
END MAIN
######################################################################
FUNCTION TEST(i_secx)
	DEFINE 
		i_secx   SMALLINT,
		o_ename  CHAR(60),
		o_relrec SMALLINT,
		i_relrec SMALLINT

	DISPLAY '------Testing single select'
	LET o_ename = 'Not found'
    SELECT ENAME INTO o_ename FROM xxTEST WHERE SECURITYX = i_secx
	IF status = NOTFOUND THEN
	    DISPLAY 'NOT FOUND'
	ELSE
		DISPLAY o_ename
	END IF

	DISPLAY '------Testing single select w/o into'
    SELECT ENAME FROM xxTEST WHERE SECURITYX = i_secx
	IF status = NOTFOUND THEN
	    DISPLAY 'NOT FOUND'
	ELSE
		DISPLAY 'FOUND'
	END IF

	DISPLAY '------Testing foreach select w/ output binding'
    DECLARE f_curs CURSOR FOR SELECT ENAME FROM xxTEST WHERE SECURITYX >= i_secx
	FOREACH f_curs INTO o_ename
		DISPLAY 'FOUND ONE'
	END FOREACH
	FREE f_curs

	DISPLAY '------Testing foreach select w/ output binding in declare'
    DECLARE g_curs CURSOR FOR SELECT ENAME INTO o_ename FROM xxTEST WHERE SECURITYX > i_secx
	FOREACH g_curs
		DISPLAY 'FOUND ONE'
	END FOREACH
	FREE g_curs

	DISPLAY '------Testing cursor select w/ output binding'
    DECLARE e_curs CURSOR FOR SELECT ENAME FROM xxTEST WHERE SECURITYX >= i_secx
	OPEN e_curs
	WHILE TRUE
	    FETCH e_curs INTO o_ename
		IF STATUS = NOTFOUND THEN
			DISPLAY 'NOT FOUND IN CURSOR FETCH'
			EXIT WHILE
		ELSE
			DISPLAY o_ename
		END IF
	END WHILE
	CLOSE e_curs
	FREE e_curs

	DISPLAY '------Testing cursor select w/ no output binding'
    DECLARE n_curs CURSOR FOR SELECT ENAME FROM xxTEST WHERE SECURITYX >= i_secx
	OPEN n_curs
	WHILE TRUE
	    FETCH n_curs 
		IF STATUS = NOTFOUND THEN
			DISPLAY 'NOT FOUND IN CURSOR FETCH'
			EXIT WHILE
		ELSE
			DISPLAY 'FOUND ONE IN CURSOR FETCH'
			EXIT WHILE
		END IF
	END WHILE
	CLOSE n_curs
	FREE n_curs

	DISPLAY '------Testing cursor select w/ output binding in declare'
    DECLARE d_curs CURSOR FOR SELECT ENAME INTO o_ename FROM xxTEST WHERE SECURITYX >= i_secx
	OPEN d_curs
	WHILE TRUE
	    FETCH d_curs 
		IF STATUS = NOTFOUND THEN
			DISPLAY 'NOT FOUND IN CURSOR FETCH'
			EXIT WHILE
		ELSE
			DISPLAY 'FOUND ONE IN CURSOR FETCH'
			EXIT WHILE
		END IF
	END WHILE
	CLOSE d_curs
	FREE d_curs

	DISPLAY '------Testing cursor within cursor (w/ prepare)'
	PREPARE stmt0 FROM "SELECT RELREC FROM xxTEST WHERE SECURITYX >= ?"
    DECLARE curs0 CURSOR FOR  stmt0
	PREPARE stmt1 FROM "SELECT RELREC, ENAME FROM xxTEST1 WHERE RELREC = ?"
    DECLARE curs1 CURSOR FOR  stmt1
	OPEN curs0 USING i_secx
	DISPLAY sqlca.sqlcode
	WHILE TRUE
	    FETCH curs0 INTO o_relrec
		IF STATUS = NOTFOUND THEN
			DISPLAY 'NOT FOUND IN curs0'
			EXIT WHILE
		ELSE
			DISPLAY '>>', o_relrec
			LET i_relrec = o_relrec
			OPEN curs1 USING i_relrec
			DISPLAY sqlca.sqlcode
			WHILE TRUE
			    FETCH curs1 INTO o_relrec, o_ename
				IF STATUS = NOTFOUND THEN
					DISPLAY 'NOT FOUND curs1'
					EXIT WHILE
				ELSE
					DISPLAY '  ', o_relrec, o_ename
				END IF
			END WHILE
			CLOSE curs1
		END IF
	END WHILE
	CLOSE curs0
	FREE curs1
	FREE curs0

END FUNCTION

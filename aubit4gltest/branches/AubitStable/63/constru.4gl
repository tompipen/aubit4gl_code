DATABASE test1

MAIN
	DEFINE	queryStr	CHAR(200),
			exitint		SMALLINT,
			selstmt		CHAR(200)
	define lv_i integer
	
	LET exitint = 0	
	OPEN FORM constru FROM "constru"
	DISPLAY FORM constru
	call startlog("constr.log")

	CREATE TEMP TABLE temp_tbl(account_number	SMALLINT)
	insert into temp_tbl values(1);
	insert into temp_tbl values(2);
	insert into temp_tbl values(3);

	WHILE TRUE
		CONSTRUCT queryStr ON temp_tbl.account_number
			FROM formonly.account_number
			ON KEY (F1)
				MESSAGE "testing"
				EXIT CONSTRUCT	

			ON KEY (F12)
				EXIT PROGRAM 0
		END CONSTRUCT

		LET selstmt = "SELECT * FROM temp_tbl WHERE ", queryStr CLIPPED

		call errorlog(selstmt clipped)

		PREPARE st_select FROM selstmt
		DECLARE c_cust CURSOR FOR st_select
		message "Declared using :",selstmt clipped
		LET lv_i=-1
		foreach c_cust into lv_i
			call errorlog("-->",lv_i)
		end foreach
		if lv_i=-1 then
			call errorlog("No rows found")
		end if

	END WHILE

	CLOSE FORM constru

END MAIN

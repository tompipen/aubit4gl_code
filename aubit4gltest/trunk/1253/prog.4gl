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

	let lv_i=0
	WHILE TRUE
		initialize queryStr to null
		CONSTRUCT queryStr ON temp_tbl.account_number
			FROM formonly.account_number
			ON KEY (F1)
				MESSAGE "testing"
				EXIT CONSTRUCT	

			ON KEY (F12)
				EXIT PROGRAM 0
		END CONSTRUCT

		let lv_i=lv_i+1

		case lv_i 
		when 1 if queryStr!="temp_tbl.account_number>'1000'" then display "Unexpected result:",queryStr,"<" exit program 1 end if
		when 2 if queryStr!="temp_tbl.account_number<'1'" then display "Unexpected result:",queryStr,"<" exit program 1 end if
		end case


	END WHILE

	CLOSE FORM constru

END MAIN

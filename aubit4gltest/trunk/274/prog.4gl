
DATABASE test1

MAIN
	DEFINE	queryStr	CHAR(200),
			exitint		SMALLINT,
			selstmt		CHAR(200)
	define lv_i integer
	
 	let lv_i=1
 	OPEN window w1 at 2,2 with form "constru"
	let queryStr="Bibble"
		CONSTRUCT queryStr ON temp_tbl.account_number
			FROM formonly.account_number
			
		if queryStr!=" Bibble" then
			display "BAD : ",queryStr clipped exit program 1
		end if
	exit program 0


END MAIN
